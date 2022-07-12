#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string get_filename() {
    std::string file_dir = getenv("HOME");
    std::string file_name = file_dir + "/.time_in";
    return file_name;
}


std::time_t get_time_then(std::string file_name) {
    std::string time_then;
    std::ifstream time_file(file_name);
    getline(time_file, time_then);
    time_file.close();
    std::stringstream time_then_stream(time_then);

    struct std::tm tm;
    time_then_stream >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y\n");
    tm.tm_isdst = 0;
    std::time_t then_raw_time = mktime(&tm);
    return then_raw_time;
}

void display_diff(double diff_seconds) {
    int seconds = int(diff_seconds);
    int minutes = seconds/60;
    int hours = minutes/60;
    std::cout << int(hours) << ":"
              << int(minutes%60) << ":"
              << int(seconds%60) << std::endl;
}

int main() {
    std::string file_name = get_filename();
    std::time_t then_raw_time = get_time_then(file_name);
    std::time_t now_raw_time = time(NULL);
    double diff_seconds = difftime(now_raw_time, then_raw_time);
    display_diff(diff_seconds);
    return 0;
}
