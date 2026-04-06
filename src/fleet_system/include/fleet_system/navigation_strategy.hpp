#pragma once // Header guard to prevent multiple inclusion errors[cite: 70].

#include <iostream>
#include <string>

/**
 * @namespace fleet_system
 * @brief Organizational scope to prevent naming collisions with ROS 2 or other libraries[cite: 380, 386].
 */
namespace fleet_system
{
    /**
     * @class INavigator
     * @brief Abstract Interface defining the "contract" for all navigation brains[cite: 377].
     * This class cannot be instantiated because it contains a pure virtual function[cite: 77].
     */
    class INavigator {
    public:
        /**
         * @brief Virtual destructor is mandatory in base classes used for inheritance.
         * It ensures derived classes are cleaned up correctly via a base pointer[cite: 416, 417].
         */
        virtual ~INavigator() = default;

        /**
         * @brief Pure virtual function that every child class must implement.
         * @param robot_id Const reference to avoid copying memory[cite: 415, 417].
         * @param target_x/y Double precision coordinates for accurate robotics movement.
         */
        virtual void navigateTo(const std::string& robot_id, double target_x, double target_y) = 0;
    };

    /**
     * @class AStarNavigator
     * @brief Concrete implementation of a smart, obstacle-avoiding brain[cite: 77].
     */
    class AStarNavigator : public INavigator{
    public:
        /**
         * @brief Overrides the base function to provide A* specific logic.
         * The 'override' keyword provides compile-time safety against typos[cite: 399].
         */
        void navigateTo(const std::string& robot_id, double target_x, double target_y) override
        {
            std::cout << "[" << robot_id << "] A* Brain: Calculating complex path around obstacles to (" 
                      << target_x << ", " << target_y << ").\n";
        };
    };

    /**
     * @class DirectLineNavigator
     * @brief Concrete implementation of a simple, straight-line movement brain[cite: 77].
     */
    class DirectLineNavigator : public INavigator
    {
    public:
        void navigateTo(const std::string& robot_id, double target_x, double target_y) override {
            std::cout << "[" << robot_id << "] Direct Brain: Driving in a straight, blind line to (" 
                      << target_x << ", " << target_y << ").\n";
        }
    };

} // namespace fleet_system