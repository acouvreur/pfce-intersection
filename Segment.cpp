//
// Created by alexisc on 31/10/18.
//

#include <cmath>
#include "Segment.h"
#include "libGraph/GraphicPrimitives.h"

void Segment::setX(double x) {
    Segment::x = x;
}

void Segment::setY(double y) {
    Segment::y = y;
}

void Segment::setL(double l) {
    Segment::l = l;
}

void Segment::setSpeed(double speed) {
    Segment::speed = speed;
}

void Segment::setAngle(double angle) {
    Segment::angle = angle;
}

void Segment::setRotation_speed(double rotation_speed) {
    Segment::rotation_speed = rotation_speed;
}

bool Segment::intersect(const Segment *s) {
    return false;
}

void Segment::draw() {

    double x1 = x + cos(angle) * (l/2);
    double y1 = y + sin(angle) * (l/2);

    double x2 = x - cos(angle) * (l/2);
    double y2 = y - sin(angle) * (l/2);

    /*
    x2 = (x2 * cos(a)) - (y2 * sin(a));
    y2 = (x2 * sin(a)) + (y2 * cos(a));
    */

    std::cout << "{" << x1 << ", " << y1 << "} {" << x2 << ", " << y2 << "}" << std::endl;

    GraphicPrimitives::drawLine2D(static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2),
                                  static_cast<float>(y2), R, G, B);
}

void Segment::tick() {

    angle += (rotation_speed/60 * M_PI);
    x = x + speed * cos(direction);
    y = y + speed * sin(direction);

    // TODO:
    // 1. Collisions avec le bord donc rebond
    // 2. Collisions avec les autres segments (au niveau du game engine car il connaît tous les segments!) donc rebond

}


