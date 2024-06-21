#include <iostream>

using namespace std;


int partition(int arr[],int low,int high){
   int pivot=arr[high];
   int i=(low-1);
   
   for(int j=low;j<=high-1;j++){
      if(arr[j]<pivot){
         i++;
         swap(arr[i],arr[j]);
      }
   }
   swap(arr[i+1],arr[high]);
   return (i+1);
}


void quickSort(int arr[],int low,int high){
   if(low<high){
      int pi=partition(arr,low,high);
      quickSort(arr,low,pi-1);
      quickSort(arr,pi+1,high);
   }
}


int absoluteValue(int value){
   if(value < 0){
      return value * -1;
   }
   return value;
}


int findShortestDistance(int arr1[], int arr2[], int lengthArray1, int lengthArray2){
   int i = 0;
   int j = 0;

   int shortest_distance = absoluteValue(arr1[i] - arr2[j]);

   while(i < lengthArray1 && j < lengthArray2){
      int new_distance = absoluteValue(arr1[i] - arr2[j]);

      if(new_distance < shortest_distance){
         shortest_distance = new_distance;
      }

      if(arr1[i] < arr2[j]){ 
         i++; 
      }else{ 
         j++; 
      }
   }

   return shortest_distance;
}



int main(){

   int array1[] = {1, 2, 3, 5, 7,-1,-8,5,-4,-9};
   int array2[] = {10, 20, 30, 40, 26,6,-12,45,99,100};
   
   int lengthArray1 = sizeof(array1)/sizeof(array1[0]);
   int lengthArray2 = sizeof(array2)/sizeof(array2[0]);

   quickSort(array1,0,lengthArray1-1);
   quickSort(array2,0,lengthArray2-1);

   int shortest_distance = findShortestDistance(array1,array2, lengthArray1, lengthArray2);

   cout << "A menor distancia entre o 1° array e o 2° array é " << shortest_distance;

   return 0;
}