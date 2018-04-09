//--------------------------------------------------------------------------------------------------
// Copyright (c) 2018 Marcus Geelnard
//
// This software is provided 'as-is', without any express or implied warranty. In no event will the
// authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose, including commercial
// applications, and to alter it and redistribute it freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not claim that you wrote
//     the original software. If you use this software in a product, an acknowledgment in the
//     product documentation would be appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be misrepresented as
//     being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//--------------------------------------------------------------------------------------------------

#ifndef BUILDCACHE_DEBUG_UTILS_HPP_
#define BUILDCACHE_DEBUG_UTILS_HPP_

#include <sstream>
#include <string>

namespace bcache {
namespace debug {
enum log_level_t { DEBUG = 1, INFO = 2, ERROR = 3, FATAL = 4, NONE = 5 };

/// @brief A simple log stream object.
///
/// Usage:
/// @code
/// debug::log(debug::INFO) << "Hello world! The answer is: " << some_variable;
/// @endcode
class log {
public:
  /// @brief Log stream constructor.
  /// @param level The log level.
  log(const log_level_t level);

  /// @brief Log stream destructor.
  ///
  /// The log message is printed once the log stream object goes out of scope.
  ~log();

  template <typename T>
  log& operator<<(const T message) {
    m_stream << message;
    return *this;
  }

private:
  const log_level_t m_level;
  std::ostringstream m_stream;
};
}  // namespace debug
}  // namespace bcache

#endif  // BUILDCACHE_DEBUG_UTILS_HPP_
