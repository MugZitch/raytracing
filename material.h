#ifndef MATERIALH
#define MATERIALH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "hittable.h"
#include "random.h"

//header file for the material classes
struct hit_record;

class material {
    public:
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};

class lambertian : public material {
    public:
        lambertian(const vec3& a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

        vec3 albedo;
};

class metal : public material {
    public:
        metal(const vec3& a, float f);
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
        vec3 albedo;
        float fuzz;
};

#endif