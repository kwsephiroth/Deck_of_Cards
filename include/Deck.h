#pragma once
#include "PlayingCard.h"
#include "Utils.h"
#include <deque>
#include <mutex>
#include <condition_variable>

namespace Seegrid::Poker
{
	const unsigned int MAX_DECK_SIZE = MAX_SUITS * MAX_RANKS;
	using PlayingCardPtr = std::unique_ptr<PlayingCard>;

	/**
	* @brief Deck class modeling a standard 52-card poker deck.
	* 
	* Models a standard 52-card deck. 
	* Provides thread-safe interfaces for interacting with the deck.
	*/
	class Deck
	{
	public:
		/**
		* @brief The constructor.
		* 
		* Initializes fully populated with 52 cards in a standard new deck order.
		*/
		Deck();

		/**
		* @brief Populates deck with 52 playing cards in a standard new deck order.
		*
		* Populates an initially empty deck with 52 playing cards.
		* The card order is based on the new deck order used
		* in a standard deck of US Playing Card Company (USPCC) cards.
		*/
		void populate();

		/**
		* @brief Shuffles the deck.
		*/
		void shuffle();

		/**
		* @brief Deals a single card from the top of the deck.
		* @return A single card object from the deck.
		*/
		PlayingCardPtr deal_card();

		/**
		* @brief Returns counter indicating how many times the deck has been fully drawn.
		* @return Fully drawn count.
		*/
		unsigned int times_emptied();

		/**
		* @brief Places card on top (front) of deck.
		* @param Card to be added to top of deck.
		*/
		void place_card_on_top(PlayingCardPtr card);

	private:
		std::deque<PlayingCardPtr> m_deck; /**< The collection of playing cards. */
		std::mutex m_mutex; /**< The mutex for synchronizing access to the deck. */
		std::condition_variable m_cv; /**< The condition variable for synchronizing access to the deck.*/
		std::atomic<unsigned int> m_timesEmptied; /**< How many times the deck has been emptied.*/
	};
}