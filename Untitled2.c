#include<stdio.h>
struct student
{
	int roll_number;
	char name[100];
	int age;
    float cgpa;
};
void printStructure(struct student *s1)
{
	printf("Student Information:\n");
	printf("Roll Number is %d\n",s1->roll_number);
	printf("Name is %s\n",s1->name);
	printf("Age is %d\n",s1->age);
	printf("CGPA is %0.2f",s1->cgpa);
}
int main()
{
	struct student s1;
	struct student *s_ptr;
	s_ptr=&s1; 
	scanf("%d",&s_ptr->roll_number);
	scanf("%s",s_ptr->name);
	scanf("%d",&s_ptr->age);
	scanf("%f",&s_ptr->cgpa);
	/*printf("Student Information:\n");
	printf("Roll Number is %d\n",s_ptr->roll_number);
	printf("Name is %s\n",s_ptr->name);
	printf("Age is %d\n",s_ptr->age);
	printf("CGPA is %0.2f",s_ptr->cgpa);*/
	printStructure(s_ptr);
}
