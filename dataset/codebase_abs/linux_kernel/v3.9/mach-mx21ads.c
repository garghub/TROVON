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
return F_7 ( F_8 ( F_9 ( 4 , 25 ) ) , V_9 ,
V_11 , L_1 , V_10 ) ;
}
static void F_10 ( struct V_6 * V_7 , void * V_10 )
{
F_11 ( F_8 ( F_9 ( 4 , 25 ) ) , V_10 ) ;
}
static void T_3 F_12 ( void )
{
F_13 () ;
F_14 ( V_12 , F_15 ( V_12 ) ) ;
}
static void T_3 F_16 ( void )
{
F_17 () ;
F_18 ( V_13 , F_15 ( V_13 ) ,
L_2 ) ;
F_19 ( & V_14 ) ;
F_20 ( & V_15 ) ;
F_21 ( & V_14 ) ;
F_22 ( & V_16 ) ;
F_23 ( 0 , & V_17 ) ;
F_24 ( & V_18 ) ;
F_25 ( V_19 , F_15 ( V_19 ) ) ;
V_20 [ 1 ] . V_21 =
F_8 ( V_22 ) ;
V_20 [ 1 ] . V_23 =
F_8 ( V_22 ) ;
F_26 ( & V_24 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( 32768 , 26000000 ) ;
}
