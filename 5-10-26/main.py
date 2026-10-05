#Code by T.Pranay
#Date:- 5-9-26

import subprocess
import numpy as np
import matplotlib.pyplot as plt

# Preliminary information for students
print("For the system of equations: kx + y = 1 and x + ky = -1")
print("• If k = -1: The system has NO SOLUTION (Parallel Lines).")
print("• If k =  1: The system has INFINITE SOLUTIONS (Coincident Lines).")
print("• Any other value: The system has a UNIQUE SOLUTION (Intersecting Lines).")

# 1. Take student input for k
try:
    k_input = input("Enter the value for k: ")
    k = float(k_input)
except ValueError:
    print("Invalid input. Defaulting to k = 2.0")
    k = 2.0

# Define coefficient matrix A and augmented matrix Ab explicitly by individual scalars
A = np.array([[k, 1.0], 
              [1.0, k]], dtype=float)

Ab = np.array([[k, 1.0, 1.0], 
               [1.0, k, -1.0]], dtype=float)

print("\n--- Initial Matrices ---")
print("Coefficient Matrix A:\n", A)
print("Augmented Matrix [A | B]:\n", Ab)

# Calculate ranks using NumPy's built-in tool
rank_A = np.linalg.matrix_rank(A)
rank_Ab = np.linalg.matrix_rank(Ab)

print(f"\nRank of Coefficient Matrix A: {rank_A}")
print(f"Rank of Augmented Matrix [A | B]: {rank_Ab}")

# 2. Standard Row Operations (Row-by-Row Element Assignment)
print("\n--- Visualizing Row Operations ---")

# Step 1: Swap Row 1 and Row 2 so the first row pivot is 1 (simplifies math for k)
print("Operation: Swap Row 1 and Row 2")
r1 = np.array([Ab[1, 0], Ab[1, 1], Ab[1, 2]])
r2 = np.array([Ab[0, 0], Ab[0, 1], Ab[0, 2]])

# Re-assemble the matrix with swapped rows
M = np.array([r1, r2])
print(M)

# Step 2: Make the element below the first pivot 0 (R2 = R2 - k * R1)
factor = k
print(f"Operation: Row 2 = Row 2 - ({factor}) * Row 1")
M[1, 0] = M[1, 0] - factor * M[0, 0]
M[1, 1] = M[1, 1] - factor * M[0, 1]
M[1, 2] = M[1, 2] - factor * M[0, 2]
print(M)

# Step 3: Standardize Row 2 by dividing it by its row 2 pivot element (if not zero)
pivot_22 = M[1, 1]
if abs(pivot_22) > 1e-9:
    print(f"Operation: Row 2 = Row 2 / {pivot_22:.4f}")
    M[1, 0] = M[1, 0] / pivot_22
    M[1, 1] = M[1, 1] / pivot_22
    M[1, 2] = M[1, 2] / pivot_22
    print(M)

    # Step 4: Back-substitution to clear above the pivot (R1 = R1 - R1_2 * R2)
    factor_up = M[0, 1]
    print(f"Operation: Row 1 = Row 1 - ({factor_up:.4f}) * Row 2")
    M[0, 0] = M[0, 0] - factor_up * M[1, 0]
    M[0, 1] = M[0, 1] - factor_up * M[1, 1]
    M[0, 2] = M[0, 2] - factor_up * M[1, 2]
    print(M)

print("\nFinal Row Reduced Echelon Form:\n", np.round(M, 4))

# 3. Plot the Graph and Save it as an Image
x = np.linspace(-10, 10, 400)
y1 = 1 - k * x

plt.figure(figsize=(8, 6))
plt.plot(x, y1, label=f'{k}x + y = 1', color='blue')

if abs(k) > 1e-9:
    y2 = (-1 - x) / k
    plt.plot(x, y2, label=f'x + {k}y = -1', color='red')
else:
    plt.axvline(x=-1, color='red', label='x = -1')

plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True, linestyle='--', alpha=0.6)
plt.title(f'System of Line Equations for k = {k}')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()

image_filename = "graph.pdf"
plt.savefig(image_filename, bbox_inches='tight')
plt.close()
print(f"\nGraph saved locally as '{image_filename}'")

# 4. Open the image file via subprocess using OS default viewer
subprocess.Popen(['termux-open','graph.pdf'])
