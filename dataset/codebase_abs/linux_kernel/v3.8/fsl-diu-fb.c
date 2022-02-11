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
F_4 ( & V_24 -> V_93 , F_15 ( V_21 , V_93 ) ) ;
F_4 ( & V_24 -> V_94 , 0x007F7F7F ) ;
F_4 ( & V_24 -> V_95 , ( V_41 -> V_54 << 16 ) | V_41 -> V_53 ) ;
V_89 = V_41 -> V_96 << 22 |
V_41 -> V_97 << 11 |
V_41 -> V_98 ;
F_4 ( & V_24 -> V_99 , V_89 ) ;
V_89 = V_41 -> V_100 << 22 |
V_41 -> V_101 << 11 |
V_41 -> V_102 ;
F_4 ( & V_24 -> V_103 , V_89 ) ;
V_8 . V_104 ( V_41 -> V_105 ) ;
#ifndef F_16
F_4 ( & V_24 -> V_106 , 0x01F5F666 ) ;
#endif
F_9 ( V_12 ) ;
}
static int F_17 ( struct V_11 * V_12 )
{
T_1 V_107 = V_12 -> V_76 . V_78 * V_12 -> V_41 . V_58 ;
void * V_108 ;
V_108 = F_18 ( V_107 , V_109 | V_110 ) ;
if ( ! V_108 ) {
F_19 ( V_12 -> V_111 , L_3 ) ;
return - V_112 ;
}
F_20 ( & V_12 -> V_113 ) ;
V_12 -> V_114 = V_108 ;
V_12 -> V_76 . V_115 = F_21 ( V_12 -> V_114 ) ;
V_12 -> V_76 . V_107 = V_107 ;
F_22 ( & V_12 -> V_113 ) ;
V_12 -> V_116 = V_12 -> V_76 . V_107 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
void * V_108 = V_12 -> V_114 ;
T_5 V_117 = V_12 -> V_76 . V_107 ;
F_20 ( & V_12 -> V_113 ) ;
V_12 -> V_114 = NULL ;
V_12 -> V_76 . V_115 = 0 ;
V_12 -> V_76 . V_107 = 0 ;
F_22 ( & V_12 -> V_113 ) ;
if ( V_108 )
F_24 ( V_108 , V_117 ) ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
V_19 -> V_118 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_119 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
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
#define F_47 ( T_6 , V_63 , V_68 , V_67 , T_7 , T_8 , T_9 , T_10 , T_11 ) \
cpu_to_le32(PF_BYTE_F | (alpha << PF_ALPHA_C_SHIFT) | \
(blue << PF_BLUE_C_SHIFT) | (green << PF_GREEN_C_SHIFT) | \
(red << PF_RED_C_SHIFT) | (c3 << PF_COMP_3_SHIFT) | \
(c2 << PF_COMP_2_SHIFT) | (c1 << PF_COMP_1_SHIFT) | \
(c0 << PF_COMP_0_SHIFT) | (size << PF_PIXEL_S_SHIFT))
switch ( V_61 ) {
case 32 :
return F_47 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_47 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_47 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_48 ( L_4 , V_61 ) ;
return 0 ;
}
}
static int F_49 ( struct V_11 * V_12 )
{
unsigned long V_120 ;
struct V_40 * V_41 = & V_12 -> V_41 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_23 T_2 * V_24 ;
V_24 = V_21 -> V_25 ;
F_13 ( V_12 ) ;
V_120 = V_12 -> V_41 . V_58 * V_12 -> V_76 . V_78 ;
if ( V_120 != V_12 -> V_76 . V_107 ) {
if ( V_12 -> V_76 . V_115 )
F_23 ( V_12 ) ;
if ( F_17 ( V_12 ) ) {
F_19 ( V_12 -> V_111 , L_5 ) ;
return - V_112 ;
}
}
if ( V_8 . V_121 )
V_19 -> V_122 = V_8 . V_121 ( V_21 -> V_91 ,
V_41 -> V_61 ) ;
else
V_19 -> V_122 = F_26 ( V_41 -> V_61 ) ;
V_19 -> V_123 = F_7 ( V_12 -> V_76 . V_115 ) ;
V_19 -> V_124 = F_7 ( ( V_41 -> V_58 << 12 ) |
V_41 -> V_57 ) | V_16 -> V_125 ;
V_19 -> V_126 = F_7 ( ( V_41 -> V_54 << 16 ) | V_41 -> V_53 ) ;
V_19 -> V_118 = F_7 ( ( V_41 -> V_60 << 16 ) | V_41 -> V_59 ) ;
V_19 -> V_119 = F_7 ( ( V_16 -> V_56 << 16 ) | V_16 -> V_55 ) ;
V_19 -> V_127 = 0 ;
V_19 -> V_128 = 0 ;
V_19 -> V_129 = 0 ;
V_19 -> V_130 = 255 ;
V_19 -> V_131 = 255 ;
V_19 -> V_132 = 255 ;
if ( V_16 -> V_26 == V_27 )
F_14 ( V_12 ) ;
return 0 ;
}
static inline T_3 F_50 ( T_3 V_5 , T_3 V_71 )
{
return ( ( V_5 << V_71 ) + 0x7FFF - V_5 ) >> 16 ;
}
static int F_51 ( unsigned int V_133 , unsigned int V_63 ,
unsigned int V_67 , unsigned int V_68 ,
unsigned int V_69 , struct V_11 * V_12 )
{
int V_134 = 1 ;
if ( V_12 -> V_41 . V_72 )
V_63 = V_67 = V_68 = ( 19595 * V_63 + 38470 * V_67 +
7471 * V_68 ) >> 16 ;
switch ( V_12 -> V_76 . V_82 ) {
case V_83 :
if ( V_133 < 16 ) {
T_1 * V_135 = V_12 -> V_136 ;
T_1 V_137 ;
V_63 = F_50 ( V_63 , V_12 -> V_41 . V_63 . V_64 ) ;
V_67 = F_50 ( V_67 , V_12 -> V_41 . V_67 . V_64 ) ;
V_68 = F_50 ( V_68 , V_12 -> V_41 . V_68 . V_64 ) ;
V_69 = F_50 ( V_69 , V_12 -> V_41 . V_69 . V_64 ) ;
V_137 = ( V_63 << V_12 -> V_41 . V_63 . V_65 ) |
( V_67 << V_12 -> V_41 . V_67 . V_65 ) |
( V_68 << V_12 -> V_41 . V_68 . V_65 ) |
( V_69 << V_12 -> V_41 . V_69 . V_65 ) ;
V_135 [ V_133 ] = V_137 ;
V_134 = 0 ;
}
break;
}
return V_134 ;
}
static int F_52 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
if ( ( V_12 -> V_41 . V_59 == V_41 -> V_59 ) &&
( V_12 -> V_41 . V_60 == V_41 -> V_60 ) )
return 0 ;
if ( V_41 -> V_59 < 0 || V_41 -> V_60 < 0
|| V_41 -> V_59 + V_12 -> V_41 . V_53 > V_12 -> V_41 . V_57
|| V_41 -> V_60 + V_12 -> V_41 . V_54 > V_12 -> V_41 . V_58 )
return - V_138 ;
V_12 -> V_41 . V_59 = V_41 -> V_59 ;
V_12 -> V_41 . V_60 = V_41 -> V_60 ;
if ( V_41 -> V_139 & V_140 )
V_12 -> V_41 . V_139 |= V_140 ;
else
V_12 -> V_41 . V_139 &= ~ V_140 ;
F_25 ( V_12 ) ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , unsigned int V_141 ,
unsigned long V_142 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_143 V_144 ;
unsigned char V_145 ;
struct V_146 V_147 ;
T_3 V_122 ;
void T_12 * V_148 = ( void T_12 * ) V_142 ;
if ( ! V_142 )
return - V_138 ;
F_54 ( V_12 -> V_111 , L_6 , V_141 ,
F_55 ( V_141 ) & V_149 ? L_7 : L_8 ,
F_55 ( V_141 ) & V_150 ? L_9 : L_8 ,
F_56 ( V_141 ) , F_57 ( V_141 ) , F_58 ( V_141 ) ) ;
switch ( V_141 ) {
case V_151 :
F_59 ( V_12 -> V_111 ,
L_10 ,
V_151 ) ;
case V_152 :
if ( F_60 ( & V_122 , V_148 , sizeof( V_122 ) ) )
return - V_153 ;
V_19 -> V_122 = V_122 ;
break;
case V_154 :
F_59 ( V_12 -> V_111 ,
L_11 ,
V_154 ) ;
case V_155 :
V_122 = V_19 -> V_122 ;
if ( F_61 ( V_148 , & V_122 , sizeof( V_122 ) ) )
return - V_153 ;
break;
case V_156 :
if ( F_60 ( & V_147 , V_148 , sizeof( V_147 ) ) )
return - V_153 ;
V_16 -> V_55 = V_147 . V_55 ;
V_16 -> V_56 = V_147 . V_56 ;
F_12 ( & V_12 -> V_41 , V_12 ) ;
F_25 ( V_12 ) ;
break;
case V_157 :
V_147 . V_55 = V_16 -> V_55 ;
V_147 . V_56 = V_16 -> V_56 ;
if ( F_61 ( V_148 , & V_147 , sizeof( V_147 ) ) )
return - V_153 ;
break;
case V_158 :
V_145 = V_16 -> V_125 ;
if ( F_61 ( V_148 , & V_145 , sizeof( V_145 ) ) )
return - V_153 ;
break;
case V_159 :
if ( F_60 ( & V_145 , V_148 , sizeof( V_145 ) ) )
return - V_153 ;
V_19 -> V_124 = ( V_19 -> V_124 & ( ~ 0xff ) ) |
( V_145 & 0xff ) ;
V_16 -> V_125 = V_145 ;
break;
case V_160 :
if ( F_60 ( & V_144 , V_148 , sizeof( V_144 ) ) )
return - V_153 ;
if ( V_144 . V_161 &&
( V_144 . V_162 < V_144 . V_163 ||
V_144 . V_164 < V_144 . V_165 ||
V_144 . V_166 < V_144 . V_167 ) )
return - V_138 ;
if ( ! V_144 . V_161 ) {
V_19 -> V_127 = 0 ;
V_19 -> V_128 = 0 ;
V_19 -> V_129 = 0 ;
V_19 -> V_130 = 255 ;
V_19 -> V_131 = 255 ;
V_19 -> V_132 = 255 ;
} else {
V_19 -> V_127 = V_144 . V_162 ;
V_19 -> V_128 = V_144 . V_164 ;
V_19 -> V_129 = V_144 . V_166 ;
V_19 -> V_130 = V_144 . V_163 ;
V_19 -> V_131 = V_144 . V_165 ;
V_19 -> V_132 = V_144 . V_167 ;
}
break;
#ifdef F_16
case V_168 : {
struct V_20 * V_21 = V_16 -> V_22 ;
if ( F_60 ( V_21 -> gamma , V_148 , sizeof( V_21 -> gamma ) ) )
return - V_153 ;
F_62 ( & V_21 -> V_25 -> gamma , 0 ) ;
break;
}
case V_169 : {
struct V_20 * V_21 = V_16 -> V_22 ;
if ( F_61 ( V_148 , V_21 -> gamma , sizeof( V_21 -> gamma ) ) )
return - V_153 ;
break;
}
#endif
default:
F_19 ( V_12 -> V_111 , L_12 , V_141 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_63 ( struct V_11 * V_12 , int V_171 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_172 = 0 ;
if ( ( V_16 -> V_26 == V_27 ) && V_8 . V_173 )
V_8 . V_173 () ;
F_64 ( & V_174 ) ;
V_16 -> V_32 ++ ;
if ( V_16 -> V_32 == 1 ) {
F_12 ( & V_12 -> V_41 , V_12 ) ;
V_172 = F_49 ( V_12 ) ;
if ( V_172 < 0 )
V_16 -> V_32 -- ;
else {
struct V_20 * V_21 = V_16 -> V_22 ;
#ifdef F_65
F_66 ( & V_21 -> V_25 -> V_175 ,
V_176 | V_177 ) ;
#else
F_66 ( & V_21 -> V_25 -> V_175 , V_176 ) ;
#endif
F_6 ( V_12 ) ;
}
}
F_67 ( & V_174 ) ;
return V_172 ;
}
static int F_68 ( struct V_11 * V_12 , int V_171 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
int V_172 = 0 ;
F_64 ( & V_174 ) ;
V_16 -> V_32 -- ;
if ( V_16 -> V_32 == 0 ) {
struct V_20 * V_21 = V_16 -> V_22 ;
F_4 ( & V_21 -> V_25 -> V_175 , 0xffffffff ) ;
F_8 ( V_12 ) ;
}
F_67 ( & V_174 ) ;
return V_172 ;
}
static int F_69 ( struct V_11 * V_12 )
{
int V_178 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_20 * V_21 = V_16 -> V_22 ;
const char * V_179 , * V_180 = L_13 ;
struct V_181 * V_182 = V_183 ;
unsigned int V_184 = F_70 ( V_183 ) ;
int V_185 = 1 ;
V_12 -> V_41 . V_186 = V_187 ;
V_12 -> V_188 = & V_189 ;
V_12 -> V_190 = V_191 | V_192 | V_193 |
V_194 ;
V_12 -> V_136 = V_16 -> V_136 ;
V_178 = F_71 ( & V_12 -> V_195 , 16 , 0 ) ;
if ( V_178 )
return V_178 ;
if ( V_16 -> V_26 == V_27 ) {
if ( V_21 -> V_196 ) {
F_72 ( V_21 -> V_197 , & V_12 -> V_198 ) ;
F_73 ( V_12 -> V_198 . V_199 ,
V_12 -> V_198 . V_200 ,
& V_12 -> V_201 ) ;
V_182 = V_12 -> V_198 . V_199 ;
V_184 = V_12 -> V_198 . V_200 ;
}
V_179 = V_202 ;
} else {
V_179 = V_180 ;
}
V_178 = F_74 ( & V_12 -> V_41 , V_12 , V_179 , V_182 , V_184 , NULL ,
V_62 ) ;
if ( ! V_178 ) {
if ( ( V_16 -> V_26 == V_27 ) && V_21 -> V_196 )
V_185 = 0 ;
else
return - V_138 ;
}
if ( ! V_185 ) {
V_178 = F_74 ( & V_12 -> V_41 , V_12 , V_179 , V_183 ,
F_70 ( V_183 ) , NULL , V_62 ) ;
if ( V_178 )
V_185 = 1 ;
}
if ( ! V_185 && V_12 -> V_198 . V_199 ) {
struct V_203 * V_204 = & V_12 -> V_198 ;
struct V_181 * V_199 = & V_204 -> V_199 [ 0 ] ;
if ( V_204 -> V_205 & V_206 ) {
int V_86 ;
for ( V_86 = 0 ; V_86 < V_204 -> V_200 ; V_86 ++ ) {
if ( V_204 -> V_199 [ V_86 ] . V_207 & V_208 ) {
V_199 = & V_204 -> V_199 [ V_86 ] ;
break;
}
}
}
V_12 -> V_41 . V_61 = V_62 ;
F_75 ( & V_12 -> V_41 , V_199 ) ;
}
if ( F_12 ( & V_12 -> V_41 , V_12 ) ) {
F_19 ( V_12 -> V_111 , L_14 ) ;
F_23 ( V_12 ) ;
F_76 ( & V_12 -> V_195 ) ;
return - V_138 ;
}
if ( F_77 ( V_12 ) < 0 ) {
F_19 ( V_12 -> V_111 , L_15 ) ;
F_23 ( V_12 ) ;
F_76 ( & V_12 -> V_195 ) ;
return - V_138 ;
}
V_16 -> V_209 = 1 ;
F_78 ( V_12 -> V_111 , L_16 , V_16 -> V_77 ) ;
return 0 ;
}
static void F_79 ( struct V_11 * V_12 )
{
struct V_13 * V_16 = V_12 -> V_17 ;
if ( ! V_16 -> V_209 )
return;
F_80 ( V_12 ) ;
F_23 ( V_12 ) ;
if ( & V_12 -> V_195 )
F_76 ( & V_12 -> V_195 ) ;
V_16 -> V_209 = 0 ;
}
static T_13 F_81 ( int V_210 , void * V_211 )
{
struct V_23 T_2 * V_24 = V_211 ;
T_14 V_212 = F_5 ( & V_24 -> V_213 ) ;
if ( V_212 ) {
if ( V_212 & V_176 ) {
F_4 ( & V_24 -> V_38 , 0 ) ;
F_82 ( 1 ) ;
F_4 ( & V_24 -> V_38 , 1 ) ;
}
#if F_83 ( F_65 )
else if ( V_212 & V_177 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_214 ;
V_86 += V_215 )
__asm__ __volatile__ (
"dcbz 0, %[input]"
::[input]"r"(&coherence_data[i]));
}
#endif
return V_216 ;
}
return V_217 ;
}
static int F_84 ( struct V_218 * V_219 , T_15 V_220 )
{
struct V_20 * V_21 ;
V_21 = F_85 ( & V_219 -> V_111 ) ;
F_10 ( V_21 -> V_52 ) ;
return 0 ;
}
static int F_86 ( struct V_218 * V_219 )
{
struct V_20 * V_21 ;
V_21 = F_85 ( & V_219 -> V_111 ) ;
F_9 ( V_21 -> V_52 ) ;
return 0 ;
}
static T_16 F_87 ( struct V_221 * V_221 ,
struct V_222 * V_223 , const char * V_148 , T_5 V_32 )
{
enum V_1 V_224 ;
struct V_20 * V_21 =
F_88 ( V_223 , struct V_20 , V_225 ) ;
V_224 = V_21 -> V_91 ;
V_21 -> V_91 = F_1 ( V_148 ) ;
if ( V_224 != V_21 -> V_91 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ )
F_49 ( & V_21 -> V_52 [ V_86 ] ) ;
}
return V_32 ;
}
static T_16 F_89 ( struct V_221 * V_221 ,
struct V_222 * V_223 , char * V_148 )
{
struct V_20 * V_21 =
F_88 ( V_223 , struct V_20 , V_225 ) ;
switch ( V_21 -> V_91 ) {
case V_4 :
return sprintf ( V_148 , L_17 ) ;
case V_6 :
return sprintf ( V_148 , L_18 ) ;
case V_7 :
return sprintf ( V_148 , L_19 ) ;
}
return 0 ;
}
static int F_90 ( struct V_218 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_111 . V_230 ;
struct V_13 * V_16 ;
struct V_20 * V_21 ;
T_17 V_231 ;
const void * V_232 ;
unsigned int V_86 ;
int V_134 ;
V_21 = F_91 ( & V_227 -> V_111 , sizeof( struct V_20 ) ,
& V_231 , V_109 | V_110 ) ;
if ( ! V_21 )
return - V_112 ;
V_21 -> V_231 = V_231 ;
if ( ( unsigned long ) V_21 & 31 ) {
F_19 ( & V_227 -> V_111 , L_20 ) ;
V_134 = - V_112 ;
goto error;
}
F_92 ( & V_21 -> V_233 ) ;
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ ) {
struct V_11 * V_12 = & V_21 -> V_52 [ V_86 ] ;
V_12 -> V_221 = & V_227 -> V_111 ;
V_12 -> V_17 = & V_21 -> V_31 [ V_86 ] ;
V_21 -> V_19 [ V_86 ] . V_29 = F_15 ( V_21 , V_19 [ V_86 ] ) ;
V_12 -> V_76 . V_115 = 0 ;
V_16 = V_12 -> V_17 ;
memcpy ( V_16 , & V_234 [ V_86 ] , sizeof( struct V_13 ) ) ;
V_16 -> V_22 = V_21 ;
V_16 -> V_19 = & V_21 -> V_19 [ V_86 ] ;
}
V_232 = F_93 ( V_229 , L_21 , & V_134 ) ;
if ( V_232 && V_134 == V_235 ) {
memcpy ( V_21 -> V_197 , V_232 , V_235 ) ;
V_21 -> V_196 = true ;
}
V_21 -> V_25 = F_94 ( V_229 , 0 ) ;
if ( ! V_21 -> V_25 ) {
F_19 ( & V_227 -> V_111 , L_22 ) ;
V_134 = - V_153 ;
goto error;
}
V_21 -> V_210 = F_95 ( V_229 , 0 ) ;
if ( ! V_21 -> V_210 ) {
F_19 ( & V_227 -> V_111 , L_23 ) ;
V_134 = - V_138 ;
goto error;
}
V_21 -> V_91 = V_91 ;
V_21 -> V_36 . V_123 = F_7 ( F_15 ( V_21 , V_236 ) ) ;
V_21 -> V_36 . V_122 = 0x88882317 ;
V_21 -> V_36 . V_124 = F_7 ( ( 4 << 12 ) | 4 ) ;
V_21 -> V_36 . V_126 = F_7 ( ( 4 << 16 ) | 2 ) ;
V_21 -> V_36 . V_118 = 0 ;
V_21 -> V_36 . V_119 = 0 ;
V_21 -> V_36 . V_33 = 0 ;
V_21 -> V_36 . V_29 = F_15 ( V_21 , V_36 ) ;
if ( F_5 ( & V_21 -> V_25 -> V_38 ) == V_237 )
F_4 ( & V_21 -> V_25 -> V_28 [ 0 ] , 0 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 1 ] , V_21 -> V_36 . V_29 ) ;
F_4 ( & V_21 -> V_25 -> V_28 [ 2 ] , V_21 -> V_36 . V_29 ) ;
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ ) {
V_134 = F_69 ( & V_21 -> V_52 [ V_86 ] ) ;
if ( V_134 ) {
F_19 ( & V_227 -> V_111 , L_24 , V_86 ) ;
goto error;
}
}
F_4 ( & V_21 -> V_25 -> V_175 , 0xffffffff ) ;
F_5 ( & V_21 -> V_25 -> V_213 ) ;
V_134 = F_96 ( V_21 -> V_210 , F_81 , 0 , L_25 ,
& V_21 -> V_25 ) ;
if ( V_134 ) {
F_19 ( & V_227 -> V_111 , L_26 ) ;
goto error;
}
F_97 ( & V_21 -> V_225 . V_223 ) ;
V_21 -> V_225 . V_223 . V_238 = L_27 ;
V_21 -> V_225 . V_223 . V_239 = V_240 | V_241 ;
V_21 -> V_225 . V_242 = F_89 ;
V_21 -> V_225 . V_243 = F_87 ;
V_134 = F_98 ( & V_227 -> V_111 , & V_21 -> V_225 ) ;
if ( V_134 ) {
F_19 ( & V_227 -> V_111 , L_28 ,
V_21 -> V_225 . V_223 . V_238 ) ;
}
F_99 ( & V_227 -> V_111 , V_21 ) ;
return 0 ;
error:
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ )
F_79 ( & V_21 -> V_52 [ V_86 ] ) ;
F_100 ( V_21 -> V_25 ) ;
return V_134 ;
}
static int F_101 ( struct V_218 * V_227 )
{
struct V_20 * V_21 ;
int V_86 ;
V_21 = F_85 ( & V_227 -> V_111 ) ;
F_10 ( & V_21 -> V_52 [ 0 ] ) ;
F_102 ( V_21 -> V_210 , & V_21 -> V_25 ) ;
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ )
F_79 ( & V_21 -> V_52 [ V_86 ] ) ;
F_100 ( V_21 -> V_25 ) ;
return 0 ;
}
static int T_18 F_103 ( char * V_244 )
{
char * V_245 ;
unsigned long V_5 ;
if ( ! V_244 || ! * V_244 )
return 0 ;
while ( ( V_245 = F_104 ( & V_244 , L_29 ) ) != NULL ) {
if ( ! * V_245 )
continue;
if ( ! strncmp ( V_245 , L_30 , 8 ) ) {
V_91 = F_1 ( V_245 + 8 ) ;
} else if ( ! strncmp ( V_245 , L_31 , 4 ) ) {
if ( ! F_2 ( V_245 + 4 , 10 , & V_5 ) )
V_62 = V_5 ;
} else
V_202 = V_245 ;
}
return 0 ;
}
static int T_18 F_105 ( void )
{
#ifdef F_65
struct V_228 * V_229 ;
const T_1 * V_232 ;
#endif
int V_134 ;
#ifndef F_106
char * V_246 ;
if ( F_107 ( L_32 , & V_246 ) )
return - V_247 ;
F_103 ( V_246 ) ;
#else
V_91 = F_1 ( V_248 ) ;
#endif
F_108 ( L_33 ) ;
#ifdef F_65
V_229 = F_109 ( NULL , L_34 ) ;
if ( ! V_229 ) {
F_48 ( L_35 ) ;
return - V_247 ;
}
V_232 = F_93 ( V_229 , L_36 , NULL ) ;
if ( V_232 == NULL ) {
F_48 ( L_37
L_38 ) ;
F_110 ( V_229 ) ;
return - V_247 ;
}
V_214 = F_111 ( V_232 ) * 13 ;
V_214 /= 8 ;
F_112 ( L_39 ,
V_214 ) ;
V_232 = F_93 ( V_229 , L_40 , NULL ) ;
if ( V_232 == NULL ) {
F_48 ( L_41
L_38 ) ;
F_110 ( V_229 ) ;
return - V_247 ;
}
V_215 = F_111 ( V_232 ) ;
F_112 ( L_42 ,
V_215 ) ;
F_110 ( V_229 ) ;
V_249 = F_113 ( V_214 ) ;
if ( ! V_249 ) {
F_48 ( L_43
L_44 , V_214 ) ;
return - V_112 ;
}
#endif
V_134 = F_114 ( & V_250 ) ;
if ( V_134 ) {
F_48 ( L_45 ) ;
#if F_83 ( F_65 )
F_115 ( V_249 ) ;
#endif
}
return V_134 ;
}
static void T_19 F_116 ( void )
{
F_117 ( & V_250 ) ;
#if F_83 ( F_65 )
F_115 ( V_249 ) ;
#endif
}
