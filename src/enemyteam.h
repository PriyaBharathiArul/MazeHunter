/**
 * @file enemyteam.h
 * @brief This file declares the enemy team class and its methods.
 * The enemyteam class is a subclass of the Agent class and is used to create a team of enemies.
 * It is used to create a team of enemies that chase the player and shoot at the player depending on the current level of the game.
 * 
 * @author Priya Bharathi Arul
 *
 * // This header file declares the enemyteam class and its methods.
 */
#ifndef __ENEMYTEAM_AGENT__H
#define __ENEMYTEAM_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class enemyteamController
 * @brief The enemyteamController class is used to control the enemyteam class. It is a subclass of the Process and AgentInterface classes.
 *
 */
class enemyteamController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the enemyteamController class.
     */
    enemyteamController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the enemyteamController class.
     * It handles the initialization of the enemy team.
     * It handles the creation of the enemy team, depending on the current level of the game.
     * It maintains the velocity of the enemy_ids in the team.
     * It handles the setup of event listeners for the enemy team.
     */
    void init() ;

    /**
     * @brief The start method for the enemyteamController class.
     * does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the enemyteamController class.
     * It handles the publishing of emit events like gamecomplete.
     */
    void update() ;

    /**
     * @brief The stop method for the enemyteamController class.
     */
    void stop() {}

    /**
     * @brief The create_enemies method for the enemyteamController class.
     * It creates the enemies for level .
     */
    void create_enemies();

    private:
    // Set the initialize flag to true.
    bool initialize = true;
    std::vector<int> enemy_ids; // track the ids of the enemies in the team.
    bool publish_gamecomplete = true;

};

/**
 * @class enemyteam
 * @brief The enemyteam class is used to create a team of enemies.
 * The enemyteam class is a subclass of the Agent class and is used to create a team of enemies.
 */
class enemyteam : public Agent {
    public:
    /**
     * @brief The constructor for the enemyteam class.
     * @param spec The JSON specification for the enemy team.
     * @param world The world in which the enemy team is created.
     */
    enemyteam(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    // The enemyteamController object that controls the enemy team.
    enemyteamController c;
};

DECLARE_INTERFACE(enemyteam)

#endif