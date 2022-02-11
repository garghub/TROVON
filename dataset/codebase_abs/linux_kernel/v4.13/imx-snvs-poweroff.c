static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 | 0x60 , V_2 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
V_2 = F_5 ( V_4 -> V_5 . V_6 , 0 ) ;
if ( ! V_2 ) {
F_6 ( & V_4 -> V_5 , L_1 ) ;
return - V_7 ;
}
V_8 = F_1 ;
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_9 ) ;
}
