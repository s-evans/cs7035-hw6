//
// FILENAME: problem_1b.cpp
//

#include <cstdlib>
#include <iostream>
#include <utility>

// Find the points 2P and 3P on the elliptic curve y^2 = x^3 + 256, defined over the field of rational numbers Q given P(0, 16).

// alpha = ( 3 * x[1] ^ 2 + a ) / ( 2 * y[1] )
// x[3] = alpha^2 − 2 * x[1]
// y[3] = -y[1] + alpha * ( x[1] - x[3] )

std::pair<int, int> next_point( std::pair<int, int> const& point, int a )
{
    int const x1 = point.first;
    int const y1 = point.second;

    int const alpha = ( 3 * x1 * x1 + a ) / ( 2 * y1 );
    int const x3 = alpha * alpha - 2 * x1;
    int const y3 = -y1 + alpha * ( x1 - x3 );

    return std::make_pair( x3, y3 );
}

std::pair<int, int> next_point( std::pair<int,int> const& point_one, std::pair<int,int> const& point_two )
{
    int const x1 = point_one.first;
    int const y1 = point_one.second;

    int const x2 = point_two.first;
    int const y2 = point_two.second;

    int const alpha = ( y2 - y1 ) / ( x2 - x1 );

    int const x3 = alpha * alpha - x1 - x2;
    int const y3 = -y1 + alpha * ( x1 - x3 );

    return std::make_pair( x3, y3 );
}

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
