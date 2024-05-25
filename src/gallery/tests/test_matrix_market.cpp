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

TEST(AnisoTest, TestsInGallery)
{
    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file_in = folder + "sas_P0.mtx";
    CSRMatrix* Amm = read_mm(file_in.c_str());
    std::string file_out = folder + "sas_P0_out.mtx";
    write_mm(Amm, file_out.c_str());
    CSRMatrix* Amm_out = read_mm(file_out.c_str());
    compare(Amm, Amm_out);

    // Diff the two mtx files 
    std::string command = "diff ";
    command += file_in.c_str();
    command += " ";
    command += file_out.c_str();
    int err = system(command.c_str());
    ASSERT_EQ(err, 0);

    remove(file_out.c_str());
     
    delete Amm_out;
    delete Amm;
} // end of TEST(AnisoTest, TestsInGallery) //


