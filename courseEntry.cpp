#include<stdio.h>
#include<conio.h>
struct Course{
	char cCode[30];
	int nSeats;
	int credits;
};
int main(){
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
