static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
F_2 ( V_4 , 0x600140 + ( V_2 -> V_8 * 0x2000 ) , 0x00000000 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
F_2 ( V_4 , 0x600140 + ( V_2 -> V_8 * 0x2000 ) , 0x00000001 ) ;
}
static void
F_4 ( struct V_1 * V_2 , T_1 * V_9 , T_1 * V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
T_2 V_11 = F_5 ( V_4 , 0x600868 + ( V_2 -> V_8 * 0x2000 ) ) ;
* V_9 = ( V_11 & 0xffff0000 ) >> 16 ;
* V_10 = ( V_11 & 0x0000ffff ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_2 V_14 = V_2 -> V_8 * 0x0200 ;
V_13 -> V_15 = F_5 ( V_4 , 0x680800 + V_14 ) & 0x0000ffff ;
V_13 -> V_16 = F_5 ( V_4 , 0x680804 + V_14 ) & 0x0000ffff ;
V_13 -> V_17 = V_13 -> V_16 - 1 ;
V_13 -> V_18 = F_5 ( V_4 , 0x680820 + V_14 ) & 0x0000ffff ;
V_13 -> V_19 = F_5 ( V_4 , 0x680824 + V_14 ) & 0x0000ffff ;
V_13 -> V_20 = V_13 -> V_19 - 1 ;
}
int
F_7 ( struct V_21 * V_5 , int V_8 )
{
return F_8 ( & V_22 , V_5 , V_8 ) ;
}
