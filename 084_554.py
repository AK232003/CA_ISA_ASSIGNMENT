# Main Memory of a IAS Computer
memory = [['0']*40]*20



# Accumulator
AC_data = ['0']*40
MBR_buffer=['0']*40
IBR_data=['0']*20
PC=0
opcode = ['0']*8
MAR_address=['0']*12

def ADD(a, b):
        val = binToDec(a) + binToDec(b)
        newVal = decToBin(val)
        b=(padding(newVal, 40))

def SUB(a, b):
        val = binToDec(a) - binToDec(b)
        newVal = decToBin(val)
        b=(padding(newVal, 40))

def LOAD (a,b):
        b=a

def STORE (a,b):
    a=b

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

def Fetch(): # fetch function
    global IBR_data,PC,opcode,MAR_address,MBR_buffer
    if (binToDec(IBR_data)): # condition for right instruction
        print("Fetching the right command")
        opcode=(IBR_data[0:8]) # MBR --> IR
        MAR_address=(IBR_data[8:20]) # MBR --> MAR
        IBR_data=['0']*20
        PC+=1

    else: # fetches left instruction
        print("Fetching the left command")
        MAR_address=(padding(decToBin(PC), 12)[8:20]) #add padding # PC --> MAR
        #print(MAR.getAddress())
        MBR_buffer=(memory[(binToDec(MAR_address))]) # MM --> MBR
        #print(MBR.getBuffer())
        IBR_data=(MBR_buffer[20:40]) # MBR --> IBR
        #print(IBR.getData())
        opcode=(MBR_buffer[0:8]) # MBR --> IR
        #print(IR.getOpcode())
        MAR_address=(MBR_buffer[8:20]) # MBR --> MAR
        #print(MAR.getAddress())


def Decode(): # decode function
    global opcode
    opcode = binToDec(opcode)
    print("Decoding the fetched command")
    return opcode


def Execute(opcode): # Execute function
    # executing load
    global MBR_buffer,MAR_address,PC,IBR_data
    if opcode == 1:
        MBR_buffer=(memory[(binToDec(MAR_address))])
        LOAD(MBR_buffer, AC_data)

    # executing add
    elif opcode == 5:
        MBR_buffer=(memory[(binToDec(MAR_address))])
        ADD(MBR_buffer, AC_data)

    # executing store
    elif opcode == 33:
        STORE(MBR_buffer, AC_data) # AC --> MBR
        memory[binToDec(MAR_address)]=MBR_buffer

    # executing subtract
    elif opcode == 6:
        MBR_buffer(memory[(binToDec(MAR_address))])
        SUB(MBR_buffer, AC_data)

    # executing left jump
    elif opcode == 13:
        PC = binToDec(MAR_address)
        IBR_data=['0']*20

    # executing right jump
    elif opcode == 14:
        PC = binToDec(MAR_address)
        IBR_data=['0']*20
        Fetch()
    print("Executing the fetched command"),
    print(opcode)

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
memory[0]=  ['0','0','0','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','0','0','1',
             '0','0','0','0','1','1','1','0',   '0','0','0','0','0','0','0','0','0','0','1','0']

#MM.setData(0, data0)
#
memory[1] =  ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
              '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','1','0','1','0']
#
#MM.setData(1, data1)
#
memory[2] =  ['0','0','0','0','0','1','0','1',   '0','0','0','0','0','0','0','0','0','0','1','1',
              '0','0','1','0','0','0','0','1',   '0','0','0','0','0','0','0','0','0','0','1','1']
#
#MM.setData(2,data2)
#
memory[3] = ['0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','0','0','0',
             '0','0','0','0','0','0','0','0',   '0','0','0','0','0','0','0','0','0','1','0','1']
#
#MM.setData(3, data3)

# main loop
while(True):
    Fetch()
    opcode = Decode()
    if(opcode == 0):
        break
    Execute(opcode)
