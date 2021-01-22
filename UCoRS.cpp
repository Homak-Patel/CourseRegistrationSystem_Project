#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Student{
	int enr;
	char fname[20];
	char lname[10];
	char programme[10];
	char pass[10];
};
struct Course{
	char cCode[30];
	int credits;
	int nSeats;
};
struct Log{
	int enr;
	char cCode[30];
	time_t currentTime;
};
void displayWelcomePage(){
	printf("Welcome to University Course Registration System \n");
	printf("1.Login as student.\n2.Login as administrator.\n");
}
int login(int sel,int enr,char pass[10]){
	int rv=-1;
	if(sel==2){
		
		int userID[3]={101,102,103};
		char passwordArray[3][20]={"abcd1234","catchMe","helloWorld"};
		int idIndex=-1;
		for(int i=0;i<3;i++){
			if(enr==userID[i]){
				idIndex=i;
				
			}
		}
		if(idIndex==-1){
			rv=0;
		}
		else{
			if(strcmp(pass,passwordArray[idIndex])==0){
				rv=1;;
			}
			else{
				rv=0;
			}
		}
		
	}
	if(sel==1){
		struct Student stu;
		FILE *fp;
		fp=fopen("student.txt","r");
		while(fread(&stu,sizeof(struct Student),1,fp)){
			if(enr==stu.enr){
				if(strcmp(pass,stu.pass)==0){
					rv=1;
				}
				else{
					rv=0;
				}
			}
			
		}
		fclose(fp);
	}
	return rv;
}
void displayOptions(int sel){
	if(sel==1){
		printf("Welcome!\n");
		printf("1.View Course directory.\n");
		printf("2.Register courses for Summer2020.\n");
		printf("3.View Registration log.\n");
		printf("4.Logout.\n");
	}
	else
		if(sel==2){
			printf("Welcome!\n");
			printf("1.Add new student\n");
			printf("2.Add new course\n");
			printf("3.Check Registration Log\n");
			printf("4.Logout\n");
		}
}
void viewCourseDirectory(){
	
	FILE *fp;	 
	 char ch;
	
	fp = fopen("CourseDirectory.txt","r");
	ch = fgetc(fp);
	
	while(ch != EOF){
	  	printf("%c",ch);  
		ch=fgetc(fp);
	}
	fclose(fp);
	back:
	printf("\n\nEnter '0' to go back...");
	int ret;
	scanf("%d",&ret);
	if(ret!=0){
		goto back;
	}
	else{
		system("cls");
	}
		
}
void courseRegistration(int enrID){
	system("cls");
	struct Course co;
	FILE *fp;
	fp=fopen("course.txt","rb");
	searchCourse:
	printf("Enter Course Code:");
	char code[30];
	scanf("%s",code);
	int checkAvailability=-1;
	int totalSeats=0;
	while(fread(&co,sizeof(struct Course),1,fp)){
		if(strcmp(co.cCode,code)==0){
			checkAvailability=1;
			totalSeats=co.nSeats;
		}
		
	}
	
	if(checkAvailability==1){
		check:
		printf("\n1.Add this course\n2.Back\n");
		int addCheck=0;
		scanf("%d",&addCheck);
		if(addCheck==2){
			
		}
		else
			if(addCheck!=1){
			goto check;
		}
		
		else{
			FILE *lg;
			lg=fopen("RegistrationLog.txt","ab+");
			struct Log l1;
			l1.enr=enrID;
			strcpy(l1.cCode,code);
			time(&l1.currentTime);
			fwrite(&l1,sizeof(struct Log),1,lg);
			if(fwrite!=0){
				printf("Successfully Added!\n");
				printf("Enter any character...");
				char buff[2];
				scanf("%s",&buff);
			}
			fclose(lg);
		}
		
	}
	else{
		printf("Course unavailable.\n");
		goto searchCourse;
	}
	
}
void viewRegistrationLog(int enrID){
		printf("Course Code\t\tTime\n");
		struct Log studentLog;
		FILE *lg;
		lg=fopen("RegistrationLog.txt","rb");
		while(fread(&studentLog,sizeof(struct Log),1,lg)){
			if(studentLog.enr==enrID){
				printf("%s\t\t\t%s",studentLog.cCode,ctime(&studentLog.currentTime));
			}
		}
		fclose(lg);
		printf("\n\nEnter '0' to go back...");
		goBack:
		int backCheck;
		scanf("%d",&backCheck);
		if(backCheck!=0){
			goto goBack;
		}
	
}
void addStudent(){
	struct Student s1;
	FILE *fp;
	fp=fopen("student.txt","ab+");
	
	printf("Enrollment number: ");
	scanf("%d",&s1.enr);
	
	printf("Enter first name: ");
	scanf("%s",s1.fname);
	
	printf("Enter last name: ");
	scanf("%s",s1.lname);
	
	printf("Enter programme: ");
	scanf("%s",s1.programme);
	
	printf("Enter password: ");
	scanf("%s",s1.pass);
	
	
	fwrite(&s1,sizeof(struct Student),1,fp);
	if(fwrite!=0){
		printf("Success!");
	}
	fclose(fp);
}
void addCourse(){
	struct Course co;
	FILE *fp;
	fp=fopen("course.txt","ab+");
	printf("Enter course code:");
	scanf("%s",co.cCode);
	printf("Enter credits:");
	scanf("%d",&co.credits);
	printf("Enter total number of seats:");
	scanf("%d",&co.nSeats);
	fwrite(&co,sizeof(struct Course),1,fp);
	if(fwrite!=0){
		printf("Success!");
	}
}
void checkOverallRegistrationLog(){
	printf("Enrollment number \t\t Course Code \t\t\t Time\n");
		struct Log studentLog;
		FILE *lg;
		lg=fopen("RegistrationLog.txt","rb");
		while(fread(&studentLog,sizeof(struct Log),1,lg)){
				printf("%d \t\t\t %s \t\t\t %s",studentLog.enr,studentLog.cCode,ctime(&studentLog.currentTime));
			
		}
		fclose(lg);
		goBack:
		printf("\n\nEnter '0' to go back...");
		int backCheck;
		scanf("%d",&backCheck);
		if(backCheck!=0){
			goto goBack;
		}
}
int main(){
	welcome:
	displayWelcomePage();
	int sel=0;
	scanf("%d",&sel);
	loginPage:
	system("cls");	
	printf("Enter Username:");
	int enrID;
	scanf("%d",&enrID);
	printf("Enter password: ");
	char password[10];
	scanf("%s",password);
	int loginAccess=login(sel,enrID,password);
	if(loginAccess==0){
		printf("Invalid Username/Password\n\n");
		goto loginPage;
	}
	else{
		displayOptions(sel);
	}
	optionSelection:
	int sel2=0;
	scanf("%d",&sel2);
	if(sel==2){
			if(sel2==1){
				addStudent();
				displayOptions(sel);
				goto optionSelection;
			}
			if(sel2==2){
				addCourse();
				displayOptions(sel);
				goto optionSelection;
			}
			if(sel2==3){
				checkOverallRegistrationLog();
				system("cls");
				displayOptions(sel);
				goto optionSelection;
			}
			if(sel2==4){
				system("cls");
				goto welcome;
			}	
		
	}	
	if(sel==1){
		
		if(sel2==1){
			viewCourseDirectory();	
			displayOptions(sel);
			goto optionSelection;
		}
		if(sel2==2){
			courseRegistration(enrID);
			system("cls");
			displayOptions(sel);
			goto optionSelection;	
		}
		if(sel2==3){
			viewRegistrationLog(enrID);
			system("cls");
			displayOptions(sel);
			goto welcome;
		}
		if(sel2==4){
			system("cls");
			goto welcome;
		}
	}
}
