#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x, y, a, b, d;
  if (x1 < x0){
    x = x1;
    x1 = x0;
    x0 = x;

    y = y1;
    y1 = y0;
    y0 = y;
  }
  else {
    x = x0;
    y = y0;
  }

  a = 2*(y1 - y0);
  b = 2*(x0 - x1);

  if (a >= 0 && a <= -b){
    d = 2*a + b;
    while (x <= x1){
      plot(s, c, x, y);
      if (d > 0){
        y++;
        d += b;
      }
      x++;
      d += a;
    }
  }

 
  else if ((-b == 0 && y1 > y0) || abs(a) > abs(b)){
    d = a - 2*b;
    while (y >= y1){
      plot(s, c, x, y);
      if (d > 0){
        x++;
        d += a;
      }
      y--;
      d -= b;
    }
  }
  else if ((-b == 0 && y1 > y0) || (a > -b)){
    d = a + 2*b;
    while (y <= y1){
      plot(s, c, x, y);
      if (d < 0){
        x++;
        d += a;
      }
      y++;
      d += b;
    }
  }
  else {
    d = 2*a - b;
    while (x <= x1){
      plot(s, c, x, y);
      if (d < 0){
        y--;
        d -= b;
      }
      x++;
      d += a;
    }
  }
}
