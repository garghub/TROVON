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
static void T_1 F_4 ( struct V_6 * V_7 , char * * V_8 ,
struct V_9 * V_10 )
{
V_10 -> V_11 = 1 ;
V_10 -> V_12 [ 0 ] . V_13 = V_14 ;
V_10 -> V_12 [ 0 ] . V_15 = 448 * V_16 ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_17 ) ;
F_7 () ;
V_18 . V_19 . V_20 = & V_21 ;
V_22 . V_19 . V_20 = & V_23 ;
F_8 ( V_24 , F_9 ( V_24 ) ) ;
F_1 () ;
F_3 () ;
}
