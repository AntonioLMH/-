//
// Created by murui on 2019-01-03.
//
#include <stdio.h>

typedef struct {
    int   studentID;
    int   age;
    char  gender;
    float WAM;
} PersonT;

void method_b(void) {
    PersonT per1;
    PersonT per2;
    PersonT *ptr;

    ptr = &per1;
    per1.studentID = 3141592;
    ptr->gender = 'M';
    ptr = &per2;
    ptr->studentID = 2718281;
    ptr->gender = 'F';
    per1.age = 25;
    per2.age = 24;
    ptr = &per1;
    per2.WAM = 86.0;
    ptr->WAM = 72.625;


    printf("==================\nper1:\n");

    printf("student Id is %d, age is %d,gender is %c, WAM is %f \n",per1.studentID,per1.age,per1.gender,per1.WAM);

    printf("==================\nper2:\n");
    printf("student Id is %d, age is %d,gender is %c, WAM is %f \n",per2.studentID,per2.age,per2.gender,per2.WAM);


}

void method_a(void) {
    int data[12] = {5, 3, 6, 2, 7, 4, 9, 1, 8};
    printf("value is %p \n",data + 4);
    printf("value is %d \n",*data + 4);
    printf("value is %d \n",*(data + 4));
    printf("value is %d \n",data[4]);
    printf("value is %d \n",*(data + *(data + 3)));
    printf("value is %d \n",data[data[2]]);
}

int main(void) {

    method_b();

}
