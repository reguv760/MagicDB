#pragma once

#include "carddeck.h"
#include "types.h"
#include <string>

class Player {
	private:
		std::string		name;

		// OOP Composition (Player HAS A Card Deck)
		CardDeck		cardDeck;

	public:
		Player(std::string name, std::string fileName, Types* types);
		virtual ~Player();
};

