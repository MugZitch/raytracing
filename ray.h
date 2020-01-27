#ifndef RAYH
#define RAYH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "vec3.cpp"

//header file for the ray class
class ray
{
    public:
    ray() {}
    ray(const vec3& a, const vec3& b);
    vec3 origin() const;
    vec3 direction() const;
    vec3 point_at_parameter(float t) const;

    vec3 A;
    vec3 B;
};

#endif