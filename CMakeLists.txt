cmake_minimum_required(VERSION 3.16)
project(amicable_numbers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(
  copy-compile-commands ALL
  ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_LIST_DIR}
)

# add no optimizations in the Debug build
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

add_executable(amicable_numbers main.cpp)
set_property(TARGET amicable_numbers PROPERTY CXX_STANDARD 17)
target_compile_options(amicable_numbers PRIVATE -Wall -Wextra -Wpedantic -Werror)

if(DEFINED ENV{TBB_INSTALL_DIR})
  target_include_directories(amicable_numbers SYSTEM BEFORE PRIVATE $ENV{TBB_INSTALL_DIR}/include)
  target_link_directories(amicable_numbers BEFORE PRIVATE $ENV{TBB_INSTALL_DIR}/lib)
  target_link_libraries(amicable_numbers PRIVATE tbb)
else()
  message(FATAL_ERROR "TBB_INSTALL_DIR not found in the environment, exitting.")
endif()
