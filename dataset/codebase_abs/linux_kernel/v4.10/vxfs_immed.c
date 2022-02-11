static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 -> V_7 -> V_8 ) ;
T_1 V_9 = ( T_1 ) V_4 -> V_10 << V_11 ;
T_2 V_12 ;
V_12 = F_3 ( V_4 ) ;
memcpy ( V_12 , V_6 -> V_13 . V_14 + V_9 , V_15 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
