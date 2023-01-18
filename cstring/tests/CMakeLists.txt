add_executable(CString CStringTest.cpp)

target_link_libraries(CString gtest gtest_main pthread)