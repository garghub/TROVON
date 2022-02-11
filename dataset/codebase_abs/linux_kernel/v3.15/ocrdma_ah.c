static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
int V_8 = 0 ;
T_1 V_9 ; bool V_10 = false ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_4 -> V_16 = V_6 -> V_14 . V_16 ;
V_9 = V_6 -> V_17 ;
if ( ! V_9 || ( V_9 > 0xFFF ) )
V_9 = V_2 -> V_18 ;
if ( V_9 && ( V_9 < 0x1000 ) ) {
V_12 . V_19 = F_2 ( 0x8100 ) ;
V_12 . V_20 = F_2 ( V_21 ) ;
V_9 |= ( V_6 -> V_22 & 7 ) << 13 ;
V_12 . V_9 = F_2 ( V_9 ) ;
V_15 = sizeof( struct V_11 ) ;
V_10 = true ;
} else {
V_12 . V_19 = F_2 ( V_21 ) ;
V_15 = sizeof( struct V_23 ) ;
}
memcpy ( & V_12 . V_24 [ 0 ] , & V_2 -> V_25 . V_26 [ 0 ] , V_27 ) ;
memcpy ( & V_12 . V_28 [ 0 ] , V_6 -> V_28 , V_27 ) ;
V_8 = F_3 ( V_2 , V_6 , & V_12 . V_28 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( & V_2 -> V_29 , 1 , V_6 -> V_14 . V_16 ,
(union V_30 * ) & V_14 . V_31 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_14 . V_32 = F_5 ( ( 6 << 28 ) |
( V_6 -> V_14 . V_33 << 24 ) |
V_6 -> V_14 . V_34 ) ;
V_14 . V_35 = F_5 ( ( V_7 << 16 ) |
( 0x1b << 8 ) | V_6 -> V_14 . V_36 ) ;
memcpy ( & V_14 . V_37 [ 0 ] , V_6 -> V_14 . V_37 . V_38 , sizeof( V_6 -> V_14 . V_37 . V_38 ) ) ;
memcpy ( & V_4 -> V_39 -> V_40 , & V_12 , V_15 ) ;
memcpy ( ( V_41 * ) V_4 -> V_39 + V_15 , & V_14 , sizeof( struct V_13 ) ) ;
if ( V_10 )
V_4 -> V_39 -> V_42 |= V_43 ;
V_4 -> V_39 -> V_42 = F_6 ( V_4 -> V_39 -> V_42 ) ;
return V_8 ;
}
struct V_44 * F_7 ( struct V_45 * V_46 , struct V_5 * V_6 )
{
T_2 * V_47 ;
int V_8 ;
struct V_3 * V_4 ;
struct V_48 * V_49 = F_8 ( V_46 ) ;
struct V_1 * V_2 = F_9 ( V_46 -> V_50 ) ;
if ( ! ( V_6 -> V_51 & V_52 ) )
return F_10 ( - V_53 ) ;
V_4 = F_11 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return F_10 ( - V_55 ) ;
V_8 = F_12 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_56;
V_8 = F_1 ( V_2 , V_4 , V_6 , V_49 -> V_57 ) ;
if ( V_8 )
goto V_58;
if ( ( V_49 -> V_59 ) && ( V_49 -> V_59 -> V_60 . V_61 ) ) {
V_47 = V_49 -> V_59 -> V_60 . V_61 + V_6 -> V_62 ;
* V_47 = V_4 -> V_57 ;
}
return & V_4 -> V_63 ;
V_58:
F_13 ( V_2 , V_4 ) ;
V_56:
F_14 ( V_4 ) ;
return F_10 ( V_8 ) ;
}
int F_15 ( struct V_44 * V_63 )
{
struct V_3 * V_4 = F_16 ( V_63 ) ;
struct V_1 * V_2 = F_9 ( V_63 -> V_50 ) ;
F_13 ( V_2 , V_4 ) ;
F_14 ( V_4 ) ;
return 0 ;
}
int F_17 ( struct V_44 * V_63 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_16 ( V_63 ) ;
struct V_64 * V_39 = V_4 -> V_39 ;
struct V_13 * V_14 ;
V_6 -> V_51 |= V_52 ;
if ( V_4 -> V_39 -> V_42 & F_18 ( 1 ) ) {
V_14 = (struct V_13 * ) ( ( V_41 * ) V_4 -> V_39 +
sizeof( struct V_11 ) ) ;
V_6 -> V_22 = F_19 ( V_39 -> V_40 . V_9 ) >> 13 ;
} else {
V_14 = (struct V_13 * ) ( ( V_41 * ) V_4 -> V_39 +
sizeof( struct V_23 ) ) ;
V_6 -> V_22 = 0 ;
}
memcpy ( & V_6 -> V_14 . V_37 . V_38 [ 0 ] , & V_14 -> V_37 [ 0 ] , sizeof( V_14 -> V_37 ) ) ;
V_6 -> V_14 . V_16 = V_4 -> V_16 ;
V_6 -> V_14 . V_36 = F_20 ( V_14 -> V_35 ) & 0xff ;
V_6 -> V_14 . V_33 = F_20 ( V_14 -> V_32 ) >> 24 ;
V_6 -> V_14 . V_34 = F_20 ( V_14 -> V_32 ) & 0x00ffffffff ;
return 0 ;
}
int F_21 ( struct V_44 * V_63 , struct V_5 * V_6 )
{
return - V_65 ;
}
int F_22 ( struct V_66 * V_29 ,
int V_67 ,
V_41 V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_73 * V_74 , struct V_73 * V_75 )
{
return V_76 ;
}
