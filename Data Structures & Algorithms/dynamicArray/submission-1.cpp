class DynamicArray {
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        data = new int [capacity];
    }

    ~DynamicArray(){
        delete [] data;
    }    
    
    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity){
            resize();
        }
        data[size] = n;
        size++;
    }

    int popback() {
        size--;
        return data[size];
    }

    void resize() {
       capacity = capacity * 2;
       int *bigger = new int [capacity];
       for(int i = 0; i < size; i++){
        bigger[i] = data[i];
       }
       delete [] data;
       data = bigger;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
private : 
    int *data;
    int size;
    int capacity;
};
