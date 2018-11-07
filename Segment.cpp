//
// Created by alexisc on 31/10/18.
//

#include "Segment.h"

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
