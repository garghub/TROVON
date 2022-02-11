int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 = V_2 -> V_6 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_12 ;
struct V_13 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_10 , F_3 ( 0 , 0 ) ) ;
if ( V_4 ) {
F_4 ( V_6 , L_1
L_2 , F_5 ( V_4 ) ,
F_6 ( V_10 ) , V_10 -> V_14 ) ;
F_7 ( V_4 ) ;
return - V_15 ;
}
V_12 = F_8 ( V_10 , F_3 ( 0 , 0 ) ) ;
if ( V_12 == 0 ) {
F_4 ( V_6 , L_3 ) ;
return - V_16 ;
}
F_9 (dev, &parent->devices, bus_list)
if ( ( V_4 -> V_17 == V_18 ) ||
( V_4 -> V_17 == V_19 ) )
F_10 ( V_4 ) ;
F_11 ( V_5 ) ;
F_9 (dev, &parent->devices, bus_list) {
if ( ( V_4 -> V_20 >> 16 ) == V_21 )
continue;
F_12 ( V_4 ) ;
}
F_13 ( V_10 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_22 , V_23 = 0 ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
struct V_3 * V_4 , * V_26 ;
struct V_9 * V_10 = V_2 -> V_6 -> V_7 -> V_8 -> V_11 ;
T_2 V_27 ;
struct V_13 * V_6 = V_2 -> V_6 ;
F_15 ( V_6 , L_4 ,
V_28 , F_6 ( V_10 ) , V_10 -> V_14 ) ;
V_22 = F_16 ( V_2 , & V_25 ) ;
if ( V_22 )
V_25 = 0 ;
F_17 (dev, temp, &parent->devices,
bus_list) {
F_18 ( V_4 ) ;
if ( V_4 -> V_17 == V_18 && V_25 ) {
F_19 ( V_4 , V_29 , & V_24 ) ;
if ( V_24 & V_30 ) {
F_4 ( V_6 ,
L_5 ,
F_5 ( V_4 ) ) ;
F_7 ( V_4 ) ;
V_23 = - V_15 ;
break;
}
}
F_20 ( V_4 ) ;
if ( V_25 ) {
F_21 ( V_4 , V_31 , & V_27 ) ;
V_27 &= ~ ( V_32 | V_33 ) ;
V_27 |= V_34 ;
F_22 ( V_4 , V_31 , V_27 ) ;
}
F_7 ( V_4 ) ;
}
return V_23 ;
}
