#if defined(__APPLE__)
#include <malloc/malloc.h>
#elif defined(__linux__) || defined(__CYGWIN__)
#include <malloc.h>
#elif defined(__FreeBSD__)
#include <malloc_np.h>
#endif

static inline size_t js_malloc_usable_size_unknown(const void *ptr)
{
    return 0;
}

/* default memory allocation functions with memory limitation */
static inline size_t js_def_malloc_usable_size(void *ptr)
{
#if defined(__APPLE__)
    return malloc_size(ptr);
#elif defined(_WIN32)
    return _msize(ptr);
#elif defined(EMSCRIPTEN) || defined(__OpenBSD__)
    return js_malloc_usable_size_unknown(ptr);
#elif defined(__linux__)
    return malloc_usable_size(ptr);
#else
    /* change this to `return 0;` if compilation fails */
    return malloc_usable_size(ptr);
#endif
}
