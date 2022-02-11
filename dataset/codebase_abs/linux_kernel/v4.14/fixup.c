static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
T_1 V_6 ;
struct V_7 * V_8 ;
if ( ( strcmp ( V_9 , L_1 ) != 0 )
&& ( strcmp ( V_9 , L_2 ) != 0 ) )
return;
V_5 = V_2 -> V_5 ;
while ( V_5 ) {
V_3 = V_5 -> V_10 ;
if ( V_3 && ( F_2 ( V_3 ) ) ) {
F_3 ( V_3 , V_11 ,
& V_6 ) ;
if ( ! ( V_6 & V_12 ) )
return;
}
V_5 = V_5 -> V_13 ;
}
if ( ! F_4 () || V_2 == F_4 () ) {
F_3 ( V_2 , V_14 , & V_6 ) ;
if ( V_6 & ( V_15 | V_16 ) ) {
V_8 = & V_2 -> V_7 [ V_17 ] ;
F_5 ( V_2 ) ;
if ( V_8 -> V_13 )
F_6 ( V_8 ) ;
V_8 -> V_18 = 0xC0000 ;
V_8 -> V_19 = V_8 -> V_18 + 0x20000 - 1 ;
V_8 -> V_20 = V_21 | V_22 |
V_23 ;
F_7 ( & V_2 -> V_24 , L_3 ,
V_8 ) ;
}
}
}
