
#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __linux__ //On Linux OS
#include <GL/glut.h>
#include <GL/glu.h>
#elif __APPLE__ //On MAC OSX
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#endif

enum SHAPES {SQUARE, ROUND};

#define X_WINDOW_SIZE 600
#define Y_WINDOW_SIZE 600
#define X_WINDOW_POS  200
#define Y_WINDOW_POS  100
#define NUM_CELLS_PER_COLUMN  20
#define TIME_IN_MILLISECOND   500

#define NUM_AGENTS_TYPE_1 10
#define SHAPE_OF_AGENTS_TYPE_1 ROUND //SQUARE 
#define TYPE_1_RED      1.0f //[0.0, 1.0]
#define TYPE_1_GREEN    0.0f //[0.0, 1.0]
#define TYPE_1_BLUE     0.0f //[0.0, 1.0]

#define NUM_AGENTS_TYPE_2 10
#define SHAPE_OF_AGENTS_TYPE_2 ROUND //SQUARE
#define TYPE_2_RED      1.0f //[0.0, 1.0]
#define TYPE_2_GREEN    0.0f //[0.0, 1.0]
#define TYPE_2_BLUE     1.0f //[0.0, 1.0]

//#define _PRINT_AGENTS_ID_
 
#define B_RED           1.0f /* a float in [0.0, 1.0] */
#define B_GREEN         1.0f /* a float in [0.0, 1.0] */
#define B_BLUE          1.0f /* a float in [0.0, 1.0] */

#define LINES_RED       0.0f /* a float in [0.0, 1.0] */
#define LINES_GREEN     1.0f /* a float in [0.0, 1.0] */
#define LINES_BLUE      0.0f /* a float in [0.0, 1.0] */


#define PI 3.14159265f

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

extern gsl_rng *r_rand;
void init_generator     ( const int root_seed );
void free_generator     ( void );
void parse_command_line ( int argc, char** argv );

long int m_rootSeed;
bool isAnimating;

#endif
