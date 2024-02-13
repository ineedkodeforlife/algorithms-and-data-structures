#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Начинаем с большого шага, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Делаем сортировку вставками с шагом gap
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Если элемент в середине массива равен целевому значению, возвращаем индекс
        if (arr[mid] == target)
            return mid;

        // Если целевое значение меньше, чем элемент в середине, ищем в левой половине
        if (arr[mid] > target)
            right = mid - 1;
        // Иначе ищем в правой половине
        else
            left = mid + 1;
    }

    // Если элемент не найден, возвращаем -1
    return -1;
}


int main() {
    int n1 = 1000, n2 = 4000, n3 = 6000;
    int s1 = 3000, s2 = 12000, s3 = 18000;


    vector<int> arr1(n1), arr2(n2), arr3(n3), arrs1(s1), arrs2(s2), arrs3(s3);
    srand(time(nullptr));
    for (int i = 0; i < n1; ++i) {
        arr1[i] = rand() % 10000;
    }
    for (int i = 0; i < n2; ++i) {
        arr2[i] = rand() % 10000;
    }
    for (int i = 0; i < n3; ++i) {
        arr3[i] = rand() % 10000;
    }
    for (int i = 0; i < s1; ++i) {
        arrs1[i] = rand() % 10000;
    }
    for (int i = 0; i < s2; ++i) {
        arrs2[i] = rand() % 10000;
    }
    for (int i = 0; i < s3; ++i) {
        arrs3[i] = rand() % 10000;
    }



    auto start = high_resolution_clock::now();
    insertionSort(arr1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_insert array 1 (size " << n1 << "): " << duration.count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    insertionSort(arr2);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_insert array 2 (size " << n2 << "): " << duration.count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    insertionSort(arr3);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_insert array 3 size " << n3 << "): " << duration.count() << " milliseconds" << endl;

//-------------------------------------------------------------------------------------------------------------------------------------//

    start = high_resolution_clock::now();
    shellSort(arrs1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_shell array 1 (size " << s1 << "): " << duration.count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    shellSort(arrs2);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_shell array 2 (size " << s2 << "): " << duration.count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    shellSort(arrs3);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort_shell array 3 size " << s3 << "): " << duration.count() << " milliseconds" << endl;
    // ---------------------------------------------------------------------------------------------------------------2//
    vector<int> arr_bin_search = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int target = 11;

    int result = binarySearch(arr_bin_search, target);

    if (result != -1)
        cout << "Arg " << target << " find in pos " << result << endl;
    else
        cout << "Arg " << target << " not found" << endl;
    
    return 0;
}
