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
struct V_4 * V_5 = & V_3 -> V_5 ;
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
V_5 -> V_7 . V_8 &= V_9 ;
V_5 -> V_10 . V_8 = 0x01 ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_11 )
{
F_6 ( 2 , L_1 , V_6 ) ;
V_3 -> V_11 = 9600 ;
return ( V_11 == V_3 -> V_11 ) ? 0 : - V_12 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
V_3 -> V_11 = 9600 ;
return 0 ;
}
