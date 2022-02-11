static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
T_2 V_6 ;
if ( ( strcmp ( V_7 , L_1 ) != 0 )
&& ( strcmp ( V_7 , L_2 ) != 0 ) )
return;
if ( ( V_2 -> V_8 >> 8 ) != V_9 )
return;
V_5 = V_2 -> V_5 ;
while ( V_5 ) {
V_3 = V_5 -> V_10 ;
if ( V_3
&& ( ( V_3 -> V_11 == V_12 )
|| ( V_3 -> V_11 == V_13 ) ) ) {
F_2 ( V_3 , V_14 ,
& V_6 ) ;
if ( ! ( V_6 & V_15 ) )
return;
}
V_5 = V_5 -> V_16 ;
}
F_2 ( V_2 , V_17 , & V_6 ) ;
if ( V_6 & ( V_18 | V_19 ) ) {
V_2 -> V_20 [ V_21 ] . V_22 |= V_23 ;
F_3 ( V_24 , & V_2 -> V_25 , L_3 ) ;
}
}
