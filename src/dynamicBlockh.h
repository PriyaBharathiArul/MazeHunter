#ifndef __DYNAMIC_BLOCKH_AGENT__H
#define __DYNAMIC_BLOCKH_AGENT__H 

#include "enviro.h"

using namespace enviro;

class dynamicBlockhController : public Process, public AgentInterface {
    public:
        dynamicBlockhController() : Process(), AgentInterface() {}

        void init() {}
        void start() {}
        void update() {}
        void stop() {}

    private:
        bool marked_for_deletion = false;
};

class dynamicBlockh : public Agent {
    public:
        dynamicBlockh(json spec, World& world) : Agent(spec, world) {
            add_process(c);
        }
    private:
        dynamicBlockhController c;
};

DECLARE_INTERFACE(dynamicBlockh)

#endif
