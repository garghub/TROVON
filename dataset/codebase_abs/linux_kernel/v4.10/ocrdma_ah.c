static T_1 F_1 ( int V_1 , T_2 V_2 )
{
switch ( V_2 ) {
case V_3 :
return ( T_1 ) 0x8915 ;
case V_4 :
return ( T_1 ) 0x0800 ;
case V_5 :
return ( T_1 ) 0x86dd ;
default:
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
}
static inline int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , union V_12 * V_13 ,
int V_14 , bool * V_15 , T_1 V_16 )
{
int V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 ;
T_1 V_23 = 0 ;
T_2 V_24 = 0x11 ;
struct V_25 V_26 ;
union {
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
} V_33 , V_34 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_23 = F_1 ( V_7 -> V_35 , V_9 -> V_2 ) ;
if ( ! V_23 )
return - V_36 ;
V_24 = ( V_23 == 0x8915 ) ? 0x1b : 0x11 ;
if ( ! V_16 || ( V_16 > 0xFFF ) )
V_16 = V_7 -> V_37 ;
if ( V_16 || V_7 -> V_38 ) {
if ( ! V_16 ) {
F_2 ( L_2 ,
V_7 -> V_35 ) ;
F_2 ( L_3 ,
V_7 -> V_35 ) ;
}
V_19 . V_39 = F_4 ( 0x8100 ) ;
V_19 . V_40 = F_4 ( V_23 ) ;
V_16 |= ( V_7 -> V_41 & 0x07 ) << V_42 ;
V_19 . V_16 = F_4 ( V_16 ) ;
V_22 = sizeof( struct V_18 ) ;
* V_15 = true ;
} else {
V_19 . V_39 = F_4 ( V_23 ) ;
V_22 = sizeof( struct V_43 ) ;
}
memcpy ( & V_19 . V_44 [ 0 ] , & V_7 -> V_45 . V_46 [ 0 ] , V_47 ) ;
V_17 = F_5 ( V_7 , V_11 , & V_19 . V_48 [ 0 ] ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_49 = V_11 -> V_21 . V_49 ;
memcpy ( & V_9 -> V_50 -> V_51 , & V_19 , V_22 ) ;
if ( V_9 -> V_2 == V_52 ) {
* ( ( V_53 * ) & V_26 ) = F_6 ( ( 4 << 12 ) | ( 5 << 8 ) |
V_11 -> V_21 . V_54 ) ;
V_26 . V_35 = F_4 ( V_14 ) ;
V_26 . V_55 = F_6 ( V_56 ) ;
V_26 . V_57 = F_6 ( 0 ) ;
V_26 . V_58 = V_11 -> V_21 . V_59 ;
V_26 . V_60 = V_24 ;
F_7 ( & V_33 . V_28 , V_13 ) ;
V_26 . V_61 = V_33 . V_30 . V_62 . V_63 ;
F_7 ( & V_34 . V_28 , & V_11 -> V_21 . V_64 ) ;
V_26 . V_65 = V_34 . V_30 . V_62 . V_63 ;
memcpy ( ( T_2 * ) V_9 -> V_50 + V_22 , & V_26 , sizeof( struct V_25 ) ) ;
} else {
memcpy ( & V_21 . V_13 [ 0 ] , V_13 -> V_66 , sizeof( union V_12 ) ) ;
V_21 . V_67 = F_8 ( ( 6 << 28 ) |
( V_11 -> V_21 . V_54 << 24 ) |
V_11 -> V_21 . V_68 ) ;
memcpy ( & V_21 . V_64 [ 0 ] , V_11 -> V_21 . V_64 . V_66 ,
sizeof( V_11 -> V_21 . V_64 . V_66 ) ) ;
V_21 . V_69 = F_8 ( ( V_14 << 16 ) |
( V_24 << 8 ) |
V_11 -> V_21 . V_59 ) ;
memcpy ( ( T_2 * ) V_9 -> V_50 + V_22 , & V_21 , sizeof( struct V_20 ) ) ;
}
if ( * V_15 )
V_9 -> V_50 -> V_70 |= V_71 ;
V_9 -> V_50 -> V_70 = F_9 ( V_9 -> V_50 -> V_70 ) ;
return V_17 ;
}
struct V_72 * F_10 ( struct V_73 * V_74 , struct V_10 * V_11 ,
struct V_75 * V_76 )
{
T_3 * V_77 ;
int V_17 ;
struct V_8 * V_9 ;
bool V_15 = false ;
T_1 V_16 = 0xffff ;
struct V_78 V_79 ;
struct V_80 * V_81 = F_11 ( V_74 ) ;
struct V_6 * V_7 = F_12 ( V_74 -> V_82 ) ;
union V_12 V_13 ;
if ( ! ( V_11 -> V_83 & V_84 ) )
return F_13 ( - V_36 ) ;
if ( F_14 ( & V_7 -> V_85 , 1 , 0 ) )
F_15 ( V_7 ) ;
V_9 = F_16 ( sizeof( * V_9 ) , V_86 ) ;
if ( ! V_9 )
return F_13 ( - V_87 ) ;
V_17 = F_17 ( V_7 , V_9 ) ;
if ( V_17 )
goto V_88;
V_17 = F_18 ( & V_7 -> V_89 , 1 , V_11 -> V_21 . V_49 , & V_13 ,
& V_79 ) ;
if ( V_17 ) {
F_2 ( L_4 ,
V_90 , V_17 ) ;
goto V_91;
}
if ( V_79 . V_92 ) {
if ( F_19 ( V_79 . V_92 ) )
V_16 = F_20 ( V_79 . V_92 ) ;
F_21 ( V_79 . V_92 ) ;
}
V_9 -> V_2 = F_22 ( V_79 . V_93 , & V_13 ) ;
if ( ( V_81 -> V_94 ) &&
( ! F_23 ( (struct V_95 * ) V_11 -> V_21 . V_64 . V_66 ) ) &&
( ! F_24 ( (struct V_95 * ) V_11 -> V_21 . V_64 . V_66 ) ) ) {
V_17 = F_25 ( & V_13 , & V_11 -> V_21 . V_64 ,
V_11 -> V_48 , & V_16 ,
& V_79 . V_92 -> V_96 ,
NULL ) ;
if ( V_17 ) {
F_2 ( L_5
L_6 , V_90 , V_17 ) ;
goto V_91;
}
}
V_17 = F_3 ( V_7 , V_9 , V_11 , & V_13 , V_81 -> V_35 , & V_15 , V_16 ) ;
if ( V_17 )
goto V_91;
if ( ( V_81 -> V_94 ) && ( V_81 -> V_94 -> V_97 . V_98 ) ) {
V_77 = V_81 -> V_94 -> V_97 . V_98 + V_11 -> V_99 ;
* V_77 = 0 ;
* V_77 |= V_9 -> V_35 & V_100 ;
if ( F_26 ( V_7 ) ) {
* V_77 |= ( ( T_3 ) V_9 -> V_2 &
V_101 ) <<
V_102 ;
}
if ( V_15 )
* V_77 |= ( V_103 <<
V_104 ) ;
}
return & V_9 -> V_105 ;
V_91:
F_27 ( V_7 , V_9 ) ;
V_88:
F_28 ( V_9 ) ;
return F_13 ( V_17 ) ;
}
int F_29 ( struct V_72 * V_105 )
{
struct V_8 * V_9 = F_30 ( V_105 ) ;
struct V_6 * V_7 = F_12 ( V_105 -> V_82 ) ;
F_27 ( V_7 , V_9 ) ;
F_28 ( V_9 ) ;
return 0 ;
}
int F_31 ( struct V_72 * V_105 , struct V_10 * V_11 )
{
struct V_8 * V_9 = F_30 ( V_105 ) ;
struct V_106 * V_50 = V_9 -> V_50 ;
struct V_20 * V_21 ;
V_11 -> V_83 |= V_84 ;
if ( V_9 -> V_50 -> V_70 & V_107 ) {
V_21 = (struct V_20 * ) ( ( T_2 * ) V_9 -> V_50 +
sizeof( struct V_18 ) ) ;
V_11 -> V_41 = F_32 ( V_50 -> V_51 . V_16 ) >> 13 ;
} else {
V_21 = (struct V_20 * ) ( ( T_2 * ) V_9 -> V_50 +
sizeof( struct V_43 ) ) ;
V_11 -> V_41 = 0 ;
}
memcpy ( & V_11 -> V_21 . V_64 . V_66 [ 0 ] , & V_21 -> V_64 [ 0 ] , sizeof( V_21 -> V_64 ) ) ;
V_11 -> V_21 . V_49 = V_9 -> V_49 ;
V_11 -> V_21 . V_59 = F_33 ( V_21 -> V_69 ) & 0xff ;
V_11 -> V_21 . V_54 = F_33 ( V_21 -> V_67 ) >> 24 ;
V_11 -> V_21 . V_68 = F_33 ( V_21 -> V_67 ) & 0x00ffffffff ;
return 0 ;
}
int F_34 ( struct V_72 * V_105 , struct V_10 * V_11 )
{
return - V_108 ;
}
int F_35 ( struct V_109 * V_89 ,
int V_110 ,
T_2 V_111 ,
const struct V_112 * V_113 ,
const struct V_114 * V_115 ,
const struct V_116 * V_117 , T_4 V_118 ,
struct V_116 * V_119 , T_4 * V_120 ,
T_1 * V_121 )
{
int V_17 ;
struct V_6 * V_7 ;
const struct V_122 * V_123 = ( const struct V_122 * ) V_117 ;
struct V_122 * V_124 = (struct V_122 * ) V_119 ;
if ( F_36 ( V_118 != sizeof( * V_123 ) ||
* V_120 != sizeof( * V_124 ) ) )
return V_125 ;
switch ( V_123 -> V_126 . V_127 ) {
case V_128 :
V_7 = F_12 ( V_89 ) ;
if ( ! F_37 ( V_7 , V_124 ) )
V_17 = V_129 | V_130 ;
else
V_17 = V_129 ;
break;
default:
V_17 = V_129 ;
break;
}
return V_17 ;
}
