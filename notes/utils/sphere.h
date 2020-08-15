#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 c, double r) : center(c), radius(r) {};

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;
    public:
        point3 center;
        double radius;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    auto A = r.origin();
    vec3 oc = (A - center);
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0*dot(r.direction(), oc);
    auto c = dot(oc, oc) - (radius*radius);
    double delta = b*b - 4*a*c;
    if(delta < 0.0) {
        return false;    
    }

    auto t = (-b - sqrt(delta))/(2*a);
    if(t < t_max && t > t_min) {
        rec.t = t;
        rec.p = r.at(t);
        rec.normal = (rec.p - center) / radius;
        return true;
    }
    return false; 
}

#endif