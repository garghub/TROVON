int T_1 F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 , * V_6 ;
unsigned long V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 , V_12 , V_13 , V_14 ;
int V_15 ;
V_8 = V_1 >> V_16 ;
V_7 = V_8 * sizeof( struct V_4 ) ;
V_12 = V_2 >> V_16 ;
V_11 = V_12 * sizeof( struct V_4 ) ;
V_10 = V_3 >> V_16 ;
V_9 = V_10 * sizeof( struct V_4 ) ;
V_14 = V_8 + V_12 + V_10 ;
V_13 = V_7 + V_11 + V_9 ;
V_6 = F_2 ( V_13 ) ;
if ( V_6 == NULL )
return - V_17 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
V_5 = & V_6 [ V_15 ] ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_18 ) ;
}
V_19 = V_14 ;
return 0 ;
}
void F_5 ( unsigned long V_20 , unsigned long V_21 , unsigned long V_22 ,
int V_23 , int V_24 , int V_25 )
{
T_2 V_26 ;
int V_27 , V_28 ;
V_27 = F_6 ( V_21 , & V_26 ) ;
V_28 = F_7 ( ( void * ) V_20 , V_27 , V_26 , V_22 , V_23 , V_24 , V_25 ) ;
if ( V_28 ) {
if ( V_28 == - V_17 )
F_8 ( V_29 L_1
L_2
L_3 ) ;
F_9 ( L_4
L_5 , V_20 , V_27 , V_26 , V_22 , V_23 , V_24 , V_25 , V_28 ) ;
}
}
void T_1 F_10 ( unsigned long V_30 , unsigned long V_31 ,
unsigned long V_22 , unsigned long long V_3 )
{
unsigned long V_32 = V_31 - V_30 ;
int V_33 = F_11 ( F_12 ( V_31 ) ) ;
int V_34 = ( V_22 - V_32 ) >> V_16 ;
int V_28 , V_26 , V_35 ;
V_36 = F_13 ( V_22 + V_3 ) ;
V_26 = V_37 - V_38 ;
V_28 = F_7 ( ( void * ) V_37 , V_36 , V_26 ,
V_22 - V_26 , 1 , 1 , 1 ) ;
if ( V_28 < 0 ) {
printf ( L_6
L_7 , V_22 - V_26 ,
( void * ) V_37 , V_28 ) ;
exit ( 1 ) ;
}
F_14 ( V_36 , F_12 ( & V_39 ) ) ;
F_15 ( V_36 , & V_39 , V_40 ) ;
V_35 = F_16 ( V_33 , V_33 + V_34 ) ;
F_17 ( F_12 ( V_31 ) + V_35 ,
V_22 - V_35 - V_32 ) ;
}
int F_6 ( unsigned long V_21 , unsigned long long * V_41 )
{
int V_27 = - 1 ;
if ( V_21 < V_42 ) {
V_27 = V_36 ;
* V_41 = V_21 ;
}
else if ( V_21 < F_12 ( V_43 ) ) {
struct V_44 * V_45 = V_46 ;
while ( V_45 != NULL ) {
if ( ( V_21 >= V_45 -> V_21 ) &&
( V_21 < V_45 -> V_21 + V_45 -> V_47 ) ) {
V_27 = V_45 -> V_27 ;
* V_41 = V_21 - V_45 -> V_21 ;
break;
}
V_45 = V_45 -> V_48 ;
}
}
else if ( V_21 < F_12 ( V_43 ) + V_3 ) {
V_27 = V_36 ;
* V_41 = V_21 - V_49 ;
}
return V_27 ;
}
static int T_1 F_18 ( char * line , int * V_50 )
{
char * V_51 ;
V_42 = F_19 ( line , & V_51 ) ;
return 0 ;
}
unsigned long F_20 ( char * V_52 , unsigned long * V_53 )
{
struct V_44 * V_45 = V_46 ;
while ( V_45 != NULL ) {
if ( ! strcmp ( V_45 -> V_52 , V_52 ) ) {
* V_53 = V_45 -> V_47 ;
return V_45 -> V_20 ;
}
V_45 = V_45 -> V_48 ;
}
return 0 ;
}
static int F_21 ( void )
{
struct V_44 * V_45 = V_46 ;
unsigned long V_54 = V_55 + V_40 ;
int V_28 ;
while ( V_45 != NULL ) {
V_28 = F_7 ( ( void * ) V_54 , V_45 -> V_27 , 0 ,
V_45 -> V_47 , 1 , 1 , 0 ) ;
if ( V_28 )
F_8 ( V_29 L_8
L_9 , V_45 -> V_52 , - V_28 ) ;
else {
V_45 -> V_20 = V_54 ;
V_45 -> V_21 = F_12 ( V_45 -> V_20 ) ;
}
V_54 += V_45 -> V_47 + V_40 ;
V_45 = V_45 -> V_48 ;
}
return 0 ;
}
