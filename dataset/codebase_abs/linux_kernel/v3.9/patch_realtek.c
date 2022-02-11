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
}
static void F_23 ( struct V_7 * V_8 , int type )
{
unsigned int V_31 ;
F_20 ( V_8 , true ) ;
switch ( type ) {
case V_38 :
F_24 ( V_8 , V_39 ) ;
break;
case V_40 :
F_24 ( V_8 , V_41 ) ;
break;
case V_42 :
F_24 ( V_8 , V_43 ) ;
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
static void F_25 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_50 . V_51 = 1 ;
V_2 -> V_50 . V_52 = V_53 ;
}
}
static int F_26 ( struct V_7 * V_8 )
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
V_54 = F_27 ( V_8 , V_16 ) ;
if ( ! ( V_54 & 1 ) ) {
F_28 ( V_62 L_2 ,
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
F_29 ( L_3 ,
V_16 , V_2 -> V_50 . V_52 ) ;
F_29 ( L_4 ,
V_2 -> V_50 . V_64 ) ;
F_29 ( L_5 , V_2 -> V_50 . V_56 ) ;
F_29 ( L_6 , V_2 -> V_50 . V_65 ) ;
F_29 ( L_7 , V_2 -> V_50 . V_66 ) ;
F_29 ( L_8 , V_2 -> V_50 . V_67 ) ;
F_29 ( L_9 , V_2 -> V_50 . V_68 ) ;
F_29 ( L_10 , V_2 -> V_50 . V_69 ) ;
F_29 ( L_11 , V_2 -> V_50 . V_70 ) ;
return 0 ;
}
static int F_30 ( T_1 V_16 , const T_1 * V_71 , int V_72 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_72 ; V_55 ++ )
if ( V_71 [ V_55 ] == V_16 )
return V_55 ;
return - 1 ;
}
static bool F_31 ( T_1 V_16 , const T_1 * V_71 , int V_72 )
{
return F_30 ( V_16 , V_71 , V_72 ) >= 0 ;
}
static int F_32 ( struct V_7 * V_8 ,
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
V_54 = F_27 ( V_8 , V_16 ) ;
F_29 ( L_12
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
F_29 ( L_14 ,
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
if ( F_31 ( V_16 , V_2 -> V_78 . V_79 . V_81 ,
V_2 -> V_78 . V_79 . V_84 ) )
return 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = V_16 ;
}
return 1 ;
}
static void F_33 ( struct V_7 * V_8 , const T_1 * V_85 )
{
if ( ! F_32 ( V_8 , V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] ) ) {
struct V_1 * V_2 = V_8 -> V_2 ;
F_29 ( L_15
L_16 ) ;
V_2 -> V_77 = V_44 ;
}
}
static int F_34 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
unsigned int V_9 ;
F_5 ( V_8 , 0x20 , 0 , V_11 ,
V_17 ) ;
V_9 = F_6 ( V_8 , 0x20 , 0 ,
V_13 , 0 ) ;
return V_9 ;
}
static void F_35 ( struct V_7 * V_8 , unsigned int V_17 ,
unsigned int V_86 )
{
F_5 ( V_8 , 0x20 , 0 , V_11 ,
V_17 ) ;
F_5 ( V_8 , 0x20 , 0 , V_14 ,
V_86 ) ;
}
static unsigned int F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_87 )
V_2 -> V_87 = F_34 ( V_8 , 0 ) ;
return V_2 -> V_87 ;
}
static T_1 F_37 ( struct V_7 * V_8 , int V_88 , int V_89 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_91 )
V_88 = V_2 -> V_92 [ V_89 ] ;
return V_2 -> V_93 [ V_88 ] ;
}
static void F_38 ( struct V_7 * V_8 , int V_88 )
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
V_98 = F_39 ( V_8 , V_2 -> V_103 ,
F_37 ( V_8 , V_88 , V_55 ) ) ;
V_9 = V_98 -> V_104 [ V_105 ] ;
if ( ! V_9 )
return;
V_16 = F_40 ( V_9 ) ;
V_99 = F_41 ( V_9 ) ;
V_100 = V_106 |
( V_99 == V_107 ? V_108 : V_109 ) ;
F_42 ( V_8 ) ;
V_9 = F_43 ( V_8 , V_16 , 1 , V_99 , 0 ) ;
if ( V_9 & 0x80 )
return;
V_9 |= 0x80 ;
F_5 ( V_8 , V_16 , 0 , V_110 ,
V_100 | V_9 ) ;
}
static void F_44 ( struct V_7 * V_8 , bool V_111 )
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
F_38 ( V_8 , V_112 ) ;
}
}
static void F_45 ( struct V_7 * V_8 ,
struct V_23 * V_118 )
{
F_44 ( V_8 , false ) ;
}
static int F_46 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_47 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_118 -> V_28 . integer . V_28 [ 0 ] = ! V_2 -> V_114 ;
return 0 ;
}
static int F_48 ( struct V_21 * V_119 ,
struct V_23 * V_118 )
{
struct V_7 * V_8 = F_47 ( V_119 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 = ! V_118 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_9 == V_2 -> V_114 )
return 0 ;
V_2 -> V_114 = V_9 ;
F_44 ( V_8 , true ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_8 , T_1 V_16 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_50 ( & V_2 -> V_78 , NULL , & V_120 ) )
return - V_121 ;
V_2 -> V_113 = 1 ;
V_2 -> V_114 = 0 ;
V_2 -> V_103 = V_16 ;
V_2 -> V_78 . V_122 = F_45 ;
return 0 ;
}
static void F_51 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_49 ( V_8 , 0x12 ) ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_55 , V_124 ;
V_124 = F_53 ( V_8 ) ;
if ( V_124 < 0 )
return V_124 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 ; V_55 ++ ) {
V_124 = F_54 ( V_8 , V_2 -> V_6 [ V_55 ] ) ;
if ( V_124 < 0 )
return V_124 ;
}
#ifdef F_55
if ( V_2 -> V_125 ) {
const struct V_3 * V_126 ;
for ( V_126 = V_127 ; V_126 -> V_128 ; V_126 ++ ) {
struct V_21 * V_22 ;
V_22 = F_56 ( V_126 , V_8 ) ;
if ( ! V_22 )
return - V_121 ;
V_22 -> V_129 = V_2 -> V_125 ;
V_124 = F_57 ( V_8 , 0 , V_22 ) ;
if ( V_124 < 0 )
return V_124 ;
}
}
#endif
F_58 ( V_8 , V_130 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_131 )
V_2 -> V_131 ( V_8 ) ;
F_4 ( V_8 ) ;
F_23 ( V_8 , V_2 -> V_77 ) ;
F_60 ( V_8 ) ;
F_58 ( V_8 , V_132 ) ;
return 0 ;
}
static inline void F_61 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 && V_2 -> V_133 )
V_2 -> V_133 ( V_8 ) ;
F_62 ( V_8 ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_2 )
return;
F_64 ( & V_2 -> V_78 ) ;
F_65 ( V_8 ) ;
F_11 ( V_2 ) ;
}
static void F_66 ( struct V_7 * V_8 )
{
F_20 ( V_8 , false ) ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_61 ( V_8 ) ;
if ( V_2 && V_2 -> V_134 )
V_2 -> V_134 ( V_8 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_8 )
{
F_22 ( 150 ) ;
V_8 -> V_135 . V_136 ( V_8 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
F_44 ( V_8 , true ) ;
F_71 ( V_8 , 0x01 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_8 , const char * V_128 )
{
F_11 ( V_8 -> V_63 ) ;
V_8 -> V_63 = F_73 ( V_128 , V_25 ) ;
if ( ! V_8 -> V_63 ) {
F_63 ( V_8 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_74 ( struct V_7 * V_8 )
{
const struct V_137 * V_37 ;
for ( V_37 = V_138 ; V_37 -> V_45 ; V_37 ++ ) {
if ( V_37 -> V_45 != V_8 -> V_45 )
continue;
if ( ( F_36 ( V_8 ) & V_37 -> V_139 ) == V_37 -> V_140 )
return F_72 ( V_8 , V_37 -> V_128 ) ;
}
return 0 ;
}
static inline int F_75 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_141 * V_142 ;
V_142 = F_76 ( V_8 -> V_59 -> V_60 , V_143 ) ;
if ( V_142 )
return V_142 -> V_28 ;
return V_2 -> V_50 . V_56 ;
}
static int F_77 ( struct V_7 * V_8 ,
const T_1 * V_144 ,
const T_1 * V_145 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_146 * V_147 = & V_2 -> V_78 . V_79 ;
int V_124 ;
V_124 = F_78 ( V_8 , V_147 , V_144 ,
V_2 -> V_148 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_145 )
F_33 ( V_8 , V_145 ) ;
V_124 = F_79 ( V_8 , V_147 ) ;
if ( V_124 < 0 )
return V_124 ;
return 1 ;
}
static int F_80 ( struct V_7 * V_8 , T_1 V_149 )
{
struct V_1 * V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
int V_124 ;
if ( ! V_2 )
return - V_121 ;
V_8 -> V_2 = V_2 ;
F_81 ( & V_2 -> V_78 ) ;
V_2 -> V_78 . V_149 = V_149 ;
V_2 -> V_78 . V_150 = 1 ;
V_8 -> V_151 = 1 ;
V_8 -> V_152 = 1 ;
V_124 = F_74 ( V_8 ) ;
if ( V_124 < 0 ) {
F_11 ( V_2 ) ;
return V_124 ;
}
return 0 ;
}
static int F_82 ( struct V_7 * V_8 )
{
static const T_1 V_153 [] = { 0x1d , 0 } ;
static const T_1 V_154 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_153 , V_154 ) ;
}
static void F_83 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_123 )
F_84 ( V_8 , 0x21 , V_155 , F_8 ) ;
}
static int F_85 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_156 = 1 ;
F_86 ( V_8 , V_157 , V_158 ,
V_159 ) ;
F_58 ( V_8 , V_49 ) ;
V_124 = F_82 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x0b , 0x05 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
V_8 -> V_135 . V_163 = F_12 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_89 ( struct V_7 * V_8 )
{
static const T_1 V_164 [] = { 0x17 , 0 } ;
static const T_1 V_165 [] = { 0x10 , 0x15 , 0x0f , 0 } ;
return F_77 ( V_8 , V_164 , V_165 ) ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_5 ( V_8 , 0x01 , 0 , V_166 ,
V_2 -> V_78 . V_167 ) ;
}
static void F_91 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
V_2 -> V_78 . V_168 = F_90 ;
V_2 -> V_78 . V_169 = 1 ;
V_2 -> V_78 . V_170 = 1 ;
V_2 -> V_78 . V_79 . V_80 [ 0 ] = 0x0f ;
F_84 ( V_8 , 0x0f , V_171 ,
V_172 ) ;
F_92 ( V_8 , V_39 ) ;
}
}
static void F_93 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static const struct V_173 V_174 [] = {
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
F_94 ( V_8 , V_174 ) ;
break;
case V_123 :
V_2 -> V_77 = V_175 ;
break;
}
}
static void F_95 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
switch ( V_48 ) {
case V_49 :
V_2 -> V_78 . V_176 = 1 ;
break;
case V_123 :
V_2 -> V_77 = V_175 ;
break;
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
V_2 -> V_78 . V_177 = 1 ;
F_86 ( V_8 , NULL , V_178 , V_179 ) ;
F_58 ( V_8 , V_49 ) ;
V_124 = F_89 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x07 , 0x05 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
V_2 -> V_133 = F_21 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static void F_97 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_132 )
return;
F_15 ( V_8 ) ;
}
static void F_98 ( struct V_7 * V_8 , int V_180 , int V_181 )
{
unsigned int V_182 , V_183 , V_184 ;
V_182 = F_6 ( V_8 , V_8 -> V_185 , 0 ,
V_186 , 0 ) ;
if ( ! V_181 )
V_182 |= ( 1 << V_180 ) ;
else
V_182 &= ~ ( 1 << V_180 ) ;
V_183 = F_6 ( V_8 , V_8 -> V_185 , 0 ,
V_187 , 0 ) ;
V_183 |= ( 1 << V_180 ) ;
V_184 = F_6 ( V_8 , V_8 -> V_185 , 0 ,
V_188 , 0 ) ;
V_184 |= ( 1 << V_180 ) ;
F_5 ( V_8 , V_8 -> V_185 , 0 ,
V_189 , V_183 ) ;
F_5 ( V_8 , V_8 -> V_185 , 0 ,
V_190 , V_184 ) ;
F_22 ( 1 ) ;
F_5 ( V_8 , V_8 -> V_185 , 0 ,
V_166 , V_182 ) ;
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
T_1 V_191 [ 2 ] = { 0x0c , 0x0d } ;
T_1 V_192 [ 2 ] = { 0x0e , 0x0f } ;
F_101 ( V_8 , 0x14 , 2 , V_191 ) ;
F_101 ( V_8 , 0x15 , 2 , V_191 ) ;
F_101 ( V_8 , 0x18 , 2 , V_192 ) ;
F_101 ( V_8 , 0x1a , 2 , V_192 ) ;
} else if ( V_48 == V_123 ) {
T_1 V_193 [ 5 ] = { 0x0c , 0x0d , 0x0e , 0x0f , 0x26 } ;
F_101 ( V_8 , 0x14 , 5 , V_193 ) ;
F_101 ( V_8 , 0x15 , 5 , V_193 ) ;
F_101 ( V_8 , 0x18 , 5 , V_193 ) ;
F_101 ( V_8 , 0x1a , 5 , V_193 ) ;
}
}
static void F_102 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_194 [ 2 ] = { 0x14 , 0x15 } ;
int V_55 ;
if ( V_48 != V_132 )
return;
for ( V_55 = 0 ; V_55 < F_3 ( V_194 ) ; V_55 ++ ) {
unsigned int V_9 = F_27 ( V_8 , V_194 [ V_55 ] ) ;
if ( F_103 ( V_9 ) != V_195 )
continue;
V_9 = F_104 ( V_8 , V_194 [ V_55 ] ) ;
V_9 |= V_196 ;
F_105 ( V_8 , V_194 [ V_55 ] , V_9 ) ;
V_2 -> V_78 . V_197 = 1 ;
break;
}
}
static void F_106 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
static T_1 V_194 [ 2 ] = { 0x18 , 0x1a } ;
int V_55 ;
if ( V_48 != V_132 )
return;
for ( V_55 = 0 ; V_55 < F_3 ( V_194 ) ; V_55 ++ ) {
unsigned int V_9 ;
V_9 = F_104 ( V_8 , V_194 [ V_55 ] ) ;
V_9 |= V_198 ;
F_105 ( V_8 , V_194 [ V_55 ] , V_9 ) ;
}
V_2 -> V_78 . V_197 = 1 ;
}
static void F_107 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_78 . V_199 = 1 ;
}
static int F_108 ( struct V_7 * V_8 )
{
static const T_1 V_200 [] = { 0x1d , 0 } ;
static const T_1 V_201 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_200 , V_201 ) ;
}
static int F_109 ( struct V_7 * V_8 )
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
F_86 ( V_8 , V_202 , V_203 ,
V_204 ) ;
F_58 ( V_8 , V_49 ) ;
F_26 ( V_8 ) ;
V_124 = F_108 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 && F_75 ( V_8 ) ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x0b , 0x05 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_110 ( struct V_7 * V_8 )
{
static const T_1 V_205 [] = { 0x1d , 0 } ;
static const T_1 V_206 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_205 , V_206 ) ;
}
static int F_111 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_207 = 0x18 ;
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
F_86 ( V_8 , V_208 , V_209 ,
V_210 ) ;
F_58 ( V_8 , V_49 ) ;
F_26 ( V_8 ) ;
V_124 = F_110 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 && F_75 ( V_8 ) ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x0b , 0x05 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
V_2 -> V_133 = F_21 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_112 ( struct V_7 * V_8 )
{
static const T_1 V_211 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_124 = F_77 ( V_8 , NULL , V_211 ) ;
if ( V_124 > 0 ) {
if ( ! V_2 -> V_78 . V_160 &&
V_2 -> V_78 . V_79 . V_212 [ 0 ] != 0x1d ) {
F_1 ( V_2 , V_213 ) ;
F_92 ( V_8 , V_214 ) ;
}
}
return V_124 ;
}
static int F_113 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_55 , V_215 , V_124 ;
V_124 = F_80 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
F_86 ( V_8 , V_216 , V_217 , V_218 ) ;
F_58 ( V_8 , V_49 ) ;
V_124 = F_112 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
V_215 = 0 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 ; V_55 ++ ) {
if ( V_2 -> V_6 [ V_55 ] == V_213 ) {
V_215 = 1 ;
break;
}
}
if ( V_215 ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
if ( ! F_114 ( V_8 , 0x1d , V_161 ) )
F_115 ( V_8 , 0x1d , V_161 ,
( 0x0c << V_219 ) |
( 0x0c << V_220 ) |
( 0x07 << V_221 ) |
( 0 << V_222 ) ) ;
}
V_8 -> V_135 = V_162 ;
V_2 -> V_133 = F_21 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_116 ( struct V_223 * V_224 ,
struct V_7 * V_8 ,
struct V_225 * V_226 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_117 ( V_8 , & V_2 -> V_227 , V_226 ,
V_224 ) ;
}
static int F_118 ( struct V_223 * V_224 ,
struct V_7 * V_8 ,
unsigned int V_228 ,
unsigned int V_229 ,
struct V_225 * V_226 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_119 ( V_8 , & V_2 -> V_227 ,
V_228 , V_229 , V_226 ) ;
}
static int F_120 ( struct V_223 * V_224 ,
struct V_7 * V_8 ,
struct V_225 * V_226 )
{
struct V_90 * V_2 = V_8 -> V_2 ;
return F_121 ( V_8 , & V_2 -> V_227 ) ;
}
static int F_122 ( struct V_7 * V_8 )
{
static const T_1 V_230 [] = { 0x1d , 0 } ;
static const T_1 V_231 [] = { 0 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_232 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
struct V_1 * V_2 = V_8 -> V_2 ;
const T_1 * V_233 ;
switch ( V_2 -> V_234 ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
V_233 = V_232 ;
break;
case V_239 :
case V_240 :
case V_241 :
V_233 = V_231 ;
break;
default:
V_233 = V_231 ;
break;
}
return F_77 ( V_8 , V_230 , V_233 ) ;
}
static void F_123 ( struct V_7 * V_8 , int V_242 )
{
int V_9 = F_34 ( V_8 , 0x04 ) ;
if ( V_242 )
V_9 |= 1 << 11 ;
else
V_9 &= ~ ( 1 << 11 ) ;
F_35 ( V_8 , 0x04 , V_9 ) ;
}
static void F_124 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_234 != V_239 )
return;
if ( V_2 -> V_234 == V_239 )
F_123 ( V_8 , 0 ) ;
if ( V_2 -> V_234 == V_239 &&
( F_36 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_2 -> V_234 == V_239 )
F_123 ( V_8 , 0 ) ;
if ( V_2 -> V_234 == V_239 &&
( F_36 ( V_8 ) & 0x00ff ) == 0x018 ) {
F_22 ( 150 ) ;
}
V_8 -> V_135 . V_136 ( V_8 ) ;
if ( V_2 -> V_234 == V_239 )
F_123 ( V_8 , 1 ) ;
if ( V_2 -> V_234 == V_239 &&
( F_36 ( V_8 ) & 0x00ff ) == 0x017 ) {
F_22 ( 200 ) ;
}
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 , 0x01 ) ;
return 0 ;
}
static void F_126 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 )
V_2 -> V_148 = V_243 ;
}
static void F_127 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_244 ;
if ( V_48 != V_132 )
return;
V_244 = F_34 ( V_8 , 0x1e ) ;
F_35 ( V_8 , 0x1e , V_244 | 0x80 ) ;
}
static void F_128 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
static const struct V_245 V_246 [] = {
{ 0x20 , V_11 , 0x0d } ,
{ 0x20 , V_14 , 0x4000 } ,
{}
} ;
unsigned int V_147 ;
if ( strcmp ( V_8 -> V_63 , L_17 ) )
return;
V_147 = F_27 ( V_8 , 0x12 ) ;
if ( F_129 ( V_147 ) == V_247 )
F_24 ( V_8 , V_246 ) ;
}
static void F_130 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_248 = & V_249 ;
V_2 -> V_78 . V_250 = & V_251 ;
}
static void F_131 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
int V_244 ;
if ( V_48 != V_132 )
return;
V_244 = F_34 ( V_8 , 0x07 ) ;
F_35 ( V_8 , 0x07 , V_244 | 0x80 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_133 ( V_8 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x680 ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_11 , 0x0c ) ;
F_5 ( V_8 , 0x20 , 0 ,
V_14 , 0x480 ) ;
}
static void F_134 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 != V_123 )
return;
V_2 -> V_78 . V_168 = F_132 ;
}
static void F_135 ( void * V_252 , int V_253 )
{
struct V_7 * V_8 = V_252 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_254 ;
if ( V_2 -> V_255 )
V_253 = ! V_253 ;
V_254 = V_256 |
( V_253 ? V_257 : V_196 ) ;
if ( V_2 -> V_258 )
F_136 ( V_8 , V_2 -> V_258 , V_254 ) ;
}
static void F_137 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_259 * V_260 = NULL ;
if ( V_48 != V_49 )
return;
while ( ( V_260 = F_138 ( V_261 , NULL , V_260 ) ) ) {
int V_262 , V_180 ;
if ( sscanf ( V_260 -> V_128 , L_18 , & V_262 , & V_180 ) != 2 )
continue;
if ( V_180 < 0x0a || V_180 >= 0x10 )
break;
V_2 -> V_255 = V_262 ;
V_2 -> V_258 = V_180 - 0x0a + 0x18 ;
V_2 -> V_78 . V_263 . V_264 = F_135 ;
V_2 -> V_78 . V_265 = 1 ;
F_29 ( L_19 , V_2 -> V_258 ,
V_2 -> V_255 ) ;
break;
}
}
static void F_139 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_255 = 0 ;
V_2 -> V_258 = 0x18 ;
V_2 -> V_78 . V_263 . V_264 = F_135 ;
V_2 -> V_78 . V_265 = 1 ;
}
}
static void F_140 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_49 ) {
V_2 -> V_255 = 0 ;
V_2 -> V_258 = 0x19 ;
V_2 -> V_78 . V_263 . V_264 = F_135 ;
V_2 -> V_78 . V_265 = 1 ;
}
}
static void F_141 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( V_48 == V_123 ) {
if ( F_2 ( ! V_2 -> V_78 . V_266 [ 1 ] . V_180 ||
! V_2 -> V_78 . V_79 . V_80 [ 0 ] ) )
return;
F_142 ( V_8 , V_2 -> V_78 . V_266 [ 1 ] . V_180 ,
V_2 -> V_78 . V_79 . V_80 [ 0 ] ) ;
}
}
static void F_143 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 ;
if ( V_2 -> V_234 != V_239 )
return;
if ( ( F_36 ( V_8 ) & 0x00ff ) < 0x015 ) {
F_35 ( V_8 , 0xf , 0x960b ) ;
F_35 ( V_8 , 0xe , 0x8817 ) ;
}
if ( ( F_36 ( V_8 ) & 0x00ff ) == 0x016 ) {
F_35 ( V_8 , 0xf , 0x960b ) ;
F_35 ( V_8 , 0xe , 0x8814 ) ;
}
if ( ( F_36 ( V_8 ) & 0x00ff ) == 0x017 ) {
V_9 = F_34 ( V_8 , 0x04 ) ;
F_35 ( V_8 , 0x04 , V_9 | ( 1 << 11 ) ) ;
}
if ( ( F_36 ( V_8 ) & 0x00ff ) == 0x018 ) {
V_9 = F_34 ( V_8 , 0xd ) ;
if ( ( V_9 & 0x0c00 ) >> 10 != 0x1 ) {
F_35 ( V_8 , 0xd , V_9 | ( 1 << 10 ) ) ;
}
V_9 = F_34 ( V_8 , 0x17 ) ;
if ( ( V_9 & 0x01c0 ) >> 6 != 0x4 ) {
F_35 ( V_8 , 0x17 , V_9 | ( 1 << 7 ) ) ;
}
}
V_9 = F_34 ( V_8 , 0xd ) ;
F_35 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
V_9 = F_34 ( V_8 , 0x4 ) ;
F_35 ( V_8 , 0x4 , V_9 | ( 1 << 11 ) ) ;
}
static int F_144 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_78 . V_207 = 0x18 ;
F_86 ( V_8 , V_267 ,
V_268 , V_269 ) ;
F_58 ( V_8 , V_49 ) ;
F_26 ( V_8 ) ;
switch ( V_8 -> V_45 ) {
case 0x10ec0269 :
V_2 -> V_234 = V_235 ;
switch ( F_36 ( V_8 ) & 0x00f0 ) {
case 0x0010 :
if ( V_8 -> V_59 -> V_60 -> V_270 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 )
V_124 = F_72 ( V_8 , L_17 ) ;
V_2 -> V_234 = V_239 ;
break;
case 0x0020 :
if ( V_8 -> V_59 -> V_60 -> V_270 == 0x17aa &&
V_8 -> V_59 -> V_60 -> V_61 == 0x21f3 )
V_124 = F_72 ( V_8 , L_20 ) ;
V_2 -> V_234 = V_236 ;
break;
case 0x0030 :
V_2 -> V_234 = V_240 ;
break;
default:
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
}
if ( V_124 < 0 )
goto error;
V_2 -> V_131 = F_143 ;
F_143 ( V_8 ) ;
break;
case 0x10ec0280 :
case 0x10ec0290 :
V_2 -> V_234 = V_237 ;
break;
case 0x10ec0233 :
case 0x10ec0282 :
case 0x10ec0283 :
V_2 -> V_234 = V_241 ;
break;
case 0x10ec0284 :
case 0x10ec0292 :
V_2 -> V_234 = V_238 ;
break;
}
V_124 = F_122 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 && F_75 ( V_8 ) ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x0b , 0x04 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
#ifdef F_145
V_8 -> V_135 . V_271 = F_125 ;
#endif
V_2 -> V_133 = F_124 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_146 ( struct V_7 * V_8 )
{
static const T_1 V_272 [] = { 0x1d , 0 } ;
static const T_1 V_273 [] = { 0x0e , 0x0f , 0x0b , 0 } ;
return F_77 ( V_8 , V_272 , V_273 ) ;
}
static void F_147 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_9 ;
if ( V_48 != V_132 )
return;
V_9 = F_104 ( V_8 , 0x0f ) ;
if ( ! ( V_9 & ( V_256 | V_274 ) ) )
V_9 |= V_256 ;
V_9 |= V_198 ;
F_105 ( V_8 , 0x0f , V_9 ) ;
V_2 -> V_78 . V_197 = 1 ;
}
static void F_148 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 )
V_8 -> V_275 = 1 ;
}
static int F_149 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x15 ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
F_86 ( V_8 , NULL , V_276 , V_277 ) ;
F_58 ( V_8 , V_49 ) ;
V_124 = F_146 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 ) {
V_124 = F_87 ( V_8 , 0x23 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x23 , 0 , V_107 ) ;
}
V_8 -> V_135 = V_162 ;
#ifdef F_145
V_2 -> V_134 = F_66 ;
#endif
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_150 ( struct V_7 * V_8 )
{
static const T_1 V_278 [] = { 0x1d , 0 } ;
static const T_1 V_279 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
return F_77 ( V_8 , V_278 , V_279 ) ;
}
static void F_151 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 == V_49 ) {
F_152 ( V_8 , 0x18 , 0x00000734 ) ;
F_152 ( V_8 , 0x19 , 0x0000073c ) ;
}
}
static int F_153 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
F_86 ( V_8 , NULL , V_280 , V_281 ) ;
F_58 ( V_8 , V_49 ) ;
V_124 = F_150 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 ) {
V_124 = F_87 ( V_8 , 0x23 ) ;
if ( V_124 < 0 )
goto error;
F_88 ( V_2 , 0x0b , 0x05 , V_161 ) ;
}
V_8 -> V_135 = V_162 ;
V_2 -> V_133 = F_21 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_154 ( struct V_7 * V_8 )
{
static const T_1 V_282 [] = { 0x1d , 0 } ;
static const T_1 V_283 [] = { 0x15 , 0x1b , 0x14 , 0x21 } ;
static const T_1 V_284 [] = { 0x15 , 0x1b , 0x14 , 0 } ;
const T_1 * V_233 ;
if ( V_8 -> V_45 == 0x10ec0272 || V_8 -> V_45 == 0x10ec0663 ||
V_8 -> V_45 == 0x10ec0665 || V_8 -> V_45 == 0x10ec0670 ||
V_8 -> V_45 == 0x10ec0671 )
V_233 = V_283 ;
else
V_233 = V_284 ;
return F_77 ( V_8 , V_282 , V_233 ) ;
}
static void F_155 ( struct V_7 * V_8 ,
const struct V_46 * V_47 , int V_48 )
{
if ( V_48 != V_49 )
return;
if ( F_115 ( V_8 , 0x2 , V_107 ,
( 0x3b << V_219 ) |
( 0x3b << V_220 ) |
( 0x03 << V_221 ) |
( 0 << V_222 ) ) )
F_28 ( V_285
L_21 ) ;
}
static void F_156 ( struct V_7 * V_8 )
{
int V_9 , V_244 ;
V_244 = F_36 ( V_8 ) ;
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
if ( ( V_244 & 0x00f0 ) == 0x0030 ) {
V_9 = F_34 ( V_8 , 0x4 ) ;
F_35 ( V_8 , 0x4 , V_9 & ~ ( 1 << 10 ) ) ;
}
break;
case 0x10ec0272 :
case 0x10ec0273 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0670 :
case 0x10ec0671 :
case 0x10ec0672 :
V_9 = F_34 ( V_8 , 0xd ) ;
F_35 ( V_8 , 0xd , V_9 | ( 1 << 14 ) ) ;
break;
}
}
static int F_157 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_124 ;
V_124 = F_80 ( V_8 , 0x0b ) ;
if ( V_124 < 0 )
return V_124 ;
V_2 = V_8 -> V_2 ;
V_2 -> V_148 = V_243 ;
F_7 ( V_8 , 0x20 , 0x04 , 15 ) ;
V_2 -> V_131 = F_156 ;
F_156 ( V_8 ) ;
F_86 ( V_8 , V_286 ,
V_287 , V_288 ) ;
F_58 ( V_8 , V_49 ) ;
F_26 ( V_8 ) ;
if ( ( F_36 ( V_8 ) & ( 1 << 14 ) ) &&
V_8 -> V_59 -> V_60 -> V_270 == 0x1025 &&
V_2 -> V_50 . V_68 == 1 ) {
if ( F_72 ( V_8 , L_22 ) < 0 )
goto error;
}
V_124 = F_154 ( V_8 ) ;
if ( V_124 < 0 )
goto error;
if ( ! V_2 -> V_78 . V_160 && F_75 ( V_8 ) ) {
V_124 = F_87 ( V_8 , 0x1 ) ;
if ( V_124 < 0 )
goto error;
switch ( V_8 -> V_45 ) {
case 0x10ec0662 :
F_88 ( V_2 , 0x0b , 0x05 , V_161 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_88 ( V_2 , 0x0b , 0x04 , V_161 ) ;
break;
case 0x10ec0273 :
F_88 ( V_2 , 0x0b , 0x03 , V_161 ) ;
break;
}
}
V_8 -> V_135 = V_162 ;
V_2 -> V_133 = F_21 ;
F_58 ( V_8 , V_123 ) ;
return 0 ;
error:
F_63 ( V_8 ) ;
return V_124 ;
}
static int F_158 ( struct V_7 * V_8 )
{
return F_77 ( V_8 , NULL , NULL ) ;
}
static int F_159 ( struct V_7 * V_8 )
{
int V_124 ;
V_124 = F_80 ( V_8 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_158 ( V_8 ) ;
if ( V_124 < 0 ) {
F_63 ( V_8 ) ;
return V_124 ;
}
V_8 -> V_135 = V_162 ;
return 0 ;
}
static int T_2 F_160 ( void )
{
return F_161 ( & V_289 ) ;
}
static void T_3 F_162 ( void )
{
F_163 ( & V_289 ) ;
}
