static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 , V_9 ;
if ( ! V_1 )
return V_10 ;
if ( V_1 != 42 )
return - V_11 ;
V_6 = ( V_2 >> 0 ) & 0x1fff ;
V_7 = ( V_2 >> 13 ) & 0x1fff ;
V_8 = ( V_2 >> 26 ) & 0xff ;
V_9 = ( V_2 >> 34 ) & 0xff ;
if ( ( V_9 ^ V_8 ) != 0xff )
return - V_11 ;
if ( ( V_7 ^ V_6 ) != 0x1fff )
return - V_11 ;
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = V_6 << 8 | V_8 ;
return V_15 ;
}
static int F_2 ( const struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 V_20 )
{
unsigned int V_6 , V_7 , V_8 , V_9 ;
unsigned int V_21 , V_22 ;
V_8 = V_17 -> V_8 & 0xff ;
V_22 = V_17 -> V_23 & 0xff ;
V_9 = V_8 ^ 0xff ;
if ( V_17 -> V_8 & 0xff700000 )
return - V_11 ;
V_6 = ( V_17 -> V_8 >> 8 ) & 0x1fff ;
V_21 = ( V_17 -> V_23 >> 8 ) & 0x1fff ;
V_7 = V_6 ^ 0x1fff ;
V_19 -> V_8 = ( T_1 ) V_9 << 34 |
( T_1 ) V_8 << 26 |
V_7 << 13 |
V_6 ;
V_19 -> V_23 = ( T_1 ) V_22 << 34 |
( T_1 ) V_22 << 26 |
V_21 << 13 |
V_21 ;
return 0 ;
}
