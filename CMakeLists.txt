cmake_minimum_required(VERSION 3.24)

project(kv_store LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- kv_core (library) ----
add_library(kv_core
	src/error.cpp
	src/config.cpp
)

target_include_directories(kv_core
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/src
		${CMAKE_CURRENT_SOURCE_DIR}/third_party/tl_expected
)

target_compile_options(kv_core PRIVATE
	-Wall -Wextra -Wpedantic -Werror
)

# ---- kv_cli (executable) ----
add_executable(kv_cli
	src/main.cpp
)

target_include_directories(kv_cli 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(kv_cli PRIVATE kv_core)

target_compile_options(kv_cli PRIVATE
	-Wall -Wextra -Wpedantic -Werror
)

# ---- kv_tests ----
enable_testing()

add_executable(kv_tests 
	tests/smoke_test.cpp
)

target_link_libraries(kv_tests PRIVATE kv_core)

target_compile_options(kv_tests PRIVATE
	-Wall -Wextra -Wpedantic -Werror
)

add_test(NAME smoke COMMAND $<TARGET_FILE:kv_tests>)
