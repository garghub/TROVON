static int F_1 ( int V_1 , T_1 V_2 , enum V_3 * V_4 ,
T_2 * V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 , V_9 , V_10 ;
if ( ! V_1 )
return V_11 ;
if ( V_1 != 42 )
return - V_12 ;
V_7 = ( V_2 >> 0 ) & 0x1fff ;
V_8 = ( V_2 >> 13 ) & 0x1fff ;
V_9 = ( V_2 >> 26 ) & 0xff ;
V_10 = ( V_2 >> 34 ) & 0xff ;
if ( ( V_10 ^ V_9 ) != 0xff )
return - V_12 ;
if ( ( V_8 ^ V_7 ) != 0x1fff )
return - V_12 ;
* V_4 = V_13 ;
* V_5 = V_7 << 8 | V_9 ;
return V_14 ;
}
static int F_2 ( const struct V_15 * V_16 ,
struct V_17 * V_18 , T_1 V_19 )
{
unsigned int V_7 , V_8 , V_9 , V_10 ;
unsigned int V_20 , V_21 ;
V_9 = V_16 -> V_9 & 0xff ;
V_21 = V_16 -> V_22 & 0xff ;
V_10 = V_9 ^ 0xff ;
if ( V_16 -> V_9 & 0xff700000 )
return - V_12 ;
V_7 = ( V_16 -> V_9 >> 8 ) & 0x1fff ;
V_20 = ( V_16 -> V_22 >> 8 ) & 0x1fff ;
V_8 = V_7 ^ 0x1fff ;
V_18 -> V_9 = ( T_1 ) V_10 << 34 |
( T_1 ) V_9 << 26 |
V_8 << 13 |
V_7 ;
V_18 -> V_22 = ( T_1 ) V_21 << 34 |
( T_1 ) V_21 << 26 |
V_20 << 13 |
V_20 ;
return 0 ;
}
