static int F_1 ( int V_1 , T_1 V_2 , enum V_3 * V_4 ,
T_2 * V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 , exp , V_9 ;
if ( V_1 != 15 )
return - V_10 ;
V_7 = ( V_2 >> 0 ) & 0x1f ;
V_8 = ( V_2 >> 5 ) & 0xff ;
exp = ( V_2 >> 13 ) & 0x1 ;
V_9 = ( V_2 >> 14 ) & 0x1 ;
if ( ! exp )
return - V_10 ;
if ( V_9 )
return - V_10 ;
* V_4 = V_11 ;
* V_5 = V_7 << 8 | V_8 ;
return V_12 ;
}
static int F_2 ( const struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_17 )
{
unsigned int V_7 , V_8 , exp = 0 , V_9 = 0 ;
unsigned int V_18 , V_19 , V_20 = 0 , V_21 = 0 ;
V_7 = ( V_14 -> V_22 >> 8 ) & 0x1f ;
V_18 = ( V_14 -> V_23 >> 8 ) & 0x1f ;
V_8 = ( V_14 -> V_22 >> 0 ) & 0xff ;
V_19 = ( V_14 -> V_23 >> 0 ) & 0xff ;
if ( V_19 ) {
exp = 1 ;
V_20 = 1 ;
V_9 = 0 ;
V_21 = 1 ;
}
V_16 -> V_22 = V_7 |
V_8 << 5 |
exp << 13 |
V_9 << 14 ;
V_16 -> V_23 = V_18 |
V_19 << 5 |
V_20 << 13 |
V_21 << 14 ;
return 0 ;
}
