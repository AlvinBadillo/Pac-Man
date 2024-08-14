#pragma once

#include "Player.h"

class Player;

class PowerUp{
    public:
        virtual void activate(Player *player);
};