/// \file betaspline.h
/// \brief Beta spline kernel function
#ifndef BETASPLINE_H
#define BETASPLINE_H
#include "kernel.h"

/// Beta spline kernel 
class BetaSpline : public Kernel
{

public:
    ///constructor to initialize the data members and
    BetaSpline(double smoothingLength);

    ///Calculates the kernel value for the given distance of two particles. 
    virtual double w(double distance) const;

    ///Calculates the kernel derivation for the given distance of two particles. 
    virtual Vec2d gradW(double distance, const Vec2d& distanceVector) const;
        
    ///Calculates the kernel derivation to distance. 
    double F(double distance) const;

private:
    ///Normalization factor
    double norm;

    ///Auxiliary factors for intermediate results: The inverse smoothing length */
    double reciprocH;

    ///Auxiliary factors for intermediate results: A pre-factor for w */
    double factorW;

    ///Auxiliary factors for intermediate results: A pre-factor for grad w */
    double factorGradW;

};

#endif
