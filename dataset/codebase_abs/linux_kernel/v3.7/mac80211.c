int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_7 -> V_10 = L_1 ;
V_7 -> V_11 = V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 |= V_25 ;
if ( V_2 -> V_26 -> V_27 & V_28 )
V_7 -> V_11 |= V_29 |
V_30 ;
#ifndef F_2
if ( V_4 -> V_11 & V_31 )
#endif
V_7 -> V_11 |= V_32 ;
V_7 -> V_33 = sizeof( struct V_34 ) ;
V_7 -> V_35 = sizeof( struct V_36 ) ;
F_3 (priv, ctx) {
V_7 -> V_37 -> V_38 |= V_9 -> V_38 ;
V_7 -> V_37 -> V_38 |= V_9 -> V_39 ;
}
F_4 ( V_40 != 2 ) ;
if ( V_7 -> V_37 -> V_38 & F_5 ( V_41 ) ) {
V_7 -> V_37 -> V_42 = V_43 ;
V_7 -> V_37 -> V_44 =
F_6 ( V_43 ) ;
} else if ( V_7 -> V_37 -> V_38 & F_5 ( V_45 ) ) {
V_7 -> V_37 -> V_42 =
V_46 ;
V_7 -> V_37 -> V_44 =
F_6 ( V_46 ) ;
}
V_7 -> V_37 -> V_47 = 500 ;
V_7 -> V_37 -> V_11 |= V_48 |
V_49 |
V_50 ;
#ifdef F_7
if ( V_2 -> V_51 -> V_52 [ V_53 ] . V_54 [ 0 ] . V_55 &&
V_2 -> V_56 -> V_57 -> V_58 &&
F_8 ( V_2 -> V_56 -> V_59 ) ) {
V_7 -> V_37 -> V_60 . V_11 = V_61 |
V_62 |
V_63 |
V_64 ;
if ( ! V_65 . V_66 )
V_7 -> V_37 -> V_60 . V_11 |=
V_67 |
V_68 ;
V_7 -> V_37 -> V_60 . V_69 = V_70 ;
V_7 -> V_37 -> V_60 . V_71 =
V_72 ;
V_7 -> V_37 -> V_60 . V_73 =
V_74 ;
}
#endif
if ( V_65 . V_75 )
V_7 -> V_37 -> V_11 |= V_76 ;
else
V_7 -> V_37 -> V_11 &= ~ V_76 ;
V_7 -> V_37 -> V_77 = V_78 ;
V_7 -> V_37 -> V_79 = V_4 -> V_80 - 24 - 34 ;
V_7 -> V_81 = V_82 ;
V_7 -> V_83 = V_84 ;
if ( V_2 -> V_26 -> V_85 [ V_86 ] . V_87 )
V_2 -> V_7 -> V_37 -> V_85 [ V_86 ] =
& V_2 -> V_26 -> V_85 [ V_86 ] ;
if ( V_2 -> V_26 -> V_85 [ V_88 ] . V_87 )
V_2 -> V_7 -> V_37 -> V_85 [ V_88 ] =
& V_2 -> V_26 -> V_85 [ V_88 ] ;
V_7 -> V_37 -> V_89 = V_2 -> V_56 -> V_90 ;
F_9 ( V_2 ) ;
V_5 = F_10 ( V_2 -> V_7 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_2 , V_5 ) ;
F_12 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_91 = 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_7 ) ;
V_2 -> V_91 = 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_5 ;
F_16 ( & V_2 -> V_92 ) ;
if ( F_17 ( V_93 , & V_2 -> V_94 ) ) {
F_18 ( V_2 , L_3 ) ;
return - V_95 ;
}
F_3 (priv, ctx) {
V_5 = F_19 ( V_2 , V_9 ) ;
if ( V_5 ) {
F_20 ( V_2 ) ;
return V_5 ;
}
}
V_5 = F_21 ( V_2 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_4 , V_5 ) ;
goto error;
}
V_5 = F_22 ( V_2 , V_96 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_5 , V_5 ) ;
goto error;
}
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_24 ( V_93 , & V_2 -> V_94 ) ;
F_25 ( V_2 ) ;
F_26 ( V_93 , & V_2 -> V_94 ) ;
F_11 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
V_5 = F_15 ( V_2 ) ;
F_31 ( & V_2 -> V_92 ) ;
if ( V_5 )
return V_5 ;
F_32 ( V_2 , L_8 ) ;
if ( F_33 ( ! F_17 ( V_97 , & V_2 -> V_94 ) ) )
V_5 = - V_95 ;
F_34 ( V_2 ) ;
V_2 -> V_98 = 1 ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( V_2 , L_7 ) ;
if ( ! V_2 -> V_98 )
return;
V_2 -> V_98 = 0 ;
F_30 ( & V_2 -> V_92 ) ;
F_25 ( V_2 ) ;
F_31 ( & V_2 -> V_92 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 -> V_99 ) ;
F_38 ( V_2 -> V_56 , false ) ;
F_29 ( V_2 , L_9 ) ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
if ( V_65 . V_66 )
return;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_104 [ V_105 ] . V_101 != V_101 )
goto V_106;
memcpy ( V_2 -> V_107 , V_103 -> V_107 , V_108 ) ;
memcpy ( V_2 -> V_109 , V_103 -> V_109 , V_110 ) ;
V_2 -> V_111 =
F_40 ( F_41 ( ( V_112 * ) & V_103 -> V_111 ) ) ;
V_2 -> V_113 = true ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_42 ( struct V_6 * V_7 ,
struct V_114 * V_60 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
int V_5 ;
if ( F_33 ( ! V_60 ) )
return - V_115 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( ! V_9 -> V_101 || V_9 -> V_101 -> type != V_116 ||
! F_43 ( V_9 ) ) {
V_5 = 1 ;
goto V_106;
}
V_5 = F_44 ( V_2 , V_60 ) ;
if ( V_5 )
goto error;
F_45 ( V_2 -> V_56 ) ;
goto V_106;
error:
V_2 -> V_60 = false ;
F_46 ( V_2 ) ;
F_47 ( V_2 -> V_7 ) ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
struct V_100 * V_101 ;
unsigned long V_11 ;
T_1 V_117 , V_94 = 0xffffffff ;
int V_5 = - V_95 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_49 ( V_2 -> V_56 , V_118 ,
V_119 ) ;
V_117 = V_2 -> V_120 . V_121 ;
if ( F_50 ( V_117 ) ) {
F_51 ( & V_2 -> V_56 -> V_122 , V_11 ) ;
V_5 = F_52 ( V_2 -> V_56 ) ;
if ( F_53 ( V_5 == 0 ) ) {
F_49 ( V_2 -> V_56 , V_123 , V_117 ) ;
V_94 = F_54 ( V_2 -> V_56 , V_124 ) ;
F_55 ( V_2 -> V_56 ) ;
}
F_56 ( & V_2 -> V_56 -> V_122 , V_11 ) ;
#ifdef F_57
if ( V_5 == 0 ) {
const struct V_125 * V_52 ;
V_52 = & ( V_2 -> V_51 -> V_52 [ V_53 ] ) ;
if ( ! V_2 -> V_126 ) {
V_2 -> V_126 =
F_58 ( V_52 -> V_54 [ V_127 ] . V_55 ,
V_128 ) ;
}
if ( V_2 -> V_126 )
F_59 (
V_2 -> V_56 , 0x800000 ,
V_2 -> V_126 ,
V_52 -> V_54 [ V_127 ] . V_55 / 4 ) ;
}
#endif
}
V_101 = V_9 -> V_101 ;
V_2 -> V_60 = false ;
F_46 ( V_2 ) ;
memset ( ( void * ) & V_9 -> V_129 , 0 , sizeof( V_9 -> V_129 ) ) ;
F_60 ( V_2 , V_9 ) ;
F_61 ( V_2 , V_9 ) ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
F_62 ( V_101 ) ;
return 1 ;
}
static void F_63 ( struct V_6 * V_7 , bool V_130 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_64 ( V_2 -> V_56 -> V_59 , V_130 ) ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_66 ( V_2 , L_10 , V_134 -> V_55 ,
F_67 ( V_7 , F_68 ( V_134 ) ) -> V_135 ) ;
if ( F_69 ( V_2 , V_132 -> V_136 , V_134 ) )
F_70 ( V_7 , V_134 ) ;
}
static void F_71 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_137 * V_138 ,
struct V_139 * V_136 ,
T_1 V_140 , T_2 * V_141 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_72 ( V_2 , V_101 , V_138 , V_136 , V_140 , V_141 ) ;
}
static int F_73 ( struct V_6 * V_7 , enum V_142 V_143 ,
struct V_100 * V_101 ,
struct V_139 * V_136 ,
struct V_137 * V_144 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_9 = V_145 -> V_9 ;
int V_5 ;
bool V_147 = false ;
F_29 ( V_2 , L_7 ) ;
if ( V_65 . V_66 ) {
F_29 ( V_2 , L_11 ) ;
return - V_148 ;
}
switch ( V_144 -> V_149 ) {
case V_150 :
V_144 -> V_11 |= V_151 ;
case V_152 :
V_144 -> V_11 |= V_153 ;
break;
default:
break;
}
if ( V_101 -> type == V_154 &&
! ( V_144 -> V_11 & V_155 ) ) {
V_144 -> V_156 = V_157 ;
return 0 ;
}
if ( V_143 == V_158 && V_144 -> V_156 == V_157 )
return 0 ;
F_30 ( & V_2 -> V_92 ) ;
F_74 ( V_2 , 100 ) ;
F_4 ( V_157 == V_159 ) ;
if ( ( V_144 -> V_149 == V_160 ||
V_144 -> V_149 == V_161 ) && ! V_136 ) {
if ( V_143 == V_162 )
V_147 = ! V_9 -> V_163 ;
else
V_147 =
V_144 -> V_156 == V_159 ;
}
switch ( V_143 ) {
case V_162 :
if ( V_147 ) {
V_5 = F_75 ( V_2 , V_145 -> V_9 , V_144 ) ;
break;
}
V_5 = F_76 ( V_2 , V_145 -> V_9 , V_144 , V_136 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_144 -> V_156 = V_157 ;
}
F_29 ( V_2 , L_12 ) ;
break;
case V_158 :
if ( V_147 )
V_5 = F_77 ( V_2 , V_9 , V_144 ) ;
else
V_5 = F_78 ( V_2 , V_9 , V_144 , V_136 ) ;
F_29 ( V_2 , L_13 ) ;
break;
default:
V_5 = - V_115 ;
}
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_164 V_165 ,
struct V_139 * V_136 , T_2 V_166 , T_2 * V_167 ,
T_3 V_168 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 = - V_115 ;
struct V_34 * V_169 = ( void * ) V_136 -> V_146 ;
F_80 ( V_2 , L_14 ,
V_136 -> V_170 , V_166 ) ;
if ( ! ( V_2 -> V_26 -> V_27 & V_28 ) )
return - V_171 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
switch ( V_165 ) {
case V_172 :
if ( V_65 . V_173 & V_174 )
break;
F_80 ( V_2 , L_15 ) ;
V_5 = F_81 ( V_2 , V_136 , V_166 , * V_167 ) ;
break;
case V_175 :
F_80 ( V_2 , L_16 ) ;
V_5 = F_82 ( V_2 , V_136 , V_166 ) ;
break;
case V_176 :
if ( ! V_2 -> V_56 -> V_57 -> V_177 )
break;
if ( V_65 . V_173 & V_178 )
break;
F_80 ( V_2 , L_17 ) ;
V_5 = F_83 ( V_2 , V_101 , V_136 , V_166 , V_167 ) ;
break;
case V_179 :
F_80 ( V_2 , L_18 ) ;
V_5 = F_84 ( V_2 , V_101 , V_136 , V_166 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_180 > 0 ) ) {
V_2 -> V_180 -- ;
F_80 ( V_2 , L_19 ,
V_2 -> V_180 ) ;
}
if ( ! V_2 -> V_180 &&
V_2 -> V_181 . V_182 ) {
V_169 -> V_183 . V_184 . V_185 . V_11 &=
~ V_186 ;
F_85 ( V_2 , F_86 ( V_101 ) ,
& V_169 -> V_183 . V_184 , V_187 , false ) ;
}
break;
case V_188 :
V_5 = F_87 ( V_2 , V_101 , V_136 , V_166 , V_168 ) ;
break;
}
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_169 = ( void * ) V_136 -> V_146 ;
struct V_36 * V_145 = ( void * ) V_101 -> V_146 ;
bool V_189 = V_101 -> type == V_116 ;
int V_5 ;
T_3 V_190 ;
F_32 ( V_2 , L_20 ,
V_136 -> V_170 ) ;
V_169 -> V_190 = V_191 ;
F_89 ( & V_169 -> V_192 , 0 ) ;
if ( V_101 -> type == V_45 )
V_169 -> V_193 = true ;
V_5 = F_90 ( V_2 , V_145 -> V_9 , V_136 -> V_170 ,
V_189 , V_136 , & V_190 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_21 ,
V_136 -> V_170 , V_5 ) ;
return V_5 ;
}
V_169 -> V_190 = V_190 ;
return 0 ;
}
static int F_91 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_169 = ( void * ) V_136 -> V_146 ;
int V_5 ;
F_32 ( V_2 , L_22 , V_136 -> V_170 ) ;
if ( V_101 -> type == V_116 ) {
V_5 = 0 ;
F_92 ( V_2 , V_169 -> V_190 , V_136 -> V_170 ) ;
} else {
V_5 = F_93 ( V_2 , V_169 -> V_190 , V_136 -> V_170 ) ;
if ( V_5 )
F_94 ( V_2 ,
L_23 , V_136 -> V_170 ) ;
}
return V_5 ;
}
static int F_95 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 ,
enum V_194 V_195 ,
enum V_194 V_196 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_145 = ( void * ) V_101 -> V_146 ;
enum {
V_197 , V_198 , REMOVE , V_199 , V_200 ,
} V_201 = V_197 ;
int V_5 ;
F_29 ( V_2 , L_24 ,
V_136 -> V_170 , V_195 , V_196 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_101 -> type == V_116 ) {
if ( V_195 == V_202 &&
V_196 == V_203 )
V_201 = V_198 ;
else if ( V_195 == V_203 &&
V_196 == V_202 )
V_201 = REMOVE ;
else if ( V_195 == V_204 &&
V_196 == V_205 )
V_201 = V_199 ;
} else {
if ( V_195 == V_204 &&
V_196 == V_205 )
V_201 = V_200 ;
else if ( V_195 == V_205 &&
V_196 == V_204 )
V_201 = REMOVE ;
}
switch ( V_201 ) {
case V_198 :
V_5 = F_88 ( V_7 , V_101 , V_136 ) ;
if ( V_5 )
break;
F_96 ( & V_2 -> V_206 ) ;
V_2 -> V_207 [ F_97 ( V_136 ) ] . V_208 &=
~ V_209 ;
F_98 ( & V_2 -> V_206 ) ;
break;
case REMOVE :
V_5 = F_91 ( V_7 , V_101 , V_136 ) ;
break;
case V_200 :
V_5 = F_88 ( V_7 , V_101 , V_136 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_136 -> V_170 ) ;
F_99 ( V_2 , V_136 , F_97 ( V_136 ) ) ;
V_5 = 0 ;
break;
case V_199 :
V_5 = F_100 ( V_2 , V_145 -> V_9 , V_136 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_136 -> V_170 ) ;
F_99 ( V_2 , V_136 , F_97 ( V_136 ) ) ;
V_5 = 0 ;
break;
default:
V_5 = 0 ;
break;
}
if ( F_101 ( V_2 ) )
V_5 = 0 ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_102 ( struct V_6 * V_7 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_212 * V_213 = & V_7 -> V_213 ;
struct V_214 * V_215 = V_211 -> V_215 ;
struct V_216 * V_217 = & V_2 -> V_218 ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
T_2 V_219 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_101 ( V_2 ) )
goto V_106;
if ( F_17 ( V_93 , & V_2 -> V_94 ) ||
F_17 ( V_220 , & V_2 -> V_94 ) ||
F_17 ( V_221 , & V_2 -> V_94 ) )
goto V_106;
if ( ! F_43 ( V_9 ) )
goto V_106;
if ( ! V_2 -> V_222 -> V_223 )
goto V_106;
V_219 = V_215 -> V_224 ;
if ( F_103 ( V_9 -> V_129 . V_215 ) == V_219 )
goto V_106;
V_2 -> V_218 . V_225 = V_213 -> V_226 ;
V_9 -> V_227 . V_130 = F_104 ( V_213 ) ;
if ( V_9 -> V_227 . V_130 )
F_105 ( V_213 , V_9 ) ;
else
V_9 -> V_227 . V_228 = false ;
if ( ( F_103 ( V_9 -> V_229 . V_215 ) != V_219 ) )
V_9 -> V_229 . V_11 = 0 ;
F_106 ( V_2 , V_215 , V_9 ) ;
F_107 ( V_2 , V_217 ) ;
F_108 ( V_2 , V_9 , V_215 -> V_230 , V_9 -> V_101 ) ;
F_24 ( V_221 , & V_2 -> V_94 ) ;
V_2 -> V_231 = F_109 ( V_219 ) ;
if ( V_2 -> V_222 -> V_223 ( V_2 , V_211 ) ) {
F_26 ( V_221 , & V_2 -> V_94 ) ;
V_2 -> V_231 = 0 ;
F_110 ( V_9 -> V_101 , false ) ;
}
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
void F_111 ( struct V_1 * V_2 , bool V_232 )
{
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
if ( F_17 ( V_93 , & V_2 -> V_94 ) )
return;
if ( F_112 ( V_221 , & V_2 -> V_94 ) )
F_110 ( V_9 -> V_101 , V_232 ) ;
}
static void F_113 ( struct V_6 * V_7 ,
unsigned int V_233 ,
unsigned int * V_234 ,
T_4 V_235 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
T_5 V_236 = 0 , V_237 = 0 ;
struct V_8 * V_9 ;
#define F_114 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_29 ( V_2 , L_26 ,
V_233 , * V_234 ) ;
F_114 ( V_238 | V_239 , V_240 ) ;
F_114 ( V_241 , V_242 | V_240 ) ;
F_114 ( V_243 , V_244 ) ;
#undef F_114
F_30 ( & V_2 -> V_92 ) ;
F_3 (priv, ctx) {
V_9 -> V_229 . V_245 &= ~ V_237 ;
V_9 -> V_229 . V_245 |= V_236 ;
}
F_31 ( & V_2 -> V_92 ) ;
* V_234 &= V_238 | V_246 | V_239 |
V_243 | V_241 ;
}
static void F_115 ( struct V_6 * V_7 , bool V_247 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_7 ) ;
if ( F_17 ( V_93 , & V_2 -> V_94 ) ) {
F_66 ( V_2 , L_27 ) ;
goto V_248;
}
if ( F_101 ( V_2 ) ) {
F_66 ( V_2 , L_28 ) ;
goto V_248;
}
if ( V_247 ) {
F_29 ( V_2 , L_29 ) ;
if ( F_116 ( V_2 , V_249 ) ) {
F_11 ( V_2 , L_30 ) ;
goto V_248;
}
}
F_29 ( V_2 , L_31 ) ;
F_117 ( V_2 -> V_56 ) ;
V_248:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_118 ( struct V_6 * V_7 ,
struct V_214 * V_215 ,
enum V_250 V_251 ,
int V_252 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_253 ] ;
int V_254 = 0 ;
if ( ! ( V_2 -> V_255 & F_5 ( V_253 ) ) )
return - V_148 ;
if ( ! ( V_9 -> V_38 & F_5 ( V_41 ) ) )
return - V_148 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_17 ( V_256 , & V_2 -> V_94 ) ) {
if ( F_119 ( V_2 -> V_257 != V_258 ) ) {
V_254 = - V_259 ;
goto V_106;
}
F_74 ( V_2 , 100 ) ;
if ( F_17 ( V_256 , & V_2 -> V_94 ) ) {
V_254 = - V_259 ;
goto V_106;
}
}
V_2 -> V_260 = V_215 ;
V_2 -> V_261 = V_251 ;
V_2 -> V_262 = F_120 ( 1000 * V_252 , 1024 ) ;
V_2 -> V_263 = false ;
F_121 ( & V_2 -> V_264 ) ;
if ( ! V_9 -> V_265 ) {
static const struct V_266 V_267 = {
. V_268 = {
. V_269 [ 0 ] = {
. V_270 = F_109 ( 3 ) ,
. V_271 = F_109 ( 7 ) ,
. V_272 = 2 ,
. V_273 = F_109 ( 1504 ) ,
} ,
. V_269 [ 1 ] = {
. V_270 = F_109 ( 7 ) ,
. V_271 = F_109 ( 15 ) ,
. V_272 = 2 ,
. V_273 = F_109 ( 3008 ) ,
} ,
. V_269 [ 2 ] = {
. V_270 = F_109 ( 15 ) ,
. V_271 = F_109 ( 1023 ) ,
. V_272 = 3 ,
} ,
. V_269 [ 3 ] = {
. V_270 = F_109 ( 15 ) ,
. V_271 = F_109 ( 1023 ) ,
. V_272 = 7 ,
} ,
} ,
} ;
V_9 -> V_265 = true ;
V_9 -> V_274 = V_267 ;
V_9 -> V_229 . V_275 = V_276 ;
memcpy ( V_9 -> V_229 . V_277 ,
V_2 -> V_104 [ V_105 ] . V_229 . V_277 ,
V_278 ) ;
memcpy ( V_9 -> V_229 . V_279 ,
V_2 -> V_104 [ V_105 ] . V_229 . V_277 ,
V_278 ) ;
V_254 = F_122 ( V_2 , V_9 ) ;
if ( V_254 )
goto V_106;
V_9 -> V_229 . V_245 |= V_280 |
V_240 |
V_242 ;
V_254 = F_122 ( V_2 , V_9 ) ;
if ( V_254 ) {
F_123 ( V_2 ) ;
goto V_106;
}
V_2 -> V_281 = true ;
}
V_254 = F_124 ( V_2 , V_9 -> V_101 , V_282 , V_215 -> V_230 ) ;
if ( V_254 )
F_123 ( V_2 ) ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_254 ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
if ( ! ( V_2 -> V_255 & F_5 ( V_253 ) ) )
return - V_148 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_74 ( V_2 , V_2 -> V_262 ) ;
F_123 ( V_2 ) ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_126 ( struct V_6 * V_7 ,
enum V_283 V_284 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_285 -> V_286 &&
V_2 -> V_285 -> V_286 -> V_287 ) {
if ( V_284 == V_288 )
V_2 -> V_289 = true ;
else if ( V_284 == V_290 )
V_2 -> V_289 = false ;
F_127 ( V_2 ) ;
} else {
F_29 ( V_2 , L_32
L_33 ) ;
}
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_128 ( struct V_6 * V_7 ,
struct V_139 * V_136 , bool V_291 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_129 ( V_2 -> V_99 , & V_2 -> V_292 ) ;
return 0 ;
}
static int F_130 ( struct V_6 * V_7 ,
struct V_100 * V_101 , T_2 V_293 ,
const struct V_294 * V_295 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_9 = V_145 -> V_9 ;
int V_296 ;
if ( F_33 ( ! V_9 ) )
return - V_115 ;
F_29 ( V_2 , L_7 ) ;
if ( ! F_131 ( V_2 ) ) {
F_29 ( V_2 , L_34 ) ;
return - V_95 ;
}
if ( V_293 >= V_297 ) {
F_29 ( V_2 , L_35 , V_293 ) ;
return 0 ;
}
V_296 = V_297 - 1 - V_293 ;
F_30 ( & V_2 -> V_92 ) ;
V_9 -> V_274 . V_268 . V_269 [ V_296 ] . V_270 =
F_109 ( V_295 -> V_270 ) ;
V_9 -> V_274 . V_268 . V_269 [ V_296 ] . V_271 =
F_109 ( V_295 -> V_271 ) ;
V_9 -> V_274 . V_268 . V_269 [ V_296 ] . V_272 = V_295 -> V_298 ;
V_9 -> V_274 . V_268 . V_269 [ V_296 ] . V_273 =
F_109 ( ( V_295 -> V_299 * 32 ) ) ;
V_9 -> V_274 . V_268 . V_269 [ V_296 ] . V_300 = 0 ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_132 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
return V_2 -> V_301 == V_302 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_60 ( V_2 , V_9 ) ;
F_61 ( V_2 , V_9 ) ;
return F_122 ( V_2 , V_9 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
int V_254 , V_269 ;
F_16 ( & V_2 -> V_92 ) ;
V_2 -> V_303 = V_101 -> type ;
V_9 -> V_265 = true ;
V_254 = F_133 ( V_2 , V_9 ) ;
if ( V_254 ) {
if ( ! V_9 -> V_304 )
V_9 -> V_265 = false ;
return V_254 ;
}
if ( V_2 -> V_285 -> V_286 && V_2 -> V_285 -> V_286 -> V_287 &&
V_101 -> type == V_154 ) {
V_2 -> V_305 = V_306 ;
}
for ( V_269 = 0 ; V_269 < V_307 ; V_269 ++ )
V_101 -> V_308 [ V_269 ] = V_9 -> V_309 [ V_269 ] ;
if ( V_101 -> type == V_45 )
V_101 -> V_310 = V_9 -> V_311 ;
else
V_101 -> V_310 = V_312 ;
return 0 ;
}
static int F_135 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_313 , * V_9 = NULL ;
int V_254 ;
enum V_314 V_315 = F_136 ( V_101 ) ;
bool V_316 = false ;
F_29 ( V_2 , L_36 ,
V_315 , V_101 -> V_170 ) ;
F_137 ( & V_2 -> V_264 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_123 ( V_2 ) ;
if ( ! F_131 ( V_2 ) ) {
F_18 ( V_2 , L_37 ) ;
V_254 = - V_115 ;
goto V_106;
}
F_3 (priv, tmp) {
T_1 V_317 =
V_313 -> V_38 | V_313 -> V_39 ;
if ( V_313 -> V_101 ) {
if ( V_313 -> V_101 == V_101 ) {
V_316 = true ;
V_9 = V_313 ;
break;
}
if ( V_313 -> V_39 &
F_5 ( V_313 -> V_101 -> type ) ) {
V_254 = - V_115 ;
goto V_106;
}
continue;
}
if ( ! ( V_317 & F_5 ( V_315 ) ) )
continue;
V_9 = V_313 ;
break;
}
if ( ! V_9 ) {
V_254 = - V_148 ;
goto V_106;
}
V_145 -> V_9 = V_9 ;
V_9 -> V_101 = V_101 ;
if ( V_101 -> type == V_318 )
V_2 -> V_7 -> V_11 |= V_319 ;
else
V_2 -> V_7 -> V_11 &= ~ V_319 ;
V_254 = F_134 ( V_2 , V_9 ) ;
if ( ! V_254 || V_316 )
goto V_106;
V_9 -> V_101 = NULL ;
V_2 -> V_303 = V_116 ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_254 ;
}
static void F_138 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
bool V_320 )
{
struct V_8 * V_9 = F_86 ( V_101 ) ;
F_16 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_321 == V_101 ) {
F_74 ( V_2 , 200 ) ;
F_139 ( V_2 ) ;
}
if ( ! V_320 ) {
F_133 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_304 )
V_9 -> V_265 = false ;
}
if ( V_101 -> type == V_154 )
V_2 -> V_305 = V_2 -> V_322 ;
}
static void F_140 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = F_86 ( V_101 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_33 ( V_9 -> V_101 != V_101 ) ) {
struct V_8 * V_313 ;
F_11 ( V_2 , L_38 , V_9 -> V_101 , V_101 ) ;
F_3 (priv, tmp)
F_11 ( V_2 , L_39 ,
V_313 -> V_323 , V_313 , V_313 -> V_101 ) ;
}
V_9 -> V_101 = NULL ;
F_138 ( V_2 , V_101 , false ) ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_141 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_314 V_324 , bool V_325 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 , * V_313 ;
enum V_314 V_326 = V_324 ;
T_1 V_38 ;
int V_254 ;
F_29 ( V_2 , L_7 ) ;
V_324 = F_142 ( V_324 , V_325 ) ;
F_30 ( & V_2 -> V_92 ) ;
V_9 = F_86 ( V_101 ) ;
if ( V_9 -> V_323 != V_105 ) {
V_254 = - V_259 ;
goto V_106;
}
if ( ! V_9 -> V_101 || ! F_131 ( V_2 ) ) {
V_254 = - V_259 ;
goto V_106;
}
V_38 = V_9 -> V_38 | V_9 -> V_39 ;
if ( ! ( V_38 & F_5 ( V_324 ) ) ) {
V_254 = - V_259 ;
goto V_106;
}
if ( V_9 -> V_39 & F_5 ( V_324 ) ) {
F_3 (priv, tmp) {
if ( V_9 == V_313 )
continue;
if ( ! V_313 -> V_265 )
continue;
V_254 = - V_259 ;
goto V_106;
}
}
F_138 ( V_2 , V_101 , true ) ;
V_101 -> type = V_326 ;
V_101 -> V_327 = V_325 ;
V_254 = F_134 ( V_2 , V_9 ) ;
F_33 ( V_254 ) ;
V_254 = 0 ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_254 ;
}
static int F_143 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_328 * V_329 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 ;
F_29 ( V_2 , L_7 ) ;
if ( V_329 -> V_87 == 0 )
return - V_115 ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_257 != V_330 ) {
F_144 ( V_2 ,
L_40 ) ;
V_2 -> V_331 = V_329 ;
V_2 -> V_321 = V_101 ;
V_5 = 0 ;
} else {
V_2 -> V_331 = V_329 ;
V_2 -> V_321 = V_101 ;
V_5 = F_124 ( V_2 , V_101 , V_330 ,
V_329 -> V_332 [ 0 ] -> V_230 ) ;
if ( V_5 ) {
V_2 -> V_331 = NULL ;
V_2 -> V_321 = NULL ;
}
}
F_29 ( V_2 , L_9 ) ;
F_31 ( & V_2 -> V_92 ) ;
return V_5 ;
}
static void F_145 ( struct V_1 * V_2 , int V_190 )
{
struct V_333 V_143 = {
. V_334 = V_335 ,
. V_336 = V_337 ,
. V_136 . V_190 = V_190 ,
} ;
F_146 ( V_2 , & V_143 , V_187 ) ;
}
static void F_147 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_338 V_143 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_169 = ( void * ) V_136 -> V_146 ;
int V_190 ;
F_29 ( V_2 , L_7 ) ;
switch ( V_143 ) {
case V_339 :
F_33 ( ! V_169 -> V_193 ) ;
V_169 -> V_340 = true ;
if ( F_148 ( & V_169 -> V_192 ) > 0 )
F_149 ( V_7 , V_136 , true ) ;
break;
case V_341 :
F_33 ( ! V_169 -> V_193 ) ;
if ( ! V_169 -> V_340 )
break;
V_169 -> V_340 = false ;
V_190 = F_97 ( V_136 ) ;
if ( V_190 != V_191 )
F_145 ( V_2 , V_190 ) ;
break;
default:
break;
}
F_29 ( V_2 , L_9 ) ;
}
struct V_6 * F_150 ( void )
{
struct V_1 * V_2 ;
struct V_342 * V_343 ;
struct V_6 * V_7 ;
V_7 = F_151 ( sizeof( struct V_1 ) +
sizeof( struct V_342 ) , & V_344 ) ;
if ( ! V_7 )
goto V_106;
V_343 = V_7 -> V_2 ;
V_2 = F_152 ( V_343 ) ;
V_2 -> V_7 = V_7 ;
V_106:
return V_7 ;
}
