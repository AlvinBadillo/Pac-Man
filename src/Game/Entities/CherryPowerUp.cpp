#include "CherryPowerUp.h"

void CherryPowerUp::activate(Player *player){
    // vector<Entity*> ent = player->getEntityManager()->entities;
    // int randomNum = (ofRandom(0,ent.size()));
    // int randX = ent[randomNum]->getBounds().getX();
    // int randY = ent[randomNum]->getBounds().getY();
    // player->setX(randX);
    // player->setY(randY);


    int random = ofRandom(0, player->getEntityManager()->entities.size());
    player->setX(player->getEntityManager()->entities[random]->getX());
    player->setY(player->getEntityManager()->entities[random]->getY());
}