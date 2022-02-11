static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_5 ;
int V_6 ;
V_6 = F_2 ( V_4 , L_1 , L_2 , 19200000 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_4 , L_3 , L_4 , 27000000 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_2 , & V_7 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_4 ( V_4 , NULL ) ;
if ( ! V_5 )
return - V_8 ;
F_5 ( V_5 , 0x31a4 , 0xffffffc0 , 0x40000400 ) ;
F_6 ( V_5 , 0x31b0 , 0x3080 ) ;
F_6 ( V_5 , 0x3cb8 , 8 ) ;
F_6 ( V_5 , 0x3cd8 , 8 ) ;
F_6 ( V_5 , 0x3cf8 , 8 ) ;
F_6 ( V_5 , 0x3d18 , 8 ) ;
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_9 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_9 ) ;
}
