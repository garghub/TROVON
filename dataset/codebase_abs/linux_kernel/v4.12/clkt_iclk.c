void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 V_5 ;
memcpy ( & V_5 , & V_2 -> V_6 , sizeof( V_5 ) ) ;
V_5 . V_7 ^= ( V_8 ^ V_9 ) ;
V_3 = V_10 -> V_11 ( & V_5 ) ;
V_3 |= ( 1 << V_2 -> V_12 ) ;
V_10 -> V_13 ( V_3 , & V_5 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 V_5 ;
memcpy ( & V_5 , & V_2 -> V_6 , sizeof( V_5 ) ) ;
V_5 . V_7 ^= ( V_8 ^ V_9 ) ;
V_3 = V_10 -> V_11 ( & V_5 ) ;
V_3 &= ~ ( 1 << V_2 -> V_12 ) ;
V_10 -> V_13 ( V_3 , & V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_4 * V_14 ,
T_2 * V_15 ,
T_2 * V_16 )
{
memcpy ( V_14 , & V_2 -> V_6 , sizeof( * V_14 ) ) ;
V_14 -> V_7 ^= ( V_17 ^ V_18 ) ;
* V_15 = V_2 -> V_12 ;
* V_16 = V_19 ;
}
