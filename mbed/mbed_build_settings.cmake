# Begin Load tensorflow
if(DEFINED BOARD_SELECT)
    message("Selected board: ${BOARD_SELECT}")
    message("Start loading mbed...")
    if (${BOARD_SELECT} STREQUAL "767" OR ${BOARD_SELECT} STREQUAL "746")
        SET(SERIES_SELECT "F7")
    elseif(${BOARD_SELECT} STREQUAL "446")
        SET(SERIES_SELECT "F4")
    else()
        message(FATAL_ERROR [[
        Incorrect board selected!!
        Set like this
        cmake -DBOARD_SELECT=767 or 746 ..
        ]])
    endif ()
else()
    message(FATAL_ERROR [[
    Board not selected!!
    Set like this
    cmake -DBOARD_SELECT=767 or 746 ..
]])
endif()

SET(CMAKE_SYSTEM_NAME Generic)
#SET(CMAKE_SYSTEM_PROCESSOR arm)
SET(CMAKE_CROSSCOMPILING TRUE)

# force compiler settings
SET(CMAKE_C_COMPILER_WORKS TRUE)
SET(CMAKE_CXX_COMPILER_WORKS TRUE)

# force cmake compilers
SET(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")
SET(CMAKE_C_COMPILER "arm-none-eabi-gcc")
SET(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
SET(ELF2BIN "arm-none-eabi-objcopy")