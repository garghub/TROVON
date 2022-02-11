void T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = ( F_2 ( V_4 ) & V_5 ) >> V_6 ;
V_2 -> V_7 = ( F_2 ( V_4 ) & V_8 ) >> V_9 ;
switch ( V_2 -> V_3 ) {
case V_10 :
V_2 -> V_11 = V_12 ;
V_2 -> type = V_13 ;
break;
default:
F_3 () ;
break;
}
}
