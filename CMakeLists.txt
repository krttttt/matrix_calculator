# cmake_minimum_required(VERSION 3.20)
# project(Matrix_Calculator LANGUAGES CXX)

# # Включаем C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Указываем, где искать matrix.h (это уберет красное подчеркивание)
# include_directories(include)

# # Собираем исполняемый файл
# add_executable(matrix_calculator src/main.cpp src/matrix.cpp)

# # Тесты
# enable_testing()
# add_subdirectory(tests)

cmake_minimum_required(VERSION 3.20)
project(Matrix_Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(matrix_calculator src/main.cpp src/matrix.cpp)

# Включаем тесты ТОЛЬКО если мы явно этого захотели (например, при локальной сборке)
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()