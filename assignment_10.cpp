
#include <stdio.h>
 
int array[100], n;
int main()
{
    void insert(int num, int location);
    void remove();
    void display();
    int choice, num;
    n = 0;
    while(1)
    {
        printf("1.Insert element \n");
        printf("2.Delete element \n");
        printf("3.Display \n");
        printf("Others.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &num);
            insert(num, n);
            n = n + 1;
            break;
        case 2:
            remove();
            break;
        case 3:
            display();
            break;
        default:
            return 0;
    	}
	}
	return 0;
}
 
void display()
{  
    int i;
    if (n == 0)
    {
        printf("Priority Queue is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
 
void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num <= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }
    array[0] = num;
}
 
void remove()
{
    int left, right, i, temp, parentnode;
    i=0;
    array[i] = array[n - 1];
    n = n - 1;
    parentnode =(i - 1) / 2;
    if (array[i] > array[parentnode])
    {
        insert(array[i], i);
        return;
    }
    left = 2 * i + 1;
    right = 2 * i + 2;
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])
    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}