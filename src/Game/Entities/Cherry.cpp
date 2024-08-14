#include "Cherry.h"

Cherry::Cherry(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 30*16 + 8, 3*16, 16, 16);
}