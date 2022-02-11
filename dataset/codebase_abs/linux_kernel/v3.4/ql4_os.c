static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 ,
T_1 V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_1 V_15 = 0 ;
T_2 V_16 [ V_17 ] ;
int V_18 ;
memset ( V_16 , 0 , V_17 ) ;
if ( ( V_4 == V_19 ) &&
( V_8 -> V_20 == V_21 ) ) {
V_12 = (struct V_11 * ) V_8 ;
memcpy ( V_16 , & V_12 -> V_22 . V_23 , V_24 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_1
L_2 , V_26 ,
& V_10 -> V_27 . V_28 , V_16 ) ) ;
V_18 = F_5 ( V_10 , V_15 , V_5 , V_6 ,
V_16 ) ;
if ( V_18 )
V_18 = - V_29 ;
} else if ( ( V_4 == V_30 ) &&
( V_8 -> V_20 == V_31 ) ) {
V_14 = (struct V_13 * ) V_8 ;
memcpy ( V_16 , & V_14 -> V_32 . V_33 . V_34 , V_17 ) ;
V_15 |= V_35 ;
if ( ( V_3 == 0 ) || ( V_3 == 1 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_3
L_4 , V_26 ,
& V_10 -> V_27 . V_36 ,
V_16 ) ) ;
V_15 |= V_37 ;
V_18 = F_5 ( V_10 , V_15 , V_5 ,
V_6 , V_16 ) ;
} else {
F_4 ( V_38 , V_10 , L_5
L_6 , V_26 , V_3 ) ;
V_18 = - V_39 ;
goto V_40;
}
if ( V_18 != V_41 ) {
V_15 &= ~ V_37 ;
if ( V_3 == 0 ) {
V_15 |= V_42 ;
F_3 ( F_4 ( V_25 , V_10 , L_7
L_8
L_9 , V_26 ,
& V_10 -> V_27 . V_43 ,
V_16 ) ) ;
} else if ( V_3 == 1 ) {
V_15 |= V_44 ;
F_3 ( F_4 ( V_25 , V_10 , L_7
L_8
L_9 , V_26 ,
& V_10 -> V_27 . V_45 ,
V_16 ) ) ;
}
V_18 = F_5 ( V_10 , V_15 , V_5 ,
V_6 , V_16 ) ;
if ( V_18 )
V_18 = - V_29 ;
}
} else
V_18 = - V_39 ;
V_40:
return V_18 ;
}
static T_3 F_6 ( int V_46 , int V_47 )
{
switch ( V_46 ) {
case V_48 :
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return V_54 ;
default:
return 0 ;
}
case V_55 :
switch ( V_47 ) {
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
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
return V_54 ;
default:
return 0 ;
}
case V_75 :
switch ( V_47 ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
return V_54 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_91 ,
T_1 * V_92 , char * V_93 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
int V_98 = 0 ;
int V_99 = 0 ;
int V_100 = 0 , V_101 ;
if ( F_8 ( V_10 ) )
V_98 = ( V_10 -> V_102 . V_103 / 2 ) /
sizeof( struct V_94 ) ;
else
V_98 = V_104 ;
F_4 ( V_25 , V_10 , L_10 ,
V_26 , * V_92 , V_91 ) ;
if ( ! V_93 ) {
V_100 = - V_105 ;
goto V_106;
}
V_97 = (struct V_96 * ) V_93 ;
F_9 ( & V_10 -> V_107 ) ;
for ( V_101 = V_91 ; V_101 < V_98 ; V_101 ++ ) {
V_95 = (struct V_94 * ) V_10 -> V_108 + V_101 ;
if ( V_95 -> V_109 !=
F_10 ( V_110 ) )
continue;
V_97 -> V_91 = V_101 ;
strncpy ( V_97 -> V_111 , V_95 -> V_112 ,
V_113 ) ;
strncpy ( V_97 -> V_114 , V_95 -> V_115 ,
V_116 ) ;
V_97 -> V_117 = V_95 -> V_118 ;
if ( V_95 -> V_119 & V_120 )
V_97 -> V_121 = V_122 ;
if ( V_95 -> V_119 & V_123 )
V_97 -> V_121 = V_124 ;
V_97 ++ ;
V_99 ++ ;
if ( V_99 == * V_92 )
break;
else
continue;
}
F_11 ( & V_10 -> V_107 ) ;
V_106:
F_4 ( V_25 , V_10 , L_11 ,
V_26 , V_99 ) ;
* V_92 = V_99 ;
return V_100 ;
}
static int F_12 ( struct V_125 * V_126 , void * V_127 )
{
int V_100 = 0 ;
T_4 * V_91 = ( T_4 * ) V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
if ( ! F_13 ( V_126 ) )
goto V_133;
V_129 = F_14 ( V_126 ) ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
if ( F_15 ( V_129 ) )
goto V_133;
if ( V_132 -> V_91 == * V_91 )
V_100 = 1 ;
V_133:
return V_100 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_4 V_91 )
{
int V_100 = 0 ;
V_100 = F_17 ( & V_2 -> V_135 , & V_91 ,
F_12 ) ;
return V_100 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_91 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_94 * V_95 ;
T_5 V_136 ;
int V_98 = 0 ;
T_1 V_137 = 0 ;
T_1 V_138 ;
int V_100 = 0 ;
V_95 = F_19 ( V_10 -> V_139 , V_140 , & V_136 ) ;
if ( V_95 == NULL )
return - V_105 ;
memset ( V_95 , 0 , sizeof( struct V_94 ) ) ;
if ( F_8 ( V_10 ) )
V_98 = ( V_10 -> V_102 . V_103 / 2 ) /
sizeof( struct V_94 ) ;
else
V_98 = V_104 ;
if ( V_91 > V_98 ) {
V_100 = - V_29 ;
goto V_141;
}
V_100 = F_16 ( V_2 , V_91 ) ;
if ( V_100 ) {
F_4 ( V_25 , V_10 , L_12
L_13 , V_91 ) ;
V_100 = - V_142 ;
goto V_141;
}
V_138 = sizeof( struct V_94 ) ;
if ( F_20 ( V_10 ) )
V_137 = V_143 | ( V_91 * V_138 ) ;
else {
V_137 = V_144 + ( V_10 -> V_102 . V_145 << 2 ) ;
if ( V_10 -> V_146 == 1 )
V_137 += ( V_10 -> V_102 . V_103 / 2 ) ;
V_137 += ( V_91 * V_138 ) ;
}
V_100 = F_21 ( V_10 , V_136 , V_137 , V_138 ) ;
if ( V_100 != V_41 ) {
V_100 = - V_29 ;
goto V_141;
}
F_3 ( F_4 ( V_25 , V_10 , L_14 ,
F_22 ( V_95 -> V_109 ) ) ) ;
if ( F_22 ( V_95 -> V_109 ) != V_110 ) {
F_4 ( V_147 , V_10 , L_15 ) ;
goto V_141;
}
V_95 -> V_109 = F_10 ( 0xFFFF ) ;
V_137 = V_143 |
( V_91 * sizeof( struct V_94 ) ) ;
V_100 = F_23 ( V_10 , V_136 , V_137 , V_138 ,
V_148 ) ;
if ( V_100 == V_41 && V_10 -> V_108 ) {
F_9 ( & V_10 -> V_107 ) ;
memcpy ( (struct V_94 * ) V_10 -> V_108 + V_91 ,
V_95 , sizeof( struct V_94 ) ) ;
F_11 ( & V_10 -> V_107 ) ;
}
if ( V_100 != V_41 )
V_100 = - V_29 ;
V_141:
F_24 ( V_10 -> V_139 , V_95 , V_136 ) ;
return V_100 ;
}
static int F_25 ( struct V_149 * V_150 ,
enum V_151 V_46 ,
int V_47 , char * V_93 )
{
struct V_1 * V_2 = F_26 ( V_150 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_152 = - V_39 ;
if ( V_46 != V_75 )
return - V_39 ;
switch ( V_47 ) {
case V_76 :
V_152 = sprintf ( V_93 , L_16 , & V_10 -> V_27 . V_28 ) ;
break;
case V_77 :
V_152 = sprintf ( V_93 , L_16 , & V_10 -> V_27 . V_153 ) ;
break;
case V_78 :
V_152 = sprintf ( V_93 , L_16 , & V_10 -> V_27 . V_154 ) ;
break;
case V_80 :
if ( V_150 -> V_4 == V_19 )
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_155 &
V_156 ) ?
L_18 : L_19 ) ;
else if ( V_150 -> V_4 == V_30 )
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_157 &
V_158 ) ?
L_18 : L_19 ) ;
break;
case V_79 :
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_159 & V_160 ) ?
L_20 : L_21 ) ;
break;
case V_82 :
if ( V_150 -> V_3 == 0 )
V_152 = sprintf ( V_93 , L_22 , & V_10 -> V_27 . V_43 ) ;
if ( V_150 -> V_3 == 1 )
V_152 = sprintf ( V_93 , L_22 , & V_10 -> V_27 . V_45 ) ;
break;
case V_81 :
V_152 = sprintf ( V_93 , L_22 ,
& V_10 -> V_27 . V_36 ) ;
break;
case V_83 :
V_152 = sprintf ( V_93 , L_22 ,
& V_10 -> V_27 . V_161 ) ;
break;
case V_84 :
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_162 &
V_163 ) ?
L_23 : L_21 ) ;
break;
case V_85 :
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_162 &
V_164 ) ?
L_24 : L_21 ) ;
break;
case V_86 :
if ( V_150 -> V_4 == V_19 )
V_152 = sprintf ( V_93 , L_25 ,
( V_10 -> V_27 . V_165 &
V_166 ) ) ;
else if ( V_150 -> V_4 == V_30 )
V_152 = sprintf ( V_93 , L_25 ,
( V_10 -> V_27 . V_167 &
V_166 ) ) ;
break;
case V_87 :
if ( V_150 -> V_4 == V_19 )
V_152 = sprintf ( V_93 , L_25 ,
( ( V_10 -> V_27 . V_165 >> 13 ) &
V_168 ) ) ;
else if ( V_150 -> V_4 == V_30 )
V_152 = sprintf ( V_93 , L_25 ,
( ( V_10 -> V_27 . V_167 >> 13 ) &
V_168 ) ) ;
break;
case V_88 :
if ( V_150 -> V_4 == V_19 )
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_155 &
V_169 ) ?
L_18 : L_19 ) ;
else if ( V_150 -> V_4 == V_30 )
V_152 = sprintf ( V_93 , L_17 ,
( V_10 -> V_27 . V_157 &
V_170 ) ?
L_18 : L_19 ) ;
break;
case V_89 :
V_152 = sprintf ( V_93 , L_25 , V_10 -> V_27 . V_171 ) ;
break;
case V_90 :
if ( V_150 -> V_4 == V_19 )
V_152 = sprintf ( V_93 , L_25 , V_10 -> V_27 . V_172 ) ;
else if ( V_150 -> V_4 == V_30 )
V_152 = sprintf ( V_93 , L_25 , V_10 -> V_27 . V_173 ) ;
break;
default:
V_152 = - V_39 ;
}
return V_152 ;
}
static struct V_174 *
F_27 ( struct V_1 * V_2 , struct V_7 * V_8 ,
int V_175 )
{
int V_100 ;
struct V_174 * V_176 ;
struct V_177 * V_178 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( ! V_2 ) {
V_100 = - V_179 ;
F_28 ( V_147 L_27 ,
V_26 ) ;
return F_29 ( V_100 ) ;
}
V_10 = F_30 ( V_2 ) ;
V_176 = F_31 ( sizeof( struct V_177 ) ) ;
if ( ! V_176 ) {
V_100 = - V_105 ;
return F_29 ( V_100 ) ;
}
V_178 = V_176 -> V_134 ;
memset ( V_178 , 0 , sizeof( struct V_177 ) ) ;
if ( V_8 -> V_20 == V_21 ) {
memcpy ( & V_178 -> V_8 , V_8 , sizeof( struct V_11 ) ) ;
V_12 = (struct V_11 * ) & V_178 -> V_8 ;
F_3 ( F_4 ( V_25 , V_10 , L_28 , V_26 ,
( char * ) & V_12 -> V_22 ) ) ;
} else if ( V_8 -> V_20 == V_31 ) {
memcpy ( & V_178 -> V_8 , V_8 ,
sizeof( struct V_13 ) ) ;
V_14 = (struct V_13 * ) & V_178 -> V_8 ;
F_3 ( F_4 ( V_25 , V_10 , L_29 , V_26 ,
( char * ) & V_14 -> V_32 ) ) ;
}
V_178 -> V_180 = V_2 ;
return V_176 ;
}
static int F_32 ( struct V_174 * V_176 , int V_181 )
{
struct V_177 * V_178 ;
struct V_9 * V_10 ;
int V_100 = 0 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_178 = V_176 -> V_134 ;
V_10 = F_2 ( V_178 -> V_180 ) ;
if ( F_33 ( V_10 ) && ! F_34 ( V_182 , & V_10 -> V_119 ) )
V_100 = 1 ;
return V_100 ;
}
static void F_35 ( struct V_174 * V_176 )
{
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
F_36 ( V_176 ) ;
}
static int F_37 ( struct V_174 * V_176 ,
enum V_183 V_47 ,
char * V_93 )
{
struct V_177 * V_178 = V_176 -> V_134 ;
struct V_7 * V_8 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
switch ( V_47 ) {
case V_59 :
case V_58 :
if ( ! V_178 )
return - V_184 ;
V_8 = (struct V_7 * ) & V_178 -> V_8 ;
if ( ! V_8 )
return - V_184 ;
return F_38 ( (struct V_185 * )
& V_178 -> V_8 , V_47 , V_93 ) ;
default:
return - V_39 ;
}
}
static void F_39 ( struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_130 * V_131 ;
struct V_128 * V_190 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
struct V_191 * V_191 ;
int V_192 ;
int V_100 ;
T_5 V_193 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_190 = F_40 ( V_187 ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_192 = F_41 ( sizeof( struct V_191 ) ) ;
V_191 = F_42 ( & V_10 -> V_194 -> V_126 , V_192 ,
& V_193 , V_140 ) ;
if ( ! V_191 ) {
F_4 ( V_147 , V_10 ,
L_30 ) ;
goto V_195;
}
V_100 = F_43 ( V_10 , V_132 -> V_196 , V_192 ,
V_193 ) ;
if ( V_100 != V_41 ) {
F_4 ( V_147 , V_10 ,
L_31 ) ;
goto V_197;
}
V_189 -> V_198 = F_44 ( V_191 -> V_199 ) ;
V_189 -> V_200 = F_44 ( V_191 -> V_201 ) ;
V_189 -> V_202 = F_45 ( V_191 -> V_203 ) ;
V_189 -> V_204 = F_45 ( V_191 -> V_205 ) ;
V_189 -> V_206 = F_45 ( V_191 -> V_207 ) ;
V_189 -> V_208 = F_45 ( V_191 -> V_209 ) ;
V_189 -> V_210 = F_45 ( V_191 -> V_211 ) ;
V_189 -> V_212 = F_45 ( V_191 -> V_213 ) ;
V_189 -> V_214 = F_45 ( V_191 -> V_215 ) ;
V_189 -> V_216 = F_45 ( V_191 -> V_217 ) ;
V_189 -> V_218 = F_45 ( V_191 -> V_219 ) ;
V_189 -> V_220 = F_45 ( V_191 -> V_221 ) ;
V_189 -> V_222 = F_45 ( V_191 -> V_223 ) ;
V_189 -> V_224 = F_45 ( V_191 -> V_225 ) ;
V_189 -> V_226 = F_45 ( V_191 -> V_227 ) ;
V_189 -> V_228 =
F_45 ( V_191 -> V_229 ) ;
V_189 -> V_230 = F_45 ( V_191 -> V_231 ) ;
V_189 -> V_232 = F_45 ( V_191 -> V_233 ) ;
V_189 -> V_234 = F_45 ( V_191 -> V_235 ) ;
V_197:
F_46 ( & V_10 -> V_194 -> V_126 , V_192 , V_191 ,
V_193 ) ;
V_195:
return;
}
static enum V_236 F_47 ( struct V_237 * V_238 )
{
struct V_128 * V_239 ;
struct V_130 * V_131 ;
unsigned long V_119 ;
enum V_236 V_100 = V_240 ;
V_239 = F_48 ( F_49 ( V_238 -> V_125 ) ) ;
V_131 = V_239 -> V_134 ;
F_50 ( & V_239 -> V_241 , V_119 ) ;
if ( V_239 -> V_242 == V_243 )
V_100 = V_244 ;
F_51 ( & V_239 -> V_241 , V_119 ) ;
return V_100 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_245 * V_246 = V_2 -> V_247 ;
T_1 V_248 = V_249 ;
F_53 ( V_10 ) ;
switch ( V_10 -> V_250 & 0x0F00 ) {
case V_251 :
V_248 = V_252 ;
break;
case V_253 :
V_248 = V_254 ;
break;
case V_255 :
V_248 = V_256 ;
break;
case V_257 :
V_248 = V_258 ;
break;
}
V_246 -> V_259 = V_248 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_245 * V_246 = V_2 -> V_247 ;
T_1 V_242 = V_260 ;
if ( F_34 ( V_261 , & V_10 -> V_119 ) )
V_242 = V_262 ;
V_246 -> V_263 = V_242 ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_264 V_47 , char * V_93 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_152 ;
switch ( V_47 ) {
case V_49 :
V_152 = F_56 ( V_93 , V_10 -> V_265 , V_266 ) ;
break;
case V_50 :
V_152 = sprintf ( V_93 , L_16 , & V_10 -> V_27 . V_28 ) ;
break;
case V_51 :
V_152 = sprintf ( V_93 , L_17 , V_10 -> V_267 ) ;
break;
case V_52 :
F_54 ( V_2 ) ;
V_152 = sprintf ( V_93 , L_17 , F_57 ( V_2 ) ) ;
break;
case V_53 :
F_52 ( V_2 ) ;
V_152 = sprintf ( V_93 , L_17 , F_58 ( V_2 ) ) ;
break;
default:
return - V_39 ;
}
return V_152 ;
}
static void F_59 ( struct V_9 * V_10 )
{
if ( V_10 -> V_268 )
return;
V_10 -> V_268 = F_60 ( V_10 -> V_180 ,
& V_269 ,
V_19 , 0 , 0 ) ;
if ( ! V_10 -> V_268 )
F_4 ( V_147 , V_10 , L_32
L_33 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_270 )
V_10 -> V_270 = F_60 ( V_10 -> V_180 ,
& V_269 ,
V_30 , 0 ,
0 ) ;
if ( ! V_10 -> V_270 )
F_4 ( V_147 , V_10 , L_34
L_33 ) ;
if ( ! V_10 -> V_271 )
V_10 -> V_271 = F_60 ( V_10 -> V_180 ,
& V_269 ,
V_30 , 1 ,
0 ) ;
if ( ! V_10 -> V_271 )
F_4 ( V_147 , V_10 , L_34
L_35 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
if ( V_10 -> V_27 . V_155 & V_156 )
F_59 ( V_10 ) ;
if ( V_10 -> V_27 . V_157 & V_158 )
F_61 ( V_10 ) ;
}
static void F_63 ( struct V_9 * V_10 )
{
if ( V_10 -> V_268 ) {
F_64 ( V_10 -> V_268 ) ;
V_10 -> V_268 = NULL ;
}
}
static void F_65 ( struct V_9 * V_10 )
{
if ( V_10 -> V_270 ) {
F_64 ( V_10 -> V_270 ) ;
V_10 -> V_270 = NULL ;
}
if ( V_10 -> V_271 ) {
F_64 ( V_10 -> V_271 ) ;
V_10 -> V_271 = NULL ;
}
}
static void F_66 ( struct V_9 * V_10 )
{
F_63 ( V_10 ) ;
F_65 ( V_10 ) ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_272 * V_273 ,
struct V_274 * V_275 )
{
switch ( V_273 -> V_47 ) {
case V_82 :
if ( V_273 -> V_3 & 0x1 )
memcpy ( V_275 -> V_45 , V_273 -> V_276 ,
sizeof( V_275 -> V_45 ) ) ;
else
memcpy ( V_275 -> V_43 , V_273 -> V_276 ,
sizeof( V_275 -> V_43 ) ) ;
break;
case V_81 :
if ( V_273 -> V_3 & 0x1 )
break;
memcpy ( V_275 -> V_277 , & V_273 -> V_276 [ 8 ] ,
sizeof( V_275 -> V_277 ) ) ;
break;
case V_83 :
if ( V_273 -> V_3 & 0x1 )
break;
memcpy ( V_275 -> V_278 , V_273 -> V_276 ,
sizeof( V_275 -> V_278 ) ) ;
break;
case V_84 :
if ( V_273 -> V_3 & 0x1 )
break;
if ( V_273 -> V_276 [ 0 ] == V_279 )
V_275 -> V_280 &=
F_68 (
~ V_163 ) ;
else if ( V_273 -> V_276 [ 0 ] == V_281 )
V_275 -> V_280 |=
F_68 (
V_163 ) ;
else
F_4 ( V_147 , V_10 , L_36
L_37 ) ;
break;
case V_85 :
if ( V_273 -> V_3 & 0x1 )
break;
if ( V_273 -> V_276 [ 0 ] ==
V_282 )
V_275 -> V_280 |= F_68 (
V_164 ) ;
else if ( V_273 -> V_276 [ 0 ] ==
V_283 )
V_275 -> V_280 &= F_68 (
~ V_164 ) ;
else
F_4 ( V_147 , V_10 , L_36
L_38 ) ;
break;
case V_284 :
if ( V_273 -> V_3 & 0x1 )
break;
if ( V_273 -> V_276 [ 0 ] == V_285 )
memset ( V_275 -> V_278 , 0 ,
sizeof( V_275 -> V_278 ) ) ;
break;
case V_80 :
if ( V_273 -> V_276 [ 0 ] == V_286 ) {
V_275 -> V_287 |=
F_68 ( V_158 ) ;
F_61 ( V_10 ) ;
} else {
V_275 -> V_287 &=
F_68 ( ~ V_158 &
0xFFFF ) ;
F_65 ( V_10 ) ;
}
break;
case V_288 :
if ( V_273 -> V_152 != sizeof( V_275 -> V_167 ) )
break;
V_275 -> V_167 =
F_69 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
case V_88 :
if ( V_273 -> V_276 [ 0 ] == V_289 )
V_275 -> V_287 |=
F_68 ( V_170 ) ;
else
V_275 -> V_287 &=
F_68 ( ~ V_170 ) ;
break;
case V_89 :
V_275 -> V_171 =
F_68 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
case V_90 :
if ( V_273 -> V_3 & 0x1 )
break;
V_275 -> V_173 =
F_68 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_39 ,
V_273 -> V_47 ) ;
break;
}
}
static void F_70 ( struct V_9 * V_10 ,
struct V_272 * V_273 ,
struct V_274 * V_275 )
{
switch ( V_273 -> V_47 ) {
case V_76 :
memcpy ( V_275 -> V_290 , V_273 -> V_276 ,
sizeof( V_275 -> V_290 ) ) ;
break;
case V_77 :
memcpy ( V_275 -> V_291 , V_273 -> V_276 ,
sizeof( V_275 -> V_291 ) ) ;
break;
case V_78 :
memcpy ( V_275 -> V_292 , V_273 -> V_276 ,
sizeof( V_275 -> V_292 ) ) ;
break;
case V_79 :
if ( V_273 -> V_276 [ 0 ] == V_293 )
V_275 -> V_294 |=
F_68 ( V_160 ) ;
else if ( V_273 -> V_276 [ 0 ] == V_295 )
V_275 -> V_294 &=
F_68 ( ~ V_160 ) ;
else
F_4 ( V_147 , V_10 , L_40 ) ;
break;
case V_80 :
if ( V_273 -> V_276 [ 0 ] == V_286 ) {
V_275 -> V_296 |=
F_68 ( V_156 ) ;
F_59 ( V_10 ) ;
} else {
V_275 -> V_296 &=
F_68 ( ~ V_156 &
0xFFFF ) ;
F_63 ( V_10 ) ;
}
break;
case V_288 :
if ( V_273 -> V_152 != sizeof( V_275 -> V_165 ) )
break;
V_275 -> V_165 =
F_69 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
case V_88 :
if ( V_273 -> V_276 [ 0 ] == V_289 )
V_275 -> V_296 |=
F_68 ( V_169 ) ;
else
V_275 -> V_296 &=
F_68 ( ~ V_169 ) ;
break;
case V_89 :
V_275 -> V_171 =
F_68 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
case V_90 :
V_275 -> V_172 =
F_68 ( * ( T_4 * ) V_273 -> V_276 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_41 ,
V_273 -> V_47 ) ;
break;
}
}
static void
F_71 ( struct V_274 * V_275 )
{
struct V_297 * V_298 ;
V_298 = (struct V_297 * ) V_275 ;
memset ( V_298 -> V_299 , 0 , sizeof( V_298 -> V_299 ) ) ;
memset ( V_298 -> V_300 , 0 , sizeof( V_298 -> V_300 ) ) ;
memset ( V_298 -> V_301 , 0 , sizeof( V_298 -> V_301 ) ) ;
memset ( V_298 -> V_302 , 0 , sizeof( V_298 -> V_302 ) ) ;
memset ( V_298 -> V_303 , 0 , sizeof( V_298 -> V_303 ) ) ;
memset ( V_298 -> V_304 , 0 , sizeof( V_298 -> V_304 ) ) ;
memset ( V_298 -> V_305 , 0 , sizeof( V_298 -> V_305 ) ) ;
memset ( V_298 -> V_306 , 0 , sizeof( V_298 -> V_306 ) ) ;
memset ( V_298 -> V_307 , 0 , sizeof( V_298 -> V_307 ) ) ;
memset ( V_298 -> V_308 , 0 , sizeof( V_298 -> V_308 ) ) ;
memset ( V_298 -> V_309 , 0 , sizeof( V_298 -> V_309 ) ) ;
memset ( V_298 -> V_310 , 0 , sizeof( V_298 -> V_310 ) ) ;
memset ( V_298 -> V_311 , 0 , sizeof( V_298 -> V_311 ) ) ;
memset ( V_298 -> V_312 , 0 , sizeof( V_298 -> V_312 ) ) ;
memset ( V_298 -> V_313 , 0 , sizeof( V_298 -> V_313 ) ) ;
}
static int
F_72 ( struct V_1 * V_2 , void * V_127 , T_1 V_152 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_18 = 0 ;
struct V_272 * V_273 = NULL ;
struct V_274 * V_275 = NULL ;
T_5 V_314 ;
T_1 V_315 [ V_316 ] ;
T_1 V_317 [ V_316 ] ;
T_1 V_318 = V_152 ;
struct V_319 * V_320 ;
V_275 = F_42 ( & V_10 -> V_194 -> V_126 ,
sizeof( struct V_274 ) ,
& V_314 , V_140 ) ;
if ( ! V_275 ) {
F_4 ( V_147 , V_10 , L_42 ,
V_26 ) ;
return - V_105 ;
}
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
if ( F_73 ( V_10 , & V_315 [ 0 ] , & V_317 [ 0 ] , V_314 ) ) {
F_4 ( V_147 , V_10 , L_43 , V_26 ) ;
V_18 = - V_321 ;
goto V_322;
}
F_74 (attr, data, len, rem) {
V_273 = F_75 ( V_320 ) ;
if ( V_273 -> V_46 != V_75 )
continue;
switch ( V_273 -> V_4 ) {
case V_19 :
switch ( V_273 -> V_3 ) {
case 0 :
F_70 ( V_10 , V_273 , V_275 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_44
L_45 ,
V_273 -> V_3 ) ;
break;
}
break;
case V_30 :
switch ( V_273 -> V_3 ) {
case 0 :
case 1 :
F_67 ( V_10 , V_273 , V_275 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_46
L_45 ,
V_273 -> V_3 ) ;
break;
}
break;
default:
F_4 ( V_147 , V_10 , L_47 ) ;
break;
}
}
V_275 -> V_109 = F_76 ( 0x11BEAD5A ) ;
V_18 = F_23 ( V_10 , V_314 , V_323 ,
sizeof( struct V_274 ) ,
V_148 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_147 , V_10 , L_48 ,
V_26 ) ;
V_18 = - V_321 ;
goto V_322;
}
V_18 = F_77 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_147 , V_10 , L_49 ,
V_26 ) ;
V_18 = - V_321 ;
goto V_322;
}
F_78 ( & V_10 -> V_324 ,
V_325 * V_326 ) ;
F_71 ( V_275 ) ;
V_18 = F_79 ( V_10 , & V_315 [ 0 ] , & V_317 [ 0 ] , V_314 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_147 , V_10 , L_50 ,
V_26 ) ;
V_18 = - V_321 ;
goto V_322;
}
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
F_80 ( V_10 , & V_315 [ 0 ] , & V_317 [ 0 ] , V_275 ,
V_314 ) ;
V_322:
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( struct V_274 ) ,
V_275 , V_314 ) ;
return V_18 ;
}
static int F_81 ( struct V_128 * V_190 ,
enum V_183 V_47 , char * V_93 )
{
struct V_130 * V_131 = V_190 -> V_134 ;
struct V_132 * V_132 = V_131 -> V_134 ;
struct V_9 * V_10 = V_132 -> V_10 ;
int V_18 , V_152 ;
T_4 V_327 ;
switch ( V_47 ) {
case V_70 :
V_18 = F_82 ( V_10 , V_131 -> V_328 ,
V_131 -> V_329 , V_330 ,
& V_327 ) ;
if ( V_18 )
return - V_29 ;
V_152 = sprintf ( V_93 , L_51 , V_327 ) ;
break;
case V_69 :
V_18 = F_82 ( V_10 , V_131 -> V_111 ,
V_131 -> V_114 , V_331 ,
& V_327 ) ;
if ( V_18 )
return - V_29 ;
V_152 = sprintf ( V_93 , L_51 , V_327 ) ;
break;
default:
return F_83 ( V_190 , V_47 , V_93 ) ;
}
return V_152 ;
}
static int F_84 ( struct V_186 * V_187 ,
enum V_183 V_47 , char * V_93 )
{
struct V_332 * V_333 ;
struct V_334 * V_334 ;
struct V_7 * V_8 ;
int V_152 = 0 ;
V_333 = V_187 -> V_134 ;
V_334 = V_333 -> V_134 ;
V_8 = & V_334 -> V_178 -> V_8 ;
switch ( V_47 ) {
case V_59 :
case V_58 :
return F_38 ( (struct V_185 * )
V_8 , V_47 , V_93 ) ;
default:
return F_85 ( V_187 , V_47 , V_93 ) ;
}
return V_152 ;
}
int F_86 ( struct V_9 * V_10 , T_4 * V_335 )
{
T_1 V_336 = 0 ;
T_4 V_337 ;
int V_100 ;
V_338:
V_337 = F_87 ( V_10 -> V_339 , V_340 ) ;
if ( V_337 >= V_340 ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_52 ) ) ;
V_100 = V_341 ;
goto V_342;
}
if ( F_88 ( V_337 , V_10 -> V_339 ) )
goto V_338;
F_3 ( F_4 ( V_25 , V_10 ,
L_53 , V_337 ) ) ;
V_100 = F_89 ( V_10 , V_337 , & V_336 ) ;
if ( V_100 == V_341 ) {
if ( V_336 == V_343 ) {
F_4 ( V_25 , V_10 ,
L_54 ,
V_337 ) ;
goto V_338;
}
F_3 ( F_4 ( V_25 , V_10 ,
L_55 ) ) ;
}
* V_335 = V_337 ;
V_342:
return V_100 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_132 * V_132 ,
char * V_344 ,
char * V_345 )
{
T_2 V_346 [ V_17 ] ;
char V_347 [ V_348 ] ;
int V_349 = V_41 , V_100 = 0 ;
if ( V_132 -> V_350 . V_15 & V_351 ) {
V_100 = F_91 ( V_345 , strlen ( V_345 ) , V_346 ,
'\0' , NULL ) ;
if ( V_100 == 0 ) {
V_349 = V_341 ;
goto V_352;
}
V_100 = sprintf ( V_347 , L_56 , V_346 ) ;
} else {
V_100 = F_92 ( V_345 , strlen ( V_345 ) , V_346 ,
'\0' , NULL ) ;
if ( V_100 == 0 ) {
V_349 = V_341 ;
goto V_352;
}
V_100 = sprintf ( V_347 , L_57 , V_346 ) ;
}
if ( strcmp ( V_344 , V_347 ) )
V_349 = V_341 ;
V_352:
return V_349 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_186 * V_187 )
{
int V_327 = 0 , V_353 , V_18 ;
struct V_128 * V_190 = F_40 ( V_187 ) ;
struct V_130 * V_131 , * V_354 ;
struct V_332 * V_333 , * V_355 ;
struct V_132 * V_132 ;
V_131 = V_190 -> V_134 ;
V_333 = V_187 -> V_134 ;
if ( V_131 -> V_356 == NULL ||
V_333 -> V_357 == NULL ||
V_333 -> V_358 == 0 )
return V_341 ;
V_353 = F_20 ( V_10 ) ? V_359 :
V_360 ;
for ( V_327 = 0 ; V_327 < V_353 ; V_327 ++ ) {
V_132 = F_94 ( V_10 , V_327 ) ;
if ( V_132 == NULL )
continue;
if ( V_132 -> V_361 != V_362 )
continue;
V_354 = V_132 -> V_131 -> V_134 ;
V_355 = V_132 -> V_333 -> V_134 ;
if ( V_354 -> V_356 == NULL ||
V_355 -> V_357 == NULL ||
V_355 -> V_358 == 0 )
continue;
F_3 ( F_4 ( V_25 , V_10 ,
L_58 ,
V_354 -> V_356 ,
V_131 -> V_356 ) ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_59 ,
V_355 -> V_357 ,
V_333 -> V_357 ) ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_60 ,
V_355 -> V_358 ,
V_333 -> V_358 ) ) ;
if ( strcmp ( V_354 -> V_356 , V_131 -> V_356 ) )
continue;
V_18 = F_90 ( V_10 , V_132 ,
V_355 -> V_357 ,
V_333 -> V_357 ) ;
if ( V_18 == V_341 )
continue;
if ( V_355 -> V_358 != V_333 -> V_358 )
continue;
break;
}
if ( V_327 == V_353 )
return V_341 ;
F_3 ( F_4 ( V_25 , V_10 ,
L_61 ) ) ;
return V_41 ;
}
static struct V_128 *
F_95 ( struct V_174 * V_176 ,
T_4 V_363 , T_4 V_364 ,
T_1 V_365 )
{
struct V_128 * V_190 ;
struct V_9 * V_10 ;
struct V_177 * V_178 ;
struct V_132 * V_132 ;
T_4 V_335 ;
struct V_130 * V_131 ;
struct V_7 * V_8 ;
int V_100 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( ! V_176 ) {
F_28 ( V_147 L_62 ) ;
return NULL ;
}
V_178 = V_176 -> V_134 ;
V_8 = (struct V_7 * ) & V_178 -> V_8 ;
V_10 = F_2 ( V_178 -> V_180 ) ;
V_100 = F_86 ( V_10 , & V_335 ) ;
if ( V_100 == V_341 )
return NULL ;
V_190 = F_96 ( & V_269 , V_178 -> V_180 ,
V_363 , sizeof( struct V_132 ) ,
sizeof( struct V_366 ) ,
V_365 , V_335 ) ;
if ( ! V_190 )
return NULL ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_196 = V_335 ;
V_132 -> V_367 = V_368 ;
V_132 -> V_10 = V_10 ;
V_132 -> V_131 = V_190 ;
V_132 -> V_369 = V_370 ;
V_132 -> V_371 = V_372 ;
V_190 -> V_373 = V_374 ;
V_10 -> V_375 [ V_132 -> V_196 ] = V_132 ;
V_10 -> V_376 ++ ;
return V_190 ;
}
static void F_97 ( struct V_128 * V_190 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
unsigned long V_119 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
F_98 ( V_10 , V_132 -> V_196 ) ;
F_50 ( & V_10 -> V_377 , V_119 ) ;
F_99 ( V_10 , V_132 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
F_100 ( V_190 ) ;
}
static struct V_186 *
F_101 ( struct V_128 * V_190 , T_1 V_378 )
{
struct V_186 * V_187 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_187 = F_102 ( V_190 , sizeof( struct V_334 ) ,
V_378 ) ;
if ( ! V_187 )
return NULL ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_333 = V_187 ;
return V_187 ;
}
static int F_103 ( struct V_128 * V_129 ,
struct V_186 * V_187 ,
T_6 V_379 , int V_380 )
{
struct V_332 * V_333 ;
struct V_334 * V_334 ;
struct V_174 * V_176 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( F_104 ( V_129 , V_187 , V_380 ) )
return - V_29 ;
V_176 = F_105 ( V_379 ) ;
V_333 = V_187 -> V_134 ;
V_334 = V_333 -> V_134 ;
V_334 -> V_178 = V_176 -> V_134 ;
return 0 ;
}
static int F_106 ( struct V_186 * V_187 )
{
struct V_128 * V_190 = F_40 ( V_187 ) ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
struct V_381 * V_350 = NULL ;
T_5 V_382 ;
T_1 V_336 = 0 ;
int V_100 = 0 ;
int V_349 = V_41 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_100 = F_93 ( V_10 , V_187 ) ;
if ( V_100 == V_41 ) {
F_4 ( V_25 , V_10 ,
L_63 ) ;
V_100 = - V_383 ;
goto V_384;
}
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_382 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_64 , V_26 ) ;
V_100 = - V_105 ;
goto V_384;
}
V_100 = F_107 ( V_10 , V_132 , V_187 , & V_336 ) ;
if ( V_100 ) {
if ( V_336 )
if ( V_132 -> V_367 ==
V_385 ) {
V_132 -> V_369 ( V_132 -> V_131 ) ;
goto V_386;
}
F_4 ( V_147 , V_10 , L_65 ,
V_26 , V_132 -> V_196 ) ;
goto V_384;
}
V_349 = F_108 ( V_10 , V_132 -> V_196 ) ;
if ( V_349 == V_341 ) {
F_4 ( V_147 , V_10 , L_66 , V_26 ,
V_131 -> V_356 ) ;
V_100 = - V_29 ;
goto V_384;
}
if ( V_132 -> V_367 == V_368 )
V_132 -> V_367 = V_387 ;
F_3 ( F_28 ( V_25 L_67 , V_26 ,
V_132 -> V_367 ) ) ;
V_386:
V_100 = 0 ;
V_384:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_382 ) ;
return V_100 ;
}
static void F_109 ( struct V_186 * V_187 )
{
struct V_128 * V_190 = F_40 ( V_187 ) ;
struct V_130 * V_131 ;
struct V_9 * V_10 ;
struct V_132 * V_132 ;
int V_15 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_15 = V_388 ;
if ( F_110 ( V_10 , V_132 , V_15 ) == V_341 )
F_4 ( V_147 , V_10 , L_68 , V_26 ) ;
}
static void F_111 ( struct V_389 * V_390 )
{
struct V_366 * V_391 ;
struct V_9 * V_10 ;
struct V_392 * V_393 ;
struct V_394 * V_395 ;
struct V_396 * V_397 ;
T_2 * V_127 ;
T_1 V_398 ;
struct V_332 * V_333 ;
int V_399 ;
T_7 V_400 ;
V_391 = F_112 ( V_390 , struct V_366 , V_401 ) ;
V_10 = V_391 -> V_10 ;
V_395 = V_391 -> V_395 ;
V_393 = & V_391 -> V_393 ;
V_399 = sizeof( struct V_396 ) ;
F_113 ( F_28 ( V_25 L_69 ) ) ;
F_113 ( F_114 ( V_393 , 64 ) ) ;
F_113 ( F_28 ( V_25 L_70 ) ) ;
F_113 ( F_114 ( V_391 -> V_402 , 64 ) ) ;
V_333 = V_395 -> V_333 ;
switch ( V_393 -> V_403 ) {
case V_404 :
V_397 = (struct V_396 * ) V_391 -> V_402 ;
V_400 = V_393 -> V_405 ;
V_397 -> V_400 = V_400 ;
V_127 = V_391 -> V_402 + V_399 ;
V_398 = V_391 -> V_406 - V_399 ;
F_115 ( V_333 , V_397 , V_127 , V_398 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_71 ,
V_393 -> V_403 ) ;
break;
}
return;
}
static int F_116 ( struct V_394 * V_395 , T_2 V_407 )
{
struct V_366 * V_391 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
int V_399 ;
V_131 = V_395 -> V_333 -> V_239 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_391 = V_395 -> V_134 ;
memset ( V_391 , 0 , sizeof( struct V_366 ) ) ;
if ( V_395 -> V_238 ) {
F_4 ( V_25 , V_10 ,
L_72 , V_26 ) ;
return - V_29 ;
}
V_399 = sizeof( struct V_396 ) ;
V_391 -> V_10 = V_10 ;
V_391 -> V_395 = V_395 ;
if ( V_395 -> V_408 ) {
V_391 -> V_409 = F_117 ( & V_10 -> V_194 -> V_126 , V_395 -> V_127 ,
V_395 -> V_408 ,
V_410 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_73 ,
V_26 , V_395 -> V_333 -> V_411 , V_399 ) ) ;
V_391 -> V_406 = V_395 -> V_333 -> V_411 + V_399 ;
V_391 -> V_402 = F_42 ( & V_10 -> V_194 -> V_126 ,
V_391 -> V_406 ,
& V_391 -> V_412 ,
V_413 ) ;
if ( ! V_391 -> V_402 )
goto V_414;
V_391 -> V_415 = V_395 -> V_408 + V_399 ;
V_391 -> V_416 = F_42 ( & V_10 -> V_194 -> V_126 ,
V_391 -> V_415 ,
& V_391 -> V_417 ,
V_413 ) ;
if ( ! V_391 -> V_416 )
goto V_414;
V_395 -> V_397 = V_391 -> V_416 ;
F_118 ( & V_391 -> V_401 , F_111 ) ;
return 0 ;
V_414:
if ( V_391 -> V_402 )
F_46 ( & V_10 -> V_194 -> V_126 , V_391 -> V_406 ,
V_391 -> V_402 , V_391 -> V_412 ) ;
if ( V_391 -> V_416 )
F_46 ( & V_10 -> V_194 -> V_126 , V_391 -> V_415 ,
V_391 -> V_416 , V_391 -> V_417 ) ;
return - V_105 ;
}
static void F_119 ( struct V_394 * V_395 )
{
struct V_366 * V_391 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
int V_399 ;
V_399 = sizeof( struct V_396 ) ;
V_131 = V_395 -> V_333 -> V_239 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_391 = V_395 -> V_134 ;
if ( V_395 -> V_408 ) {
F_120 ( & V_10 -> V_194 -> V_126 , V_391 -> V_409 ,
V_395 -> V_408 , V_410 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_73 ,
V_26 , V_395 -> V_333 -> V_411 , V_399 ) ) ;
F_46 ( & V_10 -> V_194 -> V_126 , V_391 -> V_406 ,
V_391 -> V_402 , V_391 -> V_412 ) ;
F_46 ( & V_10 -> V_194 -> V_126 , V_391 -> V_415 ,
V_391 -> V_416 , V_391 -> V_417 ) ;
return;
}
static int F_121 ( struct V_394 * V_395 )
{
struct V_237 * V_238 = V_395 -> V_238 ;
struct V_130 * V_131 = V_395 -> V_333 -> V_239 ;
struct V_132 * V_132 = V_131 -> V_134 ;
struct V_9 * V_10 = V_132 -> V_10 ;
if ( ! V_238 )
return F_122 ( V_395 ) ;
F_4 ( V_25 , V_10 , L_74 ,
V_26 ) ;
return - V_39 ;
}
static void F_123 ( struct V_9 * V_10 ,
struct V_381 * V_350 ,
struct V_128 * V_190 ,
struct V_186 * V_187 )
{
int V_418 = 0 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_332 * V_333 ;
char V_419 [ V_348 ] ;
T_4 V_15 = 0 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_333 = V_187 -> V_134 ;
V_132 -> V_91 = F_124 ( V_350 -> V_91 ) ;
V_333 -> V_411 = V_420 *
F_124 ( V_350 -> V_421 ) ;
V_333 -> V_422 = V_420 *
F_124 ( V_350 -> V_423 ) ;
V_131 -> V_424 =
( V_425 & F_124 ( V_350 -> V_426 ) ) ;
V_131 -> V_427 = F_124 ( V_350 -> V_428 ) ;
V_131 -> V_429 = ( V_430 & F_124 ( V_350 -> V_426 ) ) ;
V_131 -> V_431 = V_420 *
F_124 ( V_350 -> V_432 ) ;
V_131 -> V_433 = V_420 *
F_124 ( V_350 -> V_434 ) ;
V_131 -> V_435 = F_124 ( V_350 -> V_436 ) ;
V_131 -> V_437 = F_124 ( V_350 -> V_438 ) ;
V_333 -> V_358 = F_124 ( V_350 -> V_439 ) ;
V_131 -> V_440 = F_45 ( V_350 -> V_441 ) ;
V_15 = F_124 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 )
sprintf ( V_419 , L_56 , V_350 -> V_419 ) ;
else
sprintf ( V_419 , L_57 , V_350 -> V_419 ) ;
F_125 ( V_187 , V_60 ,
( char * ) V_350 -> V_442 , V_418 ) ;
F_125 ( V_187 , V_443 ,
( char * ) V_10 -> V_267 , V_418 ) ;
F_125 ( V_187 , V_56 ,
( char * ) V_419 , V_418 ) ;
F_125 ( V_187 , V_62 ,
( char * ) V_350 -> V_444 , V_418 ) ;
}
void F_126 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
struct V_128 * V_190 ;
struct V_186 * V_187 ;
T_1 V_445 ;
T_5 V_382 ;
struct V_381 * V_350 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_382 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_64 , V_26 ) ;
goto V_446;
}
if ( F_127 ( V_10 , V_132 -> V_196 , V_350 ,
V_382 , NULL , NULL , & V_445 ,
NULL , NULL , NULL ) == V_341 ) {
F_3 ( F_4 ( V_147 , V_10 , L_75
L_76 ,
V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ) ;
goto V_446;
}
V_190 = V_132 -> V_131 ;
V_187 = V_132 -> V_333 ;
F_123 ( V_10 , V_350 , V_190 , V_187 ) ;
V_446:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_382 ) ;
}
void F_128 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
struct V_128 * V_190 ;
struct V_186 * V_187 ;
struct V_130 * V_131 ;
struct V_332 * V_333 ;
T_1 V_445 ;
T_5 V_382 ;
struct V_381 * V_350 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_382 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_64 , V_26 ) ;
goto V_448;
}
if ( F_127 ( V_10 , V_132 -> V_196 , V_350 ,
V_382 , NULL , NULL , & V_445 ,
NULL , NULL , NULL ) == V_341 ) {
F_3 ( F_4 ( V_147 , V_10 , L_75
L_76 ,
V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ) ;
goto V_448;
}
V_190 = V_132 -> V_131 ;
V_131 = V_190 -> V_134 ;
V_187 = V_132 -> V_333 ;
V_333 = V_187 -> V_134 ;
V_132 -> V_449 =
( F_124 ( V_350 -> V_450 ) > V_451 ) &&
( F_124 ( V_350 -> V_450 ) < V_451 * 10 ) ?
F_124 ( V_350 -> V_450 ) : V_451 ;
V_132 -> V_452 =
F_124 ( V_350 -> V_436 ) ;
V_132 -> V_91 = F_124 ( V_350 -> V_91 ) ;
V_333 -> V_411 = V_420 *
F_124 ( V_350 -> V_421 ) ;
V_333 -> V_422 = V_420 *
F_124 ( V_350 -> V_423 ) ;
V_131 -> V_424 =
( V_425 & F_124 ( V_350 -> V_426 ) ) ;
V_131 -> V_427 = F_124 ( V_350 -> V_428 ) ;
V_131 -> V_429 = ( V_430 & F_124 ( V_350 -> V_426 ) ) ;
V_131 -> V_431 = V_420 *
F_124 ( V_350 -> V_432 ) ;
V_131 -> V_433 = V_420 *
F_124 ( V_350 -> V_434 ) ;
V_131 -> V_435 = F_124 ( V_350 -> V_436 ) ;
V_131 -> V_437 = F_124 ( V_350 -> V_438 ) ;
V_131 -> V_440 = F_45 ( V_350 -> V_441 ) ;
memcpy ( V_131 -> V_453 , V_10 -> V_267 ,
F_129 ( sizeof( V_10 -> V_267 ) , sizeof( V_131 -> V_453 ) ) ) ;
F_125 ( V_187 , V_62 ,
( char * ) V_350 -> V_444 , 0 ) ;
V_448:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_382 ) ;
}
static void F_130 ( struct V_9 * V_10 , void * V_454 ,
unsigned long V_455 )
{
F_131 ( F_28 ( L_77 ,
V_26 , V_10 -> V_180 -> V_447 ) ) ;
F_132 ( & V_10 -> V_456 ) ;
V_10 -> V_456 . V_457 = V_458 + V_455 * V_326 ;
V_10 -> V_456 . V_127 = ( unsigned long ) V_10 ;
V_10 -> V_456 . V_459 = ( void (*) ( unsigned long ) ) V_454 ;
F_133 ( & V_10 -> V_456 ) ;
V_10 -> V_460 = 1 ;
}
static void F_134 ( struct V_9 * V_10 )
{
F_135 ( & V_10 -> V_456 ) ;
V_10 -> V_460 = 0 ;
}
void F_136 ( struct V_128 * V_129 )
{
F_137 ( V_129 ) ;
}
void F_138 ( struct V_9 * V_10 )
{
F_139 ( V_10 -> V_180 , F_136 ) ;
}
static struct V_461 * F_140 ( struct V_9 * V_10 ,
struct V_132 * V_132 ,
struct V_237 * V_462 )
{
struct V_461 * V_461 ;
V_461 = F_141 ( V_10 -> V_463 , V_413 ) ;
if ( ! V_461 )
return V_461 ;
F_142 ( & V_461 -> V_464 ) ;
V_461 -> V_10 = V_10 ;
V_461 -> V_465 = V_132 ;
V_461 -> V_462 = V_462 ;
V_461 -> V_119 = 0 ;
F_143 ( V_462 ) = ( void * ) V_461 ;
return V_461 ;
}
static void F_144 ( struct V_9 * V_10 , struct V_461 * V_461 )
{
struct V_237 * V_462 = V_461 -> V_462 ;
if ( V_461 -> V_119 & V_466 ) {
F_145 ( V_462 ) ;
V_461 -> V_119 &= ~ V_466 ;
}
F_143 ( V_462 ) = NULL ;
}
void F_146 ( struct V_467 * V_468 )
{
struct V_461 * V_461 = F_112 ( V_468 , struct V_461 , V_464 ) ;
struct V_237 * V_462 = V_461 -> V_462 ;
struct V_9 * V_10 = V_461 -> V_10 ;
F_144 ( V_10 , V_461 ) ;
F_147 ( V_461 , V_10 -> V_463 ) ;
V_462 -> V_469 ( V_462 ) ;
}
static int F_148 ( struct V_1 * V_180 , struct V_237 * V_462 )
{
struct V_9 * V_10 = F_2 ( V_180 ) ;
struct V_132 * V_132 = V_462 -> V_125 -> V_470 ;
struct V_128 * V_131 = V_132 -> V_131 ;
struct V_461 * V_461 ;
int V_18 ;
if ( F_34 ( V_471 , & V_10 -> V_119 ) ) {
if ( F_34 ( V_472 , & V_10 -> V_119 ) )
V_462 -> V_473 = V_474 << 16 ;
else
V_462 -> V_473 = V_475 << 16 ;
goto V_476;
}
if ( ! V_131 ) {
V_462 -> V_473 = V_477 << 16 ;
goto V_476;
}
V_18 = F_15 ( V_131 ) ;
if ( V_18 ) {
V_462 -> V_473 = V_18 ;
goto V_476;
}
if ( F_34 ( V_478 , & V_10 -> V_479 ) ||
F_34 ( V_480 , & V_10 -> V_479 ) ||
F_34 ( V_481 , & V_10 -> V_479 ) ||
F_34 ( V_482 , & V_10 -> V_479 ) ||
F_34 ( V_483 , & V_10 -> V_479 ) ||
! F_34 ( V_484 , & V_10 -> V_119 ) ||
! F_34 ( V_261 , & V_10 -> V_119 ) ||
F_34 ( V_485 , & V_10 -> V_479 ) )
goto V_486;
V_461 = F_140 ( V_10 , V_132 , V_462 ) ;
if ( ! V_461 )
goto V_486;
V_18 = F_149 ( V_10 , V_461 ) ;
if ( V_18 != V_41 )
goto V_487;
return 0 ;
V_487:
F_144 ( V_10 , V_461 ) ;
F_147 ( V_461 , V_10 -> V_463 ) ;
V_486:
return V_488 ;
V_476:
V_462 -> V_469 ( V_462 ) ;
return 0 ;
}
static void F_150 ( struct V_9 * V_10 )
{
if ( V_10 -> V_489 )
F_46 ( & V_10 -> V_194 -> V_126 , V_10 -> V_490 , V_10 -> V_489 ,
V_10 -> V_491 ) ;
V_10 -> V_490 = 0 ;
V_10 -> V_489 = NULL ;
V_10 -> V_491 = 0 ;
V_10 -> V_492 = NULL ;
V_10 -> V_493 = 0 ;
V_10 -> V_494 = NULL ;
V_10 -> V_495 = 0 ;
V_10 -> V_496 = NULL ;
V_10 -> V_497 = 0 ;
if ( V_10 -> V_463 )
F_151 ( V_10 -> V_463 ) ;
V_10 -> V_463 = NULL ;
if ( V_10 -> V_139 )
F_152 ( V_10 -> V_139 ) ;
if ( V_10 -> V_108 )
F_153 ( V_10 -> V_108 ) ;
V_10 -> V_108 = NULL ;
if ( V_10 -> V_498 )
F_152 ( V_10 -> V_498 ) ;
if ( F_8 ( V_10 ) ) {
if ( V_10 -> V_499 )
F_154 (
(struct V_500 V_501 * ) V_10 -> V_499 ) ;
} else if ( V_10 -> V_502 )
F_154 ( V_10 -> V_502 ) ;
F_155 ( V_10 -> V_194 ) ;
}
static int F_156 ( struct V_9 * V_10 )
{
unsigned long V_503 ;
V_10 -> V_490 = ( ( V_504 * V_505 ) +
( V_506 * V_505 ) +
sizeof( struct V_496 ) +
V_507 +
( V_508 - 1 ) ) & ~ ( V_508 - 1 ) ;
V_10 -> V_489 = F_42 ( & V_10 -> V_194 -> V_126 , V_10 -> V_490 ,
& V_10 -> V_491 , V_140 ) ;
if ( V_10 -> V_489 == NULL ) {
F_4 ( V_38 , V_10 ,
L_78 ) ;
goto V_509;
}
memset ( V_10 -> V_489 , 0 , V_10 -> V_490 ) ;
V_503 = 0 ;
if ( ( unsigned long ) V_10 -> V_491 & ( V_507 - 1 ) )
V_503 = V_507 - ( ( unsigned long ) V_10 -> V_491 &
( V_507 - 1 ) ) ;
V_10 -> V_493 = V_10 -> V_491 + V_503 ;
V_10 -> V_492 = (struct V_510 * ) ( V_10 -> V_489 + V_503 ) ;
V_10 -> V_495 = V_10 -> V_491 + V_503 +
( V_504 * V_505 ) ;
V_10 -> V_494 = (struct V_510 * ) ( V_10 -> V_489 + V_503 +
( V_504 *
V_505 ) ) ;
V_10 -> V_497 = V_10 -> V_491 + V_503 +
( V_504 * V_505 ) +
( V_506 * V_505 ) ;
V_10 -> V_496 = (struct V_496 * ) ( V_10 -> V_489 + V_503 +
( V_504 *
V_505 ) +
( V_506 *
V_505 ) ) ;
V_10 -> V_463 = F_157 ( V_511 , V_512 ,
V_513 , V_514 ) ;
if ( V_10 -> V_463 == NULL ) {
F_4 ( V_38 , V_10 ,
L_79 ) ;
goto V_509;
}
V_10 -> V_139 = F_158 ( L_80 , & V_10 -> V_194 -> V_126 ,
V_515 , 8 , 0 ) ;
if ( V_10 -> V_139 == NULL ) {
F_4 ( V_38 , V_10 ,
L_81 , V_26 ) ;
goto V_509;
}
V_10 -> V_498 = F_158 ( L_82 , & V_10 -> V_194 -> V_126 ,
V_516 , 8 , 0 ) ;
if ( V_10 -> V_498 == NULL ) {
F_4 ( V_38 , V_10 ,
L_83 ,
V_26 ) ;
goto V_509;
}
return V_41 ;
V_509:
F_150 ( V_10 ) ;
return V_341 ;
}
static int F_159 ( struct V_9 * V_10 )
{
T_1 V_517 , V_518 , V_519 ;
int V_349 = V_41 ;
V_517 = F_160 ( V_10 , V_520 ) ;
V_518 = F_161 ( V_517 ) ;
V_519 = F_162 ( V_517 ) ;
if ( V_518 == V_521 ) {
F_4 ( V_38 , V_10 , L_84
L_85
L_86 , V_519 ) ;
V_349 = V_341 ;
} else if ( V_518 == V_522 ) {
if ( V_10 -> V_523 == V_524 )
F_4 ( V_38 , V_10 , L_87
L_88
L_89 , V_519 ) ;
} else {
if ( V_10 -> V_523 == V_522 )
F_4 ( V_25 , V_10 , L_90
L_91 ,
V_519 ) ;
}
V_10 -> V_523 = V_518 ;
return V_349 ;
}
static int F_163 ( struct V_9 * V_10 )
{
T_1 V_525 ;
int V_349 = V_41 ;
V_525 = F_160 ( V_10 , V_526 ) ;
if ( V_525 == 0xffffffff ) {
F_3 ( F_28 ( V_38 L_92
L_93 ,
V_10 -> V_447 , V_26 ) ) ;
return V_349 ;
}
if ( V_10 -> V_525 == V_525 ) {
V_10 -> V_527 ++ ;
if ( V_10 -> V_527 == 2 ) {
V_10 -> V_527 = 0 ;
F_4 ( V_25 , V_10 ,
L_94
L_95
L_96
L_97
L_98 ,
V_10 -> V_447 , V_26 ,
F_160 ( V_10 ,
V_528 ) ,
F_160 ( V_10 ,
V_529 ) ,
F_160 ( V_10 , V_530 +
0x3c ) ,
F_160 ( V_10 , V_531 +
0x3c ) ,
F_160 ( V_10 , V_532 +
0x3c ) ,
F_160 ( V_10 , V_533 +
0x3c ) ,
F_160 ( V_10 , V_534 +
0x3c ) ) ;
V_349 = V_341 ;
}
} else
V_10 -> V_527 = 0 ;
V_10 -> V_525 = V_525 ;
return V_349 ;
}
void F_164 ( struct V_9 * V_10 )
{
T_1 V_535 , V_536 ;
if ( ! ( F_34 ( V_480 , & V_10 -> V_479 ) ||
F_34 ( V_481 , & V_10 -> V_479 ) ||
F_34 ( V_537 , & V_10 -> V_479 ) ) ) {
V_535 = F_160 ( V_10 , V_538 ) ;
if ( F_159 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_99
L_100 ) ;
F_165 ( V_10 , V_539 + 0x98 ,
V_540 |
V_541 ) ;
F_166 ( V_482 , & V_10 -> V_479 ) ;
F_167 ( V_10 ) ;
} else if ( V_535 == V_542 &&
! F_34 ( V_481 , & V_10 -> V_479 ) ) {
if ( ! V_543 ) {
F_4 ( V_25 , V_10 , L_101
L_102 , V_26 ) ;
F_166 ( V_481 , & V_10 -> V_479 ) ;
F_167 ( V_10 ) ;
}
} else if ( V_535 == V_544 &&
! F_34 ( V_483 , & V_10 -> V_479 ) ) {
F_4 ( V_25 , V_10 , L_103 ,
V_26 ) ;
F_166 ( V_483 , & V_10 -> V_479 ) ;
F_167 ( V_10 ) ;
} else {
if ( F_163 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_99
L_100 ) ;
F_165 ( V_10 , V_539 + 0x98 ,
V_540 |
V_541 ) ;
V_536 = F_160 ( V_10 ,
V_528 ) ;
if ( F_168 ( V_536 ) == 0x67 )
F_4 ( V_147 , V_10 , L_104
L_105
L_106
L_107 ,
V_26 ) ;
if ( V_536 & V_545 )
F_166 ( V_482 ,
& V_10 -> V_479 ) ;
else {
F_4 ( V_25 , V_10 , L_108
L_109 , V_26 ) ;
F_166 ( V_481 , & V_10 -> V_479 ) ;
}
F_169 ( V_10 ) ;
F_167 ( V_10 ) ;
}
}
}
}
static void F_170 ( struct V_128 * V_190 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! ( V_132 -> V_361 == V_362 ) )
return;
if ( F_33 ( V_10 ) && ! F_34 ( V_546 , & V_132 -> V_119 ) &&
! F_171 ( V_190 ) ) {
if ( F_172 ( & V_132 -> V_547 ) !=
V_548 ) {
if ( F_172 ( & V_132 -> V_547 ) ==
0 ) {
F_173 ( & V_132 -> V_547 ,
V_548 ) ;
F_166 ( V_549 , & V_10 -> V_479 ) ;
F_166 ( V_546 , & V_132 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_110 ,
V_26 , V_132 -> V_196 ) ) ;
} else
F_174 ( & V_132 -> V_547 ) ;
}
}
if ( F_172 ( & V_132 -> V_550 ) &&
( F_175 ( & V_132 -> V_550 ) != 0 ) ) {
if ( ! F_171 ( V_190 ) ) {
F_176 ( & V_132 -> V_551 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_111
L_112 , V_26 ,
V_132 -> V_196 ,
F_172 ( & V_132 -> V_551 ) ,
V_132 -> V_452 + 4 ) ) ;
F_166 ( V_549 , & V_10 -> V_479 ) ;
F_173 ( & V_132 -> V_547 ,
V_132 -> V_452 + 4 ) ;
}
}
}
static void F_177 ( struct V_9 * V_10 )
{
int V_552 = 0 ;
T_4 V_553 ;
F_139 ( V_10 -> V_180 , F_170 ) ;
if ( F_34 ( V_471 , & V_10 -> V_119 ) ) {
F_178 ( & V_10 -> V_456 , V_458 + V_326 ) ;
return;
}
if ( ! F_179 ( V_10 -> V_194 ) )
F_180 ( V_10 -> V_194 , V_554 , & V_553 ) ;
if ( F_8 ( V_10 ) ) {
F_164 ( V_10 ) ;
}
if ( ! F_8 ( V_10 ) ) {
if ( V_10 -> V_555 & V_556 &&
V_10 -> V_557 != 0 ) {
V_10 -> V_527 ++ ;
if ( V_10 -> V_527 >
V_10 -> V_557 + 2 )
F_166 ( V_481 , & V_10 -> V_479 ) ;
}
}
if ( ! F_181 ( & V_10 -> V_558 ) )
V_552 ++ ;
if ( V_552 ||
F_34 ( V_481 , & V_10 -> V_479 ) ||
F_34 ( V_537 , & V_10 -> V_479 ) ||
F_34 ( V_549 , & V_10 -> V_479 ) ||
F_34 ( V_485 , & V_10 -> V_479 ) ||
F_34 ( V_478 , & V_10 -> V_479 ) ||
F_34 ( V_559 , & V_10 -> V_479 ) ||
F_34 ( V_560 , & V_10 -> V_479 ) ||
F_34 ( V_482 , & V_10 -> V_479 ) ||
F_34 ( V_483 , & V_10 -> V_479 ) ||
F_34 ( V_561 , & V_10 -> V_479 ) ) {
F_3 ( F_28 ( L_113
L_114 ,
V_10 -> V_447 , V_26 , V_10 -> V_479 ) ) ;
F_167 ( V_10 ) ;
}
F_178 ( & V_10 -> V_456 , V_458 + V_326 ) ;
F_3 ( V_10 -> V_562 ++ ) ;
}
static int F_182 ( struct V_9 * V_10 )
{
T_1 V_563 = 0 ;
unsigned long V_119 ;
struct V_237 * V_462 ;
unsigned long V_564 = V_458 + ( V_565 * V_326 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_115
L_116 , V_565 ) ) ;
while ( ! F_183 ( V_458 , V_564 ) ) {
F_50 ( & V_10 -> V_377 , V_119 ) ;
for ( V_563 = 0 ; V_563 < V_10 -> V_180 -> V_566 ; V_563 ++ ) {
V_462 = F_184 ( V_10 -> V_180 , V_563 ) ;
if ( V_462 != NULL && F_143 ( V_462 ) )
break;
}
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( V_563 == V_10 -> V_180 -> V_566 )
return V_41 ;
F_185 ( 1000 ) ;
}
return V_341 ;
}
int F_186 ( struct V_9 * V_10 )
{
T_1 V_567 ;
unsigned long V_119 = 0 ;
F_3 ( F_28 ( V_147 L_117 , V_10 -> V_447 , V_26 ) ) ;
if ( F_187 ( V_10 ) != V_41 )
return V_341 ;
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_567 = F_188 ( & V_10 -> V_502 -> V_567 ) ;
if ( ( V_567 & V_568 ) != 0 )
F_189 ( F_190 ( V_568 ) , & V_10 -> V_502 -> V_567 ) ;
F_189 ( F_190 ( V_569 ) , & V_10 -> V_502 -> V_567 ) ;
F_191 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
return V_41 ;
}
int F_192 ( struct V_9 * V_10 )
{
T_1 V_570 ;
unsigned long V_119 = 0 ;
int V_349 ;
T_1 V_567 ;
V_349 = F_186 ( V_10 ) ;
if ( V_349 != V_41 )
return V_349 ;
V_349 = V_341 ;
V_570 = V_571 ;
do {
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_567 = F_188 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( ( V_567 & V_572 ) == 0 )
break;
F_185 ( 1000 ) ;
} while ( ( -- V_570 ) );
if ( ( V_567 & V_572 ) != 0 ) {
F_3 ( F_28 ( V_38
L_118
L_119 ,
V_10 -> V_447 ) ) ;
F_50 ( & V_10 -> V_377 , V_119 ) ;
F_189 ( F_190 ( V_572 ) , & V_10 -> V_502 -> V_567 ) ;
F_191 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
}
V_570 = V_573 ;
do {
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_567 = F_188 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( ( V_567 & V_569 ) == 0 ) {
V_349 = V_41 ;
break;
}
F_185 ( 1000 ) ;
} while ( ( -- V_570 ) );
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_567 = F_188 ( & V_10 -> V_502 -> V_567 ) ;
if ( ( V_567 & V_568 ) != 0 ) {
F_189 ( F_190 ( V_568 ) , & V_10 -> V_502 -> V_567 ) ;
F_191 ( & V_10 -> V_502 -> V_567 ) ;
}
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( V_570 == 0 ) {
F_50 ( & V_10 -> V_377 , V_119 ) ;
F_189 ( F_190 ( V_574 ) , & V_10 -> V_502 -> V_567 ) ;
F_191 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
V_570 = V_573 ;
do {
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_567 = F_188 ( & V_10 -> V_502 -> V_567 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( ( V_567 & V_574 ) == 0 ) {
V_349 = V_41 ;
break;
}
F_185 ( 1000 ) ;
} while ( ( -- V_570 ) );
}
return V_349 ;
}
static void F_193 ( struct V_9 * V_10 , int V_575 )
{
struct V_461 * V_461 ;
int V_101 ;
unsigned long V_119 ;
F_50 ( & V_10 -> V_377 , V_119 ) ;
for ( V_101 = 0 ; V_101 < V_10 -> V_180 -> V_566 ; V_101 ++ ) {
V_461 = F_194 ( V_10 , V_101 ) ;
if ( V_461 != NULL ) {
V_461 -> V_462 -> V_473 = V_575 ;
F_195 ( & V_461 -> V_464 , F_146 ) ;
}
}
F_51 ( & V_10 -> V_377 , V_119 ) ;
}
void F_196 ( struct V_9 * V_10 )
{
F_197 ( V_484 , & V_10 -> V_119 ) ;
F_4 ( V_25 , V_10 , L_120 ) ;
F_193 ( V_10 , V_474 << 16 ) ;
F_138 ( V_10 ) ;
F_197 ( V_576 , & V_10 -> V_119 ) ;
}
static void F_198 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_367 = V_577 ;
if ( V_132 -> V_361 == V_362 )
F_137 ( V_132 -> V_131 ) ;
else
F_199 ( V_129 -> V_134 ,
V_578 ) ;
}
static int F_200 ( struct V_9 * V_10 )
{
int V_349 = V_341 ;
T_2 V_579 = 0 ;
T_1 V_535 ;
unsigned long V_580 ;
F_201 ( V_10 -> V_180 ) ;
F_197 ( V_484 , & V_10 -> V_119 ) ;
F_197 ( V_261 , & V_10 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_121 , V_26 ) ) ;
F_166 ( V_480 , & V_10 -> V_479 ) ;
F_139 ( V_10 -> V_180 , F_198 ) ;
if ( F_34 ( V_481 , & V_10 -> V_479 ) )
V_579 = 1 ;
if ( F_34 ( V_478 , & V_10 -> V_479 ) ) {
V_349 = V_41 ;
goto V_581;
}
if ( F_8 ( V_10 ) && ! V_579 &&
F_34 ( V_485 , & V_10 -> V_479 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_122 ,
V_10 -> V_447 , V_26 ) ) ;
V_349 = V_10 -> V_582 -> V_583 ( V_10 ) ;
if ( V_349 == V_41 ) {
if ( ! F_34 ( V_584 , & V_10 -> V_119 ) )
F_182 ( V_10 ) ;
V_10 -> V_582 -> V_585 ( V_10 ) ;
F_202 ( V_10 , V_586 ) ;
F_193 ( V_10 , V_587 << 16 ) ;
} else {
V_579 = 1 ;
F_197 ( V_485 , & V_10 -> V_479 ) ;
F_166 ( V_481 , & V_10 -> V_479 ) ;
}
}
if ( ! F_8 ( V_10 ) || V_579 ) {
if ( ! F_8 ( V_10 ) )
goto V_588;
if ( F_34 ( V_584 , & V_10 -> V_119 ) )
goto V_588;
V_580 = V_458 + ( V_589 * V_326 ) ;
while ( F_203 ( V_458 , V_580 ) ) {
if ( F_163 ( V_10 ) ) {
F_169 ( V_10 ) ;
break;
}
F_204 ( V_590 ) ;
F_205 ( V_326 ) ;
}
if ( ! F_34 ( V_584 , & V_10 -> V_119 ) )
F_182 ( V_10 ) ;
V_588:
F_202 ( V_10 , V_586 ) ;
F_193 ( V_10 , V_587 << 16 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_123 ,
V_10 -> V_447 , V_26 ) ) ;
V_349 = V_10 -> V_582 -> V_579 ( V_10 ) ;
}
F_202 ( V_10 , V_586 ) ;
V_581:
if ( V_349 == V_41 ) {
if ( ! F_8 ( V_10 ) && ( V_10 -> V_591 == 3 ) )
F_206 ( 6 ) ;
V_349 = F_207 ( V_10 , V_592 ) ;
}
if ( ! F_34 ( V_484 , & V_10 -> V_119 ) &&
! F_34 ( V_478 , & V_10 -> V_479 ) ) {
if ( F_8 ( V_10 ) ) {
F_208 ( V_10 ) ;
V_535 = F_160 ( V_10 , V_538 ) ;
F_209 ( V_10 ) ;
if ( V_535 == V_593 ) {
F_4 ( V_25 , V_10 , L_124
L_125
L_126 , V_26 ) ;
F_196 ( V_10 ) ;
F_197 ( V_537 , & V_10 -> V_479 ) ;
F_197 ( V_481 , & V_10 -> V_479 ) ;
F_197 ( V_485 ,
& V_10 -> V_479 ) ;
V_349 = V_341 ;
goto V_594;
}
}
if ( ! F_34 ( V_537 , & V_10 -> V_479 ) ) {
V_10 -> V_595 = V_596 ;
F_3 ( F_28 ( L_127
L_128 , V_10 -> V_447 ,
V_10 -> V_595 ) ) ;
F_166 ( V_537 , & V_10 -> V_479 ) ;
V_349 = V_341 ;
} else {
if ( V_10 -> V_595 > 0 ) {
V_10 -> V_595 -- ;
F_3 ( F_28 ( L_129
L_130 ,
V_10 -> V_447 ,
V_10 -> V_595 ) ) ;
V_349 = V_341 ;
}
if ( V_10 -> V_595 == 0 ) {
F_3 ( F_28 ( L_131
L_132 ,
V_10 -> V_447 ) ) ;
F_196 ( V_10 ) ;
F_197 ( V_537 , & V_10 -> V_479 ) ;
F_197 ( V_481 , & V_10 -> V_479 ) ;
F_197 ( V_485 ,
& V_10 -> V_479 ) ;
V_349 = V_341 ;
}
}
} else {
F_197 ( V_481 , & V_10 -> V_479 ) ;
F_197 ( V_485 , & V_10 -> V_479 ) ;
F_197 ( V_537 , & V_10 -> V_479 ) ;
}
V_594:
V_10 -> V_597 ++ ;
if ( F_34 ( V_484 , & V_10 -> V_119 ) )
V_10 -> V_582 -> V_598 ( V_10 ) ;
F_210 ( V_10 -> V_180 ) ;
F_197 ( V_480 , & V_10 -> V_479 ) ;
F_3 ( F_28 ( L_133 , V_10 -> V_447 ,
V_349 == V_341 ? L_134 : L_135 ) ) ;
return V_349 ;
}
static void F_211 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! F_171 ( V_129 ) ) {
if ( V_132 -> V_367 == V_385 ) {
F_4 ( V_25 , V_10 , L_136
L_137 , V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ;
F_212 ( V_132 -> V_131 ) ;
} else {
if ( V_132 -> V_361 == V_362 ) {
if ( ! F_34 ( V_546 , & V_132 -> V_119 ) )
F_213 ( V_132 ) ;
} else
F_199 ( V_129 -> V_134 ,
V_578 ) ;
}
}
}
int F_214 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
F_4 ( V_25 , V_10 , L_136
L_137 , V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ;
F_212 ( V_132 -> V_131 ) ;
if ( F_34 ( V_484 , & V_10 -> V_119 ) ) {
F_4 ( V_25 , V_10 , L_136
L_138 , V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ;
F_215 ( V_10 -> V_180 , & V_132 -> V_131 -> V_599 ) ;
}
return V_41 ;
}
int V_370 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
F_4 ( V_25 , V_10 , L_136
L_139 , V_10 -> V_447 , V_26 ,
V_132 -> V_196 ) ;
F_216 ( V_132 -> V_333 ) ;
F_217 ( V_132 -> V_333 ,
V_600 ) ;
return V_41 ;
}
static void F_218 ( struct V_9 * V_10 )
{
F_139 ( V_10 -> V_180 , F_211 ) ;
}
static void F_219 ( struct V_128 * V_190 )
{
T_4 V_550 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_550 = F_220 ( V_132 -> V_449 ,
( T_4 ) V_601 ) ;
F_173 ( & V_132 -> V_550 , V_550 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_140 , V_10 -> V_447 ,
V_132 -> V_196 , V_550 ) ) ;
F_221 ( V_190 ) ;
}
static void F_222 ( struct V_128 * V_190 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! ( V_132 -> V_361 == V_362 ) )
return;
if ( F_223 ( V_546 , & V_132 -> V_119 ) &&
! F_171 ( V_190 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_141 ) ) ;
F_219 ( V_190 ) ;
}
}
void F_167 ( struct V_9 * V_10 )
{
if ( V_10 -> V_602 )
F_224 ( V_10 -> V_602 , & V_10 -> V_603 ) ;
}
static struct V_604 *
F_225 ( struct V_9 * V_10 , T_1 V_605 ,
enum V_606 type )
{
struct V_604 * V_607 ;
T_1 V_608 = sizeof( struct V_604 ) + V_605 ;
V_607 = F_226 ( V_608 , V_413 ) ;
if ( ! V_607 )
return NULL ;
F_227 ( & V_607 -> V_609 ) ;
V_607 -> type = type ;
return V_607 ;
}
static void F_228 ( struct V_9 * V_10 ,
struct V_604 * V_607 )
{
unsigned long V_119 ;
F_50 ( & V_10 -> V_610 , V_119 ) ;
F_229 ( & V_607 -> V_609 , & V_10 -> V_558 ) ;
F_51 ( & V_10 -> V_610 , V_119 ) ;
F_167 ( V_10 ) ;
}
int F_230 ( struct V_9 * V_10 ,
enum V_611 V_612 ,
T_1 V_605 , T_2 * V_127 )
{
struct V_604 * V_607 ;
V_607 = F_225 ( V_10 , V_605 , V_613 ) ;
if ( ! V_607 )
return V_341 ;
V_607 -> V_614 . V_615 . V_616 = V_612 ;
V_607 -> V_614 . V_615 . V_605 = V_605 ;
memcpy ( V_607 -> V_614 . V_615 . V_127 , V_127 , V_605 ) ;
F_228 ( V_10 , V_607 ) ;
return V_41 ;
}
int F_231 ( struct V_9 * V_10 ,
T_1 V_349 , T_1 V_6 ,
T_1 V_605 , T_2 * V_127 )
{
struct V_604 * V_607 ;
V_607 = F_225 ( V_10 , V_605 , V_617 ) ;
if ( ! V_607 )
return V_341 ;
V_607 -> V_614 . V_618 . V_349 = V_349 ;
V_607 -> V_614 . V_618 . V_6 = V_6 ;
V_607 -> V_614 . V_618 . V_605 = V_605 ;
memcpy ( V_607 -> V_614 . V_618 . V_127 , V_127 , V_605 ) ;
F_228 ( V_10 , V_607 ) ;
return V_41 ;
}
static void F_232 ( struct V_9 * V_10 )
{
struct V_604 * V_607 , * V_619 ;
unsigned long V_119 ;
F_233 ( V_620 ) ;
F_50 ( & V_10 -> V_610 , V_119 ) ;
F_234 ( & V_10 -> V_558 , & V_620 ) ;
F_51 ( & V_10 -> V_610 , V_119 ) ;
F_235 (e, tmp, &work, list) {
F_236 ( & V_607 -> V_609 ) ;
switch ( V_607 -> type ) {
case V_613 :
F_237 ( V_10 -> V_447 ,
& V_269 ,
V_607 -> V_614 . V_615 . V_616 ,
V_607 -> V_614 . V_615 . V_605 ,
V_607 -> V_614 . V_615 . V_127 ) ;
break;
case V_617 :
F_238 ( V_10 -> V_447 ,
& V_269 ,
V_607 -> V_614 . V_618 . V_349 ,
V_607 -> V_614 . V_618 . V_6 ,
V_607 -> V_614 . V_618 . V_605 ,
V_607 -> V_614 . V_618 . V_127 ) ;
break;
default:
F_4 ( V_38 , V_10 , L_142
L_143 , V_607 -> type ) ;
}
F_239 ( V_607 ) ;
}
}
static void F_240 ( struct V_389 * V_620 )
{
struct V_9 * V_10 =
F_112 ( V_620 , struct V_9 , V_603 ) ;
int V_349 = V_341 ;
F_3 (printk(L_144
L_145,
ha->host_no, __func__, ha->flags, ha->dpc_flags))
if ( ! F_34 ( V_576 , & V_10 -> V_119 ) )
return;
if ( F_34 ( V_471 , & V_10 -> V_119 ) ) {
F_3 ( F_28 ( V_25 L_146 ,
V_10 -> V_447 , V_26 , V_10 -> V_119 ) ) ;
return;
}
F_232 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_34 ( V_482 , & V_10 -> V_479 ) ) {
F_208 ( V_10 ) ;
F_165 ( V_10 , V_538 ,
V_593 ) ;
F_209 ( V_10 ) ;
F_4 ( V_25 , V_10 , L_147 ) ;
F_241 ( V_10 ) ;
}
if ( F_223 ( V_483 , & V_10 -> V_479 ) ) {
F_242 ( V_10 ) ;
}
}
if ( ! F_34 ( V_480 , & V_10 -> V_479 ) &&
( F_34 ( V_481 , & V_10 -> V_479 ) ||
F_34 ( V_478 , & V_10 -> V_479 ) ||
F_34 ( V_485 , & V_10 -> V_479 ) ) ) {
if ( V_543 ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_447 , V_26 ) ) ;
F_197 ( V_481 , & V_10 -> V_479 ) ;
F_197 ( V_478 , & V_10 -> V_479 ) ;
F_197 ( V_485 , & V_10 -> V_479 ) ;
goto V_621;
}
if ( F_34 ( V_485 , & V_10 -> V_479 ) ||
F_34 ( V_481 , & V_10 -> V_479 ) )
F_200 ( V_10 ) ;
if ( F_34 ( V_478 , & V_10 -> V_479 ) ) {
T_2 V_622 = V_571 ;
while ( ( F_188 ( & V_10 -> V_502 -> V_567 ) &
( V_569 | V_574 ) ) != 0 ) {
if ( -- V_622 == 0 )
break;
F_185 ( 1000 ) ;
}
if ( V_622 == 0 )
F_3 ( F_28 ( L_149
L_150 ,
V_10 -> V_447 , V_26 ) ) ;
F_193 ( V_10 , V_587 << 16 ) ;
if ( F_187 ( V_10 ) == V_41 ) {
F_202 ( V_10 , V_586 ) ;
V_349 = F_200 ( V_10 ) ;
}
F_197 ( V_478 , & V_10 -> V_479 ) ;
if ( V_349 == V_41 )
V_10 -> V_582 -> V_598 ( V_10 ) ;
}
}
V_621:
if ( F_223 ( V_561 , & V_10 -> V_479 ) )
F_202 ( V_10 , V_623 ) ;
if ( F_223 ( V_559 , & V_10 -> V_479 ) )
F_243 ( V_10 ) ;
if ( F_33 ( V_10 ) &&
F_223 ( V_549 , & V_10 -> V_479 ) ) {
F_139 ( V_10 -> V_180 , F_222 ) ;
}
if ( F_223 ( V_560 , & V_10 -> V_479 ) ) {
if ( ! F_34 ( V_261 , & V_10 -> V_119 ) ) {
F_138 ( V_10 ) ;
} else {
if ( F_223 ( V_182 , & V_10 -> V_119 ) ) {
F_244 ( V_10 , V_10 -> V_624 ) ;
F_139 ( V_10 -> V_180 ,
F_221 ) ;
} else
F_218 ( V_10 ) ;
}
}
}
static void F_245 ( struct V_9 * V_10 )
{
F_193 ( V_10 , V_474 << 16 ) ;
if ( F_34 ( V_625 , & V_10 -> V_119 ) ) {
V_10 -> V_582 -> V_585 ( V_10 ) ;
}
if ( V_10 -> V_460 )
F_134 ( V_10 ) ;
if ( V_10 -> V_602 )
F_246 ( V_10 -> V_602 ) ;
if ( V_10 -> V_626 )
F_246 ( V_10 -> V_626 ) ;
V_10 -> V_582 -> V_583 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
F_208 ( V_10 ) ;
F_247 ( V_10 ) ;
F_209 ( V_10 ) ;
}
if ( F_223 ( V_627 , & V_10 -> V_119 ) )
F_248 ( V_10 ) ;
F_150 ( V_10 ) ;
}
int F_249 ( struct V_9 * V_10 )
{
int V_349 = 0 ;
unsigned long V_628 , V_629 , V_630 , V_631 ;
struct V_632 * V_194 = V_10 -> V_194 ;
V_349 = F_250 ( V_194 , V_633 ) ;
if ( V_349 ) {
F_28 ( V_38
L_151
L_152 , V_10 -> V_447 , F_251 ( V_194 ) , V_349 ) ;
goto V_634;
}
F_3 ( F_28 ( V_25 L_153 ,
V_26 , V_194 -> V_635 ) ) ;
V_10 -> V_636 = V_194 -> V_635 ;
V_628 = F_252 ( V_194 , 0 ) ;
V_629 = F_253 ( V_194 , 0 ) ;
F_3 ( F_28 ( V_25 L_154 ,
V_26 , V_628 , V_629 ) ) ;
V_10 -> V_499 = ( unsigned long ) F_254 ( V_628 , V_629 ) ;
if ( ! V_10 -> V_499 ) {
F_28 ( V_147
L_155 , F_251 ( V_194 ) ) ;
F_155 ( V_10 -> V_194 ) ;
goto V_634;
}
V_10 -> V_637 =
(struct V_500 V_501 * ) ( ( T_2 * ) V_10 -> V_499 +
0xbc000 + ( V_10 -> V_194 -> V_638 << 11 ) ) ;
V_630 = F_252 ( V_194 , 4 ) ;
V_631 = F_253 ( V_194 , 4 ) ;
V_10 -> V_639 = ( V_10 -> V_194 -> V_638 == 4 ? V_640 :
V_641 ) ;
return 0 ;
V_634:
return - V_105 ;
}
int F_255 ( struct V_9 * V_10 )
{
unsigned long V_642 , V_643 , V_644 ;
unsigned long V_645 , V_646 , V_647 ;
V_642 = F_252 ( V_10 -> V_194 , 0 ) ;
V_643 = F_253 ( V_10 -> V_194 , 0 ) ;
V_644 = F_256 ( V_10 -> V_194 , 0 ) ;
if ( V_644 & V_648 ) {
if ( V_643 < V_649 ) {
F_4 ( V_38 , V_10 ,
L_156 ) ;
V_642 = 0 ;
}
} else {
F_4 ( V_38 , V_10 , L_157 ) ;
V_642 = 0 ;
}
V_645 = F_252 ( V_10 -> V_194 , 1 ) ;
V_646 = F_253 ( V_10 -> V_194 , 1 ) ;
V_647 = F_256 ( V_10 -> V_194 , 1 ) ;
if ( ! ( V_647 & V_650 ) ) {
F_4 ( V_147 , V_10 ,
L_158 ) ;
goto V_634;
}
if ( V_646 < V_649 ) {
F_4 ( V_147 , V_10 ,
L_159 ) ;
goto V_634;
}
if ( F_250 ( V_10 -> V_194 , V_633 ) ) {
F_4 ( V_38 , V_10 ,
L_160 ) ;
goto V_634;
}
V_10 -> V_651 = V_642 ;
V_10 -> V_652 = V_643 ;
V_10 -> V_502 = F_254 ( V_645 , V_649 ) ;
if ( ! V_10 -> V_502 ) {
F_4 ( V_147 , V_10 ,
L_161 ) ;
goto V_634;
}
return 0 ;
V_634:
return - V_105 ;
}
T_4 F_257 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_496 -> V_653 ) ;
}
T_4 F_258 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_191 ( & V_10 -> V_637 -> V_653 ) ) ;
}
T_4 F_259 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_496 -> V_654 ) ;
}
T_4 F_260 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_191 ( & V_10 -> V_637 -> V_654 ) ) ;
}
static T_8 F_261 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
char * V_655 = V_93 ;
int V_656 ;
switch ( type ) {
case V_657 :
V_656 = sprintf ( V_655 , L_25 , V_658 ) ;
break;
case V_659 :
V_656 = sprintf ( V_655 , L_162 ) ;
break;
case V_660 :
V_656 = F_56 ( V_655 , V_10 -> V_265 ,
V_266 ) ;
break;
default:
V_656 = - V_39 ;
break;
}
return V_656 ;
}
static T_3 F_262 ( void * V_127 , int type )
{
int V_656 ;
switch ( type ) {
case V_657 :
case V_660 :
case V_659 :
V_656 = V_54 ;
break;
default:
V_656 = 0 ;
break;
}
return V_656 ;
}
static T_8 F_263 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
char * V_655 = V_93 ;
int V_656 ;
switch ( type ) {
case V_661 :
V_656 = sprintf ( V_655 , L_17 , V_10 -> V_267 ) ;
break;
default:
V_656 = - V_39 ;
break;
}
return V_656 ;
}
static T_3 F_264 ( void * V_127 , int type )
{
int V_656 ;
switch ( type ) {
case V_661 :
V_656 = V_54 ;
break;
default:
V_656 = 0 ;
break;
}
return V_656 ;
}
static T_8
F_265 ( struct V_662 * V_663 , int type ,
char * V_93 )
{
struct V_664 * V_665 = & V_663 -> V_666 [ 0 ] ;
char * V_655 = V_93 ;
int V_656 ;
switch ( type ) {
case V_667 :
V_656 = sprintf ( V_93 , L_17 , ( char * ) & V_663 -> V_668 ) ;
break;
case V_669 :
if ( V_663 -> V_666 [ 0 ] . V_670 . V_671 == 0x1 )
V_656 = sprintf ( V_93 , L_16 ,
& V_665 -> V_670 . V_28 ) ;
else
V_656 = sprintf ( V_655 , L_22 ,
& V_665 -> V_670 . V_28 ) ;
break;
case V_672 :
V_656 = sprintf ( V_655 , L_25 , V_665 -> V_673 ) ;
break;
case V_674 :
V_656 = sprintf ( V_655 , L_163 ,
V_665 -> V_675 . V_676 ,
( char * ) & V_665 -> V_675 . V_677 ) ;
break;
case V_678 :
V_656 = sprintf ( V_655 , L_163 ,
V_665 -> V_675 . V_679 ,
( char * ) & V_665 -> V_675 . V_680 ) ;
break;
case V_681 :
V_656 = sprintf ( V_655 , L_163 ,
V_665 -> V_675 . V_682 ,
( char * ) & V_665 -> V_675 . V_683 ) ;
break;
case V_684 :
V_656 = sprintf ( V_655 , L_163 ,
V_665 -> V_675 . V_685 ,
( char * ) & V_665 -> V_675 . V_686 ) ;
break;
case V_687 :
V_656 = sprintf ( V_655 , L_25 , V_658 ) ;
break;
case V_688 :
V_656 = sprintf ( V_655 , L_162 ) ;
break;
default:
V_656 = - V_39 ;
break;
}
return V_656 ;
}
static T_8 F_266 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
struct V_662 * V_663 = & ( V_10 -> V_689 . V_690 ) ;
return F_265 ( V_663 , type , V_93 ) ;
}
static T_8 F_267 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
struct V_662 * V_663 = & ( V_10 -> V_689 . V_691 ) ;
return F_265 ( V_663 , type , V_93 ) ;
}
static T_3 F_268 ( void * V_127 , int type )
{
int V_656 ;
switch ( type ) {
case V_667 :
case V_669 :
case V_672 :
case V_674 :
case V_678 :
case V_681 :
case V_684 :
case V_688 :
case V_687 :
V_656 = V_54 ;
break;
default:
V_656 = 0 ;
break;
}
return V_656 ;
}
static void F_269 ( void * V_127 )
{
struct V_9 * V_10 = V_127 ;
F_270 ( V_10 -> V_180 ) ;
}
static int F_271 ( struct V_9 * V_10 , T_4 V_335 [] )
{
T_5 V_692 ;
T_1 V_12 , V_693 , V_694 ;
T_1 V_137 ;
T_4 V_695 ;
T_2 V_696 ;
T_2 * V_93 = NULL ;
T_9 V_608 = 13 * sizeof( T_2 ) ;
int V_100 = V_41 ;
V_695 = F_272 ( V_10 -> V_194 -> V_638 ) ;
F_4 ( V_25 , V_10 , L_164 ,
V_26 , V_10 -> V_194 -> V_125 , V_695 ) ;
if ( F_20 ( V_10 ) ) {
if ( V_695 == 1 ) {
V_12 = V_697 ;
V_693 = V_698 ;
V_694 = V_699 ;
} else if ( V_695 == 3 ) {
V_12 = V_700 ;
V_693 = V_701 ;
V_694 = V_702 ;
} else {
V_100 = V_341 ;
goto V_703;
}
V_696 = F_273 ( V_10 , V_12 ) ;
if ( ! ( V_696 & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_165
L_166 , V_26 , V_696 ) ) ;
V_100 = V_341 ;
goto V_703;
}
V_696 = F_273 ( V_10 , V_693 ) ;
if ( V_696 & V_120 )
V_335 [ 0 ] = ( V_696 & 0x7f ) ;
V_696 = F_273 ( V_10 , V_694 ) ;
if ( V_696 & V_120 )
V_335 [ 1 ] = ( V_696 & 0x7f ) ;
} else if ( F_8 ( V_10 ) ) {
V_93 = F_42 ( & V_10 -> V_194 -> V_126 , V_608 ,
& V_692 , V_140 ) ;
if ( ! V_93 ) {
F_3 ( F_4 ( V_147 , V_10 ,
L_64 ,
V_26 ) ) ;
V_100 = V_341 ;
goto V_703;
}
if ( V_10 -> V_146 == 0 )
V_137 = V_704 ;
else if ( V_10 -> V_146 == 1 )
V_137 = V_705 ;
else {
V_100 = V_341 ;
goto V_706;
}
V_12 = V_144 + ( V_10 -> V_102 . V_707 * 4 ) +
V_137 ;
if ( F_21 ( V_10 , V_692 , V_12 ,
13 * sizeof( T_2 ) ) != V_41 ) {
F_3 ( F_4 ( V_147 , V_10 , L_167
L_168 , V_10 -> V_447 , V_26 ) ) ;
V_100 = V_341 ;
goto V_706;
}
if ( ! ( V_93 [ 1 ] & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_169
L_170 , V_93 [ 1 ] ) ) ;
V_100 = V_341 ;
goto V_706;
}
if ( V_93 [ 2 ] & V_120 )
V_335 [ 0 ] = V_93 [ 2 ] & 0x7f ;
if ( V_93 [ 11 ] & V_120 )
V_335 [ 1 ] = V_93 [ 11 ] & 0x7f ;
} else {
V_100 = V_341 ;
goto V_703;
}
F_3 ( F_4 ( V_25 , V_10 , L_171
L_172 , V_26 , V_335 [ 0 ] ,
V_335 [ 1 ] ) ) ;
V_706:
F_46 ( & V_10 -> V_194 -> V_126 , V_608 , V_93 , V_692 ) ;
V_703:
V_10 -> V_708 = V_335 [ 0 ] ;
V_10 -> V_709 = V_335 [ 1 ] ;
return V_100 ;
}
static int F_274 ( struct V_9 * V_10 , char * V_111 ,
char * V_114 )
{
int V_101 , V_100 = - V_29 ;
int V_98 = 0 ;
struct V_94 * V_95 ;
if ( F_8 ( V_10 ) )
V_98 = ( V_10 -> V_102 . V_103 / 2 ) /
sizeof( struct V_94 ) ;
else
V_98 = V_104 ;
if ( ! V_10 -> V_108 ) {
F_4 ( V_147 , V_10 , L_173 ) ;
return V_100 ;
}
F_9 ( & V_10 -> V_107 ) ;
for ( V_101 = 0 ; V_101 < V_98 ; V_101 ++ ) {
V_95 = (struct V_94 * ) V_10 -> V_108 + V_101 ;
if ( V_95 -> V_109 !=
F_10 ( V_110 ) ) {
continue;
}
if ( V_95 -> V_119 & V_120 )
continue;
if ( ! ( V_95 -> V_119 & V_123 ) )
continue;
strncpy ( V_114 , V_95 -> V_115 , V_116 ) ;
strncpy ( V_111 , V_95 -> V_112 , V_710 ) ;
V_100 = 0 ;
break;
}
F_11 ( & V_10 -> V_107 ) ;
return V_100 ;
}
static int F_275 ( struct V_9 * V_10 ,
struct V_662 * V_663 ,
T_4 V_335 )
{
struct V_664 * V_665 = & V_663 -> V_666 [ 0 ] ;
struct V_381 * V_350 ;
T_5 V_382 ;
T_4 V_327 ;
T_4 V_15 ;
int V_100 = V_41 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_382 , V_140 ) ;
if ( ! V_350 ) {
F_3 ( F_4 ( V_147 , V_10 ,
L_174 ,
V_26 ) ) ;
V_100 = V_341 ;
return V_100 ;
}
if ( F_276 ( V_10 , V_350 ,
V_382 , V_335 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_175
L_176 , V_26 , V_335 ) ) ;
V_100 = V_341 ;
goto V_711;
}
memcpy ( V_663 -> V_668 , V_350 -> V_442 ,
F_129 ( sizeof( V_663 -> V_668 ) ,
sizeof( V_350 -> V_442 ) ) ) ;
V_15 = F_124 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 ) {
memcpy ( & V_665 -> V_670 . V_28 ,
& V_350 -> V_419 [ 0 ] , V_17 ) ;
} else {
V_665 -> V_670 . V_671 = 0x1 ;
memcpy ( & V_665 -> V_670 . V_28 ,
& V_350 -> V_419 [ 0 ] , V_24 ) ;
}
V_665 -> V_673 = F_124 ( V_350 -> V_439 ) ;
V_327 = F_22 ( V_350 -> V_91 ) ;
if ( V_120 & F_124 ( V_350 -> V_426 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_177 ) ) ;
V_100 = F_277 ( V_10 , ( char * ) & V_665 -> V_675 .
V_677 ,
( char * ) & V_665 -> V_675 . V_680 ,
V_327 ) ;
if ( V_100 ) {
F_4 ( V_147 , V_10 , L_178 ) ;
V_100 = V_341 ;
goto V_711;
}
V_665 -> V_675 . V_676 = V_710 ;
V_665 -> V_675 . V_679 = V_116 ;
}
if ( V_712 & F_124 ( V_350 -> V_426 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_179 ) ) ;
V_100 = F_274 ( V_10 ,
( char * ) & V_665 -> V_675 . V_683 ,
( char * ) & V_665 -> V_675 . V_686 ) ;
if ( V_100 ) {
F_4 ( V_147 , V_10 , L_180 ) ;
V_100 = V_341 ;
goto V_711;
}
V_665 -> V_675 . V_682 = V_710 ;
V_665 -> V_675 . V_685 = V_116 ;
}
V_711:
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_382 ) ;
return V_100 ;
}
static int F_278 ( struct V_9 * V_10 )
{
T_4 V_335 [ 2 ] ;
int V_100 = V_341 ;
int V_18 ;
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
V_335 [ 0 ] = 0xffff ;
V_335 [ 1 ] = 0xffff ;
V_100 = F_271 ( V_10 , V_335 ) ;
if ( V_100 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_181 , V_26 ) ) ;
return V_100 ;
}
if ( V_713 )
return V_41 ;
if ( V_335 [ 0 ] == 0xffff )
goto V_714;
V_18 = F_275 ( V_10 , & ( V_10 -> V_689 . V_690 ) ,
V_335 [ 0 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_182
L_183 , V_26 ) ) ;
} else
V_100 = V_41 ;
V_714:
if ( V_335 [ 1 ] == 0xffff )
goto V_715;
V_18 = F_275 ( V_10 , & ( V_10 -> V_689 . V_691 ) ,
V_335 [ 1 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_184
L_185 , V_26 ) ) ;
} else
V_100 = V_41 ;
V_715:
return V_100 ;
}
static int F_279 ( struct V_9 * V_10 )
{
struct V_716 * V_717 ;
if ( F_278 ( V_10 ) != V_41 )
return V_341 ;
if ( V_713 ) {
F_4 ( V_25 , V_10 ,
L_186
L_187 , V_26 ) ;
return V_41 ;
}
V_10 -> V_718 = F_280 ( V_10 -> V_180 -> V_447 ) ;
if ( ! V_10 -> V_718 )
goto V_719;
if ( ! F_281 ( V_10 -> V_180 ) )
goto V_719;
V_717 = F_282 ( V_10 -> V_718 , 0 , V_10 ,
F_266 ,
F_268 ,
F_269 ) ;
if ( ! V_717 )
goto V_720;
if ( ! F_281 ( V_10 -> V_180 ) )
goto V_719;
V_717 = F_282 ( V_10 -> V_718 , 1 , V_10 ,
F_267 ,
F_268 ,
F_269 ) ;
if ( ! V_717 )
goto V_720;
if ( ! F_281 ( V_10 -> V_180 ) )
goto V_719;
V_717 = F_283 ( V_10 -> V_718 , 0 , V_10 ,
F_263 ,
F_264 ,
F_269 ) ;
if ( ! V_717 )
goto V_720;
if ( ! F_281 ( V_10 -> V_180 ) )
goto V_719;
V_717 = F_284 ( V_10 -> V_718 , 0 , V_10 ,
F_261 ,
F_262 ,
F_269 ) ;
if ( ! V_717 )
goto V_720;
return V_41 ;
V_720:
F_270 ( V_10 -> V_180 ) ;
V_719:
F_285 ( V_10 -> V_718 ) ;
return - V_105 ;
}
static void F_286 ( struct V_9 * V_10 )
{
int V_18 = 0 ;
T_2 * V_721 = NULL ;
T_1 V_137 ;
T_5 V_136 ;
T_1 V_138 = 0 ;
if ( F_20 ( V_10 ) )
V_138 = V_104 *
sizeof( struct V_94 ) ;
else
V_138 = V_10 -> V_102 . V_103 / 2 ;
V_721 = F_42 ( & V_10 -> V_194 -> V_126 , V_138 ,
& V_136 , V_140 ) ;
if ( ! V_721 ) {
F_4 ( V_147 , V_10 , L_188 ) ;
return;
}
if ( F_20 ( V_10 ) )
V_137 = V_143 ;
else {
V_137 = V_144 + ( V_10 -> V_102 . V_145 << 2 ) ;
if ( V_10 -> V_146 == 1 )
V_137 += V_138 ;
}
V_18 = F_21 ( V_10 , V_136 , V_137 , V_138 ) ;
if ( V_18 != V_41 )
goto V_722;
if ( V_10 -> V_108 == NULL )
V_10 -> V_108 = F_287 ( V_138 ) ;
if ( V_10 -> V_108 == NULL ) {
F_4 ( V_147 , V_10 , L_189 ) ;
goto V_722;
}
memcpy ( V_10 -> V_108 , V_721 , V_138 ) ;
V_722:
F_46 ( & V_10 -> V_194 -> V_126 , V_138 ,
V_721 , V_136 ) ;
}
static void F_288 ( struct V_132 * V_132 ,
struct V_723 * V_724 )
{
struct V_9 * V_10 ;
struct V_128 * V_190 ;
struct V_186 * V_187 ;
struct V_130 * V_131 ;
struct V_332 * V_333 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_10 = V_132 -> V_10 ;
V_190 = V_132 -> V_131 ;
V_131 = V_190 -> V_134 ;
V_187 = V_132 -> V_333 ;
V_333 = V_187 -> V_134 ;
V_724 -> V_440 = V_131 -> V_440 ;
V_724 -> V_439 = V_333 -> V_358 ;
strncpy ( V_724 -> V_442 , V_131 -> V_356 , V_725 ) ;
strncpy ( V_724 -> V_419 , V_333 -> V_357 , V_348 ) ;
}
static void F_289 ( struct V_381 * V_350 ,
struct V_723 * V_724 )
{
T_4 V_15 = 0 ;
V_724 -> V_440 = F_45 ( V_350 -> V_441 ) ;
memcpy ( & V_724 -> V_442 [ 0 ] , & V_350 -> V_442 [ 0 ] ,
F_129 ( sizeof( V_724 -> V_442 ) , sizeof( V_350 -> V_442 ) ) ) ;
V_15 = F_124 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 )
sprintf ( V_724 -> V_419 , L_56 , V_350 -> V_419 ) ;
else
sprintf ( V_724 -> V_419 , L_57 , V_350 -> V_419 ) ;
V_724 -> V_439 = F_124 ( V_350 -> V_439 ) ;
memcpy ( & V_724 -> V_726 [ 0 ] , & V_350 -> V_726 [ 0 ] , sizeof( V_724 -> V_726 ) ) ;
}
static int F_290 ( struct V_9 * V_10 ,
struct V_723 * V_727 ,
struct V_723 * V_728 ,
T_2 V_729 )
{
if ( strcmp ( V_727 -> V_442 , V_728 -> V_442 ) )
return V_341 ;
if ( strcmp ( V_727 -> V_419 , V_728 -> V_419 ) )
return V_341 ;
if ( V_727 -> V_439 != V_728 -> V_439 )
return V_341 ;
if ( V_729 ) {
F_3 ( F_4 ( V_25 , V_10 , L_190
L_191 ,
V_26 , V_727 -> V_726 [ 5 ] , V_727 -> V_726 [ 4 ] ,
V_727 -> V_726 [ 3 ] , V_727 -> V_726 [ 2 ] , V_727 -> V_726 [ 1 ] ,
V_727 -> V_726 [ 0 ] , V_728 -> V_726 [ 5 ] , V_728 -> V_726 [ 4 ] ,
V_728 -> V_726 [ 3 ] , V_728 -> V_726 [ 2 ] , V_728 -> V_726 [ 1 ] ,
V_728 -> V_726 [ 0 ] ) ) ;
if ( memcmp ( & V_727 -> V_726 [ 0 ] , & V_728 -> V_726 [ 0 ] ,
sizeof( V_727 -> V_726 ) ) )
return V_341 ;
}
F_3 ( F_4 ( V_25 , V_10 ,
L_192 ,
V_727 -> V_439 , V_727 -> V_440 , V_727 -> V_419 ,
V_727 -> V_442 , V_728 -> V_439 , V_728 -> V_440 ,
V_728 -> V_419 , V_728 -> V_442 ) ) ;
return V_41 ;
}
static int F_291 ( struct V_9 * V_10 ,
struct V_381 * V_350 )
{
struct V_132 * V_132 ;
struct V_723 * V_730 = NULL ;
struct V_723 * V_731 = NULL ;
int V_327 ;
int V_100 = V_341 ;
V_730 = F_292 ( sizeof( * V_730 ) ) ;
if ( ! V_730 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_732;
}
V_731 = F_292 ( sizeof( * V_731 ) ) ;
if ( ! V_731 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_732;
}
F_289 ( V_350 , V_730 ) ;
for ( V_327 = 0 ; V_327 < V_340 ; V_327 ++ ) {
V_132 = F_94 ( V_10 , V_327 ) ;
if ( V_132 == NULL )
continue;
F_288 ( V_132 , V_731 ) ;
if ( ! F_290 ( V_10 , V_730 , V_731 , false ) ) {
V_100 = V_41 ;
goto V_732;
}
}
V_732:
if ( V_730 )
F_153 ( V_730 ) ;
if ( V_731 )
F_153 ( V_731 ) ;
return V_100 ;
}
static int F_293 ( struct V_9 * V_10 ,
struct V_733 * V_734 ,
struct V_381 * V_350 )
{
struct V_735 * V_736 , * V_737 ;
struct V_723 * V_730 = NULL ;
struct V_723 * V_731 = NULL ;
int V_100 = V_341 ;
V_730 = F_292 ( sizeof( * V_730 ) ) ;
if ( ! V_730 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_732;
}
V_731 = F_292 ( sizeof( * V_731 ) ) ;
if ( ! V_731 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_732;
}
F_289 ( V_350 , V_730 ) ;
F_235 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
F_289 ( & V_736 -> V_738 , V_731 ) ;
if ( ! F_290 ( V_10 , V_730 , V_731 , true ) ) {
V_100 = V_41 ;
goto V_732;
}
}
V_732:
if ( V_730 )
F_153 ( V_730 ) ;
if ( V_731 )
F_153 ( V_731 ) ;
return V_100 ;
}
static void F_294 ( struct V_733 * V_739 )
{
struct V_735 * V_740 , * V_741 ;
F_235 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
F_236 ( & V_740 -> V_609 ) ;
F_153 ( V_740 ) ;
}
}
static struct V_174 * F_295 ( struct V_9 * V_10 ,
struct V_381 * V_350 )
{
struct V_174 * V_176 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_7 * V_8 ;
char * V_742 ;
V_8 = F_287 ( sizeof( * V_8 ) ) ;
if ( ! V_8 )
return NULL ;
if ( V_350 -> V_15 & V_351 ) {
V_8 -> V_20 = V_31 ;
V_14 = (struct V_13 * ) V_8 ;
V_742 = ( char * ) & V_14 -> V_32 ;
memcpy ( V_742 , V_350 -> V_419 , V_17 ) ;
V_14 -> V_743 = F_296 ( F_124 ( V_350 -> V_439 ) ) ;
} else {
V_8 -> V_20 = V_21 ;
V_12 = (struct V_11 * ) V_8 ;
V_742 = ( char * ) & V_12 -> V_22 ;
memcpy ( V_742 , V_350 -> V_419 , V_24 ) ;
V_12 -> V_744 = F_296 ( F_124 ( V_350 -> V_439 ) ) ;
}
V_176 = F_27 ( V_10 -> V_180 , V_8 , 0 ) ;
F_153 ( V_8 ) ;
return V_176 ;
}
static int F_297 ( struct V_9 * V_10 , T_4 V_327 )
{
if ( V_713 )
return V_41 ;
if ( V_327 == V_10 -> V_708 || V_327 == V_10 -> V_709 )
return V_341 ;
return V_41 ;
}
static void F_298 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
T_4 V_450 ;
V_132 -> V_361 = V_362 ;
V_132 -> V_196 = V_548 ;
V_132 -> V_367 = V_368 ;
V_132 -> V_10 = V_10 ;
V_132 -> V_369 = F_214 ;
V_132 -> V_371 = V_745 ;
F_173 ( & V_132 -> V_547 , V_548 ) ;
F_173 ( & V_132 -> V_550 , 0 ) ;
F_173 ( & V_132 -> V_551 , 0 ) ;
V_450 = F_124 ( V_132 -> V_350 . V_450 ) ;
V_132 -> V_449 =
( V_450 > V_451 ) && ( V_450 < V_451 * 10 ) ?
V_450 : V_451 ;
V_132 -> V_452 =
F_124 ( V_132 -> V_350 . V_436 ) ;
}
static void F_299 ( struct V_9 * V_10 )
{
T_1 V_327 = 0 ;
T_1 V_746 [ V_747 ] = { 0 , 1 , 2 , 3 } ;
T_1 V_393 [ V_316 ] ;
T_1 V_748 ;
unsigned long V_564 ;
int V_100 ;
V_564 = V_458 + ( V_326 * V_749 ) ;
do {
for ( V_327 = 0 ; V_327 < V_747 ; V_327 ++ ) {
if ( V_746 [ V_327 ] == - 1 )
continue;
V_100 = F_300 ( V_10 , 0 , V_746 [ V_327 ] , V_393 ) ;
if ( V_100 == V_341 ) {
V_746 [ V_327 ] = - 1 ;
continue;
}
V_748 = ( V_393 [ 1 ] & V_750 ) >> V_751 ;
F_3 ( F_4 ( V_25 , V_10 ,
L_194 ,
V_746 [ V_327 ] , V_748 ) ) ;
if ( V_748 == V_752 ||
V_748 == V_753 ||
V_748 == V_754 ||
V_748 == V_755 ||
V_748 == V_756 )
V_746 [ V_327 ] = - 1 ;
}
if ( ( V_746 [ 0 ] == - 1 ) &&
( V_746 [ 1 ] == - 1 ) &&
( V_746 [ 2 ] == - 1 ) &&
( V_746 [ 3 ] == - 1 ) )
break;
F_301 ( V_326 ) ;
} while ( F_302 ( V_564 , V_458 ) );
}
static void F_303 ( struct V_9 * V_10 ,
struct V_733 * V_757 )
{
struct V_735 * V_758 ;
int V_353 ;
int V_759 ;
struct V_381 * V_350 ;
T_5 V_760 ;
int V_100 ;
T_1 V_327 = 0 , V_761 = 0 ;
T_1 V_242 = 0 , V_762 = 0 ;
T_4 V_763 = 0 ;
V_350 = F_19 ( V_10 -> V_498 , V_140 ,
& V_760 ) ;
if ( V_350 == NULL ) {
F_3 ( F_4 ( V_147 , V_10 , L_195 ) ) ;
goto V_764;
}
V_353 = F_20 ( V_10 ) ? V_359 :
V_360 ;
V_759 = sizeof( struct V_735 ) ;
for ( V_327 = 0 ; V_327 < V_353 ; V_327 = V_761 ) {
V_100 = F_127 ( V_10 , V_327 , V_350 , V_760 ,
NULL , & V_761 , & V_242 ,
& V_762 , NULL , & V_763 ) ;
if ( V_100 == V_341 )
break;
if ( V_242 == V_765 )
goto V_766;
if ( strlen ( ( char * ) V_350 -> V_442 ) != 0 )
goto V_766;
V_758 = F_292 ( V_759 ) ;
if ( ! V_758 )
break;
V_758 -> V_767 = V_327 ;
F_229 ( & V_758 -> V_609 , V_757 ) ;
V_766:
if ( V_761 == 0 )
break;
}
V_764:
if ( V_350 )
F_24 ( V_10 -> V_498 , V_350 , V_760 ) ;
}
static void F_304 ( struct V_9 * V_10 ,
struct V_733 * V_739 )
{
struct V_735 * V_740 , * V_741 ;
T_1 V_761 = 0 ;
T_1 V_242 = 0 , V_762 = 0 ;
int V_100 ;
F_235 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
V_100 = F_127 ( V_10 , V_740 -> V_767 ,
NULL , 0 , NULL , & V_761 , & V_242 ,
& V_762 , NULL , NULL ) ;
if ( V_100 == V_341 )
continue;
if ( V_242 == V_368 ||
V_242 == V_577 ) {
F_236 ( & V_740 -> V_609 ) ;
F_153 ( V_740 ) ;
}
}
}
static int F_305 ( struct V_9 * V_10 ,
struct V_381 * V_350 ,
int V_624 )
{
struct V_128 * V_190 ;
struct V_130 * V_131 ;
struct V_186 * V_187 ;
struct V_174 * V_176 ;
T_4 V_363 = 32 ;
T_4 V_763 = 0 ;
T_1 V_365 = 0 ;
int V_100 = V_41 ;
struct V_132 * V_132 = NULL ;
V_190 = F_96 ( & V_269 , V_10 -> V_180 ,
V_363 , sizeof( struct V_132 ) ,
sizeof( struct V_366 ) ,
V_365 , V_548 ) ;
if ( ! V_190 ) {
V_100 = V_341 ;
goto V_768;
}
F_306 ( V_269 . V_769 ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_131 = V_190 ;
V_190 -> V_373 = V_374 ;
memcpy ( & V_132 -> V_350 , V_350 ,
sizeof( struct V_381 ) ) ;
F_298 ( V_10 , V_132 ) ;
V_187 = F_102 ( V_190 , sizeof( struct V_334 ) , V_763 ) ;
if ( ! V_187 ) {
V_100 = V_341 ;
goto V_768;
}
V_132 -> V_333 = V_187 ;
V_176 = F_295 ( V_10 , V_350 ) ;
if ( V_176 ) {
V_176 -> V_333 = V_187 ;
V_187 -> V_176 = V_176 ;
} else {
F_3 ( F_4 ( V_147 , V_10 , L_196 ) ) ;
V_100 = V_341 ;
goto V_768;
}
F_123 ( V_10 , V_350 , V_190 , V_187 ) ;
if ( V_624 == V_592 ) {
F_137 ( V_190 ) ;
F_166 ( V_549 , & V_10 -> V_479 ) ;
F_166 ( V_546 , & V_132 -> V_119 ) ;
}
V_768:
return V_100 ;
}
static void F_307 ( struct V_9 * V_10 ,
struct V_733 * V_734 , int V_624 )
{
struct V_381 * V_350 ;
T_5 V_760 ;
int V_353 ;
int V_759 ;
int V_100 ;
T_1 V_327 = 0 , V_761 = 0 ;
T_1 V_242 = 0 , V_762 = 0 ;
T_4 V_763 = 0 ;
struct V_735 * V_736 ;
V_350 = F_19 ( V_10 -> V_498 , V_140 ,
& V_760 ) ;
if ( V_350 == NULL ) {
F_3 ( F_4 ( V_147 , V_10 , L_195 ) ) ;
goto V_770;
}
V_353 = F_20 ( V_10 ) ? V_359 :
V_360 ;
V_759 = sizeof( struct V_735 ) ;
for ( V_327 = 0 ; V_327 < V_353 ; V_327 = V_761 ) {
V_100 = F_127 ( V_10 , V_327 , V_350 , V_760 ,
NULL , & V_761 , & V_242 ,
& V_762 , NULL , & V_763 ) ;
if ( V_100 == V_341 )
break;
if ( F_297 ( V_10 , V_327 ) != V_41 )
goto V_771;
if ( strlen ( ( char * ) V_350 -> V_442 ) == 0 )
goto V_771;
if ( ! ( V_242 == V_368 ||
V_242 == V_577 ) )
goto V_771;
F_3 ( F_4 ( V_25 , V_10 ,
L_197 , V_327 ) ) ;
if ( V_624 == V_772 ) {
V_736 = F_287 ( V_759 ) ;
if ( ! V_736 )
break;
V_736 -> V_767 = V_327 ;
memcpy ( & V_736 -> V_738 , V_350 ,
sizeof( struct V_381 ) ) ;
if ( F_293 ( V_10 , V_734 ,
V_350 ) == V_41 ) {
F_153 ( V_736 ) ;
goto V_771;
}
F_229 ( & V_736 -> V_609 , V_734 ) ;
} else if ( V_624 == V_592 ) {
if ( F_291 ( V_10 , V_350 ) ==
V_41 )
goto V_771;
}
V_100 = F_305 ( V_10 , V_350 , V_624 ) ;
if ( V_100 == V_341 )
goto V_770;
V_771:
if ( V_761 == 0 )
break;
}
V_770:
if ( V_350 )
F_24 ( V_10 -> V_498 , V_350 , V_760 ) ;
}
void F_244 ( struct V_9 * V_10 , int V_624 )
{
T_4 V_773 = 0 ;
struct V_733 V_757 , V_734 ;
struct V_735 * V_758 , * V_774 ;
unsigned long V_564 ;
if ( ! F_34 ( V_261 , & V_10 -> V_119 ) ) {
F_166 ( V_182 , & V_10 -> V_119 ) ;
V_10 -> V_624 = V_624 ;
return;
}
F_227 ( & V_757 ) ;
F_227 ( & V_734 ) ;
F_303 ( V_10 , & V_757 ) ;
F_299 ( V_10 ) ;
F_235 (st_ddb_idx, st_ddb_idx_tmp, &list_st, list) {
F_108 ( V_10 , V_758 -> V_767 ) ;
}
V_773 = ( ( V_10 -> V_450 > V_451 ) &&
( V_10 -> V_450 < V_451 * 10 ) ?
V_10 -> V_450 : V_451 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_198 , V_773 ) ) ;
V_564 = V_458 + ( V_326 * V_773 ) ;
do {
if ( F_181 ( & V_757 ) )
break;
F_304 ( V_10 , & V_757 ) ;
F_301 ( V_326 / 10 ) ;
} while ( F_302 ( V_564 , V_458 ) );
F_294 ( & V_757 ) ;
F_307 ( V_10 , & V_734 , V_624 ) ;
F_294 ( & V_734 ) ;
F_308 ( V_10 ) ;
}
static int T_10 F_309 ( struct V_632 * V_194 ,
const struct V_775 * V_776 )
{
int V_100 = - V_777 , V_349 ;
struct V_1 * V_180 ;
struct V_9 * V_10 ;
T_2 V_778 = 0 ;
char V_93 [ 34 ] ;
struct V_779 * V_780 ;
T_1 V_535 ;
if ( F_310 ( V_194 ) )
return - 1 ;
V_180 = F_311 ( & V_781 , sizeof( * V_10 ) , 0 ) ;
if ( V_180 == NULL ) {
F_28 ( V_38
L_199 ) ;
goto V_782;
}
V_10 = F_2 ( V_180 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_194 = V_194 ;
V_10 -> V_180 = V_180 ;
V_10 -> V_447 = V_180 -> V_447 ;
F_312 ( V_194 ) ;
if ( F_8 ( V_10 ) ) {
V_10 -> V_582 = & V_783 ;
F_313 ( & V_10 -> V_784 ) ;
V_10 -> V_785 = - 1 ;
V_10 -> V_786 = - 1 ;
V_10 -> V_787 = 255 ;
V_10 -> V_695 = F_272 ( V_10 -> V_194 -> V_638 ) ;
V_780 = & V_788 [ V_10 -> V_695 ] ;
V_10 -> V_780 . V_789 = V_780 -> V_789 ;
V_10 -> V_780 . V_790 =
V_780 -> V_790 ;
V_10 -> V_780 . V_791 = V_780 -> V_791 ;
V_10 -> V_780 . V_792 = V_780 -> V_792 ;
} else {
V_10 -> V_582 = & V_793 ;
}
if ( F_8 ( V_10 ) )
V_194 -> V_794 = 1 ;
V_100 = V_10 -> V_582 -> V_795 ( V_10 ) ;
if ( V_100 )
goto V_796;
F_4 ( V_25 , V_10 , L_200 ,
V_194 -> V_125 , V_194 -> V_797 , V_10 -> V_502 ) ;
F_314 ( V_10 ) ;
F_227 ( & V_10 -> V_798 ) ;
F_315 ( & V_10 -> V_799 ) ;
F_315 ( & V_10 -> V_107 ) ;
F_316 ( & V_10 -> V_800 ) ;
F_316 ( & V_10 -> V_324 ) ;
F_317 ( & V_10 -> V_377 ) ;
F_227 ( & V_10 -> V_558 ) ;
if ( F_156 ( V_10 ) ) {
F_4 ( V_38 , V_10 ,
L_201 ) ;
V_100 = - V_105 ;
goto V_801;
}
V_180 -> V_802 = 3 ;
V_180 -> V_803 = 0 ;
V_180 -> V_804 = V_805 - 1 ;
V_180 -> V_806 = V_807 ;
V_180 -> V_808 = V_809 ;
V_180 -> V_566 = V_810 ;
V_180 -> V_811 = V_812 ;
V_100 = F_318 ( V_180 , V_810 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 ,
L_202 , V_26 ) ;
goto V_801;
}
F_319 ( V_194 , V_10 ) ;
V_100 = F_320 ( V_180 , & V_194 -> V_126 ) ;
if ( V_100 )
goto V_801;
if ( F_8 ( V_10 ) )
( void ) F_321 ( V_10 ) ;
V_349 = F_207 ( V_10 , V_772 ) ;
while ( ( ! F_34 ( V_484 , & V_10 -> V_119 ) ) &&
V_778 ++ < V_813 ) {
if ( F_8 ( V_10 ) ) {
F_208 ( V_10 ) ;
V_535 = F_160 ( V_10 , V_538 ) ;
F_209 ( V_10 ) ;
if ( V_535 == V_593 ) {
F_4 ( V_38 , V_10 , L_124
L_203 ,
V_26 ) ;
break;
}
}
F_3 ( F_28 ( L_204
L_205 , V_26 , V_778 ) ) ;
if ( V_10 -> V_582 -> V_579 ( V_10 ) == V_341 )
continue;
V_349 = F_207 ( V_10 , V_772 ) ;
}
if ( ! F_34 ( V_484 , & V_10 -> V_119 ) ) {
F_4 ( V_38 , V_10 , L_206 ) ;
if ( F_8 ( V_10 ) && V_543 ) {
F_3 ( F_28 ( V_147 L_207 ) ) ;
F_208 ( V_10 ) ;
F_165 ( V_10 , V_538 ,
V_593 ) ;
F_209 ( V_10 ) ;
}
V_100 = - V_777 ;
goto V_814;
}
F_3 ( F_28 ( L_208
L_209 , V_26 ) ) ;
sprintf ( V_93 , L_210 , V_10 -> V_447 ) ;
V_10 -> V_602 = F_322 ( V_93 ) ;
if ( ! V_10 -> V_602 ) {
F_4 ( V_38 , V_10 , L_211 ) ;
V_100 = - V_777 ;
goto V_814;
}
F_118 ( & V_10 -> V_603 , F_240 ) ;
sprintf ( V_93 , L_212 , V_10 -> V_447 ) ;
V_10 -> V_626 = F_323 ( V_93 , V_815 , 1 ) ;
if ( ! V_10 -> V_626 ) {
F_4 ( V_38 , V_10 , L_213 ) ;
V_100 = - V_777 ;
goto V_814;
}
if ( ! F_8 ( V_10 ) ) {
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_214
L_215 , V_194 -> V_797 ) ;
goto V_814;
}
}
F_325 ( V_10 -> V_194 ) ;
V_10 -> V_582 -> V_598 ( V_10 ) ;
F_130 ( V_10 , F_177 , 1 ) ;
F_166 ( V_576 , & V_10 -> V_119 ) ;
F_28 ( V_25
L_216
L_217 ,
V_816 , V_10 -> V_194 -> V_125 , F_251 ( V_10 -> V_194 ) ,
V_10 -> V_447 , V_10 -> V_817 [ 0 ] , V_10 -> V_817 [ 1 ] ,
V_10 -> V_818 , V_10 -> V_819 ) ;
if ( F_279 ( V_10 ) )
F_4 ( V_147 , V_10 ,
L_218 , V_26 ) ;
F_244 ( V_10 , V_772 ) ;
F_139 ( V_10 -> V_180 , F_221 ) ;
F_286 ( V_10 ) ;
F_62 ( V_10 ) ;
return 0 ;
V_814:
F_326 ( V_10 -> V_180 ) ;
V_801:
F_245 ( V_10 ) ;
V_796:
F_327 ( V_194 ) ;
F_270 ( V_10 -> V_180 ) ;
V_782:
F_328 ( V_194 ) ;
return V_100 ;
}
static void F_329 ( struct V_9 * V_10 )
{
struct V_9 * V_820 = NULL ;
struct V_632 * V_821 = NULL ;
int V_822 = V_823 ;
if ( F_272 ( V_10 -> V_194 -> V_638 ) & V_824 )
V_822 = V_825 ;
V_821 =
F_330 ( F_331 ( V_10 -> V_194 -> V_826 ) ,
V_10 -> V_194 -> V_826 -> V_827 , F_332 ( F_333 ( V_10 -> V_194 -> V_638 ) ,
V_822 ) ) ;
if ( V_821 ) {
if ( F_172 ( & V_821 -> V_828 ) ) {
V_820 = F_334 ( V_821 ) ;
if ( V_820 ) {
F_166 ( V_829 , & V_820 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_219
L_220 , V_26 ,
F_335 ( & V_820 -> V_194 -> V_126 ) ) ) ;
}
}
F_336 ( V_821 ) ;
}
}
static void F_337 ( struct V_9 * V_10 )
{
struct V_132 * V_132 ;
int V_15 ;
int V_327 ;
for ( V_327 = 0 ; V_327 < V_340 ; V_327 ++ ) {
V_132 = F_94 ( V_10 , V_327 ) ;
if ( ( V_132 != NULL ) &&
( V_132 -> V_361 == V_362 ) ) {
V_15 = V_388 ;
if ( F_110 ( V_10 , V_132 , V_15 )
== V_341 )
F_4 ( V_147 , V_10 , L_68 ,
V_26 ) ;
F_98 ( V_10 , V_132 -> V_196 ) ;
F_338 ( V_269 . V_769 ) ;
F_36 ( V_132 -> V_333 -> V_176 ) ;
F_99 ( V_10 , V_132 ) ;
F_100 ( V_132 -> V_131 ) ;
}
}
}
static void T_11 F_339 ( struct V_632 * V_194 )
{
struct V_9 * V_10 ;
V_10 = F_334 ( V_194 ) ;
if ( ! F_8 ( V_10 ) )
F_329 ( V_10 ) ;
F_66 ( V_10 ) ;
if ( ( ! V_713 ) && V_10 -> V_718 )
F_285 ( V_10 -> V_718 ) ;
F_337 ( V_10 ) ;
F_326 ( V_10 -> V_180 ) ;
F_245 ( V_10 ) ;
F_270 ( V_10 -> V_180 ) ;
F_327 ( V_194 ) ;
F_328 ( V_194 ) ;
F_319 ( V_194 , NULL ) ;
}
static void F_314 ( struct V_9 * V_10 )
{
int V_830 ;
if ( F_340 ( V_10 -> V_194 , F_341 ( 64 ) ) == 0 ) {
if ( F_342 ( V_10 -> V_194 , F_341 ( 64 ) ) ) {
F_343 ( & V_10 -> V_194 -> V_126 ,
L_221
L_222 ) ;
V_830 = F_342 ( V_10 -> V_194 ,
F_341 ( 32 ) ) ;
}
} else
V_830 = F_340 ( V_10 -> V_194 , F_341 ( 32 ) ) ;
}
static int F_344 ( struct V_831 * V_832 )
{
struct V_128 * V_190 ;
struct V_130 * V_131 ;
struct V_132 * V_465 ;
int V_833 = V_834 ;
V_190 = F_48 ( V_832 -> V_835 ) ;
V_131 = V_190 -> V_134 ;
V_465 = V_131 -> V_134 ;
V_832 -> V_470 = V_465 ;
V_832 -> V_836 = 1 ;
if ( V_837 != 0 && V_837 <= 0xffffU )
V_833 = V_837 ;
F_345 ( V_832 , V_833 ) ;
return 0 ;
}
static int F_346 ( struct V_831 * V_832 )
{
V_832 -> V_836 = 1 ;
return 0 ;
}
static void F_347 ( struct V_831 * V_832 )
{
F_348 ( V_832 , 1 ) ;
}
struct V_461 * F_194 ( struct V_9 * V_10 ,
T_1 V_563 )
{
struct V_461 * V_461 = NULL ;
struct V_237 * V_462 = NULL ;
V_462 = F_184 ( V_10 -> V_180 , V_563 ) ;
if ( ! V_462 )
return V_461 ;
V_461 = (struct V_461 * ) F_143 ( V_462 ) ;
if ( ! V_461 )
return V_461 ;
if ( V_461 -> V_119 & V_466 ) {
V_10 -> V_838 += V_461 -> V_839 ;
V_10 -> V_839 -= V_461 -> V_839 ;
if ( V_461 -> V_462 )
V_461 -> V_462 -> V_840 =
( unsigned char * ) ( unsigned long ) V_810 ;
}
return V_461 ;
}
static int F_349 ( struct V_9 * V_10 ,
struct V_237 * V_462 )
{
int V_841 = 0 ;
struct V_461 * V_842 ;
T_1 V_570 = V_843 ;
int V_100 = V_844 ;
if ( F_350 ( F_179 ( V_10 -> V_194 ) ) ||
( F_34 ( V_471 , & V_10 -> V_119 ) ) ) {
F_4 ( V_38 , V_10 , L_223 ,
V_10 -> V_447 , V_26 ) ;
return V_100 ;
}
do {
V_842 = (struct V_461 * ) F_143 ( V_462 ) ;
if ( V_842 == NULL ) {
V_841 ++ ;
break;
}
F_185 ( 2000 ) ;
} while ( V_570 -- );
return V_841 ;
}
static int F_351 ( struct V_9 * V_10 )
{
unsigned long V_845 ;
V_845 = V_458 + ( V_846 * V_326 ) ;
while ( F_203 ( V_458 , V_845 ) ) {
if ( F_33 ( V_10 ) )
return V_41 ;
F_185 ( 2000 ) ;
}
return V_341 ;
}
static int F_352 ( struct V_9 * V_10 ,
struct F_49 * V_847 ,
struct V_831 * V_832 )
{
int V_848 ;
int V_349 = 0 ;
struct V_237 * V_462 ;
for ( V_848 = 0 ; V_848 < V_10 -> V_180 -> V_566 ; V_848 ++ ) {
V_462 = F_184 ( V_10 -> V_180 , V_848 ) ;
if ( V_462 && V_847 == F_49 ( V_462 -> V_125 ) &&
( ! V_832 || V_832 == V_462 -> V_125 ) ) {
if ( ! F_349 ( V_10 , V_462 ) ) {
V_349 ++ ;
break;
}
}
}
return V_349 ;
}
static int F_353 ( struct V_237 * V_462 )
{
struct V_9 * V_10 = F_2 ( V_462 -> V_125 -> V_180 ) ;
unsigned int V_849 = V_462 -> V_125 -> V_849 ;
unsigned int V_850 = V_462 -> V_125 -> V_850 ;
unsigned long V_119 ;
struct V_461 * V_461 = NULL ;
int V_100 = V_844 ;
int V_580 = 0 ;
F_4 ( V_25 , V_10 ,
L_224 ,
V_10 -> V_447 , V_849 , V_850 , V_462 ) ;
F_50 ( & V_10 -> V_377 , V_119 ) ;
V_461 = (struct V_461 * ) F_143 ( V_462 ) ;
if ( ! V_461 ) {
F_51 ( & V_10 -> V_377 , V_119 ) ;
return V_844 ;
}
F_354 ( & V_461 -> V_464 ) ;
F_51 ( & V_10 -> V_377 , V_119 ) ;
if ( F_355 ( V_10 , V_461 ) != V_41 ) {
F_113 ( F_28 ( L_225 ,
V_10 -> V_447 , V_849 , V_850 ) ) ;
V_100 = V_851 ;
} else {
F_113 ( F_28 ( L_226 ,
V_10 -> V_447 , V_849 , V_850 ) ) ;
V_580 = 1 ;
}
F_195 ( & V_461 -> V_464 , F_146 ) ;
if ( V_580 ) {
if ( ! F_349 ( V_10 , V_462 ) ) {
F_3 ( F_28 ( L_227 ,
V_10 -> V_447 , V_849 , V_850 ) ) ;
V_100 = V_851 ;
}
}
F_4 ( V_25 , V_10 ,
L_228 ,
V_10 -> V_447 , V_849 , V_850 , ( V_100 == V_844 ) ? L_229 : L_230 ) ;
return V_100 ;
}
static int F_356 ( struct V_237 * V_462 )
{
struct V_9 * V_10 = F_2 ( V_462 -> V_125 -> V_180 ) ;
struct V_132 * V_132 = V_462 -> V_125 -> V_470 ;
int V_100 = V_851 , V_852 ;
if ( ! V_132 )
return V_100 ;
V_100 = F_357 ( V_462 ) ;
if ( V_100 )
return V_100 ;
V_100 = V_851 ;
F_4 ( V_25 , V_10 ,
L_231 , V_10 -> V_447 ,
V_462 -> V_125 -> V_853 , V_462 -> V_125 -> V_849 , V_462 -> V_125 -> V_850 ) ;
F_3 ( F_28 ( V_25
L_232
L_233 , V_10 -> V_447 ,
V_462 , V_458 , V_462 -> V_854 -> V_855 / V_326 ,
V_10 -> V_479 , V_462 -> V_473 , V_462 -> V_856 ) ) ;
V_852 = F_358 ( V_10 , V_132 , V_462 -> V_125 -> V_850 ) ;
if ( V_852 != V_41 ) {
F_4 ( V_25 , V_10 , L_234 , V_852 ) ;
goto V_857;
}
if ( F_352 ( V_10 , F_49 ( V_462 -> V_125 ) ,
V_462 -> V_125 ) ) {
F_4 ( V_25 , V_10 ,
L_235
L_236 ) ;
goto V_857;
}
if ( F_359 ( V_10 , V_132 , V_462 -> V_125 -> V_850 ,
V_858 ) != V_41 )
goto V_857;
F_4 ( V_25 , V_10 ,
L_237 ,
V_10 -> V_447 , V_462 -> V_125 -> V_853 , V_462 -> V_125 -> V_849 ,
V_462 -> V_125 -> V_850 ) ;
V_100 = V_844 ;
V_857:
return V_100 ;
}
static int F_360 ( struct V_237 * V_462 )
{
struct V_9 * V_10 = F_2 ( V_462 -> V_125 -> V_180 ) ;
struct V_132 * V_132 = V_462 -> V_125 -> V_470 ;
int V_852 , V_100 ;
if ( ! V_132 )
return V_851 ;
V_100 = F_357 ( V_462 ) ;
if ( V_100 )
return V_100 ;
F_361 ( V_25 , F_49 ( V_462 -> V_125 ) ,
L_238 ) ;
F_3 ( F_28 ( V_25
L_239
L_240 ,
V_10 -> V_447 , V_462 , V_458 , V_462 -> V_854 -> V_855 / V_326 ,
V_10 -> V_479 , V_462 -> V_473 , V_462 -> V_856 ) ) ;
V_852 = F_362 ( V_10 , V_132 ) ;
if ( V_852 != V_41 ) {
F_361 ( V_25 , F_49 ( V_462 -> V_125 ) ,
L_241 ) ;
return V_851 ;
}
if ( F_352 ( V_10 , F_49 ( V_462 -> V_125 ) ,
NULL ) ) {
F_361 ( V_25 , F_49 ( V_462 -> V_125 ) ,
L_242
L_243 ) ;
return V_851 ;
}
if ( F_359 ( V_10 , V_132 , V_462 -> V_125 -> V_850 ,
V_859 ) != V_41 ) {
F_361 ( V_25 , F_49 ( V_462 -> V_125 ) ,
L_242
L_244 ) ;
return V_851 ;
}
F_361 ( V_25 , F_49 ( V_462 -> V_125 ) ,
L_245 ) ;
return V_844 ;
}
static int F_363 ( struct V_1 * V_2 )
{
if ( V_2 -> V_860 == V_861 )
return 1 ;
return 0 ;
}
static int F_364 ( struct V_237 * V_462 )
{
int V_862 = V_851 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_462 -> V_125 -> V_180 ) ;
if ( V_543 ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_447 , V_26 ) ) ;
if ( F_363 ( V_462 -> V_125 -> V_180 ) )
F_193 ( V_10 , V_863 << 16 ) ;
return V_851 ;
}
F_4 ( V_25 , V_10 ,
L_246 , V_10 -> V_447 ,
V_462 -> V_125 -> V_853 , V_462 -> V_125 -> V_849 , V_462 -> V_125 -> V_850 ) ;
if ( F_351 ( V_10 ) != V_41 ) {
F_3 ( F_28 ( L_247
L_248 , V_10 -> V_447 , V_462 -> V_125 -> V_853 ,
V_26 ) ) ;
return V_851 ;
}
if ( ! F_34 ( V_481 , & V_10 -> V_479 ) ) {
if ( F_8 ( V_10 ) )
F_166 ( V_485 , & V_10 -> V_479 ) ;
else
F_166 ( V_481 , & V_10 -> V_479 ) ;
}
if ( F_200 ( V_10 ) == V_41 )
V_862 = V_844 ;
F_4 ( V_25 , V_10 , L_249 ,
V_862 == V_851 ? L_134 : L_135 ) ;
return V_862 ;
}
static int F_365 ( struct V_9 * V_10 )
{
T_1 V_315 [ V_316 ] ;
T_1 V_317 [ V_316 ] ;
struct V_297 * V_298 = NULL ;
T_1 V_864 = sizeof( struct V_297 ) ;
int V_18 = V_41 ;
T_5 V_865 ;
V_298 = F_42 ( & V_10 -> V_194 -> V_126 ,
sizeof( struct V_297 ) ,
& V_865 , V_140 ) ;
if ( ! V_298 ) {
F_4 ( V_147 , V_10 , L_250 ,
V_26 ) ;
V_18 = - V_105 ;
goto V_866;
}
memset ( V_298 , 0 , V_864 ) ;
V_18 = F_366 ( V_10 , V_865 , V_867 , V_864 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_868;
}
V_18 = F_77 ( V_10 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_868;
}
F_78 ( & V_10 -> V_324 ,
V_325 * V_326 ) ;
V_18 = F_79 ( V_10 , & V_315 [ 0 ] , & V_317 [ 0 ] , V_865 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_868;
}
V_868:
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( struct V_297 ) ,
V_298 , V_865 ) ;
V_866:
F_3 ( F_4 ( V_25 , V_10 , L_251 , V_26 ,
V_18 == V_41 ? L_135 : L_134 ) ) ;
return V_18 ;
}
static int F_367 ( struct V_1 * V_2 , int V_869 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_18 = V_41 ;
if ( V_543 ) {
F_3 ( F_4 ( V_25 , V_10 , L_252 ,
V_26 ) ) ;
V_18 = - V_870 ;
goto V_871;
}
V_18 = F_351 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_253
L_254 , V_26 ) ) ;
V_18 = - V_321 ;
goto V_871;
}
if ( F_34 ( V_481 , & V_10 -> V_479 ) )
goto V_872;
switch ( V_869 ) {
case V_873 :
F_166 ( V_481 , & V_10 -> V_479 ) ;
break;
case V_874 :
if ( ! F_34 ( V_481 , & V_10 -> V_479 ) ) {
if ( F_8 ( V_10 ) )
F_166 ( V_485 ,
& V_10 -> V_479 ) ;
else {
V_18 = F_365 ( V_10 ) ;
goto V_871;
}
}
break;
}
V_872:
V_18 = F_200 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_255 ,
V_26 ) ) ;
V_18 = - V_321 ;
}
V_871:
return V_18 ;
}
static T_12
F_368 ( struct V_632 * V_194 , T_13 V_242 )
{
struct V_9 * V_10 = F_334 ( V_194 ) ;
F_4 ( V_38 , V_10 , L_256 ,
V_10 -> V_447 , V_26 , V_242 ) ;
if ( ! F_369 ( V_10 ) )
return V_875 ;
switch ( V_242 ) {
case V_876 :
F_197 ( V_471 , & V_10 -> V_119 ) ;
return V_877 ;
case V_878 :
F_166 ( V_471 , & V_10 -> V_119 ) ;
F_169 ( V_10 ) ;
F_248 ( V_10 ) ;
F_328 ( V_194 ) ;
F_193 ( V_10 , V_587 << 16 ) ;
return V_879 ;
case V_880 :
F_166 ( V_471 , & V_10 -> V_119 ) ;
F_166 ( V_472 , & V_10 -> V_119 ) ;
F_193 ( V_10 , V_474 << 16 ) ;
return V_881 ;
}
return V_879 ;
}
static T_12
F_370 ( struct V_632 * V_194 )
{
struct V_9 * V_10 = F_334 ( V_194 ) ;
if ( ! F_369 ( V_10 ) )
return V_875 ;
return V_882 ;
}
static T_1 F_371 ( struct V_9 * V_10 )
{
T_1 V_18 = V_341 ;
T_1 V_100 = 0 ;
int V_822 ;
struct V_632 * V_821 = NULL ;
F_4 ( V_38 , V_10 , L_257 , V_10 -> V_447 , V_26 ) ;
F_166 ( V_480 , & V_10 -> V_479 ) ;
if ( F_34 ( V_484 , & V_10 -> V_119 ) ) {
F_197 ( V_484 , & V_10 -> V_119 ) ;
F_197 ( V_261 , & V_10 -> V_119 ) ;
F_139 ( V_10 -> V_180 , F_198 ) ;
F_202 ( V_10 , V_586 ) ;
}
V_822 = F_272 ( V_10 -> V_194 -> V_638 ) ;
while ( V_822 > 0 ) {
V_822 -- ;
F_4 ( V_25 , V_10 , L_258
L_259 , V_10 -> V_447 , V_26 , V_822 ) ;
V_821 =
F_330 ( F_331 ( V_10 -> V_194 -> V_826 ) ,
V_10 -> V_194 -> V_826 -> V_827 , F_332 ( F_333 ( V_10 -> V_194 -> V_638 ) ,
V_822 ) ) ;
if ( ! V_821 )
continue;
if ( F_172 ( & V_821 -> V_828 ) ) {
F_4 ( V_25 , V_10 , L_260
L_261 , V_10 -> V_447 ,
V_26 , V_822 ) ;
F_336 ( V_821 ) ;
break;
}
F_336 ( V_821 ) ;
}
if ( ! V_822 ) {
F_4 ( V_25 , V_10 , L_262
L_263 , V_10 -> V_447 , V_26 ,
V_10 -> V_194 -> V_638 ) ;
F_208 ( V_10 ) ;
F_165 ( V_10 , V_538 ,
V_883 ) ;
F_165 ( V_10 , V_884 ,
V_885 ) ;
F_209 ( V_10 ) ;
F_197 ( V_584 , & V_10 -> V_119 ) ;
V_18 = F_207 ( V_10 , V_592 ) ;
F_208 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_25 , V_10 , L_264
L_265 , V_10 -> V_447 , V_26 ) ;
F_247 ( V_10 ) ;
F_165 ( V_10 , V_538 ,
V_593 ) ;
} else {
F_4 ( V_25 , V_10 , L_264
L_266 , V_10 -> V_447 , V_26 ) ;
F_165 ( V_10 , V_538 ,
V_886 ) ;
F_165 ( V_10 , V_887 , 0 ) ;
F_372 ( V_10 ) ;
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_267
L_268 ,
V_10 -> V_194 -> V_797 ) ;
V_18 = V_341 ;
} else {
V_10 -> V_582 -> V_598 ( V_10 ) ;
V_18 = V_41 ;
}
}
F_209 ( V_10 ) ;
} else {
F_4 ( V_25 , V_10 , L_269
L_270 , V_10 -> V_447 , V_26 ,
V_10 -> V_194 -> V_638 ) ;
if ( ( F_160 ( V_10 , V_538 ) ==
V_886 ) ) {
F_197 ( V_584 , & V_10 -> V_119 ) ;
V_18 = F_207 ( V_10 , V_592 ) ;
if ( V_18 == V_41 ) {
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_271
L_272
L_273 , V_10 -> V_194 -> V_797 ) ;
V_18 = V_341 ;
} else {
V_10 -> V_582 -> V_598 ( V_10 ) ;
V_18 = V_41 ;
}
}
F_208 ( V_10 ) ;
F_372 ( V_10 ) ;
F_209 ( V_10 ) ;
}
}
F_197 ( V_480 , & V_10 -> V_479 ) ;
return V_18 ;
}
static T_12
F_373 ( struct V_632 * V_194 )
{
T_12 V_100 = V_881 ;
struct V_9 * V_10 = F_334 ( V_194 ) ;
int V_656 ;
F_4 ( V_38 , V_10 , L_274 ,
V_10 -> V_447 , V_26 ) ;
if ( ! F_369 ( V_10 ) )
return V_875 ;
F_374 ( V_194 ) ;
F_325 ( V_194 ) ;
V_656 = F_310 ( V_194 ) ;
if ( V_656 ) {
F_4 ( V_38 , V_10 , L_275
L_276 , V_10 -> V_447 , V_26 ) ;
goto V_888;
}
V_10 -> V_582 -> V_585 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_371 ( V_10 ) == V_41 ) {
V_100 = V_882 ;
goto V_888;
} else
goto V_888;
}
V_888:
F_4 ( V_38 , V_10 , L_277
L_276 , V_10 -> V_447 , V_26 , V_100 ) ;
return V_100 ;
}
static void
F_375 ( struct V_632 * V_194 )
{
struct V_9 * V_10 = F_334 ( V_194 ) ;
int V_100 ;
F_4 ( V_38 , V_10 , L_278 ,
V_10 -> V_447 , V_26 ) ;
V_100 = F_351 ( V_10 ) ;
if ( V_100 != V_41 ) {
F_4 ( V_147 , V_10 , L_279
L_280 , V_10 -> V_447 ,
V_26 ) ;
}
F_376 ( V_194 ) ;
F_197 ( V_471 , & V_10 -> V_119 ) ;
}
static int T_14 F_377 ( void )
{
int V_100 ;
V_514 = F_378 ( L_281 , sizeof( struct V_461 ) , 0 ,
V_889 , NULL ) ;
if ( V_514 == NULL ) {
F_28 ( V_147
L_282
L_283 , V_633 ) ;
V_100 = - V_105 ;
goto V_890;
}
strcpy ( V_816 , V_891 ) ;
if ( V_892 )
strcat ( V_816 , L_284 ) ;
V_812 =
F_379 ( & V_269 ) ;
if ( ! V_812 ) {
V_100 = - V_777 ;
goto V_893;
}
V_100 = F_380 ( & V_894 ) ;
if ( V_100 )
goto V_895;
F_28 ( V_25 L_285 ) ;
return 0 ;
V_895:
F_381 ( & V_269 ) ;
V_893:
F_382 ( V_514 ) ;
V_890:
return V_100 ;
}
static void T_15 F_383 ( void )
{
F_384 ( & V_894 ) ;
F_381 ( & V_269 ) ;
F_382 ( V_514 ) ;
}
