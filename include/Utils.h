/**
 * @file	Utils.h
 * Author:  Kenneth Walker
 * Contact: kwalkerdev@gmail.com
 * Year:	2024
 */
#pragma once
#include <string>
#include "../include/PlayingCard.h"

namespace Seegrid::Poker
{
	// Forward declaration
	class Deck;

	/**
	* @brief Gets string representation of a Suit enumeration value.
	* @param A Suit enumeration value.
	* @return String representation of the Suit enumeration value.
	*/
	std::string to_string(const Suit suit);

	/**
	* @brief Gets string representation of a Rank enumeration value.
	* @param A Rank enumeration value.
	* @return String representation of the Rank enumeration value.
	*/
	std::string to_string(const Rank face);

	/**
	* @brief Gets string representation of a PlayingCard object.
	* @param A PlayingCard object.
	* @return String representation of the PlayingCard object.
	*/
	std::string to_string(const PlayingCard& card);

	/**
	* @brief Streams a string representation of a PlayingCard object.
	* @param A PlayingCard object.
	* @return Output stream object storing string representation of the PlayingCard object.
	*/
	std::ostream& operator<<(std::ostream& os, const PlayingCard& card);

	/**
	* @brief Determines if a card object represents an unknown card.
	* @param A PlayingCard object.
	* @return Whether or not the card is unknown.
	*/
	bool is_unknown_card(const PlayingCard& card);

	/**
	* @brief Adds unknown card to top of a deck
	* @param A Deck object
	*/
	void place_unknown_card_on_top(Deck& deck);
}
