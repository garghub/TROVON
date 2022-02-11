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
static void F_38 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_94 =
F_34 ( V_2 , F_29 ( V_11 -> V_36 . V_92 ) ,
V_11 -> V_36 . V_92 ) ;
if ( ! V_11 -> V_102 || ( ! V_11 -> V_45 && ! V_11 -> V_98 ) )
return;
F_19 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_36 . V_103 == V_104 )
return;
if ( V_11 -> V_36 . V_97 [ 0 ] == V_11 -> V_36 . V_92 [ 0 ] )
return;
V_11 -> V_95 =
F_34 ( V_2 , F_29 ( V_11 -> V_36 . V_97 ) ,
V_11 -> V_36 . V_97 ) ;
if ( ! V_11 -> V_45 || ! V_11 -> V_105 )
return;
F_19 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_76 = V_11 -> V_106 ;
if ( ! V_11 -> V_107 || ! V_11 -> V_108 )
return;
if ( F_28 ( ! V_11 -> V_26 ) )
return;
if ( F_28 ( V_11 -> V_109 < 0 || V_11 -> V_110 < 0 ) )
return;
if ( F_35 ( V_2 , V_76 [ V_11 -> V_110 ] ) )
F_20 ( V_2 , 0 , V_11 -> V_110 , false ) ;
else if ( V_11 -> V_111 >= 0 &&
F_35 ( V_2 , V_76 [ V_11 -> V_111 ] ) )
F_20 ( V_2 , 0 , V_11 -> V_111 , false ) ;
else
F_20 ( V_2 , 0 , V_11 -> V_109 , false ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
unsigned int V_34 ;
struct V_6 * V_112 ;
struct V_17 * V_113 ;
V_112 = F_42 ( V_2 , L_1 ) ;
if ( ! V_112 )
return;
V_113 = F_43 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 )
return;
V_34 = F_32 ( V_2 , V_101 -> V_3 , 0 ,
V_115 , 0 ) ;
V_34 &= V_116 ;
V_113 -> V_20 . integer . V_20 [ 0 ] = V_34 ;
V_113 -> V_20 . integer . V_20 [ 1 ] = V_34 ;
V_112 -> V_117 ( V_112 , V_113 ) ;
F_44 ( V_113 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned int V_118 )
{
F_46 ( V_2 , V_118 >> 2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_38 ( V_2 , NULL ) ;
F_39 ( V_2 , NULL ) ;
F_40 ( V_2 , NULL ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 0 ) ;
V_119 = F_32 ( V_2 , 0x20 , 0 , V_70 , 0 ) ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
if ( ( V_119 & 0xf0 ) == 0x20 )
F_32 ( V_2 , 0x20 , 0 ,
V_71 , 0x830 ) ;
else
F_32 ( V_2 , 0x20 , 0 ,
V_71 , 0x3030 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
V_119 = F_32 ( V_2 , 0x20 , 0 , V_70 , 0 ) ;
F_31 ( V_2 , 0x20 , 0 , V_68 , 7 ) ;
F_31 ( V_2 , 0x20 , 0 , V_71 , V_119 | 0x2010 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_3 , int V_91 )
{
if ( F_15 ( F_2 ( V_2 , V_3 ) ) != V_40 )
return;
if ( F_51 ( V_2 , V_3 ) & V_120 )
F_31 ( V_2 , V_3 , 0 , V_121 ,
V_91 ? 2 : 0 ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_91 )
{
static T_1 V_76 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_122 ;
for ( V_122 = V_76 ; * V_122 ; V_122 ++ )
F_50 ( V_2 , * V_122 , V_91 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_52 ( V_2 , false ) ;
F_54 ( 200 ) ;
}
static void F_55 ( struct V_1 * V_2 , int type )
{
unsigned int V_119 ;
F_52 ( V_2 , true ) ;
switch ( type ) {
case V_123 :
F_56 ( V_2 , V_124 ) ;
break;
case V_125 :
F_56 ( V_2 , V_126 ) ;
break;
case V_127 :
F_56 ( V_2 , V_128 ) ;
break;
case V_129 :
switch ( V_2 -> V_130 ) {
case 0x10ec0260 :
F_31 ( V_2 , 0x1a , 0 ,
V_68 , 7 ) ;
V_119 = F_32 ( V_2 , 0x1a , 0 ,
V_70 , 0 ) ;
F_31 ( V_2 , 0x1a , 0 ,
V_68 , 7 ) ;
F_31 ( V_2 , 0x1a , 0 ,
V_71 ,
V_119 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_49 ( V_2 ) ;
break;
case 0x10ec0888 :
F_48 ( V_2 ) ;
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
static int F_57 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_131 [] = {
L_2 , L_3 , L_4
} ;
if ( V_11 -> V_132 && V_11 -> V_133 )
return F_58 ( V_7 , V_9 , 3 , V_131 ) ;
return F_59 ( V_7 , V_9 ) ;
}
static int F_60 ( struct V_6 * V_7 ,
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
static int F_61 ( struct V_6 * V_7 ,
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
if ( V_11 -> V_132 ) {
if ( ! V_11 -> V_98 && V_11 -> V_45 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_98 = 0 ;
} else if ( V_11 -> V_133 ) {
if ( V_11 -> V_98 )
return 0 ;
V_11 -> V_98 = 1 ;
} else
return - V_134 ;
break;
case 2 :
if ( ! V_11 -> V_133 || ! V_11 -> V_132 )
return - V_134 ;
if ( V_11 -> V_45 && V_11 -> V_98 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_98 = 1 ;
break;
default:
return - V_134 ;
}
F_19 ( V_2 ) ;
return 1 ;
}
static struct V_63 *
F_62 ( struct V_10 * V_11 , const char * V_135 ,
const struct V_63 * V_136 )
{
struct V_63 * V_137 = F_63 ( & V_11 -> V_138 ) ;
if ( ! V_137 )
return NULL ;
* V_137 = * V_136 ;
V_137 -> V_135 = F_64 ( V_135 , V_114 ) ;
if ( ! V_137 -> V_135 )
return NULL ;
return V_137 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! F_62 ( V_11 , L_5 , & V_139 ) )
return - V_140 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_77 = 0 ;
int V_49 , V_143 ;
if ( V_142 -> V_92 [ 0 ] )
V_77 ++ ;
if ( V_142 -> V_97 [ 0 ] )
V_77 ++ ;
if ( V_142 -> V_96 [ 0 ] )
V_77 ++ ;
if ( V_77 < 2 )
return 0 ;
if ( ! V_142 -> V_96 [ 0 ] &&
V_142 -> V_103 == V_104 ) {
memcpy ( V_142 -> V_96 , V_142 -> V_97 ,
sizeof( V_142 -> V_96 ) ) ;
V_142 -> V_144 = V_142 -> V_145 ;
}
if ( ! V_142 -> V_92 [ 0 ] &&
V_142 -> V_103 == V_146 ) {
memcpy ( V_142 -> V_92 , V_142 -> V_97 ,
sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_147 = V_142 -> V_145 ;
}
V_11 -> V_83 = V_84 ;
for ( V_49 = 0 ; V_49 < V_142 -> V_147 ; V_49 ++ ) {
T_1 V_3 = V_142 -> V_92 [ V_49 ] ;
if ( ! F_67 ( V_2 , V_3 ) )
continue;
F_68 ( L_6 ,
V_3 ) ;
F_69 ( V_2 , V_3 , V_148 ,
F_38 ) ;
V_11 -> V_102 = 1 ;
}
if ( V_142 -> V_103 == V_149 && V_142 -> V_145 ) {
if ( V_142 -> V_144 )
for ( V_49 = 0 ; V_49 < V_142 -> V_145 ; V_49 ++ ) {
T_1 V_3 = V_142 -> V_97 [ V_49 ] ;
if ( ! F_67 ( V_2 , V_3 ) )
continue;
F_68 ( L_7
L_8 , V_3 ) ;
F_69 ( V_2 , V_3 , V_150 ,
F_39 ) ;
V_11 -> V_105 = 1 ;
}
V_11 -> V_133 = V_11 -> V_102 ;
}
V_11 -> V_132 = V_142 -> V_144 &&
( V_11 -> V_102 || V_11 -> V_105 ) ;
V_11 -> V_98 = V_11 -> V_133 ;
V_11 -> V_45 = V_11 -> V_132 ;
if ( V_11 -> V_132 || V_11 -> V_133 ) {
V_143 = F_65 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
}
return 0 ;
}
static int F_70 ( T_1 V_3 , const T_1 * V_151 , int V_152 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_152 ; V_49 ++ )
if ( V_151 [ V_49 ] == V_3 )
return V_49 ;
return - 1 ;
}
static bool F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_47 * V_48 = & V_11 -> V_153 [ 0 ] ;
int V_49 , V_154 , V_31 ;
T_1 V_155 , V_35 ;
if ( V_48 != V_11 -> V_15 )
return false ;
for ( V_154 = 0 ; V_154 < V_11 -> V_156 ; V_154 ++ ) {
V_155 = V_11 -> V_157 [ V_154 ] ;
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
V_35 = V_11 -> V_106 [ V_49 ] ;
if ( ! V_35 )
return false ;
if ( F_72 ( V_2 , V_155 , V_35 ) < 0 )
break;
}
if ( V_49 >= V_48 -> V_16 )
return true ;
}
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
V_35 = V_11 -> V_106 [ V_49 ] ;
for ( V_154 = 0 ; V_154 < V_11 -> V_156 ; V_154 ++ ) {
V_155 = V_11 -> V_157 [ V_154 ] ;
V_31 = F_72 ( V_2 , V_155 , V_35 ) ;
if ( V_31 >= 0 ) {
V_48 -> V_55 [ V_49 ] . V_56 = V_31 ;
V_11 -> V_27 [ V_49 ] = V_154 ;
break;
}
}
}
F_68 ( L_9 ) ;
V_11 -> V_52 = 1 ;
return true ;
}
static bool F_73 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_47 * V_48 ;
if ( ! V_11 -> V_107 )
return false ;
if ( V_11 -> V_108 )
return true ;
if ( ! F_71 ( V_2 ) ) {
V_11 -> V_107 = 0 ;
return false ;
}
V_48 = V_11 -> V_15 ;
V_11 -> V_110 = F_70 ( V_11 -> V_158 ,
V_11 -> V_106 , V_48 -> V_16 ) ;
V_11 -> V_109 = F_70 ( V_11 -> V_159 ,
V_11 -> V_106 , V_48 -> V_16 ) ;
V_11 -> V_111 = F_70 ( V_11 -> V_160 ,
V_11 -> V_106 , V_48 -> V_16 ) ;
if ( V_11 -> V_110 < 0 || V_11 -> V_109 < 0 ) {
V_11 -> V_107 = 0 ;
return false ;
}
F_69 ( V_2 , V_11 -> V_158 ,
V_161 , F_40 ) ;
if ( V_11 -> V_160 )
F_69 ( V_2 , V_11 -> V_160 ,
V_161 ,
F_40 ) ;
V_11 -> V_108 = 1 ;
V_11 -> V_107 = 1 ;
return true ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
T_1 V_162 , V_163 , V_164 ;
int V_49 ;
if ( V_11 -> V_51 )
return 0 ;
V_11 -> V_110 = V_11 -> V_109 = V_11 -> V_111 = - 1 ;
V_162 = V_163 = V_164 = 0 ;
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
T_1 V_3 = V_142 -> V_37 [ V_49 ] . V_35 ;
unsigned int V_166 ;
V_166 = F_17 ( V_2 , V_3 ) ;
switch ( F_75 ( V_166 ) ) {
case V_167 :
if ( V_162 )
return 0 ;
if ( V_142 -> V_37 [ V_49 ] . type != V_62 )
return 0 ;
V_162 = V_3 ;
break;
case V_168 :
return 0 ;
case V_169 :
if ( V_164 )
return 0 ;
if ( V_142 -> V_37 [ V_49 ] . type > V_170 )
return 0 ;
V_164 = V_3 ;
break;
default:
if ( V_163 )
return 0 ;
if ( V_142 -> V_37 [ V_49 ] . type != V_62 )
return 0 ;
V_163 = V_3 ;
break;
}
}
if ( ! V_163 && V_164 ) {
V_163 = V_164 ;
V_164 = 0 ;
}
if ( ! V_163 || ! V_162 )
return 0 ;
if ( ! F_67 ( V_2 , V_163 ) )
return 0 ;
if ( V_164 && ! F_67 ( V_2 , V_164 ) )
return 0 ;
V_11 -> V_158 = V_163 ;
V_11 -> V_159 = V_162 ;
V_11 -> V_160 = V_164 ;
V_11 -> V_107 = 1 ;
if ( ! F_73 ( V_2 ) )
return 0 ;
F_68 ( L_10 ,
V_163 , V_162 , V_164 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_143 ;
V_143 = F_66 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_74 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 ,
const struct V_171 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 == V_174 ) {
V_11 -> V_175 . V_176 = 1 ;
V_11 -> V_175 . V_177 = V_178 ;
}
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned int V_179 , V_119 , V_49 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_175 . V_180 = 1 ;
if ( V_11 -> V_175 . V_176 ) {
V_179 = V_11 -> V_175 . V_177 ;
if ( V_179 == V_178 )
return - 1 ;
goto V_181;
}
V_179 = V_2 -> V_182 & 0xffff ;
if ( V_179 != V_2 -> V_183 -> V_184 -> V_185 && ( V_179 & 1 ) )
goto V_181;
V_3 = 0x1d ;
if ( V_2 -> V_130 == 0x10ec0260 )
V_3 = 0x17 ;
V_179 = F_17 ( V_2 , V_3 ) ;
if ( ! ( V_179 & 1 ) ) {
F_79 ( V_186 L_11 ,
V_2 -> V_187 , V_179 ) ;
return - 1 ;
}
V_119 = 0 ;
for ( V_49 = 1 ; V_49 < 16 ; V_49 ++ ) {
if ( ( V_179 >> V_49 ) & 1 )
V_119 ++ ;
}
if ( ( ( V_179 >> 16 ) & 0xf ) != V_119 )
return - 1 ;
V_11 -> V_175 . V_188 = V_179 >> 30 ;
V_11 -> V_175 . V_180 = ( V_179 & 0x100000 ) >> 20 ;
V_11 -> V_175 . V_189 = ( V_179 >> 16 ) & 0xf ;
V_11 -> V_175 . V_190 = V_179 >> 8 ;
V_181:
V_11 -> V_175 . V_177 = V_179 ;
V_11 -> V_175 . V_191 = ( V_179 & 0x38 ) >> 3 ;
V_11 -> V_175 . V_192 = ( V_179 & 0x4 ) >> 2 ;
V_11 -> V_175 . V_193 = ( V_179 & 0x2 ) >> 1 ;
V_11 -> V_175 . V_194 = V_179 & 0x1 ;
F_80 ( L_12 ,
V_3 , V_11 -> V_175 . V_177 ) ;
F_80 ( L_13 ,
V_11 -> V_175 . V_188 ) ;
F_80 ( L_14 , V_11 -> V_175 . V_180 ) ;
F_80 ( L_15 , V_11 -> V_175 . V_189 ) ;
F_80 ( L_16 , V_11 -> V_175 . V_190 ) ;
F_80 ( L_17 , V_11 -> V_175 . V_191 ) ;
F_80 ( L_18 , V_11 -> V_175 . V_192 ) ;
F_80 ( L_19 , V_11 -> V_175 . V_193 ) ;
F_80 ( L_20 , V_11 -> V_175 . V_194 ) ;
return 0 ;
}
static bool F_81 ( T_1 V_3 , const T_1 * V_151 , int V_152 )
{
return F_70 ( V_3 , V_151 , V_152 ) >= 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_1 V_195 , T_1 V_196 ,
T_1 V_197 , T_1 V_198 )
{
unsigned int V_179 , V_119 , V_49 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_175 . V_176 ) {
V_179 = V_11 -> V_175 . V_177 ;
if ( V_179 == V_178 )
return 0 ;
goto V_181;
}
V_179 = V_2 -> V_182 & 0xffff ;
if ( ( V_179 != V_2 -> V_183 -> V_184 -> V_185 ) && ( V_179 & 1 ) )
goto V_181;
V_3 = 0x1d ;
if ( V_2 -> V_130 == 0x10ec0260 )
V_3 = 0x17 ;
V_179 = F_17 ( V_2 , V_3 ) ;
F_80 ( L_21
L_22 ,
V_179 , V_3 ) ;
if ( ! ( V_179 & 1 ) )
return 0 ;
if ( ( V_179 >> 30 ) != 1 )
return 0 ;
V_119 = 0 ;
for ( V_49 = 1 ; V_49 < 16 ; V_49 ++ ) {
if ( ( V_179 >> V_49 ) & 1 )
V_119 ++ ;
}
if ( ( ( V_179 >> 16 ) & 0xf ) != V_119 )
return 0 ;
V_181:
F_80 ( L_23 ,
V_179 & 0xffff , V_2 -> V_130 ) ;
V_119 = ( V_179 & 0x38 ) >> 3 ;
switch ( V_119 ) {
case 1 :
V_11 -> V_199 = V_123 ;
break;
case 3 :
V_11 -> V_199 = V_125 ;
break;
case 7 :
V_11 -> V_199 = V_127 ;
break;
case 5 :
default:
V_11 -> V_199 = V_129 ;
break;
}
if ( ! ( V_179 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_36 . V_92 [ 0 ] &&
! ( V_11 -> V_36 . V_97 [ 0 ] &&
V_11 -> V_36 . V_103 == V_146 ) ) {
T_1 V_3 ;
V_119 = ( V_179 >> 11 ) & 0x3 ;
if ( V_119 == 0 )
V_3 = V_195 ;
else if ( V_119 == 1 )
V_3 = V_196 ;
else if ( V_119 == 2 )
V_3 = V_197 ;
else if ( V_119 == 3 )
V_3 = V_198 ;
else
return 1 ;
if ( F_81 ( V_3 , V_11 -> V_36 . V_97 ,
V_11 -> V_36 . V_145 ) )
return 1 ;
V_11 -> V_36 . V_92 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_83 ( struct V_1 * V_2 , const T_1 * V_200 )
{
if ( ! F_82 ( V_2 , V_200 [ 0 ] , V_200 [ 1 ] , V_200 [ 2 ] , V_200 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_80 ( L_24
L_25 ) ;
V_11 -> V_199 = V_129 ;
}
}
static int F_84 ( struct V_1 * V_2 ,
unsigned int V_73 )
{
unsigned int V_34 ;
F_31 ( V_2 , 0x20 , 0 , V_68 ,
V_73 ) ;
V_34 = F_32 ( V_2 , 0x20 , 0 ,
V_70 , 0 ) ;
return V_34 ;
}
static void F_85 ( struct V_1 * V_2 , unsigned int V_73 ,
unsigned int V_201 )
{
F_31 ( V_2 , 0x20 , 0 , V_68 ,
V_73 ) ;
F_31 ( V_2 , 0x20 , 0 , V_71 ,
V_201 ) ;
}
static unsigned int F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_202 )
V_11 -> V_202 = F_84 ( V_2 , 0 ) ;
return V_11 -> V_202 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
T_1 V_35 , V_203 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_204 ; V_49 ++ ) {
V_35 = V_11 -> V_36 . V_205 [ V_49 ] ;
if ( ! V_35 )
continue;
F_18 ( V_2 , V_35 , V_82 ) ;
if ( ! V_49 )
V_203 = V_11 -> V_206 . V_207 ;
else
V_203 = V_11 -> V_208 [ V_49 - 1 ] ;
if ( ! V_203 || ! ( F_2 ( V_2 , V_203 ) & V_209 ) )
continue;
F_31 ( V_2 , V_203 , 0 ,
V_210 ,
V_211 ) ;
}
V_35 = V_11 -> V_36 . V_212 ;
if ( V_35 )
F_18 ( V_2 , V_35 , V_43 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_143 , V_152 ;
T_1 V_213 ;
V_152 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_204 ; V_49 ++ ) {
T_1 V_214 [ 4 ] ;
V_143 = F_89 ( V_2 ,
V_11 -> V_36 . V_205 [ V_49 ] ,
V_214 , F_29 ( V_214 ) ) ;
if ( V_143 <= 0 )
continue;
V_213 = V_214 [ 0 ] ;
if ( ! V_152 ) {
V_11 -> V_206 . V_207 = V_213 ;
V_11 -> V_215 = V_11 -> V_36 . V_215 [ 0 ] ;
} else {
V_11 -> V_206 . V_208 = V_11 -> V_208 ;
if ( V_152 >= F_29 ( V_11 -> V_208 ) - 1 )
break;
V_11 -> V_208 [ V_152 - 1 ] = V_213 ;
}
V_152 ++ ;
}
if ( V_11 -> V_36 . V_212 ) {
V_213 = V_2 -> V_216 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_217 ; V_49 ++ , V_213 ++ ) {
unsigned int V_218 = F_2 ( V_2 , V_213 ) ;
if ( F_15 ( V_218 ) != V_219 )
continue;
if ( ! ( V_218 & V_220 ) )
continue;
if ( ! ( V_218 & V_221 ) )
continue;
V_143 = F_72 ( V_2 , V_213 ,
V_11 -> V_36 . V_212 ) ;
if ( V_143 >= 0 ) {
V_11 -> V_222 = V_213 ;
break;
}
}
}
}
static int F_90 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_34 ;
int V_143 ;
F_91 ( & V_2 -> V_223 ) ;
if ( V_11 -> V_224 )
V_34 = F_92 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_88 ) ;
else
V_34 = F_92 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_59 ) ;
V_7 -> V_225 = V_34 ;
V_143 = F_93 ( V_7 , V_9 ) ;
F_94 ( & V_2 -> V_223 ) ;
return V_143 ;
}
static int F_95 ( struct V_6 * V_7 , int V_226 ,
unsigned int V_227 , unsigned int T_2 * V_228 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_34 ;
int V_143 ;
F_91 ( & V_2 -> V_223 ) ;
if ( V_11 -> V_224 )
V_34 = F_92 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_88 ) ;
else
V_34 = F_92 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_59 ) ;
V_7 -> V_225 = V_34 ;
V_143 = F_96 ( V_7 , V_226 , V_227 , V_228 ) ;
F_94 ( & V_2 -> V_223 ) ;
return V_143 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_229 , bool V_230 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_143 = 0 ;
F_91 ( & V_2 -> V_223 ) ;
if ( V_230 && V_11 -> V_52 ) {
for ( V_49 = 0 ; V_49 < V_11 -> V_156 ; V_49 ++ ) {
V_7 -> V_225 =
F_92 ( V_11 -> V_26 [ V_49 ] ,
3 , 0 , V_59 ) ;
V_143 = V_229 ( V_7 , V_18 ) ;
if ( V_143 < 0 )
goto error;
}
} else {
V_49 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_224 )
V_7 -> V_225 =
F_92 ( V_11 -> V_32 [ V_49 ] ,
3 , 0 , V_88 ) ;
else
V_7 -> V_225 =
F_92 ( V_11 -> V_26 [ V_49 ] ,
3 , 0 , V_59 ) ;
V_143 = V_229 ( V_7 , V_18 ) ;
}
if ( V_143 >= 0 && V_230 )
F_24 ( V_2 , false ) ;
error:
F_94 ( & V_2 -> V_223 ) ;
return V_143 ;
}
static int F_98 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_97 ( V_7 , V_18 ,
V_231 , false ) ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_97 ( V_7 , V_18 ,
V_232 , true ) ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_97 ( V_7 , V_18 ,
V_233 , false ) ;
}
static int F_101 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_97 ( V_7 , V_18 ,
V_234 , true ) ;
}
static void F_24 ( struct V_1 * V_2 , bool V_46 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
if ( ! V_11 -> V_235 )
return;
if ( ! V_11 -> V_236 && ! V_46 )
return;
for ( V_49 = 0 ; V_49 < V_11 -> V_156 ; V_49 ++ ) {
int V_237 = V_11 -> V_52 ? 0 : V_49 ;
bool V_238 = false ;
T_1 V_3 ;
int V_239 , V_4 , V_57 ;
if ( V_11 -> V_236 &&
V_11 -> V_106 [ V_11 -> V_23 [ V_237 ] ] == V_11 -> V_240 )
V_238 = true ;
if ( ! V_238 && ! V_46 )
continue;
if ( V_11 -> V_224 ) {
V_3 = V_11 -> V_32 [ V_49 ] ;
V_239 = V_241 | V_242 ;
V_4 = V_88 ;
} else {
V_3 = V_11 -> V_26 [ V_49 ] ;
V_239 = V_241 | V_243 ;
V_4 = V_59 ;
}
V_57 = F_102 ( V_2 , V_3 , 1 , V_4 , 0 ) ;
if ( V_57 & 0x80 )
continue;
if ( V_238 )
V_57 |= 0x80 ;
F_31 ( V_2 , V_3 , 0 , V_210 ,
V_239 | V_57 ) ;
}
}
static int F_103 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . integer . V_20 [ 0 ] = ! V_11 -> V_236 ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 = ! V_18 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_34 == V_11 -> V_236 )
return 0 ;
V_11 -> V_236 = V_34 ;
F_24 ( V_2 , true ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! F_62 ( V_11 , L_26 ,
& V_244 ) )
return - V_140 ;
V_11 -> V_235 = 1 ;
V_11 -> V_236 = 0 ;
V_11 -> V_240 = V_3 ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 == V_246 )
F_105 ( V_2 , 0x12 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_112 = NULL ;
const struct V_63 * V_137 ;
int V_49 , V_247 , V_143 ;
unsigned int V_248 ;
T_1 V_3 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
V_143 = F_108 ( V_2 , V_11 -> V_66 [ V_49 ] ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_11 -> V_249 ) {
V_143 = F_108 ( V_2 , V_11 -> V_249 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_11 -> V_206 . V_207 ) {
V_143 = F_109 ( V_2 ,
V_11 -> V_206 . V_207 ,
V_11 -> V_206 . V_207 ,
V_11 -> V_250 [ 1 ] . V_251 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_11 -> V_252 ) {
V_143 = F_110 ( V_2 ,
& V_11 -> V_206 ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 -> V_206 . V_253 = 1 ;
}
}
if ( V_11 -> V_222 ) {
V_143 = F_111 ( V_2 , V_11 -> V_222 ) ;
if ( V_143 < 0 )
return V_143 ;
}
#ifdef F_112
if ( V_11 -> V_254 ) {
const struct V_63 * V_137 ;
for ( V_137 = V_255 ; V_137 -> V_135 ; V_137 ++ ) {
struct V_6 * V_112 ;
V_112 = F_113 ( V_137 , V_2 ) ;
if ( ! V_112 )
return - V_140 ;
V_112 -> V_225 = V_11 -> V_254 ;
V_143 = F_114 ( V_2 , 0 , V_112 ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
#endif
if ( ! V_11 -> V_252 &&
! F_42 ( V_2 , L_1 ) ) {
unsigned int V_256 [ 4 ] ;
F_115 ( V_2 , V_11 -> V_257 ,
V_88 , V_256 ) ;
V_143 = F_116 ( V_2 , L_1 ,
V_256 , V_258 ,
L_27 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( ! V_11 -> V_252 &&
! F_42 ( V_2 , L_28 ) ) {
V_143 = F_117 ( V_2 , L_28 ,
NULL , V_258 ,
L_29 ,
true , & V_11 -> V_259 . V_260 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_112 = F_42 ( V_2 , L_30 ) ;
if ( ! V_112 )
V_112 = F_42 ( V_2 , L_31 ) ;
for ( V_49 = 0 ; V_112 && V_49 < V_112 -> V_261 ; V_49 ++ ) {
V_143 = F_118 ( V_2 , V_112 , V_49 ,
F_12 ( V_11 , V_49 ) ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
if ( V_11 -> V_249 && V_11 -> V_26 ) {
const char * V_262 = V_112 ? V_112 -> V_13 . V_135 : NULL ;
for ( V_137 = V_11 -> V_249 ; V_137 -> V_135 ; V_137 ++ ) {
if ( V_262 && strcmp ( V_137 -> V_135 , V_262 ) == 0 )
continue;
V_112 = F_42 ( V_2 , V_137 -> V_135 ) ;
for ( V_49 = 0 ; V_112 && V_49 < V_112 -> V_261 ; V_49 ++ ) {
V_143 = F_118 ( V_2 , V_112 , V_49 ,
V_11 -> V_26 [ V_49 ] ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
}
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
for ( V_137 = V_11 -> V_66 [ V_49 ] ; V_137 -> V_135 ; V_137 ++ ) {
if ( V_137 -> V_263 != V_264 )
continue;
V_112 = F_42 ( V_2 , V_137 -> V_135 ) ;
if ( V_112 == NULL )
continue;
V_248 = V_137 -> V_265 ;
for ( V_247 = 0 ; V_247 < 4 ; V_247 ++ , V_248 >>= 8 ) {
V_3 = V_248 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_248 & 0xc0 ) {
case V_266 :
V_3 = V_11 -> V_36 . V_96 [ V_3 ] ;
break;
case V_267 :
V_3 = V_11 -> V_36 . V_97 [ V_3 ] ;
break;
case V_268 :
V_3 = V_11 -> V_36 . V_92 [ V_3 ] ;
break;
default:
continue;
}
V_143 = F_118 ( V_2 , V_112 , 0 , V_3 ) ;
if ( V_143 < 0 )
return V_143 ;
}
V_248 = V_137 -> V_225 ;
for ( V_247 = 0 ; V_247 < 4 ; V_247 ++ , V_248 >>= 8 ) {
V_3 = V_248 & 0xff ;
if ( V_3 == 0 )
continue;
V_143 = F_118 ( V_2 , V_112 , 0 , V_3 ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
}
F_119 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_51 ) {
int V_143 ;
int V_3 = V_11 -> V_36 . V_37 [ 1 ] . V_35 ;
V_143 = F_121 ( V_2 , V_3 , L_32 , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_122 ( V_2 , V_3 , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
}
return F_123 ( V_2 , & V_11 -> V_36 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_143 = F_107 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_120 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
F_125 ( V_2 , V_269 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_270 )
V_11 -> V_270 ( V_2 ) ;
F_30 ( V_2 ) ;
F_55 ( V_2 , V_11 -> V_199 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_125 ( V_2 , V_271 ) ;
F_130 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_132 ( V_2 , & V_11 -> V_272 , V_3 ) ;
}
static int F_133 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_134 ( V_2 , & V_11 -> V_206 , V_276 ,
V_274 ) ;
}
static int F_135 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int V_278 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_136 ( V_2 , & V_11 -> V_206 ,
V_277 , V_278 , V_276 ) ;
}
static int F_137 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_138 ( V_2 , & V_11 -> V_206 ) ;
}
static int F_139 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_140 ( V_2 , & V_11 -> V_206 ) ;
}
static int F_141 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int V_278 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_142 ( V_2 , & V_11 -> V_206 ,
V_277 , V_278 , V_276 ) ;
}
static int F_143 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_144 ( V_2 , & V_11 -> V_206 ) ;
}
static int F_145 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_146 ( V_2 , & V_11 -> V_206 ) ;
}
static int F_147 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int V_278 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_276 -> V_279 + 1 ] ,
V_277 , 0 , V_278 ) ;
return 0 ;
}
static int F_148 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_149 ( V_2 ,
V_11 -> V_26 [ V_276 -> V_279 + 1 ] ) ;
return 0 ;
}
static int F_150 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int V_278 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_277 ;
V_11 -> V_30 = V_278 ;
F_11 ( V_2 , V_11 -> V_28 , V_277 , 0 , V_278 ) ;
return 0 ;
}
static int F_151 ( struct V_273 * V_274 ,
struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_149 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_280 * V_281 = V_11 -> V_250 ;
const struct V_273 * V_122 ;
bool V_282 ;
int V_49 ;
V_2 -> V_283 = 1 ;
V_2 -> V_284 = V_281 ;
if ( V_11 -> V_252 )
goto V_285;
snprintf ( V_11 -> V_286 , sizeof( V_11 -> V_286 ) ,
L_33 , V_2 -> V_187 ) ;
V_281 -> V_135 = V_11 -> V_286 ;
if ( V_11 -> V_206 . V_287 > 0 ) {
V_122 = V_11 -> V_288 ;
if ( ! V_122 )
V_122 = & V_289 ;
V_281 -> V_290 [ V_291 ] = * V_122 ;
V_281 -> V_290 [ V_291 ] . V_3 = V_11 -> V_206 . V_292 [ 0 ] ;
V_281 -> V_290 [ V_291 ] . V_293 =
V_11 -> V_206 . V_294 ;
if ( V_11 -> V_36 . V_103 == V_104 &&
V_11 -> V_36 . V_145 == 2 )
V_281 -> V_290 [ V_291 ] . V_295 =
V_296 ;
}
if ( V_11 -> V_26 ) {
V_122 = V_11 -> V_297 ;
if ( ! V_122 ) {
if ( V_11 -> V_52 )
V_122 = & V_298 ;
else
V_122 = & V_299 ;
}
V_281 -> V_290 [ V_300 ] = * V_122 ;
V_281 -> V_290 [ V_300 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_301 ) {
V_281 -> V_290 [ V_291 ] . V_293 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_302 ; V_49 ++ ) {
if ( V_11 -> V_301 [ V_49 ] . V_303 > V_281 -> V_290 [ V_291 ] . V_293 ) {
V_281 -> V_290 [ V_291 ] . V_293 = V_11 -> V_301 [ V_49 ] . V_303 ;
}
}
}
V_285:
if ( V_11 -> V_206 . V_207 || V_11 -> V_222 ) {
snprintf ( V_11 -> V_304 ,
sizeof( V_11 -> V_304 ) ,
L_34 , V_2 -> V_187 ) ;
V_2 -> V_283 = 2 ;
V_2 -> V_208 = V_11 -> V_206 . V_208 ;
V_281 = V_11 -> V_250 + 1 ;
V_281 -> V_135 = V_11 -> V_304 ;
if ( V_11 -> V_215 )
V_281 -> V_251 = V_11 -> V_215 ;
else
V_281 -> V_251 = V_305 ;
if ( V_11 -> V_206 . V_207 ) {
V_122 = V_11 -> V_306 ;
if ( ! V_122 )
V_122 = & V_307 ;
V_281 -> V_290 [ V_291 ] = * V_122 ;
V_281 -> V_290 [ V_291 ] . V_3 = V_11 -> V_206 . V_207 ;
}
if ( V_11 -> V_222 ) {
V_122 = V_11 -> V_308 ;
if ( ! V_122 )
V_122 = & V_309 ;
V_281 -> V_290 [ V_300 ] = * V_122 ;
V_281 -> V_290 [ V_300 ] . V_3 = V_11 -> V_222 ;
}
V_2 -> V_310 = 1 ;
}
if ( V_11 -> V_252 )
return 0 ;
V_282 = ( V_11 -> V_156 > 1 ) &&
! V_11 -> V_52 && ! V_11 -> V_107 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_311 || V_282 ) {
V_2 -> V_283 = 3 ;
V_281 = V_11 -> V_250 + 2 ;
V_281 -> V_135 = V_11 -> V_286 ;
if ( V_11 -> V_311 ) {
V_122 = V_11 -> V_312 ;
if ( ! V_122 )
V_122 = & V_313 ;
V_281 -> V_290 [ V_291 ] = * V_122 ;
V_281 -> V_290 [ V_291 ] . V_3 =
V_11 -> V_311 ;
} else {
V_281 -> V_290 [ V_291 ] =
V_314 ;
V_281 -> V_290 [ V_291 ] . V_3 = 0 ;
}
if ( V_282 ) {
V_122 = V_11 -> V_315 ;
if ( ! V_122 )
V_122 = & V_316 ;
V_281 -> V_290 [ V_300 ] = * V_122 ;
V_281 -> V_290 [ V_300 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_281 -> V_290 [ V_300 ] . V_317 =
V_11 -> V_156 - 1 ;
} else {
V_281 -> V_290 [ V_300 ] =
V_314 ;
V_281 -> V_290 [ V_300 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_153 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_318 )
V_11 -> V_318 ( V_2 ) ;
F_154 ( V_2 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_138 . V_151 ) {
struct V_63 * V_112 = V_11 -> V_138 . V_151 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_138 . V_319 ; V_49 ++ )
F_44 ( V_112 [ V_49 ] . V_135 ) ;
}
F_155 ( & V_11 -> V_138 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_320 . V_151 ) {
struct V_321 * * V_322 = V_11 -> V_320 . V_151 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_320 . V_319 ; V_49 ++ )
F_44 ( V_322 [ V_49 ] ) ;
}
F_155 ( & V_11 -> V_320 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_119 ( V_2 ) ;
F_156 ( V_2 ) ;
F_158 ( & V_11 -> V_323 ) ;
F_44 ( V_11 ) ;
F_159 ( V_2 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_52 ( V_2 , false ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_153 ( V_2 ) ;
if ( V_11 && V_11 -> V_324 )
V_11 -> V_324 ( V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
F_54 ( 150 ) ;
V_2 -> V_325 . V_326 ( V_2 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_24 ( V_2 , true ) ;
F_130 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , const char * V_135 )
{
F_44 ( V_2 -> V_187 ) ;
V_2 -> V_187 = F_64 ( V_135 , V_114 ) ;
if ( ! V_2 -> V_187 ) {
F_157 ( V_2 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_166 ( struct V_1 * V_2 )
{
const struct V_327 * V_122 ;
for ( V_122 = V_328 ; V_122 -> V_130 ; V_122 ++ ) {
if ( V_122 -> V_130 != V_2 -> V_130 )
continue;
if ( ( F_86 ( V_2 ) & V_122 -> V_329 ) == V_122 -> V_330 )
return F_165 ( V_2 , V_122 -> V_135 ) ;
}
return 0 ;
}
static int F_167 ( struct V_10 * V_11 , int type , const char * V_135 ,
int V_331 , unsigned long V_34 )
{
struct V_63 * V_137 ;
V_137 = F_62 ( V_11 , V_135 , & V_332 [ type ] ) ;
if ( ! V_137 )
return - V_140 ;
V_137 -> V_56 = V_331 ;
if ( F_168 ( V_34 ) )
V_137 -> V_265 = V_333 ;
V_137 -> V_225 = V_34 ;
return 0 ;
}
static int F_169 ( struct V_10 * V_11 , int type ,
const char * V_334 , const char * V_4 ,
const char * V_335 , int V_331 , unsigned long V_34 )
{
char V_135 [ 32 ] ;
snprintf ( V_135 , sizeof( V_135 ) , L_35 , V_334 , V_4 , V_335 ) ;
return F_167 ( V_11 , type , V_135 , V_331 , V_34 ) ;
}
static const char * F_170 ( struct V_10 * V_11 , int V_336 ,
bool V_337 , int * V_56 )
{
struct V_141 * V_142 = & V_11 -> V_36 ;
* V_56 = 0 ;
if ( V_142 -> V_145 == 1 && ! V_11 -> V_338 &&
! V_142 -> V_147 && ! V_142 -> V_144 && V_337 )
return L_36 ;
switch ( V_142 -> V_103 ) {
case V_104 :
if ( V_142 -> V_145 == 1 )
return L_37 ;
if ( V_142 -> V_145 == 2 )
return V_336 ? L_38 : L_37 ;
break;
case V_146 :
if ( V_336 && V_11 -> V_338 )
break;
* V_56 = V_336 ;
return L_39 ;
default:
if ( V_142 -> V_145 == 1 && ! V_11 -> V_338 )
return L_40 ;
break;
}
if ( V_336 >= F_29 ( V_339 ) ) {
F_171 () ;
return L_40 ;
}
return V_339 [ V_336 ] ;
}
static void F_172 ( struct V_10 * V_11 , T_1 V_64 , int V_31 )
{
struct V_340 * V_151 ;
if ( V_11 -> V_341 >= F_29 ( V_11 -> V_342 ) - 1 )
return;
V_151 = V_11 -> V_342 + V_11 -> V_341 ;
V_151 -> V_3 = V_64 ;
V_151 -> V_4 = V_59 ;
V_151 -> V_31 = V_31 ;
V_11 -> V_341 ++ ;
V_11 -> V_272 . V_343 = V_11 -> V_342 ;
}
static int F_173 ( struct V_10 * V_11 , T_1 V_35 ,
const char * V_344 , int V_345 ,
int V_31 , T_1 V_346 )
{
int V_143 ;
V_143 = F_174 ( V_11 , V_347 , V_344 , V_345 ,
F_92 ( V_346 , 3 , V_31 , V_59 ) ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_175 ( V_11 , V_348 , V_344 , V_345 ,
F_92 ( V_346 , 3 , V_31 , V_59 ) ) ;
if ( V_143 < 0 )
return V_143 ;
F_172 ( V_11 , V_346 , V_31 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_349 = F_51 ( V_2 , V_3 ) ;
return ( V_349 & V_350 ) != 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_351 ;
T_1 * V_352 = V_11 -> V_157 ;
int V_353 = F_29 ( V_11 -> V_351 ) ;
int V_49 , V_152 = 0 ;
V_3 = V_2 -> V_216 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_217 ; V_49 ++ , V_3 ++ ) {
T_1 V_237 ;
unsigned int V_354 = F_2 ( V_2 , V_3 ) ;
int type = F_15 ( V_354 ) ;
if ( type != V_219 || ( V_354 & V_220 ) )
continue;
V_26 [ V_152 ] = V_3 ;
V_352 [ V_152 ] = V_3 ;
V_237 = V_3 ;
for (; ; ) {
int V_154 ;
type = F_15 ( F_2 ( V_2 , V_237 ) ) ;
if ( type == V_40 )
break;
if ( type == V_355 ) {
V_352 [ V_152 ] = V_237 ;
break;
}
V_154 = F_21 ( V_2 , V_237 ) ;
if ( V_154 > 1 ) {
V_352 [ V_152 ] = V_237 ;
break;
} else if ( V_154 != 1 )
break;
if ( F_89 ( V_2 , V_237 , & V_237 , 1 ) != 1 )
break;
}
if ( ++ V_152 >= V_353 )
break;
}
V_11 -> V_26 = V_11 -> V_351 ;
V_11 -> V_32 = V_11 -> V_157 ;
V_11 -> V_156 = V_152 ;
return V_152 ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_141 * V_142 = & V_11 -> V_36 ;
T_1 V_356 = V_11 -> V_357 ;
struct V_47 * V_48 = & V_11 -> V_153 [ 0 ] ;
int V_358 ;
int V_49 , V_359 , V_143 , V_31 , V_360 = 0 ;
const char * V_361 = NULL ;
V_358 = F_177 ( V_2 ) ;
if ( V_358 < 0 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
T_1 V_35 ;
const char * V_362 ;
V_35 = V_142 -> V_37 [ V_49 ] . V_35 ;
if ( ! F_176 ( V_2 , V_35 ) )
continue;
V_362 = F_179 ( V_2 , V_142 , V_49 ) ;
if ( V_11 -> V_51 && ! strcmp ( V_362 , L_41 ) )
V_362 = L_32 ;
if ( V_361 && ! strcmp ( V_362 , V_361 ) )
V_360 ++ ;
else
V_360 = 0 ;
V_361 = V_362 ;
if ( V_356 ) {
V_31 = F_72 ( V_2 , V_356 , V_35 ) ;
if ( V_31 >= 0 ) {
V_143 = F_173 ( V_11 , V_35 ,
V_362 , V_360 ,
V_31 , V_356 ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
for ( V_359 = 0 ; V_359 < V_358 ; V_359 ++ ) {
T_1 V_155 = F_12 ( V_11 , V_359 ) ;
V_31 = F_72 ( V_2 , V_155 , V_35 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_106 [ V_48 -> V_16 ] = V_35 ;
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
struct V_141 * V_142 = & V_11 -> V_36 ;
unsigned int V_166 ;
T_1 V_3 ;
if ( V_142 -> V_165 != 1 )
return 0 ;
V_166 = F_17 ( V_2 , V_142 -> V_37 [ 0 ] . V_35 ) ;
if ( F_75 ( V_166 ) != V_167 )
return 0 ;
if ( V_142 -> V_147 == 1 && V_142 -> V_103 == V_104 )
V_3 = V_142 -> V_92 [ 0 ] ;
else if ( V_142 -> V_145 == 1 && V_142 -> V_103 == V_146 )
V_3 = V_142 -> V_97 [ 0 ] ;
else
return 0 ;
if ( ! ( F_51 ( V_2 , V_3 ) & V_350 ) )
return 0 ;
V_142 -> V_37 [ 1 ] . V_35 = V_3 ;
V_142 -> V_37 [ 1 ] . type = V_62 ;
V_142 -> V_165 = 2 ;
V_11 -> V_51 = 1 ;
F_68 ( L_42 , V_3 ) ;
return 0 ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_363 )
{
F_18 ( V_2 , V_3 , V_363 ) ;
if ( F_183 ( V_2 , V_3 , V_88 ) )
F_31 ( V_2 , V_3 , 0 , V_210 ,
V_211 ) ;
}
static int F_184 ( int V_103 )
{
if ( V_103 == V_146 )
return V_44 ;
else
return V_82 ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
T_1 V_3 = V_142 -> V_37 [ V_49 ] . V_35 ;
if ( F_176 ( V_2 , V_3 ) ) {
F_26 ( V_2 , V_3 , V_142 -> V_37 [ V_49 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_209 )
F_31 ( V_2 , V_3 , 0 ,
V_210 ,
V_364 ) ;
}
}
if ( V_11 -> V_357 ) {
int V_152 = F_21 ( V_2 , V_11 -> V_357 ) ;
for ( V_49 = 0 ; V_49 < V_152 ; V_49 ++ )
F_31 ( V_2 , V_11 -> V_357 , 0 ,
V_210 ,
F_186 ( V_49 ) ) ;
}
}
static T_1 F_187 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_151 [ 5 ] ;
int V_49 , V_365 ;
if ( F_15 ( F_2 ( V_2 , V_3 ) ) == V_366 )
return V_3 ;
V_365 = F_89 ( V_2 , V_3 , V_151 , F_29 ( V_151 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_15 ( F_2 ( V_2 , V_151 [ V_49 ] ) ) == V_366 )
return V_151 [ V_49 ] ;
}
return 0 ;
}
static T_1 F_188 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_367 [ 5 ] ;
int V_365 = F_89 ( V_2 , V_35 , V_367 ,
F_29 ( V_367 ) ) ;
if ( V_365 != 1 ||
F_15 ( F_2 ( V_2 , V_367 [ 0 ] ) ) != V_355 )
return V_35 ;
return V_367 [ 0 ] ;
}
static T_1 F_189 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_203 )
{
T_1 V_64 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_89 ( V_2 , V_35 , V_64 , F_29 ( V_64 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_64 [ V_49 ] ) == V_203 )
return V_64 [ V_49 ] ;
}
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_203 )
{
T_1 V_64 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_89 ( V_2 , V_35 , V_64 , F_29 ( V_64 ) ) ;
if ( V_365 < 2 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_64 [ V_49 ] ) == V_203 ) {
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
if ( F_81 ( V_3 , V_11 -> V_206 . V_292 ,
F_29 ( V_11 -> V_368 ) ) ||
F_81 ( V_3 , V_11 -> V_206 . V_369 ,
F_29 ( V_11 -> V_206 . V_369 ) ) ||
F_81 ( V_3 , V_11 -> V_206 . V_370 ,
F_29 ( V_11 -> V_206 . V_370 ) ) )
return true ;
for ( V_49 = 0 ; V_49 < V_11 -> V_338 ; V_49 ++ ) {
if ( V_11 -> V_371 [ V_49 ] . V_203 == V_3 )
return true ;
}
return false ;
}
static T_1 F_193 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_367 [ 5 ] ;
int V_49 , V_365 ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_89 ( V_2 , V_35 , V_367 , F_29 ( V_367 ) ) ;
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
T_1 V_35 , T_1 V_203 )
{
T_1 V_367 [ 5 ] ;
int V_49 , V_365 ;
if ( ! V_35 || ! V_203 )
return false ;
V_35 = F_188 ( V_2 , V_35 ) ;
V_365 = F_89 ( V_2 , V_35 , V_367 , F_29 ( V_367 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
T_1 V_3 = F_187 ( V_2 , V_367 [ V_49 ] ) ;
if ( V_3 == V_203 )
return true ;
}
return false ;
}
static T_1 F_195 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_372 = F_188 ( V_2 , V_35 ) ;
T_1 V_3 , V_373 , V_367 [ 5 ] ;
int V_49 , V_365 = F_89 ( V_2 , V_372 , V_367 ,
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
T_1 V_3 = F_168 ( V_374 ) ;
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
T_1 V_203 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
unsigned int V_34 ;
int V_378 = 0 ;
V_3 = F_200 ( V_2 , V_35 , V_203 ) ;
if ( V_3 ) {
V_34 = F_92 ( V_3 , 3 , 0 , V_88 ) ;
if ( F_201 ( V_11 -> V_376 , V_3 ) )
V_378 += V_379 ;
else
F_202 ( V_11 -> V_376 , V_34 ) ;
} else
V_378 += V_379 ;
V_3 = F_203 ( V_2 , V_35 , V_203 ) ;
if ( V_3 ) {
unsigned int V_380 = F_15 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_380 == V_40 || V_380 == V_366 )
V_34 = F_92 ( V_3 , 3 , 0 , V_88 ) ;
else
V_34 = F_92 ( V_3 , 3 , 0 , V_59 ) ;
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
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_49 , V_247 ;
int V_378 = 0 ;
T_1 V_203 ;
if ( ! V_381 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_381 ; V_49 ++ ) {
T_1 V_35 = V_76 [ V_49 ] ;
if ( ! V_382 [ V_49 ] )
V_382 [ V_49 ] = F_193 ( V_2 , V_35 ) ;
if ( ! V_382 [ V_49 ] && ! V_49 ) {
for ( V_247 = 1 ; V_247 < V_381 ; V_247 ++ ) {
if ( F_194 ( V_2 , V_35 , V_382 [ V_247 ] ) ) {
V_382 [ 0 ] = V_382 [ V_247 ] ;
V_382 [ V_247 ] = 0 ;
break;
}
}
}
V_203 = V_382 [ V_49 ] ;
if ( ! V_203 ) {
if ( F_194 ( V_2 , V_35 , V_382 [ 0 ] ) )
V_203 = V_382 [ 0 ] ;
else if ( V_142 -> V_145 > V_49 &&
F_194 ( V_2 , V_35 ,
V_11 -> V_368 [ V_49 ] ) )
V_203 = V_11 -> V_368 [ V_49 ] ;
if ( V_203 ) {
if ( ! V_49 )
V_378 += V_384 -> V_385 ;
else if ( V_49 == 1 )
V_378 += V_384 -> V_386 ;
else
V_378 += V_384 -> V_387 ;
} else if ( F_194 ( V_2 , V_35 ,
V_11 -> V_368 [ 0 ] ) ) {
V_203 = V_11 -> V_368 [ 0 ] ;
V_378 += V_384 -> V_388 ;
} else if ( ! V_49 )
V_378 += V_384 -> V_389 ;
else
V_378 += V_384 -> V_390 ;
}
if ( V_203 )
V_378 += F_199 ( V_2 , V_35 , V_203 ) ;
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
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_49 , V_143 , V_378 ;
V_11 -> V_206 . V_287 = V_142 -> V_145 ;
V_11 -> V_206 . V_292 = V_11 -> V_368 ;
memset ( V_11 -> V_368 , 0 , sizeof( V_11 -> V_368 ) ) ;
memset ( V_11 -> V_206 . V_369 , 0 , sizeof( V_11 -> V_206 . V_369 ) ) ;
memset ( V_11 -> V_206 . V_370 , 0 , sizeof( V_11 -> V_206 . V_370 ) ) ;
V_11 -> V_338 = 0 ;
F_198 ( V_2 ) ;
V_378 = 0 ;
if ( V_393 ) {
bool V_395 ;
do {
V_395 = F_205 ( V_2 , V_142 -> V_145 ,
V_142 -> V_97 ,
V_11 -> V_368 ) ;
V_395 |= F_205 ( V_2 , V_142 -> V_147 ,
V_142 -> V_92 ,
V_11 -> V_206 . V_369 ) ;
V_395 |= F_205 ( V_2 , V_142 -> V_144 ,
V_142 -> V_96 ,
V_11 -> V_206 . V_370 ) ;
if ( V_394 && V_142 -> V_145 == 1 &&
V_142 -> V_103 != V_104 ) {
V_143 = F_207 ( V_2 , V_142 -> V_97 [ 0 ] , true , 0 ) ;
if ( ! V_143 )
V_395 = true ;
}
} while ( V_395 );
}
V_378 += F_204 ( V_2 , V_142 -> V_145 , V_142 -> V_97 ,
V_11 -> V_368 ,
& V_396 ) ;
V_11 -> V_206 . V_287 = 0 ;
for ( V_49 = 0 ; V_49 < V_142 -> V_145 ; V_49 ++ ) {
if ( V_11 -> V_368 [ V_49 ] )
V_11 -> V_206 . V_287 ++ ;
else {
memmove ( V_11 -> V_368 + V_49 ,
V_11 -> V_368 + V_49 + 1 ,
sizeof( T_1 ) * ( V_142 -> V_145 - V_49 - 1 ) ) ;
V_11 -> V_368 [ V_142 -> V_145 - 1 ] = 0 ;
}
}
if ( V_394 &&
V_142 -> V_145 == 1 && V_142 -> V_103 != V_104 ) {
V_143 = F_207 ( V_2 , V_142 -> V_97 [ 0 ] , false , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_142 -> V_103 != V_146 ) {
V_143 = F_204 ( V_2 , V_142 -> V_147 , V_142 -> V_92 ,
V_11 -> V_206 . V_369 ,
& V_397 ) ;
if ( V_143 < 0 )
return V_143 ;
V_378 += V_143 ;
}
if ( V_142 -> V_103 != V_104 ) {
V_143 = F_204 ( V_2 , V_142 -> V_144 ,
V_142 -> V_96 ,
V_11 -> V_206 . V_370 ,
& V_397 ) ;
if ( V_143 < 0 )
return V_143 ;
V_378 += V_143 ;
}
if ( V_142 -> V_145 == 1 && V_142 -> V_103 != V_104 ) {
V_143 = F_207 ( V_2 , V_142 -> V_97 [ 0 ] , false , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
V_378 += V_143 ;
}
if ( V_142 -> V_147 && V_142 -> V_103 == V_104 ) {
int V_398 = 0 ;
if ( V_142 -> V_145 >= 3 )
V_398 = 1 ;
V_143 = F_207 ( V_2 , V_142 -> V_92 [ 0 ] , false ,
V_398 ) ;
if ( V_143 < 0 )
return V_143 ;
V_378 += V_143 ;
}
if ( V_11 -> V_338 == 2 ) {
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ )
V_11 -> V_368 [ V_11 -> V_206 . V_287 ++ ] =
V_11 -> V_371 [ V_49 ] . V_203 ;
V_11 -> V_399 = 2 ;
} else if ( V_11 -> V_338 ) {
V_11 -> V_338 = 0 ;
V_378 += V_400 ;
}
return V_378 ;
}
static void F_208 ( struct V_10 * V_11 , struct V_141 * V_142 )
{
F_209 ( L_43 ,
V_142 -> V_97 [ 0 ] , V_142 -> V_97 [ 1 ] ,
V_142 -> V_97 [ 2 ] , V_142 -> V_97 [ 2 ] ,
V_11 -> V_206 . V_292 [ 0 ] ,
V_11 -> V_206 . V_292 [ 1 ] ,
V_11 -> V_206 . V_292 [ 2 ] ,
V_11 -> V_206 . V_292 [ 3 ] ) ;
if ( V_11 -> V_338 > 0 )
F_209 ( L_44 ,
V_11 -> V_338 ,
V_11 -> V_371 [ 0 ] . V_35 , V_11 -> V_371 [ 1 ] . V_35 ,
V_11 -> V_371 [ 0 ] . V_203 , V_11 -> V_371 [ 1 ] . V_203 ) ;
F_209 ( L_45 ,
V_142 -> V_92 [ 0 ] , V_142 -> V_92 [ 1 ] ,
V_142 -> V_92 [ 2 ] , V_142 -> V_92 [ 2 ] ,
V_11 -> V_206 . V_369 [ 0 ] ,
V_11 -> V_206 . V_369 [ 1 ] ,
V_11 -> V_206 . V_369 [ 2 ] ,
V_11 -> V_206 . V_369 [ 3 ] ) ;
F_209 ( L_46 ,
V_142 -> V_96 [ 0 ] , V_142 -> V_96 [ 1 ] ,
V_142 -> V_96 [ 2 ] , V_142 -> V_96 [ 3 ] ,
V_11 -> V_206 . V_370 [ 0 ] ,
V_11 -> V_206 . V_370 [ 1 ] ,
V_11 -> V_206 . V_370 [ 2 ] ,
V_11 -> V_206 . V_370 [ 3 ] ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
struct V_141 * V_401 ;
int V_402 = V_403 ;
int V_378 ;
bool V_393 = true , V_394 = true ;
bool V_404 = true , V_405 = true ;
bool V_406 = false ;
V_401 = F_211 ( sizeof( * V_401 ) , V_114 ) ;
if ( ! V_401 )
return - V_140 ;
* V_401 = * V_142 ;
for (; ; ) {
V_378 = F_206 ( V_2 , V_393 ,
V_394 ) ;
if ( V_378 < 0 ) {
F_44 ( V_401 ) ;
return V_378 ;
}
F_209 ( L_47 ,
V_142 -> V_103 , V_393 , V_394 ,
V_378 ) ;
F_208 ( V_11 , V_142 ) ;
if ( V_378 < V_402 ) {
V_402 = V_378 ;
* V_401 = * V_142 ;
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
if ( V_142 -> V_144 > 0 &&
V_142 -> V_103 == V_146 ) {
V_142 -> V_147 = V_142 -> V_145 ;
memcpy ( V_142 -> V_92 , V_142 -> V_97 ,
sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_145 = V_142 -> V_144 ;
memcpy ( V_142 -> V_97 , V_142 -> V_96 ,
sizeof( V_142 -> V_96 ) ) ;
V_142 -> V_144 = 0 ;
memset ( V_142 -> V_96 , 0 , sizeof( V_142 -> V_96 ) ) ;
V_142 -> V_103 = V_104 ;
V_393 = true ;
continue;
}
if ( V_142 -> V_147 > 0 &&
V_142 -> V_103 == V_104 ) {
V_142 -> V_144 = V_142 -> V_145 ;
memcpy ( V_142 -> V_96 , V_142 -> V_97 ,
sizeof( V_142 -> V_96 ) ) ;
V_142 -> V_145 = V_142 -> V_147 ;
memcpy ( V_142 -> V_97 , V_142 -> V_92 ,
sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_147 = 0 ;
memset ( V_142 -> V_92 , 0 , sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_103 = V_146 ;
V_393 = true ;
continue;
}
break;
}
if ( V_378 ) {
* V_142 = * V_401 ;
F_206 ( V_2 , V_404 , V_405 ) ;
}
F_209 ( L_48 ,
V_142 -> V_103 , V_404 , V_405 ) ;
F_208 ( V_11 , V_142 ) ;
if ( V_142 -> V_97 [ 0 ] )
V_11 -> V_257 =
F_200 ( V_2 , V_142 -> V_97 [ 0 ] ,
V_11 -> V_206 . V_292 [ 0 ] ) ;
F_198 ( V_2 ) ;
F_44 ( V_401 ) ;
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
V_34 = F_92 ( V_3 , V_407 , 0 , V_88 ) ;
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
V_34 = F_92 ( V_3 , V_407 , 0 , V_88 ) ;
} else if ( F_21 ( V_2 , V_3 ) == 1 ) {
type = V_348 ;
V_34 = F_92 ( V_3 , V_407 , 0 , V_59 ) ;
} else {
type = V_409 ;
V_34 = F_92 ( V_3 , V_407 , 2 , V_59 ) ;
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
T_1 V_35 , T_1 V_203 )
{
T_1 V_64 = F_189 ( V_2 , V_35 , V_203 ) ;
if ( F_183 ( V_2 , V_35 , V_88 ) )
return V_35 ;
else if ( V_64 && F_183 ( V_2 , V_64 , V_59 ) )
return V_64 ;
else if ( F_183 ( V_2 , V_203 , V_88 ) )
return V_203 ;
return 0 ;
}
static T_1 F_200 ( struct V_1 * V_2 ,
T_1 V_35 , T_1 V_203 )
{
T_1 V_64 = F_189 ( V_2 , V_35 , V_203 ) ;
if ( F_216 ( V_2 , V_203 , V_88 ) )
return V_203 ;
else if ( F_216 ( V_2 , V_64 , V_88 ) )
return V_64 ;
else if ( F_216 ( V_2 , V_35 , V_88 ) )
return V_35 ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 , V_143 , V_410 ;
V_410 = V_142 -> V_145 ;
if ( V_11 -> V_338 > 0 && V_142 -> V_145 < 3 )
V_410 += V_11 -> V_338 ;
for ( V_49 = 0 ; V_49 < V_410 ; V_49 ++ ) {
const char * V_135 ;
int V_56 ;
T_1 V_203 , V_35 ;
T_1 V_411 , V_412 ;
V_203 = V_11 -> V_206 . V_292 [ V_49 ] ;
if ( ! V_203 )
continue;
if ( V_49 >= V_142 -> V_145 ) {
V_35 = V_11 -> V_371 [ V_49 - 1 ] . V_35 ;
V_56 = 0 ;
V_135 = V_339 [ V_49 ] ;
} else {
V_35 = V_142 -> V_97 [ V_49 ] ;
V_135 = F_170 ( V_11 , V_49 , true , & V_56 ) ;
}
V_411 = F_203 ( V_2 , V_35 , V_203 ) ;
V_412 = F_200 ( V_2 , V_35 , V_203 ) ;
if ( ! V_135 || ! strcmp ( V_135 , L_49 ) ) {
V_143 = F_212 ( V_2 , L_50 , 0 , V_412 , 1 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_212 ( V_2 , L_51 , 0 , V_412 , 2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_214 ( V_2 , L_50 , 0 , V_411 , 1 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_214 ( V_2 , L_51 , 0 , V_411 , 2 ) ;
if ( V_143 < 0 )
return V_143 ;
} else {
V_143 = F_213 ( V_2 , V_135 , V_56 , V_412 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_215 ( V_2 , V_135 , V_56 , V_411 ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_203 , const char * V_334 ,
int V_331 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_411 , V_412 ;
int V_143 ;
if ( ! V_203 ) {
unsigned int V_34 ;
if ( ! ( F_2 ( V_2 , V_35 ) & V_209 ) )
return 0 ;
V_34 = F_92 ( V_35 , 3 , 0 , V_88 ) ;
if ( F_201 ( V_11 -> V_377 , V_34 ) )
return 0 ;
F_202 ( V_11 -> V_377 , V_34 ) ;
return F_175 ( V_11 , V_348 , V_334 , V_331 , V_34 ) ;
}
V_411 = F_203 ( V_2 , V_35 , V_203 ) ;
V_412 = F_200 ( V_2 , V_35 , V_203 ) ;
V_143 = F_213 ( V_2 , V_334 , V_331 , V_412 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_215 ( V_2 , V_334 , V_331 , V_411 ) ;
if ( V_143 < 0 )
return V_143 ;
return 0 ;
}
static struct V_321 * F_219 ( struct V_1 * V_2 ,
unsigned int V_152 ,
struct V_413 * V_414 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_321 * * V_415 , * V_322 ;
V_415 = F_63 ( & V_11 -> V_320 ) ;
if ( ! V_415 )
return NULL ;
V_322 = F_43 ( sizeof( * V_322 ) + sizeof( long ) * ( V_152 + 1 ) , V_114 ) ;
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
char V_135 [ 32 ] ;
int V_49 , V_154 , V_143 ;
if ( ! V_75 || ! V_76 [ 0 ] )
return 0 ;
if ( V_75 == 1 ) {
T_1 V_203 = * V_382 ;
if ( ! V_203 )
V_203 = V_11 -> V_206 . V_292 [ 0 ] ;
return F_218 ( V_2 , * V_76 , V_203 , V_334 , 0 ) ;
}
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_203 ;
if ( V_382 [ V_75 - 1 ] )
V_203 = V_382 [ V_49 ] ;
else
V_203 = 0 ;
if ( V_75 == 2 && V_49 == 1 && ! strcmp ( V_334 , L_37 ) ) {
V_143 = F_218 ( V_2 , V_76 [ V_49 ] , V_203 ,
L_38 , 0 ) ;
} else if ( V_75 >= 3 ) {
snprintf ( V_135 , sizeof( V_135 ) , L_52 ,
V_334 , V_339 [ V_49 ] ) ;
V_143 = F_218 ( V_2 , V_76 [ V_49 ] , V_203 ,
V_135 , 0 ) ;
} else {
V_143 = F_218 ( V_2 , V_76 [ V_49 ] , V_203 ,
V_334 , V_49 ) ;
}
if ( V_143 < 0 )
return V_143 ;
}
if ( V_382 [ V_75 - 1 ] )
return 0 ;
V_322 = F_219 ( V_2 , V_75 , & V_416 ) ;
if ( ! V_322 )
return - V_140 ;
V_154 = 0 ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
T_1 V_412 ;
if ( ! V_76 [ V_49 ] || ! V_382 [ V_49 ] )
continue;
V_412 = F_200 ( V_2 , V_76 [ V_49 ] , V_382 [ V_49 ] ) ;
if ( V_412 )
V_322 -> V_417 [ V_154 ++ ] =
F_92 ( V_412 , 3 , 0 , V_88 ) ;
}
if ( V_154 ) {
snprintf ( V_135 , sizeof( V_135 ) , L_53 , V_334 ) ;
V_143 = F_167 ( V_11 , V_418 , V_135 , 0 , ( long ) V_322 ) ;
if ( V_143 < 0 )
return V_143 ;
}
return 0 ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_220 ( V_2 , V_11 -> V_36 . V_147 ,
V_11 -> V_36 . V_92 ,
V_11 -> V_206 . V_369 ,
L_39 ) ;
}
static int F_222 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_220 ( V_2 , V_11 -> V_36 . V_144 ,
V_11 -> V_36 . V_96 ,
V_11 -> V_206 . V_370 ,
L_37 ) ;
}
static void F_223 ( struct V_1 * V_2 ,
T_1 V_35 , int V_363 ,
T_1 V_203 )
{
int V_49 , V_365 ;
T_1 V_3 , V_64 = 0 ;
T_1 V_367 [ V_419 ] ;
F_182 ( V_2 , V_35 , V_363 ) ;
V_3 = F_188 ( V_2 , V_35 ) ;
V_365 = F_89 ( V_2 , V_3 , V_367 , F_29 ( V_367 ) ) ;
for ( V_49 = 0 ; V_49 < V_365 ; V_49 ++ ) {
if ( F_187 ( V_2 , V_367 [ V_49 ] ) != V_203 )
continue;
V_64 = V_367 [ V_49 ] ;
break;
}
if ( ! V_64 )
return;
if ( V_365 > 1 )
F_31 ( V_2 , V_3 , 0 , V_60 , V_49 ) ;
if ( F_183 ( V_2 , V_64 , V_59 ) ) {
F_31 ( V_2 , V_64 , 0 , V_210 ,
F_224 ( 0 ) ) ;
F_31 ( V_2 , V_64 , 0 , V_210 ,
F_224 ( 1 ) ) ;
}
V_3 = F_200 ( V_2 , V_35 , V_203 ) ;
if ( V_3 )
F_31 ( V_2 , V_3 , 0 , V_210 ,
V_420 ) ;
V_3 = F_203 ( V_2 , V_35 , V_203 ) ;
if ( V_3 == V_64 && F_183 ( V_2 , V_203 , V_88 ) )
F_31 ( V_2 , V_203 , 0 , V_210 ,
V_420 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_363 = F_184 ( V_11 -> V_36 . V_103 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 <= V_421 ; V_49 ++ ) {
T_1 V_3 = V_11 -> V_36 . V_97 [ V_49 ] ;
if ( V_3 )
F_223 ( V_2 , V_3 , V_363 ,
V_11 -> V_206 . V_292 [ V_49 ] ) ;
}
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
T_1 V_35 , V_203 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_147 ; V_49 ++ ) {
if ( V_11 -> V_36 . V_103 == V_146 )
break;
V_35 = V_11 -> V_36 . V_92 [ V_49 ] ;
if ( ! V_35 )
break;
V_203 = V_11 -> V_206 . V_369 [ V_49 ] ;
if ( ! V_203 ) {
if ( V_49 > 0 && V_11 -> V_206 . V_369 [ 0 ] )
V_203 = V_11 -> V_206 . V_369 [ 0 ] ;
else
V_203 = V_11 -> V_206 . V_292 [ 0 ] ;
}
F_223 ( V_2 , V_35 , V_44 , V_203 ) ;
}
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_144 ; V_49 ++ ) {
if ( V_11 -> V_36 . V_103 == V_104 )
break;
V_35 = V_11 -> V_36 . V_96 [ V_49 ] ;
if ( ! V_35 )
break;
V_203 = V_11 -> V_206 . V_370 [ V_49 ] ;
if ( ! V_203 ) {
if ( V_49 > 0 && V_11 -> V_206 . V_370 [ 0 ] )
V_203 = V_11 -> V_206 . V_370 [ 0 ] ;
else
V_203 = V_11 -> V_206 . V_292 [ 0 ] ;
}
F_223 ( V_2 , V_35 , V_82 , V_203 ) ;
}
}
static bool F_227 ( struct V_1 * V_2 ,
unsigned int V_422 , T_1 V_3 )
{
unsigned int V_166 , V_354 ;
V_166 = F_17 ( V_2 , V_3 ) ;
if ( F_16 ( V_166 ) != V_423 )
return false ;
if ( V_422 && F_228 ( V_166 ) != V_422 )
return false ;
V_354 = F_51 ( V_2 , V_3 ) ;
if ( ! ( V_354 & V_424 ) )
return false ;
return true ;
}
static int F_207 ( struct V_1 * V_2 ,
T_1 V_425 ,
bool V_426 , int V_398 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
int type , V_49 , V_247 , V_382 , V_75 , V_427 ;
unsigned int V_166 = F_17 ( V_2 , V_425 ) ;
unsigned int V_422 = F_228 ( V_166 ) ;
int V_378 = 0 ;
V_427 = V_11 -> V_338 ;
if ( V_427 >= 2 )
goto V_428;
V_75 = 0 ;
for ( type = V_170 ; type >= V_62 ; type -- ) {
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
if ( V_142 -> V_37 [ V_49 ] . type != type )
continue;
if ( F_227 ( V_2 , V_422 ,
V_142 -> V_37 [ V_49 ] . V_35 ) )
V_75 ++ ;
}
}
if ( V_75 < 2 )
goto V_428;
V_382 = V_11 -> V_206 . V_287 ;
for ( type = V_170 ; type >= V_62 ; type -- ) {
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
T_1 V_3 = V_142 -> V_37 [ V_49 ] . V_35 ;
T_1 V_203 = 0 ;
if ( V_142 -> V_37 [ V_49 ] . type != type )
continue;
if ( ! F_227 ( V_2 , V_422 , V_3 ) )
continue;
for ( V_247 = 0 ; V_247 < V_11 -> V_338 ; V_247 ++ ) {
if ( V_3 == V_11 -> V_371 [ V_247 ] . V_35 )
break;
}
if ( V_247 < V_11 -> V_338 )
continue;
if ( V_398 && V_398 + V_11 -> V_338 < V_382 ) {
V_203 = V_11 -> V_368 [ V_398 + V_11 -> V_338 ] ;
if ( ! F_194 ( V_2 , V_3 , V_203 ) )
V_203 = 0 ;
}
if ( V_426 )
V_203 = F_195 ( V_2 , V_3 ) ;
else if ( ! V_203 )
V_203 = F_193 ( V_2 , V_3 ) ;
if ( ! V_203 ) {
V_378 ++ ;
continue;
}
V_11 -> V_371 [ V_11 -> V_338 ] . V_35 = V_3 ;
V_11 -> V_371 [ V_11 -> V_338 ] . V_203 = V_203 ;
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
V_9 -> type = V_429 ;
V_9 -> V_261 = 1 ;
V_9 -> V_20 . V_21 . V_55 = V_11 -> V_338 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_338 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_338 ;
sprintf ( V_9 -> V_20 . V_21 . V_135 , L_54 ,
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
static int F_231 ( struct V_1 * V_2 , int V_31 , bool V_430 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_371 [ V_31 ] . V_35 ;
if ( ! V_11 -> V_371 [ V_31 ] . V_431 )
V_11 -> V_371 [ V_31 ] . V_431 =
F_32 ( V_2 , V_3 , 0 ,
V_86 , 0 ) ;
if ( V_430 ) {
F_232 ( V_2 , V_3 , V_82 ) ;
if ( F_2 ( V_2 , V_3 ) & V_209 )
F_22 ( V_2 , V_3 , V_88 , 0 ,
V_58 , 0 ) ;
F_190 ( V_2 , V_3 , V_11 -> V_371 [ V_31 ] . V_203 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_209 )
F_22 ( V_2 , V_3 , V_88 , 0 ,
V_58 , V_58 ) ;
F_232 ( V_2 , V_3 ,
V_11 -> V_371 [ V_31 ] . V_431 ) ;
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
return - V_134 ;
if ( V_336 == ( V_11 -> V_399 - 1 ) / 2 )
return 0 ;
V_11 -> V_399 = ( V_336 + 1 ) * 2 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_338 ; V_49 ++ )
F_231 ( V_2 , V_49 , V_49 < V_336 ) ;
V_11 -> V_206 . V_294 = F_234 ( V_11 -> V_399 ,
V_11 -> V_432 ) ;
if ( V_11 -> V_433 )
V_11 -> V_206 . V_287 = V_11 -> V_206 . V_294 / 2 ;
return 1 ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_338 > 0 ) {
if ( ! F_62 ( V_11 , L_55 ,
& V_434 ) )
return - V_140 ;
}
return 0 ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_47 * V_48 ;
T_1 V_26 [ F_29 ( V_11 -> V_351 ) ] ;
T_1 V_32 [ F_29 ( V_11 -> V_351 ) ] ;
int V_49 , V_154 , V_152 ;
V_48 = V_11 -> V_15 ;
if ( ! V_48 )
return;
if ( V_11 -> V_52 )
return;
V_435:
V_152 = 0 ;
for ( V_154 = 0 ; V_154 < V_11 -> V_156 ; V_154 ++ ) {
T_1 V_155 = V_11 -> V_157 [ V_154 ] ;
int V_50 = F_21 ( V_2 , V_155 ) ;
for ( V_49 = 0 ; V_49 < V_48 -> V_16 ; V_49 ++ ) {
T_1 V_35 = V_11 -> V_106 [ V_49 ] ;
if ( V_35 ) {
if ( F_72 ( V_2 , V_155 , V_35 ) < 0 )
break;
} else if ( V_50 <= V_48 -> V_55 [ V_49 ] . V_56 )
break;
}
if ( V_49 >= V_48 -> V_16 ) {
V_26 [ V_152 ] = V_11 -> V_351 [ V_154 ] ;
V_32 [ V_152 ++ ] = V_155 ;
}
}
if ( ! V_152 ) {
if ( ! F_71 ( V_2 ) ) {
if ( V_11 -> V_51 ) {
V_11 -> V_51 = 0 ;
V_11 -> V_153 [ 0 ] . V_16 = 1 ;
goto V_435;
}
F_79 ( V_436 L_56
L_57 ,
V_2 -> V_187 , V_11 -> V_351 [ 0 ] ) ;
V_11 -> V_156 = 1 ;
V_11 -> V_107 = 0 ;
return;
}
} else if ( V_152 != V_11 -> V_156 ) {
memcpy ( V_11 -> V_351 , V_26 ,
V_152 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_157 , V_32 ,
V_152 * sizeof( T_1 ) ) ;
V_11 -> V_156 = V_152 ;
}
if ( V_11 -> V_107 )
F_73 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 || V_11 -> V_51 )
V_11 -> V_156 = 1 ;
}
static void F_237 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_183 ( V_2 , V_3 , V_59 ) ) {
F_31 ( V_2 , V_3 , 0 ,
V_210 ,
F_186 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_183 ( V_2 , V_3 , V_88 ) )
F_31 ( V_2 , V_3 , 0 ,
V_210 ,
V_364 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_359 , V_152 ;
for ( V_359 = 0 ; V_359 < V_11 -> V_156 ; V_359 ++ )
F_237 ( V_2 , V_359 ) ;
if ( V_11 -> V_52 )
V_152 = 1 ;
else
V_152 = V_11 -> V_156 ;
for ( V_359 = 0 ; V_359 < V_152 ; V_359 ++ )
F_20 ( V_2 , V_359 , V_11 -> V_23 [ V_359 ] , true ) ;
}
static int F_239 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_49 , V_143 ;
int V_360 = 0 ;
T_1 V_3 ;
const char * V_361 = NULL ;
for ( V_49 = 0 ; V_49 < V_142 -> V_165 ; V_49 ++ ) {
if ( V_142 -> V_37 [ V_49 ] . type > V_62 )
break;
V_3 = V_142 -> V_37 [ V_49 ] . V_35 ;
if ( F_2 ( V_2 , V_3 ) & V_437 ) {
const char * V_362 ;
char V_438 [ 32 ] ;
V_362 = F_179 ( V_2 , V_142 , V_49 ) ;
if ( V_11 -> V_51 && ! strcmp ( V_362 , L_41 ) )
V_362 = L_32 ;
if ( V_361 && ! strcmp ( V_362 , V_361 ) )
V_360 ++ ;
else
V_360 = 0 ;
V_361 = V_362 ;
snprintf ( V_438 , sizeof( V_438 ) ,
L_58 , V_362 ) ;
V_143 = F_167 ( V_11 , V_347 ,
V_438 , V_360 ,
F_92 ( V_3 , 3 , 0 , V_59 ) ) ;
if ( V_143 < 0 )
return V_143 ;
}
}
return 0 ;
}
static void F_240 ( struct V_1 * V_2 , T_1 V_155 ,
int V_31 )
{
if ( F_15 ( F_2 ( V_2 , V_155 ) ) == V_53 ) {
F_22 ( V_2 , V_155 , V_59 , V_31 ,
V_58 , 0 ) ;
} else if ( F_21 ( V_2 , V_155 ) > 1 ) {
F_23 ( V_2 , V_155 , 0 ,
V_60 , V_31 ) ;
}
}
static int F_241 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
if ( ! V_35 )
return 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_156 ; V_49 ++ ) {
T_1 V_155 = F_12 ( V_11 , V_49 ) ;
int V_31 ;
V_31 = F_72 ( V_2 , V_155 , V_35 ) ;
if ( V_31 < 0 )
continue;
F_240 ( V_2 , V_155 , V_31 ) ;
return V_49 ;
}
return - 1 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_36 . V_165 ; V_49 ++ )
F_241 ( V_2 , V_11 -> V_36 . V_37 [ V_49 ] . V_35 ) ;
}
static void F_242 ( struct V_1 * V_2 )
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
V_11 -> V_224 = 1 ;
}
if ( V_11 -> V_156 > 0 ) {
int V_445 = 0 ;
int V_358 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_445 = 1 ;
if ( V_11 -> V_107 ) {
V_358 = 1 ;
V_445 = 0 ;
} else if ( V_11 -> V_52 )
V_358 = 1 ;
if ( ! V_358 ) {
if ( V_11 -> V_156 > 3 )
V_11 -> V_156 = 3 ;
else if ( ! V_11 -> V_156 )
return;
V_358 = V_11 -> V_156 ;
}
V_11 -> V_249 = V_354 [ V_445 ] [ V_358 - 1 ] ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
F_225 ( V_2 ) ;
F_226 ( V_2 ) ;
F_185 ( V_2 ) ;
F_238 ( V_2 ) ;
F_87 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static inline int F_243 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_446 * V_447 ;
V_447 = F_244 ( V_2 -> V_183 -> V_184 , V_448 ) ;
if ( V_447 )
return V_447 -> V_20 ;
return V_11 -> V_175 . V_180 ;
}
static int F_245 ( struct V_1 * V_2 ,
const T_1 * V_449 ,
const T_1 * V_450 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_141 * V_142 = & V_11 -> V_36 ;
int V_143 ;
V_143 = F_246 ( V_2 , V_142 , V_449 ,
V_11 -> V_451 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_142 -> V_145 ) {
if ( V_142 -> V_204 || V_142 -> V_212 ) {
V_11 -> V_206 . V_294 = 2 ;
V_11 -> V_252 = 1 ;
goto V_452;
}
return 0 ;
}
if ( ! V_11 -> V_453 &&
V_142 -> V_103 == V_104 &&
V_142 -> V_145 <= V_142 -> V_147 ) {
V_142 -> V_144 = V_142 -> V_145 ;
memcpy ( V_142 -> V_96 , V_142 -> V_97 ,
sizeof( V_142 -> V_96 ) ) ;
V_142 -> V_145 = V_142 -> V_147 ;
memcpy ( V_142 -> V_97 , V_142 -> V_92 , sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_147 = 0 ;
memset ( V_142 -> V_92 , 0 , sizeof( V_142 -> V_92 ) ) ;
V_142 -> V_103 = V_146 ;
}
V_143 = F_210 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_235 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_217 ( V_2 , V_142 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_221 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_222 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_181 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_178 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_142 -> V_103 == V_104 )
V_11 -> V_432 = V_142 -> V_145 * 2 ;
else
V_11 -> V_432 = V_142 -> V_144 * 2 ;
if ( V_11 -> V_338 > 0 )
V_11 -> V_206 . V_294 = F_234 ( V_11 -> V_399 ,
V_11 -> V_432 ) ;
else
V_11 -> V_206 . V_294 = V_11 -> V_206 . V_287 * 2 ;
V_452:
F_88 ( V_2 ) ;
if ( ! V_11 -> V_252 )
F_236 ( V_2 ) ;
if ( V_450 )
F_83 ( V_2 , V_450 ) ;
if ( ! V_11 -> V_252 ) {
V_143 = F_76 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_239 ( V_2 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_11 -> V_138 . V_151 )
F_27 ( V_11 , V_11 -> V_138 . V_151 ) ;
if ( ! V_11 -> V_252 && ! V_11 -> V_249 )
F_242 ( V_2 ) ;
return 1 ;
}
static int F_247 ( struct V_1 * V_2 , T_1 V_357 )
{
struct V_10 * V_11 = F_43 ( sizeof( * V_11 ) , V_114 ) ;
int V_143 ;
if ( ! V_11 )
return - V_140 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_454 = 1 ;
V_11 -> V_357 = V_357 ;
F_248 ( & V_11 -> V_323 ) ;
F_249 ( & V_11 -> V_138 , sizeof( struct V_63 ) , 32 ) ;
F_249 ( & V_11 -> V_320 , sizeof( struct V_321 * ) , 8 ) ;
V_143 = F_166 ( V_2 ) ;
if ( V_143 < 0 ) {
F_44 ( V_11 ) ;
return V_143 ;
}
return 0 ;
}
static int F_250 ( struct V_1 * V_2 )
{
static const T_1 V_455 [] = { 0x1d , 0 } ;
static const T_1 V_456 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_245 ( V_2 , V_455 , V_456 ) ;
}
static void F_251 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 == V_246 )
F_69 ( V_2 , 0x21 , V_457 , F_41 ) ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_433 = 1 ;
F_253 ( V_2 , V_458 , V_459 ,
V_460 ) ;
F_125 ( V_2 , V_461 ) ;
V_143 = F_250 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
V_2 -> V_325 . V_463 = F_45 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_256 ( struct V_1 * V_2 )
{
static const T_1 V_464 [] = { 0x17 , 0 } ;
static const T_1 V_465 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_245 ( V_2 , V_464 , V_465 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_31 ( V_2 , 0x01 , 0 , V_466 ,
V_11 -> V_94 ) ;
}
static void F_258 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 == V_246 ) {
V_11 -> V_99 = F_257 ;
V_11 -> V_102 = 1 ;
V_11 -> V_45 = 1 ;
V_11 -> V_36 . V_92 [ 0 ] = 0x0f ;
F_69 ( V_2 , 0x0f , V_148 ,
F_38 ) ;
F_259 ( & V_11 -> V_323 , V_124 ) ;
}
}
static void F_260 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_467 V_468 [] = {
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
switch ( V_173 ) {
case V_461 :
F_261 ( V_2 , V_468 ) ;
break;
case V_246 :
V_11 -> V_199 = V_469 ;
break;
}
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x07 ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
F_253 ( V_2 , NULL , V_470 , V_471 ) ;
F_125 ( V_2 , V_461 ) ;
V_143 = F_256 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x07 , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
V_11 -> V_318 = F_53 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static void F_263 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 != V_271 )
return;
F_49 ( V_2 ) ;
}
static void F_264 ( struct V_1 * V_2 , int V_35 , int V_472 )
{
unsigned int V_473 , V_474 , V_475 ;
V_473 = F_32 ( V_2 , V_2 -> V_476 , 0 ,
V_477 , 0 ) ;
if ( ! V_472 )
V_473 |= ( 1 << V_35 ) ;
else
V_473 &= ~ ( 1 << V_35 ) ;
V_474 = F_32 ( V_2 , V_2 -> V_476 , 0 ,
V_478 , 0 ) ;
V_474 |= ( 1 << V_35 ) ;
V_475 = F_32 ( V_2 , V_2 -> V_476 , 0 ,
V_479 , 0 ) ;
V_475 |= ( 1 << V_35 ) ;
F_31 ( V_2 , V_2 -> V_476 , 0 ,
V_480 , V_474 ) ;
F_31 ( V_2 , V_2 -> V_476 , 0 ,
V_481 , V_475 ) ;
F_54 ( 1 ) ;
F_31 ( V_2 , V_2 -> V_476 , 0 ,
V_466 , V_473 ) ;
}
static void F_265 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 != V_271 )
return;
F_264 ( V_2 , 0 , 0 ) ;
F_264 ( V_2 , 1 , 0 ) ;
}
static void F_266 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 == V_461 ) {
T_1 V_482 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_483 [ 2 ] = { 0x0e , 0x0f } ;
F_267 ( V_2 , 0x14 , 2 , V_482 ) ;
F_267 ( V_2 , 0x15 , 2 , V_482 ) ;
F_267 ( V_2 , 0x18 , 2 , V_483 ) ;
F_267 ( V_2 , 0x1a , 2 , V_483 ) ;
} else if ( V_173 == V_246 ) {
T_1 V_214 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_267 ( V_2 , 0x14 , 5 , V_214 ) ;
F_267 ( V_2 , 0x15 , 5 , V_214 ) ;
F_267 ( V_2 , 0x18 , 5 , V_214 ) ;
F_267 ( V_2 , 0x1a , 5 , V_214 ) ;
}
}
static void F_268 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_484 [ 2 ] = { 0x14 , 0x15 } ;
int V_49 ;
if ( V_173 != V_271 )
return;
for ( V_49 = 0 ; V_49 < F_29 ( V_484 ) ; V_49 ++ ) {
unsigned int V_34 = F_17 ( V_2 , V_484 [ V_49 ] ) ;
if ( F_269 ( V_34 ) != V_485 )
continue;
V_34 = F_32 ( V_2 , V_484 [ V_49 ] , 0 ,
V_86 , 0 ) ;
V_34 |= V_486 ;
F_18 ( V_2 , V_484 [ V_49 ] , V_34 ) ;
V_11 -> V_85 = 1 ;
break;
}
}
static void F_270 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_484 [ 2 ] = { 0x18 , 0x1a } ;
int V_49 ;
if ( V_173 != V_271 )
return;
for ( V_49 = 0 ; V_49 < F_29 ( V_484 ) ; V_49 ++ ) {
unsigned int V_34 ;
V_34 = F_32 ( V_2 , V_484 [ V_49 ] , 0 ,
V_86 , 0 ) ;
V_34 |= V_487 ;
F_18 ( V_2 , V_484 [ V_49 ] , V_34 ) ;
}
V_11 -> V_85 = 1 ;
}
static void F_271 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 == V_461 )
V_11 -> V_453 = 1 ;
}
static int F_272 ( struct V_1 * V_2 )
{
static const T_1 V_488 [] = { 0x1d , 0 } ;
static const T_1 V_489 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_245 ( V_2 , V_488 , V_489 ) ;
}
static int F_273 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
switch ( V_2 -> V_130 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_33 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_253 ( V_2 , V_490 , V_491 ,
V_492 ) ;
F_125 ( V_2 , V_461 ) ;
F_78 ( V_2 ) ;
V_143 = F_272 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 && F_243 ( V_2 ) ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_274 ( struct V_1 * V_2 )
{
static const T_1 V_493 [] = { 0x1d , 0 } ;
static const T_1 V_494 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_245 ( V_2 , V_493 , V_494 ) ;
}
static int F_275 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
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
F_253 ( V_2 , V_495 , V_496 ,
V_497 ) ;
F_125 ( V_2 , V_461 ) ;
F_78 ( V_2 ) ;
V_143 = F_274 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 && F_243 ( V_2 ) ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
V_11 -> V_318 = F_53 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_276 ( struct V_1 * V_2 )
{
static const T_1 V_498 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_143 = F_245 ( V_2 , NULL , V_498 ) ;
if ( V_143 > 0 ) {
if ( ! V_11 -> V_252 && V_11 -> V_36 . V_96 [ 0 ] != 0x1d ) {
F_27 ( V_11 , V_499 ) ;
F_259 ( & V_11 -> V_323 , V_500 ) ;
}
}
return V_143 ;
}
static int F_277 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_49 , V_501 , V_143 ;
V_143 = F_247 ( V_2 , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
F_253 ( V_2 , V_502 , V_503 , V_504 ) ;
F_125 ( V_2 , V_461 ) ;
V_143 = F_276 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
V_501 = 0 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_65 ; V_49 ++ ) {
if ( V_11 -> V_66 [ V_49 ] == V_499 ) {
V_501 = 1 ;
break;
}
}
if ( V_501 ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_59 ) )
F_278 ( V_2 , 0x1d , V_59 ,
( 0x0c << V_505 ) |
( 0x0c << V_506 ) |
( 0x07 << V_507 ) |
( 0 << V_508 ) ) ;
}
V_2 -> V_325 = V_462 ;
V_11 -> V_318 = F_53 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_279 ( struct V_1 * V_2 )
{
static const T_1 V_509 [] = { 0x1d , 0 } ;
static const T_1 V_510 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_511 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_512 ;
switch ( V_11 -> V_513 ) {
case V_514 :
case V_515 :
case V_516 :
case V_517 :
V_512 = V_511 ;
break;
case V_518 :
case V_519 :
case V_520 :
V_512 = V_510 ;
break;
default:
V_512 = V_510 ;
break;
}
return F_245 ( V_2 , V_509 , V_512 ) ;
}
static void F_280 ( struct V_1 * V_2 , int V_521 )
{
int V_34 = F_84 ( V_2 , 0x04 ) ;
if ( V_521 )
V_34 |= 1 << 11 ;
else
V_34 &= ~ ( 1 << 11 ) ;
F_85 ( V_2 , 0x04 , V_34 ) ;
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_513 != V_518 )
return;
if ( V_11 -> V_513 == V_518 )
F_280 ( V_2 , 0 ) ;
if ( V_11 -> V_513 == V_518 &&
( F_86 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_54 ( 150 ) ;
}
}
static int F_282 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_513 == V_518 )
F_280 ( V_2 , 0 ) ;
if ( V_11 -> V_513 == V_518 &&
( F_86 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_54 ( 150 ) ;
}
V_2 -> V_325 . V_326 ( V_2 ) ;
if ( V_11 -> V_513 == V_518 )
F_280 ( V_2 , 1 ) ;
if ( V_11 -> V_513 == V_518 &&
( F_86 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_54 ( 200 ) ;
}
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_130 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_283 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 == V_461 )
V_11 -> V_451 = V_522 ;
}
static void F_284 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
int V_523 ;
if ( V_173 != V_271 )
return;
V_523 = F_84 ( V_2 , 0x1e ) ;
F_85 ( V_2 , 0x1e , V_523 | 0x80 ) ;
}
static void F_285 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
static const struct V_524 V_525 [] = {
{ 0x20 , V_68 , 0x0d } ,
{ 0x20 , V_71 , 0x4000 } ,
{}
} ;
unsigned int V_142 ;
if ( strcmp ( V_2 -> V_187 , L_59 ) )
return;
V_142 = F_17 ( V_2 , 0x12 ) ;
if ( F_16 ( V_142 ) == V_526 )
F_56 ( V_2 , V_525 ) ;
}
static void F_286 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 != V_246 )
return;
V_11 -> V_288 = & V_527 ;
V_11 -> V_297 = & V_528 ;
}
static void F_287 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
int V_523 ;
if ( V_173 != V_271 )
return;
V_523 = F_84 ( V_2 , 0x07 ) ;
F_85 ( V_2 , 0x07 , V_523 | 0x80 ) ;
}
static void F_288 ( struct V_1 * V_2 )
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
static void F_289 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 != V_246 )
return;
V_11 -> V_99 = F_288 ;
}
static void F_290 ( void * V_529 , int V_530 )
{
struct V_1 * V_2 = V_529 ;
unsigned int V_531 = V_532 + ( V_530 ?
V_38 : V_486 ) ;
F_232 ( V_2 , 0x18 , V_531 ) ;
}
static void F_291 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_173 ) {
case V_269 :
V_11 -> V_259 . V_533 = F_290 ;
F_292 ( V_2 , & V_11 -> V_259 , true ) ;
case V_271 :
F_293 ( & V_11 -> V_259 ) ;
break;
}
}
static void F_294 ( void * V_529 , int V_530 )
{
struct V_1 * V_2 = V_529 ;
unsigned int V_531 = V_530 ? 0x20 : 0x24 ;
F_232 ( V_2 , 0x19 , V_531 ) ;
}
static void F_295 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_173 ) {
case V_269 :
V_11 -> V_259 . V_533 = F_294 ;
F_292 ( V_2 , & V_11 -> V_259 , true ) ;
case V_271 :
F_293 ( & V_11 -> V_259 ) ;
break;
}
}
static void F_296 ( struct V_1 * V_2 ,
const struct V_245 * V_172 ,
int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_173 == V_246 )
F_297 ( V_2 , V_11 -> V_158 ,
V_11 -> V_36 . V_92 [ 0 ] ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_34 ;
if ( V_11 -> V_513 != V_518 )
return;
if ( ( F_86 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_85 ( V_2 , 0xf , 0x960b ) ;
F_85 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_86 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_85 ( V_2 , 0xf , 0x960b ) ;
F_85 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_86 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_34 = F_84 ( V_2 , 0x04 ) ;
F_85 ( V_2 , 0x04 , V_34 | ( 1 << 11 ) ) ;
}
if ( ( F_86 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_34 = F_84 ( V_2 , 0xd ) ;
if ( ( V_34 & 0x0c00 ) >> 10 != 0x1 ) {
F_85 ( V_2 , 0xd , V_34 | ( 1 << 10 ) ) ;
}
V_34 = F_84 ( V_2 , 0x17 ) ;
if ( ( V_34 & 0x01c0 ) >> 6 != 0x4 ) {
F_85 ( V_2 , 0x17 , V_34 | ( 1 << 7 ) ) ;
}
}
V_34 = F_84 ( V_2 , 0xd ) ;
F_85 ( V_2 , 0xd , V_34 | ( 1 << 14 ) ) ;
V_34 = F_84 ( V_2 , 0x4 ) ;
F_85 ( V_2 , 0x4 , V_34 | ( 1 << 11 ) ) ;
}
static int F_299 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
F_253 ( V_2 , V_534 ,
V_535 , V_536 ) ;
F_125 ( V_2 , V_461 ) ;
F_78 ( V_2 ) ;
switch ( V_2 -> V_130 ) {
case 0x10ec0269 :
V_11 -> V_513 = V_514 ;
switch ( F_86 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_183 -> V_184 -> V_537 == 0x1025 &&
V_11 -> V_175 . V_192 == 1 )
V_143 = F_165 ( V_2 , L_59 ) ;
V_11 -> V_513 = V_518 ;
break;
case 0x0020 :
if ( V_2 -> V_183 -> V_184 -> V_537 == 0x17aa &&
V_2 -> V_183 -> V_184 -> V_185 == 0x21f3 )
V_143 = F_165 ( V_2 , L_60 ) ;
V_11 -> V_513 = V_515 ;
break;
case 0x0030 :
V_11 -> V_513 = V_519 ;
break;
default:
F_33 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_143 < 0 )
goto error;
V_11 -> V_270 = F_298 ;
F_298 ( V_2 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_11 -> V_513 = V_516 ;
break;
case 0x10ec0282 :
case 0x10ec0283 :
V_11 -> V_513 = V_520 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_11 -> V_513 = V_517 ;
break;
}
V_143 = F_279 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 && F_243 ( V_2 ) ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x0b , 0x04 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
#ifdef F_300
V_2 -> V_325 . V_538 = F_282 ;
#endif
V_11 -> V_318 = F_281 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_301 ( struct V_1 * V_2 )
{
static const T_1 V_539 [] = { 0x1d , 0 } ;
static const T_1 V_540 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_245 ( V_2 , V_539 , V_540 ) ;
}
static void F_302 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_34 ;
if ( V_173 != V_271 )
return;
V_34 = F_32 ( V_2 , 0x0f , 0 ,
V_86 , 0 ) ;
if ( ! ( V_34 & ( V_532 | V_541 ) ) )
V_34 |= V_532 ;
V_34 |= V_487 ;
F_18 ( V_2 , 0x0f , V_34 ) ;
V_11 -> V_85 = 1 ;
}
static void F_303 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 == V_461 )
V_2 -> V_542 = 1 ;
}
static int F_304 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x15 ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
F_253 ( V_2 , NULL , V_543 , V_544 ) ;
F_125 ( V_2 , V_461 ) ;
V_143 = F_301 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 ) {
V_143 = F_254 ( V_2 , 0x23 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x23 , 0 , V_88 ) ;
}
V_2 -> V_325 = V_462 ;
#ifdef F_300
V_11 -> V_324 = F_160 ;
#endif
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_305 ( struct V_1 * V_2 )
{
static const T_1 V_545 [] = { 0x1d , 0 } ;
static const T_1 V_546 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_245 ( V_2 , V_545 , V_546 ) ;
}
static void F_306 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 == V_461 ) {
F_307 ( V_2 , 0x18 , 0x00000734 ) ;
F_307 ( V_2 , 0x19 , 0x0000073c ) ;
}
}
static int F_308 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
F_253 ( V_2 , NULL , V_547 , V_548 ) ;
F_125 ( V_2 , V_461 ) ;
V_143 = F_305 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 ) {
V_143 = F_254 ( V_2 , 0x23 ) ;
if ( V_143 < 0 )
goto error;
F_255 ( V_11 , 0x0b , 0x05 , V_59 ) ;
}
V_2 -> V_325 = V_462 ;
V_11 -> V_318 = F_53 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_309 ( struct V_1 * V_2 )
{
static const T_1 V_549 [] = { 0x1d , 0 } ;
static const T_1 V_550 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_551 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_512 ;
if ( V_2 -> V_130 == 0x10ec0272 || V_2 -> V_130 == 0x10ec0663 ||
V_2 -> V_130 == 0x10ec0665 || V_2 -> V_130 == 0x10ec0670 )
V_512 = V_550 ;
else
V_512 = V_551 ;
return F_245 ( V_2 , V_549 , V_512 ) ;
}
static void F_310 ( struct V_1 * V_2 ,
const struct V_245 * V_172 , int V_173 )
{
if ( V_173 != V_246 )
return;
if ( F_278 ( V_2 , 0x2 , V_88 ,
( 0x3b << V_505 ) |
( 0x3b << V_506 ) |
( 0x03 << V_507 ) |
( 0 << V_508 ) ) )
F_79 ( V_436
L_61 ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
int V_34 , V_523 ;
V_523 = F_86 ( V_2 ) ;
switch ( V_2 -> V_130 ) {
case 0x10ec0662 :
if ( ( V_523 & 0x00f0 ) == 0x0030 ) {
V_34 = F_84 ( V_2 , 0x4 ) ;
F_85 ( V_2 , 0x4 , V_34 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_34 = F_84 ( V_2 , 0xd ) ;
F_85 ( V_2 , 0xd , V_34 | ( 1 << 14 ) ) ;
break;
}
}
static int F_312 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_143 ;
V_143 = F_247 ( V_2 , 0x0b ) ;
if ( V_143 < 0 )
return V_143 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_451 = V_522 ;
F_33 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_11 -> V_270 = F_311 ;
F_311 ( V_2 ) ;
F_253 ( V_2 , V_552 ,
V_553 , V_554 ) ;
F_125 ( V_2 , V_461 ) ;
F_78 ( V_2 ) ;
if ( ( F_86 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_183 -> V_184 -> V_537 == 0x1025 &&
V_11 -> V_175 . V_192 == 1 ) {
if ( F_165 ( V_2 , L_62 ) < 0 )
goto error;
}
V_143 = F_309 ( V_2 ) ;
if ( V_143 < 0 )
goto error;
if ( ! V_11 -> V_252 && F_243 ( V_2 ) ) {
V_143 = F_254 ( V_2 , 0x1 ) ;
if ( V_143 < 0 )
goto error;
switch ( V_2 -> V_130 ) {
case 0x10ec0662 :
F_255 ( V_11 , 0x0b , 0x05 , V_59 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_255 ( V_11 , 0x0b , 0x04 , V_59 ) ;
break;
case 0x10ec0273 :
F_255 ( V_11 , 0x0b , 0x03 , V_59 ) ;
break;
}
}
V_2 -> V_325 = V_462 ;
V_11 -> V_318 = F_53 ;
F_125 ( V_2 , V_246 ) ;
return 0 ;
error:
F_157 ( V_2 ) ;
return V_143 ;
}
static int F_313 ( struct V_1 * V_2 )
{
return F_245 ( V_2 , NULL , NULL ) ;
}
static int F_314 ( struct V_1 * V_2 )
{
int V_143 ;
V_143 = F_247 ( V_2 , 0 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_313 ( V_2 ) ;
if ( V_143 < 0 ) {
F_157 ( V_2 ) ;
return V_143 ;
}
V_2 -> V_325 = V_462 ;
return 0 ;
}
static int T_4 F_315 ( void )
{
return F_316 ( & V_555 ) ;
}
static void T_5 F_317 ( void )
{
F_318 ( & V_555 ) ;
}
