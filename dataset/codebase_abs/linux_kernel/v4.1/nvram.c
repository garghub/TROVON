static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
char * V_8 = V_1 ;
if ( V_9 == 0 || V_10 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
if ( ( F_3 ( V_10 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
memcpy ( V_8 , V_15 , V_5 ) ;
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_6 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
unsigned long V_5 ;
int V_6 ;
unsigned long V_7 ;
const char * V_8 = V_1 ;
if ( V_9 == 0 || V_17 == V_11 )
return - V_12 ;
if ( * V_3 >= V_9 )
return 0 ;
V_4 = * V_3 ;
if ( V_4 + V_2 > V_9 )
V_2 = V_9 - V_4 ;
F_2 ( & V_13 , V_7 ) ;
for (; V_2 != 0 ; V_2 -= V_5 ) {
V_5 = V_2 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
memcpy ( V_15 , V_8 , V_5 ) ;
if ( ( F_3 ( V_17 , 3 , 2 , & V_6 , V_4 , F_4 ( V_15 ) ,
V_5 ) != 0 ) || V_5 != V_6 ) {
F_5 ( & V_13 , V_7 ) ;
return - V_16 ;
}
V_8 += V_5 ;
V_4 += V_5 ;
}
F_5 ( & V_13 , V_7 ) ;
* V_3 = V_4 ;
return V_8 - V_1 ;
}
static T_1 F_7 ( void )
{
return V_9 ? V_9 : - V_12 ;
}
int F_8 ( char * V_18 , int V_19 ,
unsigned int V_20 , unsigned int V_21 )
{
int V_22 = F_9 ( & V_23 , V_18 , V_19 ,
V_20 , V_21 ) ;
if ( ! V_22 ) {
V_24 = F_10 () ;
#ifdef F_11
V_25 = F_10 () ;
#endif
}
return V_22 ;
}
int F_12 ( char * V_18 , int V_19 ,
unsigned int * V_20 , unsigned int * V_21 )
{
return F_13 ( & V_23 , V_18 , V_19 ,
V_20 , V_21 ) ;
}
int F_14 ( void )
{
T_3 V_26 ;
int V_27 = V_28 ;
int V_22 ;
if ( V_23 . V_3 == - 1 )
return - 1 ;
V_26 = V_23 . V_3 ;
V_22 = V_29 . V_30 ( ( char * ) & V_27 , sizeof( int ) , & V_26 ) ;
if ( V_22 <= 0 ) {
F_15 ( V_31 L_1 , V_22 ) ;
return V_22 ;
}
V_24 = 0 ;
return 0 ;
}
int F_16 ( void )
{
return ( V_32 . V_3 == V_23 . V_3
&& V_24
&& F_10 () - V_24 <=
V_33 ) ;
}
static int T_4 F_17 ( void )
{
int V_22 ;
F_18 () ;
V_22 = F_19 ( & V_23 ) ;
F_20 ( V_22 == 0 ) ;
return 0 ;
}
int T_4 F_21 ( void )
{
struct V_34 * V_35 ;
const T_5 * V_36 ;
unsigned int V_37 ;
V_35 = F_22 ( NULL , L_2 ) ;
if ( V_35 == NULL )
return - V_12 ;
V_36 = F_23 ( V_35 , L_3 , & V_37 ) ;
if ( V_36 == NULL || V_37 != sizeof( unsigned int ) ) {
F_24 ( V_35 ) ;
return - V_16 ;
}
V_9 = F_25 ( V_36 ) ;
V_10 = F_26 ( L_4 ) ;
V_17 = F_26 ( L_5 ) ;
F_15 ( V_38 L_6 , V_9 ) ;
F_24 ( V_35 ) ;
V_29 . V_39 = F_1 ;
V_29 . V_30 = F_6 ;
V_29 . V_9 = F_7 ;
return 0 ;
}
