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
static int F_12 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_31 , bool V_32 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_33 * V_34 ;
unsigned int V_12 ;
int V_35 , type ;
T_1 V_3 ;
V_12 = V_19 >= V_11 -> V_14 ? 0 : V_19 ;
V_34 = & V_11 -> V_15 [ V_12 ] ;
if ( ! V_34 -> V_16 && V_12 > 0 )
V_34 = & V_11 -> V_15 [ 0 ] ;
if ( V_31 >= V_34 -> V_16 )
V_31 = V_34 -> V_16 - 1 ;
if ( V_11 -> V_23 [ V_19 ] == V_31 && ! V_32 )
return 0 ;
V_11 -> V_23 [ V_19 ] = V_31 ;
if ( V_11 -> V_36 ) {
F_9 ( V_2 , V_31 ) ;
V_19 = V_11 -> V_27 [ V_31 ] ;
}
V_3 = V_11 -> V_37 ?
V_11 -> V_37 [ V_19 ] : V_11 -> V_26 [ V_19 ] ;
if ( F_13 ( V_2 , V_3 , NULL ) <= 1 )
return 1 ;
type = F_14 ( F_2 ( V_2 , V_3 ) ) ;
if ( type == V_38 ) {
for ( V_35 = 0 ; V_35 < V_34 -> V_16 ; V_35 ++ ) {
unsigned int V_39 = ( V_35 == V_31 ) ? 0 : V_40 ;
F_15 ( V_2 , V_3 , V_41 ,
V_34 -> V_42 [ V_35 ] . V_43 ,
V_40 , V_39 ) ;
}
} else {
F_16 ( V_2 , V_3 , 0 ,
V_44 ,
V_34 -> V_42 [ V_31 ] . V_43 ) ;
}
return 1 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
return F_12 ( V_2 , V_19 ,
V_18 -> V_20 . V_21 . V_22 [ 0 ] , false ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_3 ,
int V_45 )
{
unsigned int V_46 = V_47 ;
if ( V_45 == V_48 ) {
unsigned int V_49 ;
unsigned int V_50 ;
V_50 = F_19 ( V_2 , V_3 , 0 ,
V_51 , 0 ) ;
V_49 = F_20 ( V_2 , V_3 ) ;
V_49 = ( V_49 & V_52 ) >> V_53 ;
if ( ( V_49 & V_54 ) && V_50 != V_55 )
V_46 = V_56 ;
else if ( V_49 & V_57 )
V_46 = V_55 ;
else if ( V_49 & V_58 )
V_46 = V_59 ;
else if ( V_49 & V_60 )
V_46 = V_61 ;
}
F_21 ( V_2 , V_3 , 0 , V_62 , V_46 ) ;
}
static void F_22 ( struct V_10 * V_11 , const struct V_63 * V_64 )
{
if ( F_23 ( V_11 -> V_65 >= F_24 ( V_11 -> V_66 ) ) )
return;
V_11 -> V_66 [ V_11 -> V_65 ++ ] = V_64 ;
}
static void F_25 ( struct V_10 * V_11 , const struct V_67 * V_68 )
{
if ( F_23 ( V_11 -> V_69 >= F_24 ( V_11 -> V_70 ) ) )
return;
V_11 -> V_70 [ V_11 -> V_69 ++ ] = V_68 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_46 ;
if ( ! V_11 -> V_71 )
return;
F_21 ( V_2 , V_11 -> V_71 , 0 , V_72 ,
V_11 -> V_73 ) ;
V_46 = F_19 ( V_2 , V_11 -> V_71 , 0 ,
V_74 , 0 ) ;
F_21 ( V_2 , V_11 -> V_71 , 0 , V_72 ,
V_11 -> V_73 ) ;
F_21 ( V_2 , V_11 -> V_71 , 0 , V_75 ,
V_46 & ~ ( 1 << V_11 -> V_76 ) ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_71 = V_3 ;
V_11 -> V_73 = V_77 ;
V_11 -> V_76 = V_78 ;
F_26 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
#ifdef F_29
struct V_10 * V_11 = V_2 -> V_11 ;
int V_79 ;
unsigned int V_80 = V_11 -> V_81 . V_82 [ 0 ] ;
unsigned int V_83 = V_11 -> V_84 ;
unsigned int V_85 = V_11 -> V_86 ;
if ( V_80 ) {
V_79 = F_30 ( V_2 , V_80 ,
V_87 , NULL ) ;
if ( V_79 < 0 )
return V_79 ;
F_31 ( V_2 , V_80 ) ;
}
if ( V_83 ) {
V_79 = F_30 ( V_2 , V_83 ,
V_88 , NULL ) ;
if ( V_79 < 0 )
return V_79 ;
F_31 ( V_2 , V_83 ) ;
}
if ( V_85 ) {
V_79 = F_30 ( V_2 , V_85 ,
V_88 , NULL ) ;
if ( V_79 < 0 )
return V_79 ;
F_31 ( V_2 , V_85 ) ;
}
#endif
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 , int V_89 , T_1 * V_90 )
{
int V_35 , V_91 = 0 ;
for ( V_35 = 0 ; V_35 < V_89 ; V_35 ++ ) {
T_1 V_3 = V_90 [ V_35 ] ;
if ( ! V_3 )
break;
F_31 ( V_2 , V_3 ) ;
V_91 |= F_33 ( V_2 , V_3 ) ;
}
return V_91 ;
}
static void F_34 ( struct V_1 * V_2 , int V_89 , T_1 * V_90 ,
bool V_92 , bool V_93 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_94 = V_92 ? V_40 : 0 ;
unsigned int V_95 = V_92 ? 0 : ( V_93 ? V_96 : V_97 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_89 ; V_35 ++ ) {
T_1 V_3 = V_90 [ V_35 ] ;
if ( ! V_3 )
break;
switch ( V_11 -> V_98 ) {
case V_99 :
F_21 ( V_2 , V_3 , 0 ,
V_62 ,
V_95 ) ;
break;
case V_100 :
F_15 ( V_2 , V_3 , V_101 , 0 ,
V_40 , V_94 ) ;
break;
case V_102 :
V_3 = V_11 -> V_103 [ V_35 ] ;
if ( ! V_3 )
break;
F_15 ( V_2 , V_3 , V_41 , 0 ,
V_40 , V_94 ) ;
F_15 ( V_2 , V_3 , V_41 , 1 ,
V_40 , V_94 ) ;
break;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_104 ;
F_34 ( V_2 , F_24 ( V_11 -> V_81 . V_82 ) ,
V_11 -> V_81 . V_82 , V_11 -> V_105 , true ) ;
if ( ! V_11 -> V_106 )
V_104 = 0 ;
else
V_104 = V_11 -> V_107 | V_11 -> V_108 ;
V_104 |= V_11 -> V_105 ;
F_34 ( V_2 , F_24 ( V_11 -> V_81 . V_109 ) ,
V_11 -> V_81 . V_109 , V_104 , false ) ;
if ( V_11 -> V_81 . V_110 [ 0 ] == V_11 -> V_81 . V_82 [ 0 ] ||
V_11 -> V_81 . V_110 [ 0 ] == V_11 -> V_81 . V_109 [ 0 ] )
return;
if ( ! V_11 -> V_106 || ( V_11 -> V_111 && ! V_11 -> V_112 ) )
V_104 = 0 ;
else
V_104 = V_11 -> V_107 ;
V_104 |= V_11 -> V_105 ;
F_34 ( V_2 , F_24 ( V_11 -> V_81 . V_110 ) ,
V_11 -> V_81 . V_110 , V_104 , false ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_107 =
F_32 ( V_2 , F_24 ( V_11 -> V_81 . V_82 ) ,
V_11 -> V_81 . V_82 ) ;
if ( ! V_11 -> V_106 )
return;
F_35 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_81 . V_110 [ 0 ] == V_11 -> V_81 . V_82 [ 0 ] )
return;
V_11 -> V_108 =
F_32 ( V_2 , F_24 ( V_11 -> V_81 . V_110 ) ,
V_11 -> V_81 . V_110 ) ;
if ( ! V_11 -> V_106 || ! V_11 -> V_113 )
return;
F_35 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_90 = V_11 -> V_114 ;
if ( ! V_11 -> V_115 || ! V_11 -> V_116 )
return;
if ( F_23 ( ! V_11 -> V_26 ) )
return;
if ( F_23 ( V_11 -> V_117 < 0 || V_11 -> V_118 < 0 ) )
return;
if ( F_33 ( V_2 , V_90 [ V_11 -> V_118 ] ) )
F_12 ( V_2 , 0 , V_11 -> V_118 , false ) ;
else if ( V_11 -> V_119 >= 0 &&
F_33 ( V_2 , V_90 [ V_11 -> V_119 ] ) )
F_12 ( V_2 , 0 , V_11 -> V_119 , false ) ;
else
F_12 ( V_2 , 0 , V_11 -> V_117 , false ) ;
F_31 ( V_2 , V_90 [ V_11 -> V_118 ] ) ;
if ( V_11 -> V_119 >= 0 )
F_31 ( V_2 , V_90 [ V_11 -> V_119 ] ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned int V_120 )
{
if ( V_2 -> V_121 == 0x10ec0880 )
V_120 >>= 28 ;
else
V_120 >>= 26 ;
switch ( V_120 ) {
case V_122 :
F_36 ( V_2 ) ;
break;
case V_123 :
F_37 ( V_2 ) ;
break;
case V_124 :
F_38 ( V_2 ) ;
break;
}
}
static void F_40 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_21 ( V_2 , 0x20 , 0 , V_72 , 0 ) ;
V_125 = F_19 ( V_2 , 0x20 , 0 , V_74 , 0 ) ;
F_21 ( V_2 , 0x20 , 0 , V_72 , 7 ) ;
if ( ( V_125 & 0xf0 ) == 0x20 )
F_19 ( V_2 , 0x20 , 0 ,
V_75 , 0x830 ) ;
else
F_19 ( V_2 , 0x20 , 0 ,
V_75 , 0x3030 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_21 ( V_2 , 0x20 , 0 , V_72 , 7 ) ;
V_125 = F_19 ( V_2 , 0x20 , 0 , V_74 , 0 ) ;
F_21 ( V_2 , 0x20 , 0 , V_72 , 7 ) ;
F_21 ( V_2 , 0x20 , 0 , V_75 , V_125 | 0x2010 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_3 , int V_104 )
{
if ( F_14 ( F_2 ( V_2 , V_3 ) ) != V_126 )
return;
if ( F_20 ( V_2 , V_3 ) & V_127 )
F_21 ( V_2 , V_3 , 0 , V_128 ,
V_104 ? 2 : 0 ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_104 )
{
static T_1 V_90 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_129 ;
for ( V_129 = V_90 ; * V_129 ; V_129 ++ )
F_43 ( V_2 , * V_129 , V_104 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_44 ( V_2 , false ) ;
F_46 ( 200 ) ;
}
static void F_47 ( struct V_1 * V_2 , int type )
{
unsigned int V_125 ;
F_44 ( V_2 , true ) ;
switch ( type ) {
case V_130 :
F_48 ( V_2 , V_131 ) ;
break;
case V_132 :
F_48 ( V_2 , V_133 ) ;
break;
case V_134 :
F_48 ( V_2 , V_135 ) ;
break;
case V_136 :
switch ( V_2 -> V_121 ) {
case 0x10ec0260 :
F_21 ( V_2 , 0x1a , 0 ,
V_72 , 7 ) ;
V_125 = F_19 ( V_2 , 0x1a , 0 ,
V_74 , 0 ) ;
F_21 ( V_2 , 0x1a , 0 ,
V_72 , 7 ) ;
F_21 ( V_2 , 0x1a , 0 ,
V_75 ,
V_125 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_42 ( V_2 ) ;
break;
case 0x10ec0888 :
F_41 ( V_2 ) ;
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
static int F_49 ( struct V_6 * V_7 ,
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
if ( V_11 -> V_111 ) {
V_9 -> V_20 . V_21 . V_42 = 3 ;
V_139 = V_138 ;
} else {
V_9 -> V_20 . V_21 . V_42 = 2 ;
V_139 = V_137 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_42 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_42 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_142 ,
V_139 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_46 ;
if ( ! V_11 -> V_106 )
V_46 = 0 ;
else if ( ! V_11 -> V_111 || ! V_11 -> V_112 )
V_46 = 1 ;
else
V_46 = 2 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_46 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_18 -> V_20 . V_21 . V_22 [ 0 ] ) {
case 0 :
if ( ! V_11 -> V_106 )
return 0 ;
V_11 -> V_106 = 0 ;
break;
case 1 :
if ( V_11 -> V_106 &&
( ! V_11 -> V_111 || ! V_11 -> V_112 ) )
return 0 ;
V_11 -> V_106 = 1 ;
V_11 -> V_112 = 0 ;
break;
case 2 :
if ( ! V_11 -> V_111 )
return - V_143 ;
if ( V_11 -> V_106 && V_11 -> V_112 )
return 0 ;
V_11 -> V_106 = 1 ;
V_11 -> V_112 = 1 ;
break;
default:
return - V_143 ;
}
F_35 ( V_2 ) ;
return 1 ;
}
static struct V_63 * F_52 ( struct V_10 * V_11 )
{
F_53 ( & V_11 -> V_144 , sizeof( struct V_63 ) , 32 ) ;
return F_54 ( & V_11 -> V_144 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_63 * V_145 ;
V_145 = F_52 ( V_11 ) ;
if ( ! V_145 )
return - V_146 ;
* V_145 = V_147 ;
V_145 -> V_142 = F_56 ( L_5 , V_148 ) ;
if ( ! V_145 -> V_142 )
return - V_146 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
int V_91 = 0 ;
int V_35 ;
if ( V_150 -> V_82 [ 0 ] )
V_91 ++ ;
if ( V_150 -> V_110 [ 0 ] )
V_91 ++ ;
if ( V_150 -> V_109 [ 0 ] )
V_91 ++ ;
if ( V_91 < 2 )
return;
if ( V_91 == 3 )
V_11 -> V_111 = 1 ;
if ( ! V_150 -> V_109 [ 0 ] &&
V_150 -> V_151 == V_152 ) {
memcpy ( V_150 -> V_109 , V_150 -> V_110 ,
sizeof( V_150 -> V_109 ) ) ;
V_150 -> V_153 = V_150 -> V_154 ;
}
if ( ! V_150 -> V_82 [ 0 ] &&
V_150 -> V_151 == V_155 ) {
memcpy ( V_150 -> V_82 , V_150 -> V_110 ,
sizeof( V_150 -> V_82 ) ) ;
V_150 -> V_156 = V_150 -> V_154 ;
}
for ( V_35 = 0 ; V_35 < V_150 -> V_156 ; V_35 ++ ) {
T_1 V_3 = V_150 -> V_82 [ V_35 ] ;
if ( ! F_58 ( V_2 , V_3 ) )
continue;
F_59 ( L_6 ,
V_3 ) ;
F_16 ( V_2 , V_3 , 0 ,
V_157 ,
V_158 | V_122 ) ;
V_11 -> V_106 = 1 ;
V_11 -> V_98 = V_99 ;
}
if ( V_11 -> V_106 && V_150 -> V_110 [ 0 ] &&
V_150 -> V_109 [ 0 ] &&
V_150 -> V_110 [ 0 ] != V_150 -> V_82 [ 0 ] &&
V_150 -> V_110 [ 0 ] != V_150 -> V_109 [ 0 ] ) {
for ( V_35 = 0 ; V_35 < V_150 -> V_154 ; V_35 ++ ) {
T_1 V_3 = V_150 -> V_110 [ V_35 ] ;
if ( ! F_58 ( V_2 , V_3 ) )
continue;
F_59 ( L_7
L_8 , V_3 ) ;
F_16 ( V_2 , V_3 , 0 ,
V_157 ,
V_158 | V_123 ) ;
V_11 -> V_113 = 1 ;
}
V_11 -> V_112 = V_11 -> V_113 ;
}
if ( V_11 -> V_106 ) {
F_55 ( V_2 ) ;
V_11 -> V_159 = F_39 ;
}
}
static int F_60 ( T_1 V_3 , const T_1 * V_160 , int V_161 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_161 ; V_35 ++ )
if ( V_160 [ V_35 ] == V_3 )
return V_35 ;
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_33 * V_34 = & V_11 -> V_162 [ 0 ] ;
int V_35 , V_163 , V_31 ;
T_1 V_164 , V_165 ;
if ( V_34 != V_11 -> V_15 )
return false ;
for ( V_163 = 0 ; V_163 < V_11 -> V_166 ; V_163 ++ ) {
V_164 = V_11 -> V_167 [ V_163 ] ;
for ( V_35 = 0 ; V_35 < V_34 -> V_16 ; V_35 ++ ) {
V_165 = V_11 -> V_114 [ V_35 ] ;
if ( ! V_165 )
return false ;
if ( F_62 ( V_2 , V_164 , V_165 ) < 0 )
break;
}
if ( V_35 >= V_34 -> V_16 )
return true ;
}
for ( V_35 = 0 ; V_35 < V_34 -> V_16 ; V_35 ++ ) {
V_165 = V_11 -> V_114 [ V_35 ] ;
for ( V_163 = 0 ; V_163 < V_11 -> V_166 ; V_163 ++ ) {
V_164 = V_11 -> V_167 [ V_163 ] ;
V_31 = F_62 ( V_2 , V_164 , V_165 ) ;
if ( V_31 >= 0 ) {
V_34 -> V_42 [ V_35 ] . V_43 = V_31 ;
V_11 -> V_27 [ V_35 ] = V_163 ;
break;
}
}
}
F_59 ( L_9 ) ;
V_11 -> V_36 = 1 ;
return true ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_33 * V_34 ;
static char * const V_139 [ 3 ] = {
L_10 , L_11 , L_12
} ;
int V_35 ;
if ( ! V_11 -> V_115 )
return false ;
V_34 = & V_11 -> V_162 [ 0 ] ;
if ( V_11 -> V_15 == V_34 )
return true ;
V_11 -> V_114 [ 0 ] = V_11 -> V_84 ;
V_11 -> V_114 [ 1 ] = V_11 -> V_168 ;
V_11 -> V_114 [ 2 ] = V_11 -> V_86 ;
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
strcpy ( V_34 -> V_42 [ V_35 ] . V_169 , V_139 [ V_35 ] ) ;
if ( V_11 -> V_114 [ V_35 ] )
V_34 -> V_16 = V_35 + 1 ;
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_34 ;
return true ;
}
static bool F_64 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_33 * V_34 ;
if ( ! V_11 -> V_115 )
return false ;
if ( V_11 -> V_116 )
return true ;
if ( ! F_61 ( V_2 ) ) {
V_11 -> V_115 = 0 ;
return false ;
}
V_34 = V_11 -> V_15 ;
V_11 -> V_118 = F_60 ( V_11 -> V_84 ,
V_11 -> V_114 , V_34 -> V_16 ) ;
V_11 -> V_117 = F_60 ( V_11 -> V_168 ,
V_11 -> V_114 , V_34 -> V_16 ) ;
V_11 -> V_119 = F_60 ( V_11 -> V_86 ,
V_11 -> V_114 , V_34 -> V_16 ) ;
if ( V_11 -> V_118 < 0 || V_11 -> V_117 < 0 ) {
V_11 -> V_115 = 0 ;
return false ;
}
F_16 ( V_2 , V_11 -> V_84 , 0 ,
V_157 ,
V_158 | V_124 ) ;
if ( V_11 -> V_86 )
F_16 ( V_2 , V_11 -> V_86 , 0 ,
V_157 ,
V_158 | V_124 ) ;
V_11 -> V_116 = 1 ;
V_11 -> V_115 = 1 ;
return true ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
T_1 V_170 , V_171 , V_172 ;
int V_35 ;
V_11 -> V_118 = V_11 -> V_117 = V_11 -> V_119 = - 1 ;
V_170 = V_171 = V_172 = 0 ;
for ( V_35 = 0 ; V_35 < V_150 -> V_173 ; V_35 ++ ) {
T_1 V_3 = V_150 -> V_174 [ V_35 ] . V_165 ;
unsigned int V_175 ;
V_175 = F_66 ( V_2 , V_3 ) ;
switch ( F_67 ( V_175 ) ) {
case V_176 :
if ( V_170 )
return;
if ( V_150 -> V_174 [ V_35 ] . type != V_48 )
return;
V_170 = V_3 ;
break;
case V_177 :
return;
case V_178 :
if ( V_172 )
return;
if ( V_150 -> V_174 [ V_35 ] . type > V_179 )
return;
V_172 = V_3 ;
break;
default:
if ( V_171 )
return;
if ( V_150 -> V_174 [ V_35 ] . type != V_48 )
return;
V_171 = V_3 ;
break;
}
}
if ( ! V_171 && V_172 ) {
V_171 = V_172 ;
V_172 = 0 ;
}
if ( ! V_171 || ! V_170 )
return;
if ( ! F_58 ( V_2 , V_171 ) )
return;
if ( V_172 && ! F_58 ( V_2 , V_172 ) )
return;
V_11 -> V_84 = V_171 ;
V_11 -> V_168 = V_170 ;
V_11 -> V_86 = V_172 ;
V_11 -> V_115 = 1 ;
if ( ! F_64 ( V_2 ) )
return;
F_59 ( L_13 ,
V_171 , V_170 , V_172 ) ;
V_11 -> V_159 = F_39 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned int V_180 , V_125 , V_35 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_181 . V_182 = 1 ;
if ( V_11 -> V_181 . V_183 ) {
V_180 = V_11 -> V_181 . V_184 ;
if ( V_180 == V_185 )
return - 1 ;
goto V_186;
}
V_180 = V_2 -> V_187 & 0xffff ;
if ( V_180 != V_2 -> V_188 -> V_189 -> V_190 && ( V_180 & 1 ) )
goto V_186;
V_3 = 0x1d ;
if ( V_2 -> V_121 == 0x10ec0260 )
V_3 = 0x17 ;
V_180 = F_66 ( V_2 , V_3 ) ;
if ( ! ( V_180 & 1 ) ) {
F_70 ( V_191 L_14 ,
V_2 -> V_192 , V_180 ) ;
return - 1 ;
}
V_125 = 0 ;
for ( V_35 = 1 ; V_35 < 16 ; V_35 ++ ) {
if ( ( V_180 >> V_35 ) & 1 )
V_125 ++ ;
}
if ( ( ( V_180 >> 16 ) & 0xf ) != V_125 )
return - 1 ;
V_11 -> V_181 . V_193 = V_180 >> 30 ;
V_11 -> V_181 . V_182 = ( V_180 & 0x100000 ) >> 20 ;
V_11 -> V_181 . V_194 = ( V_180 >> 16 ) & 0xf ;
V_11 -> V_181 . V_195 = V_180 >> 8 ;
V_186:
V_11 -> V_181 . V_184 = V_180 ;
V_11 -> V_181 . V_196 = ( V_180 & 0x38 ) >> 3 ;
V_11 -> V_181 . V_197 = ( V_180 & 0x4 ) >> 2 ;
V_11 -> V_181 . V_198 = ( V_180 & 0x2 ) >> 1 ;
V_11 -> V_181 . V_199 = V_180 & 0x1 ;
F_71 ( L_15 ,
V_3 , V_11 -> V_181 . V_184 ) ;
F_71 ( L_16 ,
V_11 -> V_181 . V_193 ) ;
F_71 ( L_17 , V_11 -> V_181 . V_182 ) ;
F_71 ( L_18 , V_11 -> V_181 . V_194 ) ;
F_71 ( L_19 , V_11 -> V_181 . V_195 ) ;
F_71 ( L_20 , V_11 -> V_181 . V_196 ) ;
F_71 ( L_21 , V_11 -> V_181 . V_197 ) ;
F_71 ( L_22 , V_11 -> V_181 . V_198 ) ;
F_71 ( L_23 , V_11 -> V_181 . V_199 ) ;
return 0 ;
}
static bool F_72 ( T_1 V_3 , const T_1 * V_160 , int V_161 )
{
return F_60 ( V_3 , V_160 , V_161 ) >= 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_1 V_200 , T_1 V_201 ,
T_1 V_202 , T_1 V_203 )
{
unsigned int V_180 , V_125 , V_35 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_181 . V_183 ) {
V_180 = V_11 -> V_181 . V_184 ;
if ( V_180 == V_185 )
return 0 ;
goto V_186;
}
V_180 = V_2 -> V_187 & 0xffff ;
if ( ( V_180 != V_2 -> V_188 -> V_189 -> V_190 ) && ( V_180 & 1 ) )
goto V_186;
V_3 = 0x1d ;
if ( V_2 -> V_121 == 0x10ec0260 )
V_3 = 0x17 ;
V_180 = F_66 ( V_2 , V_3 ) ;
F_71 ( L_24
L_25 ,
V_180 , V_3 ) ;
if ( ! ( V_180 & 1 ) )
return 0 ;
if ( ( V_180 >> 30 ) != 1 )
return 0 ;
V_125 = 0 ;
for ( V_35 = 1 ; V_35 < 16 ; V_35 ++ ) {
if ( ( V_180 >> V_35 ) & 1 )
V_125 ++ ;
}
if ( ( ( V_180 >> 16 ) & 0xf ) != V_125 )
return 0 ;
V_186:
F_71 ( L_26 ,
V_180 & 0xffff , V_2 -> V_121 ) ;
V_125 = ( V_180 & 0x38 ) >> 3 ;
switch ( V_125 ) {
case 1 :
V_11 -> V_204 = V_130 ;
break;
case 3 :
V_11 -> V_204 = V_132 ;
break;
case 7 :
V_11 -> V_204 = V_134 ;
break;
case 5 :
default:
V_11 -> V_204 = V_136 ;
break;
}
if ( ! ( V_180 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_81 . V_82 [ 0 ] &&
! ( V_11 -> V_81 . V_110 [ 0 ] &&
V_11 -> V_81 . V_151 == V_155 ) ) {
T_1 V_3 ;
V_125 = ( V_180 >> 11 ) & 0x3 ;
if ( V_125 == 0 )
V_3 = V_200 ;
else if ( V_125 == 1 )
V_3 = V_201 ;
else if ( V_125 == 2 )
V_3 = V_202 ;
else if ( V_125 == 3 )
V_3 = V_203 ;
else
return 1 ;
if ( F_72 ( V_3 , V_11 -> V_81 . V_110 ,
V_11 -> V_81 . V_154 ) )
return 1 ;
V_11 -> V_81 . V_82 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_74 ( struct V_1 * V_2 , const T_1 * V_205 )
{
if ( ! F_73 ( V_2 , V_205 [ 0 ] , V_205 [ 1 ] , V_205 [ 2 ] , V_205 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_71 ( L_27
L_28 ) ;
V_11 -> V_204 = V_136 ;
}
}
static void F_75 ( struct V_1 * V_2 , int V_206 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = V_11 -> V_207 ;
#ifdef F_76
const char * V_208 = V_11 -> V_209 ;
#endif
int V_210 = 0 ;
if ( ! V_11 -> V_211 )
return;
while ( V_13 >= 0 ) {
const struct V_212 * V_213 = V_11 -> V_211 + V_13 ;
const struct V_214 * V_150 ;
switch ( V_213 -> type ) {
case V_215 :
if ( V_206 != V_216 || ! V_213 -> V_39 . V_217 )
break; ;
F_59 ( V_191 L_29
L_30 ,
V_2 -> V_192 , V_208 ) ;
V_11 -> V_181 . V_184 = V_213 -> V_39 . V_217 ;
V_11 -> V_181 . V_183 = 1 ;
break;
case V_218 :
V_150 = V_213 -> V_39 . V_90 ;
if ( V_206 != V_216 || ! V_150 )
break;
F_59 ( V_191 L_29
L_31 ,
V_2 -> V_192 , V_208 ) ;
for (; V_150 -> V_3 ; V_150 ++ )
F_77 ( V_2 , V_150 -> V_3 ,
V_150 -> V_46 ) ;
break;
case V_219 :
if ( V_206 != V_220 || ! V_213 -> V_39 . V_221 )
break;
F_59 ( V_191 L_29
L_32 ,
V_2 -> V_192 , V_208 ) ;
F_25 ( V_2 -> V_11 , V_213 -> V_39 . V_221 ) ;
break;
case V_222 :
if ( ! V_213 -> V_39 . V_223 )
break;
F_59 ( V_191 L_29
L_33 ,
V_2 -> V_192 , V_208 ) ;
V_213 -> V_39 . V_223 ( V_2 , V_213 , V_206 ) ;
break;
default:
F_78 ( V_224 L_29
L_34 ,
V_2 -> V_192 , V_213 -> type ) ;
break;
}
if ( ! V_213 -> V_225 )
break;
if ( ++ V_210 > 10 )
break;
V_13 = V_213 -> V_226 ;
}
}
static void F_79 ( struct V_1 * V_2 ,
const struct V_227 * V_228 ,
const struct V_229 * V_230 ,
const struct V_212 * V_231 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 = - 1 ;
const char * V_142 = NULL ;
if ( V_2 -> V_208 && V_228 ) {
while ( V_228 -> V_142 ) {
if ( ! strcmp ( V_2 -> V_208 , V_228 -> V_142 ) ) {
V_13 = V_228 -> V_13 ;
V_142 = V_228 -> V_142 ;
break;
}
V_228 ++ ;
}
}
if ( V_13 < 0 ) {
V_230 = F_80 ( V_2 -> V_188 -> V_189 , V_230 ) ;
if ( V_230 ) {
V_13 = V_230 -> V_20 ;
#ifdef F_76
V_142 = V_230 -> V_142 ;
#endif
}
}
V_11 -> V_207 = V_13 ;
if ( V_13 >= 0 ) {
V_11 -> V_211 = V_231 ;
V_11 -> V_209 = V_142 ;
}
}
static int F_81 ( struct V_1 * V_2 ,
unsigned int V_77 )
{
unsigned int V_46 ;
F_21 ( V_2 , 0x20 , 0 , V_72 ,
V_77 ) ;
V_46 = F_19 ( V_2 , 0x20 , 0 ,
V_74 , 0 ) ;
return V_46 ;
}
static void F_82 ( struct V_1 * V_2 , unsigned int V_77 ,
unsigned int V_232 )
{
F_21 ( V_2 , 0x20 , 0 , V_72 ,
V_77 ) ;
F_21 ( V_2 , 0x20 , 0 , V_75 ,
V_232 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 ;
T_1 V_165 , V_233 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_81 . V_234 ; V_35 ++ ) {
V_165 = V_11 -> V_81 . V_235 [ V_35 ] ;
if ( ! V_165 )
continue;
F_21 ( V_2 , V_165 , 0 ,
V_62 , V_97 ) ;
if ( ! V_35 )
V_233 = V_11 -> V_236 . V_237 ;
else
V_233 = V_11 -> V_238 [ V_35 - 1 ] ;
if ( ! V_233 || ! ( F_2 ( V_2 , V_233 ) & V_239 ) )
continue;
F_21 ( V_2 , V_233 , 0 ,
V_240 ,
V_241 ) ;
}
V_165 = V_11 -> V_81 . V_242 ;
if ( V_165 )
F_21 ( V_2 , V_165 , 0 ,
V_62 ,
V_47 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 , V_79 ;
T_1 V_243 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_81 . V_234 ; V_35 ++ ) {
T_1 V_244 [ 4 ] ;
V_79 = F_85 ( V_2 ,
V_11 -> V_81 . V_235 [ V_35 ] ,
V_244 , F_24 ( V_244 ) ) ;
if ( V_79 < 0 )
continue;
V_243 = V_244 [ 0 ] ;
if ( ! V_35 ) {
V_11 -> V_236 . V_237 = V_243 ;
V_11 -> V_245 = V_11 -> V_81 . V_245 [ 0 ] ;
} else {
V_11 -> V_236 . V_238 = V_11 -> V_238 ;
if ( V_35 >= F_24 ( V_11 -> V_238 ) - 1 )
break;
V_11 -> V_238 [ V_35 - 1 ] = V_243 ;
}
}
if ( V_11 -> V_81 . V_242 ) {
V_243 = V_2 -> V_246 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_247 ; V_35 ++ , V_243 ++ ) {
unsigned int V_248 = F_2 ( V_2 , V_243 ) ;
if ( F_14 ( V_248 ) != V_249 )
continue;
if ( ! ( V_248 & V_250 ) )
continue;
if ( ! ( V_248 & V_251 ) )
continue;
V_79 = F_62 ( V_2 , V_243 ,
V_11 -> V_81 . V_242 ) ;
if ( V_79 >= 0 ) {
V_11 -> V_252 = V_243 ;
break;
}
}
}
}
static int F_86 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_46 ;
int V_79 ;
F_87 ( & V_2 -> V_253 ) ;
if ( V_11 -> V_254 )
V_46 = F_88 ( V_11 -> V_37 [ 0 ] , 3 , 0 , V_101 ) ;
else
V_46 = F_88 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_41 ) ;
V_7 -> V_255 = V_46 ;
V_79 = F_89 ( V_7 , V_9 ) ;
F_90 ( & V_2 -> V_253 ) ;
return V_79 ;
}
static int F_91 ( struct V_6 * V_7 , int V_256 ,
unsigned int V_257 , unsigned int T_2 * V_258 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_46 ;
int V_79 ;
F_87 ( & V_2 -> V_253 ) ;
if ( V_11 -> V_254 )
V_46 = F_88 ( V_11 -> V_37 [ 0 ] , 3 , 0 , V_101 ) ;
else
V_46 = F_88 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_41 ) ;
V_7 -> V_255 = V_46 ;
V_79 = F_92 ( V_7 , V_256 , V_257 , V_258 ) ;
F_90 ( & V_2 -> V_253 ) ;
return V_79 ;
}
static int F_93 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_223 , bool V_259 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 , V_79 = 0 ;
F_87 ( & V_2 -> V_253 ) ;
if ( V_259 && V_11 -> V_36 ) {
for ( V_35 = 0 ; V_35 < V_11 -> V_166 ; V_35 ++ ) {
V_7 -> V_255 =
F_88 ( V_11 -> V_26 [ V_35 ] ,
3 , 0 , V_41 ) ;
V_79 = V_223 ( V_7 , V_18 ) ;
if ( V_79 < 0 )
goto error;
}
} else {
V_35 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_254 )
V_7 -> V_255 =
F_88 ( V_11 -> V_37 [ V_35 ] ,
3 , 0 , V_101 ) ;
else
V_7 -> V_255 =
F_88 ( V_11 -> V_26 [ V_35 ] ,
3 , 0 , V_41 ) ;
V_79 = V_223 ( V_7 , V_18 ) ;
}
error:
F_90 ( & V_2 -> V_253 ) ;
return V_79 ;
}
static int F_94 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_93 ( V_7 , V_18 ,
V_260 , false ) ;
}
static int F_95 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_93 ( V_7 , V_18 ,
V_261 , true ) ;
}
static int F_96 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_93 ( V_7 , V_18 ,
V_262 , false ) ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_93 ( V_7 , V_18 ,
V_263 , true ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_264 = NULL ;
const struct V_63 * V_145 ;
int V_35 , V_265 , V_79 ;
unsigned int V_266 ;
T_1 V_3 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_65 ; V_35 ++ ) {
V_79 = F_99 ( V_2 , V_11 -> V_66 [ V_35 ] ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( V_11 -> V_267 ) {
V_79 = F_99 ( V_2 , V_11 -> V_267 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( V_11 -> V_236 . V_237 ) {
V_79 = F_100 ( V_2 ,
V_11 -> V_236 . V_237 ,
V_11 -> V_236 . V_237 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( ! V_11 -> V_268 ) {
V_79 = F_101 ( V_2 ,
& V_11 -> V_236 ) ;
if ( V_79 < 0 )
return V_79 ;
V_11 -> V_236 . V_269 = 1 ;
}
}
if ( V_11 -> V_252 ) {
V_79 = F_102 ( V_2 , V_11 -> V_252 ) ;
if ( V_79 < 0 )
return V_79 ;
}
#ifdef F_103
if ( V_11 -> V_270 ) {
const struct V_63 * V_145 ;
for ( V_145 = V_271 ; V_145 -> V_142 ; V_145 ++ ) {
struct V_6 * V_264 ;
V_264 = F_104 ( V_145 , V_2 ) ;
if ( ! V_264 )
return - V_146 ;
V_264 -> V_255 = V_11 -> V_270 ;
V_79 = F_105 ( V_2 , 0 , V_264 ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
#endif
if ( ! V_11 -> V_268 &&
! F_106 ( V_2 , L_35 ) ) {
unsigned int V_272 [ 4 ] ;
F_107 ( V_2 , V_11 -> V_273 ,
V_101 , V_272 ) ;
V_79 = F_108 ( V_2 , L_35 ,
V_272 , V_274 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( ! V_11 -> V_268 &&
! F_106 ( V_2 , L_36 ) ) {
V_79 = F_108 ( V_2 , L_36 ,
NULL , V_275 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( V_11 -> V_37 || V_11 -> V_26 ) {
V_264 = F_106 ( V_2 , L_37 ) ;
if ( ! V_264 )
V_264 = F_106 ( V_2 , L_38 ) ;
for ( V_35 = 0 ; V_264 && V_35 < V_264 -> V_141 ; V_35 ++ ) {
const T_1 * V_276 = V_11 -> V_37 ;
if ( ! V_276 )
V_276 = V_11 -> V_26 ;
V_79 = F_109 ( V_2 , V_264 , V_35 , V_276 [ V_35 ] ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
if ( V_11 -> V_267 && V_11 -> V_26 ) {
const char * V_277 = V_264 ? V_264 -> V_13 . V_142 : NULL ;
for ( V_145 = V_11 -> V_267 ; V_145 -> V_142 ; V_145 ++ ) {
if ( V_277 && strcmp ( V_145 -> V_142 , V_277 ) == 0 )
continue;
V_264 = F_106 ( V_2 , V_145 -> V_142 ) ;
for ( V_35 = 0 ; V_264 && V_35 < V_264 -> V_141 ; V_35 ++ ) {
V_79 = F_109 ( V_2 , V_264 , V_35 ,
V_11 -> V_26 [ V_35 ] ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
}
for ( V_35 = 0 ; V_35 < V_11 -> V_65 ; V_35 ++ ) {
for ( V_145 = V_11 -> V_66 [ V_35 ] ; V_145 -> V_142 ; V_145 ++ ) {
if ( V_145 -> V_278 != V_279 )
continue;
V_264 = F_106 ( V_2 , V_145 -> V_142 ) ;
if ( V_264 == NULL )
continue;
V_266 = V_145 -> V_280 ;
for ( V_265 = 0 ; V_265 < 4 ; V_265 ++ , V_266 >>= 8 ) {
V_3 = V_266 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_266 & 0xc0 ) {
case V_281 :
V_3 = V_11 -> V_81 . V_109 [ V_3 ] ;
break;
case V_282 :
V_3 = V_11 -> V_81 . V_110 [ V_3 ] ;
break;
case V_283 :
V_3 = V_11 -> V_81 . V_82 [ V_3 ] ;
break;
default:
continue;
}
V_79 = F_109 ( V_2 , V_264 , 0 , V_3 ) ;
if ( V_79 < 0 )
return V_79 ;
}
V_266 = V_145 -> V_255 ;
for ( V_265 = 0 ; V_265 < 4 ; V_265 ++ , V_266 >>= 8 ) {
V_3 = V_266 & 0xff ;
if ( V_3 == 0 )
continue;
V_79 = F_109 ( V_2 , V_264 , 0 , V_3 ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
}
F_110 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_35 ;
F_26 ( V_2 ) ;
F_47 ( V_2 , V_11 -> V_204 ) ;
for ( V_35 = 0 ; V_35 < V_11 -> V_69 ; V_35 ++ )
F_48 ( V_2 , V_11 -> V_70 [ V_35 ] ) ;
F_112 ( V_2 ) ;
if ( V_11 -> V_284 )
V_11 -> V_284 ( V_2 ) ;
F_75 ( V_2 , V_285 ) ;
F_113 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , unsigned int V_120 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_159 )
V_11 -> V_159 ( V_2 , V_120 ) ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_116 ( V_2 , & V_11 -> V_286 , V_3 ) ;
}
static int F_117 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_118 ( V_2 , & V_11 -> V_236 , V_290 ,
V_288 ) ;
}
static int F_119 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int V_292 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_120 ( V_2 , & V_11 -> V_236 ,
V_291 , V_292 , V_290 ) ;
}
static int F_121 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_122 ( V_2 , & V_11 -> V_236 ) ;
}
static int F_123 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_124 ( V_2 , & V_11 -> V_236 ) ;
}
static int F_125 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int V_292 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_126 ( V_2 , & V_11 -> V_236 ,
V_291 , V_292 , V_290 ) ;
}
static int F_127 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_128 ( V_2 , & V_11 -> V_236 ) ;
}
static int F_129 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_130 ( V_2 , & V_11 -> V_236 ) ;
}
static int F_131 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int V_292 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_290 -> V_293 + 1 ] ,
V_291 , 0 , V_292 ) ;
return 0 ;
}
static int F_132 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_133 ( V_2 ,
V_11 -> V_26 [ V_290 -> V_293 + 1 ] ) ;
return 0 ;
}
static int F_134 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int V_292 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_291 ;
V_11 -> V_30 = V_292 ;
F_11 ( V_2 , V_11 -> V_28 , V_291 , 0 , V_292 ) ;
return 0 ;
}
static int F_135 ( struct V_287 * V_288 ,
struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_133 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_294 * V_295 = V_11 -> V_296 ;
const struct V_287 * V_129 ;
int V_35 ;
V_2 -> V_297 = 1 ;
V_2 -> V_298 = V_295 ;
if ( V_11 -> V_268 )
goto V_299;
snprintf ( V_11 -> V_300 , sizeof( V_11 -> V_300 ) ,
L_39 , V_2 -> V_192 ) ;
V_295 -> V_142 = V_11 -> V_300 ;
if ( V_11 -> V_236 . V_301 > 0 ) {
V_129 = V_11 -> V_302 ;
if ( ! V_129 )
V_129 = & V_303 ;
V_295 -> V_304 [ V_305 ] = * V_129 ;
V_295 -> V_304 [ V_305 ] . V_3 = V_11 -> V_236 . V_301 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_129 = V_11 -> V_306 ;
if ( ! V_129 ) {
if ( V_11 -> V_36 )
V_129 = & V_307 ;
else
V_129 = & V_308 ;
}
V_295 -> V_304 [ V_309 ] = * V_129 ;
V_295 -> V_304 [ V_309 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_310 ) {
V_295 -> V_304 [ V_305 ] . V_311 = 0 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_312 ; V_35 ++ ) {
if ( V_11 -> V_310 [ V_35 ] . V_313 > V_295 -> V_304 [ V_305 ] . V_311 ) {
V_295 -> V_304 [ V_305 ] . V_311 = V_11 -> V_310 [ V_35 ] . V_313 ;
}
}
}
V_299:
if ( V_11 -> V_236 . V_237 || V_11 -> V_252 ) {
snprintf ( V_11 -> V_314 ,
sizeof( V_11 -> V_314 ) ,
L_40 , V_2 -> V_192 ) ;
V_2 -> V_297 = 2 ;
V_2 -> V_238 = V_11 -> V_236 . V_238 ;
V_295 = V_11 -> V_296 + 1 ;
V_295 -> V_142 = V_11 -> V_314 ;
if ( V_11 -> V_245 )
V_295 -> V_315 = V_11 -> V_245 ;
else
V_295 -> V_315 = V_316 ;
if ( V_11 -> V_236 . V_237 ) {
V_129 = V_11 -> V_317 ;
if ( ! V_129 )
V_129 = & V_318 ;
V_295 -> V_304 [ V_305 ] = * V_129 ;
V_295 -> V_304 [ V_305 ] . V_3 = V_11 -> V_236 . V_237 ;
}
if ( V_11 -> V_252 ) {
V_129 = V_11 -> V_319 ;
if ( ! V_129 )
V_129 = & V_320 ;
V_295 -> V_304 [ V_309 ] = * V_129 ;
V_295 -> V_304 [ V_309 ] . V_3 = V_11 -> V_252 ;
}
V_2 -> V_321 = 1 ;
}
if ( V_11 -> V_268 )
return 0 ;
if ( V_11 -> V_322 || V_11 -> V_166 > 1 ) {
V_2 -> V_297 = 3 ;
V_295 = V_11 -> V_296 + 2 ;
V_295 -> V_142 = V_11 -> V_300 ;
if ( V_11 -> V_322 ) {
V_129 = V_11 -> V_323 ;
if ( ! V_129 )
V_129 = & V_324 ;
V_295 -> V_304 [ V_305 ] = * V_129 ;
V_295 -> V_304 [ V_305 ] . V_3 =
V_11 -> V_322 ;
} else {
V_295 -> V_304 [ V_305 ] =
V_325 ;
V_295 -> V_304 [ V_305 ] . V_3 = 0 ;
}
if ( V_11 -> V_166 > 1 ) {
V_129 = V_11 -> V_326 ;
if ( ! V_129 )
V_129 = & V_327 ;
V_295 -> V_304 [ V_309 ] = * V_129 ;
V_295 -> V_304 [ V_309 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_295 -> V_304 [ V_309 ] . V_328 =
V_11 -> V_166 - 1 ;
} else {
V_295 -> V_304 [ V_309 ] =
V_325 ;
V_295 -> V_304 [ V_309 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_137 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_329 )
V_11 -> V_329 ( V_2 ) ;
F_138 ( V_2 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_144 . V_160 ) {
struct V_63 * V_264 = V_11 -> V_144 . V_160 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_144 . V_330 ; V_35 ++ )
F_139 ( V_264 [ V_35 ] . V_142 ) ;
}
F_140 ( & V_11 -> V_144 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_137 ( V_2 ) ;
F_142 ( V_2 ) ;
F_110 ( V_2 ) ;
F_139 ( V_11 ) ;
F_143 ( V_2 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_44 ( V_2 , false ) ;
}
static int F_145 ( struct V_1 * V_2 , T_4 V_331 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_137 ( V_2 ) ;
if ( V_11 && V_11 -> V_332 )
V_11 -> V_332 ( V_2 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
F_46 ( 150 ) ;
V_2 -> V_333 . V_334 ( V_2 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
F_113 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , const char * V_142 )
{
F_139 ( V_2 -> V_192 ) ;
V_2 -> V_192 = F_56 ( V_142 , V_148 ) ;
if ( ! V_2 -> V_192 ) {
F_141 ( V_2 ) ;
return - V_146 ;
}
return 0 ;
}
static int F_150 ( struct V_10 * V_11 , int type , const char * V_142 ,
int V_335 , unsigned long V_46 )
{
struct V_63 * V_145 ;
V_145 = F_52 ( V_11 ) ;
if ( ! V_145 )
return - V_146 ;
* V_145 = V_336 [ type ] ;
V_145 -> V_142 = F_56 ( V_142 , V_148 ) ;
if ( ! V_145 -> V_142 )
return - V_146 ;
V_145 -> V_43 = V_335 ;
if ( F_151 ( V_46 ) )
V_145 -> V_280 = V_337 ;
V_145 -> V_255 = V_46 ;
return 0 ;
}
static int F_152 ( struct V_10 * V_11 , int type ,
const char * V_338 , const char * V_4 ,
const char * V_339 , int V_335 , unsigned long V_46 )
{
char V_142 [ 32 ] ;
snprintf ( V_142 , sizeof( V_142 ) , L_41 , V_338 , V_4 , V_339 ) ;
return F_150 ( V_11 , type , V_142 , V_335 , V_46 ) ;
}
static const char * F_153 ( struct V_10 * V_11 , int V_340 ,
bool V_341 , int * V_43 )
{
struct V_149 * V_150 = & V_11 -> V_81 ;
static const char * const V_342 [ 4 ] = {
L_42 , L_43 , NULL , L_44
} ;
* V_43 = 0 ;
if ( V_150 -> V_154 == 1 && ! V_11 -> V_343 &&
! V_150 -> V_156 && ! V_150 -> V_153 && V_341 )
return L_45 ;
switch ( V_150 -> V_151 ) {
case V_152 :
if ( V_150 -> V_154 == 1 )
return L_46 ;
break;
case V_155 :
if ( V_340 && V_11 -> V_343 )
break;
* V_43 = V_340 ;
return L_47 ;
default:
if ( V_150 -> V_154 == 1 && ! V_11 -> V_343 )
return L_48 ;
break;
}
return V_342 [ V_340 ] ;
}
static int F_154 ( struct V_10 * V_11 , T_1 V_165 ,
const char * V_344 , int V_345 ,
int V_31 , T_1 V_346 )
{
int V_79 ;
V_79 = F_155 ( V_11 , V_347 , V_344 , V_345 ,
F_88 ( V_346 , 3 , V_31 , V_41 ) ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_156 ( V_11 , V_348 , V_344 , V_345 ,
F_88 ( V_346 , 3 , V_31 , V_41 ) ) ;
if ( V_79 < 0 )
return V_79 ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_49 = F_20 ( V_2 , V_3 ) ;
return ( V_49 & V_349 ) != 0 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_350 ;
T_1 * V_351 = V_11 -> V_167 ;
int V_352 = F_24 ( V_11 -> V_350 ) ;
bool V_353 = false ;
int V_35 , V_161 = 0 ;
V_3 = V_2 -> V_246 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_247 ; V_35 ++ , V_3 ++ ) {
T_1 V_354 ;
const T_1 * V_160 ;
unsigned int V_355 = F_2 ( V_2 , V_3 ) ;
int type = F_14 ( V_355 ) ;
if ( type != V_249 || ( V_355 & V_250 ) )
continue;
V_26 [ V_161 ] = V_3 ;
V_351 [ V_161 ] = V_3 ;
V_354 = V_3 ;
for (; ; ) {
int V_163 ;
type = F_14 ( F_2 ( V_2 , V_354 ) ) ;
if ( type == V_126 )
break;
if ( type == V_356 ) {
V_351 [ V_161 ] = V_354 ;
V_353 = true ;
break;
}
V_163 = F_13 ( V_2 , V_354 , & V_160 ) ;
if ( V_163 > 1 ) {
V_351 [ V_161 ] = V_354 ;
V_353 = true ;
break;
} else if ( V_163 != 1 )
break;
V_354 = * V_160 ;
}
if ( ++ V_161 >= V_352 )
break;
}
V_11 -> V_26 = V_11 -> V_350 ;
V_11 -> V_37 = V_11 -> V_167 ;
V_11 -> V_166 = V_161 ;
return V_161 ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_149 * V_150 = & V_11 -> V_81 ;
T_1 V_357 = V_11 -> V_358 ;
struct V_33 * V_34 = & V_11 -> V_162 [ 0 ] ;
int V_359 ;
int V_35 , V_360 , V_79 , V_31 , V_361 = 0 ;
const char * V_362 = NULL ;
V_359 = F_158 ( V_2 ) ;
if ( V_359 < 0 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_150 -> V_173 ; V_35 ++ ) {
T_1 V_165 ;
const char * V_169 ;
V_165 = V_150 -> V_174 [ V_35 ] . V_165 ;
if ( ! F_157 ( V_2 , V_165 ) )
continue;
V_169 = F_160 ( V_2 , V_150 , V_35 ) ;
if ( V_362 && ! strcmp ( V_169 , V_362 ) )
V_361 ++ ;
else
V_361 = 0 ;
V_362 = V_169 ;
if ( V_357 ) {
V_31 = F_62 ( V_2 , V_357 , V_165 ) ;
if ( V_31 >= 0 ) {
V_79 = F_154 ( V_11 , V_165 ,
V_169 , V_361 ,
V_31 , V_357 ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
for ( V_360 = 0 ; V_360 < V_359 ; V_360 ++ ) {
T_1 V_164 = V_11 -> V_37 ?
V_11 -> V_37 [ V_360 ] : V_11 -> V_26 [ V_360 ] ;
V_31 = F_62 ( V_2 , V_164 , V_165 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_114 [ V_34 -> V_16 ] = V_165 ;
F_161 ( V_34 , V_169 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_34 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_363 )
{
F_21 ( V_2 , V_3 , 0 , V_62 ,
V_363 ) ;
if ( F_163 ( V_2 , V_3 , V_101 ) )
F_21 ( V_2 , V_3 , 0 , V_240 ,
V_241 ) ;
}
static int F_164 ( int V_151 )
{
if ( V_151 == V_155 )
return V_96 ;
else
return V_97 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_150 -> V_173 ; V_35 ++ ) {
T_1 V_3 = V_150 -> V_174 [ V_35 ] . V_165 ;
if ( F_157 ( V_2 , V_3 ) ) {
F_18 ( V_2 , V_3 , V_150 -> V_174 [ V_35 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_239 )
F_21 ( V_2 , V_3 , 0 ,
V_240 ,
V_364 ) ;
}
}
if ( V_11 -> V_358 ) {
int V_161 = F_13 ( V_2 , V_11 -> V_358 , NULL ) ;
for ( V_35 = 0 ; V_35 < V_161 ; V_35 ++ )
F_21 ( V_2 , V_11 -> V_358 , 0 ,
V_240 ,
F_166 ( V_35 ) ) ;
}
}
static T_1 F_167 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_160 [ 5 ] ;
int V_35 , V_365 ;
if ( F_14 ( F_2 ( V_2 , V_3 ) ) == V_366 )
return V_3 ;
V_365 = F_85 ( V_2 , V_3 , V_160 , F_24 ( V_160 ) ) ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
if ( F_14 ( F_2 ( V_2 , V_160 [ V_35 ] ) ) == V_366 )
return V_160 [ V_35 ] ;
}
return 0 ;
}
static T_1 F_168 ( struct V_1 * V_2 , T_1 V_165 )
{
T_1 V_367 [ 5 ] ;
int V_365 = F_85 ( V_2 , V_165 , V_367 ,
F_24 ( V_367 ) ) ;
if ( V_365 != 1 ||
F_14 ( F_2 ( V_2 , V_367 [ 0 ] ) ) != V_356 )
return V_165 ;
return V_367 [ 0 ] ;
}
static T_1 F_169 ( struct V_1 * V_2 , T_1 V_165 ,
T_1 V_233 )
{
T_1 V_64 [ 5 ] ;
int V_35 , V_365 ;
V_165 = F_168 ( V_2 , V_165 ) ;
V_365 = F_85 ( V_2 , V_165 , V_64 , F_24 ( V_64 ) ) ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
if ( F_167 ( V_2 , V_64 [ V_35 ] ) == V_233 )
return V_64 [ V_35 ] ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , T_1 V_165 ,
T_1 V_233 )
{
T_1 V_64 [ 5 ] ;
int V_35 , V_365 ;
V_165 = F_168 ( V_2 , V_165 ) ;
V_365 = F_85 ( V_2 , V_165 , V_64 , F_24 ( V_64 ) ) ;
if ( V_365 < 2 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
if ( F_167 ( V_2 , V_64 [ V_35 ] ) == V_233 ) {
F_171 ( V_2 , V_165 , 0 ,
V_44 , V_35 ) ;
return 0 ;
}
}
return 0 ;
}
static T_1 F_172 ( struct V_1 * V_2 , T_1 V_165 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_367 [ 5 ] ;
int V_35 , V_365 ;
V_165 = F_168 ( V_2 , V_165 ) ;
V_365 = F_85 ( V_2 , V_165 , V_367 , F_24 ( V_367 ) ) ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
T_1 V_3 = F_167 ( V_2 , V_367 [ V_35 ] ) ;
if ( ! V_3 )
continue;
if ( F_72 ( V_3 , V_11 -> V_236 . V_301 ,
V_11 -> V_236 . V_368 ) )
continue;
if ( V_11 -> V_236 . V_80 == V_3 )
continue;
if ( F_72 ( V_3 , V_11 -> V_236 . V_369 ,
F_24 ( V_11 -> V_236 . V_369 ) ) )
continue;
return V_3 ;
}
return 0 ;
}
static T_1 F_173 ( struct V_1 * V_2 , T_1 V_165 )
{
T_1 V_370 = F_168 ( V_2 , V_165 ) ;
if ( F_13 ( V_2 , V_370 , NULL ) == 1 )
return F_172 ( V_2 , V_165 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_149 * V_150 = & V_11 -> V_81 ;
bool V_371 = false ;
int V_35 ;
V_372:
V_11 -> V_236 . V_368 = V_150 -> V_154 ;
V_11 -> V_236 . V_80 = 0 ;
V_11 -> V_236 . V_369 [ 0 ] = 0 ;
memset ( V_11 -> V_373 , 0 , sizeof( V_11 -> V_373 ) ) ;
V_11 -> V_236 . V_301 = V_11 -> V_373 ;
if ( ! V_371 ) {
for ( V_35 = 0 ; V_35 < V_150 -> V_154 ; V_35 ++ )
V_11 -> V_373 [ V_35 ] =
F_173 ( V_2 , V_150 -> V_110 [ V_35 ] ) ;
if ( V_150 -> V_156 )
V_11 -> V_236 . V_80 =
F_173 ( V_2 , V_150 -> V_82 [ 0 ] ) ;
if ( V_150 -> V_153 )
V_11 -> V_236 . V_369 [ 0 ] =
F_173 ( V_2 , V_150 -> V_109 [ 0 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_150 -> V_154 ; V_35 ++ ) {
T_1 V_165 = V_150 -> V_110 [ V_35 ] ;
if ( V_11 -> V_373 [ V_35 ] )
continue;
V_11 -> V_373 [ V_35 ] = F_172 ( V_2 , V_165 ) ;
if ( ! V_11 -> V_373 [ V_35 ] && ! V_371 ) {
V_371 = true ;
goto V_372;
}
}
V_11 -> V_236 . V_368 = 0 ;
for ( V_35 = 0 ; V_35 < V_150 -> V_154 ; V_35 ++ ) {
if ( V_11 -> V_373 [ V_35 ] )
V_11 -> V_236 . V_368 ++ ;
else
memmove ( V_11 -> V_373 + V_35 ,
V_11 -> V_373 + V_35 + 1 ,
sizeof( T_1 ) * ( V_150 -> V_154 - V_35 - 1 ) ) ;
}
if ( V_150 -> V_156 && ! V_11 -> V_236 . V_80 )
V_11 -> V_236 . V_80 =
F_172 ( V_2 , V_150 -> V_82 [ 0 ] ) ;
if ( V_150 -> V_153 && ! V_11 -> V_236 . V_369 [ 0 ] )
V_11 -> V_236 . V_369 [ 0 ] =
F_172 ( V_2 , V_150 -> V_109 [ 0 ] ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
const char * V_338 , int V_335 ,
T_1 V_3 , unsigned int V_374 )
{
if ( ! V_3 )
return 0 ;
return F_155 ( V_2 -> V_11 , V_347 , V_338 , V_335 ,
F_88 ( V_3 , V_374 , 0 , V_101 ) ) ;
}
static int F_176 ( struct V_1 * V_2 ,
const char * V_338 , int V_335 ,
T_1 V_3 , unsigned int V_374 )
{
int V_375 ;
int type ;
unsigned long V_46 ;
if ( ! V_3 )
return 0 ;
V_375 = F_14 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_375 == V_126 || V_375 == V_366 ) {
type = V_348 ;
V_46 = F_88 ( V_3 , V_374 , 0 , V_101 ) ;
} else if ( F_13 ( V_2 , V_3 , NULL ) == 1 ) {
type = V_348 ;
V_46 = F_88 ( V_3 , V_374 , 0 , V_41 ) ;
} else {
type = V_376 ;
V_46 = F_88 ( V_3 , V_374 , 2 , V_41 ) ;
}
return F_156 ( V_2 -> V_11 , type , V_338 , V_335 , V_46 ) ;
}
static T_1 F_177 ( struct V_1 * V_2 ,
T_1 V_165 , T_1 V_233 )
{
T_1 V_64 = F_169 ( V_2 , V_165 , V_233 ) ;
if ( F_163 ( V_2 , V_165 , V_101 ) )
return V_165 ;
else if ( V_64 && F_163 ( V_2 , V_64 , V_41 ) )
return V_64 ;
else if ( F_163 ( V_2 , V_233 , V_101 ) )
return V_233 ;
return 0 ;
}
static T_1 F_178 ( struct V_1 * V_2 ,
T_1 V_165 , T_1 V_233 )
{
T_1 V_64 = F_169 ( V_2 , V_165 , V_233 ) ;
if ( F_179 ( V_2 , V_233 , V_101 ) )
return V_233 ;
else if ( F_179 ( V_2 , V_64 , V_101 ) )
return V_64 ;
else if ( F_179 ( V_2 , V_165 , V_101 ) )
return V_165 ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 ,
const struct V_149 * V_150 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 , V_79 , V_377 ;
V_377 = V_150 -> V_154 ;
if ( V_11 -> V_343 > 0 )
V_377 += V_11 -> V_343 ;
for ( V_35 = 0 ; V_35 < V_377 ; V_35 ++ ) {
const char * V_142 ;
int V_43 ;
T_1 V_233 , V_165 ;
T_1 V_378 , V_379 ;
V_233 = V_11 -> V_236 . V_301 [ V_35 ] ;
if ( ! V_233 )
continue;
if ( V_35 >= V_150 -> V_154 )
V_165 = V_11 -> V_380 [ V_35 - 1 ] . V_165 ;
else
V_165 = V_150 -> V_110 [ V_35 ] ;
V_378 = F_177 ( V_2 , V_165 , V_233 ) ;
V_379 = F_178 ( V_2 , V_165 , V_233 ) ;
V_142 = F_153 ( V_11 , V_35 , true , & V_43 ) ;
if ( ! V_142 ) {
V_79 = F_175 ( V_2 , L_49 , 0 , V_379 , 1 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_175 ( V_2 , L_50 , 0 , V_379 , 2 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_176 ( V_2 , L_49 , 0 , V_378 , 1 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_176 ( V_2 , L_50 , 0 , V_378 , 2 ) ;
if ( V_79 < 0 )
return V_79 ;
} else {
V_79 = F_181 ( V_2 , V_142 , V_43 , V_379 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_182 ( V_2 , V_142 , V_43 , V_378 ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , T_1 V_165 ,
T_1 V_233 , const char * V_338 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_378 , V_379 ;
int V_79 ;
if ( ! V_165 )
return 0 ;
if ( ! V_233 ) {
if ( ! ( F_2 ( V_2 , V_165 ) & V_239 ) )
return 0 ;
return F_184 ( V_11 , V_348 , V_338 ,
F_88 ( V_165 , 3 , 0 , V_101 ) ) ;
}
V_378 = F_177 ( V_2 , V_165 , V_233 ) ;
V_379 = F_178 ( V_2 , V_165 , V_233 ) ;
V_79 = F_181 ( V_2 , V_338 , 0 , V_379 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_182 ( V_2 , V_338 , 0 , V_378 ) ;
if ( V_79 < 0 )
return V_79 ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_183 ( V_2 , V_11 -> V_81 . V_82 [ 0 ] ,
V_11 -> V_236 . V_80 ,
L_47 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_183 ( V_2 , V_11 -> V_81 . V_109 [ 0 ] ,
V_11 -> V_236 . V_369 [ 0 ] ,
L_46 ) ;
}
static void F_187 ( struct V_1 * V_2 ,
T_1 V_165 , int V_363 ,
T_1 V_233 )
{
int V_35 , V_365 ;
T_1 V_3 , V_64 = 0 ;
T_1 V_367 [ V_381 ] ;
F_162 ( V_2 , V_165 , V_363 ) ;
V_3 = F_168 ( V_2 , V_165 ) ;
V_365 = F_85 ( V_2 , V_3 , V_367 , F_24 ( V_367 ) ) ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
if ( F_167 ( V_2 , V_367 [ V_35 ] ) != V_233 )
continue;
V_64 = V_367 [ V_35 ] ;
break;
}
if ( ! V_64 )
return;
if ( V_365 > 1 )
F_21 ( V_2 , V_3 , 0 , V_44 , V_35 ) ;
if ( F_163 ( V_2 , V_64 , V_41 ) ) {
F_21 ( V_2 , V_64 , 0 , V_240 ,
F_188 ( 0 ) ) ;
F_21 ( V_2 , V_64 , 0 , V_240 ,
F_188 ( 1 ) ) ;
}
V_3 = F_178 ( V_2 , V_165 , V_233 ) ;
if ( V_3 )
F_21 ( V_2 , V_3 , 0 , V_240 ,
V_382 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_363 = F_164 ( V_11 -> V_81 . V_151 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 <= V_383 ; V_35 ++ ) {
T_1 V_3 = V_11 -> V_81 . V_110 [ V_35 ] ;
if ( V_3 )
F_187 ( V_2 , V_3 , V_363 ,
V_11 -> V_236 . V_301 [ V_35 ] ) ;
}
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_165 , V_233 ;
V_165 = V_11 -> V_81 . V_82 [ 0 ] ;
if ( V_165 ) {
V_233 = V_11 -> V_236 . V_80 ;
if ( ! V_233 )
V_233 = V_11 -> V_236 . V_301 [ 0 ] ;
F_187 ( V_2 , V_165 , V_96 , V_233 ) ;
}
V_165 = V_11 -> V_81 . V_109 [ 0 ] ;
if ( V_165 ) {
V_233 = V_11 -> V_236 . V_369 [ 0 ] ;
if ( ! V_233 )
V_233 = V_11 -> V_236 . V_301 [ 0 ] ;
F_187 ( V_2 , V_165 , V_97 , V_233 ) ;
}
}
static int F_191 ( struct V_1 * V_2 ,
unsigned int V_384 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
int type , V_35 , V_89 = 0 ;
for ( type = V_179 ; type >= V_48 ; type -- ) {
for ( V_35 = 0 ; V_35 < V_150 -> V_173 ; V_35 ++ ) {
T_1 V_3 = V_150 -> V_174 [ V_35 ] . V_165 ;
T_1 V_233 ;
unsigned int V_175 , V_355 ;
if ( V_150 -> V_174 [ V_35 ] . type != type )
continue;
V_175 = F_66 ( V_2 , V_3 ) ;
if ( F_192 ( V_175 ) != V_385 )
continue;
if ( V_384 && F_193 ( V_175 ) != V_384 )
continue;
V_355 = F_20 ( V_2 , V_3 ) ;
if ( ! ( V_355 & V_386 ) )
continue;
V_233 = F_172 ( V_2 , V_3 ) ;
if ( ! V_233 )
continue;
V_11 -> V_380 [ V_89 ] . V_165 = V_3 ;
V_11 -> V_380 [ V_89 ] . V_233 = V_233 ;
V_89 ++ ;
V_11 -> V_373 [ V_11 -> V_236 . V_368 ++ ] = V_233 ;
}
}
V_11 -> V_236 . V_368 = 1 ;
if ( V_89 < 2 )
return 0 ;
return V_89 ;
}
static int F_194 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_140 ;
V_9 -> V_141 = 1 ;
V_9 -> V_20 . V_21 . V_42 = V_11 -> V_343 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_343 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_343 ;
sprintf ( V_9 -> V_20 . V_21 . V_142 , L_51 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_195 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_387 - 1 ) / 2 ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , int V_31 , bool V_388 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_380 [ V_31 ] . V_165 ;
if ( ! V_11 -> V_380 [ V_31 ] . V_389 )
V_11 -> V_380 [ V_31 ] . V_389 =
F_19 ( V_2 , V_3 , 0 ,
V_51 , 0 ) ;
if ( V_388 ) {
F_171 ( V_2 , V_3 , 0 ,
V_62 ,
V_97 ) ;
if ( F_2 ( V_2 , V_3 ) & V_239 )
F_15 ( V_2 , V_3 , V_101 , 0 ,
V_40 , 0 ) ;
F_170 ( V_2 , V_3 , V_11 -> V_380 [ V_31 ] . V_233 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_239 )
F_15 ( V_2 , V_3 , V_101 , 0 ,
V_40 , V_40 ) ;
F_171 ( V_2 , V_3 , 0 ,
V_62 ,
V_11 -> V_380 [ V_31 ] . V_389 ) ;
}
return 0 ;
}
static int F_197 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 , V_340 ;
V_340 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_340 < 0 || V_340 > V_11 -> V_343 )
return - V_143 ;
if ( V_340 == ( V_11 -> V_387 - 1 ) / 2 )
return 0 ;
V_11 -> V_387 = ( V_340 + 1 ) * 2 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_343 ; V_35 ++ )
F_196 ( V_2 , V_35 , V_35 < V_340 ) ;
V_11 -> V_236 . V_390 = V_11 -> V_387 ;
if ( V_11 -> V_391 && ! V_11 -> V_392 )
V_11 -> V_236 . V_368 = V_11 -> V_236 . V_390 / 2 ;
return 1 ;
}
static int F_198 ( struct V_1 * V_2 ,
int (* F_199)( struct V_1 * ) )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
unsigned int V_384 , V_175 ;
int V_89 ;
if ( V_150 -> V_151 == V_152 && V_150 -> V_156 == 1 ) {
V_150 -> V_153 = V_150 -> V_154 ;
memcpy ( V_150 -> V_109 , V_150 -> V_110 ,
sizeof( V_150 -> V_109 ) ) ;
V_150 -> V_154 = V_150 -> V_156 ;
memcpy ( V_150 -> V_110 , V_150 -> V_82 , sizeof( V_150 -> V_82 ) ) ;
V_150 -> V_156 = 0 ;
memset ( V_150 -> V_82 , 0 , sizeof( V_150 -> V_82 ) ) ;
V_150 -> V_151 = V_155 ;
if ( F_199 )
F_199 ( V_2 ) ;
}
if ( V_150 -> V_154 != 1 ||
V_150 -> V_151 == V_152 )
return 0 ;
V_175 = F_66 ( V_2 , V_150 -> V_110 [ 0 ] ) ;
V_384 = F_193 ( V_175 ) ;
V_89 = F_191 ( V_2 , V_384 ) ;
if ( V_89 > 0 ) {
struct V_63 * V_145 ;
V_145 = F_52 ( V_11 ) ;
if ( ! V_145 )
return - V_146 ;
* V_145 = V_393 ;
V_145 -> V_142 = F_56 ( L_52 , V_148 ) ;
if ( ! V_145 -> V_142 )
return - V_146 ;
V_11 -> V_343 = V_89 ;
V_11 -> V_387 = 2 ;
V_11 -> V_236 . V_368 = V_89 + 1 ;
}
return 0 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_33 * V_34 ;
T_1 V_26 [ F_24 ( V_11 -> V_350 ) ] ;
T_1 V_37 [ F_24 ( V_11 -> V_350 ) ] ;
int V_35 , V_163 , V_161 ;
V_34 = V_11 -> V_15 ;
if ( ! V_34 )
return;
if ( V_11 -> V_36 )
return;
V_161 = 0 ;
for ( V_163 = 0 ; V_163 < V_11 -> V_166 ; V_163 ++ ) {
T_1 V_164 = V_11 -> V_167 [ V_163 ] ;
int V_394 = F_13 ( V_2 , V_164 , NULL ) ;
for ( V_35 = 0 ; V_35 < V_34 -> V_16 ; V_35 ++ ) {
T_1 V_165 = V_11 -> V_114 [ V_35 ] ;
if ( V_165 ) {
if ( F_62 ( V_2 , V_164 , V_165 ) < 0 )
break;
} else if ( V_394 <= V_34 -> V_42 [ V_35 ] . V_43 )
break;
}
if ( V_35 >= V_34 -> V_16 ) {
V_26 [ V_161 ] = V_11 -> V_350 [ V_163 ] ;
V_37 [ V_161 ++ ] = V_164 ;
}
}
if ( ! V_161 ) {
if ( ! F_61 ( V_2 ) ) {
F_70 ( V_395 L_53
L_54 ,
V_2 -> V_192 , V_11 -> V_350 [ 0 ] ) ;
V_11 -> V_166 = 1 ;
V_11 -> V_115 = 0 ;
return;
}
} else if ( V_161 != V_11 -> V_166 ) {
memcpy ( V_11 -> V_350 , V_26 ,
V_161 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_167 , V_37 ,
V_161 * sizeof( T_1 ) ) ;
V_11 -> V_166 = V_161 ;
}
if ( V_11 -> V_115 )
F_64 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 )
V_11 -> V_166 = 1 ;
}
static void F_201 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_163 ( V_2 , V_3 , V_41 ) ) {
F_21 ( V_2 , V_3 , 0 ,
V_240 ,
F_166 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_37 )
return;
V_3 = V_11 -> V_37 [ V_19 ] ;
if ( F_163 ( V_2 , V_3 , V_101 ) )
F_21 ( V_2 , V_3 , 0 ,
V_240 ,
V_364 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_360 , V_161 ;
for ( V_360 = 0 ; V_360 < V_11 -> V_166 ; V_360 ++ )
F_201 ( V_2 , V_360 ) ;
if ( V_11 -> V_36 )
V_161 = 1 ;
else
V_161 = V_11 -> V_166 ;
for ( V_360 = 0 ; V_360 < V_161 ; V_360 ++ )
F_12 ( V_2 , 0 , V_11 -> V_23 [ V_360 ] , true ) ;
}
static int F_203 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_149 * V_150 = & V_11 -> V_81 ;
int V_35 , V_79 ;
int V_361 = 0 ;
T_1 V_3 ;
const char * V_362 = NULL ;
for ( V_35 = 0 ; V_35 < V_150 -> V_173 ; V_35 ++ ) {
if ( V_150 -> V_174 [ V_35 ] . type > V_48 )
break;
V_3 = V_150 -> V_174 [ V_35 ] . V_165 ;
if ( F_2 ( V_2 , V_3 ) & V_396 ) {
const char * V_169 ;
char V_397 [ 32 ] ;
V_169 = F_160 ( V_2 , V_150 , V_35 ) ;
if ( V_362 && ! strcmp ( V_169 , V_362 ) )
V_361 ++ ;
else
V_361 = 0 ;
V_362 = V_169 ;
snprintf ( V_397 , sizeof( V_397 ) ,
L_55 , V_169 ) ;
V_79 = F_150 ( V_11 , V_347 ,
V_397 , V_361 ,
F_88 ( V_3 , 3 , 0 , V_41 ) ) ;
if ( V_79 < 0 )
return V_79 ;
}
}
return 0 ;
}
static void F_204 ( struct V_1 * V_2 , T_1 V_164 ,
int V_31 )
{
if ( F_14 ( F_2 ( V_2 , V_164 ) ) == V_38 ) {
F_15 ( V_2 , V_164 , V_41 , V_31 ,
V_40 , 0 ) ;
} else if ( F_13 ( V_2 , V_164 , NULL ) > 1 ) {
F_16 ( V_2 , V_164 , 0 ,
V_44 , V_31 ) ;
}
}
static int F_205 ( struct V_1 * V_2 , T_1 V_165 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 ;
if ( ! V_165 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_166 ; V_35 ++ ) {
T_1 V_164 = V_11 -> V_37 ?
V_11 -> V_37 [ V_35 ] : V_11 -> V_26 [ V_35 ] ;
int V_31 ;
V_31 = F_62 ( V_2 , V_164 , V_165 ) ;
if ( V_31 < 0 )
continue;
F_204 ( V_2 , V_164 , V_31 ) ;
return V_35 ;
}
return - 1 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_81 . V_173 ; V_35 ++ )
F_205 ( V_2 , V_11 -> V_81 . V_174 [ V_35 ] . V_165 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_63 * V_355 [ 2 ] [ 3 ] = {
{ V_398 ,
V_399 ,
V_400 } ,
{ V_401 ,
V_402 ,
V_403 } ,
} ;
if ( ! F_179 ( V_2 , V_11 -> V_26 [ 0 ] , V_41 ) ) {
if ( ! V_11 -> V_37 )
return;
if ( ! F_179 ( V_2 , V_11 -> V_37 [ 0 ] , V_101 ) )
return;
V_11 -> V_254 = 1 ;
}
if ( V_11 -> V_166 > 0 ) {
int V_404 = 0 ;
int V_359 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_404 = 1 ;
if ( V_11 -> V_115 ) {
V_359 = 1 ;
V_404 = 0 ;
} else if ( V_11 -> V_36 )
V_359 = 1 ;
if ( ! V_359 ) {
if ( V_11 -> V_166 > 3 )
V_11 -> V_166 = 3 ;
else if ( ! V_11 -> V_166 )
return;
V_359 = V_11 -> V_166 ;
}
V_11 -> V_267 = V_355 [ V_404 ] [ V_359 - 1 ] ;
}
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_189 ( V_2 ) ;
F_190 ( V_2 ) ;
F_165 ( V_2 ) ;
F_202 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( V_11 -> V_159 )
F_40 ( V_2 ) ;
}
static inline int F_208 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_229 * V_405 ;
V_405 = F_80 ( V_2 -> V_188 -> V_189 , V_406 ) ;
if ( V_405 )
return V_405 -> V_20 ;
return V_11 -> V_181 . V_182 ;
}
static int F_209 ( struct V_1 * V_2 ,
const T_1 * V_407 ,
const T_1 * V_408 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_79 ;
V_79 = F_210 ( V_2 , & V_11 -> V_81 ,
V_407 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( ! V_11 -> V_81 . V_154 ) {
if ( V_11 -> V_81 . V_234 || V_11 -> V_81 . V_242 ) {
V_11 -> V_236 . V_390 = 2 ;
V_11 -> V_268 = 1 ;
goto V_409;
}
return 0 ;
}
V_79 = F_174 ( V_2 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_198 ( V_2 , F_174 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_180 ( V_2 , & V_11 -> V_81 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_185 ( V_2 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_186 ( V_2 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_159 ( V_2 ) ;
if ( V_79 < 0 )
return V_79 ;
V_11 -> V_236 . V_390 = V_11 -> V_236 . V_368 * 2 ;
V_409:
F_84 ( V_2 ) ;
if ( ! V_11 -> V_268 )
F_200 ( V_2 ) ;
if ( V_408 )
F_74 ( V_2 , V_408 ) ;
if ( ! V_11 -> V_268 ) {
F_68 ( V_2 ) ;
V_79 = F_203 ( V_2 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( V_11 -> V_144 . V_160 )
F_22 ( V_11 , V_11 -> V_144 . V_160 ) ;
return 1 ;
}
static int F_211 ( struct V_1 * V_2 )
{
static const T_1 V_410 [] = { 0x1d , 0 } ;
static const T_1 V_411 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_209 ( V_2 , V_410 , V_411 ) ;
}
static int F_212 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 ;
int V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
V_11 -> V_391 = 1 ;
V_412 = F_214 ( V_2 , V_413 ,
V_414 , V_415 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
V_79 = F_211 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_58 ) ;
V_412 = V_417 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_418 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x0b , 0x05 , V_41 ) ;
}
V_11 -> V_273 = 0x0c ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_421 ;
#endif
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
static const T_1 V_422 [] = { 0x17 , 0 } ;
static const T_1 V_423 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_209 ( V_2 , V_422 , V_423 ) ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_79 , V_412 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x07 ;
V_412 = F_214 ( V_2 , V_424 ,
V_425 , V_426 ) ;
if ( V_412 < 0 ) {
F_71 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_427 , V_428 ) ;
F_75 ( V_2 , V_216 ) ;
}
if ( V_412 == V_416 ) {
V_79 = F_220 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_429 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_430 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x07 , 0x05 , V_41 ) ;
}
F_75 ( V_2 , V_220 ) ;
V_11 -> V_273 = 0x08 ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_45 ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_431 ;
#endif
return 0 ;
}
static int F_222 ( struct V_1 * V_2 )
{
static const T_1 V_432 [] = { 0x1d , 0 } ;
static const T_1 V_433 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_209 ( V_2 , V_432 , V_433 ) ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_79 , V_412 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
switch ( V_2 -> V_121 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_27 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
V_412 = F_214 ( V_2 , V_434 ,
V_435 , V_436 ) ;
if ( V_412 < 0 )
V_412 = F_224 ( V_2 ,
V_434 , V_435 , V_437 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_438 , V_439 ) ;
F_75 ( V_2 , V_216 ) ;
}
F_69 ( V_2 ) ;
if ( V_412 == V_416 ) {
V_79 = F_222 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_440 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_441 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 && F_208 ( V_2 ) ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x0b , 0x05 , V_41 ) ;
}
F_75 ( V_2 , V_220 ) ;
V_11 -> V_273 = 0x0c ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
F_28 ( V_2 ) ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_442 ;
#endif
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
static const T_1 V_443 [] = { 0x1d , 0 } ;
static const T_1 V_444 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_209 ( V_2 , V_443 , V_444 ) ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 ;
int V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_69 ( V_2 ) ;
F_27 ( V_2 , 0x20 , 0x0a , 10 ) ;
V_412 = F_214 ( V_2 , V_445 ,
V_446 , V_447 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_448 , V_449 ) ;
F_75 ( V_2 , V_216 ) ;
}
if ( V_412 == V_416 ) {
V_79 = F_225 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_450 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_451 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 && F_208 ( V_2 ) ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x0b , 0x05 , V_41 ) ;
}
F_75 ( V_2 , V_220 ) ;
V_11 -> V_273 = 0x0c ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_45 ;
F_28 ( V_2 ) ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_452 ;
#endif
return 0 ;
}
static int F_227 ( struct V_1 * V_2 )
{
static const T_1 V_453 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_79 = F_209 ( V_2 , NULL , V_453 ) ;
if ( V_79 > 0 ) {
if ( ! V_11 -> V_268 && V_11 -> V_81 . V_109 [ 0 ] != 0x1d ) {
F_22 ( V_11 , V_454 ) ;
F_25 ( V_11 , V_455 ) ;
}
}
return V_79 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 ;
int V_35 , V_456 , V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_412 = F_214 ( V_2 , V_457 ,
V_458 , V_459 ) ;
if ( V_412 < 0 )
V_412 = F_224 ( V_2 ,
V_457 , V_458 , V_460 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
V_79 = F_227 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_461 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_462 [ V_412 ] ) ;
V_456 = 0 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_65 ; V_35 ++ ) {
if ( V_11 -> V_66 [ V_35 ] == V_454 ) {
V_456 = 1 ;
break;
}
}
if ( V_456 ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
if ( ! F_3 ( V_2 , 0x1d , V_41 ) )
F_229 ( V_2 , 0x1d , V_41 ,
( 0x0c << V_463 ) |
( 0x0c << V_464 ) |
( 0x07 << V_465 ) |
( 0 << V_466 ) ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
V_11 -> V_273 = 0x02 ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_45 ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_187 ) {
case 0x103c1586 :
return 1 ;
}
return 0 ;
}
static int F_231 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == 0x01 || V_3 == 0x14 ) {
int V_467 ;
if ( F_232 ( V_2 , 0x14 , 0 , V_101 , 0 ) &
V_40 )
V_467 = 0x24 ;
else
V_467 = 0x20 ;
F_171 ( V_2 , 0x19 , 0 ,
V_62 ,
V_467 ) ;
}
return F_115 ( V_2 , V_3 ) ;
}
static int F_233 ( struct V_1 * V_2 )
{
static const T_1 V_468 [] = { 0x1d , 0 } ;
static const T_1 V_469 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_470 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_471 = V_11 -> V_472 == V_473 ?
V_470 : V_469 ;
return F_209 ( V_2 , V_468 , V_471 ) ;
}
static void F_234 ( struct V_1 * V_2 , int V_474 )
{
int V_46 = F_81 ( V_2 , 0x04 ) ;
if ( V_474 )
V_46 |= 1 << 11 ;
else
V_46 &= ~ ( 1 << 11 ) ;
F_82 ( V_2 , 0x04 , V_46 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x017 )
F_234 ( V_2 , 0 ) ;
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x018 ) {
F_234 ( V_2 , 0 ) ;
F_46 ( 150 ) ;
}
}
static int F_236 ( struct V_1 * V_2 )
{
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x018 ) {
F_234 ( V_2 , 0 ) ;
F_46 ( 150 ) ;
}
V_2 -> V_333 . V_334 ( V_2 ) ;
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x017 ) {
F_234 ( V_2 , 1 ) ;
F_46 ( 200 ) ;
}
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x018 )
F_234 ( V_2 , 1 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
F_113 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_237 ( struct V_1 * V_2 ,
const struct V_212 * V_213 , int V_206 )
{
int V_475 ;
if ( V_206 != V_285 )
return;
V_475 = F_81 ( V_2 , 0x1e ) ;
F_82 ( V_2 , 0x1e , V_475 | 0x80 ) ;
}
static void F_238 ( struct V_1 * V_2 ,
const struct V_212 * V_213 , int V_206 )
{
static const struct V_67 V_221 [] = {
{ 0x20 , V_72 , 0x0d } ,
{ 0x20 , V_75 , 0x4000 } ,
{}
} ;
unsigned int V_150 ;
if ( strcmp ( V_2 -> V_192 , L_60 ) )
return;
V_150 = F_66 ( V_2 , 0x12 ) ;
if ( F_192 ( V_150 ) == V_476 )
F_48 ( V_2 , V_221 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
const struct V_212 * V_213 , int V_206 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_206 != V_220 )
return;
V_11 -> V_302 = & V_477 ;
V_11 -> V_306 = & V_478 ;
}
static void F_240 ( struct V_1 * V_2 ,
const struct V_212 * V_213 , int V_206 )
{
int V_475 ;
if ( V_206 != V_285 )
return;
V_475 = F_81 ( V_2 , 0x07 ) ;
F_82 ( V_2 , 0x07 , V_475 | 0x80 ) ;
}
static int F_241 ( struct V_1 * V_2 )
{
int V_46 ;
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) < 0x015 ) {
F_82 ( V_2 , 0xf , 0x960b ) ;
F_82 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x016 ) {
F_82 ( V_2 , 0xf , 0x960b ) ;
F_82 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x017 ) {
V_46 = F_81 ( V_2 , 0x04 ) ;
F_82 ( V_2 , 0x04 , V_46 | ( 1 << 11 ) ) ;
}
if ( ( F_81 ( V_2 , 0 ) & 0x00ff ) == 0x018 ) {
V_46 = F_81 ( V_2 , 0xd ) ;
if ( ( V_46 & 0x0c00 ) >> 10 != 0x1 ) {
F_82 ( V_2 , 0xd , V_46 | ( 1 << 10 ) ) ;
}
V_46 = F_81 ( V_2 , 0x17 ) ;
if ( ( V_46 & 0x01c0 ) >> 6 != 0x4 ) {
F_82 ( V_2 , 0x17 , V_46 | ( 1 << 7 ) ) ;
}
}
V_46 = F_81 ( V_2 , 0xd ) ;
F_82 ( V_2 , 0xd , V_46 | ( 1 << 14 ) ) ;
V_46 = F_81 ( V_2 , 0x4 ) ;
F_82 ( V_2 , 0x4 , V_46 | ( 1 << 11 ) ) ;
return 0 ;
}
static int F_242 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 , V_475 ;
int V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
F_69 ( V_2 ) ;
if ( V_2 -> V_121 == 0x10ec0269 ) {
V_11 -> V_472 = V_473 ;
V_475 = F_81 ( V_2 , 0 ) ;
if ( ( V_475 & 0x00f0 ) == 0x0010 ) {
if ( V_2 -> V_188 -> V_189 -> V_479 == 0x1025 &&
V_11 -> V_181 . V_197 == 1 ) {
F_149 ( V_2 , L_60 ) ;
} else if ( ( V_475 & 0xf000 ) == 0x2000 ) {
F_149 ( V_2 , L_61 ) ;
} else if ( ( V_475 & 0xf000 ) == 0x3000 ) {
F_149 ( V_2 , L_62 ) ;
} else if ( ( V_475 & 0xfff0 ) == 0x3010 ) {
F_149 ( V_2 , L_63 ) ;
} else {
F_149 ( V_2 , L_64 ) ;
}
V_11 -> V_472 = V_480 ;
} else if ( ( V_475 & 0x00f0 ) == 0x0020 ) {
if ( V_475 == 0xa023 )
F_149 ( V_2 , L_61 ) ;
else if ( V_475 == 0x6023 )
F_149 ( V_2 , L_65 ) ;
else if ( V_2 -> V_188 -> V_189 -> V_479 == 0x17aa &&
V_2 -> V_188 -> V_189 -> V_190 == 0x21f3 )
F_149 ( V_2 , L_66 ) ;
else
F_149 ( V_2 , L_67 ) ;
V_11 -> V_472 = V_481 ;
} else
F_27 ( V_2 , 0x20 , 0x04 , 15 ) ;
F_241 ( V_2 ) ;
}
V_412 = F_214 ( V_2 , V_482 ,
V_483 , V_484 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_485 , V_486 ) ;
F_75 ( V_2 , V_216 ) ;
}
if ( V_412 == V_416 ) {
V_79 = F_233 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_487 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_488 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 && F_208 ( V_2 ) ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x0b , 0x04 , V_41 ) ;
}
F_75 ( V_2 , V_220 ) ;
V_11 -> V_273 = 0x02 ;
V_2 -> V_333 = V_419 ;
#ifdef F_243
V_2 -> V_333 . V_489 = F_236 ;
#endif
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_235 ;
F_28 ( V_2 ) ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_490 ;
if ( F_230 ( V_2 ) )
V_2 -> V_333 . V_491 = F_231 ;
#endif
return 0 ;
}
static int F_244 ( struct V_1 * V_2 )
{
static const T_1 V_492 [] = { 0x1d , 0 } ;
static const T_1 V_493 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_209 ( V_2 , V_492 , V_493 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 ;
int V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x15 ;
V_412 = F_214 ( V_2 , V_494 ,
V_495 , V_496 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_497 , V_498 ) ;
F_75 ( V_2 , V_216 ) ;
}
if ( V_412 == V_416 ) {
V_79 = F_244 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_499 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_500 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 ) {
V_79 = F_217 ( V_2 , 0x23 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x23 , 0 , V_101 ) ;
}
V_11 -> V_273 = 0x03 ;
F_75 ( V_2 , V_220 ) ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 ) {
V_11 -> V_284 = F_207 ;
#ifdef F_219
V_11 -> V_332 = F_144 ;
#endif
}
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_501 ;
#endif
return 0 ;
}
static int F_246 ( struct V_1 * V_2 )
{
static const T_1 V_502 [] = { 0x1d , 0 } ;
static const T_1 V_503 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_209 ( V_2 , V_502 , V_503 ) ;
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_79 , V_412 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
V_412 = F_214 ( V_2 , V_504 ,
V_505 , V_506 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , NULL , V_507 , V_508 ) ;
F_75 ( V_2 , V_216 ) ;
}
if ( V_412 == V_416 ) {
V_79 = F_246 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_509 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_510 [ V_412 ] ) ;
if ( V_2 -> V_121 == 0x10ec0660 ) {
F_25 ( V_11 , V_511 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 ) {
V_79 = F_217 ( V_2 , 0x23 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
F_218 ( V_11 , 0x0b , 0x05 , V_41 ) ;
}
V_11 -> V_273 = 0x02 ;
F_75 ( V_2 , V_220 ) ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_45 ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_512 ;
#endif
return 0 ;
}
static int F_248 ( struct V_1 * V_2 )
{
static const T_1 V_513 [] = { 0x1d , 0 } ;
static const T_1 V_514 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_515 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_471 ;
if ( V_2 -> V_121 == 0x10ec0272 || V_2 -> V_121 == 0x10ec0663 ||
V_2 -> V_121 == 0x10ec0665 || V_2 -> V_121 == 0x10ec0670 )
V_471 = V_514 ;
else
V_471 = V_515 ;
return F_209 ( V_2 , V_513 , V_471 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
const struct V_212 * V_213 , int V_206 )
{
if ( V_206 != V_220 )
return;
if ( F_229 ( V_2 , 0x2 , V_101 ,
( 0x3b << V_463 ) |
( 0x3b << V_464 ) |
( 0x03 << V_465 ) |
( 0 << V_466 ) ) )
F_70 ( V_395
L_68 ) ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_79 , V_412 ;
int V_475 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( ! V_11 )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_358 = 0x0b ;
F_69 ( V_2 ) ;
F_27 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_475 = F_81 ( V_2 , 0 ) ;
if ( V_475 == 0x8020 || V_475 == 0x8011 )
F_149 ( V_2 , L_69 ) ;
else if ( V_475 & ( 1 << 14 ) &&
V_2 -> V_188 -> V_189 -> V_479 == 0x1025 &&
V_11 -> V_181 . V_197 == 1 )
F_149 ( V_2 , L_70 ) ;
else if ( V_475 == 0x4011 )
F_149 ( V_2 , L_71 ) ;
V_412 = F_214 ( V_2 , V_516 ,
V_517 , V_518 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
F_79 ( V_2 , V_519 ,
V_520 , V_521 ) ;
F_75 ( V_2 , V_216 ) ;
V_79 = F_248 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_522 ;
}
#endif
}
if ( V_412 != V_416 )
F_216 ( V_2 , & V_523 [ V_412 ] ) ;
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
if ( ! V_11 -> V_268 && F_208 ( V_2 ) ) {
V_79 = F_217 ( V_2 , 0x1 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
switch ( V_2 -> V_121 ) {
case 0x10ec0662 :
F_218 ( V_11 , 0x0b , 0x05 , V_41 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_218 ( V_11 , 0x0b , 0x04 , V_41 ) ;
break;
case 0x10ec0273 :
F_218 ( V_11 , 0x0b , 0x03 , V_41 ) ;
break;
}
}
V_11 -> V_273 = 0x02 ;
F_75 ( V_2 , V_220 ) ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
V_11 -> V_329 = F_45 ;
F_28 ( V_2 ) ;
#ifdef F_219
if ( ! V_11 -> V_286 . V_420 )
V_11 -> V_286 . V_420 = V_524 ;
#endif
return 0 ;
}
static int F_251 ( struct V_1 * V_2 )
{
if ( ( F_81 ( V_2 , 0 ) & 0x00f0 ) == 0x0030 ) {
F_139 ( V_2 -> V_192 ) ;
if ( V_2 -> V_121 == 0x10ec0887 )
V_2 -> V_192 = F_56 ( L_72 , V_148 ) ;
else
V_2 -> V_192 = F_56 ( L_73 , V_148 ) ;
if ( ! V_2 -> V_192 ) {
F_141 ( V_2 ) ;
return - V_146 ;
}
return F_250 ( V_2 ) ;
}
return F_223 ( V_2 ) ;
}
static int F_252 ( struct V_1 * V_2 )
{
if ( ( F_81 ( V_2 , 0 ) & 0x2000 ) != 0x2000 ) {
F_139 ( V_2 -> V_192 ) ;
V_2 -> V_192 = F_56 ( L_74 , V_148 ) ;
}
return F_223 ( V_2 ) ;
}
static int F_253 ( struct V_1 * V_2 )
{
return F_209 ( V_2 , NULL , NULL ) ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_412 ;
int V_79 ;
V_11 = F_213 ( sizeof( * V_11 ) , V_148 ) ;
if ( V_11 == NULL )
return - V_146 ;
V_2 -> V_11 = V_11 ;
V_412 = F_214 ( V_2 , V_525 ,
V_526 , V_527 ) ;
if ( V_412 < 0 ) {
F_70 ( V_191 L_56 ,
V_2 -> V_192 ) ;
V_412 = V_416 ;
}
if ( V_412 == V_416 ) {
V_79 = F_253 ( V_2 ) ;
if ( V_79 < 0 ) {
F_141 ( V_2 ) ;
return V_79 ;
}
#ifdef F_215
else if ( ! V_79 ) {
F_70 ( V_191
L_57
L_59 ) ;
V_412 = V_528 ;
}
#endif
}
if ( V_412 != V_416 ) {
F_216 ( V_2 , & V_529 [ V_412 ] ) ;
#ifdef F_215
V_11 -> V_306 = & V_530 ;
#endif
}
if ( ! V_11 -> V_268 && ! V_11 -> V_26 ) {
F_158 ( V_2 ) ;
F_63 ( V_2 ) ;
F_200 ( V_2 ) ;
}
if ( ! V_11 -> V_268 && ! V_11 -> V_267 )
F_206 ( V_2 ) ;
V_11 -> V_273 = 0x02 ;
V_2 -> V_333 = V_419 ;
if ( V_412 == V_416 )
V_11 -> V_284 = F_207 ;
return 0 ;
}
static int T_5 F_255 ( void )
{
return F_256 ( & V_531 ) ;
}
static void T_6 F_257 ( void )
{
F_258 ( & V_531 ) ;
}
