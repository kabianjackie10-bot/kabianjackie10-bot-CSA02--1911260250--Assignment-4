#include <stdio.h>
typedef struct{int day,month,year;} Date;
typedef struct{char city[20];int pincode;} Address;
typedef struct{int id;float weight;Address to;Date booked;} Parcel;
void print_parcel(const Parcel *p){printf("%d %.1f kg %s-%06d %02d/%02d/%04d\\n",p->id,p->weight,p->to.city,p->to.pincode,p->booked.day,p->booked.month,p->booked.year);}
void sort_by_weight(Parcel p[],int n){for(int i=0;i<n-1;i++){int m=i;for(int j=i+1;j<n;j++)if(p[j].weight<p[m].weight)m=j;if(m!=i){Parcel t=p[i];p[i]=p[m];p[m]=t;}}}
int main(void){Parcel p[3]={{501,4.5f,{"Madurai",625001},{12,10,2026}},{502,1.2f,{"Chennai",600077},{12,10,2026}},{503,2.8f,{"Coimbatore",641001},{13,10,2026}}};sort_by_weight(p,3);for(int i=0;i<3;i++)print_parcel(&p[i]);return 0;}
