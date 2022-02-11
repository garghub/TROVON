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
struct V_78 * V_79 = & V_2 -> V_80 . V_81 ;
struct V_7 V_8 ;
T_1 V_82 , V_83 ;
int V_84 ;
V_82 = ( ( V_79 -> V_85 - 1 ) & 0x3f ) | ( ( ( V_79 -> V_86 - 1 ) & 0x3 ) << 6 ) ;
V_83 = ( ( V_79 -> V_87 + V_79 -> V_88 - 1 ) & 0xf ) |
( ( ( V_79 -> V_89 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_80 . V_90 & V_91 )
V_83 |= 0x80 ;
if ( V_2 -> V_92 == V_93 ) {
if ( V_77 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_94 ;
V_8 . V_68 = F_21 ( 4 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = 0x00 ;
V_8 . V_72 [ 2 ] = V_82 ;
V_8 . V_72 [ 3 ] = V_83 ;
V_84 = F_18 ( V_2 , & V_8 ) ;
if ( V_84 )
return V_84 ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_77 ? V_95 : V_96 ;
V_8 . V_68 = F_21 ( 0 ) ;
return F_18 ( V_2 , & V_8 ) ;
} else if ( V_2 -> V_92 == V_97 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_98 ;
if ( V_77 ) {
V_8 . V_68 = F_21 ( 4 ) ;
V_8 . V_72 [ 0 ] = 0 ;
V_8 . V_72 [ 1 ] = 0 ;
V_8 . V_72 [ 2 ] = V_82 ;
V_8 . V_72 [ 3 ] = V_83 ;
} else {
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 1 ;
V_8 . V_72 [ 1 ] = 0 ;
}
return F_18 ( V_2 , & V_8 ) ;
}
return - V_99 ;
}
static int F_29 ( struct V_1 * V_2 , bool V_77 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_100 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_77 ? V_101 : V_102 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_103 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_104 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = V_103 ;
V_8 . V_72 [ 1 ] = 0x00 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_106 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_105 ;
return F_18 ( V_2 , & V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_33 ,
struct V_107 * V_108 )
{
if ( ( V_33 -> V_56 & V_109 ) == V_110 ) {
if ( V_33 -> V_72 [ 1 ] & V_111 )
V_108 -> V_112 |= V_113 ;
V_108 -> V_112 |= V_33 -> V_72 [ 0 ] << 3 ;
V_108 -> V_112 |= ( V_33 -> V_72 [ 1 ] & 0xe0 ) >> 5 ;
V_108 -> V_114 = F_33 ( V_33 -> V_72 [ 1 ] & V_115 ) ;
memcpy ( V_108 -> V_72 , & V_33 -> V_72 [ 2 ] , V_108 -> V_114 ) ;
} else {
V_108 -> V_114 = F_33 ( V_33 -> V_72 [ 0 ] & V_115 ) ;
if ( V_33 -> V_72 [ 0 ] & V_116 )
V_108 -> V_112 |= V_113 ;
if ( V_33 -> V_72 [ 0 ] & V_117 ) {
V_108 -> V_112 |= V_118 ;
V_108 -> V_112 |= V_33 -> V_72 [ 2 ] << 21 ;
V_108 -> V_112 |= V_33 -> V_72 [ 3 ] << 13 ;
V_108 -> V_112 |= V_33 -> V_72 [ 4 ] << 5 ;
V_108 -> V_112 |= ( V_33 -> V_72 [ 5 ] & 0xf8 ) >> 3 ;
} else {
V_108 -> V_112 |= V_33 -> V_72 [ 2 ] << 3 ;
V_108 -> V_112 |= V_33 -> V_72 [ 3 ] >> 5 ;
}
memcpy ( V_108 -> V_72 , & V_33 -> V_72 [ 6 ] , V_108 -> V_114 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
struct V_52 * V_33 )
{
memset ( V_33 -> V_72 , 0 , sizeof( V_33 -> V_72 ) ) ;
V_33 -> V_56 = V_119 ;
V_33 -> V_72 [ 0 ] |= V_108 -> V_114 ;
V_33 -> V_72 [ 1 ] |= V_120 ;
if ( V_2 -> V_80 . V_90 & V_121 )
V_33 -> V_72 [ 1 ] |= V_122 ;
if ( V_108 -> V_112 & V_113 )
V_33 -> V_72 [ 0 ] |= V_116 ;
if ( V_108 -> V_112 & V_118 ) {
V_33 -> V_72 [ 0 ] |= V_117 ;
V_33 -> V_72 [ 2 ] = ( V_108 -> V_112 & 0x1fe00000 ) >> 21 ;
V_33 -> V_72 [ 3 ] = ( V_108 -> V_112 & 0x001fe000 ) >> 13 ;
V_33 -> V_72 [ 4 ] = ( V_108 -> V_112 & 0x00001fe0 ) >> 5 ;
V_33 -> V_72 [ 5 ] = ( V_108 -> V_112 & 0x0000001f ) << 3 ;
} else {
V_33 -> V_72 [ 2 ] = ( V_108 -> V_112 & 0x7F8 ) >> 3 ;
V_33 -> V_72 [ 3 ] = ( V_108 -> V_112 & 0x007 ) << 5 ;
}
memcpy ( & V_33 -> V_72 [ 6 ] , V_108 -> V_72 , V_108 -> V_114 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_5 , V_8 -> V_72 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_123 * V_124 = V_2 -> V_19 ;
struct V_125 * V_126 = & V_124 -> V_126 ;
struct V_107 * V_108 ;
struct V_127 * V_128 ;
if ( V_8 -> V_66 == V_129 ) {
F_9 ( V_2 -> V_19 , L_6 , V_8 -> V_72 [ 0 ] ) ;
return;
}
V_128 = F_37 ( V_124 , & V_108 ) ;
if ( V_128 ) {
V_108 -> V_112 |= V_130 ;
V_108 -> V_72 [ 1 ] = V_131 ;
V_126 -> V_132 ++ ;
V_126 -> V_133 ++ ;
F_38 ( V_128 ) ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_123 * V_124 = V_2 -> V_19 ;
struct V_125 * V_126 = & V_124 -> V_126 ;
enum V_134 V_135 = V_2 -> V_80 . V_135 ;
T_1 V_136 , V_137 , V_138 , V_139 , V_140 ;
struct V_107 * V_108 ;
struct V_127 * V_128 ;
if ( V_8 -> V_72 [ 1 ] != V_141 ) {
F_9 ( V_2 -> V_19 , L_7 ) ;
return - V_142 ;
}
if ( F_40 ( V_8 -> V_68 ) < 6 ) {
F_9 ( V_2 -> V_19 , L_8 ) ;
return - V_143 ;
}
V_136 = V_8 -> V_72 [ 0 ] ;
V_137 = V_8 -> V_72 [ 2 ] ;
V_138 = V_8 -> V_72 [ 3 ] ;
V_139 = V_8 -> V_72 [ 4 ] ;
V_140 = V_8 -> V_72 [ 5 ] ;
if ( V_136 == V_144 ) {
int V_64 ;
F_6 ( V_2 -> V_19 , L_9 ) ;
if ( ! ( V_137 & V_145 ) ) {
F_41 ( F_42 ( & V_2 -> V_146 ) ) ;
V_126 -> V_147 ++ ;
} else {
V_126 -> V_133 ++ ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_10 ) ;
return V_64 ;
}
if ( ! ( V_2 -> V_80 . V_90 & V_148 ) )
return 0 ;
}
V_128 = F_37 ( V_124 , & V_108 ) ;
if ( V_128 == NULL )
return - V_20 ;
if ( V_136 == V_149 || V_136 == V_150 ) {
F_6 ( V_2 -> V_19 , L_11 ) ;
V_108 -> V_112 |= V_130 ;
V_108 -> V_72 [ 1 ] = V_131 ;
V_126 -> V_132 ++ ;
V_126 -> V_133 ++ ;
}
if ( V_136 == V_151 ) {
F_6 ( V_2 -> V_19 , L_12 ) ;
if ( V_138 & V_152 ) {
V_135 = V_153 ;
V_108 -> V_112 |= V_154 ;
V_2 -> V_80 . V_155 . V_156 ++ ;
F_43 ( V_124 ) ;
} else if ( V_138 & V_157 ) {
if ( V_139 >= 128 || V_140 >= 128 )
V_135 = V_158 ;
else
V_135 = V_159 ;
} else {
V_135 = V_160 ;
}
}
if ( V_136 == V_144 ) {
V_2 -> V_80 . V_155 . V_161 ++ ;
V_108 -> V_112 |= V_162 | V_163 ;
switch ( V_137 & V_164 ) {
case V_165 :
V_108 -> V_72 [ 2 ] |= V_166 ;
break;
case V_167 :
V_108 -> V_72 [ 2 ] |= V_168 ;
break;
case V_169 :
V_108 -> V_72 [ 2 ] |= V_170 ;
break;
default:
V_108 -> V_72 [ 2 ] |= V_171 ;
V_108 -> V_72 [ 3 ] = V_137 & V_172 ;
break;
}
if ( ! ( V_137 & V_145 ) )
V_108 -> V_72 [ 2 ] |= V_173 ;
V_108 -> V_72 [ 6 ] = V_140 ;
V_108 -> V_72 [ 7 ] = V_139 ;
}
if ( V_135 != V_2 -> V_80 . V_135 && ( V_135 == V_159 ||
V_135 == V_158 ) ) {
V_108 -> V_112 |= V_130 ;
if ( V_135 == V_159 ) {
V_2 -> V_80 . V_155 . V_174 ++ ;
V_108 -> V_72 [ 1 ] = ( V_140 > V_139 ) ?
V_175 :
V_176 ;
} else {
V_2 -> V_80 . V_155 . V_177 ++ ;
V_108 -> V_72 [ 1 ] = ( V_140 > V_139 ) ?
V_178 :
V_179 ;
}
V_108 -> V_72 [ 6 ] = V_140 ;
V_108 -> V_72 [ 7 ] = V_139 ;
}
V_2 -> V_80 . V_135 = V_135 ;
F_38 ( V_128 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
switch ( V_8 -> V_72 [ 0 ] ) {
case V_180 :
case V_181 :
V_2 -> V_182 . V_139 = V_8 -> V_72 [ 5 ] ;
V_2 -> V_182 . V_140 = V_8 -> V_72 [ 6 ] ;
F_45 ( & V_2 -> V_183 ) ;
break;
case V_184 :
V_2 -> V_185 = V_8 -> V_72 [ 6 ] & V_101 ;
F_45 ( & V_2 -> V_186 ) ;
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
V_2 -> V_187 , V_8 -> V_66 , F_40 ( V_8 -> V_68 ) ) ;
switch ( V_8 -> V_66 ) {
case V_188 :
F_35 ( V_2 , V_8 ) ;
break;
case V_129 :
case V_189 :
F_36 ( V_2 , V_8 ) ;
break;
case V_190 :
F_39 ( V_2 , V_8 ) ;
break;
case V_104 :
F_44 ( V_2 , V_8 ) ;
break;
default:
F_46 ( V_2 , V_8 ) ;
break;
}
}
static void F_49 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
V_128 = F_50 ( V_128 ) ;
if ( ! V_128 )
return;
F_51 ( & V_2 -> V_146 , V_128 ) ;
}
static unsigned int F_52 ( struct V_1 * V_2 )
{
struct V_127 * V_128 = F_42 ( & V_2 -> V_146 ) ;
struct V_107 * V_108 ;
T_1 V_191 ;
if ( ! V_128 ) {
F_9 ( V_2 -> V_19 , L_16 ) ;
return 0 ;
}
V_108 = (struct V_107 * ) V_128 -> V_72 ;
V_191 = V_108 -> V_114 ;
if ( V_128 -> V_192 != V_193 ) {
F_41 ( V_128 ) ;
return V_191 ;
}
V_128 -> V_194 = F_53 ( V_195 ) ;
V_128 -> V_192 = V_196 ;
V_128 -> V_197 = V_198 ;
V_128 -> V_124 = V_2 -> V_19 ;
F_54 ( V_128 ) ;
return V_191 ;
}
static bool F_55 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_107 * V_108 = (struct V_107 * ) V_128 -> V_72 ;
struct V_127 * V_199 = F_56 ( & V_2 -> V_146 ) ;
struct V_107 * V_200 ;
if ( ! V_199 )
return false ;
V_200 = (struct V_107 * ) V_199 -> V_72 ;
if ( V_108 -> V_112 != V_200 -> V_112 )
return false ;
if ( V_108 -> V_114 != V_200 -> V_114 )
return false ;
return memcmp ( V_108 -> V_72 , V_200 -> V_72 , V_108 -> V_114 ) == 0 ;
}
static bool F_57 ( struct V_1 * V_2 )
{
struct V_52 T_2 * V_33 ;
T_1 V_42 ;
if ( F_58 ( & V_2 -> V_146 ) >= V_61 )
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
struct V_123 * V_19 = V_2 -> V_19 ;
struct V_125 * V_126 = & V_19 -> V_126 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
struct V_107 * V_108 ;
struct V_127 * V_128 ;
unsigned long V_34 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_55 % 16 ) * sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , sizeof( V_33 ) ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
if ( ! ( V_33 . V_42 & V_49 ) )
return - V_201 ;
V_128 = F_60 ( V_19 , & V_108 ) ;
if ( F_61 ( V_128 == NULL ) ) {
V_126 -> V_202 ++ ;
goto V_203;
}
F_32 ( V_2 , & V_33 , V_108 ) ;
if ( F_55 ( V_2 , V_128 ) ) {
V_126 -> V_204 ++ ;
V_126 -> V_205 += F_52 ( V_2 ) ;
F_41 ( V_128 ) ;
goto V_203;
}
V_126 -> V_206 ++ ;
V_126 -> V_207 += V_108 -> V_114 ;
F_54 ( V_128 ) ;
V_203:
V_33 . V_42 ^= V_49 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
F_10 ( V_62 , & V_33 , 1 ) ;
V_2 -> V_55 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_55 + 1 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_62 ( struct V_208 * V_209 , int V_210 )
{
struct V_1 * V_2 = F_63 ( V_209 , struct V_1 , V_209 ) ;
unsigned long V_34 ;
int V_211 = 0 ;
int V_64 ;
while ( true ) {
struct V_7 V_212 ( V_8 ) ;
V_64 = F_19 ( V_2 , & V_8 ) ;
if ( V_64 )
break;
F_48 ( V_2 , & V_8 ) ;
}
while ( V_211 < V_210 ) {
V_64 = F_59 ( V_2 ) ;
if ( V_64 )
break;
V_211 ++ ;
}
if ( V_211 < V_210 )
F_64 ( V_209 ) ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( F_65 ( V_2 -> V_19 ) && F_57 ( V_2 ) )
F_66 ( V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_214 ) ;
return V_211 ;
}
static T_3 F_67 ( int V_215 , void * V_216 )
{
struct V_1 * V_2 = V_216 ;
T_1 V_217 ;
V_217 = F_5 ( & V_2 -> V_213 -> V_218 ) & ( 1 << V_2 -> V_187 ) ;
if ( V_217 == ( 1 << V_2 -> V_187 ) )
return V_219 ;
F_5 ( & V_2 -> V_5 -> V_220 ) ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_218 ) ;
F_68 ( & V_2 -> V_209 ) ;
return V_221 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned long V_222 ;
T_1 V_223 , V_224 ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_218 ) ;
V_2 -> V_45 = V_225 ;
F_1 ( V_2 , V_14 ) ;
V_223 = F_5 ( V_2 -> V_15 + V_226 ) ;
F_3 ( 0x00 , & V_2 -> V_5 -> V_227 ) ;
V_222 = V_228 ;
do {
F_1 ( V_2 , V_14 ) ;
V_224 = F_5 ( V_2 -> V_15 + V_226 ) ;
if ( V_224 == ( V_223 ^ 0xff ) )
return 0 ;
F_70 ( 10 ) ;
} while ( F_71 ( V_228 , V_222 + V_229 / 2 ) );
F_9 ( V_2 -> V_19 , L_17 ) ;
return - V_230 ;
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
F_7 ( V_2 -> V_231 , V_2 -> V_15 + V_232 , sizeof( V_2 -> V_231 ) - 1 ) ;
if ( strncmp ( V_2 -> V_231 , L_19 , 10 ) ) {
F_9 ( V_2 -> V_19 , L_20 , V_2 -> V_231 ) ;
return - V_142 ;
}
if ( strstr ( V_2 -> V_231 , L_21 ) )
V_2 -> V_92 = V_97 ;
else
V_2 -> V_92 = V_93 ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_214 ) ;
V_64 = F_20 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_22 ) ;
return V_64 ;
}
F_11 ( V_2 ) ;
V_64 = F_23 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_23 ) ;
return V_64 ;
}
V_64 = F_29 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_24 ) ;
return V_64 ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_25 ) ;
return V_64 ;
}
F_15 ( V_2 ) ;
V_64 = F_25 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_26 ) ;
return V_64 ;
}
V_64 = F_27 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_27 ) ;
return V_64 ;
}
return 0 ;
}
static int F_74 ( struct V_123 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
V_64 = F_76 ( V_19 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_28 ) ;
return V_64 ;
}
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_29 ) ;
F_77 ( V_19 ) ;
return V_64 ;
}
V_2 -> V_80 . V_135 = V_160 ;
F_78 ( V_19 ) ;
return 0 ;
}
static int F_79 ( struct V_123 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
F_80 ( V_19 ) ;
V_2 -> V_80 . V_135 = V_233 ;
V_64 = F_28 ( V_2 , false ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_30 ) ;
return V_64 ;
}
F_81 ( & V_2 -> V_146 ) ;
F_77 ( V_19 ) ;
return 0 ;
}
static int F_82 ( struct V_127 * V_128 , struct V_123 * V_19 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
struct V_107 * V_108 = (struct V_107 * ) V_128 -> V_72 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
unsigned long V_34 ;
if ( F_83 ( V_19 , V_128 ) )
return V_234 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( ! F_57 ( V_2 ) ) {
F_9 ( V_2 -> V_19 , L_31 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_235 ;
}
F_1 ( V_2 , V_2 -> V_59 + ( V_2 -> V_60 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_60 % 16 ) * sizeof( V_33 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , 1 ) ;
F_34 ( V_2 , V_108 , & V_33 ) ;
F_49 ( V_2 , V_128 ) ;
V_33 . V_42 |= V_236 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
F_3 ( 0x01 , & V_2 -> V_5 -> V_220 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_60 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_60 + 1 ) ;
if ( ! F_57 ( V_2 ) )
F_80 ( V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_234 ;
}
static int F_84 ( struct V_123 * V_19 , enum V_237 V_238 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
if ( V_238 != V_239 )
return - V_99 ;
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_19 , L_29 ) ;
return V_64 ;
}
V_2 -> V_80 . V_135 = V_160 ;
if ( F_65 ( V_19 ) )
F_66 ( V_19 ) ;
return 0 ;
}
static int F_85 ( const struct V_123 * V_19 ,
struct V_240 * V_182 )
{
struct V_1 * V_2 = F_75 ( V_19 ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_180 ) ;
if ( V_64 )
return V_64 ;
if ( ! F_86 ( & V_2 -> V_183 , V_229 ) ) {
F_87 ( V_2 -> V_19 , L_32 , V_63 ) ;
return - V_230 ;
}
V_182 -> V_139 = V_2 -> V_182 . V_139 ;
V_182 -> V_140 = V_2 -> V_182 . V_140 ;
return 0 ;
}
static T_4 F_88 ( struct V_241 * V_124 ,
struct V_242 * V_243 ,
char * V_244 )
{
struct V_1 * V_2 = F_75 ( F_89 ( V_124 ) ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_184 ) ;
if ( V_64 )
return V_64 ;
if ( ! F_86 ( & V_2 -> V_186 , V_229 ) ) {
F_87 ( V_2 -> V_19 , L_32 , V_63 ) ;
return - V_230 ;
}
return snprintf ( V_244 , V_245 , L_33 , V_2 -> V_185 ) ;
}
static T_4 F_90 ( struct V_241 * V_124 ,
struct V_242 * V_243 ,
const char * V_244 , T_5 V_246 )
{
struct V_1 * V_2 = F_75 ( F_89 ( V_124 ) ) ;
unsigned long V_247 ;
int V_64 ;
if ( F_91 ( V_244 , 0 , & V_247 ) )
return - V_143 ;
V_64 = F_29 ( V_2 , V_247 ) ;
if ( V_64 )
return V_64 ;
return V_246 ;
}
static T_4 F_92 ( struct V_241 * V_124 ,
struct V_242 * V_243 ,
char * V_244 )
{
struct V_1 * V_2 = F_75 ( F_89 ( V_124 ) ) ;
return F_93 ( V_244 , V_245 , L_34 , V_2 -> V_231 ) ;
}
static int F_94 ( struct V_248 * V_249 )
{
struct V_250 * V_251 ;
struct V_123 * V_19 ;
struct V_1 * V_2 ;
struct V_252 * V_84 ;
struct V_241 * V_124 ;
int V_64 ;
V_251 = F_95 ( & V_249 -> V_124 ) ;
if ( ! V_251 )
return - V_253 ;
F_96 ( & V_249 -> V_124 , L_35 , V_251 -> V_254 ) ;
V_124 = & V_249 -> V_124 ;
V_19 = F_97 ( sizeof( * V_2 ) , 0 ) ;
if ( ! V_19 ) {
F_98 ( V_124 , L_36 ) ;
V_64 = - V_20 ;
goto V_255;
}
F_99 ( V_249 , V_19 ) ;
V_2 = F_75 ( V_19 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_187 = V_251 -> V_254 ;
F_100 ( V_19 , & V_2 -> V_209 , F_62 , V_57 ) ;
F_101 ( & V_2 -> V_146 ) ;
F_102 ( & V_2 -> V_37 ) ;
F_103 ( & V_2 -> V_186 ) ;
F_103 ( & V_2 -> V_183 ) ;
V_19 -> V_256 [ 0 ] = & V_257 ;
V_2 -> V_45 = V_225 ;
V_19 -> V_258 = & V_259 ;
V_19 -> V_34 |= V_260 ;
F_104 ( V_19 , & V_249 -> V_124 ) ;
V_2 -> V_80 . clock . V_261 = V_262 ;
V_2 -> V_80 . V_263 = & V_264 ;
V_2 -> V_80 . V_265 = F_84 ;
V_2 -> V_80 . V_266 = F_85 ;
V_2 -> V_80 . V_267 = V_91
| V_148
| V_121 ;
V_2 -> V_215 = F_105 ( V_249 , 0 ) ;
if ( V_2 -> V_215 < 0 ) {
F_98 ( V_124 , L_37 ) ;
V_64 = - V_142 ;
goto V_268;
}
V_19 -> V_215 = V_2 -> V_215 ;
V_84 = F_106 ( V_249 , V_269 , 0 ) ;
if ( ! V_84 ) {
F_98 ( V_124 , L_38 ) ;
V_64 = - V_142 ;
goto V_268;
}
V_2 -> V_15 = F_107 ( V_84 -> V_222 , F_108 ( V_84 ) ) ;
if ( ! V_2 -> V_15 ) {
F_98 ( V_124 , L_39 ) ;
V_64 = - V_20 ;
goto V_268;
}
V_2 -> V_5 = V_2 -> V_15 + V_58 ;
V_84 = F_106 ( V_249 , V_269 , 1 ) ;
if ( ! V_84 ) {
F_98 ( V_124 , L_40 ) ;
V_64 = - V_142 ;
goto V_270;
}
V_2 -> V_213 = F_107 ( V_84 -> V_222 , F_108 ( V_84 ) ) ;
if ( ! V_2 -> V_213 ) {
F_98 ( V_124 , L_41 ) ;
V_64 = - V_20 ;
goto V_270;
}
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_218 ) ;
V_64 = F_109 ( V_2 -> V_215 , F_67 , V_271 , V_272 , V_2 ) ;
if ( V_64 ) {
F_98 ( V_124 , L_42 ) ;
goto V_273;
}
F_110 ( & V_2 -> V_209 ) ;
V_64 = F_73 ( V_2 ) ;
if ( V_64 ) {
F_98 ( V_124 , L_43 , V_63 ) ;
goto V_274;
}
V_64 = F_111 ( V_19 ) ;
if ( V_64 ) {
F_98 ( V_124 , L_44 , V_63 ) ;
goto V_274;
}
F_87 ( V_2 -> V_19 , L_45 , V_251 -> V_254 ) ;
return 0 ;
V_274:
F_112 ( & V_2 -> V_209 ) ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_218 ) ;
F_113 ( V_2 -> V_215 , V_2 ) ;
V_273:
F_114 ( V_2 -> V_213 ) ;
V_270:
F_114 ( V_2 -> V_15 ) ;
V_268:
F_115 ( V_19 ) ;
V_255:
return V_64 ;
}
static int F_116 ( struct V_248 * V_249 )
{
struct V_123 * V_19 = F_117 ( V_249 ) ;
struct V_1 * V_2 = F_75 ( V_19 ) ;
F_118 ( V_19 ) ;
F_112 ( & V_2 -> V_209 ) ;
F_3 ( 1 << V_2 -> V_187 , & V_2 -> V_213 -> V_218 ) ;
F_113 ( V_2 -> V_215 , V_2 ) ;
F_72 ( V_2 ) ;
F_114 ( V_2 -> V_213 ) ;
F_114 ( V_2 -> V_15 ) ;
F_115 ( V_19 ) ;
return 0 ;
}
