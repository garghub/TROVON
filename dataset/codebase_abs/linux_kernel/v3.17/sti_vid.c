static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_10 , V_11 , V_12 , V_13 ;
V_10 = F_5 ( * V_9 , V_2 -> V_14 ) ;
V_12 = F_5 ( * V_9 , V_2 -> V_14 + V_2 -> V_15 - 1 ) ;
V_11 = F_6 ( * V_9 , V_2 -> V_16 ) ;
V_13 = F_6 ( * V_9 , V_2 -> V_16 + V_2 -> V_17 - 1 ) ;
F_3 ( ( V_10 << 16 ) | V_11 , V_2 -> V_5 + V_18 ) ;
F_3 ( ( V_12 << 16 ) | V_13 , V_2 -> V_5 + V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 |= V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
return 0 ;
}
static const T_2 * F_8 ( struct V_1 * V_20 )
{
return NULL ;
}
static unsigned int F_9 ( struct V_1 * V_20 )
{
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_3 ( V_21 | V_7 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_22 , V_2 -> V_5 + V_23 ) ;
F_3 ( V_24 , V_2 -> V_5 + V_25 ) ;
F_3 ( V_26 , V_2 -> V_5 + V_27 ) ;
F_3 ( V_28 , V_2 -> V_5 + V_29 ) ;
F_3 ( V_30 , V_2 -> V_5 + V_31 ) ;
F_3 ( V_32 , V_2 -> V_5 + V_33 ) ;
F_3 ( V_34 , V_2 -> V_5 + V_35 ) ;
F_3 ( V_36 , V_2 -> V_5 + V_37 ) ;
}
struct V_1 * F_11 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_39 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 ) {
F_13 ( L_1 ) ;
return NULL ;
}
V_2 -> V_41 = & V_42 ;
return V_2 ;
}
