/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "material.h"

// function for the reflections
vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}

// to pick a random point in a unit radius sphere centered at the origin
vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0*vec3(random_double(), random_double(), random_double()) - vec3(1,1,1);
    } while (p.squared_length() >= 1.0);
    return p;
}

//produce a scattered ray (or say it absorbed the incident ray)
//if scattered, say how much the ray should be attenuated
bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
    vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = ray(rec.p, target-rec.p);
    attenuation = albedo;
    return true;
}

//to minimize the amount of fuzziness in the metals
metal :: metal(const vec3& a, float f) : albedo(a) {
    if (f < 1) fuzz = f; else fuzz = 1;
}

//produce a scattered ray (or say it absorbed the incident ray)
//if scattered, say how much the ray should be attenuated
bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}