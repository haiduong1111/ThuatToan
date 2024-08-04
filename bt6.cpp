#include <iostream>
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
using ll = long long;

void printArr(int a[], int n){
	for(int i=0;i< n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void selectionSort(int a[], int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(a[j] < a[min]) min = j;
		}
		swap(a[min], a[i]);
		cout << "Buoc " << i << ": ";
		printArr(a,n);
	}
}

void bubbleSort(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
		printArr(a,n);
	}
}

void insertionSort(int a[], int n){
	for(int i=1;i<n;i++){
		int temp = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > temp){
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}
}

// //qsort() in C program
// co 3 gia tri: > 0, < 0, = 0
// void qsort(void *base, size_arr, size_element, int (*cmp)(const void *a, const void *b));
// - *base: v? trí b?t d?u (d?a ch?) c?a ptu d?u tiên trong m?ng
// - size_arr: kích thu?c c?a m?ng;
// size_element: kick thuoc cua tung ptu trong mang => sizeof(data_type)

// int cmp(const void *a, const void *b){
// 	return (*(int*)a - *(int*)b);
// }
// ep kieu con tro: (int*)a

// int cmp(const void *a, const void *b){
// 	return (*(int*)b - *(int*)a);
// }

// bool sort(void *begin, void *end, bool cmp(void a, void b));
//mac dinh 2 tham so: sx tang dan
//*begin: vi tri bat dau sx
//*end: vi tri cuoi cng can sx + 1
//giam dan: greater<date_type>();

//su dung cac dau: > < =
// bool cmp(int a, int b){
// 	return a > b;
// }

//[](parameters) -> return type{code}
// sort(a, a+n, [](int a, int b) -> bool{
// 		return a > b;
// });


bool linearSearch(int a[], int n, int x){
	for(int i=0;i<n;i++){
		if(a[i] == x){
			return true;
		}
	}
	return false;
}

bool binarySearch(int a[], int n, int x){
	int l = 0;
	int r = n-1;
	while(l <= r){
		int m = (l+r)/2;
		if(x == a[m]) return true;
		else if(x > a[m]) l = m + 1;
		else
			r = m - 1;
	}
	return false;
}

//Tim thang dau tien > x
int upperBound(int a[], int n, int x){
	int l = 0;
	int r = n-1;
	int index = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(x >= a[m]) l = m+1;
		else{
			r = m - 1;
			index = m;
		}
	}
	return index;
}

//dau tien >= x
int lowerBound(int a[], int n, int x){
	int l = 0;
	int r = n-1;
	int index = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(x > a[m]) l = m+1;
		else{
			r = m - 1;
			index = m;
		}
	}
	return index;
}

//BigO(log(n))

//ham tim kien nhi phan: binary_search(*begin, *end, value); -> true/ false
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n];
	
	for(int &x : a) cin >> x;
	sort(a, a+n);

	// if(binary_search(a, a+n, 10)) cout << "da tim thay!\n";
	// else cout << "Khong tim thay!\n";

	// upper_bound(begin, end, value); -> neu la vector thi:
	// 	- tim ra phan tu dau tien > value
	// 	- tim thay: tra ve iterator(con tro) tro den vi tri cua phan tu do
	// 	- khong tim thay: tra ve v.end();

	// lower_bound(begin, end, value); -> neu la vector thi:
	// 	- tim ra phan tu dau tien >= value
	// 	- tim thay: tra ve iterator(con tro) tro den vi tri cua phan tu do
	// 	- khong tim thay: tra ve v.end();
	
	cout << lowerBound(a,n, 9) << endl;
	return 0^0;
} 
