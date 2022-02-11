static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
const char * V_5 = ( const char * ) V_1 -> V_6 ;
return F_2 ( V_2 , V_3 , V_4 , V_5 , strlen ( V_5 ) ) ;
}
static int F_3 ( struct V_7 * V_7 , struct V_1 * V_1 )
{
F_4 ( V_1 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_7 , struct V_1 * V_1 )
{
V_1 -> V_6 = ( void * ) F_6 ( V_8 , L_1 ,
V_9 ) ;
if ( ! V_1 -> V_6 )
return - V_10 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_11 * V_12 )
{
T_3 V_3 = V_12 -> V_13 - V_12 -> V_14 ;
if ( ( V_3 > V_15 ) || ( V_12 -> V_16 != 0 ) )
return - V_17 ;
if ( F_8 ( V_12 , V_12 -> V_14 ,
F_9 ( V_9 ) ,
V_3 , V_12 -> V_18 ) )
return - V_19 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_7 , struct V_1 * V_1 )
{
V_1 -> V_6 = ( void * ) F_6 ( V_8 , L_2 ,
V_20 ) ;
if ( ! V_1 -> V_6 )
return - V_10 ;
return 0 ;
}
