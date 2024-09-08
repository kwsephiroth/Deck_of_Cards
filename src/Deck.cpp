#include "../include/Deck.h"
#include <ranges>

namespace Seegrid::Poker
{
	Deck::Deck()
	{
		populate();
	}

	void Deck::populate()//TODO: Should this method be the responsibility of another class or factory method?
	{
		static const Suit suits[MAX_SUITS] = { Suit::SPADES, Suit::DIAMONDS, Suit::CLUBS, Suit::HEARTS };
		static const Rank ranks[MAX_RANKS] = { Rank::ACE, Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, Rank::SEVEN,
											   Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING };
	
		if (!m_deck.empty()) //Don't try to initialize an existing deck.
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
	}

	void Deck::shuffle()
	{
		//Use a different seed to ensure differents results
		//each time this method is called.
		srand(time(NULL));

		//Implmentation of Fisher-Yates shuffle algorithm.
		auto n = m_deck.size();
		for (int i = (n - 1); i > 0; --i)
		{
			int j = rand() % (i + 1);
			std::swap(m_deck[i], m_deck[j]);
		}
	}

	PlayingCardPtr Deck::deal_card()
	{
		if (m_deck.empty())
			return nullptr;

		auto dealt_card = std::move(m_deck.front());
		m_deck.pop_front();

		return dealt_card;
	}
}