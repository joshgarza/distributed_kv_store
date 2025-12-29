#include <string>

namespace kv {

enum class Code {
	InvalidArgument,
	Io,
	NotFound,
	Corruption,
	Timeout
};


class Error {
        public:
                Code code;
                std::string message;

};

Error make_error(Code code, std::string message);

}
