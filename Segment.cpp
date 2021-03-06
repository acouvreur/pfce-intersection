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

void Segment::draw() {

    double x1 = x + cos(angle) * (l/2);
    double y1 = y + sin(angle) * (l/2);

    double x2 = x - cos(angle) * (l/2);
    double y2 = y - sin(angle) * (l/2);

    // std::cout << "{" << x1 << ", " << y1 << "} {" << x2 << ", " << y2 << "}" << std::endl;

    GraphicPrimitives::drawLine2D(static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2),
                                  static_cast<float>(y2), R, G, B);
}

void Segment::tick() {

    double x1,x2,y1,y2;
    angle += (rotation_speed/60 * M_PI);
    x = x + speed * cos(direction);
    y = y + speed * sin(direction);
    x1 = x + cos(angle) * (l/2);y1 = y + sin(angle) * (l/2);x2 = x - cos(angle) * (l/2);y2 = y - sin(angle) * (l/2);

    if(x1>1.0){
        x = 1.0 - cos(angle) * (l/2);
        direction+=M_PI_2;
    } else if(x2>1.0){
        x = 1.0 + cos(angle) * (l/2);
        direction+=M_PI_2;
    }if(y1>1.0){
        y = 1.0 - sin(angle) * (l/2);
        direction+=M_PI_2;
    } else if(y2>1.0){
        y = 1.0 + sin(angle) * (l/2);
        direction+=M_PI_2;
    }if(x1<-1.0){
        x = -1.0 - cos(angle) * (l/2);
        direction+=M_PI_2;
    } else if(x2<-1.0){
        x = -1.0 + cos(angle) * (l/2);
        direction+=M_PI_2;
    }if(y1<-1.0){
        y = -1.0 - sin(angle) * (l/2);
        direction+=M_PI_2;
    } else if(y2<-1.0){
        y = -1.0 + sin(angle) * (l/2);
        direction+=M_PI_2;
    }

    // TODO:
    // 1. Collisions avec les autres segments (au niveau du game engine car il connaît tous les segments!) donc rebond

}

double Segment::getDirection() const {
    return direction;
}

void Segment::setDirection(double direction) {
    Segment::direction = direction;
}

double Segment::getR() const {
    return R;
}

void Segment::setR(double R) {
    Segment::R = R;
}

double Segment::getG() const {
    return G;
}

void Segment::setG(double G) {
    Segment::G = G;
}

double Segment::getB() const {
    return B;
}

void Segment::setB(double B) {
    Segment::B = B;
}


