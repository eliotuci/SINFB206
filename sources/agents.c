#include "../headers/agents.h"

void init_agents_position_and_colour( void ){
  for( int a = 0; a < NUM_AGENTS_TYPE_1; a++){
    agent_type_1[a].x_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN );
    agent_type_1[a].y_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN );
    agent_type_1[a].colors[0] = TYPE_1_RED;
    agent_type_1[a].colors[1] = TYPE_1_GREEN;
    agent_type_1[a].colors[2] = TYPE_1_BLUE;
    agent_type_1[a].shape     = SHAPE_OF_AGENTS_TYPE_1;
    
  }
  for( int a = 0; a < NUM_AGENTS_TYPE_2; a++){
    agent_type_2[a].x_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN );
    agent_type_2[a].y_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN );
    agent_type_2[a].colors[0] = TYPE_2_RED;
    agent_type_2[a].colors[1] = TYPE_2_GREEN;
    agent_type_2[a].colors[2] = TYPE_2_BLUE;
    agent_type_2[a].shape     = SHAPE_OF_AGENTS_TYPE_2;
  }
}

extern void update_agents_positions ( void ){
  init_agents_position_and_colour( );
}
