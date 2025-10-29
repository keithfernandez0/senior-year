## Analysis
- Simplifications 
	- Ignore actual and abstract statement costs
	- **Order of growth** is the interesting measure:
		- Highest order term is what counts
			- Remember that we are doing asymptotic analysis
			- As the input size grows larger, it is the higher order term that dominates
---
## Upper bound notation
- We say that InsertionSort's run time is $O(n^2)$
	- Properly we should say run time is *in* $O(n^2)$
	- Read O as "big O"
- In general, a function
	- $f(n)$ is $O(g(n))$ if there exists positive constants $c$ and $n_0$ 
---
## Lower bound notation
- We say InsertionSort's run time is $\Omega(n)$

## Asymptotic tight bound 

* A function \$f(n)\$ is in \$\Theta(g(n))\$ if there exist positive constants \$c\_1, c\_2,\$ and \$n\_0\$ such that:
  $c_1 g(n) \leq f(n) \leq c_2 g(n), \quad \forall n \geq n_0$
* Intuition: \$\Theta(g(n))\$ is a **tight bound**, meaning \$f(n)\$ grows at the same rate as \$g(n)\$, not just faster or slower.
* Theorem: \$f(n)\$ is \$\Theta(g(n))\$ **if and only if** \$f(n)\$ is both \$O(g(n))\$ and \$\Omega(g(n))\$.

  * In plain English: if Big-O gives an upper limit and Big-Omega gives a lower limit, and both point to the same function, then Theta says that’s the actual growth rate.

---

## Practical complexity

* Theoretical growth rates show how functions scale, but graphs help visualize differences:

  * \$f(n) = \log(n)\$ grows very slowly (barely noticeable increase).
  * \$f(n) = n\$ grows linearly.
  * \$f(n) = n \log(n)\$ is a bit worse than linear but much better than quadratic.
  * \$f(n) = n^2\$ and \$f(n) = n^3\$ grow much faster.
  * \$f(n) = 2^n\$ explodes — it becomes impractical very quickly.
* Plain English: this is why exponential-time algorithms are “hopeless” for large inputs — they outgrow feasible computing power almost immediately.
---
## Asymptotic performance

* Once \$n\$ is large enough, even small constants don’t matter — growth rate dominates.
* Example: a \$\Theta(n^2)\$ algorithm will **always** eventually outperform a \$\Theta(n^3)\$ algorithm, no matter the constants.
* Real-world note: sometimes slower-growing algorithms are harder to implement, so you might balance complexity with practicality.