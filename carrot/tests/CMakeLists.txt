add_executable(carrot_test carrot_test.cpp)
target_link_libraries(carrot_test carrot gtest_main)

include(GoogleTest)
gtest_discover_tests(carrot_test)
