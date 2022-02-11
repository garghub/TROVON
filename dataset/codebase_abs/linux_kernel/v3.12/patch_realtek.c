static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_2 ( V_2 -> V_5 >= F_3 ( V_2 -> V_6 ) ) )
return;
V_2 -> V_6 [ V_2 -> V_5 ++ ] = V_4 ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( ! V_2 -> V_10 )
return;
F_5 ( V_8 , V_2 -> V_10 , 0 , V_11 ,
V_2 -> V_12 ) ;
V_9 = F_6 ( V_8 , V_2 -> V_10 , 0 ,
V_13 , 0 ) ;
F_5 ( V_8 , V_2 -> V_10 , 0 , V_11 ,
V_2 -> V_12 ) ;
F_5 ( V_8 , V_2 -> V_10 , 0 , V_14 ,
V_9 & ~ ( 1 << V_2 -> V_15 ) ) ;
}
static void F_7 ( struct V_7 * V_8 , T_1 V_16 ,
unsigned int V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_10 = V_16 ;
V_2 -> V_12 = V_17 ;
V_2 -> V_15 = V_18 ;
F_4 ( V_8 ) ;
}
static void F_8 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
unsigned int V_9 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_9 ( V_8 , L_1 ) ;
if ( ! V_22 )
return;
V_24 = F_10 ( sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
return;
V_9 = F_6 ( V_8 , V_20 -> V_16 , 0 ,
V_26 , 0 ) ;
V_9 &= V_27 ;
V_24 -> V_28 . integer . V_28 [ 0 ] = V_9 ;
V_24 -> V_28 . integer . V_28 [ 1 ] = V_9 ;
V_22 -> V_29 ( V_22 , V_24 ) ;
F_11 ( V_24 ) ;
}
static void F_12 ( struct V_7 * V_8 , unsigned int V_30 )
{
F_13 ( V_8 , V_30 >> 2 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
unsigned int V_31 ;
F_5 ( V_8 , 0x20 , 0 , V_11 , 0 ) ;
V_31 = F_6 ( V_8 , 0x20 , 0 , V_13 , 0 ) ;
F_5 ( V_8 , 0x20 , 0 , V_11 , 7 ) ;
if ( ( V_31 & 0xf0 ) == 0x20 )
F_6 ( V_8 , 0x20 , 0 ,
V_14 , 0x830 ) ;
else
F_6 ( V_8 , 0x20 , 0 ,
V_14 , 0x3030 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
unsigned int V_31 ;
F_5 ( V_8 , 0x20 , 0 , V_11 , 7 ) ;
V_31 = F_6 ( V_8 , 0x20 , 0 , V_13 , 0 ) ;
F_5 ( V_8 , 0x20 , 0 , V_11 , 7 ) ;
F_5 ( V_8 , 0x20 , 0 , V_14 , V_31 | 0x2010 ) ;
}
static void F_16 ( struct V_7 * V_8 , T_1 V_16 , int V_32 )
{
if ( F_17 ( F_18 ( V_8 , V_16 ) ) != V_33 )
return;
if ( F_19 ( V_8 , V_16 ) & V_34 )
F_5 ( V_8 , V_16 , 0 , V_35 ,
V_32 ? 2 : 0 ) ;
}
static void F_20 ( struct V_7 * V_8 , bool V_32 )
{
static T_1 V_36 [] = {
0x0f , 0x10 , 0x14 , 0x15 , 0
} ;
T_1 * V_37 ;
for ( V_37 = V_36 ; * V_37 ; V_37 ++ )
F_16 ( V_8 , * V_37 , V_32 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
F_22 ( 200 ) ;
F_23 ( V_8 ) ;
}
static void F_24 ( struct V_7 * V_8 , int type )
{
unsigned int V_31 ;
F_20 ( V_8 , true ) ;
switch ( type ) {
case V_38 :
F_25 ( V_8 , V_39 ) ;
break;
case V_40 :
F_25 ( V_8 , V_41 ) ;
break;
case V_42 :
F_25 ( V_8 , V_43 ) ;
break;
case V_44 :
switch ( V_8 -> V_45 ) {
case 0x10ec0260 :
F_5 ( V_8 , 0x1a , 0 ,
V_11 , 7 ) ;
V_31 = F_6 ( V_8 , 0x1a , 0 ,
V_13 , 0 ) ;
F_5 ( V_8 , 0x1a , 0 ,
V_11 , 7 ) ;
F_5 ( V_8 , 0x1a , 0 ,
V_14 ,
V_31 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_15 ( V_8 ) ;
break;
case 0x10ec0888 :
F_14 ( V_8 ) ;
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
static void F_26 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_50 . V_51 = 1 ;
V_2 -> V_50 . V_52 = V_53 ;
}
}
static int F_27 ( struct V_7 * V_8 )
{
unsigned int V_54 , V_31 , V_55 ;
unsigned V_16 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_50 . V_56 = 1 ;
if ( V_2 -> V_50 . V_51 ) {
V_54 = V_2 -> V_50 . V_52 ;
if ( V_54 == V_53 )
return - 1 ;
goto V_57;
}
V_54 = V_8 -> V_58 & 0xffff ;
if ( V_54 != V_8 -> V_59 -> V_60 -> V_61 && ( V_54 & 1 ) )
goto V_57;
V_16 = 0x1d ;
if ( V_8 -> V_45 == 0x10ec0260 )
V_16 = 0x17 ;
V_54 = F_28 ( V_8 , V_16 ) ;
if ( ! ( V_54 & 1 ) ) {
F_29 ( V_62 L_2 ,
V_8 -> V_63 , V_54 ) ;
return - 1 ;
}
V_31 = 0 ;
for ( V_55 = 1 ; V_55 < 16 ; V_55 ++ ) {
if ( ( V_54 >> V_55 ) & 1 )
V_31 ++ ;
}
if ( ( ( V_54 >> 16 ) & 0xf ) != V_31 )
return - 1 ;
V_2 -> V_50 . V_64 = V_54 >> 30 ;
V_2 -> V_50 . V_56 = ( V_54 & 0x100000 ) >> 20 ;
V_2 -> V_50 . V_65 = ( V_54 >> 16 ) & 0xf ;
V_2 -> V_50 . V_66 = V_54 >> 8 ;
V_57:
V_2 -> V_50 . V_52 = V_54 ;
V_2 -> V_50 . V_67 = ( V_54 & 0x38 ) >> 3 ;
V_2 -> V_50 . V_68 = ( V_54 & 0x4 ) >> 2 ;
V_2 -> V_50 . V_69 = ( V_54 & 0x2 ) >> 1 ;
V_2 -> V_50 . V_70 = V_54 & 0x1 ;
F_30 ( L_3 ,
V_16 , V_2 -> V_50 . V_52 ) ;
F_30 ( L_4 ,
V_2 -> V_50 . V_64 ) ;
F_30 ( L_5 , V_2 -> V_50 . V_56 ) ;
F_30 ( L_6 , V_2 -> V_50 . V_65 ) ;
F_30 ( L_7 , V_2 -> V_50 . V_66 ) ;
F_30 ( L_8 , V_2 -> V_50 . V_67 ) ;
F_30 ( L_9 , V_2 -> V_50 . V_68 ) ;
F_30 ( L_10 , V_2 -> V_50 . V_69 ) ;
F_30 ( L_11 , V_2 -> V_50 . V_70 ) ;
return 0 ;
}
static int F_31 ( T_1 V_16 , const T_1 * V_71 , int V_72 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_72 ; V_55 ++ )
if ( V_71 [ V_55 ] == V_16 )
return V_55 ;
return - 1 ;
}
static bool F_32 ( T_1 V_16 , const T_1 * V_71 , int V_72 )
{
return F_31 ( V_16 , V_71 , V_72 ) >= 0 ;
}
static int F_33 ( struct V_7 * V_8 ,
T_1 V_73 , T_1 V_74 ,
T_1 V_75 , T_1 V_76 )
{
unsigned int V_54 , V_31 , V_55 ;
unsigned V_16 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_50 . V_51 ) {
V_54 = V_2 -> V_50 . V_52 ;
if ( V_54 == V_53 )
return 0 ;
goto V_57;
}
V_54 = V_8 -> V_58 & 0xffff ;
if ( ( V_54 != V_8 -> V_59 -> V_60 -> V_61 ) && ( V_54 & 1 ) )
goto V_57;
V_16 = 0x1d ;
if ( V_8 -> V_45 == 0x10ec0260 )
V_16 = 0x17 ;
V_54 = F_28 ( V_8 , V_16 ) ;
F_30 ( L_12
L_13 ,
V_54 , V_16 ) ;
if ( ! ( V_54 & 1 ) )
return 0 ;
if ( ( V_54 >> 30 ) != 1 )
return 0 ;
V_31 = 0 ;
for ( V_55 = 1 ; V_55 < 16 ; V_55 ++ ) {
if ( ( V_54 >> V_55 ) & 1 )
V_31 ++ ;
}
if ( ( ( V_54 >> 16 ) & 0xf ) != V_31 )
return 0 ;
V_57:
F_30 ( L_14 ,
V_54 & 0xffff , V_8 -> V_45 ) ;
V_31 = ( V_54 & 0x38 ) >> 3 ;
switch ( V_31 ) {
case 1 :
V_2 -> V_77 = V_38 ;
break;
case 3 :
V_2 -> V_77 = V_40 ;
break;
case 7 :
V_2 -> V_77 = V_42 ;
break;
case 5 :
default:
V_2 -> V_77 = V_44 ;
break;
}
if ( ! ( V_54 & 0x8000 ) )
return 1 ;
if ( ! V_2 -> V_78 . V_79 . V_80 [ 0 ] &&
! ( V_2 -> V_78 . V_79 . V_81 [ 0 ] &&
V_2 -> V_78 . V_79 . V_82 == V_83 ) ) {
T_1 V_16 ;
V_31 = ( V_54 >> 11 ) & 0x3 ;
if ( V_31 == 0 )
V_16 = V_73 ;
else if ( V_31 == 1 )
V_16 = V_74 ;
else if ( V_31 == 2 )
V_16 = V_75 ;
else if ( V_31 == 3 )
V_16 = V_76 ;
else
return 1 ;
if ( F_32 ( V_16 , V_2 -> V_78 . V_79 . V_81 ,
V_2 -> V_78 . V_79 . V_84 ) )
return 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = V_16 ;
}
return 1 ;
}
static void F_34 ( struct V_7 * V_8 , const T_1 * V_85 )
{
if ( ! F_33 ( V_8 , V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
F_30 ( L_15
L_16 ) ;
V_2 -> V_77 = V_44 ;
}
}
static int F_35 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x20 , 0 , V_11 ,
V_17 ) ;
V_9 = F_6 ( V_8 , 0x20 , 0 ,
V_13 , 0 ) ;
return V_9 ;
}
static void F_36 ( struct V_7 * V_8 , unsigned int V_17 ,
unsigned int V_86 )
{
F_5 ( V_8 , 0x20 , 0 , V_11 ,
V_17 ) ;
F_5 ( V_8 , 0x20 , 0 , V_14 ,
V_86 ) ;
}
static unsigned int F_37 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_87 )
V_2 -> V_87 = F_35 ( V_8 , 0 ) ;
return V_2 -> V_87 ;
}
static T_1 F_38 ( struct V_7 * V_8 , int V_88 , int V_89 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_91 )
V_88 = V_2 -> V_92 [ V_89 ] ;
return V_2 -> V_93 [ V_88 ] ;
}
static void F_39 ( struct V_7 * V_8 , int V_88 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_94 * V_95 = & V_2 -> V_78 . V_96 ;
struct V_97 * V_98 ;
T_1 V_16 ;
int V_55 , V_99 , V_100 ;
unsigned int V_9 ;
for ( V_55 = 0 ; V_55 < V_95 -> V_101 ; V_55 ++ ) {
if ( V_2 -> V_78 . V_102 [ V_55 ] == V_2 -> V_103 )
break;
}
if ( V_55 >= V_95 -> V_101 )
return;
V_98 = F_40 ( V_8 , V_2 -> V_103 ,
F_38 ( V_8 , V_88 , V_55 ) ) ;
V_9 = V_98 -> V_104 [ V_105 ] ;
if ( ! V_9 )
return;
V_16 = F_41 ( V_9 ) ;
V_99 = F_42 ( V_9 ) ;
V_100 = V_106 |
( V_99 == V_107 ? V_108 : V_109 ) ;
F_43 ( V_8 ) ;
V_9 = F_44 ( V_8 , V_16 , 1 , V_99 , 0 ) ;
if ( V_9 & 0x80 )
return;
V_9 |= 0x80 ;
F_5 ( V_8 , V_16 , 0 , V_110 ,
V_100 | V_9 ) ;
}
static void F_45 ( struct V_7 * V_8 , bool V_111 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_112 , V_72 ;
if ( ! V_2 -> V_113 )
return;
if ( ! V_2 -> V_114 && ! V_111 )
return;
V_72 = V_2 -> V_78 . V_91 ? 1 : V_2 -> V_78 . V_115 ;
for ( V_112 = 0 ; V_112 < V_72 ; V_112 ++ ) {
bool V_116 = false ;
if ( V_2 -> V_114 &&
V_2 -> V_78 . V_102 [ V_2 -> V_78 . V_117 [ V_112 ] ] == V_2 -> V_103 )
V_116 = true ;
if ( ! V_116 && ! V_111 )
continue;
F_39 ( V_8 , V_112 ) ;
}
}
static void F_46 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
F_45 ( V_8 , false ) ;
}
static int F_47 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_48 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_118 -> V_28 . integer . V_28 [ 0 ] = ! V_2 -> V_114 ;
return 0 ;
}
static int F_49 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_48 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 = ! V_118 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_9 == V_2 -> V_114 )
return 0 ;
V_2 -> V_114 = V_9 ;
F_45 ( V_8 , true ) ;
return 0 ;
}
static int F_50 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_51 ( & V_2 -> V_78 , NULL , & V_120 ) )
return - V_121 ;
V_2 -> V_113 = 1 ;
V_2 -> V_114 = 0 ;
V_2 -> V_103 = V_16 ;
V_2 -> V_78 . V_122 = F_46 ;
return 0 ;
}
static void F_52 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_50 ( V_8 , 0x12 ) ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_55 , V_124 ;
V_124 = F_54 ( V_8 ) ;
if ( V_124 < 0 )
return V_124 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 ; V_55 ++ ) {
V_124 = F_55 ( V_8 , V_2 -> V_6 [ V_55 ] ) ;
if ( V_124 < 0 )
return V_124 ;
}
#ifdef F_56
if ( V_2 -> V_125 ) {
const struct V_3 * V_126 ;
for ( V_126 = V_127 ; V_126 -> V_128 ; V_126 ++ ) {
struct V_21 * V_22 ;
V_22 = F_57 ( V_126 , V_8 ) ;
if ( ! V_22 )
return - V_121 ;
V_22 -> V_129 = V_2 -> V_125 ;
V_124 = F_58 ( V_8 , 0 , V_22 ) ;
if ( V_124 < 0 )
return V_124 ;
}
}
#endif
F_59 ( V_8 , V_130 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
F_4 ( V_8 ) ;
F_24 ( V_8 , V_2 -> V_77 ) ;
F_61 ( V_8 ) ;
F_59 ( V_8 , V_132 ) ;
return 0 ;
}
static inline void F_62 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 && V_2 -> V_133 )
V_2 -> V_133 ( V_8 ) ;
else
F_23 ( V_8 ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_62 ( V_8 ) ;
if ( V_2 && V_2 -> V_134 )
V_2 -> V_134 ( V_8 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_8 )
{
F_22 ( 150 ) ;
V_8 -> V_135 . V_136 ( V_8 ) ;
F_66 ( V_8 ) ;
F_67 ( V_8 ) ;
F_45 ( V_8 , true ) ;
F_68 ( V_8 , 0x01 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_8 , const char * V_128 )
{
F_11 ( V_8 -> V_63 ) ;
V_8 -> V_63 = F_70 ( V_128 , V_25 ) ;
if ( ! V_8 -> V_63 ) {
F_71 ( V_8 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_8 )
{
const struct V_137 * V_37 ;
for ( V_37 = V_138 ; V_37 -> V_45 ; V_37 ++ ) {
if ( V_37 -> V_45 != V_8 -> V_45 )
continue;
if ( ( F_37 ( V_8 ) & V_37 -> V_139 ) == V_37 -> V_140 )
return F_69 ( V_8 , V_37 -> V_128 ) ;
}
return 0 ;
}
static inline int F_73 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_141 * V_142 ;
V_142 = F_74 ( V_8 -> V_59 -> V_60 , V_143 ) ;
if ( V_142 )
return V_142 -> V_28 ;
return V_2 -> V_50 . V_56 ;
}
static int F_75 ( struct V_7 * V_8 ,
const T_1 * V_144 ,
const T_1 * V_145 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_146 * V_147 = & V_2 -> V_78 . V_79 ;
int V_124 ;
V_124 = F_76 ( V_8 , V_147 , V_144 ,
V_2 -> V_148 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_145 )
F_34 ( V_8 , V_145 ) ;
V_124 = F_77 ( V_8 , V_147 ) ;
if ( V_124 < 0 )
return V_124 ;
return 1 ;
}
static int F_78 ( struct V_7 * V_8 , T_1 V_149 )
{
struct V_1 * V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
int V_124 ;
if ( ! V_2 )
return - V_121 ;
V_8 -> V_2 = V_2 ;
F_79 ( & V_2 -> V_78 ) ;
V_2 -> V_78 . V_149 = V_149 ;
V_2 -> V_78 . V_150 = 1 ;
V_8 -> V_151 = 1 ;
V_8 -> V_152 = 1 ;
V_124 = F_72 ( V_8 ) ;
if ( V_124 < 0 ) {
F_11 ( V_2 ) ;
return V_124 ;
}
return 0 ;
}
static int F_80 ( struct V_7 * V_8 )
{
static const T_1 V_153 [] = { 0x1d , 0 } ;
static const T_1 V_154 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_75 ( V_8 , V_153 , V_154 ) ;
}
static void F_81 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_82 ( V_8 , 0x21 , V_155 , F_8 ) ;
}
static int F_83 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_156 = 1 ;
V_2 -> V_78 . V_157 = 0x01 ;
F_84 ( V_8 , V_158 , V_159 ,
V_160 ) ;
F_59 ( V_8 , V_49 ) ;
V_124 = F_80 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 )
F_85 ( V_2 , 0x0b , 0x05 , V_162 ) ;
V_8 -> V_135 = V_163 ;
V_8 -> V_135 . V_164 = F_12 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_86 ( struct V_7 * V_8 )
{
static const T_1 V_165 [] = { 0x17 , 0 } ;
static const T_1 V_166 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_75 ( V_8 , V_165 , V_166 ) ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_8 , 0x01 , 0 , V_167 ,
V_2 -> V_78 . V_168 ) ;
}
static void F_88 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
V_2 -> V_78 . V_169 = F_87 ;
V_2 -> V_78 . V_170 = 1 ;
V_2 -> V_78 . V_171 = 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = 0x0f ;
F_82 ( V_8 , 0x0f , V_172 ,
V_173 ) ;
F_89 ( V_8 , V_39 ) ;
}
}
static void F_90 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_174 V_175 [] = {
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
switch ( V_48 ) {
case V_49 :
F_91 ( V_8 , V_175 ) ;
break;
case V_123 :
V_2 -> V_77 = V_176 ;
break;
}
}
static void F_92 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 )
V_2 -> V_77 = V_176 ;
}
static void F_93 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_177 = 1 ;
V_2 -> V_78 . V_178 = 1 ;
}
}
static int F_94 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x07 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_179 = 1 ;
V_2 -> V_78 . V_157 = 0x01 ;
F_84 ( V_8 , V_180 , V_181 ,
V_182 ) ;
F_59 ( V_8 , V_49 ) ;
V_124 = F_86 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 )
F_85 ( V_2 , 0x07 , 0x05 , V_162 ) ;
V_8 -> V_135 = V_163 ;
V_2 -> V_133 = F_21 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static void F_95 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_132 )
return;
F_15 ( V_8 ) ;
}
static void F_96 ( struct V_7 * V_8 , int V_183 , int V_184 )
{
unsigned int V_185 , V_186 , V_187 ;
V_185 = F_6 ( V_8 , V_8 -> V_188 , 0 ,
V_189 , 0 ) ;
if ( ! V_184 )
V_185 |= ( 1 << V_183 ) ;
else
V_185 &= ~ ( 1 << V_183 ) ;
V_186 = F_6 ( V_8 , V_8 -> V_188 , 0 ,
V_190 , 0 ) ;
V_186 |= ( 1 << V_183 ) ;
V_187 = F_6 ( V_8 , V_8 -> V_188 , 0 ,
V_191 , 0 ) ;
V_187 |= ( 1 << V_183 ) ;
F_5 ( V_8 , V_8 -> V_188 , 0 ,
V_192 , V_186 ) ;
F_5 ( V_8 , V_8 -> V_188 , 0 ,
V_193 , V_187 ) ;
F_22 ( 1 ) ;
F_5 ( V_8 , V_8 -> V_188 , 0 ,
V_167 , V_185 ) ;
}
static void F_97 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_132 )
return;
F_96 ( V_8 , 0 , 0 ) ;
F_96 ( V_8 , 1 , 0 ) ;
}
static void F_98 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
T_1 V_194 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_195 [ 2 ] = { 0x0e , 0x0f } ;
F_99 ( V_8 , 0x14 , 2 , V_194 ) ;
F_99 ( V_8 , 0x15 , 2 , V_194 ) ;
F_99 ( V_8 , 0x18 , 2 , V_195 ) ;
F_99 ( V_8 , 0x1a , 2 , V_195 ) ;
} else if ( V_48 == V_123 ) {
T_1 V_196 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_99 ( V_8 , 0x14 , 5 , V_196 ) ;
F_99 ( V_8 , 0x15 , 5 , V_196 ) ;
F_99 ( V_8 , 0x18 , 5 , V_196 ) ;
F_99 ( V_8 , 0x1a , 5 , V_196 ) ;
}
}
static void F_100 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_197 [ 2 ] = { 0x14 , 0x15 } ;
int V_55 ;
if ( V_48 != V_132 )
return;
for ( V_55 = 0 ; V_55 < F_3 ( V_197 ) ; V_55 ++ ) {
unsigned int V_9 = F_28 ( V_8 , V_197 [ V_55 ] ) ;
if ( F_101 ( V_9 ) != V_198 )
continue;
V_9 = F_102 ( V_8 , V_197 [ V_55 ] ) ;
V_9 |= V_199 ;
F_103 ( V_8 , V_197 [ V_55 ] , V_9 ) ;
V_2 -> V_78 . V_200 = 1 ;
break;
}
}
static void F_104 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_197 [ 2 ] = { 0x18 , 0x1a } ;
int V_55 ;
if ( V_48 != V_132 )
return;
for ( V_55 = 0 ; V_55 < F_3 ( V_197 ) ; V_55 ++ ) {
unsigned int V_9 ;
V_9 = F_102 ( V_8 , V_197 [ V_55 ] ) ;
V_9 |= V_201 ;
F_103 ( V_8 , V_197 [ V_55 ] , V_9 ) ;
}
V_2 -> V_78 . V_200 = 1 ;
}
static void F_105 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_202 = 1 ;
V_2 -> V_78 . V_203 = 1 ;
}
}
static int F_106 ( struct V_7 * V_8 )
{
static const T_1 V_204 [] = { 0x1d , 0 } ;
static const T_1 V_205 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_75 ( V_8 , V_204 , V_205 ) ;
}
static int F_107 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_7 ( V_8 , 0x20 , 0x0a , 10 ) ;
break;
}
F_84 ( V_8 , V_206 , V_207 ,
V_208 ) ;
F_59 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_73 ( V_8 ) )
V_2 -> V_78 . V_157 = 0x01 ;
V_124 = F_106 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 && V_2 -> V_78 . V_157 )
F_85 ( V_2 , 0x0b , 0x05 , V_162 ) ;
V_8 -> V_135 = V_163 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_108 ( struct V_7 * V_8 )
{
static const T_1 V_209 [] = { 0x1d , 0 } ;
static const T_1 V_210 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_75 ( V_8 , V_209 , V_210 ) ;
}
static int F_109 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_211 = 0x18 ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_7 ( V_8 , 0x20 , 0x0a , 10 ) ;
F_84 ( V_8 , V_212 , V_213 ,
V_214 ) ;
F_59 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_73 ( V_8 ) )
V_2 -> V_78 . V_157 = 0x01 ;
V_124 = F_108 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 && V_2 -> V_78 . V_157 )
F_85 ( V_2 , 0x0b , 0x05 , V_162 ) ;
V_8 -> V_135 = V_163 ;
V_2 -> V_133 = F_21 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_110 ( struct V_7 * V_8 )
{
static const T_1 V_215 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_75 ( V_8 , NULL , V_215 ) ;
}
static int F_111 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_157 = 0x01 ;
F_84 ( V_8 , V_216 , V_217 , V_218 ) ;
F_59 ( V_8 , V_49 ) ;
V_124 = F_110 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( V_124 > 0 && ! V_2 -> V_78 . V_161 &&
V_2 -> V_78 . V_79 . V_219 [ 0 ] != 0x1d ) {
F_1 ( V_2 , V_220 ) ;
F_89 ( V_8 , V_221 ) ;
if ( ! F_112 ( V_8 , 0x1d , V_162 ) )
F_113 ( V_8 , 0x1d , V_162 ,
( 0x0c << V_222 ) |
( 0x0c << V_223 ) |
( 0x07 << V_224 ) |
( 0 << V_225 ) ) ;
}
V_8 -> V_135 = V_163 ;
V_2 -> V_133 = F_21 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_114 ( struct V_226 * V_227 ,
struct V_7 * V_8 ,
struct V_228 * V_229 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_115 ( V_8 , & V_2 -> V_230 , V_229 ,
V_227 ) ;
}
static int F_116 ( struct V_226 * V_227 ,
struct V_7 * V_8 ,
unsigned int V_231 ,
unsigned int V_232 ,
struct V_228 * V_229 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_117 ( V_8 , & V_2 -> V_230 ,
V_231 , V_232 , V_229 ) ;
}
static int F_118 ( struct V_226 * V_227 ,
struct V_7 * V_8 ,
struct V_228 * V_229 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_119 ( V_8 , & V_2 -> V_230 ) ;
}
static int F_120 ( struct V_7 * V_8 )
{
static const T_1 V_233 [] = { 0x1d , 0 } ;
static const T_1 V_234 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_235 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
const T_1 * V_236 ;
switch ( V_2 -> V_237 ) {
case V_238 :
case V_239 :
case V_240 :
case V_241 :
V_236 = V_235 ;
break;
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_236 = V_234 ;
break;
default:
V_236 = V_234 ;
break;
}
return F_75 ( V_8 , V_233 , V_236 ) ;
}
static void F_121 ( struct V_7 * V_8 , int V_247 )
{
int V_9 = F_35 ( V_8 , 0x04 ) ;
if ( V_247 )
V_9 |= 1 << 11 ;
else
V_9 &= ~ ( 1 << 11 ) ;
F_36 ( V_8 , 0x04 , V_9 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_237 == V_242 )
F_121 ( V_8 , 0 ) ;
if ( V_2 -> V_237 == V_242 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
F_23 ( V_8 ) ;
}
static void F_123 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_248 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_249 ;
int V_9 ;
if ( ! V_248 )
return;
V_249 = F_124 ( V_8 , V_248 ) ;
F_36 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_248 , 0 ,
V_110 , V_250 ) ;
if ( V_249 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_248 , 0 ,
V_251 , V_252 ) ;
if ( V_249 )
F_22 ( 85 ) ;
V_9 = F_35 ( V_8 , 0x46 ) ;
F_36 ( V_8 , 0x46 , V_9 & ~ ( 3 << 12 ) ) ;
F_36 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_248 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_249 ;
int V_9 ;
if ( ! V_248 ) {
F_122 ( V_8 ) ;
return;
}
V_249 = F_124 ( V_8 , V_248 ) ;
F_36 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_248 , 0 ,
V_110 , V_250 ) ;
if ( V_249 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_248 , 0 ,
V_251 , 0x0 ) ;
V_9 = F_35 ( V_8 , 0x46 ) ;
F_36 ( V_8 , 0x46 , V_9 | ( 3 << 12 ) ) ;
if ( V_249 )
F_22 ( 85 ) ;
F_23 ( V_8 ) ;
F_36 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_126 ( struct V_7 * V_8 , unsigned int V_253 ,
unsigned int V_9 )
{
F_5 ( V_8 , 0x51 , 0 , V_11 , V_253 >> 1 ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 & 0xffff ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 >> 16 ) ;
}
static int F_127 ( struct V_7 * V_8 , unsigned int V_253 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x51 , 0 , V_11 , V_253 >> 1 ) ;
V_9 = F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
& 0xffff ;
V_9 |= F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
<< 16 ;
return V_9 ;
}
static void F_128 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_126 ( V_8 , 0x3000 , 0x000c ) ;
F_126 ( V_8 , 0x880c , 0x0008 ) ;
F_126 ( V_8 , 0x61c0 , 0x11110080 ) ;
F_126 ( V_8 , 0x6230 , 0xfc0d4011 ) ;
F_126 ( V_8 , 0x61b4 , 0x040a2b03 ) ;
F_126 ( V_8 , 0x61b0 , 0x00005b17 ) ;
F_126 ( V_8 , 0x61b8 , 0x04133303 ) ;
V_9 = F_127 ( V_8 , 0x6220 ) ;
F_126 ( V_8 , 0x6220 , ( V_9 | 0x3000 ) ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
F_126 ( V_8 , 0x61b8 , 0x04133302 ) ;
F_126 ( V_8 , 0x61b0 , 0x00005b16 ) ;
F_126 ( V_8 , 0x61b4 , 0x040a2b02 ) ;
F_126 ( V_8 , 0x6230 , 0xf80d4011 ) ;
F_126 ( V_8 , 0x6220 , 0x2002010f ) ;
F_126 ( V_8 , 0x880c , 0x00000004 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_128 ( V_8 ) ;
F_129 ( V_8 ) ;
F_126 ( V_8 , 0x61b0 , 0x5b14 ) ;
F_126 ( V_8 , 0x61b0 , 0x5b16 ) ;
F_126 ( V_8 , 0x61b4 , 0x04132b00 ) ;
F_126 ( V_8 , 0x61b4 , 0x04132b02 ) ;
F_126 ( V_8 , 0x61b8 , 0x041f3300 ) ;
F_126 ( V_8 , 0x61b8 , 0x041f3302 ) ;
F_5 ( V_8 , 0x51 , 0 , V_254 , 0 ) ;
F_126 ( V_8 , 0x61b8 , 0x041b3302 ) ;
F_126 ( V_8 , 0x61b8 , 0x04173302 ) ;
F_126 ( V_8 , 0x61b8 , 0x04163302 ) ;
F_126 ( V_8 , 0x8800 , 0x348b328b ) ;
F_126 ( V_8 , 0x8808 , 0x00020022 ) ;
F_126 ( V_8 , 0x8818 , 0x00000400 ) ;
V_9 = F_127 ( V_8 , 0x6200 ) >> 16 ;
if ( V_9 <= 3 )
F_126 ( V_8 , 0x6220 , 0x2002010f ) ;
else
F_126 ( V_8 , 0x6220 , 0x6002018f ) ;
F_126 ( V_8 , 0x61ac , 0x055525f0 ) ;
F_126 ( V_8 , 0x61c0 , 0x12230080 ) ;
F_126 ( V_8 , 0x61b4 , 0x040e2b02 ) ;
F_126 ( V_8 , 0x61bc , 0x010234f8 ) ;
F_126 ( V_8 , 0x880c , 0x00000004 ) ;
F_126 ( V_8 , 0x880c , 0x00000003 ) ;
F_126 ( V_8 , 0x880c , 0x00000010 ) ;
#ifdef F_131
F_128 ( V_8 ) ;
#endif
}
static int F_132 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_255 )
F_133 ( V_8 ) ;
return F_64 ( V_8 ) ;
}
static int F_134 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_237 == V_242 )
F_121 ( V_8 , 0 ) ;
if ( V_2 -> V_237 == V_242 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
V_8 -> V_135 . V_136 ( V_8 ) ;
if ( V_2 -> V_237 == V_242 )
F_121 ( V_8 , 1 ) ;
if ( V_2 -> V_237 == V_242 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x017 ) {
F_22 ( 200 ) ;
}
F_66 ( V_8 ) ;
F_67 ( V_8 ) ;
F_45 ( V_8 , true ) ;
F_68 ( V_8 , 0x01 ) ;
if ( V_2 -> V_255 )
F_135 ( V_8 ) ;
return 0 ;
}
static void F_136 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_148 = V_256 ;
}
static void F_137 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_257 ;
if ( V_48 != V_132 )
return;
V_257 = F_35 ( V_8 , 0x1e ) ;
F_36 ( V_8 , 0x1e , V_257 | 0x80 ) ;
}
static void F_138 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_148 |= V_258 ;
}
static void F_139 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
static const struct V_259 V_260 [] = {
{ 0x20 , V_11 , 0x0d } ,
{ 0x20 , V_14 , 0x4000 } ,
{}
} ;
unsigned int V_147 ;
if ( strcmp ( V_8 -> V_63 , L_17 ) &&
strcmp ( V_8 -> V_63 , L_18 ) )
return;
V_147 = F_28 ( V_8 , 0x12 ) ;
if ( F_140 ( V_147 ) == V_261 )
F_25 ( V_8 , V_260 ) ;
}
static void F_141 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_262 = & V_263 ;
V_2 -> V_78 . V_264 = & V_265 ;
}
static void F_142 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_257 ;
if ( V_48 != V_132 )
return;
V_257 = F_35 ( V_8 , 0x07 ) ;
F_36 ( V_8 , 0x07 , V_257 | 0x80 ) ;
}
static void F_143 ( struct V_7 * V_8 )
{
F_144 ( V_8 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x680 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x480 ) ;
}
static void F_145 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_169 = F_143 ;
}
static void F_146 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_266 ;
F_22 ( 200 ) ;
V_173 ( V_8 , V_20 ) ;
V_266 = V_2 -> V_78 . V_168 ? V_267 : 0 ;
F_22 ( 100 ) ;
F_5 ( V_8 , 0x18 , 0 , V_251 ,
V_266 ) ;
F_22 ( 500 ) ;
F_5 ( V_8 , 0x18 , 0 , V_251 ,
V_266 ) ;
}
static void F_147 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_148 |= V_258 ;
V_2 -> V_78 . V_268 = F_146 ;
}
}
static void F_148 ( void * V_269 , int V_270 )
{
struct V_7 * V_8 = V_269 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_271 ;
if ( V_2 -> V_272 )
V_270 = ! V_270 ;
V_271 = V_273 |
( V_270 ? V_274 : V_199 ) ;
if ( V_2 -> V_275 )
F_149 ( V_8 , V_2 -> V_275 , V_271 ) ;
}
static void F_150 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_276 * V_277 = NULL ;
if ( V_48 != V_49 )
return;
while ( ( V_277 = F_151 ( V_278 , NULL , V_277 ) ) ) {
int V_279 , V_183 ;
if ( sscanf ( V_277 -> V_128 , L_19 , & V_279 , & V_183 ) != 2 )
continue;
if ( V_183 < 0x0a || V_183 >= 0x10 )
break;
V_2 -> V_272 = V_279 ;
V_2 -> V_275 = V_183 - 0x0a + 0x18 ;
V_2 -> V_78 . V_280 . V_281 = F_148 ;
V_2 -> V_78 . V_282 = 1 ;
F_30 ( L_20 , V_2 -> V_275 ,
V_2 -> V_272 ) ;
break;
}
}
static void F_152 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_272 = 0 ;
V_2 -> V_275 = 0x18 ;
V_2 -> V_78 . V_280 . V_281 = F_148 ;
V_2 -> V_78 . V_282 = 1 ;
}
}
static void F_153 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_272 = 0 ;
V_2 -> V_275 = 0x19 ;
V_2 -> V_78 . V_280 . V_281 = F_148 ;
V_2 -> V_78 . V_282 = 1 ;
}
}
static void F_154 ( void * V_269 , int V_270 )
{
struct V_7 * V_8 = V_269 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_283 = V_2 -> V_284 ;
if ( V_270 )
V_2 -> V_284 &= ~ 0x08 ;
else
V_2 -> V_284 |= 0x08 ;
if ( V_2 -> V_284 != V_283 )
F_5 ( V_8 , 0x01 , 0 , V_167 ,
V_2 -> V_284 ) ;
}
static void F_155 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_283 = V_2 -> V_284 ;
if ( ! V_118 )
return;
if ( V_118 -> V_28 . integer . V_28 [ 0 ] ||
V_118 -> V_28 . integer . V_28 [ 1 ] )
V_2 -> V_284 &= ~ 0x10 ;
else
V_2 -> V_284 |= 0x10 ;
if ( V_2 -> V_284 != V_283 )
F_5 ( V_8 , 0x01 , 0 , V_167 ,
V_2 -> V_284 ) ;
}
static void F_156 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_259 V_285 [] = {
{ 0x01 , V_192 , 0x18 } ,
{ 0x01 , V_193 , 0x18 } ,
{}
} ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_280 . V_281 = F_154 ;
V_2 -> V_78 . V_122 = F_155 ;
V_2 -> V_284 = 0 ;
F_89 ( V_8 , V_285 ) ;
}
}
static void F_157 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x1b , 0x0c0b ) ;
F_36 ( V_8 , 0x45 , 0xc429 ) ;
V_9 = F_35 ( V_8 , 0x35 ) ;
F_36 ( V_8 , 0x35 , V_9 & 0xbfff ) ;
F_36 ( V_8 , 0x06 , 0x2104 ) ;
F_36 ( V_8 , 0x1a , 0x0001 ) ;
F_36 ( V_8 , 0x26 , 0x0004 ) ;
F_36 ( V_8 , 0x32 , 0x42a3 ) ;
break;
case 0x10ec0292 :
F_36 ( V_8 , 0x76 , 0x000e ) ;
F_36 ( V_8 , 0x6c , 0x2400 ) ;
F_36 ( V_8 , 0x18 , 0x7308 ) ;
F_36 ( V_8 , 0x6b , 0xc429 ) ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x15 , 0x0d40 ) ;
F_36 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_158 ( L_21 ) ;
}
static void F_159 ( struct V_7 * V_8 , T_1 V_248 ,
T_1 V_286 )
{
int V_9 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x45 , 0xc429 ) ;
F_149 ( V_8 , V_248 , 0 ) ;
V_9 = F_35 ( V_8 , 0x35 ) ;
F_36 ( V_8 , 0x35 , V_9 | 1 << 14 ) ;
F_36 ( V_8 , 0x06 , 0x2100 ) ;
F_36 ( V_8 , 0x1a , 0x0021 ) ;
F_36 ( V_8 , 0x26 , 0x008c ) ;
F_149 ( V_8 , V_286 , V_287 ) ;
break;
case 0x10ec0292 :
F_149 ( V_8 , V_248 , 0 ) ;
F_36 ( V_8 , 0x19 , 0xa208 ) ;
F_36 ( V_8 , 0x2e , 0xacf0 ) ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x11 , 0x0001 ) ;
F_149 ( V_8 , V_248 , 0 ) ;
F_36 ( V_8 , 0xb7 , 0x802b ) ;
F_36 ( V_8 , 0xb5 , 0x1040 ) ;
V_9 = F_35 ( V_8 , 0xc3 ) ;
F_36 ( V_8 , 0xc3 , V_9 | 1 << 12 ) ;
F_149 ( V_8 , V_286 , V_287 ) ;
break;
}
F_158 ( L_22 ) ;
}
static void F_160 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x06 , 0x2100 ) ;
F_36 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_36 ( V_8 , 0x76 , 0x000e ) ;
F_36 ( V_8 , 0x6c , 0x2400 ) ;
F_36 ( V_8 , 0x6b , 0xc429 ) ;
F_36 ( V_8 , 0x18 , 0x7308 ) ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x11 , 0x0041 ) ;
F_36 ( V_8 , 0x15 , 0x0d40 ) ;
F_36 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_158 ( L_23 ) ;
}
static void F_161 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x45 , 0xd429 ) ;
F_36 ( V_8 , 0x1b , 0x0c2b ) ;
F_36 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_36 ( V_8 , 0x6b , 0xd429 ) ;
F_36 ( V_8 , 0x76 , 0x0008 ) ;
F_36 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x15 , 0x0d60 ) ;
F_36 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_158 ( L_24 ) ;
}
static void F_162 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x45 , 0xe429 ) ;
F_36 ( V_8 , 0x1b , 0x0c2b ) ;
F_36 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_36 ( V_8 , 0x6b , 0xe429 ) ;
F_36 ( V_8 , 0x76 , 0x0008 ) ;
F_36 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x15 , 0x0d50 ) ;
F_36 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_158 ( L_25 ) ;
}
static void F_163 ( struct V_7 * V_8 )
{
int V_9 ;
bool V_288 = false ;
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0283 :
F_36 ( V_8 , 0x45 , 0xd029 ) ;
F_22 ( 300 ) ;
V_9 = F_35 ( V_8 , 0x46 ) ;
V_288 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_36 ( V_8 , 0x6b , 0xd429 ) ;
F_22 ( 300 ) ;
V_9 = F_35 ( V_8 , 0x6c ) ;
V_288 = ( V_9 & 0x001c ) == 0x001c ;
break;
case 0x10ec0668 :
F_36 ( V_8 , 0x11 , 0x0001 ) ;
F_36 ( V_8 , 0xb7 , 0x802b ) ;
F_36 ( V_8 , 0x15 , 0x0d60 ) ;
F_36 ( V_8 , 0xc3 , 0x0c00 ) ;
F_22 ( 300 ) ;
V_9 = F_35 ( V_8 , 0xbe ) ;
V_288 = ( V_9 & 0x1c02 ) == 0x1c02 ;
break;
}
F_158 ( L_26 ,
V_288 ? L_27 : L_28 ) ;
V_2 -> V_289 = V_288 ? V_290 : V_291 ;
}
static void F_164 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_292 = V_2 -> V_78 . V_102 [ V_2 -> V_78 . V_117 [ 0 ] ] ;
T_1 V_248 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
int V_293 ;
if ( ! F_124 ( V_8 , V_248 ) )
V_293 = V_294 ;
else if ( V_292 == V_2 -> V_295 )
V_293 = V_296 ;
else if ( V_292 == V_2 -> V_297 )
V_293 = V_298 ;
else
V_293 = V_299 ;
if ( V_293 == V_2 -> V_300 )
return;
switch ( V_293 ) {
case V_294 :
F_157 ( V_8 ) ;
V_2 -> V_78 . V_168 = false ;
break;
case V_296 :
if ( V_2 -> V_289 == V_301 )
F_163 ( V_8 ) ;
if ( V_2 -> V_289 == V_290 )
F_161 ( V_8 ) ;
else if ( V_2 -> V_289 == V_291 )
F_162 ( V_8 ) ;
V_2 -> V_78 . V_168 = true ;
break;
case V_298 :
F_159 ( V_8 , V_248 , V_2 -> V_297 ) ;
V_2 -> V_78 . V_168 = false ;
break;
case V_299 :
F_160 ( V_8 ) ;
V_2 -> V_78 . V_168 = true ;
break;
}
if ( V_293 != V_298 ) {
F_149 ( V_8 , V_248 ,
V_302 | V_303 ) ;
if ( V_2 -> V_297 )
F_149 ( V_8 , V_2 -> V_297 ,
V_304 ) ;
}
V_2 -> V_300 = V_293 ;
F_144 ( V_8 ) ;
}
static void F_165 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
F_164 ( V_8 ) ;
}
static void F_166 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_289 = V_305 ;
V_173 ( V_8 , V_20 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
int V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_146 * V_147 = & V_2 -> V_78 . V_79 ;
for ( V_55 = 0 ; V_55 < V_147 -> V_306 ; V_55 ++ ) {
if ( V_147 -> V_307 [ V_55 ] . V_308 && ! V_2 -> V_295 )
V_2 -> V_295 = V_147 -> V_307 [ V_55 ] . V_183 ;
if ( V_147 -> V_307 [ V_55 ] . V_309 && ! V_2 -> V_297 )
V_2 -> V_297 = V_147 -> V_307 [ V_55 ] . V_183 ;
}
V_2 -> V_78 . V_122 = F_165 ;
V_2 -> V_78 . V_169 = F_164 ;
V_2 -> V_78 . V_268 = F_166 ;
}
static void F_168 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_48 ) {
case V_49 :
V_2 -> V_148 |= V_258 | V_310 ;
break;
case V_123 :
F_167 ( V_8 ) ;
break;
case V_132 :
V_2 -> V_300 = 0 ;
F_164 ( V_8 ) ;
break;
}
}
static void F_169 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_148 |= V_258 ;
}
else
F_168 ( V_8 , V_47 , V_48 ) ;
}
static void F_170 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
int V_9 ;
F_36 ( V_8 , 0xc4 , 0x8000 ) ;
V_9 = F_35 ( V_8 , 0xc2 ) ;
F_36 ( V_8 , 0xc2 , V_9 & 0xfe ) ;
F_149 ( V_8 , 0x18 , 0 ) ;
}
F_168 ( V_8 , V_47 , V_48 ) ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_146 * V_147 = & V_2 -> V_78 . V_79 ;
T_1 V_16 ;
unsigned int V_311 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_147 -> V_306 ; V_55 ++ ) {
if ( V_147 -> V_307 [ V_55 ] . type != V_312 )
continue;
V_16 = V_147 -> V_307 [ V_55 ] . V_183 ;
V_311 = F_28 ( V_8 , V_16 ) ;
if ( F_172 ( V_311 ) == V_313 )
continue;
return V_16 ;
}
return 0 ;
}
static void F_173 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
int V_286 = F_171 ( V_8 ) ;
int V_248 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
if ( F_2 ( ! V_286 || ! V_248 ) )
return;
F_174 ( V_8 , V_286 , V_248 ) ;
}
}
static void F_175 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_146 * V_147 = & V_2 -> V_78 . V_79 ;
int V_55 ;
if ( V_48 != V_123 )
return;
for ( V_55 = 0 ; V_55 < V_147 -> V_306 ; V_55 ++ ) {
T_1 V_16 = V_147 -> V_307 [ V_55 ] . V_183 ;
unsigned int V_311 ;
if ( V_147 -> V_307 [ V_55 ] . type != V_312 )
continue;
V_311 = F_28 ( V_8 , V_16 ) ;
if ( F_172 ( V_311 ) != V_313 )
continue;
F_113 ( V_8 , V_16 , V_162 ,
( 0x00 << V_222 ) |
( 0x01 << V_223 ) |
( 0x2f << V_224 ) |
( 0 << V_225 ) ) ;
}
}
static void F_176 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_266 ;
F_22 ( 200 ) ;
V_173 ( V_8 , V_20 ) ;
V_266 = V_2 -> V_78 . V_168 ? V_267 : 0 ;
F_22 ( 600 ) ;
F_5 ( V_8 , 0x19 , 0 , V_251 ,
V_266 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
F_178 ( V_8 , 0x03 , 0 ) ;
}
static void F_179 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_48 ) {
case V_49 :
F_177 ( V_8 ) ;
V_2 -> V_78 . V_268 = F_176 ;
V_9 = F_35 ( V_8 , 0x06 ) ;
F_36 ( V_8 , 0x06 , V_9 & ~ 0x000c ) ;
V_9 = F_35 ( V_8 , 0x1a ) ;
F_36 ( V_8 , 0x1a , V_9 | ( 1 << 4 ) ) ;
break;
}
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_144 ( V_8 ) ;
if ( F_124 ( V_8 , 0x1b ) )
V_2 -> V_78 . V_314 |= ( 1ULL << 0x14 ) ;
}
static void F_181 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_259 V_315 [] = {
{ 0x01 , V_192 , 0x04 } ,
{ 0x01 , V_193 , 0x04 } ,
{ 0x01 , V_167 , 0x04 } ,
{}
} ;
static const struct V_174 V_316 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_21 * V_22 ;
switch ( V_48 ) {
case V_49 :
F_89 ( V_8 , V_315 ) ;
F_91 ( V_8 , V_316 ) ;
V_2 -> V_78 . V_317 = 1 ;
V_2 -> V_78 . V_169 = F_180 ;
F_82 ( V_8 , 0x1b ,
V_172 ,
V_173 ) ;
break;
case V_130 :
V_22 = F_9 ( V_8 , L_29 ) ;
if ( V_22 )
strcpy ( V_22 -> V_318 . V_128 , L_30 ) ;
V_22 = F_9 ( V_8 , L_31 ) ;
if ( V_22 )
strcpy ( V_22 -> V_318 . V_128 , L_29 ) ;
break;
}
}
static void F_182 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 )
F_178 ( V_8 , 0x03 , 0 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
if ( V_2 -> V_237 != V_242 )
return;
if ( ( F_37 ( V_8 ) & 0x00ff ) < 0x015 ) {
F_36 ( V_8 , 0xf , 0x960b ) ;
F_36 ( V_8 , 0xe , 0x8817 ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x016 ) {
F_36 ( V_8 , 0xf , 0x960b ) ;
F_36 ( V_8 , 0xe , 0x8814 ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x017 ) {
V_9 = F_35 ( V_8 , 0x04 ) ;
F_36 ( V_8 , 0x04 , V_9 | ( 1 << 11 ) ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
V_9 = F_35 ( V_8 , 0xd ) ;
if ( ( V_9 & 0x0c00 ) >> 10 != 0x1 ) {
F_36 ( V_8 , 0xd , V_9 | ( 1 << 10 ) ) ;
}
V_9 = F_35 ( V_8 , 0x17 ) ;
if ( ( V_9 & 0x01c0 ) >> 6 != 0x4 ) {
F_36 ( V_8 , 0x17 , V_9 | ( 1 << 7 ) ) ;
}
}
V_9 = F_35 ( V_8 , 0xd ) ;
F_36 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
V_9 = F_35 ( V_8 , 0x4 ) ;
F_36 ( V_8 , 0x4 , V_9 | ( 1 << 11 ) ) ;
}
static int F_184 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_211 = 0x18 ;
F_84 ( V_8 , V_319 ,
V_320 , V_321 ) ;
F_59 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_73 ( V_8 ) )
V_2 -> V_78 . V_157 = 0x01 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0269 :
V_2 -> V_237 = V_238 ;
switch ( F_37 ( V_8 ) & 0x00f0 ) {
case 0x0010 :
if ( V_8 -> V_59 -> V_60 -> V_322 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 )
V_124 = F_69 ( V_8 , L_17 ) ;
V_2 -> V_237 = V_242 ;
break;
case 0x0020 :
if ( V_8 -> V_59 -> V_60 -> V_322 == 0x17aa &&
V_8 -> V_59 -> V_60 -> V_61 == 0x21f3 )
V_124 = F_69 ( V_8 , L_32 ) ;
V_2 -> V_237 = V_239 ;
break;
case 0x0030 :
V_2 -> V_237 = V_243 ;
break;
default:
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
}
if ( V_124 < 0 )
goto error;
V_2 -> V_131 = F_183 ;
F_183 ( V_8 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_2 -> V_237 = V_240 ;
break;
case 0x10ec0282 :
V_2 -> V_237 = V_244 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_2 -> V_237 = V_245 ;
V_2 -> V_133 = F_125 ;
V_2 -> V_131 = F_123 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_2 -> V_237 = V_241 ;
break;
case 0x10ec0286 :
V_2 -> V_237 = V_246 ;
break;
}
if ( F_6 ( V_8 , 0x51 , 0 , V_323 , 0 ) == 0x10ec5505 ) {
V_2 -> V_255 = true ;
V_2 -> V_131 = F_130 ;
}
V_124 = F_120 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 && V_2 -> V_78 . V_157 )
F_85 ( V_2 , 0x0b , 0x04 , V_162 ) ;
V_8 -> V_135 = V_163 ;
#ifdef F_185
V_8 -> V_135 . V_324 = F_132 ;
V_8 -> V_135 . V_325 = F_134 ;
#endif
if ( ! V_2 -> V_133 )
V_2 -> V_133 = F_122 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_186 ( struct V_7 * V_8 )
{
static const T_1 V_326 [] = { 0x1d , 0 } ;
static const T_1 V_327 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_75 ( V_8 , V_326 , V_327 ) ;
}
static void F_187 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( V_48 != V_132 )
return;
V_9 = F_102 ( V_8 , 0x0f ) ;
if ( ! ( V_9 & ( V_273 | V_302 ) ) )
V_9 |= V_273 ;
V_9 |= V_201 ;
F_103 ( V_8 , 0x0f , V_9 ) ;
V_2 -> V_78 . V_200 = 1 ;
}
static void F_188 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 )
V_8 -> V_328 = 1 ;
}
static int F_189 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x15 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_157 = 0x23 ;
F_84 ( V_8 , NULL , V_329 , V_330 ) ;
F_59 ( V_8 , V_49 ) ;
V_124 = F_186 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 )
F_85 ( V_2 , 0x23 , 0 , V_107 ) ;
V_8 -> V_135 = V_163 ;
#ifdef F_185
V_2 -> V_134 = F_63 ;
#endif
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_190 ( struct V_7 * V_8 )
{
static const T_1 V_331 [] = { 0x1d , 0 } ;
static const T_1 V_332 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_75 ( V_8 , V_331 , V_332 ) ;
}
static void F_191 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
F_192 ( V_8 , 0x18 , 0x00000734 ) ;
F_192 ( V_8 , 0x19 , 0x0000073c ) ;
}
}
static int F_193 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_157 = 0x23 ;
F_84 ( V_8 , NULL , V_333 , V_334 ) ;
F_59 ( V_8 , V_49 ) ;
V_124 = F_190 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 )
F_85 ( V_2 , 0x0b , 0x05 , V_162 ) ;
V_8 -> V_135 = V_163 ;
V_2 -> V_133 = F_21 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_194 ( struct V_7 * V_8 )
{
static const T_1 V_335 [] = { 0x1d , 0 } ;
static const T_1 V_336 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_337 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_236 ;
if ( V_8 -> V_45 == 0x10ec0272 || V_8 -> V_45 == 0x10ec0663 ||
V_8 -> V_45 == 0x10ec0665 || V_8 -> V_45 == 0x10ec0670 ||
V_8 -> V_45 == 0x10ec0671 )
V_236 = V_336 ;
else
V_236 = V_337 ;
return F_75 ( V_8 , V_335 , V_236 ) ;
}
static void F_195 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_49 )
return;
if ( F_113 ( V_8 , 0x2 , V_107 ,
( 0x3b << V_222 ) |
( 0x3b << V_223 ) |
( 0x03 << V_224 ) |
( 0 << V_225 ) ) )
F_29 ( V_338
L_33 ) ;
}
static void F_196 ( struct V_7 * V_8 )
{
int V_9 , V_257 ;
V_257 = F_37 ( V_8 ) ;
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
if ( ( V_257 & 0x00f0 ) == 0x0030 ) {
V_9 = F_35 ( V_8 , 0x4 ) ;
F_36 ( V_8 , 0x4 , V_9 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_9 = F_35 ( V_8 , 0xd ) ;
F_36 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
break;
}
}
static int F_197 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_78 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_148 = V_256 ;
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
V_2 -> V_131 = F_196 ;
F_196 ( V_8 ) ;
F_84 ( V_8 , V_339 ,
V_340 , V_341 ) ;
F_59 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_73 ( V_8 ) )
V_2 -> V_78 . V_157 = 0x01 ;
if ( ( F_37 ( V_8 ) & ( 1 << 14 ) ) &&
V_8 -> V_59 -> V_60 -> V_322 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 ) {
V_124 = F_69 ( V_8 , L_34 ) ;
if ( V_124 < 0 )
goto error;
}
V_124 = F_194 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_161 && V_2 -> V_78 . V_157 ) {
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
F_85 ( V_2 , 0x0b , 0x05 , V_162 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_85 ( V_2 , 0x0b , 0x04 , V_162 ) ;
break;
case 0x10ec0273 :
F_85 ( V_2 , 0x0b , 0x03 , V_162 ) ;
break;
}
}
V_8 -> V_135 = V_163 ;
V_2 -> V_133 = F_21 ;
F_59 ( V_8 , V_123 ) ;
return 0 ;
error:
F_71 ( V_8 ) ;
return V_124 ;
}
static int F_198 ( struct V_7 * V_8 )
{
return F_75 ( V_8 , NULL , NULL ) ;
}
static int F_199 ( struct V_7 * V_8 )
{
int V_124 ;
V_124 = F_78 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_198 ( V_8 ) ;
if ( V_124 < 0 ) {
F_71 ( V_8 ) ;
return V_124 ;
}
V_8 -> V_135 = V_163 ;
return 0 ;
}
static int T_2 F_200 ( void )
{
return F_201 ( & V_342 ) ;
}
static void T_3 F_202 ( void )
{
F_203 ( & V_342 ) ;
}
