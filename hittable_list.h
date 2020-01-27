#ifndef HITTABLELISTH
#define HITTABLELISTH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "hittable.h"
// class to put the hittables in a list.
class hittable_list: public hittable {
    public:
        hittable_list() {}
        hittable_list(hittable **l, int n);
        virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;

        hittable **list;
        int list_size;
};

#endif