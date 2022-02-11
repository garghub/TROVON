static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
V_3 = F_2 ( V_5 , L_1 , NULL , V_6 , 25000000 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
V_3 = F_2 ( V_5 , L_2 , NULL , V_6 , 25000000 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
return F_5 ( V_2 , & V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_8 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_8 ) ;
}
