#include "data_link_layer/tools.h"
#include "application_layer/data_structures.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){

    telemetry_data telem;
    printf("Size of telemetry structure : %zu\n", (sizeof(telem) / sizeof(float)));
    return 0;
}