void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_4 -> V_9 ;
V_8 -> V_10 = V_11 ;
if ( V_6 -> V_12 == 0 )
V_8 -> V_13 = V_6 -> V_14 ;
else if ( V_6 -> V_12 == 1 )
V_8 -> V_13 = V_6 -> V_15 [ 3 ] ;
else if ( V_6 -> V_12 == 2 ) {
V_8 -> V_13 = V_16 ;
V_8 -> V_17 =
F_2 ( int , V_18 ,
F_3 ( V_6 -> V_19 ) ) ;
memcpy ( V_8 -> V_20 , V_6 -> V_21 , V_8 -> V_17 ) ;
if ( V_6 -> V_14 != V_16 )
F_4 ( V_22 , V_2 ,
L_1
L_2 ,
F_5 ( V_4 -> V_2 -> V_23 ) ,
V_6 -> V_14 ) ;
}
else
V_8 -> V_13 = V_16 ;
}
