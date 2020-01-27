#ifndef SPHEREH
#define SPHEREH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "hittable.h"

//header fill for the sphere class
class sphere: public hittable  {
    public:
        sphere() {}
        sphere(vec3 cen, float r, material *m) : center(cen), radius(r), mat_ptr(m)  {};
        virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
        vec3 center;
        float radius;
        material *mat_ptr;
};

#endif