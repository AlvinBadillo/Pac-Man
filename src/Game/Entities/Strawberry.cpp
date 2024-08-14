#include "Strawberry.h"

Strawberry::Strawberry(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 504, 48, 16, 16); 
}