static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 ,
T_1 V_11 )
{
F_2 ( V_4 -> V_12 != V_13 ) ;
F_3 ( V_2 , V_4 -> V_14 ) ;
F_4 ( V_2 , V_4 -> V_15 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 , V_6 , V_5 ) ;
F_7 ( V_2 , V_16 ) ;
return 0 ;
}
static struct V_17 * F_8 ( const struct V_1 * V_2 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
F_2 ( V_2 -> type != V_20 ) ;
return F_10 ( F_11 ( & V_19 -> V_21 -> V_22 -> V_2 ) ) ;
}
