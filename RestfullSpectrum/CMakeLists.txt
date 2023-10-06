cmake_minimum_required(VERSION 3.20)
project(RestfullSpectrum C)

include_directories(
        /usr/include/postgresql
       ../SeaBreeze/include )

link_directories(~/workspace/usb2000/SeaBreeze
        /usr/lib/x86_64-linux-gnu)


link_libraries(libseabreeze.so
        /home/nicked/workspace/temp/libmicrohttpd/src/microhttpd/.libs/libmicrohttpd.so
        pq
        usb
        cjson)


set(CMAKE_C_STANDARD 11)

add_executable(RestfullSpectrum
        main.c
        src/utils.c
        src/OceanOptics.c
        src/usb2000/util.c
        src/usb2000/dump.c
        src/usb2000/usb2000.c
        src/usb2000/seabreeze-util.c)








