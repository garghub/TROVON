int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
T_1 V_6 = 0 ;
T_1 V_7 = 0 ;
T_1 V_8 = 0 ;
T_2 V_9 = V_4 -> V_10 ;
T_2 V_11 = V_4 -> V_12 ;
T_2 V_13 = V_4 -> V_14 ;
int V_15 ;
int V_16 = 0 ;
F_2 ( & V_2 -> V_17 ) ;
F_3 ( V_2 -> V_18 == F_4 () ) ;
F_5 ( V_19 , L_1 V_20 L_2 ,
F_6 ( & V_2 -> V_21 ) , V_4 -> V_22 , V_4 -> V_10 ,
V_4 -> V_12 , V_4 -> V_14 , V_4 -> V_23 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_24 ; V_15 ++ ) {
struct V_25 * V_26 = V_2 -> V_27 [ V_15 ] ;
T_3 V_28 , V_29 ;
if ( F_7 ( V_26 -> V_30 . V_23 ) ) {
V_16 = F_8 ( V_26 -> V_30 . V_23 ) ;
continue;
}
V_29 = V_26 -> V_31 ;
V_28 = F_9 ( V_2 , V_29 , V_15 ) ;
if ( V_28 > V_7 )
V_7 = V_28 ;
if ( V_26 -> V_30 . V_22 > V_29 )
V_29 = V_26 -> V_30 . V_22 ;
V_28 = F_9 ( V_2 , V_29 , V_15 ) ;
if ( V_28 > V_6 )
V_6 = V_28 ;
V_8 += V_26 -> V_30 . V_23 ;
if ( V_26 -> V_30 . V_10 > V_9 )
V_9 = V_26 -> V_30 . V_10 ;
if ( V_26 -> V_30 . V_12 > V_11 )
V_11 = V_26 -> V_30 . V_12 ;
if ( V_26 -> V_30 . V_14 > V_13 )
V_13 = V_26 -> V_30 . V_14 ;
F_5 ( V_19 , L_1 V_20 L_3 ,
F_6 ( & V_2 -> V_21 ) , V_26 -> V_32 ,
V_26 -> V_30 . V_22 , V_26 -> V_30 . V_10 ,
V_26 -> V_30 . V_12 , V_26 -> V_30 . V_14 ,
V_26 -> V_30 . V_23 ) ;
}
* V_5 = V_7 ;
V_4 -> V_22 = V_6 ;
V_4 -> V_23 = V_8 ;
V_4 -> V_10 = V_9 ;
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = V_13 ;
return V_16 ;
}
