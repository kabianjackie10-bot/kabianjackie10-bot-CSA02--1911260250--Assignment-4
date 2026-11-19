#include <stdio.h>
#include <string.h>
typedef struct{int day,month,year;} Date;
typedef struct{int systolic,diastolic;} BP;
typedef struct{char name[40],phone[16];int age;BP bp;Date visit;} Patient;
void addPatient(Patient *p,const char *name,int age,const char *phone,BP bp,Date d){snprintf(p->name,sizeof p->name,"%s",name);snprintf(p->phone,sizeof p->phone,"%s",phone);p->age=age;p->bp=bp;p->visit=d;}
int main(void){Patient p;BP b={120,80};Date d={19,11,2026};addPatient(&p,"Kumar",45,"9876543210",b,d);printf("%s %d %s BP %d/%d %02d/%02d/%04d\\n",p.name,p.age,p.phone,p.bp.systolic,p.bp.diastolic,p.visit.day,p.visit.month,p.visit.year);return 0;}
