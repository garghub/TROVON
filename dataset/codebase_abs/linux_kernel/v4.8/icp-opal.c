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
return V_7 ;
V_3 = F_8 ( V_3 ) ;
V_4 = V_3 & 0x00ffffff ;
if ( V_4 == V_8 )
return V_7 ;
V_5 = F_9 ( V_9 , V_4 ) ;
if ( F_10 ( V_5 != V_7 ) ) {
F_11 ( V_4 ) ;
return V_5 ;
}
F_12 ( V_4 ) ;
F_5 ( V_3 ) ;
return V_7 ;
}
static void F_13 ( unsigned char V_10 )
{
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
F_16 () ;
}
static void F_17 ( struct V_11 * V_12 )
{
unsigned int V_13 = ( unsigned int ) F_18 ( V_12 ) ;
T_1 V_6 ;
F_16 () ;
V_6 = F_5 ( ( F_19 () << 24 ) | V_13 ) ;
if ( V_6 > 0 )
F_20 () ;
}
static void F_21 ( int V_14 , unsigned long V_15 )
{
int V_1 = F_22 ( V_14 ) ;
F_3 ( V_1 , V_16 ) ;
}
static T_2 F_23 ( int V_5 , void * V_17 )
{
int V_1 = F_2 () ;
F_3 ( V_1 , 0xff ) ;
return F_24 () ;
}
int F_25 ( void )
{
struct V_18 * V_19 ;
V_19 = F_26 ( NULL , NULL , L_1 ) ;
if ( ! V_19 )
return - V_20 ;
V_21 = & V_22 ;
F_27 ( L_2 ) ;
return 0 ;
}
