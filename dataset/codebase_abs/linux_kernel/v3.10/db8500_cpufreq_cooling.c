static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
if ( ! F_2 ( 0 ) )
return - V_7 ;
F_3 ( 0 , & V_6 ) ;
V_4 = F_4 ( & V_6 ) ;
if ( F_5 ( V_4 ) ) {
F_6 ( & V_2 -> V_8 , L_1 ) ;
return F_7 ( V_4 ) ;
}
F_8 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_8 , L_2 , V_4 -> type ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_11 ( V_2 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_9 )
{
return - V_10 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return - V_10 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_11 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_11 ) ;
}
