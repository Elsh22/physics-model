#include <math.h>
#ifndef TEST_CORE_H
#define TEST_CORE_H

#include "precison.h"
namespace test
{
    class Vector3
    {
    private:
        /* data */
        real pad;//textboox says this is for preforms becuase of memory coming in sets for 4
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

        real magnitude() const
        {
            return real_sqrt((x*x)+(y*y)+(z*z));// you could use pow but i have a feeling that might be slower by calling a function to do that. 
        }
        real squaremagnitude() const
        {
            return (x*x)+(y*y)+(z*z);
        }
        void normalize()
        {
            real l = magnitude();
            if (l > 0){
                (*this)*=((real)1)/l ;
            }
        }
        // multplies this vector
        void operator*=(const real value)
         {
            x *= value;// we can use this is make them negtaive 
            y *= value;
            z *= value;
         }
        Vector3 operator*(const real value) const
         {
            return Vector3(x*value, y*value, z*value);
         }

         //adding vector 
        void operator+=(const Vector3& v)
         {
            x += v.x;// we can use this is make them negtaive 
            y += v.y;
            z += v.z;
         }
        Vector3 operator+(const Vector3& v) const
         {
            return Vector3(x+v.x, y+v.y, z+v.z);
         }
        void operator-=(const Vector3& v)
         {
            x -= v.x;// we can use this is make them negtaive 
            y -= v.y;
            z -= v.z;
         }
        Vector3 operator-(const Vector3& v) const
         {
            return Vector3(x-v.x, y-v.y, z-v.z);
         }

        void addScaledVector(const Vector3& vector, real scale)
        {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }

        // component product that muplty a vector and another vector together in a specail way
        Vector3 componentProduct(const Vector3 &vector) const
        {
            return Vector3(x * vector.x, y * vector.y, z * vector.z);
        }

        /**
         * Performs a component-wise product with the given vector and
         * sets this vector to its result.
         */
        void componentProductUpdate(const Vector3 &vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;
        }

        //real componentProduct(const Vector3 &vector) const
        //{
        //    return (x*vector.x + y*vector.y + z*vector.z);
        //}

        real operator *(const Vector3 &vector) const
        {
            return x*vector.x + y*vector.y + z*vector.z;
        }

        /**
         * Calculates and returns the vector product of this vector
         * with the given vector.
         */
        Vector3 vectorProduct(const Vector3 &vector) const
        {
            return Vector3(y*vector.z-z*vector.y,
                           z*vector.x-x*vector.z,
                           x*vector.y-y*vector.x);
        }

        /**
         * Updates this vector to be the vector product of its current
         * value and the given vector.
         */
        void operator %=(const Vector3 &vector)
        {
            *this = vectorProduct(vector);
        }

        /**
         * Calculates and returns the vector product of this vector
         * with the given vector.
         */
        Vector3 operator%(const Vector3 &vector) const
        {
            return Vector3(y*vector.z-z*vector.y,
                           z*vector.x-x*vector.z,
                           x*vector.y-y*vector.x);
        }
    
    };//class vector 3 
}// namespace test

#endif