# Main Memory of a IAS Computer

class MM():
    def __init__(self):
        self.memory = [['0']*40]*20

    def getData(self, loc):
        return self.memory[loc]

    def setData(self, loc, data):
        self.memory[loc] = data
# Program Control Unit of a IAS Computer

# Arithmatic Logic Unit of a IAS Computer

# Accumulator
class AC():

    def __init__(self):
        self.data = ['0']*40

    def getData(self):
        return self.data

    def setData(self, data):
        self.data = data

# Arithmatic Logic Circuits
class ALC():
    def ADD(self, MBR, AC):
        val = binToDec(MBR.getBuffer()) + binToDec(AC.getData())
        newVal = decToBin(val)
        AC.setData(padding(newVal, 40))

    def SUB(self, MBR, AC):
        val = binToDec(MBR.getBuffer()) - binToDec(AC.getData())
        newVal = decToBin(val)
        AC.setData(padding(newVal, 40))

    def LOAD (self, MBR,AC):
        AC.setData(MBR.getBuffer())

    def STORE (self, MBR, AC):
        MBR.setBuffer(AC.getData())


# Memory Buffer Register
class MBR():

    def __init__(self):
        self.buffer = ['0']*40

    def getBuffer(self):
        return self.buffer

    def setBuffer(self, buffer):
        self.buffer = buffer


# FUNCTIONS
def decToBin(n): #function for converting decimal to binary
    b = []
    while(n>0):
        b.append(str(n%2))
        n = n//2
    b = b[::-1]
    return b


def binToDec(l): #function for converting binary to decimal
    l = l[::-1]
    j = 0
    temp = 0
    for i in l:
        temp += int(i)*pow(2,j)
        j += 1
    return temp

def padding(list, n): #funtion for adding padding to the converted binary list
    l = len(list)
    for i in range(n-l):
        list.insert(0,'0')
    return list

# Instruction Buffer Register
class IBR():
    def __init__(self):
        self.data = ['0']*20

    def getData(self):
        return self.data

    def setInstruction (self, data):
        self.data = data[20:40]

    def reset(self):
        self.data = ["0"]*20


# Program Counter
class PC():

    def __init__(self):
        self.address = 0

    def incrementPC(self):
        self.address += 1


# Instruction Register
class IR():
    def __init__(self):
        self.opcode = ['0']*8

    def getOpcode(self):
        return self.opcode

    def setOpcode(self, data):
        self.opcode = data[0:8]


# Memory Address Register
class MAR():
    def __init__(self):
        self.address = ['0']*12

    def getAddress(self):
        return self.address

    def setAddress(self, data):
        self.address = data[8:20]
    
def Fetch(): # fetch function
    if (binToDec(IBR.getData())): # condition for right instruction
        print("Fetching the right command")
        IR.setOpcode(IBR.getData()) # MBR --> IR
        MAR.setAddress(IBR.getData()) # MBR --> MAR
        IBR.reset()
        PC.incrementPC()

    else: # fetches left instruction
        print("Fetching the left command")
        MAR.setAddress(padding(decToBin(PC.address), 12)) #add padding # PC --> MAR
        #print(MAR.getAddress())
        MBR.setBuffer(MM.getData(binToDec(MAR.getAddress()))) # MM --> MBR
        #print(MBR.getBuffer())
        IBR.setInstruction(MBR.getBuffer()) # MBR --> IBR
        #print(IBR.getData())
        IR.setOpcode(MBR.getBuffer()) # MBR --> IR
        #print(IR.getOpcode())
        MAR.setAddress(MBR.getBuffer()) # MBR --> MAR
        #print(MAR.getAddress())


def Decode(): # decode function
    opcode = binToDec(IR.getOpcode())
    print("Decoding the fetched command")
    return opcode


def Execute(opcode): # Execute function
    # executing load
    if opcode == 1:
        MBR.setBuffer(MM.getData(binToDec(MAR.getAddress())))
        ALC.LOAD(MBR, AC)

    # executing add
    elif opcode == 5:
        MBR.setBuffer(MM.getData(binToDec(MAR.getAddress())))
        ALC.ADD(MBR, AC)

    # executing store
    elif opcode == 33:
        ALC.STORE(MBR, AC) # AC --> MBR
        MM.setData(binToDec(MAR.getAddress()), MBR.getBuffer())

    # executing subtract
    elif opcode == 6:
        MBR.setBuffer(MM.getData(binToDec(MAR.getAddress())))
        ALC.SUB(MBR, AC)

    # executing left jump
    elif opcode == 13:
        PC.address = binToDec(MAR.getAddress())
        IBR.reset()

    # executing right jump
    elif opcode == 14:
        PC.address = binToDec(MAR.getAddress())
        IBR.reset()
        Fetch()
    print("Executing the fetched command"),
    print(opcode)

# intialising the parts

# main memory
MM = MM()

# PCU
IBR = IBR()
IR = IR()
MAR = MAR()
PC = PC()

# ALU
AC = AC()
ALC = ALC()
MBR = MBR()


# First set of input
# 0  LOAD (2) ADD(3)
# 1 ADD (4) STOR (5)
# 2 DATA --> 10
# 3 DATA --> 5
# 4 DATA --> 6
# 5 DATA TO BE
# data1 =  ['0','0','0','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','0','1','0',
#           '0','0','0','0','0','1','0','1',   '0','0','0','0','0','0','0','0','0','0','1','1']
#
# MM.setData(0, data1)
#
# data2 =  ['0','0','0','0','0','1','0','1',   '0','0','0','0','0','0','0','0','0','1','0','0',
#           '0','0','1','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','1','0','1']
#
# MM.setData(1, data2)
#
# data3 =  ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
#           '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','1','0','1','0']
#
# MM.setData(2,data3)
#
# data4 = ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
#          '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','1','0','1']
#
# MM.setData(3, data4)
#
# data5 = ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
#          '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','1','1','0']
#
# MM.setData(4,data5)

# Second set of input including jump function.
# 0 : LOAD M(1) JUMP M(2,20:39)
# 1 : DATA(10)
# 2 : ADD M(3) STOR M(3)
# 3 : DATA(5)
data0 =  ['0','0','0','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','0','0','1',
          '0','0','0','0','1','1','1','0',   '0','0','0','0','0','0','0','0','0','0','1','0']

MM.setData(0, data0)

data1 =  ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
          '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','1','0','1','0']

MM.setData(1, data1)

data2 =  ['0','0','0','0','0','1','0','1',   '0','0','0','0','0','0','0','0','0','0','1','1',
          '0','0','1','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','0','1','1']

MM.setData(2,data2)

data3 = ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
         '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','1','0','1']

MM.setData(3, data3)

# main loop
while(True):
    Fetch()
    opcode = Decode()
    if(opcode == 0):
        break
    Execute(opcode)
