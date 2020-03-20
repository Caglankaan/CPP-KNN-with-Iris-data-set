import random

f = open("test.data", "a")
for i in range(0,100):
    f.write(
        str(random.uniform(-5, 20))[:3]+","+
        str(random.uniform(-5, 20))[:3]+","+
        str(random.uniform(-5, 20))[:3]+","+
        str(random.uniform(-5, 20))[:3]+"\n"
    )

f.close()