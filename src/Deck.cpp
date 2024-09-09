#include "../include/Deck.h"
#include <ranges>
#include <iostream>

namespace Seegrid::Poker
{
	Deck::Deck() :
		m_timesEmptied(0)
	{
		populate();
	}

	void Deck::populate()
	{
		static const Suit suits[MAX_SUITS] = { Suit::SPADES, Suit::DIAMONDS, Suit::CLUBS, Suit::HEARTS };
		static const Rank ranks[MAX_RANKS] = { Rank::ACE, Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, Rank::SEVEN,
											   Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING };
	
		std::unique_lock<std::mutex> locker(m_mutex);
		if (!m_deck.empty()) //Only populate an emptied (fully drawn) deck.
			return;

		unsigned int suit_index = 0;
		while (suit_index < 2)
		{
			for (const auto rank : ranks)
			{
				PlayingCard card{ .m_suit = suits[suit_index], .m_rank = rank };
				m_deck.emplace_back(std::make_unique<PlayingCard>(card));
			}
			++suit_index;
		}

		while (suit_index < 4)
		{
			for (const auto rank : ranks | std::views::reverse)
			{
				PlayingCard card{ .m_suit = suits[suit_index], .m_rank = rank };
				m_deck.emplace_back(std::make_unique<PlayingCard>(card));
			}
			++suit_index;
		}
		locker.unlock();
		m_cv.notify_all();//Notify consumer threads that cards are available for consumption.
	}

	void Deck::shuffle()
	{
		//Use a different seed to ensure differents results
		//each time this method is called.
		srand(time(NULL));

		//Implmentation of Fisher-Yates shuffle algorithm.
		std::unique_lock<std::mutex> locker(m_mutex);
		auto n = m_deck.size();
		for (int i = (n - 1); i > 0; --i)
		{
			int j = rand() % (i + 1);
			std::swap(m_deck[i], m_deck[j]);
		}
	}

	PlayingCardPtr Deck::deal_card()
	{
		static int dealt_card_count = 0;
		std::unique_lock<std::mutex> locker(m_mutex);
		m_cv.wait(locker, [&]() {return !m_deck.empty();});//Only wake if a card can be consumed.
		
		//std::cout << "Deck contents before dealing: \n";
		/*for (const auto& card : m_deck)
		{
			std::cout << *card << "\n";
		}
		std::cout << "\n\n";*/
		
		if (is_unknown_card(*m_deck.front()))
			return nullptr;
		
		auto dealtCard = std::move(m_deck.front());
		m_deck.pop_front();
		++dealt_card_count;
        std::cout << "Dealt " << *dealtCard << "\n";
		
		if (m_deck.empty())
		{
			++m_timesEmptied;
			std::cout << "\nTimes Deck Fully Drawn: " << m_timesEmptied << "\n";
			std::cout << "Total Cards Dealt: " << dealt_card_count << "\n\n";
			dealt_card_count = 0;
		}

		return dealtCard;
	}

	unsigned int Deck::times_emptied()
	{
		return m_timesEmptied;
	}

	void Deck::place_card_on_top(PlayingCardPtr card)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		if (!is_unknown_card(*card) && m_deck.size() >= MAX_DECK_SIZE)
			return;
		m_deck.push_front(std::move(card));
		m_cv.notify_all();
	}
}