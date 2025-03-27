//Algoritma dan Struktur Data
//Group 2 : Exponential Search
//Teknik Informatika B

#include <stdio.h>

// Fungsi Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fungsi Eksponensial Search
int exponentialSearch(int arr[], int n, int target) {
    // Jika elemen pertama adalah elemen yang dicari
    if (arr[0] == target)
        return 0;

    // Menentukan rentang dengan kelipatan dua
    int i = 1;
    while (i < n && arr[i] <= target) {
        if (arr[i] == target)
            return i;
        i = i * 2;
    }

    // Melakukan binary search pada rentang yang ditemukan
    int left = i / 2;
    int right = (i < n) ? i : n - 1;
    return binarySearch(arr, left, right, target);
}

int main() {
    // Array terurut sesuai dengan contoh
    int arr[] = {2, 6, 11, 19, 24, 33, 42, 54, 67, 81, 94, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    // Cetak elemen array
    printf("Elemen dalam array adalah: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input elemen yang ingin dicari dari user
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &target);

    // Melakukan pencarian dengan eksponensial search
    int result = exponentialSearch(arr, n, target);
    if (result != -1) {
        printf("Elemen %d ditemukan pada indeks ke-%d\n", target, result);
    } else {
        printf("Elemen %d tidak ditemukan dalam array\n", target);
    }

    return 0;
}
