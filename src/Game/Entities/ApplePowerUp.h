#pragma once

#include "PowerUp.h"
#include "Player.h"

class ApplePowerUp: public PowerUp{

    public:
        void activate(Player *player);

};