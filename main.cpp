#include <iostream>

#include <GL/glut.h>
#include <fstream>
#include "libGraph/Engine.h"
#include "Segment.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"

//Main program
int main(int argc, char **argv)
{

    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    //glEnable(GL_MULTISAMPLE);
    Engine e(argc, argv);

    int collisions = 0;
    std::vector<Segment *> segments;
    segments.reserve(2000);
    GraphicEngineBase * ge = new MyGraphicEngine(&segments, &collisions);
    GameEngineBase * gme = new MyGameEngine(&segments, &collisions);

    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.start();

    return 0;
}

