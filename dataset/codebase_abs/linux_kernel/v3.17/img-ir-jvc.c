static int F_1 ( int V_1 , T_1 V_2 , enum V_3 * V_4 ,
T_2 * V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 ;
if ( V_1 != 16 )
return - V_9 ;
V_7 = ( V_2 >> 0 ) & 0xff ;
V_8 = ( V_2 >> 8 ) & 0xff ;
* V_4 = V_10 ;
* V_5 = V_7 << 8 | V_8 ;
return V_11 ;
}
static int F_2 ( const struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
unsigned int V_7 , V_8 ;
unsigned int V_17 , V_18 ;
V_7 = ( V_13 -> V_8 >> 8 ) & 0xff ;
V_17 = ( V_13 -> V_19 >> 8 ) & 0xff ;
V_8 = ( V_13 -> V_8 >> 0 ) & 0xff ;
V_18 = ( V_13 -> V_19 >> 0 ) & 0xff ;
V_15 -> V_8 = V_7 | V_8 << 8 ;
V_15 -> V_19 = V_17 | V_18 << 8 ;
return 0 ;
}
