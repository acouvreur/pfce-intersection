//
// Created by alexisc on 07/11/18.
//
#pragma once

#include "libGraph/Engine.h"
#include "Segment.h"

class MyGameEngine:public GameEngineBase {
    std::vector<Segment * > *segments;
public:

    MyGameEngine(std::vector<Segment * > * segments_) :segments(segments_){}

    virtual void idle();

};