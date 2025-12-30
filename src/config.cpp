#include "kv/config.hpp"

namespace kv {

Result<Config> load_config(const std::string& path) {
	(void)path; // explicitly unused for now
	return tl::unexpected(make_error(Code::InvalidArgument, "Must provide a valid path"));
}

} // namespace kv
