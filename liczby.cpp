#include <iostream>
#include <cstdlib>
 
using namespace std;
 
void wypelnijTab(int x, int y, int n, int* Los_liczby) {
    for(int i = 0; i < n; i++) {
        int los = rand() % (y - x + 1) + x;
        Los_liczby[i] = los;
    }
}
 
void drukujTab(int* tab, int size) {
    for (int i = 0; i < size; i++) {
        cout << tab[i] << " ";
    }
}
 
void zamiana(int * tablica, int i, int j) {
    int temp = tablica[i];
    tablica[i] = tablica[j];
    tablica[j] = temp;
}
 
void sortowanie_bombelkowe(int * tablica, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(tablica[j] > tablica[j+1]) {
                zamiana(tablica, j, j + 1);
            }
        }
    }
}
 
void scalanie(int* tab, int l, int m, int r) {
    int lSize = m - l + 1;
    int rSize = r - m;
    int* tabL = new int[lSize];
    int* tabR = new int[rSize];
 
    for (int x = 0; x < lSize; x++)
        tabL[x] = tab[l + x];
    for (int y = 0; y < rSize; y++)
        tabR[y] = tab[m + 1 + y];
 
    int indexL = 0;
    int indexR = 0;
    int currIndex;
 
    for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) {
        if (tabL[indexL] <= tabR[indexR])
            tab[currIndex] = tabL[indexL++];
        else
            tab[currIndex] = tabR[indexR++];
    }
 
    while (indexL < lSize)
        tab[currIndex++] = tabL[indexL++];
    while (indexR < rSize)
        tab[currIndex++] = tabR[indexR++];
 
    delete[] tabL;
    delete[] tabR;
}
 
 
 
void sortowanie_przez_scalanie(int* tab, int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        sortowanie_przez_scalanie(tab, l, m);
        sortowanie_przez_scalanie(tab, m + 1, r);
        scalanie(tab, l, m, r);
    }
}
 
 
int main() {
    int x, y, n;
    
    cout << "Podaj początkową liczbę dla losowanych liczb: ";
    cin >> x;
    
    cout << "Podaj końcową liczbę dla losowanych liczb: ";
    cin >> y;
    
    cout << "Podaj rozmiar Twojej tablicy: ";
    cin >> n;
 
 
    int* tablica = new int[n];
 
    wypelnijTab(x, y, n, tablica);
 
   drukujTab(tablica, n);
   cout<< " "<<endl;
   sortowanie_bombelkowe(tablica, n);
   cout<< "Posortowana tablica: " <<endl;
   drukujTab(tablica, n);
   cout<< " "<<endl;
 
    int * tablica2 = new int[n];
    wypelnijTab(x,y,n, tablica2);
    drukujTab(tablica2, n);
    cout<< " "<<endl;
    sortowanie_przez_scalanie(tablica2, 0 , n);
    cout<< "Posortowana tablica: " <<endl;
    drukujTab(tablica2, n);
 
    delete[] tablica;
    delete[] tablica2;

    return 0;
}
