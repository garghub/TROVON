static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_2 V_7 , V_8 ;
V_6 = F_2 ( V_4 ) ;
V_7 = V_6 -> V_9 -> V_10 -> V_11 ;
V_8 = V_6 -> V_9 -> V_10 -> V_12 ;
if ( V_7 == V_13 )
return V_14 ;
if ( F_3 ( V_8 >= V_15 ) ||
F_3 ( V_7 >= V_16 ) )
return V_14 ;
V_2 -> V_17 = V_4 -> V_18 ;
V_4 -> V_19 . V_20 ++ ;
V_4 -> V_19 . V_21 += V_2 -> V_22 ;
return F_4 ( V_6 -> V_9 , V_2 , V_8 , V_7 ) ;
}
void F_5 ( struct V_23 * V_6 , struct V_1 * V_2 )
{
struct V_1 * V_24 ;
struct V_5 * V_25 ;
T_3 V_26 = F_6 ( 0 , V_2 -> V_27 , V_2 -> V_22 ) ;
T_2 * V_27 ;
F_7 () ;
F_8 (sdata, &priv->slaves, list) {
if ( V_25 -> type != V_28 ||
! F_9 ( V_25 -> V_4 ) )
continue;
V_24 = F_10 ( V_2 , V_29 ) ;
V_24 -> V_4 = V_25 -> V_4 ;
V_24 -> V_30 = V_31 ;
V_27 = F_11 ( V_24 , 2 ) ;
V_27 [ 0 ] = V_26 & 0xff ;
V_27 [ 1 ] = V_26 >> 8 ;
F_12 ( V_24 ) ;
}
F_13 () ;
}
void F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = 2 ;
V_4 -> V_35 = V_36 ;
V_4 -> V_37 = 10 ;
V_4 -> type = V_38 ;
V_4 -> V_39 = V_40 | V_41 ;
V_4 -> V_42 = 0 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_45 = & V_46 ;
V_4 -> V_47 = & V_48 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> type = V_28 ;
V_6 -> V_7 = V_13 ;
V_6 -> V_8 = 0 ;
}
