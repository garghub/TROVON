void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
if ( ! ( V_7 & 4 ) ) V_9 -> V_4 = ( 0 << 3 ) ;
else V_9 -> V_4 = ( 1 << 3 ) ;
V_9 -> V_4 |= 0x00000001 ;
V_9 -> V_4 |= V_4 ;
V_9 -> V_10 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
int
F_3 ( struct V_11 * V_12 , int V_13 , struct V_1 * * V_14 )
{
return F_4 ( & V_15 , V_12 , V_13 , V_14 ) ;
}
