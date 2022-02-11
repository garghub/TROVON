static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> clock ) {
V_3 = F_2 ( V_2 -> clock ) ;
if ( V_3 < 0 )
return V_3 ;
}
#if 0
if (sdev->meram_dev && sdev->meram_dev->pdev)
pm_runtime_get_sync(&sdev->meram_dev->pdev->dev);
#endif
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
#if 0
if (sdev->meram_dev && sdev->meram_dev->pdev)
pm_runtime_put_sync(&sdev->meram_dev->pdev->dev);
#endif
if ( V_2 -> clock )
F_4 ( V_2 -> clock ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
const struct V_10 * V_11 = & V_2 -> V_12 -> V_13 ;
const struct V_14 * V_15 = & V_7 -> V_15 ;
T_1 V_16 ;
V_16 = V_2 -> V_17
| ( ( V_15 -> V_18 & V_19 ) ? 0 : V_20 )
| ( ( V_15 -> V_18 & V_21 ) ? 0 : V_22 )
| ( ( V_11 -> V_18 & V_23 ) ? V_24 : 0 )
| ( ( V_11 -> V_18 & V_25 ) ? V_26 : 0 )
| ( ( V_11 -> V_18 & V_27 ) ? V_28 : 0 )
| ( ( V_11 -> V_18 & V_29 ) ? V_30 : 0 )
| ( ( V_11 -> V_18 & V_31 ) ? V_32 : 0 ) ;
F_6 ( V_2 , V_33 , V_16 ) ;
if ( V_11 -> V_34 >= V_35 &&
V_11 -> V_34 <= V_36 ) {
V_16 = ( V_11 -> V_37 . V_38 << V_39 )
| ( V_11 -> V_37 . V_40 ? V_41 : 0 )
| ( V_11 -> V_37 . V_42 ? V_43 : 0 )
| ( V_11 -> V_37 . V_44 << V_45 )
| ( V_11 -> V_37 . V_46 << V_47 )
| ( V_11 -> V_37 . V_48 << V_49 ) ;
F_6 ( V_2 , V_50 , V_16 ) ;
V_16 = ( V_11 -> V_37 . V_51 << V_52 )
| ( V_11 -> V_37 . V_53 << V_54 )
| ( V_11 -> V_37 . V_55 << V_56 )
| ( V_11 -> V_37 . V_57 << V_58 ) ;
F_6 ( V_2 , V_59 , V_16 ) ;
}
V_16 = ( ( V_15 -> V_60 / 8 ) << 16 )
| ( V_15 -> V_61 / 8 ) ;
F_6 ( V_2 , V_62 , V_16 ) ;
V_16 = ( ( ( V_15 -> V_63 - V_15 -> V_64 ) / 8 ) << 16 )
| ( V_15 -> V_64 / 8 ) ;
F_6 ( V_2 , V_65 , V_16 ) ;
V_16 = ( ( V_15 -> V_60 & 7 ) << 24 ) | ( ( V_15 -> V_61 & 7 ) << 16 )
| ( ( ( V_15 -> V_63 - V_15 -> V_64 ) & 7 ) << 8 )
| ( V_15 -> V_64 & 7 ) ;
F_6 ( V_2 , V_66 , V_16 ) ;
V_16 = ( ( V_15 -> V_67 ) << 16 )
| V_15 -> V_68 ;
F_6 ( V_2 , V_69 , V_16 ) ;
V_16 = ( ( V_15 -> V_70 - V_15 -> V_71 ) << 16 )
| V_15 -> V_71 ;
F_6 ( V_2 , V_72 , V_16 ) ;
}
static void F_7 ( struct V_4 * V_5 , bool V_73 )
{
struct V_1 * V_2 = V_5 -> V_7 . V_8 -> V_9 ;
T_1 V_16 ;
V_16 = F_8 ( V_2 , V_74 ) ;
if ( V_73 )
F_6 ( V_2 , V_74 , V_16 | V_75 ) ;
else
F_6 ( V_2 , V_74 , V_16 & ~ V_75 ) ;
while ( 1 ) {
V_16 = F_8 ( V_2 , V_76 ) & V_77 ;
if ( ( V_73 && V_16 ) || ( ! V_73 && ! V_16 ) )
break;
F_9 () ;
}
if ( ! V_73 ) {
F_6 ( V_2 , V_78 , V_79 ) ;
}
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
const struct V_10 * V_11 = & V_2 -> V_12 -> V_13 ;
const struct V_80 * V_81 ;
struct V_82 * V_8 = V_2 -> V_83 ;
struct V_84 * V_85 ;
T_1 V_16 ;
int V_3 ;
if ( V_5 -> V_86 )
return;
V_81 = V_80 ( V_7 -> V_87 -> V_88 -> V_89 ) ;
if ( F_11 ( V_81 == NULL ) )
return;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return;
F_6 ( V_2 , V_74 , F_8 ( V_2 , V_74 ) | V_90 ) ;
F_12 ( V_2 , V_74 , V_90 , 0 ) ;
F_6 ( V_2 , V_74 , V_91 ) ;
F_7 ( V_5 , false ) ;
F_6 ( V_2 , V_92 , 0 ) ;
F_6 ( V_2 , V_76 , 0 ) ;
V_16 = V_2 -> V_93 ;
if ( V_11 -> V_94 ) {
F_6 ( V_2 , V_95 , 0 ) ;
F_6 ( V_2 , V_96 , ( 1 << ( V_11 -> V_94 / 2 ) ) - 1 ) ;
if ( V_11 -> V_94 == 1 )
V_16 |= V_97 ;
else
V_16 |= V_11 -> V_94 ;
}
F_6 ( V_2 , V_98 , V_16 ) ;
F_6 ( V_2 , V_78 , 0 ) ;
F_12 ( V_2 , V_78 , ~ 0 , 0 ) ;
F_5 ( V_5 ) ;
F_6 ( V_2 , V_99 , V_81 -> V_100 | V_101 ) ;
F_6 ( V_2 , V_102 , V_5 -> V_103 ) ;
F_6 ( V_2 , V_104 , V_5 -> V_105 [ 0 ] ) ;
if ( V_81 -> V_106 )
F_6 ( V_2 , V_107 , V_5 -> V_105 [ 1 ] ) ;
F_6 ( V_2 , V_108 , 0 ) ;
switch ( V_81 -> V_109 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_16 = V_114 | V_115 ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_16 = V_114 | V_115 | V_120 ;
break;
case V_121 :
default:
V_16 = V_114 ;
break;
}
F_6 ( V_2 , V_122 , V_16 ) ;
F_13 (plane, &dev->mode_config.plane_list) {
if ( V_85 -> V_7 == V_7 )
F_14 ( V_85 ) ;
}
F_6 ( V_2 , V_123 , V_124 ) ;
F_7 ( V_5 , true ) ;
V_5 -> V_86 = true ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
if ( ! V_5 -> V_86 )
return;
if ( V_5 -> V_125 ) {
F_16 ( V_2 -> V_126 , V_5 -> V_125 ) ;
V_5 -> V_125 = NULL ;
}
F_7 ( V_5 , false ) ;
F_6 ( V_2 , V_123 , 0 ) ;
F_3 ( V_2 ) ;
V_5 -> V_86 = false ;
}
void F_17 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
if ( V_5 -> V_127 != V_128 )
return;
F_10 ( V_5 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
int V_129 , int V_130 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_131 * V_88 = V_7 -> V_87 -> V_88 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
struct V_132 * V_133 ;
unsigned int V_134 ;
V_134 = V_5 -> V_81 -> V_106 ? 8 : V_5 -> V_81 -> V_134 ;
V_133 = F_20 ( V_88 , 0 ) ;
V_5 -> V_105 [ 0 ] = V_133 -> V_135 + V_88 -> V_136 [ 0 ]
+ V_130 * V_88 -> V_137 [ 0 ] + V_129 * V_134 / 8 ;
if ( V_5 -> V_81 -> V_106 ) {
V_134 = V_5 -> V_81 -> V_134 - 8 ;
V_133 = F_20 ( V_88 , 1 ) ;
V_5 -> V_105 [ 1 ] = V_133 -> V_135 + V_88 -> V_136 [ 1 ]
+ V_130 / ( V_134 == 4 ? 2 : 1 ) * V_88 -> V_137 [ 1 ]
+ V_129 * ( V_134 == 16 ? 2 : 1 ) ;
}
if ( V_5 -> V_125 )
F_21 ( V_2 -> V_126 , V_5 -> V_125 ,
V_5 -> V_105 [ 0 ] , V_5 -> V_105 [ 1 ] ,
& V_5 -> V_105 [ 0 ] , & V_5 -> V_105 [ 1 ] ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
F_19 ( V_5 , V_7 -> V_129 , V_7 -> V_130 ) ;
F_23 ( V_2 , V_104 , V_5 -> V_105 [ 0 ] ) ;
if ( V_5 -> V_81 -> V_106 )
F_23 ( V_2 , V_107 , V_5 -> V_105 [ 1 ] ) ;
F_6 ( V_2 , V_138 , F_8 ( V_2 , V_138 ) ^ V_139 ) ;
}
static void F_24 ( struct V_6 * V_7 , int V_15 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
if ( V_5 -> V_127 == V_15 )
return;
if ( V_15 == V_128 )
F_10 ( V_5 ) ;
else
F_15 ( V_5 ) ;
V_5 -> V_127 = V_15 ;
}
static bool F_26 ( struct V_6 * V_7 ,
const struct V_14 * V_15 ,
struct V_14 * V_140 )
{
return true ;
}
static void F_27 ( struct V_6 * V_7 )
{
F_24 ( V_7 , V_141 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_14 * V_15 ,
struct V_14 * V_140 ,
int V_129 , int V_130 ,
struct V_131 * V_142 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
const struct V_143 * V_144 = V_2 -> V_12 -> V_126 ;
const struct V_80 * V_81 ;
void * V_125 ;
V_81 = V_80 ( V_7 -> V_87 -> V_88 -> V_89 ) ;
if ( V_81 == NULL ) {
F_29 ( V_2 -> V_8 , L_1 ,
V_7 -> V_87 -> V_88 -> V_89 ) ;
return - V_145 ;
}
V_5 -> V_81 = V_81 ;
V_5 -> V_103 = V_7 -> V_87 -> V_88 -> V_137 [ 0 ] ;
if ( V_2 -> V_126 ) {
if ( V_5 -> V_125 ) {
F_16 ( V_2 -> V_126 , V_5 -> V_125 ) ;
V_5 -> V_125 = NULL ;
}
V_125 = F_30 ( V_2 -> V_126 , V_144 ,
V_7 -> V_87 -> V_88 -> V_137 [ 0 ] ,
V_140 -> V_67 ,
V_81 -> V_126 ,
& V_5 -> V_103 ) ;
if ( ! F_31 ( V_125 ) )
V_5 -> V_125 = V_125 ;
}
F_19 ( V_5 , V_129 , V_130 ) ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
F_24 ( V_7 , V_128 ) ;
}
static int F_33 ( struct V_6 * V_7 , int V_129 , int V_130 ,
struct V_131 * V_142 )
{
F_22 ( F_25 ( V_7 ) ) ;
return 0 ;
}
void F_34 ( struct V_4 * V_5 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 ;
struct V_82 * V_8 = V_5 -> V_7 . V_8 ;
unsigned long V_18 ;
F_35 ( & V_8 -> V_150 , V_18 ) ;
V_149 = V_5 -> V_149 ;
if ( V_149 && V_149 -> V_151 . V_152 == V_147 ) {
V_5 -> V_149 = NULL ;
V_149 -> V_151 . V_153 ( & V_149 -> V_151 ) ;
F_36 ( V_8 , 0 ) ;
}
F_37 ( & V_8 -> V_150 , V_18 ) ;
}
void F_38 ( struct V_4 * V_5 )
{
struct V_148 * V_149 ;
struct V_82 * V_8 = V_5 -> V_7 . V_8 ;
unsigned long V_18 ;
F_35 ( & V_8 -> V_150 , V_18 ) ;
V_149 = V_5 -> V_149 ;
V_5 -> V_149 = NULL ;
if ( V_149 ) {
F_39 ( V_8 , 0 , V_149 ) ;
F_36 ( V_8 , 0 ) ;
}
F_37 ( & V_8 -> V_150 , V_18 ) ;
}
static int F_40 ( struct V_6 * V_7 ,
struct V_131 * V_88 ,
struct V_148 * V_149 ,
T_2 V_154 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
struct V_82 * V_8 = V_5 -> V_7 . V_8 ;
unsigned long V_18 ;
F_35 ( & V_8 -> V_150 , V_18 ) ;
if ( V_5 -> V_149 != NULL ) {
F_37 ( & V_8 -> V_150 , V_18 ) ;
return - V_155 ;
}
F_37 ( & V_8 -> V_150 , V_18 ) ;
V_7 -> V_87 -> V_88 = V_88 ;
F_22 ( V_5 ) ;
if ( V_149 ) {
V_149 -> V_156 = 0 ;
F_41 ( V_8 , 0 ) ;
F_35 ( & V_8 -> V_150 , V_18 ) ;
V_5 -> V_149 = V_149 ;
F_37 ( & V_8 -> V_150 , V_18 ) ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 . V_7 ;
int V_3 ;
V_2 -> V_7 . V_127 = V_141 ;
V_3 = F_43 ( V_2 -> V_83 , V_7 , & V_157 ) ;
if ( V_3 < 0 )
return V_3 ;
F_44 ( V_7 , & V_158 ) ;
return 0 ;
}
static void F_45 ( struct V_159 * V_160 , int V_15 )
{
struct V_161 * V_162 = F_46 ( V_160 ) ;
struct V_1 * V_2 = V_160 -> V_8 -> V_9 ;
struct V_163 * V_164 = & V_2 -> V_165 ;
if ( V_162 -> V_127 == V_15 )
return;
F_47 ( V_164 , V_15 ) ;
V_162 -> V_127 = V_15 ;
}
static bool F_48 ( struct V_159 * V_160 ,
const struct V_14 * V_15 ,
struct V_14 * V_140 )
{
struct V_82 * V_8 = V_160 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_166 * V_165 = & V_2 -> V_165 . V_165 ;
const struct V_14 * V_167 ;
if ( F_49 ( & V_165 -> V_168 ) ) {
F_29 ( V_8 -> V_8 , L_2 ) ;
return false ;
}
V_167 = F_50 ( & V_165 -> V_168 ,
struct V_14 , V_169 ) ;
F_51 ( V_140 , V_167 ) ;
return true ;
}
static void F_52 ( struct V_159 * V_160 )
{
}
static void F_53 ( struct V_159 * V_160 ,
struct V_14 * V_15 ,
struct V_14 * V_140 )
{
}
static void F_54 ( struct V_159 * V_160 )
{
}
static void F_55 ( struct V_159 * V_160 )
{
F_56 ( V_160 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_159 * V_160 = & V_2 -> V_160 . V_160 ;
int V_3 ;
V_2 -> V_160 . V_127 = V_141 ;
V_160 -> V_170 = 1 ;
V_3 = F_58 ( V_2 -> V_83 , V_160 , & V_171 ,
V_172 ) ;
if ( V_3 < 0 )
return V_3 ;
F_59 ( V_160 , & V_173 ) ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , bool V_174 )
{
unsigned long V_18 ;
T_1 V_175 ;
F_35 ( & V_2 -> V_176 , V_18 ) ;
V_175 = F_8 ( V_2 , V_92 ) | V_177 ;
if ( V_174 )
V_175 |= V_178 ;
else
V_175 &= ~ V_178 ;
F_6 ( V_2 , V_92 , V_175 ) ;
F_37 ( & V_2 -> V_176 , V_18 ) ;
}
static int F_61 ( struct V_166 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_8 -> V_9 ;
struct V_14 * V_15 ;
V_15 = F_62 ( V_165 -> V_8 ) ;
if ( V_15 == NULL )
return 0 ;
V_15 -> type = V_179 | V_180 ;
V_15 -> clock = V_2 -> V_12 -> V_181 . V_15 . clock ;
V_15 -> V_60 = V_2 -> V_12 -> V_181 . V_15 . V_60 ;
V_15 -> V_64 = V_2 -> V_12 -> V_181 . V_15 . V_64 ;
V_15 -> V_63 = V_2 -> V_12 -> V_181 . V_15 . V_63 ;
V_15 -> V_61 = V_2 -> V_12 -> V_181 . V_15 . V_61 ;
V_15 -> V_67 = V_2 -> V_12 -> V_181 . V_15 . V_67 ;
V_15 -> V_71 = V_2 -> V_12 -> V_181 . V_15 . V_71 ;
V_15 -> V_70 = V_2 -> V_12 -> V_181 . V_15 . V_70 ;
V_15 -> V_68 = V_2 -> V_12 -> V_181 . V_15 . V_68 ;
V_15 -> V_18 = V_2 -> V_12 -> V_181 . V_15 . V_18 ;
F_63 ( V_15 ) ;
F_64 ( V_165 , V_15 ) ;
V_165 -> V_182 . V_183 = V_2 -> V_12 -> V_181 . V_183 ;
V_165 -> V_182 . V_184 = V_2 -> V_12 -> V_181 . V_184 ;
return 1 ;
}
static int F_65 ( struct V_166 * V_165 ,
struct V_14 * V_15 )
{
return V_185 ;
}
static struct V_159 *
F_66 ( struct V_166 * V_165 )
{
struct V_163 * V_164 = F_67 ( V_165 ) ;
return V_164 -> V_160 ;
}
static void F_68 ( struct V_166 * V_165 )
{
struct V_163 * V_164 = F_67 ( V_165 ) ;
F_69 ( V_164 ) ;
F_70 ( V_165 ) ;
F_71 ( V_165 ) ;
}
static enum V_186
F_72 ( struct V_166 * V_165 , bool V_187 )
{
return V_188 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
struct V_166 * V_165 = & V_2 -> V_165 . V_165 ;
int V_3 ;
V_2 -> V_165 . V_160 = V_160 ;
V_165 -> V_182 . V_183 = V_2 -> V_12 -> V_181 . V_183 ;
V_165 -> V_182 . V_184 = V_2 -> V_12 -> V_181 . V_184 ;
V_3 = F_74 ( V_2 -> V_83 , V_165 , & V_189 ,
V_190 ) ;
if ( V_3 < 0 )
return V_3 ;
F_75 ( V_165 , & V_191 ) ;
V_3 = F_76 ( V_165 ) ;
if ( V_3 < 0 )
goto V_192;
V_3 = F_77 ( & V_2 -> V_165 ) ;
if ( V_3 < 0 )
goto V_193;
V_3 = F_78 ( V_165 , V_160 ) ;
if ( V_3 < 0 )
goto V_194;
V_165 -> V_160 = V_160 ;
F_79 ( V_165 , V_141 ) ;
F_80 ( & V_165 -> V_151 ,
V_2 -> V_83 -> V_195 . V_196 , V_141 ) ;
return 0 ;
V_194:
F_69 ( & V_2 -> V_165 ) ;
V_193:
F_70 ( V_165 ) ;
V_192:
F_71 ( V_165 ) ;
return V_3 ;
}
