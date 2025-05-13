/**
* @file wall.cc
* @brief Implementation of the wallController class for handling dynamic and static walls in the game.
* author Priya Bharathi Arul
* This file contains the implementation of methods responsible for generating static boundary walls,
* dynamically generating walls, moving them leftwards, and removing out-of-bounds walls.
* 
*/
#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()
#include "wall.h"

using namespace enviro;

// Put your implementations here
void wallController::init() {
    
    std::srand(std::time(0)); // Seed random number generator
    if (initialize) {
        create_boundary();
        create_dynamic_walls();
        initialize = false;
    }
}
// Update function to move and remove walls dynamically
void wallController::update() {
    std::vector<int> to_remove;

    for (int id : wall_ids) {
        Agent& wall = find_agent(id);
        double x = wall.x();
        double y = wall.y();


        //  Fix: Move walls using teleport instead of move()
        wall.teleport(x + wall_speed, y, 0);

        // Remove walls that exit the left side
        if (x < -250) {
            to_remove.push_back(id);
        }
    }

    // Remove walls that exited the screen
    for (int id : to_remove) {
        if (agent_exists(id)) {
                std::cout << "Attempting to remove dynamicBlockv with ID " << id << std::endl;
                remove_agent(id);
            }
        wall_ids.erase(std::remove(wall_ids.begin(), wall_ids.end(), id), wall_ids.end());
    }

    // Generate new walls on the right
    
    generation_count++;
    if (generation_count >= generation_wait)
    {
        generate_new_walls();
        generation_count = 0;
    }
}
// Create a static boundary around the maze


void wallController::create_boundary() {

    // Create the horizontal wall like the top and bottom ones
    std::vector<std::pair<double, double>> wallh_b = {{0, 200}, {50, 200}, {-50, 200}, {100, 200}, {-100, 200}, {150, 200}, {-150, 200}, {200, 200}, {-200, 200},{250, 200}, {-250,200},{300, 200},{-300,200},
                                                    {0, -200}, {50, -200}, {-50, -200}, {100, -200}, {-100, -200}, {150, -200}, {-150, -200}, {200, -200}, {-200, -200},{250, -200}, {-250,-200},{300, -200},{-300,-200}};
    for (auto& pos : wallh_b) {
        Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
        wall_ids.push_back(wall.get_id());
    }
// Update function to move and remove walls dynamically
    // Create the vertical wall like the right and left ones
    std::vector<std::pair<double, double>> wallv_1 = {{300, 0}, {300, 50}, {300, -50}, {300, 100}, {300, -100}, {300, 150}, {300, -150}, {300, 200},
                                                    {-330, 0}, {-330, 50}, {-330, -50}, {-330, 100}, {-330, -100}, {-330, 150}, {-330, -150}, {-330, 200}};
    for (auto& pos : wallv_1) {
        Agent& wall = add_agent("blockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
        wall_ids.push_back(wall.get_id());
    }
}


void wallController::create_dynamic_walls() {
    // Clear any existing walls before adding new ones
    for (int id : wall_ids) {
        remove_agent(id);
    }
    wall_ids.clear();

    // Define grid parameters
    int grid_width = 10;   // Number of columns
    int grid_height = 6;   // Number of rows
    int block_size = 50;   // Spacing between walls

    std::vector<std::pair<double, double>> wall_positions;
    // Create a static boundary around the maze
    // Randomly place walls in the grid
    for (int i = -grid_width / 2; i <= grid_width / 2; i++) {
        for (int j = -grid_height / 2; j <= grid_height / 2; j++) {
            // Randomly decide whether to place a wall at (i, j)
            if (rand() % 3 == 0) {  // Adjust probability for density (1 in 3 chance)
                double x = i * block_size;
                double y = j * block_size;
                wall_positions.push_back({x, y});
            }
        }
    }
// Create a set of dynamic walls at random positions
    // Create walls from generated positions
    for (auto& pos : wall_positions) {


       
        int i = (rand() % 2 == 0);
        if (i == 1){
            Agent& wall = add_agent("dynamicblockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"},{"static", true},{"immovable", true}});
            wall_ids.push_back(wall.get_id());
        }else{
            Agent& wall = add_agent("dynamicblockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"},{"static", true},{"immovable", true}});
            wall_ids.push_back(wall.get_id());
        }
    }
}
// Generate new walls dynamically as the maze shifts

void wallController::generate_new_walls() {
    int block_size = 50;
    int right_x = 280;  // Right boundary where new walls spawn

    if (rand() % 4 == 0) { // Adjust probability for new walls appearing
        double y = ((rand() % 6) - 3) * block_size;  // Randomly position new wall in range

        int i = (rand() % 2 == 0);
        if (i == 1){
            Agent& wall = add_agent("dynamicblockh", right_x, y, 0, {{"fill", "orange"}, {"stroke", "black"},{"static", true},{"immovable", true}});
            wall_ids.push_back(wall.get_id());
        }else{
            Agent& wall = add_agent("dynamicblockv", right_x, y, 0, {{"fill", "orange"}, {"stroke", "black"},{"static", true},{"immovable", true}});
            wall_ids.push_back(wall.get_id());
        }
    }
   
}
