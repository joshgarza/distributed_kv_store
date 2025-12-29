#pragma once

#include "kv/error.hpp"
#include <tl/expected.hpp>

namespace kv {

template <typename T>
using Result = tl::expected<T, Error>;

} // namespace kv
