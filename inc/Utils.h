#pragma once
#include "PlayingCard.h"
#include <string>

namespace Poker
{
	std::string to_string(const Suit suit);
	std::string to_string(const Rank face);
	std::string to_string(const PlayingCard& card);
	std::ostream& operator<<(std::ostream& os, const PlayingCard& card);
}
