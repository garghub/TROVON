static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , union V_7 * V_8 , int V_9 )
{
int V_10 = 0 ;
T_1 V_11 ; bool V_12 = false ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_11 = V_6 -> V_18 ;
if ( ! V_11 || ( V_11 > 0xFFF ) )
V_11 = V_2 -> V_19 ;
if ( V_11 && ( V_11 < 0x1000 ) ) {
V_14 . V_20 = F_2 ( 0x8100 ) ;
V_14 . V_21 = F_2 ( V_22 ) ;
V_11 |= ( V_2 -> V_23 & 0x07 ) << V_24 ;
V_14 . V_11 = F_2 ( V_11 ) ;
V_17 = sizeof( struct V_13 ) ;
V_12 = true ;
} else {
V_14 . V_20 = F_2 ( V_22 ) ;
V_17 = sizeof( struct V_25 ) ;
}
memcpy ( & V_14 . V_26 [ 0 ] , & V_2 -> V_27 . V_28 [ 0 ] , V_29 ) ;
V_10 = F_3 ( V_2 , V_6 , & V_14 . V_30 [ 0 ] ) ;
if ( V_10 )
return V_10 ;
V_4 -> V_31 = V_6 -> V_16 . V_31 ;
memcpy ( & V_16 . V_8 [ 0 ] , V_8 -> V_32 , sizeof( union V_7 ) ) ;
memcpy ( & V_16 . V_33 [ 0 ] , V_6 -> V_16 . V_33 . V_32 , sizeof( V_6 -> V_16 . V_33 . V_32 ) ) ;
V_16 . V_34 = F_4 ( ( 6 << 28 ) |
( V_6 -> V_16 . V_35 << 24 ) |
V_6 -> V_16 . V_36 ) ;
V_16 . V_37 = F_4 ( ( V_9 << 16 ) |
( 0x1b << 8 ) | V_6 -> V_16 . V_38 ) ;
memcpy ( & V_4 -> V_39 -> V_40 , & V_14 , V_17 ) ;
memcpy ( ( V_41 * ) V_4 -> V_39 + V_17 , & V_16 , sizeof( struct V_15 ) ) ;
if ( V_12 )
V_4 -> V_39 -> V_42 |= V_43 ;
V_4 -> V_39 -> V_42 = F_5 ( V_4 -> V_39 -> V_42 ) ;
return V_10 ;
}
struct V_44 * F_6 ( struct V_45 * V_46 , struct V_5 * V_6 )
{
T_2 * V_47 ;
int V_10 ;
struct V_3 * V_4 ;
struct V_48 * V_49 = F_7 ( V_46 ) ;
struct V_1 * V_2 = F_8 ( V_46 -> V_50 ) ;
union V_7 V_8 ;
if ( ! ( V_6 -> V_51 & V_52 ) )
return F_9 ( - V_53 ) ;
if ( F_10 ( & V_2 -> V_54 , 1 , 0 ) )
F_11 ( V_2 ) ;
V_4 = F_12 ( sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 )
return F_9 ( - V_56 ) ;
V_10 = F_13 ( V_2 , V_4 ) ;
if ( V_10 )
goto V_57;
V_10 = F_14 ( & V_2 -> V_58 , 1 , V_6 -> V_16 . V_31 , & V_8 ) ;
if ( V_10 ) {
F_15 ( L_1 ,
V_59 , V_10 ) ;
goto V_60;
}
if ( V_49 -> V_61 ) {
V_10 = F_16 ( & V_8 , & V_6 -> V_16 . V_33 ,
V_6 -> V_30 , & V_6 -> V_18 ) ;
if ( V_10 ) {
F_15 ( L_2
L_3 , V_59 , V_10 ) ;
goto V_60;
}
}
V_10 = F_1 ( V_2 , V_4 , V_6 , & V_8 , V_49 -> V_62 ) ;
if ( V_10 )
goto V_60;
if ( ( V_49 -> V_61 ) && ( V_49 -> V_61 -> V_63 . V_64 ) ) {
V_47 = V_49 -> V_61 -> V_63 . V_64 + V_6 -> V_65 ;
* V_47 = V_4 -> V_62 ;
}
return & V_4 -> V_66 ;
V_60:
F_17 ( V_2 , V_4 ) ;
V_57:
F_18 ( V_4 ) ;
return F_9 ( V_10 ) ;
}
int F_19 ( struct V_44 * V_66 )
{
struct V_3 * V_4 = F_20 ( V_66 ) ;
struct V_1 * V_2 = F_8 ( V_66 -> V_50 ) ;
F_17 ( V_2 , V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int F_21 ( struct V_44 * V_66 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_20 ( V_66 ) ;
struct V_67 * V_39 = V_4 -> V_39 ;
struct V_15 * V_16 ;
V_6 -> V_51 |= V_52 ;
if ( V_4 -> V_39 -> V_42 & V_68 ) {
V_16 = (struct V_15 * ) ( ( V_41 * ) V_4 -> V_39 +
sizeof( struct V_13 ) ) ;
V_6 -> V_23 = F_22 ( V_39 -> V_40 . V_11 ) >> 13 ;
} else {
V_16 = (struct V_15 * ) ( ( V_41 * ) V_4 -> V_39 +
sizeof( struct V_25 ) ) ;
V_6 -> V_23 = 0 ;
}
memcpy ( & V_6 -> V_16 . V_33 . V_32 [ 0 ] , & V_16 -> V_33 [ 0 ] , sizeof( V_16 -> V_33 ) ) ;
V_6 -> V_16 . V_31 = V_4 -> V_31 ;
V_6 -> V_16 . V_38 = F_23 ( V_16 -> V_37 ) & 0xff ;
V_6 -> V_16 . V_35 = F_23 ( V_16 -> V_34 ) >> 24 ;
V_6 -> V_16 . V_36 = F_23 ( V_16 -> V_34 ) & 0x00ffffffff ;
return 0 ;
}
int F_24 ( struct V_44 * V_66 , struct V_5 * V_6 )
{
return - V_69 ;
}
int F_25 ( struct V_70 * V_58 ,
int V_71 ,
V_41 V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 , struct V_77 * V_79 )
{
return V_80 ;
}
