#include "demo_package.h"
#include <iostream>

namespace DemoPackage{
	void Print(std::string str){
		std::cout << "I'm Demo Package For Testing CMake find_package" << std::endl;
	}
}
