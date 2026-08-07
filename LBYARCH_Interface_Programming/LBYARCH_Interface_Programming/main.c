#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// assembly function
extern void convert(float* input, unsigned char* output, int size);

int main(void)
{
    int height, width;

    printf("=== Grayscale Image Float-to-Integer Converter ===\n");

    // correctness test
    printf("Enter height and width: ");

    if (scanf("%d %d", &height, &width) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    } 

    /* performance test
    height = 10; // 100 , 1000 
	width = 10; // 100 , 1000 
    */


    int size = height * width;

    // allocate memory
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

    // correctness test
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

    /* performance test - generates random input
    srand(1);

    for (int i = 0; i < size; i++)
    {
        input[i] = (float)rand() / RAND_MAX;
    } */

    // correctness test - displays the input image
    printf("\nInput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", input[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    // compute expected output in C
    for (int i = 0; i < size; i++)
    {
        expected[i] = (unsigned char)(input[i] * 255.0f);
    }

	// 30 runs for average execution time
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    for (int run = 0; run < 30; run++)
    {
        convert(input, output, size);
    }

    QueryPerformanceCounter(&end);

    double totalTime =
        (double)(end.QuadPart - start.QuadPart) /
        frequency.QuadPart;

    double averageTime = totalTime / 30.0;

    
    // correctness test - displays the output image
    printf("\nOutput Image:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%3u ", output[i]);

        if ((i + 1) % width == 0)
            printf("\n");
    }

    // correctness check
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

    printf("\nTotal Execution Time (30 runs): %.7f seconds\n", totalTime);
    printf("Average Execution Time        : %.7f seconds\n", averageTime);

    free(input);
    free(output);
    free(expected);

    return 0;
}

