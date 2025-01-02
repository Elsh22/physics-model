#include <assert.h>
#include <phys/particle.h>

using namespace test;

void Particle::integrate(real duration)
{
    assert(duration > 0);

    postion.addScaledvector(velocity, duration);

    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    velocity.addScaledVector(resultingAcc, duration);

    velocity *= real_pow(damping, duration);
}