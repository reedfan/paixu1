#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n);
void out(int arr[], int n);

int quickSort(int arr[], int first, int end);
int binary(int array[],int target,int length);


int jumpFloor(int target);

int moreThanHalf(int arr[]);



int main() {
  //  int a[] = {5,8,3,34,21,4,6};
  //  int length = sizeof(a)/4;
   // bubbleSort(a,length);
 // quickSort(a,0,length-1);

    int array[]={1,2,3,4,5,6,7};
    int length=sizeof (array)/4;
    int target=5;
    int result=	binary(array,target,length);
    cout<<result<<endl;



  //https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
   // jumpFloor(10);

  //  https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

}


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1 ; i++) {
        for (int j = 0; j < n - i-1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int arr2[]= {2,4};

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

int binary(int array[],int target,int length){

    int start=0;
    int end=length-1;
    while(start<=end){
        int midpoint = (start+end)/2;
        if(target<array[midpoint]){
            end = midpoint-1;
        }
        if(target>array[midpoint]){
            start = midpoint+1;
        }
        if(target == array[midpoint]){
            return target;
        }
    }
    return 0;
}







void out(int arr[], int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;

}

int jumpFloor(int target){
    if(target == 1){
        return 1;
    }
    if(target == 2){
        return 2;
    }
    return jumpFloor(target-1)+jumpFloor(target-2);

}

int moreThanHalf(int arr[]){



}