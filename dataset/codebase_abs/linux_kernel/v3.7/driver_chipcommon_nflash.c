int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
if ( V_4 -> V_6 . V_7 != V_8 &&
V_2 -> V_5 -> V_7 . V_9 != 0x38 ) {
F_2 ( V_4 , L_1 ) ;
return - V_10 ;
}
if ( ! ( V_2 -> V_11 & V_12 ) ) {
F_2 ( V_4 , L_2 ) ;
return - V_13 ;
}
V_2 -> V_14 . V_15 = true ;
V_16 . V_17 . V_18 = & V_2 -> V_14 ;
return 0 ;
}
