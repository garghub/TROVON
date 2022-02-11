void T_1 F_1 ( void )
{
V_1 = (struct V_2 * )
F_2 ( V_3 , sizeof( struct V_2 ) ) ;
V_4 = (struct V_2 * )
F_2 ( V_5 , sizeof( struct V_2 ) ) ;
V_6 = (struct V_7 * ) V_1 -> V_8 [ 6 ] ;
V_1 -> V_9 [ 6 ] [ 0 ] |= V_10 ;
if ( F_3 () ) {
V_11 = (struct V_12 * ) V_1 -> V_8 [ 4 ] ;
V_13 = L_1 ;
} else {
V_11 = & V_6 -> V_14 ;
V_13 = L_2 ;
}
V_15 = ( V_16 | V_17 |
V_18 | V_19 |
V_20 ) ;
V_21 = ( V_22 | V_23 |
V_24 | V_25 |
V_26 | V_27 ) ;
V_6 -> V_28 = V_15 ;
V_6 -> V_29 = V_21 ;
}
