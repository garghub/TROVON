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
V_19 = F_11 ( & F_12 ( V_2 ) -> V_19 , V_19 ) ;
F_13 ( V_2 ) ;
return V_19 ;
}
static bool F_14 ( int V_33 )
{
switch ( V_33 ) {
case V_34 :
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
return true ;
}
return false ;
}
static int F_15 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , unsigned int V_47 )
{
struct V_48 * V_49 = F_12 ( V_2 ) ;
struct V_50 * V_50 = F_16 ( V_2 ) ;
int V_51 , V_52 ;
int V_53 = - V_12 ;
bool V_54 = F_14 ( V_33 ) ;
if ( ! V_46 )
V_51 = 0 ;
else {
if ( V_47 >= sizeof( int ) ) {
if ( F_17 ( V_51 , ( int T_1 * ) V_46 ) )
return - V_55 ;
} else
V_51 = 0 ;
}
V_52 = ( V_51 != 0 ) ;
if ( F_18 ( V_33 ) )
return F_19 ( V_2 , V_33 , V_46 , V_47 ) ;
if ( V_54 )
F_20 () ;
F_21 ( V_2 ) ;
switch ( V_33 ) {
case V_56 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 == V_58 ) {
struct V_18 * V_19 ;
struct V_59 * V_60 ;
if ( V_2 -> V_8 == V_9 )
break;
if ( V_2 -> V_61 == V_62 ||
V_2 -> V_61 == V_63 ) {
struct V_64 * V_65 = F_22 ( V_2 ) ;
if ( V_65 -> V_66 == V_67 ) {
V_53 = - V_68 ;
break;
}
} else if ( V_2 -> V_61 != V_69 )
break;
if ( V_2 -> V_21 != V_70 ) {
V_53 = - V_71 ;
break;
}
if ( F_23 ( V_2 ) ||
! F_24 ( & V_2 -> V_72 ) ) {
V_53 = - V_73 ;
break;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_61 == V_69 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_28 () ;
F_29 ( V_50 , V_2 -> V_74 , - 1 ) ;
F_29 ( V_50 , & V_75 , 1 ) ;
F_30 () ;
V_2 -> V_74 = & V_75 ;
V_27 -> V_76 = & V_77 ;
V_2 -> V_78 -> V_79 = & V_80 ;
V_2 -> V_81 = V_58 ;
F_31 ( V_2 , V_27 -> V_32 ) ;
} else {
struct V_82 * V_83 = & V_84 ;
if ( V_2 -> V_61 == V_63 )
V_83 = & V_85 ;
F_28 () ;
F_29 ( V_50 , V_2 -> V_74 , - 1 ) ;
F_29 ( V_50 , V_83 , 1 ) ;
F_30 () ;
V_2 -> V_74 = V_83 ;
V_2 -> V_78 -> V_79 = & V_86 ;
V_2 -> V_81 = V_58 ;
}
V_19 = F_11 ( & V_49 -> V_19 , NULL ) ;
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_87 ) ;
V_60 = F_11 ( & V_49 -> V_88 , NULL ) ;
F_33 ( V_60 ) ;
V_2 -> V_89 = V_90 ;
F_34 ( V_2 ) ;
F_35 ( V_91 ) ;
V_53 = 0 ;
break;
}
goto V_57;
case V_92 :
if ( V_47 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_57;
V_2 -> V_93 = V_52 ;
V_53 = 0 ;
break;
case V_94 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_97 = V_52 ;
V_53 = 0 ;
break;
case V_98 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_99 = V_52 ;
V_53 = 0 ;
break;
case V_100 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_101 = V_52 ;
V_53 = 0 ;
break;
case V_102 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_103 = V_52 ;
V_53 = 0 ;
break;
case V_104 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_105 = V_52 ;
V_53 = 0 ;
break;
case V_106 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_107 = V_52 ;
V_53 = 0 ;
break;
case V_108 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_109 = V_52 ;
V_53 = 0 ;
break;
case V_110 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_111 = V_52 ;
V_53 = 0 ;
break;
case V_112 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_113 = V_52 ;
V_53 = 0 ;
break;
case V_114 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_115 = V_52 ;
V_53 = 0 ;
break;
case V_116 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 < - 1 || V_51 > 0xff )
goto V_57;
if ( V_51 == - 1 )
V_51 = 0 ;
V_49 -> V_117 = V_51 ;
V_53 = 0 ;
break;
case V_118 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_119 = V_52 ;
V_53 = 0 ;
break;
case V_120 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_121 = V_52 ;
V_53 = 0 ;
break;
case V_122 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_123 = V_52 ;
V_53 = 0 ;
break;
case V_124 :
if ( V_52 && ! F_36 ( V_50 -> V_125 , V_126 ) &&
! F_36 ( V_50 -> V_125 , V_127 ) ) {
V_53 = - V_128 ;
break;
}
if ( V_47 < sizeof( int ) )
goto V_57;
F_2 ( V_2 ) -> V_129 = V_52 ;
V_53 = 0 ;
break;
case V_130 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_95 . V_96 . V_131 = V_52 ;
V_53 = 0 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
{
struct V_18 * V_19 ;
if ( V_47 == 0 )
V_46 = NULL ;
else if ( ! V_46 )
goto V_57;
else if ( V_47 < sizeof( struct V_136 ) ||
V_47 & 0x7 || V_47 > 8 * 255 )
goto V_57;
V_53 = - V_128 ;
if ( V_33 != V_134 && ! F_36 ( V_50 -> V_125 , V_127 ) )
break;
V_19 = F_37 ( V_2 , V_49 -> V_19 , V_33 ,
(struct V_136 T_1 * ) V_46 ,
V_47 ) ;
if ( F_38 ( V_19 ) ) {
V_53 = F_39 ( V_19 ) ;
break;
}
V_53 = - V_137 ;
if ( V_33 == V_134 && V_19 && V_19 -> V_105 ) {
struct V_138 * V_139 = V_19 -> V_105 ;
switch ( V_139 -> type ) {
#if F_40 ( V_140 )
case V_141 :
if ( V_139 -> V_142 != 2 ||
V_139 -> V_143 != 1 )
goto V_144;
break;
#endif
default:
goto V_144;
}
}
V_53 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_144:
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_87 ) ;
break;
}
case V_145 :
{
struct V_146 V_147 ;
if ( V_47 == 0 )
goto V_57;
else if ( V_47 < sizeof( struct V_146 ) || ! V_46 )
goto V_57;
if ( F_41 ( & V_147 , V_46 , sizeof( struct V_146 ) ) ) {
V_53 = - V_55 ;
break;
}
if ( V_2 -> V_148 && V_147 . V_149 != V_2 -> V_148 )
goto V_57;
V_49 -> V_150 . V_149 = V_147 . V_149 ;
V_49 -> V_150 . V_151 = V_147 . V_151 ;
V_53 = 0 ;
break;
}
case V_152 :
{
struct V_18 * V_19 = NULL ;
struct V_153 V_154 ;
struct V_155 V_156 ;
int V_157 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_158 = V_2 -> V_148 ;
V_156 . V_159 = V_2 -> V_160 ;
if ( V_47 == 0 )
goto V_161;
V_53 = - V_137 ;
if ( V_47 > 64 * 1024 )
break;
V_19 = F_42 ( V_2 , sizeof( * V_19 ) + V_47 , V_13 ) ;
V_53 = - V_17 ;
if ( ! V_19 )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_87 = sizeof( * V_19 ) + V_47 ;
V_53 = - V_55 ;
if ( F_41 ( V_19 + 1 , V_46 , V_47 ) )
goto V_162;
V_154 . V_163 = V_47 ;
V_154 . V_164 = ( void * ) ( V_19 + 1 ) ;
V_53 = F_43 ( V_50 , V_2 , & V_154 , & V_156 , V_19 , & V_157 ,
& V_157 , & V_157 ) ;
if ( V_53 )
goto V_162;
V_161:
V_53 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_162:
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_87 ) ;
break;
}
case V_165 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 > 255 || V_51 < - 1 )
goto V_57;
V_49 -> V_166 = V_51 ;
V_53 = 0 ;
break;
case V_167 :
if ( V_2 -> V_8 == V_168 )
break;
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 > 255 || V_51 < - 1 )
goto V_57;
V_49 -> V_169 = ( V_51 == - 1 ? V_170 : V_51 ) ;
V_53 = 0 ;
break;
case V_171 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 != V_52 )
goto V_57;
V_49 -> V_172 = V_52 ;
V_53 = 0 ;
break;
case V_173 :
{
struct V_174 * V_175 = NULL ;
int V_176 ;
if ( V_47 != sizeof( int ) )
goto V_57;
V_176 = ( V_177 int ) F_44 ( ( V_177 V_178 ) V_51 ) ;
if ( V_176 == 0 ) {
V_49 -> V_179 = 0 ;
V_53 = 0 ;
break;
}
V_175 = F_45 ( V_50 , V_176 ) ;
V_53 = - V_73 ;
if ( ! V_175 )
break;
F_46 ( V_175 ) ;
V_53 = - V_137 ;
if ( V_2 -> V_148 )
break;
V_49 -> V_179 = V_176 ;
V_53 = 0 ;
break;
}
case V_180 :
if ( V_2 -> V_8 == V_168 )
break;
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 ) {
struct V_174 * V_175 ;
if ( V_2 -> V_148 && V_2 -> V_148 != V_51 )
goto V_57;
V_175 = F_45 ( V_50 , V_51 ) ;
if ( ! V_175 ) {
V_53 = - V_181 ;
break;
}
F_46 ( V_175 ) ;
}
V_49 -> V_182 = V_51 ;
V_53 = 0 ;
break;
case V_34 :
case V_35 :
{
struct V_183 V_184 ;
if ( V_47 < sizeof( struct V_183 ) )
goto V_57;
V_53 = - V_185 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_53 = - V_55 ;
if ( F_41 ( & V_184 , V_46 , sizeof( struct V_183 ) ) )
break;
if ( V_33 == V_34 )
V_53 = F_47 ( V_2 , V_184 . V_186 , & V_184 . V_187 ) ;
else
V_53 = F_48 ( V_2 , V_184 . V_186 , & V_184 . V_187 ) ;
break;
}
case V_36 :
case V_37 :
{
struct V_183 V_184 ;
if ( V_47 < sizeof( struct V_183 ) )
goto V_57;
V_53 = - V_55 ;
if ( F_41 ( & V_184 , V_46 , sizeof( struct V_183 ) ) )
break;
if ( V_33 == V_36 )
V_53 = F_49 ( V_2 , V_184 . V_186 , & V_184 . V_188 ) ;
else
V_53 = F_50 ( V_2 , V_184 . V_186 , & V_184 . V_188 ) ;
break;
}
case V_38 :
case V_39 :
{
struct V_189 V_190 ;
struct V_191 * V_192 ;
if ( V_47 < sizeof( struct V_189 ) )
goto V_57;
V_53 = - V_55 ;
if ( F_41 ( & V_190 , V_46 , sizeof( struct V_189 ) ) )
break;
if ( V_190 . V_193 . V_194 != V_67 ) {
V_53 = - V_73 ;
break;
}
V_192 = (struct V_191 * ) & V_190 . V_193 ;
if ( V_33 == V_38 )
V_53 = F_47 ( V_2 , V_190 . V_195 ,
& V_192 -> V_196 ) ;
else
V_53 = F_48 ( V_2 , V_190 . V_195 ,
& V_192 -> V_196 ) ;
break;
}
case V_40 :
case V_41 :
case V_42 :
case V_43 :
{
struct V_197 V_198 ;
int V_199 , V_200 ;
if ( V_47 < sizeof( struct V_197 ) )
goto V_57;
if ( F_41 ( & V_198 , V_46 , sizeof( V_198 ) ) ) {
V_53 = - V_55 ;
break;
}
if ( V_198 . V_201 . V_194 != V_67 ||
V_198 . V_202 . V_194 != V_67 ) {
V_53 = - V_73 ;
break;
}
if ( V_33 == V_42 ) {
V_199 = V_203 ;
V_200 = 1 ;
} else if ( V_33 == V_43 ) {
V_199 = V_203 ;
V_200 = 0 ;
} else if ( V_33 == V_40 ) {
struct V_191 * V_192 ;
V_192 = (struct V_191 * ) & V_198 . V_201 ;
V_53 = F_47 ( V_2 , V_198 . V_204 ,
& V_192 -> V_196 ) ;
if ( V_53 && V_53 != - V_16 )
break;
V_199 = V_205 ;
V_200 = 1 ;
} else {
V_199 = V_205 ;
V_200 = 0 ;
}
V_53 = F_51 ( V_200 , V_199 , V_2 , & V_198 ) ;
break;
}
case V_44 :
{
struct V_206 * V_207 ;
if ( V_47 < F_52 ( 0 ) )
goto V_57;
if ( V_47 > V_208 ) {
V_53 = - V_17 ;
break;
}
V_207 = F_3 ( V_47 , V_13 ) ;
if ( ! V_207 ) {
V_53 = - V_17 ;
break;
}
V_53 = - V_55 ;
if ( F_41 ( V_207 , V_46 , V_47 ) ) {
F_6 ( V_207 ) ;
break;
}
if ( V_207 -> V_209 >= 0x1ffffffU ||
V_207 -> V_209 > V_210 ) {
F_6 ( V_207 ) ;
V_53 = - V_17 ;
break;
}
if ( F_52 ( V_207 -> V_209 ) > V_47 ) {
F_6 ( V_207 ) ;
V_53 = - V_137 ;
break;
}
V_53 = F_53 ( V_2 , V_207 ) ;
F_6 ( V_207 ) ;
break;
}
case V_211 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_53 = F_1 ( V_2 , V_51 ) ;
break;
case V_212 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 < V_213 || V_51 > V_214 )
goto V_57;
V_49 -> V_215 = V_51 ;
V_53 = 0 ;
break;
case V_216 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 && V_51 < V_217 )
goto V_57;
V_49 -> V_218 = V_51 ;
V_53 = 0 ;
break;
case V_219 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_220 = V_52 ;
if ( ! V_51 )
F_54 ( & V_2 -> V_221 ) ;
V_53 = 0 ;
break;
case V_222 :
if ( V_47 < sizeof( int ) )
goto V_57;
V_49 -> V_223 = V_52 ;
V_53 = 0 ;
break;
case V_224 :
V_53 = F_55 ( V_2 , V_46 , V_47 ) ;
break;
case V_225 :
case V_226 :
V_53 = - V_128 ;
if ( ! F_36 ( V_50 -> V_125 , V_126 ) )
break;
V_53 = F_56 ( V_2 , V_33 , V_46 , V_47 ) ;
break;
case V_227 :
{
unsigned int V_228 = 0 ;
unsigned int V_229 = ~ 0 ;
if ( V_47 < sizeof( int ) )
goto V_57;
V_53 = - V_137 ;
switch ( V_51 & ( V_230 |
V_231 |
V_232 ) ) {
case V_230 :
V_228 |= V_230 ;
break;
case V_231 :
V_228 |= V_231 ;
break;
case V_232 :
break;
case 0 :
goto V_233;
default:
goto V_57;
}
V_229 &= ~ ( V_230 |
V_231 ) ;
V_233:
switch ( V_51 & ( V_234 | V_235 ) ) {
case V_234 :
break;
case V_235 :
V_228 |= V_235 ;
case 0 :
goto V_236;
default:
goto V_57;
}
V_229 &= ~ V_235 ;
V_236:
switch ( V_51 & ( V_237 | V_238 ) ) {
case V_237 :
case V_238 :
case 0 :
break;
default:
goto V_57;
}
V_49 -> V_239 = ( V_49 -> V_239 & V_229 ) | V_228 ;
V_53 = 0 ;
break;
}
case V_240 :
if ( V_47 < sizeof( int ) )
goto V_57;
if ( V_51 < 0 || V_51 > 255 )
goto V_57;
V_49 -> V_241 = V_51 ;
V_53 = 0 ;
break;
case V_242 :
V_49 -> V_243 = V_52 ;
V_53 = 0 ;
break;
case V_244 :
V_49 -> V_245 = V_52 ;
V_53 = 0 ;
break;
}
F_57 ( V_2 ) ;
if ( V_54 )
F_58 () ;
return V_53 ;
V_57:
F_57 ( V_2 ) ;
if ( V_54 )
F_58 () ;
return - V_137 ;
}
int F_59 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , unsigned int V_47 )
{
int V_246 ;
if ( V_45 == V_247 && V_2 -> V_8 != V_9 )
return V_84 . V_248 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
if ( V_45 != V_249 )
return - V_12 ;
V_246 = F_15 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
#ifdef F_60
if ( V_246 == - V_12 && V_33 != V_225 &&
V_33 != V_226 ) {
F_21 ( V_2 ) ;
V_246 = F_61 ( V_2 , V_250 , V_33 , V_46 ,
V_47 ) ;
F_57 ( V_2 ) ;
}
#endif
return V_246 ;
}
int F_62 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , unsigned int V_47 )
{
int V_246 ;
if ( V_45 == V_247 && V_2 -> V_8 != V_9 ) {
if ( V_84 . V_251 != NULL )
return V_84 . V_251 ( V_2 , V_45 , V_33 ,
V_46 , V_47 ) ;
return V_84 . V_248 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
}
if ( V_45 != V_249 )
return - V_12 ;
if ( V_33 >= V_38 && V_33 <= V_44 )
return F_63 ( V_2 , V_45 , V_33 , V_46 , V_47 ,
F_59 ) ;
V_246 = F_15 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
#ifdef F_60
if ( V_246 == - V_12 && V_33 != V_225 &&
V_33 != V_226 ) {
F_21 ( V_2 ) ;
V_246 = F_64 ( V_2 , V_250 , V_33 ,
V_46 , V_47 ) ;
F_57 ( V_2 ) ;
}
#endif
return V_246 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_33 , char T_1 * V_46 , int V_252 )
{
struct V_136 * V_253 ;
if ( ! V_19 )
return 0 ;
switch ( V_33 ) {
case V_132 :
V_253 = V_19 -> V_254 ;
break;
case V_133 :
V_253 = V_19 -> V_255 ;
break;
case V_134 :
V_253 = (struct V_136 * ) V_19 -> V_105 ;
break;
case V_135 :
V_253 = V_19 -> V_256 ;
break;
default:
return - V_137 ;
}
if ( ! V_253 )
return 0 ;
V_252 = F_66 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_67 ( V_46 , V_253 , V_252 ) )
return - V_55 ;
return V_252 ;
}
static int F_68 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , int T_1 * V_47 , unsigned int V_257 )
{
struct V_48 * V_49 = F_12 ( V_2 ) ;
int V_252 ;
int V_51 ;
if ( F_18 ( V_33 ) )
return F_69 ( V_2 , V_33 , V_46 , V_47 ) ;
if ( F_17 ( V_252 , V_47 ) )
return - V_55 ;
switch ( V_33 ) {
case V_56 :
if ( V_2 -> V_61 != V_62 &&
V_2 -> V_61 != V_63 &&
V_2 -> V_61 != V_69 )
return - V_12 ;
if ( V_2 -> V_21 != V_70 )
return - V_71 ;
V_51 = V_2 -> V_81 ;
break;
case V_44 :
{
struct V_206 V_207 ;
int V_246 ;
if ( V_252 < F_52 ( 0 ) )
return - V_137 ;
if ( F_41 ( & V_207 , V_46 , F_52 ( 0 ) ) )
return - V_55 ;
if ( V_207 . V_258 . V_194 != V_67 )
return - V_73 ;
F_21 ( V_2 ) ;
V_246 = F_70 ( V_2 , & V_207 ,
(struct V_206 T_1 * ) V_46 , V_47 ) ;
F_57 ( V_2 ) ;
return V_246 ;
}
case V_152 :
{
struct V_153 V_154 ;
struct V_59 * V_259 ;
if ( V_2 -> V_8 != V_168 )
return - V_12 ;
V_154 . V_164 = V_46 ;
V_154 . V_163 = V_252 ;
V_154 . V_260 = V_257 ;
F_21 ( V_2 ) ;
V_259 = V_49 -> V_88 ;
if ( V_259 )
F_71 ( V_2 , & V_154 , V_259 ) ;
F_57 ( V_2 ) ;
if ( ! V_259 ) {
if ( V_49 -> V_95 . V_96 . V_97 ) {
struct V_146 V_261 ;
V_261 . V_149 = V_49 -> V_182 ? V_49 -> V_182 :
V_49 -> V_150 . V_149 ;
V_261 . V_151 = V_49 -> V_182 ? V_2 -> V_72 : V_49 -> V_150 . V_151 ;
F_72 ( & V_154 , V_249 , V_145 , sizeof( V_261 ) , & V_261 ) ;
}
if ( V_49 -> V_95 . V_96 . V_101 ) {
int V_262 = V_49 -> V_169 ;
F_72 ( & V_154 , V_249 , V_263 , sizeof( V_262 ) , & V_262 ) ;
}
if ( V_49 -> V_95 . V_96 . V_119 ) {
int V_117 = ( int ) F_73 ( V_49 -> V_264 ) ;
F_72 ( & V_154 , V_249 , V_116 , sizeof( V_117 ) , & V_117 ) ;
}
if ( V_49 -> V_95 . V_96 . V_99 ) {
struct V_146 V_261 ;
V_261 . V_149 = V_49 -> V_182 ? V_49 -> V_182 :
V_49 -> V_150 . V_149 ;
V_261 . V_151 = V_49 -> V_182 ? V_2 -> V_72 :
V_49 -> V_150 . V_151 ;
F_72 ( & V_154 , V_249 , V_98 , sizeof( V_261 ) , & V_261 ) ;
}
if ( V_49 -> V_95 . V_96 . V_103 ) {
int V_262 = V_49 -> V_169 ;
F_72 ( & V_154 , V_249 , V_102 , sizeof( V_262 ) , & V_262 ) ;
}
if ( V_49 -> V_95 . V_96 . V_121 ) {
V_178 V_265 = V_49 -> V_264 ;
F_72 ( & V_154 , V_249 , V_120 , sizeof( V_265 ) , & V_265 ) ;
}
}
V_252 -= V_154 . V_163 ;
return F_74 ( V_252 , V_47 ) ;
}
case V_216 :
{
struct V_266 * V_267 ;
V_51 = 0 ;
F_75 () ;
V_267 = F_76 ( V_2 ) ;
if ( V_267 )
V_51 = F_77 ( V_267 ) ;
F_78 () ;
if ( ! V_51 )
return - V_71 ;
break;
}
case V_92 :
V_51 = V_2 -> V_93 ;
break;
case V_94 :
V_51 = V_49 -> V_95 . V_96 . V_97 ;
break;
case V_98 :
V_51 = V_49 -> V_95 . V_96 . V_99 ;
break;
case V_100 :
V_51 = V_49 -> V_95 . V_96 . V_101 ;
break;
case V_102 :
V_51 = V_49 -> V_95 . V_96 . V_103 ;
break;
case V_104 :
V_51 = V_49 -> V_95 . V_96 . V_105 ;
break;
case V_106 :
V_51 = V_49 -> V_95 . V_96 . V_107 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
{
F_21 ( V_2 ) ;
V_252 = F_65 ( V_2 , V_49 -> V_19 ,
V_33 , V_46 , V_252 ) ;
F_57 ( V_2 ) ;
if ( V_252 < 0 )
return V_252 ;
return F_74 ( V_252 , V_47 ) ;
}
case V_108 :
V_51 = V_49 -> V_95 . V_96 . V_109 ;
break;
case V_110 :
V_51 = V_49 -> V_95 . V_96 . V_111 ;
break;
case V_112 :
V_51 = V_49 -> V_95 . V_96 . V_113 ;
break;
case V_114 :
V_51 = V_49 -> V_95 . V_96 . V_115 ;
break;
case V_116 :
V_51 = V_49 -> V_117 ;
break;
case V_118 :
V_51 = V_49 -> V_95 . V_96 . V_119 ;
break;
case V_120 :
V_51 = V_49 -> V_95 . V_96 . V_121 ;
break;
case V_122 :
V_51 = V_49 -> V_95 . V_96 . V_123 ;
break;
case V_268 :
{
struct V_266 * V_267 ;
struct V_269 V_270 ;
if ( V_252 < sizeof( V_270 ) )
return - V_137 ;
V_252 = sizeof( V_270 ) ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
F_75 () ;
V_267 = F_76 ( V_2 ) ;
if ( V_267 )
V_270 . V_271 = F_77 ( V_267 ) ;
F_78 () ;
if ( ! V_270 . V_271 )
return - V_71 ;
if ( F_74 ( V_252 , V_47 ) )
return - V_55 ;
if ( F_67 ( V_46 , & V_270 , V_252 ) )
return - V_55 ;
return 0 ;
}
case V_124 :
V_51 = F_2 ( V_2 ) -> V_129 ;
break;
case V_130 :
V_51 = V_49 -> V_95 . V_96 . V_131 ;
break;
case V_165 :
case V_167 :
{
struct V_266 * V_267 ;
if ( V_33 == V_165 )
V_51 = V_49 -> V_166 ;
else
V_51 = V_49 -> V_169 ;
if ( V_51 < 0 ) {
F_75 () ;
V_267 = F_76 ( V_2 ) ;
if ( V_267 )
V_51 = F_79 ( V_267 ) ;
F_78 () ;
}
if ( V_51 < 0 )
V_51 = F_16 ( V_2 ) -> V_272 . V_273 -> V_166 ;
break;
}
case V_171 :
V_51 = V_49 -> V_172 ;
break;
case V_180 :
V_51 = V_49 -> V_182 ;
break;
case V_173 :
V_51 = ( V_177 int ) F_80 ( ( V_274 ) V_49 -> V_179 ) ;
break;
case V_212 :
V_51 = V_49 -> V_215 ;
break;
case V_219 :
V_51 = V_49 -> V_220 ;
break;
case V_222 :
V_51 = V_49 -> V_223 ;
break;
case V_224 :
{
struct V_275 V_276 ;
int V_257 ;
if ( V_252 < sizeof( V_276 ) )
return - V_137 ;
if ( F_41 ( & V_276 , V_46 , sizeof( V_276 ) ) )
return - V_55 ;
if ( V_276 . V_277 != V_278 )
return - V_137 ;
V_252 = sizeof( V_276 ) ;
V_257 = V_276 . V_279 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_51 = F_81 ( V_2 , & V_276 , V_257 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_74 ( V_252 , V_47 ) )
return - V_55 ;
if ( F_67 ( V_46 , & V_276 , V_252 ) )
return - V_55 ;
return 0 ;
}
case V_227 :
V_51 = 0 ;
if ( V_49 -> V_239 & V_231 )
V_51 |= V_231 ;
else if ( V_49 -> V_239 & V_230 )
V_51 |= V_230 ;
else {
V_51 |= V_232 ;
}
if ( V_49 -> V_239 & V_235 )
V_51 |= V_235 ;
else
V_51 |= V_234 ;
break;
case V_240 :
V_51 = V_49 -> V_241 ;
break;
case V_242 :
V_51 = V_49 -> V_243 ;
break;
case V_244 :
V_51 = V_49 -> V_245 ;
break;
default:
return - V_12 ;
}
V_252 = F_66 (unsigned int, sizeof(int), len) ;
if ( F_74 ( V_252 , V_47 ) )
return - V_55 ;
if ( F_67 ( V_46 , & V_51 , V_252 ) )
return - V_55 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , int T_1 * V_47 )
{
int V_246 ;
if ( V_45 == V_247 && V_2 -> V_8 != V_9 )
return V_84 . V_280 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
if ( V_45 != V_249 )
return - V_12 ;
V_246 = F_68 ( V_2 , V_45 , V_33 , V_46 , V_47 , 0 ) ;
#ifdef F_60
if ( V_246 == - V_12 && V_33 != V_152 ) {
int V_252 ;
if ( F_17 ( V_252 , V_47 ) )
return - V_55 ;
F_21 ( V_2 ) ;
V_246 = F_83 ( V_2 , V_250 , V_33 , V_46 ,
& V_252 ) ;
F_57 ( V_2 ) ;
if ( V_246 >= 0 )
V_246 = F_74 ( V_252 , V_47 ) ;
}
#endif
return V_246 ;
}
int F_84 ( struct V_1 * V_2 , int V_45 , int V_33 ,
char T_1 * V_46 , int T_1 * V_47 )
{
int V_246 ;
if ( V_45 == V_247 && V_2 -> V_8 != V_9 ) {
if ( V_84 . V_281 != NULL )
return V_84 . V_281 ( V_2 , V_45 , V_33 ,
V_46 , V_47 ) ;
return V_84 . V_280 ( V_2 , V_45 , V_33 , V_46 , V_47 ) ;
}
if ( V_45 != V_249 )
return - V_12 ;
if ( V_33 == V_44 )
return F_85 ( V_2 , V_45 , V_33 , V_46 , V_47 ,
F_82 ) ;
V_246 = F_68 ( V_2 , V_45 , V_33 , V_46 , V_47 ,
V_282 ) ;
#ifdef F_60
if ( V_246 == - V_12 && V_33 != V_152 ) {
int V_252 ;
if ( F_17 ( V_252 , V_47 ) )
return - V_55 ;
F_21 ( V_2 ) ;
V_246 = F_86 ( V_2 , V_250 ,
V_33 , V_46 , & V_252 ) ;
F_57 ( V_2 ) ;
if ( V_246 >= 0 )
V_246 = F_74 ( V_252 , V_47 ) ;
}
#endif
return V_246 ;
}
