void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = ( ( V_5 T_1 ) V_2 -> V_6 ^ ( V_7 ^ V_8 ) ) ;
V_3 = F_2 ( ( V_5 void V_9 * ) V_4 ) ;
V_3 |= ( 1 << V_2 -> V_10 ) ;
F_3 ( V_3 , ( V_5 void V_9 * ) V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = ( ( V_5 T_1 ) V_2 -> V_6 ^ ( V_7 ^ V_8 ) ) ;
V_3 = F_2 ( ( V_5 void V_9 * ) V_4 ) ;
V_3 &= ~ ( 1 << V_2 -> V_10 ) ;
F_3 ( V_3 , ( V_5 void V_9 * ) V_4 ) ;
}
