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
if ( V_9 == - 1 )
return;
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
case 0x10ec0900 :
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
if ( ! V_8 -> V_61 -> V_62 )
return - 1 ;
V_57 = V_8 -> V_63 & 0xffff ;
if ( V_57 != V_8 -> V_61 -> V_62 -> V_64 && ( V_57 & 1 ) )
goto V_60;
V_16 = 0x1d ;
if ( V_8 -> V_46 == 0x10ec0260 )
V_16 = 0x17 ;
V_57 = F_29 ( V_8 , V_16 ) ;
if ( ! ( V_57 & 1 ) ) {
F_30 ( V_8 , L_2 ,
V_8 -> V_65 , V_57 ) ;
return - 1 ;
}
V_31 = 0 ;
for ( V_58 = 1 ; V_58 < 16 ; V_58 ++ ) {
if ( ( V_57 >> V_58 ) & 1 )
V_31 ++ ;
}
if ( ( ( V_57 >> 16 ) & 0xf ) != V_31 )
return - 1 ;
V_2 -> V_51 . V_66 = V_57 >> 30 ;
V_2 -> V_51 . V_59 = ( V_57 & 0x100000 ) >> 20 ;
V_2 -> V_51 . V_67 = ( V_57 >> 16 ) & 0xf ;
V_2 -> V_51 . V_68 = V_57 >> 8 ;
V_60:
V_2 -> V_51 . V_53 = V_57 ;
V_2 -> V_51 . V_69 = ( V_57 & 0x38 ) >> 3 ;
V_2 -> V_51 . V_70 = ( V_57 & 0x4 ) >> 2 ;
V_2 -> V_51 . V_71 = ( V_57 & 0x2 ) >> 1 ;
V_2 -> V_51 . V_72 = V_57 & 0x1 ;
F_31 ( V_8 , L_3 ,
V_16 , V_2 -> V_51 . V_53 ) ;
F_31 ( V_8 , L_4 ,
V_2 -> V_51 . V_66 ) ;
F_31 ( V_8 , L_5 , V_2 -> V_51 . V_59 ) ;
F_31 ( V_8 , L_6 , V_2 -> V_51 . V_67 ) ;
F_31 ( V_8 , L_7 , V_2 -> V_51 . V_68 ) ;
F_31 ( V_8 , L_8 , V_2 -> V_51 . V_69 ) ;
F_31 ( V_8 , L_9 , V_2 -> V_51 . V_70 ) ;
F_31 ( V_8 , L_10 , V_2 -> V_51 . V_71 ) ;
F_31 ( V_8 , L_11 , V_2 -> V_51 . V_72 ) ;
return 0 ;
}
static int F_32 ( T_1 V_16 , const T_1 * V_73 , int V_74 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_74 ; V_58 ++ )
if ( V_73 [ V_58 ] == V_16 )
return V_58 ;
return - 1 ;
}
static bool F_33 ( T_1 V_16 , const T_1 * V_73 , int V_74 )
{
return F_32 ( V_16 , V_73 , V_74 ) >= 0 ;
}
static int F_34 ( struct V_7 * V_8 , const T_1 * V_75 )
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
V_57 = V_8 -> V_63 & 0xffff ;
if ( V_8 -> V_61 -> V_62 &&
V_57 != V_8 -> V_61 -> V_62 -> V_64 && ( V_57 & 1 ) )
goto V_60;
V_16 = 0x1d ;
if ( V_8 -> V_46 == 0x10ec0260 )
V_16 = 0x17 ;
V_57 = F_29 ( V_8 , V_16 ) ;
F_31 ( V_8 ,
L_12 ,
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
F_31 ( V_8 , L_13 ,
V_57 & 0xffff , V_8 -> V_46 ) ;
V_31 = ( V_57 & 0x38 ) >> 3 ;
switch ( V_31 ) {
case 1 :
V_2 -> V_76 = V_39 ;
break;
case 3 :
V_2 -> V_76 = V_41 ;
break;
case 7 :
V_2 -> V_76 = V_43 ;
break;
case 5 :
default:
V_2 -> V_76 = V_45 ;
break;
}
if ( ! ( V_57 & 0x8000 ) )
return 1 ;
if ( ! V_2 -> V_77 . V_78 . V_79 [ 0 ] &&
! ( V_2 -> V_77 . V_78 . V_80 [ 0 ] &&
V_2 -> V_77 . V_78 . V_81 == V_82 ) ) {
T_1 V_16 ;
V_31 = ( V_57 >> 11 ) & 0x3 ;
V_16 = V_75 [ V_31 ] ;
if ( F_33 ( V_16 , V_2 -> V_77 . V_78 . V_80 ,
V_2 -> V_77 . V_78 . V_83 ) )
return 1 ;
V_2 -> V_77 . V_78 . V_79 [ 0 ] = V_16 ;
}
return 1 ;
}
static void F_35 ( struct V_7 * V_8 , const T_1 * V_75 )
{
if ( ! F_34 ( V_8 , V_75 ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
F_31 ( V_8 ,
L_14 ) ;
V_2 -> V_76 = V_45 ;
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
unsigned int V_84 )
{
F_5 ( V_8 , V_16 , 0 , V_11 ,
V_17 ) ;
F_5 ( V_8 , V_16 , 0 , V_14 ,
V_84 ) ;
}
static unsigned int F_38 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_85 )
V_2 -> V_85 = F_39 ( V_8 , 0 ) ;
return V_2 -> V_85 ;
}
static T_1 F_40 ( struct V_7 * V_8 , int V_86 , int V_87 )
{
struct V_88 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_89 )
V_86 = V_2 -> V_90 [ V_87 ] ;
return V_2 -> V_91 [ V_86 ] ;
}
static void F_41 ( struct V_7 * V_8 , int V_86 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_92 * V_93 = & V_2 -> V_77 . V_94 ;
struct V_95 * V_96 ;
T_1 V_16 ;
int V_58 , V_97 , V_98 ;
unsigned int V_9 ;
for ( V_58 = 0 ; V_58 < V_93 -> V_99 ; V_58 ++ ) {
if ( V_2 -> V_77 . V_100 [ V_58 ] == V_2 -> V_101 )
break;
}
if ( V_58 >= V_93 -> V_99 )
return;
V_96 = F_42 ( V_8 , V_2 -> V_101 ,
F_40 ( V_8 , V_86 , V_58 ) ) ;
V_9 = V_96 -> V_102 [ V_103 ] ;
if ( ! V_9 )
return;
V_16 = F_43 ( V_9 ) ;
V_97 = F_44 ( V_9 ) ;
V_98 = V_104 |
( V_97 == V_105 ? V_106 : V_107 ) ;
F_45 ( V_8 ) ;
V_9 = F_46 ( V_8 , V_16 , 1 , V_97 , 0 ) ;
if ( V_9 & 0x80 )
return;
V_9 |= 0x80 ;
F_5 ( V_8 , V_16 , 0 , V_108 ,
V_98 | V_9 ) ;
}
static void F_47 ( struct V_7 * V_8 , bool V_109 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_110 , V_74 ;
if ( ! V_2 -> V_111 )
return;
if ( ! V_2 -> V_112 && ! V_109 )
return;
V_74 = V_2 -> V_77 . V_89 ? 1 : V_2 -> V_77 . V_113 ;
for ( V_110 = 0 ; V_110 < V_74 ; V_110 ++ ) {
bool V_114 = false ;
if ( V_2 -> V_112 &&
V_2 -> V_77 . V_100 [ V_2 -> V_77 . V_115 [ V_110 ] ] == V_2 -> V_101 )
V_114 = true ;
if ( ! V_114 && ! V_109 )
continue;
F_41 ( V_8 , V_110 ) ;
}
}
static void F_48 ( struct V_7 * V_8 ,
struct V_21 * V_116 ,
struct V_23 * V_117 )
{
F_47 ( V_8 , false ) ;
}
static int F_49 ( struct V_21 * V_116 ,
struct V_23 * V_117 )
{
struct V_7 * V_8 = F_50 ( V_116 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_117 -> V_28 . integer . V_28 [ 0 ] = ! V_2 -> V_112 ;
return 0 ;
}
static int F_51 ( struct V_21 * V_116 ,
struct V_23 * V_117 )
{
struct V_7 * V_8 = F_50 ( V_116 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 = ! V_117 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_9 == V_2 -> V_112 )
return 0 ;
V_2 -> V_112 = V_9 ;
F_47 ( V_8 , true ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_53 ( & V_2 -> V_77 , NULL , & V_118 ) )
return - V_119 ;
V_2 -> V_111 = 1 ;
V_2 -> V_112 = 0 ;
V_2 -> V_101 = V_16 ;
V_2 -> V_77 . V_120 = F_48 ;
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
int V_58 , V_121 ;
V_121 = F_56 ( V_8 ) ;
if ( V_121 < 0 )
return V_121 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_5 ; V_58 ++ ) {
V_121 = F_57 ( V_8 , V_2 -> V_6 [ V_58 ] ) ;
if ( V_121 < 0 )
return V_121 ;
}
#ifdef F_58
if ( V_2 -> V_122 ) {
const struct V_3 * V_123 ;
for ( V_123 = V_124 ; V_123 -> V_125 ; V_123 ++ ) {
struct V_21 * V_22 ;
V_22 = F_59 ( V_123 , V_8 ) ;
if ( ! V_22 )
return - V_119 ;
V_22 -> V_126 = V_2 -> V_122 ;
V_121 = F_60 ( V_8 , 0 , V_22 ) ;
if ( V_121 < 0 )
return V_121 ;
}
}
#endif
F_61 ( V_8 , V_127 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_128 )
V_2 -> V_128 ( V_8 ) ;
F_4 ( V_8 ) ;
F_24 ( V_8 , V_2 -> V_76 ) ;
F_63 ( V_8 ) ;
F_61 ( V_8 , V_129 ) ;
return 0 ;
}
static inline void F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 && V_2 -> V_130 )
V_2 -> V_130 ( V_8 ) ;
else
F_23 ( V_8 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
}
static int F_66 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_64 ( V_8 ) ;
if ( V_2 && V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_38 )
F_22 ( 150 ) ;
V_8 -> V_132 . V_133 ( V_8 ) ;
F_68 ( V_8 ) ;
F_69 ( V_8 ) ;
F_47 ( V_8 , true ) ;
F_70 ( V_8 , 0x01 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 , const char * V_125 )
{
F_11 ( V_8 -> V_65 ) ;
V_8 -> V_65 = F_72 ( V_125 , V_25 ) ;
if ( ! V_8 -> V_65 ) {
F_73 ( V_8 ) ;
return - V_119 ;
}
return 0 ;
}
static int F_74 ( struct V_7 * V_8 )
{
const struct V_134 * V_37 ;
const struct V_135 * V_136 ;
for ( V_37 = V_137 ; V_37 -> V_46 ; V_37 ++ ) {
if ( V_37 -> V_46 != V_8 -> V_46 )
continue;
if ( ( F_38 ( V_8 ) & V_37 -> V_138 ) == V_37 -> V_139 )
return F_71 ( V_8 , V_37 -> V_125 ) ;
}
if ( ! V_8 -> V_61 -> V_62 )
return 0 ;
for ( V_136 = V_140 ; V_136 -> V_141 ; V_136 ++ ) {
if ( V_136 -> V_141 != V_8 -> V_46 )
continue;
if ( V_136 -> V_142 != V_8 -> V_61 -> V_62 -> V_143 )
continue;
if ( ! V_136 -> V_144 ||
V_136 -> V_144 == V_8 -> V_61 -> V_62 -> V_64 )
return F_71 ( V_8 , V_136 -> V_125 ) ;
}
return 0 ;
}
static inline int F_75 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_145 * V_136 ;
V_136 = F_76 ( V_8 -> V_61 -> V_62 , V_146 ) ;
if ( V_136 )
return V_136 -> V_28 ;
return V_2 -> V_51 . V_59 ;
}
static int F_77 ( struct V_7 * V_8 ,
const T_1 * V_147 ,
const T_1 * V_148 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_77 . V_78 ;
int V_121 ;
V_121 = F_78 ( V_8 , V_150 , V_147 ,
V_2 -> V_151 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_148 )
F_35 ( V_8 , V_148 ) ;
V_121 = F_79 ( V_8 , V_150 ) ;
if ( V_121 < 0 )
return V_121 ;
return 1 ;
}
static int F_80 ( struct V_7 * V_8 , T_1 V_152 )
{
struct V_1 * V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
int V_121 ;
if ( ! V_2 )
return - V_119 ;
V_8 -> V_2 = V_2 ;
F_81 ( & V_2 -> V_77 ) ;
V_2 -> V_77 . V_152 = V_152 ;
V_2 -> V_77 . V_153 = 1 ;
V_8 -> V_154 = 1 ;
V_8 -> V_155 = 1 ;
V_121 = F_74 ( V_8 ) ;
if ( V_121 < 0 ) {
F_11 ( V_2 ) ;
return V_121 ;
}
return 0 ;
}
static int F_82 ( struct V_7 * V_8 )
{
static const T_1 V_156 [] = { 0x1d , 0 } ;
static const T_1 V_157 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_156 , V_157 ) ;
}
static void F_83 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_55 )
F_84 ( V_8 , 0x21 , V_158 , F_8 ) ;
}
static int F_85 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_159 = 1 ;
V_2 -> V_77 . V_160 = 0x01 ;
F_86 ( V_8 , V_161 , V_162 ,
V_163 ) ;
F_61 ( V_8 , V_50 ) ;
V_121 = F_82 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 )
F_87 ( V_2 , 0x0b , 0x05 , V_165 ) ;
V_8 -> V_132 = V_166 ;
V_8 -> V_132 . V_167 = F_12 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_88 ( struct V_7 * V_8 )
{
static const T_1 V_168 [] = { 0x17 , 0 } ;
static const T_1 V_169 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_77 ( V_8 , V_168 , V_169 ) ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_8 , 0x01 , 0 , V_170 ,
V_2 -> V_77 . V_171 ) ;
}
static void F_90 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 ) {
V_2 -> V_77 . V_172 = F_89 ;
V_2 -> V_77 . V_173 = 1 ;
V_2 -> V_77 . V_174 = 1 ;
V_2 -> V_77 . V_78 . V_79 [ 0 ] = 0x0f ;
F_84 ( V_8 , 0x0f , V_175 ,
V_176 ) ;
F_91 ( V_8 , V_40 ) ;
}
}
static void F_92 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_177 V_178 [] = {
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
F_93 ( V_8 , V_178 ) ;
break;
case V_55 :
V_2 -> V_76 = V_179 ;
break;
}
}
static void F_94 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 )
V_2 -> V_76 = V_179 ;
}
static void F_95 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_180 = 1 ;
V_2 -> V_77 . V_181 = 1 ;
}
}
static int F_96 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x07 ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_182 = 1 ;
V_2 -> V_77 . V_160 = 0x01 ;
F_86 ( V_8 , V_183 , V_184 ,
V_185 ) ;
F_61 ( V_8 , V_50 ) ;
V_121 = F_88 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 )
F_87 ( V_2 , 0x07 , 0x05 , V_165 ) ;
V_8 -> V_132 = V_166 ;
V_2 -> V_130 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static void F_97 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_129 )
return;
F_15 ( V_8 ) ;
}
static void F_98 ( struct V_7 * V_8 , int V_186 , int V_187 )
{
unsigned int V_188 , V_189 , V_190 ;
V_188 = F_6 ( V_8 , V_8 -> V_191 , 0 ,
V_192 , 0 ) ;
if ( ! V_187 )
V_188 |= ( 1 << V_186 ) ;
else
V_188 &= ~ ( 1 << V_186 ) ;
V_189 = F_6 ( V_8 , V_8 -> V_191 , 0 ,
V_193 , 0 ) ;
V_189 |= ( 1 << V_186 ) ;
V_190 = F_6 ( V_8 , V_8 -> V_191 , 0 ,
V_194 , 0 ) ;
V_190 |= ( 1 << V_186 ) ;
F_5 ( V_8 , V_8 -> V_191 , 0 ,
V_195 , V_189 ) ;
F_5 ( V_8 , V_8 -> V_191 , 0 ,
V_196 , V_190 ) ;
F_22 ( 1 ) ;
F_5 ( V_8 , V_8 -> V_191 , 0 ,
V_170 , V_188 ) ;
}
static void F_99 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_129 )
return;
F_98 ( V_8 , 0 , 0 ) ;
F_98 ( V_8 , 1 , 0 ) ;
}
static void F_100 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
T_1 V_197 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_198 [ 2 ] = { 0x0e , 0x0f } ;
F_101 ( V_8 , 0x14 , 2 , V_197 ) ;
F_101 ( V_8 , 0x15 , 2 , V_197 ) ;
F_101 ( V_8 , 0x18 , 2 , V_198 ) ;
F_101 ( V_8 , 0x1a , 2 , V_198 ) ;
} else if ( V_49 == V_55 ) {
T_1 V_199 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_101 ( V_8 , 0x14 , 5 , V_199 ) ;
F_101 ( V_8 , 0x15 , 5 , V_199 ) ;
F_101 ( V_8 , 0x18 , 5 , V_199 ) ;
F_101 ( V_8 , 0x1a , 5 , V_199 ) ;
}
}
static void F_102 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_200 [ 2 ] = { 0x14 , 0x15 } ;
int V_58 ;
if ( V_49 != V_129 )
return;
for ( V_58 = 0 ; V_58 < F_3 ( V_200 ) ; V_58 ++ ) {
unsigned int V_9 = F_29 ( V_8 , V_200 [ V_58 ] ) ;
if ( F_103 ( V_9 ) != V_201 )
continue;
V_9 = F_104 ( V_8 , V_200 [ V_58 ] ) ;
V_9 |= V_202 ;
F_105 ( V_8 , V_200 [ V_58 ] , V_9 ) ;
V_2 -> V_77 . V_203 = 1 ;
break;
}
}
static void F_106 ( struct V_7 * V_8 ,
const T_1 * V_200 , int V_204 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_204 ; V_58 ++ ) {
unsigned int V_9 ;
V_9 = F_104 ( V_8 , V_200 [ V_58 ] ) ;
V_9 |= V_205 ;
F_105 ( V_8 , V_200 [ V_58 ] , V_9 ) ;
}
V_2 -> V_77 . V_203 = 1 ;
}
static void F_107 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_200 [ 2 ] = { 0x18 , 0x1a } ;
if ( V_49 == V_129 )
F_106 ( V_8 , V_200 , F_3 ( V_200 ) ) ;
}
static void F_108 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_200 [ 1 ] = { 0x18 } ;
if ( V_49 == V_129 )
F_106 ( V_8 , V_200 , F_3 ( V_200 ) ) ;
}
static void F_109 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static T_1 V_200 [ 2 ] = { 0x18 , 0x19 } ;
if ( V_49 == V_129 )
F_106 ( V_8 , V_200 , F_3 ( V_200 ) ) ;
}
static void F_110 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_206 = 1 ;
V_2 -> V_77 . V_207 = 1 ;
}
}
static int F_111 ( struct V_7 * V_8 )
{
static const T_1 V_208 [] = { 0x1d , 0 } ;
static const T_1 V_209 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_208 , V_209 ) ;
}
static int F_112 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0882 :
case 0x10ec0885 :
case 0x10ec0900 :
break;
default:
F_7 ( V_8 , 0x20 , 0x0a , 10 ) ;
break;
}
F_86 ( V_8 , V_210 , V_211 ,
V_212 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_77 . V_160 = 0x01 ;
V_121 = F_111 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 && V_2 -> V_77 . V_160 )
F_87 ( V_2 , 0x0b , 0x05 , V_165 ) ;
V_8 -> V_132 = V_166 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_113 ( struct V_7 * V_8 )
{
static const T_1 V_213 [] = { 0x1d , 0 } ;
static const T_1 V_214 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_213 , V_214 ) ;
}
static int F_114 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_215 = 0x18 ;
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
F_86 ( V_8 , V_216 , V_217 ,
V_218 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_77 . V_160 = 0x01 ;
V_121 = F_113 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 && V_2 -> V_77 . V_160 )
F_87 ( V_2 , 0x0b , 0x05 , V_165 ) ;
V_8 -> V_132 = V_166 ;
V_2 -> V_130 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_115 ( struct V_7 * V_8 )
{
static const T_1 V_219 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , NULL , V_219 ) ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0 ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_160 = 0x01 ;
F_86 ( V_8 , V_220 , V_221 , V_222 ) ;
F_61 ( V_8 , V_50 ) ;
V_121 = F_115 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( V_121 > 0 && ! V_2 -> V_77 . V_164 &&
V_2 -> V_77 . V_78 . V_223 [ 0 ] != 0x1d ) {
F_1 ( V_2 , V_224 ) ;
F_91 ( V_8 , V_225 ) ;
if ( ! F_117 ( V_8 , 0x1d , V_165 ) )
F_118 ( V_8 , 0x1d , V_165 ,
( 0x0c << V_226 ) |
( 0x0c << V_227 ) |
( 0x07 << V_228 ) |
( 0 << V_229 ) ) ;
}
V_8 -> V_132 = V_166 ;
V_2 -> V_130 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_119 ( struct V_230 * V_231 ,
struct V_7 * V_8 ,
struct V_232 * V_233 )
{
struct V_88 * V_2 = V_8 -> V_2 ;
return F_120 ( V_8 , & V_2 -> V_234 , V_233 ,
V_231 ) ;
}
static int F_121 ( struct V_230 * V_231 ,
struct V_7 * V_8 ,
unsigned int V_235 ,
unsigned int V_236 ,
struct V_232 * V_233 )
{
struct V_88 * V_2 = V_8 -> V_2 ;
return F_122 ( V_8 , & V_2 -> V_234 ,
V_235 , V_236 , V_233 ) ;
}
static int F_123 ( struct V_230 * V_231 ,
struct V_7 * V_8 ,
struct V_232 * V_233 )
{
struct V_88 * V_2 = V_8 -> V_2 ;
return F_124 ( V_8 , & V_2 -> V_234 ) ;
}
static int F_125 ( struct V_7 * V_8 )
{
static const T_1 V_237 [] = { 0x1d , 0 } ;
static const T_1 V_238 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_239 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
const T_1 * V_240 ;
switch ( V_2 -> V_241 ) {
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_240 = V_239 ;
break;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_240 = V_238 ;
break;
default:
V_240 = V_238 ;
break;
}
return F_77 ( V_8 , V_237 , V_240 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
int V_58 ;
int V_253 = F_127 ( V_8 ) ;
if ( V_8 -> V_61 -> V_254 )
return;
for ( V_58 = 0 ; V_58 < V_8 -> V_255 . V_256 ; V_58 ++ ) {
struct V_257 * V_186 = F_128 ( & V_8 -> V_255 , V_58 ) ;
if ( V_186 -> V_16 != V_253 )
F_6 ( V_8 , V_186 -> V_16 , 0 ,
V_258 , 0 ) ;
}
V_8 -> V_259 = 1 ;
}
static void F_129 ( struct V_7 * V_8 , int V_260 )
{
int V_9 = F_39 ( V_8 , 0x04 ) ;
if ( V_9 == - 1 )
return;
if ( V_260 )
V_9 |= 1 << 11 ;
else
V_9 &= ~ ( 1 << 11 ) ;
F_130 ( V_8 , 0x04 , V_9 ) ;
}
static void F_131 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_241 == V_247 )
F_129 ( V_8 , 0 ) ;
if ( V_2 -> V_241 == V_247 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
F_23 ( V_8 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
int V_9 ;
F_130 ( V_8 , 0x03 , 0x0002 ) ;
F_130 ( V_8 , 0x05 , 0x0700 ) ;
F_130 ( V_8 , 0x07 , 0x0200 ) ;
V_9 = F_39 ( V_8 , 0x06 ) ;
F_130 ( V_8 , 0x06 , ( V_9 & ~ 0x00f0 ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x08 ) ;
F_130 ( V_8 , 0x08 , ( V_9 & ~ 0xfffc ) | 0x0c2c ) ;
F_130 ( V_8 , 0x0a , 0xcccc ) ;
F_130 ( V_8 , 0x0b , 0xcccc ) ;
F_130 ( V_8 , 0x0e , 0x6e00 ) ;
V_9 = F_39 ( V_8 , 0x0f ) ;
F_130 ( V_8 , 0x0f , ( V_9 & ~ 0xf800 ) | 0x1000 ) ;
V_9 = F_39 ( V_8 , 0x10 ) ;
F_130 ( V_8 , 0x10 , ( V_9 & ~ 0xfc00 ) | 0x0c00 ) ;
F_130 ( V_8 , 0x6f , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x0c ) ;
F_130 ( V_8 , 0x0c , ( V_9 & ~ 0xfe00 ) | 0x0 ) ;
F_130 ( V_8 , 0x34 , 0xa0c0 ) ;
V_9 = F_39 ( V_8 , 0x16 ) ;
F_130 ( V_8 , 0x16 , ( V_9 & ~ 0x0008 ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x1d ) ;
F_130 ( V_8 , 0x1d , ( V_9 & ~ 0x00e0 ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x1f ) ;
F_130 ( V_8 , 0x1f , ( V_9 & ~ 0x00e0 ) | 0x0 ) ;
F_130 ( V_8 , 0x21 , 0x8804 ) ;
F_130 ( V_8 , 0x63 , 0x2902 ) ;
F_130 ( V_8 , 0x68 , 0xa080 ) ;
F_130 ( V_8 , 0x69 , 0x3400 ) ;
F_130 ( V_8 , 0x6a , 0x2f3e ) ;
F_130 ( V_8 , 0x6b , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x6d ) ;
F_130 ( V_8 , 0x6d , ( V_9 & ~ 0x0fff ) | 0x0900 ) ;
F_130 ( V_8 , 0x6e , 0x110a ) ;
V_9 = F_39 ( V_8 , 0x70 ) ;
F_130 ( V_8 , 0x70 , ( V_9 & ~ 0x00f8 ) | 0x00d8 ) ;
F_130 ( V_8 , 0x71 , 0x0014 ) ;
F_130 ( V_8 , 0x72 , 0xc2ba ) ;
V_9 = F_39 ( V_8 , 0x77 ) ;
F_130 ( V_8 , 0x77 , ( V_9 & ~ 0x0f80 ) | 0x0 ) ;
F_130 ( V_8 , 0x6c , 0xfc06 ) ;
}
static void F_133 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
bool V_262 ;
int V_263 ;
F_132 ( V_8 ) ;
if ( ! V_261 )
return;
V_262 = F_134 ( V_8 , V_261 ) ;
V_263 = F_39 ( V_8 , 0x78 ) ;
F_130 ( V_8 , 0x78 , 0x9004 ) ;
if ( V_262 )
F_22 ( 2 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_108 , V_264 ) ;
if ( V_262 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_258 , V_265 ) ;
if ( V_262 )
F_22 ( 100 ) ;
F_130 ( V_8 , 0x78 , V_263 ) ;
}
static void F_135 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
bool V_262 ;
int V_263 ;
if ( ! V_261 ) {
F_131 ( V_8 ) ;
return;
}
V_262 = F_134 ( V_8 , V_261 ) ;
V_263 = F_39 ( V_8 , 0x78 ) ;
F_130 ( V_8 , 0x78 , 0x9004 ) ;
if ( V_262 )
F_22 ( 2 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_108 , V_264 ) ;
if ( V_262 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_258 , 0x0 ) ;
if ( V_262 )
F_22 ( 100 ) ;
F_20 ( V_8 , false ) ;
F_23 ( V_8 ) ;
F_130 ( V_8 , 0x78 , V_263 ) ;
}
static void F_136 ( struct V_7 * V_8 )
{
int V_9 ;
F_130 ( V_8 , 0x03 , 0x0002 ) ;
F_130 ( V_8 , 0x05 , 0x0700 ) ;
F_130 ( V_8 , 0x07 , 0x0200 ) ;
V_9 = F_39 ( V_8 , 0x06 ) ;
F_130 ( V_8 , 0x06 , ( V_9 & ~ 0x00f0 ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x08 ) ;
F_130 ( V_8 , 0x08 , ( V_9 & ~ 0xfffc ) | 0x0c2c ) ;
F_130 ( V_8 , 0x0a , 0xcccc ) ;
F_130 ( V_8 , 0x0b , 0xcccc ) ;
F_130 ( V_8 , 0x0e , 0x6fc0 ) ;
V_9 = F_39 ( V_8 , 0x0f ) ;
F_130 ( V_8 , 0x0f , ( V_9 & ~ 0xf800 ) | 0x1000 ) ;
V_9 = F_39 ( V_8 , 0x10 ) ;
F_130 ( V_8 , 0x10 , ( V_9 & ~ 0xfc00 ) | 0x0c00 ) ;
F_130 ( V_8 , 0x3a , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x0c ) ;
F_130 ( V_8 , 0x0c , ( V_9 & ~ 0xfe00 ) | 0x0 ) ;
F_130 ( V_8 , 0x22 , 0xa0c0 ) ;
V_9 = F_36 ( V_8 , 0x53 , 0x01 ) ;
F_37 ( V_8 , 0x53 , 0x01 , ( V_9 & ~ 0x000f ) | 0x0008 ) ;
V_9 = F_39 ( V_8 , 0x1d ) ;
F_130 ( V_8 , 0x1d , ( V_9 & ~ 0x00e0 ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x1f ) ;
F_130 ( V_8 , 0x1f , ( V_9 & ~ 0x00e0 ) | 0x0 ) ;
F_130 ( V_8 , 0x21 , 0x8804 ) ;
F_130 ( V_8 , 0x2e , 0x2902 ) ;
F_130 ( V_8 , 0x33 , 0xa080 ) ;
F_130 ( V_8 , 0x34 , 0x3400 ) ;
F_130 ( V_8 , 0x35 , 0x2f3e ) ;
F_130 ( V_8 , 0x36 , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x38 ) ;
F_130 ( V_8 , 0x38 , ( V_9 & ~ 0x0fff ) | 0x0900 ) ;
F_130 ( V_8 , 0x39 , 0x110a ) ;
V_9 = F_39 ( V_8 , 0x3b ) ;
F_130 ( V_8 , 0x3b , ( V_9 & ~ 0x00f8 ) | 0x00d8 ) ;
F_130 ( V_8 , 0x3c , 0x0014 ) ;
F_130 ( V_8 , 0x3d , 0xc2ba ) ;
V_9 = F_39 ( V_8 , 0x42 ) ;
F_130 ( V_8 , 0x42 , ( V_9 & ~ 0x0f80 ) | 0x0 ) ;
F_130 ( V_8 , 0x49 , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x40 ) ;
F_130 ( V_8 , 0x40 , ( V_9 & ~ 0xf800 ) | 0x9800 ) ;
V_9 = F_39 ( V_8 , 0x42 ) ;
F_130 ( V_8 , 0x42 , ( V_9 & ~ 0xf000 ) | 0x2000 ) ;
F_130 ( V_8 , 0x37 , 0xfc06 ) ;
}
static void F_137 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
bool V_262 ;
int V_9 ;
if ( ! V_2 -> V_77 . V_78 . V_266 ) {
if ( V_2 -> V_77 . V_78 . V_81 == V_201 )
V_261 = V_2 -> V_77 . V_78 . V_80 [ 0 ] ;
}
F_136 ( V_8 ) ;
if ( ! V_261 )
return;
V_262 = F_134 ( V_8 , V_261 ) ;
F_130 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_108 , V_264 ) ;
if ( V_262 )
F_22 ( 85 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_258 , V_265 ) ;
if ( V_262 )
F_22 ( 85 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
F_130 ( V_8 , 0x46 , V_9 & ~ ( 3 << 12 ) ) ;
F_130 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_138 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
bool V_262 ;
int V_9 ;
if ( ! V_2 -> V_77 . V_78 . V_266 ) {
if ( V_2 -> V_77 . V_78 . V_81 == V_201 )
V_261 = V_2 -> V_77 . V_78 . V_80 [ 0 ] ;
}
if ( ! V_261 ) {
F_131 ( V_8 ) ;
return;
}
V_262 = F_134 ( V_8 , V_261 ) ;
F_130 ( V_8 , 0x43 , 0x9004 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_108 , V_264 ) ;
if ( V_262 )
F_22 ( 100 ) ;
F_5 ( V_8 , V_261 , 0 ,
V_258 , 0x0 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
F_130 ( V_8 , 0x46 , V_9 | ( 3 << 12 ) ) ;
if ( V_262 )
F_22 ( 100 ) ;
F_20 ( V_8 , false ) ;
F_23 ( V_8 ) ;
F_130 ( V_8 , 0x43 , 0x9614 ) ;
}
static void F_139 ( struct V_7 * V_8 , unsigned int V_267 ,
unsigned int V_9 )
{
F_5 ( V_8 , 0x51 , 0 , V_11 , V_267 >> 1 ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 & 0xffff ) ;
F_5 ( V_8 , 0x51 , 0 , V_14 , V_9 >> 16 ) ;
}
static int F_140 ( struct V_7 * V_8 , unsigned int V_267 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x51 , 0 , V_11 , V_267 >> 1 ) ;
V_9 = F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
& 0xffff ;
V_9 |= F_6 ( V_8 , 0x51 , 0 , V_13 , 0 )
<< 16 ;
return V_9 ;
}
static void F_141 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_139 ( V_8 , 0x3000 , 0x000c ) ;
F_139 ( V_8 , 0x880c , 0x0008 ) ;
F_139 ( V_8 , 0x61c0 , 0x11110080 ) ;
F_139 ( V_8 , 0x6230 , 0xfc0d4011 ) ;
F_139 ( V_8 , 0x61b4 , 0x040a2b03 ) ;
F_139 ( V_8 , 0x61b0 , 0x00005b17 ) ;
F_139 ( V_8 , 0x61b8 , 0x04133303 ) ;
V_9 = F_140 ( V_8 , 0x6220 ) ;
F_139 ( V_8 , 0x6220 , ( V_9 | 0x3000 ) ) ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_139 ( V_8 , 0x61b8 , 0x04133302 ) ;
F_139 ( V_8 , 0x61b0 , 0x00005b16 ) ;
F_139 ( V_8 , 0x61b4 , 0x040a2b02 ) ;
F_139 ( V_8 , 0x6230 , 0xf80d4011 ) ;
F_139 ( V_8 , 0x6220 , 0x2002010f ) ;
F_139 ( V_8 , 0x880c , 0x00000004 ) ;
}
static void F_143 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
F_141 ( V_8 ) ;
F_142 ( V_8 ) ;
F_139 ( V_8 , 0x61b0 , 0x5b14 ) ;
F_139 ( V_8 , 0x61b0 , 0x5b16 ) ;
F_139 ( V_8 , 0x61b4 , 0x04132b00 ) ;
F_139 ( V_8 , 0x61b4 , 0x04132b02 ) ;
F_139 ( V_8 , 0x61b8 , 0x041f3300 ) ;
F_139 ( V_8 , 0x61b8 , 0x041f3302 ) ;
F_5 ( V_8 , 0x51 , 0 , V_268 , 0 ) ;
F_139 ( V_8 , 0x61b8 , 0x041b3302 ) ;
F_139 ( V_8 , 0x61b8 , 0x04173302 ) ;
F_139 ( V_8 , 0x61b8 , 0x04163302 ) ;
F_139 ( V_8 , 0x8800 , 0x348b328b ) ;
F_139 ( V_8 , 0x8808 , 0x00020022 ) ;
F_139 ( V_8 , 0x8818 , 0x00000400 ) ;
V_9 = F_140 ( V_8 , 0x6200 ) >> 16 ;
if ( V_9 <= 3 )
F_139 ( V_8 , 0x6220 , 0x2002010f ) ;
else
F_139 ( V_8 , 0x6220 , 0x6002018f ) ;
F_139 ( V_8 , 0x61ac , 0x055525f0 ) ;
F_139 ( V_8 , 0x61c0 , 0x12230080 ) ;
F_139 ( V_8 , 0x61b4 , 0x040e2b02 ) ;
F_139 ( V_8 , 0x61bc , 0x010234f8 ) ;
F_139 ( V_8 , 0x880c , 0x00000004 ) ;
F_139 ( V_8 , 0x880c , 0x00000003 ) ;
F_139 ( V_8 , 0x880c , 0x00000010 ) ;
#ifdef F_144
F_141 ( V_8 ) ;
#endif
}
static int F_145 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_269 )
F_146 ( V_8 ) ;
return F_66 ( V_8 ) ;
}
static int F_147 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_241 == V_247 )
F_129 ( V_8 , 0 ) ;
if ( V_2 -> V_241 == V_247 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
V_8 -> V_132 . V_133 ( V_8 ) ;
if ( V_2 -> V_241 == V_247 )
F_129 ( V_8 , 1 ) ;
if ( V_2 -> V_241 == V_247 &&
( F_38 ( V_8 ) & 0x00ff ) == 0x017 ) {
F_22 ( 200 ) ;
}
F_68 ( V_8 ) ;
F_69 ( V_8 ) ;
F_47 ( V_8 , true ) ;
F_70 ( V_8 , 0x01 ) ;
if ( V_2 -> V_270 )
F_5 ( V_8 , V_8 -> V_191 , 0 , V_170 ,
V_2 -> V_270 ) ;
if ( V_2 -> V_269 )
F_148 ( V_8 ) ;
return 0 ;
}
static void F_149 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 )
V_2 -> V_151 = V_271 ;
}
static void F_150 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
int V_272 ;
if ( V_49 != V_129 )
return;
V_272 = F_39 ( V_8 , 0x1e ) ;
F_130 ( V_8 , 0x1e , V_272 | 0x80 ) ;
}
static void F_151 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 )
V_2 -> V_151 |= V_273 ;
}
static void F_152 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
static const struct V_274 V_275 [] = {
{ 0x20 , V_11 , 0x0d } ,
{ 0x20 , V_14 , 0x4000 } ,
{}
} ;
unsigned int V_150 ;
if ( strcmp ( V_8 -> V_65 , L_15 ) &&
strcmp ( V_8 -> V_65 , L_16 ) )
return;
V_150 = F_29 ( V_8 , 0x12 ) ;
if ( F_153 ( V_150 ) == V_276 )
F_25 ( V_8 , V_275 ) ;
}
static void F_154 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 != V_55 )
return;
V_2 -> V_77 . V_277 = & V_278 ;
V_2 -> V_77 . V_279 = & V_280 ;
}
static void F_155 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
int V_272 ;
if ( V_49 != V_129 )
return;
V_272 = F_39 ( V_8 , 0x07 ) ;
F_130 ( V_8 , 0x07 , V_272 | 0x80 ) ;
}
static void F_156 ( struct V_7 * V_8 )
{
F_157 ( V_8 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x680 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x480 ) ;
}
static void F_158 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 != V_55 )
return;
V_2 -> V_77 . V_172 = F_156 ;
}
static void F_159 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_281 ;
F_22 ( 200 ) ;
V_176 ( V_8 , V_20 ) ;
V_281 = V_2 -> V_77 . V_171 ? V_282 : 0 ;
F_22 ( 100 ) ;
F_5 ( V_8 , 0x18 , 0 , V_258 ,
V_281 ) ;
F_22 ( 500 ) ;
F_5 ( V_8 , 0x18 , 0 , V_258 ,
V_281 ) ;
}
static void F_160 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_151 |= V_273 ;
V_2 -> V_77 . V_283 = F_159 ;
}
}
static void F_161 ( void * V_284 , int V_285 )
{
struct V_7 * V_8 = V_284 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_286 ;
if ( V_2 -> V_287 )
V_285 = ! V_285 ;
V_286 = F_104 ( V_8 , V_2 -> V_288 ) ;
V_286 &= ~ V_289 ;
V_286 |= V_285 ? V_290 : V_202 ;
if ( V_2 -> V_288 )
F_162 ( V_8 , V_2 -> V_288 , V_286 ) ;
}
static unsigned int F_163 ( struct V_7 * V_8 ,
T_1 V_16 ,
unsigned int V_291 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_291 != V_292 || V_16 == 0 ||
( V_16 != V_2 -> V_288 && V_16 != V_2 -> V_293 ) )
return V_291 ;
F_105 ( V_8 , V_16 ,
F_104 ( V_8 , V_16 ) ) ;
return V_294 ;
}
static void F_164 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_295 * V_296 = NULL ;
if ( V_49 != V_50 )
return;
while ( ( V_296 = F_165 ( V_297 , NULL , V_296 ) ) ) {
int V_298 , V_186 ;
if ( sscanf ( V_296 -> V_125 , L_17 , & V_298 , & V_186 ) != 2 )
continue;
if ( V_186 < 0x0a || V_186 >= 0x10 )
break;
V_2 -> V_287 = V_298 ;
V_2 -> V_288 = V_186 - 0x0a + 0x18 ;
V_2 -> V_77 . V_299 . V_300 = F_161 ;
V_2 -> V_77 . V_301 = 1 ;
V_8 -> V_302 = F_163 ;
F_31 ( V_8 ,
L_18 , V_2 -> V_288 ,
V_2 -> V_287 ) ;
break;
}
}
static void F_166 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_287 = 0 ;
V_2 -> V_288 = 0x18 ;
V_2 -> V_77 . V_299 . V_300 = F_161 ;
V_2 -> V_77 . V_301 = 1 ;
V_8 -> V_302 = F_163 ;
}
}
static void F_167 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_287 = 0 ;
V_2 -> V_288 = 0x19 ;
V_2 -> V_77 . V_299 . V_300 = F_161 ;
V_2 -> V_77 . V_301 = 1 ;
V_8 -> V_302 = F_163 ;
}
}
static void F_168 ( void * V_284 , int V_285 )
{
struct V_7 * V_8 = V_284 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_303 = V_2 -> V_270 ;
if ( V_285 )
V_2 -> V_270 &= ~ 0x08 ;
else
V_2 -> V_270 |= 0x08 ;
if ( V_2 -> V_270 != V_303 )
F_5 ( V_8 , 0x01 , 0 , V_170 ,
V_2 -> V_270 ) ;
}
static void F_169 ( struct V_7 * V_8 ,
struct V_21 * V_116 ,
struct V_23 * V_117 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_303 = V_2 -> V_270 ;
if ( ! V_117 )
return;
if ( V_117 -> V_28 . integer . V_28 [ 0 ] ||
V_117 -> V_28 . integer . V_28 [ 1 ] )
V_2 -> V_270 &= ~ 0x10 ;
else
V_2 -> V_270 |= 0x10 ;
if ( V_2 -> V_270 != V_303 )
F_5 ( V_8 , 0x01 , 0 , V_170 ,
V_2 -> V_270 ) ;
}
static void F_170 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_274 V_304 [] = {
{ 0x01 , V_195 , 0x18 } ,
{ 0x01 , V_196 , 0x18 } ,
{}
} ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_299 . V_300 = F_168 ;
V_2 -> V_77 . V_120 = F_169 ;
V_2 -> V_270 = 0 ;
F_91 ( V_8 , V_304 ) ;
}
}
static void F_171 ( struct V_7 * V_8 ,
struct V_21 * V_116 ,
struct V_23 * V_117 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_286 , V_305 , V_306 ;
V_286 = F_104 ( V_8 , V_2 -> V_293 ) ;
V_286 &= ~ V_289 ;
V_305 = V_286 | V_202 ;
V_306 = V_286 | V_290 ;
if ( ! V_117 )
return;
if ( V_117 -> V_28 . integer . V_28 [ 0 ] ||
V_117 -> V_28 . integer . V_28 [ 1 ] )
V_286 = V_306 ;
else
V_286 = V_305 ;
if ( V_2 -> V_293 )
F_162 ( V_8 , V_2 -> V_293 , V_286 ) ;
}
static void F_172 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_274 V_304 [] = {
{ 0x01 , V_195 , 0x08 } ,
{ 0x01 , V_196 , 0x08 } ,
{}
} ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_299 . V_300 = F_168 ;
V_2 -> V_77 . V_120 = F_171 ;
V_2 -> V_270 = 0 ;
V_2 -> V_293 = 0x18 ;
F_91 ( V_8 , V_304 ) ;
V_8 -> V_302 = F_163 ;
}
}
static void F_173 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_299 . V_300 = F_161 ;
V_2 -> V_77 . V_120 = F_171 ;
V_2 -> V_287 = 0 ;
V_2 -> V_288 = 0x1a ;
V_2 -> V_293 = 0x18 ;
V_2 -> V_77 . V_301 = 1 ;
V_8 -> V_302 = F_163 ;
}
}
static void F_174 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x1b , 0x0c0b ) ;
F_130 ( V_8 , 0x45 , 0xd089 ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x05 ) ;
F_37 ( V_8 , 0x57 , 0x05 , V_9 & ~ ( 1 << 14 ) ) ;
F_130 ( V_8 , 0x06 , 0x6104 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x1b , 0x0c0b ) ;
F_130 ( V_8 , 0x45 , 0xc429 ) ;
V_9 = F_39 ( V_8 , 0x35 ) ;
F_130 ( V_8 , 0x35 , V_9 & 0xbfff ) ;
F_130 ( V_8 , 0x06 , 0x2104 ) ;
F_130 ( V_8 , 0x1a , 0x0001 ) ;
F_130 ( V_8 , 0x26 , 0x0004 ) ;
F_130 ( V_8 , 0x32 , 0x42a3 ) ;
break;
case 0x10ec0292 :
F_130 ( V_8 , 0x76 , 0x000e ) ;
F_130 ( V_8 , 0x6c , 0x2400 ) ;
F_130 ( V_8 , 0x18 , 0x7308 ) ;
F_130 ( V_8 , 0x6b , 0xc429 ) ;
break;
case 0x10ec0293 :
V_9 = F_39 ( V_8 , 0x10 ) ;
F_130 ( V_8 , 0x10 , ( V_9 & ~ ( 7 << 8 ) ) | 6 << 8 ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x05 ) ;
F_37 ( V_8 , 0x57 , 0x05 , ( V_9 & ~ ( 1 << 15 | 1 << 13 ) ) | 0x0 ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x03 ) ;
F_37 ( V_8 , 0x57 , 0x03 , ( V_9 & ~ ( 1 << 10 ) ) | ( 1 << 10 ) ) ;
V_9 = F_39 ( V_8 , 0x1a ) ;
F_130 ( V_8 , 0x1a , ( V_9 & ~ ( 1 << 3 ) ) | ( 1 << 3 ) ) ;
F_130 ( V_8 , 0x45 , 0xc429 ) ;
V_9 = F_39 ( V_8 , 0x4a ) ;
F_130 ( V_8 , 0x4a , ( V_9 & 0xfff0 ) | 0x000e ) ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x15 , 0x0d40 ) ;
F_130 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_31 ( V_8 , L_19 ) ;
}
static void F_175 ( struct V_7 * V_8 , T_1 V_261 ,
T_1 V_253 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x45 , 0xc489 ) ;
F_162 ( V_8 , V_261 , 0 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8aa6 ) ;
F_130 ( V_8 , 0x06 , 0x6100 ) ;
F_162 ( V_8 , V_253 , V_307 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x45 , 0xc429 ) ;
F_162 ( V_8 , V_261 , 0 ) ;
V_9 = F_39 ( V_8 , 0x35 ) ;
F_130 ( V_8 , 0x35 , V_9 | 1 << 14 ) ;
F_130 ( V_8 , 0x06 , 0x2100 ) ;
F_130 ( V_8 , 0x1a , 0x0021 ) ;
F_130 ( V_8 , 0x26 , 0x008c ) ;
F_162 ( V_8 , V_253 , V_307 ) ;
break;
case 0x10ec0292 :
F_162 ( V_8 , V_261 , 0 ) ;
F_130 ( V_8 , 0x19 , 0xa208 ) ;
F_130 ( V_8 , 0x2e , 0xacf0 ) ;
break;
case 0x10ec0293 :
F_130 ( V_8 , 0x45 , 0xc429 ) ;
F_162 ( V_8 , V_261 , 0 ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x05 ) ;
F_37 ( V_8 , 0x57 , 0x05 , ( V_9 & ~ ( 1 << 15 | 1 << 13 ) ) | ( 1 << 15 | 1 << 13 ) ) ;
V_9 = F_36 ( V_8 , 0x57 , 0x03 ) ;
F_37 ( V_8 , 0x57 , 0x03 , ( V_9 & ~ ( 1 << 10 ) ) | 0x0 ) ;
V_9 = F_39 ( V_8 , 0x1a ) ;
F_130 ( V_8 , 0x1a , ( V_9 & ~ ( 1 << 3 ) ) | 0x0 ) ;
F_162 ( V_8 , V_253 , V_307 ) ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x11 , 0x0001 ) ;
F_162 ( V_8 , V_261 , 0 ) ;
F_130 ( V_8 , 0xb7 , 0x802b ) ;
F_130 ( V_8 , 0xb5 , 0x1040 ) ;
V_9 = F_39 ( V_8 , 0xc3 ) ;
F_130 ( V_8 , 0xc3 , V_9 | 1 << 12 ) ;
F_162 ( V_8 , V_253 , V_307 ) ;
break;
}
F_31 ( V_8 , L_20 ) ;
}
static void F_176 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x45 , 0xc089 ) ;
F_130 ( V_8 , 0x45 , 0xc489 ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
F_130 ( V_8 , 0x49 , 0x0049 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x06 , 0x2100 ) ;
F_130 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_130 ( V_8 , 0x76 , 0x000e ) ;
F_130 ( V_8 , 0x6c , 0x2400 ) ;
F_130 ( V_8 , 0x6b , 0xc429 ) ;
F_130 ( V_8 , 0x18 , 0x7308 ) ;
break;
case 0x10ec0293 :
V_9 = F_39 ( V_8 , 0x4a ) ;
F_130 ( V_8 , 0x4a , ( V_9 & 0xfff0 ) | 0x000e ) ;
F_130 ( V_8 , 0x45 , 0xC429 ) ;
V_9 = F_39 ( V_8 , 0x1a ) ;
F_130 ( V_8 , 0x1a , ( V_9 & ~ ( 1 << 3 ) ) | 0x0 ) ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x11 , 0x0041 ) ;
F_130 ( V_8 , 0x15 , 0x0d40 ) ;
F_130 ( V_8 , 0xb7 , 0x802b ) ;
break;
}
F_31 ( V_8 , L_21 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x45 , 0xd489 ) ;
F_130 ( V_8 , 0x1b , 0x0c2b ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x45 , 0xd429 ) ;
F_130 ( V_8 , 0x1b , 0x0c2b ) ;
F_130 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_130 ( V_8 , 0x6b , 0xd429 ) ;
F_130 ( V_8 , 0x76 , 0x0008 ) ;
F_130 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0293 :
F_130 ( V_8 , 0x45 , 0xd429 ) ;
V_9 = F_39 ( V_8 , 0x10 ) ;
F_130 ( V_8 , 0x10 , ( V_9 & ~ ( 7 << 8 ) ) | 7 << 8 ) ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x11 , 0x0001 ) ;
F_130 ( V_8 , 0x15 , 0x0d60 ) ;
F_130 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_31 ( V_8 , L_22 ) ;
}
static void F_178 ( struct V_7 * V_8 )
{
int V_9 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x45 , 0xe489 ) ;
F_130 ( V_8 , 0x1b , 0x0c2b ) ;
F_37 ( V_8 , 0x57 , 0x03 , 0x8ea6 ) ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x45 , 0xe429 ) ;
F_130 ( V_8 , 0x1b , 0x0c2b ) ;
F_130 ( V_8 , 0x32 , 0x4ea3 ) ;
break;
case 0x10ec0292 :
F_130 ( V_8 , 0x6b , 0xe429 ) ;
F_130 ( V_8 , 0x76 , 0x0008 ) ;
F_130 ( V_8 , 0x18 , 0x7388 ) ;
break;
case 0x10ec0293 :
F_130 ( V_8 , 0x45 , 0xe429 ) ;
V_9 = F_39 ( V_8 , 0x10 ) ;
F_130 ( V_8 , 0x10 , ( V_9 & ~ ( 7 << 8 ) ) | 7 << 8 ) ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x11 , 0x0001 ) ;
F_130 ( V_8 , 0x15 , 0x0d50 ) ;
F_130 ( V_8 , 0xc3 , 0x0000 ) ;
break;
}
F_31 ( V_8 , L_23 ) ;
}
static void F_179 ( struct V_7 * V_8 )
{
int V_9 ;
bool V_308 = false ;
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0255 :
F_130 ( V_8 , 0x45 , 0xd089 ) ;
F_130 ( V_8 , 0x49 , 0x0149 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
V_308 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
F_130 ( V_8 , 0x45 , 0xd029 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
V_308 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0292 :
F_130 ( V_8 , 0x6b , 0xd429 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x6c ) ;
V_308 = ( V_9 & 0x001c ) == 0x001c ;
break;
case 0x10ec0293 :
V_9 = F_39 ( V_8 , 0x4a ) ;
F_130 ( V_8 , 0x4a , ( V_9 & 0xfff0 ) | 0x0008 ) ;
F_130 ( V_8 , 0x45 , 0xD429 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0x46 ) ;
V_308 = ( V_9 & 0x0070 ) == 0x0070 ;
break;
case 0x10ec0668 :
F_130 ( V_8 , 0x11 , 0x0001 ) ;
F_130 ( V_8 , 0xb7 , 0x802b ) ;
F_130 ( V_8 , 0x15 , 0x0d60 ) ;
F_130 ( V_8 , 0xc3 , 0x0c00 ) ;
F_22 ( 300 ) ;
V_9 = F_39 ( V_8 , 0xbe ) ;
V_308 = ( V_9 & 0x1c02 ) == 0x1c02 ;
break;
}
F_31 ( V_8 , L_24 ,
V_308 ? L_25 : L_26 ) ;
V_2 -> V_309 = V_308 ? V_310 : V_311 ;
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_312 = V_2 -> V_77 . V_100 [ V_2 -> V_77 . V_115 [ 0 ] ] ;
T_1 V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
int V_313 ;
if ( ! F_134 ( V_8 , V_261 ) )
V_313 = V_314 ;
else if ( V_312 == V_2 -> V_315 )
V_313 = V_316 ;
else if ( V_312 == V_2 -> V_317 )
V_313 = V_318 ;
else
V_313 = V_319 ;
if ( V_313 == V_2 -> V_320 ) {
F_157 ( V_8 ) ;
return;
}
switch ( V_313 ) {
case V_314 :
F_174 ( V_8 ) ;
V_2 -> V_77 . V_171 = false ;
break;
case V_316 :
if ( V_2 -> V_309 == V_321 )
F_179 ( V_8 ) ;
if ( V_2 -> V_309 == V_310 )
F_177 ( V_8 ) ;
else if ( V_2 -> V_309 == V_311 )
F_178 ( V_8 ) ;
V_2 -> V_77 . V_171 = true ;
break;
case V_318 :
F_175 ( V_8 , V_261 , V_2 -> V_317 ) ;
V_2 -> V_77 . V_171 = false ;
break;
case V_319 :
F_176 ( V_8 ) ;
V_2 -> V_77 . V_171 = true ;
break;
}
if ( V_313 != V_318 ) {
F_162 ( V_8 , V_261 ,
V_322 | V_323 ) ;
if ( V_2 -> V_317 )
F_162 ( V_8 , V_2 -> V_317 ,
V_324 ) ;
}
V_2 -> V_320 = V_313 ;
F_157 ( V_8 ) ;
}
static void F_181 ( struct V_7 * V_8 ,
struct V_21 * V_116 ,
struct V_23 * V_117 )
{
F_180 ( V_8 ) ;
}
static void F_182 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_309 = V_321 ;
V_176 ( V_8 , V_20 ) ;
}
static void F_183 ( struct V_7 * V_8 )
{
int V_58 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_77 . V_78 ;
for ( V_58 = 0 ; V_58 < V_150 -> V_325 ; V_58 ++ ) {
if ( V_150 -> V_326 [ V_58 ] . V_327 && ! V_2 -> V_315 )
V_2 -> V_315 = V_150 -> V_326 [ V_58 ] . V_186 ;
if ( V_150 -> V_326 [ V_58 ] . V_328 && ! V_2 -> V_317 )
V_2 -> V_317 = V_150 -> V_326 [ V_58 ] . V_186 ;
}
V_2 -> V_77 . V_120 = F_181 ;
V_2 -> V_77 . V_172 = F_180 ;
V_2 -> V_77 . V_283 = F_182 ;
}
static void F_184 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_49 ) {
case V_50 :
V_2 -> V_151 |= V_273 | V_329 ;
break;
case V_55 :
F_183 ( V_8 ) ;
break;
case V_129 :
V_2 -> V_320 = 0 ;
F_180 ( V_8 ) ;
break;
}
}
static void F_185 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_151 |= V_273 ;
}
else
F_184 ( V_8 , V_48 , V_49 ) ;
}
static void F_186 ( struct V_7 * V_8 )
{
F_130 ( V_8 , 0x1b , 0x880b ) ;
F_130 ( V_8 , 0x45 , 0xd089 ) ;
F_130 ( V_8 , 0x1b , 0x080b ) ;
F_130 ( V_8 , 0x46 , 0x0004 ) ;
F_130 ( V_8 , 0x1b , 0x0c0b ) ;
F_22 ( 30 ) ;
}
static void F_187 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
F_186 ( V_8 ) ;
}
F_184 ( V_8 , V_48 , V_49 ) ;
}
static void F_188 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_151 |= V_273 ;
F_186 ( V_8 ) ;
}
else
F_184 ( V_8 , V_48 , V_49 ) ;
}
static void F_189 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_330 = 1 ;
}
}
static void F_190 ( struct V_7 * V_8 )
{
}
static void F_191 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_130 = F_190 ;
}
}
static void F_192 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_152 = 0 ;
}
}
static unsigned int F_193 ( struct V_7 * V_8 ,
T_1 V_16 ,
unsigned int V_291 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_77 . V_171 )
if ( V_16 == V_8 -> V_191 || V_16 == 0x02 || V_16 == 0x15 )
return V_294 ;
return V_291 ;
}
static void F_194 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_55 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_92 * V_93 = & V_2 -> V_77 . V_94 ;
int V_58 ;
V_2 -> V_130 = F_190 ;
V_8 -> V_302 = F_193 ;
for ( V_58 = 0 ; V_58 < V_93 -> V_99 ; V_58 ++ ) {
if ( V_2 -> V_77 . V_100 [ V_58 ] == 0x12 ) {
V_2 -> V_77 . V_115 [ 0 ] = V_58 ;
break;
}
}
}
}
static void F_195 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
int V_9 ;
F_130 ( V_8 , 0xc4 , 0x8000 ) ;
V_9 = F_39 ( V_8 , 0xc2 ) ;
F_130 ( V_8 , 0xc2 , V_9 & 0xfe ) ;
F_162 ( V_8 , 0x18 , 0 ) ;
}
F_184 ( V_8 , V_48 , V_49 ) ;
}
static int F_127 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_77 . V_78 ;
T_1 V_16 ;
unsigned int V_331 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_150 -> V_325 ; V_58 ++ ) {
if ( V_150 -> V_326 [ V_58 ] . type != V_332 )
continue;
V_16 = V_150 -> V_326 [ V_58 ] . V_186 ;
V_331 = F_29 ( V_8 , V_16 ) ;
if ( F_196 ( V_331 ) == V_333 )
continue;
return V_16 ;
}
return 0 ;
}
static void F_197 ( struct V_7 * V_8 ,
const struct V_47 * V_48 ,
int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_49 == V_55 ) {
int V_253 = F_127 ( V_8 ) ;
int V_261 = V_2 -> V_77 . V_78 . V_79 [ 0 ] ;
if ( F_2 ( ! V_253 || ! V_261 ) )
return;
F_198 ( V_8 , V_253 , V_261 ) ;
}
}
static void F_199 ( struct V_7 * V_8 ,
const struct V_47 * V_48 ,
int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_149 * V_150 = & V_2 -> V_77 . V_78 ;
int V_58 ;
if ( V_49 != V_55 )
return;
for ( V_58 = 0 ; V_58 < V_150 -> V_325 ; V_58 ++ ) {
T_1 V_16 = V_150 -> V_326 [ V_58 ] . V_186 ;
unsigned int V_331 ;
if ( V_150 -> V_326 [ V_58 ] . type != V_332 )
continue;
V_331 = F_29 ( V_8 , V_16 ) ;
if ( F_196 ( V_331 ) != V_333 )
continue;
F_118 ( V_8 , V_16 , V_165 ,
( 0x00 << V_226 ) |
( 0x01 << V_227 ) |
( 0x2f << V_228 ) |
( 0 << V_229 ) ) ;
}
}
static void F_200 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_281 ;
F_22 ( 200 ) ;
V_176 ( V_8 , V_20 ) ;
V_281 = V_2 -> V_77 . V_171 ? V_282 : 0 ;
F_22 ( 600 ) ;
F_5 ( V_8 , 0x19 , 0 , V_258 ,
V_281 ) ;
}
static void F_201 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_49 ) {
case V_50 :
F_202 ( V_8 , 0x03 , 0 ) ;
V_2 -> V_77 . V_152 = 0 ;
break;
case V_129 :
V_9 = F_39 ( V_8 , 0x06 ) ;
F_130 ( V_8 , 0x06 , V_9 & ~ 0x000c ) ;
V_9 = F_39 ( V_8 , 0x1a ) ;
F_130 ( V_8 , 0x1a , V_9 | ( 1 << 4 ) ) ;
break;
}
}
static void F_203 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
switch ( V_49 ) {
case V_50 :
V_2 -> V_77 . V_283 = F_200 ;
break;
case V_129 :
V_9 = F_39 ( V_8 , 0x06 ) ;
F_130 ( V_8 , 0x06 , V_9 & ~ 0x000c ) ;
break;
}
}
static void F_204 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_157 ( V_8 ) ;
if ( F_134 ( V_8 , 0x1b ) )
V_2 -> V_77 . V_334 |= ( 1ULL << 0x14 ) ;
}
static void F_205 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_274 V_335 [] = {
{ 0x01 , V_195 , 0x04 } ,
{ 0x01 , V_196 , 0x04 } ,
{ 0x01 , V_170 , 0x04 } ,
{}
} ;
static const struct V_177 V_336 [] = {
{ 0x1b , 0x21114000 } ,
{}
} ;
struct V_21 * V_22 ;
switch ( V_49 ) {
case V_50 :
F_91 ( V_8 , V_335 ) ;
F_93 ( V_8 , V_336 ) ;
V_2 -> V_77 . V_330 = 1 ;
V_2 -> V_77 . V_172 = F_204 ;
F_84 ( V_8 , 0x1b ,
V_175 ,
V_176 ) ;
break;
case V_127 :
V_22 = F_9 ( V_8 , L_27 ) ;
if ( V_22 )
strcpy ( V_22 -> V_337 . V_125 , L_28 ) ;
V_22 = F_9 ( V_8 , L_29 ) ;
if ( V_22 )
strcpy ( V_22 -> V_337 . V_125 , L_27 ) ;
break;
}
}
static void F_206 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
T_1 V_197 [ 2 ] = { 0x0c } ;
F_101 ( V_8 , 0x14 , 1 , V_197 ) ;
F_101 ( V_8 , 0x15 , 1 , V_197 ) ;
}
}
static void F_207 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
if ( V_2 -> V_241 != V_247 )
return;
if ( ( F_38 ( V_8 ) & 0x00ff ) < 0x015 ) {
F_130 ( V_8 , 0xf , 0x960b ) ;
F_130 ( V_8 , 0xe , 0x8817 ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x016 ) {
F_130 ( V_8 , 0xf , 0x960b ) ;
F_130 ( V_8 , 0xe , 0x8814 ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x017 ) {
V_9 = F_39 ( V_8 , 0x04 ) ;
if ( V_9 != - 1 )
F_130 ( V_8 , 0x04 , V_9 | ( 1 << 11 ) ) ;
}
if ( ( F_38 ( V_8 ) & 0x00ff ) == 0x018 ) {
V_9 = F_39 ( V_8 , 0xd ) ;
if ( V_9 != - 1 && ( V_9 & 0x0c00 ) >> 10 != 0x1 ) {
F_130 ( V_8 , 0xd , V_9 | ( 1 << 10 ) ) ;
}
V_9 = F_39 ( V_8 , 0x17 ) ;
if ( V_9 != - 1 && ( V_9 & 0x01c0 ) >> 6 != 0x4 ) {
F_130 ( V_8 , 0x17 , V_9 | ( 1 << 7 ) ) ;
}
}
V_9 = F_39 ( V_8 , 0xd ) ;
if ( V_9 != - 1 )
F_130 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
V_9 = F_39 ( V_8 , 0x4 ) ;
if ( V_9 != - 1 )
F_130 ( V_8 , 0x4 , V_9 | ( 1 << 11 ) ) ;
}
static int F_208 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_215 = 0x18 ;
F_86 ( V_8 , V_338 ,
V_339 , V_340 ) ;
F_209 ( V_8 , V_341 , V_340 ) ;
F_86 ( V_8 , NULL , V_342 ,
V_340 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_77 . V_160 = 0x01 ;
switch ( V_8 -> V_46 ) {
case 0x10ec0269 :
V_2 -> V_241 = V_242 ;
switch ( F_38 ( V_8 ) & 0x00f0 ) {
case 0x0010 :
if ( V_8 -> V_61 -> V_62 &&
V_8 -> V_61 -> V_62 -> V_143 == 0x1025 &&
V_2 -> V_51 . V_70 == 1 )
V_121 = F_71 ( V_8 , L_15 ) ;
V_2 -> V_241 = V_247 ;
break;
case 0x0020 :
if ( V_8 -> V_61 -> V_62 &&
V_8 -> V_61 -> V_62 -> V_143 == 0x17aa &&
V_8 -> V_61 -> V_62 -> V_64 == 0x21f3 )
V_121 = F_71 ( V_8 , L_30 ) ;
V_2 -> V_241 = V_243 ;
break;
case 0x0030 :
V_2 -> V_241 = V_248 ;
break;
default:
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
}
if ( V_121 < 0 )
goto error;
V_2 -> V_128 = F_207 ;
F_207 ( V_8 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_2 -> V_241 = V_244 ;
break;
case 0x10ec0282 :
V_2 -> V_241 = V_249 ;
V_2 -> V_130 = F_135 ;
V_2 -> V_128 = F_133 ;
break;
case 0x10ec0233 :
case 0x10ec0283 :
V_2 -> V_241 = V_250 ;
V_2 -> V_130 = F_138 ;
V_2 -> V_128 = F_137 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_2 -> V_241 = V_245 ;
break;
case 0x10ec0285 :
case 0x10ec0293 :
V_2 -> V_241 = V_246 ;
break;
case 0x10ec0286 :
case 0x10ec0288 :
V_2 -> V_241 = V_251 ;
V_2 -> V_130 = F_126 ;
break;
case 0x10ec0255 :
V_2 -> V_241 = V_252 ;
break;
}
if ( F_6 ( V_8 , 0x51 , 0 , V_343 , 0 ) == 0x10ec5505 ) {
V_2 -> V_269 = 1 ;
V_2 -> V_128 = F_143 ;
}
V_121 = F_125 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 && V_2 -> V_77 . V_160 )
F_87 ( V_2 , 0x0b , 0x04 , V_165 ) ;
V_8 -> V_132 = V_166 ;
#ifdef F_210
V_8 -> V_132 . V_344 = F_145 ;
V_8 -> V_132 . V_345 = F_147 ;
#endif
if ( ! V_2 -> V_130 )
V_2 -> V_130 = F_131 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_211 ( struct V_7 * V_8 )
{
static const T_1 V_346 [] = { 0x1d , 0 } ;
static const T_1 V_347 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_77 ( V_8 , V_346 , V_347 ) ;
}
static void F_212 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( V_49 != V_129 )
return;
V_9 = F_104 ( V_8 , 0x0f ) ;
if ( ! ( V_9 & ( V_348 | V_322 ) ) )
V_9 |= V_348 ;
V_9 |= V_205 ;
F_105 ( V_8 , 0x0f , V_9 ) ;
V_2 -> V_77 . V_203 = 1 ;
}
static void F_213 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 )
V_8 -> V_349 = 1 ;
}
static int F_214 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x15 ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_160 = 0x23 ;
F_86 ( V_8 , NULL , V_350 , V_351 ) ;
F_61 ( V_8 , V_50 ) ;
V_121 = F_211 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 )
F_87 ( V_2 , 0x23 , 0 , V_105 ) ;
V_8 -> V_132 = V_166 ;
#ifdef F_210
V_2 -> V_131 = F_65 ;
#endif
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_215 ( struct V_7 * V_8 )
{
static const T_1 V_352 [] = { 0x1d , 0 } ;
static const T_1 V_353 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_352 , V_353 ) ;
}
static void F_216 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_50 ) {
F_217 ( V_8 , 0x18 , 0x00000734 ) ;
F_217 ( V_8 , 0x19 , 0x0000073c ) ;
}
}
static int F_218 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_160 = 0x23 ;
F_86 ( V_8 , NULL , V_354 , V_355 ) ;
F_61 ( V_8 , V_50 ) ;
V_121 = F_215 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 )
F_87 ( V_2 , 0x0b , 0x05 , V_165 ) ;
V_8 -> V_132 = V_166 ;
V_2 -> V_130 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_219 ( struct V_7 * V_8 )
{
static const T_1 V_356 [] = { 0x1d , 0 } ;
static const T_1 V_357 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_358 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_240 ;
if ( V_8 -> V_46 == 0x10ec0272 || V_8 -> V_46 == 0x10ec0663 ||
V_8 -> V_46 == 0x10ec0665 || V_8 -> V_46 == 0x10ec0670 ||
V_8 -> V_46 == 0x10ec0671 )
V_240 = V_357 ;
else
V_240 = V_358 ;
return F_77 ( V_8 , V_356 , V_240 ) ;
}
static void F_220 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 != V_50 )
return;
if ( F_118 ( V_8 , 0x2 , V_105 ,
( 0x3b << V_226 ) |
( 0x3b << V_227 ) |
( 0x03 << V_228 ) |
( 0 << V_229 ) ) )
F_221 ( V_8 , L_31 ) ;
}
static void F_222 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
if ( V_49 == V_127 ) {
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_77 . V_359 [ 0 ] . V_360 [ 0 ] . V_361 = V_362 ;
}
}
static void F_223 ( void * V_284 , int V_285 )
{
struct V_7 * V_8 = V_284 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_303 = V_2 -> V_270 ;
if ( V_285 )
V_2 -> V_270 &= ~ 0x01 ;
else
V_2 -> V_270 |= 0x01 ;
if ( V_2 -> V_270 != V_303 )
F_5 ( V_8 , 0x01 , 0 , V_170 ,
V_2 -> V_270 ) ;
}
static unsigned int F_224 ( struct V_7 * V_8 ,
T_1 V_16 ,
unsigned int V_291 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_16 == V_8 -> V_191 && V_291 == V_292 && V_2 -> V_270 )
return V_294 ;
return V_291 ;
}
static void F_225 ( struct V_7 * V_8 ,
const struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_274 V_304 [] = {
{ 0x01 , V_195 , 0x01 } ,
{ 0x01 , V_196 , 0x01 } ,
{}
} ;
if ( V_49 == V_50 ) {
V_2 -> V_77 . V_299 . V_300 = F_223 ;
V_2 -> V_270 = 0 ;
F_91 ( V_8 , V_304 ) ;
V_8 -> V_302 = F_224 ;
}
}
static void F_226 ( struct V_7 * V_8 )
{
int V_9 , V_272 ;
V_272 = F_38 ( V_8 ) ;
switch ( V_8 -> V_46 ) {
case 0x10ec0662 :
if ( ( V_272 & 0x00f0 ) == 0x0030 ) {
V_9 = F_39 ( V_8 , 0x4 ) ;
F_130 ( V_8 , 0x4 , V_9 & ~ ( 1 << 10 ) ) ;
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
F_130 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
break;
}
}
static int F_227 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_121 ;
V_121 = F_80 ( V_8 , 0x0b ) ;
if ( V_121 < 0 )
return V_121 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_151 = V_271 ;
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
V_2 -> V_128 = F_226 ;
F_226 ( V_8 ) ;
F_86 ( V_8 , V_363 ,
V_364 , V_365 ) ;
F_209 ( V_8 , V_366 , V_365 ) ;
F_61 ( V_8 , V_50 ) ;
F_28 ( V_8 ) ;
if ( F_75 ( V_8 ) )
V_2 -> V_77 . V_160 = 0x01 ;
if ( ( F_38 ( V_8 ) & ( 1 << 14 ) ) &&
V_8 -> V_61 -> V_62 && V_8 -> V_61 -> V_62 -> V_143 == 0x1025 &&
V_2 -> V_51 . V_70 == 1 ) {
V_121 = F_71 ( V_8 , L_32 ) ;
if ( V_121 < 0 )
goto error;
}
V_121 = F_219 ( V_8 ) ;
if ( V_121 < 0 )
goto error;
if ( ! V_2 -> V_77 . V_164 && V_2 -> V_77 . V_160 ) {
switch ( V_8 -> V_46 ) {
case 0x10ec0662 :
F_87 ( V_2 , 0x0b , 0x05 , V_165 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0668 :
F_87 ( V_2 , 0x0b , 0x04 , V_165 ) ;
break;
case 0x10ec0273 :
F_87 ( V_2 , 0x0b , 0x03 , V_165 ) ;
break;
}
}
V_8 -> V_132 = V_166 ;
V_2 -> V_130 = F_21 ;
F_61 ( V_8 , V_55 ) ;
return 0 ;
error:
F_73 ( V_8 ) ;
return V_121 ;
}
static int F_228 ( struct V_7 * V_8 )
{
return F_77 ( V_8 , NULL , NULL ) ;
}
static int F_229 ( struct V_7 * V_8 )
{
int V_121 ;
V_121 = F_80 ( V_8 , 0 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_228 ( V_8 ) ;
if ( V_121 < 0 ) {
F_73 ( V_8 ) ;
return V_121 ;
}
V_8 -> V_132 = V_166 ;
return 0 ;
}
static int T_2 F_230 ( void )
{
return F_231 ( & V_367 ) ;
}
static void T_3 F_232 ( void )
{
F_233 ( & V_367 ) ;
}
