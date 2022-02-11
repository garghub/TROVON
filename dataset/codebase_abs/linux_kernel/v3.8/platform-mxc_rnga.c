static struct V_1 * T_1 F_1 (
const struct V_2 * V_3 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 ,
. V_8 = V_3 -> V_7 + V_9 - 1 ,
. V_10 = V_11 ,
} ,
} ;
return F_2 ( L_1 , - 1 ,
V_5 , F_3 ( V_5 ) , NULL , 0 ) ;
}
static int T_1 F_4 ( void )
{
struct V_1 * V_12 ;
#if F_5 ( V_13 )
if ( F_6 () )
V_12 = F_1 ( & V_14 ) ;
else
#endif
V_12 = F_7 ( - V_15 ) ;
if ( F_8 ( V_12 ) )
return F_9 ( V_12 ) ;
return 0 ;
}
