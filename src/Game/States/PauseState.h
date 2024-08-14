#pragma once

#include "State.h"
#include "Button.h"

class PauseState: public State{
    public:
        PauseState();
        //~PauseState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);          

    private:
	Button *resumeButton;
	Button *quitButton;
};
