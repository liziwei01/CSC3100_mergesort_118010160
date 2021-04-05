#include <iostream>
#include <string>

using namespace std;

void merge(long* A,long p, long q, long r) {
     long n1 = q-p+1;
     long n2 = r-q;
     long* L = new long[n1+2];
     long* R = new long[n2+2];
     for (long i = 1; i <= n1; i++) {
         L[i] = A[p+i-1];
     }
     for (long j = 1; j <= n2; j++) {
         R[j] = A[q+j];
     }
     L[n1+1] = 2147483647;
     R[n2+1] = 2147483647;
     long i = 1;
     long j = 1;
     for (long k = p; k <= r; k++) {
         if (L[i] <= R[j]) {
             A[k] = L[i];
             i++;
         } else {
             A[k] = R[j];
             j++;
         }
     }
     delete [] L;
     delete [] R;
}

void mergeSort(long* A,long p, long r) {
    if (p<r) {
        long q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void outputA(long* A, long A_size) {
    for (long i = 0; i < A_size; i++) {
        cout << A[i] << endl;
    }
}

int main() {
    long A_size;
    cin >> A_size;
    long array_A[A_size];
    for (long i = 0; i < A_size; i++) {
        cin >> array_A[i];
    }
//    long A_size=*(&array_A + 1) - array_A;
    long* A = array_A;
//    cout << "A_size = " << A_size << endl;
    mergeSort(A, 0, A_size-1);
    outputA(A, A_size);
    return 0;
}
