static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
enum V_8 V_9 )
{
if ( V_7 -> V_10 & V_11 ) {
memcpy ( V_5 -> V_12 . V_13 , & V_7 -> V_14 . V_15 , 16 ) ;
V_5 -> V_12 . V_16 = F_2 ( V_7 -> V_14 . V_17 |
( 1 << 30 ) |
V_7 -> V_14 . V_18 << 20 ) ;
V_5 -> V_12 . V_19 = V_7 -> V_14 . V_19 ;
V_5 -> V_12 . V_20 = V_7 -> V_14 . V_21 ;
}
V_5 -> V_12 . V_22 = ( V_7 -> V_23 << 4 ) ;
if ( V_9 == V_24 ) {
memcpy ( V_5 -> V_12 . V_25 , V_7 -> V_26 , sizeof( V_7 -> V_26 ) ) ;
V_5 -> V_12 . V_27 =
F_3 ( V_3 ,
V_7 -> V_28 ,
V_7 -> V_14 . V_18 ) ;
V_5 -> V_12 . V_22 |= ( V_7 -> V_29 & 0x7 ) << 1 ;
} else {
V_5 -> V_12 . V_30 = F_4 ( V_7 -> V_31 ) ;
V_5 -> V_12 . V_32 = V_7 -> V_33 & 0x7f ;
V_5 -> V_12 . V_22 |= ( V_7 -> V_29 & 0xf ) ;
}
return & V_5 -> V_34 ;
}
struct V_1 * F_5 ( struct V_35 * V_36 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = F_6 ( V_36 -> V_37 ) ;
enum V_8 V_9 ;
V_9 = V_36 -> V_37 -> V_38 ( V_36 -> V_37 , V_7 -> V_28 ) ;
if ( V_9 == V_24 && ! ( V_7 -> V_10 & V_11 ) )
return F_7 ( - V_39 ) ;
V_5 = F_8 ( sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return F_7 ( - V_41 ) ;
return F_1 ( V_3 , V_5 , V_7 , V_9 ) ;
}
int F_9 ( struct V_1 * V_34 , struct V_6 * V_7 )
{
struct V_4 * V_5 = F_10 ( V_34 ) ;
T_1 V_42 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_42 = F_11 ( V_5 -> V_12 . V_16 ) ;
if ( V_42 & ( 1 << 30 ) ) {
V_7 -> V_10 = V_11 ;
V_7 -> V_14 . V_18 = ( V_42 >> 20 ) & 0xff ;
V_7 -> V_14 . V_17 = V_42 & 0xfffff ;
memcpy ( & V_7 -> V_14 . V_15 , V_5 -> V_12 . V_13 , 16 ) ;
V_7 -> V_14 . V_19 = V_5 -> V_12 . V_19 ;
V_7 -> V_14 . V_21 = V_5 -> V_12 . V_20 ;
}
V_7 -> V_31 = F_12 ( V_5 -> V_12 . V_30 ) ;
V_7 -> V_23 = V_5 -> V_12 . V_22 >> 4 ;
V_7 -> V_29 = V_5 -> V_12 . V_22 & 0xf ;
return 0 ;
}
int F_13 ( struct V_1 * V_5 )
{
F_14 ( F_10 ( V_5 ) ) ;
return 0 ;
}
