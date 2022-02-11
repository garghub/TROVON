static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
struct V_5 T_3 * V_6 = NULL ;
struct V_7 * V_8 ;
void T_3 * V_9 = NULL ;
V_8 = F_2 ( V_2 , V_10 , 0 ) ;
if ( ! V_8 )
return - V_11 ;
V_4 = F_3 ( V_8 ) ;
if ( ! V_8 -> V_12 || ! V_4 )
return - V_11 ;
V_3 = V_8 -> V_12 ;
V_6 = F_4 ( V_3 , sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return - V_13 ;
V_9 = F_4 ( V_3 ,
V_6 -> V_14 + V_6 -> V_15 ) ;
F_5 ( V_6 ) ;
if ( ! V_9 )
return - V_13 ;
return F_6 ( V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 () ;
}
static int T_4 F_9 ( void )
{
return F_10 ( & V_16 ) ;
}
