#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 
#include "Player.h"
#include "Map.h"
#include "MapBuilder.h"

class ChoosePlayerState : public State {
private:

	Button *player1Button;
    Button *player2Button;
    int score=0;
	string player;
	ofImage mapImage;

public:
	ChoosePlayerState();
	~ChoosePlayerState();
	void setPlayer(string s);
	string getPlayer();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
    void setScore(int);
	void setActualPlayer(Player *p);
	void reset();
};
