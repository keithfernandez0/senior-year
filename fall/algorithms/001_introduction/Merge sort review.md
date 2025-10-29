## Other asymptotic notations 

* $o(g(n))$: “little-o” → grows strictly slower than $g(n)$. (Like saying `<`)
* $O(g(n))$: “big-O” → grows at most as fast as $g(n)$. (Like saying `≤`)
* $\omega(g(n)$: “little-omega” → grows strictly faster than $g(n)$. (Like saying `>`)
* $\Omega(g(n))$: grows at least as fast as $g(n)$. (Like saying `≥`)
* $\Theta(g(n))$: grows at the same rate as $g(n)$. (Like saying `=`)
* Plain English: think of it like a chain of inequalities — little-o and little-omega are strict, big-O and big-Omega are non-strict, and Theta is exact balance.

---

## Big-O fact 

* Any polynomial of degree $k$ is $O(n^k)$.
* Example: $f(n) = 3n^3 + 5n^2 + 7n + 10$ is $O(n^3)$.
* Plain English: when looking at polynomials, the **highest power of $n$** is the only one that matters in asymptotic growth.

---

## Insertion sort analysis

* **Worst case** (input sorted in reverse): takes $\Theta(n^2)$ steps.
* **Average case** (input random): also $\Theta(n^2)$.
* **Best case** (input already sorted): $\Theta(n)$.
* Insertion sort is:

  * Fine for small inputs.
  * Bad for large inputs compared to more efficient algorithms.

---

## Merge sort 

* Algorithm:

  1. If $n = 1$, stop (already sorted).
  2. Recursively sort the left and right halves.
  3. Merge the two sorted halves.
* Key idea: **divide and conquer**.
* **Merging** two sorted arrays of total length $n$ takes $\Theta(n)$ time.
* **Recurrence relation:**
  $T(n) = 2T(n/2) + \Theta(n)$
* Using recursion tree analysis, this works out to:
  $T(n) = \Theta(n \log n)$
* Conclusion:

  * Merge sort is asymptotically faster than insertion sort for large $n$ ($n \log n$) grows slower than $n^2$.
  * In practice, insertion sort can still win on small $n$ because recursion overhead makes merge sort slower until $n$ is large enough.

---

