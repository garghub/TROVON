T_1 F_1 ( T_1 V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return V_8 ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
return V_19 ;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
return V_37 ;
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
return V_49 ;
default:
if ( V_2 == V_50 )
return V_49 ;
return V_19 ;
}
}
void F_2 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_52 -> V_57 ;
struct V_58 * V_59 = (struct V_58 * ) V_56 -> V_60 ;
struct V_61 * V_62 =
F_3 ( V_54 ) ;
T_1 * V_63 = & V_62 -> V_63 [ 0 ] ;
struct V_64 * V_65 = (struct V_64 * ) V_63 ;
V_59 -> V_66 = sizeof( struct V_64 ) ;
memcpy ( & V_59 -> V_67 [ 0 ] , V_65 , sizeof( struct V_64 ) ) ;
V_56 -> V_68 = sizeof( * V_59 ) ;
}
int F_4 ( struct V_51 * V_52 , T_2 * V_69 )
{
struct V_70 * V_71 = V_52 -> V_72 ;
if ( V_71 ) {
if ( V_71 -> V_73 . V_74 == V_3 ||
V_71 -> V_73 . V_74 == V_4 ) {
* V_69 = V_71 -> V_69 ;
return 1 ;
}
}
return 0 ;
}
static struct V_75 * F_5 ( struct V_76 * V_77 )
{
return V_77 -> V_78 -> V_79 -> V_80 ;
}
struct V_81 * F_6 ( struct V_82 * V_83 )
{
return F_7 ( V_83 , struct V_81 , V_83 ) ;
}
void F_8 ( struct V_75 * V_75 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_75 -> V_85 ; V_84 ++ )
V_75 -> V_86 -> V_87 ( V_75 , V_84 ) ;
}
static void F_9 ( struct V_75 * V_75 , int V_88 )
{
void * V_89 = V_75 -> V_90 ;
F_10 ( V_88 , V_89 ) ;
}
static void F_11 ( struct V_75 * V_75 , int V_88 )
{
F_9 ( V_75 , V_88 ) ;
}
static void F_12 ( struct V_75 * V_75 , int V_88 )
{
void * V_89 = V_75 -> V_90 ;
F_13 ( V_88 , V_89 ) ;
}
static int F_14 ( struct V_75 * V_75 , int * V_88 )
{
unsigned int V_91 ;
void * V_89 = V_75 -> V_90 ;
V_91 = F_15 ( V_89 , V_75 -> V_92 ) ;
if ( V_91 >= V_75 -> V_92 )
return - V_93 ;
F_12 ( V_75 , V_91 ) ;
* V_88 = V_91 ;
return 0 ;
}
static void F_16 ( struct V_75 * V_75 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_75 -> V_92 ; ++ V_94 )
F_9 ( V_75 , V_94 ) ;
}
void F_17 ( struct V_75 * V_75 , struct V_51 * V_52 ,
struct V_53 * V_54 )
{
if ( V_52 ) {
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_96 * V_97 = V_77 -> V_98 ;
if ( ! F_18 ( V_52 -> V_99 ) )
if ( V_54 -> V_100 )
F_19 ( V_95 , V_52 -> V_101 , V_54 -> V_100 ,
V_52 -> V_102 ) ;
V_52 -> V_103 = NULL ;
if ( V_97 )
F_20 ( & V_97 -> V_104 ) ;
}
if ( V_54 -> V_60 )
F_21 ( V_75 -> V_105 , V_54 -> V_60 , V_54 -> V_106 ) ;
F_22 ( & V_54 -> V_107 ) ;
V_54 -> V_52 = NULL ;
V_54 -> V_78 = NULL ;
F_11 ( V_75 , V_54 -> V_108 ) ;
}
static int F_23 ( struct V_75 * V_75 ,
struct V_53 * V_54 )
{
return V_75 -> V_86 -> V_109 ( V_75 , V_54 ) ;
}
static int F_24 ( struct V_75 * V_75 ,
struct V_53 * V_54 , int V_110 ,
struct V_111 * V_112 )
{
return V_75 -> V_86 -> V_113 ( V_75 , V_54 , V_110 , V_112 ) ;
}
static int F_25 ( struct V_75 * V_75 ,
struct V_53 * V_54 )
{
return V_75 -> V_86 -> V_114 ( V_75 , V_54 ) ;
}
static int F_26 ( struct V_75 * V_75 ,
struct V_53 * V_54 ,
int V_115 , int V_116 , int V_117 )
{
return V_75 -> V_86 -> V_118 ( V_75 , V_54 ,
V_115 , V_116 , V_117 ) ;
}
static void F_27 ( struct V_119 * V_120 )
{
struct V_53 * V_121 =
F_7 ( V_120 , struct V_53 , V_121 ) ;
struct V_51 * V_52 = V_121 -> V_52 ;
struct V_75 * V_75 = F_5 ( V_52 -> V_95 ) ;
struct V_122 * V_123 = V_52 -> V_72 ;
struct V_111 V_124 ;
struct V_125 V_126 ;
struct V_77 * V_95 = V_75 -> V_95 ;
int V_69 = V_121 -> V_108 ;
unsigned long V_127 ;
if ( ! ( V_52 -> V_99 & V_128 ) ) {
F_28 ( V_95 , L_1 ) ;
goto V_129;
}
F_29 ( V_123 -> V_77 -> V_126 , & V_126 ) ;
V_124 . V_112 = V_130 ;
V_124 . V_131 = F_30 ( V_69 ) ;
F_31 ( V_52 -> V_95 , V_126 . V_125 , & V_124 ) ;
V_129:
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_17 ( V_75 , V_52 , V_121 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
if ( V_52 -> V_133 )
V_52 -> V_133 ( V_52 ) ;
}
static int F_34 ( struct V_51 * V_52 , struct V_134
* V_135 , int V_110 , struct V_111 * V_112 ,
int * V_136 )
{
struct V_75 * V_75 = V_135 -> V_75 ;
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_81 * V_78 ;
struct V_53 * V_54 ;
struct V_137 * V_138 ;
struct V_82 * V_83 = V_77 -> V_78 ;
struct V_77 * V_95 = V_75 -> V_95 ;
int V_139 , V_140 , V_100 = 0 , V_141 , V_88 ;
unsigned long V_127 ;
if ( ! V_83 ) {
struct V_55 * V_56 = & V_52 -> V_57 ;
V_56 -> V_59 = V_142 ;
V_56 -> V_143 = V_144 ;
if ( V_77 -> V_145 != V_146 )
V_52 -> V_133 ( V_52 ) ;
return V_144 ;
}
if ( F_35 ( V_97 ) ) {
if ( V_97 )
F_36 ( V_95 , L_2 ,
V_97 -> V_115 ) ;
else
F_36 ( V_95 , L_3 ,
F_37 ( V_77 -> V_147 ) ) ;
return V_144 ;
}
V_78 = F_6 ( V_83 ) ;
if ( V_78 && ! V_78 -> V_148 ) {
F_36 ( V_95 , L_4 ,
( F_38 ( V_77 ) ) ?
L_5 : L_6 ,
V_77 -> V_78 -> V_149 ) ;
return V_144 ;
}
if ( ! F_18 ( V_52 -> V_99 ) ) {
if ( V_52 -> V_150 ) {
V_100 = F_39 ( V_95 , V_52 -> V_101 ,
V_52 -> V_150 , V_52 -> V_102 ) ;
if ( ! V_100 ) {
V_141 = - V_151 ;
goto V_152;
}
}
} else
V_100 = V_52 -> V_150 ;
F_32 ( & V_75 -> V_132 , V_127 ) ;
if ( V_75 -> V_86 -> V_153 )
V_141 = V_75 -> V_86 -> V_153 ( V_75 , & V_88 ,
V_77 ) ;
else
V_141 = F_14 ( V_75 , & V_88 ) ;
if ( V_141 ) {
F_33 ( & V_75 -> V_132 , V_127 ) ;
goto V_154;
}
F_33 ( & V_75 -> V_132 , V_127 ) ;
V_141 = V_75 -> V_86 -> V_155 ( V_75 , V_135 ) ;
if ( V_141 )
goto V_156;
V_140 = V_135 -> V_149 ;
V_139 = V_135 -> V_157 ;
V_54 = & V_75 -> V_158 [ V_88 ] ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
V_54 -> V_108 = V_88 ;
V_54 -> V_100 = V_100 ;
V_54 -> V_140 = V_140 ;
V_54 -> V_139 = V_139 ;
V_138 = V_75 -> V_159 [ V_140 ] ;
V_54 -> V_159 = & V_138 [ V_139 ] ;
V_54 -> V_52 = V_52 ;
V_54 -> V_78 = V_78 ;
V_52 -> V_103 = V_54 ;
F_40 ( & V_54 -> V_121 , F_27 ) ;
V_54 -> V_60 = F_41 ( V_75 -> V_105 ,
V_160 , & V_54 -> V_106 ) ;
if ( ! V_54 -> V_60 ) {
V_141 = - V_151 ;
goto V_161;
}
memset ( V_54 -> V_159 , 0 , sizeof( struct V_137 ) ) ;
memset ( F_42 ( V_54 ) , 0 , V_162 ) ;
memset ( F_3 ( V_54 ) , 0 , V_163 ) ;
switch ( V_52 -> V_99 ) {
case V_164 :
V_141 = F_23 ( V_75 , V_54 ) ;
break;
case V_128 :
V_141 = F_24 ( V_75 , V_54 , V_110 , V_112 ) ;
break;
case V_165 :
case V_166 :
case V_165 | V_166 :
V_141 = F_25 ( V_75 , V_54 ) ;
break;
default:
F_28 ( V_95 , L_7 ,
V_52 -> V_99 ) ;
V_141 = - V_167 ;
break;
}
if ( V_141 ) {
F_28 ( V_95 , L_8 , V_141 ) ;
goto V_168;
}
F_43 ( & V_54 -> V_107 , & V_97 -> V_169 ) ;
F_32 ( & V_52 -> V_170 , V_127 ) ;
V_52 -> V_171 |= V_172 ;
F_33 ( & V_52 -> V_170 , V_127 ) ;
V_135 -> V_173 = V_54 ;
F_44 ( & V_97 -> V_104 ) ;
++ ( * V_136 ) ;
return 0 ;
V_168:
F_21 ( V_75 -> V_105 , V_54 -> V_60 ,
V_54 -> V_106 ) ;
V_161:
V_156:
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_11 ( V_75 , V_88 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
V_154:
F_28 ( V_95 , L_9 , V_141 ) ;
if ( ! F_18 ( V_52 -> V_99 ) )
if ( V_100 )
F_19 ( V_95 , V_52 -> V_101 , V_100 ,
V_52 -> V_102 ) ;
V_152:
return V_141 ;
}
static int F_45 ( struct V_51 * V_52 , T_3 V_174 ,
int V_110 , struct V_111 * V_112 )
{
T_2 V_141 ;
T_2 V_136 = 0 ;
unsigned long V_127 ;
struct V_75 * V_75 = F_5 ( V_52 -> V_95 ) ;
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_134 * V_135 = V_97 -> V_135 ;
if ( F_46 ( F_47 ( V_175 , & V_75 -> V_127 ) ) )
return - V_167 ;
F_32 ( & V_135 -> V_132 , V_127 ) ;
V_141 = F_34 ( V_52 , V_135 , V_110 , V_112 , & V_136 ) ;
if ( V_141 )
F_28 ( V_95 , L_10 , V_141 ) ;
if ( F_48 ( V_136 ) )
V_75 -> V_86 -> V_176 ( V_135 ) ;
F_33 ( & V_135 -> V_132 , V_127 ) ;
return V_141 ;
}
static void F_49 ( struct V_75 * V_75 , int V_84 )
{
struct V_177 * V_178 = & V_75 -> V_178 [ V_84 ] ;
struct V_179 * V_180 = & V_178 -> V_180 ;
struct V_181 * V_182 ;
if ( ! V_178 -> V_183 )
return;
V_182 = & V_75 -> V_184 ;
V_182 -> V_185 ( V_180 , V_186 ) ;
if ( V_180 -> V_178 ) {
struct V_180 * V_187 = V_180 -> V_178 ;
V_187 -> V_188 = V_180 -> V_189 ;
V_187 -> V_190 = V_191 ;
V_187 -> V_192 =
V_75 -> V_86 -> V_193 () ;
if ( V_187 -> V_194 == V_195 )
V_187 -> V_194 = V_178 -> V_194 ;
if ( V_187 -> V_196 == V_195 )
V_187 -> V_196 = V_178 -> V_196 ;
}
if ( V_178 -> V_197 & V_198 ) {
struct V_199 * V_149 ;
V_149 = (struct V_199 * ) V_178 -> V_200 ;
V_149 -> V_145 = V_178 -> V_201 . V_202 ;
V_149 -> V_203 = V_204 ;
V_149 -> V_205 = V_178 -> V_201 . V_206 ;
} else if ( V_178 -> V_197 & V_207 ) {
}
V_180 -> V_208 = V_178 -> V_208 ;
V_182 -> V_209 ( V_180 , V_210 ) ;
}
static struct V_96 * F_50 ( struct V_76 * V_77 )
{
struct V_75 * V_75 = F_5 ( V_77 ) ;
struct V_96 * V_97 = NULL ;
int V_94 ;
F_51 ( & V_75 -> V_132 ) ;
for ( V_94 = 0 ; V_94 < V_211 ; V_94 ++ ) {
if ( V_75 -> V_212 [ V_94 ] . V_145 == V_213 ) {
int V_214 = V_94 % V_75 -> V_215 ;
struct V_134 * V_135 = & V_75 -> V_135 [ V_214 ] ;
V_75 -> V_212 [ V_94 ] . V_115 = V_94 ;
V_97 = & V_75 -> V_212 [ V_94 ] ;
V_97 -> V_216 = V_217 ;
V_97 -> V_145 = V_77 -> V_145 ;
V_97 -> V_75 = V_75 ;
V_97 -> V_218 = V_77 ;
V_97 -> V_135 = V_135 ;
F_52 ( & V_75 -> V_212 [ V_94 ] . V_169 ) ;
break;
}
}
F_53 ( & V_75 -> V_132 ) ;
return V_97 ;
}
static int F_54 ( struct V_76 * V_77 )
{
struct V_75 * V_75 = F_5 ( V_77 ) ;
struct V_76 * V_219 = V_77 -> V_220 ;
struct V_96 * V_97 ;
struct V_77 * V_95 = V_75 -> V_95 ;
if ( V_75 -> V_86 -> V_221 )
V_97 = V_75 -> V_86 -> V_221 ( V_77 ) ;
else
V_97 = F_50 ( V_77 ) ;
if ( ! V_97 ) {
F_28 ( V_95 , L_11 ,
V_211 ) ;
return - V_167 ;
}
V_77 -> V_98 = V_97 ;
V_75 -> V_86 -> V_222 ( V_75 , V_97 ) ;
if ( V_219 && F_55 ( V_219 -> V_145 ) ) {
int V_84 ;
T_1 V_223 = V_219 -> V_224 . V_225 ;
struct V_226 * V_178 ;
for ( V_84 = 0 ; V_84 < V_223 ; V_84 ++ ) {
V_178 = & V_219 -> V_224 . V_226 [ V_84 ] ;
if ( F_37 ( V_178 -> V_227 ) ==
F_37 ( V_77 -> V_147 ) ) {
V_97 -> V_228 = V_84 ;
break;
}
}
if ( V_84 == V_223 ) {
F_36 ( V_95 , L_12
L_13 ,
F_37 ( V_77 -> V_147 ) ,
F_37 ( V_219 -> V_147 ) ) ;
return - V_167 ;
}
}
return 0 ;
}
static int F_56 ( struct V_229 * V_230 )
{
struct V_76 * V_95 = F_57 ( V_230 ) ;
int V_231 = F_58 ( V_230 ) ;
if ( V_231 )
return V_231 ;
if ( ! F_38 ( V_95 ) )
F_59 ( V_230 , 64 ) ;
return 0 ;
}
static void F_60 ( struct V_232 * V_233 )
{
struct V_75 * V_75 = F_61 ( V_233 ) ;
V_75 -> V_86 -> V_234 ( V_75 ) ;
}
static int F_62 ( struct V_232 * V_233 , unsigned long time )
{
struct V_75 * V_75 = F_61 ( V_233 ) ;
struct V_181 * V_184 = & V_75 -> V_184 ;
if ( time < V_235 )
return 0 ;
F_63 ( V_184 ) ;
return 1 ;
}
static void F_64 ( struct V_119 * V_120 )
{
struct V_177 * V_178 =
F_7 ( V_120 , struct V_177 , V_236 ) ;
struct V_75 * V_75 = V_178 -> V_75 ;
struct V_179 * V_180 = & V_178 -> V_180 ;
int V_84 = V_180 -> V_149 ;
V_75 -> V_86 -> V_237 ( V_75 , V_84 ) ;
F_49 ( V_75 , V_84 ) ;
}
static void F_65 ( struct V_75 * V_75 , int V_84 )
{
struct V_177 * V_178 = & V_75 -> V_178 [ V_84 ] ;
struct V_179 * V_180 = & V_178 -> V_180 ;
V_178 -> V_75 = V_75 ;
V_178 -> V_78 = NULL ;
F_66 ( & V_178 -> V_238 ) ;
V_180 -> V_239 = ( V_84 < V_75 -> V_85 ) ? 1 : 0 ;
V_180 -> V_240 = V_241 ;
V_180 -> V_242 = V_204 ;
V_180 -> V_243 = 0 ;
V_180 -> type = V_244 ;
V_180 -> V_245 = V_246 ;
V_180 -> V_247 = V_248 ;
V_180 -> V_189 = V_195 ;
V_180 -> V_149 = V_84 ;
V_180 -> V_147 = & V_75 -> V_147 [ 0 ] ;
V_180 -> V_200 = & V_178 -> V_200 [ 0 ] ;
V_180 -> V_79 = (struct V_181 * ) V_75 -> V_233 -> V_249 ;
V_180 -> V_250 = V_178 ;
F_40 ( & V_178 -> V_236 , F_64 ) ;
}
static void F_67 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = V_180 -> V_79 ;
struct V_75 * V_75 = V_182 -> V_80 ;
struct V_177 * V_178 = V_180 -> V_250 ;
struct V_82 * V_83 = V_180 -> V_78 ;
struct V_81 * V_78 = F_6 ( V_83 ) ;
unsigned long V_127 ;
if ( ! V_83 )
return;
F_32 ( & V_75 -> V_132 , V_127 ) ;
V_78 -> V_148 = 1 ;
V_78 -> V_149 = V_178 -> V_251 ;
V_178 -> V_78 = V_78 ;
V_83 -> V_252 = V_78 ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
static void F_68 ( struct V_75 * V_75 , struct V_51 * V_52 ,
struct V_53 * V_54 )
{
if ( V_52 ) {
unsigned long V_127 ;
struct V_55 * V_56 ;
V_56 = & V_52 -> V_57 ;
V_56 -> V_59 = V_253 ;
V_56 -> V_143 = V_254 ;
F_32 ( & V_52 -> V_170 , V_127 ) ;
V_52 -> V_171 &=
~ ( V_255 | V_172 ) ;
V_52 -> V_171 |= V_256 ;
F_33 ( & V_52 -> V_170 , V_127 ) ;
}
F_17 ( V_75 , V_52 , V_54 ) ;
}
static void F_69 ( struct V_75 * V_75 ,
struct V_76 * V_77 )
{
struct V_53 * V_54 , * V_257 ;
struct V_96 * V_97 = V_77 -> V_98 ;
F_70 (slot, slot2, &sas_dev->list, entry)
F_68 ( V_75 , V_54 -> V_52 , V_54 ) ;
}
static void F_71 ( struct V_75 * V_75 )
{
struct V_96 * V_97 ;
struct V_76 * V_77 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_211 ; V_94 ++ ) {
V_97 = & V_75 -> V_212 [ V_94 ] ;
V_77 = V_97 -> V_218 ;
if ( ( V_97 -> V_145 == V_213 ) ||
! V_77 )
continue;
F_69 ( V_75 , V_77 ) ;
}
}
static void F_72 ( struct V_75 * V_75 ,
struct V_76 * V_77 )
{
if ( V_75 -> V_86 -> V_258 )
V_75 -> V_86 -> V_258 ( V_75 , V_77 ) ;
}
static void F_73 ( struct V_76 * V_77 )
{
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_75 * V_75 = F_5 ( V_77 ) ;
struct V_77 * V_95 = V_75 -> V_95 ;
F_36 ( V_95 , L_14 ,
V_97 -> V_115 , V_97 -> V_145 ) ;
F_74 ( V_75 , V_77 ,
V_259 , 0 ) ;
F_72 ( V_75 , V_77 ) ;
V_75 -> V_86 -> V_260 ( V_75 , V_97 ) ;
V_77 -> V_98 = NULL ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_97 -> V_145 = V_213 ;
}
static int F_75 ( struct V_51 * V_52 , T_3 V_174 )
{
return F_45 ( V_52 , V_174 , 0 , NULL ) ;
}
static int F_76 ( struct V_179 * V_180 , enum V_261 V_262 ,
void * V_263 )
{
struct V_181 * V_182 = V_180 -> V_79 ;
struct V_75 * V_75 = V_182 -> V_80 ;
int V_84 = V_180 -> V_149 ;
switch ( V_262 ) {
case V_264 :
V_75 -> V_86 -> V_265 ( V_75 , V_84 ) ;
break;
case V_266 :
V_75 -> V_86 -> V_87 ( V_75 , V_84 ) ;
F_77 ( 100 ) ;
V_75 -> V_86 -> V_267 ( V_75 , V_84 ) ;
break;
case V_268 :
V_75 -> V_86 -> V_87 ( V_75 , V_84 ) ;
break;
case V_269 :
V_75 -> V_86 -> V_270 ( V_75 , V_84 , V_263 ) ;
break;
case V_271 :
if ( V_75 -> V_86 -> V_272 ) {
V_75 -> V_86 -> V_272 ( V_75 , V_84 ) ;
break;
}
case V_273 :
default:
return - V_274 ;
}
return 0 ;
}
static void F_78 ( struct V_51 * V_52 )
{
if ( ! F_79 ( & V_52 -> V_275 -> V_238 ) )
return;
F_80 ( & V_52 -> V_275 -> V_276 ) ;
}
static void F_81 ( unsigned long V_277 )
{
struct V_51 * V_52 = (struct V_51 * ) V_277 ;
unsigned long V_127 ;
F_32 ( & V_52 -> V_170 , V_127 ) ;
if ( ! ( V_52 -> V_171 & V_256 ) )
V_52 -> V_171 |= V_278 ;
F_33 ( & V_52 -> V_170 , V_127 ) ;
F_80 ( & V_52 -> V_275 -> V_276 ) ;
}
static int F_82 ( struct V_76 * V_77 ,
void * V_279 , T_2 V_280 ,
struct V_111 * V_112 )
{
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_75 * V_75 = V_97 -> V_75 ;
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_51 * V_52 ;
int V_281 , V_282 ;
for ( V_282 = 0 ; V_282 < V_283 ; V_282 ++ ) {
V_52 = F_83 ( V_284 ) ;
if ( ! V_52 )
return - V_151 ;
V_52 -> V_95 = V_77 ;
V_52 -> V_99 = V_77 -> V_243 ;
if ( F_38 ( V_77 ) ) {
V_52 -> V_285 . V_286 = 1 ;
memcpy ( & V_52 -> V_285 . V_287 , V_279 , V_280 ) ;
} else {
memcpy ( & V_52 -> V_288 , V_279 , V_280 ) ;
}
V_52 -> V_133 = F_78 ;
V_52 -> V_275 -> V_238 . V_277 = ( unsigned long ) V_52 ;
V_52 -> V_275 -> V_238 . V_289 = F_81 ;
V_52 -> V_275 -> V_238 . V_290 = V_291 + V_292 * V_235 ;
F_84 ( & V_52 -> V_275 -> V_238 ) ;
V_281 = F_45 ( V_52 , V_284 , 1 , V_112 ) ;
if ( V_281 ) {
F_79 ( & V_52 -> V_275 -> V_238 ) ;
F_28 ( V_95 , L_15 ,
V_281 ) ;
goto V_293;
}
F_85 ( & V_52 -> V_275 -> V_276 ) ;
V_281 = V_294 ;
if ( ( V_52 -> V_171 & V_278 ) ) {
if ( ! ( V_52 -> V_171 & V_256 ) ) {
struct V_53 * V_54 = V_52 -> V_103 ;
F_28 ( V_95 , L_16 ) ;
if ( V_54 )
V_54 -> V_52 = NULL ;
goto V_293;
}
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_295 ) {
V_281 = V_295 ;
break;
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_296 ) {
V_281 = V_296 ;
break;
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_297 ) {
F_86 ( V_95 , L_17
L_18 ,
F_37 ( V_77 -> V_147 ) ,
V_52 -> V_57 . V_59 ,
V_52 -> V_57 . V_143 ) ;
V_281 = V_52 -> V_57 . V_298 ;
break;
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_299 ) {
F_86 ( V_95 , L_19 ) ;
V_281 = - V_300 ;
break;
}
F_86 ( V_95 , L_20
L_21 ,
F_37 ( V_77 -> V_147 ) , V_52 -> V_57 . V_59 ,
V_52 -> V_57 . V_143 ) ;
F_87 ( V_52 ) ;
V_52 = NULL ;
}
V_293:
if ( V_282 == V_283 )
F_86 ( V_95 , L_22 ) ;
F_87 ( V_52 ) ;
return V_281 ;
}
static void F_88 ( struct V_301 * V_95 ,
bool V_302 , int V_303 , T_1 * V_287 )
{
struct V_304 V_73 ;
F_89 ( V_95 , & V_73 ) ;
if ( V_302 )
V_73 . V_305 |= V_306 ;
else
V_73 . V_305 &= ~ V_306 ;
V_73 . V_74 = V_39 ;
F_90 ( & V_73 , V_303 , 0 , V_287 ) ;
}
static int F_91 ( struct V_76 * V_77 )
{
T_1 V_287 [ 20 ] = { 0 } ;
struct V_307 * V_308 = V_77 -> V_309 . V_308 ;
struct V_310 * V_311 ;
int V_141 = V_294 ;
struct V_75 * V_75 = F_5 ( V_77 ) ;
struct V_77 * V_95 = V_75 -> V_95 ;
int V_312 = sizeof( struct V_313 ) ;
unsigned long V_127 ;
F_92 (link, ap, EDGE) {
int V_303 = F_93 ( V_311 ) ;
F_88 ( V_311 -> V_77 , 1 , V_303 , V_287 ) ;
V_141 = F_82 ( V_77 , V_287 , V_312 , NULL ) ;
if ( V_141 != V_295 )
break;
}
if ( V_141 == V_295 ) {
F_92 (link, ap, EDGE) {
int V_303 = F_93 ( V_311 ) ;
F_88 ( V_311 -> V_77 , 0 , V_303 , V_287 ) ;
V_141 = F_82 ( V_77 , V_287 ,
V_312 , NULL ) ;
if ( V_141 != V_295 )
F_28 ( V_95 , L_23 ) ;
}
} else {
F_28 ( V_95 , L_24 ) ;
}
if ( V_141 == V_295 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_69 ( V_75 , V_77 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
return V_141 ;
}
static int F_31 ( struct V_76 * V_77 ,
T_1 * V_126 , struct V_111 * V_112 )
{
struct V_314 V_288 ;
if ( ! ( V_77 -> V_243 & V_128 ) )
return V_315 ;
memcpy ( V_288 . V_316 , V_126 , 8 ) ;
return F_82 ( V_77 , & V_288 ,
sizeof( V_288 ) , V_112 ) ;
}
static void F_94 ( struct V_75 * V_75 ,
struct V_82 * V_83 , enum V_317 V_189 )
{
struct V_96 * V_97 ;
struct V_76 * V_77 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_211 ; V_94 ++ ) {
V_97 = & V_75 -> V_212 [ V_94 ] ;
V_77 = V_97 -> V_218 ;
if ( ( V_97 -> V_145 == V_213 )
|| ! V_77 || ( V_77 -> V_78 != V_83 ) )
continue;
V_75 -> V_86 -> V_260 ( V_75 , V_97 ) ;
if ( ! V_77 -> V_220 )
V_77 -> V_189 = V_189 ;
V_75 -> V_86 -> V_222 ( V_75 , V_97 ) ;
}
}
static void F_95 ( struct V_75 * V_75 , T_2 V_318 ,
T_2 V_319 )
{
struct V_181 * V_182 = & V_75 -> V_184 ;
struct V_82 * V_320 = NULL ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_75 -> V_85 ; V_84 ++ ) {
struct V_177 * V_178 = & V_75 -> V_178 [ V_84 ] ;
struct V_179 * V_180 = & V_178 -> V_180 ;
struct V_82 * V_83 = V_180 -> V_78 ;
struct V_81 * V_78 = F_6 ( V_83 ) ;
bool V_321 = ! ! ( V_320 != V_83 ) ;
if ( ! V_180 -> V_178 -> V_239 )
continue;
if ( V_319 & ( 1 << V_84 ) ) {
if ( V_321 && V_83 ) {
struct V_76 * V_95 = V_83 -> V_322 ;
V_320 = V_83 ;
V_78 -> V_149 = V_178 -> V_251 ;
F_94 ( V_75 ,
V_83 , V_180 -> V_189 ) ;
if ( F_55 ( V_95 -> V_145 ) )
V_182 -> V_209 ( V_180 ,
V_323 ) ;
}
} else if ( V_318 & ( 1 << V_84 ) )
F_96 ( V_75 , V_84 , 0 ) ;
}
F_97 ( V_75 -> V_233 -> V_324 ) ;
}
static int F_98 ( struct V_75 * V_75 )
{
struct V_181 * V_182 = & V_75 -> V_184 ;
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_232 * V_233 = V_75 -> V_233 ;
T_2 V_318 , V_319 ;
unsigned long V_127 ;
int V_141 ;
if ( ! V_75 -> V_86 -> V_325 )
return - 1 ;
if ( F_99 ( V_326 , & V_75 -> V_127 ) )
return - 1 ;
F_100 ( V_95 , L_25 ) ;
V_318 = V_75 -> V_86 -> V_327 ( V_75 ) ;
F_101 ( V_233 ) ;
F_13 ( V_175 , & V_75 -> V_127 ) ;
V_141 = V_75 -> V_86 -> V_325 ( V_75 ) ;
if ( V_141 ) {
F_86 ( V_95 , L_26 , V_141 ) ;
F_10 ( V_175 , & V_75 -> V_127 ) ;
goto V_129;
}
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_71 ( V_75 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
V_182 -> V_328 ( V_182 , V_329 ) ;
F_10 ( V_175 , & V_75 -> V_127 ) ;
V_75 -> V_86 -> V_234 ( V_75 ) ;
F_77 ( 1000 ) ;
F_97 ( V_75 -> V_330 ) ;
F_97 ( V_233 -> V_324 ) ;
V_319 = V_75 -> V_86 -> V_327 ( V_75 ) ;
F_95 ( V_75 , V_318 , V_319 ) ;
F_100 ( V_95 , L_27 ) ;
V_129:
F_102 ( V_233 ) ;
F_10 ( V_326 , & V_75 -> V_127 ) ;
return V_141 ;
}
static int F_103 ( struct V_51 * V_52 )
{
struct V_125 V_126 ;
struct V_111 V_124 ;
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_75 * V_75 = F_5 ( V_52 -> V_95 ) ;
struct V_77 * V_95 = V_75 -> V_95 ;
int V_141 = V_294 ;
unsigned long V_127 ;
if ( ! V_97 ) {
F_86 ( V_95 , L_28 ) ;
return V_294 ;
}
if ( V_52 -> V_171 & V_256 ) {
V_141 = V_295 ;
goto V_129;
}
V_97 -> V_216 = V_331 ;
if ( V_52 -> V_103 && V_52 -> V_99 & V_128 ) {
struct V_122 * V_123 = V_52 -> V_72 ;
struct V_53 * V_54 = V_52 -> V_103 ;
T_2 V_69 = V_54 -> V_108 ;
int V_332 ;
F_29 ( V_123 -> V_77 -> V_126 , & V_126 ) ;
V_124 . V_112 = V_130 ;
V_124 . V_131 = F_30 ( V_69 ) ;
V_141 = F_31 ( V_52 -> V_95 , V_126 . V_125 ,
& V_124 ) ;
V_332 = F_74 ( V_75 , V_77 ,
V_333 , V_69 ) ;
if ( V_141 == V_295 && V_332 != V_296 ) {
if ( V_52 -> V_103 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_68 ( V_75 , V_52 , V_54 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
}
} else if ( V_52 -> V_99 & V_165 ||
V_52 -> V_99 & V_166 ) {
if ( V_52 -> V_95 -> V_145 == V_146 ) {
F_74 ( V_75 , V_77 ,
V_259 , 0 ) ;
F_72 ( V_75 , V_77 ) ;
V_141 = F_91 ( V_77 ) ;
}
} else if ( V_52 -> V_103 && V_52 -> V_99 & V_164 ) {
struct V_53 * V_54 = V_52 -> V_103 ;
T_2 V_69 = V_54 -> V_108 ;
V_141 = F_74 ( V_75 , V_77 ,
V_333 , V_69 ) ;
if ( V_141 == V_294 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_68 ( V_75 , V_52 , V_54 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
}
V_129:
if ( V_141 != V_295 )
F_104 ( V_95 , L_29 , V_141 ) ;
return V_141 ;
}
static int F_105 ( struct V_76 * V_77 , T_1 * V_126 )
{
struct V_111 V_124 ;
int V_141 = V_294 ;
V_124 . V_112 = V_334 ;
V_141 = F_31 ( V_77 , V_126 , & V_124 ) ;
return V_141 ;
}
static int F_106 ( struct V_76 * V_77 , T_1 * V_126 )
{
int V_141 = V_294 ;
struct V_111 V_124 ;
V_124 . V_112 = V_335 ;
V_141 = F_31 ( V_77 , V_126 , & V_124 ) ;
return V_141 ;
}
static int F_107 ( struct V_76 * V_77 )
{
struct V_180 * V_178 = F_108 ( V_77 ) ;
int V_141 , V_336 = ( V_77 -> V_145 == V_146 ||
( V_77 -> V_243 & V_166 ) ) ? 0 : 1 ;
V_141 = F_109 ( V_178 , V_336 ) ;
F_110 ( V_178 ) ;
F_77 ( 2000 ) ;
return V_141 ;
}
static int F_111 ( struct V_76 * V_77 )
{
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_75 * V_75 = F_5 ( V_77 ) ;
unsigned long V_127 ;
int V_141 = V_294 ;
if ( V_97 -> V_216 != V_331 )
return V_294 ;
V_97 -> V_216 = V_217 ;
F_74 ( V_75 , V_77 ,
V_259 , 0 ) ;
F_72 ( V_75 , V_77 ) ;
V_141 = F_107 ( V_77 ) ;
if ( V_141 == V_295 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_69 ( V_75 , V_77 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
return V_141 ;
}
static int F_112 ( struct V_76 * V_77 , T_1 * V_126 )
{
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_75 * V_75 = F_5 ( V_77 ) ;
struct V_77 * V_95 = V_75 -> V_95 ;
unsigned long V_127 ;
int V_141 = V_294 ;
V_97 -> V_216 = V_331 ;
if ( F_38 ( V_77 ) ) {
struct V_180 * V_178 ;
V_141 = F_74 ( V_75 , V_77 ,
V_259 , 0 ) ;
if ( V_141 == V_294 )
goto V_129;
F_72 ( V_75 , V_77 ) ;
V_178 = F_108 ( V_77 ) ;
V_141 = F_109 ( V_178 , 1 ) ;
if ( V_141 == 0 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_69 ( V_75 , V_77 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
F_110 ( V_178 ) ;
} else {
struct V_111 V_124 = { . V_112 = V_337 } ;
V_141 = F_31 ( V_77 , V_126 , & V_124 ) ;
if ( V_141 == V_295 ) {
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_69 ( V_75 , V_77 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
}
}
V_129:
if ( V_141 != V_295 )
F_28 ( V_95 , L_30 ,
V_97 -> V_115 , V_141 ) ;
return V_141 ;
}
static int F_113 ( struct V_181 * V_182 )
{
struct V_75 * V_75 = V_182 -> V_80 ;
return F_98 ( V_75 ) ;
}
static int F_114 ( struct V_51 * V_52 )
{
struct V_125 V_126 ;
struct V_111 V_124 ;
int V_141 = V_294 ;
if ( V_52 -> V_103 && V_52 -> V_99 & V_128 ) {
struct V_122 * V_123 = V_52 -> V_72 ;
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_53 * V_54 = V_52 -> V_103 ;
T_2 V_69 = V_54 -> V_108 ;
F_29 ( V_123 -> V_77 -> V_126 , & V_126 ) ;
V_124 . V_112 = V_338 ;
V_124 . V_131 = F_30 ( V_69 ) ;
V_141 = F_31 ( V_77 ,
V_126 . V_125 ,
& V_124 ) ;
switch ( V_141 ) {
case V_296 :
case V_294 :
case V_295 :
break;
default:
V_141 = V_294 ;
break;
}
}
return V_141 ;
}
static int
F_115 ( struct V_75 * V_75 , int V_115 ,
struct V_51 * V_52 , int V_116 ,
int V_339 )
{
struct V_76 * V_77 = V_52 -> V_95 ;
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_81 * V_78 ;
struct V_53 * V_54 ;
struct V_82 * V_83 = V_77 -> V_78 ;
struct V_137 * V_138 ;
struct V_134 * V_135 = V_97 -> V_135 ;
int V_139 , V_140 , V_100 = 0 , V_141 , V_88 ;
unsigned long V_127 , V_340 ;
if ( F_46 ( F_47 ( V_175 , & V_75 -> V_127 ) ) )
return - V_167 ;
if ( ! V_77 -> V_78 )
return - 1 ;
V_78 = F_6 ( V_83 ) ;
F_32 ( & V_75 -> V_132 , V_127 ) ;
V_141 = F_14 ( V_75 , & V_88 ) ;
if ( V_141 ) {
F_33 ( & V_75 -> V_132 , V_127 ) ;
goto V_154;
}
F_33 ( & V_75 -> V_132 , V_127 ) ;
F_32 ( & V_135 -> V_132 , V_340 ) ;
V_141 = V_75 -> V_86 -> V_155 ( V_75 , V_135 ) ;
if ( V_141 )
goto V_156;
V_140 = V_135 -> V_149 ;
V_139 = V_135 -> V_157 ;
V_54 = & V_75 -> V_158 [ V_88 ] ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
V_54 -> V_108 = V_88 ;
V_54 -> V_100 = V_100 ;
V_54 -> V_140 = V_140 ;
V_54 -> V_139 = V_139 ;
V_138 = V_75 -> V_159 [ V_140 ] ;
V_54 -> V_159 = & V_138 [ V_139 ] ;
V_54 -> V_52 = V_52 ;
V_54 -> V_78 = V_78 ;
V_52 -> V_103 = V_54 ;
V_54 -> V_60 = F_41 ( V_75 -> V_105 ,
V_160 , & V_54 -> V_106 ) ;
if ( ! V_54 -> V_60 ) {
V_141 = - V_151 ;
goto V_156;
}
memset ( V_54 -> V_159 , 0 , sizeof( struct V_137 ) ) ;
memset ( F_42 ( V_54 ) , 0 , V_162 ) ;
memset ( F_3 ( V_54 ) , 0 , V_163 ) ;
V_141 = F_26 ( V_75 , V_54 , V_115 ,
V_116 , V_339 ) ;
if ( V_141 )
goto V_168;
F_43 ( & V_54 -> V_107 , & V_97 -> V_169 ) ;
F_32 ( & V_52 -> V_170 , V_127 ) ;
V_52 -> V_171 |= V_172 ;
F_33 ( & V_52 -> V_170 , V_127 ) ;
V_135 -> V_173 = V_54 ;
F_44 ( & V_97 -> V_104 ) ;
V_75 -> V_86 -> V_176 ( V_135 ) ;
F_33 ( & V_135 -> V_132 , V_340 ) ;
return 0 ;
V_168:
F_21 ( V_75 -> V_105 , V_54 -> V_60 ,
V_54 -> V_106 ) ;
V_156:
F_32 ( & V_75 -> V_132 , V_127 ) ;
F_11 ( V_75 , V_88 ) ;
F_33 ( & V_75 -> V_132 , V_127 ) ;
F_33 ( & V_135 -> V_132 , V_340 ) ;
V_154:
F_28 ( V_95 , L_31 , V_141 ) ;
return V_141 ;
}
static int
F_74 ( struct V_75 * V_75 ,
struct V_76 * V_77 ,
int V_116 , int V_69 )
{
struct V_51 * V_52 ;
struct V_96 * V_97 = V_77 -> V_98 ;
struct V_77 * V_95 = V_75 -> V_95 ;
int V_281 ;
if ( ! V_75 -> V_86 -> V_118 )
return - V_274 ;
V_52 = F_83 ( V_284 ) ;
if ( ! V_52 )
return - V_151 ;
V_52 -> V_95 = V_77 ;
V_52 -> V_99 = V_77 -> V_243 ;
V_52 -> V_133 = F_78 ;
V_52 -> V_275 -> V_238 . V_277 = ( unsigned long ) V_52 ;
V_52 -> V_275 -> V_238 . V_289 = F_81 ;
V_52 -> V_275 -> V_238 . V_290 = V_291 + F_116 ( 110 ) ;
F_84 ( & V_52 -> V_275 -> V_238 ) ;
V_281 = F_115 ( V_75 , V_97 -> V_115 ,
V_52 , V_116 , V_69 ) ;
if ( V_281 ) {
F_79 ( & V_52 -> V_275 -> V_238 ) ;
F_28 ( V_95 , L_32 ,
V_281 ) ;
goto exit;
}
F_85 ( & V_52 -> V_275 -> V_276 ) ;
V_281 = V_294 ;
if ( ( V_52 -> V_171 & V_278 ) ) {
if ( ! ( V_52 -> V_171 & V_256 ) ) {
struct V_53 * V_54 = V_52 -> V_103 ;
if ( V_54 )
V_54 -> V_52 = NULL ;
F_28 ( V_95 , L_33 ) ;
}
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_295 ) {
V_281 = V_295 ;
goto exit;
}
if ( V_52 -> V_57 . V_59 == V_253 &&
V_52 -> V_57 . V_143 == V_296 ) {
V_281 = V_296 ;
goto exit;
}
exit:
F_100 ( V_95 , L_34
L_35 ,
F_37 ( V_77 -> V_147 ) ,
V_52 ,
V_52 -> V_57 . V_59 ,
V_52 -> V_57 . V_143 ) ;
F_87 ( V_52 ) ;
return V_281 ;
}
static void F_117 ( struct V_179 * V_180 )
{
F_67 ( V_180 ) ;
}
static void F_118 ( struct V_177 * V_178 )
{
V_178 -> V_183 = 0 ;
V_178 -> V_197 = 0 ;
V_178 -> V_78 = NULL ;
}
void F_96 ( struct V_75 * V_75 , int V_84 , int V_341 )
{
struct V_177 * V_178 = & V_75 -> V_178 [ V_84 ] ;
struct V_179 * V_180 = & V_178 -> V_180 ;
struct V_181 * V_182 = & V_75 -> V_184 ;
if ( V_341 ) {
F_49 ( V_75 , V_84 ) ;
F_67 ( V_180 ) ;
} else {
struct V_81 * V_78 = V_178 -> V_78 ;
V_182 -> V_185 ( V_180 , V_342 ) ;
F_119 ( V_180 ) ;
if ( V_78 ) {
if ( V_178 -> V_197 & V_198 ) {
int V_251 = V_78 -> V_149 ;
if ( ! V_75 -> V_86 -> V_343 ( V_75 ,
V_251 ) )
V_78 -> V_148 = 0 ;
} else if ( V_178 -> V_197 & V_207 )
V_78 -> V_148 = 0 ;
}
F_118 ( V_178 ) ;
}
}
void F_120 ( struct V_75 * V_75 )
{
int V_94 , V_312 , V_344 = V_75 -> V_86 -> V_344 ;
for ( V_94 = 0 ; V_94 < V_75 -> V_215 ; V_94 ++ ) {
struct V_345 * V_346 = & V_75 -> V_346 [ V_94 ] ;
struct V_134 * V_135 = & V_75 -> V_135 [ V_94 ] ;
V_312 = sizeof( struct V_137 ) * V_347 ;
memset ( V_75 -> V_159 [ V_94 ] , 0 , V_312 ) ;
V_135 -> V_157 = 0 ;
V_312 = V_75 -> V_86 -> V_348 * V_347 ;
memset ( V_75 -> V_349 [ V_94 ] , 0 , V_312 ) ;
V_346 -> V_350 = 0 ;
}
V_312 = sizeof( struct V_351 ) * V_75 -> V_85 ;
memset ( V_75 -> V_352 , 0 , V_312 ) ;
V_312 = V_344 * sizeof( struct V_353 ) ;
memset ( V_75 -> V_354 , 0 , V_312 ) ;
V_312 = V_344 * sizeof( struct V_355 ) ;
memset ( V_75 -> V_356 , 0 , V_312 ) ;
V_312 = V_344 * sizeof( struct V_355 ) * 2 ;
memset ( V_75 -> V_357 , 0 , V_312 ) ;
}
int F_121 ( struct V_75 * V_75 , struct V_232 * V_233 )
{
struct V_77 * V_95 = V_75 -> V_95 ;
int V_94 , V_312 , V_344 = V_75 -> V_86 -> V_344 ;
F_122 ( & V_75 -> V_132 ) ;
for ( V_94 = 0 ; V_94 < V_75 -> V_85 ; V_94 ++ ) {
F_65 ( V_75 , V_94 ) ;
V_75 -> V_78 [ V_94 ] . V_148 = 0 ;
V_75 -> V_78 [ V_94 ] . V_149 = - 1 ;
}
for ( V_94 = 0 ; V_94 < V_211 ; V_94 ++ ) {
V_75 -> V_212 [ V_94 ] . V_145 = V_213 ;
V_75 -> V_212 [ V_94 ] . V_115 = V_94 ;
V_75 -> V_212 [ V_94 ] . V_216 = V_217 ;
}
for ( V_94 = 0 ; V_94 < V_75 -> V_215 ; V_94 ++ ) {
struct V_345 * V_346 = & V_75 -> V_346 [ V_94 ] ;
struct V_134 * V_135 = & V_75 -> V_135 [ V_94 ] ;
V_346 -> V_149 = V_94 ;
V_346 -> V_75 = V_75 ;
V_135 -> V_149 = V_94 ;
V_135 -> V_75 = V_75 ;
V_312 = sizeof( struct V_137 ) * V_347 ;
V_75 -> V_159 [ V_94 ] = F_123 ( V_95 , V_312 ,
& V_75 -> V_358 [ V_94 ] , V_284 ) ;
if ( ! V_75 -> V_159 [ V_94 ] )
goto V_154;
V_312 = V_75 -> V_86 -> V_348 * V_347 ;
V_75 -> V_349 [ V_94 ] = F_123 ( V_95 , V_312 ,
& V_75 -> V_359 [ V_94 ] , V_284 ) ;
if ( ! V_75 -> V_349 [ V_94 ] )
goto V_154;
}
V_312 = sizeof( struct V_360 ) ;
V_75 -> V_105 = F_124 ( L_36 , V_95 , V_312 , 16 , 0 ) ;
if ( ! V_75 -> V_105 )
goto V_154;
V_312 = V_361 * sizeof( struct V_362 ) ;
V_75 -> V_363 = F_123 ( V_95 , V_312 , & V_75 -> V_364 ,
V_284 ) ;
if ( ! V_75 -> V_363 )
goto V_154;
memset ( V_75 -> V_363 , 0 , V_312 ) ;
V_75 -> V_158 = F_125 ( V_95 , V_344 ,
sizeof( struct V_53 ) ,
V_284 ) ;
if ( ! V_75 -> V_158 )
goto V_154;
V_312 = V_344 * sizeof( struct V_353 ) ;
V_75 -> V_354 = F_123 ( V_95 , V_312 , & V_75 -> V_365 ,
V_284 ) ;
if ( ! V_75 -> V_354 )
goto V_154;
V_312 = V_344 * sizeof( struct V_355 ) ;
V_75 -> V_356 = F_123 ( V_95 , V_312 ,
& V_75 -> V_366 , V_284 ) ;
if ( ! V_75 -> V_356 )
goto V_154;
V_75 -> V_92 = V_344 ;
V_312 = V_75 -> V_92 / V_367 ;
V_75 -> V_90 = F_126 ( V_95 , V_312 , V_284 ) ;
if ( ! V_75 -> V_90 )
goto V_154;
V_312 = sizeof( struct V_351 ) * V_368 ;
V_75 -> V_352 = F_123 ( V_95 , V_312 ,
& V_75 -> V_369 , V_284 ) ;
if ( ! V_75 -> V_352 )
goto V_154;
V_312 = V_344 * sizeof( struct V_355 ) * 2 ;
V_75 -> V_357 = F_123 ( V_95 , V_312 ,
& V_75 -> V_370 , V_284 ) ;
if ( ! V_75 -> V_357 )
goto V_154;
F_120 ( V_75 ) ;
F_16 ( V_75 ) ;
V_75 -> V_330 = F_127 ( F_128 ( V_95 ) ) ;
if ( ! V_75 -> V_330 ) {
F_28 ( V_95 , L_37 ) ;
goto V_154;
}
return 0 ;
V_154:
return - V_151 ;
}
void F_129 ( struct V_75 * V_75 )
{
struct V_77 * V_95 = V_75 -> V_95 ;
int V_94 , V_312 , V_344 = V_75 -> V_86 -> V_344 ;
for ( V_94 = 0 ; V_94 < V_75 -> V_215 ; V_94 ++ ) {
V_312 = sizeof( struct V_137 ) * V_347 ;
if ( V_75 -> V_159 [ V_94 ] )
F_130 ( V_95 , V_312 ,
V_75 -> V_159 [ V_94 ] ,
V_75 -> V_358 [ V_94 ] ) ;
V_312 = V_75 -> V_86 -> V_348 * V_347 ;
if ( V_75 -> V_349 [ V_94 ] )
F_130 ( V_95 , V_312 ,
V_75 -> V_349 [ V_94 ] ,
V_75 -> V_359 [ V_94 ] ) ;
}
F_131 ( V_75 -> V_105 ) ;
V_312 = V_361 * sizeof( struct V_362 ) ;
if ( V_75 -> V_363 )
F_130 ( V_95 , V_312 ,
V_75 -> V_363 , V_75 -> V_364 ) ;
V_312 = V_344 * sizeof( struct V_353 ) ;
if ( V_75 -> V_354 )
F_130 ( V_95 , V_312 ,
V_75 -> V_354 , V_75 -> V_365 ) ;
V_312 = V_344 * sizeof( struct V_355 ) ;
if ( V_75 -> V_356 )
F_130 ( V_95 , V_312 ,
V_75 -> V_356 ,
V_75 -> V_366 ) ;
V_312 = sizeof( struct V_351 ) * V_368 ;
if ( V_75 -> V_352 )
F_130 ( V_95 , V_312 ,
V_75 -> V_352 ,
V_75 -> V_369 ) ;
V_312 = V_344 * sizeof( struct V_355 ) * 2 ;
if ( V_75 -> V_357 )
F_130 ( V_95 , V_312 ,
V_75 -> V_357 ,
V_75 -> V_370 ) ;
if ( V_75 -> V_330 )
F_132 ( V_75 -> V_330 ) ;
}
static void F_133 ( struct V_119 * V_120 )
{
struct V_75 * V_75 =
F_7 ( V_120 , struct V_75 , V_371 ) ;
F_98 ( V_75 ) ;
}
int F_134 ( struct V_75 * V_75 )
{
struct V_77 * V_95 = V_75 -> V_95 ;
struct V_372 * V_373 = V_75 -> V_374 ;
struct V_375 * V_376 = V_373 ? V_373 -> V_95 . V_377 : NULL ;
struct V_378 * V_379 ;
if ( F_135 ( V_95 , L_38 , V_75 -> V_147 ,
V_380 ) ) {
F_28 ( V_95 , L_39 ) ;
return - V_381 ;
}
if ( V_376 ) {
V_75 -> V_382 = F_136 ( V_376 ,
L_40 ) ;
if ( F_137 ( V_75 -> V_382 ) ) {
F_28 ( V_95 , L_41 ) ;
return - V_381 ;
}
if ( F_138 ( V_95 , L_42 ,
& V_75 -> V_383 ) ) {
F_28 ( V_95 ,
L_43 ) ;
return - V_381 ;
}
if ( F_138 ( V_95 , L_44 ,
& V_75 -> V_384 ) ) {
F_28 ( V_95 ,
L_45 ) ;
return - V_381 ;
}
if ( F_138 ( V_95 , L_46 ,
& V_75 -> V_385 ) ) {
F_28 ( V_95 ,
L_47 ) ;
return - V_381 ;
}
}
V_379 = F_139 ( V_95 , NULL ) ;
if ( F_137 ( V_379 ) )
F_100 ( V_95 , L_48 ) ;
else
V_75 -> V_386 = F_140 ( V_379 ) / 1000000 ;
if ( F_138 ( V_95 , L_49 , & V_75 -> V_85 ) ) {
F_28 ( V_95 , L_50 ) ;
return - V_381 ;
}
if ( F_138 ( V_95 , L_51 ,
& V_75 -> V_215 ) ) {
F_28 ( V_95 , L_52 ) ;
return - V_381 ;
}
return 0 ;
}
static struct V_232 * F_141 ( struct V_372 * V_373 ,
const struct V_387 * V_86 )
{
struct V_388 * V_281 ;
struct V_232 * V_233 ;
struct V_75 * V_75 ;
struct V_77 * V_95 = & V_373 -> V_95 ;
V_233 = F_142 ( V_389 , sizeof( * V_75 ) ) ;
if ( ! V_233 ) {
F_28 ( V_95 , L_53 ) ;
return NULL ;
}
V_75 = F_61 ( V_233 ) ;
F_40 ( & V_75 -> V_371 , F_133 ) ;
V_75 -> V_86 = V_86 ;
V_75 -> V_95 = V_95 ;
V_75 -> V_374 = V_373 ;
V_75 -> V_233 = V_233 ;
F_143 ( V_233 ) = & V_75 -> V_184 ;
F_66 ( & V_75 -> V_238 ) ;
if ( F_134 ( V_75 ) < 0 )
goto V_154;
if ( F_144 ( V_95 , F_145 ( 64 ) ) &&
F_144 ( V_95 , F_145 ( 32 ) ) ) {
F_28 ( V_95 , L_54 ) ;
goto V_154;
}
V_281 = F_146 ( V_373 , V_390 , 0 ) ;
V_75 -> V_391 = F_147 ( V_95 , V_281 ) ;
if ( F_137 ( V_75 -> V_391 ) )
goto V_154;
if ( F_121 ( V_75 , V_233 ) ) {
F_129 ( V_75 ) ;
goto V_154;
}
return V_233 ;
V_154:
F_148 ( V_233 ) ;
F_28 ( V_95 , L_55 ) ;
return NULL ;
}
void F_149 ( struct V_75 * V_75 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_75 -> V_85 ; V_94 ++ )
memcpy ( & V_75 -> V_178 [ V_94 ] . V_392 ,
V_75 -> V_147 ,
V_380 ) ;
}
int F_150 ( struct V_372 * V_373 ,
const struct V_387 * V_86 )
{
struct V_232 * V_233 ;
struct V_75 * V_75 ;
struct V_77 * V_95 = & V_373 -> V_95 ;
struct V_179 * * V_393 ;
struct V_82 * * V_394 ;
struct V_181 * V_184 ;
int V_141 , V_395 , V_396 , V_94 ;
V_233 = F_141 ( V_373 , V_86 ) ;
if ( ! V_233 )
return - V_151 ;
V_184 = F_143 ( V_233 ) ;
V_75 = F_61 ( V_233 ) ;
F_151 ( V_373 , V_184 ) ;
V_395 = V_396 = V_75 -> V_85 ;
V_393 = F_125 ( V_95 , V_395 , sizeof( void * ) , V_284 ) ;
V_394 = F_125 ( V_95 , V_396 , sizeof( void * ) , V_284 ) ;
if ( ! V_393 || ! V_394 ) {
V_141 = - V_151 ;
goto V_397;
}
V_184 -> V_180 = V_393 ;
V_184 -> V_83 = V_394 ;
V_184 -> V_80 = V_75 ;
V_233 -> V_398 = V_399 ;
V_233 -> V_400 = V_211 ;
V_233 -> V_401 = ~ 0 ;
V_233 -> V_402 = 1 ;
V_233 -> V_403 = 16 ;
V_233 -> V_404 = F_152 ( V_405 , V_406 , V_407 ) ;
V_233 -> V_408 = V_75 -> V_86 -> V_344 ;
V_233 -> V_409 = V_75 -> V_86 -> V_344 ;
V_184 -> V_410 = V_411 ;
V_184 -> V_95 = V_75 -> V_95 ;
V_184 -> V_412 = V_413 ;
V_184 -> V_147 = & V_75 -> V_147 [ 0 ] ;
V_184 -> V_225 = V_75 -> V_85 ;
V_184 -> V_414 . V_233 = V_75 -> V_233 ;
for ( V_94 = 0 ; V_94 < V_75 -> V_85 ; V_94 ++ ) {
V_184 -> V_180 [ V_94 ] = & V_75 -> V_178 [ V_94 ] . V_180 ;
V_184 -> V_83 [ V_94 ] = & V_75 -> V_78 [ V_94 ] . V_83 ;
}
F_149 ( V_75 ) ;
V_141 = F_153 ( V_233 , & V_373 -> V_95 ) ;
if ( V_141 )
goto V_397;
V_141 = F_154 ( V_184 ) ;
if ( V_141 )
goto V_415;
V_141 = V_75 -> V_86 -> V_416 ( V_75 ) ;
if ( V_141 )
goto V_415;
F_155 ( V_233 ) ;
return 0 ;
V_415:
F_156 ( V_233 ) ;
V_397:
F_129 ( V_75 ) ;
F_148 ( V_233 ) ;
return V_141 ;
}
int F_157 ( struct V_372 * V_373 )
{
struct V_181 * V_184 = F_158 ( V_373 ) ;
struct V_75 * V_75 = V_184 -> V_80 ;
struct V_232 * V_233 = V_184 -> V_414 . V_233 ;
F_159 ( V_184 ) ;
F_160 ( V_184 -> V_414 . V_233 ) ;
F_129 ( V_75 ) ;
F_148 ( V_233 ) ;
return 0 ;
}
static T_4 int F_161 ( void )
{
V_399 = F_162 ( & V_417 ) ;
if ( ! V_399 )
return - V_151 ;
return 0 ;
}
static T_5 void F_163 ( void )
{
F_164 ( V_399 ) ;
}
