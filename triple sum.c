#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//function for sorting the elements in the array

long int compare(const void *a,const void *b)
{
    return (*(long int*)a > *(long int*)b);
}

int main()
{
    long int counta=0;
    long int countb=0;
    long int *a,*b,*c;
    long int lena,lenb,lenc;
    int i,j,k;
    long int sum=0;

    //getting the size of the arrays

    scanf("%ld%ld%ld",&lena,&lenb,&lenc);

    //allocating the memory dynamically for the arrays

    a=(long int*)malloc(lena*sizeof(long int));
    b=(long int*)malloc(lenb*sizeof(long int));
    c=(long int*)malloc(lenc*sizeof(long int));

    //getting the inputs for the array

    for(i=0;i<lena;i++)
        scanf("%ld",&a[i]);

    for(i=0;i<lenb;i++)
        scanf("%ld",&b[i]);

    for(i=0;i<lenc;i++)
        scanf("%ld",&c[i]);


    //sorting the input arrays

    qsort(a,lena,sizeof(long int),compare);
    qsort(b,lenb,sizeof(long int),compare);
    qsort(c,lenc,sizeof(long int),compare);

    for(i=0;i<lenb;i++)
    {
        long int temp;
        temp=b[i];
        int j,k;

        //checking for the elements in the arraya having values less than or equal to temp

        if(i==0 || b[i] != b[i-1])
        {

        for(j=0;j<lena;j++)
        {
            if( a[j] <= temp )
                counta++;
            else
                break;
        }

        for(k=0;k<lenc;k++)
        {
            if( c[k] <= temp )
                countb++;
            else
                break;
        }

        sum=sum+( counta * countb );

        counta=0;
        countb=0;
        }

        else
            break;

    }


    printf("%ld",sum);


}
