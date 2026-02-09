#include <iostream>

#include "vec3.h"
#include "color.h"

int image_height = 256;
int image_width = 256;

int main(){
    std::cout<<"P3\n";
    std::cout<<image_height<<" "<<image_width<<"\n";
    std::cout<<255<<"\n";

    for(int y = 0; y < image_height; y++){
        std::clog<<"\rScanlines remaining: "<< (image_height - y)<<" "<< std::flush;
        for(int x = 0; x < image_width; x++){

            color pixel = {double(y) / image_height, double(x) / image_width, 0.0};
            write_color(std::cout, pixel);
        }
    }
    std::clog << "\rDone.                  \n";

}