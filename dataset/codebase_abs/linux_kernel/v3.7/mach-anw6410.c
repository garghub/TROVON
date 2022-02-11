static void T_1 F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 &= ~ V_3 ;
V_1 |= V_4 ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_5 ) ;
V_1 &= ~ V_6 ;
F_3 ( V_1 , V_5 ) ;
}
static void F_4 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
if ( V_9 ) {
V_10 |= ( V_11 << 16 ) ;
F_3 ( V_10 , V_12 ) ;
F_5 ( F_6 ( 1 ) , 1 ) ;
F_5 ( F_6 ( 4 ) , 1 ) ;
} else {
V_10 &= ~ ( V_11 << 16 ) ;
F_3 ( V_10 , V_12 ) ;
F_5 ( F_6 ( 1 ) , 0 ) ;
F_5 ( F_6 ( 4 ) , 0 ) ;
}
}
static void T_1 F_7 ( void )
{
V_10 |= ( V_13 << 16 ) ;
F_3 ( V_10 , V_12 ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( V_14 , F_10 ( V_14 ) ) ;
F_11 ( 12000000 ) ;
F_12 ( V_15 , F_10 ( V_15 ) ) ;
F_1 () ;
}
static void T_1 F_13 ( void )
{
F_14 ( & V_16 ) ;
F_15 ( F_6 ( 1 ) , L_1 ) ;
F_15 ( F_6 ( 4 ) , L_2 ) ;
F_7 () ;
F_16 ( V_17 , F_10 ( V_17 ) ) ;
}
