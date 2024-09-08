#pragma once
#include "PlayingCard.h"
#include <deque>

namespace Seegrid::Poker
{
	const unsigned int MAX_DECK_SIZE = MAX_SUITS * MAX_RANKS;
	using PlayingCardPtr = std::unique_ptr<PlayingCard>;

	class Deck
	{
	public:
		/**
		* @brief The constructor.
		*/
		Deck();

		/**
		* @brief Shuffles the deck.
		*/
		void shuffle();

		/**
		* @brief Deals a single card from the top of the deck.
		*/
		PlayingCardPtr deal_card();

	private:

		/**
		* @brief Populates deck with 52 playing cards in a standard new deck order.
		* 
		* Populates an initially empty deck with 52 playing cards.
		* The card order is based on the new deck order used
		* in a standard deck of US Playing Card Company (USPCC) cards.
		*/
		void populate();

		std::deque<PlayingCardPtr> m_deck;
	};
}