#include <math.h>
#ifndef TEST_CORE_H
#define TEST_CORE_H

#include "precision.h"
namespace test
{
    class Vector3
    {
    private:
        /* data */
        real pad;//
    public:
        real x;
        real y;
        real z;
        // so im going to assgin float value to values in the x, y,z
        /*
        Vector3::Vector3( agr )
            {
            }
            
            Vector3::~Vector3(){ }

        */
    public:
        /** The default constructor creates a zero vector. */
        Vector3() : x(0), y(0), z(0) {}

        /**
         * The explicit constructor creates a vector with the given
         * components.
         */
        Vector3(const real x, const real y, const real z)
            : x(x), y(y), z(z) {}

        void invert(){
            x = -x;
            y = -y;
            x = -z;
        }
         
    
    } //class vector 3 
}// namespace test