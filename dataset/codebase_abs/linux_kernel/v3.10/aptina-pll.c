int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
unsigned int V_11 ;
unsigned int div ;
F_2 ( V_2 , L_1 ,
V_6 -> V_12 , V_6 -> V_13 ) ;
if ( V_6 -> V_12 < V_4 -> V_14 ||
V_6 -> V_12 > V_4 -> V_15 ) {
F_3 ( V_2 , L_2 ) ;
return - V_16 ;
}
if ( V_6 -> V_13 == 0 || V_6 -> V_13 > V_4 -> V_17 ) {
F_3 ( V_2 , L_3 ) ;
return - V_16 ;
}
div = F_4 ( V_6 -> V_13 , V_6 -> V_12 ) ;
V_6 -> V_18 = V_6 -> V_13 / div ;
div = V_6 -> V_12 / div ;
V_7 = F_5 ( V_4 -> V_19 , V_6 -> V_18 ) ;
V_7 = F_6 ( V_7 , V_4 -> V_20 /
( V_6 -> V_12 / V_4 -> V_21 * V_6 -> V_18 ) ) ;
V_7 = F_6 ( V_7 , V_4 -> V_21 * V_4 -> V_9 / div ) ;
V_8 = V_4 -> V_22 / V_6 -> V_18 ;
V_8 = F_7 ( V_8 , V_4 -> V_23 /
( V_6 -> V_12 / V_4 -> V_24 * V_6 -> V_18 ) ) ;
V_8 = F_7 ( V_8 , F_5 ( V_4 -> V_24 * V_4 -> V_10 , div ) ) ;
F_2 ( V_2 , L_4 , V_7 , V_8 ) ;
if ( V_7 > V_8 ) {
F_3 ( V_2 , L_5 ) ;
return - V_16 ;
}
if ( V_4 -> V_9 == 0 ) {
F_3 ( V_2 , L_6 ) ;
return - V_16 ;
}
V_9 = F_6 ( V_4 -> V_9 , F_5 ( V_4 -> V_20 * div ,
V_6 -> V_12 * V_6 -> V_18 ) ) ;
V_10 = F_7 ( V_4 -> V_10 , V_4 -> V_23 * div /
( V_6 -> V_12 * V_6 -> V_18 ) ) ;
for ( V_11 = V_10 & ~ 1 ; V_11 >= V_9 ; V_11 -= 2 ) {
unsigned int V_25 = V_11 / F_4 ( div , V_11 ) ;
unsigned int V_26 ;
unsigned int V_27 ;
V_27 = F_8 ( F_6 ( V_7 , F_5 ( V_6 -> V_12 * V_11 ,
V_4 -> V_28 * div ) ) , V_25 ) ;
V_26 = F_7 ( V_8 , V_6 -> V_12 * V_11 /
( V_4 -> V_29 * div ) ) ;
if ( V_27 > V_26 )
continue;
V_6 -> V_30 = div * V_27 / V_11 ;
V_6 -> V_18 *= V_27 ;
V_6 -> V_11 = V_11 ;
F_2 ( V_2 , L_7 , V_6 -> V_30 , V_6 -> V_18 , V_6 -> V_11 ) ;
return 0 ;
}
F_3 ( V_2 , L_8 ) ;
return - V_16 ;
}
