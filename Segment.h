//
// Created by alexisc on 31/10/18.
//

#ifndef PFCE_INTERSECTION_SEGMENT_H
#define PFCE_INTERSECTION_SEGMENT_H


class Segment {

private:

    int x;
    int y;
    double l; // largeur (de chaque côté)
    double speed;
    double angle; // Radian
    double rotation_speed;

public:
    Segment(int x, int y, double l, double speed, double angle, double rotation_speed)
        : x(x), y(y), l(l), speed(speed), angle(angle), rotation_speed(rotation_speed) {}


    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    double getL() const {
        return l;
    }

    double getSpeed() const {
        return speed;
    }

    double getAngle() const {
        return angle;
    }

    double getRotation_speed() const {
        return rotation_speed;
    }

    void setX(int x);

    void setY(int y);

    void setL(double l);

    void setSpeed(double speed);

    void setAngle(double angle);

    void setRotation_speed(double rotation_speed);

};


#endif //PFCE_INTERSECTION_SEGMENT_H
