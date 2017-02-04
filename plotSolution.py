#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

x, rho, u, p = np.loadtxt("solution00000.dat", unpack=True, skiprows=1)

plt.figure("Property distribution plots")
plt.plot(x, rho / np.max(rho), lw=3, label="$\\rho/\\rho_{max}$")
plt.plot(x, u / np.max(u), lw=3, label="$u/u_{max}$")
plt.plot(x, p / np.max(p), lw=3, label="$p/p_{max}$")
plt.xlim((np.min(x), np.max(x)))
plt.xlabel("$x$", fontsize=18)
plt.ylabel("$\\rho/\\rho_{max}$, $u/u_{max}$, $p/p_{max}$", fontsize=18)
plt.grid()
plt.legend(loc="best")

plt.show()
