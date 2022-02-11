int F_1 ( struct V_1 * V_2 )
{
V_3 = * V_2 ;
V_4 = V_5 ;
V_6 = V_7 ;
V_8 = V_9 ;
V_10 = V_11 ;
V_12 = V_13 ;
V_14 = V_15 ;
V_16 = V_17 ;
V_18 = V_19 ;
V_20 = V_21 ;
V_22 = V_23 ;
return 0 ;
}
int
F_2 ( struct V_24 * V_25 , void * V_26 )
{
int V_27 ;
V_27 = F_3 ( V_25 ,
V_28 ,
(struct V_29 * ) V_26 ,
sizeof( struct V_29 ) ) ;
return V_27 ;
}
int F_4 ( struct V_24 * V_30 ,
T_1 V_31 ,
T_1 V_32 )
{
T_1 V_33 ;
T_1 V_34 ;
int V_27 ;
V_33 = V_35 | V_36 ;
V_34 = ( ( T_1 ) V_31 << 16 ) | V_32 ;
V_27 = F_5 ( V_30 , & V_33 , & V_34 ) ;
return V_27 ;
}
int F_6 ( struct V_24 * V_30 , T_1 * V_37 )
{
T_1 V_33 ;
int V_27 ;
V_33 = V_38 | V_39 ;
V_27 = F_7 ( V_30 , & V_33 , V_37 ) ;
return V_27 ;
}
