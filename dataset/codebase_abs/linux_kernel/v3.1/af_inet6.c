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
if ( V_67 . V_68 )
V_7 -> V_57 = V_69 ;
else
V_7 -> V_57 = V_70 ;
F_13 ( V_10 ) ;
if ( V_7 -> V_43 ) {
V_7 -> V_71 = F_14 ( V_7 -> V_43 ) ;
V_10 -> V_72 -> V_73 ( V_10 ) ;
}
if ( V_10 -> V_72 -> V_74 ) {
V_18 = V_10 -> V_72 -> V_74 ( V_10 ) ;
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
int F_16 ( struct V_2 * V_3 , struct V_75 * V_76 , int V_77 )
{
struct V_78 * V_79 = (struct V_78 * ) V_76 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
T_1 V_80 = 0 ;
unsigned short V_81 ;
int V_82 = 0 ;
int V_18 = 0 ;
if ( V_10 -> V_72 -> V_83 )
return V_10 -> V_72 -> V_83 ( V_10 , V_76 , V_77 ) ;
if ( V_77 < V_84 )
return - V_85 ;
if ( V_79 -> V_86 != V_87 )
return - V_88 ;
V_82 = F_19 ( & V_79 -> V_89 ) ;
if ( ( V_82 & V_90 ) && V_3 -> type == V_91 )
return - V_85 ;
V_81 = F_20 ( V_79 -> V_92 ) ;
if ( V_81 && V_81 < V_93 && ! F_7 ( V_94 ) )
return - V_95 ;
F_21 ( V_10 ) ;
if ( V_10 -> V_96 != V_97 || V_7 -> V_43 ) {
V_18 = - V_85 ;
goto V_37;
}
if ( V_82 == V_98 ) {
int V_99 ;
if ( V_9 -> V_59 ) {
V_18 = - V_85 ;
goto V_37;
}
V_80 = V_79 -> V_89 . V_100 [ 3 ] ;
V_99 = F_22 ( V_1 , V_80 ) ;
if ( ! V_101 &&
! ( V_7 -> V_102 || V_7 -> V_103 ) &&
V_80 != F_23 ( V_104 ) &&
V_99 != V_105 &&
V_99 != V_106 &&
V_99 != V_107 ) {
V_18 = - V_108 ;
goto V_37;
}
} else {
if ( V_82 != V_109 ) {
struct V_110 * V_111 = NULL ;
F_3 () ;
if ( V_82 & V_112 ) {
if ( V_77 >= sizeof( struct V_78 ) &&
V_79 -> V_113 ) {
V_10 -> V_114 = V_79 -> V_113 ;
}
if ( ! V_10 -> V_114 ) {
V_18 = - V_85 ;
goto V_115;
}
V_111 = F_24 ( V_1 , V_10 -> V_114 ) ;
if ( ! V_111 ) {
V_18 = - V_116 ;
goto V_115;
}
}
V_80 = V_117 ;
if ( ! ( V_82 & V_90 ) ) {
if ( ! V_7 -> V_103 &&
! F_25 ( V_1 , & V_79 -> V_89 ,
V_111 , 0 ) ) {
V_18 = - V_108 ;
goto V_115;
}
}
F_5 () ;
}
}
V_7 -> V_118 = V_80 ;
V_7 -> V_119 = V_80 ;
F_26 ( & V_9 -> V_120 , & V_79 -> V_89 ) ;
if ( ! ( V_82 & V_90 ) )
F_26 ( & V_9 -> V_121 , & V_79 -> V_89 ) ;
if ( V_10 -> V_72 -> V_122 ( V_10 , V_81 ) ) {
F_27 ( V_10 ) ;
V_18 = - V_123 ;
goto V_37;
}
if ( V_82 != V_109 ) {
V_10 -> V_124 |= V_125 ;
if ( V_82 != V_98 )
V_9 -> V_59 = 1 ;
}
if ( V_81 )
V_10 -> V_124 |= V_126 ;
V_7 -> V_71 = F_14 ( V_7 -> V_43 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_128 = 0 ;
V_37:
F_28 ( V_10 ) ;
return V_18 ;
V_115:
F_5 () ;
goto V_37;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
if ( V_10 == NULL )
return - V_85 ;
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
return F_32 ( V_3 ) ;
}
void F_33 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
if ( ( V_130 = F_34 ( & V_9 -> V_133 , NULL ) ) != NULL )
F_35 ( V_130 ) ;
if ( ( V_130 = F_34 ( & V_9 -> V_134 , NULL ) ) != NULL )
F_35 ( V_130 ) ;
F_36 ( V_10 ) ;
if ( ( V_132 = F_34 ( & V_9 -> V_132 , NULL ) ) != NULL )
F_37 ( V_10 , V_132 , V_132 -> V_135 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_75 * V_76 ,
int * V_136 , int V_137 )
{
struct V_78 * sin = (struct V_78 * ) V_76 ;
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_8 * V_9 = F_17 ( V_10 ) ;
sin -> V_86 = V_87 ;
sin -> V_138 = 0 ;
sin -> V_113 = 0 ;
if ( V_137 ) {
if ( ! V_7 -> V_127 )
return - V_139 ;
if ( ( ( 1 << V_10 -> V_96 ) & ( V_140 | V_141 ) ) &&
V_137 == 1 )
return - V_139 ;
sin -> V_92 = V_7 -> V_127 ;
F_26 ( & sin -> V_89 , & V_9 -> V_142 ) ;
if ( V_9 -> V_143 )
sin -> V_138 = V_9 -> V_144 ;
} else {
if ( F_39 ( & V_9 -> V_120 ) )
F_26 ( & sin -> V_89 , & V_9 -> V_121 ) ;
else
F_26 ( & sin -> V_89 , & V_9 -> V_120 ) ;
sin -> V_92 = V_7 -> V_71 ;
}
if ( F_19 ( & sin -> V_89 ) & V_112 )
sin -> V_113 = V_10 -> V_114 ;
* V_136 = sizeof( * sin ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 , unsigned int V_145 , unsigned long V_146 )
{
struct V_3 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 = F_18 ( V_10 ) ;
switch( V_145 )
{
case V_147 :
return F_41 ( V_10 , (struct V_148 V_149 * ) V_146 ) ;
case V_150 :
return F_42 ( V_10 , (struct V_151 V_149 * ) V_146 ) ;
case V_152 :
case V_153 :
return F_43 ( V_1 , V_145 , ( void V_149 * ) V_146 ) ;
case V_154 :
return F_44 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_155 :
return F_45 ( V_1 , ( void V_149 * ) V_146 ) ;
case V_156 :
return F_46 ( V_1 , ( void V_149 * ) V_146 ) ;
default:
if ( ! V_10 -> V_72 -> V_157 )
return - V_158 ;
return V_10 -> V_72 -> V_157 ( V_10 , V_145 , V_146 ) ;
}
return 0 ;
}
int F_47 ( struct V_11 * V_159 )
{
struct V_160 * V_161 ;
struct V_11 * V_12 ;
struct V_160 * V_162 ;
int V_4 = V_159 -> V_4 ;
int V_163 ;
F_48 ( & V_164 ) ;
V_163 = - V_85 ;
if ( V_159 -> type >= V_165 )
goto V_166;
V_12 = NULL ;
V_163 = - V_28 ;
V_162 = & V_167 [ V_159 -> type ] ;
F_49 (lh, &inetsw6[p->type]) {
V_12 = F_50 ( V_161 , struct V_11 , V_168 ) ;
if ( V_169 & V_12 -> V_33 ) {
if ( V_4 == V_12 -> V_4 )
break;
V_162 = V_161 ;
}
V_12 = NULL ;
}
if ( V_12 )
goto V_170;
F_51 ( & V_159 -> V_168 , V_162 ) ;
V_163 = 0 ;
V_37:
F_52 ( & V_164 ) ;
return V_163 ;
V_170:
F_53 ( V_171 L_3 ,
V_4 ) ;
goto V_37;
V_166:
F_53 ( V_171
L_4 ,
V_159 -> type ) ;
goto V_37;
}
void
F_54 ( struct V_11 * V_159 )
{
if ( V_169 & V_159 -> V_33 ) {
F_53 ( V_171
L_5 ,
V_159 -> V_4 ) ;
} else {
F_48 ( & V_164 ) ;
F_55 ( & V_159 -> V_168 ) ;
F_52 ( & V_164 ) ;
F_56 () ;
}
}
int F_57 ( struct V_3 * V_10 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_172 * V_173 ;
V_173 = F_58 ( V_10 , V_9 -> V_174 ) ;
if ( V_173 == NULL ) {
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_175 * V_176 , V_177 ;
struct V_178 V_179 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_180 = V_10 -> V_49 ;
F_26 ( & V_179 . V_142 , & V_9 -> V_142 ) ;
F_26 ( & V_179 . V_121 , & V_9 -> V_121 ) ;
V_179 . V_181 = V_9 -> V_144 ;
V_179 . V_182 = V_10 -> V_114 ;
V_179 . V_183 = V_10 -> V_184 ;
V_179 . V_185 = V_7 -> V_127 ;
V_179 . V_186 = V_7 -> V_71 ;
F_59 ( V_10 , F_60 ( & V_179 ) ) ;
V_176 = F_61 ( & V_179 , V_9 -> V_132 , & V_177 ) ;
V_173 = F_62 ( V_10 , & V_179 , V_176 , false ) ;
if ( F_63 ( V_173 ) ) {
V_10 -> V_187 = 0 ;
V_10 -> V_188 = - F_64 ( V_173 ) ;
return F_64 ( V_173 ) ;
}
F_65 ( V_10 , V_173 , NULL , NULL ) ;
}
return 0 ;
}
int F_66 ( struct V_3 * V_10 , struct V_129 * V_130 )
{
struct V_8 * V_9 = F_17 ( V_10 ) ;
struct V_189 * V_132 = F_67 ( V_130 ) ;
if ( V_9 -> V_190 . V_191 ) {
if ( ( V_132 -> V_192 && ( V_9 -> V_190 . V_193 . V_194 ||
V_9 -> V_190 . V_193 . V_195 ) ) ||
( ( V_196 &
* ( T_1 * ) F_68 ( V_130 ) ) &&
V_9 -> V_190 . V_193 . V_197 ) ||
( V_132 -> V_198 && ( V_9 -> V_190 . V_193 . V_198 ||
V_9 -> V_190 . V_193 . V_199 ) ) ||
( ( V_132 -> V_200 || V_132 -> V_201 ) &&
( V_9 -> V_190 . V_193 . V_202 || V_9 -> V_190 . V_193 . V_203 ) ) )
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_129 * V_130 , int V_13 )
{
const struct V_204 * V_30 = NULL ;
for (; ; ) {
struct V_205 * V_206 ;
int V_207 ;
if ( V_13 != V_208 ) {
V_30 = F_70 ( V_209 [ V_13 ] ) ;
if ( F_71 ( ! V_30 ) )
break;
if ( ! ( V_30 -> V_33 & V_210 ) )
break;
}
if ( F_71 ( ! F_72 ( V_130 , 8 ) ) )
break;
V_206 = ( void * ) V_130 -> V_211 ;
V_207 = F_73 ( V_206 ) ;
if ( F_71 ( ! F_72 ( V_130 , V_207 ) ) )
break;
V_13 = V_206 -> V_212 ;
F_74 ( V_130 , V_207 ) ;
}
return V_13 ;
}
static int F_75 ( struct V_129 * V_130 )
{
const struct V_213 * V_214 ;
const struct V_204 * V_30 ;
int V_18 = - V_85 ;
if ( F_71 ( ! F_72 ( V_130 , sizeof( * V_214 ) ) ) )
goto V_37;
V_214 = F_76 ( V_130 ) ;
F_74 ( V_130 , sizeof( * V_214 ) ) ;
V_18 = - V_25 ;
F_3 () ;
V_30 = F_70 ( V_209 [
F_69 ( V_130 , V_214 -> V_212 ) ] ) ;
if ( F_77 ( V_30 && V_30 -> V_215 ) ) {
F_78 ( V_130 ) ;
V_18 = V_30 -> V_215 ( V_130 ) ;
}
F_5 () ;
V_37:
return V_18 ;
}
static struct V_129 * F_79 ( struct V_129 * V_130 , T_2 V_216 )
{
struct V_129 * V_217 = F_80 ( - V_85 ) ;
struct V_213 * V_214 ;
const struct V_204 * V_30 ;
int V_13 ;
struct V_218 * V_219 ;
unsigned int V_220 ;
T_3 * V_221 ;
int V_222 = 0 ;
if ( ! ( V_216 & V_223 ) )
V_216 &= ~ V_224 ;
if ( F_71 ( F_81 ( V_130 ) -> V_225 &
~ ( V_226 |
V_227 |
V_228 |
V_229 |
0 ) ) )
goto V_37;
if ( F_71 ( ! F_72 ( V_130 , sizeof( * V_214 ) ) ) )
goto V_37;
V_214 = F_76 ( V_130 ) ;
F_74 ( V_130 , sizeof( * V_214 ) ) ;
V_217 = F_80 ( - V_25 ) ;
V_13 = F_69 ( V_130 , V_214 -> V_212 ) ;
F_3 () ;
V_30 = F_70 ( V_209 [ V_13 ] ) ;
if ( F_77 ( V_30 && V_30 -> V_230 ) ) {
F_78 ( V_130 ) ;
V_217 = V_30 -> V_230 ( V_130 , V_216 ) ;
}
F_5 () ;
if ( F_63 ( V_217 ) )
goto V_37;
for ( V_130 = V_217 ; V_130 ; V_130 = V_130 -> V_231 ) {
V_214 = F_76 ( V_130 ) ;
V_214 -> V_232 = F_14 ( V_130 -> V_207 - V_130 -> V_233 -
sizeof( * V_214 ) ) ;
if ( V_13 == V_234 ) {
V_220 = F_82 ( V_130 , & V_221 ) ;
V_219 = (struct V_218 * ) ( F_68 ( V_130 ) +
V_220 ) ;
V_219 -> V_235 = F_14 ( V_222 ) ;
if ( V_130 -> V_231 != NULL )
V_219 -> V_235 |= F_14 ( V_236 ) ;
V_222 += ( F_20 ( V_214 -> V_232 ) -
sizeof( struct V_218 ) ) ;
}
}
V_37:
return V_217 ;
}
static struct V_129 * * F_83 ( struct V_129 * * V_237 ,
struct V_129 * V_130 )
{
const struct V_204 * V_30 ;
struct V_129 * * V_238 = NULL ;
struct V_129 * V_159 ;
struct V_213 * V_239 ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_242 ;
int V_243 = 1 ;
int V_13 ;
T_4 V_244 ;
V_242 = F_84 ( V_130 ) ;
V_241 = V_242 + sizeof( * V_239 ) ;
V_239 = F_85 ( V_130 , V_242 ) ;
if ( F_86 ( V_130 , V_241 ) ) {
V_239 = F_87 ( V_130 , V_241 , V_242 ) ;
if ( F_71 ( ! V_239 ) )
goto V_37;
}
F_88 ( V_130 , sizeof( * V_239 ) ) ;
F_89 ( V_130 , F_84 ( V_130 ) ) ;
V_243 += F_20 ( V_239 -> V_232 ) != F_90 ( V_130 ) ;
F_3 () ;
V_13 = V_239 -> V_212 ;
V_30 = F_70 ( V_209 [ V_13 ] ) ;
if ( ! V_30 || ! V_30 -> V_245 ) {
F_91 ( V_130 , F_84 ( V_130 ) ) ;
V_13 = F_69 ( V_130 , V_13 ) ;
F_88 ( V_130 , - F_92 ( V_130 ) ) ;
F_78 ( V_130 ) ;
F_93 ( V_130 , F_84 ( V_130 ) ) ;
V_30 = F_70 ( V_209 [ V_13 ] ) ;
if ( ! V_30 || ! V_30 -> V_245 )
goto V_115;
V_239 = F_76 ( V_130 ) ;
}
F_94 ( V_130 ) -> V_13 = V_13 ;
V_243 -- ;
V_240 = F_95 ( V_130 ) ;
for ( V_159 = * V_237 ; V_159 ; V_159 = V_159 -> V_231 ) {
struct V_213 * V_246 ;
if ( ! F_96 ( V_159 ) -> V_247 )
continue;
V_246 = F_76 ( V_159 ) ;
if ( V_240 != F_95 ( V_159 ) ||
memcmp ( V_239 , V_246 , F_97 ( struct V_213 , V_232 ) ) ||
memcmp ( & V_239 -> V_212 , & V_246 -> V_212 ,
V_240 - F_97 ( struct V_213 , V_212 ) ) ) {
F_96 ( V_159 ) -> V_247 = 0 ;
continue;
}
F_96 ( V_159 ) -> V_243 |= V_243 ;
}
F_96 ( V_130 ) -> V_243 |= V_243 ;
V_244 = V_130 -> V_244 ;
F_98 ( V_130 , V_239 , F_95 ( V_130 ) ) ;
V_238 = V_30 -> V_245 ( V_237 , V_130 ) ;
V_130 -> V_244 = V_244 ;
V_115:
F_5 () ;
V_37:
F_96 ( V_130 ) -> V_243 |= V_243 ;
return V_238 ;
}
static int F_99 ( struct V_129 * V_130 )
{
const struct V_204 * V_30 ;
struct V_213 * V_239 = F_76 ( V_130 ) ;
int V_18 = - V_248 ;
V_239 -> V_232 = F_14 ( V_130 -> V_207 - F_100 ( V_130 ) -
sizeof( * V_239 ) ) ;
F_3 () ;
V_30 = F_70 ( V_209 [ F_94 ( V_130 ) -> V_13 ] ) ;
if ( F_8 ( ! V_30 || ! V_30 -> V_249 ) )
goto V_115;
V_18 = V_30 -> V_249 ( V_130 ) ;
V_115:
F_5 () ;
return V_18 ;
}
static int T_5 F_101 ( void )
{
F_102 ( & V_250 ) ;
return 0 ;
}
static void F_103 ( void )
{
F_104 ( & V_250 ) ;
}
static int T_6 F_105 ( struct V_1 * V_1 )
{
if ( F_106 ( ( void V_251 * * ) V_1 -> V_252 . V_253 ,
sizeof( struct V_254 ) ,
F_107 ( struct V_254 ) ) < 0 )
return - V_255 ;
if ( F_106 ( ( void V_251 * * ) V_1 -> V_252 . V_256 ,
sizeof( struct V_254 ) ,
F_107 ( struct V_254 ) ) < 0 )
goto V_257;
if ( F_106 ( ( void V_251 * * ) V_1 -> V_252 . V_258 ,
sizeof( struct V_259 ) ,
F_107 ( struct V_259 ) ) < 0 )
goto V_260;
if ( F_106 ( ( void V_251 * * ) V_1 -> V_252 . V_261 ,
sizeof( struct V_262 ) ,
F_107 ( struct V_262 ) ) < 0 )
goto V_263;
if ( F_106 ( ( void V_251 * * ) V_1 -> V_252 . V_264 ,
sizeof( struct V_265 ) ,
F_107 ( struct V_265 ) ) < 0 )
goto V_266;
return 0 ;
V_266:
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_261 ) ;
V_263:
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_258 ) ;
V_260:
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_256 ) ;
V_257:
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_253 ) ;
return - V_255 ;
}
static void F_109 ( struct V_1 * V_1 )
{
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_253 ) ;
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_256 ) ;
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_258 ) ;
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_261 ) ;
F_108 ( ( void V_251 * * ) V_1 -> V_252 . V_264 ) ;
}
static int T_6 F_110 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
V_1 -> V_60 . V_61 . V_62 = 0 ;
V_1 -> V_60 . V_61 . V_267 = 1 * V_268 ;
V_18 = F_105 ( V_1 ) ;
if ( V_18 )
return V_18 ;
#ifdef F_111
V_18 = F_112 ( V_1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_113 ( V_1 ) ;
if ( V_18 )
goto V_269;
V_18 = F_114 ( V_1 ) ;
if ( V_18 )
goto V_270;
#endif
return V_18 ;
#ifdef F_111
V_270:
F_115 ( V_1 ) ;
V_269:
F_116 ( V_1 ) ;
V_37:
F_109 ( V_1 ) ;
return V_18 ;
#endif
}
static void T_7 F_117 ( struct V_1 * V_1 )
{
#ifdef F_111
F_116 ( V_1 ) ;
F_115 ( V_1 ) ;
F_118 ( V_1 ) ;
#endif
F_109 ( V_1 ) ;
}
static int T_5 F_119 ( void )
{
struct V_129 * V_271 ;
struct V_160 * V_272 ;
int V_18 = 0 ;
F_120 ( sizeof( struct V_189 ) > sizeof( V_271 -> V_273 ) ) ;
for( V_272 = & V_167 [ 0 ] ; V_272 < & V_167 [ V_165 ] ; ++ V_272 )
F_121 ( V_272 ) ;
if ( V_274 ) {
F_53 ( V_275
L_6
L_7 ) ;
goto V_37;
}
V_18 = F_122 ( & V_276 , 1 ) ;
if ( V_18 )
goto V_37;
V_18 = F_122 ( & V_277 , 1 ) ;
if ( V_18 )
goto V_278;
V_18 = F_122 ( & V_279 , 1 ) ;
if ( V_18 )
goto V_280;
V_18 = F_122 ( & V_281 , 1 ) ;
if ( V_18 )
goto V_282;
V_18 = F_123 () ;
if ( V_18 )
goto V_283;
V_18 = F_124 ( & V_284 ) ;
if ( V_18 )
goto V_285;
#ifdef F_125
V_18 = F_126 () ;
if ( V_18 )
goto V_286;
#endif
V_18 = F_127 ( & V_287 ) ;
if ( V_18 )
goto V_288;
V_18 = F_128 () ;
if ( V_18 )
goto V_289;
V_18 = F_129 () ;
if ( V_18 )
goto V_290;
V_18 = F_130 () ;
if ( V_18 )
goto V_291;
V_18 = F_131 () ;
if ( V_18 )
goto V_292;
V_18 = F_132 () ;
if ( V_18 )
goto V_293;
#ifdef F_111
V_18 = - V_255 ;
if ( F_133 () )
goto V_294;
if ( F_134 () )
goto V_295;
if ( F_135 () )
goto V_296;
if ( F_136 () )
goto V_297;
#endif
V_18 = F_137 () ;
if ( V_18 )
goto V_298;
V_18 = F_138 () ;
if ( V_18 )
goto V_299;
V_18 = F_139 () ;
if ( V_18 )
goto V_300;
V_18 = F_140 () ;
if ( V_18 )
goto V_301;
V_18 = F_141 () ;
if ( V_18 )
goto V_302;
V_18 = F_142 () ;
if ( V_18 )
goto V_303;
V_18 = F_143 () ;
if ( V_18 )
goto V_304;
V_18 = F_144 () ;
if ( V_18 )
goto V_305;
V_18 = F_101 () ;
if ( V_18 )
goto V_306;
#ifdef F_125
V_18 = F_145 () ;
if ( V_18 )
goto V_307;
#endif
V_37:
return V_18 ;
#ifdef F_125
V_307:
F_103 () ;
#endif
V_306:
F_146 () ;
V_305:
F_147 () ;
V_304:
F_148 () ;
V_303:
F_149 () ;
V_302:
F_150 () ;
V_301:
F_151 () ;
V_300:
F_152 () ;
V_299:
F_153 () ;
V_298:
#ifdef F_111
F_154 () ;
V_297:
F_155 () ;
V_296:
F_156 () ;
V_295:
F_157 () ;
V_294:
#endif
F_158 () ;
V_293:
F_159 () ;
V_292:
F_160 () ;
V_291:
F_161 () ;
V_290:
F_162 () ;
V_289:
F_163 ( & V_287 ) ;
V_288:
#ifdef F_125
F_164 () ;
V_286:
#endif
F_165 ( V_26 ) ;
F_166 ( V_26 ) ;
V_285:
F_167 () ;
V_283:
F_168 ( & V_281 ) ;
V_282:
F_168 ( & V_279 ) ;
V_280:
F_168 ( & V_277 ) ;
V_278:
F_168 ( & V_276 ) ;
goto V_37;
}
static void T_8 F_169 ( void )
{
if ( V_274 )
return;
F_165 ( V_26 ) ;
F_166 ( V_26 ) ;
#ifdef F_125
F_170 () ;
#endif
F_148 () ;
F_147 () ;
F_146 () ;
F_103 () ;
F_149 () ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
#ifdef F_111
F_154 () ;
F_155 () ;
F_156 () ;
F_157 () ;
#endif
F_158 () ;
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
F_167 () ;
F_163 ( & V_287 ) ;
#ifdef F_125
F_164 () ;
#endif
F_168 ( & V_281 ) ;
F_168 ( & V_279 ) ;
F_168 ( & V_277 ) ;
F_168 ( & V_276 ) ;
F_171 () ;
}
