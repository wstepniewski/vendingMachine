cmake_minimum_required(VERSION 3.17)
project(vendingMachine)

set(CMAKE_CXX_STANDARD 14)

add_executable(vendingMachine main.cpp drink.cpp drink.h vending_machine.cpp vending_machine.h blik.cpp blik.h card.cpp card.h menu.cpp menu.h coins.cpp coins.h payment.cpp payment.h container.cpp container.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stdin.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})