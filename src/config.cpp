#include "kv/config.hpp"
#include <tl/expected.hpp>

namespace kv {

Result<Config> load_config(const std::string& path) {
	return tl::unexpected(make_error(InvalidArgument, "Must provide a valid path"));
} // namespace kv
