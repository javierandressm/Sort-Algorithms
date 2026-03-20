#include "sorting.hpp"
#include <stack>

int partitionQS(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<string>& arr, int low, int high) {
    stack<pair<int, int>> st;
    st.push({low, high});

    while (!st.empty()) {
        int l = st.top().first;
        int h = st.top().second;
        st.pop();

        if (l < h) {
            int pi = partitionQS(arr, l, h);
            st.push({l, pi - 1});
            st.push({pi + 1, h});
        }
    }
}

void heapify(vector<string>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<string>& arr) {
    int n = (int)arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

