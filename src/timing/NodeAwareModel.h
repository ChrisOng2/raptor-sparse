//
// Created by Christopher on 3/3/2025.
//

#ifndef NODEAWAREMODEL_H
#define NODEAWAREMODEL_H
#define PPN 32
#define PPS 16
#define SPN 2

#include "src/raptor-sparse.hpp"
#include <iostream>

double NodeAwareModel(ParCSRMatrix* A) {
    double T = 0;

    for (int i = 0; i < A->comm->send_data->num_msgs; i++) {
        int proc =  A->comm->send_data->procs[i];
        int msg_size = A->comm->send_data->size_msgs;
        int rank = i;

        std::vector<double> Alpha = {6.83E-07, 1.05E-06, 9.48E-07, 1.35E-06, 1.72E-05, 1.50E-04};
        std::vector<double> Beta  = {3.86E-10, 1.22E-10, 8.97E-10, 2.59E-10, 1.18E-08, 3.21E-10};
        int ByteSize              = 8192;

        if (proc/PPS == rank/PPS && msg_size < ByteSize)  { T += Alpha[0] + msg_size * Beta[0]; continue; }
        if (proc/PPS == rank/PPS && msg_size >= ByteSize) { T += Alpha[1] + msg_size * Beta[1]; continue; }
        if (proc/PPN == rank/PPN && msg_size < ByteSize)  { T += Alpha[2] + msg_size * Beta[2]; continue; }
        if (proc/PPN == rank/PPN && msg_size >= ByteSize) { T += Alpha[3] + msg_size * Beta[3]; continue; }
        if (msg_size < ByteSize)  { T += Alpha[4] + msg_size * Beta[4]; continue; }
        if (msg_size >= ByteSize) { T += Alpha[5] + msg_size * Beta[5]; continue; }
    }

    return T;
}


#endif //NODEAWAREMODEL_H
