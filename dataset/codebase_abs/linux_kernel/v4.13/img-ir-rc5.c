static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 , V_9 ;
V_2 >>= 2 ;
V_9 = ( V_2 >> 13 ) & 0x01 ;
V_8 = ( V_2 >> 11 ) & 0x01 ;
V_6 = ( V_2 >> 6 ) & 0x1f ;
V_7 = V_2 & 0x3f ;
V_7 += ( ( V_2 >> 12 ) & 0x01 ) ? 0 : 0x40 ;
if ( ! V_9 )
return - V_10 ;
V_5 -> V_11 = V_12 ;
V_5 -> V_13 = V_6 << 8 | V_7 ;
V_5 -> V_14 = V_8 ;
return V_15 ;
}
static int F_2 ( const struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 V_20 )
{
return - V_10 ;
}
