//
// Created by alexisc on 07/11/18.
//

#include "MyGraphicEngine.h"
#include <string>

void MyGraphicEngine::Draw(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the screen and the depth buffer
    glLoadIdentity();									// Reset The Projection Matrix
    for (auto &segment : *segments) {
        segment->draw();
    }



    x1 += vx1;
    if (x1 > 0.9f || x1 < -0.9f) {
        vx1 = -vx1;
        x1 += vx1;
    }

    x2 += vx2;
    if (x2 > 0.9f || x2 < -0.9f) {
        vx2 = -vx2;
        x2 += vx2;
    }

}