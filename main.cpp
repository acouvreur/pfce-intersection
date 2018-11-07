#include <iostream>

#include <GL/glut.h>
#include "libGraph/Engine.h"
#include "Segment.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"

//Main program
int main(int argc, char **argv)
{

    Engine e(argc, argv);

    std::vector<Segment *> segments;
    GraphicEngineBase * ge = new MyGraphicEngine(&segments);
    GameEngineBase * gme = new MyGameEngine(&segments);

    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.start();

    return 0;
}

