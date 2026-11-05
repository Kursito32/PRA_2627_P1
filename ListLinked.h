#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>

#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

private:

    Node<T>* first;
    int n;

public:

    // Constructor
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // Destructor
    ~ListLinked() {

        Node<T>* aux;

        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }

        n = 0;
    }

    // Devuelve el elemento de una posicion
    T get(int pos) override {

        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;

        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    // Inserta un elemento
    void insert(int pos, T value) override {

        if (pos < 0 || pos > n) {
            throw out_of_range("Posicion no valida");
        }

        Node<T>* nuevo = new Node<T>(value);

        if (pos == 0) {

            nuevo->next = first;
            first = nuevo;

        } else {

            Node<T>* aux = first;

            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            nuevo->next = aux->next;
            aux->next = nuevo;
        }

        n++;
    }

    // Elimina un elemento y lo devuelve
    T remove(int pos) override {

        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion no valida");
        }

        Node<T>* aux;

        if (pos == 0) {

            aux = first;
            first = first->next;

        } else {

            Node<T>* anterior = first;

            for (int i = 0; i < pos - 1; i++) {
                anterior = anterior->next;
            }

            aux = anterior->next;
            anterior->next = aux->next;
        }

        T valor = aux->data;

        delete aux;
        n--;

        return valor;
    }

    // Comprueba si esta vacia
    bool empty() override {
        return n == 0;
    }

    // Devuelve el tamaño
    int size() override {
        return n;
    }

    // Inserta al final
    void append(T value) {
        insert(n, value);
    }

    // Inserta al principio
    void prepend(T value) {
        insert(0, value);
    }

    // Busca un elemento
    int search(T value) {

        Node<T>* aux = first;
        int pos = 0;

        while (aux != nullptr) {

            if (aux->data == value) {
                return pos;
            }

            aux = aux->next;
            pos++;
        }

        return -1;
    }

    // Operador []
    T operator[](int pos) {

        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;

        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    // Operador <<
    friend ostream& operator<<(ostream& out, ListLinked<T>& list) {

        Node<T>* aux = list.first;

        out << "[";

        while (aux != nullptr) {

            out << aux->data;

            if (aux->next != nullptr) {
                out << ", ";
            }

            aux = aux->next;
        }

        out << "]";

        return out;
    }

};

#endif
