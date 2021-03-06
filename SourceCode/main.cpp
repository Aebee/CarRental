#include <iostream>
#include </home/mysterious/Downloads/tinyxml2-master/tinyxml2.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace tinyxml2;
using namespace std;

#ifndef XMLCheckResult
            #define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); }
#endif // XMLCheckResult

//All used functions
int main();
void CreateANewUser();

void IssueACar();

void menu();

void dropdownmenu(string c_menu);


void clearscr() { cout << string(50, '\n') ;}

void loadimg (){

    cout <<"                                       ______________                       "<<endl;
    cout <<"                                  _.-''         || \ `-.                    "<<endl;
    cout <<"                             _.-''              ||   \  `-._       -=====/  "<<endl;
    cout <<"                   _____..-''.<(]_______________||_____\    `-------/--/.   "<<endl;
    cout <<"         _..---''''__      /  ``     ____________|__________.....________\  "<<endl;
    cout <<"   _.-'''__.-.='_`_`-.\---|---'''''''       ` `  |   __  /.-'_`_`-.\      \."<<endl;
    cout <<" .' --''' .'/ /  |  \ \`. |                     /   '='.'/ /  |  \ \`.  __.|"<<endl;
    cout <<" |--------|| |``-O-''| ||----------------------/-------|| |``-O-''| ||''  / "<<endl;
    cout <<" '''----..| \\\\/_ _\/ / |______________________________|\\\\/_ _\/ / `--'  "<<endl;
    cout <<"             `-.....-'                                    `-.....-'         "<<endl;

    cout << endl << "Prague Car Rental Application" << endl;
}

void clientlist(string a, string b)

{

      ofstream myfile;
      myfile.open ("Customers/clientlist.txt", ios::app);
      myfile << "\n" << a << ":" << b;
      myfile.close();

}

void loadclients() {

  string line; int i = 0;
  ifstream myfile ("Customers/clientlist.txt");
  if (myfile.is_open())
  {

    while ( getline (myfile,line) )
    {

      i=0;

      istringstream ss(line);

      string token;

      while (getline(ss, token, ':'))

      {

        if (i <1) cout << "Client Name: " << token << endl;

        else cout << "Client ID: " << token << endl << "----------------" << endl;

      i++;

      }
    }

    myfile.close();

  }

  else cout << "Unable to open file";

}

//search for user based on given last name
void seacrhforclient(string clientlastname)

{

//set variables. found is used to terminate the loop once user has been found
string clastname, cid, line, token, a; int i = 0; int found = 0;
    //once user has passed the last name of the client, file clientlist is opened and searched for the user name along with the id to use it later for retrieving data
  ifstream myfile ("Customers/clientlist.txt");

    while ( getline (myfile,line) )

    {

        //i variable is used for the inside loop of the string split to get the user last name and id seperately
      i=0;

      istringstream ss(line);


      if (found == 1) { break;}

      while (getline(ss, token, ':'))

      {

        if (i <1)  {

            if (token == clientlastname) { clastname = token; found = 1; }

        }

        else { cid = token; }

        i++;


      }
    }
    //if user is found, load information. otherwise, print not found.
    if (found == 1) {
    cout << endl << "Loading Clients Details. Please wait.." << endl << endl;
    sleep(2);//fancy way to make the user wait!
    cout << "---------------------------------" << endl << "          Client ID: " << cid << endl << "---------------------------------" << endl;
    //initialize xml parser
    XMLDocument xmlDoc;
    //save the clientname and id into string var then convert it to pass it to the xml parser to retrieve data
    string setusrdetails = "Customers/" + clientlastname + '-' + cid + ".xml";
    xmlDoc.LoadFile(setusrdetails.c_str());
    //point firstchild
    XMLNode * pRoot = xmlDoc.FirstChild();
    XMLElement * pElement = pRoot->FirstChildElement("FirstName");
    XMLPrinter iOutInt;
    pElement->Accept(&iOutInt);

      istringstream ss(iOutInt.CStr());


    //split data inside xml file by arrow >
      while (getline(ss, token, '>'))

      {
        //ignore first retrieved part as it will be something like <FirstName and load the second part after i has increased by 1
      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        //loop again to split this time < to get the middle value only. the same process is repeated all over the retreival points
        while (getline(tt, sndtoken, '<'))

        {

            cout << "First Name: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }



    pElement = pRoot->FirstChildElement("LastName");
    XMLPrinter iOutInt2;
    pElement->Accept(&iOutInt2);
    i=0;
    istringstream xx(iOutInt2.CStr());



      while (getline(xx, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Last Name: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("Address");
    XMLPrinter iOutInt3;
    pElement->Accept(&iOutInt3);
    i=0;
    istringstream ww(iOutInt3.CStr());



      while (getline(ww, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Address: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }



    pElement = pRoot->FirstChildElement("PhoneNumber");
    XMLPrinter iOutInt4;
    pElement->Accept(&iOutInt4);
    i=0;
    istringstream ee(iOutInt4.CStr());



      while (getline(ee, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Phone Number: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("DOB");
    XMLPrinter iOutInt5;
    pElement->Accept(&iOutInt5);
    i=0;
    istringstream qq(iOutInt5.CStr());



      while (getline(qq, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Date of Birth: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }

    pElement = pRoot->FirstChildElement("CarBrand");
    XMLPrinter iOutInt6;
    pElement->Accept(&iOutInt6);
    i=0;
    istringstream rr(iOutInt6.CStr());



      while (getline(rr, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rented Car Brand: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("CarType");
    XMLPrinter iOutInt7;
    pElement->Accept(&iOutInt7);
    i=0;
    istringstream yy(iOutInt7.CStr());



      while (getline(yy, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rented Car Type: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("CarYear");
    XMLPrinter iOutInt8;
    pElement->Accept(&iOutInt8);
    i=0;
    istringstream uu(iOutInt8.CStr());



      while (getline(uu, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rented Car Model Year: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("RentStartDate");
    XMLPrinter iOutInt9;
    pElement->Accept(&iOutInt9);
    i=0;
    istringstream oo(iOutInt9.CStr());



      while (getline(oo, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rent Date: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }

    pElement = pRoot->FirstChildElement("RentEndDate");
    XMLPrinter iOutInt10;
    pElement->Accept(&iOutInt10);
    i=0;
    istringstream pp(iOutInt10.CStr());



      while (getline(pp, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rent End Date: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


    pElement = pRoot->FirstChildElement("RentDays");
    XMLPrinter iOutInt11;
    pElement->Accept(&iOutInt11);
    i=0;
    istringstream aa(iOutInt11.CStr());



      while (getline(aa, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Rent Total Days: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }

    pElement = pRoot->FirstChildElement("Totalprice");
    XMLPrinter iOutInt12;
    pElement->Accept(&iOutInt12);
    i=0;
    istringstream gg(iOutInt12.CStr());



      while (getline(gg, token, '>'))

      {

      if (i == 1)

      {
        string sndtoken;
        istringstream tt(token);
        while (getline(tt, sndtoken, '<'))

        {
            cout << "Paid Price: " << sndtoken << endl;
            break;
        }



      }

        i++;

      }


   cout << "---------------------------------" << endl;
   cout << endl << "Do you want to clear the screen and return to the home screen? Enter Y or y for yes or N or n to exit" << endl; cin >> a;
   if (a == "y" || a == "Y") { clearscr(); main(); }
   if (a == "n" || a == "N") { exit; }
 }
 else { cout << endl << "User could not be found. Type help for help or list to load clients' names and ids." << endl << "Please note that search is case sensitive. Adam is not the same as adam." << endl << endl << "Please wait as you will be sent back to homescreen"; sleep(3); clearscr(); main(); }
}

//function to save all of the passed params into the xml file
void savedata(string fname, string lname, string uphone, string uaddress, string udob, string carbrand, string cartype, string caryear, string startdate, string enddate, string numberofdays, string totalprice) {
    //create random user ids from 4 digits
    srand ( time(NULL) );
    int randid = rand() % 10000;
    //if to_string gave an error, project > build options > tick the mark next to have g++ c++11
    string c_randid = to_string(randid);
    //needed conversions to pass the values into the xml parser
    const char * s_fname = fname.c_str();
    const char * s_lname = lname.c_str();
    const char * s_uphone = uphone.c_str();
    const char * s_uaddress = uaddress.c_str();
    const char * s_udob = udob.c_str();
    const char * s_carbrand = carbrand.c_str();
    const char * s_cartype = cartype.c_str();
    const char * s_caryear = caryear.c_str();
    const char * s_startdate = startdate.c_str();
    const char * s_enddate = enddate.c_str();
    const char * s_numberofdays = numberofdays.c_str();
    const char * s_totalprice = totalprice.c_str();
    const char * s_randid = c_randid.c_str();
    XMLDocument xmlDoc;
    XMLNode * pRoot = xmlDoc.NewElement("Customer");
    xmlDoc.InsertFirstChild(pRoot);


    XMLElement * pElement = xmlDoc.NewElement("ID");
    pElement->SetText(s_randid);
    pRoot->InsertEndChild(pElement);


    pElement = xmlDoc.NewElement("FirstName");
    pElement->SetText(s_fname);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("LastName");
    pElement->SetText(s_lname);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("Address");
    pElement->SetText(s_uaddress);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("PhoneNumber");
    pElement->SetText(s_uphone);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("DOB");
    pElement->SetText(s_udob);
    pRoot->InsertEndChild(pElement);


    pElement = xmlDoc.NewElement("CarBrand");
    pElement->SetText(s_carbrand);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("CarType");
    pElement->SetText(s_cartype);
    pRoot->InsertEndChild(pElement);


    pElement = xmlDoc.NewElement("CarYear");
    pElement->SetText(s_caryear);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("RentStartDate");
    pElement->SetText(s_startdate);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("RentEndDate");
    pElement->SetText(s_enddate);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("RentDays");
    pElement->SetText(s_numberofdays);
    pRoot->InsertEndChild(pElement);


    pElement = xmlDoc.NewElement("Totalprice");
    pElement->SetText(s_totalprice);
    pRoot->InsertEndChild(pElement);


    string saveas = "Customers/" + lname + '-' + c_randid + '.' + "xml";
    XMLError eResult = xmlDoc.SaveFile(saveas.c_str());
    clientlist(lname, c_randid);
    XMLCheckResult(eResult);


}

void readhelp () {
  string line;
  ifstream myfile ("uhelp.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";


}

//changes choices from ints to string to be saved in the xml
string transchoice(string ca, int cb) {

    if (ca == "CT")

    {
        switch (cb) {

        case 1: return "Truck";
        case 2: return "Sidan";
        case 3: return "Van";
        case 4: return "Sports";
        case 5: return "HatchBack";
        default: return "Invalid";

        }

    }

    else if (ca == "CY")

    {

        switch (cb) {

        case 1: return "2011";
        case 2: return "2012";
        case 3: return "2013";
        case 4: return "2014";
        case 5: return "2015";
        default: return "Invalid";

        }

    }

    else if (ca == "CB")

    {

        switch (cb) {

        case 1: return "BMW";
        case 2: return "Porsche";
        case 3: return "Audi";
        case 4: return "Nissan";
        case 5: return "Toyota";
        default: return "Invalid";

        }

    }

}

void dropdownmenu(string c_menu) {

    if (c_menu == "carType") {

        cout << "|---------------|" << endl << "|" << "  Car Type " << "    |" << endl << "|---------------|" << endl;
        cout << "|" << "  1. truck" << "     |" << endl;
        cout << "|" << "  2. Sidan" << "     |" << endl;
        cout << "|" << "  3. Van" << "       |" << endl;
        cout << "|" << "  4. Sports" << "    |" << endl;
        cout << "|" << "  5. Hatchback" << " |" << endl;
        cout << "|---------------|" << endl;

}

    else if (c_menu == "carYear") {

        cout << "|-------------|" << endl << "|" << "  Model Year " << "|" << endl << "|-------------|" << endl;
        cout << "|" << "  1. 2011" << "    |" << endl;
        cout << "|" << "  2. 2012" << "    |" << endl;
        cout << "|" << "  3. 2013" << "    |" << endl;
        cout << "|" << "  4. 2014" << "    |" << endl;
        cout << "|" << "  5. 2015" << "    |" << endl;
        cout << "|-------------|" << endl;

    }

    else if (c_menu == "carBrand") {

        cout << "|--------------|" << endl << "|" << "  Brands " << "     |" << endl << "|--------------|" << endl;
        cout << "|" << "  1. BMW" << "      |" << endl;
        cout << "|" << "  2. Porsche" << "  |" << endl;
        cout << "|" << "  3. Audi" << "     |" << endl;
        cout << "|" << "  4. Nissan" << "   |" << endl;
        cout << "|" << "  5. Toyota" << "   |" << endl;
        cout << "|--------------|" << endl;

    }

}

//End of functions

//Used classes

class Person {

    public:
        string Fname() const { return _Fname; }
        string Lname() const { return _Lname; }
        string Uphone() const { return _Uphone; }
        string Uaddress() const { return _Uaddress; }
        string Udob() const { return _Udob; }

        void Fname(const string& Fname) { _Fname = Fname; }
        void Lname(const string& Lname) { _Lname = Lname; }
        void Uphone(const string& Uphone) { _Uphone = Uphone; }
        void Uaddress(const string& Uaddress) { _Uaddress = Uaddress; }
        void Udob(const string& Udob) { _Udob = Udob; }


    private:
        string _Fname;
        string _Lname;
        string _Uphone;
        string _Uaddress;
        string _Udob;
};


class Car: public Person {

    public:
        string CarType() const { return _CarType; }
        int CarYear() const { return _CarYear; }
        string CarBrand() const { return _CarBrand; }

        void CarType(const string& CarType) { _CarType = CarType; }
        void CarYear(const int& CarYear) { _CarYear = CarYear; }
        void CarBrand(const string& CarBrand) { _CarBrand = CarBrand; }

    private:
        string _CarType;
       int _CarYear;
        string _CarBrand;
};

class Invoice: public Car {

    public:
        int iVoiceNumber() const { return _iVoiceNumber; }
        int iVoiceTotal() const { return _iVoiceTotal; }

        void iVoiceNumber(const int& iVoiceNumber) { _iVoiceNumber = iVoiceNumber; }
        void iVoiceTotal(const int& iVoiceTotal) { _iVoiceTotal = iVoiceTotal; }


    private:
        int _iVoiceNumber;
        int _iVoiceTotal;
};

//End of Classes


int main()

{

    loadimg();
    int choice; string lookup;

    cout << "Please choose one of the following options: " << endl << "1) Enter number 1 to issue a new invoice." << endl << "2) Enter number 2 to retrieve user data." << endl << "3) Enter number 3 for help/user guidance." << endl;
    cin >> choice;

    switch(choice)

{
    case 1:
        //cout << "You have chosen to add a new record";
        CreateANewUser();
        break;
    case 2:
        returnback:
        cout << "Please enter the client's last name or enter the word list to see list of existing clients." << endl;
        cin >> lookup;
        if (lookup == "List" || lookup == "list") { cout << endl << endl; loadclients(); goto returnback;}
        else { seacrhforclient(lookup) ;break;}
        break;
    case 3:
     readhelp();
     break;
 }
}



void CreateANewUser()

{
    srand ( time(NULL) );
    int invnumber = rand() % 1000000;
    redo:
    string a, startdate, enddate, yesno; int cbrand, cyear, cty, numberofdays, priceperday;
    Invoice newuser;
    cout << endl << "Please Enter Customer's First Name: " << endl;
    cout << "'" << endl << "'" << "---> Example: Adam" << endl << endl << "First Name: ";
    cin >> a; newuser.Fname(a);

    cout << endl << "Please Enter Customers's Last Name: " << endl;
    cout << "'" << endl << "'" << "---> Example: Smith" << endl << endl << "Last Name: ";
    cin >> a; newuser.Lname(a);

    cout << endl << "Please Enter Customer's Phone numbers: " << endl;
    cout << "'" << endl << "'" << "---> Example: 605554848" << endl << endl << "Phone Number: ";
    cin >> a; newuser.Uphone(a);
    cin.ignore();
    cout << endl << "Enter Customer's Address: " << endl;
    cout << "'" << endl << "'" << "---> Example: Thakurova, Prague 6" << endl << endl << "Address: ";
    getline(cin, a); newuser.Uaddress(a);

    cout << endl << "Enter Customer's Date of Birth: " << endl;
    cout << "'" << endl << "'" << "---> Example: 18.2.1999" << endl << endl << "Date of Birth: ";

    cin >> a; newuser.Udob(a);

    cout << "Do you wish to proceed or modify? Enter Y for Yes or N for No" << endl;
    cin >> yesno;
    if ((yesno == "N") || (yesno == "n")) { goto redo; }

    rentedcar:
    //space
    cout << endl << "Choose a car brand from the menu" << endl; dropdownmenu("carBrand");
    cout << endl << "Enter brand number according to the shown menu: "; cin >> cbrand;

    cout << endl << "Choose the type of the car from the menu" << endl; dropdownmenu("carType");
    cout << endl << "Enter type number according to the shown menu: "; cin >> cty;

    cout << endl << "Choose the year of the car from the menu" << endl; dropdownmenu("carYear");
    cout << endl << "Enter year number according to the shown menu: "; cin >> cyear;

    cout << "Do you wish to proceed or modify? Enter Y for Yes or N for No" << endl;
    cin >> yesno;
    if ((yesno == "N") || (yesno == "n")) { goto rentedcar; }


    rentinfo:
    cout << endl << "Enter the rent start date: " << endl;
    cout << "'" << endl << "'" << "---> Example: 20.4.2015 or 20/4/2015" << endl << endl << "Start Date: ";
    cin >> startdate;

    cout << endl << "Enter the rent end date: " << endl;
    cout << "'" << endl << "'" << "---> Example: 20.4.2015 or 20/4/2015" << endl << endl << "End Date: ";
    cin >> enddate;

    cout << endl << "Enter the number of days the car is rented: " << endl;
    cout << "'" << endl << "'" << "---> Example: 6" << endl << endl << "Number of Days: ";
    cin >> numberofdays;

    cout << endl << "Enter price per day: " << endl;
    cout << "'" << endl << "'" << "---> Example: 20" << endl << endl << "Price/day: ";
    cin >> priceperday;

    cout << "Do you wish to proceed or modify? Enter Y for Yes or N for No" << endl;
    cin >> yesno;
    if ((yesno == "N") || (yesno == "n")) { goto rentinfo; }
    newuser.iVoiceNumber(invnumber);

    savedata(newuser.Fname(),newuser.Lname(), newuser.Uphone(),newuser.Uaddress(), newuser.Udob(), transchoice("CB", cbrand), transchoice("CT", cty), transchoice("CY", cyear), startdate, enddate, to_string(numberofdays), to_string(numberofdays * priceperday) );

    cout << endl << endl << " **** Issuing invoice. Please wait..." << endl;
    sleep(3);


    cout << " -------------------------------------------------------------- " << endl;
    cout << "'" << "              Client Invoice:   " << newuser.iVoiceNumber() << "       "<< endl;
    cout << "'" << endl;
    cout << "'" << "  First Name: " << newuser.Fname() << endl;
    cout << "'" << "  Last Name: " << newuser.Lname() << endl;
    cout << "'" << "  Phone No.: " << newuser.Uphone() << endl;
    cout << "'" << "  Date of Birth: " << newuser.Udob() << endl;
    cout << "'" << "  Address: " << newuser.Uaddress() << endl;
    cout << "'" << "  Rented Car: " << transchoice("CB", cbrand) << endl;
    cout << "'" << "  Car Type: " << transchoice("CT", cty) << endl;
    cout << "'" << "  Car Brand: " << transchoice("CY", cyear) << endl;
    cout << "'" << "  Rent Start Date: " << startdate << endl;
    cout << "'" << "  Rent End Date: " << enddate << endl;
    cout << "'" << "  Number of Rented Days: " << numberofdays << endl;
    cout << "'" << "  Price per Day: " << priceperday << endl;
    cout << "'" << "  Total Price: " << numberofdays * priceperday << endl;
    cout << "'" << endl;
    cout << " -------------------------------------------------------------- " << endl;
    cout << endl << "Do you want to clear the screen and return to the home screen? Enter Y or y for yes or N or n to exit" << endl; cin >> a;
    if (a == "y" || a == "Y") { clearscr(); main(); }
    if (a == "n" || a == "N") { exit; }
}

