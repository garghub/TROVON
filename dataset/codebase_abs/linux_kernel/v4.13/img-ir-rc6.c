static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 , V_9 , V_10 ;
V_2 >>= 27 ;
V_9 = ( V_2 >> 17 ) & 0x01 ;
V_10 = ( V_2 >> 16 ) & 0x01 ;
V_8 = ( V_2 >> 18 ) & 0x07 ;
V_6 = ( V_2 >> 8 ) & 0xff ;
V_7 = V_2 & 0xff ;
if ( V_9 == V_10 )
return - V_11 ;
if ( V_8 )
return - V_11 ;
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = V_6 << 8 | V_7 ;
V_5 -> V_15 = V_10 ;
return V_16 ;
}
static int F_2 ( const struct V_17 * V_18 ,
struct V_19 * V_20 , T_1 V_21 )
{
return - V_11 ;
}
