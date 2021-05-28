#include <bits/stdc++.h>
using namespace std;

/*
INSTRUCTION SPACE
100 LOAD M(0)               // ac = a
    SUB M(1)                // ac = ac - b
101 STOR M(3)               // M(3) = ac = a - b
    LOAD -|M(3)|            // ac = -|a - b|  <=0
102 JUMP + M(104,20:39)     // if(ac >= 0)  => ac==0
    LOAD M(0)               // ac = a
103 ADD M(1)                // ac = ac + b
    STOR M(2)               // M(2) = ac = a + b
104 HALT                    // STOP
    LOAD M(0)               // ac = a
105 SUB M(1)                // ac = ac - b
    STOR M(2)               // M(2) = ac = a - b
106 ----
    HALT                    // STOP
*/

#define LOAD 1
#define LOAD_Negative_Mod 4
#define ADD 5
#define SUB 6
#define JUMP_TO_RIGHT 16
#define STOR 33
#define EMPTY 0
#define HALT 255

int M[1000][40];

void memory_creation()
{
    //Creating Memory Space
    // a Value
    M[0][] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // b Value
    M[1][] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    // c Value
    M[2][] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //stores the result to compute a==b
    M[3][] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 100 LOAD M(0)  SUB M(1)            
    M[100][] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // 101 STOR M(3)  LOAD_Negative_Mod M(3)
    M[101][] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
                0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
    // 102 JUMP_TO_RIGHT M(104)  LOAD M(0)
    M[102][] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 103 ADD M(1) STOR M(2)
    M[103][] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    // 104 HALT  LOAD M(0)
    M[104][] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 105 SUB M(1)  STOR M(2)
    M[105][] = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    // 106 EMPTY  HALT
    M[106][] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << "Memory Creation ---> Success" << endl;
}

//typedef long long unsigned int ll

void program()
{
    int ir=0,i,temp;
    int mbr[40], ac[40], ibr[20];
    long long int mar;
    int pc = 100, program_on = 1, Jump = 0;
    temp=pc;
    while(program_on)
    {
        //fetch cycle
        if(!Jump)
        {
            //for(i=0;i<12;i++) {mar[i]=temp%2;temp=temp/2;} 
            mar=pc;
            for(i=0;i<40;i++) {mbr[i]=M[mar][i];}
            for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,i));}
            if(ir!=0)
            {
                for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}
                mar=0;
                for(i=0;i<12;i+=) {mar+=((mbr[8+i])*pow(2,i));}
                //Jump=1;
            }
        
            else
            {
                for(i=0;i<8;i++) {ir+=((mbr[20+i])*pow(2,i));}
                mar=0;
                for(i=0;i<12;i+=) {mar+=((mbr[28+i])*pow(2,i));}
                pc++;
                Jump=1;
            }
        }
        else
        {
            for(i=0;i<8;i++) {ir+=((ibr[i])*pow(2,i));}
            mar=0;
            for(i=0;i<12;i+=) {mar+=((ibr[8+i])*pow(2,i));}
            pc++;
        }
        //Execute phase
        switch(ir)
        {
            case LOAD:



        }

}

