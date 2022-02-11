static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
switch ( V_6 -> V_8 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
if ( V_7 < - 1 ) {
F_2 ( V_4 -> V_13 -> V_14 , V_6 -> type ,
V_6 -> V_8 , - 1 ) ;
return 1 ;
}
break;
}
return 0 ;
}
