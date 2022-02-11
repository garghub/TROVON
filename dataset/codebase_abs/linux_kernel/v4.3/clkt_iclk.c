void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
void T_2 * V_4 ;
V_4 = ( V_5 void T_2 * )
( ( V_5 T_1 ) V_2 -> V_6 ^ ( V_7 ^ V_8 ) ) ;
V_3 = V_9 -> V_10 ( V_4 ) ;
V_3 |= ( 1 << V_2 -> V_11 ) ;
V_9 -> V_12 ( V_3 , V_4 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
void T_2 * V_4 ;
V_4 = ( V_5 void T_2 * )
( ( V_5 T_1 ) V_2 -> V_6 ^ ( V_7 ^ V_8 ) ) ;
V_3 = V_9 -> V_10 ( V_4 ) ;
V_3 &= ~ ( 1 << V_2 -> V_11 ) ;
V_9 -> V_12 ( V_3 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
void T_2 * * V_13 ,
T_3 * V_14 ,
T_3 * V_15 )
{
T_1 V_4 ;
V_4 = ( ( V_5 T_1 ) V_2 -> V_6 ^ ( V_16 ^ V_17 ) ) ;
* V_13 = ( V_5 void T_2 * ) V_4 ;
* V_14 = V_2 -> V_11 ;
* V_15 = V_18 ;
}
