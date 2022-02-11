static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 type = V_4 -> V_7 -> V_8 -> type ;
T_1 V_9 = V_4 -> V_7 -> V_9 ;
F_2 ( V_2 , L_1 ,
V_6 -> V_10 / 1000000 ) ;
F_2 ( V_2 , L_2 , V_6 -> V_11 ) ;
F_2 ( V_2 , L_3 , V_6 -> V_12 ) ;
F_2 ( V_2 , L_4 , V_6 -> V_13 ) ;
F_2 ( V_2 , L_5 , V_6 -> V_14 ) ;
if ( V_9 == V_15 ) {
F_2 ( V_2 , L_6 ,
V_6 -> V_16 ) ;
F_2 ( V_2 , L_7 ,
V_6 -> V_17 ) ;
} else if ( V_9 == V_18 ) {
F_2 ( V_2 , L_8 ,
V_6 -> V_19 ) ;
F_2 ( V_2 , L_9 ,
V_6 -> V_20 ) ;
}
if ( type == V_21 || type == V_22 ) {
F_2 ( V_2 , L_10 ,
V_6 -> V_23 ) ;
F_2 ( V_2 , L_11 ,
V_6 -> V_24 ) ;
F_2 ( V_2 , L_12 ,
V_6 -> V_25 ) ;
}
}
static int F_3 ( struct V_1 * V_2 , void * V_26 )
{
struct V_3 * V_4 = V_2 -> V_27 ;
struct V_5 * * V_28 ;
int V_29 ;
if ( V_4 -> V_30 )
V_28 = V_31 -> V_28 ;
else
V_28 = V_4 -> V_28 ;
for ( V_29 = 0 ; V_29 < V_32 && V_28 [ V_29 ] ; V_29 ++ ) {
F_1 ( V_2 , V_4 , V_28 [ V_29 ] ) ;
F_2 ( V_2 , L_13 ) ;
}
return 0 ;
}
static int F_4 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_5 ( V_34 , F_3 , V_33 -> V_35 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_26 )
{
struct V_3 * V_4 = V_2 -> V_27 ;
F_2 ( V_2 , L_14 , V_4 -> V_36 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_5 ( V_34 , F_6 , V_33 -> V_35 ) ;
}
static int T_2 F_8 ( struct V_3 * V_4 )
{
struct V_37 * V_37 ;
int V_38 ;
V_37 = F_9 ( F_10 ( V_4 -> V_39 ) , NULL ) ;
if ( ! V_37 ) {
V_38 = - V_40 ;
goto V_41;
}
V_4 -> V_42 = V_37 ;
V_37 = F_11 ( L_15 , V_43 ,
V_4 -> V_42 , V_4 , & V_44 ) ;
if ( ! V_37 ) {
V_38 = - V_40 ;
goto V_45;
}
V_37 = F_11 ( L_16 , V_43 ,
V_4 -> V_42 , V_4 , & V_46 ) ;
if ( ! V_37 ) {
V_38 = - V_40 ;
goto V_45;
}
return 0 ;
V_45:
F_12 ( V_4 -> V_42 ) ;
V_41:
return V_38 ;
}
static void T_3 F_13 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
static inline int T_2 F_8 ( struct V_3 * V_4 )
{
return 0 ;
}
static inline void T_3 F_13 ( struct V_3 * V_4 )
{
}
static void F_14 ( T_1 V_10 )
{
V_47 = ( T_1 ) F_15 ( 1000000000000ull , V_10 ) ;
}
static T_1 F_16 ( struct V_3 * V_4 )
{
T_1 V_48 ;
void T_4 * V_49 = V_4 -> V_49 ;
V_48 = ( F_17 ( V_49 + V_50 ) & V_51 )
>> V_52 ;
V_48 = V_48 == 0 ? 32 : 16 ;
return V_48 ;
}
static T_1 F_18 ( struct V_3 * V_4 )
{
T_1 V_53 ;
void T_4 * V_49 = V_4 -> V_49 ;
V_53 = ( F_17 ( V_49 + V_50 ) & V_54 ) >> V_55 ;
return V_53 ;
}
static void F_19 ( struct V_3 * V_4 , T_5 V_56 )
{
T_1 V_57 ;
void T_4 * V_49 = V_4 -> V_49 ;
V_57 = F_17 ( V_49 + V_58 ) ;
V_57 &= ~ V_59 ;
V_57 |= ( V_56 << V_60 ) ;
F_20 ( V_57 , V_49 + V_58 ) ;
}
static void F_21 ( void )
{
struct V_3 * V_4 ;
F_22 (emif, &device_list, node) {
if ( V_4 -> V_56 == V_61 )
F_19 ( V_4 , V_62 ) ;
}
F_22 (emif, &device_list, node) {
if ( V_4 -> V_56 == V_61 )
F_19 ( V_4 , V_61 ) ;
}
}
static const struct V_63 * F_23 (
const struct V_64 * V_8 )
{
T_1 V_65 , type , V_66 ;
type = V_8 -> type ;
V_66 = V_8 -> V_66 ;
switch ( type ) {
case V_22 :
V_65 = V_66 - 1 ;
break;
case V_21 :
switch ( V_66 ) {
case V_67 :
case V_68 :
V_65 = V_66 + 3 ;
break;
default:
V_65 = V_66 - 1 ;
}
break;
default:
return NULL ;
}
return & V_69 [ V_65 ] ;
}
static const struct V_70 * F_24 ( struct V_3 * V_4 ,
T_1 V_10 )
{
T_1 V_29 , V_71 , V_72 , V_73 ;
const struct V_70 * V_74 = NULL ;
const struct V_70 * V_75 = V_4 -> V_7 -> V_74 ;
struct V_76 * V_39 = V_4 -> V_39 ;
V_73 = 1000000000 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_7 -> V_77 ; V_29 ++ ) {
V_72 = V_75 [ V_29 ] . V_78 ;
V_71 = V_75 [ V_29 ] . V_79 ;
if ( ( V_10 >= V_71 ) && ( V_10 <= V_72 ) && ( V_72 < V_73 ) ) {
V_73 = V_72 ;
V_74 = & V_75 [ V_29 ] ;
}
}
if ( ! V_74 )
F_25 ( V_39 , L_17 ,
V_80 , V_10 ) ;
F_26 ( V_39 , L_18 ,
V_80 , V_10 , V_73 ) ;
return V_74 ;
}
static T_1 F_27 ( T_1 V_10 ,
const struct V_63 * V_81 )
{
T_1 V_11 = 0 , V_82 = 0 , V_83 , V_84 ;
V_83 = V_10 / 1000 ;
V_84 = V_81 -> V_85 / 100 ;
V_82 = V_84 * V_83 / 10000 ;
V_11 |= V_82 << V_86 ;
return V_11 ;
}
static T_1 F_28 ( const struct V_70 * V_74 ,
const struct V_87 * V_88 ,
const struct V_63 * V_81 )
{
T_1 V_89 = 0 , V_82 = 0 ;
V_82 = V_72 ( V_88 -> V_90 , F_29 ( V_74 -> V_90 , V_47 ) ) - 1 ;
V_89 |= V_82 << V_91 ;
if ( V_81 -> V_92 == V_93 )
V_82 = F_29 ( V_74 -> V_94 , V_47 * 4 ) ;
else
V_82 = V_72 ( V_88 -> V_95 , F_29 ( V_74 -> V_95 , V_47 ) ) ;
V_89 |= ( V_82 - 1 ) << V_96 ;
V_82 = F_29 ( V_74 -> V_97 + V_74 -> V_98 , V_47 ) - 1 ;
V_89 |= V_82 << V_99 ;
V_82 = V_72 ( V_88 -> V_100 , F_29 ( V_74 -> V_97 , V_47 ) ) ;
V_89 |= ( V_82 - 1 ) << V_101 ;
V_82 = V_72 ( V_88 -> V_102 , F_29 ( V_74 -> V_102 , V_47 ) ) - 1 ;
V_89 |= V_82 << V_103 ;
V_82 = V_72 ( V_88 -> V_104 , F_29 ( V_74 -> V_104 , V_47 ) ) - 1 ;
V_89 |= V_82 << V_105 ;
V_82 = V_72 ( V_88 -> V_98 , F_29 ( V_74 -> V_98 , V_47 ) ) - 1 ;
V_89 |= V_82 << V_106 ;
return V_89 ;
}
static T_1 F_30 ( const struct V_70 * V_74 ,
const struct V_87 * V_88 ,
const struct V_63 * V_81 )
{
T_1 V_89 = 0 , V_82 = 0 ;
V_82 = V_72 ( V_88 -> V_90 , F_29 ( V_74 -> V_90 , V_47 ) ) - 1 ;
V_89 = V_82 << V_91 ;
if ( V_81 -> V_92 == V_93 ) {
V_82 = F_29 ( V_74 -> V_94 + 7500 , 4 * V_47 ) - 1 ;
} else {
V_82 = F_29 ( V_74 -> V_95 + 1875 , V_47 ) ;
V_82 = V_72 ( V_88 -> V_95 , V_82 ) - 1 ;
}
V_89 |= V_82 << V_96 ;
V_82 = F_29 ( V_74 -> V_97 + V_74 -> V_98 + 1875 , V_47 ) ;
V_89 |= ( V_82 - 1 ) << V_99 ;
V_82 = F_29 ( V_74 -> V_97 + 1875 , V_47 ) ;
V_82 = V_72 ( V_88 -> V_100 , V_82 ) - 1 ;
V_89 |= V_82 << V_101 ;
V_82 = V_72 ( V_88 -> V_102 , F_29 ( V_74 -> V_102 , V_47 ) ) - 1 ;
V_89 |= V_82 << V_103 ;
V_82 = V_72 ( V_88 -> V_104 , F_29 ( V_74 -> V_104 + 1875 , V_47 ) ) ;
V_89 |= ( V_82 - 1 ) << V_105 ;
V_82 = V_72 ( V_88 -> V_98 , F_29 ( V_74 -> V_98 + 1875 , V_47 ) ) ;
V_89 |= ( V_82 - 1 ) << V_106 ;
return V_89 ;
}
static T_1 F_31 ( const struct V_70 * V_74 ,
const struct V_87 * V_88 ,
const struct V_63 * V_81 ,
T_1 type )
{
T_1 V_107 = 0 , V_82 = 0 ;
V_82 = V_88 -> V_108 - 1 ;
V_107 |= V_82 << V_109 ;
V_82 = V_72 ( V_88 -> V_110 , F_29 ( V_74 -> V_110 , V_47 ) ) - 1 ;
V_107 |= V_82 << V_111 ;
V_82 = F_29 ( V_81 -> V_112 + 10000 , V_47 ) - 1 ;
V_107 |= V_82 << V_113 ;
V_107 |= V_82 << V_114 ;
V_82 = V_72 ( V_88 -> V_115 , F_29 ( V_74 -> V_115 , V_47 ) ) - 1 ;
V_107 |= V_82 << V_116 ;
return V_107 ;
}
static T_1 F_32 ( const struct V_70 * V_74 ,
const struct V_87 * V_88 ,
const struct V_63 * V_81 ,
T_1 type , T_1 V_9 , T_1 V_117 )
{
T_1 V_118 = 0 , V_82 = 0 , V_119 ;
V_82 = V_74 -> V_120 / V_81 -> V_85 - 1 ;
V_82 = V_82 > 0xF ? 0xF : V_82 ;
V_118 |= V_82 << V_121 ;
V_82 = F_29 ( V_81 -> V_112 , V_47 ) - 1 ;
V_118 |= V_82 << V_122 ;
V_119 = ( V_117 == V_123 ) ?
V_74 -> V_124 : V_74 -> V_125 ;
if ( V_9 == V_18 )
V_82 = F_29 ( V_119 + 1000 , V_47 ) - 1 ;
else
V_82 = F_29 ( V_119 , V_47 ) - 1 ;
V_118 |= V_82 << V_126 ;
V_82 = F_29 ( V_74 -> V_127 , V_47 ) - 1 ;
V_118 |= V_82 << V_128 ;
V_82 = F_29 ( V_74 -> V_129 , V_47 ) ;
V_82 = V_72 ( V_88 -> V_129 , V_82 ) - 1 ;
V_118 |= V_82 << V_130 ;
if ( V_9 == V_18 ) {
V_118 |= ( V_131 - 1 ) << V_132 ;
V_82 = F_29 ( V_133 , 128 ) - 1 ;
V_118 |= V_82 << V_134 ;
}
return V_118 ;
}
static T_1 F_33 ( const struct V_63 * V_81 ,
bool V_135 , bool V_136 )
{
T_1 V_137 = 0 , V_82 = 0 ;
V_82 = V_138 * 1000 / V_81 -> V_85 ;
V_137 |= V_82 << V_139 ;
V_82 = F_29 ( V_140 , V_141 ) - 1 ;
V_137 |= V_82 << V_142 ;
V_82 = F_29 ( V_143 , V_140 ) - 1 ;
V_137 |= V_82 << V_144 ;
V_137 |= V_145 << V_146 ;
if ( V_136 )
V_137 |= V_147 << V_148 ;
else
V_137 |= V_149 << V_148 ;
V_137 |= V_150 ;
V_82 = V_135 ? 1 : 0 ;
V_137 |= V_82 << V_151 ;
return V_137 ;
}
static T_1 F_34 ( const struct V_63 * V_81 ,
const struct V_152 * V_153 , bool V_135 ,
T_1 V_154 , T_1 V_155 )
{
T_1 V_156 = 0 , V_157 , V_158 ;
if ( V_153 && ( V_153 -> V_159 &
V_160 ) )
V_157 = V_153 -> V_161 ;
else
V_157 = V_162 ;
V_157 *= 1000000 ;
V_157 /= V_81 -> V_85 ;
V_156 |= ( V_157 << V_163 ) ;
V_155 = F_35 ( V_155 ) - 1 ;
V_158 = V_155 - V_154 ;
V_156 |= V_158 << V_164 ;
V_156 |= ( V_154 - 2 ) << V_165 ;
V_156 |= 1 << V_166 ;
V_156 |= 1 << V_167 ;
V_156 |= ( V_135 ? 1 : 0 ) << V_168 ;
return V_156 ;
}
static T_1 F_36 ( T_5 V_169 )
{
T_1 V_170 = 0 , V_82 = 0 ;
if ( V_169 )
V_82 = V_171 / V_47 / 64 - 1 ;
else
V_82 = 0x1FF ;
V_170 |= V_82 << V_172 ;
V_170 |= V_173 << V_174 ;
return V_170 ;
}
static T_1 F_37 ( T_5 V_169 )
{
T_1 V_175 = 0 , V_82 = 0 ;
if ( V_169 == V_176 )
V_82 = V_177 / V_47 / 16 - 1 ;
else
V_82 = 0 ;
V_175 |= V_82 << V_172 ;
V_175 |= V_178 << V_174 ;
return V_175 ;
}
static T_1 F_38 ( const struct V_70 * V_74 ,
T_1 V_10 , T_5 V_179 )
{
T_1 V_180 = V_181 , V_82 = 0 ;
V_82 = V_179 + F_29 ( V_74 -> V_125 , V_47 ) - 1 ;
V_180 |= V_82 << V_182 ;
if ( V_10 <= 100000000 )
V_82 = V_183 ;
else if ( V_10 <= 200000000 )
V_82 = V_184 ;
else
V_82 = V_185 ;
V_180 |= V_82 << V_186 ;
return V_180 ;
}
static T_1 F_39 ( T_1 V_10 , T_5 V_53 )
{
T_1 V_180 = V_187 , V_188 ;
if ( V_10 >= 265000000 && V_10 < 267000000 )
V_188 = 0 ;
else
V_188 = 1 ;
V_180 |= V_188 << V_189 ;
V_180 |= ( ( V_53 + F_29 ( V_190 ,
V_47 ) - 1 ) << V_191 ) ;
return V_180 ;
}
static T_1 F_40 ( void )
{
T_1 V_192 ;
V_192 = F_41 (
V_193 * 256 , V_47 ) ;
return V_192 | V_192 << 11 |
V_192 << 22 ;
}
static T_1 F_42 ( void )
{
T_1 V_192 ;
V_192 = F_41 (
V_193 * 256 , V_47 ) ;
return V_192 >> 10 | V_192 << 1 |
V_192 << 12 | V_192 << 23 ;
}
static T_1 F_43 ( void )
{
T_1 V_192 ;
V_192 = F_41 (
V_193 * 256 , V_47 ) ;
return V_192 >> 9 | V_192 << 2 |
V_192 << 13 ;
}
static T_1 F_44 ( T_1 V_10 , struct V_3 * V_4 , T_1 V_9 )
{
T_1 V_194 = 0 , V_195 ;
T_1 V_56 = V_61 ;
T_1 V_196 = V_197 ;
T_1 V_198 = V_199 ;
T_1 V_200 = V_201 ;
struct V_152 * V_202 = V_4 -> V_7 -> V_153 ;
if ( V_202 && ( V_202 -> V_159 & V_203 ) ) {
V_56 = V_202 -> V_56 ;
V_196 = V_202 -> V_204 ;
V_198 = V_202 -> V_205 ;
V_200 = V_202 -> V_206 ;
}
V_195 = V_10 >= V_200 ? V_196 : V_198 ;
if ( V_195 < 16 ) {
V_195 = 0 ;
} else {
V_195 = F_35 ( V_195 ) - 3 ;
if ( V_195 & ( V_195 - 1 ) )
V_195 ++ ;
}
switch ( V_56 ) {
case V_207 :
V_194 = ( V_195 << V_208 ) |
V_209 | V_210 ;
break;
case V_61 :
if ( V_195 < 6 )
V_195 = 6 ;
V_194 = ( V_195 << V_211 ) |
V_212 | V_210 ;
break;
case V_213 :
V_194 = ( V_195 << V_214 ) |
V_212 | V_209 ;
break;
case V_62 :
default:
V_194 = V_212 |
V_210 | V_209 ;
}
if ( V_9 == V_18 )
V_194 &= ~ V_212 ;
V_194 |= V_56 << V_60 ;
return V_194 ;
}
static void F_45 ( struct V_3 * V_4 )
{
T_1 V_57 , V_36 ;
void T_4 * V_49 ;
V_49 = V_4 -> V_49 ;
F_20 ( V_215 , V_49 + V_216 ) ;
V_36 = F_17 ( V_49 + V_217 ) ;
V_36 = ( V_36 & V_218 ) >>
V_219 ;
if ( V_4 -> V_7 -> V_8 -> V_135 ) {
F_20 ( V_215 | V_220 , V_49 + V_216 ) ;
V_57 = F_17 ( V_49 + V_217 ) ;
V_57 = ( V_57 & V_218 )
>> V_219 ;
V_36 = V_72 ( V_57 , V_36 ) ;
}
if ( F_46 ( V_36 < V_221 ) )
V_36 = V_221 ;
if ( F_47 ( V_36 != V_222 ) )
V_4 -> V_36 = V_36 ;
}
static void F_48 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_20 ( V_6 -> V_13 , V_49 + V_223 ) ;
F_20 ( V_6 -> V_224 , V_49 + V_225 ) ;
if ( V_4 -> V_7 -> V_9 != V_18 )
return;
F_20 ( V_6 -> V_226 , V_49 + V_227 ) ;
F_20 ( V_6 -> V_228 , V_49 + V_229 ) ;
F_20 ( V_6 -> V_230 , V_49 + V_231 ) ;
}
static void F_49 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_232 )
{
T_1 V_233 ;
void T_4 * V_49 = V_4 -> V_49 ;
if ( V_232 == V_176 )
V_233 = V_6 -> V_20 ;
else
V_233 = V_6 -> V_19 ;
F_20 ( V_233 , V_49 + V_234 ) ;
}
static void F_50 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_89 , V_118 , V_235 , type ;
void T_4 * V_49 = V_4 -> V_49 ;
T_1 V_236 ;
type = V_4 -> V_7 -> V_8 -> type ;
V_89 = V_6 -> V_12 ;
V_118 = V_6 -> V_14 ;
V_235 = V_6 -> V_11 ;
if ( type != V_21 && type != V_22 )
goto V_237;
V_236 = V_4 -> V_36 ;
if ( V_236 == V_238 ) {
V_235 = V_6 -> V_23 ;
} else if ( V_236 == V_239 ) {
V_89 = V_6 -> V_24 ;
V_118 = V_6 -> V_25 ;
V_235 = V_6 -> V_23 ;
}
V_237:
F_20 ( V_89 , V_49 + V_240 ) ;
F_20 ( V_118 , V_49 + V_241 ) ;
F_20 ( V_235 , V_49 + V_242 ) ;
}
static T_6 F_51 ( void T_4 * V_49 , struct V_3 * V_4 )
{
T_1 V_243 ;
T_6 V_38 = V_244 ;
F_52 ( & V_245 , V_246 ) ;
V_243 = V_4 -> V_36 ;
F_45 ( V_4 ) ;
if ( F_46 ( V_4 -> V_36 == V_243 ) ) {
goto V_237;
} else if ( ! V_4 -> V_247 ) {
F_25 ( V_4 -> V_39 , L_19 ) ;
goto V_237;
}
if ( V_4 -> V_36 < V_243 ||
V_4 -> V_36 == V_248 ) {
V_38 = V_249 ;
} else {
F_50 ( V_4 , V_4 -> V_247 ) ;
F_21 () ;
}
V_237:
F_53 ( & V_245 , V_246 ) ;
return V_38 ;
}
static T_6 F_54 ( int V_250 , void * V_251 )
{
T_1 V_252 ;
struct V_3 * V_4 = V_251 ;
void T_4 * V_49 = V_4 -> V_49 ;
struct V_76 * V_39 = V_4 -> V_39 ;
T_6 V_38 = V_244 ;
V_252 = F_17 ( V_49 + V_253 ) ;
F_20 ( V_252 , V_49 + V_253 ) ;
if ( V_252 & V_254 )
V_38 = F_51 ( V_49 , V_4 ) ;
if ( V_252 & V_255 )
F_25 ( V_39 , L_20 , V_252 ) ;
if ( V_4 -> V_7 -> V_256 & V_257 ) {
V_252 = F_17 ( V_49 + V_258 ) ;
F_20 ( V_252 , V_49 + V_258 ) ;
if ( V_252 & V_259 )
F_25 ( V_39 , L_21 ,
V_252 ) ;
}
return V_38 ;
}
static T_6 F_55 ( int V_250 , void * V_251 )
{
struct V_3 * V_4 = V_251 ;
if ( V_4 -> V_36 == V_248 ) {
F_56 ( V_4 -> V_39 , L_22 ) ;
F_57 () ;
return V_244 ;
}
F_52 ( & V_245 , V_246 ) ;
if ( V_4 -> V_247 ) {
F_50 ( V_4 , V_4 -> V_247 ) ;
F_21 () ;
} else {
F_25 ( V_4 -> V_39 , L_19 ) ;
}
F_53 ( & V_245 , V_246 ) ;
return V_244 ;
}
static void F_58 ( struct V_3 * V_4 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_20 ( F_17 ( V_49 + V_253 ) ,
V_49 + V_253 ) ;
if ( V_4 -> V_7 -> V_256 & V_257 )
F_20 ( F_17 ( V_49 + V_258 ) ,
V_49 + V_258 ) ;
}
static void F_59 ( struct V_3 * V_4 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_20 ( F_17 ( V_49 + V_260 ) ,
V_49 + V_261 ) ;
if ( V_4 -> V_7 -> V_256 & V_257 )
F_20 ( F_17 ( V_49 + V_262 ) ,
V_49 + V_263 ) ;
F_58 ( V_4 ) ;
}
static int T_2 F_60 ( struct V_3 * V_4 , T_1 V_250 )
{
T_1 V_252 , type ;
void T_4 * V_49 = V_4 -> V_49 ;
type = V_4 -> V_7 -> V_8 -> type ;
F_58 ( V_4 ) ;
V_252 = V_264 ;
if ( type == V_21 || type == V_22 )
V_252 |= V_265 ;
F_20 ( V_252 , V_49 + V_260 ) ;
if ( V_4 -> V_7 -> V_256 & V_257 ) {
V_252 = V_266 ;
F_20 ( V_252 , V_49 + V_262 ) ;
}
return F_61 ( V_4 -> V_39 , V_250 ,
F_54 ,
F_55 ,
0 , F_10 ( V_4 -> V_39 ) ,
V_4 ) ;
}
static void T_2 F_62 ( struct V_3 * V_4 )
{
T_1 V_194 , V_137 , V_267 ;
void T_4 * V_49 = V_4 -> V_49 ;
const struct V_63 * V_81 ;
const struct V_64 * V_8 ;
V_8 = V_4 -> V_7 -> V_8 ;
V_81 = F_23 ( V_8 ) ;
V_194 = F_44 ( 1000000000 , V_4 ,
V_4 -> V_7 -> V_9 ) ;
V_4 -> V_56 = ( V_194 & V_59 ) >> V_60 ;
F_20 ( V_194 , V_49 + V_58 ) ;
V_137 = F_33 ( V_81 , V_8 -> V_135 ,
V_8 -> V_136 ) ;
F_20 ( V_137 , V_49 + V_268 ) ;
F_45 ( V_4 ) ;
if ( V_4 -> V_36 == V_248 )
F_56 ( V_4 -> V_39 , L_22 ) ;
V_267 = F_34 ( V_81 ,
V_4 -> V_7 -> V_153 , V_8 -> V_135 ,
V_8 -> V_269 , F_16 ( V_4 ) ) ;
F_20 ( V_267 , V_49 + V_270 ) ;
if ( V_4 -> V_7 -> V_271 != V_272 )
return;
F_20 ( V_273 , V_49 + V_274 ) ;
F_20 ( V_275 , V_49 + V_276 ) ;
F_20 ( V_277 , V_49 + V_278 ) ;
F_20 ( V_279 , V_49 + V_280 ) ;
F_20 ( V_281 , V_49 + V_282 ) ;
F_20 ( V_283 , V_49 + V_284 ) ;
F_20 ( V_285 , V_49 + V_286 ) ;
F_20 ( V_287 , V_49 + V_288 ) ;
F_20 ( V_289 , V_49 + V_290 ) ;
F_20 ( V_291 , V_49 + V_292 ) ;
F_20 ( V_293 , V_49 + V_294 ) ;
F_20 ( V_295 , V_49 + V_296 ) ;
F_20 ( V_297 , V_49 + V_298 ) ;
F_20 ( V_299 , V_49 + V_300 ) ;
F_20 ( V_301 , V_49 + V_302 ) ;
F_20 ( V_303 , V_49 + V_304 ) ;
F_20 ( V_305 , V_49 + V_306 ) ;
F_20 ( V_307 , V_49 + V_308 ) ;
F_20 ( V_309 , V_49 + V_310 ) ;
F_20 ( V_311 , V_49 + V_312 ) ;
F_20 ( V_313 , V_49 + V_314 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_315 * V_316 = V_4 -> V_7 ;
V_316 -> V_74 = V_317 ;
V_316 -> V_77 = F_64 ( V_317 ) ;
F_65 ( V_4 -> V_39 , L_23 , V_80 ) ;
}
static int F_66 ( T_1 type , T_1 V_66 , T_1 V_269 , T_1 V_271 ,
T_1 V_9 , struct V_76 * V_39 )
{
int V_318 ;
V_318 = ( type == V_22 ||
type == V_21 )
&& ( V_66 >= V_319
&& V_66 <= V_320 )
&& ( V_269 >= V_321
&& V_269 <= V_322 ) ;
switch ( V_9 ) {
case V_15 :
V_318 = V_318 && ( V_271 == V_323 ) ;
break;
case V_18 :
V_318 = V_318 && ( V_271 == V_272 ) ;
break;
default:
V_318 = 0 ;
}
if ( ! V_318 )
F_25 ( V_39 , L_24 , V_80 ) ;
return V_318 ;
}
static int F_67 ( struct V_152 * V_202 ,
struct V_76 * V_39 )
{
int V_318 = 1 ;
if ( ( V_202 -> V_159 & V_203 ) &&
( V_202 -> V_56 != V_62 ) )
V_318 = V_202 -> V_206 &&
V_202 -> V_204 &&
V_202 -> V_205 ;
if ( V_202 -> V_159 & V_160 )
V_318 = V_318 && V_202 -> V_161 ;
if ( ! V_318 )
F_65 ( V_39 , L_25 , V_80 ) ;
return V_318 ;
}
static void T_2 F_68 ( struct V_324 * V_325 ,
struct V_3 * V_4 )
{
struct V_152 * V_202 = NULL ;
int V_326 ;
const int * V_56 , * V_327 ;
V_56 = F_69 ( V_325 , L_26 , & V_326 ) ;
V_327 = F_69 ( V_325 , L_27 , & V_326 ) ;
if ( V_56 || V_327 )
V_202 = F_70 ( V_4 -> V_39 , sizeof( * V_202 ) ,
V_328 ) ;
if ( ! V_202 )
return;
if ( V_56 ) {
V_202 -> V_159 |= V_203 ;
V_202 -> V_56 = * V_56 ;
F_71 ( V_325 ,
L_28 ,
& V_202 -> V_204 ) ;
F_71 ( V_325 ,
L_29 ,
& V_202 -> V_205 ) ;
F_71 ( V_325 ,
L_30 ,
& V_202 -> V_206 ) ;
}
if ( V_327 ) {
V_202 -> V_159 |=
V_160 ;
V_202 -> V_161 = * V_327 ;
}
if ( ! F_67 ( V_202 , V_4 -> V_39 ) ) {
F_72 ( V_4 -> V_39 , V_202 ) ;
return;
}
V_4 -> V_7 -> V_153 = V_202 ;
}
static void T_2 F_73 ( struct V_324 * V_325 ,
struct V_324 * V_329 ,
struct V_64 * V_330 )
{
T_1 V_66 = 0 , V_269 = 0 ;
int V_326 ;
if ( F_74 ( V_325 , L_31 , & V_326 ) )
V_330 -> V_135 = true ;
if ( F_74 ( V_325 , L_32 , & V_326 ) )
V_330 -> V_136 = true ;
if ( F_75 ( V_329 , L_33 ) )
V_330 -> type = V_22 ;
else if ( F_75 ( V_329 , L_34 ) )
V_330 -> type = V_21 ;
F_71 ( V_329 , L_35 , & V_66 ) ;
F_71 ( V_329 , L_36 , & V_269 ) ;
if ( V_66 & ( V_66 - 1 ) )
V_330 -> V_66 = 0 ;
else
V_330 -> V_66 = F_35 ( V_66 ) - 5 ;
if ( V_269 & ( V_269 - 1 ) )
V_330 -> V_269 = 0 ;
else
V_330 -> V_269 = F_35 ( V_269 ) - 1 ;
}
static struct V_3 * T_2 F_76 (
struct V_324 * V_325 , struct V_76 * V_39 )
{
struct V_3 * V_4 = NULL ;
struct V_64 * V_330 = NULL ;
struct V_315 * V_316 = NULL ;
struct V_324 * V_329 ;
int V_326 ;
V_329 = F_77 ( V_325 , L_37 , 0 ) ;
if ( ! V_329 )
goto error;
V_4 = F_70 ( V_39 , sizeof( struct V_3 ) , V_328 ) ;
V_316 = F_70 ( V_39 , sizeof( * V_316 ) , V_328 ) ;
V_330 = F_70 ( V_39 , sizeof( * V_330 ) , V_328 ) ;
if ( ! V_4 || ! V_316 || ! V_330 ) {
F_25 ( V_39 , L_38 ,
V_80 ) ;
goto error;
}
V_4 -> V_7 = V_316 ;
V_316 -> V_8 = V_330 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_329 = V_329 ;
V_4 -> V_36 = V_221 ;
if ( F_75 ( V_325 , L_39 ) )
V_4 -> V_7 -> V_9 = V_15 ;
else if ( F_75 ( V_325 , L_40 ) )
V_4 -> V_7 -> V_9 = V_18 ;
F_71 ( V_325 , L_41 , & V_316 -> V_271 ) ;
if ( F_74 ( V_325 , L_42 , & V_326 ) )
V_316 -> V_256 |= V_257 ;
F_73 ( V_325 , V_329 , V_330 ) ;
if ( ! F_66 ( V_316 -> V_8 -> type , V_316 -> V_8 -> V_66 ,
V_316 -> V_8 -> V_269 , V_316 -> V_271 , V_316 -> V_9 ,
V_4 -> V_39 ) ) {
F_25 ( V_39 , L_43 , V_80 ) ;
goto error;
}
if ( V_31 && V_31 -> V_329 == V_329 ) {
V_4 -> V_30 = true ;
goto V_237;
} else if ( V_31 ) {
F_65 ( V_4 -> V_39 , L_44 ,
V_80 ) ;
}
F_68 ( V_325 , V_4 ) ;
V_4 -> V_7 -> V_74 = F_78 ( V_329 , V_4 -> V_39 ,
V_4 -> V_7 -> V_8 -> type ,
& V_4 -> V_7 -> V_77 ) ;
V_4 -> V_7 -> V_88 = F_79 ( V_329 , V_4 -> V_39 ) ;
goto V_237;
error:
return NULL ;
V_237:
return V_4 ;
}
static struct V_3 * T_2 F_76 (
struct V_324 * V_325 , struct V_76 * V_39 )
{
return NULL ;
}
static struct V_3 * T_2 F_80 (
struct V_331 * V_332 )
{
T_1 V_333 ;
struct V_3 * V_4 = NULL ;
struct V_64 * V_330 ;
struct V_152 * V_202 ;
struct V_315 * V_316 ;
struct V_76 * V_39 ;
void * V_57 ;
V_316 = V_332 -> V_39 . V_334 ;
V_39 = & V_332 -> V_39 ;
if ( ! ( V_316 && V_316 -> V_8 && F_66 ( V_316 -> V_8 -> type ,
V_316 -> V_8 -> V_66 , V_316 -> V_8 -> V_269 ,
V_316 -> V_271 , V_316 -> V_9 , V_39 ) ) ) {
F_25 ( V_39 , L_45 , V_80 ) ;
goto error;
}
V_4 = F_70 ( V_39 , sizeof( * V_4 ) , V_328 ) ;
V_57 = F_70 ( V_39 , sizeof( * V_316 ) , V_328 ) ;
V_330 = F_70 ( V_39 , sizeof( * V_330 ) , V_328 ) ;
if ( ! V_4 || ! V_316 || ! V_330 ) {
F_25 ( V_39 , L_46 , V_80 , __LINE__ ) ;
goto error;
}
memcpy ( V_57 , V_316 , sizeof( * V_316 ) ) ;
V_316 = V_57 ;
memcpy ( V_330 , V_316 -> V_8 , sizeof( * V_330 ) ) ;
V_316 -> V_8 = V_330 ;
V_4 -> V_7 = V_316 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_36 = V_221 ;
V_4 -> V_30 = V_31 && ( memcmp ( V_330 ,
V_31 -> V_7 -> V_8 ,
sizeof( struct V_64 ) ) == 0 ) ;
if ( V_4 -> V_30 ) {
V_316 -> V_74 = NULL ;
V_316 -> V_88 = NULL ;
goto V_237;
} else if ( V_31 ) {
F_65 ( V_4 -> V_39 , L_44 ,
V_80 ) ;
}
V_202 = V_316 -> V_153 ;
if ( V_202 && F_67 ( V_202 , V_39 ) ) {
V_57 = F_70 ( V_39 , sizeof( * V_202 ) , V_328 ) ;
if ( V_57 )
memcpy ( V_57 , V_202 , sizeof( * V_202 ) ) ;
else
F_65 ( V_39 , L_46 , V_80 ,
__LINE__ ) ;
V_316 -> V_153 = V_57 ;
}
V_333 = sizeof( struct V_70 ) * V_316 -> V_77 ;
if ( V_316 -> V_74 ) {
V_57 = F_70 ( V_39 , V_333 , V_328 ) ;
if ( V_57 ) {
memcpy ( V_57 , V_316 -> V_74 , sizeof( * V_316 -> V_74 ) ) ;
V_316 -> V_74 = V_57 ;
} else {
F_65 ( V_39 , L_46 , V_80 ,
__LINE__ ) ;
F_63 ( V_4 ) ;
}
} else {
F_63 ( V_4 ) ;
}
if ( V_316 -> V_88 ) {
V_57 = F_70 ( V_39 , sizeof( * V_316 -> V_88 ) , V_328 ) ;
if ( V_57 ) {
memcpy ( V_57 , V_316 -> V_88 , sizeof( * V_316 -> V_88 ) ) ;
V_316 -> V_88 = V_57 ;
} else {
F_65 ( V_39 , L_46 , V_80 ,
__LINE__ ) ;
V_316 -> V_88 = & V_335 ;
}
} else {
V_316 -> V_88 = & V_335 ;
}
V_237:
return V_4 ;
error:
return NULL ;
}
static int T_2 F_81 ( struct V_331 * V_332 )
{
struct V_3 * V_4 ;
struct V_336 * V_337 ;
int V_250 ;
if ( V_332 -> V_39 . V_338 )
V_4 = F_76 ( V_332 -> V_39 . V_338 , & V_332 -> V_39 ) ;
else
V_4 = F_80 ( V_332 ) ;
if ( ! V_4 ) {
F_82 ( L_47 , V_80 ) ;
goto error;
}
F_83 ( & V_4 -> V_339 , & V_340 ) ;
V_4 -> V_81 = F_23 ( V_4 -> V_7 -> V_8 ) ;
V_4 -> V_39 = & V_332 -> V_39 ;
F_84 ( V_332 , V_4 ) ;
V_337 = F_85 ( V_332 , V_341 , 0 ) ;
if ( ! V_337 ) {
F_25 ( V_4 -> V_39 , L_48 ,
V_80 ) ;
goto error;
}
V_4 -> V_49 = F_86 ( V_4 -> V_39 , V_337 ) ;
if ( F_87 ( V_4 -> V_49 ) )
goto error;
V_250 = F_88 ( V_332 , 0 ) ;
if ( V_250 < 0 ) {
F_25 ( V_4 -> V_39 , L_49 ,
V_80 , V_250 ) ;
goto error;
}
F_62 ( V_4 ) ;
F_8 ( V_4 ) ;
F_59 ( V_4 ) ;
F_60 ( V_4 , V_250 ) ;
if ( ! V_31 ) {
V_31 = V_4 ;
F_89 ( & V_245 ) ;
}
V_330 ( & V_332 -> V_39 , L_50 ,
V_80 , V_4 -> V_49 , V_250 ) ;
return 0 ;
error:
return - V_342 ;
}
static int T_3 F_90 ( struct V_331 * V_332 )
{
struct V_3 * V_4 = F_91 ( V_332 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static void F_92 ( struct V_331 * V_332 )
{
struct V_3 * V_4 = F_91 ( V_332 ) ;
F_59 ( V_4 ) ;
}
static int F_93 ( struct V_3 * V_4 , T_1 V_10 ,
struct V_5 * V_6 )
{
T_1 V_135 , V_9 , V_271 ;
T_1 V_53 , type ;
const struct V_70 * V_74 ;
const struct V_87 * V_88 ;
const struct V_64 * V_8 ;
const struct V_63 * V_81 ;
struct V_3 * V_343 ;
struct V_76 * V_39 ;
const struct V_152 * V_153 ;
V_39 = V_4 -> V_39 ;
V_343 = V_4 -> V_30 ? V_31 : V_4 ;
V_74 = F_24 ( V_343 , V_10 ) ;
V_81 = V_343 -> V_81 ;
if ( ! V_74 || ! V_81 ) {
F_25 ( V_39 , L_51 ,
V_80 , V_10 ) ;
return - 1 ;
}
V_8 = V_343 -> V_7 -> V_8 ;
type = V_8 -> type ;
V_135 = V_8 -> V_135 ;
V_9 = V_343 -> V_7 -> V_9 ;
V_271 = V_343 -> V_7 -> V_271 ;
V_88 = V_343 -> V_7 -> V_88 ;
V_153 = V_343 -> V_7 -> V_153 ;
F_14 ( V_10 ) ;
V_6 -> V_11 = F_27 ( V_10 , V_81 ) ;
V_6 -> V_12 = F_28 ( V_74 , V_88 ,
V_81 ) ;
V_6 -> V_13 = F_31 ( V_74 , V_88 ,
V_81 , type ) ;
V_6 -> V_14 = F_32 ( V_74 , V_88 ,
V_81 , type , V_9 , V_344 ) ;
V_53 = F_18 ( V_4 ) ;
if ( V_271 == V_323 && V_9 == V_15 ) {
V_6 -> V_224 = F_38 (
V_74 , V_10 , V_53 ) ;
} else if ( V_271 == V_272 && V_9 == V_18 ) {
V_6 -> V_224 = F_39 ( V_10 , V_53 ) ;
V_6 -> V_226 = F_40 () ;
V_6 -> V_228 = F_42 () ;
V_6 -> V_230 = F_43 () ;
} else {
return - 1 ;
}
V_6 -> V_345 =
F_44 ( V_10 , V_343 , V_9 ) &
( V_212 | V_209 | V_210 ) ;
if ( V_9 & V_15 ) {
V_6 -> V_16 =
F_36 ( V_346 ) ;
V_6 -> V_17 =
F_36 ( V_176 ) ;
} else if ( V_9 & V_18 ) {
V_6 -> V_19 =
F_37 ( V_346 ) ;
V_6 -> V_20 =
F_37 ( V_176 ) ;
}
if ( type == V_21 || type == V_22 ) {
V_6 -> V_23 = F_27 ( V_10 / 4 ,
V_81 ) ;
V_6 -> V_24 =
F_30 ( V_74 , V_88 ,
V_81 ) ;
V_6 -> V_25 = F_32 ( V_74 ,
V_88 , V_81 , type , V_9 ,
V_123 ) ;
}
V_6 -> V_10 = V_10 ;
return 0 ;
}
static struct V_5 * F_94 ( struct V_3 * V_4 , T_1 V_10 )
{
int V_29 ;
struct V_5 * * V_28 ;
struct V_5 * V_6 = NULL ;
struct V_76 * V_39 ;
V_39 = V_4 -> V_39 ;
if ( V_4 -> V_247 && V_4 -> V_247 -> V_10 == V_10 ) {
F_26 ( V_39 , L_52 , V_80 , V_10 ) ;
return V_4 -> V_247 ;
}
if ( V_4 -> V_30 )
V_28 = V_31 -> V_28 ;
else
V_28 = V_4 -> V_28 ;
for ( V_29 = 0 ; V_29 < V_32 && V_28 [ V_29 ] ; V_29 ++ ) {
if ( V_28 [ V_29 ] -> V_10 == V_10 ) {
V_6 = V_28 [ V_29 ] ;
F_26 ( V_39 ,
L_53 ,
V_80 , V_10 ) ;
break;
}
}
if ( ! V_6 ) {
V_6 = F_70 ( V_4 -> V_39 , sizeof( * V_6 ) , V_347 ) ;
if ( ! V_6 )
return NULL ;
if ( F_93 ( V_4 , V_10 , V_6 ) ) {
F_72 ( V_4 -> V_39 , V_6 ) ;
return NULL ;
}
for ( V_29 = 0 ; V_29 < V_32 && V_28 [ V_29 ] ; V_29 ++ )
;
if ( V_29 >= V_32 ) {
F_65 ( V_39 , L_54 ,
V_80 ) ;
V_29 = V_32 - 1 ;
F_72 ( V_4 -> V_39 , V_28 [ V_29 ] ) ;
}
V_28 [ V_29 ] = V_6 ;
}
return V_6 ;
}
static void F_95 ( struct V_3 * V_4 , T_1 V_232 )
{
F_26 ( V_4 -> V_39 , L_55 , V_80 ,
V_232 ) ;
if ( ! V_4 -> V_247 ) {
F_25 ( V_4 -> V_39 ,
L_56 ,
V_80 , V_232 ) ;
return;
}
F_49 ( V_4 , V_4 -> V_247 , V_232 ) ;
}
static void F_96 ( struct V_3 * V_4 , T_1 V_348 )
{
struct V_5 * V_6 ;
V_6 = F_94 ( V_4 , V_348 ) ;
if ( ! V_6 )
return;
V_4 -> V_247 = V_6 ;
F_26 ( V_4 -> V_39 , L_57 ,
V_80 , V_348 ) ;
F_48 ( V_4 , V_6 ) ;
F_50 ( V_4 , V_6 ) ;
F_49 ( V_4 , V_6 , V_346 ) ;
if ( V_4 -> V_56 == V_61 )
F_19 ( V_4 , V_62 ) ;
}
static void F_97 ( struct V_3 * V_4 )
{
if ( V_4 -> V_56 == V_61 )
F_19 ( V_4 , V_61 ) ;
}
static int T_2 F_98 ( void )
{
return F_99 ( & V_349 , F_81 ) ;
}
static void T_3 F_100 ( void )
{
F_101 ( & V_349 ) ;
}
