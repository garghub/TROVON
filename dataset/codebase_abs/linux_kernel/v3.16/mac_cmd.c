static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 ,
T_1 V_11 )
{
struct V_12 * V_13 = V_12 ( V_2 ) ;
int V_14 = 0 ;
F_2 ( V_4 -> V_15 != V_16 ) ;
F_3 ( V_2 , V_4 -> V_17 ) ;
F_4 ( V_2 , V_4 -> V_18 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 , V_6 , V_5 ) ;
if ( V_13 -> V_19 ) {
struct V_20 V_21 ;
int V_22 = 0 ;
V_21 . V_23 = V_4 -> V_18 ;
V_22 |= V_24 ;
V_21 . V_17 = V_4 -> V_17 ;
V_22 |= V_25 ;
V_21 . V_26 = F_7 ( V_2 -> V_27 ) ;
V_22 |= V_28 ;
V_21 . V_29 = V_21 . V_26 ;
V_22 |= V_30 ;
V_14 = V_13 -> V_19 -> V_31 ( V_2 , & V_21 , V_22 ) ;
}
F_8 ( V_2 , V_32 ) ;
return V_14 ;
}
static struct V_33 * F_9 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
F_2 ( V_2 -> type != V_36 ) ;
return F_11 ( F_12 ( & V_35 -> V_37 -> V_38 -> V_2 ) ) ;
}
