#pragma once

#include "State.h"
#include "Button.h"
#include "Player.h"

class WinState: public State{
    
    public:
        WinState();
        void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
        void setFinalScore(int finalScore);
    private:
        Button *playAgainButton;
        Button *quitButton;
        int finalScore = 0;

};