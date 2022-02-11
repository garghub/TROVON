static int F_1 ( void )
{
F_2 ( F_3 ( 21 ) , 1 ) ;
return 0 ;
}
static void F_4 ( void )
{
F_5 ( F_3 ( 21 ) , V_1 ) ;
}
static void F_6 ( struct V_2 * V_3 , int V_4 )
{
unsigned int V_5 ;
V_4 = V_3 -> V_6 [ V_4 ] & 3 ;
F_7 ( L_1 ,
V_4 , V_3 , V_3 -> V_6 ) ;
V_5 = F_8 ( V_7 ) ;
V_5 &= V_8 ;
V_5 |= V_4 ;
V_5 |= V_9 ;
F_7 ( L_2 , V_5 ) ;
F_9 ( V_5 , V_7 ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( & V_10 ) ;
F_12 ( V_11 , F_13 ( V_11 ) ) ;
F_14 ( V_12 , F_13 ( V_12 ) ) ;
F_15 ( V_13 , V_14 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( 12000000 ) ;
F_18 () ;
}
static void T_1 F_19 ( void )
{
F_20 ( & V_15 ) ;
F_21 ( & V_16 ) ;
F_22 ( & V_17 ) ;
F_23 ( & V_18 ) ;
F_24 ( V_19 , F_13 ( V_19 ) ) ;
F_25 ( 0 , V_20 ,
F_13 ( V_20 ) ) ;
F_26 () ;
F_27 () ;
F_28 ( NULL , true , & V_21 ) ;
F_29 ( F_30 ( F_3 ( 21 ) , L_3 ) ) ;
F_31 ( & V_22 ) ;
}
