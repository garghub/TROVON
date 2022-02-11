int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_7 = V_6 -> V_3 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 , V_12 = 0 ;
F_2 () ;
V_4 = F_3 ( V_9 , F_4 ( V_2 -> V_13 , 0 ) ) ;
if ( V_4 ) {
F_5 ( V_6 , L_1
L_2 , F_6 ( V_4 ) ,
F_7 ( V_9 ) , V_2 -> V_14 , V_2 -> V_13 ) ;
F_8 ( V_4 ) ;
V_12 = - V_15 ;
goto V_16;
}
V_11 = F_9 ( V_9 , F_4 ( V_2 -> V_13 , 0 ) ) ;
if ( V_11 == 0 ) {
F_5 ( V_6 , L_3 ) ;
V_12 = - V_17 ;
goto V_16;
}
F_10 (dev, &parent->devices, bus_list) {
if ( F_11 ( V_4 -> V_18 ) != V_2 -> V_13 )
continue;
if ( ( V_4 -> V_19 == V_20 ) ||
( V_4 -> V_19 == V_21 ) )
F_12 ( V_4 ) ;
}
F_13 ( V_7 ) ;
F_10 (dev, &parent->devices, bus_list) {
if ( F_11 ( V_4 -> V_18 ) != V_2 -> V_13 )
continue;
F_14 ( V_4 ) ;
}
F_15 ( V_9 ) ;
V_16:
F_16 () ;
return V_12 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
T_2 V_23 = 0 ;
struct V_8 * V_9 = V_2 -> V_6 -> V_3 -> V_10 ;
struct V_3 * V_4 , * V_24 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( V_6 , L_4 ,
V_25 , F_7 ( V_9 ) , V_2 -> V_14 , V_2 -> V_13 ) ;
F_2 () ;
F_19 (dev, temp, &parent->devices, bus_list) {
if ( F_11 ( V_4 -> V_18 ) != V_2 -> V_13 )
continue;
F_20 ( V_4 ) ;
if ( V_4 -> V_19 == V_20 ) {
F_21 ( V_4 , V_26 , & V_23 ) ;
if ( V_23 & V_27 ) {
F_5 ( V_6 ,
L_5 ,
F_6 ( V_4 ) ) ;
F_8 ( V_4 ) ;
V_22 = - V_15 ;
break;
}
}
F_22 ( V_4 ) ;
F_8 ( V_4 ) ;
}
F_16 () ;
return V_22 ;
}
