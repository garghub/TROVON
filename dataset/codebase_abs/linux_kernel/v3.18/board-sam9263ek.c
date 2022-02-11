static void T_1 F_1 ( void )
{
F_2 ( 16367660 ) ;
}
static int F_3 ( void )
{
return ! F_4 ( V_1 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_1 , 1 ) ;
F_7 ( V_2 , 1 ) ;
}
static void T_1 F_5 ( void ) {}
static void T_1 F_8 ( void )
{
V_3 . V_4 = F_9 () ;
if ( V_3 . V_4 )
V_5 . V_6 |= V_7 ;
else
V_5 . V_6 |= V_8 ;
F_10 ( 0 , 3 , & V_5 ) ;
F_11 ( & V_3 ) ;
}
static void F_12 ( struct V_9 * V_10 , int V_11 )
{
F_13 ( V_12 , V_11 ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_13 , 1 ) ;
F_16 ( V_13 , 1 ) ;
F_15 ( V_14 , 1 ) ;
F_16 ( V_14 , 1 ) ;
F_17 ( & V_15 ) ;
}
static void T_1 F_14 ( void ) {}
static void F_18 ( int V_11 )
{
if ( V_11 ) {
F_19 ( V_16 , 1 ) ;
F_19 ( V_17 , 0 ) ;
} else {
F_19 ( V_16 , 0 ) ;
F_19 ( V_17 , 1 ) ;
}
}
static void T_1 F_20 ( void )
{
F_21 () ;
F_22 ( 0 , 0 , 0 ) ;
F_22 ( V_18 , 1 , V_19 | V_20 ) ;
F_23 () ;
F_24 ( & V_21 ) ;
F_25 ( & V_22 ) ;
F_19 ( V_23 , 1 ) ;
F_26 ( V_24 , F_27 ( V_24 ) ) ;
F_5 () ;
F_28 ( 1 , & V_25 ) ;
F_29 ( & V_26 ) ;
F_8 () ;
F_30 ( V_27 , F_27 ( V_27 ) ) ;
F_31 ( & V_28 ) ;
F_14 () ;
F_32 ( & V_29 ) ;
F_33 ( V_30 , F_27 ( V_30 ) ) ;
F_34 ( V_31 , F_27 ( V_31 ) ) ;
#if F_35 ( V_32 )
F_36 ( 1 << V_33 ) ;
#endif
F_37 ( & V_34 ) ;
F_38 ( V_35 , F_27 ( V_35 ) ) ;
}
