cmake_minimum_required (VERSION 2.6)
project (EmptyOxygine)


include_directories(../data data)
##########################################################
#########################OXYGINE##########################
add_subdirectory(../../oxygine-framework oxygine-framework)

add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})

link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")
###########################E#N#D############################


add_executable(EmptyOxygine 
    ../src/example.cpp 
    ../src/main.cpp
    ../src/ViewHelper.cpp
    ../src/Game/View/WorldScreenView.cpp
    ../src/Game/State.cpp
    ../src/Game/Unit.cpp
    ../src/Game/Fortress.cpp
    ../src/Game/Model/Game.cpp
    ../src/Game/View/UnitView.cpp
    ../src/Game/Model/Road.cpp
    ../src/Game/UnitFactory.cpp
    ../src/Game/Berserk.cpp
    ../src/Game/Warrior.cpp
    ../src/Game/BuildMenuConstructor.cpp
    ../src/Game/orcscout.cpp

)

target_link_libraries(EmptyOxygine ${OXYGINE_CORE_LIBS})



