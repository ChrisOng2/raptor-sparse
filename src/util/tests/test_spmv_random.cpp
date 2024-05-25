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

TEST(RandomSpMVTest, TestsInUtil)
{
    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file;

    file = folder + "random.pm";
    CSRMatrix* A = readMatrix(file.c_str());

    Vector x(A->n_cols);
    Vector b(A->n_rows);
    
    // Test b <- A*ones
    x.set_const_value(1.0);
    A->mult(x, b);
    file = folder + "random_ones_b.txt";
    compare_vectors(b, file);

    // Test b <- A_T*ones
    b.set_const_value(1.0);
    A->mult_T(b, x);
    file = folder + "random_ones_b_T.txt";
    compare_vectors(x, file);

    // Tests b <- A*incr
    for (int i = 0; i < A->n_cols; i++)
    {
        x[i] = i;
    }
    A->mult(x, b);
    file = folder + "random_inc_b.txt";
    compare_vectors(b, file);
 
    // Tests b <- A_T*incr
    for (int i = 0; i < A->n_rows; i++)
    {
        b[i] = i;
    }
    A->mult_T(b, x);
    file = folder + "random_inc_b_T.txt";
    compare_vectors(x, file);

    
} // end of TEST(RandomSpMVTest, TestsInUtil) //

