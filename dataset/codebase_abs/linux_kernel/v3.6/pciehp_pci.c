int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 = V_2 -> V_6 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_12 , V_13 ;
struct V_14 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_10 , F_3 ( 0 , 0 ) ) ;
if ( V_4 ) {
F_4 ( V_6 , L_1
L_2 , F_5 ( V_4 ) ,
F_6 ( V_10 ) , V_10 -> V_15 ) ;
F_7 ( V_4 ) ;
return - V_16 ;
}
V_12 = F_8 ( V_10 , F_3 ( 0 , 0 ) ) ;
if ( V_12 == 0 ) {
F_4 ( V_6 , L_3 ) ;
return - V_17 ;
}
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_4 = F_2 ( V_10 , F_3 ( 0 , V_13 ) ) ;
if ( ! V_4 )
continue;
if ( ( V_4 -> V_18 == V_19 ) ||
( V_4 -> V_18 == V_20 ) )
F_9 ( V_4 ) ;
F_7 ( V_4 ) ;
}
F_10 ( V_5 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_4 = F_2 ( V_10 , F_3 ( 0 , V_13 ) ) ;
if ( ! V_4 )
continue;
if ( ( V_4 -> V_21 >> 16 ) == V_22 ) {
F_7 ( V_4 ) ;
continue;
}
F_11 ( V_4 ) ;
F_7 ( V_4 ) ;
}
F_12 ( V_10 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_23 , V_24 = 0 ;
int V_25 ;
T_1 V_26 = 0 ;
T_1 V_27 = 0 ;
struct V_9 * V_10 = V_2 -> V_6 -> V_7 -> V_8 -> V_11 ;
T_2 V_28 ;
struct V_14 * V_6 = V_2 -> V_6 ;
F_14 ( V_6 , L_4 ,
V_29 , F_6 ( V_10 ) , V_10 -> V_15 ) ;
V_23 = F_15 ( V_2 , & V_27 ) ;
if ( V_23 )
V_27 = 0 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
struct V_3 * V_30 = F_2 ( V_10 , F_3 ( 0 , V_25 ) ) ;
if ( ! V_30 )
continue;
if ( V_30 -> V_18 == V_19 && V_27 ) {
F_16 ( V_30 , V_31 , & V_26 ) ;
if ( V_26 & V_32 ) {
F_4 ( V_6 ,
L_5 ,
F_5 ( V_30 ) ) ;
F_7 ( V_30 ) ;
V_24 = - V_16 ;
break;
}
}
F_17 ( V_30 ) ;
if ( V_27 ) {
F_18 ( V_30 , V_33 , & V_28 ) ;
V_28 &= ~ ( V_34 | V_35 ) ;
V_28 |= V_36 ;
F_19 ( V_30 , V_33 , V_28 ) ;
}
F_7 ( V_30 ) ;
}
return V_24 ;
}
