T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
float V_5 = V_2 -> V_6 / V_2 -> V_7 ;
float V_8 = V_2 -> V_9 / V_2 -> V_7 ;
float V_10 = ( 100.0 * V_2 -> V_11 ) / V_2 -> V_6 ;
struct V_12 * V_13 = & V_2 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_16 ;
T_1 V_17 = 0 ;
if ( ! V_18 ) {
V_17 = SNPRINTF ( V_3 , V_4 ,
L_1
L_2 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_8 ) /
V_5 ) ) ,
V_10 ) ;
} else {
float V_19 = V_2 -> V_20 / V_2 -> V_7 ;
float V_21 = V_2 -> V_22 / V_2 -> V_7 ;
float V_23 = V_2 -> V_24 / V_2 -> V_7 ;
V_17 = SNPRINTF ( V_3 , V_4 ,
L_3
L_4
L_5 , V_5 ,
100.0 - ( 100.0 * ( ( V_5 - V_8 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 - V_19 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_21 ) /
V_5 ) ) ,
100.0 - ( 100.0 * ( ( V_5 -
V_23 ) /
V_5 ) ) ,
V_10 ) ;
}
if ( V_2 -> V_25 -> V_26 == 1 ) {
struct V_27 * V_28 = F_2 ( V_2 -> V_25 ) ;
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_6 V_29 L_7 ,
( V_30 ) V_28 -> V_31 . V_32 ,
V_13 -> V_33 ? L_8 : L_9 ) ;
}
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_10 , F_3 ( V_2 -> V_34 ) ) ;
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_11 ) ;
if ( V_16 -> V_35 )
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_12 ,
V_16 -> V_35 ) ;
else if ( V_16 -> V_36 )
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_13 ,
V_16 -> V_36 ) ;
else if ( V_16 -> V_37 != NULL )
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_14 ,
V_16 -> V_37 ) ;
else
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_15 ) ;
if ( V_16 -> V_38 )
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_16 ,
V_2 -> V_25 -> V_39 -> V_40 > 1 ? L_17 : L_9 ,
V_16 -> V_38 ) ;
else {
if ( V_16 -> V_36 )
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_18 ) ;
else
V_17 += SNPRINTF ( V_3 + V_17 , V_4 - V_17 , L_19 ,
V_2 -> V_25 -> V_39 -> V_40 ,
V_2 -> V_25 -> V_39 -> V_40 > 1 ? L_17 : L_9 ) ;
}
return V_17 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_20 = V_2 -> V_9 =
V_2 -> V_11 = V_2 -> V_22 =
V_2 -> V_24 = 0 ;
}
