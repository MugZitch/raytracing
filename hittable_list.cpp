/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "hittable_list.h"

//putting the hittables in a list
hittable_list :: hittable_list(hittable **l, int n) {list = l; list_size = n; }
//check if there is anything to hit
bool hittable_list::hit(const ray& r, float t_min, float t_max,hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for (int i = 0; i < list_size; i++) {
        if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}
