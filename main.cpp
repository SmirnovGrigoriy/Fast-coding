#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
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

int main() {
    std::string s = archive[p_random()], x;
    std::cout << s << ' ';
    std::vector<int> start_time = get_now_time();
    std::cin >> x;
    std::vector<int> finish_time = get_now_time();

    int count_mistakes = 0;

    if (start_time[2] > finish_time[2]) {
        finish_time[2] += 60;
        --finish_time[1];
    }
    if (start_time[1] > finish_time[1]) {
        finish_time[1] += 60;
        --finish_time[0];
    }
    if (start_time[0] > finish_time[0]) {
        finish_time[0] += 24;
    }

    std::cout << "Your time - ";
    std::cout << std::setw(2) << finish_time[0] - start_time[0] << ' ' << finish_time[1] - start_time[1] << ' ' << finish_time[2] - start_time[2] << '\n';
    
    if (x.size() < s.size()) {
        count_mistakes += s.size() - x.size();
        for (int i = 0; i < x.size(); ++i) {
            if (s[i] != x[i]) ++count_mistakes;
        }
    }
    else if (x.size() > s.size()) {
        count_mistakes += x.size() - s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != x[i]) ++count_mistakes;
        }
    }
    else {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != x[i]) ++count_mistakes;
        }
    }
    std::cout << "Mistakes - " << count_mistakes;
}
