//
// FILENAME: problem_2.cpp
//

#include <cstdlib>
#include <iostream>
#include <utility>
#include <set>

// Find the order of P(½, ½) over Q on the curve y^2 = x^3 + ¼x.

/**
 * @brief Finds next point, 2P, on elliptic curve
 *
 * @param P given point, P
 * @param a slope of the line
 *
 * @return 2P
 */
std::pair<float, float> next_point( std::pair<float, float> const& P, float a )
{
    float const x1 = P.first;
    float const y1 = P.second;

    float const alpha = ( 3 * x1 * x1 + a ) / ( 2 * y1 );
    float const x3 = alpha * alpha - 2 * x1;
    float const y3 = -y1 + alpha * ( x1 - x3 );

    return std::make_pair( x3, y3 );
}

/**
 * @brief Given two points, P and Q, return the point, 2P, on an eliptic curve
 *
 * @param P the point P
 * @param Q the point Q
 *
 * @return 2P
 */
std::pair<float, float> next_point( std::pair<float, float> const& P, std::pair<float, float> const& Q )
{
    float const x1 = P.first;
    float const y1 = P.second;

    float const x2 = Q.first;
    float const y2 = Q.second;

    float const alpha = ( y2 - y1 ) / ( x2 - x1 );

    float const x3 = alpha * alpha - x1 - x2;
    float const y3 = -y1 + alpha * ( x1 - x3 );

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
std::ostream& operator<<( std::ostream& os, std::pair<float, float> const& v )
{
    return os << "(" << v.first << "," << v.second << ")";
}

/**
 * @brief Negate a point
 *
 * @param v input point
 *
 * @return the negated point (x, -y)
 */
std::pair<float, float> operator-( std::pair<float, float> const& v )
{
    return std::make_pair( v.first, -v.second );
}

int main()
{
    float const x1 = 0.5;
    float const y1 = 0.5;
    float const a = 0.25;

    auto const P1 = std::make_pair( x1, y1 );

    std::cout << "1P = " << P1 << std::endl;

    auto const P2 = next_point( P1, a );

    std::cout << "2P = " << P2 << std::endl;

    auto const P4 = next_point( P1, P2 );

    std::cout << "4P = " << P4 << std::endl;

    auto P = P2;
    auto Q = P4;

    std::set<std::pair<float, float>> set{P1, P2, P4};

    for ( int i = 3 ; true ; ++i ) {
        auto const T = next_point( P, Q );
        P = Q;
        Q = T;

        std::cout << "2^" << i << "P = " << T << std::endl;

        if ( set.find( -T ) != set.end() ) {
            std::cout << "found additive inverse" << std::endl;
            return EXIT_SUCCESS;
        }

        set.insert( T );
    }

    return EXIT_FAILURE;
}
