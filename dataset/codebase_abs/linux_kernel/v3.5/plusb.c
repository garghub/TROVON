static inline int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return F_2 ( V_2 -> V_6 ,
F_3 ( V_2 -> V_6 , 0 ) ,
V_3 ,
V_7 | V_8 | V_9 ,
V_4 , V_5 ,
NULL , 0 ,
V_10 ) ;
}
static inline int
F_4 ( struct V_1 * V_2 , int V_4 )
{
return F_1 ( V_2 , 1 , ( T_1 ) V_4 , 0 ) ;
}
static inline int
F_5 ( struct V_1 * V_2 , int V_4 )
{
return F_1 ( V_2 , 3 , ( T_1 ) V_4 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_5 ( V_2 ,
V_12 | V_13 | V_14 | V_15 ) ;
if ( V_11 != 0 && F_7 ( V_2 ) )
F_8 ( V_2 , V_16 , V_2 -> V_17 , L_1 , V_11 ) ;
return 0 ;
}
