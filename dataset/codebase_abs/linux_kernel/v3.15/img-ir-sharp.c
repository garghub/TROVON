static int F_1 ( int V_1 , T_1 V_2 , int * V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 , exp , V_7 ;
if ( V_1 != 15 )
return - V_8 ;
V_5 = ( V_2 >> 0 ) & 0x1f ;
V_6 = ( V_2 >> 5 ) & 0xff ;
exp = ( V_2 >> 13 ) & 0x1 ;
V_7 = ( V_2 >> 14 ) & 0x1 ;
if ( ! exp )
return - V_8 ;
if ( V_7 )
return - V_8 ;
* V_3 = V_5 << 8 | V_6 ;
return V_9 ;
}
static int F_2 ( const struct V_10 * V_11 ,
struct V_12 * V_13 , T_1 V_4 )
{
unsigned int V_5 , V_6 , exp = 0 , V_7 = 0 ;
unsigned int V_14 , V_15 , V_16 = 0 , V_17 = 0 ;
V_5 = ( V_11 -> V_18 >> 8 ) & 0x1f ;
V_14 = ( V_11 -> V_19 >> 8 ) & 0x1f ;
V_6 = ( V_11 -> V_18 >> 0 ) & 0xff ;
V_15 = ( V_11 -> V_19 >> 0 ) & 0xff ;
if ( V_15 ) {
exp = 1 ;
V_16 = 1 ;
V_7 = 0 ;
V_17 = 1 ;
}
V_13 -> V_18 = V_5 |
V_6 << 5 |
exp << 13 |
V_7 << 14 ;
V_13 -> V_19 = V_14 |
V_15 << 5 |
V_16 << 13 |
V_17 << 14 ;
return 0 ;
}
