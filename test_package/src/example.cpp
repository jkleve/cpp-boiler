#include "lite_logger.h"

int main()
{
    auto log = lite::log::console_logger("root");
    log.error("Test");
    log.warn("Test");
    log.info("Test");
    log.debug("Test");
    log.trace("Test");

    return 0;
}
