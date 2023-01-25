#ifndef POPULATION_CONTROL_HH
#define POPULATION_CONTROL_HH

#include <qs_config.h>

class MonteCarlo;

void PopulationControl(MonteCarlo* monteCarlo, bool loadBalance);

void RouletteLowWeightParticles(MonteCarlo* monteCarlo);

#endif

