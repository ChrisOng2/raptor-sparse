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
  //
 
void test_transpose(std::string& file_A, std::string& file_AT)
{
    CSRMatrix* A = readMatrix(file_A.c_str());
    CSRMatrix* AT_py = readMatrix(file_AT.c_str());
    CSRMatrix* AT = (CSRMatrix*) A->transpose();
    A->sort();
    AT->sort();
    AT_py->sort();
    compare(AT, AT_py);
    delete A;
    delete AT_py;
    delete AT;
}

TEST(MatrixTest, TestsInCore)
{
    std::string folder = RAPTOR_SPARSE_TEST_FOLDER;
    std::string file_A = folder + "aniso.pm";
    std::string file_AT = folder + "aniso_T.pm";
    test_transpose(file_A, file_AT);

    file_A = folder + "laplacian.pm";
    file_AT = folder + "laplacian_T.pm";
    test_transpose(file_A, file_AT);

} // end of TEST(MatrixTest, TestsInCore) //


