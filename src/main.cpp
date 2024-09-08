#include "../include/Deck.h"
#include "../include/Utils.h"
#include <iostream>

int main()
{
	Seegrid::Poker::Deck deck;
	for(;;)
	{
		auto dealt_card = deck.deal_card();
		if (dealt_card)
			std::cout << *dealt_card << "\n";
		else
			break;
	}
	return 0;
}