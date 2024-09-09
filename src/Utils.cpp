/**
 * @file	Utils.cpp
 * Author:  Kenneth Walker
 * Contact: kwalkerdev@gmail.com
 * Year:	2024
 */
#include "../include/Utils.h"
#include "../include/Deck.h"

namespace Seegrid::Poker
{
	std::string to_string(const Suit suit)
	{
		switch (suit)
		{
		case Suit::CLUBS:
			return "Clubs";
		case Suit::DIAMONDS:
			return "Diamonds";
		case Suit::HEARTS:
			return "Hearts";
		case Suit::SPADES:
			return "Spades";
		default:
			return "Unknown";
		}
	}

	std::string to_string(const Rank face)
	{
		switch (face)
		{
		case Rank::ACE:
			return "Ace";
		case Rank::TWO:
			return "2";
		case Rank::THREE:
			return "3";
		case Rank::FOUR:
			return "4";
		case Rank::FIVE:
			return "5";
		case Rank::SIX:
			return "6";
		case Rank::SEVEN:
			return "7";
		case Rank::EIGHT:
			return "8";
		case Rank::NINE:
			return "9";
		case Rank::TEN:
			return "10";
		case Rank::JACK:
			return "Jack";
		case Rank::QUEEN:
			return "Queen";
		case Rank::KING:
			return "King";
		default:
			return "Unknown";
		}
	}

	std::string to_string(const PlayingCard& card)
	{
		return to_string(card.m_rank) + " of " + to_string(card.m_suit);
	}

    std::ostream& operator<<(std::ostream& os, const PlayingCard& card)
    {
		os << to_string(card);
        return os;
    }

	bool is_unknown_card(const PlayingCard& card)
	{
		static PlayingCard unkownCard{ .m_suit = Suit::UNKNOWN, .m_rank = Rank::UNKNOWN };
		return (card == unkownCard);
	}

	void place_unknown_card_on_top(Deck& deck)
	{
		static PlayingCard unkownCard{ .m_suit = Suit::UNKNOWN, .m_rank = Rank::UNKNOWN };
		deck.place_card_on_top(std::make_unique<PlayingCard>(unkownCard));
	}
}