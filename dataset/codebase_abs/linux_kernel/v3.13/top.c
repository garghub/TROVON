T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
float V_5 ;
float V_6 ;
float V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_11 ;
T_1 V_12 = 0 ;
if ( V_2 -> V_13 ) {
V_5 = V_2 -> V_13 / V_2 -> V_14 ;
V_6 = V_2 -> V_15 / V_2 -> V_14 ;
V_7 = ( 100.0 * V_2 -> V_16 ) / V_2 -> V_13 ;
} else {
V_5 = V_6 = V_7 = 0.0 ;
}
if ( ! V_17 ) {
float V_18 = 0.0 ;
if ( V_5 )
V_18 = ( 100.0 * V_6 ) /
V_5 ;
V_12 = SNPRINTF ( V_3 , V_4 ,
L_1
L_2 , V_5 ,
V_18 , V_7 ) ;
} else {
float V_19 = V_2 -> V_20 / V_2 -> V_14 ;
float V_21 = V_2 -> V_22 / V_2 -> V_14 ;
float V_23 = V_2 -> V_24 / V_2 -> V_14 ;
V_12 = SNPRINTF ( V_3 , V_4 ,
L_3
L_4
L_5 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_6 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 - V_19 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_21 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_23 ) /
V_5 ) ) ,
V_7 ) ;
}
if ( V_2 -> V_25 -> V_26 == 1 ) {
struct V_27 * V_28 = F_2 ( V_2 -> V_25 ) ;
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_6 V_29 L_7 ,
( V_30 ) V_28 -> V_31 . V_32 ,
V_9 -> V_33 ? L_8 : L_9 ) ;
}
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_10 , F_3 ( V_2 -> V_34 ) ) ;
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_11 ) ;
if ( V_11 -> V_35 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_12 ,
V_11 -> V_35 ) ;
else if ( V_11 -> V_36 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_13 ,
V_11 -> V_36 ) ;
else if ( V_11 -> V_37 != NULL )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_14 ,
V_11 -> V_37 ) ;
else
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_15 ) ;
if ( V_11 -> V_38 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_16 ,
V_2 -> V_25 -> V_39 -> V_40 > 1 ? L_17 : L_9 ,
V_11 -> V_38 ) ;
else {
if ( V_11 -> V_36 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_18 ) ;
else
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_19 ,
V_2 -> V_25 -> V_39 -> V_40 ,
V_2 -> V_25 -> V_39 -> V_40 > 1 ? L_17 : L_9 ) ;
}
return V_12 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_13 = V_2 -> V_20 = V_2 -> V_15 =
V_2 -> V_16 = V_2 -> V_22 =
V_2 -> V_24 = 0 ;
}
