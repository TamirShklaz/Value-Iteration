//
// Created by tamir on 2019/09/20.
//

#include "State.h"

#include <utility>
using  namespace std;

State::State(float utility, vector <Action> actions) : utility(utility), actions(std::move(actions)) {}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << state.utility;
    return os;
}
