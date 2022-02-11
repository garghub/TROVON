static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_6 L_1 , F_3 ( V_2 ) ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
V_2 -> V_9 [ 1 ] . V_10 = V_4 -> V_11 [ 0 ] . V_10 + 0x100 ;
V_2 -> V_9 [ 1 ] . V_12 = V_2 -> V_9 [ 1 ] . V_10 + 0x200 - 1 ;
V_2 -> V_9 [ 1 ] . V_13 |= V_14 ;
F_4 ( ! F_5 ( & V_2 -> V_2 ,
V_15 ,
V_15 ,
V_16 ,
V_17 |
V_18 ) ) ;
break;
default:
F_2 ( L_2 ) ;
}
}
int T_1 F_6 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 )
{
return V_21 ;
}
