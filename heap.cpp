#include<iostream>
using namespace std;
class node {
	public:
	int data;
	int arr[100];
	int size=0;
void init(int data){
	size++;
	int ind=size;
	arr[ind] = data;
	while (ind>1){
		int parent=ind/2;
		if(arr[parent]<arr[ind]){
			swap(arr[parent],arr[ind]);
			ind=parent;
		}
		else{
			return;
		}
	}
}
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// ... (Previous Node class definition remains the same)

void deleteRoot()
{
    // Get the last element
    arr[1] = arr[size];
    size--;
    int i=1;
    while(i<size){
        int l = 2 * i; // left = 2*i + 1
        int r = 2 * i + 1; // right = 2*i + 2
 
    // If left child is larger than root
        if (l < size && arr[i] < arr[l]){
        	swap(arr[i], arr[l]);
            i = l;
		}
 
    // If right child is larger than largest so far
        else if (r < size && arr[i] < arr[r]){
        	swap(arr[i], arr[r]);
            i = l;
		}
		else{
			return;
		}
	}
}

void heapsort() {
    for (int i = size / 2-1 ; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size ; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print() {
    for (int i = 1; i <=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
int main(){
    node root;
    root.init(15);
    root.init(25);
    root.init(5);
    root.init(10);
    root.init(43);
    root.init(8);
    root.init(95);

    cout << "Original Array: ";
    root.print();
    
    root.deleteRoot();
     root.print();
    root.heapsort();

    cout << "Array after Heap Sort: "<<endl;
    root.print();

}
