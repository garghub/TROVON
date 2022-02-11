static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_2 ( & V_2 ) ;
F_2 ( & V_3 ) ;
}
static void F_3 ( void )
{
F_2 ( & V_4 ) ;
F_2 ( & V_5 ) ;
}
static void T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * * V_10 , struct V_11 * V_12 )
{
V_12 -> V_13 = 1 ;
V_12 -> V_14 [ 0 ] . V_15 = V_16 ;
V_12 -> V_14 [ 0 ] . V_17 = 448 * V_18 ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_19 ) ;
F_7 () ;
V_20 . V_21 . V_22 = & V_23 ;
V_24 . V_21 . V_22 = & V_25 ;
F_8 ( V_26 , F_9 ( V_26 ) ) ;
F_1 () ;
F_3 () ;
}
