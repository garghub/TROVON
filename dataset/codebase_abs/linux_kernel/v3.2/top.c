T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
float V_5 = V_2 -> V_6 / V_2 -> V_7 ;
float V_8 = V_2 -> V_9 / V_2 -> V_7 ;
float V_10 = ( 100.0 * V_2 -> V_11 ) / V_2 -> V_6 ;
T_1 V_12 = 0 ;
if ( ! V_13 ) {
V_12 = SNPRINTF ( V_3 , V_4 ,
L_1
L_2 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_8 ) /
V_5 ) ) ,
V_10 ) ;
} else {
float V_14 = V_2 -> V_15 / V_2 -> V_7 ;
float V_16 = V_2 -> V_17 / V_2 -> V_7 ;
float V_18 = V_2 -> V_19 / V_2 -> V_7 ;
V_12 = SNPRINTF ( V_3 , V_4 ,
L_3
L_4
L_5 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_8 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 - V_14 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_16 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_18 ) /
V_5 ) ) ,
V_10 ) ;
}
if ( V_2 -> V_20 -> V_21 == 1 ) {
struct V_22 * V_23 ;
V_23 = F_2 ( V_2 -> V_20 -> V_24 . V_25 , struct V_22 , V_26 ) ;
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_6 V_27 L_7 ,
( V_28 ) V_23 -> V_29 . V_30 ,
V_2 -> V_31 ? L_8 : L_9 ) ;
}
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_10 , F_3 ( V_2 -> V_32 ) ) ;
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_11 ) ;
if ( V_2 -> V_33 != - 1 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_12 ,
V_2 -> V_33 ) ;
else if ( V_2 -> V_34 != - 1 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_13 ,
V_2 -> V_34 ) ;
else
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_14 ) ;
if ( V_2 -> V_35 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_15 ,
V_2 -> V_20 -> V_36 -> V_37 > 1 ? L_16 : L_9 , V_2 -> V_35 ) ;
else {
if ( V_2 -> V_34 != - 1 )
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_17 ) ;
else
V_12 += SNPRINTF ( V_3 + V_12 , V_4 - V_12 , L_18 ,
V_2 -> V_20 -> V_36 -> V_37 ,
V_2 -> V_20 -> V_36 -> V_37 > 1 ? L_16 : L_9 ) ;
}
return V_12 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_15 = V_2 -> V_9 =
V_2 -> V_11 = V_2 -> V_17 =
V_2 -> V_19 = 0 ;
}
