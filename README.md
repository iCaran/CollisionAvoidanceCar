## CollisionAvoidanceCar: An Arduino-Based Obstacle-Avoiding Robot

This repository contains the Arduino code for a simple collision avoidance robot. The project is designed to be a beginner-friendly introduction to robotics and Arduino programming, demonstrating basic obstacle detection and avoidance mechanisms.

### Project Overview

The CollisionAvoidanceCar project utilizes an Arduino microcontroller and various sensors to enable a small car to navigate an environment while avoiding collisions with obstacles. The car uses a collision avoidance algorithm to detect obstacles and adjust its direction to avoid them.

### Features

* **Obstacle Detection:** The car can detect obstacles using different types of sensors, including ultrasound sensors and infrared sensors.
* **Obstacle Avoidance:** The car uses a simple algorithm to adjust its direction and avoid colliding with detected obstacles.
* **Multiple Versions:** The repository includes four versions of the code in four separate branches, each using a different sensor configuration:
    * **v1:** Uses a stationary fixed ultrasound sensor to detect objects.
    * **v2:** Uses a rotating ultrasound sensor to detect the direction of the obstacle and adjust the turning direction.
    * **v3:** Uses a stationary fixed infrared sensor to detect objects.
    * **v4:** Uses a rotating infrared sensor to detect the direction of the obstacle and adjust the turning direction.
* **Adjustable Parameters:** The code allows you to adjust the delay duration, motor speed, and servo angle to fine-tune the car's performance and responsiveness.

### Getting Started

1. **Hardware:** You will need an Arduino microcontroller, a set of sensors (ultrasound or infrared), motors, a servo motor, and a chassis to build the car.
2. **Software:** Download the Arduino IDE from the official website ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)).
3. **Code:** Download the code from this repository and upload it to your Arduino board.
4. **Calibration:** Adjust the delay duration, motor speed, and servo angle in the code to optimize the car's performance and ensure proper obstacle detection.

### Project Structure

The repository contains the following files:

* **README.md:** This file.
* **[version] branch:** Contains the code for each version of the project. Switch to each branch to view the code for that version.

### Contributions

Feel free to contribute to this project by:

* **Improving the code:** Optimize the collision avoidance algorithm or add new features like more sophisticated obstacle detection or path planning.
* **Adding documentation:** Create detailed instructions for building and calibrating the car for each version.
* **Sharing your experience:** Share your own collision avoidance projects or challenges.

### License

This project is licensed under the MIT License. See the LICENSE file for more details.

### Acknowledgements

This project was inspired by various online resources and tutorials on collision avoidance robots.

### Let's Get Started!

Start building your own CollisionAvoidanceCar today and explore the exciting world of robotics with Arduino!
