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
struct V_1 * V_2 = V_8 -> V_2 ;
F_20 ( V_8 , false ) ;
if ( ! V_2 -> V_38 )
F_22 ( 200 ) ;
F_23 ( V_8 ) ;
}
static void F_24 ( struct V_7 * V_8 , int type )
{
unsigned int V_31 ;
F_20 ( V_8 , true ) ;
switch ( type ) {
case V_39 :
F_25 ( V_8 , V_40 ) ;
break;
case V_41 :
F_25 ( V_8 , V_42 ) ;
break;
case V_43 :
F_25 ( V_8 , V_44 ) ;
break;
case V_45 :
switch ( V_8 -> V_46 ) {
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
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_51 . V_52 = 1 ;
V_2 -> V_51 . V_53 = V_54 ;
}
}
static void F_27 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 ) {
V_2 -> V_38 = 1 ;
V_8 -> V_56 = 0 ;
}
}
static int F_28 ( struct V_7 * V_8 )
{
unsigned int V_57 , V_31 , V_58 ;
unsigned V_16 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_51 . V_59 = 1 ;
if ( V_2 -> V_51 . V_52 ) {
V_57 = V_2 -> V_51 . V_53 ;
if ( V_57 == V_54 )
return - 1 ;
goto V_60;
}
V_57 = V_8 -> V_61 & 0xffff ;
if ( V_57 != V_8 -> V_62 -> V_63 -> V_64 && ( V_57 & 1 ) )
goto V_60;
V_16 = 0x1d ;
if ( V_8 -> V_46 == 0x10ec0260 )
V_16 = 0x17 ;
V_57 = F_29 ( V_8 , V_16 ) ;
if ( ! ( V_57 & 1 ) ) {
F_30 ( V_65 L_2 ,
V_8 -> V_66 , V_57 ) ;
return - 1 ;
}
V_31 = 0 ;
for ( V_58 = 1 ; V_58 < 16 ; V_58 ++ ) {
if ( ( V_57 >> V_58 ) & 1 )
V_31 ++ ;
}
if ( ( ( V_57 >> 16 ) & 0xf ) != V_31 )
return - 1 ;
V_2 -> V_51 . V_67 = V_57 >> 30 ;
V_2 -> V_51 . V_59 = ( V_57 & 0x100000 ) >> 20 ;
V_2 -> V_51 . V_68 = ( V_57 >> 16 ) & 0xf ;
V_2 -> V_51 . V_69 = V_57 >> 8 ;
V_60:
V_2 -> V_51 . V_53 = V_57 ;
V_2 -> V_51 . V_70 = ( V_57 & 0x38 ) >> 3 ;
V_2 -> V_51 . V_71 = ( V_57 & 0x4 ) >> 2 ;
V_2 -> V_51 . V_72 = ( V_57 & 0x2 ) >> 1 ;
V_2 -> V_51 . V_73 = V_57 & 0x1 ;
F_31 ( L_3 ,
V_16 , V_2 -> V_51 . V_53 ) ;
F_31 ( L_4 ,
V_2 -> V_51 . V_67 ) ;
F_31 ( L_5 , V_2 -> V_51 . V_59 ) ;
F_31 ( L_6 , V_2 -> V_51 . V_68 ) ;
F_31 ( L_7 , V_2 -> V_51 . V_69 ) ;
F_31 ( L_8 , V_2 -> V_51 . V_70 ) ;
F_31 ( L_9 , V_2 -> V_51 . V_71 ) ;
F_31 ( L_10 , V_2 -> V_51 . V_72 ) ;
F_31 ( L_11 , V_2 -> V_51 . V_73 ) ;
return 0 ;
}
static int F_32 ( T_1 V_16 , const T_1 * V_74 , int V_75 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_75 ; V_58 ++ )
if ( V_74 [ V_58 ] == V_16 )
return V_58 ;
return - 1 ;
}
static bool F_33 ( T_1 V_16 , const T_1 * V_74 , int V_75 )
{
return F_32 ( V_16 , V_74 , V_75 ) >= 0 ;
}
static int F_34 ( struct V_7 * V_8 , const T_1 * V_76 )
{
unsigned int V_57 , V_31 , V_58 ;
unsigned V_16 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_51 . V_52 ) {
V_57 = V_2 -> V_51 . V_53 ;
if ( V_57 == V_54 )
return 0 ;
goto V_60;
}
V_57 = V_8 -> V_61 & 0xffff ;
if ( ( V_57 != V_8 -> V_62 -> V_63 -> V_64 ) && ( V_57 & 1 ) )
goto V_60;
V_16 = 0x1d ;
if ( V_8 -> V_46 == 0x10ec0260 )
V_16 = 0x17 ;
V_57 = F_29 ( V_8 , V_16 ) ;
F_31 ( L_12
L_13 ,
V_57 , V_16 ) ;
if ( ! ( V_57 & 1 ) )
return 0 ;
if ( ( V_57 >> 30 ) != 1 )
return 0 ;
V_31 = 0 ;
for ( V_58 = 1 ; V_58 < 16 ; V_58 ++ ) {
if ( ( V_57 >> V_58 ) & 1 )
V_31 ++ ;
}
if ( ( ( V_57 >> 16 ) & 0xf ) != V_31 )
return 0 ;
V_60:
F_31 ( L_14 ,
V_57 & 0xffff , V_8 -> V_46 ) ;
V_31 = ( V_57 & 0x38 ) >> 3 ;
switch ( V_31 ) {
case 1 :
V_2 -> V_77 = V_39 ;
break;
case 3 :
V_2 -> V_77 = V_41 ;
break;
case 7 :
V_2 -> V_77 = V_43 ;
break;
case 5 :
default:
V_2 -> V_77 = V_45 ;
break;
}
if ( ! ( V_57 & 0x8000 ) )
return 1 ;
if ( ! V_2 -> V_78 . V_79 . V_80 [ 0 ] &&
! ( V_2 -> V_78 . V_79 . V_81 [ 0 ] &&
V_2 -> V_78 . V_79 . V_82 == V_83 ) ) {
T_1 V_16 ;
V_31 = ( V_57 >> 11 ) & 0x3 ;
V_16 = V_76 [ V_31 ] ;
if ( F_33 ( V_16 , V_2 -> V_78 . V_79 . V_81 ,
V_2 -> V_78 . V_79 . V_84 ) )
return 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = V_16 ;
}
return 1 ;
}
static void F_35 ( struct V_7 * V_8 , const T_1 * V_76 )
{
if ( ! F_34 ( V_8 , V_76 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
F_31 ( L_15
L_16 ) ;
V_2 -> V_77 = V_45 ;
}
}
static int F_36 ( struct V_7 * V_8 ,
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
static void F_37 ( struct V_7 * V_8 , T_1 V_16 ,
unsigned int V_17 ,
unsigned int V_85 )
{
F_5 ( V_8 , V_16 , 0 , V_11 ,
V_17 ) ;
F_5 ( V_8 , V_16 , 0 , V_14 ,
V_85 ) ;
}
static unsigned int F_38 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_86 )
V_2 -> V_86 = F_39 ( V_8 , 0 ) ;
return V_2 -> V_86 ;
}
static T_1 F_40 ( struct V_7 * V_8 , int V_87 , int V_88 )
{
struct V_89 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_90 )
V_87 = V_2 -> V_91 [ V_88 ] ;
return V_2 -> V_92 [ V_87 ] ;
}
static void F_41 ( struct V_7 * V_8 , int V_87 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_78 . V_95 ;
struct V_96 * V_97 ;
T_1 V_16 ;
int V_58 , V_98 , V_99 ;
unsigned int V_9 ;
for ( V_58 = 0 ; V_58 < V_94 -> V_100 ; V_58 ++ ) {
if ( V_2 -> V_78 . V_101 [ V_58 ] == V_2 -> V_102 )
break;
}
if ( V_58 >= V_94 -> V_100 )
return;
V_97 = F_42 ( V_8 , V_2 -> V_102 ,
F_40 ( V_8 , V_87 , V_58 ) ) ;
V_9 = V_97 -> V_103 [ V_104 ] ;
if ( ! V_9 )
return;
V_16 = F_43 ( V_9 ) ;
V_98 = F_44 ( V_9 ) ;
V_99 = V_105 |
( V_98 == V_106 ? V_107 : V_108 ) ;
F_45 ( V_8 ) ;
V_9 = F_46 ( V_8 , V_16 , 1 , V_98 , 0 ) ;
if ( V_9 & 0x80 )
return;
V_9 |= 0x80 ;
F_5 ( V_8 , V_16 , 0 , V_109 ,
V_99 | V_9 ) ;
}
static void F_47 ( struct V_7 * V_8 , bool V_110 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_111 , V_75 ;
if ( ! V_2 -> V_112 )
return;
if ( ! V_2 -> V_113 && ! V_110 )
return;
V_75 = V_2 -> V_78 . V_90 ? 1 : V_2 -> V_78 . V_114 ;
for ( V_111 = 0 ; V_111 < V_75 ; V_111 ++ ) {
bool V_115 = false ;
if ( V_2 -> V_113 &&
V_2 -> V_78 . V_101 [ V_2 -> V_78 . V_116 [ V_111 ] ] == V_2 -> V_102 )
V_115 = true ;
if ( ! V_115 && ! V_110 )
continue;
F_41 ( V_8 , V_111 ) ;
}
}
static void F_48 ( struct V_7 * V_8 ,
struct V_21 * V_117 ,
struct V_23 * V_118 )
{
F_47 ( V_8 , false ) ;
}
static int F_49 ( struct V_21 * V_117 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_50 ( V_117 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_118 -> V_28 . integer . V_28 [ 0 ] = ! V_2 -> V_113 ;
return 0 ;
}
static int F_51 ( struct V_21 * V_117 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_50 ( V_117 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 = ! V_118 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_9 == V_2 -> V_113 )
return 0 ;
V_2 -> V_113 = V_9 ;
F_47 ( V_8 , true ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_53 ( & V_2 -> V_78 , NULL , & V_119 ) )
return - V_120 ;
V_2 -> V_112 = 1 ;
V_2 -> V_113 = 0 ;
V_2 -> V_102 = V_16 ;
V_2 -> V_78 . V_121 = F_48 ;
return 0 ;
}
static void F_54 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_55 )
F_52 ( V_8 , 0x12 ) ;
}
static int F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_58 , V_122 ;
V_122 = F_56 ( V_8 ) ;
if ( V_122 < 0 )
return V_122 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_5 ; V_58 ++ ) {
V_122 = F_57 ( V_8 , V_2 -> V_6 [ V_58 ] ) ;
if ( V_122 < 0 )
return V_122 ;
}
#ifdef F_58
if ( V_2 -> V_123 ) {
const struct V_3 * V_124 ;
for ( V_124 = V_125 ; V_124 -> V_126 ; V_124 ++ ) {
struct V_21 * V_22 ;
V_22 = F_59 ( V_124 , V_8 ) ;
if ( ! V_22 )
return - V_120 ;
V_22 -> V_127 = V_2 -> V_123 ;
V_122 = F_60 ( V_8 , 0 , V_22 ) ;
if ( V_122 < 0 )
return V_122 ;
}
}
#endif
F_61 ( V_8 , V_128 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_129 )
V_2 -> V_129 ( V_8 ) ;
F_4 ( V_8 ) ;
F_24 ( V_8 , V_2 -> V_77 ) ;
F_63 ( V_8 ) ;
F_61 ( V_8 , V_130 ) ;
return 0 ;
}
static inline void F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 && V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
else
F_23 ( V_8 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
F_61 ( V_8 , V_132 ) ;
F_66 ( V_8 ) ;
}
static void F_67 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
}
static int F_68 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_64 ( V_8 ) ;
if ( V_2 && V_2 -> V_133 )
V_2 -> V_133 ( V_8 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_38 )
F_22 ( 150 ) ;
V_8 -> V_134 . V_135 ( V_8 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
F_47 ( V_8 , true ) ;
F_72 ( V_8 , 0x01 ) ;
return 0 ;
}
static int F_73 ( struct V_7 * V_8 , const char * V_126 )
{
F_11 ( V_8 -> V_66 ) ;
V_8 -> V_66 = F_74 ( V_126 , V_25 ) ;
if ( ! V_8 -> V_66 ) {
F_65 ( V_8 ) ;
return - V_120 ;
}
return 0 ;
}
static int F_75 ( struct V_7 * V_8 )
{
const struct V_136 * V_37 ;
const struct V_137 * V_138 ;
for ( V_37 = V_139 ; V_37 -> V_46 ; V_37 ++ ) {
if ( V_37 -> V_46 != V_8 -> V_46 )
continue;
if ( ( F_38 ( V_8 ) & V_37 -> V_140 ) == V_37 -> V_141 )
return F_73 ( V_8 , V_37 -> V_126 ) ;
}
for ( V_138 = V_142 ; V_138 -> V_143 ; V_138 ++ ) {
if ( V_138 -> V_143 != V_8 -> V_46 )
continue;
if ( V_138 -> V_144 != V_8 -> V_62 -> V_63 -> V_145 )
continue;
if ( ! V_138 -> V_146 ||
V_138 -> V_146 == V_8 -> V_62 -> V_63 -> V_64 )
return F_73 ( V_8 , V_138 -> V_126 ) ;
}
return 0 ;
}
static inline int F_76 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_147 * V_138 ;
V_138 = F_77 ( V_8 -> V_62 -> V_63 , V_148 ) ;
if ( V_138 )
return V_138 -> V_28 ;
return V_2 -> V_51 . V_59 ;
}
static int F_78 ( struct V_7 * V_8 ,
const T_1 * V_149 ,
const T_1 * V_150 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_151 * V_152 = & V_2 -> V_78 . V_79 ;
int V_122 ;
V_122 = F_79 ( V_8 , V_152 , V_149 ,
V_2 -> V_153 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( V_150 )
F_35 ( V_8 , V_150 ) ;
V_122 = F_80 ( V_8 , V_152 ) ;
if ( V_122 < 0 )
return V_122 ;
return 1 ;
}
static int F_81 ( struct V_7 * V_8 , T_1 V_154 )
{
struct V_1 * V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
int V_122 ;
if ( ! V_2 )
return - V_120 ;
V_8 -> V_2 = V_2 ;
F_82 ( & V_2 -> V_78 ) ;
V_2 -> V_78 . V_154 = V_154 ;
V_2 -> V_78 . V_155 = 1 ;
V_8 -> V_156 = 1 ;
V_8 -> V_157 = 1 ;
V_122 = F_75 ( V_8 ) ;
if ( V_122 < 0 ) {
F_11 ( V_2 ) ;
return V_122 ;
}
return 0 ;
}
static int F_83 ( struct V_7 * V_8 )
{
static const T_1 V_158 [] = { 0x1d , 0 } ;
static const T_1 V_159 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_78 ( V_8 , V_158 , V_159 ) ;
}
static void F_84 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_55 )
F_85 ( V_8 , 0x21 , V_160 , F_8 ) ;
}
static int F_86 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_161 = 1 ;
V_2 -> V_78 . V_162 = 0x01 ;
F_87 ( V_8 , V_163 , V_164 ,
V_165 ) ;
F_61 ( V_8 , V_50 ) ;
V_122 = F_83 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 )
F_88 ( V_2 , 0x0b , 0x05 , V_167 ) ;
V_8 -> V_134 = V_168 ;
V_8 -> V_134 . V_169 = F_12 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_89 ( struct V_7 * V_8 )
{
static const T_1 V_170 [] = { 0x17 , 0 } ;
static const T_1 V_171 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_78 ( V_8 , V_170 , V_171 ) ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_8 , 0x01 , 0 , V_172 ,
V_2 -> V_78 . V_173 ) ;
}
static void F_91 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 ) {
V_2 -> V_78 . V_174 = F_90 ;
V_2 -> V_78 . V_175 = 1 ;
V_2 -> V_78 . V_176 = 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = 0x0f ;
F_85 ( V_8 , 0x0f , V_177 ,
V_178 ) ;
F_92 ( V_8 , V_40 ) ;
}
}
static void F_93 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_179 V_180 [] = {
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
switch ( V_49 ) {
case V_50 :
F_94 ( V_8 , V_180 ) ;
break;
case V_55 :
V_2 -> V_77 = V_181 ;
break;
}
}
static void F_95 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 )
V_2 -> V_77 = V_181 ;
}
static void F_96 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_78 . V_182 = 1 ;
V_2 -> V_78 . V_183 = 1 ;
}
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x07 ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_184 = 1 ;
V_2 -> V_78 . V_162 = 0x01 ;
F_87 ( V_8 , V_185 , V_186 ,
V_187 ) ;
F_61 ( V_8 , V_50 ) ;
V_122 = F_89 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 )
F_88 ( V_2 , 0x07 , 0x05 , V_167 ) ;
V_8 -> V_134 = V_168 ;
V_2 -> V_131 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static void F_98 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_130 )
return;
F_15 ( V_8 ) ;
}
static void F_99 ( struct V_7 * V_8 , int V_188 , int V_189 )
{
unsigned int V_190 , V_191 , V_192 ;
V_190 = F_6 ( V_8 , V_8 -> V_193 , 0 ,
V_194 , 0 ) ;
if ( ! V_189 )
V_190 |= ( 1 << V_188 ) ;
else
V_190 &= ~ ( 1 << V_188 ) ;
V_191 = F_6 ( V_8 , V_8 -> V_193 , 0 ,
V_195 , 0 ) ;
V_191 |= ( 1 << V_188 ) ;
V_192 = F_6 ( V_8 , V_8 -> V_193 , 0 ,
V_196 , 0 ) ;
V_192 |= ( 1 << V_188 ) ;
F_5 ( V_8 , V_8 -> V_193 , 0 ,
V_197 , V_191 ) ;
F_5 ( V_8 , V_8 -> V_193 , 0 ,
V_198 , V_192 ) ;
F_22 ( 1 ) ;
F_5 ( V_8 , V_8 -> V_193 , 0 ,
V_172 , V_190 ) ;
}
static void F_100 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_130 )
return;
F_99 ( V_8 , 0 , 0 ) ;
F_99 ( V_8 , 1 , 0 ) ;
}
static void F_101 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
T_1 V_199 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_200 [ 2 ] = { 0x0e , 0x0f } ;
F_102 ( V_8 , 0x14 , 2 , V_199 ) ;
F_102 ( V_8 , 0x15 , 2 , V_199 ) ;
F_102 ( V_8 , 0x18 , 2 , V_200 ) ;
F_102 ( V_8 , 0x1a , 2 , V_200 ) ;
} else if ( V_49 == V_55 ) {
T_1 V_201 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_102 ( V_8 , 0x14 , 5 , V_201 ) ;
F_102 ( V_8 , 0x15 , 5 , V_201 ) ;
F_102 ( V_8 , 0x18 , 5 , V_201 ) ;
F_102 ( V_8 , 0x1a , 5 , V_201 ) ;
}
}
static void F_103 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_202 [ 2 ] = { 0x14 , 0x15 } ;
int V_58 ;
if ( V_49 != V_130 )
return;
for ( V_58 = 0 ; V_58 < F_3 ( V_202 ) ; V_58 ++ ) {
unsigned int V_9 = F_29 ( V_8 , V_202 [ V_58 ] ) ;
if ( F_104 ( V_9 ) != V_203 )
continue;
V_9 = F_105 ( V_8 , V_202 [ V_58 ] ) ;
V_9 |= V_204 ;
F_106 ( V_8 , V_202 [ V_58 ] , V_9 ) ;
V_2 -> V_78 . V_205 = 1 ;
break;
}
}
static void F_107 ( struct V_7 * V_8 ,
const T_1 * V_202 , int V_206 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_206 ; V_58 ++ ) {
unsigned int V_9 ;
V_9 = F_105 ( V_8 , V_202 [ V_58 ] ) ;
V_9 |= V_207 ;
F_106 ( V_8 , V_202 [ V_58 ] , V_9 ) ;
}
V_2 -> V_78 . V_205 = 1 ;
}
static void F_108 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_202 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_49 == V_130 )
F_107 ( V_8 , V_202 , F_3 ( V_202 ) ) ;
}
static void F_109 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_202 [ 1 ] = { 0x18 } ;
if ( V_49 == V_130 )
F_107 ( V_8 , V_202 , F_3 ( V_202 ) ) ;
}
static void F_110 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_202 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_49 == V_130 )
F_107 ( V_8 , V_202 , F_3 ( V_202 ) ) ;
}
static void F_111 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_78 . V_208 = 1 ;
V_2 -> V_78 . V_209 = 1 ;
}
}
static int F_112 ( struct V_7 * V_8 )
{
static const T_1 V_210 [] = { 0x1d , 0 } ;
static const T_1 V_211 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_78 ( V_8 , V_210 , V_211 ) ;
}
static int F_113 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_7 ( V_8 , 0x20 , 0x0a , 10 ) ;
break;
}
F_87 ( V_8 , V_212 , V_213 ,
V_214 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_76 ( V_8 ) )
V_2 -> V_78 . V_162 = 0x01 ;
V_122 = F_112 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 && V_2 -> V_78 . V_162 )
F_88 ( V_2 , 0x0b , 0x05 , V_167 ) ;
V_8 -> V_134 = V_168 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_114 ( struct V_7 * V_8 )
{
static const T_1 V_215 [] = { 0x1d , 0 } ;
static const T_1 V_216 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_78 ( V_8 , V_215 , V_216 ) ;
}
static int F_115 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_217 = 0x18 ;
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
F_87 ( V_8 , V_218 , V_219 ,
V_220 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_76 ( V_8 ) )
V_2 -> V_78 . V_162 = 0x01 ;
V_122 = F_114 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 && V_2 -> V_78 . V_162 )
F_88 ( V_2 , 0x0b , 0x05 , V_167 ) ;
V_8 -> V_134 = V_168 ;
V_2 -> V_131 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_116 ( struct V_7 * V_8 )
{
static const T_1 V_221 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_78 ( V_8 , NULL , V_221 ) ;
}
static int F_117 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0 ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_162 = 0x01 ;
F_87 ( V_8 , V_222 , V_223 , V_224 ) ;
F_61 ( V_8 , V_50 ) ;
V_122 = F_116 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( V_122 > 0 && ! V_2 -> V_78 . V_166 &&
V_2 -> V_78 . V_79 . V_225 [ 0 ] != 0x1d ) {
F_1 ( V_2 , V_226 ) ;
F_92 ( V_8 , V_227 ) ;
if ( ! F_118 ( V_8 , 0x1d , V_167 ) )
F_119 ( V_8 , 0x1d , V_167 ,
( 0x0c << V_228 ) |
( 0x0c << V_229 ) |
( 0x07 << V_230 ) |
( 0 << V_231 ) ) ;
}
V_8 -> V_134 = V_168 ;
V_2 -> V_131 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_120 ( struct V_232 * V_233 ,
struct V_7 * V_8 ,
struct V_234 * V_235 )
{
struct V_89 * V_2 = V_8 -> V_2 ;
return F_121 ( V_8 , & V_2 -> V_236 , V_235 ,
V_233 ) ;
}
static int F_122 ( struct V_232 * V_233 ,
struct V_7 * V_8 ,
unsigned int V_237 ,
unsigned int V_238 ,
struct V_234 * V_235 )
{
struct V_89 * V_2 = V_8 -> V_2 ;
return F_123 ( V_8 , & V_2 -> V_236 ,
V_237 , V_238 , V_235 ) ;
}
static int F_124 ( struct V_232 * V_233 ,
struct V_7 * V_8 ,
struct V_234 * V_235 )
{
struct V_89 * V_2 = V_8 -> V_2 ;
return F_125 ( V_8 , & V_2 -> V_236 ) ;
}
static int F_126 ( struct V_7 * V_8 )
{
static const T_1 V_239 [] = { 0x1d , 0 } ;
static const T_1 V_240 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_241 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
const T_1 * V_242 ;
switch ( V_2 -> V_243 ) {
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_242 = V_241 ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_242 = V_240 ;
break;
default:
V_242 = V_240 ;
break;
}
return F_78 ( V_8 , V_239 , V_242 ) ;
}
static void F_127 ( struct V_7 * V_8 , int V_255 )
{
int V_9 = F_39 ( V_8 , 0x04 ) ;
if ( V_255 )
V_9 |= 1 << 11 ;
else
V_9 &= ~ ( 1 << 11 ) ;
F_128 ( V_8 , 0x04 , V_9 ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_243 == V_249 )
F_127 ( V_8 , 0 ) ;
if ( V_2 -> V_243 == V_249 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
F_23 ( V_8 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_256 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_257 ;
int V_9 ;
if ( ! V_256 )
return;
V_257 = F_131 ( V_8 , V_256 ) ;
F_128 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_256 , 0 ,
V_109 , V_258 ) ;
if ( V_257 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_256 , 0 ,
V_259 , V_260 ) ;
if ( V_257 )
F_22 ( 85 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
F_128 ( V_8 , 0x46 , V_9 & ~ ( 3 << 12 ) ) ;
F_128 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_256 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
bool V_257 ;
int V_9 ;
if ( ! V_256 ) {
F_129 ( V_8 ) ;
return;
}
V_257 = F_131 ( V_8 , V_256 ) ;
F_128 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_256 , 0 ,
V_109 , V_258 ) ;
if ( V_257 )
F_22 ( 100 ) ;
F_5 ( V_8 , V_256 , 0 ,
V_259 , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
F_128 ( V_8 , 0x46 , V_9 | ( 3 << 12 ) ) ;
if ( V_257 )
F_22 ( 100 ) ;
F_23 ( V_8 ) ;
F_128 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_133 ( struct V_7 * V_8 , unsigned int V_261 ,
unsigned int V_9 )
{
F_5 ( V_8 , 0x51 , 0 , V_11 , V_261 >> 1 ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 & 0xffff ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 >> 16 ) ;
}
static int F_134 ( struct V_7 * V_8 , unsigned int V_261 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x51 , 0 , V_11 , V_261 >> 1 ) ;
V_9 = F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
& 0xffff ;
V_9 |= F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
<< 16 ;
return V_9 ;
}
static void F_135 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_133 ( V_8 , 0x3000 , 0x000c ) ;
F_133 ( V_8 , 0x880c , 0x0008 ) ;
F_133 ( V_8 , 0x61c0 , 0x11110080 ) ;
F_133 ( V_8 , 0x6230 , 0xfc0d4011 ) ;
F_133 ( V_8 , 0x61b4 , 0x040a2b03 ) ;
F_133 ( V_8 , 0x61b0 , 0x00005b17 ) ;
F_133 ( V_8 , 0x61b8 , 0x04133303 ) ;
V_9 = F_134 ( V_8 , 0x6220 ) ;
F_133 ( V_8 , 0x6220 , ( V_9 | 0x3000 ) ) ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_133 ( V_8 , 0x61b8 , 0x04133302 ) ;
F_133 ( V_8 , 0x61b0 , 0x00005b16 ) ;
F_133 ( V_8 , 0x61b4 , 0x040a2b02 ) ;
F_133 ( V_8 , 0x6230 , 0xf80d4011 ) ;
F_133 ( V_8 , 0x6220 , 0x2002010f ) ;
F_133 ( V_8 , 0x880c , 0x00000004 ) ;
}
static void F_137 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_135 ( V_8 ) ;
F_136 ( V_8 ) ;
F_133 ( V_8 , 0x61b0 , 0x5b14 ) ;
F_133 ( V_8 , 0x61b0 , 0x5b16 ) ;
F_133 ( V_8 , 0x61b4 , 0x04132b00 ) ;
F_133 ( V_8 , 0x61b4 , 0x04132b02 ) ;
F_133 ( V_8 , 0x61b8 , 0x041f3300 ) ;
F_133 ( V_8 , 0x61b8 , 0x041f3302 ) ;
F_5 ( V_8 , 0x51 , 0 , V_262 , 0 ) ;
F_133 ( V_8 , 0x61b8 , 0x041b3302 ) ;
F_133 ( V_8 , 0x61b8 , 0x04173302 ) ;
F_133 ( V_8 , 0x61b8 , 0x04163302 ) ;
F_133 ( V_8 , 0x8800 , 0x348b328b ) ;
F_133 ( V_8 , 0x8808 , 0x00020022 ) ;
F_133 ( V_8 , 0x8818 , 0x00000400 ) ;
V_9 = F_134 ( V_8 , 0x6200 ) >> 16 ;
if ( V_9 <= 3 )
F_133 ( V_8 , 0x6220 , 0x2002010f ) ;
else
F_133 ( V_8 , 0x6220 , 0x6002018f ) ;
F_133 ( V_8 , 0x61ac , 0x055525f0 ) ;
F_133 ( V_8 , 0x61c0 , 0x12230080 ) ;
F_133 ( V_8 , 0x61b4 , 0x040e2b02 ) ;
F_133 ( V_8 , 0x61bc , 0x010234f8 ) ;
F_133 ( V_8 , 0x880c , 0x00000004 ) ;
F_133 ( V_8 , 0x880c , 0x00000003 ) ;
F_133 ( V_8 , 0x880c , 0x00000010 ) ;
#ifdef F_138
F_135 ( V_8 ) ;
#endif
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_263 )
F_140 ( V_8 ) ;
return F_68 ( V_8 ) ;
}
static int F_141 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_243 == V_249 )
F_127 ( V_8 , 0 ) ;
if ( V_2 -> V_243 == V_249 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
V_8 -> V_134 . V_135 ( V_8 ) ;
if ( V_2 -> V_243 == V_249 )
F_127 ( V_8 , 1 ) ;
if ( V_2 -> V_243 == V_249 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x017 ) {
F_22 ( 200 ) ;
}
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
F_47 ( V_8 , true ) ;
F_72 ( V_8 , 0x01 ) ;
if ( V_2 -> V_263 )
F_142 ( V_8 ) ;
return 0 ;
}
static void F_143 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 )
V_2 -> V_153 = V_264 ;
}
static void F_144 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
int V_265 ;
if ( V_49 != V_130 )
return;
V_265 = F_39 ( V_8 , 0x1e ) ;
F_128 ( V_8 , 0x1e , V_265 | 0x80 ) ;
}
static void F_145 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 )
V_2 -> V_153 |= V_266 ;
}
static void F_146 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static const struct V_267 V_268 [] = {
{ 0x20 , V_11 , 0x0d } ,
{ 0x20 , V_14 , 0x4000 } ,
{}
} ;
unsigned int V_152 ;
if ( strcmp ( V_8 -> V_66 , L_17 ) &&
strcmp ( V_8 -> V_66 , L_18 ) )
return;
V_152 = F_29 ( V_8 , 0x12 ) ;
if ( F_147 ( V_152 ) == V_269 )
F_25 ( V_8 , V_268 ) ;
}
static void F_148 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 != V_55 )
return;
V_2 -> V_78 . V_270 = & V_271 ;
V_2 -> V_78 . V_272 = & V_273 ;
}
static void F_149 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
int V_265 ;
if ( V_49 != V_130 )
return;
V_265 = F_39 ( V_8 , 0x07 ) ;
F_128 ( V_8 , 0x07 , V_265 | 0x80 ) ;
}
static void F_150 ( struct V_7 * V_8 )
{
F_151 ( V_8 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x680 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x480 ) ;
}
static void F_152 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 != V_55 )
return;
V_2 -> V_78 . V_174 = F_150 ;
}
static void F_153 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_274 ;
F_22 ( 200 ) ;
V_178 ( V_8 , V_20 ) ;
V_274 = V_2 -> V_78 . V_173 ? V_275 : 0 ;
F_22 ( 100 ) ;
F_5 ( V_8 , 0x18 , 0 , V_259 ,
V_274 ) ;
F_22 ( 500 ) ;
F_5 ( V_8 , 0x18 , 0 , V_259 ,
V_274 ) ;
}
static void F_154 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_153 |= V_266 ;
V_2 -> V_78 . V_276 = F_153 ;
}
}
static void F_155 ( void * V_277 , int V_278 )
{
struct V_7 * V_8 = V_277 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_279 ;
if ( V_2 -> V_280 )
V_278 = ! V_278 ;
V_279 = V_281 |
( V_278 ? V_282 : V_204 ) ;
if ( V_2 -> V_283 )
F_156 ( V_8 , V_2 -> V_283 , V_279 ) ;
}
static unsigned int F_157 ( struct V_7 * V_8 ,
T_1 V_16 ,
unsigned int V_284 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_284 != V_285 || V_16 != V_2 -> V_283 )
return V_284 ;
F_106 ( V_8 , V_16 ,
F_105 ( V_8 , V_16 ) ) ;
return V_286 ;
}
static void F_158 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_287 * V_288 = NULL ;
if ( V_49 != V_50 )
return;
while ( ( V_288 = F_159 ( V_289 , NULL , V_288 ) ) ) {
int V_290 , V_188 ;
if ( sscanf ( V_288 -> V_126 , L_19 , & V_290 , & V_188 ) != 2 )
continue;
if ( V_188 < 0x0a || V_188 >= 0x10 )
break;
V_2 -> V_280 = V_290 ;
V_2 -> V_283 = V_188 - 0x0a + 0x18 ;
V_2 -> V_78 . V_291 . V_292 = F_155 ;
V_2 -> V_78 . V_293 = 1 ;
V_8 -> V_294 = F_157 ;
F_31 ( L_20 , V_2 -> V_283 ,
V_2 -> V_280 ) ;
break;
}
}
static void F_160 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_280 = 0 ;
V_2 -> V_283 = 0x18 ;
V_2 -> V_78 . V_291 . V_292 = F_155 ;
V_2 -> V_78 . V_293 = 1 ;
V_8 -> V_294 = F_157 ;
}
}
static void F_161 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_280 = 0 ;
V_2 -> V_283 = 0x19 ;
V_2 -> V_78 . V_291 . V_292 = F_155 ;
V_2 -> V_78 . V_293 = 1 ;
V_8 -> V_294 = F_157 ;
}
}
static void F_162 ( void * V_277 , int V_278 )
{
struct V_7 * V_8 = V_277 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_295 = V_2 -> V_296 ;
if ( V_278 )
V_2 -> V_296 &= ~ 0x08 ;
else
V_2 -> V_296 |= 0x08 ;
if ( V_2 -> V_296 != V_295 )
F_5 ( V_8 , 0x01 , 0 , V_172 ,
V_2 -> V_296 ) ;
}
static void F_163 ( struct V_7 * V_8 ,
struct V_21 * V_117 ,
struct V_23 * V_118 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_295 = V_2 -> V_296 ;
if ( ! V_118 )
return;
if ( V_118 -> V_28 . integer . V_28 [ 0 ] ||
V_118 -> V_28 . integer . V_28 [ 1 ] )
V_2 -> V_296 &= ~ 0x10 ;
else
V_2 -> V_296 |= 0x10 ;
if ( V_2 -> V_296 != V_295 )
F_5 ( V_8 , 0x01 , 0 , V_172 ,
V_2 -> V_296 ) ;
}
static void F_164 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_267 V_297 [] = {
{ 0x01 , V_197 , 0x18 } ,
{ 0x01 , V_198 , 0x18 } ,
{}
} ;
if ( V_49 == V_50 ) {
V_2 -> V_78 . V_291 . V_292 = F_162 ;
V_2 -> V_78 . V_121 = F_163 ;
V_2 -> V_296 = 0 ;
F_92 ( V_8 , V_297 ) ;
}
}
static void F_165 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x1b , 0x0c0b ) ;
F_128 ( V_8 , 0x45 , 0xd089 ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x05 ) ;
F_37 ( V_8 , 0x57 , 0x05 , V_9 & ~ ( 1 << 14 ) ) ;
F_128 ( V_8 , 0x06 , 0x6104 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x1b , 0x0c0b ) ;
F_128 ( V_8 , 0x45 , 0xc429 ) ;
V_9 = F_39 ( V_8 , 0x35 ) ;
F_128 ( V_8 , 0x35 , V_9 & 0xbfff ) ;
F_128 ( V_8 , 0x06 , 0x2104 ) ;
F_128 ( V_8 , 0x1a , 0x0001 ) ;
F_128 ( V_8 , 0x26 , 0x0004 ) ;
F_128 ( V_8 , 0x32 , 0x42a3 ) ;
break;
case 0x10ec0292 :
F_128 ( V_8 , 0x76 , 0x000e ) ;
F_128 ( V_8 , 0x6c , 0x2400 ) ;
F_128 ( V_8 , 0x18 , 0x7308 ) ;
F_128 ( V_8 , 0x6b , 0xc429 ) ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x15 , 0x0d40 ) ;
F_128 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_166 ( L_21 ) ;
}
static void F_167 ( struct V_7 * V_8 , T_1 V_256 ,
T_1 V_298 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x45 , 0xc489 ) ;
F_156 ( V_8 , V_256 , 0 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
F_128 ( V_8 , 0x06 , 0x6100 ) ;
F_156 ( V_8 , V_298 , V_299 ) ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x45 , 0xc429 ) ;
F_156 ( V_8 , V_256 , 0 ) ;
V_9 = F_39 ( V_8 , 0x35 ) ;
F_128 ( V_8 , 0x35 , V_9 | 1 << 14 ) ;
F_128 ( V_8 , 0x06 , 0x2100 ) ;
F_128 ( V_8 , 0x1a , 0x0021 ) ;
F_128 ( V_8 , 0x26 , 0x008c ) ;
F_156 ( V_8 , V_298 , V_299 ) ;
break;
case 0x10ec0292 :
F_156 ( V_8 , V_256 , 0 ) ;
F_128 ( V_8 , 0x19 , 0xa208 ) ;
F_128 ( V_8 , 0x2e , 0xacf0 ) ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x11 , 0x0001 ) ;
F_156 ( V_8 , V_256 , 0 ) ;
F_128 ( V_8 , 0xb7 , 0x802b ) ;
F_128 ( V_8 , 0xb5 , 0x1040 ) ;
V_9 = F_39 ( V_8 , 0xc3 ) ;
F_128 ( V_8 , 0xc3 , V_9 | 1 << 12 ) ;
F_156 ( V_8 , V_298 , V_299 ) ;
break;
}
F_166 ( L_22 ) ;
}
static void F_168 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x45 , 0xc089 ) ;
F_128 ( V_8 , 0x45 , 0xc489 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
F_128 ( V_8 , 0x49 , 0x0049 ) ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x06 , 0x2100 ) ;
F_128 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_128 ( V_8 , 0x76 , 0x000e ) ;
F_128 ( V_8 , 0x6c , 0x2400 ) ;
F_128 ( V_8 , 0x6b , 0xc429 ) ;
F_128 ( V_8 , 0x18 , 0x7308 ) ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x11 , 0x0041 ) ;
F_128 ( V_8 , 0x15 , 0x0d40 ) ;
F_128 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_166 ( L_23 ) ;
}
static void F_169 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x45 , 0xd489 ) ;
F_128 ( V_8 , 0x1b , 0x0c2b ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x45 , 0xd429 ) ;
F_128 ( V_8 , 0x1b , 0x0c2b ) ;
F_128 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_128 ( V_8 , 0x6b , 0xd429 ) ;
F_128 ( V_8 , 0x76 , 0x0008 ) ;
F_128 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x11 , 0x0001 ) ;
F_128 ( V_8 , 0x15 , 0x0d60 ) ;
F_128 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_166 ( L_24 ) ;
}
static void F_170 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x45 , 0xe489 ) ;
F_128 ( V_8 , 0x1b , 0x0c2b ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x45 , 0xe429 ) ;
F_128 ( V_8 , 0x1b , 0x0c2b ) ;
F_128 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_128 ( V_8 , 0x6b , 0xe429 ) ;
F_128 ( V_8 , 0x76 , 0x0008 ) ;
F_128 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x11 , 0x0001 ) ;
F_128 ( V_8 , 0x15 , 0x0d50 ) ;
F_128 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_166 ( L_25 ) ;
}
static void F_171 ( struct V_7 * V_8 )
{
int V_9 ;
bool V_300 = false ;
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_128 ( V_8 , 0x45 , 0xd089 ) ;
F_128 ( V_8 , 0x49 , 0x0149 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
V_300 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0283 :
F_128 ( V_8 , 0x45 , 0xd029 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
V_300 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_128 ( V_8 , 0x6b , 0xd429 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x6c ) ;
V_300 = ( V_9 & 0x001c ) == 0x001c ;
break;
case 0x10ec0668 :
F_128 ( V_8 , 0x11 , 0x0001 ) ;
F_128 ( V_8 , 0xb7 , 0x802b ) ;
F_128 ( V_8 , 0x15 , 0x0d60 ) ;
F_128 ( V_8 , 0xc3 , 0x0c00 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0xbe ) ;
V_300 = ( V_9 & 0x1c02 ) == 0x1c02 ;
break;
}
F_166 ( L_26 ,
V_300 ? L_27 : L_28 ) ;
V_2 -> V_301 = V_300 ? V_302 : V_303 ;
}
static void F_172 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_304 = V_2 -> V_78 . V_101 [ V_2 -> V_78 . V_116 [ 0 ] ] ;
T_1 V_256 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
int V_305 ;
if ( ! F_131 ( V_8 , V_256 ) )
V_305 = V_306 ;
else if ( V_304 == V_2 -> V_307 )
V_305 = V_308 ;
else if ( V_304 == V_2 -> V_309 )
V_305 = V_310 ;
else
V_305 = V_311 ;
if ( V_305 == V_2 -> V_312 ) {
F_151 ( V_8 ) ;
return;
}
switch ( V_305 ) {
case V_306 :
F_165 ( V_8 ) ;
V_2 -> V_78 . V_173 = false ;
break;
case V_308 :
if ( V_2 -> V_301 == V_313 )
F_171 ( V_8 ) ;
if ( V_2 -> V_301 == V_302 )
F_169 ( V_8 ) ;
else if ( V_2 -> V_301 == V_303 )
F_170 ( V_8 ) ;
V_2 -> V_78 . V_173 = true ;
break;
case V_310 :
F_167 ( V_8 , V_256 , V_2 -> V_309 ) ;
V_2 -> V_78 . V_173 = false ;
break;
case V_311 :
F_168 ( V_8 ) ;
V_2 -> V_78 . V_173 = true ;
break;
}
if ( V_305 != V_310 ) {
F_156 ( V_8 , V_256 ,
V_314 | V_315 ) ;
if ( V_2 -> V_309 )
F_156 ( V_8 , V_2 -> V_309 ,
V_316 ) ;
}
V_2 -> V_312 = V_305 ;
F_151 ( V_8 ) ;
}
static void F_173 ( struct V_7 * V_8 ,
struct V_21 * V_117 ,
struct V_23 * V_118 )
{
F_172 ( V_8 ) ;
}
static void F_174 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_301 = V_313 ;
V_178 ( V_8 , V_20 ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
int V_58 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_151 * V_152 = & V_2 -> V_78 . V_79 ;
for ( V_58 = 0 ; V_58 < V_152 -> V_317 ; V_58 ++ ) {
if ( V_152 -> V_318 [ V_58 ] . V_319 && ! V_2 -> V_307 )
V_2 -> V_307 = V_152 -> V_318 [ V_58 ] . V_188 ;
if ( V_152 -> V_318 [ V_58 ] . V_320 && ! V_2 -> V_309 )
V_2 -> V_309 = V_152 -> V_318 [ V_58 ] . V_188 ;
}
V_2 -> V_78 . V_121 = F_173 ;
V_2 -> V_78 . V_174 = F_172 ;
V_2 -> V_78 . V_276 = F_174 ;
}
static void F_176 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_49 ) {
case V_50 :
V_2 -> V_153 |= V_266 | V_321 ;
break;
case V_55 :
F_175 ( V_8 ) ;
break;
case V_130 :
V_2 -> V_312 = 0 ;
F_172 ( V_8 ) ;
break;
}
}
static void F_177 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_153 |= V_266 ;
}
else
F_176 ( V_8 , V_48 , V_49 ) ;
}
static void F_178 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
F_128 ( V_8 , 0x1b , 0x880b ) ;
F_128 ( V_8 , 0x45 , 0xd089 ) ;
F_128 ( V_8 , 0x1b , 0x080b ) ;
F_128 ( V_8 , 0x46 , 0x0004 ) ;
F_128 ( V_8 , 0x1b , 0x0c0b ) ;
F_22 ( 30 ) ;
}
F_176 ( V_8 , V_48 , V_49 ) ;
}
static void F_179 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_322 = 1 ;
}
}
static void F_180 ( struct V_7 * V_8 )
{
}
static void F_181 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_131 = F_180 ;
}
}
static void F_182 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
int V_9 ;
F_128 ( V_8 , 0xc4 , 0x8000 ) ;
V_9 = F_39 ( V_8 , 0xc2 ) ;
F_128 ( V_8 , 0xc2 , V_9 & 0xfe ) ;
F_156 ( V_8 , 0x18 , 0 ) ;
}
F_176 ( V_8 , V_48 , V_49 ) ;
}
static int F_183 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_151 * V_152 = & V_2 -> V_78 . V_79 ;
T_1 V_16 ;
unsigned int V_323 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_152 -> V_317 ; V_58 ++ ) {
if ( V_152 -> V_318 [ V_58 ] . type != V_324 )
continue;
V_16 = V_152 -> V_318 [ V_58 ] . V_188 ;
V_323 = F_29 ( V_8 , V_16 ) ;
if ( F_184 ( V_323 ) == V_325 )
continue;
return V_16 ;
}
return 0 ;
}
static void F_185 ( struct V_7 * V_8 ,
const struct V_47 * V_48 ,
int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 ) {
int V_298 = F_183 ( V_8 ) ;
int V_256 = V_2 -> V_78 . V_79 . V_80 [ 0 ] ;
if ( F_2 ( ! V_298 || ! V_256 ) )
return;
F_186 ( V_8 , V_298 , V_256 ) ;
}
}
static void F_187 ( struct V_7 * V_8 ,
const struct V_47 * V_48 ,
int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_151 * V_152 = & V_2 -> V_78 . V_79 ;
int V_58 ;
if ( V_49 != V_55 )
return;
for ( V_58 = 0 ; V_58 < V_152 -> V_317 ; V_58 ++ ) {
T_1 V_16 = V_152 -> V_318 [ V_58 ] . V_188 ;
unsigned int V_323 ;
if ( V_152 -> V_318 [ V_58 ] . type != V_324 )
continue;
V_323 = F_29 ( V_8 , V_16 ) ;
if ( F_184 ( V_323 ) != V_325 )
continue;
F_119 ( V_8 , V_16 , V_167 ,
( 0x00 << V_228 ) |
( 0x01 << V_229 ) |
( 0x2f << V_230 ) |
( 0 << V_231 ) ) ;
}
}
static void F_188 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_274 ;
F_22 ( 200 ) ;
V_178 ( V_8 , V_20 ) ;
V_274 = V_2 -> V_78 . V_173 ? V_275 : 0 ;
F_22 ( 600 ) ;
F_5 ( V_8 , 0x19 , 0 , V_259 ,
V_274 ) ;
}
static void F_189 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_49 ) {
case V_50 :
F_190 ( V_8 , 0x03 , 0 ) ;
V_2 -> V_78 . V_154 = 0 ;
break;
case V_130 :
V_9 = F_39 ( V_8 , 0x1a ) ;
F_128 ( V_8 , 0x1a , V_9 | ( 1 << 4 ) ) ;
break;
}
}
static void F_191 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_49 ) {
case V_50 :
V_2 -> V_78 . V_276 = F_188 ;
break;
case V_130 :
V_9 = F_39 ( V_8 , 0x06 ) ;
F_128 ( V_8 , 0x06 , V_9 & ~ 0x000c ) ;
break;
}
}
static void F_192 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_151 ( V_8 ) ;
if ( F_131 ( V_8 , 0x1b ) )
V_2 -> V_78 . V_326 |= ( 1ULL << 0x14 ) ;
}
static void F_193 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_267 V_327 [] = {
{ 0x01 , V_197 , 0x04 } ,
{ 0x01 , V_198 , 0x04 } ,
{ 0x01 , V_172 , 0x04 } ,
{}
} ;
static const struct V_179 V_328 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_21 * V_22 ;
switch ( V_49 ) {
case V_50 :
F_92 ( V_8 , V_327 ) ;
F_94 ( V_8 , V_328 ) ;
V_2 -> V_78 . V_322 = 1 ;
V_2 -> V_78 . V_174 = F_192 ;
F_85 ( V_8 , 0x1b ,
V_177 ,
V_178 ) ;
break;
case V_128 :
V_22 = F_9 ( V_8 , L_29 ) ;
if ( V_22 )
strcpy ( V_22 -> V_329 . V_126 , L_30 ) ;
V_22 = F_9 ( V_8 , L_31 ) ;
if ( V_22 )
strcpy ( V_22 -> V_329 . V_126 , L_29 ) ;
break;
}
}
static void F_194 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
T_1 V_199 [ 2 ] = { 0x0c } ;
F_102 ( V_8 , 0x14 , 1 , V_199 ) ;
F_102 ( V_8 , 0x15 , 1 , V_199 ) ;
}
}
static void F_195 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
if ( V_2 -> V_243 != V_249 )
return;
if ( ( F_38 ( V_8 ) & 0x00ff ) < 0x015 ) {
F_128 ( V_8 , 0xf , 0x960b ) ;
F_128 ( V_8 , 0xe , 0x8817 ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x016 ) {
F_128 ( V_8 , 0xf , 0x960b ) ;
F_128 ( V_8 , 0xe , 0x8814 ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x017 ) {
V_9 = F_39 ( V_8 , 0x04 ) ;
F_128 ( V_8 , 0x04 , V_9 | ( 1 << 11 ) ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
V_9 = F_39 ( V_8 , 0xd ) ;
if ( ( V_9 & 0x0c00 ) >> 10 != 0x1 ) {
F_128 ( V_8 , 0xd , V_9 | ( 1 << 10 ) ) ;
}
V_9 = F_39 ( V_8 , 0x17 ) ;
if ( ( V_9 & 0x01c0 ) >> 6 != 0x4 ) {
F_128 ( V_8 , 0x17 , V_9 | ( 1 << 7 ) ) ;
}
}
V_9 = F_39 ( V_8 , 0xd ) ;
F_128 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
V_9 = F_39 ( V_8 , 0x4 ) ;
F_128 ( V_8 , 0x4 , V_9 | ( 1 << 11 ) ) ;
}
static int F_196 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_217 = 0x18 ;
F_87 ( V_8 , V_330 ,
V_331 , V_332 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_76 ( V_8 ) )
V_2 -> V_78 . V_162 = 0x01 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0269 :
V_2 -> V_243 = V_244 ;
switch ( F_38 ( V_8 ) & 0x00f0 ) {
case 0x0010 :
if ( V_8 -> V_62 -> V_63 -> V_145 == 0x1025 &&
V_2 -> V_51 . V_71 == 1 )
V_122 = F_73 ( V_8 , L_17 ) ;
V_2 -> V_243 = V_249 ;
break;
case 0x0020 :
if ( V_8 -> V_62 -> V_63 -> V_145 == 0x17aa &&
V_8 -> V_62 -> V_63 -> V_64 == 0x21f3 )
V_122 = F_73 ( V_8 , L_32 ) ;
V_2 -> V_243 = V_245 ;
break;
case 0x0030 :
V_2 -> V_243 = V_250 ;
break;
default:
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
}
if ( V_122 < 0 )
goto error;
V_2 -> V_129 = F_195 ;
F_195 ( V_8 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_2 -> V_243 = V_246 ;
break;
case 0x10ec0282 :
V_2 -> V_243 = V_251 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_2 -> V_243 = V_252 ;
V_2 -> V_131 = F_132 ;
V_2 -> V_129 = F_130 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_2 -> V_243 = V_247 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_2 -> V_243 = V_248 ;
break;
case 0x10ec0286 :
V_2 -> V_243 = V_253 ;
break;
case 0x10ec0255 :
V_2 -> V_243 = V_254 ;
break;
}
if ( F_6 ( V_8 , 0x51 , 0 , V_333 , 0 ) == 0x10ec5505 ) {
V_2 -> V_263 = 1 ;
V_2 -> V_129 = F_137 ;
}
V_122 = F_126 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 && V_2 -> V_78 . V_162 )
F_88 ( V_2 , 0x0b , 0x04 , V_167 ) ;
V_8 -> V_134 = V_168 ;
#ifdef F_197
V_8 -> V_134 . V_334 = F_139 ;
V_8 -> V_134 . V_335 = F_141 ;
#endif
if ( ! V_2 -> V_131 )
V_2 -> V_131 = F_129 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_198 ( struct V_7 * V_8 )
{
static const T_1 V_336 [] = { 0x1d , 0 } ;
static const T_1 V_337 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_78 ( V_8 , V_336 , V_337 ) ;
}
static void F_199 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( V_49 != V_130 )
return;
V_9 = F_105 ( V_8 , 0x0f ) ;
if ( ! ( V_9 & ( V_281 | V_314 ) ) )
V_9 |= V_281 ;
V_9 |= V_207 ;
F_106 ( V_8 , 0x0f , V_9 ) ;
V_2 -> V_78 . V_205 = 1 ;
}
static void F_200 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 )
V_8 -> V_338 = 1 ;
}
static int F_201 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x15 ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_162 = 0x23 ;
F_87 ( V_8 , NULL , V_339 , V_340 ) ;
F_61 ( V_8 , V_50 ) ;
V_122 = F_198 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 )
F_88 ( V_2 , 0x23 , 0 , V_106 ) ;
V_8 -> V_134 = V_168 ;
#ifdef F_197
V_2 -> V_133 = F_67 ;
#endif
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_202 ( struct V_7 * V_8 )
{
static const T_1 V_341 [] = { 0x1d , 0 } ;
static const T_1 V_342 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_78 ( V_8 , V_341 , V_342 ) ;
}
static void F_203 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
F_204 ( V_8 , 0x18 , 0x00000734 ) ;
F_204 ( V_8 , 0x19 , 0x0000073c ) ;
}
}
static int F_205 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_162 = 0x23 ;
F_87 ( V_8 , NULL , V_343 , V_344 ) ;
F_61 ( V_8 , V_50 ) ;
V_122 = F_202 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 )
F_88 ( V_2 , 0x0b , 0x05 , V_167 ) ;
V_8 -> V_134 = V_168 ;
V_2 -> V_131 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_206 ( struct V_7 * V_8 )
{
static const T_1 V_345 [] = { 0x1d , 0 } ;
static const T_1 V_346 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_347 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_242 ;
if ( V_8 -> V_46 == 0x10ec0272 || V_8 -> V_46 == 0x10ec0663 ||
V_8 -> V_46 == 0x10ec0665 || V_8 -> V_46 == 0x10ec0670 ||
V_8 -> V_46 == 0x10ec0671 )
V_242 = V_346 ;
else
V_242 = V_347 ;
return F_78 ( V_8 , V_345 , V_242 ) ;
}
static void F_207 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_50 )
return;
if ( F_119 ( V_8 , 0x2 , V_106 ,
( 0x3b << V_228 ) |
( 0x3b << V_229 ) |
( 0x03 << V_230 ) |
( 0 << V_231 ) ) )
F_30 ( V_348
L_33 ) ;
}
static void F_208 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_128 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_349 [ 0 ] . V_350 [ 0 ] . V_351 = V_352 ;
}
}
static void F_209 ( struct V_7 * V_8 )
{
int V_9 , V_265 ;
V_265 = F_38 ( V_8 ) ;
switch ( V_8 -> V_46 ) {
case 0x10ec0662 :
if ( ( V_265 & 0x00f0 ) == 0x0030 ) {
V_9 = F_39 ( V_8 , 0x4 ) ;
F_128 ( V_8 , 0x4 , V_9 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_9 = F_39 ( V_8 , 0xd ) ;
F_128 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
break;
}
}
static int F_210 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_122 ;
V_122 = F_81 ( V_8 , 0x0b ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_153 = V_264 ;
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
V_2 -> V_129 = F_209 ;
F_209 ( V_8 ) ;
F_87 ( V_8 , V_353 ,
V_354 , V_355 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_76 ( V_8 ) )
V_2 -> V_78 . V_162 = 0x01 ;
if ( ( F_38 ( V_8 ) & ( 1 << 14 ) ) &&
V_8 -> V_62 -> V_63 -> V_145 == 0x1025 &&
V_2 -> V_51 . V_71 == 1 ) {
V_122 = F_73 ( V_8 , L_34 ) ;
if ( V_122 < 0 )
goto error;
}
V_122 = F_206 ( V_8 ) ;
if ( V_122 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_166 && V_2 -> V_78 . V_162 ) {
switch ( V_8 -> V_46 ) {
case 0x10ec0662 :
F_88 ( V_2 , 0x0b , 0x05 , V_167 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_88 ( V_2 , 0x0b , 0x04 , V_167 ) ;
break;
case 0x10ec0273 :
F_88 ( V_2 , 0x0b , 0x03 , V_167 ) ;
break;
}
}
V_8 -> V_134 = V_168 ;
V_2 -> V_131 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_65 ( V_8 ) ;
return V_122 ;
}
static int F_211 ( struct V_7 * V_8 )
{
return F_78 ( V_8 , NULL , NULL ) ;
}
static int F_212 ( struct V_7 * V_8 )
{
int V_122 ;
V_122 = F_81 ( V_8 , 0 ) ;
if ( V_122 < 0 )
return V_122 ;
V_122 = F_211 ( V_8 ) ;
if ( V_122 < 0 ) {
F_65 ( V_8 ) ;
return V_122 ;
}
V_8 -> V_134 = V_168 ;
return 0 ;
}
static int T_2 F_213 ( void )
{
return F_214 ( & V_356 ) ;
}
static void T_3 F_215 ( void )
{
F_216 ( & V_356 ) ;
}
