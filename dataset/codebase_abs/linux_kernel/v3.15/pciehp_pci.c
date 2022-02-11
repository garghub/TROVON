int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 = V_2 -> V_6 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_12 , V_13 = 0 ;
struct V_14 * V_6 = V_2 -> V_6 ;
F_2 () ;
V_4 = F_3 ( V_10 , F_4 ( 0 , 0 ) ) ;
if ( V_4 ) {
F_5 ( V_6 , L_1
L_2 , F_6 ( V_4 ) ,
F_7 ( V_10 ) , V_10 -> V_15 ) ;
F_8 ( V_4 ) ;
V_13 = - V_16 ;
goto V_17;
}
V_12 = F_9 ( V_10 , F_4 ( 0 , 0 ) ) ;
if ( V_12 == 0 ) {
F_5 ( V_6 , L_3 ) ;
V_13 = - V_18 ;
goto V_17;
}
F_10 (dev, &parent->devices, bus_list)
if ( ( V_4 -> V_19 == V_20 ) ||
( V_4 -> V_19 == V_21 ) )
F_11 ( V_4 ) ;
F_12 ( V_5 ) ;
F_10 (dev, &parent->devices, bus_list) {
if ( ( V_4 -> V_22 >> 16 ) == V_23 )
continue;
F_13 ( V_4 ) ;
}
F_14 ( V_10 ) ;
V_17:
F_15 () ;
return V_13 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
T_1 V_25 = 0 ;
T_1 V_26 = 0 ;
struct V_3 * V_4 , * V_27 ;
struct V_9 * V_10 = V_2 -> V_6 -> V_7 -> V_8 -> V_11 ;
T_2 V_28 ;
struct V_14 * V_6 = V_2 -> V_6 ;
F_17 ( V_6 , L_4 ,
V_29 , F_7 ( V_10 ) , V_10 -> V_15 ) ;
F_18 ( V_2 , & V_26 ) ;
F_2 () ;
F_19 (dev, temp, &parent->devices,
bus_list) {
F_20 ( V_4 ) ;
if ( V_4 -> V_19 == V_20 && V_26 ) {
F_21 ( V_4 , V_30 , & V_25 ) ;
if ( V_25 & V_31 ) {
F_5 ( V_6 ,
L_5 ,
F_6 ( V_4 ) ) ;
F_8 ( V_4 ) ;
V_24 = - V_32 ;
break;
}
}
F_22 ( V_4 ) ;
if ( V_26 ) {
F_23 ( V_4 , V_33 , & V_28 ) ;
V_28 &= ~ ( V_34 | V_35 ) ;
V_28 |= V_36 ;
F_24 ( V_4 , V_33 , V_28 ) ;
}
F_8 ( V_4 ) ;
}
F_15 () ;
return V_24 ;
}
