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
}
return V_26 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_32 * V_33 = NULL ;
if ( F_18 ( V_6 ) -> V_34 == 0 ) {
V_6 -> V_35 = V_27 ;
return;
}
while ( ( V_33 = F_19 ( V_36 << 8 , V_33 ) ) ) {
if ( V_33 -> V_37 == V_38 ) {
unsigned short V_39 = V_33 -> V_10 & V_40 ;
V_6 -> V_41 = V_39 ;
if ( V_39 == V_42 ) {
V_6 -> V_35 = V_28 ;
F_10 ( L_9 ) ;
F_20 ( ! F_9 ( V_6 ) ) ;
} else if ( V_39 == V_43 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_10 ) ;
F_20 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_39 == V_44 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_11 ) ;
F_20 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_39 == V_45 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_12 ) ;
F_20 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_20 ( F_21 ( V_6 ) ||
F_22 ( V_6 ) ) ;
} else if ( V_39 == V_46 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_13 ) ;
F_20 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_20 ( ! F_21 ( V_6 ) &&
! F_22 ( V_6 ) ) ;
} else if ( V_39 == V_47 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_14 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_39 == V_48 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_15 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_39 == V_49 ) {
V_6 -> V_35 = V_50 ;
F_10 ( L_16 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( ( V_39 == V_51 ) ||
( V_39 == V_52 ) ||
( ( V_39 == V_53 ) &&
V_33 -> V_54 ==
V_55 &&
V_33 -> V_56 ==
V_57 ) ) {
V_6 -> V_35 =
F_8 ( V_6 ) ;
} else
continue;
break;
}
}
if ( ! V_33 )
F_10 ( L_17 ) ;
F_23 ( V_33 ) ;
}
static int F_24 ( struct V_58 * V_13 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
T_2 * V_63 = V_59 ;
int V_64 ;
switch ( V_63 -> V_63 ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
return - V_69 ;
case V_70 :
V_64 = V_62 -> V_10 ;
break;
case V_71 :
V_64 = V_62 -> V_72 ;
break;
case V_73 :
V_64 = V_6 -> V_74 ;
break;
case V_75 :
V_64 = V_6 -> V_76 ? 1 : 0 ;
break;
case V_77 :
V_64 = ! ! V_6 -> V_78 [ V_79 ] ;
break;
case V_80 :
V_64 = ! ! V_6 -> V_78 [ V_81 ] ;
break;
case V_82 :
V_64 = ! ! V_6 -> V_78 [ V_83 ] ;
break;
case V_84 :
V_64 = ! ! V_6 -> V_78 [ V_85 ] ;
break;
case V_86 :
V_64 = F_26 ( V_6 ) ;
break;
case V_87 :
V_64 = F_27 ( V_6 ) ;
break;
case V_88 :
V_64 = F_28 ( V_6 ) ;
break;
case V_89 :
V_64 = V_3 . V_90 ;
break;
case V_91 :
V_64 = F_29 ( V_92 ) ;
break;
case V_93 :
V_64 = F_30 ( V_6 ) ;
break;
case V_94 :
V_64 = F_31 ( & F_18 ( V_6 ) -> V_95 ) ;
if ( ! V_64 )
return - V_69 ;
break;
case V_96 :
V_64 = F_18 ( V_6 ) -> V_95 . V_97 ;
if ( ! V_64 )
return - V_69 ;
break;
case V_98 :
V_64 = V_3 . V_99 && F_32 ( V_6 ) ;
break;
case V_100 :
V_64 = F_33 ( V_6 ) ;
break;
case V_101 :
V_64 = F_34 ( V_6 ) ;
break;
case V_102 :
V_64 = F_18 ( V_6 ) -> V_95 . V_103 ;
break;
case V_104 :
F_35 ( V_6 ) ;
V_64 = F_36 ( V_105 ) & V_106 ;
F_37 ( V_6 ) ;
break;
case V_107 :
V_64 = F_38 () ;
break;
case V_108 :
V_64 = V_6 -> V_78 [ V_109 ] &&
V_6 -> V_78 [ V_109 ] -> V_110 ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
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
V_64 = 1 ;
break;
default:
F_39 ( L_18 , V_63 -> V_63 ) ;
return - V_128 ;
}
if ( F_40 ( V_64 , V_63 -> V_64 ) )
return - V_129 ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 )
{
V_6 -> V_130 = F_42 ( 0 , F_43 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_130 ) {
F_44 ( L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_45 ( struct V_5 * V_6 )
{
int V_131 = F_46 ( V_6 ) >= 4 ? V_132 : V_133 ;
T_3 V_134 , V_135 = 0 ;
T_4 V_136 ;
int V_26 ;
if ( F_46 ( V_6 ) >= 4 )
F_47 ( V_6 -> V_130 , V_131 + 4 , & V_135 ) ;
F_47 ( V_6 -> V_130 , V_131 , & V_134 ) ;
V_136 = ( ( T_4 ) V_135 << 32 ) | V_134 ;
#ifdef F_48
if ( V_136 &&
F_49 ( V_136 , V_136 + V_137 ) )
return 0 ;
#endif
V_6 -> V_138 . V_139 = L_20 ;
V_6 -> V_138 . V_140 = V_141 ;
V_26 = F_50 ( V_6 -> V_130 -> V_142 ,
& V_6 -> V_138 ,
V_137 , V_137 ,
V_143 ,
0 , V_144 ,
V_6 -> V_130 ) ;
if ( V_26 ) {
F_51 ( L_21 , V_26 ) ;
V_6 -> V_138 . V_145 = 0 ;
return V_26 ;
}
if ( F_46 ( V_6 ) >= 4 )
F_52 ( V_6 -> V_130 , V_131 + 4 ,
F_53 ( V_6 -> V_138 . V_145 ) ) ;
F_52 ( V_6 -> V_130 , V_131 ,
F_54 ( V_6 -> V_138 . V_145 ) ) ;
return 0 ;
}
static void
F_55 ( struct V_5 * V_6 )
{
int V_146 = F_46 ( V_6 ) >= 4 ? V_132 : V_133 ;
T_3 V_147 ;
bool V_148 ;
if ( F_56 ( V_6 ) || F_57 ( V_6 ) )
return;
V_6 -> V_149 = false ;
if ( F_58 ( V_6 ) || F_59 ( V_6 ) ) {
F_47 ( V_6 -> V_130 , V_150 , & V_147 ) ;
V_148 = ! ! ( V_147 & V_151 ) ;
} else {
F_47 ( V_6 -> V_130 , V_146 , & V_147 ) ;
V_148 = V_147 & 1 ;
}
if ( V_148 )
return;
if ( F_45 ( V_6 ) )
return;
V_6 -> V_149 = true ;
if ( F_58 ( V_6 ) || F_59 ( V_6 ) ) {
F_52 ( V_6 -> V_130 , V_150 ,
V_147 | V_151 ) ;
} else {
F_47 ( V_6 -> V_130 , V_146 , & V_147 ) ;
F_52 ( V_6 -> V_130 , V_146 , V_147 | 1 ) ;
}
}
static void
F_60 ( struct V_5 * V_6 )
{
int V_146 = F_46 ( V_6 ) >= 4 ? V_132 : V_133 ;
if ( V_6 -> V_149 ) {
if ( F_58 ( V_6 ) || F_59 ( V_6 ) ) {
T_3 V_152 ;
F_47 ( V_6 -> V_130 , V_150 ,
& V_152 ) ;
V_152 &= ~ V_151 ;
F_52 ( V_6 -> V_130 , V_150 ,
V_152 ) ;
} else {
T_3 V_153 ;
F_47 ( V_6 -> V_130 , V_146 ,
& V_153 ) ;
V_153 &= ~ 1 ;
F_52 ( V_6 -> V_130 , V_146 ,
V_153 ) ;
}
}
if ( V_6 -> V_138 . V_145 )
F_61 ( & V_6 -> V_138 ) ;
}
static unsigned int F_62 ( void * V_154 , bool V_155 )
{
struct V_5 * V_6 = V_154 ;
F_63 ( V_6 , V_155 ) ;
if ( V_155 )
return V_156 | V_157 |
V_158 | V_159 ;
else
return V_158 | V_159 ;
}
static void F_64 ( struct V_32 * V_62 , enum V_160 V_155 )
{
struct V_58 * V_13 = F_65 ( V_62 ) ;
T_5 V_161 = { . V_162 = V_163 } ;
if ( V_155 == V_164 ) {
F_66 ( L_22 ) ;
V_13 -> V_165 = V_166 ;
F_67 ( V_62 , V_167 ) ;
F_68 ( V_13 ) ;
V_13 -> V_165 = V_168 ;
} else {
F_66 ( L_23 ) ;
V_13 -> V_165 = V_166 ;
F_69 ( V_13 , V_161 ) ;
V_13 -> V_165 = V_169 ;
}
}
static bool F_70 ( struct V_32 * V_62 )
{
struct V_58 * V_13 = F_65 ( V_62 ) ;
return V_13 -> V_170 == 0 ;
}
static void F_71 ( struct V_5 * V_6 )
{
F_72 ( & V_6 -> V_12 . V_171 ) ;
F_73 ( V_6 ) ;
F_74 ( V_6 ) ;
F_75 ( V_6 ) ;
F_76 ( & V_6 -> V_12 . V_171 ) ;
F_77 ( V_6 ) ;
F_20 ( ! F_78 ( & V_6 -> V_172 ) ) ;
}
static int F_79 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_80 () )
return - V_69 ;
F_81 ( V_6 ) ;
V_26 = F_82 ( V_62 , V_6 , NULL , F_62 ) ;
if ( V_26 && V_26 != - V_69 )
goto V_173;
F_83 () ;
V_26 = F_84 ( V_62 , & V_174 , false ) ;
if ( V_26 )
goto V_175;
F_85 ( V_6 ) ;
F_86 ( V_6 , false ) ;
F_87 ( V_6 ) ;
V_26 = F_88 ( V_6 ) ;
if ( V_26 )
goto V_176;
F_89 ( V_6 ) ;
V_26 = F_90 ( V_13 ) ;
if ( V_26 )
goto V_177;
F_91 ( V_6 ) ;
V_26 = F_92 ( V_6 ) ;
if ( V_26 )
goto V_178;
F_93 ( V_13 ) ;
if ( F_18 ( V_6 ) -> V_34 == 0 )
return 0 ;
V_26 = F_94 ( V_13 ) ;
if ( V_26 )
goto V_179;
F_95 ( V_6 ) ;
F_96 ( V_13 ) ;
return 0 ;
V_179:
if ( F_97 ( V_6 ) )
F_44 ( L_24 ) ;
F_71 ( V_6 ) ;
V_178:
F_98 ( V_6 ) ;
V_177:
F_99 ( V_13 ) ;
F_100 ( V_6 ) ;
V_176:
F_101 ( V_6 ) ;
F_102 ( V_6 ) ;
F_103 ( V_62 ) ;
V_175:
F_82 ( V_62 , NULL , NULL , NULL ) ;
V_173:
return V_26 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_180 * V_181 ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
struct V_182 * V_183 = & V_6 -> V_183 ;
bool V_184 ;
int V_26 ;
V_181 = F_105 ( 1 ) ;
if ( ! V_181 )
return - V_185 ;
V_181 -> V_186 [ 0 ] . V_187 = V_183 -> V_188 ;
V_181 -> V_186 [ 0 ] . V_189 = V_183 -> V_190 ;
V_184 =
V_62 -> V_191 [ V_192 ] . V_140 & V_193 ;
V_26 = F_106 ( V_181 , L_25 , V_184 ) ;
F_107 ( V_181 ) ;
return V_26 ;
}
static int F_108 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_108 ( struct V_5 * V_6 )
{
return - V_69 ;
}
static int F_108 ( struct V_5 * V_6 )
{
int V_26 = 0 ;
F_2 ( L_26 ) ;
F_109 () ;
if ( F_110 ( & V_194 ) )
V_26 = F_111 ( & V_195 , 0 , V_196 - 1 , 1 ) ;
if ( V_26 == 0 ) {
V_26 = F_112 ( & V_194 ) ;
if ( V_26 == - V_69 )
V_26 = 0 ;
}
F_113 () ;
return V_26 ;
}
static void F_114 ( struct V_5 * V_6 )
{
if ( F_57 ( V_6 ) ) {
F_115 ( V_197 ) = V_198 ;
F_115 ( V_199 ) = V_200 ;
} else if ( F_56 ( V_6 ) ) {
F_115 ( V_197 ) = V_200 ;
}
}
static int F_116 ( struct V_5 * V_6 )
{
V_6 -> V_201 = F_117 ( L_27 , 0 ) ;
if ( V_6 -> V_201 == NULL )
goto V_202;
V_6 -> V_203 . V_204 = F_117 ( L_28 , 0 ) ;
if ( V_6 -> V_203 . V_204 == NULL )
goto V_205;
return 0 ;
V_205:
F_118 ( V_6 -> V_201 ) ;
V_202:
F_44 ( L_29 ) ;
return - V_185 ;
}
static void F_119 ( struct V_5 * V_3 )
{
struct V_206 * V_78 ;
enum V_207 V_39 ;
F_120 (engine, i915, id)
F_107 ( V_78 ) ;
}
static void F_121 ( struct V_5 * V_6 )
{
F_118 ( V_6 -> V_203 . V_204 ) ;
F_118 ( V_6 -> V_201 ) ;
}
static void F_122 ( struct V_5 * V_6 )
{
bool V_208 = false ;
V_208 |= F_123 ( V_6 ) ;
V_208 |= F_124 ( V_6 , 0 , V_209 ) ;
V_208 |= F_125 ( V_6 , 0 , V_210 ) ;
if ( V_208 ) {
F_44 ( L_30
L_31 ) ;
F_126 ( V_211 , V_212 ) ;
}
}
static int F_127 ( struct V_5 * V_6 ,
const struct V_213 * V_214 )
{
const struct V_215 * V_216 =
(struct V_215 * ) V_214 -> V_217 ;
struct V_215 * V_218 ;
int V_26 = 0 ;
if ( F_80 () )
return - V_69 ;
V_218 = F_128 ( V_6 ) ;
memcpy ( V_218 , V_216 , sizeof( * V_218 ) ) ;
V_218 -> V_219 = V_6 -> V_12 . V_62 -> V_10 ;
F_129 ( V_218 -> V_220 > sizeof( V_218 -> V_221 ) * V_222 ) ;
V_218 -> V_221 = F_130 ( V_218 -> V_220 - 1 ) ;
F_131 ( & V_6 -> V_223 ) ;
F_131 ( & V_6 -> V_224 . V_225 ) ;
F_132 ( & V_6 -> V_226 ) ;
F_131 ( & V_6 -> V_227 . V_225 ) ;
F_131 ( & V_6 -> V_228 . V_229 ) ;
F_131 ( & V_6 -> V_230 ) ;
F_132 ( & V_6 -> V_231 ) ;
F_132 ( & V_6 -> V_232 ) ;
F_132 ( & V_6 -> V_233 ) ;
F_132 ( & V_6 -> V_234 . V_235 ) ;
F_132 ( & V_6 -> V_236 ) ;
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
V_26 = F_135 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_116 ( V_6 ) ;
if ( V_26 < 0 )
goto V_237;
F_17 ( V_6 ) ;
F_136 ( V_6 ) ;
F_114 ( V_6 ) ;
F_137 ( V_6 ) ;
F_138 ( V_6 ) ;
F_139 ( V_6 ) ;
F_140 ( V_6 ) ;
F_141 ( V_6 ) ;
F_142 ( V_6 ) ;
V_26 = F_143 ( V_6 ) ;
if ( V_26 < 0 )
goto V_238;
F_144 ( V_6 ) ;
F_145 ( V_6 ) ;
F_122 ( V_6 ) ;
F_146 ( V_6 ) ;
return 0 ;
V_238:
F_121 ( V_6 ) ;
V_237:
F_119 ( V_6 ) ;
return V_26 ;
}
static void F_147 ( struct V_5 * V_6 )
{
F_148 ( V_6 ) ;
F_149 ( V_6 ) ;
F_121 ( V_6 ) ;
F_119 ( V_6 ) ;
}
static int F_150 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_239 ;
int V_240 ;
V_239 = F_151 ( V_6 ) ? 1 : 0 ;
if ( F_46 ( V_6 ) < 5 )
V_240 = 512 * 1024 ;
else
V_240 = 2 * 1024 * 1024 ;
V_6 -> V_241 = F_152 ( V_62 , V_239 , V_240 ) ;
if ( V_6 -> V_241 == NULL ) {
F_44 ( L_32 ) ;
return - V_242 ;
}
F_55 ( V_6 ) ;
return 0 ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
F_60 ( V_6 ) ;
F_154 ( V_62 , V_6 -> V_241 ) ;
}
static int F_155 ( struct V_5 * V_6 )
{
int V_26 ;
if ( F_80 () )
return - V_69 ;
if ( F_41 ( V_6 ) )
return - V_242 ;
V_26 = F_150 ( V_6 ) ;
if ( V_26 < 0 )
goto V_243;
F_156 ( V_6 ) ;
F_157 ( V_6 ) ;
return 0 ;
V_243:
F_23 ( V_6 -> V_130 ) ;
return V_26 ;
}
static void F_158 ( struct V_5 * V_6 )
{
F_159 ( V_6 ) ;
F_153 ( V_6 ) ;
F_23 ( V_6 -> V_130 ) ;
}
static void F_160 ( struct V_5 * V_6 )
{
V_3 . V_244 =
F_161 ( V_6 ,
V_3 . V_244 ) ;
V_3 . V_245 =
F_162 ( V_6 , V_3 . V_245 ) ;
F_51 ( L_33 , V_3 . V_245 ) ;
V_3 . V_90 = F_163 ( V_6 , V_3 . V_90 ) ;
F_51 ( L_34 , F_164 ( V_3 . V_90 ) ) ;
F_165 ( V_6 ) ;
}
static int F_166 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_80 () )
return - V_69 ;
F_167 ( V_6 ) ;
F_160 ( V_6 ) ;
V_26 = F_168 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_104 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_35 ) ;
goto V_246;
}
V_26 = F_108 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_36 ) ;
goto V_246;
}
V_26 = F_169 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_170 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_37 ) ;
goto V_246;
}
F_171 ( V_62 ) ;
if ( F_151 ( V_6 ) ) {
V_26 = F_172 ( & V_62 -> V_13 , F_173 ( 30 ) ) ;
if ( V_26 ) {
F_44 ( L_38 ) ;
goto V_246;
}
}
if ( F_174 ( V_6 ) || F_175 ( V_6 ) ) {
V_26 = F_172 ( & V_62 -> V_13 , F_173 ( 32 ) ) ;
if ( V_26 ) {
F_44 ( L_38 ) ;
goto V_246;
}
}
F_176 ( & V_6 -> V_247 , V_248 ,
V_249 ) ;
F_177 ( V_6 ) ;
F_178 ( V_6 ) ;
F_179 ( V_6 ) ;
if ( ! F_180 ( V_6 ) && ! F_181 ( V_6 ) ) {
if ( F_182 ( V_62 ) < 0 )
F_51 ( L_39 ) ;
}
V_26 = F_183 ( V_6 ) ;
if ( V_26 )
goto V_246;
return 0 ;
V_246:
F_184 ( V_6 ) ;
return V_26 ;
}
static void F_185 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
if ( V_62 -> V_250 )
F_186 ( V_62 ) ;
F_187 ( & V_6 -> V_247 ) ;
F_184 ( V_6 ) ;
}
static void F_188 ( struct V_5 * V_6 )
{
struct V_58 * V_13 = & V_6 -> V_12 ;
F_189 ( V_6 ) ;
if ( F_190 ( V_6 ) )
F_191 ( F_192 ( V_251 ) , V_252 ) ;
if ( F_193 ( V_13 , 0 ) == 0 ) {
F_194 ( V_6 ) ;
F_195 ( V_6 ) ;
F_196 ( V_6 ) ;
F_197 ( V_6 ) ;
} else
F_44 ( L_40 ) ;
if ( F_18 ( V_6 ) -> V_34 ) {
F_198 ( V_6 ) ;
F_199 () ;
}
if ( F_9 ( V_6 ) )
F_200 ( V_6 ) ;
F_201 ( V_6 ) ;
F_202 ( V_13 ) ;
}
static void F_203 ( struct V_5 * V_6 )
{
F_204 ( V_6 ) ;
F_205 () ;
F_206 () ;
F_207 ( V_6 ) ;
F_208 ( V_6 ) ;
F_209 ( V_6 ) ;
F_210 ( V_6 ) ;
F_211 ( & V_6 -> V_12 ) ;
F_212 ( V_6 ) ;
}
int F_213 ( struct V_32 * V_62 , const struct V_213 * V_214 )
{
const struct V_215 * V_216 =
(struct V_215 * ) V_214 -> V_217 ;
struct V_5 * V_6 ;
int V_26 ;
if ( ! V_3 . V_253 &&
( V_216 -> V_220 < 5 || V_216 -> V_254 ) )
V_255 . V_256 &= ~ V_257 ;
V_26 = - V_185 ;
V_6 = F_214 ( sizeof( * V_6 ) , V_258 ) ;
if ( V_6 )
V_26 = F_215 ( & V_6 -> V_12 , & V_255 , & V_62 -> V_13 ) ;
if ( V_26 ) {
F_216 ( & V_62 -> V_13 , L_41 ) ;
goto V_259;
}
V_6 -> V_12 . V_62 = V_62 ;
V_6 -> V_12 . V_260 = V_6 ;
V_26 = F_217 ( V_62 ) ;
if ( V_26 )
goto V_261;
F_218 ( V_62 , & V_6 -> V_12 ) ;
V_62 -> V_262 |= V_263 ;
V_26 = F_127 ( V_6 , V_214 ) ;
if ( V_26 < 0 )
goto V_264;
F_35 ( V_6 ) ;
V_26 = F_155 ( V_6 ) ;
if ( V_26 < 0 )
goto V_265;
V_26 = F_166 ( V_6 ) ;
if ( V_26 < 0 )
goto V_266;
if ( F_18 ( V_6 ) -> V_34 ) {
V_26 = F_219 ( & V_6 -> V_12 ,
F_18 ( V_6 ) -> V_34 ) ;
if ( V_26 )
goto V_267;
}
V_26 = F_79 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_268;
F_188 ( V_6 ) ;
F_220 ( V_6 ) ;
V_6 -> V_269 = false ;
if ( F_221 ( V_270 ) )
F_2 ( L_42 ) ;
if ( F_221 ( V_271 ) )
F_2 ( L_43 ) ;
F_37 ( V_6 ) ;
return 0 ;
V_268:
F_222 ( & V_6 -> V_12 ) ;
V_267:
F_185 ( V_6 ) ;
V_266:
F_158 ( V_6 ) ;
V_265:
F_37 ( V_6 ) ;
F_147 ( V_6 ) ;
V_264:
F_223 ( V_62 ) ;
V_261:
F_224 ( V_6 , L_44 , V_26 ) ;
F_225 ( & V_6 -> V_12 ) ;
V_259:
F_107 ( V_6 ) ;
return V_26 ;
}
void F_226 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
F_227 ( V_13 ) ;
if ( F_97 ( V_6 ) )
F_44 ( L_24 ) ;
F_228 ( V_6 , V_272 ) ;
F_229 ( V_13 ) ;
F_230 ( V_6 ) ;
F_203 ( V_6 ) ;
F_222 ( V_13 ) ;
F_231 ( V_13 ) ;
if ( V_6 -> V_273 . V_274 && V_6 -> V_273 . V_275 ) {
F_107 ( V_6 -> V_273 . V_274 ) ;
V_6 -> V_273 . V_274 = NULL ;
V_6 -> V_273 . V_275 = 0 ;
}
F_107 ( V_6 -> V_273 . V_276 ) ;
V_6 -> V_273 . V_276 = NULL ;
F_107 ( V_6 -> V_273 . V_277 ) ;
V_6 -> V_273 . V_277 = NULL ;
F_103 ( V_62 ) ;
F_82 ( V_62 , NULL , NULL , NULL ) ;
F_101 ( V_6 ) ;
F_232 ( & V_6 -> V_224 . V_278 ) ;
F_233 ( V_6 ) ;
F_234 ( V_6 -> V_201 ) ;
F_71 ( V_6 ) ;
F_98 ( V_6 ) ;
F_235 ( V_6 ) ;
F_102 ( V_6 ) ;
F_185 ( V_6 ) ;
F_158 ( V_6 ) ;
F_236 ( V_6 , V_272 ) ;
}
static void F_237 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
F_147 ( V_6 ) ;
F_225 ( & V_6 -> V_12 ) ;
F_107 ( V_6 ) ;
}
static int F_238 ( struct V_58 * V_13 , struct V_60 * V_279 )
{
int V_26 ;
V_26 = F_239 ( V_13 , V_279 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_240 ( struct V_58 * V_13 )
{
F_241 ( V_13 ) ;
F_242 () ;
}
static void F_243 ( struct V_58 * V_13 , struct V_60 * V_279 )
{
struct V_280 * V_61 = V_279 -> V_281 ;
F_72 ( & V_13 -> V_171 ) ;
F_244 ( V_13 , V_279 ) ;
F_245 ( V_13 , V_279 ) ;
F_76 ( & V_13 -> V_171 ) ;
F_107 ( V_61 ) ;
}
static void F_246 ( struct V_5 * V_6 )
{
struct V_58 * V_13 = & V_6 -> V_12 ;
struct V_282 * V_283 ;
F_247 ( V_13 ) ;
F_248 (dev, encoder)
if ( V_283 -> V_284 )
V_283 -> V_284 ( V_283 ) ;
F_249 ( V_13 ) ;
}
static bool F_250 ( struct V_5 * V_6 )
{
#if F_221 ( V_285 )
if ( F_251 () < V_286 )
return true ;
#endif
return false ;
}
static int F_252 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
T_6 V_287 ;
int error ;
F_72 ( & V_6 -> V_232 ) ;
V_6 -> V_288 = V_289 ;
F_76 ( & V_6 -> V_232 ) ;
F_253 ( V_6 ) ;
F_254 ( V_6 , true ) ;
F_255 ( V_13 ) ;
F_256 ( V_62 ) ;
error = F_97 ( V_6 ) ;
if ( error ) {
F_257 ( & V_62 -> V_13 ,
L_45 ) ;
goto V_173;
}
F_258 ( V_13 ) ;
F_259 ( V_13 ) ;
F_260 ( V_6 ) ;
F_261 ( V_6 ) ;
F_246 ( V_6 ) ;
F_262 ( V_6 ) ;
F_263 ( V_6 ) ;
F_264 ( V_6 ) ;
V_287 = F_250 ( V_6 ) ? V_290 : V_291 ;
F_265 ( V_6 , V_287 ) ;
F_266 ( V_6 ) ;
F_207 ( V_6 ) ;
F_267 ( V_13 , V_292 , true ) ;
V_6 -> V_293 ++ ;
F_268 ( V_6 ) ;
V_173:
F_269 ( V_6 ) ;
return error ;
}
static int F_270 ( struct V_58 * V_13 , bool V_294 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
bool V_295 ;
int V_26 ;
F_253 ( V_6 ) ;
F_254 ( V_6 , false ) ;
V_295 = ! F_271 ( V_6 ) &&
F_250 ( V_6 ) && V_6 -> V_296 . V_297 ;
if ( ! V_295 )
F_272 ( V_6 ) ;
V_26 = 0 ;
if ( F_271 ( V_6 ) )
F_273 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_274 ( V_6 ) ;
else if ( F_56 ( V_6 ) || F_57 ( V_6 ) )
V_26 = F_275 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_46 , V_26 ) ;
if ( ! V_295 )
F_86 ( V_6 , true ) ;
goto V_173;
}
F_223 ( V_62 ) ;
if ( ! ( V_294 && F_46 ( V_6 ) < 6 ) )
F_67 ( V_62 , V_298 ) ;
V_6 -> V_299 = F_250 ( V_6 ) ;
V_173:
F_269 ( V_6 ) ;
return V_26 ;
}
static int F_69 ( struct V_58 * V_13 , T_5 V_155 )
{
int error ;
if ( ! V_13 ) {
F_44 ( L_47 , V_13 ) ;
F_44 ( L_48 ) ;
return - V_69 ;
}
if ( F_276 ( V_155 . V_162 != V_163 &&
V_155 . V_162 != V_300 ) )
return - V_128 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
error = F_252 ( V_13 ) ;
if ( error )
return error ;
return F_270 ( V_13 , false ) ;
}
static int F_277 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 ;
F_253 ( V_6 ) ;
F_278 ( V_6 ) ;
V_26 = F_170 ( V_6 ) ;
if ( V_26 )
F_44 ( L_49 ) ;
F_279 ( V_6 ) ;
F_280 ( V_6 ) ;
F_281 ( V_6 ) ;
F_282 ( V_6 ) ;
F_178 ( V_6 ) ;
F_283 ( V_6 ) ;
F_284 ( V_6 ) ;
F_285 ( V_13 ) ;
F_72 ( & V_13 -> V_171 ) ;
if ( F_286 ( V_6 ) ) {
F_44 ( L_50 ) ;
F_287 ( V_6 ) ;
}
F_76 ( & V_13 -> V_171 ) ;
F_288 ( V_6 ) ;
F_289 ( V_13 ) ;
F_290 ( & V_6 -> V_223 ) ;
if ( V_6 -> V_301 . V_302 )
V_6 -> V_301 . V_302 ( V_6 ) ;
F_291 ( & V_6 -> V_223 ) ;
F_292 ( V_13 ) ;
F_293 ( V_13 ) ;
F_294 ( V_13 ) ;
F_95 ( V_6 ) ;
F_198 ( V_6 ) ;
F_267 ( V_13 , V_303 , false ) ;
F_72 ( & V_6 -> V_232 ) ;
V_6 -> V_288 = V_304 ;
F_76 ( & V_6 -> V_232 ) ;
F_265 ( V_6 , V_167 ) ;
F_295 ( V_6 ) ;
F_269 ( V_6 ) ;
return 0 ;
}
static int F_296 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
V_26 = F_67 ( V_62 , V_167 ) ;
if ( V_26 ) {
F_44 ( L_51 , V_26 ) ;
goto V_173;
}
if ( F_217 ( V_62 ) ) {
V_26 = - V_242 ;
goto V_173;
}
F_171 ( V_62 ) ;
F_253 ( V_6 ) ;
if ( F_56 ( V_6 ) || F_57 ( V_6 ) )
V_26 = F_297 ( V_6 , false ) ;
if ( V_26 )
F_44 ( L_52 ,
V_26 ) ;
F_298 ( V_6 ) ;
if ( F_271 ( V_6 ) ) {
if ( ! V_6 -> V_299 )
F_299 ( V_6 ) ;
F_300 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_301 ( V_6 ) ;
}
F_177 ( V_6 ) ;
if ( F_271 ( V_6 ) ||
! ( V_6 -> V_299 && V_6 -> V_296 . V_297 ) )
F_86 ( V_6 , true ) ;
F_302 ( V_6 ) ;
F_269 ( V_6 ) ;
V_173:
V_6 -> V_299 = false ;
return V_26 ;
}
static int F_68 ( struct V_58 * V_13 )
{
int V_26 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
V_26 = F_296 ( V_13 ) ;
if ( V_26 )
return V_26 ;
return F_277 ( V_13 ) ;
}
void F_303 ( struct V_5 * V_6 )
{
struct V_305 * error = & V_6 -> V_224 ;
int V_26 ;
F_304 ( & V_6 -> V_12 . V_171 ) ;
F_305 ( ! F_306 ( V_306 , & error -> V_140 ) ) ;
if ( ! F_306 ( V_307 , & error -> V_140 ) )
return;
if ( ! F_307 ( V_6 ) )
goto V_308;
error -> V_309 ++ ;
F_308 ( L_53 ) ;
F_309 ( V_6 -> V_12 . V_310 ) ;
V_26 = F_310 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_54 ) ;
F_311 ( V_6 , V_311 ) ;
goto error;
}
V_26 = F_311 ( V_6 , V_311 ) ;
if ( V_26 ) {
if ( V_26 != - V_69 )
F_44 ( L_55 , V_26 ) ;
else
F_51 ( L_56 ) ;
goto error;
}
F_312 ( V_6 ) ;
F_313 ( V_6 ) ;
V_26 = F_286 ( V_6 ) ;
if ( V_26 ) {
F_44 ( L_57 , V_26 ) ;
goto error;
}
F_314 ( V_6 ) ;
V_312:
F_315 ( V_6 ) ;
F_316 ( V_6 -> V_12 . V_310 ) ;
V_308:
F_317 ( V_307 , & error -> V_140 ) ;
F_318 ( & error -> V_140 , V_307 ) ;
return;
error:
F_287 ( V_6 ) ;
goto V_312;
}
static int F_319 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_320 ( V_11 ) ;
struct V_58 * V_13 = F_65 ( V_62 ) ;
if ( ! V_13 ) {
F_257 ( V_11 , L_48 ) ;
return - V_69 ;
}
if ( V_13 -> V_165 == V_169 )
return 0 ;
return F_252 ( V_13 ) ;
}
static int F_321 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_322 ( V_11 ) -> V_12 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
return F_270 ( V_13 , false ) ;
}
static int F_323 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_322 ( V_11 ) -> V_12 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
return F_270 ( V_13 , true ) ;
}
static int F_324 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_322 ( V_11 ) -> V_12 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
return F_296 ( V_13 ) ;
}
static int F_325 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_322 ( V_11 ) -> V_12 ;
if ( V_13 -> V_165 == V_169 )
return 0 ;
return F_277 ( V_13 ) ;
}
static int F_326 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_319 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_327 ( F_322 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_328 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_321 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_329 ( F_322 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_330 ( struct V_10 * V_11 )
{
return F_324 ( V_11 ) ;
}
static int F_331 ( struct V_10 * V_11 )
{
return F_325 ( V_11 ) ;
}
static int F_332 ( struct V_10 * V_11 )
{
return F_324 ( V_11 ) ;
}
static int F_333 ( struct V_10 * V_11 )
{
return F_325 ( V_11 ) ;
}
static void F_334 ( struct V_5 * V_6 )
{
struct V_313 * V_314 = & V_6 -> V_313 ;
int V_315 ;
V_314 -> V_316 = F_36 ( V_317 ) ;
V_314 -> V_318 = F_36 ( V_319 ) ;
V_314 -> V_320 = F_36 ( V_321 ) ;
V_314 -> V_322 = F_36 ( V_323 ) ;
V_314 -> V_324 = F_36 ( V_325 ) ;
for ( V_315 = 0 ; V_315 < F_335 ( V_314 -> V_326 ) ; V_315 ++ )
V_314 -> V_326 [ V_315 ] = F_36 ( F_336 ( V_315 ) ) ;
V_314 -> V_327 = F_36 ( V_328 ) ;
V_314 -> V_329 = F_36 ( V_330 ) ;
V_314 -> V_331 = F_36 ( V_332 ) ;
V_314 -> V_333 = F_36 ( V_334 ) ;
V_314 -> V_335 = F_36 ( V_336 ) ;
V_314 -> V_337 = F_36 ( V_338 ) ;
V_314 -> V_339 = F_36 ( V_340 ) ;
V_314 -> V_341 = F_36 ( V_342 ) ;
V_314 -> V_343 = F_36 ( V_344 ) ;
V_314 -> V_345 = F_36 ( V_346 ) ;
V_314 -> V_347 = F_36 ( V_348 ) ;
V_314 -> V_349 = F_36 ( V_350 ) ;
V_314 -> V_351 = F_36 ( V_352 ) ;
V_314 -> V_353 = F_36 ( V_354 ) ;
V_314 -> V_355 = F_36 ( V_356 ) ;
V_314 -> V_357 = F_36 ( V_358 ) ;
V_314 -> V_359 = F_36 ( V_360 ) ;
V_314 -> V_361 = F_36 ( V_362 ) ;
V_314 -> V_363 = F_36 ( V_364 ) ;
V_314 -> V_365 = F_36 ( V_366 ) ;
V_314 -> V_367 = F_36 ( V_368 ) ;
V_314 -> V_369 = F_36 ( V_370 ) ;
V_314 -> V_371 = F_36 ( V_372 ) ;
V_314 -> V_373 = F_36 ( V_374 ) ;
V_314 -> V_375 = F_36 ( V_376 ) ;
V_314 -> V_377 = F_36 ( V_378 ) ;
V_314 -> V_379 = F_36 ( V_380 ) ;
V_314 -> V_381 = F_36 ( V_382 ) ;
V_314 -> V_383 = F_36 ( V_384 ) ;
V_314 -> V_385 = F_36 ( V_386 ) ;
for ( V_315 = 0 ; V_315 < F_335 ( V_314 -> V_387 ) ; V_315 ++ )
V_314 -> V_387 [ V_315 ] = F_36 ( F_337 ( V_315 ) ) ;
V_314 -> V_388 = F_36 ( V_389 ) ;
V_314 -> V_390 = F_36 ( V_391 ) ;
V_314 -> V_392 = F_36 ( V_393 ) ;
V_314 -> V_394 = F_36 ( V_395 ) ;
V_314 -> V_396 = F_36 ( V_397 ) ;
V_314 -> V_398 = F_36 ( V_399 ) ;
V_314 -> V_400 = F_36 ( V_401 ) ;
V_314 -> V_402 = F_36 ( V_403 ) ;
V_314 -> V_404 = F_36 ( V_405 ) ;
}
static void F_338 ( struct V_5 * V_6 )
{
struct V_313 * V_314 = & V_6 -> V_313 ;
T_3 V_406 ;
int V_315 ;
F_191 ( V_317 , V_314 -> V_316 ) ;
F_191 ( V_319 , V_314 -> V_318 ) ;
F_191 ( V_321 , V_314 -> V_320 | ( 0xffff << 16 ) ) ;
F_191 ( V_323 , V_314 -> V_322 ) ;
F_191 ( V_325 , V_314 -> V_324 ) ;
for ( V_315 = 0 ; V_315 < F_335 ( V_314 -> V_326 ) ; V_315 ++ )
F_191 ( F_336 ( V_315 ) , V_314 -> V_326 [ V_315 ] ) ;
F_191 ( V_328 , V_314 -> V_327 ) ;
F_191 ( V_330 , V_314 -> V_329 ) ;
F_191 ( V_332 , V_314 -> V_331 ) ;
F_191 ( V_334 , V_314 -> V_333 ) ;
F_191 ( V_336 , V_314 -> V_335 ) ;
F_191 ( V_338 , V_314 -> V_337 ) ;
F_191 ( V_340 , V_314 -> V_339 ) ;
F_191 ( V_342 , V_314 -> V_341 ) ;
F_191 ( V_344 , V_314 -> V_343 ) ;
F_191 ( V_346 , V_314 -> V_345 ) ;
F_191 ( V_348 , V_314 -> V_347 ) ;
F_191 ( V_350 , V_314 -> V_349 ) ;
F_191 ( V_352 , V_314 -> V_351 ) ;
F_191 ( V_354 , V_314 -> V_353 ) ;
F_191 ( V_356 , V_314 -> V_355 ) ;
F_191 ( V_358 , V_314 -> V_357 ) ;
F_191 ( V_360 , V_314 -> V_359 ) ;
F_191 ( V_362 , V_314 -> V_361 ) ;
F_191 ( V_364 , V_314 -> V_363 ) ;
F_191 ( V_366 , V_314 -> V_365 ) ;
F_191 ( V_368 , V_314 -> V_367 ) ;
F_191 ( V_370 , V_314 -> V_369 ) ;
F_191 ( V_372 , V_314 -> V_371 ) ;
F_191 ( V_374 , V_314 -> V_373 ) ;
F_191 ( V_376 , V_314 -> V_375 ) ;
F_191 ( V_378 , V_314 -> V_377 ) ;
F_191 ( V_380 , V_314 -> V_379 ) ;
F_191 ( V_382 , V_314 -> V_381 ) ;
F_191 ( V_384 , V_314 -> V_383 ) ;
F_191 ( V_386 , V_314 -> V_385 ) ;
for ( V_315 = 0 ; V_315 < F_335 ( V_314 -> V_387 ) ; V_315 ++ )
F_191 ( F_337 ( V_315 ) , V_314 -> V_387 [ V_315 ] ) ;
F_191 ( V_389 , V_314 -> V_388 ) ;
F_191 ( V_391 , V_314 -> V_390 ) ;
V_406 = F_36 ( V_393 ) ;
V_406 &= V_407 ;
V_406 |= V_314 -> V_392 & ~ V_407 ;
F_191 ( V_393 , V_406 ) ;
V_406 = F_36 ( V_395 ) ;
V_406 &= V_408 ;
V_406 |= V_314 -> V_394 & ~ V_408 ;
F_191 ( V_395 , V_406 ) ;
F_191 ( V_397 , V_314 -> V_396 ) ;
F_191 ( V_399 , V_314 -> V_398 ) ;
F_191 ( V_401 , V_314 -> V_400 ) ;
F_191 ( V_403 , V_314 -> V_402 ) ;
F_191 ( V_405 , V_314 -> V_404 ) ;
}
static int F_339 ( struct V_5 * V_6 ,
T_3 V_409 , T_3 V_406 )
{
return F_340 ( ( F_341 ( V_410 ) & V_409 ) == V_406 ,
3 ) ;
}
int F_342 ( struct V_5 * V_6 , bool V_411 )
{
T_3 V_406 ;
int V_412 ;
V_406 = F_36 ( V_395 ) ;
V_406 &= ~ V_408 ;
if ( V_411 )
V_406 |= V_408 ;
F_191 ( V_395 , V_406 ) ;
if ( ! V_411 )
return 0 ;
V_412 = F_343 ( V_6 ,
V_395 ,
V_413 ,
V_413 ,
20 ) ;
if ( V_412 )
F_44 ( L_58 ,
F_36 ( V_395 ) ) ;
return V_412 ;
}
static int F_344 ( struct V_5 * V_6 , bool V_414 )
{
T_3 V_409 ;
T_3 V_406 ;
int V_412 ;
V_406 = F_36 ( V_393 ) ;
V_406 &= ~ V_407 ;
if ( V_414 )
V_406 |= V_407 ;
F_191 ( V_393 , V_406 ) ;
F_345 ( V_393 ) ;
V_409 = V_415 ;
V_406 = V_414 ? V_409 : 0 ;
V_412 = F_339 ( V_6 , V_409 , V_406 ) ;
if ( V_412 )
F_44 ( L_59 ) ;
return V_412 ;
}
static void F_346 ( struct V_5 * V_6 ,
bool V_416 )
{
T_3 V_409 ;
T_3 V_406 ;
V_409 = V_417 | V_418 ;
V_406 = V_416 ? V_409 : 0 ;
if ( F_339 ( V_6 , V_409 , V_406 ) )
F_44 ( L_60 ,
F_347 ( V_416 ) ) ;
}
static void F_348 ( struct V_5 * V_6 )
{
if ( ! ( F_36 ( V_410 ) & V_419 ) )
return;
F_51 ( L_61 ) ;
F_191 ( V_410 , V_419 ) ;
}
static int F_275 ( struct V_5 * V_6 )
{
T_3 V_409 ;
int V_412 ;
F_346 ( V_6 , false ) ;
V_409 = V_420 | V_421 ;
F_20 ( ( F_36 ( V_393 ) & V_409 ) != V_409 ) ;
F_348 ( V_6 ) ;
V_412 = F_342 ( V_6 , true ) ;
if ( V_412 )
goto V_422;
V_412 = F_344 ( V_6 , false ) ;
if ( V_412 )
goto V_423;
if ( ! F_57 ( V_6 ) )
F_334 ( V_6 ) ;
V_412 = F_342 ( V_6 , false ) ;
if ( V_412 )
goto V_423;
return 0 ;
V_423:
F_344 ( V_6 , true ) ;
V_422:
F_342 ( V_6 , false ) ;
return V_412 ;
}
static int F_297 ( struct V_5 * V_6 ,
bool V_424 )
{
int V_412 ;
int V_26 ;
V_26 = F_342 ( V_6 , true ) ;
if ( ! F_57 ( V_6 ) )
F_338 ( V_6 ) ;
V_412 = F_344 ( V_6 , true ) ;
if ( ! V_26 )
V_26 = V_412 ;
V_412 = F_342 ( V_6 , false ) ;
if ( ! V_26 )
V_26 = V_412 ;
F_348 ( V_6 ) ;
if ( V_424 )
F_349 ( V_6 ) ;
return V_26 ;
}
static int F_350 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_320 ( V_11 ) ;
struct V_58 * V_13 = F_65 ( V_62 ) ;
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 ;
if ( F_276 ( ! ( V_6 -> V_425 . V_148 && F_351 () ) ) )
return - V_69 ;
if ( F_276 ( ! F_352 ( V_6 ) ) )
return - V_69 ;
F_10 ( L_62 ) ;
F_253 ( V_6 ) ;
F_353 ( V_6 ) ;
F_354 ( V_6 ) ;
F_260 ( V_6 ) ;
V_26 = 0 ;
if ( F_271 ( V_6 ) ) {
F_355 ( V_6 ) ;
F_273 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_274 ( V_6 ) ;
} else if ( F_56 ( V_6 ) || F_57 ( V_6 ) ) {
V_26 = F_275 ( V_6 ) ;
}
if ( V_26 ) {
F_44 ( L_63 , V_26 ) ;
F_284 ( V_6 ) ;
F_269 ( V_6 ) ;
return V_26 ;
}
F_266 ( V_6 ) ;
F_269 ( V_6 ) ;
F_276 ( F_356 ( & V_6 -> V_426 . V_427 ) ) ;
if ( F_357 ( V_6 ) )
F_44 ( L_64 ) ;
V_6 -> V_426 . V_428 = true ;
if ( F_14 ( V_6 ) ) {
F_265 ( V_6 , V_298 ) ;
} else {
F_265 ( V_6 , V_290 ) ;
}
F_358 ( V_6 ) ;
if ( ! F_56 ( V_6 ) && ! F_57 ( V_6 ) )
F_359 ( V_6 ) ;
F_10 ( L_65 ) ;
return 0 ;
}
static int F_360 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_320 ( V_11 ) ;
struct V_58 * V_13 = F_65 ( V_62 ) ;
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 = 0 ;
if ( F_276 ( ! F_352 ( V_6 ) ) )
return - V_69 ;
F_10 ( L_66 ) ;
F_276 ( F_356 ( & V_6 -> V_426 . V_427 ) ) ;
F_253 ( V_6 ) ;
F_265 ( V_6 , V_167 ) ;
V_6 -> V_426 . V_428 = false ;
if ( F_361 ( V_6 ) )
F_51 ( L_67 ) ;
F_288 ( V_6 ) ;
if ( F_11 ( V_6 ) )
F_283 ( V_6 ) ;
if ( F_271 ( V_6 ) ) {
F_300 ( V_6 ) ;
F_362 ( V_6 , true ) ;
if ( V_6 -> V_296 . V_297 &&
( V_6 -> V_296 . V_429 & V_430 ) )
F_363 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_301 ( V_6 ) ;
} else if ( F_56 ( V_6 ) || F_57 ( V_6 ) ) {
V_26 = F_297 ( V_6 , true ) ;
}
F_364 ( V_6 ) ;
F_365 ( V_6 ) ;
F_284 ( V_6 ) ;
if ( ! F_56 ( V_6 ) && ! F_57 ( V_6 ) )
F_95 ( V_6 ) ;
F_269 ( V_6 ) ;
if ( V_26 )
F_44 ( L_68 , V_26 ) ;
else
F_10 ( L_69 ) ;
return V_26 ;
}
static int
F_366 ( struct V_58 * V_13 , void * V_59 ,
struct V_60 * V_279 )
{
return - V_69 ;
}
