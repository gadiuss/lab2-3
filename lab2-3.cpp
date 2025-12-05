#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;


void inputData(float* p, int n){
    cout << "Введите значения: ";
    for (int i = 0; i < n; i++){
        while (true){
        cin >> *(p + i);
        if (cin.fail() or *(p + i) < -50 or *(p + i) > 50){
            cout << "Ошибка! Введите число от -50 до 50" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{
            break;
        }
        }
    }
}

float average(const float* p, int n){
    float sums = 0;
    float avg = 0;
    for (int i = 0; i <n; i++){
        sums += *(p + i);
    }
    avg = sums/n;
    return avg;
}

float minValue(const float* p, int n){
    float mins = *p;
    for (int i =1; i < n; i++){
        if (*(p + i) < mins){
            mins = *(p + i);
        } 
    }
    return mins;
}

float maxValue(const float* p, int n){
    float maxs = *p;
    for (int i =1; i < n; i++){
        if (*(p + i) > maxs){
            maxs = *(p + i);
        } 
    }
    return maxs;
}

float* filterAboveAverage(float* p, int n, int& newCount){
    float avg = average(p, n);
    float* temp = new float[n];
    newCount = 0;
    
    for (int i = 0; i < n; i++){
        if (*(p + i) > avg) {
            *(temp + newCount) = *(p + i);
            newCount++;
        }
    }
    
    float* ans = new float[newCount];
    for (int i = 0; i < newCount; i++){
        *(ans + i) = *(temp + i);
    }
    
    delete[] temp; 
    return ans;
}


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Анализ сенсора ===" << endl;
    int n;
    while (true){
        cout << "Введите количество измерений: ";
        cin >> n;
        if (cin.fail() or n < 1 ){
            cout << "Ошибка! Введите целое число > 0" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (cin.peek() != '\n'){
            cout << "Ошибка! Введите целое число!!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
    }
        else{
            break;
        }
    }
    

    float* data = new float[n];
    inputData(data, n);
    int newCount = 0;
    float* abvAvg = filterAboveAverage(data, n, newCount);

    float avg = average(data, n);
    float mns = minValue(data, n);
    float mxs = maxValue(data, n);

    cout << fixed << setprecision(2);
    cout << "Среднее значение: " << avg << endl;
    cout << "Минимум: " << mns << endl;
    cout << "Максимум: " << mxs << endl;
    cout << "Значения выше среднего:" << endl;
    for (int i = 0; i < newCount; i++) {
        cout << *(abvAvg + i) << " ";
    }


    delete[] data;
    delete[] abvAvg;
    return 0;
}
