static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_1 -> V_7 , struct V_3 , V_8 ) ;
if ( F_3 ( 0 , & V_4 -> V_9 ) ) {
F_4 ( & V_4 -> V_10 , L_1 ) ;
return - V_11 ;
}
V_6 = F_5 ( sizeof( * V_6 ) , V_12 ) ;
if ( V_6 == NULL )
goto V_13;
F_6 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_13:
F_7 ( 0 , & V_4 -> V_9 ) ;
return - V_14 ;
}
static T_1 F_8 ( struct V_2 * V_2 , const char T_2 * V_15 ,
T_3 V_16 , T_4 * V_17 )
{
return F_9 ( V_2 , V_15 , V_16 , V_17 , NULL ) ;
}
static int F_10 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
F_11 ( V_2 , V_6 ) ;
F_7 ( 0 , & V_6 -> V_4 -> V_9 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
