static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 ) ;
F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_10 ) ;
F_4 ( V_4 , V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_4 ( V_4 , V_13 ) ;
F_4 ( V_4 , V_14 ) ;
F_4 ( V_4 , V_15 ) ;
F_4 ( V_4 , V_16 ) ;
F_4 ( V_4 , V_17 ) ;
F_4 ( V_4 , V_18 ) ;
F_4 ( V_4 , V_19 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , V_21 ) ;
F_4 ( V_4 , V_22 ) ;
F_4 ( V_4 , V_23 ) ;
F_4 ( V_4 , V_24 ) ;
F_4 ( V_4 , V_25 ) ;
F_4 ( V_4 , V_26 ) ;
F_4 ( V_4 , V_27 ) ;
F_4 ( V_4 , V_28 ) ;
F_4 ( V_4 , V_29 ) ;
F_4 ( V_4 , V_30 ) ;
F_4 ( V_4 , V_31 ) ;
F_4 ( V_4 , V_32 ) ;
F_4 ( V_4 , V_33 ) ;
F_4 ( V_4 , V_34 ) ;
F_4 ( V_4 , V_35 ) ;
F_4 ( V_4 , V_36 ) ;
F_4 ( V_4 , V_37 ) ;
F_4 ( V_4 , V_38 ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 , V_39 , V_40 ) &
V_41 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_44 * V_45 ;
unsigned int V_46 , V_47 ;
unsigned int V_48 , V_49 ;
unsigned int V_50 , V_51 , V_52 ;
unsigned int V_53 , V_54 ;
V_48 = V_43 -> V_55 ;
V_49 = V_43 -> V_56 ;
if ( ( V_48 < 2 ) || ( V_48 > 6 ) ||
( V_49 < 2 ) || ( V_49 > 6 ) ) {
F_3 ( V_4 -> V_5 , L_3 ) ;
return - V_57 ;
}
if ( V_43 -> V_58 & 3 ) {
F_3 ( V_4 -> V_5 ,
L_4 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_59 & 1 ) || ( V_43 -> V_60 & 1 ) ) {
F_3 ( V_4 -> V_5 , L_5 ) ;
return - V_57 ;
}
V_45 = F_8 ( V_2 , NULL , V_61 ,
V_62 ) ;
V_53 = V_45 -> V_63 ;
V_54 = V_45 -> V_64 ;
V_46 = 1 << V_48 ;
V_50 = ( ( V_53 + V_43 -> V_59 + V_46 - 1 )
>> V_48 ) + 1 ;
V_47 = 1 << V_49 ;
V_51 = ( ( V_54 + V_43 -> V_60 + V_47 - 1 )
>> V_49 ) + 1 ;
V_52 = 4 * V_50 * V_51 ;
if ( V_52 > V_43 -> V_65 ) {
F_3 ( V_4 -> V_5 , L_6 ) ;
return - V_57 ;
}
if ( V_43 -> V_58 < ( V_50 * 4 ) ) {
F_3 ( V_4 -> V_5 , L_7 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_65 / V_43 -> V_58 ) < V_51 ) {
F_3 ( V_4 -> V_5 , L_8 ) ;
return - V_57 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_66 )
{
F_10 ( F_2 ( V_2 ) , V_66 ,
V_39 , V_67 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_42 * V_68 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_69 ;
F_10 ( V_4 , V_68 -> V_58 , V_39 ,
V_70 ) ;
V_69 = 0 ;
V_69 |= V_68 -> V_56 << V_71 ;
V_69 |= V_68 -> V_55 << V_72 ;
V_69 |= V_68 -> V_73 << V_74 ;
F_10 ( V_4 , V_69 , V_39 , V_75 ) ;
V_69 = 0 ;
V_69 &= ~ V_76 ;
V_69 |= V_68 -> V_59 << V_77 ;
V_69 &= ~ V_78 ;
V_69 |= V_68 -> V_60 << V_79 ;
F_10 ( V_4 , V_69 , V_39 ,
V_80 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_81 ;
F_10 ( V_4 , V_82 ,
V_83 , V_84 ) ;
for ( V_81 = 0 ; V_81 < 1000 ; V_81 ++ ) {
if ( F_6 ( V_4 , V_83 , V_84 ) &
V_82 ) {
F_10 ( V_4 , V_82 ,
V_83 , V_84 ) ;
return 0 ;
}
F_13 () ;
F_14 ( 1 ) ;
}
return - V_85 ;
}
static int F_15 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_44 * V_45 =
F_8 ( V_2 , NULL , V_61 ,
V_62 ) ;
if ( ( V_45 -> V_87 != V_88 ) &&
( V_45 -> V_87 != V_89 ) &&
( V_45 -> V_87 != V_90 ) &&
( V_45 -> V_87 != V_91 ) )
return - V_57 ;
if ( V_86 )
F_16 ( V_4 , V_92 ) ;
F_17 ( V_4 , V_39 , V_75 ,
V_93 , V_86 ? V_93 : 0 ) ;
if ( V_86 ) {
if ( F_12 ( V_2 ) < 0 ) {
F_18 ( V_4 , V_39 ,
V_75 , V_93 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_19 ( F_20 ( V_2 ) , L_9 ) ;
return - V_85 ;
}
V_2 -> V_94 . V_95 = V_97 ;
} else {
V_2 -> V_94 . V_95 = V_98 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 , V_39 , V_75 ) &
V_99 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
if ( ! V_101 -> V_86 )
return - V_57 ;
if ( F_7 ( V_2 , & V_101 -> V_102 ) < 0 ) {
F_3 ( F_20 ( V_2 ) , L_10 ) ;
return - V_57 ;
}
if ( F_21 ( V_2 ) )
return - V_103 ;
F_11 ( V_2 , & V_101 -> V_102 ) ;
F_9 ( V_2 , V_101 -> V_104 . V_105 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 , V_39 , V_75 ,
V_93 ) ;
V_2 -> V_94 . V_95 = V_96 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_101 == NULL )
return;
if ( V_101 -> V_104 . V_66 ) {
F_25 ( & V_101 -> V_104 . V_106 ) ;
F_26 ( V_4 -> V_5 , V_101 -> V_102 . V_65 , V_101 -> V_104 . V_66 ,
V_101 -> V_104 . V_105 ) ;
}
F_27 ( V_101 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_100 * V_101 , * V_109 ;
unsigned long V_110 ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
F_30 (req, n, queue, list) {
F_31 ( & V_101 -> V_112 ) ;
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
F_24 ( V_2 , V_101 ) ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
static void F_33 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_115 * V_94 ;
V_94 = F_34 ( V_114 , struct V_115 , V_116 ) ;
V_2 = F_34 ( V_94 , struct V_1 , V_94 ) ;
F_28 ( V_2 , & V_94 -> V_117 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_118 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
unsigned long V_110 ;
T_2 V_119 ;
int V_120 ;
V_119 = V_102 -> V_119 &
( V_121 | V_122 ) ;
if ( ! V_119 )
return 0 ;
if ( V_119 != ( V_121 | V_122 ) ) {
F_3 ( F_20 ( V_2 ) ,
L_11 ,
V_123 ) ;
return - V_57 ;
}
V_101 = F_36 ( sizeof( * V_101 ) , V_124 ) ;
if ( V_101 == NULL )
return - V_125 ;
if ( V_102 -> V_126 & V_121 ) {
if ( F_37 ( & V_101 -> V_102 , V_102 -> V_43 ,
sizeof( V_101 -> V_102 ) ) ) {
V_120 = - V_127 ;
goto V_128;
}
V_101 -> V_86 = 1 ;
V_101 -> V_104 . V_66 = F_38 ( V_4 -> V_5 , V_101 -> V_102 . V_65 ,
& V_101 -> V_104 . V_105 ,
V_124 ) ;
if ( V_101 -> V_104 . V_66 == NULL ) {
V_120 = - V_125 ;
goto V_128;
}
V_120 = F_39 ( V_4 -> V_5 , & V_101 -> V_104 . V_106 ,
V_101 -> V_104 . V_66 , V_101 -> V_104 . V_105 ,
V_101 -> V_102 . V_65 ) ;
if ( V_120 < 0 )
goto V_128;
F_40 ( V_4 -> V_5 , V_101 -> V_104 . V_106 . V_129 ,
V_101 -> V_104 . V_106 . V_130 , V_131 ) ;
if ( F_37 ( V_101 -> V_104 . V_66 , V_102 -> V_94 ,
V_101 -> V_102 . V_65 ) ) {
V_120 = - V_127 ;
goto V_128;
}
F_41 ( V_4 -> V_5 , V_101 -> V_104 . V_106 . V_129 ,
V_101 -> V_104 . V_106 . V_130 , V_131 ) ;
}
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_132 ) {
F_42 ( & V_2 -> V_94 . V_132 -> V_112 , & V_2 -> V_94 . V_117 ) ;
F_43 ( & V_2 -> V_94 . V_116 ) ;
}
V_2 -> V_94 . V_132 = V_101 ;
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
V_120 = 0 ;
V_128:
if ( V_120 < 0 )
F_24 ( V_2 , V_101 ) ;
return V_120 ;
}
static inline int F_44 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
int V_120 ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
V_120 = V_2 -> V_94 . V_133 != NULL ;
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
return V_120 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_115 * V_94 = & V_2 -> V_94 ;
if ( V_94 -> V_95 != V_96 )
return - V_57 ;
if ( V_94 -> V_133 ) {
F_42 ( & V_94 -> V_133 -> V_112 , & V_94 -> V_117 ) ;
V_94 -> V_133 = NULL ;
}
if ( F_22 ( V_2 , V_94 -> V_132 ) < 0 ) {
F_46 ( F_2 ( V_2 ) ,
V_92 ) ;
F_42 ( & V_94 -> V_132 -> V_112 , & V_94 -> V_117 ) ;
V_94 -> V_132 = NULL ;
goto V_128;
}
V_94 -> V_133 = V_94 -> V_132 ;
V_94 -> V_132 = NULL ;
F_15 ( V_2 , 1 ) ;
V_128:
if ( ! F_47 ( & V_94 -> V_117 ) )
F_43 ( & V_94 -> V_116 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_134 ;
if ( V_2 -> V_135 ) {
V_134 = V_2 -> V_134 . V_136 << V_137 ;
V_134 |= V_2 -> V_134 . V_138 << V_139 ;
V_134 |= V_2 -> V_134 . V_140 << V_141 ;
V_134 |= V_2 -> V_134 . V_142 << V_143 ;
F_10 ( V_4 , V_134 , V_39 , V_144 ) ;
} else {
F_10 ( V_4 , V_2 -> V_134 . V_145 ,
V_39 , V_146 ) ;
}
F_17 ( V_4 , V_39 , V_144 ,
V_147 ,
V_2 -> V_135 ? V_147 : 0 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 , V_39 , V_148 , V_149 ) ;
if ( ! V_2 -> V_150 )
return;
F_10 ( V_4 , V_2 -> V_151 . V_105 , V_39 ,
V_152 ) ;
F_10 ( V_4 , ( V_2 -> V_151 . V_153 << V_154 ) ,
V_39 , V_148 ) ;
F_10 ( V_4 , ( V_2 -> V_151 . V_153 << V_154 ) |
V_149 , V_39 , V_148 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_155 ;
V_155 = V_2 -> V_155 . V_156 << V_157 ;
V_155 |= V_2 -> V_155 . V_158 << V_159 ;
V_155 |= V_2 -> V_155 . V_160 << V_161 ;
V_155 |= V_2 -> V_155 . V_162 << V_163 ;
F_10 ( V_4 , V_155 , V_39 , V_164 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_165 ,
V_166 ,
V_2 -> V_167 ? V_166 : 0 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_168 * V_169 ;
T_3 V_170 = 0 ;
V_169 = F_53 ( V_2 -> V_171 [ V_61 ] . V_87 ) ;
switch ( V_169 -> V_63 ) {
case 8 :
return;
case 10 :
V_170 = V_172 ;
break;
case 11 :
V_170 = V_173 ;
break;
case 12 :
V_170 = V_174 ;
break;
case 13 :
V_170 = V_175 ;
break;
}
if ( V_2 -> V_170 )
V_170 |= V_176 ;
F_10 ( V_4 , V_170 , V_39 , V_177 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_3 V_178 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_178 , V_39 , V_179 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_118 * V_180 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_110 ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
V_2 -> V_182 = 1 ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
if ( V_183 & V_180 -> V_119 ) {
V_2 -> V_170 = ! ! ( V_183 & V_180 -> V_126 ) ;
V_2 -> V_119 |= V_183 ;
}
if ( V_184 & V_180 -> V_119 ) {
V_2 -> V_167 = ! ! ( V_184 & V_180 -> V_126 ) ;
V_2 -> V_119 |= V_184 ;
}
if ( V_185 & V_180 -> V_119 ) {
if ( F_37 ( & V_2 -> V_134 , V_180 -> V_186 ,
sizeof( V_2 -> V_134 ) ) ) {
V_2 -> V_182 = 0 ;
return - V_127 ;
}
V_2 -> V_135 = ! ! ( V_185 & V_180 -> V_126 ) ;
V_2 -> V_119 |= V_185 ;
}
if ( V_187 & V_180 -> V_119 ) {
if ( F_37 ( & V_2 -> V_155 , V_180 -> V_155 ,
sizeof( V_2 -> V_155 ) ) ) {
V_2 -> V_182 = 0 ;
return - V_127 ;
}
V_2 -> V_119 |= V_187 ;
}
V_2 -> V_182 = 0 ;
if ( V_188 & V_180 -> V_119 ) {
struct V_189 V_151 ;
struct V_190 V_191 = { . V_66 = NULL , } ;
struct V_190 V_192 ;
T_3 V_65 ;
if ( V_2 -> V_95 != V_193 )
return - V_103 ;
V_2 -> V_150 = ! ! ( V_188 & V_180 -> V_126 ) ;
if ( V_2 -> V_150 ) {
if ( F_37 ( & V_151 , V_180 -> V_151 , sizeof( V_151 ) ) )
return - V_127 ;
V_65 = V_151 . V_153 * 4 ;
V_192 . V_153 = V_151 . V_153 ;
V_192 . V_66 = F_38 ( V_4 -> V_5 , V_65 ,
& V_192 . V_105 ,
V_124 ) ;
if ( V_192 . V_66 == NULL )
return - V_125 ;
if ( F_37 ( V_192 . V_66 ,
( V_194 void V_195 * ) V_151 . V_196 ,
V_65 ) ) {
F_26 ( V_4 -> V_5 , V_65 , V_192 . V_66 ,
V_192 . V_105 ) ;
return - V_127 ;
}
V_191 = V_2 -> V_151 ;
V_2 -> V_151 = V_192 ;
}
F_49 ( V_2 ) ;
if ( V_191 . V_66 != NULL )
F_26 ( V_4 -> V_5 , V_191 . V_153 * 4 ,
V_191 . V_66 , V_191 . V_105 ) ;
}
return F_35 ( V_2 , V_180 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_119 & V_183 ) {
F_52 ( V_2 ) ;
V_2 -> V_119 &= ~ V_183 ;
}
if ( V_2 -> V_119 & V_184 ) {
F_51 ( V_2 ) ;
V_2 -> V_119 &= ~ V_184 ;
}
if ( V_2 -> V_119 & V_185 ) {
F_48 ( V_2 ) ;
V_2 -> V_119 &= ~ V_185 ;
}
if ( V_2 -> V_119 & V_187 ) {
F_50 ( V_2 ) ;
V_2 -> V_119 &= ~ V_187 ;
}
}
void F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
F_58 ( V_4 , V_39 , V_198 , V_199 ) ;
V_2 -> V_119 = V_183 | V_184
| V_185 | V_187 ;
F_56 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_168 * V_169 ;
struct V_44 * V_45 ;
unsigned long V_204 = V_201 -> V_204 ;
unsigned int V_205 = V_4 -> V_206 == V_207 ? 64 : 8 ;
unsigned int div = 0 ;
T_3 V_208 = V_209 ;
V_45 = & V_2 -> V_171 [ V_210 ] ;
if ( ! V_45 -> V_87 ) {
F_10 ( V_4 , 0 , V_39 , V_211 ) ;
return;
}
F_10 ( V_4 , ( 0 << V_212 ) |
( V_45 -> V_63 << V_213 ) ,
V_39 , V_214 ) ;
F_10 ( V_4 , ( 0 << V_215 ) |
( ( V_45 -> V_64 + 1 ) << V_216 ) ,
V_39 , V_217 ) ;
F_10 ( V_4 , ( V_45 -> V_63 << V_218 ) |
( V_45 -> V_64 << V_219 ) ,
V_39 , V_220 ) ;
V_169 = F_53 ( V_2 -> V_171 [ V_61 ] . V_87 ) ;
switch ( V_169 -> V_63 ) {
case 8 :
case 10 :
V_208 |= V_221 ;
break;
case 11 :
V_208 |= V_222 ;
break;
case 12 :
V_208 |= V_223 ;
break;
case 13 :
V_208 |= V_224 ;
break;
}
if ( V_201 -> V_225 )
div = F_61 ( V_204 , V_201 -> V_226 ) ;
else if ( V_201 -> V_227 )
div = V_204 / V_201 -> V_227 ;
div = V_134 ( div , 2U , V_205 ) ;
V_208 |= ( div - 2 ) << V_228 ;
F_10 ( V_4 , V_208 , V_39 , V_211 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
unsigned int V_229 ,
enum V_230 V_231 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_232 = 0 ;
F_10 ( V_4 , V_229 & 0xffff , V_39 ,
V_233 ) ;
switch ( V_231 ) {
case V_234 :
case V_235 :
V_232 |= ( 1 << V_236 )
| ( 1 << V_237 )
| ( 1 << V_238 )
| ( 1 << V_239 ) ;
break;
default:
break;
}
F_10 ( V_4 , V_232 , V_39 , V_240 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_3 V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_66 , V_39 , V_241 ) ;
}
void F_64 ( struct V_1 * V_2 ,
unsigned int * V_226 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
unsigned int V_242 ;
if ( V_201 == NULL )
return;
if ( V_2 -> V_225 == V_243 )
V_242 = V_201 -> V_204 / 2 * 9 / 10 ;
else
V_242 = V_201 -> V_204 / 2 ;
* V_226 = F_65 ( * V_226 , V_242 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_244 * V_245 ,
unsigned int V_246 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_44 * V_45 ;
T_3 V_247 = V_248 ;
V_45 = & V_2 -> V_171 [ V_61 ] ;
if ( V_45 -> V_87 == V_249 ||
V_45 -> V_87 == V_250 ) {
if ( V_2 -> V_251 )
V_247 |= V_252 ;
else
V_247 |= V_253 ;
}
switch ( V_246 ) {
case 8 :
V_247 |= V_254 ;
break;
case 10 :
V_247 |= V_255 ;
break;
case 11 :
V_247 |= V_256 ;
break;
case 12 :
V_247 |= V_257 ;
break;
}
if ( V_245 && V_245 -> V_258 )
V_247 |= V_259 ;
if ( V_245 && V_245 -> V_260 )
V_247 |= V_261 ;
if ( ( V_245 && V_245 -> V_262 ) || V_2 -> V_251 )
V_247 |= V_263 ;
if ( V_245 && V_245 -> V_264 )
V_247 |= V_265 ;
F_10 ( V_4 , V_247 , V_39 , V_165 ) ;
if ( V_45 -> V_87 == V_250 )
F_58 ( V_4 , V_39 , V_198 ,
V_266 ) ;
else
F_18 ( V_4 , V_39 , V_198 ,
V_266 ) ;
if ( V_2 -> V_251 )
F_58 ( V_4 , V_39 , V_267 ,
V_268 | V_269 ) ;
else
F_18 ( V_4 , V_39 , V_267 ,
V_268 | V_269 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_244 * V_245 = NULL ;
struct V_270 * V_271 ;
struct V_44 * V_45 ;
const struct V_272 * V_273 ;
const struct V_168 * V_274 ;
struct V_275 V_276 ;
unsigned int V_277 ;
unsigned int V_278 = 0 ;
struct V_279 * V_280 ;
unsigned long V_110 ;
unsigned int V_281 ;
unsigned int V_282 ;
unsigned int V_283 ;
unsigned int V_284 ;
T_3 V_247 ;
T_3 V_285 ;
V_2 -> V_251 = false ;
V_2 -> V_286 = 0 ;
V_280 = F_68 ( & V_2 -> V_287 [ V_61 ] ) ;
V_271 = F_69 ( V_280 -> V_203 ) ;
if ( V_2 -> V_225 == V_243 ) {
struct V_288 V_68 ;
int V_120 ;
V_120 = F_70 ( V_271 , V_289 , V_290 , & V_68 ) ;
if ( ! V_120 )
V_2 -> V_251 = V_68 . type == V_291 ;
V_245 = & ( (struct V_292 * ) V_271 -> V_293 )
-> V_294 . V_295 ;
}
V_45 = & V_2 -> V_171 [ V_61 ] ;
V_276 . V_280 = V_280 -> V_296 ;
V_276 . V_297 = V_62 ;
if ( ! F_70 ( V_271 , V_280 , V_298 , NULL , & V_276 ) ) {
V_274 = F_53 ( V_276 . V_45 . V_87 ) ;
V_278 = V_274 -> V_63 ;
}
V_274 = F_53 ( V_45 -> V_87 ) ;
V_277 = V_274 -> V_63 ;
V_282 = V_278 - V_277 ;
if ( V_2 -> V_251 )
V_281 = V_299 ;
else if ( V_274 -> V_87 == V_249 )
V_281 = V_300 ;
else if ( V_274 -> V_87 == V_250 )
V_281 = V_301 ;
else
V_281 = V_299 ;
F_71 ( V_4 , V_2 -> V_225 , V_245 , V_282 , V_281 ) ;
F_66 ( V_2 , V_245 , V_277 ) ;
V_247 = F_6 ( V_4 , V_39 , V_165 ) ;
V_247 &= ~ V_302 ;
if ( V_2 -> V_303 & V_304 )
V_247 |= V_305 ;
else
V_247 &= ~ V_305 ;
if ( V_2 -> V_303 & V_306 )
V_247 |= V_307 ;
else
V_247 &= ~ V_307 ;
switch ( V_45 -> V_87 ) {
case V_89 :
case V_308 :
V_285 = V_309 ;
break;
case V_90 :
case V_310 :
V_285 = V_311 ;
break;
case V_91 :
case V_312 :
V_285 = V_313 ;
break;
default:
V_285 = V_314 ;
break;
}
F_54 ( V_2 , V_285 ) ;
F_10 ( V_4 , ( ( V_45 -> V_64 - 2 ) << V_315 ) |
( ( V_45 -> V_64 * 2 / 3 ) << V_316 ) ,
V_39 , V_317 ) ;
V_45 = & V_2 -> V_171 [ V_318 ] ;
V_273 = & V_2 -> V_273 ;
if ( V_2 -> V_251 ) {
V_284 = V_273 -> V_319 * 2 ;
V_283 = V_273 -> V_63 * 2 - 1 ;
} else {
V_284 = V_273 -> V_319 ;
V_283 = V_273 -> V_63 - 1 ;
}
F_10 ( V_4 , ( V_284 << V_320 ) |
( V_283 << V_321 ) ,
V_39 , V_322 ) ;
F_10 ( V_4 , ( V_273 -> V_323 << V_324 ) |
( V_273 -> V_323 << V_325 ) ,
V_39 , V_326 ) ;
F_10 ( V_4 , ( V_273 -> V_64 - 1 )
<< V_327 ,
V_39 , V_328 ) ;
F_62 ( V_2 , V_2 -> V_329 . V_330 ,
V_45 -> V_231 ) ;
if ( V_2 -> V_171 [ V_61 ] . V_231 == V_331 &&
( V_45 -> V_231 == V_234 ||
V_45 -> V_231 == V_235 ) )
V_247 |= V_332 ;
if ( V_45 -> V_87 == V_333 )
F_58 ( V_4 , V_39 , V_198 ,
V_334 ) ;
else
F_18 ( V_4 , V_39 , V_198 ,
V_334 ) ;
if ( F_53 ( V_45 -> V_87 ) -> V_63 <= 8 || V_2 -> V_251 )
V_247 |= V_335 ;
else
V_247 &= ~ V_335 ;
F_10 ( V_4 , V_247 , V_39 , V_165 ) ;
F_59 ( V_2 ) ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_336;
F_72 ( V_2 -> V_94 . V_133 ) ;
if ( V_2 -> V_94 . V_133 == NULL &&
F_22 ( V_2 , V_2 -> V_94 . V_132 ) == 0 ) {
V_2 -> V_94 . V_133 = V_2 -> V_94 . V_132 ;
} else {
F_42 ( & V_2 -> V_94 . V_132 -> V_112 , & V_2 -> V_94 . V_117 ) ;
F_43 ( & V_2 -> V_94 . V_116 ) ;
}
V_2 -> V_94 . V_132 = NULL ;
V_336:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
F_56 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_40 ,
V_337 , V_86 ? V_337 : 0 ) ;
V_2 -> V_338 = V_86 ;
}
static int F_74 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
int V_120 = 0 ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( V_2 -> V_95 == V_339 )
V_2 -> V_340 = V_341 ;
if ( ! V_2 -> V_338 )
V_2 -> V_340 = V_342 ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
V_120 = F_75 ( V_2 -> V_81 ,
V_2 -> V_340 == V_342 ,
F_76 ( 2000 ) ) ;
if ( V_120 == 0 ) {
V_120 = - V_85 ;
F_19 ( F_20 ( V_2 ) , L_12 ) ;
}
F_46 ( F_2 ( V_2 ) , V_92 ) ;
F_77 ( & V_2 -> V_343 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_132 ) ;
V_2 -> V_94 . V_132 = V_2 -> V_94 . V_133 ;
V_2 -> V_94 . V_133 = NULL ;
F_78 ( & V_2 -> V_94 . V_116 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_117 ) ;
F_79 ( & V_2 -> V_343 ) ;
V_2 -> V_340 = V_344 ;
return V_120 > 0 ? 0 : V_120 ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( F_44 ( V_2 ) )
F_15 ( V_2 , 1 ) ;
F_73 ( V_2 , 1 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( V_2 )
| ( F_6 ( V_4 , V_345 , V_346 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_348 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_349 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_350 ) &
V_347 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
unsigned int V_351 )
{
unsigned int V_81 = 0 ;
if ( V_351 == 0 )
V_351 = 10000 ;
for ( V_81 = 0 ; V_81 <= V_351 ; V_81 ++ ) {
if ( ! F_81 ( V_2 ) )
return 0 ;
F_13 () ;
F_14 ( 1 ) ;
}
return - V_103 ;
}
static int F_83 ( struct V_1 * V_2 , T_3 V_352 )
{
int V_353 = 0 ;
switch ( ( V_2 -> V_340 & 3 ) | V_352 ) {
case V_341 | V_354 :
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_73 ( V_2 , 0 ) ;
V_2 -> V_340 = V_355 ;
return 1 ;
case V_355 | V_356 :
V_2 -> V_340 |= V_357 ;
if ( V_2 -> V_94 . V_95 == V_96 )
V_2 -> V_340 |= V_358 ;
V_353 = 1 ;
break;
case V_355 | V_359 :
V_2 -> V_340 |= V_358 ;
V_353 = 1 ;
break;
case V_355 | V_354 :
return 1 ;
}
if ( V_2 -> V_340 == V_342 ) {
F_84 ( & V_2 -> V_81 ) ;
V_353 = 1 ;
}
return V_353 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_360 * V_361 = V_2 -> V_202 . V_362 ;
struct V_363 V_352 ;
F_86 ( & V_201 -> V_364 ) ;
memset ( & V_352 , 0 , sizeof( V_352 ) ) ;
V_352 . type = V_365 ;
V_352 . V_366 . V_367 . V_368 = F_87 ( & V_201 -> V_364 ) ;
F_88 ( V_361 , & V_352 ) ;
}
static void F_89 ( struct V_1 * V_2 , T_3 V_369 )
{
unsigned long V_110 ;
if ( V_369 & V_370 ) {
struct V_200 * V_201 =
F_60 ( & V_2 -> V_202 . V_203 ) ;
F_23 ( V_2 ) ;
V_201 -> error = true ;
F_3 ( F_20 ( V_2 ) , L_13 ) ;
}
if ( ! ( V_369 & V_371 ) )
return;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_95 == V_98 )
V_2 -> V_94 . V_95 = V_96 ;
if ( F_83 ( V_2 , V_359 ) )
goto V_128;
if ( V_2 -> V_94 . V_95 != V_372 )
goto V_128;
V_2 -> V_94 . V_95 = V_96 ;
if ( V_369 & V_373 )
goto V_128;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_128;
F_45 ( V_2 ) ;
V_128:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
static bool F_90 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_230 V_374 = V_2 -> V_171 [ V_318 ] . V_231 ;
enum V_230 V_231 ;
if ( V_374 == V_375 )
return true ;
V_231 = F_6 ( V_4 , V_39 , V_165 )
& V_376
? V_377 : V_378 ;
if ( V_374 == V_331 ) {
V_201 -> V_231 = V_231 ;
return true ;
}
V_2 -> V_286 |= V_231 == V_377
? V_379 : V_380 ;
if ( V_2 -> V_286 != V_381 )
return false ;
if ( ( V_374 == V_234 && V_231 == V_378 ) ||
( V_374 == V_235 && V_231 == V_377 ) )
return false ;
V_2 -> V_286 = 0 ;
return true ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_382 * V_383 ;
if ( F_47 ( & V_2 -> V_329 . V_384 ) )
return 0 ;
if ( V_2 -> V_95 == V_339 && V_2 -> V_385 ) {
V_2 -> V_385 = 0 ;
return 1 ;
}
if ( F_82 ( V_2 , 1000 ) ) {
F_92 ( V_4 -> V_5 , L_14 ) ;
F_93 ( & V_4 -> V_386 , & V_2 -> V_202 . V_203 ) ;
F_94 ( V_201 ) ;
return 0 ;
}
if ( ! F_90 ( V_2 ) )
return 1 ;
V_383 = F_95 ( & V_2 -> V_329 ) ;
if ( V_383 != NULL )
F_63 ( V_2 , V_383 -> V_105 ) ;
V_201 -> V_95 |= V_387 ;
if ( V_2 -> V_95 == V_388 &&
F_96 ( V_201 ) )
F_97 ( V_201 ,
V_388 ) ;
return V_383 != NULL ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
int V_389 = 0 ;
if ( V_2 -> V_251 ) {
struct V_200 * V_201 =
F_60 ( & V_2 -> V_202 . V_203 ) ;
F_86 ( & V_201 -> V_364 ) ;
}
if ( V_2 -> V_251 ) {
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( V_2 -> V_95 == V_339 &&
V_2 -> V_303 & V_304 ) {
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_73 ( V_2 , 0 ) ;
}
F_83 ( V_2 , V_354 ) ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
}
if ( V_2 -> V_303 & V_304 )
V_389 = F_91 ( V_2 ) ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( F_83 ( V_2 , V_356 ) ) {
F_32 ( & V_2 -> V_181 , V_110 ) ;
return;
}
if ( ! V_2 -> V_182 )
F_56 ( V_2 ) ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
if ( V_389 )
F_80 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
if ( V_2 -> V_251 )
return;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
switch ( V_2 -> V_95 ) {
case V_388 :
V_2 -> V_340 = V_341 ;
break;
case V_339 :
if ( V_2 -> V_303 & V_304 ) {
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_73 ( V_2 , 0 ) ;
}
break;
case V_193 :
break;
}
if ( F_83 ( V_2 , V_354 ) )
goto V_128;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_128;
if ( V_2 -> V_94 . V_95 == V_97 ) {
F_15 ( V_2 , 0 ) ;
V_2 -> V_94 . V_95 = V_372 ;
goto V_128;
}
if ( V_2 -> V_94 . V_95 == V_96 )
F_45 ( V_2 ) ;
V_128:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
int F_100 ( struct V_1 * V_2 , T_3 V_369 )
{
if ( V_2 -> V_95 == V_193 )
return 0 ;
if ( V_369 & V_390 )
F_99 ( V_2 ) ;
F_89 ( V_2 , V_369 ) ;
if ( V_369 & V_391 )
F_98 ( V_2 ) ;
if ( V_369 & V_373 )
F_85 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_392 * V_289 , struct V_382 * V_383 )
{
struct V_1 * V_2 = & V_289 -> V_4 -> V_197 ;
unsigned long V_110 ;
bool V_389 = false ;
if ( ! ( V_2 -> V_303 & V_304 ) )
return - V_393 ;
F_63 ( V_2 , V_383 -> V_105 ) ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( V_2 -> V_95 == V_339 && ! V_2 -> V_338 &&
V_2 -> V_251 )
V_389 = true ;
else
V_2 -> V_385 = 1 ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
if ( V_389 )
F_80 ( V_2 ) ;
return 0 ;
}
static long F_102 ( struct V_270 * V_394 , unsigned int V_395 , void * V_396 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
int V_120 ;
switch ( V_395 ) {
case V_397 :
F_77 ( & V_2 -> V_343 ) ;
V_120 = F_55 ( V_2 , V_396 ) ;
F_79 ( & V_2 -> V_343 ) ;
break;
default:
return - V_398 ;
}
return V_120 ;
}
static int F_104 ( struct V_270 * V_394 , struct V_399 * V_400 ,
struct V_401 * V_402 )
{
if ( V_402 -> type != V_365 )
return - V_57 ;
if ( V_402 -> V_403 != 0 )
return - V_57 ;
return F_105 ( V_400 , V_402 , V_404 , NULL ) ;
}
static int F_106 ( struct V_270 * V_394 , struct V_399 * V_400 ,
struct V_401 * V_402 )
{
return F_107 ( V_400 , V_402 ) ;
}
static int F_108 ( struct V_270 * V_394 , int V_86 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_120 = 0 ;
if ( V_2 -> V_95 == V_193 ) {
if ( V_86 == V_193 )
return 0 ;
F_109 ( V_4 , V_405 ) ;
F_58 ( V_4 , V_39 , V_198 ,
V_199 ) ;
F_67 ( V_2 ) ;
F_1 ( V_2 ) ;
}
switch ( V_86 ) {
case V_339 :
if ( V_2 -> V_303 & V_304 )
F_16 ( V_4 , V_406 ) ;
if ( V_2 -> V_385 || ! ( V_2 -> V_303 & V_304 ) )
F_80 ( V_2 ) ;
V_2 -> V_385 = 0 ;
break;
case V_388 :
if ( V_2 -> V_303 & V_304 &&
V_2 -> V_95 != V_388 )
F_16 ( V_4 , V_406 ) ;
F_80 ( V_2 ) ;
break;
case V_193 :
V_120 = F_74 ( V_2 ) ;
if ( V_2 -> V_303 & V_304 )
F_46 ( V_4 , V_406 ) ;
F_110 ( V_4 , V_405 ) ;
V_2 -> V_385 = 0 ;
break;
}
V_2 -> V_95 = V_86 ;
return V_120 ;
}
static struct V_44 *
F_8 ( struct V_1 * V_2 , struct V_407 * V_68 ,
unsigned int V_280 , enum V_408 V_297 )
{
if ( V_297 == V_409 )
return F_111 ( & V_2 -> V_202 , V_68 , V_280 ) ;
else
return & V_2 -> V_171 [ V_280 ] ;
}
static struct V_272 *
F_112 ( struct V_1 * V_2 , struct V_407 * V_68 ,
enum V_408 V_297 )
{
if ( V_297 == V_409 )
return F_113 ( & V_2 -> V_202 , V_68 , V_318 ) ;
else
return & V_2 -> V_273 ;
}
static void
F_114 ( struct V_1 * V_2 , struct V_407 * V_68 ,
unsigned int V_280 , struct V_44 * V_410 ,
enum V_408 V_297 )
{
const struct V_168 * V_169 ;
T_3 V_411 ;
unsigned int V_63 = V_410 -> V_63 ;
unsigned int V_64 = V_410 -> V_64 ;
struct V_272 * V_273 ;
enum V_230 V_231 ;
unsigned int V_412 ;
switch ( V_280 ) {
case V_61 :
for ( V_412 = 0 ; V_412 < F_115 ( V_413 ) ; V_412 ++ ) {
if ( V_410 -> V_87 == V_413 [ V_412 ] )
break;
}
if ( V_412 >= F_115 ( V_413 ) )
V_410 -> V_87 = V_88 ;
V_410 -> V_63 = F_116 ( T_3 , V_63 , 32 , 4096 ) ;
V_410 -> V_64 = F_116 ( T_3 , V_64 , 32 , 4096 ) ;
if ( V_410 -> V_231 == V_414 )
V_410 -> V_231 = V_375 ;
break;
case V_318 :
V_411 = V_410 -> V_87 ;
V_231 = V_410 -> V_231 ;
* V_410 = * F_8 ( V_2 , V_68 , V_61 , V_297 ) ;
if ( V_410 -> V_87 == V_249 ||
V_410 -> V_87 == V_250 ) {
if ( V_411 == V_249 ||
V_411 == V_250 ||
V_411 == V_333 ||
V_411 == V_415 )
V_410 -> V_87 = V_411 ;
if ( V_410 -> V_87 == V_249 )
V_410 -> V_87 = V_333 ;
else if ( V_410 -> V_87 == V_250 )
V_410 -> V_87 = V_415 ;
}
V_273 = F_112 ( V_2 , V_68 , V_297 ) ;
V_410 -> V_63 = V_273 -> V_63 ;
V_410 -> V_64 = V_273 -> V_64 ;
if ( V_410 -> V_231 == V_331 &&
( V_231 == V_234 ||
V_231 == V_235 ) ) {
V_410 -> V_231 = V_231 ;
V_410 -> V_64 *= 2 ;
}
break;
case V_210 :
* V_410 = * F_8 ( V_2 , V_68 , V_61 , V_297 ) ;
V_169 = F_53 ( V_410 -> V_87 ) ;
V_410 -> V_87 = V_169 -> V_416 ;
if ( V_410 -> V_87 == V_249 ||
V_410 -> V_87 == V_250 )
V_410 -> V_87 = 0 ;
V_410 -> V_63 = F_116 ( T_3 , V_63 , 32 , V_410 -> V_63 ) ;
V_410 -> V_64 = F_116 ( T_3 , V_64 , 32 , V_410 -> V_64 - 1 ) ;
break;
}
V_410 -> V_417 = V_418 ;
}
static void F_117 ( struct V_1 * V_2 ,
const struct V_44 * V_419 ,
struct V_272 * V_273 )
{
const struct V_168 * V_169 ;
unsigned int V_420 ;
V_169 = F_53 ( V_419 -> V_87 ) ;
if ( V_169 -> V_421 != V_422 ) {
V_273 -> V_319 &= ~ 1 ;
V_273 -> V_323 &= ~ 1 ;
}
V_273 -> V_319 = F_116 ( T_3 , V_273 -> V_319 , 0 , V_419 -> V_63 - V_423 ) ;
V_273 -> V_323 = F_116 ( T_3 , V_273 -> V_323 , 0 , V_419 -> V_64 - V_424 ) ;
V_420 = ( V_419 -> V_63 - V_273 -> V_319 + 15 ) & ~ 15 ;
V_273 -> V_63 = F_116 ( T_3 , V_273 -> V_63 , V_423 , V_420 )
& ~ 15 ;
V_273 -> V_64 = F_116 ( T_3 , V_273 -> V_64 , V_424 ,
V_419 -> V_64 - V_273 -> V_323 ) ;
if ( V_169 -> V_421 != V_422 ) {
V_273 -> V_63 &= ~ 1 ;
V_273 -> V_64 &= ~ 1 ;
}
}
static int F_118 ( struct V_270 * V_394 ,
struct V_407 * V_68 ,
struct V_425 * V_87 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 * V_45 ;
switch ( V_87 -> V_280 ) {
case V_61 :
if ( V_87 -> V_296 >= F_115 ( V_413 ) )
return - V_57 ;
V_87 -> V_87 = V_413 [ V_87 -> V_296 ] ;
break;
case V_318 :
V_45 = F_8 ( V_2 , V_68 , V_87 -> V_280 ,
V_87 -> V_297 ) ;
if ( V_45 -> V_87 == V_249 ||
V_45 -> V_87 == V_250 ) {
if ( V_87 -> V_296 == 0 )
V_87 -> V_87 = V_333 ;
else if ( V_87 -> V_296 == 1 )
V_87 -> V_87 = V_415 ;
else
return - V_57 ;
} else {
if ( V_87 -> V_296 == 0 )
V_87 -> V_87 = V_45 -> V_87 ;
else
return - V_57 ;
}
break;
case V_210 :
if ( V_87 -> V_296 != 0 )
return - V_57 ;
V_45 = F_8 ( V_2 , V_68 , V_87 -> V_280 ,
V_87 -> V_297 ) ;
if ( V_45 -> V_87 == 0 )
return - V_57 ;
V_87 -> V_87 = V_45 -> V_87 ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_119 ( struct V_270 * V_394 ,
struct V_407 * V_68 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 V_45 ;
if ( V_427 -> V_296 != 0 )
return - V_57 ;
V_45 . V_87 = V_427 -> V_87 ;
V_45 . V_63 = 1 ;
V_45 . V_64 = 1 ;
F_114 ( V_2 , V_68 , V_427 -> V_280 , & V_45 , V_427 -> V_297 ) ;
V_427 -> V_50 = V_45 . V_63 ;
V_427 -> V_51 = V_45 . V_64 ;
if ( V_45 . V_87 != V_427 -> V_87 )
return - V_57 ;
V_45 . V_87 = V_427 -> V_87 ;
V_45 . V_63 = - 1 ;
V_45 . V_64 = - 1 ;
F_114 ( V_2 , V_68 , V_427 -> V_280 , & V_45 , V_427 -> V_297 ) ;
V_427 -> V_420 = V_45 . V_63 ;
V_427 -> V_428 = V_45 . V_64 ;
return 0 ;
}
static int F_120 ( struct V_270 * V_394 , struct V_407 * V_68 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 * V_45 ;
if ( V_430 -> V_280 != V_318 )
return - V_57 ;
switch ( V_430 -> V_431 ) {
case V_432 :
V_430 -> V_433 . V_319 = 0 ;
V_430 -> V_433 . V_323 = 0 ;
V_430 -> V_433 . V_63 = V_434 ;
V_430 -> V_433 . V_64 = V_434 ;
V_45 = F_8 ( V_2 , V_68 , V_61 , V_430 -> V_297 ) ;
F_117 ( V_2 , V_45 , & V_430 -> V_433 ) ;
break;
case V_435 :
V_430 -> V_433 = * F_112 ( V_2 , V_68 , V_430 -> V_297 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_121 ( struct V_270 * V_394 , struct V_407 * V_68 ,
struct V_429 * V_430 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 * V_45 ;
if ( V_430 -> V_431 != V_435 ||
V_430 -> V_280 != V_318 )
return - V_57 ;
if ( V_2 -> V_95 != V_193 )
return - V_103 ;
if ( V_430 -> V_110 & V_436 ) {
V_430 -> V_433 = * F_112 ( V_2 , V_68 , V_430 -> V_297 ) ;
return 0 ;
}
V_45 = F_8 ( V_2 , V_68 , V_61 , V_430 -> V_297 ) ;
F_117 ( V_2 , V_45 , & V_430 -> V_433 ) ;
* F_112 ( V_2 , V_68 , V_430 -> V_297 ) = V_430 -> V_433 ;
V_45 = F_8 ( V_2 , V_68 , V_318 , V_430 -> V_297 ) ;
F_114 ( V_2 , V_68 , V_318 , V_45 , V_430 -> V_297 ) ;
return 0 ;
}
static int F_122 ( struct V_270 * V_394 , struct V_407 * V_68 ,
struct V_275 * V_410 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_68 , V_410 -> V_280 , V_410 -> V_297 ) ;
if ( V_45 == NULL )
return - V_57 ;
V_410 -> V_45 = * V_45 ;
return 0 ;
}
static int F_123 ( struct V_270 * V_394 , struct V_407 * V_68 ,
struct V_275 * V_410 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_44 * V_45 ;
struct V_272 * V_273 ;
V_45 = F_8 ( V_2 , V_68 , V_410 -> V_280 , V_410 -> V_297 ) ;
if ( V_45 == NULL )
return - V_57 ;
F_114 ( V_2 , V_68 , V_410 -> V_280 , & V_410 -> V_45 , V_410 -> V_297 ) ;
* V_45 = V_410 -> V_45 ;
if ( V_410 -> V_280 == V_61 ) {
V_273 = F_112 ( V_2 , V_68 , V_410 -> V_297 ) ;
V_273 -> V_319 = 0 ;
V_273 -> V_323 = 0 ;
V_273 -> V_63 = V_410 -> V_45 . V_63 ;
V_273 -> V_64 = V_410 -> V_45 . V_64 ;
F_117 ( V_2 , & V_410 -> V_45 , V_273 ) ;
V_45 = F_8 ( V_2 , V_68 , V_318 ,
V_410 -> V_297 ) ;
* V_45 = V_410 -> V_45 ;
F_114 ( V_2 , V_68 , V_318 , V_45 ,
V_410 -> V_297 ) ;
V_45 = F_8 ( V_2 , V_68 , V_210 ,
V_410 -> V_297 ) ;
* V_45 = V_410 -> V_45 ;
F_114 ( V_2 , V_68 , V_210 , V_45 ,
V_410 -> V_297 ) ;
}
return 0 ;
}
static bool F_124 ( T_3 V_437 , T_3 V_438 , unsigned int V_439 )
{
const struct V_168 * V_440 , * V_441 ;
if ( V_437 == V_438 )
return true ;
V_440 = F_53 ( V_437 ) ;
V_441 = F_53 ( V_438 ) ;
if ( ( V_440 -> V_421 == 0 ) || ( V_441 -> V_421 == 0 ) )
return false ;
if ( V_440 -> V_421 != V_441 -> V_421 )
return false ;
return V_440 -> V_63 - V_441 -> V_63 + V_439 <= 6 ;
}
static int F_125 ( struct V_270 * V_394 ,
struct V_442 * V_443 ,
struct V_275 * V_444 ,
struct V_275 * V_445 )
{
struct V_1 * V_2 = F_103 ( V_394 ) ;
unsigned long V_446 ;
if ( V_444 -> V_45 . V_63 != V_445 -> V_45 . V_63 ||
V_444 -> V_45 . V_64 != V_445 -> V_45 . V_64 )
return - V_447 ;
if ( V_2 -> V_225 == V_243 ) {
struct V_244 * V_245 =
& ( (struct V_292 * )
F_69 ( V_443 -> V_448 -> V_203 )
-> V_293 ) -> V_294 . V_295 ;
V_446 = V_245 -> V_449 ;
} else {
V_446 = 0 ;
}
if ( ! F_124 ( V_444 -> V_45 . V_87 ,
V_445 -> V_45 . V_87 , V_446 ) )
return - V_447 ;
return 0 ;
}
static int F_126 ( struct V_270 * V_394 , struct V_450 * V_400 )
{
struct V_275 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_280 = V_61 ;
V_45 . V_297 = V_400 ? V_409 : V_62 ;
V_45 . V_45 . V_87 = V_88 ;
V_45 . V_45 . V_63 = 4096 ;
V_45 . V_45 . V_64 = 4096 ;
F_123 ( V_394 , V_400 ? V_400 -> V_280 : NULL , & V_45 ) ;
return 0 ;
}
static int F_127 ( struct V_451 * V_203 ,
const struct V_279 * V_452 ,
const struct V_279 * V_453 , T_3 V_110 )
{
struct V_270 * V_394 = F_69 ( V_203 ) ;
struct V_1 * V_2 = F_103 ( V_394 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_296 = V_452 -> V_296 ;
if ( F_128 ( V_453 -> V_203 ) )
V_296 |= 2 << 16 ;
switch ( V_296 ) {
case V_61 | 2 << 16 :
if ( ! ( V_110 & V_454 ) ) {
V_2 -> V_225 = V_455 ;
break;
}
if ( V_2 -> V_225 != V_455 )
return - V_103 ;
if ( V_453 -> V_203 == & V_4 -> V_456 . V_202 . V_203 )
V_2 -> V_225 = V_457 ;
else if ( V_453 -> V_203 == & V_4 -> V_458 . V_202 . V_203 )
V_2 -> V_225 = V_459 ;
else if ( V_453 -> V_203 == & V_4 -> V_460 . V_202 . V_203 )
V_2 -> V_225 = V_461 ;
else
V_2 -> V_225 = V_243 ;
break;
case V_210 | 2 << 16 :
if ( V_110 & V_454 ) {
if ( V_2 -> V_303 & ~ V_462 )
return - V_103 ;
V_2 -> V_303 |= V_462 ;
} else {
V_2 -> V_303 &= ~ V_462 ;
}
break;
case V_318 :
if ( V_110 & V_454 ) {
if ( V_2 -> V_303 & ~ V_304 )
return - V_103 ;
V_2 -> V_303 |= V_304 ;
} else {
V_2 -> V_303 &= ~ V_304 ;
}
break;
case V_318 | 2 << 16 :
if ( V_110 & V_454 ) {
if ( V_2 -> V_303 & ~ V_306 )
return - V_103 ;
V_2 -> V_303 |= V_306 ;
} else {
V_2 -> V_303 &= ~ V_306 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_130 ( & V_2 -> V_202 ) ;
F_131 ( & V_2 -> V_329 ) ;
}
int F_132 ( struct V_1 * V_2 ,
struct V_463 * V_361 )
{
int V_120 ;
V_120 = F_133 ( V_361 , & V_2 -> V_202 ) ;
if ( V_120 < 0 )
goto error;
V_120 = F_134 ( & V_2 -> V_329 , V_361 ) ;
if ( V_120 < 0 )
goto error;
return 0 ;
error:
F_129 ( V_2 ) ;
return V_120 ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_270 * V_394 = & V_2 -> V_202 ;
struct V_279 * V_287 = V_2 -> V_287 ;
struct V_451 * V_464 = & V_394 -> V_203 ;
int V_120 ;
V_2 -> V_225 = V_455 ;
F_136 ( V_394 , & V_465 ) ;
V_394 -> V_466 = & V_467 ;
F_137 ( V_394 -> V_468 , L_15 , sizeof( V_394 -> V_468 ) ) ;
V_394 -> V_469 = 1 << 16 ;
F_138 ( V_394 , V_2 ) ;
V_394 -> V_110 |= V_470 | V_471 ;
V_287 [ V_61 ] . V_110 = V_472
| V_473 ;
V_287 [ V_210 ] . V_110 = V_474 ;
V_287 [ V_318 ] . V_110 = V_474 ;
V_464 -> V_475 = & V_476 ;
V_120 = F_139 ( V_464 , V_477 , V_287 ) ;
if ( V_120 < 0 )
return V_120 ;
F_126 ( V_394 , NULL ) ;
V_2 -> V_329 . type = V_478 ;
V_2 -> V_329 . V_475 = & V_479 ;
V_2 -> V_329 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_329 . V_480 = F_140 ( 4096 * 4096 ) * 3 ;
V_2 -> V_329 . V_481 = 32 ;
V_120 = F_141 ( & V_2 -> V_329 , L_16 ) ;
if ( V_120 < 0 )
goto error;
return 0 ;
error:
F_142 ( V_464 ) ;
return V_120 ;
}
int F_143 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
int V_120 ;
F_144 ( & V_2 -> V_181 ) ;
F_145 ( & V_2 -> V_81 ) ;
F_146 ( & V_2 -> V_343 ) ;
V_2 -> V_340 = V_344 ;
F_147 ( & V_2 -> V_94 . V_116 , F_33 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_148 ( & V_2 -> V_94 . V_117 ) ;
F_144 ( & V_2 -> V_94 . V_111 ) ;
V_2 -> V_134 . V_138 = 0 ;
V_2 -> V_134 . V_145 = 0 ;
V_2 -> V_119 = V_185 ;
F_56 ( V_2 ) ;
V_120 = F_135 ( V_2 ) ;
if ( V_120 < 0 ) {
F_149 ( & V_2 -> V_343 ) ;
return V_120 ;
}
return 0 ;
}
void F_150 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
F_151 ( & V_2 -> V_329 ) ;
F_142 ( & V_2 -> V_202 . V_203 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_132 ) ;
F_78 ( & V_2 -> V_94 . V_116 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_117 ) ;
if ( V_2 -> V_151 . V_66 != NULL )
F_26 ( V_4 -> V_5 , V_2 -> V_151 . V_153 * 4 , V_2 -> V_151 . V_66 ,
V_2 -> V_151 . V_105 ) ;
F_149 ( & V_2 -> V_343 ) ;
}
