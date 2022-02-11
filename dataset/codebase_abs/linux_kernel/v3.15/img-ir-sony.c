static int F_1 ( int V_1 , T_1 V_2 , int * V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
switch ( V_1 ) {
case 12 :
if ( ! ( V_4 & V_8 ) )
return - V_9 ;
V_7 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_5 = V_2 & 0x1f ;
V_6 = 0 ;
break;
case 15 :
if ( ! ( V_4 & V_10 ) )
return - V_9 ;
V_7 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_5 = V_2 & 0xff ;
V_6 = 0 ;
break;
case 20 :
if ( ! ( V_4 & V_11 ) )
return - V_9 ;
V_7 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_5 = V_2 & 0x1f ;
V_2 >>= 5 ;
V_6 = V_2 & 0xff ;
break;
default:
return - V_9 ;
}
* V_3 = V_5 << 16 | V_6 << 8 | V_7 ;
return V_12 ;
}
static int F_2 ( const struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
unsigned int V_17 , V_18 , V_19 ;
unsigned int V_1 = 0 ;
V_5 = ( V_14 -> V_20 >> 16 ) & 0xff ;
V_17 = ( V_14 -> V_21 >> 16 ) & 0xff ;
V_6 = ( V_14 -> V_20 >> 8 ) & 0xff ;
V_18 = ( V_14 -> V_21 >> 8 ) & 0xff ;
V_7 = ( V_14 -> V_20 >> 0 ) & 0x7f ;
V_19 = ( V_14 -> V_21 >> 0 ) & 0x7f ;
if ( V_6 & V_18 ) {
if ( V_5 & V_17 & 0xe0 )
return - V_9 ;
if ( ! ( V_4 & V_11 ) )
return - V_9 ;
V_1 = 20 ;
V_17 &= 0x1f ;
} else if ( V_5 & V_17 & 0xe0 ) {
if ( ! ( V_4 & V_10 ) )
return - V_9 ;
V_1 = 15 ;
V_18 = 0 ;
} else {
V_18 &= ( V_17 >> 5 ) | 0xf8 ;
V_17 &= 0x1f ;
}
V_5 &= V_17 ;
V_6 &= V_18 ;
V_16 -> V_20 = V_7 |
V_5 << 7 |
V_6 << 15 ;
V_16 -> V_21 = V_19 |
V_17 << 7 |
V_18 << 15 ;
if ( V_1 ) {
V_16 -> V_22 = V_1 ;
V_16 -> V_23 = V_1 ;
}
return 0 ;
}
