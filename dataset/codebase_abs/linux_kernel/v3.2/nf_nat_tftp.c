static unsigned int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
struct V_5 * exp )
{
const struct V_6 * V_7 = exp -> V_8 ;
exp -> V_9 . V_10 . V_11
= V_7 -> V_12 [ V_13 ] . V_14 . V_15 . V_16 . V_10 . V_11 ;
exp -> V_17 = V_18 ;
exp -> V_19 = V_20 ;
if ( F_2 ( exp ) != 0 )
return V_21 ;
return V_22 ;
}
static void T_1 F_3 ( void )
{
F_4 ( V_23 , NULL ) ;
F_5 () ;
}
static int T_2 F_6 ( void )
{
F_7 ( V_23 != NULL ) ;
F_4 ( V_23 , F_1 ) ;
return 0 ;
}
