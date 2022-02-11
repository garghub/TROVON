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
return V_8 . V_9 ( V_3 ) ;
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
if ( V_24 -> V_28 [ 0 ] != V_19 -> V_29 )
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
if ( V_24 -> V_28 [ 0 ] != V_21 -> V_36 . V_29 )
F_3 ( & V_24 -> V_28 [ 0 ] , V_21 -> V_36 . V_29 ) ;
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
V_8 . V_90 ( V_21 -> V_91 ) ;
V_88 = V_21 -> gamma ;
for ( V_86 = 0 ; V_86 <= 2 ; V_86 ++ )
for ( V_87 = 0 ; V_87 <= 255 ; V_87 ++ )
* V_88 ++ = V_87 ;
if ( V_8 . V_92 )
V_8 . V_92 ( V_21 -> V_91 , V_21 -> gamma ) ;
F_10 ( V_12 ) ;
F_4 ( & V_24 -> gamma , F_15 ( V_21 , gamma ) ) ;
F_4 ( & V_24 -> V_93 , F_15 ( V_21 , V_93 ) ) ;
F_4 ( & V_24 -> V_94 , 0x007F7F7F ) ;
F_4 ( & V_24 -> V_95 , 0 ) ;
F_4 ( & V_24 -> V_96 , ( V_41 -> V_54 << 16 | V_41 -> V_53 ) ) ;
F_4 ( & V_24 -> V_97 , 0 ) ;
F_4 ( & V_24 -> V_98 , 0 ) ;
V_89 = V_41 -> V_99 << 22 |
V_41 -> V_100 << 11 |
V_41 -> V_101 ;
F_4 ( & V_24 -> V_102 , V_89 ) ;
V_89 = V_41 -> V_103 << 22 |
V_41 -> V_104 << 11 |
V_41 -> V_105 ;
F_4 ( & V_24 -> V_106 , V_89 ) ;
V_8 . V_107 ( V_41 -> V_108 ) ;
F_4 ( & V_24 -> V_109 , 0 ) ;
F_4 ( & V_24 -> V_110 , 0x00037800 ) ;
F_4 ( & V_24 -> V_111 , 0 ) ;
F_4 ( & V_24 -> V_112 , 0x01F5F666 ) ;
F_9 ( V_12 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
T_1 V_113 = V_12 -> V_76 . V_78 * V_12 -> V_41 . V_58 ;
void * V_114 ;
V_114 = F_17 ( V_113 , V_115 | V_116 ) ;
if ( ! V_114 ) {
F_18 ( V_12 -> V_117 , L_3 ) ;
return - V_118 ;
}
F_19 ( & V_12 -> V_119 ) ;
V_12 -> V_120 = V_114 ;
V_12 -> V_76 . V_121 = F_20 ( V_12 -> V_120 ) ;
V_12 -> V_76 . V_113 = V_113 ;
F_21 ( & V_12 -> V_119 ) ;
V_12 -> V_122 = V_12 -> V_76 . V_113 ;
return 0 ;
}
static void F_22 ( struct V_11 * V_12 )
{
void * V_114 = V_12 -> V_120 ;
T_5 V_123 = V_12 -> V_76 . V_113 ;
F_19 ( & V_12 -> V_119 ) ;
V_12 -> V_120 = NULL ;
V_12 -> V_76 . V_121 = 0 ;
V_12 -> V_76 . V_113 = 0 ;
F_21 ( & V_12 -> V_119 ) ;
if ( V_114 )
F_23 ( V_114 , V_123 ) ;
}
static int F_24 ( struct V_11 * V_12 )
{
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
V_19 -> V_124 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_125 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
return 0 ;
}
static T_1 F_25 ( unsigned int V_61 )
{
#define F_26 0x10000000
#define F_27 0x0E000000
#define F_28 25
#define F_29 0x01800000
#define F_30 23
#define F_31 0x00600000
#define F_32 21
#define F_33 0x00180000
#define F_34 19
#define F_35 0x00040000
#define F_36 0x00030000
#define F_37 16
#define F_38 0x0000F000
#define F_39 12
#define F_40 0x00000F00
#define F_41 8
#define F_42 0x000000F0
#define F_43 4
#define F_44 0x0000000F
#define F_45 0
#define F_46 ( T_6 , V_63 , V_68 , V_67 , T_7 , T_8 , T_9 , T_10 , T_11 ) \
cpu_to_le32(PF_BYTE_F | (alpha << PF_ALPHA_C_SHIFT) | \
(blue << PF_BLUE_C_SHIFT) | (green << PF_GREEN_C_SHIFT) | \
(red << PF_RED_C_SHIFT) | (c3 << PF_COMP_3_SHIFT) | \
(c2 << PF_COMP_2_SHIFT) | (c1 << PF_COMP_1_SHIFT) | \
(c0 << PF_COMP_0_SHIFT) | (size << PF_PIXEL_S_SHIFT))
switch ( V_61 ) {
case 32 :
return F_46 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_46 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_46 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_47 ( L_4 , V_61 ) ;
return 0 ;
}
}
static int F_48 ( struct V_11 * V_12 )
{
unsigned long V_126 ;
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_23 T_2 * V_24 ;
V_24 = V_21 -> V_25 ;
F_13 ( V_12 ) ;
V_16 -> V_127 = 1 ;
V_126 = V_12 -> V_41 . V_58 * V_12 -> V_76 . V_78 ;
if ( V_126 != V_12 -> V_76 . V_113 ) {
if ( V_12 -> V_76 . V_121 )
F_22 ( V_12 ) ;
if ( F_16 ( V_12 ) ) {
F_18 ( V_12 -> V_117 , L_5 ) ;
return - V_118 ;
}
}
if ( V_8 . V_128 )
V_19 -> V_129 = V_8 . V_128 ( V_21 -> V_91 ,
V_41 -> V_61 ) ;
else
V_19 -> V_129 = F_25 ( V_41 -> V_61 ) ;
V_19 -> V_130 = F_7 ( V_12 -> V_76 . V_121 ) ;
V_19 -> V_131 = F_7 ( ( V_41 -> V_58 << 12 ) |
V_41 -> V_57 ) | V_16 -> V_132 ;
V_19 -> V_133 = F_7 ( ( V_41 -> V_54 << 16 ) | V_41 -> V_53 ) ;
V_19 -> V_124 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_125 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
V_19 -> V_134 = 0 ;
V_19 -> V_135 = 0 ;
V_19 -> V_136 = 0 ;
V_19 -> V_137 = 255 ;
V_19 -> V_138 = 255 ;
V_19 -> V_139 = 255 ;
if ( V_16 -> V_26 == V_27 )
F_14 ( V_12 ) ;
return 0 ;
}
static inline T_3 F_49 ( T_3 V_5 , T_3 V_71 )
{
return ( ( V_5 << V_71 ) + 0x7FFF - V_5 ) >> 16 ;
}
static int F_50 ( unsigned int V_140 , unsigned int V_63 ,
unsigned int V_67 , unsigned int V_68 ,
unsigned int V_69 , struct V_11 * V_12 )
{
int V_141 = 1 ;
if ( V_12 -> V_41 . V_72 )
V_63 = V_67 = V_68 = ( 19595 * V_63 + 38470 * V_67 +
7471 * V_68 ) >> 16 ;
switch ( V_12 -> V_76 . V_82 ) {
case V_83 :
if ( V_140 < 16 ) {
T_1 * V_142 = V_12 -> V_143 ;
T_1 V_144 ;
V_63 = F_49 ( V_63 , V_12 -> V_41 . V_63 . V_64 ) ;
V_67 = F_49 ( V_67 , V_12 -> V_41 . V_67 . V_64 ) ;
V_68 = F_49 ( V_68 , V_12 -> V_41 . V_68 . V_64 ) ;
V_69 = F_49 ( V_69 , V_12 -> V_41 . V_69 . V_64 ) ;
V_144 = ( V_63 << V_12 -> V_41 . V_63 . V_65 ) |
( V_67 << V_12 -> V_41 . V_67 . V_65 ) |
( V_68 << V_12 -> V_41 . V_68 . V_65 ) |
( V_69 << V_12 -> V_41 . V_69 . V_65 ) ;
V_142 [ V_140 ] = V_144 ;
V_141 = 0 ;
}
break;
}
return V_141 ;
}
static int F_51 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
if ( ( V_12 -> V_41 . V_59 == V_41 -> V_59 ) &&
( V_12 -> V_41 . V_60 == V_41 -> V_60 ) )
return 0 ;
if ( V_41 -> V_59 < 0 || V_41 -> V_60 < 0
|| V_41 -> V_59 + V_12 -> V_41 . V_53 > V_12 -> V_41 . V_57
|| V_41 -> V_60 + V_12 -> V_41 . V_54 > V_12 -> V_41 . V_58 )
return - V_145 ;
V_12 -> V_41 . V_59 = V_41 -> V_59 ;
V_12 -> V_41 . V_60 = V_41 -> V_60 ;
if ( V_41 -> V_146 & V_147 )
V_12 -> V_41 . V_146 |= V_147 ;
else
V_12 -> V_41 . V_146 &= ~ V_147 ;
F_24 ( V_12 ) ;
return 0 ;
}
static int F_52 ( struct V_11 * V_12 , unsigned int V_148 ,
unsigned long V_149 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_150 V_151 ;
unsigned char V_152 ;
struct V_153 V_154 ;
T_3 V_129 ;
void T_12 * V_155 = ( void T_12 * ) V_149 ;
if ( ! V_149 )
return - V_145 ;
switch ( V_148 ) {
case V_156 :
F_53 ( V_12 -> V_117 ,
L_6 ,
V_156 ) ;
case V_157 :
if ( F_54 ( & V_129 , V_155 , sizeof( V_129 ) ) )
return - V_158 ;
V_19 -> V_129 = V_129 ;
break;
case V_159 :
F_53 ( V_12 -> V_117 ,
L_7 ,
V_159 ) ;
case V_160 :
V_129 = V_19 -> V_129 ;
if ( F_55 ( V_155 , & V_129 , sizeof( V_129 ) ) )
return - V_158 ;
break;
case V_161 :
if ( F_54 ( & V_154 , V_155 , sizeof( V_154 ) ) )
return - V_158 ;
V_16 -> V_55 = V_154 . V_55 ;
V_16 -> V_56 = V_154 . V_56 ;
F_12 ( & V_12 -> V_41 , V_12 ) ;
F_24 ( V_12 ) ;
break;
case V_162 :
V_154 . V_55 = V_16 -> V_55 ;
V_154 . V_56 = V_16 -> V_56 ;
if ( F_55 ( V_155 , & V_154 , sizeof( V_154 ) ) )
return - V_158 ;
break;
case V_163 :
V_152 = V_16 -> V_132 ;
if ( F_55 ( V_155 , & V_152 , sizeof( V_152 ) ) )
return - V_158 ;
break;
case V_164 :
if ( F_54 ( & V_152 , V_155 , sizeof( V_152 ) ) )
return - V_158 ;
V_19 -> V_131 = ( V_19 -> V_131 & ( ~ 0xff ) ) |
( V_152 & 0xff ) ;
V_16 -> V_132 = V_152 ;
break;
case V_165 :
if ( F_54 ( & V_151 , V_155 , sizeof( V_151 ) ) )
return - V_158 ;
if ( V_151 . V_166 &&
( V_151 . V_167 < V_151 . V_168 ||
V_151 . V_169 < V_151 . V_170 ||
V_151 . V_171 < V_151 . V_172 ) )
return - V_145 ;
if ( ! V_151 . V_166 ) {
V_19 -> V_134 = 0 ;
V_19 -> V_135 = 0 ;
V_19 -> V_136 = 0 ;
V_19 -> V_137 = 255 ;
V_19 -> V_138 = 255 ;
V_19 -> V_139 = 255 ;
} else {
V_19 -> V_134 = V_151 . V_167 ;
V_19 -> V_135 = V_151 . V_169 ;
V_19 -> V_136 = V_151 . V_171 ;
V_19 -> V_137 = V_151 . V_168 ;
V_19 -> V_138 = V_151 . V_170 ;
V_19 -> V_139 = V_151 . V_172 ;
}
break;
default:
F_18 ( V_12 -> V_117 , L_8 , V_148 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_56 ( struct V_11 * V_12 , int V_174 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_175 = 0 ;
if ( ( V_16 -> V_26 == V_27 ) && V_8 . V_176 )
V_8 . V_176 () ;
F_57 ( & V_177 ) ;
V_16 -> V_32 ++ ;
if ( V_16 -> V_32 == 1 ) {
F_12 ( & V_12 -> V_41 , V_12 ) ;
V_175 = F_48 ( V_12 ) ;
if ( V_175 < 0 )
V_16 -> V_32 -- ;
else
F_6 ( V_12 ) ;
}
F_58 ( & V_177 ) ;
return V_175 ;
}
static int F_59 ( struct V_11 * V_12 , int V_174 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_175 = 0 ;
F_57 ( & V_177 ) ;
V_16 -> V_32 -- ;
if ( V_16 -> V_32 == 0 )
F_8 ( V_12 ) ;
F_58 ( & V_177 ) ;
return V_175 ;
}
static int T_13 F_60 ( struct V_11 * V_12 )
{
int V_178 ;
struct V_13 * V_16 = V_12 -> V_17 ;
const char * V_179 , * V_180 = L_9 ;
struct V_181 * V_182 = V_183 ;
unsigned int V_184 = F_61 ( V_183 ) ;
int V_185 = 1 ;
V_12 -> V_41 . V_186 = V_187 ;
V_12 -> V_188 = & V_189 ;
V_12 -> V_190 = V_191 | V_192 | V_193 |
V_194 ;
V_12 -> V_143 = V_16 -> V_143 ;
V_178 = F_62 ( & V_12 -> V_195 , 16 , 0 ) ;
if ( V_178 )
return V_178 ;
if ( V_16 -> V_26 == V_27 ) {
if ( V_16 -> V_196 ) {
F_63 ( V_16 -> V_196 , & V_12 -> V_197 ) ;
F_64 ( V_12 -> V_197 . V_198 ,
V_12 -> V_197 . V_199 ,
& V_12 -> V_200 ) ;
V_182 = V_12 -> V_197 . V_198 ;
V_184 = V_12 -> V_197 . V_199 ;
}
V_179 = V_201 ;
} else {
V_179 = V_180 ;
}
V_178 = F_65 ( & V_12 -> V_41 , V_12 , V_179 , V_182 , V_184 , NULL ,
V_62 ) ;
if ( ! V_178 ) {
if ( ( V_16 -> V_26 == V_27 ) && V_16 -> V_196 )
V_185 = 0 ;
else
return - V_145 ;
}
if ( ! V_185 ) {
V_178 = F_65 ( & V_12 -> V_41 , V_12 , V_179 , V_183 ,
F_61 ( V_183 ) , NULL , V_62 ) ;
if ( V_178 )
V_185 = 1 ;
}
if ( ! V_185 && V_12 -> V_197 . V_198 ) {
struct V_202 * V_203 = & V_12 -> V_197 ;
struct V_181 * V_198 = & V_203 -> V_198 [ 0 ] ;
if ( V_203 -> V_204 & V_205 ) {
int V_86 ;
for ( V_86 = 0 ; V_86 < V_203 -> V_199 ; V_86 ++ ) {
if ( V_203 -> V_198 [ V_86 ] . V_206 & V_207 ) {
V_198 = & V_203 -> V_198 [ V_86 ] ;
break;
}
}
}
V_12 -> V_41 . V_61 = V_62 ;
F_66 ( & V_12 -> V_41 , V_198 ) ;
}
if ( F_12 ( & V_12 -> V_41 , V_12 ) ) {
F_18 ( V_12 -> V_117 , L_10 ) ;
F_22 ( V_12 ) ;
F_67 ( & V_12 -> V_195 ) ;
return - V_145 ;
}
if ( F_68 ( V_12 ) < 0 ) {
F_18 ( V_12 -> V_117 , L_11 ) ;
F_22 ( V_12 ) ;
F_67 ( & V_12 -> V_195 ) ;
return - V_145 ;
}
V_16 -> V_208 = 1 ;
F_69 ( V_12 -> V_117 , L_12 , V_16 -> V_77 ) ;
return 0 ;
}
static void F_70 ( struct V_11 * V_12 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
if ( ! V_16 -> V_208 )
return;
if ( V_16 -> V_26 == V_27 )
F_71 ( V_16 -> V_196 ) ;
F_72 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( & V_12 -> V_195 )
F_67 ( & V_12 -> V_195 ) ;
V_16 -> V_208 = 0 ;
}
static T_14 F_73 ( int V_209 , void * V_210 )
{
struct V_23 T_2 * V_24 = V_210 ;
unsigned int V_211 = F_5 ( & V_24 -> V_111 ) ;
if ( V_211 ) {
if ( V_211 & V_212 ) {
F_4 ( & V_24 -> V_38 , 0 ) ;
F_74 ( 1 ) ;
F_4 ( & V_24 -> V_38 , 1 ) ;
}
#if F_75 ( V_213 )
else if ( V_211 & V_214 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_215 ;
V_86 += V_216 )
__asm__ __volatile__ (
"dcbz 0, %[input]"
::[input]"r"(&coherence_data[i]));
}
#endif
return V_217 ;
}
return V_218 ;
}
static int F_76 ( struct V_20 * V_21 )
{
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
T_1 V_219 ;
int V_141 ;
F_5 ( & V_24 -> V_111 ) ;
V_141 = F_77 ( V_21 -> V_209 , F_73 , 0 , L_13 , V_24 ) ;
if ( ! V_141 ) {
V_219 = V_220 | V_221 ;
#if ! F_75 ( V_213 )
V_219 |= V_214 ;
#endif
F_5 ( & V_24 -> V_111 ) ;
F_4 ( & V_24 -> V_222 , V_219 ) ;
}
return V_141 ;
}
static void F_78 ( struct V_20 * V_21 )
{
struct V_23 T_2 * V_24 = V_21 -> V_25 ;
F_4 ( & V_24 -> V_222 , 0x1f ) ;
F_79 ( V_21 -> V_209 , NULL ) ;
}
static int F_80 ( struct V_223 * V_224 , T_15 V_225 )
{
struct V_20 * V_21 ;
V_21 = F_81 ( & V_224 -> V_117 ) ;
F_10 ( V_21 -> V_52 ) ;
return 0 ;
}
static int F_82 ( struct V_223 * V_224 )
{
struct V_20 * V_21 ;
V_21 = F_81 ( & V_224 -> V_117 ) ;
F_9 ( V_21 -> V_52 ) ;
return 0 ;
}
static T_16 F_83 ( struct V_226 * V_226 ,
struct V_227 * V_228 , const char * V_155 , T_5 V_32 )
{
enum V_1 V_229 ;
struct V_20 * V_21 =
F_84 ( V_228 , struct V_20 , V_230 ) ;
V_229 = V_21 -> V_91 ;
V_21 -> V_91 = F_1 ( V_155 ) ;
if ( V_229 != V_21 -> V_91 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_231 ; V_86 ++ )
F_48 ( & V_21 -> V_52 [ V_86 ] ) ;
}
return V_32 ;
}
static T_16 F_85 ( struct V_226 * V_226 ,
struct V_227 * V_228 , char * V_155 )
{
struct V_20 * V_21 =
F_84 ( V_228 , struct V_20 , V_230 ) ;
switch ( V_21 -> V_91 ) {
case V_4 :
return sprintf ( V_155 , L_14 ) ;
case V_6 :
return sprintf ( V_155 , L_15 ) ;
case V_7 :
return sprintf ( V_155 , L_16 ) ;
}
return 0 ;
}
static int T_13 F_86 ( struct V_223 * V_232 )
{
struct V_233 * V_234 = V_232 -> V_117 . V_235 ;
struct V_13 * V_16 ;
struct V_20 * V_21 ;
int V_38 ;
T_17 V_236 ;
unsigned int V_86 ;
int V_141 ;
V_21 = F_87 ( & V_232 -> V_117 , sizeof( struct V_20 ) ,
& V_236 , V_115 | V_116 ) ;
if ( ! V_21 )
return - V_118 ;
V_21 -> V_236 = V_236 ;
if ( ( unsigned long ) V_21 & 31 ) {
F_18 ( & V_232 -> V_117 , L_17 ) ;
V_141 = - V_118 ;
goto error;
}
F_88 ( & V_21 -> V_237 ) ;
for ( V_86 = 0 ; V_86 < V_231 ; V_86 ++ ) {
struct V_11 * V_12 = & V_21 -> V_52 [ V_86 ] ;
V_12 -> V_226 = & V_232 -> V_117 ;
V_12 -> V_17 = & V_21 -> V_31 [ V_86 ] ;
V_21 -> V_19 [ V_86 ] . V_29 = F_15 ( V_21 , V_19 [ V_86 ] ) ;
V_12 -> V_76 . V_121 = 0 ;
V_16 = V_12 -> V_17 ;
memcpy ( V_16 , & V_238 [ V_86 ] , sizeof( struct V_13 ) ) ;
V_16 -> V_22 = V_21 ;
V_16 -> V_19 = & V_21 -> V_19 [ V_86 ] ;
if ( V_16 -> V_26 == V_27 ) {
const T_4 * V_239 ;
int V_126 ;
V_239 = F_89 ( V_234 , L_18 , & V_126 ) ;
if ( V_239 && V_126 == V_240 )
V_16 -> V_196 = F_90 ( V_239 , V_240 ,
V_241 ) ;
}
}
V_21 -> V_25 = F_91 ( V_234 , 0 ) ;
if ( ! V_21 -> V_25 ) {
F_18 ( & V_232 -> V_117 , L_19 ) ;
V_141 = - V_158 ;
goto error;
}
V_38 = F_5 ( & V_21 -> V_25 -> V_38 ) ;
if ( V_38 == V_242 )
F_4 ( & V_21 -> V_25 -> V_38 , 0 ) ;
V_21 -> V_209 = F_92 ( V_234 , 0 ) ;
if ( ! V_21 -> V_209 ) {
F_18 ( & V_232 -> V_117 , L_20 ) ;
V_141 = - V_145 ;
goto error;
}
V_21 -> V_91 = V_91 ;
V_21 -> V_36 . V_130 = F_7 ( F_15 ( V_21 , V_243 ) ) ;
V_21 -> V_36 . V_129 = 0x88882317 ;
V_21 -> V_36 . V_131 = F_7 ( ( 4 << 12 ) | 4 ) ;
V_21 -> V_36 . V_133 = F_7 ( ( 4 << 16 ) | 2 ) ;
V_21 -> V_36 . V_124 = 0 ;
V_21 -> V_36 . V_125 = 0 ;
V_21 -> V_36 . V_33 = 0 ;
V_21 -> V_36 . V_29 = F_15 ( V_21 , V_36 ) ;
if ( V_38 == V_242 )
F_4 ( & V_21 -> V_25 -> V_28 [ 0 ] , V_21 -> V_36 . V_29 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 1 ] , V_21 -> V_36 . V_29 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 2 ] , V_21 -> V_36 . V_29 ) ;
for ( V_86 = 0 ; V_86 < V_231 ; V_86 ++ ) {
V_141 = F_60 ( & V_21 -> V_52 [ V_86 ] ) ;
if ( V_141 ) {
F_18 ( & V_232 -> V_117 , L_21 , V_86 ) ;
goto error;
}
}
if ( F_76 ( V_21 ) ) {
F_18 ( & V_232 -> V_117 , L_22 ) ;
goto error;
}
F_93 ( & V_21 -> V_230 . V_228 ) ;
V_21 -> V_230 . V_228 . V_244 = L_23 ;
V_21 -> V_230 . V_228 . V_245 = V_246 | V_247 ;
V_21 -> V_230 . V_248 = F_85 ;
V_21 -> V_230 . V_249 = F_83 ;
V_141 = F_94 ( & V_232 -> V_117 , & V_21 -> V_230 ) ;
if ( V_141 ) {
F_18 ( & V_232 -> V_117 , L_24 ,
V_21 -> V_230 . V_228 . V_244 ) ;
}
F_95 ( & V_232 -> V_117 , V_21 ) ;
return 0 ;
error:
for ( V_86 = 0 ; V_86 < V_231 ; V_86 ++ )
F_70 ( & V_21 -> V_52 [ V_86 ] ) ;
F_96 ( V_21 -> V_25 ) ;
F_97 ( & V_232 -> V_117 , sizeof( struct V_20 ) , V_21 ,
V_21 -> V_236 ) ;
return V_141 ;
}
static int F_98 ( struct V_223 * V_232 )
{
struct V_20 * V_21 ;
int V_86 ;
V_21 = F_81 ( & V_232 -> V_117 ) ;
F_10 ( & V_21 -> V_52 [ 0 ] ) ;
F_78 ( V_21 ) ;
for ( V_86 = 0 ; V_86 < V_231 ; V_86 ++ )
F_70 ( & V_21 -> V_52 [ V_86 ] ) ;
F_96 ( V_21 -> V_25 ) ;
F_97 ( & V_232 -> V_117 , sizeof( struct V_20 ) , V_21 ,
V_21 -> V_236 ) ;
return 0 ;
}
static int T_18 F_99 ( char * V_250 )
{
char * V_251 ;
unsigned long V_5 ;
if ( ! V_250 || ! * V_250 )
return 0 ;
while ( ( V_251 = F_100 ( & V_250 , L_25 ) ) != NULL ) {
if ( ! * V_251 )
continue;
if ( ! strncmp ( V_251 , L_26 , 8 ) ) {
V_91 = F_1 ( V_251 + 8 ) ;
} else if ( ! strncmp ( V_251 , L_27 , 4 ) ) {
if ( ! F_2 ( V_251 + 4 , 10 , & V_5 ) )
V_62 = V_5 ;
} else
V_201 = V_251 ;
}
return 0 ;
}
static int T_18 F_101 ( void )
{
#ifdef V_213
struct V_233 * V_234 ;
const T_1 * V_239 ;
#endif
int V_141 ;
#ifndef F_102
char * V_252 ;
if ( F_103 ( L_28 , & V_252 ) )
return - V_253 ;
F_99 ( V_252 ) ;
#else
V_91 = F_1 ( V_254 ) ;
#endif
F_104 ( L_29 ) ;
#ifdef V_213
V_234 = F_105 ( NULL , L_30 ) ;
if ( ! V_234 ) {
F_47 ( L_31 ) ;
return - V_253 ;
}
V_239 = F_89 ( V_234 , L_32 , NULL ) ;
if ( V_239 == NULL ) {
F_47 ( L_33
L_34 ) ;
F_106 ( V_234 ) ;
return - V_253 ;
}
V_215 = F_107 ( V_239 ) * 13 ;
V_215 /= 8 ;
V_239 = F_89 ( V_234 , L_35 , NULL ) ;
if ( V_239 == NULL ) {
F_47 ( L_36
L_34 ) ;
F_106 ( V_234 ) ;
return - V_253 ;
}
V_216 = F_107 ( V_239 ) ;
F_106 ( V_234 ) ;
V_255 = F_108 ( V_215 ) ;
if ( ! V_255 )
return - V_118 ;
#endif
V_141 = F_109 ( & V_256 ) ;
if ( V_141 ) {
F_47 ( L_37 ) ;
#if F_75 ( V_213 )
F_110 ( V_255 ) ;
#endif
}
return V_141 ;
}
static void T_19 F_111 ( void )
{
F_112 ( & V_256 ) ;
#if F_75 ( V_213 )
F_110 ( V_255 ) ;
#endif
}
