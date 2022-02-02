#include "lite_logger.h"

int main()
{
    auto log = lite::log::console_logger("root");
    log.info("Hello, world!");

    return 0;
}
