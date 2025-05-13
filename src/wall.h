#ifndef __WALL_AGENT__H
#define __WALL_AGENT__H 

#include "enviro.h"
#include <set>

using namespace enviro;

class wallController : public Process, public AgentInterface {
    public:
        wallController() : Process(), AgentInterface() {}

        void init();
        void start() {}
        void update();
        void stop() {}

        void create_boundary();   // Add fixed boundary walls
        // New function for dynamic wall creation
        void create_dynamic_walls();
        void generate_new_walls();  // Function to generate new walls on the righ

    private:
        bool initialize = true;
        std::vector<int> wall_ids; // Stores wall entity IDs
        double wall_speed = -2.0;
        int generation_wait = 3;
        int generation_count = 0;

};

class wall : public Agent {
    public:
        wall(json spec, World& world) : Agent(spec, world) {
            add_process(c);
        }
    private:
        wallController c;
};

DECLARE_INTERFACE(wall)

#endif
