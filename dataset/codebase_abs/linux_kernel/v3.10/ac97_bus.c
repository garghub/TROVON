static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
int V_6 = 0 ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_8 )
V_6 = V_2 -> V_7 -> V_8 ( V_2 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_9 )
V_6 = V_2 -> V_7 -> V_9 ( V_2 ) ;
return V_6 ;
}
static int T_2 F_4 ( void )
{
return F_5 ( & V_10 ) ;
}
static void T_3 F_6 ( void )
{
F_7 ( & V_10 ) ;
}
