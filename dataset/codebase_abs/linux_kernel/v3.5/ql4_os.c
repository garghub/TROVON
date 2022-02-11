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
unsigned long V_119 , V_377 ;
struct V_378 * V_350 = NULL ;
T_5 V_379 ;
T_1 V_380 ;
int V_100 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_379 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_63 , V_26 ) ;
goto V_381;
}
V_377 = V_382 + ( V_326 * V_383 ) ;
do {
V_100 = F_98 ( V_10 , V_132 -> V_196 ,
V_350 , V_379 ,
NULL , NULL , & V_380 , NULL ,
NULL , NULL ) ;
if ( V_100 == V_341 )
goto V_381;
if ( ( V_380 == V_368 ) ||
( V_380 == V_384 ) )
goto V_381;
F_99 ( V_326 ) ;
} while ( ( F_100 ( V_377 , V_382 ) ) );
V_381:
F_101 ( V_10 , V_132 -> V_196 ) ;
F_50 ( & V_10 -> V_385 , V_119 ) ;
F_102 ( V_10 , V_132 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
F_103 ( V_190 ) ;
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_379 ) ;
}
static struct V_186 *
F_104 ( struct V_128 * V_190 , T_1 V_386 )
{
struct V_186 * V_187 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
V_187 = F_105 ( V_190 , sizeof( struct V_334 ) ,
V_386 ) ;
if ( ! V_187 )
return NULL ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_333 = V_187 ;
return V_187 ;
}
static int F_106 ( struct V_128 * V_129 ,
struct V_186 * V_187 ,
T_6 V_387 , int V_388 )
{
struct V_332 * V_333 ;
struct V_334 * V_334 ;
struct V_174 * V_176 ;
F_3 ( F_28 ( V_25 L_26 , V_26 ) ) ;
if ( F_107 ( V_129 , V_187 , V_388 ) )
return - V_29 ;
V_176 = F_108 ( V_387 ) ;
V_333 = V_187 -> V_134 ;
V_334 = V_333 -> V_134 ;
V_334 -> V_178 = V_176 -> V_134 ;
return 0 ;
}
static int F_109 ( struct V_186 * V_187 )
{
struct V_128 * V_190 = F_40 ( V_187 ) ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
struct V_378 * V_350 = NULL ;
T_5 V_379 ;
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
L_64 ) ;
V_100 = - V_389 ;
goto V_390;
}
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_379 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_63 , V_26 ) ;
V_100 = - V_105 ;
goto V_390;
}
V_100 = F_110 ( V_10 , V_132 , V_187 , & V_336 ) ;
if ( V_100 ) {
if ( V_336 )
if ( V_132 -> V_367 ==
V_391 ) {
V_132 -> V_369 ( V_132 -> V_131 ) ;
goto V_392;
}
F_4 ( V_147 , V_10 , L_65 ,
V_26 , V_132 -> V_196 ) ;
goto V_390;
}
V_349 = F_111 ( V_10 , V_132 -> V_196 ) ;
if ( V_349 == V_341 ) {
F_4 ( V_147 , V_10 , L_66 , V_26 ,
V_131 -> V_356 ) ;
V_100 = - V_29 ;
goto V_390;
}
if ( V_132 -> V_367 == V_368 )
V_132 -> V_367 = V_393 ;
F_3 ( F_28 ( V_25 L_67 , V_26 ,
V_132 -> V_367 ) ) ;
V_392:
V_100 = 0 ;
V_390:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_379 ) ;
return V_100 ;
}
static void F_112 ( struct V_186 * V_187 )
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
V_15 = V_394 ;
if ( F_113 ( V_10 , V_132 , V_15 ) == V_341 )
F_4 ( V_147 , V_10 , L_68 , V_26 ) ;
}
static void F_114 ( struct V_395 * V_396 )
{
struct V_366 * V_397 ;
struct V_9 * V_10 ;
struct V_398 * V_399 ;
struct V_400 * V_401 ;
struct V_402 * V_403 ;
T_2 * V_127 ;
T_1 V_404 ;
struct V_332 * V_333 ;
int V_405 ;
T_7 V_406 ;
V_397 = F_115 ( V_396 , struct V_366 , V_407 ) ;
V_10 = V_397 -> V_10 ;
V_401 = V_397 -> V_401 ;
V_399 = & V_397 -> V_399 ;
V_405 = sizeof( struct V_402 ) ;
F_116 ( F_28 ( V_25 L_69 ) ) ;
F_116 ( F_117 ( V_399 , 64 ) ) ;
F_116 ( F_28 ( V_25 L_70 ) ) ;
F_116 ( F_117 ( V_397 -> V_408 , 64 ) ) ;
V_333 = V_401 -> V_333 ;
switch ( V_399 -> V_409 ) {
case V_410 :
V_403 = (struct V_402 * ) V_397 -> V_408 ;
V_406 = V_399 -> V_411 ;
V_403 -> V_406 = V_406 ;
V_127 = V_397 -> V_408 + V_405 ;
V_404 = V_397 -> V_412 - V_405 ;
F_118 ( V_333 , V_403 , V_127 , V_404 ) ;
break;
default:
F_4 ( V_147 , V_10 , L_71 ,
V_399 -> V_409 ) ;
break;
}
return;
}
static int F_119 ( struct V_400 * V_401 , T_2 V_413 )
{
struct V_366 * V_397 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
int V_405 ;
V_131 = V_401 -> V_333 -> V_239 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_397 = V_401 -> V_134 ;
memset ( V_397 , 0 , sizeof( struct V_366 ) ) ;
if ( V_401 -> V_238 ) {
F_4 ( V_25 , V_10 ,
L_72 , V_26 ) ;
return - V_29 ;
}
V_405 = sizeof( struct V_402 ) ;
V_397 -> V_10 = V_10 ;
V_397 -> V_401 = V_401 ;
if ( V_401 -> V_414 ) {
V_397 -> V_415 = F_120 ( & V_10 -> V_194 -> V_126 , V_401 -> V_127 ,
V_401 -> V_414 ,
V_416 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_73 ,
V_26 , V_401 -> V_333 -> V_417 , V_405 ) ) ;
V_397 -> V_412 = V_401 -> V_333 -> V_417 + V_405 ;
V_397 -> V_408 = F_42 ( & V_10 -> V_194 -> V_126 ,
V_397 -> V_412 ,
& V_397 -> V_418 ,
V_419 ) ;
if ( ! V_397 -> V_408 )
goto V_420;
V_397 -> V_421 = V_401 -> V_414 + V_405 ;
V_397 -> V_422 = F_42 ( & V_10 -> V_194 -> V_126 ,
V_397 -> V_421 ,
& V_397 -> V_423 ,
V_419 ) ;
if ( ! V_397 -> V_422 )
goto V_420;
V_401 -> V_403 = V_397 -> V_422 ;
F_121 ( & V_397 -> V_407 , F_114 ) ;
return 0 ;
V_420:
if ( V_397 -> V_408 )
F_46 ( & V_10 -> V_194 -> V_126 , V_397 -> V_412 ,
V_397 -> V_408 , V_397 -> V_418 ) ;
if ( V_397 -> V_422 )
F_46 ( & V_10 -> V_194 -> V_126 , V_397 -> V_421 ,
V_397 -> V_422 , V_397 -> V_423 ) ;
return - V_105 ;
}
static void F_122 ( struct V_400 * V_401 )
{
struct V_366 * V_397 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
int V_405 ;
V_405 = sizeof( struct V_402 ) ;
V_131 = V_401 -> V_333 -> V_239 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_397 = V_401 -> V_134 ;
if ( V_401 -> V_414 ) {
F_123 ( & V_10 -> V_194 -> V_126 , V_397 -> V_415 ,
V_401 -> V_414 , V_416 ) ;
}
F_3 ( F_4 ( V_25 , V_10 , L_73 ,
V_26 , V_401 -> V_333 -> V_417 , V_405 ) ) ;
F_46 ( & V_10 -> V_194 -> V_126 , V_397 -> V_412 ,
V_397 -> V_408 , V_397 -> V_418 ) ;
F_46 ( & V_10 -> V_194 -> V_126 , V_397 -> V_421 ,
V_397 -> V_422 , V_397 -> V_423 ) ;
return;
}
static int F_124 ( struct V_400 * V_401 )
{
struct V_237 * V_238 = V_401 -> V_238 ;
struct V_130 * V_131 = V_401 -> V_333 -> V_239 ;
struct V_132 * V_132 = V_131 -> V_134 ;
struct V_9 * V_10 = V_132 -> V_10 ;
if ( ! V_238 )
return F_125 ( V_401 ) ;
F_4 ( V_25 , V_10 , L_74 ,
V_26 ) ;
return - V_39 ;
}
static void F_126 ( struct V_9 * V_10 ,
struct V_378 * V_350 ,
struct V_128 * V_190 ,
struct V_186 * V_187 )
{
int V_424 = 0 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_332 * V_333 ;
char V_425 [ V_348 ] ;
T_4 V_15 = 0 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_333 = V_187 -> V_134 ;
V_132 -> V_91 = F_127 ( V_350 -> V_91 ) ;
V_333 -> V_417 = V_426 *
F_127 ( V_350 -> V_427 ) ;
V_333 -> V_428 = V_426 *
F_127 ( V_350 -> V_429 ) ;
V_131 -> V_430 =
( V_431 & F_127 ( V_350 -> V_432 ) ) ;
V_131 -> V_433 = F_127 ( V_350 -> V_434 ) ;
V_131 -> V_435 = ( V_436 & F_127 ( V_350 -> V_432 ) ) ;
V_131 -> V_437 = V_426 *
F_127 ( V_350 -> V_438 ) ;
V_131 -> V_439 = V_426 *
F_127 ( V_350 -> V_440 ) ;
V_131 -> V_441 = F_127 ( V_350 -> V_442 ) ;
V_131 -> V_443 = F_127 ( V_350 -> V_444 ) ;
V_333 -> V_358 = F_127 ( V_350 -> V_445 ) ;
V_131 -> V_446 = F_45 ( V_350 -> V_447 ) ;
V_15 = F_127 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 )
sprintf ( V_425 , L_56 , V_350 -> V_425 ) ;
else
sprintf ( V_425 , L_57 , V_350 -> V_425 ) ;
F_128 ( V_187 , V_60 ,
( char * ) V_350 -> V_448 , V_424 ) ;
F_128 ( V_187 , V_449 ,
( char * ) V_10 -> V_267 , V_424 ) ;
F_128 ( V_187 , V_56 ,
( char * ) V_425 , V_424 ) ;
F_128 ( V_187 , V_62 ,
( char * ) V_350 -> V_450 , V_424 ) ;
}
void F_129 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
struct V_128 * V_190 ;
struct V_186 * V_187 ;
T_1 V_380 ;
T_5 V_379 ;
struct V_378 * V_350 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_379 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_63 , V_26 ) ;
goto V_451;
}
if ( F_98 ( V_10 , V_132 -> V_196 , V_350 ,
V_379 , NULL , NULL , & V_380 ,
NULL , NULL , NULL ) == V_341 ) {
F_3 ( F_4 ( V_147 , V_10 , L_75
L_76 ,
V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ) ;
goto V_451;
}
V_190 = V_132 -> V_131 ;
V_187 = V_132 -> V_333 ;
F_126 ( V_10 , V_350 , V_190 , V_187 ) ;
V_451:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_379 ) ;
}
void F_130 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
struct V_128 * V_190 ;
struct V_186 * V_187 ;
struct V_130 * V_131 ;
struct V_332 * V_333 ;
T_1 V_380 ;
T_5 V_379 ;
struct V_378 * V_350 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_379 , V_140 ) ;
if ( ! V_350 ) {
F_4 ( V_147 , V_10 ,
L_63 , V_26 ) ;
goto V_453;
}
if ( F_98 ( V_10 , V_132 -> V_196 , V_350 ,
V_379 , NULL , NULL , & V_380 ,
NULL , NULL , NULL ) == V_341 ) {
F_3 ( F_4 ( V_147 , V_10 , L_75
L_76 ,
V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ) ;
goto V_453;
}
V_190 = V_132 -> V_131 ;
V_131 = V_190 -> V_134 ;
V_187 = V_132 -> V_333 ;
V_333 = V_187 -> V_134 ;
V_132 -> V_454 =
( F_127 ( V_350 -> V_455 ) > V_456 ) &&
( F_127 ( V_350 -> V_455 ) < V_456 * 10 ) ?
F_127 ( V_350 -> V_455 ) : V_456 ;
V_132 -> V_457 =
F_127 ( V_350 -> V_442 ) ;
V_132 -> V_91 = F_127 ( V_350 -> V_91 ) ;
V_333 -> V_417 = V_426 *
F_127 ( V_350 -> V_427 ) ;
V_333 -> V_428 = V_426 *
F_127 ( V_350 -> V_429 ) ;
V_131 -> V_430 =
( V_431 & F_127 ( V_350 -> V_432 ) ) ;
V_131 -> V_433 = F_127 ( V_350 -> V_434 ) ;
V_131 -> V_435 = ( V_436 & F_127 ( V_350 -> V_432 ) ) ;
V_131 -> V_437 = V_426 *
F_127 ( V_350 -> V_438 ) ;
V_131 -> V_439 = V_426 *
F_127 ( V_350 -> V_440 ) ;
V_131 -> V_441 = F_127 ( V_350 -> V_442 ) ;
V_131 -> V_443 = F_127 ( V_350 -> V_444 ) ;
V_131 -> V_446 = F_45 ( V_350 -> V_447 ) ;
memcpy ( V_131 -> V_458 , V_10 -> V_267 ,
F_131 ( sizeof( V_10 -> V_267 ) , sizeof( V_131 -> V_458 ) ) ) ;
F_128 ( V_187 , V_62 ,
( char * ) V_350 -> V_450 , 0 ) ;
V_453:
if ( V_350 )
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_379 ) ;
}
static void F_132 ( struct V_9 * V_10 , void * V_459 ,
unsigned long V_460 )
{
F_133 ( F_28 ( L_77 ,
V_26 , V_10 -> V_180 -> V_452 ) ) ;
F_134 ( & V_10 -> V_461 ) ;
V_10 -> V_461 . V_462 = V_382 + V_460 * V_326 ;
V_10 -> V_461 . V_127 = ( unsigned long ) V_10 ;
V_10 -> V_461 . V_463 = ( void (*) ( unsigned long ) ) V_459 ;
F_135 ( & V_10 -> V_461 ) ;
V_10 -> V_464 = 1 ;
}
static void F_136 ( struct V_9 * V_10 )
{
F_137 ( & V_10 -> V_461 ) ;
V_10 -> V_464 = 0 ;
}
void F_138 ( struct V_128 * V_129 )
{
F_139 ( V_129 ) ;
}
void F_140 ( struct V_9 * V_10 )
{
F_141 ( V_10 -> V_180 , F_138 ) ;
}
static struct V_465 * F_142 ( struct V_9 * V_10 ,
struct V_132 * V_132 ,
struct V_237 * V_466 )
{
struct V_465 * V_465 ;
V_465 = F_143 ( V_10 -> V_467 , V_419 ) ;
if ( ! V_465 )
return V_465 ;
F_144 ( & V_465 -> V_468 ) ;
V_465 -> V_10 = V_10 ;
V_465 -> V_469 = V_132 ;
V_465 -> V_466 = V_466 ;
V_465 -> V_119 = 0 ;
F_145 ( V_466 ) = ( void * ) V_465 ;
return V_465 ;
}
static void F_146 ( struct V_9 * V_10 , struct V_465 * V_465 )
{
struct V_237 * V_466 = V_465 -> V_466 ;
if ( V_465 -> V_119 & V_470 ) {
F_147 ( V_466 ) ;
V_465 -> V_119 &= ~ V_470 ;
}
F_145 ( V_466 ) = NULL ;
}
void F_148 ( struct V_471 * V_472 )
{
struct V_465 * V_465 = F_115 ( V_472 , struct V_465 , V_468 ) ;
struct V_237 * V_466 = V_465 -> V_466 ;
struct V_9 * V_10 = V_465 -> V_10 ;
F_146 ( V_10 , V_465 ) ;
F_149 ( V_465 , V_10 -> V_467 ) ;
V_466 -> V_473 ( V_466 ) ;
}
static int F_150 ( struct V_1 * V_180 , struct V_237 * V_466 )
{
struct V_9 * V_10 = F_2 ( V_180 ) ;
struct V_132 * V_132 = V_466 -> V_125 -> V_474 ;
struct V_128 * V_131 = V_132 -> V_131 ;
struct V_465 * V_465 ;
int V_18 ;
if ( F_34 ( V_475 , & V_10 -> V_119 ) ) {
if ( F_34 ( V_476 , & V_10 -> V_119 ) )
V_466 -> V_477 = V_478 << 16 ;
else
V_466 -> V_477 = V_479 << 16 ;
goto V_480;
}
if ( ! V_131 ) {
V_466 -> V_477 = V_481 << 16 ;
goto V_480;
}
V_18 = F_15 ( V_131 ) ;
if ( V_18 ) {
V_466 -> V_477 = V_18 ;
goto V_480;
}
if ( F_34 ( V_482 , & V_10 -> V_483 ) ||
F_34 ( V_484 , & V_10 -> V_483 ) ||
F_34 ( V_485 , & V_10 -> V_483 ) ||
F_34 ( V_486 , & V_10 -> V_483 ) ||
F_34 ( V_487 , & V_10 -> V_483 ) ||
! F_34 ( V_488 , & V_10 -> V_119 ) ||
! F_34 ( V_261 , & V_10 -> V_119 ) ||
F_34 ( V_489 , & V_10 -> V_483 ) )
goto V_490;
V_465 = F_142 ( V_10 , V_132 , V_466 ) ;
if ( ! V_465 )
goto V_490;
V_18 = F_151 ( V_10 , V_465 ) ;
if ( V_18 != V_41 )
goto V_491;
return 0 ;
V_491:
F_146 ( V_10 , V_465 ) ;
F_149 ( V_465 , V_10 -> V_467 ) ;
V_490:
return V_492 ;
V_480:
V_466 -> V_473 ( V_466 ) ;
return 0 ;
}
static void F_152 ( struct V_9 * V_10 )
{
if ( V_10 -> V_493 )
F_46 ( & V_10 -> V_194 -> V_126 , V_10 -> V_494 , V_10 -> V_493 ,
V_10 -> V_495 ) ;
if ( V_10 -> V_496 )
F_153 ( V_10 -> V_496 ) ;
V_10 -> V_494 = 0 ;
V_10 -> V_493 = NULL ;
V_10 -> V_495 = 0 ;
V_10 -> V_497 = NULL ;
V_10 -> V_498 = 0 ;
V_10 -> V_499 = NULL ;
V_10 -> V_500 = 0 ;
V_10 -> V_501 = NULL ;
V_10 -> V_502 = 0 ;
V_10 -> V_496 = NULL ;
V_10 -> V_503 = 0 ;
if ( V_10 -> V_467 )
F_154 ( V_10 -> V_467 ) ;
V_10 -> V_467 = NULL ;
if ( V_10 -> V_139 )
F_155 ( V_10 -> V_139 ) ;
if ( V_10 -> V_108 )
F_153 ( V_10 -> V_108 ) ;
V_10 -> V_108 = NULL ;
if ( V_10 -> V_504 )
F_155 ( V_10 -> V_504 ) ;
if ( F_8 ( V_10 ) ) {
if ( V_10 -> V_505 )
F_156 (
(struct V_506 V_507 * ) V_10 -> V_505 ) ;
} else if ( V_10 -> V_508 )
F_156 ( V_10 -> V_508 ) ;
F_157 ( V_10 -> V_194 ) ;
}
static int F_158 ( struct V_9 * V_10 )
{
unsigned long V_509 ;
V_10 -> V_494 = ( ( V_510 * V_511 ) +
( V_512 * V_511 ) +
sizeof( struct V_501 ) +
V_513 +
( V_514 - 1 ) ) & ~ ( V_514 - 1 ) ;
V_10 -> V_493 = F_42 ( & V_10 -> V_194 -> V_126 , V_10 -> V_494 ,
& V_10 -> V_495 , V_140 ) ;
if ( V_10 -> V_493 == NULL ) {
F_4 ( V_38 , V_10 ,
L_78 ) ;
goto V_515;
}
memset ( V_10 -> V_493 , 0 , V_10 -> V_494 ) ;
V_509 = 0 ;
if ( ( unsigned long ) V_10 -> V_495 & ( V_513 - 1 ) )
V_509 = V_513 - ( ( unsigned long ) V_10 -> V_495 &
( V_513 - 1 ) ) ;
V_10 -> V_498 = V_10 -> V_495 + V_509 ;
V_10 -> V_497 = (struct V_516 * ) ( V_10 -> V_493 + V_509 ) ;
V_10 -> V_500 = V_10 -> V_495 + V_509 +
( V_510 * V_511 ) ;
V_10 -> V_499 = (struct V_516 * ) ( V_10 -> V_493 + V_509 +
( V_510 *
V_511 ) ) ;
V_10 -> V_502 = V_10 -> V_495 + V_509 +
( V_510 * V_511 ) +
( V_512 * V_511 ) ;
V_10 -> V_501 = (struct V_501 * ) ( V_10 -> V_493 + V_509 +
( V_510 *
V_511 ) +
( V_512 *
V_511 ) ) ;
V_10 -> V_467 = F_159 ( V_517 , V_518 ,
V_519 , V_520 ) ;
if ( V_10 -> V_467 == NULL ) {
F_4 ( V_38 , V_10 ,
L_79 ) ;
goto V_515;
}
V_10 -> V_139 = F_160 ( L_80 , & V_10 -> V_194 -> V_126 ,
V_521 , 8 , 0 ) ;
if ( V_10 -> V_139 == NULL ) {
F_4 ( V_38 , V_10 ,
L_81 , V_26 ) ;
goto V_515;
}
V_10 -> V_504 = F_160 ( L_82 , & V_10 -> V_194 -> V_126 ,
V_522 , 8 , 0 ) ;
if ( V_10 -> V_504 == NULL ) {
F_4 ( V_38 , V_10 ,
L_83 ,
V_26 ) ;
goto V_515;
}
return V_41 ;
V_515:
F_152 ( V_10 ) ;
return V_341 ;
}
static int F_161 ( struct V_9 * V_10 )
{
T_1 V_523 , V_524 , V_525 ;
int V_349 = V_41 ;
V_523 = F_162 ( V_10 , V_526 ) ;
V_524 = F_163 ( V_523 ) ;
V_525 = F_164 ( V_523 ) ;
if ( V_524 == V_527 ) {
F_4 ( V_38 , V_10 , L_84
L_85
L_86 , V_525 ) ;
V_349 = V_341 ;
} else if ( V_524 == V_528 ) {
if ( V_10 -> V_529 == V_530 )
F_4 ( V_38 , V_10 , L_87
L_88
L_89 , V_525 ) ;
} else {
if ( V_10 -> V_529 == V_528 )
F_4 ( V_25 , V_10 , L_90
L_91 ,
V_525 ) ;
}
V_10 -> V_529 = V_524 ;
return V_349 ;
}
static int F_165 ( struct V_9 * V_10 )
{
T_1 V_531 ;
int V_349 = V_41 ;
V_531 = F_162 ( V_10 , V_532 ) ;
if ( V_531 == 0xffffffff ) {
F_3 ( F_28 ( V_38 L_92
L_93 ,
V_10 -> V_452 , V_26 ) ) ;
return V_349 ;
}
if ( V_10 -> V_531 == V_531 ) {
V_10 -> V_533 ++ ;
if ( V_10 -> V_533 == 2 ) {
V_10 -> V_533 = 0 ;
F_4 ( V_25 , V_10 ,
L_94
L_95
L_96
L_97
L_98 ,
V_10 -> V_452 , V_26 ,
F_162 ( V_10 ,
V_534 ) ,
F_162 ( V_10 ,
V_535 ) ,
F_162 ( V_10 , V_536 +
0x3c ) ,
F_162 ( V_10 , V_537 +
0x3c ) ,
F_162 ( V_10 , V_538 +
0x3c ) ,
F_162 ( V_10 , V_539 +
0x3c ) ,
F_162 ( V_10 , V_540 +
0x3c ) ) ;
V_349 = V_341 ;
}
} else
V_10 -> V_533 = 0 ;
V_10 -> V_531 = V_531 ;
return V_349 ;
}
void F_166 ( struct V_9 * V_10 )
{
T_1 V_541 , V_542 ;
if ( ! ( F_34 ( V_484 , & V_10 -> V_483 ) ||
F_34 ( V_485 , & V_10 -> V_483 ) ||
F_34 ( V_543 , & V_10 -> V_483 ) ) ) {
V_541 = F_162 ( V_10 , V_544 ) ;
if ( F_161 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_99
L_100 ) ;
F_167 ( V_10 , V_545 + 0x98 ,
V_546 |
V_547 ) ;
F_168 ( V_486 , & V_10 -> V_483 ) ;
F_169 ( V_10 ) ;
} else if ( V_541 == V_548 &&
! F_34 ( V_485 , & V_10 -> V_483 ) ) {
if ( ! V_549 ) {
F_4 ( V_25 , V_10 , L_101
L_102 , V_26 ) ;
F_168 ( V_485 , & V_10 -> V_483 ) ;
F_169 ( V_10 ) ;
}
} else if ( V_541 == V_550 &&
! F_34 ( V_487 , & V_10 -> V_483 ) ) {
F_4 ( V_25 , V_10 , L_103 ,
V_26 ) ;
F_168 ( V_487 , & V_10 -> V_483 ) ;
F_169 ( V_10 ) ;
} else {
if ( F_165 ( V_10 ) ) {
F_4 ( V_25 , V_10 , L_99
L_100 ) ;
F_167 ( V_10 , V_545 + 0x98 ,
V_546 |
V_547 ) ;
V_542 = F_162 ( V_10 ,
V_534 ) ;
if ( F_170 ( V_542 ) == 0x67 )
F_4 ( V_147 , V_10 , L_104
L_105
L_106
L_107 ,
V_26 ) ;
if ( V_542 & V_551 )
F_168 ( V_486 ,
& V_10 -> V_483 ) ;
else {
F_4 ( V_25 , V_10 , L_108
L_109 , V_26 ) ;
F_168 ( V_485 , & V_10 -> V_483 ) ;
}
F_171 ( V_10 ) ;
F_169 ( V_10 ) ;
}
}
}
}
static void F_172 ( struct V_128 * V_190 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! ( V_132 -> V_361 == V_362 ) )
return;
if ( F_33 ( V_10 ) && ! F_34 ( V_552 , & V_132 -> V_119 ) &&
! F_173 ( V_190 ) ) {
if ( F_174 ( & V_132 -> V_553 ) !=
V_554 ) {
if ( F_174 ( & V_132 -> V_553 ) ==
0 ) {
F_175 ( & V_132 -> V_553 ,
V_554 ) ;
F_168 ( V_555 , & V_10 -> V_483 ) ;
F_168 ( V_552 , & V_132 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_110 ,
V_26 , V_132 -> V_196 ) ) ;
} else
F_176 ( & V_132 -> V_553 ) ;
}
}
if ( F_174 ( & V_132 -> V_556 ) &&
( F_177 ( & V_132 -> V_556 ) != 0 ) ) {
if ( ! F_173 ( V_190 ) ) {
F_178 ( & V_132 -> V_557 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_111
L_112 , V_26 ,
V_132 -> V_196 ,
F_174 ( & V_132 -> V_557 ) ,
V_132 -> V_457 + 4 ) ) ;
F_168 ( V_555 , & V_10 -> V_483 ) ;
F_175 ( & V_132 -> V_553 ,
V_132 -> V_457 + 4 ) ;
}
}
}
static void F_179 ( struct V_9 * V_10 )
{
int V_558 = 0 ;
T_4 V_559 ;
F_141 ( V_10 -> V_180 , F_172 ) ;
if ( F_34 ( V_475 , & V_10 -> V_119 ) ) {
F_180 ( & V_10 -> V_461 , V_382 + V_326 ) ;
return;
}
if ( ! F_181 ( V_10 -> V_194 ) )
F_182 ( V_10 -> V_194 , V_560 , & V_559 ) ;
if ( F_8 ( V_10 ) ) {
F_166 ( V_10 ) ;
}
if ( ! F_8 ( V_10 ) ) {
if ( V_10 -> V_561 & V_562 &&
V_10 -> V_563 != 0 ) {
V_10 -> V_533 ++ ;
if ( V_10 -> V_533 >
V_10 -> V_563 + 2 )
F_168 ( V_485 , & V_10 -> V_483 ) ;
}
}
if ( ! F_183 ( & V_10 -> V_564 ) )
V_558 ++ ;
if ( V_558 ||
F_34 ( V_485 , & V_10 -> V_483 ) ||
F_34 ( V_543 , & V_10 -> V_483 ) ||
F_34 ( V_555 , & V_10 -> V_483 ) ||
F_34 ( V_489 , & V_10 -> V_483 ) ||
F_34 ( V_482 , & V_10 -> V_483 ) ||
F_34 ( V_565 , & V_10 -> V_483 ) ||
F_34 ( V_566 , & V_10 -> V_483 ) ||
F_34 ( V_486 , & V_10 -> V_483 ) ||
F_34 ( V_487 , & V_10 -> V_483 ) ||
F_34 ( V_567 , & V_10 -> V_483 ) ) {
F_3 ( F_28 ( L_113
L_114 ,
V_10 -> V_452 , V_26 , V_10 -> V_483 ) ) ;
F_169 ( V_10 ) ;
}
F_180 ( & V_10 -> V_461 , V_382 + V_326 ) ;
F_3 ( V_10 -> V_568 ++ ) ;
}
static int F_184 ( struct V_9 * V_10 )
{
T_1 V_569 = 0 ;
unsigned long V_119 ;
struct V_237 * V_466 ;
unsigned long V_377 = V_382 + ( V_570 * V_326 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_115
L_116 , V_570 ) ) ;
while ( ! F_185 ( V_382 , V_377 ) ) {
F_50 ( & V_10 -> V_385 , V_119 ) ;
for ( V_569 = 0 ; V_569 < V_10 -> V_180 -> V_571 ; V_569 ++ ) {
V_466 = F_186 ( V_10 -> V_180 , V_569 ) ;
if ( V_466 != NULL && F_145 ( V_466 ) )
break;
}
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( V_569 == V_10 -> V_180 -> V_571 )
return V_41 ;
F_187 ( 1000 ) ;
}
return V_341 ;
}
int F_188 ( struct V_9 * V_10 )
{
T_1 V_572 ;
unsigned long V_119 = 0 ;
F_3 ( F_28 ( V_147 L_117 , V_10 -> V_452 , V_26 ) ) ;
if ( F_189 ( V_10 ) != V_41 )
return V_341 ;
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_572 = F_190 ( & V_10 -> V_508 -> V_572 ) ;
if ( ( V_572 & V_573 ) != 0 )
F_191 ( F_192 ( V_573 ) , & V_10 -> V_508 -> V_572 ) ;
F_191 ( F_192 ( V_574 ) , & V_10 -> V_508 -> V_572 ) ;
F_193 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
return V_41 ;
}
int F_194 ( struct V_9 * V_10 )
{
T_1 V_575 ;
unsigned long V_119 = 0 ;
int V_349 ;
T_1 V_572 ;
V_349 = F_188 ( V_10 ) ;
if ( V_349 != V_41 )
return V_349 ;
V_349 = V_341 ;
V_575 = V_576 ;
do {
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_572 = F_190 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( ( V_572 & V_577 ) == 0 )
break;
F_187 ( 1000 ) ;
} while ( ( -- V_575 ) );
if ( ( V_572 & V_577 ) != 0 ) {
F_3 ( F_28 ( V_38
L_118
L_119 ,
V_10 -> V_452 ) ) ;
F_50 ( & V_10 -> V_385 , V_119 ) ;
F_191 ( F_192 ( V_577 ) , & V_10 -> V_508 -> V_572 ) ;
F_193 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
}
V_575 = V_578 ;
do {
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_572 = F_190 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( ( V_572 & V_574 ) == 0 ) {
V_349 = V_41 ;
break;
}
F_187 ( 1000 ) ;
} while ( ( -- V_575 ) );
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_572 = F_190 ( & V_10 -> V_508 -> V_572 ) ;
if ( ( V_572 & V_573 ) != 0 ) {
F_191 ( F_192 ( V_573 ) , & V_10 -> V_508 -> V_572 ) ;
F_193 ( & V_10 -> V_508 -> V_572 ) ;
}
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( V_575 == 0 ) {
F_50 ( & V_10 -> V_385 , V_119 ) ;
F_191 ( F_192 ( V_579 ) , & V_10 -> V_508 -> V_572 ) ;
F_193 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
V_575 = V_578 ;
do {
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_572 = F_190 ( & V_10 -> V_508 -> V_572 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( ( V_572 & V_579 ) == 0 ) {
V_349 = V_41 ;
break;
}
F_187 ( 1000 ) ;
} while ( ( -- V_575 ) );
}
return V_349 ;
}
static void F_195 ( struct V_9 * V_10 , int V_580 )
{
struct V_465 * V_465 ;
int V_101 ;
unsigned long V_119 ;
F_50 ( & V_10 -> V_385 , V_119 ) ;
for ( V_101 = 0 ; V_101 < V_10 -> V_180 -> V_571 ; V_101 ++ ) {
V_465 = F_196 ( V_10 , V_101 ) ;
if ( V_465 != NULL ) {
V_465 -> V_466 -> V_477 = V_580 ;
F_197 ( & V_465 -> V_468 , F_148 ) ;
}
}
F_51 ( & V_10 -> V_385 , V_119 ) ;
}
void F_198 ( struct V_9 * V_10 )
{
F_199 ( V_488 , & V_10 -> V_119 ) ;
F_4 ( V_25 , V_10 , L_120 ) ;
F_195 ( V_10 , V_478 << 16 ) ;
F_140 ( V_10 ) ;
F_199 ( V_581 , & V_10 -> V_119 ) ;
}
static void F_200 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_367 = V_384 ;
if ( V_132 -> V_361 == V_362 )
F_139 ( V_132 -> V_131 ) ;
else
F_201 ( V_129 -> V_134 ,
V_582 ) ;
}
static int F_202 ( struct V_9 * V_10 )
{
int V_349 = V_341 ;
T_2 V_583 = 0 ;
T_1 V_541 ;
unsigned long V_584 ;
F_203 ( V_10 -> V_180 ) ;
F_199 ( V_488 , & V_10 -> V_119 ) ;
F_199 ( V_261 , & V_10 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_121 , V_26 ) ) ;
F_168 ( V_484 , & V_10 -> V_483 ) ;
F_141 ( V_10 -> V_180 , F_200 ) ;
if ( F_34 ( V_485 , & V_10 -> V_483 ) )
V_583 = 1 ;
if ( F_34 ( V_482 , & V_10 -> V_483 ) ) {
V_349 = V_41 ;
goto V_585;
}
if ( F_8 ( V_10 ) && ! V_583 &&
F_34 ( V_489 , & V_10 -> V_483 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_122 ,
V_10 -> V_452 , V_26 ) ) ;
V_349 = V_10 -> V_586 -> V_587 ( V_10 ) ;
if ( V_349 == V_41 ) {
if ( ! F_34 ( V_588 , & V_10 -> V_119 ) )
F_184 ( V_10 ) ;
V_10 -> V_586 -> V_589 ( V_10 ) ;
F_204 ( V_10 , V_590 ) ;
F_195 ( V_10 , V_591 << 16 ) ;
} else {
V_583 = 1 ;
F_199 ( V_489 , & V_10 -> V_483 ) ;
F_168 ( V_485 , & V_10 -> V_483 ) ;
}
}
if ( ! F_8 ( V_10 ) || V_583 ) {
if ( ! F_8 ( V_10 ) )
goto V_592;
if ( F_34 ( V_588 , & V_10 -> V_119 ) )
goto V_592;
V_584 = V_382 + ( V_593 * V_326 ) ;
while ( F_205 ( V_382 , V_584 ) ) {
if ( F_165 ( V_10 ) ) {
F_171 ( V_10 ) ;
break;
}
F_206 ( V_594 ) ;
F_207 ( V_326 ) ;
}
if ( ! F_34 ( V_588 , & V_10 -> V_119 ) )
F_184 ( V_10 ) ;
V_592:
F_204 ( V_10 , V_590 ) ;
F_195 ( V_10 , V_591 << 16 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_123 ,
V_10 -> V_452 , V_26 ) ) ;
V_349 = V_10 -> V_586 -> V_583 ( V_10 ) ;
}
F_204 ( V_10 , V_590 ) ;
V_585:
if ( V_349 == V_41 ) {
if ( ! F_8 ( V_10 ) && ( V_10 -> V_595 == 3 ) )
F_208 ( 6 ) ;
V_349 = F_209 ( V_10 , V_596 ) ;
}
if ( ! F_34 ( V_488 , & V_10 -> V_119 ) &&
! F_34 ( V_482 , & V_10 -> V_483 ) ) {
if ( F_8 ( V_10 ) ) {
F_210 ( V_10 ) ;
V_541 = F_162 ( V_10 , V_544 ) ;
F_211 ( V_10 ) ;
if ( V_541 == V_597 ) {
F_4 ( V_25 , V_10 , L_124
L_125
L_126 , V_26 ) ;
F_198 ( V_10 ) ;
F_199 ( V_543 , & V_10 -> V_483 ) ;
F_199 ( V_485 , & V_10 -> V_483 ) ;
F_199 ( V_489 ,
& V_10 -> V_483 ) ;
V_349 = V_341 ;
goto V_598;
}
}
if ( ! F_34 ( V_543 , & V_10 -> V_483 ) ) {
V_10 -> V_599 = V_600 ;
F_3 ( F_28 ( L_127
L_128 , V_10 -> V_452 ,
V_10 -> V_599 ) ) ;
F_168 ( V_543 , & V_10 -> V_483 ) ;
V_349 = V_341 ;
} else {
if ( V_10 -> V_599 > 0 ) {
V_10 -> V_599 -- ;
F_3 ( F_28 ( L_129
L_130 ,
V_10 -> V_452 ,
V_10 -> V_599 ) ) ;
V_349 = V_341 ;
}
if ( V_10 -> V_599 == 0 ) {
F_3 ( F_28 ( L_131
L_132 ,
V_10 -> V_452 ) ) ;
F_198 ( V_10 ) ;
F_199 ( V_543 , & V_10 -> V_483 ) ;
F_199 ( V_485 , & V_10 -> V_483 ) ;
F_199 ( V_489 ,
& V_10 -> V_483 ) ;
V_349 = V_341 ;
}
}
} else {
F_199 ( V_485 , & V_10 -> V_483 ) ;
F_199 ( V_489 , & V_10 -> V_483 ) ;
F_199 ( V_543 , & V_10 -> V_483 ) ;
}
V_598:
V_10 -> V_601 ++ ;
if ( F_34 ( V_488 , & V_10 -> V_119 ) )
V_10 -> V_586 -> V_602 ( V_10 ) ;
F_212 ( V_10 -> V_180 ) ;
F_199 ( V_484 , & V_10 -> V_483 ) ;
F_3 ( F_28 ( L_133 , V_10 -> V_452 ,
V_349 == V_341 ? L_134 : L_135 ) ) ;
return V_349 ;
}
static void F_213 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! F_173 ( V_129 ) ) {
if ( V_132 -> V_367 == V_391 ) {
F_4 ( V_25 , V_10 , L_136
L_137 , V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ;
F_214 ( V_132 -> V_131 ) ;
} else {
if ( V_132 -> V_361 == V_362 ) {
if ( ! F_34 ( V_552 , & V_132 -> V_119 ) )
F_215 ( V_132 ) ;
} else
F_201 ( V_129 -> V_134 ,
V_582 ) ;
}
}
}
int F_216 ( struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_129 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
F_4 ( V_25 , V_10 , L_136
L_137 , V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ;
F_214 ( V_132 -> V_131 ) ;
if ( F_34 ( V_488 , & V_10 -> V_119 ) ) {
F_4 ( V_25 , V_10 , L_136
L_138 , V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ;
F_217 ( V_10 -> V_180 , & V_132 -> V_131 -> V_603 ) ;
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
L_139 , V_10 -> V_452 , V_26 ,
V_132 -> V_196 ) ;
F_218 ( V_132 -> V_333 ) ;
F_219 ( V_132 -> V_333 ,
V_604 ) ;
return V_41 ;
}
static void F_220 ( struct V_9 * V_10 )
{
F_141 ( V_10 -> V_180 , F_213 ) ;
}
static void F_221 ( struct V_128 * V_190 )
{
T_4 V_556 ;
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
V_556 = F_222 ( V_132 -> V_454 ,
( T_4 ) V_605 ) ;
F_175 ( & V_132 -> V_556 , V_556 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_140 , V_10 -> V_452 ,
V_132 -> V_196 , V_556 ) ) ;
F_223 ( V_190 ) ;
}
static void F_224 ( struct V_128 * V_190 )
{
struct V_130 * V_131 ;
struct V_132 * V_132 ;
struct V_9 * V_10 ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_10 = V_132 -> V_10 ;
if ( ! ( V_132 -> V_361 == V_362 ) )
return;
if ( F_225 ( V_552 , & V_132 -> V_119 ) &&
! F_173 ( V_190 ) ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_141 ) ) ;
F_221 ( V_190 ) ;
}
}
void F_169 ( struct V_9 * V_10 )
{
if ( V_10 -> V_606 )
F_226 ( V_10 -> V_606 , & V_10 -> V_607 ) ;
}
static struct V_608 *
F_227 ( struct V_9 * V_10 , T_1 V_609 ,
enum V_610 type )
{
struct V_608 * V_611 ;
T_1 V_612 = sizeof( struct V_608 ) + V_609 ;
V_611 = F_228 ( V_612 , V_419 ) ;
if ( ! V_611 )
return NULL ;
F_229 ( & V_611 -> V_613 ) ;
V_611 -> type = type ;
return V_611 ;
}
static void F_230 ( struct V_9 * V_10 ,
struct V_608 * V_611 )
{
unsigned long V_119 ;
F_50 ( & V_10 -> V_614 , V_119 ) ;
F_231 ( & V_611 -> V_613 , & V_10 -> V_564 ) ;
F_51 ( & V_10 -> V_614 , V_119 ) ;
F_169 ( V_10 ) ;
}
int F_232 ( struct V_9 * V_10 ,
enum V_615 V_616 ,
T_1 V_609 , T_2 * V_127 )
{
struct V_608 * V_611 ;
V_611 = F_227 ( V_10 , V_609 , V_617 ) ;
if ( ! V_611 )
return V_341 ;
V_611 -> V_618 . V_619 . V_620 = V_616 ;
V_611 -> V_618 . V_619 . V_609 = V_609 ;
memcpy ( V_611 -> V_618 . V_619 . V_127 , V_127 , V_609 ) ;
F_230 ( V_10 , V_611 ) ;
return V_41 ;
}
int F_233 ( struct V_9 * V_10 ,
T_1 V_349 , T_1 V_6 ,
T_1 V_609 , T_2 * V_127 )
{
struct V_608 * V_611 ;
V_611 = F_227 ( V_10 , V_609 , V_621 ) ;
if ( ! V_611 )
return V_341 ;
V_611 -> V_618 . V_622 . V_349 = V_349 ;
V_611 -> V_618 . V_622 . V_6 = V_6 ;
V_611 -> V_618 . V_622 . V_609 = V_609 ;
memcpy ( V_611 -> V_618 . V_622 . V_127 , V_127 , V_609 ) ;
F_230 ( V_10 , V_611 ) ;
return V_41 ;
}
static void F_234 ( struct V_9 * V_10 )
{
struct V_608 * V_611 , * V_623 ;
unsigned long V_119 ;
F_235 ( V_624 ) ;
F_50 ( & V_10 -> V_614 , V_119 ) ;
F_236 ( & V_10 -> V_564 , & V_624 ) ;
F_51 ( & V_10 -> V_614 , V_119 ) ;
F_237 (e, tmp, &work, list) {
F_238 ( & V_611 -> V_613 ) ;
switch ( V_611 -> type ) {
case V_617 :
F_239 ( V_10 -> V_452 ,
& V_269 ,
V_611 -> V_618 . V_619 . V_620 ,
V_611 -> V_618 . V_619 . V_609 ,
V_611 -> V_618 . V_619 . V_127 ) ;
break;
case V_621 :
F_240 ( V_10 -> V_452 ,
& V_269 ,
V_611 -> V_618 . V_622 . V_349 ,
V_611 -> V_618 . V_622 . V_6 ,
V_611 -> V_618 . V_622 . V_609 ,
V_611 -> V_618 . V_622 . V_127 ) ;
break;
default:
F_4 ( V_38 , V_10 , L_142
L_143 , V_611 -> type ) ;
}
F_241 ( V_611 ) ;
}
}
static void F_242 ( struct V_395 * V_624 )
{
struct V_9 * V_10 =
F_115 ( V_624 , struct V_9 , V_607 ) ;
int V_349 = V_341 ;
F_3 (printk(L_144
L_145,
ha->host_no, __func__, ha->flags, ha->dpc_flags))
if ( ! F_34 ( V_581 , & V_10 -> V_119 ) )
return;
if ( F_34 ( V_475 , & V_10 -> V_119 ) ) {
F_3 ( F_28 ( V_25 L_146 ,
V_10 -> V_452 , V_26 , V_10 -> V_119 ) ) ;
return;
}
F_234 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_34 ( V_486 , & V_10 -> V_483 ) ) {
F_210 ( V_10 ) ;
F_167 ( V_10 , V_544 ,
V_597 ) ;
F_211 ( V_10 ) ;
F_4 ( V_25 , V_10 , L_147 ) ;
F_243 ( V_10 ) ;
}
if ( F_225 ( V_487 , & V_10 -> V_483 ) ) {
F_244 ( V_10 ) ;
}
}
if ( ! F_34 ( V_484 , & V_10 -> V_483 ) &&
( F_34 ( V_485 , & V_10 -> V_483 ) ||
F_34 ( V_482 , & V_10 -> V_483 ) ||
F_34 ( V_489 , & V_10 -> V_483 ) ) ) {
if ( V_549 ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_452 , V_26 ) ) ;
F_199 ( V_485 , & V_10 -> V_483 ) ;
F_199 ( V_482 , & V_10 -> V_483 ) ;
F_199 ( V_489 , & V_10 -> V_483 ) ;
goto V_625;
}
if ( F_34 ( V_489 , & V_10 -> V_483 ) ||
F_34 ( V_485 , & V_10 -> V_483 ) )
F_202 ( V_10 ) ;
if ( F_34 ( V_482 , & V_10 -> V_483 ) ) {
T_2 V_626 = V_576 ;
while ( ( F_190 ( & V_10 -> V_508 -> V_572 ) &
( V_574 | V_579 ) ) != 0 ) {
if ( -- V_626 == 0 )
break;
F_187 ( 1000 ) ;
}
if ( V_626 == 0 )
F_3 ( F_28 ( L_149
L_150 ,
V_10 -> V_452 , V_26 ) ) ;
F_195 ( V_10 , V_591 << 16 ) ;
if ( F_189 ( V_10 ) == V_41 ) {
F_204 ( V_10 , V_590 ) ;
V_349 = F_202 ( V_10 ) ;
}
F_199 ( V_482 , & V_10 -> V_483 ) ;
if ( V_349 == V_41 )
V_10 -> V_586 -> V_602 ( V_10 ) ;
}
}
V_625:
if ( F_225 ( V_567 , & V_10 -> V_483 ) )
F_204 ( V_10 , V_627 ) ;
if ( F_225 ( V_565 , & V_10 -> V_483 ) )
F_245 ( V_10 ) ;
if ( F_33 ( V_10 ) &&
F_225 ( V_555 , & V_10 -> V_483 ) ) {
F_141 ( V_10 -> V_180 , F_224 ) ;
}
if ( F_225 ( V_566 , & V_10 -> V_483 ) ) {
if ( ! F_34 ( V_261 , & V_10 -> V_119 ) ) {
F_140 ( V_10 ) ;
} else {
if ( F_225 ( V_182 , & V_10 -> V_119 ) ) {
F_246 ( V_10 , V_10 -> V_628 ) ;
F_141 ( V_10 -> V_180 ,
F_223 ) ;
} else
F_220 ( V_10 ) ;
}
}
}
static void F_247 ( struct V_9 * V_10 )
{
F_195 ( V_10 , V_478 << 16 ) ;
if ( F_34 ( V_629 , & V_10 -> V_119 ) ) {
V_10 -> V_586 -> V_589 ( V_10 ) ;
}
if ( V_10 -> V_464 )
F_136 ( V_10 ) ;
if ( V_10 -> V_606 )
F_248 ( V_10 -> V_606 ) ;
if ( V_10 -> V_630 )
F_248 ( V_10 -> V_630 ) ;
V_10 -> V_586 -> V_587 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
F_210 ( V_10 ) ;
F_249 ( V_10 ) ;
F_211 ( V_10 ) ;
}
if ( F_225 ( V_631 , & V_10 -> V_119 ) )
F_250 ( V_10 ) ;
F_152 ( V_10 ) ;
}
int F_251 ( struct V_9 * V_10 )
{
int V_349 = 0 ;
unsigned long V_632 , V_633 , V_634 , V_635 ;
struct V_636 * V_194 = V_10 -> V_194 ;
V_349 = F_252 ( V_194 , V_637 ) ;
if ( V_349 ) {
F_28 ( V_38
L_151
L_152 , V_10 -> V_452 , F_253 ( V_194 ) , V_349 ) ;
goto V_638;
}
F_3 ( F_28 ( V_25 L_153 ,
V_26 , V_194 -> V_639 ) ) ;
V_10 -> V_640 = V_194 -> V_639 ;
V_632 = F_254 ( V_194 , 0 ) ;
V_633 = F_255 ( V_194 , 0 ) ;
F_3 ( F_28 ( V_25 L_154 ,
V_26 , V_632 , V_633 ) ) ;
V_10 -> V_505 = ( unsigned long ) F_256 ( V_632 , V_633 ) ;
if ( ! V_10 -> V_505 ) {
F_28 ( V_147
L_155 , F_253 ( V_194 ) ) ;
F_157 ( V_10 -> V_194 ) ;
goto V_638;
}
V_10 -> V_641 =
(struct V_506 V_507 * ) ( ( T_2 * ) V_10 -> V_505 +
0xbc000 + ( V_10 -> V_194 -> V_642 << 11 ) ) ;
V_634 = F_254 ( V_194 , 4 ) ;
V_635 = F_255 ( V_194 , 4 ) ;
V_10 -> V_643 = ( V_10 -> V_194 -> V_642 == 4 ? V_644 :
V_645 ) ;
return 0 ;
V_638:
return - V_105 ;
}
int F_257 ( struct V_9 * V_10 )
{
unsigned long V_646 , V_647 , V_648 ;
unsigned long V_649 , V_650 , V_651 ;
V_646 = F_254 ( V_10 -> V_194 , 0 ) ;
V_647 = F_255 ( V_10 -> V_194 , 0 ) ;
V_648 = F_258 ( V_10 -> V_194 , 0 ) ;
if ( V_648 & V_652 ) {
if ( V_647 < V_653 ) {
F_4 ( V_38 , V_10 ,
L_156 ) ;
V_646 = 0 ;
}
} else {
F_4 ( V_38 , V_10 , L_157 ) ;
V_646 = 0 ;
}
V_649 = F_254 ( V_10 -> V_194 , 1 ) ;
V_650 = F_255 ( V_10 -> V_194 , 1 ) ;
V_651 = F_258 ( V_10 -> V_194 , 1 ) ;
if ( ! ( V_651 & V_654 ) ) {
F_4 ( V_147 , V_10 ,
L_158 ) ;
goto V_638;
}
if ( V_650 < V_653 ) {
F_4 ( V_147 , V_10 ,
L_159 ) ;
goto V_638;
}
if ( F_252 ( V_10 -> V_194 , V_637 ) ) {
F_4 ( V_38 , V_10 ,
L_160 ) ;
goto V_638;
}
V_10 -> V_655 = V_646 ;
V_10 -> V_656 = V_647 ;
V_10 -> V_508 = F_256 ( V_649 , V_653 ) ;
if ( ! V_10 -> V_508 ) {
F_4 ( V_147 , V_10 ,
L_161 ) ;
goto V_638;
}
return 0 ;
V_638:
return - V_105 ;
}
T_4 F_259 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_501 -> V_657 ) ;
}
T_4 F_260 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_193 ( & V_10 -> V_641 -> V_657 ) ) ;
}
T_4 F_261 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( V_10 -> V_501 -> V_658 ) ;
}
T_4 F_262 ( struct V_9 * V_10 )
{
return ( T_4 ) F_45 ( F_193 ( & V_10 -> V_641 -> V_658 ) ) ;
}
static T_8 F_263 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
char * V_659 = V_93 ;
int V_660 ;
switch ( type ) {
case V_661 :
V_660 = sprintf ( V_659 , L_25 , V_662 ) ;
break;
case V_663 :
V_660 = sprintf ( V_659 , L_162 ) ;
break;
case V_664 :
V_660 = F_56 ( V_659 , V_10 -> V_265 ,
V_266 ) ;
break;
default:
V_660 = - V_39 ;
break;
}
return V_660 ;
}
static T_3 F_264 ( void * V_127 , int type )
{
int V_660 ;
switch ( type ) {
case V_661 :
case V_664 :
case V_663 :
V_660 = V_54 ;
break;
default:
V_660 = 0 ;
break;
}
return V_660 ;
}
static T_8 F_265 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
char * V_659 = V_93 ;
int V_660 ;
switch ( type ) {
case V_665 :
V_660 = sprintf ( V_659 , L_17 , V_10 -> V_267 ) ;
break;
default:
V_660 = - V_39 ;
break;
}
return V_660 ;
}
static T_3 F_266 ( void * V_127 , int type )
{
int V_660 ;
switch ( type ) {
case V_665 :
V_660 = V_54 ;
break;
default:
V_660 = 0 ;
break;
}
return V_660 ;
}
static T_8
F_267 ( struct V_666 * V_667 , int type ,
char * V_93 )
{
struct V_668 * V_669 = & V_667 -> V_670 [ 0 ] ;
char * V_659 = V_93 ;
int V_660 ;
switch ( type ) {
case V_671 :
V_660 = sprintf ( V_93 , L_17 , ( char * ) & V_667 -> V_672 ) ;
break;
case V_673 :
if ( V_667 -> V_670 [ 0 ] . V_674 . V_675 == 0x1 )
V_660 = sprintf ( V_93 , L_16 ,
& V_669 -> V_674 . V_28 ) ;
else
V_660 = sprintf ( V_659 , L_22 ,
& V_669 -> V_674 . V_28 ) ;
break;
case V_676 :
V_660 = sprintf ( V_659 , L_25 , V_669 -> V_677 ) ;
break;
case V_678 :
V_660 = sprintf ( V_659 , L_163 ,
V_669 -> V_679 . V_680 ,
( char * ) & V_669 -> V_679 . V_681 ) ;
break;
case V_682 :
V_660 = sprintf ( V_659 , L_163 ,
V_669 -> V_679 . V_683 ,
( char * ) & V_669 -> V_679 . V_684 ) ;
break;
case V_685 :
V_660 = sprintf ( V_659 , L_163 ,
V_669 -> V_679 . V_686 ,
( char * ) & V_669 -> V_679 . V_687 ) ;
break;
case V_688 :
V_660 = sprintf ( V_659 , L_163 ,
V_669 -> V_679 . V_689 ,
( char * ) & V_669 -> V_679 . V_690 ) ;
break;
case V_691 :
V_660 = sprintf ( V_659 , L_25 , V_662 ) ;
break;
case V_692 :
V_660 = sprintf ( V_659 , L_162 ) ;
break;
default:
V_660 = - V_39 ;
break;
}
return V_660 ;
}
static T_8 F_268 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
struct V_666 * V_667 = & ( V_10 -> V_693 . V_694 ) ;
return F_267 ( V_667 , type , V_93 ) ;
}
static T_8 F_269 ( void * V_127 , int type , char * V_93 )
{
struct V_9 * V_10 = V_127 ;
struct V_666 * V_667 = & ( V_10 -> V_693 . V_695 ) ;
return F_267 ( V_667 , type , V_93 ) ;
}
static T_3 F_270 ( void * V_127 , int type )
{
int V_660 ;
switch ( type ) {
case V_671 :
case V_673 :
case V_676 :
case V_678 :
case V_682 :
case V_685 :
case V_688 :
case V_692 :
case V_691 :
V_660 = V_54 ;
break;
default:
V_660 = 0 ;
break;
}
return V_660 ;
}
static void F_271 ( void * V_127 )
{
struct V_9 * V_10 = V_127 ;
F_272 ( V_10 -> V_180 ) ;
}
static int F_273 ( struct V_9 * V_10 , T_4 V_335 [] )
{
T_5 V_696 ;
T_1 V_12 , V_697 , V_698 ;
T_1 V_137 ;
T_4 V_699 ;
T_2 V_700 ;
T_2 * V_93 = NULL ;
T_9 V_612 = 13 * sizeof( T_2 ) ;
int V_100 = V_41 ;
V_699 = F_274 ( V_10 -> V_194 -> V_642 ) ;
F_4 ( V_25 , V_10 , L_164 ,
V_26 , V_10 -> V_194 -> V_125 , V_699 ) ;
if ( F_20 ( V_10 ) ) {
if ( V_699 == 1 ) {
V_12 = V_701 ;
V_697 = V_702 ;
V_698 = V_703 ;
} else if ( V_699 == 3 ) {
V_12 = V_704 ;
V_697 = V_705 ;
V_698 = V_706 ;
} else {
V_100 = V_341 ;
goto V_707;
}
V_700 = F_275 ( V_10 , V_12 ) ;
if ( ! ( V_700 & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_165
L_166 , V_26 , V_700 ) ) ;
V_100 = V_341 ;
goto V_707;
}
V_700 = F_275 ( V_10 , V_697 ) ;
if ( V_700 & V_120 )
V_335 [ 0 ] = ( V_700 & 0x7f ) ;
V_700 = F_275 ( V_10 , V_698 ) ;
if ( V_700 & V_120 )
V_335 [ 1 ] = ( V_700 & 0x7f ) ;
} else if ( F_8 ( V_10 ) ) {
V_93 = F_42 ( & V_10 -> V_194 -> V_126 , V_612 ,
& V_696 , V_140 ) ;
if ( ! V_93 ) {
F_3 ( F_4 ( V_147 , V_10 ,
L_63 ,
V_26 ) ) ;
V_100 = V_341 ;
goto V_707;
}
if ( V_10 -> V_146 == 0 )
V_137 = V_708 ;
else if ( V_10 -> V_146 == 1 )
V_137 = V_709 ;
else {
V_100 = V_341 ;
goto V_710;
}
V_12 = V_144 + ( V_10 -> V_102 . V_711 * 4 ) +
V_137 ;
if ( F_21 ( V_10 , V_696 , V_12 ,
13 * sizeof( T_2 ) ) != V_41 ) {
F_3 ( F_4 ( V_147 , V_10 , L_167
L_168 , V_10 -> V_452 , V_26 ) ) ;
V_100 = V_341 ;
goto V_710;
}
if ( ! ( V_93 [ 1 ] & 0x07 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_169
L_170 , V_93 [ 1 ] ) ) ;
V_100 = V_341 ;
goto V_710;
}
if ( V_93 [ 2 ] & V_120 )
V_335 [ 0 ] = V_93 [ 2 ] & 0x7f ;
if ( V_93 [ 11 ] & V_120 )
V_335 [ 1 ] = V_93 [ 11 ] & 0x7f ;
} else {
V_100 = V_341 ;
goto V_707;
}
F_3 ( F_4 ( V_25 , V_10 , L_171
L_172 , V_26 , V_335 [ 0 ] ,
V_335 [ 1 ] ) ) ;
V_710:
F_46 ( & V_10 -> V_194 -> V_126 , V_612 , V_93 , V_696 ) ;
V_707:
V_10 -> V_712 = V_335 [ 0 ] ;
V_10 -> V_713 = V_335 [ 1 ] ;
return V_100 ;
}
static int F_276 ( struct V_9 * V_10 , char * V_111 ,
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
strncpy ( V_111 , V_95 -> V_112 , V_714 ) ;
V_100 = 0 ;
break;
}
F_11 ( & V_10 -> V_107 ) ;
return V_100 ;
}
static int F_277 ( struct V_9 * V_10 ,
struct V_666 * V_667 ,
T_4 V_335 )
{
struct V_668 * V_669 = & V_667 -> V_670 [ 0 ] ;
struct V_378 * V_350 ;
T_5 V_379 ;
T_4 V_327 ;
T_4 V_15 ;
int V_100 = V_41 ;
V_350 = F_42 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
& V_379 , V_140 ) ;
if ( ! V_350 ) {
F_3 ( F_4 ( V_147 , V_10 ,
L_174 ,
V_26 ) ) ;
V_100 = V_341 ;
return V_100 ;
}
if ( F_278 ( V_10 , V_350 ,
V_379 , V_335 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_175
L_176 , V_26 , V_335 ) ) ;
V_100 = V_341 ;
goto V_715;
}
memcpy ( V_667 -> V_672 , V_350 -> V_448 ,
F_131 ( sizeof( V_667 -> V_672 ) ,
sizeof( V_350 -> V_448 ) ) ) ;
V_15 = F_127 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 ) {
memcpy ( & V_669 -> V_674 . V_28 ,
& V_350 -> V_425 [ 0 ] , V_17 ) ;
} else {
V_669 -> V_674 . V_675 = 0x1 ;
memcpy ( & V_669 -> V_674 . V_28 ,
& V_350 -> V_425 [ 0 ] , V_24 ) ;
}
V_669 -> V_677 = F_127 ( V_350 -> V_445 ) ;
V_327 = F_22 ( V_350 -> V_91 ) ;
if ( V_120 & F_127 ( V_350 -> V_432 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_177 ) ) ;
V_100 = F_279 ( V_10 , ( char * ) & V_669 -> V_679 .
V_681 ,
( char * ) & V_669 -> V_679 . V_684 ,
V_327 ) ;
if ( V_100 ) {
F_4 ( V_147 , V_10 , L_178 ) ;
V_100 = V_341 ;
goto V_715;
}
V_669 -> V_679 . V_680 = V_714 ;
V_669 -> V_679 . V_683 = V_116 ;
}
if ( V_716 & F_127 ( V_350 -> V_432 ) ) {
F_3 ( F_4 ( V_25 , V_10 , L_179 ) ) ;
V_100 = F_276 ( V_10 ,
( char * ) & V_669 -> V_679 . V_687 ,
( char * ) & V_669 -> V_679 . V_690 ) ;
if ( V_100 ) {
F_4 ( V_147 , V_10 , L_180 ) ;
V_100 = V_341 ;
goto V_715;
}
V_669 -> V_679 . V_686 = V_714 ;
V_669 -> V_679 . V_689 = V_116 ;
}
V_715:
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( * V_350 ) ,
V_350 , V_379 ) ;
return V_100 ;
}
static int F_280 ( struct V_9 * V_10 )
{
T_4 V_335 [ 2 ] ;
int V_100 = V_341 ;
int V_18 ;
memset ( V_335 , 0 , sizeof( V_335 ) ) ;
V_335 [ 0 ] = 0xffff ;
V_335 [ 1 ] = 0xffff ;
V_100 = F_273 ( V_10 , V_335 ) ;
if ( V_100 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 ,
L_181 , V_26 ) ) ;
return V_100 ;
}
if ( V_717 )
return V_41 ;
if ( V_335 [ 0 ] == 0xffff )
goto V_718;
V_18 = F_277 ( V_10 , & ( V_10 -> V_693 . V_694 ) ,
V_335 [ 0 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_182
L_183 , V_26 ) ) ;
} else
V_100 = V_41 ;
V_718:
if ( V_335 [ 1 ] == 0xffff )
goto V_719;
V_18 = F_277 ( V_10 , & ( V_10 -> V_693 . V_695 ) ,
V_335 [ 1 ] ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_184
L_185 , V_26 ) ) ;
} else
V_100 = V_41 ;
V_719:
return V_100 ;
}
static int F_281 ( struct V_9 * V_10 )
{
struct V_720 * V_721 ;
if ( F_280 ( V_10 ) != V_41 )
return V_341 ;
if ( V_717 ) {
F_4 ( V_25 , V_10 ,
L_186
L_187 , V_26 ) ;
return V_41 ;
}
V_10 -> V_722 = F_282 ( V_10 -> V_180 -> V_452 ) ;
if ( ! V_10 -> V_722 )
goto V_723;
if ( ! F_283 ( V_10 -> V_180 ) )
goto V_723;
V_721 = F_284 ( V_10 -> V_722 , 0 , V_10 ,
F_268 ,
F_270 ,
F_271 ) ;
if ( ! V_721 )
goto V_724;
if ( ! F_283 ( V_10 -> V_180 ) )
goto V_723;
V_721 = F_284 ( V_10 -> V_722 , 1 , V_10 ,
F_269 ,
F_270 ,
F_271 ) ;
if ( ! V_721 )
goto V_724;
if ( ! F_283 ( V_10 -> V_180 ) )
goto V_723;
V_721 = F_285 ( V_10 -> V_722 , 0 , V_10 ,
F_265 ,
F_266 ,
F_271 ) ;
if ( ! V_721 )
goto V_724;
if ( ! F_283 ( V_10 -> V_180 ) )
goto V_723;
V_721 = F_286 ( V_10 -> V_722 , 0 , V_10 ,
F_263 ,
F_264 ,
F_271 ) ;
if ( ! V_721 )
goto V_724;
return V_41 ;
V_724:
F_272 ( V_10 -> V_180 ) ;
V_723:
F_287 ( V_10 -> V_722 ) ;
return - V_105 ;
}
static void F_288 ( struct V_9 * V_10 )
{
int V_18 = 0 ;
T_2 * V_725 = NULL ;
T_1 V_137 ;
T_5 V_136 ;
T_1 V_138 = 0 ;
if ( F_20 ( V_10 ) )
V_138 = V_104 *
sizeof( struct V_94 ) ;
else
V_138 = V_10 -> V_102 . V_103 / 2 ;
V_725 = F_42 ( & V_10 -> V_194 -> V_126 , V_138 ,
& V_136 , V_140 ) ;
if ( ! V_725 ) {
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
goto V_726;
if ( V_10 -> V_108 == NULL )
V_10 -> V_108 = F_289 ( V_138 ) ;
if ( V_10 -> V_108 == NULL ) {
F_4 ( V_147 , V_10 , L_189 ) ;
goto V_726;
}
memcpy ( V_10 -> V_108 , V_725 , V_138 ) ;
V_726:
F_46 ( & V_10 -> V_194 -> V_126 , V_138 ,
V_725 , V_136 ) ;
}
static void F_290 ( struct V_132 * V_132 ,
struct V_727 * V_728 )
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
V_728 -> V_446 = V_131 -> V_446 ;
V_728 -> V_445 = V_333 -> V_358 ;
strncpy ( V_728 -> V_448 , V_131 -> V_356 , V_729 ) ;
strncpy ( V_728 -> V_425 , V_333 -> V_357 , V_348 ) ;
}
static void F_291 ( struct V_378 * V_350 ,
struct V_727 * V_728 )
{
T_4 V_15 = 0 ;
V_728 -> V_446 = F_45 ( V_350 -> V_447 ) ;
memcpy ( & V_728 -> V_448 [ 0 ] , & V_350 -> V_448 [ 0 ] ,
F_131 ( sizeof( V_728 -> V_448 ) , sizeof( V_350 -> V_448 ) ) ) ;
V_15 = F_127 ( V_350 -> V_15 ) ;
if ( V_15 & V_351 )
sprintf ( V_728 -> V_425 , L_56 , V_350 -> V_425 ) ;
else
sprintf ( V_728 -> V_425 , L_57 , V_350 -> V_425 ) ;
V_728 -> V_445 = F_127 ( V_350 -> V_445 ) ;
memcpy ( & V_728 -> V_730 [ 0 ] , & V_350 -> V_730 [ 0 ] , sizeof( V_728 -> V_730 ) ) ;
}
static int F_292 ( struct V_9 * V_10 ,
struct V_727 * V_731 ,
struct V_727 * V_732 ,
T_2 V_733 )
{
if ( strcmp ( V_731 -> V_448 , V_732 -> V_448 ) )
return V_341 ;
if ( strcmp ( V_731 -> V_425 , V_732 -> V_425 ) )
return V_341 ;
if ( V_731 -> V_445 != V_732 -> V_445 )
return V_341 ;
if ( V_733 ) {
F_3 ( F_4 ( V_25 , V_10 , L_190
L_191 ,
V_26 , V_731 -> V_730 [ 5 ] , V_731 -> V_730 [ 4 ] ,
V_731 -> V_730 [ 3 ] , V_731 -> V_730 [ 2 ] , V_731 -> V_730 [ 1 ] ,
V_731 -> V_730 [ 0 ] , V_732 -> V_730 [ 5 ] , V_732 -> V_730 [ 4 ] ,
V_732 -> V_730 [ 3 ] , V_732 -> V_730 [ 2 ] , V_732 -> V_730 [ 1 ] ,
V_732 -> V_730 [ 0 ] ) ) ;
if ( memcmp ( & V_731 -> V_730 [ 0 ] , & V_732 -> V_730 [ 0 ] ,
sizeof( V_731 -> V_730 ) ) )
return V_341 ;
}
F_3 ( F_4 ( V_25 , V_10 ,
L_192 ,
V_731 -> V_445 , V_731 -> V_446 , V_731 -> V_425 ,
V_731 -> V_448 , V_732 -> V_445 , V_732 -> V_446 ,
V_732 -> V_425 , V_732 -> V_448 ) ) ;
return V_41 ;
}
static int F_293 ( struct V_9 * V_10 ,
struct V_378 * V_350 )
{
struct V_132 * V_132 ;
struct V_727 * V_734 = NULL ;
struct V_727 * V_735 = NULL ;
int V_327 ;
int V_100 = V_341 ;
V_734 = F_294 ( sizeof( * V_734 ) ) ;
if ( ! V_734 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_736;
}
V_735 = F_294 ( sizeof( * V_735 ) ) ;
if ( ! V_735 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_736;
}
F_291 ( V_350 , V_734 ) ;
for ( V_327 = 0 ; V_327 < V_340 ; V_327 ++ ) {
V_132 = F_94 ( V_10 , V_327 ) ;
if ( V_132 == NULL )
continue;
F_290 ( V_132 , V_735 ) ;
if ( ! F_292 ( V_10 , V_734 , V_735 , false ) ) {
V_100 = V_41 ;
goto V_736;
}
}
V_736:
if ( V_734 )
F_153 ( V_734 ) ;
if ( V_735 )
F_153 ( V_735 ) ;
return V_100 ;
}
static int F_295 ( struct V_9 * V_10 ,
struct V_737 * V_738 ,
struct V_378 * V_350 )
{
struct V_739 * V_740 , * V_741 ;
struct V_727 * V_734 = NULL ;
struct V_727 * V_735 = NULL ;
int V_100 = V_341 ;
V_734 = F_294 ( sizeof( * V_734 ) ) ;
if ( ! V_734 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_736;
}
V_735 = F_294 ( sizeof( * V_735 ) ) ;
if ( ! V_735 ) {
F_3 ( F_4 ( V_38 , V_10 ,
L_193 ) ) ;
V_100 = V_41 ;
goto V_736;
}
F_291 ( V_350 , V_734 ) ;
F_237 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
F_291 ( & V_740 -> V_742 , V_735 ) ;
if ( ! F_292 ( V_10 , V_734 , V_735 , true ) ) {
V_100 = V_41 ;
goto V_736;
}
}
V_736:
if ( V_734 )
F_153 ( V_734 ) ;
if ( V_735 )
F_153 ( V_735 ) ;
return V_100 ;
}
static void F_296 ( struct V_737 * V_743 )
{
struct V_739 * V_744 , * V_745 ;
F_237 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
F_238 ( & V_744 -> V_613 ) ;
F_153 ( V_744 ) ;
}
}
static struct V_174 * F_297 ( struct V_9 * V_10 ,
struct V_378 * V_350 )
{
struct V_174 * V_176 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_7 * V_8 ;
char * V_746 ;
V_8 = F_289 ( sizeof( * V_8 ) ) ;
if ( ! V_8 )
return NULL ;
if ( V_350 -> V_15 & V_351 ) {
V_8 -> V_20 = V_31 ;
V_14 = (struct V_13 * ) V_8 ;
V_746 = ( char * ) & V_14 -> V_32 ;
memcpy ( V_746 , V_350 -> V_425 , V_17 ) ;
V_14 -> V_747 = F_298 ( F_127 ( V_350 -> V_445 ) ) ;
} else {
V_8 -> V_20 = V_21 ;
V_12 = (struct V_11 * ) V_8 ;
V_746 = ( char * ) & V_12 -> V_22 ;
memcpy ( V_746 , V_350 -> V_425 , V_24 ) ;
V_12 -> V_748 = F_298 ( F_127 ( V_350 -> V_445 ) ) ;
}
V_176 = F_27 ( V_10 -> V_180 , V_8 , 0 ) ;
F_153 ( V_8 ) ;
return V_176 ;
}
static int F_299 ( struct V_9 * V_10 , T_4 V_327 )
{
if ( V_717 )
return V_41 ;
if ( V_327 == V_10 -> V_712 || V_327 == V_10 -> V_713 )
return V_341 ;
return V_41 ;
}
static void F_300 ( struct V_9 * V_10 ,
struct V_132 * V_132 )
{
T_4 V_455 ;
V_132 -> V_361 = V_362 ;
V_132 -> V_196 = V_554 ;
V_132 -> V_367 = V_368 ;
V_132 -> V_10 = V_10 ;
V_132 -> V_369 = F_216 ;
V_132 -> V_371 = V_749 ;
F_175 ( & V_132 -> V_553 , V_554 ) ;
F_175 ( & V_132 -> V_556 , 0 ) ;
F_175 ( & V_132 -> V_557 , 0 ) ;
V_455 = F_127 ( V_132 -> V_350 . V_455 ) ;
V_132 -> V_454 =
( V_455 > V_456 ) && ( V_455 < V_456 * 10 ) ?
V_455 : V_456 ;
V_132 -> V_457 =
F_127 ( V_132 -> V_350 . V_442 ) ;
}
static void F_301 ( struct V_9 * V_10 )
{
T_1 V_327 = 0 ;
T_1 V_750 [ V_751 ] = { 0 , 1 , 2 , 3 } ;
T_1 V_399 [ V_316 ] ;
T_1 V_752 ;
unsigned long V_377 ;
int V_100 ;
V_377 = V_382 + ( V_326 * V_753 ) ;
do {
for ( V_327 = 0 ; V_327 < V_751 ; V_327 ++ ) {
if ( V_750 [ V_327 ] == - 1 )
continue;
V_100 = F_302 ( V_10 , 0 , V_750 [ V_327 ] , V_399 ) ;
if ( V_100 == V_341 ) {
V_750 [ V_327 ] = - 1 ;
continue;
}
V_752 = ( V_399 [ 1 ] & V_754 ) >> V_755 ;
F_3 ( F_4 ( V_25 , V_10 ,
L_194 ,
V_750 [ V_327 ] , V_752 ) ) ;
if ( V_752 == V_756 ||
V_752 == V_757 ||
V_752 == V_758 ||
V_752 == V_759 ||
V_752 == V_760 )
V_750 [ V_327 ] = - 1 ;
}
if ( ( V_750 [ 0 ] == - 1 ) &&
( V_750 [ 1 ] == - 1 ) &&
( V_750 [ 2 ] == - 1 ) &&
( V_750 [ 3 ] == - 1 ) )
break;
F_99 ( V_326 ) ;
} while ( F_100 ( V_377 , V_382 ) );
}
static void F_303 ( struct V_9 * V_10 ,
struct V_737 * V_761 )
{
struct V_739 * V_762 ;
int V_353 ;
int V_763 ;
struct V_378 * V_350 ;
T_5 V_764 ;
int V_100 ;
T_1 V_327 = 0 , V_765 = 0 ;
T_1 V_242 = 0 , V_766 = 0 ;
T_4 V_767 = 0 ;
V_350 = F_19 ( V_10 -> V_504 , V_140 ,
& V_764 ) ;
if ( V_350 == NULL ) {
F_3 ( F_4 ( V_147 , V_10 , L_195 ) ) ;
goto V_768;
}
V_353 = F_20 ( V_10 ) ? V_359 :
V_360 ;
V_763 = sizeof( struct V_739 ) ;
for ( V_327 = 0 ; V_327 < V_353 ; V_327 = V_765 ) {
V_100 = F_98 ( V_10 , V_327 , V_350 , V_764 ,
NULL , & V_765 , & V_242 ,
& V_766 , NULL , & V_767 ) ;
if ( V_100 == V_341 )
break;
if ( V_242 == V_769 )
goto V_770;
if ( strlen ( ( char * ) V_350 -> V_448 ) != 0 )
goto V_770;
V_762 = F_294 ( V_763 ) ;
if ( ! V_762 )
break;
V_762 -> V_771 = V_327 ;
F_231 ( & V_762 -> V_613 , V_761 ) ;
V_770:
if ( V_765 == 0 )
break;
}
V_768:
if ( V_350 )
F_24 ( V_10 -> V_504 , V_350 , V_764 ) ;
}
static void F_304 ( struct V_9 * V_10 ,
struct V_737 * V_743 )
{
struct V_739 * V_744 , * V_745 ;
T_1 V_765 = 0 ;
T_1 V_242 = 0 , V_766 = 0 ;
int V_100 ;
F_237 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
V_100 = F_98 ( V_10 , V_744 -> V_771 ,
NULL , 0 , NULL , & V_765 , & V_242 ,
& V_766 , NULL , NULL ) ;
if ( V_100 == V_341 )
continue;
if ( V_242 == V_368 ||
V_242 == V_384 ) {
F_238 ( & V_744 -> V_613 ) ;
F_153 ( V_744 ) ;
}
}
}
static int F_305 ( struct V_9 * V_10 ,
struct V_378 * V_350 ,
int V_628 )
{
struct V_128 * V_190 ;
struct V_130 * V_131 ;
struct V_186 * V_187 ;
struct V_174 * V_176 ;
T_4 V_363 = 32 ;
T_4 V_767 = 0 ;
T_1 V_365 = 0 ;
int V_100 = V_41 ;
struct V_132 * V_132 = NULL ;
V_190 = F_96 ( & V_269 , V_10 -> V_180 ,
V_363 , sizeof( struct V_132 ) ,
sizeof( struct V_366 ) ,
V_365 , V_554 ) ;
if ( ! V_190 ) {
V_100 = V_341 ;
goto V_772;
}
F_306 ( V_269 . V_773 ) ;
V_131 = V_190 -> V_134 ;
V_132 = V_131 -> V_134 ;
V_132 -> V_131 = V_190 ;
V_190 -> V_373 = V_374 ;
memcpy ( & V_132 -> V_350 , V_350 ,
sizeof( struct V_378 ) ) ;
F_300 ( V_10 , V_132 ) ;
V_187 = F_105 ( V_190 , sizeof( struct V_334 ) , V_767 ) ;
if ( ! V_187 ) {
V_100 = V_341 ;
goto V_772;
}
V_132 -> V_333 = V_187 ;
V_176 = F_297 ( V_10 , V_350 ) ;
if ( V_176 ) {
V_176 -> V_333 = V_187 ;
V_187 -> V_176 = V_176 ;
} else {
F_3 ( F_4 ( V_147 , V_10 , L_196 ) ) ;
V_100 = V_341 ;
goto V_772;
}
F_126 ( V_10 , V_350 , V_190 , V_187 ) ;
if ( V_628 == V_596 ) {
F_139 ( V_190 ) ;
F_168 ( V_555 , & V_10 -> V_483 ) ;
F_168 ( V_552 , & V_132 -> V_119 ) ;
}
V_772:
return V_100 ;
}
static void F_307 ( struct V_9 * V_10 ,
struct V_737 * V_738 , int V_628 )
{
struct V_378 * V_350 ;
T_5 V_764 ;
int V_353 ;
int V_763 ;
int V_100 ;
T_1 V_327 = 0 , V_765 = 0 ;
T_1 V_242 = 0 , V_766 = 0 ;
T_4 V_767 = 0 ;
struct V_739 * V_740 ;
V_350 = F_19 ( V_10 -> V_504 , V_140 ,
& V_764 ) ;
if ( V_350 == NULL ) {
F_3 ( F_4 ( V_147 , V_10 , L_195 ) ) ;
goto V_774;
}
V_353 = F_20 ( V_10 ) ? V_359 :
V_360 ;
V_763 = sizeof( struct V_739 ) ;
for ( V_327 = 0 ; V_327 < V_353 ; V_327 = V_765 ) {
V_100 = F_98 ( V_10 , V_327 , V_350 , V_764 ,
NULL , & V_765 , & V_242 ,
& V_766 , NULL , & V_767 ) ;
if ( V_100 == V_341 )
break;
if ( F_299 ( V_10 , V_327 ) != V_41 )
goto V_775;
if ( strlen ( ( char * ) V_350 -> V_448 ) == 0 )
goto V_775;
if ( ! ( V_242 == V_368 ||
V_242 == V_384 ) )
goto V_775;
F_3 ( F_4 ( V_25 , V_10 ,
L_197 , V_327 ) ) ;
if ( V_628 == V_776 ) {
V_740 = F_289 ( V_763 ) ;
if ( ! V_740 )
break;
V_740 -> V_771 = V_327 ;
memcpy ( & V_740 -> V_742 , V_350 ,
sizeof( struct V_378 ) ) ;
if ( F_295 ( V_10 , V_738 ,
V_350 ) == V_41 ) {
F_153 ( V_740 ) ;
goto V_775;
}
F_231 ( & V_740 -> V_613 , V_738 ) ;
} else if ( V_628 == V_596 ) {
if ( F_293 ( V_10 , V_350 ) ==
V_41 )
goto V_775;
}
V_100 = F_305 ( V_10 , V_350 , V_628 ) ;
if ( V_100 == V_341 )
goto V_774;
V_775:
if ( V_765 == 0 )
break;
}
V_774:
if ( V_350 )
F_24 ( V_10 -> V_504 , V_350 , V_764 ) ;
}
void F_246 ( struct V_9 * V_10 , int V_628 )
{
T_4 V_777 = 0 ;
struct V_737 V_761 , V_738 ;
struct V_739 * V_762 , * V_778 ;
unsigned long V_377 ;
if ( ! F_34 ( V_261 , & V_10 -> V_119 ) ) {
F_168 ( V_182 , & V_10 -> V_119 ) ;
V_10 -> V_628 = V_628 ;
return;
}
F_229 ( & V_761 ) ;
F_229 ( & V_738 ) ;
F_303 ( V_10 , & V_761 ) ;
F_301 ( V_10 ) ;
F_237 (st_ddb_idx, st_ddb_idx_tmp, &list_st, list) {
F_111 ( V_10 , V_762 -> V_771 ) ;
}
V_777 = ( ( V_10 -> V_455 > V_456 ) &&
( V_10 -> V_455 < V_456 * 10 ) ?
V_10 -> V_455 : V_456 ) ;
F_3 ( F_4 ( V_25 , V_10 ,
L_198 , V_777 ) ) ;
V_377 = V_382 + ( V_326 * V_777 ) ;
do {
if ( F_183 ( & V_761 ) )
break;
F_304 ( V_10 , & V_761 ) ;
F_99 ( V_326 / 10 ) ;
} while ( F_100 ( V_377 , V_382 ) );
F_296 ( & V_761 ) ;
F_307 ( V_10 , & V_738 , V_628 ) ;
F_296 ( & V_738 ) ;
F_308 ( V_10 ) ;
}
static int T_10 F_309 ( struct V_636 * V_194 ,
const struct V_779 * V_780 )
{
int V_100 = - V_781 , V_349 ;
struct V_1 * V_180 ;
struct V_9 * V_10 ;
T_2 V_782 = 0 ;
char V_93 [ 34 ] ;
struct V_783 * V_784 ;
T_1 V_541 ;
if ( F_310 ( V_194 ) )
return - 1 ;
V_180 = F_311 ( & V_785 , sizeof( * V_10 ) , 0 ) ;
if ( V_180 == NULL ) {
F_28 ( V_38
L_199 ) ;
goto V_786;
}
V_10 = F_2 ( V_180 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_194 = V_194 ;
V_10 -> V_180 = V_180 ;
V_10 -> V_452 = V_180 -> V_452 ;
F_312 ( V_194 ) ;
if ( F_8 ( V_10 ) ) {
V_10 -> V_586 = & V_787 ;
F_313 ( & V_10 -> V_788 ) ;
V_10 -> V_789 = - 1 ;
V_10 -> V_790 = - 1 ;
V_10 -> V_791 = 255 ;
V_10 -> V_699 = F_274 ( V_10 -> V_194 -> V_642 ) ;
V_784 = & V_792 [ V_10 -> V_699 ] ;
V_10 -> V_784 . V_793 = V_784 -> V_793 ;
V_10 -> V_784 . V_794 =
V_784 -> V_794 ;
V_10 -> V_784 . V_795 = V_784 -> V_795 ;
V_10 -> V_784 . V_796 = V_784 -> V_796 ;
} else {
V_10 -> V_586 = & V_797 ;
}
if ( F_8 ( V_10 ) )
V_194 -> V_798 = 1 ;
V_100 = V_10 -> V_586 -> V_799 ( V_10 ) ;
if ( V_100 )
goto V_800;
F_4 ( V_25 , V_10 , L_200 ,
V_194 -> V_125 , V_194 -> V_801 , V_10 -> V_508 ) ;
F_314 ( V_10 ) ;
F_229 ( & V_10 -> V_802 ) ;
F_315 ( & V_10 -> V_803 ) ;
F_315 ( & V_10 -> V_107 ) ;
F_316 ( & V_10 -> V_804 ) ;
F_316 ( & V_10 -> V_324 ) ;
F_317 ( & V_10 -> V_385 ) ;
F_229 ( & V_10 -> V_564 ) ;
if ( F_158 ( V_10 ) ) {
F_4 ( V_38 , V_10 ,
L_201 ) ;
V_100 = - V_105 ;
goto V_805;
}
V_180 -> V_806 = 3 ;
V_180 -> V_807 = 0 ;
V_180 -> V_808 = V_809 - 1 ;
V_180 -> V_810 = V_811 ;
V_180 -> V_812 = V_813 ;
V_180 -> V_571 = V_814 ;
V_180 -> V_815 = V_816 ;
V_100 = F_318 ( V_180 , V_814 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 ,
L_202 , V_26 ) ;
goto V_805;
}
F_319 ( V_194 , V_10 ) ;
V_100 = F_320 ( V_180 , & V_194 -> V_126 ) ;
if ( V_100 )
goto V_805;
if ( F_8 ( V_10 ) )
( void ) F_321 ( V_10 ) ;
V_349 = F_209 ( V_10 , V_776 ) ;
while ( ( ! F_34 ( V_488 , & V_10 -> V_119 ) ) &&
V_782 ++ < V_817 ) {
if ( F_8 ( V_10 ) ) {
F_210 ( V_10 ) ;
V_541 = F_162 ( V_10 , V_544 ) ;
F_211 ( V_10 ) ;
if ( V_541 == V_597 ) {
F_4 ( V_38 , V_10 , L_124
L_203 ,
V_26 ) ;
break;
}
}
F_3 ( F_28 ( L_204
L_205 , V_26 , V_782 ) ) ;
if ( V_10 -> V_586 -> V_583 ( V_10 ) == V_341 )
continue;
V_349 = F_209 ( V_10 , V_776 ) ;
}
if ( ! F_34 ( V_488 , & V_10 -> V_119 ) ) {
F_4 ( V_38 , V_10 , L_206 ) ;
if ( F_8 ( V_10 ) && V_549 ) {
F_3 ( F_28 ( V_147 L_207 ) ) ;
F_210 ( V_10 ) ;
F_167 ( V_10 , V_544 ,
V_597 ) ;
F_211 ( V_10 ) ;
}
V_100 = - V_781 ;
goto V_818;
}
F_3 ( F_28 ( L_208
L_209 , V_26 ) ) ;
sprintf ( V_93 , L_210 , V_10 -> V_452 ) ;
V_10 -> V_606 = F_322 ( V_93 ) ;
if ( ! V_10 -> V_606 ) {
F_4 ( V_38 , V_10 , L_211 ) ;
V_100 = - V_781 ;
goto V_818;
}
F_121 ( & V_10 -> V_607 , F_242 ) ;
sprintf ( V_93 , L_212 , V_10 -> V_452 ) ;
V_10 -> V_630 = F_323 ( V_93 , V_819 , 1 ) ;
if ( ! V_10 -> V_630 ) {
F_4 ( V_38 , V_10 , L_213 ) ;
V_100 = - V_781 ;
goto V_818;
}
if ( ! F_8 ( V_10 ) ) {
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_214
L_215 , V_194 -> V_801 ) ;
goto V_818;
}
}
F_325 ( V_10 -> V_194 ) ;
V_10 -> V_586 -> V_602 ( V_10 ) ;
F_132 ( V_10 , F_179 , 1 ) ;
F_168 ( V_581 , & V_10 -> V_119 ) ;
F_326 ( V_10 ) ;
F_28 ( V_25
L_216
L_217 ,
V_820 , V_10 -> V_194 -> V_125 , F_253 ( V_10 -> V_194 ) ,
V_10 -> V_452 , V_10 -> V_821 [ 0 ] , V_10 -> V_821 [ 1 ] ,
V_10 -> V_822 , V_10 -> V_823 ) ;
if ( F_281 ( V_10 ) )
F_4 ( V_147 , V_10 ,
L_218 , V_26 ) ;
F_246 ( V_10 , V_776 ) ;
F_141 ( V_10 -> V_180 , F_223 ) ;
F_288 ( V_10 ) ;
F_62 ( V_10 ) ;
return 0 ;
V_818:
F_327 ( V_10 -> V_180 ) ;
V_805:
F_247 ( V_10 ) ;
V_800:
F_328 ( V_194 ) ;
F_272 ( V_10 -> V_180 ) ;
V_786:
F_329 ( V_194 ) ;
return V_100 ;
}
static void F_330 ( struct V_9 * V_10 )
{
struct V_9 * V_824 = NULL ;
struct V_636 * V_825 = NULL ;
int V_826 = V_827 ;
if ( F_274 ( V_10 -> V_194 -> V_642 ) & V_828 )
V_826 = V_829 ;
V_825 =
F_331 ( F_332 ( V_10 -> V_194 -> V_830 ) ,
V_10 -> V_194 -> V_830 -> V_831 , F_333 ( F_334 ( V_10 -> V_194 -> V_642 ) ,
V_826 ) ) ;
if ( V_825 ) {
if ( F_174 ( & V_825 -> V_832 ) ) {
V_824 = F_335 ( V_825 ) ;
if ( V_824 ) {
F_168 ( V_833 , & V_824 -> V_119 ) ;
F_3 ( F_4 ( V_25 , V_10 , L_219
L_220 , V_26 ,
F_336 ( & V_824 -> V_194 -> V_126 ) ) ) ;
}
}
F_337 ( V_825 ) ;
}
}
static void F_338 ( struct V_9 * V_10 )
{
struct V_132 * V_132 ;
int V_15 ;
int V_327 ;
for ( V_327 = 0 ; V_327 < V_340 ; V_327 ++ ) {
V_132 = F_94 ( V_10 , V_327 ) ;
if ( ( V_132 != NULL ) &&
( V_132 -> V_361 == V_362 ) ) {
V_15 = V_394 ;
if ( F_113 ( V_10 , V_132 , V_15 )
== V_341 )
F_4 ( V_147 , V_10 , L_68 ,
V_26 ) ;
F_101 ( V_10 , V_132 -> V_196 ) ;
F_339 ( V_269 . V_773 ) ;
F_36 ( V_132 -> V_333 -> V_176 ) ;
F_102 ( V_10 , V_132 ) ;
F_103 ( V_132 -> V_131 ) ;
}
}
}
static void T_11 F_340 ( struct V_636 * V_194 )
{
struct V_9 * V_10 ;
V_10 = F_335 ( V_194 ) ;
if ( ! F_8 ( V_10 ) )
F_330 ( V_10 ) ;
F_66 ( V_10 ) ;
if ( ( ! V_717 ) && V_10 -> V_722 )
F_287 ( V_10 -> V_722 ) ;
F_338 ( V_10 ) ;
F_341 ( V_10 ) ;
F_327 ( V_10 -> V_180 ) ;
F_247 ( V_10 ) ;
F_272 ( V_10 -> V_180 ) ;
F_328 ( V_194 ) ;
F_329 ( V_194 ) ;
F_319 ( V_194 , NULL ) ;
}
static void F_314 ( struct V_9 * V_10 )
{
int V_834 ;
if ( F_342 ( V_10 -> V_194 , F_343 ( 64 ) ) == 0 ) {
if ( F_344 ( V_10 -> V_194 , F_343 ( 64 ) ) ) {
F_345 ( & V_10 -> V_194 -> V_126 ,
L_221
L_222 ) ;
V_834 = F_344 ( V_10 -> V_194 ,
F_343 ( 32 ) ) ;
}
} else
V_834 = F_342 ( V_10 -> V_194 , F_343 ( 32 ) ) ;
}
static int F_346 ( struct V_835 * V_836 )
{
struct V_128 * V_190 ;
struct V_130 * V_131 ;
struct V_132 * V_469 ;
int V_837 = V_838 ;
V_190 = F_48 ( V_836 -> V_839 ) ;
V_131 = V_190 -> V_134 ;
V_469 = V_131 -> V_134 ;
V_836 -> V_474 = V_469 ;
V_836 -> V_840 = 1 ;
if ( V_841 != 0 && V_841 <= 0xffffU )
V_837 = V_841 ;
F_347 ( V_836 , V_837 ) ;
return 0 ;
}
static int F_348 ( struct V_835 * V_836 )
{
V_836 -> V_840 = 1 ;
return 0 ;
}
static void F_349 ( struct V_835 * V_836 )
{
F_350 ( V_836 , 1 ) ;
}
static int F_351 ( struct V_835 * V_836 , int V_364 ,
int V_842 )
{
if ( ! V_843 )
return - V_844 ;
return F_352 ( V_836 , V_364 , V_842 ) ;
}
struct V_465 * F_196 ( struct V_9 * V_10 ,
T_1 V_569 )
{
struct V_465 * V_465 = NULL ;
struct V_237 * V_466 = NULL ;
V_466 = F_186 ( V_10 -> V_180 , V_569 ) ;
if ( ! V_466 )
return V_465 ;
V_465 = (struct V_465 * ) F_145 ( V_466 ) ;
if ( ! V_465 )
return V_465 ;
if ( V_465 -> V_119 & V_470 ) {
V_10 -> V_845 += V_465 -> V_846 ;
V_10 -> V_846 -= V_465 -> V_846 ;
if ( V_465 -> V_466 )
V_465 -> V_466 -> V_847 =
( unsigned char * ) ( unsigned long ) V_814 ;
}
return V_465 ;
}
static int F_353 ( struct V_9 * V_10 ,
struct V_237 * V_466 )
{
int V_848 = 0 ;
struct V_465 * V_849 ;
T_1 V_575 = V_850 ;
int V_100 = V_851 ;
if ( F_354 ( F_181 ( V_10 -> V_194 ) ) ||
( F_34 ( V_475 , & V_10 -> V_119 ) ) ) {
F_4 ( V_38 , V_10 , L_223 ,
V_10 -> V_452 , V_26 ) ;
return V_100 ;
}
do {
V_849 = (struct V_465 * ) F_145 ( V_466 ) ;
if ( V_849 == NULL ) {
V_848 ++ ;
break;
}
F_187 ( 2000 ) ;
} while ( V_575 -- );
return V_848 ;
}
static int F_355 ( struct V_9 * V_10 )
{
unsigned long V_852 ;
V_852 = V_382 + ( V_853 * V_326 ) ;
while ( F_205 ( V_382 , V_852 ) ) {
if ( F_33 ( V_10 ) )
return V_41 ;
F_187 ( 2000 ) ;
}
return V_341 ;
}
static int F_356 ( struct V_9 * V_10 ,
struct F_49 * V_854 ,
struct V_835 * V_836 )
{
int V_855 ;
int V_349 = 0 ;
struct V_237 * V_466 ;
for ( V_855 = 0 ; V_855 < V_10 -> V_180 -> V_571 ; V_855 ++ ) {
V_466 = F_186 ( V_10 -> V_180 , V_855 ) ;
if ( V_466 && V_854 == F_49 ( V_466 -> V_125 ) &&
( ! V_836 || V_836 == V_466 -> V_125 ) ) {
if ( ! F_353 ( V_10 , V_466 ) ) {
V_349 ++ ;
break;
}
}
}
return V_349 ;
}
static int F_357 ( struct V_237 * V_466 )
{
struct V_9 * V_10 = F_2 ( V_466 -> V_125 -> V_180 ) ;
unsigned int V_856 = V_466 -> V_125 -> V_856 ;
unsigned int V_857 = V_466 -> V_125 -> V_857 ;
unsigned long V_119 ;
struct V_465 * V_465 = NULL ;
int V_100 = V_851 ;
int V_584 = 0 ;
F_4 ( V_25 , V_10 ,
L_224 ,
V_10 -> V_452 , V_856 , V_857 , V_466 ) ;
F_50 ( & V_10 -> V_385 , V_119 ) ;
V_465 = (struct V_465 * ) F_145 ( V_466 ) ;
if ( ! V_465 ) {
F_51 ( & V_10 -> V_385 , V_119 ) ;
return V_851 ;
}
F_358 ( & V_465 -> V_468 ) ;
F_51 ( & V_10 -> V_385 , V_119 ) ;
if ( F_359 ( V_10 , V_465 ) != V_41 ) {
F_116 ( F_28 ( L_225 ,
V_10 -> V_452 , V_856 , V_857 ) ) ;
V_100 = V_858 ;
} else {
F_116 ( F_28 ( L_226 ,
V_10 -> V_452 , V_856 , V_857 ) ) ;
V_584 = 1 ;
}
F_197 ( & V_465 -> V_468 , F_148 ) ;
if ( V_584 ) {
if ( ! F_353 ( V_10 , V_466 ) ) {
F_3 ( F_28 ( L_227 ,
V_10 -> V_452 , V_856 , V_857 ) ) ;
V_100 = V_858 ;
}
}
F_4 ( V_25 , V_10 ,
L_228 ,
V_10 -> V_452 , V_856 , V_857 , ( V_100 == V_851 ) ? L_229 : L_230 ) ;
return V_100 ;
}
static int F_360 ( struct V_237 * V_466 )
{
struct V_9 * V_10 = F_2 ( V_466 -> V_125 -> V_180 ) ;
struct V_132 * V_132 = V_466 -> V_125 -> V_474 ;
int V_100 = V_858 , V_859 ;
if ( ! V_132 )
return V_100 ;
V_100 = F_361 ( V_466 ) ;
if ( V_100 )
return V_100 ;
V_100 = V_858 ;
F_4 ( V_25 , V_10 ,
L_231 , V_10 -> V_452 ,
V_466 -> V_125 -> V_860 , V_466 -> V_125 -> V_856 , V_466 -> V_125 -> V_857 ) ;
F_3 ( F_28 ( V_25
L_232
L_233 , V_10 -> V_452 ,
V_466 , V_382 , V_466 -> V_861 -> V_862 / V_326 ,
V_10 -> V_483 , V_466 -> V_477 , V_466 -> V_863 ) ) ;
V_859 = F_362 ( V_10 , V_132 , V_466 -> V_125 -> V_857 ) ;
if ( V_859 != V_41 ) {
F_4 ( V_25 , V_10 , L_234 , V_859 ) ;
goto V_864;
}
if ( F_356 ( V_10 , F_49 ( V_466 -> V_125 ) ,
V_466 -> V_125 ) ) {
F_4 ( V_25 , V_10 ,
L_235
L_236 ) ;
goto V_864;
}
if ( F_363 ( V_10 , V_132 , V_466 -> V_125 -> V_857 ,
V_865 ) != V_41 )
goto V_864;
F_4 ( V_25 , V_10 ,
L_237 ,
V_10 -> V_452 , V_466 -> V_125 -> V_860 , V_466 -> V_125 -> V_856 ,
V_466 -> V_125 -> V_857 ) ;
V_100 = V_851 ;
V_864:
return V_100 ;
}
static int F_364 ( struct V_237 * V_466 )
{
struct V_9 * V_10 = F_2 ( V_466 -> V_125 -> V_180 ) ;
struct V_132 * V_132 = V_466 -> V_125 -> V_474 ;
int V_859 , V_100 ;
if ( ! V_132 )
return V_858 ;
V_100 = F_361 ( V_466 ) ;
if ( V_100 )
return V_100 ;
F_365 ( V_25 , F_49 ( V_466 -> V_125 ) ,
L_238 ) ;
F_3 ( F_28 ( V_25
L_239
L_240 ,
V_10 -> V_452 , V_466 , V_382 , V_466 -> V_861 -> V_862 / V_326 ,
V_10 -> V_483 , V_466 -> V_477 , V_466 -> V_863 ) ) ;
V_859 = F_366 ( V_10 , V_132 ) ;
if ( V_859 != V_41 ) {
F_365 ( V_25 , F_49 ( V_466 -> V_125 ) ,
L_241 ) ;
return V_858 ;
}
if ( F_356 ( V_10 , F_49 ( V_466 -> V_125 ) ,
NULL ) ) {
F_365 ( V_25 , F_49 ( V_466 -> V_125 ) ,
L_242
L_243 ) ;
return V_858 ;
}
if ( F_363 ( V_10 , V_132 , V_466 -> V_125 -> V_857 ,
V_866 ) != V_41 ) {
F_365 ( V_25 , F_49 ( V_466 -> V_125 ) ,
L_242
L_244 ) ;
return V_858 ;
}
F_365 ( V_25 , F_49 ( V_466 -> V_125 ) ,
L_245 ) ;
return V_851 ;
}
static int F_367 ( struct V_1 * V_2 )
{
if ( V_2 -> V_867 == V_868 )
return 1 ;
return 0 ;
}
static int F_368 ( struct V_237 * V_466 )
{
int V_869 = V_858 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_466 -> V_125 -> V_180 ) ;
if ( V_549 ) {
F_3 ( F_28 ( L_148 ,
V_10 -> V_452 , V_26 ) ) ;
if ( F_367 ( V_466 -> V_125 -> V_180 ) )
F_195 ( V_10 , V_870 << 16 ) ;
return V_858 ;
}
F_4 ( V_25 , V_10 ,
L_246 , V_10 -> V_452 ,
V_466 -> V_125 -> V_860 , V_466 -> V_125 -> V_856 , V_466 -> V_125 -> V_857 ) ;
if ( F_355 ( V_10 ) != V_41 ) {
F_3 ( F_28 ( L_247
L_248 , V_10 -> V_452 , V_466 -> V_125 -> V_860 ,
V_26 ) ) ;
return V_858 ;
}
if ( ! F_34 ( V_485 , & V_10 -> V_483 ) ) {
if ( F_8 ( V_10 ) )
F_168 ( V_489 , & V_10 -> V_483 ) ;
else
F_168 ( V_485 , & V_10 -> V_483 ) ;
}
if ( F_202 ( V_10 ) == V_41 )
V_869 = V_851 ;
F_4 ( V_25 , V_10 , L_249 ,
V_869 == V_858 ? L_134 : L_135 ) ;
return V_869 ;
}
static int F_369 ( struct V_9 * V_10 )
{
T_1 V_315 [ V_316 ] ;
T_1 V_317 [ V_316 ] ;
struct V_297 * V_298 = NULL ;
T_1 V_871 = sizeof( struct V_297 ) ;
int V_18 = V_41 ;
T_5 V_872 ;
V_298 = F_42 ( & V_10 -> V_194 -> V_126 ,
sizeof( struct V_297 ) ,
& V_872 , V_140 ) ;
if ( ! V_298 ) {
F_4 ( V_147 , V_10 , L_250 ,
V_26 ) ;
V_18 = - V_105 ;
goto V_873;
}
memset ( V_298 , 0 , V_871 ) ;
V_18 = F_370 ( V_10 , V_872 , V_874 , V_871 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_875;
}
V_18 = F_77 ( V_10 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_875;
}
F_78 ( & V_10 -> V_324 ,
V_325 * V_326 ) ;
V_18 = F_79 ( V_10 , & V_315 [ 0 ] , & V_317 [ 0 ] , V_872 ) ;
if ( V_18 != V_41 ) {
V_18 = - V_321 ;
goto V_875;
}
V_875:
F_46 ( & V_10 -> V_194 -> V_126 , sizeof( struct V_297 ) ,
V_298 , V_872 ) ;
V_873:
F_3 ( F_4 ( V_25 , V_10 , L_251 , V_26 ,
V_18 == V_41 ? L_135 : L_134 ) ) ;
return V_18 ;
}
static int F_371 ( struct V_1 * V_2 , int V_876 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_18 = V_41 ;
if ( V_549 ) {
F_3 ( F_4 ( V_25 , V_10 , L_252 ,
V_26 ) ) ;
V_18 = - V_877 ;
goto V_878;
}
V_18 = F_355 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_253
L_254 , V_26 ) ) ;
V_18 = - V_321 ;
goto V_878;
}
if ( F_34 ( V_485 , & V_10 -> V_483 ) )
goto V_879;
switch ( V_876 ) {
case V_880 :
F_168 ( V_485 , & V_10 -> V_483 ) ;
break;
case V_881 :
if ( ! F_34 ( V_485 , & V_10 -> V_483 ) ) {
if ( F_8 ( V_10 ) )
F_168 ( V_489 ,
& V_10 -> V_483 ) ;
else {
V_18 = F_369 ( V_10 ) ;
goto V_878;
}
}
break;
}
V_879:
V_18 = F_202 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_3 ( F_4 ( V_25 , V_10 , L_255 ,
V_26 ) ) ;
V_18 = - V_321 ;
}
V_878:
return V_18 ;
}
static T_12
F_372 ( struct V_636 * V_194 , T_13 V_242 )
{
struct V_9 * V_10 = F_335 ( V_194 ) ;
F_4 ( V_38 , V_10 , L_256 ,
V_10 -> V_452 , V_26 , V_242 ) ;
if ( ! F_373 ( V_10 ) )
return V_882 ;
switch ( V_242 ) {
case V_883 :
F_199 ( V_475 , & V_10 -> V_119 ) ;
return V_884 ;
case V_885 :
F_168 ( V_475 , & V_10 -> V_119 ) ;
F_171 ( V_10 ) ;
F_250 ( V_10 ) ;
F_329 ( V_194 ) ;
F_195 ( V_10 , V_591 << 16 ) ;
return V_886 ;
case V_887 :
F_168 ( V_475 , & V_10 -> V_119 ) ;
F_168 ( V_476 , & V_10 -> V_119 ) ;
F_195 ( V_10 , V_478 << 16 ) ;
return V_888 ;
}
return V_886 ;
}
static T_12
F_374 ( struct V_636 * V_194 )
{
struct V_9 * V_10 = F_335 ( V_194 ) ;
if ( ! F_373 ( V_10 ) )
return V_882 ;
return V_889 ;
}
static T_1 F_375 ( struct V_9 * V_10 )
{
T_1 V_18 = V_341 ;
T_1 V_100 = 0 ;
int V_826 ;
struct V_636 * V_825 = NULL ;
F_4 ( V_38 , V_10 , L_257 , V_10 -> V_452 , V_26 ) ;
F_168 ( V_484 , & V_10 -> V_483 ) ;
if ( F_34 ( V_488 , & V_10 -> V_119 ) ) {
F_199 ( V_488 , & V_10 -> V_119 ) ;
F_199 ( V_261 , & V_10 -> V_119 ) ;
F_141 ( V_10 -> V_180 , F_200 ) ;
F_204 ( V_10 , V_590 ) ;
}
V_826 = F_274 ( V_10 -> V_194 -> V_642 ) ;
while ( V_826 > 0 ) {
V_826 -- ;
F_4 ( V_25 , V_10 , L_258
L_259 , V_10 -> V_452 , V_26 , V_826 ) ;
V_825 =
F_331 ( F_332 ( V_10 -> V_194 -> V_830 ) ,
V_10 -> V_194 -> V_830 -> V_831 , F_333 ( F_334 ( V_10 -> V_194 -> V_642 ) ,
V_826 ) ) ;
if ( ! V_825 )
continue;
if ( F_174 ( & V_825 -> V_832 ) ) {
F_4 ( V_25 , V_10 , L_260
L_261 , V_10 -> V_452 ,
V_26 , V_826 ) ;
F_337 ( V_825 ) ;
break;
}
F_337 ( V_825 ) ;
}
if ( ! V_826 ) {
F_4 ( V_25 , V_10 , L_262
L_263 , V_10 -> V_452 , V_26 ,
V_10 -> V_194 -> V_642 ) ;
F_210 ( V_10 ) ;
F_167 ( V_10 , V_544 ,
V_890 ) ;
F_167 ( V_10 , V_891 ,
V_892 ) ;
F_211 ( V_10 ) ;
F_199 ( V_588 , & V_10 -> V_119 ) ;
V_18 = F_209 ( V_10 , V_596 ) ;
F_210 ( V_10 ) ;
if ( V_18 != V_41 ) {
F_4 ( V_25 , V_10 , L_264
L_265 , V_10 -> V_452 , V_26 ) ;
F_249 ( V_10 ) ;
F_167 ( V_10 , V_544 ,
V_597 ) ;
} else {
F_4 ( V_25 , V_10 , L_264
L_266 , V_10 -> V_452 , V_26 ) ;
F_167 ( V_10 , V_544 ,
V_893 ) ;
F_167 ( V_10 , V_894 , 0 ) ;
F_376 ( V_10 ) ;
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_267
L_268 ,
V_10 -> V_194 -> V_801 ) ;
V_18 = V_341 ;
} else {
V_10 -> V_586 -> V_602 ( V_10 ) ;
V_18 = V_41 ;
}
}
F_211 ( V_10 ) ;
} else {
F_4 ( V_25 , V_10 , L_269
L_270 , V_10 -> V_452 , V_26 ,
V_10 -> V_194 -> V_642 ) ;
if ( ( F_162 ( V_10 , V_544 ) ==
V_893 ) ) {
F_199 ( V_588 , & V_10 -> V_119 ) ;
V_18 = F_209 ( V_10 , V_596 ) ;
if ( V_18 == V_41 ) {
V_100 = F_324 ( V_10 ) ;
if ( V_100 ) {
F_4 ( V_38 , V_10 , L_271
L_272
L_273 , V_10 -> V_194 -> V_801 ) ;
V_18 = V_341 ;
} else {
V_10 -> V_586 -> V_602 ( V_10 ) ;
V_18 = V_41 ;
}
}
F_210 ( V_10 ) ;
F_376 ( V_10 ) ;
F_211 ( V_10 ) ;
}
}
F_199 ( V_484 , & V_10 -> V_483 ) ;
return V_18 ;
}
static T_12
F_377 ( struct V_636 * V_194 )
{
T_12 V_100 = V_888 ;
struct V_9 * V_10 = F_335 ( V_194 ) ;
int V_660 ;
F_4 ( V_38 , V_10 , L_274 ,
V_10 -> V_452 , V_26 ) ;
if ( ! F_373 ( V_10 ) )
return V_882 ;
F_378 ( V_194 ) ;
F_325 ( V_194 ) ;
V_660 = F_310 ( V_194 ) ;
if ( V_660 ) {
F_4 ( V_38 , V_10 , L_275
L_276 , V_10 -> V_452 , V_26 ) ;
goto V_895;
}
V_10 -> V_586 -> V_589 ( V_10 ) ;
if ( F_8 ( V_10 ) ) {
if ( F_375 ( V_10 ) == V_41 ) {
V_100 = V_889 ;
goto V_895;
} else
goto V_895;
}
V_895:
F_4 ( V_38 , V_10 , L_277
L_276 , V_10 -> V_452 , V_26 , V_100 ) ;
return V_100 ;
}
static void
F_379 ( struct V_636 * V_194 )
{
struct V_9 * V_10 = F_335 ( V_194 ) ;
int V_100 ;
F_4 ( V_38 , V_10 , L_278 ,
V_10 -> V_452 , V_26 ) ;
V_100 = F_355 ( V_10 ) ;
if ( V_100 != V_41 ) {
F_4 ( V_147 , V_10 , L_279
L_280 , V_10 -> V_452 ,
V_26 ) ;
}
F_380 ( V_194 ) ;
F_199 ( V_475 , & V_10 -> V_119 ) ;
}
static int T_14 F_381 ( void )
{
int V_100 ;
V_520 = F_382 ( L_281 , sizeof( struct V_465 ) , 0 ,
V_896 , NULL ) ;
if ( V_520 == NULL ) {
F_28 ( V_147
L_282
L_283 , V_637 ) ;
V_100 = - V_105 ;
goto V_897;
}
strcpy ( V_820 , V_898 ) ;
if ( V_899 )
strcat ( V_820 , L_284 ) ;
V_816 =
F_383 ( & V_269 ) ;
if ( ! V_816 ) {
V_100 = - V_781 ;
goto V_900;
}
V_100 = F_384 ( & V_901 ) ;
if ( V_100 )
goto V_902;
F_28 ( V_25 L_285 ) ;
return 0 ;
V_902:
F_385 ( & V_269 ) ;
V_900:
F_386 ( V_520 ) ;
V_897:
return V_100 ;
}
static void T_15 F_387 ( void )
{
F_388 ( & V_901 ) ;
F_385 ( & V_269 ) ;
F_386 ( V_520 ) ;
}
