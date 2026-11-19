#include <stdio.h>
enum kind{TEMPERATURE,HUMIDITY,STATUS};
typedef struct{enum kind type;union{float celsius;int percent;char status[8];}value;} Reading;
void show(const Reading *r){switch(r->type){case TEMPERATURE:printf("Temp %.1f C\\n",r->value.celsius);break;case HUMIDITY:printf("Humidity %d %%\\n",r->value.percent);break;case STATUS:printf("Status %s\\n",r->value.status);break;}}
int main(void){Reading a[]={{TEMPERATURE,{.celsius=31.5f}},{HUMIDITY,{.percent=68}},{STATUS,{.status="OK"}}};printf("sizeof union = %zu, sizeof struct reading = %zu\\n",sizeof a[0].value,sizeof a[0]);for(int i=0;i<3;i++)show(&a[i]);return 0;}
