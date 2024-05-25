# CMake generated Testfile for 
# Source directory: /Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests
# Build directory: /Users/bienz/Documents/Programs/raptor_master/raptor-sparse/build/src/gallery/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[StencilTest]=] "./test_stencil")
set_tests_properties([=[StencilTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;3;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[LaplacianTest]=] "./test_laplacian")
set_tests_properties([=[LaplacianTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;7;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[AnisoTest]=] "./test_aniso")
set_tests_properties([=[AnisoTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;11;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[MatrixMarketTest]=] "./test_matrix_market")
set_tests_properties([=[MatrixMarketTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;15;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[ParLaplacianTest1]=] "mpirun" "-n" "1" "./test_par_laplacian")
set_tests_properties([=[ParLaplacianTest1]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;21;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[ParLaplacianTest2]=] "mpirun" "-n" "2" "./test_par_laplacian")
set_tests_properties([=[ParLaplacianTest2]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;22;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[ParAnisoTest1]=] "mpirun" "-n" "1" "./test_par_aniso")
set_tests_properties([=[ParAnisoTest1]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;26;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[ParAnisoTest2]=] "mpirun" "-n" "2" "./test_par_aniso")
set_tests_properties([=[ParAnisoTest2]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;27;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
add_test([=[ParMatrixMarketTest2]=] "mpirun" "-n" "2" "./test_par_matrix_market")
set_tests_properties([=[ParMatrixMarketTest2]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;33;add_test;/Users/bienz/Documents/Programs/raptor_master/raptor-sparse/src/gallery/tests/CMakeLists.txt;0;")
