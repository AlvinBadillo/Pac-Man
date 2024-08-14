#pragma once
#include "Player.h"
#include "Entity.h"
#include "PowerUp.h"

class StrawberryPowerUp: public PowerUp{
    // private:
    //     bool active = false;
    // public:
    //     void activate(Player* p);
    //     void setActive(bool b);
    //     bool isActive();

    public:
        void activate(Player *player);

};      