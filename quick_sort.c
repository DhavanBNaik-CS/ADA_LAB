#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_size 1000000
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[max_size], n ,i;
  clock_t start, end;
  double total_t;
  printf("Enter array size :");
  scanf("%d",&n);
  printf("Array\n");
  for(i=0;i<n;i++){
      data[i]=rand()%1000;
  }
  start = clock();
  quickSort(data, 0, n - 1);
  end = clock();
  total_t = (double)(end-start)/CLOCKS_PER_SEC;
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
  
  printf("\n\ntime taken: %f",total_t);
}
