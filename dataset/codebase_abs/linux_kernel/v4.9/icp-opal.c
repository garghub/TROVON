static void F_1 ( void )
{
int V_1 = F_2 () ;
F_3 ( V_1 , 0xff ) ;
}
static void F_4 ( void )
{
F_5 ( ( 0x00 << 24 ) | V_2 ) ;
}
static unsigned int F_6 ( void )
{
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
T_1 V_6 ;
V_6 = F_7 ( & V_3 , false ) ;
if ( V_6 < 0 )
return 0 ;
V_3 = F_8 ( V_3 ) ;
V_4 = V_3 & 0x00ffffff ;
if ( V_4 == V_7 )
return 0 ;
V_5 = F_9 ( V_8 , V_4 ) ;
if ( F_10 ( V_5 ) ) {
F_11 ( V_4 ) ;
return V_5 ;
}
F_12 ( V_4 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static void F_13 ( unsigned char V_9 )
{
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
F_16 () ;
}
static void F_17 ( struct V_10 * V_11 )
{
unsigned int V_12 = ( unsigned int ) F_18 ( V_11 ) ;
T_1 V_6 ;
F_16 () ;
V_6 = F_5 ( ( F_19 () << 24 ) | V_12 ) ;
if ( V_6 > 0 )
F_20 () ;
}
static void F_21 ( int V_13 , unsigned long V_14 )
{
int V_1 = F_22 ( V_13 ) ;
F_3 ( V_1 , V_15 ) ;
}
static T_2 F_23 ( int V_5 , void * V_16 )
{
int V_1 = F_2 () ;
F_3 ( V_1 , 0xff ) ;
return F_24 () ;
}
int F_25 ( void )
{
struct V_17 * V_18 ;
V_18 = F_26 ( NULL , NULL , L_1 ) ;
if ( ! V_18 )
return - V_19 ;
V_20 = & V_21 ;
F_27 ( L_2 ) ;
return 0 ;
}
