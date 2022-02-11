static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 ;
if ( V_1 != 16 )
return - V_8 ;
V_6 = ( V_2 >> 0 ) & 0xff ;
V_7 = ( V_2 >> 8 ) & 0xff ;
V_5 -> V_9 = V_10 ;
V_5 -> V_11 = V_6 << 8 | V_7 ;
return V_12 ;
}
static int F_2 ( const struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_17 )
{
unsigned int V_6 , V_7 ;
unsigned int V_18 , V_19 ;
V_6 = ( V_14 -> V_7 >> 8 ) & 0xff ;
V_18 = ( V_14 -> V_20 >> 8 ) & 0xff ;
V_7 = ( V_14 -> V_7 >> 0 ) & 0xff ;
V_19 = ( V_14 -> V_20 >> 0 ) & 0xff ;
V_16 -> V_7 = V_6 | V_7 << 8 ;
V_16 -> V_20 = V_18 | V_19 << 8 ;
return 0 ;
}
