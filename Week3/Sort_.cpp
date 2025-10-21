#include<iostream>
#include<vector>
using namespace std;

//-------------INSERTION SORT----------------
void insertionSort(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
}
//-----------SELECTION SORT----------------
void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		int index_min = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[index_min]) {
				index_min = j;
			}
		}
		if (index_min != i) {
			swap(v[index_min], v[i]);
		}
	}
}
//-----------BUBBLE SORT-----------------
void bubbleSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size()-1; j++) {
			if (v[j + 1] < v[j])swap(v[j], v[j + 1]);
		}
	}
}
//----------MERGE SORT-------------------
// Ham tron hai mang con da duoc sap xep
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tao mang tam
    vector<int> L(n1), R(n2);

    // Sao chep du lieu vao 2 mang tam
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Tron hai mang tam vao mang arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chep cac phan tu con lai (neu co)
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// Ham de quy Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tranh tran so

        // Goi de quy chia doi mang
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Tron 2 nua da sap xep
        merge(arr, left, mid, right);
    }
}
//------------QUICK SORT-----------------------
// Ham chia mang (partition)
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];  // Chon pivot o dau mang
    int i = left + 1;       // i la vi tri tim phan tu lon hon pivot
    int j = right;          // j la vi tri tim phan tu nho hon pivot

    while (true) {
        // Di chuyen i sang phai den khi gap phan tu lon hon pivot
        while (i <= j && arr[i] <= pivot) i++;
        // Di chuyen j sang trai den khi gap phan tu nho hon pivot
        while (i <= j && arr[j] > pivot) j--;

        if (i >= j) break;  // Khi 2 chi so da cat nhau -> dung

        swap(arr[i], arr[j]);  // Doi cho 2 phan tu sai vi tri
    }

    // Dua pivot ve dung vi tri (j)
    swap(arr[left], arr[j]);
    return j; // Tra ve vi tri moi cua pivot
}

// Ham de quy Quick Sort
void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right); // Phan chia
        quickSort(arr, left, pivotIndex - 1);  // Sap xep ben trai
        quickSort(arr, pivotIndex + 1, right); // Sap xep ben phai
    }
}
