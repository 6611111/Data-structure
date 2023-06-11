#include<stdio.h>
struct student
{
	int roll_number;
	char name[100];
	int age;
    float cgpa;
};
int main()
{
	struct student s1; 
	scanf("%d",&s1.roll_number);
	scanf("%s",s1.name);
	scanf("%d",&s1.age);
	scanf("%0.2f",&s1.cgpa);
	printf("Student Information:\n");
	printf("Roll Number is %d\n",s1.roll_number);
	printf("Name is %s\n",s1.name);
	printf("Age is %d\n",s1.age);
	printf("CGPA %0.2f\n",s1.cgpa);
}
