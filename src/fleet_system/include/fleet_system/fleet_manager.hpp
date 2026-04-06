#pragma once

#include "robot_base.hpp"
#include <vector> // The Magic Train
#include <memory> // For shared_ptr

namespace fleet_system {

/**
 * @class FleetManager
 * @brief Manages a collection of robots using Polymorphism and Smart Pointers.
 */
class FleetManager {
private:
    // A Magic Train (vector) that holds Family Keys (shared_ptr) 
    // pointing to any kind of Robot (BaseRobot).
    std::vector<std::shared_ptr<BaseRobot>> robots_;

public:
    FleetManager() = default;
    ~FleetManager() = default;

    /**
     * @brief Adds a new robot to the warehouse fleet.
     * @param robot A shared pointer to a robot (could be a Forklift or Drone).
     */
    void addRobot(std::shared_ptr<BaseRobot> robot) {
        if (robot) {
            // Push the robot into our magic train
            robots_.push_back(robot);
            std::cout << "FleetManager: Robot added to the fleet inventory.\n";
        }
    }

    /**
     * @brief THE "WHOA" MOMENT: One loop to rule them all.
     * This uses Polymorphism to call the right code for each robot.
     */
    void deployFleet(double x, double y) {
        std::cout << "\n--- Deploying Fleet to Target (" << x << ", " << y << ") ---\n";
        
        // We walk through our magic train
        for (const auto& robot : robots_) {
            // Even though the train only knows they are 'BaseRobots',
            // C++ knows if it's actually a Forklift or Drone!
            robot->performMove(x, y);
        }
        std::cout << "--- All robots have been dispatched ---\n";
    }
};

} // namespace fleet_system