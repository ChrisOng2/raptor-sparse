// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#include "gtest/gtest.h"
#include "src/raptor-sparse.hpp"
#include "src/tests/compare.hpp"

using namespace raptor;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

} // end of main() //

TEST(LaplacianSpMVTest, TestsInUtil)
{
    int grid[3] = {10, 10, 10};
    double* stencil = laplace_stencil_27pt();
    CSRMatrix* A_sten = stencil_grid(stencil, grid, 3);

    Vector x(A_sten->n_rows);
    Vector b(A_sten->n_rows);
    
    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file;

    // Test b <- A*ones
    x.set_const_value(1.0);
    A_sten->mult(x, b);
    file = folder + "laplacian27_ones_b.txt";
    compare_vectors(b, file);


    // Test b <- A_T*ones
    A_sten->mult_T(x, b);
    file = folder + "laplacian27_ones_b_T.txt";
    compare_vectors(b, file);

    // Tests b <- A*incr
    for (int i = 0; i < A_sten->n_rows; i++)
    {
        x[i] = i;
    }
    A_sten->mult(x, b);
    file = folder + "laplacian27_inc_b.txt";
    compare_vectors(b, file);


    // Tests b <- A_T*incr
    A_sten->mult_T(x, b);
    file = folder + "laplacian27_inc_b_T.txt";
    compare_vectors(b, file);

    delete A_sten;

} // end of TEST(LaplacianSpMVTest, TestsInUtil) //

