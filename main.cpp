#include <iostream>
#include <vector>
#include <algorithm>
#include "State.h"
#include "Action.h"

using namespace std;

float gamma = 0.8f;

void printGrid(vector<vector<State>> states) {
    for (int y = 0; y < states.size(); y++) {
        for (int x = 0; x < states[0].size(); x++) {
            cout << states[y][x] << " ";
        }
        cout << endl;
    }
}


int main() {
    State s1(0.0f, {{EAction::down,  0.0f},
                    {EAction::right, 0.0f}});
    State s2(0.0f, {{EAction::left,  0.0f},
                    {EAction::down,  0.0f},
                    {EAction::right, 50.0f}});
    State s3(0.0f, {});
    State s4(0.0f, {{EAction::up,    0.0f},
                    {EAction::right, 0.0f}});
    State s5(0.0f, {{EAction::left,  0.0f},
                    {EAction::up,    0.0f},
                    {EAction::right, 0.0f}});
    State s6(0.0f, {{EAction::left, 0.0f},
                    {EAction::up,   100.0f}});

    vector<vector<State>> states = {{s1, s2, s3},
                                    {s4, s5, s6}};
    bool converged = true;

    int maxIterations = 10;
    for (int i = 0; i < maxIterations; i++) {
        cout << "Iteration: " << i+1 << endl;
        printGrid(states);
        cout << endl << endl;
        converged = true;
        for (int y = 0; y < states.size(); y++) {
            for (int x = 0; x < states[0].size(); x++) {
                vector<float> rewards = {};
                for (Action a : states[y][x].actions) {
                    int nextX = x, nextY = y;
                    switch (a.action) {
                        case EAction::up:
                            nextY--;
                            break;
                        case EAction::left:
                            nextX--;
                            break;
                        case EAction::right:
                            nextX++;
                            break;
                        case EAction::down:
                            nextY++;
                            break;
                    }
                    rewards.push_back(a.reward + gamma * states[nextY][nextX].utility);
                }
                if(!rewards.empty() && rewards.size() > 0){
                    float utility = *max_element(rewards.begin(), rewards.end());
                    if(states[y][x].utility != utility){
                        converged = false;
                    }
                    states[y][x].utility = utility;
                }

            }
        }
        if(converged){
            cout << "Converged after " << (i+1) << " iterations" << endl;
            break;
        }
    }


    return 0;
}