#include <iostream>
#include <cmath>
#include <iomanip>

void main(int argc, char *argv[]){
    long double fovscale = atof(argv[1]);
    const long double M_PI = 3.1415926535897932384626433832795;
    long double v0 = fovscale * 70;
    long double i0 = 1;
    long double g0[8] = { 1, 0.95625, 0.95625, 0.95, 0.95, 0.95, 0.95, 1}; //0.9 + ((0.1 * 0.75) * 0.75) = 0.95625
    std::cout << std::fixed << std::setprecision(19) << "VxT = 4x3 fov " << v0 << std::endl;
    if(argc > 2){
        i0 = atof(argv[2]);
        std::cout << "offset " << i0 << std::endl;
    }

    long double hfft = tan((M_PI / 180) * (v0 / 2));

    long double v[9];
    v[0] = (60 * fovscale);
    v[1] = (38.59068547 * fovscale);
    v[2] = (26.27556256 * fovscale);
    v[3] = (19.85825982 * fovscale);
    v[4] = (13.31276054 * fovscale);
    v[5] = (10.00423937 * fovscale);
    v[6] = (8.010712494 * fovscale);

    std::cout << std::endl;

    for (int i = 0; i < 7; i++) {
        v[7] = (tan((M_PI / 180) * (v[i] / 2)) / hfft);
        
        v[8] = v[i] / std::round(v0);
        std::cout << "mouse_zoomed_sensitivity_scalar_" << i << " " << (v[8] / v[7]) * i0 * g0[i] << std::endl;
    }

    return;
}