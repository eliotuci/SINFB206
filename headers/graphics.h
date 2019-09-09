#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "general.h"

void renderBitmapString(float x, float y, void *font,const char *string);
void set_color3f(  float *colors );

void draw_square_agents( GLfloat min_coordinate, GLfloat max_coordinate, GLfloat size, int x_pos, int y_pos, float *colors );
void draw_circle_agents( GLfloat min_coordinate, GLfloat max_coordinate, GLfloat size, int x_pos, int y_pos, float *colors, int id );

void renderScene(void);
void reshape ( GLsizei width, GLsizei height );
void process_normal_keys( unsigned char key, int x, int y );
void animate ( int value );
void initGL( int argc, char **argv);

#endif
