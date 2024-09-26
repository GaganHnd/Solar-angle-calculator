#include<iostream>
using namespace std;
class position
{
    private: 
        float sum_tilt, win_tilt, spr_tilt, avg_tilt; 
        const int Chennai[15]={29, 21, 13, 5, 180, 180, 180, 5, 13, 21, 29, 36, 180, 36, 13};
        const int Kolkata[15]={39, 31, 23, 15, 7, 0, 7, 15, 23, 31, 39, 46, 0, 46, 23};
        const int Delhi[15]={45, 37, 29, 21, 13, 6, 13, 21, 29, 37, 45, 52, 6, 52, 29};
        const int Mumbai[15]={35, 27, 19, 11, 3, 180, 3, 11, 19, 27, 35, 42, 180, 42, 19};
        const int Bengaluru[15]={29, 21, 13, 5, 180, 180, 180, 5, 12, 21, 29, 36, 180, 36, 13};
        void calc(float lati)
        {
        sum_tilt=((lati*0.9) - 23.5);
        win_tilt=((lati*0.9) + 29);
        spr_tilt=((lati-2.5));
        avg_tilt=(sum_tilt + win_tilt + spr_tilt)/3 ;
        }
    public: 
        float lati;
        void setdata(float lati1);
        void getdata();
        void quickmode();
};
void position ::quickmode()
{
    int choice;
    do{
        cout<<" 1.\t Bengaluru"<<endl<<" 2. \t Chennai"<<endl<<" 3. \t Delhi"<<endl<<" 4. \t Kolkata"<<endl<<" 5. \t Mumbai"<<endl;
        cout<<"Enter the number corresponding to the desired city or 0 to EXIT:";
        cin>>choice;
        if (choice==1 || choice==2 || choice==3 || choice==4 || choice==5)
        {
            cout<<endl<<endl;
            if(choice==1)
            cout<<" \t\t\t\tYou selected BENGALURU"<<endl<<endl;
            else if(choice==2)
            cout<<" \t\t\t\tYou selected CHENNAI"<<endl<<endl;
            else if(choice==3)
            cout<<" \t\t\t\tYou selected DELHI"<<endl<<endl;
            else if(choice==4)
            cout<<" \t\t\t\tYou selected KOLKATA"<<endl<<endl;
            else
            cout<<" \t\t\t\tYou selected MUMBAI"<<endl<<endl;
            cout<<"Jan\tFeb\tMar\tApr\tMay\tJune\tJuly\tAug\tSep\tOct\tNov\tDec"<<endl;
        for (int i=0; i<12; i++)
        {
            if(choice==1)
            cout<<Bengaluru[i]<<"\t";
            else if(choice==2)
            cout<<Chennai[i]<<"\t";
            else if(choice==3)
            cout<<Delhi[i]<<"\t";
            else if(choice==4)
            cout<<Kolkata[i]<<"\t";
            else
            cout<<Mumbai[i]<<"\t";       
        }
        cout<<endl<<"The average angle over a season for the selected city:"<<endl;
        cout<<endl<<"Summer\tWinter\tSpring/Autumn"<<endl;
        if(choice==1)
            cout<<Bengaluru[12]<<"\t"<<Bengaluru[13]<<"\t"<<Bengaluru[14]<<endl;
            else if(choice==2)
            cout<<Chennai[12]<<"\t"<<Chennai[13]<<"\t"<<Chennai[14]<<endl;
            else if(choice==3)
            cout<<Delhi[12]<<"\t"<<Delhi[13]<<"\t"<<Delhi[14]<<endl;
            else if(choice==4)
            cout<<Kolkata[12]<<"\t"<<Kolkata[13]<<"\t"<<Kolkata[14]<<endl;
            else
            cout<<Mumbai[12]<<"\t"<<Mumbai[13]<<"\t"<<Mumbai[14]<<endl;         
        cout<<endl<<endl<<endl;}
        else if (choice==0)
        {
            cout<<"\t\t\t\tEXITING!!"<<endl<<endl;
            break;
        }
        else 
        cout<<"\t\t\t\t INVALID CHOICE!! ENTER AGAIN"<<endl<<endl;
    }while(choice);
}
void position ::setdata(float lati1)
{
    lati=lati1;
    calc(lati);
    getdata();
}
void position :: getdata()
{
    cout<<"The Optimal Tilt Angle for Summer season is: \t"<<(int)sum_tilt<<" degrees."<<endl;
    cout<<"The Optimal Tilt Angle for Winter season is: \t"<<(int)win_tilt<<" degrees."<<endl;
    cout<<"The Optimal Tilt Angle for Spring season is: \t"<<(int)spr_tilt<<" degrees."<<endl;
    cout<<"The Optimal Average Tilt Angle is: \t\t"<<(int)avg_tilt<<" degrees."<<endl<<endl<<endl;
}
int main()
{
    position p1;
    int query;
    cout<<"\t\t\t\t\t ***** THE GREEN ANGLE  *****"<<endl;
    cout<<"\t\t\t\t WELCOME TO THE SOLAR PANEL ANGLE CALCULATOR:"<<endl;
    do{
        cout<<"QUICK MODE: It will display the list of selected cities and pre-determined angles. You have to choose city only."<<endl;;
        cout<<"DYNAMIC MODE: It will ask you to enter your location latitude and calculate the optimal angle for your Solar Panel Tilt."<<endl;
        cout<<endl<<"NOTE: ALL VALUES ARE IN DEGREES!"<<endl;
        cout<<"Do you want to use QUICK MODE OR DYNAMIC MODE?"<<endl<<"press 1 for QUICK MODE"<<endl<<"Press 2 for DYNAMIC MODE"<<endl<<"Press 0 to exit.";
        cin>>query;
        if (query==1)
        {
        cout<<endl<<endl<<"\t\t\t\t Enabling QUICK MODE:"<<endl;
        p1.quickmode();
        }
        else if (query==2)
        {cout<<"\t\t\t\t Enabling DYNAMIC MODE:"<<endl;
        cout<<"Enter the latitude of your location:";
        cin>>p1.lati;
        p1.setdata(p1.lati);
        }
        else if (query==0)
        { cout<<"\t\t\t\tEXITING!! THANK YOU"; 
          break;}        
        else
        cout<<"\t\t\t\tInvalid Choice!!! Enter Again:"<<endl<<endl;
    }while(query);
    return 0;
}