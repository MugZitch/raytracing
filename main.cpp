/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include "hittable_list.cpp"
#include "sphere.cpp"
#include "camera.cpp"
#include "material.cpp"
#include "random.h"
#include <float.h>
#include <fstream>
#include <iostream>

//function for the color
vec3 color(const ray& r, hittable *world, int depth) {
    hit_record rec;
    if (world->hit(r, 0.001, FLT_MAX, rec)) {
        ray scattered;
        vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation*color(scattered, world, depth+1);
        }
        else {
            return vec3(0,0,0);
        }
    }
    else {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5*(unit_direction.y() + 1.0);
        return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
    }
}

// The scene for the picture is created
hittable *random_scene() {
    int n = 500;
    hittable **list = new hittable*[n+1];
    list[0] = new sphere(vec3(0,-1000,0), 1000, new lambertian(vec3(0.5, 0.5, 0.5)));
    int i = 1;
    for (int a = -6; a < 9; a++) {
        for (int b = -11; b < 5; b++) {
            float choose_mat = random_double();
            vec3 center(a+0.9*random_double(),0.2,b+0.9*random_double());
            if ((center-vec3(4,0.2,0)).length() > 0.9) {
                if (choose_mat < 0.8) { // diffuse
                    list[i++] = new sphere(center, 0.2, 
                        new lambertian(vec3(random_double()*random_double(),
                                            random_double()*random_double(),
                                            random_double()*random_double()))
                    );
                }
                else if (choose_mat < 0.95) { // metal
                    list[i++] = new sphere(center, 0.2,
                            new metal(vec3(0.5*(1 + random_double()),
                                           0.5*(1 + random_double()),
                                           0.5*(1 + random_double())),
                                      0.5*random_double()));
                }
            } 
        }
    }

    list[i++] = new sphere(vec3(-4, 1, 0), 1.0, new lambertian(vec3(0.4, 0.2, 0.1)));
    list[i++] = new sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));

    return new hittable_list(list,i);
}

// The ppm file / picture is created
int main() {
    std::ofstream outfile;
    outfile.open("image.ppm");
    int nx = 800;
    int ny = 450;
    int ns = 100;

    outfile << "P3\n" << nx << " " << ny << "\n255\n";

    hittable *world = random_scene();

    vec3 lookfrom(10,2,-6);
    vec3 lookat(0,0,0);
    float dist_to_focus = 10;
    float aperture = 0.1;

    camera cam(lookfrom, lookat, vec3(0,1,0), 20, float(nx)/float(ny), aperture, dist_to_focus);

    for (int j = ny-1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s++) {
                float u = float(i + random_double()) / float(nx);
                float v = float(j + random_double()) / float(ny);
                ray r = cam.get_ray(u, v);
                col += color(r, world, 0);
            }
            col /= float(ns);
            col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            outfile << ir << " " << ig << " " << ib << "\n";
        }
    }
    outfile.close();
    return 0;
}