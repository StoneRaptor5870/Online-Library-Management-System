//*****************************************************************************
//	PROJECT ONLINE BOOK LIBRARY
//*****************************************************************************

//*****************************************************************************
//	INCLUDED HEADER FILES
//*****************************************************************************
#include <fstream.h>
#include <system.h>  //USER DEFINED HEADER FILE
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <colbox.h>  //USER DEFINED HEADER FILE
//*****************************************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//*****************************************************************************

class MENU
{
public :
	   void main_menue(void) ;
	   void admin(void) ;
	   void membermenue(void) ;
	   void intro(void) ;
private :
	   void edit_book(void) ;
	   void edit_member(void) ;
} ;

//*****************************************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO BOOKS
//*****************************************************************************

class BOOK
{
public :
	   char *bookaddr(int) ;
	   void list(void) ;
protected :
	   int book_found(int) ;
	   int bookname_found(char []) ;
	   int recordno(int) ;
	   int bookcodeof(char[]) ;
	   int reccount(void) ;
	   char *bookname(int) ;
	   char *authorname(int) ;
	   char *bookpublisher(int) ;
	   void add_new_book(int, char tname[33], char tauthor[26], char tpub[33], char taddr[50]) ;
	   void identify_book(int) ;
	   void modify(int, char[], char[], char[],char[]) ;
	   void deletion(void) ;
	   void display(int) ;
	   void delete_rec(int) ;
private :
	   int   bookcode ;
	   char  name[33], author[26] ,pub[33] ,addr[50] ;
} ;

//*****************************************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO MEMBERS
//*****************************************************************************

class MEMBER
{
public :	
	  char *membername(int) ;
	  void list(void) ;
protected :
	  int  member_found(int) ;
	  int  lastcode(void) ;
	  char *memberphone(int) ;
	  char *memberaddress(int) ;
	  void add_mem(int, char [], char [], char[]) ;
	  void modify(int, char[], char[], char[]) ;
	  void update_book(int, int) ;
	  void display(int) ;
	  void delete_rec(int) ;
private :
	  int  memcode, bookcode ;
	  char name[26], phone[10], address[33] ;
} ;

//*****************************************************************************
// THIS IS DERIVED FROM CLASS BOOK & MEMBER AND CONTAINS FUNCTIONS FOR WORKING.
//*****************************************************************************

class WORKING : public BOOK, public MEMBER
{
public :
	  void downloadbook(void) ;
	  void add_book(void) ;
	  void add_member(void) ;
	  void modify_book(void) ;
	  void modify_member(void) ;
	  void delete_book(void) ;
	  void delete_member(void) ;
	  void searchbook(void) ;
} ;

//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED DATE
//**********************************************************

class DATE
{
public :
	  int  day, mon, year ;
} ;

//*****************************************************************************
// FUNCTION FOR PASSWORD TO GO TO ADIMINSTRATIVE MENU.
//*****************************************************************************

void password()
{
    clrscr();
    int ctr=0;
    int  o;
    char pass[5];
    gotoxy(30,11);
    cout<<"ENTER PASSWORD : ";
    for(int i=0; i<5 && (o=getch())!=13  ; i++)
    {
	pass[i]=o;
	putch('*');
    }
    pass[i]='\0';
    ctr=strcmp(pass,"qwert");
    if(ctr==0)
    {
	MENU M;
	M.admin();
    }
    else
   { 
    textcolor(RED+BLINK) ;
    gotoxy(32,13) ;
    cprintf("WRONG PASSWORD") ;
    textcolor(LIGHTGRAY) ;
    getch() ;
    return ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY ADMINSTRATIVE MAIN MENU & CONTROL ALL THE FUNCTION MENU.
//*****************************************************************************

void MENU :: admin(void)
{
    char ch ;
    while (1)
    {   clrscr();
	colorbox(4,4,77,20);
	gotoxy(23,6) ;
	cout <<"A D M I N S T R A T I V E   M E N U E" ;
	gotoxy(23,7) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,10) ;
	cout <<"1. INTRODUCTION" ;
	gotoxy(32,11) ;
	cout <<"2. ADD NEW BOOK" ;
	gotoxy(32,12) ;
	cout <<"3. LIST OF BOOKS" ;
	gotoxy(32,13) ;
	cout <<"4. LIST OF MEMBERS" ;
	gotoxy(32,14) ;
	cout <<"5. EDIT BOOK" ;
	gotoxy(32,15) ;
	cout <<"0. QUIT" ;
	gotoxy(30,18) ;
	cout <<"Enter your choice : " ;
	ch = getche() ;
	if (ch == 27)
	    break ;
	else if (ch == '1')
	    intro() ;
	else if (ch == '2')
	{
	    WORKING W ;
	    W.add_book() ;
	}
	else if (ch == '3')
	{
	    BOOK B ;
	    B.list() ;
	}
	else if (ch == '4')
	{
	    MEMBER M ;
	    M.list() ;
	}
	else if (ch == '5')
	{
	    MENU M;
	    M.edit_book() ;
	}
	else if (ch == '0')
	    break ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY MAIN MENU & CONTROL ALL THE FUNCTION MENU.
//*****************************************************************************

void MENU :: main_menue(void)
{
    char ch ;
    while (1)
    {   clrscr();
	colorbox(4,4,77,20);
	gotoxy(23,7) ;
	cout <<"O N L I N E  B O O K  L I B R A R Y";
	gotoxy(23,8) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,10) ;
	cout <<"1. INDRODUCTION " ;
	gotoxy(32,11) ;
	cout <<"2. FOR MEMBERS" ;
	gotoxy(32,12) ;
	cout <<"3. FOR ADMINSTRATIVE" ;
	gotoxy(32,13) ;
	cout <<"4. SIGN UP ";
	gotoxy(32,14) ;
	cout <<"0. EXIT";
	gotoxy(30,17);
	cout <<"Enter your choice : " ;
	ch = getche() ;
	if (ch == 27)
	    break ;
	else if (ch =='1')
	{   MENU M;
	    M.intro() ;
	}
	else if (ch == '2')
	{   MENU M;
	    M.membermenue() ;
	}
	else if (ch =='3')
	{   password();
	}
	else if (ch=='4')
	{   WORKING W;
	    W.add_member();
	}
	else if (ch == '0')
	    break ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY MEMBER MENUE & CONTROL ALL THE FUNCTION MENU.
//*****************************************************************************

void MENU :: membermenue(void)
{
    char ch ;
    while (1)
    {   clrscr();
	colorbox(4,4,77,20);
	gotoxy(29,7) ;
	cout <<"M E M B E R   M E N U E";
	gotoxy(29,8) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(32,10) ;
	cout <<"1. LIST OF BOOKS" ;
	gotoxy(32,11) ;
	cout <<"2. SEARCH A BOOK" ;
	gotoxy(32,12);
	cout <<"3. DOWNLOAD";
	gotoxy(32,13);
	cout <<"4. EDIT USER";
	gotoxy(32,14) ;
	cout <<"0. EXIT" ;
	gotoxy(30,17) ;
	cout <<"Enter your choice : " ;
	ch = getche() ;
	if (ch == 27)
	    break ;
	else if (ch == '1')
	{
	    BOOK B ;
	    B.list();
	}
	else if (ch == '2')
	{
	    WORKING W ;
	    W.searchbook();
	}
	else if (ch=='3')
	{   WORKING W;
	    W.downloadbook();

	}
	else if (ch=='4')
	{   MENU W;
	    W.edit_member();

	}
	else if (ch == '0')
	    break ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY EDIT MENU FOR BOOK & CONTROL FUNCTION IN THE EDIT MENU.
//*****************************************************************************

void MENU :: edit_book(void)
{
    char ch ;
    while (1)
    {
	clrscr() ;
	colorbox(4,4,77,20);
	gotoxy(31,7) ;
	cout <<"E D I T   B O O K S";
	gotoxy(31,8) ;
	cout <<"~~~~~~~~~~~~~~~~~~" ;
	gotoxy(35,11) ;
	cout <<"1. MODIFY" ;
	gotoxy(35,12) ;
	cout <<"2. DELETE" ;
	gotoxy(35,13) ;
	cout <<"0. EXIT" ;
	gotoxy(32,16) ;
	cout <<"Enter your choice : " ;
	ch = getche() ;
	if (ch == 27)
	    break ;
	else if (ch == '1')
	{
	    WORKING W ;
	    W.modify_book() ;
	}
	else if (ch == '2')
	{
	    WORKING W ;
	    W.delete_book() ;
	}
	else if (ch == '0')
	    break ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY EDIT MENU FOR MEMBERS & CONTROL FUNCTION IN THE EDIT MENU.
//*****************************************************************************

void MENU :: edit_member(void)
{
    char ch ;
    while (1)
    {
	clrscr() ;
	colorbox(4,4,77,20);
	gotoxy(30,7) ;
	cout <<"E D I T  M E M B E R S";
	gotoxy(30,8) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(35,11) ;
	cout <<"1. MODIFY" ;
	gotoxy(35,12) ;
	cout <<"2. DELETE" ;
	gotoxy(35,13) ;
	cout <<"0. EXIT" ;
	gotoxy(32,16) ;
	cout <<"Enter your choice : " ;
	ch = getche() ;
	if (ch == 27)
	    break ;
	else if (ch == '1')
	{
	    WORKING W ;
	    W.modify_member() ;
	}
	else if (ch == '2')
	{
	    WORKING W ;
	    W.delete_member() ;
	}
	else if (ch == '0')
	    break ;
    }
}

//*****************************************************************************
// FUNCTION TO DISPLAY THE INTRODUCTION OF THE PROJECT.
//*****************************************************************************

void MENU :: intro(void)
{
    clrscr() ;
    gotoxy(30,5) ;
    cout <<"Welcome to Project" ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(27,7) ;
    cprintf(" ONLINE  BOOK  LIBRARY ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    gotoxy(15,10) ;
    cout <<"This  project has facility of maintaining  records" ;
    gotoxy(15,11) ;
    cout <<"              of BOOKS and MEMBERS." ;
    gotoxy(15,14) ;
    cout <<"This  project  can  hold more  than  10,000  books" ;
    gotoxy(15,15) ;
    cout <<"                    records." ;
    gotoxy(15,18) ;
    cout <<"One  member  can  download  one  book  at  a  time." ;
    textcolor(LIGHTGRAY+BLINK) ;
    gotoxy(27,24) ;
    cprintf("Press any key to continue") ;
    textcolor(LIGHTGRAY) ;
    getch() ;
}
//*****************************************************************************
// THIS FUNCTION RETURNS THE NO. OF RECORDS IN BOOK FILE.
//*****************************************************************************

int BOOK :: reccount(void)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
		count++ ;
	file.close() ;
	return count ;
}

//*****************************************************************************
// THIS FUNCTION RETURN 0 IF GIVEN BOOK CODE NOT FOUND
//*****************************************************************************

int BOOK :: book_found(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    found = 1 ;
	    break ;
	}
    }
    file.close() ;
    return found ;
}

//*****************************************************************************
// THIS FUNCTION RETURN 0 IF GIVEN BOOK NAME NOT FOUND
//*****************************************************************************

int BOOK :: bookname_found(char t1code[33])
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (!strcmpi(name,t1code))
	{
	    found = 1 ;
	    break ;
	}
    }
    file.close() ;
    return found ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS THE BOOK NAME OF THE GIVEN BOOK CODE.
//*****************************************************************************

char *BOOK :: bookname(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char tname[33] ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    strcpy(tname,name) ;
	    break ;
	}
    }
    file.close() ;
    return tname ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS THE AUTHOR NAME OF THE GIVEN BOOK CODE.
//*****************************************************************************

char *BOOK :: authorname(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char tauthor[26] ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    strcpy(tauthor,author) ;
	    break ;
	}
    }
    file.close() ;
    return tauthor ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS THE ADDRESS  OF THE GIVEN BOOK CODE.
//*****************************************************************************

char *BOOK :: bookaddr(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char taddr[50] ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    strcpy(taddr,addr) ;
	    break ;
	}
    }
    file.close() ;
    return taddr ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS THE PUBLISHER NAME OF THE GIVEN BOOK CODE.
//*****************************************************************************

char *BOOK :: bookpublisher(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char tpub[33] ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    strcpy(tpub,pub) ;
	    break ;
	}
    }
    file.close() ;
    return tpub ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS THE BOOK CODE OF THE GIVEN BOOK NAME.
//*****************************************************************************

int BOOK :: bookcodeof(char t1code[33])
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int tcode=0 ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (!strcmpi(name,t1code))
	{
	    tcode = bookcode ;
	    break ;
	}
    }
    file.close() ;
    return tcode ;
}

//*****************************************************************************
// THIS FUNCTION DELETES THE RECORD OF THE GIVEN BOOK CODE.
//*****************************************************************************

void BOOK :: delete_rec(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(BOOK)) ;
	if ( file.eof() )
	    break ;
	if ( bookcode != tcode )
	    temp.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("BOOK.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(BOOK)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION ADD THE RECORD IN THE BOOK FILE
//*****************************************************************************

void BOOK :: add_new_book(int tcode,char tname[33], char tauthor[26], char tpub[33] ,char taddr[50])
{
    fstream file ;
    file.open("BOOK.DAT", ios::app) ;
    bookcode = tcode ;
    strcpy(name,tname) ;
    strcpy(author,tauthor) ;
    strcpy(pub,tpub) ;
    strcpy(addr,taddr) ;
    file.write((char *) this, sizeof(BOOK)) ;
    file.close() ;
}

//*****************************************************************************
// THIS FUNCTION SHOW THE RECORD IN THE BOOK FILE FOR THE GIVEN BOOK CODE.
//*****************************************************************************

void BOOK :: identify_book(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(BOOK)) ;
	if ( file.eof() )
	    break ;
	if ( bookcode == tcode )
	{
	    temp.write((char *) this, sizeof(BOOK)) ;
	}
	else
	    temp.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("BOOK.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(BOOK)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION MODIFY THE RECORD IN THE BOOK FILE FOR THE GIVEN BOOK CODE.
//*****************************************************************************

void BOOK :: modify(int tcode, char tname[33], char tauthor[26], char taddr[50] ,char tpub[50] )
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(BOOK)) ;
	if ( file.eof() )
	    break ;
	if ( bookcode == tcode )
	{
	    strcpy(name,tname) ;
	    strcpy(author,tauthor) ;
	    strcpy(addr,taddr) ;
	    strcpy(pub,tpub) ;
	    temp.write((char *) this, sizeof(BOOK)) ;
	}
	else
	    temp.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("BOOK.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(BOOK)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(BOOK)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION DISPLAY THE RECORD FROM THE BOOK FILE FOR THE GIVEN BOOK CODE.
//*****************************************************************************

void BOOK :: display(int tcode)
{
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	if (bookcode == tcode)
	{
	    gotoxy(5,5) ;
	    cout <<"Book Code   : " <<bookcode ;
	    gotoxy(5,7) ;
	    cout <<"Book Name   : " <<name ;
	    gotoxy(5,8) ;
	    cout <<"Author Name : " <<author ;
	    gotoxy(5,9) ;
	    cout <<"Publisher   : " <<pub ;
	    gotoxy(5,10) ;
	    cout <<"Address     : " <<addr ;
	    break ;
	}
    }
    file.close() ;
}

//*****************************************************************************
// THIS FUNCTION DISPLAY THE LIST OF BOOKS.
//*****************************************************************************

void BOOK :: list(void)
{
    clrscr() ;
    int row = 6 , found=0, flag=0 ;
    char ch ;
    gotoxy(33,2) ;
    cout <<"LIST OF BOOKS" ;
    gotoxy(32,3) ;
    cout <<"~~~~~~~~~~~~~~~" ;
    gotoxy(1,4) ;
    cout <<"CODE    BOOK NAME      AUTHOR        PUBLISHER         ADDRESS" ;
    gotoxy(1,5) ;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
    fstream file ;
    file.open("BOOK.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(BOOK)))
    {
	flag = 0 ;
	delay(100) ;
	found = 1 ;
	gotoxy(2,row) ;
	cout <<bookcode ;
	gotoxy(10,row) ;
	cout	<<name ;
	gotoxy(25,row) ;
	cout	<<author ;
	gotoxy(39,row) ;
	cout	<<pub ;
	gotoxy(57,row) ;
	cout <<addr ;
	if ( row == 22 )
	{
	    flag = 1 ;
	    row = 6 ;
	    gotoxy(1,25) ;
	    cout <<"Press any key to continue or Press <ESC> to exit" ;
	    ch = getch() ;
	    if (ch == 27)
		break ;
	    clrscr() ;
	    gotoxy(33,2) ;
	    cout <<"LIST OF BOOKS" ;
	    gotoxy(32,3) ;
	    cout <<"~~~~~~~~~~~~~~~" ;
	    gotoxy(1,4) ;
	    cout <<"CODE  BOOK NAME                        AUTHOR                    Publisher" ;
	    gotoxy(1,5) ;
	    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	}
	else
	    row = row + 2 ;
    }
    if (!found)
    {
	gotoxy(5,10) ;
	cout <<"\7Records not found" ;
    }
    if (!flag)
    {
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
    }
    file.close () ;
}

//*****************************************************************************
// THIS FUNCTION RETURN 0 IF THE GIVEN MEMBER CODE NOT FOUND.
//*****************************************************************************

int MEMBER :: member_found(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	if (memcode == mcode)
	{
	    found = 1 ;
	    break ;
	}
    }
    file.close() ;
    return found ;
}

//*****************************************************************************
// THIS FUNCTION RETURN THE LAST CODE OF THE MEMBER FILE.
//*****************************************************************************

int MEMBER :: lastcode(void)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int mcode=0 ;
    while (file.read((char *) this, sizeof(MEMBER)))
	mcode = memcode ;
    file.close() ;
    return mcode ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS MEMBER NAME OF THE GIVEN MEMBER CODE.
//*****************************************************************************

char *MEMBER :: membername(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char mname[26] ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	if (memcode == mcode)
	{
	    strcpy(mname,name) ;
	    break ;
	}
    }
    file.close() ;
    return mname ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS MEMBER PHONE NUMBER OF THE GIVEN MEMBER CODE.
//*****************************************************************************

char *MEMBER :: memberphone(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char mphone[10] ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	if (memcode == mcode)
	{
	    strcpy(mphone,phone) ;
	    break ;
	}
    }
    file.close() ;
    return mphone ;
}

//*****************************************************************************
// THIS FUNCTION RETURNS MEMBER ADDRESS OF THE GIVEN MEMBER CODE.
//*****************************************************************************

char *MEMBER :: memberaddress(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    char maddress[33] ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	if (memcode == mcode)
	{
	    strcpy(maddress,address) ;
	    break ;
	}
    }
    file.close() ;
    return maddress ;
}

//*****************************************************************************
// THIS FUNCTION DELETE RECORD FOR THE GIVEN MEMBER CODE.
//*****************************************************************************

void MEMBER :: delete_rec(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(MEMBER)) ;
	if ( file.eof() )
	    break ;
	if ( memcode != mcode )
	    temp.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("MEMBER.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(MEMBER)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION UPDATE RECORD FOR THE GIVEN MEMBER CODE.
//*****************************************************************************

void MEMBER :: update_book(int mcode, int tcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(MEMBER)) ;
	if ( file.eof() )
	    break ;
	if ( memcode == mcode )
	{
	    bookcode = tcode ;
	    temp.write((char *) this, sizeof(MEMBER)) ;
	}
	else
	    temp.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("MEMBER.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(MEMBER)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION MODIFY RECORD FOR THE GIVEN MEMBER CODE.
//*****************************************************************************

void MEMBER :: modify(int mcode, char mname[26], char mphone[10], char maddress[33])
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
	file.read((char *) this, sizeof(MEMBER)) ;
	if ( file.eof() )
	    break ;
	if ( memcode == mcode )
	{
	    strcpy(name,mname) ;
	    strcpy(phone,mphone) ;
	    strcpy(address,maddress) ;
	    temp.write((char *) this, sizeof(MEMBER)) ;
	}
	else
	    temp.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("MEMBER.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
	temp.read((char *) this, sizeof(MEMBER)) ;
	if ( temp.eof() )
	    break ;
	file.write((char *) this, sizeof(MEMBER)) ;
    }
    file.close() ;
    temp.close() ;
}

//*****************************************************************************
// THIS FUNCTION ADD RECORD IN THE FILE FOR THE GIVEN MEMBER CODE.
//*****************************************************************************

void MEMBER :: add_mem(int mcode, char mname[26], char maddress[33], char mphone[10])
{
    fstream file ;
    file.open("MEMBER.DAT", ios::app) ;
    memcode = mcode ;
    strcpy(name,mname) ;
    strcpy(phone,mphone) ;
    strcpy(address,maddress) ;
    file.write((char *) this, sizeof(MEMBER)) ;
    file.close() ;
}

//*****************************************************************************
// THIS FUNCTION DISPLAY THE RECORD FOR THE GIVEN MEMBER CODE.
//*****************************************************************************

void MEMBER :: display(int mcode)
{
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	if (memcode == mcode)
	{
	    gotoxy(5,3) ;
	    cout <<"Member Code # " <<mcode ;
	    gotoxy(5,4) ;
	    cout <<"~~~~~~~~~~~~~~~~~" ;
	    gotoxy(5,6) ;
	    cout <<"Name    : " <<name ;
	    gotoxy(5,7) ;
	    cout <<"Phone   : " <<phone ;
	    gotoxy(5,8) ;
	    cout <<"Address : " <<address ;
	    break ;
	}
    }
    file.close() ;
}

//*****************************************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE MEMBERS
//*****************************************************************************

void MEMBER :: list(void)
{
    clrscr() ;
    BOOK B ;
    int row = 6 , found=0, flag=0 ;
    char ch ;
    gotoxy(32,2) ;
    cout <<"LIST OF MEMBERS" ;
    gotoxy(31,3) ;
    cout <<"~~~~~~~~~~~~~~~~~" ;
    gotoxy(1,4) ;
    cout <<"CODE     NAME                         PHONE" ;
    gotoxy(1,5) ;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
    fstream file ;
    file.open("MEMBER.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(MEMBER)))
    {
	flag = 0 ;
	delay(20) ;
	found = 1 ;
	gotoxy(2,row) ;
	cout <<memcode ;
	gotoxy(10,row) ;
	cout	<<name ;
	gotoxy(40,row) ;
	cout <<phone ;
	if ( row == 22 )
	{
	    flag = 1 ;
	    row = 6 ;
	    gotoxy(1,25) ;
	    cout <<"Press any key to continue or Press <ESC> to exit" ;
	    ch = getch() ;
	    if (ch == 27)
		break ;
	    clrscr() ;
	    gotoxy(32,2) ;
	    cout <<"LIST OF MEMBERS" ;
	    gotoxy(31,3) ;
	    cout <<"~~~~~~~~~~~~~~~~~" ;
	    gotoxy(1,4) ;
	    cout <<"CODE  BOOK CODE   NAME                         PHONE" ;
	    gotoxy(1,5) ;
	    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	}
	else
	    row = row + 2 ;
    }
    if (!found)
    {
	gotoxy(5,10) ;
	cout <<"\n\tRecords not found" ;
    }
    if (!flag)
    {
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
    }
    file.close () ;
}

//*****************************************************************************
// FUNCTION TO DISPLAY THE BOOK FOR THE GIVEN BOOKCODE.
//*****************************************************************************

void WORKING :: searchbook(void)
{   char t1code[5];
    char  ch ;
    int t2code=0, tcode=0 ;
    int valid ;
    do
    {
	valid = 1 ;
	while (1)
	{
	    clrscr() ;
	    gotoxy(72,1) ;
	    cout <<"<0>=Exit" ;
	    gotoxy(5,5) ;
	    cout <<"Enter Code  of the Book to be Search:" ;
	    gotoxy(5,6) ;
	    cout <<"                  or                       " ;
	    gotoxy(5,7) ;
	    cout <<"Press <ENTER> for help  " ;
	    gets(t1code) ;
	    if (t1code[0] == '0')
		return ;
	    if (strlen(t1code) == 0)
	    {   BOOK B;
		B.list() ;
	    }
	    else
		break ;
	}
	t2code = atoi(t1code) ;
	tcode = t2code ;
	if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
	{
	    valid = 0 ;
	    gotoxy(5,10) ;
	    cout <<"\7Record not found" ;
	    gotoxy(5,11) ;
	    cout <<"Press <ESC> to exit or any other key to continue..." ;
	    ch = getch() ;
	    if (ch == 27)
		return ;
	}
    } while (!valid) ;
    if (tcode == 0)
	tcode = bookcodeof(t1code) ;
    clrscr() ;
    gotoxy(72,1) ;
    cout <<"<0>=Exit" ;
    BOOK::display(tcode) ;
    getch();
}

//*****************************************************************************
// THIS FUNCTION TO ADD RECORD IN THE BOOK FILE.
//*****************************************************************************

void WORKING :: add_book(void)
{   if (!reccount())  // MEMBER FUNCTION OF BOOK
	{
		add_new_book(0,"null","null","null","null") ;
		BOOK::delete_rec(0) ;
	}

    char ch ;
    int tcode ;
    char tname[33], tauthor[26] ,tpubl[33] ,taddr[50] ;

    do
    {
	int found=0, valid=0 ;
	int tc ;

	char t[10], t1[10] ;
	clrscr() ;
	gotoxy(29,3) ;
	cout <<"ADDITION OF THE BOOKS" ;
	gotoxy(29,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(72,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,25) ;
	cout <<"Enter code no. of the book" ;
	gotoxy(5,5) ;
	cout <<"Code no. " ;
	gets(t) ;
	tc = atoi(t) ;
	tcode = tc ;
	if (tcode == 0)
	    return ;
	if (book_found(tcode))
	{
	    found = 1 ;
	    gotoxy(19,8) ;
	    cout <<bookname(tcode) ;
	    gotoxy(19,9) ;
	    cout <<authorname(tcode) ;
	    gotoxy(19,10) ;
	    cout <<bookpublisher(tcode) ;
	    gotoxy(19,11);
	    cout <<bookaddr(tcode);
	}
	gotoxy(5,8) ;
	cout <<"Book Name   : " ;
	gotoxy(5,9) ;
	cout <<"Author Name : " ;
	gotoxy(5,10) ;
	cout <<"Publisher   : " ;
	gotoxy(5,11) ;
	cout <<"Address     : " ;
	valid = 0 ;
	while (!valid && !found)
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the name of the book" ;
	    gotoxy(19,8) ;
	    clreol() ;
	    gets(tname) ;
	    strupr(tname) ;
	    if (tname[0] == '0')
		return ;
	    if (strlen(tname) < 1 || strlen(tname) > 32)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\nEnter correctly (Range: 1..32)" ;
		getch() ;
	    }
	}
	valid = 0 ;
	while (!valid && !found)
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the author's name of the book" ;
	    gotoxy(19,9) ;
	    clreol() ;
	    gets(tauthor) ;
	    strupr(tauthor) ;
	    if (tauthor[0] == '0')
		return ;
	    if (strlen(tauthor) < 1 || strlen(tauthor) > 25)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\7Enter correctly (Range: 1..25)" ;
		getch() ;
	    }
	}
	valid = 0 ;
	while (!valid && !found)
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the publisher of the book" ;
	    gotoxy(19,10) ;
	    clreol() ;
	    gets(tpubl) ;
	    strupr(tpubl) ;
	    if (tpubl[0] == '0')
		return ;
	    if (strlen(tpubl) < 1 || strlen(tpubl) > 32)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\nEnter correctly (Range: 1..32)" ;
		getch() ;
	    }
	}
	valid = 0 ;
	while (!valid && !found)
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the address of the book" ;
	    gotoxy(19,11) ;
	    clreol() ;
	    gets(taddr) ;
	    strupr(taddr) ;
	    if (tname[0] == '0')
		return ;
	    if (strlen(taddr) < 1 || strlen(taddr) > 32)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\nEnter correctly (Range: 1..32)" ;
		getch() ;
	    }
	}

	gotoxy(5,25) ;
	clreol() ;
	do
	{
	    gotoxy(5,15) ;
	    clreol() ;
	    cout <<"Do you want to save (y/n) : " ;
	    ch = getche() ;
	    ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;

	if (ch == 'Y')
	{
	    if (found)
		identify_book(tcode) ;
	    else
		add_new_book(tcode,tname,tauthor,tpubl,taddr) ;
	}
	do
	{
	    gotoxy(5,17) ;
	    clreol() ;
	    cout <<"Do you want to add more (y/n) : " ;
	    ch = getche() ;
	    ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
    } while (ch == 'Y') ;
}

//*****************************************************************************
// THIS DATA TO ADD RECORD IN THE MEMBER FILE
//*****************************************************************************

void WORKING :: add_member(void)
{
    char ch ;
    int mcode ;
    char mname[26], mphone[10], maddress[33] ;
    mcode = lastcode() ;
    if (mcode == 0)
    {
	add_mem(mcode,"null","null","null") ;
	MEMBER::delete_rec(mcode) ;
    }
    mcode++ ;
    do
    {
	int valid=0 ;
	clrscr() ;
	gotoxy(28,3) ;
	cout <<"ADDITION OF THE MEMBERS" ;
	gotoxy(28,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(72,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,7) ;
	cout <<"Member Code # " <<mcode ;
	gotoxy(5,8) ;
	cout <<"~~~~~~~~~~~~~~~~~" ;
	gotoxy(5,10) ;
	cout <<"Name    : " ;
	gotoxy(5,12) ;
	cout <<"Phone   : " ;
	gotoxy(5,14) ;
	cout <<"Address : " ;
	do
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the name of the New Member" ;
	    gotoxy(15,10) ;
	    clreol() ;
	    gets(mname) ;
	    strupr(mname) ;
	    if (mname[0] == '0')
		return ;
	    if (strlen(mname) < 1 || strlen(mname) > 25)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\7Enter correctly (Range: 1..25)" ;
		getch() ;
	    }
	} while (!valid) ;
	do
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter Phone no. of the Member or Press <ENTER> for none" ;
	    gotoxy(15,12) ;
	    clreol() ;
	    gets(mphone) ;
	    if (mphone[0] == '0')
		return ;
	    if ((strlen(mphone) < 10 && strlen(mphone) > 0) || (strlen(mphone) > 12))
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\7Enter correctly" ;
		getch() ;
	    }
	} while (!valid) ;
	if (strlen(mphone) == 0)
	    strcpy(mphone,"-") ;
	do
	{
	    valid = 1 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"Enter the address of the New Member" ;
	    gotoxy(15,14) ;
	    clreol() ;
	    gets(maddress) ;
	    strupr(maddress) ;
	    if (maddress[0] == '0')
		return ;
	    if (strlen(maddress) < 1 || strlen(maddress) > 32)
	    {
		valid = 0 ;
		gotoxy(5,25) ;
		clreol() ;
		cout <<"\7Enter correctly (Range: 1..32)" ;
		getch() ;
	    }
	} while (!valid) ;
	gotoxy(5,25) ;
	clreol() ;
	do
	{
	    gotoxy(5,17) ;
	    clreol() ;
	    cout <<"Do you want to save (y/n) : " ;
	    ch = getche() ;
	    ch = toupper(ch) ;
	    if (ch == '0')
		return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'Y')
	{
	    add_mem(mcode,mname,maddress,mphone) ;
	    mcode++ ;
	    md(mname);
	}
	do
	{
	    gotoxy(5,19) ;
	    clreol() ;
	    cout <<"Do you want to add more (y/n) : " ;
	    ch = getche() ;
	    ch = toupper(ch) ;
	    if (ch == '0')
		return ;
	} while (ch != 'Y' && ch != 'N') ;
    } while (ch == 'Y') ;
}

//*****************************************************************************
// THIS FUNCTION DOWNLOAD THE BOOK
//*****************************************************************************

void WORKING :: downloadbook(void)
{
    BOOK B ;
    MEMBER M ;
    DATE D ;
    char t1code[33], ch ;
    char sor[50],dest[33],so[50],de[33];
    int t2code=0, tcode=0, mcode=0 ;
    int valid ;
    int d1, m1, y1 ;
    struct date d;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    do
    {
	valid = 1 ;
	while (1)
        {
            clrscr() ;
            gotoxy(5,2) ;
	    cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
            gotoxy(72,1) ;
            cout <<"<0>=Exit" ;
            gotoxy(5,5) ;
            cout <<"Enter Code or Name of the Book to be download" ;
            gotoxy(5,6) ;
            cout <<"                  or                       " ;
            gotoxy(5,7) ;
            cout <<"Press <ENTER> for help  " ;
            gets(t1code) ;
            if (t1code[0] == '0')
                return ;
            if (strlen(t1code) == 0)
		B.list() ;
            else
                break ;
        }
        t2code = atoi(t1code) ;
        tcode = t2code ;
        if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
        {
            valid = 0 ;
            gotoxy(5,10) ;
            cout <<"\7Record not found" ;
            gotoxy(5,11) ;
            cout <<"Press <ESC> to exit or any other key to continue..." ;
	    ch = getch() ;
            if (ch == 27)
                return ;
        }
    } while (!valid) ;
    if (tcode == 0)
	tcode = bookcodeof(t1code) ;


    do
    {
        valid = 1 ;
        while (1)
	{
            clrscr() ;
            gotoxy(72,1) ;
            cout <<"<0>=Exit" ;
            gotoxy(5,2) ;
            cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
            gotoxy(5,5) ;
            cout <<"Book Name: " <<bookname(tcode) ;
            gotoxy(5,7) ;
            cout <<"Enter Code no. of the Member" ;
            gotoxy(5,8) ;
            cout <<"            or              " ;
            gotoxy(5,9) ;
	    cout <<"Press <ENTER> for help  " ;
            gets(t1code) ;
            if (t1code[0] == '0')
                return ;
            if (strlen(t1code) == 0)
                M.list() ;
            else
                break ;
        }
        t2code = atoi(t1code) ;
        mcode = t2code ;
        if (mcode == 0)
        {
	    valid = 0 ;
            gotoxy(5,25) ;
            cout <<"\7Enter Correctly" ;
            getch() ;
        }
        if (!member_found(mcode) && valid)
        {
            valid = 0 ;
            gotoxy(5,13) ;
            cout <<"\7Record not found" ;
            gotoxy(5,14) ;
	    cout <<"Press <ESC> to exit or any other key to continue..." ;
	    ch = getch() ;
	    if (ch == 27)
		return ;
	}
    } while (!valid) ;
    identify_book(tcode) ;  // member function of BOOK
    update_book(mcode,tcode) ;  // member function of MEMBER

    strcpy(sor,B.bookaddr(tcode));
    strcpy(dest,M.membername(mcode));
    copy(sor,dest);
    getch();
    gotoxy(5,13) ;
    cout <<"\7Book is downloading to " <<membername(mcode) ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(5,15) ;
    cprintf(" ! BOOK DOWNLOADED ! ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    getch();

}

//*****************************************************************************
// THIS FUNCTION TO MODIFY THE BOOK RECORD
//*****************************************************************************

void WORKING :: modify_book(void)
{
    BOOK B ;
    char t1code[5], tname[33], tauthor[26], ch ,taddr[50],tpub[33];
    int t2code=0, tcode=0 ;

    int valid ;
    do
    {
	valid = 1 ;
	while (1)
	{
	    clrscr() ;
	    gotoxy(72,1) ;
	    cout <<"<0>=Exit" ;
	    gotoxy(5,5) ;
	    cout <<"Enter Code or Name of the Book to be modified" ;
	    gotoxy(5,6) ;
	    cout <<"                  or                       " ;
	    gotoxy(5,7) ;
	    cout <<"Press <ENTER> for help  " ;
	    gets(t1code) ;
	    if (t1code[0] == '0')
		return ;
	    if (strlen(t1code) == 0)
		B.list() ;
	    else
		break ;
	}
	t2code = atoi(t1code) ;
	tcode = t2code ;
	if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
	{
	    valid = 0 ;
	    gotoxy(5,10) ;
	    cout <<"\7Record not found" ;
	    gotoxy(5,11) ;
	    cout <<"Press <ESC> to exit or any other key to continue..." ;
	    ch = getch() ;
	    if (ch == 27)
		return ;
	}
    } while (!valid) ;
    if (tcode == 0)
	tcode = bookcodeof(t1code) ;
    clrscr() ;
    gotoxy(72,1) ;
    cout <<"<0>=Exit" ;
    BOOK::display(tcode) ;
    do
    {
	gotoxy(5,13) ;
	clreol() ;
	cout <<"Do you want to modify this record (y/n) : " ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch == '0')
	    return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
	return ;
    gotoxy(5,16) ;
    cout <<"Book Name   : " ;
    gotoxy(5,17) ;
    cout <<"Author Name : " ;
    gotoxy(5,18) ;
    cout <<"Publisher   : " ;
    gotoxy(5,19);
    cout <<"Address     : " ;
    do
    {
	valid = 1 ;
	gotoxy(5,25) ;
	clreol() ;
	cout <<"Enter the name of the book or <ENTER> for no change" ;
	gotoxy(19,16) ;
	clreol() ;
	gets(tname) ;
	strupr(tname) ;
	if (tname[0] == '0')
	    return ;
	if (strlen(tname) > 32)
	{
	    valid = 0 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"\7Enter correctly (Range: 1..32)" ;
	    getch() ;
	}
    } while (!valid) ;
    if (strlen(tname) == 0)
	strcpy(tname,bookname(tcode)) ;
    do
    {
	valid = 1 ;
	gotoxy(5,25) ;
	clreol() ;
	cout <<"Enter the author's name or <ENTER> for no change" ;
	gotoxy(19,17) ;
	clreol() ;
	gets(tauthor) ;
	strupr(tauthor) ;
	if (tauthor[0] == '0')
	    return ;
	if (strlen(tauthor) > 25)
	{
	    valid = 0 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"\nEnter correctly (Range: 1..25)" ;
	    getch() ;
	}
    } while (!valid) ;
    if (strlen(tauthor) == 0)
	strcpy(tauthor,authorname(tcode)) ;
    do
    {
	valid = 1 ;
	gotoxy(5,25) ;
	clreol() ;
	cout <<"Enter the Publisher's name or <ENTER> for no change" ;
	gotoxy(19,18) ;
	clreol() ;
	gets(tpub) ;
	strupr(tpub) ;
	if (tpub[0] == '0')
	    return ;
	if (strlen(tpub) > 33)
	{
	    valid = 0 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"\nEnter correctly (Range: 1..25)" ;
	    getch() ;
	}
    } while (!valid) ;
    if (strlen(tpub) == 0)
	strcpy(tpub,bookpublisher(tcode)) ;
     do
    {
	valid = 1 ;
	gotoxy(5,25) ;
	clreol() ;
	cout <<"Enter the address of the book or <ENTER> for no change" ;
	gotoxy(19,19) ;
	clreol() ;
	gets(taddr) ;
	strupr(taddr) ;
	if (taddr[0] == '0')
	    return ;
	if (strlen(taddr) > 32)
	{
	    valid = 0 ;
	    gotoxy(5,25) ;
	    clreol() ;
	    cout <<"\7Enter correctly (Range: 1..32)" ;
	    getch() ;
	}
    } while (!valid) ;
    if (strlen(taddr) == 0)
	strcpy(taddr,bookaddr(tcode)) ;
    do
    {   gotoxy(5,25) ;
	clreol() ;
	cout <<" " ;
	gotoxy(5,20) ;
	clreol() ;
	cout <<"Do you want to save changes (y/n) : " ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch == '0')
	    return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
	return ;
    BOOK::modify(tcode,tname,tauthor,taddr,tpub) ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(27,22) ;
    cprintf(" RECORD MODIFIED ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    getch() ;
}

//*****************************************************************************
// THIS FUNCTION TO MODIFY THE MEMBER RECORD
//*****************************************************************************

void WORKING :: modify_member(void)
{
    MEMBER M ;
    char m1code[10], mname[26], mphone[10], maddress[33], ch ;
    int m2code=0, mcode=0 ;
    int valid ;
    do
    {
	valid = 1 ;
	while (1)
	{
            clrscr() ;
            gotoxy(72,1) ;
            cout <<"<0>=Exit" ;
            gotoxy(5,7) ;
            cout <<"Enter Code no. of the Member to be Modify" ;
            gotoxy(5,8) ;
            cout <<"                        or              " ;
            gotoxy(5,9) ;
            cout <<"Press <ENTER> for help  " ;
            gets(m1code) ;
            m2code = atoi(m1code) ;
            mcode = m2code ;
	    if (m1code[0] == '0')
                return ;
            if (strlen(m1code) == 0)
                M.list() ;
            else
                break ;
        }
        if (mcode == 0)
        {
            valid = 0 ;
            gotoxy(5,25) ;
            cout <<"\7Enter Correctly" ;
            getch() ;
	}
        if (valid && !member_found(mcode))
        {
            valid = 0 ;
            gotoxy(5,13) ;
            cout <<"\7Record not found" ;
            gotoxy(5,14) ;
            cout <<"Press <ESC> to exit or any other key to continue..." ;
            ch = getch() ;
            if (ch == 27)
                return ;
        }
    } while (!valid) ;
    clrscr() ;
    gotoxy(72,1) ;
    cout <<"<0>=Exit" ;
    MEMBER::display(mcode) ;
    do
    {
        gotoxy(5,10) ;
        clreol() ;
        cout <<"Do you want to modify this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
        return ;
    gotoxy(5,13) ;
    cout <<"Name    : " ;
    gotoxy(5,14) ;
    cout <<"Phone   : " ;
    gotoxy(5,15) ;
    cout <<"Address : " ;
    do
    {
        valid = 1 ;
        gotoxy(5,25) ;
	clreol() ;
        cout <<"Enter the name of the member or <ENTER> for no change" ;
        gotoxy(19,13) ;
        clreol() ;
        gets(mname) ;
        strupr(mname) ;
        if (mname[0] == '0')
            return ;
        if (strlen(mname) > 25)
        {
            valid = 0 ;
            gotoxy(5,25) ;
            clreol() ;
	    cout <<"\7Enter correctly (Range: 1..25)" ;
            getch() ;
        }
    }
    while (!valid) ;
    if (strlen(mname) == 0)
        strcpy(mname,membername(mcode)) ;
    do
    {
        valid = 1 ;
        gotoxy(5,25) ;
        clreol() ;
        cout <<"Enter the Phone no. of Member or <ENTER> for no change" ;
	gotoxy(19,14) ;
        clreol() ;
        gets(mphone) ;
        if (mphone[0] == '0')
            return ;
	if ((strlen(mphone) < 10 && strlen(mphone) > 0) || (strlen(mphone) > 12))
        {
            valid = 0 ;
            gotoxy(5,25) ;
            clreol() ;
            cout <<"\7Enter correctly" ;
            getch() ;
        }
    } while (!valid) ;
    if (strlen(mphone) == 0)
        strcpy(mphone,memberphone(mcode)) ;
    do
    {
        valid = 1 ;
        gotoxy(5,25) ;
        clreol() ;
        cout <<"Enter the address of the member or <ENTER> for no change" ;
        gotoxy(19,15) ;
        clreol() ;
        gets(maddress) ;
        strupr(maddress);
	if(maddress[0]== '0')
            return ;
        if (strlen(maddress) > 32)
        {
            valid = 0 ;
            gotoxy(5,25) ;
            clreol() ;
            cout <<"\7Enter correctly (Range: 1..32)" ;
            getch() ;
        }
    } while (!valid) ;
    if (strlen(maddress) == 0)
        strcpy(maddress,memberaddress(mcode)) ;
    gotoxy(5,25) ;
    clreol() ;
    do
    {
        gotoxy(5,18) ;
        clreol() ;
        cout <<"Do you want to save changes (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
	return ;
    MEMBER::modify(mcode,mname,mphone,maddress) ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(27,20) ;
    cprintf(" RECORD MODIFIED ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    getch() ;
}

//*****************************************************************************
// THIS FUNCTION TO DELETE THE BOOK RECORD
//*****************************************************************************

void WORKING :: delete_book(void)
{
    BOOK B ;
    char t1code[5], tname[33], tauthor[26], ch ;
    int t2code=0, tcode=0 ;
    int valid ;
    do
    {
        valid = 1 ;
        while (1)
	{
            clrscr() ;
            gotoxy(72,1) ;
            cout <<"<0>=Exit" ;
            gotoxy(5,5) ;
            cout <<"Enter Code or Name of the Book to be Deleted" ;
            gotoxy(5,6) ;
            cout <<"                  or                       " ;
            gotoxy(5,7) ;
            cout <<"Press <ENTER> for help  " ;
	    gets(t1code) ;
            if (t1code[0] == '0')
                return ;
	    if (strlen(t1code) == 0)
                B.list() ;
            else
                break ;
        }
        t2code = atoi(t1code) ;
        tcode = t2code ;
        if ((tcode == 0 && !bookname_found(t1code)) || (tcode != 0 && !book_found(tcode)))
        {
            valid = 0 ;
	    gotoxy(5,10) ;
            cout <<"\7Record not found" ;
            gotoxy(5,11) ;
	    cout <<"Press <ESC> to exit or any other key to continue..." ;
            ch = getch() ;
            if (ch == 27)
                return ;
        }
    } while (!valid) ;
    if (tcode == 0)
	tcode = bookcodeof(t1code) ;
    clrscr() ;
    gotoxy(72,1) ;
    cout <<"<0>=Exit" ;
    BOOK::display(tcode) ;
    do
    {
        gotoxy(5,13) ;
        clreol() ;
        cout <<"Do you want to delete this record (y/n) : " ;
        ch = getche() ;
	ch = toupper(ch) ;
	if (ch == '0')
	    return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
	return ;
    BOOK::delete_rec(tcode) ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(27,22) ;
    cprintf(" RECORD DELETED ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    getch() ;
}

//*****************************************************************************
// THIS FUNCTION TO DELETE THE MEMBER RECORD.
//*****************************************************************************

void WORKING :: delete_member(void)
{
    MEMBER M ;
    char m1code[5], mname[26], mphone[10], maddress[33], ch ;
    int m2code=0, mcode=0 ;
    int valid ;
    do
    {
        valid = 1 ;
        while (1)
        {
	    clrscr() ;
            gotoxy(72,1) ;
	    cout <<"<0>=Exit" ;
            gotoxy(5,7) ;
            cout <<"Enter Code no. of the Member to be Deleted" ;
            gotoxy(5,8) ;
            cout <<"                        or              " ;
            gotoxy(5,9) ;
            cout <<"Press <ENTER> for help  " ;
            gets(m1code) ;
            m2code = atoi(m1code) ;
            mcode = m2code ;
            if (m1code[0] == '0')
		return ;
            if (strlen(m1code) == 0)
		M.list() ;
            else
                break ;
        }
        if (mcode == 0)
        {
            valid = 0 ;
            gotoxy(5,25) ;
            cout <<"\7Enter Correctly" ;
            getch() ;
        }
	if (valid && !member_found(mcode))
        {
	    valid = 0 ;
            gotoxy(5,13) ;
            cout <<"\7Record not found" ;
            gotoxy(5,14) ;
            cout <<"Press <ESC> to exit or any other key to continue..." ;
            ch = getch() ;
            if (ch == 27)
                return ;
        }
    } while (!valid) ;
    clrscr() ;
    gotoxy(72,1) ;
    cout <<"<0>=Exit" ;
    MEMBER::display(mcode) ;
    do
    {
        gotoxy(5,10) ;
        clreol() ;
        cout <<"Do you want to Delete this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'Y' && ch != 'N') ;
    if (ch == 'N')
	return ;
    MEMBER::delete_rec(mcode) ;
    textcolor(BLACK+BLINK) ;
    textbackground(WHITE) ;
    gotoxy(27,22) ;
    cprintf(" RECORD DELETED ") ;
    textcolor(LIGHTGRAY) ;
    textbackground(BLACK) ;
    getch() ;
}

//*****************************************************************************
// MAIN FUNCTION CALLING INTRODUCTION AND MAIN MENU.
//*****************************************************************************
void main(void)
{
    MENU menu ;
    menu.intro() ;
    menu.main_menue() ;
}
