#include <iostream>
#include <chrono>  
#include <cstdlib> 
#include <ctime>   

using namespace std;
using namespace std::chrono;

// Shell Sort modificado para contar intercambios y comparaciones
void shellSort(int arr[], int n, int &swapCount, int &comparisonCount) 
{
    int k = n, cen, i; 
    while (k > 1) 
    {
        k = k / 2;
        cen = 1;
    }
    while (cen == 1) 
    {
        cen = 0; 
        i = 0;
        while (i + k < n) 
        {
            comparisonCount++; // Incrementar el contador de comparaciones
            if (arr[i + k] < arr[i]) 
            {
                int aux;
                aux = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = aux;
                cen = 1;
                swapCount++; // Incrementar el contador de intercambios
            }
            i = i + 1;
        }
    }
}

// Bubble Sort modificado para contar intercambios y comparaciones
void bubbleSort(int arr[], int n, int &swapCount, int &comparisonCount) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            comparisonCount++; // Incrementar el contador de comparaciones
            if (arr[i] > arr[j]) 
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                swapCount++; // Incrementar el contador de intercambios
            }
        }
    }
}

// Generador de arreglos aleatorios
void generador(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

// Copiar un arreglo
void copia(int original[], int copi[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        copi[i] = original[i];
    }
}

int main()
{
    int n;
    cout << "Ingrese la cantidad de datos: "; 
    cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    // Generar el arreglo y copiarlo
    generador(arr1, n);
    copia(arr1, arr2, n);

    // Contadores de intercambios y comparaciones
    int swapCountShell = 0, comparisonCountShell = 0;
    int swapCountBubble = 0, comparisonCountBubble = 0;

    // Medir tiempo de ejecución para Shell Sort
    auto startShell = high_resolution_clock::now();
    shellSort(arr1, n, swapCountShell, comparisonCountShell);
    auto stopShell = high_resolution_clock::now();
    auto durationShell = duration_cast<microseconds>(stopShell - startShell);

    // Medir tiempo de ejecución para Bubble Sort
    auto startBubble = high_resolution_clock::now();
    bubbleSort(arr2, n, swapCountBubble, comparisonCountBubble);
    auto stopBubble = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);

    // Mostrar resultados
    cout << "............................................................................................." << endl;
    cout << "                                       RESULTADOS                                            " << endl;
    cout << "............................................................................................." << endl;
    cout<<"-----------------------------------------SHELL SORT--------------------------------------------" << endl;
    cout << "Tiempo de ejecucion con Shell Sort: " << durationShell.count() << " microsegundos" << endl;
    cout << "Cantidad de intercambios en Shell Sort: " << swapCountShell << endl;
    cout << "Cantidad de comparaciones en Shell Sort: " << comparisonCountShell << endl;
    cout <<"-----------------------------------------BUBBLE SORT--------------------------------------------" << endl;
    cout << "Tiempo de ejecucion con Bubble Sort: " << durationBubble.count() << " microsegundos" << endl;
    cout << "Cantidad de intercambios en Bubble Sort: " << swapCountBubble << endl;
    cout << "Cantidad de comparaciones en Bubble Sort: " << comparisonCountBubble << endl;
    cout <<"..............................................................................................." << endl;

    // Liberar memoria
    delete[] arr1;
    delete[] arr2;

    return 0;
}
