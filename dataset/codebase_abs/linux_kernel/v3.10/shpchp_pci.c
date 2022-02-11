int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_7 = V_6 -> V_3 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 ;
V_4 = F_2 ( V_9 , F_3 ( V_2 -> V_12 , 0 ) ) ;
if ( V_4 ) {
F_4 ( V_6 , L_1
L_2 , F_5 ( V_4 ) ,
F_6 ( V_9 ) , V_2 -> V_13 , V_2 -> V_12 ) ;
F_7 ( V_4 ) ;
return - V_14 ;
}
V_11 = F_8 ( V_9 , F_3 ( V_2 -> V_12 , 0 ) ) ;
if ( V_11 == 0 ) {
F_4 ( V_6 , L_3 ) ;
return - V_15 ;
}
F_9 (dev, &parent->devices, bus_list) {
if ( F_10 ( V_4 -> V_16 ) != V_2 -> V_12 )
continue;
if ( ( V_4 -> V_17 == V_18 ) ||
( V_4 -> V_17 == V_19 ) )
F_11 ( V_4 ) ;
}
F_12 ( V_7 ) ;
F_9 (dev, &parent->devices, bus_list) {
if ( F_10 ( V_4 -> V_16 ) != V_2 -> V_12 )
continue;
F_13 ( V_4 ) ;
}
F_14 ( V_9 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
T_2 V_21 = 0 ;
struct V_8 * V_9 = V_2 -> V_6 -> V_3 -> V_10 ;
struct V_3 * V_4 , * V_22 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_16 ( V_6 , L_4 ,
V_23 , F_6 ( V_9 ) , V_2 -> V_13 , V_2 -> V_12 ) ;
F_17 (dev, temp, &parent->devices, bus_list) {
if ( F_10 ( V_4 -> V_16 ) != V_2 -> V_12 )
continue;
F_18 ( V_4 ) ;
if ( V_4 -> V_17 == V_18 ) {
F_19 ( V_4 , V_24 , & V_21 ) ;
if ( V_21 & V_25 ) {
F_4 ( V_6 ,
L_5 ,
F_5 ( V_4 ) ) ;
F_7 ( V_4 ) ;
V_20 = - V_14 ;
break;
}
}
F_20 ( V_4 ) ;
F_7 ( V_4 ) ;
}
return V_20 ;
}
