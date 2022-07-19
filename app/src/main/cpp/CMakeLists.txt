# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.
project("jnidemo"
        VERSION 0.1
        LANGUAGES CXX
        )
#需要修改此变量
#set(HUAWEI_SDK "/Users/eason/SDK/huawei")
set(HUAWEI_SDK /home/eason/Android/huawei_sdk)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#批量查询到.c .h .cpp文件
#file(GLOB allCpp *.c *.h *.cpp *.hpp)
include_directories(${CMAKE_SOURCE_DIR}/header)
include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${HUAWEI_SDK}/include)

add_library( # Sets the name of the library.
        window_soa
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        window-lib.cpp SoaWindowsImpl.cpp)

add_library( # Sets the name of the library.
        hac_soa
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        hac-lib.cpp SoaHacImpl.cpp)

## 添加第三方库
add_library(soa_ap
        SHARED
        IMPORTED)
set_target_properties(
        soa_ap
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/libs/libCalculatorClient.so)

message("${CMAKE_SOURCE_DIR}")
message("${ANDROID_ABI}")

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        window_soa
        soa_ap
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

target_link_libraries( # Specifies the target library.
        hac_soa
        soa_ap
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})