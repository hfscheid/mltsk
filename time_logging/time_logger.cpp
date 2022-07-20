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

void assert_last_interval_is_closed(std::list<time_interval>* l) {
    if ((l->size() > 0) && (l->back().is_open())) {
        throw "last interval has not been closed.";
    }
}

std::list<time_interval> 
    time_logger::get_time_from_file(std::string file_name) {

    std::string time_as_string;
    std::ifstream time_file(file_name);
    std::list<time_interval> t_i_list = {};
    time_interval* t_i;
    struct std::tm tm;
    std::time_t raw_time;
    char time_direction;

    while(getline(time_file, time_as_string)){
        time_direction = time_as_string[0];
        std::stringstream time_as_stringstream(
            time_as_string.erase(0,1));
        time_as_stringstream >> std::get_time(
            &tm, "%a %b %d %H:%M:%S %Y\n");
        tm.tm_isdst = 0;
        raw_time = mktime(&tm);
        if (time_direction == '>') {
            try {
                assert_last_interval_is_closed(&t_i_list);
                t_i = new time_interval(raw_time);
                t_i_list.push_back(*t_i);
            }
            catch (const char* e) {
                std::cerr << "Could not parse " << file_name << ": " << e << std::endl;
                time_file.close();
                exit(0);
            }
        }
        else if (time_direction == '<') {
            t_i_list.back().close_interval(raw_time);
        }
        else {
            std::cout << time_direction + time_as_string + "does not follow the .mltsk format";
        }
    }
    time_file.close();
    return t_i_list;
}


void time_logger::write_time_to_file(
    std::time_t time, std::string file_name, std::string how) {

    std::ofstream time_file(file_name, std::ios::app);
//  iterate over the file. If there are already open intervals,
//  an error will be thrown
    std::list<time_interval> t_i_list = get_time_from_file(file_name);
    try {
        assert_last_interval_is_closed(&t_i_list);

        std::string time_as_string = ctime(&time);
        if (how == "close") {
            time_file << "<" << time_as_string;
        }
        if (how == "open") {
            time_file << ">" << time_as_string;
        }
    }
    catch (const char* e) {
        std::cerr << "Could not parse " << file_name << ": " << e << std::endl;
        time_file.close();
        exit(0);
    }
    time_file.close();
}
