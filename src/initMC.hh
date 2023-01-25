#ifndef INIT_MC_HH
#define INIT_MC_HH

#include <qs_config.h>

class Parameters;
class MonteCarlo;

MonteCarlo* initMC(const Parameters& params);

#endif
