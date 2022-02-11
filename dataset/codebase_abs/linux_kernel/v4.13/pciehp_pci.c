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
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
V_17:
F_16 () ;
return V_13 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
struct V_3 * V_4 , * V_22 ;
struct V_9 * V_10 = V_2 -> V_6 -> V_7 -> V_8 -> V_11 ;
T_2 V_23 ;
struct V_14 * V_6 = V_2 -> V_6 ;
F_18 ( V_6 , L_3 ,
V_24 , F_7 ( V_10 ) , V_10 -> V_15 ) ;
F_19 ( V_2 , & V_21 ) ;
F_2 () ;
F_20 (dev, temp, &parent->devices,
bus_list) {
F_21 ( V_4 ) ;
if ( V_4 -> V_25 == V_26 && V_21 ) {
F_22 ( V_4 , V_27 , & V_20 ) ;
if ( V_20 & V_28 ) {
F_5 ( V_6 ,
L_4 ,
F_6 ( V_4 ) ) ;
F_8 ( V_4 ) ;
V_19 = - V_29 ;
break;
}
}
if ( ! V_21 ) {
F_23 ( V_4 , NULL ) ;
if ( F_24 ( V_4 ) )
F_25 ( V_4 -> V_11 ,
F_23 , NULL ) ;
}
F_26 ( V_4 ) ;
if ( V_21 ) {
F_27 ( V_4 , V_30 , & V_23 ) ;
V_23 &= ~ ( V_31 | V_32 ) ;
V_23 |= V_33 ;
F_28 ( V_4 , V_30 , V_23 ) ;
}
F_8 ( V_4 ) ;
}
F_16 () ;
return V_19 ;
}
