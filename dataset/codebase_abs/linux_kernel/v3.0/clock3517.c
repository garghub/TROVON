static void F_1 ( struct V_1 * V_1 ,
void T_1 * * V_2 ,
T_2 * V_3 ,
T_2 * V_4 )
{
* V_2 = ( V_5 void T_1 * ) ( V_1 -> V_6 ) ;
* V_3 = V_1 -> V_7 + V_8 ;
* V_4 = V_9 ;
}
static void F_2 ( struct V_1 * V_1 , void T_1 * * V_10 ,
T_2 * V_11 )
{
* V_10 = ( V_5 void T_1 * ) ( V_1 -> V_6 ) ;
if ( V_1 -> V_7 & V_12 )
* V_11 = V_1 -> V_7 + V_13 ;
else
* V_11 = V_1 -> V_7 - V_13 ;
}
static void F_3 ( struct V_1 * V_1 ,
void T_1 * * V_2 ,
T_2 * V_3 ,
T_2 * V_4 )
{
T_3 V_14 ;
V_14 = ( ( ( V_5 T_3 ) V_1 -> V_6 & ~ 0xf0 ) | 0x20 ) ;
* V_2 = ( V_5 void T_1 * ) V_14 ;
* V_3 = V_15 ;
* V_4 = V_16 ;
}
