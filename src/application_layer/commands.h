// src/common/commands.h

#ifndef COMMANDS_H
#define COMMANDS_H

// Navigation Module Commands
#define NAV_CMD_INIT 200
#define NAV_CMD_START 201
#define NAV_CMD_STOP 202
#define NAV_CMD_SET_DESTINATION 203
#define NAV_CMD_GET_POSITION 204

// Flight Module Commands
#define FLIGHT_CMD_TAKEOFF 300
#define FLIGHT_CMD_LAND 301
#define FLIGHT_CMD_HOVER 302
#define FLIGHT_CMD_SET_ALTITUDE 303
#define FLIGHT_CMD_GET_STATUS 304

// Communication Module Commands
#define COMM_CMD_INIT 400
#define COMM_CMD_SEND_MESSAGE 401
#define COMM_CMD_RECEIVE_MESSAGE 402
#define COMM_CMD_SET_FREQUENCY 403
#define COMM_CMD_GET_SIGNAL_STRENGTH 404

// Ground Station Commands
#define GROUND_CMD_INIT 500
#define GROUND_CMD_LAUNCH 501
#define GROUND_CMD_ABORT 502
#define GROUND_CMD_GET_TELEMETRY 503
#define GROUND_CMD_SEND_ACK 504

// Example of control commands for various actions
#define CMD_FIN_TEST 101
#define CMD_ROCKET_ARM 102
#define CMD_ROCKET_DISARM 103
#define CMD_ROCKET_LAUNCH 104

#endif // COMMANDS_H
