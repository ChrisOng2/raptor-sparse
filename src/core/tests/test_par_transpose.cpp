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
    int temp=RUN_ALL_TESTS();
    MPI_Finalize();
    return temp;

} // end of main() //

void test_par_transpose(std::string& file_A, std::string& file_AT)
{
    ParCSRMatrix* A = readParMatrix(file_A.c_str());
    ParCSRMatrix* AT_py = readParMatrix(file_AT.c_str());
    ParCSRMatrix* AT = (ParCSRMatrix*) A->transpose();
    A->sort();
    AT->sort();
    AT_py->sort();
    compare(AT, AT_py);
    delete A;
    delete AT_py;
    delete AT;

}

TEST(ParMatrixTest, TestsInCore)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file_A = folder + "aniso.pm";
    std::string file_AT = folder + "aniso_T.pm";
    test_par_transpose(file_A, file_AT);

    file_A = folder + "laplacian.pm";
    file_AT = folder + "laplacian_T.pm";
    test_par_transpose(file_A, file_AT);


} // end of TEST(ParMatrixTest, TestsInCore) //

