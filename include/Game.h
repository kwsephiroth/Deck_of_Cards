/**
 * @file	Game.h
 * Author:  Kenneth Walker
 * Contact: kwalkerdev@gmail.com
 * Year:	2024
 */
#pragma once
#include "Deck.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>

namespace Seegrid::Poker
{
	class Game
	{
	public:
		/**
		* @brief Starts poker game loop.
		*/
		void start();

	private:
		/**
		* @brief Task that simulates Dealer actions.
		* @param Deck the Dealer will shuffle and repopulate.
		* @param How long the Dealer should wait before taking actions on the deck.
		*/
		void run_dealer_task(Deck& deck, std::chrono::milliseconds waitFor);

		/**
		* @brief Task that simulates Player actions.
		* @param Deck the Player should draw from.
		* @param How long the Player should wait before taking actions on the deck.
		*/
		void run_player_task(Deck& deck, std::chrono::milliseconds waitFor, const std::string& playerId);
	};
}
