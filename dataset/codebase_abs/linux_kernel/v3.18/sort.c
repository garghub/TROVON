static int F_1 ( void const * V_1 , void const * V_2 )
{
struct V_3 const * V_4 = V_1 ;
struct V_3 const * V_5 = V_2 ;
if ( ! V_4 -> V_6 || ! V_5 -> V_6 )
return 0 ;
return V_4 -> V_7 - V_5 -> V_7 ;
}
VOID F_2 ( struct V_8 * V_9 )
{
F_3 ( V_9 , V_10 , V_11 ,
V_12 , L_1 ) ;
F_4 ( V_9 -> V_13 , V_14 , sizeof( struct V_3 ) ,
F_1 , NULL ) ;
}
static int F_5 ( void const * V_1 , void const * V_2 )
{
struct V_15 const * V_4 = V_1 ;
struct V_15 const * V_5 = V_2 ;
if ( ! V_4 -> V_16 || ! V_5 -> V_16 )
return 0 ;
return V_4 -> V_17 - V_5 -> V_17 ;
}
VOID F_6 ( struct V_8 * V_9 )
{
F_3 ( V_9 , V_10 , V_11 ,
V_12 , L_1 ) ;
F_4 ( V_9 -> V_18 , V_19 ,
sizeof( struct V_15 ) , F_5 , NULL ) ;
}
