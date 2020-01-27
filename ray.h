#ifndef RAYH
#define RAYH
#include "vec3.cpp"

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