static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_2 ( & V_2 ) ;
F_2 ( & V_3 ) ;
F_3 ( 2 , V_4 ,
F_4 ( V_4 ) ) ;
}
static void F_5 ( void )
{
struct V_5 * V_6 ;
V_6 = V_7 . V_8 . V_9 ;
V_6 -> V_10 = V_11 ;
V_12 . V_13 = V_14 ;
F_2 ( & V_15 ) ;
F_2 ( & V_16 ) ;
F_2 ( & V_7 ) ;
}
static void T_1 F_6 ( struct V_17 * V_18 , char * * V_19 ,
struct V_20 * V_21 )
{
V_21 -> V_22 = 2 ;
V_21 -> V_23 [ 0 ] . V_24 = V_25 ;
V_21 -> V_23 [ 0 ] . V_26 = 448 * V_27 ;
V_21 -> V_23 [ 1 ] . V_24 = V_28 ;
V_21 -> V_23 [ 1 ] . V_26 = V_28 ;
}
static int T_1 F_7 ( void )
{
if ( ! F_8 () )
return 0 ;
return F_9 ( true , true ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( V_29 ) ;
F_12 () ;
V_30 . V_8 . V_9 = & V_31 ;
V_32 . V_8 . V_9 = & V_33 ;
F_13 ( V_34 , F_4 ( V_34 ) ) ;
F_1 () ;
F_5 () ;
}
