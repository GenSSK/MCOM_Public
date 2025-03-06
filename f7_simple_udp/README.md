# f7_simple_udp

F7シリーズ用のUDPライブラリ．

自分のプロジェクトに以下のような送受信したい構造体が含まれるdataStruct.hを用意

```c++
#ifndef MBED_DEV_DATASTRUCT_H
#define MBED_DEV_DATASTRUCT_H

/* PC to mbed */
struct toMbed{
    float ch1 = 0.0;
    float ch2 = 0.0;
    float ch3 = 0.0;
    float ch4 = 0.0;
    float led1 = 0.0;
    float led2 = 0.0;
    float led3 = 0.0;
    float led4 = 0.0;
    float led5 = 0.0;
    float led6 = 0.0;
    float led7 = 0.0;
    bool servo1 = false;
    bool servo2 = false;
    int checkCount = 0;
    int returnCount = 0;
};

/* mbed to PC */
struct toPC{
    int tim1_pulse = 0;
    int tim3_pulse = 0;
    int tim4_pulse = 0;
    int tim8_pulse = 0;
    float ch1 = 0.0;
    float ch2 = 0.0;
    float ch3 = 0.0;
    float ch4 = 0.0;
    int checkCount = 0;
    int returnCount = 0;
    int mbedCheck = 0;
};

#endif //MBED_DEV_DATASTRUCT_H
```

CMakeLists.txtを以下のように変更

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
include(mbed/mbed_build_settings.cmake)

# here starts the project
PROJECT(F767_simple_UDP C CXX ASM)

# uncomment below to have a verbose build process
#SET(CMAKE_VERBOSE_MAKEFILE ON)

include(mbed/mbed_files.cmake)

include(f7_simple_udp/f7_simple_udp.cmake) #追加

ADD_EXECUTABLE(${PROJECT_NAME}
        ${libmbed_files}
        ${board_specific_files}
        ${f7_simple_udp_files} #追加
        main.cpp
        dataStruct.h #追加
        #ここにソースを追加していく
        )


SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 1)
# add syslibs dependencies to create the correct linker order
TARGET_LINK_LIBRARIES(${PROJECT_NAME} -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys)

include(mbed/mbed_after_build.cmake)
```

