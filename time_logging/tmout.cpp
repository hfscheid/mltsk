#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "time_logger.hpp"

std::string get_filename(std::string suffix) {
    std::string file_dir = getenv("HOME");
    std::string file_name = file_dir + "/.mltsk/time_in_" + suffix;
    return file_name;
}

int main(int argc, char** argv) {
    std::string time_log_file;
    if (argc > 1) {
        time_log_file = get_filename(std::string(argv[1]));
    } else {
        time_log_file = get_filename("default");
    }

    std::time_t rawtime = time(NULL);
    time_logger::write_time_to_file(rawtime, time_log_file, "close");

    std::cout << "Timed out at " << ctime(&rawtime) << std::endl;
    return 0;
}
