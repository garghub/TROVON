static bool F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , unsigned int V_5 )
{
if ( ! V_3 )
return false ;
if ( F_2 ( V_2 , V_3 ) & ( 1 << ( V_4 + 1 ) ) )
if ( F_3 ( V_2 , V_3 , V_4 ) & V_5 )
return true ;
return false ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_12 = F_6 ( V_7 , & V_9 -> V_13 ) ;
if ( V_12 >= V_11 -> V_14 )
V_12 = 0 ;
if ( ! V_11 -> V_15 [ V_12 ] . V_16 && V_12 > 0 )
V_12 = 0 ;
return F_7 ( & V_11 -> V_15 [ V_12 ] , V_9 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_11 -> V_23 [ V_19 ] ;
return 0 ;
}
static bool F_9 ( struct V_1 * V_2 , int V_24 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_25 = V_11 -> V_26 [ V_11 -> V_27 [ V_24 ] ] ;
if ( V_11 -> V_28 && V_11 -> V_28 != V_25 ) {
F_10 ( V_2 , V_11 -> V_28 , 1 ) ;
V_11 -> V_28 = V_25 ;
F_11 ( V_2 , V_25 ,
V_11 -> V_29 , 0 ,
V_11 -> V_30 ) ;
return true ;
}
return false ;
}
static inline T_1 F_12 ( struct V_10 * V_11 , int V_31 )
{
return V_11 -> V_32 ?
V_11 -> V_32 [ V_31 ] : V_11 -> V_26 [ V_31 ] ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_31 , bool V_33 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
unsigned int V_12 ;
int V_36 , type , V_37 ;
T_1 V_3 ;
if ( ! V_11 -> V_15 )
return 0 ;
V_12 = V_19 >= V_11 -> V_14 ? 0 : V_19 ;
V_35 = & V_11 -> V_15 [ V_12 ] ;
if ( ! V_35 -> V_16 && V_12 > 0 )
V_35 = & V_11 -> V_15 [ 0 ] ;
if ( ! V_35 -> V_16 )
return 0 ;
if ( V_31 >= V_35 -> V_16 )
V_31 = V_35 -> V_16 - 1 ;
if ( V_11 -> V_23 [ V_19 ] == V_31 && ! V_33 )
return 0 ;
V_11 -> V_23 [ V_19 ] = V_31 ;
if ( V_11 -> V_38 ) {
F_14 ( V_2 , V_11 -> V_39 . V_40 [ 1 ] . V_41 , 0 ,
V_42 ,
V_11 -> V_23 [ V_19 ] ?
V_43 : V_44 ) ;
V_11 -> V_45 = ! V_11 -> V_23 [ V_19 ] ;
F_15 ( V_2 ) ;
}
if ( V_11 -> V_46 ) {
F_9 ( V_2 , V_31 ) ;
V_19 = V_11 -> V_27 [ V_31 ] ;
}
V_3 = F_12 ( V_11 , V_19 ) ;
V_37 = F_16 ( V_2 , V_3 , NULL ) ;
if ( V_37 <= 1 )
return 1 ;
type = F_17 ( F_2 ( V_2 , V_3 ) ) ;
if ( type == V_47 ) {
int V_48 = V_35 -> V_49 [ V_31 ] . V_50 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
unsigned int V_51 = ( V_36 == V_48 ) ? 0 : V_52 ;
F_18 ( V_2 , V_3 , V_53 , V_36 ,
V_52 , V_51 ) ;
}
} else {
F_19 ( V_2 , V_3 , 0 ,
V_54 ,
V_35 -> V_49 [ V_31 ] . V_50 ) ;
}
return 1 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
return F_13 ( V_2 , V_19 ,
V_18 -> V_20 . V_21 . V_22 [ 0 ] , false ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_3 ,
int V_55 )
{
unsigned int V_56 = V_57 ;
if ( V_55 == V_58 ) {
unsigned int V_59 ;
unsigned int V_60 ;
V_60 = F_22 ( V_2 , V_3 , 0 ,
V_61 , 0 ) ;
V_59 = F_23 ( V_2 , V_3 ) ;
V_59 = ( V_59 & V_62 ) >> V_63 ;
if ( ( V_59 & V_64 ) && V_60 != V_65 )
V_56 = V_43 ;
else if ( V_59 & V_66 )
V_56 = V_65 ;
else if ( V_59 & V_67 )
V_56 = V_68 ;
else if ( V_59 & V_69 )
V_56 = V_70 ;
}
F_14 ( V_2 , V_3 , 0 , V_42 , V_56 ) ;
}
static void F_24 ( struct V_10 * V_11 , const struct V_71 * V_72 )
{
if ( F_25 ( V_11 -> V_73 >= F_26 ( V_11 -> V_74 ) ) )
return;
V_11 -> V_74 [ V_11 -> V_73 ++ ] = V_72 ;
}
static void F_27 ( struct V_10 * V_11 , const struct V_75 * V_76 )
{
if ( F_25 ( V_11 -> V_77 >= F_26 ( V_11 -> V_78 ) ) )
return;
V_11 -> V_78 [ V_11 -> V_77 ++ ] = V_76 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 ;
if ( ! V_11 -> V_79 )
return;
F_14 ( V_2 , V_11 -> V_79 , 0 , V_80 ,
V_11 -> V_81 ) ;
V_56 = F_22 ( V_2 , V_11 -> V_79 , 0 ,
V_82 , 0 ) ;
F_14 ( V_2 , V_11 -> V_79 , 0 , V_80 ,
V_11 -> V_81 ) ;
F_14 ( V_2 , V_11 -> V_79 , 0 , V_83 ,
V_56 & ~ ( 1 << V_11 -> V_84 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_85 , unsigned int V_86 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_79 = V_3 ;
V_11 -> V_81 = V_85 ;
V_11 -> V_84 = V_86 ;
F_28 ( V_2 ) ;
}
static bool F_30 ( struct V_1 * V_2 , int V_87 , T_1 * V_88 )
{
int V_36 , V_89 = 0 ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
T_1 V_3 = V_88 [ V_36 ] ;
if ( ! V_3 )
break;
V_89 |= F_31 ( V_2 , V_3 ) ;
}
return V_89 ;
}
static void F_32 ( struct V_1 * V_2 , int V_87 , T_1 * V_88 ,
bool V_90 , bool V_91 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_92 = V_90 ? V_52 : 0 ;
unsigned int V_93 = V_90 ? 0 : ( V_91 ? V_44 : V_94 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
T_1 V_3 = V_88 [ V_36 ] ;
unsigned int V_56 ;
if ( ! V_3 )
break;
switch ( V_11 -> V_95 ) {
case V_96 :
if ( V_11 -> V_97 ) {
V_56 = F_22 ( V_2 , V_3 , 0 ,
V_61 , 0 ) ;
V_56 &= ~ V_44 ;
} else
V_56 = 0 ;
V_56 |= V_93 ;
F_14 ( V_2 , V_3 , 0 ,
V_42 ,
V_56 ) ;
break;
case V_98 :
F_18 ( V_2 , V_3 , V_99 , 0 ,
V_52 , V_92 ) ;
break;
case V_100 :
V_3 = V_11 -> V_101 [ V_36 ] ;
if ( ! V_3 )
break;
F_18 ( V_2 , V_3 , V_53 , 0 ,
V_52 , V_92 ) ;
F_18 ( V_2 , V_3 , V_53 , 1 ,
V_52 , V_92 ) ;
break;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_102 ;
if ( ! V_11 -> V_38 )
F_32 ( V_2 , F_26 ( V_11 -> V_39 . V_103 ) ,
V_11 -> V_39 . V_103 , V_11 -> V_104 , true ) ;
if ( ! V_11 -> V_45 )
V_102 = 0 ;
else
V_102 = V_11 -> V_105 | V_11 -> V_106 ;
V_102 |= V_11 -> V_104 ;
F_32 ( V_2 , F_26 ( V_11 -> V_39 . V_107 ) ,
V_11 -> V_39 . V_107 , V_102 , false ) ;
if ( V_11 -> V_39 . V_108 [ 0 ] == V_11 -> V_39 . V_103 [ 0 ] ||
V_11 -> V_39 . V_108 [ 0 ] == V_11 -> V_39 . V_107 [ 0 ] )
return;
if ( ! V_11 -> V_109 )
V_102 = 0 ;
else
V_102 = V_11 -> V_105 ;
V_102 |= V_11 -> V_104 ;
F_32 ( V_2 , F_26 ( V_11 -> V_39 . V_108 ) ,
V_11 -> V_39 . V_108 , V_102 , false ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_110 )
V_11 -> V_110 ( V_2 ) ;
else
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_105 =
F_30 ( V_2 , F_26 ( V_11 -> V_39 . V_103 ) ,
V_11 -> V_39 . V_103 ) ;
if ( ! V_11 -> V_111 || ( ! V_11 -> V_45 && ! V_11 -> V_109 ) )
return;
F_15 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_39 . V_108 [ 0 ] == V_11 -> V_39 . V_103 [ 0 ] )
return;
V_11 -> V_106 =
F_30 ( V_2 , F_26 ( V_11 -> V_39 . V_108 ) ,
V_11 -> V_39 . V_108 ) ;
if ( ! V_11 -> V_45 || ! V_11 -> V_112 )
return;
F_15 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_88 = V_11 -> V_113 ;
if ( ! V_11 -> V_114 || ! V_11 -> V_115 )
return;
if ( F_25 ( ! V_11 -> V_26 ) )
return;
if ( F_25 ( V_11 -> V_116 < 0 || V_11 -> V_117 < 0 ) )
return;
if ( F_31 ( V_2 , V_88 [ V_11 -> V_117 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_117 , false ) ;
else if ( V_11 -> V_118 >= 0 &&
F_31 ( V_2 , V_88 [ V_11 -> V_118 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_118 , false ) ;
else
F_13 ( V_2 , 0 , V_11 -> V_116 , false ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_119 )
{
switch ( V_119 ) {
case V_120 :
F_34 ( V_2 ) ;
break;
case V_121 :
F_35 ( V_2 ) ;
break;
case V_122 :
F_36 ( V_2 ) ;
break;
}
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_56 ;
struct V_6 * V_123 ;
struct V_17 * V_124 ;
V_123 = F_40 ( V_2 , L_1 ) ;
if ( ! V_123 )
return;
V_124 = F_41 ( sizeof( * V_124 ) , V_125 ) ;
if ( ! V_124 )
return;
V_56 = F_22 ( V_2 , V_3 , 0 ,
V_126 , 0 ) ;
V_56 &= V_127 ;
V_124 -> V_20 . integer . V_20 [ 0 ] = V_56 ;
V_124 -> V_20 . integer . V_20 [ 1 ] = V_56 ;
V_123 -> V_128 ( V_123 , V_124 ) ;
F_42 ( V_124 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_129 )
{
int V_119 ;
if ( V_2 -> V_130 == 0x10ec0880 )
V_129 >>= 28 ;
else
V_129 >>= 26 ;
V_119 = F_44 ( V_2 , V_129 ) ;
if ( V_119 == V_131 ) {
struct V_132 * V_133 ;
V_133 = F_45 ( V_2 , V_129 ) ;
if ( V_133 )
F_39 ( V_2 , V_133 -> V_3 ) ;
return;
}
F_37 ( V_2 , V_119 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned int V_134 ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 0 ) ;
V_134 = F_22 ( V_2 , 0x20 , 0 , V_82 , 0 ) ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
if ( ( V_134 & 0xf0 ) == 0x20 )
F_22 ( V_2 , 0x20 , 0 ,
V_83 , 0x830 ) ;
else
F_22 ( V_2 , 0x20 , 0 ,
V_83 , 0x3030 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_134 ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
V_134 = F_22 ( V_2 , 0x20 , 0 , V_82 , 0 ) ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
F_14 ( V_2 , 0x20 , 0 , V_83 , V_134 | 0x2010 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_3 , int V_102 )
{
if ( F_17 ( F_2 ( V_2 , V_3 ) ) != V_135 )
return;
if ( F_23 ( V_2 , V_3 ) & V_136 )
F_14 ( V_2 , V_3 , 0 , V_137 ,
V_102 ? 2 : 0 ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_102 )
{
static T_1 V_88 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_138 ;
for ( V_138 = V_88 ; * V_138 ; V_138 ++ )
F_49 ( V_2 , * V_138 , V_102 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_50 ( V_2 , false ) ;
F_52 ( 200 ) ;
}
static void F_53 ( struct V_1 * V_2 , int type )
{
unsigned int V_134 ;
F_50 ( V_2 , true ) ;
switch ( type ) {
case V_139 :
F_54 ( V_2 , V_140 ) ;
break;
case V_141 :
F_54 ( V_2 , V_142 ) ;
break;
case V_143 :
F_54 ( V_2 , V_144 ) ;
break;
case V_145 :
switch ( V_2 -> V_130 ) {
case 0x10ec0260 :
F_14 ( V_2 , 0x1a , 0 ,
V_80 , 7 ) ;
V_134 = F_22 ( V_2 , 0x1a , 0 ,
V_82 , 0 ) ;
F_14 ( V_2 , 0x1a , 0 ,
V_80 , 7 ) ;
F_14 ( V_2 , 0x1a , 0 ,
V_83 ,
V_134 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_48 ( V_2 ) ;
break;
case 0x10ec0888 :
F_47 ( V_2 ) ;
break;
#if 0
case 0x10ec0267:
case 0x10ec0268:
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x3000);
break;
#endif
}
break;
}
}
static int F_55 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_146 [] = {
L_2 , L_3
} ;
static const char * const V_147 [] = {
L_2 , L_4 , L_5
} ;
const char * const * V_148 ;
V_9 -> type = V_149 ;
V_9 -> V_150 = 1 ;
if ( V_11 -> V_151 && V_11 -> V_152 ) {
V_9 -> V_20 . V_21 . V_49 = 3 ;
V_148 = V_147 ;
} else {
V_9 -> V_20 . V_21 . V_49 = 2 ;
V_148 = V_146 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_49 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_49 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_153 ,
V_148 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 = 0 ;
if ( V_11 -> V_45 )
V_56 ++ ;
if ( V_11 -> V_109 )
V_56 ++ ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_56 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_18 -> V_20 . V_21 . V_22 [ 0 ] ) {
case 0 :
if ( ! V_11 -> V_45 && ! V_11 -> V_109 )
return 0 ;
V_11 -> V_45 = 0 ;
V_11 -> V_109 = 0 ;
break;
case 1 :
if ( V_11 -> V_151 ) {
if ( ! V_11 -> V_109 && V_11 -> V_45 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_109 = 0 ;
} else if ( V_11 -> V_152 ) {
if ( V_11 -> V_109 )
return 0 ;
V_11 -> V_109 = 1 ;
} else
return - V_154 ;
break;
case 2 :
if ( ! V_11 -> V_152 || ! V_11 -> V_151 )
return - V_154 ;
if ( V_11 -> V_45 && V_11 -> V_109 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_109 = 1 ;
break;
default:
return - V_154 ;
}
F_15 ( V_2 ) ;
return 1 ;
}
static struct V_71 * F_58 ( struct V_10 * V_11 )
{
F_59 ( & V_11 -> V_155 , sizeof( struct V_71 ) , 32 ) ;
return F_60 ( & V_11 -> V_155 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_71 * V_156 ;
V_156 = F_58 ( V_11 ) ;
if ( ! V_156 )
return - V_157 ;
* V_156 = V_158 ;
V_156 -> V_153 = F_62 ( L_6 , V_125 ) ;
if ( ! V_156 -> V_153 )
return - V_157 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_89 = 0 ;
int V_36 ;
if ( V_160 -> V_103 [ 0 ] )
V_89 ++ ;
if ( V_160 -> V_108 [ 0 ] )
V_89 ++ ;
if ( V_160 -> V_107 [ 0 ] )
V_89 ++ ;
if ( V_89 < 2 )
return;
if ( ! V_160 -> V_107 [ 0 ] &&
V_160 -> V_161 == V_162 ) {
memcpy ( V_160 -> V_107 , V_160 -> V_108 ,
sizeof( V_160 -> V_107 ) ) ;
V_160 -> V_163 = V_160 -> V_164 ;
}
if ( ! V_160 -> V_103 [ 0 ] &&
V_160 -> V_161 == V_165 ) {
memcpy ( V_160 -> V_103 , V_160 -> V_108 ,
sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_166 = V_160 -> V_164 ;
}
V_11 -> V_95 = V_96 ;
for ( V_36 = 0 ; V_36 < V_160 -> V_166 ; V_36 ++ ) {
T_1 V_3 = V_160 -> V_103 [ V_36 ] ;
if ( ! F_64 ( V_2 , V_3 ) )
continue;
F_65 ( L_7 ,
V_3 ) ;
F_66 ( V_2 , V_3 , V_120 ) ;
V_11 -> V_111 = 1 ;
}
if ( V_160 -> V_161 == V_167 && V_160 -> V_164 ) {
if ( V_160 -> V_163 )
for ( V_36 = 0 ; V_36 < V_160 -> V_164 ; V_36 ++ ) {
T_1 V_3 = V_160 -> V_108 [ V_36 ] ;
if ( ! F_64 ( V_2 , V_3 ) )
continue;
F_65 ( L_8
L_9 , V_3 ) ;
F_66 ( V_2 , V_3 ,
V_121 ) ;
V_11 -> V_112 = 1 ;
}
V_11 -> V_152 = V_11 -> V_111 ;
}
V_11 -> V_151 = V_160 -> V_163 &&
( V_11 -> V_111 || V_11 -> V_112 ) ;
V_11 -> V_109 = V_11 -> V_152 ;
V_11 -> V_45 = V_11 -> V_151 ;
if ( V_11 -> V_151 || V_11 -> V_152 ) {
F_61 ( V_2 ) ;
V_11 -> V_168 = F_43 ;
}
}
static int F_67 ( T_1 V_3 , const T_1 * V_169 , int V_170 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_170 ; V_36 ++ )
if ( V_169 [ V_36 ] == V_3 )
return V_36 ;
return - 1 ;
}
static bool F_68 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 = & V_11 -> V_171 [ 0 ] ;
int V_36 , V_172 , V_31 ;
T_1 V_173 , V_41 ;
if ( V_35 != V_11 -> V_15 )
return false ;
for ( V_172 = 0 ; V_172 < V_11 -> V_174 ; V_172 ++ ) {
V_173 = V_11 -> V_175 [ V_172 ] ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_41 = V_11 -> V_113 [ V_36 ] ;
if ( ! V_41 )
return false ;
if ( F_69 ( V_2 , V_173 , V_41 ) < 0 )
break;
}
if ( V_36 >= V_35 -> V_16 )
return true ;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_41 = V_11 -> V_113 [ V_36 ] ;
for ( V_172 = 0 ; V_172 < V_11 -> V_174 ; V_172 ++ ) {
V_173 = V_11 -> V_175 [ V_172 ] ;
V_31 = F_69 ( V_2 , V_173 , V_41 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_49 [ V_36 ] . V_50 = V_31 ;
V_11 -> V_27 [ V_36 ] = V_172 ;
break;
}
}
}
F_65 ( L_10 ) ;
V_11 -> V_46 = 1 ;
return true ;
}
static bool F_70 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
if ( ! V_11 -> V_114 )
return false ;
if ( V_11 -> V_115 )
return true ;
if ( ! F_68 ( V_2 ) ) {
V_11 -> V_114 = 0 ;
return false ;
}
V_35 = V_11 -> V_15 ;
V_11 -> V_117 = F_67 ( V_11 -> V_176 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
V_11 -> V_116 = F_67 ( V_11 -> V_177 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
V_11 -> V_118 = F_67 ( V_11 -> V_178 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
if ( V_11 -> V_117 < 0 || V_11 -> V_116 < 0 ) {
V_11 -> V_114 = 0 ;
return false ;
}
F_66 ( V_2 , V_11 -> V_176 , V_122 ) ;
if ( V_11 -> V_178 )
F_66 ( V_2 , V_11 -> V_178 ,
V_122 ) ;
V_11 -> V_115 = 1 ;
V_11 -> V_114 = 1 ;
return true ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
T_1 V_179 , V_180 , V_181 ;
int V_36 ;
if ( V_11 -> V_38 )
return;
V_11 -> V_117 = V_11 -> V_116 = V_11 -> V_118 = - 1 ;
V_179 = V_180 = V_181 = 0 ;
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
T_1 V_3 = V_160 -> V_40 [ V_36 ] . V_41 ;
unsigned int V_183 ;
V_183 = F_72 ( V_2 , V_3 ) ;
switch ( F_73 ( V_183 ) ) {
case V_184 :
if ( V_179 )
return;
if ( V_160 -> V_40 [ V_36 ] . type != V_58 )
return;
V_179 = V_3 ;
break;
case V_185 :
return;
case V_186 :
if ( V_181 )
return;
if ( V_160 -> V_40 [ V_36 ] . type > V_187 )
return;
V_181 = V_3 ;
break;
default:
if ( V_180 )
return;
if ( V_160 -> V_40 [ V_36 ] . type != V_58 )
return;
V_180 = V_3 ;
break;
}
}
if ( ! V_180 && V_181 ) {
V_180 = V_181 ;
V_181 = 0 ;
}
if ( ! V_180 || ! V_179 )
return;
if ( ! F_64 ( V_2 , V_180 ) )
return;
if ( V_181 && ! F_64 ( V_2 , V_181 ) )
return;
V_11 -> V_176 = V_180 ;
V_11 -> V_177 = V_179 ;
V_11 -> V_178 = V_181 ;
V_11 -> V_114 = 1 ;
if ( ! F_70 ( V_2 ) )
return;
F_65 ( L_11 ,
V_180 , V_179 , V_181 ) ;
V_11 -> V_168 = F_43 ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
F_71 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
unsigned int V_188 , V_134 , V_36 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_189 . V_190 = 1 ;
if ( V_11 -> V_189 . V_191 ) {
V_188 = V_11 -> V_189 . V_192 ;
if ( V_188 == V_193 )
return - 1 ;
goto V_194;
}
V_188 = V_2 -> V_195 & 0xffff ;
if ( V_188 != V_2 -> V_196 -> V_197 -> V_198 && ( V_188 & 1 ) )
goto V_194;
V_3 = 0x1d ;
if ( V_2 -> V_130 == 0x10ec0260 )
V_3 = 0x17 ;
V_188 = F_72 ( V_2 , V_3 ) ;
if ( ! ( V_188 & 1 ) ) {
F_76 ( V_199 L_12 ,
V_2 -> V_200 , V_188 ) ;
return - 1 ;
}
V_134 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_188 >> V_36 ) & 1 )
V_134 ++ ;
}
if ( ( ( V_188 >> 16 ) & 0xf ) != V_134 )
return - 1 ;
V_11 -> V_189 . V_201 = V_188 >> 30 ;
V_11 -> V_189 . V_190 = ( V_188 & 0x100000 ) >> 20 ;
V_11 -> V_189 . V_202 = ( V_188 >> 16 ) & 0xf ;
V_11 -> V_189 . V_203 = V_188 >> 8 ;
V_194:
V_11 -> V_189 . V_192 = V_188 ;
V_11 -> V_189 . V_204 = ( V_188 & 0x38 ) >> 3 ;
V_11 -> V_189 . V_205 = ( V_188 & 0x4 ) >> 2 ;
V_11 -> V_189 . V_206 = ( V_188 & 0x2 ) >> 1 ;
V_11 -> V_189 . V_207 = V_188 & 0x1 ;
F_77 ( L_13 ,
V_3 , V_11 -> V_189 . V_192 ) ;
F_77 ( L_14 ,
V_11 -> V_189 . V_201 ) ;
F_77 ( L_15 , V_11 -> V_189 . V_190 ) ;
F_77 ( L_16 , V_11 -> V_189 . V_202 ) ;
F_77 ( L_17 , V_11 -> V_189 . V_203 ) ;
F_77 ( L_18 , V_11 -> V_189 . V_204 ) ;
F_77 ( L_19 , V_11 -> V_189 . V_205 ) ;
F_77 ( L_20 , V_11 -> V_189 . V_206 ) ;
F_77 ( L_21 , V_11 -> V_189 . V_207 ) ;
return 0 ;
}
static bool F_78 ( T_1 V_3 , const T_1 * V_169 , int V_170 )
{
return F_67 ( V_3 , V_169 , V_170 ) >= 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
T_1 V_208 , T_1 V_209 ,
T_1 V_210 , T_1 V_211 )
{
unsigned int V_188 , V_134 , V_36 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_189 . V_191 ) {
V_188 = V_11 -> V_189 . V_192 ;
if ( V_188 == V_193 )
return 0 ;
goto V_194;
}
V_188 = V_2 -> V_195 & 0xffff ;
if ( ( V_188 != V_2 -> V_196 -> V_197 -> V_198 ) && ( V_188 & 1 ) )
goto V_194;
V_3 = 0x1d ;
if ( V_2 -> V_130 == 0x10ec0260 )
V_3 = 0x17 ;
V_188 = F_72 ( V_2 , V_3 ) ;
F_77 ( L_22
L_23 ,
V_188 , V_3 ) ;
if ( ! ( V_188 & 1 ) )
return 0 ;
if ( ( V_188 >> 30 ) != 1 )
return 0 ;
V_134 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_188 >> V_36 ) & 1 )
V_134 ++ ;
}
if ( ( ( V_188 >> 16 ) & 0xf ) != V_134 )
return 0 ;
V_194:
F_77 ( L_24 ,
V_188 & 0xffff , V_2 -> V_130 ) ;
V_134 = ( V_188 & 0x38 ) >> 3 ;
switch ( V_134 ) {
case 1 :
V_11 -> V_212 = V_139 ;
break;
case 3 :
V_11 -> V_212 = V_141 ;
break;
case 7 :
V_11 -> V_212 = V_143 ;
break;
case 5 :
default:
V_11 -> V_212 = V_145 ;
break;
}
if ( ! ( V_188 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_39 . V_103 [ 0 ] &&
! ( V_11 -> V_39 . V_108 [ 0 ] &&
V_11 -> V_39 . V_161 == V_165 ) ) {
T_1 V_3 ;
V_134 = ( V_188 >> 11 ) & 0x3 ;
if ( V_134 == 0 )
V_3 = V_208 ;
else if ( V_134 == 1 )
V_3 = V_209 ;
else if ( V_134 == 2 )
V_3 = V_210 ;
else if ( V_134 == 3 )
V_3 = V_211 ;
else
return 1 ;
if ( F_78 ( V_3 , V_11 -> V_39 . V_108 ,
V_11 -> V_39 . V_164 ) )
return 1 ;
V_11 -> V_39 . V_103 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_80 ( struct V_1 * V_2 , const T_1 * V_213 )
{
if ( ! F_79 ( V_2 , V_213 [ 0 ] , V_213 [ 1 ] , V_213 [ 2 ] , V_213 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_77 ( L_25
L_26 ) ;
V_11 -> V_212 = V_145 ;
}
}
static void F_81 ( struct V_1 * V_2 ,
const struct V_214 * V_160 )
{
for (; V_160 -> V_3 ; V_160 ++ )
F_82 ( V_2 , V_160 -> V_3 , V_160 -> V_56 ) ;
}
static void F_83 ( struct V_1 * V_2 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = V_11 -> V_215 ;
#ifdef F_84
const char * V_216 = V_11 -> V_217 ;
#endif
int V_218 = 0 ;
if ( ! V_11 -> V_219 )
return;
while ( V_13 >= 0 ) {
const struct V_220 * V_221 = V_11 -> V_219 + V_13 ;
const struct V_214 * V_160 ;
switch ( V_221 -> type ) {
case V_222 :
if ( V_119 != V_223 || ! V_221 -> V_51 . V_224 )
break;
F_65 ( V_199 L_27
L_28 ,
V_2 -> V_200 , V_216 ) ;
V_11 -> V_189 . V_192 = V_221 -> V_51 . V_224 ;
V_11 -> V_189 . V_191 = 1 ;
break;
case V_225 :
V_160 = V_221 -> V_51 . V_88 ;
if ( V_119 != V_223 || ! V_160 )
break;
F_65 ( V_199 L_27
L_29 ,
V_2 -> V_200 , V_216 ) ;
F_81 ( V_2 , V_160 ) ;
break;
case V_226 :
if ( V_119 != V_227 || ! V_221 -> V_51 . V_228 )
break;
F_65 ( V_199 L_27
L_30 ,
V_2 -> V_200 , V_216 ) ;
F_27 ( V_2 -> V_11 , V_221 -> V_51 . V_228 ) ;
break;
case V_229 :
if ( ! V_221 -> V_51 . V_230 )
break;
F_65 ( V_199 L_27
L_31 ,
V_2 -> V_200 , V_216 ) ;
V_221 -> V_51 . V_230 ( V_2 , V_221 , V_119 ) ;
break;
default:
F_85 ( V_231 L_27
L_32 ,
V_2 -> V_200 , V_221 -> type ) ;
break;
}
if ( ! V_221 -> V_232 )
break;
if ( ++ V_218 > 10 )
break;
V_13 = V_221 -> V_233 ;
}
}
static void F_86 ( struct V_1 * V_2 ,
const struct V_234 * V_235 ,
const struct V_236 * V_237 ,
const struct V_220 * V_238 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_236 * V_239 ;
int V_13 = - 1 ;
const char * V_153 = NULL ;
if ( V_2 -> V_216 && ! strcmp ( V_2 -> V_216 , L_33 ) ) {
V_11 -> V_219 = NULL ;
V_11 -> V_215 = - 1 ;
return;
}
if ( V_2 -> V_216 && V_235 ) {
while ( V_235 -> V_153 ) {
if ( ! strcmp ( V_2 -> V_216 , V_235 -> V_153 ) ) {
V_13 = V_235 -> V_13 ;
V_153 = V_235 -> V_153 ;
break;
}
V_235 ++ ;
}
}
if ( V_13 < 0 ) {
V_239 = F_87 ( V_2 -> V_196 -> V_197 , V_237 ) ;
if ( V_239 ) {
V_13 = V_239 -> V_20 ;
#ifdef F_84
V_153 = V_239 -> V_153 ;
#endif
}
}
if ( V_13 < 0 ) {
for ( V_239 = V_237 ; V_239 -> V_240 ; V_239 ++ ) {
unsigned int V_241 =
V_239 -> V_242 | ( V_239 -> V_240 << 16 ) ;
if ( V_241 == V_2 -> V_195 ) {
V_13 = V_239 -> V_20 ;
#ifdef F_84
V_153 = V_239 -> V_153 ;
#endif
break;
}
}
}
V_11 -> V_215 = V_13 ;
if ( V_13 >= 0 ) {
V_11 -> V_219 = V_238 ;
V_11 -> V_217 = V_153 ;
}
}
static int F_88 ( struct V_1 * V_2 ,
unsigned int V_85 )
{
unsigned int V_56 ;
F_14 ( V_2 , 0x20 , 0 , V_80 ,
V_85 ) ;
V_56 = F_22 ( V_2 , 0x20 , 0 ,
V_82 , 0 ) ;
return V_56 ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_85 ,
unsigned int V_243 )
{
F_14 ( V_2 , 0x20 , 0 , V_80 ,
V_85 ) ;
F_14 ( V_2 , 0x20 , 0 , V_83 ,
V_243 ) ;
}
static unsigned int F_90 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_244 )
V_11 -> V_244 = F_88 ( V_2 , 0 ) ;
return V_11 -> V_244 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_41 , V_245 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_246 ; V_36 ++ ) {
V_41 = V_11 -> V_39 . V_247 [ V_36 ] ;
if ( ! V_41 )
continue;
F_14 ( V_2 , V_41 , 0 ,
V_42 , V_94 ) ;
if ( ! V_36 )
V_245 = V_11 -> V_248 . V_249 ;
else
V_245 = V_11 -> V_250 [ V_36 - 1 ] ;
if ( ! V_245 || ! ( F_2 ( V_2 , V_245 ) & V_251 ) )
continue;
F_14 ( V_2 , V_245 , 0 ,
V_252 ,
V_253 ) ;
}
V_41 = V_11 -> V_39 . V_254 ;
if ( V_41 )
F_14 ( V_2 , V_41 , 0 ,
V_42 ,
V_57 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_255 , V_170 ;
T_1 V_256 ;
V_170 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_246 ; V_36 ++ ) {
T_1 V_257 [ 4 ] ;
V_255 = F_93 ( V_2 ,
V_11 -> V_39 . V_247 [ V_36 ] ,
V_257 , F_26 ( V_257 ) ) ;
if ( V_255 <= 0 )
continue;
V_256 = V_257 [ 0 ] ;
if ( ! V_170 ) {
V_11 -> V_248 . V_249 = V_256 ;
V_11 -> V_258 = V_11 -> V_39 . V_258 [ 0 ] ;
} else {
V_11 -> V_248 . V_250 = V_11 -> V_250 ;
if ( V_170 >= F_26 ( V_11 -> V_250 ) - 1 )
break;
V_11 -> V_250 [ V_170 - 1 ] = V_256 ;
}
V_170 ++ ;
}
if ( V_11 -> V_39 . V_254 ) {
V_256 = V_2 -> V_259 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_260 ; V_36 ++ , V_256 ++ ) {
unsigned int V_261 = F_2 ( V_2 , V_256 ) ;
if ( F_17 ( V_261 ) != V_262 )
continue;
if ( ! ( V_261 & V_263 ) )
continue;
if ( ! ( V_261 & V_264 ) )
continue;
V_255 = F_69 ( V_2 , V_256 ,
V_11 -> V_39 . V_254 ) ;
if ( V_255 >= 0 ) {
V_11 -> V_265 = V_256 ;
break;
}
}
}
}
static int F_94 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_56 ;
int V_255 ;
F_95 ( & V_2 -> V_266 ) ;
if ( V_11 -> V_267 )
V_56 = F_96 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_99 ) ;
else
V_56 = F_96 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_268 = V_56 ;
V_255 = F_97 ( V_7 , V_9 ) ;
F_98 ( & V_2 -> V_266 ) ;
return V_255 ;
}
static int F_99 ( struct V_6 * V_7 , int V_269 ,
unsigned int V_270 , unsigned int T_2 * V_271 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_56 ;
int V_255 ;
F_95 ( & V_2 -> V_266 ) ;
if ( V_11 -> V_267 )
V_56 = F_96 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_99 ) ;
else
V_56 = F_96 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_268 = V_56 ;
V_255 = F_100 ( V_7 , V_269 , V_270 , V_271 ) ;
F_98 ( & V_2 -> V_266 ) ;
return V_255 ;
}
static int F_101 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_230 , bool V_272 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_255 = 0 ;
F_95 ( & V_2 -> V_266 ) ;
if ( V_272 && V_11 -> V_46 ) {
for ( V_36 = 0 ; V_36 < V_11 -> V_174 ; V_36 ++ ) {
V_7 -> V_268 =
F_96 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_255 = V_230 ( V_7 , V_18 ) ;
if ( V_255 < 0 )
goto error;
}
} else {
V_36 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_267 )
V_7 -> V_268 =
F_96 ( V_11 -> V_32 [ V_36 ] ,
3 , 0 , V_99 ) ;
else
V_7 -> V_268 =
F_96 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_255 = V_230 ( V_7 , V_18 ) ;
}
error:
F_98 ( & V_2 -> V_266 ) ;
return V_255 ;
}
static int F_102 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_101 ( V_7 , V_18 ,
V_273 , false ) ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_101 ( V_7 , V_18 ,
V_274 , true ) ;
}
static int F_104 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_101 ( V_7 , V_18 ,
V_275 , false ) ;
}
static int F_105 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_101 ( V_7 , V_18 ,
V_276 , true ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_123 = NULL ;
const struct V_71 * V_156 ;
int V_36 , V_277 , V_255 ;
unsigned int V_278 ;
T_1 V_3 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
V_255 = F_107 ( V_2 , V_11 -> V_74 [ V_36 ] ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( V_11 -> V_279 ) {
V_255 = F_107 ( V_2 , V_11 -> V_279 ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( V_11 -> V_248 . V_249 ) {
V_255 = F_108 ( V_2 ,
V_11 -> V_248 . V_249 ,
V_11 -> V_248 . V_249 ) ;
if ( V_255 < 0 )
return V_255 ;
if ( ! V_11 -> V_280 ) {
V_255 = F_109 ( V_2 ,
& V_11 -> V_248 ) ;
if ( V_255 < 0 )
return V_255 ;
V_11 -> V_248 . V_281 = 1 ;
}
}
if ( V_11 -> V_265 ) {
V_255 = F_110 ( V_2 , V_11 -> V_265 ) ;
if ( V_255 < 0 )
return V_255 ;
}
#ifdef F_111
if ( V_11 -> V_282 ) {
const struct V_71 * V_156 ;
for ( V_156 = V_283 ; V_156 -> V_153 ; V_156 ++ ) {
struct V_6 * V_123 ;
V_123 = F_112 ( V_156 , V_2 ) ;
if ( ! V_123 )
return - V_157 ;
V_123 -> V_268 = V_11 -> V_282 ;
V_255 = F_113 ( V_2 , 0 , V_123 ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
#endif
if ( ! V_11 -> V_280 &&
! F_40 ( V_2 , L_1 ) ) {
unsigned int V_284 [ 4 ] ;
F_114 ( V_2 , V_11 -> V_285 ,
V_99 , V_284 ) ;
V_255 = F_115 ( V_2 , L_1 ,
V_284 , V_286 ,
L_34 ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( ! V_11 -> V_280 &&
! F_40 ( V_2 , L_35 ) ) {
V_255 = F_116 ( V_2 , L_35 ,
NULL , V_286 ,
L_36 ,
true , & V_11 -> V_287 . V_288 ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_123 = F_40 ( V_2 , L_37 ) ;
if ( ! V_123 )
V_123 = F_40 ( V_2 , L_38 ) ;
for ( V_36 = 0 ; V_123 && V_36 < V_123 -> V_150 ; V_36 ++ ) {
V_255 = F_117 ( V_2 , V_123 , V_36 ,
F_12 ( V_11 , V_36 ) ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
if ( V_11 -> V_279 && V_11 -> V_26 ) {
const char * V_289 = V_123 ? V_123 -> V_13 . V_153 : NULL ;
for ( V_156 = V_11 -> V_279 ; V_156 -> V_153 ; V_156 ++ ) {
if ( V_289 && strcmp ( V_156 -> V_153 , V_289 ) == 0 )
continue;
V_123 = F_40 ( V_2 , V_156 -> V_153 ) ;
for ( V_36 = 0 ; V_123 && V_36 < V_123 -> V_150 ; V_36 ++ ) {
V_255 = F_117 ( V_2 , V_123 , V_36 ,
V_11 -> V_26 [ V_36 ] ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
}
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
for ( V_156 = V_11 -> V_74 [ V_36 ] ; V_156 -> V_153 ; V_156 ++ ) {
if ( V_156 -> V_290 != V_291 )
continue;
V_123 = F_40 ( V_2 , V_156 -> V_153 ) ;
if ( V_123 == NULL )
continue;
V_278 = V_156 -> V_242 ;
for ( V_277 = 0 ; V_277 < 4 ; V_277 ++ , V_278 >>= 8 ) {
V_3 = V_278 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_278 & 0xc0 ) {
case V_292 :
V_3 = V_11 -> V_39 . V_107 [ V_3 ] ;
break;
case V_293 :
V_3 = V_11 -> V_39 . V_108 [ V_3 ] ;
break;
case V_294 :
V_3 = V_11 -> V_39 . V_103 [ V_3 ] ;
break;
default:
continue;
}
V_255 = F_117 ( V_2 , V_123 , 0 , V_3 ) ;
if ( V_255 < 0 )
return V_255 ;
}
V_278 = V_156 -> V_268 ;
for ( V_277 = 0 ; V_277 < 4 ; V_277 ++ , V_278 >>= 8 ) {
V_3 = V_278 & 0xff ;
if ( V_3 == 0 )
continue;
V_255 = F_117 ( V_2 , V_123 , 0 , V_3 ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
}
F_118 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_255 = F_106 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_120 ( V_2 , & V_11 -> V_39 ) ;
if ( V_255 < 0 )
return V_255 ;
F_83 ( V_2 , V_295 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_36 ;
if ( V_11 -> V_296 )
V_11 -> V_296 ( V_2 ) ;
F_28 ( V_2 ) ;
F_53 ( V_2 , V_11 -> V_212 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_77 ; V_36 ++ )
F_54 ( V_2 , V_11 -> V_78 [ V_36 ] ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_83 ( V_2 , V_297 ) ;
F_38 ( V_2 ) ;
F_124 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , unsigned int V_129 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_168 )
V_11 -> V_168 ( V_2 , V_129 ) ;
}
static int F_126 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_127 ( V_2 , & V_11 -> V_298 , V_3 ) ;
}
static int F_128 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_129 ( V_2 , & V_11 -> V_248 , V_302 ,
V_300 ) ;
}
static int F_130 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
unsigned int V_303 ,
unsigned int V_304 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_131 ( V_2 , & V_11 -> V_248 ,
V_303 , V_304 , V_302 ) ;
}
static int F_132 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_133 ( V_2 , & V_11 -> V_248 ) ;
}
static int F_134 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_135 ( V_2 , & V_11 -> V_248 ) ;
}
static int F_136 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
unsigned int V_303 ,
unsigned int V_304 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_137 ( V_2 , & V_11 -> V_248 ,
V_303 , V_304 , V_302 ) ;
}
static int F_138 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_139 ( V_2 , & V_11 -> V_248 ) ;
}
static int F_140 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_141 ( V_2 , & V_11 -> V_248 ) ;
}
static int F_142 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
unsigned int V_303 ,
unsigned int V_304 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_302 -> V_305 + 1 ] ,
V_303 , 0 , V_304 ) ;
return 0 ;
}
static int F_143 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_144 ( V_2 ,
V_11 -> V_26 [ V_302 -> V_305 + 1 ] ) ;
return 0 ;
}
static int F_145 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
unsigned int V_303 ,
unsigned int V_304 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_303 ;
V_11 -> V_30 = V_304 ;
F_11 ( V_2 , V_11 -> V_28 , V_303 , 0 , V_304 ) ;
return 0 ;
}
static int F_146 ( struct V_299 * V_300 ,
struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_144 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_306 * V_307 = V_11 -> V_308 ;
const struct V_299 * V_138 ;
bool V_309 ;
int V_36 ;
V_2 -> V_310 = 1 ;
V_2 -> V_311 = V_307 ;
if ( V_11 -> V_280 )
goto V_312;
snprintf ( V_11 -> V_313 , sizeof( V_11 -> V_313 ) ,
L_39 , V_2 -> V_200 ) ;
V_307 -> V_153 = V_11 -> V_313 ;
if ( V_11 -> V_248 . V_314 > 0 ) {
V_138 = V_11 -> V_315 ;
if ( ! V_138 )
V_138 = & V_316 ;
V_307 -> V_317 [ V_318 ] = * V_138 ;
V_307 -> V_317 [ V_318 ] . V_3 = V_11 -> V_248 . V_319 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_138 = V_11 -> V_320 ;
if ( ! V_138 ) {
if ( V_11 -> V_46 )
V_138 = & V_321 ;
else
V_138 = & V_322 ;
}
V_307 -> V_317 [ V_323 ] = * V_138 ;
V_307 -> V_317 [ V_323 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_324 ) {
V_307 -> V_317 [ V_318 ] . V_325 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_326 ; V_36 ++ ) {
if ( V_11 -> V_324 [ V_36 ] . V_327 > V_307 -> V_317 [ V_318 ] . V_325 ) {
V_307 -> V_317 [ V_318 ] . V_325 = V_11 -> V_324 [ V_36 ] . V_327 ;
}
}
}
V_312:
if ( V_11 -> V_248 . V_249 || V_11 -> V_265 ) {
snprintf ( V_11 -> V_328 ,
sizeof( V_11 -> V_328 ) ,
L_40 , V_2 -> V_200 ) ;
V_2 -> V_310 = 2 ;
V_2 -> V_250 = V_11 -> V_248 . V_250 ;
V_307 = V_11 -> V_308 + 1 ;
V_307 -> V_153 = V_11 -> V_328 ;
if ( V_11 -> V_258 )
V_307 -> V_329 = V_11 -> V_258 ;
else
V_307 -> V_329 = V_330 ;
if ( V_11 -> V_248 . V_249 ) {
V_138 = V_11 -> V_331 ;
if ( ! V_138 )
V_138 = & V_332 ;
V_307 -> V_317 [ V_318 ] = * V_138 ;
V_307 -> V_317 [ V_318 ] . V_3 = V_11 -> V_248 . V_249 ;
}
if ( V_11 -> V_265 ) {
V_138 = V_11 -> V_333 ;
if ( ! V_138 )
V_138 = & V_334 ;
V_307 -> V_317 [ V_323 ] = * V_138 ;
V_307 -> V_317 [ V_323 ] . V_3 = V_11 -> V_265 ;
}
V_2 -> V_335 = 1 ;
}
if ( V_11 -> V_280 )
return 0 ;
V_309 = ( V_11 -> V_174 > 1 ) &&
! V_11 -> V_46 && ! V_11 -> V_114 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_336 || V_309 ) {
V_2 -> V_310 = 3 ;
V_307 = V_11 -> V_308 + 2 ;
V_307 -> V_153 = V_11 -> V_313 ;
if ( V_11 -> V_336 ) {
V_138 = V_11 -> V_337 ;
if ( ! V_138 )
V_138 = & V_338 ;
V_307 -> V_317 [ V_318 ] = * V_138 ;
V_307 -> V_317 [ V_318 ] . V_3 =
V_11 -> V_336 ;
} else {
V_307 -> V_317 [ V_318 ] =
V_339 ;
V_307 -> V_317 [ V_318 ] . V_3 = 0 ;
}
if ( V_309 ) {
V_138 = V_11 -> V_340 ;
if ( ! V_138 )
V_138 = & V_341 ;
V_307 -> V_317 [ V_323 ] = * V_138 ;
V_307 -> V_317 [ V_323 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_307 -> V_317 [ V_323 ] . V_342 =
V_11 -> V_174 - 1 ;
} else {
V_307 -> V_317 [ V_323 ] =
V_339 ;
V_307 -> V_317 [ V_323 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_148 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_343 )
V_11 -> V_343 ( V_2 ) ;
F_149 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_155 . V_169 ) {
struct V_71 * V_123 = V_11 -> V_155 . V_169 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_155 . V_344 ; V_36 ++ )
F_42 ( V_123 [ V_36 ] . V_153 ) ;
}
F_150 ( & V_11 -> V_155 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_345 . V_169 ) {
struct V_346 * * V_347 = V_11 -> V_345 . V_169 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_345 . V_344 ; V_36 ++ )
F_42 ( V_347 [ V_36 ] ) ;
}
F_150 ( & V_11 -> V_345 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_148 ( V_2 ) ;
F_118 ( V_2 ) ;
F_151 ( V_2 ) ;
F_42 ( V_11 ) ;
F_153 ( V_2 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
F_50 ( V_2 , false ) ;
}
static int F_155 ( struct V_1 * V_2 , T_4 V_348 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_148 ( V_2 ) ;
if ( V_11 && V_11 -> V_349 )
V_11 -> V_349 ( V_2 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
F_52 ( 150 ) ;
V_2 -> V_350 . V_351 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_124 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 , const char * V_153 )
{
F_42 ( V_2 -> V_200 ) ;
V_2 -> V_200 = F_62 ( V_153 , V_125 ) ;
if ( ! V_2 -> V_200 ) {
F_152 ( V_2 ) ;
return - V_157 ;
}
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
const struct V_352 * V_138 ;
for ( V_138 = V_353 ; V_138 -> V_130 ; V_138 ++ ) {
if ( V_138 -> V_130 != V_2 -> V_130 )
continue;
if ( ( F_90 ( V_2 ) & V_138 -> V_354 ) == V_138 -> V_355 )
return F_159 ( V_2 , V_138 -> V_153 ) ;
}
return 0 ;
}
static int F_161 ( struct V_10 * V_11 , int type , const char * V_153 ,
int V_356 , unsigned long V_56 )
{
struct V_71 * V_156 ;
V_156 = F_58 ( V_11 ) ;
if ( ! V_156 )
return - V_157 ;
* V_156 = V_357 [ type ] ;
V_156 -> V_153 = F_62 ( V_153 , V_125 ) ;
if ( ! V_156 -> V_153 )
return - V_157 ;
V_156 -> V_50 = V_356 ;
if ( F_162 ( V_56 ) )
V_156 -> V_242 = V_358 ;
V_156 -> V_268 = V_56 ;
return 0 ;
}
static int F_163 ( struct V_10 * V_11 , int type ,
const char * V_359 , const char * V_4 ,
const char * V_360 , int V_356 , unsigned long V_56 )
{
char V_153 [ 32 ] ;
snprintf ( V_153 , sizeof( V_153 ) , L_41 , V_359 , V_4 , V_360 ) ;
return F_161 ( V_11 , type , V_153 , V_356 , V_56 ) ;
}
static const char * F_164 ( struct V_10 * V_11 , int V_361 ,
bool V_362 , int * V_50 )
{
struct V_159 * V_160 = & V_11 -> V_39 ;
* V_50 = 0 ;
if ( V_160 -> V_164 == 1 && ! V_11 -> V_363 &&
! V_160 -> V_166 && ! V_160 -> V_163 && V_362 )
return L_42 ;
switch ( V_160 -> V_161 ) {
case V_162 :
if ( V_160 -> V_164 == 1 )
return L_43 ;
if ( V_160 -> V_164 == 2 )
return V_361 ? L_44 : L_43 ;
break;
case V_165 :
if ( V_361 && V_11 -> V_363 )
break;
* V_50 = V_361 ;
return L_45 ;
default:
if ( V_160 -> V_164 == 1 && ! V_11 -> V_363 )
return L_46 ;
break;
}
if ( F_25 ( V_361 >= F_26 ( V_364 ) ) )
return L_46 ;
return V_364 [ V_361 ] ;
}
static void F_165 ( struct V_10 * V_11 , T_1 V_72 , int V_31 )
{
struct V_365 * V_169 ;
if ( V_11 -> V_366 >= F_26 ( V_11 -> V_367 ) - 1 )
return;
V_169 = V_11 -> V_367 + V_11 -> V_366 ;
V_169 -> V_3 = V_72 ;
V_169 -> V_4 = V_53 ;
V_169 -> V_31 = V_31 ;
V_11 -> V_366 ++ ;
V_11 -> V_298 . V_368 = V_11 -> V_367 ;
}
static int F_166 ( struct V_10 * V_11 , T_1 V_41 ,
const char * V_369 , int V_370 ,
int V_31 , T_1 V_371 )
{
int V_255 ;
V_255 = F_167 ( V_11 , V_372 , V_369 , V_370 ,
F_96 ( V_371 , 3 , V_31 , V_53 ) ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_168 ( V_11 , V_373 , V_369 , V_370 ,
F_96 ( V_371 , 3 , V_31 , V_53 ) ) ;
if ( V_255 < 0 )
return V_255 ;
F_165 ( V_11 , V_371 , V_31 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_59 = F_23 ( V_2 , V_3 ) ;
return ( V_59 & V_374 ) != 0 ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_375 ;
T_1 * V_376 = V_11 -> V_175 ;
int V_377 = F_26 ( V_11 -> V_375 ) ;
int V_36 , V_170 = 0 ;
V_3 = V_2 -> V_259 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_260 ; V_36 ++ , V_3 ++ ) {
T_1 V_378 ;
const T_1 * V_169 ;
unsigned int V_379 = F_2 ( V_2 , V_3 ) ;
int type = F_17 ( V_379 ) ;
if ( type != V_262 || ( V_379 & V_263 ) )
continue;
V_26 [ V_170 ] = V_3 ;
V_376 [ V_170 ] = V_3 ;
V_378 = V_3 ;
for (; ; ) {
int V_172 ;
type = F_17 ( F_2 ( V_2 , V_378 ) ) ;
if ( type == V_135 )
break;
if ( type == V_380 ) {
V_376 [ V_170 ] = V_378 ;
break;
}
V_172 = F_16 ( V_2 , V_378 , & V_169 ) ;
if ( V_172 > 1 ) {
V_376 [ V_170 ] = V_378 ;
break;
} else if ( V_172 != 1 )
break;
V_378 = * V_169 ;
}
if ( ++ V_170 >= V_377 )
break;
}
V_11 -> V_26 = V_11 -> V_375 ;
V_11 -> V_32 = V_11 -> V_175 ;
V_11 -> V_174 = V_170 ;
return V_170 ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_159 * V_160 = & V_11 -> V_39 ;
T_1 V_381 = V_11 -> V_382 ;
struct V_34 * V_35 = & V_11 -> V_171 [ 0 ] ;
int V_383 ;
int V_36 , V_384 , V_255 , V_31 , V_385 = 0 ;
const char * V_386 = NULL ;
V_383 = F_170 ( V_2 ) ;
if ( V_383 < 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
T_1 V_41 ;
const char * V_387 ;
V_41 = V_160 -> V_40 [ V_36 ] . V_41 ;
if ( ! F_169 ( V_2 , V_41 ) )
continue;
V_387 = F_172 ( V_2 , V_160 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_387 , L_47 ) )
V_387 = L_48 ;
if ( V_386 && ! strcmp ( V_387 , V_386 ) )
V_385 ++ ;
else
V_385 = 0 ;
V_386 = V_387 ;
if ( V_381 ) {
V_31 = F_69 ( V_2 , V_381 , V_41 ) ;
if ( V_31 >= 0 ) {
V_255 = F_166 ( V_11 , V_41 ,
V_387 , V_385 ,
V_31 , V_381 ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
for ( V_384 = 0 ; V_384 < V_383 ; V_384 ++ ) {
T_1 V_173 = F_12 ( V_11 , V_384 ) ;
V_31 = F_69 ( V_2 , V_173 , V_41 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_113 [ V_35 -> V_16 ] = V_41 ;
F_173 ( V_35 , V_387 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_35 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
unsigned int V_183 ;
T_1 V_3 ;
if ( V_160 -> V_182 != 1 )
return 0 ;
V_183 = F_72 ( V_2 , V_160 -> V_40 [ 0 ] . V_41 ) ;
if ( F_73 ( V_183 ) != V_184 )
return 0 ;
if ( V_160 -> V_166 == 1 && V_160 -> V_161 == V_162 )
V_3 = V_160 -> V_103 [ 0 ] ;
else if ( V_160 -> V_164 == 1 && V_160 -> V_161 == V_165 )
V_3 = V_160 -> V_108 [ 0 ] ;
else
return 0 ;
if ( ! ( F_23 ( V_2 , V_3 ) & V_374 ) )
return 0 ;
V_160 -> V_40 [ 1 ] . V_41 = V_3 ;
V_160 -> V_40 [ 1 ] . type = V_58 ;
V_160 -> V_182 = 2 ;
V_11 -> V_38 = 1 ;
F_65 ( L_49 , V_3 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_388 )
{
F_14 ( V_2 , V_3 , 0 , V_42 ,
V_388 ) ;
if ( F_176 ( V_2 , V_3 , V_99 ) )
F_14 ( V_2 , V_3 , 0 , V_252 ,
V_253 ) ;
}
static int F_177 ( int V_161 )
{
if ( V_161 == V_165 )
return V_44 ;
else
return V_94 ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
T_1 V_3 = V_160 -> V_40 [ V_36 ] . V_41 ;
if ( F_169 ( V_2 , V_3 ) ) {
F_21 ( V_2 , V_3 , V_160 -> V_40 [ V_36 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_251 )
F_14 ( V_2 , V_3 , 0 ,
V_252 ,
V_389 ) ;
}
}
if ( V_11 -> V_382 ) {
int V_170 = F_16 ( V_2 , V_11 -> V_382 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_170 ; V_36 ++ )
F_14 ( V_2 , V_11 -> V_382 , 0 ,
V_252 ,
F_179 ( V_36 ) ) ;
}
}
static T_1 F_180 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_169 [ 5 ] ;
int V_36 , V_390 ;
if ( F_17 ( F_2 ( V_2 , V_3 ) ) == V_391 )
return V_3 ;
V_390 = F_93 ( V_2 , V_3 , V_169 , F_26 ( V_169 ) ) ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
if ( F_17 ( F_2 ( V_2 , V_169 [ V_36 ] ) ) == V_391 )
return V_169 [ V_36 ] ;
}
return 0 ;
}
static T_1 F_181 ( struct V_1 * V_2 , T_1 V_41 )
{
T_1 V_392 [ 5 ] ;
int V_390 = F_93 ( V_2 , V_41 , V_392 ,
F_26 ( V_392 ) ) ;
if ( V_390 != 1 ||
F_17 ( F_2 ( V_2 , V_392 [ 0 ] ) ) != V_380 )
return V_41 ;
return V_392 [ 0 ] ;
}
static T_1 F_182 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_245 )
{
T_1 V_72 [ 5 ] ;
int V_36 , V_390 ;
V_41 = F_181 ( V_2 , V_41 ) ;
V_390 = F_93 ( V_2 , V_41 , V_72 , F_26 ( V_72 ) ) ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
if ( F_180 ( V_2 , V_72 [ V_36 ] ) == V_245 )
return V_72 [ V_36 ] ;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_245 )
{
T_1 V_72 [ 5 ] ;
int V_36 , V_390 ;
V_41 = F_181 ( V_2 , V_41 ) ;
V_390 = F_93 ( V_2 , V_41 , V_72 , F_26 ( V_72 ) ) ;
if ( V_390 < 2 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
if ( F_180 ( V_2 , V_72 [ V_36 ] ) == V_245 ) {
F_184 ( V_2 , V_41 , 0 ,
V_54 , V_36 ) ;
return 0 ;
}
}
return 0 ;
}
static bool F_185 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( F_78 ( V_3 , V_11 -> V_248 . V_319 ,
F_26 ( V_11 -> V_393 ) ) ||
F_78 ( V_3 , V_11 -> V_248 . V_394 ,
F_26 ( V_11 -> V_248 . V_394 ) ) ||
F_78 ( V_3 , V_11 -> V_248 . V_395 ,
F_26 ( V_11 -> V_248 . V_395 ) ) )
return true ;
for ( V_36 = 0 ; V_36 < V_11 -> V_363 ; V_36 ++ ) {
if ( V_11 -> V_396 [ V_36 ] . V_245 == V_3 )
return true ;
}
return false ;
}
static T_1 F_186 ( struct V_1 * V_2 , T_1 V_41 )
{
T_1 V_392 [ 5 ] ;
int V_36 , V_390 ;
V_41 = F_181 ( V_2 , V_41 ) ;
V_390 = F_93 ( V_2 , V_41 , V_392 , F_26 ( V_392 ) ) ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
T_1 V_3 = F_180 ( V_2 , V_392 [ V_36 ] ) ;
if ( ! V_3 )
continue;
if ( ! F_185 ( V_2 , V_3 ) )
return V_3 ;
}
return 0 ;
}
static bool F_187 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_245 )
{
T_1 V_392 [ 5 ] ;
int V_36 , V_390 ;
if ( ! V_41 || ! V_245 )
return false ;
V_41 = F_181 ( V_2 , V_41 ) ;
V_390 = F_93 ( V_2 , V_41 , V_392 , F_26 ( V_392 ) ) ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
T_1 V_3 = F_180 ( V_2 , V_392 [ V_36 ] ) ;
if ( V_3 == V_245 )
return true ;
}
return false ;
}
static T_1 F_188 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_397 = F_181 ( V_2 , V_41 ) ;
T_1 V_3 , V_398 , V_392 [ 5 ] ;
int V_36 , V_390 = F_93 ( V_2 , V_397 , V_392 ,
F_26 ( V_392 ) ) ;
if ( V_390 == 1 )
return F_186 ( V_2 , V_41 ) ;
V_398 = 0 ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
if ( V_392 [ V_36 ] == V_11 -> V_382 )
continue;
V_3 = F_180 ( V_2 , V_392 [ V_36 ] ) ;
if ( V_3 && ! F_185 ( V_2 , V_3 ) ) {
if ( V_398 )
return 0 ;
V_398 = V_3 ;
}
}
return V_398 ;
}
static inline unsigned int F_189 ( unsigned int V_399 )
{
T_1 V_3 = F_162 ( V_399 ) ;
unsigned int V_4 ;
if ( F_25 ( V_3 >= V_400 ) )
return 0 ;
V_4 = F_190 ( V_399 ) ;
return ( V_3 << 1 ) | V_4 ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
memset ( V_11 -> V_401 , 0 , sizeof( V_11 -> V_401 ) ) ;
memset ( V_11 -> V_402 , 0 , sizeof( V_11 -> V_402 ) ) ;
}
static int F_192 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_245 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
unsigned int V_56 ;
int V_403 = 0 ;
V_3 = F_193 ( V_2 , V_41 , V_245 ) ;
if ( V_3 ) {
V_56 = F_96 ( V_3 , 3 , 0 , V_99 ) ;
if ( F_194 ( V_11 -> V_401 , V_3 ) )
V_403 += V_404 ;
else
F_195 ( V_11 -> V_401 , V_56 ) ;
} else
V_403 += V_404 ;
V_3 = F_196 ( V_2 , V_41 , V_245 ) ;
if ( V_3 ) {
unsigned int V_405 = F_17 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_405 == V_135 || V_405 == V_391 )
V_56 = F_96 ( V_3 , 3 , 0 , V_99 ) ;
else
V_56 = F_96 ( V_3 , 3 , 0 , V_53 ) ;
if ( F_194 ( V_11 -> V_402 , V_56 ) )
V_403 += V_404 ;
else
F_195 ( V_11 -> V_402 , V_56 ) ;
} else
V_403 += V_404 ;
return V_403 ;
}
static int F_197 ( struct V_1 * V_2 , int V_406 ,
const T_1 * V_88 , T_1 * V_407 ,
const struct V_408 * V_409 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_36 , V_277 ;
int V_403 = 0 ;
T_1 V_245 ;
if ( ! V_406 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_406 ; V_36 ++ ) {
T_1 V_41 = V_88 [ V_36 ] ;
if ( ! V_407 [ V_36 ] )
V_407 [ V_36 ] = F_186 ( V_2 , V_41 ) ;
if ( ! V_407 [ V_36 ] && ! V_36 ) {
for ( V_277 = 1 ; V_277 < V_406 ; V_277 ++ ) {
if ( F_187 ( V_2 , V_41 , V_407 [ V_277 ] ) ) {
V_407 [ 0 ] = V_407 [ V_277 ] ;
V_407 [ V_277 ] = 0 ;
break;
}
}
}
V_245 = V_407 [ V_36 ] ;
if ( ! V_245 ) {
if ( F_187 ( V_2 , V_41 , V_407 [ 0 ] ) )
V_245 = V_407 [ 0 ] ;
else if ( V_160 -> V_164 > V_36 &&
F_187 ( V_2 , V_41 ,
V_11 -> V_393 [ V_36 ] ) )
V_245 = V_11 -> V_393 [ V_36 ] ;
if ( V_245 ) {
if ( ! V_36 )
V_403 += V_409 -> V_410 ;
else if ( V_36 == 1 )
V_403 += V_409 -> V_411 ;
else
V_403 += V_409 -> V_412 ;
} else if ( F_187 ( V_2 , V_41 ,
V_11 -> V_393 [ 0 ] ) ) {
V_245 = V_11 -> V_393 [ 0 ] ;
V_403 += V_409 -> V_413 ;
} else if ( ! V_36 )
V_403 += V_409 -> V_414 ;
else
V_403 += V_409 -> V_415 ;
}
if ( V_245 )
V_403 += F_192 ( V_2 , V_41 , V_245 ) ;
}
return V_403 ;
}
static bool F_198 ( struct V_1 * V_2 , int V_416 ,
const T_1 * V_88 , T_1 * V_407 )
{
int V_36 ;
bool V_417 = false ;
for ( V_36 = 0 ; V_36 < V_416 ; V_36 ++ ) {
if ( V_407 [ V_36 ] )
continue;
V_407 [ V_36 ] = F_188 ( V_2 , V_88 [ V_36 ] ) ;
if ( V_407 [ V_36 ] )
V_417 = true ;
}
return V_417 ;
}
static int F_199 ( struct V_1 * V_2 ,
bool V_418 ,
bool V_419 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_36 , V_255 , V_403 ;
V_11 -> V_248 . V_314 = V_160 -> V_164 ;
V_11 -> V_248 . V_319 = V_11 -> V_393 ;
memset ( V_11 -> V_393 , 0 , sizeof( V_11 -> V_393 ) ) ;
memset ( V_11 -> V_248 . V_394 , 0 , sizeof( V_11 -> V_248 . V_394 ) ) ;
memset ( V_11 -> V_248 . V_395 , 0 , sizeof( V_11 -> V_248 . V_395 ) ) ;
V_11 -> V_363 = 0 ;
F_191 ( V_2 ) ;
V_403 = 0 ;
if ( V_418 ) {
bool V_420 ;
do {
V_420 = F_198 ( V_2 , V_160 -> V_164 ,
V_160 -> V_108 ,
V_11 -> V_393 ) ;
V_420 |= F_198 ( V_2 , V_160 -> V_166 ,
V_160 -> V_103 ,
V_11 -> V_248 . V_394 ) ;
V_420 |= F_198 ( V_2 , V_160 -> V_163 ,
V_160 -> V_107 ,
V_11 -> V_248 . V_395 ) ;
if ( V_419 && V_160 -> V_164 == 1 &&
V_160 -> V_161 != V_162 ) {
V_255 = F_200 ( V_2 , V_160 -> V_108 [ 0 ] , true , 0 ) ;
if ( ! V_255 )
V_420 = true ;
}
} while ( V_420 );
}
V_403 += F_197 ( V_2 , V_160 -> V_164 , V_160 -> V_108 ,
V_11 -> V_393 ,
& V_421 ) ;
V_11 -> V_248 . V_314 = 0 ;
for ( V_36 = 0 ; V_36 < V_160 -> V_164 ; V_36 ++ ) {
if ( V_11 -> V_393 [ V_36 ] )
V_11 -> V_248 . V_314 ++ ;
else {
memmove ( V_11 -> V_393 + V_36 ,
V_11 -> V_393 + V_36 + 1 ,
sizeof( T_1 ) * ( V_160 -> V_164 - V_36 - 1 ) ) ;
V_11 -> V_393 [ V_160 -> V_164 - 1 ] = 0 ;
}
}
if ( V_419 &&
V_160 -> V_164 == 1 && V_160 -> V_161 != V_162 ) {
V_255 = F_200 ( V_2 , V_160 -> V_108 [ 0 ] , false , 0 ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( V_160 -> V_161 != V_165 ) {
V_255 = F_197 ( V_2 , V_160 -> V_166 , V_160 -> V_103 ,
V_11 -> V_248 . V_394 ,
& V_422 ) ;
if ( V_255 < 0 )
return V_255 ;
V_403 += V_255 ;
}
if ( V_160 -> V_161 != V_162 ) {
V_255 = F_197 ( V_2 , V_160 -> V_163 ,
V_160 -> V_107 ,
V_11 -> V_248 . V_395 ,
& V_422 ) ;
if ( V_255 < 0 )
return V_255 ;
V_403 += V_255 ;
}
if ( V_160 -> V_164 == 1 && V_160 -> V_161 != V_162 ) {
V_255 = F_200 ( V_2 , V_160 -> V_108 [ 0 ] , false , 0 ) ;
if ( V_255 < 0 )
return V_255 ;
V_403 += V_255 ;
}
if ( V_160 -> V_166 && V_160 -> V_161 == V_162 ) {
int V_423 = 0 ;
if ( V_160 -> V_164 >= 3 )
V_423 = 1 ;
V_255 = F_200 ( V_2 , V_160 -> V_103 [ 0 ] , false ,
V_423 ) ;
if ( V_255 < 0 )
return V_255 ;
V_403 += V_255 ;
}
if ( V_11 -> V_363 == 2 ) {
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ )
V_11 -> V_393 [ V_11 -> V_248 . V_314 ++ ] =
V_11 -> V_396 [ V_36 ] . V_245 ;
V_11 -> V_424 = 2 ;
} else if ( V_11 -> V_363 ) {
V_11 -> V_363 = 0 ;
V_403 += V_425 ;
}
return V_403 ;
}
static void F_201 ( struct V_10 * V_11 , struct V_159 * V_160 )
{
F_202 ( L_50 ,
V_160 -> V_108 [ 0 ] , V_160 -> V_108 [ 1 ] ,
V_160 -> V_108 [ 2 ] , V_160 -> V_108 [ 2 ] ,
V_11 -> V_248 . V_319 [ 0 ] ,
V_11 -> V_248 . V_319 [ 1 ] ,
V_11 -> V_248 . V_319 [ 2 ] ,
V_11 -> V_248 . V_319 [ 3 ] ) ;
if ( V_11 -> V_363 > 0 )
F_202 ( L_51 ,
V_11 -> V_363 ,
V_11 -> V_396 [ 0 ] . V_41 , V_11 -> V_396 [ 1 ] . V_41 ,
V_11 -> V_396 [ 0 ] . V_245 , V_11 -> V_396 [ 1 ] . V_245 ) ;
F_202 ( L_52 ,
V_160 -> V_103 [ 0 ] , V_160 -> V_103 [ 1 ] ,
V_160 -> V_103 [ 2 ] , V_160 -> V_103 [ 2 ] ,
V_11 -> V_248 . V_394 [ 0 ] ,
V_11 -> V_248 . V_394 [ 1 ] ,
V_11 -> V_248 . V_394 [ 2 ] ,
V_11 -> V_248 . V_394 [ 3 ] ) ;
F_202 ( L_53 ,
V_160 -> V_107 [ 0 ] , V_160 -> V_107 [ 1 ] ,
V_160 -> V_107 [ 2 ] , V_160 -> V_107 [ 3 ] ,
V_11 -> V_248 . V_395 [ 0 ] ,
V_11 -> V_248 . V_395 [ 1 ] ,
V_11 -> V_248 . V_395 [ 2 ] ,
V_11 -> V_248 . V_395 [ 3 ] ) ;
}
static int F_203 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
struct V_159 * V_426 ;
int V_427 = V_428 ;
int V_403 ;
bool V_418 = true , V_419 = true ;
bool V_429 = true , V_430 = true ;
bool V_431 = false ;
V_426 = F_204 ( sizeof( * V_426 ) , V_125 ) ;
if ( ! V_426 )
return - V_157 ;
* V_426 = * V_160 ;
for (; ; ) {
V_403 = F_199 ( V_2 , V_418 ,
V_419 ) ;
if ( V_403 < 0 ) {
F_42 ( V_426 ) ;
return V_403 ;
}
F_202 ( L_54 ,
V_160 -> V_161 , V_418 , V_419 ,
V_403 ) ;
F_201 ( V_11 , V_160 ) ;
if ( V_403 < V_427 ) {
V_427 = V_403 ;
* V_426 = * V_160 ;
V_429 = V_418 ;
V_430 = V_419 ;
}
if ( ! V_403 )
break;
V_419 = ! V_419 ;
if ( ! V_419 )
continue;
V_418 = ! V_418 ;
if ( ! V_418 )
continue;
if ( V_431 )
break;
V_431 = true ;
if ( V_160 -> V_163 > 0 &&
V_160 -> V_161 == V_165 ) {
V_160 -> V_166 = V_160 -> V_164 ;
memcpy ( V_160 -> V_103 , V_160 -> V_108 ,
sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_164 = V_160 -> V_163 ;
memcpy ( V_160 -> V_108 , V_160 -> V_107 ,
sizeof( V_160 -> V_107 ) ) ;
V_160 -> V_163 = 0 ;
memset ( V_160 -> V_107 , 0 , sizeof( V_160 -> V_107 ) ) ;
V_160 -> V_161 = V_162 ;
V_418 = true ;
continue;
}
if ( V_160 -> V_166 > 0 &&
V_160 -> V_161 == V_162 ) {
V_160 -> V_163 = V_160 -> V_164 ;
memcpy ( V_160 -> V_107 , V_160 -> V_108 ,
sizeof( V_160 -> V_107 ) ) ;
V_160 -> V_164 = V_160 -> V_166 ;
memcpy ( V_160 -> V_108 , V_160 -> V_103 ,
sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_166 = 0 ;
memset ( V_160 -> V_103 , 0 , sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_161 = V_165 ;
V_418 = true ;
continue;
}
break;
}
if ( V_403 ) {
* V_160 = * V_426 ;
F_199 ( V_2 , V_429 , V_430 ) ;
}
F_202 ( L_55 ,
V_160 -> V_161 , V_429 , V_430 ) ;
F_201 ( V_11 , V_160 ) ;
if ( V_160 -> V_108 [ 0 ] )
V_11 -> V_285 =
F_193 ( V_2 , V_160 -> V_108 [ 0 ] ,
V_11 -> V_248 . V_319 [ 0 ] ) ;
F_191 ( V_2 ) ;
F_42 ( V_426 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
const char * V_359 , int V_356 ,
T_1 V_3 , unsigned int V_432 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 ;
if ( ! V_3 )
return 0 ;
V_56 = F_96 ( V_3 , V_432 , 0 , V_99 ) ;
if ( F_194 ( V_11 -> V_401 , V_56 ) && V_432 != 2 )
return 0 ;
F_195 ( V_11 -> V_401 , V_56 ) ;
return F_167 ( V_2 -> V_11 , V_372 , V_359 , V_356 ,
V_56 ) ;
}
static int F_206 ( struct V_1 * V_2 ,
const char * V_359 , int V_356 ,
T_1 V_3 )
{
int V_432 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_433 )
V_432 = 3 ;
return F_205 ( V_2 , V_359 , V_356 , V_3 , V_432 ) ;
}
static int F_207 ( struct V_1 * V_2 ,
const char * V_359 , int V_356 ,
T_1 V_3 , unsigned int V_432 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_405 ;
int type ;
unsigned long V_56 ;
if ( ! V_3 )
return 0 ;
V_405 = F_17 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_405 == V_135 || V_405 == V_391 ) {
type = V_373 ;
V_56 = F_96 ( V_3 , V_432 , 0 , V_99 ) ;
} else if ( F_16 ( V_2 , V_3 , NULL ) == 1 ) {
type = V_373 ;
V_56 = F_96 ( V_3 , V_432 , 0 , V_53 ) ;
} else {
type = V_434 ;
V_56 = F_96 ( V_3 , V_432 , 2 , V_53 ) ;
}
if ( F_194 ( V_11 -> V_402 , V_56 ) && V_432 != 2 )
return 0 ;
F_195 ( V_11 -> V_402 , V_56 ) ;
return F_168 ( V_2 -> V_11 , type , V_359 , V_356 , V_56 ) ;
}
static int F_208 ( struct V_1 * V_2 , const char * V_359 ,
int V_356 , T_1 V_3 )
{
int V_432 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_433 )
V_432 = 3 ;
return F_207 ( V_2 , V_359 , V_356 , V_3 , V_432 ) ;
}
static T_1 F_196 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_245 )
{
T_1 V_72 = F_182 ( V_2 , V_41 , V_245 ) ;
if ( F_176 ( V_2 , V_41 , V_99 ) )
return V_41 ;
else if ( V_72 && F_176 ( V_2 , V_72 , V_53 ) )
return V_72 ;
else if ( F_176 ( V_2 , V_245 , V_99 ) )
return V_245 ;
return 0 ;
}
static T_1 F_193 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_245 )
{
T_1 V_72 = F_182 ( V_2 , V_41 , V_245 ) ;
if ( F_209 ( V_2 , V_245 , V_99 ) )
return V_245 ;
else if ( F_209 ( V_2 , V_72 , V_99 ) )
return V_72 ;
else if ( F_209 ( V_2 , V_41 , V_99 ) )
return V_41 ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 ,
const struct V_159 * V_160 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_255 , V_435 ;
V_435 = V_160 -> V_164 ;
if ( V_11 -> V_363 > 0 && V_160 -> V_164 < 3 )
V_435 += V_11 -> V_363 ;
for ( V_36 = 0 ; V_36 < V_435 ; V_36 ++ ) {
const char * V_153 ;
int V_50 ;
T_1 V_245 , V_41 ;
T_1 V_436 , V_437 ;
V_245 = V_11 -> V_248 . V_319 [ V_36 ] ;
if ( ! V_245 )
continue;
if ( V_36 >= V_160 -> V_164 ) {
V_41 = V_11 -> V_396 [ V_36 - 1 ] . V_41 ;
V_50 = 0 ;
V_153 = V_364 [ V_36 ] ;
} else {
V_41 = V_160 -> V_108 [ V_36 ] ;
V_153 = F_164 ( V_11 , V_36 , true , & V_50 ) ;
}
V_436 = F_196 ( V_2 , V_41 , V_245 ) ;
V_437 = F_193 ( V_2 , V_41 , V_245 ) ;
if ( ! V_153 || ! strcmp ( V_153 , L_56 ) ) {
V_255 = F_205 ( V_2 , L_57 , 0 , V_437 , 1 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_205 ( V_2 , L_58 , 0 , V_437 , 2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_207 ( V_2 , L_57 , 0 , V_436 , 1 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_207 ( V_2 , L_58 , 0 , V_436 , 2 ) ;
if ( V_255 < 0 )
return V_255 ;
} else {
V_255 = F_206 ( V_2 , V_153 , V_50 , V_437 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_208 ( V_2 , V_153 , V_50 , V_436 ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_245 , const char * V_359 ,
int V_356 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_436 , V_437 ;
int V_255 ;
if ( ! V_245 ) {
unsigned int V_56 ;
if ( ! ( F_2 ( V_2 , V_41 ) & V_251 ) )
return 0 ;
V_56 = F_96 ( V_41 , 3 , 0 , V_99 ) ;
if ( F_194 ( V_11 -> V_402 , V_56 ) )
return 0 ;
F_195 ( V_11 -> V_402 , V_56 ) ;
return F_168 ( V_11 , V_373 , V_359 , V_356 , V_56 ) ;
}
V_436 = F_196 ( V_2 , V_41 , V_245 ) ;
V_437 = F_193 ( V_2 , V_41 , V_245 ) ;
V_255 = F_206 ( V_2 , V_359 , V_356 , V_437 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_208 ( V_2 , V_359 , V_356 , V_436 ) ;
if ( V_255 < 0 )
return V_255 ;
return 0 ;
}
static struct V_346 * F_212 ( struct V_1 * V_2 ,
unsigned int V_170 ,
struct V_438 * V_439 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_346 * * V_440 , * V_347 ;
F_59 ( & V_11 -> V_345 , sizeof( V_347 ) , 8 ) ;
V_440 = F_60 ( & V_11 -> V_345 ) ;
if ( ! V_440 )
return NULL ;
V_347 = F_41 ( sizeof( * V_347 ) + sizeof( long ) * ( V_170 + 1 ) , V_125 ) ;
* V_440 = V_347 ;
if ( V_347 )
V_347 -> V_439 = V_439 ;
return V_347 ;
}
static int F_213 ( struct V_1 * V_2 , int V_87 ,
const T_1 * V_88 ,
const T_1 * V_407 ,
const char * V_359 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_346 * V_347 ;
char V_153 [ 32 ] ;
int V_36 , V_172 , V_255 ;
if ( ! V_87 || ! V_88 [ 0 ] )
return 0 ;
if ( V_87 == 1 ) {
T_1 V_245 = * V_407 ;
if ( ! V_245 )
V_245 = V_11 -> V_248 . V_319 [ 0 ] ;
return F_211 ( V_2 , * V_88 , V_245 , V_359 , 0 ) ;
}
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
T_1 V_245 ;
if ( V_407 [ V_87 - 1 ] )
V_245 = V_407 [ V_36 ] ;
else
V_245 = 0 ;
if ( V_87 == 2 && V_36 == 1 && ! strcmp ( V_359 , L_43 ) ) {
V_255 = F_211 ( V_2 , V_88 [ V_36 ] , V_245 ,
L_44 , 0 ) ;
} else if ( V_87 >= 3 ) {
snprintf ( V_153 , sizeof( V_153 ) , L_59 ,
V_359 , V_364 [ V_36 ] ) ;
V_255 = F_211 ( V_2 , V_88 [ V_36 ] , V_245 ,
V_153 , 0 ) ;
} else {
V_255 = F_211 ( V_2 , V_88 [ V_36 ] , V_245 ,
V_359 , V_36 ) ;
}
if ( V_255 < 0 )
return V_255 ;
}
if ( V_407 [ V_87 - 1 ] )
return 0 ;
V_347 = F_212 ( V_2 , V_87 , & V_441 ) ;
if ( ! V_347 )
return - V_157 ;
V_172 = 0 ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
T_1 V_437 ;
if ( ! V_88 [ V_36 ] || ! V_407 [ V_36 ] )
continue;
V_437 = F_193 ( V_2 , V_88 [ V_36 ] , V_407 [ V_36 ] ) ;
if ( V_437 )
V_347 -> V_442 [ V_172 ++ ] =
F_96 ( V_437 , 3 , 0 , V_99 ) ;
}
if ( V_172 ) {
snprintf ( V_153 , sizeof( V_153 ) , L_60 , V_359 ) ;
V_255 = F_161 ( V_11 , V_443 , V_153 , 0 , ( long ) V_347 ) ;
if ( V_255 < 0 )
return V_255 ;
}
return 0 ;
}
static int F_214 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_213 ( V_2 , V_11 -> V_39 . V_166 ,
V_11 -> V_39 . V_103 ,
V_11 -> V_248 . V_394 ,
L_45 ) ;
}
static int F_215 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_213 ( V_2 , V_11 -> V_39 . V_163 ,
V_11 -> V_39 . V_107 ,
V_11 -> V_248 . V_395 ,
L_43 ) ;
}
static void F_216 ( struct V_1 * V_2 ,
T_1 V_41 , int V_388 ,
T_1 V_245 )
{
int V_36 , V_390 ;
T_1 V_3 , V_72 = 0 ;
T_1 V_392 [ V_444 ] ;
F_175 ( V_2 , V_41 , V_388 ) ;
V_3 = F_181 ( V_2 , V_41 ) ;
V_390 = F_93 ( V_2 , V_3 , V_392 , F_26 ( V_392 ) ) ;
for ( V_36 = 0 ; V_36 < V_390 ; V_36 ++ ) {
if ( F_180 ( V_2 , V_392 [ V_36 ] ) != V_245 )
continue;
V_72 = V_392 [ V_36 ] ;
break;
}
if ( ! V_72 )
return;
if ( V_390 > 1 )
F_14 ( V_2 , V_3 , 0 , V_54 , V_36 ) ;
if ( F_176 ( V_2 , V_72 , V_53 ) ) {
F_14 ( V_2 , V_72 , 0 , V_252 ,
F_217 ( 0 ) ) ;
F_14 ( V_2 , V_72 , 0 , V_252 ,
F_217 ( 1 ) ) ;
}
V_3 = F_193 ( V_2 , V_41 , V_245 ) ;
if ( V_3 )
F_14 ( V_2 , V_3 , 0 , V_252 ,
V_445 ) ;
V_3 = F_196 ( V_2 , V_41 , V_245 ) ;
if ( V_3 == V_72 && F_176 ( V_2 , V_245 , V_99 ) )
F_14 ( V_2 , V_245 , 0 , V_252 ,
V_445 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_388 = F_177 ( V_11 -> V_39 . V_161 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_446 ; V_36 ++ ) {
T_1 V_3 = V_11 -> V_39 . V_108 [ V_36 ] ;
if ( V_3 )
F_216 ( V_2 , V_3 , V_388 ,
V_11 -> V_248 . V_319 [ V_36 ] ) ;
}
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_41 , V_245 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_166 ; V_36 ++ ) {
if ( V_11 -> V_39 . V_161 == V_165 )
break;
V_41 = V_11 -> V_39 . V_103 [ V_36 ] ;
if ( ! V_41 )
break;
V_245 = V_11 -> V_248 . V_394 [ V_36 ] ;
if ( ! V_245 ) {
if ( V_36 > 0 && V_11 -> V_248 . V_394 [ 0 ] )
V_245 = V_11 -> V_248 . V_394 [ 0 ] ;
else
V_245 = V_11 -> V_248 . V_319 [ 0 ] ;
}
F_216 ( V_2 , V_41 , V_44 , V_245 ) ;
}
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_163 ; V_36 ++ ) {
if ( V_11 -> V_39 . V_161 == V_162 )
break;
V_41 = V_11 -> V_39 . V_107 [ V_36 ] ;
if ( ! V_41 )
break;
V_245 = V_11 -> V_248 . V_395 [ V_36 ] ;
if ( ! V_245 ) {
if ( V_36 > 0 && V_11 -> V_248 . V_395 [ 0 ] )
V_245 = V_11 -> V_248 . V_395 [ 0 ] ;
else
V_245 = V_11 -> V_248 . V_319 [ 0 ] ;
}
F_216 ( V_2 , V_41 , V_94 , V_245 ) ;
}
}
static bool F_220 ( struct V_1 * V_2 ,
unsigned int V_447 , T_1 V_3 )
{
unsigned int V_183 , V_379 ;
V_183 = F_72 ( V_2 , V_3 ) ;
if ( F_221 ( V_183 ) != V_448 )
return false ;
if ( V_447 && F_222 ( V_183 ) != V_447 )
return false ;
V_379 = F_23 ( V_2 , V_3 ) ;
if ( ! ( V_379 & V_449 ) )
return false ;
return true ;
}
static int F_200 ( struct V_1 * V_2 ,
T_1 V_450 ,
bool V_451 , int V_423 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int type , V_36 , V_277 , V_407 , V_87 , V_452 ;
unsigned int V_183 = F_72 ( V_2 , V_450 ) ;
unsigned int V_447 = F_222 ( V_183 ) ;
int V_403 = 0 ;
V_452 = V_11 -> V_363 ;
if ( V_452 >= 2 )
goto V_453;
V_87 = 0 ;
for ( type = V_187 ; type >= V_58 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
if ( V_160 -> V_40 [ V_36 ] . type != type )
continue;
if ( F_220 ( V_2 , V_447 ,
V_160 -> V_40 [ V_36 ] . V_41 ) )
V_87 ++ ;
}
}
if ( V_87 < 2 )
goto V_453;
V_407 = V_11 -> V_248 . V_314 ;
for ( type = V_187 ; type >= V_58 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
T_1 V_3 = V_160 -> V_40 [ V_36 ] . V_41 ;
T_1 V_245 = 0 ;
if ( V_160 -> V_40 [ V_36 ] . type != type )
continue;
if ( ! F_220 ( V_2 , V_447 , V_3 ) )
continue;
for ( V_277 = 0 ; V_277 < V_11 -> V_363 ; V_277 ++ ) {
if ( V_3 == V_11 -> V_396 [ V_277 ] . V_41 )
break;
}
if ( V_277 < V_11 -> V_363 )
continue;
if ( V_423 && V_423 + V_11 -> V_363 < V_407 ) {
V_245 = V_11 -> V_393 [ V_423 + V_11 -> V_363 ] ;
if ( ! F_187 ( V_2 , V_3 , V_245 ) )
V_245 = 0 ;
}
if ( V_451 )
V_245 = F_188 ( V_2 , V_3 ) ;
else if ( ! V_245 )
V_245 = F_186 ( V_2 , V_3 ) ;
if ( ! V_245 ) {
V_403 ++ ;
continue;
}
V_11 -> V_396 [ V_11 -> V_363 ] . V_41 = V_3 ;
V_11 -> V_396 [ V_11 -> V_363 ] . V_245 = V_245 ;
V_11 -> V_363 ++ ;
if ( V_11 -> V_363 >= 2 )
break;
}
}
V_453:
if ( V_403 )
V_403 = V_425 ;
if ( V_452 == V_11 -> V_363 ) {
if ( V_451 )
return 1 ;
else
return V_403 ;
}
if ( ! V_451 && V_11 -> V_363 < 2 ) {
V_11 -> V_363 = V_452 ;
return V_403 ;
}
return 0 ;
}
static int F_223 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_149 ;
V_9 -> V_150 = 1 ;
V_9 -> V_20 . V_21 . V_49 = V_11 -> V_363 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_363 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_363 ;
sprintf ( V_9 -> V_20 . V_21 . V_153 , L_61 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_224 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_424 - 1 ) / 2 ;
return 0 ;
}
static int F_225 ( struct V_1 * V_2 , int V_31 , bool V_454 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_396 [ V_31 ] . V_41 ;
if ( ! V_11 -> V_396 [ V_31 ] . V_455 )
V_11 -> V_396 [ V_31 ] . V_455 =
F_22 ( V_2 , V_3 , 0 ,
V_61 , 0 ) ;
if ( V_454 ) {
F_184 ( V_2 , V_3 , 0 ,
V_42 ,
V_94 ) ;
if ( F_2 ( V_2 , V_3 ) & V_251 )
F_18 ( V_2 , V_3 , V_99 , 0 ,
V_52 , 0 ) ;
F_183 ( V_2 , V_3 , V_11 -> V_396 [ V_31 ] . V_245 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_251 )
F_18 ( V_2 , V_3 , V_99 , 0 ,
V_52 , V_52 ) ;
F_184 ( V_2 , V_3 , 0 ,
V_42 ,
V_11 -> V_396 [ V_31 ] . V_455 ) ;
}
return 0 ;
}
static int F_226 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_361 ;
V_361 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_361 < 0 || V_361 > V_11 -> V_363 )
return - V_154 ;
if ( V_361 == ( V_11 -> V_424 - 1 ) / 2 )
return 0 ;
V_11 -> V_424 = ( V_361 + 1 ) * 2 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_363 ; V_36 ++ )
F_225 ( V_2 , V_36 , V_36 < V_361 ) ;
V_11 -> V_248 . V_456 = V_11 -> V_424 ;
if ( V_11 -> V_457 && ! V_11 -> V_458 )
V_11 -> V_248 . V_314 = V_11 -> V_248 . V_456 / 2 ;
return 1 ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_363 > 0 ) {
struct V_71 * V_156 ;
V_156 = F_58 ( V_11 ) ;
if ( ! V_156 )
return - V_157 ;
* V_156 = V_459 ;
V_156 -> V_153 = F_62 ( L_62 , V_125 ) ;
if ( ! V_156 -> V_153 )
return - V_157 ;
}
return 0 ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
T_1 V_26 [ F_26 ( V_11 -> V_375 ) ] ;
T_1 V_32 [ F_26 ( V_11 -> V_375 ) ] ;
int V_36 , V_172 , V_170 ;
V_35 = V_11 -> V_15 ;
if ( ! V_35 )
return;
if ( V_11 -> V_46 )
return;
V_460:
V_170 = 0 ;
for ( V_172 = 0 ; V_172 < V_11 -> V_174 ; V_172 ++ ) {
T_1 V_173 = V_11 -> V_175 [ V_172 ] ;
int V_37 = F_16 ( V_2 , V_173 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
T_1 V_41 = V_11 -> V_113 [ V_36 ] ;
if ( V_41 ) {
if ( F_69 ( V_2 , V_173 , V_41 ) < 0 )
break;
} else if ( V_37 <= V_35 -> V_49 [ V_36 ] . V_50 )
break;
}
if ( V_36 >= V_35 -> V_16 ) {
V_26 [ V_170 ] = V_11 -> V_375 [ V_172 ] ;
V_32 [ V_170 ++ ] = V_173 ;
}
}
if ( ! V_170 ) {
if ( ! F_68 ( V_2 ) ) {
if ( V_11 -> V_38 ) {
V_11 -> V_38 = 0 ;
V_11 -> V_171 [ 0 ] . V_16 = 1 ;
goto V_460;
}
F_76 ( V_461 L_63
L_64 ,
V_2 -> V_200 , V_11 -> V_375 [ 0 ] ) ;
V_11 -> V_174 = 1 ;
V_11 -> V_114 = 0 ;
return;
}
} else if ( V_170 != V_11 -> V_174 ) {
memcpy ( V_11 -> V_375 , V_26 ,
V_170 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_175 , V_32 ,
V_170 * sizeof( T_1 ) ) ;
V_11 -> V_174 = V_170 ;
}
if ( V_11 -> V_114 )
F_70 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 || V_11 -> V_38 )
V_11 -> V_174 = 1 ;
}
static void F_229 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_176 ( V_2 , V_3 , V_53 ) ) {
F_14 ( V_2 , V_3 , 0 ,
V_252 ,
F_179 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_176 ( V_2 , V_3 , V_99 ) )
F_14 ( V_2 , V_3 , 0 ,
V_252 ,
V_389 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_384 , V_170 ;
for ( V_384 = 0 ; V_384 < V_11 -> V_174 ; V_384 ++ )
F_229 ( V_2 , V_384 ) ;
if ( V_11 -> V_46 )
V_170 = 1 ;
else
V_170 = V_11 -> V_174 ;
for ( V_384 = 0 ; V_384 < V_170 ; V_384 ++ )
F_13 ( V_2 , V_384 , V_11 -> V_23 [ V_384 ] , true ) ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_36 , V_255 ;
int V_385 = 0 ;
T_1 V_3 ;
const char * V_386 = NULL ;
for ( V_36 = 0 ; V_36 < V_160 -> V_182 ; V_36 ++ ) {
if ( V_160 -> V_40 [ V_36 ] . type > V_58 )
break;
V_3 = V_160 -> V_40 [ V_36 ] . V_41 ;
if ( F_2 ( V_2 , V_3 ) & V_462 ) {
const char * V_387 ;
char V_463 [ 32 ] ;
V_387 = F_172 ( V_2 , V_160 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_387 , L_47 ) )
V_387 = L_48 ;
if ( V_386 && ! strcmp ( V_387 , V_386 ) )
V_385 ++ ;
else
V_385 = 0 ;
V_386 = V_387 ;
snprintf ( V_463 , sizeof( V_463 ) ,
L_65 , V_387 ) ;
V_255 = F_161 ( V_11 , V_372 ,
V_463 , V_385 ,
F_96 ( V_3 , 3 , 0 , V_53 ) ) ;
if ( V_255 < 0 )
return V_255 ;
}
}
return 0 ;
}
static void F_232 ( struct V_1 * V_2 , T_1 V_173 ,
int V_31 )
{
if ( F_17 ( F_2 ( V_2 , V_173 ) ) == V_47 ) {
F_18 ( V_2 , V_173 , V_53 , V_31 ,
V_52 , 0 ) ;
} else if ( F_16 ( V_2 , V_173 , NULL ) > 1 ) {
F_19 ( V_2 , V_173 , 0 ,
V_54 , V_31 ) ;
}
}
static int F_233 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( ! V_41 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_174 ; V_36 ++ ) {
T_1 V_173 = F_12 ( V_11 , V_36 ) ;
int V_31 ;
V_31 = F_69 ( V_2 , V_173 , V_41 ) ;
if ( V_31 < 0 )
continue;
F_232 ( V_2 , V_173 , V_31 ) ;
return V_36 ;
}
return - 1 ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_182 ; V_36 ++ )
F_233 ( V_2 , V_11 -> V_39 . V_40 [ V_36 ] . V_41 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_71 * V_379 [ 2 ] [ 3 ] = {
{ V_464 ,
V_465 ,
V_466 } ,
{ V_467 ,
V_468 ,
V_469 } ,
} ;
if ( ! F_209 ( V_2 , V_11 -> V_26 [ 0 ] , V_53 ) ) {
if ( ! V_11 -> V_32 )
return;
if ( ! F_209 ( V_2 , V_11 -> V_32 [ 0 ] , V_99 ) )
return;
V_11 -> V_267 = 1 ;
}
if ( V_11 -> V_174 > 0 ) {
int V_470 = 0 ;
int V_383 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_470 = 1 ;
if ( V_11 -> V_114 ) {
V_383 = 1 ;
V_470 = 0 ;
} else if ( V_11 -> V_46 )
V_383 = 1 ;
if ( ! V_383 ) {
if ( V_11 -> V_174 > 3 )
V_11 -> V_174 = 3 ;
else if ( ! V_11 -> V_174 )
return;
V_383 = V_11 -> V_174 ;
}
V_11 -> V_279 = V_379 [ V_470 ] [ V_383 - 1 ] ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_218 ( V_2 ) ;
F_219 ( V_2 ) ;
F_178 ( V_2 ) ;
F_230 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_11 -> V_168 )
F_46 ( V_2 ) ;
}
static inline int F_235 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_236 * V_239 ;
V_239 = F_87 ( V_2 -> V_196 -> V_197 , V_471 ) ;
if ( V_239 )
return V_239 -> V_20 ;
return V_11 -> V_189 . V_190 ;
}
static int F_236 ( struct V_1 * V_2 ,
const T_1 * V_472 ,
const T_1 * V_473 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_159 * V_160 = & V_11 -> V_39 ;
int V_255 ;
V_255 = F_237 ( V_2 , V_160 , V_472 ,
V_11 -> V_474 ) ;
if ( V_255 < 0 )
return V_255 ;
if ( ! V_160 -> V_164 ) {
if ( V_160 -> V_246 || V_160 -> V_254 ) {
V_11 -> V_248 . V_456 = 2 ;
V_11 -> V_280 = 1 ;
goto V_475;
}
return 0 ;
}
if ( V_160 -> V_161 == V_162 &&
V_160 -> V_164 <= V_160 -> V_166 ) {
V_160 -> V_163 = V_160 -> V_164 ;
memcpy ( V_160 -> V_107 , V_160 -> V_108 ,
sizeof( V_160 -> V_107 ) ) ;
V_160 -> V_164 = V_160 -> V_166 ;
memcpy ( V_160 -> V_108 , V_160 -> V_103 , sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_166 = 0 ;
memset ( V_160 -> V_103 , 0 , sizeof( V_160 -> V_103 ) ) ;
V_160 -> V_161 = V_165 ;
}
V_255 = F_203 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_227 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_210 ( V_2 , V_160 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_214 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_215 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_174 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_255 = F_171 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
V_11 -> V_248 . V_456 = V_11 -> V_248 . V_314 * 2 ;
V_475:
F_92 ( V_2 ) ;
if ( ! V_11 -> V_280 )
F_228 ( V_2 ) ;
if ( V_473 )
F_80 ( V_2 , V_473 ) ;
if ( ! V_11 -> V_280 ) {
F_74 ( V_2 ) ;
V_255 = F_231 ( V_2 ) ;
if ( V_255 < 0 )
return V_255 ;
}
if ( V_11 -> V_155 . V_169 )
F_24 ( V_11 , V_11 -> V_155 . V_169 ) ;
if ( ! V_11 -> V_280 && ! V_11 -> V_279 )
F_234 ( V_2 ) ;
return 1 ;
}
static int F_238 ( struct V_1 * V_2 )
{
static const T_1 V_476 [] = { 0x1d , 0 } ;
static const T_1 V_477 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_476 , V_477 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 == V_227 )
F_66 ( V_2 , 0x21 , V_131 ) ;
}
static int F_240 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
V_11 -> V_457 = 1 ;
F_86 ( V_2 , V_478 , V_479 ,
V_480 ) ;
F_83 ( V_2 , V_223 ) ;
V_255 = F_238 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_243 ( struct V_1 * V_2 )
{
static const T_1 V_482 [] = { 0x17 , 0 } ;
static const T_1 V_483 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_236 ( V_2 , V_482 , V_483 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_14 ( V_2 , 0x01 , 0 , V_484 ,
V_11 -> V_105 ) ;
}
static void F_245 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_119 == V_227 ) {
V_11 -> V_110 = F_244 ;
V_11 -> V_111 = 1 ;
V_11 -> V_45 = 1 ;
V_11 -> V_39 . V_103 [ 0 ] = 0x0f ;
F_66 ( V_2 , 0x0f , V_120 ) ;
V_11 -> V_168 = F_43 ;
F_27 ( V_2 -> V_11 , V_140 ) ;
}
}
static void F_246 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_214 V_485 [] = {
{ 0x0f , 0x02214000 } ,
{ 0x12 , 0x90a60160 } ,
{ 0x13 , 0x02a19000 } ,
{ 0x18 , 0x01446000 } ,
{ 0x10 , 0x411111f0 } ,
{ 0x11 , 0x411111f0 } ,
{ 0x14 , 0x411111f0 } ,
{ 0x15 , 0x411111f0 } ,
{ 0x16 , 0x411111f0 } ,
{ 0x17 , 0x411111f0 } ,
{ 0x19 , 0x411111f0 } ,
{ }
} ;
switch ( V_119 ) {
case V_223 :
F_81 ( V_2 , V_485 ) ;
break;
case V_227 :
V_11 -> V_212 = V_486 ;
break;
}
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x07 ;
F_86 ( V_2 , NULL , V_487 , V_488 ) ;
F_83 ( V_2 , V_223 ) ;
V_255 = F_243 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x07 , 0x05 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
V_11 -> V_343 = F_51 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static void F_248 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 != V_297 )
return;
F_48 ( V_2 ) ;
}
static void F_249 ( struct V_1 * V_2 , int V_41 , int V_489 )
{
unsigned int V_490 , V_491 , V_492 ;
V_490 = F_22 ( V_2 , V_2 -> V_493 , 0 ,
V_494 , 0 ) ;
if ( ! V_489 )
V_490 |= ( 1 << V_41 ) ;
else
V_490 &= ~ ( 1 << V_41 ) ;
V_491 = F_22 ( V_2 , V_2 -> V_493 , 0 ,
V_495 , 0 ) ;
V_491 |= ( 1 << V_41 ) ;
V_492 = F_22 ( V_2 , V_2 -> V_493 , 0 ,
V_496 , 0 ) ;
V_492 |= ( 1 << V_41 ) ;
F_14 ( V_2 , V_2 -> V_493 , 0 ,
V_497 , V_491 ) ;
F_14 ( V_2 , V_2 -> V_493 , 0 ,
V_498 , V_492 ) ;
F_52 ( 1 ) ;
F_14 ( V_2 , V_2 -> V_493 , 0 ,
V_484 , V_490 ) ;
}
static void F_250 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 != V_297 )
return;
F_249 ( V_2 , 0 , 0 ) ;
F_249 ( V_2 , 1 , 0 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 == V_223 ) {
T_1 V_499 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_500 [ 2 ] = { 0x0e , 0x0f } ;
F_252 ( V_2 , 0x14 , 2 , V_499 ) ;
F_252 ( V_2 , 0x15 , 2 , V_499 ) ;
F_252 ( V_2 , 0x18 , 2 , V_500 ) ;
F_252 ( V_2 , 0x1a , 2 , V_500 ) ;
} else if ( V_119 == V_227 ) {
T_1 V_257 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_252 ( V_2 , 0x14 , 5 , V_257 ) ;
F_252 ( V_2 , 0x15 , 5 , V_257 ) ;
F_252 ( V_2 , 0x18 , 5 , V_257 ) ;
F_252 ( V_2 , 0x1a , 5 , V_257 ) ;
}
}
static void F_253 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_501 [ 2 ] = { 0x14 , 0x15 } ;
int V_36 ;
if ( V_119 != V_297 )
return;
for ( V_36 = 0 ; V_36 < F_26 ( V_501 ) ; V_36 ++ ) {
unsigned int V_56 = F_72 ( V_2 , V_501 [ V_36 ] ) ;
if ( F_254 ( V_56 ) != V_502 )
continue;
V_56 = F_22 ( V_2 , V_501 [ V_36 ] , 0 ,
V_61 , 0 ) ;
V_56 |= V_503 ;
F_14 ( V_2 , V_501 [ V_36 ] , 0 ,
V_42 , V_56 ) ;
V_11 -> V_97 = 1 ;
break;
}
}
static void F_255 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_501 [ 2 ] = { 0x18 , 0x1a } ;
int V_36 ;
if ( V_119 != V_297 )
return;
for ( V_36 = 0 ; V_36 < F_26 ( V_501 ) ; V_36 ++ ) {
unsigned int V_56 ;
V_56 = F_22 ( V_2 , V_501 [ V_36 ] , 0 ,
V_61 , 0 ) ;
V_56 |= V_504 ;
F_14 ( V_2 , V_501 [ V_36 ] , 0 ,
V_42 , V_56 ) ;
}
V_11 -> V_97 = 1 ;
}
static int F_256 ( struct V_1 * V_2 )
{
static const T_1 V_505 [] = { 0x1d , 0 } ;
static const T_1 V_506 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_505 , V_506 ) ;
}
static int F_257 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
switch ( V_2 -> V_130 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
V_255 = F_160 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
F_86 ( V_2 , V_507 , V_508 ,
V_509 ) ;
F_83 ( V_2 , V_223 ) ;
F_75 ( V_2 ) ;
V_255 = F_256 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 && F_235 ( V_2 ) ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_258 ( struct V_1 * V_2 )
{
static const T_1 V_510 [] = { 0x1d , 0 } ;
static const T_1 V_511 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_510 , V_511 ) ;
}
static int F_259 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_86 ( V_2 , NULL , V_512 , V_513 ) ;
F_83 ( V_2 , V_223 ) ;
F_75 ( V_2 ) ;
V_255 = F_258 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 && F_235 ( V_2 ) ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
V_11 -> V_343 = F_51 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_260 ( struct V_1 * V_2 )
{
static const T_1 V_514 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_255 = F_236 ( V_2 , NULL , V_514 ) ;
if ( V_255 > 0 ) {
if ( ! V_11 -> V_280 && V_11 -> V_39 . V_107 [ 0 ] != 0x1d ) {
F_24 ( V_11 , V_515 ) ;
F_27 ( V_11 , V_516 ) ;
}
}
return V_255 ;
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_36 , V_517 , V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_255 = F_260 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
V_517 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
if ( V_11 -> V_74 [ V_36 ] == V_515 ) {
V_517 = 1 ;
break;
}
}
if ( V_517 ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_53 ) )
F_262 ( V_2 , 0x1d , V_53 ,
( 0x0c << V_518 ) |
( 0x0c << V_519 ) |
( 0x07 << V_520 ) |
( 0 << V_521 ) ) ;
}
V_2 -> V_350 = V_481 ;
V_11 -> V_343 = F_51 ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_263 ( struct V_1 * V_2 )
{
static const T_1 V_522 [] = { 0x1d , 0 } ;
static const T_1 V_523 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_524 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_525 = V_11 -> V_526 == V_527 ?
V_524 : V_523 ;
return F_236 ( V_2 , V_522 , V_525 ) ;
}
static void F_264 ( struct V_1 * V_2 , int V_528 )
{
int V_56 = F_88 ( V_2 , 0x04 ) ;
if ( V_528 )
V_56 |= 1 << 11 ;
else
V_56 &= ~ ( 1 << 11 ) ;
F_89 ( V_2 , 0x04 , V_56 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x017 )
F_264 ( V_2 , 0 ) ;
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_264 ( V_2 , 0 ) ;
F_52 ( 150 ) ;
}
}
static int F_266 ( struct V_1 * V_2 )
{
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_264 ( V_2 , 0 ) ;
F_52 ( 150 ) ;
}
V_2 -> V_350 . V_351 ( V_2 ) ;
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_264 ( V_2 , 1 ) ;
F_52 ( 200 ) ;
}
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x018 )
F_264 ( V_2 , 1 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_124 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_267 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
int V_529 ;
if ( V_119 != V_297 )
return;
V_529 = F_88 ( V_2 , 0x1e ) ;
F_89 ( V_2 , 0x1e , V_529 | 0x80 ) ;
}
static void F_268 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
static const struct V_75 V_228 [] = {
{ 0x20 , V_80 , 0x0d } ,
{ 0x20 , V_83 , 0x4000 } ,
{}
} ;
unsigned int V_160 ;
if ( strcmp ( V_2 -> V_200 , L_66 ) )
return;
V_160 = F_72 ( V_2 , 0x12 ) ;
if ( F_221 ( V_160 ) == V_530 )
F_54 ( V_2 , V_228 ) ;
}
static void F_269 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_119 != V_227 )
return;
V_11 -> V_315 = & V_531 ;
V_11 -> V_320 = & V_532 ;
}
static void F_270 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
int V_529 ;
if ( V_119 != V_297 )
return;
V_529 = F_88 ( V_2 , 0x07 ) ;
F_89 ( V_2 , 0x07 , V_529 | 0x80 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_14 ( V_2 , 0x20 , 0 ,
V_80 , 0x0c ) ;
F_14 ( V_2 , 0x20 , 0 ,
V_83 , 0x680 ) ;
F_14 ( V_2 , 0x20 , 0 ,
V_80 , 0x0c ) ;
F_14 ( V_2 , 0x20 , 0 ,
V_83 , 0x480 ) ;
}
static void F_272 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_119 != V_227 )
return;
V_11 -> V_110 = F_271 ;
}
static void F_273 ( void * V_533 , int V_534 )
{
struct V_1 * V_2 = V_533 ;
unsigned int V_535 = V_534 ? 0x20 : 0x24 ;
F_184 ( V_2 , 0x19 , 0 ,
V_42 ,
V_535 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_119 ) {
case V_295 :
V_11 -> V_287 . V_536 = F_273 ;
F_275 ( V_2 , & V_11 -> V_287 , true ) ;
case V_297 :
F_276 ( & V_11 -> V_287 ) ;
break;
}
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_56 ;
if ( V_11 -> V_526 != V_537 )
return;
if ( ( F_90 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_89 ( V_2 , 0xf , 0x960b ) ;
F_89 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_89 ( V_2 , 0xf , 0x960b ) ;
F_89 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_56 = F_88 ( V_2 , 0x04 ) ;
F_89 ( V_2 , 0x04 , V_56 | ( 1 << 11 ) ) ;
}
if ( ( F_90 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_56 = F_88 ( V_2 , 0xd ) ;
if ( ( V_56 & 0x0c00 ) >> 10 != 0x1 ) {
F_89 ( V_2 , 0xd , V_56 | ( 1 << 10 ) ) ;
}
V_56 = F_88 ( V_2 , 0x17 ) ;
if ( ( V_56 & 0x01c0 ) >> 6 != 0x4 ) {
F_89 ( V_2 , 0x17 , V_56 | ( 1 << 7 ) ) ;
}
}
V_56 = F_88 ( V_2 , 0xd ) ;
F_89 ( V_2 , 0xd , V_56 | ( 1 << 14 ) ) ;
V_56 = F_88 ( V_2 , 0x4 ) ;
F_89 ( V_2 , 0x4 , V_56 | ( 1 << 11 ) ) ;
}
static int F_278 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 = 0 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
V_255 = F_160 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( V_2 -> V_130 == 0x10ec0269 ) {
V_11 -> V_526 = V_527 ;
switch ( F_90 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_196 -> V_197 -> V_538 == 0x1025 &&
V_11 -> V_189 . V_205 == 1 )
V_255 = F_159 ( V_2 , L_66 ) ;
V_11 -> V_526 = V_537 ;
break;
case 0x0020 :
if ( V_2 -> V_196 -> V_197 -> V_538 == 0x17aa &&
V_2 -> V_196 -> V_197 -> V_198 == 0x21f3 )
V_255 = F_159 ( V_2 , L_67 ) ;
V_11 -> V_526 = V_539 ;
break;
default:
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_255 < 0 )
goto error;
V_11 -> V_296 = F_277 ;
F_277 ( V_2 ) ;
}
F_86 ( V_2 , V_540 ,
V_541 , V_542 ) ;
F_83 ( V_2 , V_223 ) ;
F_75 ( V_2 ) ;
V_255 = F_263 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 && F_235 ( V_2 ) ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x0b , 0x04 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
#ifdef F_279
V_2 -> V_350 . V_543 = F_266 ;
#endif
V_11 -> V_343 = F_265 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_280 ( struct V_1 * V_2 )
{
static const T_1 V_544 [] = { 0x1d , 0 } ;
static const T_1 V_545 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_236 ( V_2 , V_544 , V_545 ) ;
}
static void F_281 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 ;
if ( V_119 != V_297 )
return;
V_56 = F_22 ( V_2 , 0x0f , 0 ,
V_61 , 0 ) ;
if ( ! ( V_56 & ( V_546 | V_547 ) ) )
V_56 |= V_546 ;
V_56 |= V_504 ;
F_14 ( V_2 , 0x0f , 0 ,
V_42 , V_56 ) ;
V_11 -> V_97 = 1 ;
}
static void F_282 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 == V_223 )
V_2 -> V_548 = 1 ;
}
static int F_283 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x15 ;
F_86 ( V_2 , NULL , V_549 , V_550 ) ;
F_83 ( V_2 , V_223 ) ;
V_255 = F_280 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 ) {
V_255 = F_241 ( V_2 , 0x23 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x23 , 0 , V_99 ) ;
}
V_2 -> V_350 = V_481 ;
#ifdef F_284
V_11 -> V_349 = F_154 ;
#endif
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_285 ( struct V_1 * V_2 )
{
static const T_1 V_551 [] = { 0x1d , 0 } ;
static const T_1 V_552 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_551 , V_552 ) ;
}
static void F_286 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 == V_223 ) {
F_287 ( V_2 , 0x18 , 0x00001714 ) ;
F_287 ( V_2 , 0x19 , 0x0000171c ) ;
}
}
static int F_288 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
F_86 ( V_2 , NULL , V_553 , V_554 ) ;
F_83 ( V_2 , V_223 ) ;
V_255 = F_285 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( V_2 -> V_130 == 0x10ec0660 ) {
F_27 ( V_11 , V_555 ) ;
}
if ( ! V_11 -> V_280 ) {
V_255 = F_241 ( V_2 , 0x23 ) ;
if ( V_255 < 0 )
goto error;
F_242 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_350 = V_481 ;
V_11 -> V_343 = F_51 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_289 ( struct V_1 * V_2 )
{
static const T_1 V_556 [] = { 0x1d , 0 } ;
static const T_1 V_557 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_558 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_525 ;
if ( V_2 -> V_130 == 0x10ec0272 || V_2 -> V_130 == 0x10ec0663 ||
V_2 -> V_130 == 0x10ec0665 || V_2 -> V_130 == 0x10ec0670 )
V_525 = V_557 ;
else
V_525 = V_558 ;
return F_236 ( V_2 , V_556 , V_525 ) ;
}
static void F_290 ( struct V_1 * V_2 ,
const struct V_220 * V_221 , int V_119 )
{
if ( V_119 != V_227 )
return;
if ( F_262 ( V_2 , 0x2 , V_99 ,
( 0x3b << V_518 ) |
( 0x3b << V_519 ) |
( 0x03 << V_520 ) |
( 0 << V_521 ) ) )
F_76 ( V_461
L_68 ) ;
}
static int F_291 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 = 0 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( ! V_11 )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_382 = 0x0b ;
V_11 -> V_474 = V_559 ;
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_255 = F_160 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ( F_90 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_196 -> V_197 -> V_538 == 0x1025 &&
V_11 -> V_189 . V_205 == 1 ) {
if ( F_159 ( V_2 , L_69 ) < 0 )
goto error;
}
F_86 ( V_2 , V_560 ,
V_561 , V_562 ) ;
F_83 ( V_2 , V_223 ) ;
F_75 ( V_2 ) ;
V_255 = F_289 ( V_2 ) ;
if ( V_255 < 0 )
goto error;
if ( ! V_11 -> V_280 && F_235 ( V_2 ) ) {
V_255 = F_241 ( V_2 , 0x1 ) ;
if ( V_255 < 0 )
goto error;
switch ( V_2 -> V_130 ) {
case 0x10ec0662 :
F_242 ( V_11 , 0x0b , 0x05 , V_53 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_242 ( V_11 , 0x0b , 0x04 , V_53 ) ;
break;
case 0x10ec0273 :
F_242 ( V_11 , 0x0b , 0x03 , V_53 ) ;
break;
}
}
V_2 -> V_350 = V_481 ;
V_11 -> V_343 = F_51 ;
F_83 ( V_2 , V_227 ) ;
return 0 ;
error:
F_152 ( V_2 ) ;
return V_255 ;
}
static int F_292 ( struct V_1 * V_2 )
{
return F_236 ( V_2 , NULL , NULL ) ;
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_255 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_125 ) ;
if ( V_11 == NULL )
return - V_157 ;
V_2 -> V_11 = V_11 ;
V_255 = F_292 ( V_2 ) ;
if ( V_255 < 0 ) {
F_152 ( V_2 ) ;
return V_255 ;
}
V_2 -> V_350 = V_481 ;
return 0 ;
}
static int T_5 F_294 ( void )
{
return F_295 ( & V_563 ) ;
}
static void T_6 F_296 ( void )
{
F_297 ( & V_563 ) ;
}
