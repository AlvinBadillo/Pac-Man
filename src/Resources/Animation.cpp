#include "Animation.h"

Animation::Animation(int speed, std::vector<ofImage> frames){
    this->speed = speed;
    this->frames = frames;
    this->index = 0;
    this->timer = 0;
}

void Animation::tick(){
    timer += 1;
    if(timer > speed * speedFactor){
        index++;
        timer = 0;
        if(index == frames.size()){
            index = 0;
        }
    }
}

ofImage Animation::getCurrentFrame(){
    return frames[index];
}

// void Animation::setSpeedFactor(int speedFactor){
//     this->speedFactor = speedFactor;
// }