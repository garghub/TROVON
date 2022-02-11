int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_7 , T_2 V_8 ,
T_2 V_9 , T_2 V_10 , T_3 V_11 )
{
int V_12 = V_5 -> V_13 ;
struct V_14 * V_15 ;
int V_16 ;
F_2 ( V_5 ) ;
F_3 ( V_5 ) ;
V_5 -> V_17 = 0 ;
F_4 ( V_5 ) ;
F_5 ( V_5 , & V_3 -> V_7 ) ;
memset ( F_6 ( V_5 ) , 0 , sizeof( * F_6 ( V_5 ) ) ) ;
F_7 ( V_5 , sizeof( struct V_14 ) ) ;
F_8 ( V_5 ) ;
V_15 = F_9 ( V_5 ) ;
V_15 -> V_18 = 4 ;
V_15 -> V_19 = sizeof( struct V_14 ) >> 2 ;
V_15 -> V_20 = V_11 ;
V_15 -> V_21 = V_8 ;
V_15 -> V_9 = V_9 ;
V_15 -> V_22 = V_7 ;
V_15 -> V_23 = V_6 ;
V_15 -> V_10 = V_10 ;
F_10 ( V_15 , & V_3 -> V_7 , ( F_11 ( V_5 ) -> V_24 ? : 1 ) - 1 ) ;
V_16 = F_12 ( V_5 ) ;
if ( F_13 ( F_14 ( V_16 ) ) )
V_12 = 0 ;
return V_12 ;
}
int F_15 ( struct V_4 * V_5 , int V_25 , T_3 V_26 )
{
if ( F_13 ( ! F_16 ( V_5 , V_25 ) ) )
return - V_27 ;
F_17 ( V_5 , V_25 ) ;
if ( V_26 == F_18 ( V_28 ) ) {
struct V_29 * V_30 = (struct V_29 * ) V_5 -> V_31 ;
if ( F_13 ( ! F_16 ( V_5 , V_32 ) ) )
return - V_27 ;
if ( F_19 ( F_20 ( V_30 -> V_33 ) >= V_34 ) )
V_5 -> V_21 = V_30 -> V_33 ;
else
V_5 -> V_21 = F_18 ( V_35 ) ;
} else {
V_5 -> V_21 = V_26 ;
}
F_2 ( V_5 ) ;
F_3 ( V_5 ) ;
if ( ! V_5 -> V_36 )
V_5 -> V_17 = 0 ;
F_4 ( V_5 ) ;
V_5 -> V_37 = 0 ;
F_21 ( V_5 , 0 ) ;
V_5 -> V_38 = V_39 ;
return 0 ;
}
