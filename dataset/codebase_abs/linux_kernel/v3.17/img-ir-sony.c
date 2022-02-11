static int F_1 ( int V_1 , T_1 V_2 , enum V_3 * V_4 ,
T_2 * V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 , V_9 ;
switch ( V_1 ) {
case 12 :
if ( ! ( V_6 & V_10 ) )
return - V_11 ;
V_9 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_7 = V_2 & 0x1f ;
V_8 = 0 ;
* V_4 = V_12 ;
break;
case 15 :
if ( ! ( V_6 & V_13 ) )
return - V_11 ;
V_9 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_7 = V_2 & 0xff ;
V_8 = 0 ;
* V_4 = V_14 ;
break;
case 20 :
if ( ! ( V_6 & V_15 ) )
return - V_11 ;
V_9 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_7 = V_2 & 0x1f ;
V_2 >>= 5 ;
V_8 = V_2 & 0xff ;
* V_4 = V_16 ;
break;
default:
return - V_11 ;
}
* V_5 = V_7 << 16 | V_8 << 8 | V_9 ;
return V_17 ;
}
static int F_2 ( const struct V_18 * V_19 ,
struct V_20 * V_21 , T_1 V_22 )
{
unsigned int V_7 , V_8 , V_9 ;
unsigned int V_23 , V_24 , V_25 ;
unsigned int V_1 = 0 ;
V_7 = ( V_19 -> V_26 >> 16 ) & 0xff ;
V_23 = ( V_19 -> V_27 >> 16 ) & 0xff ;
V_8 = ( V_19 -> V_26 >> 8 ) & 0xff ;
V_24 = ( V_19 -> V_27 >> 8 ) & 0xff ;
V_9 = ( V_19 -> V_26 >> 0 ) & 0x7f ;
V_25 = ( V_19 -> V_27 >> 0 ) & 0x7f ;
if ( V_8 & V_24 ) {
if ( V_7 & V_23 & 0xe0 )
return - V_11 ;
if ( ! ( V_22 & V_15 ) )
return - V_11 ;
V_1 = 20 ;
V_23 &= 0x1f ;
} else if ( V_7 & V_23 & 0xe0 ) {
if ( ! ( V_22 & V_13 ) )
return - V_11 ;
V_1 = 15 ;
V_24 = 0 ;
} else {
V_24 &= ( V_23 >> 5 ) | 0xf8 ;
V_23 &= 0x1f ;
}
V_7 &= V_23 ;
V_8 &= V_24 ;
V_21 -> V_26 = V_9 |
V_7 << 7 |
V_8 << 15 ;
V_21 -> V_27 = V_25 |
V_23 << 7 |
V_24 << 15 ;
if ( V_1 ) {
V_21 -> V_28 = V_1 ;
V_21 -> V_29 = V_1 ;
}
return 0 ;
}
