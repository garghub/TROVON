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
V_7 -> V_37 -> V_47 = 1000 ;
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
static void F_65 ( struct V_6 * V_7 , struct V_131 * V_132 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_66 ( V_2 , L_10 , V_132 -> V_55 ,
F_67 ( V_7 , F_68 ( V_132 ) ) -> V_133 ) ;
if ( F_69 ( V_2 , V_132 ) )
F_70 ( V_132 ) ;
}
static void F_71 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_134 * V_135 ,
struct V_136 * V_137 ,
T_1 V_138 , T_2 * V_139 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_72 ( V_2 , V_101 , V_135 , V_137 , V_138 , V_139 ) ;
}
static int F_73 ( struct V_6 * V_7 , enum V_140 V_141 ,
struct V_100 * V_101 ,
struct V_136 * V_137 ,
struct V_134 * V_142 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_143 = ( void * ) V_101 -> V_144 ;
struct V_8 * V_9 = V_143 -> V_9 ;
int V_5 ;
bool V_145 = false ;
F_29 ( V_2 , L_7 ) ;
if ( V_65 . V_66 ) {
F_29 ( V_2 , L_11 ) ;
return - V_146 ;
}
switch ( V_142 -> V_147 ) {
case V_148 :
V_142 -> V_11 |= V_149 ;
case V_150 :
V_142 -> V_11 |= V_151 ;
break;
default:
break;
}
if ( V_101 -> type == V_152 &&
! ( V_142 -> V_11 & V_153 ) ) {
V_142 -> V_154 = V_155 ;
return 0 ;
}
if ( V_141 == V_156 && V_142 -> V_154 == V_155 )
return 0 ;
F_30 ( & V_2 -> V_92 ) ;
F_74 ( V_2 , 100 ) ;
F_4 ( V_155 == V_157 ) ;
if ( ( V_142 -> V_147 == V_158 ||
V_142 -> V_147 == V_159 ) && ! V_137 ) {
if ( V_141 == V_160 )
V_145 = ! V_9 -> V_161 ;
else
V_145 =
V_142 -> V_154 == V_157 ;
}
switch ( V_141 ) {
case V_160 :
if ( V_145 ) {
V_5 = F_75 ( V_2 , V_143 -> V_9 , V_142 ) ;
break;
}
V_5 = F_76 ( V_2 , V_143 -> V_9 , V_142 , V_137 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_142 -> V_154 = V_155 ;
}
F_29 ( V_2 , L_12 ) ;
break;
case V_156 :
if ( V_145 )
V_5 = F_77 ( V_2 , V_9 , V_142 ) ;
else
V_5 = F_78 ( V_2 , V_9 , V_142 , V_137 ) ;
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
enum V_162 V_163 ,
struct V_136 * V_137 , T_2 V_164 , T_2 * V_165 ,
T_3 V_166 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 = - V_115 ;
struct V_34 * V_167 = ( void * ) V_137 -> V_144 ;
F_80 ( V_2 , L_14 ,
V_137 -> V_168 , V_164 ) ;
if ( ! ( V_2 -> V_26 -> V_27 & V_28 ) )
return - V_169 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
switch ( V_163 ) {
case V_170 :
if ( V_65 . V_171 & V_172 )
break;
F_80 ( V_2 , L_15 ) ;
V_5 = F_81 ( V_2 , V_137 , V_164 , * V_165 ) ;
break;
case V_173 :
F_80 ( V_2 , L_16 ) ;
V_5 = F_82 ( V_2 , V_137 , V_164 ) ;
break;
case V_174 :
if ( ! V_2 -> V_56 -> V_57 -> V_175 )
break;
if ( V_65 . V_171 & V_176 )
break;
F_80 ( V_2 , L_17 ) ;
V_5 = F_83 ( V_2 , V_101 , V_137 , V_164 , V_165 ) ;
break;
case V_177 :
F_80 ( V_2 , L_18 ) ;
V_5 = F_84 ( V_2 , V_101 , V_137 , V_164 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_178 > 0 ) ) {
V_2 -> V_178 -- ;
F_80 ( V_2 , L_19 ,
V_2 -> V_178 ) ;
}
if ( ! V_2 -> V_178 &&
V_2 -> V_179 . V_180 ) {
V_167 -> V_181 . V_182 . V_183 . V_11 &=
~ V_184 ;
F_85 ( V_2 , F_86 ( V_101 ) ,
& V_167 -> V_181 . V_182 , V_185 , false ) ;
}
break;
case V_186 :
V_5 = F_87 ( V_2 , V_101 , V_137 , V_164 , V_166 ) ;
break;
}
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_167 = ( void * ) V_137 -> V_144 ;
struct V_36 * V_143 = ( void * ) V_101 -> V_144 ;
bool V_187 = V_101 -> type == V_116 ;
int V_5 ;
T_3 V_188 ;
F_32 ( V_2 , L_20 ,
V_137 -> V_168 ) ;
V_167 -> V_188 = V_189 ;
F_89 ( & V_167 -> V_190 , 0 ) ;
if ( V_101 -> type == V_45 )
V_167 -> V_191 = true ;
V_5 = F_90 ( V_2 , V_143 -> V_9 , V_137 -> V_168 ,
V_187 , V_137 , & V_188 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_21 ,
V_137 -> V_168 , V_5 ) ;
return V_5 ;
}
V_167 -> V_188 = V_188 ;
return 0 ;
}
static int F_91 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_167 = ( void * ) V_137 -> V_144 ;
int V_5 ;
F_32 ( V_2 , L_22 , V_137 -> V_168 ) ;
if ( V_101 -> type == V_116 ) {
V_5 = 0 ;
F_92 ( V_2 , V_167 -> V_188 , V_137 -> V_168 ) ;
} else {
V_5 = F_93 ( V_2 , V_167 -> V_188 , V_137 -> V_168 ) ;
if ( V_5 )
F_94 ( V_2 ,
L_23 , V_137 -> V_168 ) ;
}
return V_5 ;
}
static int F_95 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_136 * V_137 ,
enum V_192 V_193 ,
enum V_192 V_194 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_143 = ( void * ) V_101 -> V_144 ;
enum {
V_195 , V_196 , REMOVE , V_197 , V_198 ,
} V_199 = V_195 ;
int V_5 ;
F_29 ( V_2 , L_24 ,
V_137 -> V_168 , V_193 , V_194 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_101 -> type == V_116 ) {
if ( V_193 == V_200 &&
V_194 == V_201 )
V_199 = V_196 ;
else if ( V_193 == V_201 &&
V_194 == V_200 )
V_199 = REMOVE ;
else if ( V_193 == V_202 &&
V_194 == V_203 )
V_199 = V_197 ;
} else {
if ( V_193 == V_202 &&
V_194 == V_203 )
V_199 = V_198 ;
else if ( V_193 == V_203 &&
V_194 == V_202 )
V_199 = REMOVE ;
}
switch ( V_199 ) {
case V_196 :
V_5 = F_88 ( V_7 , V_101 , V_137 ) ;
if ( V_5 )
break;
F_96 ( & V_2 -> V_204 ) ;
V_2 -> V_205 [ F_97 ( V_137 ) ] . V_206 &=
~ V_207 ;
F_98 ( & V_2 -> V_204 ) ;
break;
case REMOVE :
V_5 = F_91 ( V_7 , V_101 , V_137 ) ;
break;
case V_198 :
V_5 = F_88 ( V_7 , V_101 , V_137 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_137 -> V_168 ) ;
F_99 ( V_2 , V_137 , F_97 ( V_137 ) ) ;
V_5 = 0 ;
break;
case V_197 :
V_5 = F_100 ( V_2 , V_143 -> V_9 , V_137 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_137 -> V_168 ) ;
F_99 ( V_2 , V_137 , F_97 ( V_137 ) ) ;
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
struct V_208 * V_209 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_210 * V_211 = & V_7 -> V_211 ;
struct V_212 * V_213 = V_209 -> V_213 ;
struct V_214 * V_215 = & V_2 -> V_216 ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
T_2 V_217 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_101 ( V_2 ) )
goto V_106;
if ( F_17 ( V_93 , & V_2 -> V_94 ) ||
F_17 ( V_218 , & V_2 -> V_94 ) ||
F_17 ( V_219 , & V_2 -> V_94 ) )
goto V_106;
if ( ! F_43 ( V_9 ) )
goto V_106;
if ( ! V_2 -> V_220 -> V_221 )
goto V_106;
V_217 = V_213 -> V_222 ;
if ( F_103 ( V_9 -> V_129 . V_213 ) == V_217 )
goto V_106;
V_2 -> V_216 . V_223 = V_211 -> V_224 ;
V_9 -> V_225 . V_130 = F_104 ( V_211 ) ;
if ( V_9 -> V_225 . V_130 )
F_105 ( V_211 , V_9 ) ;
else
V_9 -> V_225 . V_226 = false ;
if ( ( F_103 ( V_9 -> V_227 . V_213 ) != V_217 ) )
V_9 -> V_227 . V_11 = 0 ;
F_106 ( V_2 , V_213 , V_9 ) ;
F_107 ( V_2 , V_215 ) ;
F_108 ( V_2 , V_9 , V_213 -> V_228 , V_9 -> V_101 ) ;
F_24 ( V_219 , & V_2 -> V_94 ) ;
V_2 -> V_229 = F_109 ( V_217 ) ;
if ( V_2 -> V_220 -> V_221 ( V_2 , V_209 ) ) {
F_26 ( V_219 , & V_2 -> V_94 ) ;
V_2 -> V_229 = 0 ;
F_110 ( V_9 -> V_101 , false ) ;
}
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
void F_111 ( struct V_1 * V_2 , bool V_230 )
{
struct V_8 * V_9 = & V_2 -> V_104 [ V_105 ] ;
if ( F_17 ( V_93 , & V_2 -> V_94 ) )
return;
if ( F_112 ( V_219 , & V_2 -> V_94 ) )
F_110 ( V_9 -> V_101 , V_230 ) ;
}
static void F_113 ( struct V_6 * V_7 ,
unsigned int V_231 ,
unsigned int * V_232 ,
T_4 V_233 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
T_5 V_234 = 0 , V_235 = 0 ;
struct V_8 * V_9 ;
#define F_114 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_29 ( V_2 , L_26 ,
V_231 , * V_232 ) ;
F_114 ( V_236 | V_237 , V_238 ) ;
F_114 ( V_239 , V_240 | V_238 ) ;
F_114 ( V_241 , V_242 ) ;
#undef F_114
F_30 ( & V_2 -> V_92 ) ;
F_3 (priv, ctx) {
V_9 -> V_227 . V_243 &= ~ V_235 ;
V_9 -> V_227 . V_243 |= V_234 ;
}
F_31 ( & V_2 -> V_92 ) ;
* V_232 &= V_236 | V_244 | V_237 |
V_241 | V_239 ;
}
static void F_115 ( struct V_6 * V_7 , bool V_245 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_7 ) ;
if ( F_17 ( V_93 , & V_2 -> V_94 ) ) {
F_66 ( V_2 , L_27 ) ;
goto V_246;
}
if ( F_101 ( V_2 ) ) {
F_66 ( V_2 , L_28 ) ;
goto V_246;
}
if ( V_245 ) {
F_29 ( V_2 , L_29 ) ;
if ( F_116 ( V_2 , V_247 ) ) {
F_11 ( V_2 , L_30 ) ;
goto V_246;
}
}
F_29 ( V_2 , L_31 ) ;
F_117 ( V_2 -> V_56 ) ;
V_246:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_118 ( struct V_6 * V_7 ,
struct V_212 * V_213 ,
enum V_248 V_249 ,
int V_250 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_104 [ V_251 ] ;
int V_252 = 0 ;
if ( ! ( V_2 -> V_253 & F_5 ( V_251 ) ) )
return - V_146 ;
if ( ! ( V_9 -> V_38 & F_5 ( V_41 ) ) )
return - V_146 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_17 ( V_254 , & V_2 -> V_94 ) ) {
if ( F_119 ( V_2 -> V_255 != V_256 ) ) {
V_252 = - V_257 ;
goto V_106;
}
F_74 ( V_2 , 100 ) ;
if ( F_17 ( V_254 , & V_2 -> V_94 ) ) {
V_252 = - V_257 ;
goto V_106;
}
}
V_2 -> V_258 = V_213 ;
V_2 -> V_259 = V_249 ;
V_2 -> V_260 = F_120 ( 1000 * V_250 , 1024 ) ;
V_2 -> V_261 = false ;
F_121 ( & V_2 -> V_262 ) ;
if ( ! V_9 -> V_263 ) {
static const struct V_264 V_265 = {
. V_266 = {
. V_267 [ 0 ] = {
. V_268 = F_109 ( 3 ) ,
. V_269 = F_109 ( 7 ) ,
. V_270 = 2 ,
. V_271 = F_109 ( 1504 ) ,
} ,
. V_267 [ 1 ] = {
. V_268 = F_109 ( 7 ) ,
. V_269 = F_109 ( 15 ) ,
. V_270 = 2 ,
. V_271 = F_109 ( 3008 ) ,
} ,
. V_267 [ 2 ] = {
. V_268 = F_109 ( 15 ) ,
. V_269 = F_109 ( 1023 ) ,
. V_270 = 3 ,
} ,
. V_267 [ 3 ] = {
. V_268 = F_109 ( 15 ) ,
. V_269 = F_109 ( 1023 ) ,
. V_270 = 7 ,
} ,
} ,
} ;
V_9 -> V_263 = true ;
V_9 -> V_272 = V_265 ;
V_9 -> V_227 . V_273 = V_274 ;
memcpy ( V_9 -> V_227 . V_275 ,
V_2 -> V_104 [ V_105 ] . V_227 . V_275 ,
V_276 ) ;
memcpy ( V_9 -> V_227 . V_277 ,
V_2 -> V_104 [ V_105 ] . V_227 . V_275 ,
V_276 ) ;
V_252 = F_122 ( V_2 , V_9 ) ;
if ( V_252 )
goto V_106;
V_9 -> V_227 . V_243 |= V_278 |
V_238 |
V_240 ;
V_252 = F_122 ( V_2 , V_9 ) ;
if ( V_252 ) {
F_123 ( V_2 ) ;
goto V_106;
}
V_2 -> V_279 = true ;
}
V_252 = F_124 ( V_2 , V_9 -> V_101 , V_280 , V_213 -> V_228 ) ;
if ( V_252 )
F_123 ( V_2 ) ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_252 ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
if ( ! ( V_2 -> V_253 & F_5 ( V_251 ) ) )
return - V_146 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_74 ( V_2 , V_2 -> V_260 ) ;
F_123 ( V_2 ) ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_126 ( struct V_6 * V_7 ,
enum V_281 V_282 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_283 -> V_284 &&
V_2 -> V_283 -> V_284 -> V_285 ) {
if ( V_282 == V_286 )
V_2 -> V_287 = true ;
else if ( V_282 == V_288 )
V_2 -> V_287 = false ;
F_127 ( V_2 ) ;
} else {
F_29 ( V_2 , L_32
L_33 ) ;
}
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_128 ( struct V_6 * V_7 ,
struct V_136 * V_137 , bool V_289 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_129 ( V_2 -> V_99 , & V_2 -> V_290 ) ;
return 0 ;
}
static int F_130 ( struct V_6 * V_7 ,
struct V_100 * V_101 , T_2 V_291 ,
const struct V_292 * V_293 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_143 = ( void * ) V_101 -> V_144 ;
struct V_8 * V_9 = V_143 -> V_9 ;
int V_294 ;
if ( F_33 ( ! V_9 ) )
return - V_115 ;
F_29 ( V_2 , L_7 ) ;
if ( ! F_131 ( V_2 ) ) {
F_29 ( V_2 , L_34 ) ;
return - V_95 ;
}
if ( V_291 >= V_295 ) {
F_29 ( V_2 , L_35 , V_291 ) ;
return 0 ;
}
V_294 = V_295 - 1 - V_291 ;
F_30 ( & V_2 -> V_92 ) ;
V_9 -> V_272 . V_266 . V_267 [ V_294 ] . V_268 =
F_109 ( V_293 -> V_268 ) ;
V_9 -> V_272 . V_266 . V_267 [ V_294 ] . V_269 =
F_109 ( V_293 -> V_269 ) ;
V_9 -> V_272 . V_266 . V_267 [ V_294 ] . V_270 = V_293 -> V_296 ;
V_9 -> V_272 . V_266 . V_267 [ V_294 ] . V_271 =
F_109 ( ( V_293 -> V_297 * 32 ) ) ;
V_9 -> V_272 . V_266 . V_267 [ V_294 ] . V_298 = 0 ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_132 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
return V_2 -> V_299 == V_300 ;
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
int V_252 , V_267 ;
F_16 ( & V_2 -> V_92 ) ;
V_2 -> V_301 = V_101 -> type ;
V_9 -> V_263 = true ;
V_252 = F_133 ( V_2 , V_9 ) ;
if ( V_252 ) {
if ( ! V_9 -> V_302 )
V_9 -> V_263 = false ;
return V_252 ;
}
if ( V_2 -> V_283 -> V_284 && V_2 -> V_283 -> V_284 -> V_285 &&
V_101 -> type == V_152 ) {
V_2 -> V_303 = V_304 ;
}
for ( V_267 = 0 ; V_267 < V_305 ; V_267 ++ )
V_101 -> V_306 [ V_267 ] = V_9 -> V_307 [ V_267 ] ;
if ( V_101 -> type == V_45 )
V_101 -> V_308 = V_9 -> V_309 ;
else
V_101 -> V_308 = V_310 ;
return 0 ;
}
static int F_135 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_36 * V_143 = ( void * ) V_101 -> V_144 ;
struct V_8 * V_311 , * V_9 = NULL ;
int V_252 ;
enum V_312 V_313 = F_136 ( V_101 ) ;
bool V_314 = false ;
F_29 ( V_2 , L_36 ,
V_313 , V_101 -> V_168 ) ;
F_137 ( & V_2 -> V_262 ) ;
F_30 ( & V_2 -> V_92 ) ;
F_123 ( V_2 ) ;
if ( ! F_131 ( V_2 ) ) {
F_18 ( V_2 , L_37 ) ;
V_252 = - V_115 ;
goto V_106;
}
F_3 (priv, tmp) {
T_1 V_315 =
V_311 -> V_38 | V_311 -> V_39 ;
if ( V_311 -> V_101 ) {
if ( V_311 -> V_101 == V_101 ) {
V_314 = true ;
V_9 = V_311 ;
break;
}
if ( V_311 -> V_39 &
F_5 ( V_311 -> V_101 -> type ) ) {
V_252 = - V_115 ;
goto V_106;
}
continue;
}
if ( ! ( V_315 & F_5 ( V_313 ) ) )
continue;
V_9 = V_311 ;
break;
}
if ( ! V_9 ) {
V_252 = - V_146 ;
goto V_106;
}
V_143 -> V_9 = V_9 ;
V_9 -> V_101 = V_101 ;
V_252 = F_134 ( V_2 , V_9 ) ;
if ( ! V_252 || V_314 )
goto V_106;
V_9 -> V_101 = NULL ;
V_2 -> V_301 = V_116 ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_252 ;
}
static void F_138 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
bool V_316 )
{
struct V_8 * V_9 = F_86 ( V_101 ) ;
F_16 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_317 == V_101 ) {
F_74 ( V_2 , 200 ) ;
F_139 ( V_2 ) ;
}
if ( ! V_316 ) {
F_133 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_302 )
V_9 -> V_263 = false ;
}
if ( V_101 -> type == V_152 )
V_2 -> V_303 = V_2 -> V_318 ;
}
static void F_140 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = F_86 ( V_101 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_92 ) ;
if ( F_33 ( V_9 -> V_101 != V_101 ) ) {
struct V_8 * V_311 ;
F_11 ( V_2 , L_38 , V_9 -> V_101 , V_101 ) ;
F_3 (priv, tmp)
F_11 ( V_2 , L_39 ,
V_311 -> V_319 , V_311 , V_311 -> V_101 ) ;
}
V_9 -> V_101 = NULL ;
F_138 ( V_2 , V_101 , false ) ;
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_141 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_312 V_320 , bool V_321 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 , * V_311 ;
enum V_312 V_322 = V_320 ;
T_1 V_38 ;
int V_252 ;
F_29 ( V_2 , L_7 ) ;
V_320 = F_142 ( V_320 , V_321 ) ;
F_30 ( & V_2 -> V_92 ) ;
V_9 = F_86 ( V_101 ) ;
if ( V_9 -> V_319 != V_105 ) {
V_252 = - V_257 ;
goto V_106;
}
if ( ! V_9 -> V_101 || ! F_131 ( V_2 ) ) {
V_252 = - V_257 ;
goto V_106;
}
V_38 = V_9 -> V_38 | V_9 -> V_39 ;
if ( ! ( V_38 & F_5 ( V_320 ) ) ) {
V_252 = - V_257 ;
goto V_106;
}
if ( V_9 -> V_39 & F_5 ( V_320 ) ) {
F_3 (priv, tmp) {
if ( V_9 == V_311 )
continue;
if ( ! V_311 -> V_263 )
continue;
V_252 = - V_257 ;
goto V_106;
}
}
F_138 ( V_2 , V_101 , true ) ;
V_101 -> type = V_322 ;
V_101 -> V_323 = V_321 ;
V_252 = F_134 ( V_2 , V_9 ) ;
F_33 ( V_252 ) ;
V_252 = 0 ;
V_106:
F_31 ( & V_2 -> V_92 ) ;
F_29 ( V_2 , L_9 ) ;
return V_252 ;
}
static int F_143 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
struct V_324 * V_325 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 ;
F_29 ( V_2 , L_7 ) ;
if ( V_325 -> V_87 == 0 )
return - V_115 ;
F_30 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_255 != V_326 ) {
F_144 ( V_2 ,
L_40 ) ;
V_2 -> V_327 = V_325 ;
V_2 -> V_317 = V_101 ;
V_5 = 0 ;
} else {
V_2 -> V_327 = V_325 ;
V_2 -> V_317 = V_101 ;
V_5 = F_124 ( V_2 , V_101 , V_326 ,
V_325 -> V_328 [ 0 ] -> V_228 ) ;
if ( V_5 ) {
V_2 -> V_327 = NULL ;
V_2 -> V_317 = NULL ;
}
}
F_29 ( V_2 , L_9 ) ;
F_31 ( & V_2 -> V_92 ) ;
return V_5 ;
}
static void F_145 ( struct V_1 * V_2 , int V_188 )
{
struct V_329 V_141 = {
. V_330 = V_331 ,
. V_332 = V_333 ,
. V_137 . V_188 = V_188 ,
} ;
F_146 ( V_2 , & V_141 , V_185 ) ;
}
static void F_147 ( struct V_6 * V_7 ,
struct V_100 * V_101 ,
enum V_334 V_141 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_167 = ( void * ) V_137 -> V_144 ;
int V_188 ;
F_29 ( V_2 , L_7 ) ;
switch ( V_141 ) {
case V_335 :
F_33 ( ! V_167 -> V_191 ) ;
V_167 -> V_336 = true ;
if ( F_148 ( & V_167 -> V_190 ) > 0 )
F_149 ( V_7 , V_137 , true ) ;
break;
case V_337 :
F_33 ( ! V_167 -> V_191 ) ;
if ( ! V_167 -> V_336 )
break;
V_167 -> V_336 = false ;
V_188 = F_97 ( V_137 ) ;
if ( V_188 != V_189 )
F_145 ( V_2 , V_188 ) ;
break;
default:
break;
}
F_29 ( V_2 , L_9 ) ;
}
struct V_6 * F_150 ( void )
{
struct V_1 * V_2 ;
struct V_338 * V_339 ;
struct V_6 * V_7 ;
V_7 = F_151 ( sizeof( struct V_1 ) +
sizeof( struct V_338 ) , & V_340 ) ;
if ( ! V_7 )
goto V_106;
V_339 = V_7 -> V_2 ;
V_2 = F_152 ( V_339 ) ;
V_2 -> V_7 = V_7 ;
V_106:
return V_7 ;
}
