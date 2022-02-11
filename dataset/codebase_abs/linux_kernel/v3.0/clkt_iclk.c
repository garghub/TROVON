void F_1 ( struct V_1 * V_1 )
{
T_1 V_2 , V_3 ;
V_3 = ( ( V_4 T_1 ) V_1 -> V_5 ^ ( V_6 ^ V_7 ) ) ;
V_2 = F_2 ( ( V_4 void V_8 * ) V_3 ) ;
V_2 |= ( 1 << V_1 -> V_9 ) ;
F_3 ( V_2 , ( V_4 void V_8 * ) V_3 ) ;
}
void F_4 ( struct V_1 * V_1 )
{
T_1 V_2 , V_3 ;
V_3 = ( ( V_4 T_1 ) V_1 -> V_5 ^ ( V_6 ^ V_7 ) ) ;
V_2 = F_2 ( ( V_4 void V_8 * ) V_3 ) ;
V_2 &= ~ ( 1 << V_1 -> V_9 ) ;
F_3 ( V_2 , ( V_4 void V_8 * ) V_3 ) ;
}
