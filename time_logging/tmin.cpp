#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "time_logger.hpp"

int main() {
    std::string file_dir = getenv("HOME");
    std::string file_name = file_dir + "/.time_in";

    std::time_t rawtime = time(NULL);
    time_logger::write_time_to_file(rawtime, file_name);

    std::cout << "Timed in at " << ctime(&rawtime) << std::endl;
    return 0;
}
