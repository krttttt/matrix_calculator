# Ищем библиотеку Google Test
find_package(GTest REQUIRED)

# Создаем исполняемый файл тестов (подключаем наши исходники)
add_executable(matrix_tests test_matrix.cpp ../src/matrix.cpp)

# Линкуем Google Test и указываем путь к заголовкам
target_link_libraries(matrix_tests GTest::gtest_main)
target_include_directories(matrix_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Добавляем в CTest
add_test(NAME matrix_tests COMMAND matrix_tests)