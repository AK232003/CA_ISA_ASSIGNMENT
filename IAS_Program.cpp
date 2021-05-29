#include <bits/stdc++.h>
using namespace std;

/* "Creating Memory Space"
0) - a Value
M[0] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

1) - b Value
M[1] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};

2) - c Value
M[2] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

3) - Stores the result to compute a==b
M[3] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

4) - LOAD M(0)  SUB M(1)            
M[4] =  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

5) - STOR M(3)  LOAD -|M(3)|
M[5] =  {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
         0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

6) - JUMP + M(8, 20:39)  LOAD M(0)
M[6] =  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

7) - ADD M(1)  STOR M(2)
M[7] =  {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
         0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};

8) - HALT  LOAD M(0)
M[8] =  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

9) - SUB M(1)  STOR M(2)
M[9] =  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
         0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
10) - ------  HALT
M[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};*/

//Memory of the IAS Computer.
int M[1000][40] = 
{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},

        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
         0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},

        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
         0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},

        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
         0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
         1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void int_to_bin(long long signed int a,long long signed int l)
{
    if(a<0) 
    {
        M[l][0]=1;
        a=-a;
    }
    else M[l][0]=0;
    for(long long signed i=0;i<39;i++) {M[l][39-i]=a%2;a=a/2;}
}

void program()
{
    long long int ir=0,i;//ir-instruction register(8 bits)
    int mbr[40], ac[40], ibr[20];//mbr-memory buffer register(40 bits),ac-accumulator(40 bits),ibr-instruction buffer register(20 bits)
    for(i=0;i<40;i++) ac[i]=0;
    long long int mar = 0;//mar-memory address register(12 bits)
    long long int pc = 4, program_on = 1, Jump = 0;//pc-program counter
    while(program_on)
    {
        //FETCH PHASE AND DECODE PHASE
        if(!Jump)
        { 
            mar=pc;//passing location into mar.
            ir=0;
            for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//taking 40 bit instruction from that location and storing into mbr.
            for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,7-i));}//calculating ir for left opcode.
            if(ir!=0)
            {
                for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}//storing right instruction in ibr.
                mar=0;//reset mar..
                for(i=0;i<12;i++) {mar+=((mbr[8+i])*pow(2,11-i));}//storing left address in decimal in mar.
            }
            else
            {
                ir=0;
                for(i=0;i<8;i++) {ir+=((mbr[20+i])*pow(2,7-i));}//taking right opcode
                mar=0;//reset mar
                for(i=0;i<12;i++) {mar+=((mbr[28+i])*pow(2,11-i));}//storing right address in decimal in mar.
                pc++;//incrementing pc.
                Jump=1;//jumping to next instruction.
            }
        }
        else
        {
            ir=0;
            for(i=0;i<8;i++) {ir+=((ibr[i])*pow(2,7-i));}
            mar=0;
            for(i=0;i<12;i++) {mar+=((ibr[8+i])*pow(2,11-i));}
            pc++;
        }
        cout <<"IR code in decimal is: "<< ir << endl;

        //Execute phase
        switch(ir)
        {
            //LOAD M(mar).
            case 1:
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];ac[i]=mbr[i];}//storing M[mar] in mbr and mbr in ac.
                cout<<"LOAD COMPLETE"<<endl;
                long long int A;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
            //LOAD NEGATIVE MODULUS.    
            case 4:
                if(M[mar][0] == 0)
                    {mbr[0] = 1; ac[0] = 1;}//for negative case.
                else
                    {mbr[0] = 0; ac[0] = 0;}//for positive or zero case.
                for(i=1;i<40;i++) {mbr[i]=M[mar][i];ac[i]=mbr[i];}//storing M[mar] in mbr and mbr in ac.
                cout<<"LOAD NEGATIVE MOD COMPLETE"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
            //ADDITION
            case 5:
                long long signed int MBR,AC;
                AC=0;
                MBR=0;
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//ac[i]=mbr[i];}//storing M[mar] in mbr.
                for(i=1;i<40;i++) {MBR+=mbr[i]*pow(2,39-i);AC+=ac[i]*pow(2,39-i);}//calculating decimal values of mbr and ac.
                if(mbr[0]==1) MBR=-MBR; //negative case.
                if(ac[0]==1) AC=-AC;//negative case.
                AC=AC+MBR;
                if(AC>=0)
                 for(i=0;i<40;i++) {ac[39-i]=AC%2;AC=AC/2;}
                else
                {
                    AC=-AC;
                    for(i=0;i<39;i++) {ac[39-i]=AC%2;AC=AC/2;}
                    ac[0]=1;//to represent negative number.
                }
                cout<<"ADDITION COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
            //SUBTRACTION
            case 6:
                MBR=0,AC=0;
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//ac[i]=mbr[i];}//storing M[mar] in mbr.
                for(i=1;i<40;i++) {MBR+=mbr[i]*pow(2,39-i);AC+=ac[i]*pow(2,39-i);}//calculating decimal values of mbr and ac.
                if(mbr[0]==1) MBR=-MBR;//negative case.
                if(ac[0]==1) AC=-AC;//negative case.
                AC=AC-MBR;
                cout <<"MBR IS "<<MBR<<endl;
                cout << "Ac is "<<AC << endl;
                if(AC>=0)
                    for(i=0;i<40;i++) {ac[39-i]=AC%2;AC=AC/2;}
                else
                {
                    AC=-AC;
                    for(i=0;i<39;i++) {ac[39-i]=AC%2;AC=AC/2;}
                    ac[0]=1;//to represent negative number.
                }
                cout<<"SUBTRACTION COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
            //JUMP TO RIGHT
            case 16:
                if(ac[0]==0)
                {
                    pc=mar;
                    mar=pc;
                    ir=0;
                    for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//storing M[mar] in mbr.
                    for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,7-i));}//left opcode into ir.
                    for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}//right instruction into ibr.
                    mar=0;//reset mar.
                    for(i=0;i<12;i++) {mar+=((mbr[8+i])*pow(2,11-i));}//left address into mar.
                    Jump=0;
                }
                for(i=0;i<40;i++) ac[i]=0;//reset accumulator.
                cout<<"JUMP TO RIGHT "<<pc<<" COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}//decimal value of ac.
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
            //STOR
            case 33:
                for(i=0;i<40;i++) {mbr[i]=0;}//reset mbr.
                for(i=0;i<40;i++) {mbr[i]=ac[i];}//ac into mbr.
                for(i=0;i<40;i++) {M[mar][i]=mbr[i];}//mbr into M[mar].
                cout<<"STORAGE DONE!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;                
                break;
            //HALT-To stop running.
            case 255:
                program_on=0;
                cout<<"HALT!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<"AC is: "<<A<<endl;
                else 
                    cout<<"AC is: "<<"-" << A <<endl;
                break;
        }
        Jump=!Jump;
    }
    long long unsigned int AC=0;
    for(i=1;i<40;i++) {AC+=M[2][i]*pow(2,39-i);}//calculating ac value in decimal as stored in binary.
    cout << endl;
    if(M[2][0] == 0) 
        cout<<"C value is: "<<AC<<endl;
    else 
        cout<<"C value is: "<<"-" << AC <<endl;
}

int main()
{
    long long signed int a,b;
    cout <<"Enter 'a' value" <<endl;
    cin>>a;
    int_to_bin(a,0);
    cout <<"Enter 'b' value" <<endl;
    cin>>b;
    int_to_bin(b,1);
    cout << "Memory Creation ---> Success" << endl;
    cout << endl;
    program();
}
