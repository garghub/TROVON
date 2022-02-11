static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_1 -> V_8 , struct V_3 , V_9 ) ;
V_6 = F_3 ( sizeof( * V_6 ) , V_10 ) ;
if ( V_6 == NULL )
return - V_11 ;
V_7 = F_4 ( & V_6 -> V_12 ) ;
if ( V_7 ) {
F_5 ( V_6 ) ;
return - V_11 ;
}
F_6 ( V_2 , V_4 , & V_6 -> V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = F_2 ( V_14 , struct V_5 , V_6 ) ;
F_8 ( V_2 , V_14 ) ;
F_9 ( V_14 -> V_4 , & V_6 -> V_12 ) ;
F_5 ( V_6 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_2 * V_2 , const char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = F_2 ( V_14 , struct V_5 , V_6 ) ;
return F_11 ( V_2 , V_16 , V_17 , V_18 , & V_6 -> V_12 ) ;
}
