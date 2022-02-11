static inline int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return F_2 ( V_2 , V_3 ,
V_6 | V_7 |
V_8 ,
V_4 , V_5 , NULL , 0 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 , int V_4 )
{
return F_1 ( V_2 , 1 , ( T_1 ) V_4 , 0 ) ;
}
static inline int
F_4 ( struct V_1 * V_2 , int V_4 )
{
return F_1 ( V_2 , 3 , ( T_1 ) V_4 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 ,
V_10 | V_11 | V_12 | V_13 ) ;
if ( V_9 != 0 && F_6 ( V_2 ) )
F_7 ( V_2 , V_14 , V_2 -> V_15 , L_1 , V_9 ) ;
return 0 ;
}
