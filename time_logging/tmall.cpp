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

simple_time get_time_sum(std::list<time_interval>* time_list) {
    std::list<time_interval>::iterator it;
    simple_time sum;
    for (it = time_list->begin(); it != time_list->end(); ++it) {
        sum = sum + it->get_interval();
    }
    return sum;
}

int main(int argc, char** argv) {
    std::string time_log_file;
    if (argc > 1) {
        time_log_file = get_filename(std::string(argv[1]));
    } else {
        time_log_file = get_filename("default");
    }

    std::list<time_interval> time_list = time_logger::
            get_time_from_file(time_log_file);
    simple_time time_sum = get_time_sum(&time_list);
    print_simple_time(time_sum);
    return 0;
}
