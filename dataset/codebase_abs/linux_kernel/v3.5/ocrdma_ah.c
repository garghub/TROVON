static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 = 0 ;
T_1 V_7 ; bool V_8 = false ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_2 -> V_16 = V_4 -> V_14 . V_16 ;
V_7 = F_2 ( & V_4 -> V_14 . V_17 ) ;
if ( V_7 && ( V_7 < 0x1000 ) ) {
V_12 . V_18 = F_3 ( 0x8100 ) ;
V_12 . V_19 = F_3 ( V_20 ) ;
V_7 |= ( V_4 -> V_21 & 7 ) << 13 ;
V_12 . V_7 = F_3 ( V_7 ) ;
V_15 = sizeof( struct V_11 ) ;
V_8 = true ;
} else {
V_12 . V_18 = F_3 ( V_20 ) ;
V_15 = sizeof( struct V_22 ) ;
}
memcpy ( & V_12 . V_23 [ 0 ] , & V_10 -> V_24 . V_25 [ 0 ] , V_26 ) ;
V_6 = F_4 ( V_10 , & V_4 -> V_14 . V_17 , & V_12 . V_27 [ 0 ] ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( & V_10 -> V_28 , 1 , V_4 -> V_14 . V_16 ,
(union V_29 * ) & V_14 . V_30 [ 0 ] ) ;
if ( V_6 )
return V_6 ;
V_14 . V_31 = F_6 ( ( 6 << 28 ) |
( V_4 -> V_14 . V_32 << 24 ) |
V_4 -> V_14 . V_33 ) ;
V_14 . V_34 = F_6 ( ( V_5 << 16 ) |
( 0x1b << 8 ) | V_4 -> V_14 . V_35 ) ;
memcpy ( & V_14 . V_17 [ 0 ] , V_4 -> V_14 . V_17 . V_36 , sizeof( V_4 -> V_14 . V_17 . V_36 ) ) ;
memcpy ( & V_2 -> V_37 -> V_38 , & V_12 , V_15 ) ;
memcpy ( ( V_39 * ) V_2 -> V_37 + V_15 , & V_14 , sizeof( struct V_13 ) ) ;
if ( V_8 )
V_2 -> V_37 -> V_40 |= V_41 ;
return V_6 ;
}
struct V_42 * F_7 ( struct V_43 * V_44 , struct V_3 * V_4 )
{
T_2 * V_45 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_46 * V_47 = F_8 ( V_44 ) ;
struct V_9 * V_10 = V_47 -> V_10 ;
if ( ! ( V_4 -> V_48 & V_49 ) )
return F_9 ( - V_50 ) ;
V_2 = F_10 ( sizeof *V_2 , V_51 ) ;
if ( ! V_2 )
return F_9 ( - V_52 ) ;
V_2 -> V_10 = V_47 -> V_10 ;
V_6 = F_11 ( V_10 , V_2 ) ;
if ( V_6 )
goto V_53;
V_6 = F_1 ( V_2 , V_4 , V_47 -> V_54 ) ;
if ( V_6 )
goto V_55;
if ( ( V_47 -> V_56 ) && ( V_47 -> V_56 -> V_57 . V_58 ) ) {
V_45 = V_47 -> V_56 -> V_57 . V_58 + V_4 -> V_59 ;
* V_45 = V_2 -> V_54 ;
}
return & V_2 -> V_60 ;
V_55:
F_12 ( V_10 , V_2 ) ;
V_53:
F_13 ( V_2 ) ;
return F_9 ( V_6 ) ;
}
int F_14 ( struct V_42 * V_60 )
{
struct V_1 * V_2 = F_15 ( V_60 ) ;
F_12 ( V_2 -> V_10 , V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_42 * V_60 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_60 ) ;
struct V_61 * V_37 = V_2 -> V_37 ;
struct V_13 * V_14 ;
V_4 -> V_48 |= V_49 ;
if ( V_2 -> V_37 -> V_40 & F_17 ( 1 ) ) {
V_14 = (struct V_13 * ) ( ( V_39 * ) V_2 -> V_37 +
sizeof( struct V_11 ) ) ;
V_4 -> V_21 = F_18 ( V_37 -> V_38 . V_7 ) >> 13 ;
} else {
V_14 = (struct V_13 * ) ( ( V_39 * ) V_2 -> V_37 +
sizeof( struct V_22 ) ) ;
V_4 -> V_21 = 0 ;
}
memcpy ( & V_4 -> V_14 . V_17 . V_36 [ 0 ] , & V_14 -> V_17 [ 0 ] , sizeof( V_14 -> V_17 ) ) ;
V_4 -> V_14 . V_16 = V_2 -> V_16 ;
V_4 -> V_14 . V_35 = F_19 ( V_14 -> V_34 ) & 0xff ;
V_4 -> V_14 . V_32 = F_19 ( V_14 -> V_31 ) >> 24 ;
V_4 -> V_14 . V_33 = F_19 ( V_14 -> V_31 ) & 0x00ffffffff ;
return 0 ;
}
int F_20 ( struct V_42 * V_60 , struct V_3 * V_4 )
{
return - V_62 ;
}
int F_21 ( struct V_63 * V_28 ,
int V_64 ,
V_39 V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * V_71 , struct V_70 * V_72 )
{
return V_73 ;
}
