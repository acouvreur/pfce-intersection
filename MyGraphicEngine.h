//
// Created by alexisc on 07/11/18.
//
#pragma once
#include "libGraph/Engine.h"
#include "libGraph/GraphicPrimitives.h"
#include "Segment.h"

class MyGraphicEngine:public GraphicEngineBase {

    std::vector<Segment * > *segments;
    int frame=0,time,timebase=0;
    double fps=0;
    int* collisions;

public:

    MyGraphicEngine(std::vector<Segment * > * segments_, int* collisions) :
            segments(segments_),
            x1(0.5f),
            x2(-0.5f),
            vx1(0.01f),
            vx2(-0.02f),
            collisions(collisions)
    {}

    float x1,x2,vx1,vx2;

    void Draw() override;

};
