//"Owais khan","Riaz","Sanaullah"
//"16686","16887","16952"



#include<iostream>
#include<climits>//Defines INT_MAX and INT_MIN in this program.
#include <cstdlib>//Allows system("cls"); to clear the screen.
using namespace std;

//GLOBALLY DEFINED >>
//Arrays for items,prices and their codes.
	string items[]={"Headphone","Phonecover","Keyboard","Mouse   ","VGAcable","Powercable","Speakers","HDMIcable"};
	int itemsprices[]={3000,400,3000,1200,500,200,1100,1000};
	int itemscode[]={111,222,333,444,555,666,777,888};

//finding no. of items/Finding Size of arrays
	int itemcount= sizeof(items) / sizeof(items[0]);// (32/4)=8
                   //32 bytes        //4 bytes


// Functions Declaration
bool login();
string menu();
void display_items();
void search_item(int code);
void low_to_high_price();
void high_to_low_price();
void shopping();


// Main //Main Function ==============================================================================================================================================================
int main() {
	
	
	//Header for shop name.	
cout<<"===========================================\n";
cout<<"      { Computer Accessories Store }      \n";
cout<<"      { Purchasing Software        }      \n";
cout<<"===========================================\n\n";

	
	
	
bool approval = login();//approval stores the return from login();
 if(approval == 0){
 	cout<<"=> Exiting Program.";
 	return 0;
 	
 		}
 	
    while (true) {
    	
    
		string choice=menu();//choice stores return from menu.
		
   
   if(choice == "1"){
   	display_items();
   }
      else if(choice =="2" ){
      
      	
cout<<"\n";
cout<<"         { Search Item By Code }       \n";
cout<<"><><><><><><><><><><><><><><><><><><><><><\n\n";
      	
      	int s_code;
      	cout<<"=> Search:";
      	cin>>s_code;
      	   if (cin.fail()) {
            cin.clear();                 // Clear the error flag
            cin.ignore(INT_MAX, '\n');   // Ignore invalid input
            cout << "=> Invalid input! Please enter a numeric code.\n";
            continue;                    // Skip to the next iteration
        }
      	
      	cout<<endl;
      	
      	search_item(s_code);
      	
   }
      else if(choice =="3" ){
      	low_to_high_price();
   }
      else if(choice =="4"){
      	high_to_low_price();
   }
      else if(choice =="5"){
      	shopping();
   }
      else if(choice =="6" ){
      	cout<<"\nExiting Program...................................................................................\n";
      	return 0;
   }   
      else{
      	cout<<"=> Invalid choice\n";
      	
   }
   

    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////	LOGIN FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Login
bool login(){
cout<<"::::::::::::::::::::::::::::::::::::\n";
cout<<"         { User Login }             \n";
cout<<"::::::::::::::::::::::::::::::::::::\n\n";

//Valid usern and pass
string valid_usern[]={"Owais khan","Riaz","Sanaullah"};
string valid_pass[]={"16686","16887","16952"};

int size_v=sizeof(valid_usern)/sizeof(valid_usern[0]);

//usern and pass declaration.
string in_usern;
string in_pass;

int tries=2;//no. of tries left for login.
while(true){

//usern and pass input.
cout<<"=> User Name:";
getline(cin, in_usern); // Safely read the input

cout<<"=> Password:";
getline(cin, in_pass);

system("cls");//clears the screen


for(int i=0;i<size_v;i++){

	if(in_usern==valid_usern[i] && in_pass==valid_pass[i]){
	cout<<"=> Login successful!\n=> Welcome to the Computer Accessories Store!\n\n";
		return 1;
		break;
	}

}
	if(tries>0){
        cout<<"=> Invalid Username or Password try again.You have "<<tries<<" tries left."<<endl;
		tries--;
	}
	else{
		cout<<"=> Sorry, you've exceeded the maximum number of login attempts. Try to login later.\n";
		return 0;
		break;
		}
}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////	MENU FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string menu(){
		string choice;
cout<<"-------------------------------------------\n";
cout<<"               { Main Menu }             \n";
cout<<"-------------------------------------------\n\n";

	cout<<"1. Display Items\n";
	cout<<"2. Search Item by Code\n";
	cout<<"3. Sort Items by Low to High Price\n";
	cout<<"4. Sort Items by High to Low Price\n";
	cout<<"5. Start Shopping\n";
	cout<<"6. Exit\n";
	
	cout<<"\n=> Enter your choice(1 to 6):";//Takes choice as a input
	cin>>choice;
	
	system("cls");//clears the screen
	return choice;}
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////	DISPLAY ITEMS FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_items(){



int i=0,j=0;
int smallest=INT_MAX;


int smallest_index=0;



for(j=0;j<itemcount;j++)
{
	
	for(i=j;i<itemcount;i++)
	{
		if(smallest>=itemscode[i])
		{
			smallest=itemscode[i];
			smallest_index=i;
		}
	}
swap(itemscode[j],itemscode[smallest_index]);
swap(itemsprices[j],itemsprices[smallest_index]);
swap(items[j],items[smallest_index]);

smallest=INT_MAX;
}

cout<<endl;
cout<<"              { Items }             \n";
cout<<"><><><><><><><><><><><><><><><><><><><><><\n\n";

cout<<"-------------------------------------------\n";
cout<<"Items		Prices		Item Code  \n";
cout<<"===========================================\n";
	for(int i=0;i<itemcount;i++)
	{cout<<items[i]<<"\t"<<itemsprices[i]<<"\t\t  "<<itemscode[i]<<"\t   "<<endl;}
	cout<<"===========================================\n\n";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////	SEARCH ITEM BY ITEM CODE FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_item(int code){

	
	int found=0;//varify that item found or not
for(int i=0;i<itemcount;i++){
	if(code == itemscode[i]){
		cout<<"---{ Item found }---\n\n";
		cout<<"> Item Name: "<<items[i]<<endl;
		cout<<"> Item Price: "<<itemsprices[i]<<endl;
		cout<<"> Item Code: "<<itemscode[i]<<endl<<endl;
		
		found=1;
		
		
		}
		
    	
	}
	
	if(found == 0){
		cout<<"=> Invalid Item Code\n";
	}
	
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// SORT FOR LOW TO HIGH PRICE FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void low_to_high_price(){


int i=0,j=0;
int smallest=INT_MAX;


int smallest_index=0;



for(j=0;j<itemcount;j++)
{
	
	for(i=j;i<itemcount;i++)
	{
		if(smallest>=itemsprices[i])
		{
			smallest=itemsprices[i];
			smallest_index=i;
		}
	}
swap(itemscode[j],itemscode[smallest_index]);
swap(itemsprices[j],itemsprices[smallest_index]);
swap(items[j],items[smallest_index]);

smallest=INT_MAX;
}
cout<<"\n";
cout<<"       { Low to High Price }        \n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";

cout<<"-------------------------------------------\n";
cout<<"Items		Prices		Item Code  \n";
cout<<"===========================================\n";
for(int i=0;i<itemcount;i++)
	{cout<<items[i]<<"\t"<<itemsprices[i]<<"\t\t  "<<itemscode[i]<<"\t   "<<endl;}
	cout<<"===========================================\n";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////	SORT FOR HIGH TO LOW PRICE FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void high_to_low_price()

void high_to_low_price(){

int i=0,j=0;
int largest=INT_MIN;


int largest_index=0;



for(j=0;j<itemcount;j++)
{
	
	for(i=j;i<itemcount;i++)
	{
		if(largest<=itemsprices[i])
		{
			largest=itemsprices[i];
			largest_index=i;
		}
	}
swap(itemscode[j],itemscode[largest_index]);
swap(itemsprices[j],itemsprices[largest_index]);
swap(items[j],items[largest_index]);

largest=INT_MIN;
}

cout<<"\n";
cout<<"       { High to Low Price }        \n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";

cout<<"-------------------------------------------\n";
cout<<"Items		Prices		Item Code  \n";
cout<<"===========================================\n";
for(int i=0;i<itemcount;i++)
	{cout<<items[i]<<"\t"<<itemsprices[i]<<"\t\t  "<<itemscode[i]<<"\t   "<<endl;}
	cout<<"===========================================\n\n";
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////	SHOPING FUNCTION	//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void shopping() {
	display_items();
   
   //variables
 int code, quantity;
    double gross_bill= 0.0;

cout<<"\n";
cout<<"          { Start Shoping }        \n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
    while (true) {
        cout << "=> Enter Item Code (or 0 to finish shopping): ";
        cin >> code;
          if (cin.fail()) {
            cin.clear();                 // Clear the error flag
            cin.ignore(INT_MAX, '\n');   // Ignore invalid input
            cout << "=> Invalid input! Please enter a numeric code.\n";
            continue;                    // Skip to the next iteration
        }
                if (code == 0) {
        	
        break;	
		}
			int check=0;
	for(int i=0;i<itemcount;i++){
		
		if(code == itemscode[i]){
			  cout<<"=> Enter Quantity:";
        cin>>quantity;
			gross_bill+=(itemsprices[i]*quantity);
			check=1;
			break;}
			
		if(i==7 && check==0){	
		cout<<"=> Invalid Item code.\n";
		break;
		}
		}
        
    	
}  //LOOP ENDS HERE	

//BILLING =>
system("cls");
cout<<"\n";
cout<<"          { Gross Bill }        \n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
    cout << "\n=> Gross Bill: Rs." <<gross_bill<< endl;

    float disc_pr = 0.0;
    if (gross_bill >= 10000) disc_pr = 10.0;
    else if (gross_bill >= 7000) disc_pr = 7.0;
    else if (gross_bill >= 3000) disc_pr = 5.0;

    double disc_amount = (gross_bill * disc_pr) / 100;
    double tot_bill = gross_bill - disc_amount;

    cout << "=> You got " << disc_pr << "% discount.\n";
    cout << "=> Total Bill After Discount: Rs." << tot_bill << endl;
    cout << "Thank you for shopping!\n";
    



}
 
 //**************************************************************
//                       THE END!                              *
//**************************************************************



