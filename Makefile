conan_install:
	conan install . -if cmake-build-debug -b missing -s build_type=Debug -pr:b=clang-cpp17 -pr:h=clang-cpp17

config:
	cmake -S . -B cmake-build-debug -DCMAKE_TOOLCHAIN_FILE=cmake-build-debug/conan/conan_toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES

build:
	cmake --build cmake-build-debug -- -j12

test:
	echo "Implement"

install:
	echo "Implement"

package:
	echo "Implement"