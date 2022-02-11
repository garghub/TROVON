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
if ( V_6 == NULL ) {
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
static int F_14 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , unsigned int V_36 )
{
struct V_37 * V_38 = F_12 ( V_2 ) ;
struct V_39 * V_39 = F_15 ( V_2 ) ;
int V_40 , V_41 ;
int V_42 = - V_12 ;
if ( V_35 == NULL )
V_40 = 0 ;
else {
if ( V_36 >= sizeof( int ) ) {
if ( F_16 ( V_40 , ( int T_1 * ) V_35 ) )
return - V_43 ;
} else
V_40 = 0 ;
}
V_41 = ( V_40 != 0 ) ;
if ( F_17 ( V_34 ) )
return F_18 ( V_2 , V_34 , V_35 , V_36 ) ;
F_19 ( V_2 ) ;
switch ( V_34 ) {
case V_44 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 == V_46 ) {
struct V_18 * V_19 ;
struct V_47 * V_48 ;
if ( V_2 -> V_8 == V_9 )
break;
if ( V_2 -> V_49 == V_50 ||
V_2 -> V_49 == V_51 ) {
struct V_52 * V_53 = F_20 ( V_2 ) ;
if ( V_53 -> V_54 == V_55 ) {
V_42 = - V_56 ;
break;
}
} else if ( V_2 -> V_49 != V_57 )
break;
if ( V_2 -> V_21 != V_58 ) {
V_42 = - V_59 ;
break;
}
if ( F_21 ( V_2 ) ||
! F_22 ( & V_2 -> V_60 ) ) {
V_42 = - V_61 ;
break;
}
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( V_2 -> V_49 == V_57 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_26 () ;
F_27 ( V_39 , V_2 -> V_62 , - 1 ) ;
F_27 ( V_39 , & V_63 , 1 ) ;
F_28 () ;
V_2 -> V_62 = & V_63 ;
V_27 -> V_64 = & V_65 ;
V_2 -> V_66 -> V_67 = & V_68 ;
V_2 -> V_69 = V_46 ;
F_29 ( V_2 , V_27 -> V_32 ) ;
} else {
struct V_70 * V_71 = & V_72 ;
if ( V_2 -> V_49 == V_51 )
V_71 = & V_73 ;
F_26 () ;
F_27 ( V_39 , V_2 -> V_62 , - 1 ) ;
F_27 ( V_39 , V_71 , 1 ) ;
F_28 () ;
V_2 -> V_62 = V_71 ;
V_2 -> V_66 -> V_67 = & V_74 ;
V_2 -> V_69 = V_46 ;
}
V_19 = F_11 ( & V_38 -> V_19 , NULL ) ;
if ( V_19 )
F_30 ( V_2 , V_19 , V_19 -> V_75 ) ;
V_48 = F_11 ( & V_38 -> V_76 , NULL ) ;
F_31 ( V_48 ) ;
V_2 -> V_77 = V_78 ;
F_32 ( V_2 ) ;
F_33 ( V_79 ) ;
V_42 = 0 ;
break;
}
goto V_45;
case V_80 :
if ( V_36 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_45;
V_2 -> V_81 = V_41 ;
V_42 = 0 ;
break;
case V_82 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_85 = V_41 ;
V_42 = 0 ;
break;
case V_86 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_87 = V_41 ;
V_42 = 0 ;
break;
case V_88 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_89 = V_41 ;
V_42 = 0 ;
break;
case V_90 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_91 = V_41 ;
V_42 = 0 ;
break;
case V_92 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_93 = V_41 ;
V_42 = 0 ;
break;
case V_94 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_95 = V_41 ;
V_42 = 0 ;
break;
case V_96 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_97 = V_41 ;
V_42 = 0 ;
break;
case V_98 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_99 = V_41 ;
V_42 = 0 ;
break;
case V_100 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_101 = V_41 ;
V_42 = 0 ;
break;
case V_102 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_103 = V_41 ;
V_42 = 0 ;
break;
case V_104 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 < - 1 || V_40 > 0xff )
goto V_45;
if ( V_40 == - 1 )
V_40 = 0 ;
V_38 -> V_105 = V_40 ;
V_42 = 0 ;
break;
case V_106 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_107 = V_41 ;
V_42 = 0 ;
break;
case V_108 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_109 = V_41 ;
V_42 = 0 ;
break;
case V_110 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_111 = V_41 ;
V_42 = 0 ;
break;
case V_112 :
if ( V_41 && ! F_34 ( V_39 -> V_113 , V_114 ) &&
! F_34 ( V_39 -> V_113 , V_115 ) ) {
V_42 = - V_116 ;
break;
}
if ( V_36 < sizeof( int ) )
goto V_45;
F_2 ( V_2 ) -> V_117 = V_41 ;
V_42 = 0 ;
break;
case V_118 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_83 . V_84 . V_119 = V_41 ;
V_42 = 0 ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
{
struct V_18 * V_19 ;
if ( V_36 == 0 )
V_35 = NULL ;
else if ( V_35 == NULL )
goto V_45;
else if ( V_36 < sizeof( struct V_124 ) ||
V_36 & 0x7 || V_36 > 8 * 255 )
goto V_45;
V_42 = - V_116 ;
if ( V_34 != V_122 && ! F_34 ( V_39 -> V_113 , V_115 ) )
break;
V_19 = F_35 ( V_2 , V_38 -> V_19 , V_34 ,
(struct V_124 T_1 * ) V_35 ,
V_36 ) ;
if ( F_36 ( V_19 ) ) {
V_42 = F_37 ( V_19 ) ;
break;
}
V_42 = - V_125 ;
if ( V_34 == V_122 && V_19 && V_19 -> V_93 ) {
struct V_126 * V_127 = V_19 -> V_93 ;
switch ( V_127 -> type ) {
#if F_38 ( V_128 )
case V_129 :
if ( V_127 -> V_130 != 2 ||
V_127 -> V_131 != 1 )
goto V_132;
break;
#endif
default:
goto V_132;
}
}
V_42 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_132:
if ( V_19 )
F_30 ( V_2 , V_19 , V_19 -> V_75 ) ;
break;
}
case V_133 :
{
struct V_134 V_135 ;
if ( V_36 == 0 )
goto V_45;
else if ( V_36 < sizeof( struct V_134 ) || V_35 == NULL )
goto V_45;
if ( F_39 ( & V_135 , V_35 , sizeof( struct V_134 ) ) ) {
V_42 = - V_43 ;
break;
}
if ( V_2 -> V_136 && V_135 . V_137 != V_2 -> V_136 )
goto V_45;
V_38 -> V_138 . V_137 = V_135 . V_137 ;
V_38 -> V_138 . V_139 = V_135 . V_139 ;
V_42 = 0 ;
break;
}
case V_140 :
{
struct V_18 * V_19 = NULL ;
struct V_141 V_142 ;
struct V_143 V_144 ;
int V_145 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_146 = V_2 -> V_136 ;
V_144 . V_147 = V_2 -> V_148 ;
if ( V_36 == 0 )
goto V_149;
V_42 = - V_125 ;
if ( V_36 > 64 * 1024 )
break;
V_19 = F_40 ( V_2 , sizeof( * V_19 ) + V_36 , V_13 ) ;
V_42 = - V_17 ;
if ( V_19 == NULL )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_75 = sizeof( * V_19 ) + V_36 ;
V_42 = - V_43 ;
if ( F_39 ( V_19 + 1 , V_35 , V_36 ) )
goto V_150;
V_142 . V_151 = V_36 ;
V_142 . V_152 = ( void * ) ( V_19 + 1 ) ;
V_42 = F_41 ( V_39 , V_2 , & V_142 , & V_144 , V_19 , & V_145 ,
& V_145 , & V_145 ) ;
if ( V_42 )
goto V_150;
V_149:
V_42 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_150:
if ( V_19 )
F_30 ( V_2 , V_19 , V_19 -> V_75 ) ;
break;
}
case V_153 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 > 255 || V_40 < - 1 )
goto V_45;
V_38 -> V_154 = V_40 ;
V_42 = 0 ;
break;
case V_155 :
if ( V_2 -> V_8 == V_156 )
break;
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 > 255 || V_40 < - 1 )
goto V_45;
V_38 -> V_157 = ( V_40 == - 1 ? V_158 : V_40 ) ;
V_42 = 0 ;
break;
case V_159 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 != V_41 )
goto V_45;
V_38 -> V_160 = V_41 ;
V_42 = 0 ;
break;
case V_161 :
{
struct V_162 * V_163 = NULL ;
int V_164 ;
if ( V_36 != sizeof( int ) )
goto V_45;
V_164 = ( V_165 int ) F_42 ( ( V_165 V_166 ) V_40 ) ;
if ( V_164 == 0 ) {
V_38 -> V_167 = 0 ;
V_42 = 0 ;
break;
}
V_163 = F_43 ( V_39 , V_164 ) ;
V_42 = - V_61 ;
if ( ! V_163 )
break;
F_44 ( V_163 ) ;
V_42 = - V_125 ;
if ( V_2 -> V_136 )
break;
V_38 -> V_167 = V_164 ;
V_42 = 0 ;
break;
}
case V_168 :
if ( V_2 -> V_8 == V_156 )
break;
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 ) {
struct V_162 * V_163 ;
if ( V_2 -> V_136 && V_2 -> V_136 != V_40 )
goto V_45;
V_163 = F_43 ( V_39 , V_40 ) ;
if ( ! V_163 ) {
V_42 = - V_169 ;
break;
}
F_44 ( V_163 ) ;
}
V_38 -> V_170 = V_40 ;
V_42 = 0 ;
break;
case V_171 :
case V_172 :
{
struct V_173 V_174 ;
if ( V_36 < sizeof( struct V_173 ) )
goto V_45;
V_42 = - V_175 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_42 = - V_43 ;
if ( F_39 ( & V_174 , V_35 , sizeof( struct V_173 ) ) )
break;
if ( V_34 == V_171 )
V_42 = F_45 ( V_2 , V_174 . V_176 , & V_174 . V_177 ) ;
else
V_42 = F_46 ( V_2 , V_174 . V_176 , & V_174 . V_177 ) ;
break;
}
case V_178 :
case V_179 :
{
struct V_173 V_174 ;
if ( V_36 < sizeof( struct V_173 ) )
goto V_45;
V_42 = - V_43 ;
if ( F_39 ( & V_174 , V_35 , sizeof( struct V_173 ) ) )
break;
if ( V_34 == V_178 )
V_42 = F_47 ( V_2 , V_174 . V_176 , & V_174 . V_180 ) ;
else
V_42 = F_48 ( V_2 , V_174 . V_176 , & V_174 . V_180 ) ;
break;
}
case V_181 :
case V_182 :
{
struct V_183 V_184 ;
struct V_185 * V_186 ;
if ( V_36 < sizeof( struct V_183 ) )
goto V_45;
V_42 = - V_43 ;
if ( F_39 ( & V_184 , V_35 , sizeof( struct V_183 ) ) )
break;
if ( V_184 . V_187 . V_188 != V_55 ) {
V_42 = - V_61 ;
break;
}
V_186 = (struct V_185 * ) & V_184 . V_187 ;
if ( V_34 == V_181 )
V_42 = F_45 ( V_2 , V_184 . V_189 ,
& V_186 -> V_190 ) ;
else
V_42 = F_46 ( V_2 , V_184 . V_189 ,
& V_186 -> V_190 ) ;
break;
}
case V_191 :
case V_192 :
case V_193 :
case V_194 :
{
struct V_195 V_196 ;
int V_197 , V_198 ;
if ( V_36 < sizeof( struct V_195 ) )
goto V_45;
if ( F_39 ( & V_196 , V_35 , sizeof( V_196 ) ) ) {
V_42 = - V_43 ;
break;
}
if ( V_196 . V_199 . V_188 != V_55 ||
V_196 . V_200 . V_188 != V_55 ) {
V_42 = - V_61 ;
break;
}
if ( V_34 == V_193 ) {
V_197 = V_201 ;
V_198 = 1 ;
} else if ( V_34 == V_194 ) {
V_197 = V_201 ;
V_198 = 0 ;
} else if ( V_34 == V_191 ) {
struct V_185 * V_186 ;
V_186 = (struct V_185 * ) & V_196 . V_199 ;
V_42 = F_45 ( V_2 , V_196 . V_202 ,
& V_186 -> V_190 ) ;
if ( V_42 && V_42 != - V_16 )
break;
V_197 = V_203 ;
V_198 = 1 ;
} else {
V_197 = V_203 ;
V_198 = 0 ;
}
V_42 = F_49 ( V_198 , V_197 , V_2 , & V_196 ) ;
break;
}
case V_204 :
{
struct V_205 * V_206 ;
if ( V_36 < F_50 ( 0 ) )
goto V_45;
if ( V_36 > V_207 ) {
V_42 = - V_17 ;
break;
}
V_206 = F_3 ( V_36 , V_13 ) ;
if ( ! V_206 ) {
V_42 = - V_17 ;
break;
}
V_42 = - V_43 ;
if ( F_39 ( V_206 , V_35 , V_36 ) ) {
F_6 ( V_206 ) ;
break;
}
if ( V_206 -> V_208 >= 0x1ffffffU ||
V_206 -> V_208 > V_209 ) {
F_6 ( V_206 ) ;
V_42 = - V_17 ;
break;
}
if ( F_50 ( V_206 -> V_208 ) > V_36 ) {
F_6 ( V_206 ) ;
V_42 = - V_125 ;
break;
}
V_42 = F_51 ( V_2 , V_206 ) ;
F_6 ( V_206 ) ;
break;
}
case V_210 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_42 = F_1 ( V_2 , V_40 ) ;
break;
case V_211 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 < V_212 || V_40 > V_213 )
goto V_45;
V_38 -> V_214 = V_40 ;
V_42 = 0 ;
break;
case V_215 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 && V_40 < V_216 )
goto V_45;
V_38 -> V_217 = V_40 ;
V_42 = 0 ;
break;
case V_218 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_219 = V_41 ;
if ( ! V_40 )
F_52 ( & V_2 -> V_220 ) ;
V_42 = 0 ;
break;
case V_221 :
if ( V_36 < sizeof( int ) )
goto V_45;
V_38 -> V_222 = V_41 ;
V_42 = 0 ;
break;
case V_223 :
V_42 = F_53 ( V_2 , V_35 , V_36 ) ;
break;
case V_224 :
case V_225 :
V_42 = - V_116 ;
if ( ! F_34 ( V_39 -> V_113 , V_114 ) )
break;
V_42 = F_54 ( V_2 , V_34 , V_35 , V_36 ) ;
break;
case V_226 :
{
unsigned int V_227 = 0 ;
unsigned int V_228 = ~ 0 ;
if ( V_36 < sizeof( int ) )
goto V_45;
V_42 = - V_125 ;
switch ( V_40 & ( V_229 |
V_230 |
V_231 ) ) {
case V_229 :
V_227 |= V_229 ;
break;
case V_230 :
V_227 |= V_230 ;
break;
case V_231 :
break;
case 0 :
goto V_232;
default:
goto V_45;
}
V_228 &= ~ ( V_229 |
V_230 ) ;
V_232:
switch ( V_40 & ( V_233 | V_234 ) ) {
case V_233 :
break;
case V_234 :
V_227 |= V_234 ;
case 0 :
goto V_235;
default:
goto V_45;
}
V_228 &= ~ V_234 ;
V_235:
switch ( V_40 & ( V_236 | V_237 ) ) {
case V_236 :
case V_237 :
case 0 :
break;
default:
goto V_45;
}
V_38 -> V_238 = ( V_38 -> V_238 & V_228 ) | V_227 ;
V_42 = 0 ;
break;
}
case V_239 :
if ( V_36 < sizeof( int ) )
goto V_45;
if ( V_40 < 0 || V_40 > 255 )
goto V_45;
V_38 -> V_240 = V_40 ;
V_42 = 0 ;
break;
case V_241 :
V_38 -> V_242 = V_41 ;
V_42 = 0 ;
break;
case V_243 :
V_38 -> V_244 = V_41 ;
V_42 = 0 ;
break;
}
F_55 ( V_2 ) ;
return V_42 ;
V_45:
F_55 ( V_2 ) ;
return - V_125 ;
}
int F_56 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , unsigned int V_36 )
{
int V_245 ;
if ( V_33 == V_246 && V_2 -> V_8 != V_9 )
return V_72 . V_247 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
if ( V_33 != V_248 )
return - V_12 ;
V_245 = F_14 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
#ifdef F_57
if ( V_245 == - V_12 && V_34 != V_224 &&
V_34 != V_225 ) {
F_19 ( V_2 ) ;
V_245 = F_58 ( V_2 , V_249 , V_34 , V_35 ,
V_36 ) ;
F_55 ( V_2 ) ;
}
#endif
return V_245 ;
}
int F_59 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , unsigned int V_36 )
{
int V_245 ;
if ( V_33 == V_246 && V_2 -> V_8 != V_9 ) {
if ( V_72 . V_250 != NULL )
return V_72 . V_250 ( V_2 , V_33 , V_34 ,
V_35 , V_36 ) ;
return V_72 . V_247 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
}
if ( V_33 != V_248 )
return - V_12 ;
if ( V_34 >= V_181 && V_34 <= V_204 )
return F_60 ( V_2 , V_33 , V_34 , V_35 , V_36 ,
F_56 ) ;
V_245 = F_14 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
#ifdef F_57
if ( V_245 == - V_12 && V_34 != V_224 &&
V_34 != V_225 ) {
F_19 ( V_2 ) ;
V_245 = F_61 ( V_2 , V_249 , V_34 ,
V_35 , V_36 ) ;
F_55 ( V_2 ) ;
}
#endif
return V_245 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_34 , char T_1 * V_35 , int V_251 )
{
struct V_124 * V_252 ;
if ( ! V_19 )
return 0 ;
switch ( V_34 ) {
case V_120 :
V_252 = V_19 -> V_253 ;
break;
case V_121 :
V_252 = V_19 -> V_254 ;
break;
case V_122 :
V_252 = (struct V_124 * ) V_19 -> V_93 ;
break;
case V_123 :
V_252 = V_19 -> V_255 ;
break;
default:
return - V_125 ;
}
if ( ! V_252 )
return 0 ;
V_251 = F_63 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_64 ( V_35 , V_252 , V_251 ) )
return - V_43 ;
return V_251 ;
}
static int F_65 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , int T_1 * V_36 , unsigned int V_256 )
{
struct V_37 * V_38 = F_12 ( V_2 ) ;
int V_251 ;
int V_40 ;
if ( F_17 ( V_34 ) )
return F_66 ( V_2 , V_34 , V_35 , V_36 ) ;
if ( F_16 ( V_251 , V_36 ) )
return - V_43 ;
switch ( V_34 ) {
case V_44 :
if ( V_2 -> V_49 != V_50 &&
V_2 -> V_49 != V_51 &&
V_2 -> V_49 != V_57 )
return - V_12 ;
if ( V_2 -> V_21 != V_58 )
return - V_59 ;
V_40 = V_2 -> V_69 ;
break;
case V_204 :
{
struct V_205 V_206 ;
int V_245 ;
if ( V_251 < F_50 ( 0 ) )
return - V_125 ;
if ( F_39 ( & V_206 , V_35 , F_50 ( 0 ) ) )
return - V_43 ;
if ( V_206 . V_257 . V_188 != V_55 )
return - V_61 ;
F_19 ( V_2 ) ;
V_245 = F_67 ( V_2 , & V_206 ,
(struct V_205 T_1 * ) V_35 , V_36 ) ;
F_55 ( V_2 ) ;
return V_245 ;
}
case V_140 :
{
struct V_141 V_142 ;
struct V_47 * V_258 ;
if ( V_2 -> V_8 != V_156 )
return - V_12 ;
V_142 . V_152 = V_35 ;
V_142 . V_151 = V_251 ;
V_142 . V_259 = V_256 ;
F_19 ( V_2 ) ;
V_258 = V_38 -> V_76 ;
if ( V_258 )
F_68 ( & V_258 -> V_260 ) ;
F_55 ( V_2 ) ;
if ( V_258 ) {
F_69 ( V_2 , & V_142 , V_258 ) ;
F_31 ( V_258 ) ;
} else {
if ( V_38 -> V_83 . V_84 . V_85 ) {
struct V_134 V_261 ;
V_261 . V_137 = V_38 -> V_170 ? V_38 -> V_170 :
V_38 -> V_138 . V_137 ;
V_261 . V_139 = V_38 -> V_170 ? V_2 -> V_60 : V_38 -> V_138 . V_139 ;
F_70 ( & V_142 , V_248 , V_133 , sizeof( V_261 ) , & V_261 ) ;
}
if ( V_38 -> V_83 . V_84 . V_89 ) {
int V_262 = V_38 -> V_157 ;
F_70 ( & V_142 , V_248 , V_263 , sizeof( V_262 ) , & V_262 ) ;
}
if ( V_38 -> V_83 . V_84 . V_107 ) {
int V_105 = ( int ) F_71 ( V_38 -> V_264 ) ;
F_70 ( & V_142 , V_248 , V_104 , sizeof( V_105 ) , & V_105 ) ;
}
if ( V_38 -> V_83 . V_84 . V_87 ) {
struct V_134 V_261 ;
V_261 . V_137 = V_38 -> V_170 ? V_38 -> V_170 :
V_38 -> V_138 . V_137 ;
V_261 . V_139 = V_38 -> V_170 ? V_2 -> V_60 :
V_38 -> V_138 . V_139 ;
F_70 ( & V_142 , V_248 , V_86 , sizeof( V_261 ) , & V_261 ) ;
}
if ( V_38 -> V_83 . V_84 . V_91 ) {
int V_262 = V_38 -> V_157 ;
F_70 ( & V_142 , V_248 , V_90 , sizeof( V_262 ) , & V_262 ) ;
}
if ( V_38 -> V_83 . V_84 . V_109 ) {
V_166 V_265 = V_38 -> V_264 ;
F_70 ( & V_142 , V_248 , V_108 , sizeof( V_265 ) , & V_265 ) ;
}
}
V_251 -= V_142 . V_151 ;
return F_72 ( V_251 , V_36 ) ;
}
case V_215 :
{
struct V_266 * V_267 ;
V_40 = 0 ;
F_73 () ;
V_267 = F_74 ( V_2 ) ;
if ( V_267 )
V_40 = F_75 ( V_267 ) ;
F_76 () ;
if ( ! V_40 )
return - V_59 ;
break;
}
case V_80 :
V_40 = V_2 -> V_81 ;
break;
case V_82 :
V_40 = V_38 -> V_83 . V_84 . V_85 ;
break;
case V_86 :
V_40 = V_38 -> V_83 . V_84 . V_87 ;
break;
case V_88 :
V_40 = V_38 -> V_83 . V_84 . V_89 ;
break;
case V_90 :
V_40 = V_38 -> V_83 . V_84 . V_91 ;
break;
case V_92 :
V_40 = V_38 -> V_83 . V_84 . V_93 ;
break;
case V_94 :
V_40 = V_38 -> V_83 . V_84 . V_95 ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
{
F_19 ( V_2 ) ;
V_251 = F_62 ( V_2 , V_38 -> V_19 ,
V_34 , V_35 , V_251 ) ;
F_55 ( V_2 ) ;
if ( V_251 < 0 )
return V_251 ;
return F_72 ( V_251 , V_36 ) ;
}
case V_96 :
V_40 = V_38 -> V_83 . V_84 . V_97 ;
break;
case V_98 :
V_40 = V_38 -> V_83 . V_84 . V_99 ;
break;
case V_100 :
V_40 = V_38 -> V_83 . V_84 . V_101 ;
break;
case V_102 :
V_40 = V_38 -> V_83 . V_84 . V_103 ;
break;
case V_104 :
V_40 = V_38 -> V_105 ;
break;
case V_106 :
V_40 = V_38 -> V_83 . V_84 . V_107 ;
break;
case V_108 :
V_40 = V_38 -> V_83 . V_84 . V_109 ;
break;
case V_110 :
V_40 = V_38 -> V_83 . V_84 . V_111 ;
break;
case V_268 :
{
struct V_266 * V_267 ;
struct V_269 V_270 ;
if ( V_251 < sizeof( V_270 ) )
return - V_125 ;
V_251 = sizeof( V_270 ) ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
F_73 () ;
V_267 = F_74 ( V_2 ) ;
if ( V_267 )
V_270 . V_271 = F_75 ( V_267 ) ;
F_76 () ;
if ( ! V_270 . V_271 )
return - V_59 ;
if ( F_72 ( V_251 , V_36 ) )
return - V_43 ;
if ( F_64 ( V_35 , & V_270 , V_251 ) )
return - V_43 ;
return 0 ;
}
case V_112 :
V_40 = F_2 ( V_2 ) -> V_117 ;
break;
case V_118 :
V_40 = V_38 -> V_83 . V_84 . V_119 ;
break;
case V_153 :
case V_155 :
{
struct V_266 * V_267 ;
if ( V_34 == V_153 )
V_40 = V_38 -> V_154 ;
else
V_40 = V_38 -> V_157 ;
if ( V_40 < 0 ) {
F_73 () ;
V_267 = F_74 ( V_2 ) ;
if ( V_267 )
V_40 = F_77 ( V_267 ) ;
F_76 () ;
}
if ( V_40 < 0 )
V_40 = F_15 ( V_2 ) -> V_272 . V_273 -> V_154 ;
break;
}
case V_159 :
V_40 = V_38 -> V_160 ;
break;
case V_168 :
V_40 = V_38 -> V_170 ;
break;
case V_161 :
V_40 = ( V_165 int ) F_78 ( ( V_274 ) V_38 -> V_167 ) ;
break;
case V_211 :
V_40 = V_38 -> V_214 ;
break;
case V_218 :
V_40 = V_38 -> V_219 ;
break;
case V_221 :
V_40 = V_38 -> V_222 ;
break;
case V_223 :
{
struct V_275 V_276 ;
int V_256 ;
if ( V_251 < sizeof( V_276 ) )
return - V_125 ;
if ( F_39 ( & V_276 , V_35 , sizeof( V_276 ) ) )
return - V_43 ;
if ( V_276 . V_277 != V_278 )
return - V_125 ;
V_251 = sizeof( V_276 ) ;
V_256 = V_276 . V_279 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_40 = F_79 ( V_2 , & V_276 , V_256 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( F_72 ( V_251 , V_36 ) )
return - V_43 ;
if ( F_64 ( V_35 , & V_276 , V_251 ) )
return - V_43 ;
return 0 ;
}
case V_226 :
V_40 = 0 ;
if ( V_38 -> V_238 & V_230 )
V_40 |= V_230 ;
else if ( V_38 -> V_238 & V_229 )
V_40 |= V_229 ;
else {
V_40 |= V_231 ;
}
if ( V_38 -> V_238 & V_234 )
V_40 |= V_234 ;
else
V_40 |= V_233 ;
break;
case V_239 :
V_40 = V_38 -> V_240 ;
break;
case V_241 :
V_40 = V_38 -> V_242 ;
break;
case V_243 :
V_40 = V_38 -> V_244 ;
break;
default:
return - V_12 ;
}
V_251 = F_63 (unsigned int, sizeof(int), len) ;
if ( F_72 ( V_251 , V_36 ) )
return - V_43 ;
if ( F_64 ( V_35 , & V_40 , V_251 ) )
return - V_43 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , int T_1 * V_36 )
{
int V_245 ;
if ( V_33 == V_246 && V_2 -> V_8 != V_9 )
return V_72 . V_280 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
if ( V_33 != V_248 )
return - V_12 ;
V_245 = F_65 ( V_2 , V_33 , V_34 , V_35 , V_36 , 0 ) ;
#ifdef F_57
if ( V_245 == - V_12 && V_34 != V_140 ) {
int V_251 ;
if ( F_16 ( V_251 , V_36 ) )
return - V_43 ;
F_19 ( V_2 ) ;
V_245 = F_81 ( V_2 , V_249 , V_34 , V_35 ,
& V_251 ) ;
F_55 ( V_2 ) ;
if ( V_245 >= 0 )
V_245 = F_72 ( V_251 , V_36 ) ;
}
#endif
return V_245 ;
}
int F_82 ( struct V_1 * V_2 , int V_33 , int V_34 ,
char T_1 * V_35 , int T_1 * V_36 )
{
int V_245 ;
if ( V_33 == V_246 && V_2 -> V_8 != V_9 ) {
if ( V_72 . V_281 != NULL )
return V_72 . V_281 ( V_2 , V_33 , V_34 ,
V_35 , V_36 ) ;
return V_72 . V_280 ( V_2 , V_33 , V_34 , V_35 , V_36 ) ;
}
if ( V_33 != V_248 )
return - V_12 ;
if ( V_34 == V_204 )
return F_83 ( V_2 , V_33 , V_34 , V_35 , V_36 ,
F_80 ) ;
V_245 = F_65 ( V_2 , V_33 , V_34 , V_35 , V_36 ,
V_282 ) ;
#ifdef F_57
if ( V_245 == - V_12 && V_34 != V_140 ) {
int V_251 ;
if ( F_16 ( V_251 , V_36 ) )
return - V_43 ;
F_19 ( V_2 ) ;
V_245 = F_84 ( V_2 , V_249 ,
V_34 , V_35 , & V_251 ) ;
F_55 ( V_2 ) ;
if ( V_245 >= 0 )
V_245 = F_72 ( V_251 , V_36 ) ;
}
#endif
return V_245 ;
}
