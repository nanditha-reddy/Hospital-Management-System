//MINI PROJECT - HOSPITAL MANAGEMENT SYSTEM
//1602-19-737-171 - G. Shri Pallavi
//1602-19-737-141 - N. Nanditha Reddy

//HEADER FILES
#include<windows.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>	//For strcmp(),strcpy(),strlen(),etc
#include<stdio.h>	//For standard I/O Operation
#include<conio.h>	//For delay(),getch(),gotoxy(),etc.
#include<ctype.h>	//For toupper(), tolower(),etc

//FUNCTION DECLARATIONS
//WelcomeScreen Function
void WelcomeScreen(void);

//Title Function 
void Title(void);

//RegisterLogin Function 
void RegisterLogin(void);

//Exit Function
void Exit(void);

//Actor1 - Patient
void PLogin();		
void Pat_Register();		
void Pat_Login();
void PatientMenu(char[]);	
void SearchDoctor();
void MakeAppointment(char[]);
void CheckAppointment();
void Unregister(char[]);

//Actor2 - Admin
void ALogin();
void AdminMenu();
void AddPatient();
void PatientList();
void AddDoctor();
void EditPatientRecord();
void CheckDoctors();
void GiveAppointment();
void DeleteUser();

//Actor3 - Receptionist
void RLogin();
void ReceptionistMenu();
void PatientsList();
void ViewPatientDetails();
void CheckPatientAppointments();
void CheckDoctorsAppLeft();

//Actor4 - Doctor 
void DLogin();
void DoctorMenu();
void MyPatients(char[]);
void CancelAppointment();



//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};//sets co-ordinates in (x,y).
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Patient
{
	char Username[30];
	char Password[20];
	int Age;
	char Gender;
	char Name[20]; 
	char Contact[15];
	char Address[30];
	char Email[30];
	char Problem[50];
};
struct Patient  p, temp_c, l, iter;

struct doctor
{
	char Username[30];
	char Password[20];
	int Age;
	char Gender;
	char Name[30]; 
	char Contact[15];
	char Address[30];
	char spec[30];
	char appointments;
};
struct doctor d,iter1;

char ans=0; 
int ok;
int b, valid=0;

int main(void)
{
    system("color 07");
	//Use to call WelcomeScreen Function
	WelcomeScreen();
	//Use to call Title Function
	Title();
	//Use to call Register and Login Functions
	RegisterLogin();
	return 0;
}

void WelcomeScreen(void) 
{
	system("cls");
	system("color 09"); 
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t----------------------------------------\n\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	printf("\n\n\t\t\t\t\t\t\t WELCOME TO HOSPITAL MANAGEMENT SYSTEM\n\n");
	printf("\n\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	printf("\t\t\t\t\t\t\t----------------------------------------");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Press Any Key to Continue......\n");
	getch();//Use to holds screen for some seconds
	system("cls");//Use to clear screen
}

//Function for Title Screen
void Title(void)
{
	printf("\n\n\t\t--------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t\t    VASAVI HOSPITAL - A Place Where Healing Starts         ");
	printf("\n\t\t--------------------------------------------------------------------------------------------------------------------------------------------");
}

//Function to Exit
void Exit(void)
{ 
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\t\t\t\t\tTHANK YOU FOR VISITING :)\n\n\n");
	getch();//holds screen
}

//Function for Register or Login 
void RegisterLogin()
{
	system("cls");
	system("color 09"); 
	int select;
	// call Title function
	Title();
	printf("\n\n\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 1. Are you a Patient ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 2. Are you an Admin ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 3. Are you a Receptionist ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 4. Are you a Doctor ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 5. Exit\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\tChoose from 1 to 5: ");
	scanf("%i", &select);	fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				PLogin();//PLogin function is called
				break;
		case 2:
				ALogin();//ALogin function is called
				break;
		case 3:
				RLogin();//RLogin function is called
				break;
		case 4:
				DLogin();//DLogin function is called
				break;
		case 5:
				Exit();//Exit function is called
				break;
		default:
				printf("\n\n\n\n\t\t\t\t\t----------------------------Invalid Entry...Choose Again--------------------------");
				getch();//holds screen
	}//end of switch
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PLogin()
{
	int select, ch;
	system("cls");
	system("color 06"); 
	// call Title function
	Title();
	printf("\n\n\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 1. Are you a New Patient ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 2. Are you already a Member of the Hospital ?\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 3. Go Back?\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\tChoose from 1 to 3: ");
	scanf("%i", &select);		fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t============================================\n\t\t\t\t\t\t\t\tPLEASE CONSULT ADMIN FOR CREATING AN ACCOUNT\n\t\t\t\t\t\t\t\t============================================");
				getch();
				RegisterLogin();
				break;
		case 2:
				Pat_Login();// Patient Login function is called
				break;
		case 3:
				RegisterLogin();//Exit function is called
				break;
		default:
				printf("\n\n\n\n\t\t\t\t\t----------------------------Invalid Entry...Choose Again--------------------------");
				getch();//holds screen
				PLogin();
				break;
	}//end of switch
}

void Pat_Login()
{
	system("cls");
	FILE *fp;
	int flag = 0;
	char username[30],pwd[20];
	printf("\n\n\t\t\t\t============================================ PATIENT'S LOGIN ============================================");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Username: ");
	gets(username);
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Password: ");
	gets(pwd);
	fp = fopen("Patients.txt","r");
	while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", iter.Username,iter.Password, iter.Name, &iter.Gender, &iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem)!=EOF)
	{
		if(strcmp(iter.Username, username)==0)
		{
			flag = 1;
			if (strcmp(iter.Password, pwd)==0)
			{
				printf("\n\n\n\n\t\t\t\t\t\t\t----------------------------Logging in--------------------------");
				Sleep(1000);
				fclose(fp);
				PatientMenu(username);
			}
			else
			{
				fclose(fp);
				printf("\n\n\n\n\n\n\n\t\t\t\t---------------------------------------- WRONG PASSWORD...PLEASE ENTER AGAIN ------------------------------------");
				Sleep(1000);
				Pat_Login();
			}
		}
	}
	if(flag == 0)
	{
		printf("\n\n\t\t\t--------------------------USERNAME NOT FOUND...Please Give Correct Details-----------------------------");
		fclose(fp);
		Sleep(1000);
		PLogin();
	}
}

void PatientMenu(char username[30])
{
	system("cls");
	system("color 02"); 
	int select;
	// call Title function
	Title();
	printf("\n\n\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 1. View Doctors List\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 2. Make an Appointment\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 3. Check Your Appointments\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 4. Unregister from Hospital\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 5. Logout\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\tChoose from 1 to 5: ");
	scanf("%i", &select);	fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				SearchDoctor(username);//SearchDoctor function is called
				break;
		case 2:
				MakeAppointment(username);//MakeAppointment function is called
				break;
		case 3:
				CheckAppointment(username);//CheckStatus function is called
				break;
		case 4:
				Unregister(username);//Unregister funtion is called
				RegisterLogin();
				break;
		case 5:
				RegisterLogin();//Exit function is called
				break;
		default:
				printf("\n\n\n\n\t\t\t\t\t----------------------------Invalid Entry...Choose Again--------------------------");
				getch();//holds screen
				break;
	}//end of switch
}

void SearchDoctor(char username[30])
{
	system("cls");
	Title();
	FILE *fp;
	char doctorName[30],spec[30];
	fp = fopen("doctorslist.txt","r");
	printf("\n\n\t\t\t\t============================================ DOCTOR'S LIST ============================================");
	printf("\n\n\n\n\t\t\t\t\t\t\tDOCTOR NAME\t\t\t\t\tSPECIALIZATION\n");
	printf("\n\t\t\t\t\t\t\t-----------\t\t\t\t\t--------------\n");
	while(fscanf(fp,"%s %s\n",doctorName,spec) != EOF)
	{
		printf("\t\t\t\t\t\t\t%s\t\t\t\t\t%s\n",doctorName,spec);
	}
	fclose(fp);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\tEnter any key to continue");
	getch();
	PatientMenu(username);
}

void MakeAppointment(char username[30])
{
	FILE *fp,*fp1,*fp2;
	char doctorName[30],doct[30],verify[5],left1[5];
	char appLeft[5],left;
	int i = 0,choice,flag = 0;
	fp1 = fopen("AvailableAppointments.txt","r");
	fp = fopen("PatientAppointments.txt","a+");
	printf("\n\n\t\t\t\t\t----------------------------DOCTORS AND APPOINTMENTS LEFT----------------------------\n");
	while(fscanf(fp1,"%s %s\n",doctorName,appLeft) != EOF)
	{
		printf("\n\t\t\t\t\t\t\t\t\t%s\t%s",doctorName,appLeft);
	}
	fclose(fp1);

	printf("\n\n\t\t\t\t\t---------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\tEnter Doctor Name : ");
	gets(doct);
	printf("\n\t\t\t\t\t\t\t\tENTER 'YES' TO CONFIRM APPOINTMENT : ");
	gets(verify);

	if(strcmp(verify,"YES") == 0)
	{
		fp1 = fopen("AvailableAppointments.txt","r");
		fp2 = fopen("NewAppointments.txt","w+");
		while(fscanf(fp1,"%s %s\n",doctorName,appLeft) != EOF)
		{
			if(strcmp(doctorName,doct) == 0)
			{	
				flag = 1;
				left = atoi(appLeft);
				if(left>0)
				{
					left--;
					itoa(left,left1,10);
					printf("\n\n\t\t\t\t\t\t\t\t!!!!!!!! APPOINTMENT BOOKED !!!!!!!!");
					fprintf(fp2,"%s %s\n",doctorName,left1);
					fprintf(fp,"%s %s\n",username,doctorName);
				}
				else
				{
					printf("\n\n\n\t\t\t\t\t\t\t\tNO APPOINTMENTS LEFT FOR THIS DOCTOR");
					fprintf(fp2,"%s %s\n",doctorName,appLeft);
				}
			}
			else
			{
				fprintf(fp2,"%s %s\n",doctorName,appLeft);
			}
		}
		if(flag != 1)
		{
			printf("\n\t\t\t\t\t\t\t\tINVALID DOCTOR NAME");
		}
		fclose(fp1);
		fclose(fp2);
		remove("AvailableAppointments.txt");
		rename("NewAppointments.txt","AvailableAppointments.txt");
	}
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\tVERIFICATION FAILED! ENTER ANY KEY TO GO BACK");
	}
	fclose(fp);
	getch();
	PatientMenu(username);
}

void CheckAppointment(char username[30])
{
	FILE *fp;
	int counter = 0;
	char PatName[30],DocName[30];
	fp = fopen("PatientAppointments.txt","r");
	while(fscanf(fp,"%s %s\n",PatName,DocName) != EOF )
	{
		if(strcmp(PatName,username) == 0)
		{
			counter++;
			printf("\n\t\t\xDB YOU HAVE APPOINTMENT WITH - %s\n",DocName);
		}
	}
	if(counter == 0)
	{
		printf("\n\t\t\tYOU DID NOT BOOK ANY APPOINTMENTS !");
	}
	fclose(fp);
	getch();
	PatientMenu(username);
}

void Unregister(char username[30])
{
	FILE *fp,*fp1;
	fp = fopen("Patients.txt","r");
	fp1 = fopen("temp.txt","w+");
	while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", iter.Username,iter.Password, iter.Name, &iter.Gender, &iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem)!=EOF)
	{
		if(strcmp(iter.Username,username) == 0)
		{
			printf("\n\t\t------------------YOUR ACCOUNT IS SUCCESSFULLY DELETED----------------\n");
			printf("\n\t\t       ENTER ANY KEY TO GO BACK TO MAINMENU.");
		}
		else
		{
			fprintf(fp1,"%s %s %s %c %i %s %s %s %s\n", iter.Username, iter.Password, iter.Name, iter.Gender, iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("Patients.txt");
	rename("temp.txt","Patients.txt");
	getch();
	RegisterLogin();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ALogin()//function for login screen for Admin
{
	//list of variables	
	char Username[15];
	char Password[15];
	char original_Username[25]="admin@gmail.com";
	char original_Password[15]="admin";
	
	system("cls");
	system("color 05"); 
	Title();	
	printf("\n\n\t\t\t\t=============================================== ADMIN'S LOGIN ===============================================");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Username: ");
	gets(Username);
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Password: ");
	gets(Password);
	
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\n\t\t\t\t\t\t------------------------------- Login Successful -----------------------------");
		Sleep(1000);
		AdminMenu();//call Menu function
	}
	else
	{
		printf("\n\n\n\n\t\t\t\t\t----------------------------Invalid Credentials...Enter Again--------------------------");
		getch();
		ALogin();
	}
}

void AdminMenu()
{
	system("cls");
	system("color 70"); 
	int select;
	// call Title function
	Title();
	printf("\n\n\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 1. Add a Patient\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 2. List of Patients\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 3. Edit List of Patients\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 4. Add Doctor\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 5. Check List of Doctors\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 6. Give an Appointment\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 7. Delete an User\n");
	printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB 8. Logout\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\tChoose from 1 to 8: ");
	scanf("%i", &select); 	fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				AddPatient();//AddPatients function is called
				break;
		case 2:
				PatientList();//PatientList function is called
				break;
		case 3:
				EditPatientRecord();//EditPatientRecord function is called
				break;
		case 4:
				AddDoctor();
				break;
		case 5:
				CheckDoctors();//CheckDoctors funtion is called
				break;
		case 6:
				GiveAppointment();//GiveAppointment function is called
				break;
		case 7:
				DeleteUser();//DeleteUser funtion is called
				break;
		case 8:
				RegisterLogin();//Exit function is called
				break;
		default:
				printf("\n\n\n\n\t\t\t\t\t----------------------------Invalid Entry...Choose Again--------------------------");
				getch();//holds screen
				AdminMenu();
				break;
	}//end of switch*/
}

void AddPatient()
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE *fp,*fp1;//file pointer
	char username[30];
	fp1 = fopen("Patients.txt","r");
	fp = fopen("Patients.txt","a+");//open file in write mode
	printf("\n\n\t\t\t\t======================================= ADD PATIENT'S RECORD =======================================");
	
	/* **************************User Name*********************************** */
	A:
	printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Username: ");
	gets(username);
	while(fscanf(fp1,"%s %s %s %c %i %s %s %s %s\n", iter.Username, iter.Password, iter.Name, &iter.Gender, &iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem) != EOF)
	{
		if(strcmp(username,iter.Username) == 0)
		{
			printf("\n\t\t\t\t\t--------------------------------USERNAME ALREADY EXISTS------------------------------");
			goto A;
		}
	}
	strcpy(p.Username,username);
	if(strlen(p.Username)>25||strlen(p.Username)<5)
	{
		printf("\n\t\t\t\t\t-------------------Invalid Username...The max range for Username is 25 and min range is 5-------------------");
		goto A;
	}
	/* **************************Password*********************************** */
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Password: ");
	gets(p.Password);
	/* ********************************************** Full Name ************************************************ */
	B:
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Full Name: ");
    gets(p.Name);
    p.Name[0]=toupper(p.Name[0]);
    if(strlen(p.Name)>25||strlen(p.Name)<5)
	{
		printf("\n\t\t\t\t\t-------------------Invalid FullName...The max range for FullName is 25 and min range is 5-------------------");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Name);b++)
		{
			if (isalpha(p.Name[b]))
			{ 
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t\t\t\t-------------------Full Name contains an Invalid character...Enter again-------------------");
			goto B;
		}
	}
	/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Gender[F/M/O]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F' || toupper(p.Gender)=='O')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t\t\t\t-------------------Gender contains Invalid character...Enter either F or M or O-------------------");
    	}
	}	while(!ok);
	/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Age: ");
    scanf(" %i",&p.Age);	fflush(stdin);
	/* **************************************** Address ******************************************************************* */    
	C:
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Address: ");
	gets(p.Address);
	p.Address[0]=toupper(p.Address[0]);
	if(strlen(p.Address)>30||strlen(p.Address)<8)
	{
		printf("\n\t\t\t\t\t-------------------Invalid Address...The max range for address is 20 and min range is 8-------------------");
		goto C;
	}
	
	/* ******************************************* Contact no. ***************************************** */
	do
	{
		D:
		printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Contact: ");
		gets(p.Contact);
		if(strlen(p.Contact)>10||strlen(p.Contact)!=10)
		{
			printf("\n\t\t\t\t\t-------------------Invalid...Contact must contain 10 numbers...Enter again\n\t-------------------");
			goto D;
		}
		else
		{
			for (b=0;b<strlen(p.Contact);b++)
			{
				if (!isalpha(p.Contact[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t\t\t\t-------------------Contact contains Invalid character...Enter again...-------------------");
				goto D;
			}
		}
	}while(!valid);
	/* ************************************************** Email ******************************************** */
	do
	{
		printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Email: ");
		gets(p.Email);
		if (strlen(p.Email)>30||strlen(p.Email)<8)
		{
		printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
		}
	}while(strlen(p.Email)>30||strlen(p.Email)<8);
	/* ********************************************************* Problem *********************************************** */
	E:
    printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Problem: ");
    gets(p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>15||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contains Invalid character :(  Enter again :)");
			goto E;
		}
	}
	
    fprintf(fp,"%s %s %s %c %i %s %s %s %s\n", p.Username,p.Password, p.Name, p.Gender, p.Age, p.Address, p.Contact, p.Email, p.Problem);
    printf("\n\t\t\t\t\t--------------------------------INFORMATION RECORD SUCCESSFULL------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Patient Username : %s \n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Patient Password : %s",p.Username,p.Password);
    fclose(fp);//fp file is closed
	fclose(fp1);
	sd:
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Do you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
		AddPatient();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t\t\t\t------------------------------------- THANK YOU ------------------------------------------\n");
		getch();
		AdminMenu();
	}
    else
    {
        printf("\n\t\t\t\t\t------------------------------------- INVALID INPUT ------------------------------------------\n");
        goto sd;
    }
}

void PatientList()
{
	int row;
	system("cls");
	Title();
	FILE *fp;
	fp=fopen("Patients.txt","r");
	printf("\n\n\t\t\t\t======================================= LIST OF PATIENTS =======================================");
		gotoxy(1,15);
		printf("UserName");
		gotoxy(25,15);
		printf("FullName");
		gotoxy(45,15);
		printf("Gender");
		gotoxy(55,15);
		printf("Age");
		gotoxy(60,15);
		printf("Address");
		gotoxy(85,15);
		printf("Contact");
		gotoxy(100,15);
		printf("Email");
		gotoxy(125,15);
		printf("Problem\n");
		printf("======================================================================================================================================");
		row=17;
		while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",p.Username);
			gotoxy(25,row);
			printf("%s",p.Name);
			gotoxy(45,row);
			printf("%c",p.Gender);
			gotoxy(55,row);
			printf("%i",p.Age);
			gotoxy(60,row);
			printf("%s",p.Address);
			gotoxy(85,row);
			printf("%s",p.Contact);
			gotoxy(100,row);
			printf("%s",p.Email);
			gotoxy(125,row);
			printf("%s",p.Problem);
			row++;
		}
	fclose(fp);
	getch();
	AdminMenu();
}

void EditPatientRecord()
{
	FILE *fp, *r;
	int k = 0,t = 0, upAge;
	char upGender,temp;
	char patUserName[30],name[50], upName[20], upAddress[20], upPhno[15], upEm[35],upProblem[30];
	r = fopen("temp.txt", "w+");
	if ((fp = fopen("Patients.txt", "r")) == NULL)
	{
		printf("NO PATIENT RECORDS ADDED.");
		getch();
	}
	else
	{
		printf("\nENTER USERNAME OF PATIENT TO EDIT : \n");
		gets(patUserName);
		while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem) != EOF)
		{
            if(strcmp(patUserName,p.Username) == 0)
            {
				k = 1;
				printf("\n\n\t---------------------New Record---------------------");
				printf("\nEnter New Name           : ");
				gets(upName);
				printf("\nEnter New Address        : ");
				gets(upAddress);
				printf("\nEnter New Phone number   : ");
				gets(upPhno);
				printf("\nEnter New Gender    : ");
				scanf(" %c", &upGender);		scanf("%c",&temp);
				printf("\nEnter New Email          : ");
				gets(upEm);
				printf("\nEnter New Age         : ");
				scanf("%i", &upAge);			scanf("%c",&temp);
				printf("\nEnter New Problem         : ");
				gets(upProblem);
				fflush(stdin);
				fprintf(r, "%s %s %s %c %i %s %s %s %s\n", p.Username,p.Password,upName,upGender, upAge,upAddress,upPhno,upEm,upProblem);
				printf("\nPATIENT DETAILS SUCCESSFULLY UPDATED !");
            }
            else
            {
                fprintf(r, "%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, p.Gender, p.Age, p.Address, p.Contact, p.Email, p.Problem);
            }
		}
		if (k == 0)
		{
			printf("\n\nNO RECORDS WITH THIS USERNAME OF PATIENT NAME !");
		}
	}
	fclose(r);
	fclose(fp);
	remove("Patients.txt");
	rename("temp.txt", "Patients.txt");
	getch();
	AdminMenu();
}

void AddDoctor()
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE *fp,*fp1,*fp2,*fp3;//file pointer
	char username[30];
	fp1 = fopen("Doctors.txt","r");
	fp = fopen("Doctors.txt","a+");//opening files
	fp2 = fopen("AvailableAppointments.txt","a+");
	fp3 = fopen("DoctorsList.txt","a+");
	printf("\n\n\t\t\t\t======================================= ADD DOCTOR'S RECORD =======================================");
	
	/* **************************User Name*********************************** */
	A:
	printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB User Name: ");
	gets(username);
	while(fscanf(fp1,"%s %s %s %c %i %s %s %s %c\n", iter1.Username, iter1.Password, iter1.Name, &iter1.Gender, &iter1.Age, iter1.Address, iter1.Contact, iter1.spec, &iter1.appointments) != EOF)
	{
		if(strcmp(username,iter1.Username) == 0)
		{
			printf("\n\t USERNAME ALREADY EXISTS !");
			goto A;
		}
	}
	strcpy(d.Username,username);
	if(strlen(d.Username)>25||strlen(d.Username)<5)
	{
		printf("\n\t Invalid Username\t The max range for first name is 25 and min range is 5");
		goto A;
	}
	/* **************************Password*********************************** */
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Password : ");
	gets(d.Password);
	/* ********************************************** Full Name ************************************************ */
	B:
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Full Name of Doctor : ");
    gets(d.Name);
    d.Name[0]=toupper(d.Name[0]);
    if(strlen(d.Name)>25||strlen(d.Name)<5)
	{
		printf("\n\t Invalid...\t The max range for Full name is 25 and min range is 5");
		goto B;
	}
	/* ******************************************* Gender ************************************************************** */	    
	do
	{
		printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Gender[F/M]: ");
		scanf(" %c",&d.Gender);
		if(toupper(d.Gender)=='M'|| toupper(d.Gender)=='F' || toupper(d.Gender)=='O')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
		{
			printf("\n\t\t Gender contains Invalid character Enter either F or M or O");
		}
	}	while(!ok);
	/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Age:");
    scanf(" %i",&d.Age);	fflush(stdin);
	/* **************************************** Address ******************************************************************* */    
	C:
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Address: ");
	gets(d.Address);
	d.Address[0]=toupper(d.Address[0]);
	if(strlen(d.Address)>20||strlen(d.Address)<8)
	{
		printf("\n\t Invalid...\t The max range for address is 20 and min range is 8");
		goto C;
	}

	/* **************************************** Contact ******************************************************************* */
	do
	{
		D:
		printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Contact: ");
		gets(d.Contact);
		if(strlen(d.Contact)>10||strlen(d.Contact)!=10)
		{
			printf("\n\t Invalid.....Contact must contain 10 numbers. Enter again");
			goto D;
		}
		else
		{
			for (b=0;b<strlen(d.Contact);b++)
			{
				if (!isalpha(d.Contact[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact no. contain Invalid character....Enter again...");
				goto D;
			}
		}
	}while(!valid);

	/* **************************************** speciaization ******************************************************************* */
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Specialisation: ");
	gets(d.spec);
	/* **************************************** No.of appointments ******************************************************************* */
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB No. of Appointments per day : ");
	scanf(" %c",&d.appointments);	fflush(stdin);

	/* **************************************** Adding to file ******************************************************************* */

	fprintf(fp,"%s %s %s %c %i %s %s %s %c\n", d.Username, d.Password, d.Name, d.Gender, d.Age, d.Address, d.Contact, d.spec, d.appointments);
	fprintf(fp2,"%s %c",d.Name,d.appointments);
	fprintf(fp3,"%s %s\n",d.Name,d.spec);
    printf("\n\t\t\t\t\t--------------------------------INFORMATION RECORD SUCCESSFULL------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Doctor Username : %s \n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Doctor Password : %s",d.Username,d.Password);
    fclose(fp);//fp file is closed
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	sd:
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Do you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
		AddPatient();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t\t\t\t------------------------------------- THANK YOU ------------------------------------------\n");
		getch();
		AdminMenu();
	}
    else
    {
        printf("\n\t\t\t\t\t------------------------------------- INVALID INPUT ------------------------------------------\n");
        goto sd;
    }
}

void CheckDoctors()
{
	system("cls");
	FILE *fp;
	char doctorName[30],spec[30];
	fp = fopen("doctorslist.txt","r");
	printf("\n\n\t\t!!!!!!!!!!!!!!!! List of Doctors !!!!!!!!!!!!!\n");
	printf("\n\t\t\tDOCTOR NAME\t\tSPECIALIZATION\n\n");
	while(fscanf(fp,"%s %s\n",doctorName,spec) != EOF)
	{
		printf("\t\t\t%s\t\t%s\n",doctorName,spec);
	}
	fclose(fp);
	printf("\nEnter any key to continue");
	getch();
	AdminMenu();
}

void GiveAppointment()
{
	system("cls");
	FILE *f,*fp,*fp1,*fp2;
	char doctorName[30],doct[30],verify[5],left1[5],username[30];
	char appLeft[5],left;
	int i = 0,choice,flag = 0, temp = 0;
	f = fopen("Patients.txt","r");
	fp = fopen("PatientAppointments.txt","a+");
	fp1 = fopen("AvailableAppointments.txt","r");
	
	printf("\n\t\t\t-------DOCTORS AND APPOINTMENTS LEFT-------\n");
	while(fscanf(fp1,"%s %s\n",doctorName,appLeft) != EOF)
	{
		printf("%s - %s\n",doctorName,appLeft);
	}
	fclose(fp1);
	printf("\n=============================================================");
	printf("\n\tEnter username of Patient : ");
	gets(username);
	printf("\n\tEnter doctor name for appointment : ");
	gets(doct);
	printf("\n\n\tENTER 'YES' TO CONFIRM APPOINTMENT : ");
	gets(verify);
	if(strcmp(verify,"YES") == 0)
	{
		while(fscanf(f,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem) != EOF)
		{
			if(strcmp(username,p.Username) == 0)
			{
				temp = 1;
				fp1 = fopen("AvailableAppointments.txt","r");
				fp2 = fopen("NewAppointments.txt","w+");
				while(fscanf(fp1,"%s %s\n",doctorName,appLeft) != EOF)
				{
					if(strcmp(doctorName,doct) == 0)
					{	
						flag = 1;
						left = atoi(appLeft);
						if(appLeft>0)
						{
							left--;
							itoa(left,left1,10);
							printf("\n\n\t YOUR APPOINTMENT IS BOOKED !");
							Sleep(1000);
							fprintf(fp2,"%s %s\n",doctorName,left1);
							fprintf(fp,"%s %s\n",username,doctorName);
						}
						else
						{
							printf("\n\n\t NO APPOINTMENTS LEFT FOR THIS DOCTOR !");
							fprintf(fp2,"%s %s\n",doctorName,appLeft);
						}
					}
					else
					{
						fprintf(fp2,"%s %s\n",doctorName,appLeft);
					}
				}
				if(flag != 1)
				{
					printf("\n\tINVALID DOCTOR NAME");
				}
				fclose(fp1);
				fclose(fp2);
				remove("AvailableAppointments.txt");
				rename("NewAppointments.txt","AvailableAppointments.txt");
			}
		}
		if(temp != 1)
		{
			printf("PATIENT WITH THE SPECIFIED USERNAME IS NOT FOUND !");
		}
	}
	fclose(f);
	fclose(fp);
	getch();
	AdminMenu();
}

void DeleteUser()
{
	system("cls");
	char username[30];
	FILE *fp,*fp1;
	fp = fopen("Patients.txt","r");
	fp1 = fopen("temp.txt","w+");
	printf("\n\n\t\t!!!!!!!!!!!!!!!! Delete a Patient Record !!!!!!!!!!!!!\n");
	printf("\n\n\n\t\tENTER USERNAME OF THE PATIENT : ");
	gets(username);
	while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", iter.Username,iter.Password, iter.Name, &iter.Gender, &iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem)!=EOF)
	{
		if(strcmp(iter.Username,username) == 0)
		{
			printf("\n\t\t------ YOUR ACCOUNT IS SUCCESSFULLY DELETED ! -----");
			printf("\n\t\t       ENTER ANY KEY TO GO BACK TO MAINMENU.");
		}
		else
		{
			fprintf(fp1,"%s %s %s %c %i %s %s %s %s\n", iter.Username, iter.Password, iter.Name, iter.Gender, iter.Age, iter.Address, iter.Contact, iter.Email, iter.Problem);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("Patients.txt");
	rename("temp.txt","Patients.txt");
	getch();
	AdminMenu();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RLogin()//function for login screen for Receptionist
{
	//list of variables	
	char Username[15];
	char Password[15];
	char original_Username[25]="receptionist@gmail.com";
	char original_Password[15]="receptionist";
	
	system("cls");
	Title();                 
	printf("\n\n\t\t\t\t=============================================== RECEPTIONIST'S LOGIN ===============================================");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Username: ");
	scanf("%s",&Username);
	printf("\n\t\t\t\t\t\t\t\t\t\xDB\xDB Enter Password: ");
	scanf("%s",&Password);
	
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\t...Login Successfull...");
		getch();
		ReceptionistMenu();//call Menu function
	}
	else
	{
		printf("\n\t\t\tPassword in incorrect.Try Again.");
		getch();
		RLogin();
	}
}

void ReceptionistMenu()
{
	system("cls");
	system("color 09");
	int select;
	// call Title function
	Title();                 
	printf("\n\t\t\t\t1. View List of Patients\n");
	printf("\n\t\t\t\t2. View Details of a Patient\n");
	printf("\n\t\t\t\t3. Check Appointments of a patient\n");
	printf("\n\t\t\t\t4. Check Available Appointments of Doctors\n");
	printf("\n\t\t\t\t5. Go back\n");
	printf("\n\n\n\n\t\t\t\tChoose from 1 to 3: ");
	scanf("%i", &select);		fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				PatientsList();// PatientDetails function is called
				break;
		case 2:
				ViewPatientDetails();// SearchPatient(); function is called
				break;
		case 3:
				CheckPatientAppointments();
				break;
		case 4:
				CheckDoctorsAppLeft();
				break;
		case 5:
				RegisterLogin();// MainMenu function is called
				break;
		default:
				printf("\t\t\tInvalid entry. Please Select the Right Option. ");
				getch();//holds screen
				ReceptionistMenu();
				break;
	}//end of switch
}

void PatientsList()
{
	int row;
	system("cls");
	Title();
	FILE *fp;
	fp=fopen("Patients.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("UserName");
		gotoxy(25,15);
		printf("FullName");
		gotoxy(45,15);
		printf("Gender");
		gotoxy(55,15);
		printf("Age");
		gotoxy(60,15);
		printf("Address");
		gotoxy(85,15);
		printf("Contact");
		gotoxy(100,15);
		printf("Email");
		gotoxy(125,15);
		printf("Problem\n");
		printf("======================================================================================================================================");
		row=17;
		while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",p.Username);
			gotoxy(25,row);
			printf("%s",p.Name);
			gotoxy(45,row);
			printf("%c",p.Gender);
			gotoxy(55,row);
			printf("%i",p.Age);
			gotoxy(60,row);
			printf("%s",p.Address);
			gotoxy(85,row);
			printf("%s",p.Contact);
			gotoxy(100,row);
			printf("%s",p.Email);
			gotoxy(125,row);
			printf("%s",p.Problem);
			row++;
		}
	fclose(fp);
	getch();
	ReceptionistMenu();
}

void ViewPatientDetails()
{
	char username[30];
	int flag = 0;
	system("cls");
	Title();// call Title function
	FILE *fp;
	fp=fopen("Patients.txt","r");
	gotoxy(12,8);
	printf("\n Enter Patient's UserName to be viewed : ");
	gets(username);
	printf("\n\n\t\t\t!!!!!!!!!!!!!! View Patient Details !!!!!!!!!!!!!\n");
	while(fscanf(fp,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem)!=EOF)
	{
		if(strcmp(p.Username,username)==0)
		{
			flag = 1;
			printf("\n\n\t\t\t\tUSERNAME         :   %s",p.Username);
			printf("\n\t\t\t\tPATIENT NAME     :   %s",p.Name);
			printf("\n\t\t\t\tGENDER           :   %c",p.Gender);
			printf("\n\t\t\t\tAGE              :   %i",p.Age);
			printf("\n\t\t\t\tADDRESS          :   %s",p.Address);
			printf("\n\t\t\t\tCONTACT          :   %s",p.Contact);
			printf("\n\t\t\t\tEMAIL            :   %s",p.Email);
			printf("\n\t\t\t\tPROBLEM          :   %s",p.Problem);
			printf("\n=================================================================================================================");
		}
	}
	if(flag == 0)
	{
		printf("\n\t\t\t\tPATIENT RECORDS NOT FOUND !");
	}
	fclose(fp);
	getch();
	ReceptionistMenu();
}

void CheckPatientAppointments()
{
	char username[30];
	FILE *fp;
	int counter = 0;
	char PatName[30],DocName[30];
	printf("\n Enter Patient's UserName to Check : ");
	gets(username);
	fp = fopen("PatientAppointments.txt","r");
	while(fscanf(fp,"%s %s\n",PatName,DocName) != EOF )
	{
		if(strcmp(PatName,username) == 0)
		{
			counter++;
			printf("\n\n\t\tPATIENT HAVE APPOINTMENT WITH - %s\n",DocName);
		}
	}
	if(counter == 0)
	{
		printf("\n\t\tPATIENT DON'T HAVE ANY APPOINTMENTS !");
	}
	fclose(fp);
	getch();
	ReceptionistMenu();
}

void CheckDoctorsAppLeft()
{
	FILE *fp1;
	char doctorName[30],appLeft[30];
	fp1 = fopen("AvailableAppointments.txt","r");
	printf("\n\t\t\t-------DOCTORS AND APPOINTMENTS LEFT-------\n");
	while(fscanf(fp1,"%s %s\n",doctorName,appLeft) != EOF)
	{
		printf("\t\t\t\t%s     -     %s\n",doctorName,appLeft);
	}
	fclose(fp1);
	getch();
	ReceptionistMenu();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DLogin()//function for login screen for Receptionist
{
	system("cls");
	FILE *fp;
	int flag = 0;
	char username[30],pwd[20];
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Doctors Login !!!!!!!!!!!!!\n");
	printf("Enter Username: ");
	gets(username);
	printf("\nEnter Password: ");
	gets(pwd);
	fp = fopen("Doctors.txt","r");
	while(fscanf(fp,"%s %s %s %c %i %s %s %s %c\n", iter1.Username, iter1.Password, iter1.Name, &iter1.Gender, &iter1.Age, iter1.Address, iter1.Contact, iter1.spec, &iter1.appointments)!=EOF)
	{
		if(strcmp(iter1.Username, username)==0)
		{
			flag = 1;
			if (strcmp(iter1.Password, pwd)==0)
			{
				printf("\n\n\t\t\t----------------------------Logging in--------------------------");
				Sleep(1000);
				fclose(fp);
				DoctorMenu(iter1.Name);
			}
			else
			{
				fclose(fp);
				printf("\n\n\t\t\t--------------------------Wrong Password...Please Give Correct Details-----------------------------");
				Sleep(1000);
				DLogin();
			}
		}
	}
	if(flag == 0)
	{
		printf("\n\n\t\t\t--------------------------Username not found...Please Give Correct Details-----------------------------");
		fclose(fp);
		Sleep(1000);
		RegisterLogin();
	}
}

void DoctorMenu(char doctorname[30])
{
	system("cls");
	system("color 06");
	int select;
	// call Title function
	Title();
	printf("\n\n\n\t\t\t\t1. View Patients Assigned to you\n");
	printf("\n\t\t\t\t2. Cancel Appointment\n");
	printf("\n\t\t\t\t3. Logout\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 3: ");
	scanf("%d",&select);		fflush(stdin);
	switch(select)//switch to different case
	{
		case 1:
				MyPatients(doctorname);// PatientDetails function is called
				break;
		case 2:
				CancelAppointment(doctorname);// CancelAppointment function is called
				break;
		case 3:
				RegisterLogin();// Exit function is called
				break;
		default:
				printf("\t\t\tInvalid entry. Please Select the Right Option. ");
				getch();//holds screen
				DoctorMenu(doctorname);
	}//end of switch*/
}

void MyPatients(char doctorname[30])
{
	FILE *fp,*fp1;
	char PatID[30],DocName[30];
	int counter=0;
	fp = fopen("PatientAppointments.txt","r");
	printf("\n\t\t\t\t\tDOCTOR NAME : %s",doctorname);
	while(fscanf(fp,"%s %s\n",PatID,DocName) != EOF )
	{
		if(strcmp(DocName,doctorname) == 0)
		{
			fp1 = fopen("Patients.txt","r");
			printf("\n========================================================================================================");
			printf("\n\t\tYOUR APPOINTMENT HAS BEEN WITH PATIENT OF USERNAME - %s\n",PatID);
			printf("\n\tDETAILS OF PATIENT : ");
			while(fscanf(fp1,"%s %s %s %c %i %s %s %s %s\n", p.Username, p.Password, p.Name, &p.Gender, &p.Age, p.Address, p.Contact, p.Email, p.Problem)!=EOF)
			{
				if(strcmp(p.Username,PatID) == 0)
				{
					counter++;
					printf("\n\t\tNAME    : %s",p.Name);
					printf("\n\t\tGENDER  : %c",p.Gender);
					printf("\n\t\tAGE     : %i",p.Age);
					printf("\n\t\tCONTACT : %s",p.Contact);
					printf("\n\t\tEMAIL   : %s",p.Email);
					printf("\n\t\tPROBLEM : %s",p.Problem);
				}
			}
			fclose(fp1);
		}
	}
	printf("\n========================================================================================================");
	if(counter == 0)
	{
		printf("\n\t\t\t\t\tNO CONSULTATIONS");
	}
	fclose(fp);
	getch();
	DoctorMenu(doctorname);
}

void CancelAppointment(char doctorname[30])
{
	char patientID[30],PatID[30],DocName[30];
	int flag = 0;
	FILE *fp,*fp1;
	fp = fopen("PatientAppointments.txt","r");
	fp1 = fopen("temp.txt","w+");
	printf("\n\n\t\t\tENTER PATIENT USERNAME TO DELETE APPOINTMENT : ");
	gets(patientID);
	while(fscanf(fp,"%s %s\n",PatID,DocName) != EOF )
	{
		if(strcmp(DocName,doctorname) == 0)
		{
			if(strcmp(PatID,patientID) == 0)
			{
				flag = 1;
			}
			else
			{
				fprintf(fp1,"%s %s\n",PatID,DocName);
			}
		}
		else
		{
			fprintf(fp1,"%s %s\n",PatID,DocName);
		}
	}
	if(flag == 1)
	{
		printf("\n\t\t\t   YOUR APPOINTMENT FOR THIS PATIENT IS DELETED!");
	}
	else
	{
		printf("\n\t\tPATIENT NOT FOUND IN YOUR APPOINTMENTS LIST !");
	}
	fclose(fp);
	fclose(fp1);
	remove("PatientAppointments.txt");
	rename("temp.txt","PatientAppointments.txt");
	getch();
	DoctorMenu(doctorname);
}

