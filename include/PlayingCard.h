#pragma once
#include <iostream>

namespace Seegrid::Poker
{
	const unsigned int MAX_SUITS = 4;
	const unsigned MAX_RANKS = 13;

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

	/**
	* @brief Models a standard playing card in a poker deck.
	*/
	struct PlayingCard
	{
		Suit m_suit = Suit::UNKNOWN;
		Rank m_rank = Rank::UNKNOWN;

		/**
		* @brief Equivalence overloading.
		* @param Another PlayingCard object.
		* @return Whether the two PlayingCard objects repesent the same playing card.
		*/
		bool operator==(const PlayingCard& rhs) const
		{

			return (m_rank == rhs.m_rank && m_suit == rhs.m_suit);
		}

		/**
		* @brief Inequivalence overloading.
		* @param Another PlayingCard object.
		* @return Whether the two PlayingCard objects represent different playing cards.
		*/
		bool operator!=(const PlayingCard& rhs) const
		{
			return !operator==(rhs);
		}
	};
}

