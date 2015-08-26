#include<stdio.h>
#include<stdlib.h>
int inv=0;
void merge(int *,int,int,int);
void mergeSort(int *arr,int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
void merge(int *arr,int beg,int mid,int end)
{
    int index=beg,i=beg,j=mid+1,temp[end],k;
    
    while((i<=mid)&&(j<=end))
    {
        if(arr[i]<=arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
            inv+=(mid-i+1);
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
   
   // for(i=beg;i<=mid;i++)
   // {
    //    for(j=mid+1;j<=end;j++)
    //    {
   //         if(arr[i]>arr[j])
   //         {
   //             printf("%d%d\n",arr[i],arr[j]);
   //             inv++;
   //         }
   //    }
   // }

    for(k=beg;k<index;k++)
    {
        arr[k]=temp[k];
    }
}

int main(int argc,char* argv[])
{
    int size,i;
    
    printf("Enter the size of array and the elements of array\n");
    scanf("%d",&size);

    int *n=(int *)malloc(size*sizeof(int));
    int beg=0,end=size-1;

    for(i=0;i<size;i++)
    {
        scanf("%d",&n[i]);
    }
    mergeSort(n,beg,end);

    printf("The number of inversions are : %d",inv);
}
