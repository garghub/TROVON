static void T_1 F_1 ( void )
{
#ifdef F_2
static struct V_1 V_2 = {
. V_3 = ( void V_4 * ) V_5 ,
. V_6 = V_7 ,
. V_8 = V_9 ,
. V_10 = V_11 ,
. V_12 = V_13 | V_14 ,
. V_15 = 2 ,
. V_16 = 24000000 ,
. line = 0 ,
. type = V_17 ,
. V_18 = 16 ,
} ;
F_3 ( & V_2 ) ;
#endif
}
static int F_4 ( struct V_19 * V_20 )
{
if ( F_5 ( & V_21 ) == 1 ) {
F_6 ( 1 << V_22 ) ;
F_7 ( 1 << V_23 ) ;
F_8 ( 1 << V_24 ) ;
F_9 ( ( F_10 ( V_25 ) | ( 0X2 << 24 ) ) ,
V_25 ) ;
}
return 0 ;
}
static void F_11 ( struct V_19 * V_20 )
{
if ( F_12 ( & V_21 ) == 0 )
F_13 ( 1 << V_23 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 ( V_26 , F_17 ( V_26 ) ) ;
F_18 () ;
F_19 () ;
V_27 = V_28 ;
}
static void T_1 F_20 ( void )
{
F_21 () ;
F_22 ( V_29 , F_17 ( V_29 ) ) ;
F_1 () ;
}
