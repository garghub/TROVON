static void F_1 ( void )
{
int V_1 = F_2 () ;
F_3 ( V_1 , 0xff ) ;
}
static void F_4 ( void )
{
if ( F_5 ( ( 0x00 << 24 ) | V_2 ) > 0 )
F_6 () ;
}
static unsigned int F_7 ( void )
{
unsigned int V_3 ;
T_1 V_4 ;
T_2 V_5 ;
V_3 = F_8 () ;
if ( V_3 )
return V_3 ;
V_5 = F_9 ( & V_4 , false ) ;
if ( V_5 < 0 )
return 0 ;
return F_10 ( V_4 ) ;
}
static unsigned int F_11 ( void )
{
unsigned int V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
V_6 = F_7 () ;
V_7 = V_6 & 0x00ffffff ;
if ( V_7 == V_9 )
return 0 ;
V_8 = F_12 ( V_10 , V_7 ) ;
if ( F_13 ( V_8 ) ) {
F_14 ( V_7 ) ;
return V_8 ;
}
F_15 ( V_7 ) ;
if ( F_5 ( V_6 ) > 0 )
F_6 () ;
return 0 ;
}
static void F_16 ( unsigned char V_11 )
{
if ( V_11 >= V_12 )
V_11 = V_13 ;
F_17 ( V_11 ) ;
F_18 ( V_11 ) ;
F_19 () ;
}
static void F_20 ( struct V_14 * V_15 )
{
unsigned int V_16 = ( unsigned int ) F_21 ( V_15 ) ;
T_2 V_5 ;
F_19 () ;
V_5 = F_5 ( ( F_22 () << 24 ) | V_16 ) ;
if ( V_5 > 0 )
F_6 () ;
}
static void F_23 ( int V_17 , unsigned long V_18 )
{
int V_1 = F_24 ( V_17 ) ;
F_25 ( V_17 , 1 ) ;
F_3 ( V_1 , V_19 ) ;
}
static T_3 F_26 ( int V_8 , void * V_20 )
{
int V_17 = F_27 () ;
F_25 ( V_17 , 0 ) ;
F_3 ( F_24 ( V_17 ) , 0xff ) ;
return F_28 () ;
}
void F_29 ( void )
{
unsigned int V_6 ;
unsigned int V_7 ;
do {
V_6 = F_7 () ;
V_7 = V_6 & 0x00ffffff ;
if ( V_7 == V_9 )
break;
if ( V_7 == V_2 ) {
int V_17 = F_27 () ;
F_25 ( V_17 , 0 ) ;
F_3 ( F_24 ( V_17 ) , 0xff ) ;
} else {
F_30 ( L_1
L_2 , V_7 ) ;
F_15 ( V_7 ) ;
}
} while ( F_5 ( V_6 ) > 0 );
}
int F_31 ( void )
{
struct V_21 * V_22 ;
V_22 = F_32 ( NULL , NULL , L_3 ) ;
if ( ! V_22 )
return - V_23 ;
V_24 = & V_25 ;
F_33 ( L_4 ) ;
return 0 ;
}
