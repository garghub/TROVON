static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_2 -> V_5 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_6 ,
struct V_3 * V_4 )
{
T_1 V_7 = V_2 -> V_5 ;
return F_4 ( V_7 , V_6 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_8 , T_2 V_9 )
{
T_1 V_7 = * ( T_1 * ) V_8 ;
V_2 -> V_5 = F_6 ( V_7 ) ;
return 0 ;
}
static int T_3 F_7 ( void )
{
return F_8 ( & V_10 ) ;
}
static void T_4 F_9 ( void )
{
F_10 ( & V_10 ) ;
}
