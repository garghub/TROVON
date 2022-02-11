int F_1 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 )
{
return F_2 ( V_1 , ( V_5 * ) V_2 , V_3 , V_4 ,
F_3 ( T_2 ) ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 )
{
return F_5 ( V_1 , ( V_5 * ) V_2 , V_3 , V_4 ,
L_1 ,
F_3 ( T_2 ) ) ;
}
int F_6 ( T_1 * V_6 , T_2 * V_2 , T_1 * V_7 , int V_4 )
{
F_7 ( V_8 ) * V_9 ;
int V_10 = F_8 ( V_2 -> type ) ;
if ( V_10 == V_11 )
V_9 = V_2 -> V_12 . V_13 -> V_14 ;
else
V_9 = NULL ;
V_4 ^= V_15 ;
return F_9 ( V_6 , ( V_5 * ) V_2 , V_7 , V_4 ,
V_10 , V_16 , V_9 ,
F_3 ( T_2 ) ) ;
}
T_2 * F_10 ( T_1 * V_6 , T_1 * * V_17 )
{
return ( T_2 * ) F_11 ( V_6 , V_17 , F_3 ( T_2 ) ) ;
}
