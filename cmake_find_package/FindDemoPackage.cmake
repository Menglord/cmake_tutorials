message("Now using FindDemoPackage.cmake find DemoPackage lib")

Find_PATH(DemoPackage_INCLUDE_DIR math.h /usr/local/include)
message(".h dir ${DemoPackage_INCLUDE_DIR}")

FIND_LIBRARY(DemoPackage_LIBRARY libDemoPackage.so /usr/local/lib)
message("lib dir ${DemoPackage_LIBRARY}")

if(DemoPackage_INCLUDE_DIR AND DemoPackage_LIBRARY)
    set(DemoPackage_FOUND TRUE)
endif(DemoPackage_INCLUDE_DIR AND DemoPackage_LIBRARY)