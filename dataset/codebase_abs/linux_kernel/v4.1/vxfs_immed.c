static void *
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
F_4 ( V_4 , V_6 -> V_7 . V_8 ) ;
return NULL ;
}
static int
F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_12 -> V_13 -> V_14 ) ;
T_1 V_15 = ( T_1 ) V_12 -> V_16 << V_17 ;
T_2 V_18 ;
V_18 = F_6 ( V_12 ) ;
memcpy ( V_18 , V_6 -> V_7 . V_8 + V_15 , V_19 ) ;
F_7 ( V_12 ) ;
F_8 ( V_12 ) ;
F_9 ( V_12 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
