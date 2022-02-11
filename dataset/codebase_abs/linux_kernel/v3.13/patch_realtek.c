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
T_1 V_16 ,
unsigned int V_17 )
{
unsigned int V_9 ;
F_5 ( V_8 , V_16 , 0 , V_11 ,
V_17 ) ;
V_9 = F_6 ( V_8 , V_16 , 0 ,
V_13 , 0 ) ;
return V_9 ;
}
static void F_36 ( struct V_7 * V_8 , T_1 V_16 ,
unsigned int V_17 ,
unsigned int V_86 )
{
F_5 ( V_8 , V_16 , 0 , V_11 ,
V_17 ) ;
F_5 ( V_8 , V_16 , 0 , V_14 ,
V_86 ) ;
}
static unsigned int F_37 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_87 )
V_2 -> V_87 = F_38 ( V_8 , 0 ) ;
return V_2 -> V_87 ;
}
static T_1 F_39 ( struct V_7 * V_8 , int V_88 , int V_89 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_91 )
V_88 = V_2 -> V_92 [ V_89 ] ;
return V_2 -> V_93 [ V_88 ] ;
}
static void F_40 ( struct V_7 * V_8 , int V_88 )
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
V_98 = F_41 ( V_8 , V_2 -> V_103 ,
F_39 ( V_8 , V_88 , V_55 ) ) ;
V_9 = V_98 -> V_104 [ V_105 ] ;
if ( ! V_9 )
return;
V_16 = F_42 ( V_9 ) ;
V_99 = F_43 ( V_9 ) ;
V_100 = V_106 |
( V_99 == V_107 ? V_108 : V_109 ) ;
F_44 ( V_8 ) ;
V_9 = F_45 ( V_8 , V_16 , 1 , V_99 , 0 ) ;
if ( V_9 & 0x80 )
return;
V_9 |= 0x80 ;
F_5 ( V_8 , V_16 , 0 , V_110 ,
V_100 | V_9 ) ;
}
static void F_46 ( struct V_7 * V_8 , bool V_111 )
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
F_40 ( V_8 , V_112 ) ;
}
}
static void F_47 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
F_46 ( V_8 , false ) ;
}
static int F_48 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_49 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_118 -> V_28 . integer . V_28 [ 0 ] = ! V_2 -> V_114 ;
return 0 ;
}
static int F_50 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_49 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 = ! V_118 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_9 == V_2 -> V_114 )
return 0 ;
V_2 -> V_114 = V_9 ;
F_46 ( V_8 , true ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_52 ( & V_2 -> V_78 , NULL , & V_120 ) )
return - V_121 ;
V_2 -> V_113 = 1 ;
V_2 -> V_114 = 0 ;
V_2 -> V_103 = V_16 ;
V_2 -> V_78 . V_122 = F_47 ;
return 0 ;
}
static void F_53 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_51 ( V_8 , 0x12 ) ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_55 , V_124 ;
V_124 = F_55 ( V_8 ) ;
if ( V_124 < 0 )
return V_124 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 ; V_55 ++ ) {
V_124 = F_56 ( V_8 , V_2 -> V_6 [ V_55 ] ) ;
if ( V_124 < 0 )
return V_124 ;
}
#ifdef F_57
if ( V_2 -> V_125 ) {
const struct V_3 * V_126 ;
for ( V_126 = V_127 ; V_126 -> V_128 ; V_126 ++ ) {
struct V_21 * V_22 ;
V_22 = F_58 ( V_126 , V_8 ) ;
if ( ! V_22 )
return - V_121 ;
V_22 -> V_129 = V_2 -> V_125 ;
V_124 = F_59 ( V_8 , 0 , V_22 ) ;
if ( V_124 < 0 )
return V_124 ;
}
}
#endif
F_60 ( V_8 , V_130 ) ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
F_4 ( V_8 ) ;
F_24 ( V_8 , V_2 -> V_77 ) ;
F_62 ( V_8 ) ;
F_60 ( V_8 , V_132 ) ;
return 0 ;
}
static inline void F_63 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 && V_2 -> V_133 )
V_2 -> V_133 ( V_8 ) ;
else
F_23 ( V_8 ) ;
}
static void F_64 ( struct V_7 * V_8 )
{
F_60 ( V_8 , V_134 ) ;
F_65 ( V_8 ) ;
}
static void F_66 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_63 ( V_8 ) ;
if ( V_2 && V_2 -> V_135 )
V_2 -> V_135 ( V_8 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_8 )
{
F_22 ( 150 ) ;
V_8 -> V_136 . V_137 ( V_8 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
F_46 ( V_8 , true ) ;
F_71 ( V_8 , 0x01 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_8 , const char * V_128 )
{
F_11 ( V_8 -> V_63 ) ;
V_8 -> V_63 = F_73 ( V_128 , V_25 ) ;
if ( ! V_8 -> V_63 ) {
F_64 ( V_8 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_74 ( struct V_7 * V_8 )
{
const struct V_138 * V_37 ;
for ( V_37 = V_139 ; V_37 -> V_45 ; V_37 ++ ) {
if ( V_37 -> V_45 != V_8 -> V_45 )
continue;
if ( ( F_37 ( V_8 ) & V_37 -> V_140 ) == V_37 -> V_141 )
return F_72 ( V_8 , V_37 -> V_128 ) ;
}
return 0 ;
}
static inline int F_75 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_142 * V_143 ;
V_143 = F_76 ( V_8 -> V_59 -> V_60 , V_144 ) ;
if ( V_143 )
return V_143 -> V_28 ;
return V_2 -> V_50 . V_56 ;
}
static int F_77 ( struct V_7 * V_8 ,
const T_1 * V_145 ,
const T_1 * V_146 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_147 * V_148 = & V_2 -> V_78 . V_79 ;
int V_124 ;
V_124 = F_78 ( V_8 , V_148 , V_145 ,
V_2 -> V_149 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_146 )
F_34 ( V_8 , V_146 ) ;
V_124 = F_79 ( V_8 , V_148 ) ;
if ( V_124 < 0 )
return V_124 ;
return 1 ;
}
static int F_80 ( struct V_7 * V_8 , T_1 V_150 )
{
struct V_1 * V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
int V_124 ;
if ( ! V_2 )
return - V_121 ;
V_8 -> V_2 = V_2 ;
F_81 ( & V_2 -> V_78 ) ;
V_2 -> V_78 . V_150 = V_150 ;
V_2 -> V_78 . V_151 = 1 ;
V_8 -> V_152 = 1 ;
V_8 -> V_153 = 1 ;
V_124 = F_74 ( V_8 ) ;
if ( V_124 < 0 ) {
F_11 ( V_2 ) ;
return V_124 ;
}
return 0 ;
}
static int F_82 ( struct V_7 * V_8 )
{
static const T_1 V_154 [] = { 0x1d , 0 } ;
static const T_1 V_155 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_154 , V_155 ) ;
}
static void F_83 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_84 ( V_8 , 0x21 , V_156 , F_8 ) ;
}
static int F_85 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_157 = 1 ;
V_2 -> V_78 . V_158 = 0x01 ;
F_86 ( V_8 , V_159 , V_160 ,
V_161 ) ;
F_60 ( V_8 , V_49 ) ;
V_124 = F_82 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 )
F_87 ( V_2 , 0x0b , 0x05 , V_163 ) ;
V_8 -> V_136 = V_164 ;
V_8 -> V_136 . V_165 = F_12 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_88 ( struct V_7 * V_8 )
{
static const T_1 V_166 [] = { 0x17 , 0 } ;
static const T_1 V_167 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_77 ( V_8 , V_166 , V_167 ) ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_8 , 0x01 , 0 , V_168 ,
V_2 -> V_78 . V_169 ) ;
}
static void F_90 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
V_2 -> V_78 . V_170 = F_89 ;
V_2 -> V_78 . V_171 = 1 ;
V_2 -> V_78 . V_172 = 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = 0x0f ;
F_84 ( V_8 , 0x0f , V_173 ,
V_174 ) ;
F_91 ( V_8 , V_39 ) ;
}
}
static void F_92 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_175 V_176 [] = {
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
F_93 ( V_8 , V_176 ) ;
break;
case V_123 :
V_2 -> V_77 = V_177 ;
break;
}
}
static void F_94 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 )
V_2 -> V_77 = V_177 ;
}
static void F_95 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_178 = 1 ;
V_2 -> V_78 . V_179 = 1 ;
}
}
static int F_96 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x07 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_180 = 1 ;
V_2 -> V_78 . V_158 = 0x01 ;
F_86 ( V_8 , V_181 , V_182 ,
V_183 ) ;
F_60 ( V_8 , V_49 ) ;
V_124 = F_88 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 )
F_87 ( V_2 , 0x07 , 0x05 , V_163 ) ;
V_8 -> V_136 = V_164 ;
V_2 -> V_133 = F_21 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static void F_97 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_132 )
return;
F_15 ( V_8 ) ;
}
static void F_98 ( struct V_7 * V_8 , int V_184 , int V_185 )
{
unsigned int V_186 , V_187 , V_188 ;
V_186 = F_6 ( V_8 , V_8 -> V_189 , 0 ,
V_190 , 0 ) ;
if ( ! V_185 )
V_186 |= ( 1 << V_184 ) ;
else
V_186 &= ~ ( 1 << V_184 ) ;
V_187 = F_6 ( V_8 , V_8 -> V_189 , 0 ,
V_191 , 0 ) ;
V_187 |= ( 1 << V_184 ) ;
V_188 = F_6 ( V_8 , V_8 -> V_189 , 0 ,
V_192 , 0 ) ;
V_188 |= ( 1 << V_184 ) ;
F_5 ( V_8 , V_8 -> V_189 , 0 ,
V_193 , V_187 ) ;
F_5 ( V_8 , V_8 -> V_189 , 0 ,
V_194 , V_188 ) ;
F_22 ( 1 ) ;
F_5 ( V_8 , V_8 -> V_189 , 0 ,
V_168 , V_186 ) ;
}
static void F_99 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_132 )
return;
F_98 ( V_8 , 0 , 0 ) ;
F_98 ( V_8 , 1 , 0 ) ;
}
static void F_100 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
T_1 V_195 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_196 [ 2 ] = { 0x0e , 0x0f } ;
F_101 ( V_8 , 0x14 , 2 , V_195 ) ;
F_101 ( V_8 , 0x15 , 2 , V_195 ) ;
F_101 ( V_8 , 0x18 , 2 , V_196 ) ;
F_101 ( V_8 , 0x1a , 2 , V_196 ) ;
} else if ( V_48 == V_123 ) {
T_1 V_197 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_101 ( V_8 , 0x14 , 5 , V_197 ) ;
F_101 ( V_8 , 0x15 , 5 , V_197 ) ;
F_101 ( V_8 , 0x18 , 5 , V_197 ) ;
F_101 ( V_8 , 0x1a , 5 , V_197 ) ;
}
}
static void F_102 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_198 [ 2 ] = { 0x14 , 0x15 } ;
int V_55 ;
if ( V_48 != V_132 )
return;
for ( V_55 = 0 ; V_55 < F_3 ( V_198 ) ; V_55 ++ ) {
unsigned int V_9 = F_28 ( V_8 , V_198 [ V_55 ] ) ;
if ( F_103 ( V_9 ) != V_199 )
continue;
V_9 = F_104 ( V_8 , V_198 [ V_55 ] ) ;
V_9 |= V_200 ;
F_105 ( V_8 , V_198 [ V_55 ] , V_9 ) ;
V_2 -> V_78 . V_201 = 1 ;
break;
}
}
static void F_106 ( struct V_7 * V_8 ,
const T_1 * V_198 , int V_202 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_202 ; V_55 ++ ) {
unsigned int V_9 ;
V_9 = F_104 ( V_8 , V_198 [ V_55 ] ) ;
V_9 |= V_203 ;
F_105 ( V_8 , V_198 [ V_55 ] , V_9 ) ;
}
V_2 -> V_78 . V_201 = 1 ;
}
static void F_107 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
static T_1 V_198 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_48 == V_132 )
F_106 ( V_8 , V_198 , F_3 ( V_198 ) ) ;
}
static void F_108 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
static T_1 V_198 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_48 == V_132 )
F_106 ( V_8 , V_198 , F_3 ( V_198 ) ) ;
}
static void F_109 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_204 = 1 ;
V_2 -> V_78 . V_205 = 1 ;
}
}
static int F_110 ( struct V_7 * V_8 )
{
static const T_1 V_206 [] = { 0x1d , 0 } ;
static const T_1 V_207 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_206 , V_207 ) ;
}
static int F_111 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
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
F_86 ( V_8 , V_208 , V_209 ,
V_210 ) ;
F_60 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_78 . V_158 = 0x01 ;
V_124 = F_110 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 && V_2 -> V_78 . V_158 )
F_87 ( V_2 , 0x0b , 0x05 , V_163 ) ;
V_8 -> V_136 = V_164 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_112 ( struct V_7 * V_8 )
{
static const T_1 V_211 [] = { 0x1d , 0 } ;
static const T_1 V_212 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_211 , V_212 ) ;
}
static int F_113 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_213 = 0x18 ;
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
F_86 ( V_8 , V_214 , V_215 ,
V_216 ) ;
F_60 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_78 . V_158 = 0x01 ;
V_124 = F_112 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 && V_2 -> V_78 . V_158 )
F_87 ( V_2 , 0x0b , 0x05 , V_163 ) ;
V_8 -> V_136 = V_164 ;
V_2 -> V_133 = F_21 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_114 ( struct V_7 * V_8 )
{
static const T_1 V_217 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , NULL , V_217 ) ;
}
static int F_115 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_158 = 0x01 ;
F_86 ( V_8 , V_218 , V_219 , V_220 ) ;
F_60 ( V_8 , V_49 ) ;
V_124 = F_114 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( V_124 > 0 && ! V_2 -> V_78 . V_162 &&
V_2 -> V_78 . V_79 . V_221 [ 0 ] != 0x1d ) {
F_1 ( V_2 , V_222 ) ;
F_91 ( V_8 , V_223 ) ;
if ( ! F_116 ( V_8 , 0x1d , V_163 ) )
F_117 ( V_8 , 0x1d , V_163 ,
( 0x0c << V_224 ) |
( 0x0c << V_225 ) |
( 0x07 << V_226 ) |
( 0 << V_227 ) ) ;
}
V_8 -> V_136 = V_164 ;
V_2 -> V_133 = F_21 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_118 ( struct V_228 * V_229 ,
struct V_7 * V_8 ,
struct V_230 * V_231 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_119 ( V_8 , & V_2 -> V_232 , V_231 ,
V_229 ) ;
}
static int F_120 ( struct V_228 * V_229 ,
struct V_7 * V_8 ,
unsigned int V_233 ,
unsigned int V_234 ,
struct V_230 * V_231 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_121 ( V_8 , & V_2 -> V_232 ,
V_233 , V_234 , V_231 ) ;
}
static int F_122 ( struct V_228 * V_229 ,
struct V_7 * V_8 ,
struct V_230 * V_231 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_123 ( V_8 , & V_2 -> V_232 ) ;
}
static int F_124 ( struct V_7 * V_8 )
{
static const T_1 V_235 [] = { 0x1d , 0 } ;
static const T_1 V_236 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_237 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
const T_1 * V_238 ;
switch ( V_2 -> V_239 ) {
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_238 = V_237 ;
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_238 = V_236 ;
break;
default:
V_238 = V_236 ;
break;
}
return F_77 ( V_8 , V_235 , V_238 ) ;
}
static void F_125 ( struct V_7 * V_8 , int V_251 )
{
int V_9 = F_38 ( V_8 , 0x04 ) ;
if ( V_251 )
V_9 |= 1 << 11 ;
else
V_9 &= ~ ( 1 << 11 ) ;
F_126 ( V_8 , 0x04 , V_9 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_239 == V_245 )
F_125 ( V_8 , 0 ) ;
if ( V_2 -> V_239 == V_245 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
F_23 ( V_8 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_252 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_253 ;
int V_9 ;
if ( ! V_252 )
return;
V_253 = F_129 ( V_8 , V_252 ) ;
F_126 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_252 , 0 ,
V_110 , V_254 ) ;
if ( V_253 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_252 , 0 ,
V_255 , V_256 ) ;
if ( V_253 )
F_22 ( 85 ) ;
V_9 = F_38 ( V_8 , 0x46 ) ;
F_126 ( V_8 , 0x46 , V_9 & ~ ( 3 << 12 ) ) ;
F_126 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_252 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_253 ;
int V_9 ;
if ( ! V_252 ) {
F_127 ( V_8 ) ;
return;
}
V_253 = F_129 ( V_8 , V_252 ) ;
F_126 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_252 , 0 ,
V_110 , V_254 ) ;
if ( V_253 )
F_22 ( 100 ) ;
F_5 ( V_8 , V_252 , 0 ,
V_255 , 0x0 ) ;
V_9 = F_38 ( V_8 , 0x46 ) ;
F_126 ( V_8 , 0x46 , V_9 | ( 3 << 12 ) ) ;
if ( V_253 )
F_22 ( 100 ) ;
F_23 ( V_8 ) ;
F_126 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_131 ( struct V_7 * V_8 , unsigned int V_257 ,
unsigned int V_9 )
{
F_5 ( V_8 , 0x51 , 0 , V_11 , V_257 >> 1 ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 & 0xffff ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 >> 16 ) ;
}
static int F_132 ( struct V_7 * V_8 , unsigned int V_257 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x51 , 0 , V_11 , V_257 >> 1 ) ;
V_9 = F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
& 0xffff ;
V_9 |= F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
<< 16 ;
return V_9 ;
}
static void F_133 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_131 ( V_8 , 0x3000 , 0x000c ) ;
F_131 ( V_8 , 0x880c , 0x0008 ) ;
F_131 ( V_8 , 0x61c0 , 0x11110080 ) ;
F_131 ( V_8 , 0x6230 , 0xfc0d4011 ) ;
F_131 ( V_8 , 0x61b4 , 0x040a2b03 ) ;
F_131 ( V_8 , 0x61b0 , 0x00005b17 ) ;
F_131 ( V_8 , 0x61b8 , 0x04133303 ) ;
V_9 = F_132 ( V_8 , 0x6220 ) ;
F_131 ( V_8 , 0x6220 , ( V_9 | 0x3000 ) ) ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_131 ( V_8 , 0x61b8 , 0x04133302 ) ;
F_131 ( V_8 , 0x61b0 , 0x00005b16 ) ;
F_131 ( V_8 , 0x61b4 , 0x040a2b02 ) ;
F_131 ( V_8 , 0x6230 , 0xf80d4011 ) ;
F_131 ( V_8 , 0x6220 , 0x2002010f ) ;
F_131 ( V_8 , 0x880c , 0x00000004 ) ;
}
static void F_135 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_133 ( V_8 ) ;
F_134 ( V_8 ) ;
F_131 ( V_8 , 0x61b0 , 0x5b14 ) ;
F_131 ( V_8 , 0x61b0 , 0x5b16 ) ;
F_131 ( V_8 , 0x61b4 , 0x04132b00 ) ;
F_131 ( V_8 , 0x61b4 , 0x04132b02 ) ;
F_131 ( V_8 , 0x61b8 , 0x041f3300 ) ;
F_131 ( V_8 , 0x61b8 , 0x041f3302 ) ;
F_5 ( V_8 , 0x51 , 0 , V_258 , 0 ) ;
F_131 ( V_8 , 0x61b8 , 0x041b3302 ) ;
F_131 ( V_8 , 0x61b8 , 0x04173302 ) ;
F_131 ( V_8 , 0x61b8 , 0x04163302 ) ;
F_131 ( V_8 , 0x8800 , 0x348b328b ) ;
F_131 ( V_8 , 0x8808 , 0x00020022 ) ;
F_131 ( V_8 , 0x8818 , 0x00000400 ) ;
V_9 = F_132 ( V_8 , 0x6200 ) >> 16 ;
if ( V_9 <= 3 )
F_131 ( V_8 , 0x6220 , 0x2002010f ) ;
else
F_131 ( V_8 , 0x6220 , 0x6002018f ) ;
F_131 ( V_8 , 0x61ac , 0x055525f0 ) ;
F_131 ( V_8 , 0x61c0 , 0x12230080 ) ;
F_131 ( V_8 , 0x61b4 , 0x040e2b02 ) ;
F_131 ( V_8 , 0x61bc , 0x010234f8 ) ;
F_131 ( V_8 , 0x880c , 0x00000004 ) ;
F_131 ( V_8 , 0x880c , 0x00000003 ) ;
F_131 ( V_8 , 0x880c , 0x00000010 ) ;
#ifdef F_136
F_133 ( V_8 ) ;
#endif
}
static int F_137 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_259 )
F_138 ( V_8 ) ;
return F_67 ( V_8 ) ;
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_239 == V_245 )
F_125 ( V_8 , 0 ) ;
if ( V_2 -> V_239 == V_245 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
V_8 -> V_136 . V_137 ( V_8 ) ;
if ( V_2 -> V_239 == V_245 )
F_125 ( V_8 , 1 ) ;
if ( V_2 -> V_239 == V_245 &&
( F_37 ( V_8 ) & 0x00ff ) == 0x017 ) {
F_22 ( 200 ) ;
}
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
F_46 ( V_8 , true ) ;
F_71 ( V_8 , 0x01 ) ;
if ( V_2 -> V_259 )
F_140 ( V_8 ) ;
return 0 ;
}
static void F_141 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_149 = V_260 ;
}
static void F_142 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_261 ;
if ( V_48 != V_132 )
return;
V_261 = F_38 ( V_8 , 0x1e ) ;
F_126 ( V_8 , 0x1e , V_261 | 0x80 ) ;
}
static void F_143 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_149 |= V_262 ;
}
static void F_144 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
static const struct V_263 V_264 [] = {
{ 0x20 , V_11 , 0x0d } ,
{ 0x20 , V_14 , 0x4000 } ,
{}
} ;
unsigned int V_148 ;
if ( strcmp ( V_8 -> V_63 , L_17 ) &&
strcmp ( V_8 -> V_63 , L_18 ) )
return;
V_148 = F_28 ( V_8 , 0x12 ) ;
if ( F_145 ( V_148 ) == V_265 )
F_25 ( V_8 , V_264 ) ;
}
static void F_146 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_266 = & V_267 ;
V_2 -> V_78 . V_268 = & V_269 ;
}
static void F_147 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_261 ;
if ( V_48 != V_132 )
return;
V_261 = F_38 ( V_8 , 0x07 ) ;
F_126 ( V_8 , 0x07 , V_261 | 0x80 ) ;
}
static void F_148 ( struct V_7 * V_8 )
{
F_149 ( V_8 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x680 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x480 ) ;
}
static void F_150 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_170 = F_148 ;
}
static void F_151 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_270 ;
F_22 ( 200 ) ;
V_174 ( V_8 , V_20 ) ;
V_270 = V_2 -> V_78 . V_169 ? V_271 : 0 ;
F_22 ( 100 ) ;
F_5 ( V_8 , 0x18 , 0 , V_255 ,
V_270 ) ;
F_22 ( 500 ) ;
F_5 ( V_8 , 0x18 , 0 , V_255 ,
V_270 ) ;
}
static void F_152 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_149 |= V_262 ;
V_2 -> V_78 . V_272 = F_151 ;
}
}
static void F_153 ( void * V_273 , int V_274 )
{
struct V_7 * V_8 = V_273 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_275 ;
if ( V_2 -> V_276 )
V_274 = ! V_274 ;
V_275 = V_277 |
( V_274 ? V_278 : V_200 ) ;
if ( V_2 -> V_279 )
F_154 ( V_8 , V_2 -> V_279 , V_275 ) ;
}
static unsigned int F_155 ( struct V_7 * V_8 ,
T_1 V_16 ,
unsigned int V_280 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_280 != V_281 || V_16 != V_2 -> V_279 )
return V_280 ;
F_105 ( V_8 , V_16 ,
F_104 ( V_8 , V_16 ) ) ;
return V_282 ;
}
static void F_156 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_283 * V_284 = NULL ;
if ( V_48 != V_49 )
return;
while ( ( V_284 = F_157 ( V_285 , NULL , V_284 ) ) ) {
int V_286 , V_184 ;
if ( sscanf ( V_284 -> V_128 , L_19 , & V_286 , & V_184 ) != 2 )
continue;
if ( V_184 < 0x0a || V_184 >= 0x10 )
break;
V_2 -> V_276 = V_286 ;
V_2 -> V_279 = V_184 - 0x0a + 0x18 ;
V_2 -> V_78 . V_287 . V_288 = F_153 ;
V_2 -> V_78 . V_289 = 1 ;
V_8 -> V_290 = F_155 ;
F_30 ( L_20 , V_2 -> V_279 ,
V_2 -> V_276 ) ;
break;
}
}
static void F_158 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_276 = 0 ;
V_2 -> V_279 = 0x18 ;
V_2 -> V_78 . V_287 . V_288 = F_153 ;
V_2 -> V_78 . V_289 = 1 ;
V_8 -> V_290 = F_155 ;
}
}
static void F_159 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_276 = 0 ;
V_2 -> V_279 = 0x19 ;
V_2 -> V_78 . V_287 . V_288 = F_153 ;
V_2 -> V_78 . V_289 = 1 ;
V_8 -> V_290 = F_155 ;
}
}
static void F_160 ( void * V_273 , int V_274 )
{
struct V_7 * V_8 = V_273 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_291 = V_2 -> V_292 ;
if ( V_274 )
V_2 -> V_292 &= ~ 0x08 ;
else
V_2 -> V_292 |= 0x08 ;
if ( V_2 -> V_292 != V_291 )
F_5 ( V_8 , 0x01 , 0 , V_168 ,
V_2 -> V_292 ) ;
}
static void F_161 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_291 = V_2 -> V_292 ;
if ( ! V_118 )
return;
if ( V_118 -> V_28 . integer . V_28 [ 0 ] ||
V_118 -> V_28 . integer . V_28 [ 1 ] )
V_2 -> V_292 &= ~ 0x10 ;
else
V_2 -> V_292 |= 0x10 ;
if ( V_2 -> V_292 != V_291 )
F_5 ( V_8 , 0x01 , 0 , V_168 ,
V_2 -> V_292 ) ;
}
static void F_162 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_263 V_293 [] = {
{ 0x01 , V_193 , 0x18 } ,
{ 0x01 , V_194 , 0x18 } ,
{}
} ;
if ( V_48 == V_49 ) {
V_2 -> V_78 . V_287 . V_288 = F_160 ;
V_2 -> V_78 . V_122 = F_161 ;
V_2 -> V_292 = 0 ;
F_91 ( V_8 , V_293 ) ;
}
}
static void F_163 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x1b , 0x0c0b ) ;
F_126 ( V_8 , 0x45 , 0xd089 ) ;
V_9 = F_35 ( V_8 , 0x57 , 0x05 ) ;
F_36 ( V_8 , 0x57 , 0x05 , V_9 & ~ ( 1 << 14 ) ) ;
F_126 ( V_8 , 0x06 , 0x6104 ) ;
F_36 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x1b , 0x0c0b ) ;
F_126 ( V_8 , 0x45 , 0xc429 ) ;
V_9 = F_38 ( V_8 , 0x35 ) ;
F_126 ( V_8 , 0x35 , V_9 & 0xbfff ) ;
F_126 ( V_8 , 0x06 , 0x2104 ) ;
F_126 ( V_8 , 0x1a , 0x0001 ) ;
F_126 ( V_8 , 0x26 , 0x0004 ) ;
F_126 ( V_8 , 0x32 , 0x42a3 ) ;
break;
case 0x10ec0292 :
F_126 ( V_8 , 0x76 , 0x000e ) ;
F_126 ( V_8 , 0x6c , 0x2400 ) ;
F_126 ( V_8 , 0x18 , 0x7308 ) ;
F_126 ( V_8 , 0x6b , 0xc429 ) ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x15 , 0x0d40 ) ;
F_126 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_164 ( L_21 ) ;
}
static void F_165 ( struct V_7 * V_8 , T_1 V_252 ,
T_1 V_294 )
{
int V_9 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x45 , 0xc489 ) ;
F_154 ( V_8 , V_252 , 0 ) ;
F_36 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
F_126 ( V_8 , 0x06 , 0x6100 ) ;
F_154 ( V_8 , V_294 , V_295 ) ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x45 , 0xc429 ) ;
F_154 ( V_8 , V_252 , 0 ) ;
V_9 = F_38 ( V_8 , 0x35 ) ;
F_126 ( V_8 , 0x35 , V_9 | 1 << 14 ) ;
F_126 ( V_8 , 0x06 , 0x2100 ) ;
F_126 ( V_8 , 0x1a , 0x0021 ) ;
F_126 ( V_8 , 0x26 , 0x008c ) ;
F_154 ( V_8 , V_294 , V_295 ) ;
break;
case 0x10ec0292 :
F_154 ( V_8 , V_252 , 0 ) ;
F_126 ( V_8 , 0x19 , 0xa208 ) ;
F_126 ( V_8 , 0x2e , 0xacf0 ) ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x11 , 0x0001 ) ;
F_154 ( V_8 , V_252 , 0 ) ;
F_126 ( V_8 , 0xb7 , 0x802b ) ;
F_126 ( V_8 , 0xb5 , 0x1040 ) ;
V_9 = F_38 ( V_8 , 0xc3 ) ;
F_126 ( V_8 , 0xc3 , V_9 | 1 << 12 ) ;
F_154 ( V_8 , V_294 , V_295 ) ;
break;
}
F_164 ( L_22 ) ;
}
static void F_166 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x45 , 0xc089 ) ;
F_126 ( V_8 , 0x45 , 0xc489 ) ;
F_36 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
F_126 ( V_8 , 0x49 , 0x0049 ) ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x06 , 0x2100 ) ;
F_126 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_126 ( V_8 , 0x76 , 0x000e ) ;
F_126 ( V_8 , 0x6c , 0x2400 ) ;
F_126 ( V_8 , 0x6b , 0xc429 ) ;
F_126 ( V_8 , 0x18 , 0x7308 ) ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x11 , 0x0041 ) ;
F_126 ( V_8 , 0x15 , 0x0d40 ) ;
F_126 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_164 ( L_23 ) ;
}
static void F_167 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x45 , 0xd489 ) ;
F_126 ( V_8 , 0x1b , 0x0c2b ) ;
F_36 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x45 , 0xd429 ) ;
F_126 ( V_8 , 0x1b , 0x0c2b ) ;
F_126 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_126 ( V_8 , 0x6b , 0xd429 ) ;
F_126 ( V_8 , 0x76 , 0x0008 ) ;
F_126 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x11 , 0x0001 ) ;
F_126 ( V_8 , 0x15 , 0x0d60 ) ;
F_126 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_164 ( L_24 ) ;
}
static void F_168 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x45 , 0xe489 ) ;
F_126 ( V_8 , 0x1b , 0x0c2b ) ;
F_36 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x45 , 0xe429 ) ;
F_126 ( V_8 , 0x1b , 0x0c2b ) ;
F_126 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_126 ( V_8 , 0x6b , 0xe429 ) ;
F_126 ( V_8 , 0x76 , 0x0008 ) ;
F_126 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x11 , 0x0001 ) ;
F_126 ( V_8 , 0x15 , 0x0d50 ) ;
F_126 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_164 ( L_25 ) ;
}
static void F_169 ( struct V_7 * V_8 )
{
int V_9 ;
bool V_296 = false ;
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0255 :
F_126 ( V_8 , 0x45 , 0xd089 ) ;
F_126 ( V_8 , 0x49 , 0x0149 ) ;
F_22 ( 300 ) ;
V_9 = F_38 ( V_8 , 0x46 ) ;
V_296 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0283 :
F_126 ( V_8 , 0x45 , 0xd029 ) ;
F_22 ( 300 ) ;
V_9 = F_38 ( V_8 , 0x46 ) ;
V_296 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_126 ( V_8 , 0x6b , 0xd429 ) ;
F_22 ( 300 ) ;
V_9 = F_38 ( V_8 , 0x6c ) ;
V_296 = ( V_9 & 0x001c ) == 0x001c ;
break;
case 0x10ec0668 :
F_126 ( V_8 , 0x11 , 0x0001 ) ;
F_126 ( V_8 , 0xb7 , 0x802b ) ;
F_126 ( V_8 , 0x15 , 0x0d60 ) ;
F_126 ( V_8 , 0xc3 , 0x0c00 ) ;
F_22 ( 300 ) ;
V_9 = F_38 ( V_8 , 0xbe ) ;
V_296 = ( V_9 & 0x1c02 ) == 0x1c02 ;
break;
}
F_164 ( L_26 ,
V_296 ? L_27 : L_28 ) ;
V_2 -> V_297 = V_296 ? V_298 : V_299 ;
}
static void F_170 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_300 = V_2 -> V_78 . V_102 [ V_2 -> V_78 . V_117 [ 0 ] ] ;
T_1 V_252 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
int V_301 ;
if ( ! F_129 ( V_8 , V_252 ) )
V_301 = V_302 ;
else if ( V_300 == V_2 -> V_303 )
V_301 = V_304 ;
else if ( V_300 == V_2 -> V_305 )
V_301 = V_306 ;
else
V_301 = V_307 ;
if ( V_301 == V_2 -> V_308 ) {
F_149 ( V_8 ) ;
return;
}
switch ( V_301 ) {
case V_302 :
F_163 ( V_8 ) ;
V_2 -> V_78 . V_169 = false ;
break;
case V_304 :
if ( V_2 -> V_297 == V_309 )
F_169 ( V_8 ) ;
if ( V_2 -> V_297 == V_298 )
F_167 ( V_8 ) ;
else if ( V_2 -> V_297 == V_299 )
F_168 ( V_8 ) ;
V_2 -> V_78 . V_169 = true ;
break;
case V_306 :
F_165 ( V_8 , V_252 , V_2 -> V_305 ) ;
V_2 -> V_78 . V_169 = false ;
break;
case V_307 :
F_166 ( V_8 ) ;
V_2 -> V_78 . V_169 = true ;
break;
}
if ( V_301 != V_306 ) {
F_154 ( V_8 , V_252 ,
V_310 | V_311 ) ;
if ( V_2 -> V_305 )
F_154 ( V_8 , V_2 -> V_305 ,
V_312 ) ;
}
V_2 -> V_308 = V_301 ;
F_149 ( V_8 ) ;
}
static void F_171 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
F_170 ( V_8 ) ;
}
static void F_172 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_297 = V_309 ;
V_174 ( V_8 , V_20 ) ;
}
static void F_173 ( struct V_7 * V_8 )
{
int V_55 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_147 * V_148 = & V_2 -> V_78 . V_79 ;
for ( V_55 = 0 ; V_55 < V_148 -> V_313 ; V_55 ++ ) {
if ( V_148 -> V_314 [ V_55 ] . V_315 && ! V_2 -> V_303 )
V_2 -> V_303 = V_148 -> V_314 [ V_55 ] . V_184 ;
if ( V_148 -> V_314 [ V_55 ] . V_316 && ! V_2 -> V_305 )
V_2 -> V_305 = V_148 -> V_314 [ V_55 ] . V_184 ;
}
V_2 -> V_78 . V_122 = F_171 ;
V_2 -> V_78 . V_170 = F_170 ;
V_2 -> V_78 . V_272 = F_172 ;
}
static void F_174 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_48 ) {
case V_49 :
V_2 -> V_149 |= V_262 | V_317 ;
break;
case V_123 :
F_173 ( V_8 ) ;
break;
case V_132 :
V_2 -> V_308 = 0 ;
F_170 ( V_8 ) ;
break;
}
}
static void F_175 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_149 |= V_262 ;
}
else
F_174 ( V_8 , V_47 , V_48 ) ;
}
static void F_176 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
F_126 ( V_8 , 0x1b , 0x880b ) ;
F_126 ( V_8 , 0x45 , 0xd089 ) ;
F_126 ( V_8 , 0x1b , 0x080b ) ;
F_126 ( V_8 , 0x46 , 0x0004 ) ;
F_126 ( V_8 , 0x1b , 0x0c0b ) ;
F_22 ( 30 ) ;
}
F_174 ( V_8 , V_47 , V_48 ) ;
}
static void F_177 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
int V_9 ;
F_126 ( V_8 , 0xc4 , 0x8000 ) ;
V_9 = F_38 ( V_8 , 0xc2 ) ;
F_126 ( V_8 , 0xc2 , V_9 & 0xfe ) ;
F_154 ( V_8 , 0x18 , 0 ) ;
}
F_174 ( V_8 , V_47 , V_48 ) ;
}
static int F_178 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_147 * V_148 = & V_2 -> V_78 . V_79 ;
T_1 V_16 ;
unsigned int V_318 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_148 -> V_313 ; V_55 ++ ) {
if ( V_148 -> V_314 [ V_55 ] . type != V_319 )
continue;
V_16 = V_148 -> V_314 [ V_55 ] . V_184 ;
V_318 = F_28 ( V_8 , V_16 ) ;
if ( F_179 ( V_318 ) == V_320 )
continue;
return V_16 ;
}
return 0 ;
}
static void F_180 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
int V_294 = F_178 ( V_8 ) ;
int V_252 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
if ( F_2 ( ! V_294 || ! V_252 ) )
return;
F_181 ( V_8 , V_294 , V_252 ) ;
}
}
static void F_182 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_147 * V_148 = & V_2 -> V_78 . V_79 ;
int V_55 ;
if ( V_48 != V_123 )
return;
for ( V_55 = 0 ; V_55 < V_148 -> V_313 ; V_55 ++ ) {
T_1 V_16 = V_148 -> V_314 [ V_55 ] . V_184 ;
unsigned int V_318 ;
if ( V_148 -> V_314 [ V_55 ] . type != V_319 )
continue;
V_318 = F_28 ( V_8 , V_16 ) ;
if ( F_179 ( V_318 ) != V_320 )
continue;
F_117 ( V_8 , V_16 , V_163 ,
( 0x00 << V_224 ) |
( 0x01 << V_225 ) |
( 0x2f << V_226 ) |
( 0 << V_227 ) ) ;
}
}
static void F_183 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_270 ;
F_22 ( 200 ) ;
V_174 ( V_8 , V_20 ) ;
V_270 = V_2 -> V_78 . V_169 ? V_271 : 0 ;
F_22 ( 600 ) ;
F_5 ( V_8 , 0x19 , 0 , V_255 ,
V_270 ) ;
}
static void F_184 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_48 ) {
case V_49 :
F_185 ( V_8 , 0x03 , 0 ) ;
V_2 -> V_78 . V_150 = 0 ;
break;
case V_132 :
V_9 = F_38 ( V_8 , 0x1a ) ;
F_126 ( V_8 , 0x1a , V_9 | ( 1 << 4 ) ) ;
break;
}
}
static void F_186 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_48 ) {
case V_49 :
V_2 -> V_78 . V_272 = F_183 ;
break;
case V_132 :
V_9 = F_38 ( V_8 , 0x06 ) ;
F_126 ( V_8 , 0x06 , V_9 & ~ 0x000c ) ;
break;
}
}
static void F_187 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_149 ( V_8 ) ;
if ( F_129 ( V_8 , 0x1b ) )
V_2 -> V_78 . V_321 |= ( 1ULL << 0x14 ) ;
}
static void F_188 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_263 V_322 [] = {
{ 0x01 , V_193 , 0x04 } ,
{ 0x01 , V_194 , 0x04 } ,
{ 0x01 , V_168 , 0x04 } ,
{}
} ;
static const struct V_175 V_323 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_21 * V_22 ;
switch ( V_48 ) {
case V_49 :
F_91 ( V_8 , V_322 ) ;
F_93 ( V_8 , V_323 ) ;
V_2 -> V_78 . V_324 = 1 ;
V_2 -> V_78 . V_170 = F_187 ;
F_84 ( V_8 , 0x1b ,
V_173 ,
V_174 ) ;
break;
case V_130 :
V_22 = F_9 ( V_8 , L_29 ) ;
if ( V_22 )
strcpy ( V_22 -> V_325 . V_128 , L_30 ) ;
V_22 = F_9 ( V_8 , L_31 ) ;
if ( V_22 )
strcpy ( V_22 -> V_325 . V_128 , L_29 ) ;
break;
}
}
static void F_189 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 )
F_185 ( V_8 , 0x03 , 0 ) ;
}
static T_2 F_190 ( T_3 V_326 , T_4 V_327 , void * V_328 ,
void * * V_329 )
{
bool * V_330 = V_328 ;
* V_330 = true ;
return V_331 ;
}
static bool F_191 ( struct V_7 * V_8 )
{
bool V_330 = false ;
if ( V_8 -> V_58 >> 16 != 0x17aa )
return false ;
if ( F_192 ( F_193 ( L_32 , F_190 , & V_330 , NULL ) ) && V_330 )
return true ;
V_330 = false ;
return F_192 ( F_193 ( L_33 , F_190 , & V_330 , NULL ) ) && V_330 ;
}
static void F_194 ( void * V_273 , int V_274 )
{
if ( V_332 )
V_332 ( V_333 , ! V_274 ) ;
}
static void F_195 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
if ( ! V_118 || ! V_332 )
return;
if ( strcmp ( L_34 , V_118 -> V_325 . V_128 ) == 0 && V_118 -> V_325 . V_334 == 0 ) {
bool V_9 = V_118 -> V_28 . integer . V_28 [ 0 ] || V_118 -> V_28 . integer . V_28 [ 1 ] ;
V_332 ( V_335 , ! V_9 ) ;
}
}
static void F_196 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_336 = false ;
if ( V_48 == V_123 ) {
if ( ! F_191 ( V_8 ) )
return;
if ( ! V_332 )
V_332 = F_197 ( V_337 ) ;
if ( ! V_332 ) {
F_198 ( V_338 L_35 ) ;
return;
}
V_336 = true ;
if ( V_332 ( V_333 , false ) >= 0 ) {
V_2 -> V_78 . V_287 . V_288 = F_194 ;
V_336 = false ;
}
if ( V_332 ( V_335 , false ) >= 0 ) {
if ( V_2 -> V_78 . V_115 > 1 )
F_164 ( L_36 ) ;
else {
V_2 -> V_78 . V_122 = F_195 ;
V_336 = false ;
}
}
}
if ( V_332 && ( V_48 == V_134 || V_336 ) ) {
F_199 ( V_337 ) ;
V_332 = NULL ;
}
}
static void F_196 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
}
static void F_200 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
if ( V_2 -> V_239 != V_245 )
return;
if ( ( F_37 ( V_8 ) & 0x00ff ) < 0x015 ) {
F_126 ( V_8 , 0xf , 0x960b ) ;
F_126 ( V_8 , 0xe , 0x8817 ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x016 ) {
F_126 ( V_8 , 0xf , 0x960b ) ;
F_126 ( V_8 , 0xe , 0x8814 ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x017 ) {
V_9 = F_38 ( V_8 , 0x04 ) ;
F_126 ( V_8 , 0x04 , V_9 | ( 1 << 11 ) ) ;
}
if ( ( F_37 ( V_8 ) & 0x00ff ) == 0x018 ) {
V_9 = F_38 ( V_8 , 0xd ) ;
if ( ( V_9 & 0x0c00 ) >> 10 != 0x1 ) {
F_126 ( V_8 , 0xd , V_9 | ( 1 << 10 ) ) ;
}
V_9 = F_38 ( V_8 , 0x17 ) ;
if ( ( V_9 & 0x01c0 ) >> 6 != 0x4 ) {
F_126 ( V_8 , 0x17 , V_9 | ( 1 << 7 ) ) ;
}
}
V_9 = F_38 ( V_8 , 0xd ) ;
F_126 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
V_9 = F_38 ( V_8 , 0x4 ) ;
F_126 ( V_8 , 0x4 , V_9 | ( 1 << 11 ) ) ;
}
static int F_201 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_213 = 0x18 ;
F_86 ( V_8 , V_339 ,
V_340 , V_341 ) ;
F_60 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_78 . V_158 = 0x01 ;
switch ( V_8 -> V_45 ) {
case 0x10ec0269 :
V_2 -> V_239 = V_240 ;
switch ( F_37 ( V_8 ) & 0x00f0 ) {
case 0x0010 :
if ( V_8 -> V_59 -> V_60 -> V_342 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 )
V_124 = F_72 ( V_8 , L_17 ) ;
V_2 -> V_239 = V_245 ;
break;
case 0x0020 :
if ( V_8 -> V_59 -> V_60 -> V_342 == 0x17aa &&
V_8 -> V_59 -> V_60 -> V_61 == 0x21f3 )
V_124 = F_72 ( V_8 , L_37 ) ;
V_2 -> V_239 = V_241 ;
break;
case 0x0030 :
V_2 -> V_239 = V_246 ;
break;
default:
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
}
if ( V_124 < 0 )
goto error;
V_2 -> V_131 = F_200 ;
F_200 ( V_8 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_2 -> V_239 = V_242 ;
break;
case 0x10ec0282 :
V_2 -> V_239 = V_247 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_2 -> V_239 = V_248 ;
V_2 -> V_133 = F_130 ;
V_2 -> V_131 = F_128 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_2 -> V_239 = V_243 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_2 -> V_239 = V_244 ;
break;
case 0x10ec0286 :
V_2 -> V_239 = V_249 ;
break;
case 0x10ec0255 :
V_2 -> V_239 = V_250 ;
break;
}
if ( F_6 ( V_8 , 0x51 , 0 , V_343 , 0 ) == 0x10ec5505 ) {
V_2 -> V_259 = true ;
V_2 -> V_131 = F_135 ;
}
V_124 = F_124 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 && V_2 -> V_78 . V_158 )
F_87 ( V_2 , 0x0b , 0x04 , V_163 ) ;
V_8 -> V_136 = V_164 ;
#ifdef F_202
V_8 -> V_136 . V_344 = F_137 ;
V_8 -> V_136 . V_345 = F_139 ;
#endif
if ( ! V_2 -> V_133 )
V_2 -> V_133 = F_127 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_203 ( struct V_7 * V_8 )
{
static const T_1 V_346 [] = { 0x1d , 0 } ;
static const T_1 V_347 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_77 ( V_8 , V_346 , V_347 ) ;
}
static void F_204 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( V_48 != V_132 )
return;
V_9 = F_104 ( V_8 , 0x0f ) ;
if ( ! ( V_9 & ( V_277 | V_310 ) ) )
V_9 |= V_277 ;
V_9 |= V_203 ;
F_105 ( V_8 , 0x0f , V_9 ) ;
V_2 -> V_78 . V_201 = 1 ;
}
static void F_205 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 )
V_8 -> V_348 = 1 ;
}
static int F_206 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x15 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_158 = 0x23 ;
F_86 ( V_8 , NULL , V_349 , V_350 ) ;
F_60 ( V_8 , V_49 ) ;
V_124 = F_203 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 )
F_87 ( V_2 , 0x23 , 0 , V_107 ) ;
V_8 -> V_136 = V_164 ;
#ifdef F_202
V_2 -> V_135 = F_66 ;
#endif
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_207 ( struct V_7 * V_8 )
{
static const T_1 V_351 [] = { 0x1d , 0 } ;
static const T_1 V_352 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_351 , V_352 ) ;
}
static void F_208 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
F_209 ( V_8 , 0x18 , 0x00000734 ) ;
F_209 ( V_8 , 0x19 , 0x0000073c ) ;
}
}
static int F_210 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_158 = 0x23 ;
F_86 ( V_8 , NULL , V_353 , V_354 ) ;
F_60 ( V_8 , V_49 ) ;
V_124 = F_207 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 )
F_87 ( V_2 , 0x0b , 0x05 , V_163 ) ;
V_8 -> V_136 = V_164 ;
V_2 -> V_133 = F_21 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_211 ( struct V_7 * V_8 )
{
static const T_1 V_355 [] = { 0x1d , 0 } ;
static const T_1 V_356 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_357 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_238 ;
if ( V_8 -> V_45 == 0x10ec0272 || V_8 -> V_45 == 0x10ec0663 ||
V_8 -> V_45 == 0x10ec0665 || V_8 -> V_45 == 0x10ec0670 ||
V_8 -> V_45 == 0x10ec0671 )
V_238 = V_356 ;
else
V_238 = V_357 ;
return F_77 ( V_8 , V_355 , V_238 ) ;
}
static void F_212 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_49 )
return;
if ( F_117 ( V_8 , 0x2 , V_107 ,
( 0x3b << V_224 ) |
( 0x3b << V_225 ) |
( 0x03 << V_226 ) |
( 0 << V_227 ) ) )
F_29 ( V_338
L_38 ) ;
}
static void F_213 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_130 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_358 [ 0 ] . V_359 [ 0 ] . V_360 = V_361 ;
}
}
static void F_214 ( struct V_7 * V_8 )
{
int V_9 , V_261 ;
V_261 = F_37 ( V_8 ) ;
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
if ( ( V_261 & 0x00f0 ) == 0x0030 ) {
V_9 = F_38 ( V_8 , 0x4 ) ;
F_126 ( V_8 , 0x4 , V_9 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_9 = F_38 ( V_8 , 0xd ) ;
F_126 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
break;
}
}
static int F_215 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_149 = V_260 ;
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
V_2 -> V_131 = F_214 ;
F_214 ( V_8 ) ;
F_86 ( V_8 , V_362 ,
V_363 , V_364 ) ;
F_60 ( V_8 , V_49 ) ;
F_27 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_78 . V_158 = 0x01 ;
if ( ( F_37 ( V_8 ) & ( 1 << 14 ) ) &&
V_8 -> V_59 -> V_60 -> V_342 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 ) {
V_124 = F_72 ( V_8 , L_39 ) ;
if ( V_124 < 0 )
goto error;
}
V_124 = F_211 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_162 && V_2 -> V_78 . V_158 ) {
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
F_87 ( V_2 , 0x0b , 0x05 , V_163 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_87 ( V_2 , 0x0b , 0x04 , V_163 ) ;
break;
case 0x10ec0273 :
F_87 ( V_2 , 0x0b , 0x03 , V_163 ) ;
break;
}
}
V_8 -> V_136 = V_164 ;
V_2 -> V_133 = F_21 ;
F_60 ( V_8 , V_123 ) ;
return 0 ;
error:
F_64 ( V_8 ) ;
return V_124 ;
}
static int F_216 ( struct V_7 * V_8 )
{
return F_77 ( V_8 , NULL , NULL ) ;
}
static int F_217 ( struct V_7 * V_8 )
{
int V_124 ;
V_124 = F_80 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_216 ( V_8 ) ;
if ( V_124 < 0 ) {
F_64 ( V_8 ) ;
return V_124 ;
}
V_8 -> V_136 = V_164 ;
return 0 ;
}
static int T_5 F_218 ( void )
{
return F_219 ( & V_365 ) ;
}
static void T_6 F_220 ( void )
{
F_221 ( & V_365 ) ;
}
