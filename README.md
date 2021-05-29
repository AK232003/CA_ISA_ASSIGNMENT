# IAS COMPUTER

-------------------------------------------------------------------------------------

**PROJECT DISCRIPTION **
   
    Language used to design this project is C++
    The aim of this project is to create an IAS Computer which can execute a particular C program.

    There are three phases of this IAS Computer:
        1)Fetch  -  In this phase the Program Counter(PC) value is moved to the Memory Address Register(MAR)
                    and the value at the memory location MAR is fed into the Memory Buffer Register(MBR).
                    Once this is done, the OPCODE of the LEFT instruction is loaded into the Instruction 
                    Register(IR)and the address portion is loaded into the MAR and the right instruction is 
                    loaded into the Instruction Buffer Register(IBR).

        2)Decode -  In this phase the data stored in the registers is decoded based on the instruction OPCODE 
                    value and the corresponding control signals are sent to move the data around or 
                    perform specific tasks. The "binary data" is well read and converted into an assembly
                    language for the execute phase. 
        
        3)Execute - In this phase the ALU performs the tasks as specified by the assembly language for a 
                    particular C program.
    
    >> Steps to run the code:
        STEP 1: Compile the c++ code using "g++ IAS_Program.cpp", a new executable is generated in the current
                repository.
        STEP 2: To run the executable, use "./a.out".
        STEP 3: The program will then require 'a' & 'b' values which can be input by the user.
                Press "ENTER" key to run the program. 

-------------------------------------------------------------------------------------

Note : We are going to implement the C code as coded in "implementation.c" in the IAS Machine as our base code.

-------------------------------------------------------------------------------------

***MEMORY SPACE***
M(0)    -       'a' value
M(1)    -       'b' value
M(2)    -       'c' value
M(3)    -       'garbage' value to compute if(a==b)
M(4)    -       LOAD M(0)           SUB M(1)
M(5)    -       STOR M(3)           LOAD -|M(3)|
M(6)    -       JUMP + M(8, 20:39)  LOAD M(0)
M(7)    -       ADD M(1)            STOR M(2)
M(8)    -       HALT                LOAD M(0)
M(9)    -       SUB M(1)            STOR M(2)
M(10)   -       --------            HALT

-------------------------------------------------------------------------------------
**Github link for the above project**: https://github.com/AK232003/CA_ISA_ASSIGNMENT.git
-------------------------------------------------------------------------------------
***CONTRIBUTORS***
IMT2020084 - ARYA KONDAWAR
IMT2020554 - ANSHUL MADURWAR

-------------------------------------------------------------------------------------

