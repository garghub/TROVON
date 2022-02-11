void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 , L_1 ) ;
if ( V_2 -> V_6 || V_2 -> V_7 ) {
enum V_8 V_9 ;
enum V_10 V_11 ;
const struct V_12 * V_13 ;
unsigned int V_14 = V_2 -> V_15 -> V_16 ;
V_13 = ( V_14 < F_3 ( V_17 ) ) ?
V_17 [ V_14 ] : NULL ;
if ( ( V_13 == NULL ) ||
( V_2 -> V_18 < 0 ) ||
( V_2 -> V_18 >= V_13 -> V_19 ) ) {
F_2 ( V_20 ,
L_2
L_3
L_4 ,
V_14 , V_2 -> V_18 ) ;
return;
}
V_9 = V_13 -> V_21 [ V_2 -> V_18 ] . V_22 ;
V_11 = V_13 -> V_21 [ V_2 -> V_18 ] . V_23 ;
F_2 ( V_5 ,
L_5 ,
V_9 , V_11 ) ;
V_4 -> V_24 -> V_25 -> V_26 ( V_4 , ( V_27 ) V_9 , 0 , 0 ) ;
V_4 -> V_24 -> V_28 -> V_26 ( V_4 , ( V_27 ) V_11 , 0 , 0 ) ;
}
}
