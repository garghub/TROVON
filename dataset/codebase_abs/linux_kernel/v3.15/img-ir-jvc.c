static int F_1 ( int V_1 , T_1 V_2 , int * V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 ;
if ( V_1 != 16 )
return - V_7 ;
V_5 = ( V_2 >> 0 ) & 0xff ;
V_6 = ( V_2 >> 8 ) & 0xff ;
* V_3 = V_5 << 8 | V_6 ;
return V_8 ;
}
static int F_2 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , T_1 V_4 )
{
unsigned int V_5 , V_6 ;
unsigned int V_13 , V_14 ;
V_5 = ( V_10 -> V_6 >> 8 ) & 0xff ;
V_13 = ( V_10 -> V_15 >> 8 ) & 0xff ;
V_6 = ( V_10 -> V_6 >> 0 ) & 0xff ;
V_14 = ( V_10 -> V_15 >> 0 ) & 0xff ;
V_12 -> V_6 = V_5 | V_6 << 8 ;
V_12 -> V_15 = V_13 | V_14 << 8 ;
return 0 ;
}
