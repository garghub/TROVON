static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 ;
if ( ! ( V_2 -> V_10 & V_11 ) || ! V_4 -> V_12 )
return 0 ;
V_9 = V_4 -> V_12 -> V_9 ;
if ( V_6 -> V_13 == V_14 ) {
F_2 ( V_9 , V_15 , V_16 , 1 ) ;
F_3 ( V_9 ) ;
F_2 ( V_9 , V_15 , V_16 , 0 ) ;
F_3 ( V_9 ) ;
return 1 ;
}
return 0 ;
}
