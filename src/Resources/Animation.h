#pragma once

#include "ofMain.h"

class Animation {

private:
	int speed, index;
	int timer;
	std::vector<ofImage> frames;
	bool end = false;
	int speedFactor = 2;
public:
	Animation(int speed, std::vector<ofImage> frames);
	void tick();
	ofImage getCurrentFrame();
	void reset();
	// void setSpeedFactor(int speedFactor);

};