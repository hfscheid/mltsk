#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <list>
#include "time_logger.hpp"
#include "time_interval.hpp"

//struct simple_time {
//    int seconds;
//    int minutes;
//    int hours;
//};

std::string get_filename(std::string suffix) {
    std::string file_dir = getenv("HOME");
    std::string file_name = file_dir + "/.mltsk/time_in_" + suffix;
    return file_name;
}

void print_simple_time(struct simple_time s_t) {
    std::cout << "Time on task since last time-in:\n\n";
    std::cout << s_t.hours << ":"
              << s_t.minutes << ":"
              << s_t.seconds << std::endl << std::endl;
}

//struct simple_time break_seconds(double diff_seconds) {
//    struct simple_time s_t;
//    int seconds = int(diff_seconds);
//    int minutes = seconds/60;
//    int hours = minutes/60;
//    s_t.seconds = seconds%60;
//    s_t.minutes = minutes%60;
//    s_t.hours = hours;
//    return s_t;
//}
//
//void display_diff(double diff_seconds) {
//    print(break_seconds(diff_seconds));
//}

int main(int argc, char** argv) {
    std::string time_log_file;
    if (argc > 1) {
        time_log_file = get_filename(std::string(argv[1]));
    } else {
        time_log_file = get_filename("default");
    }

//    std::time_t then_raw_time = 
//        time_logger::get_time_from_file(time_log_file);
//    std::time_t now_raw_time = time(NULL);
    std::list<time_interval> time_list = time_logger::
            get_time_from_file(time_log_file);
    time_interval last_interval = time_list.back();
    if (last_interval.is_open()) {
        print_simple_time(last_interval.get_interval());
    }
    else {
        std::cout << "There are no open intervals. "
                  << "To start an interval, run command 'tmin'\n";
    }

    return 0;
}
