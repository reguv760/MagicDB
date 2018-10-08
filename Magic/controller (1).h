#pragma once

#include "constants.h"
#include "rules.h"
#include <vector>
#include <string>

class Controller {
	private:
		// OOP Composition: the Controler HAS A Rules
		Rules*	rules;

	public:
		Controller();
		~Controller();
};
