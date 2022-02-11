static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
enum V_6 V_7 )
{
unsigned char V_8 [ 3 ] ;
unsigned long V_9 ;
int V_10 = 0 ;
switch( V_7 ) {
case V_11 :
V_8 [ 0 ] = 0x00 ;
break;
case V_12 :
V_8 [ 0 ] = 0x03 ;
break;
case V_13 :
V_8 [ 0 ] = 0x02 ;
break;
case V_14 :
V_8 [ 0 ] = 0x04 ;
break;
case V_15 :
V_8 [ 0 ] = 0x05 ;
break;
case V_16 :
V_8 [ 0 ] = 0x06 ;
break;
case V_17 :
V_8 [ 0 ] = 0x07 ;
break;
default:
return - V_18 ;
}
F_4 ( V_5 , V_8 , 1 ) ;
V_9 = V_19 + V_20 * 3 ;
for (; ; ) {
V_8 [ 0 ] = 0x10 ;
F_4 ( V_5 , V_8 , 1 ) ;
F_5 ( V_5 , V_8 , 1 ) ;
if ( ! ( V_8 [ 0 ] & 0x20 ) )
break;
if ( F_6 ( V_19 , V_9 ) ) {
V_10 = - V_21 ;
break;
}
F_7 ( 10 ) ;
}
F_7 ( 50 ) ;
return V_10 ;
}
static inline void F_8 ( struct V_4 * V_5 , T_1 V_22 , T_1 V_23 )
{
T_2 V_8 [ 2 ] ;
V_8 [ 0 ] = V_22 ;
V_8 [ 1 ] = V_23 ;
F_4 ( V_5 , V_8 , 2 ) ;
}
static inline void F_9 ( struct V_4 * V_5 , T_1 V_22 , T_3 V_23 )
{
T_2 V_8 [ 3 ] ;
V_8 [ 0 ] = V_22 ;
V_8 [ 1 ] = V_23 >> 8 ;
V_8 [ 2 ] = V_23 & 0xff ;
F_4 ( V_5 , V_8 , 3 ) ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_1 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_26 ;
int V_27 ;
int V_28 ;
F_8 ( V_5 , 0x71 ,
V_26 -> V_29 != V_30 ) ;
if ( V_26 -> V_29 == V_30 ) {
F_9 ( V_5 , 0x80 , V_26 -> V_31 ) ;
F_9 ( V_5 , 0x81 , V_26 -> V_32 ) ;
V_27 = V_26 -> V_32 ;
} else {
F_9 ( V_5 , 0x81 , V_26 -> V_31 ) ;
V_27 = V_26 -> V_31 ;
}
F_8 ( V_5 , 0x93 ,
V_26 -> V_33 == V_34 ) ;
if ( V_26 -> V_33 == V_34 )
V_28 = V_35 == V_26 -> V_36 ;
else
V_28 = V_37 == V_26 -> V_38 ;
F_8 ( V_5 , 0x94 , V_28 ) ;
V_27 += V_28 ? 384 : 256 ;
V_27 += 768 ;
if ( V_27 > V_39 )
V_27 = V_39 ;
F_9 ( V_5 , 0xb1 , V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_40 * V_41 )
{
struct V_1 * V_24 =
F_2 ( V_41 -> V_42 , struct V_1 , V_43 ) ;
switch ( V_41 -> V_44 ) {
case V_45 :
if ( V_41 -> V_23 == V_30 &&
V_24 -> V_46 -> V_23 < V_24 -> V_47 -> V_23 )
V_24 -> V_46 -> V_23 = V_24 -> V_47 -> V_23 ;
break;
}
return 0 ;
}
static int F_12 ( struct V_40 * V_41 )
{
struct V_1 * V_24 =
F_2 ( V_41 -> V_42 , struct V_1 , V_43 ) ;
struct V_25 * V_26 = & V_24 -> V_26 ;
switch ( V_41 -> V_44 ) {
case V_48 :
break;
case V_49 :
V_26 -> V_50 = V_41 -> V_23 ;
break;
case V_51 :
V_26 -> V_52 = V_41 -> V_23 ;
break;
case V_53 :
V_26 -> V_54 = V_41 -> V_23 ;
break;
case V_55 :
V_26 -> V_56 = V_41 -> V_23 ;
break;
case V_57 :
V_26 -> V_33 = V_41 -> V_23 ;
break;
case V_58 :
V_26 -> V_38 = V_41 -> V_23 ;
break;
case V_59 :
V_26 -> V_36 = V_41 -> V_23 ;
break;
case V_60 :
break;
case V_61 :
break;
case V_62 :
V_26 -> V_63 = V_41 -> V_23 ;
break;
case V_45 :
V_26 -> V_29 = V_41 -> V_23 ;
V_26 -> V_31 = V_24 -> V_47 -> V_23 / 1000 ;
V_26 -> V_32 = V_24 -> V_46 -> V_23 / 1000 ;
F_13 ( V_24 -> V_46 ,
V_41 -> V_23 == V_30 ) ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_4 V_64 )
{
unsigned char V_8 [ 9 ] , V_65 [ 4 ] ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_15 ( V_3 ) ;
unsigned V_66 ;
T_4 V_67 ;
unsigned char V_68 [ 256 ] ;
unsigned char V_69 [ 256 ] ;
F_8 ( V_5 , 0x41 , V_24 -> V_70 ) ;
F_8 ( V_5 , 0x40 , ( V_24 -> V_71 & V_72 ) ? 1 : 0 ) ;
F_10 ( V_5 , V_24 ) ;
F_9 ( V_5 , 0x72 , 0x030d ) ;
F_8 ( V_5 , 0x82 , 0x04 ) ;
F_8 ( V_5 , 0x83 , 0x0c ) ;
F_8 ( V_5 , 0xd0 , 0x81 ) ;
F_8 ( V_5 , 0xb0 , 0x05 ) ;
F_9 ( V_5 , 0xf6 , V_64 ) ;
memcpy ( V_68 , V_73 , sizeof( V_73 ) ) ;
V_68 [ 17 ] = 0xe0 | ( ( V_24 -> V_26 . V_50 >> 8 ) & 0x0f ) ;
V_68 [ 18 ] = V_24 -> V_26 . V_50 & 0xff ;
V_67 = F_16 ( ~ 0 , & V_68 [ 7 ] , sizeof( V_73 ) - 7 - 4 ) ;
V_68 [ sizeof( V_73 ) - 4 ] = ( V_67 >> 24 ) & 0xFF ;
V_68 [ sizeof( V_73 ) - 3 ] = ( V_67 >> 16 ) & 0xFF ;
V_68 [ sizeof( V_73 ) - 2 ] = ( V_67 >> 8 ) & 0xFF ;
V_68 [ sizeof( V_73 ) - 1 ] = V_67 & 0xFF ;
if ( V_24 -> V_26 . V_33 == V_34 ) {
V_66 = sizeof( V_74 ) ;
memcpy ( V_69 , V_74 , V_66 ) ;
} else {
V_66 = sizeof( V_75 ) ;
memcpy ( V_69 , V_75 , V_66 ) ;
}
V_69 [ 3 ] = 0x40 | ( ( V_24 -> V_26 . V_50 >> 8 ) & 0x0f ) ;
V_69 [ 4 ] = V_24 -> V_26 . V_50 & 0xff ;
V_69 [ 15 ] = 0xE0 | ( ( V_24 -> V_26 . V_56 >> 8 ) & 0x0F ) ;
V_69 [ 16 ] = V_24 -> V_26 . V_56 & 0xFF ;
V_69 [ 20 ] = 0xE0 | ( ( V_24 -> V_26 . V_54 >> 8 ) & 0x0F ) ;
V_69 [ 21 ] = V_24 -> V_26 . V_54 & 0xFF ;
V_69 [ 25 ] = 0xE0 | ( ( V_24 -> V_26 . V_52 >> 8 ) & 0x0F ) ;
V_69 [ 26 ] = V_24 -> V_26 . V_52 & 0xFF ;
V_67 = F_16 ( ~ 0 , & V_69 [ 7 ] , V_66 - 7 - 4 ) ;
V_69 [ V_66 - 4 ] = ( V_67 >> 24 ) & 0xFF ;
V_69 [ V_66 - 3 ] = ( V_67 >> 16 ) & 0xFF ;
V_69 [ V_66 - 2 ] = ( V_67 >> 8 ) & 0xFF ;
V_69 [ V_66 - 1 ] = V_67 & 0xFF ;
F_9 ( V_5 , 0xc1 , V_24 -> V_26 . V_52 ) ;
F_9 ( V_5 , 0xc0 , V_24 -> V_26 . V_54 ) ;
F_9 ( V_5 , 0xc4 , V_24 -> V_26 . V_56 ) ;
F_4 ( V_5 , V_68 , sizeof( V_73 ) ) ;
F_4 ( V_5 , V_69 , V_66 ) ;
F_8 ( V_5 , 0xa4 , 1 ) ;
F_8 ( V_5 , 0xa4 , 0 ) ;
F_3 ( V_5 , V_13 ) ;
V_8 [ 0 ] = 0xE1 ;
V_8 [ 1 ] = 0xA7 ;
V_8 [ 2 ] = 0xFE ;
V_8 [ 3 ] = 0x82 ;
V_8 [ 4 ] = 0xB0 ;
F_4 ( V_5 , V_8 , 5 ) ;
F_5 ( V_5 , V_65 , 4 ) ;
V_8 [ 0 ] = 0xE0 ;
V_8 [ 1 ] = 0xA7 ;
V_8 [ 2 ] = 0xFE ;
V_8 [ 3 ] = 0x82 ;
V_8 [ 4 ] = 0xB0 ;
V_8 [ 5 ] = V_65 [ 0 ] ;
switch ( V_24 -> V_26 . V_63 ) {
case V_76 :
V_8 [ 6 ] = V_65 [ 1 ] | 0x40 ;
break;
case V_77 :
default:
V_8 [ 6 ] = V_65 [ 1 ] & 0xBF ;
break;
}
V_8 [ 7 ] = V_65 [ 2 ] ;
V_8 [ 8 ] = V_65 [ 3 ] ;
F_4 ( V_5 , V_8 , 9 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_78 * V_79 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
if ( V_24 -> V_70 == V_80 )
V_24 -> V_70 = V_81 ;
V_79 -> V_82 = V_83 [ V_24 -> V_70 ] . V_84 . V_85 . V_82 ;
V_79 -> V_86 = V_83 [ V_24 -> V_70 ] . V_84 . V_85 . V_86 ;
V_79 -> V_87 = V_88 ;
V_79 -> V_89 = V_90 ;
V_79 -> V_91 = V_92 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_78 * V_79 )
{
int V_93 , V_94 , V_95 ;
V_79 -> V_87 = V_88 ;
V_93 = abs ( V_79 -> V_82 - 352 ) ;
V_94 = abs ( V_79 -> V_82 - 480 ) ;
V_95 = abs ( V_79 -> V_82 - 720 ) ;
if ( V_95 < V_94 ) {
V_79 -> V_82 = 720 ;
V_79 -> V_86 = 576 ;
} else if ( V_94 < V_93 ) {
V_79 -> V_82 = 480 ;
V_79 -> V_86 = 576 ;
} else {
V_79 -> V_82 = 352 ;
if ( abs ( V_79 -> V_86 - 576 ) < abs ( V_79 -> V_86 - 288 ) )
V_79 -> V_86 = 576 ;
else
V_79 -> V_86 = 288 ;
}
V_79 -> V_89 = V_90 ;
V_79 -> V_91 = V_92 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_78 * V_79 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
if ( V_79 -> V_87 != V_88 )
return - V_18 ;
F_18 ( V_3 , V_79 ) ;
if ( V_79 -> V_82 == 720 )
V_24 -> V_70 = V_81 ;
else if ( V_79 -> V_82 == 480 )
V_24 -> V_70 = V_96 ;
else if ( V_79 -> V_86 == 576 )
V_24 -> V_70 = V_97 ;
else
V_24 -> V_70 = V_98 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , T_5 V_99 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
V_24 -> V_71 = V_99 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 ,
const struct V_100 * V_44 )
{
struct V_1 * V_24 ;
struct V_2 * V_3 ;
struct V_101 * V_43 ;
T_2 V_102 = 0x13 ;
T_2 V_103 [ 12 ] ;
F_22 ( V_5 , L_1 ,
V_5 -> V_102 << 1 , V_5 -> V_104 -> V_105 ) ;
V_24 = F_23 ( & V_5 -> V_106 , sizeof( * V_24 ) , V_107 ) ;
if ( V_24 == NULL )
return - V_108 ;
V_3 = & V_24 -> V_3 ;
F_24 ( V_3 , V_5 , & V_109 ) ;
F_4 ( V_5 , & V_102 , 1 ) ;
F_5 ( V_5 , V_103 , sizeof( V_103 ) ) ;
V_24 -> V_110 = ( V_103 [ 8 ] << 8 ) | V_103 [ 9 ] ;
V_24 -> V_111 = 0 ;
if ( V_24 -> V_110 == 0x0206 ) {
V_24 -> V_111 = 1 ;
F_22 ( V_5 , L_2 ) ;
}
V_24 -> V_26 = V_112 ;
V_43 = & V_24 -> V_43 ;
F_25 ( V_43 , 14 ) ;
F_26 ( V_43 , & V_113 ,
V_57 ,
V_24 -> V_111 ? V_34 :
V_114 ,
0x0d , V_114 ) ;
F_26 ( V_43 , & V_113 ,
V_58 ,
V_37 ,
~ ( ( 1 << V_115 ) |
( 1 << V_37 ) ) ,
V_115 ) ;
if ( V_24 -> V_111 )
F_26 ( V_43 , & V_113 ,
V_59 ,
V_35 ,
~ ( ( 1 << V_116 ) |
( 1 << V_35 ) ) ,
V_116 ) ;
F_26 ( V_43 , & V_113 ,
V_60 ,
V_117 ,
~ ( 1 << V_117 ) ,
V_117 ) ;
F_26 ( V_43 , & V_113 ,
V_61 ,
V_118 ,
~ ( 1 << V_118 ) ,
V_118 ) ;
F_26 ( V_43 , & V_113 ,
V_62 ,
V_76 , 0x01 ,
V_77 ) ;
V_24 -> V_46 = F_27 ( V_43 , & V_113 ,
V_119 ,
1000000 , 27000000 , 1000 , 8000000 ) ;
F_26 ( V_43 , & V_113 ,
V_48 ,
V_120 ,
~ ( 1 << V_120 ) ,
V_120 ) ;
V_24 -> V_121 = F_26 ( V_43 , & V_113 ,
V_45 ,
V_122 , 0 ,
V_30 ) ;
V_24 -> V_47 = F_27 ( V_43 , & V_113 ,
V_123 , 1000000 , 27000000 , 1000 , 6000000 ) ;
F_27 ( V_43 , & V_113 ,
V_49 , 0 , ( 1 << 14 ) - 1 , 1 , 16 ) ;
F_27 ( V_43 , & V_113 ,
V_51 , 0 , ( 1 << 14 ) - 1 , 1 , 260 ) ;
F_27 ( V_43 , & V_113 ,
V_53 , 0 , ( 1 << 14 ) - 1 , 1 , 256 ) ;
F_27 ( V_43 , & V_113 ,
V_55 , 0 , ( 1 << 14 ) - 1 , 1 , 259 ) ;
V_3 -> V_124 = V_43 ;
if ( V_43 -> error ) {
int V_125 = V_43 -> error ;
F_28 ( V_43 ) ;
return V_125 ;
}
F_29 ( 3 , & V_24 -> V_121 ) ;
F_30 ( V_43 ) ;
V_24 -> V_71 = 0 ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_32 ( V_5 ) ;
F_33 ( V_3 ) ;
F_28 ( & F_1 ( V_3 ) -> V_43 ) ;
return 0 ;
}
