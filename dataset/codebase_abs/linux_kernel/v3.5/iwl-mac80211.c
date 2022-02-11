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
if ( V_2 -> V_24 . V_25 & V_26 )
V_7 -> V_11 |= V_27 |
V_28 ;
#ifndef F_2
if ( V_4 -> V_11 & V_29 )
#endif
V_7 -> V_11 |= V_30 ;
V_7 -> V_31 = sizeof( struct V_32 ) ;
V_7 -> V_33 = sizeof( struct V_34 ) ;
F_3 (priv, ctx) {
V_7 -> V_35 -> V_36 |= V_9 -> V_36 ;
V_7 -> V_35 -> V_36 |= V_9 -> V_37 ;
}
F_4 ( V_38 != 2 ) ;
if ( V_7 -> V_35 -> V_36 & F_5 ( V_39 ) ) {
V_7 -> V_35 -> V_40 = V_41 ;
V_7 -> V_35 -> V_42 =
F_6 ( V_41 ) ;
} else if ( V_7 -> V_35 -> V_36 & F_5 ( V_43 ) ) {
V_7 -> V_35 -> V_40 =
V_44 ;
V_7 -> V_35 -> V_42 =
F_6 ( V_44 ) ;
}
V_7 -> V_35 -> V_45 = 1000 ;
V_7 -> V_35 -> V_11 |= V_46 |
V_47 |
V_48 ;
#ifdef F_7
if ( V_2 -> V_49 -> V_50 [ V_51 ] . V_52 [ 0 ] . V_53 &&
V_2 -> V_54 -> V_55 -> V_56 &&
F_8 ( V_2 -> V_54 -> V_57 ) ) {
V_7 -> V_35 -> V_58 . V_11 = V_59 |
V_60 |
V_61 |
V_62 ;
if ( ! V_63 . V_64 )
V_7 -> V_35 -> V_58 . V_11 |=
V_65 |
V_66 ;
V_7 -> V_35 -> V_58 . V_67 = V_68 ;
V_7 -> V_35 -> V_58 . V_69 =
V_70 ;
V_7 -> V_35 -> V_58 . V_71 =
V_72 ;
}
#endif
if ( V_63 . V_73 )
V_7 -> V_35 -> V_11 |= V_74 ;
else
V_7 -> V_35 -> V_11 &= ~ V_74 ;
V_7 -> V_35 -> V_75 = V_76 ;
V_7 -> V_35 -> V_77 = V_4 -> V_78 - 24 - 34 ;
V_7 -> V_79 = V_80 ;
V_7 -> V_81 = V_82 ;
if ( V_2 -> V_83 [ V_84 ] . V_85 )
V_2 -> V_7 -> V_35 -> V_83 [ V_84 ] =
& V_2 -> V_83 [ V_84 ] ;
if ( V_2 -> V_83 [ V_86 ] . V_85 )
V_2 -> V_7 -> V_35 -> V_83 [ V_86 ] =
& V_2 -> V_83 [ V_86 ] ;
V_7 -> V_35 -> V_87 = V_2 -> V_54 -> V_88 ;
F_9 ( V_2 ) ;
V_5 = F_10 ( V_2 -> V_7 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_2 , V_5 ) ;
F_12 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_89 = 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_89 )
return;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_7 ) ;
V_2 -> V_89 = 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_5 ;
F_16 ( & V_2 -> V_90 ) ;
if ( F_17 ( V_91 , & V_2 -> V_92 ) ) {
F_18 ( V_2 , L_3 ) ;
return - V_93 ;
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
V_5 = F_22 ( V_2 , V_94 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_5 , V_5 ) ;
goto error;
}
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_24 ( V_91 , & V_2 -> V_92 ) ;
F_25 ( V_2 ) ;
F_26 ( V_91 , & V_2 -> V_92 ) ;
F_11 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
V_5 = F_15 ( V_2 ) ;
F_31 ( & V_2 -> V_90 ) ;
if ( V_5 )
return V_5 ;
F_32 ( V_2 , L_8 ) ;
if ( F_33 ( ! F_17 ( V_95 , & V_2 -> V_92 ) ) )
V_5 = - V_93 ;
F_34 ( V_2 ) ;
V_2 -> V_96 = 1 ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( V_2 , L_7 ) ;
if ( ! V_2 -> V_96 )
return;
V_2 -> V_96 = 0 ;
F_30 ( & V_2 -> V_90 ) ;
F_25 ( V_2 ) ;
F_31 ( & V_2 -> V_90 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 -> V_97 ) ;
F_38 ( V_2 -> V_54 , false ) ;
F_29 ( V_2 , L_9 ) ;
}
void F_39 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
if ( V_63 . V_64 )
return;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_102 [ V_103 ] . V_99 != V_99 )
goto V_104;
memcpy ( V_2 -> V_105 , V_101 -> V_105 , V_106 ) ;
memcpy ( V_2 -> V_107 , V_101 -> V_107 , V_108 ) ;
V_2 -> V_109 =
F_40 ( F_41 ( ( V_110 * ) & V_101 -> V_109 ) ) ;
V_2 -> V_111 = true ;
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
}
int F_42 ( struct V_6 * V_7 , struct V_112 * V_58 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_102 [ V_103 ] ;
int V_5 ;
if ( F_33 ( ! V_58 ) )
return - V_113 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( ! V_9 -> V_99 || V_9 -> V_99 -> type != V_114 ||
! F_43 ( V_9 ) ) {
V_5 = 1 ;
goto V_104;
}
V_5 = F_44 ( V_2 , V_58 ) ;
if ( V_5 )
goto error;
F_45 ( V_2 -> V_54 -> V_57 , true ) ;
F_46 ( V_2 -> V_54 ) ;
goto V_104;
error:
V_2 -> V_58 = false ;
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_7 ) ;
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_102 [ V_103 ] ;
struct V_98 * V_99 ;
unsigned long V_11 ;
T_1 V_115 , V_92 = 0xffffffff ;
int V_5 = - V_93 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
F_50 ( V_2 -> V_54 , V_116 ,
V_117 ) ;
V_115 = V_2 -> V_118 . V_119 ;
if ( F_51 ( V_115 ) ) {
F_52 ( & V_2 -> V_54 -> V_120 , V_11 ) ;
V_5 = F_53 ( V_2 -> V_54 ) ;
if ( F_54 ( V_5 == 0 ) ) {
F_50 ( V_2 -> V_54 , V_121 , V_115 ) ;
V_92 = F_55 ( V_2 -> V_54 , V_122 ) ;
F_56 ( V_2 -> V_54 ) ;
}
F_57 ( & V_2 -> V_54 -> V_120 , V_11 ) ;
#ifdef F_58
if ( V_5 == 0 ) {
const struct V_123 * V_50 ;
V_50 = & ( V_2 -> V_49 -> V_50 [ V_51 ] ) ;
if ( ! V_2 -> V_124 ) {
V_2 -> V_124 =
F_59 ( V_50 -> V_52 [ V_125 ] . V_53 ,
V_126 ) ;
}
if ( V_2 -> V_124 )
F_60 (
V_2 -> V_54 , 0x800000 ,
V_2 -> V_124 ,
V_50 -> V_52 [ V_125 ] . V_53 / 4 ) ;
}
#endif
}
V_99 = V_9 -> V_99 ;
V_2 -> V_58 = false ;
F_45 ( V_2 -> V_54 -> V_57 , false ) ;
F_47 ( V_2 ) ;
memset ( ( void * ) & V_9 -> V_127 , 0 , sizeof( V_9 -> V_127 ) ) ;
F_61 ( V_2 , V_9 ) ;
F_62 ( V_2 , V_9 ) ;
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
F_63 ( V_99 ) ;
return 1 ;
}
void F_64 ( struct V_6 * V_7 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_65 ( V_2 , L_10 , V_129 -> V_53 ,
F_66 ( V_7 , F_67 ( V_129 ) ) -> V_130 ) ;
if ( F_68 ( V_2 , V_129 ) )
F_69 ( V_129 ) ;
}
void F_70 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_131 * V_132 ,
struct V_133 * V_134 ,
T_1 V_135 , T_2 * V_136 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_71 ( V_2 , V_99 , V_132 , V_134 , V_135 , V_136 ) ;
}
int F_72 ( struct V_6 * V_7 , enum V_137 V_138 ,
struct V_98 * V_99 ,
struct V_133 * V_134 ,
struct V_131 * V_139 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_140 = ( void * ) V_99 -> V_141 ;
struct V_8 * V_9 = V_140 -> V_9 ;
int V_5 ;
bool V_142 = false ;
F_29 ( V_2 , L_7 ) ;
if ( V_63 . V_64 ) {
F_29 ( V_2 , L_11 ) ;
return - V_143 ;
}
switch ( V_139 -> V_144 ) {
case V_145 :
V_139 -> V_11 |= V_146 ;
case V_147 :
V_139 -> V_11 |= V_148 ;
break;
default:
break;
}
if ( V_99 -> type == V_149 &&
! ( V_139 -> V_11 & V_150 ) ) {
V_139 -> V_151 = V_152 ;
return 0 ;
}
if ( V_138 == V_153 && V_139 -> V_151 == V_152 )
return 0 ;
F_30 ( & V_2 -> V_90 ) ;
F_73 ( V_2 , 100 ) ;
F_4 ( V_152 == V_154 ) ;
if ( ( V_139 -> V_144 == V_155 ||
V_139 -> V_144 == V_156 ) && ! V_134 ) {
if ( V_138 == V_157 )
V_142 = ! V_9 -> V_158 ;
else
V_142 =
V_139 -> V_151 == V_154 ;
}
switch ( V_138 ) {
case V_157 :
if ( V_142 ) {
V_5 = F_74 ( V_2 , V_140 -> V_9 , V_139 ) ;
break;
}
V_5 = F_75 ( V_2 , V_140 -> V_9 , V_139 , V_134 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_139 -> V_151 = V_152 ;
}
F_29 ( V_2 , L_12 ) ;
break;
case V_153 :
if ( V_142 )
V_5 = F_76 ( V_2 , V_9 , V_139 ) ;
else
V_5 = F_77 ( V_2 , V_9 , V_139 , V_134 ) ;
F_29 ( V_2 , L_13 ) ;
break;
default:
V_5 = - V_113 ;
}
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
int F_78 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
enum V_159 V_160 ,
struct V_133 * V_134 , T_2 V_161 , T_2 * V_162 ,
T_3 V_163 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 = - V_113 ;
struct V_32 * V_164 = ( void * ) V_134 -> V_141 ;
F_79 ( V_2 , L_14 ,
V_134 -> V_165 , V_161 ) ;
if ( ! ( V_2 -> V_24 . V_25 & V_26 ) )
return - V_166 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
switch ( V_160 ) {
case V_167 :
if ( V_63 . V_168 & V_169 )
break;
F_79 ( V_2 , L_15 ) ;
V_5 = F_80 ( V_2 , V_134 , V_161 , * V_162 ) ;
break;
case V_170 :
F_79 ( V_2 , L_16 ) ;
V_5 = F_81 ( V_2 , V_134 , V_161 ) ;
break;
case V_171 :
if ( ! V_2 -> V_54 -> V_55 -> V_172 )
break;
if ( V_63 . V_168 & V_173 )
break;
F_79 ( V_2 , L_17 ) ;
V_5 = F_82 ( V_2 , V_99 , V_134 , V_161 , V_162 ) ;
break;
case V_174 :
F_79 ( V_2 , L_18 ) ;
V_5 = F_83 ( V_2 , V_99 , V_134 , V_161 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_175 > 0 ) ) {
V_2 -> V_175 -- ;
F_79 ( V_2 , L_19 ,
V_2 -> V_175 ) ;
}
if ( ! V_2 -> V_175 &&
V_2 -> V_24 . V_176 ) {
V_164 -> V_177 . V_178 . V_179 . V_11 &=
~ V_180 ;
F_84 ( V_2 , F_85 ( V_99 ) ,
& V_164 -> V_177 . V_178 , V_181 , false ) ;
}
break;
case V_182 :
V_5 = F_86 ( V_2 , V_99 , V_134 , V_161 , V_163 ) ;
break;
}
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_32 * V_164 = ( void * ) V_134 -> V_141 ;
struct V_34 * V_140 = ( void * ) V_99 -> V_141 ;
bool V_183 = V_99 -> type == V_114 ;
int V_5 ;
T_3 V_184 ;
F_32 ( V_2 , L_20 ,
V_134 -> V_165 ) ;
V_164 -> V_184 = V_185 ;
F_88 ( & V_164 -> V_186 , 0 ) ;
if ( V_99 -> type == V_43 )
V_164 -> V_187 = true ;
V_5 = F_89 ( V_2 , V_140 -> V_9 , V_134 -> V_165 ,
V_183 , V_134 , & V_184 ) ;
if ( V_5 ) {
F_11 ( V_2 , L_21 ,
V_134 -> V_165 , V_5 ) ;
return V_5 ;
}
V_164 -> V_184 = V_184 ;
return 0 ;
}
static int F_90 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_32 * V_164 = ( void * ) V_134 -> V_141 ;
int V_5 ;
F_32 ( V_2 , L_22 , V_134 -> V_165 ) ;
if ( V_99 -> type == V_114 ) {
V_5 = 0 ;
F_91 ( V_2 , V_164 -> V_184 , V_134 -> V_165 ) ;
} else {
V_5 = F_92 ( V_2 , V_164 -> V_184 , V_134 -> V_165 ) ;
if ( V_5 )
F_93 ( V_2 ,
L_23 , V_134 -> V_165 ) ;
}
return V_5 ;
}
int F_94 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_133 * V_134 ,
enum V_188 V_189 ,
enum V_188 V_190 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_140 = ( void * ) V_99 -> V_141 ;
enum {
V_191 , V_192 , REMOVE , V_193 , V_194 ,
} V_195 = V_191 ;
int V_5 ;
F_29 ( V_2 , L_24 ,
V_134 -> V_165 , V_189 , V_190 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( V_99 -> type == V_114 ) {
if ( V_189 == V_196 &&
V_190 == V_197 )
V_195 = V_192 ;
else if ( V_189 == V_197 &&
V_190 == V_196 )
V_195 = REMOVE ;
else if ( V_189 == V_198 &&
V_190 == V_199 )
V_195 = V_193 ;
} else {
if ( V_189 == V_198 &&
V_190 == V_199 )
V_195 = V_194 ;
else if ( V_189 == V_199 &&
V_190 == V_198 )
V_195 = REMOVE ;
}
switch ( V_195 ) {
case V_192 :
V_5 = F_87 ( V_7 , V_99 , V_134 ) ;
if ( V_5 )
break;
F_95 ( & V_2 -> V_200 ) ;
V_2 -> V_201 [ F_96 ( V_134 ) ] . V_202 &=
~ V_203 ;
F_97 ( & V_2 -> V_200 ) ;
break;
case REMOVE :
V_5 = F_90 ( V_7 , V_99 , V_134 ) ;
break;
case V_194 :
V_5 = F_87 ( V_7 , V_99 , V_134 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_134 -> V_165 ) ;
F_98 ( V_2 , V_134 , F_96 ( V_134 ) ) ;
V_5 = 0 ;
break;
case V_193 :
V_5 = F_99 ( V_2 , V_140 -> V_9 , V_134 ) ;
if ( V_5 )
break;
F_32 ( V_2 ,
L_25 ,
V_134 -> V_165 ) ;
F_98 ( V_2 , V_134 , F_96 ( V_134 ) ) ;
V_5 = 0 ;
break;
default:
V_5 = 0 ;
break;
}
if ( F_100 ( V_2 ) )
V_5 = 0 ;
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_5 ;
}
void F_101 ( struct V_6 * V_7 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
const struct V_206 * V_207 ;
struct V_208 * V_209 = & V_7 -> V_209 ;
struct V_210 * V_211 = V_205 -> V_211 ;
struct V_212 * V_213 = & V_2 -> V_214 ;
struct V_8 * V_9 = & V_2 -> V_102 [ V_103 ] ;
T_2 V_215 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( F_100 ( V_2 ) )
goto V_104;
if ( F_17 ( V_91 , & V_2 -> V_92 ) ||
F_17 ( V_216 , & V_2 -> V_92 ) ||
F_17 ( V_217 , & V_2 -> V_92 ) )
goto V_104;
if ( ! F_43 ( V_9 ) )
goto V_104;
if ( ! V_2 -> V_218 -> V_219 )
goto V_104;
V_215 = V_211 -> V_220 ;
if ( F_102 ( V_9 -> V_127 . V_211 ) == V_215 )
goto V_104;
V_207 = F_103 ( V_2 , V_211 -> V_221 , V_215 ) ;
if ( ! F_104 ( V_207 ) ) {
F_29 ( V_2 , L_26 ) ;
goto V_104;
}
V_2 -> V_214 . V_222 = V_209 -> V_223 ;
V_9 -> V_224 . V_225 = F_105 ( V_209 ) ;
if ( V_9 -> V_224 . V_225 )
F_106 ( V_209 , V_9 ) ;
else
V_9 -> V_224 . V_226 = false ;
if ( ( F_102 ( V_9 -> V_227 . V_211 ) != V_215 ) )
V_9 -> V_227 . V_11 = 0 ;
F_107 ( V_2 , V_211 , V_9 ) ;
F_108 ( V_2 , V_213 ) ;
F_109 ( V_2 , V_9 , V_211 -> V_221 , V_9 -> V_99 ) ;
F_24 ( V_217 , & V_2 -> V_92 ) ;
V_2 -> V_228 = F_110 ( V_215 ) ;
if ( V_2 -> V_218 -> V_219 ( V_2 , V_205 ) ) {
F_26 ( V_217 , & V_2 -> V_92 ) ;
V_2 -> V_228 = 0 ;
F_111 ( V_9 -> V_99 , false ) ;
}
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
}
void F_112 ( struct V_1 * V_2 , bool V_229 )
{
struct V_8 * V_9 = & V_2 -> V_102 [ V_103 ] ;
if ( F_17 ( V_91 , & V_2 -> V_92 ) )
return;
if ( F_113 ( V_217 , & V_2 -> V_92 ) )
F_111 ( V_9 -> V_99 , V_229 ) ;
}
void F_114 ( struct V_6 * V_7 ,
unsigned int V_230 ,
unsigned int * V_231 ,
T_4 V_232 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
T_5 V_233 = 0 , V_234 = 0 ;
struct V_8 * V_9 ;
#define F_115 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_29 ( V_2 , L_27 ,
V_230 , * V_231 ) ;
F_115 ( V_235 | V_236 , V_237 ) ;
F_115 ( V_238 , V_239 | V_237 ) ;
F_115 ( V_240 , V_241 ) ;
#undef F_115
F_30 ( & V_2 -> V_90 ) ;
F_3 (priv, ctx) {
V_9 -> V_227 . V_242 &= ~ V_234 ;
V_9 -> V_227 . V_242 |= V_233 ;
}
F_31 ( & V_2 -> V_90 ) ;
* V_231 &= V_235 | V_243 | V_236 |
V_240 | V_238 ;
}
void F_116 ( struct V_6 * V_7 , bool V_244 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_7 ) ;
if ( F_17 ( V_91 , & V_2 -> V_92 ) ) {
F_65 ( V_2 , L_28 ) ;
goto V_245;
}
if ( F_100 ( V_2 ) ) {
F_65 ( V_2 , L_29 ) ;
goto V_245;
}
if ( V_244 ) {
F_29 ( V_2 , L_30 ) ;
if ( F_117 ( V_2 , V_246 ) ) {
F_11 ( V_2 , L_31 ) ;
goto V_245;
}
}
F_29 ( V_2 , L_32 ) ;
F_118 ( V_2 -> V_54 ) ;
V_245:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_119 ( struct V_6 * V_7 ,
struct V_210 * V_211 ,
enum V_247 V_248 ,
int V_249 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_102 [ V_250 ] ;
int V_251 = 0 ;
if ( ! ( V_2 -> V_252 & F_5 ( V_250 ) ) )
return - V_143 ;
if ( ! ( V_9 -> V_36 & F_5 ( V_39 ) ) )
return - V_143 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( F_17 ( V_253 , & V_2 -> V_92 ) ) {
V_251 = - V_254 ;
goto V_104;
}
V_2 -> V_255 = V_211 ;
V_2 -> V_256 = V_248 ;
V_2 -> V_257 = F_120 ( 1000 * V_249 , 1024 ) ;
V_2 -> V_258 = false ;
F_121 ( & V_2 -> V_259 ) ;
if ( ! V_9 -> V_260 ) {
static const struct V_261 V_262 = {
. V_263 = {
. V_264 [ 0 ] = {
. V_265 = F_110 ( 3 ) ,
. V_266 = F_110 ( 7 ) ,
. V_267 = 2 ,
. V_268 = F_110 ( 1504 ) ,
} ,
. V_264 [ 1 ] = {
. V_265 = F_110 ( 7 ) ,
. V_266 = F_110 ( 15 ) ,
. V_267 = 2 ,
. V_268 = F_110 ( 3008 ) ,
} ,
. V_264 [ 2 ] = {
. V_265 = F_110 ( 15 ) ,
. V_266 = F_110 ( 1023 ) ,
. V_267 = 3 ,
} ,
. V_264 [ 3 ] = {
. V_265 = F_110 ( 15 ) ,
. V_266 = F_110 ( 1023 ) ,
. V_267 = 7 ,
} ,
} ,
} ;
V_9 -> V_260 = true ;
V_9 -> V_269 = V_262 ;
V_9 -> V_227 . V_270 = V_271 ;
memcpy ( V_9 -> V_227 . V_272 ,
V_2 -> V_102 [ V_103 ] . V_227 . V_272 ,
V_273 ) ;
memcpy ( V_9 -> V_227 . V_274 ,
V_2 -> V_102 [ V_103 ] . V_227 . V_272 ,
V_273 ) ;
V_251 = F_122 ( V_2 , V_9 ) ;
if ( V_251 )
goto V_104;
V_9 -> V_227 . V_242 |= V_275 |
V_237 |
V_239 ;
V_251 = F_122 ( V_2 , V_9 ) ;
if ( V_251 ) {
F_123 ( V_2 ) ;
goto V_104;
}
V_2 -> V_276 = true ;
}
V_251 = F_124 ( V_2 , V_9 -> V_99 , V_277 , V_211 -> V_221 ) ;
if ( V_251 )
F_123 ( V_2 ) ;
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_251 ;
}
int F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
if ( ! ( V_2 -> V_252 & F_5 ( V_250 ) ) )
return - V_143 ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
F_73 ( V_2 , V_2 -> V_257 ) ;
F_123 ( V_2 ) ;
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
void F_126 ( struct V_6 * V_7 ,
enum V_278 V_279 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_280 -> V_281 &&
V_2 -> V_280 -> V_281 -> V_282 ) {
if ( V_279 == V_283 )
V_2 -> V_284 = true ;
else if ( V_279 == V_285 )
V_2 -> V_284 = false ;
F_127 ( V_2 ) ;
} else {
F_29 ( V_2 , L_33
L_34 ) ;
}
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
}
int F_128 ( struct V_6 * V_7 ,
struct V_133 * V_134 , bool V_286 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_129 ( V_2 -> V_97 , & V_2 -> V_287 ) ;
return 0 ;
}
int F_130 ( struct V_6 * V_7 ,
struct V_98 * V_99 , T_2 V_288 ,
const struct V_289 * V_290 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_140 = ( void * ) V_99 -> V_141 ;
struct V_8 * V_9 = V_140 -> V_9 ;
int V_291 ;
if ( F_33 ( ! V_9 ) )
return - V_113 ;
F_29 ( V_2 , L_7 ) ;
if ( ! F_131 ( V_2 ) ) {
F_29 ( V_2 , L_35 ) ;
return - V_93 ;
}
if ( V_288 >= V_292 ) {
F_29 ( V_2 , L_36 , V_288 ) ;
return 0 ;
}
V_291 = V_292 - 1 - V_288 ;
F_30 ( & V_2 -> V_90 ) ;
V_9 -> V_269 . V_263 . V_264 [ V_291 ] . V_265 =
F_110 ( V_290 -> V_265 ) ;
V_9 -> V_269 . V_263 . V_264 [ V_291 ] . V_266 =
F_110 ( V_290 -> V_266 ) ;
V_9 -> V_269 . V_263 . V_264 [ V_291 ] . V_267 = V_290 -> V_293 ;
V_9 -> V_269 . V_263 . V_264 [ V_291 ] . V_268 =
F_110 ( ( V_290 -> V_294 * 32 ) ) ;
V_9 -> V_269 . V_263 . V_264 [ V_291 ] . V_295 = 0 ;
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return 0 ;
}
int F_132 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
return V_2 -> V_296 == V_297 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_61 ( V_2 , V_9 ) ;
F_62 ( V_2 , V_9 ) ;
return F_122 ( V_2 , V_9 ) ;
}
int F_134 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_98 * V_99 = V_9 -> V_99 ;
int V_251 , V_264 ;
F_16 ( & V_2 -> V_90 ) ;
V_2 -> V_298 = V_99 -> type ;
V_9 -> V_260 = true ;
V_251 = F_133 ( V_2 , V_9 ) ;
if ( V_251 ) {
if ( ! V_9 -> V_299 )
V_9 -> V_260 = false ;
return V_251 ;
}
if ( V_2 -> V_280 -> V_281 && V_2 -> V_280 -> V_281 -> V_282 &&
V_99 -> type == V_149 ) {
V_2 -> V_300 = V_301 ;
}
for ( V_264 = 0 ; V_264 < V_302 ; V_264 ++ )
V_99 -> V_303 [ V_264 ] = V_9 -> V_304 [ V_264 ] ;
if ( V_99 -> type == V_43 )
V_99 -> V_305 = V_9 -> V_306 ;
else
V_99 -> V_305 = V_307 ;
return 0 ;
}
static int F_135 ( struct V_6 * V_7 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_34 * V_140 = ( void * ) V_99 -> V_141 ;
struct V_8 * V_308 , * V_9 = NULL ;
int V_251 ;
enum V_309 V_310 = F_136 ( V_99 ) ;
bool V_311 = false ;
F_29 ( V_2 , L_37 ,
V_310 , V_99 -> V_165 ) ;
F_137 ( & V_2 -> V_259 ) ;
F_30 ( & V_2 -> V_90 ) ;
F_123 ( V_2 ) ;
if ( ! F_131 ( V_2 ) ) {
F_18 ( V_2 , L_38 ) ;
V_251 = - V_113 ;
goto V_104;
}
F_3 (priv, tmp) {
T_1 V_312 =
V_308 -> V_36 | V_308 -> V_37 ;
if ( V_308 -> V_99 ) {
if ( V_308 -> V_99 == V_99 ) {
V_311 = true ;
V_9 = V_308 ;
break;
}
if ( V_308 -> V_37 &
F_5 ( V_308 -> V_99 -> type ) ) {
V_251 = - V_113 ;
goto V_104;
}
continue;
}
if ( ! ( V_312 & F_5 ( V_310 ) ) )
continue;
V_9 = V_308 ;
break;
}
if ( ! V_9 ) {
V_251 = - V_143 ;
goto V_104;
}
V_140 -> V_9 = V_9 ;
V_9 -> V_99 = V_99 ;
V_251 = F_134 ( V_2 , V_9 ) ;
if ( ! V_251 || V_311 )
goto V_104;
V_9 -> V_99 = NULL ;
V_2 -> V_298 = V_114 ;
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_251 ;
}
void F_138 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
bool V_313 )
{
struct V_8 * V_9 = F_85 ( V_99 ) ;
F_16 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_314 == V_99 ) {
F_73 ( V_2 , 200 ) ;
F_139 ( V_2 ) ;
}
if ( ! V_313 ) {
F_133 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_299 )
V_9 -> V_260 = false ;
}
if ( V_99 -> type == V_149 )
V_2 -> V_300 = V_2 -> V_315 ;
}
static void F_140 ( struct V_6 * V_7 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = F_85 ( V_99 ) ;
F_29 ( V_2 , L_7 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( F_33 ( V_9 -> V_99 != V_99 ) ) {
struct V_8 * V_308 ;
F_11 ( V_2 , L_39 , V_9 -> V_99 , V_99 ) ;
F_3 (priv, tmp)
F_11 ( V_2 , L_40 ,
V_308 -> V_316 , V_308 , V_308 -> V_99 ) ;
}
V_9 -> V_99 = NULL ;
F_138 ( V_2 , V_99 , false ) ;
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
}
static int F_141 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
enum V_309 V_317 , bool V_318 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_8 * V_9 = F_85 ( V_99 ) ;
struct V_8 * V_319 = & V_2 -> V_102 [ V_103 ] ;
struct V_8 * V_308 ;
enum V_309 V_320 = V_317 ;
T_1 V_36 ;
int V_251 ;
F_29 ( V_2 , L_7 ) ;
V_317 = F_142 ( V_317 , V_318 ) ;
F_30 ( & V_2 -> V_90 ) ;
if ( ! V_9 -> V_99 || ! F_131 ( V_2 ) ) {
V_251 = - V_254 ;
goto V_104;
}
V_36 = V_9 -> V_36 | V_9 -> V_37 ;
if ( ! ( V_36 & F_5 ( V_317 ) ) ) {
V_251 = - V_254 ;
goto V_104;
}
if ( V_9 -> V_316 == V_250 && ! V_319 -> V_99 &&
( V_319 -> V_36 & F_5 ( V_317 ) ||
V_319 -> V_37 & F_5 ( V_317 ) ) ) {
F_4 ( V_38 != 2 ) ;
V_251 = - V_254 ;
goto V_104;
}
if ( V_9 -> V_37 & F_5 ( V_317 ) ) {
F_3 (priv, tmp) {
if ( V_9 == V_308 )
continue;
if ( ! V_308 -> V_99 )
continue;
V_251 = - V_254 ;
goto V_104;
}
}
F_138 ( V_2 , V_99 , true ) ;
V_99 -> type = V_320 ;
V_99 -> V_321 = V_318 ;
V_251 = F_134 ( V_2 , V_9 ) ;
F_33 ( V_251 ) ;
V_251 = 0 ;
V_104:
F_31 ( & V_2 -> V_90 ) ;
F_29 ( V_2 , L_9 ) ;
return V_251 ;
}
int F_143 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_322 * V_323 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
int V_5 ;
F_29 ( V_2 , L_7 ) ;
if ( V_323 -> V_85 == 0 )
return - V_113 ;
F_30 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_324 != V_325 ) {
F_144 ( V_2 ,
L_41 ) ;
V_2 -> V_326 = V_323 ;
V_2 -> V_314 = V_99 ;
V_5 = 0 ;
} else {
V_2 -> V_326 = V_323 ;
V_2 -> V_314 = V_99 ;
V_5 = F_124 ( V_2 , V_99 , V_325 ,
V_323 -> V_327 [ 0 ] -> V_221 ) ;
if ( V_5 ) {
V_2 -> V_326 = NULL ;
V_2 -> V_314 = NULL ;
}
}
F_29 ( V_2 , L_9 ) ;
F_31 ( & V_2 -> V_90 ) ;
return V_5 ;
}
static void F_145 ( struct V_1 * V_2 , int V_184 )
{
struct V_328 V_138 = {
. V_329 = V_330 ,
. V_331 = V_332 ,
. V_134 . V_184 = V_184 ,
} ;
F_146 ( V_2 , & V_138 , V_181 ) ;
}
void F_147 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
enum V_333 V_138 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
struct V_32 * V_164 = ( void * ) V_134 -> V_141 ;
int V_184 ;
F_29 ( V_2 , L_7 ) ;
switch ( V_138 ) {
case V_334 :
F_33 ( ! V_164 -> V_187 ) ;
V_164 -> V_335 = true ;
if ( F_148 ( & V_164 -> V_186 ) > 0 )
F_149 ( V_7 , V_134 , true ) ;
break;
case V_336 :
F_33 ( ! V_164 -> V_187 ) ;
if ( ! V_164 -> V_335 )
break;
V_164 -> V_335 = false ;
V_184 = F_96 ( V_134 ) ;
if ( V_184 != V_185 )
F_145 ( V_2 , V_184 ) ;
break;
default:
break;
}
F_29 ( V_2 , L_9 ) ;
}
struct V_6 * F_150 ( void )
{
struct V_1 * V_2 ;
struct V_337 * V_338 ;
struct V_6 * V_7 ;
V_7 = F_151 ( sizeof( struct V_1 ) +
sizeof( struct V_337 ) , & V_339 ) ;
if ( ! V_7 )
goto V_104;
V_338 = V_7 -> V_2 ;
V_2 = F_152 ( V_338 ) ;
V_2 -> V_7 = V_7 ;
V_104:
return V_7 ;
}
