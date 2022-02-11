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
static
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
return true ;
}
return false ;
}
static int F_15 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , unsigned int V_48 )
{
struct V_49 * V_50 = F_12 ( V_2 ) ;
struct V_51 * V_51 = F_16 ( V_2 ) ;
int V_52 , V_53 ;
int V_54 = - V_12 ;
bool V_55 = F_14 ( V_34 ) ;
if ( ! V_47 )
V_52 = 0 ;
else {
if ( V_48 >= sizeof( int ) ) {
if ( F_17 ( V_52 , ( int T_1 * ) V_47 ) )
return - V_56 ;
} else
V_52 = 0 ;
}
V_53 = ( V_52 != 0 ) ;
if ( F_18 ( V_34 ) )
return F_19 ( V_2 , V_34 , V_47 , V_48 ) ;
if ( V_55 )
F_20 () ;
F_21 ( V_2 ) ;
switch ( V_34 ) {
case V_57 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 == V_59 ) {
struct V_18 * V_19 ;
struct V_60 * V_61 ;
if ( V_2 -> V_8 == V_9 )
break;
if ( V_2 -> V_62 == V_63 ||
V_2 -> V_62 == V_64 ) {
struct V_65 * V_66 = F_22 ( V_2 ) ;
if ( V_66 -> V_67 == V_68 ) {
V_54 = - V_69 ;
break;
}
} else if ( V_2 -> V_62 != V_70 )
break;
if ( V_2 -> V_21 != V_71 ) {
V_54 = - V_72 ;
break;
}
if ( F_23 ( V_2 ) ||
! F_24 ( & V_2 -> V_73 ) ) {
V_54 = - V_74 ;
break;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_62 == V_70 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_28 () ;
F_29 ( V_51 , V_2 -> V_75 , - 1 ) ;
F_29 ( V_51 , & V_76 , 1 ) ;
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
F_29 ( V_51 , V_2 -> V_75 , - 1 ) ;
F_29 ( V_51 , V_84 , 1 ) ;
F_30 () ;
V_2 -> V_75 = V_84 ;
V_2 -> V_79 -> V_80 = & V_87 ;
V_2 -> V_82 = V_59 ;
}
V_19 = F_11 ( ( V_33 struct V_18 * * ) & V_50 -> V_19 ,
NULL ) ;
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
V_61 = F_11 ( & V_50 -> V_90 , NULL ) ;
F_34 ( V_61 ) ;
V_2 -> V_91 = V_92 ;
F_35 ( V_2 ) ;
F_36 ( V_93 ) ;
V_54 = 0 ;
break;
}
goto V_58;
case V_94 :
if ( V_48 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_58;
V_2 -> V_95 = V_53 ;
V_54 = 0 ;
break;
case V_96 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_99 = V_53 ;
V_54 = 0 ;
break;
case V_100 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_101 = V_53 ;
V_54 = 0 ;
break;
case V_102 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_103 = V_53 ;
V_54 = 0 ;
break;
case V_104 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_105 = V_53 ;
V_54 = 0 ;
break;
case V_106 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_107 = V_53 ;
V_54 = 0 ;
break;
case V_108 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_109 = V_53 ;
V_54 = 0 ;
break;
case V_110 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_111 = V_53 ;
V_54 = 0 ;
break;
case V_112 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_113 = V_53 ;
V_54 = 0 ;
break;
case V_114 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_115 = V_53 ;
V_54 = 0 ;
break;
case V_116 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_117 = V_53 ;
V_54 = 0 ;
break;
case V_118 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 < - 1 || V_52 > 0xff )
goto V_58;
if ( V_52 == - 1 )
V_52 = 0 ;
V_50 -> V_119 = V_52 ;
V_54 = 0 ;
break;
case V_120 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_121 = V_53 ;
V_54 = 0 ;
break;
case V_122 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_123 = V_53 ;
V_54 = 0 ;
break;
case V_124 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_125 = V_53 ;
V_54 = 0 ;
break;
case V_126 :
if ( V_53 && ! F_37 ( V_51 -> V_127 , V_128 ) &&
! F_37 ( V_51 -> V_127 , V_129 ) ) {
V_54 = - V_130 ;
break;
}
if ( V_48 < sizeof( int ) )
goto V_58;
F_2 ( V_2 ) -> V_131 = V_53 ;
V_54 = 0 ;
break;
case V_132 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_97 . V_98 . V_133 = V_53 ;
V_54 = 0 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
{
struct V_18 * V_19 ;
if ( V_48 == 0 )
V_47 = NULL ;
else if ( ! V_47 )
goto V_58;
else if ( V_48 < sizeof( struct V_138 ) ||
V_48 & 0x7 || V_48 > 8 * 255 )
goto V_58;
V_54 = - V_130 ;
if ( V_34 != V_136 && ! F_37 ( V_51 -> V_127 , V_129 ) )
break;
V_19 = F_38 ( V_50 -> V_19 ,
F_39 ( V_2 ) ) ;
V_19 = F_40 ( V_2 , V_19 , V_34 ,
(struct V_138 T_1 * ) V_47 ,
V_48 ) ;
if ( F_41 ( V_19 ) ) {
V_54 = F_42 ( V_19 ) ;
break;
}
V_54 = - V_139 ;
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
default:
goto V_146;
}
}
V_54 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_146:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_147 :
{
struct V_148 V_149 ;
if ( V_48 == 0 )
goto V_58;
else if ( V_48 < sizeof( struct V_148 ) || ! V_47 )
goto V_58;
if ( F_44 ( & V_149 , V_47 , sizeof( struct V_148 ) ) ) {
V_54 = - V_56 ;
break;
}
if ( V_2 -> V_150 && V_149 . V_151 != V_2 -> V_150 )
goto V_58;
V_50 -> V_152 . V_151 = V_149 . V_151 ;
V_50 -> V_152 . V_153 = V_149 . V_153 ;
V_54 = 0 ;
break;
}
case V_154 :
{
struct V_18 * V_19 = NULL ;
struct V_155 V_156 ;
struct V_157 V_158 ;
struct V_159 V_160 ;
struct V_161 V_162 ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_163 = V_2 -> V_150 ;
V_158 . V_164 = V_2 -> V_165 ;
if ( V_48 == 0 )
goto V_166;
V_54 = - V_139 ;
if ( V_48 > 64 * 1024 )
break;
V_19 = F_45 ( V_2 , sizeof( * V_19 ) + V_48 , V_13 ) ;
V_54 = - V_17 ;
if ( ! V_19 )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_46 ( & V_19 -> V_167 , 1 ) ;
V_19 -> V_88 = sizeof( * V_19 ) + V_48 ;
V_54 = - V_56 ;
if ( F_44 ( V_19 + 1 , V_47 , V_48 ) )
goto V_168;
V_156 . V_169 = V_48 ;
V_156 . V_170 = ( void * ) ( V_19 + 1 ) ;
V_162 . V_19 = V_19 ;
V_54 = F_47 ( V_51 , V_2 , & V_156 , & V_158 , & V_162 , & V_160 ) ;
if ( V_54 )
goto V_168;
V_166:
V_54 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_168:
if ( V_19 ) {
F_32 ( V_19 -> V_88 , & V_2 -> V_89 ) ;
F_33 ( V_19 ) ;
}
break;
}
case V_171 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 > 255 || V_52 < - 1 )
goto V_58;
V_50 -> V_172 = V_52 ;
V_54 = 0 ;
break;
case V_173 :
if ( V_2 -> V_8 == V_174 )
break;
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 > 255 || V_52 < - 1 )
goto V_58;
V_50 -> V_175 = ( V_52 == - 1 ? V_176 : V_52 ) ;
V_54 = 0 ;
break;
case V_177 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 != V_53 )
goto V_58;
V_50 -> V_178 = V_53 ;
V_54 = 0 ;
break;
case V_179 :
{
struct V_180 * V_181 = NULL ;
int V_182 ;
if ( V_48 != sizeof( int ) )
goto V_58;
V_182 = ( V_33 int ) F_48 ( ( V_33 V_183 ) V_52 ) ;
if ( V_182 == 0 ) {
V_50 -> V_184 = 0 ;
V_54 = 0 ;
break;
}
V_181 = F_49 ( V_51 , V_182 ) ;
V_54 = - V_74 ;
if ( ! V_181 )
break;
F_50 ( V_181 ) ;
V_54 = - V_139 ;
if ( V_2 -> V_150 )
break;
V_50 -> V_184 = V_182 ;
V_54 = 0 ;
break;
}
case V_185 :
if ( V_2 -> V_8 == V_174 )
break;
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 ) {
struct V_180 * V_181 ;
if ( V_2 -> V_150 && V_2 -> V_150 != V_52 )
goto V_58;
V_181 = F_49 ( V_51 , V_52 ) ;
if ( ! V_181 ) {
V_54 = - V_186 ;
break;
}
F_50 ( V_181 ) ;
}
V_50 -> V_187 = V_52 ;
V_54 = 0 ;
break;
case V_35 :
case V_36 :
{
struct V_188 V_189 ;
if ( V_48 < sizeof( struct V_188 ) )
goto V_58;
V_54 = - V_190 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_54 = - V_56 ;
if ( F_44 ( & V_189 , V_47 , sizeof( struct V_188 ) ) )
break;
if ( V_34 == V_35 )
V_54 = F_51 ( V_2 , V_189 . V_191 , & V_189 . V_192 ) ;
else
V_54 = F_52 ( V_2 , V_189 . V_191 , & V_189 . V_192 ) ;
break;
}
case V_37 :
case V_38 :
{
struct V_188 V_189 ;
if ( V_48 < sizeof( struct V_188 ) )
goto V_58;
V_54 = - V_56 ;
if ( F_44 ( & V_189 , V_47 , sizeof( struct V_188 ) ) )
break;
if ( V_34 == V_37 )
V_54 = F_53 ( V_2 , V_189 . V_191 , & V_189 . V_193 ) ;
else
V_54 = F_54 ( V_2 , V_189 . V_191 , & V_189 . V_193 ) ;
break;
}
case V_39 :
case V_40 :
{
struct V_194 V_195 ;
struct V_196 * V_197 ;
if ( V_48 < sizeof( struct V_194 ) )
goto V_58;
V_54 = - V_56 ;
if ( F_44 ( & V_195 , V_47 , sizeof( struct V_194 ) ) )
break;
if ( V_195 . V_198 . V_199 != V_68 ) {
V_54 = - V_74 ;
break;
}
V_197 = (struct V_196 * ) & V_195 . V_198 ;
if ( V_34 == V_39 )
V_54 = F_51 ( V_2 , V_195 . V_200 ,
& V_197 -> V_201 ) ;
else
V_54 = F_52 ( V_2 , V_195 . V_200 ,
& V_197 -> V_201 ) ;
break;
}
case V_41 :
case V_42 :
case V_43 :
case V_44 :
{
struct V_202 V_203 ;
int V_204 , V_205 ;
if ( V_48 < sizeof( struct V_202 ) )
goto V_58;
if ( F_44 ( & V_203 , V_47 , sizeof( V_203 ) ) ) {
V_54 = - V_56 ;
break;
}
if ( V_203 . V_206 . V_199 != V_68 ||
V_203 . V_207 . V_199 != V_68 ) {
V_54 = - V_74 ;
break;
}
if ( V_34 == V_43 ) {
V_204 = V_208 ;
V_205 = 1 ;
} else if ( V_34 == V_44 ) {
V_204 = V_208 ;
V_205 = 0 ;
} else if ( V_34 == V_41 ) {
struct V_196 * V_197 ;
V_197 = (struct V_196 * ) & V_203 . V_206 ;
V_54 = F_51 ( V_2 , V_203 . V_209 ,
& V_197 -> V_201 ) ;
if ( V_54 && V_54 != - V_16 )
break;
V_204 = V_210 ;
V_205 = 1 ;
} else {
V_204 = V_210 ;
V_205 = 0 ;
}
V_54 = F_55 ( V_205 , V_204 , V_2 , & V_203 ) ;
break;
}
case V_45 :
{
struct V_211 * V_212 ;
if ( V_48 < F_56 ( 0 ) )
goto V_58;
if ( V_48 > V_213 ) {
V_54 = - V_17 ;
break;
}
V_212 = F_3 ( V_48 , V_13 ) ;
if ( ! V_212 ) {
V_54 = - V_17 ;
break;
}
V_54 = - V_56 ;
if ( F_44 ( V_212 , V_47 , V_48 ) ) {
F_6 ( V_212 ) ;
break;
}
if ( V_212 -> V_214 >= 0x1ffffffU ||
V_212 -> V_214 > V_215 ) {
F_6 ( V_212 ) ;
V_54 = - V_17 ;
break;
}
if ( F_56 ( V_212 -> V_214 ) > V_48 ) {
F_6 ( V_212 ) ;
V_54 = - V_139 ;
break;
}
V_54 = F_57 ( V_2 , V_212 ) ;
F_6 ( V_212 ) ;
break;
}
case V_216 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_54 = F_1 ( V_2 , V_52 ) ;
break;
case V_217 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 < V_218 || V_52 > V_219 )
goto V_58;
V_50 -> V_220 = V_52 ;
V_54 = 0 ;
break;
case V_221 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 && V_52 < V_222 )
goto V_58;
V_50 -> V_223 = V_52 ;
V_54 = 0 ;
break;
case V_224 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_225 = V_53 ;
if ( ! V_52 )
F_58 ( & V_2 -> V_226 ) ;
V_54 = 0 ;
break;
case V_227 :
if ( V_48 < sizeof( int ) )
goto V_58;
V_50 -> V_228 = V_53 ;
V_54 = 0 ;
break;
case V_229 :
V_54 = F_59 ( V_2 , V_47 , V_48 ) ;
break;
case V_230 :
case V_231 :
V_54 = - V_130 ;
if ( ! F_37 ( V_51 -> V_127 , V_128 ) )
break;
V_54 = F_60 ( V_2 , V_34 , V_47 , V_48 ) ;
break;
case V_232 :
{
unsigned int V_233 = 0 ;
unsigned int V_234 = ~ 0 ;
if ( V_48 < sizeof( int ) )
goto V_58;
V_54 = - V_139 ;
switch ( V_52 & ( V_235 |
V_236 |
V_237 ) ) {
case V_235 :
V_233 |= V_235 ;
break;
case V_236 :
V_233 |= V_236 ;
break;
case V_237 :
break;
case 0 :
goto V_238;
default:
goto V_58;
}
V_234 &= ~ ( V_235 |
V_236 ) ;
V_238:
switch ( V_52 & ( V_239 | V_240 ) ) {
case V_239 :
break;
case V_240 :
V_233 |= V_240 ;
case 0 :
goto V_241;
default:
goto V_58;
}
V_234 &= ~ V_240 ;
V_241:
switch ( V_52 & ( V_242 | V_243 ) ) {
case V_242 :
case V_243 :
case 0 :
break;
default:
goto V_58;
}
V_50 -> V_244 = ( V_50 -> V_244 & V_234 ) | V_233 ;
V_54 = 0 ;
break;
}
case V_245 :
if ( V_48 < sizeof( int ) )
goto V_58;
if ( V_52 < 0 || V_52 > 255 )
goto V_58;
V_50 -> V_246 = V_52 ;
V_54 = 0 ;
break;
case V_247 :
V_50 -> V_248 = V_53 ;
V_54 = 0 ;
break;
case V_249 :
V_50 -> V_250 = V_53 ;
V_54 = 0 ;
break;
}
F_61 ( V_2 ) ;
if ( V_55 )
F_62 () ;
return V_54 ;
V_58:
F_61 ( V_2 ) ;
if ( V_55 )
F_62 () ;
return - V_139 ;
}
int F_63 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , unsigned int V_48 )
{
int V_251 ;
if ( V_46 == V_252 && V_2 -> V_8 != V_9 )
return V_85 . V_253 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
if ( V_46 != V_254 )
return - V_12 ;
V_251 = F_15 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
#ifdef F_64
if ( V_251 == - V_12 && V_34 != V_230 &&
V_34 != V_231 ) {
F_21 ( V_2 ) ;
V_251 = F_65 ( V_2 , V_255 , V_34 , V_47 ,
V_48 ) ;
F_61 ( V_2 ) ;
}
#endif
return V_251 ;
}
int F_66 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , unsigned int V_48 )
{
int V_251 ;
if ( V_46 == V_252 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_256 != NULL )
return V_85 . V_256 ( V_2 , V_46 , V_34 ,
V_47 , V_48 ) ;
return V_85 . V_253 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
}
if ( V_46 != V_254 )
return - V_12 ;
if ( V_34 >= V_39 && V_34 <= V_45 )
return F_67 ( V_2 , V_46 , V_34 , V_47 , V_48 ,
F_63 ) ;
V_251 = F_15 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
#ifdef F_64
if ( V_251 == - V_12 && V_34 != V_230 &&
V_34 != V_231 ) {
F_21 ( V_2 ) ;
V_251 = F_68 ( V_2 , V_255 , V_34 ,
V_47 , V_48 ) ;
F_61 ( V_2 ) ;
}
#endif
return V_251 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_34 , char T_1 * V_47 , int V_257 )
{
struct V_138 * V_258 ;
if ( ! V_19 )
return 0 ;
switch ( V_34 ) {
case V_134 :
V_258 = V_19 -> V_259 ;
break;
case V_135 :
V_258 = V_19 -> V_260 ;
break;
case V_136 :
V_258 = (struct V_138 * ) V_19 -> V_107 ;
break;
case V_137 :
V_258 = V_19 -> V_261 ;
break;
default:
return - V_139 ;
}
if ( ! V_258 )
return 0 ;
V_257 = F_70 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_71 ( V_47 , V_258 , V_257 ) )
return - V_56 ;
return V_257 ;
}
static int F_72 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , int T_1 * V_48 , unsigned int V_262 )
{
struct V_49 * V_50 = F_12 ( V_2 ) ;
int V_257 ;
int V_52 ;
if ( F_18 ( V_34 ) )
return F_73 ( V_2 , V_34 , V_47 , V_48 ) ;
if ( F_17 ( V_257 , V_48 ) )
return - V_56 ;
switch ( V_34 ) {
case V_57 :
if ( V_2 -> V_62 != V_63 &&
V_2 -> V_62 != V_64 &&
V_2 -> V_62 != V_70 )
return - V_12 ;
if ( V_2 -> V_21 != V_71 )
return - V_72 ;
V_52 = V_2 -> V_82 ;
break;
case V_45 :
{
struct V_211 V_212 ;
int V_251 ;
if ( V_257 < F_56 ( 0 ) )
return - V_139 ;
if ( F_44 ( & V_212 , V_47 , F_56 ( 0 ) ) )
return - V_56 ;
if ( V_212 . V_263 . V_199 != V_68 )
return - V_74 ;
F_21 ( V_2 ) ;
V_251 = F_74 ( V_2 , & V_212 ,
(struct V_211 T_1 * ) V_47 , V_48 ) ;
F_61 ( V_2 ) ;
return V_251 ;
}
case V_154 :
{
struct V_155 V_156 ;
struct V_60 * V_264 ;
if ( V_2 -> V_8 != V_174 )
return - V_12 ;
V_156 . V_170 = V_47 ;
V_156 . V_169 = V_257 ;
V_156 . V_265 = V_262 ;
F_21 ( V_2 ) ;
V_264 = V_50 -> V_90 ;
if ( V_264 )
F_75 ( V_2 , & V_156 , V_264 ) ;
F_61 ( V_2 ) ;
if ( ! V_264 ) {
if ( V_50 -> V_97 . V_98 . V_99 ) {
struct V_148 V_266 ;
V_266 . V_151 = V_50 -> V_187 ? V_50 -> V_187 :
V_50 -> V_152 . V_151 ;
V_266 . V_153 = V_50 -> V_187 ? V_2 -> V_73 : V_50 -> V_152 . V_153 ;
F_76 ( & V_156 , V_254 , V_147 , sizeof( V_266 ) , & V_266 ) ;
}
if ( V_50 -> V_97 . V_98 . V_103 ) {
int V_267 = V_50 -> V_175 ;
F_76 ( & V_156 , V_254 , V_268 , sizeof( V_267 ) , & V_267 ) ;
}
if ( V_50 -> V_97 . V_98 . V_121 ) {
int V_119 = ( int ) F_77 ( V_50 -> V_269 ) ;
F_76 ( & V_156 , V_254 , V_118 , sizeof( V_119 ) , & V_119 ) ;
}
if ( V_50 -> V_97 . V_98 . V_101 ) {
struct V_148 V_266 ;
V_266 . V_151 = V_50 -> V_187 ? V_50 -> V_187 :
V_50 -> V_152 . V_151 ;
V_266 . V_153 = V_50 -> V_187 ? V_2 -> V_73 :
V_50 -> V_152 . V_153 ;
F_76 ( & V_156 , V_254 , V_100 , sizeof( V_266 ) , & V_266 ) ;
}
if ( V_50 -> V_97 . V_98 . V_105 ) {
int V_267 = V_50 -> V_175 ;
F_76 ( & V_156 , V_254 , V_104 , sizeof( V_267 ) , & V_267 ) ;
}
if ( V_50 -> V_97 . V_98 . V_123 ) {
V_183 V_270 = V_50 -> V_269 ;
F_76 ( & V_156 , V_254 , V_122 , sizeof( V_270 ) , & V_270 ) ;
}
}
V_257 -= V_156 . V_169 ;
return F_78 ( V_257 , V_48 ) ;
}
case V_221 :
{
struct V_271 * V_272 ;
V_52 = 0 ;
F_79 () ;
V_272 = F_80 ( V_2 ) ;
if ( V_272 )
V_52 = F_81 ( V_272 ) ;
F_82 () ;
if ( ! V_52 )
return - V_72 ;
break;
}
case V_94 :
V_52 = V_2 -> V_95 ;
break;
case V_96 :
V_52 = V_50 -> V_97 . V_98 . V_99 ;
break;
case V_100 :
V_52 = V_50 -> V_97 . V_98 . V_101 ;
break;
case V_102 :
V_52 = V_50 -> V_97 . V_98 . V_103 ;
break;
case V_104 :
V_52 = V_50 -> V_97 . V_98 . V_105 ;
break;
case V_106 :
V_52 = V_50 -> V_97 . V_98 . V_107 ;
break;
case V_108 :
V_52 = V_50 -> V_97 . V_98 . V_109 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
{
struct V_18 * V_19 ;
F_21 ( V_2 ) ;
V_19 = F_38 ( V_50 -> V_19 ,
F_39 ( V_2 ) ) ;
V_257 = F_69 ( V_2 , V_19 , V_34 , V_47 , V_257 ) ;
F_61 ( V_2 ) ;
if ( V_257 < 0 )
return V_257 ;
return F_78 ( V_257 , V_48 ) ;
}
case V_110 :
V_52 = V_50 -> V_97 . V_98 . V_111 ;
break;
case V_112 :
V_52 = V_50 -> V_97 . V_98 . V_113 ;
break;
case V_114 :
V_52 = V_50 -> V_97 . V_98 . V_115 ;
break;
case V_116 :
V_52 = V_50 -> V_97 . V_98 . V_117 ;
break;
case V_118 :
V_52 = V_50 -> V_119 ;
break;
case V_120 :
V_52 = V_50 -> V_97 . V_98 . V_121 ;
break;
case V_122 :
V_52 = V_50 -> V_97 . V_98 . V_123 ;
break;
case V_124 :
V_52 = V_50 -> V_97 . V_98 . V_125 ;
break;
case V_273 :
{
struct V_271 * V_272 ;
struct V_274 V_275 ;
if ( V_257 < sizeof( V_275 ) )
return - V_139 ;
V_257 = sizeof( V_275 ) ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
F_79 () ;
V_272 = F_80 ( V_2 ) ;
if ( V_272 )
V_275 . V_276 = F_81 ( V_272 ) ;
F_82 () ;
if ( ! V_275 . V_276 )
return - V_72 ;
if ( F_78 ( V_257 , V_48 ) )
return - V_56 ;
if ( F_71 ( V_47 , & V_275 , V_257 ) )
return - V_56 ;
return 0 ;
}
case V_126 :
V_52 = F_2 ( V_2 ) -> V_131 ;
break;
case V_132 :
V_52 = V_50 -> V_97 . V_98 . V_133 ;
break;
case V_171 :
case V_173 :
{
struct V_271 * V_272 ;
if ( V_34 == V_171 )
V_52 = V_50 -> V_172 ;
else
V_52 = V_50 -> V_175 ;
if ( V_52 < 0 ) {
F_79 () ;
V_272 = F_80 ( V_2 ) ;
if ( V_272 )
V_52 = F_83 ( V_272 ) ;
F_82 () ;
}
if ( V_52 < 0 )
V_52 = F_16 ( V_2 ) -> V_277 . V_278 -> V_172 ;
break;
}
case V_177 :
V_52 = V_50 -> V_178 ;
break;
case V_185 :
V_52 = V_50 -> V_187 ;
break;
case V_179 :
V_52 = ( V_33 int ) F_84 ( ( V_279 ) V_50 -> V_184 ) ;
break;
case V_217 :
V_52 = V_50 -> V_220 ;
break;
case V_224 :
V_52 = V_50 -> V_225 ;
break;
case V_227 :
V_52 = V_50 -> V_228 ;
break;
case V_229 :
{
struct V_280 V_281 ;
int V_262 ;
if ( V_257 < sizeof( V_281 ) )
return - V_139 ;
if ( F_44 ( & V_281 , V_47 , sizeof( V_281 ) ) )
return - V_56 ;
if ( V_281 . V_282 != V_283 )
return - V_139 ;
V_257 = sizeof( V_281 ) ;
V_262 = V_281 . V_284 ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_52 = F_85 ( V_2 , & V_281 , V_262 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_78 ( V_257 , V_48 ) )
return - V_56 ;
if ( F_71 ( V_47 , & V_281 , V_257 ) )
return - V_56 ;
return 0 ;
}
case V_232 :
V_52 = 0 ;
if ( V_50 -> V_244 & V_236 )
V_52 |= V_236 ;
else if ( V_50 -> V_244 & V_235 )
V_52 |= V_235 ;
else {
V_52 |= V_237 ;
}
if ( V_50 -> V_244 & V_240 )
V_52 |= V_240 ;
else
V_52 |= V_239 ;
break;
case V_245 :
V_52 = V_50 -> V_246 ;
break;
case V_247 :
V_52 = V_50 -> V_248 ;
break;
case V_249 :
V_52 = V_50 -> V_250 ;
break;
default:
return - V_12 ;
}
V_257 = F_70 (unsigned int, sizeof(int), len) ;
if ( F_78 ( V_257 , V_48 ) )
return - V_56 ;
if ( F_71 ( V_47 , & V_52 , V_257 ) )
return - V_56 ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , int T_1 * V_48 )
{
int V_251 ;
if ( V_46 == V_252 && V_2 -> V_8 != V_9 )
return V_85 . V_285 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
if ( V_46 != V_254 )
return - V_12 ;
V_251 = F_72 ( V_2 , V_46 , V_34 , V_47 , V_48 , 0 ) ;
#ifdef F_64
if ( V_251 == - V_12 && V_34 != V_154 ) {
int V_257 ;
if ( F_17 ( V_257 , V_48 ) )
return - V_56 ;
F_21 ( V_2 ) ;
V_251 = F_87 ( V_2 , V_255 , V_34 , V_47 ,
& V_257 ) ;
F_61 ( V_2 ) ;
if ( V_251 >= 0 )
V_251 = F_78 ( V_257 , V_48 ) ;
}
#endif
return V_251 ;
}
int F_88 ( struct V_1 * V_2 , int V_46 , int V_34 ,
char T_1 * V_47 , int T_1 * V_48 )
{
int V_251 ;
if ( V_46 == V_252 && V_2 -> V_8 != V_9 ) {
if ( V_85 . V_286 != NULL )
return V_85 . V_286 ( V_2 , V_46 , V_34 ,
V_47 , V_48 ) ;
return V_85 . V_285 ( V_2 , V_46 , V_34 , V_47 , V_48 ) ;
}
if ( V_46 != V_254 )
return - V_12 ;
if ( V_34 == V_45 )
return F_89 ( V_2 , V_46 , V_34 , V_47 , V_48 ,
F_86 ) ;
V_251 = F_72 ( V_2 , V_46 , V_34 , V_47 , V_48 ,
V_287 ) ;
#ifdef F_64
if ( V_251 == - V_12 && V_34 != V_154 ) {
int V_257 ;
if ( F_17 ( V_257 , V_48 ) )
return - V_56 ;
F_21 ( V_2 ) ;
V_251 = F_90 ( V_2 , V_255 ,
V_34 , V_47 , & V_257 ) ;
F_61 ( V_2 ) ;
if ( V_251 >= 0 )
V_251 = F_78 ( V_257 , V_48 ) ;
}
#endif
return V_251 ;
}
