#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include <vector>


class PowerUp;

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        int timer;
        bool walking = false;
        bool invincible = false;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        std::vector<PowerUp*> powerUpList;
        string spriteImg;
        int speedFactor = 1;
        bool faster;
        int fasterCounter;
        ofImage pacmanSpriteSheet;



    public:
        Player(int, int, int , int, EntityManager*, string);
        ~Player();
        int getHealth();
        int getScore();
        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setFacing(FACING facing);
        string getSprite();
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();
        bool isInvincible();
        void setInvincible(bool b);
        EntityManager *getEntityManager();
        void setSprite(string s);
        void setSpriteImage(string s);
        void setSpeedFactor(int speedFactor);
        void setFaster(bool faster);
        void setFasterCounter(int fasterCounter);
        void setTimer(int timer);
        // Animation* getWalkUpAnimation();
        // Animation* getWalkDownAnimation();
        // Animation* getWalkLeftAnimation();
        // Animation* getWalkRightAnimation();
        
};
