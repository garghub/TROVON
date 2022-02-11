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
int V_5 ;
F_2 ( & V_6 ) ;
F_2 ( & V_7 ) ;
V_5 = F_6 ( V_8 , V_9 ,
L_1 ) ;
if ( V_5 ) {
F_7 ( L_2 , V_5 ) ;
return;
}
F_2 ( & V_10 ) ;
}
static void T_1 F_8 ( struct V_11 * V_12 , char * * V_13 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = 2 ;
V_15 -> V_17 [ 0 ] . V_18 = V_19 ;
V_15 -> V_17 [ 0 ] . V_20 = 448 * V_21 ;
V_15 -> V_17 [ 1 ] . V_18 = V_22 ;
V_15 -> V_17 [ 1 ] . V_20 = V_22 ;
}
static int T_1 F_9 ( void )
{
if ( ! F_10 () )
return 0 ;
return F_11 ( true , true ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( V_23 ) ;
F_14 () ;
V_24 . V_25 . V_26 = & V_27 ;
V_28 . V_25 . V_26 = & V_29 ;
F_15 ( V_30 , F_4 ( V_30 ) ) ;
F_1 () ;
F_5 () ;
}
