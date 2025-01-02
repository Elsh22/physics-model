#ifndef TEST_PARTICLE_H
#define TEST_PARTICLE_H

#include "core.h"

namespace test
{
    class Particle
    {

    private:
        /* data */

    public:
        /* */
        Vector3 position;


        Vector3 velocity;

        Vector3 acceleration;

        real damping;
        
        real inverseMass;

        void integrate(real duration);
        


    };

    
} // namespace test

#endif