static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , union V_7 * V_8 ,
int V_9 , bool * V_10 , T_1 V_11 )
{
int V_12 = 0 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( ! V_11 || ( V_11 > 0xFFF ) )
V_11 = V_2 -> V_18 ;
if ( V_11 || V_2 -> V_19 ) {
if ( ! V_11 ) {
F_2 ( L_1 ,
V_2 -> V_20 ) ;
F_2 ( L_2 ,
V_2 -> V_20 ) ;
}
V_14 . V_21 = F_3 ( 0x8100 ) ;
V_14 . V_22 = F_3 ( V_23 ) ;
V_11 |= ( V_2 -> V_24 & 0x07 ) << V_25 ;
V_14 . V_11 = F_3 ( V_11 ) ;
V_17 = sizeof( struct V_13 ) ;
* V_10 = true ;
} else {
V_14 . V_21 = F_3 ( V_23 ) ;
V_17 = sizeof( struct V_26 ) ;
}
memcpy ( & V_14 . V_27 [ 0 ] , & V_2 -> V_28 . V_29 [ 0 ] , V_30 ) ;
V_12 = F_4 ( V_2 , V_6 , & V_14 . V_31 [ 0 ] ) ;
if ( V_12 )
return V_12 ;
V_4 -> V_32 = V_6 -> V_16 . V_32 ;
memcpy ( & V_16 . V_8 [ 0 ] , V_8 -> V_33 , sizeof( union V_7 ) ) ;
memcpy ( & V_16 . V_34 [ 0 ] , V_6 -> V_16 . V_34 . V_33 , sizeof( V_6 -> V_16 . V_34 . V_33 ) ) ;
V_16 . V_35 = F_5 ( ( 6 << 28 ) |
( V_6 -> V_16 . V_36 << 24 ) |
V_6 -> V_16 . V_37 ) ;
V_16 . V_38 = F_5 ( ( V_9 << 16 ) |
( 0x1b << 8 ) | V_6 -> V_16 . V_39 ) ;
memcpy ( & V_4 -> V_40 -> V_41 , & V_14 , V_17 ) ;
memcpy ( ( V_42 * ) V_4 -> V_40 + V_17 , & V_16 , sizeof( struct V_15 ) ) ;
if ( * V_10 )
V_4 -> V_40 -> V_43 |= V_44 ;
V_4 -> V_40 -> V_43 = F_6 ( V_4 -> V_40 -> V_43 ) ;
return V_12 ;
}
struct V_45 * F_7 ( struct V_46 * V_47 , struct V_5 * V_6 )
{
T_2 * V_48 ;
int V_12 ;
struct V_3 * V_4 ;
bool V_10 = false ;
T_1 V_11 = 0xffff ;
struct V_49 V_50 ;
struct V_51 * V_52 = F_8 ( V_47 ) ;
struct V_1 * V_2 = F_9 ( V_47 -> V_53 ) ;
union V_7 V_8 ;
if ( ! ( V_6 -> V_54 & V_55 ) )
return F_10 ( - V_56 ) ;
if ( F_11 ( & V_2 -> V_57 , 1 , 0 ) )
F_12 ( V_2 ) ;
V_4 = F_13 ( sizeof( * V_4 ) , V_58 ) ;
if ( ! V_4 )
return F_10 ( - V_59 ) ;
V_12 = F_14 ( V_2 , V_4 ) ;
if ( V_12 )
goto V_60;
V_12 = F_15 ( & V_2 -> V_61 , 1 , V_6 -> V_16 . V_32 , & V_8 ,
& V_50 ) ;
if ( V_12 ) {
F_2 ( L_3 ,
V_62 , V_12 ) ;
goto V_63;
}
if ( V_50 . V_64 ) {
if ( F_16 ( V_50 . V_64 ) )
V_11 = F_17 ( V_50 . V_64 ) ;
F_18 ( V_50 . V_64 ) ;
}
if ( ( V_52 -> V_65 ) &&
( ! F_19 ( (struct V_66 * ) V_6 -> V_16 . V_34 . V_33 ) ) &&
( ! F_20 ( (struct V_66 * ) V_6 -> V_16 . V_34 . V_33 ) ) ) {
V_12 = F_21 ( & V_8 , & V_6 -> V_16 . V_34 ,
V_6 -> V_31 , & V_11 ,
& V_50 . V_64 -> V_67 ,
NULL ) ;
if ( V_12 ) {
F_2 ( L_4
L_5 , V_62 , V_12 ) ;
goto V_63;
}
}
V_12 = F_1 ( V_2 , V_4 , V_6 , & V_8 , V_52 -> V_20 , & V_10 , V_11 ) ;
if ( V_12 )
goto V_63;
if ( ( V_52 -> V_65 ) && ( V_52 -> V_65 -> V_68 . V_69 ) ) {
V_48 = V_52 -> V_65 -> V_68 . V_69 + V_6 -> V_70 ;
* V_48 = 0 ;
* V_48 |= V_4 -> V_20 & V_71 ;
if ( V_10 )
* V_48 |= ( V_72 <<
V_73 ) ;
}
return & V_4 -> V_74 ;
V_63:
F_22 ( V_2 , V_4 ) ;
V_60:
F_23 ( V_4 ) ;
return F_10 ( V_12 ) ;
}
int F_24 ( struct V_45 * V_74 )
{
struct V_3 * V_4 = F_25 ( V_74 ) ;
struct V_1 * V_2 = F_9 ( V_74 -> V_53 ) ;
F_22 ( V_2 , V_4 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
int F_26 ( struct V_45 * V_74 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_25 ( V_74 ) ;
struct V_75 * V_40 = V_4 -> V_40 ;
struct V_15 * V_16 ;
V_6 -> V_54 |= V_55 ;
if ( V_4 -> V_40 -> V_43 & V_76 ) {
V_16 = (struct V_15 * ) ( ( V_42 * ) V_4 -> V_40 +
sizeof( struct V_13 ) ) ;
V_6 -> V_24 = F_27 ( V_40 -> V_41 . V_11 ) >> 13 ;
} else {
V_16 = (struct V_15 * ) ( ( V_42 * ) V_4 -> V_40 +
sizeof( struct V_26 ) ) ;
V_6 -> V_24 = 0 ;
}
memcpy ( & V_6 -> V_16 . V_34 . V_33 [ 0 ] , & V_16 -> V_34 [ 0 ] , sizeof( V_16 -> V_34 ) ) ;
V_6 -> V_16 . V_32 = V_4 -> V_32 ;
V_6 -> V_16 . V_39 = F_28 ( V_16 -> V_38 ) & 0xff ;
V_6 -> V_16 . V_36 = F_28 ( V_16 -> V_35 ) >> 24 ;
V_6 -> V_16 . V_37 = F_28 ( V_16 -> V_35 ) & 0x00ffffffff ;
return 0 ;
}
int F_29 ( struct V_45 * V_74 , struct V_5 * V_6 )
{
return - V_77 ;
}
int F_30 ( struct V_78 * V_61 ,
int V_79 ,
V_42 V_80 ,
const struct V_81 * V_82 ,
const struct V_83 * V_84 ,
const struct V_85 * V_86 , T_3 V_87 ,
struct V_85 * V_88 , T_3 * V_89 ,
T_1 * V_90 )
{
int V_12 ;
struct V_1 * V_2 ;
const struct V_91 * V_92 = ( const struct V_91 * ) V_86 ;
struct V_91 * V_93 = (struct V_91 * ) V_88 ;
if ( F_31 ( V_87 != sizeof( * V_92 ) ||
* V_89 != sizeof( * V_93 ) ) )
return V_94 ;
switch ( V_92 -> V_95 . V_96 ) {
case V_97 :
V_2 = F_9 ( V_61 ) ;
if ( ! F_32 ( V_2 , V_93 ) )
V_12 = V_98 | V_99 ;
else
V_12 = V_98 ;
break;
default:
V_12 = V_98 ;
break;
}
return V_12 ;
}
