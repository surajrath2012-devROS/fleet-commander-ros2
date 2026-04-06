# 🚀 Autonomous Warehouse Fleet Commander (ROS 2 & Modern C++)

A professional-grade ROS 2 Lifecycle system managing a polymorphic fleet of 12 unique warehouse robots using Modern C++ design patterns.

## 🎯 Project Overview
This project demonstrates a scalable architecture for managing diverse robotic assets in a warehouse environment. It focuses on **Memory Safety**, **Software Design Patterns**, and **Deterministic Robot States**.



## 🏗️ Key Architectural Features

### 1. The Strategy Pattern (Decoupled Navigation)
Instead of hardcoding movement, I implemented a **Strategy Pattern**. This allows robots to switch "brains" (e.g., A* Pathfinding vs. Direct Line) at runtime without modifying the robot's core code.
* **Concepts:** Pure Virtual Functions, Abstract Interfaces, `override` safety.



### 2. Modern C++ Memory Management
The system is 100% leak-proof using **Smart Pointers**:
* `std::unique_ptr`: Used for exclusive ownership of robot brains.
* `std::shared_ptr`: Used by the Fleet Manager to maintain a collection of robots.
* `std::move`: Handover semantics to transfer ownership safely.

### 3. ROS 2 Lifecycle Management
Built using `rclcpp_lifecycle` to ensure the fleet only executes commands when the system is in a deterministic `Active` state.
* **States handled:** `on_configure` (allocation), `on_activate` (execution), `on_cleanup` (de-allocation).

### 4. Polymorphism & Scalability
The `FleetManager` handles 12 different robot types (Drones, Forklifts, Scrubbers, etc.) through a single interface. Adding a 13th robot type requires zero changes to the management logic.



## 🛠️ Tech Stack
* **Language:** C++17/20
* **Framework:** ROS 2 (Humble/Jazzy)
* **Build System:** Colcon / CMake

## 🚀 How to Run
1. `colcon build --packages-select fleet_system`
2. `source install/setup.bash`
3. `ros2 run fleet_system fleet_commander_node`
4. Use ROS 2 Lifecycle CLI to `configure` and `activate`.