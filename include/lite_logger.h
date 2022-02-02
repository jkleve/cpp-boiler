#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <string_view>

namespace lite {
namespace log {

enum class log_lvl {
    error,
    warn,
    info,
    debug,
    trace,
};

template<typename Impl>
class logger {
public:
  logger(std::string name, log_lvl lvl = log_lvl::info)
      : name(std::move(name))
      , impl(this->name) {}

  void error(std::string_view msg) {
    // Impl::error(msg); // possibly a ctx object too
    impl.error(msg);
  }

  void warn(std::string_view msg) {
    impl.warn(msg);
  }

  void info(std::string_view msg) {
    impl.info(msg);
  }

  void debug(std::string_view msg) {
    impl.debug(msg);
  }

  void trace(std::string_view msg) {
    impl.trace(msg);
  }

private:
  // struct Ctx {
  //   std::string name;
  // } ctx;

  std::string name;
  Impl impl;
};

class spdlog_console_logger {
public:
  spdlog_console_logger(const std::string& name)
    : log(spdlog::stdout_color_mt(name))
  {}

  void error(std::string_view msg) {
    log->error(msg);
  }

  void warn(std::string_view msg) {
    log->warn(msg);
  }

  void info(std::string_view msg) {
    log->info(msg);
  }

  void debug(std::string_view msg) {
    log->debug(msg);
  }

  void trace(std::string_view msg) {
    log->trace(msg);
  }
  
private:
  std::shared_ptr<spdlog::logger> log;
};

using console_logger = logger<spdlog_console_logger>;

// options:
//  1. inject implementation via template argument on class logger
//  2. inject implementation via logger ctor (spdlog injects "sinks" which are the implementation details)

} // namespace log
} // namespace lite