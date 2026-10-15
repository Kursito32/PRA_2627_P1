Ask

Copy
#include <ostream>
#include <stdexcept>
#include "List.h"
#include <string>
#ifndef LISTARRAY_H
#define LISTARRAY_H
using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T*arr;
	int max;
	int n;
	static const int MINSIZE=2;
	void resize (int new_size){
		T* new_arr = new T[new_size];
		for (int i = 0; i < n; i++){
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		max = new_size;
	}
    public:
	ListArray(){
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}
	~ListArray() override{
		delete[] arr;
	}
	T operator[](int pos){
		if (pos < 0 || pos >= n){
			throw out_of_range("Error: La posicion" + to_string(pos) + "esta fuera de rango.");
		}
		return arr[pos];
	}
	friend ostream &operator<< (ostream &out,const ListArray<T> &list);
        // miembros públicos, incluidos los heredados de List<T>

    
};
