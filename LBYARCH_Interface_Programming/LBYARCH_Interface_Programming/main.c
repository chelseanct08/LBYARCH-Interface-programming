#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Assembly function
extern void imgCvtGrayFloatToInt(float* input, unsigned char* output, int size);

int main(void)
{
    int height, width;

    printf("=== Grayscale Float Image Input ===\n");

    printf("Enter height and width: ");

    if (scanf("%d %d", &height, &width) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    int size = height * width;

    float* input = (float*)malloc(size * sizeof(float));
    unsigned char* output = (unsigned char*)malloc(size * sizeof(unsigned char));

    if (input == NULL || output == NULL)
    {
        printf("Memory allocation failed.\n");

        free(input);
        free(output);

        return 1;
    }

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

    printf("\nInput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", input[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    imgCvtGrayFloatToInt(input, output, size);

    printf("\nOutput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%u ", output[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    free(input);
    free(output);

    return 0;
}