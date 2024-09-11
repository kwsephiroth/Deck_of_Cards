/**
 * @file	Deck.h
 * Author:  Kenneth Walker
 * Contact: kwalkerdev@gmail.com
 * Year:	2024
 */

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
		* 
		* @param How many times the deck can be fully drawn (emptied).
		*/
		Deck(unsigned int maxTimesFullyDrawn = 1);

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
		* @brief Deals a single card from the top of the deck.
		* @param Id of player to whom the card is dealt.
		* @return A single card object from the deck.
		*/
		PlayingCardPtr deal_card(const std::string& playerId);

		/**
		* @brief Returns counter indicating how many times the deck has been fully drawn.
		* @return Fully drawn count.
		*/
		unsigned int times_fully_drawn();

		/**
		* @brief Places card on top (front) of deck.
		* @param Card to be added to top of deck.
		*/
		void place_card_on_top(PlayingCardPtr card);

		/**
		* @brief Clears deck and resets times fully drawn state.
		*/
		void reset();

		/**
		* @brief Returns whether or not the deck is available for use based on max times fully drawn.
		* @return Whether or not the deck is available for use.
		*/
		bool is_available() const;
	private:
		std::deque<PlayingCardPtr> m_deck; /**< The collection of playing cards. */
		std::mutex m_mutex; /**< The mutex for synchronizing access to the deck. */
		std::condition_variable m_cv; /**< The condition variable for synchronizing access to the deck.*/
		std::atomic<unsigned int> m_TimesFullyDrawn; /**< How many times the deck has been emptied.*/
		unsigned int m_MaxTimesFullyDrawn;/**< The max amount of times the deck can be fully drawn.*/
		std::atomic<bool> m_IsAvailable;/**< Is the deck available for use.*/
	};
}