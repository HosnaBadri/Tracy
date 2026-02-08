#include <iostream>

int image_height = 256;
int image_width = 256;

int main(){
    std::cout<<"P3\n";
    std::cout<<image_height<<" "<<image_width<<"\n";
    std::cout<<255<<"\n";

    for(int y = 0; y < image_height; y++){
        std::clog<<"\rScanlines remaining: "<< (image_height - y)<<" "<< std::flush;
        for(int x = 0; x < image_width; x++){

            auto r = double(y) / image_height;
            auto g = double(x) / image_width;

            int ri = 255 *r;
            int gi = 0;
            int bi = 255 *g;

            std::cout<<ri<<" "<<gi<<" "<<bi<<"\n";

        }
    }
    std::clog << "\rDone.                  \n";

}