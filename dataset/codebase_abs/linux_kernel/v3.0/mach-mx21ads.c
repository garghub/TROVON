static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ V_5 ;
F_3 ( V_3 , V_4 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
return ( F_2 ( V_4 ) & V_8 ) ? 1 : 0 ;
}
static int F_6 ( struct V_6 * V_7 , T_2 V_9 ,
void * V_10 )
{
return F_7 ( F_8 ( 25 ) , V_9 ,
V_11 , L_1 , V_10 ) ;
}
static void F_9 ( struct V_6 * V_7 , void * V_10 )
{
F_10 ( F_8 ( 25 ) , V_10 ) ;
}
static void T_3 F_11 ( void )
{
F_12 () ;
F_13 ( V_12 , F_14 ( V_12 ) ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( V_13 , F_14 ( V_13 ) ,
L_2 ) ;
F_17 ( & V_14 ) ;
F_18 ( & V_15 ) ;
F_19 ( & V_14 ) ;
F_20 ( & V_16 ) ;
F_21 ( 0 , & V_17 ) ;
F_22 ( & V_18 ) ;
F_23 ( V_19 , F_14 ( V_19 ) ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( 32768 , 26000000 ) ;
}
