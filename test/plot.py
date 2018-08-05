#!/usr/bin/python3

import pylab


data = pylab.loadtxt('build/output.txt', delimiter=',')

pylab.plot(data[:, 0], label='x')
pylab.plot(data[:, 1], label='v')
pylab.plot(data[:, 2], label='a')

pylab.legend()
pylab.grid(True, which="both", ls="-")
pylab.xlabel("Time step t")
pylab.show()