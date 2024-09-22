#include <iostream>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // constructor to initialize the time to 0:0:0
    Time() : hour(0), minute(0), second(0) {}

    // function to return the hour value
    int hours() const {
        return hour;
    }

    // function to return the minute value
    int minutes() const {
        return minute;
    }

    // function to return the second value
    int seconds() const {
        return second;
    }

    // function to reset the time to given hour, minute, and second
    void reset(int h, int m, int s) {
        if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60) {
            std::cout << "Invalid time values." << std::endl;
            return;
        }
        hour = h % 24; // reset hour to 0 when it reaches 24
        minute = m % 60;
        second = s % 60;
    }

    // function to advance the current time by h hours, m minutes, and s seconds
    void advance(int h, int m, int s) {
        if (h < 0 || m < 0 || s < 0) {
            std::cout << "Invalid time increment values." << std::endl;
            return;
        }

        second += s;
        minute += m + second / 60; // add overflow from seconds to minutes
        hour += h + minute / 60;    // add overflow from minutes to hours

        // normalize the time values
        second %= 60;
        minute %= 60;
        hour %= 24; // reset hour to 0 when it reaches 24
    }

    // function to print the current time stored
    void print() const {
        std::cout << "Current time: "
                  << (hour < 10 ? "0" : "") << hour << ":"
                  << (minute < 10 ? "0" : "") << minute << ":"
                  << (second < 10 ? "0" : "") << second << std::endl;
    }
};

int main() {
    Time myTime;

    // reset the time to 13:45:30
    myTime.reset(13, 45, 30);
    myTime.print(); // output: Current time: 13:45:30

    // advance the time by 2 hours, 30 minutes, and 40 seconds
    myTime.advance(2, 30, 40);
    myTime.print(); // output: Current time: 16:16:10

    // advance the time by 8 hours, 50 minutes, and 50 seconds
    myTime.advance(8, 50, 50);
    myTime.print(); // output: Current time: 01:07:00 (next day)

    // attempting to reset with invalid values
    myTime.reset(24, 61, 61); // invalid values

    return 0;
}
