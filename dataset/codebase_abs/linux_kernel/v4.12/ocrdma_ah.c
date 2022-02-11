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
const struct V_28 * V_29 ;
union {
struct V_30 V_31 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
} V_36 , V_37 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_24 = F_1 ( V_8 -> V_38 , V_10 -> V_2 ) ;
if ( ! V_24 )
return - V_39 ;
V_25 = ( V_24 == V_4 ) ? 0x1b : 0x11 ;
if ( ! V_17 || ( V_17 > 0xFFF ) )
V_17 = V_8 -> V_40 ;
if ( V_17 || V_8 -> V_41 ) {
if ( ! V_17 ) {
F_2 ( L_2 ,
V_8 -> V_38 ) ;
F_2 ( L_3 ,
V_8 -> V_38 ) ;
}
V_20 . V_42 = F_4 ( 0x8100 ) ;
V_20 . V_43 = F_4 ( V_24 ) ;
V_17 |= ( V_8 -> V_44 & 0x07 ) << V_45 ;
V_20 . V_17 = F_4 ( V_17 ) ;
V_23 = sizeof( struct V_19 ) ;
* V_16 = true ;
} else {
V_20 . V_42 = F_4 ( V_24 ) ;
V_23 = sizeof( struct V_46 ) ;
}
memcpy ( & V_20 . V_47 [ 0 ] , & V_8 -> V_48 . V_49 [ 0 ] , V_50 ) ;
V_18 = F_5 ( V_8 , V_12 , & V_20 . V_51 [ 0 ] ) ;
if ( V_18 )
return V_18 ;
V_29 = F_6 ( V_12 ) ;
V_10 -> V_52 = V_29 -> V_52 ;
memcpy ( & V_10 -> V_53 -> V_54 , & V_20 , V_23 ) ;
if ( V_10 -> V_2 == V_55 ) {
* ( ( V_56 * ) & V_27 ) = F_7 ( ( 4 << 12 ) | ( 5 << 8 ) |
V_29 -> V_57 ) ;
V_27 . V_38 = F_4 ( V_15 ) ;
V_27 . V_58 = F_7 ( V_59 ) ;
V_27 . V_60 = F_7 ( 0 ) ;
V_27 . V_61 = V_29 -> V_62 ;
V_27 . V_63 = V_25 ;
F_8 ( & V_36 . V_31 , V_14 ) ;
V_27 . V_64 = V_36 . V_33 . V_65 . V_66 ;
F_8 ( & V_37 . V_31 , & V_29 -> V_67 ) ;
V_27 . V_68 = V_37 . V_33 . V_65 . V_66 ;
memcpy ( ( T_2 * ) V_10 -> V_53 + V_23 , & V_27 , sizeof( struct V_26 ) ) ;
} else {
memcpy ( & V_22 . V_14 [ 0 ] , V_14 -> V_69 , sizeof( union V_13 ) ) ;
V_22 . V_70 = F_9 ( ( 6 << 28 ) |
( V_29 -> V_57 << 24 ) |
V_29 -> V_71 ) ;
memcpy ( & V_22 . V_67 [ 0 ] , V_29 -> V_67 . V_69 ,
sizeof( V_29 -> V_67 . V_69 ) ) ;
V_22 . V_72 = F_9 ( ( V_15 << 16 ) |
( V_25 << 8 ) |
V_29 -> V_62 ) ;
memcpy ( ( T_2 * ) V_10 -> V_53 + V_23 , & V_22 , sizeof( struct V_21 ) ) ;
}
if ( * V_16 )
V_10 -> V_53 -> V_73 |= V_74 ;
V_10 -> V_53 -> V_73 = F_10 ( V_10 -> V_53 -> V_73 ) ;
return V_18 ;
}
struct V_75 * F_11 ( struct V_76 * V_77 , struct V_11 * V_12 ,
struct V_78 * V_79 )
{
T_3 * V_80 ;
int V_18 ;
struct V_9 * V_10 ;
bool V_16 = false ;
T_1 V_17 = 0xffff ;
struct V_81 V_82 ;
struct V_83 * V_84 = F_12 ( V_77 ) ;
struct V_7 * V_8 = F_13 ( V_77 -> V_85 ) ;
const struct V_28 * V_22 ;
union V_13 V_14 ;
if ( ( V_12 -> type != V_86 ) ||
! ( F_14 ( V_12 ) & V_87 ) )
return F_15 ( - V_39 ) ;
V_22 = F_6 ( V_12 ) ;
if ( F_16 ( & V_8 -> V_88 , 1 , 0 ) )
F_17 ( V_8 ) ;
V_10 = F_18 ( sizeof( * V_10 ) , V_89 ) ;
if ( ! V_10 )
return F_15 ( - V_90 ) ;
V_18 = F_19 ( V_8 , V_10 ) ;
if ( V_18 )
goto V_91;
V_18 = F_20 ( & V_8 -> V_92 , 1 , V_22 -> V_52 , & V_14 ,
& V_82 ) ;
if ( V_18 ) {
F_2 ( L_4 ,
V_93 , V_18 ) ;
goto V_94;
}
if ( V_82 . V_95 ) {
if ( F_21 ( V_82 . V_95 ) )
V_17 = F_22 ( V_82 . V_95 ) ;
F_23 ( V_82 . V_95 ) ;
}
V_10 -> V_2 = F_24 ( V_82 . V_96 , & V_14 ) ;
if ( ( V_84 -> V_97 ) &&
( ! F_25 ( (struct V_98 * ) V_22 -> V_67 . V_69 ) ) &&
( ! F_26 ( (struct V_98 * ) V_22 -> V_67 . V_69 ) ) ) {
V_18 = F_27 ( & V_14 , & V_22 -> V_67 ,
V_12 -> V_99 . V_51 ,
& V_17 ,
& V_82 . V_95 -> V_100 ,
NULL ) ;
if ( V_18 ) {
F_2 ( L_5
L_6 , V_93 , V_18 ) ;
goto V_94;
}
}
V_18 = F_3 ( V_8 , V_10 , V_12 , & V_14 , V_84 -> V_38 , & V_16 , V_17 ) ;
if ( V_18 )
goto V_94;
if ( ( V_84 -> V_97 ) && ( V_84 -> V_97 -> V_101 . V_102 ) ) {
V_80 = V_84 -> V_97 -> V_101 . V_102 + F_28 ( V_12 ) ;
* V_80 = 0 ;
* V_80 |= V_10 -> V_38 & V_103 ;
if ( F_29 ( V_8 ) ) {
* V_80 |= ( ( T_3 ) V_10 -> V_2 &
V_104 ) <<
V_105 ;
}
if ( V_16 )
* V_80 |= ( V_106 <<
V_107 ) ;
}
return & V_10 -> V_108 ;
V_94:
F_30 ( V_8 , V_10 ) ;
V_91:
F_31 ( V_10 ) ;
return F_15 ( V_18 ) ;
}
int F_32 ( struct V_75 * V_108 )
{
struct V_9 * V_10 = F_33 ( V_108 ) ;
struct V_7 * V_8 = F_13 ( V_108 -> V_85 ) ;
F_30 ( V_8 , V_10 ) ;
F_31 ( V_10 ) ;
return 0 ;
}
int F_34 ( struct V_75 * V_108 , struct V_11 * V_12 )
{
struct V_9 * V_10 = F_33 ( V_108 ) ;
struct V_109 * V_53 = V_10 -> V_53 ;
struct V_21 * V_22 ;
V_12 -> type = V_108 -> type ;
if ( V_10 -> V_53 -> V_73 & V_110 ) {
V_22 = (struct V_21 * ) ( ( T_2 * ) V_10 -> V_53 +
sizeof( struct V_19 ) ) ;
F_35 ( V_12 , F_36 ( V_53 -> V_54 . V_17 ) >> 13 ) ;
} else {
V_22 = (struct V_21 * ) ( ( T_2 * ) V_10 -> V_53 +
sizeof( struct V_46 ) ) ;
F_35 ( V_12 , 0 ) ;
}
F_37 ( V_12 , NULL ,
F_38 ( V_22 -> V_70 ) & 0xffffffff ,
V_10 -> V_52 ,
F_38 ( V_22 -> V_72 ) & 0xff ,
F_38 ( V_22 -> V_70 ) >> 24 ) ;
F_39 ( V_12 , & V_22 -> V_67 [ 0 ] ) ;
return 0 ;
}
int F_40 ( struct V_75 * V_108 , struct V_11 * V_12 )
{
return - V_111 ;
}
int F_41 ( struct V_112 * V_92 ,
int V_113 ,
T_2 V_114 ,
const struct V_115 * V_116 ,
const struct V_29 * V_117 ,
const struct V_118 * V_119 , T_4 V_120 ,
struct V_118 * V_121 , T_4 * V_122 ,
T_1 * V_123 )
{
int V_18 ;
struct V_7 * V_8 ;
const struct V_124 * V_125 = ( const struct V_124 * ) V_119 ;
struct V_124 * V_126 = (struct V_124 * ) V_121 ;
if ( F_42 ( V_120 != sizeof( * V_125 ) ||
* V_122 != sizeof( * V_126 ) ) )
return V_127 ;
switch ( V_125 -> V_128 . V_129 ) {
case V_130 :
V_8 = F_13 ( V_92 ) ;
if ( ! F_43 ( V_8 , V_126 ) )
V_18 = V_131 | V_132 ;
else
V_18 = V_131 ;
break;
default:
V_18 = V_131 ;
break;
}
return V_18 ;
}
