#include "rules.h"

Rules::Rules() {
	if (!create()) {
		std::string message = "Rules::Rules(): unable to create rules. File not found or errors found: " + DATA_PATH + RULES_FILE;
		throw std::runtime_error(message.c_str());
	}
}

Rules::~Rules() {
}

bool Rules::create() {
	bool valid = true;

	std::vector<std::string> messages;
	std::vector<std::string> errors;
	std::vector<std::string> warnings;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, RULES_FILE, messages);

	if (!rootTree->isEmpty()) {
		if (rootTree->getErrors() == 0) {
			// Get the root Tree's subtrees
			std::vector<XMLTree<std::string, std::string>*>  rootTreeSubTrees = rootTree->getTreesInPreOrder();

			for (XMLTree<std::string, std::string>* tree : rootTreeSubTrees) {
				// <type> tags are organized by the tag name (type), not by the tag value!
				// Retrieved in-order (alphabetical by "type") causes them to be retrieved last-type-tag first.
				// Retrieved in-pre-oder causes them to be retrieved first-type-tag first.
				std::vector<std::pair<std::string, std::string>> nodes = tree->getNodesInOrder();

				if (tree->getTreeKey() == "card-types") {
					for (std::pair<std::string, std::string> pair : nodes) {
						if (!cardTypes.emplace(std::make_pair(pair.second, cardTypes.size())).second || !cardTypeIndexes.emplace(std::make_pair(cardTypeIndexes.size(), pair.second)).second) {
							errors.emplace_back("Rules::create(): <card-types>: duplicate <type> tag found: " + pair.second);
						}
					}
				}
				else if (tree->getTreeKey() == "colors") {
					for (std::pair<std::string, std::string> pair : nodes) {
						if (!cardColors.emplace(std::make_pair(pair.second, cardColors.size())).second || !cardColorIndexes.emplace(std::make_pair(cardColorIndexes.size(), pair.second)).second) {
							errors.emplace_back("Rules::create(): <colors>: duplicate <color> tag found: " + pair.second);
						}
					}
				}
			}
		}
		else {
			errors.emplace_back("Rules::create(): Error(s) found parsing the Rules file. Please correct and re-run.");
		}
	}
	else {
		errors.emplace_back("Rules::create(): Rules file is empty or was not found");
	}

	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}

	return valid;
}

bool Rules::findCardType(std::string name) {
	bool found = false;

	/*
	// Long way
	const std::map<std::string, int>::const_iterator iterator = cardTypes.find(name);

	if (iterator != cardTypes.end()) {
		found = true;
	}
	*/

	// Short way
	if (cardTypes.find(name) != cardTypes.end()) {
		found = true;
	}

	return found;
}

bool Rules::findCardType(int number) {
	bool found = false;

	if (cardTypeIndexes.find(number) != cardTypeIndexes.end()) {
		found = true;
	}

	return found;
}

int Rules::getCardType(std::string name) {
	int number = 0;

	const std::map<std::string, int>::const_iterator iterator = cardTypes.find(name);

	if (iterator != cardTypes.end()) {
		number = iterator->second;
	}

	return number;
}

std::string Rules::getCardType(int number) {
	std::string name = "";

	const std::map<int, std::string>::const_iterator iterator = cardTypeIndexes.find(number);

	if (iterator != cardTypeIndexes.end()) {
		name = iterator->second;
	}

	return name;
}

bool Rules::addCardType(std::string name, int number) {
	bool added = false;

	/*
	// Long way
	const std::pair<std::map<std::string, int>::iterator, bool> result = cardTypes.emplace(std::make_pair(name, number));

	if (result.second) {
		const std::pair<std::map<int, std::string>::iterator, bool> result = cardTypeIndexes.emplace(std::make_pair(number, name));

		if (result.second) {
			added = true;
		}
	}
	*/

	// Short way
	if (cardTypes.emplace(std::make_pair(name, number)).second && cardTypeIndexes.emplace(std::make_pair(number, name)).second) {
		added = true;
	}

	return added;
}
