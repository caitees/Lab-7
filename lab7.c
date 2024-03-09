#include <stdio.h>
//bubble sort first
void bubbleSort(int arr[], int n, int swaps[]) {
  for(int k = 0; k < n; k++) {
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swaps[arr[i]]++;
      }
    }
  }
}

//selection sort
void selectionSort(int arr[], int n, int swaps[]){
  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    if(min != i){
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
      swaps[arr[i]]++;
    }
  }
}

//print function
void printA(int arr[], int n, int swaps[]){
  int total = 0;
  for(int i = 0; i < n; i++){
    printf("%d: %d \n", arr[i], swaps[arr[i]]);
    total += swaps[arr[i]];;
  }
  printf("Total swaps: %d \n", total);
}

//main function
//array1: 97  16  45  63  13  22  7  58  72
//array2: 90  80  70  60  50  40  30  20  10
int main(){
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n = sizeof(array1) / sizeof(array1[0]);
  int swaps1[100] = {0};
  int swaps2[100] = {0};

  //bubble sort
  printf("array1 bubble sort: \n");
  bubbleSort(array1, n, swaps1);
  printA(array1, n, swaps1);
  printf("\narray2 bubble sort: \n");
  bubbleSort(array2, n, swaps2);
  printA(array2, n, swaps2);

  //set arrays back to normal
  for (int i = 0; i < n; i++) {
      array1[i] = 97 - i * 10;
      array2[i] = 90 - i * 10;
      swaps1[array1[i]] = 0; // Reset swaps array
      swaps2[array2[i]] = 0; // Reset swaps array
  }

  //selection sort
  printf("\narray1 selection sort: \n");
  selectionSort(array1, n, swaps1);
  printA(array1, n, swaps1);
  printf("\narray2 selection sort: \n");
  selectionSort(array2, n, swaps2);
  printA(array2, n, swaps2);

  return 0;
}

