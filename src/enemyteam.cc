#include <iostream>
#include "enemyteam.h"

using namespace enviro;


void enemyteamController::init() {


    // check the level, initialize flags and create the enemy team
    if (initialize) {
        initialize = false; // Set the initialize flag to false.
        create_enemies(); //calling create_enemies to create the enemy team
    }
}

void enemyteamController::create_enemies(){
    // Create the enemies for level 
    enviro::Agent& enemy_agent_1 = add_agent("enemy", 150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("enemy", -150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_3 = add_agent("enemy", 100, -50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_4 = add_agent("enemy", -100, 150, 0, {{"fill", "red"}, {"stroke", "black"}});

    // save the agent id in a vector
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
    enemy_ids.push_back(enemy_agent_3.get_id());
    enemy_ids.push_back(enemy_agent_4.get_id());
}

void enemyteamController::update() {
    
    // if all the enemies are dead, then emit level event.
    if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (! agent_exists(enemy_ids[2])) && (! agent_exists(enemy_ids[3]))) {
        emit(Event("GameCompleted")); // emit GameCompleted event
        publish_gamecomplete = true;
    }
}
