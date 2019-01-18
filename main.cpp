#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n);
void out(int arr[], int n);

int quickSort(int arr[], int first, int end);

int main() {
    int a[] = {5,8,3,34,21,4,6};
    int length = sizeof(a)/4;
  //  bubbleSort(a,length);
  quickSort(a,0,length-1);

}


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    out(arr,n);
}


int quickSort(int arr[], int low, int high){



    int start = low;
    int end = high;
    int key = arr[low];   //选取基准值
    while (end>start){
        //从后往前比较
        while (end > start && arr[end]>=key){
            end --;
        }
        if(arr[end]<=key){
            int tmp = arr[end];
            arr[end] = arr[start];
            arr[start] = tmp;
        }

        //从前往后比较
        while (end>start&&arr[start]<=key){
            start++;
        }
        if(arr[start]>=key){//如果没有比关键值大的，比较下一个，直到有比关键值大的交换位置
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        //此时第一次循环比较结束，关键值的位置已经确定了。左边的值都比关键值小，右边的值都比关键值大，但是两边的顺序还有可能是不一样的，进行下面的递归调用

    }
    if(start>low){
        quickSort(arr,low,start-1);
    }
    if(end<high){
        quickSort(arr,end+1,high);
    }

 //   out(arr, sizeof(arr)/4);


}







void out(int arr[], int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;

}