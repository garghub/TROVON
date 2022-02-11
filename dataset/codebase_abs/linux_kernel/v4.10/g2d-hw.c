void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( 0 , V_7 ) ;
F_2 ( V_5 -> V_8 & 0xFFFF , V_9 ) ;
V_6 = V_5 -> V_10 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_11 & 0xFFF ;
F_2 ( V_6 , V_12 ) ;
V_6 = V_5 -> V_13 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_14 & 0xFFF ;
F_2 ( V_6 , V_15 ) ;
F_2 ( V_5 -> V_16 -> V_17 , V_18 ) ;
}
void F_4 ( struct V_1 * V_2 , T_2 V_19 )
{
F_2 ( V_19 , V_20 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( 0 , V_21 ) ;
F_2 ( V_5 -> V_8 & 0xFFFF , V_22 ) ;
V_6 = V_5 -> V_10 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_11 & 0xFFF ;
F_2 ( V_6 , V_23 ) ;
V_6 = V_5 -> V_13 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_14 & 0xFFF ;
F_2 ( V_6 , V_24 ) ;
F_2 ( V_5 -> V_16 -> V_17 , V_25 ) ;
}
void F_6 ( struct V_1 * V_2 , T_2 V_19 )
{
F_2 ( V_19 , V_26 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_27 )
{
F_2 ( V_27 , V_28 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_27 )
{
F_2 ( V_27 , V_29 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_4 * V_30 ,
struct V_4 * V_31 )
{
F_2 ( V_32 , V_33 ) ;
F_2 ( ( V_30 -> V_34 << 16 ) / V_31 -> V_34 , V_35 ) ;
F_2 ( ( V_30 -> V_36 << 16 ) / V_31 -> V_36 , V_37 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_38 )
{
F_2 ( V_38 , V_39 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 -> V_41 == V_42 )
F_2 ( 0x7 , V_43 ) ;
F_2 ( 1 , V_44 ) ;
F_2 ( 1 , V_45 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_46 ) ;
}
