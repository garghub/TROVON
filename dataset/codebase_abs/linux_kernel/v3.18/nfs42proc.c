static int F_1 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( F_3 ( V_2 ) ) ;
V_7 = F_4 ( V_5 ) ;
if ( F_5 ( V_7 ) ) {
F_6 ( V_5 ) ;
return F_7 ( V_7 ) ;
}
V_8 = F_8 ( V_1 , V_5 , V_7 , V_3 ) ;
F_9 ( V_7 ) ;
F_6 ( V_5 ) ;
return V_8 ;
}
T_3 F_10 ( struct V_2 * V_9 , T_3 V_10 , int V_11 )
{
struct V_12 * V_12 = F_11 ( V_9 ) ;
struct V_13 args = {
. V_14 = F_12 ( V_12 ) ,
. V_15 = V_10 ,
. V_16 = ( V_11 == V_17 ) ?
V_18 : V_19 ,
} ;
struct V_20 V_21 ;
struct V_22 V_23 = {
. V_24 = & V_25 [ V_26 ] ,
. V_27 = & args ,
. V_28 = & V_21 ,
} ;
struct V_29 * V_30 = F_13 ( V_12 ) ;
int V_31 ;
if ( ! ( V_30 -> V_32 & V_33 ) )
return - V_34 ;
V_31 = F_1 ( & args . V_35 , V_9 , V_36 ) ;
if ( V_31 )
return V_31 ;
F_14 ( V_12 ) ;
V_31 = F_15 ( V_30 -> V_37 , V_30 , & V_23 ,
& args . V_38 , & V_21 . V_39 , 0 ) ;
if ( V_31 == - V_34 )
V_30 -> V_32 &= ~ V_33 ;
if ( V_31 )
return V_31 ;
return F_16 ( V_9 , V_21 . V_40 , V_12 -> V_41 -> V_42 ) ;
}
