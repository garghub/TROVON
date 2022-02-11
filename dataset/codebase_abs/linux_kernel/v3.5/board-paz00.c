static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_2 ( & V_2 ) ;
F_2 ( & V_3 ) ;
}
static void F_3 ( void )
{
V_4 . V_5 = V_6 ;
F_2 ( & V_7 ) ;
F_2 ( & V_8 ) ;
}
static void T_1 F_4 ( struct V_9 * V_10 , char * * V_11 ,
struct V_12 * V_13 )
{
V_13 -> V_14 = 1 ;
V_13 -> V_15 [ 0 ] . V_16 = V_17 ;
V_13 -> V_15 [ 0 ] . V_18 = 448 * V_19 ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_20 ) ;
F_7 () ;
V_21 . V_22 . V_23 = & V_24 ;
V_25 . V_22 . V_23 = & V_26 ;
F_8 ( V_27 , F_9 ( V_27 ) ) ;
F_1 () ;
F_3 () ;
}
