#include "../headers/general.h"

/* -------------------------------------------------------------------------- */
gsl_rng *r_rand;
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
void init_generator( const int root_seed ){
  const gsl_rng_type *T;
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r_rand = gsl_rng_alloc (T);
  gsl_rng_set (r_rand, root_seed );
}
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
void free_generator( void ){
  gsl_rng_free ( r_rand );
}
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
void usage ( void )
{
  printf(" Bad input format - Options are required \n option -s required followed by a seed number different from zero \n");
  exit(0);
}
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
void parse_command_line( int argc, char** argv )
{
  if( argc == 3 ){
    //char option[2] = {'-','s'};
    char option[] = "-s";
    if( !strcmp(argv[1], option ) ){
      m_rootSeed = atoi( argv[2] );
      if( m_rootSeed == 0 ) usage();
    }
    else usage();
  }
  else{
    usage();
  }
}
/* -------------------------------------------------------------------------- */
