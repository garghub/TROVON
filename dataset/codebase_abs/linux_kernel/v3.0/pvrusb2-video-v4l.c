void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 || V_2 -> V_6 ) {
const struct V_7 * V_8 ;
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
T_1 V_12 ;
F_2 ( V_13 , L_1 ,
V_2 -> V_14 ) ;
V_8 = ( V_9 < F_3 ( V_15 ) ) ?
V_15 [ V_9 ] : NULL ;
if ( ( V_8 == NULL ) ||
( V_2 -> V_14 < 0 ) ||
( V_2 -> V_14 >= V_8 -> V_16 ) ) {
F_2 ( V_17 ,
L_2
L_3
L_4 ,
V_9 , V_2 -> V_14 ) ;
return;
}
V_12 = V_8 -> V_18 [ V_2 -> V_14 ] ;
V_4 -> V_19 -> V_20 -> V_21 ( V_4 , V_12 , 0 , 0 ) ;
}
}
