import numpy as np
import subprocess
import matplotlib.pyplot as plt

# a and b are the finite end points given in the question
a = 12   # first function:  5x - 2     runs from -infinity to a
b = 1    # second function: x^3 + x^2 + 1 runs from b to +infinity
print("a =", a)
print("b =", b)

# infinity cannot be plotted, so a large number stands in for it
L = 50

x1 = np.linspace(-L, a, 400)
y1 = 5 * x1 - 2

x2 = np.linspace(b, L, 400)
y2 = x2**3 + x2**2 + 1

plt.figure(figsize=(8, 5))
plt.plot(x1, y1, label="5x - 2  (-inf to 12)")
plt.plot(x2, y2, label="x^3 + x^2 + 1  (1 to inf)")
plt.xlabel("x")
plt.ylabel("y")
plt.title("Graphs of the two functions")
plt.grid(True)
plt.legend()
plt.savefig("graph.pdf")
subprocess.Popen(['termux-open','graph.pdf'])
