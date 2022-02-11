void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( V_5 -> V_7 & 0xFFFF , V_8 ) ;
V_6 = V_5 -> V_9 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_10 & 0xFFF ;
F_2 ( V_6 , V_11 ) ;
V_6 = V_5 -> V_12 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_13 & 0xFFF ;
F_2 ( V_6 , V_14 ) ;
F_2 ( V_5 -> V_15 -> V_16 , V_17 ) ;
}
void F_4 ( struct V_1 * V_2 , T_2 V_18 )
{
F_2 ( V_18 , V_19 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( V_5 -> V_7 & 0xFFFF , V_20 ) ;
V_6 = V_5 -> V_9 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_10 & 0xFFF ;
F_2 ( V_6 , V_21 ) ;
V_6 = V_5 -> V_12 & 0xFFF ;
V_6 <<= 16 ;
V_6 |= V_5 -> V_13 & 0xFFF ;
F_2 ( V_6 , V_22 ) ;
F_2 ( V_5 -> V_15 -> V_16 , V_23 ) ;
}
void F_6 ( struct V_1 * V_2 , T_2 V_18 )
{
F_2 ( V_18 , V_24 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_25 )
{
F_2 ( V_25 , V_26 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_25 )
{
F_2 ( V_25 , V_27 ) ;
}
T_1 F_9 ( T_1 V_28 )
{
V_28 &= 1 ;
return V_28 << 4 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_29 )
{
F_2 ( V_29 , V_30 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_2 ( 0x7 , V_31 ) ;
F_2 ( 1 , V_32 ) ;
F_2 ( 1 , V_33 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_34 ) ;
}
