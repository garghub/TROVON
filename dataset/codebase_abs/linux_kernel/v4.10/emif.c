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
if ( ( V_4 -> V_7 -> V_9 == V_15 ) &&
( V_58 == V_56 ) ) {
F_20 ( 1 ,
L_17
L_18 ) ;
V_56 = V_59 ;
}
V_57 = F_17 ( V_49 + V_60 ) ;
V_57 &= ~ V_61 ;
V_57 |= ( V_56 << V_62 ) ;
F_21 ( V_57 , V_49 + V_60 ) ;
}
static void F_22 ( void )
{
struct V_3 * V_4 ;
F_23 (emif, &device_list, node) {
if ( V_4 -> V_56 == V_59 )
F_19 ( V_4 , V_63 ) ;
}
F_23 (emif, &device_list, node) {
if ( V_4 -> V_56 == V_59 )
F_19 ( V_4 , V_59 ) ;
}
}
static const struct V_64 * F_24 (
const struct V_65 * V_8 )
{
T_1 V_66 , type , V_67 ;
type = V_8 -> type ;
V_67 = V_8 -> V_67 ;
switch ( type ) {
case V_22 :
V_66 = V_67 - 1 ;
break;
case V_21 :
switch ( V_67 ) {
case V_68 :
case V_69 :
V_66 = V_67 + 3 ;
break;
default:
V_66 = V_67 - 1 ;
}
break;
default:
return NULL ;
}
return & V_70 [ V_66 ] ;
}
static const struct V_71 * F_25 ( struct V_3 * V_4 ,
T_1 V_10 )
{
T_1 V_29 , V_72 , V_73 , V_74 ;
const struct V_71 * V_75 = NULL ;
const struct V_71 * V_76 = V_4 -> V_7 -> V_75 ;
struct V_77 * V_39 = V_4 -> V_39 ;
V_74 = 1000000000 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_7 -> V_78 ; V_29 ++ ) {
V_73 = V_76 [ V_29 ] . V_79 ;
V_72 = V_76 [ V_29 ] . V_80 ;
if ( ( V_10 >= V_72 ) && ( V_10 <= V_73 ) && ( V_73 < V_74 ) ) {
V_74 = V_73 ;
V_75 = & V_76 [ V_29 ] ;
}
}
if ( ! V_75 )
F_26 ( V_39 , L_19 ,
V_81 , V_10 ) ;
F_27 ( V_39 , L_20 ,
V_81 , V_10 , V_74 ) ;
return V_75 ;
}
static T_1 F_28 ( T_1 V_10 ,
const struct V_64 * V_82 )
{
T_1 V_11 = 0 , V_83 = 0 , V_84 , V_85 ;
V_84 = V_10 / 1000 ;
V_85 = V_82 -> V_86 / 100 ;
V_83 = V_85 * V_84 / 10000 ;
V_11 |= V_83 << V_87 ;
return V_11 ;
}
static T_1 F_29 ( const struct V_71 * V_75 ,
const struct V_88 * V_89 ,
const struct V_64 * V_82 )
{
T_1 V_90 = 0 , V_83 = 0 ;
V_83 = V_73 ( V_89 -> V_91 , F_30 ( V_75 -> V_91 , V_47 ) ) - 1 ;
V_90 |= V_83 << V_92 ;
if ( V_82 -> V_93 == V_94 )
V_83 = F_30 ( V_75 -> V_95 , V_47 * 4 ) ;
else
V_83 = V_73 ( V_89 -> V_96 , F_30 ( V_75 -> V_96 , V_47 ) ) ;
V_90 |= ( V_83 - 1 ) << V_97 ;
V_83 = F_30 ( V_75 -> V_98 + V_75 -> V_99 , V_47 ) - 1 ;
V_90 |= V_83 << V_100 ;
V_83 = V_73 ( V_89 -> V_101 , F_30 ( V_75 -> V_98 , V_47 ) ) ;
V_90 |= ( V_83 - 1 ) << V_102 ;
V_83 = V_73 ( V_89 -> V_103 , F_30 ( V_75 -> V_103 , V_47 ) ) - 1 ;
V_90 |= V_83 << V_104 ;
V_83 = V_73 ( V_89 -> V_105 , F_30 ( V_75 -> V_105 , V_47 ) ) - 1 ;
V_90 |= V_83 << V_106 ;
V_83 = V_73 ( V_89 -> V_99 , F_30 ( V_75 -> V_99 , V_47 ) ) - 1 ;
V_90 |= V_83 << V_107 ;
return V_90 ;
}
static T_1 F_31 ( const struct V_71 * V_75 ,
const struct V_88 * V_89 ,
const struct V_64 * V_82 )
{
T_1 V_90 = 0 , V_83 = 0 ;
V_83 = V_73 ( V_89 -> V_91 , F_30 ( V_75 -> V_91 , V_47 ) ) - 1 ;
V_90 = V_83 << V_92 ;
if ( V_82 -> V_93 == V_94 ) {
V_83 = F_30 ( V_75 -> V_95 + 7500 , 4 * V_47 ) - 1 ;
} else {
V_83 = F_30 ( V_75 -> V_96 + 1875 , V_47 ) ;
V_83 = V_73 ( V_89 -> V_96 , V_83 ) - 1 ;
}
V_90 |= V_83 << V_97 ;
V_83 = F_30 ( V_75 -> V_98 + V_75 -> V_99 + 1875 , V_47 ) ;
V_90 |= ( V_83 - 1 ) << V_100 ;
V_83 = F_30 ( V_75 -> V_98 + 1875 , V_47 ) ;
V_83 = V_73 ( V_89 -> V_101 , V_83 ) - 1 ;
V_90 |= V_83 << V_102 ;
V_83 = V_73 ( V_89 -> V_103 , F_30 ( V_75 -> V_103 , V_47 ) ) - 1 ;
V_90 |= V_83 << V_104 ;
V_83 = V_73 ( V_89 -> V_105 , F_30 ( V_75 -> V_105 + 1875 , V_47 ) ) ;
V_90 |= ( V_83 - 1 ) << V_106 ;
V_83 = V_73 ( V_89 -> V_99 , F_30 ( V_75 -> V_99 + 1875 , V_47 ) ) ;
V_90 |= ( V_83 - 1 ) << V_107 ;
return V_90 ;
}
static T_1 F_32 ( const struct V_71 * V_75 ,
const struct V_88 * V_89 ,
const struct V_64 * V_82 ,
T_1 type )
{
T_1 V_108 = 0 , V_83 = 0 ;
V_83 = V_89 -> V_109 - 1 ;
V_108 |= V_83 << V_110 ;
V_83 = V_73 ( V_89 -> V_111 , F_30 ( V_75 -> V_111 , V_47 ) ) - 1 ;
V_108 |= V_83 << V_112 ;
V_83 = F_30 ( V_82 -> V_113 + 10000 , V_47 ) - 1 ;
V_108 |= V_83 << V_114 ;
V_108 |= V_83 << V_115 ;
V_83 = V_73 ( V_89 -> V_116 , F_30 ( V_75 -> V_116 , V_47 ) ) - 1 ;
V_108 |= V_83 << V_117 ;
return V_108 ;
}
static T_1 F_33 ( const struct V_71 * V_75 ,
const struct V_88 * V_89 ,
const struct V_64 * V_82 ,
T_1 type , T_1 V_9 , T_1 V_118 )
{
T_1 V_119 = 0 , V_83 = 0 , V_120 ;
V_83 = V_75 -> V_121 / V_82 -> V_86 - 1 ;
V_83 = V_83 > 0xF ? 0xF : V_83 ;
V_119 |= V_83 << V_122 ;
V_83 = F_30 ( V_82 -> V_113 , V_47 ) - 1 ;
V_119 |= V_83 << V_123 ;
V_120 = ( V_118 == V_124 ) ?
V_75 -> V_125 : V_75 -> V_126 ;
if ( V_9 == V_18 )
V_83 = F_30 ( V_120 + 1000 , V_47 ) - 1 ;
else
V_83 = F_30 ( V_120 , V_47 ) - 1 ;
V_119 |= V_83 << V_127 ;
V_83 = F_30 ( V_75 -> V_128 , V_47 ) - 1 ;
V_119 |= V_83 << V_129 ;
V_83 = F_30 ( V_75 -> V_130 , V_47 ) ;
V_83 = V_73 ( V_89 -> V_130 , V_83 ) - 1 ;
V_119 |= V_83 << V_131 ;
if ( V_9 == V_18 ) {
V_119 |= ( V_132 - 1 ) << V_133 ;
V_83 = F_30 ( V_134 , 128 ) - 1 ;
V_119 |= V_83 << V_135 ;
}
return V_119 ;
}
static T_1 F_34 ( const struct V_64 * V_82 ,
bool V_136 , bool V_137 )
{
T_1 V_138 = 0 , V_83 = 0 ;
V_83 = V_139 * 1000 / V_82 -> V_86 ;
V_138 |= V_83 << V_140 ;
V_83 = F_30 ( V_141 , V_142 ) - 1 ;
V_138 |= V_83 << V_143 ;
V_83 = F_30 ( V_144 , V_141 ) - 1 ;
V_138 |= V_83 << V_145 ;
V_138 |= V_146 << V_147 ;
if ( V_137 )
V_138 |= V_148 << V_149 ;
else
V_138 |= V_150 << V_149 ;
V_138 |= V_151 ;
V_83 = V_136 ? 1 : 0 ;
V_138 |= V_83 << V_152 ;
return V_138 ;
}
static T_1 F_35 ( const struct V_64 * V_82 ,
const struct V_153 * V_154 , bool V_136 ,
T_1 V_155 , T_1 V_156 )
{
T_1 V_157 = 0 , V_158 , V_159 ;
if ( V_154 && ( V_154 -> V_160 &
V_161 ) )
V_158 = V_154 -> V_162 ;
else
V_158 = V_163 ;
V_158 *= 1000000 ;
V_158 /= V_82 -> V_86 ;
V_157 |= ( V_158 << V_164 ) ;
V_156 = F_36 ( V_156 ) - 1 ;
V_159 = V_156 - V_155 ;
V_157 |= V_159 << V_165 ;
V_157 |= ( V_155 - 2 ) << V_166 ;
V_157 |= 1 << V_167 ;
V_157 |= 1 << V_168 ;
V_157 |= ( V_136 ? 1 : 0 ) << V_169 ;
return V_157 ;
}
static T_1 F_37 ( T_5 V_170 )
{
T_1 V_171 = 0 , V_83 = 0 ;
if ( V_170 )
V_83 = V_172 / V_47 / 64 - 1 ;
else
V_83 = 0x1FF ;
V_171 |= V_83 << V_173 ;
V_171 |= V_174 << V_175 ;
return V_171 ;
}
static T_1 F_38 ( T_5 V_170 )
{
T_1 V_176 = 0 , V_83 = 0 ;
if ( V_170 == V_177 )
V_83 = V_178 / V_47 / 16 - 1 ;
else
V_83 = 0 ;
V_176 |= V_83 << V_173 ;
V_176 |= V_179 << V_175 ;
return V_176 ;
}
static T_1 F_39 ( const struct V_71 * V_75 ,
T_1 V_10 , T_5 V_180 )
{
T_1 V_181 = V_182 , V_83 = 0 ;
V_83 = V_180 + F_30 ( V_75 -> V_126 , V_47 ) - 1 ;
V_181 |= V_83 << V_183 ;
if ( V_10 <= 100000000 )
V_83 = V_184 ;
else if ( V_10 <= 200000000 )
V_83 = V_185 ;
else
V_83 = V_186 ;
V_181 |= V_83 << V_187 ;
return V_181 ;
}
static T_1 F_40 ( T_1 V_10 , T_5 V_53 )
{
T_1 V_181 = V_188 , V_189 ;
if ( V_10 >= 265000000 && V_10 < 267000000 )
V_189 = 0 ;
else
V_189 = 1 ;
V_181 |= V_189 << V_190 ;
V_181 |= ( ( V_53 + F_30 ( V_191 ,
V_47 ) - 1 ) << V_192 ) ;
return V_181 ;
}
static T_1 F_41 ( void )
{
T_1 V_193 ;
V_193 = F_42 (
V_194 * 256 , V_47 ) ;
return V_193 | V_193 << 11 |
V_193 << 22 ;
}
static T_1 F_43 ( void )
{
T_1 V_193 ;
V_193 = F_42 (
V_194 * 256 , V_47 ) ;
return V_193 >> 10 | V_193 << 1 |
V_193 << 12 | V_193 << 23 ;
}
static T_1 F_44 ( void )
{
T_1 V_193 ;
V_193 = F_42 (
V_194 * 256 , V_47 ) ;
return V_193 >> 9 | V_193 << 2 |
V_193 << 13 ;
}
static T_1 F_45 ( T_1 V_10 , struct V_3 * V_4 , T_1 V_9 )
{
T_1 V_195 = 0 , V_196 ;
T_1 V_56 = V_59 ;
T_1 V_197 = V_198 ;
T_1 V_199 = V_200 ;
T_1 V_201 = V_202 ;
T_1 V_160 ;
T_5 V_203 ;
struct V_153 * V_204 = V_4 -> V_7 -> V_154 ;
if ( V_204 && ( V_204 -> V_160 & V_205 ) ) {
V_56 = V_204 -> V_56 ;
V_197 = V_204 -> V_206 ;
V_199 = V_204 -> V_207 ;
V_201 = V_204 -> V_208 ;
}
V_196 = V_10 >= V_201 ? V_197 : V_199 ;
if ( V_196 < 16 ) {
V_196 = 0 ;
} else {
if ( V_196 & ( V_196 - 1 ) )
V_196 <<= 1 ;
V_196 = F_36 ( V_196 ) - 3 ;
}
switch ( V_56 ) {
case V_209 :
V_203 = V_210 ;
V_160 = V_211 ;
break;
case V_59 :
if ( V_196 < 6 )
V_196 = 6 ;
V_203 = V_212 ;
V_160 = V_213 ;
break;
case V_58 :
V_203 = V_214 ;
V_160 = V_215 ;
break;
case V_63 :
default:
V_160 = 0 ;
V_203 = 0 ;
break;
}
if ( V_56 != V_63 && V_196 > V_160 >> V_203 ) {
F_46 ( L_21 ,
V_56 ,
V_197 ,
V_199 ,
V_201 ) ;
F_47 ( 1 , L_22 ,
V_196 , V_160 >> V_203 ) ;
V_196 = V_160 >> V_203 ;
}
V_195 = ( V_196 << V_203 ) & V_160 ;
V_195 |= ( V_213 | V_211 | V_215 ) &
~ V_160 ;
if ( V_9 == V_18 )
V_195 &= ~ V_211 ;
V_195 |= V_56 << V_62 ;
return V_195 ;
}
static void F_48 ( struct V_3 * V_4 )
{
T_1 V_57 , V_36 ;
void T_4 * V_49 ;
V_49 = V_4 -> V_49 ;
F_21 ( V_216 , V_49 + V_217 ) ;
V_36 = F_17 ( V_49 + V_218 ) ;
V_36 = ( V_36 & V_219 ) >>
V_220 ;
if ( V_4 -> V_7 -> V_8 -> V_136 ) {
F_21 ( V_216 | V_221 , V_49 + V_217 ) ;
V_57 = F_17 ( V_49 + V_218 ) ;
V_57 = ( V_57 & V_219 )
>> V_220 ;
V_36 = V_73 ( V_57 , V_36 ) ;
}
if ( F_49 ( V_36 < V_222 ) )
V_36 = V_222 ;
if ( F_50 ( V_36 != V_223 ) )
V_4 -> V_36 = V_36 ;
}
static void F_51 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_21 ( V_6 -> V_13 , V_49 + V_224 ) ;
F_21 ( V_6 -> V_225 , V_49 + V_226 ) ;
F_21 ( V_6 -> V_227 ,
V_49 + V_228 ) ;
if ( V_4 -> V_7 -> V_9 != V_18 )
return;
F_21 ( V_6 -> V_229 , V_49 + V_230 ) ;
F_21 ( V_6 -> V_231 , V_49 + V_232 ) ;
F_21 ( V_6 -> V_233 , V_49 + V_234 ) ;
}
static void F_52 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_235 )
{
T_1 V_236 ;
void T_4 * V_49 = V_4 -> V_49 ;
if ( V_235 == V_177 )
V_236 = V_6 -> V_20 ;
else
V_236 = V_6 -> V_19 ;
F_21 ( V_236 , V_49 + V_237 ) ;
}
static void F_53 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_90 , V_119 , V_238 , type ;
void T_4 * V_49 = V_4 -> V_49 ;
T_1 V_239 ;
type = V_4 -> V_7 -> V_8 -> type ;
V_90 = V_6 -> V_12 ;
V_119 = V_6 -> V_14 ;
V_238 = V_6 -> V_11 ;
if ( type != V_21 && type != V_22 )
goto V_240;
V_239 = V_4 -> V_36 ;
if ( V_239 == V_241 ) {
V_238 = V_6 -> V_23 ;
} else if ( V_239 == V_242 ) {
V_90 = V_6 -> V_24 ;
V_119 = V_6 -> V_25 ;
V_238 = V_6 -> V_23 ;
}
V_240:
F_21 ( V_90 , V_49 + V_243 ) ;
F_21 ( V_119 , V_49 + V_244 ) ;
F_21 ( V_238 , V_49 + V_245 ) ;
}
static T_6 F_54 ( void T_4 * V_49 , struct V_3 * V_4 )
{
T_1 V_246 ;
T_6 V_38 = V_247 ;
struct V_153 * V_154 ;
F_55 ( & V_248 , V_249 ) ;
V_246 = V_4 -> V_36 ;
F_48 ( V_4 ) ;
if ( F_49 ( V_4 -> V_36 == V_246 ) ) {
goto V_240;
} else if ( ! V_4 -> V_250 ) {
F_26 ( V_4 -> V_39 , L_23 ) ;
goto V_240;
}
V_154 = V_4 -> V_7 -> V_154 ;
if ( V_154 && ! ( V_154 -> V_160 &
V_251 ) ) {
if ( V_4 -> V_36 >= V_241 ) {
F_26 ( V_4 -> V_39 ,
L_24
L_25 ,
V_81 , V_4 -> V_36 ) ;
V_4 -> V_36 = V_252 ;
V_38 = V_253 ;
goto V_240;
}
}
if ( V_4 -> V_36 < V_246 ||
V_4 -> V_36 == V_252 ) {
V_38 = V_253 ;
} else {
F_53 ( V_4 , V_4 -> V_250 ) ;
F_22 () ;
}
V_240:
F_56 ( & V_248 , V_249 ) ;
return V_38 ;
}
static T_6 F_57 ( int V_254 , void * V_255 )
{
T_1 V_256 ;
struct V_3 * V_4 = V_255 ;
void T_4 * V_49 = V_4 -> V_49 ;
struct V_77 * V_39 = V_4 -> V_39 ;
T_6 V_38 = V_247 ;
V_256 = F_17 ( V_49 + V_257 ) ;
F_21 ( V_256 , V_49 + V_257 ) ;
if ( V_256 & V_258 )
V_38 = F_54 ( V_49 , V_4 ) ;
if ( V_256 & V_259 )
F_26 ( V_39 , L_26 , V_256 ) ;
if ( V_4 -> V_7 -> V_260 & V_261 ) {
V_256 = F_17 ( V_49 + V_262 ) ;
F_21 ( V_256 , V_49 + V_262 ) ;
if ( V_256 & V_263 )
F_26 ( V_39 , L_27 ,
V_256 ) ;
}
return V_38 ;
}
static T_6 F_58 ( int V_254 , void * V_255 )
{
struct V_3 * V_4 = V_255 ;
if ( V_4 -> V_36 == V_252 ) {
F_59 ( V_4 -> V_39 , L_28 ) ;
if ( V_264 ) {
F_60 () ;
} else {
F_47 ( 1 , L_29 ) ;
F_61 ( L_30 ) ;
}
return V_247 ;
}
F_55 ( & V_248 , V_249 ) ;
if ( V_4 -> V_250 ) {
F_53 ( V_4 , V_4 -> V_250 ) ;
F_22 () ;
} else {
F_26 ( V_4 -> V_39 , L_23 ) ;
}
F_56 ( & V_248 , V_249 ) ;
return V_247 ;
}
static void F_62 ( struct V_3 * V_4 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_21 ( F_17 ( V_49 + V_257 ) ,
V_49 + V_257 ) ;
if ( V_4 -> V_7 -> V_260 & V_261 )
F_21 ( F_17 ( V_49 + V_262 ) ,
V_49 + V_262 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
void T_4 * V_49 = V_4 -> V_49 ;
F_21 ( F_17 ( V_49 + V_265 ) ,
V_49 + V_266 ) ;
if ( V_4 -> V_7 -> V_260 & V_261 )
F_21 ( F_17 ( V_49 + V_267 ) ,
V_49 + V_268 ) ;
F_62 ( V_4 ) ;
}
static int T_2 F_64 ( struct V_3 * V_4 , T_1 V_254 )
{
T_1 V_256 , type ;
void T_4 * V_49 = V_4 -> V_49 ;
type = V_4 -> V_7 -> V_8 -> type ;
F_62 ( V_4 ) ;
V_256 = V_269 ;
if ( type == V_21 || type == V_22 )
V_256 |= V_270 ;
F_21 ( V_256 , V_49 + V_265 ) ;
if ( V_4 -> V_7 -> V_260 & V_261 ) {
V_256 = V_271 ;
F_21 ( V_256 , V_49 + V_267 ) ;
}
return F_65 ( V_4 -> V_39 , V_254 ,
F_57 ,
F_58 ,
0 , F_10 ( V_4 -> V_39 ) ,
V_4 ) ;
}
static void T_2 F_66 ( struct V_3 * V_4 )
{
T_1 V_195 , V_138 , V_272 ;
void T_4 * V_49 = V_4 -> V_49 ;
const struct V_64 * V_82 ;
const struct V_65 * V_8 ;
V_8 = V_4 -> V_7 -> V_8 ;
V_82 = F_24 ( V_8 ) ;
V_195 = F_45 ( 1000000000 , V_4 ,
V_4 -> V_7 -> V_9 ) ;
V_4 -> V_56 = ( V_195 & V_61 ) >> V_62 ;
F_21 ( V_195 , V_49 + V_60 ) ;
V_138 = F_34 ( V_82 , V_8 -> V_136 ,
V_8 -> V_137 ) ;
F_21 ( V_138 , V_49 + V_273 ) ;
F_48 ( V_4 ) ;
if ( V_4 -> V_36 == V_252 )
F_59 ( V_4 -> V_39 , L_28 ) ;
V_272 = F_35 ( V_82 ,
V_4 -> V_7 -> V_154 , V_8 -> V_136 ,
V_8 -> V_274 , F_16 ( V_4 ) ) ;
F_21 ( V_272 , V_49 + V_275 ) ;
if ( V_4 -> V_7 -> V_276 != V_277 )
return;
F_21 ( V_278 , V_49 + V_279 ) ;
F_21 ( V_280 , V_49 + V_281 ) ;
F_21 ( V_282 , V_49 + V_283 ) ;
F_21 ( V_284 , V_49 + V_285 ) ;
F_21 ( V_286 , V_49 + V_287 ) ;
F_21 ( V_288 , V_49 + V_289 ) ;
F_21 ( V_290 , V_49 + V_291 ) ;
F_21 ( V_292 , V_49 + V_293 ) ;
F_21 ( V_294 , V_49 + V_295 ) ;
F_21 ( V_296 , V_49 + V_297 ) ;
F_21 ( V_298 , V_49 + V_299 ) ;
F_21 ( V_300 , V_49 + V_301 ) ;
F_21 ( V_302 , V_49 + V_303 ) ;
F_21 ( V_304 , V_49 + V_305 ) ;
F_21 ( V_306 , V_49 + V_307 ) ;
F_21 ( V_308 , V_49 + V_309 ) ;
F_21 ( V_310 , V_49 + V_311 ) ;
F_21 ( V_312 , V_49 + V_313 ) ;
F_21 ( V_314 , V_49 + V_315 ) ;
F_21 ( V_316 , V_49 + V_317 ) ;
F_21 ( V_318 , V_49 + V_319 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_320 * V_321 = V_4 -> V_7 ;
V_321 -> V_75 = V_322 ;
V_321 -> V_78 = F_68 ( V_322 ) ;
F_69 ( V_4 -> V_39 , L_31 , V_81 ) ;
}
static int F_70 ( T_1 type , T_1 V_67 , T_1 V_274 , T_1 V_276 ,
T_1 V_9 , struct V_77 * V_39 )
{
int V_323 ;
V_323 = ( type == V_22 ||
type == V_21 )
&& ( V_67 >= V_324
&& V_67 <= V_325 )
&& ( V_274 >= V_326
&& V_274 <= V_327 ) ;
switch ( V_9 ) {
case V_15 :
V_323 = V_323 && ( V_276 == V_328 ) ;
break;
case V_18 :
V_323 = V_323 && ( V_276 == V_277 ) ;
break;
default:
V_323 = 0 ;
}
if ( ! V_323 )
F_26 ( V_39 , L_32 , V_81 ) ;
return V_323 ;
}
static int F_71 ( struct V_153 * V_204 ,
struct V_77 * V_39 )
{
int V_323 = 1 ;
if ( ( V_204 -> V_160 & V_205 ) &&
( V_204 -> V_56 != V_63 ) )
V_323 = V_204 -> V_208 &&
V_204 -> V_206 &&
V_204 -> V_207 ;
if ( V_204 -> V_160 & V_161 )
V_323 = V_323 && V_204 -> V_162 ;
if ( ! V_323 )
F_69 ( V_39 , L_33 , V_81 ) ;
return V_323 ;
}
static void T_2 F_72 ( struct V_329 * V_330 ,
struct V_3 * V_4 )
{
struct V_153 * V_204 = NULL ;
int V_331 ;
const T_7 * V_56 , * V_332 ;
V_56 = F_73 ( V_330 , L_34 , & V_331 ) ;
V_332 = F_73 ( V_330 , L_35 , & V_331 ) ;
if ( V_56 || V_332 )
V_204 = F_74 ( V_4 -> V_39 , sizeof( * V_204 ) ,
V_333 ) ;
if ( ! V_204 )
return;
if ( V_56 ) {
V_204 -> V_160 |= V_205 ;
V_204 -> V_56 = F_75 ( V_56 ) ;
F_76 ( V_330 ,
L_36 ,
& V_204 -> V_206 ) ;
F_76 ( V_330 ,
L_37 ,
& V_204 -> V_207 ) ;
F_76 ( V_330 ,
L_38 ,
& V_204 -> V_208 ) ;
}
if ( V_332 ) {
V_204 -> V_160 |=
V_161 ;
V_204 -> V_162 =
F_75 ( V_332 ) ;
}
if ( F_77 ( V_330 , L_39 , & V_331 ) )
V_204 -> V_160 |= V_251 ;
if ( ! F_71 ( V_204 , V_4 -> V_39 ) ) {
F_78 ( V_4 -> V_39 , V_204 ) ;
return;
}
V_4 -> V_7 -> V_154 = V_204 ;
}
static void T_2 F_79 ( struct V_329 * V_330 ,
struct V_329 * V_334 ,
struct V_65 * V_335 )
{
T_1 V_67 = 0 , V_274 = 0 ;
int V_331 ;
if ( F_77 ( V_330 , L_40 , & V_331 ) )
V_335 -> V_136 = true ;
if ( F_77 ( V_330 , L_41 , & V_331 ) )
V_335 -> V_137 = true ;
if ( F_80 ( V_334 , L_42 ) )
V_335 -> type = V_22 ;
else if ( F_80 ( V_334 , L_43 ) )
V_335 -> type = V_21 ;
F_76 ( V_334 , L_44 , & V_67 ) ;
F_76 ( V_334 , L_45 , & V_274 ) ;
if ( V_67 & ( V_67 - 1 ) )
V_335 -> V_67 = 0 ;
else
V_335 -> V_67 = F_36 ( V_67 ) - 5 ;
if ( V_274 & ( V_274 - 1 ) )
V_335 -> V_274 = 0 ;
else
V_335 -> V_274 = F_36 ( V_274 ) - 1 ;
}
static struct V_3 * T_2 F_81 (
struct V_329 * V_330 , struct V_77 * V_39 )
{
struct V_3 * V_4 = NULL ;
struct V_65 * V_335 = NULL ;
struct V_320 * V_321 = NULL ;
struct V_329 * V_334 ;
int V_331 ;
V_334 = F_82 ( V_330 , L_46 , 0 ) ;
if ( ! V_334 )
goto error;
V_4 = F_74 ( V_39 , sizeof( struct V_3 ) , V_333 ) ;
V_321 = F_74 ( V_39 , sizeof( * V_321 ) , V_333 ) ;
V_335 = F_74 ( V_39 , sizeof( * V_335 ) , V_333 ) ;
if ( ! V_4 || ! V_321 || ! V_335 ) {
F_26 ( V_39 , L_47 ,
V_81 ) ;
goto error;
}
V_4 -> V_7 = V_321 ;
V_321 -> V_8 = V_335 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_334 = V_334 ;
V_4 -> V_36 = V_222 ;
if ( F_80 ( V_330 , L_48 ) )
V_4 -> V_7 -> V_9 = V_15 ;
else if ( F_80 ( V_330 , L_49 ) )
V_4 -> V_7 -> V_9 = V_18 ;
F_76 ( V_330 , L_50 , & V_321 -> V_276 ) ;
if ( F_77 ( V_330 , L_51 , & V_331 ) )
V_321 -> V_260 |= V_261 ;
F_79 ( V_330 , V_334 , V_335 ) ;
if ( ! F_70 ( V_321 -> V_8 -> type , V_321 -> V_8 -> V_67 ,
V_321 -> V_8 -> V_274 , V_321 -> V_276 , V_321 -> V_9 ,
V_4 -> V_39 ) ) {
F_26 ( V_39 , L_52 , V_81 ) ;
goto error;
}
if ( V_31 && V_31 -> V_334 == V_334 ) {
V_4 -> V_30 = true ;
goto V_240;
} else if ( V_31 ) {
F_69 ( V_4 -> V_39 , L_53 ,
V_81 ) ;
}
F_72 ( V_330 , V_4 ) ;
V_4 -> V_7 -> V_75 = F_83 ( V_334 , V_4 -> V_39 ,
V_4 -> V_7 -> V_8 -> type ,
& V_4 -> V_7 -> V_78 ) ;
V_4 -> V_7 -> V_89 = F_84 ( V_334 , V_4 -> V_39 ) ;
goto V_240;
error:
return NULL ;
V_240:
return V_4 ;
}
static struct V_3 * T_2 F_81 (
struct V_329 * V_330 , struct V_77 * V_39 )
{
return NULL ;
}
static struct V_3 * T_2 F_85 (
struct V_336 * V_337 )
{
T_1 V_338 ;
struct V_3 * V_4 = NULL ;
struct V_65 * V_335 ;
struct V_153 * V_204 ;
struct V_320 * V_321 ;
struct V_77 * V_39 ;
void * V_57 ;
V_321 = V_337 -> V_39 . V_339 ;
V_39 = & V_337 -> V_39 ;
if ( ! ( V_321 && V_321 -> V_8 && F_70 ( V_321 -> V_8 -> type ,
V_321 -> V_8 -> V_67 , V_321 -> V_8 -> V_274 ,
V_321 -> V_276 , V_321 -> V_9 , V_39 ) ) ) {
F_26 ( V_39 , L_54 , V_81 ) ;
goto error;
}
V_4 = F_74 ( V_39 , sizeof( * V_4 ) , V_333 ) ;
V_57 = F_74 ( V_39 , sizeof( * V_321 ) , V_333 ) ;
V_335 = F_74 ( V_39 , sizeof( * V_335 ) , V_333 ) ;
if ( ! V_4 || ! V_321 || ! V_335 ) {
F_26 ( V_39 , L_55 , V_81 , __LINE__ ) ;
goto error;
}
memcpy ( V_57 , V_321 , sizeof( * V_321 ) ) ;
V_321 = V_57 ;
memcpy ( V_335 , V_321 -> V_8 , sizeof( * V_335 ) ) ;
V_321 -> V_8 = V_335 ;
V_4 -> V_7 = V_321 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_36 = V_222 ;
V_4 -> V_30 = V_31 && ( memcmp ( V_335 ,
V_31 -> V_7 -> V_8 ,
sizeof( struct V_65 ) ) == 0 ) ;
if ( V_4 -> V_30 ) {
V_321 -> V_75 = NULL ;
V_321 -> V_89 = NULL ;
goto V_240;
} else if ( V_31 ) {
F_69 ( V_4 -> V_39 , L_53 ,
V_81 ) ;
}
V_204 = V_321 -> V_154 ;
if ( V_204 && F_71 ( V_204 , V_39 ) ) {
V_57 = F_74 ( V_39 , sizeof( * V_204 ) , V_333 ) ;
if ( V_57 )
memcpy ( V_57 , V_204 , sizeof( * V_204 ) ) ;
else
F_69 ( V_39 , L_55 , V_81 ,
__LINE__ ) ;
V_321 -> V_154 = V_57 ;
}
V_338 = sizeof( struct V_71 ) * V_321 -> V_78 ;
if ( V_321 -> V_75 ) {
V_57 = F_74 ( V_39 , V_338 , V_333 ) ;
if ( V_57 ) {
memcpy ( V_57 , V_321 -> V_75 , V_338 ) ;
V_321 -> V_75 = V_57 ;
} else {
F_69 ( V_39 , L_55 , V_81 ,
__LINE__ ) ;
F_67 ( V_4 ) ;
}
} else {
F_67 ( V_4 ) ;
}
if ( V_321 -> V_89 ) {
V_57 = F_74 ( V_39 , sizeof( * V_321 -> V_89 ) , V_333 ) ;
if ( V_57 ) {
memcpy ( V_57 , V_321 -> V_89 , sizeof( * V_321 -> V_89 ) ) ;
V_321 -> V_89 = V_57 ;
} else {
F_69 ( V_39 , L_55 , V_81 ,
__LINE__ ) ;
V_321 -> V_89 = & V_340 ;
}
} else {
V_321 -> V_89 = & V_340 ;
}
V_240:
return V_4 ;
error:
return NULL ;
}
static int T_2 F_86 ( struct V_336 * V_337 )
{
struct V_3 * V_4 ;
struct V_341 * V_342 ;
int V_254 ;
if ( V_337 -> V_39 . V_343 )
V_4 = F_81 ( V_337 -> V_39 . V_343 , & V_337 -> V_39 ) ;
else
V_4 = F_85 ( V_337 ) ;
if ( ! V_4 ) {
F_46 ( L_56 , V_81 ) ;
goto error;
}
F_87 ( & V_4 -> V_344 , & V_345 ) ;
V_4 -> V_82 = F_24 ( V_4 -> V_7 -> V_8 ) ;
V_4 -> V_39 = & V_337 -> V_39 ;
F_88 ( V_337 , V_4 ) ;
V_342 = F_89 ( V_337 , V_346 , 0 ) ;
V_4 -> V_49 = F_90 ( V_4 -> V_39 , V_342 ) ;
if ( F_91 ( V_4 -> V_49 ) )
goto error;
V_254 = F_92 ( V_337 , 0 ) ;
if ( V_254 < 0 ) {
F_26 ( V_4 -> V_39 , L_57 ,
V_81 , V_254 ) ;
goto error;
}
F_66 ( V_4 ) ;
F_8 ( V_4 ) ;
F_63 ( V_4 ) ;
F_64 ( V_4 , V_254 ) ;
if ( ! V_31 ) {
V_31 = V_4 ;
F_93 ( & V_248 ) ;
}
V_335 ( & V_337 -> V_39 , L_58 ,
V_81 , V_4 -> V_49 , V_254 ) ;
return 0 ;
error:
return - V_347 ;
}
static int T_3 F_94 ( struct V_336 * V_337 )
{
struct V_3 * V_4 = F_95 ( V_337 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static void F_96 ( struct V_336 * V_337 )
{
struct V_3 * V_4 = F_95 ( V_337 ) ;
F_63 ( V_4 ) ;
}
static int F_97 ( struct V_3 * V_4 , T_1 V_10 ,
struct V_5 * V_6 )
{
T_1 V_136 , V_9 , V_276 ;
T_1 V_53 , type ;
const struct V_71 * V_75 ;
const struct V_88 * V_89 ;
const struct V_65 * V_8 ;
const struct V_64 * V_82 ;
struct V_3 * V_348 ;
struct V_77 * V_39 ;
const struct V_153 * V_154 ;
V_39 = V_4 -> V_39 ;
V_348 = V_4 -> V_30 ? V_31 : V_4 ;
V_75 = F_25 ( V_348 , V_10 ) ;
V_82 = V_348 -> V_82 ;
if ( ! V_75 || ! V_82 ) {
F_26 ( V_39 , L_59 ,
V_81 , V_10 ) ;
return - 1 ;
}
V_8 = V_348 -> V_7 -> V_8 ;
type = V_8 -> type ;
V_136 = V_8 -> V_136 ;
V_9 = V_348 -> V_7 -> V_9 ;
V_276 = V_348 -> V_7 -> V_276 ;
V_89 = V_348 -> V_7 -> V_89 ;
V_154 = V_348 -> V_7 -> V_154 ;
F_14 ( V_10 ) ;
V_6 -> V_11 = F_28 ( V_10 , V_82 ) ;
V_6 -> V_12 = F_29 ( V_75 , V_89 ,
V_82 ) ;
V_6 -> V_13 = F_32 ( V_75 , V_89 ,
V_82 , type ) ;
V_6 -> V_14 = F_33 ( V_75 , V_89 ,
V_82 , type , V_9 , V_349 ) ;
V_53 = F_18 ( V_4 ) ;
if ( V_276 == V_328 && V_9 == V_15 ) {
V_6 -> V_225 = F_39 (
V_75 , V_10 , V_53 ) ;
} else if ( V_276 == V_277 && V_9 == V_18 ) {
V_6 -> V_225 = F_40 ( V_10 , V_53 ) ;
V_6 -> V_229 = F_41 () ;
V_6 -> V_231 = F_43 () ;
V_6 -> V_233 = F_44 () ;
} else {
return - 1 ;
}
V_6 -> V_227 =
F_45 ( V_10 , V_348 , V_9 ) &
( V_211 | V_213 | V_215 ) ;
if ( V_9 & V_15 ) {
V_6 -> V_16 =
F_37 ( V_350 ) ;
V_6 -> V_17 =
F_37 ( V_177 ) ;
} else if ( V_9 & V_18 ) {
V_6 -> V_19 =
F_38 ( V_350 ) ;
V_6 -> V_20 =
F_38 ( V_177 ) ;
}
if ( type == V_21 || type == V_22 ) {
V_6 -> V_23 = F_28 ( V_10 / 4 ,
V_82 ) ;
V_6 -> V_24 =
F_31 ( V_75 , V_89 ,
V_82 ) ;
V_6 -> V_25 = F_33 ( V_75 ,
V_89 , V_82 , type , V_9 ,
V_124 ) ;
}
V_6 -> V_10 = V_10 ;
return 0 ;
}
static struct V_5 * F_98 ( struct V_3 * V_4 , T_1 V_10 )
{
int V_29 ;
struct V_5 * * V_28 ;
struct V_5 * V_6 = NULL ;
struct V_77 * V_39 ;
V_39 = V_4 -> V_39 ;
if ( V_4 -> V_250 && V_4 -> V_250 -> V_10 == V_10 ) {
F_27 ( V_39 , L_60 , V_81 , V_10 ) ;
return V_4 -> V_250 ;
}
if ( V_4 -> V_30 )
V_28 = V_31 -> V_28 ;
else
V_28 = V_4 -> V_28 ;
for ( V_29 = 0 ; V_29 < V_32 && V_28 [ V_29 ] ; V_29 ++ ) {
if ( V_28 [ V_29 ] -> V_10 == V_10 ) {
V_6 = V_28 [ V_29 ] ;
F_27 ( V_39 ,
L_61 ,
V_81 , V_10 ) ;
break;
}
}
if ( ! V_6 ) {
V_6 = F_74 ( V_4 -> V_39 , sizeof( * V_6 ) , V_351 ) ;
if ( ! V_6 )
return NULL ;
if ( F_97 ( V_4 , V_10 , V_6 ) ) {
F_78 ( V_4 -> V_39 , V_6 ) ;
return NULL ;
}
for ( V_29 = 0 ; V_29 < V_32 && V_28 [ V_29 ] ; V_29 ++ )
;
if ( V_29 >= V_32 ) {
F_69 ( V_39 , L_62 ,
V_81 ) ;
V_29 = V_32 - 1 ;
F_78 ( V_4 -> V_39 , V_28 [ V_29 ] ) ;
}
V_28 [ V_29 ] = V_6 ;
}
return V_6 ;
}
static void F_99 ( struct V_3 * V_4 , T_1 V_235 )
{
F_27 ( V_4 -> V_39 , L_63 , V_81 ,
V_235 ) ;
if ( ! V_4 -> V_250 ) {
F_26 ( V_4 -> V_39 ,
L_64 ,
V_81 , V_235 ) ;
return;
}
F_52 ( V_4 , V_4 -> V_250 , V_235 ) ;
}
static void F_100 ( struct V_3 * V_4 , T_1 V_352 )
{
struct V_5 * V_6 ;
V_6 = F_98 ( V_4 , V_352 ) ;
if ( ! V_6 )
return;
V_4 -> V_250 = V_6 ;
F_27 ( V_4 -> V_39 , L_65 ,
V_81 , V_352 ) ;
F_51 ( V_4 , V_6 ) ;
F_53 ( V_4 , V_6 ) ;
F_52 ( V_4 , V_6 , V_350 ) ;
if ( V_4 -> V_56 == V_59 )
F_19 ( V_4 , V_63 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
if ( V_4 -> V_56 == V_59 )
F_19 ( V_4 , V_59 ) ;
}
