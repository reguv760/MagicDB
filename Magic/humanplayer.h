#pragma once

#include "player.h"
#include "types.h"
#include <string>

// Private inheritance: only the child class will be able to call parent public functions.
// Other classes will still see the parent public functions but will be unable to call them!
class HumanPlayer : public Player {
	private:

	public:
		HumanPlayer(std::string name, std::string fileName, Types* types);
		virtual ~HumanPlayer();

		void test();
};

