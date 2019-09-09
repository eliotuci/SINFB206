#include "../headers/general.h"
#include "../headers/agents.h"
#include <../headers/graphics.h>

int main(int argc, char **argv) {

  parse_command_line( argc, argv );//call command line parser
  
  free_generator( );//Init the GSL libary
  init_generator( m_rootSeed ); //Seed the GSL random number the generator 

  init_agents_position_and_colour( );
    
  initGL( argc, argv); //Init the graphic window

  glutDisplayFunc(renderScene); // register callbacks
  glutReshapeFunc( reshape );
  //glutIdleFunc( renderScene );

  glutKeyboardFunc(process_normal_keys);
  glutPostRedisplay();
  glutTimerFunc(TIME_IN_MILLISECOND, animate, 0); 
  glutMainLoop();   // enter GLUT event processing cycle
      
  return 1;
}

