# include "WinState.h"

WinState::WinState(){
    playAgainButton = new Button(ofGetWidth()/3, ofGetHeight()/2, 64, 50, "Play Again");
    quitButton = new Button(2*ofGetWidth()/3, ofGetHeight()/2, 64, 50, "Quit Game");

}
void WinState::reset(){

}
void WinState::tick(){
    playAgainButton->tick();
    quitButton->tick();
	if(playAgainButton->wasPressed()){
        setPlayAgain(true);
    }
    if(quitButton->wasPressed()){
        ofExit();
    }
}
void WinState::render(){
    playAgainButton->render();
    quitButton->render();
    ofDrawBitmapString("Final Score: " + to_string(finalScore), ofGetWidth()/2 - 22, ofGetHeight()/2, 50);
}
void WinState::keyPressed(int key){

}
void WinState::mousePressed(int x, int y, int button){
    playAgainButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);
}

void WinState::setFinalScore(int finalScore){
    this->finalScore = finalScore;
}