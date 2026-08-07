# LBYARCH-Interface-programming
---
## Files
- `main.c` - Handles memory allocation, reads the image data, calls the assembly function, checks the output for correctness, and measures the execution time.
- `convert.asm` - Converts grayscale floating-point pixel values to 8-bit integer grayscale values using x86-64 assembly.
---
## Correctness

### Sample Input
```text
Enter height and width: 3 4

Enter 12 grayscale values (0.0 to 1.0):
0.25 0.35 0.45 0.33
0.55 0.65 0.75 0.33
0.85 0.95 0.15 0.33
```

### Sample Output
```text
Output Image:
63 89 114 84
140 165 191 84
216 242 38 84
```
### Result
[short summary of the correctness test]

### Screenshot
> <img width="383" height="299" alt="image" src="https://github.com/user-attachments/assets/03abc258-274f-42fe-9ebc-e188e03d253e" />

---
## Performance Evaluation

### Test Setup
- Number of Runs: **30**
- Image Sizes Tested:
  - 10 x 10
  - 100 x 100
  - 1000 x 1000
 
### Performance Test Screenshots
> 10x10

> <img width="612" height="151" alt="Screenshot 2026-08-07 122243" src="https://github.com/user-attachments/assets/7a451b7f-8e72-4d73-b273-95e60b1b3931" />

> 100x100

> <img width="615" height="151" alt="Screenshot 2026-08-07 122144" src="https://github.com/user-attachments/assets/5f9867db-12bc-45ac-90e0-869b6e0dde2e" />

> 1000x1000

> <img width="613" height="147" alt="Screenshot 2026-08-07 123355" src="https://github.com/user-attachments/assets/ca676a5c-0326-46c8-a70b-6dc9567b055d" />

## Performance Results

| Image Size | Total Execution Time (30 Runs) | Average Execution Time |
|------------|-------------------------------:|-----------------------:|
| 10 × 10 | 0.0000063 seconds | 0.0000002 seconds |
| 100 × 100 | 0.0003723 seconds | 0.0000124 seconds |
| 1000 × 1000 | 0.0452087 seconds | 0.0015070 seconds |


## Performance Analysis
[short discussion of the performance results]
