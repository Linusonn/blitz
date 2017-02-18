#include "utils/blitz_cpu_function.h"

#ifdef USE_MKL
#include <mkl.h>
#else

#ifdef __cplusplus
  extern "C" {
#endif
    #include <cblas.h>
#ifdef __cplusplus
  }
#endif
#endif

namespace blitz {

template<>
void BlitzCPUCopy<float>(const float* X, float* Y, size_t N) {
  cblas_scopy(N, X, 1, Y, 1);
}

template<>
void BlitzCPUCopy<double>(const double* X, double* Y, size_t N) {
  cblas_dcopy(N, X, 1, Y, 1);
}

}  // namespace blitz

