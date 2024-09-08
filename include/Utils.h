#pragma once
#include "PlayingCard.h"
#include "Deck.h"
#include <string>

namespace Seegrid::Poker
{
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
}
