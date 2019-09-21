//
// Created by tamir on 2019/09/20.
//


#ifndef AS5_STATE_H
#define AS5_STATE_H


#include <vector>
#include <ostream>
#include "Action.h"

class State {
public:
    float utility;
    std::vector<Action> actions;

    State(float utility, std::vector<Action> actions);

    friend std::ostream &operator<<(std::ostream &os, const State &state);
};


#endif //AS5_STATE_H
