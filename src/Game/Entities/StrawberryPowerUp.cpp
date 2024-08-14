#include "StrawberryPowerUp.h"
#include "Player.h"
#include "Map.h"
#include "EntityManager.h"
#include "Ghost.h"

// void StrawberryPowerUp::activate(Player* p){
//     setActive(true);
//     p->setInvincible(true);
// }
// bool StrawberryPowerUp::isActive(){
//     return active;
// }
// void StrawberryPowerUp::setActive(bool b){
//     this->active = b;
// }

void StrawberryPowerUp::activate(Player *player){

    // int random = ofRandom(0, player->getEntityManager()->entities.size());
    // player->setX(player->getEntityManager()->entities[random]->getX());
    // player->setY(player->getEntityManager()->entities[random]->getY());
    player->setInvincible(true);
    player->setTimer(7);
}
