#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "Cherry.h"
#include "Strawberry.h"
#include "StrawberryPowerUp.h"
#include "Apple.h"
#include "ApplePowerUp.h"
#include "PowerUp.h"
#include "CherryPowerUp.h"
#include "ChoosePlayerState.h"

Player::Player(int x, int y, int width, int height, EntityManager* em, string spritePlay) : Entity(x, y, width, height){
    spawnX = x;
    spawnY = y;
    pacmanSpriteSheet.load("images/Background.png");

    if (spritePlay == "Pac"){
        sprite.load("images/pacman.png");
    }
    else{
        sprite.load("images/rumman.png");
    }
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;

    moving = MLEFT;
    
}
void Player::tick(){

    checkCollisions();

    if (moving == MUP && canMoveUp) 
        facing = UP;
    else if (moving == MDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MRIGHT && canMoveRight)
        facing = RIGHT;

    if(facing == UP && canMoveUp){
        y-= speed * speedFactor;
        walkUp->tick();
    }else if(facing == DOWN && canMoveDown){
        y+=speed * speedFactor;
        walkDown->tick();
    }else if(facing == LEFT && canMoveLeft){
        x-=speed * speedFactor;
        walkLeft->tick();
    }else if(facing == RIGHT && canMoveRight){
        x+=speed * speedFactor;
        walkRight->tick();
    }

    if(faster){
        fasterCounter--;
        if(fasterCounter == 0){
            faster = false; 
            this->setSpeedFactor(1);
        }
    }
    if(isInvincible() ==true){
        timer--;
        if(timer == 0){
            this->setInvincible(false);

        }
    }
    
}


void Player::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());
    if(isInvincible() == false){
    if(facing == UP)
        walkUp->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN)
        walkDown->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT)
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT)
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
    else{
        // timer++;
        // if(timer == 7 * 30){
        //     setInvincible(false);
        //     timer = 0;
        //     if(facing == UP)
        //         walkUp->getCurrentFrame().draw(x, y, width, height);
        //     else if(facing == DOWN)
        //         walkDown->getCurrentFrame().draw(x, y, width, height);
        //     else if(facing == LEFT)
        //         walkLeft->getCurrentFrame().draw(x, y, width, height);
        //     else if(facing == RIGHT)
        //         walkRight->getCurrentFrame().draw(x, y, width, height);
        // }
    }
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Health: ", ofGetWidth()/2 + 100, 50);
    ofDrawBitmapString("Power Ups: ", ofGetWidth()/2 + 100, 30);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +200, 50, 10);
    }
    ofDrawBitmapString("Score:"  + to_string(score), ofGetWidth()/2-200, 50);

    Cherry* cherry = nullptr;
    Strawberry* strawberry = nullptr;
    Apple* apple = nullptr;

    for(unsigned int j = 0; j < powerUpList.size(); j++){
        if(dynamic_cast<CherryPowerUp*>(powerUpList[j])){
            cherry = new Cherry(static_cast<int>(ofGetWidth()/2 + 25*j) +200 -12, 15, 24, 24, pacmanSpriteSheet);
            cherry->render();
        }
        if(dynamic_cast<StrawberryPowerUp*>(powerUpList[j])){
            strawberry = new Strawberry(static_cast<int>(ofGetWidth()/2 + 25*j) +200 -12, 15, 24, 24, pacmanSpriteSheet);
            strawberry->render();
        }
        if(dynamic_cast<ApplePowerUp*>(powerUpList[j])){
            apple = new Apple(static_cast<int>(ofGetWidth()/2 + 25*j) +200 -12, 15, 24, 24, pacmanSpriteSheet);
            apple->render();
        }
    }
    delete cherry;
    delete strawberry;
    delete apple;
}
void Player::setInvincible(bool b){
    this->invincible = b;
}
bool Player::isInvincible(){
    return invincible;
}

void Player::setSpriteImage(string s){
    spriteImg = s;
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
            moving = MUP;
            break;
        case 's':
            moving = MDOWN;
            break;
        case 'a':
            moving = MLEFT;;
            break;
        case 'd':
            moving = MRIGHT;;
            break;
        case 'n':
            die();
            break;
        case 'm':
            if(health < 3){
                health++;
            }
            break;
        case ' ':
            if(powerUpList.size() != 0){
                powerUpList[0]->activate(this);
                powerUpList.erase(powerUpList.begin());

            }
            break;
    } 
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

int Player::getHealth(){ return health; }
int Player::getScore(){ return score; }
FACING Player::getFacing(){ return facing; }
void Player::setHealth(int h){ health = h; }
void Player::setFacing(FACING facing){ this->facing = facing; }
void Player::setScore(int h){ score = h; }

void Player::checkCollisions(){
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
    //StrawberryPowerUp* strawberry = new StrawberryPowerUp;

    for(BoundBlock* boundBlock: em->boundBlocks){
        if(this->getBounds(x, y-speed * speedFactor).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed * speedFactor).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed * speedFactor, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed * speedFactor, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }

    for(Entity* entity:em->entities){  //TODO To use this, power ups must be enitites and added to entityManeger entities em->entities
        if(collides(entity)){   
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
                score += 10;        //this adds 10 points
            }
            if(dynamic_cast<BigDot*>(entity)){
                score +=20;         //this adds s20 points
                em->setKillable(true);
            }
            if(dynamic_cast<Cherry*>(entity)){
                entity->remove = true;
                score += 30;
                if(powerUpList.size() < 3){
                    CherryPowerUp* cherryPowerUp = new CherryPowerUp;
                    powerUpList.push_back(cherryPowerUp);
                }
            }
            if(dynamic_cast<Strawberry*>(entity)){
                entity->remove = true;
                score += 30;

                if(powerUpList.size() < 3){
                    StrawberryPowerUp* strawberryPowerUp = new StrawberryPowerUp;
                    powerUpList.push_back(strawberryPowerUp);
                }

                // if(powerUpList.size() < 3){
                //     StrawberryPowerUp* strawberryPowerUp = new StrawberryPowerUp;
                //     powerUpList.push_back(strawberryPowerUp);
                // }                
            }           
            if(dynamic_cast<Apple*>(entity)){
                entity->remove = true;
                score += 30;
                if(powerUpList.size() < 3){
                    ApplePowerUp* applePowerUp = new ApplePowerUp;
                    powerUpList.push_back(applePowerUp);
                }
            }
            //TODO: Add if collision with new power ups
        }
    }
    for(Entity* entity:em->ghosts){
        if(collides(entity)){
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable())
                ghost->remove = true;
            else if(this->isInvincible() == false){
                die();
            }
        }
    }
}

void Player::die(){
    health--;
    x = spawnX;
    y = spawnY;
    this->setSpeedFactor(1);

}

Player::~Player(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}

EntityManager *Player::getEntityManager(){
    return em;
}

string Player::getSprite(){
    return spriteImg;
}
void Player::setSprite(string s){
    this->spriteImg = s;
}

void Player::setSpeedFactor(int speedFactor){
    this->speedFactor = speedFactor;
}

void Player::setFaster(bool faster){
    this->faster = faster;
}
void Player::setFasterCounter(int fasterCounter){
    this->fasterCounter = fasterCounter * ofGetFrameRate();
}

void Player::setTimer(int timer){
    this->timer = timer * ofGetFrameRate();
}
