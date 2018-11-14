//
// Created by alexisc on 07/11/18.
//

#include "MyGraphicEngine.h"
#include <string>
#include <cstdio>

void MyGraphicEngine::Draw(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the screen and the depth buffer
    glLoadIdentity();									// Reset The Projection Matrix

    frame++;
    time=glutGet(GLUT_ELAPSED_TIME);

    if (time - timebase > 1000) {
        fps = frame * 1000.0 / (time - timebase);
        timebase = time;
        frame = 0;
    }

    std::cout << segments->size() << ":" << fps << std::endl;

    char *fpsC = static_cast<char *>(malloc(sizeof(char) * 256));
    char *nbSeg = static_cast<char *>(malloc(sizeof(char) * 256));
    char* col = static_cast<char *>(malloc(sizeof(char) * 256));

    sprintf(nbSeg, "Size: %lu", segments->size());
    sprintf(fpsC, "FPS: %2.lf", fps);
    sprintf(col, "Collisions: %i", *collisions);

    GraphicPrimitives::drawText2D(col, 0, 0.90, 1, 1, 1);
    GraphicPrimitives::drawText2D(nbSeg, -0.98, 0.90, 1, 1, 1);
    GraphicPrimitives::drawText2D(fpsC, 0.75, 0.90, 1, 1, 1);

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