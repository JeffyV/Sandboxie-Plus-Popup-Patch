cmake_minimum_required(VERSION 4.0)
project(SandManMsgPatcher)

set(CMAKE_CXX_STANDARD 26)

add_link_options(-static-libstdc++ -Wl,-Bstatic -lunwind -Wl,-Bdynamic)

add_library(version SHARED dllmain.cpp version.def)
