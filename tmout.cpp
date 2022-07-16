#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <unistd.h>

struct simple_time {
    int seconds;
    int minutes;
    int hours;
};

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

void print(struct simple_time s_t) {
    std::cout << s_t.hours << ":"
              << s_t.minutes << ":"
              << s_t.seconds << std::endl;
}

struct simple_time break_seconds(double diff_seconds) {
    struct simple_time s_t;
    int seconds = int(diff_seconds);
    int minutes = seconds/60;
    int hours = minutes/60;
    s_t.seconds = seconds%60;
    s_t.minutes = minutes%60;
    s_t.hours = hours;
    return s_t;
}

void display_diff(double diff_seconds) {
    print(break_seconds(diff_seconds));
}

void display_diff_continuous(double diff_seconds) {
    struct simple_time s_t = break_seconds(diff_seconds);
    while (true) {
        print(s_t);
        ++s_t.seconds;
        sleep(1);
    }
}

int main(int argc, char** argv) {
    std::string file_name = get_filename();
    std::time_t then_raw_time = get_time_then(file_name);
    std::time_t now_raw_time = time(NULL);
    double diff_seconds = difftime(now_raw_time, then_raw_time);


    if (argc > 1) {
        if (std::string(argv[1]) == "-c") {
            display_diff_continuous(diff_seconds);
        }
    }
    else {
        display_diff(diff_seconds);
    }
    return 0;
}
