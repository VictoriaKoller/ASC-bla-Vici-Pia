# search for libraray like bla.cpython-312-darwin.so in the build directory:
import sys, os
sys.path.append(r"C:\Users\victo\Documents\vivi\university\Semester5\ScientificComputing\Vici_Pia_repository\ASC-bla-Vici-Pia\build")
os.add_dll_directory(r"C:\msys64\ucrt64\bin")
from bla import Vector

# import from the installed ASCsoft package:
#from ASCsoft.bla import Vector

x = Vector(3)
y = Vector(3)

for i in range(len(x)):
    x[i] = i
y[:] = 2    

print ("x =", x)
print ("y =", y)
print ("x+3*y =", x+3*y)


x = Vector(10)
x[0:] = 1
print (x)

x[3:7] = 2
print (x)

x[0:10:2] = 3
print (x)



