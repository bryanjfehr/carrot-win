include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(memlock_test memlock_test.cpp)
target_link_libraries(memlock_test memlock gtest_main)

include(GoogleTest)
gtest_discover_tests(memlock_test)
