void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( V_2 -> V_7 == V_8 ) {
F_2 ( V_9 , 1 , L_1 , V_4 -> V_10 ) ;
F_3 ( 50 ) ;
F_4 ( 0xda000000 , V_11 ) ;
V_6 = F_5 ( V_12 ) ;
V_6 |= V_13 ;
V_6 &= ~ V_14 ;
F_4 ( V_6 , V_12 ) ;
F_3 ( 500 ) ;
V_2 -> V_7 = V_15 ;
}
F_3 ( 100 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( V_2 -> V_7 == V_15 ) {
F_2 ( V_9 , 1 , L_2 , V_4 -> V_10 ) ;
F_3 ( 50 ) ;
F_4 ( 0x00da0000 , V_11 ) ;
V_6 = F_5 ( V_12 ) ;
V_6 |= V_14 ;
V_6 &= ~ V_13 ;
F_4 ( V_6 , V_12 ) ;
F_3 ( 500 ) ;
V_2 -> V_7 = V_8 ;
}
F_3 ( 100 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_16 , V_17 ;
F_4 ( F_5 ( V_18 ) | V_19 , V_18 ) ;
V_16 = F_5 ( V_20 ) ;
V_17 = F_5 ( V_12 ) ;
if ( V_16 & V_21 ) {
F_2 ( V_9 , 1 , L_3 , V_4 -> V_10 ) ;
F_4 ( V_17 | V_13 , V_12 ) ;
V_2 -> V_7 = V_15 ;
F_8 ( & V_2 -> V_22 ,
0 ,
V_23 ) ;
} else {
F_2 ( V_9 , 1 , L_4 , V_4 -> V_10 ) ;
F_4 ( V_17 | V_14 , V_12 ) ;
V_2 -> V_7 = V_8 ;
F_8 ( & V_2 -> V_22 ,
0 ,
V_24 ) ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( F_5 ( V_20 ) & ( ~ V_25 | ~ V_26 ) , V_20 ) ;
F_4 ( F_5 ( V_18 ) & ~ V_19 , V_18 ) ;
}
