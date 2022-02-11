struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_3 -> V_6 & V_7 ) {
memcpy ( V_5 -> V_8 . V_9 , & V_3 -> V_10 . V_11 , 16 ) ;
V_5 -> V_8 . V_12 = F_2 ( V_3 -> V_10 . V_13 |
( 1 << 30 ) |
V_3 -> V_10 . V_14 << 20 ) ;
V_5 -> V_8 . V_15 = V_3 -> V_10 . V_15 ;
V_5 -> V_8 . V_16 = V_3 -> V_10 . V_17 ;
}
V_5 -> V_8 . V_18 = F_3 ( V_3 -> V_19 ) ;
V_5 -> V_8 . V_20 = V_3 -> V_21 & 0x7f ;
V_5 -> V_8 . V_22 = ( V_3 -> V_23 << 4 ) | ( V_3 -> V_24 & 0xf ) ;
return & V_5 -> V_25 ;
}
struct V_1 * F_4 ( struct V_26 * V_27 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_5 ( sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return F_6 ( - V_29 ) ;
return F_1 ( V_3 , V_5 ) ;
}
int F_7 ( struct V_1 * V_25 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_8 ( V_25 ) ;
T_1 V_30 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_30 = F_9 ( V_5 -> V_8 . V_12 ) ;
if ( V_30 & ( 1 << 30 ) ) {
V_3 -> V_6 = V_7 ;
V_3 -> V_10 . V_14 = ( V_30 >> 20 ) & 0xff ;
V_3 -> V_10 . V_13 = V_30 & 0xfffff ;
memcpy ( & V_3 -> V_10 . V_11 , V_5 -> V_8 . V_9 , 16 ) ;
V_3 -> V_10 . V_15 = V_5 -> V_8 . V_15 ;
V_3 -> V_10 . V_17 = V_5 -> V_8 . V_16 ;
}
V_3 -> V_19 = F_10 ( V_5 -> V_8 . V_18 ) ;
V_3 -> V_23 = V_5 -> V_8 . V_22 >> 4 ;
V_3 -> V_24 = V_5 -> V_8 . V_22 & 0xf ;
return 0 ;
}
int F_11 ( struct V_1 * V_5 )
{
F_12 ( F_8 ( V_5 ) ) ;
return 0 ;
}
