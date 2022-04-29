#include <array>
#include <algorithm>
#include <iostream>
#define max_length 50
using namespace std;
class heap {
protected:
	friend class priorityqueue;
	int size=0;
public:
	array<int, max_length> arr;
	virtual void insert(int x) {
		arr[(size++)] = x;
	}
	template<std::size_t SIZE>
	void insertarray(array<int, SIZE> x) {
		int tmp = SIZE;
		for (int i = size; i < size+tmp; i++) {
			arr[ i] = x[i-size];
		}
	}
	virtual void showcontents() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
	}
	void maxheapify(int i) {
		int left = 2 * i+1;
		int right = 2 * i + 2;
		int largest;
		if (left <= size-1 && arr[left] > arr[i]) largest = left;
		else largest = i;
		if (right <= size-1 && arr[right] > arr[largest]) largest = right;
		if (largest != i) {
			swap(arr[i], arr[largest]);
			maxheapify(largest);
		}
	}
	virtual void buildmaxheap() {
		for (int i = size / 2; i >= 1; i--) {
			maxheapify(i);
		}
	}
	virtual void heapsort() {
		buildmaxheap();
		int tmp = size;
		for (int i = size; i > 1; i--) {
			swap(arr[0], arr[i - 1]);
			size--;
			maxheapify(0);
		}
		size = tmp;
	}
};
class priorityqueue : public heap {
public:
	void insert(int x) {
		arr[(size++)] = x;
		buildmaxheap();
	}
	template<std::size_t SIZE>
	void insertpqueue(array<int, SIZE> x) {
		for (int i = size; i < size + SIZE; i++) {
			arr[i] = x[i];
			buildmaxheap();
		}
	}
	int max_heap_maximum() {
		if (size < 1) { throw "heap underflow"; }
		else return arr[0];
	}
	int max_heap_extract_max() {
		int max = max_heap_maximum();
		arr[0] = arr[size - 1];
		size--;
		maxheapify(0);
		return max;
	}
	void max_heap_increase_key(heap& h, int elem, int newelem) {
		if (newelem<arr[elem])
		{
			throw "new key is smaller than current key";
		}
		else { arr[elem] = newelem; }
		int i = elem;
		while (i > 0 && arr[i / 2] < arr[i]) {
			swap(arr[i], arr[i / 2]);
			i = i / 2;
		}
	}
	void max_heap_insert(heap& h, int newelem) {
		h.size++;
		h.insert(newelem);
		max_heap_increase_key(h, h.size, newelem);
	}
};

