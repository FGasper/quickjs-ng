#if defined(__APPLE__)
#include <malloc/malloc.h>
#elif defined(__linux__) || defined(__CYGWIN__)
#include <malloc.h>
#elif defined(__FreeBSD__)
#include <malloc_np.h>
#endif
