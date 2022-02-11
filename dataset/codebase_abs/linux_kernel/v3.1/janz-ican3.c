static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_3 >= V_4 ) ;
F_3 ( V_3 , & V_2 -> V_5 -> V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned int V_9 , V_10 ;
T_1 V_11 , V_12 , V_13 ;
F_1 ( V_2 , V_14 ) ;
V_12 = F_5 ( V_2 -> V_15 + V_16 ) ;
V_11 = F_5 ( V_2 -> V_15 + V_17 ) ;
V_13 = V_11 ^ V_12 ;
if ( ( V_13 & V_18 ) == 0x00 ) {
F_6 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
if ( ( V_13 & V_18 ) == V_18 )
V_9 = ( V_13 & V_21 ) ? V_22 : V_23 ;
else
V_9 = ( V_13 & V_22 ) ? V_22 : V_23 ;
V_10 = ( V_9 == V_22 ) ? V_24 : V_25 ;
F_1 ( V_2 , V_10 ) ;
F_7 ( V_8 , V_2 -> V_15 , sizeof( * V_8 ) ) ;
V_11 ^= V_9 ;
F_1 ( V_2 , V_14 ) ;
F_3 ( V_11 , V_2 -> V_15 + V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned int V_9 , V_10 ;
T_1 V_11 , V_12 , V_13 ;
F_1 ( V_2 , V_14 ) ;
V_12 = F_5 ( V_2 -> V_15 + V_16 ) ;
V_11 = F_5 ( V_2 -> V_15 + V_17 ) ;
V_13 = V_11 ^ V_12 ;
if ( ( V_13 & V_26 ) == V_26 ) {
F_9 ( V_2 -> V_19 , L_2 ) ;
return - V_20 ;
}
V_9 = ( V_13 & V_27 ) ? V_28 : V_27 ;
V_10 = ( V_9 == V_27 ) ? V_29 : V_30 ;
F_1 ( V_2 , V_10 ) ;
F_10 ( V_2 -> V_15 , V_8 , sizeof( * V_8 ) ) ;
V_11 ^= V_9 ;
if ( V_9 == V_28 )
V_11 |= V_31 ;
F_1 ( V_2 , V_14 ) ;
F_3 ( V_11 , V_2 -> V_15 + V_17 ) ;
return 0 ;
}
static void T_2 F_11 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
unsigned long V_34 ;
void T_3 * V_35 ;
int V_36 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
F_1 ( V_2 , V_40 ) ;
V_35 = V_2 -> V_15 ;
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ ) {
V_33 . V_42 = V_43 | F_13 ( 1 ) ;
V_33 . V_44 = V_2 -> V_45 ;
if ( V_36 == V_41 - 1 )
V_33 . V_42 |= V_46 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_35 += sizeof( V_33 ) ;
V_2 -> V_45 ++ ;
}
F_1 ( V_2 , V_47 ) ;
V_35 = V_2 -> V_15 ;
V_2 -> V_48 = 0 ;
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ ) {
V_33 . V_42 = V_49 | F_13 ( 1 ) ;
V_33 . V_44 = V_2 -> V_45 ;
if ( V_36 == V_41 - 1 )
V_33 . V_42 |= V_46 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_35 += sizeof( V_33 ) ;
V_2 -> V_45 ++ ;
}
F_1 ( V_2 , V_50 ) ;
V_35 = V_2 -> V_15 ;
V_33 . V_42 = V_49 | V_46 | F_13 ( 1 ) ;
V_33 . V_44 = V_2 -> V_45 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_45 ++ ;
F_1 ( V_2 , V_51 ) ;
V_35 = V_2 -> V_15 ;
V_33 . V_42 = V_49 | V_46 | F_13 ( 1 ) ;
V_33 . V_44 = V_2 -> V_45 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_45 ++ ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
}
static void T_2 F_15 ( struct V_1 * V_2 )
{
struct V_52 V_33 ;
unsigned long V_34 ;
unsigned int V_53 ;
void T_3 * V_35 ;
int V_36 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
V_2 -> V_54 = V_2 -> V_45 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_42 = 0x00 ;
V_33 . V_57 = 1 ;
V_53 = 0 ;
for ( V_36 = 0 ; V_36 < V_58 ; V_36 ++ ) {
if ( V_36 == V_58 - 1 )
V_33 . V_42 |= V_46 ;
F_1 ( V_2 , V_2 -> V_45 ) ;
V_35 = V_2 -> V_15 + V_53 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_53 += sizeof( V_33 ) ;
if ( V_53 >= V_59 ) {
V_53 = 0 ;
V_2 -> V_45 ++ ;
}
}
if ( V_53 != 0 )
V_2 -> V_45 ++ ;
V_2 -> V_60 = V_2 -> V_45 ;
V_2 -> V_61 = 0 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_42 = V_49 ;
V_33 . V_57 = 1 ;
V_53 = 0 ;
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ ) {
if ( V_36 == V_62 - 1 )
V_33 . V_42 |= V_46 ;
F_1 ( V_2 , V_2 -> V_45 ) ;
V_35 = V_2 -> V_15 + V_53 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_53 += sizeof( V_33 ) ;
if ( V_53 >= V_59 ) {
V_53 = 0 ;
V_2 -> V_45 ++ ;
}
}
F_14 ( & V_2 -> V_37 , V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_32 V_33 ;
void T_3 * V_63 = V_2 -> V_15 + ( V_2 -> V_48 * sizeof( V_33 ) ) ;
F_1 ( V_2 , V_47 ) ;
F_7 ( & V_33 , V_63 , sizeof( V_33 ) ) ;
if ( ! ( V_33 . V_42 & V_49 ) ) {
F_6 ( V_2 -> V_19 , L_3 , V_64 ) ;
return - V_20 ;
}
F_1 ( V_2 , V_33 . V_44 ) ;
F_10 ( V_2 -> V_15 , V_8 , sizeof( * V_8 ) ) ;
F_1 ( V_2 , V_47 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_63 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_48 = ( V_33 . V_42 & V_46 ) ? 0 : ( V_2 -> V_48 + 1 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_32 V_33 ;
void T_3 * V_63 = V_2 -> V_15 + ( V_2 -> V_38 * sizeof( V_33 ) ) ;
F_1 ( V_2 , V_40 ) ;
F_7 ( & V_33 , V_63 , sizeof( V_33 ) ) ;
if ( ! ( V_33 . V_42 & V_49 ) ) {
F_6 ( V_2 -> V_19 , L_4 , V_64 ) ;
return - V_20 ;
}
F_1 ( V_2 , V_33 . V_44 ) ;
F_7 ( V_8 , V_2 -> V_15 , sizeof( * V_8 ) ) ;
F_1 ( V_2 , V_40 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_63 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_38 = ( V_33 . V_42 & V_46 ) ? 0 : ( V_2 -> V_38 + 1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_34 ;
int V_65 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( V_2 -> V_66 == 0 )
V_65 = F_8 ( V_2 , V_8 ) ;
else
V_65 = F_16 ( V_2 , V_8 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_65 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_34 ;
int V_65 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( V_2 -> V_66 == 0 )
V_65 = F_4 ( V_2 , V_8 ) ;
else
V_65 = F_17 ( V_2 , V_8 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_65 ;
}
static int T_2 F_20 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_68 ;
V_8 . V_69 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int T_4 F_22 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_70 ;
V_8 . V_69 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int T_2 F_23 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
int V_65 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_71 ;
V_8 . V_69 = F_21 ( 0 ) ;
F_24 ( V_2 -> V_66 != 0 ) ;
V_65 = F_18 ( V_2 , & V_8 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_66 = 1 ;
return 0 ;
}
static int T_2 F_25 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
unsigned int V_53 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_72 ;
V_8 . V_69 = F_21 ( 8 ) ;
V_53 = F_26 ( V_2 -> V_54 ) ;
V_8 . V_73 [ 0 ] = V_53 & 0xff ;
V_8 . V_73 [ 1 ] = ( V_53 >> 8 ) & 0xff ;
V_8 . V_73 [ 2 ] = ( V_53 >> 16 ) & 0xff ;
V_8 . V_73 [ 3 ] = ( V_53 >> 24 ) & 0xff ;
V_53 = F_26 ( V_2 -> V_60 ) ;
V_8 . V_73 [ 4 ] = V_53 & 0xff ;
V_8 . V_73 [ 5 ] = ( V_53 >> 8 ) & 0xff ;
V_8 . V_73 [ 6 ] = ( V_53 >> 16 ) & 0xff ;
V_8 . V_73 [ 7 ] = ( V_53 >> 24 ) & 0xff ;
F_24 ( V_2 -> V_66 != 1 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int T_2 F_27 ( struct V_1 * V_2 , bool V_74 )
{
struct V_7 V_8 ;
int V_65 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_75 ;
V_8 . V_69 = F_21 ( 5 ) ;
V_8 . V_73 [ 0 ] = 0x00 ;
V_8 . V_73 [ 1 ] = 0x00 ;
V_8 . V_73 [ 2 ] = 0xff ;
V_8 . V_73 [ 3 ] = 0x07 ;
V_8 . V_73 [ 4 ] = V_74 ? V_76 : V_77 ;
V_65 = F_18 ( V_2 , & V_8 ) ;
if ( V_65 )
return V_65 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_75 ;
V_8 . V_69 = F_21 ( 13 ) ;
V_8 . V_73 [ 0 ] = 0 ;
V_8 . V_73 [ 1 ] = 0x00 ;
V_8 . V_73 [ 2 ] = 0x00 ;
V_8 . V_73 [ 3 ] = 0x00 ;
V_8 . V_73 [ 4 ] = 0x20 ;
V_8 . V_73 [ 5 ] = 0xff ;
V_8 . V_73 [ 6 ] = 0xff ;
V_8 . V_73 [ 7 ] = 0xff ;
V_8 . V_73 [ 8 ] = 0x3f ;
V_8 . V_73 [ 9 ] = V_74 ? V_76 : V_77 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_28 ( struct V_1 * V_2 , bool V_78 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_78 ? V_79 : V_80 ;
V_8 . V_69 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_29 ( struct V_1 * V_2 , bool V_78 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_81 ;
V_8 . V_69 = F_21 ( 2 ) ;
V_8 . V_73 [ 0 ] = 0x00 ;
V_8 . V_73 [ 1 ] = V_78 ? V_82 : V_83 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_84 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_85 ;
V_8 . V_69 = F_21 ( 2 ) ;
V_8 . V_73 [ 0 ] = V_84 ;
V_8 . V_73 [ 1 ] = 0x00 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_86 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_87 ;
V_8 . V_69 = F_21 ( 2 ) ;
V_8 . V_73 [ 0 ] = 0x00 ;
V_8 . V_73 [ 1 ] = V_86 ;
return F_18 ( V_2 , & V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_33 ,
struct V_88 * V_89 )
{
if ( ( V_33 -> V_57 & V_90 ) == V_91 ) {
if ( V_33 -> V_73 [ 1 ] & V_92 )
V_89 -> V_93 |= V_94 ;
V_89 -> V_93 |= V_33 -> V_73 [ 0 ] << 3 ;
V_89 -> V_93 |= ( V_33 -> V_73 [ 1 ] & 0xe0 ) >> 5 ;
V_89 -> V_95 = V_33 -> V_73 [ 1 ] & V_96 ;
memcpy ( V_89 -> V_73 , & V_33 -> V_73 [ 2 ] , sizeof( V_89 -> V_73 ) ) ;
} else {
V_89 -> V_95 = V_33 -> V_73 [ 0 ] & V_96 ;
if ( V_33 -> V_73 [ 0 ] & V_97 )
V_89 -> V_93 |= V_94 ;
if ( V_33 -> V_73 [ 0 ] & V_98 ) {
V_89 -> V_93 |= V_99 ;
V_89 -> V_93 |= V_33 -> V_73 [ 2 ] << 21 ;
V_89 -> V_93 |= V_33 -> V_73 [ 3 ] << 13 ;
V_89 -> V_93 |= V_33 -> V_73 [ 4 ] << 5 ;
V_89 -> V_93 |= ( V_33 -> V_73 [ 5 ] & 0xf8 ) >> 3 ;
} else {
V_89 -> V_93 |= V_33 -> V_73 [ 2 ] << 3 ;
V_89 -> V_93 |= V_33 -> V_73 [ 3 ] >> 5 ;
}
memcpy ( V_89 -> V_73 , & V_33 -> V_73 [ 6 ] , sizeof( V_89 -> V_73 ) ) ;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
struct V_52 * V_33 )
{
memset ( V_33 -> V_73 , 0 , sizeof( V_33 -> V_73 ) ) ;
V_33 -> V_57 = V_100 ;
V_33 -> V_73 [ 0 ] |= V_89 -> V_95 ;
V_33 -> V_73 [ 1 ] |= V_101 ;
if ( V_89 -> V_93 & V_94 )
V_33 -> V_73 [ 0 ] |= V_97 ;
if ( V_89 -> V_93 & V_99 ) {
V_33 -> V_73 [ 0 ] |= V_98 ;
V_33 -> V_73 [ 2 ] = ( V_89 -> V_93 & 0x1fe00000 ) >> 21 ;
V_33 -> V_73 [ 3 ] = ( V_89 -> V_93 & 0x001fe000 ) >> 13 ;
V_33 -> V_73 [ 4 ] = ( V_89 -> V_93 & 0x00001fe0 ) >> 5 ;
V_33 -> V_73 [ 5 ] = ( V_89 -> V_93 & 0x0000001f ) << 3 ;
} else {
V_33 -> V_73 [ 2 ] = ( V_89 -> V_93 & 0x7F8 ) >> 3 ;
V_33 -> V_73 [ 3 ] = ( V_89 -> V_93 & 0x007 ) << 5 ;
}
memcpy ( & V_33 -> V_73 [ 6 ] , V_89 -> V_73 , sizeof( V_89 -> V_73 ) ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_5 , V_8 -> V_73 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_102 * V_19 = V_2 -> V_103 ;
struct V_104 * V_105 = & V_19 -> V_105 ;
struct V_88 * V_89 ;
struct V_106 * V_107 ;
if ( V_8 -> V_67 == V_108 ) {
F_9 ( V_2 -> V_19 , L_6 , V_8 -> V_73 [ 0 ] ) ;
return;
}
V_107 = F_36 ( V_19 , & V_89 ) ;
if ( V_107 ) {
V_89 -> V_93 |= V_109 ;
V_89 -> V_73 [ 1 ] = V_110 ;
V_105 -> V_111 ++ ;
V_105 -> V_112 += V_89 -> V_95 ;
F_37 ( V_107 ) ;
}
}
static int F_38 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_102 * V_19 = V_2 -> V_103 ;
struct V_104 * V_105 = & V_19 -> V_105 ;
enum V_113 V_114 = V_2 -> V_115 . V_114 ;
T_1 V_116 , V_117 , V_118 , V_119 ;
struct V_88 * V_89 ;
struct V_106 * V_107 ;
if ( V_8 -> V_73 [ 1 ] != V_120 ) {
F_9 ( V_2 -> V_19 , L_7 ) ;
return - V_121 ;
}
if ( F_39 ( V_8 -> V_69 ) < 6 ) {
F_9 ( V_2 -> V_19 , L_8 ) ;
return - V_122 ;
}
V_107 = F_36 ( V_19 , & V_89 ) ;
if ( V_107 == NULL )
return - V_20 ;
V_117 = V_8 -> V_73 [ 0 ] ;
V_116 = V_8 -> V_73 [ 3 ] ;
V_118 = V_8 -> V_73 [ 4 ] ;
V_119 = V_8 -> V_73 [ 5 ] ;
if ( V_117 == V_123 || V_117 == V_124 ) {
F_6 ( V_2 -> V_19 , L_9 ) ;
V_89 -> V_93 |= V_109 ;
V_89 -> V_73 [ 1 ] = V_110 ;
V_105 -> V_125 ++ ;
V_105 -> V_111 ++ ;
}
if ( V_117 == V_126 ) {
F_6 ( V_2 -> V_19 , L_10 ) ;
if ( V_116 & V_127 ) {
V_114 = V_128 ;
V_89 -> V_93 |= V_129 ;
F_40 ( V_19 ) ;
} else if ( V_116 & V_130 ) {
if ( V_118 >= 128 || V_119 >= 128 )
V_114 = V_131 ;
else
V_114 = V_132 ;
} else {
V_114 = V_133 ;
}
}
if ( V_117 == V_134 ) {
T_1 V_135 = V_8 -> V_73 [ 2 ] ;
F_6 ( V_2 -> V_19 , L_11 ) ;
V_2 -> V_115 . V_136 . V_137 ++ ;
V_105 -> V_111 ++ ;
V_89 -> V_93 |= V_138 | V_139 ;
switch ( V_135 & V_140 ) {
case V_141 :
V_89 -> V_73 [ 2 ] |= V_142 ;
break;
case V_143 :
V_89 -> V_73 [ 2 ] |= V_144 ;
break;
case V_145 :
V_89 -> V_73 [ 2 ] |= V_146 ;
break;
default:
V_89 -> V_73 [ 2 ] |= V_147 ;
V_89 -> V_73 [ 3 ] = V_135 & V_148 ;
break;
}
if ( ( V_135 & V_149 ) == 0 )
V_89 -> V_73 [ 2 ] |= V_150 ;
V_89 -> V_73 [ 6 ] = V_119 ;
V_89 -> V_73 [ 7 ] = V_118 ;
}
if ( V_114 != V_2 -> V_115 . V_114 && ( V_114 == V_132 ||
V_114 == V_131 ) ) {
V_89 -> V_93 |= V_109 ;
if ( V_114 == V_132 ) {
V_2 -> V_115 . V_136 . V_151 ++ ;
V_89 -> V_73 [ 1 ] = ( V_119 > V_118 ) ?
V_152 :
V_153 ;
} else {
V_2 -> V_115 . V_136 . V_154 ++ ;
V_89 -> V_73 [ 1 ] = ( V_119 > V_118 ) ?
V_155 :
V_156 ;
}
V_89 -> V_73 [ 6 ] = V_119 ;
V_89 -> V_73 [ 7 ] = V_118 ;
}
V_2 -> V_115 . V_114 = V_114 ;
V_105 -> V_111 ++ ;
V_105 -> V_112 += V_89 -> V_95 ;
F_37 ( V_107 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
switch ( V_8 -> V_73 [ 0 ] ) {
case V_157 :
case V_158 :
V_2 -> V_159 . V_118 = V_8 -> V_73 [ 5 ] ;
V_2 -> V_159 . V_119 = V_8 -> V_73 [ 6 ] ;
F_42 ( & V_2 -> V_160 ) ;
break;
case V_161 :
V_2 -> V_162 = V_8 -> V_73 [ 6 ] & V_82 ;
F_42 ( & V_2 -> V_163 ) ;
break;
default:
F_9 ( V_2 -> V_19 , L_12 ) ;
break;
}
}
static void F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_44 ( V_2 -> V_19 , L_13 ,
V_8 -> V_67 , F_39 ( V_8 -> V_69 ) ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_14 , V_64 ,
V_2 -> V_164 , V_8 -> V_67 , F_39 ( V_8 -> V_69 ) ) ;
switch ( V_8 -> V_67 ) {
case V_165 :
F_34 ( V_2 , V_8 ) ;
break;
case V_108 :
case V_166 :
F_35 ( V_2 , V_8 ) ;
break;
case V_167 :
F_38 ( V_2 , V_8 ) ;
break;
case V_85 :
F_41 ( V_2 , V_8 ) ;
break;
default:
F_43 ( V_2 , V_8 ) ;
break;
}
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_52 T_3 * V_33 ;
T_1 V_42 ;
F_1 ( V_2 , V_2 -> V_60 + ( V_2 -> V_61 / 16 ) ) ;
V_33 = V_2 -> V_15 + ( ( V_2 -> V_61 % 16 ) * sizeof( * V_33 ) ) ;
V_42 = F_5 ( & V_33 -> V_42 ) ;
if ( ! ( V_42 & V_49 ) )
return false ;
return true ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = V_2 -> V_103 ;
struct V_104 * V_105 = & V_103 -> V_105 ;
struct V_52 V_33 ;
void T_3 * V_63 ;
struct V_88 * V_89 ;
struct V_106 * V_107 ;
unsigned long V_34 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
V_63 = V_2 -> V_15 + ( ( V_2 -> V_55 % 16 ) * sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_63 , sizeof( V_33 ) ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
if ( ! ( V_33 . V_42 & V_49 ) )
return - V_168 ;
V_107 = F_48 ( V_103 , & V_89 ) ;
if ( F_49 ( V_107 == NULL ) ) {
V_105 -> V_169 ++ ;
goto V_170;
}
F_32 ( V_2 , & V_33 , V_89 ) ;
F_50 ( V_107 ) ;
V_105 -> V_171 ++ ;
V_105 -> V_112 += V_89 -> V_95 ;
V_170:
V_33 . V_42 ^= V_49 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
F_10 ( V_63 , & V_33 , 1 ) ;
V_2 -> V_55 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_55 + 1 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_51 ( struct V_172 * V_173 , int V_174 )
{
struct V_1 * V_2 = F_52 ( V_173 , struct V_1 , V_173 ) ;
struct V_7 V_8 ;
unsigned long V_34 ;
int V_175 = 0 ;
int V_65 ;
while ( true ) {
V_65 = F_19 ( V_2 , & V_8 ) ;
if ( V_65 )
break;
F_45 ( V_2 , & V_8 ) ;
}
while ( V_175 < V_174 ) {
V_65 = F_47 ( V_2 ) ;
if ( V_65 )
break;
V_175 ++ ;
}
if ( V_175 < V_174 )
F_53 ( V_173 ) ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( F_54 ( V_2 -> V_103 ) && F_46 ( V_2 ) )
F_55 ( V_2 -> V_103 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_177 ) ;
return V_175 ;
}
static T_5 F_56 ( int V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
T_1 V_180 ;
V_180 = F_5 ( & V_2 -> V_176 -> V_181 ) & ( 1 << V_2 -> V_164 ) ;
if ( V_180 == ( 1 << V_2 -> V_164 ) )
return V_182 ;
F_5 ( & V_2 -> V_5 -> V_183 ) ;
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_181 ) ;
F_57 ( & V_2 -> V_173 ) ;
return V_184 ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_1 V_185 = 1 << V_2 -> V_164 ;
unsigned long V_186 ;
T_1 V_187 , V_188 ;
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_181 ) ;
V_2 -> V_45 = V_189 ;
F_1 ( V_2 , V_14 ) ;
V_187 = F_5 ( V_2 -> V_15 + V_190 ) ;
F_3 ( V_185 , & V_2 -> V_176 -> V_191 ) ;
F_3 ( V_185 , & V_2 -> V_176 -> V_192 ) ;
V_186 = V_193 ;
do {
F_1 ( V_2 , V_14 ) ;
V_188 = F_5 ( V_2 -> V_15 + V_190 ) ;
if ( V_188 == ( V_187 ^ 0xff ) )
return 0 ;
F_59 ( 10 ) ;
} while ( F_60 ( V_193 , V_186 + V_194 / 4 ) );
F_9 ( V_2 -> V_19 , L_15 ) ;
return - V_195 ;
}
static void T_4 F_61 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_58 ( V_2 ) ;
}
static int T_2 F_62 ( struct V_1 * V_2 )
{
int V_65 ;
V_65 = F_58 ( V_2 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_16 ) ;
return V_65 ;
}
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_177 ) ;
V_65 = F_20 ( V_2 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_17 ) ;
return V_65 ;
}
F_11 ( V_2 ) ;
V_65 = F_23 ( V_2 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_18 ) ;
return V_65 ;
}
V_65 = F_29 ( V_2 , true ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_19 ) ;
return V_65 ;
}
V_65 = F_31 ( V_2 , V_196 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_20 ) ;
return V_65 ;
}
F_15 ( V_2 ) ;
V_65 = F_25 ( V_2 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_21 ) ;
return V_65 ;
}
V_65 = F_27 ( V_2 , true ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_22 ) ;
return V_65 ;
}
return 0 ;
}
static int F_63 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
T_1 V_86 ;
int V_65 ;
V_65 = F_65 ( V_103 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_23 ) ;
return V_65 ;
}
if ( V_2 -> V_115 . V_197 & V_198 )
V_86 = V_196 ;
else
V_86 = 0 ;
V_65 = F_31 ( V_2 , V_86 ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_20 ) ;
F_66 ( V_103 ) ;
return V_65 ;
}
V_65 = F_28 ( V_2 , true ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_24 ) ;
F_66 ( V_103 ) ;
return V_65 ;
}
V_2 -> V_115 . V_114 = V_133 ;
F_67 ( V_103 ) ;
return 0 ;
}
static int F_68 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
int V_65 ;
F_69 ( V_103 ) ;
V_2 -> V_115 . V_114 = V_199 ;
V_65 = F_28 ( V_2 , false ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_25 ) ;
return V_65 ;
}
F_66 ( V_103 ) ;
return 0 ;
}
static int F_70 ( struct V_106 * V_107 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
struct V_104 * V_105 = & V_103 -> V_105 ;
struct V_88 * V_89 = (struct V_88 * ) V_107 -> V_73 ;
struct V_52 V_33 ;
void T_3 * V_63 ;
unsigned long V_34 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( ! F_46 ( V_2 ) ) {
F_9 ( V_2 -> V_19 , L_26 ) ;
F_69 ( V_103 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_200 ;
}
F_1 ( V_2 , V_2 -> V_60 + ( V_2 -> V_61 / 16 ) ) ;
V_63 = V_2 -> V_15 + ( ( V_2 -> V_61 % 16 ) * sizeof( V_33 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_63 , 1 ) ;
F_33 ( V_2 , V_89 , & V_33 ) ;
V_33 . V_42 |= V_201 ;
F_10 ( V_63 , & V_33 , sizeof( V_33 ) ) ;
F_3 ( 0x01 , & V_2 -> V_5 -> V_183 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_63 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_61 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_61 + 1 ) ;
V_105 -> V_202 ++ ;
V_105 -> V_203 += V_89 -> V_95 ;
F_71 ( V_107 ) ;
if ( ! F_46 ( V_2 ) )
F_69 ( V_103 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_204 ;
}
static int F_72 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
struct V_205 * V_206 = & V_2 -> V_115 . V_207 ;
struct V_7 V_8 ;
T_1 V_208 , V_209 ;
V_208 = ( ( V_206 -> V_210 - 1 ) & 0x3f ) | ( ( ( V_206 -> V_211 - 1 ) & 0x3 ) << 6 ) ;
V_209 = ( ( V_206 -> V_212 + V_206 -> V_213 - 1 ) & 0xf ) |
( ( ( V_206 -> V_214 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_115 . V_197 & V_215 )
V_209 |= 0x80 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_67 = V_216 ;
V_8 . V_69 = F_21 ( 4 ) ;
V_8 . V_73 [ 0 ] = 0x00 ;
V_8 . V_73 [ 1 ] = 0x00 ;
V_8 . V_73 [ 2 ] = V_208 ;
V_8 . V_73 [ 3 ] = V_209 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_73 ( struct V_102 * V_103 , enum V_217 V_218 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
int V_65 ;
if ( V_218 != V_219 )
return - V_220 ;
V_65 = F_28 ( V_2 , true ) ;
if ( V_65 ) {
F_9 ( V_2 -> V_19 , L_24 ) ;
return V_65 ;
}
V_2 -> V_115 . V_114 = V_133 ;
if ( F_54 ( V_103 ) )
F_55 ( V_103 ) ;
return 0 ;
}
static int F_74 ( const struct V_102 * V_103 ,
struct V_221 * V_159 )
{
struct V_1 * V_2 = F_64 ( V_103 ) ;
int V_65 ;
V_65 = F_30 ( V_2 , V_157 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_75 ( & V_2 -> V_160 , V_194 ) ;
if ( V_65 <= 0 ) {
F_76 ( V_2 -> V_19 , L_27 , V_64 ) ;
return - V_195 ;
}
V_159 -> V_118 = V_2 -> V_159 . V_118 ;
V_159 -> V_119 = V_2 -> V_159 . V_119 ;
return 0 ;
}
static T_6 F_77 ( struct V_222 * V_19 ,
struct V_223 * V_224 ,
char * V_225 )
{
struct V_1 * V_2 = F_64 ( F_78 ( V_19 ) ) ;
int V_65 ;
V_65 = F_30 ( V_2 , V_161 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_75 ( & V_2 -> V_163 , V_194 ) ;
if ( V_65 <= 0 ) {
F_76 ( V_2 -> V_19 , L_27 , V_64 ) ;
return - V_195 ;
}
return snprintf ( V_225 , V_226 , L_28 , V_2 -> V_162 ) ;
}
static T_6 F_79 ( struct V_222 * V_19 ,
struct V_223 * V_224 ,
const char * V_225 , T_7 V_227 )
{
struct V_1 * V_2 = F_64 ( F_78 ( V_19 ) ) ;
unsigned long V_228 ;
int V_65 ;
if ( F_80 ( V_225 , 0 , & V_228 ) )
return - V_122 ;
V_65 = F_29 ( V_2 , V_228 ) ;
if ( V_65 )
return V_65 ;
return V_227 ;
}
static int T_2 F_81 ( struct V_229 * V_230 )
{
struct V_231 * V_232 ;
struct V_102 * V_103 ;
struct V_1 * V_2 ;
struct V_233 * V_234 ;
struct V_222 * V_19 ;
int V_65 ;
V_232 = V_230 -> V_19 . V_235 ;
if ( ! V_232 )
return - V_236 ;
F_6 ( & V_230 -> V_19 , L_29 , V_232 -> V_237 ) ;
V_19 = & V_230 -> V_19 ;
V_103 = F_82 ( sizeof( * V_2 ) , 0 ) ;
if ( ! V_103 ) {
F_9 ( V_19 , L_30 ) ;
V_65 = - V_20 ;
goto V_238;
}
F_83 ( V_230 , V_103 ) ;
V_2 = F_64 ( V_103 ) ;
V_2 -> V_103 = V_103 ;
V_2 -> V_19 = & V_230 -> V_19 ;
V_2 -> V_164 = V_232 -> V_237 ;
F_84 ( V_103 , & V_2 -> V_173 , F_51 , V_58 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_86 ( & V_2 -> V_163 ) ;
F_86 ( & V_2 -> V_160 ) ;
V_103 -> V_239 [ 0 ] = & V_240 ;
V_2 -> V_45 = V_189 ;
V_103 -> V_241 = & V_242 ;
V_103 -> V_34 |= V_243 ;
F_87 ( V_103 , & V_230 -> V_19 ) ;
V_2 -> V_115 . clock . V_244 = V_245 ;
V_2 -> V_115 . V_246 = & V_247 ;
V_2 -> V_115 . V_248 = F_72 ;
V_2 -> V_115 . V_249 = F_73 ;
V_2 -> V_115 . V_250 = F_74 ;
V_2 -> V_115 . V_251 = V_215
| V_198 ;
V_2 -> V_178 = F_88 ( V_230 , 0 ) ;
if ( V_2 -> V_178 < 0 ) {
F_9 ( V_19 , L_31 ) ;
V_65 = - V_121 ;
goto V_252;
}
V_103 -> V_178 = V_2 -> V_178 ;
V_234 = F_89 ( V_230 , V_253 , 0 ) ;
if ( ! V_234 ) {
F_9 ( V_19 , L_32 ) ;
V_65 = - V_121 ;
goto V_252;
}
V_2 -> V_15 = F_90 ( V_234 -> V_186 , F_91 ( V_234 ) ) ;
if ( ! V_2 -> V_15 ) {
F_9 ( V_19 , L_33 ) ;
V_65 = - V_20 ;
goto V_252;
}
V_2 -> V_5 = V_2 -> V_15 + V_59 ;
V_234 = F_89 ( V_230 , V_253 , 1 ) ;
if ( ! V_234 ) {
F_9 ( V_19 , L_34 ) ;
V_65 = - V_121 ;
goto V_254;
}
V_2 -> V_176 = F_90 ( V_234 -> V_186 , F_91 ( V_234 ) ) ;
if ( ! V_2 -> V_176 ) {
F_9 ( V_19 , L_35 ) ;
V_65 = - V_20 ;
goto V_254;
}
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_181 ) ;
V_65 = F_92 ( V_2 -> V_178 , F_56 , V_255 , V_256 , V_2 ) ;
if ( V_65 ) {
F_9 ( V_19 , L_36 ) ;
goto V_257;
}
F_93 ( & V_2 -> V_173 ) ;
V_65 = F_62 ( V_2 ) ;
if ( V_65 ) {
F_9 ( V_19 , L_37 , V_64 ) ;
goto V_258;
}
V_65 = F_94 ( V_103 ) ;
if ( V_65 ) {
F_9 ( V_19 , L_38 , V_64 ) ;
goto V_258;
}
F_76 ( V_19 , L_39 , V_232 -> V_237 ) ;
return 0 ;
V_258:
F_95 ( & V_2 -> V_173 ) ;
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_181 ) ;
F_96 ( V_2 -> V_178 , V_2 ) ;
V_257:
F_97 ( V_2 -> V_176 ) ;
V_254:
F_97 ( V_2 -> V_15 ) ;
V_252:
F_98 ( V_103 ) ;
V_238:
return V_65 ;
}
static int T_4 F_99 ( struct V_229 * V_230 )
{
struct V_102 * V_103 = F_100 ( V_230 ) ;
struct V_1 * V_2 = F_64 ( V_103 ) ;
F_101 ( V_103 ) ;
F_95 ( & V_2 -> V_173 ) ;
F_3 ( 1 << V_2 -> V_164 , & V_2 -> V_176 -> V_181 ) ;
F_96 ( V_2 -> V_178 , V_2 ) ;
F_61 ( V_2 ) ;
F_97 ( V_2 -> V_176 ) ;
F_97 ( V_2 -> V_15 ) ;
F_98 ( V_103 ) ;
return 0 ;
}
static int T_8 F_102 ( void )
{
return F_103 ( & V_259 ) ;
}
static void T_9 F_104 ( void )
{
F_105 ( & V_259 ) ;
}
