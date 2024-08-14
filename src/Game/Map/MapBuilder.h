#pragma once

#include "ofMain.h" 
#include "Map.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "Cherry.h"
#include "Strawberry.h"
#include "Apple.h"

class MapBuilder {
    public:
        MapBuilder(string p);
	    Map* createMap(ofImage);
        void setSpriteImg(string s);
        string getSpriteImg();
	private:
        vector<ofImage> bound;
        int pixelMultiplier;
        ofColor boundBoundBlock;
        string spritePlayer;
        ofColor pacman;
        ofColor ghostC;
	    ofColor dotC;
	    ofColor bigDotC;
        ofImage pacmanSpriteSheet;
        ofImage tempBound;
        ofImage getSprite(ofImage, int, int);
        EntityManager* entityManager;
        
};