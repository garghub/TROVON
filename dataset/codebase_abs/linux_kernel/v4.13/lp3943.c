int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 * V_3 )
{
int V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_1 -> V_6 , V_2 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = ( T_1 ) V_5 ;
return 0 ;
}
int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 )
{
return F_4 ( V_1 -> V_6 , V_2 , V_7 ) ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_8 , T_1 V_7 )
{
return F_6 ( V_1 -> V_6 , V_2 , V_8 , V_7 ) ;
}
static int F_7 ( struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_1 * V_1 ;
struct V_13 * V_14 = & V_10 -> V_14 ;
V_1 = F_8 ( V_14 , sizeof( * V_1 ) , V_15 ) ;
if ( ! V_1 )
return - V_16 ;
V_1 -> V_6 = F_9 ( V_10 , & V_17 ) ;
if ( F_10 ( V_1 -> V_6 ) )
return F_11 ( V_1 -> V_6 ) ;
V_1 -> V_18 = F_12 ( V_14 ) ;
V_1 -> V_14 = V_14 ;
V_1 -> V_19 = V_20 ;
F_13 ( V_10 , V_1 ) ;
return F_14 ( V_14 , - 1 , V_21 ,
F_15 ( V_21 ) ,
NULL , 0 , NULL ) ;
}
