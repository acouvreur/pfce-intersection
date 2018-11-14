//
// Created by alexisc on 07/11/18.
//
#pragma once

#include <cmath>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>
#include "libGraph/Engine.h"
#include "Segment.h"

class MyGameEngine:public GameEngineBase {
    std::vector<Segment * > *segments;
    double epsilon;
    int* collisions;
public:

    explicit MyGameEngine(std::vector<Segment * > * segments_, int* collisions) :segments(segments_), epsilon(0.0001), collisions(collisions){
        const int N = 1000;


        std::thread t1([&] {
            double L = 1.5 / sqrt(N);

            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> r1(-1.0, 1.0);
            std::uniform_real_distribution<double> r2((-1.0 + (L / 4)), (1.0 - (L / 4)));
            std::uniform_real_distribution<double> r3(0.5, 2.0);
            std::uniform_real_distribution<double> r4(0.0, 2*M_PI);


            using namespace std::chrono_literals;

            for(int p = 0; p < 10; p++) {
                // std::cout << "From " << std::pow(2., p) << " to " << std::pow(2., p + 1) << std::endl;

                for (int i = static_cast<int>(std::pow(2., p)); i < std::pow(2., p + 1); ++i) {

                    double x = r2(mt);
                    double y = r2(mt);
                    double a = r1(mt);
                    double R = r1(mt);
                    double G = r1(mt);
                    double B = r1(mt);
                    double rotation_speed = r3(mt);
                    double direction = r4(mt);

                    auto * s = new Segment(x, y, L, 0.01, direction, a, rotation_speed, R, G, B);

                    segments->push_back(s);

                    std::this_thread::sleep_for(50ms);
                }
            }
            // pthread_exit(nullptr);
        });

        t1.detach();
    }

    void idle() override;
    bool ccw(double ax, double ay, double bx, double by, double cx, double cy);
    bool intersect(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy, double epsilon);
};