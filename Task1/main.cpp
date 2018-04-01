#include <fstream>
#include <iostream>
#include <locale>

using namespace std;

const int N = 6;

struct Matrix {
    int size;
    int* vect;
    int* cols;
    int* rows;

    Matrix() {
        size = N * N; // по-другому (зачем полностью)
        vect = new int[size];
        cols = new int[size];
        rows = new int[size];
        for (int i = 0; i < N; i++) {
            vect[i] = 0;
            cols[i] = 0;
            rows[i] = 0;
        }
    }

    ~Matrix() {
        delete[] vect;
        delete[] cols;
        delete[] rows;
    }

    friend ostream& operator<<(ostream& os, Matrix& m);
};

int Sort_c(Matrix* b) {
    int min;
    int size_local = N;
    int k = 0;

    for (int i = 0; i < size_local; i++) {
        min = i;
        for (int j = i; j < size_local; j++) {
            if (b->vect[j] <= b->vect[min])
                min = j;
        }
        swap(b->vect[i], b->vect[min]);
    }
}

void readF(Matrix& m) {
    ifstream in;
    in.open("F.txt");
    int* tmp = new int[N * N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> tmp[j + i * N];
            cout << tmp[j + i * N] << " ";
        }
        cout << endl;
    }
    in.close();

    /*int* result = new int[m.size];
for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                result[j+i*N] = 0;
            }
        }*/

    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tmp[j + i * N] != 0) {
                m.vect[k] = tmp[j + i * N];
                m.cols[k] = j;
                m.rows[k] = i;
                k++;
            }
        }
    }

    m.size = k;

    for (int i = 0; i < m.size; i++) {
        cout << m.vect[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m.size; i++) {
        cout << m.rows[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m.size; i++) {
        cout << m.cols[i] << " ";
    }
    cout << endl;

    delete[] tmp;
}

ostream& operator<<(ostream& os, Matrix& m) {
    for (int i = 0; i < m.size; i++) {
        os << m.vect[i] << " ";
    }
    os << endl;
    for (int i = 0; i < m.size; i++) {
        os << m.rows[i] << " ";
    }
    os << endl;
    for (int i = 0; i < m.size; i++) {
        os << m.cols[i] << " ";
    }
    os << endl;
    return os;
}

int main() {
    ofstream out;
    out.open("F1.txt");
    Matrix A;
    readF(A);
    out << A << endl;
    out.close();
}
