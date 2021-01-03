#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<double>cr;
vector<int> x;
vector<int> y;
vector<double> m_re;
vector<double> m_im;
vector<int> itr;
int main() {
    fstream mandelbrot;
    mandelbrot.open("mandelbrot.ppm", ios::out);
    for (int i = 0; i != 1000; i++) {
        itr.push_back(i);
    }
    for (double elm = -2; elm <= 1.25; elm += 0.002) {
        cr.push_back(elm);
    }
    mandelbrot << "P3" << endl;
    mandelbrot << cr.size() << " " << cr.size() << endl;
    mandelbrot << "256" << endl;
    for (int i = 0; i != cr.size(); i++) {
        x.push_back(i);
        y.push_back(i);
    }
    for (auto re : x) {
        for (auto im : y) {
            bool conv = true;
            double c_re = cr[re];
            double c_im = cr[im];
            double z_re = 0;
            double z_im = 0;
            for (auto j : itr) {
                double z_re2 = z_re;
                z_re = (z_re * z_re - z_im * z_im + c_re);
                z_im = 2 * z_re2 * z_im + c_im;
                if ((z_re * z_re) + (z_im * z_im) > 4) {
                    conv = false;
                    mandelbrot << (j/1000)*255 << " " << (j / 1000) * 255 << " " << (j / 1000) * 255 << endl;
                    break;
                }
            };
            if (conv == true) {
                mandelbrot << 255 << " " << 255 << " " << 255 << endl;
            }
        }
    }
    return 0;
}