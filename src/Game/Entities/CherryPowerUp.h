#pragma once

#include "PowerUp.h"
#include "Player.h"

class CherryPowerUp: public PowerUp{

    public:
        void activate(Player *player);

};