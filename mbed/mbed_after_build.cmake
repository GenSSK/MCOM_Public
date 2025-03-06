if (${BOARD_SELECT} STREQUAL "767")
    add_custom_command(TARGET ${PROJECT_NAME} PRE_LINK
            COMMAND "arm-none-eabi-cpp" -E -P -Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=softfp mbed/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/device/TOOLCHAIN_GCC_ARM/STM32F767xI.ld -o ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld"
            )
elseif(${BOARD_SELECT} STREQUAL "746")
    add_custom_command(TARGET ${PROJECT_NAME} PRE_LINK
            COMMAND "arm-none-eabi-cpp" -E -P -Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=softfp mbed/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F746xG/device/TOOLCHAIN_GCC_ARM/STM32F746xG.ld -o ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld"
            )
elseif(${BOARD_SELECT} STREQUAL "446")
    add_custom_command(TARGET ${PROJECT_NAME} PRE_LINK
            COMMAND "arm-none-eabi-cpp" -E -P -Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -ffunction-sections -fdata-sections -funsigned-char -MMD -fomit-frame-pointer -Os -g -DMBED_TRAP_ERRORS_ENABLED=1 -DMBED_MINIMAL_PRINTF -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -DMBED_ROM_START=0x8000000 -DMBED_ROM_SIZE=0x80000 -DMBED_RAM_START=0x20000000 -DMBED_RAM_SIZE=0x20000 -DMBED_BOOT_STACK_SIZE=4096 -DXIP_ENABLE=0 mbed/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F446xE/device/TOOLCHAIN_GCC_ARM/STM32F446XE.ld -o ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_pp.link_script.ld"
            )
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${ELF2BIN} -O ihex $<TARGET_FILE:${PROJECT_NAME}> $<TARGET_FILE:${PROJECT_NAME}>.hex
        COMMAND ${CMAKE_COMMAND} -E echo "-- built: $<TARGET_FILE:${PROJECT_NAME}>.hex"
        )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${ELF2BIN} -O binary $<TARGET_FILE:${PROJECT_NAME}> $<TARGET_FILE:${PROJECT_NAME}>.bin
        COMMAND ${CMAKE_COMMAND} -E echo "-- built: $<TARGET_FILE:${PROJECT_NAME}>.bin"
        )