/** file: test-ball.cpp
 ** brief: Tests the bouncing ball simulation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

void run(Simulation & s, double dt) {
 for (int i = 0; i < 100; ++i) {
   s.step(dt);
   s.display();
 }
}

int main(int argc, char** argv)
{
  Ball ball ;
  const double dt = 1.0/30 ;
  run(ball, dt);
  return 0 ;
}
