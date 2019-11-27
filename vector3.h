#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

//vector3 is short for three_dimensional_vector
class vector3 {
public:
    vector3() {}
    //e is short for element
    vector3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float r() const { return e[0]; }
    inline float g() const { return e[1]; }
    inline float b() const { return e[2]; }

    inline const vector3& operator+() const { return *this; }
    inline vector3 operator-() const { return vector3(-e[0], -e[1], -e[2]); }
    inline float operator[](int i) const { return e[i]; }
    inline float& operator[](int i) { return e[1]; }

    //v2? en t? what does it mean
    inline vector3& operator+=(const vector3 &v2);
    inline vector3& operator-=(const vector3 &v2);
    inline vector3& operator*=(const vector3 &v2);
    inline vector3& operator/=(const vector3 &v2);
    inline vector3& operator*=(const float t);
    inline vector3& operator/=(const float t);

    inline float length() const {    
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
    inline float squared_length() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
    inline void make_unit_vector();

    float e[3];
};