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
static void T_1 F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * * V_15 , struct V_16 * V_17 )
{
V_17 -> V_18 = 2 ;
V_17 -> V_19 [ 0 ] . V_20 = V_21 ;
V_17 -> V_19 [ 0 ] . V_22 = 448 * V_23 ;
V_17 -> V_19 [ 1 ] . V_20 = V_24 ;
V_17 -> V_19 [ 1 ] . V_22 = V_24 ;
}
static int T_1 F_9 ( void )
{
if ( ! F_10 () )
return 0 ;
return F_11 ( true , true ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( V_25 ) ;
F_14 () ;
V_26 . V_27 . V_28 = & V_29 ;
V_30 . V_27 . V_28 = & V_31 ;
F_15 ( V_32 , F_4 ( V_32 ) ) ;
F_1 () ;
F_5 () ;
}
