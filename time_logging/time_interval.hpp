#ifndef TIME_INTERVAL
#define TIME_INTERVAL

struct simple_time {
    long int seconds = 0;
    long int minutes = 0;
    long int hours = 0;
    simple_time operator+(const simple_time&);
};

class time_interval {
    public:
    time_interval(std::time_t begin);
    struct simple_time get_interval();
    void close_interval(std::time_t end);
    bool is_open();

    private:
    std::time_t* begin;
    std::time_t* end;
    bool open;
};

#endif
