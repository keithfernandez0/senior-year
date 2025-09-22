## What is in this course
- Basic goals for an algorithm
	- Always correct
	- always terminates
	- Performance is prioritized in this class
		- Performance often draws the line between what is possible and what is impossible.
---
## Design and analysis of algorithms
- **Analysis**: predict the cost of an algorithm in terms of resources and performance
- **Design**: design algorithms which minimize cost
- Why is my program running slow?
	- Running time efficiency
- Why does my program run out of memory?
	- Space efficiency
---
##  Review: Inductions
- Example #1:
	- Suppose
		- $S(k)$ is true for fixed constant $k$
		- $S(n)$ is true for all $n >= k$
---
## Proof by induction
	- Claim: $S(n)$ is true for all $n>=k$
	- Base case $S(k)$
		- Show the statement (formula) is true for the initial value $n=k$
		- If $n=1$, then $1=1(1+1)/2$
	- Induction hypothesis
		- Assume it's true for an arbitrary value of $n, n>=k$
		- Assume $1+2+3+...+n=\frac{n(n+1)}{2}$
	- Induction step
		- Assume it is also true for $n+1$
		- $1+2+...+n+n+1=(1+2+...+n)+(n+1)$
- Example #2:
	- Prove $2^n >= n+1, n>=0$
	- Base case: when $n=0$
	- Inductive hypothesis:
		- Assume $2^n >= n+1$ for some arbitrary $n>=0$
	- Inductive step (show true for n+1):
		- $2^{n+1} = 2 \cdot 2^{n+1}$
---
## Our machine model
- Generic random access machine (RAM)
	- Executes one instruction at a time
	- Set of primitive operations
		- Arithmetic, logical, comparisons, function calls
	- Simplifying assumption: all ops cost 1 unit
		- Eliminates dependence on the speed of our computer, otherwise impossible to verify and compare
---
## Input size
- Time and space complexity
	- This is generally a **function of the input size**
		- E.g.: sorting, multiplication
		- How we measure input size depends:
			- sorting: number of input items
			- Multiplication: total number of bits
			- Graph algorithms: number of nodes and edges
---
## Running time
- Number of primitive steps that are executed
	- Except for the time of executing a function call most statements roughly requires the same amount of time
---
## Kind of analyses
- Worst case (usually)
	- Provides an upper bound on running time
	- An absolute guarantee
- Average-case (sometimes)
	- Provides the expected running time
	- Very useful, but treat with care --> define average?
		- Random
		- Real-life inputs
		- Harder to do!
- Best-case (never)
	- Cheat with a slow algorithm that works fast on *some* input
---
## Asymptotic performance
- In this course, we care about asymptotic performance
	- How does the algorithm behave when the input size grows very large?
		- Running time
		- Memory/storage requirements
		- Bandwidth/power requirements, logic gates, etc.
---
## Example: Sorting problem
- Input: sequence of numbers $a_1$ to $a_n$
- Output: permutation $a`_1, a`_2, ...$ such that $a`_1<=a`_2<=...<=a`_n$

---
## Insertion sort
- Pseudocode
	- ```
	  for i <-- 2 to n
		  do key <-- A[i]
			  j <-- i - 1
			  while j>0 and A[j] > key 
				  do A[j+1] <-- A[j]
					  j <-- j-1
				A[j+1] = key
	  ```
## Running time
- The running time depends on the input: an already sorted sequence is easier to sort
- Major simplifying convention:
	- Parameterize the running time by the size of the input, since short sequences are easier to sort than longer ones.
		- $T(n)$ = time of $A$ on length $n$ inputs
	- Generally, we seek upper bounds on the running time, to have a guarantee of performance
---
## Machine-independent time
- What is insertion sort's worst-case time?
	- Depends on the speed of our computer: relative vs. absolute speed
- Big ideas:
	- Ignore machine dependent constants, otherwise impossible to verify and compare algorithms
	- Look at growth of $T(n)$ as $n \rightarrow \infty$
	- "Asymptotic analysis"
---