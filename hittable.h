#ifndef HITTABLEH
#define HITTABLEH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "ray.cpp"

class material;

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
    material *mat_ptr;
};

class hittable {
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif