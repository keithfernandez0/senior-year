# Midterm Study Sheet — Systems Programming & Parallel Computing
## **I. C Programming Fundamentals**

### **Key Components**

- **#include statements:** Bring in standard or user-defined libraries (e.g., `<stdio.h>`). Allows reuse of prewritten functions.
    
- **main routine:** Entry point of every C program. Defined as `int main(void)` or `int main(int argc, char *argv[])`.
    
- **Function definition:** `return_type function_name(parameters) { ... }`. Use prototypes for declarations before `main()`.
    

### **Syntax Essentials**

|Concept|Description|Example|
|---|---|---|
|`for` loop|Fixed iteration count.|`for(int i=0; i<n; i++) { }`|
|`while` loop|Condition-based iteration.|`while(condition) { }`|
|`if` statement|Conditional branching.|`if(x>0){...}`|
|**Arrays**|Contiguous memory blocks. Use `malloc()` for dynamic allocation.|`int *arr = malloc(n * sizeof(int));`|
|**Fundamental types**|`char`, `int`, `float`, `double`. Size and precision differ by type.||
|**Integer arithmetic**|Be mindful of overflow, truncation, and integer division behavior.|`5/2 == 2` not `2.5`|

---

## **II. Code Optimization Principles**

### **Memory Locality**

- **Spatial locality:** Access data stored near each other.
    
- **Temporal locality:** Reuse recently accessed data.
    
- **Rule:** Traverse arrays in contiguous order (e.g., row-major for C).  
    → Improves cache performance and reduces cache misses.
    

### **Function Call Minimization**

- **Strength reduction:** Replace expensive operations with cheaper ones (e.g., `x*x` instead of `pow(x,2)`).
    
- **Inlining:** Use macros or inline functions to remove function call overhead for small, frequently called functions.
    

### **Branch Reduction**

- Branch mispredictions cause pipeline stalls (especially harmful in loops).
    
- Prefer straight-line code or arithmetic substitutions when possible.
    

### **Loop Optimization**

- **Move invariants out of loops.** Compute constants once before loop.
    
- **Simplify loop body.** Avoid unnecessary calculations.
    
- **Static memory:** Easier for compiler optimization than dynamic memory.
    
- **Example:**
    
    ```c
    for(int i=0; i<n; i++) z[i] = a*b + c[i];  // a*b can be moved outside loop
    ```
    

---

## **III. Python Acceleration Techniques**

1. **Numba:**
    
    - JIT compiler that translates Python functions (especially NumPy-heavy ones) to optimized machine code using LLVM.
        
    - Add `@njit` decorator for minimal effort speedup.
        
2. **CUDA with TensorFlow or PyTorch:**
    
    - Offloads matrix/tensor operations to GPU.
        
    - Extremely effective for large-scale numeric computation and ML tasks.
        
3. **Other options:**
    
    - Cython or rewriting hotspots in C/C++.
        

---

## **IV. Parallel Computing Concepts**

|Term|Definition|
|---|---|
|**Concurrent**|Multiple tasks make progress at once (may share a single CPU via time-slicing).|
|**Parallel**|Tasks execute simultaneously on multiple cores or processors.|
|**Speedup (S)**|`S = T_serial / T_parallel` — higher is better.|
|**Efficiency (E)**|`E = S / P` (where P = number of processors). Ideal = 1.|
|**Loop-carried dependency**|When one iteration depends on the result of another → prevents parallelization.|

---

## **V. CUDA Programming Essentials**

### **Thread Organization**

- **Threads:** Smallest execution unit.
- **Block:** Group of threads that share memory.
- **Grid:** Collection of blocks for full kernel execution.

|Variable|Description|
|---|---|
|`threadIdx.x`|Index of thread within its block|
|`blockDim.x`|Number of threads per block|
|`blockIdx.x`|Index of block in the grid|
|`gridDim.x`|Number of blocks in the grid|

→ **Global thread index:**  
`int idx = threadIdx.x + blockIdx.x * blockDim.x;`

### **Device vs. Host Code**

- **Host:** Runs on CPU.
- **Device:** Runs on GPU.
- Host cannot call device functions directly except via **kernel launches** (`<<< >>>` syntax).
    

### **Branching Impact**

- Divergence within a warp (32 threads) → serialized execution → slower GPU utilization.

### **CUDA Kernel Example Fix**

Original kernel:

```c
__global__ void add_arrays(int n, float *a, float *b, float *c) {
    int ind = threadIdx.x + blockIdx.x * blockDim.x;
    c[ind] = a[ind] + b[ind];
}
```

**Corrected (bounds check):**

```c
__global__ void add_arrays(int n, float *a, float *b, float *c) {
    int ind = threadIdx.x + blockIdx.x * blockDim.x;
    if (ind < n) c[ind] = a[ind] + b[ind];
}
```

---

## **VI. Algorithm Suitability for GPU**

|Problem|GPU Fit|Why|
|---|---|---|
|**Matrix-Matrix Multiply**|Excellent|High data parallelism; each output cell independent.|
|**Monte Carlo Integration (with function pointers)**|Poor|Control flow divergence and function pointer calls prevent efficient GPU execution.|

---

## **VII. Language Performance & Optimization Reasoning**

**Why Python is slower:**

- Python is **interpreted**, **dynamically typed**, and uses **reference counting** → high overhead.
- C/C++ are **compiled to native machine code**, allowing compiler-level optimizations.
- Profiling (like 1D wave equation) shows Python spends most time in interpreter overhead rather than math operations.
    

**How to fix it (minimal effort):**

|Method|Description|Effort|Effectiveness|
|---|---|---|---|
|**Numba JIT**|Compile hot loops to native code|Low|High|
|**Vectorize with NumPy**|Avoid explicit Python loops|Low|Medium|
|**GPU libraries (TensorFlow/PyTorch)**|Offload to CUDA cores|Medium|Very High|

---

## **VIII. Example Optimization Question (Loop)**

```c
for(i=0;i<n;i++) {
    if(i==0)
        z[index_array[0]]=0.0;
    else if (i==n-1)
        z[index_array[n-1]]=0.0;
    else
        z[index_array[i]] = f(index_array[i])*sin(2.0);
}
```

**Optimizations:**

1. **Remove invariant:** `sin(2.0)` is constant — compute once outside loop.
    
2. **Inline `f(x)`** since it’s simple (`x*x`).
    
3. **Reduce branching:** handle edge cases before loop or after.
    
4. **Exploit memory locality:** ensure `index_array` accesses are sequential or reordered if possible.
    

Rewritten:

```c
double s = sin(2.0);
z[index_array[0]] = 0.0;
for (i = 1; i < n-1; i++)
    z[index_array[i]] = index_array[i] * index_array[i] * s;
z[index_array[n-1]] = 0.0;
```

---

## **IX. CUDA Conversion Practice — Julia Set**

To parallelize the loop for image computation:

```c
__global__ void computeJulia(unsigned char *imageData, Complex c) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if (i >= WIDTH || j >= HEIGHT) return;

    int value = juliaValue(i, j, c);
    int index = (j * WIDTH + i) * 3;
    // Convert hue to RGB...
}
```

Launch:

```c
dim3 threads(16,16);
dim3 blocks((WIDTH+15)/16, (HEIGHT+15)/16);
computeJulia<<<blocks,threads>>>(imageData, c);
```

---

## **X. Quick Summary Checklist**

✅ C syntax and control structures  
✅ Static vs dynamic memory  
✅ Function inlining, loop invariants, locality  
✅ CUDA grid/block/thread indexing  
✅ GPU divergence and efficiency  
✅ Speedup & efficiency formulas  
✅ Python optimization (Numba, CUDA libs)

---