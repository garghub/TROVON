static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_2 ) )
return;
if ( V_6 -> V_7 <= V_6 -> V_8 )
F_4 ( V_6 , V_4 ) ;
else
F_5 ( V_6 , F_6 ( V_6 -> V_7 , V_9 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_8 ( V_6 -> V_7 - ( V_6 -> V_7 >> V_10 ) , 2U ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_11 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_11 ) ;
}
