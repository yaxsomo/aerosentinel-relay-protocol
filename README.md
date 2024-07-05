<p align="center">
  <img src="https://github.com/yaxsomo/aerosentinel-relay-protocol/assets/71334330/b1a6072a-204e-46a4-a6a0-3012d6d64d7f" alt="aerosentinel RP logo">
</p>

#

Welcome to the Aerosentinel Relay Protocol firmware repository. This custom communication protocol is developed in C to ensure reliable data transmission within the Aerosentinel ecosystem.

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
3. [Usage](#usage)
    - [Building the Protocol](#building-the-protocol)
5. [Features](#features)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction
The Aerosentinel Relay Protocol is designed to handle communication tasks for the Aerosentinel ecosystem, ensuring reliable and efficient data transmission between various modules and the ground station. This protocol is developed to support seamless integration and robust performance.

## Getting Started

### Prerequisites
Before getting started, make sure you have the following installed:
- GCC compiler
- Make or CMake for build automation

### Installation
1. Clone this repository to your local machine using:
    ```bash
    git clone https://github.com/yaxsomo/aerosentinel-relay-protocol.git
    ```
2. Navigate to the project directory:
    ```bash
    cd aerosentinel-relay-protocol
    ```
3. You're all set!

## Usage

### Building the Protocol
To build the protocol, follow these steps:

1. Ensure all dependencies are installed.
2. Navigate to the project directory.
3. Use the provided Makefile to build the project:
    ```bash
    make
    ```
4. To clean the build artifacts, use:
    ```bash
    make clean
    ```

## Features
- **Reliable Data Transmission**: Ensures robust communication between modules and the ground station.
- **Low Latency**: Designed for fast and efficient data exchange.
- **Error Checking and Correction**: Implements mechanisms to ensure data integrity during transmission.
- **Scalability**: Can be extended to support additional modules and communication needs.

## Contributing
Contributions are welcome! Please follow the [contribution guidelines](CONTRIBUTING.md) when making contributions to this project.

## License
This project is licensed under the [BSD 3-Clause License](LICENSE).
