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

//#define 1 1
//#define 4 4
//#define 5 5
//#define 6 6
//#define 16 16
//#define 33 33
//#define 0 0
//#define 255 255

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
    //if(a>=0) B[0]=0;
}
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
    long long int ir=0,i,temp;
    int mbr[40], ac[40], ibr[20];
    for(i=0;i<40;i++) ac[i]=0;
    long long int mar = 0;
    long long int pc = 4, program_on = 1, Jump = 0;
    temp=pc;
    while(program_on)
    {
        //fetch cycle
        if(!Jump)
        {
            //for(i=0;i<12;i++) {mar[i]=temp%2;temp=temp/2;} 
            mar=pc;
            ir=0;
            for(i=0;i<40;i++) {mbr[i]=M[mar][i];}
            for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,7-i));}
            if(ir!=0)
            {
                for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}
                mar=0;
                for(i=0;i<12;i++) {mar+=((mbr[8+i])*pow(2,11-i));}
                //pc++;
            }
            else
            {
                ir=0;
                for(i=0;i<8;i++) {ir+=((mbr[20+i])*pow(2,7-i));}
                mar=0;
                for(i=0;i<12;i++) {mar+=((mbr[28+i])*pow(2,11-i));}
                pc++;
                Jump=1;
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
        //cout<<"fetch cycle completed!!"<<endl<<"decode cycle completed!!"<<endl;
        switch(ir)
        {
            case 1:
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];ac[i]=mbr[i];}
                cout<<"LOAD COMPLETE"<<endl;
                long long int A;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
            case 4:
                if(M[mar][0] == 0)
                    {mbr[0] = 1; ac[0] = 1;}
                else
                     {mbr[0] = 0; ac[0] = 0;}
                for(i=1;i<40;i++) {mbr[i]=M[mar][i];ac[i]=mbr[i];}
                cout<<"LOAD NEGATIVE MOD COMPLETE"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
            case 5:
                long long signed int MBR,AC;
                AC=0;
                MBR=0;
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//ac[i]=mbr[i];}
                for(i=1;i<40;i++) {MBR+=mbr[i]*pow(2,39-i);AC+=ac[i]*pow(2,39-i);}
                if(mbr[0]==1) MBR=-MBR; 
                if(ac[0]==1) AC=-AC;
                AC=AC+MBR;
                if(AC>=0)
                 for(i=0;i<40;i++) {ac[39-i]=AC%2;AC=AC/2;}
                else
                {
                    AC=-AC;
                    for(i=0;i<39;i++) {ac[39-i]=AC%2;AC=AC/2;}
                    ac[0]=1;
                }
                cout<<"ADDITION COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
            case 6:
                MBR=0,AC=0;
                for(i=0;i<40;i++) {mbr[i]=M[mar][i];}//ac[i]=mbr[i];}
                for(i=1;i<40;i++) {MBR+=mbr[i]*pow(2,39-i);AC+=ac[i]*pow(2,39-i);}
                if(mbr[0]==1) MBR=-MBR; 
                if(ac[0]==1) AC=-AC;
                AC=AC-MBR;
                cout <<"MBR IS "<<MBR<<endl;
                cout << "Ac is "<<AC << endl;
                if(AC>=0)
                    for(i=0;i<40;i++) {ac[39-i]=AC%2;AC=AC/2;}
                else
                {
                    AC=-AC;
                    for(i=0;i<39;i++) {ac[39-i]=AC%2;AC=AC/2;}
                    ac[0]=1;
                }
                cout<<"SUBTRACTION COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
            
            case 16:
                if(ac[0]==0)
                {
                    pc=mar;
                    mar=pc;
                    ir=0;
                    for(i=0;i<40;i++) {mbr[i]=M[mar][i];}
                    for(i=0;i<8;i++) {ir+=((mbr[i])*pow(2,7-i));}
                    for(i=0;i<20;i++) {ibr[i]=mbr[20+i];}
                    mar=0;
                    for(i=0;i<12;i++) {mar+=((mbr[8+i])*pow(2,11-i));}
                    Jump=0;
                }
                for(i=0;i<40;i++) ac[i]=0;
                cout<<"JUMP TO RIGHT "<<pc<<" COMPLETED!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;
                break;
            case 33:
                for(i=0;i<40;i++) {mbr[i]=0;}
                for(i=0;i<40;i++) {mbr[i]=ac[i];}
                for(i=0;i<40;i++) {M[mar][i]=mbr[i];}
                cout<<"STORAGE DONE!!"<<endl;
                A = 0;
                for(i=1;i<40;i++) {A+=ac[i]*pow(2,39-i);}
                if(ac[0] == 0) 
                    cout<<A<<endl;
                else 
                    cout<<"-" << A <<endl;                
                break;
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
    for(i=1;i<40;i++) {AC+=M[2][i]*pow(2,39-i);}
    if(M[2][0] == 0) 
        cout<<AC<<endl;
    else 
        cout<<"-" << AC <<endl;
    //cout<<M[2]<<endl;
}

int main()
{
    //memory_creation();
    long long signed int a,b;
    cout <<"Enter 'a' value" <<endl;
    cin>>a;
    int_to_bin(a,0);
    cout <<"Enter 'b' value" <<endl;
    cin>>b;
    int_to_bin(b,1);
    program();
}
