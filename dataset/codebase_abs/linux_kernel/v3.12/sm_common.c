static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
int V_8 ;
memset ( & V_7 , - 1 , V_9 ) ;
V_7 . V_10 = 0x0F ;
V_5 . V_11 = V_12 ;
V_5 . V_13 = 0 ;
V_5 . V_14 = V_2 -> V_15 ;
V_5 . V_16 = ( void * ) & V_7 ;
V_5 . V_17 = NULL ;
V_8 = F_2 ( V_2 , V_3 , & V_5 ) ;
if ( V_8 < 0 || V_5 . V_18 != V_9 ) {
F_3 ( V_19
L_1 ,
( int ) V_3 ) ;
return - V_20 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_21 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
int V_8 ;
V_23 -> V_25 |= V_26 ;
V_8 = F_5 ( V_2 , 1 , V_21 ?
V_27 : V_28 ) ;
if ( V_8 )
return V_8 ;
V_23 -> V_29 = 0x05 ;
V_23 -> V_30 = 7 ;
V_23 -> V_31 = F_1 ;
if ( V_2 -> V_32 == V_33 )
V_23 -> V_34 . V_35 = & V_36 ;
else if ( V_2 -> V_32 == V_37 )
V_23 -> V_34 . V_35 = & V_38 ;
else
return - V_39 ;
V_8 = F_6 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_7 ( V_2 , NULL , 0 ) ;
}
