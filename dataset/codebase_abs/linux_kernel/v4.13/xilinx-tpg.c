static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static T_1 F_3 ( unsigned int V_5 )
{
switch ( V_5 ) {
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
default:
return V_14 ;
}
}
static void F_4 ( struct V_1 * V_15 ,
bool V_16 , bool V_17 )
{
T_1 V_18 = ( 1 << ( V_15 -> V_17 -> V_19 + 1 ) ) - 1 ;
if ( V_15 -> V_20 == 1 || ! V_15 -> V_21 )
V_16 = false ;
if ( V_16 )
V_18 &= ~ 1 ;
if ( V_17 )
V_18 &= 1 ;
F_5 ( V_15 -> V_17 , 0 , V_15 -> V_17 -> V_19 ,
V_18 , V_17 ? 9 : 0 ) ;
}
static void F_6 ( struct V_1 * V_15 ,
bool V_16 , bool V_17 )
{
F_7 ( V_15 -> V_22 . V_23 ) ;
F_4 ( V_15 , V_16 , V_17 ) ;
F_8 ( V_15 -> V_22 . V_23 ) ;
}
static int F_9 ( struct V_2 * V_3 , int V_24 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned int V_25 = V_15 -> V_26 [ 0 ] . V_25 ;
unsigned int V_27 = V_15 -> V_26 [ 0 ] . V_27 ;
bool V_16 ;
T_1 V_28 ;
if ( ! V_24 ) {
F_10 ( & V_15 -> V_4 ) ;
if ( V_15 -> V_29 )
F_11 ( V_15 -> V_29 ) ;
F_6 ( V_15 , true , true ) ;
V_15 -> V_30 = false ;
return 0 ;
}
F_12 ( & V_15 -> V_4 , & V_15 -> V_26 [ 0 ] ) ;
if ( V_15 -> V_29 ) {
struct V_31 V_32 = {
. V_33 = V_25 ,
. V_34 = V_25 + 1 ,
. V_35 = V_27 ,
. V_36 = V_27 + 1 ,
} ;
unsigned int V_37 ;
unsigned int V_38 ;
V_37 = F_13 (unsigned int, XVTC_MAX_HSIZE,
v4l2_ctrl_g_ctrl(xtpg->hblank) + width) ;
V_38 = F_13 (unsigned int, XVTC_MAX_VSIZE,
v4l2_ctrl_g_ctrl(xtpg->vblank) + height) ;
V_32 . V_39 = V_37 - 1 ;
V_32 . V_40 = V_37 ;
V_32 . V_41 = V_38 - 1 ;
V_32 . V_42 = V_38 ;
F_14 ( V_15 -> V_29 , & V_32 ) ;
}
F_7 ( V_15 -> V_22 . V_23 ) ;
F_15 ( & V_15 -> V_4 , V_43 ,
V_44 , V_15 -> V_17 -> V_45 . V_46 ) ;
V_16 = V_15 -> V_17 -> V_45 . V_46 == 0 ;
F_4 ( V_15 , V_16 , ! V_16 ) ;
V_15 -> V_30 = true ;
F_8 ( V_15 -> V_22 . V_23 ) ;
V_28 = V_16 ? V_14
: F_3 ( V_15 -> V_26 [ 0 ] . V_5 ) ;
F_16 ( & V_15 -> V_4 , V_47 , V_28 ) ;
if ( V_15 -> V_48 )
F_17 ( V_15 -> V_48 , ! V_16 ) ;
F_18 ( & V_15 -> V_4 ) ;
return 0 ;
}
static struct V_49 *
F_19 ( struct V_1 * V_15 ,
struct V_50 * V_51 ,
unsigned int V_52 , T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
return F_20 ( & V_15 -> V_4 . V_3 , V_51 , V_52 ) ;
case V_55 :
return & V_15 -> V_26 [ V_52 ] ;
default:
return NULL ;
}
}
static int F_21 ( struct V_2 * V_3 ,
struct V_50 * V_51 ,
struct V_56 * V_57 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
V_57 -> V_58 = * F_19 ( V_15 , V_51 , V_57 -> V_52 , V_57 -> V_53 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_50 * V_51 ,
struct V_56 * V_57 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_49 * V_59 ;
T_1 V_28 ;
V_59 = F_19 ( V_15 , V_51 , V_57 -> V_52 , V_57 -> V_53 ) ;
if ( V_15 -> V_20 == 2 && V_57 -> V_52 == 1 ) {
V_57 -> V_58 = * V_59 ;
return 0 ;
}
if ( V_15 -> V_60 ) {
V_28 = F_3 ( V_57 -> V_58 . V_5 ) ;
if ( V_28 != V_14 )
V_59 -> V_5 = V_57 -> V_58 . V_5 ;
}
F_23 ( V_59 , V_57 ) ;
V_57 -> V_58 = * V_59 ;
if ( V_15 -> V_20 == 2 ) {
V_59 = F_19 ( V_15 , V_51 , 1 , V_57 -> V_53 ) ;
* V_59 = V_57 -> V_58 ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_50 * V_51 ,
struct V_61 * V_62 )
{
struct V_49 * V_58 ;
V_58 = F_20 ( V_3 , V_51 , V_62 -> V_52 ) ;
if ( V_62 -> V_63 || V_62 -> V_5 != V_58 -> V_5 )
return - V_64 ;
if ( V_62 -> V_52 == 0 ) {
V_62 -> V_65 = V_66 ;
V_62 -> V_67 = V_68 ;
V_62 -> V_69 = V_70 ;
V_62 -> V_71 = V_72 ;
} else {
V_62 -> V_65 = V_58 -> V_25 ;
V_62 -> V_67 = V_58 -> V_25 ;
V_62 -> V_69 = V_58 -> V_27 ;
V_62 -> V_71 = V_58 -> V_27 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_73 * V_74 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_49 * V_58 ;
V_58 = F_20 ( V_3 , V_74 -> V_52 , 0 ) ;
* V_58 = V_15 -> V_75 ;
if ( V_15 -> V_20 == 2 ) {
V_58 = F_20 ( V_3 , V_74 -> V_52 , 1 ) ;
* V_58 = V_15 -> V_75 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_73 * V_74 )
{
return 0 ;
}
static int F_27 ( struct V_76 * V_77 )
{
struct V_1 * V_15 = F_2 ( V_77 -> V_78 ,
struct V_1 ,
V_22 ) ;
switch ( V_77 -> V_79 ) {
case V_80 :
F_15 ( & V_15 -> V_4 , V_43 ,
V_44 , V_77 -> V_46 ) ;
return 0 ;
case V_81 :
F_28 ( & V_15 -> V_4 , V_43 ,
V_82 , V_77 -> V_46 ) ;
return 0 ;
case V_83 :
F_28 ( & V_15 -> V_4 , V_43 ,
V_84 , V_77 -> V_46 ) ;
return 0 ;
case V_85 :
F_15 ( & V_15 -> V_4 , V_43 ,
V_86 ,
V_77 -> V_46 <<
V_87 ) ;
return 0 ;
case V_88 :
F_28 ( & V_15 -> V_4 , V_43 ,
V_89 , V_77 -> V_46 ) ;
return 0 ;
case V_90 :
F_28 ( & V_15 -> V_4 , V_43 ,
V_91 , V_77 -> V_46 ) ;
return 0 ;
case V_92 :
F_28 ( & V_15 -> V_4 , V_43 ,
V_93 , V_77 -> V_46 ) ;
return 0 ;
case V_94 :
F_16 ( & V_15 -> V_4 , V_95 , V_77 -> V_46 ) ;
return 0 ;
case V_96 :
F_15 ( & V_15 -> V_4 , V_97 ,
V_98 ,
V_77 -> V_46 << V_99 ) ;
return 0 ;
case V_100 :
F_15 ( & V_15 -> V_4 , V_97 ,
V_101 ,
V_77 -> V_46 << V_102 ) ;
return 0 ;
case V_103 :
F_15 ( & V_15 -> V_4 , V_104 ,
V_105 ,
V_77 -> V_46 << V_106 ) ;
return 0 ;
case V_107 :
F_15 ( & V_15 -> V_4 , V_104 ,
V_108 ,
V_77 -> V_46 << V_109 ) ;
return 0 ;
case V_110 :
F_15 ( & V_15 -> V_4 , V_111 ,
V_105 ,
V_77 -> V_46 << V_106 ) ;
return 0 ;
case V_112 :
F_15 ( & V_15 -> V_4 , V_111 ,
V_108 ,
V_77 -> V_46 << V_109 ) ;
return 0 ;
case V_113 :
F_16 ( & V_15 -> V_4 , V_114 , V_77 -> V_46 ) ;
return 0 ;
case V_115 :
F_16 ( & V_15 -> V_4 , V_116 , V_77 -> V_46 ) ;
return 0 ;
case V_117 :
F_16 ( & V_15 -> V_4 , V_118 , V_77 -> V_46 ) ;
return 0 ;
case V_119 :
F_16 ( & V_15 -> V_4 , V_120 , V_77 -> V_46 ) ;
return 0 ;
}
return 0 ;
}
static int T_2 F_29 ( struct V_121 * V_122 )
{
struct V_1 * V_15 = F_30 ( V_122 ) ;
F_31 ( & V_15 -> V_4 ) ;
return 0 ;
}
static int T_2 F_32 ( struct V_121 * V_122 )
{
struct V_1 * V_15 = F_30 ( V_122 ) ;
F_33 ( & V_15 -> V_4 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_15 )
{
struct V_121 * V_122 = V_15 -> V_4 . V_122 ;
struct V_123 * V_124 = V_15 -> V_4 . V_122 -> V_125 ;
struct V_123 * V_126 ;
struct V_123 * V_127 ;
unsigned int V_128 = 0 ;
bool V_129 = false ;
V_126 = F_35 ( V_124 , L_1 ) ;
if ( V_126 == NULL )
V_126 = V_124 ;
F_36 (ports, port) {
const struct V_130 * V_58 ;
struct V_123 * V_131 ;
if ( ! V_127 -> V_132 || F_37 ( V_127 -> V_132 , L_2 ) )
continue;
V_58 = F_38 ( V_127 ) ;
if ( F_39 ( V_58 ) ) {
F_40 ( V_122 , L_3 ) ;
F_41 ( V_127 ) ;
return F_42 ( V_58 ) ;
}
if ( ! V_15 -> V_133 ) {
V_15 -> V_133 = V_58 ;
} else if ( V_15 -> V_133 != V_58 ) {
F_40 ( V_122 , L_4 ) ;
F_41 ( V_127 ) ;
return - V_64 ;
}
if ( V_128 == 0 ) {
V_131 = F_43 ( V_127 , NULL ) ;
if ( V_131 )
V_129 = true ;
F_41 ( V_131 ) ;
}
V_128 ++ ;
}
if ( V_128 != 1 && V_128 != 2 ) {
F_40 ( V_122 , L_5 , V_128 ) ;
return - V_64 ;
}
V_15 -> V_20 = V_128 ;
if ( V_128 == 2 && V_129 )
V_15 -> V_21 = true ;
return 0 ;
}
static int F_44 ( struct V_134 * V_135 )
{
struct V_2 * V_3 ;
struct V_1 * V_15 ;
T_1 V_136 , V_28 ;
int V_137 ;
V_15 = F_45 ( & V_135 -> V_122 , sizeof( * V_15 ) , V_138 ) ;
if ( ! V_15 )
return - V_139 ;
V_15 -> V_4 . V_122 = & V_135 -> V_122 ;
V_137 = F_34 ( V_15 ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_46 ( & V_15 -> V_4 ) ;
if ( V_137 < 0 )
return V_137 ;
V_15 -> V_48 = F_47 ( & V_135 -> V_122 , L_6 ,
V_140 ) ;
if ( F_39 ( V_15 -> V_48 ) ) {
V_137 = F_42 ( V_15 -> V_48 ) ;
goto V_141;
}
V_15 -> V_29 = F_48 ( V_135 -> V_122 . V_125 ) ;
if ( F_39 ( V_15 -> V_29 ) ) {
V_137 = F_42 ( V_15 -> V_29 ) ;
goto V_141;
}
F_49 ( & V_15 -> V_4 ) ;
if ( V_15 -> V_20 == 2 ) {
V_15 -> V_142 [ 0 ] . V_143 = V_144 ;
V_15 -> V_142 [ 1 ] . V_143 = V_145 ;
} else {
V_15 -> V_142 [ 0 ] . V_143 = V_145 ;
}
V_15 -> V_75 . V_5 = V_15 -> V_133 -> V_5 ;
V_15 -> V_75 . V_146 = V_147 ;
V_15 -> V_75 . V_148 = V_149 ;
F_50 ( & V_15 -> V_4 , & V_15 -> V_75 ) ;
V_28 = F_3 ( V_15 -> V_133 -> V_5 ) ;
if ( V_28 != V_14 )
V_15 -> V_60 = true ;
V_15 -> V_26 [ 0 ] = V_15 -> V_75 ;
if ( V_15 -> V_20 == 2 )
V_15 -> V_26 [ 1 ] = V_15 -> V_75 ;
V_3 = & V_15 -> V_4 . V_3 ;
F_51 ( V_3 , & V_150 ) ;
V_3 -> V_122 = & V_135 -> V_122 ;
V_3 -> V_151 = & V_152 ;
F_52 ( V_3 -> V_132 , F_53 ( & V_135 -> V_122 ) , sizeof( V_3 -> V_132 ) ) ;
F_54 ( V_3 , V_15 ) ;
V_3 -> V_143 |= V_153 ;
V_3 -> V_154 . V_155 = & V_156 ;
V_137 = F_55 ( & V_3 -> V_154 , V_15 -> V_20 , V_15 -> V_142 ) ;
if ( V_137 < 0 )
goto error;
F_56 ( & V_15 -> V_22 , 3 + F_57 ( V_157 ) ) ;
V_15 -> V_158 = F_58 ( & V_15 -> V_22 , & V_159 ,
V_160 , V_161 ,
V_162 , 1 , 100 ) ;
V_15 -> V_163 = F_58 ( & V_15 -> V_22 , & V_159 ,
V_164 , V_165 ,
V_166 , 1 , 100 ) ;
V_15 -> V_17 = F_59 ( & V_15 -> V_22 ,
& V_159 , V_80 ,
F_57 ( V_167 ) - 1 ,
1 , 9 , V_167 ) ;
for ( V_136 = 0 ; V_136 < F_57 ( V_157 ) ; V_136 ++ )
F_60 ( & V_15 -> V_22 , & V_157 [ V_136 ] , NULL ) ;
if ( V_15 -> V_22 . error ) {
F_40 ( & V_135 -> V_122 , L_7 ) ;
V_137 = V_15 -> V_22 . error ;
goto error;
}
V_3 -> V_22 = & V_15 -> V_22 ;
F_6 ( V_15 , true , true ) ;
V_137 = F_61 ( & V_15 -> V_22 ) ;
if ( V_137 < 0 ) {
F_40 ( & V_135 -> V_122 , L_8 ) ;
goto error;
}
F_62 ( V_135 , V_15 ) ;
F_63 ( & V_15 -> V_4 ) ;
V_137 = F_64 ( V_3 ) ;
if ( V_137 < 0 ) {
F_40 ( & V_135 -> V_122 , L_9 ) ;
goto error;
}
return 0 ;
error:
F_65 ( & V_15 -> V_22 ) ;
F_66 ( & V_3 -> V_154 ) ;
F_67 ( V_15 -> V_29 ) ;
V_141:
F_68 ( & V_15 -> V_4 ) ;
return V_137 ;
}
static int F_69 ( struct V_134 * V_135 )
{
struct V_1 * V_15 = F_70 ( V_135 ) ;
struct V_2 * V_3 = & V_15 -> V_4 . V_3 ;
F_71 ( V_3 ) ;
F_65 ( & V_15 -> V_22 ) ;
F_66 ( & V_3 -> V_154 ) ;
F_68 ( & V_15 -> V_4 ) ;
return 0 ;
}
