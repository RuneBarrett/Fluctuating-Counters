#include "Arduino.h"
#include "Counter.h"

Counter::Counter(int val, int speed, bool up)
{
  _val = val;
  _speed = speed;
  _up = up;
  _frames = 1;
}

Counter::Counter(){
  _val = 0;
  _speed = 5;
  _up = true;
  _frames = 1;
}

void Counter::setUp(int v, int s){
  _val = v;
  _speed = s;
}

void Counter::count()
{
  _frames++;
  // increment
  if(_frames % 500 == 0)
  {
    if(_up)
      _val+=_speed;
    else
      _val-=_speed;
  }
  if(_val > 254) _val = 255;
  if(_val < 1) _val = 0;
  //switch between up and down
  if (_val > 254)
    _up = false;
  if (_val < 1)
    _up = true;
  if(_frames > 9999999)
      _frames = 1;
}

int Counter::getVal()
{
  return _val;
}
