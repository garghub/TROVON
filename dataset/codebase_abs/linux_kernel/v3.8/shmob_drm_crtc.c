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
struct V_152 V_153 ;
unsigned long V_17 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
V_147 = V_4 -> V_147 ;
V_4 -> V_147 = NULL ;
F_37 ( & V_7 -> V_148 , V_17 ) ;
if ( V_147 == NULL )
return;
V_147 -> V_147 . V_154 = F_39 ( V_7 , 0 , & V_153 ) ;
V_147 -> V_147 . V_155 = V_153 . V_155 ;
V_147 -> V_147 . V_156 = V_153 . V_156 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
F_40 ( & V_147 -> V_149 . V_157 , & V_147 -> V_149 . V_150 -> V_158 ) ;
F_41 ( & V_147 -> V_149 . V_150 -> V_159 ) ;
F_37 ( & V_7 -> V_148 , V_17 ) ;
F_36 ( V_7 , 0 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_129 * V_86 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = F_25 ( V_6 ) ;
struct V_81 * V_7 = V_4 -> V_6 . V_7 ;
unsigned long V_17 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
if ( V_4 -> V_147 != NULL ) {
F_37 ( & V_7 -> V_148 , V_17 ) ;
return - V_160 ;
}
F_37 ( & V_7 -> V_148 , V_17 ) ;
V_6 -> V_86 = V_86 ;
F_22 ( V_4 ) ;
if ( V_147 ) {
V_147 -> V_161 = 0 ;
F_35 ( & V_7 -> V_148 , V_17 ) ;
V_4 -> V_147 = V_147 ;
F_37 ( & V_7 -> V_148 , V_17 ) ;
F_43 ( V_7 , 0 ) ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 . V_6 ;
int V_162 ;
V_2 -> V_6 . V_125 = V_139 ;
V_162 = F_45 ( V_2 -> V_82 , V_6 , & V_163 ) ;
if ( V_162 < 0 )
return V_162 ;
F_46 ( V_6 , & V_164 ) ;
return 0 ;
}
static void F_47 ( struct V_165 * V_166 , int V_14 )
{
struct V_167 * V_168 = F_48 ( V_166 ) ;
struct V_1 * V_2 = V_166 -> V_7 -> V_8 ;
struct V_169 * V_170 = & V_2 -> V_171 ;
if ( V_168 -> V_125 == V_14 )
return;
F_49 ( V_170 , V_14 ) ;
V_168 -> V_125 = V_14 ;
}
static bool F_50 ( struct V_165 * V_166 ,
const struct V_13 * V_14 ,
struct V_13 * V_138 )
{
struct V_81 * V_7 = V_166 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 ;
struct V_172 * V_171 = & V_2 -> V_171 . V_171 ;
const struct V_13 * V_173 ;
if ( F_51 ( & V_171 -> V_174 ) ) {
F_29 ( V_7 -> V_7 , L_2 ) ;
return false ;
}
V_173 = F_52 ( & V_171 -> V_174 ,
struct V_13 , V_175 ) ;
F_53 ( V_138 , V_173 ) ;
return true ;
}
static void F_54 ( struct V_165 * V_166 )
{
}
static void F_55 ( struct V_165 * V_166 ,
struct V_13 * V_14 ,
struct V_13 * V_138 )
{
}
static void F_56 ( struct V_165 * V_166 )
{
}
static void F_57 ( struct V_165 * V_166 )
{
F_58 ( V_166 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_165 * V_166 = & V_2 -> V_166 . V_166 ;
int V_162 ;
V_2 -> V_166 . V_125 = V_139 ;
V_166 -> V_176 = 1 ;
V_162 = F_60 ( V_2 -> V_82 , V_166 , & V_177 ,
V_178 ) ;
if ( V_162 < 0 )
return V_162 ;
F_61 ( V_166 , & V_179 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 , bool V_180 )
{
unsigned long V_17 ;
T_1 V_181 ;
F_35 ( & V_2 -> V_182 , V_17 ) ;
V_181 = F_8 ( V_2 , V_90 ) | V_183 ;
if ( V_180 )
V_181 |= V_184 ;
else
V_181 &= ~ V_184 ;
F_6 ( V_2 , V_90 , V_181 ) ;
F_37 ( & V_2 -> V_182 , V_17 ) ;
}
static int F_63 ( struct V_172 * V_171 )
{
struct V_1 * V_2 = V_171 -> V_7 -> V_8 ;
struct V_13 * V_14 ;
V_14 = F_64 ( V_171 -> V_7 ) ;
if ( V_14 == NULL )
return 0 ;
V_14 -> type = V_185 | V_186 ;
V_14 -> clock = V_2 -> V_11 -> V_187 . V_14 . clock ;
V_14 -> V_59 = V_2 -> V_11 -> V_187 . V_14 . V_59 ;
V_14 -> V_63 = V_2 -> V_11 -> V_187 . V_14 . V_63 ;
V_14 -> V_62 = V_2 -> V_11 -> V_187 . V_14 . V_62 ;
V_14 -> V_60 = V_2 -> V_11 -> V_187 . V_14 . V_60 ;
V_14 -> V_66 = V_2 -> V_11 -> V_187 . V_14 . V_66 ;
V_14 -> V_70 = V_2 -> V_11 -> V_187 . V_14 . V_70 ;
V_14 -> V_69 = V_2 -> V_11 -> V_187 . V_14 . V_69 ;
V_14 -> V_67 = V_2 -> V_11 -> V_187 . V_14 . V_67 ;
V_14 -> V_17 = V_2 -> V_11 -> V_187 . V_14 . V_17 ;
F_65 ( V_14 ) ;
F_66 ( V_171 , V_14 ) ;
V_171 -> V_188 . V_189 = V_2 -> V_11 -> V_187 . V_189 ;
V_171 -> V_188 . V_190 = V_2 -> V_11 -> V_187 . V_190 ;
return 1 ;
}
static int F_67 ( struct V_172 * V_171 ,
struct V_13 * V_14 )
{
return V_191 ;
}
static struct V_165 *
F_68 ( struct V_172 * V_171 )
{
struct V_169 * V_170 = F_69 ( V_171 ) ;
return V_170 -> V_166 ;
}
static void F_70 ( struct V_172 * V_171 )
{
struct V_169 * V_170 = F_69 ( V_171 ) ;
F_71 ( V_170 ) ;
F_72 ( V_171 ) ;
F_73 ( V_171 ) ;
}
static enum V_192
F_74 ( struct V_172 * V_171 , bool V_193 )
{
return V_194 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_172 * V_171 = & V_2 -> V_171 . V_171 ;
int V_162 ;
V_2 -> V_171 . V_166 = V_166 ;
V_171 -> V_188 . V_189 = V_2 -> V_11 -> V_187 . V_189 ;
V_171 -> V_188 . V_190 = V_2 -> V_11 -> V_187 . V_190 ;
V_162 = F_76 ( V_2 -> V_82 , V_171 , & V_195 ,
V_196 ) ;
if ( V_162 < 0 )
return V_162 ;
F_77 ( V_171 , & V_197 ) ;
V_162 = F_78 ( V_171 ) ;
if ( V_162 < 0 )
goto V_198;
V_162 = F_79 ( & V_2 -> V_171 ) ;
if ( V_162 < 0 )
goto V_199;
V_162 = F_80 ( V_171 , V_166 ) ;
if ( V_162 < 0 )
goto V_200;
V_171 -> V_166 = V_166 ;
F_81 ( V_171 , V_139 ) ;
F_82 ( & V_171 -> V_149 ,
V_2 -> V_82 -> V_201 . V_202 , V_139 ) ;
return 0 ;
V_200:
F_71 ( & V_2 -> V_171 ) ;
V_199:
F_72 ( V_171 ) ;
V_198:
F_73 ( V_171 ) ;
return V_162 ;
}
