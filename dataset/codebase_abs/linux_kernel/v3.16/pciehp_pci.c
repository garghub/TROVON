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
F_5 ( V_6 , L_1 ,
F_6 ( V_4 ) , F_7 ( V_10 ) , V_10 -> V_15 ) ;
F_8 ( V_4 ) ;
V_13 = - V_16 ;
goto V_17;
}
V_12 = F_9 ( V_10 , F_4 ( 0 , 0 ) ) ;
if ( V_12 == 0 ) {
F_5 ( V_6 , L_2 ) ;
V_13 = - V_18 ;
goto V_17;
}
F_10 (dev, &parent->devices, bus_list)
if ( F_11 ( V_4 ) )
F_12 ( V_4 ) ;
F_13 ( V_5 ) ;
F_10 (dev, &parent->devices, bus_list) {
if ( ( V_4 -> V_19 >> 16 ) == V_20 )
continue;
F_14 ( V_4 ) ;
}
F_15 ( V_10 ) ;
V_17:
F_16 () ;
return V_13 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
struct V_3 * V_4 , * V_24 ;
struct V_9 * V_10 = V_2 -> V_6 -> V_7 -> V_8 -> V_11 ;
T_2 V_25 ;
struct V_14 * V_6 = V_2 -> V_6 ;
F_18 ( V_6 , L_3 ,
V_26 , F_7 ( V_10 ) , V_10 -> V_15 ) ;
F_19 ( V_2 , & V_23 ) ;
F_2 () ;
F_20 (dev, temp, &parent->devices,
bus_list) {
F_21 ( V_4 ) ;
if ( V_4 -> V_27 == V_28 && V_23 ) {
F_22 ( V_4 , V_29 , & V_22 ) ;
if ( V_22 & V_30 ) {
F_5 ( V_6 ,
L_4 ,
F_6 ( V_4 ) ) ;
F_8 ( V_4 ) ;
V_21 = - V_31 ;
break;
}
}
F_23 ( V_4 ) ;
if ( V_23 ) {
F_24 ( V_4 , V_32 , & V_25 ) ;
V_25 &= ~ ( V_33 | V_34 ) ;
V_25 |= V_35 ;
F_25 ( V_4 , V_32 , V_25 ) ;
}
F_8 ( V_4 ) ;
}
F_16 () ;
return V_21 ;
}
