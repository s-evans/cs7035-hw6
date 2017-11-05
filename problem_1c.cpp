//
// FILENAME: problem_1c.cpp
//

#include <cstdlib>
#include <iostream>
#include <utility>

// Find the order of P (the smallest integer n such that nP = O) on the elliptic curve y^2 = x^3 + 256, defined over the field of rational numbers Q.

/**
 * @brief Finds next point, 2P, on elliptic curve
 *
 * @param P given point, P
 * @param a slope of the line
 *
 * @return 2P
 */
std::pair<int, int> next_point( std::pair<int, int> const& P, int a )
{
    int const x1 = P.first;
    int const y1 = P.second;

    int const alpha = ( 3 * x1 * x1 + a ) / ( 2 * y1 );
    int const x3 = alpha * alpha - 2 * x1;
    int const y3 = -y1 + alpha * ( x1 - x3 );

    return std::make_pair( x3, y3 );
}

/**
 * @brief Print the given point
 *
 * @param os output stream object
 * @param v point object
 *
 * @return output stream
 */
std::ostream& operator<<( std::ostream& os, std::pair<int, int> const& v )
{
    return os << "(" << v.first << "," << v.second << ")";
}

int main()
{
    int const x1 = 0;
    int const y1 = 16;
    int const a = 0;

    auto const P1 = std::make_pair( x1, y1 );

    std::cout << "1P = " << P1 << std::endl;

    auto P = P1;

    for ( int i = 1 ; i < 2 ; ++i ) {
        P = next_point( P, a );
        std::cout << i * 2 << "P = " << P << std::endl;
    }

    return EXIT_FAILURE;
}
