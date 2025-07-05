//
// Created by Christopher on 6/23/2025.
//

#ifndef PARTITIONING_TIMING_H
#define PARTITIONING_TIMING_H
#define PPN 32
#define PPS 16
#define SPN 2

#include <vector>
#include "src/raptor.hpp"
#include "src/tests/par_matrix.hpp"

std::vector<int> ParMatrix::GlobaltoLocalIndex()
{
    std::vector<int> LocalIndex;
    if (off_proc->nnz == 0)
    {
        return;
    }

    int prev_col = -1;

    std::map<int, int> orig_to_new;

    std::copy(off_proc->idx2.begin(), off_proc->idx2.end(),
            std::back_inserter(off_proc_column_map));
    std::sort(off_proc_column_map.begin(), off_proc_column_map.end());

    off_proc_num_cols = 0;
    for (std::vector<int>::iterator it = off_proc_column_map.begin();
            it != off_proc_column_map.end(); ++it)
    {
        if (*it != prev_col)
        {
            orig_to_new[*it] = off_proc_num_cols;
            off_proc_column_map[off_proc_num_cols++] = *it;
            prev_col = *it;
        }
    }
    off_proc_column_map.resize(off_proc_num_cols);

    for (std::vector<int>::iterator it = off_proc->idx2.begin();
            it != off_proc->idx2.end(); ++it)
    {
        *it = orig_to_new[*it];
    }
    LocalIndex = off_proc_column_map;
    return LocalIndex;
}

double CSC_Partition_Time_Estimation(ParCSRMatrix* A) {
    ParCSRMatrix* recv_mat      = A->comm->communicate(A, false);
    // global matrix columns to local index
    std::vector<int> LocalIndex = recv_mat.GlobaltoLocalIndex();
    ParCSCMatrix* recv_mat_CSC  = recv_mat.to_ParCSC();

    std::vector<double> Alpha = {6.83E-07, 1.05E-06, 9.48E-07, 1.35E-06, 1.72E-05, 1.50E-04};
    std::vector<double> Beta  = {3.86E-10, 1.22E-10, 8.97E-10, 2.59E-10, 1.18E-08, 3.21E-10};
    int ByteSize              = 8192;

    for (int col = 0; col < recv_mat_CSC->n_cols; col++) {
        int col_start = 0;
        int col_end   = 0;
        double Timing = 0;

        for (int j = col_start; j < col_end; j++) {
            int row = recv_mat_CSC->idx2[j];
            int row_start = recv_mat->idx1[row];
            int row_end = recv_mat.idx1[row+1];

            for (int k = row_start; k < row_end; k++) {
                int LocalCol = recv_mat->idx2[k];

            }
        }
    }


    return Timing;

}
#endif //PARTITIONING_TIMING_H
