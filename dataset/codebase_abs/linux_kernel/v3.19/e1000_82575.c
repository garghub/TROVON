static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
bool V_4 = false ;
switch ( V_2 -> V_5 . type ) {
case V_6 :
case V_7 :
V_3 = F_2 ( V_8 ) ;
V_4 = ! ! ( V_3 & V_9 ) ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_3 = F_2 ( V_15 ) ;
V_4 = ! ! ( V_3 & V_16 ) ;
break;
default:
break;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 ;
T_3 V_20 ;
T_4 V_21 = 0 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_24 , 0 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_18 -> V_22 . V_25 ( V_2 , V_26 , & V_20 ) ;
if ( V_19 )
return V_19 ;
if ( V_20 & V_27 )
V_21 = V_28 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_24 , 1 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_18 -> V_22 . V_25 ( V_2 , V_26 , & V_20 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_24 , 0 ) ;
if ( V_19 )
return V_19 ;
if ( V_20 & V_27 )
V_21 = V_29 ;
if ( V_21 && ( V_2 -> V_30 . V_31 . V_32 != V_21 ) ) {
V_2 -> V_30 . V_31 . V_32 = V_21 ;
V_2 -> V_30 . V_31 . V_33 = true ;
} else {
V_19 = F_4 ( V_2 ) ;
}
return 0 ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 = 0 ;
T_1 V_34 ;
if ( V_2 -> V_18 . V_35 != V_36 ) {
V_18 -> type = V_37 ;
goto V_38;
}
V_18 -> V_39 = V_40 ;
V_18 -> V_41 = 100 ;
V_34 = F_2 ( V_42 ) ;
if ( F_6 ( V_2 ) ) {
V_18 -> V_22 . V_43 = V_44 ;
V_34 |= V_45 ;
} else {
V_18 -> V_22 . V_43 = V_46 ;
V_34 &= ~ V_45 ;
}
F_7 ( V_42 , V_34 ) ;
F_8 ( V_2 ) ;
if ( F_6 ( V_2 ) && ! F_1 ( V_2 ) ) {
V_18 -> V_22 . V_25 = V_47 ;
V_18 -> V_22 . V_23 = V_48 ;
} else {
switch ( V_2 -> V_5 . type ) {
case V_10 :
case V_11 :
case V_12 :
V_18 -> V_22 . V_25 = V_49 ;
V_18 -> V_22 . V_23 = V_50 ;
break;
case V_13 :
case V_14 :
V_18 -> V_22 . V_25 = V_51 ;
V_18 -> V_22 . V_23 = V_52 ;
break;
default:
V_18 -> V_22 . V_25 = V_53 ;
V_18 -> V_22 . V_23 = V_54 ;
}
}
V_2 -> V_55 . V_56 = ( F_2 ( V_57 ) & V_58 ) >>
V_59 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
switch ( V_18 -> V_60 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_18 -> type = V_65 ;
V_18 -> V_22 . V_66 = V_67 ;
V_18 -> V_22 . V_68 = V_69 ;
if ( V_18 -> V_60 != V_64 )
V_18 -> V_22 . V_70 =
V_71 ;
else
V_18 -> V_22 . V_70 = V_72 ;
V_18 -> V_22 . V_73 = V_74 ;
if ( V_18 -> V_60 == V_63 ) {
T_3 V_20 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 ,
V_24 ,
2 ) ;
if ( V_19 )
goto V_38;
V_19 = V_18 -> V_22 . V_25 ( V_2 ,
V_75 ,
& V_20 ) ;
if ( V_19 )
goto V_38;
V_20 = ( V_20 & V_76 ) >>
V_77 ;
if ( V_20 == V_78 ||
V_20 == V_79 )
V_2 -> V_5 . V_22 . V_80 =
F_3 ;
}
break;
case V_81 :
V_18 -> type = V_82 ;
V_18 -> V_22 . V_68 = V_83 ;
V_18 -> V_22 . V_70 = V_84 ;
V_18 -> V_22 . V_73 = V_85 ;
V_18 -> V_22 . V_86 = V_87 ;
V_18 -> V_22 . V_88 = V_89 ;
break;
case V_90 :
case V_91 :
V_18 -> type = V_92 ;
V_18 -> V_22 . V_73 =
V_93 ;
V_18 -> V_22 . V_70 = V_94 ;
V_18 -> V_22 . V_68 = V_95 ;
V_18 -> V_22 . V_86 = V_96 ;
V_18 -> V_22 . V_88 = V_97 ;
break;
case V_98 :
V_18 -> type = V_99 ;
V_18 -> V_22 . V_66 = V_67 ;
V_18 -> V_22 . V_68 = V_69 ;
V_18 -> V_22 . V_70 = V_71 ;
V_18 -> V_22 . V_86 = V_96 ;
V_18 -> V_22 . V_88 = V_97 ;
V_18 -> V_22 . V_73 = V_74 ;
break;
default:
V_19 = - V_100 ;
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = & V_2 -> V_102 ;
T_1 V_103 = F_2 ( V_104 ) ;
T_3 V_105 ;
V_105 = ( T_3 ) ( ( V_103 & V_106 ) >>
V_107 ) ;
V_105 += V_108 ;
if ( V_105 > 15 )
V_105 = 15 ;
V_102 -> V_109 = 1 << V_105 ;
V_102 -> V_110 = 8 ;
V_102 -> V_111 = 1 ;
switch ( V_102 -> V_112 ) {
case V_113 :
V_102 -> V_114 = 32 ;
V_102 -> V_115 = 16 ;
break;
case V_116 :
V_102 -> V_114 = 8 ;
V_102 -> V_115 = 8 ;
break;
default:
V_102 -> V_114 = V_103 & V_117 ? 32 : 8 ;
V_102 -> V_115 = V_103 & V_117 ?
16 : 8 ;
break;
}
if ( V_102 -> V_109 == ( 1 << 15 ) )
V_102 -> V_114 = 128 ;
V_102 -> type = V_118 ;
V_102 -> V_22 . V_119 = V_120 ;
V_102 -> V_22 . V_121 = V_122 ;
V_102 -> V_22 . V_123 = V_124 ;
V_102 -> V_22 . V_125 = V_126 ;
V_102 -> V_22 . V_127 = V_128 ;
if ( V_102 -> V_109 < ( 1 << 15 ) )
V_102 -> V_22 . V_129 = V_130 ;
else
V_102 -> V_22 . V_129 = V_131 ;
switch ( V_2 -> V_5 . type ) {
case V_10 :
V_102 -> V_22 . V_125 = V_132 ;
V_102 -> V_22 . V_127 = V_133 ;
break;
case V_12 :
case V_11 :
V_102 -> V_22 . V_125 = V_134 ;
V_102 -> V_22 . V_127 = V_135 ;
break;
default:
break;
}
return 0 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_136 * V_5 = & V_2 -> V_5 ;
struct V_137 * V_30 = & V_2 -> V_30 . V_31 ;
V_5 -> V_138 = 128 ;
switch ( V_5 -> type ) {
case V_7 :
V_5 -> V_139 = V_140 ;
break;
case V_10 :
V_5 -> V_139 = V_141 ;
break;
case V_11 :
case V_12 :
V_5 -> V_139 = V_142 ;
break;
default:
V_5 -> V_139 = V_143 ;
break;
}
if ( V_5 -> type >= V_10 )
V_5 -> V_22 . V_144 = V_145 ;
else
V_5 -> V_22 . V_144 = V_146 ;
if ( V_5 -> type >= V_13 ) {
V_5 -> V_22 . V_147 = V_148 ;
V_5 -> V_22 . V_149 = V_150 ;
} else {
V_5 -> V_22 . V_147 = V_151 ;
V_5 -> V_22 . V_149 = V_152 ;
}
V_5 -> V_153 = true ;
V_5 -> V_154 =
( F_2 ( V_155 ) & V_156 )
? true : false ;
if ( V_5 -> type >= V_11 )
V_30 -> V_157 = false ;
else
V_30 -> V_157 = true ;
if ( V_5 -> type >= V_13 )
V_30 -> V_158 = true ;
V_5 -> V_22 . V_159 =
( V_2 -> V_18 . V_35 == V_36 )
? V_160
: V_161 ;
if ( V_5 -> type == V_10 ) {
switch ( V_2 -> V_162 ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
break;
default:
V_2 -> V_30 . V_31 . V_167 = true ;
break;
}
}
return 0 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
T_2 V_19 = V_168 ;
T_1 V_34 = 0 ;
struct V_137 * V_30 = & V_2 -> V_30 . V_31 ;
struct V_169 * V_170 = & V_30 -> V_170 ;
T_4 V_171 = 0 ;
T_2 V_172 = 3 ;
V_34 = F_2 ( V_42 ) ;
V_34 &= ~ V_173 ;
F_7 ( V_42 , V_34 | V_45 ) ;
F_13 () ;
while ( V_172 ) {
V_19 = F_14 ( V_2 ,
F_15 ( V_174 ) ,
& V_171 ) ;
if ( V_19 == 0 )
break;
F_16 ( 100 ) ;
V_172 -- ;
}
if ( V_19 != 0 )
goto V_38;
V_19 = F_14 ( V_2 ,
F_15 ( V_175 ) ,
( T_4 * ) V_170 ) ;
if ( V_19 != 0 )
goto V_38;
if ( ( V_171 == V_176 ) ||
( V_171 == V_177 ) ) {
V_30 -> V_178 = true ;
if ( V_170 -> V_179 || V_170 -> V_180 ) {
V_2 -> V_18 . V_35 = V_181 ;
} else if ( V_170 -> V_182 ) {
V_30 -> V_183 = true ;
V_2 -> V_18 . V_35 = V_181 ;
} else if ( V_170 -> V_184 ) {
V_30 -> V_183 = true ;
V_2 -> V_18 . V_35 = V_36 ;
} else {
V_2 -> V_18 . V_35 = V_185 ;
F_17 ( L_1 ) ;
goto V_38;
}
} else {
V_2 -> V_18 . V_35 = V_185 ;
}
V_19 = 0 ;
V_38:
F_7 ( V_42 , V_34 ) ;
return V_19 ;
}
static T_2 F_18 ( struct V_1 * V_2 )
{
struct V_136 * V_5 = & V_2 -> V_5 ;
struct V_137 * V_30 = & V_2 -> V_30 . V_31 ;
T_2 V_19 ;
T_1 V_34 = 0 ;
T_1 V_186 = 0 ;
switch ( V_2 -> V_162 ) {
case V_187 :
case V_188 :
case V_189 :
V_5 -> type = V_6 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
V_5 -> type = V_7 ;
break;
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_5 -> type = V_10 ;
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_5 -> type = V_11 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
V_5 -> type = V_13 ;
break;
case V_214 :
V_5 -> type = V_14 ;
break;
case V_215 :
case V_216 :
case V_217 :
V_5 -> type = V_12 ;
break;
default:
return - V_218 ;
}
V_2 -> V_18 . V_35 = V_36 ;
V_30 -> V_183 = false ;
V_30 -> V_178 = false ;
V_34 = F_2 ( V_42 ) ;
V_186 = V_34 & V_219 ;
switch ( V_186 ) {
case V_220 :
V_2 -> V_18 . V_35 = V_181 ;
break;
case V_221 :
if ( F_1 ( V_2 ) ) {
V_2 -> V_18 . V_35 = V_36 ;
V_30 -> V_183 = true ;
break;
}
case V_222 :
V_19 = F_12 ( V_2 ) ;
if ( ( V_19 != 0 ) ||
( V_2 -> V_18 . V_35 == V_185 ) ) {
V_2 -> V_18 . V_35 = V_181 ;
if ( V_186 == V_221 ) {
V_2 -> V_18 . V_35 = V_36 ;
V_30 -> V_183 = true ;
}
break;
}
if ( V_30 -> V_170 . V_182 )
break;
V_34 &= ~ V_219 ;
if ( V_2 -> V_18 . V_35 == V_36 )
V_34 |= V_221 ;
else
V_34 |= V_222 ;
F_7 ( V_42 , V_34 ) ;
break;
default:
break;
}
V_19 = F_11 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_10 ( V_2 ) ;
switch ( V_2 -> V_5 . type ) {
case V_13 :
case V_14 :
V_19 = F_19 ( V_2 ) ;
break;
default:
break;
}
if ( V_19 )
goto V_38;
switch ( V_5 -> type ) {
case V_7 :
case V_11 :
F_20 ( V_2 ) ;
break;
default:
break;
}
V_19 = F_5 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 F_21 ( struct V_1 * V_2 )
{
T_3 V_223 = V_224 ;
if ( V_2 -> V_55 . V_56 == V_225 )
V_223 = V_226 ;
else if ( V_2 -> V_55 . V_56 == V_227 )
V_223 = V_228 ;
else if ( V_2 -> V_55 . V_56 == V_229 )
V_223 = V_230 ;
return V_2 -> V_5 . V_22 . V_147 ( V_2 , V_223 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_3 V_223 = V_224 ;
if ( V_2 -> V_55 . V_56 == V_225 )
V_223 = V_226 ;
else if ( V_2 -> V_55 . V_56 == V_227 )
V_223 = V_228 ;
else if ( V_2 -> V_55 . V_56 == V_229 )
V_223 = V_230 ;
V_2 -> V_5 . V_22 . V_149 ( V_2 , V_223 ) ;
}
static T_2 V_47 ( struct V_1 * V_2 , T_1 V_231 ,
T_3 * V_20 )
{
T_2 V_19 = - V_232 ;
if ( V_231 > V_233 ) {
F_17 ( L_2 , V_231 ) ;
goto V_38;
}
V_19 = V_2 -> V_18 . V_22 . V_119 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_23 ( V_2 , V_231 , V_20 ) ;
V_2 -> V_18 . V_22 . V_121 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 V_48 ( struct V_1 * V_2 , T_1 V_231 ,
T_3 V_20 )
{
T_2 V_19 = - V_232 ;
if ( V_231 > V_233 ) {
F_17 ( L_3 , V_231 ) ;
goto V_38;
}
V_19 = V_2 -> V_18 . V_22 . V_119 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_24 ( V_2 , V_231 , V_20 ) ;
V_2 -> V_18 . V_22 . V_121 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 = 0 ;
T_3 V_234 ;
T_1 V_34 ;
T_1 V_235 ;
if ( V_2 -> V_5 . type == V_12 )
F_25 ( V_2 ) ;
if ( ! ( F_6 ( V_2 ) ) ) {
V_18 -> V_236 = 1 ;
V_19 = F_25 ( V_2 ) ;
goto V_38;
}
if ( F_1 ( V_2 ) ) {
switch ( V_2 -> V_5 . type ) {
case V_6 :
case V_7 :
V_235 = F_2 ( V_8 ) ;
V_235 &= V_237 ;
V_18 -> V_236 = V_235 >> V_238 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_235 = F_2 ( V_15 ) ;
V_235 &= V_239 ;
V_18 -> V_236 = V_235 >> V_240 ;
break;
default:
V_19 = - V_100 ;
goto V_38;
}
V_19 = F_25 ( V_2 ) ;
goto V_38;
}
V_34 = F_2 ( V_42 ) ;
F_7 ( V_42 , V_34 & ~ V_173 ) ;
F_13 () ;
F_16 ( 300 ) ;
for ( V_18 -> V_236 = 1 ; V_18 -> V_236 < 8 ; V_18 -> V_236 ++ ) {
V_19 = V_47 ( V_2 , V_241 , & V_234 ) ;
if ( V_19 == 0 ) {
F_17 ( L_4 ,
V_234 , V_18 -> V_236 ) ;
if ( V_234 == V_242 )
break;
} else {
F_17 ( L_5 , V_18 -> V_236 ) ;
}
}
if ( V_18 -> V_236 == 8 ) {
V_18 -> V_236 = 0 ;
V_19 = - V_100 ;
goto V_38;
} else {
V_19 = F_25 ( V_2 ) ;
}
F_7 ( V_42 , V_34 ) ;
V_38:
return V_19 ;
}
static T_2 V_44 ( struct V_1 * V_2 )
{
T_2 V_19 ;
F_17 ( L_6 ) ;
V_19 = V_2 -> V_18 . V_22 . V_23 ( V_2 , 0x1B , 0x8084 ) ;
if ( V_19 )
goto V_38;
V_19 = F_26 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 V_87 ( struct V_1 * V_2 , bool V_243 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 ;
T_3 V_20 ;
V_19 = V_18 -> V_22 . V_25 ( V_2 , V_244 , & V_20 ) ;
if ( V_19 )
goto V_38;
if ( V_243 ) {
V_20 |= V_245 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_244 ,
V_20 ) ;
if ( V_19 )
goto V_38;
V_19 = V_18 -> V_22 . V_25 ( V_2 , V_246 ,
& V_20 ) ;
V_20 &= ~ V_247 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_246 ,
V_20 ) ;
if ( V_19 )
goto V_38;
} else {
V_20 &= ~ V_245 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_244 ,
V_20 ) ;
if ( V_18 -> V_248 == V_249 ) {
V_19 = V_18 -> V_22 . V_25 ( V_2 ,
V_246 , & V_20 ) ;
if ( V_19 )
goto V_38;
V_20 |= V_247 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 ,
V_246 , V_20 ) ;
if ( V_19 )
goto V_38;
} else if ( V_18 -> V_248 == V_250 ) {
V_19 = V_18 -> V_22 . V_25 ( V_2 ,
V_246 , & V_20 ) ;
if ( V_19 )
goto V_38;
V_20 &= ~ V_247 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 ,
V_246 , V_20 ) ;
if ( V_19 )
goto V_38;
}
}
V_38:
return V_19 ;
}
static T_2 V_96 ( struct V_1 * V_2 , bool V_243 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_3 V_20 ;
V_20 = F_2 ( V_251 ) ;
if ( V_243 ) {
V_20 |= V_252 ;
V_20 &= ~ V_253 ;
} else {
V_20 &= ~ V_252 ;
if ( V_18 -> V_248 == V_249 )
V_20 |= V_253 ;
else if ( V_18 -> V_248 == V_250 )
V_20 &= ~ V_253 ; }
F_7 ( V_251 , V_20 ) ;
return 0 ;
}
static T_2 V_97 ( struct V_1 * V_2 , bool V_243 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_3 V_20 ;
V_20 = F_2 ( V_251 ) ;
if ( ! V_243 ) {
V_20 &= ~ V_254 ;
if ( V_18 -> V_248 == V_249 )
V_20 |= V_253 ;
else if ( V_18 -> V_248 == V_250 )
V_20 &= ~ V_253 ;
} else if ( ( V_18 -> V_255 == V_256 ) ||
( V_18 -> V_255 == V_257 ) ||
( V_18 -> V_255 == V_258 ) ) {
V_20 |= V_254 ;
V_20 &= ~ V_253 ;
}
F_7 ( V_251 , V_20 ) ;
return 0 ;
}
static T_2 V_120 ( struct V_1 * V_2 )
{
T_2 V_19 ;
V_19 = V_2 -> V_5 . V_22 . V_147 ( V_2 , V_259 ) ;
if ( V_19 )
goto V_38;
V_19 = F_27 ( V_2 ) ;
if ( V_19 )
V_2 -> V_5 . V_22 . V_149 ( V_2 , V_259 ) ;
V_38:
return V_19 ;
}
static void V_122 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
V_2 -> V_5 . V_22 . V_149 ( V_2 , V_259 ) ;
}
static T_2 V_151 ( struct V_1 * V_2 , T_3 V_223 )
{
T_1 V_260 ;
T_1 V_261 = V_223 ;
T_1 V_262 = V_223 << 16 ;
T_2 V_19 = 0 ;
T_2 V_263 = 0 , V_172 = 200 ;
while ( V_263 < V_172 ) {
if ( F_29 ( V_2 ) ) {
V_19 = - V_264 ;
goto V_38;
}
V_260 = F_2 ( V_265 ) ;
if ( ! ( V_260 & ( V_262 | V_261 ) ) )
break;
F_30 ( V_2 ) ;
F_31 ( 5 ) ;
V_263 ++ ;
}
if ( V_263 == V_172 ) {
F_17 ( L_7 ) ;
V_19 = - V_264 ;
goto V_38;
}
V_260 |= V_261 ;
F_7 ( V_265 , V_260 ) ;
F_30 ( V_2 ) ;
V_38:
return V_19 ;
}
static void V_152 ( struct V_1 * V_2 , T_3 V_223 )
{
T_1 V_260 ;
while ( F_29 ( V_2 ) != 0 )
;
V_260 = F_2 ( V_265 ) ;
V_260 &= ~ V_223 ;
F_7 ( V_265 , V_260 ) ;
F_30 ( V_2 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
T_2 V_172 = V_266 ;
T_1 V_223 = V_267 ;
if ( V_2 -> V_55 . V_56 == 1 )
V_223 = V_268 ;
else if ( V_2 -> V_55 . V_56 == V_227 )
V_223 = V_269 ;
else if ( V_2 -> V_55 . V_56 == V_229 )
V_223 = V_270 ;
while ( V_172 ) {
if ( F_2 ( V_271 ) & V_223 )
break;
F_33 ( 1000 , 2000 ) ;
V_172 -- ;
}
if ( ! V_172 )
F_17 ( L_8 ) ;
if ( ( ( F_2 ( V_104 ) & V_272 ) == 0 ) &&
( V_2 -> V_18 . type == V_82 ) )
F_34 ( V_2 ) ;
return 0 ;
}
static T_2 F_35 ( struct V_1 * V_2 , T_3 * V_273 ,
T_3 * V_274 )
{
T_2 V_19 ;
if ( V_2 -> V_18 . V_35 != V_36 )
V_19 = F_36 ( V_2 , V_273 ,
V_274 ) ;
else
V_19 = F_37 ( V_2 , V_273 ,
V_274 ) ;
return V_19 ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_273 , V_274 ;
if ( V_2 -> V_18 . V_35 != V_36 ) {
V_19 = F_36 ( V_2 , & V_273 ,
& V_274 ) ;
V_2 -> V_5 . V_275 = ! V_2 -> V_5 . V_276 ;
V_19 = F_38 ( V_2 ) ;
if ( V_19 )
F_17 ( L_9 ) ;
} else {
V_19 = F_39 ( V_2 ) ;
}
return V_19 ;
}
void F_40 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ( V_2 -> V_18 . V_35 != V_181 ) &&
! F_6 ( V_2 ) )
return;
V_3 = F_2 ( V_277 ) ;
V_3 |= V_278 ;
F_7 ( V_277 , V_3 ) ;
V_3 = F_2 ( V_42 ) ;
V_3 &= ~ V_173 ;
F_7 ( V_42 , V_3 ) ;
F_13 () ;
F_33 ( 1000 , 2000 ) ;
}
static T_2 F_36 ( struct V_1 * V_2 , T_3 * V_273 ,
T_3 * V_274 )
{
struct V_136 * V_5 = & V_2 -> V_5 ;
T_1 V_279 , V_280 ;
V_5 -> V_276 = false ;
* V_273 = 0 ;
* V_274 = 0 ;
V_279 = F_2 ( V_281 ) ;
if ( ( V_279 & V_282 ) && ( V_279 & V_283 ) ) {
V_5 -> V_276 = true ;
if ( V_279 & V_284 )
* V_273 = V_285 ;
else if ( V_279 & V_286 )
* V_273 = V_287 ;
else
* V_273 = V_288 ;
if ( V_279 & V_289 )
* V_274 = V_290 ;
else
* V_274 = V_291 ;
if ( V_5 -> type == V_12 ) {
V_280 = F_2 ( V_57 ) ;
if ( ( V_280 & V_292 ) &&
! ( V_280 & V_293 ) ) {
* V_273 = V_294 ;
* V_274 = V_290 ;
F_17 ( L_10 ) ;
F_17 ( L_11 ) ;
}
}
}
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_18 . V_35 != V_181 &&
F_6 ( V_2 ) )
return;
if ( ! F_42 ( V_2 ) ) {
V_3 = F_2 ( V_277 ) ;
V_3 &= ~ V_278 ;
F_7 ( V_277 , V_3 ) ;
V_3 = F_2 ( V_42 ) ;
V_3 |= V_173 ;
F_7 ( V_42 , V_3 ) ;
F_13 () ;
F_33 ( 1000 , 2000 ) ;
}
}
static T_2 V_146 ( struct V_1 * V_2 )
{
T_1 V_295 ;
T_2 V_19 ;
V_19 = F_43 ( V_2 ) ;
if ( V_19 )
F_17 ( L_12 ) ;
V_19 = F_44 ( V_2 ) ;
if ( V_19 )
F_17 ( L_13 ) ;
F_17 ( L_14 ) ;
F_7 ( V_296 , 0xffffffff ) ;
F_7 ( V_297 , 0 ) ;
F_7 ( V_298 , V_299 ) ;
F_13 () ;
F_33 ( 10000 , 20000 ) ;
V_295 = F_2 ( V_300 ) ;
F_17 ( L_15 ) ;
F_7 ( V_300 , V_295 | V_301 ) ;
V_19 = F_45 ( V_2 ) ;
if ( V_19 ) {
F_17 ( L_16 ) ;
}
if ( ( F_2 ( V_104 ) & V_272 ) == 0 )
F_46 ( V_2 ) ;
F_7 ( V_296 , 0xffffffff ) ;
F_2 ( V_302 ) ;
V_19 = F_47 ( V_2 ) ;
return V_19 ;
}
static T_2 F_48 ( struct V_1 * V_2 )
{
struct V_136 * V_5 = & V_2 -> V_5 ;
T_2 V_19 ;
T_3 V_263 , V_303 = V_5 -> V_139 ;
if ( ( V_2 -> V_5 . type >= V_13 ) &&
! ( F_49 ( V_2 ) ) ) {
V_19 = F_50 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_51 ( V_2 ) ;
if ( V_19 ) {
F_17 ( L_17 ) ;
}
F_17 ( L_18 ) ;
if ( ( V_2 -> V_5 . type == V_11 ) || ( V_2 -> V_5 . type == V_12 ) )
F_52 ( V_2 ) ;
else
F_53 ( V_2 ) ;
F_54 ( V_2 , V_303 ) ;
F_17 ( L_19 ) ;
for ( V_263 = 0 ; V_263 < V_5 -> V_138 ; V_263 ++ )
F_55 ( V_304 , V_263 , 0 ) ;
F_17 ( L_20 ) ;
for ( V_263 = 0 ; V_263 < V_5 -> V_305 ; V_263 ++ )
F_55 ( V_306 , V_263 , 0 ) ;
V_19 = F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_19 ;
}
static T_2 V_160 ( struct V_1 * V_2 )
{
T_1 V_295 ;
T_2 V_19 ;
T_1 V_307 ;
V_295 = F_2 ( V_300 ) ;
V_295 |= V_308 ;
V_295 &= ~ ( V_309 | V_310 ) ;
F_7 ( V_300 , V_295 ) ;
switch ( V_2 -> V_5 . type ) {
case V_10 :
case V_11 :
case V_13 :
case V_14 :
V_307 = F_2 ( V_251 ) ;
V_307 &= ~ V_311 ;
F_7 ( V_251 , V_307 ) ;
break;
default:
break;
}
V_19 = V_161 ( V_2 ) ;
if ( V_19 )
goto V_38;
if ( F_6 ( V_2 ) && ! V_2 -> V_18 . V_312 ) {
F_16 ( 300 ) ;
V_19 = V_2 -> V_18 . V_22 . V_43 ( V_2 ) ;
if ( V_19 ) {
F_17 ( L_21 ) ;
goto V_38;
}
}
switch ( V_2 -> V_18 . type ) {
case V_99 :
case V_65 :
switch ( V_2 -> V_18 . V_60 ) {
case V_62 :
case V_63 :
case V_61 :
case V_98 :
V_19 = F_58 ( V_2 ) ;
break;
default:
V_19 = F_59 ( V_2 ) ;
break;
}
break;
case V_82 :
V_19 = F_60 ( V_2 ) ;
break;
case V_92 :
V_19 = F_61 ( V_2 ) ;
break;
default:
V_19 = - V_100 ;
break;
}
if ( V_19 )
goto V_38;
V_19 = F_62 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 V_161 ( struct V_1 * V_2 )
{
T_1 V_34 , V_313 , V_3 , V_314 ;
bool V_315 ;
T_2 V_19 = 0 ;
T_3 V_20 ;
if ( ( V_2 -> V_18 . V_35 != V_181 ) &&
! F_6 ( V_2 ) )
return V_19 ;
F_7 ( V_316 , V_317 ) ;
V_34 = F_2 ( V_42 ) ;
V_34 &= ~ V_173 ;
V_34 |= V_45 ;
F_7 ( V_42 , V_34 ) ;
V_313 = F_2 ( V_300 ) ;
V_313 |= V_308 ;
if ( V_2 -> V_5 . type == V_6 || V_2 -> V_5 . type == V_7 ) {
V_313 |= V_318 | V_319 ;
V_3 = F_2 ( V_320 ) ;
V_3 |= V_321 ;
F_7 ( V_320 , V_3 ) ;
}
V_3 = F_2 ( V_322 ) ;
V_315 = V_2 -> V_5 . V_323 ;
switch ( V_34 & V_219 ) {
case V_221 :
V_315 = true ;
V_3 &= ~ ( V_324 ) ;
break;
case V_220 :
V_315 = false ;
default:
if ( V_2 -> V_5 . type == V_6 ||
V_2 -> V_5 . type == V_7 ) {
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_325 , 1 , & V_20 ) ;
if ( V_19 ) {
F_17 ( V_326 L_22 ) ;
return V_19 ;
}
if ( V_20 & V_327 )
V_315 = false ;
}
V_313 |= V_328 | V_309 |
V_329 | V_310 ;
V_3 |= V_330 | V_331 ;
break;
}
F_7 ( V_300 , V_313 ) ;
V_3 &= ~ ( V_332 | V_333 |
V_334 | V_335 ) ;
if ( V_315 ) {
V_3 |= V_332 |
V_336 ;
V_3 &= ~ V_337 ;
V_314 = F_2 ( V_338 ) ;
V_314 &= ~ ( V_339 | V_340 ) ;
switch ( V_2 -> V_341 . V_342 ) {
case V_343 :
case V_344 :
V_314 |= V_339 ;
V_314 |= V_340 ;
break;
case V_345 :
V_314 |= V_339 ;
break;
default:
break;
}
F_7 ( V_338 , V_314 ) ;
F_17 ( L_23 , V_3 ) ;
} else {
V_3 |= V_334 ;
V_3 |= V_337 ;
F_17 ( L_24 , V_3 ) ;
}
F_7 ( V_322 , V_3 ) ;
if ( ! V_315 && ! F_6 ( V_2 ) )
F_63 ( V_2 ) ;
return V_19 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_137 * V_30 = & V_2 -> V_30 . V_31 ;
return V_30 -> V_183 ;
}
static T_2 F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . type == V_6 ) {
F_17 ( L_25 ) ;
F_64 ( V_2 , V_316 , 0x00 , 0x0C ) ;
F_64 ( V_2 , V_316 , 0x01 , 0x78 ) ;
F_64 ( V_2 , V_316 , 0x1B , 0x23 ) ;
F_64 ( V_2 , V_316 , 0x23 , 0x15 ) ;
F_64 ( V_2 , V_346 , 0x14 , 0x00 ) ;
F_64 ( V_2 , V_346 , 0x10 , 0x00 ) ;
F_64 ( V_2 , V_347 , 0x00 , 0xEC ) ;
F_64 ( V_2 , V_347 , 0x61 , 0xDF ) ;
F_64 ( V_2 , V_347 , 0x34 , 0x05 ) ;
F_64 ( V_2 , V_347 , 0x2F , 0x81 ) ;
F_64 ( V_2 , V_348 , 0x02 , 0x47 ) ;
F_64 ( V_2 , V_348 , 0x14 , 0x00 ) ;
F_64 ( V_2 , V_348 , 0x10 , 0x00 ) ;
}
return 0 ;
}
static T_2 F_65 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
V_19 = F_47 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_66 ( V_2 ) ;
V_38:
return V_19 ;
}
void F_67 ( struct V_1 * V_2 )
{
if ( ! ( F_42 ( V_2 ) || F_68 ( V_2 ) ) )
F_69 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_70 ( V_2 ) ;
F_2 ( V_349 ) ;
F_2 ( V_350 ) ;
F_2 ( V_351 ) ;
F_2 ( V_352 ) ;
F_2 ( V_353 ) ;
F_2 ( V_354 ) ;
F_2 ( V_355 ) ;
F_2 ( V_356 ) ;
F_2 ( V_357 ) ;
F_2 ( V_358 ) ;
F_2 ( V_359 ) ;
F_2 ( V_360 ) ;
F_2 ( V_361 ) ;
F_2 ( V_362 ) ;
F_2 ( V_363 ) ;
F_2 ( V_364 ) ;
F_2 ( V_365 ) ;
F_2 ( V_366 ) ;
F_2 ( V_367 ) ;
F_2 ( V_368 ) ;
F_2 ( V_369 ) ;
F_2 ( V_370 ) ;
F_2 ( V_371 ) ;
F_2 ( V_372 ) ;
F_2 ( V_373 ) ;
F_2 ( V_374 ) ;
F_2 ( V_375 ) ;
F_2 ( V_376 ) ;
F_2 ( V_377 ) ;
F_2 ( V_378 ) ;
F_2 ( V_379 ) ;
F_2 ( V_380 ) ;
F_2 ( V_381 ) ;
F_2 ( V_382 ) ;
F_2 ( V_383 ) ;
F_2 ( V_384 ) ;
F_2 ( V_385 ) ;
F_2 ( V_386 ) ;
F_2 ( V_387 ) ;
F_2 ( V_388 ) ;
F_2 ( V_389 ) ;
if ( V_2 -> V_18 . V_35 == V_181 ||
F_6 ( V_2 ) )
F_2 ( V_390 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
T_1 V_391 , V_392 , V_393 [ 4 ] , V_394 , V_395 , V_396 ;
int V_263 , V_397 ;
if ( V_2 -> V_5 . type != V_6 ||
! ( F_2 ( V_398 ) & V_399 ) )
return;
for ( V_263 = 0 ; V_263 < 4 ; V_263 ++ ) {
V_393 [ V_263 ] = F_2 ( F_72 ( V_263 ) ) ;
F_7 ( F_72 ( V_263 ) ,
V_393 [ V_263 ] & ~ V_400 ) ;
}
for ( V_397 = 0 ; V_397 < 10 ; V_397 ++ ) {
F_33 ( 1000 , 2000 ) ;
V_396 = 0 ;
for ( V_263 = 0 ; V_263 < 4 ; V_263 ++ )
V_396 |= F_2 ( F_72 ( V_263 ) ) ;
if ( ! ( V_396 & V_400 ) )
break;
}
if ( V_397 == 10 )
F_17 ( L_26 ) ;
V_394 = F_2 ( V_401 ) ;
F_7 ( V_401 , V_394 & ~ V_402 ) ;
V_392 = F_2 ( V_403 ) ;
F_7 ( V_403 , 0 ) ;
V_391 = F_2 ( V_297 ) ;
V_395 = V_391 & ~ ( V_404 | V_405 ) ;
V_395 |= V_406 ;
F_7 ( V_297 , V_395 ) ;
F_7 ( V_297 , V_395 | V_404 ) ;
F_13 () ;
F_33 ( 2000 , 3000 ) ;
for ( V_263 = 0 ; V_263 < 4 ; V_263 ++ )
F_7 ( F_72 ( V_263 ) , V_393 [ V_263 ] ) ;
F_7 ( V_297 , V_391 ) ;
F_13 () ;
F_7 ( V_403 , V_392 ) ;
F_7 ( V_401 , V_394 ) ;
F_2 ( V_407 ) ;
F_2 ( V_408 ) ;
F_2 ( V_409 ) ;
}
static T_2 F_44 ( struct V_1 * V_2 )
{
T_1 V_410 = F_2 ( V_411 ) ;
T_2 V_19 = 0 ;
T_3 V_412 ;
if ( V_410 & V_413 )
goto V_38;
if ( ! ( V_410 & V_414 ) ) {
V_410 |= V_415 ;
goto V_38;
}
V_19 = F_73 ( V_2 , V_416 ,
& V_412 ) ;
if ( V_19 )
goto V_38;
V_412 |= V_417 ;
V_19 = F_74 ( V_2 , V_416 ,
& V_412 ) ;
V_38:
V_410 &= ~ V_418 ;
F_7 ( V_411 , V_410 ) ;
return V_19 ;
}
void F_75 ( struct V_1 * V_2 , bool V_419 , int V_420 )
{
T_1 V_421 , V_422 ;
switch ( V_2 -> V_5 . type ) {
case V_7 :
V_422 = V_423 ;
break;
case V_11 :
case V_12 :
V_422 = V_424 ;
break;
default:
return;
}
V_421 = F_2 ( V_422 ) ;
if ( V_419 ) {
V_421 |= ( V_425 |
V_426 ) ;
V_421 ^= ( 1 << V_420 | 1 << ( V_420 + V_427 ) ) ;
} else {
V_421 &= ~ ( V_425 |
V_426 ) ;
}
F_7 ( V_422 , V_421 ) ;
}
void F_76 ( struct V_1 * V_2 , bool V_419 )
{
T_1 V_428 ;
switch ( V_2 -> V_5 . type ) {
case V_7 :
V_428 = F_2 ( V_423 ) ;
if ( V_419 )
V_428 |= V_429 ;
else
V_428 &= ~ V_429 ;
F_7 ( V_423 , V_428 ) ;
break;
case V_12 :
case V_11 :
V_428 = F_2 ( V_424 ) ;
if ( V_419 )
V_428 |= V_429 ;
else
V_428 &= ~ V_429 ;
F_7 ( V_424 , V_428 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_1 * V_2 , bool V_419 )
{
T_1 V_430 = F_2 ( V_431 ) ;
if ( V_419 )
V_430 |= V_432 ;
else
V_430 &= ~ V_432 ;
F_7 ( V_431 , V_430 ) ;
}
static T_2 V_49 ( struct V_1 * V_2 , T_1 V_231 , T_3 * V_20 )
{
T_2 V_19 ;
V_19 = V_2 -> V_18 . V_22 . V_119 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_78 ( V_2 , V_231 , V_20 ) ;
V_2 -> V_18 . V_22 . V_121 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 V_50 ( struct V_1 * V_2 , T_1 V_231 , T_3 V_20 )
{
T_2 V_19 ;
V_19 = V_2 -> V_18 . V_22 . V_119 ( V_2 ) ;
if ( V_19 )
goto V_38;
V_19 = F_79 ( V_2 , V_231 , V_20 ) ;
V_2 -> V_18 . V_22 . V_121 ( V_2 ) ;
V_38:
return V_19 ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
T_1 V_433 ;
T_3 V_434 = 0 ;
if ( V_2 -> V_5 . type != V_10 )
goto V_38;
if ( ! F_6 ( V_2 ) )
goto V_38;
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_435 +
F_80 ( V_2 -> V_55 . V_56 ) , 1 ,
& V_434 ) ;
if ( V_19 ) {
F_17 ( L_27 ) ;
goto V_38;
}
V_433 = F_2 ( V_15 ) ;
if ( V_434 & V_436 )
V_433 |= V_16 ;
if ( V_434 & V_437 )
V_433 |= V_438 ;
F_7 ( V_15 , V_433 ) ;
V_38:
return V_19 ;
}
static T_2 V_145 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
T_3 V_439 = V_440 ;
T_1 V_295 ;
bool V_441 = V_2 -> V_30 . V_31 . V_441 ;
V_2 -> V_30 . V_31 . V_441 = false ;
if ( V_2 -> V_5 . type == V_10 )
V_441 = false ;
V_295 = F_2 ( V_300 ) ;
V_19 = F_43 ( V_2 ) ;
if ( V_19 )
F_17 ( L_12 ) ;
F_17 ( L_14 ) ;
F_7 ( V_296 , 0xffffffff ) ;
F_7 ( V_297 , 0 ) ;
F_7 ( V_298 , V_299 ) ;
F_13 () ;
F_33 ( 10000 , 11000 ) ;
if ( V_441 &&
V_2 -> V_5 . V_22 . V_147 ( V_2 , V_439 ) )
V_441 = false ;
if ( V_441 &&
! ( F_2 ( V_57 ) & V_442 ) )
V_295 |= V_443 ;
else
V_295 |= V_301 ;
F_7 ( V_300 , V_295 ) ;
F_13 () ;
if ( V_441 )
F_33 ( 5000 , 6000 ) ;
V_19 = F_45 ( V_2 ) ;
if ( V_19 ) {
F_17 ( L_16 ) ;
}
F_7 ( V_57 , V_442 ) ;
F_7 ( V_296 , 0xffffffff ) ;
F_2 ( V_302 ) ;
V_19 = F_8 ( V_2 ) ;
if ( V_19 )
F_17 ( L_28 ) ;
V_19 = F_47 ( V_2 ) ;
if ( V_441 )
V_2 -> V_5 . V_22 . V_149 ( V_2 , V_439 ) ;
return V_19 ;
}
T_3 F_81 ( T_1 V_20 )
{
T_3 V_19 = 0 ;
if ( V_20 < F_82 ( V_444 ) )
V_19 = V_444 [ V_20 ] ;
return V_19 ;
}
static T_2 F_83 ( struct V_1 * V_2 ,
T_3 V_231 )
{
T_2 V_19 = 0 ;
T_3 V_445 = 0 ;
T_3 V_263 , V_434 ;
for ( V_263 = V_231 ; V_263 < ( ( V_446 + V_231 ) + 1 ) ; V_263 ++ ) {
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_263 , 1 , & V_434 ) ;
if ( V_19 ) {
F_17 ( L_27 ) ;
goto V_38;
}
V_445 += V_434 ;
}
if ( V_445 != ( T_3 ) V_447 ) {
F_17 ( L_29 ) ;
V_19 = - V_448 ;
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 F_84 ( struct V_1 * V_2 , T_3 V_231 )
{
T_2 V_19 ;
T_3 V_445 = 0 ;
T_3 V_263 , V_434 ;
for ( V_263 = V_231 ; V_263 < ( V_446 + V_231 ) ; V_263 ++ ) {
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_263 , 1 , & V_434 ) ;
if ( V_19 ) {
F_17 ( L_30 ) ;
goto V_38;
}
V_445 += V_434 ;
}
V_445 = ( T_3 ) V_447 - V_445 ;
V_19 = V_2 -> V_102 . V_22 . V_123 ( V_2 , ( V_446 + V_231 ) , 1 ,
& V_445 ) ;
if ( V_19 )
F_17 ( L_31 ) ;
V_38:
return V_19 ;
}
static T_2 V_132 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
T_3 V_449 = 1 ;
T_3 V_450 , V_434 ;
T_3 V_451 ;
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_452 , 1 , & V_434 ) ;
if ( V_19 ) {
F_17 ( L_27 ) ;
goto V_38;
}
if ( V_434 & V_453 ) {
V_449 = 4 ;
}
for ( V_450 = 0 ; V_450 < V_449 ; V_450 ++ ) {
V_451 = F_80 ( V_450 ) ;
V_19 = F_83 ( V_2 ,
V_451 ) ;
if ( V_19 != 0 )
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 V_133 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_450 , V_434 ;
T_3 V_451 ;
V_19 = V_2 -> V_102 . V_22 . V_129 ( V_2 , V_452 , 1 , & V_434 ) ;
if ( V_19 ) {
F_17 ( L_32 ) ;
goto V_38;
}
if ( ( V_434 & V_453 ) == 0 ) {
V_434 = V_434 | V_453 ;
V_19 = V_2 -> V_102 . V_22 . V_123 ( V_2 , V_452 , 1 ,
& V_434 ) ;
if ( V_19 ) {
F_17 ( L_33 ) ;
goto V_38;
}
}
for ( V_450 = 0 ; V_450 < 4 ; V_450 ++ ) {
V_451 = F_80 ( V_450 ) ;
V_19 = F_84 ( V_2 , V_451 ) ;
if ( V_19 )
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 V_134 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
T_3 V_450 ;
T_3 V_451 ;
for ( V_450 = 0 ; V_450 < 4 ; V_450 ++ ) {
V_451 = F_80 ( V_450 ) ;
V_19 = F_83 ( V_2 ,
V_451 ) ;
if ( V_19 != 0 )
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 V_135 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
T_3 V_450 ;
T_3 V_451 ;
for ( V_450 = 0 ; V_450 < 4 ; V_450 ++ ) {
V_451 = F_80 ( V_450 ) ;
V_19 = F_84 ( V_2 , V_451 ) ;
if ( V_19 != 0 )
goto V_38;
}
V_38:
return V_19 ;
}
static T_2 F_85 ( struct V_1 * V_2 , T_3 V_454 ,
T_3 * V_20 , bool V_129 )
{
T_2 V_19 = 0 ;
V_19 = V_2 -> V_18 . V_22 . V_23 ( V_2 , V_455 , V_454 ) ;
if ( V_19 )
return V_19 ;
if ( V_129 )
V_19 = V_2 -> V_18 . V_22 . V_25 ( V_2 , V_456 , V_20 ) ;
else
V_19 = V_2 -> V_18 . V_22 . V_23 ( V_2 , V_456 , * V_20 ) ;
return V_19 ;
}
T_2 F_86 ( struct V_1 * V_2 , T_3 V_236 , T_3 * V_20 )
{
return F_85 ( V_2 , V_236 , V_20 , true ) ;
}
T_2 F_87 ( struct V_1 * V_2 , bool V_457 , bool V_458 )
{
T_1 V_459 , V_460 ;
if ( ( V_2 -> V_5 . type < V_11 ) ||
( V_2 -> V_18 . V_35 != V_36 ) )
goto V_38;
V_459 = F_2 ( V_461 ) ;
V_460 = F_2 ( V_462 ) ;
if ( ! ( V_2 -> V_30 . V_31 . V_157 ) ) {
T_1 V_463 = F_2 ( V_464 ) ;
if ( V_458 )
V_459 |= V_465 ;
else
V_459 &= ~ V_465 ;
if ( V_457 )
V_459 |= V_466 ;
else
V_459 &= ~ V_466 ;
V_460 |= ( V_467 | V_468 |
V_469 ) ;
if ( V_463 & V_470 )
F_17 ( L_34 ) ;
} else {
V_459 &= ~ ( V_466 |
V_465 ) ;
V_460 &= ~ ( V_467 |
V_468 |
V_469 ) ;
}
F_7 ( V_461 , V_459 ) ;
F_7 ( V_462 , V_460 ) ;
F_2 ( V_461 ) ;
F_2 ( V_462 ) ;
V_38:
return 0 ;
}
T_2 F_88 ( struct V_1 * V_2 , bool V_457 , bool V_458 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 = 0 ;
T_3 V_471 ;
if ( ( V_2 -> V_18 . V_35 != V_36 ) ||
( V_18 -> V_60 != V_61 ) )
goto V_38;
if ( ! V_2 -> V_30 . V_31 . V_157 ) {
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_472 , 18 ) ;
if ( V_19 )
goto V_38;
V_19 = V_18 -> V_22 . V_25 ( V_2 , V_473 ,
& V_471 ) ;
if ( V_19 )
goto V_38;
V_471 |= V_474 ;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_473 ,
V_471 ) ;
if ( V_19 )
goto V_38;
V_19 = V_18 -> V_22 . V_23 ( V_2 , V_472 , 0 ) ;
if ( V_19 )
goto V_38;
V_19 = F_89 ( V_2 , V_475 ,
V_476 ,
& V_471 ) ;
if ( V_19 )
goto V_38;
if ( V_458 )
V_471 |= V_477 ;
else
V_471 &= ~ V_477 ;
if ( V_457 )
V_471 |= V_478 ;
else
V_471 &= ~ V_478 ;
V_19 = F_90 ( V_2 , V_475 ,
V_476 ,
V_471 ) ;
} else {
V_19 = F_89 ( V_2 , V_475 ,
V_476 ,
& V_471 ) ;
if ( V_19 )
goto V_38;
V_471 &= ~ ( V_477 |
V_478 ) ;
V_19 = F_90 ( V_2 , V_475 ,
V_476 ,
V_471 ) ;
}
V_38:
return V_19 ;
}
T_2 F_91 ( struct V_1 * V_2 , bool * V_280 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_2 V_19 = 0 ;
T_3 V_471 ;
if ( ( V_2 -> V_18 . V_35 != V_36 ) ||
( V_18 -> V_60 != V_61 ) )
goto V_38;
V_19 = F_89 ( V_2 , V_479 ,
V_480 ,
& V_471 ) ;
if ( V_19 )
goto V_38;
* V_280 = V_471 & ( V_481 |
V_482 ) ? true : false ;
V_38:
return V_19 ;
}
static T_2 F_92 ( struct V_1 * V_2 )
{
T_3 V_483 ;
T_3 V_484 ;
T_3 V_485 ;
T_4 V_486 ;
T_4 V_487 ;
T_4 V_488 ;
T_4 V_263 ;
struct V_489 * V_20 = & V_2 -> V_5 . V_490 ;
if ( ( V_2 -> V_5 . type != V_11 ) || ( V_2 -> V_55 . V_56 != 0 ) )
return V_491 ;
V_20 -> V_492 [ 0 ] . V_493 = ( F_2 ( V_494 ) & 0xFF ) ;
V_2 -> V_102 . V_22 . V_129 ( V_2 , V_495 , 1 , & V_483 ) ;
if ( ( V_483 == 0x0000 ) || ( V_483 == 0xFFFF ) )
return 0 ;
V_2 -> V_102 . V_22 . V_129 ( V_2 , V_483 , 1 , & V_484 ) ;
if ( ( ( V_484 & V_496 ) >> V_497 )
!= V_498 )
return V_491 ;
V_486 = ( V_484 & V_499 ) ;
if ( V_486 > V_500 )
V_486 = V_500 ;
for ( V_263 = 1 ; V_263 < V_486 ; V_263 ++ ) {
V_2 -> V_102 . V_22 . V_129 ( V_2 , ( V_483 + V_263 ) , 1 , & V_485 ) ;
V_487 = ( ( V_485 & V_501 ) >>
V_502 ) ;
V_488 = ( ( V_485 & V_503 ) >>
V_504 ) ;
if ( V_488 != 0 )
V_2 -> V_18 . V_22 . V_505 ( V_2 ,
V_506 [ V_487 ] ,
V_507 ,
& V_20 -> V_492 [ V_263 ] . V_493 ) ;
}
return 0 ;
}
static T_2 F_93 ( struct V_1 * V_2 )
{
T_3 V_483 ;
T_3 V_484 ;
T_3 V_485 ;
T_4 V_508 ;
T_4 V_486 ;
T_4 V_487 ;
T_4 V_488 ;
T_4 V_509 ;
T_4 V_263 ;
struct V_489 * V_20 = & V_2 -> V_5 . V_490 ;
if ( ( V_2 -> V_5 . type != V_11 ) || ( V_2 -> V_55 . V_56 != 0 ) )
return V_491 ;
memset ( V_20 , 0 , sizeof( struct V_489 ) ) ;
V_20 -> V_492 [ 0 ] . V_510 = 0x1 ;
V_20 -> V_492 [ 0 ] . V_511 =
( F_2 ( V_512 ) & 0xFF ) ;
V_20 -> V_492 [ 0 ] . V_513 =
( F_2 ( V_514 ) & 0xFF ) ;
V_2 -> V_102 . V_22 . V_129 ( V_2 , V_495 , 1 , & V_483 ) ;
if ( ( V_483 == 0x0000 ) || ( V_483 == 0xFFFF ) )
return 0 ;
V_2 -> V_102 . V_22 . V_129 ( V_2 , V_483 , 1 , & V_484 ) ;
if ( ( ( V_484 & V_496 ) >> V_497 )
!= V_498 )
return V_491 ;
V_508 = ( ( V_484 & V_515 ) >>
V_516 ) ;
V_486 = ( V_484 & V_499 ) ;
for ( V_263 = 1 ; V_263 <= V_486 ; V_263 ++ ) {
V_2 -> V_102 . V_22 . V_129 ( V_2 , ( V_483 + V_263 ) , 1 , & V_485 ) ;
V_487 = ( ( V_485 & V_501 ) >>
V_502 ) ;
V_488 = ( ( V_485 & V_503 ) >>
V_504 ) ;
V_509 = V_485 & V_517 ;
V_2 -> V_18 . V_22 . V_518 ( V_2 ,
V_519 [ V_487 ] ,
V_507 ,
V_509 ) ;
if ( ( V_263 < V_500 ) && ( V_488 != 0 ) ) {
V_20 -> V_492 [ V_263 ] . V_510 = V_488 ;
V_20 -> V_492 [ V_263 ] . V_511 = V_509 ;
V_20 -> V_492 [ V_263 ] . V_513 = V_509 -
V_508 ;
}
}
return 0 ;
}
