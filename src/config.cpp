#include "kv/result.hpp"
#include <tl/expected.hpp>

namespace kv {

Result<Config> load_config(const std::string& path) {
	Code code = Code::InvalidArgument;

	return tl::unexpected(make_error(code, "Must provide a valid path"));
} // namespace kv
