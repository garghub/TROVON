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
F_9 ( V_2 , V_31 ) ;
V_19 = V_11 -> V_27 [ V_31 ] ;
}
V_3 = F_12 ( V_11 , V_19 ) ;
V_37 = F_14 ( V_2 , V_3 , NULL ) ;
if ( V_37 <= 1 )
return 1 ;
type = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( type == V_39 ) {
int V_40 = V_35 -> V_41 [ V_31 ] . V_42 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
unsigned int V_43 = ( V_36 == V_40 ) ? 0 : V_44 ;
F_16 ( V_2 , V_3 , V_45 , V_36 ,
V_44 , V_43 ) ;
}
} else {
F_17 ( V_2 , V_3 , 0 ,
V_46 ,
V_35 -> V_41 [ V_31 ] . V_42 ) ;
}
return 1 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
return F_13 ( V_2 , V_19 ,
V_18 -> V_20 . V_21 . V_22 [ 0 ] , false ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_3 ,
int V_47 )
{
unsigned int V_48 = V_49 ;
if ( V_47 == V_50 ) {
unsigned int V_51 ;
unsigned int V_52 ;
V_52 = F_20 ( V_2 , V_3 , 0 ,
V_53 , 0 ) ;
V_51 = F_21 ( V_2 , V_3 ) ;
V_51 = ( V_51 & V_54 ) >> V_55 ;
if ( ( V_51 & V_56 ) && V_52 != V_57 )
V_48 = V_58 ;
else if ( V_51 & V_59 )
V_48 = V_57 ;
else if ( V_51 & V_60 )
V_48 = V_61 ;
else if ( V_51 & V_62 )
V_48 = V_63 ;
}
F_22 ( V_2 , V_3 , 0 , V_64 , V_48 ) ;
}
static void F_23 ( struct V_10 * V_11 , const struct V_65 * V_66 )
{
if ( F_24 ( V_11 -> V_67 >= F_25 ( V_11 -> V_68 ) ) )
return;
V_11 -> V_68 [ V_11 -> V_67 ++ ] = V_66 ;
}
static void F_26 ( struct V_10 * V_11 , const struct V_69 * V_70 )
{
if ( F_24 ( V_11 -> V_71 >= F_25 ( V_11 -> V_72 ) ) )
return;
V_11 -> V_72 [ V_11 -> V_71 ++ ] = V_70 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_48 ;
if ( ! V_11 -> V_73 )
return;
F_22 ( V_2 , V_11 -> V_73 , 0 , V_74 ,
V_11 -> V_75 ) ;
V_48 = F_20 ( V_2 , V_11 -> V_73 , 0 ,
V_76 , 0 ) ;
F_22 ( V_2 , V_11 -> V_73 , 0 , V_74 ,
V_11 -> V_75 ) ;
F_22 ( V_2 , V_11 -> V_73 , 0 , V_77 ,
V_48 & ~ ( 1 << V_11 -> V_78 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_73 = V_3 ;
V_11 -> V_75 = V_79 ;
V_11 -> V_78 = V_80 ;
F_27 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
#ifdef F_30
struct V_10 * V_11 = V_2 -> V_11 ;
int V_81 ;
unsigned int V_82 = V_11 -> V_83 . V_84 [ 0 ] ;
unsigned int V_85 = V_11 -> V_86 ;
unsigned int V_87 = V_11 -> V_88 ;
if ( V_82 ) {
V_81 = F_31 ( V_2 , V_82 ,
V_89 , NULL ) ;
if ( V_81 < 0 )
return V_81 ;
F_32 ( V_2 , V_82 ) ;
}
if ( V_85 ) {
V_81 = F_31 ( V_2 , V_85 ,
V_90 , NULL ) ;
if ( V_81 < 0 )
return V_81 ;
F_32 ( V_2 , V_85 ) ;
}
if ( V_87 ) {
V_81 = F_31 ( V_2 , V_87 ,
V_90 , NULL ) ;
if ( V_81 < 0 )
return V_81 ;
F_32 ( V_2 , V_87 ) ;
}
#endif
return 0 ;
}
static bool F_33 ( struct V_1 * V_2 , int V_91 , T_1 * V_92 )
{
int V_36 , V_93 = 0 ;
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
T_1 V_3 = V_92 [ V_36 ] ;
if ( ! V_3 )
break;
F_32 ( V_2 , V_3 ) ;
V_93 |= F_34 ( V_2 , V_3 ) ;
}
return V_93 ;
}
static void F_35 ( struct V_1 * V_2 , int V_91 , T_1 * V_92 ,
bool V_94 , bool V_95 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_96 = V_94 ? V_44 : 0 ;
unsigned int V_97 = V_94 ? 0 : ( V_95 ? V_98 : V_99 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
T_1 V_3 = V_92 [ V_36 ] ;
if ( ! V_3 )
break;
switch ( V_11 -> V_100 ) {
case V_101 :
F_22 ( V_2 , V_3 , 0 ,
V_64 ,
V_97 ) ;
break;
case V_102 :
F_16 ( V_2 , V_3 , V_103 , 0 ,
V_44 , V_96 ) ;
break;
case V_104 :
V_3 = V_11 -> V_105 [ V_36 ] ;
if ( ! V_3 )
break;
F_16 ( V_2 , V_3 , V_45 , 0 ,
V_44 , V_96 ) ;
F_16 ( V_2 , V_3 , V_45 , 1 ,
V_44 , V_96 ) ;
break;
}
}
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_106 ;
F_35 ( V_2 , F_25 ( V_11 -> V_83 . V_84 ) ,
V_11 -> V_83 . V_84 , V_11 -> V_107 , true ) ;
if ( ! V_11 -> V_108 )
V_106 = 0 ;
else
V_106 = V_11 -> V_109 | V_11 -> V_110 ;
V_106 |= V_11 -> V_107 ;
F_35 ( V_2 , F_25 ( V_11 -> V_83 . V_111 ) ,
V_11 -> V_83 . V_111 , V_106 , false ) ;
if ( V_11 -> V_83 . V_112 [ 0 ] == V_11 -> V_83 . V_84 [ 0 ] ||
V_11 -> V_83 . V_112 [ 0 ] == V_11 -> V_83 . V_111 [ 0 ] )
return;
if ( ! V_11 -> V_113 )
V_106 = 0 ;
else
V_106 = V_11 -> V_109 ;
V_106 |= V_11 -> V_107 ;
F_35 ( V_2 , F_25 ( V_11 -> V_83 . V_112 ) ,
V_11 -> V_83 . V_112 , V_106 , false ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_114 )
V_11 -> V_114 ( V_2 ) ;
else
F_36 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_109 =
F_33 ( V_2 , F_25 ( V_11 -> V_83 . V_84 ) ,
V_11 -> V_83 . V_84 ) ;
if ( ! V_11 -> V_115 || ( ! V_11 -> V_108 && ! V_11 -> V_113 ) )
return;
F_37 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_83 . V_112 [ 0 ] == V_11 -> V_83 . V_84 [ 0 ] )
return;
V_11 -> V_110 =
F_33 ( V_2 , F_25 ( V_11 -> V_83 . V_112 ) ,
V_11 -> V_83 . V_112 ) ;
if ( ! V_11 -> V_108 || ! V_11 -> V_116 )
return;
F_37 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_92 = V_11 -> V_117 ;
if ( ! V_11 -> V_118 || ! V_11 -> V_119 )
return;
if ( F_24 ( ! V_11 -> V_26 ) )
return;
if ( F_24 ( V_11 -> V_120 < 0 || V_11 -> V_121 < 0 ) )
return;
if ( F_34 ( V_2 , V_92 [ V_11 -> V_121 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_121 , false ) ;
else if ( V_11 -> V_122 >= 0 &&
F_34 ( V_2 , V_92 [ V_11 -> V_122 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_122 , false ) ;
else
F_13 ( V_2 , 0 , V_11 -> V_120 , false ) ;
F_32 ( V_2 , V_92 [ V_11 -> V_121 ] ) ;
if ( V_11 -> V_122 >= 0 )
F_32 ( V_2 , V_92 [ V_11 -> V_122 ] ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_123 )
{
if ( V_2 -> V_124 == 0x10ec0880 )
V_123 >>= 28 ;
else
V_123 >>= 26 ;
switch ( V_123 ) {
case V_125 :
F_38 ( V_2 ) ;
break;
case V_126 :
F_39 ( V_2 ) ;
break;
case V_127 :
F_40 ( V_2 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned int V_128 ;
F_22 ( V_2 , 0x20 , 0 , V_74 , 0 ) ;
V_128 = F_20 ( V_2 , 0x20 , 0 , V_76 , 0 ) ;
F_22 ( V_2 , 0x20 , 0 , V_74 , 7 ) ;
if ( ( V_128 & 0xf0 ) == 0x20 )
F_20 ( V_2 , 0x20 , 0 ,
V_77 , 0x830 ) ;
else
F_20 ( V_2 , 0x20 , 0 ,
V_77 , 0x3030 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
unsigned int V_128 ;
F_22 ( V_2 , 0x20 , 0 , V_74 , 7 ) ;
V_128 = F_20 ( V_2 , 0x20 , 0 , V_76 , 0 ) ;
F_22 ( V_2 , 0x20 , 0 , V_74 , 7 ) ;
F_22 ( V_2 , 0x20 , 0 , V_77 , V_128 | 0x2010 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_3 , int V_106 )
{
if ( F_15 ( F_2 ( V_2 , V_3 ) ) != V_129 )
return;
if ( F_21 ( V_2 , V_3 ) & V_130 )
F_22 ( V_2 , V_3 , 0 , V_131 ,
V_106 ? 2 : 0 ) ;
}
static void F_46 ( struct V_1 * V_2 , bool V_106 )
{
static T_1 V_92 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_132 ;
for ( V_132 = V_92 ; * V_132 ; V_132 ++ )
F_45 ( V_2 , * V_132 , V_106 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_2 , false ) ;
F_48 ( 200 ) ;
}
static void F_49 ( struct V_1 * V_2 , int type )
{
unsigned int V_128 ;
F_46 ( V_2 , true ) ;
switch ( type ) {
case V_133 :
F_50 ( V_2 , V_134 ) ;
break;
case V_135 :
F_50 ( V_2 , V_136 ) ;
break;
case V_137 :
F_50 ( V_2 , V_138 ) ;
break;
case V_139 :
switch ( V_2 -> V_124 ) {
case 0x10ec0260 :
F_22 ( V_2 , 0x1a , 0 ,
V_74 , 7 ) ;
V_128 = F_20 ( V_2 , 0x1a , 0 ,
V_76 , 0 ) ;
F_22 ( V_2 , 0x1a , 0 ,
V_74 , 7 ) ;
F_22 ( V_2 , 0x1a , 0 ,
V_77 ,
V_128 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_44 ( V_2 ) ;
break;
case 0x10ec0888 :
F_43 ( V_2 ) ;
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
static int F_51 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_140 [] = {
L_1 , L_2
} ;
static const char * const V_141 [] = {
L_1 , L_3 , L_4
} ;
const char * const * V_142 ;
V_9 -> type = V_143 ;
V_9 -> V_144 = 1 ;
if ( V_11 -> V_145 && V_11 -> V_146 ) {
V_9 -> V_20 . V_21 . V_41 = 3 ;
V_142 = V_141 ;
} else {
V_9 -> V_20 . V_21 . V_41 = 2 ;
V_142 = V_140 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_41 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_41 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_147 ,
V_142 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_48 = 0 ;
if ( V_11 -> V_108 )
V_48 ++ ;
if ( V_11 -> V_113 )
V_48 ++ ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_48 ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_18 -> V_20 . V_21 . V_22 [ 0 ] ) {
case 0 :
if ( ! V_11 -> V_108 && ! V_11 -> V_113 )
return 0 ;
V_11 -> V_108 = 0 ;
V_11 -> V_113 = 0 ;
break;
case 1 :
if ( V_11 -> V_145 ) {
if ( ! V_11 -> V_113 && V_11 -> V_108 )
return 0 ;
V_11 -> V_108 = 1 ;
V_11 -> V_113 = 0 ;
} else if ( V_11 -> V_146 ) {
if ( V_11 -> V_113 )
return 0 ;
V_11 -> V_113 = 1 ;
} else
return - V_148 ;
break;
case 2 :
if ( ! V_11 -> V_146 || ! V_11 -> V_145 )
return - V_148 ;
if ( V_11 -> V_108 && V_11 -> V_113 )
return 0 ;
V_11 -> V_108 = 1 ;
V_11 -> V_113 = 1 ;
break;
default:
return - V_148 ;
}
F_37 ( V_2 ) ;
return 1 ;
}
static struct V_65 * F_54 ( struct V_10 * V_11 )
{
F_55 ( & V_11 -> V_149 , sizeof( struct V_65 ) , 32 ) ;
return F_56 ( & V_11 -> V_149 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_65 * V_150 ;
V_150 = F_54 ( V_11 ) ;
if ( ! V_150 )
return - V_151 ;
* V_150 = V_152 ;
V_150 -> V_147 = F_58 ( L_5 , V_153 ) ;
if ( ! V_150 -> V_147 )
return - V_151 ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
int V_93 = 0 ;
int V_36 ;
if ( V_155 -> V_84 [ 0 ] )
V_93 ++ ;
if ( V_155 -> V_112 [ 0 ] )
V_93 ++ ;
if ( V_155 -> V_111 [ 0 ] )
V_93 ++ ;
if ( V_93 < 2 )
return;
if ( ! V_155 -> V_111 [ 0 ] &&
V_155 -> V_156 == V_157 ) {
memcpy ( V_155 -> V_111 , V_155 -> V_112 ,
sizeof( V_155 -> V_111 ) ) ;
V_155 -> V_158 = V_155 -> V_159 ;
}
if ( ! V_155 -> V_84 [ 0 ] &&
V_155 -> V_156 == V_160 ) {
memcpy ( V_155 -> V_84 , V_155 -> V_112 ,
sizeof( V_155 -> V_84 ) ) ;
V_155 -> V_161 = V_155 -> V_159 ;
}
V_11 -> V_100 = V_101 ;
for ( V_36 = 0 ; V_36 < V_155 -> V_161 ; V_36 ++ ) {
T_1 V_3 = V_155 -> V_84 [ V_36 ] ;
if ( ! F_60 ( V_2 , V_3 ) )
continue;
F_61 ( L_6 ,
V_3 ) ;
F_17 ( V_2 , V_3 , 0 ,
V_162 ,
V_163 | V_125 ) ;
V_11 -> V_115 = 1 ;
}
if ( V_155 -> V_156 == V_164 && V_155 -> V_159 ) {
if ( V_155 -> V_158 )
for ( V_36 = 0 ; V_36 < V_155 -> V_159 ; V_36 ++ ) {
T_1 V_3 = V_155 -> V_112 [ V_36 ] ;
if ( ! F_60 ( V_2 , V_3 ) )
continue;
F_61 ( L_7
L_8 , V_3 ) ;
F_17 ( V_2 , V_3 , 0 ,
V_162 ,
V_163 | V_126 ) ;
V_11 -> V_116 = 1 ;
}
V_11 -> V_146 = V_11 -> V_115 ;
}
V_11 -> V_145 = V_155 -> V_158 &&
( V_11 -> V_115 || V_11 -> V_116 ) ;
V_11 -> V_113 = V_11 -> V_146 ;
V_11 -> V_108 = V_11 -> V_145 ;
if ( V_11 -> V_145 || V_11 -> V_146 ) {
F_57 ( V_2 ) ;
V_11 -> V_165 = F_41 ;
}
}
static int F_62 ( T_1 V_3 , const T_1 * V_166 , int V_167 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_167 ; V_36 ++ )
if ( V_166 [ V_36 ] == V_3 )
return V_36 ;
return - 1 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 = & V_11 -> V_168 [ 0 ] ;
int V_36 , V_169 , V_31 ;
T_1 V_170 , V_171 ;
if ( V_35 != V_11 -> V_15 )
return false ;
for ( V_169 = 0 ; V_169 < V_11 -> V_172 ; V_169 ++ ) {
V_170 = V_11 -> V_173 [ V_169 ] ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_171 = V_11 -> V_117 [ V_36 ] ;
if ( ! V_171 )
return false ;
if ( F_64 ( V_2 , V_170 , V_171 ) < 0 )
break;
}
if ( V_36 >= V_35 -> V_16 )
return true ;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_171 = V_11 -> V_117 [ V_36 ] ;
for ( V_169 = 0 ; V_169 < V_11 -> V_172 ; V_169 ++ ) {
V_170 = V_11 -> V_173 [ V_169 ] ;
V_31 = F_64 ( V_2 , V_170 , V_171 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_41 [ V_36 ] . V_42 = V_31 ;
V_11 -> V_27 [ V_36 ] = V_169 ;
break;
}
}
}
F_61 ( L_9 ) ;
V_11 -> V_38 = 1 ;
return true ;
}
static bool F_65 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 ;
static char * const V_142 [ 3 ] = {
L_10 , L_11 , L_12
} ;
int V_36 ;
if ( ! V_11 -> V_118 )
return false ;
V_35 = & V_11 -> V_168 [ 0 ] ;
if ( V_11 -> V_15 == V_35 )
return true ;
V_11 -> V_117 [ 0 ] = V_11 -> V_86 ;
V_11 -> V_117 [ 1 ] = V_11 -> V_174 ;
V_11 -> V_117 [ 2 ] = V_11 -> V_88 ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ ) {
strcpy ( V_35 -> V_41 [ V_36 ] . V_175 , V_142 [ V_36 ] ) ;
if ( V_11 -> V_117 [ V_36 ] ) {
T_1 V_171 = V_11 -> V_117 [ V_36 ] ;
int V_176 ;
for ( V_176 = 0 ; V_176 < V_11 -> V_172 ; V_176 ++ ) {
T_1 V_170 = F_12 ( V_11 , V_176 ) ;
int V_31 = F_64 ( V_2 , V_170 , V_171 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_41 [ V_36 ] . V_42 = V_31 ;
break;
}
}
V_35 -> V_16 = V_36 + 1 ;
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_35 ;
return true ;
}
static bool F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
if ( ! V_11 -> V_118 )
return false ;
if ( V_11 -> V_119 )
return true ;
if ( ! F_63 ( V_2 ) ) {
V_11 -> V_118 = 0 ;
return false ;
}
V_35 = V_11 -> V_15 ;
V_11 -> V_121 = F_62 ( V_11 -> V_86 ,
V_11 -> V_117 , V_35 -> V_16 ) ;
V_11 -> V_120 = F_62 ( V_11 -> V_174 ,
V_11 -> V_117 , V_35 -> V_16 ) ;
V_11 -> V_122 = F_62 ( V_11 -> V_88 ,
V_11 -> V_117 , V_35 -> V_16 ) ;
if ( V_11 -> V_121 < 0 || V_11 -> V_120 < 0 ) {
V_11 -> V_118 = 0 ;
return false ;
}
F_17 ( V_2 , V_11 -> V_86 , 0 ,
V_162 ,
V_163 | V_127 ) ;
if ( V_11 -> V_88 )
F_17 ( V_2 , V_11 -> V_88 , 0 ,
V_162 ,
V_163 | V_127 ) ;
V_11 -> V_119 = 1 ;
V_11 -> V_118 = 1 ;
return true ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
T_1 V_177 , V_178 , V_179 ;
int V_36 ;
V_11 -> V_121 = V_11 -> V_120 = V_11 -> V_122 = - 1 ;
V_177 = V_178 = V_179 = 0 ;
for ( V_36 = 0 ; V_36 < V_155 -> V_180 ; V_36 ++ ) {
T_1 V_3 = V_155 -> V_181 [ V_36 ] . V_171 ;
unsigned int V_182 ;
V_182 = F_68 ( V_2 , V_3 ) ;
switch ( F_69 ( V_182 ) ) {
case V_183 :
if ( V_177 )
return;
if ( V_155 -> V_181 [ V_36 ] . type != V_50 )
return;
V_177 = V_3 ;
break;
case V_184 :
return;
case V_185 :
if ( V_179 )
return;
if ( V_155 -> V_181 [ V_36 ] . type > V_186 )
return;
V_179 = V_3 ;
break;
default:
if ( V_178 )
return;
if ( V_155 -> V_181 [ V_36 ] . type != V_50 )
return;
V_178 = V_3 ;
break;
}
}
if ( ! V_178 && V_179 ) {
V_178 = V_179 ;
V_179 = 0 ;
}
if ( ! V_178 || ! V_177 )
return;
if ( ! F_60 ( V_2 , V_178 ) )
return;
if ( V_179 && ! F_60 ( V_2 , V_179 ) )
return;
V_11 -> V_86 = V_178 ;
V_11 -> V_174 = V_177 ;
V_11 -> V_88 = V_179 ;
V_11 -> V_118 = 1 ;
if ( ! F_66 ( V_2 ) )
return;
F_61 ( L_13 ,
V_178 , V_177 , V_179 ) ;
V_11 -> V_165 = F_41 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_67 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned int V_187 , V_128 , V_36 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_188 . V_189 = 1 ;
if ( V_11 -> V_188 . V_190 ) {
V_187 = V_11 -> V_188 . V_191 ;
if ( V_187 == V_192 )
return - 1 ;
goto V_193;
}
V_187 = V_2 -> V_194 & 0xffff ;
if ( V_187 != V_2 -> V_195 -> V_196 -> V_197 && ( V_187 & 1 ) )
goto V_193;
V_3 = 0x1d ;
if ( V_2 -> V_124 == 0x10ec0260 )
V_3 = 0x17 ;
V_187 = F_68 ( V_2 , V_3 ) ;
if ( ! ( V_187 & 1 ) ) {
F_72 ( V_198 L_14 ,
V_2 -> V_199 , V_187 ) ;
return - 1 ;
}
V_128 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_187 >> V_36 ) & 1 )
V_128 ++ ;
}
if ( ( ( V_187 >> 16 ) & 0xf ) != V_128 )
return - 1 ;
V_11 -> V_188 . V_200 = V_187 >> 30 ;
V_11 -> V_188 . V_189 = ( V_187 & 0x100000 ) >> 20 ;
V_11 -> V_188 . V_201 = ( V_187 >> 16 ) & 0xf ;
V_11 -> V_188 . V_202 = V_187 >> 8 ;
V_193:
V_11 -> V_188 . V_191 = V_187 ;
V_11 -> V_188 . V_203 = ( V_187 & 0x38 ) >> 3 ;
V_11 -> V_188 . V_204 = ( V_187 & 0x4 ) >> 2 ;
V_11 -> V_188 . V_205 = ( V_187 & 0x2 ) >> 1 ;
V_11 -> V_188 . V_206 = V_187 & 0x1 ;
F_73 ( L_15 ,
V_3 , V_11 -> V_188 . V_191 ) ;
F_73 ( L_16 ,
V_11 -> V_188 . V_200 ) ;
F_73 ( L_17 , V_11 -> V_188 . V_189 ) ;
F_73 ( L_18 , V_11 -> V_188 . V_201 ) ;
F_73 ( L_19 , V_11 -> V_188 . V_202 ) ;
F_73 ( L_20 , V_11 -> V_188 . V_203 ) ;
F_73 ( L_21 , V_11 -> V_188 . V_204 ) ;
F_73 ( L_22 , V_11 -> V_188 . V_205 ) ;
F_73 ( L_23 , V_11 -> V_188 . V_206 ) ;
return 0 ;
}
static bool F_74 ( T_1 V_3 , const T_1 * V_166 , int V_167 )
{
return F_62 ( V_3 , V_166 , V_167 ) >= 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_1 V_207 , T_1 V_208 ,
T_1 V_209 , T_1 V_210 )
{
unsigned int V_187 , V_128 , V_36 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_188 . V_190 ) {
V_187 = V_11 -> V_188 . V_191 ;
if ( V_187 == V_192 )
return 0 ;
goto V_193;
}
V_187 = V_2 -> V_194 & 0xffff ;
if ( ( V_187 != V_2 -> V_195 -> V_196 -> V_197 ) && ( V_187 & 1 ) )
goto V_193;
V_3 = 0x1d ;
if ( V_2 -> V_124 == 0x10ec0260 )
V_3 = 0x17 ;
V_187 = F_68 ( V_2 , V_3 ) ;
F_73 ( L_24
L_25 ,
V_187 , V_3 ) ;
if ( ! ( V_187 & 1 ) )
return 0 ;
if ( ( V_187 >> 30 ) != 1 )
return 0 ;
V_128 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_187 >> V_36 ) & 1 )
V_128 ++ ;
}
if ( ( ( V_187 >> 16 ) & 0xf ) != V_128 )
return 0 ;
V_193:
F_73 ( L_26 ,
V_187 & 0xffff , V_2 -> V_124 ) ;
V_128 = ( V_187 & 0x38 ) >> 3 ;
switch ( V_128 ) {
case 1 :
V_11 -> V_211 = V_133 ;
break;
case 3 :
V_11 -> V_211 = V_135 ;
break;
case 7 :
V_11 -> V_211 = V_137 ;
break;
case 5 :
default:
V_11 -> V_211 = V_139 ;
break;
}
if ( ! ( V_187 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_83 . V_84 [ 0 ] &&
! ( V_11 -> V_83 . V_112 [ 0 ] &&
V_11 -> V_83 . V_156 == V_160 ) ) {
T_1 V_3 ;
V_128 = ( V_187 >> 11 ) & 0x3 ;
if ( V_128 == 0 )
V_3 = V_207 ;
else if ( V_128 == 1 )
V_3 = V_208 ;
else if ( V_128 == 2 )
V_3 = V_209 ;
else if ( V_128 == 3 )
V_3 = V_210 ;
else
return 1 ;
if ( F_74 ( V_3 , V_11 -> V_83 . V_112 ,
V_11 -> V_83 . V_159 ) )
return 1 ;
V_11 -> V_83 . V_84 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_76 ( struct V_1 * V_2 , const T_1 * V_212 )
{
if ( ! F_75 ( V_2 , V_212 [ 0 ] , V_212 [ 1 ] , V_212 [ 2 ] , V_212 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_73 ( L_27
L_28 ) ;
V_11 -> V_211 = V_139 ;
}
}
static void F_77 ( struct V_1 * V_2 , int V_213 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = V_11 -> V_214 ;
#ifdef F_78
const char * V_215 = V_11 -> V_216 ;
#endif
int V_217 = 0 ;
if ( ! V_11 -> V_218 )
return;
while ( V_13 >= 0 ) {
const struct V_219 * V_220 = V_11 -> V_218 + V_13 ;
const struct V_221 * V_155 ;
switch ( V_220 -> type ) {
case V_222 :
if ( V_213 != V_223 || ! V_220 -> V_43 . V_224 )
break;
F_61 ( V_198 L_29
L_30 ,
V_2 -> V_199 , V_215 ) ;
V_11 -> V_188 . V_191 = V_220 -> V_43 . V_224 ;
V_11 -> V_188 . V_190 = 1 ;
break;
case V_225 :
V_155 = V_220 -> V_43 . V_92 ;
if ( V_213 != V_223 || ! V_155 )
break;
F_61 ( V_198 L_29
L_31 ,
V_2 -> V_199 , V_215 ) ;
for (; V_155 -> V_3 ; V_155 ++ )
F_79 ( V_2 , V_155 -> V_3 ,
V_155 -> V_48 ) ;
break;
case V_226 :
if ( V_213 != V_227 || ! V_220 -> V_43 . V_228 )
break;
F_61 ( V_198 L_29
L_32 ,
V_2 -> V_199 , V_215 ) ;
F_26 ( V_2 -> V_11 , V_220 -> V_43 . V_228 ) ;
break;
case V_229 :
if ( ! V_220 -> V_43 . V_230 )
break;
F_61 ( V_198 L_29
L_33 ,
V_2 -> V_199 , V_215 ) ;
V_220 -> V_43 . V_230 ( V_2 , V_220 , V_213 ) ;
break;
default:
F_80 ( V_231 L_29
L_34 ,
V_2 -> V_199 , V_220 -> type ) ;
break;
}
if ( ! V_220 -> V_232 )
break;
if ( ++ V_217 > 10 )
break;
V_13 = V_220 -> V_233 ;
}
}
static void F_81 ( struct V_1 * V_2 ,
const struct V_234 * V_235 ,
const struct V_236 * V_237 ,
const struct V_219 * V_238 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = - 1 ;
const char * V_147 = NULL ;
if ( V_2 -> V_215 && V_235 ) {
while ( V_235 -> V_147 ) {
if ( ! strcmp ( V_2 -> V_215 , V_235 -> V_147 ) ) {
V_13 = V_235 -> V_13 ;
V_147 = V_235 -> V_147 ;
break;
}
V_235 ++ ;
}
}
if ( V_13 < 0 ) {
V_237 = F_82 ( V_2 -> V_195 -> V_196 , V_237 ) ;
if ( V_237 ) {
V_13 = V_237 -> V_20 ;
#ifdef F_78
V_147 = V_237 -> V_147 ;
#endif
}
}
V_11 -> V_214 = V_13 ;
if ( V_13 >= 0 ) {
V_11 -> V_218 = V_238 ;
V_11 -> V_216 = V_147 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
unsigned int V_79 )
{
unsigned int V_48 ;
F_22 ( V_2 , 0x20 , 0 , V_74 ,
V_79 ) ;
V_48 = F_20 ( V_2 , 0x20 , 0 ,
V_76 , 0 ) ;
return V_48 ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_79 ,
unsigned int V_239 )
{
F_22 ( V_2 , 0x20 , 0 , V_74 ,
V_79 ) ;
F_22 ( V_2 , 0x20 , 0 , V_77 ,
V_239 ) ;
}
static unsigned int F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_240 )
V_11 -> V_240 = F_83 ( V_2 , 0 ) ;
return V_11 -> V_240 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_171 , V_241 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_83 . V_242 ; V_36 ++ ) {
V_171 = V_11 -> V_83 . V_243 [ V_36 ] ;
if ( ! V_171 )
continue;
F_22 ( V_2 , V_171 , 0 ,
V_64 , V_99 ) ;
if ( ! V_36 )
V_241 = V_11 -> V_244 . V_245 ;
else
V_241 = V_11 -> V_246 [ V_36 - 1 ] ;
if ( ! V_241 || ! ( F_2 ( V_2 , V_241 ) & V_247 ) )
continue;
F_22 ( V_2 , V_241 , 0 ,
V_248 ,
V_249 ) ;
}
V_171 = V_11 -> V_83 . V_250 ;
if ( V_171 )
F_22 ( V_2 , V_171 , 0 ,
V_64 ,
V_49 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_81 , V_167 ;
T_1 V_251 ;
V_167 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_83 . V_242 ; V_36 ++ ) {
T_1 V_252 [ 4 ] ;
V_81 = F_88 ( V_2 ,
V_11 -> V_83 . V_243 [ V_36 ] ,
V_252 , F_25 ( V_252 ) ) ;
if ( V_81 <= 0 )
continue;
V_251 = V_252 [ 0 ] ;
if ( ! V_167 ) {
V_11 -> V_244 . V_245 = V_251 ;
V_11 -> V_253 = V_11 -> V_83 . V_253 [ 0 ] ;
} else {
V_11 -> V_244 . V_246 = V_11 -> V_246 ;
if ( V_167 >= F_25 ( V_11 -> V_246 ) - 1 )
break;
V_11 -> V_246 [ V_167 - 1 ] = V_251 ;
}
V_167 ++ ;
}
if ( V_11 -> V_83 . V_250 ) {
V_251 = V_2 -> V_254 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_255 ; V_36 ++ , V_251 ++ ) {
unsigned int V_256 = F_2 ( V_2 , V_251 ) ;
if ( F_15 ( V_256 ) != V_257 )
continue;
if ( ! ( V_256 & V_258 ) )
continue;
if ( ! ( V_256 & V_259 ) )
continue;
V_81 = F_64 ( V_2 , V_251 ,
V_11 -> V_83 . V_250 ) ;
if ( V_81 >= 0 ) {
V_11 -> V_260 = V_251 ;
break;
}
}
}
}
static int F_89 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_48 ;
int V_81 ;
F_90 ( & V_2 -> V_261 ) ;
if ( V_11 -> V_262 )
V_48 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_103 ) ;
else
V_48 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_45 ) ;
V_7 -> V_263 = V_48 ;
V_81 = F_92 ( V_7 , V_9 ) ;
F_93 ( & V_2 -> V_261 ) ;
return V_81 ;
}
static int F_94 ( struct V_6 * V_7 , int V_264 ,
unsigned int V_265 , unsigned int T_2 * V_266 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_48 ;
int V_81 ;
F_90 ( & V_2 -> V_261 ) ;
if ( V_11 -> V_262 )
V_48 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_103 ) ;
else
V_48 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_45 ) ;
V_7 -> V_263 = V_48 ;
V_81 = F_95 ( V_7 , V_264 , V_265 , V_266 ) ;
F_93 ( & V_2 -> V_261 ) ;
return V_81 ;
}
static int F_96 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_230 , bool V_267 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_81 = 0 ;
F_90 ( & V_2 -> V_261 ) ;
if ( V_267 && V_11 -> V_38 ) {
for ( V_36 = 0 ; V_36 < V_11 -> V_172 ; V_36 ++ ) {
V_7 -> V_263 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_45 ) ;
V_81 = V_230 ( V_7 , V_18 ) ;
if ( V_81 < 0 )
goto error;
}
} else {
V_36 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_262 )
V_7 -> V_263 =
F_91 ( V_11 -> V_32 [ V_36 ] ,
3 , 0 , V_103 ) ;
else
V_7 -> V_263 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_45 ) ;
V_81 = V_230 ( V_7 , V_18 ) ;
}
error:
F_93 ( & V_2 -> V_261 ) ;
return V_81 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_268 , false ) ;
}
static int F_98 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_269 , true ) ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_270 , false ) ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_271 , true ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_272 = NULL ;
const struct V_65 * V_150 ;
int V_36 , V_273 , V_81 ;
unsigned int V_274 ;
T_1 V_3 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_67 ; V_36 ++ ) {
V_81 = F_102 ( V_2 , V_11 -> V_68 [ V_36 ] ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( V_11 -> V_275 ) {
V_81 = F_102 ( V_2 , V_11 -> V_275 ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( V_11 -> V_244 . V_245 ) {
V_81 = F_103 ( V_2 ,
V_11 -> V_244 . V_245 ,
V_11 -> V_244 . V_245 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! V_11 -> V_276 ) {
V_81 = F_104 ( V_2 ,
& V_11 -> V_244 ) ;
if ( V_81 < 0 )
return V_81 ;
V_11 -> V_244 . V_277 = 1 ;
}
}
if ( V_11 -> V_260 ) {
V_81 = F_105 ( V_2 , V_11 -> V_260 ) ;
if ( V_81 < 0 )
return V_81 ;
}
#ifdef F_106
if ( V_11 -> V_278 ) {
const struct V_65 * V_150 ;
for ( V_150 = V_279 ; V_150 -> V_147 ; V_150 ++ ) {
struct V_6 * V_272 ;
V_272 = F_107 ( V_150 , V_2 ) ;
if ( ! V_272 )
return - V_151 ;
V_272 -> V_263 = V_11 -> V_278 ;
V_81 = F_108 ( V_2 , 0 , V_272 ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
#endif
if ( ! V_11 -> V_276 &&
! F_109 ( V_2 , L_35 ) ) {
unsigned int V_280 [ 4 ] ;
F_110 ( V_2 , V_11 -> V_281 ,
V_103 , V_280 ) ;
V_81 = F_111 ( V_2 , L_35 ,
V_280 , V_282 ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( ! V_11 -> V_276 &&
! F_109 ( V_2 , L_36 ) ) {
V_81 = F_111 ( V_2 , L_36 ,
NULL , V_283 ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_272 = F_109 ( V_2 , L_37 ) ;
if ( ! V_272 )
V_272 = F_109 ( V_2 , L_38 ) ;
for ( V_36 = 0 ; V_272 && V_36 < V_272 -> V_144 ; V_36 ++ ) {
V_81 = F_112 ( V_2 , V_272 , V_36 ,
F_12 ( V_11 , V_36 ) ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
if ( V_11 -> V_275 && V_11 -> V_26 ) {
const char * V_284 = V_272 ? V_272 -> V_13 . V_147 : NULL ;
for ( V_150 = V_11 -> V_275 ; V_150 -> V_147 ; V_150 ++ ) {
if ( V_284 && strcmp ( V_150 -> V_147 , V_284 ) == 0 )
continue;
V_272 = F_109 ( V_2 , V_150 -> V_147 ) ;
for ( V_36 = 0 ; V_272 && V_36 < V_272 -> V_144 ; V_36 ++ ) {
V_81 = F_112 ( V_2 , V_272 , V_36 ,
V_11 -> V_26 [ V_36 ] ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
}
for ( V_36 = 0 ; V_36 < V_11 -> V_67 ; V_36 ++ ) {
for ( V_150 = V_11 -> V_68 [ V_36 ] ; V_150 -> V_147 ; V_150 ++ ) {
if ( V_150 -> V_285 != V_286 )
continue;
V_272 = F_109 ( V_2 , V_150 -> V_147 ) ;
if ( V_272 == NULL )
continue;
V_274 = V_150 -> V_287 ;
for ( V_273 = 0 ; V_273 < 4 ; V_273 ++ , V_274 >>= 8 ) {
V_3 = V_274 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_274 & 0xc0 ) {
case V_288 :
V_3 = V_11 -> V_83 . V_111 [ V_3 ] ;
break;
case V_289 :
V_3 = V_11 -> V_83 . V_112 [ V_3 ] ;
break;
case V_290 :
V_3 = V_11 -> V_83 . V_84 [ V_3 ] ;
break;
default:
continue;
}
V_81 = F_112 ( V_2 , V_272 , 0 , V_3 ) ;
if ( V_81 < 0 )
return V_81 ;
}
V_274 = V_150 -> V_263 ;
for ( V_273 = 0 ; V_273 < 4 ; V_273 ++ , V_274 >>= 8 ) {
V_3 = V_274 & 0xff ;
if ( V_3 == 0 )
continue;
V_81 = F_112 ( V_2 , V_272 , 0 , V_3 ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
}
F_113 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_36 ;
F_27 ( V_2 ) ;
F_49 ( V_2 , V_11 -> V_211 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_71 ; V_36 ++ )
F_50 ( V_2 , V_11 -> V_72 [ V_36 ] ) ;
F_115 ( V_2 ) ;
if ( V_11 -> V_291 )
V_11 -> V_291 ( V_2 ) ;
F_77 ( V_2 , V_292 ) ;
F_116 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , unsigned int V_123 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_165 )
V_11 -> V_165 ( V_2 , V_123 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_119 ( V_2 , & V_11 -> V_293 , V_3 ) ;
}
static int F_120 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_121 ( V_2 , & V_11 -> V_244 , V_297 ,
V_295 ) ;
}
static int F_122 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
unsigned int V_298 ,
unsigned int V_299 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_123 ( V_2 , & V_11 -> V_244 ,
V_298 , V_299 , V_297 ) ;
}
static int F_124 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_125 ( V_2 , & V_11 -> V_244 ) ;
}
static int F_126 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_127 ( V_2 , & V_11 -> V_244 ) ;
}
static int F_128 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
unsigned int V_298 ,
unsigned int V_299 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_129 ( V_2 , & V_11 -> V_244 ,
V_298 , V_299 , V_297 ) ;
}
static int F_130 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_131 ( V_2 , & V_11 -> V_244 ) ;
}
static int F_132 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_133 ( V_2 , & V_11 -> V_244 ) ;
}
static int F_134 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
unsigned int V_298 ,
unsigned int V_299 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_297 -> V_300 + 1 ] ,
V_298 , 0 , V_299 ) ;
return 0 ;
}
static int F_135 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_136 ( V_2 ,
V_11 -> V_26 [ V_297 -> V_300 + 1 ] ) ;
return 0 ;
}
static int F_137 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
unsigned int V_298 ,
unsigned int V_299 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_298 ;
V_11 -> V_30 = V_299 ;
F_11 ( V_2 , V_11 -> V_28 , V_298 , 0 , V_299 ) ;
return 0 ;
}
static int F_138 ( struct V_294 * V_295 ,
struct V_1 * V_2 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_136 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_301 * V_302 = V_11 -> V_303 ;
const struct V_294 * V_132 ;
bool V_304 ;
int V_36 ;
V_2 -> V_305 = 1 ;
V_2 -> V_306 = V_302 ;
if ( V_11 -> V_276 )
goto V_307;
snprintf ( V_11 -> V_308 , sizeof( V_11 -> V_308 ) ,
L_39 , V_2 -> V_199 ) ;
V_302 -> V_147 = V_11 -> V_308 ;
if ( V_11 -> V_244 . V_309 > 0 ) {
V_132 = V_11 -> V_310 ;
if ( ! V_132 )
V_132 = & V_311 ;
V_302 -> V_312 [ V_313 ] = * V_132 ;
V_302 -> V_312 [ V_313 ] . V_3 = V_11 -> V_244 . V_309 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_132 = V_11 -> V_314 ;
if ( ! V_132 ) {
if ( V_11 -> V_38 )
V_132 = & V_315 ;
else
V_132 = & V_316 ;
}
V_302 -> V_312 [ V_317 ] = * V_132 ;
V_302 -> V_312 [ V_317 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_318 ) {
V_302 -> V_312 [ V_313 ] . V_319 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_320 ; V_36 ++ ) {
if ( V_11 -> V_318 [ V_36 ] . V_321 > V_302 -> V_312 [ V_313 ] . V_319 ) {
V_302 -> V_312 [ V_313 ] . V_319 = V_11 -> V_318 [ V_36 ] . V_321 ;
}
}
}
V_307:
if ( V_11 -> V_244 . V_245 || V_11 -> V_260 ) {
snprintf ( V_11 -> V_322 ,
sizeof( V_11 -> V_322 ) ,
L_40 , V_2 -> V_199 ) ;
V_2 -> V_305 = 2 ;
V_2 -> V_246 = V_11 -> V_244 . V_246 ;
V_302 = V_11 -> V_303 + 1 ;
V_302 -> V_147 = V_11 -> V_322 ;
if ( V_11 -> V_253 )
V_302 -> V_323 = V_11 -> V_253 ;
else
V_302 -> V_323 = V_324 ;
if ( V_11 -> V_244 . V_245 ) {
V_132 = V_11 -> V_325 ;
if ( ! V_132 )
V_132 = & V_326 ;
V_302 -> V_312 [ V_313 ] = * V_132 ;
V_302 -> V_312 [ V_313 ] . V_3 = V_11 -> V_244 . V_245 ;
}
if ( V_11 -> V_260 ) {
V_132 = V_11 -> V_327 ;
if ( ! V_132 )
V_132 = & V_328 ;
V_302 -> V_312 [ V_317 ] = * V_132 ;
V_302 -> V_312 [ V_317 ] . V_3 = V_11 -> V_260 ;
}
V_2 -> V_329 = 1 ;
}
if ( V_11 -> V_276 )
return 0 ;
V_304 = ( V_11 -> V_172 > 1 ) &&
! V_11 -> V_38 && ! V_11 -> V_118 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_330 || V_304 ) {
V_2 -> V_305 = 3 ;
V_302 = V_11 -> V_303 + 2 ;
V_302 -> V_147 = V_11 -> V_308 ;
if ( V_11 -> V_330 ) {
V_132 = V_11 -> V_331 ;
if ( ! V_132 )
V_132 = & V_332 ;
V_302 -> V_312 [ V_313 ] = * V_132 ;
V_302 -> V_312 [ V_313 ] . V_3 =
V_11 -> V_330 ;
} else {
V_302 -> V_312 [ V_313 ] =
V_333 ;
V_302 -> V_312 [ V_313 ] . V_3 = 0 ;
}
if ( V_304 ) {
V_132 = V_11 -> V_334 ;
if ( ! V_132 )
V_132 = & V_335 ;
V_302 -> V_312 [ V_317 ] = * V_132 ;
V_302 -> V_312 [ V_317 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_302 -> V_312 [ V_317 ] . V_336 =
V_11 -> V_172 - 1 ;
} else {
V_302 -> V_312 [ V_317 ] =
V_333 ;
V_302 -> V_312 [ V_317 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_140 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_337 )
V_11 -> V_337 ( V_2 ) ;
F_141 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_149 . V_166 ) {
struct V_65 * V_272 = V_11 -> V_149 . V_166 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_149 . V_338 ; V_36 ++ )
F_142 ( V_272 [ V_36 ] . V_147 ) ;
}
F_143 ( & V_11 -> V_149 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_339 . V_166 ) {
struct V_340 * * V_341 = V_11 -> V_339 . V_166 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_339 . V_338 ; V_36 ++ )
F_142 ( V_341 [ V_36 ] ) ;
}
F_143 ( & V_11 -> V_339 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_140 ( V_2 ) ;
F_146 ( V_2 ) ;
F_113 ( V_2 ) ;
F_144 ( V_2 ) ;
F_142 ( V_11 ) ;
F_147 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_46 ( V_2 , false ) ;
}
static int F_149 ( struct V_1 * V_2 , T_4 V_342 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_140 ( V_2 ) ;
if ( V_11 && V_11 -> V_343 )
V_11 -> V_343 ( V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 )
{
F_48 ( 150 ) ;
V_2 -> V_344 . V_345 ( V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_116 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , const char * V_147 )
{
F_142 ( V_2 -> V_199 ) ;
V_2 -> V_199 = F_58 ( V_147 , V_153 ) ;
if ( ! V_2 -> V_199 ) {
F_145 ( V_2 ) ;
return - V_151 ;
}
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
const struct V_346 * V_132 ;
for ( V_132 = V_347 ; V_132 -> V_124 ; V_132 ++ ) {
if ( V_132 -> V_124 != V_2 -> V_124 )
continue;
if ( ( F_85 ( V_2 ) & V_132 -> V_348 ) == V_132 -> V_349 )
return F_153 ( V_2 , V_132 -> V_147 ) ;
}
return 0 ;
}
static int F_155 ( struct V_10 * V_11 , int type , const char * V_147 ,
int V_350 , unsigned long V_48 )
{
struct V_65 * V_150 ;
V_150 = F_54 ( V_11 ) ;
if ( ! V_150 )
return - V_151 ;
* V_150 = V_351 [ type ] ;
V_150 -> V_147 = F_58 ( V_147 , V_153 ) ;
if ( ! V_150 -> V_147 )
return - V_151 ;
V_150 -> V_42 = V_350 ;
if ( F_156 ( V_48 ) )
V_150 -> V_287 = V_352 ;
V_150 -> V_263 = V_48 ;
return 0 ;
}
static int F_157 ( struct V_10 * V_11 , int type ,
const char * V_353 , const char * V_4 ,
const char * V_354 , int V_350 , unsigned long V_48 )
{
char V_147 [ 32 ] ;
snprintf ( V_147 , sizeof( V_147 ) , L_41 , V_353 , V_4 , V_354 ) ;
return F_155 ( V_11 , type , V_147 , V_350 , V_48 ) ;
}
static const char * F_158 ( struct V_10 * V_11 , int V_355 ,
bool V_356 , int * V_42 )
{
struct V_154 * V_155 = & V_11 -> V_83 ;
* V_42 = 0 ;
if ( V_155 -> V_159 == 1 && ! V_11 -> V_357 &&
! V_155 -> V_161 && ! V_155 -> V_158 && V_356 )
return L_42 ;
switch ( V_155 -> V_156 ) {
case V_157 :
if ( V_155 -> V_159 == 1 )
return L_43 ;
if ( V_155 -> V_159 == 2 )
return V_355 ? L_44 : L_43 ;
break;
case V_160 :
if ( V_355 && V_11 -> V_357 )
break;
* V_42 = V_355 ;
return L_45 ;
default:
if ( V_155 -> V_159 == 1 && ! V_11 -> V_357 )
return L_46 ;
break;
}
if ( F_24 ( V_355 >= F_25 ( V_358 ) ) )
return L_46 ;
return V_358 [ V_355 ] ;
}
static int F_159 ( struct V_10 * V_11 , T_1 V_171 ,
const char * V_359 , int V_360 ,
int V_31 , T_1 V_361 )
{
int V_81 ;
V_81 = F_160 ( V_11 , V_362 , V_359 , V_360 ,
F_91 ( V_361 , 3 , V_31 , V_45 ) ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_161 ( V_11 , V_363 , V_359 , V_360 ,
F_91 ( V_361 , 3 , V_31 , V_45 ) ) ;
if ( V_81 < 0 )
return V_81 ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_51 = F_21 ( V_2 , V_3 ) ;
return ( V_51 & V_364 ) != 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_365 ;
T_1 * V_366 = V_11 -> V_173 ;
int V_367 = F_25 ( V_11 -> V_365 ) ;
int V_36 , V_167 = 0 ;
V_3 = V_2 -> V_254 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_255 ; V_36 ++ , V_3 ++ ) {
T_1 V_368 ;
const T_1 * V_166 ;
unsigned int V_369 = F_2 ( V_2 , V_3 ) ;
int type = F_15 ( V_369 ) ;
if ( type != V_257 || ( V_369 & V_258 ) )
continue;
V_26 [ V_167 ] = V_3 ;
V_366 [ V_167 ] = V_3 ;
V_368 = V_3 ;
for (; ; ) {
int V_169 ;
type = F_15 ( F_2 ( V_2 , V_368 ) ) ;
if ( type == V_129 )
break;
if ( type == V_370 ) {
V_366 [ V_167 ] = V_368 ;
break;
}
V_169 = F_14 ( V_2 , V_368 , & V_166 ) ;
if ( V_169 > 1 ) {
V_366 [ V_167 ] = V_368 ;
break;
} else if ( V_169 != 1 )
break;
V_368 = * V_166 ;
}
if ( ++ V_167 >= V_367 )
break;
}
V_11 -> V_26 = V_11 -> V_365 ;
V_11 -> V_32 = V_11 -> V_173 ;
V_11 -> V_172 = V_167 ;
return V_167 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_154 * V_155 = & V_11 -> V_83 ;
T_1 V_371 = V_11 -> V_372 ;
struct V_34 * V_35 = & V_11 -> V_168 [ 0 ] ;
int V_373 ;
int V_36 , V_176 , V_81 , V_31 , V_374 = 0 ;
const char * V_375 = NULL ;
V_373 = F_163 ( V_2 ) ;
if ( V_373 < 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_155 -> V_180 ; V_36 ++ ) {
T_1 V_171 ;
const char * V_175 ;
V_171 = V_155 -> V_181 [ V_36 ] . V_171 ;
if ( ! F_162 ( V_2 , V_171 ) )
continue;
V_175 = F_165 ( V_2 , V_155 , V_36 ) ;
if ( V_375 && ! strcmp ( V_175 , V_375 ) )
V_374 ++ ;
else
V_374 = 0 ;
V_375 = V_175 ;
if ( V_371 ) {
V_31 = F_64 ( V_2 , V_371 , V_171 ) ;
if ( V_31 >= 0 ) {
V_81 = F_159 ( V_11 , V_171 ,
V_175 , V_374 ,
V_31 , V_371 ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
for ( V_176 = 0 ; V_176 < V_373 ; V_176 ++ ) {
T_1 V_170 = F_12 ( V_11 , V_176 ) ;
V_31 = F_64 ( V_2 , V_170 , V_171 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_117 [ V_35 -> V_16 ] = V_171 ;
F_166 ( V_35 , V_175 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_35 ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_376 )
{
F_22 ( V_2 , V_3 , 0 , V_64 ,
V_376 ) ;
if ( F_168 ( V_2 , V_3 , V_103 ) )
F_22 ( V_2 , V_3 , 0 , V_248 ,
V_249 ) ;
}
static int F_169 ( int V_156 )
{
if ( V_156 == V_160 )
return V_98 ;
else
return V_99 ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_155 -> V_180 ; V_36 ++ ) {
T_1 V_3 = V_155 -> V_181 [ V_36 ] . V_171 ;
if ( F_162 ( V_2 , V_3 ) ) {
F_19 ( V_2 , V_3 , V_155 -> V_181 [ V_36 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_247 )
F_22 ( V_2 , V_3 , 0 ,
V_248 ,
V_377 ) ;
}
}
if ( V_11 -> V_372 ) {
int V_167 = F_14 ( V_2 , V_11 -> V_372 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_167 ; V_36 ++ )
F_22 ( V_2 , V_11 -> V_372 , 0 ,
V_248 ,
F_171 ( V_36 ) ) ;
}
}
static T_1 F_172 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_166 [ 5 ] ;
int V_36 , V_378 ;
if ( F_15 ( F_2 ( V_2 , V_3 ) ) == V_379 )
return V_3 ;
V_378 = F_88 ( V_2 , V_3 , V_166 , F_25 ( V_166 ) ) ;
for ( V_36 = 0 ; V_36 < V_378 ; V_36 ++ ) {
if ( F_15 ( F_2 ( V_2 , V_166 [ V_36 ] ) ) == V_379 )
return V_166 [ V_36 ] ;
}
return 0 ;
}
static T_1 F_173 ( struct V_1 * V_2 , T_1 V_171 )
{
T_1 V_380 [ 5 ] ;
int V_378 = F_88 ( V_2 , V_171 , V_380 ,
F_25 ( V_380 ) ) ;
if ( V_378 != 1 ||
F_15 ( F_2 ( V_2 , V_380 [ 0 ] ) ) != V_370 )
return V_171 ;
return V_380 [ 0 ] ;
}
static T_1 F_174 ( struct V_1 * V_2 , T_1 V_171 ,
T_1 V_241 )
{
T_1 V_66 [ 5 ] ;
int V_36 , V_378 ;
V_171 = F_173 ( V_2 , V_171 ) ;
V_378 = F_88 ( V_2 , V_171 , V_66 , F_25 ( V_66 ) ) ;
for ( V_36 = 0 ; V_36 < V_378 ; V_36 ++ ) {
if ( F_172 ( V_2 , V_66 [ V_36 ] ) == V_241 )
return V_66 [ V_36 ] ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , T_1 V_171 ,
T_1 V_241 )
{
T_1 V_66 [ 5 ] ;
int V_36 , V_378 ;
V_171 = F_173 ( V_2 , V_171 ) ;
V_378 = F_88 ( V_2 , V_171 , V_66 , F_25 ( V_66 ) ) ;
if ( V_378 < 2 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_378 ; V_36 ++ ) {
if ( F_172 ( V_2 , V_66 [ V_36 ] ) == V_241 ) {
F_176 ( V_2 , V_171 , 0 ,
V_46 , V_36 ) ;
return 0 ;
}
}
return 0 ;
}
static T_1 F_177 ( struct V_1 * V_2 , T_1 V_171 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_380 [ 5 ] ;
int V_36 , V_378 ;
V_171 = F_173 ( V_2 , V_171 ) ;
V_378 = F_88 ( V_2 , V_171 , V_380 , F_25 ( V_380 ) ) ;
for ( V_36 = 0 ; V_36 < V_378 ; V_36 ++ ) {
T_1 V_3 = F_172 ( V_2 , V_380 [ V_36 ] ) ;
if ( ! V_3 )
continue;
if ( F_74 ( V_3 , V_11 -> V_244 . V_309 ,
F_25 ( V_11 -> V_381 ) ) )
continue;
if ( F_74 ( V_3 , V_11 -> V_244 . V_382 ,
F_25 ( V_11 -> V_244 . V_382 ) ) )
continue;
if ( F_74 ( V_3 , V_11 -> V_244 . V_383 ,
F_25 ( V_11 -> V_244 . V_383 ) ) )
continue;
return V_3 ;
}
return 0 ;
}
static T_1 F_178 ( struct V_1 * V_2 , T_1 V_171 )
{
T_1 V_384 = F_173 ( V_2 , V_171 ) ;
if ( F_14 ( V_2 , V_384 , NULL ) == 1 )
return F_177 ( V_2 , V_171 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , int V_385 ,
const T_1 * V_92 , T_1 * V_386 )
{
int V_36 ;
if ( V_385 && ! V_386 [ 0 ] ) {
V_386 [ 0 ] = F_177 ( V_2 , V_92 [ 0 ] ) ;
if ( ! V_386 [ 0 ] )
return 0 ;
}
for ( V_36 = 1 ; V_36 < V_385 ; V_36 ++ )
V_386 [ V_36 ] = F_178 ( V_2 , V_92 [ V_36 ] ) ;
for ( V_36 = 1 ; V_36 < V_385 ; V_36 ++ ) {
if ( ! V_386 [ V_36 ] )
V_386 [ V_36 ] = F_177 ( V_2 , V_92 [ V_36 ] ) ;
}
return 1 ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
bool V_387 = false ;
int V_36 ;
V_388:
V_11 -> V_244 . V_389 = V_155 -> V_159 ;
V_11 -> V_244 . V_382 [ 0 ] = 0 ;
V_11 -> V_244 . V_383 [ 0 ] = 0 ;
memset ( V_11 -> V_381 , 0 , sizeof( V_11 -> V_381 ) ) ;
V_11 -> V_244 . V_309 = V_11 -> V_381 ;
V_11 -> V_357 = 0 ;
if ( ! V_387 ) {
for ( V_36 = 0 ; V_36 < V_155 -> V_159 ; V_36 ++ )
V_11 -> V_381 [ V_36 ] =
F_178 ( V_2 , V_155 -> V_112 [ V_36 ] ) ;
if ( V_155 -> V_161 )
V_11 -> V_244 . V_382 [ 0 ] =
F_178 ( V_2 , V_155 -> V_84 [ 0 ] ) ;
if ( V_155 -> V_158 )
V_11 -> V_244 . V_383 [ 0 ] =
F_178 ( V_2 , V_155 -> V_111 [ 0 ] ) ;
}
for ( V_36 = 0 ; V_36 < V_155 -> V_159 ; V_36 ++ ) {
T_1 V_171 = V_155 -> V_112 [ V_36 ] ;
if ( V_11 -> V_381 [ V_36 ] )
continue;
V_11 -> V_381 [ V_36 ] = F_177 ( V_2 , V_171 ) ;
if ( ! V_11 -> V_381 [ V_36 ] && ! V_387 ) {
V_387 = true ;
goto V_388;
}
}
V_11 -> V_244 . V_389 = 0 ;
for ( V_36 = 0 ; V_36 < V_155 -> V_159 ; V_36 ++ ) {
if ( V_11 -> V_381 [ V_36 ] )
V_11 -> V_244 . V_389 ++ ;
else {
memmove ( V_11 -> V_381 + V_36 ,
V_11 -> V_381 + V_36 + 1 ,
sizeof( T_1 ) * ( V_155 -> V_159 - V_36 - 1 ) ) ;
V_11 -> V_381 [ V_155 -> V_159 - 1 ] = 0 ;
}
}
if ( V_155 -> V_159 == 1 && V_155 -> V_156 != V_157 ) {
unsigned int V_390 , V_182 ;
int V_91 ;
V_182 = F_68 ( V_2 , V_155 -> V_112 [ 0 ] ) ;
V_390 = F_181 ( V_182 ) ;
V_91 = F_182 ( V_2 , V_390 ) ;
if ( V_91 > 0 ) {
V_11 -> V_357 = V_91 ;
V_11 -> V_391 = 2 ;
V_11 -> V_244 . V_389 = V_91 + 1 ;
}
}
if ( V_155 -> V_156 != V_160 )
F_179 ( V_2 , V_155 -> V_161 , V_155 -> V_84 ,
V_11 -> V_244 . V_382 ) ;
if ( V_155 -> V_156 != V_157 ) {
int V_81 = F_179 ( V_2 , V_155 -> V_158 ,
V_155 -> V_111 ,
V_11 -> V_244 . V_383 ) ;
if ( ! V_81 && V_155 -> V_158 > 0 &&
V_155 -> V_156 == V_160 ) {
V_155 -> V_161 = V_155 -> V_159 ;
memcpy ( V_155 -> V_84 , V_155 -> V_112 ,
sizeof( V_155 -> V_84 ) ) ;
V_155 -> V_159 = V_155 -> V_158 ;
memcpy ( V_155 -> V_112 , V_155 -> V_111 ,
sizeof( V_155 -> V_111 ) ) ;
V_155 -> V_158 = 0 ;
memset ( V_155 -> V_111 , 0 , sizeof( V_155 -> V_111 ) ) ;
V_155 -> V_156 = V_157 ;
V_387 = false ;
goto V_388;
}
}
return 0 ;
}
static inline unsigned int F_183 ( unsigned int V_392 )
{
T_1 V_3 = F_156 ( V_392 ) ;
unsigned int V_4 = F_184 ( V_392 ) ;
return ( V_3 << 1 ) | V_4 ;
}
static int F_185 ( struct V_1 * V_2 ,
const char * V_353 , int V_350 ,
T_1 V_3 , unsigned int V_393 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_48 ;
if ( ! V_3 )
return 0 ;
V_48 = F_91 ( V_3 , V_393 , 0 , V_103 ) ;
if ( F_186 ( V_11 -> V_394 , V_48 ) && V_393 != 2 )
return 0 ;
F_187 ( V_11 -> V_394 , V_48 ) ;
return F_160 ( V_2 -> V_11 , V_362 , V_353 , V_350 ,
V_48 ) ;
}
static int F_188 ( struct V_1 * V_2 ,
const char * V_353 , int V_350 ,
T_1 V_3 , unsigned int V_393 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_395 ;
int type ;
unsigned long V_48 ;
if ( ! V_3 )
return 0 ;
V_395 = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_395 == V_129 || V_395 == V_379 ) {
type = V_363 ;
V_48 = F_91 ( V_3 , V_393 , 0 , V_103 ) ;
} else if ( F_14 ( V_2 , V_3 , NULL ) == 1 ) {
type = V_363 ;
V_48 = F_91 ( V_3 , V_393 , 0 , V_45 ) ;
} else {
type = V_396 ;
V_48 = F_91 ( V_3 , V_393 , 2 , V_45 ) ;
}
if ( F_186 ( V_11 -> V_397 , V_48 ) && V_393 != 2 )
return 0 ;
F_187 ( V_11 -> V_397 , V_48 ) ;
return F_161 ( V_2 -> V_11 , type , V_353 , V_350 , V_48 ) ;
}
static T_1 F_189 ( struct V_1 * V_2 ,
T_1 V_171 , T_1 V_241 )
{
T_1 V_66 = F_174 ( V_2 , V_171 , V_241 ) ;
if ( F_168 ( V_2 , V_171 , V_103 ) )
return V_171 ;
else if ( V_66 && F_168 ( V_2 , V_66 , V_45 ) )
return V_66 ;
else if ( F_168 ( V_2 , V_241 , V_103 ) )
return V_241 ;
return 0 ;
}
static T_1 F_190 ( struct V_1 * V_2 ,
T_1 V_171 , T_1 V_241 )
{
T_1 V_66 = F_174 ( V_2 , V_171 , V_241 ) ;
if ( F_191 ( V_2 , V_241 , V_103 ) )
return V_241 ;
else if ( F_191 ( V_2 , V_66 , V_103 ) )
return V_66 ;
else if ( F_191 ( V_2 , V_171 , V_103 ) )
return V_171 ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 ,
const struct V_154 * V_155 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_81 , V_398 ;
V_398 = V_155 -> V_159 ;
if ( V_11 -> V_357 > 0 )
V_398 += V_11 -> V_357 ;
for ( V_36 = 0 ; V_36 < V_398 ; V_36 ++ ) {
const char * V_147 ;
int V_42 ;
T_1 V_241 , V_171 ;
T_1 V_399 , V_400 ;
V_241 = V_11 -> V_244 . V_309 [ V_36 ] ;
if ( ! V_241 )
continue;
if ( V_36 >= V_155 -> V_159 )
V_171 = V_11 -> V_401 [ V_36 - 1 ] . V_171 ;
else
V_171 = V_155 -> V_112 [ V_36 ] ;
V_399 = F_189 ( V_2 , V_171 , V_241 ) ;
V_400 = F_190 ( V_2 , V_171 , V_241 ) ;
V_147 = F_158 ( V_11 , V_36 , true , & V_42 ) ;
if ( ! V_147 || ! strcmp ( V_147 , L_47 ) ) {
V_81 = F_185 ( V_2 , L_48 , 0 , V_400 , 1 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_185 ( V_2 , L_49 , 0 , V_400 , 2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_188 ( V_2 , L_48 , 0 , V_399 , 1 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_188 ( V_2 , L_49 , 0 , V_399 , 2 ) ;
if ( V_81 < 0 )
return V_81 ;
} else {
V_81 = F_193 ( V_2 , V_147 , V_42 , V_400 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_194 ( V_2 , V_147 , V_42 , V_399 ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
return 0 ;
}
static int F_195 ( struct V_1 * V_2 , T_1 V_171 ,
T_1 V_241 , const char * V_353 ,
int V_350 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_399 , V_400 ;
int V_81 ;
if ( ! V_241 ) {
unsigned int V_48 ;
if ( ! ( F_2 ( V_2 , V_171 ) & V_247 ) )
return 0 ;
V_48 = F_91 ( V_171 , 3 , 0 , V_103 ) ;
if ( F_186 ( V_11 -> V_397 , V_48 ) )
return 0 ;
F_187 ( V_11 -> V_397 , V_48 ) ;
return F_161 ( V_11 , V_363 , V_353 , V_350 , V_48 ) ;
}
V_399 = F_189 ( V_2 , V_171 , V_241 ) ;
V_400 = F_190 ( V_2 , V_171 , V_241 ) ;
V_81 = F_193 ( V_2 , V_353 , V_350 , V_400 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_194 ( V_2 , V_353 , V_350 , V_399 ) ;
if ( V_81 < 0 )
return V_81 ;
return 0 ;
}
static struct V_340 * F_196 ( struct V_1 * V_2 ,
unsigned int V_167 ,
struct V_402 * V_403 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_340 * * V_404 , * V_341 ;
F_55 ( & V_11 -> V_339 , sizeof( V_341 ) , 8 ) ;
V_404 = F_56 ( & V_11 -> V_339 ) ;
if ( ! V_404 )
return NULL ;
V_341 = F_197 ( sizeof( * V_341 ) + sizeof( long ) * ( V_167 + 1 ) , V_153 ) ;
* V_404 = V_341 ;
if ( V_341 )
V_341 -> V_403 = V_403 ;
return V_341 ;
}
static int F_198 ( struct V_1 * V_2 , int V_91 ,
const T_1 * V_92 ,
const T_1 * V_386 ,
const char * V_353 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_340 * V_341 ;
char V_147 [ 32 ] ;
int V_36 , V_169 , V_81 ;
if ( ! V_91 || ! V_92 [ 0 ] )
return 0 ;
if ( V_91 == 1 ) {
T_1 V_241 = * V_386 ;
if ( ! V_241 )
V_241 = V_11 -> V_244 . V_309 [ 0 ] ;
return F_195 ( V_2 , * V_92 , V_241 , V_353 , 0 ) ;
}
if ( V_386 [ V_91 - 1 ] ) {
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
if ( V_91 >= 3 ) {
snprintf ( V_147 , sizeof( V_147 ) , L_50 ,
V_353 , V_358 [ V_36 ] ) ;
V_81 = F_195 ( V_2 , V_92 [ V_36 ] , V_386 [ V_36 ] ,
V_147 , 0 ) ;
} else {
V_81 = F_195 ( V_2 , V_92 [ V_36 ] , V_386 [ V_36 ] ,
V_353 , V_36 ) ;
}
if ( V_81 < 0 )
return V_81 ;
}
return 0 ;
}
V_341 = F_196 ( V_2 , V_91 , & V_405 ) ;
if ( ! V_341 )
return - V_151 ;
V_169 = 0 ;
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
if ( F_2 ( V_2 , V_92 [ V_36 ] ) & V_247 )
V_341 -> V_406 [ V_169 ++ ] =
F_91 ( V_92 [ V_36 ] , 3 , 0 , V_103 ) ;
}
if ( V_169 ) {
snprintf ( V_147 , sizeof( V_147 ) , L_51 , V_353 ) ;
V_81 = F_155 ( V_11 , V_407 , V_147 , 0 , ( long ) V_341 ) ;
if ( V_81 < 0 )
return V_81 ;
}
V_341 = F_196 ( V_2 , V_91 , & V_408 ) ;
if ( ! V_341 )
return - V_151 ;
V_169 = 0 ;
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
T_1 V_400 ;
if ( ! V_92 [ V_36 ] || ! V_386 [ V_36 ] )
continue;
V_400 = F_190 ( V_2 , V_92 [ V_36 ] , V_386 [ V_36 ] ) ;
if ( V_400 )
V_341 -> V_406 [ V_169 ++ ] =
F_91 ( V_400 , 3 , 0 , V_103 ) ;
}
if ( V_169 ) {
snprintf ( V_147 , sizeof( V_147 ) , L_52 , V_353 ) ;
V_81 = F_155 ( V_11 , V_409 , V_147 , 0 , ( long ) V_341 ) ;
if ( V_81 < 0 )
return V_81 ;
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_198 ( V_2 , V_11 -> V_83 . V_161 ,
V_11 -> V_83 . V_84 ,
V_11 -> V_244 . V_382 ,
L_45 ) ;
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_198 ( V_2 , V_11 -> V_83 . V_158 ,
V_11 -> V_83 . V_111 ,
V_11 -> V_244 . V_383 ,
L_43 ) ;
}
static void F_201 ( struct V_1 * V_2 ,
T_1 V_171 , int V_376 ,
T_1 V_241 )
{
int V_36 , V_378 ;
T_1 V_3 , V_66 = 0 ;
T_1 V_380 [ V_410 ] ;
F_167 ( V_2 , V_171 , V_376 ) ;
V_3 = F_173 ( V_2 , V_171 ) ;
V_378 = F_88 ( V_2 , V_3 , V_380 , F_25 ( V_380 ) ) ;
for ( V_36 = 0 ; V_36 < V_378 ; V_36 ++ ) {
if ( F_172 ( V_2 , V_380 [ V_36 ] ) != V_241 )
continue;
V_66 = V_380 [ V_36 ] ;
break;
}
if ( ! V_66 )
return;
if ( V_378 > 1 )
F_22 ( V_2 , V_3 , 0 , V_46 , V_36 ) ;
if ( F_168 ( V_2 , V_66 , V_45 ) ) {
F_22 ( V_2 , V_66 , 0 , V_248 ,
F_202 ( 0 ) ) ;
F_22 ( V_2 , V_66 , 0 , V_248 ,
F_202 ( 1 ) ) ;
}
V_3 = F_190 ( V_2 , V_171 , V_241 ) ;
if ( V_3 )
F_22 ( V_2 , V_3 , 0 , V_248 ,
V_411 ) ;
V_3 = F_189 ( V_2 , V_171 , V_241 ) ;
if ( V_3 == V_66 && F_168 ( V_2 , V_241 , V_103 ) )
F_22 ( V_2 , V_241 , 0 , V_248 ,
V_411 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_376 = F_169 ( V_11 -> V_83 . V_156 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_412 ; V_36 ++ ) {
T_1 V_3 = V_11 -> V_83 . V_112 [ V_36 ] ;
if ( V_3 )
F_201 ( V_2 , V_3 , V_376 ,
V_11 -> V_244 . V_309 [ V_36 ] ) ;
}
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_171 , V_241 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_83 . V_161 ; V_36 ++ ) {
if ( V_11 -> V_83 . V_156 == V_160 )
break;
V_171 = V_11 -> V_83 . V_84 [ V_36 ] ;
if ( ! V_171 )
break;
V_241 = V_11 -> V_244 . V_382 [ V_36 ] ;
if ( ! V_241 ) {
if ( V_36 > 0 && V_11 -> V_244 . V_382 [ 0 ] )
V_241 = V_11 -> V_244 . V_382 [ 0 ] ;
else
V_241 = V_11 -> V_244 . V_309 [ 0 ] ;
}
F_201 ( V_2 , V_171 , V_98 , V_241 ) ;
}
for ( V_36 = 0 ; V_36 < V_11 -> V_83 . V_158 ; V_36 ++ ) {
if ( V_11 -> V_83 . V_156 == V_157 )
break;
V_171 = V_11 -> V_83 . V_111 [ V_36 ] ;
if ( ! V_171 )
break;
V_241 = V_11 -> V_244 . V_383 [ V_36 ] ;
if ( ! V_241 ) {
if ( V_36 > 0 && V_11 -> V_244 . V_383 [ 0 ] )
V_241 = V_11 -> V_244 . V_383 [ 0 ] ;
else
V_241 = V_11 -> V_244 . V_309 [ 0 ] ;
}
F_201 ( V_2 , V_171 , V_99 , V_241 ) ;
}
}
static int F_182 ( struct V_1 * V_2 ,
unsigned int V_390 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
T_1 V_413 = V_11 -> V_381 [ 0 ] ;
int type , V_36 , V_91 = 0 ;
for ( type = V_186 ; type >= V_50 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_155 -> V_180 ; V_36 ++ ) {
T_1 V_3 = V_155 -> V_181 [ V_36 ] . V_171 ;
T_1 V_241 ;
unsigned int V_182 , V_369 ;
if ( V_155 -> V_181 [ V_36 ] . type != type )
continue;
V_182 = F_68 ( V_2 , V_3 ) ;
if ( F_205 ( V_182 ) != V_414 )
continue;
if ( V_390 && F_181 ( V_182 ) != V_390 )
continue;
V_369 = F_21 ( V_2 , V_3 ) ;
if ( ! ( V_369 & V_415 ) )
continue;
V_241 = F_177 ( V_2 , V_3 ) ;
if ( ! V_241 )
continue;
V_11 -> V_401 [ V_91 ] . V_171 = V_3 ;
V_11 -> V_401 [ V_91 ] . V_241 = V_241 ;
V_91 ++ ;
V_11 -> V_381 [ V_11 -> V_244 . V_389 ++ ] = V_241 ;
}
}
V_11 -> V_244 . V_389 = 1 ;
if ( V_91 < 2 ) {
memset ( V_11 -> V_381 , 0 ,
sizeof( V_11 -> V_381 ) ) ;
V_11 -> V_381 [ 0 ] = V_413 ;
return 0 ;
}
return V_91 ;
}
static int F_206 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_143 ;
V_9 -> V_144 = 1 ;
V_9 -> V_20 . V_21 . V_41 = V_11 -> V_357 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_357 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_357 ;
sprintf ( V_9 -> V_20 . V_21 . V_147 , L_53 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_207 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_391 - 1 ) / 2 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , int V_31 , bool V_416 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_401 [ V_31 ] . V_171 ;
if ( ! V_11 -> V_401 [ V_31 ] . V_417 )
V_11 -> V_401 [ V_31 ] . V_417 =
F_20 ( V_2 , V_3 , 0 ,
V_53 , 0 ) ;
if ( V_416 ) {
F_176 ( V_2 , V_3 , 0 ,
V_64 ,
V_99 ) ;
if ( F_2 ( V_2 , V_3 ) & V_247 )
F_16 ( V_2 , V_3 , V_103 , 0 ,
V_44 , 0 ) ;
F_175 ( V_2 , V_3 , V_11 -> V_401 [ V_31 ] . V_241 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_247 )
F_16 ( V_2 , V_3 , V_103 , 0 ,
V_44 , V_44 ) ;
F_176 ( V_2 , V_3 , 0 ,
V_64 ,
V_11 -> V_401 [ V_31 ] . V_417 ) ;
}
return 0 ;
}
static int F_209 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_355 ;
V_355 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_355 < 0 || V_355 > V_11 -> V_357 )
return - V_148 ;
if ( V_355 == ( V_11 -> V_391 - 1 ) / 2 )
return 0 ;
V_11 -> V_391 = ( V_355 + 1 ) * 2 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_357 ; V_36 ++ )
F_208 ( V_2 , V_36 , V_36 < V_355 ) ;
V_11 -> V_244 . V_418 = V_11 -> V_391 ;
if ( V_11 -> V_419 && ! V_11 -> V_420 )
V_11 -> V_244 . V_389 = V_11 -> V_244 . V_418 / 2 ;
return 1 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_357 > 0 ) {
struct V_65 * V_150 ;
V_150 = F_54 ( V_11 ) ;
if ( ! V_150 )
return - V_151 ;
* V_150 = V_421 ;
V_150 -> V_147 = F_58 ( L_54 , V_153 ) ;
if ( ! V_150 -> V_147 )
return - V_151 ;
}
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
T_1 V_26 [ F_25 ( V_11 -> V_365 ) ] ;
T_1 V_32 [ F_25 ( V_11 -> V_365 ) ] ;
int V_36 , V_169 , V_167 ;
V_35 = V_11 -> V_15 ;
if ( ! V_35 )
return;
if ( V_11 -> V_38 )
return;
V_167 = 0 ;
for ( V_169 = 0 ; V_169 < V_11 -> V_172 ; V_169 ++ ) {
T_1 V_170 = V_11 -> V_173 [ V_169 ] ;
int V_37 = F_14 ( V_2 , V_170 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
T_1 V_171 = V_11 -> V_117 [ V_36 ] ;
if ( V_171 ) {
if ( F_64 ( V_2 , V_170 , V_171 ) < 0 )
break;
} else if ( V_37 <= V_35 -> V_41 [ V_36 ] . V_42 )
break;
}
if ( V_36 >= V_35 -> V_16 ) {
V_26 [ V_167 ] = V_11 -> V_365 [ V_169 ] ;
V_32 [ V_167 ++ ] = V_170 ;
}
}
if ( ! V_167 ) {
if ( ! F_63 ( V_2 ) ) {
F_72 ( V_422 L_55
L_56 ,
V_2 -> V_199 , V_11 -> V_365 [ 0 ] ) ;
V_11 -> V_172 = 1 ;
V_11 -> V_118 = 0 ;
return;
}
} else if ( V_167 != V_11 -> V_172 ) {
memcpy ( V_11 -> V_365 , V_26 ,
V_167 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_173 , V_32 ,
V_167 * sizeof( T_1 ) ) ;
V_11 -> V_172 = V_167 ;
}
if ( V_11 -> V_118 )
F_66 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 )
V_11 -> V_172 = 1 ;
}
static void F_212 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_168 ( V_2 , V_3 , V_45 ) ) {
F_22 ( V_2 , V_3 , 0 ,
V_248 ,
F_171 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_168 ( V_2 , V_3 , V_103 ) )
F_22 ( V_2 , V_3 , 0 ,
V_248 ,
V_377 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_176 , V_167 ;
for ( V_176 = 0 ; V_176 < V_11 -> V_172 ; V_176 ++ )
F_212 ( V_2 , V_176 ) ;
if ( V_11 -> V_38 )
V_167 = 1 ;
else
V_167 = V_11 -> V_172 ;
for ( V_176 = 0 ; V_176 < V_167 ; V_176 ++ )
F_13 ( V_2 , 0 , V_11 -> V_23 [ V_176 ] , true ) ;
}
static int F_214 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
int V_36 , V_81 ;
int V_374 = 0 ;
T_1 V_3 ;
const char * V_375 = NULL ;
for ( V_36 = 0 ; V_36 < V_155 -> V_180 ; V_36 ++ ) {
if ( V_155 -> V_181 [ V_36 ] . type > V_50 )
break;
V_3 = V_155 -> V_181 [ V_36 ] . V_171 ;
if ( F_2 ( V_2 , V_3 ) & V_423 ) {
const char * V_175 ;
char V_424 [ 32 ] ;
V_175 = F_165 ( V_2 , V_155 , V_36 ) ;
if ( V_375 && ! strcmp ( V_175 , V_375 ) )
V_374 ++ ;
else
V_374 = 0 ;
V_375 = V_175 ;
snprintf ( V_424 , sizeof( V_424 ) ,
L_57 , V_175 ) ;
V_81 = F_155 ( V_11 , V_362 ,
V_424 , V_374 ,
F_91 ( V_3 , 3 , 0 , V_45 ) ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 , T_1 V_170 ,
int V_31 )
{
if ( F_15 ( F_2 ( V_2 , V_170 ) ) == V_39 ) {
F_16 ( V_2 , V_170 , V_45 , V_31 ,
V_44 , 0 ) ;
} else if ( F_14 ( V_2 , V_170 , NULL ) > 1 ) {
F_17 ( V_2 , V_170 , 0 ,
V_46 , V_31 ) ;
}
}
static int F_216 ( struct V_1 * V_2 , T_1 V_171 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( ! V_171 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_172 ; V_36 ++ ) {
T_1 V_170 = F_12 ( V_11 , V_36 ) ;
int V_31 ;
V_31 = F_64 ( V_2 , V_170 , V_171 ) ;
if ( V_31 < 0 )
continue;
F_215 ( V_2 , V_170 , V_31 ) ;
return V_36 ;
}
return - 1 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_83 . V_180 ; V_36 ++ )
F_216 ( V_2 , V_11 -> V_83 . V_181 [ V_36 ] . V_171 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_65 * V_369 [ 2 ] [ 3 ] = {
{ V_425 ,
V_426 ,
V_427 } ,
{ V_428 ,
V_429 ,
V_430 } ,
} ;
if ( ! F_191 ( V_2 , V_11 -> V_26 [ 0 ] , V_45 ) ) {
if ( ! V_11 -> V_32 )
return;
if ( ! F_191 ( V_2 , V_11 -> V_32 [ 0 ] , V_103 ) )
return;
V_11 -> V_262 = 1 ;
}
if ( V_11 -> V_172 > 0 ) {
int V_431 = 0 ;
int V_373 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_431 = 1 ;
if ( V_11 -> V_118 ) {
V_373 = 1 ;
V_431 = 0 ;
} else if ( V_11 -> V_38 )
V_373 = 1 ;
if ( ! V_373 ) {
if ( V_11 -> V_172 > 3 )
V_11 -> V_172 = 3 ;
else if ( ! V_11 -> V_172 )
return;
V_373 = V_11 -> V_172 ;
}
V_11 -> V_275 = V_369 [ V_431 ] [ V_373 - 1 ] ;
}
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_203 ( V_2 ) ;
F_204 ( V_2 ) ;
F_170 ( V_2 ) ;
F_213 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_11 -> V_165 )
F_42 ( V_2 ) ;
}
static inline int F_219 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_236 * V_432 ;
V_432 = F_82 ( V_2 -> V_195 -> V_196 , V_433 ) ;
if ( V_432 )
return V_432 -> V_20 ;
return V_11 -> V_188 . V_189 ;
}
static int F_220 ( struct V_1 * V_2 ,
const T_1 * V_434 ,
const T_1 * V_435 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_154 * V_155 = & V_11 -> V_83 ;
int V_81 ;
V_81 = F_221 ( V_2 , V_155 , V_434 ,
V_11 -> V_436 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! V_155 -> V_159 ) {
if ( V_155 -> V_242 || V_155 -> V_250 ) {
V_11 -> V_244 . V_418 = 2 ;
V_11 -> V_276 = 1 ;
goto V_437;
}
return 0 ;
}
if ( V_155 -> V_156 == V_157 &&
V_155 -> V_159 <= V_155 -> V_161 ) {
V_155 -> V_158 = V_155 -> V_159 ;
memcpy ( V_155 -> V_111 , V_155 -> V_112 ,
sizeof( V_155 -> V_111 ) ) ;
V_155 -> V_159 = V_155 -> V_161 ;
memcpy ( V_155 -> V_112 , V_155 -> V_84 , sizeof( V_155 -> V_84 ) ) ;
V_155 -> V_161 = 0 ;
memset ( V_155 -> V_84 , 0 , sizeof( V_155 -> V_84 ) ) ;
V_155 -> V_156 = V_160 ;
}
V_81 = F_180 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_210 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_192 ( V_2 , V_155 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_199 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_200 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_164 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
V_11 -> V_244 . V_418 = V_11 -> V_244 . V_389 * 2 ;
V_437:
F_87 ( V_2 ) ;
if ( ! V_11 -> V_276 )
F_211 ( V_2 ) ;
if ( V_435 )
F_76 ( V_2 , V_435 ) ;
if ( ! V_11 -> V_276 ) {
F_70 ( V_2 ) ;
V_81 = F_214 ( V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( V_11 -> V_149 . V_166 )
F_23 ( V_11 , V_11 -> V_149 . V_166 ) ;
return 1 ;
}
static int F_222 ( struct V_1 * V_2 )
{
static const T_1 V_438 [] = { 0x1d , 0 } ;
static const T_1 V_439 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_220 ( V_2 , V_438 , V_439 ) ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_440 ;
int V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
V_11 -> V_419 = 1 ;
V_440 = F_224 ( V_2 , V_441 ,
V_442 , V_443 ) ;
if ( V_440 < 0 ) {
F_72 ( V_198 L_58 ,
V_2 -> V_199 ) ;
V_440 = V_444 ;
}
if ( V_440 == V_444 ) {
V_81 = F_222 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
#ifdef F_225
else if ( ! V_81 ) {
F_72 ( V_198
L_59
L_60 ) ;
V_440 = V_445 ;
}
#endif
}
if ( V_440 != V_444 )
F_226 ( V_2 , & V_446 [ V_440 ] ) ;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x0b , 0x05 , V_45 ) ;
}
V_11 -> V_281 = 0x0c ;
V_2 -> V_344 = V_447 ;
if ( V_440 == V_444 )
V_11 -> V_291 = F_218 ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_449 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_230 ( struct V_1 * V_2 )
{
static const T_1 V_450 [] = { 0x17 , 0 } ;
static const T_1 V_451 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_220 ( V_2 , V_450 , V_451 ) ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 , V_440 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x07 ;
V_440 = F_224 ( V_2 , V_452 ,
V_453 , V_454 ) ;
if ( V_440 < 0 ) {
F_73 ( V_198 L_58 ,
V_2 -> V_199 ) ;
V_440 = V_444 ;
}
if ( V_440 == V_444 ) {
F_81 ( V_2 , NULL , V_455 , V_456 ) ;
F_77 ( V_2 , V_223 ) ;
}
if ( V_440 == V_444 ) {
V_81 = F_230 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
#ifdef F_225
else if ( ! V_81 ) {
F_72 ( V_198
L_59
L_61 ) ;
V_440 = V_457 ;
}
#endif
}
if ( V_440 != V_444 )
F_226 ( V_2 , & V_458 [ V_440 ] ) ;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x07 , 0x05 , V_45 ) ;
}
F_77 ( V_2 , V_227 ) ;
V_11 -> V_281 = 0x08 ;
V_2 -> V_344 = V_447 ;
if ( V_440 == V_444 )
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_47 ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_459 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_232 ( struct V_1 * V_2 )
{
static const T_1 V_460 [] = { 0x1d , 0 } ;
static const T_1 V_461 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_220 ( V_2 , V_460 , V_461 ) ;
}
static int F_233 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 , V_440 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
switch ( V_2 -> V_124 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_28 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
V_81 = F_154 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
V_440 = F_224 ( V_2 , V_462 ,
V_463 , V_464 ) ;
if ( V_440 < 0 )
V_440 = F_234 ( V_2 ,
V_462 , V_463 , V_465 ) ;
if ( V_440 < 0 ) {
F_72 ( V_198 L_58 ,
V_2 -> V_199 ) ;
V_440 = V_444 ;
}
if ( V_440 == V_444 ) {
F_81 ( V_2 , NULL , V_466 , V_467 ) ;
F_77 ( V_2 , V_223 ) ;
}
F_71 ( V_2 ) ;
if ( V_440 == V_444 ) {
V_81 = F_232 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
#ifdef F_225
else if ( ! V_81 ) {
F_72 ( V_198
L_59
L_61 ) ;
V_440 = V_468 ;
}
#endif
}
if ( V_440 != V_444 )
F_226 ( V_2 , & V_469 [ V_440 ] ) ;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 && F_219 ( V_2 ) ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x0b , 0x05 , V_45 ) ;
}
F_77 ( V_2 , V_227 ) ;
V_11 -> V_281 = 0x0c ;
V_2 -> V_344 = V_447 ;
if ( V_440 == V_444 )
V_11 -> V_291 = F_218 ;
F_29 ( V_2 ) ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_470 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_235 ( struct V_1 * V_2 )
{
static const T_1 V_471 [] = { 0x1d , 0 } ;
static const T_1 V_472 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_220 ( V_2 , V_471 , V_472 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_440 ;
int V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_71 ( V_2 ) ;
F_28 ( V_2 , 0x20 , 0x0a , 10 ) ;
V_440 = F_224 ( V_2 , V_473 ,
V_474 , V_475 ) ;
if ( V_440 < 0 ) {
F_72 ( V_198 L_58 ,
V_2 -> V_199 ) ;
V_440 = V_444 ;
}
if ( V_440 == V_444 ) {
F_81 ( V_2 , NULL , V_476 , V_477 ) ;
F_77 ( V_2 , V_223 ) ;
}
if ( V_440 == V_444 ) {
V_81 = F_235 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
#ifdef F_225
else if ( ! V_81 ) {
F_72 ( V_198
L_59
L_61 ) ;
V_440 = V_478 ;
}
#endif
}
if ( V_440 != V_444 )
F_226 ( V_2 , & V_479 [ V_440 ] ) ;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 && F_219 ( V_2 ) ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x0b , 0x05 , V_45 ) ;
}
F_77 ( V_2 , V_227 ) ;
V_11 -> V_281 = 0x0c ;
V_2 -> V_344 = V_447 ;
if ( V_440 == V_444 )
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_47 ;
F_29 ( V_2 ) ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_480 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_237 ( struct V_1 * V_2 )
{
static const T_1 V_481 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_81 = F_220 ( V_2 , NULL , V_481 ) ;
if ( V_81 > 0 ) {
if ( ! V_11 -> V_276 && V_11 -> V_83 . V_111 [ 0 ] != 0x1d ) {
F_23 ( V_11 , V_482 ) ;
F_26 ( V_11 , V_483 ) ;
}
}
return V_81 ;
}
static int F_238 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_36 , V_484 , V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_81 = F_237 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
V_484 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_67 ; V_36 ++ ) {
if ( V_11 -> V_68 [ V_36 ] == V_482 ) {
V_484 = 1 ;
break;
}
}
if ( V_484 ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_45 ) )
F_239 ( V_2 , 0x1d , V_45 ,
( 0x0c << V_485 ) |
( 0x0c << V_486 ) |
( 0x07 << V_487 ) |
( 0 << V_488 ) ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
V_11 -> V_281 = 0x02 ;
V_2 -> V_344 = V_447 ;
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_47 ;
F_29 ( V_2 ) ;
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_240 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_194 ) {
case 0x103c1586 :
return 1 ;
}
return 0 ;
}
static int F_241 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == 0x01 || V_3 == 0x14 ) {
int V_489 ;
if ( F_242 ( V_2 , 0x14 , 0 , V_103 , 0 ) &
V_44 )
V_489 = 0x24 ;
else
V_489 = 0x20 ;
F_176 ( V_2 , 0x19 , 0 ,
V_64 ,
V_489 ) ;
}
return F_118 ( V_2 , V_3 ) ;
}
static int F_243 ( struct V_1 * V_2 )
{
static const T_1 V_490 [] = { 0x1d , 0 } ;
static const T_1 V_491 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_492 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_493 = V_11 -> V_494 == V_495 ?
V_492 : V_491 ;
return F_220 ( V_2 , V_490 , V_493 ) ;
}
static void F_244 ( struct V_1 * V_2 , int V_496 )
{
int V_48 = F_83 ( V_2 , 0x04 ) ;
if ( V_496 )
V_48 |= 1 << 11 ;
else
V_48 &= ~ ( 1 << 11 ) ;
F_84 ( V_2 , 0x04 , V_48 ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 )
F_244 ( V_2 , 0 ) ;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_244 ( V_2 , 0 ) ;
F_48 ( 150 ) ;
}
}
static int F_246 ( struct V_1 * V_2 )
{
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_244 ( V_2 , 0 ) ;
F_48 ( 150 ) ;
}
V_2 -> V_344 . V_345 ( V_2 ) ;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_244 ( V_2 , 1 ) ;
F_48 ( 200 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 )
F_244 ( V_2 , 1 ) ;
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_116 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_247 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
int V_497 ;
if ( V_213 != V_292 )
return;
V_497 = F_83 ( V_2 , 0x1e ) ;
F_84 ( V_2 , 0x1e , V_497 | 0x80 ) ;
}
static void F_248 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
static const struct V_69 V_228 [] = {
{ 0x20 , V_74 , 0x0d } ,
{ 0x20 , V_77 , 0x4000 } ,
{}
} ;
unsigned int V_155 ;
if ( strcmp ( V_2 -> V_199 , L_62 ) )
return;
V_155 = F_68 ( V_2 , 0x12 ) ;
if ( F_205 ( V_155 ) == V_498 )
F_50 ( V_2 , V_228 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_213 != V_227 )
return;
V_11 -> V_310 = & V_499 ;
V_11 -> V_314 = & V_500 ;
}
static void F_250 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
int V_497 ;
if ( V_213 != V_292 )
return;
V_497 = F_83 ( V_2 , 0x07 ) ;
F_84 ( V_2 , 0x07 , V_497 | 0x80 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_22 ( V_2 , 0x20 , 0 ,
V_74 , 0x0c ) ;
F_22 ( V_2 , 0x20 , 0 ,
V_77 , 0x680 ) ;
F_22 ( V_2 , 0x20 , 0 ,
V_74 , 0x0c ) ;
F_22 ( V_2 , 0x20 , 0 ,
V_77 , 0x480 ) ;
}
static void F_252 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_213 != V_227 )
return;
V_11 -> V_114 = F_251 ;
}
static int F_253 ( struct V_1 * V_2 )
{
int V_48 ;
if ( ( F_85 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_48 = F_83 ( V_2 , 0x04 ) ;
F_84 ( V_2 , 0x04 , V_48 | ( 1 << 11 ) ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_48 = F_83 ( V_2 , 0xd ) ;
if ( ( V_48 & 0x0c00 ) >> 10 != 0x1 ) {
F_84 ( V_2 , 0xd , V_48 | ( 1 << 10 ) ) ;
}
V_48 = F_83 ( V_2 , 0x17 ) ;
if ( ( V_48 & 0x01c0 ) >> 6 != 0x4 ) {
F_84 ( V_2 , 0x17 , V_48 | ( 1 << 7 ) ) ;
}
}
V_48 = F_83 ( V_2 , 0xd ) ;
F_84 ( V_2 , 0xd , V_48 | ( 1 << 14 ) ) ;
V_48 = F_83 ( V_2 , 0x4 ) ;
F_84 ( V_2 , 0x4 , V_48 | ( 1 << 11 ) ) ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 = 0 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
F_71 ( V_2 ) ;
V_81 = F_154 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( V_2 -> V_124 == 0x10ec0269 ) {
V_11 -> V_494 = V_495 ;
switch ( F_85 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_195 -> V_196 -> V_501 == 0x1025 &&
V_11 -> V_188 . V_204 == 1 )
V_81 = F_153 ( V_2 , L_62 ) ;
V_11 -> V_494 = V_502 ;
break;
case 0x0020 :
if ( V_2 -> V_195 -> V_196 -> V_501 == 0x17aa &&
V_2 -> V_195 -> V_196 -> V_197 == 0x21f3 )
V_81 = F_153 ( V_2 , L_63 ) ;
V_11 -> V_494 = V_503 ;
break;
default:
F_28 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_81 < 0 )
goto error;
F_253 ( V_2 ) ;
}
F_81 ( V_2 , V_504 ,
V_505 , V_506 ) ;
F_77 ( V_2 , V_223 ) ;
V_81 = F_243 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 && F_219 ( V_2 ) ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x0b , 0x04 , V_45 ) ;
}
F_77 ( V_2 , V_227 ) ;
V_11 -> V_281 = 0x02 ;
V_2 -> V_344 = V_447 ;
#ifdef F_255
V_2 -> V_344 . V_507 = F_246 ;
#endif
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_245 ;
F_29 ( V_2 ) ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_508 ;
if ( F_240 ( V_2 ) )
V_2 -> V_344 . V_509 = F_241 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_256 ( struct V_1 * V_2 )
{
static const T_1 V_510 [] = { 0x1d , 0 } ;
static const T_1 V_511 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_220 ( V_2 , V_510 , V_511 ) ;
}
static int F_257 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x15 ;
F_81 ( V_2 , NULL , V_512 , V_513 ) ;
F_77 ( V_2 , V_223 ) ;
V_81 = F_256 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 ) {
V_81 = F_227 ( V_2 , 0x23 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x23 , 0 , V_103 ) ;
}
V_11 -> V_281 = 0x03 ;
F_77 ( V_2 , V_227 ) ;
V_2 -> V_344 = V_447 ;
V_11 -> V_291 = F_218 ;
#ifdef F_229
V_11 -> V_343 = F_148 ;
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_514 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_258 ( struct V_1 * V_2 )
{
static const T_1 V_515 [] = { 0x1d , 0 } ;
static const T_1 V_516 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_220 ( V_2 , V_515 , V_516 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
if ( V_213 == V_223 ) {
F_260 ( V_2 , 0x18 , 0x00001714 ) ;
F_260 ( V_2 , 0x19 , 0x0000171c ) ;
}
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
F_81 ( V_2 , NULL , V_517 , V_518 ) ;
F_77 ( V_2 , V_223 ) ;
V_81 = F_258 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( V_2 -> V_124 == 0x10ec0660 ) {
F_26 ( V_11 , V_519 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 ) {
V_81 = F_227 ( V_2 , 0x23 ) ;
if ( V_81 < 0 )
goto error;
F_228 ( V_11 , 0x0b , 0x05 , V_45 ) ;
}
V_11 -> V_281 = 0x02 ;
F_77 ( V_2 , V_227 ) ;
V_2 -> V_344 = V_447 ;
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_47 ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_520 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_262 ( struct V_1 * V_2 )
{
static const T_1 V_521 [] = { 0x1d , 0 } ;
static const T_1 V_522 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_523 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_493 ;
if ( V_2 -> V_124 == 0x10ec0272 || V_2 -> V_124 == 0x10ec0663 ||
V_2 -> V_124 == 0x10ec0665 || V_2 -> V_124 == 0x10ec0670 )
V_493 = V_522 ;
else
V_493 = V_523 ;
return F_220 ( V_2 , V_521 , V_493 ) ;
}
static void F_263 ( struct V_1 * V_2 ,
const struct V_219 * V_220 , int V_213 )
{
if ( V_213 != V_227 )
return;
if ( F_239 ( V_2 , 0x2 , V_103 ,
( 0x3b << V_485 ) |
( 0x3b << V_486 ) |
( 0x03 << V_487 ) |
( 0 << V_488 ) ) )
F_72 ( V_422
L_64 ) ;
}
static int F_264 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 = 0 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( ! V_11 )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_372 = 0x0b ;
V_11 -> V_436 = V_524 ;
F_71 ( V_2 ) ;
F_28 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_81 = F_154 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( ( F_85 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_195 -> V_196 -> V_501 == 0x1025 &&
V_11 -> V_188 . V_204 == 1 ) {
if ( F_153 ( V_2 , L_65 ) < 0 )
goto error;
}
F_81 ( V_2 , V_525 ,
V_526 , V_527 ) ;
F_77 ( V_2 , V_223 ) ;
V_81 = F_262 ( V_2 ) ;
if ( V_81 < 0 )
goto error;
if ( ! V_11 -> V_276 && ! V_11 -> V_26 ) {
F_163 ( V_2 ) ;
F_65 ( V_2 ) ;
F_211 ( V_2 ) ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
if ( ! V_11 -> V_276 && F_219 ( V_2 ) ) {
V_81 = F_227 ( V_2 , 0x1 ) ;
if ( V_81 < 0 )
goto error;
switch ( V_2 -> V_124 ) {
case 0x10ec0662 :
F_228 ( V_11 , 0x0b , 0x05 , V_45 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_228 ( V_11 , 0x0b , 0x04 , V_45 ) ;
break;
case 0x10ec0273 :
F_228 ( V_11 , 0x0b , 0x03 , V_45 ) ;
break;
}
}
V_11 -> V_281 = 0x02 ;
F_77 ( V_2 , V_227 ) ;
V_2 -> V_344 = V_447 ;
V_11 -> V_291 = F_218 ;
V_11 -> V_337 = F_47 ;
F_29 ( V_2 ) ;
#ifdef F_229
if ( ! V_11 -> V_293 . V_448 )
V_11 -> V_293 . V_448 = V_528 ;
#endif
return 0 ;
error:
F_145 ( V_2 ) ;
return V_81 ;
}
static int F_265 ( struct V_1 * V_2 )
{
return F_220 ( V_2 , NULL , NULL ) ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_81 ;
V_11 = F_197 ( sizeof( * V_11 ) , V_153 ) ;
if ( V_11 == NULL )
return - V_151 ;
V_2 -> V_11 = V_11 ;
V_81 = F_265 ( V_2 ) ;
if ( V_81 < 0 ) {
F_145 ( V_2 ) ;
return V_81 ;
}
if ( ! V_11 -> V_276 && ! V_11 -> V_275 )
F_217 ( V_2 ) ;
V_11 -> V_281 = 0x02 ;
V_2 -> V_344 = V_447 ;
V_11 -> V_291 = F_218 ;
return 0 ;
}
static int T_5 F_267 ( void )
{
return F_268 ( & V_529 ) ;
}
static void T_6 F_269 ( void )
{
F_270 ( & V_529 ) ;
}
