aux_source_directory(. DIR_LIB_SRCS)
add_library(libMathFunctions STATIC ${DIR_LIB_SRCS})
#Install Rules
install(TARGETS libMathFunctions DESTINATION bin)
install(FILES math_function.h DESTINATION include)