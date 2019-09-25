#include "../headers/agents.h"


void avoid_overlapping_agents_on_starting_state() {
    for (int a = 0; a < NUM_AGENTS_TYPE_1; a++) {
        for (int aa = 0; aa < NUM_AGENTS_TYPE_1; aa++) {
            if (a == aa) continue;
            if (agent_type_1[a].x_pos == agent_type_1[aa].x_pos && agent_type_1[a].y_pos == agent_type_1[aa].y_pos) {
                agent_type_1[a].x_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN);
                agent_type_1[a].y_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN);
                aa -= 1;
            }
        }
    }
    for (int a = 0; a < NUM_AGENTS_TYPE_2; a++) {
        for (int aa = 0; aa < NUM_AGENTS_TYPE_2; aa++) {
            if (a == aa) continue;
            if (agent_type_1[a].x_pos == agent_type_1[aa].x_pos && agent_type_1[a].y_pos == agent_type_1[aa].y_pos) {
                agent_type_1[a].x_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN);
                agent_type_1[a].y_pos = gsl_rng_uniform_int(r_rand, NUM_CELLS_PER_COLUMN);
                aa -= 1;
            }
        }
    }
}

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
  avoid_overlapping_agents_on_starting_state()
}

extern void update_agents_positions ( void ){
  init_agents_position_and_colour( );
}
