//
// FILENAME: problem_1a.cpp
//

#include <cstdlib>
#include <iostream>

// Verify that the point P(0, 16) is on the elliptic curve y^2 = x^3 + 256, defined over the field of rational numbers Q.

int main()
{
    auto const x = 0;
    auto const y = 16;

    if (y*y != x*x*x + 256) {
        std::cout << "P(0,16) is NOT on the curve y^2 = x^3 + 256" << std::endl;
        std::cout << y*y << " != " << x*x*x << " + 256" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "P(0,16) is on the curve y^2 = x^3 + 256" << std::endl;
    std::cout << y*y << " = " << x*x*x << " + 256" << std::endl;

    return EXIT_SUCCESS;
}
