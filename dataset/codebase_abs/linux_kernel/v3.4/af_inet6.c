static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned char V_15 ;
char V_16 ;
int V_17 = 0 ;
int V_18 ;
if ( V_3 -> type != V_19 &&
V_3 -> type != V_20 &&
! V_21 )
F_2 () ;
V_22:
V_18 = - V_23 ;
F_3 () ;
F_4 (answer, &inetsw6[sock->type], list) {
V_18 = 0 ;
if ( V_4 == V_12 -> V_4 ) {
if ( V_4 != V_24 )
break;
} else {
if ( V_24 == V_4 ) {
V_4 = V_12 -> V_4 ;
break;
}
if ( V_24 == V_12 -> V_4 )
break;
}
V_18 = - V_25 ;
}
if ( V_18 ) {
if ( V_17 < 2 ) {
F_5 () ;
if ( ++ V_17 == 1 )
F_6 ( L_1 ,
V_26 , V_4 , V_3 -> type ) ;
else
F_6 ( L_2 ,
V_26 , V_4 ) ;
goto V_22;
} else
goto V_27;
}
V_18 = - V_28 ;
if ( V_3 -> type == V_19 && ! V_5 && ! F_7 ( V_29 ) )
goto V_27;
V_3 -> V_30 = V_12 -> V_30 ;
V_14 = V_12 -> V_31 ;
V_16 = V_12 -> V_32 ;
V_15 = V_12 -> V_33 ;
F_5 () ;
F_8 ( V_14 -> V_34 == NULL ) ;
V_18 = - V_35 ;
V_10 = F_9 ( V_1 , V_26 , V_36 , V_14 ) ;
if ( V_10 == NULL )
goto V_37;
F_10 ( V_3 , V_10 ) ;
V_18 = 0 ;
V_10 -> V_38 = V_16 ;
if ( V_39 & V_15 )
V_10 -> V_40 = 1 ;
V_7 = F_11 ( V_10 ) ;
V_7 -> V_41 = ( V_42 & V_15 ) != 0 ;
if ( V_19 == V_3 -> type ) {
V_7 -> V_43 = V_4 ;
if ( V_44 == V_4 )
V_7 -> V_45 = 1 ;
}
V_10 -> V_46 = V_47 ;
V_10 -> V_48 = V_26 ;
V_10 -> V_49 = V_4 ;
V_10 -> V_50 = V_12 -> V_31 -> V_51 ;
F_11 ( V_10 ) -> V_52 = V_9 = F_12 ( V_10 ) ;
V_9 -> V_53 = - 1 ;
V_9 -> V_54 = V_55 ;
V_9 -> V_56 = 1 ;
V_9 -> V_57 = V_58 ;
V_9 -> V_59 = V_1 -> V_60 . V_61 . V_62 ;
V_7 -> V_63 = - 1 ;
V_7 -> V_56 = 1 ;
V_7 -> V_64 = 1 ;
V_7 -> V_65 = 0 ;
V_7 -> V_66 = NULL ;
V_7 -> V_67 = 0 ;
if ( V_68 . V_69 )
V_7 -> V_57 = V_70 ;
else
V_7 -> V_57 = V_71 ;
F_13 ( V_10 ) ;
if ( V_7 -> V_43 ) {
V_7 -> V_72 = F_14 ( V_7 -> V_43 ) ;
V_10 -> V_73 -> V_74 ( V_10 ) ;
}
if ( V_10 -> V_73 -> V_75 ) {
V_18 = V_10 -> V_73 -> V_75 ( V_10 ) ;
if ( V_18 ) {
F_15 ( V_10 ) ;
goto V_37;
}
}
V_37:
return V_18 ;
V_27:
F_5 () ;
goto V_37;
}
int F_16 ( struct V_2 * V_3 , struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
T_1 V_81 = 0 ;
unsigned short V_82 ;
int V_83 = 0 ;
int V_18 = 0 ;
if ( V_10 -> V_73 -> V_84 )
return V_10 -> V_73 -> V_84 ( V_10 , V_77 , V_78 ) ;
if ( V_78 < V_85 )
return - V_86 ;
if ( V_80 -> V_87 != V_88 )
return - V_89 ;
V_83 = F_19 ( & V_80 -> V_90 ) ;
if ( ( V_83 & V_91 ) && V_3 -> type == V_92 )
return - V_86 ;
V_82 = F_20 ( V_80 -> V_93 ) ;
if ( V_82 && V_82 < V_94 && ! F_7 ( V_95 ) )
return - V_96 ;
F_21 ( V_10 ) ;
if ( V_10 -> V_97 != V_98 || V_7 -> V_43 ) {
V_18 = - V_86 ;
goto V_37;
}
if ( V_83 == V_99 ) {
int V_100 ;
if ( V_9 -> V_59 ) {
V_18 = - V_86 ;
goto V_37;
}
V_81 = V_80 -> V_90 . V_101 [ 3 ] ;
V_100 = F_22 ( V_1 , V_81 ) ;
if ( ! V_102 &&
! ( V_7 -> V_103 || V_7 -> V_104 ) &&
V_81 != F_23 ( V_105 ) &&
V_100 != V_106 &&
V_100 != V_107 &&
V_100 != V_108 ) {
V_18 = - V_109 ;
goto V_37;
}
} else {
if ( V_83 != V_110 ) {
struct V_111 * V_112 = NULL ;
F_3 () ;
if ( V_83 & V_113 ) {
if ( V_78 >= sizeof( struct V_79 ) &&
V_80 -> V_114 ) {
V_10 -> V_115 = V_80 -> V_114 ;
}
if ( ! V_10 -> V_115 ) {
V_18 = - V_86 ;
goto V_116;
}
V_112 = F_24 ( V_1 , V_10 -> V_115 ) ;
if ( ! V_112 ) {
V_18 = - V_117 ;
goto V_116;
}
}
V_81 = V_118 ;
if ( ! ( V_83 & V_91 ) ) {
if ( ! ( V_7 -> V_103 || V_7 -> V_104 ) &&
! F_25 ( V_1 , & V_80 -> V_90 ,
V_112 , 0 ) ) {
V_18 = - V_109 ;
goto V_116;
}
}
F_5 () ;
}
}
V_7 -> V_119 = V_81 ;
V_7 -> V_120 = V_81 ;
V_9 -> V_121 = V_80 -> V_90 ;
if ( ! ( V_83 & V_91 ) )
V_9 -> V_122 = V_80 -> V_90 ;
if ( V_10 -> V_73 -> V_123 ( V_10 , V_82 ) ) {
F_26 ( V_10 ) ;
V_18 = - V_124 ;
goto V_37;
}
if ( V_83 != V_110 ) {
V_10 -> V_125 |= V_126 ;
if ( V_83 != V_99 )
V_9 -> V_59 = 1 ;
}
if ( V_82 )
V_10 -> V_125 |= V_127 ;
V_7 -> V_72 = F_14 ( V_7 -> V_43 ) ;
V_7 -> V_128 = 0 ;
V_7 -> V_129 = 0 ;
V_37:
F_27 ( V_10 ) ;
return V_18 ;
V_116:
F_5 () ;
goto V_37;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( V_10 == NULL )
return - V_86 ;
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
return F_31 ( V_3 ) ;
}
void F_32 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
if ( ( V_131 = F_33 ( & V_9 -> V_134 , NULL ) ) != NULL )
F_34 ( V_131 ) ;
if ( ( V_131 = F_33 ( & V_9 -> V_135 , NULL ) ) != NULL )
F_34 ( V_131 ) ;
F_35 ( V_10 ) ;
if ( ( V_133 = F_33 ( & V_9 -> V_133 , NULL ) ) != NULL )
F_36 ( V_10 , V_133 , V_133 -> V_136 ) ;
}
int F_37 ( struct V_2 * V_3 , struct V_76 * V_77 ,
int * V_137 , int V_138 )
{
struct V_79 * sin = (struct V_79 * ) V_77 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
sin -> V_87 = V_88 ;
sin -> V_139 = 0 ;
sin -> V_114 = 0 ;
if ( V_138 ) {
if ( ! V_7 -> V_128 )
return - V_140 ;
if ( ( ( 1 << V_10 -> V_97 ) & ( V_141 | V_142 ) ) &&
V_138 == 1 )
return - V_140 ;
sin -> V_93 = V_7 -> V_128 ;
sin -> V_90 = V_9 -> V_143 ;
if ( V_9 -> V_144 )
sin -> V_139 = V_9 -> V_145 ;
} else {
if ( F_38 ( & V_9 -> V_121 ) )
sin -> V_90 = V_9 -> V_122 ;
else
sin -> V_90 = V_9 -> V_121 ;
sin -> V_93 = V_7 -> V_72 ;
}
if ( F_19 ( & sin -> V_90 ) & V_113 )
sin -> V_114 = V_10 -> V_115 ;
* V_137 = sizeof( * sin ) ;
return 0 ;
}
int F_39 ( struct V_2 * V_3 , unsigned int V_146 , unsigned long V_147 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
switch( V_146 )
{
case V_148 :
return F_40 ( V_10 , (struct V_149 V_150 * ) V_147 ) ;
case V_151 :
return F_41 ( V_10 , (struct V_152 V_150 * ) V_147 ) ;
case V_153 :
case V_154 :
return F_42 ( V_1 , V_146 , ( void V_150 * ) V_147 ) ;
case V_155 :
return F_43 ( V_1 , ( void V_150 * ) V_147 ) ;
case V_156 :
return F_44 ( V_1 , ( void V_150 * ) V_147 ) ;
case V_157 :
return F_45 ( V_1 , ( void V_150 * ) V_147 ) ;
default:
if ( ! V_10 -> V_73 -> V_158 )
return - V_159 ;
return V_10 -> V_73 -> V_158 ( V_10 , V_146 , V_147 ) ;
}
return 0 ;
}
int F_46 ( struct V_11 * V_160 )
{
struct V_161 * V_162 ;
struct V_11 * V_12 ;
struct V_161 * V_163 ;
int V_4 = V_160 -> V_4 ;
int V_164 ;
F_47 ( & V_165 ) ;
V_164 = - V_86 ;
if ( V_160 -> type >= V_166 )
goto V_167;
V_12 = NULL ;
V_164 = - V_28 ;
V_163 = & V_168 [ V_160 -> type ] ;
F_48 (lh, &inetsw6[p->type]) {
V_12 = F_49 ( V_162 , struct V_11 , V_169 ) ;
if ( V_170 & V_12 -> V_33 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_163 = V_162 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_171;
F_50 ( & V_160 -> V_169 , V_163 ) ;
V_164 = 0 ;
V_37:
F_51 ( & V_165 ) ;
return V_164 ;
V_171:
F_52 ( V_172 L_3 ,
V_4 ) ;
goto V_37;
V_167:
F_52 ( V_172
L_4 ,
V_160 -> type ) ;
goto V_37;
}
void
F_53 ( struct V_11 * V_160 )
{
if ( V_170 & V_160 -> V_33 ) {
F_52 ( V_172
L_5 ,
V_160 -> V_4 ) ;
} else {
F_47 ( & V_165 ) ;
F_54 ( & V_160 -> V_169 ) ;
F_51 ( & V_165 ) ;
F_55 () ;
}
}
int F_56 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_173 * V_174 ;
V_174 = F_57 ( V_10 , V_9 -> V_175 ) ;
if ( V_174 == NULL ) {
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_176 * V_177 , V_178 ;
struct V_179 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_181 = V_10 -> V_49 ;
V_180 . V_143 = V_9 -> V_143 ;
V_180 . V_122 = V_9 -> V_122 ;
V_180 . V_182 = V_9 -> V_145 ;
V_180 . V_183 = V_10 -> V_115 ;
V_180 . V_184 = V_10 -> V_185 ;
V_180 . V_186 = V_7 -> V_128 ;
V_180 . V_187 = V_7 -> V_72 ;
F_58 ( V_10 , F_59 ( & V_180 ) ) ;
V_177 = F_60 ( & V_180 , V_9 -> V_133 , & V_178 ) ;
V_174 = F_61 ( V_10 , & V_180 , V_177 , false ) ;
if ( F_62 ( V_174 ) ) {
V_10 -> V_188 = 0 ;
V_10 -> V_189 = - F_63 ( V_174 ) ;
return F_63 ( V_174 ) ;
}
F_64 ( V_10 , V_174 , NULL , NULL ) ;
}
return 0 ;
}
int F_65 ( struct V_3 * V_10 , struct V_130 * V_131 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_190 * V_133 = F_66 ( V_131 ) ;
if ( V_9 -> V_191 . V_192 ) {
if ( ( V_133 -> V_193 && ( V_9 -> V_191 . V_194 . V_195 ||
V_9 -> V_191 . V_194 . V_196 ) ) ||
( ( V_197 &
* ( T_1 * ) F_67 ( V_131 ) ) &&
V_9 -> V_191 . V_194 . V_198 ) ||
( V_133 -> V_199 && ( V_9 -> V_191 . V_194 . V_199 ||
V_9 -> V_191 . V_194 . V_200 ) ) ||
( ( V_133 -> V_201 || V_133 -> V_202 ) &&
( V_9 -> V_191 . V_194 . V_203 || V_9 -> V_191 . V_194 . V_204 ) ) )
return 1 ;
}
return 0 ;
}
static int F_68 ( struct V_130 * V_131 , int V_13 )
{
const struct V_205 * V_30 = NULL ;
for (; ; ) {
struct V_206 * V_207 ;
int V_208 ;
if ( V_13 != V_209 ) {
V_30 = F_69 ( V_210 [ V_13 ] ) ;
if ( F_70 ( ! V_30 ) )
break;
if ( ! ( V_30 -> V_33 & V_211 ) )
break;
}
if ( F_70 ( ! F_71 ( V_131 , 8 ) ) )
break;
V_207 = ( void * ) V_131 -> V_212 ;
V_208 = F_72 ( V_207 ) ;
if ( F_70 ( ! F_71 ( V_131 , V_208 ) ) )
break;
V_13 = V_207 -> V_213 ;
F_73 ( V_131 , V_208 ) ;
}
return V_13 ;
}
static int F_74 ( struct V_130 * V_131 )
{
const struct V_214 * V_215 ;
const struct V_205 * V_30 ;
int V_18 = - V_86 ;
if ( F_70 ( ! F_71 ( V_131 , sizeof( * V_215 ) ) ) )
goto V_37;
V_215 = F_75 ( V_131 ) ;
F_73 ( V_131 , sizeof( * V_215 ) ) ;
V_18 = - V_25 ;
F_3 () ;
V_30 = F_69 ( V_210 [
F_68 ( V_131 , V_215 -> V_213 ) ] ) ;
if ( F_76 ( V_30 && V_30 -> V_216 ) ) {
F_77 ( V_131 ) ;
V_18 = V_30 -> V_216 ( V_131 ) ;
}
F_5 () ;
V_37:
return V_18 ;
}
static struct V_130 * F_78 ( struct V_130 * V_131 ,
T_2 V_217 )
{
struct V_130 * V_218 = F_79 ( - V_86 ) ;
struct V_214 * V_215 ;
const struct V_205 * V_30 ;
int V_13 ;
struct V_219 * V_220 ;
unsigned int V_221 ;
T_3 * V_222 ;
int V_223 = 0 ;
if ( ! ( V_217 & V_224 ) )
V_217 &= ~ V_225 ;
if ( F_70 ( F_80 ( V_131 ) -> V_226 &
~ ( V_227 |
V_228 |
V_229 |
V_230 |
0 ) ) )
goto V_37;
if ( F_70 ( ! F_71 ( V_131 , sizeof( * V_215 ) ) ) )
goto V_37;
V_215 = F_75 ( V_131 ) ;
F_73 ( V_131 , sizeof( * V_215 ) ) ;
V_218 = F_79 ( - V_25 ) ;
V_13 = F_68 ( V_131 , V_215 -> V_213 ) ;
F_3 () ;
V_30 = F_69 ( V_210 [ V_13 ] ) ;
if ( F_76 ( V_30 && V_30 -> V_231 ) ) {
F_77 ( V_131 ) ;
V_218 = V_30 -> V_231 ( V_131 , V_217 ) ;
}
F_5 () ;
if ( F_62 ( V_218 ) )
goto V_37;
for ( V_131 = V_218 ; V_131 ; V_131 = V_131 -> V_232 ) {
V_215 = F_75 ( V_131 ) ;
V_215 -> V_233 = F_14 ( V_131 -> V_208 - V_131 -> V_234 -
sizeof( * V_215 ) ) ;
if ( V_13 == V_235 ) {
V_221 = F_81 ( V_131 , & V_222 ) ;
V_220 = (struct V_219 * ) ( F_67 ( V_131 ) +
V_221 ) ;
V_220 -> V_236 = F_14 ( V_223 ) ;
if ( V_131 -> V_232 != NULL )
V_220 -> V_236 |= F_14 ( V_237 ) ;
V_223 += ( F_20 ( V_215 -> V_233 ) -
sizeof( struct V_219 ) ) ;
}
}
V_37:
return V_218 ;
}
static struct V_130 * * F_82 ( struct V_130 * * V_238 ,
struct V_130 * V_131 )
{
const struct V_205 * V_30 ;
struct V_130 * * V_239 = NULL ;
struct V_130 * V_160 ;
struct V_214 * V_240 ;
unsigned int V_241 ;
unsigned int V_242 ;
unsigned int V_243 ;
int V_244 = 1 ;
int V_13 ;
T_4 V_245 ;
V_243 = F_83 ( V_131 ) ;
V_242 = V_243 + sizeof( * V_240 ) ;
V_240 = F_84 ( V_131 , V_243 ) ;
if ( F_85 ( V_131 , V_242 ) ) {
V_240 = F_86 ( V_131 , V_242 , V_243 ) ;
if ( F_70 ( ! V_240 ) )
goto V_37;
}
F_87 ( V_131 , sizeof( * V_240 ) ) ;
F_88 ( V_131 , F_83 ( V_131 ) ) ;
V_244 += F_20 ( V_240 -> V_233 ) != F_89 ( V_131 ) ;
F_3 () ;
V_13 = V_240 -> V_213 ;
V_30 = F_69 ( V_210 [ V_13 ] ) ;
if ( ! V_30 || ! V_30 -> V_246 ) {
F_90 ( V_131 , F_83 ( V_131 ) ) ;
V_13 = F_68 ( V_131 , V_13 ) ;
F_87 ( V_131 , - F_91 ( V_131 ) ) ;
F_77 ( V_131 ) ;
F_92 ( V_131 , F_83 ( V_131 ) ) ;
V_30 = F_69 ( V_210 [ V_13 ] ) ;
if ( ! V_30 || ! V_30 -> V_246 )
goto V_116;
V_240 = F_75 ( V_131 ) ;
}
F_93 ( V_131 ) -> V_13 = V_13 ;
V_244 -- ;
V_241 = F_94 ( V_131 ) ;
for ( V_160 = * V_238 ; V_160 ; V_160 = V_160 -> V_232 ) {
struct V_214 * V_247 ;
if ( ! F_95 ( V_160 ) -> V_248 )
continue;
V_247 = F_75 ( V_160 ) ;
if ( V_241 != F_94 ( V_160 ) ||
memcmp ( V_240 , V_247 , F_96 ( struct V_214 , V_233 ) ) ||
memcmp ( & V_240 -> V_213 , & V_247 -> V_213 ,
V_241 - F_96 ( struct V_214 , V_213 ) ) ) {
F_95 ( V_160 ) -> V_248 = 0 ;
continue;
}
F_95 ( V_160 ) -> V_244 |= V_244 ;
}
F_95 ( V_131 ) -> V_244 |= V_244 ;
V_245 = V_131 -> V_245 ;
F_97 ( V_131 , V_240 , F_94 ( V_131 ) ) ;
V_239 = V_30 -> V_246 ( V_238 , V_131 ) ;
V_131 -> V_245 = V_245 ;
V_116:
F_5 () ;
V_37:
F_95 ( V_131 ) -> V_244 |= V_244 ;
return V_239 ;
}
static int F_98 ( struct V_130 * V_131 )
{
const struct V_205 * V_30 ;
struct V_214 * V_240 = F_75 ( V_131 ) ;
int V_18 = - V_249 ;
V_240 -> V_233 = F_14 ( V_131 -> V_208 - F_99 ( V_131 ) -
sizeof( * V_240 ) ) ;
F_3 () ;
V_30 = F_69 ( V_210 [ F_93 ( V_131 ) -> V_13 ] ) ;
if ( F_8 ( ! V_30 || ! V_30 -> V_250 ) )
goto V_116;
V_18 = V_30 -> V_250 ( V_131 ) ;
V_116:
F_5 () ;
return V_18 ;
}
static int T_5 F_100 ( void )
{
F_101 ( & V_251 ) ;
return 0 ;
}
static void F_102 ( void )
{
F_103 ( & V_251 ) ;
}
static int T_6 F_104 ( struct V_1 * V_1 )
{
if ( F_105 ( ( void V_252 * * ) V_1 -> V_253 . V_254 ,
sizeof( struct V_255 ) ,
F_106 ( struct V_255 ) ) < 0 )
return - V_256 ;
if ( F_105 ( ( void V_252 * * ) V_1 -> V_253 . V_257 ,
sizeof( struct V_255 ) ,
F_106 ( struct V_255 ) ) < 0 )
goto V_258;
if ( F_105 ( ( void V_252 * * ) V_1 -> V_253 . V_259 ,
sizeof( struct V_260 ) ,
F_106 ( struct V_260 ) ) < 0 )
goto V_261;
if ( F_105 ( ( void V_252 * * ) V_1 -> V_253 . V_262 ,
sizeof( struct V_263 ) ,
F_106 ( struct V_263 ) ) < 0 )
goto V_264;
V_1 -> V_253 . V_265 = F_107 ( sizeof( struct V_266 ) ,
V_36 ) ;
if ( ! V_1 -> V_253 . V_265 )
goto V_267;
return 0 ;
V_267:
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_262 ) ;
V_264:
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_259 ) ;
V_261:
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_257 ) ;
V_258:
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_254 ) ;
return - V_256 ;
}
static void F_109 ( struct V_1 * V_1 )
{
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_254 ) ;
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_257 ) ;
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_259 ) ;
F_108 ( ( void V_252 * * ) V_1 -> V_253 . V_262 ) ;
F_110 ( V_1 -> V_253 . V_265 ) ;
}
static int T_6 F_111 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
V_1 -> V_60 . V_61 . V_62 = 0 ;
V_1 -> V_60 . V_61 . V_268 = 1 * V_269 ;
V_18 = F_104 ( V_1 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_112
V_18 = F_113 ( V_1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_114 ( V_1 ) ;
if ( V_18 )
goto V_270;
V_18 = F_115 ( V_1 ) ;
if ( V_18 )
goto V_271;
#endif
return V_18 ;
#ifdef F_112
V_271:
F_116 ( V_1 ) ;
V_270:
F_117 ( V_1 ) ;
V_37:
F_109 ( V_1 ) ;
return V_18 ;
#endif
}
static void T_7 F_118 ( struct V_1 * V_1 )
{
#ifdef F_112
F_117 ( V_1 ) ;
F_116 ( V_1 ) ;
F_119 ( V_1 ) ;
#endif
F_109 ( V_1 ) ;
}
static int T_5 F_120 ( void )
{
struct V_130 * V_272 ;
struct V_161 * V_273 ;
int V_18 = 0 ;
F_121 ( sizeof( struct V_190 ) > sizeof( V_272 -> V_274 ) ) ;
for( V_273 = & V_168 [ 0 ] ; V_273 < & V_168 [ V_166 ] ; ++ V_273 )
F_122 ( V_273 ) ;
if ( V_275 ) {
F_52 ( V_276
L_6
L_7 ) ;
goto V_37;
}
V_18 = F_123 ( & V_277 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_123 ( & V_278 , 1 ) ;
if ( V_18 )
goto V_279;
V_18 = F_123 ( & V_280 , 1 ) ;
if ( V_18 )
goto V_281;
V_18 = F_123 ( & V_282 , 1 ) ;
if ( V_18 )
goto V_283;
V_18 = F_124 () ;
if ( V_18 )
goto V_284;
V_18 = F_125 ( & V_285 ) ;
if ( V_18 )
goto V_286;
#ifdef F_126
V_18 = F_127 () ;
if ( V_18 )
goto V_287;
#endif
V_277 . V_288 = V_289 . V_290 . V_291 ;
V_18 = F_128 ( & V_292 ) ;
if ( V_18 )
goto V_293;
V_18 = F_129 () ;
if ( V_18 )
goto V_294;
V_18 = F_130 () ;
if ( V_18 )
goto V_295;
V_18 = F_131 () ;
if ( V_18 )
goto V_296;
V_18 = F_132 () ;
if ( V_18 )
goto V_297;
V_18 = F_133 () ;
if ( V_18 )
goto V_298;
#ifdef F_112
V_18 = - V_256 ;
if ( F_134 () )
goto V_299;
if ( F_135 () )
goto V_300;
if ( F_136 () )
goto V_301;
if ( F_137 () )
goto V_302;
#endif
V_18 = F_138 () ;
if ( V_18 )
goto V_303;
V_18 = F_139 () ;
if ( V_18 )
goto V_304;
V_18 = F_140 () ;
if ( V_18 )
goto V_305;
V_18 = F_141 () ;
if ( V_18 )
goto V_306;
V_18 = F_142 () ;
if ( V_18 )
goto V_307;
V_18 = F_143 () ;
if ( V_18 )
goto V_308;
V_18 = F_144 () ;
if ( V_18 )
goto V_309;
V_18 = F_145 () ;
if ( V_18 )
goto V_310;
V_18 = F_100 () ;
if ( V_18 )
goto V_311;
#ifdef F_126
V_18 = F_146 () ;
if ( V_18 )
goto V_312;
#endif
V_37:
return V_18 ;
#ifdef F_126
V_312:
F_102 () ;
#endif
V_311:
F_147 () ;
V_310:
F_148 () ;
V_309:
F_149 () ;
V_308:
F_150 () ;
V_307:
F_151 () ;
V_306:
F_152 () ;
V_305:
F_153 () ;
V_304:
F_154 () ;
V_303:
#ifdef F_112
F_155 () ;
V_302:
F_156 () ;
V_301:
F_157 () ;
V_300:
F_158 () ;
V_299:
#endif
F_159 () ;
V_298:
F_160 () ;
V_297:
F_161 () ;
V_296:
F_162 () ;
V_295:
F_163 () ;
V_294:
F_164 ( & V_292 ) ;
V_293:
#ifdef F_126
F_165 () ;
V_287:
#endif
F_166 ( V_26 ) ;
F_167 ( V_26 ) ;
V_286:
F_168 () ;
V_284:
F_169 ( & V_282 ) ;
V_283:
F_169 ( & V_280 ) ;
V_281:
F_169 ( & V_278 ) ;
V_279:
F_169 ( & V_277 ) ;
goto V_37;
}
static void T_8 F_170 ( void )
{
if ( V_275 )
return;
F_166 ( V_26 ) ;
F_167 ( V_26 ) ;
#ifdef F_126
F_171 () ;
#endif
F_149 () ;
F_148 () ;
F_147 () ;
F_102 () ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
#ifdef F_112
F_155 () ;
F_156 () ;
F_157 () ;
F_158 () ;
#endif
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
F_163 () ;
F_168 () ;
F_164 ( & V_292 ) ;
#ifdef F_126
F_165 () ;
#endif
F_169 ( & V_282 ) ;
F_169 ( & V_280 ) ;
F_169 ( & V_278 ) ;
F_169 ( & V_277 ) ;
F_172 () ;
}
