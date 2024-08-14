#include "ChoosePlayerState.h"
#include "GameOverState.h"
#include "Player.h"
#include "Map.h"

ChoosePlayerState::ChoosePlayerState(){
	player1Button = new Button(ofGetWidth()/3, ofGetHeight()/2, 50, 50, "Yellow Pacman");
    player2Button = new Button(2*ofGetWidth()/3, ofGetHeight()/2, 50, 50, "RUM Pacman");
}
void ChoosePlayerState::tick() {
	player1Button->tick();
    player2Button->tick();
	if(player1Button->wasPressed()){
        setPlayer("Pac");
        setPreviousState("Menu");
		setNextState("Game");
		setFinished(true);

	}
    if(player2Button->wasPressed()){
        setPlayer("Rum");
        setPreviousState("Menu");
        setNextState("Game");
		setFinished(true);

	}
}

void ChoosePlayerState::render() {
	ofSetColor(ofColor::yellow);
    ofDrawBitmapString("Choose Your Character!", ofGetWidth() / 2 - 50, ofGetHeight() / 4);
	player1Button->render();
    player2Button->render();

}

void ChoosePlayerState::keyPressed(int key){
	
}

void ChoosePlayerState::mousePressed(int x, int y, int button){
	player1Button->mousePressed(x, y);
    player2Button->mousePressed(x, y);

}
void ChoosePlayerState::setScore(int sc){
    score = sc;
}
void ChoosePlayerState::reset(){
	player1Button->reset();
    player2Button->reset();
}

void ChoosePlayerState::setPlayer(string s){
    this->player = s;
}
void ChoosePlayerState::setActualPlayer(Player* p){
    p->setSprite((this->getPlayer()));
}
string ChoosePlayerState::getPlayer(){
    return player;
}
ChoosePlayerState::~ChoosePlayerState(){
	delete player1Button;
    delete player2Button;
}