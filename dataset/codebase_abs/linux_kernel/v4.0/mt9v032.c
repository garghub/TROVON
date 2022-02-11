static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int
F_3 ( struct V_1 * V_1 , T_1 V_5 , int V_6 )
{
struct V_7 * V_8 = V_1 -> V_7 ;
T_1 V_9 = V_1 -> V_10 ;
int V_11 ;
if ( V_6 )
V_9 |= V_5 ;
else
V_9 &= ~ V_5 ;
V_11 = F_4 ( V_8 , V_12 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
V_1 -> V_10 = V_9 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_1 )
{
struct V_13 * V_14 = & V_1 -> V_14 ;
unsigned int V_15 = V_1 -> V_16 -> V_17 -> V_15 ;
unsigned int V_18 ;
if ( V_1 -> V_19 -> V_19 == V_20 )
V_15 += ( V_1 -> V_21 - 1 ) * 10 ;
V_15 = F_6 ( int , V_1 -> V_16 -> V_17 -> V_22 - V_14 -> V_23 ,
V_15 ) ;
V_18 = F_6 (unsigned int, mt9v032->hblank, min_hblank) ;
return F_4 ( V_1 -> V_7 , V_24 ,
V_18 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_7 ;
int V_11 ;
V_11 = F_8 ( V_1 -> V_25 , V_1 -> V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_1 -> V_25 ) ;
if ( V_11 )
return V_11 ;
F_10 ( 1 ) ;
V_11 = F_4 ( V_8 , V_27 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_27 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_4 ( V_8 , V_28 , 0 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_12 ( V_1 -> V_25 ) ;
}
static int F_13 ( struct V_1 * V_1 , bool V_29 )
{
struct V_7 * V_8 = V_1 -> V_7 ;
int V_11 ;
if ( ! V_29 ) {
F_11 ( V_1 ) ;
return 0 ;
}
V_11 = F_7 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_1 -> V_30 && V_1 -> V_30 -> V_31 ) {
V_11 = F_4 ( V_8 , V_1 -> V_16 -> V_17 -> V_32 ,
V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_11 = F_4 ( V_8 , V_34 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_14 ( & V_1 -> V_35 ) ;
}
static struct V_36 *
F_15 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned int V_39 , enum V_40 V_5 )
{
switch ( V_5 ) {
case V_41 :
return F_16 ( V_38 , V_39 ) ;
case V_42 :
return & V_1 -> V_43 ;
default:
return NULL ;
}
}
static struct V_13 *
F_17 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned int V_39 , enum V_40 V_5 )
{
switch ( V_5 ) {
case V_41 :
return F_18 ( V_38 , V_39 ) ;
case V_42 :
return & V_1 -> V_14 ;
default:
return NULL ;
}
}
static int F_19 ( struct V_2 * V_4 , int V_6 )
{
const T_1 V_44 = V_45
| V_46
| V_47 ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_13 * V_14 = & V_1 -> V_14 ;
struct V_7 * V_8 = V_1 -> V_7 ;
unsigned int V_48 ;
unsigned int V_49 ;
int V_11 ;
if ( ! V_6 )
return F_20 ( V_8 , V_28 , V_44 , 0 ) ;
V_48 = F_21 ( V_1 -> V_21 ) - 1 ;
V_49 = F_21 ( V_1 -> V_50 ) - 1 ;
V_11 = F_20 ( V_8 , V_51 ,
~ V_52 ,
V_48 << V_53 |
V_49 << V_54 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_55 , V_14 -> V_56 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_57 , V_14 -> V_58 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_59 , V_14 -> V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_60 , V_14 -> V_61 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_20 ( V_8 , V_28 , V_44 , V_44 ) ;
}
static int F_22 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_64 > 0 )
return - V_65 ;
V_63 -> V_63 = V_66 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_67 * V_68 )
{
if ( V_68 -> V_64 >= 3 || V_68 -> V_63 != V_66 )
return - V_65 ;
V_68 -> V_69 = V_70 / ( 1 << V_68 -> V_64 ) ;
V_68 -> V_71 = V_68 -> V_69 ;
V_68 -> V_72 = V_73 / ( 1 << V_68 -> V_64 ) ;
V_68 -> V_74 = V_68 -> V_72 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_75 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_43 -> V_43 = * F_15 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_5 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_76 * V_77 = F_26 ( & V_1 -> V_4 ) ;
int V_11 ;
V_11 = F_27 ( V_1 -> V_78 ,
V_1 -> V_26 / V_1 -> V_21 ) ;
if ( V_11 < 0 )
F_28 ( & V_77 -> V_79 , L_1 , V_11 ) ;
}
static unsigned int F_29 ( unsigned int V_80 , unsigned int V_81 )
{
if ( V_81 * 3 > V_80 * 2 )
return 1 ;
if ( V_81 * 3 > V_80 )
return 2 ;
return 4 ;
}
static int F_30 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_75 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_82 ;
struct V_13 * V_83 ;
unsigned int V_23 ;
unsigned int V_61 ;
unsigned int V_21 ;
unsigned int V_50 ;
V_83 = F_17 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_5 ) ;
V_23 = F_31 ( F_32 ( V_43 -> V_43 . V_23 , 2 ) ,
F_6 (unsigned int, __crop->width / 4 ,
MT9V032_WINDOW_WIDTH_MIN) ,
V_83 -> V_23 ) ;
V_61 = F_31 ( F_32 ( V_43 -> V_43 . V_61 , 2 ) ,
F_6 (unsigned int, __crop->height / 4 ,
MT9V032_WINDOW_HEIGHT_MIN) ,
V_83 -> V_61 ) ;
V_21 = F_29 ( V_83 -> V_23 , V_23 ) ;
V_50 = F_29 ( V_83 -> V_61 , V_61 ) ;
V_82 = F_15 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_5 ) ;
V_82 -> V_23 = V_83 -> V_23 / V_21 ;
V_82 -> V_61 = V_83 -> V_61 / V_50 ;
if ( V_43 -> V_5 == V_42 ) {
V_1 -> V_21 = V_21 ;
V_1 -> V_50 = V_50 ;
F_25 ( V_1 ) ;
}
V_43 -> V_43 = * V_82 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_84 * V_85 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_85 -> V_86 != V_87 )
return - V_65 ;
V_85 -> V_88 = * F_17 ( V_1 , V_38 , V_85 -> V_39 , V_85 -> V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_84 * V_85 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_82 ;
struct V_13 * V_83 ;
struct V_13 V_89 ;
if ( V_85 -> V_86 != V_87 )
return - V_65 ;
V_89 . V_56 = F_31 ( F_32 ( V_85 -> V_88 . V_56 + 1 , 2 ) - 1 ,
V_90 ,
V_91 ) ;
V_89 . V_58 = F_31 ( F_32 ( V_85 -> V_88 . V_58 + 1 , 2 ) - 1 ,
V_92 ,
V_93 ) ;
V_89 . V_23 = F_35 (unsigned int, ALIGN(sel->r.width, 2),
MT9V032_WINDOW_WIDTH_MIN,
MT9V032_WINDOW_WIDTH_MAX) ;
V_89 . V_61 = F_35 (unsigned int, ALIGN(sel->r.height, 2),
MT9V032_WINDOW_HEIGHT_MIN,
MT9V032_WINDOW_HEIGHT_MAX) ;
V_89 . V_23 = F_36 (unsigned int,
rect.width, MT9V032_PIXEL_ARRAY_WIDTH - rect.left) ;
V_89 . V_61 = F_36 (unsigned int,
rect.height, MT9V032_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_83 = F_17 ( V_1 , V_38 , V_85 -> V_39 , V_85 -> V_5 ) ;
if ( V_89 . V_23 != V_83 -> V_23 || V_89 . V_61 != V_83 -> V_61 ) {
V_82 = F_15 ( V_1 , V_38 , V_85 -> V_39 ,
V_85 -> V_5 ) ;
V_82 -> V_23 = V_89 . V_23 ;
V_82 -> V_61 = V_89 . V_61 ;
if ( V_85 -> V_5 == V_42 ) {
V_1 -> V_21 = 1 ;
V_1 -> V_50 = 1 ;
F_25 ( V_1 ) ;
}
}
* V_83 = V_89 ;
V_85 -> V_88 = V_89 ;
return 0 ;
}
static int F_37 ( struct V_94 * V_95 )
{
struct V_1 * V_1 =
F_2 ( V_95 -> V_96 , struct V_1 , V_35 ) ;
struct V_7 * V_8 = V_1 -> V_7 ;
T_2 V_97 ;
T_1 V_17 ;
switch ( V_95 -> V_98 ) {
case V_99 :
return F_3 ( V_1 , V_100 ,
V_95 -> V_101 ) ;
case V_102 :
return F_4 ( V_8 , V_103 , V_95 -> V_101 ) ;
case V_104 :
return F_3 ( V_1 , V_105 ,
! V_95 -> V_101 ) ;
case V_106 :
return F_4 ( V_8 , V_107 ,
V_95 -> V_101 ) ;
case V_108 :
V_1 -> V_18 = V_95 -> V_101 ;
return F_5 ( V_1 ) ;
case V_109 :
return F_4 ( V_8 , V_110 ,
V_95 -> V_101 ) ;
case V_111 :
case V_112 :
if ( V_1 -> V_113 == NULL )
break;
V_97 = V_1 -> V_30 -> V_114 [ V_1 -> V_113 -> V_101 ] ;
* V_1 -> V_78 -> V_115 . V_116 = V_97 ;
V_1 -> V_26 = V_97 ;
break;
case V_117 :
switch ( V_1 -> V_118 -> V_101 ) {
case 0 :
V_17 = 0 ;
break;
case 1 :
V_17 = V_119
| V_120 ;
break;
case 2 :
V_17 = V_121
| V_120 ;
break;
case 3 :
V_17 = V_122
| V_120 ;
break;
default:
V_17 = ( V_1 -> V_123 -> V_101 <<
V_124 )
| V_125
| V_120
| V_126 ;
break;
}
return F_4 ( V_8 , V_127 , V_17 ) ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_4 , int V_29 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_39 ( & V_1 -> V_128 ) ;
if ( V_1 -> V_129 == ! V_29 ) {
V_11 = F_13 ( V_1 , ! ! V_29 ) ;
if ( V_11 < 0 )
goto V_130;
}
V_1 -> V_129 += V_29 ? 1 : - 1 ;
F_40 ( V_1 -> V_129 < 0 ) ;
V_130:
F_41 ( & V_1 -> V_128 ) ;
return V_11 ;
}
static int F_42 ( struct V_2 * V_4 )
{
struct V_76 * V_77 = F_26 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned int V_131 ;
T_2 V_19 ;
int V_11 ;
F_43 ( & V_77 -> V_79 , L_2 ,
V_77 -> V_132 ) ;
V_11 = F_7 ( V_1 ) ;
if ( V_11 < 0 ) {
F_44 ( & V_77 -> V_79 , L_3 ) ;
return V_11 ;
}
V_11 = F_45 ( V_1 -> V_7 , V_133 , & V_19 ) ;
if ( V_11 < 0 ) {
F_44 ( & V_77 -> V_79 , L_4 ) ;
return V_11 ;
}
for ( V_131 = 0 ; V_131 < F_46 ( V_134 ) ; ++ V_131 ) {
if ( V_134 [ V_131 ] . V_19 == V_19 ) {
V_1 -> V_19 = & V_134 [ V_131 ] ;
break;
}
}
if ( V_1 -> V_19 == NULL ) {
F_44 ( & V_77 -> V_79 , L_5 ,
V_19 ) ;
return - V_135 ;
}
F_11 ( V_1 ) ;
F_43 ( & V_77 -> V_79 , L_6 ,
V_1 -> V_19 -> V_136 , V_77 -> V_132 ) ;
F_25 ( V_1 ) ;
return V_11 ;
}
static int F_47 ( struct V_2 * V_4 , struct V_37 * V_38 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_43 ;
struct V_13 * V_14 ;
V_14 = F_18 ( V_38 , 0 ) ;
V_14 -> V_56 = V_137 ;
V_14 -> V_58 = V_138 ;
V_14 -> V_23 = V_70 ;
V_14 -> V_61 = V_73 ;
V_43 = F_16 ( V_38 , 0 ) ;
if ( V_1 -> V_16 -> V_139 )
V_43 -> V_63 = V_66 ;
else
V_43 -> V_63 = V_140 ;
V_43 -> V_23 = V_70 ;
V_43 -> V_61 = V_73 ;
V_43 -> V_141 = V_142 ;
V_43 -> V_143 = V_144 ;
return F_38 ( V_4 , 1 ) ;
}
static int F_48 ( struct V_2 * V_4 , struct V_37 * V_38 )
{
return F_38 ( V_4 , 0 ) ;
}
static int F_49 ( struct V_76 * V_77 ,
const struct V_145 * V_146 )
{
struct V_147 * V_30 = V_77 -> V_79 . V_148 ;
struct V_1 * V_1 ;
unsigned int V_131 ;
int V_11 ;
if ( ! F_50 ( V_77 -> V_149 ,
V_150 ) ) {
F_28 ( & V_77 -> V_149 -> V_79 ,
L_7 ) ;
return - V_151 ;
}
V_1 = F_51 ( & V_77 -> V_79 , sizeof( * V_1 ) , V_152 ) ;
if ( ! V_1 )
return - V_153 ;
V_1 -> V_7 = F_52 ( V_77 , & V_154 ) ;
if ( F_53 ( V_1 -> V_7 ) )
return F_54 ( V_1 -> V_7 ) ;
V_1 -> V_25 = F_55 ( & V_77 -> V_79 , NULL ) ;
if ( F_53 ( V_1 -> V_25 ) )
return F_54 ( V_1 -> V_25 ) ;
F_56 ( & V_1 -> V_128 ) ;
V_1 -> V_30 = V_30 ;
V_1 -> V_16 = ( const void * ) V_146 -> V_155 ;
F_57 ( & V_1 -> V_35 , 10 ) ;
F_58 ( & V_1 -> V_35 , & V_156 ,
V_99 , 0 , 1 , 1 , 1 ) ;
F_58 ( & V_1 -> V_35 , & V_156 ,
V_102 , V_157 ,
V_158 , 1 , V_159 ) ;
F_59 ( & V_1 -> V_35 , & V_156 ,
V_104 , V_160 , 0 ,
V_161 ) ;
F_58 ( & V_1 -> V_35 , & V_156 ,
V_106 , V_1 -> V_16 -> V_17 -> V_162 ,
V_1 -> V_16 -> V_17 -> V_163 , 1 ,
V_164 ) ;
F_58 ( & V_1 -> V_35 , & V_156 ,
V_108 , V_1 -> V_16 -> V_17 -> V_15 ,
V_165 , 1 ,
V_166 ) ;
F_58 ( & V_1 -> V_35 , & V_156 ,
V_109 , V_1 -> V_16 -> V_17 -> V_167 ,
V_1 -> V_16 -> V_17 -> V_168 , 1 ,
V_169 ) ;
V_1 -> V_118 = F_60 ( & V_1 -> V_35 ,
& V_156 , V_117 ,
F_46 ( V_170 ) - 1 , 0 , 0 ,
V_170 ) ;
V_1 -> V_123 = F_61 ( & V_1 -> V_35 ,
& V_171 , NULL ) ;
F_62 ( 2 , & V_1 -> V_118 ) ;
V_1 -> V_78 =
F_58 ( & V_1 -> V_35 , & V_156 ,
V_111 , 1 , V_172 , 1 , 1 ) ;
if ( V_30 && V_30 -> V_114 ) {
unsigned int V_173 = 0 ;
for ( V_131 = 0 ; V_30 -> V_114 [ V_131 ] ; ++ V_131 ) {
if ( V_30 -> V_114 [ V_131 ] == V_30 -> V_174 )
V_173 = V_131 ;
}
V_1 -> V_113 =
F_63 ( & V_1 -> V_35 ,
& V_156 ,
V_112 , V_131 - 1 , V_173 ,
V_30 -> V_114 ) ;
F_62 ( 2 , & V_1 -> V_113 ) ;
}
V_1 -> V_4 . V_175 = & V_1 -> V_35 ;
if ( V_1 -> V_35 . error )
F_64 ( V_176 L_8 ,
V_177 , V_1 -> V_35 . error ) ;
V_1 -> V_14 . V_56 = V_137 ;
V_1 -> V_14 . V_58 = V_138 ;
V_1 -> V_14 . V_23 = V_70 ;
V_1 -> V_14 . V_61 = V_73 ;
if ( V_1 -> V_16 -> V_139 )
V_1 -> V_43 . V_63 = V_66 ;
else
V_1 -> V_43 . V_63 = V_140 ;
V_1 -> V_43 . V_23 = V_70 ;
V_1 -> V_43 . V_61 = V_73 ;
V_1 -> V_43 . V_141 = V_142 ;
V_1 -> V_43 . V_143 = V_144 ;
V_1 -> V_21 = 1 ;
V_1 -> V_50 = 1 ;
V_1 -> V_10 = V_105 | V_100 ;
V_1 -> V_18 = V_166 ;
V_1 -> V_26 = V_178 ;
F_65 ( & V_1 -> V_4 , V_77 , & V_179 ) ;
V_1 -> V_4 . V_180 = & V_181 ;
V_1 -> V_4 . V_182 |= V_183 ;
V_1 -> V_39 . V_182 = V_184 ;
V_11 = F_66 ( & V_1 -> V_4 . V_185 , 1 , & V_1 -> V_39 , 0 ) ;
if ( V_11 < 0 )
goto V_186;
V_1 -> V_4 . V_79 = & V_77 -> V_79 ;
V_11 = F_67 ( & V_1 -> V_4 ) ;
if ( V_11 < 0 )
goto V_186;
return 0 ;
V_186:
F_68 ( & V_1 -> V_4 . V_185 ) ;
F_69 ( & V_1 -> V_35 ) ;
return V_11 ;
}
static int F_70 ( struct V_76 * V_77 )
{
struct V_2 * V_4 = F_71 ( V_77 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_72 ( V_4 ) ;
F_69 ( & V_1 -> V_35 ) ;
F_73 ( V_4 ) ;
F_68 ( & V_4 -> V_185 ) ;
return 0 ;
}
