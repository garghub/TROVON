static int F_1 ( void )
{
volatile unsigned int V_1 , V_2 ;
F_2 () ;
V_2 = F_3 ( 0x80 ) ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0x90 ;
F_4 ( 15 ) ;
V_1 = * ( volatile unsigned char * ) V_3 ;
V_2 = F_3 ( 0x80 ) ;
if ( V_1 == 0xB0 )
V_2 = * ( volatile unsigned char * ) ( V_3 + 2 ) ;
else
V_2 = * ( volatile unsigned char * ) ( V_3 + 1 ) ;
V_2 += ( V_1 << 8 ) ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0xFF ;
if ( V_2 == V_4 )
V_5 = V_6 ;
return V_2 ;
}
static long F_5 ( struct V_7 * V_8 , unsigned int V_9 , unsigned long V_10 )
{
F_6 ( & V_11 ) ;
switch ( V_9 ) {
case V_12 :
V_13 = 0 ;
V_14 = 0 ;
break;
case V_15 :
V_14 = 1 ;
break;
case V_16 :
V_13 = 1 ;
break;
default:
V_13 = 0 ;
V_14 = 0 ;
F_7 ( & V_11 ) ;
return - V_17 ;
}
F_7 ( & V_11 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_7 * V_7 , char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
T_1 V_21 ;
if ( V_22 )
F_9 ( V_23 L_1
L_2 , * V_20 , V_18 , V_19 ) ;
if ( F_10 ( & V_24 ) )
return - V_25 ;
V_21 = F_11 ( V_18 , V_19 , V_20 , ( void * ) V_3 , V_5 ) ;
F_7 ( & V_24 ) ;
return V_21 ;
}
static T_1 F_12 ( struct V_7 * V_7 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
unsigned long V_26 = * V_20 ;
unsigned int V_27 = V_19 ;
int V_28 ;
int V_29 , V_30 , V_31 ;
int V_32 , V_33 ;
if ( V_22 )
F_9 ( L_3 ,
V_26 , V_18 , V_27 ) ;
if ( ! V_14 )
return - V_17 ;
if ( V_26 < 64 * 1024 && ( ! V_13 ) )
return - V_17 ;
if ( V_26 >= V_5 )
return V_27 ? - V_34 : 0 ;
if ( V_27 > V_5 - V_26 )
V_27 = V_5 - V_26 ;
if ( ! F_13 ( V_35 , V_18 , V_27 ) )
return - V_36 ;
if ( F_10 ( & V_24 ) )
return - V_25 ;
V_28 = 0 ;
V_29 = ( int ) V_26 >> 16 ;
V_30 = ( ( int ) ( V_26 + V_27 ) >> 16 ) - V_29 + 1 ;
if ( ( ( int ) ( V_26 + V_27 ) & 0xFFFF ) == 0 )
V_30 -= 1 ;
if ( V_22 )
F_9 ( V_23 L_4
L_5 , V_30 , V_29 ) ;
for (; V_30 ; V_30 -- , V_29 ++ ) {
if ( V_22 )
F_9 ( V_23 L_6 , V_29 ) ;
V_32 = 0 ;
V_33 = 0 ;
V_37:
do {
V_31 = F_14 ( V_29 ) ;
V_32 ++ ;
} while ( V_31 && V_32 < 10 );
if ( V_31 ) {
F_9 ( V_38 L_7 , V_31 ) ;
break;
}
if ( V_22 )
F_9 ( V_23 L_8
L_9 , V_26 , V_18 ,
V_27 - V_28 ) ;
V_31 = F_15 ( V_26 , V_18 , V_27 - V_28 ) ;
V_33 ++ ;
if ( ! V_31 ) {
if ( V_33 < 10 )
goto V_37;
else
V_31 = - 1 ;
}
if ( V_31 < 0 ) {
F_9 ( V_38 L_10 , V_31 ) ;
break;
}
V_26 += V_31 ;
V_18 += V_31 ;
V_28 += V_31 ;
* V_20 += V_31 ;
if ( V_22 )
F_9 ( V_23 L_11 , V_28 ) ;
}
F_7 ( & V_24 ) ;
return V_28 ;
}
static T_4 F_16 ( struct V_7 * V_7 , T_4 V_39 , int V_40 )
{
T_4 V_21 ;
F_6 ( & V_11 ) ;
if ( V_22 )
F_9 ( V_23 L_12 ,
( unsigned int ) V_39 , V_40 ) ;
switch ( V_40 ) {
case 0 :
if ( V_39 < 0 ) {
V_21 = - V_17 ;
break;
}
if ( ( unsigned int ) V_39 > V_5 ) {
V_21 = - V_17 ;
break;
}
V_7 -> V_41 = ( unsigned int ) V_39 ;
V_21 = V_7 -> V_41 ;
break;
case 1 :
if ( ( V_7 -> V_41 + V_39 ) > V_5 ) {
V_21 = - V_17 ;
break;
}
if ( ( V_7 -> V_41 + V_39 ) < 0 ) {
V_21 = - V_17 ;
break;
}
V_7 -> V_41 += V_39 ;
V_21 = V_7 -> V_41 ;
break;
default:
V_21 = - V_17 ;
}
F_7 ( & V_11 ) ;
return V_21 ;
}
static int F_14 ( int V_29 )
{
volatile unsigned int V_1 ;
volatile unsigned char * V_42 ;
unsigned long V_43 ;
int V_30 , V_44 ;
* V_45 = 0 ;
V_1 = * ( volatile unsigned char * ) ( V_3 + 0x8000 ) ;
F_2 () ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0x50 ;
V_42 = ( unsigned char * ) ( ( unsigned int ) ( V_3 + 0x8000 + ( V_29 << 16 ) ) ) ;
V_1 = * V_42 ;
F_2 () ;
* ( volatile unsigned char * ) V_42 = 0x20 ;
* ( volatile unsigned char * ) V_42 = 0xD0 ;
F_17 ( 10 ) ;
V_43 = V_46 + 10 * V_47 ;
V_1 = 0 ;
while ( ! ( V_1 & 0x80 ) && F_18 ( V_46 , V_43 ) ) {
F_17 ( 10 ) ;
V_1 = * ( volatile unsigned char * ) ( V_42 ) ;
}
F_2 () ;
* ( volatile unsigned char * ) V_42 = 0xFF ;
if ( V_1 & 0x20 ) {
F_9 ( V_38 L_13 , V_42 ) ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0x50 ;
return - 2 ;
}
F_17 ( 10 ) ;
V_42 = ( unsigned char * ) ( ( unsigned int ) ( V_3 + ( V_29 << 16 ) ) ) ;
for ( V_30 = 0 ; V_30 < 16 * 1024 ; V_30 ++ , V_42 += 4 ) {
if ( ( V_44 = * ( volatile unsigned int * ) V_42 ) != 0xFFFFFFFF ) {
F_9 ( V_38 L_14 ,
V_42 , V_44 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_15 ( unsigned long V_26 , const char T_2 * V_18 , int V_27 )
{
volatile unsigned int V_1 ;
volatile unsigned int V_2 ;
unsigned char * V_42 ;
unsigned int V_48 ;
unsigned int V_39 ;
unsigned long V_43 ;
unsigned long V_49 ;
V_42 = ( unsigned char * ) ( ( unsigned int ) ( V_3 + V_26 ) ) ;
V_39 = V_26 & 0xFFFF ;
if ( V_39 + V_27 > 0x10000 )
V_27 = 0x10000 - V_39 ;
V_43 = V_46 + 30 * V_47 ;
for ( V_39 = 0 ; V_39 < V_27 ; V_39 ++ , V_42 ++ ) {
V_48 = ( unsigned int ) V_42 ;
V_48 &= 0xFFFFFFFC ;
if ( F_19 ( V_2 , V_18 + V_39 ) )
return - V_36 ;
V_50:
V_1 = * ( volatile unsigned char * ) ( V_3 + 0x8000 ) ;
F_2 () ;
* V_45 = ( unsigned int ) V_42 & 3 ;
* ( volatile unsigned char * ) ( V_48 ) = 0x40 ;
* ( volatile unsigned char * ) ( V_48 ) = V_2 ;
* ( volatile unsigned char * ) ( V_3 + 0x10000 ) = 0x70 ;
V_1 = 0 ;
V_49 = V_46 + 1 * V_47 ;
while ( ! ( V_1 & 0x80 ) && F_18 ( V_46 , V_49 ) )
V_1 = * ( volatile unsigned char * ) ( V_3 + 0x8000 ) ;
if ( F_20 ( V_46 , V_49 ) ) {
F_2 () ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0x50 ;
goto V_50;
}
F_2 () ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0xFF ;
if ( V_1 & 0x10 ) {
F_2 () ;
* ( volatile unsigned char * ) ( V_3 + 0x8000 ) = 0x50 ;
if ( F_18 ( V_46 , V_43 ) ) {
if ( V_22 )
F_9 ( V_23 L_15 ,
V_42 - V_3 ) ;
F_17 ( 10 ) ;
goto V_50;
} else {
F_9 ( V_38 L_16 ,
V_42 - V_3 ) ;
return - 2 ;
}
}
}
F_17 ( 10 ) ;
V_42 = ( unsigned char * ) ( ( unsigned int ) ( V_3 + V_26 ) ) ;
for ( V_39 = 0 ; V_39 < V_27 ; V_39 ++ ) {
char V_51 , V_1 ;
if ( F_19 ( V_51 , V_18 ) )
return - V_36 ;
V_18 ++ ;
if ( ( V_1 = * V_42 ++ ) != V_51 ) {
F_9 ( V_38 L_17 ,
V_42 - V_3 , V_1 , V_51 ) ;
return 0 ;
}
}
return V_27 ;
}
static void F_2 ( void )
{
unsigned long V_52 ;
F_21 ( & V_53 , V_52 ) ;
F_22 ( V_54 , V_54 ) ;
F_23 ( & V_53 , V_52 ) ;
F_4 ( 25 ) ;
}
static int T_5 F_24 ( void )
{
int V_21 = - V_55 ;
if ( F_25 () ) {
int V_56 ;
V_3 = F_26 ( V_57 , V_6 ) ;
if ( ! V_3 )
goto V_58;
V_56 = F_1 () ;
if ( ( V_56 != V_59 ) && ( V_56 != V_4 ) ) {
V_21 = - V_34 ;
F_27 ( ( void * ) V_3 ) ;
F_9 ( L_18 , V_56 ) ;
goto V_58;
}
F_9 ( L_19 ,
V_60 , V_56 , V_5 / ( 1024 * 1024 ) ) ;
V_21 = F_28 ( & V_61 ) ;
if ( V_21 < 0 ) {
F_27 ( ( void * ) V_3 ) ;
}
}
V_58:
return V_21 ;
}
static void T_6 F_29 ( void )
{
F_30 ( & V_61 ) ;
F_27 ( ( void * ) V_3 ) ;
}
