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
static void F_39 ( struct V_1 * V_2 , unsigned int V_123 )
{
if ( V_2 -> V_124 == 0x10ec0880 )
V_123 >>= 28 ;
else
V_123 >>= 26 ;
V_123 = F_40 ( V_2 , V_123 ) ;
F_37 ( V_2 , V_123 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 0 ) ;
V_125 = F_22 ( V_2 , 0x20 , 0 , V_82 , 0 ) ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
if ( ( V_125 & 0xf0 ) == 0x20 )
F_22 ( V_2 , 0x20 , 0 ,
V_83 , 0x830 ) ;
else
F_22 ( V_2 , 0x20 , 0 ,
V_83 , 0x3030 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
V_125 = F_22 ( V_2 , 0x20 , 0 , V_82 , 0 ) ;
F_14 ( V_2 , 0x20 , 0 , V_80 , 7 ) ;
F_14 ( V_2 , 0x20 , 0 , V_83 , V_125 | 0x2010 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_3 , int V_102 )
{
if ( F_17 ( F_2 ( V_2 , V_3 ) ) != V_126 )
return;
if ( F_23 ( V_2 , V_3 ) & V_127 )
F_14 ( V_2 , V_3 , 0 , V_128 ,
V_102 ? 2 : 0 ) ;
}
static void F_45 ( struct V_1 * V_2 , bool V_102 )
{
static T_1 V_88 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_129 ;
for ( V_129 = V_88 ; * V_129 ; V_129 ++ )
F_44 ( V_2 , * V_129 , V_102 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_45 ( V_2 , false ) ;
F_47 ( 200 ) ;
}
static void F_48 ( struct V_1 * V_2 , int type )
{
unsigned int V_125 ;
F_45 ( V_2 , true ) ;
switch ( type ) {
case V_130 :
F_49 ( V_2 , V_131 ) ;
break;
case V_132 :
F_49 ( V_2 , V_133 ) ;
break;
case V_134 :
F_49 ( V_2 , V_135 ) ;
break;
case V_136 :
switch ( V_2 -> V_124 ) {
case 0x10ec0260 :
F_14 ( V_2 , 0x1a , 0 ,
V_80 , 7 ) ;
V_125 = F_22 ( V_2 , 0x1a , 0 ,
V_82 , 0 ) ;
F_14 ( V_2 , 0x1a , 0 ,
V_80 , 7 ) ;
F_14 ( V_2 , 0x1a , 0 ,
V_83 ,
V_125 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_43 ( V_2 ) ;
break;
case 0x10ec0888 :
F_42 ( V_2 ) ;
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
static int F_50 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_137 [] = {
L_1 , L_2
} ;
static const char * const V_138 [] = {
L_1 , L_3 , L_4
} ;
const char * const * V_139 ;
V_9 -> type = V_140 ;
V_9 -> V_141 = 1 ;
if ( V_11 -> V_142 && V_11 -> V_143 ) {
V_9 -> V_20 . V_21 . V_49 = 3 ;
V_139 = V_138 ;
} else {
V_9 -> V_20 . V_21 . V_49 = 2 ;
V_139 = V_137 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_49 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_49 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_144 ,
V_139 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
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
static int F_52 ( struct V_6 * V_7 ,
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
if ( V_11 -> V_142 ) {
if ( ! V_11 -> V_109 && V_11 -> V_45 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_109 = 0 ;
} else if ( V_11 -> V_143 ) {
if ( V_11 -> V_109 )
return 0 ;
V_11 -> V_109 = 1 ;
} else
return - V_145 ;
break;
case 2 :
if ( ! V_11 -> V_143 || ! V_11 -> V_142 )
return - V_145 ;
if ( V_11 -> V_45 && V_11 -> V_109 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_109 = 1 ;
break;
default:
return - V_145 ;
}
F_15 ( V_2 ) ;
return 1 ;
}
static struct V_71 * F_53 ( struct V_10 * V_11 )
{
F_54 ( & V_11 -> V_146 , sizeof( struct V_71 ) , 32 ) ;
return F_55 ( & V_11 -> V_146 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_71 * V_147 ;
V_147 = F_53 ( V_11 ) ;
if ( ! V_147 )
return - V_148 ;
* V_147 = V_149 ;
V_147 -> V_144 = F_57 ( L_5 , V_150 ) ;
if ( ! V_147 -> V_144 )
return - V_148 ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
int V_89 = 0 ;
int V_36 ;
if ( V_152 -> V_103 [ 0 ] )
V_89 ++ ;
if ( V_152 -> V_108 [ 0 ] )
V_89 ++ ;
if ( V_152 -> V_107 [ 0 ] )
V_89 ++ ;
if ( V_89 < 2 )
return;
if ( ! V_152 -> V_107 [ 0 ] &&
V_152 -> V_153 == V_154 ) {
memcpy ( V_152 -> V_107 , V_152 -> V_108 ,
sizeof( V_152 -> V_107 ) ) ;
V_152 -> V_155 = V_152 -> V_156 ;
}
if ( ! V_152 -> V_103 [ 0 ] &&
V_152 -> V_153 == V_157 ) {
memcpy ( V_152 -> V_103 , V_152 -> V_108 ,
sizeof( V_152 -> V_103 ) ) ;
V_152 -> V_158 = V_152 -> V_156 ;
}
V_11 -> V_95 = V_96 ;
for ( V_36 = 0 ; V_36 < V_152 -> V_158 ; V_36 ++ ) {
T_1 V_3 = V_152 -> V_103 [ V_36 ] ;
if ( ! F_59 ( V_2 , V_3 ) )
continue;
F_60 ( L_6 ,
V_3 ) ;
F_61 ( V_2 , V_3 , V_120 ) ;
V_11 -> V_111 = 1 ;
}
if ( V_152 -> V_153 == V_159 && V_152 -> V_156 ) {
if ( V_152 -> V_155 )
for ( V_36 = 0 ; V_36 < V_152 -> V_156 ; V_36 ++ ) {
T_1 V_3 = V_152 -> V_108 [ V_36 ] ;
if ( ! F_59 ( V_2 , V_3 ) )
continue;
F_60 ( L_7
L_8 , V_3 ) ;
F_61 ( V_2 , V_3 ,
V_121 ) ;
V_11 -> V_112 = 1 ;
}
V_11 -> V_143 = V_11 -> V_111 ;
}
V_11 -> V_142 = V_152 -> V_155 &&
( V_11 -> V_111 || V_11 -> V_112 ) ;
V_11 -> V_109 = V_11 -> V_143 ;
V_11 -> V_45 = V_11 -> V_142 ;
if ( V_11 -> V_142 || V_11 -> V_143 ) {
F_56 ( V_2 ) ;
V_11 -> V_160 = F_39 ;
}
}
static int F_62 ( T_1 V_3 , const T_1 * V_161 , int V_162 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_162 ; V_36 ++ )
if ( V_161 [ V_36 ] == V_3 )
return V_36 ;
return - 1 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 = & V_11 -> V_163 [ 0 ] ;
int V_36 , V_164 , V_31 ;
T_1 V_165 , V_41 ;
if ( V_35 != V_11 -> V_15 )
return false ;
for ( V_164 = 0 ; V_164 < V_11 -> V_166 ; V_164 ++ ) {
V_165 = V_11 -> V_167 [ V_164 ] ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_41 = V_11 -> V_113 [ V_36 ] ;
if ( ! V_41 )
return false ;
if ( F_64 ( V_2 , V_165 , V_41 ) < 0 )
break;
}
if ( V_36 >= V_35 -> V_16 )
return true ;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_41 = V_11 -> V_113 [ V_36 ] ;
for ( V_164 = 0 ; V_164 < V_11 -> V_166 ; V_164 ++ ) {
V_165 = V_11 -> V_167 [ V_164 ] ;
V_31 = F_64 ( V_2 , V_165 , V_41 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_49 [ V_36 ] . V_50 = V_31 ;
V_11 -> V_27 [ V_36 ] = V_164 ;
break;
}
}
}
F_60 ( L_9 ) ;
V_11 -> V_46 = 1 ;
return true ;
}
static bool F_65 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 ;
static char * const V_139 [ 3 ] = {
L_10 , L_11 , L_12
} ;
int V_36 ;
if ( ! V_11 -> V_114 )
return false ;
V_35 = & V_11 -> V_163 [ 0 ] ;
if ( V_11 -> V_15 == V_35 )
return true ;
V_11 -> V_113 [ 0 ] = V_11 -> V_168 ;
V_11 -> V_113 [ 1 ] = V_11 -> V_169 ;
V_11 -> V_113 [ 2 ] = V_11 -> V_170 ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ ) {
strcpy ( V_35 -> V_49 [ V_36 ] . V_171 , V_139 [ V_36 ] ) ;
if ( V_11 -> V_113 [ V_36 ] ) {
T_1 V_41 = V_11 -> V_113 [ V_36 ] ;
int V_172 ;
for ( V_172 = 0 ; V_172 < V_11 -> V_166 ; V_172 ++ ) {
T_1 V_165 = F_12 ( V_11 , V_172 ) ;
int V_31 = F_64 ( V_2 , V_165 , V_41 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_49 [ V_36 ] . V_50 = V_31 ;
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
if ( ! V_11 -> V_114 )
return false ;
if ( V_11 -> V_115 )
return true ;
if ( ! F_63 ( V_2 ) ) {
V_11 -> V_114 = 0 ;
return false ;
}
V_35 = V_11 -> V_15 ;
V_11 -> V_117 = F_62 ( V_11 -> V_168 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
V_11 -> V_116 = F_62 ( V_11 -> V_169 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
V_11 -> V_118 = F_62 ( V_11 -> V_170 ,
V_11 -> V_113 , V_35 -> V_16 ) ;
if ( V_11 -> V_117 < 0 || V_11 -> V_116 < 0 ) {
V_11 -> V_114 = 0 ;
return false ;
}
F_61 ( V_2 , V_11 -> V_168 , V_122 ) ;
if ( V_11 -> V_170 )
F_61 ( V_2 , V_11 -> V_170 ,
V_122 ) ;
V_11 -> V_115 = 1 ;
V_11 -> V_114 = 1 ;
return true ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
T_1 V_173 , V_174 , V_175 ;
int V_36 ;
if ( V_11 -> V_38 )
return;
V_11 -> V_117 = V_11 -> V_116 = V_11 -> V_118 = - 1 ;
V_173 = V_174 = V_175 = 0 ;
for ( V_36 = 0 ; V_36 < V_152 -> V_176 ; V_36 ++ ) {
T_1 V_3 = V_152 -> V_40 [ V_36 ] . V_41 ;
unsigned int V_177 ;
V_177 = F_68 ( V_2 , V_3 ) ;
switch ( F_69 ( V_177 ) ) {
case V_178 :
if ( V_173 )
return;
if ( V_152 -> V_40 [ V_36 ] . type != V_58 )
return;
V_173 = V_3 ;
break;
case V_179 :
return;
case V_180 :
if ( V_175 )
return;
if ( V_152 -> V_40 [ V_36 ] . type > V_181 )
return;
V_175 = V_3 ;
break;
default:
if ( V_174 )
return;
if ( V_152 -> V_40 [ V_36 ] . type != V_58 )
return;
V_174 = V_3 ;
break;
}
}
if ( ! V_174 && V_175 ) {
V_174 = V_175 ;
V_175 = 0 ;
}
if ( ! V_174 || ! V_173 )
return;
if ( ! F_59 ( V_2 , V_174 ) )
return;
if ( V_175 && ! F_59 ( V_2 , V_175 ) )
return;
V_11 -> V_168 = V_174 ;
V_11 -> V_169 = V_173 ;
V_11 -> V_170 = V_175 ;
V_11 -> V_114 = 1 ;
if ( ! F_66 ( V_2 ) )
return;
F_60 ( L_13 ,
V_174 , V_173 , V_175 ) ;
V_11 -> V_160 = F_39 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
F_67 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned int V_182 , V_125 , V_36 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_183 . V_184 = 1 ;
if ( V_11 -> V_183 . V_185 ) {
V_182 = V_11 -> V_183 . V_186 ;
if ( V_182 == V_187 )
return - 1 ;
goto V_188;
}
V_182 = V_2 -> V_189 & 0xffff ;
if ( V_182 != V_2 -> V_190 -> V_191 -> V_192 && ( V_182 & 1 ) )
goto V_188;
V_3 = 0x1d ;
if ( V_2 -> V_124 == 0x10ec0260 )
V_3 = 0x17 ;
V_182 = F_68 ( V_2 , V_3 ) ;
if ( ! ( V_182 & 1 ) ) {
F_72 ( V_193 L_14 ,
V_2 -> V_194 , V_182 ) ;
return - 1 ;
}
V_125 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_182 >> V_36 ) & 1 )
V_125 ++ ;
}
if ( ( ( V_182 >> 16 ) & 0xf ) != V_125 )
return - 1 ;
V_11 -> V_183 . V_195 = V_182 >> 30 ;
V_11 -> V_183 . V_184 = ( V_182 & 0x100000 ) >> 20 ;
V_11 -> V_183 . V_196 = ( V_182 >> 16 ) & 0xf ;
V_11 -> V_183 . V_197 = V_182 >> 8 ;
V_188:
V_11 -> V_183 . V_186 = V_182 ;
V_11 -> V_183 . V_198 = ( V_182 & 0x38 ) >> 3 ;
V_11 -> V_183 . V_199 = ( V_182 & 0x4 ) >> 2 ;
V_11 -> V_183 . V_200 = ( V_182 & 0x2 ) >> 1 ;
V_11 -> V_183 . V_201 = V_182 & 0x1 ;
F_73 ( L_15 ,
V_3 , V_11 -> V_183 . V_186 ) ;
F_73 ( L_16 ,
V_11 -> V_183 . V_195 ) ;
F_73 ( L_17 , V_11 -> V_183 . V_184 ) ;
F_73 ( L_18 , V_11 -> V_183 . V_196 ) ;
F_73 ( L_19 , V_11 -> V_183 . V_197 ) ;
F_73 ( L_20 , V_11 -> V_183 . V_198 ) ;
F_73 ( L_21 , V_11 -> V_183 . V_199 ) ;
F_73 ( L_22 , V_11 -> V_183 . V_200 ) ;
F_73 ( L_23 , V_11 -> V_183 . V_201 ) ;
return 0 ;
}
static bool F_74 ( T_1 V_3 , const T_1 * V_161 , int V_162 )
{
return F_62 ( V_3 , V_161 , V_162 ) >= 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_1 V_202 , T_1 V_203 ,
T_1 V_204 , T_1 V_205 )
{
unsigned int V_182 , V_125 , V_36 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_183 . V_185 ) {
V_182 = V_11 -> V_183 . V_186 ;
if ( V_182 == V_187 )
return 0 ;
goto V_188;
}
V_182 = V_2 -> V_189 & 0xffff ;
if ( ( V_182 != V_2 -> V_190 -> V_191 -> V_192 ) && ( V_182 & 1 ) )
goto V_188;
V_3 = 0x1d ;
if ( V_2 -> V_124 == 0x10ec0260 )
V_3 = 0x17 ;
V_182 = F_68 ( V_2 , V_3 ) ;
F_73 ( L_24
L_25 ,
V_182 , V_3 ) ;
if ( ! ( V_182 & 1 ) )
return 0 ;
if ( ( V_182 >> 30 ) != 1 )
return 0 ;
V_125 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_182 >> V_36 ) & 1 )
V_125 ++ ;
}
if ( ( ( V_182 >> 16 ) & 0xf ) != V_125 )
return 0 ;
V_188:
F_73 ( L_26 ,
V_182 & 0xffff , V_2 -> V_124 ) ;
V_125 = ( V_182 & 0x38 ) >> 3 ;
switch ( V_125 ) {
case 1 :
V_11 -> V_206 = V_130 ;
break;
case 3 :
V_11 -> V_206 = V_132 ;
break;
case 7 :
V_11 -> V_206 = V_134 ;
break;
case 5 :
default:
V_11 -> V_206 = V_136 ;
break;
}
if ( ! ( V_182 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_39 . V_103 [ 0 ] &&
! ( V_11 -> V_39 . V_108 [ 0 ] &&
V_11 -> V_39 . V_153 == V_157 ) ) {
T_1 V_3 ;
V_125 = ( V_182 >> 11 ) & 0x3 ;
if ( V_125 == 0 )
V_3 = V_202 ;
else if ( V_125 == 1 )
V_3 = V_203 ;
else if ( V_125 == 2 )
V_3 = V_204 ;
else if ( V_125 == 3 )
V_3 = V_205 ;
else
return 1 ;
if ( F_74 ( V_3 , V_11 -> V_39 . V_108 ,
V_11 -> V_39 . V_156 ) )
return 1 ;
V_11 -> V_39 . V_103 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_76 ( struct V_1 * V_2 , const T_1 * V_207 )
{
if ( ! F_75 ( V_2 , V_207 [ 0 ] , V_207 [ 1 ] , V_207 [ 2 ] , V_207 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_73 ( L_27
L_28 ) ;
V_11 -> V_206 = V_136 ;
}
}
static void F_77 ( struct V_1 * V_2 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = V_11 -> V_208 ;
#ifdef F_78
const char * V_209 = V_11 -> V_210 ;
#endif
int V_211 = 0 ;
if ( ! V_11 -> V_212 )
return;
while ( V_13 >= 0 ) {
const struct V_213 * V_214 = V_11 -> V_212 + V_13 ;
const struct V_215 * V_152 ;
switch ( V_214 -> type ) {
case V_216 :
if ( V_119 != V_217 || ! V_214 -> V_51 . V_218 )
break;
F_60 ( V_193 L_29
L_30 ,
V_2 -> V_194 , V_209 ) ;
V_11 -> V_183 . V_186 = V_214 -> V_51 . V_218 ;
V_11 -> V_183 . V_185 = 1 ;
break;
case V_219 :
V_152 = V_214 -> V_51 . V_88 ;
if ( V_119 != V_217 || ! V_152 )
break;
F_60 ( V_193 L_29
L_31 ,
V_2 -> V_194 , V_209 ) ;
for (; V_152 -> V_3 ; V_152 ++ )
F_79 ( V_2 , V_152 -> V_3 ,
V_152 -> V_56 ) ;
break;
case V_220 :
if ( V_119 != V_221 || ! V_214 -> V_51 . V_222 )
break;
F_60 ( V_193 L_29
L_32 ,
V_2 -> V_194 , V_209 ) ;
F_27 ( V_2 -> V_11 , V_214 -> V_51 . V_222 ) ;
break;
case V_223 :
if ( ! V_214 -> V_51 . V_224 )
break;
F_60 ( V_193 L_29
L_33 ,
V_2 -> V_194 , V_209 ) ;
V_214 -> V_51 . V_224 ( V_2 , V_214 , V_119 ) ;
break;
default:
F_80 ( V_225 L_29
L_34 ,
V_2 -> V_194 , V_214 -> type ) ;
break;
}
if ( ! V_214 -> V_226 )
break;
if ( ++ V_211 > 10 )
break;
V_13 = V_214 -> V_227 ;
}
}
static void F_81 ( struct V_1 * V_2 ,
const struct V_228 * V_229 ,
const struct V_230 * V_231 ,
const struct V_213 * V_232 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_230 * V_233 ;
int V_13 = - 1 ;
const char * V_144 = NULL ;
if ( V_2 -> V_209 && V_229 ) {
while ( V_229 -> V_144 ) {
if ( ! strcmp ( V_2 -> V_209 , V_229 -> V_144 ) ) {
V_13 = V_229 -> V_13 ;
V_144 = V_229 -> V_144 ;
break;
}
V_229 ++ ;
}
}
if ( V_13 < 0 ) {
V_233 = F_82 ( V_2 -> V_190 -> V_191 , V_231 ) ;
if ( V_233 ) {
V_13 = V_233 -> V_20 ;
#ifdef F_78
V_144 = V_233 -> V_144 ;
#endif
}
}
if ( V_13 < 0 ) {
for ( V_233 = V_231 ; V_233 -> V_234 ; V_233 ++ ) {
unsigned int V_235 =
V_233 -> V_236 | ( V_233 -> V_234 << 16 ) ;
if ( V_235 == V_2 -> V_189 ) {
V_13 = V_233 -> V_20 ;
#ifdef F_78
V_144 = V_233 -> V_144 ;
#endif
break;
}
}
}
V_11 -> V_208 = V_13 ;
if ( V_13 >= 0 ) {
V_11 -> V_212 = V_232 ;
V_11 -> V_210 = V_144 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
unsigned int V_85 )
{
unsigned int V_56 ;
F_14 ( V_2 , 0x20 , 0 , V_80 ,
V_85 ) ;
V_56 = F_22 ( V_2 , 0x20 , 0 ,
V_82 , 0 ) ;
return V_56 ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_85 ,
unsigned int V_237 )
{
F_14 ( V_2 , 0x20 , 0 , V_80 ,
V_85 ) ;
F_14 ( V_2 , 0x20 , 0 , V_83 ,
V_237 ) ;
}
static unsigned int F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_238 )
V_11 -> V_238 = F_83 ( V_2 , 0 ) ;
return V_11 -> V_238 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_41 , V_239 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_240 ; V_36 ++ ) {
V_41 = V_11 -> V_39 . V_241 [ V_36 ] ;
if ( ! V_41 )
continue;
F_14 ( V_2 , V_41 , 0 ,
V_42 , V_94 ) ;
if ( ! V_36 )
V_239 = V_11 -> V_242 . V_243 ;
else
V_239 = V_11 -> V_244 [ V_36 - 1 ] ;
if ( ! V_239 || ! ( F_2 ( V_2 , V_239 ) & V_245 ) )
continue;
F_14 ( V_2 , V_239 , 0 ,
V_246 ,
V_247 ) ;
}
V_41 = V_11 -> V_39 . V_248 ;
if ( V_41 )
F_14 ( V_2 , V_41 , 0 ,
V_42 ,
V_57 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_249 , V_162 ;
T_1 V_250 ;
V_162 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_240 ; V_36 ++ ) {
T_1 V_251 [ 4 ] ;
V_249 = F_88 ( V_2 ,
V_11 -> V_39 . V_241 [ V_36 ] ,
V_251 , F_26 ( V_251 ) ) ;
if ( V_249 <= 0 )
continue;
V_250 = V_251 [ 0 ] ;
if ( ! V_162 ) {
V_11 -> V_242 . V_243 = V_250 ;
V_11 -> V_252 = V_11 -> V_39 . V_252 [ 0 ] ;
} else {
V_11 -> V_242 . V_244 = V_11 -> V_244 ;
if ( V_162 >= F_26 ( V_11 -> V_244 ) - 1 )
break;
V_11 -> V_244 [ V_162 - 1 ] = V_250 ;
}
V_162 ++ ;
}
if ( V_11 -> V_39 . V_248 ) {
V_250 = V_2 -> V_253 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_254 ; V_36 ++ , V_250 ++ ) {
unsigned int V_255 = F_2 ( V_2 , V_250 ) ;
if ( F_17 ( V_255 ) != V_256 )
continue;
if ( ! ( V_255 & V_257 ) )
continue;
if ( ! ( V_255 & V_258 ) )
continue;
V_249 = F_64 ( V_2 , V_250 ,
V_11 -> V_39 . V_248 ) ;
if ( V_249 >= 0 ) {
V_11 -> V_259 = V_250 ;
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
unsigned long V_56 ;
int V_249 ;
F_90 ( & V_2 -> V_260 ) ;
if ( V_11 -> V_261 )
V_56 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_99 ) ;
else
V_56 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_262 = V_56 ;
V_249 = F_92 ( V_7 , V_9 ) ;
F_93 ( & V_2 -> V_260 ) ;
return V_249 ;
}
static int F_94 ( struct V_6 * V_7 , int V_263 ,
unsigned int V_264 , unsigned int T_2 * V_265 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_56 ;
int V_249 ;
F_90 ( & V_2 -> V_260 ) ;
if ( V_11 -> V_261 )
V_56 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_99 ) ;
else
V_56 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_262 = V_56 ;
V_249 = F_95 ( V_7 , V_263 , V_264 , V_265 ) ;
F_93 ( & V_2 -> V_260 ) ;
return V_249 ;
}
static int F_96 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_224 , bool V_266 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_249 = 0 ;
F_90 ( & V_2 -> V_260 ) ;
if ( V_266 && V_11 -> V_46 ) {
for ( V_36 = 0 ; V_36 < V_11 -> V_166 ; V_36 ++ ) {
V_7 -> V_262 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_249 = V_224 ( V_7 , V_18 ) ;
if ( V_249 < 0 )
goto error;
}
} else {
V_36 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_261 )
V_7 -> V_262 =
F_91 ( V_11 -> V_32 [ V_36 ] ,
3 , 0 , V_99 ) ;
else
V_7 -> V_262 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_249 = V_224 ( V_7 , V_18 ) ;
}
error:
F_93 ( & V_2 -> V_260 ) ;
return V_249 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_267 , false ) ;
}
static int F_98 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_268 , true ) ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_269 , false ) ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_270 , true ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_271 = NULL ;
const struct V_71 * V_147 ;
int V_36 , V_272 , V_249 ;
unsigned int V_273 ;
T_1 V_3 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
V_249 = F_102 ( V_2 , V_11 -> V_74 [ V_36 ] ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( V_11 -> V_274 ) {
V_249 = F_102 ( V_2 , V_11 -> V_274 ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( V_11 -> V_242 . V_243 ) {
V_249 = F_103 ( V_2 ,
V_11 -> V_242 . V_243 ,
V_11 -> V_242 . V_243 ) ;
if ( V_249 < 0 )
return V_249 ;
if ( ! V_11 -> V_275 ) {
V_249 = F_104 ( V_2 ,
& V_11 -> V_242 ) ;
if ( V_249 < 0 )
return V_249 ;
V_11 -> V_242 . V_276 = 1 ;
}
}
if ( V_11 -> V_259 ) {
V_249 = F_105 ( V_2 , V_11 -> V_259 ) ;
if ( V_249 < 0 )
return V_249 ;
}
#ifdef F_106
if ( V_11 -> V_277 ) {
const struct V_71 * V_147 ;
for ( V_147 = V_278 ; V_147 -> V_144 ; V_147 ++ ) {
struct V_6 * V_271 ;
V_271 = F_107 ( V_147 , V_2 ) ;
if ( ! V_271 )
return - V_148 ;
V_271 -> V_262 = V_11 -> V_277 ;
V_249 = F_108 ( V_2 , 0 , V_271 ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
#endif
if ( ! V_11 -> V_275 &&
! F_109 ( V_2 , L_35 ) ) {
unsigned int V_279 [ 4 ] ;
F_110 ( V_2 , V_11 -> V_280 ,
V_99 , V_279 ) ;
V_249 = F_111 ( V_2 , L_35 ,
V_279 , V_281 ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( ! V_11 -> V_275 &&
! F_109 ( V_2 , L_36 ) ) {
V_249 = F_111 ( V_2 , L_36 ,
NULL , V_282 ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_271 = F_109 ( V_2 , L_37 ) ;
if ( ! V_271 )
V_271 = F_109 ( V_2 , L_38 ) ;
for ( V_36 = 0 ; V_271 && V_36 < V_271 -> V_141 ; V_36 ++ ) {
V_249 = F_112 ( V_2 , V_271 , V_36 ,
F_12 ( V_11 , V_36 ) ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
if ( V_11 -> V_274 && V_11 -> V_26 ) {
const char * V_283 = V_271 ? V_271 -> V_13 . V_144 : NULL ;
for ( V_147 = V_11 -> V_274 ; V_147 -> V_144 ; V_147 ++ ) {
if ( V_283 && strcmp ( V_147 -> V_144 , V_283 ) == 0 )
continue;
V_271 = F_109 ( V_2 , V_147 -> V_144 ) ;
for ( V_36 = 0 ; V_271 && V_36 < V_271 -> V_141 ; V_36 ++ ) {
V_249 = F_112 ( V_2 , V_271 , V_36 ,
V_11 -> V_26 [ V_36 ] ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
}
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
for ( V_147 = V_11 -> V_74 [ V_36 ] ; V_147 -> V_144 ; V_147 ++ ) {
if ( V_147 -> V_284 != V_285 )
continue;
V_271 = F_109 ( V_2 , V_147 -> V_144 ) ;
if ( V_271 == NULL )
continue;
V_273 = V_147 -> V_236 ;
for ( V_272 = 0 ; V_272 < 4 ; V_272 ++ , V_273 >>= 8 ) {
V_3 = V_273 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_273 & 0xc0 ) {
case V_286 :
V_3 = V_11 -> V_39 . V_107 [ V_3 ] ;
break;
case V_287 :
V_3 = V_11 -> V_39 . V_108 [ V_3 ] ;
break;
case V_288 :
V_3 = V_11 -> V_39 . V_103 [ V_3 ] ;
break;
default:
continue;
}
V_249 = F_112 ( V_2 , V_271 , 0 , V_3 ) ;
if ( V_249 < 0 )
return V_249 ;
}
V_273 = V_147 -> V_262 ;
for ( V_272 = 0 ; V_272 < 4 ; V_272 ++ , V_273 >>= 8 ) {
V_3 = V_273 & 0xff ;
if ( V_3 == 0 )
continue;
V_249 = F_112 ( V_2 , V_271 , 0 , V_3 ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
}
F_113 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_249 = F_101 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
return F_115 ( V_2 , & V_11 -> V_39 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_36 ;
if ( V_2 -> V_124 == 0x10ec0269 )
F_117 ( V_2 ) ;
F_28 ( V_2 ) ;
F_48 ( V_2 , V_11 -> V_206 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_77 ; V_36 ++ )
F_49 ( V_2 , V_11 -> V_78 [ V_36 ] ) ;
F_118 ( V_2 ) ;
if ( V_11 -> V_289 )
V_11 -> V_289 ( V_2 ) ;
F_77 ( V_2 , V_290 ) ;
F_38 ( V_2 ) ;
F_119 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 , unsigned int V_123 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_160 )
V_11 -> V_160 ( V_2 , V_123 ) ;
}
static int F_121 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_122 ( V_2 , & V_11 -> V_291 , V_3 ) ;
}
static int F_123 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_124 ( V_2 , & V_11 -> V_242 , V_295 ,
V_293 ) ;
}
static int F_125 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
unsigned int V_296 ,
unsigned int V_297 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_126 ( V_2 , & V_11 -> V_242 ,
V_296 , V_297 , V_295 ) ;
}
static int F_127 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_128 ( V_2 , & V_11 -> V_242 ) ;
}
static int F_129 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_130 ( V_2 , & V_11 -> V_242 ) ;
}
static int F_131 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
unsigned int V_296 ,
unsigned int V_297 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_132 ( V_2 , & V_11 -> V_242 ,
V_296 , V_297 , V_295 ) ;
}
static int F_133 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_134 ( V_2 , & V_11 -> V_242 ) ;
}
static int F_135 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_136 ( V_2 , & V_11 -> V_242 ) ;
}
static int F_137 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
unsigned int V_296 ,
unsigned int V_297 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_295 -> V_298 + 1 ] ,
V_296 , 0 , V_297 ) ;
return 0 ;
}
static int F_138 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_139 ( V_2 ,
V_11 -> V_26 [ V_295 -> V_298 + 1 ] ) ;
return 0 ;
}
static int F_140 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
unsigned int V_296 ,
unsigned int V_297 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_296 ;
V_11 -> V_30 = V_297 ;
F_11 ( V_2 , V_11 -> V_28 , V_296 , 0 , V_297 ) ;
return 0 ;
}
static int F_141 ( struct V_292 * V_293 ,
struct V_1 * V_2 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_139 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_299 * V_300 = V_11 -> V_301 ;
const struct V_292 * V_129 ;
bool V_302 ;
int V_36 ;
V_2 -> V_303 = 1 ;
V_2 -> V_304 = V_300 ;
if ( V_11 -> V_275 )
goto V_305;
snprintf ( V_11 -> V_306 , sizeof( V_11 -> V_306 ) ,
L_39 , V_2 -> V_194 ) ;
V_300 -> V_144 = V_11 -> V_306 ;
if ( V_11 -> V_242 . V_307 > 0 ) {
V_129 = V_11 -> V_308 ;
if ( ! V_129 )
V_129 = & V_309 ;
V_300 -> V_310 [ V_311 ] = * V_129 ;
V_300 -> V_310 [ V_311 ] . V_3 = V_11 -> V_242 . V_312 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_129 = V_11 -> V_313 ;
if ( ! V_129 ) {
if ( V_11 -> V_46 )
V_129 = & V_314 ;
else
V_129 = & V_315 ;
}
V_300 -> V_310 [ V_316 ] = * V_129 ;
V_300 -> V_310 [ V_316 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_317 ) {
V_300 -> V_310 [ V_311 ] . V_318 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_319 ; V_36 ++ ) {
if ( V_11 -> V_317 [ V_36 ] . V_320 > V_300 -> V_310 [ V_311 ] . V_318 ) {
V_300 -> V_310 [ V_311 ] . V_318 = V_11 -> V_317 [ V_36 ] . V_320 ;
}
}
}
V_305:
if ( V_11 -> V_242 . V_243 || V_11 -> V_259 ) {
snprintf ( V_11 -> V_321 ,
sizeof( V_11 -> V_321 ) ,
L_40 , V_2 -> V_194 ) ;
V_2 -> V_303 = 2 ;
V_2 -> V_244 = V_11 -> V_242 . V_244 ;
V_300 = V_11 -> V_301 + 1 ;
V_300 -> V_144 = V_11 -> V_321 ;
if ( V_11 -> V_252 )
V_300 -> V_322 = V_11 -> V_252 ;
else
V_300 -> V_322 = V_323 ;
if ( V_11 -> V_242 . V_243 ) {
V_129 = V_11 -> V_324 ;
if ( ! V_129 )
V_129 = & V_325 ;
V_300 -> V_310 [ V_311 ] = * V_129 ;
V_300 -> V_310 [ V_311 ] . V_3 = V_11 -> V_242 . V_243 ;
}
if ( V_11 -> V_259 ) {
V_129 = V_11 -> V_326 ;
if ( ! V_129 )
V_129 = & V_327 ;
V_300 -> V_310 [ V_316 ] = * V_129 ;
V_300 -> V_310 [ V_316 ] . V_3 = V_11 -> V_259 ;
}
V_2 -> V_328 = 1 ;
}
if ( V_11 -> V_275 )
return 0 ;
V_302 = ( V_11 -> V_166 > 1 ) &&
! V_11 -> V_46 && ! V_11 -> V_114 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_329 || V_302 ) {
V_2 -> V_303 = 3 ;
V_300 = V_11 -> V_301 + 2 ;
V_300 -> V_144 = V_11 -> V_306 ;
if ( V_11 -> V_329 ) {
V_129 = V_11 -> V_330 ;
if ( ! V_129 )
V_129 = & V_331 ;
V_300 -> V_310 [ V_311 ] = * V_129 ;
V_300 -> V_310 [ V_311 ] . V_3 =
V_11 -> V_329 ;
} else {
V_300 -> V_310 [ V_311 ] =
V_332 ;
V_300 -> V_310 [ V_311 ] . V_3 = 0 ;
}
if ( V_302 ) {
V_129 = V_11 -> V_333 ;
if ( ! V_129 )
V_129 = & V_334 ;
V_300 -> V_310 [ V_316 ] = * V_129 ;
V_300 -> V_310 [ V_316 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_300 -> V_310 [ V_316 ] . V_335 =
V_11 -> V_166 - 1 ;
} else {
V_300 -> V_310 [ V_316 ] =
V_332 ;
V_300 -> V_310 [ V_316 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_143 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_336 )
V_11 -> V_336 ( V_2 ) ;
F_144 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_146 . V_161 ) {
struct V_71 * V_271 = V_11 -> V_146 . V_161 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_146 . V_337 ; V_36 ++ )
F_145 ( V_271 [ V_36 ] . V_144 ) ;
}
F_146 ( & V_11 -> V_146 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_338 . V_161 ) {
struct V_339 * * V_340 = V_11 -> V_338 . V_161 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_338 . V_337 ; V_36 ++ )
F_145 ( V_340 [ V_36 ] ) ;
}
F_146 ( & V_11 -> V_338 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_143 ( V_2 ) ;
F_113 ( V_2 ) ;
F_147 ( V_2 ) ;
F_145 ( V_11 ) ;
F_149 ( V_2 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_45 ( V_2 , false ) ;
}
static int F_151 ( struct V_1 * V_2 , T_4 V_341 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_143 ( V_2 ) ;
if ( V_11 && V_11 -> V_342 )
V_11 -> V_342 ( V_2 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 )
{
F_47 ( 150 ) ;
V_2 -> V_343 . V_344 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
F_119 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , const char * V_144 )
{
F_145 ( V_2 -> V_194 ) ;
V_2 -> V_194 = F_57 ( V_144 , V_150 ) ;
if ( ! V_2 -> V_194 ) {
F_148 ( V_2 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
const struct V_345 * V_129 ;
for ( V_129 = V_346 ; V_129 -> V_124 ; V_129 ++ ) {
if ( V_129 -> V_124 != V_2 -> V_124 )
continue;
if ( ( F_85 ( V_2 ) & V_129 -> V_347 ) == V_129 -> V_348 )
return F_155 ( V_2 , V_129 -> V_144 ) ;
}
return 0 ;
}
static int F_157 ( struct V_10 * V_11 , int type , const char * V_144 ,
int V_349 , unsigned long V_56 )
{
struct V_71 * V_147 ;
V_147 = F_53 ( V_11 ) ;
if ( ! V_147 )
return - V_148 ;
* V_147 = V_350 [ type ] ;
V_147 -> V_144 = F_57 ( V_144 , V_150 ) ;
if ( ! V_147 -> V_144 )
return - V_148 ;
V_147 -> V_50 = V_349 ;
if ( F_158 ( V_56 ) )
V_147 -> V_236 = V_351 ;
V_147 -> V_262 = V_56 ;
return 0 ;
}
static int F_159 ( struct V_10 * V_11 , int type ,
const char * V_352 , const char * V_4 ,
const char * V_353 , int V_349 , unsigned long V_56 )
{
char V_144 [ 32 ] ;
snprintf ( V_144 , sizeof( V_144 ) , L_41 , V_352 , V_4 , V_353 ) ;
return F_157 ( V_11 , type , V_144 , V_349 , V_56 ) ;
}
static const char * F_160 ( struct V_10 * V_11 , int V_354 ,
bool V_355 , int * V_50 )
{
struct V_151 * V_152 = & V_11 -> V_39 ;
* V_50 = 0 ;
if ( V_152 -> V_156 == 1 && ! V_11 -> V_356 &&
! V_152 -> V_158 && ! V_152 -> V_155 && V_355 )
return L_42 ;
switch ( V_152 -> V_153 ) {
case V_154 :
if ( V_152 -> V_156 == 1 )
return L_43 ;
if ( V_152 -> V_156 == 2 )
return V_354 ? L_44 : L_43 ;
break;
case V_157 :
if ( V_354 && V_11 -> V_356 )
break;
* V_50 = V_354 ;
return L_45 ;
default:
if ( V_152 -> V_156 == 1 && ! V_11 -> V_356 )
return L_46 ;
break;
}
if ( F_25 ( V_354 >= F_26 ( V_357 ) ) )
return L_46 ;
return V_357 [ V_354 ] ;
}
static int F_161 ( struct V_10 * V_11 , T_1 V_41 ,
const char * V_358 , int V_359 ,
int V_31 , T_1 V_360 )
{
int V_249 ;
V_249 = F_162 ( V_11 , V_361 , V_358 , V_359 ,
F_91 ( V_360 , 3 , V_31 , V_53 ) ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_163 ( V_11 , V_362 , V_358 , V_359 ,
F_91 ( V_360 , 3 , V_31 , V_53 ) ) ;
if ( V_249 < 0 )
return V_249 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_59 = F_23 ( V_2 , V_3 ) ;
return ( V_59 & V_363 ) != 0 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_364 ;
T_1 * V_365 = V_11 -> V_167 ;
int V_366 = F_26 ( V_11 -> V_364 ) ;
int V_36 , V_162 = 0 ;
if ( V_11 -> V_38 )
V_366 = 1 ;
V_3 = V_2 -> V_253 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_254 ; V_36 ++ , V_3 ++ ) {
T_1 V_367 ;
const T_1 * V_161 ;
unsigned int V_368 = F_2 ( V_2 , V_3 ) ;
int type = F_17 ( V_368 ) ;
if ( type != V_256 || ( V_368 & V_257 ) )
continue;
V_26 [ V_162 ] = V_3 ;
V_365 [ V_162 ] = V_3 ;
V_367 = V_3 ;
for (; ; ) {
int V_164 ;
type = F_17 ( F_2 ( V_2 , V_367 ) ) ;
if ( type == V_126 )
break;
if ( type == V_369 ) {
V_365 [ V_162 ] = V_367 ;
break;
}
V_164 = F_16 ( V_2 , V_367 , & V_161 ) ;
if ( V_164 > 1 ) {
V_365 [ V_162 ] = V_367 ;
break;
} else if ( V_164 != 1 )
break;
V_367 = * V_161 ;
}
if ( ++ V_162 >= V_366 )
break;
}
V_11 -> V_26 = V_11 -> V_364 ;
V_11 -> V_32 = V_11 -> V_167 ;
V_11 -> V_166 = V_162 ;
return V_162 ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_151 * V_152 = & V_11 -> V_39 ;
T_1 V_370 = V_11 -> V_371 ;
struct V_34 * V_35 = & V_11 -> V_163 [ 0 ] ;
int V_372 ;
int V_36 , V_172 , V_249 , V_31 , V_373 = 0 ;
const char * V_374 = NULL ;
V_372 = F_165 ( V_2 ) ;
if ( V_372 < 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_152 -> V_176 ; V_36 ++ ) {
T_1 V_41 ;
const char * V_171 ;
V_41 = V_152 -> V_40 [ V_36 ] . V_41 ;
if ( ! F_164 ( V_2 , V_41 ) )
continue;
V_171 = F_167 ( V_2 , V_152 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_171 , L_47 ) )
V_171 = L_48 ;
if ( V_374 && ! strcmp ( V_171 , V_374 ) )
V_373 ++ ;
else
V_373 = 0 ;
V_374 = V_171 ;
if ( V_370 ) {
V_31 = F_64 ( V_2 , V_370 , V_41 ) ;
if ( V_31 >= 0 ) {
V_249 = F_161 ( V_11 , V_41 ,
V_171 , V_373 ,
V_31 , V_370 ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
for ( V_172 = 0 ; V_172 < V_372 ; V_172 ++ ) {
T_1 V_165 = F_12 ( V_11 , V_172 ) ;
V_31 = F_64 ( V_2 , V_165 , V_41 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_113 [ V_35 -> V_16 ] = V_41 ;
F_168 ( V_35 , V_171 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_35 ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
unsigned int V_177 ;
T_1 V_3 ;
if ( V_152 -> V_176 != 1 )
return 0 ;
V_177 = F_68 ( V_2 , V_152 -> V_40 [ 0 ] . V_41 ) ;
if ( F_69 ( V_177 ) != V_178 )
return 0 ;
if ( V_152 -> V_158 == 1 && V_152 -> V_153 == V_154 )
V_3 = V_152 -> V_103 [ 0 ] ;
else if ( V_152 -> V_156 == 1 && V_152 -> V_153 == V_157 )
V_3 = V_152 -> V_108 [ 0 ] ;
else
return 0 ;
if ( ! ( F_23 ( V_2 , V_3 ) & V_363 ) )
return 0 ;
V_152 -> V_40 [ 1 ] . V_41 = V_3 ;
V_152 -> V_40 [ 1 ] . type = V_58 ;
V_152 -> V_176 = 2 ;
V_11 -> V_38 = 1 ;
F_60 ( L_49 , V_3 ) ;
return 0 ;
}
static void F_170 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_375 )
{
F_14 ( V_2 , V_3 , 0 , V_42 ,
V_375 ) ;
if ( F_171 ( V_2 , V_3 , V_99 ) )
F_14 ( V_2 , V_3 , 0 , V_246 ,
V_247 ) ;
}
static int F_172 ( int V_153 )
{
if ( V_153 == V_157 )
return V_44 ;
else
return V_94 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_152 -> V_176 ; V_36 ++ ) {
T_1 V_3 = V_152 -> V_40 [ V_36 ] . V_41 ;
if ( F_164 ( V_2 , V_3 ) ) {
F_21 ( V_2 , V_3 , V_152 -> V_40 [ V_36 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_245 )
F_14 ( V_2 , V_3 , 0 ,
V_246 ,
V_376 ) ;
}
}
if ( V_11 -> V_371 ) {
int V_162 = F_16 ( V_2 , V_11 -> V_371 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_162 ; V_36 ++ )
F_14 ( V_2 , V_11 -> V_371 , 0 ,
V_246 ,
F_174 ( V_36 ) ) ;
}
}
static T_1 F_175 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_161 [ 5 ] ;
int V_36 , V_377 ;
if ( F_17 ( F_2 ( V_2 , V_3 ) ) == V_378 )
return V_3 ;
V_377 = F_88 ( V_2 , V_3 , V_161 , F_26 ( V_161 ) ) ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
if ( F_17 ( F_2 ( V_2 , V_161 [ V_36 ] ) ) == V_378 )
return V_161 [ V_36 ] ;
}
return 0 ;
}
static T_1 F_176 ( struct V_1 * V_2 , T_1 V_41 )
{
T_1 V_379 [ 5 ] ;
int V_377 = F_88 ( V_2 , V_41 , V_379 ,
F_26 ( V_379 ) ) ;
if ( V_377 != 1 ||
F_17 ( F_2 ( V_2 , V_379 [ 0 ] ) ) != V_369 )
return V_41 ;
return V_379 [ 0 ] ;
}
static T_1 F_177 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_239 )
{
T_1 V_72 [ 5 ] ;
int V_36 , V_377 ;
V_41 = F_176 ( V_2 , V_41 ) ;
V_377 = F_88 ( V_2 , V_41 , V_72 , F_26 ( V_72 ) ) ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
if ( F_175 ( V_2 , V_72 [ V_36 ] ) == V_239 )
return V_72 [ V_36 ] ;
}
return 0 ;
}
static int F_178 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_239 )
{
T_1 V_72 [ 5 ] ;
int V_36 , V_377 ;
V_41 = F_176 ( V_2 , V_41 ) ;
V_377 = F_88 ( V_2 , V_41 , V_72 , F_26 ( V_72 ) ) ;
if ( V_377 < 2 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
if ( F_175 ( V_2 , V_72 [ V_36 ] ) == V_239 ) {
F_179 ( V_2 , V_41 , 0 ,
V_54 , V_36 ) ;
return 0 ;
}
}
return 0 ;
}
static T_1 F_180 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_379 [ 5 ] ;
int V_36 , V_377 ;
V_41 = F_176 ( V_2 , V_41 ) ;
V_377 = F_88 ( V_2 , V_41 , V_379 , F_26 ( V_379 ) ) ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
T_1 V_3 = F_175 ( V_2 , V_379 [ V_36 ] ) ;
if ( ! V_3 )
continue;
if ( F_74 ( V_3 , V_11 -> V_242 . V_312 ,
F_26 ( V_11 -> V_380 ) ) )
continue;
if ( F_74 ( V_3 , V_11 -> V_242 . V_381 ,
F_26 ( V_11 -> V_242 . V_381 ) ) )
continue;
if ( F_74 ( V_3 , V_11 -> V_242 . V_382 ,
F_26 ( V_11 -> V_242 . V_382 ) ) )
continue;
return V_3 ;
}
return 0 ;
}
static bool F_181 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_239 )
{
T_1 V_379 [ 5 ] ;
int V_36 , V_377 ;
V_41 = F_176 ( V_2 , V_41 ) ;
V_377 = F_88 ( V_2 , V_41 , V_379 , F_26 ( V_379 ) ) ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
T_1 V_3 = F_175 ( V_2 , V_379 [ V_36 ] ) ;
if ( V_3 == V_239 )
return true ;
}
return false ;
}
static T_1 F_182 ( struct V_1 * V_2 , T_1 V_41 )
{
T_1 V_383 = F_176 ( V_2 , V_41 ) ;
if ( F_16 ( V_2 , V_383 , NULL ) == 1 )
return F_180 ( V_2 , V_41 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , int V_384 ,
const T_1 * V_88 , T_1 * V_385 )
{
int V_36 ;
if ( V_384 && ! V_385 [ 0 ] ) {
V_385 [ 0 ] = F_180 ( V_2 , V_88 [ 0 ] ) ;
if ( ! V_385 [ 0 ] )
return 0 ;
}
for ( V_36 = 1 ; V_36 < V_384 ; V_36 ++ )
V_385 [ V_36 ] = F_182 ( V_2 , V_88 [ V_36 ] ) ;
for ( V_36 = 1 ; V_36 < V_384 ; V_36 ++ ) {
if ( ! V_385 [ V_36 ] )
V_385 [ V_36 ] = F_180 ( V_2 , V_88 [ V_36 ] ) ;
}
return 1 ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
unsigned int V_386 , V_177 ;
int V_87 ;
bool V_387 = false ;
int V_36 ;
V_388:
V_11 -> V_242 . V_307 = V_152 -> V_156 ;
V_11 -> V_242 . V_381 [ 0 ] = 0 ;
V_11 -> V_242 . V_382 [ 0 ] = 0 ;
memset ( V_11 -> V_380 , 0 , sizeof( V_11 -> V_380 ) ) ;
V_11 -> V_242 . V_312 = V_11 -> V_380 ;
V_11 -> V_356 = 0 ;
if ( ! V_387 ) {
for ( V_36 = 0 ; V_36 < V_152 -> V_156 ; V_36 ++ )
V_11 -> V_380 [ V_36 ] =
F_182 ( V_2 , V_152 -> V_108 [ V_36 ] ) ;
if ( V_152 -> V_158 )
V_11 -> V_242 . V_381 [ 0 ] =
F_182 ( V_2 , V_152 -> V_103 [ 0 ] ) ;
if ( V_152 -> V_155 )
V_11 -> V_242 . V_382 [ 0 ] =
F_182 ( V_2 , V_152 -> V_107 [ 0 ] ) ;
}
for ( V_36 = 0 ; V_36 < V_152 -> V_156 ; V_36 ++ ) {
T_1 V_41 = V_152 -> V_108 [ V_36 ] ;
if ( V_11 -> V_380 [ V_36 ] )
continue;
V_11 -> V_380 [ V_36 ] = F_180 ( V_2 , V_41 ) ;
if ( ! V_11 -> V_380 [ V_36 ] && ! V_387 ) {
V_387 = true ;
goto V_388;
}
}
V_11 -> V_242 . V_307 = 0 ;
for ( V_36 = 0 ; V_36 < V_152 -> V_156 ; V_36 ++ ) {
if ( V_11 -> V_380 [ V_36 ] )
V_11 -> V_242 . V_307 ++ ;
else {
memmove ( V_11 -> V_380 + V_36 ,
V_11 -> V_380 + V_36 + 1 ,
sizeof( T_1 ) * ( V_152 -> V_156 - V_36 - 1 ) ) ;
V_11 -> V_380 [ V_152 -> V_156 - 1 ] = 0 ;
}
}
if ( V_152 -> V_156 == 1 && V_152 -> V_153 != V_154 ) {
V_177 = F_68 ( V_2 , V_152 -> V_108 [ 0 ] ) ;
V_386 = F_185 ( V_177 ) ;
V_87 = F_186 ( V_2 , V_386 , 0 ) ;
if ( V_87 > 0 ) {
V_11 -> V_356 = V_87 ;
V_11 -> V_389 = 2 ;
V_11 -> V_242 . V_307 = V_87 + 1 ;
}
}
if ( V_152 -> V_153 != V_157 )
F_183 ( V_2 , V_152 -> V_158 , V_152 -> V_103 ,
V_11 -> V_242 . V_381 ) ;
if ( V_152 -> V_153 != V_154 ) {
int V_249 = F_183 ( V_2 , V_152 -> V_155 ,
V_152 -> V_107 ,
V_11 -> V_242 . V_382 ) ;
if ( ! V_249 && V_152 -> V_155 > 0 &&
V_152 -> V_153 == V_157 ) {
V_152 -> V_158 = V_152 -> V_156 ;
memcpy ( V_152 -> V_103 , V_152 -> V_108 ,
sizeof( V_152 -> V_103 ) ) ;
V_152 -> V_156 = V_152 -> V_155 ;
memcpy ( V_152 -> V_108 , V_152 -> V_107 ,
sizeof( V_152 -> V_107 ) ) ;
V_152 -> V_155 = 0 ;
memset ( V_152 -> V_107 , 0 , sizeof( V_152 -> V_107 ) ) ;
V_152 -> V_153 = V_154 ;
V_387 = false ;
goto V_388;
}
}
if ( ! V_11 -> V_356 &&
V_152 -> V_153 == V_154 &&
V_152 -> V_158 ) {
V_177 = F_68 ( V_2 , V_152 -> V_103 [ 0 ] ) ;
V_386 = F_185 ( V_177 ) ;
V_87 = F_186 ( V_2 , V_386 , 1 ) ;
if ( V_87 > 0 ) {
V_11 -> V_356 = V_87 ;
V_11 -> V_389 = 2 ;
V_11 -> V_242 . V_307 = V_87 + 1 ;
}
}
if ( V_152 -> V_108 [ 0 ] )
V_11 -> V_280 =
F_187 ( V_2 , V_152 -> V_108 [ 0 ] ,
V_11 -> V_242 . V_312 [ 0 ] ) ;
return 0 ;
}
static inline unsigned int F_188 ( unsigned int V_390 )
{
T_1 V_3 = F_158 ( V_390 ) ;
unsigned int V_4 ;
if ( F_25 ( V_3 >= V_391 ) )
return 0 ;
V_4 = F_189 ( V_390 ) ;
return ( V_3 << 1 ) | V_4 ;
}
static int F_190 ( struct V_1 * V_2 ,
const char * V_352 , int V_349 ,
T_1 V_3 , unsigned int V_392 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 ;
if ( ! V_3 )
return 0 ;
V_56 = F_91 ( V_3 , V_392 , 0 , V_99 ) ;
if ( F_191 ( V_11 -> V_393 , V_56 ) && V_392 != 2 )
return 0 ;
F_192 ( V_11 -> V_393 , V_56 ) ;
return F_162 ( V_2 -> V_11 , V_361 , V_352 , V_349 ,
V_56 ) ;
}
static int F_193 ( struct V_1 * V_2 ,
const char * V_352 , int V_349 ,
T_1 V_3 )
{
int V_392 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_394 )
V_392 = 3 ;
return F_190 ( V_2 , V_352 , V_349 , V_3 , V_392 ) ;
}
static int F_194 ( struct V_1 * V_2 ,
const char * V_352 , int V_349 ,
T_1 V_3 , unsigned int V_392 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_395 ;
int type ;
unsigned long V_56 ;
if ( ! V_3 )
return 0 ;
V_395 = F_17 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_395 == V_126 || V_395 == V_378 ) {
type = V_362 ;
V_56 = F_91 ( V_3 , V_392 , 0 , V_99 ) ;
} else if ( F_16 ( V_2 , V_3 , NULL ) == 1 ) {
type = V_362 ;
V_56 = F_91 ( V_3 , V_392 , 0 , V_53 ) ;
} else {
type = V_396 ;
V_56 = F_91 ( V_3 , V_392 , 2 , V_53 ) ;
}
if ( F_191 ( V_11 -> V_397 , V_56 ) && V_392 != 2 )
return 0 ;
F_192 ( V_11 -> V_397 , V_56 ) ;
return F_163 ( V_2 -> V_11 , type , V_352 , V_349 , V_56 ) ;
}
static int F_195 ( struct V_1 * V_2 , const char * V_352 ,
int V_349 , T_1 V_3 )
{
int V_392 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_394 )
V_392 = 3 ;
return F_194 ( V_2 , V_352 , V_349 , V_3 , V_392 ) ;
}
static T_1 F_196 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_239 )
{
T_1 V_72 = F_177 ( V_2 , V_41 , V_239 ) ;
if ( F_171 ( V_2 , V_41 , V_99 ) )
return V_41 ;
else if ( V_72 && F_171 ( V_2 , V_72 , V_53 ) )
return V_72 ;
else if ( F_171 ( V_2 , V_239 , V_99 ) )
return V_239 ;
return 0 ;
}
static T_1 F_187 ( struct V_1 * V_2 ,
T_1 V_41 , T_1 V_239 )
{
T_1 V_72 = F_177 ( V_2 , V_41 , V_239 ) ;
if ( F_197 ( V_2 , V_239 , V_99 ) )
return V_239 ;
else if ( F_197 ( V_2 , V_72 , V_99 ) )
return V_72 ;
else if ( F_197 ( V_2 , V_41 , V_99 ) )
return V_41 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 ,
const struct V_151 * V_152 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_249 , V_398 ;
V_398 = V_152 -> V_156 ;
if ( V_11 -> V_356 > 0 && V_152 -> V_156 < 3 )
V_398 += V_11 -> V_356 ;
for ( V_36 = 0 ; V_36 < V_398 ; V_36 ++ ) {
const char * V_144 ;
int V_50 ;
T_1 V_239 , V_41 ;
T_1 V_399 , V_400 ;
V_239 = V_11 -> V_242 . V_312 [ V_36 ] ;
if ( ! V_239 )
continue;
if ( V_36 >= V_152 -> V_156 )
V_41 = V_11 -> V_401 [ V_36 - 1 ] . V_41 ;
else
V_41 = V_152 -> V_108 [ V_36 ] ;
V_399 = F_196 ( V_2 , V_41 , V_239 ) ;
V_400 = F_187 ( V_2 , V_41 , V_239 ) ;
V_144 = F_160 ( V_11 , V_36 , true , & V_50 ) ;
if ( ! V_144 || ! strcmp ( V_144 , L_50 ) ) {
V_249 = F_190 ( V_2 , L_51 , 0 , V_400 , 1 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_190 ( V_2 , L_52 , 0 , V_400 , 2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_194 ( V_2 , L_51 , 0 , V_399 , 1 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_194 ( V_2 , L_52 , 0 , V_399 , 2 ) ;
if ( V_249 < 0 )
return V_249 ;
} else {
V_249 = F_193 ( V_2 , V_144 , V_50 , V_400 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_195 ( V_2 , V_144 , V_50 , V_399 ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , T_1 V_41 ,
T_1 V_239 , const char * V_352 ,
int V_349 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_399 , V_400 ;
int V_249 ;
if ( ! V_239 ) {
unsigned int V_56 ;
if ( ! ( F_2 ( V_2 , V_41 ) & V_245 ) )
return 0 ;
V_56 = F_91 ( V_41 , 3 , 0 , V_99 ) ;
if ( F_191 ( V_11 -> V_397 , V_56 ) )
return 0 ;
F_192 ( V_11 -> V_397 , V_56 ) ;
return F_163 ( V_11 , V_362 , V_352 , V_349 , V_56 ) ;
}
V_399 = F_196 ( V_2 , V_41 , V_239 ) ;
V_400 = F_187 ( V_2 , V_41 , V_239 ) ;
V_249 = F_193 ( V_2 , V_352 , V_349 , V_400 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_195 ( V_2 , V_352 , V_349 , V_399 ) ;
if ( V_249 < 0 )
return V_249 ;
return 0 ;
}
static struct V_339 * F_200 ( struct V_1 * V_2 ,
unsigned int V_162 ,
struct V_402 * V_403 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_339 * * V_404 , * V_340 ;
F_54 ( & V_11 -> V_338 , sizeof( V_340 ) , 8 ) ;
V_404 = F_55 ( & V_11 -> V_338 ) ;
if ( ! V_404 )
return NULL ;
V_340 = F_201 ( sizeof( * V_340 ) + sizeof( long ) * ( V_162 + 1 ) , V_150 ) ;
* V_404 = V_340 ;
if ( V_340 )
V_340 -> V_403 = V_403 ;
return V_340 ;
}
static int F_202 ( struct V_1 * V_2 , int V_87 ,
const T_1 * V_88 ,
const T_1 * V_385 ,
const char * V_352 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_339 * V_340 ;
char V_144 [ 32 ] ;
int V_36 , V_164 , V_249 ;
if ( ! V_87 || ! V_88 [ 0 ] )
return 0 ;
if ( V_87 == 1 ) {
T_1 V_239 = * V_385 ;
if ( ! V_239 )
V_239 = V_11 -> V_242 . V_312 [ 0 ] ;
return F_199 ( V_2 , * V_88 , V_239 , V_352 , 0 ) ;
}
if ( V_385 [ V_87 - 1 ] ) {
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
if ( V_87 >= 3 ) {
snprintf ( V_144 , sizeof( V_144 ) , L_53 ,
V_352 , V_357 [ V_36 ] ) ;
V_249 = F_199 ( V_2 , V_88 [ V_36 ] , V_385 [ V_36 ] ,
V_144 , 0 ) ;
} else {
V_249 = F_199 ( V_2 , V_88 [ V_36 ] , V_385 [ V_36 ] ,
V_352 , V_36 ) ;
}
if ( V_249 < 0 )
return V_249 ;
}
return 0 ;
}
V_340 = F_200 ( V_2 , V_87 , & V_405 ) ;
if ( ! V_340 )
return - V_148 ;
V_164 = 0 ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
if ( F_2 ( V_2 , V_88 [ V_36 ] ) & V_245 )
V_340 -> V_406 [ V_164 ++ ] =
F_91 ( V_88 [ V_36 ] , 3 , 0 , V_99 ) ;
}
if ( V_164 ) {
snprintf ( V_144 , sizeof( V_144 ) , L_54 , V_352 ) ;
V_249 = F_157 ( V_11 , V_407 , V_144 , 0 , ( long ) V_340 ) ;
if ( V_249 < 0 )
return V_249 ;
}
V_340 = F_200 ( V_2 , V_87 , & V_408 ) ;
if ( ! V_340 )
return - V_148 ;
V_164 = 0 ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ ) {
T_1 V_400 ;
if ( ! V_88 [ V_36 ] || ! V_385 [ V_36 ] )
continue;
V_400 = F_187 ( V_2 , V_88 [ V_36 ] , V_385 [ V_36 ] ) ;
if ( V_400 )
V_340 -> V_406 [ V_164 ++ ] =
F_91 ( V_400 , 3 , 0 , V_99 ) ;
}
if ( V_164 ) {
snprintf ( V_144 , sizeof( V_144 ) , L_55 , V_352 ) ;
V_249 = F_157 ( V_11 , V_409 , V_144 , 0 , ( long ) V_340 ) ;
if ( V_249 < 0 )
return V_249 ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_202 ( V_2 , V_11 -> V_39 . V_158 ,
V_11 -> V_39 . V_103 ,
V_11 -> V_242 . V_381 ,
L_45 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_202 ( V_2 , V_11 -> V_39 . V_155 ,
V_11 -> V_39 . V_107 ,
V_11 -> V_242 . V_382 ,
L_43 ) ;
}
static void F_205 ( struct V_1 * V_2 ,
T_1 V_41 , int V_375 ,
T_1 V_239 )
{
int V_36 , V_377 ;
T_1 V_3 , V_72 = 0 ;
T_1 V_379 [ V_410 ] ;
F_170 ( V_2 , V_41 , V_375 ) ;
V_3 = F_176 ( V_2 , V_41 ) ;
V_377 = F_88 ( V_2 , V_3 , V_379 , F_26 ( V_379 ) ) ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
if ( F_175 ( V_2 , V_379 [ V_36 ] ) != V_239 )
continue;
V_72 = V_379 [ V_36 ] ;
break;
}
if ( ! V_72 )
return;
if ( V_377 > 1 )
F_14 ( V_2 , V_3 , 0 , V_54 , V_36 ) ;
if ( F_171 ( V_2 , V_72 , V_53 ) ) {
F_14 ( V_2 , V_72 , 0 , V_246 ,
F_206 ( 0 ) ) ;
F_14 ( V_2 , V_72 , 0 , V_246 ,
F_206 ( 1 ) ) ;
}
V_3 = F_187 ( V_2 , V_41 , V_239 ) ;
if ( V_3 )
F_14 ( V_2 , V_3 , 0 , V_246 ,
V_411 ) ;
V_3 = F_196 ( V_2 , V_41 , V_239 ) ;
if ( V_3 == V_72 && F_171 ( V_2 , V_239 , V_99 ) )
F_14 ( V_2 , V_239 , 0 , V_246 ,
V_411 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_375 = F_172 ( V_11 -> V_39 . V_153 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_412 ; V_36 ++ ) {
T_1 V_3 = V_11 -> V_39 . V_108 [ V_36 ] ;
if ( V_3 )
F_205 ( V_2 , V_3 , V_375 ,
V_11 -> V_242 . V_312 [ V_36 ] ) ;
}
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_41 , V_239 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_158 ; V_36 ++ ) {
if ( V_11 -> V_39 . V_153 == V_157 )
break;
V_41 = V_11 -> V_39 . V_103 [ V_36 ] ;
if ( ! V_41 )
break;
V_239 = V_11 -> V_242 . V_381 [ V_36 ] ;
if ( ! V_239 ) {
if ( V_36 > 0 && V_11 -> V_242 . V_381 [ 0 ] )
V_239 = V_11 -> V_242 . V_381 [ 0 ] ;
else
V_239 = V_11 -> V_242 . V_312 [ 0 ] ;
}
F_205 ( V_2 , V_41 , V_44 , V_239 ) ;
}
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_155 ; V_36 ++ ) {
if ( V_11 -> V_39 . V_153 == V_154 )
break;
V_41 = V_11 -> V_39 . V_107 [ V_36 ] ;
if ( ! V_41 )
break;
V_239 = V_11 -> V_242 . V_382 [ V_36 ] ;
if ( ! V_239 ) {
if ( V_36 > 0 && V_11 -> V_242 . V_382 [ 0 ] )
V_239 = V_11 -> V_242 . V_382 [ 0 ] ;
else
V_239 = V_11 -> V_242 . V_312 [ 0 ] ;
}
F_205 ( V_2 , V_41 , V_94 , V_239 ) ;
}
}
static int F_186 ( struct V_1 * V_2 ,
unsigned int V_386 ,
int V_413 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
T_1 V_414 = V_11 -> V_380 [ 0 ] ;
int type , V_36 , V_385 , V_87 = 0 ;
V_385 = V_11 -> V_242 . V_307 ;
for ( type = V_181 ; type >= V_58 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_152 -> V_176 ; V_36 ++ ) {
T_1 V_3 = V_152 -> V_40 [ V_36 ] . V_41 ;
T_1 V_239 = 0 ;
unsigned int V_177 , V_368 ;
if ( V_152 -> V_40 [ V_36 ] . type != type )
continue;
V_177 = F_68 ( V_2 , V_3 ) ;
if ( F_209 ( V_177 ) != V_415 )
continue;
if ( V_386 && F_185 ( V_177 ) != V_386 )
continue;
V_368 = F_23 ( V_2 , V_3 ) ;
if ( ! ( V_368 & V_416 ) )
continue;
if ( V_413 && V_413 + V_87 < V_385 ) {
V_239 = V_11 -> V_380 [ V_413 + V_87 ] ;
if ( ! F_181 ( V_2 , V_3 , V_239 ) )
V_239 = 0 ;
}
if ( ! V_239 )
V_239 = F_180 ( V_2 , V_3 ) ;
if ( ! V_239 )
continue;
V_11 -> V_401 [ V_87 ] . V_41 = V_3 ;
V_11 -> V_401 [ V_87 ] . V_239 = V_239 ;
V_87 ++ ;
V_11 -> V_380 [ V_11 -> V_242 . V_307 ++ ] = V_239 ;
}
}
V_11 -> V_242 . V_307 = V_385 ;
if ( V_87 < 2 ) {
memset ( V_11 -> V_380 + V_385 , 0 ,
sizeof( T_1 ) * ( V_417 - V_385 ) ) ;
V_11 -> V_380 [ 0 ] = V_414 ;
return 0 ;
}
return V_87 ;
}
static int F_210 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_140 ;
V_9 -> V_141 = 1 ;
V_9 -> V_20 . V_21 . V_49 = V_11 -> V_356 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_356 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_356 ;
sprintf ( V_9 -> V_20 . V_21 . V_144 , L_56 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_211 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_389 - 1 ) / 2 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , int V_31 , bool V_418 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_401 [ V_31 ] . V_41 ;
if ( ! V_11 -> V_401 [ V_31 ] . V_419 )
V_11 -> V_401 [ V_31 ] . V_419 =
F_22 ( V_2 , V_3 , 0 ,
V_61 , 0 ) ;
if ( V_418 ) {
F_179 ( V_2 , V_3 , 0 ,
V_42 ,
V_94 ) ;
if ( F_2 ( V_2 , V_3 ) & V_245 )
F_18 ( V_2 , V_3 , V_99 , 0 ,
V_52 , 0 ) ;
F_178 ( V_2 , V_3 , V_11 -> V_401 [ V_31 ] . V_239 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_245 )
F_18 ( V_2 , V_3 , V_99 , 0 ,
V_52 , V_52 ) ;
F_179 ( V_2 , V_3 , 0 ,
V_42 ,
V_11 -> V_401 [ V_31 ] . V_419 ) ;
}
return 0 ;
}
static int F_213 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_354 ;
V_354 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_354 < 0 || V_354 > V_11 -> V_356 )
return - V_145 ;
if ( V_354 == ( V_11 -> V_389 - 1 ) / 2 )
return 0 ;
V_11 -> V_389 = ( V_354 + 1 ) * 2 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_356 ; V_36 ++ )
F_212 ( V_2 , V_36 , V_36 < V_354 ) ;
V_11 -> V_242 . V_420 = V_11 -> V_389 ;
if ( V_11 -> V_421 && ! V_11 -> V_422 )
V_11 -> V_242 . V_307 = V_11 -> V_242 . V_420 / 2 ;
return 1 ;
}
static int F_214 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_356 > 0 ) {
struct V_71 * V_147 ;
V_147 = F_53 ( V_11 ) ;
if ( ! V_147 )
return - V_148 ;
* V_147 = V_423 ;
V_147 -> V_144 = F_57 ( L_57 , V_150 ) ;
if ( ! V_147 -> V_144 )
return - V_148 ;
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
T_1 V_26 [ F_26 ( V_11 -> V_364 ) ] ;
T_1 V_32 [ F_26 ( V_11 -> V_364 ) ] ;
int V_36 , V_164 , V_162 ;
V_35 = V_11 -> V_15 ;
if ( ! V_35 )
return;
if ( V_11 -> V_46 )
return;
V_162 = 0 ;
for ( V_164 = 0 ; V_164 < V_11 -> V_166 ; V_164 ++ ) {
T_1 V_165 = V_11 -> V_167 [ V_164 ] ;
int V_37 = F_16 ( V_2 , V_165 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
T_1 V_41 = V_11 -> V_113 [ V_36 ] ;
if ( V_41 ) {
if ( F_64 ( V_2 , V_165 , V_41 ) < 0 )
break;
} else if ( V_37 <= V_35 -> V_49 [ V_36 ] . V_50 )
break;
}
if ( V_36 >= V_35 -> V_16 ) {
V_26 [ V_162 ] = V_11 -> V_364 [ V_164 ] ;
V_32 [ V_162 ++ ] = V_165 ;
}
}
if ( ! V_162 ) {
if ( ! F_63 ( V_2 ) ) {
F_72 ( V_424 L_58
L_59 ,
V_2 -> V_194 , V_11 -> V_364 [ 0 ] ) ;
V_11 -> V_166 = 1 ;
V_11 -> V_114 = 0 ;
return;
}
} else if ( V_162 != V_11 -> V_166 ) {
memcpy ( V_11 -> V_364 , V_26 ,
V_162 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_167 , V_32 ,
V_162 * sizeof( T_1 ) ) ;
V_11 -> V_166 = V_162 ;
}
if ( V_11 -> V_114 )
F_66 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 )
V_11 -> V_166 = 1 ;
}
static void F_216 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_171 ( V_2 , V_3 , V_53 ) ) {
F_14 ( V_2 , V_3 , 0 ,
V_246 ,
F_174 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_171 ( V_2 , V_3 , V_99 ) )
F_14 ( V_2 , V_3 , 0 ,
V_246 ,
V_376 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_172 , V_162 ;
for ( V_172 = 0 ; V_172 < V_11 -> V_166 ; V_172 ++ )
F_216 ( V_2 , V_172 ) ;
if ( V_11 -> V_46 )
V_162 = 1 ;
else
V_162 = V_11 -> V_166 ;
for ( V_172 = 0 ; V_172 < V_162 ; V_172 ++ )
F_13 ( V_2 , V_172 , V_11 -> V_23 [ V_172 ] , true ) ;
}
static int F_218 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
int V_36 , V_249 ;
int V_373 = 0 ;
T_1 V_3 ;
const char * V_374 = NULL ;
for ( V_36 = 0 ; V_36 < V_152 -> V_176 ; V_36 ++ ) {
if ( V_152 -> V_40 [ V_36 ] . type > V_58 )
break;
V_3 = V_152 -> V_40 [ V_36 ] . V_41 ;
if ( F_2 ( V_2 , V_3 ) & V_425 ) {
const char * V_171 ;
char V_426 [ 32 ] ;
V_171 = F_167 ( V_2 , V_152 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_171 , L_47 ) )
V_171 = L_48 ;
if ( V_374 && ! strcmp ( V_171 , V_374 ) )
V_373 ++ ;
else
V_373 = 0 ;
V_374 = V_171 ;
snprintf ( V_426 , sizeof( V_426 ) ,
L_60 , V_171 ) ;
V_249 = F_157 ( V_11 , V_361 ,
V_426 , V_373 ,
F_91 ( V_3 , 3 , 0 , V_53 ) ) ;
if ( V_249 < 0 )
return V_249 ;
}
}
return 0 ;
}
static void F_219 ( struct V_1 * V_2 , T_1 V_165 ,
int V_31 )
{
if ( F_17 ( F_2 ( V_2 , V_165 ) ) == V_47 ) {
F_18 ( V_2 , V_165 , V_53 , V_31 ,
V_52 , 0 ) ;
} else if ( F_16 ( V_2 , V_165 , NULL ) > 1 ) {
F_19 ( V_2 , V_165 , 0 ,
V_54 , V_31 ) ;
}
}
static int F_220 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( ! V_41 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_166 ; V_36 ++ ) {
T_1 V_165 = F_12 ( V_11 , V_36 ) ;
int V_31 ;
V_31 = F_64 ( V_2 , V_165 , V_41 ) ;
if ( V_31 < 0 )
continue;
F_219 ( V_2 , V_165 , V_31 ) ;
return V_36 ;
}
return - 1 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_39 . V_176 ; V_36 ++ )
F_220 ( V_2 , V_11 -> V_39 . V_40 [ V_36 ] . V_41 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_71 * V_368 [ 2 ] [ 3 ] = {
{ V_427 ,
V_428 ,
V_429 } ,
{ V_430 ,
V_431 ,
V_432 } ,
} ;
if ( ! F_197 ( V_2 , V_11 -> V_26 [ 0 ] , V_53 ) ) {
if ( ! V_11 -> V_32 )
return;
if ( ! F_197 ( V_2 , V_11 -> V_32 [ 0 ] , V_99 ) )
return;
V_11 -> V_261 = 1 ;
}
if ( V_11 -> V_166 > 0 ) {
int V_433 = 0 ;
int V_372 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_433 = 1 ;
if ( V_11 -> V_114 ) {
V_372 = 1 ;
V_433 = 0 ;
} else if ( V_11 -> V_46 )
V_372 = 1 ;
if ( ! V_372 ) {
if ( V_11 -> V_166 > 3 )
V_11 -> V_166 = 3 ;
else if ( ! V_11 -> V_166 )
return;
V_372 = V_11 -> V_166 ;
}
V_11 -> V_274 = V_368 [ V_433 ] [ V_372 - 1 ] ;
}
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_207 ( V_2 ) ;
F_208 ( V_2 ) ;
F_173 ( V_2 ) ;
F_217 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_11 -> V_160 )
F_41 ( V_2 ) ;
}
static inline int F_223 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_230 * V_233 ;
V_233 = F_82 ( V_2 -> V_190 -> V_191 , V_434 ) ;
if ( V_233 )
return V_233 -> V_20 ;
return V_11 -> V_183 . V_184 ;
}
static int F_224 ( struct V_1 * V_2 ,
const T_1 * V_435 ,
const T_1 * V_436 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_151 * V_152 = & V_11 -> V_39 ;
int V_249 ;
V_249 = F_225 ( V_2 , V_152 , V_435 ,
V_11 -> V_437 ) ;
if ( V_249 < 0 )
return V_249 ;
if ( ! V_152 -> V_156 ) {
if ( V_152 -> V_240 || V_152 -> V_248 ) {
V_11 -> V_242 . V_420 = 2 ;
V_11 -> V_275 = 1 ;
goto V_438;
}
return 0 ;
}
if ( V_152 -> V_153 == V_154 &&
V_152 -> V_156 <= V_152 -> V_158 ) {
V_152 -> V_155 = V_152 -> V_156 ;
memcpy ( V_152 -> V_107 , V_152 -> V_108 ,
sizeof( V_152 -> V_107 ) ) ;
V_152 -> V_156 = V_152 -> V_158 ;
memcpy ( V_152 -> V_108 , V_152 -> V_103 , sizeof( V_152 -> V_103 ) ) ;
V_152 -> V_158 = 0 ;
memset ( V_152 -> V_103 , 0 , sizeof( V_152 -> V_103 ) ) ;
V_152 -> V_153 = V_157 ;
}
V_249 = F_184 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_214 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_198 ( V_2 , V_152 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_203 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_204 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_169 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 = F_166 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
V_11 -> V_242 . V_420 = V_11 -> V_242 . V_307 * 2 ;
V_438:
F_87 ( V_2 ) ;
if ( ! V_11 -> V_275 )
F_215 ( V_2 ) ;
if ( V_436 )
F_76 ( V_2 , V_436 ) ;
if ( ! V_11 -> V_275 ) {
F_70 ( V_2 ) ;
V_249 = F_218 ( V_2 ) ;
if ( V_249 < 0 )
return V_249 ;
}
if ( V_11 -> V_146 . V_161 )
F_24 ( V_11 , V_11 -> V_146 . V_161 ) ;
return 1 ;
}
static int F_226 ( struct V_1 * V_2 )
{
static const T_1 V_439 [] = { 0x1d , 0 } ;
static const T_1 V_440 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_224 ( V_2 , V_439 , V_440 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_441 ;
int V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
V_11 -> V_421 = 1 ;
V_441 = F_228 ( V_2 , V_442 ,
V_443 , V_444 ) ;
if ( V_441 < 0 ) {
F_72 ( V_193 L_61 ,
V_2 -> V_194 ) ;
V_441 = V_445 ;
}
if ( V_441 == V_445 ) {
F_81 ( V_2 , NULL , V_446 , V_447 ) ;
F_77 ( V_2 , V_217 ) ;
}
if ( V_441 == V_445 ) {
V_249 = F_226 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
#ifdef F_229
else if ( ! V_249 ) {
F_72 ( V_193
L_62
L_63 ) ;
V_441 = V_448 ;
}
#endif
}
if ( V_441 != V_445 ) {
V_11 -> V_280 = 0x0c ;
F_230 ( V_2 , & V_449 [ V_441 ] ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
if ( V_441 == V_445 )
V_11 -> V_289 = F_222 ;
else
V_2 -> V_343 . V_451 = F_101 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_453 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_234 ( struct V_1 * V_2 )
{
static const T_1 V_454 [] = { 0x17 , 0 } ;
static const T_1 V_455 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_224 ( V_2 , V_454 , V_455 ) ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 , V_441 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x07 ;
V_441 = F_228 ( V_2 , V_456 ,
V_457 , V_458 ) ;
if ( V_441 < 0 ) {
F_73 ( V_193 L_61 ,
V_2 -> V_194 ) ;
V_441 = V_445 ;
}
if ( V_441 == V_445 ) {
F_81 ( V_2 , NULL , V_459 , V_460 ) ;
F_77 ( V_2 , V_217 ) ;
}
if ( V_441 == V_445 ) {
V_249 = F_234 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
#ifdef F_229
else if ( ! V_249 ) {
F_72 ( V_193
L_62
L_64 ) ;
V_441 = V_461 ;
}
#endif
}
if ( V_441 != V_445 ) {
F_230 ( V_2 , & V_462 [ V_441 ] ) ;
V_11 -> V_280 = 0x08 ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x07 , 0x05 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
if ( V_441 == V_445 )
V_11 -> V_289 = F_222 ;
else
V_2 -> V_343 . V_451 = F_101 ;
V_11 -> V_336 = F_46 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_463 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static void F_236 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
if ( V_119 != V_290 )
return;
F_43 ( V_2 ) ;
}
static void F_237 ( struct V_1 * V_2 , int V_41 , int V_464 )
{
unsigned int V_465 , V_466 , V_467 ;
V_465 = F_22 ( V_2 , V_2 -> V_468 , 0 ,
V_469 , 0 ) ;
if ( ! V_464 )
V_465 |= ( 1 << V_41 ) ;
else
V_465 &= ~ ( 1 << V_41 ) ;
V_466 = F_22 ( V_2 , V_2 -> V_468 , 0 ,
V_470 , 0 ) ;
V_466 |= ( 1 << V_41 ) ;
V_467 = F_22 ( V_2 , V_2 -> V_468 , 0 ,
V_471 , 0 ) ;
V_467 |= ( 1 << V_41 ) ;
F_14 ( V_2 , V_2 -> V_468 , 0 ,
V_472 , V_466 ) ;
F_14 ( V_2 , V_2 -> V_468 , 0 ,
V_473 , V_467 ) ;
F_47 ( 1 ) ;
F_14 ( V_2 , V_2 -> V_468 , 0 ,
V_474 , V_465 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
if ( V_119 != V_290 )
return;
F_237 ( V_2 , 0 , 0 ) ;
F_237 ( V_2 , 1 , 0 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
if ( V_119 == V_217 ) {
T_1 V_475 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_476 [ 2 ] = { 0x0e , 0x0f } ;
F_240 ( V_2 , 0x14 , 2 , V_475 ) ;
F_240 ( V_2 , 0x15 , 2 , V_475 ) ;
F_240 ( V_2 , 0x18 , 2 , V_476 ) ;
F_240 ( V_2 , 0x1a , 2 , V_476 ) ;
} else if ( V_119 == V_221 ) {
T_1 V_251 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_240 ( V_2 , 0x14 , 5 , V_251 ) ;
F_240 ( V_2 , 0x15 , 5 , V_251 ) ;
F_240 ( V_2 , 0x18 , 5 , V_251 ) ;
F_240 ( V_2 , 0x1a , 5 , V_251 ) ;
}
}
static int F_241 ( struct V_1 * V_2 )
{
static const T_1 V_477 [] = { 0x1d , 0 } ;
static const T_1 V_478 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_224 ( V_2 , V_477 , V_478 ) ;
}
static int F_242 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 , V_441 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
switch ( V_2 -> V_124 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
V_249 = F_156 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
V_441 = F_228 ( V_2 , V_479 ,
V_480 , NULL ) ;
if ( V_441 < 0 )
V_441 = F_243 ( V_2 ,
V_479 , V_480 , V_481 ) ;
if ( V_441 < 0 ) {
F_72 ( V_193 L_61 ,
V_2 -> V_194 ) ;
V_441 = V_445 ;
}
if ( V_441 == V_445 ) {
F_81 ( V_2 , NULL , V_482 , V_483 ) ;
F_77 ( V_2 , V_217 ) ;
}
F_71 ( V_2 ) ;
if ( V_441 == V_445 ) {
V_249 = F_241 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
}
if ( V_441 != V_445 ) {
F_230 ( V_2 , & V_484 [ V_441 ] ) ;
V_11 -> V_280 = 0x0c ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 && F_223 ( V_2 ) ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
if ( V_441 == V_445 )
V_11 -> V_289 = F_222 ;
else
V_2 -> V_343 . V_451 = F_101 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_485 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_244 ( struct V_1 * V_2 )
{
static const T_1 V_486 [] = { 0x1d , 0 } ;
static const T_1 V_487 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_224 ( V_2 , V_486 , V_487 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
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
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_81 ( V_2 , NULL , V_488 , V_489 ) ;
F_77 ( V_2 , V_217 ) ;
V_249 = F_244 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 && F_223 ( V_2 ) ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
V_11 -> V_336 = F_46 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_490 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_246 ( struct V_1 * V_2 )
{
static const T_1 V_491 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_249 = F_224 ( V_2 , NULL , V_491 ) ;
if ( V_249 > 0 ) {
if ( ! V_11 -> V_275 && V_11 -> V_39 . V_107 [ 0 ] != 0x1d ) {
F_24 ( V_11 , V_492 ) ;
F_27 ( V_11 , V_493 ) ;
}
}
return V_249 ;
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_36 , V_494 , V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_249 = F_246 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
V_494 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_73 ; V_36 ++ ) {
if ( V_11 -> V_74 [ V_36 ] == V_492 ) {
V_494 = 1 ;
break;
}
}
if ( V_494 ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_53 ) )
F_248 ( V_2 , 0x1d , V_53 ,
( 0x0c << V_495 ) |
( 0x0c << V_496 ) |
( 0x07 << V_497 ) |
( 0 << V_498 ) ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
V_11 -> V_336 = F_46 ;
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_249 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_189 ) {
case 0x103c1586 :
return 1 ;
}
return 0 ;
}
static int F_250 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == 0x01 || V_3 == 0x14 ) {
int V_499 ;
if ( F_251 ( V_2 , 0x14 , 0 , V_99 , 0 ) &
V_52 )
V_499 = 0x24 ;
else
V_499 = 0x20 ;
F_179 ( V_2 , 0x19 , 0 ,
V_42 ,
V_499 ) ;
}
return F_121 ( V_2 , V_3 ) ;
}
static int F_252 ( struct V_1 * V_2 )
{
static const T_1 V_500 [] = { 0x1d , 0 } ;
static const T_1 V_501 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_502 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_503 = V_11 -> V_504 == V_505 ?
V_502 : V_501 ;
return F_224 ( V_2 , V_500 , V_503 ) ;
}
static void F_253 ( struct V_1 * V_2 , int V_506 )
{
int V_56 = F_83 ( V_2 , 0x04 ) ;
if ( V_506 )
V_56 |= 1 << 11 ;
else
V_56 &= ~ ( 1 << 11 ) ;
F_84 ( V_2 , 0x04 , V_56 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 )
F_253 ( V_2 , 0 ) ;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_253 ( V_2 , 0 ) ;
F_47 ( 150 ) ;
}
}
static int F_255 ( struct V_1 * V_2 )
{
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_253 ( V_2 , 0 ) ;
F_47 ( 150 ) ;
}
V_2 -> V_343 . V_344 ( V_2 ) ;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_253 ( V_2 , 1 ) ;
F_47 ( 200 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 )
F_253 ( V_2 , 1 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
F_119 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
int V_507 ;
if ( V_119 != V_290 )
return;
V_507 = F_83 ( V_2 , 0x1e ) ;
F_84 ( V_2 , 0x1e , V_507 | 0x80 ) ;
}
static void F_257 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
static const struct V_75 V_222 [] = {
{ 0x20 , V_80 , 0x0d } ,
{ 0x20 , V_83 , 0x4000 } ,
{}
} ;
unsigned int V_152 ;
if ( strcmp ( V_2 -> V_194 , L_65 ) )
return;
V_152 = F_68 ( V_2 , 0x12 ) ;
if ( F_209 ( V_152 ) == V_508 )
F_49 ( V_2 , V_222 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_119 != V_221 )
return;
V_11 -> V_308 = & V_509 ;
V_11 -> V_313 = & V_510 ;
}
static void F_259 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
int V_507 ;
if ( V_119 != V_290 )
return;
V_507 = F_83 ( V_2 , 0x07 ) ;
F_84 ( V_2 , 0x07 , V_507 | 0x80 ) ;
}
static void F_260 ( struct V_1 * V_2 )
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
static void F_261 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_119 != V_221 )
return;
V_11 -> V_110 = F_260 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_56 ;
if ( V_11 -> V_504 != V_511 )
return 0 ;
if ( ( F_85 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_56 = F_83 ( V_2 , 0x04 ) ;
F_84 ( V_2 , 0x04 , V_56 | ( 1 << 11 ) ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_56 = F_83 ( V_2 , 0xd ) ;
if ( ( V_56 & 0x0c00 ) >> 10 != 0x1 ) {
F_84 ( V_2 , 0xd , V_56 | ( 1 << 10 ) ) ;
}
V_56 = F_83 ( V_2 , 0x17 ) ;
if ( ( V_56 & 0x01c0 ) >> 6 != 0x4 ) {
F_84 ( V_2 , 0x17 , V_56 | ( 1 << 7 ) ) ;
}
}
V_56 = F_83 ( V_2 , 0xd ) ;
F_84 ( V_2 , 0xd , V_56 | ( 1 << 14 ) ) ;
V_56 = F_83 ( V_2 , 0x4 ) ;
F_84 ( V_2 , 0x4 , V_56 | ( 1 << 11 ) ) ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 = 0 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
F_71 ( V_2 ) ;
V_249 = F_156 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( V_2 -> V_124 == 0x10ec0269 ) {
V_11 -> V_504 = V_505 ;
switch ( F_85 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_190 -> V_191 -> V_512 == 0x1025 &&
V_11 -> V_183 . V_199 == 1 )
V_249 = F_155 ( V_2 , L_65 ) ;
V_11 -> V_504 = V_511 ;
break;
case 0x0020 :
if ( V_2 -> V_190 -> V_191 -> V_512 == 0x17aa &&
V_2 -> V_190 -> V_191 -> V_192 == 0x21f3 )
V_249 = F_155 ( V_2 , L_66 ) ;
V_11 -> V_504 = V_513 ;
break;
default:
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_249 < 0 )
goto error;
F_117 ( V_2 ) ;
}
F_81 ( V_2 , V_514 ,
V_515 , V_516 ) ;
F_77 ( V_2 , V_217 ) ;
V_249 = F_252 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 && F_223 ( V_2 ) ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x0b , 0x04 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
#ifdef F_263
V_2 -> V_343 . V_517 = F_255 ;
#endif
V_11 -> V_289 = F_222 ;
V_11 -> V_336 = F_254 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_518 ;
if ( F_249 ( V_2 ) )
V_2 -> V_343 . V_519 = F_250 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_264 ( struct V_1 * V_2 )
{
static const T_1 V_520 [] = { 0x1d , 0 } ;
static const T_1 V_521 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_224 ( V_2 , V_520 , V_521 ) ;
}
static void F_265 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_56 ;
if ( V_119 != V_290 )
return;
V_56 = F_22 ( V_2 , 0x0f , 0 ,
V_61 , 0 ) ;
if ( ! ( V_56 & ( V_522 | V_523 ) ) )
V_56 |= V_522 ;
V_56 |= V_524 ;
F_14 ( V_2 , 0x0f , 0 ,
V_42 , V_56 ) ;
V_11 -> V_97 = 1 ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x15 ;
F_81 ( V_2 , NULL , V_525 , V_526 ) ;
F_77 ( V_2 , V_217 ) ;
V_249 = F_264 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 ) {
V_249 = F_231 ( V_2 , 0x23 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x23 , 0 , V_99 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
#ifdef F_233
V_11 -> V_342 = F_150 ;
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_527 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_267 ( struct V_1 * V_2 )
{
static const T_1 V_528 [] = { 0x1d , 0 } ;
static const T_1 V_529 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_224 ( V_2 , V_528 , V_529 ) ;
}
static void F_268 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
if ( V_119 == V_217 ) {
F_269 ( V_2 , 0x18 , 0x00001714 ) ;
F_269 ( V_2 , 0x19 , 0x0000171c ) ;
}
}
static int F_270 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
F_81 ( V_2 , NULL , V_530 , V_531 ) ;
F_77 ( V_2 , V_217 ) ;
V_249 = F_267 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( V_2 -> V_124 == 0x10ec0660 ) {
F_27 ( V_11 , V_532 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 ) {
V_249 = F_231 ( V_2 , 0x23 ) ;
if ( V_249 < 0 )
goto error;
F_232 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
V_11 -> V_336 = F_46 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_533 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_271 ( struct V_1 * V_2 )
{
static const T_1 V_534 [] = { 0x1d , 0 } ;
static const T_1 V_535 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_536 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_503 ;
if ( V_2 -> V_124 == 0x10ec0272 || V_2 -> V_124 == 0x10ec0663 ||
V_2 -> V_124 == 0x10ec0665 || V_2 -> V_124 == 0x10ec0670 )
V_503 = V_535 ;
else
V_503 = V_536 ;
return F_224 ( V_2 , V_534 , V_503 ) ;
}
static void F_272 ( struct V_1 * V_2 ,
const struct V_213 * V_214 , int V_119 )
{
if ( V_119 != V_221 )
return;
if ( F_248 ( V_2 , 0x2 , V_99 ,
( 0x3b << V_495 ) |
( 0x3b << V_496 ) |
( 0x03 << V_497 ) |
( 0 << V_498 ) ) )
F_72 ( V_424
L_67 ) ;
}
static int F_273 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 = 0 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( ! V_11 )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_371 = 0x0b ;
V_11 -> V_437 = V_537 ;
F_71 ( V_2 ) ;
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_249 = F_156 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( ( F_85 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_190 -> V_191 -> V_512 == 0x1025 &&
V_11 -> V_183 . V_199 == 1 ) {
if ( F_155 ( V_2 , L_68 ) < 0 )
goto error;
}
F_81 ( V_2 , V_538 ,
V_539 , V_540 ) ;
F_77 ( V_2 , V_217 ) ;
V_249 = F_271 ( V_2 ) ;
if ( V_249 < 0 )
goto error;
if ( ! V_11 -> V_275 && ! V_11 -> V_26 ) {
F_165 ( V_2 ) ;
F_65 ( V_2 ) ;
F_215 ( V_2 ) ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
if ( ! V_11 -> V_275 && F_223 ( V_2 ) ) {
V_249 = F_231 ( V_2 , 0x1 ) ;
if ( V_249 < 0 )
goto error;
switch ( V_2 -> V_124 ) {
case 0x10ec0662 :
F_232 ( V_11 , 0x0b , 0x05 , V_53 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_232 ( V_11 , 0x0b , 0x04 , V_53 ) ;
break;
case 0x10ec0273 :
F_232 ( V_11 , 0x0b , 0x03 , V_53 ) ;
break;
}
}
F_77 ( V_2 , V_221 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
V_11 -> V_336 = F_46 ;
#ifdef F_233
if ( ! V_11 -> V_291 . V_452 )
V_11 -> V_291 . V_452 = V_541 ;
#endif
return 0 ;
error:
F_148 ( V_2 ) ;
return V_249 ;
}
static int F_274 ( struct V_1 * V_2 )
{
return F_224 ( V_2 , NULL , NULL ) ;
}
static int F_275 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_249 ;
V_11 = F_201 ( sizeof( * V_11 ) , V_150 ) ;
if ( V_11 == NULL )
return - V_148 ;
V_2 -> V_11 = V_11 ;
V_249 = F_274 ( V_2 ) ;
if ( V_249 < 0 ) {
F_148 ( V_2 ) ;
return V_249 ;
}
if ( ! V_11 -> V_275 && ! V_11 -> V_274 )
F_221 ( V_2 ) ;
V_2 -> V_343 = V_450 ;
V_11 -> V_289 = F_222 ;
return 0 ;
}
static int T_5 F_276 ( void )
{
return F_277 ( & V_542 ) ;
}
static void T_6 F_278 ( void )
{
F_279 ( & V_542 ) ;
}
