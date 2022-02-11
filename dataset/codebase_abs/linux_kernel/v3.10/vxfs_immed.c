static void *
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_4 , V_6 -> V_8 . V_9 ) ;
return NULL ;
}
static int
F_4 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_13 -> V_14 -> V_15 ) ;
T_1 V_16 = ( T_1 ) V_13 -> V_17 << V_18 ;
T_2 V_19 ;
V_19 = F_5 ( V_13 ) ;
memcpy ( V_19 , V_6 -> V_8 . V_9 + V_16 , V_20 ) ;
F_6 ( V_13 ) ;
F_7 ( V_13 ) ;
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
return 0 ;
}
