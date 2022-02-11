static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 ;
switch ( V_1 ) {
case 12 :
if ( ! ( V_3 & V_9 ) )
return - V_10 ;
V_8 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_6 = V_2 & 0x1f ;
V_7 = 0 ;
V_5 -> V_11 = V_12 ;
break;
case 15 :
if ( ! ( V_3 & V_13 ) )
return - V_10 ;
V_8 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_6 = V_2 & 0xff ;
V_7 = 0 ;
V_5 -> V_11 = V_14 ;
break;
case 20 :
if ( ! ( V_3 & V_15 ) )
return - V_10 ;
V_8 = V_2 & 0x7f ;
V_2 >>= 7 ;
V_6 = V_2 & 0x1f ;
V_2 >>= 5 ;
V_7 = V_2 & 0xff ;
V_5 -> V_11 = V_16 ;
break;
default:
return - V_10 ;
}
V_5 -> V_17 = V_6 << 16 | V_7 << 8 | V_8 ;
return V_18 ;
}
static int F_2 ( const struct V_19 * V_20 ,
struct V_21 * V_22 , T_1 V_23 )
{
unsigned int V_6 , V_7 , V_8 ;
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_1 = 0 ;
V_6 = ( V_20 -> V_27 >> 16 ) & 0xff ;
V_24 = ( V_20 -> V_28 >> 16 ) & 0xff ;
V_7 = ( V_20 -> V_27 >> 8 ) & 0xff ;
V_25 = ( V_20 -> V_28 >> 8 ) & 0xff ;
V_8 = ( V_20 -> V_27 >> 0 ) & 0x7f ;
V_26 = ( V_20 -> V_28 >> 0 ) & 0x7f ;
V_23 &= V_9 | V_13 | V_15 ;
if ( ! F_3 ( V_23 ) ) {
if ( V_7 & V_25 )
V_23 = V_15 ;
else if ( V_6 & V_24 & 0xe0 )
V_23 = V_13 ;
else
V_23 = V_9 ;
}
if ( V_23 == V_15 ) {
if ( V_6 & V_24 & 0xe0 )
return - V_10 ;
V_1 = 20 ;
V_24 &= 0x1f ;
} else if ( V_23 == V_13 ) {
V_1 = 15 ;
V_25 = 0 ;
} else {
V_25 &= ( V_24 >> 5 ) | 0xf8 ;
V_24 &= 0x1f ;
}
V_6 &= V_24 ;
V_7 &= V_25 ;
V_22 -> V_27 = V_8 |
V_6 << 7 |
V_7 << 15 ;
V_22 -> V_28 = V_26 |
V_24 << 7 |
V_25 << 15 ;
if ( V_1 ) {
V_22 -> V_29 = V_1 ;
V_22 -> V_30 = V_1 ;
}
return 0 ;
}
