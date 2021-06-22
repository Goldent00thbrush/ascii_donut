#ifndef DONUT_H
#define DONUT_H
#include <string>

class donut
{
public:
    donut();
    std::string iterate();

private:
    int R2, K2, screen_width, screen_height, sz; //constants
    float A, B, phi, theta, phi_spacing, theta_spacing;
    char * out;
    float * depths;
};

#endif // DONUT_H
