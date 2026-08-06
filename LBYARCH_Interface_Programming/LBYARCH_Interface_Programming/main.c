#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int height, width;

    printf("=== Grayscale Float Image Input ===\n");

    // Read image dimensions
    printf("Enter height and width: ");

    if (scanf("%d %d", &height, &width) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    int size = height * width;

    // Allocate memory
    float* input = (float*)malloc(size * sizeof(float));
    unsigned char* output = (unsigned char*)malloc(size * sizeof(unsigned char));

    if (input == NULL || output == NULL)
    {
        printf("Memory allocation failed.\n");

        free(input);
        free(output);

        return 1;
    }

    // Read pixel values
    printf("Enter %d grayscale values (0.0 to 1.0):\n", size);

    for (int i = 0; i < size; i++)
    {
        if (scanf("%f", &input[i]) != 1)
        {
            printf("Invalid pixel value.\n");

            free(input);
            free(output);

            return 1;
        }
    }

    // Display the input image
    printf("\nInput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", input[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    // Free allocated memory
    free(input);
    free(output);

    return 0;
}