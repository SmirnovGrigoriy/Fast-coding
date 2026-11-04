#include <ctime>
#include <string>
#include <vector>
#include <random>

int p_random() {
    std::random_device x;
    std::mt19937 y(x());
    std::uniform_int_distribution<> z(0, 149);
    return z(y);
}

std::vector<int> get_now_time() {
    std::vector<int> a(3);
    std::time_t x = std::time(nullptr);
    std::tm* y = std::localtime(&x);

    a[0] = y->tm_hour;
    a[1] = y->tm_min;
    a[2] = y->tm_sec;
    return a;
}