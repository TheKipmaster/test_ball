/** file: ball.h
 ** brief: Ball class
 ** author: Andrea Vedaldi
 **/

#ifndef __ball__
#define __ball__

#include "simulation.h"
#include <tuple>

class Ball : public Simulation
{
public:
  // Constructors and member functions
  Ball() ;
  Ball(double X, double Y) ;
  void step(double dt) ;
  void display() ;
  void setPosition(double x, double y) ;
  std::tuple<double, double> getPosition() ;

protected:
  // Data members
  // Position and velocity of the ball
  double x ;
  double y ;
  double vx ;
  double vy ;

  // Mass and size of the ball
  double m ;
  double r ;

  // Gravity acceleration
  double g ;

  // Geometry of the box containing the ball
  double xmin ;
  double xmax ;
  double ymin ;
  double ymax ;
} ;

#endif /* defined(__ball__) */
