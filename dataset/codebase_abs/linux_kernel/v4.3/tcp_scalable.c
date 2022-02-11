static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_2 ) )
return;
if ( F_4 ( V_6 ) )
F_5 ( V_6 , V_4 ) ;
else
F_6 ( V_6 , F_7 ( V_6 -> V_7 , V_8 ) ,
1 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_9 ( V_6 -> V_7 - ( V_6 -> V_7 >> V_9 ) , 2U ) ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_10 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_10 ) ;
}
