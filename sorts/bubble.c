#include <stdio.h>

int main() {
    int arr[8] = {23, 78, 65, 12, 41, 5, 63, 74};
    
    int length = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
}