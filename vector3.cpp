#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class vector3 {
public:
    vector3() {}
        //e equals element
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

        
}