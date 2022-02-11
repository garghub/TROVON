static int F_1 ( T_1 V_1 )
{
int V_2 ;
F_2 ( & V_3 -> V_4 , V_5 ) ;
V_2 = F_3 ( ( F_4 ( & V_3 -> V_4 ) & V_5 ) == 0 ,
10000 , 10 ) ? 0 : - V_6 ;
if ( V_2 )
F_5 ( V_7 , L_1 ) ;
return V_2 ;
}
static int F_6 ( T_1 V_1 )
{
if ( V_1 != V_8 )
return 0 ;
return 1 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_3 = F_8 ( V_10 -> V_11 . V_12 , 0 ) ;
if ( ! V_3 )
return - V_13 ;
V_7 = & V_10 -> V_11 ;
F_9 ( & V_14 ) ;
return 0 ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_15 ) ;
}
