static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
V_6 = F_3 ( V_8 ) ;
if ( V_3 ) {
if ( ( V_6 & V_9 ) &&
( V_6 & V_10 ) ) {
if ( ! V_5 -> V_11 ) {
V_7 = F_4 ( V_12 ) & ~ V_13 ;
V_7 |= F_5 ( 0xd ) ;
F_6 ( V_12 , V_7 ) ;
V_6 &= ~ V_14 ;
V_6 |= F_7 ( 1 ) ;
V_6 |= V_15 ;
V_6 |= V_16 ;
F_8 ( V_8 , V_6 ) ;
F_9 ( 10 ) ;
V_6 &= ~ V_16 ;
F_8 ( V_8 , V_6 ) ;
}
}
} else {
if ( ! V_5 -> V_11 ) {
V_6 &= ~ V_14 ;
V_6 &= ~ V_15 ;
}
if ( ( V_6 & V_9 ) ||
( V_6 & V_10 ) )
F_8 ( V_8 , V_6 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
bool V_3 )
{
F_1 ( V_2 , V_3 ) ;
if ( V_3 )
F_11 ( V_17 , V_18 , ~ V_18 ) ;
else
F_11 ( V_17 , 0 , ~ V_18 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
if ( V_3 ) {
if ( V_20 -> V_21 ) {
F_6 ( V_22 , 0xC0000000 ) ;
F_14 ( V_23 , 0xFFFFFFFF ) ;
F_14 ( V_24 , 0xFFFFFFFF ) ;
F_14 ( V_25 , 0xFFFFFFFF ) ;
F_14 ( V_26 , 0xFFFFFFFF ) ;
F_14 ( V_27 , 0xFFFFFFFF ) ;
F_14 ( V_28 , 0xFFFFFFFF ) ;
F_14 ( V_29 , 0xFFFFFFFF ) ;
F_14 ( V_30 , 0xFFFFFFFF ) ;
F_14 ( V_31 , 0xFFFFFFFF ) ;
F_14 ( V_32 , 0xFFFFFFFF ) ;
F_14 ( V_33 , 0xFFFFFFFF ) ;
F_14 ( V_34 , 0xFFFFFFFF ) ;
F_11 ( V_35 , V_36 , ~ V_36 ) ;
}
F_11 ( V_35 , V_37 , ~ V_37 ) ;
} else {
F_11 ( V_35 , 0 , ~ V_37 ) ;
F_11 ( V_35 , V_38 , ~ V_38 ) ;
F_11 ( V_35 , 0 , ~ V_38 ) ;
F_4 ( V_39 ) ;
if ( V_20 -> V_21 ) {
F_11 ( V_35 , 0 , ~ V_36 ) ;
F_6 ( V_22 , 0xC0000000 ) ;
F_14 ( V_23 , 0 ) ;
F_14 ( V_24 , 0 ) ;
F_14 ( V_25 , 0 ) ;
F_14 ( V_26 , 0 ) ;
F_14 ( V_27 , 0 ) ;
F_14 ( V_28 , 0 ) ;
F_14 ( V_29 , 0 ) ;
F_14 ( V_30 , 0 ) ;
F_14 ( V_31 , 0 ) ;
F_14 ( V_32 , 0 ) ;
F_14 ( V_33 , 0 ) ;
F_14 ( V_34 , 0 ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
if ( V_3 ) {
T_1 V_40 ;
if ( V_2 -> V_41 == V_42 )
V_40 = V_43 ;
else if ( V_2 -> V_41 == V_44 )
V_40 = V_45 ;
else
V_40 = V_46 ;
F_6 ( V_22 , 0xC0000000 ) ;
F_14 ( V_47 , V_48 ) ;
F_14 ( V_49 , V_50 & 0xFFFFCFFF ) ;
F_14 ( V_51 , V_52 ) ;
F_14 ( V_53 , V_54 ) ;
if ( V_5 -> V_55 )
F_6 ( V_56 , V_40 ) ;
if ( V_20 -> V_57 ) {
F_11 ( V_58 , V_59 , ~ V_59 ) ;
F_11 ( V_60 , V_59 , ~ V_59 ) ;
F_11 ( V_61 , V_59 , ~ V_59 ) ;
F_11 ( V_62 , V_59 , ~ V_59 ) ;
F_11 ( V_63 , V_59 , ~ V_59 ) ;
F_11 ( V_64 , V_59 , ~ V_59 ) ;
F_11 ( V_65 , V_59 , ~ V_59 ) ;
F_11 ( V_66 , V_59 , ~ V_59 ) ;
}
} else {
F_6 ( V_22 , 0xC0000000 ) ;
F_14 ( V_47 , 0xFFFFFFFF ) ;
F_14 ( V_49 , 0xFFFFFFFF ) ;
F_14 ( V_51 , 0xFFFFFFFF ) ;
F_14 ( V_53 , 0xFFFFFFFF ) ;
if ( V_5 -> V_55 )
F_6 ( V_56 , 0x81f44bc0 ) ;
}
}
void F_16 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 ) {
if ( V_5 -> V_67 )
F_11 ( V_17 , V_68 , ~ V_68 ) ;
if ( V_5 -> V_69 )
F_11 ( V_70 , V_71 , ~ V_71 ) ;
} else {
F_11 ( V_72 , 0 , ~ V_73 ) ;
F_11 ( V_17 , 0 , ~ V_68 ) ;
F_11 ( V_70 , 0 , ~ V_71 ) ;
F_11 ( V_70 , 0 , ~ V_74 ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
F_11 ( V_17 , V_75 , ~ V_75 ) ;
}
void F_18 ( struct V_1 * V_2 ,
bool V_3 )
{
if ( V_3 )
F_11 ( V_35 , 0 , ~ V_76 ) ;
else
F_11 ( V_35 , V_76 , ~ V_76 ) ;
}
void F_19 ( struct V_1 * V_2 ,
bool V_3 )
{
if ( V_3 )
F_11 ( V_77 , 0 , ~ V_78 ) ;
else
F_11 ( V_77 , V_78 , ~ V_78 ) ;
}
int F_20 ( struct V_1 * V_2 ,
bool V_79 )
{
T_2 V_80 = V_79 ?
( T_2 ) V_81 : ( T_2 ) V_82 ;
if ( F_21 ( V_2 , V_80 ) != V_83 )
return - V_84 ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
T_1 V_85 ;
T_1 V_86 ;
V_85 = F_23 ( V_2 ) ;
V_86 = ( 460 * V_85 ) / 100 ;
F_24 ( V_2 ,
V_87 ,
V_86 ) ;
F_24 ( V_2 ,
V_88 , 1 ) ;
F_24 ( V_2 ,
V_89 , 0xAA ) ;
F_25 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_24 ( V_2 ,
V_90 , 1 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 V_91 , bool V_92 )
{
#if F_28 ( V_93 )
struct V_19 * V_20 = F_13 ( V_2 ) ;
#endif
T_1 V_6 ;
F_9 ( 10 ) ;
V_6 = F_3 ( V_8 ) ;
if ( ( V_91 == V_94 ) && ( V_6 & V_95 ) )
return 0 ;
#if F_28 ( V_93 )
if ( ( V_91 == V_94 ) ||
( V_91 == V_96 ) ) {
V_20 -> V_97 = true ;
return F_29 ( V_2 , V_91 , V_92 ) ;
} else if ( ( V_91 == V_98 ) &&
V_20 -> V_97 ) {
V_20 -> V_97 = false ;
return F_29 ( V_2 , V_91 , V_92 ) ;
}
#endif
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
#if F_28 ( V_93 )
F_31 ( V_2 ) ;
#endif
V_6 = F_3 ( V_8 ) ;
if ( ( V_6 & V_9 ) &&
( V_6 & V_10 ) )
V_5 -> V_99 = true ;
else
V_5 -> V_99 = false ;
if ( ! V_5 -> V_99 )
F_27 ( V_2 , V_96 , true ) ;
}
static enum V_100 F_32 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = F_33 ( V_102 ) ;
if ( V_104 -> V_105 . V_106 & V_107 )
return 1 ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_101 * V_108 ,
struct V_101 * V_109 )
{
enum V_100 V_110 =
F_32 ( V_108 ) ;
enum V_100 V_111 =
F_32 ( V_109 ) ;
T_3 V_112 ;
if ( V_110 < V_111 ) {
if ( V_110 == V_113 )
V_112 = V_94 ;
else if ( V_110 == V_114 )
V_112 = V_96 ;
else
V_112 = V_115 ;
F_27 ( V_2 , V_112 , false ) ;
}
}
void F_35 ( struct V_1 * V_2 ,
struct V_101 * V_108 ,
struct V_101 * V_109 )
{
enum V_100 V_110 =
F_32 ( V_108 ) ;
enum V_100 V_111 =
F_32 ( V_109 ) ;
T_3 V_112 ;
if ( V_110 > V_111 ) {
if ( V_110 == V_113 )
V_112 = V_94 ;
else if ( V_110 == V_114 )
V_112 = V_96 ;
else
V_112 = V_115 ;
F_27 ( V_2 , V_112 , false ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
T_4 V_118 , T_5 * V_119 )
{
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_117 -> V_121 ; V_120 ++ ) {
if ( V_118 <= V_117 -> V_122 [ V_120 ] . V_118 ) {
V_119 -> V_123 = ( T_3 ) V_120 ;
V_119 -> V_118 = F_37 ( V_117 -> V_122 [ V_120 ] . V_118 ) ;
break;
}
}
if ( V_120 == V_117 -> V_121 )
return - V_84 ;
return 0 ;
}
T_3 F_38 ( struct V_1 * V_2 , T_1 V_124 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_125 = 0 ;
bool V_126 = false ;
if ( V_5 -> V_127 ) {
if ( V_124 <= V_5 -> V_128 )
V_126 = true ;
V_125 = F_39 ( V_2 , V_124 , V_126 ) ;
if ( V_126 )
V_125 |= V_129 ;
}
return V_125 ;
}
T_1 F_40 ( struct V_1 * V_2 , T_1 V_130 )
{
T_1 V_131 = V_2 -> clock . V_132 . V_133 ;
T_1 V_134 = V_130 * V_131 ;
if ( V_131 == 10000 ) {
if ( V_134 > 500000 )
return 0xC6 ;
if ( V_134 > 400000 )
return 0x9D ;
if ( V_134 > 330000 )
return 0x6C ;
if ( V_134 > 250000 )
return 0x2B ;
if ( V_134 > 160000 )
return 0x5B ;
if ( V_134 > 120000 )
return 0x0A ;
return 0x4B ;
}
if ( V_134 > 250000 )
return 0x8B ;
if ( V_134 > 200000 )
return 0xCC ;
if ( V_134 > 150000 )
return 0x9B ;
return 0x6B ;
}
static int F_41 ( struct V_1 * V_2 ,
T_1 V_135 , T_1 V_136 ,
T_6 * V_124 ,
bool V_126 , bool V_137 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_138 =
V_5 -> V_139 . V_140 . V_138 ;
T_1 V_141 =
V_5 -> V_139 . V_140 . V_141 ;
T_1 V_142 =
V_5 -> V_139 . V_140 . V_142 ;
T_1 V_143 =
V_5 -> V_139 . V_140 . V_143 ;
T_1 V_144 =
V_5 -> V_139 . V_140 . V_144 ;
T_1 V_145 =
V_5 -> V_139 . V_140 . V_145 ;
T_1 V_146 = V_5 -> V_139 . V_140 . V_146 ;
T_1 V_147 = V_5 -> V_139 . V_140 . V_147 ;
struct V_148 V_149 ;
T_1 V_150 ;
T_1 V_151 ;
int V_152 ;
T_1 V_153 ;
V_152 = F_42 ( V_2 , V_154 ,
V_136 , V_126 , & V_149 ) ;
if ( V_152 )
return V_152 ;
if ( ! V_126 ) {
V_153 = F_4 ( V_155 ) ;
if( V_153 & 0x8000000 )
V_149 . V_156 = 1 ;
}
V_150 = F_40 ( V_2 , V_149 . V_157 ) ;
V_138 &= ~ ( V_158 |
V_159 |
V_160 |
V_161 |
V_162 ) ;
V_138 |= F_43 ( V_149 . V_163 ) ;
V_138 |= F_44 ( V_149 . V_156 ) ;
V_138 |= F_45 ( V_149 . V_157 ) ;
V_138 |= F_46 ( V_149 . V_164 ) ;
V_138 |= F_47 ( V_150 ) ;
if ( V_149 . V_165 )
V_141 |= V_166 ;
else
V_141 &= ~ V_166 ;
if ( V_5 -> V_127 ) {
V_142 &= ~ ( V_158 |
V_159 |
V_160 |
V_161 |
V_162 ) ;
V_142 |= F_43 ( V_149 . V_163 ) ;
V_142 |= F_44 ( V_149 . V_156 ) ;
V_142 |= F_45 ( V_149 . V_157 ) ;
V_142 |= F_46 ( V_149 . V_164 ) ;
V_142 |= F_47 ( V_150 ) ;
if ( V_126 )
V_142 &= ~ V_167 ;
else
V_142 |= V_167 ;
if ( V_149 . V_165 )
V_143 |= V_166 ;
else
V_143 &= ~ V_166 ;
}
if ( V_5 -> V_69 ) {
struct V_168 V_169 ;
T_1 V_170 = V_136 * V_149 . V_156 ;
if ( F_48 ( V_2 , & V_169 ,
V_171 , V_170 ) ) {
T_1 V_85 = V_2 -> clock . V_132 . V_133 ;
T_1 V_172 = F_49 ( V_149 . V_163 ) ;
T_1 V_173 = V_85 * 5 / ( V_172 * V_169 . V_174 ) ;
T_1 V_175 = V_169 . V_176 *
( 0x4000 * V_149 . V_157 + 0x800 * V_149 . V_164 ) / ( V_173 * 625 ) ;
V_146 &= ~ V_177 ;
V_146 |= F_50 ( V_175 ) ;
V_147 &= ~ V_178 ;
V_147 |= F_51 ( V_173 ) ;
}
}
V_151 = F_52 ( V_5 -> V_127 ,
V_136 ) ;
V_144 &= ~ V_179 ;
V_144 |= F_53 ( V_151 ) ;
if ( V_137 )
V_144 |= ( V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ) ;
else
V_144 &= ~ ( V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ) ;
V_124 -> V_188 . V_189 = F_54 ( V_136 ) ;
V_124 -> V_188 . V_190 = F_54 ( V_138 ) ;
V_124 -> V_188 . V_191 = F_54 ( V_141 ) ;
V_124 -> V_188 . V_192 = F_54 ( V_142 ) ;
V_124 -> V_188 . V_193 = F_54 ( V_143 ) ;
V_124 -> V_188 . V_194 = F_54 ( V_144 ) ;
V_124 -> V_188 . V_195 = F_54 ( V_145 ) ;
V_124 -> V_188 . V_196 = F_54 ( V_146 ) ;
V_124 -> V_188 . V_197 = F_54 ( V_147 ) ;
return 0 ;
}
T_3 F_39 ( struct V_1 * V_2 ,
T_1 V_136 , bool V_126 )
{
T_3 V_198 ;
if ( V_2 -> V_41 >= V_199 ) {
if ( V_126 ) {
if ( V_136 < 10000 )
V_198 = 0x00 ;
else if ( V_136 > 47500 )
V_198 = 0x0f ;
else
V_198 = ( T_3 ) ( ( V_136 - 10000 ) / 2500 ) ;
} else {
if ( V_136 < 65000 )
V_198 = 0x00 ;
else if ( V_136 > 135000 )
V_198 = 0x0f ;
else
V_198 = ( T_3 ) ( ( V_136 - 60000 ) / 5000 ) ;
}
} else {
if ( V_126 ) {
if ( V_136 < 10000 )
V_198 = 0x00 ;
else if ( V_136 > 47500 )
V_198 = 0x0f ;
else
V_198 = ( T_3 ) ( ( V_136 - 10000 ) / 2500 ) ;
} else {
if ( V_136 < 40000 )
V_198 = 0x00 ;
else if ( V_136 > 115000 )
V_198 = 0x0f ;
else
V_198 = ( T_3 ) ( ( V_136 - 40000 ) / 5000 ) ;
}
}
return V_198 ;
}
static int F_55 ( struct V_1 * V_2 ,
T_1 V_124 ,
T_5 * V_119 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
if ( ! V_5 -> V_200 ) {
V_119 -> V_123 = V_20 -> V_201 ;
V_119 -> V_118 = F_37 ( V_202 ) ;
return 0 ;
}
if ( V_124 <= V_5 -> V_203 ) {
V_119 -> V_123 = V_20 -> V_204 ;
V_119 -> V_118 = F_37 ( V_205 ) ;
} else {
V_119 -> V_123 = V_20 -> V_201 ;
V_119 -> V_118 = F_37 ( V_202 ) ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
T_7 * V_208 ,
T_3 V_209 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
int V_152 ;
bool V_137 ;
V_208 -> V_210 = V_5 -> V_99 ?
( ( V_207 -> V_106 & V_107 ) ? 1 : 0 ) : 0 ;
V_208 -> V_211 = ( V_207 -> V_106 & V_107 ) ? 1 : 0 ;
V_208 -> V_212 = ( V_207 -> V_106 & V_213 ) ? 1 : 0 ;
V_208 -> V_214 = V_209 ;
V_152 = F_57 ( V_2 , V_207 -> V_215 , & V_208 -> V_215 ) ;
if ( V_152 )
return V_152 ;
V_208 -> V_216 = 0 ;
if ( V_5 -> V_217 &&
( V_207 -> V_124 <= V_5 -> V_217 ) &&
! V_20 -> V_218 ) {
V_208 -> V_216 |= V_219 ;
if ( V_20 -> V_220 )
V_208 -> V_221 |= V_222 ;
else
V_208 -> V_221 &= ~ V_222 ;
}
if ( V_5 -> V_127 ) {
if ( V_207 -> V_124 > V_5 -> V_223 )
V_208 -> V_216 |= V_224 ;
if ( V_207 -> V_124 > V_20 -> V_225 )
V_208 -> V_216 |= V_226 ;
V_208 -> V_227 = F_38 ( V_2 , V_207 -> V_124 ) ;
if ( V_208 -> V_227 & V_129 ) {
if ( F_39 ( V_2 , V_207 -> V_124 , true ) >=
( ( F_4 ( V_155 ) >> 16 ) & 0xf ) )
V_137 = ( ( F_4 ( V_228 ) >> 1 ) & 0x1 ) ? true : false ;
else
V_137 = ( ( F_4 ( V_229 ) >> 1 ) & 0x1 ) ? true : false ;
} else
V_137 = V_20 -> V_230 ;
V_152 = F_41 ( V_2 ,
V_207 -> V_215 ,
V_207 -> V_124 ,
& V_208 -> V_124 ,
( V_208 -> V_227 & V_129 ) != 0 ,
V_137 ) ;
} else {
V_152 = F_41 ( V_2 ,
V_207 -> V_215 ,
V_207 -> V_124 ,
& V_208 -> V_124 ,
true ,
true ) ;
}
if ( V_152 )
return V_152 ;
V_152 = F_36 ( V_2 ,
& V_20 -> V_231 ,
V_207 -> V_232 ,
& V_208 -> V_232 ) ;
if ( V_152 )
return V_152 ;
if ( V_20 -> V_233 ) {
V_152 = F_36 ( V_2 ,
& V_20 -> V_234 ,
V_207 -> V_235 ,
& V_208 -> V_235 ) ;
if ( V_152 )
return V_152 ;
}
V_152 = F_55 ( V_2 , V_207 -> V_124 , & V_208 -> V_236 ) ;
return V_152 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
T_8 * V_237 )
{
struct V_103 * V_104 = F_33 ( V_102 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
int V_152 ;
if ( ! ( V_102 -> V_238 & V_239 ) )
V_237 -> V_106 |= V_240 ;
V_152 = F_56 ( V_2 ,
& V_104 -> V_241 ,
& V_237 -> V_242 [ 0 ] ,
V_243 ) ;
if ( V_152 )
return V_152 ;
V_152 = F_56 ( V_2 ,
& V_104 -> V_244 ,
& V_237 -> V_242 [ 1 ] ,
V_243 ) ;
if ( V_152 )
return V_152 ;
V_152 = F_56 ( V_2 ,
& V_104 -> V_105 ,
& V_237 -> V_242 [ 2 ] ,
V_245 ) ;
if ( V_152 )
return V_152 ;
V_237 -> V_242 [ 0 ] . V_246 = V_247 ;
V_237 -> V_242 [ 1 ] . V_246 = V_248 ;
V_237 -> V_242 [ 2 ] . V_246 = V_249 ;
if ( V_20 -> V_250 ) {
V_237 -> V_242 [ 0 ] . V_251 = 2 ;
V_237 -> V_242 [ 1 ] . V_251 = 3 ;
V_237 -> V_242 [ 2 ] . V_251 = 4 ;
} else {
V_237 -> V_242 [ 0 ] . V_251 = 0 ;
V_237 -> V_242 [ 1 ] . V_251 = 0 ;
V_237 -> V_242 [ 2 ] . V_251 = 0 ;
}
F_59 ( V_2 , V_102 , V_237 ) ;
return F_60 ( V_2 , V_102 , V_237 ) ;
}
static void F_61 ( struct V_252 * V_253 ,
T_9 * V_254 ,
T_1 V_255 , T_1 V_256 )
{
T_1 V_120 , V_257 ;
for ( V_120 = 0 , V_257 = 0 ; V_257 < V_255 ; V_257 ++ ) {
if ( V_256 & ( 1 << V_257 ) ) {
V_254 -> V_118 [ V_120 ] = F_54 ( V_253 -> V_258 [ V_257 ] ) ;
V_120 ++ ;
}
}
}
static void F_62 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
T_9 * V_259 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_120 = 0 ;
for ( V_120 = 0 ; V_120 < V_20 -> V_260 . V_255 ; V_120 ++ ) {
if ( V_207 -> V_124 <=
V_20 -> V_260 . V_261 [ V_120 ] . V_262 )
break;
}
if ( ( V_120 == V_20 -> V_260 . V_255 ) && ( V_120 > 0 ) )
-- V_120 ;
F_61 ( & V_20 -> V_260 . V_261 [ V_120 ] ,
V_259 ,
V_20 -> V_260 . V_263 ,
V_20 -> V_260 . V_256 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
T_10 * V_260 )
{
struct V_103 * V_104 = F_33 ( V_102 ) ;
F_62 ( V_2 ,
& V_104 -> V_241 ,
& V_260 -> V_254 [ 2 ] ) ;
F_62 ( V_2 ,
& V_104 -> V_244 ,
& V_260 -> V_254 [ 3 ] ) ;
F_62 ( V_2 ,
& V_104 -> V_105 ,
& V_260 -> V_254 [ 4 ] ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_101 * V_108 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_4 V_264 = V_5 -> V_265 +
F_65 ( V_266 , V_267 ) ;
T_8 V_104 = { 0 } ;
int V_152 ;
V_152 = F_58 ( V_2 , V_108 , & V_104 ) ;
if ( V_152 )
return V_152 ;
return F_66 ( V_2 , V_264 , ( T_3 * ) & V_104 ,
sizeof( T_8 ) ,
V_5 -> V_268 ) ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_101 * V_108 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_10 V_260 = { 0 } ;
T_4 V_264 ;
F_63 ( V_2 , V_108 , & V_260 ) ;
V_264 = V_20 -> V_269 +
( T_4 ) F_65 ( T_10 , V_254 [ 2 ] ) ;
return F_66 ( V_2 , V_264 ,
( T_3 * ) & V_260 . V_254 [ 2 ] ,
sizeof( T_9 ) * 3 ,
V_5 -> V_268 ) ;
}
T_1 F_68 ( struct V_1 * V_2 ,
T_1 V_135 , T_1 V_136 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_270 = V_5 -> V_127 ? 1 : 2 ;
T_1 V_125 = ( 4 * V_270 * V_135 ) / ( V_136 / 2 ) ;
T_1 V_271 ;
if ( V_125 <= 4 )
V_271 = 0 ;
else if ( V_125 < 8 )
V_271 = V_125 - 4 ;
else {
V_271 = V_125 / 2 ;
if ( V_271 > 18 )
V_271 = 18 ;
}
return V_271 ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_101 * V_108 )
{
struct V_103 * V_272 = F_33 ( V_108 ) ;
T_1 V_273 = F_4 ( V_274 ) ;
V_273 &= ~ ( V_275 | V_276 | V_277 ) ;
V_273 |= F_70 ( F_68 ( V_2 ,
V_272 -> V_241 . V_215 ,
V_272 -> V_241 . V_124 ) ) ;
V_273 |= F_71 ( F_68 ( V_2 ,
V_272 -> V_244 . V_215 ,
V_272 -> V_244 . V_124 ) ) ;
V_273 |= F_72 ( F_68 ( V_2 ,
V_272 -> V_105 . V_215 ,
V_272 -> V_105 . V_124 ) ) ;
F_73 ( V_2 , V_108 ) ;
F_6 ( V_274 , V_273 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
T_10 * V_260 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_120 , V_257 ;
for ( V_120 = 0 , V_257 = 0 ; V_257 < V_20 -> V_260 . V_263 ; V_257 ++ ) {
if ( V_20 -> V_260 . V_256 & ( 1 << V_257 ) ) {
V_260 -> V_264 [ V_120 ] . V_278 =
F_37 ( V_20 -> V_260 . V_279 [ V_257 ] . V_278 ) ;
V_260 -> V_264 [ V_120 ] . V_280 =
F_37 ( V_20 -> V_260 . V_279 [ V_257 ] . V_280 ) ;
V_120 ++ ;
}
}
V_260 -> V_263 = ( T_3 ) V_120 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_120 = 0 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_281 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_282 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_283 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_284 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_285 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_286 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_287 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_288 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_289 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_290 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_291 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_292 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_293 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_294 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_295 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_296 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_297 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_298 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_299 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_300 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_301 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_302 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_303 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_303 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_304 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_304 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_279 [ V_120 ] . V_278 = V_305 >> 2 ;
V_20 -> V_260 . V_279 [ V_120 ] . V_280 = V_305 >> 2 ;
V_120 ++ ;
V_20 -> V_260 . V_263 = ( T_3 ) V_120 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_252 * V_253 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_120 ;
for ( V_120 = 0 ; V_120 < V_20 -> V_260 . V_263 ; V_120 ++ )
V_253 -> V_258 [ V_120 ] =
F_4 ( V_20 -> V_260 . V_279 [ V_120 ] . V_280 << 2 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_306 * V_307 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_120 , V_257 ;
for ( V_120 = 0 ; V_120 < V_307 -> V_255 ; V_120 ++ ) {
V_20 -> V_260 . V_261 [ V_120 ] . V_262 =
V_307 -> V_124 [ V_120 ] ;
F_78 ( V_2 , V_307 -> V_124 [ V_120 ] ) ;
F_76 ( V_2 ,
& V_20 -> V_260 . V_261 [ V_120 ] ) ;
}
V_20 -> V_260 . V_255 = V_307 -> V_255 ;
V_20 -> V_260 . V_256 = 0 ;
for ( V_120 = 0 ; V_120 < V_20 -> V_260 . V_263 ; V_120 ++ ) {
for ( V_257 = 1 ; V_257 < V_307 -> V_255 ; V_257 ++ ) {
if ( V_20 -> V_260 . V_261 [ V_257 - 1 ] . V_258 [ V_120 ] !=
V_20 -> V_260 . V_261 [ V_257 ] . V_258 [ V_120 ] ) {
V_20 -> V_260 . V_256 |= ( 1 << V_120 ) ;
break;
}
}
}
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_308 = F_80 ( V_2 ) ;
struct V_306 V_307 = { 0 } ;
int V_152 ;
V_152 = F_81 ( V_2 ,
V_5 -> V_127 ,
V_308 , & V_307 ) ;
if ( V_152 )
return V_152 ;
F_77 ( V_2 , & V_307 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , T_3 V_118 )
{
T_1 V_120 , V_257 ;
T_1 V_309 = 2 ;
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) )
V_309 = 4 ;
else if ( V_2 -> V_41 == V_42 )
V_309 = 1 ;
for ( V_120 = 0 ; V_120 < V_309 ; V_120 ++ ) {
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) ) {
F_11 ( V_312 , F_83 ( V_120 ) , ~ V_313 ) ;
F_11 ( V_314 , F_83 ( V_120 ) , ~ V_313 ) ;
} else {
F_11 ( V_315 , F_84 ( V_120 ) , ~ V_316 ) ;
F_11 ( V_317 , F_84 ( V_120 ) , ~ V_316 ) ;
}
for ( V_257 = 0 ; V_257 < V_2 -> V_318 ; V_257 ++ ) {
if ( ( ( F_4 ( V_319 ) & V_320 ) >> V_321 ) == V_118 )
break;
F_9 ( 1 ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 ,
struct V_101 * V_322 )
{
struct V_103 * V_323 = F_33 ( V_322 ) ;
T_1 V_126 ;
T_1 V_324 ;
int V_120 ;
if ( F_4 ( V_325 ) & V_326 )
return;
F_78 ( V_2 , V_323 -> V_241 . V_124 ) ;
F_86 ( V_2 ) ;
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) ) {
F_6 ( V_312 , 0xf ) ;
F_6 ( V_314 , 0xf ) ;
} else {
F_6 ( V_315 , 0xf ) ;
F_6 ( V_317 , 0xf ) ;
}
for ( V_120 = 0 ; V_120 < V_2 -> V_327 ; V_120 ++ )
F_87 ( V_2 , V_120 ) ;
F_6 ( V_319 , V_328 ) ;
F_82 ( V_2 , V_328 ) ;
V_126 = F_38 ( V_2 ,
V_323 -> V_241 . V_124 ) ;
V_324 = F_88 ( V_329 ) ;
V_324 |= F_89 ( V_126 ) ;
F_6 ( V_319 , V_324 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_318 ; V_120 ++ ) {
if ( F_4 ( V_325 ) & V_326 )
break;
F_9 ( 1 ) ;
}
V_324 &= ~ V_330 ;
V_324 |= F_88 ( V_331 ) ;
F_6 ( V_319 , V_324 ) ;
F_82 ( V_2 , V_331 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_118 ;
T_1 V_120 ;
for ( V_120 = 0 ; V_120 < V_20 -> V_260 . V_263 ; V_120 ++ ) {
V_118 = F_4 ( V_20 -> V_260 . V_279 [ V_120 ] . V_280 << 2 ) ;
F_6 ( V_20 -> V_260 . V_279 [ V_120 ] . V_278 << 2 , V_118 ) ;
}
}
static void F_91 ( struct V_1 * V_2 ,
struct V_101 * V_322 )
{
struct V_103 * V_323 = F_33 ( V_322 ) ;
T_1 V_126 ;
T_1 V_324 ;
int V_120 ;
F_90 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) ) {
F_6 ( V_312 , 0xf ) ;
F_6 ( V_314 , 0xf ) ;
} else {
F_6 ( V_315 , 0xf ) ;
F_6 ( V_317 , 0xf ) ;
}
for ( V_120 = 0 ; V_120 < V_2 -> V_327 ; V_120 ++ )
F_87 ( V_2 , V_120 ) ;
F_6 ( V_319 , V_328 ) ;
F_82 ( V_2 , V_328 ) ;
V_126 = F_38 ( V_2 ,
V_323 -> V_241 . V_124 ) ;
V_324 = F_88 ( V_332 ) ;
V_324 |= F_89 ( V_126 ) ;
F_6 ( V_319 , V_324 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_318 ; V_120 ++ ) {
if ( ! ( F_4 ( V_325 ) & V_326 ) )
break;
F_9 ( 1 ) ;
}
V_324 &= ~ V_330 ;
V_324 |= F_88 ( V_331 ) ;
F_6 ( V_319 , V_324 ) ;
F_82 ( V_2 , V_331 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
T_5 * V_119 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
V_119 -> V_123 = V_20 -> V_201 ;
V_119 -> V_118 = F_37 ( V_202 ) ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_101 * V_333 ,
V_266 * V_117 )
{
struct V_103 * V_334 = F_33 ( V_333 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_335 ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_190 =
F_54 ( V_5 -> V_139 . V_140 . V_138 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_191 =
F_54 ( V_5 -> V_139 . V_140 . V_141 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_192 =
F_54 ( V_5 -> V_139 . V_140 . V_142 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_193 =
F_54 ( V_5 -> V_139 . V_140 . V_143 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_194 =
F_54 ( V_5 -> V_139 . V_140 . V_144 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_195 =
F_54 ( V_5 -> V_139 . V_140 . V_145 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_196 =
F_54 ( V_5 -> V_139 . V_140 . V_146 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_197 =
F_54 ( V_5 -> V_139 . V_140 . V_147 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_124 . V_188 . V_189 =
F_54 ( V_334 -> V_241 . V_124 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_337 =
F_54 ( V_5 -> V_139 . V_140 . V_338 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_339 =
F_54 ( V_5 -> V_139 . V_140 . V_340 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_341 =
F_54 ( V_5 -> V_139 . V_140 . V_342 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_343 =
F_54 ( V_5 -> V_139 . V_140 . V_344 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_345 =
F_54 ( V_5 -> V_139 . V_140 . V_346 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_215 . V_347 =
F_54 ( V_334 -> V_241 . V_215 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_246 = V_348 ;
V_117 -> V_336 . V_242 [ 0 ] . V_251 = 0 ;
F_36 ( V_2 ,
& V_20 -> V_231 ,
V_334 -> V_241 . V_232 ,
& V_117 -> V_336 . V_242 [ 0 ] . V_232 ) ;
if ( V_20 -> V_233 )
F_36 ( V_2 ,
& V_20 -> V_234 ,
V_334 -> V_241 . V_235 ,
& V_117 -> V_336 . V_242 [ 0 ] . V_235 ) ;
F_92 ( V_2 ,
& V_117 -> V_336 . V_242 [ 0 ] . V_236 ) ;
V_335 = F_94 ( 0xffff ) | F_95 ( 0 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_349 = F_54 ( V_335 ) ;
V_117 -> V_336 . V_242 [ 0 ] . V_350 = F_54 ( V_5 -> V_351 ) ;
if ( V_5 -> V_11 )
V_117 -> V_336 . V_242 [ 0 ] . V_210 = 1 ;
else
V_117 -> V_336 . V_242 [ 0 ] . V_210 = 0 ;
if ( V_334 -> V_241 . V_106 & V_107 )
V_117 -> V_336 . V_242 [ 0 ] . V_211 = 1 ;
else
V_117 -> V_336 . V_242 [ 0 ] . V_211 = 0 ;
if ( V_5 -> V_127 ) {
V_117 -> V_336 . V_242 [ 0 ] . V_227 =
F_38 ( V_2 ,
V_334 -> V_241 . V_124 ) ;
if ( V_334 -> V_241 . V_124 > V_5 -> V_223 )
V_117 -> V_336 . V_242 [ 0 ] . V_216 = V_224 | V_226 ;
else
V_117 -> V_336 . V_242 [ 0 ] . V_216 = 0 ;
}
V_117 -> V_336 . V_242 [ 1 ] = V_117 -> V_336 . V_242 [ 0 ] ;
V_117 -> V_336 . V_242 [ 2 ] = V_117 -> V_336 . V_242 [ 0 ] ;
V_117 -> V_336 . V_106 |= V_240 ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 ,
V_266 * V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_138 =
V_5 -> V_139 . V_140 . V_138 ;
T_1 V_141 =
V_5 -> V_139 . V_140 . V_141 ;
T_1 V_142 =
V_5 -> V_139 . V_140 . V_142 ;
T_1 V_143 =
V_5 -> V_139 . V_140 . V_143 ;
T_1 V_352 =
V_5 -> V_139 . V_140 . V_338 ;
T_1 V_353 =
V_5 -> V_139 . V_140 . V_340 ;
T_1 V_354 =
V_5 -> V_139 . V_140 . V_342 ;
T_1 V_144 =
V_5 -> V_139 . V_140 . V_144 ;
T_1 V_145 =
V_5 -> V_139 . V_140 . V_145 ;
V_117 -> V_355 = V_117 -> V_336 ;
V_117 -> V_355 . V_106 &= ~ V_240 ;
if ( V_5 -> V_356 ) {
F_36 ( V_2 ,
& V_20 -> V_231 ,
V_5 -> V_356 ,
& V_117 -> V_355 . V_242 [ 0 ] . V_232 ) ;
if ( V_5 -> V_99 ) {
if ( V_5 -> V_357 )
V_117 -> V_355 . V_242 [ 0 ] . V_210 = 1 ;
else
V_117 -> V_355 . V_242 [ 0 ] . V_210 = 0 ;
} else
V_117 -> V_355 . V_242 [ 0 ] . V_210 = 0 ;
if ( V_5 -> V_357 )
V_117 -> V_355 . V_242 [ 0 ] . V_211 = 1 ;
else
V_117 -> V_355 . V_242 [ 0 ] . V_211 = 0 ;
} else {
F_36 ( V_2 ,
& V_20 -> V_231 ,
V_5 -> V_358 ,
& V_117 -> V_355 . V_242 [ 0 ] . V_232 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_210 = 0 ;
}
if ( V_20 -> V_359 ) {
if ( V_20 -> V_233 ) {
F_36 ( V_2 ,
& V_20 -> V_234 ,
V_20 -> V_359 ,
& V_117 -> V_355 . V_242 [ 0 ] . V_235 ) ;
}
}
V_138 &= ~ V_167 ;
V_141 |= V_360 | V_361 ;
if ( V_5 -> V_127 )
V_142 &= ~ V_167 ;
V_143 |= V_360 | V_361 | V_362 ;
V_144 |= ( V_363 |
V_364 |
V_365 |
V_366 |
V_367 |
V_368 |
V_369 |
V_370 ) ;
V_144 &= ~ ( V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ) ;
V_145 |= ( V_371 |
V_372 |
V_373 |
V_374 |
V_375 |
V_376 |
V_377 |
V_378 ) ;
if ( V_2 -> V_41 <= V_311 )
V_352 |= V_379 | V_380 | V_381 ;
V_353 &= ~ V_382 ;
V_353 |= F_97 ( 4 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_190 =
F_54 ( V_138 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_191 =
F_54 ( V_141 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_192 =
F_54 ( V_142 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_193 =
F_54 ( V_143 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_194 =
F_54 ( V_144 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_195 = F_54 ( V_145 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_124 . V_188 . V_189 = 0 ;
V_117 -> V_355 . V_242 [ 0 ] . V_215 . V_337 =
F_54 ( V_352 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_215 . V_339 =
F_54 ( V_353 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_215 . V_341 =
F_54 ( V_354 ) ;
V_117 -> V_355 . V_242 [ 0 ] . V_215 . V_347 = 0 ;
F_55 ( V_2 , 0 , & V_117 -> V_355 . V_242 [ 0 ] . V_236 ) ;
if ( V_20 -> V_250 )
V_117 -> V_355 . V_242 [ 0 ] . V_251 = 1 ;
V_117 -> V_355 . V_242 [ 1 ] = V_117 -> V_355 . V_242 [ 0 ] ;
V_117 -> V_355 . V_242 [ 2 ] = V_117 -> V_355 . V_242 [ 0 ] ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_116 * V_383 )
{
unsigned int V_120 , V_384 ;
if ( V_383 -> V_121 <= V_385 )
return;
V_384 = V_383 -> V_121 - V_385 ;
for ( V_120 = 0 ; V_120 < V_385 ; V_120 ++ )
V_383 -> V_122 [ V_120 ] = V_383 -> V_122 [ V_120 + V_384 ] ;
V_383 -> V_121 = V_385 ;
}
int F_99 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
int V_152 ;
V_152 = F_100 ( V_2 , V_386 , 0 ,
& V_20 -> V_231 ) ;
if ( V_152 )
return V_152 ;
if ( V_20 -> V_231 . V_121 > V_385 )
F_98 ( V_2 ,
& V_20 -> V_231 ) ;
if ( V_20 -> V_233 ) {
V_152 = F_100 ( V_2 , V_387 , 0 ,
& V_20 -> V_234 ) ;
if ( V_152 )
return V_152 ;
if ( V_20 -> V_234 . V_121 > V_385 )
F_98 ( V_2 ,
& V_20 -> V_234 ) ;
}
return 0 ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_116 * V_383 ,
V_266 * V_117 )
{
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_383 -> V_121 ; V_120 ++ ) {
V_117 -> V_388 [ V_120 ] = 0 ;
V_117 -> V_389 [ V_120 ] |= F_54 ( V_383 -> V_122 [ V_120 ] . V_390 ) ;
}
}
int F_102 ( struct V_1 * V_2 ,
V_266 * V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
unsigned char V_120 ;
if ( V_20 -> V_231 . V_121 ) {
F_101 ( V_2 ,
& V_20 -> V_231 ,
V_117 ) ;
V_117 -> V_391 . V_392 [ V_393 ] = 0 ;
V_117 -> V_391 . V_394 [ V_393 ] =
F_54 ( V_20 -> V_231 . V_395 ) ;
for ( V_120 = 0 ; V_120 < V_20 -> V_231 . V_121 ; V_120 ++ ) {
if ( V_5 -> V_396 <=
V_20 -> V_231 . V_122 [ V_120 ] . V_118 ) {
V_117 -> V_397 = V_120 ;
break;
}
}
}
if ( V_20 -> V_234 . V_121 ) {
F_101 ( V_2 ,
& V_20 -> V_234 ,
V_117 ) ;
V_117 -> V_391 . V_392 [ V_398 ] = 0 ;
V_117 -> V_391 . V_394 [ V_398 ] =
F_54 ( V_20 -> V_231 . V_395 ) ;
}
return 0 ;
}
static T_1 F_103 ( struct V_399 * V_400 )
{
if ( ( V_400 -> V_401 == V_402 ) ||
( V_400 -> V_401 == V_403 ) )
return 30000 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_3 V_308 ;
struct V_399 V_400 ;
T_1 V_6 = F_4 ( V_17 ) ;
if ( ! ( V_6 & V_404 ) ) {
V_20 -> V_201 = 0 ;
V_20 -> V_204 = 1 ;
V_5 -> V_200 = false ;
return 0 ;
}
if ( V_6 & V_405 )
V_20 -> V_201 = 1 ;
else
V_20 -> V_201 = 0 ;
V_20 -> V_204 =
( V_20 -> V_201 == 0 ) ? 1 : 0 ;
V_308 = F_80 ( V_2 ) ;
if ( F_105 ( V_2 , V_308 , & V_400 ) ) {
V_5 -> V_200 = false ;
return 0 ;
}
V_5 -> V_203 =
F_103 ( & V_400 ) ;
if ( V_5 -> V_203 == 0 ) {
V_5 -> V_200 = false ;
return 0 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_101 * V_322 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_266 * V_117 = & V_5 -> V_406 ;
int V_152 ;
memset ( V_117 , 0 , sizeof( V_266 ) ) ;
F_102 ( V_2 , V_117 ) ;
switch ( V_2 -> V_407 . V_408 ) {
case V_409 :
case V_410 :
V_117 -> V_411 = V_412 ;
break;
case V_413 :
V_117 -> V_411 = V_414 ;
break;
default:
V_117 -> V_411 = V_415 ;
break;
}
if ( V_2 -> V_407 . V_416 . V_417 & V_418 )
V_117 -> V_419 |= V_420 ;
if ( V_2 -> V_407 . V_416 . V_417 & V_421 )
V_117 -> V_419 |= V_422 ;
if ( V_2 -> V_407 . V_416 . V_417 & V_423 )
V_117 -> V_419 |= V_424 ;
if ( V_5 -> V_127 )
V_117 -> V_419 |= V_425 ;
V_152 = F_93 ( V_2 , V_322 , V_117 ) ;
if ( V_152 )
return V_152 ;
V_152 = F_96 ( V_2 , V_117 ) ;
if ( V_152 )
return V_152 ;
V_117 -> V_267 = V_117 -> V_336 ;
return F_66 ( V_2 ,
V_5 -> V_265 ,
( T_3 * ) V_117 , sizeof( V_266 ) ,
V_5 -> V_268 ) ;
}
int F_107 ( struct V_1 * V_2 ,
struct V_101 * V_322 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
struct V_103 * V_323 = F_33 ( V_322 ) ;
T_10 V_260 = { 0 } ;
F_24 ( V_2 ,
V_426 , 1 ) ;
F_74 ( V_2 , & V_260 ) ;
F_62 ( V_2 ,
& V_323 -> V_241 ,
& V_260 . V_254 [ 0 ] ) ;
F_61 ( & V_20 -> V_260 . V_261 [ 0 ] ,
& V_260 . V_254 [ 1 ] , V_20 -> V_260 . V_263 ,
V_20 -> V_260 . V_256 ) ;
F_63 ( V_2 , V_322 , & V_260 ) ;
return F_66 ( V_2 , V_20 -> V_269 ,
( T_3 * ) & V_260 , sizeof( T_10 ) ,
V_5 -> V_268 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
T_1 V_6 ;
int V_152 ;
V_152 = F_109 ( V_2 ,
V_427 +
V_428 ,
& V_6 , V_5 -> V_268 ) ;
if ( V_152 )
return V_152 ;
V_5 -> V_265 = ( T_4 ) V_6 ;
V_152 = F_109 ( V_2 ,
V_427 +
V_429 ,
& V_6 , V_5 -> V_268 ) ;
if ( V_152 )
return V_152 ;
V_5 -> V_430 = ( T_4 ) V_6 ;
V_152 = F_109 ( V_2 ,
V_427 +
V_431 ,
& V_6 , V_5 -> V_268 ) ;
if ( V_152 )
return V_152 ;
V_20 -> V_269 = ( T_4 ) V_6 ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
T_1 V_6 = F_4 ( V_432 ) ;
V_6 &= ~ ( V_433 | V_434 ) ;
V_6 |= ( F_111 ( V_435 ) |
F_112 ( V_435 ) ) ;
V_6 &= ~ ( V_436 | V_437 ) ;
V_6 |= ( F_113 ( V_438 ) |
F_114 ( V_435 ) ) ;
F_6 ( V_432 , V_6 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
T_1 V_6 , V_439 ;
int V_120 ;
V_6 = F_4 ( V_432 ) & ~ ( V_433 | V_434 ) ;
if ( V_2 -> V_407 . V_416 . V_440 > 0 )
V_6 |= F_111 ( V_441 ) ;
else
V_6 |= F_111 ( V_435 ) ;
if ( V_2 -> V_407 . V_416 . V_440 > 1 )
V_6 |= F_112 ( V_441 ) ;
else
V_6 |= F_112 ( V_435 ) ;
F_6 ( V_432 , V_6 ) ;
V_6 = F_4 ( V_442 ) ;
V_439 = ( V_6 & V_443 ) >> V_444 ;
if ( ( V_2 -> V_407 . V_416 . V_440 > 0 ) &&
( ! ( V_2 -> V_407 . V_416 . V_445 & ( 1 << V_439 ) ) ) ) {
for ( V_120 = 0 ; V_120 < V_2 -> V_327 ; V_120 ++ ) {
if ( V_2 -> V_407 . V_416 . V_445 & ( 1 << V_120 ) )
break;
}
if ( V_120 == V_2 -> V_327 )
V_439 = 0 ;
else
V_439 = V_120 ;
V_6 &= ~ V_443 ;
V_6 |= F_116 ( V_439 ) ;
F_6 ( V_442 , V_6 ) ;
}
F_20 ( V_2 , V_2 -> V_407 . V_416 . V_440 > 0 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 ) ;
if ( V_20 -> V_446 )
V_20 -> V_97 = false ;
if ( V_20 -> V_446 )
F_30 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
struct V_101 * V_447 = V_2 -> V_407 . V_416 . V_447 ;
int V_152 ;
if ( V_5 -> V_448 )
F_125 ( V_2 ) ;
if ( F_126 ( V_2 ) )
return - V_84 ;
if ( V_5 -> V_449 ) {
F_127 ( V_2 , true ) ;
V_152 = F_99 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_1 ) ;
return V_152 ;
}
}
if ( V_5 -> V_200 ) {
V_152 = F_104 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_2 ) ;
return V_152 ;
}
}
if ( V_20 -> V_250 ) {
F_75 ( V_2 ) ;
F_91 ( V_2 , V_447 ) ;
V_152 = F_79 ( V_2 ) ;
if ( V_152 )
V_20 -> V_250 = false ;
F_85 ( V_2 , V_447 ) ;
}
if ( V_2 -> V_407 . V_416 . V_417 & V_450 )
F_129 ( V_2 , true ) ;
if ( V_5 -> V_451 )
F_16 ( V_2 , true ) ;
if ( V_5 -> V_452 )
F_130 ( V_2 , true ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
F_110 ( V_2 ) ;
F_137 ( V_2 ) ;
if ( V_5 -> V_453 )
F_10 ( V_2 , true ) ;
V_152 = F_138 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_3 ) ;
return V_152 ;
}
V_152 = F_108 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_4 ) ;
return V_152 ;
}
V_152 = F_106 ( V_2 , V_447 ) ;
if ( V_152 ) {
F_128 ( L_5 ) ;
return V_152 ;
}
if ( V_20 -> V_250 ) {
V_152 = F_107 ( V_2 , V_447 ) ;
if ( V_152 ) {
F_128 ( L_6 ) ;
return V_152 ;
}
}
F_22 ( V_2 ) ;
F_139 ( V_2 ) ;
V_152 = F_20 ( V_2 , false ) ;
if ( V_152 ) {
F_128 ( L_7 ) ;
return V_152 ;
}
F_18 ( V_2 , true ) ;
if ( V_20 -> V_454 )
F_19 ( V_2 , true ) ;
F_17 ( V_2 ) ;
if ( V_5 -> V_448 )
F_12 ( V_2 , true ) ;
if ( V_5 -> V_455 )
F_15 ( V_2 , true ) ;
F_140 ( V_2 , V_456 , true ) ;
return 0 ;
}
void F_141 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_13 ( V_2 ) ;
struct V_101 * V_447 = V_2 -> V_407 . V_416 . V_447 ;
if ( ! F_126 ( V_2 ) )
return;
F_142 ( V_2 ) ;
if ( V_5 -> V_452 )
F_130 ( V_2 , false ) ;
if ( V_5 -> V_453 )
F_10 ( V_2 , false ) ;
if ( V_2 -> V_457 . V_458 &&
F_143 ( V_2 -> V_407 . V_408 ) ) {
V_2 -> V_457 . V_459 = false ;
F_144 ( V_2 ) ;
}
if ( V_5 -> V_448 )
F_12 ( V_2 , false ) ;
if ( V_5 -> V_455 )
F_15 ( V_2 , false ) ;
F_145 ( V_2 ) ;
F_146 ( V_2 ) ;
F_16 ( V_2 , false ) ;
if ( V_20 -> V_250 )
F_85 ( V_2 , V_447 ) ;
F_147 ( V_2 ) ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_13 ( V_2 ) ;
struct V_101 * V_460 = V_2 -> V_407 . V_416 . V_461 ;
struct V_101 * V_462 = V_2 -> V_407 . V_416 . V_463 ;
int V_152 ;
V_152 = F_149 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_8 ) ;
return V_152 ;
}
if ( V_20 -> V_446 )
F_35 ( V_2 , V_460 , V_462 ) ;
F_150 ( V_2 , V_460 , V_462 ) ;
V_152 = F_151 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_9 ) ;
return V_152 ;
}
V_152 = F_64 ( V_2 , V_460 ) ;
if ( V_152 ) {
F_128 ( L_10 ) ;
return V_152 ;
}
if ( V_20 -> V_250 ) {
V_152 = F_67 ( V_2 , V_460 ) ;
if ( V_152 ) {
F_128 ( L_11 ) ;
return V_152 ;
}
}
F_69 ( V_2 , V_460 ) ;
V_152 = F_152 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_12 ) ;
return V_152 ;
}
V_152 = F_153 ( V_2 ) ;
if ( V_152 ) {
F_128 ( L_13 ) ;
return V_152 ;
}
F_154 ( V_2 , V_460 , V_462 ) ;
if ( V_20 -> V_446 )
F_34 ( V_2 , V_460 , V_462 ) ;
return 0 ;
}
void F_155 ( struct V_1 * V_2 )
{
F_149 ( V_2 ) ;
F_156 ( V_2 ) ;
}
void F_157 ( struct V_1 * V_2 )
{
F_115 ( V_2 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_19 * V_20 ;
struct V_148 V_149 ;
int V_152 ;
V_20 = F_159 ( sizeof( struct V_19 ) , V_464 ) ;
if ( V_20 == NULL )
return - V_465 ;
V_2 -> V_407 . V_416 . V_466 = V_20 ;
V_5 = & V_20 -> V_467 ;
F_120 ( V_2 ) ;
V_20 -> V_468 . V_469 = false ;
V_5 -> V_356 = 0 ;
V_20 -> V_359 = 0 ;
V_5 -> V_358 = 0 ;
V_5 -> V_396 = 0 ;
V_152 = F_160 ( V_2 ) ;
if ( V_152 )
return V_152 ;
V_152 = F_161 ( V_2 ) ;
if ( V_152 )
return V_152 ;
if ( V_2 -> V_407 . V_416 . V_470 == 0 )
V_2 -> V_407 . V_416 . V_470 = V_471 ;
if ( V_2 -> V_407 . V_416 . V_472 == 0 )
V_2 -> V_407 . V_416 . V_472 = V_473 ;
V_152 = F_42 ( V_2 , V_474 ,
0 , false , & V_149 ) ;
if ( V_152 )
V_5 -> V_163 = V_149 . V_163 + 1 ;
else
V_5 -> V_163 = V_475 ;
V_5 -> V_128 = 40000 ;
V_5 -> V_223 = 40000 ;
V_20 -> V_225 = 40000 ;
V_5 -> V_476 = V_477 ;
V_5 -> V_478 = V_479 ;
V_5 -> V_480 = V_481 ;
V_5 -> V_482 = V_483 ;
V_5 -> V_449 =
F_162 ( V_2 , V_386 , 0 ) ;
V_5 -> V_200 =
F_162 ( V_2 , V_484 , 0 ) ;
V_20 -> V_233 =
F_162 ( V_2 , V_387 , 0 ) ;
F_163 ( V_2 ) ;
V_5 -> V_485 = V_486 ;
V_5 -> V_487 = V_488 ;
V_5 -> V_489 = V_490 ;
V_5 -> V_491 = false ;
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) )
V_5 -> V_448 = false ;
else
V_5 -> V_448 = true ;
V_5 -> V_455 = true ;
V_5 -> V_55 = true ;
V_20 -> V_492 = false ;
V_20 -> V_220 = false ;
V_5 -> V_453 = true ;
if ( V_2 -> V_407 . V_408 != V_413 )
V_5 -> V_452 = true ;
else
V_5 -> V_452 = false ;
V_5 -> V_493 = true ;
if ( V_2 -> V_106 & V_494 )
V_5 -> V_495 = true ;
else
V_5 -> V_495 = false ;
V_5 -> V_496 = true ;
V_20 -> V_250 = true ;
V_20 -> V_497 = true ;
V_20 -> V_57 = true ;
V_20 -> V_21 = true ;
V_20 -> V_454 = true ;
#if F_28 ( V_93 )
V_20 -> V_446 =
F_164 ( V_2 ) ;
#else
V_20 -> V_446 = false ;
#endif
if ( ( V_2 -> V_41 == V_310 ) ||
( V_2 -> V_41 == V_311 ) ||
( V_2 -> V_41 == V_498 ) )
V_20 -> V_230 = true ;
else
V_20 -> V_230 = false ;
V_20 -> V_220 = false ;
V_5 -> V_217 = 0 ;
V_5 -> V_268 = V_499 ;
return 0 ;
}
void F_165 ( struct V_1 * V_2 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_2 -> V_407 . V_416 . V_500 ; V_120 ++ ) {
F_166 ( V_2 -> V_407 . V_416 . V_501 [ V_120 ] . V_502 ) ;
}
F_166 ( V_2 -> V_407 . V_416 . V_501 ) ;
F_166 ( V_2 -> V_407 . V_416 . V_466 ) ;
}
bool F_167 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_503 = F_168 ( V_2 ) ;
T_1 V_504 = V_5 -> V_127 ? 450 : 0 ;
if ( V_503 < V_504 )
return true ;
else
return false ;
}
