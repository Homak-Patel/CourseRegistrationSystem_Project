#include<stdio.h>
#include<string.h>
struct Student{
	int enr;
	char fname[20];
	char lname[20];
	char programme[10];
	char pass[15];	
};
struct Course{
	char cCode[30];
	int credits;
	int nSeats;
	
};
int checkLogin(int sel,int enr,char pw[15]){
	int rv=-1;
	struct Student stu;
	FILE *fp;
	fp=fopen("student.txt","rb");
	while(fread(&stu,sizeof(struct Student),1,fp)){
		if(enr==stu.enr){
			if(strcmp(pw,stu.pass)==0){
				rv=1;
			}
		
	}
	fclose(fp);
	return rv;
	
	}
}
int main(){
	FILE *fp;
	struct Course stu;
	fp=fopen("course.txt","rb");
	while(fread(&stu,sizeof(struct Course),1,fp)){
		printf("%s\t%d\t%d\n",stu.cCode,stu.credits,stu.nSeats);
	}
	fclose(fp);
}
