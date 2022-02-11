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
static int F_11 ( int V_40 , struct V_25 * V_26 ,
struct V_41 * V_42 )
{
switch ( V_42 -> V_43 ) {
case V_44 :
V_42 -> V_45 = V_46 ;
break;
case V_47 :
V_42 -> V_45 = V_26 -> V_48 ;
break;
case V_49 :
V_42 -> V_45 = V_26 -> V_50 ;
break;
case V_51 :
V_42 -> V_45 = V_26 -> V_52 ;
break;
case V_53 :
V_42 -> V_45 = V_26 -> V_54 ;
break;
case V_55 :
V_42 -> V_45 = V_26 -> V_33 ;
break;
case V_56 :
V_42 -> V_45 = V_26 -> V_38 ;
break;
case V_57 :
if ( ! V_40 )
return - V_18 ;
V_42 -> V_45 = V_26 -> V_36 ;
break;
case V_58 :
V_42 -> V_45 = V_59 ;
break;
case V_60 :
V_42 -> V_45 = V_61 ;
break;
case V_62 :
V_42 -> V_45 = V_26 -> V_63 ;
break;
case V_64 :
V_42 -> V_45 = V_26 -> V_31 * 1000 ;
break;
case V_65 :
V_42 -> V_45 = V_26 -> V_32 * 1000 ;
break;
case V_66 :
V_42 -> V_45 = V_26 -> V_29 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_12 ( int V_40 , struct V_25 * V_26 ,
struct V_41 * V_42 , int V_67 )
{
int V_68 = 0 , V_69 ;
V_69 = V_42 -> V_45 ;
switch ( V_42 -> V_43 ) {
case V_44 :
V_68 = V_46 ;
if ( V_67 && V_69 != V_68 )
return - V_70 ;
V_69 = V_68 ;
break;
case V_47 :
V_68 = V_26 -> V_48 ;
if ( V_67 && V_69 > V_71 )
return - V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_26 -> V_48 = V_69 ;
break;
case V_49 :
V_68 = V_26 -> V_50 ;
if ( V_67 && V_69 > V_71 )
return - V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_26 -> V_50 = V_69 ;
break;
case V_51 :
V_68 = V_26 -> V_52 ;
if ( V_67 && V_69 > V_71 )
return - V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_26 -> V_52 = V_69 ;
break;
case V_53 :
V_68 = V_26 -> V_54 ;
if ( V_67 && V_69 > V_71 )
return - V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_26 -> V_54 = V_69 ;
break;
case V_55 :
V_68 = V_26 -> V_33 ;
if ( V_67 && V_69 != V_72 &&
( ! V_40 || V_69 != V_34 ) )
return - V_70 ;
V_26 -> V_33 = V_69 ;
break;
case V_56 :
V_68 = V_26 -> V_38 ;
if ( V_67 && V_69 != V_73 &&
V_69 != V_37 )
return - V_70 ;
if ( V_69 <= V_73 )
V_69 = V_73 ;
else
V_69 = V_37 ;
V_26 -> V_38 = V_69 ;
break;
case V_57 :
if ( ! V_40 )
return - V_18 ;
V_68 = V_26 -> V_36 ;
if ( V_67 && V_69 != V_74 &&
V_69 != V_35 )
return - V_70 ;
if ( V_69 <= V_74 )
V_69 = V_74 ;
else
V_69 = V_35 ;
V_26 -> V_36 = V_69 ;
break;
case V_58 :
V_68 = V_59 ;
if ( V_67 && V_69 != V_68 )
return - V_70 ;
V_69 = V_68 ;
break;
case V_60 :
V_68 = V_61 ;
if ( V_67 && V_69 != V_68 )
return - V_70 ;
V_69 = V_68 ;
break;
case V_62 :
V_68 = V_26 -> V_63 ;
if ( V_67 && V_69 != V_75 &&
V_69 != V_76 )
return - V_70 ;
if ( V_69 != V_75 )
V_69 = V_76 ;
V_26 -> V_63 = V_69 ;
break;
case V_64 :
V_68 = V_26 -> V_31 * 1000 ;
V_69 = 1000 * ( V_69 / 1000 ) ;
if ( V_67 && V_69 > V_77 * 1000 )
return - V_70 ;
if ( V_69 > V_77 * 1000 )
V_69 = V_77 * 1000 ;
V_26 -> V_31 = V_69 / 1000 ;
break;
case V_65 :
V_68 = V_26 -> V_32 * 1000 ;
V_69 = 1000 * ( V_69 / 1000 ) ;
if ( V_67 && V_69 > V_77 * 1000 )
return - V_70 ;
if ( V_69 > V_77 * 1000 )
V_69 = V_77 * 1000 ;
V_26 -> V_32 = V_69 / 1000 ;
break;
case V_66 :
V_68 = V_26 -> V_29 ;
V_26 -> V_29 = V_69 ;
break;
default:
return - V_18 ;
}
V_42 -> V_45 = V_69 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_78 * V_79 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_25 * V_26 = & V_24 -> V_26 ;
int V_80 ;
switch ( V_79 -> V_43 ) {
case V_55 :
return F_14 ( V_79 ,
V_72 ,
V_24 -> V_40 ? V_34 :
V_72 ,
1 , V_72 ) ;
case V_56 :
return F_14 ( V_79 ,
V_73 ,
V_37 , 1 ,
V_73 ) ;
case V_57 :
if ( ! V_24 -> V_40 )
return - V_18 ;
return F_14 ( V_79 ,
V_74 ,
V_35 , 1 ,
V_74 ) ;
case V_58 :
return F_14 ( V_79 ,
V_59 ,
V_59 , 1 ,
V_59 ) ;
case V_60 :
return F_14 ( V_79 ,
V_61 ,
V_61 , 1 ,
V_61 ) ;
case V_62 :
return F_14 ( V_79 ,
V_76 ,
V_75 , 1 ,
V_76 ) ;
case V_65 :
V_80 = F_14 ( V_79 , 0 , 27000000 , 1 , 8000000 ) ;
if ( V_80 == 0 &&
V_26 -> V_29 ==
V_81 )
V_79 -> V_82 |= V_83 ;
return V_80 ;
case V_44 :
return F_14 ( V_79 ,
V_46 ,
V_46 , 1 ,
V_46 ) ;
case V_66 :
return F_14 ( V_79 ,
V_30 ,
V_81 , 1 ,
V_30 ) ;
case V_64 :
return F_14 ( V_79 , 0 , 27000000 , 1 , 6000000 ) ;
case V_47 :
return F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 16 ) ;
case V_49 :
return F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 260 ) ;
case V_51 :
return F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 256 ) ;
case V_53 :
return F_14 ( V_79 , 0 , ( 1 << 14 ) - 1 , 1 , 259 ) ;
default:
break;
}
return - V_18 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_84 * V_85 )
{
static const T_4 V_86 [] = {
V_72 ,
V_87
} ;
static const T_4 V_88 [] = {
V_72 ,
V_34 ,
V_87
} ;
static T_4 V_89 [] = {
V_73 ,
V_37 ,
V_87
} ;
static T_4 V_90 [] = {
V_74 ,
V_35 ,
V_87
} ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_78 V_79 ;
int V_80 ;
V_79 . V_43 = V_85 -> V_43 ;
V_80 = F_13 ( V_3 , & V_79 ) ;
if ( V_80 )
return V_80 ;
switch ( V_85 -> V_43 ) {
case V_56 :
return F_16 ( V_85 ,
V_89 ) ;
case V_57 :
if ( ! V_24 -> V_40 )
return - V_18 ;
return F_16 ( V_85 ,
V_90 ) ;
case V_55 :
return F_16 ( V_85 ,
V_24 -> V_40 ? V_88 :
V_86 ) ;
}
return F_17 ( V_85 , & V_79 , NULL ) ;
}
static int F_18 ( struct V_2 * V_3 , T_4 V_91 )
{
unsigned char V_8 [ 9 ] , V_92 [ 4 ] ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_19 ( V_3 ) ;
unsigned V_93 ;
T_4 V_94 ;
unsigned char V_95 [ 256 ] ;
unsigned char V_96 [ 256 ] ;
F_8 ( V_5 , 0x41 , V_24 -> V_97 ) ;
F_8 ( V_5 , 0x40 , ( V_24 -> V_98 & V_99 ) ? 1 : 0 ) ;
F_10 ( V_5 , V_24 ) ;
F_9 ( V_5 , 0x72 , 0x030d ) ;
F_8 ( V_5 , 0x82 , 0x04 ) ;
F_8 ( V_5 , 0x83 , 0x0c ) ;
F_8 ( V_5 , 0xd0 , 0x81 ) ;
F_8 ( V_5 , 0xb0 , 0x05 ) ;
F_9 ( V_5 , 0xf6 , V_91 ) ;
memcpy ( V_95 , V_100 , sizeof( V_100 ) ) ;
V_95 [ 17 ] = 0xe0 | ( ( V_24 -> V_26 . V_48 >> 8 ) & 0x0f ) ;
V_95 [ 18 ] = V_24 -> V_26 . V_48 & 0xff ;
V_94 = F_20 ( ~ 0 , & V_95 [ 7 ] , sizeof( V_100 ) - 7 - 4 ) ;
V_95 [ sizeof( V_100 ) - 4 ] = ( V_94 >> 24 ) & 0xFF ;
V_95 [ sizeof( V_100 ) - 3 ] = ( V_94 >> 16 ) & 0xFF ;
V_95 [ sizeof( V_100 ) - 2 ] = ( V_94 >> 8 ) & 0xFF ;
V_95 [ sizeof( V_100 ) - 1 ] = V_94 & 0xFF ;
if ( V_24 -> V_26 . V_33 == V_34 ) {
V_93 = sizeof( V_101 ) ;
memcpy ( V_96 , V_101 , V_93 ) ;
} else {
V_93 = sizeof( V_102 ) ;
memcpy ( V_96 , V_102 , V_93 ) ;
}
V_96 [ 3 ] = 0x40 | ( ( V_24 -> V_26 . V_48 >> 8 ) & 0x0f ) ;
V_96 [ 4 ] = V_24 -> V_26 . V_48 & 0xff ;
V_96 [ 15 ] = 0xE0 | ( ( V_24 -> V_26 . V_54 >> 8 ) & 0x0F ) ;
V_96 [ 16 ] = V_24 -> V_26 . V_54 & 0xFF ;
V_96 [ 20 ] = 0xE0 | ( ( V_24 -> V_26 . V_52 >> 8 ) & 0x0F ) ;
V_96 [ 21 ] = V_24 -> V_26 . V_52 & 0xFF ;
V_96 [ 25 ] = 0xE0 | ( ( V_24 -> V_26 . V_50 >> 8 ) & 0x0F ) ;
V_96 [ 26 ] = V_24 -> V_26 . V_50 & 0xFF ;
V_94 = F_20 ( ~ 0 , & V_96 [ 7 ] , V_93 - 7 - 4 ) ;
V_96 [ V_93 - 4 ] = ( V_94 >> 24 ) & 0xFF ;
V_96 [ V_93 - 3 ] = ( V_94 >> 16 ) & 0xFF ;
V_96 [ V_93 - 2 ] = ( V_94 >> 8 ) & 0xFF ;
V_96 [ V_93 - 1 ] = V_94 & 0xFF ;
F_9 ( V_5 , 0xc1 , V_24 -> V_26 . V_50 ) ;
F_9 ( V_5 , 0xc0 , V_24 -> V_26 . V_52 ) ;
F_9 ( V_5 , 0xc4 , V_24 -> V_26 . V_54 ) ;
F_4 ( V_5 , V_95 , sizeof( V_100 ) ) ;
F_4 ( V_5 , V_96 , V_93 ) ;
F_8 ( V_5 , 0xa4 , 1 ) ;
F_8 ( V_5 , 0xa4 , 0 ) ;
F_3 ( V_5 , V_13 ) ;
V_8 [ 0 ] = 0xE1 ;
V_8 [ 1 ] = 0xA7 ;
V_8 [ 2 ] = 0xFE ;
V_8 [ 3 ] = 0x82 ;
V_8 [ 4 ] = 0xB0 ;
F_4 ( V_5 , V_8 , 5 ) ;
F_5 ( V_5 , V_92 , 4 ) ;
V_8 [ 0 ] = 0xE0 ;
V_8 [ 1 ] = 0xA7 ;
V_8 [ 2 ] = 0xFE ;
V_8 [ 3 ] = 0x82 ;
V_8 [ 4 ] = 0xB0 ;
V_8 [ 5 ] = V_92 [ 0 ] ;
switch ( V_24 -> V_26 . V_63 ) {
case V_75 :
V_8 [ 6 ] = V_92 [ 1 ] | 0x40 ;
break;
case V_76 :
default:
V_8 [ 6 ] = V_92 [ 1 ] & 0xBF ;
break;
}
V_8 [ 7 ] = V_92 [ 2 ] ;
V_8 [ 8 ] = V_92 [ 3 ] ;
F_4 ( V_5 , V_8 , 9 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_103 * V_104 , int V_67 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_25 V_26 ;
int V_105 ;
if ( V_104 -> V_106 != V_107 )
return - V_18 ;
V_26 = V_24 -> V_26 ;
for ( V_105 = 0 ; V_105 < V_104 -> V_108 ; V_105 ++ ) {
int V_80 = F_12 ( V_24 -> V_40 , & V_26 , V_104 -> V_109 + V_105 , V_67 ) ;
if ( V_80 ) {
V_104 -> V_110 = V_105 ;
return V_80 ;
}
}
if ( V_67 )
V_24 -> V_26 = V_26 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_103 * V_104 )
{
return F_21 ( V_3 , V_104 , 1 ) ;
}
static int F_23 ( struct V_2 * V_3 , struct V_103 * V_104 )
{
return F_21 ( V_3 , V_104 , 0 ) ;
}
static int F_24 ( struct V_2 * V_3 , struct V_103 * V_104 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
int V_105 ;
if ( V_104 -> V_106 != V_107 )
return - V_18 ;
for ( V_105 = 0 ; V_105 < V_104 -> V_108 ; V_105 ++ ) {
int V_80 = F_11 ( V_24 -> V_40 , & V_24 -> V_26 , V_104 -> V_109 + V_105 ) ;
if ( V_80 ) {
V_104 -> V_110 = V_105 ;
return V_80 ;
}
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_111 * V_112 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
if ( V_24 -> V_97 == V_113 )
V_24 -> V_97 = V_114 ;
V_112 -> V_115 = V_116 [ V_24 -> V_97 ] . V_117 . V_118 . V_115 ;
V_112 -> V_119 = V_116 [ V_24 -> V_97 ] . V_117 . V_118 . V_119 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = V_123 ;
V_112 -> V_124 = V_125 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_111 * V_112 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
int V_126 , V_127 , V_128 ;
if ( V_112 -> V_120 != V_121 )
return - V_18 ;
V_126 = abs ( V_112 -> V_115 - 352 ) ;
V_127 = abs ( V_112 -> V_115 - 480 ) ;
V_128 = abs ( V_112 -> V_115 - 720 ) ;
if ( V_128 < V_127 ) {
V_112 -> V_115 = 720 ;
V_112 -> V_119 = 576 ;
V_24 -> V_97 = V_114 ;
} else if ( V_127 < V_126 ) {
V_112 -> V_115 = 480 ;
V_112 -> V_119 = 576 ;
V_24 -> V_97 = V_129 ;
} else {
V_112 -> V_115 = 352 ;
if ( abs ( V_112 -> V_119 - 576 ) <
abs ( V_112 -> V_119 - 288 ) ) {
V_112 -> V_119 = 576 ;
V_24 -> V_97 = V_130 ;
} else {
V_112 -> V_119 = 288 ;
V_24 -> V_97 = V_131 ;
}
}
V_112 -> V_122 = V_123 ;
V_112 -> V_124 = V_125 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , T_5 V_132 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
V_24 -> V_98 = V_132 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_133 * V_134 )
{
struct V_4 * V_5 = F_19 ( V_3 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
return F_29 ( V_5 ,
V_134 , V_24 -> V_134 , V_24 -> V_135 ) ;
}
static int F_30 ( struct V_4 * V_5 ,
const struct V_136 * V_43 )
{
struct V_1 * V_24 = F_31 ( sizeof( * V_24 ) , V_137 ) ;
struct V_2 * V_3 ;
T_2 V_138 = 0x13 ;
T_2 V_139 [ 12 ] ;
F_32 ( V_5 , L_1 ,
V_5 -> V_138 << 1 , V_5 -> V_140 -> V_141 ) ;
if ( V_24 == NULL )
return - V_142 ;
V_3 = & V_24 -> V_3 ;
F_33 ( V_3 , V_5 , & V_143 ) ;
F_4 ( V_5 , & V_138 , 1 ) ;
F_5 ( V_5 , V_139 , sizeof( V_139 ) ) ;
V_24 -> V_134 = V_144 ;
V_24 -> V_135 = ( V_139 [ 8 ] << 8 ) | V_139 [ 9 ] ;
V_24 -> V_40 = 0 ;
if ( V_24 -> V_135 == 0x0206 ) {
V_24 -> V_134 = V_145 ;
V_24 -> V_40 = 1 ;
F_32 ( V_5 , L_2 ) ;
}
V_24 -> V_26 = V_146 ;
V_24 -> V_98 = 0 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_35 ( V_5 ) ;
F_36 ( V_3 ) ;
F_37 ( F_1 ( V_3 ) ) ;
return 0 ;
}
