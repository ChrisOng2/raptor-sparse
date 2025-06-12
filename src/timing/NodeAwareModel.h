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

double NodeAwareModel(ParCSRMatrix A) {
    double T = 0;

    for (int i = 0; i < A.comm.send_data.num_msgs; i++) {
        double Alpha = 0;
        double Beta = 0;
        int proc =  A.comm.send_data.procs[i];
        int msg_size = A.comm.send_data.size_msgs;
        int rank = i;

        if (proc/PPS == rank/PPS) {
            if (msg_size < 8192) {
                Alpha = 6.83E-07;
                Beta = 3.86E-10;
            }

            if (msg_size > 8192) {
                Alpha = 1.05E-06;
                Beta = 1.22E-10;
            }
        }
        else if (proc/PPN == rank/PPN) {
            if (msg_size < 8192) {
                Alpha = 9.48E-07;
                Beta = 8.97E-10;
            }

            if (msg_size > 8192) {
                Alpha = 1.35E-06;
                Beta = 2.59E-10;
            }
        }
        else {
            if (msg_size < 8192) {
                Alpha = 1.72E-05;
                Beta = 1.18E-08;
            }

            if (msg_size > 8192) {
                Alpha = 1.50E-04;
                Beta = 3.21E-10;
            }
        }

        T += Alpha + msg_size * Beta;
    }

//std::cout << "Total Estimates Timing: " << T << " (sec)" << std::endl;
    return T;
}


#endif //NODEAWAREMODEL_H
