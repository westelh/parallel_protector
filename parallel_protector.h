#ifndef INCLUDED_PARALLEL_PROTECTOR_H
#define INCLUDED_PARALLEL_PROTECTOR_H

#include <mutex>

namespace elh {
    template <class T>
    class parallel_protected {
            T t;
            std::recursive_mutex mutex;
        public:
            T& access() noexcept {
                std::lock_guard<std::recursive_mutex>{mutex};
                return t;
            }
    };
}

#endif /* end of include guard:INCLUDED_PARALLEL_PROTECTOR_H */
