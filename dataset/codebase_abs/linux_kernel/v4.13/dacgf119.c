static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
F_3 ( V_4 , 0x612280 + V_8 , 0x07070707 , 0x00000000 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_11 = ( V_10 == & V_2 -> V_12 ) * 0x20000 + V_2 -> V_13 * 0x20 ;
T_1 V_14 = F_5 ( V_4 , 0x640180 + V_11 ) ;
V_10 -> V_15 = ( V_14 & 0x00000f00 ) >> 8 ;
switch ( V_10 -> V_15 ) {
case 0 : V_10 -> V_16 = V_17 ; break;
default:
V_10 -> V_16 = V_18 ;
break;
}
V_10 -> V_19 = V_14 & 0x0000000f ;
}
int
F_6 ( struct V_20 * V_5 , int V_13 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_7 . V_4 ;
if ( ! ( F_5 ( V_4 , 0x612004 ) & ( 0x00000010 << V_13 ) ) )
return 0 ;
return F_7 ( & V_21 , V_5 , V_22 , V_13 ) ;
}
