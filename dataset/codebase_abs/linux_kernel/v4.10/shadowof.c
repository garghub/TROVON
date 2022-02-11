static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_6 = V_1 ;
if ( V_2 < V_6 -> V_7 ) {
V_3 = F_2 ( T_1 , V_3 , V_6 -> V_7 - V_2 ) ;
F_3 ( V_5 -> V_1 + V_2 , V_6 -> V_1 + V_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static T_1
F_4 ( void * V_1 )
{
struct V_6 * V_6 = V_1 ;
return V_6 -> V_7 ;
}
static void *
F_5 ( struct V_4 * V_5 , const char * V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 . V_10 ;
struct V_12 * V_13 = V_10 -> V_14 -> V_15 ( V_10 ) -> V_13 ;
struct V_16 * V_17 ;
struct V_6 * V_6 ;
if ( ! ( V_17 = F_6 ( V_13 ) ) )
return F_7 ( - V_18 ) ;
if ( ! ( V_6 = F_8 ( sizeof( * V_6 ) , V_19 ) ) )
return F_7 ( - V_20 ) ;
if ( ( V_6 -> V_1 = F_9 ( V_17 , L_1 , & V_6 -> V_7 ) ) )
return V_6 ;
F_10 ( V_6 ) ;
return F_7 ( - V_21 ) ;
}
