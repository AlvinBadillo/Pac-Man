#include "ApplePowerUp.h"

void ApplePowerUp::activate(Player *player){
    player->setSpeedFactor(2);
    player->setFaster(true);
    player->setFasterCounter(7);
}