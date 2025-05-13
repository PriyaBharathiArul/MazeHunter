#ifndef __DYNAMIC_BLOCKV_AGENT__H
#define __DYNAMIC_BLOCKV_AGENT__H 

#include "enviro.h"

using namespace enviro;

class dynamicBlockvController : public Process, public AgentInterface {
    public:
        dynamicBlockvController() : Process(), AgentInterface() {}

        void init() {}
        void start() {}
        void update() {}
        void stop() {}
    
    private:
        bool marked_for_deletion = false;
};

class dynamicBlockv : public Agent {
    public:
        dynamicBlockv(json spec, World& world) : Agent(spec, world) {
            add_process(c);
        }
    private:
        dynamicBlockvController c;
};

DECLARE_INTERFACE(dynamicBlockv)

#endif
