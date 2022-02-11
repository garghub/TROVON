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
unsigned int V_39 ;
T_1 V_40 = V_11 -> V_41 . V_42 [ 1 ] . V_40 ;
if ( V_11 -> V_23 [ V_19 ] )
V_39 = F_14 ( V_2 , V_40 ) | V_43 ;
else
V_39 = V_44 ;
F_15 ( V_2 , V_40 , V_39 ) ;
V_11 -> V_45 = ! V_11 -> V_23 [ V_19 ] ;
F_16 ( V_2 ) ;
}
if ( V_11 -> V_46 ) {
F_9 ( V_2 , V_31 ) ;
V_19 = V_11 -> V_27 [ V_31 ] ;
}
V_3 = F_12 ( V_11 , V_19 ) ;
V_37 = F_17 ( V_2 , V_3 ) ;
if ( V_37 <= 1 )
return 1 ;
type = F_18 ( F_2 ( V_2 , V_3 ) ) ;
if ( type == V_47 ) {
int V_48 = V_35 -> V_49 [ V_31 ] . V_50 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
unsigned int V_51 = ( V_36 == V_48 ) ? 0 : V_52 ;
F_19 ( V_2 , V_3 , V_53 , V_36 ,
V_52 , V_51 ) ;
}
} else {
F_20 ( V_2 , V_3 , 0 ,
V_54 ,
V_35 -> V_49 [ V_31 ] . V_50 ) ;
}
return 1 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_19 = F_6 ( V_7 , & V_18 -> V_13 ) ;
return F_13 ( V_2 , V_19 ,
V_18 -> V_20 . V_21 . V_22 [ 0 ] , false ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 ,
int V_55 )
{
unsigned int V_39 = V_43 ;
if ( V_55 == V_56 )
V_39 |= F_14 ( V_2 , V_3 ) ;
F_15 ( V_2 , V_3 , V_39 ) ;
}
static void F_23 ( struct V_10 * V_11 , const struct V_57 * V_58 )
{
if ( F_24 ( V_11 -> V_59 >= F_25 ( V_11 -> V_60 ) ) )
return;
V_11 -> V_60 [ V_11 -> V_59 ++ ] = V_58 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_39 ;
if ( ! V_11 -> V_61 )
return;
F_27 ( V_2 , V_11 -> V_61 , 0 , V_62 ,
V_11 -> V_63 ) ;
V_39 = F_28 ( V_2 , V_11 -> V_61 , 0 ,
V_64 , 0 ) ;
F_27 ( V_2 , V_11 -> V_61 , 0 , V_62 ,
V_11 -> V_63 ) ;
F_27 ( V_2 , V_11 -> V_61 , 0 , V_65 ,
V_39 & ~ ( 1 << V_11 -> V_66 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_67 , unsigned int V_68 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_61 = V_3 ;
V_11 -> V_63 = V_67 ;
V_11 -> V_66 = V_68 ;
F_26 ( V_2 ) ;
}
static bool F_30 ( struct V_1 * V_2 , int V_69 , T_1 * V_70 )
{
int V_36 , V_71 = 0 ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
T_1 V_3 = V_70 [ V_36 ] ;
if ( ! V_3 )
break;
V_71 |= F_31 ( V_2 , V_3 ) ;
}
return V_71 ;
}
static void F_32 ( struct V_1 * V_2 , int V_69 , T_1 * V_70 ,
bool V_72 , bool V_73 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_74 = V_72 ? V_52 : 0 ;
unsigned int V_75 = V_72 ? 0 : ( V_73 ? V_44 : V_76 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
T_1 V_3 = V_70 [ V_36 ] ;
unsigned int V_39 ;
if ( ! V_3 )
break;
switch ( V_11 -> V_77 ) {
case V_78 :
if ( V_11 -> V_79 ) {
V_39 = F_28 ( V_2 , V_3 , 0 ,
V_80 , 0 ) ;
V_39 &= ~ V_44 ;
} else
V_39 = 0 ;
V_39 |= V_75 ;
F_15 ( V_2 , V_3 , V_39 ) ;
break;
case V_81 :
F_19 ( V_2 , V_3 , V_82 , 0 ,
V_52 , V_74 ) ;
break;
case V_83 :
V_3 = V_11 -> V_84 [ V_36 ] ;
if ( ! V_3 )
break;
F_19 ( V_2 , V_3 , V_53 , 0 ,
V_52 , V_74 ) ;
F_19 ( V_2 , V_3 , V_53 , 1 ,
V_52 , V_74 ) ;
break;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_85 ;
if ( ! V_11 -> V_38 )
F_32 ( V_2 , F_25 ( V_11 -> V_41 . V_86 ) ,
V_11 -> V_41 . V_86 , V_11 -> V_87 , true ) ;
if ( ! V_11 -> V_45 )
V_85 = 0 ;
else
V_85 = V_11 -> V_88 | V_11 -> V_89 ;
V_85 |= V_11 -> V_87 ;
F_32 ( V_2 , F_25 ( V_11 -> V_41 . V_90 ) ,
V_11 -> V_41 . V_90 , V_85 , false ) ;
if ( V_11 -> V_41 . V_91 [ 0 ] == V_11 -> V_41 . V_86 [ 0 ] ||
V_11 -> V_41 . V_91 [ 0 ] == V_11 -> V_41 . V_90 [ 0 ] )
return;
if ( ! V_11 -> V_92 )
V_85 = 0 ;
else
V_85 = V_11 -> V_88 ;
V_85 |= V_11 -> V_87 ;
F_32 ( V_2 , F_25 ( V_11 -> V_41 . V_91 ) ,
V_11 -> V_41 . V_91 , V_85 , false ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_93 )
V_11 -> V_93 ( V_2 ) ;
else
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_88 =
F_30 ( V_2 , F_25 ( V_11 -> V_41 . V_86 ) ,
V_11 -> V_41 . V_86 ) ;
if ( ! V_11 -> V_94 || ( ! V_11 -> V_45 && ! V_11 -> V_92 ) )
return;
F_16 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_41 . V_91 [ 0 ] == V_11 -> V_41 . V_86 [ 0 ] )
return;
V_11 -> V_89 =
F_30 ( V_2 , F_25 ( V_11 -> V_41 . V_91 ) ,
V_11 -> V_41 . V_91 ) ;
if ( ! V_11 -> V_45 || ! V_11 -> V_95 )
return;
F_16 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 * V_70 = V_11 -> V_96 ;
if ( ! V_11 -> V_97 || ! V_11 -> V_98 )
return;
if ( F_24 ( ! V_11 -> V_26 ) )
return;
if ( F_24 ( V_11 -> V_99 < 0 || V_11 -> V_100 < 0 ) )
return;
if ( F_31 ( V_2 , V_70 [ V_11 -> V_100 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_100 , false ) ;
else if ( V_11 -> V_101 >= 0 &&
F_31 ( V_2 , V_70 [ V_11 -> V_101 ] ) )
F_13 ( V_2 , 0 , V_11 -> V_101 , false ) ;
else
F_13 ( V_2 , 0 , V_11 -> V_99 , false ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_102 )
{
switch ( V_102 ) {
case V_103 :
F_34 ( V_2 ) ;
break;
case V_104 :
F_35 ( V_2 ) ;
break;
case V_105 :
F_36 ( V_2 ) ;
break;
}
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_39 ;
struct V_6 * V_106 ;
struct V_17 * V_107 ;
V_106 = F_40 ( V_2 , L_1 ) ;
if ( ! V_106 )
return;
V_107 = F_41 ( sizeof( * V_107 ) , V_108 ) ;
if ( ! V_107 )
return;
V_39 = F_28 ( V_2 , V_3 , 0 ,
V_109 , 0 ) ;
V_39 &= V_110 ;
V_107 -> V_20 . integer . V_20 [ 0 ] = V_39 ;
V_107 -> V_20 . integer . V_20 [ 1 ] = V_39 ;
V_106 -> V_111 ( V_106 , V_107 ) ;
F_42 ( V_107 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_112 )
{
int V_102 ;
if ( V_2 -> V_113 == 0x10ec0880 )
V_112 >>= 28 ;
else
V_112 >>= 26 ;
V_102 = F_44 ( V_2 , V_112 ) ;
if ( V_102 == V_114 ) {
struct V_115 * V_116 ;
V_116 = F_45 ( V_2 , V_112 ) ;
if ( V_116 )
F_39 ( V_2 , V_116 -> V_3 ) ;
return;
}
F_37 ( V_2 , V_102 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned int V_117 ;
F_27 ( V_2 , 0x20 , 0 , V_62 , 0 ) ;
V_117 = F_28 ( V_2 , 0x20 , 0 , V_64 , 0 ) ;
F_27 ( V_2 , 0x20 , 0 , V_62 , 7 ) ;
if ( ( V_117 & 0xf0 ) == 0x20 )
F_28 ( V_2 , 0x20 , 0 ,
V_65 , 0x830 ) ;
else
F_28 ( V_2 , 0x20 , 0 ,
V_65 , 0x3030 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_117 ;
F_27 ( V_2 , 0x20 , 0 , V_62 , 7 ) ;
V_117 = F_28 ( V_2 , 0x20 , 0 , V_64 , 0 ) ;
F_27 ( V_2 , 0x20 , 0 , V_62 , 7 ) ;
F_27 ( V_2 , 0x20 , 0 , V_65 , V_117 | 0x2010 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_3 , int V_85 )
{
if ( F_18 ( F_2 ( V_2 , V_3 ) ) != V_118 )
return;
if ( F_50 ( V_2 , V_3 ) & V_119 )
F_27 ( V_2 , V_3 , 0 , V_120 ,
V_85 ? 2 : 0 ) ;
}
static void F_51 ( struct V_1 * V_2 , bool V_85 )
{
static T_1 V_70 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_121 ;
for ( V_121 = V_70 ; * V_121 ; V_121 ++ )
F_49 ( V_2 , * V_121 , V_85 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_51 ( V_2 , false ) ;
F_53 ( 200 ) ;
}
static void F_54 ( struct V_1 * V_2 , int type )
{
unsigned int V_117 ;
F_51 ( V_2 , true ) ;
switch ( type ) {
case V_122 :
F_55 ( V_2 , V_123 ) ;
break;
case V_124 :
F_55 ( V_2 , V_125 ) ;
break;
case V_126 :
F_55 ( V_2 , V_127 ) ;
break;
case V_128 :
switch ( V_2 -> V_113 ) {
case 0x10ec0260 :
F_27 ( V_2 , 0x1a , 0 ,
V_62 , 7 ) ;
V_117 = F_28 ( V_2 , 0x1a , 0 ,
V_64 , 0 ) ;
F_27 ( V_2 , 0x1a , 0 ,
V_62 , 7 ) ;
F_27 ( V_2 , 0x1a , 0 ,
V_65 ,
V_117 | 0x2010 ) ;
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
static int F_56 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
static const char * const V_129 [] = {
L_2 , L_3
} ;
static const char * const V_130 [] = {
L_2 , L_4 , L_5
} ;
const char * const * V_131 ;
V_9 -> type = V_132 ;
V_9 -> V_133 = 1 ;
if ( V_11 -> V_134 && V_11 -> V_135 ) {
V_9 -> V_20 . V_21 . V_49 = 3 ;
V_131 = V_130 ;
} else {
V_9 -> V_20 . V_21 . V_49 = 2 ;
V_131 = V_129 ;
}
if ( V_9 -> V_20 . V_21 . V_22 >= V_9 -> V_20 . V_21 . V_49 )
V_9 -> V_20 . V_21 . V_22 = V_9 -> V_20 . V_21 . V_49 - 1 ;
strcpy ( V_9 -> V_20 . V_21 . V_136 ,
V_131 [ V_9 -> V_20 . V_21 . V_22 ] ) ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_39 = 0 ;
if ( V_11 -> V_45 )
V_39 ++ ;
if ( V_11 -> V_92 )
V_39 ++ ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = V_39 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_18 -> V_20 . V_21 . V_22 [ 0 ] ) {
case 0 :
if ( ! V_11 -> V_45 && ! V_11 -> V_92 )
return 0 ;
V_11 -> V_45 = 0 ;
V_11 -> V_92 = 0 ;
break;
case 1 :
if ( V_11 -> V_134 ) {
if ( ! V_11 -> V_92 && V_11 -> V_45 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_92 = 0 ;
} else if ( V_11 -> V_135 ) {
if ( V_11 -> V_92 )
return 0 ;
V_11 -> V_92 = 1 ;
} else
return - V_137 ;
break;
case 2 :
if ( ! V_11 -> V_135 || ! V_11 -> V_134 )
return - V_137 ;
if ( V_11 -> V_45 && V_11 -> V_92 )
return 0 ;
V_11 -> V_45 = 1 ;
V_11 -> V_92 = 1 ;
break;
default:
return - V_137 ;
}
F_16 ( V_2 ) ;
return 1 ;
}
static struct V_57 * F_59 ( struct V_10 * V_11 )
{
F_60 ( & V_11 -> V_138 , sizeof( struct V_57 ) , 32 ) ;
return F_61 ( & V_11 -> V_138 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_57 * V_139 ;
V_139 = F_59 ( V_11 ) ;
if ( ! V_139 )
return - V_140 ;
* V_139 = V_141 ;
V_139 -> V_136 = F_63 ( L_6 , V_108 ) ;
if ( ! V_139 -> V_136 )
return - V_140 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_71 = 0 ;
int V_36 ;
if ( V_143 -> V_86 [ 0 ] )
V_71 ++ ;
if ( V_143 -> V_91 [ 0 ] )
V_71 ++ ;
if ( V_143 -> V_90 [ 0 ] )
V_71 ++ ;
if ( V_71 < 2 )
return;
if ( ! V_143 -> V_90 [ 0 ] &&
V_143 -> V_144 == V_145 ) {
memcpy ( V_143 -> V_90 , V_143 -> V_91 ,
sizeof( V_143 -> V_90 ) ) ;
V_143 -> V_146 = V_143 -> V_147 ;
}
if ( ! V_143 -> V_86 [ 0 ] &&
V_143 -> V_144 == V_148 ) {
memcpy ( V_143 -> V_86 , V_143 -> V_91 ,
sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_149 = V_143 -> V_147 ;
}
V_11 -> V_77 = V_78 ;
for ( V_36 = 0 ; V_36 < V_143 -> V_149 ; V_36 ++ ) {
T_1 V_3 = V_143 -> V_86 [ V_36 ] ;
if ( ! F_65 ( V_2 , V_3 ) )
continue;
F_66 ( L_7 ,
V_3 ) ;
F_67 ( V_2 , V_3 , V_103 ) ;
V_11 -> V_94 = 1 ;
}
if ( V_143 -> V_144 == V_150 && V_143 -> V_147 ) {
if ( V_143 -> V_146 )
for ( V_36 = 0 ; V_36 < V_143 -> V_147 ; V_36 ++ ) {
T_1 V_3 = V_143 -> V_91 [ V_36 ] ;
if ( ! F_65 ( V_2 , V_3 ) )
continue;
F_66 ( L_8
L_9 , V_3 ) ;
F_67 ( V_2 , V_3 ,
V_104 ) ;
V_11 -> V_95 = 1 ;
}
V_11 -> V_135 = V_11 -> V_94 ;
}
V_11 -> V_134 = V_143 -> V_146 &&
( V_11 -> V_94 || V_11 -> V_95 ) ;
V_11 -> V_92 = V_11 -> V_135 ;
V_11 -> V_45 = V_11 -> V_134 ;
if ( V_11 -> V_134 || V_11 -> V_135 ) {
F_62 ( V_2 ) ;
V_11 -> V_151 = F_43 ;
}
}
static int F_68 ( T_1 V_3 , const T_1 * V_152 , int V_153 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ )
if ( V_152 [ V_36 ] == V_3 )
return V_36 ;
return - 1 ;
}
static bool F_69 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_34 * V_35 = & V_11 -> V_154 [ 0 ] ;
int V_36 , V_155 , V_31 ;
T_1 V_156 , V_40 ;
if ( V_35 != V_11 -> V_15 )
return false ;
for ( V_155 = 0 ; V_155 < V_11 -> V_157 ; V_155 ++ ) {
V_156 = V_11 -> V_158 [ V_155 ] ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_40 = V_11 -> V_96 [ V_36 ] ;
if ( ! V_40 )
return false ;
if ( F_70 ( V_2 , V_156 , V_40 ) < 0 )
break;
}
if ( V_36 >= V_35 -> V_16 )
return true ;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
V_40 = V_11 -> V_96 [ V_36 ] ;
for ( V_155 = 0 ; V_155 < V_11 -> V_157 ; V_155 ++ ) {
V_156 = V_11 -> V_158 [ V_155 ] ;
V_31 = F_70 ( V_2 , V_156 , V_40 ) ;
if ( V_31 >= 0 ) {
V_35 -> V_49 [ V_36 ] . V_50 = V_31 ;
V_11 -> V_27 [ V_36 ] = V_155 ;
break;
}
}
}
F_66 ( L_10 ) ;
V_11 -> V_46 = 1 ;
return true ;
}
static bool F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
if ( ! V_11 -> V_97 )
return false ;
if ( V_11 -> V_98 )
return true ;
if ( ! F_69 ( V_2 ) ) {
V_11 -> V_97 = 0 ;
return false ;
}
V_35 = V_11 -> V_15 ;
V_11 -> V_100 = F_68 ( V_11 -> V_159 ,
V_11 -> V_96 , V_35 -> V_16 ) ;
V_11 -> V_99 = F_68 ( V_11 -> V_160 ,
V_11 -> V_96 , V_35 -> V_16 ) ;
V_11 -> V_101 = F_68 ( V_11 -> V_161 ,
V_11 -> V_96 , V_35 -> V_16 ) ;
if ( V_11 -> V_100 < 0 || V_11 -> V_99 < 0 ) {
V_11 -> V_97 = 0 ;
return false ;
}
F_67 ( V_2 , V_11 -> V_159 , V_105 ) ;
if ( V_11 -> V_161 )
F_67 ( V_2 , V_11 -> V_161 ,
V_105 ) ;
V_11 -> V_98 = 1 ;
V_11 -> V_97 = 1 ;
return true ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
T_1 V_162 , V_163 , V_164 ;
int V_36 ;
if ( V_11 -> V_38 )
return;
V_11 -> V_100 = V_11 -> V_99 = V_11 -> V_101 = - 1 ;
V_162 = V_163 = V_164 = 0 ;
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
T_1 V_3 = V_143 -> V_42 [ V_36 ] . V_40 ;
unsigned int V_166 ;
V_166 = F_73 ( V_2 , V_3 ) ;
switch ( F_74 ( V_166 ) ) {
case V_167 :
if ( V_162 )
return;
if ( V_143 -> V_42 [ V_36 ] . type != V_56 )
return;
V_162 = V_3 ;
break;
case V_168 :
return;
case V_169 :
if ( V_164 )
return;
if ( V_143 -> V_42 [ V_36 ] . type > V_170 )
return;
V_164 = V_3 ;
break;
default:
if ( V_163 )
return;
if ( V_143 -> V_42 [ V_36 ] . type != V_56 )
return;
V_163 = V_3 ;
break;
}
}
if ( ! V_163 && V_164 ) {
V_163 = V_164 ;
V_164 = 0 ;
}
if ( ! V_163 || ! V_162 )
return;
if ( ! F_65 ( V_2 , V_163 ) )
return;
if ( V_164 && ! F_65 ( V_2 , V_164 ) )
return;
V_11 -> V_159 = V_163 ;
V_11 -> V_160 = V_162 ;
V_11 -> V_161 = V_164 ;
V_11 -> V_97 = 1 ;
if ( ! F_71 ( V_2 ) )
return;
F_66 ( L_11 ,
V_163 , V_162 , V_164 ) ;
V_11 -> V_151 = F_43 ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
F_72 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
const struct V_171 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_102 == V_173 ) {
V_11 -> V_174 . V_175 = 1 ;
V_11 -> V_174 . V_176 = V_177 ;
}
}
static int F_77 ( struct V_1 * V_2 )
{
unsigned int V_178 , V_117 , V_36 ;
unsigned V_3 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_174 . V_179 = 1 ;
if ( V_11 -> V_174 . V_175 ) {
V_178 = V_11 -> V_174 . V_176 ;
if ( V_178 == V_177 )
return - 1 ;
goto V_180;
}
V_178 = V_2 -> V_181 & 0xffff ;
if ( V_178 != V_2 -> V_182 -> V_183 -> V_184 && ( V_178 & 1 ) )
goto V_180;
V_3 = 0x1d ;
if ( V_2 -> V_113 == 0x10ec0260 )
V_3 = 0x17 ;
V_178 = F_73 ( V_2 , V_3 ) ;
if ( ! ( V_178 & 1 ) ) {
F_78 ( V_185 L_12 ,
V_2 -> V_186 , V_178 ) ;
return - 1 ;
}
V_117 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_178 >> V_36 ) & 1 )
V_117 ++ ;
}
if ( ( ( V_178 >> 16 ) & 0xf ) != V_117 )
return - 1 ;
V_11 -> V_174 . V_187 = V_178 >> 30 ;
V_11 -> V_174 . V_179 = ( V_178 & 0x100000 ) >> 20 ;
V_11 -> V_174 . V_188 = ( V_178 >> 16 ) & 0xf ;
V_11 -> V_174 . V_189 = V_178 >> 8 ;
V_180:
V_11 -> V_174 . V_176 = V_178 ;
V_11 -> V_174 . V_190 = ( V_178 & 0x38 ) >> 3 ;
V_11 -> V_174 . V_191 = ( V_178 & 0x4 ) >> 2 ;
V_11 -> V_174 . V_192 = ( V_178 & 0x2 ) >> 1 ;
V_11 -> V_174 . V_193 = V_178 & 0x1 ;
F_79 ( L_13 ,
V_3 , V_11 -> V_174 . V_176 ) ;
F_79 ( L_14 ,
V_11 -> V_174 . V_187 ) ;
F_79 ( L_15 , V_11 -> V_174 . V_179 ) ;
F_79 ( L_16 , V_11 -> V_174 . V_188 ) ;
F_79 ( L_17 , V_11 -> V_174 . V_189 ) ;
F_79 ( L_18 , V_11 -> V_174 . V_190 ) ;
F_79 ( L_19 , V_11 -> V_174 . V_191 ) ;
F_79 ( L_20 , V_11 -> V_174 . V_192 ) ;
F_79 ( L_21 , V_11 -> V_174 . V_193 ) ;
return 0 ;
}
static bool F_80 ( T_1 V_3 , const T_1 * V_152 , int V_153 )
{
return F_68 ( V_3 , V_152 , V_153 ) >= 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_1 V_194 , T_1 V_195 ,
T_1 V_196 , T_1 V_197 )
{
unsigned int V_178 , V_117 , V_36 ;
unsigned V_3 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_174 . V_175 ) {
V_178 = V_11 -> V_174 . V_176 ;
if ( V_178 == V_177 )
return 0 ;
goto V_180;
}
V_178 = V_2 -> V_181 & 0xffff ;
if ( ( V_178 != V_2 -> V_182 -> V_183 -> V_184 ) && ( V_178 & 1 ) )
goto V_180;
V_3 = 0x1d ;
if ( V_2 -> V_113 == 0x10ec0260 )
V_3 = 0x17 ;
V_178 = F_73 ( V_2 , V_3 ) ;
F_79 ( L_22
L_23 ,
V_178 , V_3 ) ;
if ( ! ( V_178 & 1 ) )
return 0 ;
if ( ( V_178 >> 30 ) != 1 )
return 0 ;
V_117 = 0 ;
for ( V_36 = 1 ; V_36 < 16 ; V_36 ++ ) {
if ( ( V_178 >> V_36 ) & 1 )
V_117 ++ ;
}
if ( ( ( V_178 >> 16 ) & 0xf ) != V_117 )
return 0 ;
V_180:
F_79 ( L_24 ,
V_178 & 0xffff , V_2 -> V_113 ) ;
V_117 = ( V_178 & 0x38 ) >> 3 ;
switch ( V_117 ) {
case 1 :
V_11 -> V_198 = V_122 ;
break;
case 3 :
V_11 -> V_198 = V_124 ;
break;
case 7 :
V_11 -> V_198 = V_126 ;
break;
case 5 :
default:
V_11 -> V_198 = V_128 ;
break;
}
if ( ! ( V_178 & 0x8000 ) )
return 1 ;
if ( ! V_11 -> V_41 . V_86 [ 0 ] &&
! ( V_11 -> V_41 . V_91 [ 0 ] &&
V_11 -> V_41 . V_144 == V_148 ) ) {
T_1 V_3 ;
V_117 = ( V_178 >> 11 ) & 0x3 ;
if ( V_117 == 0 )
V_3 = V_194 ;
else if ( V_117 == 1 )
V_3 = V_195 ;
else if ( V_117 == 2 )
V_3 = V_196 ;
else if ( V_117 == 3 )
V_3 = V_197 ;
else
return 1 ;
if ( F_80 ( V_3 , V_11 -> V_41 . V_91 ,
V_11 -> V_41 . V_147 ) )
return 1 ;
V_11 -> V_41 . V_86 [ 0 ] = V_3 ;
}
return 1 ;
}
static void F_82 ( struct V_1 * V_2 , const T_1 * V_199 )
{
if ( ! F_81 ( V_2 , V_199 [ 0 ] , V_199 [ 1 ] , V_199 [ 2 ] , V_199 [ 3 ] ) ) {
struct V_10 * V_11 = V_2 -> V_11 ;
F_79 ( L_25
L_26 ) ;
V_11 -> V_198 = V_128 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
unsigned int V_67 )
{
unsigned int V_39 ;
F_27 ( V_2 , 0x20 , 0 , V_62 ,
V_67 ) ;
V_39 = F_28 ( V_2 , 0x20 , 0 ,
V_64 , 0 ) ;
return V_39 ;
}
static void F_84 ( struct V_1 * V_2 , unsigned int V_67 ,
unsigned int V_200 )
{
F_27 ( V_2 , 0x20 , 0 , V_62 ,
V_67 ) ;
F_27 ( V_2 , 0x20 , 0 , V_65 ,
V_200 ) ;
}
static unsigned int F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_201 )
V_11 -> V_201 = F_83 ( V_2 , 0 ) ;
return V_11 -> V_201 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_40 , V_202 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_41 . V_203 ; V_36 ++ ) {
V_40 = V_11 -> V_41 . V_204 [ V_36 ] ;
if ( ! V_40 )
continue;
F_15 ( V_2 , V_40 , V_76 ) ;
if ( ! V_36 )
V_202 = V_11 -> V_205 . V_206 ;
else
V_202 = V_11 -> V_207 [ V_36 - 1 ] ;
if ( ! V_202 || ! ( F_2 ( V_2 , V_202 ) & V_208 ) )
continue;
F_27 ( V_2 , V_202 , 0 ,
V_209 ,
V_210 ) ;
}
V_40 = V_11 -> V_41 . V_211 ;
if ( V_40 )
F_15 ( V_2 , V_40 , V_43 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_212 , V_153 ;
T_1 V_213 ;
V_153 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_41 . V_203 ; V_36 ++ ) {
T_1 V_214 [ 4 ] ;
V_212 = F_88 ( V_2 ,
V_11 -> V_41 . V_204 [ V_36 ] ,
V_214 , F_25 ( V_214 ) ) ;
if ( V_212 <= 0 )
continue;
V_213 = V_214 [ 0 ] ;
if ( ! V_153 ) {
V_11 -> V_205 . V_206 = V_213 ;
V_11 -> V_215 = V_11 -> V_41 . V_215 [ 0 ] ;
} else {
V_11 -> V_205 . V_207 = V_11 -> V_207 ;
if ( V_153 >= F_25 ( V_11 -> V_207 ) - 1 )
break;
V_11 -> V_207 [ V_153 - 1 ] = V_213 ;
}
V_153 ++ ;
}
if ( V_11 -> V_41 . V_211 ) {
V_213 = V_2 -> V_216 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_217 ; V_36 ++ , V_213 ++ ) {
unsigned int V_218 = F_2 ( V_2 , V_213 ) ;
if ( F_18 ( V_218 ) != V_219 )
continue;
if ( ! ( V_218 & V_220 ) )
continue;
if ( ! ( V_218 & V_221 ) )
continue;
V_212 = F_70 ( V_2 , V_213 ,
V_11 -> V_41 . V_211 ) ;
if ( V_212 >= 0 ) {
V_11 -> V_222 = V_213 ;
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
unsigned long V_39 ;
int V_212 ;
F_90 ( & V_2 -> V_223 ) ;
if ( V_11 -> V_224 )
V_39 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_82 ) ;
else
V_39 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_225 = V_39 ;
V_212 = F_92 ( V_7 , V_9 ) ;
F_93 ( & V_2 -> V_223 ) ;
return V_212 ;
}
static int F_94 ( struct V_6 * V_7 , int V_226 ,
unsigned int V_227 , unsigned int T_2 * V_228 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_39 ;
int V_212 ;
F_90 ( & V_2 -> V_223 ) ;
if ( V_11 -> V_224 )
V_39 = F_91 ( V_11 -> V_32 [ 0 ] , 3 , 0 , V_82 ) ;
else
V_39 = F_91 ( V_11 -> V_26 [ 0 ] , 3 , 0 , V_53 ) ;
V_7 -> V_225 = V_39 ;
V_212 = F_95 ( V_7 , V_226 , V_227 , V_228 ) ;
F_93 ( & V_2 -> V_223 ) ;
return V_212 ;
}
static int F_96 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
T_3 V_229 , bool V_230 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_212 = 0 ;
F_90 ( & V_2 -> V_223 ) ;
if ( V_230 && V_11 -> V_46 ) {
for ( V_36 = 0 ; V_36 < V_11 -> V_157 ; V_36 ++ ) {
V_7 -> V_225 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_212 = V_229 ( V_7 , V_18 ) ;
if ( V_212 < 0 )
goto error;
}
} else {
V_36 = F_6 ( V_7 , & V_18 -> V_13 ) ;
if ( V_11 -> V_224 )
V_7 -> V_225 =
F_91 ( V_11 -> V_32 [ V_36 ] ,
3 , 0 , V_82 ) ;
else
V_7 -> V_225 =
F_91 ( V_11 -> V_26 [ V_36 ] ,
3 , 0 , V_53 ) ;
V_212 = V_229 ( V_7 , V_18 ) ;
}
error:
F_93 ( & V_2 -> V_223 ) ;
return V_212 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_231 , false ) ;
}
static int F_98 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_232 , true ) ;
}
static int F_99 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_233 , false ) ;
}
static int F_100 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
return F_96 ( V_7 , V_18 ,
V_234 , true ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_106 = NULL ;
const struct V_57 * V_139 ;
int V_36 , V_235 , V_212 ;
unsigned int V_236 ;
T_1 V_3 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_59 ; V_36 ++ ) {
V_212 = F_102 ( V_2 , V_11 -> V_60 [ V_36 ] ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( V_11 -> V_237 ) {
V_212 = F_102 ( V_2 , V_11 -> V_237 ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( V_11 -> V_205 . V_206 ) {
V_212 = F_103 ( V_2 ,
V_11 -> V_205 . V_206 ,
V_11 -> V_205 . V_206 ) ;
if ( V_212 < 0 )
return V_212 ;
if ( ! V_11 -> V_238 ) {
V_212 = F_104 ( V_2 ,
& V_11 -> V_205 ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 -> V_205 . V_239 = 1 ;
}
}
if ( V_11 -> V_222 ) {
V_212 = F_105 ( V_2 , V_11 -> V_222 ) ;
if ( V_212 < 0 )
return V_212 ;
}
#ifdef F_106
if ( V_11 -> V_240 ) {
const struct V_57 * V_139 ;
for ( V_139 = V_241 ; V_139 -> V_136 ; V_139 ++ ) {
struct V_6 * V_106 ;
V_106 = F_107 ( V_139 , V_2 ) ;
if ( ! V_106 )
return - V_140 ;
V_106 -> V_225 = V_11 -> V_240 ;
V_212 = F_108 ( V_2 , 0 , V_106 ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
#endif
if ( ! V_11 -> V_238 &&
! F_40 ( V_2 , L_1 ) ) {
unsigned int V_242 [ 4 ] ;
F_109 ( V_2 , V_11 -> V_243 ,
V_82 , V_242 ) ;
V_212 = F_110 ( V_2 , L_1 ,
V_242 , V_244 ,
L_27 ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( ! V_11 -> V_238 &&
! F_40 ( V_2 , L_28 ) ) {
V_212 = F_111 ( V_2 , L_28 ,
NULL , V_244 ,
L_29 ,
true , & V_11 -> V_245 . V_246 ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( V_11 -> V_32 || V_11 -> V_26 ) {
V_106 = F_40 ( V_2 , L_30 ) ;
if ( ! V_106 )
V_106 = F_40 ( V_2 , L_31 ) ;
for ( V_36 = 0 ; V_106 && V_36 < V_106 -> V_133 ; V_36 ++ ) {
V_212 = F_112 ( V_2 , V_106 , V_36 ,
F_12 ( V_11 , V_36 ) ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
if ( V_11 -> V_237 && V_11 -> V_26 ) {
const char * V_247 = V_106 ? V_106 -> V_13 . V_136 : NULL ;
for ( V_139 = V_11 -> V_237 ; V_139 -> V_136 ; V_139 ++ ) {
if ( V_247 && strcmp ( V_139 -> V_136 , V_247 ) == 0 )
continue;
V_106 = F_40 ( V_2 , V_139 -> V_136 ) ;
for ( V_36 = 0 ; V_106 && V_36 < V_106 -> V_133 ; V_36 ++ ) {
V_212 = F_112 ( V_2 , V_106 , V_36 ,
V_11 -> V_26 [ V_36 ] ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
}
for ( V_36 = 0 ; V_36 < V_11 -> V_59 ; V_36 ++ ) {
for ( V_139 = V_11 -> V_60 [ V_36 ] ; V_139 -> V_136 ; V_139 ++ ) {
if ( V_139 -> V_248 != V_249 )
continue;
V_106 = F_40 ( V_2 , V_139 -> V_136 ) ;
if ( V_106 == NULL )
continue;
V_236 = V_139 -> V_250 ;
for ( V_235 = 0 ; V_235 < 4 ; V_235 ++ , V_236 >>= 8 ) {
V_3 = V_236 & 0x3f ;
if ( V_3 == 0 )
continue;
switch ( V_236 & 0xc0 ) {
case V_251 :
V_3 = V_11 -> V_41 . V_90 [ V_3 ] ;
break;
case V_252 :
V_3 = V_11 -> V_41 . V_91 [ V_3 ] ;
break;
case V_253 :
V_3 = V_11 -> V_41 . V_86 [ V_3 ] ;
break;
default:
continue;
}
V_212 = F_112 ( V_2 , V_106 , 0 , V_3 ) ;
if ( V_212 < 0 )
return V_212 ;
}
V_236 = V_139 -> V_225 ;
for ( V_235 = 0 ; V_235 < 4 ; V_235 ++ , V_236 >>= 8 ) {
V_3 = V_236 & 0xff ;
if ( V_3 == 0 )
continue;
V_212 = F_112 ( V_2 , V_106 , 0 , V_3 ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
}
F_113 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_212 = F_101 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_115 ( V_2 , & V_11 -> V_41 ) ;
if ( V_212 < 0 )
return V_212 ;
F_116 ( V_2 , V_254 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_255 )
V_11 -> V_255 ( V_2 ) ;
F_26 ( V_2 ) ;
F_54 ( V_2 , V_11 -> V_198 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_116 ( V_2 , V_256 ) ;
F_38 ( V_2 ) ;
F_121 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_122 ( struct V_1 * V_2 , unsigned int V_112 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_151 )
V_11 -> V_151 ( V_2 , V_112 ) ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_124 ( V_2 , & V_11 -> V_257 , V_3 ) ;
}
static int F_125 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_126 ( V_2 , & V_11 -> V_205 , V_261 ,
V_259 ) ;
}
static int F_127 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned int V_263 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_128 ( V_2 , & V_11 -> V_205 ,
V_262 , V_263 , V_261 ) ;
}
static int F_129 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_130 ( V_2 , & V_11 -> V_205 ) ;
}
static int F_131 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_132 ( V_2 , & V_11 -> V_205 ) ;
}
static int F_133 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned int V_263 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_134 ( V_2 , & V_11 -> V_205 ,
V_262 , V_263 , V_261 ) ;
}
static int F_135 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_136 ( V_2 , & V_11 -> V_205 ) ;
}
static int F_137 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_138 ( V_2 , & V_11 -> V_205 ) ;
}
static int F_139 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned int V_263 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_11 ( V_2 , V_11 -> V_26 [ V_261 -> V_264 + 1 ] ,
V_262 , 0 , V_263 ) ;
return 0 ;
}
static int F_140 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_141 ( V_2 ,
V_11 -> V_26 [ V_261 -> V_264 + 1 ] ) ;
return 0 ;
}
static int F_142 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned int V_263 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_28 = V_11 -> V_26 [ V_11 -> V_27 [ V_11 -> V_23 [ 0 ] ] ] ;
V_11 -> V_29 = V_262 ;
V_11 -> V_30 = V_263 ;
F_11 ( V_2 , V_11 -> V_28 , V_262 , 0 , V_263 ) ;
return 0 ;
}
static int F_143 ( struct V_258 * V_259 ,
struct V_1 * V_2 ,
struct V_260 * V_261 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_141 ( V_2 , V_11 -> V_28 ) ;
V_11 -> V_28 = 0 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_265 * V_266 = V_11 -> V_267 ;
const struct V_258 * V_121 ;
bool V_268 ;
int V_36 ;
V_2 -> V_269 = 1 ;
V_2 -> V_270 = V_266 ;
if ( V_11 -> V_238 )
goto V_271;
snprintf ( V_11 -> V_272 , sizeof( V_11 -> V_272 ) ,
L_32 , V_2 -> V_186 ) ;
V_266 -> V_136 = V_11 -> V_272 ;
if ( V_11 -> V_205 . V_273 > 0 ) {
V_121 = V_11 -> V_274 ;
if ( ! V_121 )
V_121 = & V_275 ;
V_266 -> V_276 [ V_277 ] = * V_121 ;
V_266 -> V_276 [ V_277 ] . V_3 = V_11 -> V_205 . V_278 [ 0 ] ;
}
if ( V_11 -> V_26 ) {
V_121 = V_11 -> V_279 ;
if ( ! V_121 ) {
if ( V_11 -> V_46 )
V_121 = & V_280 ;
else
V_121 = & V_281 ;
}
V_266 -> V_276 [ V_282 ] = * V_121 ;
V_266 -> V_276 [ V_282 ] . V_3 = V_11 -> V_26 [ 0 ] ;
}
if ( V_11 -> V_283 ) {
V_266 -> V_276 [ V_277 ] . V_284 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_285 ; V_36 ++ ) {
if ( V_11 -> V_283 [ V_36 ] . V_286 > V_266 -> V_276 [ V_277 ] . V_284 ) {
V_266 -> V_276 [ V_277 ] . V_284 = V_11 -> V_283 [ V_36 ] . V_286 ;
}
}
}
V_271:
if ( V_11 -> V_205 . V_206 || V_11 -> V_222 ) {
snprintf ( V_11 -> V_287 ,
sizeof( V_11 -> V_287 ) ,
L_33 , V_2 -> V_186 ) ;
V_2 -> V_269 = 2 ;
V_2 -> V_207 = V_11 -> V_205 . V_207 ;
V_266 = V_11 -> V_267 + 1 ;
V_266 -> V_136 = V_11 -> V_287 ;
if ( V_11 -> V_215 )
V_266 -> V_288 = V_11 -> V_215 ;
else
V_266 -> V_288 = V_289 ;
if ( V_11 -> V_205 . V_206 ) {
V_121 = V_11 -> V_290 ;
if ( ! V_121 )
V_121 = & V_291 ;
V_266 -> V_276 [ V_277 ] = * V_121 ;
V_266 -> V_276 [ V_277 ] . V_3 = V_11 -> V_205 . V_206 ;
}
if ( V_11 -> V_222 ) {
V_121 = V_11 -> V_292 ;
if ( ! V_121 )
V_121 = & V_293 ;
V_266 -> V_276 [ V_282 ] = * V_121 ;
V_266 -> V_276 [ V_282 ] . V_3 = V_11 -> V_222 ;
}
V_2 -> V_294 = 1 ;
}
if ( V_11 -> V_238 )
return 0 ;
V_268 = ( V_11 -> V_157 > 1 ) &&
! V_11 -> V_46 && ! V_11 -> V_97 &&
( ! V_11 -> V_15 || V_11 -> V_15 -> V_16 > 1 ) ;
if ( V_11 -> V_295 || V_268 ) {
V_2 -> V_269 = 3 ;
V_266 = V_11 -> V_267 + 2 ;
V_266 -> V_136 = V_11 -> V_272 ;
if ( V_11 -> V_295 ) {
V_121 = V_11 -> V_296 ;
if ( ! V_121 )
V_121 = & V_297 ;
V_266 -> V_276 [ V_277 ] = * V_121 ;
V_266 -> V_276 [ V_277 ] . V_3 =
V_11 -> V_295 ;
} else {
V_266 -> V_276 [ V_277 ] =
V_298 ;
V_266 -> V_276 [ V_277 ] . V_3 = 0 ;
}
if ( V_268 ) {
V_121 = V_11 -> V_299 ;
if ( ! V_121 )
V_121 = & V_300 ;
V_266 -> V_276 [ V_282 ] = * V_121 ;
V_266 -> V_276 [ V_282 ] . V_3 =
V_11 -> V_26 [ 1 ] ;
V_266 -> V_276 [ V_282 ] . V_301 =
V_11 -> V_157 - 1 ;
} else {
V_266 -> V_276 [ V_282 ] =
V_298 ;
V_266 -> V_276 [ V_282 ] . V_3 = 0 ;
}
}
return 0 ;
}
static inline void F_145 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 && V_11 -> V_302 )
V_11 -> V_302 ( V_2 ) ;
F_146 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_138 . V_152 ) {
struct V_57 * V_106 = V_11 -> V_138 . V_152 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_138 . V_303 ; V_36 ++ )
F_42 ( V_106 [ V_36 ] . V_136 ) ;
}
F_147 ( & V_11 -> V_138 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_304 . V_152 ) {
struct V_305 * * V_306 = V_11 -> V_304 . V_152 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_304 . V_303 ; V_36 ++ )
F_42 ( V_306 [ V_36 ] ) ;
}
F_147 ( & V_11 -> V_304 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 )
return;
F_145 ( V_2 ) ;
F_113 ( V_2 ) ;
F_148 ( V_2 ) ;
F_150 ( & V_11 -> V_307 ) ;
F_42 ( V_11 ) ;
F_151 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_51 ( V_2 , false ) ;
}
static int F_153 ( struct V_1 * V_2 , T_4 V_308 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_145 ( V_2 ) ;
if ( V_11 && V_11 -> V_309 )
V_11 -> V_309 ( V_2 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
F_53 ( 150 ) ;
V_2 -> V_310 . V_311 ( V_2 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
F_121 ( V_2 , 0x01 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , const char * V_136 )
{
F_42 ( V_2 -> V_186 ) ;
V_2 -> V_186 = F_63 ( V_136 , V_108 ) ;
if ( ! V_2 -> V_186 ) {
F_149 ( V_2 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_158 ( struct V_1 * V_2 )
{
const struct V_312 * V_121 ;
for ( V_121 = V_313 ; V_121 -> V_113 ; V_121 ++ ) {
if ( V_121 -> V_113 != V_2 -> V_113 )
continue;
if ( ( F_85 ( V_2 ) & V_121 -> V_314 ) == V_121 -> V_315 )
return F_157 ( V_2 , V_121 -> V_136 ) ;
}
return 0 ;
}
static int F_159 ( struct V_10 * V_11 , int type , const char * V_136 ,
int V_316 , unsigned long V_39 )
{
struct V_57 * V_139 ;
V_139 = F_59 ( V_11 ) ;
if ( ! V_139 )
return - V_140 ;
* V_139 = V_317 [ type ] ;
V_139 -> V_136 = F_63 ( V_136 , V_108 ) ;
if ( ! V_139 -> V_136 )
return - V_140 ;
V_139 -> V_50 = V_316 ;
if ( F_160 ( V_39 ) )
V_139 -> V_250 = V_318 ;
V_139 -> V_225 = V_39 ;
return 0 ;
}
static int F_161 ( struct V_10 * V_11 , int type ,
const char * V_319 , const char * V_4 ,
const char * V_320 , int V_316 , unsigned long V_39 )
{
char V_136 [ 32 ] ;
snprintf ( V_136 , sizeof( V_136 ) , L_34 , V_319 , V_4 , V_320 ) ;
return F_159 ( V_11 , type , V_136 , V_316 , V_39 ) ;
}
static const char * F_162 ( struct V_10 * V_11 , int V_321 ,
bool V_322 , int * V_50 )
{
struct V_142 * V_143 = & V_11 -> V_41 ;
* V_50 = 0 ;
if ( V_143 -> V_147 == 1 && ! V_11 -> V_323 &&
! V_143 -> V_149 && ! V_143 -> V_146 && V_322 )
return L_35 ;
switch ( V_143 -> V_144 ) {
case V_145 :
if ( V_143 -> V_147 == 1 )
return L_36 ;
if ( V_143 -> V_147 == 2 )
return V_321 ? L_37 : L_36 ;
break;
case V_148 :
if ( V_321 && V_11 -> V_323 )
break;
* V_50 = V_321 ;
return L_38 ;
default:
if ( V_143 -> V_147 == 1 && ! V_11 -> V_323 )
return L_39 ;
break;
}
if ( F_24 ( V_321 >= F_25 ( V_324 ) ) )
return L_39 ;
return V_324 [ V_321 ] ;
}
static void F_163 ( struct V_10 * V_11 , T_1 V_58 , int V_31 )
{
struct V_325 * V_152 ;
if ( V_11 -> V_326 >= F_25 ( V_11 -> V_327 ) - 1 )
return;
V_152 = V_11 -> V_327 + V_11 -> V_326 ;
V_152 -> V_3 = V_58 ;
V_152 -> V_4 = V_53 ;
V_152 -> V_31 = V_31 ;
V_11 -> V_326 ++ ;
V_11 -> V_257 . V_328 = V_11 -> V_327 ;
}
static int F_164 ( struct V_10 * V_11 , T_1 V_40 ,
const char * V_329 , int V_330 ,
int V_31 , T_1 V_331 )
{
int V_212 ;
V_212 = F_165 ( V_11 , V_332 , V_329 , V_330 ,
F_91 ( V_331 , 3 , V_31 , V_53 ) ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_166 ( V_11 , V_333 , V_329 , V_330 ,
F_91 ( V_331 , 3 , V_31 , V_53 ) ) ;
if ( V_212 < 0 )
return V_212 ;
F_163 ( V_11 , V_331 , V_31 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_334 = F_50 ( V_2 , V_3 ) ;
return ( V_334 & V_335 ) != 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 * V_26 = V_11 -> V_336 ;
T_1 * V_337 = V_11 -> V_158 ;
int V_338 = F_25 ( V_11 -> V_336 ) ;
int V_36 , V_153 = 0 ;
V_3 = V_2 -> V_216 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_217 ; V_36 ++ , V_3 ++ ) {
T_1 V_339 ;
unsigned int V_340 = F_2 ( V_2 , V_3 ) ;
int type = F_18 ( V_340 ) ;
if ( type != V_219 || ( V_340 & V_220 ) )
continue;
V_26 [ V_153 ] = V_3 ;
V_337 [ V_153 ] = V_3 ;
V_339 = V_3 ;
for (; ; ) {
int V_155 ;
type = F_18 ( F_2 ( V_2 , V_339 ) ) ;
if ( type == V_118 )
break;
if ( type == V_341 ) {
V_337 [ V_153 ] = V_339 ;
break;
}
V_155 = F_17 ( V_2 , V_339 ) ;
if ( V_155 > 1 ) {
V_337 [ V_153 ] = V_339 ;
break;
} else if ( V_155 != 1 )
break;
if ( F_88 ( V_2 , V_339 , & V_339 , 1 ) != 1 )
break;
}
if ( ++ V_153 >= V_338 )
break;
}
V_11 -> V_26 = V_11 -> V_336 ;
V_11 -> V_32 = V_11 -> V_158 ;
V_11 -> V_157 = V_153 ;
return V_153 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_142 * V_143 = & V_11 -> V_41 ;
T_1 V_342 = V_11 -> V_343 ;
struct V_34 * V_35 = & V_11 -> V_154 [ 0 ] ;
int V_344 ;
int V_36 , V_345 , V_212 , V_31 , V_346 = 0 ;
const char * V_347 = NULL ;
V_344 = F_168 ( V_2 ) ;
if ( V_344 < 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
T_1 V_40 ;
const char * V_348 ;
V_40 = V_143 -> V_42 [ V_36 ] . V_40 ;
if ( ! F_167 ( V_2 , V_40 ) )
continue;
V_348 = F_170 ( V_2 , V_143 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_348 , L_40 ) )
V_348 = L_41 ;
if ( V_347 && ! strcmp ( V_348 , V_347 ) )
V_346 ++ ;
else
V_346 = 0 ;
V_347 = V_348 ;
if ( V_342 ) {
V_31 = F_70 ( V_2 , V_342 , V_40 ) ;
if ( V_31 >= 0 ) {
V_212 = F_164 ( V_11 , V_40 ,
V_348 , V_346 ,
V_31 , V_342 ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
for ( V_345 = 0 ; V_345 < V_344 ; V_345 ++ ) {
T_1 V_156 = F_12 ( V_11 , V_345 ) ;
V_31 = F_70 ( V_2 , V_156 , V_40 ) ;
if ( V_31 >= 0 ) {
V_11 -> V_96 [ V_35 -> V_16 ] = V_40 ;
F_171 ( V_35 , V_348 , V_31 , NULL ) ;
break;
}
}
}
V_11 -> V_14 = 1 ;
V_11 -> V_15 = V_35 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
unsigned int V_166 ;
T_1 V_3 ;
if ( V_143 -> V_165 != 1 )
return 0 ;
V_166 = F_73 ( V_2 , V_143 -> V_42 [ 0 ] . V_40 ) ;
if ( F_74 ( V_166 ) != V_167 )
return 0 ;
if ( V_143 -> V_149 == 1 && V_143 -> V_144 == V_145 )
V_3 = V_143 -> V_86 [ 0 ] ;
else if ( V_143 -> V_147 == 1 && V_143 -> V_144 == V_148 )
V_3 = V_143 -> V_91 [ 0 ] ;
else
return 0 ;
if ( ! ( F_50 ( V_2 , V_3 ) & V_335 ) )
return 0 ;
V_143 -> V_42 [ 1 ] . V_40 = V_3 ;
V_143 -> V_42 [ 1 ] . type = V_56 ;
V_143 -> V_165 = 2 ;
V_11 -> V_38 = 1 ;
F_66 ( L_42 , V_3 ) ;
return 0 ;
}
static void F_173 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_349 )
{
F_15 ( V_2 , V_3 , V_349 ) ;
if ( F_174 ( V_2 , V_3 , V_82 ) )
F_27 ( V_2 , V_3 , 0 , V_209 ,
V_210 ) ;
}
static int F_175 ( int V_144 )
{
if ( V_144 == V_148 )
return V_44 ;
else
return V_76 ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
T_1 V_3 = V_143 -> V_42 [ V_36 ] . V_40 ;
if ( F_167 ( V_2 , V_3 ) ) {
F_22 ( V_2 , V_3 , V_143 -> V_42 [ V_36 ] . type ) ;
if ( F_2 ( V_2 , V_3 ) & V_208 )
F_27 ( V_2 , V_3 , 0 ,
V_209 ,
V_350 ) ;
}
}
if ( V_11 -> V_343 ) {
int V_153 = F_17 ( V_2 , V_11 -> V_343 ) ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ )
F_27 ( V_2 , V_11 -> V_343 , 0 ,
V_209 ,
F_177 ( V_36 ) ) ;
}
}
static T_1 F_178 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_152 [ 5 ] ;
int V_36 , V_351 ;
if ( F_18 ( F_2 ( V_2 , V_3 ) ) == V_352 )
return V_3 ;
V_351 = F_88 ( V_2 , V_3 , V_152 , F_25 ( V_152 ) ) ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
if ( F_18 ( F_2 ( V_2 , V_152 [ V_36 ] ) ) == V_352 )
return V_152 [ V_36 ] ;
}
return 0 ;
}
static T_1 F_179 ( struct V_1 * V_2 , T_1 V_40 )
{
T_1 V_353 [ 5 ] ;
int V_351 = F_88 ( V_2 , V_40 , V_353 ,
F_25 ( V_353 ) ) ;
if ( V_351 != 1 ||
F_18 ( F_2 ( V_2 , V_353 [ 0 ] ) ) != V_341 )
return V_40 ;
return V_353 [ 0 ] ;
}
static T_1 F_180 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_202 )
{
T_1 V_58 [ 5 ] ;
int V_36 , V_351 ;
V_40 = F_179 ( V_2 , V_40 ) ;
V_351 = F_88 ( V_2 , V_40 , V_58 , F_25 ( V_58 ) ) ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
if ( F_178 ( V_2 , V_58 [ V_36 ] ) == V_202 )
return V_58 [ V_36 ] ;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_202 )
{
T_1 V_58 [ 5 ] ;
int V_36 , V_351 ;
V_40 = F_179 ( V_2 , V_40 ) ;
V_351 = F_88 ( V_2 , V_40 , V_58 , F_25 ( V_58 ) ) ;
if ( V_351 < 2 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
if ( F_178 ( V_2 , V_58 [ V_36 ] ) == V_202 ) {
F_182 ( V_2 , V_40 , 0 ,
V_54 , V_36 ) ;
return 0 ;
}
}
return 0 ;
}
static bool F_183 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( F_80 ( V_3 , V_11 -> V_205 . V_278 ,
F_25 ( V_11 -> V_354 ) ) ||
F_80 ( V_3 , V_11 -> V_205 . V_355 ,
F_25 ( V_11 -> V_205 . V_355 ) ) ||
F_80 ( V_3 , V_11 -> V_205 . V_356 ,
F_25 ( V_11 -> V_205 . V_356 ) ) )
return true ;
for ( V_36 = 0 ; V_36 < V_11 -> V_323 ; V_36 ++ ) {
if ( V_11 -> V_357 [ V_36 ] . V_202 == V_3 )
return true ;
}
return false ;
}
static T_1 F_184 ( struct V_1 * V_2 , T_1 V_40 )
{
T_1 V_353 [ 5 ] ;
int V_36 , V_351 ;
V_40 = F_179 ( V_2 , V_40 ) ;
V_351 = F_88 ( V_2 , V_40 , V_353 , F_25 ( V_353 ) ) ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
T_1 V_3 = F_178 ( V_2 , V_353 [ V_36 ] ) ;
if ( ! V_3 )
continue;
if ( ! F_183 ( V_2 , V_3 ) )
return V_3 ;
}
return 0 ;
}
static bool F_185 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 V_202 )
{
T_1 V_353 [ 5 ] ;
int V_36 , V_351 ;
if ( ! V_40 || ! V_202 )
return false ;
V_40 = F_179 ( V_2 , V_40 ) ;
V_351 = F_88 ( V_2 , V_40 , V_353 , F_25 ( V_353 ) ) ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
T_1 V_3 = F_178 ( V_2 , V_353 [ V_36 ] ) ;
if ( V_3 == V_202 )
return true ;
}
return false ;
}
static T_1 F_186 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_358 = F_179 ( V_2 , V_40 ) ;
T_1 V_3 , V_359 , V_353 [ 5 ] ;
int V_36 , V_351 = F_88 ( V_2 , V_358 , V_353 ,
F_25 ( V_353 ) ) ;
if ( V_351 == 1 )
return F_184 ( V_2 , V_40 ) ;
V_359 = 0 ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
if ( V_353 [ V_36 ] == V_11 -> V_343 )
continue;
V_3 = F_178 ( V_2 , V_353 [ V_36 ] ) ;
if ( V_3 && ! F_183 ( V_2 , V_3 ) ) {
if ( V_359 )
return 0 ;
V_359 = V_3 ;
}
}
return V_359 ;
}
static inline unsigned int F_187 ( unsigned int V_360 )
{
T_1 V_3 = F_160 ( V_360 ) ;
unsigned int V_4 ;
if ( F_24 ( V_3 >= V_361 ) )
return 0 ;
V_4 = F_188 ( V_360 ) ;
return ( V_3 << 1 ) | V_4 ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
memset ( V_11 -> V_362 , 0 , sizeof( V_11 -> V_362 ) ) ;
memset ( V_11 -> V_363 , 0 , sizeof( V_11 -> V_363 ) ) ;
}
static int F_190 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_202 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
unsigned int V_39 ;
int V_364 = 0 ;
V_3 = F_191 ( V_2 , V_40 , V_202 ) ;
if ( V_3 ) {
V_39 = F_91 ( V_3 , 3 , 0 , V_82 ) ;
if ( F_192 ( V_11 -> V_362 , V_3 ) )
V_364 += V_365 ;
else
F_193 ( V_11 -> V_362 , V_39 ) ;
} else
V_364 += V_365 ;
V_3 = F_194 ( V_2 , V_40 , V_202 ) ;
if ( V_3 ) {
unsigned int V_366 = F_18 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_366 == V_118 || V_366 == V_352 )
V_39 = F_91 ( V_3 , 3 , 0 , V_82 ) ;
else
V_39 = F_91 ( V_3 , 3 , 0 , V_53 ) ;
if ( F_192 ( V_11 -> V_363 , V_39 ) )
V_364 += V_365 ;
else
F_193 ( V_11 -> V_363 , V_39 ) ;
} else
V_364 += V_365 ;
return V_364 ;
}
static int F_195 ( struct V_1 * V_2 , int V_367 ,
const T_1 * V_70 , T_1 * V_368 ,
const struct V_369 * V_370 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_36 , V_235 ;
int V_364 = 0 ;
T_1 V_202 ;
if ( ! V_367 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_367 ; V_36 ++ ) {
T_1 V_40 = V_70 [ V_36 ] ;
if ( ! V_368 [ V_36 ] )
V_368 [ V_36 ] = F_184 ( V_2 , V_40 ) ;
if ( ! V_368 [ V_36 ] && ! V_36 ) {
for ( V_235 = 1 ; V_235 < V_367 ; V_235 ++ ) {
if ( F_185 ( V_2 , V_40 , V_368 [ V_235 ] ) ) {
V_368 [ 0 ] = V_368 [ V_235 ] ;
V_368 [ V_235 ] = 0 ;
break;
}
}
}
V_202 = V_368 [ V_36 ] ;
if ( ! V_202 ) {
if ( F_185 ( V_2 , V_40 , V_368 [ 0 ] ) )
V_202 = V_368 [ 0 ] ;
else if ( V_143 -> V_147 > V_36 &&
F_185 ( V_2 , V_40 ,
V_11 -> V_354 [ V_36 ] ) )
V_202 = V_11 -> V_354 [ V_36 ] ;
if ( V_202 ) {
if ( ! V_36 )
V_364 += V_370 -> V_371 ;
else if ( V_36 == 1 )
V_364 += V_370 -> V_372 ;
else
V_364 += V_370 -> V_373 ;
} else if ( F_185 ( V_2 , V_40 ,
V_11 -> V_354 [ 0 ] ) ) {
V_202 = V_11 -> V_354 [ 0 ] ;
V_364 += V_370 -> V_374 ;
} else if ( ! V_36 )
V_364 += V_370 -> V_375 ;
else
V_364 += V_370 -> V_376 ;
}
if ( V_202 )
V_364 += F_190 ( V_2 , V_40 , V_202 ) ;
}
return V_364 ;
}
static bool F_196 ( struct V_1 * V_2 , int V_377 ,
const T_1 * V_70 , T_1 * V_368 )
{
int V_36 ;
bool V_378 = false ;
for ( V_36 = 0 ; V_36 < V_377 ; V_36 ++ ) {
if ( V_368 [ V_36 ] )
continue;
V_368 [ V_36 ] = F_186 ( V_2 , V_70 [ V_36 ] ) ;
if ( V_368 [ V_36 ] )
V_378 = true ;
}
return V_378 ;
}
static int F_197 ( struct V_1 * V_2 ,
bool V_379 ,
bool V_380 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_36 , V_212 , V_364 ;
V_11 -> V_205 . V_273 = V_143 -> V_147 ;
V_11 -> V_205 . V_278 = V_11 -> V_354 ;
memset ( V_11 -> V_354 , 0 , sizeof( V_11 -> V_354 ) ) ;
memset ( V_11 -> V_205 . V_355 , 0 , sizeof( V_11 -> V_205 . V_355 ) ) ;
memset ( V_11 -> V_205 . V_356 , 0 , sizeof( V_11 -> V_205 . V_356 ) ) ;
V_11 -> V_323 = 0 ;
F_189 ( V_2 ) ;
V_364 = 0 ;
if ( V_379 ) {
bool V_381 ;
do {
V_381 = F_196 ( V_2 , V_143 -> V_147 ,
V_143 -> V_91 ,
V_11 -> V_354 ) ;
V_381 |= F_196 ( V_2 , V_143 -> V_149 ,
V_143 -> V_86 ,
V_11 -> V_205 . V_355 ) ;
V_381 |= F_196 ( V_2 , V_143 -> V_146 ,
V_143 -> V_90 ,
V_11 -> V_205 . V_356 ) ;
if ( V_380 && V_143 -> V_147 == 1 &&
V_143 -> V_144 != V_145 ) {
V_212 = F_198 ( V_2 , V_143 -> V_91 [ 0 ] , true , 0 ) ;
if ( ! V_212 )
V_381 = true ;
}
} while ( V_381 );
}
V_364 += F_195 ( V_2 , V_143 -> V_147 , V_143 -> V_91 ,
V_11 -> V_354 ,
& V_382 ) ;
V_11 -> V_205 . V_273 = 0 ;
for ( V_36 = 0 ; V_36 < V_143 -> V_147 ; V_36 ++ ) {
if ( V_11 -> V_354 [ V_36 ] )
V_11 -> V_205 . V_273 ++ ;
else {
memmove ( V_11 -> V_354 + V_36 ,
V_11 -> V_354 + V_36 + 1 ,
sizeof( T_1 ) * ( V_143 -> V_147 - V_36 - 1 ) ) ;
V_11 -> V_354 [ V_143 -> V_147 - 1 ] = 0 ;
}
}
if ( V_380 &&
V_143 -> V_147 == 1 && V_143 -> V_144 != V_145 ) {
V_212 = F_198 ( V_2 , V_143 -> V_91 [ 0 ] , false , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( V_143 -> V_144 != V_148 ) {
V_212 = F_195 ( V_2 , V_143 -> V_149 , V_143 -> V_86 ,
V_11 -> V_205 . V_355 ,
& V_383 ) ;
if ( V_212 < 0 )
return V_212 ;
V_364 += V_212 ;
}
if ( V_143 -> V_144 != V_145 ) {
V_212 = F_195 ( V_2 , V_143 -> V_146 ,
V_143 -> V_90 ,
V_11 -> V_205 . V_356 ,
& V_383 ) ;
if ( V_212 < 0 )
return V_212 ;
V_364 += V_212 ;
}
if ( V_143 -> V_147 == 1 && V_143 -> V_144 != V_145 ) {
V_212 = F_198 ( V_2 , V_143 -> V_91 [ 0 ] , false , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_364 += V_212 ;
}
if ( V_143 -> V_149 && V_143 -> V_144 == V_145 ) {
int V_384 = 0 ;
if ( V_143 -> V_147 >= 3 )
V_384 = 1 ;
V_212 = F_198 ( V_2 , V_143 -> V_86 [ 0 ] , false ,
V_384 ) ;
if ( V_212 < 0 )
return V_212 ;
V_364 += V_212 ;
}
if ( V_11 -> V_323 == 2 ) {
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ )
V_11 -> V_354 [ V_11 -> V_205 . V_273 ++ ] =
V_11 -> V_357 [ V_36 ] . V_202 ;
V_11 -> V_385 = 2 ;
} else if ( V_11 -> V_323 ) {
V_11 -> V_323 = 0 ;
V_364 += V_386 ;
}
return V_364 ;
}
static void F_199 ( struct V_10 * V_11 , struct V_142 * V_143 )
{
F_200 ( L_43 ,
V_143 -> V_91 [ 0 ] , V_143 -> V_91 [ 1 ] ,
V_143 -> V_91 [ 2 ] , V_143 -> V_91 [ 2 ] ,
V_11 -> V_205 . V_278 [ 0 ] ,
V_11 -> V_205 . V_278 [ 1 ] ,
V_11 -> V_205 . V_278 [ 2 ] ,
V_11 -> V_205 . V_278 [ 3 ] ) ;
if ( V_11 -> V_323 > 0 )
F_200 ( L_44 ,
V_11 -> V_323 ,
V_11 -> V_357 [ 0 ] . V_40 , V_11 -> V_357 [ 1 ] . V_40 ,
V_11 -> V_357 [ 0 ] . V_202 , V_11 -> V_357 [ 1 ] . V_202 ) ;
F_200 ( L_45 ,
V_143 -> V_86 [ 0 ] , V_143 -> V_86 [ 1 ] ,
V_143 -> V_86 [ 2 ] , V_143 -> V_86 [ 2 ] ,
V_11 -> V_205 . V_355 [ 0 ] ,
V_11 -> V_205 . V_355 [ 1 ] ,
V_11 -> V_205 . V_355 [ 2 ] ,
V_11 -> V_205 . V_355 [ 3 ] ) ;
F_200 ( L_46 ,
V_143 -> V_90 [ 0 ] , V_143 -> V_90 [ 1 ] ,
V_143 -> V_90 [ 2 ] , V_143 -> V_90 [ 3 ] ,
V_11 -> V_205 . V_356 [ 0 ] ,
V_11 -> V_205 . V_356 [ 1 ] ,
V_11 -> V_205 . V_356 [ 2 ] ,
V_11 -> V_205 . V_356 [ 3 ] ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
struct V_142 * V_387 ;
int V_388 = V_389 ;
int V_364 ;
bool V_379 = true , V_380 = true ;
bool V_390 = true , V_391 = true ;
bool V_392 = false ;
V_387 = F_202 ( sizeof( * V_387 ) , V_108 ) ;
if ( ! V_387 )
return - V_140 ;
* V_387 = * V_143 ;
for (; ; ) {
V_364 = F_197 ( V_2 , V_379 ,
V_380 ) ;
if ( V_364 < 0 ) {
F_42 ( V_387 ) ;
return V_364 ;
}
F_200 ( L_47 ,
V_143 -> V_144 , V_379 , V_380 ,
V_364 ) ;
F_199 ( V_11 , V_143 ) ;
if ( V_364 < V_388 ) {
V_388 = V_364 ;
* V_387 = * V_143 ;
V_390 = V_379 ;
V_391 = V_380 ;
}
if ( ! V_364 )
break;
V_380 = ! V_380 ;
if ( ! V_380 )
continue;
V_379 = ! V_379 ;
if ( ! V_379 )
continue;
if ( V_392 )
break;
V_392 = true ;
if ( V_143 -> V_146 > 0 &&
V_143 -> V_144 == V_148 ) {
V_143 -> V_149 = V_143 -> V_147 ;
memcpy ( V_143 -> V_86 , V_143 -> V_91 ,
sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_147 = V_143 -> V_146 ;
memcpy ( V_143 -> V_91 , V_143 -> V_90 ,
sizeof( V_143 -> V_90 ) ) ;
V_143 -> V_146 = 0 ;
memset ( V_143 -> V_90 , 0 , sizeof( V_143 -> V_90 ) ) ;
V_143 -> V_144 = V_145 ;
V_379 = true ;
continue;
}
if ( V_143 -> V_149 > 0 &&
V_143 -> V_144 == V_145 ) {
V_143 -> V_146 = V_143 -> V_147 ;
memcpy ( V_143 -> V_90 , V_143 -> V_91 ,
sizeof( V_143 -> V_90 ) ) ;
V_143 -> V_147 = V_143 -> V_149 ;
memcpy ( V_143 -> V_91 , V_143 -> V_86 ,
sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_149 = 0 ;
memset ( V_143 -> V_86 , 0 , sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_144 = V_148 ;
V_379 = true ;
continue;
}
break;
}
if ( V_364 ) {
* V_143 = * V_387 ;
F_197 ( V_2 , V_390 , V_391 ) ;
}
F_200 ( L_48 ,
V_143 -> V_144 , V_390 , V_391 ) ;
F_199 ( V_11 , V_143 ) ;
if ( V_143 -> V_91 [ 0 ] )
V_11 -> V_243 =
F_191 ( V_2 , V_143 -> V_91 [ 0 ] ,
V_11 -> V_205 . V_278 [ 0 ] ) ;
F_189 ( V_2 ) ;
F_42 ( V_387 ) ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 ,
const char * V_319 , int V_316 ,
T_1 V_3 , unsigned int V_393 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_39 ;
if ( ! V_3 )
return 0 ;
V_39 = F_91 ( V_3 , V_393 , 0 , V_82 ) ;
if ( F_192 ( V_11 -> V_362 , V_39 ) && V_393 != 2 )
return 0 ;
F_193 ( V_11 -> V_362 , V_39 ) ;
return F_165 ( V_2 -> V_11 , V_332 , V_319 , V_316 ,
V_39 ) ;
}
static int F_204 ( struct V_1 * V_2 ,
const char * V_319 , int V_316 ,
T_1 V_3 )
{
int V_393 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_394 )
V_393 = 3 ;
return F_203 ( V_2 , V_319 , V_316 , V_3 , V_393 ) ;
}
static int F_205 ( struct V_1 * V_2 ,
const char * V_319 , int V_316 ,
T_1 V_3 , unsigned int V_393 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_366 ;
int type ;
unsigned long V_39 ;
if ( ! V_3 )
return 0 ;
V_366 = F_18 ( F_2 ( V_2 , V_3 ) ) ;
if ( V_366 == V_118 || V_366 == V_352 ) {
type = V_333 ;
V_39 = F_91 ( V_3 , V_393 , 0 , V_82 ) ;
} else if ( F_17 ( V_2 , V_3 ) == 1 ) {
type = V_333 ;
V_39 = F_91 ( V_3 , V_393 , 0 , V_53 ) ;
} else {
type = V_395 ;
V_39 = F_91 ( V_3 , V_393 , 2 , V_53 ) ;
}
if ( F_192 ( V_11 -> V_363 , V_39 ) && V_393 != 2 )
return 0 ;
F_193 ( V_11 -> V_363 , V_39 ) ;
return F_166 ( V_2 -> V_11 , type , V_319 , V_316 , V_39 ) ;
}
static int F_206 ( struct V_1 * V_2 , const char * V_319 ,
int V_316 , T_1 V_3 )
{
int V_393 = 1 ;
if ( F_2 ( V_2 , V_3 ) & V_394 )
V_393 = 3 ;
return F_205 ( V_2 , V_319 , V_316 , V_3 , V_393 ) ;
}
static T_1 F_194 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 V_202 )
{
T_1 V_58 = F_180 ( V_2 , V_40 , V_202 ) ;
if ( F_174 ( V_2 , V_40 , V_82 ) )
return V_40 ;
else if ( V_58 && F_174 ( V_2 , V_58 , V_53 ) )
return V_58 ;
else if ( F_174 ( V_2 , V_202 , V_82 ) )
return V_202 ;
return 0 ;
}
static T_1 F_191 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 V_202 )
{
T_1 V_58 = F_180 ( V_2 , V_40 , V_202 ) ;
if ( F_207 ( V_2 , V_202 , V_82 ) )
return V_202 ;
else if ( F_207 ( V_2 , V_58 , V_82 ) )
return V_58 ;
else if ( F_207 ( V_2 , V_40 , V_82 ) )
return V_40 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
const struct V_142 * V_143 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_212 , V_396 ;
V_396 = V_143 -> V_147 ;
if ( V_11 -> V_323 > 0 && V_143 -> V_147 < 3 )
V_396 += V_11 -> V_323 ;
for ( V_36 = 0 ; V_36 < V_396 ; V_36 ++ ) {
const char * V_136 ;
int V_50 ;
T_1 V_202 , V_40 ;
T_1 V_397 , V_398 ;
V_202 = V_11 -> V_205 . V_278 [ V_36 ] ;
if ( ! V_202 )
continue;
if ( V_36 >= V_143 -> V_147 ) {
V_40 = V_11 -> V_357 [ V_36 - 1 ] . V_40 ;
V_50 = 0 ;
V_136 = V_324 [ V_36 ] ;
} else {
V_40 = V_143 -> V_91 [ V_36 ] ;
V_136 = F_162 ( V_11 , V_36 , true , & V_50 ) ;
}
V_397 = F_194 ( V_2 , V_40 , V_202 ) ;
V_398 = F_191 ( V_2 , V_40 , V_202 ) ;
if ( ! V_136 || ! strcmp ( V_136 , L_49 ) ) {
V_212 = F_203 ( V_2 , L_50 , 0 , V_398 , 1 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_203 ( V_2 , L_51 , 0 , V_398 , 2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_205 ( V_2 , L_50 , 0 , V_397 , 1 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_205 ( V_2 , L_51 , 0 , V_397 , 2 ) ;
if ( V_212 < 0 )
return V_212 ;
} else {
V_212 = F_204 ( V_2 , V_136 , V_50 , V_398 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_206 ( V_2 , V_136 , V_50 , V_397 ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_202 , const char * V_319 ,
int V_316 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_397 , V_398 ;
int V_212 ;
if ( ! V_202 ) {
unsigned int V_39 ;
if ( ! ( F_2 ( V_2 , V_40 ) & V_208 ) )
return 0 ;
V_39 = F_91 ( V_40 , 3 , 0 , V_82 ) ;
if ( F_192 ( V_11 -> V_363 , V_39 ) )
return 0 ;
F_193 ( V_11 -> V_363 , V_39 ) ;
return F_166 ( V_11 , V_333 , V_319 , V_316 , V_39 ) ;
}
V_397 = F_194 ( V_2 , V_40 , V_202 ) ;
V_398 = F_191 ( V_2 , V_40 , V_202 ) ;
V_212 = F_204 ( V_2 , V_319 , V_316 , V_398 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_206 ( V_2 , V_319 , V_316 , V_397 ) ;
if ( V_212 < 0 )
return V_212 ;
return 0 ;
}
static struct V_305 * F_210 ( struct V_1 * V_2 ,
unsigned int V_153 ,
struct V_399 * V_400 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_305 * * V_401 , * V_306 ;
F_60 ( & V_11 -> V_304 , sizeof( V_306 ) , 8 ) ;
V_401 = F_61 ( & V_11 -> V_304 ) ;
if ( ! V_401 )
return NULL ;
V_306 = F_41 ( sizeof( * V_306 ) + sizeof( long ) * ( V_153 + 1 ) , V_108 ) ;
* V_401 = V_306 ;
if ( V_306 )
V_306 -> V_400 = V_400 ;
return V_306 ;
}
static int F_211 ( struct V_1 * V_2 , int V_69 ,
const T_1 * V_70 ,
const T_1 * V_368 ,
const char * V_319 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_305 * V_306 ;
char V_136 [ 32 ] ;
int V_36 , V_155 , V_212 ;
if ( ! V_69 || ! V_70 [ 0 ] )
return 0 ;
if ( V_69 == 1 ) {
T_1 V_202 = * V_368 ;
if ( ! V_202 )
V_202 = V_11 -> V_205 . V_278 [ 0 ] ;
return F_209 ( V_2 , * V_70 , V_202 , V_319 , 0 ) ;
}
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
T_1 V_202 ;
if ( V_368 [ V_69 - 1 ] )
V_202 = V_368 [ V_36 ] ;
else
V_202 = 0 ;
if ( V_69 == 2 && V_36 == 1 && ! strcmp ( V_319 , L_36 ) ) {
V_212 = F_209 ( V_2 , V_70 [ V_36 ] , V_202 ,
L_37 , 0 ) ;
} else if ( V_69 >= 3 ) {
snprintf ( V_136 , sizeof( V_136 ) , L_52 ,
V_319 , V_324 [ V_36 ] ) ;
V_212 = F_209 ( V_2 , V_70 [ V_36 ] , V_202 ,
V_136 , 0 ) ;
} else {
V_212 = F_209 ( V_2 , V_70 [ V_36 ] , V_202 ,
V_319 , V_36 ) ;
}
if ( V_212 < 0 )
return V_212 ;
}
if ( V_368 [ V_69 - 1 ] )
return 0 ;
V_306 = F_210 ( V_2 , V_69 , & V_402 ) ;
if ( ! V_306 )
return - V_140 ;
V_155 = 0 ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
T_1 V_398 ;
if ( ! V_70 [ V_36 ] || ! V_368 [ V_36 ] )
continue;
V_398 = F_191 ( V_2 , V_70 [ V_36 ] , V_368 [ V_36 ] ) ;
if ( V_398 )
V_306 -> V_403 [ V_155 ++ ] =
F_91 ( V_398 , 3 , 0 , V_82 ) ;
}
if ( V_155 ) {
snprintf ( V_136 , sizeof( V_136 ) , L_53 , V_319 ) ;
V_212 = F_159 ( V_11 , V_404 , V_136 , 0 , ( long ) V_306 ) ;
if ( V_212 < 0 )
return V_212 ;
}
return 0 ;
}
static int F_212 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_211 ( V_2 , V_11 -> V_41 . V_149 ,
V_11 -> V_41 . V_86 ,
V_11 -> V_205 . V_355 ,
L_38 ) ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return F_211 ( V_2 , V_11 -> V_41 . V_146 ,
V_11 -> V_41 . V_90 ,
V_11 -> V_205 . V_356 ,
L_36 ) ;
}
static void F_214 ( struct V_1 * V_2 ,
T_1 V_40 , int V_349 ,
T_1 V_202 )
{
int V_36 , V_351 ;
T_1 V_3 , V_58 = 0 ;
T_1 V_353 [ V_405 ] ;
F_173 ( V_2 , V_40 , V_349 ) ;
V_3 = F_179 ( V_2 , V_40 ) ;
V_351 = F_88 ( V_2 , V_3 , V_353 , F_25 ( V_353 ) ) ;
for ( V_36 = 0 ; V_36 < V_351 ; V_36 ++ ) {
if ( F_178 ( V_2 , V_353 [ V_36 ] ) != V_202 )
continue;
V_58 = V_353 [ V_36 ] ;
break;
}
if ( ! V_58 )
return;
if ( V_351 > 1 )
F_27 ( V_2 , V_3 , 0 , V_54 , V_36 ) ;
if ( F_174 ( V_2 , V_58 , V_53 ) ) {
F_27 ( V_2 , V_58 , 0 , V_209 ,
F_215 ( 0 ) ) ;
F_27 ( V_2 , V_58 , 0 , V_209 ,
F_215 ( 1 ) ) ;
}
V_3 = F_191 ( V_2 , V_40 , V_202 ) ;
if ( V_3 )
F_27 ( V_2 , V_3 , 0 , V_209 ,
V_406 ) ;
V_3 = F_194 ( V_2 , V_40 , V_202 ) ;
if ( V_3 == V_58 && F_174 ( V_2 , V_202 , V_82 ) )
F_27 ( V_2 , V_202 , 0 , V_209 ,
V_406 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_349 = F_175 ( V_11 -> V_41 . V_144 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 <= V_407 ; V_36 ++ ) {
T_1 V_3 = V_11 -> V_41 . V_91 [ V_36 ] ;
if ( V_3 )
F_214 ( V_2 , V_3 , V_349 ,
V_11 -> V_205 . V_278 [ V_36 ] ) ;
}
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
T_1 V_40 , V_202 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_41 . V_149 ; V_36 ++ ) {
if ( V_11 -> V_41 . V_144 == V_148 )
break;
V_40 = V_11 -> V_41 . V_86 [ V_36 ] ;
if ( ! V_40 )
break;
V_202 = V_11 -> V_205 . V_355 [ V_36 ] ;
if ( ! V_202 ) {
if ( V_36 > 0 && V_11 -> V_205 . V_355 [ 0 ] )
V_202 = V_11 -> V_205 . V_355 [ 0 ] ;
else
V_202 = V_11 -> V_205 . V_278 [ 0 ] ;
}
F_214 ( V_2 , V_40 , V_44 , V_202 ) ;
}
for ( V_36 = 0 ; V_36 < V_11 -> V_41 . V_146 ; V_36 ++ ) {
if ( V_11 -> V_41 . V_144 == V_145 )
break;
V_40 = V_11 -> V_41 . V_90 [ V_36 ] ;
if ( ! V_40 )
break;
V_202 = V_11 -> V_205 . V_356 [ V_36 ] ;
if ( ! V_202 ) {
if ( V_36 > 0 && V_11 -> V_205 . V_356 [ 0 ] )
V_202 = V_11 -> V_205 . V_356 [ 0 ] ;
else
V_202 = V_11 -> V_205 . V_278 [ 0 ] ;
}
F_214 ( V_2 , V_40 , V_76 , V_202 ) ;
}
}
static bool F_218 ( struct V_1 * V_2 ,
unsigned int V_408 , T_1 V_3 )
{
unsigned int V_166 , V_340 ;
V_166 = F_73 ( V_2 , V_3 ) ;
if ( F_219 ( V_166 ) != V_409 )
return false ;
if ( V_408 && F_220 ( V_166 ) != V_408 )
return false ;
V_340 = F_50 ( V_2 , V_3 ) ;
if ( ! ( V_340 & V_410 ) )
return false ;
return true ;
}
static int F_198 ( struct V_1 * V_2 ,
T_1 V_411 ,
bool V_412 , int V_384 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int type , V_36 , V_235 , V_368 , V_69 , V_413 ;
unsigned int V_166 = F_73 ( V_2 , V_411 ) ;
unsigned int V_408 = F_220 ( V_166 ) ;
int V_364 = 0 ;
V_413 = V_11 -> V_323 ;
if ( V_413 >= 2 )
goto V_414;
V_69 = 0 ;
for ( type = V_170 ; type >= V_56 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
if ( V_143 -> V_42 [ V_36 ] . type != type )
continue;
if ( F_218 ( V_2 , V_408 ,
V_143 -> V_42 [ V_36 ] . V_40 ) )
V_69 ++ ;
}
}
if ( V_69 < 2 )
goto V_414;
V_368 = V_11 -> V_205 . V_273 ;
for ( type = V_170 ; type >= V_56 ; type -- ) {
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
T_1 V_3 = V_143 -> V_42 [ V_36 ] . V_40 ;
T_1 V_202 = 0 ;
if ( V_143 -> V_42 [ V_36 ] . type != type )
continue;
if ( ! F_218 ( V_2 , V_408 , V_3 ) )
continue;
for ( V_235 = 0 ; V_235 < V_11 -> V_323 ; V_235 ++ ) {
if ( V_3 == V_11 -> V_357 [ V_235 ] . V_40 )
break;
}
if ( V_235 < V_11 -> V_323 )
continue;
if ( V_384 && V_384 + V_11 -> V_323 < V_368 ) {
V_202 = V_11 -> V_354 [ V_384 + V_11 -> V_323 ] ;
if ( ! F_185 ( V_2 , V_3 , V_202 ) )
V_202 = 0 ;
}
if ( V_412 )
V_202 = F_186 ( V_2 , V_3 ) ;
else if ( ! V_202 )
V_202 = F_184 ( V_2 , V_3 ) ;
if ( ! V_202 ) {
V_364 ++ ;
continue;
}
V_11 -> V_357 [ V_11 -> V_323 ] . V_40 = V_3 ;
V_11 -> V_357 [ V_11 -> V_323 ] . V_202 = V_202 ;
V_11 -> V_323 ++ ;
if ( V_11 -> V_323 >= 2 )
break;
}
}
V_414:
if ( V_364 )
V_364 = V_386 ;
if ( V_413 == V_11 -> V_323 ) {
if ( V_412 )
return 1 ;
else
return V_364 ;
}
if ( ! V_412 && V_11 -> V_323 < 2 ) {
V_11 -> V_323 = V_413 ;
return V_364 ;
}
return 0 ;
}
static int F_221 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_9 -> type = V_132 ;
V_9 -> V_133 = 1 ;
V_9 -> V_20 . V_21 . V_49 = V_11 -> V_323 + 1 ;
if ( V_9 -> V_20 . V_21 . V_22 > V_11 -> V_323 )
V_9 -> V_20 . V_21 . V_22 = V_11 -> V_323 ;
sprintf ( V_9 -> V_20 . V_21 . V_136 , L_54 ,
( V_9 -> V_20 . V_21 . V_22 + 1 ) * 2 ) ;
return 0 ;
}
static int F_222 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_18 -> V_20 . V_21 . V_22 [ 0 ] = ( V_11 -> V_385 - 1 ) / 2 ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 , int V_31 , bool V_415 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 = V_11 -> V_357 [ V_31 ] . V_40 ;
if ( ! V_11 -> V_357 [ V_31 ] . V_416 )
V_11 -> V_357 [ V_31 ] . V_416 =
F_28 ( V_2 , V_3 , 0 ,
V_80 , 0 ) ;
if ( V_415 ) {
F_224 ( V_2 , V_3 , V_76 ) ;
if ( F_2 ( V_2 , V_3 ) & V_208 )
F_19 ( V_2 , V_3 , V_82 , 0 ,
V_52 , 0 ) ;
F_181 ( V_2 , V_3 , V_11 -> V_357 [ V_31 ] . V_202 ) ;
} else {
if ( F_2 ( V_2 , V_3 ) & V_208 )
F_19 ( V_2 , V_3 , V_82 , 0 ,
V_52 , V_52 ) ;
F_224 ( V_2 , V_3 ,
V_11 -> V_357 [ V_31 ] . V_416 ) ;
}
return 0 ;
}
static int F_225 ( struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 , V_321 ;
V_321 = V_18 -> V_20 . V_21 . V_22 [ 0 ] ;
if ( V_321 < 0 || V_321 > V_11 -> V_323 )
return - V_137 ;
if ( V_321 == ( V_11 -> V_385 - 1 ) / 2 )
return 0 ;
V_11 -> V_385 = ( V_321 + 1 ) * 2 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_323 ; V_36 ++ )
F_223 ( V_2 , V_36 , V_36 < V_321 ) ;
V_11 -> V_205 . V_417 = V_11 -> V_385 ;
if ( V_11 -> V_418 && ! V_11 -> V_419 )
V_11 -> V_205 . V_273 = V_11 -> V_205 . V_417 / 2 ;
return 1 ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_323 > 0 ) {
struct V_57 * V_139 ;
V_139 = F_59 ( V_11 ) ;
if ( ! V_139 )
return - V_140 ;
* V_139 = V_420 ;
V_139 -> V_136 = F_63 ( L_55 , V_108 ) ;
if ( ! V_139 -> V_136 )
return - V_140 ;
}
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_34 * V_35 ;
T_1 V_26 [ F_25 ( V_11 -> V_336 ) ] ;
T_1 V_32 [ F_25 ( V_11 -> V_336 ) ] ;
int V_36 , V_155 , V_153 ;
V_35 = V_11 -> V_15 ;
if ( ! V_35 )
return;
if ( V_11 -> V_46 )
return;
V_421:
V_153 = 0 ;
for ( V_155 = 0 ; V_155 < V_11 -> V_157 ; V_155 ++ ) {
T_1 V_156 = V_11 -> V_158 [ V_155 ] ;
int V_37 = F_17 ( V_2 , V_156 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_16 ; V_36 ++ ) {
T_1 V_40 = V_11 -> V_96 [ V_36 ] ;
if ( V_40 ) {
if ( F_70 ( V_2 , V_156 , V_40 ) < 0 )
break;
} else if ( V_37 <= V_35 -> V_49 [ V_36 ] . V_50 )
break;
}
if ( V_36 >= V_35 -> V_16 ) {
V_26 [ V_153 ] = V_11 -> V_336 [ V_155 ] ;
V_32 [ V_153 ++ ] = V_156 ;
}
}
if ( ! V_153 ) {
if ( ! F_69 ( V_2 ) ) {
if ( V_11 -> V_38 ) {
V_11 -> V_38 = 0 ;
V_11 -> V_154 [ 0 ] . V_16 = 1 ;
goto V_421;
}
F_78 ( V_422 L_56
L_57 ,
V_2 -> V_186 , V_11 -> V_336 [ 0 ] ) ;
V_11 -> V_157 = 1 ;
V_11 -> V_97 = 0 ;
return;
}
} else if ( V_153 != V_11 -> V_157 ) {
memcpy ( V_11 -> V_336 , V_26 ,
V_153 * sizeof( T_1 ) ) ;
memcpy ( V_11 -> V_158 , V_32 ,
V_153 * sizeof( T_1 ) ) ;
V_11 -> V_157 = V_153 ;
}
if ( V_11 -> V_97 )
F_71 ( V_2 ) ;
else if ( V_11 -> V_15 -> V_16 == 1 || V_11 -> V_38 )
V_11 -> V_157 = 1 ;
}
static void F_228 ( struct V_1 * V_2 , int V_19 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_3 ;
V_3 = V_11 -> V_26 [ V_19 ] ;
if ( F_174 ( V_2 , V_3 , V_53 ) ) {
F_27 ( V_2 , V_3 , 0 ,
V_209 ,
F_177 ( 0 ) ) ;
return;
}
if ( ! V_11 -> V_32 )
return;
V_3 = V_11 -> V_32 [ V_19 ] ;
if ( F_174 ( V_2 , V_3 , V_82 ) )
F_27 ( V_2 , V_3 , 0 ,
V_209 ,
V_350 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_345 , V_153 ;
for ( V_345 = 0 ; V_345 < V_11 -> V_157 ; V_345 ++ )
F_228 ( V_2 , V_345 ) ;
if ( V_11 -> V_46 )
V_153 = 1 ;
else
V_153 = V_11 -> V_157 ;
for ( V_345 = 0 ; V_345 < V_153 ; V_345 ++ )
F_13 ( V_2 , V_345 , V_11 -> V_23 [ V_345 ] , true ) ;
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_36 , V_212 ;
int V_346 = 0 ;
T_1 V_3 ;
const char * V_347 = NULL ;
for ( V_36 = 0 ; V_36 < V_143 -> V_165 ; V_36 ++ ) {
if ( V_143 -> V_42 [ V_36 ] . type > V_56 )
break;
V_3 = V_143 -> V_42 [ V_36 ] . V_40 ;
if ( F_2 ( V_2 , V_3 ) & V_423 ) {
const char * V_348 ;
char V_424 [ 32 ] ;
V_348 = F_170 ( V_2 , V_143 , V_36 ) ;
if ( V_11 -> V_38 && ! strcmp ( V_348 , L_40 ) )
V_348 = L_41 ;
if ( V_347 && ! strcmp ( V_348 , V_347 ) )
V_346 ++ ;
else
V_346 = 0 ;
V_347 = V_348 ;
snprintf ( V_424 , sizeof( V_424 ) ,
L_58 , V_348 ) ;
V_212 = F_159 ( V_11 , V_332 ,
V_424 , V_346 ,
F_91 ( V_3 , 3 , 0 , V_53 ) ) ;
if ( V_212 < 0 )
return V_212 ;
}
}
return 0 ;
}
static void F_231 ( struct V_1 * V_2 , T_1 V_156 ,
int V_31 )
{
if ( F_18 ( F_2 ( V_2 , V_156 ) ) == V_47 ) {
F_19 ( V_2 , V_156 , V_53 , V_31 ,
V_52 , 0 ) ;
} else if ( F_17 ( V_2 , V_156 ) > 1 ) {
F_20 ( V_2 , V_156 , 0 ,
V_54 , V_31 ) ;
}
}
static int F_232 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
if ( ! V_40 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_157 ; V_36 ++ ) {
T_1 V_156 = F_12 ( V_11 , V_36 ) ;
int V_31 ;
V_31 = F_70 ( V_2 , V_156 , V_40 ) ;
if ( V_31 < 0 )
continue;
F_231 ( V_2 , V_156 , V_31 ) ;
return V_36 ;
}
return - 1 ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_41 . V_165 ; V_36 ++ )
F_232 ( V_2 , V_11 -> V_41 . V_42 [ V_36 ] . V_40 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_57 * V_340 [ 2 ] [ 3 ] = {
{ V_425 ,
V_426 ,
V_427 } ,
{ V_428 ,
V_429 ,
V_430 } ,
} ;
if ( ! F_207 ( V_2 , V_11 -> V_26 [ 0 ] , V_53 ) ) {
if ( ! V_11 -> V_32 )
return;
if ( ! F_207 ( V_2 , V_11 -> V_32 [ 0 ] , V_82 ) )
return;
V_11 -> V_224 = 1 ;
}
if ( V_11 -> V_157 > 0 ) {
int V_431 = 0 ;
int V_344 = 0 ;
if ( V_11 -> V_15 && V_11 -> V_15 -> V_16 > 1 )
V_431 = 1 ;
if ( V_11 -> V_97 ) {
V_344 = 1 ;
V_431 = 0 ;
} else if ( V_11 -> V_46 )
V_344 = 1 ;
if ( ! V_344 ) {
if ( V_11 -> V_157 > 3 )
V_11 -> V_157 = 3 ;
else if ( ! V_11 -> V_157 )
return;
V_344 = V_11 -> V_157 ;
}
V_11 -> V_237 = V_340 [ V_431 ] [ V_344 - 1 ] ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_176 ( V_2 ) ;
F_229 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_11 -> V_151 )
F_46 ( V_2 ) ;
}
static inline int F_234 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
const struct V_432 * V_433 ;
V_433 = F_235 ( V_2 -> V_182 -> V_183 , V_434 ) ;
if ( V_433 )
return V_433 -> V_20 ;
return V_11 -> V_174 . V_179 ;
}
static int F_236 ( struct V_1 * V_2 ,
const T_1 * V_435 ,
const T_1 * V_436 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_142 * V_143 = & V_11 -> V_41 ;
int V_212 ;
V_212 = F_237 ( V_2 , V_143 , V_435 ,
V_11 -> V_437 ) ;
if ( V_212 < 0 )
return V_212 ;
if ( ! V_143 -> V_147 ) {
if ( V_143 -> V_203 || V_143 -> V_211 ) {
V_11 -> V_205 . V_417 = 2 ;
V_11 -> V_238 = 1 ;
goto V_438;
}
return 0 ;
}
if ( V_143 -> V_144 == V_145 &&
V_143 -> V_147 <= V_143 -> V_149 ) {
V_143 -> V_146 = V_143 -> V_147 ;
memcpy ( V_143 -> V_90 , V_143 -> V_91 ,
sizeof( V_143 -> V_90 ) ) ;
V_143 -> V_147 = V_143 -> V_149 ;
memcpy ( V_143 -> V_91 , V_143 -> V_86 , sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_149 = 0 ;
memset ( V_143 -> V_86 , 0 , sizeof( V_143 -> V_86 ) ) ;
V_143 -> V_144 = V_148 ;
}
V_212 = F_201 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_226 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_208 ( V_2 , V_143 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_212 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_213 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_172 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_169 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 -> V_205 . V_417 = V_11 -> V_205 . V_273 * 2 ;
V_438:
F_87 ( V_2 ) ;
if ( ! V_11 -> V_238 )
F_227 ( V_2 ) ;
if ( V_436 )
F_82 ( V_2 , V_436 ) ;
if ( ! V_11 -> V_238 ) {
F_75 ( V_2 ) ;
V_212 = F_230 ( V_2 ) ;
if ( V_212 < 0 )
return V_212 ;
}
if ( V_11 -> V_138 . V_152 )
F_23 ( V_11 , V_11 -> V_138 . V_152 ) ;
if ( ! V_11 -> V_238 && ! V_11 -> V_237 )
F_233 ( V_2 ) ;
return 1 ;
}
static int F_238 ( struct V_1 * V_2 , T_1 V_343 )
{
struct V_10 * V_11 = F_41 ( sizeof( * V_11 ) , V_108 ) ;
int V_212 ;
if ( ! V_11 )
return - V_140 ;
V_2 -> V_11 = V_11 ;
V_11 -> V_343 = V_343 ;
F_239 ( & V_11 -> V_307 ) ;
V_212 = F_158 ( V_2 ) ;
if ( V_212 < 0 ) {
F_42 ( V_11 ) ;
return V_212 ;
}
return 0 ;
}
static int F_240 ( struct V_1 * V_2 )
{
static const T_1 V_439 [] = { 0x1d , 0 } ;
static const T_1 V_440 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_439 , V_440 ) ;
}
static void F_241 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 == V_442 )
F_67 ( V_2 , 0x21 , V_114 ) ;
}
static int F_242 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_418 = 1 ;
F_243 ( V_2 , V_443 , V_444 ,
V_445 ) ;
F_116 ( V_2 , V_446 ) ;
V_212 = F_240 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_246 ( struct V_1 * V_2 )
{
static const T_1 V_448 [] = { 0x17 , 0 } ;
static const T_1 V_449 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_236 ( V_2 , V_448 , V_449 ) ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_27 ( V_2 , 0x01 , 0 , V_450 ,
V_11 -> V_88 ) ;
}
static void F_248 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_102 == V_442 ) {
V_11 -> V_93 = F_247 ;
V_11 -> V_94 = 1 ;
V_11 -> V_45 = 1 ;
V_11 -> V_41 . V_86 [ 0 ] = 0x0f ;
F_67 ( V_2 , 0x0f , V_103 ) ;
V_11 -> V_151 = F_43 ;
F_249 ( & V_11 -> V_307 , V_123 ) ;
}
}
static void F_250 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static const struct V_451 V_452 [] = {
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
switch ( V_102 ) {
case V_446 :
F_251 ( V_2 , V_452 ) ;
break;
case V_442 :
V_11 -> V_198 = V_453 ;
break;
}
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x07 ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
F_243 ( V_2 , NULL , V_454 , V_455 ) ;
F_116 ( V_2 , V_446 ) ;
V_212 = F_246 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x07 , 0x05 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
V_11 -> V_302 = F_52 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static void F_253 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 != V_256 )
return;
F_48 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 , int V_40 , int V_456 )
{
unsigned int V_457 , V_458 , V_459 ;
V_457 = F_28 ( V_2 , V_2 -> V_460 , 0 ,
V_461 , 0 ) ;
if ( ! V_456 )
V_457 |= ( 1 << V_40 ) ;
else
V_457 &= ~ ( 1 << V_40 ) ;
V_458 = F_28 ( V_2 , V_2 -> V_460 , 0 ,
V_462 , 0 ) ;
V_458 |= ( 1 << V_40 ) ;
V_459 = F_28 ( V_2 , V_2 -> V_460 , 0 ,
V_463 , 0 ) ;
V_459 |= ( 1 << V_40 ) ;
F_27 ( V_2 , V_2 -> V_460 , 0 ,
V_464 , V_458 ) ;
F_27 ( V_2 , V_2 -> V_460 , 0 ,
V_465 , V_459 ) ;
F_53 ( 1 ) ;
F_27 ( V_2 , V_2 -> V_460 , 0 ,
V_450 , V_457 ) ;
}
static void F_255 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 != V_256 )
return;
F_254 ( V_2 , 0 , 0 ) ;
F_254 ( V_2 , 1 , 0 ) ;
}
static void F_256 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 == V_446 ) {
T_1 V_466 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_467 [ 2 ] = { 0x0e , 0x0f } ;
F_257 ( V_2 , 0x14 , 2 , V_466 ) ;
F_257 ( V_2 , 0x15 , 2 , V_466 ) ;
F_257 ( V_2 , 0x18 , 2 , V_467 ) ;
F_257 ( V_2 , 0x1a , 2 , V_467 ) ;
} else if ( V_102 == V_442 ) {
T_1 V_214 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_257 ( V_2 , 0x14 , 5 , V_214 ) ;
F_257 ( V_2 , 0x15 , 5 , V_214 ) ;
F_257 ( V_2 , 0x18 , 5 , V_214 ) ;
F_257 ( V_2 , 0x1a , 5 , V_214 ) ;
}
}
static void F_258 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_468 [ 2 ] = { 0x14 , 0x15 } ;
int V_36 ;
if ( V_102 != V_256 )
return;
for ( V_36 = 0 ; V_36 < F_25 ( V_468 ) ; V_36 ++ ) {
unsigned int V_39 = F_73 ( V_2 , V_468 [ V_36 ] ) ;
if ( F_259 ( V_39 ) != V_469 )
continue;
V_39 = F_28 ( V_2 , V_468 [ V_36 ] , 0 ,
V_80 , 0 ) ;
V_39 |= V_470 ;
F_15 ( V_2 , V_468 [ V_36 ] , V_39 ) ;
V_11 -> V_79 = 1 ;
break;
}
}
static void F_260 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
static T_1 V_468 [ 2 ] = { 0x18 , 0x1a } ;
int V_36 ;
if ( V_102 != V_256 )
return;
for ( V_36 = 0 ; V_36 < F_25 ( V_468 ) ; V_36 ++ ) {
unsigned int V_39 ;
V_39 = F_28 ( V_2 , V_468 [ V_36 ] , 0 ,
V_80 , 0 ) ;
V_39 |= V_471 ;
F_15 ( V_2 , V_468 [ V_36 ] , V_39 ) ;
}
V_11 -> V_79 = 1 ;
}
static int F_261 ( struct V_1 * V_2 )
{
static const T_1 V_472 [] = { 0x1d , 0 } ;
static const T_1 V_473 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_472 , V_473 ) ;
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
switch ( V_2 -> V_113 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
break;
}
F_243 ( V_2 , V_474 , V_475 ,
V_476 ) ;
F_116 ( V_2 , V_446 ) ;
F_77 ( V_2 ) ;
V_212 = F_261 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 && F_234 ( V_2 ) ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_263 ( struct V_1 * V_2 )
{
static const T_1 V_477 [] = { 0x1d , 0 } ;
static const T_1 V_478 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_477 , V_478 ) ;
}
static int F_264 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
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
F_29 ( V_2 , 0x20 , 0x0a , 10 ) ;
F_243 ( V_2 , NULL , V_479 , V_480 ) ;
F_116 ( V_2 , V_446 ) ;
F_77 ( V_2 ) ;
V_212 = F_263 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 && F_234 ( V_2 ) ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
V_11 -> V_302 = F_52 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_265 ( struct V_1 * V_2 )
{
static const T_1 V_481 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_212 = F_236 ( V_2 , NULL , V_481 ) ;
if ( V_212 > 0 ) {
if ( ! V_11 -> V_238 && V_11 -> V_41 . V_90 [ 0 ] != 0x1d ) {
F_23 ( V_11 , V_482 ) ;
F_249 ( & V_11 -> V_307 , V_483 ) ;
}
}
return V_212 ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_36 , V_484 , V_212 ;
V_212 = F_238 ( V_2 , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
V_212 = F_265 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
V_484 = 0 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_59 ; V_36 ++ ) {
if ( V_11 -> V_60 [ V_36 ] == V_482 ) {
V_484 = 1 ;
break;
}
}
if ( V_484 ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
if ( ! F_3 ( V_2 , 0x1d , V_53 ) )
F_267 ( V_2 , 0x1d , V_53 ,
( 0x0c << V_485 ) |
( 0x0c << V_486 ) |
( 0x07 << V_487 ) |
( 0 << V_488 ) ) ;
}
V_2 -> V_310 = V_447 ;
V_11 -> V_302 = F_52 ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_268 ( struct V_1 * V_2 )
{
static const T_1 V_489 [] = { 0x1d , 0 } ;
static const T_1 V_490 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_491 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_10 * V_11 = V_2 -> V_11 ;
const T_1 * V_492 ;
switch ( V_11 -> V_493 ) {
case V_494 :
case V_495 :
V_492 = V_491 ;
break;
case V_496 :
case V_497 :
V_492 = V_490 ;
break;
default:
V_492 = V_490 ;
break;
}
return F_236 ( V_2 , V_489 , V_492 ) ;
}
static void F_269 ( struct V_1 * V_2 , int V_498 )
{
int V_39 = F_83 ( V_2 , 0x04 ) ;
if ( V_498 )
V_39 |= 1 << 11 ;
else
V_39 &= ~ ( 1 << 11 ) ;
F_84 ( V_2 , 0x04 , V_39 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_493 != V_496 )
return;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 )
F_269 ( V_2 , 0 ) ;
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_269 ( V_2 , 0 ) ;
F_53 ( 150 ) ;
}
}
static int F_271 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_493 == V_496 ||
( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
F_269 ( V_2 , 0 ) ;
F_53 ( 150 ) ;
}
V_2 -> V_310 . V_311 ( V_2 ) ;
if ( V_11 -> V_493 == V_496 ||
( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
F_269 ( V_2 , 1 ) ;
F_53 ( 200 ) ;
}
if ( V_11 -> V_493 == V_496 ||
( F_85 ( V_2 ) & 0x00ff ) == 0x018 )
F_269 ( V_2 , 1 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
F_121 ( V_2 , 0x01 ) ;
return 0 ;
}
static void F_272 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
int V_499 ;
if ( V_102 != V_256 )
return;
V_499 = F_83 ( V_2 , 0x1e ) ;
F_84 ( V_2 , 0x1e , V_499 | 0x80 ) ;
}
static void F_273 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
static const struct V_500 V_501 [] = {
{ 0x20 , V_62 , 0x0d } ,
{ 0x20 , V_65 , 0x4000 } ,
{}
} ;
unsigned int V_143 ;
if ( strcmp ( V_2 -> V_186 , L_59 ) )
return;
V_143 = F_73 ( V_2 , 0x12 ) ;
if ( F_219 ( V_143 ) == V_502 )
F_55 ( V_2 , V_501 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_102 != V_442 )
return;
V_11 -> V_274 = & V_503 ;
V_11 -> V_279 = & V_504 ;
}
static void F_275 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
int V_499 ;
if ( V_102 != V_256 )
return;
V_499 = F_83 ( V_2 , 0x07 ) ;
F_84 ( V_2 , 0x07 , V_499 | 0x80 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_27 ( V_2 , 0x20 , 0 ,
V_62 , 0x0c ) ;
F_27 ( V_2 , 0x20 , 0 ,
V_65 , 0x680 ) ;
F_27 ( V_2 , 0x20 , 0 ,
V_62 , 0x0c ) ;
F_27 ( V_2 , 0x20 , 0 ,
V_65 , 0x480 ) ;
}
static void F_277 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_102 != V_442 )
return;
V_11 -> V_93 = F_276 ;
}
static void F_278 ( void * V_505 , int V_506 )
{
struct V_1 * V_2 = V_505 ;
unsigned int V_507 = V_506 ? 0x20 : 0x24 ;
F_224 ( V_2 , 0x19 , V_507 ) ;
}
static void F_279 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
switch ( V_102 ) {
case V_254 :
V_11 -> V_245 . V_508 = F_278 ;
F_280 ( V_2 , & V_11 -> V_245 , true ) ;
case V_256 :
F_281 ( & V_11 -> V_245 ) ;
break;
}
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_39 ;
if ( V_11 -> V_493 != V_496 )
return;
if ( ( F_85 ( V_2 ) & 0x00ff ) < 0x015 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8817 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x016 ) {
F_84 ( V_2 , 0xf , 0x960b ) ;
F_84 ( V_2 , 0xe , 0x8814 ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x017 ) {
V_39 = F_83 ( V_2 , 0x04 ) ;
F_84 ( V_2 , 0x04 , V_39 | ( 1 << 11 ) ) ;
}
if ( ( F_85 ( V_2 ) & 0x00ff ) == 0x018 ) {
V_39 = F_83 ( V_2 , 0xd ) ;
if ( ( V_39 & 0x0c00 ) >> 10 != 0x1 ) {
F_84 ( V_2 , 0xd , V_39 | ( 1 << 10 ) ) ;
}
V_39 = F_83 ( V_2 , 0x17 ) ;
if ( ( V_39 & 0x01c0 ) >> 6 != 0x4 ) {
F_84 ( V_2 , 0x17 , V_39 | ( 1 << 7 ) ) ;
}
}
V_39 = F_83 ( V_2 , 0xd ) ;
F_84 ( V_2 , 0xd , V_39 | ( 1 << 14 ) ) ;
V_39 = F_83 ( V_2 , 0x4 ) ;
F_84 ( V_2 , 0x4 , V_39 | ( 1 << 11 ) ) ;
}
static int F_283 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
if ( V_2 -> V_113 == 0x10ec0269 ) {
V_11 -> V_493 = V_494 ;
switch ( F_85 ( V_2 ) & 0x00f0 ) {
case 0x0010 :
if ( V_2 -> V_182 -> V_183 -> V_509 == 0x1025 &&
V_11 -> V_174 . V_191 == 1 )
V_212 = F_157 ( V_2 , L_59 ) ;
V_11 -> V_493 = V_496 ;
break;
case 0x0020 :
if ( V_2 -> V_182 -> V_183 -> V_509 == 0x17aa &&
V_2 -> V_182 -> V_183 -> V_184 == 0x21f3 )
V_212 = F_157 ( V_2 , L_60 ) ;
V_11 -> V_493 = V_495 ;
break;
case 0x0030 :
V_11 -> V_493 = V_497 ;
break;
default:
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
}
if ( V_212 < 0 )
goto error;
V_11 -> V_255 = F_282 ;
F_282 ( V_2 ) ;
}
F_243 ( V_2 , V_510 ,
V_511 , V_512 ) ;
F_116 ( V_2 , V_446 ) ;
F_77 ( V_2 ) ;
V_212 = F_268 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 && F_234 ( V_2 ) ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x0b , 0x04 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
#ifdef F_284
V_2 -> V_310 . V_513 = F_271 ;
#endif
V_11 -> V_302 = F_270 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_285 ( struct V_1 * V_2 )
{
static const T_1 V_514 [] = { 0x1d , 0 } ;
static const T_1 V_515 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_236 ( V_2 , V_514 , V_515 ) ;
}
static void F_286 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_39 ;
if ( V_102 != V_256 )
return;
V_39 = F_28 ( V_2 , 0x0f , 0 ,
V_80 , 0 ) ;
if ( ! ( V_39 & ( V_516 | V_517 ) ) )
V_39 |= V_516 ;
V_39 |= V_471 ;
F_15 ( V_2 , 0x0f , V_39 ) ;
V_11 -> V_79 = 1 ;
}
static void F_287 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 == V_446 )
V_2 -> V_518 = 1 ;
}
static int F_288 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x15 ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
F_243 ( V_2 , NULL , V_519 , V_520 ) ;
F_116 ( V_2 , V_446 ) ;
V_212 = F_285 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 ) {
V_212 = F_244 ( V_2 , 0x23 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x23 , 0 , V_82 ) ;
}
V_2 -> V_310 = V_447 ;
#ifdef F_289
V_11 -> V_309 = F_152 ;
#endif
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_290 ( struct V_1 * V_2 )
{
static const T_1 V_521 [] = { 0x1d , 0 } ;
static const T_1 V_522 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_236 ( V_2 , V_521 , V_522 ) ;
}
static void F_291 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 == V_446 ) {
F_292 ( V_2 , 0x18 , 0x00001714 ) ;
F_292 ( V_2 , 0x19 , 0x0000171c ) ;
}
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
F_243 ( V_2 , NULL , V_523 , V_524 ) ;
F_116 ( V_2 , V_446 ) ;
V_212 = F_290 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( V_2 -> V_113 == 0x10ec0660 ) {
F_249 ( & V_11 -> V_307 , V_525 ) ;
}
if ( ! V_11 -> V_238 ) {
V_212 = F_244 ( V_2 , 0x23 ) ;
if ( V_212 < 0 )
goto error;
F_245 ( V_11 , 0x0b , 0x05 , V_53 ) ;
}
V_2 -> V_310 = V_447 ;
V_11 -> V_302 = F_52 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_294 ( struct V_1 * V_2 )
{
static const T_1 V_526 [] = { 0x1d , 0 } ;
static const T_1 V_527 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_528 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_492 ;
if ( V_2 -> V_113 == 0x10ec0272 || V_2 -> V_113 == 0x10ec0663 ||
V_2 -> V_113 == 0x10ec0665 || V_2 -> V_113 == 0x10ec0670 )
V_492 = V_527 ;
else
V_492 = V_528 ;
return F_236 ( V_2 , V_526 , V_492 ) ;
}
static void F_295 ( struct V_1 * V_2 ,
const struct V_441 * V_172 , int V_102 )
{
if ( V_102 != V_442 )
return;
if ( F_267 ( V_2 , 0x2 , V_82 ,
( 0x3b << V_485 ) |
( 0x3b << V_486 ) |
( 0x03 << V_487 ) |
( 0 << V_488 ) ) )
F_78 ( V_422
L_61 ) ;
}
static void F_296 ( struct V_1 * V_2 )
{
int V_39 , V_499 ;
V_499 = F_85 ( V_2 ) ;
switch ( V_2 -> V_113 ) {
case 0x10ec0662 :
if ( ( V_499 & 0x00f0 ) == 0x0030 ) {
V_39 = F_83 ( V_2 , 0x4 ) ;
F_84 ( V_2 , 0x4 , V_39 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_39 = F_83 ( V_2 , 0xd ) ;
F_84 ( V_2 , 0xd , V_39 | ( 1 << 14 ) ) ;
break;
}
}
static int F_297 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_212 ;
V_212 = F_238 ( V_2 , 0x0b ) ;
if ( V_212 < 0 )
return V_212 ;
V_11 = V_2 -> V_11 ;
V_11 -> V_437 = V_529 ;
F_29 ( V_2 , 0x20 , 0x04 , 15 ) ;
V_11 -> V_255 = F_296 ;
F_296 ( V_2 ) ;
F_243 ( V_2 , V_530 ,
V_531 , V_532 ) ;
F_116 ( V_2 , V_446 ) ;
F_77 ( V_2 ) ;
if ( ( F_85 ( V_2 ) & ( 1 << 14 ) ) &&
V_2 -> V_182 -> V_183 -> V_509 == 0x1025 &&
V_11 -> V_174 . V_191 == 1 ) {
if ( F_157 ( V_2 , L_62 ) < 0 )
goto error;
}
V_212 = F_294 ( V_2 ) ;
if ( V_212 < 0 )
goto error;
if ( ! V_11 -> V_238 && F_234 ( V_2 ) ) {
V_212 = F_244 ( V_2 , 0x1 ) ;
if ( V_212 < 0 )
goto error;
switch ( V_2 -> V_113 ) {
case 0x10ec0662 :
F_245 ( V_11 , 0x0b , 0x05 , V_53 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_245 ( V_11 , 0x0b , 0x04 , V_53 ) ;
break;
case 0x10ec0273 :
F_245 ( V_11 , 0x0b , 0x03 , V_53 ) ;
break;
}
}
V_2 -> V_310 = V_447 ;
V_11 -> V_302 = F_52 ;
F_116 ( V_2 , V_442 ) ;
return 0 ;
error:
F_149 ( V_2 ) ;
return V_212 ;
}
static int F_298 ( struct V_1 * V_2 )
{
return F_236 ( V_2 , NULL , NULL ) ;
}
static int F_299 ( struct V_1 * V_2 )
{
int V_212 ;
V_212 = F_238 ( V_2 , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_212 = F_298 ( V_2 ) ;
if ( V_212 < 0 ) {
F_149 ( V_2 ) ;
return V_212 ;
}
V_2 -> V_310 = V_447 ;
return 0 ;
}
static int T_5 F_300 ( void )
{
return F_301 ( & V_533 ) ;
}
static void T_6 F_302 ( void )
{
F_303 ( & V_533 ) ;
}
