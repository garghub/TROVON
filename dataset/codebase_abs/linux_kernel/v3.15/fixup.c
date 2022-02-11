static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
T_1 V_6 ;
if ( ( strcmp ( V_7 , L_1 ) != 0 )
&& ( strcmp ( V_7 , L_2 ) != 0 ) )
return;
V_5 = V_2 -> V_5 ;
while ( V_5 ) {
V_3 = V_5 -> V_8 ;
if ( V_3
&& ( ( V_3 -> V_9 == V_10 )
|| ( V_3 -> V_9 == V_11 ) ) ) {
F_2 ( V_3 , V_12 ,
& V_6 ) ;
if ( ! ( V_6 & V_13 ) )
return;
}
V_5 = V_5 -> V_14 ;
}
if ( ! F_3 () || V_2 == F_3 () ) {
F_2 ( V_2 , V_15 , & V_6 ) ;
if ( V_6 & ( V_16 | V_17 ) ) {
V_2 -> V_18 [ V_19 ] . V_20 |= V_21 ;
F_4 ( V_22 , & V_2 -> V_23 , L_3 ) ;
F_5 ( V_2 ) ;
}
}
}
