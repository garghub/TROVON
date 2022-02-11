static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 )
V_3 = F_4 ( V_2 , V_7 ,
V_8 ) ;
else
V_3 = F_4 ( V_2 , V_7 , 0 ) ;
return V_3 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_9 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_9 ) ;
}
