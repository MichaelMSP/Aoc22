

cmake_minimum_required(VERSION 3.24)

project(AoC22)

set(CMAKE_CXX_STANDARD 20)


set (AOC_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/2022.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/days.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HelperFunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Day1.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Day2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Day3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Day4.cpp
)

add_executable(AoC2022 ${AOC_SRC})

set(Inputs
    inputs/day1_input.txt
    inputs/day2_input.txt
    inputs/day3_input.txt
)

foreach(file ${Inputs})
    add_custom_command(
    TARGET AoC2022 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/${file} 
        $<TARGET_FILE_DIR:AoC2022>)
endforeach()