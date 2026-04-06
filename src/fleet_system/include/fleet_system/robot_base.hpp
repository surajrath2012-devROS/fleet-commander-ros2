#pragma once 

#include "navigation_strategy.hpp"
#include <memory>

namespace fleet_system {

/**
 * @class BaseRobot
 * @brief The "Body" of our robot. It owns a "Brain" (Navigator).
 */
class BaseRobot {
protected:
    // 'protected' means child classes (like Forklift) can see these, 
    // but the outside world cannot. This is Encapsulation.
    std::string id_;
    int battery_level_;

    // 'std::unique_ptr' is a Smart Pointer. 
    // It means this robot is the ONLY owner of this brain.
    // When the robot dies, the brain is automatically deleted (no memory leaks!).
    std::unique_ptr<INavigator> brain_;

public:
    /**
     * @brief Constructor: We "inject" the brain into the robot.
     * We use std::move because a unique_ptr cannot be copied—only moved.
     */
    BaseRobot(std::string id, std::unique_ptr<INavigator> brain) 
        : id_(id), battery_level_(100), brain_(std::move(brain)) {}

    // Virtual destructor is mandatory for clean memory cleanup in inheritance.
    virtual ~BaseRobot() = default;

    /**
     * @brief The Arrow Operator (->) is used to reach into the 
     * smart pointer and call the brain's function.
     */
    void performMove(double x, double y) {
        if (brain_) {
            brain_->navigateTo(id_, x, y);
        }
    }

};

// 1. Forklift Robot 
class ForkliftRobot : public BaseRobot {
public:
    ForkliftRobot(std::string id, std::unique_ptr<INavigator> brain)
        : BaseRobot(id, std::move(brain)) {}
};

// 2. Drone Robot
class DroneRobot : public BaseRobot {
public:
    DroneRobot(std::string id, std::unique_ptr<INavigator> brain)
        : BaseRobot(id, std::move(brain)) {}
};

// 3. Floor Cleaning Robot
class ScrubberRobot : public BaseRobot {
public:
    ScrubberRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 4. Heavy Duty Lifting Robot
class PalletJackRobot : public BaseRobot {
public:
    PalletJackRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 5. Package Sorting Robot
class SorterRobot : public BaseRobot {
public:
    SorterRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 6. Night Patrol Security Robot
class SecurityRobot : public BaseRobot {
public:
    SecurityRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 7. RFID / Barcode Scanning Robot
class InventoryScannerRobot : public BaseRobot {
public:
    InventoryScannerRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 8. Towing/Tugger Robot
class TuggerRobot : public BaseRobot {
public:
    TuggerRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 9. Last-mile Indoor Delivery Robot
class DeliveryRobot : public BaseRobot {
public:
    DeliveryRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 10. Mobile Conveyor Belt Robot
class ConveyorRobot : public BaseRobot {
public:
    ConveyorRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 11. Maintenance & Tool Carrying Robot
class MaintenanceRobot : public BaseRobot {
public:
    MaintenanceRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

// 12. Mobile Charging Station Robot
class ChargerRobot : public BaseRobot {
public:
    ChargerRobot(std::string id, std::unique_ptr<INavigator> brain) : BaseRobot(id, std::move(brain)) {}
};

} // namespace fleet_system