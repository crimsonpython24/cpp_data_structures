#include <iostream>
using namespace std;

struct arrstc {
    int *A;
    int size;
    int length;
};

void readin(arrstc &arr, int &n) {
    cout << "Enter size of the array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    cout << "Enter number of numbers: ";
    cin >> n;
    cout << "Enter all elements:" << endl;
    for (int i=0; i<n; ++i)
        cin >> arr.A[i];
    arr.length = n;
}

void display(arrstc arr) {
    cout << "The elements are:" << endl;
    for (int i=0; i<arr.length; ++i)
        cout << arr.A[i] << " ";
    cout << endl;
}

// TODO debug
void append(arrstc *arr, int x) {
    if (arr->length < arr->size) 
        arr->A[arr->length++] = x;
}

void insert(arrstc *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        ++arr->length;
    }
}

int remove(arrstc *arr, int index) {
    int x = 0;
    if (index >= 0 && index <= arr->length) {
        x = arr -> A[index];
        for (int i=index; i<arr->length-1; ++i)
            arr->A[i] = arr->A[i+1];
        --arr->length;
        return x;
    }
    return 0;
}

void swap(int *x, int *y) {
    int temp; temp = *x;
    *x = *y; *y = temp;
}

int linearSearch(arrstc arr, int key) {
    for (int i=0; i<arr.length; ++i) {
        if (key == arr.A[i]) 
            return i;
    }
    return -1;
}

int moveFront(arrstc *arr, int key) {
    for (int i=0; i<arr->length; ++i) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int binarySearch(arrstc arr, int key) {
    int l = 0, mid, h = arr.length-1;
    while (l <= h) {
        mid = (l + h)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int recurBinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l + h)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return recurBinarySearch(a, l, mid-1, key);
        else
            return recurBinarySearch(a, mid+1, h, key);
    }
}

int get(arrstc arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void set(arrstc *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int max(arrstc arr) {
    int max = arr.A[0];
    for (int i=0; i<arr.length; ++i)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

int min(arrstc arr) {
    int min = arr.A[0];
    for (int i=0; i<arr.length; ++i)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

int sum(arrstc arr) {
    int sum = 0;
    for (int i=0; i<arr.length; ++i)
        sum += arr.A[i];
    return sum;
}

float avg(arrstc arr) {
    int sum = 0;
    for (int i=0; i<arr.length; ++i)
        sum += arr.A[i];
    return (float)sum/arr.length;
}

void reverse(arrstc *arr) {
    int *B;
    B = new int[arr->length];
    for (int i=arr->length-1; i>=0; --i)
        B[arr->length-i-1] = arr->A[i];
    cout << endl;
    for (int i=0; i<arr->length; ++i) 
        arr->A[i] = B[i];
}

void insertSort(arrstc *arr, int x) {
    int i=arr->length-1;
    if (arr->length==arr->size)
        return;
    while (i >= 0 && arr->A[i]>x) {
        arr->A[i+1] = arr->A[i];
        --i;
    }
    arr->A[i+1] = x;
    ++arr->length;
}

bool isSorted(arrstc arr) {
    for (int i=0; i<arr.length-1; ++i)
        if (arr.A[i] > arr.A[i+1])
            return false;
    return true;
}

// TODO infinite loop
void rearrange(arrstc *arr) {
    int i, j;
    i = 0;
    j = arr->length-1;
    while (i < j) {
        while (arr->A[i] < 0) 
            i++;
        while (arr->A[i] >= 0) 
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main() {
    arrstc arr;
    int n;

    readin(arr, n); 
    // append(&arr, 10);
    //insertSort(&arr, 10);
    rearrange(&arr);
    display(arr);

    return 0;
}
