#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  srand(time(NULL));  
  screen s;
  color c;
  int r1 = rand();
  c.red = 0;
  c.green = r1%10;
  c.blue = 0;
  clear_screen(s);
  for(int i=0;i<250; i++){
    for(int x=0;x<250; x++){
      c.green = i+r1%10;
      c.blue = i+r1%10;
      draw_line(x,i,500,500,s,c);
    }
  }
  display(s);
  save_extension(s, "lines.png");
  printf("Complete");
}
