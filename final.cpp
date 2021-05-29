#include <bits/stdc++.h>
using namespace std;

/*
INSTRUCTION SPACE
100 1 M(0)               // ac = a
    6 M(1)                // ac = ac - b
101 33 M(3)               // M(3) = ac = a - b
    1 -|M(3)|            // ac = -|a - b|  <=0
102 JUMP + M(104,20:39)     // if(ac >= 0)  => ac==0
    1 M(0)               // ac = a
103 5 M(1)                // ac = ac + b
    33 M(2)               // M(2) = ac = a + b
104 255                    // STOP
    1 M(0)               // ac = a
105 6 M(1)                // ac = ac - b
    33 M(2)               // M(2) = ac = a - b
106 ----
    255                    // STOP
*/
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

void memory_creation()
{
    /*//Creating Memory Space
    // a Value
    M[0] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // b Value
    M[1] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    // c Value
    M[2] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //stores the result to compute a==b
    M[3] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 100 1 M(0)  6 M(1)            
    M[4] =   {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // 101 33 M(3)  4 M(3)
    M[5] =   {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
                0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
     102 16 M(8)  1 M(0)
    M[6] =  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 103 5 M(1) 33 M(2)
    M[7] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    // 104 255  1 M(0)
    M[8] =  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 105 6 M(1)  33 M(2)
    M[9] = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    // 106 0  255
    M[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};*/
    /*M[][40] = 
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
    cout << "Memory Creation ---> Success" << endl;*/
}

//typedef long long unsigned int ll

void program()
{
    long long int ir=0,i,temp;//ir-instruction register(8 bits)
    int mbr[40], ac[40], ibr[20];//mbr-memory buffer register(40 bits),ac-accumulator(40 bits),ibr-instruction buffer register(20 bits)
    for(i=0;i<40;i++) ac[i]=0;
    long long int mar = 0;//mar-memory address register(12 bits)
    long long int pc = 4, program_on = 1, Jump = 0;//pc-program counter
    temp=pc;
    while(program_on)
    {
        //fetch cycle
        if(!Jump)
        {
            //for(i=0;i<12;i++) {mar[i]=temp%2;temp=temp/2;} 
            mar=pc;//passing location into mar.
            ir=0;
            for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//taking 40 bit instruction from that location and storing into mbr.
            for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,7-i));}//calculatig ir for left opcode.
            if(ir!=0)
            {
                for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}//storing right instruction in ibr.
                mar=0;//reset mar..
                for(i=0;i<12;i++) {mar+=((mbr[8+i])*pow(2,11-i));}//storing left address in decimal in mar.
                //pc++;
            }
            else
            {
                ir=0;
                for(i=0;i<8;i++) {ir+=((mbr[20+i])*pow(2,7-i));}//taking right opcode
                mar=0;//reset mar
                for(i=0;i<12;i++) {mar+=((mbr[28+i])*pow(2,11-i));}//storing right address in decimal in mar.
                pc++;//incrementing pc.
                Jump=1;//jumping to next instruction
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
        cout << ir << endl;
        //Execute phase
        //cout<<"fetch cycle completed!!"<<endl<<"decode cycle completed!!"<<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
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
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;                
                break;
            //HALT-To stop running.
            case 255:
                program_on=0;
                cout<<"HALT!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
        }
        Jump=!Jump;
    }
    long long unsigned int AC=0;
    for(i=1;i<40;i++) {AC+=M[2][i]*pow(2,39-i);}//calculating ac value in decimal as stored in binary.
    if(M[2][0] == 0) 
        cout<<AC<<endl;
    else 
        cout<<"-" << AC <<endl;
    //cout<<M[2]<<endl;
}

int main()
{
    //memory_creation();
    program();
}
