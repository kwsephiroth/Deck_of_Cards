#pragma once
#include <iostream>

namespace Poker
{
	enum class Suit
	{
		UNKNOWN,
		HEARTS,
		SPADES,
		CLUBS,
		DIAMONDS
	};

	enum class Rank
	{
		UNKNOWN = 0,
		ACE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 11,
		QUEEN = 12,
		KING = 13
	};

	struct PlayingCard
	{
		Suit m_suit = Suit::UNKNOWN;
		Rank m_rank = Rank::UNKNOWN;

		bool operator==(const PlayingCard& rhs) const
		{
			return (m_rank == rhs.m_rank && m_suit == rhs.m_suit);
		}

		bool operator!=(const PlayingCard& rhs) const
		{
			return !operator==(rhs);
		}
	};
}

