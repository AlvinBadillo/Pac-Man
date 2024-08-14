#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"
#include "EntityManager.h"

class GameState: public State{
    public: 
        GameState();
		~GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		void setSprite(string s);
		string getSprite();
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		string spriteImg;
		Map* map;
		int finalScore=0;
		//EntityManager* entityManager;

};