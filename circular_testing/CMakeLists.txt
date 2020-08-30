find_package(GTest)

macro(circular_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    circular::header
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

circular_add_test(circulator circulator_test circulator_test.cpp)
circular_add_test(circulant circulant_test circulant_test.cpp)
circular_add_test(fixed_circulant fixed_circulant_test fixed_circulant_test.cpp)
circular_add_test(algorithms algorithms_test algorithms_test.cpp)

