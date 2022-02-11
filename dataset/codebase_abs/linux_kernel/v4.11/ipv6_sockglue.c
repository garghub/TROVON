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
V_2 -> V_91 = V_92 ;
F_35 ( V_2 ) ;
F_36 ( V_93 ) ;
V_55 = 0 ;
break;
}
goto V_58;
case V_94 :
if ( V_49 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_58;
V_2 -> V_95 = V_54 ;
V_55 = 0 ;
break;
case V_96 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_99 = V_54 ;
V_55 = 0 ;
break;
case V_100 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_101 = V_54 ;
V_55 = 0 ;
break;
case V_102 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_103 = V_54 ;
V_55 = 0 ;
break;
case V_104 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_105 = V_54 ;
V_55 = 0 ;
break;
case V_106 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_107 = V_54 ;
V_55 = 0 ;
break;
case V_108 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_109 = V_54 ;
V_55 = 0 ;
break;
case V_110 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_111 = V_54 ;
V_55 = 0 ;
break;
case V_112 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_113 = V_54 ;
V_55 = 0 ;
break;
case V_114 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_115 = V_54 ;
V_55 = 0 ;
break;
case V_116 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_117 = V_54 ;
V_55 = 0 ;
break;
case V_118 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < - 1 || V_53 > 0xff )
goto V_58;
if ( V_53 == - 1 )
V_53 = 0 ;
V_51 -> V_119 = V_53 ;
V_55 = 0 ;
break;
case V_120 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_121 = V_54 ;
V_55 = 0 ;
break;
case V_122 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_123 = V_54 ;
V_55 = 0 ;
break;
case V_124 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_125 = V_54 ;
V_55 = 0 ;
break;
case V_126 :
if ( V_54 && ! F_37 ( V_52 -> V_127 , V_128 ) &&
! F_37 ( V_52 -> V_127 , V_129 ) ) {
V_55 = - V_130 ;
break;
}
if ( V_49 < sizeof( int ) )
goto V_58;
F_2 ( V_2 ) -> V_131 = V_54 ;
V_55 = 0 ;
break;
case V_132 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_97 . V_98 . V_133 = V_54 ;
V_55 = 0 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
{
struct V_18 * V_19 ;
if ( V_49 == 0 )
V_48 = NULL ;
else if ( ! V_48 )
goto V_58;
else if ( V_49 < sizeof( struct V_138 ) ||
V_49 & 0x7 || V_49 > 8 * 255 )
goto V_58;
V_55 = - V_130 ;
if ( V_34 != V_136 && ! F_37 ( V_52 -> V_127 , V_129 ) )
break;
V_19 = F_38 ( V_51 -> V_19 ,
F_39 ( V_2 ) ) ;
V_19 = F_40 ( V_2 , V_19 , V_34 ,
(struct V_138 T_1 * ) V_48 ,
V_49 ) ;
if ( F_41 ( V_19 ) ) {
V_55 = F_42 ( V_19 ) ;
break;
}
V_55 = - V_139 ;
if ( V_34 == V_136 && V_19 && V_19 -> V_107 ) {
struct V_140 * V_141 = V_19 -> V_107 ;
switch ( V_141 -> type ) {
#if F_43 ( V_142 )
case V_143 :
if ( V_141 -> V_144 != 2 ||
V_141 -> V_145 != 1 )
goto V_146;
break;
#endif
case V_147 :
{
struct V_148 * V_149 = (struct V_148 * )
V_19 -> V_107 ;
if ( ! F_44 ( V_149 , V_49 ) )
goto V_146;
break;
}
default:
goto V_146;
}
}
V_55 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_146:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_150 :
{
struct V_151 V_152 ;
if ( V_49 == 0 )
goto V_58;
else if ( V_49 < sizeof( struct V_151 ) || ! V_48 )
goto V_58;
if ( F_45 ( & V_152 , V_48 , sizeof( struct V_151 ) ) ) {
V_55 = - V_57 ;
break;
}
if ( V_2 -> V_153 && V_152 . V_154 != V_2 -> V_153 )
goto V_58;
V_51 -> V_155 . V_154 = V_152 . V_154 ;
V_51 -> V_155 . V_156 = V_152 . V_156 ;
V_55 = 0 ;
break;
}
case V_157 :
{
struct V_18 * V_19 = NULL ;
struct V_158 V_159 ;
struct V_160 V_161 ;
struct V_162 V_163 ;
struct V_164 V_165 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_166 = V_2 -> V_153 ;
V_161 . V_167 = V_2 -> V_168 ;
if ( V_49 == 0 )
goto V_169;
V_55 = - V_139 ;
if ( V_49 > 64 * 1024 )
break;
V_19 = F_46 ( V_2 , sizeof( * V_19 ) + V_49 , V_13 ) ;
V_55 = - V_17 ;
if ( ! V_19 )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_47 ( & V_19 -> V_170 , 1 ) ;
V_19 -> V_88 = sizeof( * V_19 ) + V_49 ;
V_55 = - V_57 ;
if ( F_45 ( V_19 + 1 , V_48 , V_49 ) )
goto V_171;
V_159 . V_172 = V_49 ;
V_159 . V_173 = ( void * ) ( V_19 + 1 ) ;
V_165 . V_19 = V_19 ;
V_55 = F_48 ( V_52 , V_2 , & V_159 , & V_161 , & V_165 , & V_163 ) ;
if ( V_55 )
goto V_171;
V_169:
V_55 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_171:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_174 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 > 255 || V_53 < - 1 )
goto V_58;
V_51 -> V_175 = V_53 ;
V_55 = 0 ;
break;
case V_176 :
if ( V_2 -> V_8 == V_177 )
break;
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 > 255 || V_53 < - 1 )
goto V_58;
V_51 -> V_178 = ( V_53 == - 1 ? V_179 : V_53 ) ;
V_55 = 0 ;
break;
case V_180 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 != V_54 )
goto V_58;
V_51 -> V_181 = V_54 ;
V_55 = 0 ;
break;
case V_182 :
{
struct V_183 * V_184 = NULL ;
int V_185 ;
if ( V_49 != sizeof( int ) )
goto V_58;
V_185 = ( V_33 int ) F_49 ( ( V_33 V_186 ) V_53 ) ;
if ( V_185 == 0 ) {
V_51 -> V_187 = 0 ;
V_55 = 0 ;
break;
}
V_184 = F_50 ( V_52 , V_185 ) ;
V_55 = - V_74 ;
if ( ! V_184 )
break;
F_51 ( V_184 ) ;
V_55 = - V_139 ;
if ( V_2 -> V_153 )
break;
V_51 -> V_187 = V_185 ;
V_55 = 0 ;
break;
}
case V_188 :
if ( V_2 -> V_8 == V_177 )
break;
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 ) {
struct V_183 * V_184 ;
int V_189 ;
F_52 () ;
V_184 = F_53 ( V_52 , V_53 ) ;
if ( ! V_184 ) {
F_54 () ;
V_55 = - V_190 ;
break;
}
V_189 = F_55 ( V_184 ) ;
F_54 () ;
if ( V_2 -> V_153 &&
V_2 -> V_153 != V_53 &&
( ! V_189 || V_189 != V_2 -> V_153 ) )
goto V_58;
}
V_51 -> V_191 = V_53 ;
V_55 = 0 ;
break;
case V_36 :
case V_37 :
{
struct V_192 V_193 ;
if ( V_49 < sizeof( struct V_192 ) )
goto V_58;
V_55 = - V_194 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_55 = - V_57 ;
if ( F_45 ( & V_193 , V_48 , sizeof( struct V_192 ) ) )
break;
if ( V_34 == V_36 )
V_55 = F_56 ( V_2 , V_193 . V_195 , & V_193 . V_196 ) ;
else
V_55 = F_57 ( V_2 , V_193 . V_195 , & V_193 . V_196 ) ;
break;
}
case V_38 :
case V_39 :
{
struct V_192 V_193 ;
if ( V_49 < sizeof( struct V_192 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_193 , V_48 , sizeof( struct V_192 ) ) )
break;
if ( V_34 == V_38 )
V_55 = F_58 ( V_2 , V_193 . V_195 , & V_193 . V_197 ) ;
else
V_55 = F_59 ( V_2 , V_193 . V_195 , & V_193 . V_197 ) ;
break;
}
case V_40 :
case V_41 :
{
struct V_198 V_199 ;
struct V_200 * V_201 ;
if ( V_49 < sizeof( struct V_198 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_199 , V_48 , sizeof( struct V_198 ) ) )
break;
if ( V_199 . V_202 . V_203 != V_68 ) {
V_55 = - V_74 ;
break;
}
V_201 = (struct V_200 * ) & V_199 . V_202 ;
if ( V_34 == V_40 )
V_55 = F_56 ( V_2 , V_199 . V_204 ,
& V_201 -> V_205 ) ;
else
V_55 = F_57 ( V_2 , V_199 . V_204 ,
& V_201 -> V_205 ) ;
break;
}
case V_42 :
case V_43 :
case V_44 :
case V_45 :
{
struct V_206 V_207 ;
int V_208 , V_209 ;
if ( V_49 < sizeof( struct V_206 ) )
goto V_58;
if ( F_45 ( & V_207 , V_48 , sizeof( V_207 ) ) ) {
V_55 = - V_57 ;
break;
}
if ( V_207 . V_210 . V_203 != V_68 ||
V_207 . V_211 . V_203 != V_68 ) {
V_55 = - V_74 ;
break;
}
if ( V_34 == V_44 ) {
V_208 = V_212 ;
V_209 = 1 ;
} else if ( V_34 == V_45 ) {
V_208 = V_212 ;
V_209 = 0 ;
} else if ( V_34 == V_42 ) {
struct V_200 * V_201 ;
V_201 = (struct V_200 * ) & V_207 . V_210 ;
V_55 = F_56 ( V_2 , V_207 . V_213 ,
& V_201 -> V_205 ) ;
if ( V_55 && V_55 != - V_16 )
break;
V_208 = V_214 ;
V_209 = 1 ;
} else {
V_208 = V_214 ;
V_209 = 0 ;
}
V_55 = F_60 ( V_209 , V_208 , V_2 , & V_207 ) ;
break;
}
case V_46 :
{
struct V_215 * V_216 ;
if ( V_49 < F_61 ( 0 ) )
goto V_58;
if ( V_49 > V_217 ) {
V_55 = - V_17 ;
break;
}
V_216 = F_3 ( V_49 , V_13 ) ;
if ( ! V_216 ) {
V_55 = - V_17 ;
break;
}
V_55 = - V_57 ;
if ( F_45 ( V_216 , V_48 , V_49 ) ) {
F_6 ( V_216 ) ;
break;
}
if ( V_216 -> V_218 >= 0x1ffffffU ||
V_216 -> V_218 > V_219 ) {
F_6 ( V_216 ) ;
V_55 = - V_17 ;
break;
}
if ( F_61 ( V_216 -> V_218 ) > V_49 ) {
F_6 ( V_216 ) ;
V_55 = - V_139 ;
break;
}
V_55 = F_62 ( V_2 , V_216 ) ;
F_6 ( V_216 ) ;
break;
}
case V_220 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = F_1 ( V_2 , V_53 ) ;
break;
case V_221 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < V_222 || V_53 > V_223 )
goto V_58;
V_51 -> V_224 = V_53 ;
V_55 = 0 ;
break;
case V_225 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 && V_53 < V_226 )
goto V_58;
V_51 -> V_227 = V_53 ;
V_55 = 0 ;
break;
case V_228 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_229 = V_54 ;
if ( ! V_53 )
F_63 ( & V_2 -> V_230 ) ;
V_55 = 0 ;
break;
case V_231 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_232 = V_54 ;
V_55 = 0 ;
break;
case V_233 :
V_55 = F_64 ( V_2 , V_48 , V_49 ) ;
break;
case V_234 :
case V_235 :
V_55 = - V_130 ;
if ( ! F_37 ( V_52 -> V_127 , V_128 ) )
break;
V_55 = F_65 ( V_2 , V_34 , V_48 , V_49 ) ;
break;
case V_236 :
{
unsigned int V_237 = 0 ;
unsigned int V_238 = ~ 0 ;
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = - V_139 ;
switch ( V_53 & ( V_239 |
V_240 |
V_241 ) ) {
case V_239 :
V_237 |= V_239 ;
break;
case V_240 :
V_237 |= V_240 ;
break;
case V_241 :
break;
case 0 :
goto V_242;
default:
goto V_58;
}
V_238 &= ~ ( V_239 |
V_240 ) ;
V_242:
switch ( V_53 & ( V_243 | V_244 ) ) {
case V_243 :
break;
case V_244 :
V_237 |= V_244 ;
case 0 :
goto V_245;
default:
goto V_58;
}
V_238 &= ~ V_244 ;
V_245:
switch ( V_53 & ( V_246 | V_247 ) ) {
case V_246 :
case V_247 :
case 0 :
break;
default:
goto V_58;
}
V_51 -> V_248 = ( V_51 -> V_248 & V_238 ) | V_237 ;
V_55 = 0 ;
break;
}
case V_249 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < 0 || V_53 > 255 )
goto V_58;
V_51 -> V_250 = V_53 ;
V_55 = 0 ;
break;
case V_251 :
V_51 -> V_252 = V_54 ;
V_55 = 0 ;
break;
case V_253 :
V_51 -> V_254 = V_54 ;
V_55 = 0 ;
break;
case V_255 :
V_51 -> V_97 . V_98 . V_256 = V_54 ;
V_55 = 0 ;
break;
}
F_66 ( V_2 ) ;
if ( V_56 )
F_67 () ;
return V_55 ;
V_58:
F_66 ( V_2 ) ;
if ( V_56 )
F_67 () ;
return - V_139 ;
}
int F_68 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_257 ;
if ( V_47 == V_258 && V_2 -> V_8 != V_9 )
return V_85 . V_259 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_260 )
return - V_12 ;
V_257 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_69
if ( V_257 == - V_12 && V_34 != V_234 &&
V_34 != V_235 ) {
F_21 ( V_2 ) ;
V_257 = F_70 ( V_2 , V_261 , V_34 , V_48 ,
V_49 ) ;
F_66 ( V_2 ) ;
}
#endif
return V_257 ;
}
int F_71 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_257 ;
if ( V_47 == V_258 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_262 != NULL )
return V_85 . V_262 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_259 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_260 )
return - V_12 ;
if ( V_34 >= V_40 && V_34 <= V_46 )
return F_72 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_68 ) ;
V_257 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_69
if ( V_257 == - V_12 && V_34 != V_234 &&
V_34 != V_235 ) {
F_21 ( V_2 ) ;
V_257 = F_73 ( V_2 , V_261 , V_34 ,
V_48 , V_49 ) ;
F_66 ( V_2 ) ;
}
#endif
return V_257 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_34 , char T_1 * V_48 , int V_263 )
{
struct V_138 * V_264 ;
if ( ! V_19 )
return 0 ;
switch ( V_34 ) {
case V_134 :
V_264 = V_19 -> V_265 ;
break;
case V_135 :
V_264 = V_19 -> V_266 ;
break;
case V_136 :
V_264 = (struct V_138 * ) V_19 -> V_107 ;
break;
case V_137 :
V_264 = V_19 -> V_267 ;
break;
default:
return - V_139 ;
}
if ( ! V_264 )
return 0 ;
V_263 = F_75 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_76 ( V_48 , V_264 , V_263 ) )
return - V_57 ;
return V_263 ;
}
static int F_77 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 , unsigned int V_268 )
{
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_263 ;
int V_53 ;
if ( F_18 ( V_34 ) )
return F_78 ( V_2 , V_34 , V_48 , V_49 ) ;
if ( F_17 ( V_263 , V_49 ) )
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
struct V_215 V_216 ;
int V_257 ;
if ( V_263 < F_61 ( 0 ) )
return - V_139 ;
if ( F_45 ( & V_216 , V_48 , F_61 ( 0 ) ) )
return - V_57 ;
if ( V_216 . V_269 . V_203 != V_68 )
return - V_74 ;
F_21 ( V_2 ) ;
V_257 = F_79 ( V_2 , & V_216 ,
(struct V_215 T_1 * ) V_48 , V_49 ) ;
F_66 ( V_2 ) ;
return V_257 ;
}
case V_157 :
{
struct V_158 V_159 ;
struct V_60 * V_270 ;
if ( V_2 -> V_8 != V_177 )
return - V_12 ;
V_159 . V_173 = V_48 ;
V_159 . V_172 = V_263 ;
V_159 . V_271 = V_268 ;
F_21 ( V_2 ) ;
V_270 = V_51 -> V_90 ;
if ( V_270 )
F_80 ( V_2 , & V_159 , V_270 ) ;
F_66 ( V_2 ) ;
if ( ! V_270 ) {
if ( V_51 -> V_97 . V_98 . V_99 ) {
struct V_151 V_272 ;
V_272 . V_154 = V_51 -> V_191 ? V_51 -> V_191 :
V_51 -> V_155 . V_154 ;
V_272 . V_156 = V_51 -> V_191 ? V_2 -> V_73 : V_51 -> V_155 . V_156 ;
F_81 ( & V_159 , V_260 , V_150 , sizeof( V_272 ) , & V_272 ) ;
}
if ( V_51 -> V_97 . V_98 . V_103 ) {
int V_273 = V_51 -> V_178 ;
F_81 ( & V_159 , V_260 , V_274 , sizeof( V_273 ) , & V_273 ) ;
}
if ( V_51 -> V_97 . V_98 . V_121 ) {
int V_119 = ( int ) F_82 ( V_51 -> V_275 ) ;
F_81 ( & V_159 , V_260 , V_118 , sizeof( V_119 ) , & V_119 ) ;
}
if ( V_51 -> V_97 . V_98 . V_101 ) {
struct V_151 V_272 ;
V_272 . V_154 = V_51 -> V_191 ? V_51 -> V_191 :
V_51 -> V_155 . V_154 ;
V_272 . V_156 = V_51 -> V_191 ? V_2 -> V_73 :
V_51 -> V_155 . V_156 ;
F_81 ( & V_159 , V_260 , V_100 , sizeof( V_272 ) , & V_272 ) ;
}
if ( V_51 -> V_97 . V_98 . V_105 ) {
int V_273 = V_51 -> V_178 ;
F_81 ( & V_159 , V_260 , V_104 , sizeof( V_273 ) , & V_273 ) ;
}
if ( V_51 -> V_97 . V_98 . V_123 ) {
V_186 V_276 = V_51 -> V_275 ;
F_81 ( & V_159 , V_260 , V_122 , sizeof( V_276 ) , & V_276 ) ;
}
}
V_263 -= V_159 . V_172 ;
return F_83 ( V_263 , V_49 ) ;
}
case V_225 :
{
struct V_277 * V_278 ;
V_53 = 0 ;
F_52 () ;
V_278 = F_84 ( V_2 ) ;
if ( V_278 )
V_53 = F_85 ( V_278 ) ;
F_54 () ;
if ( ! V_53 )
return - V_72 ;
break;
}
case V_94 :
V_53 = V_2 -> V_95 ;
break;
case V_96 :
V_53 = V_51 -> V_97 . V_98 . V_99 ;
break;
case V_100 :
V_53 = V_51 -> V_97 . V_98 . V_101 ;
break;
case V_102 :
V_53 = V_51 -> V_97 . V_98 . V_103 ;
break;
case V_104 :
V_53 = V_51 -> V_97 . V_98 . V_105 ;
break;
case V_106 :
V_53 = V_51 -> V_97 . V_98 . V_107 ;
break;
case V_108 :
V_53 = V_51 -> V_97 . V_98 . V_109 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
{
struct V_18 * V_19 ;
F_21 ( V_2 ) ;
V_19 = F_38 ( V_51 -> V_19 ,
F_39 ( V_2 ) ) ;
V_263 = F_74 ( V_2 , V_19 , V_34 , V_48 , V_263 ) ;
F_66 ( V_2 ) ;
if ( V_263 < 0 )
return V_263 ;
return F_83 ( V_263 , V_49 ) ;
}
case V_110 :
V_53 = V_51 -> V_97 . V_98 . V_111 ;
break;
case V_112 :
V_53 = V_51 -> V_97 . V_98 . V_113 ;
break;
case V_114 :
V_53 = V_51 -> V_97 . V_98 . V_115 ;
break;
case V_116 :
V_53 = V_51 -> V_97 . V_98 . V_117 ;
break;
case V_118 :
V_53 = V_51 -> V_119 ;
break;
case V_120 :
V_53 = V_51 -> V_97 . V_98 . V_121 ;
break;
case V_122 :
V_53 = V_51 -> V_97 . V_98 . V_123 ;
break;
case V_124 :
V_53 = V_51 -> V_97 . V_98 . V_125 ;
break;
case V_279 :
{
struct V_277 * V_278 ;
struct V_280 V_281 ;
if ( V_263 < sizeof( V_281 ) )
return - V_139 ;
V_263 = sizeof( V_281 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
F_52 () ;
V_278 = F_84 ( V_2 ) ;
if ( V_278 )
V_281 . V_282 = F_85 ( V_278 ) ;
F_54 () ;
if ( ! V_281 . V_282 )
return - V_72 ;
if ( F_83 ( V_263 , V_49 ) )
return - V_57 ;
if ( F_76 ( V_48 , & V_281 , V_263 ) )
return - V_57 ;
return 0 ;
}
case V_126 :
V_53 = F_2 ( V_2 ) -> V_131 ;
break;
case V_132 :
V_53 = V_51 -> V_97 . V_98 . V_133 ;
break;
case V_174 :
case V_176 :
{
struct V_277 * V_278 ;
if ( V_34 == V_174 )
V_53 = V_51 -> V_175 ;
else
V_53 = V_51 -> V_178 ;
if ( V_53 < 0 ) {
F_52 () ;
V_278 = F_84 ( V_2 ) ;
if ( V_278 )
V_53 = F_86 ( V_278 ) ;
F_54 () ;
}
if ( V_53 < 0 )
V_53 = F_16 ( V_2 ) -> V_283 . V_284 -> V_175 ;
break;
}
case V_180 :
V_53 = V_51 -> V_181 ;
break;
case V_188 :
V_53 = V_51 -> V_191 ;
break;
case V_182 :
V_53 = ( V_33 int ) F_87 ( ( V_285 ) V_51 -> V_187 ) ;
break;
case V_221 :
V_53 = V_51 -> V_224 ;
break;
case V_228 :
V_53 = V_51 -> V_229 ;
break;
case V_231 :
V_53 = V_51 -> V_232 ;
break;
case V_233 :
{
struct V_286 V_287 ;
int V_268 ;
if ( V_263 < sizeof( V_287 ) )
return - V_139 ;
if ( F_45 ( & V_287 , V_48 , sizeof( V_287 ) ) )
return - V_57 ;
if ( V_287 . V_288 != V_289 )
return - V_139 ;
V_263 = sizeof( V_287 ) ;
V_268 = V_287 . V_290 ;
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
V_53 = F_88 ( V_2 , & V_287 , V_268 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_83 ( V_263 , V_49 ) )
return - V_57 ;
if ( F_76 ( V_48 , & V_287 , V_263 ) )
return - V_57 ;
return 0 ;
}
case V_236 :
V_53 = 0 ;
if ( V_51 -> V_248 & V_240 )
V_53 |= V_240 ;
else if ( V_51 -> V_248 & V_239 )
V_53 |= V_239 ;
else {
V_53 |= V_241 ;
}
if ( V_51 -> V_248 & V_244 )
V_53 |= V_244 ;
else
V_53 |= V_243 ;
break;
case V_249 :
V_53 = V_51 -> V_250 ;
break;
case V_251 :
V_53 = V_51 -> V_252 ;
break;
case V_253 :
V_53 = V_51 -> V_254 ;
break;
case V_255 :
V_53 = V_51 -> V_97 . V_98 . V_256 ;
break;
default:
return - V_12 ;
}
V_263 = F_75 (unsigned int, sizeof(int), len) ;
if ( F_83 ( V_263 , V_49 ) )
return - V_57 ;
if ( F_76 ( V_48 , & V_53 , V_263 ) )
return - V_57 ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_257 ;
if ( V_47 == V_258 && V_2 -> V_8 != V_9 )
return V_85 . V_291 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_260 )
return - V_12 ;
V_257 = F_77 ( V_2 , V_47 , V_34 , V_48 , V_49 , 0 ) ;
#ifdef F_69
if ( V_257 == - V_12 && V_34 != V_157 ) {
int V_263 ;
if ( F_17 ( V_263 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_257 = F_90 ( V_2 , V_261 , V_34 , V_48 ,
& V_263 ) ;
F_66 ( V_2 ) ;
if ( V_257 >= 0 )
V_257 = F_83 ( V_263 , V_49 ) ;
}
#endif
return V_257 ;
}
int F_91 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_257 ;
if ( V_47 == V_258 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_292 != NULL )
return V_85 . V_292 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_291 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_260 )
return - V_12 ;
if ( V_34 == V_46 )
return F_92 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_89 ) ;
V_257 = F_77 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
V_293 ) ;
#ifdef F_69
if ( V_257 == - V_12 && V_34 != V_157 ) {
int V_263 ;
if ( F_17 ( V_263 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_257 = F_93 ( V_2 , V_261 ,
V_34 , V_48 , & V_263 ) ;
F_66 ( V_2 ) ;
if ( V_257 >= 0 )
V_257 = F_83 ( V_263 , V_49 ) ;
}
#endif
return V_257 ;
}
