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
return V_36 ;
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
return V_47 ;
default:
if ( V_2 == V_48 )
return V_47 ;
return V_19 ;
}
}
void F_2 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_50 -> V_55 ;
struct V_56 * V_57 = (struct V_56 * ) V_54 -> V_58 ;
struct V_59 * V_60 =
F_3 ( V_52 ) ;
T_1 * V_61 = & V_60 -> V_61 [ 0 ] ;
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
V_57 -> V_64 = sizeof( struct V_62 ) ;
memcpy ( & V_57 -> V_65 [ 0 ] , V_63 , sizeof( struct V_62 ) ) ;
V_54 -> V_66 = sizeof( * V_57 ) ;
}
int F_4 ( struct V_49 * V_50 , T_2 * V_67 )
{
struct V_68 * V_69 = V_50 -> V_70 ;
if ( V_69 ) {
if ( V_69 -> V_71 . V_72 == V_3 ||
V_69 -> V_71 . V_72 == V_4 ) {
* V_67 = V_69 -> V_67 ;
return 1 ;
}
}
return 0 ;
}
static struct V_73 * F_5 ( struct V_74 * V_75 )
{
return V_75 -> V_76 -> V_77 -> V_78 ;
}
struct V_79 * F_6 ( struct V_80 * V_81 )
{
return F_7 ( V_81 , struct V_79 , V_81 ) ;
}
static void F_8 ( struct V_73 * V_73 , int V_82 )
{
void * V_83 = V_73 -> V_84 ;
F_9 ( V_82 , V_83 ) ;
}
static void F_10 ( struct V_73 * V_73 , int V_82 )
{
F_8 ( V_73 , V_82 ) ;
}
static void F_11 ( struct V_73 * V_73 , int V_82 )
{
void * V_83 = V_73 -> V_84 ;
F_12 ( V_82 , V_83 ) ;
}
static int F_13 ( struct V_73 * V_73 , int * V_82 )
{
unsigned int V_85 ;
void * V_83 = V_73 -> V_84 ;
V_85 = F_14 ( V_83 , V_73 -> V_86 ) ;
if ( V_85 >= V_73 -> V_86 )
return - V_87 ;
F_11 ( V_73 , V_85 ) ;
* V_82 = V_85 ;
return 0 ;
}
static void F_15 ( struct V_73 * V_73 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_73 -> V_86 ; ++ V_88 )
F_8 ( V_73 , V_88 ) ;
}
void F_16 ( struct V_73 * V_73 , struct V_49 * V_50 ,
struct V_51 * V_52 )
{
if ( V_50 ) {
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_90 * V_91 = V_75 -> V_92 ;
if ( ! F_17 ( V_50 -> V_93 ) )
if ( V_52 -> V_94 )
F_18 ( V_89 , V_50 -> V_95 , V_52 -> V_94 ,
V_50 -> V_96 ) ;
V_50 -> V_97 = NULL ;
if ( V_91 )
F_19 ( & V_91 -> V_98 ) ;
}
if ( V_52 -> V_58 )
F_20 ( V_73 -> V_99 , V_52 -> V_58 , V_52 -> V_100 ) ;
F_21 ( & V_52 -> V_101 ) ;
V_52 -> V_50 = NULL ;
V_52 -> V_76 = NULL ;
F_10 ( V_73 , V_52 -> V_102 ) ;
}
static int F_22 ( struct V_73 * V_73 ,
struct V_51 * V_52 )
{
return V_73 -> V_103 -> V_104 ( V_73 , V_52 ) ;
}
static int F_23 ( struct V_73 * V_73 ,
struct V_51 * V_52 , int V_105 ,
struct V_106 * V_107 )
{
return V_73 -> V_103 -> V_108 ( V_73 , V_52 , V_105 , V_107 ) ;
}
static int F_24 ( struct V_73 * V_73 ,
struct V_51 * V_52 )
{
return V_73 -> V_103 -> V_109 ( V_73 , V_52 ) ;
}
static int F_25 ( struct V_73 * V_73 ,
struct V_51 * V_52 ,
int V_110 , int V_111 , int V_112 )
{
return V_73 -> V_103 -> V_113 ( V_73 , V_52 ,
V_110 , V_111 , V_112 ) ;
}
static void F_26 ( struct V_114 * V_115 )
{
struct V_51 * V_116 =
F_7 ( V_115 , struct V_51 , V_116 ) ;
struct V_49 * V_50 = V_116 -> V_50 ;
struct V_73 * V_73 = F_5 ( V_50 -> V_89 ) ;
struct V_117 * V_118 = V_50 -> V_70 ;
struct V_106 V_119 ;
struct V_120 V_121 ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_67 = V_116 -> V_102 ;
unsigned long V_122 ;
if ( ! ( V_50 -> V_93 & V_123 ) ) {
F_27 ( V_89 , L_1 ) ;
goto V_124;
}
F_28 ( V_118 -> V_75 -> V_121 , & V_121 ) ;
V_119 . V_107 = V_125 ;
V_119 . V_126 = F_29 ( V_67 ) ;
F_30 ( V_50 -> V_89 , V_121 . V_120 , & V_119 ) ;
V_124:
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_16 ( V_73 , V_50 , V_116 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
if ( V_50 -> V_128 )
V_50 -> V_128 ( V_50 ) ;
}
static int F_33 ( struct V_49 * V_50 , struct V_129
* V_130 , int V_105 , struct V_106 * V_107 ,
int * V_131 )
{
struct V_73 * V_73 = V_130 -> V_73 ;
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_79 * V_76 ;
struct V_51 * V_52 ;
struct V_132 * V_133 ;
struct V_80 * V_81 = V_75 -> V_76 ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_134 , V_135 , V_94 = 0 , V_136 , V_82 ;
unsigned long V_122 ;
if ( ! V_81 ) {
struct V_53 * V_54 = & V_50 -> V_55 ;
V_54 -> V_57 = V_137 ;
V_54 -> V_138 = V_139 ;
if ( V_75 -> V_140 != V_141 )
V_50 -> V_128 ( V_50 ) ;
return V_139 ;
}
if ( F_34 ( V_91 ) ) {
if ( V_91 )
F_35 ( V_89 , L_2 ,
V_91 -> V_110 ) ;
else
F_35 ( V_89 , L_3 ,
F_36 ( V_75 -> V_142 ) ) ;
return V_139 ;
}
V_76 = F_6 ( V_81 ) ;
if ( V_76 && ! V_76 -> V_143 ) {
F_35 ( V_89 , L_4 ,
( F_37 ( V_75 ) ) ?
L_5 : L_6 ,
V_75 -> V_76 -> V_144 ) ;
return V_139 ;
}
if ( ! F_17 ( V_50 -> V_93 ) ) {
if ( V_50 -> V_145 ) {
V_94 = F_38 ( V_89 , V_50 -> V_95 ,
V_50 -> V_145 , V_50 -> V_96 ) ;
if ( ! V_94 ) {
V_136 = - V_146 ;
goto V_147;
}
}
} else
V_94 = V_50 -> V_145 ;
F_31 ( & V_73 -> V_127 , V_122 ) ;
if ( V_73 -> V_103 -> V_148 )
V_136 = V_73 -> V_103 -> V_148 ( V_73 , & V_82 ,
V_75 ) ;
else
V_136 = F_13 ( V_73 , & V_82 ) ;
if ( V_136 ) {
F_32 ( & V_73 -> V_127 , V_122 ) ;
goto V_149;
}
F_32 ( & V_73 -> V_127 , V_122 ) ;
V_136 = V_73 -> V_103 -> V_150 ( V_73 , V_130 ) ;
if ( V_136 )
goto V_151;
V_135 = V_130 -> V_144 ;
V_134 = V_130 -> V_152 ;
V_52 = & V_73 -> V_153 [ V_82 ] ;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> V_102 = V_82 ;
V_52 -> V_94 = V_94 ;
V_52 -> V_135 = V_135 ;
V_52 -> V_134 = V_134 ;
V_133 = V_73 -> V_154 [ V_135 ] ;
V_52 -> V_154 = & V_133 [ V_134 ] ;
V_52 -> V_50 = V_50 ;
V_52 -> V_76 = V_76 ;
V_50 -> V_97 = V_52 ;
F_39 ( & V_52 -> V_116 , F_26 ) ;
V_52 -> V_58 = F_40 ( V_73 -> V_99 ,
V_155 , & V_52 -> V_100 ) ;
if ( ! V_52 -> V_58 ) {
V_136 = - V_146 ;
goto V_156;
}
memset ( V_52 -> V_154 , 0 , sizeof( struct V_132 ) ) ;
memset ( F_41 ( V_52 ) , 0 , V_157 ) ;
memset ( F_3 ( V_52 ) , 0 , V_158 ) ;
switch ( V_50 -> V_93 ) {
case V_159 :
V_136 = F_22 ( V_73 , V_52 ) ;
break;
case V_123 :
V_136 = F_23 ( V_73 , V_52 , V_105 , V_107 ) ;
break;
case V_160 :
case V_161 :
case V_160 | V_161 :
V_136 = F_24 ( V_73 , V_52 ) ;
break;
default:
F_27 ( V_89 , L_7 ,
V_50 -> V_93 ) ;
V_136 = - V_162 ;
break;
}
if ( V_136 ) {
F_27 ( V_89 , L_8 , V_136 ) ;
goto V_163;
}
F_42 ( & V_52 -> V_101 , & V_91 -> V_164 ) ;
F_31 ( & V_50 -> V_165 , V_122 ) ;
V_50 -> V_166 |= V_167 ;
F_32 ( & V_50 -> V_165 , V_122 ) ;
V_130 -> V_168 = V_52 ;
F_43 ( & V_91 -> V_98 ) ;
++ ( * V_131 ) ;
return 0 ;
V_163:
F_20 ( V_73 -> V_99 , V_52 -> V_58 ,
V_52 -> V_100 ) ;
V_156:
V_151:
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_10 ( V_73 , V_82 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
V_149:
F_27 ( V_89 , L_9 , V_136 ) ;
if ( ! F_17 ( V_50 -> V_93 ) )
if ( V_94 )
F_18 ( V_89 , V_50 -> V_95 , V_94 ,
V_50 -> V_96 ) ;
V_147:
return V_136 ;
}
static int F_44 ( struct V_49 * V_50 , T_3 V_169 ,
int V_105 , struct V_106 * V_107 )
{
T_2 V_136 ;
T_2 V_131 = 0 ;
unsigned long V_122 ;
struct V_73 * V_73 = F_5 ( V_50 -> V_89 ) ;
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_129 * V_130 = V_91 -> V_130 ;
if ( F_45 ( F_46 ( V_170 , & V_73 -> V_122 ) ) )
return - V_162 ;
F_31 ( & V_130 -> V_127 , V_122 ) ;
V_136 = F_33 ( V_50 , V_130 , V_105 , V_107 , & V_131 ) ;
if ( V_136 )
F_27 ( V_89 , L_10 , V_136 ) ;
if ( F_47 ( V_131 ) )
V_73 -> V_103 -> V_171 ( V_130 ) ;
F_32 ( & V_130 -> V_127 , V_122 ) ;
return V_136 ;
}
static void F_48 ( struct V_73 * V_73 , int V_172 )
{
struct V_173 * V_174 = & V_73 -> V_174 [ V_172 ] ;
struct V_175 * V_176 = & V_174 -> V_176 ;
struct V_177 * V_178 ;
if ( ! V_174 -> V_179 )
return;
V_178 = & V_73 -> V_180 ;
V_178 -> V_181 ( V_176 , V_182 ) ;
if ( V_176 -> V_174 ) {
struct V_176 * V_183 = V_176 -> V_174 ;
V_183 -> V_184 = V_176 -> V_185 ;
V_183 -> V_186 = V_187 ;
V_183 -> V_188 =
V_73 -> V_103 -> V_189 () ;
if ( V_183 -> V_190 == V_191 )
V_183 -> V_190 = V_174 -> V_190 ;
if ( V_183 -> V_192 == V_191 )
V_183 -> V_192 = V_174 -> V_192 ;
}
if ( V_174 -> V_193 & V_194 ) {
struct V_195 * V_144 ;
V_144 = (struct V_195 * ) V_174 -> V_196 ;
V_144 -> V_140 = V_174 -> V_197 . V_198 ;
V_144 -> V_199 = V_200 ;
V_144 -> V_201 = V_174 -> V_197 . V_202 ;
} else if ( V_174 -> V_193 & V_203 ) {
}
V_176 -> V_204 = V_174 -> V_204 ;
V_178 -> V_205 ( V_176 , V_206 ) ;
}
static struct V_90 * F_49 ( struct V_74 * V_75 )
{
struct V_73 * V_73 = F_5 ( V_75 ) ;
struct V_90 * V_91 = NULL ;
int V_88 ;
F_50 ( & V_73 -> V_127 ) ;
for ( V_88 = 0 ; V_88 < V_207 ; V_88 ++ ) {
if ( V_73 -> V_208 [ V_88 ] . V_140 == V_209 ) {
int V_210 = V_88 % V_73 -> V_211 ;
struct V_129 * V_130 = & V_73 -> V_130 [ V_210 ] ;
V_73 -> V_208 [ V_88 ] . V_110 = V_88 ;
V_91 = & V_73 -> V_208 [ V_88 ] ;
V_91 -> V_212 = V_213 ;
V_91 -> V_140 = V_75 -> V_140 ;
V_91 -> V_73 = V_73 ;
V_91 -> V_214 = V_75 ;
V_91 -> V_130 = V_130 ;
F_51 ( & V_73 -> V_208 [ V_88 ] . V_164 ) ;
break;
}
}
F_52 ( & V_73 -> V_127 ) ;
return V_91 ;
}
static int F_53 ( struct V_74 * V_75 )
{
struct V_73 * V_73 = F_5 ( V_75 ) ;
struct V_74 * V_215 = V_75 -> V_216 ;
struct V_90 * V_91 ;
struct V_75 * V_89 = V_73 -> V_89 ;
if ( V_73 -> V_103 -> V_217 )
V_91 = V_73 -> V_103 -> V_217 ( V_75 ) ;
else
V_91 = F_49 ( V_75 ) ;
if ( ! V_91 ) {
F_27 ( V_89 , L_11 ,
V_207 ) ;
return - V_162 ;
}
V_75 -> V_92 = V_91 ;
V_73 -> V_103 -> V_218 ( V_73 , V_91 ) ;
if ( V_215 && F_54 ( V_215 -> V_140 ) ) {
int V_172 ;
T_1 V_219 = V_215 -> V_220 . V_221 ;
struct V_222 * V_174 ;
for ( V_172 = 0 ; V_172 < V_219 ; V_172 ++ ) {
V_174 = & V_215 -> V_220 . V_222 [ V_172 ] ;
if ( F_36 ( V_174 -> V_223 ) ==
F_36 ( V_75 -> V_142 ) ) {
V_91 -> V_224 = V_172 ;
break;
}
}
if ( V_172 == V_219 ) {
F_35 ( V_89 , L_12
L_13 ,
F_36 ( V_75 -> V_142 ) ,
F_36 ( V_215 -> V_142 ) ) ;
return - V_162 ;
}
}
return 0 ;
}
static int F_55 ( struct V_225 * V_226 )
{
struct V_74 * V_89 = F_56 ( V_226 ) ;
int V_227 = F_57 ( V_226 ) ;
if ( V_227 )
return V_227 ;
if ( ! F_37 ( V_89 ) )
F_58 ( V_226 , 64 ) ;
return 0 ;
}
static void F_59 ( struct V_228 * V_229 )
{
struct V_73 * V_73 = F_60 ( V_229 ) ;
V_73 -> V_103 -> V_230 ( V_73 ) ;
}
static int F_61 ( struct V_228 * V_229 , unsigned long time )
{
struct V_73 * V_73 = F_60 ( V_229 ) ;
struct V_177 * V_180 = & V_73 -> V_180 ;
if ( time < V_231 )
return 0 ;
F_62 ( V_180 ) ;
return 1 ;
}
static void F_63 ( struct V_114 * V_115 )
{
struct V_173 * V_174 =
F_7 ( V_115 , struct V_173 , V_232 ) ;
struct V_73 * V_73 = V_174 -> V_73 ;
struct V_175 * V_176 = & V_174 -> V_176 ;
int V_172 = V_176 -> V_144 ;
V_73 -> V_103 -> V_233 ( V_73 , V_172 ) ;
F_48 ( V_73 , V_172 ) ;
}
static void F_64 ( struct V_73 * V_73 , int V_172 )
{
struct V_173 * V_174 = & V_73 -> V_174 [ V_172 ] ;
struct V_175 * V_176 = & V_174 -> V_176 ;
V_174 -> V_73 = V_73 ;
V_174 -> V_76 = NULL ;
F_65 ( & V_174 -> V_234 ) ;
V_176 -> V_235 = ( V_172 < V_73 -> V_236 ) ? 1 : 0 ;
V_176 -> V_237 = V_238 ;
V_176 -> V_239 = V_200 ;
V_176 -> V_240 = 0 ;
V_176 -> type = V_241 ;
V_176 -> V_242 = V_243 ;
V_176 -> V_244 = V_245 ;
V_176 -> V_185 = V_191 ;
V_176 -> V_144 = V_172 ;
V_176 -> V_142 = & V_73 -> V_142 [ 0 ] ;
V_176 -> V_196 = & V_174 -> V_196 [ 0 ] ;
V_176 -> V_77 = (struct V_177 * ) V_73 -> V_229 -> V_246 ;
V_176 -> V_247 = V_174 ;
F_39 ( & V_174 -> V_232 , F_63 ) ;
}
static void F_66 ( struct V_175 * V_176 )
{
struct V_177 * V_178 = V_176 -> V_77 ;
struct V_73 * V_73 = V_178 -> V_78 ;
struct V_173 * V_174 = V_176 -> V_247 ;
struct V_80 * V_81 = V_176 -> V_76 ;
struct V_79 * V_76 = F_6 ( V_81 ) ;
unsigned long V_122 ;
if ( ! V_81 )
return;
F_31 ( & V_73 -> V_127 , V_122 ) ;
V_76 -> V_143 = 1 ;
V_76 -> V_144 = V_174 -> V_248 ;
V_174 -> V_76 = V_76 ;
V_81 -> V_249 = V_76 ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
static void F_67 ( struct V_73 * V_73 , struct V_49 * V_50 ,
struct V_51 * V_52 )
{
if ( V_50 ) {
unsigned long V_122 ;
struct V_53 * V_54 ;
V_54 = & V_50 -> V_55 ;
V_54 -> V_57 = V_250 ;
V_54 -> V_138 = V_251 ;
F_31 ( & V_50 -> V_165 , V_122 ) ;
V_50 -> V_166 &=
~ ( V_252 | V_167 ) ;
V_50 -> V_166 |= V_253 ;
F_32 ( & V_50 -> V_165 , V_122 ) ;
}
F_16 ( V_73 , V_50 , V_52 ) ;
}
static void F_68 ( struct V_73 * V_73 ,
struct V_74 * V_75 )
{
struct V_51 * V_52 , * V_254 ;
struct V_90 * V_91 = V_75 -> V_92 ;
F_69 (slot, slot2, &sas_dev->list, entry)
F_67 ( V_73 , V_52 -> V_50 , V_52 ) ;
}
static void F_70 ( struct V_73 * V_73 )
{
struct V_90 * V_91 ;
struct V_74 * V_75 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_207 ; V_88 ++ ) {
V_91 = & V_73 -> V_208 [ V_88 ] ;
V_75 = V_91 -> V_214 ;
if ( ( V_91 -> V_140 == V_209 ) ||
! V_75 )
continue;
F_68 ( V_73 , V_75 ) ;
}
}
static void F_71 ( struct V_73 * V_73 ,
struct V_74 * V_75 )
{
if ( V_73 -> V_103 -> V_255 )
V_73 -> V_103 -> V_255 ( V_73 , V_75 ) ;
}
static void F_72 ( struct V_74 * V_75 )
{
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_73 * V_73 = F_5 ( V_75 ) ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_256 = V_91 -> V_110 ;
F_35 ( V_89 , L_14 ,
V_91 -> V_110 , V_91 -> V_140 ) ;
F_73 ( V_73 , V_75 ,
V_257 , 0 ) ;
F_71 ( V_73 , V_75 ) ;
V_73 -> V_103 -> V_258 ( V_73 , V_91 ) ;
V_75 -> V_92 = NULL ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_91 -> V_110 = V_256 ;
V_91 -> V_140 = V_209 ;
V_91 -> V_212 = V_213 ;
}
static int F_74 ( struct V_49 * V_50 , T_3 V_169 )
{
return F_44 ( V_50 , V_169 , 0 , NULL ) ;
}
static int F_75 ( struct V_175 * V_176 , enum V_259 V_260 ,
void * V_261 )
{
struct V_177 * V_178 = V_176 -> V_77 ;
struct V_73 * V_73 = V_178 -> V_78 ;
int V_172 = V_176 -> V_144 ;
switch ( V_260 ) {
case V_262 :
V_73 -> V_103 -> V_263 ( V_73 , V_172 ) ;
break;
case V_264 :
V_73 -> V_103 -> V_265 ( V_73 , V_172 ) ;
F_76 ( 100 ) ;
V_73 -> V_103 -> V_266 ( V_73 , V_172 ) ;
break;
case V_267 :
V_73 -> V_103 -> V_265 ( V_73 , V_172 ) ;
break;
case V_268 :
V_73 -> V_103 -> V_269 ( V_73 , V_172 , V_261 ) ;
break;
case V_270 :
default:
return - V_271 ;
}
return 0 ;
}
static void F_77 ( struct V_49 * V_50 )
{
if ( ! F_78 ( & V_50 -> V_272 -> V_234 ) )
return;
F_79 ( & V_50 -> V_272 -> V_273 ) ;
}
static void F_80 ( unsigned long V_274 )
{
struct V_49 * V_50 = (struct V_49 * ) V_274 ;
unsigned long V_122 ;
F_31 ( & V_50 -> V_165 , V_122 ) ;
if ( ! ( V_50 -> V_166 & V_253 ) )
V_50 -> V_166 |= V_275 ;
F_32 ( & V_50 -> V_165 , V_122 ) ;
F_79 ( & V_50 -> V_272 -> V_273 ) ;
}
static int F_81 ( struct V_74 * V_75 ,
void * V_276 , T_2 V_277 ,
struct V_106 * V_107 )
{
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_73 * V_73 = V_91 -> V_73 ;
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_49 * V_50 ;
int V_278 , V_279 ;
for ( V_279 = 0 ; V_279 < V_280 ; V_279 ++ ) {
V_50 = F_82 ( V_281 ) ;
if ( ! V_50 )
return - V_146 ;
V_50 -> V_89 = V_75 ;
V_50 -> V_93 = V_75 -> V_240 ;
if ( F_37 ( V_75 ) ) {
V_50 -> V_282 . V_283 = 1 ;
memcpy ( & V_50 -> V_282 . V_284 , V_276 , V_277 ) ;
} else {
memcpy ( & V_50 -> V_285 , V_276 , V_277 ) ;
}
V_50 -> V_128 = F_77 ;
V_50 -> V_272 -> V_234 . V_274 = ( unsigned long ) V_50 ;
V_50 -> V_272 -> V_234 . V_286 = F_80 ;
V_50 -> V_272 -> V_234 . V_287 = V_288 + V_289 * V_231 ;
F_83 ( & V_50 -> V_272 -> V_234 ) ;
V_278 = F_44 ( V_50 , V_281 , 1 , V_107 ) ;
if ( V_278 ) {
F_78 ( & V_50 -> V_272 -> V_234 ) ;
F_27 ( V_89 , L_15 ,
V_278 ) ;
goto V_290;
}
F_84 ( & V_50 -> V_272 -> V_273 ) ;
V_278 = V_291 ;
if ( ( V_50 -> V_166 & V_275 ) ) {
if ( ! ( V_50 -> V_166 & V_253 ) ) {
struct V_51 * V_52 = V_50 -> V_97 ;
F_27 ( V_89 , L_16 ) ;
if ( V_52 )
V_52 -> V_50 = NULL ;
goto V_290;
}
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_292 ) {
V_278 = V_292 ;
break;
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_293 ) {
V_278 = V_293 ;
break;
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_294 ) {
F_85 ( V_89 , L_17
L_18 ,
F_36 ( V_75 -> V_142 ) ,
V_50 -> V_55 . V_57 ,
V_50 -> V_55 . V_138 ) ;
V_278 = V_50 -> V_55 . V_295 ;
break;
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_296 ) {
F_85 ( V_89 , L_19 ) ;
V_278 = - V_297 ;
break;
}
F_85 ( V_89 , L_20
L_21 ,
F_36 ( V_75 -> V_142 ) , V_50 -> V_55 . V_57 ,
V_50 -> V_55 . V_138 ) ;
F_86 ( V_50 ) ;
V_50 = NULL ;
}
V_290:
if ( V_279 == V_280 )
F_85 ( V_89 , L_22 ) ;
F_86 ( V_50 ) ;
return V_278 ;
}
static void F_87 ( struct V_298 * V_89 ,
bool V_299 , int V_300 , T_1 * V_284 )
{
struct V_301 V_71 ;
F_88 ( V_89 , & V_71 ) ;
if ( V_299 )
V_71 . V_302 |= V_303 ;
else
V_71 . V_302 &= ~ V_303 ;
V_71 . V_72 = V_38 ;
F_89 ( & V_71 , V_300 , 0 , V_284 ) ;
}
static int F_90 ( struct V_74 * V_75 )
{
T_1 V_284 [ 20 ] = { 0 } ;
struct V_304 * V_305 = V_75 -> V_306 . V_305 ;
struct V_307 * V_308 ;
int V_136 = V_291 ;
struct V_73 * V_73 = F_5 ( V_75 ) ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_309 = sizeof( struct V_310 ) ;
unsigned long V_122 ;
F_91 (link, ap, EDGE) {
int V_300 = F_92 ( V_308 ) ;
F_87 ( V_308 -> V_75 , 1 , V_300 , V_284 ) ;
V_136 = F_81 ( V_75 , V_284 , V_309 , NULL ) ;
if ( V_136 != V_292 )
break;
}
if ( V_136 == V_292 ) {
F_91 (link, ap, EDGE) {
int V_300 = F_92 ( V_308 ) ;
F_87 ( V_308 -> V_75 , 0 , V_300 , V_284 ) ;
V_136 = F_81 ( V_75 , V_284 ,
V_309 , NULL ) ;
if ( V_136 != V_292 )
F_27 ( V_89 , L_23 ) ;
}
} else {
F_27 ( V_89 , L_24 ) ;
}
if ( V_136 == V_292 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_68 ( V_73 , V_75 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
return V_136 ;
}
static int F_30 ( struct V_74 * V_75 ,
T_1 * V_121 , struct V_106 * V_107 )
{
struct V_311 V_285 ;
if ( ! ( V_75 -> V_240 & V_123 ) )
return V_312 ;
memcpy ( V_285 . V_313 , V_121 , 8 ) ;
return F_81 ( V_75 , & V_285 ,
sizeof( V_285 ) , V_107 ) ;
}
static int F_93 ( struct V_73 * V_73 )
{
int V_136 ;
if ( ! V_73 -> V_103 -> V_314 )
return - 1 ;
if ( ! F_94 ( V_170 , & V_73 -> V_122 ) ) {
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_177 * V_178 = & V_73 -> V_180 ;
unsigned long V_122 ;
F_95 ( V_89 , L_25 ) ;
F_96 ( V_73 -> V_229 ) ;
V_136 = V_73 -> V_103 -> V_314 ( V_73 ) ;
if ( V_136 ) {
F_85 ( V_89 , L_26 , V_136 ) ;
goto V_124;
}
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_70 ( V_73 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
V_178 -> V_315 ( V_178 , V_316 ) ;
F_95 ( V_89 , L_27 ) ;
} else
return - 1 ;
V_124:
F_97 ( V_73 -> V_229 ) ;
F_9 ( V_170 , & V_73 -> V_122 ) ;
return V_136 ;
}
static int F_98 ( struct V_49 * V_50 )
{
struct V_120 V_121 ;
struct V_106 V_119 ;
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_73 * V_73 = F_5 ( V_50 -> V_89 ) ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_136 = V_291 ;
unsigned long V_122 ;
if ( ! V_91 ) {
F_85 ( V_89 , L_28 ) ;
return V_291 ;
}
if ( V_50 -> V_166 & V_253 ) {
V_136 = V_292 ;
goto V_124;
}
V_91 -> V_212 = V_317 ;
if ( V_50 -> V_97 && V_50 -> V_93 & V_123 ) {
struct V_117 * V_118 = V_50 -> V_70 ;
struct V_51 * V_52 = V_50 -> V_97 ;
T_2 V_67 = V_52 -> V_102 ;
int V_318 ;
F_28 ( V_118 -> V_75 -> V_121 , & V_121 ) ;
V_119 . V_107 = V_125 ;
V_119 . V_126 = F_29 ( V_67 ) ;
V_136 = F_30 ( V_50 -> V_89 , V_121 . V_120 ,
& V_119 ) ;
V_318 = F_73 ( V_73 , V_75 ,
V_319 , V_67 ) ;
if ( V_136 == V_292 && V_318 != V_293 ) {
if ( V_50 -> V_97 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_67 ( V_73 , V_50 , V_52 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
}
} else if ( V_50 -> V_93 & V_160 ||
V_50 -> V_93 & V_161 ) {
if ( V_50 -> V_89 -> V_140 == V_141 ) {
F_73 ( V_73 , V_75 ,
V_257 , 0 ) ;
F_71 ( V_73 , V_75 ) ;
V_136 = F_90 ( V_75 ) ;
}
} else if ( V_50 -> V_97 && V_50 -> V_93 & V_159 ) {
struct V_51 * V_52 = V_50 -> V_97 ;
T_2 V_67 = V_52 -> V_102 ;
V_136 = F_73 ( V_73 , V_75 ,
V_319 , V_67 ) ;
if ( V_136 == V_291 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_67 ( V_73 , V_50 , V_52 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
}
V_124:
if ( V_136 != V_292 )
F_99 ( V_89 , L_29 , V_136 ) ;
return V_136 ;
}
static int F_100 ( struct V_74 * V_75 , T_1 * V_121 )
{
struct V_106 V_119 ;
int V_136 = V_291 ;
V_119 . V_107 = V_320 ;
V_136 = F_30 ( V_75 , V_121 , & V_119 ) ;
return V_136 ;
}
static int F_101 ( struct V_74 * V_75 , T_1 * V_121 )
{
int V_136 = V_291 ;
struct V_106 V_119 ;
V_119 . V_107 = V_321 ;
V_136 = F_30 ( V_75 , V_121 , & V_119 ) ;
return V_136 ;
}
static int F_102 ( struct V_74 * V_75 )
{
struct V_176 * V_174 = F_103 ( V_75 ) ;
int V_136 , V_322 = ( V_75 -> V_140 == V_141 ||
( V_75 -> V_240 & V_161 ) ) ? 0 : 1 ;
V_136 = F_104 ( V_174 , V_322 ) ;
F_105 ( V_174 ) ;
F_76 ( 2000 ) ;
return V_136 ;
}
static int F_106 ( struct V_74 * V_75 )
{
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_73 * V_73 = F_5 ( V_75 ) ;
unsigned long V_122 ;
int V_136 = V_291 ;
if ( V_91 -> V_212 != V_317 )
return V_291 ;
V_91 -> V_212 = V_213 ;
F_73 ( V_73 , V_75 ,
V_257 , 0 ) ;
F_71 ( V_73 , V_75 ) ;
V_136 = F_102 ( V_75 ) ;
if ( V_136 == V_292 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_68 ( V_73 , V_75 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
return V_136 ;
}
static int F_107 ( struct V_74 * V_75 , T_1 * V_121 )
{
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_73 * V_73 = F_5 ( V_75 ) ;
struct V_75 * V_89 = V_73 -> V_89 ;
unsigned long V_122 ;
int V_136 = V_291 ;
V_91 -> V_212 = V_317 ;
if ( F_37 ( V_75 ) ) {
struct V_176 * V_174 ;
V_136 = F_73 ( V_73 , V_75 ,
V_257 , 0 ) ;
if ( V_136 == V_291 )
goto V_124;
F_71 ( V_73 , V_75 ) ;
V_174 = F_103 ( V_75 ) ;
V_136 = F_104 ( V_174 , 1 ) ;
if ( V_136 == 0 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_68 ( V_73 , V_75 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
F_105 ( V_174 ) ;
} else {
struct V_106 V_119 = { . V_107 = V_323 } ;
V_136 = F_30 ( V_75 , V_121 , & V_119 ) ;
if ( V_136 == V_292 ) {
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_68 ( V_73 , V_75 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
}
}
V_124:
if ( V_136 != V_292 )
F_27 ( V_89 , L_30 ,
V_91 -> V_110 , V_136 ) ;
return V_136 ;
}
static int F_108 ( struct V_177 * V_178 )
{
struct V_73 * V_73 = V_178 -> V_78 ;
return F_93 ( V_73 ) ;
}
static int F_109 ( struct V_49 * V_50 )
{
struct V_120 V_121 ;
struct V_106 V_119 ;
int V_136 = V_291 ;
if ( V_50 -> V_97 && V_50 -> V_93 & V_123 ) {
struct V_117 * V_118 = V_50 -> V_70 ;
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_51 * V_52 = V_50 -> V_97 ;
T_2 V_67 = V_52 -> V_102 ;
F_28 ( V_118 -> V_75 -> V_121 , & V_121 ) ;
V_119 . V_107 = V_324 ;
V_119 . V_126 = F_29 ( V_67 ) ;
V_136 = F_30 ( V_75 ,
V_121 . V_120 ,
& V_119 ) ;
switch ( V_136 ) {
case V_293 :
case V_291 :
case V_292 :
break;
default:
V_136 = V_291 ;
break;
}
}
return V_136 ;
}
static int
F_110 ( struct V_73 * V_73 , int V_110 ,
struct V_49 * V_50 , int V_111 ,
int V_325 )
{
struct V_74 * V_75 = V_50 -> V_89 ;
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_79 * V_76 ;
struct V_51 * V_52 ;
struct V_80 * V_81 = V_75 -> V_76 ;
struct V_132 * V_133 ;
struct V_129 * V_130 = V_91 -> V_130 ;
int V_134 , V_135 , V_94 = 0 , V_136 , V_82 ;
unsigned long V_122 , V_326 ;
if ( F_45 ( F_46 ( V_170 , & V_73 -> V_122 ) ) )
return - V_162 ;
if ( ! V_75 -> V_76 )
return - 1 ;
V_76 = F_6 ( V_81 ) ;
F_31 ( & V_73 -> V_127 , V_122 ) ;
V_136 = F_13 ( V_73 , & V_82 ) ;
if ( V_136 ) {
F_32 ( & V_73 -> V_127 , V_122 ) ;
goto V_149;
}
F_32 ( & V_73 -> V_127 , V_122 ) ;
F_31 ( & V_130 -> V_127 , V_326 ) ;
V_136 = V_73 -> V_103 -> V_150 ( V_73 , V_130 ) ;
if ( V_136 )
goto V_151;
V_135 = V_130 -> V_144 ;
V_134 = V_130 -> V_152 ;
V_52 = & V_73 -> V_153 [ V_82 ] ;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> V_102 = V_82 ;
V_52 -> V_94 = V_94 ;
V_52 -> V_135 = V_135 ;
V_52 -> V_134 = V_134 ;
V_133 = V_73 -> V_154 [ V_135 ] ;
V_52 -> V_154 = & V_133 [ V_134 ] ;
V_52 -> V_50 = V_50 ;
V_52 -> V_76 = V_76 ;
V_50 -> V_97 = V_52 ;
memset ( V_52 -> V_154 , 0 , sizeof( struct V_132 ) ) ;
V_136 = F_25 ( V_73 , V_52 , V_110 ,
V_111 , V_325 ) ;
if ( V_136 )
goto V_151;
F_42 ( & V_52 -> V_101 , & V_91 -> V_164 ) ;
F_31 ( & V_50 -> V_165 , V_122 ) ;
V_50 -> V_166 |= V_167 ;
F_32 ( & V_50 -> V_165 , V_122 ) ;
V_130 -> V_168 = V_52 ;
F_43 ( & V_91 -> V_98 ) ;
V_73 -> V_103 -> V_171 ( V_130 ) ;
F_32 ( & V_130 -> V_127 , V_326 ) ;
return 0 ;
V_151:
F_31 ( & V_73 -> V_127 , V_122 ) ;
F_10 ( V_73 , V_82 ) ;
F_32 ( & V_73 -> V_127 , V_122 ) ;
F_32 ( & V_130 -> V_127 , V_326 ) ;
V_149:
F_27 ( V_89 , L_31 , V_136 ) ;
return V_136 ;
}
static int
F_73 ( struct V_73 * V_73 ,
struct V_74 * V_75 ,
int V_111 , int V_67 )
{
struct V_49 * V_50 ;
struct V_90 * V_91 = V_75 -> V_92 ;
struct V_75 * V_89 = V_73 -> V_89 ;
int V_278 ;
if ( ! V_73 -> V_103 -> V_113 )
return - V_271 ;
V_50 = F_82 ( V_281 ) ;
if ( ! V_50 )
return - V_146 ;
V_50 -> V_89 = V_75 ;
V_50 -> V_93 = V_75 -> V_240 ;
V_50 -> V_128 = F_77 ;
V_50 -> V_272 -> V_234 . V_274 = ( unsigned long ) V_50 ;
V_50 -> V_272 -> V_234 . V_286 = F_80 ;
V_50 -> V_272 -> V_234 . V_287 = V_288 + F_111 ( 110 ) ;
F_83 ( & V_50 -> V_272 -> V_234 ) ;
V_278 = F_110 ( V_73 , V_91 -> V_110 ,
V_50 , V_111 , V_67 ) ;
if ( V_278 ) {
F_78 ( & V_50 -> V_272 -> V_234 ) ;
F_27 ( V_89 , L_32 ,
V_278 ) ;
goto exit;
}
F_84 ( & V_50 -> V_272 -> V_273 ) ;
V_278 = V_291 ;
if ( ( V_50 -> V_166 & V_275 ) ) {
if ( ! ( V_50 -> V_166 & V_253 ) ) {
struct V_51 * V_52 = V_50 -> V_97 ;
if ( V_52 )
V_52 -> V_50 = NULL ;
F_27 ( V_89 , L_33 ) ;
}
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_292 ) {
V_278 = V_292 ;
goto exit;
}
if ( V_50 -> V_55 . V_57 == V_250 &&
V_50 -> V_55 . V_138 == V_293 ) {
V_278 = V_293 ;
goto exit;
}
exit:
F_95 ( V_89 , L_34
L_35 ,
F_36 ( V_75 -> V_142 ) ,
V_50 ,
V_50 -> V_55 . V_57 ,
V_50 -> V_55 . V_138 ) ;
F_86 ( V_50 ) ;
return V_278 ;
}
static void F_112 ( struct V_175 * V_176 )
{
F_66 ( V_176 ) ;
}
static void F_113 ( struct V_173 * V_174 )
{
V_174 -> V_179 = 0 ;
V_174 -> V_193 = 0 ;
V_174 -> V_76 = NULL ;
}
void F_114 ( struct V_73 * V_73 , int V_172 , int V_327 )
{
struct V_173 * V_174 = & V_73 -> V_174 [ V_172 ] ;
struct V_175 * V_176 = & V_174 -> V_176 ;
struct V_177 * V_178 = & V_73 -> V_180 ;
if ( V_327 ) {
F_48 ( V_73 , V_172 ) ;
F_66 ( V_176 ) ;
} else {
struct V_79 * V_76 = V_174 -> V_76 ;
V_178 -> V_181 ( V_176 , V_328 ) ;
F_115 ( V_176 ) ;
if ( V_76 ) {
if ( V_174 -> V_193 & V_194 ) {
int V_248 = V_76 -> V_144 ;
if ( ! V_73 -> V_103 -> V_329 ( V_73 ,
V_248 ) )
V_76 -> V_143 = 0 ;
} else if ( V_174 -> V_193 & V_203 )
V_76 -> V_143 = 0 ;
}
F_113 ( V_174 ) ;
}
}
void F_116 ( struct V_73 * V_73 , T_2 V_330 ,
T_2 V_331 )
{
struct V_177 * V_178 = & V_73 -> V_180 ;
int V_172 ;
for ( V_172 = 0 ; V_172 < V_73 -> V_236 ; V_172 ++ ) {
struct V_173 * V_174 = & V_73 -> V_174 [ V_172 ] ;
struct V_175 * V_176 = & V_174 -> V_176 ;
struct V_80 * V_81 = V_176 -> V_76 ;
struct V_74 * V_89 ;
if ( V_176 -> V_235 ) {
if ( V_331 & ( 1 << V_172 ) )
continue;
if ( V_330 & ( 1 << V_172 ) )
F_114 ( V_73 , V_172 , 0 ) ;
}
if ( ! V_81 )
continue;
V_89 = V_81 -> V_332 ;
if ( F_54 ( V_89 -> V_140 ) )
V_178 -> V_181 ( V_176 , V_333 ) ;
}
}
void F_117 ( struct V_73 * V_73 )
{
int V_88 , V_309 , V_334 = V_73 -> V_103 -> V_334 ;
for ( V_88 = 0 ; V_88 < V_73 -> V_211 ; V_88 ++ ) {
struct V_335 * V_336 = & V_73 -> V_336 [ V_88 ] ;
struct V_129 * V_130 = & V_73 -> V_130 [ V_88 ] ;
V_309 = sizeof( struct V_132 ) * V_337 ;
memset ( V_73 -> V_154 [ V_88 ] , 0 , V_309 ) ;
V_130 -> V_152 = 0 ;
V_309 = V_73 -> V_103 -> V_338 * V_337 ;
memset ( V_73 -> V_339 [ V_88 ] , 0 , V_309 ) ;
V_336 -> V_340 = 0 ;
}
V_309 = sizeof( struct V_341 ) * V_73 -> V_236 ;
memset ( V_73 -> V_342 , 0 , V_309 ) ;
V_309 = V_334 * sizeof( struct V_343 ) ;
memset ( V_73 -> V_344 , 0 , V_309 ) ;
V_309 = V_334 * sizeof( struct V_345 ) ;
memset ( V_73 -> V_346 , 0 , V_309 ) ;
V_309 = V_334 * sizeof( struct V_345 ) * 2 ;
memset ( V_73 -> V_347 , 0 , V_309 ) ;
}
int F_118 ( struct V_73 * V_73 , struct V_228 * V_229 )
{
struct V_75 * V_89 = V_73 -> V_89 ;
int V_88 , V_309 , V_334 = V_73 -> V_103 -> V_334 ;
F_119 ( & V_73 -> V_127 ) ;
for ( V_88 = 0 ; V_88 < V_73 -> V_236 ; V_88 ++ ) {
F_64 ( V_73 , V_88 ) ;
V_73 -> V_76 [ V_88 ] . V_143 = 0 ;
V_73 -> V_76 [ V_88 ] . V_144 = - 1 ;
}
for ( V_88 = 0 ; V_88 < V_207 ; V_88 ++ ) {
V_73 -> V_208 [ V_88 ] . V_140 = V_209 ;
V_73 -> V_208 [ V_88 ] . V_110 = V_88 ;
V_73 -> V_208 [ V_88 ] . V_212 = V_213 ;
}
for ( V_88 = 0 ; V_88 < V_73 -> V_211 ; V_88 ++ ) {
struct V_335 * V_336 = & V_73 -> V_336 [ V_88 ] ;
struct V_129 * V_130 = & V_73 -> V_130 [ V_88 ] ;
V_336 -> V_144 = V_88 ;
V_336 -> V_73 = V_73 ;
V_130 -> V_144 = V_88 ;
V_130 -> V_73 = V_73 ;
V_309 = sizeof( struct V_132 ) * V_337 ;
V_73 -> V_154 [ V_88 ] = F_120 ( V_89 , V_309 ,
& V_73 -> V_348 [ V_88 ] , V_281 ) ;
if ( ! V_73 -> V_154 [ V_88 ] )
goto V_149;
V_309 = V_73 -> V_103 -> V_338 * V_337 ;
V_73 -> V_339 [ V_88 ] = F_120 ( V_89 , V_309 ,
& V_73 -> V_349 [ V_88 ] , V_281 ) ;
if ( ! V_73 -> V_339 [ V_88 ] )
goto V_149;
}
V_309 = sizeof( struct V_350 ) ;
V_73 -> V_99 = F_121 ( L_36 , V_89 , V_309 , 16 , 0 ) ;
if ( ! V_73 -> V_99 )
goto V_149;
V_309 = V_351 * sizeof( struct V_352 ) ;
V_73 -> V_353 = F_120 ( V_89 , V_309 , & V_73 -> V_354 ,
V_281 ) ;
if ( ! V_73 -> V_353 )
goto V_149;
memset ( V_73 -> V_353 , 0 , V_309 ) ;
V_73 -> V_153 = F_122 ( V_89 , V_334 ,
sizeof( struct V_51 ) ,
V_281 ) ;
if ( ! V_73 -> V_153 )
goto V_149;
V_309 = V_334 * sizeof( struct V_343 ) ;
V_73 -> V_344 = F_120 ( V_89 , V_309 , & V_73 -> V_355 ,
V_281 ) ;
if ( ! V_73 -> V_344 )
goto V_149;
V_309 = V_334 * sizeof( struct V_345 ) ;
V_73 -> V_346 = F_120 ( V_89 , V_309 ,
& V_73 -> V_356 , V_281 ) ;
if ( ! V_73 -> V_346 )
goto V_149;
V_73 -> V_86 = V_334 ;
V_309 = V_73 -> V_86 / V_357 ;
V_73 -> V_84 = F_123 ( V_89 , V_309 , V_281 ) ;
if ( ! V_73 -> V_84 )
goto V_149;
V_309 = sizeof( struct V_341 ) * V_358 ;
V_73 -> V_342 = F_120 ( V_89 , V_309 ,
& V_73 -> V_359 , V_281 ) ;
if ( ! V_73 -> V_342 )
goto V_149;
V_309 = V_334 * sizeof( struct V_345 ) * 2 ;
V_73 -> V_347 = F_120 ( V_89 , V_309 ,
& V_73 -> V_360 , V_281 ) ;
if ( ! V_73 -> V_347 )
goto V_149;
F_117 ( V_73 ) ;
F_15 ( V_73 ) ;
V_73 -> V_361 = F_124 ( F_125 ( V_89 ) ) ;
if ( ! V_73 -> V_361 ) {
F_27 ( V_89 , L_37 ) ;
goto V_149;
}
return 0 ;
V_149:
return - V_146 ;
}
void F_126 ( struct V_73 * V_73 )
{
struct V_75 * V_89 = V_73 -> V_89 ;
int V_88 , V_309 , V_334 = V_73 -> V_103 -> V_334 ;
for ( V_88 = 0 ; V_88 < V_73 -> V_211 ; V_88 ++ ) {
V_309 = sizeof( struct V_132 ) * V_337 ;
if ( V_73 -> V_154 [ V_88 ] )
F_127 ( V_89 , V_309 ,
V_73 -> V_154 [ V_88 ] ,
V_73 -> V_348 [ V_88 ] ) ;
V_309 = V_73 -> V_103 -> V_338 * V_337 ;
if ( V_73 -> V_339 [ V_88 ] )
F_127 ( V_89 , V_309 ,
V_73 -> V_339 [ V_88 ] ,
V_73 -> V_349 [ V_88 ] ) ;
}
F_128 ( V_73 -> V_99 ) ;
V_309 = V_351 * sizeof( struct V_352 ) ;
if ( V_73 -> V_353 )
F_127 ( V_89 , V_309 ,
V_73 -> V_353 , V_73 -> V_354 ) ;
V_309 = V_334 * sizeof( struct V_343 ) ;
if ( V_73 -> V_344 )
F_127 ( V_89 , V_309 ,
V_73 -> V_344 , V_73 -> V_355 ) ;
V_309 = V_334 * sizeof( struct V_345 ) ;
if ( V_73 -> V_346 )
F_127 ( V_89 , V_309 ,
V_73 -> V_346 ,
V_73 -> V_356 ) ;
V_309 = sizeof( struct V_341 ) * V_358 ;
if ( V_73 -> V_342 )
F_127 ( V_89 , V_309 ,
V_73 -> V_342 ,
V_73 -> V_359 ) ;
V_309 = V_334 * sizeof( struct V_345 ) * 2 ;
if ( V_73 -> V_347 )
F_127 ( V_89 , V_309 ,
V_73 -> V_347 ,
V_73 -> V_360 ) ;
if ( V_73 -> V_361 )
F_129 ( V_73 -> V_361 ) ;
}
static void F_130 ( struct V_114 * V_115 )
{
struct V_73 * V_73 =
F_7 ( V_115 , struct V_73 , V_362 ) ;
F_93 ( V_73 ) ;
}
int F_131 ( struct V_73 * V_73 )
{
struct V_75 * V_89 = V_73 -> V_89 ;
struct V_363 * V_364 = V_73 -> V_365 ;
struct V_366 * V_367 = V_364 ? V_364 -> V_89 . V_368 : NULL ;
struct V_369 * V_370 ;
if ( F_132 ( V_89 , L_38 , V_73 -> V_142 ,
V_371 ) ) {
F_27 ( V_89 , L_39 ) ;
return - V_372 ;
}
if ( V_367 ) {
V_73 -> V_373 = F_133 ( V_367 ,
L_40 ) ;
if ( F_134 ( V_73 -> V_373 ) ) {
F_27 ( V_89 , L_41 ) ;
return - V_372 ;
}
if ( F_135 ( V_89 , L_42 ,
& V_73 -> V_374 ) ) {
F_27 ( V_89 ,
L_43 ) ;
return - V_372 ;
}
if ( F_135 ( V_89 , L_44 ,
& V_73 -> V_375 ) ) {
F_27 ( V_89 ,
L_45 ) ;
return - V_372 ;
}
if ( F_135 ( V_89 , L_46 ,
& V_73 -> V_376 ) ) {
F_27 ( V_89 ,
L_47 ) ;
return - V_372 ;
}
}
V_370 = F_136 ( V_89 , NULL ) ;
if ( F_134 ( V_370 ) )
F_95 ( V_89 , L_48 ) ;
else
V_73 -> V_377 = F_137 ( V_370 ) / 1000000 ;
if ( F_135 ( V_89 , L_49 , & V_73 -> V_236 ) ) {
F_27 ( V_89 , L_50 ) ;
return - V_372 ;
}
if ( F_135 ( V_89 , L_51 ,
& V_73 -> V_211 ) ) {
F_27 ( V_89 , L_52 ) ;
return - V_372 ;
}
return 0 ;
}
static struct V_228 * F_138 ( struct V_363 * V_364 ,
const struct V_378 * V_103 )
{
struct V_379 * V_278 ;
struct V_228 * V_229 ;
struct V_73 * V_73 ;
struct V_75 * V_89 = & V_364 -> V_89 ;
V_229 = F_139 ( V_380 , sizeof( * V_73 ) ) ;
if ( ! V_229 ) {
F_27 ( V_89 , L_53 ) ;
return NULL ;
}
V_73 = F_60 ( V_229 ) ;
F_39 ( & V_73 -> V_362 , F_130 ) ;
V_73 -> V_103 = V_103 ;
V_73 -> V_89 = V_89 ;
V_73 -> V_365 = V_364 ;
V_73 -> V_229 = V_229 ;
F_140 ( V_229 ) = & V_73 -> V_180 ;
F_65 ( & V_73 -> V_234 ) ;
if ( F_131 ( V_73 ) < 0 )
goto V_149;
if ( F_141 ( V_89 , F_142 ( 64 ) ) &&
F_141 ( V_89 , F_142 ( 32 ) ) ) {
F_27 ( V_89 , L_54 ) ;
goto V_149;
}
V_278 = F_143 ( V_364 , V_381 , 0 ) ;
V_73 -> V_382 = F_144 ( V_89 , V_278 ) ;
if ( F_134 ( V_73 -> V_382 ) )
goto V_149;
if ( F_118 ( V_73 , V_229 ) ) {
F_126 ( V_73 ) ;
goto V_149;
}
return V_229 ;
V_149:
F_145 ( V_229 ) ;
F_27 ( V_89 , L_55 ) ;
return NULL ;
}
void F_146 ( struct V_73 * V_73 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_73 -> V_236 ; V_88 ++ )
memcpy ( & V_73 -> V_174 [ V_88 ] . V_383 ,
V_73 -> V_142 ,
V_371 ) ;
}
int F_147 ( struct V_363 * V_364 ,
const struct V_378 * V_103 )
{
struct V_228 * V_229 ;
struct V_73 * V_73 ;
struct V_75 * V_89 = & V_364 -> V_89 ;
struct V_175 * * V_384 ;
struct V_80 * * V_385 ;
struct V_177 * V_180 ;
int V_136 , V_386 , V_387 , V_88 ;
V_229 = F_138 ( V_364 , V_103 ) ;
if ( ! V_229 )
return - V_146 ;
V_180 = F_140 ( V_229 ) ;
V_73 = F_60 ( V_229 ) ;
F_148 ( V_364 , V_180 ) ;
V_386 = V_387 = V_73 -> V_236 ;
V_384 = F_122 ( V_89 , V_386 , sizeof( void * ) , V_281 ) ;
V_385 = F_122 ( V_89 , V_387 , sizeof( void * ) , V_281 ) ;
if ( ! V_384 || ! V_385 ) {
V_136 = - V_146 ;
goto V_388;
}
V_180 -> V_176 = V_384 ;
V_180 -> V_81 = V_385 ;
V_180 -> V_78 = V_73 ;
V_229 -> V_389 = V_390 ;
V_229 -> V_391 = V_207 ;
V_229 -> V_392 = ~ 0 ;
V_229 -> V_393 = 1 ;
V_229 -> V_394 = 16 ;
V_229 -> V_395 = F_149 ( V_396 , V_397 , V_398 ) ;
V_229 -> V_399 = V_73 -> V_103 -> V_334 ;
V_229 -> V_400 = V_73 -> V_103 -> V_334 ;
V_180 -> V_401 = V_402 ;
V_180 -> V_89 = V_73 -> V_89 ;
V_180 -> V_403 = V_404 ;
V_180 -> V_142 = & V_73 -> V_142 [ 0 ] ;
V_180 -> V_221 = V_73 -> V_236 ;
V_180 -> V_405 . V_229 = V_73 -> V_229 ;
for ( V_88 = 0 ; V_88 < V_73 -> V_236 ; V_88 ++ ) {
V_180 -> V_176 [ V_88 ] = & V_73 -> V_174 [ V_88 ] . V_176 ;
V_180 -> V_81 [ V_88 ] = & V_73 -> V_76 [ V_88 ] . V_81 ;
}
F_146 ( V_73 ) ;
V_136 = F_150 ( V_229 , & V_364 -> V_89 ) ;
if ( V_136 )
goto V_388;
V_136 = F_151 ( V_180 ) ;
if ( V_136 )
goto V_406;
V_136 = V_73 -> V_103 -> V_407 ( V_73 ) ;
if ( V_136 )
goto V_406;
F_152 ( V_229 ) ;
return 0 ;
V_406:
F_153 ( V_229 ) ;
V_388:
F_126 ( V_73 ) ;
F_145 ( V_229 ) ;
return V_136 ;
}
int F_154 ( struct V_363 * V_364 )
{
struct V_177 * V_180 = F_155 ( V_364 ) ;
struct V_73 * V_73 = V_180 -> V_78 ;
struct V_228 * V_229 = V_180 -> V_405 . V_229 ;
F_156 ( V_180 ) ;
F_157 ( V_180 -> V_405 . V_229 ) ;
F_126 ( V_73 ) ;
F_145 ( V_229 ) ;
return 0 ;
}
static T_4 int F_158 ( void )
{
F_159 ( L_56 , V_408 ) ;
V_390 = F_160 ( & V_409 ) ;
if ( ! V_390 )
return - V_146 ;
return 0 ;
}
static T_5 void F_161 ( void )
{
F_162 ( V_390 ) ;
}
