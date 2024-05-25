// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#include "gtest/gtest.h"
#include "src/raptor-sparse.hpp"
#include "src/tests/par_compare.hpp"

using namespace raptor;

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    ::testing::InitGoogleTest(&argc, argv);
    int temp = RUN_ALL_TESTS();
    MPI_Finalize();
    return temp;
} // end of main() //

TEST(ParRandomSpMVTest, TestsInUtil)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file;

    file = folder + "random.pm";
    ParCSRMatrix* A = readParMatrix(file.c_str());

    ParVector x(A->global_num_cols, A->on_proc_num_cols);
    ParVector b(A->global_num_rows, A->local_num_rows);

    x.set_const_value(1.0);
    A->mult(x, b);
    file = folder + "random_ones_b.txt";
    compare_par_vectors(b, A->partition->first_local_row, file);

    b.set_const_value(1.0);
    A->mult_T(b, x);
    file = folder + "random_ones_b_T.txt";
    compare_par_vectors(x, A->partition->first_local_row, file);

    for (int i = 0; i < A->on_proc_num_cols; i++)
    {
        x[i] = A->partition->first_local_col + i;
    }
    A->mult(x, b);
    file = folder + "random_inc_b.txt";
    compare_par_vectors(b, A->partition->first_local_row, file);

    for (int i = 0; i < A->local_num_rows; i++)
    {
        b[i] = A->partition->first_local_row + i;
    }
    A->mult_T(b, x);
    file = folder + "random_inc_b_T.txt";
    compare_par_vectors(x, A->partition->first_local_row, file);

    delete A;

} // end of TEST(ParRandomSpMVTest, TestsInUtil) //
