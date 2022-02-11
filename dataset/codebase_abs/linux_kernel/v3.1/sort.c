static int F_1 ( void const * V_1 , void const * V_2 )
{
T_1 const * V_3 = V_1 ;
T_1 const * V_4 = V_2 ;
if ( ! V_3 -> V_5 || ! V_4 -> V_5 )
return 0 ;
return V_3 -> V_6 - V_4 -> V_6 ;
}
VOID F_2 ( T_2 V_7 )
{
F_3 ( V_7 , V_8 , V_9 ,
V_10 , L_1 ) ;
F_4 ( V_7 -> V_11 , V_12 , sizeof( T_1 ) ,
F_1 , NULL ) ;
}
static int F_5 ( void const * V_1 , void const * V_2 )
{
T_3 const * V_3 = V_1 ;
T_3 const * V_4 = V_2 ;
if ( ! V_3 -> V_13 || ! V_4 -> V_13 )
return 0 ;
return V_3 -> V_14 - V_4 -> V_14 ;
}
VOID F_6 ( T_2 V_7 )
{
F_3 ( V_7 , V_8 , V_9 ,
V_10 , L_1 ) ;
F_4 ( V_7 -> V_15 , V_16 ,
sizeof( T_3 ) , F_5 , NULL ) ;
}
