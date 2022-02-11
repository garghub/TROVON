bool F_1 ( const char * V_1 , int line )
{
if ( V_2 >= V_3 . V_4 )
return false ;
if ( ++ V_2 == V_3 . V_4 ) {
F_2 ( L_1 ,
V_3 . V_4 , V_1 , line ) ;
return true ;
}
return false ;
}
void
F_3 ( struct V_5 * V_6 , const char * V_7 ,
const char * V_8 , ... )
{
static bool V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
bool V_14 = V_7 [ 1 ] <= V_15 [ 1 ] ;
bool V_16 = V_7 [ 1 ] == V_17 [ 1 ] ;
struct V_18 V_19 ;
T_1 args ;
if ( V_16 && ! ( V_20 & V_21 ) )
return;
va_start ( args , V_8 ) ;
V_19 . V_8 = V_8 ;
V_19 . V_22 = & args ;
F_4 ( V_7 , V_11 , L_2 V_23 L_3 ,
F_5 ( 0 ) , & V_19 ) ;
if ( V_14 && ! V_9 ) {
F_6 ( V_11 , L_4 , V_24 ) ;
V_9 = true ;
}
va_end ( args ) ;
}
static bool F_7 ( struct V_5 * V_6 )
{
return V_3 . V_4 &&
V_2 == V_3 . V_4 ;
}
static enum V_25 F_8 ( struct V_5 * V_6 )
{
enum V_25 V_26 = V_27 ;
if ( F_9 ( V_6 ) ) {
V_26 = V_28 ;
F_10 ( L_5 ) ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
V_26 = V_29 ;
F_10 ( L_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
V_26 = V_30 ;
F_10 ( L_7 ) ;
} else if ( F_15 ( V_6 ) || F_16 ( V_6 ) ) {
V_26 = V_31 ;
F_10 ( L_8 ) ;
} else if ( F_17 ( V_6 ) || F_18 ( V_6 ) ) {
V_26 = V_32 ;
F_10 ( L_9 ) ;
}
return V_26 ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_33 * V_34 = NULL ;
if ( F_20 ( V_6 ) -> V_35 == 0 ) {
V_6 -> V_36 = V_27 ;
return;
}
while ( ( V_34 = F_21 ( V_37 << 8 , V_34 ) ) ) {
if ( V_34 -> V_38 == V_39 ) {
unsigned short V_40 = V_34 -> V_10 & V_41 ;
unsigned short V_42 = V_34 -> V_10 &
V_43 ;
if ( V_40 == V_44 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_28 ;
F_10 ( L_10 ) ;
F_22 ( ! F_9 ( V_6 ) ) ;
} else if ( V_40 == V_46 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_29 ;
F_10 ( L_11 ) ;
F_22 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_40 == V_47 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_29 ;
F_10 ( L_12 ) ;
F_22 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_40 == V_48 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_30 ;
F_10 ( L_13 ) ;
F_22 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_22 ( F_23 ( V_6 ) ||
F_24 ( V_6 ) ) ;
} else if ( V_40 == V_49 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_30 ;
F_10 ( L_14 ) ;
F_22 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_22 ( ! F_23 ( V_6 ) &&
! F_24 ( V_6 ) ) ;
} else if ( V_40 == V_50 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_31 ;
F_10 ( L_15 ) ;
F_22 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_42 == V_51 ) {
V_6 -> V_45 = V_42 ;
V_6 -> V_36 = V_31 ;
F_10 ( L_16 ) ;
F_22 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_40 == V_52 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_53 ;
F_10 ( L_17 ) ;
F_22 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_40 == V_54 ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 = V_32 ;
F_10 ( L_18 ) ;
F_22 ( ! F_18 ( V_6 ) &&
! F_17 ( V_6 ) ) ;
} else if ( V_42 == V_55 ) {
V_6 -> V_45 = V_42 ;
V_6 -> V_36 = V_32 ;
F_10 ( L_19 ) ;
F_22 ( ! F_18 ( V_6 ) &&
! F_17 ( V_6 ) ) ;
} else if ( ( V_40 == V_56 ) ||
( V_40 == V_57 ) ||
( ( V_40 == V_58 ) &&
V_34 -> V_59 ==
V_60 &&
V_34 -> V_61 ==
V_62 ) ) {
V_6 -> V_45 = V_40 ;
V_6 -> V_36 =
F_8 ( V_6 ) ;
} else
continue;
break;
}
}
if ( ! V_34 )
F_10 ( L_20 ) ;
F_25 ( V_34 ) ;
}
static int F_26 ( struct V_63 * V_13 , void * V_64 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
T_2 * V_68 = V_64 ;
int V_69 ;
switch ( V_68 -> V_68 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
return - V_74 ;
case V_75 :
V_69 = V_67 -> V_10 ;
break;
case V_76 :
V_69 = V_67 -> V_77 ;
break;
case V_78 :
V_69 = V_6 -> V_79 ;
break;
case V_80 :
V_69 = V_6 -> V_81 ? 1 : 0 ;
break;
case V_82 :
V_69 = ! ! V_6 -> V_83 [ V_84 ] ;
break;
case V_85 :
V_69 = ! ! V_6 -> V_83 [ V_86 ] ;
break;
case V_87 :
V_69 = ! ! V_6 -> V_83 [ V_88 ] ;
break;
case V_89 :
V_69 = ! ! V_6 -> V_83 [ V_90 ] ;
break;
case V_91 :
V_69 = F_28 ( V_6 ) ;
break;
case V_92 :
V_69 = F_29 ( V_6 ) ;
break;
case V_93 :
V_69 = F_30 ( V_6 ) ;
break;
case V_94 :
V_69 = V_3 . V_95 ;
break;
case V_96 :
V_69 = F_31 ( V_97 ) ;
break;
case V_98 :
V_69 = F_32 ( V_6 ) ;
break;
case V_99 :
V_69 = F_33 ( & F_20 ( V_6 ) -> V_100 ) ;
if ( ! V_69 )
return - V_74 ;
break;
case V_101 :
V_69 = F_20 ( V_6 ) -> V_100 . V_102 ;
if ( ! V_69 )
return - V_74 ;
break;
case V_103 :
V_69 = V_3 . V_104 && F_34 ( V_6 ) ;
break;
case V_105 :
V_69 = F_35 ( V_6 ) ;
break;
case V_106 :
V_69 = F_36 ( V_6 ) ;
break;
case V_107 :
V_69 = F_20 ( V_6 ) -> V_100 . V_108 ;
break;
case V_109 :
F_37 ( V_6 ) ;
V_69 = F_38 ( V_110 ) & V_111 ;
F_39 ( V_6 ) ;
break;
case V_112 :
V_69 = F_40 () ;
break;
case V_113 :
V_69 = V_6 -> V_83 [ V_114 ] &&
V_6 -> V_83 [ V_114 ] -> V_115 ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_69 = 1 ;
break;
case V_135 :
V_69 = F_20 ( V_6 ) -> V_100 . V_136 ;
if ( ! V_69 )
return - V_74 ;
break;
case V_137 :
V_69 = F_20 ( V_6 ) -> V_100 . V_138 ;
if ( ! V_69 )
return - V_74 ;
break;
default:
F_41 ( L_21 , V_68 -> V_68 ) ;
return - V_139 ;
}
if ( F_42 ( V_69 , V_68 -> V_69 ) )
return - V_140 ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 )
{
V_6 -> V_141 = F_44 ( 0 , F_45 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_141 ) {
F_46 ( L_22 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_47 ( struct V_5 * V_6 )
{
int V_142 = F_48 ( V_6 ) >= 4 ? V_143 : V_144 ;
T_3 V_145 , V_146 = 0 ;
T_4 V_147 ;
int V_26 ;
if ( F_48 ( V_6 ) >= 4 )
F_49 ( V_6 -> V_141 , V_142 + 4 , & V_146 ) ;
F_49 ( V_6 -> V_141 , V_142 , & V_145 ) ;
V_147 = ( ( T_4 ) V_146 << 32 ) | V_145 ;
#ifdef F_50
if ( V_147 &&
F_51 ( V_147 , V_147 + V_148 ) )
return 0 ;
#endif
V_6 -> V_149 . V_150 = L_23 ;
V_6 -> V_149 . V_151 = V_152 ;
V_26 = F_52 ( V_6 -> V_141 -> V_153 ,
& V_6 -> V_149 ,
V_148 , V_148 ,
V_154 ,
0 , V_155 ,
V_6 -> V_141 ) ;
if ( V_26 ) {
F_53 ( L_24 , V_26 ) ;
V_6 -> V_149 . V_156 = 0 ;
return V_26 ;
}
if ( F_48 ( V_6 ) >= 4 )
F_54 ( V_6 -> V_141 , V_142 + 4 ,
F_55 ( V_6 -> V_149 . V_156 ) ) ;
F_54 ( V_6 -> V_141 , V_142 ,
F_56 ( V_6 -> V_149 . V_156 ) ) ;
return 0 ;
}
static void
F_57 ( struct V_5 * V_6 )
{
int V_157 = F_48 ( V_6 ) >= 4 ? V_143 : V_144 ;
T_3 V_158 ;
bool V_159 ;
if ( F_58 ( V_6 ) || F_59 ( V_6 ) )
return;
V_6 -> V_160 = false ;
if ( F_60 ( V_6 ) || F_61 ( V_6 ) ) {
F_49 ( V_6 -> V_141 , V_161 , & V_158 ) ;
V_159 = ! ! ( V_158 & V_162 ) ;
} else {
F_49 ( V_6 -> V_141 , V_157 , & V_158 ) ;
V_159 = V_158 & 1 ;
}
if ( V_159 )
return;
if ( F_47 ( V_6 ) )
return;
V_6 -> V_160 = true ;
if ( F_60 ( V_6 ) || F_61 ( V_6 ) ) {
F_54 ( V_6 -> V_141 , V_161 ,
V_158 | V_162 ) ;
} else {
F_49 ( V_6 -> V_141 , V_157 , & V_158 ) ;
F_54 ( V_6 -> V_141 , V_157 , V_158 | 1 ) ;
}
}
static void
F_62 ( struct V_5 * V_6 )
{
int V_157 = F_48 ( V_6 ) >= 4 ? V_143 : V_144 ;
if ( V_6 -> V_160 ) {
if ( F_60 ( V_6 ) || F_61 ( V_6 ) ) {
T_3 V_163 ;
F_49 ( V_6 -> V_141 , V_161 ,
& V_163 ) ;
V_163 &= ~ V_162 ;
F_54 ( V_6 -> V_141 , V_161 ,
V_163 ) ;
} else {
T_3 V_164 ;
F_49 ( V_6 -> V_141 , V_157 ,
& V_164 ) ;
V_164 &= ~ 1 ;
F_54 ( V_6 -> V_141 , V_157 ,
V_164 ) ;
}
}
if ( V_6 -> V_149 . V_156 )
F_63 ( & V_6 -> V_149 ) ;
}
static unsigned int F_64 ( void * V_165 , bool V_166 )
{
struct V_5 * V_6 = V_165 ;
F_65 ( V_6 , V_166 ) ;
if ( V_166 )
return V_167 | V_168 |
V_169 | V_170 ;
else
return V_169 | V_170 ;
}
static void F_66 ( struct V_33 * V_67 , enum V_171 V_166 )
{
struct V_63 * V_13 = F_67 ( V_67 ) ;
T_5 V_172 = { . V_173 = V_174 } ;
if ( V_166 == V_175 ) {
F_68 ( L_25 ) ;
V_13 -> V_176 = V_177 ;
F_69 ( V_67 , V_178 ) ;
F_70 ( V_13 ) ;
V_13 -> V_176 = V_179 ;
} else {
F_68 ( L_26 ) ;
V_13 -> V_176 = V_177 ;
F_71 ( V_13 , V_172 ) ;
V_13 -> V_176 = V_180 ;
}
}
static bool F_72 ( struct V_33 * V_67 )
{
struct V_63 * V_13 = F_67 ( V_67 ) ;
return V_13 -> V_181 == 0 ;
}
static void F_73 ( struct V_5 * V_6 )
{
F_74 ( & V_6 -> V_12 . V_182 ) ;
F_75 ( V_6 ) ;
F_76 ( V_6 ) ;
F_77 ( V_6 ) ;
F_78 ( V_6 ) ;
F_79 ( & V_6 -> V_12 . V_182 ) ;
F_80 ( V_6 ) ;
F_22 ( ! F_81 ( & V_6 -> V_183 ) ) ;
}
static int F_82 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
int V_26 ;
if ( F_83 () )
return - V_74 ;
F_84 ( V_6 ) ;
V_26 = F_85 ( V_67 , V_6 , NULL , F_64 ) ;
if ( V_26 && V_26 != - V_74 )
goto V_184;
F_86 () ;
V_26 = F_87 ( V_67 , & V_185 , false ) ;
if ( V_26 )
goto V_186;
F_88 ( V_6 ) ;
F_89 ( V_6 , false ) ;
F_90 ( V_6 ) ;
V_26 = F_91 ( V_6 ) ;
if ( V_26 )
goto V_187;
F_92 ( V_6 ) ;
V_26 = F_93 ( V_13 ) ;
if ( V_26 )
goto V_188;
F_94 ( V_6 ) ;
V_26 = F_95 ( V_6 ) ;
if ( V_26 )
goto V_189;
F_96 ( V_13 ) ;
if ( F_20 ( V_6 ) -> V_35 == 0 )
return 0 ;
V_26 = F_97 ( V_13 ) ;
if ( V_26 )
goto V_190;
F_98 ( V_6 ) ;
F_99 ( V_13 ) ;
return 0 ;
V_190:
if ( F_100 ( V_6 ) )
F_46 ( L_27 ) ;
F_73 ( V_6 ) ;
V_189:
F_101 ( V_6 ) ;
V_188:
F_102 ( V_13 ) ;
F_103 ( V_6 ) ;
V_187:
F_104 ( V_6 ) ;
F_105 ( V_6 ) ;
F_106 ( V_67 ) ;
V_186:
F_85 ( V_67 , NULL , NULL , NULL ) ;
V_184:
return V_26 ;
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_191 * V_192 ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
struct V_193 * V_194 = & V_6 -> V_194 ;
bool V_195 ;
int V_26 ;
V_192 = F_108 ( 1 ) ;
if ( ! V_192 )
return - V_196 ;
V_192 -> V_197 [ 0 ] . V_198 = V_194 -> V_199 ;
V_192 -> V_197 [ 0 ] . V_200 = V_194 -> V_201 ;
V_195 =
V_67 -> V_202 [ V_203 ] . V_151 & V_204 ;
V_26 = F_109 ( V_192 , L_28 , V_195 ) ;
F_110 ( V_192 ) ;
return V_26 ;
}
static int F_111 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_111 ( struct V_5 * V_6 )
{
return - V_74 ;
}
static int F_111 ( struct V_5 * V_6 )
{
int V_26 = 0 ;
F_2 ( L_29 ) ;
F_112 () ;
if ( F_113 ( & V_205 ) )
V_26 = F_114 ( & V_206 , 0 , V_207 - 1 , 1 ) ;
if ( V_26 == 0 ) {
V_26 = F_115 ( & V_205 ) ;
if ( V_26 == - V_74 )
V_26 = 0 ;
}
F_116 () ;
return V_26 ;
}
static void F_117 ( struct V_5 * V_6 )
{
if ( F_59 ( V_6 ) ) {
F_118 ( V_208 ) = V_209 ;
F_118 ( V_210 ) = V_211 ;
} else if ( F_58 ( V_6 ) ) {
F_118 ( V_208 ) = V_211 ;
}
}
static int F_119 ( struct V_5 * V_6 )
{
V_6 -> V_212 = F_120 ( L_30 , 0 ) ;
if ( V_6 -> V_212 == NULL )
goto V_213;
V_6 -> V_214 . V_215 = F_120 ( L_31 , 0 ) ;
if ( V_6 -> V_214 . V_215 == NULL )
goto V_216;
return 0 ;
V_216:
F_121 ( V_6 -> V_212 ) ;
V_213:
F_46 ( L_32 ) ;
return - V_196 ;
}
static void F_122 ( struct V_5 * V_3 )
{
struct V_217 * V_83 ;
enum V_218 V_40 ;
F_123 (engine, i915, id)
F_110 ( V_83 ) ;
}
static void F_124 ( struct V_5 * V_6 )
{
F_121 ( V_6 -> V_214 . V_215 ) ;
F_121 ( V_6 -> V_212 ) ;
}
static void F_125 ( struct V_5 * V_6 )
{
bool V_219 = false ;
V_219 |= F_126 ( V_6 ) ;
V_219 |= F_127 ( V_6 , 0 , V_220 ) ;
V_219 |= F_128 ( V_6 , 0 , V_221 ) ;
if ( V_219 ) {
F_46 ( L_33
L_34 ) ;
F_129 ( V_222 , V_223 ) ;
}
}
static int F_130 ( struct V_5 * V_6 ,
const struct V_224 * V_225 )
{
const struct V_226 * V_227 =
(struct V_226 * ) V_225 -> V_228 ;
struct V_226 * V_229 ;
int V_26 = 0 ;
if ( F_83 () )
return - V_74 ;
V_229 = F_131 ( V_6 ) ;
memcpy ( V_229 , V_227 , sizeof( * V_229 ) ) ;
V_229 -> V_230 = V_6 -> V_12 . V_67 -> V_10 ;
F_132 ( V_229 -> V_231 > sizeof( V_229 -> V_232 ) * V_233 ) ;
V_229 -> V_232 = F_133 ( V_229 -> V_231 - 1 ) ;
F_134 ( & V_6 -> V_234 ) ;
F_134 ( & V_6 -> V_235 . V_236 ) ;
F_135 ( & V_6 -> V_237 ) ;
F_134 ( & V_6 -> V_238 . V_236 ) ;
F_134 ( & V_6 -> V_239 . V_240 ) ;
F_134 ( & V_6 -> V_241 ) ;
F_135 ( & V_6 -> V_242 ) ;
F_135 ( & V_6 -> V_243 ) ;
F_135 ( & V_6 -> V_244 ) ;
F_135 ( & V_6 -> V_245 . V_246 ) ;
F_135 ( & V_6 -> V_247 ) ;
F_136 ( V_6 ) ;
F_137 ( V_6 ) ;
V_26 = F_119 ( V_6 ) ;
if ( V_26 < 0 )
goto V_248;
F_19 ( V_6 ) ;
F_138 ( V_6 ) ;
F_117 ( V_6 ) ;
F_139 ( V_6 ) ;
F_140 ( V_6 ) ;
F_141 ( V_6 ) ;
F_142 ( V_6 ) ;
F_143 ( V_6 ) ;
F_144 ( V_6 ) ;
V_26 = F_145 ( V_6 ) ;
if ( V_26 < 0 )
goto V_249;
F_146 ( V_6 ) ;
F_147 ( V_6 ) ;
F_125 ( V_6 ) ;
F_148 ( V_6 ) ;
return 0 ;
V_249:
F_149 ( V_6 ) ;
F_124 ( V_6 ) ;
V_248:
F_122 ( V_6 ) ;
return V_26 ;
}
static void F_150 ( struct V_5 * V_6 )
{
F_151 ( V_6 ) ;
F_152 ( V_6 ) ;
F_149 ( V_6 ) ;
F_124 ( V_6 ) ;
F_122 ( V_6 ) ;
}
static int F_153 ( struct V_5 * V_6 )
{
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
int V_250 ;
int V_251 ;
V_250 = F_154 ( V_6 ) ? 1 : 0 ;
if ( F_48 ( V_6 ) < 5 )
V_251 = 512 * 1024 ;
else
V_251 = 2 * 1024 * 1024 ;
V_6 -> V_252 = F_155 ( V_67 , V_250 , V_251 ) ;
if ( V_6 -> V_252 == NULL ) {
F_46 ( L_35 ) ;
return - V_253 ;
}
F_57 ( V_6 ) ;
return 0 ;
}
static void F_156 ( struct V_5 * V_6 )
{
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
F_62 ( V_6 ) ;
F_157 ( V_67 , V_6 -> V_252 ) ;
}
static int F_158 ( struct V_5 * V_6 )
{
int V_26 ;
if ( F_83 () )
return - V_74 ;
if ( F_43 ( V_6 ) )
return - V_253 ;
V_26 = F_153 ( V_6 ) ;
if ( V_26 < 0 )
goto V_254;
F_159 ( V_6 ) ;
V_26 = F_160 ( V_6 ) ;
if ( V_26 )
goto V_255;
F_161 ( V_6 ) ;
return 0 ;
V_255:
F_162 ( V_6 ) ;
V_254:
F_25 ( V_6 -> V_141 ) ;
return V_26 ;
}
static void F_163 ( struct V_5 * V_6 )
{
F_162 ( V_6 ) ;
F_156 ( V_6 ) ;
F_25 ( V_6 -> V_141 ) ;
}
static void F_164 ( struct V_5 * V_6 )
{
V_3 . V_256 =
F_165 ( V_6 ,
V_3 . V_256 ) ;
V_3 . V_257 =
F_166 ( V_6 , V_3 . V_257 ) ;
F_53 ( L_36 , V_3 . V_257 ) ;
V_3 . V_95 = F_167 ( V_6 , V_3 . V_95 ) ;
F_53 ( L_37 , F_168 ( V_3 . V_95 ) ) ;
F_169 ( V_6 ) ;
F_170 ( V_6 ) ;
}
static int F_171 ( struct V_5 * V_6 )
{
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
int V_26 ;
if ( F_83 () )
return - V_74 ;
F_172 ( V_6 ) ;
F_164 ( V_6 ) ;
V_26 = F_173 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_107 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_38 ) ;
goto V_258;
}
V_26 = F_111 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_39 ) ;
goto V_258;
}
V_26 = F_174 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_175 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_40 ) ;
goto V_258;
}
F_176 ( V_67 ) ;
if ( F_154 ( V_6 ) ) {
V_26 = F_177 ( & V_67 -> V_13 , F_178 ( 30 ) ) ;
if ( V_26 ) {
F_46 ( L_41 ) ;
goto V_258;
}
}
if ( F_179 ( V_6 ) || F_180 ( V_6 ) ) {
V_26 = F_177 ( & V_67 -> V_13 , F_178 ( 32 ) ) ;
if ( V_26 ) {
F_46 ( L_41 ) ;
goto V_258;
}
}
F_181 ( & V_6 -> V_259 , V_260 ,
V_261 ) ;
F_182 ( V_6 ) ;
F_183 ( V_6 ) ;
F_184 ( V_6 ) ;
if ( F_48 ( V_6 ) >= 5 ) {
if ( F_185 ( V_67 ) < 0 )
F_53 ( L_42 ) ;
}
V_26 = F_186 ( V_6 ) ;
if ( V_26 )
goto V_258;
return 0 ;
V_258:
F_187 ( V_6 ) ;
return V_26 ;
}
static void F_188 ( struct V_5 * V_6 )
{
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
if ( V_67 -> V_262 )
F_189 ( V_67 ) ;
F_190 ( & V_6 -> V_259 ) ;
F_187 ( V_6 ) ;
}
static void F_191 ( struct V_5 * V_6 )
{
struct V_63 * V_13 = & V_6 -> V_12 ;
F_192 ( V_6 ) ;
if ( F_193 ( V_6 ) )
F_194 ( F_195 ( V_263 ) , V_264 ) ;
if ( F_196 ( V_13 , 0 ) == 0 ) {
F_197 ( V_6 ) ;
F_198 ( V_6 ) ;
F_199 ( V_6 ) ;
F_200 ( V_6 ) ;
} else
F_46 ( L_43 ) ;
if ( F_20 ( V_6 ) -> V_35 ) {
F_201 ( V_6 ) ;
F_202 () ;
}
if ( F_9 ( V_6 ) )
F_203 ( V_6 ) ;
F_204 ( V_6 ) ;
F_205 ( V_13 ) ;
}
static void F_206 ( struct V_5 * V_6 )
{
F_207 ( V_6 ) ;
F_208 () ;
F_209 () ;
F_210 ( V_6 ) ;
F_211 ( V_6 ) ;
F_212 ( V_6 ) ;
F_213 ( V_6 ) ;
F_214 ( & V_6 -> V_12 ) ;
F_215 ( V_6 ) ;
}
int F_216 ( struct V_33 * V_67 , const struct V_224 * V_225 )
{
const struct V_226 * V_227 =
(struct V_226 * ) V_225 -> V_228 ;
struct V_5 * V_6 ;
int V_26 ;
if ( ! V_3 . V_265 && V_227 -> V_231 < 5 )
V_266 . V_267 &= ~ V_268 ;
V_26 = - V_196 ;
V_6 = F_217 ( sizeof( * V_6 ) , V_269 ) ;
if ( V_6 )
V_26 = F_218 ( & V_6 -> V_12 , & V_266 , & V_67 -> V_13 ) ;
if ( V_26 ) {
F_219 ( & V_67 -> V_13 , L_44 ) ;
goto V_270;
}
V_6 -> V_12 . V_67 = V_67 ;
V_6 -> V_12 . V_271 = V_6 ;
V_26 = F_220 ( V_67 ) ;
if ( V_26 )
goto V_272;
F_221 ( V_67 , & V_6 -> V_12 ) ;
V_67 -> V_273 |= V_274 ;
V_26 = F_130 ( V_6 , V_225 ) ;
if ( V_26 < 0 )
goto V_275;
F_37 ( V_6 ) ;
V_26 = F_158 ( V_6 ) ;
if ( V_26 < 0 )
goto V_276;
V_26 = F_171 ( V_6 ) ;
if ( V_26 < 0 )
goto V_277;
if ( F_20 ( V_6 ) -> V_35 ) {
V_26 = F_222 ( & V_6 -> V_12 ,
F_20 ( V_6 ) -> V_35 ) ;
if ( V_26 )
goto V_278;
}
V_26 = F_82 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_279;
F_191 ( V_6 ) ;
F_223 ( V_6 ) ;
V_6 -> V_280 = false ;
if ( F_224 ( V_281 ) )
F_2 ( L_45 ) ;
if ( F_224 ( V_282 ) )
F_2 ( L_46 ) ;
F_39 ( V_6 ) ;
return 0 ;
V_279:
F_225 ( & V_6 -> V_12 ) ;
V_278:
F_188 ( V_6 ) ;
V_277:
F_163 ( V_6 ) ;
V_276:
F_39 ( V_6 ) ;
F_150 ( V_6 ) ;
V_275:
F_226 ( V_67 ) ;
V_272:
F_227 ( V_6 , L_47 , V_26 ) ;
F_228 ( & V_6 -> V_12 ) ;
V_270:
F_110 ( V_6 ) ;
return V_26 ;
}
void F_229 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
F_230 ( V_13 ) ;
if ( F_100 ( V_6 ) )
F_46 ( L_27 ) ;
F_231 ( V_6 , V_283 ) ;
F_232 ( V_13 ) ;
F_233 ( V_6 ) ;
F_206 ( V_6 ) ;
F_225 ( V_13 ) ;
F_234 ( V_13 ) ;
if ( V_6 -> V_284 . V_285 && V_6 -> V_284 . V_286 ) {
F_110 ( V_6 -> V_284 . V_285 ) ;
V_6 -> V_284 . V_285 = NULL ;
V_6 -> V_284 . V_286 = 0 ;
}
F_110 ( V_6 -> V_284 . V_287 ) ;
V_6 -> V_284 . V_287 = NULL ;
F_110 ( V_6 -> V_284 . V_288 ) ;
V_6 -> V_284 . V_288 = NULL ;
F_106 ( V_67 ) ;
F_85 ( V_67 , NULL , NULL , NULL ) ;
F_104 ( V_6 ) ;
F_235 ( & V_6 -> V_235 . V_289 ) ;
F_236 ( V_6 ) ;
F_237 ( V_6 -> V_212 ) ;
F_73 ( V_6 ) ;
F_101 ( V_6 ) ;
F_238 ( V_6 ) ;
F_105 ( V_6 ) ;
F_188 ( V_6 ) ;
F_163 ( V_6 ) ;
F_239 ( V_6 , V_283 ) ;
}
static void F_240 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
F_150 ( V_6 ) ;
F_228 ( & V_6 -> V_12 ) ;
F_110 ( V_6 ) ;
}
static int F_241 ( struct V_63 * V_13 , struct V_65 * V_290 )
{
int V_26 ;
V_26 = F_242 ( V_13 , V_290 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_243 ( struct V_63 * V_13 )
{
F_244 ( V_13 ) ;
F_245 () ;
}
static void F_246 ( struct V_63 * V_13 , struct V_65 * V_290 )
{
struct V_291 * V_66 = V_290 -> V_292 ;
F_74 ( & V_13 -> V_182 ) ;
F_247 ( V_13 , V_290 ) ;
F_248 ( V_13 , V_290 ) ;
F_79 ( & V_13 -> V_182 ) ;
F_110 ( V_66 ) ;
}
static void F_249 ( struct V_5 * V_6 )
{
struct V_63 * V_13 = & V_6 -> V_12 ;
struct V_293 * V_294 ;
F_250 ( V_13 ) ;
F_251 (dev, encoder)
if ( V_294 -> V_295 )
V_294 -> V_295 ( V_294 ) ;
F_252 ( V_13 ) ;
}
static bool F_253 ( struct V_5 * V_6 )
{
#if F_224 ( V_296 )
if ( F_254 () < V_297 )
return true ;
#endif
return false ;
}
static int F_255 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
T_6 V_298 ;
int error ;
F_74 ( & V_6 -> V_243 ) ;
V_6 -> V_299 = V_300 ;
F_79 ( & V_6 -> V_243 ) ;
F_256 ( V_6 ) ;
F_257 ( V_6 , true ) ;
F_258 ( V_13 ) ;
F_259 ( V_67 ) ;
error = F_100 ( V_6 ) ;
if ( error ) {
F_260 ( & V_67 -> V_13 ,
L_48 ) ;
goto V_184;
}
F_261 ( V_13 ) ;
F_262 ( V_13 ) ;
F_263 ( V_6 ) ;
F_264 ( V_6 ) ;
F_249 ( V_6 ) ;
F_265 ( V_6 ) ;
F_266 ( V_6 ) ;
F_267 ( V_6 ) ;
V_298 = F_253 ( V_6 ) ? V_301 : V_302 ;
F_268 ( V_6 , V_298 ) ;
F_269 ( V_6 ) ;
F_210 ( V_6 ) ;
F_270 ( V_13 , V_303 , true ) ;
V_6 -> V_304 ++ ;
F_271 ( V_6 ) ;
V_184:
F_272 ( V_6 ) ;
return error ;
}
static int F_273 ( struct V_63 * V_13 , bool V_305 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
bool V_306 ;
int V_26 ;
F_256 ( V_6 ) ;
F_257 ( V_6 , false ) ;
V_306 = ! F_274 ( V_6 ) &&
F_253 ( V_6 ) && V_6 -> V_307 . V_308 ;
if ( ! V_306 )
F_275 ( V_6 ) ;
V_26 = 0 ;
if ( F_274 ( V_6 ) )
F_276 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_277 ( V_6 ) ;
else if ( F_58 ( V_6 ) || F_59 ( V_6 ) )
V_26 = F_278 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_49 , V_26 ) ;
if ( ! V_306 )
F_89 ( V_6 , true ) ;
goto V_184;
}
F_226 ( V_67 ) ;
if ( ! ( V_305 && F_48 ( V_6 ) < 6 ) )
F_69 ( V_67 , V_309 ) ;
V_6 -> V_310 = F_253 ( V_6 ) ;
V_184:
F_272 ( V_6 ) ;
return V_26 ;
}
static int F_71 ( struct V_63 * V_13 , T_5 V_166 )
{
int error ;
if ( ! V_13 ) {
F_46 ( L_50 , V_13 ) ;
F_46 ( L_51 ) ;
return - V_74 ;
}
if ( F_279 ( V_166 . V_173 != V_174 &&
V_166 . V_173 != V_311 ) )
return - V_139 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
error = F_255 ( V_13 ) ;
if ( error )
return error ;
return F_273 ( V_13 , false ) ;
}
static int F_280 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
int V_26 ;
F_256 ( V_6 ) ;
F_281 ( V_6 ) ;
V_26 = F_175 ( V_6 ) ;
if ( V_26 )
F_46 ( L_52 ) ;
F_282 ( V_6 ) ;
F_283 ( V_6 ) ;
F_284 ( V_6 ) ;
F_285 ( V_6 ) ;
F_183 ( V_6 ) ;
F_286 ( V_6 ) ;
F_287 ( V_6 ) ;
F_288 ( V_13 ) ;
F_74 ( & V_13 -> V_182 ) ;
if ( F_289 ( V_6 ) ) {
F_46 ( L_53 ) ;
F_290 ( V_6 ) ;
}
F_79 ( & V_13 -> V_182 ) ;
F_291 ( V_6 ) ;
F_292 ( V_13 ) ;
F_293 ( & V_6 -> V_234 ) ;
if ( V_6 -> V_312 . V_313 )
V_6 -> V_312 . V_313 ( V_6 ) ;
F_294 ( & V_6 -> V_234 ) ;
F_295 ( V_13 ) ;
F_296 ( V_13 ) ;
F_297 ( V_13 ) ;
F_98 ( V_6 ) ;
F_201 ( V_6 ) ;
F_270 ( V_13 , V_314 , false ) ;
F_74 ( & V_6 -> V_243 ) ;
V_6 -> V_299 = V_315 ;
F_79 ( & V_6 -> V_243 ) ;
F_268 ( V_6 , V_178 ) ;
F_298 ( V_6 ) ;
F_272 ( V_6 ) ;
return 0 ;
}
static int F_299 ( struct V_63 * V_13 )
{
struct V_5 * V_6 = F_27 ( V_13 ) ;
struct V_33 * V_67 = V_6 -> V_12 . V_67 ;
int V_26 ;
V_26 = F_69 ( V_67 , V_178 ) ;
if ( V_26 ) {
F_46 ( L_54 , V_26 ) ;
goto V_184;
}
if ( F_220 ( V_67 ) ) {
V_26 = - V_253 ;
goto V_184;
}
F_176 ( V_67 ) ;
F_256 ( V_6 ) ;
if ( F_58 ( V_6 ) || F_59 ( V_6 ) )
V_26 = F_300 ( V_6 , false ) ;
if ( V_26 )
F_46 ( L_55 ,
V_26 ) ;
F_301 ( V_6 ) ;
if ( F_274 ( V_6 ) ) {
if ( ! V_6 -> V_310 )
F_302 ( V_6 ) ;
F_303 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_304 ( V_6 ) ;
}
F_182 ( V_6 ) ;
if ( F_274 ( V_6 ) ||
! ( V_6 -> V_310 && V_6 -> V_307 . V_308 ) )
F_89 ( V_6 , true ) ;
F_305 ( V_6 ) ;
F_272 ( V_6 ) ;
V_184:
V_6 -> V_310 = false ;
return V_26 ;
}
static int F_70 ( struct V_63 * V_13 )
{
int V_26 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
V_26 = F_299 ( V_13 ) ;
if ( V_26 )
return V_26 ;
return F_280 ( V_13 ) ;
}
void F_306 ( struct V_5 * V_6 )
{
struct V_316 * error = & V_6 -> V_235 ;
int V_26 ;
F_307 ( & V_6 -> V_12 . V_182 ) ;
F_308 ( ! F_309 ( V_317 , & error -> V_151 ) ) ;
if ( ! F_309 ( V_318 , & error -> V_151 ) )
return;
if ( ! F_310 ( V_6 ) )
goto V_319;
error -> V_320 ++ ;
F_311 ( L_56 ) ;
F_312 ( V_6 -> V_12 . V_321 ) ;
V_26 = F_313 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_57 ) ;
F_314 ( V_6 , V_322 ) ;
goto error;
}
V_26 = F_314 ( V_6 , V_322 ) ;
if ( V_26 ) {
if ( V_26 != - V_74 )
F_46 ( L_58 , V_26 ) ;
else
F_53 ( L_59 ) ;
goto error;
}
F_315 ( V_6 ) ;
F_316 ( V_6 ) ;
V_26 = F_289 ( V_6 ) ;
if ( V_26 ) {
F_46 ( L_60 , V_26 ) ;
goto error;
}
F_317 ( V_6 ) ;
V_323:
F_318 ( V_6 ) ;
F_319 ( V_6 -> V_12 . V_321 ) ;
V_319:
F_320 ( V_318 , & error -> V_151 ) ;
F_321 ( & error -> V_151 , V_318 ) ;
return;
error:
F_290 ( V_6 ) ;
goto V_323;
}
static int F_322 ( struct V_10 * V_11 )
{
struct V_33 * V_67 = F_323 ( V_11 ) ;
struct V_63 * V_13 = F_67 ( V_67 ) ;
if ( ! V_13 ) {
F_260 ( V_11 , L_51 ) ;
return - V_74 ;
}
if ( V_13 -> V_176 == V_180 )
return 0 ;
return F_255 ( V_13 ) ;
}
static int F_324 ( struct V_10 * V_11 )
{
struct V_63 * V_13 = & F_325 ( V_11 ) -> V_12 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
return F_273 ( V_13 , false ) ;
}
static int F_326 ( struct V_10 * V_11 )
{
struct V_63 * V_13 = & F_325 ( V_11 ) -> V_12 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
return F_273 ( V_13 , true ) ;
}
static int F_327 ( struct V_10 * V_11 )
{
struct V_63 * V_13 = & F_325 ( V_11 ) -> V_12 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
return F_299 ( V_13 ) ;
}
static int F_328 ( struct V_10 * V_11 )
{
struct V_63 * V_13 = & F_325 ( V_11 ) -> V_12 ;
if ( V_13 -> V_176 == V_180 )
return 0 ;
return F_280 ( V_13 ) ;
}
static int F_329 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_322 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_330 ( F_325 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_331 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_324 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_332 ( F_325 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_333 ( struct V_10 * V_11 )
{
return F_327 ( V_11 ) ;
}
static int F_334 ( struct V_10 * V_11 )
{
return F_328 ( V_11 ) ;
}
static int F_335 ( struct V_10 * V_11 )
{
return F_327 ( V_11 ) ;
}
static int F_336 ( struct V_10 * V_11 )
{
return F_328 ( V_11 ) ;
}
static void F_337 ( struct V_5 * V_6 )
{
struct V_324 * V_325 = & V_6 -> V_324 ;
int V_326 ;
V_325 -> V_327 = F_38 ( V_328 ) ;
V_325 -> V_329 = F_38 ( V_330 ) ;
V_325 -> V_331 = F_38 ( V_332 ) ;
V_325 -> V_333 = F_38 ( V_334 ) ;
V_325 -> V_335 = F_38 ( V_336 ) ;
for ( V_326 = 0 ; V_326 < F_338 ( V_325 -> V_337 ) ; V_326 ++ )
V_325 -> V_337 [ V_326 ] = F_38 ( F_339 ( V_326 ) ) ;
V_325 -> V_338 = F_38 ( V_339 ) ;
V_325 -> V_340 = F_38 ( V_341 ) ;
V_325 -> V_342 = F_38 ( V_343 ) ;
V_325 -> V_344 = F_38 ( V_345 ) ;
V_325 -> V_346 = F_38 ( V_347 ) ;
V_325 -> V_348 = F_38 ( V_349 ) ;
V_325 -> V_350 = F_38 ( V_351 ) ;
V_325 -> V_352 = F_38 ( V_353 ) ;
V_325 -> V_354 = F_38 ( V_355 ) ;
V_325 -> V_356 = F_38 ( V_357 ) ;
V_325 -> V_358 = F_38 ( V_359 ) ;
V_325 -> V_360 = F_38 ( V_361 ) ;
V_325 -> V_362 = F_38 ( V_363 ) ;
V_325 -> V_364 = F_38 ( V_365 ) ;
V_325 -> V_366 = F_38 ( V_367 ) ;
V_325 -> V_368 = F_38 ( V_369 ) ;
V_325 -> V_370 = F_38 ( V_371 ) ;
V_325 -> V_372 = F_38 ( V_373 ) ;
V_325 -> V_374 = F_38 ( V_375 ) ;
V_325 -> V_376 = F_38 ( V_377 ) ;
V_325 -> V_378 = F_38 ( V_379 ) ;
V_325 -> V_380 = F_38 ( V_381 ) ;
V_325 -> V_382 = F_38 ( V_383 ) ;
V_325 -> V_384 = F_38 ( V_385 ) ;
V_325 -> V_386 = F_38 ( V_387 ) ;
V_325 -> V_388 = F_38 ( V_389 ) ;
V_325 -> V_390 = F_38 ( V_391 ) ;
V_325 -> V_392 = F_38 ( V_393 ) ;
V_325 -> V_394 = F_38 ( V_395 ) ;
V_325 -> V_396 = F_38 ( V_397 ) ;
for ( V_326 = 0 ; V_326 < F_338 ( V_325 -> V_398 ) ; V_326 ++ )
V_325 -> V_398 [ V_326 ] = F_38 ( F_340 ( V_326 ) ) ;
V_325 -> V_399 = F_38 ( V_400 ) ;
V_325 -> V_401 = F_38 ( V_402 ) ;
V_325 -> V_403 = F_38 ( V_404 ) ;
V_325 -> V_405 = F_38 ( V_406 ) ;
V_325 -> V_407 = F_38 ( V_408 ) ;
V_325 -> V_409 = F_38 ( V_410 ) ;
V_325 -> V_411 = F_38 ( V_412 ) ;
V_325 -> V_413 = F_38 ( V_414 ) ;
V_325 -> V_415 = F_38 ( V_416 ) ;
}
static void F_341 ( struct V_5 * V_6 )
{
struct V_324 * V_325 = & V_6 -> V_324 ;
T_3 V_417 ;
int V_326 ;
F_194 ( V_328 , V_325 -> V_327 ) ;
F_194 ( V_330 , V_325 -> V_329 ) ;
F_194 ( V_332 , V_325 -> V_331 | ( 0xffff << 16 ) ) ;
F_194 ( V_334 , V_325 -> V_333 ) ;
F_194 ( V_336 , V_325 -> V_335 ) ;
for ( V_326 = 0 ; V_326 < F_338 ( V_325 -> V_337 ) ; V_326 ++ )
F_194 ( F_339 ( V_326 ) , V_325 -> V_337 [ V_326 ] ) ;
F_194 ( V_339 , V_325 -> V_338 ) ;
F_194 ( V_341 , V_325 -> V_340 ) ;
F_194 ( V_343 , V_325 -> V_342 ) ;
F_194 ( V_345 , V_325 -> V_344 ) ;
F_194 ( V_347 , V_325 -> V_346 ) ;
F_194 ( V_349 , V_325 -> V_348 ) ;
F_194 ( V_351 , V_325 -> V_350 ) ;
F_194 ( V_353 , V_325 -> V_352 ) ;
F_194 ( V_355 , V_325 -> V_354 ) ;
F_194 ( V_357 , V_325 -> V_356 ) ;
F_194 ( V_359 , V_325 -> V_358 ) ;
F_194 ( V_361 , V_325 -> V_360 ) ;
F_194 ( V_363 , V_325 -> V_362 ) ;
F_194 ( V_365 , V_325 -> V_364 ) ;
F_194 ( V_367 , V_325 -> V_366 ) ;
F_194 ( V_369 , V_325 -> V_368 ) ;
F_194 ( V_371 , V_325 -> V_370 ) ;
F_194 ( V_373 , V_325 -> V_372 ) ;
F_194 ( V_375 , V_325 -> V_374 ) ;
F_194 ( V_377 , V_325 -> V_376 ) ;
F_194 ( V_379 , V_325 -> V_378 ) ;
F_194 ( V_381 , V_325 -> V_380 ) ;
F_194 ( V_383 , V_325 -> V_382 ) ;
F_194 ( V_385 , V_325 -> V_384 ) ;
F_194 ( V_387 , V_325 -> V_386 ) ;
F_194 ( V_389 , V_325 -> V_388 ) ;
F_194 ( V_391 , V_325 -> V_390 ) ;
F_194 ( V_393 , V_325 -> V_392 ) ;
F_194 ( V_395 , V_325 -> V_394 ) ;
F_194 ( V_397 , V_325 -> V_396 ) ;
for ( V_326 = 0 ; V_326 < F_338 ( V_325 -> V_398 ) ; V_326 ++ )
F_194 ( F_340 ( V_326 ) , V_325 -> V_398 [ V_326 ] ) ;
F_194 ( V_400 , V_325 -> V_399 ) ;
F_194 ( V_402 , V_325 -> V_401 ) ;
V_417 = F_38 ( V_404 ) ;
V_417 &= V_418 ;
V_417 |= V_325 -> V_403 & ~ V_418 ;
F_194 ( V_404 , V_417 ) ;
V_417 = F_38 ( V_406 ) ;
V_417 &= V_419 ;
V_417 |= V_325 -> V_405 & ~ V_419 ;
F_194 ( V_406 , V_417 ) ;
F_194 ( V_408 , V_325 -> V_407 ) ;
F_194 ( V_410 , V_325 -> V_409 ) ;
F_194 ( V_412 , V_325 -> V_411 ) ;
F_194 ( V_414 , V_325 -> V_413 ) ;
F_194 ( V_416 , V_325 -> V_415 ) ;
}
static int F_342 ( struct V_5 * V_6 ,
T_3 V_420 , T_3 V_417 )
{
return F_343 ( ( F_344 ( V_421 ) & V_420 ) == V_417 ,
3 ) ;
}
int F_345 ( struct V_5 * V_6 , bool V_422 )
{
T_3 V_417 ;
int V_423 ;
V_417 = F_38 ( V_406 ) ;
V_417 &= ~ V_419 ;
if ( V_422 )
V_417 |= V_419 ;
F_194 ( V_406 , V_417 ) ;
if ( ! V_422 )
return 0 ;
V_423 = F_346 ( V_6 ,
V_406 ,
V_424 ,
V_424 ,
20 ) ;
if ( V_423 )
F_46 ( L_61 ,
F_38 ( V_406 ) ) ;
return V_423 ;
}
static int F_347 ( struct V_5 * V_6 , bool V_425 )
{
T_3 V_420 ;
T_3 V_417 ;
int V_423 ;
V_417 = F_38 ( V_404 ) ;
V_417 &= ~ V_418 ;
if ( V_425 )
V_417 |= V_418 ;
F_194 ( V_404 , V_417 ) ;
F_348 ( V_404 ) ;
V_420 = V_426 ;
V_417 = V_425 ? V_420 : 0 ;
V_423 = F_342 ( V_6 , V_420 , V_417 ) ;
if ( V_423 )
F_46 ( L_62 ) ;
return V_423 ;
}
static void F_349 ( struct V_5 * V_6 ,
bool V_427 )
{
T_3 V_420 ;
T_3 V_417 ;
V_420 = V_428 | V_429 ;
V_417 = V_427 ? V_420 : 0 ;
if ( F_342 ( V_6 , V_420 , V_417 ) )
F_46 ( L_63 ,
F_350 ( V_427 ) ) ;
}
static void F_351 ( struct V_5 * V_6 )
{
if ( ! ( F_38 ( V_421 ) & V_430 ) )
return;
F_53 ( L_64 ) ;
F_194 ( V_421 , V_430 ) ;
}
static int F_278 ( struct V_5 * V_6 )
{
T_3 V_420 ;
int V_423 ;
F_349 ( V_6 , false ) ;
V_420 = V_431 | V_432 ;
F_22 ( ( F_38 ( V_404 ) & V_420 ) != V_420 ) ;
F_351 ( V_6 ) ;
V_423 = F_345 ( V_6 , true ) ;
if ( V_423 )
goto V_433;
V_423 = F_347 ( V_6 , false ) ;
if ( V_423 )
goto V_434;
if ( ! F_59 ( V_6 ) )
F_337 ( V_6 ) ;
V_423 = F_345 ( V_6 , false ) ;
if ( V_423 )
goto V_434;
return 0 ;
V_434:
F_347 ( V_6 , true ) ;
V_433:
F_345 ( V_6 , false ) ;
return V_423 ;
}
static int F_300 ( struct V_5 * V_6 ,
bool V_435 )
{
int V_423 ;
int V_26 ;
V_26 = F_345 ( V_6 , true ) ;
if ( ! F_59 ( V_6 ) )
F_341 ( V_6 ) ;
V_423 = F_347 ( V_6 , true ) ;
if ( ! V_26 )
V_26 = V_423 ;
V_423 = F_345 ( V_6 , false ) ;
if ( ! V_26 )
V_26 = V_423 ;
F_351 ( V_6 ) ;
if ( V_435 )
F_352 ( V_6 ) ;
return V_26 ;
}
static int F_353 ( struct V_10 * V_11 )
{
struct V_33 * V_67 = F_323 ( V_11 ) ;
struct V_63 * V_13 = F_67 ( V_67 ) ;
struct V_5 * V_6 = F_27 ( V_13 ) ;
int V_26 ;
if ( F_279 ( ! ( V_6 -> V_436 . V_159 && F_354 () ) ) )
return - V_74 ;
if ( F_279 ( ! F_355 ( V_6 ) ) )
return - V_74 ;
F_10 ( L_65 ) ;
F_256 ( V_6 ) ;
F_356 ( V_6 ) ;
F_357 ( V_6 ) ;
F_263 ( V_6 ) ;
V_26 = 0 ;
if ( F_274 ( V_6 ) ) {
F_358 ( V_6 ) ;
F_276 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_277 ( V_6 ) ;
} else if ( F_58 ( V_6 ) || F_59 ( V_6 ) ) {
V_26 = F_278 ( V_6 ) ;
}
if ( V_26 ) {
F_46 ( L_66 , V_26 ) ;
F_287 ( V_6 ) ;
F_272 ( V_6 ) ;
return V_26 ;
}
F_269 ( V_6 ) ;
F_272 ( V_6 ) ;
F_279 ( F_359 ( & V_6 -> V_437 . V_438 ) ) ;
if ( F_360 ( V_6 ) )
F_46 ( L_67 ) ;
V_6 -> V_437 . V_439 = true ;
if ( F_14 ( V_6 ) ) {
F_268 ( V_6 , V_309 ) ;
} else {
F_268 ( V_6 , V_301 ) ;
}
F_361 ( V_6 ) ;
if ( ! F_58 ( V_6 ) && ! F_59 ( V_6 ) )
F_362 ( V_6 ) ;
F_10 ( L_68 ) ;
return 0 ;
}
static int F_363 ( struct V_10 * V_11 )
{
struct V_33 * V_67 = F_323 ( V_11 ) ;
struct V_63 * V_13 = F_67 ( V_67 ) ;
struct V_5 * V_6 = F_27 ( V_13 ) ;
int V_26 = 0 ;
if ( F_279 ( ! F_355 ( V_6 ) ) )
return - V_74 ;
F_10 ( L_69 ) ;
F_279 ( F_359 ( & V_6 -> V_437 . V_438 ) ) ;
F_256 ( V_6 ) ;
F_268 ( V_6 , V_178 ) ;
V_6 -> V_437 . V_439 = false ;
if ( F_364 ( V_6 ) )
F_53 ( L_70 ) ;
F_291 ( V_6 ) ;
if ( F_274 ( V_6 ) ) {
F_303 ( V_6 ) ;
F_365 ( V_6 , true ) ;
if ( V_6 -> V_307 . V_308 &&
( V_6 -> V_307 . V_440 & V_441 ) )
F_366 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_304 ( V_6 ) ;
} else if ( F_58 ( V_6 ) || F_59 ( V_6 ) ) {
V_26 = F_300 ( V_6 , true ) ;
}
F_367 ( V_6 ) ;
F_368 ( V_6 ) ;
F_287 ( V_6 ) ;
if ( ! F_58 ( V_6 ) && ! F_59 ( V_6 ) )
F_98 ( V_6 ) ;
F_272 ( V_6 ) ;
if ( V_26 )
F_46 ( L_71 , V_26 ) ;
else
F_10 ( L_72 ) ;
return V_26 ;
}
static int
F_369 ( struct V_63 * V_13 , void * V_64 ,
struct V_65 * V_290 )
{
return - V_74 ;
}
