static int F_1 ( int V_1 , T_1 V_2 , int * V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
if ( ! V_1 )
return V_9 ;
if ( V_1 != 42 )
return - V_10 ;
V_5 = ( V_2 >> 0 ) & 0x1fff ;
V_6 = ( V_2 >> 13 ) & 0x1fff ;
V_7 = ( V_2 >> 26 ) & 0xff ;
V_8 = ( V_2 >> 34 ) & 0xff ;
if ( ( V_8 ^ V_7 ) != 0xff )
return - V_10 ;
if ( ( V_6 ^ V_5 ) != 0x1fff )
return - V_10 ;
* V_3 = V_5 << 8 | V_7 ;
return V_11 ;
}
static int F_2 ( const struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
unsigned int V_16 , V_17 ;
V_7 = V_13 -> V_7 & 0xff ;
V_17 = V_13 -> V_18 & 0xff ;
V_8 = V_7 ^ 0xff ;
if ( V_13 -> V_7 & 0xff700000 )
return - V_10 ;
V_5 = ( V_13 -> V_7 >> 8 ) & 0x1fff ;
V_16 = ( V_13 -> V_18 >> 8 ) & 0x1fff ;
V_6 = V_5 ^ 0x1fff ;
V_15 -> V_7 = ( T_1 ) V_8 << 34 |
( T_1 ) V_7 << 26 |
V_6 << 13 |
V_5 ;
V_15 -> V_18 = ( T_1 ) V_17 << 34 |
( T_1 ) V_17 << 26 |
V_16 << 13 |
V_16 ;
return 0 ;
}
