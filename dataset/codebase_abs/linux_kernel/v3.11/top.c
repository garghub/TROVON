T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
float V_5 ;
float V_6 ;
float V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 ;
T_1 V_13 = 0 ;
if ( V_2 -> V_14 ) {
V_5 = V_2 -> V_14 / V_2 -> V_15 ;
V_6 = V_2 -> V_16 / V_2 -> V_15 ;
V_7 = ( 100.0 * V_2 -> V_17 ) / V_2 -> V_14 ;
} else {
V_5 = V_6 = V_7 = 0.0 ;
}
if ( ! V_18 ) {
float V_19 = 0.0 ;
if ( V_5 )
V_19 = ( 100.0 * V_6 ) /
V_5 ;
V_13 = SNPRINTF ( V_3 , V_4 ,
L_1
L_2 , V_5 ,
V_19 , V_7 ) ;
} else {
float V_20 = V_2 -> V_21 / V_2 -> V_15 ;
float V_22 = V_2 -> V_23 / V_2 -> V_15 ;
float V_24 = V_2 -> V_25 / V_2 -> V_15 ;
V_13 = SNPRINTF ( V_3 , V_4 ,
L_3
L_4
L_5 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_6 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 - V_20 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_22 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_24 ) /
V_5 ) ) ,
V_7 ) ;
}
if ( V_2 -> V_26 -> V_27 == 1 ) {
struct V_28 * V_29 = F_2 ( V_2 -> V_26 ) ;
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_6 V_30 L_7 ,
( V_31 ) V_29 -> V_32 . V_33 ,
V_9 -> V_34 ? L_8 : L_9 ) ;
}
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_10 , F_3 ( V_2 -> V_35 ) ) ;
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_11 ) ;
if ( V_12 -> V_36 )
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_12 ,
V_12 -> V_36 ) ;
else if ( V_12 -> V_37 )
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_13 ,
V_12 -> V_37 ) ;
else if ( V_12 -> V_38 != NULL )
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_14 ,
V_12 -> V_38 ) ;
else
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_15 ) ;
if ( V_12 -> V_39 )
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_16 ,
V_2 -> V_26 -> V_40 -> V_41 > 1 ? L_17 : L_9 ,
V_12 -> V_39 ) ;
else {
if ( V_12 -> V_37 )
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_18 ) ;
else
V_13 += SNPRINTF ( V_3 + V_13 , V_4 - V_13 , L_19 ,
V_2 -> V_26 -> V_40 -> V_41 ,
V_2 -> V_26 -> V_40 -> V_41 > 1 ? L_17 : L_9 ) ;
}
return V_13 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_14 = V_2 -> V_21 = V_2 -> V_16 =
V_2 -> V_17 = V_2 -> V_23 =
V_2 -> V_25 = 0 ;
}
