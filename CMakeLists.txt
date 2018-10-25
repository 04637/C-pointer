cmake_minimum_required(VERSION 3.9)
project(laba7 C)

set(CMAKE_C_STANDARD 99)

####  part2
#add_executable(laba7 part2/polytree-c/loggingstringnode.h part2/polytree-c/loggingstringnode.c
#        part2/polytree-c/integernode.c part2/polytree-c/integernode.h
#        part2/polytree-c/node.c part2/polytree-c/node.h
#        part2/polytree-c/polytree.c
#        part2/polytree-c/reversestringnode.c part2/polytree-c/reversestringnode.h
#        part2/polytree-c/stringnode.c part2/polytree-c/stringnode.h)

####  part3
add_executable(laba7 part3/list.c part3/list.h  part3/trunc.c)

#### part4
#add_executable(laba7 part4/SB-switch.c)