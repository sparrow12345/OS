#include <stdio.h>

void BubbleSort(int a[],int n) {
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (a[i]>a[j]) {
        a[i]=a[i]+a[j];
        a[j]=a[i]-a[j];
        a[i]=a[i]-a[j];
      }
    }
  }
}

int main() {
  int n=10;
  int a[] = {3,6,4,1,5,7,1,5,9,4};
  BubbleSort(a,n);
  for (int i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}
