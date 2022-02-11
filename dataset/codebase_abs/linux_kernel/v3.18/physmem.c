void T_1 F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
unsigned long V_6 , V_7 ;
V_4 = V_1 >> V_8 ;
V_6 = V_2 >> V_8 ;
V_5 = V_3 >> V_8 ;
V_7 = V_4 + V_6 + V_5 ;
V_9 = V_7 ;
}
void F_2 ( unsigned long V_10 , unsigned long V_11 , unsigned long V_12 ,
int V_13 , int V_14 , int V_15 )
{
T_2 V_16 ;
int V_17 , V_18 ;
V_17 = F_3 ( V_11 , & V_16 ) ;
V_18 = F_4 ( ( void * ) V_10 , V_17 , V_16 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_18 ) {
if ( V_18 == - V_19 )
F_5 ( V_20 L_1
L_2
L_3 ) ;
F_6 ( L_4
L_5 , V_10 , V_17 , V_16 , V_12 , V_13 , V_14 , V_15 , V_18 ) ;
}
}
void T_1 F_7 ( unsigned long V_21 , unsigned long V_22 ,
unsigned long V_12 , unsigned long long V_3 )
{
unsigned long V_23 = V_22 - V_21 ;
int V_24 = F_8 ( F_9 ( V_22 ) ) ;
int V_25 = ( V_12 - V_23 ) >> V_8 ;
int V_18 , V_16 , V_26 ;
V_27 = F_10 ( V_12 + V_3 ) ;
V_16 = V_28 - V_29 ;
V_18 = F_4 ( ( void * ) V_28 , V_27 , V_16 ,
V_12 - V_16 , 1 , 1 , 1 ) ;
if ( V_18 < 0 ) {
printf ( L_6
L_7 , V_12 - V_16 ,
( void * ) V_28 , V_18 ) ;
exit ( 1 ) ;
}
F_11 ( V_27 , F_9 ( & V_30 ) ) ;
F_12 ( V_27 , & V_30 , V_31 ) ;
F_13 ( V_27 ) ;
V_26 = F_14 ( V_24 , V_24 + V_25 ) ;
F_15 ( F_9 ( V_22 ) + V_26 ,
V_12 - V_26 - V_23 ) ;
}
int F_3 ( unsigned long V_11 , unsigned long long * V_32 )
{
int V_17 = - 1 ;
if ( V_11 < V_33 ) {
V_17 = V_27 ;
* V_32 = V_11 ;
}
else if ( V_11 < F_9 ( V_34 ) ) {
struct V_35 * V_36 = V_37 ;
while ( V_36 != NULL ) {
if ( ( V_11 >= V_36 -> V_11 ) &&
( V_11 < V_36 -> V_11 + V_36 -> V_38 ) ) {
V_17 = V_36 -> V_17 ;
* V_32 = V_11 - V_36 -> V_11 ;
break;
}
V_36 = V_36 -> V_39 ;
}
}
else if ( V_11 < F_9 ( V_34 ) + V_3 ) {
V_17 = V_27 ;
* V_32 = V_11 - V_40 ;
}
return V_17 ;
}
static int T_1 F_16 ( char * line , int * V_41 )
{
char * V_42 ;
V_33 = F_17 ( line , & V_42 ) ;
return 0 ;
}
unsigned long F_18 ( char * V_43 , unsigned long * V_44 )
{
struct V_35 * V_36 = V_37 ;
while ( V_36 != NULL ) {
if ( ! strcmp ( V_36 -> V_43 , V_43 ) ) {
* V_44 = V_36 -> V_38 ;
return V_36 -> V_10 ;
}
V_36 = V_36 -> V_39 ;
}
return 0 ;
}
static int F_19 ( void )
{
struct V_35 * V_36 = V_37 ;
unsigned long V_45 = V_46 + V_31 ;
int V_18 ;
while ( V_36 != NULL ) {
V_18 = F_4 ( ( void * ) V_45 , V_36 -> V_17 , 0 ,
V_36 -> V_38 , 1 , 1 , 0 ) ;
if ( V_18 )
F_5 ( V_20 L_8
L_9 , V_36 -> V_43 , - V_18 ) ;
else {
V_36 -> V_10 = V_45 ;
V_36 -> V_11 = F_9 ( V_36 -> V_10 ) ;
}
V_45 += V_36 -> V_38 + V_31 ;
V_36 = V_36 -> V_39 ;
}
return 0 ;
}
