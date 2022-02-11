static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_6 = V_1 ;
if ( V_2 + V_3 <= V_6 -> V_7 ) {
F_2 ( V_5 -> V_1 + V_2 , V_6 -> V_1 + V_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void *
F_3 ( struct V_4 * V_5 , const char * V_8 )
{
struct V_9 * V_10 = F_4 ( V_5 ) -> V_10 ;
struct V_11 * V_12 ;
struct V_6 * V_6 ;
if ( ! ( V_12 = F_5 ( V_10 ) ) )
return F_6 ( - V_13 ) ;
if ( ! ( V_6 = F_7 ( sizeof( * V_6 ) , V_14 ) ) )
return F_6 ( - V_15 ) ;
if ( ( V_6 -> V_1 = F_8 ( V_12 , L_1 , & V_6 -> V_7 ) ) )
return V_6 ;
F_9 ( V_6 ) ;
return F_6 ( - V_16 ) ;
}
