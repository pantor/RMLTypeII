#!/usr/bin/python3

import pylab

def plotCSV(file):
    data = pylab.loadtxt(file, delimiter=',')

    dof = int( (len(data[0]) - 1) / 2 )

    for i in range(dof):
        pylab.plot(data[:, -1], data[:, i], label='x_{}'.format(i))
        pylab.plot(data[:, -1], data[:, dof + i], label='v_{}'.format(i))

    pylab.legend()
    pylab.grid(True, which="both", ls="-")
    pylab.xlabel("Time t [s]")
    pylab.show()

if __name__ == "__main__":
    plotCSV('../build/output.csv')
