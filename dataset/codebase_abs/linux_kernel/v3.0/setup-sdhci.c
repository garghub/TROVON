void F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
T_2 V_8 , V_9 ;
V_8 = F_2 ( V_3 + V_10 ) ;
V_8 &= V_11 ;
V_8 |= ( V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
if ( V_5 -> clock < 25 * 1000000 )
V_9 = ( V_17 |
V_18 |
V_19 |
V_20 ) ;
else
V_9 = ( V_19 | V_20 ) ;
F_3 ( V_8 , V_3 + V_10 ) ;
F_3 ( V_9 , V_3 + V_21 ) ;
}
