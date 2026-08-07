# LBYARCH-Interface-programming
---
## Files
- `main.c` - Handles memory allocation, reads the image data, calls the assembly function, checks the output for correctness, and measures the execution time.
- `convert.asm` - Converts grayscale floating-point pixel values to 8-bit integer grayscale values using x86-64 assembly.
---
## Correctness Check

### Sample Input
[Insert the sample input used for testing]
  
### Sample Output
```text
Output Image:
63 89 114 84
140 165 191 84
216 242 38 84

Correctness Check: PASSED
```
### Result
[Insert description]

### Screenshot
> [Insert a screenshot of the correctness test]

---
## Performance Evaluation

### Test Setup
- Number of Runs: **30**
- Image Sizes Tested:
  - 10 x 10
  - 100 x 100
  - 1000 x 100
 
### Performance Test Screenshots
> 10x10

> <img width="612" height="151" alt="Screenshot 2026-08-07 122243" src="https://github.com/user-attachments/assets/7a451b7f-8e72-4d73-b273-95e60b1b3931" />

> 100x100

> <img width="615" height="151" alt="Screenshot 2026-08-07 122144" src="https://github.com/user-attachments/assets/5f9867db-12bc-45ac-90e0-869b6e0dde2e" />

> 1000x1000

> <img width="665" height="151" alt="Screenshot 2026-08-07 112152" src="https://github.com/user-attachments/assets/42e70b6a-7b86-43e1-93fc-5a00da9c060d" />

## Performance Results

| Image Size | Total Execution Time (30 Runs) | Average Execution Time |
|------------|-------------------------------:|-----------------------:|
| 10 × 10 | 0.0000063 seconds      | 0.00000002 seconds     |
| 100 × 100 | 0.000543300000 seconds | 0.000018110000 seconds |
| 1000 × 1000 | 0.050163800000 seconds | 0.001672126667 seconds |


## Performance Analysis
