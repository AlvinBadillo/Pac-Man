#pragma once

#include "ofMain.h"

class State {
	public:
		State() {}
		virtual void reset() = 0;
		virtual void tick() = 0;
		virtual void render() = 0;
		virtual void keyPressed(int key) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;

		virtual void keyReleased(int key){}
		void mouseMoved(int x, int y){}
		void mouseDragged(int x, int y, int button){}
		void mouseReleased(int x, int y, int button){}
		void mouseEntered(int x, int y){}
		void mouseExited(int x, int y){}
		void windowResized(int w, int h){}
		void gotMessage(ofMessage msg){}
		void dragEvent(ofDragInfo dragInfo){}
		bool hasFinished(){
			return finished;
		}

		string getNextState(){
			return nextState;
		}
		
		string getPreviousState(){
			return previousState;
		}
		void setFinished(bool finished){
			this->finished = finished;
		}
		//add a option to see if its paused or not
		void setPause(bool paused){
			this->paused = paused;
		}
		bool hasPaused(){
			return paused;
		}


		void setWon(bool won){
			this->won = won;
		}
		bool hasWon(){
			return won;
		}

		void setNextState(string nextState){
			this->nextState = nextState;
		}
		void setPreviousState(string previousState){
			this->previousState = previousState;
		}

		bool getPlayAgain(){
			return playAgain;
		}

        void setPlayAgain(bool playAgain){
			this->playAgain = playAgain;
		}



	private:
		string nextState;
		string previousState;
		bool finished = false;
		bool paused = false;
		bool won = false;
		bool playAgain = false;

};