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
V_81 = V_80 ( V_7 -> V_87 -> V_88 -> V_81 -> V_81 ) ;
if ( F_11 ( V_81 == NULL ) )
return;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return;
F_6 ( V_2 , V_74 , F_8 ( V_2 , V_74 ) | V_89 ) ;
F_12 ( V_2 , V_74 , V_89 , 0 ) ;
F_6 ( V_2 , V_74 , V_90 ) ;
F_7 ( V_5 , false ) ;
F_6 ( V_2 , V_91 , 0 ) ;
F_6 ( V_2 , V_76 , 0 ) ;
V_16 = V_2 -> V_92 ;
if ( V_11 -> V_93 ) {
F_6 ( V_2 , V_94 , 0 ) ;
F_6 ( V_2 , V_95 , ( 1 << ( V_11 -> V_93 / 2 ) ) - 1 ) ;
if ( V_11 -> V_93 == 1 )
V_16 |= V_96 ;
else
V_16 |= V_11 -> V_93 ;
}
F_6 ( V_2 , V_97 , V_16 ) ;
F_6 ( V_2 , V_78 , 0 ) ;
F_12 ( V_2 , V_78 , ~ 0 , 0 ) ;
F_5 ( V_5 ) ;
F_6 ( V_2 , V_98 , V_81 -> V_99 | V_100 ) ;
F_6 ( V_2 , V_101 , V_5 -> V_102 ) ;
F_6 ( V_2 , V_103 , V_5 -> V_104 [ 0 ] ) ;
if ( V_81 -> V_105 )
F_6 ( V_2 , V_106 , V_5 -> V_104 [ 1 ] ) ;
F_6 ( V_2 , V_107 , 0 ) ;
switch ( V_81 -> V_108 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_16 = V_113 | V_114 ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_16 = V_113 | V_114 | V_119 ;
break;
case V_120 :
default:
V_16 = V_113 ;
break;
}
F_6 ( V_2 , V_121 , V_16 ) ;
F_13 (plane, dev) {
if ( V_85 -> V_7 == V_7 )
F_14 ( V_85 ) ;
}
F_6 ( V_2 , V_122 , V_123 ) ;
F_7 ( V_5 , true ) ;
V_5 -> V_86 = true ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
if ( ! V_5 -> V_86 )
return;
if ( V_5 -> V_124 ) {
F_16 ( V_2 -> V_125 , V_5 -> V_124 ) ;
V_5 -> V_124 = NULL ;
}
F_7 ( V_5 , false ) ;
F_6 ( V_2 , V_122 , 0 ) ;
F_3 ( V_2 ) ;
V_5 -> V_86 = false ;
}
void F_17 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
if ( V_5 -> V_126 != V_127 )
return;
F_10 ( V_5 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
int V_128 , int V_129 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_130 * V_88 = V_7 -> V_87 -> V_88 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
struct V_131 * V_132 ;
unsigned int V_133 ;
V_133 = V_5 -> V_81 -> V_105 ? 8 : V_5 -> V_81 -> V_133 ;
V_132 = F_20 ( V_88 , 0 ) ;
V_5 -> V_104 [ 0 ] = V_132 -> V_134 + V_88 -> V_135 [ 0 ]
+ V_129 * V_88 -> V_136 [ 0 ] + V_128 * V_133 / 8 ;
if ( V_5 -> V_81 -> V_105 ) {
V_133 = V_5 -> V_81 -> V_133 - 8 ;
V_132 = F_20 ( V_88 , 1 ) ;
V_5 -> V_104 [ 1 ] = V_132 -> V_134 + V_88 -> V_135 [ 1 ]
+ V_129 / ( V_133 == 4 ? 2 : 1 ) * V_88 -> V_136 [ 1 ]
+ V_128 * ( V_133 == 16 ? 2 : 1 ) ;
}
if ( V_5 -> V_124 )
F_21 ( V_2 -> V_125 , V_5 -> V_124 ,
V_5 -> V_104 [ 0 ] , V_5 -> V_104 [ 1 ] ,
& V_5 -> V_104 [ 0 ] , & V_5 -> V_104 [ 1 ] ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
F_19 ( V_5 , V_7 -> V_128 , V_7 -> V_129 ) ;
F_23 ( V_2 , V_103 , V_5 -> V_104 [ 0 ] ) ;
if ( V_5 -> V_81 -> V_105 )
F_23 ( V_2 , V_106 , V_5 -> V_104 [ 1 ] ) ;
F_6 ( V_2 , V_137 , F_8 ( V_2 , V_137 ) ^ V_138 ) ;
}
static void F_24 ( struct V_6 * V_7 , int V_15 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
if ( V_5 -> V_126 == V_15 )
return;
if ( V_15 == V_127 )
F_10 ( V_5 ) ;
else
F_15 ( V_5 ) ;
V_5 -> V_126 = V_15 ;
}
static void F_26 ( struct V_6 * V_7 )
{
F_24 ( V_7 , V_139 ) ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_14 * V_15 ,
struct V_14 * V_140 ,
int V_128 , int V_129 ,
struct V_130 * V_141 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
const struct V_142 * V_143 = V_2 -> V_12 -> V_125 ;
const struct V_80 * V_81 ;
void * V_124 ;
V_81 = V_80 ( V_7 -> V_87 -> V_88 -> V_81 -> V_81 ) ;
if ( V_81 == NULL ) {
F_28 ( V_2 -> V_8 , L_1 ,
V_7 -> V_87 -> V_88 -> V_81 -> V_81 ) ;
return - V_144 ;
}
V_5 -> V_81 = V_81 ;
V_5 -> V_102 = V_7 -> V_87 -> V_88 -> V_136 [ 0 ] ;
if ( V_2 -> V_125 ) {
if ( V_5 -> V_124 ) {
F_16 ( V_2 -> V_125 , V_5 -> V_124 ) ;
V_5 -> V_124 = NULL ;
}
V_124 = F_29 ( V_2 -> V_125 , V_143 ,
V_7 -> V_87 -> V_88 -> V_136 [ 0 ] ,
V_140 -> V_67 ,
V_81 -> V_125 ,
& V_5 -> V_102 ) ;
if ( ! F_30 ( V_124 ) )
V_5 -> V_124 = V_124 ;
}
F_19 ( V_5 , V_128 , V_129 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
F_24 ( V_7 , V_127 ) ;
}
static int F_32 ( struct V_6 * V_7 , int V_128 , int V_129 ,
struct V_130 * V_141 )
{
F_22 ( F_25 ( V_7 ) ) ;
return 0 ;
}
void F_33 ( struct V_4 * V_5 )
{
struct V_145 * V_146 ;
struct V_82 * V_8 = V_5 -> V_7 . V_8 ;
unsigned long V_18 ;
F_34 ( & V_8 -> V_147 , V_18 ) ;
V_146 = V_5 -> V_146 ;
V_5 -> V_146 = NULL ;
if ( V_146 ) {
F_35 ( & V_5 -> V_7 , V_146 ) ;
F_36 ( & V_5 -> V_7 ) ;
}
F_37 ( & V_8 -> V_147 , V_18 ) ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_130 * V_88 ,
struct V_145 * V_146 ,
T_2 V_148 ,
struct V_149 * V_150 )
{
struct V_4 * V_5 = F_25 ( V_7 ) ;
struct V_82 * V_8 = V_5 -> V_7 . V_8 ;
unsigned long V_18 ;
F_34 ( & V_8 -> V_147 , V_18 ) ;
if ( V_5 -> V_146 != NULL ) {
F_37 ( & V_8 -> V_147 , V_18 ) ;
return - V_151 ;
}
F_37 ( & V_8 -> V_147 , V_18 ) ;
V_7 -> V_87 -> V_88 = V_88 ;
F_22 ( V_5 ) ;
if ( V_146 ) {
V_146 -> V_152 = 0 ;
F_39 ( & V_5 -> V_7 ) ;
F_34 ( & V_8 -> V_147 , V_18 ) ;
V_5 -> V_146 = V_146 ;
F_37 ( & V_8 -> V_147 , V_18 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
bool V_153 )
{
unsigned long V_18 ;
T_1 V_154 ;
F_34 ( & V_2 -> V_155 , V_18 ) ;
V_154 = F_8 ( V_2 , V_91 ) | V_156 ;
if ( V_153 )
V_154 |= V_157 ;
else
V_154 &= ~ V_157 ;
F_6 ( V_2 , V_91 , V_154 ) ;
F_37 ( & V_2 -> V_155 , V_18 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
F_40 ( V_2 , true ) ;
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 -> V_9 ;
F_40 ( V_2 , false ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 . V_7 ;
int V_3 ;
V_2 -> V_7 . V_126 = V_139 ;
V_3 = F_44 ( V_2 -> V_83 , V_7 , & V_158 ) ;
if ( V_3 < 0 )
return V_3 ;
F_45 ( V_7 , & V_159 ) ;
return 0 ;
}
static void F_46 ( struct V_160 * V_161 , int V_15 )
{
struct V_162 * V_163 = F_47 ( V_161 ) ;
struct V_1 * V_2 = V_161 -> V_8 -> V_9 ;
struct V_164 * V_165 = & V_2 -> V_166 ;
if ( V_163 -> V_126 == V_15 )
return;
F_48 ( V_165 , V_15 ) ;
V_163 -> V_126 = V_15 ;
}
static bool F_49 ( struct V_160 * V_161 ,
const struct V_14 * V_15 ,
struct V_14 * V_140 )
{
struct V_82 * V_8 = V_161 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_9 ;
struct V_167 * V_166 = & V_2 -> V_166 . V_166 ;
const struct V_14 * V_168 ;
if ( F_50 ( & V_166 -> V_169 ) ) {
F_28 ( V_8 -> V_8 , L_2 ) ;
return false ;
}
V_168 = F_51 ( & V_166 -> V_169 ,
struct V_14 , V_170 ) ;
F_52 ( V_140 , V_168 ) ;
return true ;
}
static void F_53 ( struct V_160 * V_161 )
{
}
static void F_54 ( struct V_160 * V_161 ,
struct V_14 * V_15 ,
struct V_14 * V_140 )
{
}
static void F_55 ( struct V_160 * V_161 )
{
}
static void F_56 ( struct V_160 * V_161 )
{
F_57 ( V_161 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = & V_2 -> V_161 . V_161 ;
int V_3 ;
V_2 -> V_161 . V_126 = V_139 ;
V_161 -> V_171 = 1 ;
V_3 = F_59 ( V_2 -> V_83 , V_161 , & V_172 ,
V_173 , NULL ) ;
if ( V_3 < 0 )
return V_3 ;
F_60 ( V_161 , & V_174 ) ;
return 0 ;
}
static int F_61 ( struct V_167 * V_166 )
{
struct V_1 * V_2 = V_166 -> V_8 -> V_9 ;
struct V_14 * V_15 ;
V_15 = F_62 ( V_166 -> V_8 ) ;
if ( V_15 == NULL )
return 0 ;
V_15 -> type = V_175 | V_176 ;
V_15 -> clock = V_2 -> V_12 -> V_177 . V_15 . clock ;
V_15 -> V_60 = V_2 -> V_12 -> V_177 . V_15 . V_60 ;
V_15 -> V_64 = V_2 -> V_12 -> V_177 . V_15 . V_64 ;
V_15 -> V_63 = V_2 -> V_12 -> V_177 . V_15 . V_63 ;
V_15 -> V_61 = V_2 -> V_12 -> V_177 . V_15 . V_61 ;
V_15 -> V_67 = V_2 -> V_12 -> V_177 . V_15 . V_67 ;
V_15 -> V_71 = V_2 -> V_12 -> V_177 . V_15 . V_71 ;
V_15 -> V_70 = V_2 -> V_12 -> V_177 . V_15 . V_70 ;
V_15 -> V_68 = V_2 -> V_12 -> V_177 . V_15 . V_68 ;
V_15 -> V_18 = V_2 -> V_12 -> V_177 . V_15 . V_18 ;
F_63 ( V_15 ) ;
F_64 ( V_166 , V_15 ) ;
V_166 -> V_178 . V_179 = V_2 -> V_12 -> V_177 . V_179 ;
V_166 -> V_178 . V_180 = V_2 -> V_12 -> V_177 . V_180 ;
return 1 ;
}
static struct V_160 *
F_65 ( struct V_167 * V_166 )
{
struct V_164 * V_165 = F_66 ( V_166 ) ;
return V_165 -> V_161 ;
}
static void F_67 ( struct V_167 * V_166 )
{
struct V_164 * V_165 = F_66 ( V_166 ) ;
F_68 ( V_165 ) ;
F_69 ( V_166 ) ;
F_70 ( V_166 ) ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_160 * V_161 )
{
struct V_167 * V_166 = & V_2 -> V_166 . V_166 ;
int V_3 ;
V_2 -> V_166 . V_161 = V_161 ;
V_166 -> V_178 . V_179 = V_2 -> V_12 -> V_177 . V_179 ;
V_166 -> V_178 . V_180 = V_2 -> V_12 -> V_177 . V_180 ;
V_3 = F_72 ( V_2 -> V_83 , V_166 , & V_181 ,
V_182 ) ;
if ( V_3 < 0 )
return V_3 ;
F_73 ( V_166 , & V_183 ) ;
V_3 = F_74 ( & V_2 -> V_166 ) ;
if ( V_3 < 0 )
goto V_184;
V_3 = F_75 ( V_166 , V_161 ) ;
if ( V_3 < 0 )
goto V_185;
F_76 ( V_166 , V_139 ) ;
F_77 ( & V_166 -> V_186 ,
V_2 -> V_83 -> V_187 . V_188 , V_139 ) ;
return 0 ;
V_185:
F_68 ( & V_2 -> V_166 ) ;
V_184:
F_70 ( V_166 ) ;
return V_3 ;
}
