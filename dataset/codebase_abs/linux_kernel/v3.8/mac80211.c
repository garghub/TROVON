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
if ( V_2 -> V_26 -> V_27 )
V_7 -> V_11 |= V_28 |
V_29 ;
if ( V_2 -> V_30 -> V_31 . V_11 & V_32 &&
! V_33 . V_34 )
V_7 -> V_11 |= V_35 ;
V_7 -> V_36 = sizeof( struct V_37 ) ;
V_7 -> V_38 = sizeof( struct V_39 ) ;
F_2 (priv, ctx) {
V_7 -> V_40 -> V_41 |= V_9 -> V_41 ;
V_7 -> V_40 -> V_41 |= V_9 -> V_42 ;
}
F_3 ( V_43 != 2 ) ;
if ( V_7 -> V_40 -> V_41 & F_4 ( V_44 ) ) {
V_7 -> V_40 -> V_45 = V_46 ;
V_7 -> V_40 -> V_47 =
F_5 ( V_46 ) ;
} else if ( V_7 -> V_40 -> V_41 & F_4 ( V_48 ) ) {
V_7 -> V_40 -> V_45 =
V_49 ;
V_7 -> V_40 -> V_47 =
F_5 ( V_49 ) ;
}
V_7 -> V_40 -> V_50 = 500 ;
V_7 -> V_40 -> V_11 |= V_51 |
V_52 |
V_53 ;
#ifdef F_6
if ( V_2 -> V_30 -> V_54 [ V_55 ] . V_56 [ 0 ] . V_57 &&
V_2 -> V_58 -> V_59 -> V_60 &&
F_7 ( V_2 -> V_58 -> V_61 ) ) {
V_7 -> V_40 -> V_62 . V_11 = V_63 |
V_64 |
V_65 |
V_66 ;
if ( ! V_33 . V_34 )
V_7 -> V_40 -> V_62 . V_11 |=
V_67 |
V_68 ;
V_7 -> V_40 -> V_62 . V_69 = V_70 ;
V_7 -> V_40 -> V_62 . V_71 =
V_72 ;
V_7 -> V_40 -> V_62 . V_73 =
V_74 ;
}
#endif
if ( V_33 . V_75 )
V_7 -> V_40 -> V_11 |= V_76 ;
else
V_7 -> V_40 -> V_11 &= ~ V_76 ;
V_7 -> V_40 -> V_77 = V_78 ;
V_7 -> V_40 -> V_79 = V_4 -> V_80 - 24 - 34 ;
V_7 -> V_81 = V_82 ;
V_7 -> V_83 = V_84 ;
if ( V_2 -> V_26 -> V_85 [ V_86 ] . V_87 )
V_2 -> V_7 -> V_40 -> V_85 [ V_86 ] =
& V_2 -> V_26 -> V_85 [ V_86 ] ;
if ( V_2 -> V_26 -> V_85 [ V_88 ] . V_87 )
V_2 -> V_7 -> V_40 -> V_85 [ V_88 ] =
& V_2 -> V_26 -> V_85 [ V_88 ] ;
V_7 -> V_40 -> V_89 = V_2 -> V_58 -> V_90 ;
F_8 ( V_2 ) ;
V_5 = F_9 ( V_2 -> V_7 ) ;
if ( V_5 ) {
F_10 ( V_2 , L_2 , V_5 ) ;
F_11 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_91 = 1 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return;
F_11 ( V_2 ) ;
F_13 ( V_2 -> V_7 ) ;
V_2 -> V_91 = 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_5 ;
F_15 ( & V_2 -> V_92 ) ;
if ( F_16 ( V_93 , & V_2 -> V_94 ) ) {
F_17 ( V_2 , L_3 ) ;
return - V_95 ;
}
F_2 (priv, ctx) {
V_5 = F_18 ( V_2 , V_9 ) ;
if ( V_5 ) {
F_19 ( V_2 ) ;
return V_5 ;
}
}
V_5 = F_20 ( V_2 ) ;
if ( V_5 ) {
F_10 ( V_2 , L_4 , V_5 ) ;
goto error;
}
V_5 = F_21 ( V_2 , V_96 ) ;
if ( V_5 ) {
F_10 ( V_2 , L_5 , V_5 ) ;
goto error;
}
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_23 ( V_93 , & V_2 -> V_94 ) ;
F_24 ( V_2 ) ;
F_25 ( V_93 , & V_2 -> V_94 ) ;
F_10 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
int V_5 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
V_5 = F_14 ( V_2 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_5 )
return V_5 ;
F_31 ( V_2 , L_8 ) ;
if ( F_32 ( ! F_16 ( V_97 , & V_2 -> V_94 ) ) )
V_5 = - V_95 ;
F_33 ( V_2 ) ;
V_2 -> V_98 = 1 ;
F_28 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_28 ( V_2 , L_7 ) ;
if ( ! V_2 -> V_98 )
return;
V_2 -> V_98 = 0 ;
F_29 ( & V_2 -> V_92 ) ;
F_24 ( V_2 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_99 ) ;
F_37 ( V_2 -> V_58 , false ) ;
F_28 ( V_2 , L_9 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
if ( V_33 . V_34 )
return;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_104 [ V_105 ] . V_101 != V_101 )
goto V_106;
memcpy ( V_2 -> V_107 , V_103 -> V_107 , V_108 ) ;
memcpy ( V_2 -> V_109 , V_103 -> V_109 , V_110 ) ;
V_2 -> V_111 =
F_39 ( F_40 ( ( V_112 * ) & V_103 -> V_111 ) ) ;
V_2 -> V_113 = true ;
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
}
static int F_41 ( struct V_6 * V_7 ,
struct V_114 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
int V_5 ;
if ( F_32 ( ! V_62 ) )
return - V_115 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( ! V_9 -> V_101 || V_9 -> V_101 -> type != V_116 ||
! F_42 ( V_9 ) ) {
V_5 = 1 ;
goto V_106;
}
V_5 = F_43 ( V_2 , V_62 ) ;
if ( V_5 )
goto error;
F_44 ( V_2 -> V_58 ) ;
goto V_106;
error:
V_2 -> V_62 = false ;
F_45 ( V_2 ) ;
F_46 ( V_2 -> V_7 ) ;
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
struct V_100 * V_101 ;
unsigned long V_11 ;
T_1 V_117 , V_94 = 0xffffffff ;
int V_5 = - V_95 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
F_48 ( V_2 -> V_58 , V_118 ,
V_119 ) ;
V_117 = V_2 -> V_120 . V_121 ;
if ( F_49 ( V_117 ) ) {
F_50 ( & V_2 -> V_58 -> V_122 , V_11 ) ;
V_5 = F_51 ( V_2 -> V_58 ) ;
if ( F_52 ( V_5 == 0 ) ) {
F_48 ( V_2 -> V_58 , V_123 , V_117 ) ;
V_94 = F_53 ( V_2 -> V_58 , V_124 ) ;
F_54 ( V_2 -> V_58 ) ;
}
F_55 ( & V_2 -> V_58 -> V_122 , V_11 ) ;
#ifdef F_56
if ( V_5 == 0 ) {
const struct V_125 * V_54 ;
V_54 = & ( V_2 -> V_30 -> V_54 [ V_55 ] ) ;
if ( ! V_2 -> V_126 ) {
V_2 -> V_126 =
F_57 ( V_54 -> V_56 [ V_127 ] . V_57 ,
V_128 ) ;
}
if ( V_2 -> V_126 )
F_58 (
V_2 -> V_58 , 0x800000 ,
V_2 -> V_126 ,
V_54 -> V_56 [ V_127 ] . V_57 / 4 ) ;
}
#endif
}
V_101 = V_9 -> V_101 ;
V_2 -> V_62 = false ;
F_45 ( V_2 ) ;
memset ( ( void * ) & V_9 -> V_129 , 0 , sizeof( V_9 -> V_129 ) ) ;
F_59 ( V_2 , V_9 ) ;
F_60 ( V_2 , V_9 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
F_61 ( V_101 ) ;
return 1 ;
}
static void F_62 ( struct V_6 * V_7 , bool V_130 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_63 ( V_2 -> V_58 -> V_61 , V_130 ) ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_65 ( V_2 , L_10 , V_134 -> V_57 ,
F_66 ( V_7 , F_67 ( V_134 ) ) -> V_135 ) ;
if ( F_68 ( V_2 , V_132 -> V_136 , V_134 ) )
F_69 ( V_7 , V_134 ) ;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_137 * V_138 ,
struct V_139 * V_136 ,
T_1 V_140 , T_2 * V_141 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_71 ( V_2 , V_101 , V_138 , V_136 , V_140 , V_141 ) ;
}
static int F_72 ( struct V_6 * V_7 , enum V_142 V_143 ,
struct V_100 * V_101 ,
struct V_139 * V_136 ,
struct V_137 * V_144 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_39 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_9 = V_145 -> V_9 ;
int V_5 ;
bool V_147 = false ;
F_28 ( V_2 , L_7 ) ;
if ( V_33 . V_34 ) {
F_28 ( V_2 , L_11 ) ;
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
F_29 ( & V_2 -> V_92 ) ;
F_73 ( V_2 , 100 ) ;
F_3 ( V_157 == V_159 ) ;
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
V_5 = F_74 ( V_2 , V_145 -> V_9 , V_144 ) ;
break;
}
V_5 = F_75 ( V_2 , V_145 -> V_9 , V_144 , V_136 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_144 -> V_156 = V_157 ;
}
F_28 ( V_2 , L_12 ) ;
break;
case V_158 :
if ( V_147 )
V_5 = F_76 ( V_2 , V_9 , V_144 ) ;
else
V_5 = F_77 ( V_2 , V_9 , V_144 , V_136 ) ;
F_28 ( V_2 , L_13 ) ;
break;
default:
V_5 = - V_115 ;
}
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_164 V_165 ,
struct V_139 * V_136 , T_2 V_166 , T_2 * V_167 ,
T_3 V_168 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
int V_5 = - V_115 ;
struct V_37 * V_169 = ( void * ) V_136 -> V_146 ;
F_79 ( V_2 , L_14 ,
V_136 -> V_170 , V_166 ) ;
if ( ! ( V_2 -> V_26 -> V_27 ) )
return - V_171 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
switch ( V_165 ) {
case V_172 :
if ( V_33 . V_173 & V_174 )
break;
F_79 ( V_2 , L_15 ) ;
V_5 = F_80 ( V_2 , V_136 , V_166 , * V_167 ) ;
break;
case V_175 :
F_79 ( V_2 , L_16 ) ;
V_5 = F_81 ( V_2 , V_136 , V_166 ) ;
break;
case V_176 :
if ( ! V_2 -> V_58 -> V_59 -> V_177 )
break;
if ( V_33 . V_173 & V_178 )
break;
F_79 ( V_2 , L_17 ) ;
V_5 = F_82 ( V_2 , V_101 , V_136 , V_166 , V_167 ) ;
break;
case V_179 :
F_79 ( V_2 , L_18 ) ;
V_5 = F_83 ( V_2 , V_101 , V_136 , V_166 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_180 > 0 ) ) {
V_2 -> V_180 -- ;
F_79 ( V_2 , L_19 ,
V_2 -> V_180 ) ;
}
if ( ! V_2 -> V_180 &&
V_2 -> V_181 . V_182 ) {
V_169 -> V_183 . V_184 . V_185 . V_11 &=
~ V_186 ;
F_84 ( V_2 , F_85 ( V_101 ) ,
& V_169 -> V_183 . V_184 , V_187 , false ) ;
}
break;
case V_188 :
V_5 = F_86 ( V_2 , V_101 , V_136 , V_166 , V_168 ) ;
break;
}
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_37 * V_169 = ( void * ) V_136 -> V_146 ;
struct V_39 * V_145 = ( void * ) V_101 -> V_146 ;
bool V_189 = V_101 -> type == V_116 ;
int V_5 ;
T_3 V_190 ;
F_31 ( V_2 , L_20 ,
V_136 -> V_170 ) ;
V_169 -> V_190 = V_191 ;
F_88 ( & V_169 -> V_192 , 0 ) ;
if ( V_101 -> type == V_48 )
V_169 -> V_193 = true ;
V_5 = F_89 ( V_2 , V_145 -> V_9 , V_136 -> V_170 ,
V_189 , V_136 , & V_190 ) ;
if ( V_5 ) {
F_10 ( V_2 , L_21 ,
V_136 -> V_170 , V_5 ) ;
return V_5 ;
}
V_169 -> V_190 = V_190 ;
return 0 ;
}
static int F_90 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_37 * V_169 = ( void * ) V_136 -> V_146 ;
int V_5 ;
F_31 ( V_2 , L_22 , V_136 -> V_170 ) ;
if ( V_101 -> type == V_116 ) {
V_5 = 0 ;
F_91 ( V_2 , V_169 -> V_190 , V_136 -> V_170 ) ;
} else {
V_5 = F_92 ( V_2 , V_169 -> V_190 , V_136 -> V_170 ) ;
if ( V_5 )
F_93 ( V_2 ,
L_23 , V_136 -> V_170 ) ;
}
return V_5 ;
}
static int F_94 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_139 * V_136 ,
enum V_194 V_195 ,
enum V_194 V_196 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_39 * V_145 = ( void * ) V_101 -> V_146 ;
enum {
V_197 , V_198 , REMOVE , V_199 , V_200 ,
} V_201 = V_197 ;
int V_5 ;
F_28 ( V_2 , L_24 ,
V_136 -> V_170 , V_195 , V_196 ) ;
F_29 ( & V_2 -> V_92 ) ;
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
V_5 = F_87 ( V_7 , V_101 , V_136 ) ;
if ( V_5 )
break;
F_95 ( & V_2 -> V_206 ) ;
V_2 -> V_207 [ F_96 ( V_136 ) ] . V_208 &=
~ V_209 ;
F_97 ( & V_2 -> V_206 ) ;
break;
case REMOVE :
V_5 = F_90 ( V_7 , V_101 , V_136 ) ;
break;
case V_200 :
V_5 = F_87 ( V_7 , V_101 , V_136 ) ;
if ( V_5 )
break;
F_31 ( V_2 ,
L_25 ,
V_136 -> V_170 ) ;
F_98 ( V_2 , V_136 , F_96 ( V_136 ) ) ;
V_5 = 0 ;
break;
case V_199 :
V_5 = F_99 ( V_2 , V_145 -> V_9 , V_136 ) ;
if ( V_5 )
break;
F_31 ( V_2 ,
L_25 ,
V_136 -> V_170 ) ;
F_98 ( V_2 , V_136 , F_96 ( V_136 ) ) ;
V_5 = 0 ;
break;
default:
V_5 = 0 ;
break;
}
if ( F_100 ( V_2 ) )
V_5 = 0 ;
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_101 ( struct V_6 * V_7 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_212 * V_213 = & V_7 -> V_213 ;
struct V_214 * V_215 = V_211 -> V_215 ;
struct V_216 * V_217 = & V_2 -> V_218 ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
T_2 V_219 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( F_100 ( V_2 ) )
goto V_106;
if ( F_16 ( V_93 , & V_2 -> V_94 ) ||
F_16 ( V_220 , & V_2 -> V_94 ) ||
F_16 ( V_221 , & V_2 -> V_94 ) )
goto V_106;
if ( ! F_42 ( V_9 ) )
goto V_106;
if ( ! V_2 -> V_222 -> V_223 )
goto V_106;
V_219 = V_215 -> V_224 ;
if ( F_102 ( V_9 -> V_129 . V_215 ) == V_219 )
goto V_106;
V_2 -> V_218 . V_225 = V_213 -> V_226 ;
V_9 -> V_227 . V_130 = F_103 ( V_213 ) ;
if ( V_9 -> V_227 . V_130 )
F_104 ( V_213 , V_9 ) ;
else
V_9 -> V_227 . V_228 = false ;
if ( ( F_102 ( V_9 -> V_229 . V_215 ) != V_219 ) )
V_9 -> V_229 . V_11 = 0 ;
F_105 ( V_2 , V_215 , V_9 ) ;
F_106 ( V_2 , V_217 ) ;
F_107 ( V_2 , V_9 , V_215 -> V_230 , V_9 -> V_101 ) ;
F_23 ( V_221 , & V_2 -> V_94 ) ;
V_2 -> V_231 = F_108 ( V_219 ) ;
if ( V_2 -> V_222 -> V_223 ( V_2 , V_211 ) ) {
F_25 ( V_221 , & V_2 -> V_94 ) ;
V_2 -> V_231 = 0 ;
F_109 ( V_9 -> V_101 , false ) ;
}
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
}
void F_110 ( struct V_1 * V_2 , bool V_232 )
{
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
if ( F_16 ( V_93 , & V_2 -> V_94 ) )
return;
if ( F_111 ( V_221 , & V_2 -> V_94 ) )
F_109 ( V_9 -> V_101 , V_232 ) ;
}
static void F_112 ( struct V_6 * V_7 ,
unsigned int V_233 ,
unsigned int * V_234 ,
T_4 V_235 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
T_5 V_236 = 0 , V_237 = 0 ;
struct V_8 * V_9 ;
#define F_113 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_28 ( V_2 , L_26 ,
V_233 , * V_234 ) ;
F_113 ( V_238 | V_239 , V_240 ) ;
F_113 ( V_241 , V_242 | V_240 ) ;
F_113 ( V_243 , V_244 ) ;
#undef F_113
F_29 ( & V_2 -> V_92 ) ;
F_2 (priv, ctx) {
V_9 -> V_229 . V_245 &= ~ V_237 ;
V_9 -> V_229 . V_245 |= V_236 ;
}
F_30 ( & V_2 -> V_92 ) ;
* V_234 &= V_238 | V_246 | V_239 |
V_243 | V_241 ;
}
static void F_114 ( struct V_6 * V_7 , bool V_247 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_7 ) ;
if ( F_16 ( V_93 , & V_2 -> V_94 ) ) {
F_65 ( V_2 , L_27 ) ;
goto V_248;
}
if ( F_100 ( V_2 ) ) {
F_65 ( V_2 , L_28 ) ;
goto V_248;
}
if ( V_247 ) {
F_28 ( V_2 , L_29 ) ;
if ( F_115 ( V_2 ) ) {
F_10 ( V_2 , L_30 ) ;
goto V_248;
}
}
F_28 ( V_2 , L_31 ) ;
F_116 ( V_2 -> V_58 ) ;
V_248:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
}
static int F_117 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_214 * V_215 ,
int V_249 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_250 ] ;
int V_251 = 0 ;
if ( ! ( V_2 -> V_252 & F_4 ( V_250 ) ) )
return - V_148 ;
if ( ! ( V_9 -> V_41 & F_4 ( V_44 ) ) )
return - V_148 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( F_16 ( V_253 , & V_2 -> V_94 ) ) {
if ( F_118 ( V_2 -> V_254 != V_255 ) ) {
V_251 = - V_256 ;
goto V_106;
}
F_73 ( V_2 , 100 ) ;
if ( F_16 ( V_253 , & V_2 -> V_94 ) ) {
V_251 = - V_256 ;
goto V_106;
}
}
V_2 -> V_257 = V_215 ;
V_2 -> V_258 = F_119 ( 1000 * V_249 , 1024 ) ;
V_2 -> V_259 = false ;
F_120 ( & V_2 -> V_260 ) ;
if ( ! V_9 -> V_261 ) {
static const struct V_262 V_263 = {
. V_264 = {
. V_265 [ 0 ] = {
. V_266 = F_108 ( 3 ) ,
. V_267 = F_108 ( 7 ) ,
. V_268 = 2 ,
. V_269 = F_108 ( 1504 ) ,
} ,
. V_265 [ 1 ] = {
. V_266 = F_108 ( 7 ) ,
. V_267 = F_108 ( 15 ) ,
. V_268 = 2 ,
. V_269 = F_108 ( 3008 ) ,
} ,
. V_265 [ 2 ] = {
. V_266 = F_108 ( 15 ) ,
. V_267 = F_108 ( 1023 ) ,
. V_268 = 3 ,
} ,
. V_265 [ 3 ] = {
. V_266 = F_108 ( 15 ) ,
. V_267 = F_108 ( 1023 ) ,
. V_268 = 7 ,
} ,
} ,
} ;
V_9 -> V_261 = true ;
V_9 -> V_270 = V_263 ;
V_9 -> V_229 . V_271 = V_272 ;
memcpy ( V_9 -> V_229 . V_273 ,
V_2 -> V_104 [ V_105 ] . V_229 . V_273 ,
V_274 ) ;
memcpy ( V_9 -> V_229 . V_275 ,
V_2 -> V_104 [ V_105 ] . V_229 . V_273 ,
V_274 ) ;
V_251 = F_121 ( V_2 , V_9 ) ;
if ( V_251 )
goto V_106;
V_9 -> V_229 . V_245 |= V_276 |
V_240 |
V_242 ;
V_251 = F_121 ( V_2 , V_9 ) ;
if ( V_251 ) {
F_122 ( V_2 ) ;
goto V_106;
}
V_2 -> V_277 = true ;
}
V_251 = F_123 ( V_2 , V_9 -> V_101 , V_278 , V_215 -> V_230 ) ;
if ( V_251 )
F_122 ( V_2 ) ;
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_251 ;
}
static int F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
if ( ! ( V_2 -> V_252 & F_4 ( V_250 ) ) )
return - V_148 ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
F_73 ( V_2 , V_2 -> V_258 ) ;
F_122 ( V_2 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_125 ( struct V_6 * V_7 ,
enum V_279 V_280 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_281 -> V_282 &&
V_2 -> V_281 -> V_282 -> V_283 ) {
if ( V_280 == V_284 )
V_2 -> V_285 = true ;
else if ( V_280 == V_286 )
V_2 -> V_285 = false ;
F_126 ( V_2 ) ;
} else {
F_28 ( V_2 , L_32
L_33 ) ;
}
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
}
static int F_127 ( struct V_6 * V_7 ,
struct V_139 * V_136 , bool V_287 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_128 ( V_2 -> V_99 , & V_2 -> V_288 ) ;
return 0 ;
}
static int F_129 ( struct V_6 * V_7 ,
struct V_100 * V_101 , T_2 V_289 ,
const struct V_290 * V_291 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_39 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_9 = V_145 -> V_9 ;
int V_292 ;
if ( F_32 ( ! V_9 ) )
return - V_115 ;
F_28 ( V_2 , L_7 ) ;
if ( ! F_130 ( V_2 ) ) {
F_28 ( V_2 , L_34 ) ;
return - V_95 ;
}
if ( V_289 >= V_293 ) {
F_28 ( V_2 , L_35 , V_289 ) ;
return 0 ;
}
V_292 = V_293 - 1 - V_289 ;
F_29 ( & V_2 -> V_92 ) ;
V_9 -> V_270 . V_264 . V_265 [ V_292 ] . V_266 =
F_108 ( V_291 -> V_266 ) ;
V_9 -> V_270 . V_264 . V_265 [ V_292 ] . V_267 =
F_108 ( V_291 -> V_267 ) ;
V_9 -> V_270 . V_264 . V_265 [ V_292 ] . V_268 = V_291 -> V_294 ;
V_9 -> V_270 . V_264 . V_265 [ V_292 ] . V_269 =
F_108 ( ( V_291 -> V_295 * 32 ) ) ;
V_9 -> V_270 . V_264 . V_265 [ V_292 ] . V_296 = 0 ;
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_131 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
return V_2 -> V_297 == V_298 ;
}
static int F_132 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_59 ( V_2 , V_9 ) ;
F_60 ( V_2 , V_9 ) ;
return F_121 ( V_2 , V_9 ) ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
int V_251 , V_265 ;
F_15 ( & V_2 -> V_92 ) ;
V_2 -> V_299 = V_101 -> type ;
V_9 -> V_261 = true ;
V_251 = F_132 ( V_2 , V_9 ) ;
if ( V_251 ) {
if ( ! V_9 -> V_300 )
V_9 -> V_261 = false ;
return V_251 ;
}
if ( V_2 -> V_281 -> V_282 && V_2 -> V_281 -> V_282 -> V_283 &&
V_101 -> type == V_154 ) {
V_2 -> V_301 = V_302 ;
}
for ( V_265 = 0 ; V_265 < V_303 ; V_265 ++ )
V_101 -> V_304 [ V_265 ] = V_9 -> V_305 [ V_265 ] ;
if ( V_101 -> type == V_48 )
V_101 -> V_306 = V_9 -> V_307 ;
else
V_101 -> V_306 = V_308 ;
return 0 ;
}
static int F_134 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_39 * V_145 = ( void * ) V_101 -> V_146 ;
struct V_8 * V_309 , * V_9 = NULL ;
int V_251 ;
enum V_310 V_311 = F_135 ( V_101 ) ;
bool V_312 = false ;
F_28 ( V_2 , L_36 ,
V_311 , V_101 -> V_170 ) ;
F_136 ( & V_2 -> V_260 ) ;
F_29 ( & V_2 -> V_92 ) ;
F_122 ( V_2 ) ;
if ( ! F_130 ( V_2 ) ) {
F_17 ( V_2 , L_37 ) ;
V_251 = - V_115 ;
goto V_106;
}
F_2 (priv, tmp) {
T_1 V_313 =
V_309 -> V_41 | V_309 -> V_42 ;
if ( V_309 -> V_101 ) {
if ( V_309 -> V_101 == V_101 ) {
V_312 = true ;
V_9 = V_309 ;
break;
}
if ( V_309 -> V_42 &
F_4 ( V_309 -> V_101 -> type ) ) {
V_251 = - V_115 ;
goto V_106;
}
continue;
}
if ( ! ( V_313 & F_4 ( V_311 ) ) )
continue;
V_9 = V_309 ;
break;
}
if ( ! V_9 ) {
V_251 = - V_148 ;
goto V_106;
}
V_145 -> V_9 = V_9 ;
V_9 -> V_101 = V_101 ;
if ( V_101 -> type == V_314 )
V_2 -> V_7 -> V_11 |= V_315 ;
else
V_2 -> V_7 -> V_11 &= ~ V_315 ;
V_251 = F_133 ( V_2 , V_9 ) ;
if ( ! V_251 || V_312 )
goto V_106;
V_9 -> V_101 = NULL ;
V_2 -> V_299 = V_116 ;
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_251 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
bool V_316 )
{
struct V_8 * V_9 = F_85 ( V_101 ) ;
F_15 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_317 == V_101 ) {
F_73 ( V_2 , 200 ) ;
F_138 ( V_2 ) ;
}
if ( ! V_316 ) {
F_132 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_300 )
V_9 -> V_261 = false ;
}
if ( V_101 -> type == V_154 )
V_2 -> V_301 = V_2 -> V_318 ;
}
static void F_139 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_8 * V_9 = F_85 ( V_101 ) ;
F_28 ( V_2 , L_7 ) ;
F_29 ( & V_2 -> V_92 ) ;
if ( F_32 ( V_9 -> V_101 != V_101 ) ) {
struct V_8 * V_309 ;
F_10 ( V_2 , L_38 , V_9 -> V_101 , V_101 ) ;
F_2 (priv, tmp)
F_10 ( V_2 , L_39 ,
V_309 -> V_319 , V_309 , V_309 -> V_101 ) ;
}
V_9 -> V_101 = NULL ;
F_137 ( V_2 , V_101 , false ) ;
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
}
static int F_140 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_310 V_320 , bool V_321 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_8 * V_9 , * V_309 ;
enum V_310 V_322 = V_320 ;
T_1 V_41 ;
int V_251 ;
F_28 ( V_2 , L_7 ) ;
V_320 = F_141 ( V_320 , V_321 ) ;
F_29 ( & V_2 -> V_92 ) ;
V_9 = F_85 ( V_101 ) ;
if ( V_9 -> V_319 != V_105 ) {
V_251 = - V_256 ;
goto V_106;
}
if ( ! V_9 -> V_101 || ! F_130 ( V_2 ) ) {
V_251 = - V_256 ;
goto V_106;
}
V_41 = V_9 -> V_41 | V_9 -> V_42 ;
if ( ! ( V_41 & F_4 ( V_320 ) ) ) {
V_251 = - V_256 ;
goto V_106;
}
if ( V_9 -> V_42 & F_4 ( V_320 ) ) {
F_2 (priv, tmp) {
if ( V_9 == V_309 )
continue;
if ( ! V_309 -> V_261 )
continue;
V_251 = - V_256 ;
goto V_106;
}
}
F_137 ( V_2 , V_101 , true ) ;
V_101 -> type = V_322 ;
V_101 -> V_323 = V_321 ;
V_251 = F_133 ( V_2 , V_9 ) ;
F_32 ( V_251 ) ;
V_251 = 0 ;
V_106:
F_30 ( & V_2 -> V_92 ) ;
F_28 ( V_2 , L_9 ) ;
return V_251 ;
}
static int F_142 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_324 * V_325 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
int V_5 ;
F_28 ( V_2 , L_7 ) ;
if ( V_325 -> V_87 == 0 )
return - V_115 ;
F_29 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_254 != V_326 ) {
F_143 ( V_2 ,
L_40 ) ;
V_2 -> V_327 = V_325 ;
V_2 -> V_317 = V_101 ;
V_5 = 0 ;
} else {
V_2 -> V_327 = V_325 ;
V_2 -> V_317 = V_101 ;
V_5 = F_123 ( V_2 , V_101 , V_326 ,
V_325 -> V_328 [ 0 ] -> V_230 ) ;
if ( V_5 ) {
V_2 -> V_327 = NULL ;
V_2 -> V_317 = NULL ;
}
}
F_28 ( V_2 , L_9 ) ;
F_30 ( & V_2 -> V_92 ) ;
return V_5 ;
}
static void F_144 ( struct V_1 * V_2 , int V_190 )
{
struct V_329 V_143 = {
. V_330 = V_331 ,
. V_332 = V_333 ,
. V_136 . V_190 = V_190 ,
} ;
F_145 ( V_2 , & V_143 , V_187 ) ;
}
static void F_146 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_334 V_143 ,
struct V_139 * V_136 )
{
struct V_1 * V_2 = F_27 ( V_7 ) ;
struct V_37 * V_169 = ( void * ) V_136 -> V_146 ;
int V_190 ;
F_28 ( V_2 , L_7 ) ;
switch ( V_143 ) {
case V_335 :
F_32 ( ! V_169 -> V_193 ) ;
V_169 -> V_336 = true ;
if ( F_147 ( & V_169 -> V_192 ) > 0 )
F_148 ( V_7 , V_136 , true ) ;
break;
case V_337 :
F_32 ( ! V_169 -> V_193 ) ;
if ( ! V_169 -> V_336 )
break;
V_169 -> V_336 = false ;
V_190 = F_96 ( V_136 ) ;
if ( V_190 != V_191 )
F_144 ( V_2 , V_190 ) ;
break;
default:
break;
}
F_28 ( V_2 , L_9 ) ;
}
struct V_6 * F_149 ( void )
{
struct V_1 * V_2 ;
struct V_338 * V_339 ;
struct V_6 * V_7 ;
V_7 = F_150 ( sizeof( struct V_1 ) +
sizeof( struct V_338 ) , & V_340 ) ;
if ( ! V_7 )
goto V_106;
V_339 = V_7 -> V_2 ;
V_2 = F_151 ( V_339 ) ;
V_2 -> V_7 = V_7 ;
V_106:
return V_7 ;
}
