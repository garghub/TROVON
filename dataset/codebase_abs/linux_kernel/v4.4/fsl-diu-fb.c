static enum V_1 F_1 ( const char * V_2 )
{
enum V_1 V_3 = V_4 ;
unsigned long V_5 ;
if ( V_2 ) {
if ( ! F_2 ( V_2 , 10 , & V_5 ) && ( V_5 <= 2 ) )
V_3 = (enum V_1 ) V_5 ;
else if ( strncmp ( V_2 , L_1 , 4 ) == 0 )
V_3 = V_6 ;
else if ( strncmp ( V_2 , L_2 , 5 ) == 0 )
V_3 = V_7 ;
}
if ( V_8 . V_9 )
V_3 = V_8 . V_9 ( V_3 ) ;
return V_3 ;
}
void F_3 ( T_1 * V_10 , T_1 V_5 )
{
do {
F_4 ( V_10 , V_5 ) ;
} while ( F_5 ( V_10 ) != V_5 );
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 , * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
switch ( V_16 -> V_26 ) {
case V_27 :
F_3 ( & V_24 -> V_28 [ 0 ] , V_19 -> V_29 ) ;
break;
case V_30 :
V_15 = & V_21 -> V_31 [ 2 ] ;
if ( V_24 -> V_28 [ 1 ] != V_19 -> V_29 ) {
if ( V_15 -> V_32 > 0 )
V_19 -> V_33 =
F_7 ( V_15 -> V_19 -> V_29 ) ;
else
V_19 -> V_33 = 0 ;
F_3 ( & V_24 -> V_28 [ 1 ] , V_19 -> V_29 ) ;
}
break;
case V_34 :
V_15 = & V_21 -> V_31 [ 4 ] ;
if ( V_24 -> V_28 [ 2 ] != V_19 -> V_29 ) {
if ( V_15 -> V_32 > 0 )
V_19 -> V_33 =
F_7 ( V_15 -> V_19 -> V_29 ) ;
else
V_19 -> V_33 = 0 ;
F_3 ( & V_24 -> V_28 [ 2 ] , V_19 -> V_29 ) ;
}
break;
case V_35 :
V_14 = & V_21 -> V_31 [ 1 ] ;
V_19 -> V_33 = 0 ;
if ( V_24 -> V_28 [ 1 ] == V_21 -> V_36 . V_29 )
F_3 ( & V_24 -> V_28 [ 1 ] , V_19 -> V_29 ) ;
else
V_14 -> V_19 -> V_33 = F_7 ( V_19 -> V_29 ) ;
break;
case V_37 :
V_14 = & V_21 -> V_31 [ 3 ] ;
V_19 -> V_33 = 0 ;
if ( V_24 -> V_28 [ 2 ] == V_21 -> V_36 . V_29 )
F_3 ( & V_24 -> V_28 [ 2 ] , V_19 -> V_29 ) ;
else
V_14 -> V_19 -> V_33 = F_7 ( V_19 -> V_29 ) ;
break;
}
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 , * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
switch ( V_16 -> V_26 ) {
case V_27 :
F_3 ( & V_24 -> V_28 [ 0 ] , 0 ) ;
break;
case V_30 :
V_15 = & V_21 -> V_31 [ 2 ] ;
if ( V_15 -> V_32 > 0 )
F_3 ( & V_24 -> V_28 [ 1 ] , V_15 -> V_19 -> V_29 ) ;
else
F_3 ( & V_24 -> V_28 [ 1 ] , V_21 -> V_36 . V_29 ) ;
break;
case V_34 :
V_15 = & V_21 -> V_31 [ 4 ] ;
if ( V_15 -> V_32 > 0 )
F_3 ( & V_24 -> V_28 [ 2 ] , V_15 -> V_19 -> V_29 ) ;
else
F_3 ( & V_24 -> V_28 [ 2 ] , V_21 -> V_36 . V_29 ) ;
break;
case V_35 :
V_14 = & V_21 -> V_31 [ 1 ] ;
if ( V_24 -> V_28 [ 1 ] != V_19 -> V_29 ) {
if ( V_14 -> V_32 > 0 )
V_14 -> V_19 -> V_33 = 0 ;
} else
F_3 ( & V_24 -> V_28 [ 1 ] , V_21 -> V_36 . V_29 ) ;
break;
case V_37 :
V_14 = & V_21 -> V_31 [ 3 ] ;
if ( V_24 -> V_28 [ 2 ] != V_19 -> V_29 ) {
if ( V_14 -> V_32 > 0 )
V_14 -> V_19 -> V_33 = 0 ;
} else
F_3 ( & V_24 -> V_28 [ 2 ] , V_21 -> V_36 . V_29 ) ;
break;
}
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
F_4 ( & V_24 -> V_38 , V_39 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
F_4 ( & V_24 -> V_38 , 0 ) ;
}
static void F_11 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
struct V_13 * V_42 , * V_43 , * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
int V_44 , V_45 ;
enum V_46 V_26 = V_16 -> V_26 ;
int V_47 , V_48 ;
T_3 V_49 , V_50 , V_51 ;
V_49 = V_21 -> V_52 [ 0 ] . V_41 . V_53 ;
V_50 = V_21 -> V_52 [ 0 ] . V_41 . V_54 ;
if ( V_16 -> V_55 < 0 )
V_16 -> V_55 = 0 ;
if ( V_16 -> V_56 < 0 )
V_16 -> V_56 = 0 ;
switch ( V_26 ) {
case V_27 :
if ( V_16 -> V_55 != 0 )
V_16 -> V_55 = 0 ;
if ( V_16 -> V_56 != 0 )
V_16 -> V_56 = 0 ;
break;
case V_30 :
case V_34 :
V_42 = V_21 -> V_52 [ V_26 + 1 ] . V_17 ;
V_47 = V_42 -> V_32 > 0 ? 1 : 0 ;
if ( V_41 -> V_53 > V_49 )
V_41 -> V_53 = V_49 ;
if ( ( V_16 -> V_55 + V_41 -> V_53 ) > V_49 )
V_16 -> V_55 = V_49 - V_41 -> V_53 ;
if ( V_47 )
V_44 = V_42 -> V_56 ;
else
V_44 = V_50 ;
if ( V_41 -> V_54 > V_44 )
V_41 -> V_54 = V_44 ;
if ( ( V_16 -> V_56 + V_41 -> V_54 ) > V_44 )
V_16 -> V_56 = V_44 - V_41 -> V_54 ;
break;
case V_35 :
case V_37 :
V_43 = V_21 -> V_52 [ V_26 - 1 ] . V_17 ;
V_51 = V_21 -> V_52 [ V_26 - 1 ] . V_41 . V_54 ;
V_45 = V_43 -> V_56 + V_51 ;
V_48 = V_43 -> V_32 > 0 ? 1 : 0 ;
if ( V_41 -> V_53 > V_49 )
V_41 -> V_53 = V_49 ;
if ( ( V_16 -> V_55 + V_41 -> V_53 ) > V_49 )
V_16 -> V_55 = V_49 - V_41 -> V_53 ;
if ( V_16 -> V_56 < 0 )
V_16 -> V_56 = 0 ;
if ( V_48 ) {
if ( V_16 -> V_56 < V_45 )
V_16 -> V_56 = V_45 ;
V_44 = V_50
- V_45 ;
} else
V_44 = V_50 ;
if ( V_41 -> V_54 > V_44 )
V_41 -> V_54 = V_44 ;
if ( ( V_16 -> V_56 + V_41 -> V_54 ) > V_50 )
V_16 -> V_56 = V_50 - V_41 -> V_54 ;
break;
}
}
static int F_12 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
if ( V_41 -> V_57 < V_41 -> V_53 )
V_41 -> V_57 = V_41 -> V_53 ;
if ( V_41 -> V_58 < V_41 -> V_54 )
V_41 -> V_58 = V_41 -> V_54 ;
if ( V_41 -> V_59 < 0 )
V_41 -> V_59 = 0 ;
if ( V_41 -> V_60 < 0 )
V_41 -> V_60 = 0 ;
if ( V_41 -> V_59 + V_12 -> V_41 . V_53 > V_12 -> V_41 . V_57 )
V_41 -> V_59 = V_12 -> V_41 . V_57 - V_12 -> V_41 . V_53 ;
if ( V_41 -> V_60 + V_12 -> V_41 . V_54 > V_12 -> V_41 . V_58 )
V_41 -> V_60 = V_12 -> V_41 . V_58 - V_12 -> V_41 . V_54 ;
if ( ( V_41 -> V_61 != 32 ) && ( V_41 -> V_61 != 24 ) &&
( V_41 -> V_61 != 16 ) )
V_41 -> V_61 = V_62 ;
switch ( V_41 -> V_61 ) {
case 16 :
V_41 -> V_63 . V_64 = 5 ;
V_41 -> V_63 . V_65 = 11 ;
V_41 -> V_63 . V_66 = 0 ;
V_41 -> V_67 . V_64 = 6 ;
V_41 -> V_67 . V_65 = 5 ;
V_41 -> V_67 . V_66 = 0 ;
V_41 -> V_68 . V_64 = 5 ;
V_41 -> V_68 . V_65 = 0 ;
V_41 -> V_68 . V_66 = 0 ;
V_41 -> V_69 . V_64 = 0 ;
V_41 -> V_69 . V_65 = 0 ;
V_41 -> V_69 . V_66 = 0 ;
break;
case 24 :
V_41 -> V_63 . V_64 = 8 ;
V_41 -> V_63 . V_65 = 0 ;
V_41 -> V_63 . V_66 = 0 ;
V_41 -> V_67 . V_64 = 8 ;
V_41 -> V_67 . V_65 = 8 ;
V_41 -> V_67 . V_66 = 0 ;
V_41 -> V_68 . V_64 = 8 ;
V_41 -> V_68 . V_65 = 16 ;
V_41 -> V_68 . V_66 = 0 ;
V_41 -> V_69 . V_64 = 0 ;
V_41 -> V_69 . V_65 = 0 ;
V_41 -> V_69 . V_66 = 0 ;
break;
case 32 :
V_41 -> V_63 . V_64 = 8 ;
V_41 -> V_63 . V_65 = 16 ;
V_41 -> V_63 . V_66 = 0 ;
V_41 -> V_67 . V_64 = 8 ;
V_41 -> V_67 . V_65 = 8 ;
V_41 -> V_67 . V_66 = 0 ;
V_41 -> V_68 . V_64 = 8 ;
V_41 -> V_68 . V_65 = 0 ;
V_41 -> V_68 . V_66 = 0 ;
V_41 -> V_69 . V_64 = 8 ;
V_41 -> V_69 . V_65 = 24 ;
V_41 -> V_69 . V_66 = 0 ;
break;
}
V_41 -> V_70 = - 1 ;
V_41 -> V_71 = - 1 ;
V_41 -> V_72 = 0 ;
V_41 -> V_73 |= V_41 -> V_74 ;
V_41 -> V_74 |= V_41 -> V_73 ;
F_11 ( V_41 , V_12 ) ;
return 0 ;
}
static void F_13 ( struct V_11 * V_12 )
{
struct V_75 * V_76 = & V_12 -> V_76 ;
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
strncpy ( V_76 -> V_77 , V_16 -> V_77 , sizeof( V_76 -> V_77 ) ) ;
V_76 -> V_78 = V_41 -> V_57 * V_41 -> V_61 / 8 ;
V_76 -> type = V_79 ;
V_76 -> V_80 = V_81 ;
V_76 -> V_82 = V_83 ;
V_76 -> V_84 = 1 ;
V_76 -> V_85 = 1 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 ;
int V_86 , V_87 ;
T_4 * V_88 ;
T_1 V_89 ;
V_24 = V_21 -> V_25 ;
if ( V_8 . V_90 )
V_8 . V_90 ( V_21 -> V_91 ) ;
V_88 = V_21 -> gamma ;
for ( V_86 = 0 ; V_86 <= 2 ; V_86 ++ )
for ( V_87 = 0 ; V_87 <= 255 ; V_87 ++ )
* V_88 ++ = V_87 ;
if ( V_8 . V_92 )
V_8 . V_92 ( V_21 -> V_91 , V_21 -> gamma ) ;
F_10 ( V_12 ) ;
F_4 ( & V_24 -> gamma , F_15 ( V_21 , gamma ) ) ;
F_4 ( & V_24 -> V_93 , 0x007F7F7F ) ;
F_4 ( & V_24 -> V_94 , ( V_41 -> V_54 << 16 ) | V_41 -> V_53 ) ;
V_89 = V_41 -> V_95 << 22 |
V_41 -> V_96 << 11 |
V_41 -> V_97 ;
F_4 ( & V_24 -> V_98 , V_89 ) ;
V_89 = V_41 -> V_99 << 22 |
V_41 -> V_100 << 11 |
V_41 -> V_101 ;
F_4 ( & V_24 -> V_102 , V_89 ) ;
V_8 . V_103 ( V_41 -> V_104 ) ;
#ifndef F_16
F_4 ( & V_24 -> V_105 , 0x01F5F666 ) ;
#endif
F_9 ( V_12 ) ;
}
static int F_17 ( struct V_11 * V_12 )
{
T_1 V_106 = V_12 -> V_76 . V_78 * V_12 -> V_41 . V_58 ;
void * V_107 ;
V_107 = F_18 ( V_106 , V_108 | V_109 ) ;
if ( ! V_107 ) {
F_19 ( V_12 -> V_110 , L_3 ) ;
return - V_111 ;
}
F_20 ( & V_12 -> V_112 ) ;
V_12 -> V_113 = V_107 ;
V_12 -> V_76 . V_114 = F_21 ( V_12 -> V_113 ) ;
V_12 -> V_76 . V_106 = V_106 ;
F_22 ( & V_12 -> V_112 ) ;
V_12 -> V_115 = V_12 -> V_76 . V_106 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
void * V_107 = V_12 -> V_113 ;
T_5 V_116 = V_12 -> V_76 . V_106 ;
F_20 ( & V_12 -> V_112 ) ;
V_12 -> V_113 = NULL ;
V_12 -> V_76 . V_114 = 0 ;
V_12 -> V_76 . V_106 = 0 ;
F_22 ( & V_12 -> V_112 ) ;
if ( V_107 )
F_24 ( V_107 , V_116 ) ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
V_19 -> V_117 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_118 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
return 0 ;
}
static T_1 F_26 ( unsigned int V_61 )
{
#define F_27 0x10000000
#define F_28 0x0E000000
#define F_29 25
#define F_30 0x01800000
#define F_31 23
#define F_32 0x00600000
#define F_33 21
#define F_34 0x00180000
#define F_35 19
#define F_36 0x00040000
#define F_37 0x00030000
#define F_38 16
#define F_39 0x0000F000
#define F_40 12
#define F_41 0x00000F00
#define F_42 8
#define F_43 0x000000F0
#define F_44 4
#define F_45 0x0000000F
#define F_46 0
#define F_47 ( T_6 , V_63 , V_67 , V_68 , T_7 , T_8 , T_9 , T_10 , T_11 ) \
cpu_to_le32(PF_BYTE_F | (alpha << PF_ALPHA_C_SHIFT) | \
(blue << PF_BLUE_C_SHIFT) | (green << PF_GREEN_C_SHIFT) | \
(red << PF_RED_C_SHIFT) | (c3 << PF_COMP_3_SHIFT) | \
(c2 << PF_COMP_2_SHIFT) | (c1 << PF_COMP_1_SHIFT) | \
(c0 << PF_COMP_0_SHIFT) | (size << PF_PIXEL_S_SHIFT))
switch ( V_61 ) {
case 32 :
return F_47 ( 3 , 2 , 1 , 0 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_47 ( 4 , 0 , 1 , 2 , 2 , 8 , 8 , 8 , 0 ) ;
case 16 :
return F_47 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_48 ( L_4 , V_61 ) ;
return 0 ;
}
}
static void F_49 ( struct V_11 * V_12 ,
const void * V_119 , T_12 V_120 , T_12 V_121 ,
unsigned int V_71 , unsigned int V_70 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
T_13 * V_122 = V_21 -> V_122 ;
T_13 V_123 = F_50 ( V_121 ) ;
T_13 V_124 = F_50 ( V_120 ) ;
unsigned int V_125 , V_126 ;
for ( V_125 = 0 ; V_125 < V_70 ; V_125 ++ ) {
T_14 V_127 = 1 << 31 ;
T_14 line = F_51 ( V_119 ) ;
for ( V_126 = 0 ; V_126 < V_71 ; V_126 ++ ) {
V_122 [ V_126 ] = ( line & V_127 ) ? V_123 : V_124 ;
V_127 >>= 1 ;
}
V_122 += V_128 ;
V_119 += F_52 ( V_71 , 8 ) ;
}
}
static int F_53 ( struct V_11 * V_12 , struct V_129 * V_122 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
if ( V_122 -> V_119 . V_71 > V_128 || V_122 -> V_119 . V_70 > V_128 )
return - V_130 ;
if ( V_122 -> V_131 & V_132 ) {
memset ( V_21 -> V_122 , 0 , sizeof( V_21 -> V_122 ) ) ;
}
if ( V_122 -> V_131 & V_133 ) {
T_14 V_134 , V_135 ;
V_135 = ( V_122 -> V_119 . V_136 - V_12 -> V_41 . V_60 ) & 0x7ff ;
V_134 = ( V_122 -> V_119 . V_137 - V_12 -> V_41 . V_59 ) & 0x7ff ;
F_4 ( & V_24 -> V_138 , V_135 << 16 | V_134 ) ;
}
if ( V_122 -> V_131 & ( V_139 | V_140 | V_141 ) ) {
unsigned int V_142 =
F_52 ( V_122 -> V_119 . V_71 , 8 ) * V_122 -> V_119 . V_70 ;
unsigned int V_143 =
F_52 ( V_142 , sizeof( T_14 ) ) ;
unsigned int V_144 = V_122 -> V_119 . V_145 ;
unsigned int V_146 = V_122 -> V_119 . V_147 ;
T_15 V_148 [ V_142 ] ;
T_14 * V_119 , * V_149 , * V_127 ;
T_12 V_121 , V_120 ;
unsigned int V_86 ;
if ( V_12 -> V_150 != V_151 )
return 0 ;
V_142 = F_52 ( V_122 -> V_119 . V_71 , 8 ) *
V_122 -> V_119 . V_70 ;
V_120 = ( ( V_12 -> V_152 . V_63 [ V_144 ] & 0xf8 ) << 7 ) |
( ( V_12 -> V_152 . V_67 [ V_144 ] & 0xf8 ) << 2 ) |
( ( V_12 -> V_152 . V_68 [ V_144 ] & 0xf8 ) >> 3 ) |
1 << 15 ;
V_121 = ( ( V_12 -> V_152 . V_63 [ V_146 ] & 0xf8 ) << 7 ) |
( ( V_12 -> V_152 . V_67 [ V_146 ] & 0xf8 ) << 2 ) |
( ( V_12 -> V_152 . V_68 [ V_146 ] & 0xf8 ) >> 3 ) |
1 << 15 ;
V_119 = ( T_14 * ) V_148 ;
V_149 = ( T_14 * ) V_122 -> V_119 . V_21 ;
V_127 = ( T_14 * ) V_122 -> V_127 ;
if ( V_122 -> V_153 == V_154 )
for ( V_86 = 0 ; V_86 < V_143 ; V_86 ++ )
V_119 [ V_86 ] = V_149 [ V_86 ] ^ V_127 [ V_86 ] ;
else
for ( V_86 = 0 ; V_86 < V_143 ; V_86 ++ )
V_119 [ V_86 ] = V_149 [ V_86 ] & V_127 [ V_86 ] ;
F_49 ( V_12 , V_119 , V_120 , V_121 ,
V_122 -> V_119 . V_71 , V_122 -> V_119 . V_70 ) ;
}
if ( V_122 -> V_155 )
F_4 ( & V_24 -> V_122 , F_15 ( V_21 , V_122 ) ) ;
else
F_4 ( & V_24 -> V_122 , F_15 ( V_21 , V_156 ) ) ;
return 0 ;
}
static int F_54 ( struct V_11 * V_12 )
{
unsigned long V_157 ;
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_23 T_2 * V_24 ;
V_24 = V_21 -> V_25 ;
F_13 ( V_12 ) ;
V_157 = V_12 -> V_41 . V_58 * V_12 -> V_76 . V_78 ;
if ( V_157 != V_12 -> V_76 . V_106 ) {
if ( V_12 -> V_76 . V_114 )
F_23 ( V_12 ) ;
if ( F_17 ( V_12 ) ) {
F_19 ( V_12 -> V_110 , L_5 ) ;
return - V_111 ;
}
}
if ( V_8 . V_158 )
V_19 -> V_159 = V_8 . V_158 ( V_21 -> V_91 ,
V_41 -> V_61 ) ;
else
V_19 -> V_159 = F_26 ( V_41 -> V_61 ) ;
V_19 -> V_160 = F_7 ( V_12 -> V_76 . V_114 ) ;
V_19 -> V_161 = F_7 ( ( V_41 -> V_58 << 12 ) |
V_41 -> V_57 ) | V_16 -> V_162 ;
V_19 -> V_163 = F_7 ( ( V_41 -> V_54 << 16 ) | V_41 -> V_53 ) ;
V_19 -> V_117 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_118 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
V_19 -> V_164 = 0 ;
V_19 -> V_165 = 0 ;
V_19 -> V_166 = 0 ;
V_19 -> V_167 = 255 ;
V_19 -> V_168 = 255 ;
V_19 -> V_169 = 255 ;
if ( V_16 -> V_26 == V_27 )
F_14 ( V_12 ) ;
return 0 ;
}
static inline T_3 F_55 ( T_3 V_5 , T_3 V_71 )
{
return ( ( V_5 << V_71 ) + 0x7FFF - V_5 ) >> 16 ;
}
static int F_56 ( unsigned int V_170 , unsigned int V_63 ,
unsigned int V_67 , unsigned int V_68 ,
unsigned int V_69 , struct V_11 * V_12 )
{
int V_171 = 1 ;
if ( V_12 -> V_41 . V_72 )
V_63 = V_67 = V_68 = ( 19595 * V_63 + 38470 * V_67 +
7471 * V_68 ) >> 16 ;
switch ( V_12 -> V_76 . V_82 ) {
case V_83 :
if ( V_170 < 16 ) {
T_1 * V_172 = V_12 -> V_173 ;
T_1 V_174 ;
V_63 = F_55 ( V_63 , V_12 -> V_41 . V_63 . V_64 ) ;
V_67 = F_55 ( V_67 , V_12 -> V_41 . V_67 . V_64 ) ;
V_68 = F_55 ( V_68 , V_12 -> V_41 . V_68 . V_64 ) ;
V_69 = F_55 ( V_69 , V_12 -> V_41 . V_69 . V_64 ) ;
V_174 = ( V_63 << V_12 -> V_41 . V_63 . V_65 ) |
( V_67 << V_12 -> V_41 . V_67 . V_65 ) |
( V_68 << V_12 -> V_41 . V_68 . V_65 ) |
( V_69 << V_12 -> V_41 . V_69 . V_65 ) ;
V_172 [ V_170 ] = V_174 ;
V_171 = 0 ;
}
break;
}
return V_171 ;
}
static int F_57 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
if ( ( V_12 -> V_41 . V_59 == V_41 -> V_59 ) &&
( V_12 -> V_41 . V_60 == V_41 -> V_60 ) )
return 0 ;
if ( V_41 -> V_59 < 0 || V_41 -> V_60 < 0
|| V_41 -> V_59 + V_12 -> V_41 . V_53 > V_12 -> V_41 . V_57
|| V_41 -> V_60 + V_12 -> V_41 . V_54 > V_12 -> V_41 . V_58 )
return - V_130 ;
V_12 -> V_41 . V_59 = V_41 -> V_59 ;
V_12 -> V_41 . V_60 = V_41 -> V_60 ;
if ( V_41 -> V_175 & V_176 )
V_12 -> V_41 . V_175 |= V_176 ;
else
V_12 -> V_41 . V_175 &= ~ V_176 ;
F_25 ( V_12 ) ;
return 0 ;
}
static int F_58 ( struct V_11 * V_12 , unsigned int V_177 ,
unsigned long V_178 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_179 V_180 ;
unsigned char V_181 ;
struct V_182 V_183 ;
T_3 V_159 ;
void T_16 * V_184 = ( void T_16 * ) V_178 ;
if ( ! V_178 )
return - V_130 ;
F_59 ( V_12 -> V_110 , L_6 , V_177 ,
F_60 ( V_177 ) & V_185 ? L_7 : L_8 ,
F_60 ( V_177 ) & V_186 ? L_9 : L_8 ,
F_61 ( V_177 ) , F_62 ( V_177 ) , F_63 ( V_177 ) ) ;
switch ( V_177 ) {
case V_187 :
F_64 ( V_12 -> V_110 ,
L_10 ,
V_187 ) ;
case V_188 :
if ( F_65 ( & V_159 , V_184 , sizeof( V_159 ) ) )
return - V_189 ;
V_19 -> V_159 = V_159 ;
break;
case V_190 :
F_64 ( V_12 -> V_110 ,
L_11 ,
V_190 ) ;
case V_191 :
V_159 = V_19 -> V_159 ;
if ( F_66 ( V_184 , & V_159 , sizeof( V_159 ) ) )
return - V_189 ;
break;
case V_192 :
if ( F_65 ( & V_183 , V_184 , sizeof( V_183 ) ) )
return - V_189 ;
V_16 -> V_55 = V_183 . V_55 ;
V_16 -> V_56 = V_183 . V_56 ;
F_12 ( & V_12 -> V_41 , V_12 ) ;
F_25 ( V_12 ) ;
break;
case V_193 :
V_183 . V_55 = V_16 -> V_55 ;
V_183 . V_56 = V_16 -> V_56 ;
if ( F_66 ( V_184 , & V_183 , sizeof( V_183 ) ) )
return - V_189 ;
break;
case V_194 :
V_181 = V_16 -> V_162 ;
if ( F_66 ( V_184 , & V_181 , sizeof( V_181 ) ) )
return - V_189 ;
break;
case V_195 :
if ( F_65 ( & V_181 , V_184 , sizeof( V_181 ) ) )
return - V_189 ;
V_19 -> V_161 = ( V_19 -> V_161 & ( ~ 0xff ) ) |
( V_181 & 0xff ) ;
V_16 -> V_162 = V_181 ;
break;
case V_196 :
if ( F_65 ( & V_180 , V_184 , sizeof( V_180 ) ) )
return - V_189 ;
if ( V_180 . V_155 &&
( V_180 . V_197 < V_180 . V_198 ||
V_180 . V_199 < V_180 . V_200 ||
V_180 . V_201 < V_180 . V_202 ) )
return - V_130 ;
if ( ! V_180 . V_155 ) {
V_19 -> V_164 = 0 ;
V_19 -> V_165 = 0 ;
V_19 -> V_166 = 0 ;
V_19 -> V_167 = 255 ;
V_19 -> V_168 = 255 ;
V_19 -> V_169 = 255 ;
} else {
V_19 -> V_164 = V_180 . V_197 ;
V_19 -> V_165 = V_180 . V_199 ;
V_19 -> V_166 = V_180 . V_201 ;
V_19 -> V_167 = V_180 . V_198 ;
V_19 -> V_168 = V_180 . V_200 ;
V_19 -> V_169 = V_180 . V_202 ;
}
break;
#ifdef F_16
case V_203 : {
struct V_20 * V_21 = V_16 -> V_22 ;
if ( F_65 ( V_21 -> gamma , V_184 , sizeof( V_21 -> gamma ) ) )
return - V_189 ;
F_67 ( & V_21 -> V_25 -> gamma , 0 ) ;
break;
}
case V_204 : {
struct V_20 * V_21 = V_16 -> V_22 ;
if ( F_66 ( V_184 , V_21 -> gamma , sizeof( V_21 -> gamma ) ) )
return - V_189 ;
break;
}
#endif
default:
F_19 ( V_12 -> V_110 , L_12 , V_177 ) ;
return - V_205 ;
}
return 0 ;
}
static inline void F_68 ( struct V_20 * V_21 )
{
T_1 V_206 = V_207 ;
if ( F_69 ( V_208 ) )
V_206 |= V_209 ;
F_70 ( & V_21 -> V_25 -> V_206 , V_206 ) ;
}
static int F_71 ( struct V_11 * V_12 , int V_210 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_211 = 0 ;
if ( ( V_16 -> V_26 == V_27 ) && V_8 . V_212 )
V_8 . V_212 () ;
F_72 ( & V_213 ) ;
V_16 -> V_32 ++ ;
if ( V_16 -> V_32 == 1 ) {
F_12 ( & V_12 -> V_41 , V_12 ) ;
V_211 = F_54 ( V_12 ) ;
if ( V_211 < 0 )
V_16 -> V_32 -- ;
else {
F_68 ( V_16 -> V_22 ) ;
F_6 ( V_12 ) ;
}
}
F_73 ( & V_213 ) ;
return V_211 ;
}
static int F_74 ( struct V_11 * V_12 , int V_210 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_211 = 0 ;
F_72 ( & V_213 ) ;
V_16 -> V_32 -- ;
if ( V_16 -> V_32 == 0 ) {
struct V_20 * V_21 = V_16 -> V_22 ;
bool V_214 = true ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ ) {
struct V_13 * V_216 = V_21 -> V_52 [ V_86 ] . V_17 ;
if ( V_216 -> V_32 )
V_214 = false ;
}
if ( V_214 )
F_4 ( & V_21 -> V_25 -> V_206 , 0xffffffff ) ;
F_8 ( V_12 ) ;
}
F_73 ( & V_213 ) ;
return V_211 ;
}
static int F_75 ( struct V_11 * V_12 )
{
int V_217 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
const char * V_218 , * V_219 = L_13 ;
struct V_220 * V_221 = V_222 ;
unsigned int V_223 = F_76 ( V_222 ) ;
int V_224 = 1 ;
V_12 -> V_41 . V_225 = V_226 ;
V_12 -> V_227 = & V_228 ;
V_12 -> V_229 = V_230 | V_231 | V_232 |
V_233 ;
V_12 -> V_173 = V_16 -> V_173 ;
V_217 = F_77 ( & V_12 -> V_152 , 16 , 0 ) ;
if ( V_217 )
return V_217 ;
if ( V_16 -> V_26 == V_27 ) {
if ( V_21 -> V_234 ) {
F_78 ( V_21 -> V_235 , & V_12 -> V_236 ) ;
F_79 ( V_12 -> V_236 . V_237 ,
V_12 -> V_236 . V_238 ,
& V_12 -> V_239 ) ;
V_221 = V_12 -> V_236 . V_237 ;
V_223 = V_12 -> V_236 . V_238 ;
}
V_218 = V_240 ;
} else {
V_218 = V_219 ;
}
V_217 = F_80 ( & V_12 -> V_41 , V_12 , V_218 , V_221 , V_223 , NULL ,
V_62 ) ;
if ( ! V_217 ) {
if ( ( V_16 -> V_26 == V_27 ) && V_21 -> V_234 )
V_224 = 0 ;
else
return - V_130 ;
}
if ( ! V_224 ) {
V_217 = F_80 ( & V_12 -> V_41 , V_12 , V_218 , V_222 ,
F_76 ( V_222 ) , NULL , V_62 ) ;
if ( V_217 )
V_224 = 1 ;
}
if ( ! V_224 && V_12 -> V_236 . V_237 ) {
struct V_241 * V_242 = & V_12 -> V_236 ;
struct V_220 * V_237 = & V_242 -> V_237 [ 0 ] ;
if ( V_242 -> V_243 & V_244 ) {
int V_86 ;
for ( V_86 = 0 ; V_86 < V_242 -> V_238 ; V_86 ++ ) {
if ( V_242 -> V_237 [ V_86 ] . V_245 & V_246 ) {
V_237 = & V_242 -> V_237 [ V_86 ] ;
break;
}
}
}
V_12 -> V_41 . V_61 = V_62 ;
F_81 ( & V_12 -> V_41 , V_237 ) ;
}
if ( F_12 ( & V_12 -> V_41 , V_12 ) ) {
F_19 ( V_12 -> V_110 , L_14 ) ;
F_23 ( V_12 ) ;
F_82 ( & V_12 -> V_152 ) ;
return - V_130 ;
}
if ( F_83 ( V_12 ) < 0 ) {
F_19 ( V_12 -> V_110 , L_15 ) ;
F_23 ( V_12 ) ;
F_82 ( & V_12 -> V_152 ) ;
return - V_130 ;
}
V_16 -> V_247 = 1 ;
F_84 ( V_12 -> V_110 , L_16 , V_16 -> V_77 ) ;
return 0 ;
}
static void F_85 ( struct V_11 * V_12 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
if ( ! V_16 -> V_247 )
return;
F_86 ( V_12 ) ;
F_23 ( V_12 ) ;
if ( & V_12 -> V_152 )
F_82 ( & V_12 -> V_152 ) ;
V_16 -> V_247 = 0 ;
}
static T_17 F_87 ( int V_248 , void * V_249 )
{
struct V_23 T_2 * V_24 = V_249 ;
T_14 V_250 = F_5 ( & V_24 -> V_251 ) ;
if ( V_250 ) {
if ( V_250 & V_207 ) {
F_4 ( & V_24 -> V_38 , 0 ) ;
F_88 ( 1 ) ;
F_4 ( & V_24 -> V_38 , 1 ) ;
}
#if F_89 ( V_208 )
else if ( V_250 & V_209 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_252 ;
V_86 += V_253 )
__asm__ __volatile__ (
"dcbz 0, %[input]"
::[input]"r"(&coherence_data[i]));
}
#endif
return V_254 ;
}
return V_255 ;
}
static int F_90 ( struct V_256 * V_257 , T_18 V_150 )
{
struct V_20 * V_21 ;
V_21 = F_91 ( & V_257 -> V_110 ) ;
F_10 ( V_21 -> V_52 ) ;
return 0 ;
}
static int F_92 ( struct V_256 * V_257 )
{
struct V_20 * V_21 ;
unsigned int V_86 ;
V_21 = F_91 ( & V_257 -> V_110 ) ;
F_68 ( V_21 ) ;
F_14 ( V_21 -> V_52 ) ;
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ ) {
if ( V_21 -> V_31 [ V_86 ] . V_32 )
F_6 ( & V_21 -> V_52 [ V_86 ] ) ;
}
return 0 ;
}
static T_19 F_93 ( struct V_258 * V_258 ,
struct V_259 * V_260 , const char * V_184 , T_5 V_32 )
{
enum V_1 V_261 ;
struct V_20 * V_21 =
F_94 ( V_260 , struct V_20 , V_262 ) ;
V_261 = V_21 -> V_91 ;
V_21 -> V_91 = F_1 ( V_184 ) ;
if ( V_261 != V_21 -> V_91 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ )
F_54 ( & V_21 -> V_52 [ V_86 ] ) ;
}
return V_32 ;
}
static T_19 F_95 ( struct V_258 * V_258 ,
struct V_259 * V_260 , char * V_184 )
{
struct V_20 * V_21 =
F_94 ( V_260 , struct V_20 , V_262 ) ;
switch ( V_21 -> V_91 ) {
case V_4 :
return sprintf ( V_184 , L_17 ) ;
case V_6 :
return sprintf ( V_184 , L_18 ) ;
case V_7 :
return sprintf ( V_184 , L_19 ) ;
}
return 0 ;
}
static int F_96 ( struct V_256 * V_263 )
{
struct V_264 * V_265 = V_263 -> V_110 . V_266 ;
struct V_13 * V_16 ;
struct V_20 * V_21 ;
T_20 V_267 ;
const void * V_268 ;
unsigned int V_86 ;
int V_171 ;
V_21 = F_97 ( & V_263 -> V_110 , sizeof( struct V_20 ) ,
& V_267 , V_108 | V_109 ) ;
if ( ! V_21 )
return - V_111 ;
V_21 -> V_267 = V_267 ;
if ( ( unsigned long ) V_21 & 31 ) {
F_19 ( & V_263 -> V_110 , L_20 ) ;
V_171 = - V_111 ;
goto error;
}
F_98 ( & V_21 -> V_269 ) ;
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ ) {
struct V_11 * V_12 = & V_21 -> V_52 [ V_86 ] ;
V_12 -> V_258 = & V_263 -> V_110 ;
V_12 -> V_17 = & V_21 -> V_31 [ V_86 ] ;
V_21 -> V_19 [ V_86 ] . V_29 = F_15 ( V_21 , V_19 [ V_86 ] ) ;
V_12 -> V_76 . V_114 = 0 ;
V_16 = V_12 -> V_17 ;
memcpy ( V_16 , & V_270 [ V_86 ] , sizeof( struct V_13 ) ) ;
V_16 -> V_22 = V_21 ;
V_16 -> V_19 = & V_21 -> V_19 [ V_86 ] ;
}
V_268 = F_99 ( V_265 , L_21 , & V_171 ) ;
if ( V_268 && V_171 == V_271 ) {
memcpy ( V_21 -> V_235 , V_268 , V_271 ) ;
V_21 -> V_234 = true ;
}
V_21 -> V_25 = F_100 ( V_265 , 0 ) ;
if ( ! V_21 -> V_25 ) {
F_19 ( & V_263 -> V_110 , L_22 ) ;
V_171 = - V_189 ;
goto error;
}
V_21 -> V_248 = F_101 ( V_265 , 0 ) ;
if ( ! V_21 -> V_248 ) {
F_19 ( & V_263 -> V_110 , L_23 ) ;
V_171 = - V_130 ;
goto error;
}
V_21 -> V_91 = V_91 ;
V_21 -> V_36 . V_160 = F_7 ( F_15 ( V_21 , V_272 ) ) ;
V_21 -> V_36 . V_159 = 0x88882317 ;
V_21 -> V_36 . V_161 = F_7 ( ( 4 << 12 ) | 4 ) ;
V_21 -> V_36 . V_163 = F_7 ( ( 4 << 16 ) | 2 ) ;
V_21 -> V_36 . V_117 = 0 ;
V_21 -> V_36 . V_118 = 0 ;
V_21 -> V_36 . V_33 = 0 ;
V_21 -> V_36 . V_29 = F_15 ( V_21 , V_36 ) ;
if ( F_5 ( & V_21 -> V_25 -> V_38 ) == V_273 )
F_4 ( & V_21 -> V_25 -> V_28 [ 0 ] , 0 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 1 ] , V_21 -> V_36 . V_29 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 2 ] , V_21 -> V_36 . V_29 ) ;
F_4 ( & V_21 -> V_25 -> V_206 , 0xffffffff ) ;
F_5 ( & V_21 -> V_25 -> V_251 ) ;
V_171 = F_102 ( V_21 -> V_248 , F_87 , 0 , L_24 ,
V_21 -> V_25 ) ;
if ( V_171 ) {
F_19 ( & V_263 -> V_110 , L_25 ) ;
goto error;
}
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ ) {
V_171 = F_75 ( & V_21 -> V_52 [ V_86 ] ) ;
if ( V_171 ) {
F_19 ( & V_263 -> V_110 , L_26 , V_86 ) ;
F_103 ( V_21 -> V_248 , V_21 -> V_25 ) ;
goto error;
}
}
F_104 ( & V_21 -> V_262 . V_260 ) ;
V_21 -> V_262 . V_260 . V_274 = L_27 ;
V_21 -> V_262 . V_260 . V_275 = V_276 | V_277 ;
V_21 -> V_262 . V_278 = F_95 ;
V_21 -> V_262 . V_279 = F_93 ;
V_171 = F_105 ( & V_263 -> V_110 , & V_21 -> V_262 ) ;
if ( V_171 ) {
F_19 ( & V_263 -> V_110 , L_28 ,
V_21 -> V_262 . V_260 . V_274 ) ;
}
F_106 ( & V_263 -> V_110 , V_21 ) ;
return 0 ;
error:
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ )
F_85 ( & V_21 -> V_52 [ V_86 ] ) ;
F_107 ( V_21 -> V_25 ) ;
return V_171 ;
}
static int F_108 ( struct V_256 * V_263 )
{
struct V_20 * V_21 ;
int V_86 ;
V_21 = F_91 ( & V_263 -> V_110 ) ;
F_10 ( & V_21 -> V_52 [ 0 ] ) ;
F_103 ( V_21 -> V_248 , V_21 -> V_25 ) ;
for ( V_86 = 0 ; V_86 < V_215 ; V_86 ++ )
F_85 ( & V_21 -> V_52 [ V_86 ] ) ;
F_107 ( V_21 -> V_25 ) ;
return 0 ;
}
static int T_21 F_109 ( char * V_280 )
{
char * V_281 ;
unsigned long V_5 ;
if ( ! V_280 || ! * V_280 )
return 0 ;
while ( ( V_281 = F_110 ( & V_280 , L_29 ) ) != NULL ) {
if ( ! * V_281 )
continue;
if ( ! strncmp ( V_281 , L_30 , 8 ) ) {
V_91 = F_1 ( V_281 + 8 ) ;
} else if ( ! strncmp ( V_281 , L_31 , 4 ) ) {
if ( ! F_2 ( V_281 + 4 , 10 , & V_5 ) )
V_62 = V_5 ;
} else
V_240 = V_281 ;
}
return 0 ;
}
static int T_21 F_111 ( void )
{
#ifdef V_208
struct V_264 * V_265 ;
const T_1 * V_268 ;
#endif
int V_171 ;
#ifndef F_112
char * V_282 ;
if ( F_113 ( L_32 , & V_282 ) )
return - V_283 ;
F_109 ( V_282 ) ;
#else
V_91 = F_1 ( V_284 ) ;
#endif
if ( ! V_8 . V_103 )
return - V_283 ;
F_114 ( L_33 ) ;
#ifdef V_208
V_265 = F_115 ( NULL , L_34 ) ;
if ( ! V_265 ) {
F_48 ( L_35 ) ;
return - V_283 ;
}
V_268 = F_99 ( V_265 , L_36 , NULL ) ;
if ( V_268 == NULL ) {
F_48 ( L_37
L_38 ) ;
F_116 ( V_265 ) ;
return - V_283 ;
}
V_252 = F_51 ( V_268 ) * 13 ;
V_252 /= 8 ;
F_117 ( L_39 ,
V_252 ) ;
V_268 = F_99 ( V_265 , L_40 , NULL ) ;
if ( V_268 == NULL ) {
F_48 ( L_41
L_38 ) ;
F_116 ( V_265 ) ;
return - V_283 ;
}
V_253 = F_51 ( V_268 ) ;
F_117 ( L_42 ,
V_253 ) ;
F_116 ( V_265 ) ;
V_285 = F_118 ( V_252 ) ;
if ( ! V_285 ) {
F_48 ( L_43
L_44 , V_252 ) ;
return - V_111 ;
}
#endif
V_171 = F_119 ( & V_286 ) ;
if ( V_171 ) {
F_48 ( L_45 ) ;
#if F_89 ( V_208 )
F_120 ( V_285 ) ;
#endif
}
return V_171 ;
}
static void T_22 F_121 ( void )
{
F_122 ( & V_286 ) ;
#if F_89 ( V_208 )
F_120 ( V_285 ) ;
#endif
}
