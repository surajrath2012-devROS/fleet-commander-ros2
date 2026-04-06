cmake_minimum_required(VERSION 3.8)
project(fleet_system)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(std_msgs REQUIRED)

# Include the headers folder
include_directories(include)

# Create the Executable (The actual program)
add_executable(fleet_commander_node src/fleet_commander_node.cpp)

# Link the libraries (Connecting our code to ROS 2)
target_link_libraries(fleet_commander_node
  rclcpp::rclcpp
  rclcpp_lifecycle::rclcpp_lifecycle
)

# Install the executable so we can run it with 'ros2 run'
install(TARGETS
  fleet_commander_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()