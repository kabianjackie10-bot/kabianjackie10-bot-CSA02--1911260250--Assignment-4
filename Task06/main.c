#include <stdio.h>
#include <string.h>
typedef struct{int d,m,y;} Date;
enum Kind{PACKAGED,COOKED,COMBO};
typedef struct{char name[24];float price;int stock;enum Kind kind;union{Date expiry;int prepared_minute;int components[3];}detail;} Item;
void sell(Item *p,int qty,float *revenue){if(qty<=0||qty>p->stock){printf("Sale rejected: %s\\n",p->name);return;}p->stock-=qty;*revenue+=qty*p->price;printf("Sold %d %s; stock=%d\\n",qty,p->name,p->stock);}
int main(void){Item a[3]={{"Milk",30,5,PACKAGED,.detail.expiry={21,11,2026}},{"Idli",20,10,COOKED,.detail.prepared_minute=480},{"Combo",80,3,COMBO,.detail.components={0,1,0}}};float revenue[3]={0};sell(&a[0],2,&revenue[0]);sell(&a[1],12,&revenue[1]);sell(&a[2],1,&revenue[2]);for(int i=0;i<3;i++)printf("%s revenue=%.2f\\n",a[i].name,revenue[i]);return 0;}
