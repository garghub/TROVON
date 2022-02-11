void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 || V_2 -> V_6 ) {
T_1 V_7 ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_7 = 1 ;
break;
default:
V_7 = 2 ;
break;
}
F_2 ( V_10 , L_1 ,
V_2 -> V_8 , V_7 ) ;
V_4 -> V_11 -> V_12 -> V_13 ( V_4 , V_7 , 0 , 0 ) ;
}
}
