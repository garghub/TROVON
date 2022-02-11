static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
if ( ! memcmp ( V_6 -> V_11 , V_6 -> V_12 , V_13 ) )
F_3 ( V_4 -> V_14 , V_6 -> V_11 ,
sizeof( V_4 -> V_14 ) ) ;
else
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) ,
L_1 , V_6 -> V_11 , V_6 -> V_12 ) ;
F_3 ( V_4 -> V_15 , F_4 ( V_6 -> V_16 ) ,
sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
}
static T_1 F_5 ( struct V_5 * V_6 , T_2 * V_20 )
{
T_1 V_21 = 0 , V_22 ;
T_2 V_23 ;
struct V_24 V_25 ;
int V_26 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_26 = F_6 ( V_6 , & V_25 , 0 , 0 ,
V_20 , & V_21 , & V_22 ,
& V_23 ) ;
return V_21 ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_20 ,
T_1 V_27 , void * V_28 )
{
struct V_24 V_29 ;
T_1 V_30 = 0 , V_31 = 0 , V_32 ;
T_1 V_22 = 0 ;
T_2 V_23 ;
int V_26 = 0 ;
V_29 . V_33 = V_34 ;
V_29 . V_35 = F_8 ( & V_6 -> V_16 -> V_36 , V_29 . V_33 ,
& V_29 . V_37 , V_38 ) ;
if ( ! V_29 . V_35 ) {
F_9 ( & V_6 -> V_16 -> V_36 ,
L_2 ) ;
return - V_39 ;
}
while ( ( V_31 < V_27 ) && ! V_22 ) {
V_32 = F_10 ( T_1 , ( V_27 - V_31 ) ,
V_34 ) ;
V_32 = F_11 ( V_32 , 4 ) ;
V_26 = F_6 ( V_6 , & V_29 , V_32 ,
V_31 , V_20 ,
& V_30 , & V_22 , & V_23 ) ;
if ( ! V_26 ) {
memcpy ( V_28 + V_31 , V_29 . V_35 , V_30 ) ;
V_31 += V_30 ;
V_22 &= V_40 ;
} else {
V_26 = - V_41 ;
break;
}
}
F_12 ( & V_6 -> V_16 -> V_36 , V_29 . V_33 , V_29 . V_35 ,
V_29 . V_37 ) ;
return V_26 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_42 = 0 ;
if ( ! F_14 ( V_6 , V_43 ) )
return 0 ;
if ( F_15 ( V_6 ) ) {
if ( F_16 ( V_6 ) )
V_42 = F_5 ( V_6 ,
V_44 ) ;
else
F_17 ( V_6 , & V_42 ) ;
}
return V_42 ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_45 * V_46 , void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_15 ( V_6 ) ) {
memset ( V_28 , 0 , V_46 -> V_47 ) ;
if ( F_16 ( V_6 ) )
F_7 ( V_6 , V_44 ,
V_46 -> V_47 , V_28 ) ;
else
F_19 ( V_6 , V_46 -> V_47 , V_28 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_50 * V_51 = & V_6 -> V_52 [ 0 ] ;
V_49 -> V_53 = V_51 -> V_54 ;
V_49 -> V_55 = V_51 -> V_56 ;
V_49 -> V_57 = V_51 -> V_58 ;
V_49 -> V_59 = V_51 -> V_54 ;
V_49 -> V_60 = V_51 -> V_56 ;
V_49 -> V_61 = V_51 -> V_58 ;
V_49 -> V_62 = V_51 -> V_63 ;
V_49 -> V_64 = V_51 -> V_63 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_50 * V_51 = & V_6 -> V_52 [ 0 ] ;
struct V_65 * V_66 ;
int V_67 ;
F_22 (adapter, eqo, i) {
V_51 -> V_63 = V_49 -> V_62 ;
V_51 -> V_56 = F_23 ( V_49 -> V_55 , V_68 ) ;
V_51 -> V_58 = F_23 ( V_49 -> V_57 , V_51 -> V_56 ) ;
V_51 -> V_69 = F_23 ( V_49 -> V_53 , V_51 -> V_56 ) ;
V_51 -> V_69 = F_24 ( V_51 -> V_69 , V_51 -> V_58 ) ;
V_51 ++ ;
}
if ( ! V_49 -> V_62 && F_25 ( V_6 ) )
F_26 ( V_6 , true ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_70 * V_71 , T_3 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
void * V_77 ;
unsigned int V_67 , V_78 , V_79 = 0 , V_80 ;
for ( V_67 = 0 ; V_67 < V_81 ; V_67 ++ ) {
V_77 = ( T_2 * ) & V_6 -> V_82 + V_83 [ V_67 ] . V_84 ;
V_72 [ V_67 ] = * ( T_1 * ) V_77 ;
}
V_79 += V_81 ;
F_28 (adapter, rxo, j) {
struct V_85 * V_71 = F_29 ( V_74 ) ;
do {
V_80 = F_30 ( & V_71 -> V_86 ) ;
V_72 [ V_79 ] = V_71 -> V_87 ;
V_72 [ V_79 + 1 ] = V_71 -> V_88 ;
} while ( F_31 ( & V_71 -> V_86 , V_80 ) );
for ( V_67 = 2 ; V_67 < V_89 ; V_67 ++ ) {
V_77 = ( T_2 * ) V_71 + V_90 [ V_67 ] . V_84 ;
V_72 [ V_79 + V_67 ] = * ( T_1 * ) V_77 ;
}
V_79 += V_89 ;
}
F_32 (adapter, txo, j) {
struct V_91 * V_71 = F_33 ( V_76 ) ;
do {
V_80 = F_30 ( & V_71 -> V_92 ) ;
V_72 [ V_79 ] = V_71 -> V_93 ;
} while ( F_31 ( & V_71 -> V_92 , V_80 ) );
do {
V_80 = F_30 ( & V_71 -> V_86 ) ;
for ( V_67 = 1 ; V_67 < V_94 ; V_67 ++ ) {
V_77 = ( T_2 * ) V_71 + V_95 [ V_67 ] . V_84 ;
V_72 [ V_79 + V_67 ] =
( V_95 [ V_67 ] . V_33 == sizeof( V_96 ) ) ?
* ( V_96 * ) V_77 : * ( T_1 * ) V_77 ;
}
} while ( F_31 ( & V_71 -> V_86 , V_80 ) );
V_79 += V_94 ;
}
}
static void F_34 ( struct V_1 * V_2 , T_4 V_97 ,
T_5 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_67 , V_78 ;
switch ( V_97 ) {
case V_98 :
for ( V_67 = 0 ; V_67 < V_81 ; V_67 ++ ) {
memcpy ( V_72 , V_83 [ V_67 ] . V_99 , V_100 ) ;
V_72 += V_100 ;
}
for ( V_67 = 0 ; V_67 < V_6 -> V_101 ; V_67 ++ ) {
for ( V_78 = 0 ; V_78 < V_89 ; V_78 ++ ) {
sprintf ( V_72 , L_3 , V_67 ,
V_90 [ V_78 ] . V_99 ) ;
V_72 += V_100 ;
}
}
for ( V_67 = 0 ; V_67 < V_6 -> V_102 ; V_67 ++ ) {
for ( V_78 = 0 ; V_78 < V_94 ; V_78 ++ ) {
sprintf ( V_72 , L_4 , V_67 ,
V_95 [ V_78 ] . V_99 ) ;
V_72 += V_100 ;
}
}
break;
case V_103 :
for ( V_67 = 0 ; V_67 < V_104 ; V_67 ++ ) {
memcpy ( V_72 , V_105 [ V_67 ] , V_100 ) ;
V_72 += V_100 ;
}
break;
}
}
static int F_35 ( struct V_1 * V_2 , int V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_97 ) {
case V_103 :
return V_104 ;
case V_98 :
return V_81 +
V_6 -> V_101 * V_89 +
V_6 -> V_102 * V_94 ;
default:
return - V_106 ;
}
}
static T_1 F_36 ( struct V_5 * V_6 )
{
T_1 V_107 ;
switch ( V_6 -> V_108 . V_109 ) {
case V_110 :
case V_111 :
case V_112 :
V_107 = V_113 ;
break;
case V_114 :
if ( V_6 -> V_108 . V_115 & V_116 )
V_107 = V_117 ;
else
V_107 = V_118 ;
break;
case V_119 :
if ( V_6 -> V_108 . V_115 & V_120 )
V_107 = V_117 ;
else
V_107 = V_118 ;
break;
case V_121 :
case V_122 :
V_107 = V_118 ;
break;
case V_123 :
V_107 = V_113 ;
break;
default:
V_107 = V_124 ;
}
return V_107 ;
}
static T_1 F_37 ( struct V_5 * V_6 , T_1 V_125 )
{
T_1 V_126 = 0 ;
switch ( V_6 -> V_108 . V_109 ) {
case V_110 :
case V_111 :
case V_112 :
V_126 |= V_127 ;
if ( V_125 & V_128 )
V_126 |= V_129 ;
if ( V_125 & V_130 )
V_126 |= V_131 ;
if ( V_125 & V_132 )
V_126 |= V_133 ;
break;
case V_134 :
V_126 |= V_135 ;
if ( V_125 & V_128 )
V_126 |= V_136 ;
if ( V_125 & V_137 )
V_126 |= V_138 ;
break;
case V_139 :
V_126 |= V_135 ;
if ( V_125 & V_137 )
V_126 |= V_140 ;
if ( V_125 & V_141 )
V_126 |= V_142 ;
break;
case V_143 :
V_126 |= V_135 |
V_140 ;
break;
case V_144 :
V_126 |= V_135 ;
if ( V_125 & V_137 )
V_126 |= V_140 ;
if ( V_125 & V_145 )
V_126 |= V_146 ;
break;
case V_119 :
if ( V_125 & V_145 ) {
switch ( V_6 -> V_108 . V_115 ) {
case V_120 :
V_126 |= V_147 ;
break;
case V_148 :
V_126 |= V_149 ;
break;
default:
V_126 |= V_150 ;
break;
}
}
case V_114 :
case V_121 :
case V_122 :
V_126 |= V_151 ;
if ( V_125 & V_137 )
V_126 |= V_152 ;
if ( V_125 & V_128 )
V_126 |= V_129 ;
break;
case V_123 :
V_126 |= V_127 ;
if ( V_125 & V_137 )
V_126 |= V_152 ;
if ( V_125 & V_128 )
V_126 |= V_129 ;
if ( V_125 & V_130 )
V_126 |= V_131 ;
break;
default:
V_126 |= V_127 ;
}
return V_126 ;
}
bool F_38 ( struct V_5 * V_6 )
{
return ( V_6 -> V_108 . V_109 == V_114 ||
V_6 -> V_108 . V_109 == V_121 ) ?
false : true ;
}
static int F_39 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_155 ;
T_6 V_156 = 0 ;
int V_26 ;
T_1 V_157 ;
T_1 V_158 ;
if ( V_6 -> V_108 . V_156 < 0 ) {
V_26 = F_40 ( V_6 , & V_156 ,
& V_155 , 0 ) ;
if ( ! V_26 )
F_41 ( V_6 , V_155 ) ;
F_42 ( V_154 , V_156 ) ;
V_26 = F_43 ( V_6 ) ;
if ( ! V_26 ) {
V_157 = V_6 -> V_108 . V_159 ;
V_158 = V_6 -> V_108 . V_160 ;
F_44 ( V_6 ) ;
V_154 -> V_161 =
F_37 ( V_6 ,
V_157 |
V_158 ) ;
V_154 -> V_162 =
F_37 ( V_6 , V_157 ) ;
V_154 -> V_107 = F_36 ( V_6 ) ;
if ( V_6 -> V_108 . V_159 ) {
V_154 -> V_161 |= V_163 ;
V_154 -> V_164 = V_165 ;
V_154 -> V_162 |= V_166 ;
}
V_154 -> V_161 |= V_167 ;
if ( F_38 ( V_6 ) )
V_154 -> V_162 |= V_168 ;
switch ( V_6 -> V_108 . V_109 ) {
case V_143 :
case V_134 :
V_154 -> V_169 = V_170 ;
break;
default:
V_154 -> V_169 = V_171 ;
break;
}
} else {
V_154 -> V_107 = V_124 ;
V_154 -> V_164 = V_172 ;
V_154 -> V_169 = V_173 ;
}
V_6 -> V_108 . V_156 = F_45 ( V_154 ) ;
V_6 -> V_108 . V_174 = V_154 -> V_107 ;
V_6 -> V_108 . V_169 = V_154 -> V_169 ;
V_6 -> V_108 . V_164 = V_154 -> V_164 ;
V_6 -> V_108 . V_162 = V_154 -> V_162 ;
V_6 -> V_108 . V_161 = V_154 -> V_161 ;
} else {
F_42 ( V_154 , V_6 -> V_108 . V_156 ) ;
V_154 -> V_107 = V_6 -> V_108 . V_174 ;
V_154 -> V_169 = V_6 -> V_108 . V_169 ;
V_154 -> V_164 = V_6 -> V_108 . V_164 ;
V_154 -> V_162 = V_6 -> V_108 . V_162 ;
V_154 -> V_161 = V_6 -> V_108 . V_161 ;
}
V_154 -> V_175 = F_46 ( V_2 ) ? V_176 : V_177 ;
V_154 -> V_178 = V_6 -> V_179 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_181 -> V_182 = V_6 -> V_183 [ 0 ] . V_184 . V_47 ;
V_181 -> V_185 = V_6 -> V_183 [ 0 ] . V_184 . V_47 ;
V_181 -> V_186 = V_6 -> V_187 [ 0 ] . V_184 . V_47 ;
V_181 -> V_188 = V_6 -> V_187 [ 0 ] . V_184 . V_47 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_189 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_49 ( V_6 , & V_154 -> V_190 , & V_154 -> V_191 ) ;
V_154 -> V_164 = V_6 -> V_108 . V_192 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_189 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_154 -> V_164 != V_6 -> V_108 . V_192 )
return - V_106 ;
V_26 = F_51 ( V_6 , V_154 -> V_190 ,
V_154 -> V_191 ) ;
if ( V_26 ) {
F_52 ( & V_6 -> V_16 -> V_36 , L_5 ) ;
return F_53 ( V_26 ) ;
}
V_6 -> V_193 = V_154 -> V_190 ;
V_6 -> V_194 = V_154 -> V_191 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_195 V_196 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_196 ) {
case V_197 :
F_55 ( V_6 , V_6 -> V_198 ,
& V_6 -> V_199 ) ;
return 1 ;
case V_200 :
F_56 ( V_6 , V_6 -> V_198 , 0 , 0 ,
V_201 ) ;
break;
case V_202 :
F_56 ( V_6 , V_6 -> V_198 , 0 , 0 ,
V_203 ) ;
break;
case V_204 :
F_56 ( V_6 , V_6 -> V_198 , 0 , 0 ,
V_6 -> V_199 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_205 * V_206 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_207 * V_36 = & V_6 -> V_16 -> V_36 ;
int V_26 ;
if ( ! F_16 ( V_6 ) ||
! F_14 ( V_6 , V_43 ) )
return - V_208 ;
switch ( V_206 -> V_209 ) {
case V_210 :
V_26 = F_58 ( V_6 ) ;
if ( ! V_26 )
F_59 ( V_36 , L_6 ) ;
break;
case V_211 :
V_26 = F_60 ( V_6 ) ;
if ( ! V_26 )
F_59 ( V_36 , L_7 ) ;
break;
default:
F_9 ( V_36 , L_8 , V_206 -> V_209 ) ;
return - V_106 ;
}
return V_26 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_214 & V_215 ) {
V_213 -> V_161 |= V_216 ;
if ( V_6 -> V_217 )
V_213 -> V_218 |= V_216 ;
} else {
V_213 -> V_218 = 0 ;
}
memset ( & V_213 -> V_219 , 0 , sizeof( V_213 -> V_219 ) ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_213 -> V_218 & ~ V_216 )
return - V_208 ;
if ( ! ( V_6 -> V_214 & V_215 ) ) {
F_52 ( & V_6 -> V_16 -> V_36 , L_9 ) ;
return - V_208 ;
}
if ( V_213 -> V_218 & V_216 )
V_6 -> V_217 = true ;
else
V_6 -> V_217 = false ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
int V_220 , V_67 ;
struct V_24 V_221 ;
static const V_96 V_222 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_221 . V_33 = sizeof( struct V_223 ) ;
V_221 . V_35 = F_8 ( & V_6 -> V_16 -> V_36 ,
V_221 . V_33 , & V_221 . V_37 ,
V_224 ) ;
if ( ! V_221 . V_35 )
return - V_39 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_220 = F_64 ( V_6 , V_222 [ V_67 ] ,
4096 , & V_221 ) ;
if ( V_220 != 0 )
goto V_225;
}
V_225:
F_12 ( & V_6 -> V_16 -> V_36 , V_221 . V_33 , V_221 . V_35 ,
V_221 . V_37 ) ;
return F_53 ( V_220 ) ;
}
static V_96 F_65 ( struct V_5 * V_6 , T_2 V_226 ,
V_96 * V_26 )
{
int V_220 ;
V_220 = F_66 ( V_6 , V_6 -> V_198 ,
V_226 , 1 ) ;
if ( V_220 )
return V_220 ;
* V_26 = F_67 ( V_6 , V_6 -> V_198 ,
V_226 , 1500 , 2 , 0xabc ) ;
V_220 = F_66 ( V_6 , V_6 -> V_198 ,
V_227 , 1 ) ;
if ( V_220 )
return V_220 ;
return * V_26 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_228 * V_229 ,
V_96 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
T_2 V_155 = 0 ;
if ( V_6 -> V_230 & V_231 ) {
F_9 ( & V_6 -> V_16 -> V_36 , L_10 ) ;
V_229 -> V_232 |= V_233 ;
return;
}
memset ( V_72 , 0 , sizeof( V_96 ) * V_104 ) ;
if ( V_229 -> V_232 & V_234 ) {
if ( F_65 ( V_6 , V_235 , & V_72 [ 0 ] ) != 0 )
V_229 -> V_232 |= V_233 ;
if ( F_65 ( V_6 , V_236 , & V_72 [ 1 ] ) != 0 )
V_229 -> V_232 |= V_233 ;
if ( V_229 -> V_232 & V_237 ) {
if ( F_65 ( V_6 , V_238 ,
& V_72 [ 2 ] ) != 0 )
V_229 -> V_232 |= V_233 ;
V_229 -> V_232 |= V_239 ;
}
}
if ( ! F_16 ( V_6 ) && F_63 ( V_6 ) != 0 ) {
V_72 [ 3 ] = 1 ;
V_229 -> V_232 |= V_233 ;
}
V_26 = F_40 ( V_6 , NULL , & V_155 , 0 ) ;
if ( V_26 ) {
V_229 -> V_232 |= V_233 ;
V_72 [ 4 ] = - 1 ;
} else if ( ! V_155 ) {
V_229 -> V_232 |= V_233 ;
V_72 [ 4 ] = 1 ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_240 * V_241 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_70 ( V_6 , V_241 -> V_72 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_6 , V_43 ) )
return 0 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_5 ( V_6 ,
V_242 ) ;
else
return F_5 ( V_6 ,
V_243 ) ;
} else {
return V_244 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_245 * V_246 , T_5 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_247 ;
struct V_248 * V_249 ;
int V_26 ;
if ( ! V_246 -> V_47 )
return - V_106 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_7 ( V_6 , V_242 ,
V_246 -> V_47 , V_72 ) ;
else
return F_7 ( V_6 , V_243 ,
V_246 -> V_47 , V_72 ) ;
}
V_246 -> V_250 = V_251 | ( V_6 -> V_16 -> V_207 << 16 ) ;
memset ( & V_247 , 0 , sizeof( struct V_24 ) ) ;
V_247 . V_33 = sizeof( struct V_252 ) ;
V_247 . V_35 = F_8 ( & V_6 -> V_16 -> V_36 ,
V_247 . V_33 , & V_247 . V_37 ,
V_224 ) ;
if ( ! V_247 . V_35 )
return - V_39 ;
V_26 = F_73 ( V_6 , & V_247 ) ;
if ( ! V_26 ) {
V_249 = V_247 . V_35 ;
memcpy ( V_72 , V_249 -> V_253 + V_246 -> V_84 , V_246 -> V_47 ) ;
}
F_12 ( & V_6 -> V_16 -> V_36 , V_247 . V_33 , V_247 . V_35 ,
V_247 . V_37 ) ;
return F_53 ( V_26 ) ;
}
static T_1 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_254 ;
}
static void F_75 ( struct V_1 * V_2 , T_1 V_255 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_254 == V_255 )
return;
if ( ( V_255 & V_256 ) != ( V_6 -> V_254 & V_256 ) )
if ( F_76 ( V_6 ) )
F_77 ( V_6 , V_255 & V_256 ?
V_257 :
V_258 ) ;
V_6 -> V_254 = V_255 ;
}
static V_96 F_78 ( struct V_5 * V_6 , V_96 V_259 )
{
V_96 V_72 = 0 ;
switch ( V_259 ) {
case V_260 :
if ( V_6 -> V_261 . V_262 & V_263 )
V_72 |= V_264 | V_265 ;
if ( V_6 -> V_261 . V_262 & V_266 )
V_72 |= V_267 | V_268 ;
break;
case V_269 :
if ( V_6 -> V_261 . V_262 & V_263 )
V_72 |= V_264 | V_265 ;
if ( V_6 -> V_261 . V_262 & V_270 )
V_72 |= V_267 | V_268 ;
break;
case V_271 :
if ( V_6 -> V_261 . V_262 & V_272 )
V_72 |= V_264 | V_265 ;
if ( V_6 -> V_261 . V_262 & V_273 )
V_72 |= V_267 | V_268 ;
break;
case V_274 :
if ( V_6 -> V_261 . V_262 & V_272 )
V_72 |= V_264 | V_265 ;
if ( V_6 -> V_261 . V_262 & V_275 )
V_72 |= V_267 | V_268 ;
break;
}
return V_72 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_276 * V_277 ,
T_1 * V_278 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_80 ( V_6 ) ) {
F_59 ( & V_6 -> V_16 -> V_36 ,
L_11 ) ;
return - V_106 ;
}
switch ( V_277 -> V_277 ) {
case V_279 :
V_277 -> V_72 = F_78 ( V_6 , V_277 -> V_259 ) ;
break;
case V_280 :
V_277 -> V_72 = V_6 -> V_101 - 1 ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_81 ( struct V_5 * V_6 ,
struct V_276 * V_277 )
{
struct V_73 * V_74 ;
int V_26 = 0 , V_67 , V_78 ;
T_2 V_281 [ 128 ] ;
T_1 V_262 = V_6 -> V_261 . V_262 ;
if ( V_277 -> V_72 != V_282 &&
V_277 -> V_72 != ( V_282 | V_283 ) )
return - V_106 ;
switch ( V_277 -> V_259 ) {
case V_260 :
if ( V_277 -> V_72 == V_282 )
V_262 &= ~ V_266 ;
else if ( V_277 -> V_72 == ( V_282 | V_283 ) )
V_262 |= V_263 |
V_266 ;
break;
case V_271 :
if ( V_277 -> V_72 == V_282 )
V_262 &= ~ V_273 ;
else if ( V_277 -> V_72 == ( V_282 | V_283 ) )
V_262 |= V_272 |
V_273 ;
break;
case V_269 :
if ( ( V_277 -> V_72 == ( V_282 | V_283 ) ) &&
F_76 ( V_6 ) )
return - V_106 ;
if ( V_277 -> V_72 == V_282 )
V_262 &= ~ V_270 ;
else if ( V_277 -> V_72 == ( V_282 | V_283 ) )
V_262 |= V_263 |
V_270 ;
break;
case V_274 :
if ( ( V_277 -> V_72 == ( V_282 | V_283 ) ) &&
F_76 ( V_6 ) )
return - V_106 ;
if ( V_277 -> V_72 == V_282 )
V_262 &= ~ V_275 ;
else if ( V_277 -> V_72 == ( V_282 | V_283 ) )
V_262 |= V_272 |
V_275 ;
break;
default:
return - V_106 ;
}
if ( V_262 == V_6 -> V_261 . V_262 )
return V_26 ;
if ( F_80 ( V_6 ) ) {
for ( V_78 = 0 ; V_78 < 128 ; V_78 += V_6 -> V_284 ) {
F_82 (adapter, rxo, i) {
if ( ( V_78 + V_67 ) >= 128 )
break;
V_281 [ V_78 + V_67 ] = V_74 -> V_285 ;
}
}
}
V_26 = F_83 ( V_6 , V_6 -> V_261 . V_281 ,
V_262 , 128 , V_6 -> V_261 . V_286 ) ;
if ( ! V_26 )
V_6 -> V_261 . V_262 = V_262 ;
return F_53 ( V_26 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_276 * V_277 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( ! F_80 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_36 ,
L_12 ) ;
return - V_106 ;
}
switch ( V_277 -> V_277 ) {
case V_287 :
V_26 = F_81 ( V_6 , V_277 ) ;
break;
default:
return - V_106 ;
}
return V_26 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_288 * V_289 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_289 -> V_290 = V_6 -> V_291 ;
V_289 -> V_292 = F_86 ( V_6 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_288 * V_289 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_289 -> V_293 || V_289 -> V_294 || V_289 -> V_295 ||
! V_289 -> V_290 || V_289 -> V_290 > F_86 ( V_6 ) )
return - V_106 ;
V_6 -> V_296 = V_289 -> V_290 ;
V_26 = F_88 ( V_6 ) ;
return F_53 ( V_26 ) ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
return V_297 ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
return V_298 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_299 , T_2 * V_300 ,
T_2 * V_301 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_67 ;
struct V_261 * V_302 = & V_6 -> V_261 ;
if ( V_299 ) {
for ( V_67 = 0 ; V_67 < V_297 ; V_67 ++ )
V_299 [ V_67 ] = V_302 -> V_303 [ V_67 ] ;
}
if ( V_300 )
memcpy ( V_300 , V_302 -> V_286 , V_298 ) ;
if ( V_301 )
* V_301 = V_304 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , const T_1 * V_299 ,
const T_2 * V_300 , const T_2 V_301 )
{
int V_305 = 0 , V_67 , V_78 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_281 [ V_297 ] ;
if ( V_301 != V_306 && V_301 != V_304 )
return - V_208 ;
if ( V_299 ) {
struct V_73 * V_74 ;
for ( V_67 = 0 ; V_67 < V_297 ; V_67 ++ ) {
V_78 = V_299 [ V_67 ] ;
V_74 = & V_6 -> V_183 [ V_78 ] ;
V_281 [ V_67 ] = V_74 -> V_285 ;
V_6 -> V_261 . V_303 [ V_67 ] = V_78 ;
}
} else {
memcpy ( V_281 , V_6 -> V_261 . V_281 ,
V_297 ) ;
}
if ( ! V_300 )
V_300 = V_6 -> V_261 . V_286 ;
V_305 = F_83 ( V_6 , V_281 ,
V_6 -> V_261 . V_262 ,
V_297 , V_300 ) ;
if ( V_305 ) {
V_6 -> V_261 . V_262 = V_307 ;
return - V_41 ;
}
memcpy ( V_6 -> V_261 . V_286 , V_300 , V_298 ) ;
memcpy ( V_6 -> V_261 . V_281 , V_281 ,
V_297 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_310 [ V_311 ] ;
int V_26 ;
if ( ! F_14 ( V_6 , V_43 ) )
return - V_208 ;
V_26 = F_94 ( V_6 , V_312 ,
V_310 ) ;
if ( ! V_26 ) {
if ( ! V_310 [ V_313 ] ) {
V_309 -> type = V_314 ;
V_309 -> V_315 = V_311 ;
} else {
V_309 -> type = V_316 ;
V_309 -> V_315 = 2 * V_311 ;
}
}
return F_53 ( V_26 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_245 * V_246 , T_2 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( ! F_14 ( V_6 , V_43 ) )
return - V_208 ;
V_26 = F_94 ( V_6 , V_312 ,
V_72 ) ;
if ( V_26 )
goto V_225;
if ( V_246 -> V_84 + V_246 -> V_47 > V_311 ) {
V_26 = F_94 ( V_6 ,
V_317 ,
V_72 +
V_311 ) ;
if ( V_26 )
goto V_225;
}
if ( V_246 -> V_84 )
memcpy ( V_72 , V_72 + V_246 -> V_84 , V_246 -> V_47 ) ;
V_225:
return F_53 ( V_26 ) ;
}
