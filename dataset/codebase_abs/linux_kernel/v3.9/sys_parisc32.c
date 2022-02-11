T_1 long F_1 ( int V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , int V_7 )
{
F_2 ( V_8 L_1 ,
V_9 -> V_10 , V_9 -> V_11 , V_7 ) ;
return - V_12 ;
}
T_1 long F_3 ( T_2 V_13 , T_2 V_14 ,
T_3 T_4 * V_15 , T_5 V_16 )
{
return F_4 ( ( int ) V_13 , ( int ) V_14 , V_15 , V_16 ) ;
}
T_1 long F_5 ( T_2 V_13 , T_2 V_14 ,
T_6 T_4 * V_15 , T_5 V_16 )
{
return F_6 ( ( int ) V_13 , ( int ) V_14 ,
( V_17 T_4 * ) V_15 , V_16 ) ;
}
T_1 long F_7 ( int V_18 , int V_19 , int V_20 , union V_21 V_22 )
{
union V_21 V_23 ;
if ( V_20 == V_24 ) {
V_23 . V_25 = * ( ( int * ) & V_22 + 1 ) ;
return F_8 ( V_18 , V_19 , V_20 , V_23 ) ;
}
return F_8 ( V_18 , V_19 , V_20 , V_22 ) ;
}
long F_9 ( T_2 V_26 , T_2 V_27 , char T_4 * V_28 ,
T_7 V_29 )
{
return F_10 ( ( V_30 ) V_26 << 32 | V_27 ,
V_28 , V_29 ) ;
}
T_1 long F_11 ( int V_31 , int V_32 , T_2 V_33 ,
T_2 V_34 , int V_35 ,
const char T_4 * V_36 )
{
return F_12 ( V_31 , V_32 , ( ( V_30 ) V_33 << 32 ) | V_34 ,
V_35 , V_36 ) ;
}
