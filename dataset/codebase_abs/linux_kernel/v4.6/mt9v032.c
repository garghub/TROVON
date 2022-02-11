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
if ( V_1 -> V_25 )
F_8 ( V_1 -> V_25 , 1 ) ;
V_11 = F_9 ( V_1 -> V_26 , V_1 -> V_27 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_10 ( V_1 -> V_26 ) ;
if ( V_11 )
return V_11 ;
F_11 ( 1 ) ;
if ( V_1 -> V_25 ) {
F_8 ( V_1 -> V_25 , 0 ) ;
F_11 ( 1 ) ;
}
V_11 = F_4 ( V_8 , V_28 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_28 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_4 ( V_8 , V_29 , 0 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_13 ( V_1 -> V_26 ) ;
}
static int F_14 ( struct V_1 * V_1 , bool V_30 )
{
struct V_7 * V_8 = V_1 -> V_7 ;
int V_11 ;
if ( ! V_30 ) {
F_12 ( V_1 ) ;
return 0 ;
}
V_11 = F_7 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_1 -> V_31 && V_1 -> V_31 -> V_32 ) {
V_11 = F_4 ( V_8 , V_1 -> V_16 -> V_17 -> V_33 ,
V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_11 = F_4 ( V_8 , V_35 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_15 ( & V_1 -> V_36 ) ;
}
static struct V_37 *
F_16 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned int V_40 , enum V_41 V_5 )
{
switch ( V_5 ) {
case V_42 :
return F_17 ( & V_1 -> V_4 , V_39 , V_40 ) ;
case V_43 :
return & V_1 -> V_44 ;
default:
return NULL ;
}
}
static struct V_13 *
F_18 ( struct V_1 * V_1 , struct V_38 * V_39 ,
unsigned int V_40 , enum V_41 V_5 )
{
switch ( V_5 ) {
case V_42 :
return F_19 ( & V_1 -> V_4 , V_39 , V_40 ) ;
case V_43 :
return & V_1 -> V_14 ;
default:
return NULL ;
}
}
static int F_20 ( struct V_2 * V_4 , int V_6 )
{
const T_1 V_45 = V_46
| V_47
| V_48 ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_13 * V_14 = & V_1 -> V_14 ;
struct V_7 * V_8 = V_1 -> V_7 ;
unsigned int V_49 ;
unsigned int V_50 ;
int V_11 ;
if ( ! V_6 )
return F_21 ( V_8 , V_29 , V_45 , 0 ) ;
V_49 = F_22 ( V_1 -> V_21 ) - 1 ;
V_50 = F_22 ( V_1 -> V_51 ) - 1 ;
V_11 = F_21 ( V_8 , V_52 ,
~ V_53 ,
V_49 << V_54 |
V_50 << V_55 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_56 , V_14 -> V_57 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_58 , V_14 -> V_59 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_60 , V_14 -> V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_8 , V_61 , V_14 -> V_62 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_21 ( V_8 , V_29 , V_45 , V_45 ) ;
}
static int F_23 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_63 * V_64 )
{
if ( V_64 -> V_65 > 0 )
return - V_66 ;
V_64 -> V_64 = V_67 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_68 * V_69 )
{
if ( V_69 -> V_65 >= 3 || V_69 -> V_64 != V_67 )
return - V_66 ;
V_69 -> V_70 = V_71 / ( 1 << V_69 -> V_65 ) ;
V_69 -> V_72 = V_69 -> V_70 ;
V_69 -> V_73 = V_74 / ( 1 << V_69 -> V_65 ) ;
V_69 -> V_75 = V_69 -> V_73 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_76 * V_44 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_44 -> V_44 = * F_16 ( V_1 , V_39 , V_44 -> V_40 ,
V_44 -> V_5 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_77 * V_78 = F_27 ( & V_1 -> V_4 ) ;
int V_11 ;
V_11 = F_28 ( V_1 -> V_79 ,
V_1 -> V_27 / V_1 -> V_21 ) ;
if ( V_11 < 0 )
F_29 ( & V_78 -> V_80 , L_1 , V_11 ) ;
}
static unsigned int F_30 ( unsigned int V_81 , unsigned int V_82 )
{
if ( V_82 * 3 > V_81 * 2 )
return 1 ;
if ( V_82 * 3 > V_81 )
return 2 ;
return 4 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_76 * V_44 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_37 * V_83 ;
struct V_13 * V_84 ;
unsigned int V_23 ;
unsigned int V_62 ;
unsigned int V_21 ;
unsigned int V_51 ;
V_84 = F_18 ( V_1 , V_39 , V_44 -> V_40 ,
V_44 -> V_5 ) ;
V_23 = F_32 ( F_33 ( V_44 -> V_44 . V_23 , 2 ) ,
F_6 (unsigned int, __crop->width / 4 ,
MT9V032_WINDOW_WIDTH_MIN) ,
V_84 -> V_23 ) ;
V_62 = F_32 ( F_33 ( V_44 -> V_44 . V_62 , 2 ) ,
F_6 (unsigned int, __crop->height / 4 ,
MT9V032_WINDOW_HEIGHT_MIN) ,
V_84 -> V_62 ) ;
V_21 = F_30 ( V_84 -> V_23 , V_23 ) ;
V_51 = F_30 ( V_84 -> V_62 , V_62 ) ;
V_83 = F_16 ( V_1 , V_39 , V_44 -> V_40 ,
V_44 -> V_5 ) ;
V_83 -> V_23 = V_84 -> V_23 / V_21 ;
V_83 -> V_62 = V_84 -> V_62 / V_51 ;
if ( V_44 -> V_5 == V_43 ) {
V_1 -> V_21 = V_21 ;
V_1 -> V_51 = V_51 ;
F_26 ( V_1 ) ;
}
V_44 -> V_44 = * V_83 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_85 * V_86 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_86 -> V_87 != V_88 )
return - V_66 ;
V_86 -> V_89 = * F_18 ( V_1 , V_39 , V_86 -> V_40 , V_86 -> V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_4 ,
struct V_38 * V_39 ,
struct V_85 * V_86 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_37 * V_83 ;
struct V_13 * V_84 ;
struct V_13 V_90 ;
if ( V_86 -> V_87 != V_88 )
return - V_66 ;
V_90 . V_57 = F_32 ( F_33 ( V_86 -> V_89 . V_57 + 1 , 2 ) - 1 ,
V_91 ,
V_92 ) ;
V_90 . V_59 = F_32 ( F_33 ( V_86 -> V_89 . V_59 + 1 , 2 ) - 1 ,
V_93 ,
V_94 ) ;
V_90 . V_23 = F_36 (unsigned int, ALIGN(sel->r.width, 2),
MT9V032_WINDOW_WIDTH_MIN,
MT9V032_WINDOW_WIDTH_MAX) ;
V_90 . V_62 = F_36 (unsigned int, ALIGN(sel->r.height, 2),
MT9V032_WINDOW_HEIGHT_MIN,
MT9V032_WINDOW_HEIGHT_MAX) ;
V_90 . V_23 = F_37 (unsigned int,
rect.width, MT9V032_PIXEL_ARRAY_WIDTH - rect.left) ;
V_90 . V_62 = F_37 (unsigned int,
rect.height, MT9V032_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_84 = F_18 ( V_1 , V_39 , V_86 -> V_40 , V_86 -> V_5 ) ;
if ( V_90 . V_23 != V_84 -> V_23 || V_90 . V_62 != V_84 -> V_62 ) {
V_83 = F_16 ( V_1 , V_39 , V_86 -> V_40 ,
V_86 -> V_5 ) ;
V_83 -> V_23 = V_90 . V_23 ;
V_83 -> V_62 = V_90 . V_62 ;
if ( V_86 -> V_5 == V_43 ) {
V_1 -> V_21 = 1 ;
V_1 -> V_51 = 1 ;
F_26 ( V_1 ) ;
}
}
* V_84 = V_90 ;
V_86 -> V_89 = V_90 ;
return 0 ;
}
static int F_38 ( struct V_95 * V_96 )
{
struct V_1 * V_1 =
F_2 ( V_96 -> V_97 , struct V_1 , V_36 ) ;
struct V_7 * V_8 = V_1 -> V_7 ;
T_2 V_98 ;
T_1 V_17 ;
switch ( V_96 -> V_99 ) {
case V_100 :
return F_3 ( V_1 , V_101 ,
V_96 -> V_102 ) ;
case V_103 :
return F_4 ( V_8 , V_104 , V_96 -> V_102 ) ;
case V_105 :
return F_3 ( V_1 , V_106 ,
! V_96 -> V_102 ) ;
case V_107 :
return F_4 ( V_8 , V_108 ,
V_96 -> V_102 ) ;
case V_109 :
V_1 -> V_18 = V_96 -> V_102 ;
return F_5 ( V_1 ) ;
case V_110 :
return F_4 ( V_8 , V_111 ,
V_96 -> V_102 ) ;
case V_112 :
case V_113 :
if ( V_1 -> V_114 == NULL )
break;
V_98 = V_1 -> V_31 -> V_115 [ V_1 -> V_114 -> V_102 ] ;
* V_1 -> V_79 -> V_116 . V_117 = V_98 ;
V_1 -> V_27 = V_98 ;
break;
case V_118 :
switch ( V_1 -> V_119 -> V_102 ) {
case 0 :
V_17 = 0 ;
break;
case 1 :
V_17 = V_120
| V_121 ;
break;
case 2 :
V_17 = V_122
| V_121 ;
break;
case 3 :
V_17 = V_123
| V_121 ;
break;
default:
V_17 = ( V_1 -> V_124 -> V_102 <<
V_125 )
| V_126
| V_121
| V_127 ;
break;
}
return F_4 ( V_8 , V_128 , V_17 ) ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_4 , int V_30 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_11 = 0 ;
F_40 ( & V_1 -> V_129 ) ;
if ( V_1 -> V_130 == ! V_30 ) {
V_11 = F_14 ( V_1 , ! ! V_30 ) ;
if ( V_11 < 0 )
goto V_131;
}
V_1 -> V_130 += V_30 ? 1 : - 1 ;
F_41 ( V_1 -> V_130 < 0 ) ;
V_131:
F_42 ( & V_1 -> V_129 ) ;
return V_11 ;
}
static int F_43 ( struct V_2 * V_4 )
{
struct V_77 * V_78 = F_27 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned int V_132 ;
T_2 V_19 ;
int V_11 ;
F_44 ( & V_78 -> V_80 , L_2 ,
V_78 -> V_133 ) ;
V_11 = F_7 ( V_1 ) ;
if ( V_11 < 0 ) {
F_45 ( & V_78 -> V_80 , L_3 ) ;
return V_11 ;
}
V_11 = F_46 ( V_1 -> V_7 , V_134 , & V_19 ) ;
if ( V_11 < 0 ) {
F_45 ( & V_78 -> V_80 , L_4 ) ;
return V_11 ;
}
for ( V_132 = 0 ; V_132 < F_47 ( V_135 ) ; ++ V_132 ) {
if ( V_135 [ V_132 ] . V_19 == V_19 ) {
V_1 -> V_19 = & V_135 [ V_132 ] ;
break;
}
}
if ( V_1 -> V_19 == NULL ) {
F_45 ( & V_78 -> V_80 , L_5 ,
V_19 ) ;
return - V_136 ;
}
F_12 ( V_1 ) ;
F_44 ( & V_78 -> V_80 , L_6 ,
V_1 -> V_19 -> V_137 , V_78 -> V_133 ) ;
F_26 ( V_1 ) ;
return V_11 ;
}
static int F_48 ( struct V_2 * V_4 , struct V_138 * V_139 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_37 * V_44 ;
struct V_13 * V_14 ;
V_14 = F_19 ( V_4 , V_139 -> V_40 , 0 ) ;
V_14 -> V_57 = V_140 ;
V_14 -> V_59 = V_141 ;
V_14 -> V_23 = V_71 ;
V_14 -> V_62 = V_74 ;
V_44 = F_17 ( V_4 , V_139 -> V_40 , 0 ) ;
if ( V_1 -> V_16 -> V_142 )
V_44 -> V_64 = V_67 ;
else
V_44 -> V_64 = V_143 ;
V_44 -> V_23 = V_71 ;
V_44 -> V_62 = V_74 ;
V_44 -> V_144 = V_145 ;
V_44 -> V_146 = V_147 ;
return F_39 ( V_4 , 1 ) ;
}
static int F_49 ( struct V_2 * V_4 , struct V_138 * V_139 )
{
return F_39 ( V_4 , 0 ) ;
}
static struct V_148 *
F_50 ( struct V_77 * V_78 )
{
struct V_148 * V_31 = NULL ;
struct V_149 V_150 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
if ( ! F_51 ( V_155 ) || ! V_78 -> V_80 . V_156 )
return V_78 -> V_80 . V_157 ;
V_152 = F_52 ( V_78 -> V_80 . V_156 , NULL ) ;
if ( ! V_152 )
return NULL ;
if ( F_53 ( V_152 , & V_150 ) < 0 )
goto V_131;
V_31 = F_54 ( & V_78 -> V_80 , sizeof( * V_31 ) , V_158 ) ;
if ( ! V_31 )
goto V_131;
V_154 = F_55 ( V_152 , L_7 , NULL ) ;
if ( V_154 ) {
T_3 * V_115 ;
T_4 V_159 = V_154 -> V_160 / sizeof( * V_115 ) ;
V_115 = F_56 ( & V_78 -> V_80 , V_159 ,
sizeof( * V_115 ) , V_158 ) ;
if ( ! V_115 )
goto V_131;
if ( F_57 ( V_152 , L_7 ,
V_115 , V_159 ) < 0 )
goto V_131;
V_31 -> V_115 = V_115 ;
V_31 -> V_161 = V_115 [ 0 ] ;
}
V_31 -> V_32 = ! ! ( V_150 . V_162 . V_163 . V_164 &
V_165 ) ;
V_131:
F_58 ( V_152 ) ;
return V_31 ;
}
static int F_59 ( struct V_77 * V_78 ,
const struct V_166 * V_167 )
{
struct V_148 * V_31 = F_50 ( V_78 ) ;
struct V_1 * V_1 ;
unsigned int V_132 ;
int V_11 ;
if ( ! F_60 ( V_78 -> V_168 ,
V_169 ) ) {
F_29 ( & V_78 -> V_168 -> V_80 ,
L_8 ) ;
return - V_170 ;
}
V_1 = F_54 ( & V_78 -> V_80 , sizeof( * V_1 ) , V_158 ) ;
if ( ! V_1 )
return - V_171 ;
V_1 -> V_7 = F_61 ( V_78 , & V_172 ) ;
if ( F_62 ( V_1 -> V_7 ) )
return F_63 ( V_1 -> V_7 ) ;
V_1 -> V_26 = F_64 ( & V_78 -> V_80 , NULL ) ;
if ( F_62 ( V_1 -> V_26 ) )
return F_63 ( V_1 -> V_26 ) ;
V_1 -> V_25 = F_65 ( & V_78 -> V_80 , L_9 ,
V_173 ) ;
if ( F_62 ( V_1 -> V_25 ) )
return F_63 ( V_1 -> V_25 ) ;
V_1 -> V_174 = F_65 ( & V_78 -> V_80 , L_10 ,
V_175 ) ;
if ( F_62 ( V_1 -> V_174 ) )
return F_63 ( V_1 -> V_174 ) ;
F_66 ( & V_1 -> V_129 ) ;
V_1 -> V_31 = V_31 ;
V_1 -> V_16 = ( const void * ) V_167 -> V_176 ;
F_67 ( & V_1 -> V_36 , 10 ) ;
F_68 ( & V_1 -> V_36 , & V_177 ,
V_100 , 0 , 1 , 1 , 1 ) ;
F_68 ( & V_1 -> V_36 , & V_177 ,
V_103 , V_178 ,
V_179 , 1 , V_180 ) ;
F_69 ( & V_1 -> V_36 , & V_177 ,
V_105 , V_181 , 0 ,
V_182 ) ;
F_68 ( & V_1 -> V_36 , & V_177 ,
V_107 , V_1 -> V_16 -> V_17 -> V_183 ,
V_1 -> V_16 -> V_17 -> V_184 , 1 ,
V_185 ) ;
F_68 ( & V_1 -> V_36 , & V_177 ,
V_109 , V_1 -> V_16 -> V_17 -> V_15 ,
V_186 , 1 ,
V_187 ) ;
F_68 ( & V_1 -> V_36 , & V_177 ,
V_110 , V_1 -> V_16 -> V_17 -> V_188 ,
V_1 -> V_16 -> V_17 -> V_189 , 1 ,
V_190 ) ;
V_1 -> V_119 = F_70 ( & V_1 -> V_36 ,
& V_177 , V_118 ,
F_47 ( V_191 ) - 1 , 0 , 0 ,
V_191 ) ;
V_1 -> V_124 = F_71 ( & V_1 -> V_36 ,
& V_192 , NULL ) ;
F_72 ( 2 , & V_1 -> V_119 ) ;
V_1 -> V_79 =
F_68 ( & V_1 -> V_36 , & V_177 ,
V_112 , 1 , V_193 , 1 , 1 ) ;
if ( V_31 && V_31 -> V_115 ) {
unsigned int V_194 = 0 ;
for ( V_132 = 0 ; V_31 -> V_115 [ V_132 ] ; ++ V_132 ) {
if ( V_31 -> V_115 [ V_132 ] == V_31 -> V_161 )
V_194 = V_132 ;
}
V_1 -> V_114 =
F_73 ( & V_1 -> V_36 ,
& V_177 ,
V_113 , V_132 - 1 , V_194 ,
V_31 -> V_115 ) ;
F_72 ( 2 , & V_1 -> V_114 ) ;
}
V_1 -> V_4 . V_195 = & V_1 -> V_36 ;
if ( V_1 -> V_36 . error ) {
F_45 ( & V_78 -> V_80 , L_11 ,
V_1 -> V_36 . error ) ;
V_11 = V_1 -> V_36 . error ;
goto V_196;
}
V_1 -> V_14 . V_57 = V_140 ;
V_1 -> V_14 . V_59 = V_141 ;
V_1 -> V_14 . V_23 = V_71 ;
V_1 -> V_14 . V_62 = V_74 ;
if ( V_1 -> V_16 -> V_142 )
V_1 -> V_44 . V_64 = V_67 ;
else
V_1 -> V_44 . V_64 = V_143 ;
V_1 -> V_44 . V_23 = V_71 ;
V_1 -> V_44 . V_62 = V_74 ;
V_1 -> V_44 . V_144 = V_145 ;
V_1 -> V_44 . V_146 = V_147 ;
V_1 -> V_21 = 1 ;
V_1 -> V_51 = 1 ;
V_1 -> V_10 = V_106 | V_101 ;
V_1 -> V_18 = V_187 ;
V_1 -> V_27 = V_197 ;
F_74 ( & V_1 -> V_4 , V_78 , & V_198 ) ;
V_1 -> V_4 . V_199 = & V_200 ;
V_1 -> V_4 . V_164 |= V_201 ;
V_1 -> V_40 . V_164 = V_202 ;
V_11 = F_75 ( & V_1 -> V_4 . V_203 , 1 , & V_1 -> V_40 ) ;
if ( V_11 < 0 )
goto V_196;
V_1 -> V_4 . V_80 = & V_78 -> V_80 ;
V_11 = F_76 ( & V_1 -> V_4 ) ;
if ( V_11 < 0 )
goto V_196;
return 0 ;
V_196:
F_77 ( & V_1 -> V_4 . V_203 ) ;
F_78 ( & V_1 -> V_36 ) ;
return V_11 ;
}
static int F_79 ( struct V_77 * V_78 )
{
struct V_2 * V_4 = F_80 ( V_78 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_81 ( V_4 ) ;
F_78 ( & V_1 -> V_36 ) ;
F_77 ( & V_4 -> V_203 ) ;
return 0 ;
}
