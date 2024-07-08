// physical_layer/signal.h

#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <stdint.h>

// Function prototypes
void physical_init(void);
void physical_send(uint8_t *data, uint8_t length);
void physical_receive(uint8_t *buffer, uint8_t *length);

#endif // PHYSICAL_H
