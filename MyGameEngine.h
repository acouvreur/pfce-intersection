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
        const int N = 10000;
        double L = 1.5 / sqrt(N);

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(-1.0, 1.0);

        for (int i = 0; i < N; ++i) {

            double x = dist(mt);
            double y = dist(mt);
            double a = dist(mt);
            double R = dist(mt);
            double G = dist(mt);
            double B = dist(mt);

            segments->push_back(new Segment(x, y, 0.2, 0.5, a, 0.2, R, G, B));
        }
    }

    virtual void idle();
};