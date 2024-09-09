/**
 * @file	Game.cpp
 * Author:  Kenneth Walker
 * Contact: kwalkerdev@gmail.com
 * Year:	2024
 */
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
		std::thread dealerThread(&Game::run_dealer_task, this, std::ref(deck), std::chrono::milliseconds(1000));

		// Delay before starting player threads to make sure the dealer 
		// has time to shuffle the deck for the first time.
		std::this_thread::sleep_for(std::chrono::seconds(1));

		//Spawn player threads.
		std::thread player1Thread(&Game::run_player_task, this, std::ref(deck), std::chrono::milliseconds(100), "Player 1");
		std::thread player2Thread(&Game::run_player_task, this, std::ref(deck), std::chrono::milliseconds(100), "Player 2");

		dealerThread.join();
		player1Thread.join();
		player2Thread.join();
		std::cout << "Poker Game Ended.\n";
	}

	void Game::run_dealer_task(Deck& deck, std::chrono::milliseconds waitFor)
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
			std::this_thread::sleep_for(waitFor);
			
		}
	}

	void Game::run_player_task(Deck& deck, std::chrono::milliseconds waitFor, const std::string& playerId)
	{
		int handSize = 0;
		while (true)
		{
			auto dealt_card = deck.deal_card(playerId);
			if (!dealt_card)
				break;

			++handSize;
			if (handSize >= 5)
			{
				std::this_thread::sleep_for(waitFor);
				srand(time(NULL));
				int randNum = (rand() % 5 + 1);
				handSize -= randNum; //play random amount of cards from 5-card hand
			}
		}
	}
}