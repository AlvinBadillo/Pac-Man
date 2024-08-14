#include "PauseState.h"

PauseState::PauseState(){
    resumeButton = new Button(ofGetWidth()/3, ofGetHeight()/2, 64, 50, "Resume");
    quitButton = new Button(2*ofGetWidth()/3, ofGetHeight()/2, 64, 50, "Quit");
}
void PauseState::tick() {
    resumeButton->tick();
    quitButton->tick();
	if(resumeButton->wasPressed()){
        setPause(false);
    }
    if(quitButton->wasPressed()){
        ofExit();
    }
}
void PauseState::render() {
    ofSetColor(ofColor::yellow);
    ofDrawBitmapString("Pause State", ofGetWidth() / 2 - 50, ofGetHeight() / 4);
    ofDrawBitmapString("Natha es extremadamente gay", ofGetWidth() / 2 - 50 + 30, ofGetHeight() / 4 + 30);

	resumeButton->render();
    quitButton->render();
}
void PauseState::reset(){

}

void PauseState::keyPressed(int key){

}
void PauseState::mousePressed(int x, int y, int button){
    resumeButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);
}
