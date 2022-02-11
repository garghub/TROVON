static void F_1 ( struct V_1 * V_2 ,
void T_1 * * V_3 ,
T_2 * V_4 ,
T_2 * V_5 )
{
* V_3 = ( V_6 void T_1 * ) ( V_2 -> V_7 ) ;
* V_4 = V_2 -> V_8 + V_9 ;
* V_5 = V_10 ;
}
static void F_2 ( struct V_1 * V_2 ,
void T_1 * * V_11 ,
T_2 * V_12 )
{
* V_11 = ( V_6 void T_1 * ) ( V_2 -> V_7 ) ;
if ( V_2 -> V_8 & V_13 )
* V_12 = V_2 -> V_8 + V_14 ;
else
* V_12 = V_2 -> V_8 - V_14 ;
}
static void F_3 ( struct V_1 * V_2 ,
void T_1 * * V_3 ,
T_2 * V_4 ,
T_2 * V_5 )
{
T_3 V_15 ;
V_15 = ( ( ( V_6 T_3 ) V_2 -> V_7 & ~ 0xf0 ) | 0x20 ) ;
* V_3 = ( V_6 void T_1 * ) V_15 ;
* V_4 = V_16 ;
* V_5 = V_17 ;
}
