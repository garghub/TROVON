static void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 = F_2 ( V_4 , 0x40 ) ;
T_1 V_9 = F_3 ( V_8 / V_2 -> V_10 -> V_11 , 0x40 ) ;
if ( ! F_4 ( & V_2 -> V_10 -> V_9 , 0 , 1 , V_9 , V_9 , 1 , & V_7 -> V_12 ) ) {
if ( V_5 & 2 ) V_7 -> V_13 |= 0x10000000 ;
else V_7 -> V_13 |= 0x20000000 ;
V_7 -> V_13 |= ( ( V_7 -> V_12 -> V_14 ) >> 6 ) ;
V_7 -> V_13 |= ( ( V_7 -> V_12 -> V_14 + V_9 - 1 ) >> 6 ) << 14 ;
#ifdef F_5
V_7 -> V_13 |= 0x80000000 ;
#endif
}
}
int
F_6 ( struct V_15 * V_16 , int V_17 , struct V_1 * * V_18 )
{
return F_7 ( & V_19 , V_16 , V_17 , V_18 ) ;
}
