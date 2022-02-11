static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
V_5 = F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
F_3 ( V_8 , V_9 ) ;
( void ) F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_10 , ( ( V_3 ) & 0xff ) ) ;
( void ) F_4 ( V_10 ) ;
V_5 = F_4 ( V_11 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_10 , ( ( V_3 ) & 0xff ) ) ;
( void ) F_4 ( V_10 ) ;
F_3 ( V_11 , ( V_9 ) ) ;
( void ) F_4 ( V_11 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_12 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
V_5 = F_4 ( V_14 ) ;
F_5 ( & V_2 -> V_12 , V_4 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_12 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
F_3 ( V_14 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_12 , V_4 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
bool V_15 , T_1 V_16 ,
T_1 V_17 , T_1 V_18 )
{
if ( V_15 ) {
T_2 V_19 ;
unsigned V_20 = ( V_16 == 0xffffffff ) ? 0 : V_16 ;
unsigned V_21 = ( V_17 == 0xffffffff ) ? 0 : V_17 ;
switch ( V_18 ) {
case V_22 :
return V_2 -> V_23 . V_24 . V_25 [ V_20 ] [ V_21 ] . V_26 ;
case V_27 :
return V_2 -> V_23 . V_24 . V_25 [ V_20 ] [ V_21 ] . V_28 ;
case V_29 :
return V_2 -> V_23 . V_24 . V_25 [ V_20 ] [ V_21 ] . V_30 ;
}
F_12 ( & V_2 -> V_31 ) ;
if ( V_16 != 0xffffffff || V_17 != 0xffffffff )
F_13 ( V_2 , V_16 , V_17 , 0xffffffff ) ;
V_19 = F_4 ( V_18 ) ;
if ( V_16 != 0xffffffff || V_17 != 0xffffffff )
F_13 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_14 ( & V_2 -> V_31 ) ;
return V_19 ;
} else {
unsigned V_32 ;
switch ( V_18 ) {
case V_33 :
return V_2 -> V_23 . V_24 . V_34 ;
case V_35 :
return V_2 -> V_23 . V_24 . V_36 ;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_32 = ( V_18 - V_37 ) ;
return V_2 -> V_23 . V_24 . V_69 [ V_32 ] ;
default:
return F_4 ( V_18 ) ;
}
}
}
static int F_15 ( struct V_1 * V_2 , T_1 V_16 ,
T_1 V_17 , T_1 V_18 , T_1 * V_70 )
{
T_2 V_71 ;
* V_70 = 0 ;
for ( V_71 = 0 ; V_71 < F_16 ( V_72 ) ; V_71 ++ ) {
bool V_15 = V_72 [ V_71 ] . V_73 ;
if ( V_18 != V_72 [ V_71 ] . V_18 )
continue;
* V_70 = F_11 ( V_2 , V_15 , V_16 , V_17 ,
V_18 ) ;
return 0 ;
}
return - V_74 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
T_1 V_75 ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
T_1 V_78 = 0 ;
T_1 V_79 ;
bool V_5 ;
V_75 = F_4 ( V_80 ) ;
if ( V_2 -> V_81 . V_82 ) {
V_76 = F_4 ( V_83 ) ;
V_77 = F_4 ( V_84 ) ;
V_78 = F_4 ( V_85 ) ;
}
V_79 = F_4 ( V_86 ) ;
F_3 ( V_80 , ( V_75 & ~ V_87 ) ) ;
if ( V_2 -> V_81 . V_82 ) {
F_3 ( V_83 ,
( V_76 & ~ ( V_88 |
V_89 ) ) ) ;
F_3 ( V_84 ,
( V_77 & ~ ( V_88 |
V_89 ) ) ) ;
F_3 ( V_85 ,
( V_78 & V_90 ) ) ;
}
F_3 ( V_86 , V_79 | V_91 ) ;
V_5 = F_18 ( V_2 ) ;
F_3 ( V_80 , V_75 ) ;
if ( V_2 -> V_81 . V_82 ) {
F_3 ( V_83 , V_76 ) ;
F_3 ( V_84 , V_77 ) ;
F_3 ( V_85 , V_78 ) ;
}
F_3 ( V_86 , V_79 ) ;
return V_5 ;
}
static bool F_19 ( struct V_1 * V_2 ,
T_3 * V_92 , T_1 V_93 )
{
T_1 * V_94 ;
T_1 V_71 , V_95 ;
if ( V_92 == NULL )
return false ;
if ( V_93 == 0 )
return false ;
if ( V_2 -> V_4 & V_96 )
return false ;
V_94 = ( T_1 * ) V_92 ;
V_95 = F_20 ( V_93 , 4 ) / 4 ;
F_3 ( V_97 , 0 ) ;
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ )
V_94 [ V_71 ] = F_4 ( V_98 ) ;
return true ;
}
static int F_21 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
return F_4 ( V_99 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_100 )
{
T_2 V_101 ;
V_101 = F_4 ( V_102 ) ;
if ( V_100 == false ) {
V_101 &= ~ ( 1 << 0 ) ;
V_101 |= ( 1 << 1 ) ;
} else {
V_101 &= ~ ( 1 << 1 ) ;
}
F_3 ( V_102 , V_101 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_1 V_103 = V_2 -> clock . V_104 . V_105 ;
T_1 V_106 ;
V_106 = F_4 ( V_107 ) ;
if ( V_106 & V_108 )
return V_109 ;
V_106 = F_4 ( V_110 ) ;
if ( V_106 & V_111 )
return V_103 / 4 ;
return V_103 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_112 , T_1 V_113 )
{
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( F_27 () )
V_2 -> V_114 . V_115 |= V_116 ;
}
static T_2 F_28 ( struct V_1 * V_2 )
{
return ( F_4 ( V_117 ) & V_118 )
>> V_119 ;
}
static int F_29 ( void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
V_2 -> V_121 = & F_9 ;
V_2 -> V_122 = & F_10 ;
V_2 -> V_123 = & F_1 ;
V_2 -> V_124 = & F_6 ;
V_2 -> V_125 = & F_7 ;
V_2 -> V_126 = & F_8 ;
V_2 -> V_127 = NULL ;
V_2 -> V_128 = NULL ;
V_2 -> V_129 = NULL ;
V_2 -> V_130 = NULL ;
V_2 -> V_131 = & V_132 ;
V_2 -> V_133 = F_28 ( V_2 ) ;
V_2 -> V_134 = 0xFF ;
switch ( V_2 -> V_135 ) {
case V_136 :
V_2 -> V_137 =
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ;
V_2 -> V_150 = 0 ;
V_2 -> V_134 = ( V_2 -> V_133 == 0 ) ? 1 :
( V_2 -> V_133 == 1 ) ? 5 : 6 ;
break;
case V_151 :
V_2 -> V_137 =
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_152 |
V_153 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ;
V_2 -> V_150 = 0 ;
V_2 -> V_134 = V_2 -> V_133 + 20 ;
break;
case V_154 :
V_2 -> V_137 =
V_138 |
V_139 |
V_140 |
V_141 |
V_155 |
V_142 |
V_153 |
V_143 |
V_144 |
V_156 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ;
V_2 -> V_150 = 0 ;
V_2 -> V_134 = V_2 -> V_133 + 40 ;
break;
case V_157 :
V_2 -> V_137 =
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_152 |
V_153 |
V_143 |
V_144 |
V_145 |
V_147 |
V_148 |
V_149 ;
V_2 -> V_150 = 0 ;
V_2 -> V_134 = 60 ;
break;
case V_158 :
V_2 -> V_137 =
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_152 |
V_153 |
V_143 |
V_144 |
V_145 |
V_148 |
V_149 ;
V_2 -> V_150 = 0 ;
V_2 -> V_134 = 70 ;
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_30 ( void * V_120 )
{
return 0 ;
}
static int F_31 ( void * V_120 )
{
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_135 ) {
case V_136 :
F_33 ( V_2 ,
V_159 ,
( const T_1 ) F_16 ( V_159 ) ) ;
F_33 ( V_2 ,
V_160 ,
( const T_1 ) F_16 ( V_160 ) ) ;
F_33 ( V_2 ,
V_161 ,
( const T_1 ) F_16 ( V_161 ) ) ;
F_33 ( V_2 ,
V_162 ,
( const T_1 ) F_16 ( V_162 ) ) ;
break;
case V_151 :
F_33 ( V_2 ,
V_163 ,
( const T_1 ) F_16 ( V_163 ) ) ;
F_33 ( V_2 ,
V_164 ,
( const T_1 ) F_16 ( V_164 ) ) ;
F_33 ( V_2 ,
V_165 ,
( const T_1 ) F_16 ( V_165 ) ) ;
break;
case V_154 :
F_33 ( V_2 ,
V_166 ,
( const T_1 ) F_16 ( V_166 ) ) ;
F_33 ( V_2 ,
V_167 ,
( const T_1 ) F_16 ( V_167 ) ) ;
F_33 ( V_2 ,
V_168 ,
( const T_1 ) F_16 ( V_168 ) ) ;
F_33 ( V_2 ,
V_169 ,
( const T_1 ) F_16 ( V_169 ) ) ;
break;
case V_157 :
F_33 ( V_2 ,
V_170 ,
( const T_1 ) F_16 ( V_170 ) ) ;
F_33 ( V_2 ,
V_171 ,
( const T_1 ) F_16 ( V_171 ) ) ;
F_33 ( V_2 ,
V_172 ,
( const T_1 ) F_16 ( V_172 ) ) ;
break;
case V_158 :
F_33 ( V_2 ,
V_173 ,
( const T_1 ) F_16 ( V_173 ) ) ;
F_33 ( V_2 ,
V_174 ,
( const T_1 ) F_16 ( V_174 ) ) ;
F_33 ( V_2 ,
V_175 ,
( const T_1 ) F_16 ( V_175 ) ) ;
break;
default:
F_34 () ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_176 * V_177 = V_2 -> V_178 -> V_179 -> V_180 ;
int V_181 , V_182 ;
T_1 V_183 , V_184 , V_185 ;
int V_186 , V_71 ;
T_4 V_187 ;
if ( F_36 ( V_2 -> V_178 -> V_179 ) )
return;
if ( V_188 == 0 )
return;
if ( V_2 -> V_4 & V_96 )
return;
V_186 = F_37 ( V_2 -> V_189 , & V_184 ) ;
if ( V_186 != 0 )
return;
if ( ! ( V_184 & ( V_190 | V_191 ) ) )
return;
V_183 = F_38 ( V_192 ) ;
V_185 = ( V_183 & V_193 ) >>
V_194 ;
if ( V_184 & V_191 ) {
if ( V_185 == 2 ) {
F_39 ( L_1 ) ;
return;
}
F_39 ( L_2 ) ;
} else if ( V_184 & V_190 ) {
if ( V_185 == 1 ) {
F_39 ( L_3 ) ;
return;
}
F_39 ( L_4 ) ;
}
V_181 = F_40 ( V_177 ) ;
if ( ! V_181 )
return;
V_182 = F_40 ( V_2 -> V_178 ) ;
if ( ! V_182 )
return;
if ( V_184 & V_191 ) {
if ( V_185 != 2 ) {
T_4 V_195 , V_196 ;
T_4 V_197 , V_198 ;
T_1 V_199 , V_200 , V_106 ;
F_41 ( V_177 , V_181 + V_201 , & V_195 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_201 , & V_196 ) ;
V_187 = V_195 | V_202 ;
F_42 ( V_177 , V_181 + V_201 , V_187 ) ;
V_187 = V_196 | V_202 ;
F_42 ( V_2 -> V_178 , V_182 + V_201 , V_187 ) ;
V_106 = F_43 ( V_203 ) ;
V_199 = ( V_106 & V_204 ) >> V_205 ;
V_200 = ( V_106 & V_206 ) >> V_207 ;
if ( V_200 < V_199 ) {
V_106 = F_38 ( V_208 ) ;
if ( V_106 & V_209 ) {
V_106 &= ~ ( V_210 | V_211 ) ;
V_106 |= ( V_199 << V_212 ) ;
V_106 |= V_213 | V_214 | V_215 ;
F_44 ( V_208 , V_106 ) ;
}
}
for ( V_71 = 0 ; V_71 < 10 ; V_71 ++ ) {
F_41 ( V_2 -> V_178 , V_182 + V_216 , & V_187 ) ;
if ( V_187 & V_217 )
break;
F_41 ( V_177 , V_181 + V_201 , & V_195 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_201 , & V_196 ) ;
F_41 ( V_177 , V_181 + V_218 , & V_197 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_218 , & V_198 ) ;
V_106 = F_38 ( V_219 ) ;
V_106 |= V_220 ;
F_44 ( V_219 , V_106 ) ;
V_106 = F_38 ( V_219 ) ;
V_106 |= V_221 ;
F_44 ( V_219 , V_106 ) ;
F_45 ( 100 ) ;
F_41 ( V_177 , V_181 + V_201 , & V_187 ) ;
V_187 &= ~ V_202 ;
V_187 |= ( V_195 & V_202 ) ;
F_42 ( V_177 , V_181 + V_201 , V_187 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_201 , & V_187 ) ;
V_187 &= ~ V_202 ;
V_187 |= ( V_196 & V_202 ) ;
F_42 ( V_2 -> V_178 , V_182 + V_201 , V_187 ) ;
F_41 ( V_177 , V_181 + V_218 , & V_187 ) ;
V_187 &= ~ ( ( 1 << 4 ) | ( 7 << 9 ) ) ;
V_187 |= ( V_197 & ( ( 1 << 4 ) | ( 7 << 9 ) ) ) ;
F_42 ( V_177 , V_181 + V_218 , V_187 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_218 , & V_187 ) ;
V_187 &= ~ ( ( 1 << 4 ) | ( 7 << 9 ) ) ;
V_187 |= ( V_198 & ( ( 1 << 4 ) | ( 7 << 9 ) ) ) ;
F_42 ( V_2 -> V_178 , V_182 + V_218 , V_187 ) ;
V_106 = F_38 ( V_219 ) ;
V_106 &= ~ V_220 ;
F_44 ( V_219 , V_106 ) ;
}
}
}
V_183 |= V_222 | V_223 ;
V_183 &= ~ V_224 ;
F_44 ( V_192 , V_183 ) ;
F_41 ( V_2 -> V_178 , V_182 + V_218 , & V_187 ) ;
V_187 &= ~ 0xf ;
if ( V_184 & V_191 )
V_187 |= 3 ;
else if ( V_184 & V_190 )
V_187 |= 2 ;
else
V_187 |= 1 ;
F_42 ( V_2 -> V_178 , V_182 + V_218 , V_187 ) ;
V_183 = F_38 ( V_192 ) ;
V_183 |= V_225 ;
F_44 ( V_192 , V_183 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_226 ; V_71 ++ ) {
V_183 = F_38 ( V_192 ) ;
if ( ( V_183 & V_225 ) == 0 )
break;
F_46 ( 1 ) ;
}
}
static inline T_1 F_47 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_227 , ( ( V_3 ) & 0xffff ) ) ;
V_5 = F_4 ( V_228 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static inline void F_48 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_227 , ( ( V_3 ) & 0xffff ) ) ;
F_3 ( V_228 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static inline T_1 F_49 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_229 , ( ( V_3 ) & 0xffff ) ) ;
V_5 = F_4 ( V_230 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static inline void F_50 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_229 , ( ( V_3 ) & 0xffff ) ) ;
F_3 ( V_230 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_231 , V_232 ;
bool V_233 = false , V_234 = false , V_235 = false ;
bool V_236 = false ;
if ( V_237 == 0 )
return;
if ( V_2 -> V_4 & V_96 )
return;
V_232 = V_231 = F_38 ( V_238 ) ;
V_231 &= ~ V_239 ;
V_231 |= F_52 ( 0x24 ) | V_240 ;
if ( V_232 != V_231 )
F_44 ( V_238 , V_231 ) ;
V_232 = V_231 = F_38 ( V_241 ) ;
V_231 |= V_242 ;
if ( V_232 != V_231 )
F_44 ( V_241 , V_231 ) ;
V_232 = V_231 = F_43 ( V_243 ) ;
V_231 |= V_244 ;
if ( V_232 != V_231 )
F_53 ( V_243 , V_231 ) ;
V_232 = V_231 = F_38 ( V_245 ) ;
V_231 &= ~ ( V_246 | V_247 ) ;
V_231 |= V_248 ;
if ( ! V_233 )
V_231 |= F_54 ( 7 ) ;
if ( ! V_234 ) {
V_231 |= F_55 ( 7 ) ;
V_231 &= ~ V_248 ;
if ( V_232 != V_231 )
F_44 ( V_245 , V_231 ) ;
if ( ! V_235 ) {
bool V_249 ;
V_232 = V_231 = F_47 ( V_2 , V_250 ) ;
V_231 &= ~ ( V_251 | V_252 ) ;
V_231 |= F_56 ( 7 ) | F_57 ( 7 ) ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_250 , V_231 ) ;
V_232 = V_231 = F_47 ( V_2 , V_253 ) ;
V_231 &= ~ ( V_254 | V_255 ) ;
V_231 |= F_58 ( 7 ) | F_59 ( 7 ) ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_253 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_256 ) ;
V_231 &= ~ ( V_251 | V_252 ) ;
V_231 |= F_56 ( 7 ) | F_57 ( 7 ) ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_256 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_257 ) ;
V_231 &= ~ ( V_254 | V_255 ) ;
V_231 |= F_58 ( 7 ) | F_59 ( 7 ) ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_257 , V_231 ) ;
if ( ( V_2 -> V_258 != V_157 ) && ( V_2 -> V_258 != V_158 ) ) {
V_232 = V_231 = F_47 ( V_2 , V_250 ) ;
V_231 &= ~ V_259 ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_250 , V_231 ) ;
V_232 = V_231 = F_47 ( V_2 , V_253 ) ;
V_231 &= ~ V_260 ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_253 , V_231 ) ;
V_232 = V_231 = F_47 ( V_2 , V_261 ) ;
V_231 &= ~ V_262 ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_261 , V_231 ) ;
V_232 = V_231 = F_47 ( V_2 , V_263 ) ;
V_231 &= ~ V_264 ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_263 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_256 ) ;
V_231 &= ~ V_259 ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_256 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_257 ) ;
V_231 &= ~ V_260 ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_257 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_265 ) ;
V_231 &= ~ V_262 ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_265 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_266 ) ;
V_231 &= ~ V_264 ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_266 , V_231 ) ;
}
V_232 = V_231 = F_38 ( V_208 ) ;
V_231 &= ~ V_267 ;
V_231 |= F_60 ( 3 ) ;
if ( V_232 != V_231 )
F_44 ( V_208 , V_231 ) ;
V_232 = V_231 = F_47 ( V_2 , V_268 ) ;
V_231 &= ~ V_269 ;
if ( ( V_2 -> V_258 == V_157 ) || ( V_2 -> V_258 == V_158 ) )
V_231 |= F_61 ( 5 ) ;
if ( V_232 != V_231 )
F_48 ( V_2 , V_268 , V_231 ) ;
V_232 = V_231 = F_49 ( V_2 , V_270 ) ;
V_231 &= ~ V_269 ;
if ( ( V_2 -> V_258 == V_157 ) || ( V_2 -> V_258 == V_158 ) )
V_231 |= F_61 ( 5 ) ;
if ( V_232 != V_231 )
F_50 ( V_2 , V_270 , V_231 ) ;
if ( ! V_236 &&
! F_36 ( V_2 -> V_178 -> V_179 ) ) {
struct V_176 * V_177 = V_2 -> V_178 -> V_179 -> V_180 ;
T_1 V_271 ;
V_249 = false ;
F_62 ( V_177 , V_272 , & V_271 ) ;
if ( V_271 & V_273 )
V_249 = true ;
} else {
V_249 = false ;
}
if ( V_249 ) {
V_232 = V_231 = F_38 ( V_274 ) ;
V_231 |= V_275 | V_276 ;
if ( V_232 != V_231 )
F_44 ( V_274 , V_231 ) ;
V_232 = V_231 = F_4 ( V_277 ) ;
V_231 &= ~ ( V_278 | V_279 ) ;
V_231 |= F_63 ( 1 ) | F_64 ( 1 ) ;
if ( V_232 != V_231 )
F_3 ( V_277 , V_231 ) ;
V_232 = V_231 = F_4 ( V_280 ) ;
V_231 &= ~ ( V_281 | V_282 ) ;
V_231 |= F_65 ( 1 ) | F_66 ( 1 ) ;
if ( V_232 != V_231 )
F_3 ( V_280 , V_231 ) ;
V_232 = V_231 = F_4 ( V_110 ) ;
V_231 &= ~ V_283 ;
if ( V_232 != V_231 )
F_3 ( V_110 , V_231 ) ;
V_232 = V_231 = F_4 ( V_107 ) ;
V_231 &= ~ V_284 ;
if ( V_232 != V_231 )
F_3 ( V_107 , V_231 ) ;
V_232 = V_231 = F_4 ( V_285 ) ;
V_231 &= ~ V_286 ;
V_231 |= F_67 ( 4 ) ;
if ( V_232 != V_231 )
F_3 ( V_285 , V_231 ) ;
V_232 = V_231 = F_4 ( V_287 ) ;
V_231 &= ~ V_288 ;
if ( V_232 != V_231 )
F_3 ( V_287 , V_231 ) ;
}
}
} else {
if ( V_232 != V_231 )
F_44 ( V_245 , V_231 ) ;
}
V_232 = V_231 = F_43 ( V_289 ) ;
V_231 |= V_290 | V_291 | V_292 ;
if ( V_232 != V_231 )
F_53 ( V_289 , V_231 ) ;
if ( ! V_233 ) {
V_231 = F_38 ( V_238 ) ;
if( ( V_231 & V_293 ) == V_293 ) {
V_231 = F_43 ( V_203 ) ;
if ( ( V_231 & V_294 ) && ( V_231 & V_295 ) ) {
V_232 = V_231 = F_38 ( V_245 ) ;
V_231 &= ~ V_246 ;
if ( V_232 != V_231 )
F_44 ( V_245 , V_231 ) ;
}
}
}
}
static void F_68 ( struct V_1 * V_2 )
{
int V_296 ;
T_4 V_9 ;
V_296 = F_69 ( V_2 -> V_178 ) ;
V_9 = F_70 ( V_296 ) - 8 ;
if ( ( V_9 == 0 ) || ( V_9 == 6 ) || ( V_9 == 7 ) )
F_71 ( V_2 -> V_178 , 512 ) ;
}
static int F_72 ( void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
F_68 ( V_2 ) ;
F_32 ( V_2 ) ;
F_35 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_73 ( void * V_120 )
{
return 0 ;
}
static int F_74 ( void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
return F_73 ( V_2 ) ;
}
static int F_75 ( void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
return F_72 ( V_2 ) ;
}
static bool F_76 ( void * V_120 )
{
return true ;
}
static int F_77 ( void * V_120 )
{
return 0 ;
}
static int F_78 ( void * V_120 )
{
return 0 ;
}
static int F_79 ( void * V_120 ,
enum V_297 V_100 )
{
return 0 ;
}
static int F_80 ( void * V_120 ,
enum V_298 V_100 )
{
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
switch ( V_2 -> V_135 ) {
case V_154 :
case V_136 :
case V_151 :
F_82 ( V_2 , & V_299 ) ;
F_82 ( V_2 , & V_300 ) ;
F_82 ( V_2 , & V_301 ) ;
F_82 ( V_2 , & V_302 ) ;
if ( V_2 -> V_303 )
F_82 ( V_2 , & V_304 ) ;
else
F_82 ( V_2 , & V_305 ) ;
F_82 ( V_2 , & V_306 ) ;
F_82 ( V_2 , & V_307 ) ;
break;
case V_157 :
F_82 ( V_2 , & V_299 ) ;
F_82 ( V_2 , & V_300 ) ;
F_82 ( V_2 , & V_301 ) ;
F_82 ( V_2 , & V_302 ) ;
if ( V_2 -> V_303 )
F_82 ( V_2 , & V_304 ) ;
else
F_82 ( V_2 , & V_308 ) ;
F_82 ( V_2 , & V_306 ) ;
F_82 ( V_2 , & V_307 ) ;
break;
case V_158 :
F_82 ( V_2 , & V_299 ) ;
F_82 ( V_2 , & V_300 ) ;
F_82 ( V_2 , & V_301 ) ;
F_82 ( V_2 , & V_302 ) ;
if ( V_2 -> V_303 )
F_82 ( V_2 , & V_304 ) ;
F_82 ( V_2 , & V_306 ) ;
F_82 ( V_2 , & V_307 ) ;
break;
default:
F_34 () ;
}
return 0 ;
}
