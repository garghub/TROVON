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
F_3 ( V_4 -> V_5 , L_4
L_5 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_59 & 1 ) || ( V_43 -> V_60 & 1 ) ) {
F_3 ( V_4 -> V_5 , L_6 ) ;
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
F_3 ( V_4 -> V_5 , L_7 ) ;
return - V_57 ;
}
if ( V_43 -> V_58 < ( V_50 * 4 ) ) {
F_3 ( V_4 -> V_5 , L_8 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_65 / V_43 -> V_58 ) < V_51 ) {
F_3 ( V_4 -> V_5 , L_9 ) ;
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
F_19 ( F_20 ( V_2 ) , L_10 ) ;
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
F_3 ( F_20 ( V_2 ) , L_11 ) ;
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
F_3 ( F_20 ( V_2 ) , L_12
L_13 , V_123 ) ;
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
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_133 ) {
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
return 1 ;
}
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
return 0 ;
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
unsigned long V_204 = V_201 -> V_204 ;
unsigned int V_205 = V_4 -> V_206 == V_207 ? 64 : 8 ;
unsigned int div = 0 ;
T_3 V_208 ;
V_208 = F_6 ( V_4 , V_39 , V_209 )
& ~ ( V_210 | V_211 ) ;
V_169 = F_53 ( V_2 -> V_171 [ V_61 ] . V_87 ) ;
switch ( V_169 -> V_63 ) {
case 8 :
case 10 :
V_208 |= V_212 ;
break;
case 11 :
V_208 |= V_213 ;
break;
case 12 :
V_208 |= V_214 ;
break;
case 13 :
V_208 |= V_215 ;
break;
}
if ( V_201 -> V_216 )
div = F_61 ( V_204 , V_201 -> V_217 ) ;
else if ( V_201 -> V_218 )
div = V_204 / V_201 -> V_218 ;
div = V_134 ( div , 2U , V_205 ) ;
V_208 |= ( div - 2 ) << V_219 ;
F_10 ( V_4 , V_208 , V_39 , V_209 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_4 V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_209 ,
V_220 , V_86 ? V_220 : 0 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
T_3 V_58 , T_4 V_221 , T_4 V_222 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_58 & 0xffff ,
V_39 , V_223 ) ;
F_18 ( V_4 , V_39 , V_224 ,
V_225 ) ;
F_18 ( V_4 , V_39 , V_224 ,
V_226 ) ;
switch ( V_221 ) {
case V_227 :
F_58 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_228 ) ;
break;
case V_229 :
F_58 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_230 ) ;
break;
case V_231 :
F_58 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_232 ) ;
break;
case V_233 :
F_58 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_234 ) ;
break;
default:
break;
}
}
static void F_64 ( struct V_1 * V_2 , T_3 V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_66 , V_39 , V_235 ) ;
}
void F_65 ( struct V_1 * V_2 ,
unsigned int * V_217 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
unsigned int V_236 ;
if ( V_201 == NULL )
return;
if ( V_2 -> V_216 == V_237 )
V_236 = V_201 -> V_204 / 2 * 9 / 10 ;
else
V_236 = V_201 -> V_204 / 2 ;
* V_217 = F_66 ( * V_217 , V_236 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_238 * V_239 ,
unsigned int V_240 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_44 * V_45 ;
T_3 V_241 = V_242 ;
V_45 = & V_2 -> V_171 [ V_61 ] ;
if ( V_45 -> V_87 == V_243 ||
V_45 -> V_87 == V_244 ) {
V_241 |= V_245 ;
}
switch ( V_240 ) {
case 8 :
V_241 |= V_246 ;
break;
case 10 :
V_241 |= V_247 ;
break;
case 11 :
V_241 |= V_248 ;
break;
case 12 :
V_241 |= V_249 ;
break;
}
if ( V_239 && V_239 -> V_250 )
V_241 |= V_251 ;
if ( V_239 && V_239 -> V_252 )
V_241 |= V_253 ;
if ( V_239 && V_239 -> V_254 )
V_241 |= V_255 ;
F_10 ( V_4 , V_241 , V_39 , V_165 ) ;
if ( V_45 -> V_87 == V_244 )
F_58 ( V_4 , V_39 , V_198 ,
V_256 ) ;
else
F_18 ( V_4 , V_39 , V_198 ,
V_256 ) ;
F_18 ( V_4 , V_39 , V_257 ,
V_258 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_238 * V_239 = NULL ;
struct V_259 * V_260 ;
struct V_44 * V_45 ;
const struct V_261 * V_262 ;
const struct V_168 * V_263 ;
struct V_264 V_265 ;
unsigned int V_266 ;
unsigned int V_267 = 0 ;
struct V_268 * V_269 ;
unsigned long V_110 ;
unsigned int V_270 ;
unsigned int V_271 ;
T_3 V_241 ;
T_3 V_272 ;
V_269 = F_69 ( & V_2 -> V_273 [ V_61 ] ) ;
V_260 = F_70 ( V_269 -> V_203 ) ;
if ( V_2 -> V_216 == V_237 )
V_239 = & ( (struct V_274 * ) V_260 -> V_275 )
-> V_276 . V_277 ;
V_265 . V_269 = V_269 -> V_278 ;
V_265 . V_279 = V_62 ;
if ( ! F_71 ( V_260 , V_269 , V_280 , NULL , & V_265 ) ) {
V_263 = F_53 ( V_265 . V_45 . V_87 ) ;
V_267 = V_263 -> V_63 ;
}
V_263 = F_53
( V_4 -> V_197 . V_171 [ V_61 ] . V_87 ) ;
V_266 = V_263 -> V_63 ;
V_271 = V_267 - V_266 ;
if ( V_263 -> V_87 == V_243 )
V_270 = V_281 ;
else if ( V_263 -> V_87 == V_244 )
V_270 = V_282 ;
else
V_270 = V_283 ;
F_72 ( V_4 , V_2 -> V_216 , V_239 , V_271 , V_270 ) ;
F_67 ( V_2 , V_239 , V_266 ) ;
V_241 = F_6 ( V_4 , V_39 , V_165 ) ;
V_241 &= ~ V_284 ;
if ( V_2 -> V_285 & V_286 )
V_241 |= V_287 ;
else
V_241 &= ~ V_287 ;
if ( V_2 -> V_285 & V_288 )
V_241 |= V_289 ;
else
V_241 &= ~ V_289 ;
V_45 = & V_2 -> V_171 [ V_61 ] ;
switch ( V_45 -> V_87 ) {
case V_89 :
case V_290 :
V_272 = V_291 ;
break;
case V_90 :
case V_292 :
V_272 = V_293 ;
break;
case V_91 :
case V_294 :
V_272 = V_295 ;
break;
default:
V_272 = V_296 ;
break;
}
F_54 ( V_2 , V_272 ) ;
F_10 ( V_4 , ( ( V_45 -> V_64 - 2 ) << V_297 ) |
( ( V_45 -> V_64 * 2 / 3 ) << V_298 ) ,
V_39 , V_299 ) ;
V_45 = & V_2 -> V_171 [ V_300 ] ;
V_262 = & V_2 -> V_262 ;
F_10 ( V_4 , ( V_262 -> V_301 << V_302 ) |
( ( V_262 -> V_63 - 1 ) << V_303 ) ,
V_39 , V_304 ) ;
F_10 ( V_4 , V_262 -> V_305 << V_306 ,
V_39 , V_307 ) ;
F_10 ( V_4 , ( V_262 -> V_64 - 1 )
<< V_308 ,
V_39 , V_309 ) ;
F_63 ( V_2 , V_2 -> V_310 . V_311 , 0 , 0 ) ;
if ( V_45 -> V_87 == V_312 )
F_58 ( V_4 , V_39 , V_198 ,
V_313 ) ;
else
F_18 ( V_4 , V_39 , V_198 ,
V_313 ) ;
if ( F_53 ( V_45 -> V_87 ) -> V_63 <= 8 )
V_241 |= V_314 ;
else
V_241 &= ~ V_314 ;
F_10 ( V_4 , V_241 , V_39 , V_165 ) ;
V_45 = & V_2 -> V_171 [ V_315 ] ;
F_10 ( V_4 , ( 0 << V_316 ) |
( V_45 -> V_63 << V_317 ) ,
V_39 , V_318 ) ;
F_10 ( V_4 , ( 0 << V_319 ) |
( ( V_45 -> V_64 + 1 ) << V_320 ) ,
V_39 , V_321 ) ;
F_10 ( V_4 , ( V_45 -> V_63 << V_322 ) |
( V_45 -> V_64 << V_323 ) ,
V_39 , V_324 ) ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_325;
F_73 ( V_2 -> V_94 . V_133 ) ;
if ( V_2 -> V_94 . V_133 == NULL &&
F_22 ( V_2 , V_2 -> V_94 . V_132 ) == 0 ) {
V_2 -> V_94 . V_133 = V_2 -> V_94 . V_132 ;
} else {
F_42 ( & V_2 -> V_94 . V_132 -> V_112 , & V_2 -> V_94 . V_117 ) ;
F_43 ( & V_2 -> V_94 . V_116 ) ;
}
V_2 -> V_94 . V_132 = NULL ;
V_325:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
F_56 ( V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_40 ,
V_326 , V_86 ? V_326 : 0 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
int V_120 = 0 ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( V_2 -> V_95 == V_327 )
V_2 -> V_328 = V_329 ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
V_120 = F_76 ( V_2 -> V_81 ,
V_2 -> V_328 == V_330 ,
F_77 ( 2000 ) ) ;
if ( V_120 == 0 ) {
V_120 = - V_85 ;
F_19 ( F_20 ( V_2 ) , L_14 ) ;
}
F_46 ( F_2 ( V_2 ) , V_92 ) ;
F_78 ( & V_2 -> V_331 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_132 ) ;
V_2 -> V_94 . V_132 = V_2 -> V_94 . V_133 ;
V_2 -> V_94 . V_133 = NULL ;
F_79 ( & V_2 -> V_94 . V_116 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_117 ) ;
F_80 ( & V_2 -> V_331 ) ;
V_2 -> V_328 = V_332 ;
return V_120 > 0 ? 0 : V_120 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( F_44 ( V_2 ) )
F_15 ( V_2 , 1 ) ;
F_74 ( V_2 , 1 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( V_2 )
| ( F_6 ( V_4 , V_333 , V_334 ) &
V_335 )
| ( F_6 ( V_4 , V_333 , V_336 ) &
V_335 )
| ( F_6 ( V_4 , V_333 , V_337 ) &
V_335 )
| ( F_6 ( V_4 , V_333 , V_338 ) &
V_335 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
unsigned int V_339 )
{
unsigned int V_81 = 0 ;
if ( V_339 == 0 )
V_339 = 10000 ;
for ( V_81 = 0 ; V_81 <= V_339 ; V_81 ++ ) {
if ( ! F_82 ( V_2 ) )
return 0 ;
F_13 () ;
F_14 ( 1 ) ;
}
return - V_103 ;
}
static int F_84 ( struct V_1 * V_2 , T_3 V_340 )
{
int V_341 = 0 ;
switch ( ( V_2 -> V_328 & 3 ) | V_340 ) {
case V_329 | V_342 :
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_74 ( V_2 , 0 ) ;
V_2 -> V_328 = V_343 ;
return 1 ;
case V_343 | V_344 :
V_2 -> V_328 |= V_345 ;
if ( V_2 -> V_94 . V_95 == V_96 )
V_2 -> V_328 |= V_346 ;
V_341 = 1 ;
break;
case V_343 | V_347 :
V_2 -> V_328 |= V_346 ;
V_341 = 1 ;
break;
case V_343 | V_342 :
return 1 ;
}
if ( V_2 -> V_328 == V_330 ) {
F_85 ( & V_2 -> V_81 ) ;
V_341 = 1 ;
}
return V_341 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_348 * V_349 = V_2 -> V_202 . V_350 ;
struct V_351 V_340 ;
F_87 ( & V_201 -> V_352 ) ;
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . type = V_353 ;
V_340 . V_354 . V_355 . V_356 = F_88 ( & V_201 -> V_352 ) ;
F_89 ( V_349 , & V_340 ) ;
}
static void F_90 ( struct V_1 * V_2 , T_3 V_357 )
{
unsigned long V_110 ;
if ( V_357 & V_358 ) {
struct V_200 * V_201 =
F_60 ( & V_2 -> V_202 . V_203 ) ;
F_23 ( V_2 ) ;
V_201 -> error = true ;
F_3 ( F_20 ( V_2 ) , L_15 ) ;
}
if ( ! ( V_357 & V_359 ) )
return;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
if ( V_2 -> V_94 . V_95 == V_98 )
V_2 -> V_94 . V_95 = V_96 ;
if ( F_84 ( V_2 , V_347 ) )
goto V_128;
if ( V_2 -> V_94 . V_95 != V_360 )
goto V_128;
V_2 -> V_94 . V_95 = V_96 ;
if ( V_357 & V_361 )
goto V_128;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_128;
F_45 ( V_2 ) ;
V_128:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_60 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_362 * V_363 ;
int V_364 = 0 ;
if ( F_47 ( & V_2 -> V_310 . V_365 ) )
goto V_128;
if ( V_2 -> V_95 == V_327 && V_2 -> V_366 ) {
V_364 = 1 ;
V_2 -> V_366 = 0 ;
goto V_128;
}
if ( F_83 ( V_2 , 1000 ) ) {
F_92 ( V_4 -> V_5 , L_16 ) ;
V_4 -> V_367 |= 1U << V_2 -> V_202 . V_203 . V_368 ;
F_93 ( V_201 ) ;
goto V_128;
}
V_363 = F_94 ( & V_2 -> V_310 ) ;
if ( V_363 != NULL ) {
F_64 ( V_2 , V_363 -> V_105 ) ;
V_364 = 1 ;
}
V_201 -> V_95 |= V_369 ;
if ( V_2 -> V_95 == V_370 &&
F_95 ( V_201 ) )
F_96 ( V_201 ,
V_370 ) ;
V_128:
return V_364 ;
}
static void F_97 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
int V_364 = 0 ;
if ( V_2 -> V_285 & V_286 )
V_364 = F_91 ( V_2 ) ;
F_29 ( & V_2 -> V_181 , V_110 ) ;
if ( F_84 ( V_2 , V_344 ) ) {
F_32 ( & V_2 -> V_181 , V_110 ) ;
return;
}
if ( ! V_2 -> V_182 )
F_56 ( V_2 ) ;
F_32 ( & V_2 -> V_181 , V_110 ) ;
if ( V_364 )
F_81 ( V_2 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
F_29 ( & V_2 -> V_94 . V_111 , V_110 ) ;
switch ( V_2 -> V_95 ) {
case V_370 :
V_2 -> V_328 = V_329 ;
break;
case V_327 :
if ( V_2 -> V_285 & V_286 ) {
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_74 ( V_2 , 0 ) ;
}
break;
case V_193 :
break;
}
if ( F_84 ( V_2 , V_342 ) )
goto V_128;
if ( V_2 -> V_94 . V_132 == NULL )
goto V_128;
if ( V_2 -> V_94 . V_95 == V_97 ) {
F_15 ( V_2 , 0 ) ;
V_2 -> V_94 . V_95 = V_360 ;
goto V_128;
}
if ( V_2 -> V_94 . V_95 == V_96 )
F_45 ( V_2 ) ;
V_128:
F_32 ( & V_2 -> V_94 . V_111 , V_110 ) ;
}
int F_99 ( struct V_1 * V_2 , T_3 V_357 )
{
if ( V_2 -> V_95 == V_193 )
return 0 ;
if ( V_357 & V_371 )
F_98 ( V_2 ) ;
F_90 ( V_2 , V_357 ) ;
if ( V_357 & V_372 )
F_97 ( V_2 ) ;
if ( V_357 & V_361 )
F_86 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_373 * V_374 , struct V_362 * V_363 )
{
struct V_1 * V_2 = & V_374 -> V_4 -> V_197 ;
if ( ! ( V_2 -> V_285 & V_286 ) )
return - V_375 ;
F_64 ( V_2 , V_363 -> V_105 ) ;
V_2 -> V_366 = 1 ;
return 0 ;
}
static long F_101 ( struct V_259 * V_376 , unsigned int V_377 , void * V_378 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
int V_120 ;
switch ( V_377 ) {
case V_379 :
F_78 ( & V_2 -> V_331 ) ;
V_120 = F_55 ( V_2 , V_378 ) ;
F_80 ( & V_2 -> V_331 ) ;
break;
default:
return - V_380 ;
}
return V_120 ;
}
static int F_103 ( struct V_259 * V_376 , struct V_381 * V_382 ,
struct V_383 * V_384 )
{
if ( V_384 -> type != V_353 )
return - V_57 ;
if ( V_384 -> V_368 != 0 )
return - V_57 ;
return F_104 ( V_382 , V_384 , V_385 , NULL ) ;
}
static int F_105 ( struct V_259 * V_376 , struct V_381 * V_382 ,
struct V_383 * V_384 )
{
return F_106 ( V_382 , V_384 ) ;
}
static int F_107 ( struct V_259 * V_376 , int V_86 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_120 = 0 ;
if ( V_2 -> V_95 == V_193 ) {
if ( V_86 == V_193 )
return 0 ;
F_108 ( V_4 , V_386 ) ;
F_58 ( V_4 , V_39 , V_198 ,
V_199 ) ;
F_68 ( V_2 ) ;
F_59 ( V_2 ) ;
F_62 ( V_2 , 1 ) ;
F_1 ( V_2 ) ;
}
switch ( V_86 ) {
case V_327 :
if ( V_2 -> V_285 & V_286 )
F_16 ( V_4 , V_387 ) ;
if ( V_2 -> V_366 || ! ( V_2 -> V_285 & V_286 ) )
F_81 ( V_2 ) ;
V_2 -> V_366 = 0 ;
break;
case V_370 :
if ( V_2 -> V_285 & V_286 &&
V_2 -> V_95 != V_370 )
F_16 ( V_4 , V_387 ) ;
F_81 ( V_2 ) ;
break;
case V_193 :
V_120 = F_75 ( V_2 ) ;
if ( V_2 -> V_285 & V_286 )
F_46 ( V_4 , V_387 ) ;
F_109 ( V_4 , V_386 ) ;
V_2 -> V_366 = 0 ;
break;
}
V_2 -> V_95 = V_86 ;
return V_120 ;
}
static struct V_44 *
F_8 ( struct V_1 * V_2 , struct V_388 * V_382 ,
unsigned int V_269 , enum V_389 V_279 )
{
if ( V_279 == V_390 )
return F_110 ( V_382 , V_269 ) ;
else
return & V_2 -> V_171 [ V_269 ] ;
}
static struct V_261 *
F_111 ( struct V_1 * V_2 , struct V_388 * V_382 ,
enum V_389 V_279 )
{
if ( V_279 == V_390 )
return F_112 ( V_382 , V_300 ) ;
else
return & V_2 -> V_262 ;
}
static void
F_113 ( struct V_1 * V_2 , struct V_388 * V_382 ,
unsigned int V_269 , struct V_44 * V_391 ,
enum V_389 V_279 )
{
const struct V_168 * V_169 ;
enum V_392 V_393 ;
unsigned int V_63 = V_391 -> V_63 ;
unsigned int V_64 = V_391 -> V_64 ;
struct V_261 * V_262 ;
unsigned int V_394 ;
switch ( V_269 ) {
case V_61 :
for ( V_394 = 0 ; V_394 < F_114 ( V_395 ) ; V_394 ++ ) {
if ( V_391 -> V_87 == V_395 [ V_394 ] )
break;
}
if ( V_394 >= F_114 ( V_395 ) )
V_391 -> V_87 = V_88 ;
V_391 -> V_63 = F_115 ( T_3 , V_63 , 32 , 4096 ) ;
V_391 -> V_64 = F_115 ( T_3 , V_64 , 32 , 4096 ) ;
break;
case V_300 :
V_393 = V_391 -> V_87 ;
* V_391 = * F_8 ( V_2 , V_382 , V_61 , V_279 ) ;
if ( V_391 -> V_87 == V_243 ||
V_391 -> V_87 == V_244 ) {
if ( V_393 == V_243 ||
V_393 == V_244 ||
V_393 == V_312 ||
V_393 == V_396 )
V_391 -> V_87 = V_393 ;
if ( V_391 -> V_87 == V_243 )
V_391 -> V_87 = V_312 ;
else if ( V_391 -> V_87 == V_244 )
V_391 -> V_87 = V_396 ;
}
V_262 = F_111 ( V_2 , V_382 , V_279 ) ;
V_391 -> V_63 = V_262 -> V_63 ;
V_391 -> V_64 = V_262 -> V_64 ;
break;
case V_315 :
* V_391 = * F_8 ( V_2 , V_382 , V_61 , V_279 ) ;
V_169 = F_53 ( V_391 -> V_87 ) ;
V_391 -> V_87 = V_169 -> V_397 ;
if ( V_391 -> V_87 == V_243 ||
V_391 -> V_87 == V_244 )
V_391 -> V_87 = 0 ;
V_391 -> V_63 = F_115 ( T_3 , V_63 , 32 , V_391 -> V_63 ) ;
V_391 -> V_64 = F_115 ( T_3 , V_64 , 32 , V_391 -> V_64 - 1 ) ;
break;
}
V_391 -> V_398 = V_399 ;
V_391 -> V_400 = V_401 ;
}
static void F_116 ( struct V_1 * V_2 ,
const struct V_44 * V_402 ,
struct V_261 * V_262 )
{
const struct V_168 * V_169 ;
unsigned int V_403 ;
V_169 = F_53 ( V_402 -> V_87 ) ;
if ( V_169 -> V_404 != V_405 ) {
V_262 -> V_301 &= ~ 1 ;
V_262 -> V_305 &= ~ 1 ;
}
V_262 -> V_301 = F_115 ( T_3 , V_262 -> V_301 , 0 , V_402 -> V_63 - V_406 ) ;
V_262 -> V_305 = F_115 ( T_3 , V_262 -> V_305 , 0 , V_402 -> V_64 - V_407 ) ;
V_403 = ( V_402 -> V_63 - V_262 -> V_301 + 15 ) & ~ 15 ;
V_262 -> V_63 = F_115 ( T_3 , V_262 -> V_63 , V_406 , V_403 )
& ~ 15 ;
V_262 -> V_64 = F_115 ( T_3 , V_262 -> V_64 , V_407 ,
V_402 -> V_64 - V_262 -> V_305 ) ;
if ( V_169 -> V_404 != V_405 ) {
V_262 -> V_63 &= ~ 1 ;
V_262 -> V_64 &= ~ 1 ;
}
}
static int F_117 ( struct V_259 * V_376 ,
struct V_388 * V_382 ,
struct V_408 * V_87 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 * V_45 ;
switch ( V_87 -> V_269 ) {
case V_61 :
if ( V_87 -> V_278 >= F_114 ( V_395 ) )
return - V_57 ;
V_87 -> V_87 = V_395 [ V_87 -> V_278 ] ;
break;
case V_300 :
V_45 = F_8 ( V_2 , V_382 , V_87 -> V_269 ,
V_390 ) ;
if ( V_45 -> V_87 == V_243 ||
V_45 -> V_87 == V_244 ) {
if ( V_87 -> V_278 == 0 )
V_87 -> V_87 = V_312 ;
else if ( V_87 -> V_278 == 1 )
V_87 -> V_87 = V_396 ;
else
return - V_57 ;
} else {
if ( V_87 -> V_278 == 0 )
V_87 -> V_87 = V_45 -> V_87 ;
else
return - V_57 ;
}
break;
case V_315 :
if ( V_87 -> V_278 != 0 )
return - V_57 ;
V_45 = F_8 ( V_2 , V_382 , V_87 -> V_269 ,
V_390 ) ;
if ( V_45 -> V_87 == 0 )
return - V_57 ;
V_87 -> V_87 = V_45 -> V_87 ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_118 ( struct V_259 * V_376 ,
struct V_388 * V_382 ,
struct V_409 * V_410 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 V_45 ;
if ( V_410 -> V_278 != 0 )
return - V_57 ;
V_45 . V_87 = V_410 -> V_87 ;
V_45 . V_63 = 1 ;
V_45 . V_64 = 1 ;
F_113 ( V_2 , V_382 , V_410 -> V_269 , & V_45 , V_390 ) ;
V_410 -> V_50 = V_45 . V_63 ;
V_410 -> V_51 = V_45 . V_64 ;
if ( V_45 . V_87 != V_410 -> V_87 )
return - V_57 ;
V_45 . V_87 = V_410 -> V_87 ;
V_45 . V_63 = - 1 ;
V_45 . V_64 = - 1 ;
F_113 ( V_2 , V_382 , V_410 -> V_269 , & V_45 , V_390 ) ;
V_410 -> V_403 = V_45 . V_63 ;
V_410 -> V_411 = V_45 . V_64 ;
return 0 ;
}
static int F_119 ( struct V_259 * V_376 , struct V_388 * V_382 ,
struct V_412 * V_413 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 * V_45 ;
if ( V_413 -> V_269 != V_300 )
return - V_57 ;
switch ( V_413 -> V_414 ) {
case V_415 :
V_413 -> V_416 . V_301 = 0 ;
V_413 -> V_416 . V_305 = 0 ;
V_413 -> V_416 . V_63 = V_417 ;
V_413 -> V_416 . V_64 = V_417 ;
V_45 = F_8 ( V_2 , V_382 , V_61 , V_413 -> V_279 ) ;
F_116 ( V_2 , V_45 , & V_413 -> V_416 ) ;
break;
case V_418 :
V_413 -> V_416 = * F_111 ( V_2 , V_382 , V_413 -> V_279 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_120 ( struct V_259 * V_376 , struct V_388 * V_382 ,
struct V_412 * V_413 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 * V_45 ;
if ( V_413 -> V_414 != V_418 ||
V_413 -> V_269 != V_300 )
return - V_57 ;
if ( V_2 -> V_95 != V_193 )
return - V_103 ;
if ( V_413 -> V_110 & V_419 ) {
V_413 -> V_416 = * F_111 ( V_2 , V_382 , V_413 -> V_279 ) ;
return 0 ;
}
V_45 = F_8 ( V_2 , V_382 , V_61 , V_413 -> V_279 ) ;
F_116 ( V_2 , V_45 , & V_413 -> V_416 ) ;
* F_111 ( V_2 , V_382 , V_413 -> V_279 ) = V_413 -> V_416 ;
V_45 = F_8 ( V_2 , V_382 , V_300 , V_413 -> V_279 ) ;
F_113 ( V_2 , V_382 , V_300 , V_45 , V_413 -> V_279 ) ;
return 0 ;
}
static int F_121 ( struct V_259 * V_376 , struct V_388 * V_382 ,
struct V_264 * V_391 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_382 , V_391 -> V_269 , V_391 -> V_279 ) ;
if ( V_45 == NULL )
return - V_57 ;
V_391 -> V_45 = * V_45 ;
return 0 ;
}
static int F_122 ( struct V_259 * V_376 , struct V_388 * V_382 ,
struct V_264 * V_391 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_44 * V_45 ;
struct V_261 * V_262 ;
V_45 = F_8 ( V_2 , V_382 , V_391 -> V_269 , V_391 -> V_279 ) ;
if ( V_45 == NULL )
return - V_57 ;
F_113 ( V_2 , V_382 , V_391 -> V_269 , & V_391 -> V_45 , V_391 -> V_279 ) ;
* V_45 = V_391 -> V_45 ;
if ( V_391 -> V_269 == V_61 ) {
V_262 = F_111 ( V_2 , V_382 , V_391 -> V_279 ) ;
V_262 -> V_301 = 0 ;
V_262 -> V_305 = 0 ;
V_262 -> V_63 = V_391 -> V_45 . V_63 ;
V_262 -> V_64 = V_391 -> V_45 . V_64 ;
F_116 ( V_2 , & V_391 -> V_45 , V_262 ) ;
V_45 = F_8 ( V_2 , V_382 , V_300 ,
V_391 -> V_279 ) ;
* V_45 = V_391 -> V_45 ;
F_113 ( V_2 , V_382 , V_300 , V_45 ,
V_391 -> V_279 ) ;
V_45 = F_8 ( V_2 , V_382 , V_315 ,
V_391 -> V_279 ) ;
* V_45 = V_391 -> V_45 ;
F_113 ( V_2 , V_382 , V_315 , V_45 ,
V_391 -> V_279 ) ;
}
return 0 ;
}
static bool F_123 ( enum V_392 V_420 ,
enum V_392 V_421 ,
unsigned int V_422 )
{
const struct V_168 * V_423 , * V_424 ;
if ( V_420 == V_421 )
return true ;
V_423 = F_53 ( V_420 ) ;
V_424 = F_53 ( V_421 ) ;
if ( ( V_423 -> V_404 == 0 ) || ( V_424 -> V_404 == 0 ) )
return false ;
if ( V_423 -> V_404 != V_424 -> V_404 )
return false ;
return V_423 -> V_63 - V_424 -> V_63 + V_422 <= 6 ;
}
static int F_124 ( struct V_259 * V_376 ,
struct V_425 * V_426 ,
struct V_264 * V_427 ,
struct V_264 * V_428 )
{
struct V_1 * V_2 = F_102 ( V_376 ) ;
unsigned long V_429 ;
if ( V_427 -> V_45 . V_63 != V_428 -> V_45 . V_63 ||
V_427 -> V_45 . V_64 != V_428 -> V_45 . V_64 )
return - V_430 ;
if ( V_2 -> V_216 == V_237 ) {
struct V_238 * V_239 =
& ( (struct V_274 * )
F_70 ( V_426 -> V_431 -> V_203 )
-> V_275 ) -> V_276 . V_277 ;
V_429 = V_239 -> V_432 * 2 ;
} else {
V_429 = 0 ;
}
if ( ! F_123 ( V_427 -> V_45 . V_87 ,
V_428 -> V_45 . V_87 , V_429 ) )
return - V_430 ;
return 0 ;
}
static int F_125 ( struct V_259 * V_376 , struct V_388 * V_382 )
{
struct V_264 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_269 = V_61 ;
V_45 . V_279 = V_382 ? V_390 : V_62 ;
V_45 . V_45 . V_87 = V_88 ;
V_45 . V_45 . V_63 = 4096 ;
V_45 . V_45 . V_64 = 4096 ;
F_122 ( V_376 , V_382 , & V_45 ) ;
return 0 ;
}
static int F_126 ( struct V_433 * V_203 ,
const struct V_268 * V_434 ,
const struct V_268 * V_435 , T_3 V_110 )
{
struct V_259 * V_376 = F_70 ( V_203 ) ;
struct V_1 * V_2 = F_102 ( V_376 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_434 -> V_278 | F_127 ( V_435 -> V_203 ) ) {
case V_61 | V_436 :
if ( ! ( V_110 & V_437 ) ) {
V_2 -> V_216 = V_438 ;
break;
}
if ( V_2 -> V_216 != V_438 )
return - V_103 ;
if ( V_435 -> V_203 == & V_4 -> V_439 . V_202 . V_203 )
V_2 -> V_216 = V_440 ;
else if ( V_435 -> V_203 == & V_4 -> V_441 . V_202 . V_203 )
V_2 -> V_216 = V_442 ;
else if ( V_435 -> V_203 == & V_4 -> V_443 . V_202 . V_203 )
V_2 -> V_216 = V_444 ;
else
V_2 -> V_216 = V_237 ;
break;
case V_315 | V_436 :
if ( V_110 & V_437 ) {
if ( V_2 -> V_285 & ~ V_445 )
return - V_103 ;
V_2 -> V_285 |= V_445 ;
} else {
V_2 -> V_285 &= ~ V_445 ;
}
break;
case V_300 | V_446 :
if ( V_110 & V_437 ) {
if ( V_2 -> V_285 & ~ V_286 )
return - V_103 ;
V_2 -> V_285 |= V_286 ;
} else {
V_2 -> V_285 &= ~ V_286 ;
}
break;
case V_300 | V_436 :
if ( V_110 & V_437 ) {
if ( V_2 -> V_285 & ~ V_288 )
return - V_103 ;
V_2 -> V_285 |= V_288 ;
} else {
V_2 -> V_285 &= ~ V_288 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
void F_128 ( struct V_1 * V_2 )
{
F_129 ( & V_2 -> V_202 ) ;
F_130 ( & V_2 -> V_310 ) ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_447 * V_349 )
{
int V_120 ;
V_120 = F_132 ( V_349 , & V_2 -> V_202 ) ;
if ( V_120 < 0 )
goto error;
V_120 = F_133 ( & V_2 -> V_310 , V_349 ) ;
if ( V_120 < 0 )
goto error;
return 0 ;
error:
F_128 ( V_2 ) ;
return V_120 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_259 * V_376 = & V_2 -> V_202 ;
struct V_268 * V_273 = V_2 -> V_273 ;
struct V_433 * V_448 = & V_376 -> V_203 ;
int V_120 ;
V_2 -> V_216 = V_438 ;
F_135 ( V_376 , & V_449 ) ;
V_376 -> V_450 = & V_451 ;
F_136 ( V_376 -> V_452 , L_17 , sizeof( V_376 -> V_452 ) ) ;
V_376 -> V_453 = 1 << 16 ;
F_137 ( V_376 , V_2 ) ;
V_376 -> V_110 |= V_454 | V_455 ;
V_273 [ V_61 ] . V_110 = V_456
| V_457 ;
V_273 [ V_315 ] . V_110 = V_458 ;
V_273 [ V_300 ] . V_110 = V_458 ;
V_448 -> V_459 = & V_460 ;
V_120 = F_138 ( V_448 , V_461 , V_273 , 0 ) ;
if ( V_120 < 0 )
return V_120 ;
F_125 ( V_376 , NULL ) ;
V_2 -> V_310 . type = V_462 ;
V_2 -> V_310 . V_459 = & V_463 ;
V_2 -> V_310 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_310 . V_464 = F_139 ( 4096 * 4096 ) * 3 ;
V_2 -> V_310 . V_465 = 32 ;
V_120 = F_140 ( & V_2 -> V_310 , L_18 ) ;
if ( V_120 < 0 )
goto V_466;
V_120 = F_141 ( & V_2 -> V_202 . V_203 , V_300 ,
& V_2 -> V_310 . V_374 . V_203 , 0 , 0 ) ;
if ( V_120 < 0 )
goto V_467;
return 0 ;
V_467:
F_142 ( & V_2 -> V_310 ) ;
V_466:
F_143 ( V_448 ) ;
return V_120 ;
}
int F_144 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
int V_120 ;
F_145 ( & V_2 -> V_181 ) ;
F_146 ( & V_2 -> V_81 ) ;
F_147 ( & V_2 -> V_331 ) ;
V_2 -> V_328 = V_332 ;
F_148 ( & V_2 -> V_94 . V_116 , F_33 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_149 ( & V_2 -> V_94 . V_117 ) ;
F_145 ( & V_2 -> V_94 . V_111 ) ;
V_2 -> V_134 . V_138 = 0 ;
V_2 -> V_134 . V_145 = 0 ;
V_2 -> V_119 = V_185 ;
F_56 ( V_2 ) ;
V_120 = F_134 ( V_2 ) ;
if ( V_120 < 0 ) {
F_150 ( & V_2 -> V_331 ) ;
return V_120 ;
}
return 0 ;
}
void F_151 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
F_142 ( & V_2 -> V_310 ) ;
F_143 ( & V_2 -> V_202 . V_203 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_132 ) ;
F_79 ( & V_2 -> V_94 . V_116 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_117 ) ;
if ( V_2 -> V_151 . V_66 != NULL )
F_26 ( V_4 -> V_5 , V_2 -> V_151 . V_153 * 4 , V_2 -> V_151 . V_66 ,
V_2 -> V_151 . V_105 ) ;
F_150 ( & V_2 -> V_331 ) ;
}
