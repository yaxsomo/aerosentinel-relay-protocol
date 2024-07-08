// common/tools.h

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Telemetry data structure for sensor data
typedef struct {
    float imu_accel_x;
    float imu_accel_y;
    float imu_accel_z;

    float imu_gyro_x;
    float imu_gyro_y;
    float imu_gyro_z;

    float imu_mag_x;
    float imu_mag_y;
    float imu_mag_z;

    float ahrs_accel_x;
    float ahrs_accel_y;
    float ahrs_accel_z;

    float ahrs_gyro_x;
    float ahrs_gyro_y;
    float ahrs_gyro_z;

    float ahrs_mag_x;
    float ahrs_mag_y;
    float ahrs_mag_z;

    float automotive_imu_accel_x;
    float automotive_imu_accel_y;
    float automotive_imu_accel_z;

    float automotive_imu_gyro_x;
    float automotive_imu_gyro_y;
    float automotive_imu_gyro_z;

    float magnetometer_x;
    float magnetometer_y;
    float magnetometer_z;

    float pressure_sensor;
    float temperature_sensor;
    float humidity_sensor;

    float barometric_pressure;

    float gps_latitude;
    float gps_longitude;
} telemetry_data;

// Calculate SENSOR_DATA_COUNT based on the number of fields in telemetry_data
#define SENSOR_DATA_COUNT (sizeof(telemetry_data) / sizeof(float))
#define ENCODED_BUFFER_SIZE (SENSOR_DATA_COUNT * sizeof(float) + SENSOR_DATA_COUNT) // COBS overhead


// Telemetry data structure for encoded data
typedef struct {
    unsigned char encoded_buffer[ENCODED_BUFFER_SIZE];
} encoded_telemetry_data;


#endif // data_structures.h
