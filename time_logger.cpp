#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include "time_logger.hpp"

std::time_t time_logger::get_time_from_file(std::string file_name) {
    std::string time_as_string;
    std::ifstream time_file(file_name);
    getline(time_file, time_as_string);
    time_file.close();
    std::stringstream time_as_stringstream(time_as_string);

    struct std::tm tm;
    time_as_stringstream >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y\n");
    tm.tm_isdst = 0;
    std::time_t raw_time = mktime(&tm);
    return raw_time;
}


void time_logger::write_time_to_file(std::time_t time, std::string file_name) {
    std::ofstream time_file(file_name);
    std::string time_as_string = ctime(&time);
    time_file << time_as_string;
    time_file.close();
}
