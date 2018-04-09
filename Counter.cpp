#include "Arduino.h"
#include "Counter.h"

Counter::Counter(int val, int speed, bool up)
{
  _val = val;
  if(speed < 1)
    _speed = 1;
  else
    _speed = speed;
  _up = up;
  _frames = 1;
  _upLim = 255;
  _downLim = 0;
}

Counter::Counter(int val, int speed, bool up, int down, int upLim)
{
  _val = val;
  if(speed < 1)
    _speed = 1;
  else
    _speed = speed;
  _up = up;
  _frames = 1;
  _upLim = upLim;
  _downLim = down;
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

    if(_val >= _upLim) _val = _upLim;
    if(_val <= _downLim) _val = _downLim;

    //switch between up and down
    if (_val >= _upLim)
      _up = false;
    if (_val <= _downLim)
      _up = true;
  }
  if(_frames > 999999)
      _frames = 1;
}

int Counter::getVal()
{
  return _val;
}
