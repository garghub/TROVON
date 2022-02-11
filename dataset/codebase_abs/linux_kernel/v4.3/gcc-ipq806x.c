static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_6 ;
int V_7 ;
V_3 = F_2 ( V_5 , L_1 , NULL , V_8 , 25000000 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
V_3 = F_2 ( V_5 , L_2 , NULL , V_8 , 25000000 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
V_7 = F_5 ( V_2 , & V_9 ) ;
if ( V_7 )
return V_7 ;
V_6 = F_6 ( V_5 , NULL ) ;
if ( ! V_6 )
return - V_10 ;
F_7 ( V_6 , 0x31a4 , 0xffffffc0 , 0x40000400 ) ;
F_8 ( V_6 , 0x31b0 , 0x3080 ) ;
F_8 ( V_6 , 0x3cb8 , 8 ) ;
F_8 ( V_6 , 0x3cd8 , 8 ) ;
F_8 ( V_6 , 0x3cf8 , 8 ) ;
F_8 ( V_6 , 0x3d18 , 8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_11 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_11 ) ;
}
