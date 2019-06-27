cmake_minimum_required(VERSION 2.6)
project(ctf CXX)

set (CMAKE_CXX_STANDARD 11)

if (APPLE)
       set(CMAKE_MACOSX_RPATH ON)
endif (APPLE)

add_library(xor4file
        SHARED include/xor4file.h include/xor4file.cpp
        )

add_executable(exec-encrypt encrypt/main.cpp)

target_link_libraries(exec-encrypt xor4file)

execute_process(
        COMMAND ./exec-encrypt ctf4b-kosen{y0u_g0t_th1s_flag} ./code
        OUTPUT_FILE ${PROJECT_BINARY_DIR}/.hint
)

add_executable(exec-me app/main.cpp)

target_link_libraries(exec-me xor4file)

install(CODE "execute_process(COMMAND sh ${PROJECT_SOURCE_DIR}/install.sh)")
