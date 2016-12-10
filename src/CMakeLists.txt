find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(teamgreen team_green.cpp Target.cpp TargetDetector.cpp TargetProcessor.cpp NetworkController.cpp VideoDevice.cpp GUIManager.cpp CmdLineInterface.cpp AppConfig.cpp)
target_link_libraries(teamgreen ${OpenCV_LIBS} ${Boost_LIBRARIES})
