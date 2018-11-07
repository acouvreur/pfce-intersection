//
// Created by alexisc on 07/11/18.
//

#include "MyGameEngine.h"


void MyGameEngine::idle(){

    for (auto &segment : *segments) {
        segment->tick();
    }

}