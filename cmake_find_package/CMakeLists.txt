cmake_minimum_required(VERSION 2.8)
project(DemoPackage)
add_compile_options(-std=c++11)

aux_source_directory(src DIR_LIB_SRCS)

add_library(DemoPackage SHARED ${DIR_LIB_SRCS})

#Install Rules
install(TARGETS DemoPackage DESTINATION /usr/local/lib)
install(FILES src/demo_package.h DESTINATION /usr/local/include)
install(FILES FindDemoPackage.cmake DESTINATION /usr/local/share/cmake/Modules)