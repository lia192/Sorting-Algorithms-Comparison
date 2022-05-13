#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

//random string generator
string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}
 
template<typename T>
void bubbleSort(vector<T> arr, int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

template<typename T>
void insertionSort(vector<T> arr, int n){
    T key; int j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
void selectionSort(vector<T> arr, int n){
    int min_idx;
    for (int i = 0; i < n - 1; ++i){
        min_idx = i;
        for(int j = i+1; j < n; ++j)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

template<typename T>
void quickSort(vector<T> &arr, int start, int end){
 
    if (start >= end)return;
    
    T pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot)i++;
        while (arr[j] > pivot)j--;
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    int p = pivotIndex;
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

template<typename T>
void mergeSort(vector<T> &arr, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int start = m + 1, mid = m, end = r;
        int start2 = mid + 1;
        if (arr[mid] <= arr[start2])return;
        while (start <= mid && start2 <= end) {
            if(arr[start] <= arr[start2])start++;
            else {
                T value = arr[start2];
                int index = start2;
                while (index != start){
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[start] = value;
                start++;
                mid++;
                start2++;
            }
        }
    }
}

int mx = 1e6, mod = 100;
vector<int> cur, arr;
vector<char> ccur, carr;
vector<string> scur, sarr;
char letters[] = "abcdefghijklmnopqrstuvwxyz";

int main(){

    cout << setprecision(5) << fixed;

    cout << "For integer values : \n";
    for(int N = 10; N <= 1e7; N *= 10){

        cout << "N = " << N << '\n';
        
        arr.clear();
        int batch_size = max(1, mx/N);

        for(int i = N; i > 0; --i){
            //arr.push_back(rand() % mod);
            arr.push_back(i);
        }

        if(N <= 10e3){
            auto start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                bubbleSort(arr, N);
            auto stop = high_resolution_clock::now();
            auto duration = (duration_cast<microseconds>(stop - start));
        
            cout << "BubbleSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << '\n';
            
            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                insertionSort(arr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "InsertionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;

            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                selectionSort(arr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "SelectionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;
        }

        cur.clear();
        for(auto it: arr)cur.push_back(it);

        auto start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            quickSort(cur, 0, N - 1);
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<microseconds>(stop - start));
        
        cout << "QuickSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;

        cur.clear();
        for(auto it: arr)cur.push_back(it);
        start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            mergeSort(cur, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = (duration_cast<microseconds>(stop - start));
        
        cout << "MergeSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;
    }

    return 0;

    cout << "For char values : \n";
    for(int N = 10; N <= 1e6; N *= 10){

        cout << "N = " << N << '\n';
        
        carr.clear();
        int batch_size = max(1, mx/N);

        for(int i = N; i > 0; --i){
            //carr.push_back(letters[rand() % 26]);
            carr.push_back('0' + i);
        }

        if(N <= 1e3){
            auto start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                bubbleSort(carr, N);
            auto stop = high_resolution_clock::now();
            auto duration = (duration_cast<microseconds>(stop - start));
        
            cout << "BubbleSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << '\n';
            
            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                insertionSort(carr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "InsertionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;

            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                selectionSort(carr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "SelectionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;
        }

        ccur.clear();
        for(auto it: carr)ccur.push_back(it);

        auto start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            quickSort(ccur, 0, N - 1);
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<microseconds>(stop - start));
        
        cout << "QuickSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;

        ccur.clear();
        for(auto it: carr)ccur.push_back(it);
        start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            mergeSort(ccur, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = (duration_cast<microseconds>(stop - start));
        
        cout << "MergeSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;
    }

    return 0;
    
    cout << "For string values : \n";
    for(int N = 10; N <= 1e5; N *= 10){

        cout << "N = " << N << '\n';
        
        sarr.clear();
        int batch_size = max(1, mx/N);

        for(int i = N; i > 0; --i){
            //sarr.push_back(gen_random(rand()%mod + 1));
            sarr.push_back(to_string(i));
        }

        if(N <= 1e3){
            auto start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                bubbleSort(sarr, N);
            auto stop = high_resolution_clock::now();
            auto duration = (duration_cast<microseconds>(stop - start));
        
            cout << "BubbleSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << '\n';
            
            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                insertionSort(sarr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "InsertionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;

            start = high_resolution_clock::now();
            for(int i = 0; i < batch_size; ++i)
                selectionSort(sarr, N);
            stop = high_resolution_clock::now();
            duration = (duration_cast<microseconds>(stop - start));
        
            cout << "SelectionSort: "
                << 1.00*duration.count()/batch_size << " microseconds" << endl;
        }

        scur.clear();
        for(auto it: sarr)scur.push_back(it);

        auto start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            quickSort(scur, 0, N - 1);
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<microseconds>(stop - start));
        
        cout << "QuickSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;

        scur.clear();
        for(auto it: sarr)scur.push_back(it);
        start = high_resolution_clock::now();
        for(int i = 0; i < batch_size; ++i)
            mergeSort(scur, 0, N - 1);
        stop = high_resolution_clock::now();
        duration = (duration_cast<microseconds>(stop - start));
        
        cout << "MergeSort: "
            << 1.00*duration.count()/batch_size << " microseconds" << endl;
    }
    
    return 0;
}
