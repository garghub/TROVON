static void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
T_2 V_6 ;
int V_7 ;
V_6 = V_1 & V_8 ;
V_2 = F_2 ( V_1 + V_2 ) - V_6 ;
if ( V_9 &&
V_6 >= V_10 && V_6 < F_3 ( V_11 ) &&
! ( V_6 >= F_4 ( ( T_2 ) V_12 ) &&
V_6 < F_4 ( ( T_2 ) V_12 ) ) ) {
F_5 ( L_1 V_13 L_2 ,
( unsigned long ) V_6 , F_6 ( 0 ) ) ;
return NULL ;
}
if ( V_2 == 0 )
return NULL ;
if ( V_9 ) {
struct V_14 * V_15 ;
V_15 = F_7 ( V_2 , V_16 ) ;
if ( V_15 == NULL )
return NULL ;
V_4 = ( unsigned long ) V_15 -> V_1 ;
} else {
V_4 = ( V_17 -= V_2 ) ;
}
if ( ( V_3 & V_18 ) == 0 )
V_3 |= V_19 ;
if ( V_3 & V_20 )
V_3 |= V_21 ;
V_7 = 0 ;
for ( V_5 = 0 ; V_5 < V_2 && V_7 == 0 ; V_5 += V_22 )
V_7 = F_8 ( V_4 + V_5 , V_6 + V_5 , V_3 ) ;
if ( V_7 ) {
if ( V_9 )
F_9 ( ( void * ) V_4 ) ;
return NULL ;
}
return ( void T_1 * ) ( V_4 + ( ( unsigned long ) V_1 & ~ V_8 ) ) ;
}
void T_1 * F_10 ( T_2 V_1 , unsigned long V_2 )
{
return F_1 ( V_1 , V_2 , V_20 ) ;
}
void F_11 ( void T_1 * V_1 )
{
if ( ( V_23 void * ) V_1 > V_11 &&
( unsigned long ) V_1 < V_17 )
F_9 ( ( void * ) ( V_8 & ( unsigned long ) V_1 ) ) ;
}
int F_8 ( unsigned long V_24 , T_2 V_25 , int V_3 )
{
T_3 * V_26 ;
T_4 * V_27 ;
int V_7 = - V_28 ;
V_26 = F_12 ( F_13 ( V_24 ) , V_24 ) ;
V_27 = F_14 ( V_26 , V_24 ) ;
if ( V_27 != NULL ) {
V_7 = 0 ;
F_15 ( & V_29 , V_24 , V_27 , F_16 ( V_25 >> V_30 ,
F_17 ( V_3 ) ) ) ;
if ( F_18 ( V_9 ) )
F_19 ( V_24 ) ;
}
return V_7 ;
}
void T_5 F_20 ( void )
{
unsigned long V_4 , V_6 , V_31 , V_32 ;
V_4 = V_33 ;
V_6 = V_10 ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 += V_22 ) {
V_32 = V_18 | V_35 |
V_36 | V_37 ;
if ( ( char * ) V_4 < V_38 || ( char * ) V_4 >= V_39 )
V_32 |= V_40 ;
else
V_32 |= V_41 ;
F_8 ( V_4 , V_6 , V_32 ) ;
V_4 += V_22 ;
V_6 += V_22 ;
}
}
static int F_21 ( struct V_42 * V_43 , unsigned long V_1 , T_4 * * V_44 )
{
T_6 * V_45 ;
T_3 * V_46 ;
T_4 * V_47 ;
int V_48 = 0 ;
V_45 = F_22 ( V_43 , V_1 & V_8 ) ;
if ( V_45 ) {
V_46 = F_12 ( V_45 , V_1 & V_8 ) ;
if ( F_23 ( * V_46 ) ) {
V_47 = F_24 ( V_46 , V_1 & V_8 ) ;
if ( V_47 ) {
V_48 = 1 ;
* V_44 = V_47 ;
}
}
}
return V_48 ;
}
unsigned long F_25 ( unsigned long V_1 )
{
unsigned long V_25 ;
T_4 * V_47 ;
struct V_42 * V_43 ;
if ( V_1 < V_49 )
V_43 = V_50 -> V_43 ;
else
V_43 = & V_29 ;
V_25 = 0 ;
if ( F_21 ( V_43 , V_1 , & V_47 ) )
V_25 = ( F_26 ( * V_47 ) & V_8 ) | ( V_1 & ~ V_8 ) ;
return V_25 ;
}
T_7 T_4 * F_27 ( struct V_42 * V_43 ,
unsigned long V_51 )
{
T_4 * V_47 ;
if ( V_9 ) {
V_47 = ( T_4 * ) F_28 ( V_52 | V_53 ) ;
} else {
V_47 = ( T_4 * ) F_29 () ;
if ( V_47 )
F_30 ( V_47 ) ;
}
return V_47 ;
}
void F_31 ( enum V_54 V_55 , T_2 V_56 , T_8 V_3 )
{
unsigned long V_51 = F_32 ( V_55 ) ;
if ( V_55 >= V_57 )
F_33 () ;
F_8 ( V_51 , V_56 , F_34 ( V_3 ) ) ;
}
