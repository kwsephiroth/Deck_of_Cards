#include "../include/Game.h"
#include <vector>
#include <cassert>

namespace Seegrid::Poker
{
	void Game::start()
	{
		std::cout << "Poker Game Started.\n\n";
		Deck deck;

		//Spawn dealer thread.
		std::thread dealerThread(&Game::run_dealer_task, this, std::ref(deck));
		//assert(dealerThread.joinable());

		// Delay before starting player threads to make sure the dealer 
		// has time to shuffle the deck for the first time.
		std::this_thread::sleep_for(std::chrono::seconds(1));

		//Spawn player threads.
		std::thread player1Thread(&Game::run_player_task, this, std::ref(deck));
		std::thread player2Thread(&Game::run_player_task, this, std::ref(deck));

		dealerThread.join();
		player1Thread.join();
		player2Thread.join();
		std::cout << "Poker Game Ended.\n";
	}

	void Game::run_dealer_task(Deck& deck)
	{
		while (true)
		{
			if (deck.times_emptied() >= 3)
			{
				//Add unknown card to deck to signal game over.
				PlayingCard unknownCard{ .m_suit = Suit::UNKNOWN, .m_rank = Rank::UNKNOWN };
				deck.place_card_on_top(std::make_unique<PlayingCard>(unknownCard));
				return;
			}

			deck.populate();
			deck.shuffle();
		}
	}

	void Game::run_player_task(Deck& deck)
	{
		while (deck.deal_card())
		{
		}
	}
}