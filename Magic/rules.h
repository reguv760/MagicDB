#pragma once

#include "constants.h"
#include "tools.h"
#include "xmltree.h"
#include "xmlnode.h"
#include <map>
#include <string>
#include <vector>

class Rules {
	private:
		std::map<std::string, int>		cardTypes;
		std::map<int, std::string>		cardTypeIndexes;
		std::map<std::string, int>		cardColors;
		std::map<int, std::string>		cardColorIndexes;

		// Helper functions
		bool create();

		public:
			Rules();
			~Rules();

			bool		findCardType(std::string name);
			bool		findCardType(int number);
			int			getCardType(std::string name);
			std::string getCardType(int number);
			bool		addCardType(std::string name, int number);
};

