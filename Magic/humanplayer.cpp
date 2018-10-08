#include "humanplayer.h"

// : Player(...) is the initializer list. Pass to the parent constructor what it expects.
HumanPlayer::HumanPlayer(std::string name, std::string fileName, Types* types) : Player(name, fileName, types) {
}

HumanPlayer::~HumanPlayer() {
}

void HumanPlayer::test() {
	
}