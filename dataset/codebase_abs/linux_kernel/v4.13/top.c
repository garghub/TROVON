T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
float V_5 ;
float V_6 ;
float V_7 ;
struct V_8 * V_9 = & V_2 -> V_8 ;
struct V_10 * V_10 = & V_9 -> V_10 ;
T_1 V_11 = 0 ;
if ( V_2 -> V_12 ) {
V_5 = V_2 -> V_12 / V_2 -> V_13 ;
V_6 = V_2 -> V_14 / V_2 -> V_13 ;
V_7 = ( 100.0 * V_2 -> V_15 ) / V_2 -> V_12 ;
} else {
V_5 = V_6 = V_7 = 0.0 ;
}
if ( ! V_16 ) {
float V_17 = 0.0 ;
if ( V_5 )
V_17 = ( 100.0 * V_6 ) /
V_5 ;
V_11 = SNPRINTF ( V_3 , V_4 ,
L_1
L_2 , V_5 ,
V_17 , V_7 ) ;
} else {
float V_18 = V_2 -> V_19 / V_2 -> V_13 ;
float V_20 = V_2 -> V_21 / V_2 -> V_13 ;
float V_22 = V_2 -> V_23 / V_2 -> V_13 ;
V_11 = SNPRINTF ( V_3 , V_4 ,
L_3
L_4
L_5 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_6 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 - V_18 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_20 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_22 ) /
V_5 ) ) ,
V_7 ) ;
}
if ( V_2 -> V_24 -> V_25 == 1 ) {
struct V_26 * V_27 = F_2 ( V_2 -> V_24 ) ;
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_6 V_28 L_7 ,
( V_29 ) V_27 -> V_30 . V_31 ,
V_9 -> V_32 ? L_8 : L_9 ) ;
}
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_10 , F_3 ( V_2 -> V_33 ) ) ;
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_11 ) ;
if ( V_10 -> V_34 )
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_12 ,
V_10 -> V_34 ) ;
else if ( V_10 -> V_35 )
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_13 ,
V_10 -> V_35 ) ;
else if ( V_10 -> V_36 != NULL )
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_14 ,
V_10 -> V_36 ) ;
else
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_15 ) ;
if ( V_10 -> V_37 )
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_16 ,
V_2 -> V_24 -> V_38 -> V_39 > 1 ? L_17 : L_9 ,
V_10 -> V_37 ) ;
else {
if ( V_10 -> V_35 )
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_18 ) ;
else
V_11 += SNPRINTF ( V_3 + V_11 , V_4 - V_11 , L_19 ,
V_2 -> V_24 -> V_38 -> V_39 ,
V_2 -> V_24 -> V_38 -> V_39 > 1 ? L_17 : L_9 ) ;
}
return V_11 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_12 = V_2 -> V_19 = V_2 -> V_14 =
V_2 -> V_15 = V_2 -> V_21 =
V_2 -> V_23 = 0 ;
}
