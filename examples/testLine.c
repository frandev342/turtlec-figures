#include "../turtlec.h"
#include <math.h>

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;

  turtleForward(turtle, length);

  turtleLeft(turtle, 30);
  fractalTree(turtle, length * 0.8, depth - 1);

  turtleRight(turtle, 60);
  fractalTree(turtle, length * 0.8, depth - 1);

  turtleLeft(turtle, 30);

  if (depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else
    turtleSetColor(turtle, 0, 200, 0);

  turtleBackward(turtle, length);

  //  if (depth > 5)
  //    turtleSetColor(turtle, 120, 70, 20);
  //  else
  //    turtleSetColor(turtle, 0, 200, 0);
}

void levy(Turtle *turtle, float length, int depth) {
  if (depth == 0) {
    turtleForward(turtle, length);
    return;
  }
  turtleLeft(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleRight(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}

int main(void) {
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if (app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  // Moviendo a la tortuga a un lugar adecuado para comenzar a dibujar
  turtlePenUp(t);
  turtleLeft(t, 90);
  turtleBackward(t, 50);
  turtleRight(t, 90);
  turtlePenDown(t);

  turtleSetSpeed(t, 0.5);

  //  fractalTree(t, 20, 7);

  for (int i = 0; i < 10; i++) {
    levy(t, 100, i);
    turtleClear(t);
    turtleHome(t);
  }
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
