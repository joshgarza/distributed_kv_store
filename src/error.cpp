#include "kv/error.hpp"

namespace kv {

Error make_error(Code code, std::string message) {
	return new Error{code, std::move message};
}

} // namespace kv
