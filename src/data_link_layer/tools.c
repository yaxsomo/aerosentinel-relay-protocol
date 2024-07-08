#include <stdlib.h>
#include "tools.h"

// Function to generate a random float within a specified range
float generate_random_float(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}
