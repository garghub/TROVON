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
static void F_11 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
unsigned long V_34 ;
void T_2 * V_35 ;
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
static void F_15 ( struct V_1 * V_2 )
{
struct V_52 V_33 ;
unsigned long V_34 ;
unsigned int V_53 ;
void T_2 * V_35 ;
int V_36 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
V_2 -> V_54 = V_2 -> V_45 ;
V_2 -> V_55 = 0 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_42 = 0x00 ;
V_33 . V_56 = 1 ;
V_53 = 0 ;
for ( V_36 = 0 ; V_36 < V_57 ; V_36 ++ ) {
if ( V_36 == V_57 - 1 )
V_33 . V_42 |= V_46 ;
F_1 ( V_2 , V_2 -> V_45 ) ;
V_35 = V_2 -> V_15 + V_53 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_53 += sizeof( V_33 ) ;
if ( V_53 >= V_58 ) {
V_53 = 0 ;
V_2 -> V_45 ++ ;
}
}
if ( V_53 != 0 )
V_2 -> V_45 ++ ;
V_2 -> V_59 = V_2 -> V_45 ;
V_2 -> V_60 = 0 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_42 = V_49 ;
V_33 . V_56 = 1 ;
V_53 = 0 ;
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
if ( V_36 == V_61 - 1 )
V_33 . V_42 |= V_46 ;
F_1 ( V_2 , V_2 -> V_45 ) ;
V_35 = V_2 -> V_15 + V_53 ;
F_10 ( V_35 , & V_33 , sizeof( V_33 ) ) ;
V_53 += sizeof( V_33 ) ;
if ( V_53 >= V_58 ) {
V_53 = 0 ;
V_2 -> V_45 ++ ;
}
}
F_14 ( & V_2 -> V_37 , V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_32 V_33 ;
void T_2 * V_62 = V_2 -> V_15 + ( V_2 -> V_48 * sizeof( V_33 ) ) ;
F_1 ( V_2 , V_47 ) ;
F_7 ( & V_33 , V_62 , sizeof( V_33 ) ) ;
if ( ! ( V_33 . V_42 & V_49 ) ) {
F_6 ( V_2 -> V_19 , L_3 , V_63 ) ;
return - V_20 ;
}
F_1 ( V_2 , V_33 . V_44 ) ;
F_10 ( V_2 -> V_15 , V_8 , sizeof( * V_8 ) ) ;
F_1 ( V_2 , V_47 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_48 = ( V_33 . V_42 & V_46 ) ? 0 : ( V_2 -> V_48 + 1 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_32 V_33 ;
void T_2 * V_62 = V_2 -> V_15 + ( V_2 -> V_38 * sizeof( V_33 ) ) ;
F_1 ( V_2 , V_40 ) ;
F_7 ( & V_33 , V_62 , sizeof( V_33 ) ) ;
if ( ! ( V_33 . V_42 & V_49 ) ) {
F_6 ( V_2 -> V_19 , L_4 , V_63 ) ;
return - V_20 ;
}
F_1 ( V_2 , V_33 . V_44 ) ;
F_7 ( V_8 , V_2 -> V_15 , sizeof( * V_8 ) ) ;
F_1 ( V_2 , V_40 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_38 = ( V_33 . V_42 & V_46 ) ? 0 : ( V_2 -> V_38 + 1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_34 ;
int V_64 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( V_2 -> V_65 == 0 )
V_64 = F_8 ( V_2 , V_8 ) ;
else
V_64 = F_16 ( V_2 , V_8 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_64 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_34 ;
int V_64 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( V_2 -> V_65 == 0 )
V_64 = F_4 ( V_2 , V_8 ) ;
else
V_64 = F_17 ( V_2 , V_8 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_64 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_67 ;
V_8 . V_68 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_69 ;
V_8 . V_68 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
int V_64 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_70 ;
V_8 . V_68 = F_21 ( 0 ) ;
F_24 ( V_2 -> V_65 != 0 ) ;
V_64 = F_18 ( V_2 , & V_8 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_65 = 1 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
unsigned int V_53 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_71 ;
V_8 . V_68 = F_21 ( 8 ) ;
V_53 = F_26 ( V_2 -> V_54 ) ;
V_8 . V_72 [ 0 ] = V_53 & 0xff ;
V_8 . V_72 [ 1 ] = ( V_53 >> 8 ) & 0xff ;
V_8 . V_72 [ 2 ] = ( V_53 >> 16 ) & 0xff ;
V_8 . V_72 [ 3 ] = ( V_53 >> 24 ) & 0xff ;
V_53 = F_26 ( V_2 -> V_59 ) ;
V_8 . V_72 [ 4 ] = V_53 & 0xff ;
V_8 . V_72 [ 5 ] = ( V_53 >> 8 ) & 0xff ;
V_8 . V_72 [ 6 ] = ( V_53 >> 16 ) & 0xff ;
V_8 . V_72 [ 7 ] = ( V_53 >> 24 ) & 0xff ;
F_24 ( V_2 -> V_65 != 1 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_27 ( struct V_1 * V_2 , bool V_73 )
{
struct V_7 V_8 ;
int V_64 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_74 ;
V_8 . V_68 = F_21 ( 5 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = 0x00 ;
V_8 . V_72 [ 2 ] = 0xff ;
V_8 . V_72 [ 3 ] = 0x07 ;
V_8 . V_72 [ 4 ] = V_73 ? V_75 : V_76 ;
V_64 = F_18 ( V_2 , & V_8 ) ;
if ( V_64 )
return V_64 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_74 ;
V_8 . V_68 = F_21 ( 13 ) ;
V_8 . V_72 [ 0 ] = 0 ;
V_8 . V_72 [ 1 ] = 0x00 ;
V_8 . V_72 [ 2 ] = 0x00 ;
V_8 . V_72 [ 3 ] = 0x00 ;
V_8 . V_72 [ 4 ] = 0x20 ;
V_8 . V_72 [ 5 ] = 0xff ;
V_8 . V_72 [ 6 ] = 0xff ;
V_8 . V_72 [ 7 ] = 0xff ;
V_8 . V_72 [ 8 ] = 0x3f ;
V_8 . V_72 [ 9 ] = V_73 ? V_75 : V_76 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_28 ( struct V_1 * V_2 , bool V_77 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_77 ? V_78 : V_79 ;
V_8 . V_68 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_29 ( struct V_1 * V_2 , bool V_77 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_80 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_77 ? V_81 : V_82 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_84 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = V_83 ;
V_8 . V_72 [ 1 ] = 0x00 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_85 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_86 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_85 ;
return F_18 ( V_2 , & V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_33 ,
struct V_87 * V_88 )
{
if ( ( V_33 -> V_56 & V_89 ) == V_90 ) {
if ( V_33 -> V_72 [ 1 ] & V_91 )
V_88 -> V_92 |= V_93 ;
V_88 -> V_92 |= V_33 -> V_72 [ 0 ] << 3 ;
V_88 -> V_92 |= ( V_33 -> V_72 [ 1 ] & 0xe0 ) >> 5 ;
V_88 -> V_94 = F_33 ( V_33 -> V_72 [ 1 ] & V_95 ) ;
memcpy ( V_88 -> V_72 , & V_33 -> V_72 [ 2 ] , V_88 -> V_94 ) ;
} else {
V_88 -> V_94 = F_33 ( V_33 -> V_72 [ 0 ] & V_95 ) ;
if ( V_33 -> V_72 [ 0 ] & V_96 )
V_88 -> V_92 |= V_93 ;
if ( V_33 -> V_72 [ 0 ] & V_97 ) {
V_88 -> V_92 |= V_98 ;
V_88 -> V_92 |= V_33 -> V_72 [ 2 ] << 21 ;
V_88 -> V_92 |= V_33 -> V_72 [ 3 ] << 13 ;
V_88 -> V_92 |= V_33 -> V_72 [ 4 ] << 5 ;
V_88 -> V_92 |= ( V_33 -> V_72 [ 5 ] & 0xf8 ) >> 3 ;
} else {
V_88 -> V_92 |= V_33 -> V_72 [ 2 ] << 3 ;
V_88 -> V_92 |= V_33 -> V_72 [ 3 ] >> 5 ;
}
memcpy ( V_88 -> V_72 , & V_33 -> V_72 [ 6 ] , V_88 -> V_94 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_52 * V_33 )
{
memset ( V_33 -> V_72 , 0 , sizeof( V_33 -> V_72 ) ) ;
V_33 -> V_56 = V_99 ;
V_33 -> V_72 [ 0 ] |= V_88 -> V_94 ;
V_33 -> V_72 [ 1 ] |= V_100 ;
if ( V_2 -> V_101 . V_102 & V_103 )
V_33 -> V_72 [ 1 ] |= V_104 ;
if ( V_88 -> V_92 & V_93 )
V_33 -> V_72 [ 0 ] |= V_96 ;
if ( V_88 -> V_92 & V_98 ) {
V_33 -> V_72 [ 0 ] |= V_97 ;
V_33 -> V_72 [ 2 ] = ( V_88 -> V_92 & 0x1fe00000 ) >> 21 ;
V_33 -> V_72 [ 3 ] = ( V_88 -> V_92 & 0x001fe000 ) >> 13 ;
V_33 -> V_72 [ 4 ] = ( V_88 -> V_92 & 0x00001fe0 ) >> 5 ;
V_33 -> V_72 [ 5 ] = ( V_88 -> V_92 & 0x0000001f ) << 3 ;
} else {
V_33 -> V_72 [ 2 ] = ( V_88 -> V_92 & 0x7F8 ) >> 3 ;
V_33 -> V_72 [ 3 ] = ( V_88 -> V_92 & 0x007 ) << 5 ;
}
memcpy ( & V_33 -> V_72 [ 6 ] , V_88 -> V_72 , V_88 -> V_94 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_5 , V_8 -> V_72 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_105 * V_106 = V_2 -> V_19 ;
struct V_107 * V_108 = & V_106 -> V_108 ;
struct V_87 * V_88 ;
struct V_109 * V_110 ;
if ( V_8 -> V_66 == V_111 ) {
F_9 ( V_2 -> V_19 , L_6 , V_8 -> V_72 [ 0 ] ) ;
return;
}
V_110 = F_37 ( V_106 , & V_88 ) ;
if ( V_110 ) {
V_88 -> V_92 |= V_112 ;
V_88 -> V_72 [ 1 ] = V_113 ;
V_108 -> V_114 ++ ;
V_108 -> V_115 ++ ;
F_38 ( V_110 ) ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_105 * V_106 = V_2 -> V_19 ;
struct V_107 * V_108 = & V_106 -> V_108 ;
enum V_116 V_117 = V_2 -> V_101 . V_117 ;
T_1 V_118 , V_119 , V_120 , V_121 , V_122 ;
struct V_87 * V_88 ;
struct V_109 * V_110 ;
if ( V_8 -> V_72 [ 1 ] != V_123 ) {
F_9 ( V_2 -> V_19 , L_7 ) ;
return - V_124 ;
}
if ( F_40 ( V_8 -> V_68 ) < 6 ) {
F_9 ( V_2 -> V_19 , L_8 ) ;
return - V_125 ;
}
V_118 = V_8 -> V_72 [ 0 ] ;
V_119 = V_8 -> V_72 [ 2 ] ;
V_120 = V_8 -> V_72 [ 3 ] ;
V_121 = V_8 -> V_72 [ 4 ] ;
V_122 = V_8 -> V_72 [ 5 ] ;
if ( V_118 == V_126 ) {
int V_64 ;
F_6 ( V_2 -> V_19 , L_9 ) ;
if ( ! ( V_119 & V_127 ) ) {
F_41 ( F_42 ( & V_2 -> V_128 ) ) ;
V_108 -> V_129 ++ ;
} else {
V_108 -> V_115 ++ ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_10 ) ;
return V_64 ;
}
if ( ! ( V_2 -> V_101 . V_102 & V_130 ) )
return 0 ;
}
V_110 = F_37 ( V_106 , & V_88 ) ;
if ( V_110 == NULL )
return - V_20 ;
if ( V_118 == V_131 || V_118 == V_132 ) {
F_6 ( V_2 -> V_19 , L_11 ) ;
V_88 -> V_92 |= V_112 ;
V_88 -> V_72 [ 1 ] = V_113 ;
V_108 -> V_114 ++ ;
V_108 -> V_115 ++ ;
}
if ( V_118 == V_133 ) {
F_6 ( V_2 -> V_19 , L_12 ) ;
if ( V_120 & V_134 ) {
V_117 = V_135 ;
V_88 -> V_92 |= V_136 ;
F_43 ( V_106 ) ;
} else if ( V_120 & V_137 ) {
if ( V_121 >= 128 || V_122 >= 128 )
V_117 = V_138 ;
else
V_117 = V_139 ;
} else {
V_117 = V_140 ;
}
}
if ( V_118 == V_126 ) {
V_2 -> V_101 . V_141 . V_142 ++ ;
V_88 -> V_92 |= V_143 | V_144 ;
switch ( V_119 & V_145 ) {
case V_146 :
V_88 -> V_72 [ 2 ] |= V_147 ;
break;
case V_148 :
V_88 -> V_72 [ 2 ] |= V_149 ;
break;
case V_150 :
V_88 -> V_72 [ 2 ] |= V_151 ;
break;
default:
V_88 -> V_72 [ 2 ] |= V_152 ;
V_88 -> V_72 [ 3 ] = V_119 & V_153 ;
break;
}
if ( ! ( V_119 & V_127 ) )
V_88 -> V_72 [ 2 ] |= V_154 ;
V_88 -> V_72 [ 6 ] = V_122 ;
V_88 -> V_72 [ 7 ] = V_121 ;
}
if ( V_117 != V_2 -> V_101 . V_117 && ( V_117 == V_139 ||
V_117 == V_138 ) ) {
V_88 -> V_92 |= V_112 ;
if ( V_117 == V_139 ) {
V_2 -> V_101 . V_141 . V_155 ++ ;
V_88 -> V_72 [ 1 ] = ( V_122 > V_121 ) ?
V_156 :
V_157 ;
} else {
V_2 -> V_101 . V_141 . V_158 ++ ;
V_88 -> V_72 [ 1 ] = ( V_122 > V_121 ) ?
V_159 :
V_160 ;
}
V_88 -> V_72 [ 6 ] = V_122 ;
V_88 -> V_72 [ 7 ] = V_121 ;
}
V_2 -> V_101 . V_117 = V_117 ;
F_38 ( V_110 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
switch ( V_8 -> V_72 [ 0 ] ) {
case V_161 :
case V_162 :
V_2 -> V_163 . V_121 = V_8 -> V_72 [ 5 ] ;
V_2 -> V_163 . V_122 = V_8 -> V_72 [ 6 ] ;
F_45 ( & V_2 -> V_164 ) ;
break;
case V_165 :
V_2 -> V_166 = V_8 -> V_72 [ 6 ] & V_81 ;
F_45 ( & V_2 -> V_167 ) ;
break;
default:
F_9 ( V_2 -> V_19 , L_13 ) ;
break;
}
}
static void F_46 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_47 ( V_2 -> V_19 , L_14 ,
V_8 -> V_66 , F_40 ( V_8 -> V_68 ) ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_15 , V_63 ,
V_2 -> V_168 , V_8 -> V_66 , F_40 ( V_8 -> V_68 ) ) ;
switch ( V_8 -> V_66 ) {
case V_169 :
F_35 ( V_2 , V_8 ) ;
break;
case V_111 :
case V_170 :
F_36 ( V_2 , V_8 ) ;
break;
case V_171 :
F_39 ( V_2 , V_8 ) ;
break;
case V_84 :
F_44 ( V_2 , V_8 ) ;
break;
default:
F_46 ( V_2 , V_8 ) ;
break;
}
}
static void F_49 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
V_110 = F_50 ( V_110 ) ;
if ( ! V_110 )
return;
F_51 ( & V_2 -> V_128 , V_110 ) ;
}
static unsigned int F_52 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_42 ( & V_2 -> V_128 ) ;
struct V_87 * V_88 ;
T_1 V_172 ;
if ( ! V_110 ) {
F_9 ( V_2 -> V_19 , L_16 ) ;
return 0 ;
}
V_88 = (struct V_87 * ) V_110 -> V_72 ;
V_172 = V_88 -> V_94 ;
if ( V_110 -> V_173 != V_174 ) {
F_41 ( V_110 ) ;
return V_172 ;
}
V_110 -> V_175 = F_53 ( V_176 ) ;
V_110 -> V_173 = V_177 ;
V_110 -> V_178 = V_179 ;
V_110 -> V_106 = V_2 -> V_19 ;
F_54 ( V_110 ) ;
return V_172 ;
}
static bool F_55 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
struct V_87 * V_88 = (struct V_87 * ) V_110 -> V_72 ;
struct V_109 * V_180 = F_56 ( & V_2 -> V_128 ) ;
struct V_87 * V_181 ;
if ( ! V_180 )
return false ;
V_181 = (struct V_87 * ) V_180 -> V_72 ;
if ( V_88 -> V_92 != V_181 -> V_92 )
return false ;
if ( V_88 -> V_94 != V_181 -> V_94 )
return false ;
return memcmp ( V_88 -> V_72 , V_181 -> V_72 , V_88 -> V_94 ) == 0 ;
}
static bool F_57 ( struct V_1 * V_2 )
{
struct V_52 T_2 * V_33 ;
T_1 V_42 ;
if ( F_58 ( & V_2 -> V_128 ) >= V_61 )
return false ;
F_1 ( V_2 , V_2 -> V_59 + ( V_2 -> V_60 / 16 ) ) ;
V_33 = V_2 -> V_15 + ( ( V_2 -> V_60 % 16 ) * sizeof( * V_33 ) ) ;
V_42 = F_5 ( & V_33 -> V_42 ) ;
if ( ! ( V_42 & V_49 ) )
return false ;
return true ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_105 * V_19 = V_2 -> V_19 ;
struct V_107 * V_108 = & V_19 -> V_108 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
struct V_87 * V_88 ;
struct V_109 * V_110 ;
unsigned long V_34 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_55 % 16 ) * sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , sizeof( V_33 ) ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
if ( ! ( V_33 . V_42 & V_49 ) )
return - V_182 ;
V_110 = F_60 ( V_19 , & V_88 ) ;
if ( F_61 ( V_110 == NULL ) ) {
V_108 -> V_183 ++ ;
goto V_184;
}
F_32 ( V_2 , & V_33 , V_88 ) ;
if ( F_55 ( V_2 , V_110 ) ) {
V_108 -> V_185 ++ ;
V_108 -> V_186 += F_52 ( V_2 ) ;
F_41 ( V_110 ) ;
goto V_184;
}
V_108 -> V_187 ++ ;
V_108 -> V_188 += V_88 -> V_94 ;
F_54 ( V_110 ) ;
V_184:
V_33 . V_42 ^= V_49 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
F_10 ( V_62 , & V_33 , 1 ) ;
V_2 -> V_55 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_55 + 1 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_62 ( struct V_189 * V_190 , int V_191 )
{
struct V_1 * V_2 = F_63 ( V_190 , struct V_1 , V_190 ) ;
unsigned long V_34 ;
int V_192 = 0 ;
int V_64 ;
while ( true ) {
struct V_7 V_193 ( V_8 ) ;
V_64 = F_19 ( V_2 , & V_8 ) ;
if ( V_64 )
break;
F_48 ( V_2 , & V_8 ) ;
}
while ( V_192 < V_191 ) {
V_64 = F_59 ( V_2 ) ;
if ( V_64 )
break;
V_192 ++ ;
}
if ( V_192 < V_191 )
F_64 ( V_190 ) ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( F_65 ( V_2 -> V_19 ) && F_57 ( V_2 ) )
F_66 ( V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_195 ) ;
return V_192 ;
}
static T_3 F_67 ( int V_196 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
T_1 V_198 ;
V_198 = F_5 ( & V_2 -> V_194 -> V_199 ) & ( 1 << V_2 -> V_168 ) ;
if ( V_198 == ( 1 << V_2 -> V_168 ) )
return V_200 ;
F_5 ( & V_2 -> V_5 -> V_201 ) ;
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_199 ) ;
F_68 ( & V_2 -> V_190 ) ;
return V_202 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned long V_203 ;
T_1 V_204 , V_205 ;
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_199 ) ;
V_2 -> V_45 = V_206 ;
F_1 ( V_2 , V_14 ) ;
V_204 = F_5 ( V_2 -> V_15 + V_207 ) ;
F_3 ( 0x00 , & V_2 -> V_5 -> V_208 ) ;
V_203 = V_209 ;
do {
F_1 ( V_2 , V_14 ) ;
V_205 = F_5 ( V_2 -> V_15 + V_207 ) ;
if ( V_205 == ( V_204 ^ 0xff ) )
return 0 ;
F_70 ( 10 ) ;
} while ( F_71 ( V_209 , V_203 + V_210 / 4 ) );
F_9 ( V_2 -> V_19 , L_17 ) ;
return - V_211 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_64 ;
V_64 = F_69 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_18 ) ;
return V_64 ;
}
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_195 ) ;
V_64 = F_20 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_19 ) ;
return V_64 ;
}
F_11 ( V_2 ) ;
V_64 = F_23 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_20 ) ;
return V_64 ;
}
V_64 = F_29 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_21 ) ;
return V_64 ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_22 ) ;
return V_64 ;
}
F_15 ( V_2 ) ;
V_64 = F_25 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_23 ) ;
return V_64 ;
}
V_64 = F_27 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_24 ) ;
return V_64 ;
}
return 0 ;
}
static int F_74 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
V_64 = F_76 ( V_19 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_25 ) ;
return V_64 ;
}
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_26 ) ;
F_77 ( V_19 ) ;
return V_64 ;
}
V_2 -> V_101 . V_117 = V_140 ;
F_78 ( V_19 ) ;
return 0 ;
}
static int F_79 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
F_80 ( V_19 ) ;
V_2 -> V_101 . V_117 = V_212 ;
V_64 = F_28 ( V_2 , false ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_27 ) ;
return V_64 ;
}
F_81 ( & V_2 -> V_128 ) ;
F_77 ( V_19 ) ;
return 0 ;
}
static int F_82 ( struct V_109 * V_110 , struct V_105 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
struct V_87 * V_88 = (struct V_87 * ) V_110 -> V_72 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
unsigned long V_34 ;
if ( F_83 ( V_19 , V_110 ) )
return V_213 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( ! F_57 ( V_2 ) ) {
F_9 ( V_2 -> V_19 , L_28 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_214 ;
}
F_1 ( V_2 , V_2 -> V_59 + ( V_2 -> V_60 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_60 % 16 ) * sizeof( V_33 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , 1 ) ;
F_34 ( V_2 , V_88 , & V_33 ) ;
F_49 ( V_2 , V_110 ) ;
V_33 . V_42 |= V_215 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
F_3 ( 0x01 , & V_2 -> V_5 -> V_201 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_60 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_60 + 1 ) ;
if ( ! F_57 ( V_2 ) )
F_80 ( V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_213 ;
}
static int F_84 ( struct V_105 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
struct V_216 * V_217 = & V_2 -> V_101 . V_218 ;
struct V_7 V_8 ;
T_1 V_219 , V_220 ;
V_219 = ( ( V_217 -> V_221 - 1 ) & 0x3f ) | ( ( ( V_217 -> V_222 - 1 ) & 0x3 ) << 6 ) ;
V_220 = ( ( V_217 -> V_223 + V_217 -> V_224 - 1 ) & 0xf ) |
( ( ( V_217 -> V_225 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_101 . V_102 & V_226 )
V_220 |= 0x80 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_227 ;
V_8 . V_68 = F_21 ( 4 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = 0x00 ;
V_8 . V_72 [ 2 ] = V_219 ;
V_8 . V_72 [ 3 ] = V_220 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_85 ( struct V_105 * V_19 , enum V_228 V_229 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
if ( V_229 != V_230 )
return - V_231 ;
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_19 , L_26 ) ;
return V_64 ;
}
V_2 -> V_101 . V_117 = V_140 ;
if ( F_65 ( V_19 ) )
F_66 ( V_19 ) ;
return 0 ;
}
static int F_86 ( const struct V_105 * V_19 ,
struct V_232 * V_163 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_161 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_87 ( & V_2 -> V_164 , V_210 ) ;
if ( V_64 == 0 ) {
F_88 ( V_2 -> V_19 , L_29 , V_63 ) ;
return - V_211 ;
}
V_163 -> V_121 = V_2 -> V_163 . V_121 ;
V_163 -> V_122 = V_2 -> V_163 . V_122 ;
return 0 ;
}
static T_4 F_89 ( struct V_233 * V_106 ,
struct V_234 * V_235 ,
char * V_236 )
{
struct V_1 * V_2 = F_75 ( F_90 ( V_106 ) ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_165 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_87 ( & V_2 -> V_167 , V_210 ) ;
if ( V_64 == 0 ) {
F_88 ( V_2 -> V_19 , L_29 , V_63 ) ;
return - V_211 ;
}
return snprintf ( V_236 , V_237 , L_30 , V_2 -> V_166 ) ;
}
static T_4 F_91 ( struct V_233 * V_106 ,
struct V_234 * V_235 ,
const char * V_236 , T_5 V_238 )
{
struct V_1 * V_2 = F_75 ( F_90 ( V_106 ) ) ;
unsigned long V_239 ;
int V_64 ;
if ( F_92 ( V_236 , 0 , & V_239 ) )
return - V_125 ;
V_64 = F_29 ( V_2 , V_239 ) ;
if ( V_64 )
return V_64 ;
return V_238 ;
}
static int F_93 ( struct V_240 * V_241 )
{
struct V_242 * V_243 ;
struct V_105 * V_19 ;
struct V_1 * V_2 ;
struct V_244 * V_245 ;
struct V_233 * V_106 ;
int V_64 ;
V_243 = F_94 ( & V_241 -> V_106 ) ;
if ( ! V_243 )
return - V_246 ;
F_95 ( & V_241 -> V_106 , L_31 , V_243 -> V_247 ) ;
V_106 = & V_241 -> V_106 ;
V_19 = F_96 ( sizeof( * V_2 ) , 0 ) ;
if ( ! V_19 ) {
F_97 ( V_106 , L_32 ) ;
V_64 = - V_20 ;
goto V_248;
}
F_98 ( V_241 , V_19 ) ;
V_2 = F_75 ( V_19 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_168 = V_243 -> V_247 ;
F_99 ( V_19 , & V_2 -> V_190 , F_62 , V_57 ) ;
F_100 ( & V_2 -> V_128 ) ;
F_101 ( & V_2 -> V_37 ) ;
F_102 ( & V_2 -> V_167 ) ;
F_102 ( & V_2 -> V_164 ) ;
V_19 -> V_249 [ 0 ] = & V_250 ;
V_2 -> V_45 = V_206 ;
V_19 -> V_251 = & V_252 ;
V_19 -> V_34 |= V_253 ;
F_103 ( V_19 , & V_241 -> V_106 ) ;
V_2 -> V_101 . clock . V_254 = V_255 ;
V_2 -> V_101 . V_256 = & V_257 ;
V_2 -> V_101 . V_258 = F_84 ;
V_2 -> V_101 . V_259 = F_85 ;
V_2 -> V_101 . V_260 = F_86 ;
V_2 -> V_101 . V_261 = V_226
| V_130
| V_103 ;
V_2 -> V_196 = F_104 ( V_241 , 0 ) ;
if ( V_2 -> V_196 < 0 ) {
F_97 ( V_106 , L_33 ) ;
V_64 = - V_124 ;
goto V_262;
}
V_19 -> V_196 = V_2 -> V_196 ;
V_245 = F_105 ( V_241 , V_263 , 0 ) ;
if ( ! V_245 ) {
F_97 ( V_106 , L_34 ) ;
V_64 = - V_124 ;
goto V_262;
}
V_2 -> V_15 = F_106 ( V_245 -> V_203 , F_107 ( V_245 ) ) ;
if ( ! V_2 -> V_15 ) {
F_97 ( V_106 , L_35 ) ;
V_64 = - V_20 ;
goto V_262;
}
V_2 -> V_5 = V_2 -> V_15 + V_58 ;
V_245 = F_105 ( V_241 , V_263 , 1 ) ;
if ( ! V_245 ) {
F_97 ( V_106 , L_36 ) ;
V_64 = - V_124 ;
goto V_264;
}
V_2 -> V_194 = F_106 ( V_245 -> V_203 , F_107 ( V_245 ) ) ;
if ( ! V_2 -> V_194 ) {
F_97 ( V_106 , L_37 ) ;
V_64 = - V_20 ;
goto V_264;
}
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_199 ) ;
V_64 = F_108 ( V_2 -> V_196 , F_67 , V_265 , V_266 , V_2 ) ;
if ( V_64 ) {
F_97 ( V_106 , L_38 ) ;
goto V_267;
}
F_109 ( & V_2 -> V_190 ) ;
V_64 = F_73 ( V_2 ) ;
if ( V_64 ) {
F_97 ( V_106 , L_39 , V_63 ) ;
goto V_268;
}
V_64 = F_110 ( V_19 ) ;
if ( V_64 ) {
F_97 ( V_106 , L_40 , V_63 ) ;
goto V_268;
}
F_111 ( V_106 , L_41 , V_243 -> V_247 ) ;
return 0 ;
V_268:
F_112 ( & V_2 -> V_190 ) ;
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_199 ) ;
F_113 ( V_2 -> V_196 , V_2 ) ;
V_267:
F_114 ( V_2 -> V_194 ) ;
V_264:
F_114 ( V_2 -> V_15 ) ;
V_262:
F_115 ( V_19 ) ;
V_248:
return V_64 ;
}
static int F_116 ( struct V_240 * V_241 )
{
struct V_105 * V_19 = F_117 ( V_241 ) ;
struct V_1 * V_2 = F_75 ( V_19 ) ;
F_118 ( V_19 ) ;
F_112 ( & V_2 -> V_190 ) ;
F_3 ( 1 << V_2 -> V_168 , & V_2 -> V_194 -> V_199 ) ;
F_113 ( V_2 -> V_196 , V_2 ) ;
F_72 ( V_2 ) ;
F_114 ( V_2 -> V_194 ) ;
F_114 ( V_2 -> V_15 ) ;
F_115 ( V_19 ) ;
return 0 ;
}
