#include "../turtlec.h"
#include <math.h>

void fractalTree(Turtle *turtle, float length, int depth) {
  if (depth == 0 || length < 5)
    return;

  turtleForward(turtle, length);

  // Dibujar tres ramas
  turtleLeft(turtle, 30); // GIrar 30° a la izquierda y dibujar rama
  fractalTree(turtle, length * 0.6, depth - 1);

  turtleRight(turtle,
              30); // Regresar al centro girando 30° a la derecha y dibujar rama
  fractalTree(turtle, length * 0.8, depth - 1);

  turtleRight(turtle, 30); // Girar 30° a la derecha y dibujar rama
  fractalTree(turtle, length * 0.6, depth - 1);

  turtleLeft(turtle, 30);

  int r = (253 * depth) % 256;
  int g = (156 * depth) % 256;
  int b = (43 * depth) % 256;
  turtleSetColor(turtle, r, g, b);

  turtleBackward(turtle, length);
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

  int r = (253 * depth) % 256;
  int g = (156 * depth) % 256;
  int b = (43 * depth) % 256;
  turtleSetColor(turtle, r, g, b);
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

  //  fractalTree(t, 20, 6);

  //  turtleSetSpeed(t, 0.5);

  //  fractalTree(t, 20, 7);
  levy(t, 100, 7);

  //  for (int i = 0; i < 10; i++) {
  //    levy(t, 100, i);
  //    turtleClear(t);
  //    turtleHome(t);
  //  }
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
