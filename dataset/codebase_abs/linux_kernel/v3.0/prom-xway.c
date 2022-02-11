void T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = ( F_2 ( V_4 ) & V_5 ) >> V_6 ;
V_2 -> V_7 = ( F_2 ( V_4 ) & V_8 ) >> V_9 ;
switch ( V_2 -> V_3 ) {
case V_10 :
case V_11 :
V_2 -> V_12 = V_13 ;
V_2 -> type = V_14 ;
break;
case V_15 :
V_2 -> V_12 = V_16 ;
V_2 -> type = V_14 ;
break;
case V_17 :
case V_18 :
case V_19 :
V_2 -> V_12 = V_20 ;
V_2 -> type = V_21 ;
break;
default:
F_3 () ;
break;
}
}
