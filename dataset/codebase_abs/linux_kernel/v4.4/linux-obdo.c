void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
V_5 &= V_4 -> V_6 ;
if ( V_5 & ( V_7 | V_8 ) )
F_2 ( V_9 ,
L_1 ,
V_4 -> V_6 , F_3 ( V_2 -> V_10 ) ,
F_3 ( V_2 -> V_11 ) , V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_5 & V_14 && V_4 -> V_15 > F_3 ( V_2 -> V_16 ) )
F_3 ( V_2 -> V_16 ) = V_4 -> V_15 ;
if ( V_5 & V_8 && V_4 -> V_12 > F_3 ( V_2 -> V_10 ) )
F_3 ( V_2 -> V_10 ) = V_4 -> V_12 ;
if ( V_5 & V_7 && V_4 -> V_13 > F_3 ( V_2 -> V_11 ) )
F_3 ( V_2 -> V_11 ) = V_4 -> V_13 ;
if ( V_5 & V_17 )
F_4 ( V_2 , V_4 -> V_18 ) ;
if ( V_5 & V_19 && V_4 -> V_20 > ( 1 << V_2 -> V_21 ) )
V_2 -> V_21 = F_5 ( V_4 -> V_20 ) - 1 ;
if ( V_2 -> V_21 < V_22 )
V_2 -> V_21 = V_22 ;
if ( V_5 & V_23 && V_4 -> V_24 > V_2 -> V_25 )
V_2 -> V_25 = V_4 -> V_24 ;
}
