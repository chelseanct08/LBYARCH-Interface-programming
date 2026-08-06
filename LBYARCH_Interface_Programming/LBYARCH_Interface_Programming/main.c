#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    unsigned char* expected = (unsigned char*)malloc(size * sizeof(unsigned char));

    if (input == NULL || output == NULL || expected == NULL)
    {
        printf("Memory allocation failed.\n");

        free(input);
        free(output);
        free(expected);

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
            free(expected);

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

    // Compute expected output in C
    for (int i = 0; i < size; i++)
    {
        expected[i] = (unsigned char)(input[i] * 255.0f);
    }

    // Measure ASM execution time (30 runs)
    double totalTime = 0.0;

    for (int run = 0; run < 30; run++)
    {
        clock_t start = clock();

        imgCvtGrayFloatToInt(input, output, size);

        clock_t end = clock();

        totalTime += (double)(end - start) / CLOCKS_PER_SEC;
    }

    double averageTime = totalTime / 30.0;

    printf("\nOutput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%u ", output[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    // Correctness check
    int correct = 1;

    for (int i = 0; i < size; i++)
    {
        if (output[i] != expected[i])
        {
            correct = 0;

            printf("\nMismatch at pixel %d\n", i);
            printf("ASM Output : %u\n", output[i]);
            printf("Expected   : %u\n", expected[i]);
        }
    }

    if (correct)
    {
        printf("\nCorrectness Check: PASSED\n");
    }
    else
    {
        printf("\nCorrectness Check: FAILED\n");
    }

    printf("Average ASM Execution Time (30 runs): %.10f seconds\n", averageTime);

    free(input);
    free(output);
    free(expected);

    return 0;
}