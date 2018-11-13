//
// Created by alexisc on 07/11/18.
//
#pragma once

#include <cmath>
#include <random>
#include "libGraph/Engine.h"
#include "Segment.h"

class MyGameEngine:public GameEngineBase {
    std::vector<Segment * > *segments;
public:

    MyGameEngine(std::vector<Segment * > * segments_) :segments(segments_){
        const int N = 50;
        double L = 1.5 / sqrt(N);

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> r1(-1.0, 1.0);
        std::uniform_real_distribution<double> r2((-1.0 + (L / 4)), (1.0 - (L / 4)));
        std::uniform_real_distribution<double> r3(0.5, 2.0);
        std::uniform_real_distribution<double> r4(0.0, 2*M_PI);


        for (int i = 0; i < N; ++i) {

            double x = r2(mt);
            double y = r2(mt);
            double a = r1(mt);
            double R = r1(mt);
            double G = r1(mt);
            double B = r1(mt);
            double rotation_speed = r3(mt);
            double direction = r4(mt);

            segments->push_back(new Segment(x, y, L, 0.01, direction, a, rotation_speed, R, G, B));
        }
    }

    virtual void idle();
};