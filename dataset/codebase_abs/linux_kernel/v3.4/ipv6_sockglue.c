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
V_19 = F_11 ( & F_12 ( V_2 ) -> V_19 , V_19 ) ;
} else {
F_13 ( & V_2 -> V_33 ) ;
V_19 = F_11 ( & F_12 ( V_2 ) -> V_19 , V_19 ) ;
F_14 ( & V_2 -> V_33 ) ;
}
F_15 ( V_2 ) ;
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , unsigned int V_37 )
{
struct V_38 * V_39 = F_12 ( V_2 ) ;
struct V_40 * V_40 = F_17 ( V_2 ) ;
int V_41 , V_42 ;
int V_43 = - V_12 ;
if ( V_36 == NULL )
V_41 = 0 ;
else {
if ( V_37 >= sizeof( int ) ) {
if ( F_18 ( V_41 , ( int T_1 * ) V_36 ) )
return - V_44 ;
} else
V_41 = 0 ;
}
V_42 = ( V_41 != 0 ) ;
if ( F_19 ( V_35 ) )
return F_20 ( V_2 , V_35 , V_36 , V_37 ) ;
F_21 ( V_2 ) ;
switch ( V_35 ) {
case V_45 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 == V_47 ) {
struct V_18 * V_19 ;
struct V_48 * V_49 ;
if ( V_2 -> V_8 == V_9 )
break;
if ( V_2 -> V_50 == V_51 ||
V_2 -> V_50 == V_52 ) {
struct V_53 * V_54 = F_22 ( V_2 ) ;
if ( V_54 -> V_55 == V_56 ) {
V_43 = - V_57 ;
break;
}
} else if ( V_2 -> V_50 != V_58 )
break;
if ( V_2 -> V_21 != V_59 ) {
V_43 = - V_60 ;
break;
}
if ( F_23 ( V_2 ) ||
! F_24 ( & V_39 -> V_61 ) ) {
V_43 = - V_62 ;
break;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_50 == V_58 ) {
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_28 () ;
F_29 ( V_40 , V_2 -> V_63 , - 1 ) ;
F_29 ( V_40 , & V_64 , 1 ) ;
F_30 () ;
V_2 -> V_63 = & V_64 ;
V_27 -> V_65 = & V_66 ;
V_2 -> V_67 -> V_68 = & V_69 ;
V_2 -> V_70 = V_47 ;
F_31 ( V_2 , V_27 -> V_32 ) ;
} else {
struct V_71 * V_72 = & V_73 ;
if ( V_2 -> V_50 == V_52 )
V_72 = & V_74 ;
F_28 () ;
F_29 ( V_40 , V_2 -> V_63 , - 1 ) ;
F_29 ( V_40 , V_72 , 1 ) ;
F_30 () ;
V_2 -> V_63 = V_72 ;
V_2 -> V_67 -> V_68 = & V_75 ;
V_2 -> V_70 = V_47 ;
}
V_19 = F_11 ( & V_39 -> V_19 , NULL ) ;
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_76 ) ;
V_49 = F_11 ( & V_39 -> V_77 , NULL ) ;
F_33 ( V_49 ) ;
V_2 -> V_78 = V_79 ;
F_34 ( V_2 ) ;
F_35 ( V_80 ) ;
V_43 = 0 ;
break;
}
goto V_46;
case V_81 :
if ( V_37 < sizeof( int ) ||
F_2 ( V_2 ) -> V_10 )
goto V_46;
V_39 -> V_82 = V_42 ;
V_43 = 0 ;
break;
case V_83 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_86 = V_42 ;
V_43 = 0 ;
break;
case V_87 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_88 = V_42 ;
V_43 = 0 ;
break;
case V_89 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_90 = V_42 ;
V_43 = 0 ;
break;
case V_91 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_92 = V_42 ;
V_43 = 0 ;
break;
case V_93 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_94 = V_42 ;
V_43 = 0 ;
break;
case V_95 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_96 = V_42 ;
V_43 = 0 ;
break;
case V_97 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_98 = V_42 ;
V_43 = 0 ;
break;
case V_99 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_100 = V_42 ;
V_43 = 0 ;
break;
case V_101 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_102 = V_42 ;
V_43 = 0 ;
break;
case V_103 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_104 = V_42 ;
V_43 = 0 ;
break;
case V_105 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 < - 1 || V_41 > 0xff )
goto V_46;
if ( V_41 == - 1 )
V_41 = 0 ;
V_39 -> V_106 = V_41 ;
V_43 = 0 ;
break;
case V_107 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_108 = V_42 ;
V_43 = 0 ;
break;
case V_109 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_110 = V_42 ;
V_43 = 0 ;
break;
case V_111 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_112 = V_42 ;
V_43 = 0 ;
break;
case V_113 :
if ( V_42 && ! F_36 ( V_114 ) && ! F_36 ( V_115 ) ) {
V_43 = - V_116 ;
break;
}
if ( V_37 < sizeof( int ) )
goto V_46;
F_2 ( V_2 ) -> V_117 = V_42 ;
V_43 = 0 ;
break;
case V_118 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_84 . V_85 . V_119 = V_42 ;
V_43 = 0 ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
{
struct V_18 * V_19 ;
if ( V_37 == 0 )
V_36 = NULL ;
else if ( V_36 == NULL )
goto V_46;
else if ( V_37 < sizeof( struct V_124 ) ||
V_37 & 0x7 || V_37 > 8 * 255 )
goto V_46;
V_43 = - V_116 ;
if ( V_35 != V_122 && ! F_36 ( V_115 ) )
break;
V_19 = F_37 ( V_2 , V_39 -> V_19 , V_35 ,
(struct V_124 T_1 * ) V_36 ,
V_37 ) ;
if ( F_38 ( V_19 ) ) {
V_43 = F_39 ( V_19 ) ;
break;
}
V_43 = - V_125 ;
if ( V_35 == V_122 && V_19 && V_19 -> V_94 ) {
struct V_126 * V_127 = V_19 -> V_94 ;
switch ( V_127 -> type ) {
#if F_40 ( V_128 ) || F_40 ( V_129 )
case V_130 :
if ( V_127 -> V_131 != 2 ||
V_127 -> V_132 != 1 )
goto V_133;
break;
#endif
default:
goto V_133;
}
}
V_43 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_133:
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_76 ) ;
break;
}
case V_134 :
{
struct V_135 V_136 ;
if ( V_37 == 0 )
goto V_46;
else if ( V_37 < sizeof( struct V_135 ) || V_36 == NULL )
goto V_46;
if ( F_41 ( & V_136 , V_36 , sizeof( struct V_135 ) ) ) {
V_43 = - V_44 ;
break;
}
if ( V_2 -> V_137 && V_136 . V_138 != V_2 -> V_137 )
goto V_46;
V_39 -> V_139 . V_138 = V_136 . V_138 ;
V_39 -> V_139 . V_140 = V_136 . V_140 ;
V_43 = 0 ;
break;
}
case V_141 :
{
struct V_18 * V_19 = NULL ;
struct V_142 V_143 ;
struct V_144 V_145 ;
int V_146 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_147 = V_2 -> V_137 ;
V_145 . V_148 = V_2 -> V_149 ;
if ( V_37 == 0 )
goto V_150;
V_43 = - V_125 ;
if ( V_37 > 64 * 1024 )
break;
V_19 = F_42 ( V_2 , sizeof( * V_19 ) + V_37 , V_13 ) ;
V_43 = - V_17 ;
if ( V_19 == NULL )
break;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_76 = sizeof( * V_19 ) + V_37 ;
V_43 = - V_44 ;
if ( F_41 ( V_19 + 1 , V_36 , V_37 ) )
goto V_151;
V_143 . V_152 = V_37 ;
V_143 . V_153 = ( void * ) ( V_19 + 1 ) ;
V_43 = F_43 ( V_40 , V_2 , & V_143 , & V_145 , V_19 , & V_146 , & V_146 ,
& V_146 ) ;
if ( V_43 )
goto V_151;
V_150:
V_43 = 0 ;
V_19 = F_9 ( V_2 , V_19 ) ;
V_151:
if ( V_19 )
F_32 ( V_2 , V_19 , V_19 -> V_76 ) ;
break;
}
case V_154 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 > 255 || V_41 < - 1 )
goto V_46;
V_39 -> V_155 = V_41 ;
V_43 = 0 ;
break;
case V_156 :
if ( V_2 -> V_8 == V_157 )
break;
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 > 255 || V_41 < - 1 )
goto V_46;
V_39 -> V_158 = ( V_41 == - 1 ? V_159 : V_41 ) ;
V_43 = 0 ;
break;
case V_160 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 != V_42 )
goto V_46;
V_39 -> V_161 = V_42 ;
V_43 = 0 ;
break;
case V_162 :
{
struct V_163 * V_164 = NULL ;
int V_165 ;
if ( V_37 != sizeof( int ) )
goto V_46;
V_165 = ( V_166 int ) F_44 ( ( V_166 V_167 ) V_41 ) ;
if ( V_165 == 0 ) {
V_39 -> V_168 = 0 ;
V_43 = 0 ;
break;
}
V_164 = F_45 ( V_40 , V_165 ) ;
V_43 = - V_62 ;
if ( ! V_164 )
break;
F_46 ( V_164 ) ;
V_43 = - V_125 ;
if ( V_2 -> V_137 )
break;
V_39 -> V_168 = V_165 ;
V_43 = 0 ;
break;
}
case V_169 :
if ( V_2 -> V_8 == V_157 )
break;
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 ) {
struct V_163 * V_164 ;
if ( V_2 -> V_137 && V_2 -> V_137 != V_41 )
goto V_46;
V_164 = F_45 ( V_40 , V_41 ) ;
if ( ! V_164 ) {
V_43 = - V_170 ;
break;
}
F_46 ( V_164 ) ;
}
V_39 -> V_171 = V_41 ;
V_43 = 0 ;
break;
case V_172 :
case V_173 :
{
struct V_174 V_175 ;
if ( V_37 < sizeof( struct V_174 ) )
goto V_46;
V_43 = - V_176 ;
if ( F_2 ( V_2 ) -> V_20 )
break;
V_43 = - V_44 ;
if ( F_41 ( & V_175 , V_36 , sizeof( struct V_174 ) ) )
break;
if ( V_35 == V_172 )
V_43 = F_47 ( V_2 , V_175 . V_177 , & V_175 . V_178 ) ;
else
V_43 = F_48 ( V_2 , V_175 . V_177 , & V_175 . V_178 ) ;
break;
}
case V_179 :
case V_180 :
{
struct V_174 V_175 ;
if ( V_37 < sizeof( struct V_174 ) )
goto V_46;
V_43 = - V_44 ;
if ( F_41 ( & V_175 , V_36 , sizeof( struct V_174 ) ) )
break;
if ( V_35 == V_179 )
V_43 = F_49 ( V_2 , V_175 . V_177 , & V_175 . V_181 ) ;
else
V_43 = F_50 ( V_2 , V_175 . V_177 , & V_175 . V_181 ) ;
break;
}
case V_182 :
case V_183 :
{
struct V_184 V_185 ;
struct V_186 * V_187 ;
if ( V_37 < sizeof( struct V_184 ) )
goto V_46;
V_43 = - V_44 ;
if ( F_41 ( & V_185 , V_36 , sizeof( struct V_184 ) ) )
break;
if ( V_185 . V_188 . V_189 != V_56 ) {
V_43 = - V_62 ;
break;
}
V_187 = (struct V_186 * ) & V_185 . V_188 ;
if ( V_35 == V_182 )
V_43 = F_47 ( V_2 , V_185 . V_190 ,
& V_187 -> V_191 ) ;
else
V_43 = F_48 ( V_2 , V_185 . V_190 ,
& V_187 -> V_191 ) ;
break;
}
case V_192 :
case V_193 :
case V_194 :
case V_195 :
{
struct V_196 V_197 ;
int V_198 , V_199 ;
if ( V_37 < sizeof( struct V_196 ) )
goto V_46;
if ( F_41 ( & V_197 , V_36 , sizeof( V_197 ) ) ) {
V_43 = - V_44 ;
break;
}
if ( V_197 . V_200 . V_189 != V_56 ||
V_197 . V_201 . V_189 != V_56 ) {
V_43 = - V_62 ;
break;
}
if ( V_35 == V_194 ) {
V_198 = V_202 ;
V_199 = 1 ;
} else if ( V_35 == V_195 ) {
V_198 = V_202 ;
V_199 = 0 ;
} else if ( V_35 == V_192 ) {
struct V_186 * V_187 ;
V_187 = (struct V_186 * ) & V_197 . V_200 ;
V_43 = F_47 ( V_2 , V_197 . V_203 ,
& V_187 -> V_191 ) ;
if ( V_43 && V_43 != - V_16 )
break;
V_198 = V_204 ;
V_199 = 1 ;
} else {
V_198 = V_204 ;
V_199 = 0 ;
}
V_43 = F_51 ( V_199 , V_198 , V_2 , & V_197 ) ;
break;
}
case V_205 :
{
extern int V_206 ;
struct V_207 * V_208 ;
if ( V_37 < F_52 ( 0 ) )
goto V_46;
if ( V_37 > V_209 ) {
V_43 = - V_17 ;
break;
}
V_208 = F_3 ( V_37 , V_13 ) ;
if ( ! V_208 ) {
V_43 = - V_17 ;
break;
}
V_43 = - V_44 ;
if ( F_41 ( V_208 , V_36 , V_37 ) ) {
F_6 ( V_208 ) ;
break;
}
if ( V_208 -> V_210 >= 0x1ffffffU ||
V_208 -> V_210 > V_206 ) {
F_6 ( V_208 ) ;
V_43 = - V_17 ;
break;
}
if ( F_52 ( V_208 -> V_210 ) > V_37 ) {
F_6 ( V_208 ) ;
V_43 = - V_125 ;
break;
}
V_43 = F_53 ( V_2 , V_208 ) ;
F_6 ( V_208 ) ;
break;
}
case V_211 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_43 = F_1 ( V_2 , V_41 ) ;
break;
case V_212 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 < V_213 || V_41 > V_214 )
goto V_46;
V_39 -> V_215 = V_41 ;
V_43 = 0 ;
break;
case V_216 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 && V_41 < V_217 )
goto V_46;
V_39 -> V_218 = V_41 ;
V_43 = 0 ;
break;
case V_219 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_220 = V_42 ;
if ( ! V_41 )
F_54 ( & V_2 -> V_221 ) ;
V_43 = 0 ;
break;
case V_222 :
if ( V_37 < sizeof( int ) )
goto V_46;
V_39 -> V_223 = V_42 ;
V_43 = 0 ;
break;
case V_224 :
V_43 = F_55 ( V_2 , V_36 , V_37 ) ;
break;
case V_225 :
case V_226 :
V_43 = - V_116 ;
if ( ! F_36 ( V_114 ) )
break;
V_43 = F_56 ( V_2 , V_35 , V_36 , V_37 ) ;
break;
case V_227 :
{
unsigned int V_228 = 0 ;
unsigned int V_229 = ~ 0 ;
if ( V_37 < sizeof( int ) )
goto V_46;
V_43 = - V_125 ;
switch ( V_41 & ( V_230 |
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
goto V_46;
}
V_229 &= ~ ( V_230 |
V_231 ) ;
V_233:
switch ( V_41 & ( V_234 | V_235 ) ) {
case V_234 :
break;
case V_235 :
V_228 |= V_235 ;
case 0 :
goto V_236;
default:
goto V_46;
}
V_229 &= ~ V_235 ;
V_236:
switch ( V_41 & ( V_237 | V_238 ) ) {
case V_237 :
case V_238 :
case 0 :
break;
default:
goto V_46;
}
V_39 -> V_239 = ( V_39 -> V_239 & V_229 ) | V_228 ;
V_43 = 0 ;
break;
}
case V_240 :
if ( V_37 < sizeof( int ) )
goto V_46;
if ( V_41 < 0 || V_41 > 255 )
goto V_46;
V_39 -> V_241 = V_41 ;
break;
case V_242 :
V_39 -> V_243 = V_42 ;
V_43 = 0 ;
break;
}
F_57 ( V_2 ) ;
return V_43 ;
V_46:
F_57 ( V_2 ) ;
return - V_125 ;
}
int F_58 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , unsigned int V_37 )
{
int V_244 ;
if ( V_34 == V_245 && V_2 -> V_8 != V_9 )
return V_73 . V_246 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
if ( V_34 != V_247 )
return - V_12 ;
V_244 = F_16 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
#ifdef F_59
if ( V_244 == - V_12 && V_35 != V_225 &&
V_35 != V_226 ) {
F_21 ( V_2 ) ;
V_244 = F_60 ( V_2 , V_248 , V_35 , V_36 ,
V_37 ) ;
F_57 ( V_2 ) ;
}
#endif
return V_244 ;
}
int F_61 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , unsigned int V_37 )
{
int V_244 ;
if ( V_34 == V_245 && V_2 -> V_8 != V_9 ) {
if ( V_73 . V_249 != NULL )
return V_73 . V_249 ( V_2 , V_34 , V_35 ,
V_36 , V_37 ) ;
return V_73 . V_246 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
}
if ( V_34 != V_247 )
return - V_12 ;
if ( V_35 >= V_182 && V_35 <= V_205 )
return F_62 ( V_2 , V_34 , V_35 , V_36 , V_37 ,
F_58 ) ;
V_244 = F_16 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
#ifdef F_59
if ( V_244 == - V_12 && V_35 != V_225 &&
V_35 != V_226 ) {
F_21 ( V_2 ) ;
V_244 = F_63 ( V_2 , V_248 , V_35 ,
V_36 , V_37 ) ;
F_57 ( V_2 ) ;
}
#endif
return V_244 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_35 , char T_1 * V_36 , int V_250 )
{
struct V_124 * V_251 ;
if ( ! V_19 )
return 0 ;
switch( V_35 ) {
case V_120 :
V_251 = V_19 -> V_252 ;
break;
case V_121 :
V_251 = V_19 -> V_253 ;
break;
case V_122 :
V_251 = (struct V_124 * ) V_19 -> V_94 ;
break;
case V_123 :
V_251 = V_19 -> V_254 ;
break;
default:
return - V_125 ;
}
if ( ! V_251 )
return 0 ;
V_250 = F_65 (unsigned int, len, ipv6_optlen(hdr)) ;
if ( F_66 ( V_36 , V_251 , V_250 ) )
return - V_44 ;
return V_250 ;
}
static int F_67 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , int T_1 * V_37 , unsigned V_255 )
{
struct V_38 * V_39 = F_12 ( V_2 ) ;
int V_250 ;
int V_41 ;
if ( F_19 ( V_35 ) )
return F_68 ( V_2 , V_35 , V_36 , V_37 ) ;
if ( F_18 ( V_250 , V_37 ) )
return - V_44 ;
switch ( V_35 ) {
case V_45 :
if ( V_2 -> V_50 != V_51 &&
V_2 -> V_50 != V_52 &&
V_2 -> V_50 != V_58 )
return - V_12 ;
if ( V_2 -> V_21 != V_59 )
return - V_60 ;
V_41 = V_2 -> V_70 ;
break;
case V_205 :
{
struct V_207 V_208 ;
int V_244 ;
if ( V_250 < F_52 ( 0 ) )
return - V_125 ;
if ( F_41 ( & V_208 , V_36 , F_52 ( 0 ) ) )
return - V_44 ;
if ( V_208 . V_256 . V_189 != V_56 )
return - V_62 ;
F_21 ( V_2 ) ;
V_244 = F_69 ( V_2 , & V_208 ,
(struct V_207 T_1 * ) V_36 , V_37 ) ;
F_57 ( V_2 ) ;
return V_244 ;
}
case V_141 :
{
struct V_142 V_143 ;
struct V_48 * V_257 ;
if ( V_2 -> V_8 != V_157 )
return - V_12 ;
V_143 . V_153 = V_36 ;
V_143 . V_152 = V_250 ;
V_143 . V_258 = V_255 ;
F_21 ( V_2 ) ;
V_257 = V_39 -> V_77 ;
if ( V_257 )
F_70 ( & V_257 -> V_259 ) ;
F_57 ( V_2 ) ;
if ( V_257 ) {
int V_244 = F_71 ( V_2 , & V_143 , V_257 ) ;
F_33 ( V_257 ) ;
if ( V_244 )
return V_244 ;
} else {
if ( V_39 -> V_84 . V_85 . V_86 ) {
struct V_135 V_260 ;
V_260 . V_138 = V_39 -> V_171 ? V_39 -> V_171 :
V_39 -> V_139 . V_138 ;
V_260 . V_140 = V_39 -> V_171 ? V_39 -> V_61 : V_39 -> V_139 . V_140 ;
F_72 ( & V_143 , V_247 , V_134 , sizeof( V_260 ) , & V_260 ) ;
}
if ( V_39 -> V_84 . V_85 . V_90 ) {
int V_261 = V_39 -> V_158 ;
F_72 ( & V_143 , V_247 , V_262 , sizeof( V_261 ) , & V_261 ) ;
}
if ( V_39 -> V_84 . V_85 . V_108 ) {
int V_106 = V_39 -> V_263 ;
F_72 ( & V_143 , V_247 , V_105 , sizeof( V_106 ) , & V_106 ) ;
}
if ( V_39 -> V_84 . V_85 . V_88 ) {
struct V_135 V_260 ;
V_260 . V_138 = V_39 -> V_171 ? V_39 -> V_171 :
V_39 -> V_139 . V_138 ;
V_260 . V_140 = V_39 -> V_171 ? V_39 -> V_61 : V_39 -> V_139 . V_140 ;
F_72 ( & V_143 , V_247 , V_87 , sizeof( V_260 ) , & V_260 ) ;
}
if ( V_39 -> V_84 . V_85 . V_92 ) {
int V_261 = V_39 -> V_158 ;
F_72 ( & V_143 , V_247 , V_91 , sizeof( V_261 ) , & V_261 ) ;
}
}
V_250 -= V_143 . V_152 ;
return F_73 ( V_250 , V_37 ) ;
}
case V_216 :
{
struct V_264 * V_265 ;
V_41 = 0 ;
F_74 () ;
V_265 = F_75 ( V_2 ) ;
if ( V_265 )
V_41 = F_76 ( V_265 ) ;
F_77 () ;
if ( ! V_41 )
return - V_60 ;
break;
}
case V_81 :
V_41 = V_39 -> V_82 ;
break;
case V_83 :
V_41 = V_39 -> V_84 . V_85 . V_86 ;
break;
case V_87 :
V_41 = V_39 -> V_84 . V_85 . V_88 ;
break;
case V_89 :
V_41 = V_39 -> V_84 . V_85 . V_90 ;
break;
case V_91 :
V_41 = V_39 -> V_84 . V_85 . V_92 ;
break;
case V_93 :
V_41 = V_39 -> V_84 . V_85 . V_94 ;
break;
case V_95 :
V_41 = V_39 -> V_84 . V_85 . V_96 ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
{
F_21 ( V_2 ) ;
V_250 = F_64 ( V_2 , V_39 -> V_19 ,
V_35 , V_36 , V_250 ) ;
F_57 ( V_2 ) ;
if ( V_250 < 0 )
return V_250 ;
return F_73 ( V_250 , V_37 ) ;
}
case V_97 :
V_41 = V_39 -> V_84 . V_85 . V_98 ;
break;
case V_99 :
V_41 = V_39 -> V_84 . V_85 . V_100 ;
break;
case V_101 :
V_41 = V_39 -> V_84 . V_85 . V_102 ;
break;
case V_103 :
V_41 = V_39 -> V_84 . V_85 . V_104 ;
break;
case V_105 :
V_41 = V_39 -> V_106 ;
break;
case V_107 :
V_41 = V_39 -> V_84 . V_85 . V_108 ;
break;
case V_109 :
V_41 = V_39 -> V_84 . V_85 . V_110 ;
break;
case V_111 :
V_41 = V_39 -> V_84 . V_85 . V_112 ;
break;
case V_266 :
{
struct V_264 * V_265 ;
struct V_267 V_268 ;
if ( V_250 < sizeof( V_268 ) )
return - V_125 ;
V_250 = sizeof( V_268 ) ;
memset ( & V_268 , 0 , sizeof( V_268 ) ) ;
F_74 () ;
V_265 = F_75 ( V_2 ) ;
if ( V_265 )
V_268 . V_269 = F_76 ( V_265 ) ;
F_77 () ;
if ( ! V_268 . V_269 )
return - V_60 ;
if ( F_73 ( V_250 , V_37 ) )
return - V_44 ;
if ( F_66 ( V_36 , & V_268 , V_250 ) )
return - V_44 ;
return 0 ;
break;
}
case V_113 :
V_41 = F_2 ( V_2 ) -> V_117 ;
break;
case V_118 :
V_41 = V_39 -> V_84 . V_85 . V_119 ;
break;
case V_154 :
case V_156 :
{
struct V_264 * V_265 ;
if ( V_35 == V_154 )
V_41 = V_39 -> V_155 ;
else
V_41 = V_39 -> V_158 ;
if ( V_41 < 0 ) {
F_74 () ;
V_265 = F_75 ( V_2 ) ;
if ( V_265 )
V_41 = F_78 ( V_265 ) ;
F_77 () ;
}
if ( V_41 < 0 )
V_41 = F_17 ( V_2 ) -> V_270 . V_271 -> V_155 ;
break;
}
case V_160 :
V_41 = V_39 -> V_161 ;
break;
case V_169 :
V_41 = V_39 -> V_171 ;
break;
case V_162 :
V_41 = ( V_166 int ) F_79 ( ( V_272 ) V_39 -> V_168 ) ;
break;
case V_212 :
V_41 = V_39 -> V_215 ;
break;
case V_219 :
V_41 = V_39 -> V_220 ;
break;
case V_222 :
V_41 = V_39 -> V_223 ;
break;
case V_227 :
V_41 = 0 ;
if ( V_39 -> V_239 & V_231 )
V_41 |= V_231 ;
else if ( V_39 -> V_239 & V_230 )
V_41 |= V_230 ;
else {
V_41 |= V_232 ;
}
if ( V_39 -> V_239 & V_235 )
V_41 |= V_235 ;
else
V_41 |= V_234 ;
break;
case V_240 :
V_41 = V_39 -> V_241 ;
break;
case V_242 :
V_41 = V_39 -> V_243 ;
break;
default:
return - V_12 ;
}
V_250 = F_65 (unsigned int, sizeof(int), len) ;
if( F_73 ( V_250 , V_37 ) )
return - V_44 ;
if( F_66 ( V_36 , & V_41 , V_250 ) )
return - V_44 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , int T_1 * V_37 )
{
int V_244 ;
if ( V_34 == V_245 && V_2 -> V_8 != V_9 )
return V_73 . V_273 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
if( V_34 != V_247 )
return - V_12 ;
V_244 = F_67 ( V_2 , V_34 , V_35 , V_36 , V_37 , 0 ) ;
#ifdef F_59
if ( V_244 == - V_12 && V_35 != V_141 ) {
int V_250 ;
if ( F_18 ( V_250 , V_37 ) )
return - V_44 ;
F_21 ( V_2 ) ;
V_244 = F_81 ( V_2 , V_248 , V_35 , V_36 ,
& V_250 ) ;
F_57 ( V_2 ) ;
if ( V_244 >= 0 )
V_244 = F_73 ( V_250 , V_37 ) ;
}
#endif
return V_244 ;
}
int F_82 ( struct V_1 * V_2 , int V_34 , int V_35 ,
char T_1 * V_36 , int T_1 * V_37 )
{
int V_244 ;
if ( V_34 == V_245 && V_2 -> V_8 != V_9 ) {
if ( V_73 . V_274 != NULL )
return V_73 . V_274 ( V_2 , V_34 , V_35 ,
V_36 , V_37 ) ;
return V_73 . V_273 ( V_2 , V_34 , V_35 , V_36 , V_37 ) ;
}
if ( V_34 != V_247 )
return - V_12 ;
if ( V_35 == V_205 )
return F_83 ( V_2 , V_34 , V_35 , V_36 , V_37 ,
F_80 ) ;
V_244 = F_67 ( V_2 , V_34 , V_35 , V_36 , V_37 ,
V_275 ) ;
#ifdef F_59
if ( V_244 == - V_12 && V_35 != V_141 ) {
int V_250 ;
if ( F_18 ( V_250 , V_37 ) )
return - V_44 ;
F_21 ( V_2 ) ;
V_244 = F_84 ( V_2 , V_248 ,
V_35 , V_36 , & V_250 ) ;
F_57 ( V_2 ) ;
if ( V_244 >= 0 )
V_244 = F_73 ( V_250 , V_37 ) ;
}
#endif
return V_244 ;
}
