// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#ifndef RAPTOR_SPARSE_HPP
#define RAPTOR_SPARSE_HPP

// Define types such as int and double sizes
#include "core/types.hpp"
#include "core/utilities.hpp"

// Data about topology and matrix partitions
#ifndef NO_MPI
    #include "core/mpi_types.hpp"
    #include "core/partition.hpp"
    #include "core/topology.hpp"
#endif 

// Matrix and vector classes
#include "core/matrix.hpp"
#include "core/vector.hpp"
#ifndef NO_MPI
    #include "core/par_matrix.hpp"
    #include "core/par_vector.hpp"
#endif 

// Communication classes
#ifndef NO_MPI
    #include "core/comm_data.hpp"
    #include "core/comm_pkg.hpp"
#endif

// Stencil and diffusion classes
#include "gallery/laplacian27pt.hpp"
#include "gallery/diffusion.hpp"
#include "gallery/stencil.hpp"
#include "gallery/random.hpp"
#ifndef NO_MPI
    #include "gallery/par_stencil.hpp"
    #include "gallery/par_random.hpp"
#endif

// Matrix IO
#include "gallery/matrix_IO.hpp"
#include "gallery/matrix_market.hpp"
#ifndef NO_MPI
    #include "gallery/par_matrix_IO.hpp"
    #include "gallery/par_matrix_market.hpp"
#endif

// Repartitioning matrix methods
#ifndef NO_MPI
#include "util/linalg/repartition.hpp"
#endif
#ifdef USING_PTSCOTCH
    #include "util/linalg/external/ptscotch_wrapper.hpp"
#endif
#ifdef USING_PARMETIS
    #include "util/linalg/external/parmetis_wrapper.hpp"
#endif


#endif

