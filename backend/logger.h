#include <spdlog/spdlog.h>

class logger {
    private:
        static logger* logger_;

        logger();

    public:
        static logger* get_instance();
};