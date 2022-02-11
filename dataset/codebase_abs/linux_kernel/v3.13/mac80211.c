static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_4 [ V_3 ] . V_6 = V_3 ;
V_2 -> V_4 [ V_3 ] . V_7 = 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 -> V_9 . V_10 & V_11 )
return V_2 -> V_8 -> V_9 . V_12 - 24 - 2 ;
return V_2 -> V_8 -> V_9 . V_12 - 24 - 34 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_15 , V_16 , V_3 ;
V_14 -> V_10 = V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ;
V_14 -> V_29 = V_2 -> V_30 ;
V_14 -> V_31 = V_32 ;
V_14 -> V_33 = L_1 ;
if ( V_2 -> V_8 -> V_9 . V_10 & V_34 &&
! V_35 . V_36 )
V_14 -> V_10 |= V_37 ;
if ( V_2 -> V_8 -> V_9 . V_10 & V_38 ) {
V_14 -> V_10 |= V_39 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_42 = V_43 ;
}
V_14 -> V_44 = sizeof( struct V_45 ) ;
V_14 -> V_46 = sizeof( struct V_47 ) ;
V_14 -> V_48 = sizeof( V_49 ) ;
V_14 -> V_50 -> V_51 = F_4 ( V_52 ) |
F_4 ( V_53 ) |
F_4 ( V_54 ) |
F_4 ( V_55 ) |
F_4 ( V_56 ) ;
if ( F_5 ( V_2 -> V_8 -> V_57 ) >= 8 )
V_14 -> V_50 -> V_51 |= F_4 ( V_58 ) ;
V_14 -> V_50 -> V_10 |= V_59 |
V_60 |
V_61 ;
V_14 -> V_50 -> V_62 = V_63 ;
V_14 -> V_50 -> V_64 =
F_6 ( V_63 ) ;
V_14 -> V_50 -> V_65 = 10000 ;
V_14 -> V_66 = V_67 ;
memcpy ( V_2 -> V_68 [ 0 ] . V_69 , V_2 -> V_70 -> V_71 , V_72 ) ;
V_14 -> V_50 -> V_68 = V_2 -> V_68 ;
V_14 -> V_50 -> V_73 = 1 ;
V_15 = ( V_2 -> V_70 -> V_74 > 1 ) ?
F_7 ( V_75 , V_2 -> V_70 -> V_74 ) : 1 ;
for ( V_3 = 1 ; V_3 < V_15 ; V_3 ++ ) {
memcpy ( V_2 -> V_68 [ V_3 ] . V_69 , V_2 -> V_68 [ V_3 - 1 ] . V_69 ,
V_72 ) ;
V_2 -> V_68 [ V_3 ] . V_69 [ 5 ] ++ ;
V_14 -> V_50 -> V_73 ++ ;
}
F_1 ( V_2 ) ;
V_14 -> V_50 -> V_76 = F_2 ( V_2 ) ;
V_14 -> V_50 -> V_77 = V_78 ;
if ( V_2 -> V_70 -> V_79 [ V_80 ] . V_81 )
V_14 -> V_50 -> V_79 [ V_80 ] =
& V_2 -> V_70 -> V_79 [ V_80 ] ;
if ( V_2 -> V_70 -> V_79 [ V_82 ] . V_81 )
V_14 -> V_50 -> V_79 [ V_82 ] =
& V_2 -> V_70 -> V_79 [ V_82 ] ;
V_14 -> V_50 -> V_83 = V_2 -> V_84 -> V_85 ;
if ( V_86 . V_87 != V_88 )
V_14 -> V_50 -> V_10 |= V_89 ;
else
V_14 -> V_50 -> V_10 &= ~ V_89 ;
if ( V_2 -> V_8 -> V_9 . V_10 & V_90 ) {
V_14 -> V_50 -> V_10 |= V_91 ;
V_14 -> V_50 -> V_92 = V_78 ;
V_14 -> V_50 -> V_93 = V_94 ;
V_14 -> V_50 -> V_95 =
V_96 - 24 - 2 ;
}
V_14 -> V_50 -> V_97 |= V_98 |
V_99 ;
V_2 -> V_100 = V_101 ;
#ifdef F_8
if ( V_2 -> V_8 -> V_102 [ V_103 ] . V_104 [ 0 ] . V_105 &&
V_2 -> V_84 -> V_106 -> V_107 &&
V_2 -> V_84 -> V_106 -> V_108 &&
F_9 ( V_2 -> V_84 -> V_109 ) ) {
V_2 -> V_110 . V_10 = V_111 |
V_112 |
V_113 |
V_114 ;
if ( ! V_35 . V_36 )
V_2 -> V_110 . V_10 |= V_115 |
V_116 |
V_117 ;
V_2 -> V_110 . V_118 = V_119 ;
V_2 -> V_110 . V_120 = V_121 ;
V_2 -> V_110 . V_122 = V_123 ;
V_2 -> V_110 . V_124 = & V_125 ;
V_14 -> V_50 -> V_110 = & V_2 -> V_110 ;
}
#endif
V_16 = F_10 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_11 ( V_2 -> V_14 ) ;
if ( V_16 )
F_12 ( V_2 ) ;
return V_16 ;
}
static void F_13 ( struct V_13 * V_14 ,
struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 , L_2 ) ;
goto V_130;
}
if ( F_17 ( V_129 ) -> V_131 == V_32 &&
! F_18 ( V_132 , & V_2 -> V_133 ) )
goto V_130;
if ( V_127 -> V_134 ) {
if ( F_19 ( V_2 , V_129 , V_127 -> V_134 ) )
goto V_130;
return;
}
if ( F_20 ( V_2 , V_129 ) )
goto V_130;
return;
V_130:
F_21 ( V_14 , V_129 ) ;
}
static int F_22 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
enum V_137 V_138 ,
struct V_139 * V_134 , V_49 V_140 ,
V_49 * V_141 , T_1 V_142 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_23 ( V_2 , L_3 ,
V_134 -> V_69 , V_140 , V_138 ) ;
if ( ! ( V_2 -> V_70 -> V_143 ) )
return - V_144 ;
F_24 ( & V_2 -> V_145 ) ;
switch ( V_138 ) {
case V_146 :
if ( V_35 . V_147 & V_148 ) {
V_16 = - V_149 ;
break;
}
V_16 = F_25 ( V_2 , V_134 , V_140 , * V_141 , true ) ;
break;
case V_150 :
V_16 = F_25 ( V_2 , V_134 , V_140 , 0 , false ) ;
break;
case V_151 :
if ( V_35 . V_147 & V_152 ) {
V_16 = - V_149 ;
break;
}
V_16 = F_26 ( V_2 , V_136 , V_134 , V_140 , V_141 ) ;
break;
case V_153 :
V_16 = F_27 ( V_2 , V_136 , V_134 , V_140 ) ;
break;
case V_154 :
case V_155 :
V_16 = F_28 ( V_2 , V_136 , V_134 , V_140 ) ;
break;
case V_156 :
V_16 = F_29 ( V_2 , V_136 , V_134 , V_140 , V_142 ) ;
break;
default:
F_30 ( 1 ) ;
V_16 = - V_149 ;
break;
}
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_32 ( void * V_157 , T_1 * V_158 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_157 ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
V_159 -> V_160 = false ;
V_159 -> V_161 = V_162 ;
V_159 -> V_163 ++ ;
F_34 ( & V_2 -> V_164 ) ;
F_35 ( V_2 , & V_159 -> V_165 ) ;
F_36 ( & V_2 -> V_164 ) ;
V_159 -> V_166 = NULL ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_84 ) ;
F_39 ( V_2 -> V_84 , false ) ;
V_2 -> V_167 = V_168 ;
F_40 ( V_2 -> V_14 ) ;
F_41 (
V_2 -> V_14 , V_169 ,
F_32 , V_2 ) ;
V_2 -> V_170 = NULL ;
F_1 ( V_2 ) ;
memset ( V_2 -> V_171 , 0 , sizeof( V_2 -> V_171 ) ) ;
memset ( V_2 -> V_172 , 0 , sizeof( V_2 -> V_172 ) ) ;
F_42 ( V_2 -> V_14 ) ;
V_2 -> V_173 = 0 ;
V_2 -> V_174 = 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
if ( F_18 ( V_175 , & V_2 -> V_133 ) )
F_37 ( V_2 ) ;
V_16 = F_44 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_45 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
F_46 ( V_175 , & V_2 -> V_133 ) ;
V_16 = F_47 ( V_2 , NULL ) ;
if ( V_16 )
F_48 ( V_2 , L_4 ,
V_16 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static void F_49 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_50 ( & V_2 -> V_176 ) ;
F_24 ( & V_2 -> V_145 ) ;
F_51 ( & V_2 -> V_177 ) ;
F_38 ( V_2 -> V_84 ) ;
F_39 ( V_2 -> V_84 , false ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , & V_2 -> V_178 ) ;
F_31 ( & V_2 -> V_145 ) ;
F_51 ( & V_2 -> V_176 ) ;
}
static void F_54 ( void * V_157 , T_1 * V_158 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_157 ;
int V_16 ;
V_16 = F_55 ( V_2 , V_136 ) ;
if ( V_16 )
F_48 ( V_2 , L_5 ) ;
}
static void F_56 ( void * V_157 , T_1 * V_158 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = V_157 ;
F_57 ( V_2 , V_136 ) ;
}
static struct V_179 * F_58 ( struct V_1 * V_2 )
{
V_49 V_3 ;
F_59 ( & V_2 -> V_145 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
if ( ! V_2 -> V_4 [ V_3 ] . V_7 )
return & V_2 -> V_4 [ V_3 ] ;
F_48 ( V_2 , L_6 ) ;
return NULL ;
}
static int F_60 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
V_16 = F_61 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_180;
if ( V_136 -> type != V_56 )
V_2 -> V_173 ++ ;
if ( V_2 -> V_173 > 1 ) {
F_62 ( V_2 ,
L_7 ) ;
F_41 (
V_2 -> V_14 ,
V_181 ,
F_54 , V_2 ) ;
}
if ( V_136 -> type == V_54 ||
V_136 -> type == V_58 ) {
T_2 V_182 = F_63 ( V_2 , V_136 ) ;
V_16 = F_64 ( V_2 , & V_159 -> V_183 ,
V_182 ) ;
if ( V_16 ) {
F_48 ( V_2 , L_8 ) ;
goto V_184;
}
F_65 ( V_2 , V_136 ) ;
goto V_180;
}
V_16 = F_66 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_184;
F_57 ( V_2 , V_136 ) ;
V_16 = F_67 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_185;
if ( ! V_2 -> V_186 &&
V_136 -> type == V_52 && ! V_136 -> V_187 &&
V_2 -> V_8 -> V_9 . V_10 & V_188 ) {
V_2 -> V_186 = V_159 ;
V_136 -> V_189 |= V_190 |
V_191 ;
}
if ( V_136 -> type == V_56 ) {
V_159 -> V_166 = F_58 ( V_2 ) ;
if ( ! V_159 -> V_166 ) {
V_16 = - V_192 ;
goto V_193;
}
F_68 ( V_2 , V_159 -> V_166 ) ;
V_16 = F_69 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_194;
V_16 = F_70 ( V_2 , V_136 , & V_159 -> V_183 ) ;
if ( V_16 )
goto V_195;
V_2 -> V_170 = V_136 ;
}
F_65 ( V_2 , V_136 ) ;
goto V_180;
V_195:
F_71 ( V_2 , V_136 ) ;
V_194:
F_72 ( V_2 , V_159 -> V_166 ) ;
V_193:
if ( V_2 -> V_186 == V_159 ) {
V_2 -> V_186 = NULL ;
V_136 -> V_189 &= ~ ( V_190 |
V_191 ) ;
}
V_185:
V_159 -> V_166 = NULL ;
F_73 ( V_2 , V_136 ) ;
V_184:
if ( V_136 -> type != V_56 )
V_2 -> V_173 -- ;
F_74 (
V_2 -> V_14 , V_181 ,
F_56 , V_2 ) ;
F_75 ( V_2 , V_136 ) ;
V_180:
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
T_2 V_196 = 0 , V_197 ;
for ( V_197 = 0 ; V_197 < V_198 ; V_197 ++ )
if ( V_136 -> V_131 [ V_197 ] != V_199 )
V_196 |= F_4 ( V_136 -> V_131 [ V_197 ] ) ;
if ( V_136 -> V_200 != V_199 )
V_196 |= F_4 ( V_136 -> V_200 ) ;
if ( V_196 ) {
F_24 ( & V_2 -> V_145 ) ;
F_77 ( V_2 , V_196 , true ) ;
F_31 ( & V_2 -> V_145 ) ;
}
if ( V_136 -> type == V_56 ) {
F_50 ( & V_2 -> V_177 ) ;
} else {
F_50 ( & V_2 -> V_201 ) ;
}
}
static void F_78 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
F_76 ( V_2 , V_136 ) ;
F_24 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_186 == V_159 ) {
V_2 -> V_186 = NULL ;
V_136 -> V_189 &= ~ ( V_190 |
V_191 ) ;
}
F_79 ( V_2 , V_136 ) ;
if ( V_136 -> type == V_54 ||
V_136 -> type == V_58 ) {
#ifdef F_80
if ( V_136 == V_2 -> V_202 ) {
V_2 -> V_202 = NULL ;
V_2 -> V_203 = 0 ;
}
#endif
F_53 ( V_2 , & V_159 -> V_183 ) ;
goto V_184;
}
if ( V_136 -> type == V_56 ) {
V_2 -> V_170 = NULL ;
F_81 ( V_2 , & V_159 -> V_183 ) ;
F_71 ( V_2 , V_136 ) ;
F_72 ( V_2 , V_159 -> V_166 ) ;
V_159 -> V_166 = NULL ;
}
if ( V_2 -> V_173 && V_136 -> type != V_56 )
V_2 -> V_173 -- ;
F_62 ( V_2 , L_9 ,
V_2 -> V_173 ) ;
if ( V_2 -> V_173 == 1 ) {
F_74 (
V_2 -> V_14 , V_181 ,
F_56 , V_2 ) ;
}
F_73 ( V_2 , V_136 ) ;
V_184:
F_75 ( V_2 , V_136 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_135 * V_136 ,
T_3 V_204 )
{
struct V_205 V_206 = {
. V_207 = F_33 ( V_136 ) -> V_6 ,
. V_208 = F_83 ( V_204 ) ,
} ;
return F_84 ( V_2 , V_209 , V_210 ,
sizeof( V_206 ) ,
& V_206 ) ;
}
static int F_85 ( struct V_13 * V_14 , T_2 V_211 )
{
return 0 ;
}
static void F_86 ( struct V_13 * V_14 ,
unsigned int V_212 ,
unsigned int * V_213 ,
T_4 V_214 )
{
* V_213 = 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_215 V_216 = {
. V_217 = 1 ,
} ;
memcpy ( V_216 . V_218 , V_136 -> V_219 . V_218 , V_72 ) ;
return F_84 ( V_2 , V_220 , V_210 ,
sizeof( V_216 ) ,
& V_216 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_221 * V_219 ,
T_2 V_222 )
{
struct V_47 * V_159 = F_33 ( V_136 ) ;
int V_16 ;
V_16 = F_89 ( V_2 , V_136 ) ;
if ( V_16 )
F_48 ( V_2 , L_10 , V_136 -> V_69 ) ;
if ( V_222 & V_223 ) {
if ( V_219 -> V_224 ) {
V_16 = F_47 ( V_2 , V_136 ) ;
if ( V_16 ) {
F_48 ( V_2 , L_11 ) ;
return;
}
F_87 ( V_2 , V_136 ) ;
if ( F_18 ( V_175 ,
& V_2 -> V_133 ) ) {
T_2 V_225 = ( 11 * V_136 -> V_219 . V_226 ) / 10 ;
F_90 ( V_2 , V_136 , V_225 , V_225 ,
5 * V_225 ) ;
}
} else if ( V_159 -> V_161 != V_162 ) {
V_16 = F_91 ( V_2 , V_136 , V_159 -> V_161 ) ;
if ( V_16 )
F_48 ( V_2 , L_12 ) ;
V_159 -> V_161 = V_162 ;
V_16 = F_47 ( V_2 , NULL ) ;
if ( V_16 )
F_48 ( V_2 , L_11 ) ;
}
V_159 -> V_227 . V_228 = 0 ;
if ( ! ( V_2 -> V_8 -> V_9 . V_10 &
V_229 ) ) {
V_16 = F_57 ( V_2 , V_136 ) ;
if ( V_16 )
F_48 ( V_2 , L_13 ) ;
}
F_92 ( V_2 ) ;
} else if ( V_222 & V_230 ) {
F_93 ( V_2 , V_159 ,
& V_159 -> V_165 ) ;
} else if ( V_222 & ( V_231 | V_232 ) ) {
V_16 = F_57 ( V_2 , V_136 ) ;
if ( V_16 )
F_48 ( V_2 , L_13 ) ;
}
if ( V_222 & V_233 ) {
F_94 ( V_2 , L_14 ,
V_219 -> V_234 ) ;
F_82 ( V_2 , V_136 , V_219 -> V_234 ) ;
}
if ( V_222 & V_235 ) {
F_62 ( V_2 , L_15 ) ;
V_159 -> V_227 . V_236 = 0 ;
V_16 = F_95 ( V_2 , V_136 ) ;
if ( V_16 )
F_48 ( V_2 , L_16 ) ;
}
}
static int F_96 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
V_16 = F_97 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_180;
V_16 = F_66 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_180;
V_16 = F_69 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_237;
V_159 -> V_238 = true ;
V_16 = F_98 ( V_2 , V_136 , & V_159 -> V_183 ) ;
if ( V_16 )
goto V_195;
V_16 = F_47 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_239;
if ( V_136 -> V_187 && V_2 -> V_170 )
F_89 ( V_2 , V_2 -> V_170 ) ;
F_92 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
return 0 ;
V_239:
F_99 ( V_2 , & V_159 -> V_183 ) ;
V_195:
F_71 ( V_2 , V_136 ) ;
V_237:
F_73 ( V_2 , V_136 ) ;
V_180:
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_100 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
F_76 ( V_2 , V_136 ) ;
F_24 ( & V_2 -> V_145 ) ;
V_159 -> V_238 = false ;
F_92 ( V_2 ) ;
if ( V_136 -> V_187 && V_2 -> V_170 )
F_89 ( V_2 , V_2 -> V_170 ) ;
F_47 ( V_2 , NULL ) ;
F_99 ( V_2 , & V_159 -> V_183 ) ;
F_71 ( V_2 , V_136 ) ;
F_73 ( V_2 , V_136 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static void
F_101 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_221 * V_219 ,
T_2 V_222 )
{
if ( V_222 & V_240 ) {
if ( F_97 ( V_2 , V_136 ) )
F_102 ( V_2 , L_17 ) ;
}
}
static void F_103 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_221 * V_219 ,
T_2 V_222 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_24 ( & V_2 -> V_145 ) ;
switch ( V_136 -> type ) {
case V_52 :
F_88 ( V_2 , V_136 , V_219 , V_222 ) ;
break;
case V_54 :
case V_58 :
F_101 ( V_2 , V_136 , V_219 , V_222 ) ;
break;
default:
F_30 ( 1 ) ;
}
F_31 ( & V_2 -> V_145 ) ;
}
static int F_104 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
if ( V_242 -> V_81 == 0 || V_242 -> V_81 > V_243 )
return - V_149 ;
F_24 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_167 == V_168 )
V_16 = F_105 ( V_2 , V_136 , V_242 ) ;
else
V_16 = - V_244 ;
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_106 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_24 ( & V_2 -> V_145 ) ;
F_107 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static void
F_108 ( struct V_13 * V_14 ,
struct V_139 * V_134 , V_49 V_140 ,
int V_245 ,
enum V_246 V_247 ,
bool V_248 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_109 ( V_2 , V_134 , V_247 , V_245 ) ;
}
static void F_110 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
enum V_249 V_250 ,
struct V_139 * V_134 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_45 * V_251 = ( void * ) V_134 -> V_252 ;
switch ( V_250 ) {
case V_253 :
if ( F_111 ( & V_2 -> V_254 [ V_251 -> V_255 ] ) > 0 )
F_112 ( V_14 , V_134 , true ) ;
break;
case V_256 :
if ( F_113 ( V_251 -> V_255 == V_162 ) )
break;
F_114 ( V_2 , V_134 ) ;
break;
default:
break;
}
}
static int F_115 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_139 * V_134 ,
enum V_257 V_258 ,
enum V_257 V_259 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
int V_16 ;
F_62 ( V_2 , L_18 ,
V_134 -> V_69 , V_258 , V_259 ) ;
if ( F_30 ( ! V_159 -> V_166 ) )
return - V_149 ;
F_50 ( & V_2 -> V_201 ) ;
F_24 ( & V_2 -> V_145 ) ;
if ( V_258 == V_260 &&
V_259 == V_261 ) {
if ( V_136 -> type == V_52 &&
V_136 -> V_219 . V_226 < 16 ) {
F_48 ( V_2 ,
L_19 ,
V_134 -> V_69 , V_136 -> V_219 . V_226 ) ;
V_16 = - V_149 ;
goto V_180;
}
V_16 = F_116 ( V_2 , V_136 , V_134 ) ;
} else if ( V_258 == V_261 &&
V_259 == V_262 ) {
V_16 = 0 ;
} else if ( V_258 == V_262 &&
V_259 == V_263 ) {
V_16 = F_117 ( V_2 , V_136 , V_134 ) ;
if ( V_16 == 0 )
F_118 ( V_2 , V_134 ,
V_159 -> V_166 -> V_264 -> V_265 ) ;
} else if ( V_258 == V_263 &&
V_259 == V_266 ) {
F_113 ( F_119 ( V_2 , V_136 ) ) ;
V_16 = 0 ;
} else if ( V_258 == V_266 &&
V_259 == V_263 ) {
F_113 ( F_67 ( V_2 , V_136 ) ) ;
V_16 = 0 ;
} else if ( V_258 == V_263 &&
V_259 == V_262 ) {
V_16 = 0 ;
} else if ( V_258 == V_262 &&
V_259 == V_261 ) {
V_16 = 0 ;
} else if ( V_258 == V_261 &&
V_259 == V_260 ) {
V_16 = F_120 ( V_2 , V_136 , V_134 ) ;
} else {
V_16 = - V_267 ;
}
V_180:
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static int F_121 ( struct V_13 * V_14 , T_2 V_268 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_2 -> V_100 = V_268 ;
return 0 ;
}
static int F_122 ( struct V_13 * V_14 ,
struct V_135 * V_136 , V_49 V_197 ,
const struct V_269 * V_270 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
V_159 -> V_271 [ V_197 ] = * V_270 ;
if ( V_136 -> type == V_56 ) {
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
V_16 = F_89 ( V_2 , V_136 ) ;
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
return 0 ;
}
static void F_123 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
T_2 V_272 = F_7 ( V_273 ,
200 + V_136 -> V_219 . V_226 ) ;
T_2 V_274 = F_7 ( V_275 ,
100 + V_136 -> V_219 . V_226 ) ;
if ( F_30 ( V_136 -> V_219 . V_224 ) )
return;
F_24 ( & V_2 -> V_145 ) ;
F_90 ( V_2 , V_136 , V_272 , V_274 , 500 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static int F_124 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_276 * V_242 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_167 != V_168 ) {
F_125 ( V_2 ,
L_20 ) ;
V_16 = - V_244 ;
goto V_279;
}
V_2 -> V_167 = V_280 ;
V_16 = F_126 ( V_2 , V_136 , V_242 , V_278 ) ;
if ( V_16 )
goto V_281;
V_16 = F_127 ( V_2 , V_242 ) ;
if ( V_16 )
goto V_281;
V_16 = F_128 ( V_2 , V_242 ) ;
if ( ! V_16 )
goto V_279;
V_281:
V_2 -> V_167 = V_168 ;
V_279:
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_129 ( struct V_13 * V_14 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_24 ( & V_2 -> V_145 ) ;
F_130 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static int F_131 ( struct V_13 * V_14 ,
enum V_282 V_250 ,
struct V_135 * V_136 ,
struct V_139 * V_134 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_16 ;
if ( V_35 . V_36 ) {
F_62 ( V_2 , L_21 ) ;
return - V_285 ;
}
switch ( V_284 -> V_286 ) {
case V_287 :
V_284 -> V_10 |= V_288 ;
case V_289 :
V_284 -> V_10 |= V_290 ;
break;
case V_291 :
F_30 ( ! ( V_14 -> V_10 & V_37 ) ) ;
break;
case V_292 :
case V_293 :
return 0 ;
default:
return - V_285 ;
}
F_24 ( & V_2 -> V_145 ) ;
switch ( V_250 ) {
case V_294 :
if ( ( V_136 -> type == V_58 ||
V_136 -> type == V_54 ) && ! V_134 ) {
V_16 = 0 ;
V_284 -> V_295 = V_296 ;
break;
}
F_62 ( V_2 , L_22 ) ;
V_16 = F_132 ( V_2 , V_136 , V_134 , V_284 , false ) ;
if ( V_16 ) {
F_102 ( V_2 , L_23 ) ;
V_284 -> V_295 = V_296 ;
V_16 = 0 ;
}
break;
case V_297 :
if ( V_284 -> V_295 == V_296 ) {
V_16 = 0 ;
break;
}
F_62 ( V_2 , L_24 ) ;
V_16 = F_133 ( V_2 , V_136 , V_134 , V_284 ) ;
break;
default:
V_16 = - V_149 ;
}
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_134 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_283 * V_298 ,
struct V_139 * V_134 ,
T_2 V_299 , V_49 * V_300 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( V_298 -> V_295 == V_296 )
return;
F_135 ( V_2 , V_136 , V_298 , V_134 , V_299 , V_300 ) ;
}
static int F_136 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_301 * V_264 ,
int V_272 ,
enum V_302 type )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
struct V_303 V_304 ;
struct V_179 * V_166 ;
int V_16 , V_3 ;
F_62 ( V_2 , L_25 , V_264 -> V_305 ,
V_272 , type ) ;
if ( V_136 -> type != V_56 ) {
F_48 ( V_2 , L_26 , V_136 -> type ) ;
return - V_149 ;
}
F_24 ( & V_2 -> V_145 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_166 = & V_2 -> V_4 [ V_3 ] ;
if ( V_166 -> V_7 == 0 || V_159 -> V_166 == V_166 )
continue;
if ( V_166 -> V_7 && V_264 == V_166 -> V_264 ) {
V_16 = F_71 ( V_2 , V_136 ) ;
if ( F_137 ( V_16 , L_27 ) )
goto V_180;
F_72 ( V_2 , V_159 -> V_166 ) ;
V_159 -> V_166 = V_166 ;
V_16 = F_69 ( V_2 , V_136 ) ;
if ( F_137 ( V_16 , L_28 ) )
goto V_180;
F_68 ( V_2 , V_159 -> V_166 ) ;
goto V_306;
}
}
if ( V_264 == V_159 -> V_166 -> V_264 )
goto V_306;
F_138 ( & V_304 , V_264 , V_307 ) ;
if ( V_159 -> V_166 -> V_7 == 1 ) {
V_16 = F_139 ( V_2 , V_159 -> V_166 ,
& V_304 , 1 , 1 ) ;
if ( V_16 )
goto V_180;
} else {
V_166 = F_58 ( V_2 ) ;
if ( ! V_166 ) {
V_16 = - V_192 ;
goto V_180;
}
V_16 = F_139 ( V_2 , V_166 , & V_304 ,
1 , 1 ) ;
if ( V_16 ) {
F_48 ( V_2 , L_29 ) ;
goto V_180;
}
V_16 = F_71 ( V_2 , V_136 ) ;
if ( F_137 ( V_16 , L_27 ) )
goto V_180;
F_72 ( V_2 , V_159 -> V_166 ) ;
V_159 -> V_166 = V_166 ;
V_16 = F_69 ( V_2 , V_136 ) ;
if ( F_137 ( V_16 , L_28 ) )
goto V_180;
F_68 ( V_2 , V_159 -> V_166 ) ;
}
V_306:
V_16 = F_140 ( V_2 , V_136 , V_272 , type ) ;
V_180:
F_31 ( & V_2 -> V_145 ) ;
F_62 ( V_2 , L_30 ) ;
return V_16 ;
}
static int F_141 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
F_62 ( V_2 , L_31 ) ;
F_24 ( & V_2 -> V_145 ) ;
F_142 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
F_62 ( V_2 , L_30 ) ;
return 0 ;
}
static int F_143 ( struct V_13 * V_14 ,
struct V_308 * V_309 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_310 = ( V_49 * ) V_309 -> V_252 ;
struct V_179 * V_166 ;
int V_16 ;
F_62 ( V_2 , L_32 ) ;
F_24 ( & V_2 -> V_145 ) ;
V_166 = F_58 ( V_2 ) ;
if ( ! V_166 ) {
V_16 = - V_192 ;
goto V_279;
}
V_16 = F_139 ( V_2 , V_166 , & V_309 -> V_311 ,
V_309 -> V_312 ,
V_309 -> V_313 ) ;
if ( V_16 ) {
F_48 ( V_2 , L_33 ) ;
goto V_279;
}
F_68 ( V_2 , V_166 ) ;
* V_310 = V_166 -> V_6 ;
V_279:
F_31 ( & V_2 -> V_145 ) ;
return V_16 ;
}
static void F_144 ( struct V_13 * V_14 ,
struct V_308 * V_309 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_310 = ( V_49 * ) V_309 -> V_252 ;
struct V_179 * V_166 = & V_2 -> V_4 [ * V_310 ] ;
F_24 ( & V_2 -> V_145 ) ;
F_72 ( V_2 , V_166 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static void F_145 ( struct V_13 * V_14 ,
struct V_308 * V_309 ,
T_2 V_211 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_310 = ( V_49 * ) V_309 -> V_252 ;
struct V_179 * V_166 = & V_2 -> V_4 [ * V_310 ] ;
if ( F_146 ( ( V_166 -> V_7 > 1 ) &&
( V_211 & ~ ( V_314 |
V_315 |
V_316 ) ) ,
L_34 ,
V_166 -> V_7 , V_211 ) )
return;
F_24 ( & V_2 -> V_145 ) ;
F_139 ( V_2 , V_166 , & V_309 -> V_311 ,
V_309 -> V_312 ,
V_309 -> V_313 ) ;
F_92 ( V_2 ) ;
F_31 ( & V_2 -> V_145 ) ;
}
static int F_147 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_308 * V_309 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
V_49 * V_310 = ( V_49 * ) V_309 -> V_252 ;
struct V_179 * V_166 = & V_2 -> V_4 [ * V_310 ] ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
int V_16 ;
F_24 ( & V_2 -> V_145 ) ;
V_159 -> V_166 = V_166 ;
switch ( V_136 -> type ) {
case V_54 :
case V_58 :
V_16 = 0 ;
goto V_180;
case V_52 :
case V_317 :
break;
default:
V_16 = - V_149 ;
goto V_180;
}
V_16 = F_69 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_180;
if ( V_136 -> type == V_317 ) {
V_159 -> V_318 = true ;
V_16 = F_47 ( V_2 , V_136 ) ;
if ( V_16 )
goto V_319;
}
goto V_180;
V_319:
F_71 ( V_2 , V_136 ) ;
V_180:
F_31 ( & V_2 -> V_145 ) ;
if ( V_16 )
V_159 -> V_166 = NULL ;
return V_16 ;
}
static void F_148 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
struct V_308 * V_309 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_47 * V_159 = F_33 ( V_136 ) ;
F_24 ( & V_2 -> V_145 ) ;
F_93 ( V_2 , V_159 , & V_159 -> V_165 ) ;
switch ( V_136 -> type ) {
case V_54 :
case V_58 :
goto V_180;
case V_317 :
V_159 -> V_318 = false ;
F_47 ( V_2 , NULL ) ;
break;
default:
break;
}
F_71 ( V_2 , V_136 ) ;
V_180:
V_159 -> V_166 = NULL ;
F_31 ( & V_2 -> V_145 ) ;
}
static int F_149 ( struct V_13 * V_14 ,
struct V_139 * V_134 ,
bool V_320 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_45 * V_321 = ( void * ) V_134 -> V_252 ;
if ( ! V_321 || ! V_321 -> V_136 ) {
F_48 ( V_2 , L_35 ) ;
return - V_149 ;
}
return F_97 ( V_2 , V_321 -> V_136 ) ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
void * V_157 , int V_105 )
{
struct V_322 * V_323 [ V_324 + 1 ] ;
int V_281 ;
T_2 V_203 ;
V_281 = F_151 ( V_323 , V_324 , V_157 , V_105 , V_325 ) ;
if ( V_281 )
return V_281 ;
if ( ! V_323 [ V_326 ] )
return - V_149 ;
switch ( F_152 ( V_323 [ V_326 ] ) ) {
case V_327 :
if ( ! V_136 || V_136 -> type != V_54 || ! V_136 -> V_187 ||
! V_136 -> V_219 . V_328 ||
! V_323 [ V_329 ] )
return - V_149 ;
V_203 = F_152 ( V_323 [ V_329 ] ) ;
if ( V_203 >= V_136 -> V_219 . V_226 )
return - V_149 ;
V_2 -> V_203 = V_203 ;
V_2 -> V_202 = V_136 ;
return F_47 ( V_2 , NULL ) ;
case V_330 :
if ( ! V_136 || V_136 -> type != V_52 ||
! V_136 -> V_219 . V_224 || ! V_136 -> V_219 . V_331 ||
! V_323 [ V_332 ] )
return - V_149 ;
if ( F_152 ( V_323 [ V_332 ] ) )
return F_119 ( V_2 , V_136 ) ;
return F_67 ( V_2 , V_136 ) ;
}
return - V_285 ;
}
static int F_153 ( struct V_13 * V_14 ,
struct V_135 * V_136 ,
void * V_157 , int V_105 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
int V_281 ;
F_24 ( & V_2 -> V_145 ) ;
V_281 = F_150 ( V_2 , V_136 , V_157 , V_105 ) ;
F_31 ( & V_2 -> V_145 ) ;
return V_281 ;
}
