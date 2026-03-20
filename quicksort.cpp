#include "quicksort.hpp"
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

