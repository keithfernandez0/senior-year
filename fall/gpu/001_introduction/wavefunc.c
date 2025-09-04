#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    clock_t start_time = clock();
    clock_t end_time;   // declare once
    double cpu_time;

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

    double tmax = 10.0;
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

    end_time = clock();  // reuse existing variable
    cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", cpu_time);

    return 0;
}

