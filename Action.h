//
// Created by tamir on 2019/09/20.
//

#ifndef AS5_ACTION_H
#define AS5_ACTION_H


enum EAction{
    up,
    down,
    left,
    right
};

class Action {
public:
    EAction  action;
    float reward;

    Action(EAction action, float reward);
};


#endif //AS5_ACTION_H
