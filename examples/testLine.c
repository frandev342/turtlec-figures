#include "../turtlec.h"

void fractalTree ( Turtle * turtle , float length , int depth) {
	if( depth == 0 || length < 5)
		return ;
	turtleForward ( turtle , length ) ;

	turtleLeft ( turtle , 30) ;
	fractalTree ( turtle , length * 0.8 , depth - 1) ;

	turtleRight ( turtle , 60) ;
	fractalTree ( turtle , length * 0.8 , depth - 1) ;

	turtleLeft ( turtle , 30) ;
	turtleBackward ( turtle , length ) ;
}

void levy ( Turtle * turtle , float length , int depth ) {
	if( depth == 0) {
		turtleForward ( turtle , length ) ;
		return ;
	}
	turtleLeft ( turtle , 45) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;

	turtleRight ( turtle , 90) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;
	
	turtleLeft ( turtle , 45) ;
}

int main(void){
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  turtleForward(t, 300.0f);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
