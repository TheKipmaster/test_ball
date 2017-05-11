/** file: test-srpingmass.cpp
 ** brief: Tests the spring mass simulation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

int main(int argc, char** argv)
{
  SpringMass springmass ;

  const double mass = 0.05 ;
  const double radius = 0.02 ;
  const double naturalLength = 0.95 ;
  const double damping = 0.01;
  const double stiffness = 0.5;

  Mass m1(Vector2(-0.5,-0.5), Vector2(), mass, radius) ;
  Mass m2(Vector2(+0.5,0), Vector2(), mass, radius) ;
/* COMPLETE: TYPE YOUR CODE HERE */
  springmass.newMass(m1);
  springmass.newMass(m2);
  springmass.newSpring(naturalLength, damping, stiffness, 0, 1);

  const double dt = 1.0/30 ;
  for (int i = 0 ; i < 200 ; ++i) {
    springmass.step(dt) ;
    springmass.display() ;
  }

  return 0 ;
}
