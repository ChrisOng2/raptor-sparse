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

TEST(ParAnisoTest, TestsInGallery)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file_in = folder + "sas_P0.mtx";
    std::string file_out = folder + "sas_P0_out.mtx";

    ParCSRMatrix* Amm = read_par_mm(file_in.c_str());

    MPI_Barrier(MPI_COMM_WORLD);
    write_par_mm(Amm, file_out.c_str());

    MPI_Barrier(MPI_COMM_WORLD);
    ParCSRMatrix* Amm_out = read_par_mm(file_out.c_str());
    
    MPI_Barrier(MPI_COMM_WORLD);
    compare(Amm, Amm_out);

    // Diff the two mtx files 
    if (rank == 0)
    {
        remove(file_out.c_str());
    }

    delete Amm_out;
    delete Amm;

 } // end of TEST(ParAnisoTest, TestsInGallery) //


