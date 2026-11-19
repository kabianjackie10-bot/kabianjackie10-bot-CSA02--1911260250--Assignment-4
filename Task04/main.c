#include <stdio.h>
typedef struct{int number;float balance;} Account;
void addInterest(Account *a,float rate){a->balance+=a->balance*rate/100.0f;}
int main(void){Account a[]={{101,5000},{102,12000},{103,800}};for(int i=0;i<3;i++){printf("before %p ",(void*)&a[i]);addInterest(&a[i],4);printf("after %.2f\\n",a[i].balance);}return 0;}
