#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashItem;

int* twoSum(int* nums, int numsSize, int target) {
    HashItem* map = (HashItem*)calloc(numsSize, sizeof(HashItem));
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        for (int j = 0; j < i; j++) {
            if (map[j].key == complement) {
                result[0] = map[j].value;
                result[1] = i;
                free(map);
                return result;
            }
        }
        map[i].key = nums[i];
        map[i].value = i;
    }

    free(map);
    return NULL;
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int* indices = twoSum(nums, n, target);
    if (indices != NULL) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No two numbers sum up to the target.\n");
    }

    free(nums);
    return 0;
}