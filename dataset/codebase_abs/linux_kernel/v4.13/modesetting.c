void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 ,
T_3 V_10 , T_3 V_11 )
{
struct V_12 * V_13 ;
V_13 = F_2 ( V_2 , sizeof( * V_13 ) , V_14 ,
V_15 ) ;
if ( ! V_13 )
return;
V_13 -> V_16 = V_3 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_5 = V_5 ;
V_13 -> V_6 = V_6 ;
V_13 -> V_17 = V_7 ;
V_13 -> V_8 = V_8 ;
V_13 -> V_9 = V_9 ;
V_13 -> V_18 = V_10 ;
V_13 -> V_11 = V_11 ;
F_3 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_13 ) ;
}
int F_5 ( struct V_1 * V_2 , T_2 V_4 , T_2 V_5 ,
T_1 V_8 , T_1 V_9 )
{
struct V_19 * V_13 ;
V_13 = F_2 ( V_2 , sizeof( * V_13 ) , V_14 ,
V_20 ) ;
if ( ! V_13 )
return - V_21 ;
V_13 -> V_22 = V_4 ;
V_13 -> V_23 = V_5 ;
V_13 -> V_24 = V_8 ;
V_13 -> V_25 = V_9 ;
F_3 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_13 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , unsigned int V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_13 ;
T_4 V_30 ;
if ( F_7 ( ! V_28 ) )
return - V_31 ;
V_30 = V_26 * sizeof( struct V_27 ) ;
V_13 = F_2 ( V_2 , sizeof( * V_13 ) + V_30 , V_14 ,
V_32 ) ;
if ( ! V_13 )
return - V_21 ;
V_13 -> V_33 = V_26 ;
V_13 -> V_34 = sizeof( struct V_27 ) ;
V_13 -> V_35 = V_36 ;
F_3 ( V_2 , V_13 ) ;
if ( F_8 ( V_13 -> V_35 ) ) {
F_4 ( V_2 , V_13 ) ;
return - V_37 ;
}
memcpy ( V_28 , ( ( V_38 * ) V_13 ) + sizeof( struct V_29 ) , V_30 ) ;
F_4 ( V_2 , V_13 ) ;
return 0 ;
}
