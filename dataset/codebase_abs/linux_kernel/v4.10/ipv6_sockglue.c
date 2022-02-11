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
if ( V_2 -> V_153 && V_2 -> V_153 != V_53 )
goto V_58;
V_184 = F_50 ( V_52 , V_53 ) ;
if ( ! V_184 ) {
V_55 = - V_189 ;
break;
}
F_51 ( V_184 ) ;
}
V_51 -> V_190 = V_53 ;
V_55 = 0 ;
break;
case V_36 :
case V_37 :
{
struct V_191 V_192 ;
if ( V_49 < sizeof( struct V_191 ) )
goto V_58;
V_55 = - V_193 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_55 = - V_57 ;
if ( F_45 ( & V_192 , V_48 , sizeof( struct V_191 ) ) )
break;
if ( V_34 == V_36 )
V_55 = F_52 ( V_2 , V_192 . V_194 , & V_192 . V_195 ) ;
else
V_55 = F_53 ( V_2 , V_192 . V_194 , & V_192 . V_195 ) ;
break;
}
case V_38 :
case V_39 :
{
struct V_191 V_192 ;
if ( V_49 < sizeof( struct V_191 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_192 , V_48 , sizeof( struct V_191 ) ) )
break;
if ( V_34 == V_38 )
V_55 = F_54 ( V_2 , V_192 . V_194 , & V_192 . V_196 ) ;
else
V_55 = F_55 ( V_2 , V_192 . V_194 , & V_192 . V_196 ) ;
break;
}
case V_40 :
case V_41 :
{
struct V_197 V_198 ;
struct V_199 * V_200 ;
if ( V_49 < sizeof( struct V_197 ) )
goto V_58;
V_55 = - V_57 ;
if ( F_45 ( & V_198 , V_48 , sizeof( struct V_197 ) ) )
break;
if ( V_198 . V_201 . V_202 != V_68 ) {
V_55 = - V_74 ;
break;
}
V_200 = (struct V_199 * ) & V_198 . V_201 ;
if ( V_34 == V_40 )
V_55 = F_52 ( V_2 , V_198 . V_203 ,
& V_200 -> V_204 ) ;
else
V_55 = F_53 ( V_2 , V_198 . V_203 ,
& V_200 -> V_204 ) ;
break;
}
case V_42 :
case V_43 :
case V_44 :
case V_45 :
{
struct V_205 V_206 ;
int V_207 , V_208 ;
if ( V_49 < sizeof( struct V_205 ) )
goto V_58;
if ( F_45 ( & V_206 , V_48 , sizeof( V_206 ) ) ) {
V_55 = - V_57 ;
break;
}
if ( V_206 . V_209 . V_202 != V_68 ||
V_206 . V_210 . V_202 != V_68 ) {
V_55 = - V_74 ;
break;
}
if ( V_34 == V_44 ) {
V_207 = V_211 ;
V_208 = 1 ;
} else if ( V_34 == V_45 ) {
V_207 = V_211 ;
V_208 = 0 ;
} else if ( V_34 == V_42 ) {
struct V_199 * V_200 ;
V_200 = (struct V_199 * ) & V_206 . V_209 ;
V_55 = F_52 ( V_2 , V_206 . V_212 ,
& V_200 -> V_204 ) ;
if ( V_55 && V_55 != - V_16 )
break;
V_207 = V_213 ;
V_208 = 1 ;
} else {
V_207 = V_213 ;
V_208 = 0 ;
}
V_55 = F_56 ( V_208 , V_207 , V_2 , & V_206 ) ;
break;
}
case V_46 :
{
struct V_214 * V_215 ;
if ( V_49 < F_57 ( 0 ) )
goto V_58;
if ( V_49 > V_216 ) {
V_55 = - V_17 ;
break;
}
V_215 = F_3 ( V_49 , V_13 ) ;
if ( ! V_215 ) {
V_55 = - V_17 ;
break;
}
V_55 = - V_57 ;
if ( F_45 ( V_215 , V_48 , V_49 ) ) {
F_6 ( V_215 ) ;
break;
}
if ( V_215 -> V_217 >= 0x1ffffffU ||
V_215 -> V_217 > V_218 ) {
F_6 ( V_215 ) ;
V_55 = - V_17 ;
break;
}
if ( F_57 ( V_215 -> V_217 ) > V_49 ) {
F_6 ( V_215 ) ;
V_55 = - V_139 ;
break;
}
V_55 = F_58 ( V_2 , V_215 ) ;
F_6 ( V_215 ) ;
break;
}
case V_219 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = F_1 ( V_2 , V_53 ) ;
break;
case V_220 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < V_221 || V_53 > V_222 )
goto V_58;
V_51 -> V_223 = V_53 ;
V_55 = 0 ;
break;
case V_224 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 && V_53 < V_225 )
goto V_58;
V_51 -> V_226 = V_53 ;
V_55 = 0 ;
break;
case V_227 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_228 = V_54 ;
if ( ! V_53 )
F_59 ( & V_2 -> V_229 ) ;
V_55 = 0 ;
break;
case V_230 :
if ( V_49 < sizeof( int ) )
goto V_58;
V_51 -> V_231 = V_54 ;
V_55 = 0 ;
break;
case V_232 :
V_55 = F_60 ( V_2 , V_48 , V_49 ) ;
break;
case V_233 :
case V_234 :
V_55 = - V_130 ;
if ( ! F_37 ( V_52 -> V_127 , V_128 ) )
break;
V_55 = F_61 ( V_2 , V_34 , V_48 , V_49 ) ;
break;
case V_235 :
{
unsigned int V_236 = 0 ;
unsigned int V_237 = ~ 0 ;
if ( V_49 < sizeof( int ) )
goto V_58;
V_55 = - V_139 ;
switch ( V_53 & ( V_238 |
V_239 |
V_240 ) ) {
case V_238 :
V_236 |= V_238 ;
break;
case V_239 :
V_236 |= V_239 ;
break;
case V_240 :
break;
case 0 :
goto V_241;
default:
goto V_58;
}
V_237 &= ~ ( V_238 |
V_239 ) ;
V_241:
switch ( V_53 & ( V_242 | V_243 ) ) {
case V_242 :
break;
case V_243 :
V_236 |= V_243 ;
case 0 :
goto V_244;
default:
goto V_58;
}
V_237 &= ~ V_243 ;
V_244:
switch ( V_53 & ( V_245 | V_246 ) ) {
case V_245 :
case V_246 :
case 0 :
break;
default:
goto V_58;
}
V_51 -> V_247 = ( V_51 -> V_247 & V_237 ) | V_236 ;
V_55 = 0 ;
break;
}
case V_248 :
if ( V_49 < sizeof( int ) )
goto V_58;
if ( V_53 < 0 || V_53 > 255 )
goto V_58;
V_51 -> V_249 = V_53 ;
V_55 = 0 ;
break;
case V_250 :
V_51 -> V_251 = V_54 ;
V_55 = 0 ;
break;
case V_252 :
V_51 -> V_253 = V_54 ;
V_55 = 0 ;
break;
case V_254 :
V_51 -> V_97 . V_98 . V_255 = V_54 ;
V_55 = 0 ;
break;
}
F_62 ( V_2 ) ;
if ( V_56 )
F_63 () ;
return V_55 ;
V_58:
F_62 ( V_2 ) ;
if ( V_56 )
F_63 () ;
return - V_139 ;
}
int F_64 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_256 ;
if ( V_47 == V_257 && V_2 -> V_8 != V_9 )
return V_85 . V_258 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_259 )
return - V_12 ;
V_256 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_65
if ( V_256 == - V_12 && V_34 != V_233 &&
V_34 != V_234 ) {
F_21 ( V_2 ) ;
V_256 = F_66 ( V_2 , V_260 , V_34 , V_48 ,
V_49 ) ;
F_62 ( V_2 ) ;
}
#endif
return V_256 ;
}
int F_67 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , unsigned int V_49 )
{
int V_256 ;
if ( V_47 == V_257 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_261 != NULL )
return V_85 . V_261 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_258 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_259 )
return - V_12 ;
if ( V_34 >= V_40 && V_34 <= V_46 )
return F_68 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_64 ) ;
V_256 = F_15 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
#ifdef F_65
if ( V_256 == - V_12 && V_34 != V_233 &&
V_34 != V_234 ) {
F_21 ( V_2 ) ;
V_256 = F_69 ( V_2 , V_260 , V_34 ,
V_48 , V_49 ) ;
F_62 ( V_2 ) ;
}
#endif
return V_256 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_34 , char T_1 * V_48 , int V_262 )
{
struct V_138 * V_263 ;
if ( ! V_19 )
return 0 ;
switch ( V_34 ) {
case V_134 :
V_263 = V_19 -> V_264 ;
break;
case V_135 :
V_263 = V_19 -> V_265 ;
break;
case V_136 :
V_263 = (struct V_138 * ) V_19 -> V_107 ;
break;
case V_137 :
V_263 = V_19 -> V_266 ;
break;
default:
return - V_139 ;
}
if ( ! V_263 )
return 0 ;
V_262 = F_71 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_72 ( V_48 , V_263 , V_262 ) )
return - V_57 ;
return V_262 ;
}
static int F_73 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 , unsigned int V_267 )
{
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_262 ;
int V_53 ;
if ( F_18 ( V_34 ) )
return F_74 ( V_2 , V_34 , V_48 , V_49 ) ;
if ( F_17 ( V_262 , V_49 ) )
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
struct V_214 V_215 ;
int V_256 ;
if ( V_262 < F_57 ( 0 ) )
return - V_139 ;
if ( F_45 ( & V_215 , V_48 , F_57 ( 0 ) ) )
return - V_57 ;
if ( V_215 . V_268 . V_202 != V_68 )
return - V_74 ;
F_21 ( V_2 ) ;
V_256 = F_75 ( V_2 , & V_215 ,
(struct V_214 T_1 * ) V_48 , V_49 ) ;
F_62 ( V_2 ) ;
return V_256 ;
}
case V_157 :
{
struct V_158 V_159 ;
struct V_60 * V_269 ;
if ( V_2 -> V_8 != V_177 )
return - V_12 ;
V_159 . V_173 = V_48 ;
V_159 . V_172 = V_262 ;
V_159 . V_270 = V_267 ;
F_21 ( V_2 ) ;
V_269 = V_51 -> V_90 ;
if ( V_269 )
F_76 ( V_2 , & V_159 , V_269 ) ;
F_62 ( V_2 ) ;
if ( ! V_269 ) {
if ( V_51 -> V_97 . V_98 . V_99 ) {
struct V_151 V_271 ;
V_271 . V_154 = V_51 -> V_190 ? V_51 -> V_190 :
V_51 -> V_155 . V_154 ;
V_271 . V_156 = V_51 -> V_190 ? V_2 -> V_73 : V_51 -> V_155 . V_156 ;
F_77 ( & V_159 , V_259 , V_150 , sizeof( V_271 ) , & V_271 ) ;
}
if ( V_51 -> V_97 . V_98 . V_103 ) {
int V_272 = V_51 -> V_178 ;
F_77 ( & V_159 , V_259 , V_273 , sizeof( V_272 ) , & V_272 ) ;
}
if ( V_51 -> V_97 . V_98 . V_121 ) {
int V_119 = ( int ) F_78 ( V_51 -> V_274 ) ;
F_77 ( & V_159 , V_259 , V_118 , sizeof( V_119 ) , & V_119 ) ;
}
if ( V_51 -> V_97 . V_98 . V_101 ) {
struct V_151 V_271 ;
V_271 . V_154 = V_51 -> V_190 ? V_51 -> V_190 :
V_51 -> V_155 . V_154 ;
V_271 . V_156 = V_51 -> V_190 ? V_2 -> V_73 :
V_51 -> V_155 . V_156 ;
F_77 ( & V_159 , V_259 , V_100 , sizeof( V_271 ) , & V_271 ) ;
}
if ( V_51 -> V_97 . V_98 . V_105 ) {
int V_272 = V_51 -> V_178 ;
F_77 ( & V_159 , V_259 , V_104 , sizeof( V_272 ) , & V_272 ) ;
}
if ( V_51 -> V_97 . V_98 . V_123 ) {
V_186 V_275 = V_51 -> V_274 ;
F_77 ( & V_159 , V_259 , V_122 , sizeof( V_275 ) , & V_275 ) ;
}
}
V_262 -= V_159 . V_172 ;
return F_79 ( V_262 , V_49 ) ;
}
case V_224 :
{
struct V_276 * V_277 ;
V_53 = 0 ;
F_80 () ;
V_277 = F_81 ( V_2 ) ;
if ( V_277 )
V_53 = F_82 ( V_277 ) ;
F_83 () ;
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
V_262 = F_70 ( V_2 , V_19 , V_34 , V_48 , V_262 ) ;
F_62 ( V_2 ) ;
if ( V_262 < 0 )
return V_262 ;
return F_79 ( V_262 , V_49 ) ;
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
case V_278 :
{
struct V_276 * V_277 ;
struct V_279 V_280 ;
if ( V_262 < sizeof( V_280 ) )
return - V_139 ;
V_262 = sizeof( V_280 ) ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
F_80 () ;
V_277 = F_81 ( V_2 ) ;
if ( V_277 )
V_280 . V_281 = F_82 ( V_277 ) ;
F_83 () ;
if ( ! V_280 . V_281 )
return - V_72 ;
if ( F_79 ( V_262 , V_49 ) )
return - V_57 ;
if ( F_72 ( V_48 , & V_280 , V_262 ) )
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
struct V_276 * V_277 ;
if ( V_34 == V_174 )
V_53 = V_51 -> V_175 ;
else
V_53 = V_51 -> V_178 ;
if ( V_53 < 0 ) {
F_80 () ;
V_277 = F_81 ( V_2 ) ;
if ( V_277 )
V_53 = F_84 ( V_277 ) ;
F_83 () ;
}
if ( V_53 < 0 )
V_53 = F_16 ( V_2 ) -> V_282 . V_283 -> V_175 ;
break;
}
case V_180 :
V_53 = V_51 -> V_181 ;
break;
case V_188 :
V_53 = V_51 -> V_190 ;
break;
case V_182 :
V_53 = ( V_33 int ) F_85 ( ( V_284 ) V_51 -> V_187 ) ;
break;
case V_220 :
V_53 = V_51 -> V_223 ;
break;
case V_227 :
V_53 = V_51 -> V_228 ;
break;
case V_230 :
V_53 = V_51 -> V_231 ;
break;
case V_232 :
{
struct V_285 V_286 ;
int V_267 ;
if ( V_262 < sizeof( V_286 ) )
return - V_139 ;
if ( F_45 ( & V_286 , V_48 , sizeof( V_286 ) ) )
return - V_57 ;
if ( V_286 . V_287 != V_288 )
return - V_139 ;
V_262 = sizeof( V_286 ) ;
V_267 = V_286 . V_289 ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
V_53 = F_86 ( V_2 , & V_286 , V_267 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_79 ( V_262 , V_49 ) )
return - V_57 ;
if ( F_72 ( V_48 , & V_286 , V_262 ) )
return - V_57 ;
return 0 ;
}
case V_235 :
V_53 = 0 ;
if ( V_51 -> V_247 & V_239 )
V_53 |= V_239 ;
else if ( V_51 -> V_247 & V_238 )
V_53 |= V_238 ;
else {
V_53 |= V_240 ;
}
if ( V_51 -> V_247 & V_243 )
V_53 |= V_243 ;
else
V_53 |= V_242 ;
break;
case V_248 :
V_53 = V_51 -> V_249 ;
break;
case V_250 :
V_53 = V_51 -> V_251 ;
break;
case V_252 :
V_53 = V_51 -> V_253 ;
break;
case V_254 :
V_53 = V_51 -> V_97 . V_98 . V_255 ;
break;
default:
return - V_12 ;
}
V_262 = F_71 (unsigned int, sizeof(int), len) ;
if ( F_79 ( V_262 , V_49 ) )
return - V_57 ;
if ( F_72 ( V_48 , & V_53 , V_262 ) )
return - V_57 ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_256 ;
if ( V_47 == V_257 && V_2 -> V_8 != V_9 )
return V_85 . V_290 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
if ( V_47 != V_259 )
return - V_12 ;
V_256 = F_73 ( V_2 , V_47 , V_34 , V_48 , V_49 , 0 ) ;
#ifdef F_65
if ( V_256 == - V_12 && V_34 != V_157 ) {
int V_262 ;
if ( F_17 ( V_262 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_256 = F_88 ( V_2 , V_260 , V_34 , V_48 ,
& V_262 ) ;
F_62 ( V_2 ) ;
if ( V_256 >= 0 )
V_256 = F_79 ( V_262 , V_49 ) ;
}
#endif
return V_256 ;
}
int F_89 ( struct V_1 * V_2 , int V_47 , int V_34 ,
char T_1 * V_48 , int T_1 * V_49 )
{
int V_256 ;
if ( V_47 == V_257 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_291 != NULL )
return V_85 . V_291 ( V_2 , V_47 , V_34 ,
V_48 , V_49 ) ;
return V_85 . V_290 ( V_2 , V_47 , V_34 , V_48 , V_49 ) ;
}
if ( V_47 != V_259 )
return - V_12 ;
if ( V_34 == V_46 )
return F_90 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
F_87 ) ;
V_256 = F_73 ( V_2 , V_47 , V_34 , V_48 , V_49 ,
V_292 ) ;
#ifdef F_65
if ( V_256 == - V_12 && V_34 != V_157 ) {
int V_262 ;
if ( F_17 ( V_262 , V_49 ) )
return - V_57 ;
F_21 ( V_2 ) ;
V_256 = F_91 ( V_2 , V_260 ,
V_34 , V_48 , & V_262 ) ;
F_62 ( V_2 ) ;
if ( V_256 >= 0 )
V_256 = F_79 ( V_262 , V_49 ) ;
}
#endif
return V_256 ;
}
