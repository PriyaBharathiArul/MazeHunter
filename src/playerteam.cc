#include <iostream>
#include "playerteam.h"

using namespace enviro;

void playerteamController::init() {
    // Add Welcome message
    enviro::Agent& msg_agent_title = add_agent("message", -335, -300, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_title.label("Welcome To The Maze Hunter Game..!! It's Do or Die. Survival of the skillful..Lets Start..!!", 0, 0);

    // Add Tips to the player
    enviro::Agent& msg_agent_tip = add_agent("message", -335, -280, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_tip.label("Use the a,s,d,f to navigate (Tap the keys, gives better control).. use space bar to shoot in the last pressed direction..use the momemtum for ur advantage", 0, 0);


    // watch for emit GameComplete event
     watch("GameCompleted", [&](Event& e) {
        // remove the level  message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;
        create_gamecomplete_message(); //calling create_gamecomplete_message to create the message
    }); 

    // If the initialize flag is true, then create the player and the level message.
    if (initialize) {
         initialize = false; // Set the initialize flag to false.
         // Create the player
        enviro::Agent& player_agent = add_agent("Player", 50, 50, 0, {{"fill", "blue"}, {"stroke", "black"}});
        player_id = player_agent.get_id(); // save the player id

        create_message();
    }       
}

void playerteamController::update() {
    //check if the player is killed 
    if ((! agent_exists(player_id))) {
        // delete the level message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;
        create_gameover_message(); // Create the game over message
    }
}    

void playerteamController::create_message(){
    // Create the message for level
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Enemies will CHASE and SHOOT if you get too close..!!", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_gameover_message(){
    // Create the game over message
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Game Over..!!!!! The hunter got killed.. Re-launch the game if you like to try again.! ", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_gamecomplete_message(){
    // Create the game over message
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Congratulations..!! You are a true HUNTER.! Re-launch the game if you like to play again.!", 0, 0);
    message_id = msg_agent.get_id();
}