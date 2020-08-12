#include <iostream>

#define MAX_PIXEL 255.999

using namespace std;

int main() {

    // Image size
    const int image_width = 256;
    const int image_height = 256;

    // Render
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int i = 0; i < image_width; ++i) 
    {
        for(int j = 0; j < image_height; ++j) 
        {
            cerr << "\rScanlines in proccess: " << j << ' ' << flush;
            auto r = ((double)i/(image_height-1)), g = ((double)j/(image_width-1)), b = 0.25;
            cout << static_cast<int>(MAX_PIXEL * r) << ' ' 
                 << static_cast<int>(MAX_PIXEL * g) << ' ' 
                 << static_cast<int>(MAX_PIXEL * b) <<  '\n';
        }
    }

    return 0;
}