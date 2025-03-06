# mbed ライブラリ
cmakeでmbedをビルド可能なリポジトリです．

## 対応ボード
- NUCLEO-F767ZI
- NUCLEO-F746ZG
- NUCLEO-F446RE

要望があれば他のボードも対応可能だと思います．Isuueかなにかで知らせてください．

## 使い方
### サブモジュールとして既存プロジェクトに追加
プロジェクトを作成したらまず以下のコマンドでサブモジュールとして追加します．

```bash
git submodule add https://github.com/crl-tdu/mbed.git mbed
```

### CMakeLists.txtに追加
完了したら以下のようにCMakeLists.txtを記述することでビルド可能です．

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
SET(BOARD_SELECT 767) # 767,746, or 446
include(mbed/mbed_build_settings.cmake)

# here starts the project
PROJECT(TEST C CXX ASM)

# uncomment below to have a verbose build process
#SET(CMAKE_VERBOSE_MAKEFILE ON)

include(mbed/mbed_files.cmake)

ADD_EXECUTABLE(${PROJECT_NAME}
        ${libmbed_files}
        ${board_specific_files}
        ${series_specific_files}
        main.cpp
        #ここにソースを追加していく
        )


SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 1)
# add syslibs dependencies to create the correct linker order
TARGET_LINK_LIBRARIES(${PROJECT_NAME} -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys)

include(mbed/mbed_after_build.cmake)
```

## 環境変数
```shell
PATH=/Applications/ARM/arm-none-eabi/bin:/Applications/ARM/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
```