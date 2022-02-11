static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
unsigned int V_4 ;
V_4 = F_6 ( V_5 ) ;
V_4 |= V_6 ;
F_7 ( V_4 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
unsigned int V_4 ;
V_4 = F_6 ( V_5 ) ;
V_4 &= ~ V_6 ;
F_7 ( V_4 , V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_7 )
{
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
return 0 ;
}
