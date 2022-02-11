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
struct V_9 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_11 = V_6 -> V_7 ;
return F_10 ( V_6 -> V_7 - ( V_6 -> V_7 >> V_12 ) , 2U ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
const struct V_9 * V_10 = F_9 ( V_2 ) ;
return F_10 ( F_2 ( V_2 ) -> V_7 , V_10 -> V_11 ) ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_13 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_13 ) ;
}
