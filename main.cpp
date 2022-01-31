#include<iostream>
#include<cstring>
#include<cmath>

int main() {

    const int width = 120;
    const int height = 30;
    float aspect = (float)width / height;
    float pixelaspect = 11.0f / 24.0f;
    char* screen = new char[width * height + 1];
    screen[width * height] = '\n';
    char gradient[] = ".,-~:;=!*#$@";
    int gradientSize = std::size(gradient) - 2;

    int rb = 10;
    int r = 4;

    float x, y, z;

    const double PI = 3.141592653589793238463;

    float z0 = 10;

    for (float q = 0; q < 1000; q+=0.01) {
        for (int i = 0; i < width * height; i++) {
            screen[i] = ' ';
        }
        for (float f = 0; f < 2 * PI; f += 0.1) {
            for (float t = 0; t < 2 * PI; t += 0.1) {

                int x, y, z;
                float a = q;
                float b = q;
                x = (rb + r * cos(t)) * (cos(b) * cos(f) + sin(a) * sin(b) * sin(f)) - r * cos(a) * sin(b) * sin(t);
                y = (rb + r * cos(t)) * (cos(f) * sin(b) - cos(b) * sin(a) * sin(f)) + r * cos(a) * cos(b) * sin(t);
                z = cos(a) * (rb + r * cos(t)) * sin(f) + r * sin(a) * sin(t);
                x = (x + 30) * pixelaspect * aspect;
                y = y + 15;
                int dist = z;
                if (dist > gradientSize) { dist = gradientSize - 1; }
                if (dist < 0) { dist = 0; }
                screen[x + y * width] = gradient[dist];
                

            }
        }
        printf(screen);
    }
    delete[] screen;
    getchar();

	
	return 0;
}
