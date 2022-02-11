static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> clock )
F_2 ( V_2 -> clock ) ;
#if 0
if (sdev->meram_dev && sdev->meram_dev->pdev)
pm_runtime_get_sync(&sdev->meram_dev->pdev->dev);
#endif
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
static void F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
const struct V_9 * V_10 = & V_2 -> V_11 -> V_12 ;
const struct V_13 * V_14 = & V_6 -> V_14 ;
T_1 V_15 ;
V_15 = V_2 -> V_16
| ( ( V_14 -> V_17 & V_18 ) ? 0 : V_19 )
| ( ( V_14 -> V_17 & V_20 ) ? 0 : V_21 )
| ( ( V_10 -> V_17 & V_22 ) ? V_23 : 0 )
| ( ( V_10 -> V_17 & V_24 ) ? V_25 : 0 )
| ( ( V_10 -> V_17 & V_26 ) ? V_27 : 0 )
| ( ( V_10 -> V_17 & V_28 ) ? V_29 : 0 )
| ( ( V_10 -> V_17 & V_30 ) ? V_31 : 0 ) ;
F_6 ( V_2 , V_32 , V_15 ) ;
if ( V_10 -> V_33 >= V_34 &&
V_10 -> V_33 <= V_35 ) {
V_15 = ( V_10 -> V_36 . V_37 << V_38 )
| ( V_10 -> V_36 . V_39 ? V_40 : 0 )
| ( V_10 -> V_36 . V_41 ? V_42 : 0 )
| ( V_10 -> V_36 . V_43 << V_44 )
| ( V_10 -> V_36 . V_45 << V_46 )
| ( V_10 -> V_36 . V_47 << V_48 ) ;
F_6 ( V_2 , V_49 , V_15 ) ;
V_15 = ( V_10 -> V_36 . V_50 << V_51 )
| ( V_10 -> V_36 . V_52 << V_53 )
| ( V_10 -> V_36 . V_54 << V_55 )
| ( V_10 -> V_36 . V_56 << V_57 ) ;
F_6 ( V_2 , V_58 , V_15 ) ;
}
V_15 = ( ( V_14 -> V_59 / 8 ) << 16 )
| ( V_14 -> V_60 / 8 ) ;
F_6 ( V_2 , V_61 , V_15 ) ;
V_15 = ( ( ( V_14 -> V_62 - V_14 -> V_63 ) / 8 ) << 16 )
| ( V_14 -> V_63 / 8 ) ;
F_6 ( V_2 , V_64 , V_15 ) ;
V_15 = ( ( V_14 -> V_59 & 7 ) << 24 ) | ( ( V_14 -> V_60 & 7 ) << 16 )
| ( ( ( V_14 -> V_62 - V_14 -> V_63 ) & 7 ) << 8 )
| ( V_14 -> V_63 & 7 ) ;
F_6 ( V_2 , V_65 , V_15 ) ;
V_15 = ( ( V_14 -> V_66 ) << 16 )
| V_14 -> V_67 ;
F_6 ( V_2 , V_68 , V_15 ) ;
V_15 = ( ( V_14 -> V_69 - V_14 -> V_70 ) << 16 )
| V_14 -> V_70 ;
F_6 ( V_2 , V_71 , V_15 ) ;
}
static void F_7 ( struct V_3 * V_4 , bool V_72 )
{
struct V_1 * V_2 = V_4 -> V_6 . V_7 -> V_8 ;
T_1 V_15 ;
V_15 = F_8 ( V_2 , V_73 ) ;
if ( V_72 )
F_6 ( V_2 , V_73 , V_15 | V_74 ) ;
else
F_6 ( V_2 , V_73 , V_15 & ~ V_74 ) ;
while ( 1 ) {
V_15 = F_8 ( V_2 , V_75 ) & V_76 ;
if ( ( V_72 && V_15 ) || ( ! V_72 && ! V_15 ) )
break;
F_9 () ;
}
if ( ! V_72 ) {
F_6 ( V_2 , V_77 , V_78 ) ;
}
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
const struct V_9 * V_10 = & V_2 -> V_11 -> V_12 ;
const struct V_79 * V_80 ;
struct V_81 * V_7 = V_2 -> V_82 ;
struct V_83 * V_84 ;
T_1 V_15 ;
if ( V_4 -> V_85 )
return;
V_80 = V_79 ( V_6 -> V_86 -> V_87 ) ;
if ( F_11 ( V_80 == NULL ) )
return;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_73 , F_8 ( V_2 , V_73 ) | V_88 ) ;
F_12 ( V_2 , V_73 , V_88 , 0 ) ;
F_6 ( V_2 , V_73 , V_89 ) ;
F_7 ( V_4 , false ) ;
F_6 ( V_2 , V_90 , 0 ) ;
F_6 ( V_2 , V_75 , 0 ) ;
V_15 = V_2 -> V_91 ;
if ( V_10 -> V_92 ) {
F_6 ( V_2 , V_93 , 0 ) ;
F_6 ( V_2 , V_94 , ( 1 << ( V_10 -> V_92 / 2 ) ) - 1 ) ;
if ( V_10 -> V_92 == 1 )
V_15 |= V_95 ;
else
V_15 |= V_10 -> V_92 ;
}
F_6 ( V_2 , V_96 , V_15 ) ;
F_6 ( V_2 , V_77 , 0 ) ;
F_12 ( V_2 , V_77 , ~ 0 , 0 ) ;
F_5 ( V_4 ) ;
F_6 ( V_2 , V_97 , V_80 -> V_98 | V_99 ) ;
F_6 ( V_2 , V_100 , V_4 -> V_101 ) ;
F_6 ( V_2 , V_102 , V_4 -> V_103 [ 0 ] ) ;
if ( V_80 -> V_104 )
F_6 ( V_2 , V_105 , V_4 -> V_103 [ 1 ] ) ;
F_6 ( V_2 , V_106 , 0 ) ;
switch ( V_80 -> V_107 ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_15 = V_112 | V_113 ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_15 = V_112 | V_113 | V_118 ;
break;
case V_119 :
default:
V_15 = V_112 ;
break;
}
F_6 ( V_2 , V_120 , V_15 ) ;
F_13 (plane, &dev->mode_config.plane_list, head) {
if ( V_84 -> V_6 == V_6 )
F_14 ( V_84 ) ;
}
F_6 ( V_2 , V_121 , V_122 ) ;
F_7 ( V_4 , true ) ;
V_4 -> V_85 = true ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
if ( ! V_4 -> V_85 )
return;
if ( V_4 -> V_123 ) {
F_16 ( V_2 -> V_124 , V_4 -> V_123 ) ;
V_4 -> V_123 = NULL ;
}
F_7 ( V_4 , false ) ;
F_6 ( V_2 , V_121 , 0 ) ;
F_3 ( V_2 ) ;
V_4 -> V_85 = false ;
}
void F_17 ( struct V_3 * V_4 )
{
F_15 ( V_4 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
if ( V_4 -> V_125 != V_126 )
return;
F_10 ( V_4 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
int V_127 , int V_128 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_129 * V_86 = V_6 -> V_86 ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
struct V_130 * V_131 ;
unsigned int V_132 ;
V_132 = V_4 -> V_80 -> V_104 ? 8 : V_4 -> V_80 -> V_132 ;
V_131 = F_20 ( V_86 , 0 ) ;
V_4 -> V_103 [ 0 ] = V_131 -> V_133 + V_86 -> V_134 [ 0 ]
+ V_128 * V_86 -> V_135 [ 0 ] + V_127 * V_132 / 8 ;
if ( V_4 -> V_80 -> V_104 ) {
V_132 = V_4 -> V_80 -> V_132 - 8 ;
V_131 = F_20 ( V_86 , 1 ) ;
V_4 -> V_103 [ 1 ] = V_131 -> V_133 + V_86 -> V_134 [ 1 ]
+ V_128 / ( V_132 == 4 ? 2 : 1 ) * V_86 -> V_135 [ 1 ]
+ V_127 * ( V_132 == 16 ? 2 : 1 ) ;
}
if ( V_4 -> V_123 )
F_21 ( V_2 -> V_124 , V_4 -> V_123 ,
V_4 -> V_103 [ 0 ] , V_4 -> V_103 [ 1 ] ,
& V_4 -> V_103 [ 0 ] , & V_4 -> V_103 [ 1 ] ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
F_19 ( V_4 , V_6 -> V_127 , V_6 -> V_128 ) ;
F_23 ( V_2 , V_102 , V_4 -> V_103 [ 0 ] ) ;
if ( V_4 -> V_80 -> V_104 )
F_23 ( V_2 , V_105 , V_4 -> V_103 [ 1 ] ) ;
F_6 ( V_2 , V_136 , F_8 ( V_2 , V_136 ) ^ V_137 ) ;
}
static void F_24 ( struct V_5 * V_6 , int V_14 )
{
struct V_3 * V_4 = F_25 ( V_6 ) ;
if ( V_4 -> V_125 == V_14 )
return;
if ( V_14 == V_126 )
F_10 ( V_4 ) ;
else
F_15 ( V_4 ) ;
V_4 -> V_125 = V_14 ;
}
static bool F_26 ( struct V_5 * V_6 ,
const struct V_13 * V_14 ,
struct V_13 * V_138 )
{
return true ;
}
static void F_27 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_139 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_13 * V_14 ,
struct V_13 * V_138 ,
int V_127 , int V_128 ,
struct V_129 * V_140 )
{
struct V_3 * V_4 = F_25 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_7 -> V_8 ;
const struct V_141 * V_142 = V_2 -> V_11 -> V_124 ;
const struct V_79 * V_80 ;
void * V_123 ;
V_80 = V_79 ( V_6 -> V_86 -> V_87 ) ;
if ( V_80 == NULL ) {
F_29 ( V_2 -> V_7 , L_1 ,
V_6 -> V_86 -> V_87 ) ;
return - V_143 ;
}
V_4 -> V_80 = V_80 ;
V_4 -> V_101 = V_6 -> V_86 -> V_135 [ 0 ] ;
if ( V_2 -> V_124 ) {
if ( V_4 -> V_123 ) {
F_16 ( V_2 -> V_124 , V_4 -> V_123 ) ;
V_4 -> V_123 = NULL ;
}
V_123 = F_30 ( V_2 -> V_124 , V_142 ,
V_6 -> V_86 -> V_135 [ 0 ] ,
V_138 -> V_66 ,
V_80 -> V_124 ,
& V_4 -> V_101 ) ;
if ( ! F_31 ( V_123 ) )
V_4 -> V_123 = V_123 ;
}
F_19 ( V_4 , V_127 , V_128 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_126 ) ;
}
static int F_33 ( struct V_5 * V_6 , int V_127 , int V_128 ,
struct V_129 * V_140 )
{
F_22 ( F_25 ( V_6 ) ) ;
return 0 ;
}
void F_34 ( struct V_3 * V_4 ,
struct V_144 * V_145 )
{
struct V_146 * V_147 ;
struct V_81 * V_7 = V_4 -> V_6 . V_7 ;
unsigned long V_17 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
V_147 = V_4 -> V_147 ;
if ( V_147 && V_147 -> V_149 . V_150 == V_145 ) {
V_4 -> V_147 = NULL ;
V_147 -> V_149 . V_151 ( & V_147 -> V_149 ) ;
F_36 ( V_7 , 0 ) ;
}
F_37 ( & V_7 -> V_148 , V_17 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_146 * V_147 ;
struct V_81 * V_7 = V_4 -> V_6 . V_7 ;
unsigned long V_17 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
V_147 = V_4 -> V_147 ;
V_4 -> V_147 = NULL ;
if ( V_147 ) {
F_39 ( V_7 , 0 , V_147 ) ;
F_36 ( V_7 , 0 ) ;
}
F_37 ( & V_7 -> V_148 , V_17 ) ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_129 * V_86 ,
struct V_146 * V_147 ,
T_2 V_152 )
{
struct V_3 * V_4 = F_25 ( V_6 ) ;
struct V_81 * V_7 = V_4 -> V_6 . V_7 ;
unsigned long V_17 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
if ( V_4 -> V_147 != NULL ) {
F_37 ( & V_7 -> V_148 , V_17 ) ;
return - V_153 ;
}
F_37 ( & V_7 -> V_148 , V_17 ) ;
V_6 -> V_86 = V_86 ;
F_22 ( V_4 ) ;
if ( V_147 ) {
V_147 -> V_154 = 0 ;
F_41 ( V_7 , 0 ) ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
V_4 -> V_147 = V_147 ;
F_37 ( & V_7 -> V_148 , V_17 ) ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 . V_6 ;
int V_155 ;
V_2 -> V_6 . V_125 = V_139 ;
V_155 = F_43 ( V_2 -> V_82 , V_6 , & V_156 ) ;
if ( V_155 < 0 )
return V_155 ;
F_44 ( V_6 , & V_157 ) ;
return 0 ;
}
static void F_45 ( struct V_158 * V_159 , int V_14 )
{
struct V_160 * V_161 = F_46 ( V_159 ) ;
struct V_1 * V_2 = V_159 -> V_7 -> V_8 ;
struct V_162 * V_163 = & V_2 -> V_164 ;
if ( V_161 -> V_125 == V_14 )
return;
F_47 ( V_163 , V_14 ) ;
V_161 -> V_125 = V_14 ;
}
static bool F_48 ( struct V_158 * V_159 ,
const struct V_13 * V_14 ,
struct V_13 * V_138 )
{
struct V_81 * V_7 = V_159 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 ;
struct V_165 * V_164 = & V_2 -> V_164 . V_164 ;
const struct V_13 * V_166 ;
if ( F_49 ( & V_164 -> V_167 ) ) {
F_29 ( V_7 -> V_7 , L_2 ) ;
return false ;
}
V_166 = F_50 ( & V_164 -> V_167 ,
struct V_13 , V_168 ) ;
F_51 ( V_138 , V_166 ) ;
return true ;
}
static void F_52 ( struct V_158 * V_159 )
{
}
static void F_53 ( struct V_158 * V_159 ,
struct V_13 * V_14 ,
struct V_13 * V_138 )
{
}
static void F_54 ( struct V_158 * V_159 )
{
}
static void F_55 ( struct V_158 * V_159 )
{
F_56 ( V_159 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_158 * V_159 = & V_2 -> V_159 . V_159 ;
int V_155 ;
V_2 -> V_159 . V_125 = V_139 ;
V_159 -> V_169 = 1 ;
V_155 = F_58 ( V_2 -> V_82 , V_159 , & V_170 ,
V_171 ) ;
if ( V_155 < 0 )
return V_155 ;
F_59 ( V_159 , & V_172 ) ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , bool V_173 )
{
unsigned long V_17 ;
T_1 V_174 ;
F_35 ( & V_2 -> V_175 , V_17 ) ;
V_174 = F_8 ( V_2 , V_90 ) | V_176 ;
if ( V_173 )
V_174 |= V_177 ;
else
V_174 &= ~ V_177 ;
F_6 ( V_2 , V_90 , V_174 ) ;
F_37 ( & V_2 -> V_175 , V_17 ) ;
}
static int F_61 ( struct V_165 * V_164 )
{
struct V_1 * V_2 = V_164 -> V_7 -> V_8 ;
struct V_13 * V_14 ;
V_14 = F_62 ( V_164 -> V_7 ) ;
if ( V_14 == NULL )
return 0 ;
V_14 -> type = V_178 | V_179 ;
V_14 -> clock = V_2 -> V_11 -> V_180 . V_14 . clock ;
V_14 -> V_59 = V_2 -> V_11 -> V_180 . V_14 . V_59 ;
V_14 -> V_63 = V_2 -> V_11 -> V_180 . V_14 . V_63 ;
V_14 -> V_62 = V_2 -> V_11 -> V_180 . V_14 . V_62 ;
V_14 -> V_60 = V_2 -> V_11 -> V_180 . V_14 . V_60 ;
V_14 -> V_66 = V_2 -> V_11 -> V_180 . V_14 . V_66 ;
V_14 -> V_70 = V_2 -> V_11 -> V_180 . V_14 . V_70 ;
V_14 -> V_69 = V_2 -> V_11 -> V_180 . V_14 . V_69 ;
V_14 -> V_67 = V_2 -> V_11 -> V_180 . V_14 . V_67 ;
V_14 -> V_17 = V_2 -> V_11 -> V_180 . V_14 . V_17 ;
F_63 ( V_14 ) ;
F_64 ( V_164 , V_14 ) ;
V_164 -> V_181 . V_182 = V_2 -> V_11 -> V_180 . V_182 ;
V_164 -> V_181 . V_183 = V_2 -> V_11 -> V_180 . V_183 ;
return 1 ;
}
static int F_65 ( struct V_165 * V_164 ,
struct V_13 * V_14 )
{
return V_184 ;
}
static struct V_158 *
F_66 ( struct V_165 * V_164 )
{
struct V_162 * V_163 = F_67 ( V_164 ) ;
return V_163 -> V_159 ;
}
static void F_68 ( struct V_165 * V_164 )
{
struct V_162 * V_163 = F_67 ( V_164 ) ;
F_69 ( V_163 ) ;
F_70 ( V_164 ) ;
F_71 ( V_164 ) ;
}
static enum V_185
F_72 ( struct V_165 * V_164 , bool V_186 )
{
return V_187 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
struct V_165 * V_164 = & V_2 -> V_164 . V_164 ;
int V_155 ;
V_2 -> V_164 . V_159 = V_159 ;
V_164 -> V_181 . V_182 = V_2 -> V_11 -> V_180 . V_182 ;
V_164 -> V_181 . V_183 = V_2 -> V_11 -> V_180 . V_183 ;
V_155 = F_74 ( V_2 -> V_82 , V_164 , & V_188 ,
V_189 ) ;
if ( V_155 < 0 )
return V_155 ;
F_75 ( V_164 , & V_190 ) ;
V_155 = F_76 ( V_164 ) ;
if ( V_155 < 0 )
goto V_191;
V_155 = F_77 ( & V_2 -> V_164 ) ;
if ( V_155 < 0 )
goto V_192;
V_155 = F_78 ( V_164 , V_159 ) ;
if ( V_155 < 0 )
goto V_193;
V_164 -> V_159 = V_159 ;
F_79 ( V_164 , V_139 ) ;
F_80 ( & V_164 -> V_149 ,
V_2 -> V_82 -> V_194 . V_195 , V_139 ) ;
return 0 ;
V_193:
F_69 ( & V_2 -> V_164 ) ;
V_192:
F_70 ( V_164 ) ;
V_191:
F_71 ( V_164 ) ;
return V_155 ;
}
