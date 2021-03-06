#ifndef TIME_LOGGER
#define TIME_LOGGER
// Responsible for managing time logs.
// Reads/writes time from files, allowing for
// work with time_t objects regardless of the data source
#include <list>
class time_interval;
class time_logger {
    public:
    // 'how' parameter may be "open" or "close"
    static std::list<time_interval> get_time_from_file(std::string file_name);
    static void write_time_to_file(std::time_t time,
                                   std::string file_name,
                                   std::string how);
    private:
    static std::list<time_interval> build_list(std::string file_name);
};

#endif
