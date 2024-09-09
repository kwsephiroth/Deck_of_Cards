#pragma once
#include "Deck.h"
#include <thread>
#include <atomic>
#include <iostream>

namespace Seegrid::Poker
{
	class Game
	{
	public:
		void start();
	private:
		void run_dealer_task(Deck& deck);
		void run_player_task(Deck& deck);

		std::atomic<bool> m_IsGameOver = false;
	};
}
