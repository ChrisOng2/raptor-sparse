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

TEST(ParMatrixAddTest, TestsInUtil)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    ParCSRMatrix* A;
    ParCSRMatrix* S;
    ParCSRMatrix* AS;
    ParCSRMatrix* AS_rap;

    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file;

    // TEST LEVEL 0
    file = folder + "rss_A0.pm";
    A = readParMatrix(file.c_str());
    file = folder + "rss_S0.pm";
    S = readParMatrix(file.c_str());
    file = folder + "rss_AS.pm";
    AS = readParMatrix(file.c_str());
    AS_rap = A->add(S);

    compare(AS, AS_rap);
    delete AS;
    delete AS_rap;

    file = folder + "rss_AmS.pm";
    AS = readParMatrix(file.c_str());
    AS_rap = A->subtract(S);

    compare(AS, AS_rap);

    delete AS_rap;
    delete AS;
    delete S;
    delete A;


 
} // end of TEST(ParMatrixAddTest, TestsInUtil) //

