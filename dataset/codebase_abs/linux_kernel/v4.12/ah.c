static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( F_2 ( V_7 ) & V_8 ) {
const struct V_9 * V_10 = F_3 ( V_7 ) ;
memcpy ( V_5 -> V_11 . V_12 , & V_10 -> V_13 , 16 ) ;
V_5 -> V_11 . V_14 = F_4 ( V_10 -> V_15 |
( 1 << 30 ) |
V_10 -> V_16 << 20 ) ;
V_5 -> V_11 . V_17 = V_10 -> V_17 ;
V_5 -> V_11 . V_18 = V_10 -> V_19 ;
}
V_5 -> V_11 . V_20 = ( F_5 ( V_7 ) << 4 ) ;
if ( V_7 -> type == V_21 ) {
memcpy ( V_5 -> V_11 . V_22 , V_7 -> V_23 . V_24 ,
sizeof( V_7 -> V_23 . V_24 ) ) ;
V_5 -> V_11 . V_25 =
F_6 ( V_3 ,
F_7 ( V_7 ) ,
F_3 ( V_7 ) -> V_16 ) ;
V_5 -> V_11 . V_20 |= ( F_8 ( V_7 ) & 0x7 ) << 1 ;
} else {
V_5 -> V_11 . V_26 = F_9 ( F_10 ( V_7 ) ) ;
V_5 -> V_11 . V_27 = F_11 ( V_7 ) & 0x7f ;
V_5 -> V_11 . V_20 |= ( F_8 ( V_7 ) & 0xf ) ;
}
return & V_5 -> V_28 ;
}
struct V_1 * F_12 ( struct V_29 * V_30 , struct V_6 * V_7 ,
struct V_31 * V_32 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = F_13 ( V_30 -> V_33 ) ;
enum V_34 V_35 = V_7 -> type ;
if ( ( V_35 == V_21 ) &&
! ( F_2 ( V_7 ) & V_8 ) )
return F_14 ( - V_36 ) ;
if ( V_35 == V_21 && V_32 ) {
int V_37 ;
struct V_38 V_39 = {} ;
T_1 V_40 = F_15 ( F_16 ( V_39 ) , V_24 ) +
sizeof( V_39 . V_24 ) ;
if ( V_32 -> V_41 < V_40 )
return F_14 ( - V_36 ) ;
V_39 . V_42 = V_40 ;
V_37 = F_17 ( V_30 -> V_33 , V_7 ) ;
if ( V_37 )
return F_14 ( V_37 ) ;
memcpy ( V_39 . V_24 , V_7 -> V_23 . V_24 , V_43 ) ;
V_37 = F_18 ( V_32 , & V_39 , V_39 . V_42 ) ;
if ( V_37 )
return F_14 ( V_37 ) ;
}
V_5 = F_19 ( sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return F_14 ( - V_45 ) ;
return F_1 ( V_3 , V_5 , V_7 ) ;
}
int F_20 ( struct V_1 * V_28 , struct V_6 * V_7 )
{
struct V_4 * V_5 = F_21 ( V_28 ) ;
T_1 V_46 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> type = V_28 -> type ;
V_46 = F_22 ( V_5 -> V_11 . V_14 ) ;
if ( V_46 & ( 1 << 30 ) ) {
F_23 ( V_7 , NULL ,
V_46 & 0xfffff ,
( V_46 >> 20 ) & 0xff ,
V_5 -> V_11 . V_17 ,
V_5 -> V_11 . V_18 ) ;
F_24 ( V_7 , V_5 -> V_11 . V_12 ) ;
}
F_25 ( V_7 , F_26 ( V_5 -> V_11 . V_26 ) ) ;
F_27 ( V_7 , V_5 -> V_11 . V_20 >> 4 ) ;
F_28 ( V_7 , V_5 -> V_11 . V_20 & 0xf ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_5 )
{
F_30 ( F_21 ( V_5 ) ) ;
return 0 ;
}
