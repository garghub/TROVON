static void T_1 F_1 ( void )
{
struct V_1 * V_2 = NULL ;
F_2 () ;
V_2 = F_3 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
F_4 ( V_3 L_2 ) ;
return;
}
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static void T_1 F_7 ( void )
{
struct V_1 * V_4 ;
F_4 ( V_5 L_3 ) ;
#ifdef F_8
F_9 () ;
#endif
F_10 () ;
V_4 = F_3 ( NULL , NULL , L_4 ) ;
if ( V_4 ) {
V_6 = F_11 ( V_4 , 0 ) ;
if ( V_6 == NULL )
F_4 ( V_3 L_5 ) ;
F_6 ( V_4 ) ;
}
#if F_12 ( V_7 )
F_13 () ;
#endif
}
static unsigned int F_14 ( void )
{
unsigned int V_8 ;
V_8 = F_15 ( V_6 ) ;
return V_8 & 0xff ;
}
static unsigned int F_16 ( void )
{
unsigned int V_8 ;
V_8 = F_15 ( V_6 ) ;
return ( V_8 >> 8 ) & 0xff ;
}
static unsigned int F_17 ( void )
{
unsigned int V_8 ;
V_8 = F_15 ( V_6 ) ;
return ( V_8 >> 16 ) & 0xff ;
}
static unsigned int F_18 ( void )
{
unsigned int V_8 ;
V_8 = F_15 ( V_6 ) ;
return ( V_8 >> 24 ) & 0xf ;
}
static void F_19 ( struct V_9 * V_10 )
{
T_2 V_11 = F_20 ( V_12 ) ;
F_21 ( V_10 , L_6 ) ;
F_21 ( V_10 , L_7 , F_14 () ) ;
F_21 ( V_10 , L_8 , F_16 () ,
( 'A' + F_17 () - 1 ) ) ;
F_21 ( V_10 , L_9 , F_18 () ) ;
F_21 ( V_10 , L_10 , V_11 ) ;
}
static void F_22 ( struct V_13 * V_14 )
{
unsigned int V_15 ;
if ( ! F_23 ( V_16 ) )
return;
F_4 ( V_5 L_11 ) ;
F_24 ( V_14 , 0xe0 , & V_15 ) ;
F_25 ( V_14 , 0xe0 , ( V_15 & ~ 7 ) | 0x2 ) ;
F_25 ( V_14 , 0xe4 , 1 << 5 ) ;
}
static int T_1 F_26 ( void )
{
unsigned long V_17 = F_27 () ;
if ( F_28 ( V_17 , L_12 ) )
return 1 ;
return 0 ;
}
static long T_1 F_29 ( void )
{
unsigned int V_18 ;
F_30 ( V_19 , 0 ) ;
F_30 ( V_20 , 0 ) ;
V_18 = F_20 ( V_21 ) ;
V_18 |= V_22 ;
F_30 ( V_21 , V_18 ) ;
asm volatile("isync");
return 0 ;
}
static int T_1 F_31 ( void )
{
F_4 ( V_23 L_13 ) ;
F_32 ( NULL , V_24 , NULL ) ;
return 0 ;
}
