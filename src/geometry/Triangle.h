#pragma once

#include <geometry/Convex.h>

class Triangle : public Convex
{
public:

    // TODO: template for float or double?
    Triangle(vec2f point1, vec2f point2, vec2f point3)
    {
    }

    ~Triangle() {}

    //
    // Convex implementation
    //

    vec2f getCenter()
    {
        return vec2f();
    }
};