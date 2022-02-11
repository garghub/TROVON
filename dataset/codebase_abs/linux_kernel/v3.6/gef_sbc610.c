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
#ifdef F_8
struct V_1 * V_5 ;
F_9 (np, L_3 , L_4 ) {
F_10 ( V_5 , 1 ) ;
}
#endif
F_4 ( V_6 L_5 ) ;
#ifdef F_11
F_12 () ;
#endif
V_4 = F_3 ( NULL , NULL , L_6 ) ;
if ( V_4 ) {
V_7 = F_13 ( V_4 , 0 ) ;
if ( V_7 == NULL )
F_4 ( V_3 L_7 ) ;
F_6 ( V_4 ) ;
}
#if F_14 ( V_8 )
F_15 () ;
#endif
}
static unsigned int F_16 ( void )
{
unsigned int V_9 ;
V_9 = F_17 ( V_7 ) ;
return ( V_9 >> 8 ) & 0xff ;
}
static unsigned int F_18 ( void )
{
unsigned int V_9 ;
V_9 = F_17 ( V_7 ) ;
return ( V_9 >> 16 ) & 0xff ;
}
static unsigned int F_19 ( void )
{
unsigned int V_9 ;
V_9 = F_17 ( V_7 ) ;
return ( V_9 >> 24 ) & 0xf ;
}
static void F_20 ( struct V_10 * V_11 )
{
T_2 V_12 = F_21 ( V_13 ) ;
F_22 ( V_11 , L_8 ) ;
F_22 ( V_11 , L_9 , F_16 () ,
( 'A' + F_18 () - 1 ) ) ;
F_22 ( V_11 , L_10 , F_19 () ) ;
F_22 ( V_11 , L_11 , V_12 ) ;
}
static void T_3 F_23 ( struct V_14 * V_15 )
{
unsigned int V_16 ;
if ( ! F_24 ( V_17 ) )
return;
F_4 ( V_6 L_12 ) ;
F_25 ( V_15 , 0xe0 , & V_16 ) ;
F_26 ( V_15 , 0xe0 , ( V_16 & ~ 7 ) | 0x5 ) ;
F_26 ( V_15 , 0xe4 , 1 << 5 ) ;
}
static int T_1 F_27 ( void )
{
unsigned long V_18 = F_28 () ;
if ( F_29 ( V_18 , L_13 ) )
return 1 ;
return 0 ;
}
static long T_1 F_30 ( void )
{
unsigned int V_19 ;
F_31 ( V_20 , 0 ) ;
F_31 ( V_21 , 0 ) ;
V_19 = F_21 ( V_22 ) ;
V_19 |= V_23 ;
F_31 ( V_22 , V_19 ) ;
asm volatile("isync");
return 0 ;
}
static int T_1 F_32 ( void )
{
F_4 ( V_24 L_14 ) ;
F_33 ( NULL , V_25 , NULL ) ;
return 0 ;
}
