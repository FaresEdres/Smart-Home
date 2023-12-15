# Smart Home Project README

## Overview
The Smart Home Project is designed to create a secure and automated environment for managing various aspects of a home. It involves a Master microcontroller that interfaces with a keypad and an LCD, allowing users to input passwords and navigate through a menu to configure settings. Additionally, there's a Slave microcontroller responsible for controlling room appliances such as lights, TV, AC, and monitoring temperature.

## Features

### Master Microcontroller
- **Keypad Input:** Accepts input for passwords, distinguishing between admin and guest access.
- **LCD Menu:** Provides a user-friendly menu interface for selecting admin or guest mode and configuring initial settings.
- **Block State:** Temporarily blocks access after multiple incorrect password attempts to prevent unauthorized entry.
- **Timeout Feature:** Implements a timeout mechanism after successful authentication to ensure security.

### Slave Microcontroller
- **Room Controls:** Allows the user (Slave) to remotely control four rooms, a TV, and an AC.
- **Temperature-Based AC Control:** Regulates the AC based on a temperature sensor; the AC operates only when the set temperature is lower than the current room temperature.

## Functionality
The Master microcontroller primarily handles user authentication, access control, and initial system setup. It provides a secure login interface and manages access privileges between admin and guest users. It also enforces security measures such as block state and timeout to enhance protection.

The Slave microcontroller focuses on room automation, enabling the user to remotely control various home appliances. It allows turning on/off lights, managing the TV, and controlling the AC based on environmental conditions by utilizing the temperature sensor.
## Circuit Diagram
![Screenshot 2023-12-15 134243](https://github.com/FaresEdres/Smart-Home/assets/88932198/63509112-b414-41ae-9d56-aa9708b8554d)

## Notes
This project aims to create a smart and secure home environment with user-friendly controls and automated functionalities. The system ensures proper access control while offering convenient management of home appliances based on user preferences and environmental factors.
