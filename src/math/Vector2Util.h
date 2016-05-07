#pragma once

#include <glm/vec2.hpp>
#include <glm/geometric.hpp>

using glm::dvec2;
using glm::dot;

class Vector2Util
{
public:

    static double cross(const dvec2& p1, const dvec2& p2)
    {
        return p1.x * p2.y - p1.y * p2.x;
    }

    //!
    //! Computes:
    //! b * (a . c) - a * (b . c)
    //!
    static dvec2 tripleProduct(const dvec2& a, const dvec2& b, const dvec2& c)
    {
        return (b * dot(a, c)) - (a * dot(b, c));
    }

    //!
    //! Magnitude squared:
    //! v.x * v.x + v.y * v.y
    //!
    static double magnitudeSquared(const dvec2& a)
    {
        return a.x * a.x + a.y * a.y;
    }

    //! Returns the left-handed normal of this vector.
    static dvec2 left(const dvec2& v)
    {
        return dvec2(v.y, -v.x);
    }

    //! Returns the right-handed normal of this vector.
    dvec2 right(const dvec2& v)
    {
        return dvec2(-v.y, v.x);
    }
};