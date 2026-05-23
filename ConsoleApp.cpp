#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <Windows.h>

using namespace std;

struct Object {
    string name;
    vector<double> features;
};

double euclideanDistance(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    vector<Object> dataset = {
        {"Яблуко", {150, 7, 1}},   
        {"Банан",  {120, 15, 2}},
        {"Апельсин",{200, 8, 3}}
    };

    vector<double> input = { 140, 6, 1 };

    double minDist = 1e9;
    string result;

    for (auto& obj : dataset) {
        double dist = euclideanDistance(input, obj.features);
        cout << "Відстань до " << obj.name << ": " << dist << endl;

        if (dist < minDist) {
            minDist = dist;
            result = obj.name;
        }
    }

    cout << "\nРезультат: це найбільш схоже на -> " << result << endl;

    return 0;
}