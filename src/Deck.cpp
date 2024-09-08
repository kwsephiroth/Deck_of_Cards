#include "../include/Deck.h"
#include <ranges>

namespace Seegrid::Poker
{
	Deck::Deck()
	{
		initialize();
	}

	void Deck::initialize()
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
		auto n = m_deck.size();
		for (size_t i = 0; i < n - 1; i++)
		{
			int j = i + rand() % (n - i);
			std::swap(m_deck[i], m_deck[j]);
		}
	}

	PlayingCardPtr Deck::deal_card()
	{
		PlayingCardPtr dealt_card = nullptr;

		if (!m_deck.empty())
		{
			dealt_card = std::move(m_deck.front());
			m_deck.pop_front();
		}

		return dealt_card;
	}
}