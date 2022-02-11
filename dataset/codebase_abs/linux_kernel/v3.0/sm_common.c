static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
int V_8 , error = 0 ;
memset ( & V_7 , - 1 , V_9 ) ;
V_7 . V_10 = 0x0F ;
V_5 . V_11 = V_12 ;
V_5 . V_13 = 0 ;
V_5 . V_14 = V_2 -> V_15 ;
V_5 . V_16 = ( void * ) & V_7 ;
V_5 . V_17 = NULL ;
V_8 = V_2 -> V_18 ( V_2 , V_3 , & V_5 ) ;
if ( V_8 < 0 || V_5 . V_19 != V_9 ) {
F_2 ( V_20
L_1 ,
( int ) V_3 ) ;
error = - V_21 ;
} else
V_2 -> V_22 . V_23 ++ ;
return error ;
}
int F_3 ( struct V_1 * V_2 , int V_24 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_8 ;
V_26 -> V_28 |= V_29 ;
V_8 = F_4 ( V_2 , 1 , V_24 ?
V_30 : V_31 ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_32 = 0x05 ;
V_26 -> V_33 = 7 ;
V_26 -> V_34 = F_1 ;
if ( V_2 -> V_35 == V_36 )
V_26 -> V_37 . V_38 = & V_39 ;
else if ( V_2 -> V_35 == V_40 )
V_26 -> V_37 . V_38 = & V_41 ;
else
return - V_42 ;
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_2 , NULL , 0 ) ;
}
