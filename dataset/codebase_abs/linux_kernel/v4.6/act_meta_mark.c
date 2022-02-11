static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_2 -> V_7 ;
return F_2 ( V_6 , V_3 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_8 , T_2 V_9 )
{
T_1 V_6 = * ( T_1 * ) V_8 ;
V_2 -> V_7 = F_4 ( V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return F_6 ( V_2 -> V_7 , V_5 ) ;
}
static int T_3 F_7 ( void )
{
return F_8 ( & V_10 ) ;
}
static void T_4 F_9 ( void )
{
F_10 ( & V_10 ) ;
}
