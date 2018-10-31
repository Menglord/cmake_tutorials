cmake_minimum_required(VERSION 2.8)
project(Demo3)
set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

message("${PROJECT_SOURCE_DIR}")
message("${PROJECT_BINARY_DIR}")
message("${CMAKE_ROOT}")
message("${CMAKE_INCLUDE_PATH}")
message("${CMAKE_LIBRARY_PATH}")
message("${CMAKE_PREFIX_PATH}")

include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HAVE_POW)

configure_file(
	"${PROJECT_SOURCE_DIR}/config/config.h.in"
	"${PROJECT_BINARY_DIR}/config/config.h"
)

include_directories("${PROJECT_BINARY_DIR}/config")

option(USE_MYMATH "Use provided math implementation" ON)

if (USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/src/math")
	add_subdirectory(src/math)
	set(EXTRA_LIBS ${EXTRA_LIBS} libMathFunctions)
endif(USE_MYMATH)

aux_source_directory(src DIR_SRCS)

add_executable(Demo ${DIR_SRCS})
target_link_libraries(Demo ${EXTRA_LIBS})

install(TARGETS Demo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config/config.h" DESTINATION include)

enable_testing()
#Test Macro
macro(do_test arg1 arg2 result)
	add_test(test_${arg1}_${arg2} Demo ${arg1} ${arg2})
	set_tests_properties(test_${arg1}_${arg2}
		PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

do_test(5  2 "is 25")
do_test(10 5 "is 100000")
do_test(2 10 "is 1024")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
	"${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
include(CPack)



