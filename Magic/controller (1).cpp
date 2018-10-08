#include "controller.h"

Controller::Controller() {
	rules = new Rules();
}

Controller::~Controller() {
	delete rules;
}
