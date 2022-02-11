static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = V_2 -> V_9 * 0x800 ;
F_2 ( V_4 , 0x6100c0 + V_8 , 0x00000001 , 0x00000000 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = V_2 -> V_9 * 0x800 ;
F_2 ( V_4 , 0x6100c0 + V_8 , 0x00000001 , 0x00000001 ) ;
}
static void
F_4 ( struct V_1 * V_2 , int div )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
F_2 ( V_4 , 0x612200 + ( V_2 -> V_9 * 0x800 ) , 0x0000000f , div ) ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = ( V_11 == & V_2 -> V_12 ) * 0x20000 + V_2 -> V_9 * 0x300 ;
T_1 V_13 ;
V_13 = F_6 ( V_4 , 0x640414 + V_8 ) ;
V_11 -> V_14 = ( V_13 & 0xffff0000 ) >> 16 ;
V_11 -> V_15 = ( V_13 & 0x0000ffff ) ;
V_13 = F_6 ( V_4 , 0x640418 + V_8 ) ;
V_11 -> V_16 = ( V_13 & 0xffff0000 ) >> 16 ;
V_11 -> V_17 = ( V_13 & 0x0000ffff ) ;
V_13 = F_6 ( V_4 , 0x64041c + V_8 ) ;
V_11 -> V_18 = ( V_13 & 0xffff0000 ) >> 16 ;
V_11 -> V_19 = ( V_13 & 0x0000ffff ) ;
V_13 = F_6 ( V_4 , 0x640420 + V_8 ) ;
V_11 -> V_20 = ( V_13 & 0xffff0000 ) >> 16 ;
V_11 -> V_21 = ( V_13 & 0x0000ffff ) ;
V_11 -> V_22 = F_6 ( V_4 , 0x640450 + V_8 ) ;
V_13 = F_6 ( V_4 , 0x640404 + V_8 ) ;
switch ( ( V_13 & 0x000003c0 ) >> 6 ) {
case 6 : V_11 -> V_23 . V_24 = 30 ; break;
case 5 : V_11 -> V_23 . V_24 = 24 ; break;
case 2 : V_11 -> V_23 . V_24 = 18 ; break;
case 0 : V_11 -> V_23 . V_24 = 18 ; break;
default:
V_11 -> V_23 . V_24 = 18 ;
F_7 ( 1 ) ;
break;
}
}
int
F_8 ( struct V_25 * V_5 , int V_9 )
{
return F_9 ( & V_26 , V_5 , V_9 ) ;
}
