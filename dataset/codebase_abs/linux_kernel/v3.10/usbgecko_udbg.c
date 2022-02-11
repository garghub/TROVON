static T_1 F_1 ( T_1 V_1 )
{
T_1 T_2 * V_2 = V_3 + V_4 ;
T_1 T_2 * V_5 = V_3 + V_6 ;
T_1 T_2 * V_7 = V_3 + V_8 ;
T_1 V_9 , V_10 , V_11 ;
V_9 = V_12 | V_13 ;
F_2 ( V_2 , V_9 ) ;
V_10 = V_1 ;
F_2 ( V_5 , V_10 ) ;
V_11 = F_3 ( 2 ) | V_14 | V_15 ;
F_2 ( V_7 , V_11 ) ;
while ( F_4 ( V_7 ) & V_15 )
F_5 () ;
F_2 ( V_2 , 0 ) ;
V_10 = F_4 ( V_5 ) ;
return V_10 ;
}
static int F_6 ( void )
{
if ( ! V_3 )
return 0 ;
return F_1 ( 0x90000000 ) == 0x04700000 ;
}
static int F_7 ( void )
{
return F_1 ( 0xc0000000 ) & 0x04000000 ;
}
static void F_8 ( char V_16 )
{
F_1 ( 0xb0000000 | ( V_16 << 20 ) ) ;
}
static void F_9 ( char V_16 )
{
int V_17 = V_18 ;
if ( ! V_3 )
return;
if ( V_16 == '\n' )
F_9 ( '\r' ) ;
while ( ! F_7 () && V_17 -- )
F_5 () ;
if ( V_17 >= 0 )
F_8 ( V_16 ) ;
}
static int F_10 ( void )
{
return F_1 ( 0xd0000000 ) & 0x04000000 ;
}
static int F_11 ( void )
{
T_1 V_10 = F_1 ( 0xa0000000 ) ;
if ( V_10 & 0x08000000 )
return ( V_10 >> 16 ) & 0xff ;
else
return - 1 ;
}
static int F_12 ( void )
{
int V_17 = V_19 ;
if ( ! V_3 )
return - 1 ;
while ( ! F_10 () && V_17 -- )
F_5 () ;
return F_11 () ;
}
void F_13 ( char V_16 )
{
F_9 ( V_16 ) ;
}
static int F_14 ( void )
{
int V_16 ;
while ( ( V_16 = F_12 () ) == - 1 )
F_5 () ;
return V_16 ;
}
static int F_15 ( void )
{
if ( ! F_10 () )
return - 1 ;
return F_12 () ;
}
static void T_2 * F_16 ( struct V_20 * V_21 )
{
void T_2 * V_22 = NULL ;
T_3 V_23 ;
const unsigned int * V_24 ;
V_24 = F_17 ( V_21 , L_1 , NULL ) ;
if ( V_24 ) {
V_23 = F_18 ( V_21 , V_24 ) ;
if ( V_23 )
V_22 = F_19 ( V_23 , V_24 [ 1 ] ) ;
}
return V_22 ;
}
static void T_2 * F_20 ( void T_2 * V_22 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
V_3 = V_22 + 0x14 * V_25 ;
if ( F_6 () )
break;
}
if ( V_25 == 2 )
V_3 = NULL ;
return V_3 ;
}
void T_4 F_21 ( void )
{
struct V_20 * V_21 ;
void T_2 * V_22 ;
if ( V_3 )
F_22 ( L_2 , V_26 ) ;
V_21 = F_23 ( NULL , NULL , L_3 ) ;
if ( ! V_21 ) {
F_22 ( L_4 , V_26 ) ;
goto V_27;
}
V_22 = F_16 ( V_21 ) ;
if ( ! V_22 ) {
F_22 ( L_5 , V_26 ) ;
goto V_27;
}
if ( ! F_20 ( V_22 ) ) {
F_22 ( L_6 ) ;
F_24 ( V_22 ) ;
} else {
V_28 = F_13 ;
V_29 = F_14 ;
V_30 = F_15 ;
F_22 ( L_7 ) ;
}
V_27:
if ( V_21 )
F_25 ( V_21 ) ;
return;
}
static T_3 T_4 F_26 ( void )
{
#if F_27 ( V_31 )
return 0x0c000000 ;
#elif F_27 ( V_32 )
return 0x0d000000 ;
#else
#error Invalid platform for USB Gecko based early debugging.
#endif
}
void T_4 F_28 ( void )
{
void T_2 * V_33 ;
void T_2 * V_22 ;
V_33 = ( void T_2 * ) F_29 ( V_34 ) ;
V_22 = V_33 + 0x00006800 ;
if ( ! F_20 ( V_22 ) )
return;
V_28 = F_13 ;
V_29 = F_14 ;
V_30 = F_15 ;
F_30 ( 1 , ( unsigned long ) V_33 ,
F_26 () , 128 * 1024 , V_35 ) ;
}
