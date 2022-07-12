#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main() {
    std::string file_dir = getenv("HOME");
    std::string file_name = file_dir + "/.time_in";

    std::time_t rawtime = time(NULL);
    std::string time_now = ctime(&rawtime);

    std::ofstream time_file(file_name);
    time_file << time_now;
    time_file.close();
    std::cout << "Timed in at " << time_now << std::endl;
    return 0;
}
