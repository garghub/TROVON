int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 , * V_6 , * * V_7 ;
if ( V_2 -> V_8 != V_9 || F_2 ( V_2 ) -> V_10 != V_11 )
return - V_12 ;
V_6 = ( V_3 >= 0 ) ? F_3 ( sizeof( * V_6 ) , V_13 ) : NULL ;
F_4 ( & V_14 ) ;
for ( V_7 = & V_4 ; ( V_5 = * V_7 ) != NULL ; V_7 = & V_5 -> V_15 ) {
if ( V_5 -> V_2 == V_2 ) {
if ( V_3 >= 0 ) {
F_5 ( & V_14 ) ;
F_6 ( V_6 ) ;
return - V_16 ;
}
* V_7 = V_5 -> V_15 ;
F_5 ( & V_14 ) ;
F_7 ( V_2 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
}
if ( ! V_6 ) {
F_5 ( & V_14 ) ;
return - V_17 ;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_15 = V_5 ;
* V_7 = V_6 ;
F_8 ( V_2 ) ;
F_5 ( & V_14 ) ;
return 0 ;
}
struct V_18 * F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( F_2 ( V_2 ) -> V_20 ) {
if ( V_19 &&
! ( ( 1 << V_2 -> V_21 ) & ( V_22 | V_23 ) ) &&
F_2 ( V_2 ) -> V_24 != V_25 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
V_27 -> V_28 = V_19 -> V_29 + V_19 -> V_30 ;
V_27 -> V_31 ( V_2 , V_27 -> V_32 ) ;
}
}
V_19 = F_11 ( ( V_33 struct V_18 * * ) & F_12 ( V_2 ) -> V_19 ,
V_19 ) ;
F_13 ( V_2 ) ;
return V_19 ;
}
static bool F_14 ( int V_34 )
{
switch ( V_34 ) {
case V_35 :
case V_36 :
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
return true ;
}
return false ;
}
static int F_15 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
struct V_50 * V_51 = F_12 ( V_2 ) ;
struct V_52 * V_52 = F_16 ( V_2 ) ;
int V_53 , V_54 ;
int V_55 = - V_12 ;
bool V_56 = F_14 ( V_34 ) ;
if ( ! V_48 )
V_53 = 0 ;
else {
if ( V_49 >= sizeof( int ) ) {
if ( F_17 ( V_53 , ( int T_1 * ) V_48 ) )
return - V_57 ;
} else
V_53 = 0 ;
}
V_54 = ( V_53 != 0 ) ;
if ( F_18 ( V_34 ) )
return F_19 ( V_2 , V_34 , V_48 , V_49 ) ;
if ( V_56 )
F_20 () ;
F_21 ( V_2 ) ;
switch ( V_34 ) {
case V_35 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 == V_59 ) {
struct V_18 * V_19 ;
struct V_60 * V_61 ;
if ( V_2 -> V_8 == V_9 )
break;
if ( V_2 -> V_62 == V_63 ||
V_2 -> V_62 == V_64 ) {
struct V_65 * V_66 = F_22 ( V_2 ) ;
if ( V_66 -> V_67 == V_68 ) {
V_55 = - V_69 ;
break;
}
} else if ( V_2 -> V_62 != V_70 )
break;
if ( V_2 -> V_21 != V_71 ) {
V_55 = - V_72 ;
break;
}
if ( F_23 ( V_2 ) ||
! F_24 ( & V_2 -> V_73 ) ) {
V_55 = - V_74 ;
break;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_62 == V_70 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_28 () ;
F_29 ( V_52 , V_2 -> V_75 , - 1 ) ;
F_29 ( V_52 , & V_76 , 1 ) ;
F_30 () ;
V_2 -> V_75 = & V_76 ;
V_27 -> V_77 = & V_78 ;
V_2 -> V_79 -> V_80 = & V_81 ;
V_2 -> V_82 = V_59 ;
F_31 ( V_2 , V_27 -> V_32 ) ;
} else {
struct V_83 * V_84 = & V_85 ;
if ( V_2 -> V_62 == V_64 )
V_84 = & V_86 ;
F_28 () ;
F_29 ( V_52 , V_2 -> V_75 , - 1 ) ;
F_29 ( V_52 , V_84 , 1 ) ;
F_30 () ;
V_2 -> V_75 = V_84 ;
V_2 -> V_79 -> V_80 = & V_87 ;
V_2 -> V_82 = V_59 ;
}
V_19 = F_11 ( ( V_33 struct V_18 * * ) & V_51 -> V_19 ,
NULL ) ;
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
V_61 = F_11 ( & V_51 -> V_90 , NULL ) ;
F_34 ( V_61 ) ;
F_35 ( V_2 ) ;
F_36 ( V_91 ) ;
V_55 = 0 ;
break;
}
goto V_58;
case V_92 :
if ( V_49 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_58;
V_2 -> V_93 = V_54 ;
V_55 = 0 ;
break;
case V_94 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_97 = V_54 ;
V_55 = 0 ;
break;
case V_98 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_99 = V_54 ;
V_55 = 0 ;
break;
case V_100 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_101 = V_54 ;
V_55 = 0 ;
break;
case V_102 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_103 = V_54 ;
V_55 = 0 ;
break;
case V_104 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_105 = V_54 ;
V_55 = 0 ;
break;
case V_106 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_107 = V_54 ;
V_55 = 0 ;
break;
case V_108 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_109 = V_54 ;
V_55 = 0 ;
break;
case V_110 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_111 = V_54 ;
V_55 = 0 ;
break;
case V_112 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_113 = V_54 ;
V_55 = 0 ;
break;
case V_114 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_115 = V_54 ;
V_55 = 0 ;
break;
case V_116 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < - 1 || V_53 > 0xff )
goto V_58;
if ( V_53 == - 1 )
V_53 = 0 ;
V_51 -> V_117 = V_53 ;
V_55 = 0 ;
break;
case V_118 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_119 = V_54 ;
V_55 = 0 ;
break;
case V_120 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_121 = V_54 ;
V_55 = 0 ;
break;
case V_122 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_123 = V_54 ;
V_55 = 0 ;
break;
case V_124 :
if ( V_54 && ! F_37 ( V_52 -> V_125 , V_126 ) &&
! F_37 ( V_52 -> V_125 , V_127 ) ) {
V_55 = - V_128 ;
break;
}
if ( V_49 < sizeof( int ) )
goto V_58;
F_2 ( V_2 ) -> V_129 = V_54 ;
V_55 = 0 ;
break;
case V_130 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_95 . V_96 . V_131 = V_54 ;
V_55 = 0 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
{
struct V_18 * V_19 ;
if ( V_49 == 0 )
V_48 = NULL ;
else if ( ! V_48 )
goto V_58;
else if ( V_49 < sizeof( struct V_136 ) ||
V_49 & 0x7 || V_49 > 8 * 255 )
goto V_58;
V_55 = - V_128 ;
if ( V_34 != V_134 && ! F_37 ( V_52 -> V_125 , V_127 ) )
break;
V_19 = F_38 ( V_51 -> V_19 ,
F_39 ( V_2 ) ) ;
V_19 = F_40 ( V_2 , V_19 , V_34 ,
(struct V_136 T_1 * ) V_48 ,
V_49 ) ;
if ( F_41 ( V_19 ) ) {
V_55 = F_42 ( V_19 ) ;
break;
}
V_55 = - V_137 ;
if ( V_34 == V_134 && V_19 && V_19 -> V_105 ) {
struct V_138 * V_139 = V_19 -> V_105 ;
switch ( V_139 -> type ) {
#if F_43 ( V_140 )
case V_141 :
if ( V_139 -> V_142 != 2 ||
V_139 -> V_143 != 1 )
goto V_144;
break;
#endif
case V_145 :
{
struct V_146 * V_147 = (struct V_146 * )
V_19 -> V_105 ;
if ( ! F_44 ( V_147 , V_49 ) )
goto V_144;
break;
}
default:
goto V_144;
}
}
V_55 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_144:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_148 :
{
struct V_149 V_150 ;
if ( V_49 == 0 )
goto V_58;
else if ( V_49 < sizeof( struct V_149 ) || ! V_48 )
goto V_58;
if ( F_45 ( & V_150 , V_48 , sizeof( struct V_149 ) ) ) {
V_55 = - V_57 ;
break;
}
if ( V_2 -> V_151 && V_150 . V_152 != V_2 -> V_151 )
goto V_58;
V_51 -> V_153 . V_152 = V_150 . V_152 ;
V_51 -> V_153 . V_154 = V_150 . V_154 ;
V_55 = 0 ;
break;
}
case V_155 :
{
struct V_18 * V_19 = NULL ;
struct V_156 V_157 ;
struct V_158 V_159 ;
struct V_160 V_161 ;
struct V_162 V_163 ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_159 . V_164 = V_2 -> V_151 ;
V_159 . V_165 = V_2 -> V_166 ;
if ( V_49 == 0 )
goto V_167;
V_55 = - V_137 ;
if ( V_49 > 64 * 1024 )
break;
V_19 = F_46 ( V_2 , sizeof( * V_19 ) + V_49 , V_13 ) ;
V_55 = - V_17 ;
if ( ! V_19 )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_47 ( & V_19 -> V_168 , 1 ) ;
V_19 -> V_88 = sizeof( * V_19 ) + V_49 ;
V_55 = - V_57 ;
if ( F_45 ( V_19 + 1 , V_48 , V_49 ) )
goto V_169;
V_157 . V_170 = V_49 ;
V_157 . V_171 = ( void * ) ( V_19 + 1 ) ;
V_163 . V_19 = V_19 ;
V_55 = F_48 ( V_52 , V_2 , & V_157 , & V_159 , & V_163 , & V_161 ) ;
if ( V_55 )
goto V_169;
V_167:
V_55 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_169:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_172 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 > 255 || V_53 < - 1 )
goto V_58;
V_51 -> V_173 = V_53 ;
V_55 = 0 ;
break;
case V_174 :
if ( V_2 -> V_8 == V_175 )
break;
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 > 255 || V_53 < - 1 )
goto V_58;
V_51 -> V_176 = ( V_53 == - 1 ? V_177 : V_53 ) ;
V_55 = 0 ;
break;
case V_178 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 != V_54 )
goto V_58;
V_51 -> V_179 = V_54 ;
V_55 = 0 ;
break;
case V_180 :
{
struct V_181 * V_182 = NULL ;
int V_183 ;
if ( V_49 != sizeof( int ) )
goto V_58;
V_183 = ( V_33 int ) F_49 ( ( V_33 V_184 ) V_53 ) ;
if ( V_183 == 0 ) {
V_51 -> V_185 = 0 ;
V_55 = 0 ;
break;
}
V_182 = F_50 ( V_52 , V_183 ) ;
V_55 = - V_74 ;
if ( ! V_182 )
break;
F_51 ( V_182 ) ;
V_55 = - V_137 ;
if ( V_2 -> V_151 )
break;
V_51 -> V_185 = V_183 ;
V_55 = 0 ;
break;
}
case V_186 :
if ( V_2 -> V_8 == V_175 )
break;
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 ) {
struct V_181 * V_182 ;
int V_187 ;
F_52 () ;
V_182 = F_53 ( V_52 , V_53 ) ;
if ( ! V_182 ) {
F_54 () ;
V_55 = - V_188 ;
break;
}
V_187 = F_55 ( V_182 ) ;
F_54 () ;
if ( V_2 -> V_151 &&
V_2 -> V_151 != V_53 &&
( ! V_187 || V_187 != V_2 -> V_151 ) )
goto V_58;
}
V_51 -> V_189 = V_53 ;
V_55 = 0 ;
break;
case V_36 :
case V_37 :
{
struct V_190 V_191 ;
if ( V_49 < sizeof( struct V_190 ) )
goto V_58;
V_55 = - V_192 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_55 = - V_57 ;
if ( F_45 ( & V_191 , V_48 , sizeof( struct V_190 ) ) )
break;
if ( V_34 == V_36 )
V_55 = F_56 ( V_2 , V_191 . V_193 , & V_191 . V_194 ) ;
else
V_55 = F_57 ( V_2 , V_191 . V_193 , & V_191 . V_194 ) ;
break;
}
case V_38 :
case V_39 :
{
struct V_190 V_191 ;
if ( V_49 < sizeof( struct V_190 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_191 , V_48 , sizeof( struct V_190 ) ) )
break;
if ( V_34 == V_38 )
V_55 = F_58 ( V_2 , V_191 . V_193 , & V_191 . V_195 ) ;
else
V_55 = F_59 ( V_2 , V_191 . V_193 , & V_191 . V_195 ) ;
break;
}
case V_40 :
case V_41 :
{
struct V_196 V_197 ;
struct V_198 * V_199 ;
if ( V_49 < sizeof( struct V_196 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_197 , V_48 , sizeof( struct V_196 ) ) )
break;
if ( V_197 . V_200 . V_201 != V_68 ) {
V_55 = - V_74 ;
break;
}
V_199 = (struct V_198 * ) & V_197 . V_200 ;
if ( V_34 == V_40 )
V_55 = F_56 ( V_2 , V_197 . V_202 ,
& V_199 -> V_203 ) ;
else
V_55 = F_57 ( V_2 , V_197 . V_202 ,
& V_199 -> V_203 ) ;
break;
}
case V_42 :
case V_43 :
case V_44 :
case V_45 :
{
struct V_204 V_205 ;
int V_206 , V_207 ;
if ( V_49 < sizeof( struct V_204 ) )
goto V_58;
if ( F_45 ( & V_205 , V_48 , sizeof( V_205 ) ) ) {
V_55 = - V_57 ;
break;
}
if ( V_205 . V_208 . V_201 != V_68 ||
V_205 . V_209 . V_201 != V_68 ) {
V_55 = - V_74 ;
break;
}
if ( V_34 == V_44 ) {
V_206 = V_210 ;
V_207 = 1 ;
} else if ( V_34 == V_45 ) {
V_206 = V_210 ;
V_207 = 0 ;
} else if ( V_34 == V_42 ) {
struct V_198 * V_199 ;
V_199 = (struct V_198 * ) & V_205 . V_208 ;
V_55 = F_56 ( V_2 , V_205 . V_211 ,
& V_199 -> V_203 ) ;
if ( V_55 && V_55 != - V_16 )
break;
V_206 = V_212 ;
V_207 = 1 ;
} else {
V_206 = V_212 ;
V_207 = 0 ;
}
V_55 = F_60 ( V_207 , V_206 , V_2 , & V_205 ) ;
break;
}
case V_46 :
{
struct V_213 * V_214 ;
if ( V_49 < F_61 ( 0 ) )
goto V_58;
if ( V_49 > V_215 ) {
V_55 = - V_17 ;
break;
}
V_214 = F_62 ( V_48 , V_49 ) ;
if ( F_41 ( V_214 ) ) {
V_55 = F_42 ( V_214 ) ;
break;
}
if ( V_214 -> V_216 >= 0x1ffffffU ||
V_214 -> V_216 > V_217 ) {
F_6 ( V_214 ) ;
V_55 = - V_17 ;
break;
}
if ( F_61 ( V_214 -> V_216 ) > V_49 ) {
F_6 ( V_214 ) ;
V_55 = - V_137 ;
break;
}
V_55 = F_63 ( V_2 , V_214 ) ;
F_6 ( V_214 ) ;
break;
}
case V_218 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = F_1 ( V_2 , V_53 ) ;
break;
case V_219 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < V_220 || V_53 > V_221 )
goto V_58;
V_51 -> V_222 = V_53 ;
V_55 = 0 ;
break;
case V_223 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 && V_53 < V_224 )
goto V_58;
V_51 -> V_225 = V_53 ;
V_55 = 0 ;
break;
case V_226 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_227 = V_54 ;
if ( ! V_53 )
F_64 ( & V_2 -> V_228 ) ;
V_55 = 0 ;
break;
case V_229 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_230 = V_54 ;
V_55 = 0 ;
break;
case V_231 :
V_55 = F_65 ( V_2 , V_48 , V_49 ) ;
break;
case V_232 :
case V_233 :
V_55 = - V_128 ;
if ( ! F_37 ( V_52 -> V_125 , V_126 ) )
break;
V_55 = F_66 ( V_2 , V_34 , V_48 , V_49 ) ;
break;
case V_234 :
{
unsigned int V_235 = 0 ;
unsigned int V_236 = ~ 0 ;
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = - V_137 ;
switch ( V_53 & ( V_237 |
V_238 |
V_239 ) ) {
case V_237 :
V_235 |= V_237 ;
break;
case V_238 :
V_235 |= V_238 ;
break;
case V_239 :
break;
case 0 :
goto V_240;
default:
goto V_58;
}
V_236 &= ~ ( V_237 |
V_238 ) ;
V_240:
switch ( V_53 & ( V_241 | V_242 ) ) {
case V_241 :
break;
case V_242 :
V_235 |= V_242 ;
case 0 :
goto V_243;
default:
goto V_58;
}
V_236 &= ~ V_242 ;
V_243:
switch ( V_53 & ( V_244 | V_245 ) ) {
case V_244 :
case V_245 :
case 0 :
break;
default:
goto V_58;
}
V_51 -> V_246 = ( V_51 -> V_246 & V_236 ) | V_235 ;
V_55 = 0 ;
break;
}
case V_247 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < 0 || V_53 > 255 )
goto V_58;
V_51 -> V_248 = V_53 ;
V_55 = 0 ;
break;
case V_249 :
V_51 -> V_250 = V_54 ;
V_55 = 0 ;
break;
case V_251 :
V_51 -> V_252 = V_54 ;
V_55 = 0 ;
break;
case V_253 :
V_51 -> V_95 . V_96 . V_254 = V_54 ;
V_55 = 0 ;
break;
}
F_67 ( V_2 ) ;
if ( V_56 )
F_68 () ;
return V_55 ;
V_58:
F_67 ( V_2 ) ;
if ( V_56 )
F_68 () ;
return - V_137 ;
}
int F_69 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_255 ;
if ( V_47 == V_256 && V_2 -> V_8 != V_9 )
return V_85 . V_257 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_258 )
return - V_12 ;
V_255 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_70
if ( V_255 == - V_12 && V_34 != V_232 &&
V_34 != V_233 ) {
F_21 ( V_2 ) ;
V_255 = F_71 ( V_2 , V_259 , V_34 , V_48 ,
V_49 ) ;
F_67 ( V_2 ) ;
}
#endif
return V_255 ;
}
int F_72 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_255 ;
if ( V_47 == V_256 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_260 != NULL )
return V_85 . V_260 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_257 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_258 )
return - V_12 ;
if ( V_34 >= V_40 && V_34 <= V_46 )
return F_73 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_69 ) ;
V_255 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_70
if ( V_255 == - V_12 && V_34 != V_232 &&
V_34 != V_233 ) {
F_21 ( V_2 ) ;
V_255 = F_74 ( V_2 , V_259 , V_34 ,
V_48 , V_49 ) ;
F_67 ( V_2 ) ;
}
#endif
return V_255 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_34 , char T_1 * V_48 , int V_261 )
{
struct V_136 * V_262 ;
if ( ! V_19 )
return 0 ;
switch ( V_34 ) {
case V_132 :
V_262 = V_19 -> V_263 ;
break;
case V_133 :
V_262 = V_19 -> V_264 ;
break;
case V_134 :
V_262 = (struct V_136 * ) V_19 -> V_105 ;
break;
case V_135 :
V_262 = V_19 -> V_265 ;
break;
default:
return - V_137 ;
}
if ( ! V_262 )
return 0 ;
V_261 = F_76 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_77 ( V_48 , V_262 , V_261 ) )
return - V_57 ;
return V_261 ;
}
static int F_78 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 , unsigned int V_266 )
{
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_261 ;
int V_53 ;
if ( F_18 ( V_34 ) )
return F_79 ( V_2 , V_34 , V_48 , V_49 ) ;
if ( F_17 ( V_261 , V_49 ) )
return - V_57 ;
switch ( V_34 ) {
case V_35 :
if ( V_2 -> V_62 != V_63 &&
V_2 -> V_62 != V_64 &&
V_2 -> V_62 != V_70 )
return - V_12 ;
if ( V_2 -> V_21 != V_71 )
return - V_72 ;
V_53 = V_2 -> V_82 ;
break;
case V_46 :
{
struct V_213 V_214 ;
int V_255 ;
if ( V_261 < F_61 ( 0 ) )
return - V_137 ;
if ( F_45 ( & V_214 , V_48 , F_61 ( 0 ) ) )
return - V_57 ;
if ( V_214 . V_267 . V_201 != V_68 )
return - V_74 ;
F_21 ( V_2 ) ;
V_255 = F_80 ( V_2 , & V_214 ,
(struct V_213 T_1 * ) V_48 , V_49 ) ;
F_67 ( V_2 ) ;
return V_255 ;
}
case V_155 :
{
struct V_156 V_157 ;
struct V_60 * V_268 ;
if ( V_2 -> V_8 != V_175 )
return - V_12 ;
V_157 . V_171 = V_48 ;
V_157 . V_170 = V_261 ;
V_157 . V_269 = V_266 ;
F_21 ( V_2 ) ;
V_268 = V_51 -> V_90 ;
if ( V_268 )
F_81 ( V_2 , & V_157 , V_268 ) ;
F_67 ( V_2 ) ;
if ( ! V_268 ) {
if ( V_51 -> V_95 . V_96 . V_97 ) {
struct V_149 V_270 ;
V_270 . V_152 = V_51 -> V_189 ? V_51 -> V_189 :
V_51 -> V_153 . V_152 ;
V_270 . V_154 = V_51 -> V_189 ? V_2 -> V_73 : V_51 -> V_153 . V_154 ;
F_82 ( & V_157 , V_258 , V_148 , sizeof( V_270 ) , & V_270 ) ;
}
if ( V_51 -> V_95 . V_96 . V_101 ) {
int V_271 = V_51 -> V_176 ;
F_82 ( & V_157 , V_258 , V_272 , sizeof( V_271 ) , & V_271 ) ;
}
if ( V_51 -> V_95 . V_96 . V_119 ) {
int V_117 = ( int ) F_83 ( V_51 -> V_273 ) ;
F_82 ( & V_157 , V_258 , V_116 , sizeof( V_117 ) , & V_117 ) ;
}
if ( V_51 -> V_95 . V_96 . V_99 ) {
struct V_149 V_270 ;
V_270 . V_152 = V_51 -> V_189 ? V_51 -> V_189 :
V_51 -> V_153 . V_152 ;
V_270 . V_154 = V_51 -> V_189 ? V_2 -> V_73 :
V_51 -> V_153 . V_154 ;
F_82 ( & V_157 , V_258 , V_98 , sizeof( V_270 ) , & V_270 ) ;
}
if ( V_51 -> V_95 . V_96 . V_103 ) {
int V_271 = V_51 -> V_176 ;
F_82 ( & V_157 , V_258 , V_102 , sizeof( V_271 ) , & V_271 ) ;
}
if ( V_51 -> V_95 . V_96 . V_121 ) {
V_184 V_274 = V_51 -> V_273 ;
F_82 ( & V_157 , V_258 , V_120 , sizeof( V_274 ) , & V_274 ) ;
}
}
V_261 -= V_157 . V_170 ;
return F_84 ( V_261 , V_49 ) ;
}
case V_223 :
{
struct V_275 * V_276 ;
V_53 = 0 ;
F_52 () ;
V_276 = F_85 ( V_2 ) ;
if ( V_276 )
V_53 = F_86 ( V_276 ) ;
F_54 () ;
if ( ! V_53 )
return - V_72 ;
break;
}
case V_92 :
V_53 = V_2 -> V_93 ;
break;
case V_94 :
V_53 = V_51 -> V_95 . V_96 . V_97 ;
break;
case V_98 :
V_53 = V_51 -> V_95 . V_96 . V_99 ;
break;
case V_100 :
V_53 = V_51 -> V_95 . V_96 . V_101 ;
break;
case V_102 :
V_53 = V_51 -> V_95 . V_96 . V_103 ;
break;
case V_104 :
V_53 = V_51 -> V_95 . V_96 . V_105 ;
break;
case V_106 :
V_53 = V_51 -> V_95 . V_96 . V_107 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
{
struct V_18 * V_19 ;
F_21 ( V_2 ) ;
V_19 = F_38 ( V_51 -> V_19 ,
F_39 ( V_2 ) ) ;
V_261 = F_75 ( V_2 , V_19 , V_34 , V_48 , V_261 ) ;
F_67 ( V_2 ) ;
if ( V_261 < 0 )
return V_261 ;
return F_84 ( V_261 , V_49 ) ;
}
case V_108 :
V_53 = V_51 -> V_95 . V_96 . V_109 ;
break;
case V_110 :
V_53 = V_51 -> V_95 . V_96 . V_111 ;
break;
case V_112 :
V_53 = V_51 -> V_95 . V_96 . V_113 ;
break;
case V_114 :
V_53 = V_51 -> V_95 . V_96 . V_115 ;
break;
case V_116 :
V_53 = V_51 -> V_117 ;
break;
case V_118 :
V_53 = V_51 -> V_95 . V_96 . V_119 ;
break;
case V_120 :
V_53 = V_51 -> V_95 . V_96 . V_121 ;
break;
case V_122 :
V_53 = V_51 -> V_95 . V_96 . V_123 ;
break;
case V_277 :
{
struct V_275 * V_276 ;
struct V_278 V_279 ;
if ( V_261 < sizeof( V_279 ) )
return - V_137 ;
V_261 = sizeof( V_279 ) ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
F_52 () ;
V_276 = F_85 ( V_2 ) ;
if ( V_276 )
V_279 . V_280 = F_86 ( V_276 ) ;
F_54 () ;
if ( ! V_279 . V_280 )
return - V_72 ;
if ( F_84 ( V_261 , V_49 ) )
return - V_57 ;
if ( F_77 ( V_48 , & V_279 , V_261 ) )
return - V_57 ;
return 0 ;
}
case V_124 :
V_53 = F_2 ( V_2 ) -> V_129 ;
break;
case V_130 :
V_53 = V_51 -> V_95 . V_96 . V_131 ;
break;
case V_172 :
case V_174 :
{
struct V_275 * V_276 ;
if ( V_34 == V_172 )
V_53 = V_51 -> V_173 ;
else
V_53 = V_51 -> V_176 ;
if ( V_53 < 0 ) {
F_52 () ;
V_276 = F_85 ( V_2 ) ;
if ( V_276 )
V_53 = F_87 ( V_276 ) ;
F_54 () ;
}
if ( V_53 < 0 )
V_53 = F_16 ( V_2 ) -> V_281 . V_282 -> V_173 ;
break;
}
case V_178 :
V_53 = V_51 -> V_179 ;
break;
case V_186 :
V_53 = V_51 -> V_189 ;
break;
case V_180 :
V_53 = ( V_33 int ) F_88 ( ( V_283 ) V_51 -> V_185 ) ;
break;
case V_219 :
V_53 = V_51 -> V_222 ;
break;
case V_226 :
V_53 = V_51 -> V_227 ;
break;
case V_229 :
V_53 = V_51 -> V_230 ;
break;
case V_231 :
{
struct V_284 V_285 ;
int V_266 ;
if ( V_261 < sizeof( V_285 ) )
return - V_137 ;
if ( F_45 ( & V_285 , V_48 , sizeof( V_285 ) ) )
return - V_57 ;
if ( V_285 . V_286 != V_287 )
return - V_137 ;
V_261 = sizeof( V_285 ) ;
V_266 = V_285 . V_288 ;
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
V_53 = F_89 ( V_2 , & V_285 , V_266 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_84 ( V_261 , V_49 ) )
return - V_57 ;
if ( F_77 ( V_48 , & V_285 , V_261 ) )
return - V_57 ;
return 0 ;
}
case V_234 :
V_53 = 0 ;
if ( V_51 -> V_246 & V_238 )
V_53 |= V_238 ;
else if ( V_51 -> V_246 & V_237 )
V_53 |= V_237 ;
else {
V_53 |= V_239 ;
}
if ( V_51 -> V_246 & V_242 )
V_53 |= V_242 ;
else
V_53 |= V_241 ;
break;
case V_247 :
V_53 = V_51 -> V_248 ;
break;
case V_249 :
V_53 = V_51 -> V_250 ;
break;
case V_251 :
V_53 = V_51 -> V_252 ;
break;
case V_253 :
V_53 = V_51 -> V_95 . V_96 . V_254 ;
break;
default:
return - V_12 ;
}
V_261 = F_76 (unsigned int, sizeof(int), len) ;
if ( F_84 ( V_261 , V_49 ) )
return - V_57 ;
if ( F_77 ( V_48 , & V_53 , V_261 ) )
return - V_57 ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_255 ;
if ( V_47 == V_256 && V_2 -> V_8 != V_9 )
return V_85 . V_289 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_258 )
return - V_12 ;
V_255 = F_78 ( V_2 , V_47 , V_34 , V_48 , V_49 , 0 ) ;
#ifdef F_70
if ( V_255 == - V_12 && V_34 != V_155 ) {
int V_261 ;
if ( F_17 ( V_261 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_255 = F_91 ( V_2 , V_259 , V_34 , V_48 ,
& V_261 ) ;
F_67 ( V_2 ) ;
if ( V_255 >= 0 )
V_255 = F_84 ( V_261 , V_49 ) ;
}
#endif
return V_255 ;
}
int F_92 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_255 ;
if ( V_47 == V_256 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_290 != NULL )
return V_85 . V_290 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_289 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_258 )
return - V_12 ;
if ( V_34 == V_46 )
return F_93 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_90 ) ;
V_255 = F_78 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
V_291 ) ;
#ifdef F_70
if ( V_255 == - V_12 && V_34 != V_155 ) {
int V_261 ;
if ( F_17 ( V_261 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_255 = F_94 ( V_2 , V_259 ,
V_34 , V_48 , & V_261 ) ;
F_67 ( V_2 ) ;
if ( V_255 >= 0 )
V_255 = F_84 ( V_261 , V_49 ) ;
}
#endif
return V_255 ;
}
