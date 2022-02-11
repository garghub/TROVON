static T_1 F_1 ( int V_1 , T_2 V_2 )
{
switch ( V_2 ) {
case V_3 :
return ( T_1 ) V_4 ;
case V_5 :
return ( T_1 ) 0x0800 ;
case V_6 :
return ( T_1 ) 0x86dd ;
default:
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
}
static inline int F_3 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_11 * V_12 , union V_13 * V_14 ,
int V_15 , bool * V_16 , T_1 V_17 )
{
int V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
int V_23 ;
T_1 V_24 = 0 ;
T_2 V_25 = 0x11 ;
struct V_26 V_27 ;
union {
struct V_28 V_29 ;
struct V_30 V_31 ;
struct V_32 V_33 ;
} V_34 , V_35 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_24 = F_1 ( V_8 -> V_36 , V_10 -> V_2 ) ;
if ( ! V_24 )
return - V_37 ;
V_25 = ( V_24 == V_4 ) ? 0x1b : 0x11 ;
if ( ! V_17 || ( V_17 > 0xFFF ) )
V_17 = V_8 -> V_38 ;
if ( V_17 || V_8 -> V_39 ) {
if ( ! V_17 ) {
F_2 ( L_2 ,
V_8 -> V_36 ) ;
F_2 ( L_3 ,
V_8 -> V_36 ) ;
}
V_20 . V_40 = F_4 ( 0x8100 ) ;
V_20 . V_41 = F_4 ( V_24 ) ;
V_17 |= ( V_8 -> V_42 & 0x07 ) << V_43 ;
V_20 . V_17 = F_4 ( V_17 ) ;
V_23 = sizeof( struct V_19 ) ;
* V_16 = true ;
} else {
V_20 . V_40 = F_4 ( V_24 ) ;
V_23 = sizeof( struct V_44 ) ;
}
memcpy ( & V_20 . V_45 [ 0 ] , & V_8 -> V_46 . V_47 [ 0 ] , V_48 ) ;
V_18 = F_5 ( V_8 , V_12 , & V_20 . V_49 [ 0 ] ) ;
if ( V_18 )
return V_18 ;
V_10 -> V_50 = V_12 -> V_22 . V_50 ;
memcpy ( & V_10 -> V_51 -> V_52 , & V_20 , V_23 ) ;
if ( V_10 -> V_2 == V_53 ) {
* ( ( V_54 * ) & V_27 ) = F_6 ( ( 4 << 12 ) | ( 5 << 8 ) |
V_12 -> V_22 . V_55 ) ;
V_27 . V_36 = F_4 ( V_15 ) ;
V_27 . V_56 = F_6 ( V_57 ) ;
V_27 . V_58 = F_6 ( 0 ) ;
V_27 . V_59 = V_12 -> V_22 . V_60 ;
V_27 . V_61 = V_25 ;
F_7 ( & V_34 . V_29 , V_14 ) ;
V_27 . V_62 = V_34 . V_31 . V_63 . V_64 ;
F_7 ( & V_35 . V_29 , & V_12 -> V_22 . V_65 ) ;
V_27 . V_66 = V_35 . V_31 . V_63 . V_64 ;
memcpy ( ( T_2 * ) V_10 -> V_51 + V_23 , & V_27 , sizeof( struct V_26 ) ) ;
} else {
memcpy ( & V_22 . V_14 [ 0 ] , V_14 -> V_67 , sizeof( union V_13 ) ) ;
V_22 . V_68 = F_8 ( ( 6 << 28 ) |
( V_12 -> V_22 . V_55 << 24 ) |
V_12 -> V_22 . V_69 ) ;
memcpy ( & V_22 . V_65 [ 0 ] , V_12 -> V_22 . V_65 . V_67 ,
sizeof( V_12 -> V_22 . V_65 . V_67 ) ) ;
V_22 . V_70 = F_8 ( ( V_15 << 16 ) |
( V_25 << 8 ) |
V_12 -> V_22 . V_60 ) ;
memcpy ( ( T_2 * ) V_10 -> V_51 + V_23 , & V_22 , sizeof( struct V_21 ) ) ;
}
if ( * V_16 )
V_10 -> V_51 -> V_71 |= V_72 ;
V_10 -> V_51 -> V_71 = F_9 ( V_10 -> V_51 -> V_71 ) ;
return V_18 ;
}
struct V_73 * F_10 ( struct V_74 * V_75 , struct V_11 * V_12 ,
struct V_76 * V_77 )
{
T_3 * V_78 ;
int V_18 ;
struct V_9 * V_10 ;
bool V_16 = false ;
T_1 V_17 = 0xffff ;
struct V_79 V_80 ;
struct V_81 * V_82 = F_11 ( V_75 ) ;
struct V_7 * V_8 = F_12 ( V_75 -> V_83 ) ;
union V_13 V_14 ;
if ( ! ( V_12 -> V_84 & V_85 ) )
return F_13 ( - V_37 ) ;
if ( F_14 ( & V_8 -> V_86 , 1 , 0 ) )
F_15 ( V_8 ) ;
V_10 = F_16 ( sizeof( * V_10 ) , V_87 ) ;
if ( ! V_10 )
return F_13 ( - V_88 ) ;
V_18 = F_17 ( V_8 , V_10 ) ;
if ( V_18 )
goto V_89;
V_18 = F_18 ( & V_8 -> V_90 , 1 , V_12 -> V_22 . V_50 , & V_14 ,
& V_80 ) ;
if ( V_18 ) {
F_2 ( L_4 ,
V_91 , V_18 ) ;
goto V_92;
}
if ( V_80 . V_93 ) {
if ( F_19 ( V_80 . V_93 ) )
V_17 = F_20 ( V_80 . V_93 ) ;
F_21 ( V_80 . V_93 ) ;
}
V_10 -> V_2 = F_22 ( V_80 . V_94 , & V_14 ) ;
if ( ( V_82 -> V_95 ) &&
( ! F_23 ( (struct V_96 * ) V_12 -> V_22 . V_65 . V_67 ) ) &&
( ! F_24 ( (struct V_96 * ) V_12 -> V_22 . V_65 . V_67 ) ) ) {
V_18 = F_25 ( & V_14 , & V_12 -> V_22 . V_65 ,
V_12 -> V_49 , & V_17 ,
& V_80 . V_93 -> V_97 ,
NULL ) ;
if ( V_18 ) {
F_2 ( L_5
L_6 , V_91 , V_18 ) ;
goto V_92;
}
}
V_18 = F_3 ( V_8 , V_10 , V_12 , & V_14 , V_82 -> V_36 , & V_16 , V_17 ) ;
if ( V_18 )
goto V_92;
if ( ( V_82 -> V_95 ) && ( V_82 -> V_95 -> V_98 . V_99 ) ) {
V_78 = V_82 -> V_95 -> V_98 . V_99 + V_12 -> V_100 ;
* V_78 = 0 ;
* V_78 |= V_10 -> V_36 & V_101 ;
if ( F_26 ( V_8 ) ) {
* V_78 |= ( ( T_3 ) V_10 -> V_2 &
V_102 ) <<
V_103 ;
}
if ( V_16 )
* V_78 |= ( V_104 <<
V_105 ) ;
}
return & V_10 -> V_106 ;
V_92:
F_27 ( V_8 , V_10 ) ;
V_89:
F_28 ( V_10 ) ;
return F_13 ( V_18 ) ;
}
int F_29 ( struct V_73 * V_106 )
{
struct V_9 * V_10 = F_30 ( V_106 ) ;
struct V_7 * V_8 = F_12 ( V_106 -> V_83 ) ;
F_27 ( V_8 , V_10 ) ;
F_28 ( V_10 ) ;
return 0 ;
}
int F_31 ( struct V_73 * V_106 , struct V_11 * V_12 )
{
struct V_9 * V_10 = F_30 ( V_106 ) ;
struct V_107 * V_51 = V_10 -> V_51 ;
struct V_21 * V_22 ;
V_12 -> V_84 |= V_85 ;
if ( V_10 -> V_51 -> V_71 & V_108 ) {
V_22 = (struct V_21 * ) ( ( T_2 * ) V_10 -> V_51 +
sizeof( struct V_19 ) ) ;
V_12 -> V_42 = F_32 ( V_51 -> V_52 . V_17 ) >> 13 ;
} else {
V_22 = (struct V_21 * ) ( ( T_2 * ) V_10 -> V_51 +
sizeof( struct V_44 ) ) ;
V_12 -> V_42 = 0 ;
}
memcpy ( & V_12 -> V_22 . V_65 . V_67 [ 0 ] , & V_22 -> V_65 [ 0 ] , sizeof( V_22 -> V_65 ) ) ;
V_12 -> V_22 . V_50 = V_10 -> V_50 ;
V_12 -> V_22 . V_60 = F_33 ( V_22 -> V_70 ) & 0xff ;
V_12 -> V_22 . V_55 = F_33 ( V_22 -> V_68 ) >> 24 ;
V_12 -> V_22 . V_69 = F_33 ( V_22 -> V_68 ) & 0x00ffffffff ;
return 0 ;
}
int F_34 ( struct V_73 * V_106 , struct V_11 * V_12 )
{
return - V_109 ;
}
int F_35 ( struct V_110 * V_90 ,
int V_111 ,
T_2 V_112 ,
const struct V_113 * V_114 ,
const struct V_115 * V_116 ,
const struct V_117 * V_118 , T_4 V_119 ,
struct V_117 * V_120 , T_4 * V_121 ,
T_1 * V_122 )
{
int V_18 ;
struct V_7 * V_8 ;
const struct V_123 * V_124 = ( const struct V_123 * ) V_118 ;
struct V_123 * V_125 = (struct V_123 * ) V_120 ;
if ( F_36 ( V_119 != sizeof( * V_124 ) ||
* V_121 != sizeof( * V_125 ) ) )
return V_126 ;
switch ( V_124 -> V_127 . V_128 ) {
case V_129 :
V_8 = F_12 ( V_90 ) ;
if ( ! F_37 ( V_8 , V_125 ) )
V_18 = V_130 | V_131 ;
else
V_18 = V_130 ;
break;
default:
V_18 = V_130 ;
break;
}
return V_18 ;
}
