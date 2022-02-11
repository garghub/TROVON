static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_2 , V_5 ) )
return;
if ( V_7 -> V_8 <= V_7 -> V_9 )
F_4 ( V_7 , V_4 ) ;
else
F_5 ( V_7 , F_6 ( V_7 -> V_8 , V_10 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_8 ( V_7 -> V_8 - ( V_7 -> V_8 >> V_11 ) , 2U ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_12 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_12 ) ;
}
