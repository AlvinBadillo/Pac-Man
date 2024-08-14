#include "GameState.h"
#include "Entity.h"
#include "Map.h"
#include "Player.h"


GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	//mapImage.load("images/map1.png");
	mapImage.load("images/map2.png"); //change default map
	//map = MapBuilder().createMap(mapImage);
	
	map = MapBuilder(getSprite()).createMap(mapImage);
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}

	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if(map->getEntityManeger()->entities.size() == 0){
		finalScore = map->getPlayer()->getScore();
		setWon(true);
	}
	
}
void GameState::render() {
	map->render();
}
void GameState::setSprite(string s){
	this->spriteImg = s;
}
string GameState::getSprite(){
	return spriteImg;
}
void GameState::keyPressed(int key){
	// if(key == 'c'){
	// 	CherryPowerUp *cherry = new CherryPowerUp();
	// 	cherry->activate();
	// }
	if(key == 'p'){
		setPause(true);
	}
	else if(key == 'y'){
		finalScore = map->getPlayer()->getScore();
		setWon(true);
	}
	else{
		map->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
	map = MapBuilder(getSprite()).createMap(mapImage); //Resets entities (part 5 of phase 1)
	setWon(false);
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}