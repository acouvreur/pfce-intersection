#include <iostream>

#include <GL/glut.h>
#include "libGraph/Engine.h"
#include "Segment.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"

//Main program
int main(int argc, char **argv)
{

    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glEnable(GL_MULTISAMPLE);
    Engine e(argc, argv);

    std::vector<Segment *> segments;
    GraphicEngineBase * ge = new MyGraphicEngine(&segments);
    GameEngineBase * gme = new MyGameEngine(&segments);

    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.start();

    return 0;
}

