#code by pranay

import numpy as np
import subprocess
import matplotlib.pyplot as plt

C = 1/21
x = np.linspace(0, 5, 500)
p = np.where((x >= 1) & (x <= 4), C * x**2, 0)

plt.plot(x, p, label="P(x) = x²/21")
xs = np.linspace(2, 3, 100)
plt.fill_between(xs, C * xs**2, alpha=0.4, label="P(2 ≤ x ≤ 3) ≈ 0.302")
plt.xlabel("x"); plt.ylabel("P(x)")
plt.legend(); plt.grid(True)
plt.savefig("graph.pdf")
subprocess.Popen(["termux-open","graph.pdf"])
