#include "../headers/graphics.h"
#include "../headers/agents.h"

void renderBitmapString(float x, float y, void *font,const char *string){
  const char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void set_color3f(  float *colors ){
  glColor3f(colors[0], colors[1], colors[2]);
}

void draw_circle_agents( GLfloat min_coordinate, GLfloat max_coordinate, GLfloat size,
 			 int x_pos, int y_pos, float *colors, int id ){
  int numSegments = 100;
  GLfloat angle;
  glBegin(GL_TRIANGLE_FAN );
  set_color3f( colors );
  for(int i = 0; i <= numSegments; i++){
    angle = 2.0f * PI * (float)(i) / (double)(numSegments);
    glVertex2f(min_coordinate + (size*x_pos + size/2) + cosf(angle) * (size/2),
	       min_coordinate + (size*y_pos+size/2) + sinf(angle) * (size/2));
  }
  glEnd();
#ifdef _PRINT_AGENTS_ID_
  char sa[5];
  sprintf(sa, "%d", id);
  glColor3f(0.0f, 0.0f, 0.0f);
  renderBitmapString(min_coordinate + (size*x_pos + size/2),
		     min_coordinate + (size*y_pos + size/2), (void*)GLUT_BITMAP_TIMES_ROMAN_24, sa);
#endif
}

void draw_square_agents( GLfloat min_coordinate, GLfloat max_coordinate, GLfloat size,
			 int x_pos, int y_pos, float *colors ){
  GLfloat offset = 0.005;
  glBegin(GL_QUADS);
  set_color3f(  colors );
  glVertex2f( min_coordinate+(x_pos*size)+offset,     max_coordinate-((y_pos+1)*size)+offset);
  glVertex2f( min_coordinate+((x_pos+1)*size)-offset, max_coordinate-((y_pos+1)*size)+offset);
  glVertex2f( min_coordinate+((x_pos+1)*size)-offset, max_coordinate-(y_pos*size)-offset);
  glVertex2f( min_coordinate+(x_pos*size)+offset,     max_coordinate-(y_pos*size)-offset);
  glEnd();
}

void renderScene(void) {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  GLfloat offset = 0.5;
  GLfloat size = (2.0f-offset)/(float)(NUM_CELLS_PER_COLUMN);
  GLfloat min_coordinate = -1.0f + (offset*0.5);
  GLfloat max_coordinate = 1.0f - (offset*0.5);

  //This is to draw the grid, which extend
  // from point (min_coordinate, min_coordinate) bottom left, to point (max_coordinate, max_coordinate) top right
  char letter;
  for(int i = 0, letter = 'a'; i < NUM_CELLS_PER_COLUMN+1; i++, ++letter){//This is a square grid
    GLfloat target_point = min_coordinate + (i*size);
    glBegin( GL_LINES );
    glColor3f(LINES_RED, LINES_GREEN, LINES_BLUE);//This is to define the colour of the grid lines
    glVertex2f(min_coordinate, target_point); //X, and Y coordinate of the horizontal line start
    glVertex2f(max_coordinate, target_point );//X, and Y coordinate of the horizontal line end    
    glVertex2f(target_point, min_coordinate); //X, and Y coordinate of the vertical line start
    glVertex2f(target_point, max_coordinate); //X, and Y coordinate of the vertical line end
    glEnd();
    if( i < NUM_CELLS_PER_COLUMN ){
      char sa[5];
      sprintf(sa, "%d", i+1);
      renderBitmapString(max_coordinate+0.02, target_point+(size*0.5), (void*)GLUT_BITMAP_9_BY_15, &sa);
      renderBitmapString(target_point+(size*0.5), max_coordinate+0.02, (void*)GLUT_BITMAP_9_BY_15, &letter );
    }
  }

  for( int a =0; a < NUM_AGENTS_TYPE_1; a++){
    if( agent_type_1[a].shape == SQUARE ){
      draw_square_agents( min_coordinate, max_coordinate, size,
			  agent_type_1[a].x_pos, agent_type_1[a].y_pos, &agent_type_1[a].colors );
    }
    else{
      draw_circle_agents( min_coordinate, max_coordinate, size,
			  agent_type_1[a].x_pos, agent_type_1[a].y_pos, &agent_type_1[a].colors, a );
    }
  }
  for( int a =0; a < NUM_AGENTS_TYPE_2; a++){
    if( agent_type_2[a].shape == SQUARE ){
      draw_square_agents( min_coordinate, max_coordinate, size,
			  agent_type_2[a].x_pos, agent_type_2[a].y_pos, &agent_type_2[a].colors );
    }
    else{
      draw_circle_agents( min_coordinate, max_coordinate, size,
			  agent_type_2[a].x_pos, agent_type_2[a].y_pos, &agent_type_2[a].colors, a );
    }
  }
    
  glutSwapBuffers();
  glFlush();
}

void reshape ( GLsizei width, GLsizei height ){
  if( height == 0 ) height = 1;
  GLfloat ratio = (GLfloat)(width)/(GLfloat)(height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, width, height);    
  if( width >= height ){
    gluOrtho2D(-1.0*ratio, 1.0*ratio, -1.0, 1.0);
  }else{
    gluOrtho2D(-1.0, 1.0, -1.0/ratio, 1.0/ratio );
  }
}

void process_normal_keys( unsigned char key, int x, int y ){
  if( key == 'x') // exit animation
    exit(0);
  else if( key == 'p') //pause animation
    isAnimating = false;
  else if (key == 's') //restart animation
    isAnimating=true;
  
}

void animate ( int value ){
  glutTimerFunc(TIME_IN_MILLISECOND, animate, 0);
  if( isAnimating ){
    //Ask to players to enter their move
    //int user_input;
    //printf("\n Please enter a number in [0-10] : \n");
    //scanf("%d", &user_input);
    update_agents_positions ( );
  }
  glutPostRedisplay();
}


void initGL( int argc, char **argv) { 
  glutInit(&argc, argv);  // init GLUT and create window
  glutInitWindowPosition(X_WINDOW_POS, Y_WINDOW_POS);//Position the windows on the screen
  glutInitWindowSize(X_WINDOW_SIZE, Y_WINDOW_SIZE);//Resize the graphic window
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("SINFB2016 project - 2019/2020");
  glClearColor(B_RED, B_GREEN, B_BLUE, 1.0);//set the background color
  isAnimating = true;
}
