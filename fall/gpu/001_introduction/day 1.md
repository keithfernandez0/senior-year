## Getting started 
```python
squares = [x**2 for x in range(10)]
```

```python
import os
if(not os.path.exists("malware.gzip"))
	!wget "https://kissmyass.net/malware.gzip"
if(not os.path.exists("malware"))
	!gunzip "malware.gzip"
```

### Using UNIX commands in Colab
```python
%%writefile Hello.java
public class Hello {
	public static void main (String[] args) {
		System.out.println("Hello world.");
	}
}
```

```python
%%shell 
%%bash
javac Hello.java
java Hello
```
## Testing code
This is pseudocode. We will be modelling the following wave equation:
$$

\frac{d^2}{dt^2} y = k \frac{d^2}{dx^2} y

$$
```
n=2500 // approximate the string as being made up of n points
x = linspace(0,10,n) // space those points linearly from 0 to 10 in x
v = zeros(n) // set all velocities to zero
y = exp(-(x-5.0)**2) // start off the curvature with a bump
dvdt = zeros(n) // start off the string with no acceleration
store step size as dx = x[1]-x[0]
dxsquared = dx*dx
  

// run times from 0 to 10
tmin = 0
tmax = 10
// set timestep by dx (smaller dx needs smaller dt)
dt_ideal = 0.5*dx
// pick enough timesteps to get about that dt
nt = int(tmax/dt_ideal)+1
// linearly space time points
tgrid = linspace(tmin,tmax,nt)
// store dt
dt = tgrid[1]-tgrid[0]

  

k=1
for t in tgrid
for i in 1 to n-2 (assuming 0 is array start)
// use approximation to calculate curvature
dvdt[i] = k*(y[i-1]+y[i+1]-2.0*y[i])/dxsquared
for i in 0 to n-1
// use dvdt to update v
v[i] = v[i] + dvdt[i]*dt
for i in 0 to n-1
// use v = dydt to update y
y[i] = y[i] + y[i]*dt

OUTPUT Y
```
### C equivalent (cleaned)
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 2500;
    double *x = malloc(n * sizeof(double));
    double *v = calloc(n, sizeof(double));
    double *y = malloc(n * sizeof(double));
    double *dvdt = calloc(n, sizeof(double));

    // Create linspace
    double x_min = 0.0, x_max = 10.0;
    double dx = (x_max - x_min) / (n - 1);
    for (int i = 0; i < n; i++) {
        x[i] = x_min + i * dx;
        y[i] = exp(-pow(x[i] - 5.0, 2.0));
    }
    double dxsquared = dx * dx;

    double tmin = 0.0, tmax = 10.0;
    double dt_ideal = 0.5 * dx;
    int nt = (int)(tmax / dt_ideal) + 1;
    double dt = tmax / (nt - 1);

    double k = 1.0;

    // Time loop
    for (int step = 0; step < nt; step++) {
        // update accelerations
        for (int i = 1; i < n - 1; i++) {
            dvdt[i] = k * (y[i - 1] + y[i + 1] - 2.0 * y[i]) / dxsquared;
        }

        // update velocities
        for (int i = 0; i < n; i++) {
            v[i] += dvdt[i] * dt;
        }

        // update displacements
        for (int i = 0; i < n; i++) {
            y[i] += v[i] * dt;
        }
    }

    // Print final Y
    for (int i = 0; i < n; i++) {
        printf("%f\n", y[i]);
    }

    free(x);
    free(v);
    free(y);
    free(dvdt);

    return 0;
}
```
### Python equivalent (cleaned)
```python
import numpy as np

# Parameters
n = 2500
x = np.linspace(0, 10, n)
v = np.zeros(n)                     # velocity
y = np.exp(-(x - 5.0) ** 2)         # initial bump
dvdt = np.zeros(n)                  # acceleration

dx = x[1] - x[0]
dxsquared = dx * dx

tmin, tmax = 0.0, 10.0
dt_ideal = 0.5 * dx
nt = int(tmax / dt_ideal) + 1
tgrid = np.linspace(tmin, tmax, nt)
dt = tgrid[1] - tgrid[0]

k = 1.0

# Time loop
for t in tgrid:
    # update accelerations
    for i in range(1, n - 1):
        dvdt[i] = k * (y[i - 1] + y[i + 1] - 2.0 * y[i]) / dxsquared

    # update velocities
    for i in range(n):
        v[i] += dvdt[i] * dt

    # update positions
    for i in range(n):
        y[i] += v[i] * dt

# Final output
print(y)
```
## Profiling and measuring time
