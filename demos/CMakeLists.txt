add_executable (demo_vector demo_vector.cpp)
add_executable (demo_matrix demo_matrix.cpp)
add_executable (demo_test_lapack_matrix test_lapack_matrix.cpp)


target_sources (demo_vector PUBLIC ../src/vector.hpp ../src/vecexpr.hpp)
