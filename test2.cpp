#include<stdio.h>
#include<time.h>
struct Time{
	time_t currentTime;
};
int main(){
	struct Time t1;
	time(&t1.currentTime);   
    printf("%s",ctime(&t1.currentTime));

}
