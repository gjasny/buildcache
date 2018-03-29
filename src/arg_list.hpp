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

#ifndef BUILDCACHE_ARG_LIST_HPP_
#define BUILDCACHE_ARG_LIST_HPP_

#include <string>
#include <vector>

namespace bcache {
class arg_list_t {
public:
  arg_list_t(const int argc, const char** argv) {
    for (int i = 0; i < argc; ++i) {
      m_args.emplace_back(std::string(argv[i]));
    }
  }

  std::string join(const std::string& separator) const {
    std::string result;
    for (auto arg : m_args) {
      if (result.empty()) {
        result = result + arg;
      } else {
        result = result + separator + arg;
      }
    }
    return result;
  }

  std::string& operator[](const size_t idx) {
    return m_args[idx];
  }

  const std::string& operator[](const size_t idx) const {
    return m_args[idx];
  }

private:
  std::vector<std::string> m_args;
};
}  // namespace bcache

#endif  // BUILDCACHE_ARG_LIST_HPP_
