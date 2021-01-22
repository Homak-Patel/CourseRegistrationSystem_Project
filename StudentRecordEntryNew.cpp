#include<stdio.h>
#include<conio.h>
struct Student{
	int enr;
	char fname[20];
	char lname[20];
	char programme[10];
	char pass[15];	
};
int main(){
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
	return 0;
}
