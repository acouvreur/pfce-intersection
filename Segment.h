//
// Created by alexisc on 31/10/18.
//

#ifndef PFCE_INTERSECTION_SEGMENT_H
#define PFCE_INTERSECTION_SEGMENT_H


class Segment {

private:

    double x;
    double y;
    double l; // largeur (de chaque côté)
    double speed;
    double direction;
public:
    double getR() const;

    void setR(double R);

    double getG() const;

    void setG(double G);

    double getB() const;

    void setB(double B);

public:
    double getDirection() const;

    void setDirection(double direction);

private:
    // Radian
    double angle; // Radian
    double rotation_speed;
    double R, G, B;

public:
    Segment(double x, double y, double l, double speed, double direction, double angle, double rotation_speed, double R, double G, double B)
        : x(x), y(y), l(l), speed(speed), direction(direction), angle(angle), rotation_speed(rotation_speed), R(R), G(G), B(B) {}


    double getX() const {
        return x;
    }

    double getY() const {
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

    void setX(double x);

    void setY(double y);

    void setL(double l);

    void setSpeed(double speed);

    void setAngle(double angle);

    void setRotation_speed(double rotation_speed);

    void draw();

    void tick();

};


#endif //PFCE_INTERSECTION_SEGMENT_H
