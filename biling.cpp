#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
        	void administrator();
        void menu();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping :: menu()

{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t         Supermarket main menu     \n";
    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t 1) Administrator |\n";
    cout<<"\t\t\t\t                  |\n";
    cout<<"\t\t\t\t 2) Buyer         |\n";
    cout<<"\t\t\t\t                  |\n";
    cout<<"\t\t\t\t 3) Exit          |\n";
    cout<<"\t\t\t\t                  |\n";
    cout<<"\t\t\t\t   please select";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;

            if(email=="critik127@gmail.com" && password=="Rc8299@$@$@$")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid Email/Password";
            }
            break;
            
    
    case 2:
        {
            buyer();
        }
    case 3:
    {
        exit(0);
    }
    default :
        {
            cout<< "Please select from given option";
        }
}


goto m;
}

void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t|____1) Add the product____|";
    cout<<"\n\n\n\t\t\t|                          |";
    cout<<"\n\n\n\t\t\t|____2) Modify the product__|";
    cout<<"\n\n\n\t\t\t|                          |";
    cout<<"\n\n\n\t\t\t|____3) Delete the product__|";
    cout<<"\n\n\n\t\t\t|                          |";
    cout<<"\n\n\n\t\t\t|____4)Back to main menu____|";
    
    cout<<"\n\n\n\t Please enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        default :
            cout<<"Invalid choice";

    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t___________\n";
    cout<<"                   \n";
    cout<<"\t\t\t1) Buy product \n";
    cout<<"                   \n";
    cout<<"\t\t\t2) Do Back   \n";
    cout<<"\t\t\t Enter your choice : ";

    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();

        default :
            cout<<"Invalid Choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t\t\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c ==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    
    if(token==1)
    goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
}
    cout<<"\n\n\t\t Record inserted !";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File dosen't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;                
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found !";
        }
    }
    

}
void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File dosen't exist";
    }

    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted ??";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data1>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found ??";
        }
    }
}
void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n______________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n______________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping ::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEPT ??";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database ??";
    }

    else{
        data.close();

        list();
        cout<<"\n________________________________________\n";
        cout<<"\n________________________________________\n";
        cout<<"\n         Please place the order         \n";
        cout<<"\n________________________________________\n";
        cout<<"\n________________________________________\n";
        do{
        	m:
            cout<<"\n\n Enter product code :";
            cin>>arrc[c];
            cout<<"\n\n Enter quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate produt code. Try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Wanna buy another product if yes then press (y) else for no press (n) \n THANKYOU";
            cin>>choice;
        }
        while(choice =='y');

        cout<<"\n\n\t\t\t__________________RECEPT___________________\n";
        cout<<"\n Product No\t Product Name\t Product quantity\tPrice\tAmount\tAmount with discount🤑\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();

    }
    cout<<"\n\n____________________________________________";
    cout<<"\n Total amount :" <<total;
   cout<<"\n\n\t\t THAKYOU \n\n\t\t VISIT AGAIN^_^";
}
int main()
{
    shopping s;
    s.menu();
}
