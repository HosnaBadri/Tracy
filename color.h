//
// Created by Hosna on 2/8/2026.
//

#ifndef TRACY_COLOR_H
#define TRACY_COLOR_H

#include "vec3.h"

using color = vec3;

void write_color( std::ostream& out, const color& c ) {

    int ri = int(255 *c.x());
    int gi = int(255 *c.y());
    int bi = int(255 *c.z());

    out<<ri<<" "<<gi<<" "<<bi<<"\n";

}

#endif //TRACY_COLOR_H