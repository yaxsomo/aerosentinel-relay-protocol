#include "data_link_layer/tools.h"
#include "application_layer/data_structures.h"
#include "data_link_layer/cobs.h"  // Assuming you have a COBS implementation
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to generate sensor data
void generate_sensor_data(telemetry_data *telemetry) {
    // Generate random sensor data
    telemetry->imu_accel_x = generate_random_float(-10.0, 10.0);
    telemetry->imu_accel_y = generate_random_float(-10.0, 10.0);
    telemetry->imu_accel_z = generate_random_float(-10.0, 10.0);

    telemetry->imu_gyro_x = generate_random_float(-5.0, 5.0);
    telemetry->imu_gyro_y = generate_random_float(-5.0, 5.0);
    telemetry->imu_gyro_z = generate_random_float(-5.0, 5.0);

    telemetry->imu_mag_x = generate_random_float(-50.0, 50.0);
    telemetry->imu_mag_y = generate_random_float(-50.0, 50.0);
    telemetry->imu_mag_z = generate_random_float(-50.0, 50.0);

    telemetry->ahrs_accel_x = generate_random_float(-10.0, 10.0);
    telemetry->ahrs_accel_y = generate_random_float(-10.0, 10.0);
    telemetry->ahrs_accel_z = generate_random_float(-10.0, 10.0);

    telemetry->ahrs_gyro_x = generate_random_float(-5.0, 5.0);
    telemetry->ahrs_gyro_y = generate_random_float(-5.0, 5.0);
    telemetry->ahrs_gyro_z = generate_random_float(-5.0, 5.0);

    telemetry->ahrs_mag_x = generate_random_float(-50.0, 50.0);
    telemetry->ahrs_mag_y = generate_random_float(-50.0, 50.0);
    telemetry->ahrs_mag_z = generate_random_float(-50.0, 50.0);

    telemetry->automotive_imu_accel_x = generate_random_float(-10.0, 10.0);
    telemetry->automotive_imu_accel_y = generate_random_float(-10.0, 10.0);
    telemetry->automotive_imu_accel_z = generate_random_float(-10.0, 10.0);

    telemetry->automotive_imu_gyro_x = generate_random_float(-5.0, 5.0);
    telemetry->automotive_imu_gyro_y = generate_random_float(-5.0, 5.0);
    telemetry->automotive_imu_gyro_z = generate_random_float(-5.0, 5.0);

    telemetry->magnetometer_x = generate_random_float(-100.0, 100.0);
    telemetry->magnetometer_y = generate_random_float(-100.0, 100.0);
    telemetry->magnetometer_z = generate_random_float(-100.0, 100.0);

    telemetry->pressure_sensor = generate_random_float(800.0, 1200.0);
    telemetry->temperature_sensor = generate_random_float(15.0, 35.0);
    telemetry->humidity_sensor = generate_random_float(20.0, 80.0);

    telemetry->barometric_pressure = generate_random_float(800.0, 1200.0);

    telemetry->gps_latitude = generate_random_float(-90.0, 90.0);
    telemetry->gps_longitude = generate_random_float(-180.0, 180.0);
}

void encode_sensor_data(const telemetry_data *telemetry, encoded_telemetry_data *encoded_data) {
    // Calculate the size of telemetry_data in bytes
    size_t data_size = sizeof(telemetry_data);

    // COBS encode the telemetry_data structure
    size_t encoded_size = cobs_encode((const uint8_t *)telemetry, data_size, encoded_data->encoded_buffer);

    if (encoded_size == 0) {
        // Handle error (this is just an example, handle errors appropriately in your application)
        printf("COBS encoding error\n");
    }
}

void decode_sensor_data(const encoded_telemetry_data *encoded_data, telemetry_data *decoded_data) {
    // COBS decode the data into decoded_telemetry_data structure
    size_t decoded_size = cobs_decode(encoded_data->encoded_buffer, ENCODED_BUFFER_SIZE, (uint8_t *)decoded_data);

    if (decoded_size == 0) {
        // Handle error (this is just an example, handle errors appropriately in your application)
        printf("COBS decoding error\n");
    }
}

int telemetry_exemple() {
    srand(time(NULL));

    telemetry_data telemetry;  // Structure to hold all sensor data

    // Generate dummy sensor data
    generate_sensor_data(&telemetry);

    // Example: Print generated sensor data
    printf("Generated Sensor Data:\n");
    printf("IMU Acceleration: (%.2f, %.2f, %.2f)\n", telemetry.imu_accel_x, telemetry.imu_accel_y, telemetry.imu_accel_z);
    printf("IMU Gyroscope: (%.2f, %.2f, %.2f)\n", telemetry.imu_gyro_x, telemetry.imu_gyro_y, telemetry.imu_gyro_z);
    printf("IMU Magnetometer: (%.2f, %.2f, %.2f)\n", telemetry.imu_mag_x, telemetry.imu_mag_y, telemetry.imu_mag_z);
    printf("AHRS Acceleration: (%.2f, %.2f, %.2f)\n", telemetry.ahrs_accel_x, telemetry.ahrs_accel_y, telemetry.ahrs_accel_z);
    printf("AHRS Gyroscope: (%.2f, %.2f, %.2f)\n", telemetry.ahrs_gyro_x, telemetry.ahrs_gyro_y, telemetry.ahrs_gyro_z);
    printf("AHRS Magnetometer: (%.2f, %.2f, %.2f)\n", telemetry.ahrs_mag_x, telemetry.ahrs_mag_y, telemetry.ahrs_mag_z);
    printf("Automotive IMU Acceleration: (%.2f, %.2f, %.2f)\n", telemetry.automotive_imu_accel_x, telemetry.automotive_imu_accel_y, telemetry.automotive_imu_accel_z);
    printf("Automotive IMU Gyroscope: (%.2f, %.2f, %.2f)\n", telemetry.automotive_imu_gyro_x, telemetry.automotive_imu_gyro_y, telemetry.automotive_imu_gyro_z);
    printf("Magnetometer: (%.2f, %.2f, %.2f)\n", telemetry.magnetometer_x, telemetry.magnetometer_y, telemetry.magnetometer_z);
    printf("Pressure Sensor: %.2f hPa\n", telemetry.pressure_sensor);
    printf("Temperature Sensor: %.2f Celsius\n", telemetry.temperature_sensor);
    printf("Humidity Sensor: %.2f %%\n", telemetry.humidity_sensor);
    printf("Barometric Pressure: %.2f hPa\n", telemetry.barometric_pressure);
    printf("GPS Coordinates: (%.2f, %.2f)\n", telemetry.gps_latitude, telemetry.gps_longitude);

    encoded_telemetry_data encoded_data;  // Structure to hold encoded sensor data

    // Encode sensor data
    encode_sensor_data(&telemetry, &encoded_data);

    // Simulate sending data (in real application, use send_data function)
    printf("Simulating sending data:\n");
    for (int i = 0; i < ENCODED_BUFFER_SIZE; ++i) {
        printf("%02X ", encoded_data.encoded_buffer[i]);
    }
    printf("\n");

    // Simulate receiving data (in real application, use receive_data function)
    printf("Simulating receiving data:\n");
    // Copy encoded data to simulate receiving
    encoded_telemetry_data received_data;
    for (int i = 0; i < ENCODED_BUFFER_SIZE; ++i) {
        received_data.encoded_buffer[i] = encoded_data.encoded_buffer[i];
        printf("%02X ", received_data.encoded_buffer[i]);
    }
    printf("\n");

    telemetry_data decoded_data;  // Structure to hold decoded sensor data

    // Decode received data
    decode_sensor_data(&received_data, &decoded_data);

    // Print decoded sensor data
    printf("Decoded sensor data:\n");
    printf("IMU Acceleration: (%.2f, %.2f, %.2f)\n", decoded_data.imu_accel_x, decoded_data.imu_accel_y, decoded_data.imu_accel_z);
    printf("IMU Gyroscope: (%.2f, %.2f, %.2f)\n", decoded_data.imu_gyro_x, decoded_data.imu_gyro_y, decoded_data.imu_gyro_z);
    printf("IMU Magnetometer: (%.2f, %.2f, %.2f)\n", decoded_data.imu_mag_x, decoded_data.imu_mag_y, decoded_data.imu_mag_z);
    printf("AHRS Acceleration: (%.2f, %.2f, %.2f)\n", decoded_data.ahrs_accel_x, decoded_data.ahrs_accel_y, decoded_data.ahrs_accel_z);
    printf("AHRS Gyroscope: (%.2f, %.2f, %.2f)\n", decoded_data.ahrs_gyro_x, decoded_data.ahrs_gyro_y, decoded_data.ahrs_gyro_z);
    printf("AHRS Magnetometer: (%.2f, %.2f, %.2f)\n", decoded_data.ahrs_mag_x, decoded_data.ahrs_mag_y, decoded_data.ahrs_mag_z);
    printf("Automotive IMU Acceleration: (%.2f, %.2f, %.2f)\n", decoded_data.automotive_imu_accel_x, decoded_data.automotive_imu_accel_y, decoded_data.automotive_imu_accel_z);
    printf("Automotive IMU Gyroscope: (%.2f, %.2f, %.2f)\n", decoded_data.automotive_imu_gyro_x, decoded_data.automotive_imu_gyro_y, decoded_data.automotive_imu_gyro_z);
    printf("Magnetometer: (%.2f, %.2f, %.2f)\n", decoded_data.magnetometer_x, decoded_data.magnetometer_y, decoded_data.magnetometer_z);
    printf("Pressure Sensor: %.2f hPa\n", decoded_data.pressure_sensor);
    printf("Temperature Sensor: %.2f Celsius\n", decoded_data.temperature_sensor);
    printf("Humidity Sensor: %.2f %%\n", decoded_data.humidity_sensor);
    printf("Barometric Pressure: %.2f hPa\n", decoded_data.barometric_pressure);
    printf("GPS Coordinates: (%.2f, %.2f)\n", decoded_data.gps_latitude, decoded_data.gps_longitude);

    return 0;
}

