static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , exp , V_8 ;
if ( V_1 != 15 )
return - V_9 ;
V_6 = ( V_2 >> 0 ) & 0x1f ;
V_7 = ( V_2 >> 5 ) & 0xff ;
exp = ( V_2 >> 13 ) & 0x1 ;
V_8 = ( V_2 >> 14 ) & 0x1 ;
if ( ! exp )
return - V_9 ;
if ( V_8 )
return - V_9 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = V_6 << 8 | V_7 ;
return V_13 ;
}
static int F_2 ( const struct V_14 * V_15 ,
struct V_16 * V_17 , T_1 V_18 )
{
unsigned int V_6 , V_7 , exp = 0 , V_8 = 0 ;
unsigned int V_19 , V_20 , V_21 = 0 , V_22 = 0 ;
V_6 = ( V_15 -> V_23 >> 8 ) & 0x1f ;
V_19 = ( V_15 -> V_24 >> 8 ) & 0x1f ;
V_7 = ( V_15 -> V_23 >> 0 ) & 0xff ;
V_20 = ( V_15 -> V_24 >> 0 ) & 0xff ;
if ( V_20 ) {
exp = 1 ;
V_21 = 1 ;
V_8 = 0 ;
V_22 = 1 ;
}
V_17 -> V_23 = V_6 |
V_7 << 5 |
exp << 13 |
V_8 << 14 ;
V_17 -> V_24 = V_19 |
V_20 << 5 |
V_21 << 13 |
V_22 << 14 ;
return 0 ;
}
