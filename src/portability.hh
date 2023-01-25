#ifndef PORTABILITY_HH
#define PORTABILITY_HH

#include <qs_config.h>

#ifdef CSTDINT_MISSING
#include <stdint.h>
#else
#include <cstdint>
#endif

#endif
