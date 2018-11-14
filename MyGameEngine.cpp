//
// Created by alexisc on 07/11/18.
//

#include "MyGameEngine.h"


void MyGameEngine::idle(){

    // 0. Reset color
    for(auto &segment1 : *segments) {
        segment1->setR(.0);
        segment1->setG(1.0);
        segment1->setB(.0);
    }

    auto start = std::chrono::steady_clock::now();

    *collisions = 0;

    // 1. Check for collisions
    for(auto &segment1 : *segments) {
        double ax = segment1->getX() + cos(segment1->getAngle()) * (segment1->getL()/2);
        double ay = segment1->getY() + sin(segment1->getAngle()) * (segment1->getL()/2);

        double bx = segment1->getX() - cos(segment1->getAngle()) * (segment1->getL()/2);
        double by = segment1->getY() - sin(segment1->getAngle()) * (segment1->getL()/2);
        for(auto &segment2 : *segments) {
            if(segment1 == segment2) {
                // std::cout << "Comparing with same instance, continue" << std::endl;
                continue;
            }
            double cx = segment2->getX() + cos(segment2->getAngle()) * (segment2->getL()/2);
            double cy = segment2->getY() + sin(segment2->getAngle()) * (segment2->getL()/2);

            double dx = segment2->getX() - cos(segment2->getAngle()) * (segment2->getL()/2);
            double dy = segment2->getY() - sin(segment2->getAngle()) * (segment2->getL()/2);
            if(intersect(ax, ay, bx, by, cx, cy, dx, dy, epsilon)) {

                (*collisions)++;
                // std::cout << "Collision detected !" << std::endl;
                /*segment1->setDirection(segment1->getDirection() + M_PI_2); // Reverse direction
                segment1->setRotation_speed(-segment1->getRotation_speed()); // Reverse rotation speed
                */
                //segment2->setDirection(segment2->getDirection() + M_PI_2); // Reverse direction
                //segment2->setRotation_speed(-segment2->getRotation_speed()); // Reverse rotation speed

                segment1->setR(1.0);
                segment1->setG(.0);
                segment1->setB(.0);

                segment2->setR(1.0);
                segment2->setG(.0);
                segment2->setB(.0);
            }
        }
    }
    // 2. Tick the move
    for (auto &segment : *segments) {
        segment->tick();
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << segments->size() << ":" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << ":" << *collisions << std::endl;

}

bool MyGameEngine::ccw(double ax, double ay, double bx, double by, double cx, double cy){
    return (cy-ay)*(bx-ax) > (by-ay)*(cx-ax);
}

bool MyGameEngine::intersect(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy, double epsilon) {
    /*double det    = (bx - ax) * (dy * cy) - (by - ay) * (dx - cx);
    double gamma  = ((ay - cy) * (dx - cx)) - ((ax - cx) * (dy - cy));
    double lambda = ((ay - cy) * (bx - ax)) - ((ax - cx)) * ((by - ay));
    if(det == 0.) {
        return gamma == 0 && lambda == 0;
    } else {
        double r = gamma / det;
        double s = lambda / det;
        return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
    }*/
    return ccw(ax,ay,cx,cy,dx,dy) != ccw(bx,by,cx,cy,dx,dy) && ccw(ax,ay,bx,by,cx,cy) != ccw(ax,ay,bx,by,dx,dy);

}