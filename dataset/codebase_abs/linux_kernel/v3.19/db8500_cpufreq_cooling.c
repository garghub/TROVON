static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_5 ) ;
if ( F_3 ( V_4 ) ) {
int V_6 = F_4 ( V_4 ) ;
if ( V_6 != - V_7 )
F_5 ( & V_2 -> V_8 ,
L_1 ,
V_6 ) ;
return V_6 ;
}
F_6 ( V_2 , V_4 ) ;
F_7 ( & V_2 -> V_8 , L_2 , V_4 -> type ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_9 )
{
return - V_10 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return - V_10 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_11 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_11 ) ;
}
