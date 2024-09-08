#include "../include/Deck.h"
#include "../include/Utils.h"
#include <iostream>

int main()
{
	Seegrid::Poker::Deck deck;

	auto deal_and_print_cards = [](Seegrid::Poker::Deck& deck) mutable
	{
		for (;;)
		{
			auto dealt_card = deck.deal_card();
			if (dealt_card)
				std::cout << *dealt_card << "\n";
			else
				break;
		}
	};

	deal_and_print_cards(deck);
	std::cout << '\n';
	deck = Seegrid::Poker::Deck();
	deck.shuffle();
	std::cout << "\nSHUFFLED:\n";
	deal_and_print_cards(deck);
	deck = Seegrid::Poker::Deck();
	deck.shuffle();
	std::cout << "\nSHUFFLED:\n";
	deal_and_print_cards(deck);

	return 0;
}