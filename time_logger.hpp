#ifndef TIME_LOGGER
#define TIME_LOGGER
// Responsible for managing time logs.
// Reads/writes time from files, allowing for
// work with time_t objects regardless of the data source
class time_logger {
    public:
    static std::time_t get_time_from_file(std::string file_name);
    static void write_time_to_file(std::time_t time, std::string file_name);
};

#endif
