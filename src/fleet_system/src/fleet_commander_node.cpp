#include <rclcpp/rclcpp.hpp>
#include "fleet_system/fleet_manager.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

namespace fleet_system 
{
    /**
 * @class FleetCommanderNode
 * @brief ROS 2 Lifecycle Node that controls our C++ Fleet logic.
 */
class FleetCommanderNode : public rclcpp_lifecycle::LifecycleNode {

private:
    // We own the Commander through a unique_ptr
    std::unique_ptr<FleetManager> manager_;

public:
    // Constructor: Giving the node a name in the ROS 2 system
    explicit FleetCommanderNode(const std::string & node_name)
    : rclcpp_lifecycle::LifecycleNode(node_name) {}

    /**
     * @brief Transition: Unconfigured -> Inactive
     * Purpose: Initialize our C++ objects and setup the fleet.
     */
    CallbackReturn on_configure(const rclcpp_lifecycle::State &) {
    RCLCPP_INFO(get_logger(), "Configuring Fleet: Building an army of 12 robots...");

    manager_ = std::make_unique<FleetManager>();

    // 1 & 2: Original Robots
    auto drone = std::make_shared<DroneRobot>("SkyEye_01", std::make_unique<AStarNavigator>());
    auto forklift = std::make_shared<ForkliftRobot>("LiftMaster_99", std::make_unique<DirectLineNavigator>());

    // 3 & 4: Cleaning and Heavy Lifting
    auto scrubber = std::make_shared<ScrubberRobot>("Scrubby_01", std::make_unique<DirectLineNavigator>());
    auto pallet_jack = std::make_shared<PalletJackRobot>("Heavy_Pete", std::make_unique<DirectLineNavigator>());

    // 5 & 6: Logistics and Security (Smart Brains)
    auto sorter = std::make_shared<SorterRobot>("Sort_O_Matic", std::make_unique<AStarNavigator>());
    auto security = std::make_shared<SecurityRobot>("GuardDog_05", std::make_unique<AStarNavigator>());

    // 7 & 8: Inventory and Towing
    auto scanner = std::make_shared<InventoryScannerRobot>("Shelf_Scanner", std::make_unique<DirectLineNavigator>());
    auto tugger = std::make_shared<TuggerRobot>("Tuggy_McTug", std::make_unique<DirectLineNavigator>());

    // 9 & 10: Delivery and Conveying
    auto delivery = std::make_shared<DeliveryRobot>("Express_Bot", std::make_unique<AStarNavigator>());
    auto conveyor = std::make_shared<ConveyorRobot>("Belt_on_Wheels", std::make_unique<DirectLineNavigator>());

    // 11 & 12: Maintenance and Power
    auto maintenance = std::make_shared<MaintenanceRobot>("Wrench_Wizard", std::make_unique<AStarNavigator>());
    auto charger = std::make_shared<ChargerRobot>("Power_Plug", std::make_unique<DirectLineNavigator>());

    // Adding all 12 to the Manager
    manager_->addRobot(drone);
    manager_->addRobot(forklift);
    manager_->addRobot(scrubber);
    manager_->addRobot(pallet_jack);
    manager_->addRobot(sorter);
    manager_->addRobot(security);
    manager_->addRobot(scanner);
    manager_->addRobot(tugger);
    manager_->addRobot(delivery);
    manager_->addRobot(conveyor);
    manager_->addRobot(maintenance);
    manager_->addRobot(charger);

    RCLCPP_INFO(get_logger(), "Fleet Setup Complete. 12 robots are standing by.");
    return CallbackReturn::SUCCESS;
}

    /**
     * @brief Transition: Inactive -> Active
     * Purpose: Start the actual robotics mission.
     */
    CallbackReturn on_activate(const rclcpp_lifecycle::State &) {
        RCLCPP_INFO(get_logger(), "Fleet Activated! Dispatching robots...");
        
        // This is the C++ function we wrote in Phase 3!
        manager_->deployFleet(15.5, 20.0);

        return CallbackReturn::SUCCESS;
    }

    /**
     * @brief Cleanup when the node is shut down.
     */
    CallbackReturn on_cleanup(const rclcpp_lifecycle::State &) {
        manager_.reset(); // Deletes the manager and all its robots automatically
        RCLCPP_INFO(get_logger(), "Fleet Cleaned up.");
        return CallbackReturn::SUCCESS;
    }
    
};    

} // namespace fleet_system

// The standard C++ main function to run the node
int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<fleet_system::FleetCommanderNode>("fleet_commander");
    rclcpp::spin(node->get_node_base_interface()); // The "Spinning" process [cite: 334]
    rclcpp::shutdown();
    return 0;
}