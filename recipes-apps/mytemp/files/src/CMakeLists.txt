cmake_minimum_required(VERSION 3.16.3)
project(test)
add_executable(test uart_test.c)
install(TARGETS test DESTINATION bin)
