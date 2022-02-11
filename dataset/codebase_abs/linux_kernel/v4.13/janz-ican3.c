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
V_8 . V_72 [ 0 ] = V_99 ;
V_8 . V_72 [ 1 ] = 0 ;
V_8 . V_72 [ 2 ] = V_82 ;
V_8 . V_72 [ 3 ] = V_83 ;
} else {
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = V_100 ;
V_8 . V_72 [ 1 ] = 0 ;
}
V_84 = F_18 ( V_2 , & V_8 ) ;
if ( V_84 )
return V_84 ;
if ( V_77 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_101 ;
V_8 . V_68 = F_21 ( 11 ) ;
V_8 . V_72 [ 0 ] = V_102 ;
V_8 . V_72 [ 1 ] = 0 ;
V_8 . V_72 [ 2 ] = 2 ;
V_8 . V_72 [ 3 ] = 1 ;
strcpy ( V_8 . V_72 + 4 , L_5 ) ;
return F_18 ( V_2 , & V_8 ) ;
}
return 0 ;
}
return - V_103 ;
}
static int F_29 ( struct V_1 * V_2 , bool V_77 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_104 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_77 ? V_105 : V_106 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_108 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = V_107 ;
V_8 . V_72 [ 1 ] = 0x00 ;
return F_18 ( V_2 , & V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_7 V_8 ;
if ( V_2 -> V_92 == V_93 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_110 ;
V_8 . V_68 = F_21 ( 2 ) ;
V_8 . V_72 [ 0 ] = 0x00 ;
V_8 . V_72 [ 1 ] = V_109 ;
} else if ( V_2 -> V_92 == V_97 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_66 = V_98 ;
V_8 . V_68 = F_21 ( 4 ) ;
V_8 . V_72 [ 0 ] = V_111 ;
V_8 . V_72 [ 1 ] = 0x00 ;
V_8 . V_72 [ 2 ] = 0x00 ;
V_8 . V_72 [ 3 ] = V_109 ;
} else {
return - V_103 ;
}
return F_18 ( V_2 , & V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_33 ,
struct V_112 * V_113 )
{
if ( ( V_33 -> V_56 & V_114 ) == V_115 ) {
if ( V_33 -> V_72 [ 1 ] & V_116 )
V_113 -> V_117 |= V_118 ;
V_113 -> V_117 |= V_33 -> V_72 [ 0 ] << 3 ;
V_113 -> V_117 |= ( V_33 -> V_72 [ 1 ] & 0xe0 ) >> 5 ;
V_113 -> V_119 = F_33 ( V_33 -> V_72 [ 1 ] & V_120 ) ;
memcpy ( V_113 -> V_72 , & V_33 -> V_72 [ 2 ] , V_113 -> V_119 ) ;
} else {
V_113 -> V_119 = F_33 ( V_33 -> V_72 [ 0 ] & V_120 ) ;
if ( V_33 -> V_72 [ 0 ] & V_121 )
V_113 -> V_117 |= V_118 ;
if ( V_33 -> V_72 [ 0 ] & V_122 ) {
V_113 -> V_117 |= V_123 ;
V_113 -> V_117 |= V_33 -> V_72 [ 2 ] << 21 ;
V_113 -> V_117 |= V_33 -> V_72 [ 3 ] << 13 ;
V_113 -> V_117 |= V_33 -> V_72 [ 4 ] << 5 ;
V_113 -> V_117 |= ( V_33 -> V_72 [ 5 ] & 0xf8 ) >> 3 ;
} else {
V_113 -> V_117 |= V_33 -> V_72 [ 2 ] << 3 ;
V_113 -> V_117 |= V_33 -> V_72 [ 3 ] >> 5 ;
}
memcpy ( V_113 -> V_72 , & V_33 -> V_72 [ 6 ] , V_113 -> V_119 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
struct V_52 * V_33 )
{
memset ( V_33 -> V_72 , 0 , sizeof( V_33 -> V_72 ) ) ;
V_33 -> V_56 = V_124 ;
V_33 -> V_72 [ 0 ] |= V_113 -> V_119 ;
V_33 -> V_72 [ 1 ] |= V_125 ;
if ( V_2 -> V_80 . V_90 & V_126 )
V_33 -> V_72 [ 1 ] |= V_127 ;
if ( V_113 -> V_117 & V_118 )
V_33 -> V_72 [ 0 ] |= V_121 ;
if ( V_113 -> V_117 & V_123 ) {
V_33 -> V_72 [ 0 ] |= V_122 ;
V_33 -> V_72 [ 2 ] = ( V_113 -> V_117 & 0x1fe00000 ) >> 21 ;
V_33 -> V_72 [ 3 ] = ( V_113 -> V_117 & 0x001fe000 ) >> 13 ;
V_33 -> V_72 [ 4 ] = ( V_113 -> V_117 & 0x00001fe0 ) >> 5 ;
V_33 -> V_72 [ 5 ] = ( V_113 -> V_117 & 0x0000001f ) << 3 ;
} else {
V_33 -> V_72 [ 2 ] = ( V_113 -> V_117 & 0x7F8 ) >> 3 ;
V_33 -> V_72 [ 3 ] = ( V_113 -> V_117 & 0x007 ) << 5 ;
}
memcpy ( & V_33 -> V_72 [ 6 ] , V_113 -> V_72 , V_113 -> V_119 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_6 , V_8 -> V_72 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_128 * V_129 = V_2 -> V_19 ;
struct V_130 * V_131 = & V_129 -> V_131 ;
struct V_112 * V_113 ;
struct V_132 * V_133 ;
if ( V_8 -> V_66 == V_134 ) {
F_9 ( V_2 -> V_19 , L_7 , V_8 -> V_72 [ 0 ] ) ;
return;
}
V_133 = F_37 ( V_129 , & V_113 ) ;
if ( V_133 ) {
V_113 -> V_117 |= V_135 ;
V_113 -> V_72 [ 1 ] = V_136 ;
V_131 -> V_137 ++ ;
V_131 -> V_138 ++ ;
F_38 ( V_133 ) ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_128 * V_129 = V_2 -> V_19 ;
struct V_130 * V_131 = & V_129 -> V_131 ;
enum V_139 V_140 = V_2 -> V_80 . V_140 ;
T_1 V_141 , V_142 , V_143 , V_144 , V_145 ;
struct V_112 * V_113 ;
struct V_132 * V_133 ;
if ( V_8 -> V_72 [ 1 ] != V_146 ) {
F_9 ( V_2 -> V_19 , L_8 ) ;
return - V_147 ;
}
if ( F_40 ( V_8 -> V_68 ) < 6 ) {
F_9 ( V_2 -> V_19 , L_9 ) ;
return - V_148 ;
}
V_141 = V_8 -> V_72 [ 0 ] ;
V_142 = V_8 -> V_72 [ 2 ] ;
V_143 = V_8 -> V_72 [ 3 ] ;
V_144 = V_8 -> V_72 [ 4 ] ;
V_145 = V_8 -> V_72 [ 5 ] ;
if ( V_141 == V_149 ) {
int V_64 ;
F_6 ( V_2 -> V_19 , L_10 ) ;
if ( ! ( V_142 & V_150 ) ) {
F_41 ( F_42 ( & V_2 -> V_151 ) ) ;
V_131 -> V_152 ++ ;
} else {
V_131 -> V_138 ++ ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_11 ) ;
return V_64 ;
}
if ( ! ( V_2 -> V_80 . V_90 & V_153 ) )
return 0 ;
}
V_133 = F_37 ( V_129 , & V_113 ) ;
if ( V_133 == NULL )
return - V_20 ;
if ( V_141 == V_154 || V_141 == V_155 ) {
F_6 ( V_2 -> V_19 , L_12 ) ;
V_113 -> V_117 |= V_135 ;
V_113 -> V_72 [ 1 ] = V_136 ;
V_131 -> V_137 ++ ;
V_131 -> V_138 ++ ;
}
if ( V_141 == V_156 ) {
F_6 ( V_2 -> V_19 , L_13 ) ;
if ( V_143 & V_157 ) {
V_140 = V_158 ;
V_113 -> V_117 |= V_159 ;
V_2 -> V_80 . V_160 . V_161 ++ ;
F_43 ( V_129 ) ;
} else if ( V_143 & V_162 ) {
if ( V_144 >= 128 || V_145 >= 128 )
V_140 = V_163 ;
else
V_140 = V_164 ;
} else {
V_140 = V_165 ;
}
}
if ( V_141 == V_149 ) {
V_2 -> V_80 . V_160 . V_166 ++ ;
V_113 -> V_117 |= V_167 | V_168 ;
switch ( V_142 & V_169 ) {
case V_170 :
V_113 -> V_72 [ 2 ] |= V_171 ;
break;
case V_172 :
V_113 -> V_72 [ 2 ] |= V_173 ;
break;
case V_174 :
V_113 -> V_72 [ 2 ] |= V_175 ;
break;
default:
V_113 -> V_72 [ 3 ] = V_142 & V_176 ;
break;
}
if ( ! ( V_142 & V_150 ) )
V_113 -> V_72 [ 2 ] |= V_177 ;
V_113 -> V_72 [ 6 ] = V_145 ;
V_113 -> V_72 [ 7 ] = V_144 ;
}
if ( V_140 != V_2 -> V_80 . V_140 && ( V_140 == V_164 ||
V_140 == V_163 ) ) {
V_113 -> V_117 |= V_135 ;
if ( V_140 == V_164 ) {
V_2 -> V_80 . V_160 . V_178 ++ ;
V_113 -> V_72 [ 1 ] = ( V_145 > V_144 ) ?
V_179 :
V_180 ;
} else {
V_2 -> V_80 . V_160 . V_181 ++ ;
V_113 -> V_72 [ 1 ] = ( V_145 > V_144 ) ?
V_182 :
V_183 ;
}
V_113 -> V_72 [ 6 ] = V_145 ;
V_113 -> V_72 [ 7 ] = V_144 ;
}
V_2 -> V_80 . V_140 = V_140 ;
F_38 ( V_133 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
switch ( V_8 -> V_72 [ 0 ] ) {
case V_184 :
case V_185 :
V_2 -> V_186 . V_144 = V_8 -> V_72 [ 5 ] ;
V_2 -> V_186 . V_145 = V_8 -> V_72 [ 6 ] ;
F_45 ( & V_2 -> V_187 ) ;
break;
case V_188 :
V_2 -> V_189 = V_8 -> V_72 [ 6 ] & V_105 ;
F_45 ( & V_2 -> V_190 ) ;
break;
default:
F_9 ( V_2 -> V_19 , L_14 ) ;
break;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_3 V_107 ;
V_107 = V_8 -> V_72 [ 0 ] + V_8 -> V_72 [ 1 ] * 0x100 ;
if ( V_107 == V_191 ) {
switch ( V_8 -> V_72 [ 2 ] ) {
case V_192 :
case V_193 :
F_47 ( & V_8 -> V_68 , - 3 ) ;
memmove ( V_8 -> V_72 , V_8 -> V_72 + 3 , F_40 ( V_8 -> V_68 ) ) ;
F_39 ( V_2 , V_8 ) ;
break;
case V_194 :
case V_195 :
break;
default:
F_48 ( V_2 -> V_19 , L_15 ,
V_8 -> V_72 [ 2 ] ) ;
break;
}
} else if ( V_107 == V_196 ) {
} else {
F_48 ( V_2 -> V_19 , L_16 ,
V_107 ) ;
return;
}
}
static void F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_48 ( V_2 -> V_19 , L_17 ,
V_8 -> V_66 , F_40 ( V_8 -> V_68 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_19 , L_18 , V_63 ,
V_2 -> V_197 , V_8 -> V_66 , F_40 ( V_8 -> V_68 ) ) ;
switch ( V_8 -> V_66 ) {
case V_198 :
F_35 ( V_2 , V_8 ) ;
break;
case V_134 :
case V_199 :
F_36 ( V_2 , V_8 ) ;
break;
case V_200 :
F_39 ( V_2 , V_8 ) ;
break;
case V_108 :
F_44 ( V_2 , V_8 ) ;
break;
case V_101 :
F_46 ( V_2 , V_8 ) ;
break;
default:
F_49 ( V_2 , V_8 ) ;
break;
}
}
static void F_51 ( struct V_1 * V_2 , struct V_132 * V_133 )
{
V_133 = F_52 ( V_133 ) ;
if ( ! V_133 )
return;
F_53 ( & V_2 -> V_151 , V_133 ) ;
}
static unsigned int F_54 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = F_42 ( & V_2 -> V_151 ) ;
struct V_112 * V_113 ;
T_1 V_201 ;
if ( ! V_133 ) {
F_9 ( V_2 -> V_19 , L_19 ) ;
return 0 ;
}
V_113 = (struct V_112 * ) V_133 -> V_72 ;
V_201 = V_113 -> V_119 ;
if ( V_133 -> V_202 != V_203 ) {
F_41 ( V_133 ) ;
return V_201 ;
}
V_133 -> V_204 = F_55 ( V_205 ) ;
V_133 -> V_202 = V_206 ;
V_133 -> V_207 = V_208 ;
V_133 -> V_129 = V_2 -> V_19 ;
F_56 ( V_133 ) ;
return V_201 ;
}
static bool F_57 ( struct V_1 * V_2 , struct V_132 * V_133 )
{
struct V_112 * V_113 = (struct V_112 * ) V_133 -> V_72 ;
struct V_132 * V_209 = F_58 ( & V_2 -> V_151 ) ;
struct V_112 * V_210 ;
if ( ! V_209 )
return false ;
V_210 = (struct V_112 * ) V_209 -> V_72 ;
if ( V_113 -> V_117 != V_210 -> V_117 )
return false ;
if ( V_113 -> V_119 != V_210 -> V_119 )
return false ;
return memcmp ( V_113 -> V_72 , V_210 -> V_72 , V_113 -> V_119 ) == 0 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
struct V_52 T_2 * V_33 ;
T_1 V_42 ;
if ( F_60 ( & V_2 -> V_151 ) >= V_61 )
return false ;
F_1 ( V_2 , V_2 -> V_59 + ( V_2 -> V_60 / 16 ) ) ;
V_33 = V_2 -> V_15 + ( ( V_2 -> V_60 % 16 ) * sizeof( * V_33 ) ) ;
V_42 = F_5 ( & V_33 -> V_42 ) ;
if ( ! ( V_42 & V_49 ) )
return false ;
return true ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_128 * V_19 = V_2 -> V_19 ;
struct V_130 * V_131 = & V_19 -> V_131 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
struct V_112 * V_113 ;
struct V_132 * V_133 ;
unsigned long V_34 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_55 % 16 ) * sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , sizeof( V_33 ) ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
if ( ! ( V_33 . V_42 & V_49 ) )
return - V_211 ;
V_133 = F_62 ( V_19 , & V_113 ) ;
if ( F_63 ( V_133 == NULL ) ) {
V_131 -> V_212 ++ ;
goto V_213;
}
F_32 ( V_2 , & V_33 , V_113 ) ;
if ( F_57 ( V_2 , V_133 ) ) {
V_131 -> V_214 ++ ;
V_131 -> V_215 += F_54 ( V_2 ) ;
F_41 ( V_133 ) ;
goto V_213;
}
V_131 -> V_216 ++ ;
V_131 -> V_217 += V_113 -> V_119 ;
F_56 ( V_133 ) ;
V_213:
V_33 . V_42 ^= V_49 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_2 -> V_54 + ( V_2 -> V_55 / 16 ) ) ;
F_10 ( V_62 , & V_33 , 1 ) ;
V_2 -> V_55 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_55 + 1 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_64 ( struct V_218 * V_219 , int V_220 )
{
struct V_1 * V_2 = F_65 ( V_219 , struct V_1 , V_219 ) ;
unsigned long V_34 ;
int V_221 = 0 ;
int V_64 ;
while ( true ) {
struct V_7 V_222 ( V_8 ) ;
V_64 = F_19 ( V_2 , & V_8 ) ;
if ( V_64 )
break;
F_50 ( V_2 , & V_8 ) ;
}
while ( V_221 < V_220 ) {
V_64 = F_61 ( V_2 ) ;
if ( V_64 )
break;
V_221 ++ ;
}
if ( V_221 < V_220 )
F_66 ( V_219 , V_221 ) ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( F_67 ( V_2 -> V_19 ) && F_59 ( V_2 ) )
F_68 ( V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_224 ) ;
return V_221 ;
}
static T_4 F_69 ( int V_225 , void * V_226 )
{
struct V_1 * V_2 = V_226 ;
T_1 V_227 ;
V_227 = F_5 ( & V_2 -> V_223 -> V_228 ) & ( 1 << V_2 -> V_197 ) ;
if ( V_227 == ( 1 << V_2 -> V_197 ) )
return V_229 ;
F_5 ( & V_2 -> V_5 -> V_230 ) ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_228 ) ;
F_70 ( & V_2 -> V_219 ) ;
return V_231 ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned long V_232 ;
T_1 V_233 , V_234 ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_228 ) ;
V_2 -> V_45 = V_235 ;
F_1 ( V_2 , V_14 ) ;
V_233 = F_5 ( V_2 -> V_15 + V_236 ) ;
F_3 ( 0x00 , & V_2 -> V_5 -> V_237 ) ;
V_232 = V_238 ;
do {
F_1 ( V_2 , V_14 ) ;
V_234 = F_5 ( V_2 -> V_15 + V_236 ) ;
if ( V_234 == ( V_233 ^ 0xff ) )
return 0 ;
F_72 ( 10 ) ;
} while ( F_73 ( V_238 , V_232 + V_239 / 2 ) );
F_9 ( V_2 -> V_19 , L_20 ) ;
return - V_240 ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_71 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_64 ;
V_64 = F_71 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_21 ) ;
return V_64 ;
}
F_7 ( V_2 -> V_241 , V_2 -> V_15 + V_242 , sizeof( V_2 -> V_241 ) - 1 ) ;
if ( strncmp ( V_2 -> V_241 , L_22 , 10 ) ) {
F_9 ( V_2 -> V_19 , L_23 , V_2 -> V_241 ) ;
return - V_147 ;
}
if ( strstr ( V_2 -> V_241 , L_24 ) )
V_2 -> V_92 = V_97 ;
else
V_2 -> V_92 = V_93 ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_224 ) ;
V_64 = F_20 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_25 ) ;
return V_64 ;
}
F_11 ( V_2 ) ;
V_64 = F_23 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_26 ) ;
return V_64 ;
}
V_64 = F_29 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_27 ) ;
return V_64 ;
}
V_64 = F_31 ( V_2 , 1 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_28 ) ;
return V_64 ;
}
F_15 ( V_2 ) ;
V_64 = F_25 ( V_2 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_29 ) ;
return V_64 ;
}
V_64 = F_27 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_30 ) ;
return V_64 ;
}
return 0 ;
}
static int F_76 ( struct V_128 * V_19 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
int V_64 ;
V_64 = F_78 ( V_19 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_31 ) ;
return V_64 ;
}
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_32 ) ;
F_79 ( V_19 ) ;
return V_64 ;
}
V_2 -> V_80 . V_140 = V_165 ;
F_80 ( V_19 ) ;
return 0 ;
}
static int F_81 ( struct V_128 * V_19 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
int V_64 ;
F_82 ( V_19 ) ;
V_2 -> V_80 . V_140 = V_243 ;
V_64 = F_28 ( V_2 , false ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_19 , L_33 ) ;
return V_64 ;
}
F_83 ( & V_2 -> V_151 ) ;
F_79 ( V_19 ) ;
return 0 ;
}
static int F_84 ( struct V_132 * V_133 , struct V_128 * V_19 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
struct V_112 * V_113 = (struct V_112 * ) V_133 -> V_72 ;
struct V_52 V_33 ;
void T_2 * V_62 ;
unsigned long V_34 ;
if ( F_85 ( V_19 , V_133 ) )
return V_244 ;
F_12 ( & V_2 -> V_37 , V_34 ) ;
if ( ! F_59 ( V_2 ) ) {
F_9 ( V_2 -> V_19 , L_34 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_245 ;
}
F_1 ( V_2 , V_2 -> V_59 + ( V_2 -> V_60 / 16 ) ) ;
V_62 = V_2 -> V_15 + ( ( V_2 -> V_60 % 16 ) * sizeof( V_33 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_7 ( & V_33 , V_62 , 1 ) ;
F_34 ( V_2 , V_113 , & V_33 ) ;
F_51 ( V_2 , V_133 ) ;
V_33 . V_42 |= V_246 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
F_3 ( 0x01 , & V_2 -> V_5 -> V_230 ) ;
V_33 . V_42 ^= V_49 ;
F_10 ( V_62 , & V_33 , sizeof( V_33 ) ) ;
V_2 -> V_60 = ( V_33 . V_42 & V_46 ) ? 0
: ( V_2 -> V_60 + 1 ) ;
if ( ! F_59 ( V_2 ) )
F_82 ( V_19 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
return V_244 ;
}
static int F_86 ( struct V_128 * V_19 , enum V_247 V_248 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
int V_64 ;
if ( V_248 != V_249 )
return - V_103 ;
V_64 = F_28 ( V_2 , true ) ;
if ( V_64 ) {
F_9 ( V_19 , L_32 ) ;
return V_64 ;
}
V_2 -> V_80 . V_140 = V_165 ;
if ( F_67 ( V_19 ) )
F_68 ( V_19 ) ;
return 0 ;
}
static int F_87 ( const struct V_128 * V_19 ,
struct V_250 * V_186 )
{
struct V_1 * V_2 = F_77 ( V_19 ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_184 ) ;
if ( V_64 )
return V_64 ;
if ( ! F_88 ( & V_2 -> V_187 , V_239 ) ) {
F_89 ( V_2 -> V_19 , L_35 , V_63 ) ;
return - V_240 ;
}
V_186 -> V_144 = V_2 -> V_186 . V_144 ;
V_186 -> V_145 = V_2 -> V_186 . V_145 ;
return 0 ;
}
static T_5 F_90 ( struct V_251 * V_129 ,
struct V_252 * V_253 ,
char * V_254 )
{
struct V_1 * V_2 = F_77 ( F_91 ( V_129 ) ) ;
int V_64 ;
V_64 = F_30 ( V_2 , V_188 ) ;
if ( V_64 )
return V_64 ;
if ( ! F_88 ( & V_2 -> V_190 , V_239 ) ) {
F_89 ( V_2 -> V_19 , L_35 , V_63 ) ;
return - V_240 ;
}
return snprintf ( V_254 , V_255 , L_36 , V_2 -> V_189 ) ;
}
static T_5 F_92 ( struct V_251 * V_129 ,
struct V_252 * V_253 ,
const char * V_254 , T_6 V_256 )
{
struct V_1 * V_2 = F_77 ( F_91 ( V_129 ) ) ;
unsigned long V_257 ;
int V_64 ;
if ( F_93 ( V_254 , 0 , & V_257 ) )
return - V_148 ;
V_64 = F_29 ( V_2 , V_257 ) ;
if ( V_64 )
return V_64 ;
return V_256 ;
}
static T_5 F_94 ( struct V_251 * V_129 ,
struct V_252 * V_253 ,
char * V_254 )
{
struct V_1 * V_2 = F_77 ( F_91 ( V_129 ) ) ;
return F_95 ( V_254 , V_255 , L_37 , V_2 -> V_241 ) ;
}
static int F_96 ( struct V_258 * V_259 )
{
struct V_260 * V_261 ;
struct V_128 * V_19 ;
struct V_1 * V_2 ;
struct V_262 * V_84 ;
struct V_251 * V_129 ;
int V_64 ;
V_261 = F_97 ( & V_259 -> V_129 ) ;
if ( ! V_261 )
return - V_263 ;
F_98 ( & V_259 -> V_129 , L_38 , V_261 -> V_264 ) ;
V_129 = & V_259 -> V_129 ;
V_19 = F_99 ( sizeof( * V_2 ) , 0 ) ;
if ( ! V_19 ) {
F_100 ( V_129 , L_39 ) ;
V_64 = - V_20 ;
goto V_265;
}
F_101 ( V_259 , V_19 ) ;
V_2 = F_77 ( V_19 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_197 = V_261 -> V_264 ;
F_102 ( V_19 , & V_2 -> V_219 , F_64 , V_57 ) ;
F_103 ( & V_2 -> V_151 ) ;
F_104 ( & V_2 -> V_37 ) ;
F_105 ( & V_2 -> V_190 ) ;
F_105 ( & V_2 -> V_187 ) ;
V_19 -> V_266 [ 0 ] = & V_267 ;
V_2 -> V_45 = V_235 ;
V_19 -> V_268 = & V_269 ;
V_19 -> V_34 |= V_270 ;
F_106 ( V_19 , & V_259 -> V_129 ) ;
V_2 -> V_80 . clock . V_271 = V_272 ;
V_2 -> V_80 . V_273 = & V_274 ;
V_2 -> V_80 . V_275 = F_86 ;
V_2 -> V_80 . V_276 = F_87 ;
V_2 -> V_80 . V_277 = V_91
| V_153
| V_126 ;
V_2 -> V_225 = F_107 ( V_259 , 0 ) ;
if ( V_2 -> V_225 < 0 ) {
F_100 ( V_129 , L_40 ) ;
V_64 = - V_147 ;
goto V_278;
}
V_19 -> V_225 = V_2 -> V_225 ;
V_84 = F_108 ( V_259 , V_279 , 0 ) ;
if ( ! V_84 ) {
F_100 ( V_129 , L_41 ) ;
V_64 = - V_147 ;
goto V_278;
}
V_2 -> V_15 = F_109 ( V_84 -> V_232 , F_110 ( V_84 ) ) ;
if ( ! V_2 -> V_15 ) {
F_100 ( V_129 , L_42 ) ;
V_64 = - V_20 ;
goto V_278;
}
V_2 -> V_5 = V_2 -> V_15 + V_58 ;
V_84 = F_108 ( V_259 , V_279 , 1 ) ;
if ( ! V_84 ) {
F_100 ( V_129 , L_43 ) ;
V_64 = - V_147 ;
goto V_280;
}
V_2 -> V_223 = F_109 ( V_84 -> V_232 , F_110 ( V_84 ) ) ;
if ( ! V_2 -> V_223 ) {
F_100 ( V_129 , L_44 ) ;
V_64 = - V_20 ;
goto V_280;
}
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_228 ) ;
V_64 = F_111 ( V_2 -> V_225 , F_69 , V_281 , V_282 , V_2 ) ;
if ( V_64 ) {
F_100 ( V_129 , L_45 ) ;
goto V_283;
}
F_112 ( & V_2 -> V_219 ) ;
V_64 = F_75 ( V_2 ) ;
if ( V_64 ) {
F_100 ( V_129 , L_46 , V_63 ) ;
goto V_284;
}
V_64 = F_113 ( V_19 ) ;
if ( V_64 ) {
F_100 ( V_129 , L_47 , V_63 ) ;
goto V_284;
}
F_89 ( V_2 -> V_19 , L_48 , V_261 -> V_264 ) ;
return 0 ;
V_284:
F_114 ( & V_2 -> V_219 ) ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_228 ) ;
F_115 ( V_2 -> V_225 , V_2 ) ;
V_283:
F_116 ( V_2 -> V_223 ) ;
V_280:
F_116 ( V_2 -> V_15 ) ;
V_278:
F_117 ( V_19 ) ;
V_265:
return V_64 ;
}
static int F_118 ( struct V_258 * V_259 )
{
struct V_128 * V_19 = F_119 ( V_259 ) ;
struct V_1 * V_2 = F_77 ( V_19 ) ;
F_120 ( V_19 ) ;
F_114 ( & V_2 -> V_219 ) ;
F_3 ( 1 << V_2 -> V_197 , & V_2 -> V_223 -> V_228 ) ;
F_115 ( V_2 -> V_225 , V_2 ) ;
F_74 ( V_2 ) ;
F_116 ( V_2 -> V_223 ) ;
F_116 ( V_2 -> V_15 ) ;
F_117 ( V_19 ) ;
return 0 ;
}
