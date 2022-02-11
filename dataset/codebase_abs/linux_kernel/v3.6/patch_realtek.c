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
static void F_13 ( struct V_1 * V_2 , bool V_33 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 ;
T_1 V_35 = V_11 -> V_36 . V_37 [ 1 ] . V_35 ;
V_34 = F_14 ( V_2 , V_35 ) ;
if ( V_34 == V_38 ) {
const T_1 V_39 = 0x18 ;
if ( F_15 ( F_2 ( V_2 , V_39 ) ) == V_40 &&
F_16 ( F_17 ( V_2 , V_39 ) ) == V_41 ) {
unsigned int V_42 = F_14 ( V_2 , V_39 ) ;
if ( V_42 != V_38 )
F_18 ( V_2 , V_39 , V_43 | ( V_33 ? V_42 : 0 ) ) ;
}
}
V_34 = V_33 ? V_34 | V_43 : V_44 ;
F_18 ( V_2 , V_35 , V_34 ) ;
V_11 -> V_45 = ! V_33 ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_31 , bool V_46 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_47 * V_48 ;
unsigned int V_12 ;
int V_49 , type , V_50 ;
T_1 V_3 ;
if ( ! V_11 -> V_15 )
return 0 ;
V_12 = V_19 >= V_11 -> V_14 ? 0 : V_19 ;
V_48 = & V_11 -> V_15 [ V_12 ] ;
if ( ! V_48 -> V_16 && V_12 > 0 )
V_48 = & V_11 -> V_15 [ 0 ] ;
if ( ! V_48 -> V_16 )
return 0 ;
if ( V_31 >= V_48 -> V_16 )
V_31 = V_48 -> V_16 - 1 ;
if ( V_11 -> V_23 [ V_19 ] == V_31 && ! V_46 )
return 0 ;
V_11 -> V_23 [ V_19 ] = V_31 ;
if ( V_11 -> V_51 )
F_13 ( V_2 , V_11 -> V_23 [ V_19 ] ) ;
if ( V_11 -> V_52 ) {
F_9 ( V_2 , V_31 ) ;
V_19 = V_11 -> V_27 [ V_31 ] ;
}
V_3 = F_12 ( V_11 , V_19 ) ;
V_50 = F_21 ( V_2 , V_3 ) ;
if ( V_50 <= 1 )
return 1 ;
type = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( type == V_53 ) {
int V_54 = V_48 -> V_55 [ V_31 ] . V_56 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
unsigned int V_57 = ( V_49 == V_54 ) ? 0 : V_58 ;
F_22 ( V_2 , V_3 , V_59 , V_49 ,
V_58 , V_57 ) ;
}
} else {
F_23 ( V_2 , V_3 , 0 ,
V_60 ,
V_48 -> V_55 [ V_31 ] . V_56 ) ;
}
F_24 ( V_2 , true ) ;
return 1 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
return F_20 ( V_2 , V_19 ,
V_18 -> V_20 . V_21 . V_22 [ 0 ] , false ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_3 ,
int V_61 )
{
unsigned int V_34 = V_43 ;
if ( V_61 == V_62 )
V_34 |= F_14 ( V_2 , V_3 ) ;
F_18 ( V_2 , V_3 , V_34 ) ;
}
static void F_27 ( struct V_10 * V_11 , const struct V_63 * V_64 )
{
if ( F_28 ( V_11 -> V_65 >= F_29 ( V_11 -> V_66 ) ) )
return;
V_11 -> V_66 [ V_11 -> V_65 ++ ] = V_64 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 ;
if ( ! V_11 -> V_67 )
return;
F_31 ( V_2 , V_11 -> V_67 , 0 , V_68 ,
V_11 -> V_69 ) ;
V_34 = F_32 ( V_2 , V_11 -> V_67 , 0 ,
V_70 , 0 ) ;
F_31 ( V_2 , V_11 -> V_67 , 0 , V_68 ,
V_11 -> V_69 ) ;
F_31 ( V_2 , V_11 -> V_67 , 0 , V_71 ,
V_34 & ~ ( 1 << V_11 -> V_72 ) ) ;
}
static void F_33 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_73 , unsigned int V_74 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_67 = V_3 ;
V_11 -> V_69 = V_73 ;
V_11 -> V_72 = V_74 ;
F_30 ( V_2 ) ;
}
static bool F_34 ( struct V_1 * V_2 , int V_75 , T_1 * V_76 )
{
int V_49 , V_77 = 0 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_3 = V_76 [ V_49 ] ;
if ( ! V_3 )
break;
V_77 |= F_35 ( V_2 , V_3 ) ;
}
return V_77 ;
}
static void F_36 ( struct V_1 * V_2 , int V_75 , T_1 * V_76 ,
bool V_78 , bool V_79 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_80 = V_78 ? V_58 : 0 ;
unsigned int V_81 = V_78 ? 0 : ( V_79 ? V_44 : V_82 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_3 = V_76 [ V_49 ] ;
unsigned int V_34 ;
if ( ! V_3 )
break;
switch ( V_11 -> V_83 ) {
case V_84 :
if ( V_11 -> V_85 ) {
V_34 = F_32 ( V_2 , V_3 , 0 ,
V_86 , 0 ) ;
V_34 &= ~ V_44 ;
} else
V_34 = 0 ;
V_34 |= V_81 ;
F_18 ( V_2 , V_3 , V_34 ) ;
break;
case V_87 :
F_22 ( V_2 , V_3 , V_88 , 0 ,
V_58 , V_80 ) ;
break;
case V_89 :
V_3 = V_11 -> V_90 [ V_49 ] ;
if ( ! V_3 )
break;
F_22 ( V_2 , V_3 , V_59 , 0 ,
V_58 , V_80 ) ;
F_22 ( V_2 , V_3 , V_59 , 1 ,
V_58 , V_80 ) ;
break;
}
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_91 ;
if ( ! V_11 -> V_51 )
F_36 ( V_2 , F_29 ( V_11 -> V_36 . V_92 ) ,
V_11 -> V_36 . V_92 , V_11 -> V_93 , true ) ;
if ( ! V_11 -> V_45 )
V_91 = 0 ;
else
V_91 = V_11 -> V_94 | V_11 -> V_95 ;
V_91 |= V_11 -> V_93 ;
F_36 ( V_2 , F_29 ( V_11 -> V_36 . V_96 ) ,
V_11 -> V_36 . V_96 , V_91 , false ) ;
if ( V_11 -> V_36 . V_97 [ 0 ] == V_11 -> V_36 . V_92 [ 0 ] ||
V_11 -> V_36 . V_97 [ 0 ] == V_11 -> V_36 . V_96 [ 0 ] )
return;
if ( ! V_11 -> V_98 )
V_91 = 0 ;
else
V_91 = V_11 -> V_94 ;
V_91 |= V_11 -> V_93 ;
F_36 ( V_2 , F_29 ( V_11 -> V_36 . V_97 ) ,
V_11 -> V_36 . V_97 , V_91 , false ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_99 )
V_11 -> V_99 ( V_2 ) ;
else
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_94 =
F_34 ( V_2 , F_29 ( V_11 -> V_36 . V_92 ) ,
V_11 -> V_36 . V_92 ) ;
if ( ! V_11 -> V_100 || ( ! V_11 -> V_45 && ! V_11 -> V_98 ) )
return;
F_19 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_36 . V_97 [ 0 ] == V_11 -> V_36 . V_92 [ 0 ] )
return;
V_11 -> V_95 =
F_34 ( V_2 , F_29 ( V_11 -> V_36 . V_97 ) ,
V_11 -> V_36 . V_97 ) ;
if ( ! V_11 -> V_45 || ! V_11 -> V_101 )
return;
F_19 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_76 = V_11 -> V_102 ;
if ( ! V_11 -> V_103 || ! V_11 -> V_104 )
return;
if ( F_28 ( ! V_11 -> V_26 ) )
return;
if ( F_28 ( V_11 -> V_105 < 0 || V_11 -> V_106 < 0 ) )
return;
if ( F_35 ( V_2 , V_76 [ V_11 -> V_106 ] ) )
F_20 ( V_2 , 0 , V_11 -> V_106 , false ) ;
else if ( V_11 -> V_107 >= 0 &&
F_35 ( V_2 , V_76 [ V_11 -> V_107 ] ) )
F_20 ( V_2 , 0 , V_11 -> V_107 , false ) ;
else
F_20 ( V_2 , 0 , V_11 -> V_105 , false ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_108 )
{
switch ( V_108 ) {
case V_109 :
F_38 ( V_2 ) ;
break;
case V_110 :
F_39 ( V_2 ) ;
break;
case V_111 :
F_40 ( V_2 ) ;
break;
}
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_34 ;
struct V_6 * V_112 ;
struct V_17 * V_113 ;
V_112 = F_44 ( V_2 , L_1 ) ;
if ( ! V_112 )
return;
V_113 = F_45 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 )
return;
V_34 = F_32 ( V_2 , V_3 , 0 ,
V_115 , 0 ) ;
V_34 &= V_116 ;
V_113 -> V_20 . integer . V_20 [ 0 ] = V_34 ;
V_113 -> V_20 . integer . V_20 [ 1 ] = V_34 ;
V_112 -> V_117 ( V_112 , V_113 ) ;
F_46 ( V_113 ) ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_118 )
{
int V_108 ;
if ( V_2 -> V_119 == 0x10ec0880 )
V_118 >>= 28 ;
else
V_118 >>= 26 ;
V_108 = F_48 ( V_2 , V_118 ) ;
if ( V_108 == V_120 ) {
struct V_121 * V_122 ;
V_122 = F_49 ( V_2 , V_118 ) ;
if ( V_122 )
F_43 ( V_2 , V_122 -> V_3 ) ;
return;
}
F_41 ( V_2 , V_108 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 0 ) ;
V_123 = F_32 ( V_2 , 0x20 , 0 , V_70 , 0 ) ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
if ( ( V_123 & 0xf0 ) == 0x20 )
F_32 ( V_2 , 0x20 , 0 ,
V_71 , 0x830 ) ;
else
F_32 ( V_2 , 0x20 , 0 ,
V_71 , 0x3030 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
V_123 = F_32 ( V_2 , 0x20 , 0 , V_70 , 0 ) ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
F_31 ( V_2 , 0x20 , 0 , V_71 , V_123 | 0x2010 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_1 V_3 , int V_91 )
{
if ( F_15 ( F_2 ( V_2 , V_3 ) ) != V_40 )
return;
if ( F_54 ( V_2 , V_3 ) & V_124 )
F_31 ( V_2 , V_3 , 0 , V_125 ,
V_91 ? 2 : 0 ) ;
}
static void F_55 ( struct V_1 * V_2 , bool V_91 )
{
static T_1 V_76 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_126 ;
for ( V_126 = V_76 ; * V_126 ; V_126 ++ )
F_53 ( V_2 , * V_126 , V_91 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_55 ( V_2 , false ) ;
F_57 ( 200 ) ;
}
static void F_58 ( struct V_1 * V_2 , int type )
{
unsigned int V_123 ;
F_55 ( V_2 , true ) ;
switch ( type ) {
case V_127 :
F_59 ( V_2 , V_128 ) ;
break;
case V_129 :
F_59 ( V_2 , V_130 ) ;
break;
case V_131 :
F_59 ( V_2 , V_132 ) ;
break;
case V_133 :
switch ( V_2 -> V_119 ) {
case 0x10ec0260 :
F_31 ( V_2 , 0x1a , 0 ,
V_68 , 7 ) ;
V_123 = F_32 ( V_2 , 0x1a , 0 ,
V_70 , 0 ) ;
F_31 ( V_2 , 0x1a , 0 ,
V_68 , 7 ) ;
F_31 ( V_2 , 0x1a , 0 ,
V_71 ,
V_123 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_52 ( V_2 ) ;
break;
case 0x10ec0888 :
F_51 ( V_2 ) ;
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
static int F_60 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_134 [] = {
L_2 , L_3
} ;
static const char * const V_135 [] = {
L_2 , L_4 , L_5
} ;
const char * const * V_136 ;
V_9 -> type = V_137 ;
V_9 -> V_138 = 1 ;
if ( V_11 -> V_139 && V_11 -> V_140 ) {
V_9 -> V_20 . V_21 . V_55 = 3 ;
V_136 = V_135 ;
} else {
V_9 -> V_20 . V_21 . V_55 = 2 ;
V_136 = V_134 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_55 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_55 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_141 ,
V_136 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 = 0 ;
if ( V_11 -> V_45 )
V_34 ++ ;
if ( V_11 -> V_98 )
V_34 ++ ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_34 ;
return 0 ;
}
static int F_62 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_18 -> V_20 . V_21 . V_22 [ 0 ] ) {
case 0 :
if ( ! V_11 -> V_45 && ! V_11 -> V_98 )
return 0 ;
V_11 -> V_45 = 0 ;
V_11 -> V_98 = 0 ;
break;
case 1 :
if ( V_11 -> V_139 ) {
if ( ! V_11 -> V_98 && V_11 -> V_45 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_98 = 0 ;
} else if ( V_11 -> V_140 ) {
if ( V_11 -> V_98 )
return 0 ;
V_11 -> V_98 = 1 ;
} else
return - V_142 ;
break;
case 2 :
if ( ! V_11 -> V_140 || ! V_11 -> V_139 )
return - V_142 ;
if ( V_11 -> V_45 && V_11 -> V_98 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_98 = 1 ;
break;
default:
return - V_142 ;
}
F_19 ( V_2 ) ;
return 1 ;
}
static struct V_63 * F_63 ( struct V_10 * V_11 )
{
F_64 ( & V_11 -> V_143 , sizeof( struct V_63 ) , 32 ) ;
return F_65 ( & V_11 -> V_143 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_63 * V_144 ;
V_144 = F_63 ( V_11 ) ;
if ( ! V_144 )
return - V_145 ;
* V_144 = V_146 ;
V_144 -> V_141 = F_67 ( L_6 , V_114 ) ;
if ( ! V_144 -> V_141 )
return - V_145 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_77 = 0 ;
int V_49 ;
if ( V_148 -> V_92 [ 0 ] )
V_77 ++ ;
if ( V_148 -> V_97 [ 0 ] )
V_77 ++ ;
if ( V_148 -> V_96 [ 0 ] )
V_77 ++ ;
if ( V_77 < 2 )
return;
if ( ! V_148 -> V_96 [ 0 ] &&
V_148 -> V_149 == V_150 ) {
memcpy ( V_148 -> V_96 , V_148 -> V_97 ,
sizeof( V_148 -> V_96 ) ) ;
V_148 -> V_151 = V_148 -> V_152 ;
}
if ( ! V_148 -> V_92 [ 0 ] &&
V_148 -> V_149 == V_153 ) {
memcpy ( V_148 -> V_92 , V_148 -> V_97 ,
sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_154 = V_148 -> V_152 ;
}
V_11 -> V_83 = V_84 ;
for ( V_49 = 0 ; V_49 < V_148 -> V_154 ; V_49 ++ ) {
T_1 V_3 = V_148 -> V_92 [ V_49 ] ;
if ( ! F_69 ( V_2 , V_3 ) )
continue;
F_70 ( L_7 ,
V_3 ) ;
F_71 ( V_2 , V_3 , V_109 ) ;
V_11 -> V_100 = 1 ;
}
if ( V_148 -> V_149 == V_155 && V_148 -> V_152 ) {
if ( V_148 -> V_151 )
for ( V_49 = 0 ; V_49 < V_148 -> V_152 ; V_49 ++ ) {
T_1 V_3 = V_148 -> V_97 [ V_49 ] ;
if ( ! F_69 ( V_2 , V_3 ) )
continue;
F_70 ( L_8
L_9 , V_3 ) ;
F_71 ( V_2 , V_3 ,
V_110 ) ;
V_11 -> V_101 = 1 ;
}
V_11 -> V_140 = V_11 -> V_100 ;
}
V_11 -> V_139 = V_148 -> V_151 &&
( V_11 -> V_100 || V_11 -> V_101 ) ;
V_11 -> V_98 = V_11 -> V_140 ;
V_11 -> V_45 = V_11 -> V_139 ;
if ( V_11 -> V_139 || V_11 -> V_140 )
F_66 ( V_2 ) ;
}
static int F_72 ( T_1 V_3 , const T_1 * V_156 , int V_157 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_157 ; V_49 ++ )
if ( V_156 [ V_49 ] == V_3 )
return V_49 ;
return - 1 ;
}
static bool F_73 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_47 * V_48 = & V_11 -> V_158 [ 0 ] ;
int V_49 , V_159 , V_31 ;
T_1 V_160 , V_35 ;
if ( V_48 != V_11 -> V_15 )
return false ;
for ( V_159 = 0 ; V_159 < V_11 -> V_161 ; V_159 ++ ) {
V_160 = V_11 -> V_162 [ V_159 ] ;
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
V_35 = V_11 -> V_102 [ V_49 ] ;
if ( ! V_35 )
return false ;
if ( F_74 ( V_2 , V_160 , V_35 ) < 0 )
break;
}
if ( V_49 >= V_48 -> V_16 )
return true ;
}
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
V_35 = V_11 -> V_102 [ V_49 ] ;
for ( V_159 = 0 ; V_159 < V_11 -> V_161 ; V_159 ++ ) {
V_160 = V_11 -> V_162 [ V_159 ] ;
V_31 = F_74 ( V_2 , V_160 , V_35 ) ;
if ( V_31 >= 0 ) {
V_48 -> V_55 [ V_49 ] . V_56 = V_31 ;
V_11 -> V_27 [ V_49 ] = V_159 ;
break;
}
}
}
F_70 ( L_10 ) ;
V_11 -> V_52 = 1 ;
return true ;
}
static bool F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_47 * V_48 ;
if ( ! V_11 -> V_103 )
return false ;
if ( V_11 -> V_104 )
return true ;
if ( ! F_73 ( V_2 ) ) {
V_11 -> V_103 = 0 ;
return false ;
}
V_48 = V_11 -> V_15 ;
V_11 -> V_106 = F_72 ( V_11 -> V_163 ,
V_11 -> V_102 , V_48 -> V_16 ) ;
V_11 -> V_105 = F_72 ( V_11 -> V_164 ,
V_11 -> V_102 , V_48 -> V_16 ) ;
V_11 -> V_107 = F_72 ( V_11 -> V_165 ,
V_11 -> V_102 , V_48 -> V_16 ) ;
if ( V_11 -> V_106 < 0 || V_11 -> V_105 < 0 ) {
V_11 -> V_103 = 0 ;
return false ;
}
F_71 ( V_2 , V_11 -> V_163 , V_111 ) ;
if ( V_11 -> V_165 )
F_71 ( V_2 , V_11 -> V_165 ,
V_111 ) ;
V_11 -> V_104 = 1 ;
V_11 -> V_103 = 1 ;
return true ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
T_1 V_166 , V_167 , V_168 ;
int V_49 ;
if ( V_11 -> V_51 )
return;
V_11 -> V_106 = V_11 -> V_105 = V_11 -> V_107 = - 1 ;
V_166 = V_167 = V_168 = 0 ;
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
T_1 V_3 = V_148 -> V_37 [ V_49 ] . V_35 ;
unsigned int V_170 ;
V_170 = F_17 ( V_2 , V_3 ) ;
switch ( F_77 ( V_170 ) ) {
case V_171 :
if ( V_166 )
return;
if ( V_148 -> V_37 [ V_49 ] . type != V_62 )
return;
V_166 = V_3 ;
break;
case V_172 :
return;
case V_173 :
if ( V_168 )
return;
if ( V_148 -> V_37 [ V_49 ] . type > V_174 )
return;
V_168 = V_3 ;
break;
default:
if ( V_167 )
return;
if ( V_148 -> V_37 [ V_49 ] . type != V_62 )
return;
V_167 = V_3 ;
break;
}
}
if ( ! V_167 && V_168 ) {
V_167 = V_168 ;
V_168 = 0 ;
}
if ( ! V_167 || ! V_166 )
return;
if ( ! F_69 ( V_2 , V_167 ) )
return;
if ( V_168 && ! F_69 ( V_2 , V_168 ) )
return;
V_11 -> V_163 = V_167 ;
V_11 -> V_164 = V_166 ;
V_11 -> V_165 = V_168 ;
V_11 -> V_103 = 1 ;
if ( ! F_75 ( V_2 ) )
return;
F_70 ( L_11 ,
V_167 , V_166 , V_168 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_76 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
const struct V_175 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 == V_177 ) {
V_11 -> V_178 . V_179 = 1 ;
V_11 -> V_178 . V_180 = V_181 ;
}
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned int V_182 , V_123 , V_49 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_178 . V_183 = 1 ;
if ( V_11 -> V_178 . V_179 ) {
V_182 = V_11 -> V_178 . V_180 ;
if ( V_182 == V_181 )
return - 1 ;
goto V_184;
}
V_182 = V_2 -> V_185 & 0xffff ;
if ( V_182 != V_2 -> V_186 -> V_187 -> V_188 && ( V_182 & 1 ) )
goto V_184;
V_3 = 0x1d ;
if ( V_2 -> V_119 == 0x10ec0260 )
V_3 = 0x17 ;
V_182 = F_17 ( V_2 , V_3 ) ;
if ( ! ( V_182 & 1 ) ) {
F_81 ( V_189 L_12 ,
V_2 -> V_190 , V_182 ) ;
return - 1 ;
}
V_123 = 0 ;
for ( V_49 = 1 ; V_49 < 16 ; V_49 ++ ) {
if ( ( V_182 >> V_49 ) & 1 )
V_123 ++ ;
}
if ( ( ( V_182 >> 16 ) & 0xf ) != V_123 )
return - 1 ;
V_11 -> V_178 . V_191 = V_182 >> 30 ;
V_11 -> V_178 . V_183 = ( V_182 & 0x100000 ) >> 20 ;
V_11 -> V_178 . V_192 = ( V_182 >> 16 ) & 0xf ;
V_11 -> V_178 . V_193 = V_182 >> 8 ;
V_184:
V_11 -> V_178 . V_180 = V_182 ;
V_11 -> V_178 . V_194 = ( V_182 & 0x38 ) >> 3 ;
V_11 -> V_178 . V_195 = ( V_182 & 0x4 ) >> 2 ;
V_11 -> V_178 . V_196 = ( V_182 & 0x2 ) >> 1 ;
V_11 -> V_178 . V_197 = V_182 & 0x1 ;
F_82 ( L_13 ,
V_3 , V_11 -> V_178 . V_180 ) ;
F_82 ( L_14 ,
V_11 -> V_178 . V_191 ) ;
F_82 ( L_15 , V_11 -> V_178 . V_183 ) ;
F_82 ( L_16 , V_11 -> V_178 . V_192 ) ;
F_82 ( L_17 , V_11 -> V_178 . V_193 ) ;
F_82 ( L_18 , V_11 -> V_178 . V_194 ) ;
F_82 ( L_19 , V_11 -> V_178 . V_195 ) ;
F_82 ( L_20 , V_11 -> V_178 . V_196 ) ;
F_82 ( L_21 , V_11 -> V_178 . V_197 ) ;
return 0 ;
}
static bool F_83 ( T_1 V_3 , const T_1 * V_156 , int V_157 )
{
return F_72 ( V_3 , V_156 , V_157 ) >= 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_1 V_198 , T_1 V_199 ,
T_1 V_200 , T_1 V_201 )
{
unsigned int V_182 , V_123 , V_49 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_178 . V_179 ) {
V_182 = V_11 -> V_178 . V_180 ;
if ( V_182 == V_181 )
return 0 ;
goto V_184;
}
V_182 = V_2 -> V_185 & 0xffff ;
if ( ( V_182 != V_2 -> V_186 -> V_187 -> V_188 ) && ( V_182 & 1 ) )
goto V_184;
V_3 = 0x1d ;
if ( V_2 -> V_119 == 0x10ec0260 )
V_3 = 0x17 ;
V_182 = F_17 ( V_2 , V_3 ) ;
F_82 ( L_22
L_23 ,
V_182 , V_3 ) ;
if ( ! ( V_182 & 1 ) )
return 0 ;
if ( ( V_182 >> 30 ) != 1 )
return 0 ;
V_123 = 0 ;
for ( V_49 = 1 ; V_49 < 16 ; V_49 ++ ) {
if ( ( V_182 >> V_49 ) & 1 )
V_123 ++ ;
}
if ( ( ( V_182 >> 16 ) & 0xf ) != V_123 )
return 0 ;
V_184:
F_82 ( L_24 ,
V_182 & 0xffff , V_2 -> V_119 ) ;
V_123 = ( V_182 & 0x38 ) >> 3 ;
switch ( V_123 ) {
case 1 :
V_11 -> V_202 = V_127 ;
break;
case 3 :
V_11 -> V_202 = V_129 ;
break;
case 7 :
V_11 -> V_202 = V_131 ;
break;
case 5 :
default:
V_11 -> V_202 = V_133 ;
break;
}
if ( ! ( V_182 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_36 . V_92 [ 0 ] &&
! ( V_11 -> V_36 . V_97 [ 0 ] &&
V_11 -> V_36 . V_149 == V_153 ) ) {
T_1 V_3 ;
V_123 = ( V_182 >> 11 ) & 0x3 ;
if ( V_123 == 0 )
V_3 = V_198 ;
else if ( V_123 == 1 )
V_3 = V_199 ;
else if ( V_123 == 2 )
V_3 = V_200 ;
else if ( V_123 == 3 )
V_3 = V_201 ;
else
return 1 ;
if ( F_83 ( V_3 , V_11 -> V_36 . V_97 ,
V_11 -> V_36 . V_152 ) )
return 1 ;
V_11 -> V_36 . V_92 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_85 ( struct V_1 * V_2 , const T_1 * V_203 )
{
if ( ! F_84 ( V_2 , V_203 [ 0 ] , V_203 [ 1 ] , V_203 [ 2 ] , V_203 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_82 ( L_25
L_26 ) ;
V_11 -> V_202 = V_133 ;
}
}
static int F_86 ( struct V_1 * V_2 ,
unsigned int V_73 )
{
unsigned int V_34 ;
F_31 ( V_2 , 0x20 , 0 , V_68 ,
V_73 ) ;
V_34 = F_32 ( V_2 , 0x20 , 0 ,
V_70 , 0 ) ;
return V_34 ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_73 ,
unsigned int V_204 )
{
F_31 ( V_2 , 0x20 , 0 , V_68 ,
V_73 ) ;
F_31 ( V_2 , 0x20 , 0 , V_71 ,
V_204 ) ;
}
static unsigned int F_88 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_205 )
V_11 -> V_205 = F_86 ( V_2 , 0 ) ;
return V_11 -> V_205 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
T_1 V_35 , V_206 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_207 ; V_49 ++ ) {
V_35 = V_11 -> V_36 . V_208 [ V_49 ] ;
if ( ! V_35 )
continue;
F_18 ( V_2 , V_35 , V_82 ) ;
if ( ! V_49 )
V_206 = V_11 -> V_209 . V_210 ;
else
V_206 = V_11 -> V_211 [ V_49 - 1 ] ;
if ( ! V_206 || ! ( F_2 ( V_2 , V_206 ) & V_212 ) )
continue;
F_31 ( V_2 , V_206 , 0 ,
V_213 ,
V_214 ) ;
}
V_35 = V_11 -> V_36 . V_215 ;
if ( V_35 )
F_18 ( V_2 , V_35 , V_43 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_216 , V_157 ;
T_1 V_217 ;
V_157 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_207 ; V_49 ++ ) {
T_1 V_218 [ 4 ] ;
V_216 = F_91 ( V_2 ,
V_11 -> V_36 . V_208 [ V_49 ] ,
V_218 , F_29 ( V_218 ) ) ;
if ( V_216 <= 0 )
continue;
V_217 = V_218 [ 0 ] ;
if ( ! V_157 ) {
V_11 -> V_209 . V_210 = V_217 ;
V_11 -> V_219 = V_11 -> V_36 . V_219 [ 0 ] ;
} else {
V_11 -> V_209 . V_211 = V_11 -> V_211 ;
if ( V_157 >= F_29 ( V_11 -> V_211 ) - 1 )
break;
V_11 -> V_211 [ V_157 - 1 ] = V_217 ;
}
V_157 ++ ;
}
if ( V_11 -> V_36 . V_215 ) {
V_217 = V_2 -> V_220 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_221 ; V_49 ++ , V_217 ++ ) {
unsigned int V_222 = F_2 ( V_2 , V_217 ) ;
if ( F_15 ( V_222 ) != V_223 )
continue;
if ( ! ( V_222 & V_224 ) )
continue;
if ( ! ( V_222 & V_225 ) )
continue;
V_216 = F_74 ( V_2 , V_217 ,
V_11 -> V_36 . V_215 ) ;
if ( V_216 >= 0 ) {
V_11 -> V_226 = V_217 ;
break;
}
}
}
}
static int F_92 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_34 ;
int V_216 ;
F_93 ( & V_2 -> V_227 ) ;
if ( V_11 -> V_228 )
V_34 = F_94 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_88 ) ;
else
V_34 = F_94 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_59 ) ;
V_7 -> V_229 = V_34 ;
V_216 = F_95 ( V_7 , V_9 ) ;
F_96 ( & V_2 -> V_227 ) ;
return V_216 ;
}
static int F_97 ( struct V_6 * V_7 , int V_230 ,
unsigned int V_231 , unsigned int T_2 * V_232 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_34 ;
int V_216 ;
F_93 ( & V_2 -> V_227 ) ;
if ( V_11 -> V_228 )
V_34 = F_94 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_88 ) ;
else
V_34 = F_94 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_59 ) ;
V_7 -> V_229 = V_34 ;
V_216 = F_98 ( V_7 , V_230 , V_231 , V_232 ) ;
F_96 ( & V_2 -> V_227 ) ;
return V_216 ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_233 , bool V_234 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_216 = 0 ;
F_93 ( & V_2 -> V_227 ) ;
if ( V_234 && V_11 -> V_52 ) {
for ( V_49 = 0 ; V_49 < V_11 -> V_161 ; V_49 ++ ) {
V_7 -> V_229 =
F_94 ( V_11 -> V_26 [ V_49 ] ,
3 , 0 , V_59 ) ;
V_216 = V_233 ( V_7 , V_18 ) ;
if ( V_216 < 0 )
goto error;
}
} else {
V_49 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_228 )
V_7 -> V_229 =
F_94 ( V_11 -> V_32 [ V_49 ] ,
3 , 0 , V_88 ) ;
else
V_7 -> V_229 =
F_94 ( V_11 -> V_26 [ V_49 ] ,
3 , 0 , V_59 ) ;
V_216 = V_233 ( V_7 , V_18 ) ;
}
if ( V_216 >= 0 && V_234 )
F_24 ( V_2 , false ) ;
error:
F_96 ( & V_2 -> V_227 ) ;
return V_216 ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_99 ( V_7 , V_18 ,
V_235 , false ) ;
}
static int F_101 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_99 ( V_7 , V_18 ,
V_236 , true ) ;
}
static int F_102 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_99 ( V_7 , V_18 ,
V_237 , false ) ;
}
static int F_103 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_99 ( V_7 , V_18 ,
V_238 , true ) ;
}
static void F_24 ( struct V_1 * V_2 , bool V_46 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
if ( ! V_11 -> V_239 )
return;
if ( ! V_11 -> V_240 && ! V_46 )
return;
for ( V_49 = 0 ; V_49 < V_11 -> V_161 ; V_49 ++ ) {
int V_241 = V_11 -> V_52 ? 0 : V_49 ;
bool V_242 = false ;
T_1 V_3 ;
int V_243 , V_4 , V_57 ;
if ( V_11 -> V_240 &&
V_11 -> V_102 [ V_11 -> V_23 [ V_241 ] ] == V_11 -> V_244 )
V_242 = true ;
if ( ! V_242 && ! V_46 )
continue;
if ( V_11 -> V_228 ) {
V_3 = V_11 -> V_32 [ V_49 ] ;
V_243 = V_245 | V_246 ;
V_4 = V_88 ;
} else {
V_3 = V_11 -> V_26 [ V_49 ] ;
V_243 = V_245 | V_247 ;
V_4 = V_59 ;
}
V_57 = F_104 ( V_2 , V_3 , 1 , V_4 , 0 ) ;
if ( V_57 & 0x80 )
continue;
if ( V_242 )
V_57 |= 0x80 ;
F_31 ( V_2 , V_3 , 0 , V_213 ,
V_243 | V_57 ) ;
}
}
static int F_105 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . integer . V_20 [ 0 ] = ! V_11 -> V_240 ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 = ! V_18 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_34 == V_11 -> V_240 )
return 0 ;
V_11 -> V_240 = V_34 ;
F_24 ( V_2 , true ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_63 * V_144 = F_63 ( V_11 ) ;
if ( ! V_144 )
return - V_145 ;
* V_144 = V_248 ;
V_144 -> V_141 = F_67 ( L_27 , V_114 ) ;
if ( ! V_144 -> V_141 )
return - V_145 ;
V_11 -> V_239 = 1 ;
V_11 -> V_240 = 0 ;
V_11 -> V_244 = V_3 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 == V_250 )
F_107 ( V_2 , 0x12 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_112 = NULL ;
const struct V_63 * V_144 ;
int V_49 , V_251 , V_216 ;
unsigned int V_252 ;
T_1 V_3 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
V_216 = F_110 ( V_2 , V_11 -> V_66 [ V_49 ] ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( V_11 -> V_253 ) {
V_216 = F_110 ( V_2 , V_11 -> V_253 ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( V_11 -> V_209 . V_210 ) {
V_216 = F_111 ( V_2 ,
V_11 -> V_209 . V_210 ,
V_11 -> V_209 . V_210 ) ;
if ( V_216 < 0 )
return V_216 ;
if ( ! V_11 -> V_254 ) {
V_216 = F_112 ( V_2 ,
& V_11 -> V_209 ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 -> V_209 . V_255 = 1 ;
}
}
if ( V_11 -> V_226 ) {
V_216 = F_113 ( V_2 , V_11 -> V_226 ) ;
if ( V_216 < 0 )
return V_216 ;
}
#ifdef F_114
if ( V_11 -> V_256 ) {
const struct V_63 * V_144 ;
for ( V_144 = V_257 ; V_144 -> V_141 ; V_144 ++ ) {
struct V_6 * V_112 ;
V_112 = F_115 ( V_144 , V_2 ) ;
if ( ! V_112 )
return - V_145 ;
V_112 -> V_229 = V_11 -> V_256 ;
V_216 = F_116 ( V_2 , 0 , V_112 ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
#endif
if ( ! V_11 -> V_254 &&
! F_44 ( V_2 , L_1 ) ) {
unsigned int V_258 [ 4 ] ;
F_117 ( V_2 , V_11 -> V_259 ,
V_88 , V_258 ) ;
V_216 = F_118 ( V_2 , L_1 ,
V_258 , V_260 ,
L_28 ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( ! V_11 -> V_254 &&
! F_44 ( V_2 , L_29 ) ) {
V_216 = F_119 ( V_2 , L_29 ,
NULL , V_260 ,
L_30 ,
true , & V_11 -> V_261 . V_262 ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_112 = F_44 ( V_2 , L_31 ) ;
if ( ! V_112 )
V_112 = F_44 ( V_2 , L_32 ) ;
for ( V_49 = 0 ; V_112 && V_49 < V_112 -> V_138 ; V_49 ++ ) {
V_216 = F_120 ( V_2 , V_112 , V_49 ,
F_12 ( V_11 , V_49 ) ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
if ( V_11 -> V_253 && V_11 -> V_26 ) {
const char * V_263 = V_112 ? V_112 -> V_13 . V_141 : NULL ;
for ( V_144 = V_11 -> V_253 ; V_144 -> V_141 ; V_144 ++ ) {
if ( V_263 && strcmp ( V_144 -> V_141 , V_263 ) == 0 )
continue;
V_112 = F_44 ( V_2 , V_144 -> V_141 ) ;
for ( V_49 = 0 ; V_112 && V_49 < V_112 -> V_138 ; V_49 ++ ) {
V_216 = F_120 ( V_2 , V_112 , V_49 ,
V_11 -> V_26 [ V_49 ] ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
}
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
for ( V_144 = V_11 -> V_66 [ V_49 ] ; V_144 -> V_141 ; V_144 ++ ) {
if ( V_144 -> V_264 != V_265 )
continue;
V_112 = F_44 ( V_2 , V_144 -> V_141 ) ;
if ( V_112 == NULL )
continue;
V_252 = V_144 -> V_266 ;
for ( V_251 = 0 ; V_251 < 4 ; V_251 ++ , V_252 >>= 8 ) {
V_3 = V_252 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_252 & 0xc0 ) {
case V_267 :
V_3 = V_11 -> V_36 . V_96 [ V_3 ] ;
break;
case V_268 :
V_3 = V_11 -> V_36 . V_97 [ V_3 ] ;
break;
case V_269 :
V_3 = V_11 -> V_36 . V_92 [ V_3 ] ;
break;
default:
continue;
}
V_216 = F_120 ( V_2 , V_112 , 0 , V_3 ) ;
if ( V_216 < 0 )
return V_216 ;
}
V_252 = V_144 -> V_229 ;
for ( V_251 = 0 ; V_251 < 4 ; V_251 ++ , V_252 >>= 8 ) {
V_3 = V_252 & 0xff ;
if ( V_3 == 0 )
continue;
V_216 = F_120 ( V_2 , V_112 , 0 , V_3 ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
}
F_121 ( V_2 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_51 ) {
int V_216 ;
int V_3 = V_11 -> V_36 . V_37 [ 1 ] . V_35 ;
V_216 = F_123 ( V_2 , V_3 , L_33 , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_71 ( V_2 , V_3 , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
}
return F_124 ( V_2 , & V_11 -> V_36 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
int V_216 = F_109 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_122 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
F_126 ( V_2 , V_270 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_271 )
V_11 -> V_271 ( V_2 ) ;
F_30 ( V_2 ) ;
F_58 ( V_2 , V_11 -> V_202 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_126 ( V_2 , V_272 ) ;
F_42 ( V_2 ) ;
F_131 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_133 ( V_2 , & V_11 -> V_273 , V_3 ) ;
}
static int F_134 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_135 ( V_2 , & V_11 -> V_209 , V_277 ,
V_275 ) ;
}
static int F_136 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
unsigned int V_278 ,
unsigned int V_279 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_137 ( V_2 , & V_11 -> V_209 ,
V_278 , V_279 , V_277 ) ;
}
static int F_138 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_139 ( V_2 , & V_11 -> V_209 ) ;
}
static int F_140 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_141 ( V_2 , & V_11 -> V_209 ) ;
}
static int F_142 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
unsigned int V_278 ,
unsigned int V_279 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_143 ( V_2 , & V_11 -> V_209 ,
V_278 , V_279 , V_277 ) ;
}
static int F_144 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_145 ( V_2 , & V_11 -> V_209 ) ;
}
static int F_146 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_147 ( V_2 , & V_11 -> V_209 ) ;
}
static int F_148 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
unsigned int V_278 ,
unsigned int V_279 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_277 -> V_280 + 1 ] ,
V_278 , 0 , V_279 ) ;
return 0 ;
}
static int F_149 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_150 ( V_2 ,
V_11 -> V_26 [ V_277 -> V_280 + 1 ] ) ;
return 0 ;
}
static int F_151 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
unsigned int V_278 ,
unsigned int V_279 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_278 ;
V_11 -> V_30 = V_279 ;
F_11 ( V_2 , V_11 -> V_28 , V_278 , 0 , V_279 ) ;
return 0 ;
}
static int F_152 ( struct V_274 * V_275 ,
struct V_1 * V_2 ,
struct V_276 * V_277 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_150 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_281 * V_282 = V_11 -> V_283 ;
const struct V_274 * V_126 ;
bool V_284 ;
int V_49 ;
V_2 -> V_285 = 1 ;
V_2 -> V_286 = V_282 ;
if ( V_11 -> V_254 )
goto V_287;
snprintf ( V_11 -> V_288 , sizeof( V_11 -> V_288 ) ,
L_34 , V_2 -> V_190 ) ;
V_282 -> V_141 = V_11 -> V_288 ;
if ( V_11 -> V_209 . V_289 > 0 ) {
V_126 = V_11 -> V_290 ;
if ( ! V_126 )
V_126 = & V_291 ;
V_282 -> V_292 [ V_293 ] = * V_126 ;
V_282 -> V_292 [ V_293 ] . V_3 = V_11 -> V_209 . V_294 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_126 = V_11 -> V_295 ;
if ( ! V_126 ) {
if ( V_11 -> V_52 )
V_126 = & V_296 ;
else
V_126 = & V_297 ;
}
V_282 -> V_292 [ V_298 ] = * V_126 ;
V_282 -> V_292 [ V_298 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_299 ) {
V_282 -> V_292 [ V_293 ] . V_300 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_301 ; V_49 ++ ) {
if ( V_11 -> V_299 [ V_49 ] . V_302 > V_282 -> V_292 [ V_293 ] . V_300 ) {
V_282 -> V_292 [ V_293 ] . V_300 = V_11 -> V_299 [ V_49 ] . V_302 ;
}
}
}
V_287:
if ( V_11 -> V_209 . V_210 || V_11 -> V_226 ) {
snprintf ( V_11 -> V_303 ,
sizeof( V_11 -> V_303 ) ,
L_35 , V_2 -> V_190 ) ;
V_2 -> V_285 = 2 ;
V_2 -> V_211 = V_11 -> V_209 . V_211 ;
V_282 = V_11 -> V_283 + 1 ;
V_282 -> V_141 = V_11 -> V_303 ;
if ( V_11 -> V_219 )
V_282 -> V_304 = V_11 -> V_219 ;
else
V_282 -> V_304 = V_305 ;
if ( V_11 -> V_209 . V_210 ) {
V_126 = V_11 -> V_306 ;
if ( ! V_126 )
V_126 = & V_307 ;
V_282 -> V_292 [ V_293 ] = * V_126 ;
V_282 -> V_292 [ V_293 ] . V_3 = V_11 -> V_209 . V_210 ;
}
if ( V_11 -> V_226 ) {
V_126 = V_11 -> V_308 ;
if ( ! V_126 )
V_126 = & V_309 ;
V_282 -> V_292 [ V_298 ] = * V_126 ;
V_282 -> V_292 [ V_298 ] . V_3 = V_11 -> V_226 ;
}
V_2 -> V_310 = 1 ;
}
if ( V_11 -> V_254 )
return 0 ;
V_284 = ( V_11 -> V_161 > 1 ) &&
! V_11 -> V_52 && ! V_11 -> V_103 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_311 || V_284 ) {
V_2 -> V_285 = 3 ;
V_282 = V_11 -> V_283 + 2 ;
V_282 -> V_141 = V_11 -> V_288 ;
if ( V_11 -> V_311 ) {
V_126 = V_11 -> V_312 ;
if ( ! V_126 )
V_126 = & V_313 ;
V_282 -> V_292 [ V_293 ] = * V_126 ;
V_282 -> V_292 [ V_293 ] . V_3 =
V_11 -> V_311 ;
} else {
V_282 -> V_292 [ V_293 ] =
V_314 ;
V_282 -> V_292 [ V_293 ] . V_3 = 0 ;
}
if ( V_284 ) {
V_126 = V_11 -> V_315 ;
if ( ! V_126 )
V_126 = & V_316 ;
V_282 -> V_292 [ V_298 ] = * V_126 ;
V_282 -> V_292 [ V_298 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_282 -> V_292 [ V_298 ] . V_317 =
V_11 -> V_161 - 1 ;
} else {
V_282 -> V_292 [ V_298 ] =
V_314 ;
V_282 -> V_292 [ V_298 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_154 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_318 )
V_11 -> V_318 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_143 . V_156 ) {
struct V_63 * V_112 = V_11 -> V_143 . V_156 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_143 . V_319 ; V_49 ++ )
F_46 ( V_112 [ V_49 ] . V_141 ) ;
}
F_156 ( & V_11 -> V_143 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_320 . V_156 ) {
struct V_321 * * V_322 = V_11 -> V_320 . V_156 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_320 . V_319 ; V_49 ++ )
F_46 ( V_322 [ V_49 ] ) ;
}
F_156 ( & V_11 -> V_320 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_154 ( V_2 ) ;
F_121 ( V_2 ) ;
F_157 ( V_2 ) ;
F_159 ( & V_11 -> V_323 ) ;
F_46 ( V_11 ) ;
F_160 ( V_2 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_55 ( V_2 , false ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_154 ( V_2 ) ;
if ( V_11 && V_11 -> V_324 )
V_11 -> V_324 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
F_57 ( 150 ) ;
V_2 -> V_325 . V_326 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
F_24 ( V_2 , true ) ;
F_131 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , const char * V_141 )
{
F_46 ( V_2 -> V_190 ) ;
V_2 -> V_190 = F_67 ( V_141 , V_114 ) ;
if ( ! V_2 -> V_190 ) {
F_158 ( V_2 ) ;
return - V_145 ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 )
{
const struct V_327 * V_126 ;
for ( V_126 = V_328 ; V_126 -> V_119 ; V_126 ++ ) {
if ( V_126 -> V_119 != V_2 -> V_119 )
continue;
if ( ( F_88 ( V_2 ) & V_126 -> V_329 ) == V_126 -> V_330 )
return F_166 ( V_2 , V_126 -> V_141 ) ;
}
return 0 ;
}
static int F_168 ( struct V_10 * V_11 , int type , const char * V_141 ,
int V_331 , unsigned long V_34 )
{
struct V_63 * V_144 ;
V_144 = F_63 ( V_11 ) ;
if ( ! V_144 )
return - V_145 ;
* V_144 = V_332 [ type ] ;
V_144 -> V_141 = F_67 ( V_141 , V_114 ) ;
if ( ! V_144 -> V_141 )
return - V_145 ;
V_144 -> V_56 = V_331 ;
if ( F_169 ( V_34 ) )
V_144 -> V_266 = V_333 ;
V_144 -> V_229 = V_34 ;
return 0 ;
}
static int F_170 ( struct V_10 * V_11 , int type ,
const char * V_334 , const char * V_4 ,
const char * V_335 , int V_331 , unsigned long V_34 )
{
char V_141 [ 32 ] ;
snprintf ( V_141 , sizeof( V_141 ) , L_36 , V_334 , V_4 , V_335 ) ;
return F_168 ( V_11 , type , V_141 , V_331 , V_34 ) ;
}
static const char * F_171 ( struct V_10 * V_11 , int V_336 ,
bool V_337 , int * V_56 )
{
struct V_147 * V_148 = & V_11 -> V_36 ;
* V_56 = 0 ;
if ( V_148 -> V_152 == 1 && ! V_11 -> V_338 &&
! V_148 -> V_154 && ! V_148 -> V_151 && V_337 )
return L_37 ;
switch ( V_148 -> V_149 ) {
case V_150 :
if ( V_148 -> V_152 == 1 )
return L_38 ;
if ( V_148 -> V_152 == 2 )
return V_336 ? L_39 : L_38 ;
break;
case V_153 :
if ( V_336 && V_11 -> V_338 )
break;
* V_56 = V_336 ;
return L_40 ;
default:
if ( V_148 -> V_152 == 1 && ! V_11 -> V_338 )
return L_41 ;
break;
}
if ( F_28 ( V_336 >= F_29 ( V_339 ) ) )
return L_41 ;
return V_339 [ V_336 ] ;
}
static void F_172 ( struct V_10 * V_11 , T_1 V_64 , int V_31 )
{
struct V_340 * V_156 ;
if ( V_11 -> V_341 >= F_29 ( V_11 -> V_342 ) - 1 )
return;
V_156 = V_11 -> V_342 + V_11 -> V_341 ;
V_156 -> V_3 = V_64 ;
V_156 -> V_4 = V_59 ;
V_156 -> V_31 = V_31 ;
V_11 -> V_341 ++ ;
V_11 -> V_273 . V_343 = V_11 -> V_342 ;
}
static int F_173 ( struct V_10 * V_11 , T_1 V_35 ,
const char * V_344 , int V_345 ,
int V_31 , T_1 V_346 )
{
int V_216 ;
V_216 = F_174 ( V_11 , V_347 , V_344 , V_345 ,
F_94 ( V_346 , 3 , V_31 , V_59 ) ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_175 ( V_11 , V_348 , V_344 , V_345 ,
F_94 ( V_346 , 3 , V_31 , V_59 ) ) ;
if ( V_216 < 0 )
return V_216 ;
F_172 ( V_11 , V_346 , V_31 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_349 = F_54 ( V_2 , V_3 ) ;
return ( V_349 & V_350 ) != 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_351 ;
T_1 * V_352 = V_11 -> V_162 ;
int V_353 = F_29 ( V_11 -> V_351 ) ;
int V_49 , V_157 = 0 ;
V_3 = V_2 -> V_220 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_221 ; V_49 ++ , V_3 ++ ) {
T_1 V_241 ;
unsigned int V_354 = F_2 ( V_2 , V_3 ) ;
int type = F_15 ( V_354 ) ;
if ( type != V_223 || ( V_354 & V_224 ) )
continue;
V_26 [ V_157 ] = V_3 ;
V_352 [ V_157 ] = V_3 ;
V_241 = V_3 ;
for (; ; ) {
int V_159 ;
type = F_15 ( F_2 ( V_2 , V_241 ) ) ;
if ( type == V_40 )
break;
if ( type == V_355 ) {
V_352 [ V_157 ] = V_241 ;
break;
}
V_159 = F_21 ( V_2 , V_241 ) ;
if ( V_159 > 1 ) {
V_352 [ V_157 ] = V_241 ;
break;
} else if ( V_159 != 1 )
break;
if ( F_91 ( V_2 , V_241 , & V_241 , 1 ) != 1 )
break;
}
if ( ++ V_157 >= V_353 )
break;
}
V_11 -> V_26 = V_11 -> V_351 ;
V_11 -> V_32 = V_11 -> V_162 ;
V_11 -> V_161 = V_157 ;
return V_157 ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_147 * V_148 = & V_11 -> V_36 ;
T_1 V_356 = V_11 -> V_357 ;
struct V_47 * V_48 = & V_11 -> V_158 [ 0 ] ;
int V_358 ;
int V_49 , V_359 , V_216 , V_31 , V_360 = 0 ;
const char * V_361 = NULL ;
V_358 = F_177 ( V_2 ) ;
if ( V_358 < 0 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
T_1 V_35 ;
const char * V_362 ;
V_35 = V_148 -> V_37 [ V_49 ] . V_35 ;
if ( ! F_176 ( V_2 , V_35 ) )
continue;
V_362 = F_179 ( V_2 , V_148 , V_49 ) ;
if ( V_11 -> V_51 && ! strcmp ( V_362 , L_42 ) )
V_362 = L_33 ;
if ( V_361 && ! strcmp ( V_362 , V_361 ) )
V_360 ++ ;
else
V_360 = 0 ;
V_361 = V_362 ;
if ( V_356 ) {
V_31 = F_74 ( V_2 , V_356 , V_35 ) ;
if ( V_31 >= 0 ) {
V_216 = F_173 ( V_11 , V_35 ,
V_362 , V_360 ,
V_31 , V_356 ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
for ( V_359 = 0 ; V_359 < V_358 ; V_359 ++ ) {
T_1 V_160 = F_12 ( V_11 , V_359 ) ;
V_31 = F_74 ( V_2 , V_160 , V_35 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_102 [ V_48 -> V_16 ] = V_35 ;
F_180 ( V_48 , V_362 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_48 ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
unsigned int V_170 ;
T_1 V_3 ;
if ( V_148 -> V_169 != 1 )
return 0 ;
V_170 = F_17 ( V_2 , V_148 -> V_37 [ 0 ] . V_35 ) ;
if ( F_77 ( V_170 ) != V_171 )
return 0 ;
if ( V_148 -> V_154 == 1 && V_148 -> V_149 == V_150 )
V_3 = V_148 -> V_92 [ 0 ] ;
else if ( V_148 -> V_152 == 1 && V_148 -> V_149 == V_153 )
V_3 = V_148 -> V_97 [ 0 ] ;
else
return 0 ;
if ( ! ( F_54 ( V_2 , V_3 ) & V_350 ) )
return 0 ;
V_148 -> V_37 [ 1 ] . V_35 = V_3 ;
V_148 -> V_37 [ 1 ] . type = V_62 ;
V_148 -> V_169 = 2 ;
V_11 -> V_51 = 1 ;
F_70 ( L_43 , V_3 ) ;
return 0 ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_363 )
{
F_18 ( V_2 , V_3 , V_363 ) ;
if ( F_183 ( V_2 , V_3 , V_88 ) )
F_31 ( V_2 , V_3 , 0 , V_213 ,
V_214 ) ;
}
static int F_184 ( int V_149 )
{
if ( V_149 == V_153 )
return V_44 ;
else
return V_82 ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
T_1 V_3 = V_148 -> V_37 [ V_49 ] . V_35 ;
if ( F_176 ( V_2 , V_3 ) ) {
F_26 ( V_2 , V_3 , V_148 -> V_37 [ V_49 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_212 )
F_31 ( V_2 , V_3 , 0 ,
V_213 ,
V_364 ) ;
}
}
if ( V_11 -> V_357 ) {
int V_157 = F_21 ( V_2 , V_11 -> V_357 ) ;
for ( V_49 = 0 ; V_49 < V_157 ; V_49 ++ )
F_31 ( V_2 , V_11 -> V_357 , 0 ,
V_213 ,
F_186 ( V_49 ) ) ;
}
}
static T_1 F_187 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_156 [ 5 ] ;
int V_49 , V_365 ;
if ( F_15 ( F_2 ( V_2 , V_3 ) ) == V_366 )
return V_3 ;
V_365 = F_91 ( V_2 , V_3 , V_156 , F_29 ( V_156 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_15 ( F_2 ( V_2 , V_156 [ V_49 ] ) ) == V_366 )
return V_156 [ V_49 ] ;
}
return 0 ;
}
static T_1 F_188 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_367 [ 5 ] ;
int V_365 = F_91 ( V_2 , V_35 , V_367 ,
F_29 ( V_367 ) ) ;
if ( V_365 != 1 ||
F_15 ( F_2 ( V_2 , V_367 [ 0 ] ) ) != V_355 )
return V_35 ;
return V_367 [ 0 ] ;
}
static T_1 F_189 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_206 )
{
T_1 V_64 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_91 ( V_2 , V_35 , V_64 , F_29 ( V_64 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_64 [ V_49 ] ) == V_206 )
return V_64 [ V_49 ] ;
}
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_206 )
{
T_1 V_64 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_91 ( V_2 , V_35 , V_64 , F_29 ( V_64 ) ) ;
if ( V_365 < 2 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_64 [ V_49 ] ) == V_206 ) {
F_191 ( V_2 , V_35 , 0 ,
V_60 , V_49 ) ;
return 0 ;
}
}
return 0 ;
}
static bool F_192 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
if ( F_83 ( V_3 , V_11 -> V_209 . V_294 ,
F_29 ( V_11 -> V_368 ) ) ||
F_83 ( V_3 , V_11 -> V_209 . V_369 ,
F_29 ( V_11 -> V_209 . V_369 ) ) ||
F_83 ( V_3 , V_11 -> V_209 . V_370 ,
F_29 ( V_11 -> V_209 . V_370 ) ) )
return true ;
for ( V_49 = 0 ; V_49 < V_11 -> V_338 ; V_49 ++ ) {
if ( V_11 -> V_371 [ V_49 ] . V_206 == V_3 )
return true ;
}
return false ;
}
static T_1 F_193 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_367 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_91 ( V_2 , V_35 , V_367 , F_29 ( V_367 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
T_1 V_3 = F_187 ( V_2 , V_367 [ V_49 ] ) ;
if ( ! V_3 )
continue;
if ( ! F_192 ( V_2 , V_3 ) )
return V_3 ;
}
return 0 ;
}
static bool F_194 ( struct V_1 * V_2 ,
T_1 V_35 , T_1 V_206 )
{
T_1 V_367 [ 5 ] ;
int V_49 , V_365 ;
if ( ! V_35 || ! V_206 )
return false ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_91 ( V_2 , V_35 , V_367 , F_29 ( V_367 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
T_1 V_3 = F_187 ( V_2 , V_367 [ V_49 ] ) ;
if ( V_3 == V_206 )
return true ;
}
return false ;
}
static T_1 F_195 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_372 = F_188 ( V_2 , V_35 ) ;
T_1 V_3 , V_373 , V_367 [ 5 ] ;
int V_49 , V_365 = F_91 ( V_2 , V_372 , V_367 ,
F_29 ( V_367 ) ) ;
if ( V_365 == 1 )
return F_193 ( V_2 , V_35 ) ;
V_373 = 0 ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( V_367 [ V_49 ] == V_11 -> V_357 )
continue;
V_3 = F_187 ( V_2 , V_367 [ V_49 ] ) ;
if ( V_3 && ! F_192 ( V_2 , V_3 ) ) {
if ( V_373 )
return 0 ;
V_373 = V_3 ;
}
}
return V_373 ;
}
static inline unsigned int F_196 ( unsigned int V_374 )
{
T_1 V_3 = F_169 ( V_374 ) ;
unsigned int V_4 ;
if ( F_28 ( V_3 >= V_375 ) )
return 0 ;
V_4 = F_197 ( V_374 ) ;
return ( V_3 << 1 ) | V_4 ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
memset ( V_11 -> V_376 , 0 , sizeof( V_11 -> V_376 ) ) ;
memset ( V_11 -> V_377 , 0 , sizeof( V_11 -> V_377 ) ) ;
}
static int F_199 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_206 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
unsigned int V_34 ;
int V_378 = 0 ;
V_3 = F_200 ( V_2 , V_35 , V_206 ) ;
if ( V_3 ) {
V_34 = F_94 ( V_3 , 3 , 0 , V_88 ) ;
if ( F_201 ( V_11 -> V_376 , V_3 ) )
V_378 += V_379 ;
else
F_202 ( V_11 -> V_376 , V_34 ) ;
} else
V_378 += V_379 ;
V_3 = F_203 ( V_2 , V_35 , V_206 ) ;
if ( V_3 ) {
unsigned int V_380 = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_380 == V_40 || V_380 == V_366 )
V_34 = F_94 ( V_3 , 3 , 0 , V_88 ) ;
else
V_34 = F_94 ( V_3 , 3 , 0 , V_59 ) ;
if ( F_201 ( V_11 -> V_377 , V_34 ) )
V_378 += V_379 ;
else
F_202 ( V_11 -> V_377 , V_34 ) ;
} else
V_378 += V_379 ;
return V_378 ;
}
static int F_204 ( struct V_1 * V_2 , int V_381 ,
const T_1 * V_76 , T_1 * V_382 ,
const struct V_383 * V_384 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_49 , V_251 ;
int V_378 = 0 ;
T_1 V_206 ;
if ( ! V_381 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_381 ; V_49 ++ ) {
T_1 V_35 = V_76 [ V_49 ] ;
if ( ! V_382 [ V_49 ] )
V_382 [ V_49 ] = F_193 ( V_2 , V_35 ) ;
if ( ! V_382 [ V_49 ] && ! V_49 ) {
for ( V_251 = 1 ; V_251 < V_381 ; V_251 ++ ) {
if ( F_194 ( V_2 , V_35 , V_382 [ V_251 ] ) ) {
V_382 [ 0 ] = V_382 [ V_251 ] ;
V_382 [ V_251 ] = 0 ;
break;
}
}
}
V_206 = V_382 [ V_49 ] ;
if ( ! V_206 ) {
if ( F_194 ( V_2 , V_35 , V_382 [ 0 ] ) )
V_206 = V_382 [ 0 ] ;
else if ( V_148 -> V_152 > V_49 &&
F_194 ( V_2 , V_35 ,
V_11 -> V_368 [ V_49 ] ) )
V_206 = V_11 -> V_368 [ V_49 ] ;
if ( V_206 ) {
if ( ! V_49 )
V_378 += V_384 -> V_385 ;
else if ( V_49 == 1 )
V_378 += V_384 -> V_386 ;
else
V_378 += V_384 -> V_387 ;
} else if ( F_194 ( V_2 , V_35 ,
V_11 -> V_368 [ 0 ] ) ) {
V_206 = V_11 -> V_368 [ 0 ] ;
V_378 += V_384 -> V_388 ;
} else if ( ! V_49 )
V_378 += V_384 -> V_389 ;
else
V_378 += V_384 -> V_390 ;
}
if ( V_206 )
V_378 += F_199 ( V_2 , V_35 , V_206 ) ;
}
return V_378 ;
}
static bool F_205 ( struct V_1 * V_2 , int V_391 ,
const T_1 * V_76 , T_1 * V_382 )
{
int V_49 ;
bool V_392 = false ;
for ( V_49 = 0 ; V_49 < V_391 ; V_49 ++ ) {
if ( V_382 [ V_49 ] )
continue;
V_382 [ V_49 ] = F_195 ( V_2 , V_76 [ V_49 ] ) ;
if ( V_382 [ V_49 ] )
V_392 = true ;
}
return V_392 ;
}
static int F_206 ( struct V_1 * V_2 ,
bool V_393 ,
bool V_394 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_49 , V_216 , V_378 ;
V_11 -> V_209 . V_289 = V_148 -> V_152 ;
V_11 -> V_209 . V_294 = V_11 -> V_368 ;
memset ( V_11 -> V_368 , 0 , sizeof( V_11 -> V_368 ) ) ;
memset ( V_11 -> V_209 . V_369 , 0 , sizeof( V_11 -> V_209 . V_369 ) ) ;
memset ( V_11 -> V_209 . V_370 , 0 , sizeof( V_11 -> V_209 . V_370 ) ) ;
V_11 -> V_338 = 0 ;
F_198 ( V_2 ) ;
V_378 = 0 ;
if ( V_393 ) {
bool V_395 ;
do {
V_395 = F_205 ( V_2 , V_148 -> V_152 ,
V_148 -> V_97 ,
V_11 -> V_368 ) ;
V_395 |= F_205 ( V_2 , V_148 -> V_154 ,
V_148 -> V_92 ,
V_11 -> V_209 . V_369 ) ;
V_395 |= F_205 ( V_2 , V_148 -> V_151 ,
V_148 -> V_96 ,
V_11 -> V_209 . V_370 ) ;
if ( V_394 && V_148 -> V_152 == 1 &&
V_148 -> V_149 != V_150 ) {
V_216 = F_207 ( V_2 , V_148 -> V_97 [ 0 ] , true , 0 ) ;
if ( ! V_216 )
V_395 = true ;
}
} while ( V_395 );
}
V_378 += F_204 ( V_2 , V_148 -> V_152 , V_148 -> V_97 ,
V_11 -> V_368 ,
& V_396 ) ;
V_11 -> V_209 . V_289 = 0 ;
for ( V_49 = 0 ; V_49 < V_148 -> V_152 ; V_49 ++ ) {
if ( V_11 -> V_368 [ V_49 ] )
V_11 -> V_209 . V_289 ++ ;
else {
memmove ( V_11 -> V_368 + V_49 ,
V_11 -> V_368 + V_49 + 1 ,
sizeof( T_1 ) * ( V_148 -> V_152 - V_49 - 1 ) ) ;
V_11 -> V_368 [ V_148 -> V_152 - 1 ] = 0 ;
}
}
if ( V_394 &&
V_148 -> V_152 == 1 && V_148 -> V_149 != V_150 ) {
V_216 = F_207 ( V_2 , V_148 -> V_97 [ 0 ] , false , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( V_148 -> V_149 != V_153 ) {
V_216 = F_204 ( V_2 , V_148 -> V_154 , V_148 -> V_92 ,
V_11 -> V_209 . V_369 ,
& V_397 ) ;
if ( V_216 < 0 )
return V_216 ;
V_378 += V_216 ;
}
if ( V_148 -> V_149 != V_150 ) {
V_216 = F_204 ( V_2 , V_148 -> V_151 ,
V_148 -> V_96 ,
V_11 -> V_209 . V_370 ,
& V_397 ) ;
if ( V_216 < 0 )
return V_216 ;
V_378 += V_216 ;
}
if ( V_148 -> V_152 == 1 && V_148 -> V_149 != V_150 ) {
V_216 = F_207 ( V_2 , V_148 -> V_97 [ 0 ] , false , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
V_378 += V_216 ;
}
if ( V_148 -> V_154 && V_148 -> V_149 == V_150 ) {
int V_398 = 0 ;
if ( V_148 -> V_152 >= 3 )
V_398 = 1 ;
V_216 = F_207 ( V_2 , V_148 -> V_92 [ 0 ] , false ,
V_398 ) ;
if ( V_216 < 0 )
return V_216 ;
V_378 += V_216 ;
}
if ( V_11 -> V_338 == 2 ) {
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ )
V_11 -> V_368 [ V_11 -> V_209 . V_289 ++ ] =
V_11 -> V_371 [ V_49 ] . V_206 ;
V_11 -> V_399 = 2 ;
} else if ( V_11 -> V_338 ) {
V_11 -> V_338 = 0 ;
V_378 += V_400 ;
}
return V_378 ;
}
static void F_208 ( struct V_10 * V_11 , struct V_147 * V_148 )
{
F_209 ( L_44 ,
V_148 -> V_97 [ 0 ] , V_148 -> V_97 [ 1 ] ,
V_148 -> V_97 [ 2 ] , V_148 -> V_97 [ 2 ] ,
V_11 -> V_209 . V_294 [ 0 ] ,
V_11 -> V_209 . V_294 [ 1 ] ,
V_11 -> V_209 . V_294 [ 2 ] ,
V_11 -> V_209 . V_294 [ 3 ] ) ;
if ( V_11 -> V_338 > 0 )
F_209 ( L_45 ,
V_11 -> V_338 ,
V_11 -> V_371 [ 0 ] . V_35 , V_11 -> V_371 [ 1 ] . V_35 ,
V_11 -> V_371 [ 0 ] . V_206 , V_11 -> V_371 [ 1 ] . V_206 ) ;
F_209 ( L_46 ,
V_148 -> V_92 [ 0 ] , V_148 -> V_92 [ 1 ] ,
V_148 -> V_92 [ 2 ] , V_148 -> V_92 [ 2 ] ,
V_11 -> V_209 . V_369 [ 0 ] ,
V_11 -> V_209 . V_369 [ 1 ] ,
V_11 -> V_209 . V_369 [ 2 ] ,
V_11 -> V_209 . V_369 [ 3 ] ) ;
F_209 ( L_47 ,
V_148 -> V_96 [ 0 ] , V_148 -> V_96 [ 1 ] ,
V_148 -> V_96 [ 2 ] , V_148 -> V_96 [ 3 ] ,
V_11 -> V_209 . V_370 [ 0 ] ,
V_11 -> V_209 . V_370 [ 1 ] ,
V_11 -> V_209 . V_370 [ 2 ] ,
V_11 -> V_209 . V_370 [ 3 ] ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
struct V_147 * V_401 ;
int V_402 = V_403 ;
int V_378 ;
bool V_393 = true , V_394 = true ;
bool V_404 = true , V_405 = true ;
bool V_406 = false ;
V_401 = F_211 ( sizeof( * V_401 ) , V_114 ) ;
if ( ! V_401 )
return - V_145 ;
* V_401 = * V_148 ;
for (; ; ) {
V_378 = F_206 ( V_2 , V_393 ,
V_394 ) ;
if ( V_378 < 0 ) {
F_46 ( V_401 ) ;
return V_378 ;
}
F_209 ( L_48 ,
V_148 -> V_149 , V_393 , V_394 ,
V_378 ) ;
F_208 ( V_11 , V_148 ) ;
if ( V_378 < V_402 ) {
V_402 = V_378 ;
* V_401 = * V_148 ;
V_404 = V_393 ;
V_405 = V_394 ;
}
if ( ! V_378 )
break;
V_394 = ! V_394 ;
if ( ! V_394 )
continue;
V_393 = ! V_393 ;
if ( ! V_393 )
continue;
if ( V_406 )
break;
V_406 = true ;
if ( V_148 -> V_151 > 0 &&
V_148 -> V_149 == V_153 ) {
V_148 -> V_154 = V_148 -> V_152 ;
memcpy ( V_148 -> V_92 , V_148 -> V_97 ,
sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_152 = V_148 -> V_151 ;
memcpy ( V_148 -> V_97 , V_148 -> V_96 ,
sizeof( V_148 -> V_96 ) ) ;
V_148 -> V_151 = 0 ;
memset ( V_148 -> V_96 , 0 , sizeof( V_148 -> V_96 ) ) ;
V_148 -> V_149 = V_150 ;
V_393 = true ;
continue;
}
if ( V_148 -> V_154 > 0 &&
V_148 -> V_149 == V_150 ) {
V_148 -> V_151 = V_148 -> V_152 ;
memcpy ( V_148 -> V_96 , V_148 -> V_97 ,
sizeof( V_148 -> V_96 ) ) ;
V_148 -> V_152 = V_148 -> V_154 ;
memcpy ( V_148 -> V_97 , V_148 -> V_92 ,
sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_154 = 0 ;
memset ( V_148 -> V_92 , 0 , sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_149 = V_153 ;
V_393 = true ;
continue;
}
break;
}
if ( V_378 ) {
* V_148 = * V_401 ;
F_206 ( V_2 , V_404 , V_405 ) ;
}
F_209 ( L_49 ,
V_148 -> V_149 , V_404 , V_405 ) ;
F_208 ( V_11 , V_148 ) ;
if ( V_148 -> V_97 [ 0 ] )
V_11 -> V_259 =
F_200 ( V_2 , V_148 -> V_97 [ 0 ] ,
V_11 -> V_209 . V_294 [ 0 ] ) ;
F_198 ( V_2 ) ;
F_46 ( V_401 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 ,
const char * V_334 , int V_331 ,
T_1 V_3 , unsigned int V_407 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 ;
if ( ! V_3 )
return 0 ;
V_34 = F_94 ( V_3 , V_407 , 0 , V_88 ) ;
if ( F_201 ( V_11 -> V_376 , V_34 ) && V_407 != 2 )
return 0 ;
F_202 ( V_11 -> V_376 , V_34 ) ;
return F_174 ( V_2 -> V_11 , V_347 , V_334 , V_331 ,
V_34 ) ;
}
static int F_213 ( struct V_1 * V_2 ,
const char * V_334 , int V_331 ,
T_1 V_3 )
{
int V_407 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_408 )
V_407 = 3 ;
return F_212 ( V_2 , V_334 , V_331 , V_3 , V_407 ) ;
}
static int F_214 ( struct V_1 * V_2 ,
const char * V_334 , int V_331 ,
T_1 V_3 , unsigned int V_407 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_380 ;
int type ;
unsigned long V_34 ;
if ( ! V_3 )
return 0 ;
V_380 = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_380 == V_40 || V_380 == V_366 ) {
type = V_348 ;
V_34 = F_94 ( V_3 , V_407 , 0 , V_88 ) ;
} else if ( F_21 ( V_2 , V_3 ) == 1 ) {
type = V_348 ;
V_34 = F_94 ( V_3 , V_407 , 0 , V_59 ) ;
} else {
type = V_409 ;
V_34 = F_94 ( V_3 , V_407 , 2 , V_59 ) ;
}
if ( F_201 ( V_11 -> V_377 , V_34 ) && V_407 != 2 )
return 0 ;
F_202 ( V_11 -> V_377 , V_34 ) ;
return F_175 ( V_2 -> V_11 , type , V_334 , V_331 , V_34 ) ;
}
static int F_215 ( struct V_1 * V_2 , const char * V_334 ,
int V_331 , T_1 V_3 )
{
int V_407 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_408 )
V_407 = 3 ;
return F_214 ( V_2 , V_334 , V_331 , V_3 , V_407 ) ;
}
static T_1 F_203 ( struct V_1 * V_2 ,
T_1 V_35 , T_1 V_206 )
{
T_1 V_64 = F_189 ( V_2 , V_35 , V_206 ) ;
if ( F_183 ( V_2 , V_35 , V_88 ) )
return V_35 ;
else if ( V_64 && F_183 ( V_2 , V_64 , V_59 ) )
return V_64 ;
else if ( F_183 ( V_2 , V_206 , V_88 ) )
return V_206 ;
return 0 ;
}
static T_1 F_200 ( struct V_1 * V_2 ,
T_1 V_35 , T_1 V_206 )
{
T_1 V_64 = F_189 ( V_2 , V_35 , V_206 ) ;
if ( F_216 ( V_2 , V_206 , V_88 ) )
return V_206 ;
else if ( F_216 ( V_2 , V_64 , V_88 ) )
return V_64 ;
else if ( F_216 ( V_2 , V_35 , V_88 ) )
return V_35 ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 ,
const struct V_147 * V_148 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_216 , V_410 ;
V_410 = V_148 -> V_152 ;
if ( V_11 -> V_338 > 0 && V_148 -> V_152 < 3 )
V_410 += V_11 -> V_338 ;
for ( V_49 = 0 ; V_49 < V_410 ; V_49 ++ ) {
const char * V_141 ;
int V_56 ;
T_1 V_206 , V_35 ;
T_1 V_411 , V_412 ;
V_206 = V_11 -> V_209 . V_294 [ V_49 ] ;
if ( ! V_206 )
continue;
if ( V_49 >= V_148 -> V_152 ) {
V_35 = V_11 -> V_371 [ V_49 - 1 ] . V_35 ;
V_56 = 0 ;
V_141 = V_339 [ V_49 ] ;
} else {
V_35 = V_148 -> V_97 [ V_49 ] ;
V_141 = F_171 ( V_11 , V_49 , true , & V_56 ) ;
}
V_411 = F_203 ( V_2 , V_35 , V_206 ) ;
V_412 = F_200 ( V_2 , V_35 , V_206 ) ;
if ( ! V_141 || ! strcmp ( V_141 , L_50 ) ) {
V_216 = F_212 ( V_2 , L_51 , 0 , V_412 , 1 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_212 ( V_2 , L_52 , 0 , V_412 , 2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_214 ( V_2 , L_51 , 0 , V_411 , 1 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_214 ( V_2 , L_52 , 0 , V_411 , 2 ) ;
if ( V_216 < 0 )
return V_216 ;
} else {
V_216 = F_213 ( V_2 , V_141 , V_56 , V_412 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_215 ( V_2 , V_141 , V_56 , V_411 ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_206 , const char * V_334 ,
int V_331 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_411 , V_412 ;
int V_216 ;
if ( ! V_206 ) {
unsigned int V_34 ;
if ( ! ( F_2 ( V_2 , V_35 ) & V_212 ) )
return 0 ;
V_34 = F_94 ( V_35 , 3 , 0 , V_88 ) ;
if ( F_201 ( V_11 -> V_377 , V_34 ) )
return 0 ;
F_202 ( V_11 -> V_377 , V_34 ) ;
return F_175 ( V_11 , V_348 , V_334 , V_331 , V_34 ) ;
}
V_411 = F_203 ( V_2 , V_35 , V_206 ) ;
V_412 = F_200 ( V_2 , V_35 , V_206 ) ;
V_216 = F_213 ( V_2 , V_334 , V_331 , V_412 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_215 ( V_2 , V_334 , V_331 , V_411 ) ;
if ( V_216 < 0 )
return V_216 ;
return 0 ;
}
static struct V_321 * F_219 ( struct V_1 * V_2 ,
unsigned int V_157 ,
struct V_413 * V_414 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_321 * * V_415 , * V_322 ;
F_64 ( & V_11 -> V_320 , sizeof( V_322 ) , 8 ) ;
V_415 = F_65 ( & V_11 -> V_320 ) ;
if ( ! V_415 )
return NULL ;
V_322 = F_45 ( sizeof( * V_322 ) + sizeof( long ) * ( V_157 + 1 ) , V_114 ) ;
* V_415 = V_322 ;
if ( V_322 )
V_322 -> V_414 = V_414 ;
return V_322 ;
}
static int F_220 ( struct V_1 * V_2 , int V_75 ,
const T_1 * V_76 ,
const T_1 * V_382 ,
const char * V_334 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_321 * V_322 ;
char V_141 [ 32 ] ;
int V_49 , V_159 , V_216 ;
if ( ! V_75 || ! V_76 [ 0 ] )
return 0 ;
if ( V_75 == 1 ) {
T_1 V_206 = * V_382 ;
if ( ! V_206 )
V_206 = V_11 -> V_209 . V_294 [ 0 ] ;
return F_218 ( V_2 , * V_76 , V_206 , V_334 , 0 ) ;
}
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_206 ;
if ( V_382 [ V_75 - 1 ] )
V_206 = V_382 [ V_49 ] ;
else
V_206 = 0 ;
if ( V_75 == 2 && V_49 == 1 && ! strcmp ( V_334 , L_38 ) ) {
V_216 = F_218 ( V_2 , V_76 [ V_49 ] , V_206 ,
L_39 , 0 ) ;
} else if ( V_75 >= 3 ) {
snprintf ( V_141 , sizeof( V_141 ) , L_53 ,
V_334 , V_339 [ V_49 ] ) ;
V_216 = F_218 ( V_2 , V_76 [ V_49 ] , V_206 ,
V_141 , 0 ) ;
} else {
V_216 = F_218 ( V_2 , V_76 [ V_49 ] , V_206 ,
V_334 , V_49 ) ;
}
if ( V_216 < 0 )
return V_216 ;
}
if ( V_382 [ V_75 - 1 ] )
return 0 ;
V_322 = F_219 ( V_2 , V_75 , & V_416 ) ;
if ( ! V_322 )
return - V_145 ;
V_159 = 0 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_412 ;
if ( ! V_76 [ V_49 ] || ! V_382 [ V_49 ] )
continue;
V_412 = F_200 ( V_2 , V_76 [ V_49 ] , V_382 [ V_49 ] ) ;
if ( V_412 )
V_322 -> V_417 [ V_159 ++ ] =
F_94 ( V_412 , 3 , 0 , V_88 ) ;
}
if ( V_159 ) {
snprintf ( V_141 , sizeof( V_141 ) , L_54 , V_334 ) ;
V_216 = F_168 ( V_11 , V_418 , V_141 , 0 , ( long ) V_322 ) ;
if ( V_216 < 0 )
return V_216 ;
}
return 0 ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_220 ( V_2 , V_11 -> V_36 . V_154 ,
V_11 -> V_36 . V_92 ,
V_11 -> V_209 . V_369 ,
L_40 ) ;
}
static int F_222 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_220 ( V_2 , V_11 -> V_36 . V_151 ,
V_11 -> V_36 . V_96 ,
V_11 -> V_209 . V_370 ,
L_38 ) ;
}
static void F_223 ( struct V_1 * V_2 ,
T_1 V_35 , int V_363 ,
T_1 V_206 )
{
int V_49 , V_365 ;
T_1 V_3 , V_64 = 0 ;
T_1 V_367 [ V_419 ] ;
F_182 ( V_2 , V_35 , V_363 ) ;
V_3 = F_188 ( V_2 , V_35 ) ;
V_365 = F_91 ( V_2 , V_3 , V_367 , F_29 ( V_367 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_367 [ V_49 ] ) != V_206 )
continue;
V_64 = V_367 [ V_49 ] ;
break;
}
if ( ! V_64 )
return;
if ( V_365 > 1 )
F_31 ( V_2 , V_3 , 0 , V_60 , V_49 ) ;
if ( F_183 ( V_2 , V_64 , V_59 ) ) {
F_31 ( V_2 , V_64 , 0 , V_213 ,
F_224 ( 0 ) ) ;
F_31 ( V_2 , V_64 , 0 , V_213 ,
F_224 ( 1 ) ) ;
}
V_3 = F_200 ( V_2 , V_35 , V_206 ) ;
if ( V_3 )
F_31 ( V_2 , V_3 , 0 , V_213 ,
V_420 ) ;
V_3 = F_203 ( V_2 , V_35 , V_206 ) ;
if ( V_3 == V_64 && F_183 ( V_2 , V_206 , V_88 ) )
F_31 ( V_2 , V_206 , 0 , V_213 ,
V_420 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_363 = F_184 ( V_11 -> V_36 . V_149 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 <= V_421 ; V_49 ++ ) {
T_1 V_3 = V_11 -> V_36 . V_97 [ V_49 ] ;
if ( V_3 )
F_223 ( V_2 , V_3 , V_363 ,
V_11 -> V_209 . V_294 [ V_49 ] ) ;
}
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
T_1 V_35 , V_206 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_154 ; V_49 ++ ) {
if ( V_11 -> V_36 . V_149 == V_153 )
break;
V_35 = V_11 -> V_36 . V_92 [ V_49 ] ;
if ( ! V_35 )
break;
V_206 = V_11 -> V_209 . V_369 [ V_49 ] ;
if ( ! V_206 ) {
if ( V_49 > 0 && V_11 -> V_209 . V_369 [ 0 ] )
V_206 = V_11 -> V_209 . V_369 [ 0 ] ;
else
V_206 = V_11 -> V_209 . V_294 [ 0 ] ;
}
F_223 ( V_2 , V_35 , V_44 , V_206 ) ;
}
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_151 ; V_49 ++ ) {
if ( V_11 -> V_36 . V_149 == V_150 )
break;
V_35 = V_11 -> V_36 . V_96 [ V_49 ] ;
if ( ! V_35 )
break;
V_206 = V_11 -> V_209 . V_370 [ V_49 ] ;
if ( ! V_206 ) {
if ( V_49 > 0 && V_11 -> V_209 . V_370 [ 0 ] )
V_206 = V_11 -> V_209 . V_370 [ 0 ] ;
else
V_206 = V_11 -> V_209 . V_294 [ 0 ] ;
}
F_223 ( V_2 , V_35 , V_82 , V_206 ) ;
}
}
static bool F_227 ( struct V_1 * V_2 ,
unsigned int V_422 , T_1 V_3 )
{
unsigned int V_170 , V_354 ;
V_170 = F_17 ( V_2 , V_3 ) ;
if ( F_16 ( V_170 ) != V_423 )
return false ;
if ( V_422 && F_228 ( V_170 ) != V_422 )
return false ;
V_354 = F_54 ( V_2 , V_3 ) ;
if ( ! ( V_354 & V_424 ) )
return false ;
return true ;
}
static int F_207 ( struct V_1 * V_2 ,
T_1 V_425 ,
bool V_426 , int V_398 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int type , V_49 , V_251 , V_382 , V_75 , V_427 ;
unsigned int V_170 = F_17 ( V_2 , V_425 ) ;
unsigned int V_422 = F_228 ( V_170 ) ;
int V_378 = 0 ;
V_427 = V_11 -> V_338 ;
if ( V_427 >= 2 )
goto V_428;
V_75 = 0 ;
for ( type = V_174 ; type >= V_62 ; type -- ) {
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
if ( V_148 -> V_37 [ V_49 ] . type != type )
continue;
if ( F_227 ( V_2 , V_422 ,
V_148 -> V_37 [ V_49 ] . V_35 ) )
V_75 ++ ;
}
}
if ( V_75 < 2 )
goto V_428;
V_382 = V_11 -> V_209 . V_289 ;
for ( type = V_174 ; type >= V_62 ; type -- ) {
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
T_1 V_3 = V_148 -> V_37 [ V_49 ] . V_35 ;
T_1 V_206 = 0 ;
if ( V_148 -> V_37 [ V_49 ] . type != type )
continue;
if ( ! F_227 ( V_2 , V_422 , V_3 ) )
continue;
for ( V_251 = 0 ; V_251 < V_11 -> V_338 ; V_251 ++ ) {
if ( V_3 == V_11 -> V_371 [ V_251 ] . V_35 )
break;
}
if ( V_251 < V_11 -> V_338 )
continue;
if ( V_398 && V_398 + V_11 -> V_338 < V_382 ) {
V_206 = V_11 -> V_368 [ V_398 + V_11 -> V_338 ] ;
if ( ! F_194 ( V_2 , V_3 , V_206 ) )
V_206 = 0 ;
}
if ( V_426 )
V_206 = F_195 ( V_2 , V_3 ) ;
else if ( ! V_206 )
V_206 = F_193 ( V_2 , V_3 ) ;
if ( ! V_206 ) {
V_378 ++ ;
continue;
}
V_11 -> V_371 [ V_11 -> V_338 ] . V_35 = V_3 ;
V_11 -> V_371 [ V_11 -> V_338 ] . V_206 = V_206 ;
V_11 -> V_338 ++ ;
if ( V_11 -> V_338 >= 2 )
break;
}
}
V_428:
if ( V_378 )
V_378 = V_400 ;
if ( V_427 == V_11 -> V_338 ) {
if ( V_426 )
return 1 ;
else
return V_378 ;
}
if ( ! V_426 && V_11 -> V_338 < 2 ) {
V_11 -> V_338 = V_427 ;
return V_378 ;
}
return 0 ;
}
static int F_229 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_137 ;
V_9 -> V_138 = 1 ;
V_9 -> V_20 . V_21 . V_55 = V_11 -> V_338 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_338 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_338 ;
sprintf ( V_9 -> V_20 . V_21 . V_141 , L_55 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_230 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_399 - 1 ) / 2 ;
return 0 ;
}
static int F_231 ( struct V_1 * V_2 , int V_31 , bool V_429 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_371 [ V_31 ] . V_35 ;
if ( ! V_11 -> V_371 [ V_31 ] . V_430 )
V_11 -> V_371 [ V_31 ] . V_430 =
F_32 ( V_2 , V_3 , 0 ,
V_86 , 0 ) ;
if ( V_429 ) {
F_232 ( V_2 , V_3 , V_82 ) ;
if ( F_2 ( V_2 , V_3 ) & V_212 )
F_22 ( V_2 , V_3 , V_88 , 0 ,
V_58 , 0 ) ;
F_190 ( V_2 , V_3 , V_11 -> V_371 [ V_31 ] . V_206 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_212 )
F_22 ( V_2 , V_3 , V_88 , 0 ,
V_58 , V_58 ) ;
F_232 ( V_2 , V_3 ,
V_11 -> V_371 [ V_31 ] . V_430 ) ;
}
return 0 ;
}
static int F_233 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_336 ;
V_336 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_336 < 0 || V_336 > V_11 -> V_338 )
return - V_142 ;
if ( V_336 == ( V_11 -> V_399 - 1 ) / 2 )
return 0 ;
V_11 -> V_399 = ( V_336 + 1 ) * 2 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_338 ; V_49 ++ )
F_231 ( V_2 , V_49 , V_49 < V_336 ) ;
V_11 -> V_209 . V_431 = V_11 -> V_399 ;
if ( V_11 -> V_432 && ! V_11 -> V_433 )
V_11 -> V_209 . V_289 = V_11 -> V_209 . V_431 / 2 ;
return 1 ;
}
static int F_234 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_338 > 0 ) {
struct V_63 * V_144 ;
V_144 = F_63 ( V_11 ) ;
if ( ! V_144 )
return - V_145 ;
* V_144 = V_434 ;
V_144 -> V_141 = F_67 ( L_56 , V_114 ) ;
if ( ! V_144 -> V_141 )
return - V_145 ;
}
return 0 ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_47 * V_48 ;
T_1 V_26 [ F_29 ( V_11 -> V_351 ) ] ;
T_1 V_32 [ F_29 ( V_11 -> V_351 ) ] ;
int V_49 , V_159 , V_157 ;
V_48 = V_11 -> V_15 ;
if ( ! V_48 )
return;
if ( V_11 -> V_52 )
return;
V_435:
V_157 = 0 ;
for ( V_159 = 0 ; V_159 < V_11 -> V_161 ; V_159 ++ ) {
T_1 V_160 = V_11 -> V_162 [ V_159 ] ;
int V_50 = F_21 ( V_2 , V_160 ) ;
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
T_1 V_35 = V_11 -> V_102 [ V_49 ] ;
if ( V_35 ) {
if ( F_74 ( V_2 , V_160 , V_35 ) < 0 )
break;
} else if ( V_50 <= V_48 -> V_55 [ V_49 ] . V_56 )
break;
}
if ( V_49 >= V_48 -> V_16 ) {
V_26 [ V_157 ] = V_11 -> V_351 [ V_159 ] ;
V_32 [ V_157 ++ ] = V_160 ;
}
}
if ( ! V_157 ) {
if ( ! F_73 ( V_2 ) ) {
if ( V_11 -> V_51 ) {
V_11 -> V_51 = 0 ;
V_11 -> V_158 [ 0 ] . V_16 = 1 ;
goto V_435;
}
F_81 ( V_436 L_57
L_58 ,
V_2 -> V_190 , V_11 -> V_351 [ 0 ] ) ;
V_11 -> V_161 = 1 ;
V_11 -> V_103 = 0 ;
return;
}
} else if ( V_157 != V_11 -> V_161 ) {
memcpy ( V_11 -> V_351 , V_26 ,
V_157 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_162 , V_32 ,
V_157 * sizeof( T_1 ) ) ;
V_11 -> V_161 = V_157 ;
}
if ( V_11 -> V_103 )
F_75 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 || V_11 -> V_51 )
V_11 -> V_161 = 1 ;
}
static void F_236 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_183 ( V_2 , V_3 , V_59 ) ) {
F_31 ( V_2 , V_3 , 0 ,
V_213 ,
F_186 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_183 ( V_2 , V_3 , V_88 ) )
F_31 ( V_2 , V_3 , 0 ,
V_213 ,
V_364 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_359 , V_157 ;
for ( V_359 = 0 ; V_359 < V_11 -> V_161 ; V_359 ++ )
F_236 ( V_2 , V_359 ) ;
if ( V_11 -> V_52 )
V_157 = 1 ;
else
V_157 = V_11 -> V_161 ;
for ( V_359 = 0 ; V_359 < V_157 ; V_359 ++ )
F_20 ( V_2 , V_359 , V_11 -> V_23 [ V_359 ] , true ) ;
}
static int F_238 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_49 , V_216 ;
int V_360 = 0 ;
T_1 V_3 ;
const char * V_361 = NULL ;
for ( V_49 = 0 ; V_49 < V_148 -> V_169 ; V_49 ++ ) {
if ( V_148 -> V_37 [ V_49 ] . type > V_62 )
break;
V_3 = V_148 -> V_37 [ V_49 ] . V_35 ;
if ( F_2 ( V_2 , V_3 ) & V_437 ) {
const char * V_362 ;
char V_438 [ 32 ] ;
V_362 = F_179 ( V_2 , V_148 , V_49 ) ;
if ( V_11 -> V_51 && ! strcmp ( V_362 , L_42 ) )
V_362 = L_33 ;
if ( V_361 && ! strcmp ( V_362 , V_361 ) )
V_360 ++ ;
else
V_360 = 0 ;
V_361 = V_362 ;
snprintf ( V_438 , sizeof( V_438 ) ,
L_59 , V_362 ) ;
V_216 = F_168 ( V_11 , V_347 ,
V_438 , V_360 ,
F_94 ( V_3 , 3 , 0 , V_59 ) ) ;
if ( V_216 < 0 )
return V_216 ;
}
}
return 0 ;
}
static void F_239 ( struct V_1 * V_2 , T_1 V_160 ,
int V_31 )
{
if ( F_15 ( F_2 ( V_2 , V_160 ) ) == V_53 ) {
F_22 ( V_2 , V_160 , V_59 , V_31 ,
V_58 , 0 ) ;
} else if ( F_21 ( V_2 , V_160 ) > 1 ) {
F_23 ( V_2 , V_160 , 0 ,
V_60 , V_31 ) ;
}
}
static int F_240 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
if ( ! V_35 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_161 ; V_49 ++ ) {
T_1 V_160 = F_12 ( V_11 , V_49 ) ;
int V_31 ;
V_31 = F_74 ( V_2 , V_160 , V_35 ) ;
if ( V_31 < 0 )
continue;
F_239 ( V_2 , V_160 , V_31 ) ;
return V_49 ;
}
return - 1 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_169 ; V_49 ++ )
F_240 ( V_2 , V_11 -> V_36 . V_37 [ V_49 ] . V_35 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_63 * V_354 [ 2 ] [ 3 ] = {
{ V_439 ,
V_440 ,
V_441 } ,
{ V_442 ,
V_443 ,
V_444 } ,
} ;
if ( ! F_216 ( V_2 , V_11 -> V_26 [ 0 ] , V_59 ) ) {
if ( ! V_11 -> V_32 )
return;
if ( ! F_216 ( V_2 , V_11 -> V_32 [ 0 ] , V_88 ) )
return;
V_11 -> V_228 = 1 ;
}
if ( V_11 -> V_161 > 0 ) {
int V_445 = 0 ;
int V_358 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_445 = 1 ;
if ( V_11 -> V_103 ) {
V_358 = 1 ;
V_445 = 0 ;
} else if ( V_11 -> V_52 )
V_358 = 1 ;
if ( ! V_358 ) {
if ( V_11 -> V_161 > 3 )
V_11 -> V_161 = 3 ;
else if ( ! V_11 -> V_161 )
return;
V_358 = V_11 -> V_161 ;
}
V_11 -> V_253 = V_354 [ V_445 ] [ V_358 - 1 ] ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
F_225 ( V_2 ) ;
F_226 ( V_2 ) ;
F_185 ( V_2 ) ;
F_237 ( V_2 ) ;
F_89 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static inline int F_242 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_446 * V_447 ;
V_447 = F_243 ( V_2 -> V_186 -> V_187 , V_448 ) ;
if ( V_447 )
return V_447 -> V_20 ;
return V_11 -> V_178 . V_183 ;
}
static int F_244 ( struct V_1 * V_2 ,
const T_1 * V_449 ,
const T_1 * V_450 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_147 * V_148 = & V_11 -> V_36 ;
int V_216 ;
V_216 = F_245 ( V_2 , V_148 , V_449 ,
V_11 -> V_451 ) ;
if ( V_216 < 0 )
return V_216 ;
if ( ! V_148 -> V_152 ) {
if ( V_148 -> V_207 || V_148 -> V_215 ) {
V_11 -> V_209 . V_431 = 2 ;
V_11 -> V_254 = 1 ;
goto V_452;
}
return 0 ;
}
if ( ! V_11 -> V_453 &&
V_148 -> V_149 == V_150 &&
V_148 -> V_152 <= V_148 -> V_154 ) {
V_148 -> V_151 = V_148 -> V_152 ;
memcpy ( V_148 -> V_96 , V_148 -> V_97 ,
sizeof( V_148 -> V_96 ) ) ;
V_148 -> V_152 = V_148 -> V_154 ;
memcpy ( V_148 -> V_97 , V_148 -> V_92 , sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_154 = 0 ;
memset ( V_148 -> V_92 , 0 , sizeof( V_148 -> V_92 ) ) ;
V_148 -> V_149 = V_153 ;
}
V_216 = F_210 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_234 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_217 ( V_2 , V_148 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_221 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_222 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_181 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_178 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 -> V_209 . V_431 = V_11 -> V_209 . V_289 * 2 ;
V_452:
F_90 ( V_2 ) ;
if ( ! V_11 -> V_254 )
F_235 ( V_2 ) ;
if ( V_450 )
F_85 ( V_2 , V_450 ) ;
if ( ! V_11 -> V_254 ) {
F_78 ( V_2 ) ;
V_216 = F_238 ( V_2 ) ;
if ( V_216 < 0 )
return V_216 ;
}
if ( V_11 -> V_143 . V_156 )
F_27 ( V_11 , V_11 -> V_143 . V_156 ) ;
if ( ! V_11 -> V_254 && ! V_11 -> V_253 )
F_241 ( V_2 ) ;
return 1 ;
}
static int F_246 ( struct V_1 * V_2 , T_1 V_357 )
{
struct V_10 * V_11 = F_45 ( sizeof( * V_11 ) , V_114 ) ;
int V_216 ;
if ( ! V_11 )
return - V_145 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_357 = V_357 ;
F_247 ( & V_11 -> V_323 ) ;
V_216 = F_167 ( V_2 ) ;
if ( V_216 < 0 ) {
F_46 ( V_11 ) ;
return V_216 ;
}
return 0 ;
}
static int F_248 ( struct V_1 * V_2 )
{
static const T_1 V_454 [] = { 0x1d , 0 } ;
static const T_1 V_455 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_244 ( V_2 , V_454 , V_455 ) ;
}
static void F_249 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 == V_250 )
F_71 ( V_2 , 0x21 , V_120 ) ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_432 = 1 ;
F_251 ( V_2 , V_456 , V_457 ,
V_458 ) ;
F_126 ( V_2 , V_459 ) ;
V_216 = F_248 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_254 ( struct V_1 * V_2 )
{
static const T_1 V_461 [] = { 0x17 , 0 } ;
static const T_1 V_462 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_244 ( V_2 , V_461 , V_462 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_31 ( V_2 , 0x01 , 0 , V_463 ,
V_11 -> V_94 ) ;
}
static void F_256 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 == V_250 ) {
V_11 -> V_99 = F_255 ;
V_11 -> V_100 = 1 ;
V_11 -> V_45 = 1 ;
V_11 -> V_36 . V_92 [ 0 ] = 0x0f ;
F_71 ( V_2 , 0x0f , V_109 ) ;
F_257 ( & V_11 -> V_323 , V_128 ) ;
}
}
static void F_258 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_464 V_465 [] = {
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
switch ( V_108 ) {
case V_459 :
F_259 ( V_2 , V_465 ) ;
break;
case V_250 :
V_11 -> V_202 = V_466 ;
break;
}
}
static int F_260 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x07 ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
F_251 ( V_2 , NULL , V_467 , V_468 ) ;
F_126 ( V_2 , V_459 ) ;
V_216 = F_254 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x07 , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
V_11 -> V_318 = F_56 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static void F_261 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 != V_272 )
return;
F_52 ( V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 , int V_35 , int V_469 )
{
unsigned int V_470 , V_471 , V_472 ;
V_470 = F_32 ( V_2 , V_2 -> V_473 , 0 ,
V_474 , 0 ) ;
if ( ! V_469 )
V_470 |= ( 1 << V_35 ) ;
else
V_470 &= ~ ( 1 << V_35 ) ;
V_471 = F_32 ( V_2 , V_2 -> V_473 , 0 ,
V_475 , 0 ) ;
V_471 |= ( 1 << V_35 ) ;
V_472 = F_32 ( V_2 , V_2 -> V_473 , 0 ,
V_476 , 0 ) ;
V_472 |= ( 1 << V_35 ) ;
F_31 ( V_2 , V_2 -> V_473 , 0 ,
V_477 , V_471 ) ;
F_31 ( V_2 , V_2 -> V_473 , 0 ,
V_478 , V_472 ) ;
F_57 ( 1 ) ;
F_31 ( V_2 , V_2 -> V_473 , 0 ,
V_463 , V_470 ) ;
}
static void F_263 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 != V_272 )
return;
F_262 ( V_2 , 0 , 0 ) ;
F_262 ( V_2 , 1 , 0 ) ;
}
static void F_264 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 == V_459 ) {
T_1 V_479 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_480 [ 2 ] = { 0x0e , 0x0f } ;
F_265 ( V_2 , 0x14 , 2 , V_479 ) ;
F_265 ( V_2 , 0x15 , 2 , V_479 ) ;
F_265 ( V_2 , 0x18 , 2 , V_480 ) ;
F_265 ( V_2 , 0x1a , 2 , V_480 ) ;
} else if ( V_108 == V_250 ) {
T_1 V_218 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_265 ( V_2 , 0x14 , 5 , V_218 ) ;
F_265 ( V_2 , 0x15 , 5 , V_218 ) ;
F_265 ( V_2 , 0x18 , 5 , V_218 ) ;
F_265 ( V_2 , 0x1a , 5 , V_218 ) ;
}
}
static void F_266 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_481 [ 2 ] = { 0x14 , 0x15 } ;
int V_49 ;
if ( V_108 != V_272 )
return;
for ( V_49 = 0 ; V_49 < F_29 ( V_481 ) ; V_49 ++ ) {
unsigned int V_34 = F_17 ( V_2 , V_481 [ V_49 ] ) ;
if ( F_267 ( V_34 ) != V_482 )
continue;
V_34 = F_32 ( V_2 , V_481 [ V_49 ] , 0 ,
V_86 , 0 ) ;
V_34 |= V_483 ;
F_18 ( V_2 , V_481 [ V_49 ] , V_34 ) ;
V_11 -> V_85 = 1 ;
break;
}
}
static void F_268 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_481 [ 2 ] = { 0x18 , 0x1a } ;
int V_49 ;
if ( V_108 != V_272 )
return;
for ( V_49 = 0 ; V_49 < F_29 ( V_481 ) ; V_49 ++ ) {
unsigned int V_34 ;
V_34 = F_32 ( V_2 , V_481 [ V_49 ] , 0 ,
V_86 , 0 ) ;
V_34 |= V_484 ;
F_18 ( V_2 , V_481 [ V_49 ] , V_34 ) ;
}
V_11 -> V_85 = 1 ;
}
static void F_269 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 == V_459 )
V_11 -> V_453 = 1 ;
}
static int F_270 ( struct V_1 * V_2 )
{
static const T_1 V_485 [] = { 0x1d , 0 } ;
static const T_1 V_486 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_244 ( V_2 , V_485 , V_486 ) ;
}
static int F_271 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
switch ( V_2 -> V_119 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_33 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_251 ( V_2 , V_487 , V_488 ,
V_489 ) ;
F_126 ( V_2 , V_459 ) ;
F_80 ( V_2 ) ;
V_216 = F_270 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 && F_242 ( V_2 ) ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_272 ( struct V_1 * V_2 )
{
static const T_1 V_490 [] = { 0x1d , 0 } ;
static const T_1 V_491 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_244 ( V_2 , V_490 , V_491 ) ;
}
static int F_273 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_33 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_251 ( V_2 , V_492 , V_493 ,
V_494 ) ;
F_126 ( V_2 , V_459 ) ;
F_80 ( V_2 ) ;
V_216 = F_272 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 && F_242 ( V_2 ) ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
V_11 -> V_318 = F_56 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_274 ( struct V_1 * V_2 )
{
static const T_1 V_495 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_216 = F_244 ( V_2 , NULL , V_495 ) ;
if ( V_216 > 0 ) {
if ( ! V_11 -> V_254 && V_11 -> V_36 . V_96 [ 0 ] != 0x1d ) {
F_27 ( V_11 , V_496 ) ;
F_257 ( & V_11 -> V_323 , V_497 ) ;
}
}
return V_216 ;
}
static int F_275 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_49 , V_498 , V_216 ;
V_216 = F_246 ( V_2 , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
F_251 ( V_2 , V_499 , NULL , V_500 ) ;
F_126 ( V_2 , V_459 ) ;
V_216 = F_274 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
V_498 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
if ( V_11 -> V_66 [ V_49 ] == V_496 ) {
V_498 = 1 ;
break;
}
}
if ( V_498 ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_59 ) )
F_276 ( V_2 , 0x1d , V_59 ,
( 0x0c << V_501 ) |
( 0x0c << V_502 ) |
( 0x07 << V_503 ) |
( 0 << V_504 ) ) ;
}
V_2 -> V_325 = V_460 ;
V_11 -> V_318 = F_56 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_277 ( struct V_1 * V_2 )
{
static const T_1 V_505 [] = { 0x1d , 0 } ;
static const T_1 V_506 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_507 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_508 ;
switch ( V_11 -> V_509 ) {
case V_510 :
case V_511 :
V_508 = V_507 ;
break;
case V_512 :
case V_513 :
V_508 = V_506 ;
break;
default:
V_508 = V_506 ;
break;
}
return F_244 ( V_2 , V_505 , V_508 ) ;
}
static void F_278 ( struct V_1 * V_2 , int V_514 )
{
int V_34 = F_86 ( V_2 , 0x04 ) ;
if ( V_514 )
V_34 |= 1 << 11 ;
else
V_34 &= ~ ( 1 << 11 ) ;
F_87 ( V_2 , 0x04 , V_34 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_509 != V_512 )
return;
if ( ( F_88 ( V_2 ) & 0x00ff ) == 0x017 )
F_278 ( V_2 , 0 ) ;
if ( ( F_88 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_278 ( V_2 , 0 ) ;
F_57 ( 150 ) ;
}
}
static int F_280 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_509 == V_512 ||
( F_88 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_278 ( V_2 , 0 ) ;
F_57 ( 150 ) ;
}
V_2 -> V_325 . V_326 ( V_2 ) ;
if ( V_11 -> V_509 == V_512 ||
( F_88 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_278 ( V_2 , 1 ) ;
F_57 ( 200 ) ;
}
if ( V_11 -> V_509 == V_512 ||
( F_88 ( V_2 ) & 0x00ff ) == 0x018 )
F_278 ( V_2 , 1 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
F_131 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_281 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 == V_459 )
V_11 -> V_451 = V_515 ;
}
static void F_282 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
int V_516 ;
if ( V_108 != V_272 )
return;
V_516 = F_86 ( V_2 , 0x1e ) ;
F_87 ( V_2 , 0x1e , V_516 | 0x80 ) ;
}
static void F_283 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
static const struct V_517 V_518 [] = {
{ 0x20 , V_68 , 0x0d } ,
{ 0x20 , V_71 , 0x4000 } ,
{}
} ;
unsigned int V_148 ;
if ( strcmp ( V_2 -> V_190 , L_60 ) )
return;
V_148 = F_17 ( V_2 , 0x12 ) ;
if ( F_16 ( V_148 ) == V_519 )
F_59 ( V_2 , V_518 ) ;
}
static void F_284 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 != V_250 )
return;
V_11 -> V_290 = & V_520 ;
V_11 -> V_295 = & V_521 ;
}
static void F_285 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
int V_516 ;
if ( V_108 != V_272 )
return;
V_516 = F_86 ( V_2 , 0x07 ) ;
F_87 ( V_2 , 0x07 , V_516 | 0x80 ) ;
}
static void F_286 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
F_31 ( V_2 , 0x20 , 0 ,
V_68 , 0x0c ) ;
F_31 ( V_2 , 0x20 , 0 ,
V_71 , 0x680 ) ;
F_31 ( V_2 , 0x20 , 0 ,
V_68 , 0x0c ) ;
F_31 ( V_2 , 0x20 , 0 ,
V_71 , 0x480 ) ;
}
static void F_287 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_108 != V_250 )
return;
V_11 -> V_99 = F_286 ;
}
static void F_288 ( void * V_522 , int V_523 )
{
struct V_1 * V_2 = V_522 ;
unsigned int V_524 = V_523 ? 0x20 : 0x24 ;
F_232 ( V_2 , 0x19 , V_524 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_108 ) {
case V_270 :
V_11 -> V_261 . V_525 = F_288 ;
F_290 ( V_2 , & V_11 -> V_261 , true ) ;
case V_272 :
F_291 ( & V_11 -> V_261 ) ;
break;
}
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_34 ;
if ( V_11 -> V_509 != V_512 )
return;
if ( ( F_88 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_87 ( V_2 , 0xf , 0x960b ) ;
F_87 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_88 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_87 ( V_2 , 0xf , 0x960b ) ;
F_87 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_88 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_34 = F_86 ( V_2 , 0x04 ) ;
F_87 ( V_2 , 0x04 , V_34 | ( 1 << 11 ) ) ;
}
if ( ( F_88 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_34 = F_86 ( V_2 , 0xd ) ;
if ( ( V_34 & 0x0c00 ) >> 10 != 0x1 ) {
F_87 ( V_2 , 0xd , V_34 | ( 1 << 10 ) ) ;
}
V_34 = F_86 ( V_2 , 0x17 ) ;
if ( ( V_34 & 0x01c0 ) >> 6 != 0x4 ) {
F_87 ( V_2 , 0x17 , V_34 | ( 1 << 7 ) ) ;
}
}
V_34 = F_86 ( V_2 , 0xd ) ;
F_87 ( V_2 , 0xd , V_34 | ( 1 << 14 ) ) ;
V_34 = F_86 ( V_2 , 0x4 ) ;
F_87 ( V_2 , 0x4 , V_34 | ( 1 << 11 ) ) ;
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
if ( V_2 -> V_119 == 0x10ec0269 ) {
V_11 -> V_509 = V_510 ;
switch ( F_88 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_186 -> V_187 -> V_526 == 0x1025 &&
V_11 -> V_178 . V_195 == 1 )
V_216 = F_166 ( V_2 , L_60 ) ;
V_11 -> V_509 = V_512 ;
break;
case 0x0020 :
if ( V_2 -> V_186 -> V_187 -> V_526 == 0x17aa &&
V_2 -> V_186 -> V_187 -> V_188 == 0x21f3 )
V_216 = F_166 ( V_2 , L_61 ) ;
V_11 -> V_509 = V_511 ;
break;
case 0x0030 :
V_11 -> V_509 = V_513 ;
break;
default:
F_33 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_216 < 0 )
goto error;
V_11 -> V_271 = F_292 ;
F_292 ( V_2 ) ;
}
F_251 ( V_2 , V_527 ,
V_528 , V_529 ) ;
F_126 ( V_2 , V_459 ) ;
F_80 ( V_2 ) ;
V_216 = F_277 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 && F_242 ( V_2 ) ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x0b , 0x04 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
#ifdef F_294
V_2 -> V_325 . V_530 = F_280 ;
#endif
V_11 -> V_318 = F_279 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_295 ( struct V_1 * V_2 )
{
static const T_1 V_531 [] = { 0x1d , 0 } ;
static const T_1 V_532 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_244 ( V_2 , V_531 , V_532 ) ;
}
static void F_296 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 ;
if ( V_108 != V_272 )
return;
V_34 = F_32 ( V_2 , 0x0f , 0 ,
V_86 , 0 ) ;
if ( ! ( V_34 & ( V_533 | V_534 ) ) )
V_34 |= V_533 ;
V_34 |= V_484 ;
F_18 ( V_2 , 0x0f , V_34 ) ;
V_11 -> V_85 = 1 ;
}
static void F_297 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 == V_459 )
V_2 -> V_535 = 1 ;
}
static int F_298 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x15 ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
F_251 ( V_2 , NULL , V_536 , V_537 ) ;
F_126 ( V_2 , V_459 ) ;
V_216 = F_295 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 ) {
V_216 = F_252 ( V_2 , 0x23 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x23 , 0 , V_88 ) ;
}
V_2 -> V_325 = V_460 ;
#ifdef F_299
V_11 -> V_324 = F_161 ;
#endif
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_300 ( struct V_1 * V_2 )
{
static const T_1 V_538 [] = { 0x1d , 0 } ;
static const T_1 V_539 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_244 ( V_2 , V_538 , V_539 ) ;
}
static void F_301 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 == V_459 ) {
F_302 ( V_2 , 0x18 , 0x00001714 ) ;
F_302 ( V_2 , 0x19 , 0x0000171c ) ;
}
}
static int F_303 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
F_251 ( V_2 , NULL , V_540 , V_541 ) ;
F_126 ( V_2 , V_459 ) ;
V_216 = F_300 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 ) {
V_216 = F_252 ( V_2 , 0x23 ) ;
if ( V_216 < 0 )
goto error;
F_253 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_460 ;
V_11 -> V_318 = F_56 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_304 ( struct V_1 * V_2 )
{
static const T_1 V_542 [] = { 0x1d , 0 } ;
static const T_1 V_543 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_544 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_508 ;
if ( V_2 -> V_119 == 0x10ec0272 || V_2 -> V_119 == 0x10ec0663 ||
V_2 -> V_119 == 0x10ec0665 || V_2 -> V_119 == 0x10ec0670 )
V_508 = V_543 ;
else
V_508 = V_544 ;
return F_244 ( V_2 , V_542 , V_508 ) ;
}
static void F_305 ( struct V_1 * V_2 ,
const struct V_249 * V_176 , int V_108 )
{
if ( V_108 != V_250 )
return;
if ( F_276 ( V_2 , 0x2 , V_88 ,
( 0x3b << V_501 ) |
( 0x3b << V_502 ) |
( 0x03 << V_503 ) |
( 0 << V_504 ) ) )
F_81 ( V_436
L_62 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
int V_34 , V_516 ;
V_516 = F_88 ( V_2 ) ;
switch ( V_2 -> V_119 ) {
case 0x10ec0662 :
if ( ( V_516 & 0x00f0 ) == 0x0030 ) {
V_34 = F_86 ( V_2 , 0x4 ) ;
F_87 ( V_2 , 0x4 , V_34 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_34 = F_86 ( V_2 , 0xd ) ;
F_87 ( V_2 , 0xd , V_34 | ( 1 << 14 ) ) ;
break;
}
}
static int F_307 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_216 ;
V_216 = F_246 ( V_2 , 0x0b ) ;
if ( V_216 < 0 )
return V_216 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_451 = V_515 ;
F_33 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_11 -> V_271 = F_306 ;
F_306 ( V_2 ) ;
F_251 ( V_2 , V_545 ,
V_546 , V_547 ) ;
F_126 ( V_2 , V_459 ) ;
F_80 ( V_2 ) ;
if ( ( F_88 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_186 -> V_187 -> V_526 == 0x1025 &&
V_11 -> V_178 . V_195 == 1 ) {
if ( F_166 ( V_2 , L_63 ) < 0 )
goto error;
}
V_216 = F_304 ( V_2 ) ;
if ( V_216 < 0 )
goto error;
if ( ! V_11 -> V_254 && F_242 ( V_2 ) ) {
V_216 = F_252 ( V_2 , 0x1 ) ;
if ( V_216 < 0 )
goto error;
switch ( V_2 -> V_119 ) {
case 0x10ec0662 :
F_253 ( V_11 , 0x0b , 0x05 , V_59 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_253 ( V_11 , 0x0b , 0x04 , V_59 ) ;
break;
case 0x10ec0273 :
F_253 ( V_11 , 0x0b , 0x03 , V_59 ) ;
break;
}
}
V_2 -> V_325 = V_460 ;
V_11 -> V_318 = F_56 ;
F_126 ( V_2 , V_250 ) ;
return 0 ;
error:
F_158 ( V_2 ) ;
return V_216 ;
}
static int F_308 ( struct V_1 * V_2 )
{
return F_244 ( V_2 , NULL , NULL ) ;
}
static int F_309 ( struct V_1 * V_2 )
{
int V_216 ;
V_216 = F_246 ( V_2 , 0 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_308 ( V_2 ) ;
if ( V_216 < 0 ) {
F_158 ( V_2 ) ;
return V_216 ;
}
V_2 -> V_325 = V_460 ;
return 0 ;
}
static int T_4 F_310 ( void )
{
return F_311 ( & V_548 ) ;
}
static void T_5 F_312 ( void )
{
F_313 ( & V_548 ) ;
}
