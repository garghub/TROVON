static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ( V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ) == NULL )
return - V_8 ;
V_4 = V_1 -> V_9 ;
V_6 -> V_10 = snprintf ( V_6 -> V_11 , V_12 ,
L_1 ,
V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ) ;
V_2 -> V_16 = V_6 ;
return 0 ;
}
static T_1 F_3 ( struct V_2 * V_2 , char T_2 * V_17 ,
T_3 V_18 , T_4 * V_19 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
return F_4 ( V_17 , V_18 , V_19 , V_6 -> V_11 , V_6 -> V_10 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
V_2 -> V_16 = NULL ;
F_6 ( V_6 ) ;
return 0 ;
}
