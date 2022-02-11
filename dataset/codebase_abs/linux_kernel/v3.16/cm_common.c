void T_1 F_1 ( void T_2 * V_1 , void T_2 * V_2 )
{
V_3 = V_1 ;
V_4 = V_2 ;
}
int F_2 ( void T_2 * V_5 , T_3 * V_6 ,
T_4 * V_7 )
{
if ( ! V_8 -> V_9 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
return V_8 -> V_9 ( V_5 , V_6 ,
V_7 ) ;
}
int F_4 ( T_3 V_12 , T_4 V_13 , T_4 V_14 )
{
if ( ! V_8 -> V_15 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
return V_8 -> V_15 ( V_12 , V_13 , V_14 ) ;
}
int F_5 ( struct V_8 * V_16 )
{
if ( ! V_16 )
return - V_11 ;
if ( V_8 != & V_17 )
return - V_18 ;
V_8 = V_16 ;
return 0 ;
}
int F_6 ( struct V_8 * V_16 )
{
if ( ! V_16 || V_8 != V_16 )
return - V_11 ;
V_8 = & V_17 ;
return 0 ;
}
