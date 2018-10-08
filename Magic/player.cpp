#include "player.h"

Player::Player(std::string name, std::string fileName, Types* types) : cardDeck(fileName, types) {
	this->name = name;
}

Player::~Player() {
}
