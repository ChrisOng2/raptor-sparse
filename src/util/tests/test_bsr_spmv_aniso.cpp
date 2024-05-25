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

TEST(AnisoSpMVTest, TestsInUtil)
{
    int grid[2] = {25, 25};
    double eps = 0.001;
    double theta = M_PI/8.0;
    double* stencil = diffusion_stencil_2d(eps, theta);
    CSRMatrix* A_sten = stencil_grid(stencil, grid, 2);
    BSRMatrix* A = new BSRMatrix(A_sten, 5, 5);

    Vector x(A_sten->n_rows);
    Vector b(A_sten->n_rows);

    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file;

    // Test b <- A*ones
    x.set_const_value(1.0);
    A->mult(x, b);
    file = folder + "aniso_ones_b.txt";
    compare_vectors(b, file);

    // Test b <- A_T*ones
    A->mult_T(x, b);
    file = folder + "aniso_ones_b_T.txt";
    compare_vectors(b, file);

    // Tests b <- A*incr
    for (int i = 0; i < A_sten->n_rows; i++)
    {
        x[i] = i;
    }
    A->mult(x, b);
    file = folder + "aniso_inc_b.txt";
    compare_vectors(b, file);

    // Tests b <- A_T*incr
    A->mult_T(x, b);
    file = folder + "aniso_inc_b_T.txt";
    compare_vectors(b, file);

    delete A;
    delete A_sten;

} // end of TEST(AnisoSpMVTest, TestsInUtil) //

