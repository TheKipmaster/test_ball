/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

Mass::Mass()
: position(), velocity(), force(), mass(1), radius(1)
{ }

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
: position(position), velocity(velocity), force(), mass(mass), radius(radius),
xmin(-1),xmax(1),ymin(-1),ymax(1)
{ }

void Mass::setForce(Vector2 f)
{
  force = f ;
}

void Mass::addForce(Vector2 f)
{
  force = force + f ;
}

Vector2 Mass::getForce() const
{
  return force ;
}

Vector2 Mass::getPosition() const
{
  return position ;
}

Vector2 Mass::getVelocity() const
{
  return velocity ;
}

double Mass::getRadius() const
{
  return radius ;
}

double Mass::getMass() const
{
  return mass ;
}

double Mass::getEnergy(double gravity) const
{
  double totalE=0, kineticE, potentialE;

  /* COMPLETE: TYPE YOUR CODE HERE */
  kineticE = ((mass * velocity.norm2())/2);
  potentialE = mass*gravity*(position.y-getRadius());
  totalE = potentialE + kineticE;

  return totalE ;
}

void Mass::step(double dt)
{
/* INCOMPLETE: TYPE YOUR CODE HERE */
  double xp, yp, xv, yv;
  Vector2 a;

  a = force/mass;
  if (xmin + radius <= xp && xp <= xmax - radius) {
    xp = position.x + velocity.x*dt + (a.x*dt*dt)/2;
  } else {
    velocity.x = -velocity.x;
  }
  if (ymin + radius <= yp && yp <= ymax - radius) {
    yp = position.y + velocity.y*dt + (a.y*dt*dt)/2;
  } else {
    velocity.y = -velocity.y;
  }

}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2),
naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{ }

Mass * Spring::getMass1() const
{
  return mass1 ;
}

Mass * Spring::getMass2() const
{
  return mass2 ;
}

Vector2 Spring::getForce() const
{
  Vector2 F, distance, unit;
/* COMPLETE: TYPE YOUR CODE HERE */
  double currentLength, stretchV;

  distance = mass1->getPosition() - mass2->getPosition();
  currentLength = distance.norm();
  unit = distance/currentLength;
  stretchV = dot( unit, (mass1->getVelocity()-mass2->getVelocity()) );
  F = ((naturalLength - currentLength)*stiffness + stretchV) * damping * unit;

  return F ;
}

double Spring::getLength() const
{
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  return u.norm() ;
}

double Spring::getEnergy() const {
  double length = getLength() ;
  double dl = length - naturalLength;
  return 0.5 * stiffness * dl * dl ;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
  os<<"("
  <<m.getPosition().x<<","
  <<m.getPosition().y<<")" ;
  return os ;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
  return os<<"$"<<s.getLength() ;
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

SpringMass::SpringMass(double gravity)
: gravity(gravity)
{ }

void SpringMass::display() {
/* COMPLETE: TYPE YOUR CODE HERE */
  unsigned int i;

  for(i = 0; i < masses.size(); i++) {
    std::cout << masses.at(i) << std::endl;
  }
  for(i = 0; i < springs.size(); i++ ) {
    std::cout << springs.at(i) << std::endl;
  }
  std::cout << getEnergy() << std::endl;
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;
/* COMPLETE: TYPE YOUR CODE HERE */
  unsigned int i;

  for(i = 0; i < masses.size(); i++) {
    energy += masses.at(i).getEnergy(gravity);
  }
  for(i = 0; i <springs.size(); i++) {
    energy += springs.at(i).getEnergy();
  }

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ;
/* COMPLETE: TYPE YOUR CODE HERE */
  unsigned int i;

  for(i = 0; i < masses.size(); i++) {
    masses.at(i).setForce(g * masses.at(i).getMass());
  }

  for(i = 0; i < springs.size(); i++) {
    springs.at(i).getMass1()->addForce(-1 * springs.at(i).getForce());
    springs.at(i).getMass2()->addForce(+1 * springs.at(i).getForce());
  }

  for(i = 0; i < masses.size(); i++) {
    masses.at(i).step(dt);
  }
}

/* COMPLETE: TYPE YOUR CODE HERE */
int SpringMass::newMass(Mass mass) {
  masses.push_back(mass);
  return masses.size();
}

void SpringMass::newSpring(double naturalLength, double damping, double stiffness, int mass1ref, int mass2ref) {
  Spring spring(&masses.at(mass1ref), &masses.at(mass2ref), naturalLength, stiffness, damping);
  springs.push_back(spring);
}
