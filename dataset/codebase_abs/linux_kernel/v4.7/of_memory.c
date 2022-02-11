const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 = 0 ;
struct V_1 * V_7 ;
V_7 = F_2 ( V_5 , sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
goto V_9;
V_6 |= F_3 ( V_3 , L_1 , & V_7 -> V_10 ) ;
V_6 |= F_3 ( V_3 , L_2 , & V_7 -> V_11 ) ;
V_6 |= F_3 ( V_3 , L_3 , & V_7 -> V_12 ) ;
V_6 |= F_3 ( V_3 , L_4 , & V_7 -> V_13 ) ;
V_6 |= F_3 ( V_3 , L_5 , & V_7 -> V_14 ) ;
V_6 |= F_3 ( V_3 , L_6 , & V_7 -> V_15 ) ;
V_6 |= F_3 ( V_3 , L_7 , & V_7 -> V_16 ) ;
V_6 |= F_3 ( V_3 , L_8 , & V_7 -> V_17 ) ;
V_6 |= F_3 ( V_3 , L_9 , & V_7 -> V_18 ) ;
V_6 |= F_3 ( V_3 , L_10 , & V_7 -> V_19 ) ;
V_6 |= F_3 ( V_3 , L_11 , & V_7 -> V_20 ) ;
if ( V_6 ) {
F_4 ( V_5 , V_7 ) ;
goto V_9;
}
return V_7 ;
V_9:
F_5 ( V_5 , L_12 , V_21 ) ;
return & V_22 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
int V_6 ;
V_6 = F_3 ( V_3 , L_13 , & V_24 -> V_25 ) ;
V_6 |= F_3 ( V_3 , L_14 , & V_24 -> V_26 ) ;
V_6 |= F_3 ( V_3 , L_15 , & V_24 -> V_10 ) ;
V_6 |= F_3 ( V_3 , L_16 , & V_24 -> V_11 ) ;
V_6 |= F_3 ( V_3 , L_17 , & V_24 -> V_12 ) ;
V_6 |= F_3 ( V_3 , L_18 , & V_24 -> V_27 ) ;
V_6 |= F_3 ( V_3 , L_19 , & V_24 -> V_14 ) ;
V_6 |= F_3 ( V_3 , L_20 , & V_24 -> V_15 ) ;
V_6 |= F_3 ( V_3 , L_21 , & V_24 -> V_16 ) ;
V_6 |= F_3 ( V_3 , L_22 , & V_24 -> V_17 ) ;
V_6 |= F_3 ( V_3 , L_23 , & V_24 -> V_19 ) ;
V_6 |= F_3 ( V_3 , L_24 , & V_24 -> V_28 ) ;
V_6 |= F_3 ( V_3 , L_25 , & V_24 -> V_20 ) ;
V_6 |= F_3 ( V_3 , L_26 , & V_24 -> V_29 ) ;
V_6 |= F_3 ( V_3 , L_27 , & V_24 -> V_30 ) ;
V_6 |= F_3 ( V_3 , L_28 , & V_24 -> V_31 ) ;
V_6 |= F_3 ( V_3 , L_29 , & V_24 -> V_32 ) ;
V_6 |= F_3 ( V_3 , L_30 ,
& V_24 -> V_33 ) ;
return V_6 ;
}
const struct V_23 * F_7 ( struct V_2 * V_34 ,
struct V_4 * V_5 , T_1 V_35 , T_1 * V_36 )
{
struct V_23 * V_37 = NULL ;
T_1 V_38 = 0 , V_39 = 0 ;
struct V_2 * V_40 ;
char * V_41 = NULL ;
switch ( V_35 ) {
case V_42 :
case V_43 :
V_41 = L_31 ;
break;
default:
F_5 ( V_5 , L_32 , V_21 ) ;
}
F_8 (np_ddr, np_tim)
if ( F_9 ( V_40 , V_41 ) )
V_38 ++ ;
if ( V_38 )
V_37 = F_2 ( V_5 , sizeof( * V_37 ) * V_38 ,
V_8 ) ;
if ( ! V_37 )
goto V_44;
F_8 (np_ddr, np_tim) {
if ( F_9 ( V_40 , V_41 ) ) {
if ( F_6 ( V_40 , & V_37 [ V_39 ] ) ) {
F_4 ( V_5 , V_37 ) ;
goto V_44;
}
V_39 ++ ;
}
}
* V_36 = V_38 ;
return V_37 ;
V_44:
F_5 ( V_5 , L_33 , V_21 ) ;
* V_36 = F_10 ( V_45 ) ;
return V_45 ;
}
