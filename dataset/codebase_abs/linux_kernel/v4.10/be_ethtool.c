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
}
static T_1 F_5 ( struct V_5 * V_6 , T_2 * V_17 )
{
T_1 V_18 = 0 , V_19 ;
T_2 V_20 ;
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_6 ( V_6 , & V_22 , 0 , 0 , V_17 ,
& V_18 , & V_19 , & V_20 ) ;
return V_18 ;
}
static int F_7 ( struct V_5 * V_6 )
{
T_1 V_23 = 0 ;
if ( F_8 ( V_6 ) )
V_23 = F_5 ( V_6 ,
V_24 ) ;
else
V_23 = V_6 -> V_25 ;
return V_23 ;
}
static int F_9 ( struct V_5 * V_6 , T_2 * V_17 ,
T_1 V_26 , void * V_27 )
{
struct V_21 V_28 ;
T_1 V_29 = 0 , V_30 = 0 , V_31 ;
T_1 V_19 = 0 ;
T_2 V_20 ;
int V_32 = 0 ;
V_28 . V_33 = V_34 ;
V_28 . V_35 = F_10 ( & V_6 -> V_16 -> V_36 , V_28 . V_33 ,
& V_28 . V_37 , V_38 ) ;
if ( ! V_28 . V_35 ) {
F_11 ( & V_6 -> V_16 -> V_36 ,
L_2 ) ;
return - V_39 ;
}
while ( ( V_30 < V_26 ) && ! V_19 ) {
V_31 = F_12 ( T_1 , ( V_26 - V_30 ) ,
V_34 ) ;
V_31 = F_13 ( V_31 , 4 ) ;
V_32 = F_6 ( V_6 , & V_28 , V_31 ,
V_30 , V_17 ,
& V_29 , & V_19 , & V_20 ) ;
if ( ! V_32 ) {
memcpy ( V_27 + V_30 , V_28 . V_35 , V_29 ) ;
V_30 += V_29 ;
V_19 &= V_40 ;
} else {
V_32 = - V_41 ;
break;
}
}
F_14 ( & V_6 -> V_16 -> V_36 , V_28 . V_33 , V_28 . V_35 ,
V_28 . V_37 ) ;
return V_32 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 V_42 ,
void * V_27 )
{
int V_32 = 0 ;
if ( F_8 ( V_6 ) )
V_32 = F_9 ( V_6 , V_24 ,
V_42 , V_27 ) ;
else
V_32 = F_16 ( V_6 , V_42 , V_27 ) ;
return V_32 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_45 * V_46 = & V_6 -> V_47 [ 0 ] ;
V_44 -> V_48 = V_46 -> V_49 ;
V_44 -> V_50 = V_46 -> V_51 ;
V_44 -> V_52 = V_46 -> V_53 ;
V_44 -> V_54 = V_46 -> V_49 ;
V_44 -> V_55 = V_46 -> V_51 ;
V_44 -> V_56 = V_46 -> V_53 ;
V_44 -> V_57 = V_46 -> V_58 ;
V_44 -> V_59 = V_46 -> V_58 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_45 * V_46 = & V_6 -> V_47 [ 0 ] ;
struct V_60 * V_61 ;
int V_62 ;
F_19 (adapter, eqo, i) {
V_46 -> V_58 = V_44 -> V_57 ;
V_46 -> V_51 = F_20 ( V_44 -> V_50 , V_63 ) ;
V_46 -> V_53 = F_20 ( V_44 -> V_52 , V_46 -> V_51 ) ;
V_46 -> V_64 = F_20 ( V_44 -> V_48 , V_46 -> V_51 ) ;
V_46 -> V_64 = F_21 ( V_46 -> V_64 , V_46 -> V_53 ) ;
V_46 ++ ;
}
if ( ! V_44 -> V_57 && F_22 ( V_6 ) )
F_23 ( V_6 , true ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_65 * V_66 , T_3 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
void * V_72 ;
unsigned int V_62 , V_73 , V_74 = 0 , V_75 ;
for ( V_62 = 0 ; V_62 < V_76 ; V_62 ++ ) {
V_72 = ( T_2 * ) & V_6 -> V_77 + V_78 [ V_62 ] . V_79 ;
V_67 [ V_62 ] = * ( T_1 * ) V_72 ;
}
V_74 += V_76 ;
F_25 (adapter, rxo, j) {
struct V_80 * V_66 = F_26 ( V_69 ) ;
do {
V_75 = F_27 ( & V_66 -> V_81 ) ;
V_67 [ V_74 ] = V_66 -> V_82 ;
V_67 [ V_74 + 1 ] = V_66 -> V_83 ;
} while ( F_28 ( & V_66 -> V_81 , V_75 ) );
for ( V_62 = 2 ; V_62 < V_84 ; V_62 ++ ) {
V_72 = ( T_2 * ) V_66 + V_85 [ V_62 ] . V_79 ;
V_67 [ V_74 + V_62 ] = * ( T_1 * ) V_72 ;
}
V_74 += V_84 ;
}
F_29 (adapter, txo, j) {
struct V_86 * V_66 = F_30 ( V_71 ) ;
do {
V_75 = F_27 ( & V_66 -> V_87 ) ;
V_67 [ V_74 ] = V_66 -> V_88 ;
} while ( F_28 ( & V_66 -> V_87 , V_75 ) );
do {
V_75 = F_27 ( & V_66 -> V_81 ) ;
for ( V_62 = 1 ; V_62 < V_89 ; V_62 ++ ) {
V_72 = ( T_2 * ) V_66 + V_90 [ V_62 ] . V_79 ;
V_67 [ V_74 + V_62 ] =
( V_90 [ V_62 ] . V_33 == sizeof( V_91 ) ) ?
* ( V_91 * ) V_72 : * ( T_1 * ) V_72 ;
}
} while ( F_28 ( & V_66 -> V_81 , V_75 ) );
V_74 += V_89 ;
}
}
static void F_31 ( struct V_1 * V_2 , T_4 V_92 ,
T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_62 , V_73 ;
switch ( V_92 ) {
case V_93 :
for ( V_62 = 0 ; V_62 < V_76 ; V_62 ++ ) {
memcpy ( V_67 , V_78 [ V_62 ] . V_94 , V_95 ) ;
V_67 += V_95 ;
}
for ( V_62 = 0 ; V_62 < V_6 -> V_96 ; V_62 ++ ) {
for ( V_73 = 0 ; V_73 < V_84 ; V_73 ++ ) {
sprintf ( V_67 , L_3 , V_62 ,
V_85 [ V_73 ] . V_94 ) ;
V_67 += V_95 ;
}
}
for ( V_62 = 0 ; V_62 < V_6 -> V_97 ; V_62 ++ ) {
for ( V_73 = 0 ; V_73 < V_89 ; V_73 ++ ) {
sprintf ( V_67 , L_4 , V_62 ,
V_90 [ V_73 ] . V_94 ) ;
V_67 += V_95 ;
}
}
break;
case V_98 :
for ( V_62 = 0 ; V_62 < V_99 ; V_62 ++ ) {
memcpy ( V_67 , V_100 [ V_62 ] , V_95 ) ;
V_67 += V_95 ;
}
break;
case V_101 :
for ( V_62 = 0 ; V_62 < F_32 ( V_102 ) ; V_62 ++ )
strcpy ( V_67 + V_62 * V_95 , V_102 [ V_62 ] ) ;
break;
}
}
static int F_33 ( struct V_1 * V_2 , int V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_92 ) {
case V_98 :
return V_99 ;
case V_93 :
return V_76 +
V_6 -> V_96 * V_84 +
V_6 -> V_97 * V_89 ;
case V_101 :
return F_32 ( V_102 ) ;
default:
return - V_103 ;
}
}
static T_1 F_34 ( struct V_5 * V_6 )
{
T_1 V_104 ;
switch ( V_6 -> V_105 . V_106 ) {
case V_107 :
case V_108 :
case V_109 :
V_104 = V_110 ;
break;
case V_111 :
if ( V_6 -> V_105 . V_112 & V_113 )
V_104 = V_114 ;
else
V_104 = V_115 ;
break;
case V_116 :
if ( V_6 -> V_105 . V_112 & V_117 )
V_104 = V_114 ;
else
V_104 = V_115 ;
break;
case V_118 :
case V_119 :
V_104 = V_115 ;
break;
case V_120 :
V_104 = V_110 ;
break;
default:
V_104 = V_121 ;
}
return V_104 ;
}
static T_1 F_35 ( struct V_5 * V_6 , T_1 V_122 )
{
T_1 V_123 = 0 ;
switch ( V_6 -> V_105 . V_106 ) {
case V_107 :
case V_108 :
case V_109 :
V_123 |= V_124 ;
if ( V_122 & V_125 )
V_123 |= V_126 ;
if ( V_122 & V_127 )
V_123 |= V_128 ;
if ( V_122 & V_129 )
V_123 |= V_130 ;
break;
case V_131 :
V_123 |= V_132 ;
if ( V_122 & V_125 )
V_123 |= V_133 ;
if ( V_122 & V_134 )
V_123 |= V_135 ;
break;
case V_136 :
V_123 |= V_132 ;
if ( V_122 & V_134 )
V_123 |= V_137 ;
if ( V_122 & V_138 )
V_123 |= V_139 ;
break;
case V_140 :
V_123 |= V_132 |
V_137 ;
break;
case V_141 :
V_123 |= V_132 ;
if ( V_122 & V_134 )
V_123 |= V_137 ;
if ( V_122 & V_142 )
V_123 |= V_143 ;
break;
case V_116 :
if ( V_122 & V_142 ) {
switch ( V_6 -> V_105 . V_112 ) {
case V_117 :
V_123 |= V_144 ;
break;
case V_145 :
V_123 |= V_146 ;
break;
default:
V_123 |= V_147 ;
break;
}
}
case V_111 :
case V_118 :
case V_119 :
V_123 |= V_148 ;
if ( V_122 & V_134 )
V_123 |= V_149 ;
if ( V_122 & V_125 )
V_123 |= V_126 ;
break;
case V_120 :
V_123 |= V_124 ;
if ( V_122 & V_134 )
V_123 |= V_149 ;
if ( V_122 & V_125 )
V_123 |= V_126 ;
if ( V_122 & V_127 )
V_123 |= V_128 ;
break;
default:
V_123 |= V_124 ;
}
return V_123 ;
}
bool F_36 ( struct V_5 * V_6 )
{
return ( V_6 -> V_105 . V_106 == V_111 ||
V_6 -> V_105 . V_106 == V_118 ) ?
false : true ;
}
static int F_37 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_152 ;
T_6 V_153 = 0 ;
int V_32 ;
T_1 V_154 ;
T_1 V_155 ;
if ( V_6 -> V_105 . V_153 < 0 ) {
V_32 = F_38 ( V_6 , & V_153 ,
& V_152 , 0 ) ;
if ( ! V_32 )
F_39 ( V_6 , V_152 ) ;
F_40 ( V_151 , V_153 ) ;
V_32 = F_41 ( V_6 ) ;
if ( ! V_32 ) {
V_154 = V_6 -> V_105 . V_156 ;
V_155 = V_6 -> V_105 . V_157 ;
F_42 ( V_6 ) ;
V_151 -> V_158 =
F_35 ( V_6 ,
V_154 |
V_155 ) ;
V_151 -> V_159 =
F_35 ( V_6 , V_154 ) ;
V_151 -> V_104 = F_34 ( V_6 ) ;
if ( V_6 -> V_105 . V_156 ) {
V_151 -> V_158 |= V_160 ;
V_151 -> V_161 = V_162 ;
V_151 -> V_159 |= V_163 ;
}
V_151 -> V_158 |= V_164 ;
if ( F_36 ( V_6 ) )
V_151 -> V_159 |= V_165 ;
switch ( V_6 -> V_105 . V_106 ) {
case V_140 :
case V_131 :
V_151 -> V_166 = V_167 ;
break;
default:
V_151 -> V_166 = V_168 ;
break;
}
} else {
V_151 -> V_104 = V_121 ;
V_151 -> V_161 = V_169 ;
V_151 -> V_166 = V_170 ;
}
V_6 -> V_105 . V_153 = F_43 ( V_151 ) ;
V_6 -> V_105 . V_171 = V_151 -> V_104 ;
V_6 -> V_105 . V_166 = V_151 -> V_166 ;
V_6 -> V_105 . V_161 = V_151 -> V_161 ;
V_6 -> V_105 . V_159 = V_151 -> V_159 ;
V_6 -> V_105 . V_158 = V_151 -> V_158 ;
} else {
F_40 ( V_151 , V_6 -> V_105 . V_153 ) ;
V_151 -> V_104 = V_6 -> V_105 . V_171 ;
V_151 -> V_166 = V_6 -> V_105 . V_166 ;
V_151 -> V_161 = V_6 -> V_105 . V_161 ;
V_151 -> V_159 = V_6 -> V_105 . V_159 ;
V_151 -> V_158 = V_6 -> V_105 . V_158 ;
}
V_151 -> V_172 = F_44 ( V_2 ) ? V_173 : V_174 ;
V_151 -> V_175 = V_6 -> V_176 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_178 -> V_179 = V_6 -> V_180 [ 0 ] . V_181 . V_182 ;
V_178 -> V_183 = V_6 -> V_180 [ 0 ] . V_181 . V_182 ;
V_178 -> V_184 = V_6 -> V_185 [ 0 ] . V_181 . V_182 ;
V_178 -> V_186 = V_6 -> V_185 [ 0 ] . V_181 . V_182 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_187 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_47 ( V_6 , & V_151 -> V_188 , & V_151 -> V_189 ) ;
V_151 -> V_161 = V_6 -> V_105 . V_190 ;
}
static int
F_48 ( struct V_1 * V_2 , struct V_187 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( V_151 -> V_161 != V_6 -> V_105 . V_190 )
return - V_103 ;
V_32 = F_49 ( V_6 , V_151 -> V_188 ,
V_151 -> V_189 ) ;
if ( V_32 ) {
F_50 ( & V_6 -> V_16 -> V_36 , L_5 ) ;
return F_51 ( V_32 ) ;
}
V_6 -> V_191 = V_151 -> V_188 ;
V_6 -> V_192 = V_151 -> V_189 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_193 V_194 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 = 0 ;
switch ( V_194 ) {
case V_195 :
V_32 = F_53 ( V_6 , V_6 -> V_196 ,
& V_6 -> V_197 ) ;
if ( V_32 )
return F_51 ( V_32 ) ;
return 1 ;
case V_198 :
V_32 = F_54 ( V_6 , V_6 -> V_196 ,
0 , 0 , V_199 ) ;
break;
case V_200 :
V_32 = F_54 ( V_6 , V_6 -> V_196 ,
0 , 0 , V_201 ) ;
break;
case V_202 :
V_32 = F_54 ( V_6 , V_6 -> V_196 ,
0 , 0 , V_6 -> V_197 ) ;
}
return F_51 ( V_32 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_205 * V_36 = & V_6 -> V_16 -> V_36 ;
int V_32 ;
if ( ! F_8 ( V_6 ) ||
! F_56 ( V_6 , V_206 ) )
return - V_207 ;
switch ( V_204 -> V_208 ) {
case V_209 :
V_32 = F_57 ( V_6 ) ;
if ( ! V_32 )
F_58 ( V_36 , L_6 ) ;
break;
case V_210 :
V_32 = F_59 ( V_6 ) ;
if ( ! V_32 )
F_58 ( V_36 , L_7 ) ;
break;
default:
F_11 ( V_36 , L_8 , V_204 -> V_208 ) ;
return - V_103 ;
}
return V_32 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_213 & V_214 ) {
V_212 -> V_158 |= V_215 ;
if ( V_6 -> V_216 )
V_212 -> V_217 |= V_215 ;
} else {
V_212 -> V_217 = 0 ;
}
memset ( & V_212 -> V_218 , 0 , sizeof( V_212 -> V_218 ) ) ;
}
static int F_61 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_205 * V_36 = & V_6 -> V_16 -> V_36 ;
struct V_21 V_219 ;
T_2 V_220 [ V_221 ] ;
bool V_58 ;
int V_32 ;
if ( V_212 -> V_217 & ~ V_215 )
return - V_207 ;
if ( ! ( V_6 -> V_213 & V_214 ) ) {
F_50 ( & V_6 -> V_16 -> V_36 , L_9 ) ;
return - V_207 ;
}
V_219 . V_33 = sizeof( struct V_222 ) ;
V_219 . V_35 = F_10 ( V_36 , V_219 . V_33 , & V_219 . V_37 , V_223 ) ;
if ( ! V_219 . V_35 )
return - V_39 ;
F_62 ( V_220 ) ;
V_58 = V_212 -> V_217 & V_215 ;
if ( V_58 )
F_63 ( V_220 , V_6 -> V_2 -> V_224 ) ;
V_32 = F_64 ( V_6 , V_220 , & V_219 ) ;
if ( V_32 ) {
F_11 ( V_36 , L_10 ) ;
V_32 = F_51 ( V_32 ) ;
goto V_225;
}
F_65 ( V_6 -> V_16 , V_226 , V_58 ) ;
F_65 ( V_6 -> V_16 , V_227 , V_58 ) ;
V_6 -> V_216 = V_58 ? true : false ;
V_225:
F_14 ( V_36 , V_219 . V_33 , V_219 . V_35 , V_219 . V_37 ) ;
return V_32 ;
}
static int F_66 ( struct V_5 * V_6 )
{
int V_228 , V_62 ;
struct V_21 V_229 ;
static const V_91 V_230 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_229 . V_33 = sizeof( struct V_231 ) ;
V_229 . V_35 = F_10 ( & V_6 -> V_16 -> V_36 ,
V_229 . V_33 , & V_229 . V_37 ,
V_223 ) ;
if ( ! V_229 . V_35 )
return - V_39 ;
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
V_228 = F_67 ( V_6 , V_230 [ V_62 ] ,
4096 , & V_229 ) ;
if ( V_228 != 0 )
goto V_225;
}
V_225:
F_14 ( & V_6 -> V_16 -> V_36 , V_229 . V_33 , V_229 . V_35 ,
V_229 . V_37 ) ;
return F_51 ( V_228 ) ;
}
static V_91 F_68 ( struct V_5 * V_6 , T_2 V_232 ,
V_91 * V_32 )
{
int V_228 ;
V_228 = F_69 ( V_6 , V_6 -> V_196 ,
V_232 , 1 ) ;
if ( V_228 )
return V_228 ;
* V_32 = F_70 ( V_6 , V_6 -> V_196 ,
V_232 , 1500 , 2 , 0xabc ) ;
V_228 = F_69 ( V_6 , V_6 -> V_196 ,
V_233 , 1 ) ;
if ( V_228 )
return V_228 ;
return * V_32 ;
}
static void F_71 ( struct V_1 * V_2 , struct V_234 * V_235 ,
V_91 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
T_2 V_152 = 0 ;
if ( V_6 -> V_236 & V_237 ) {
F_11 ( & V_6 -> V_16 -> V_36 , L_11 ) ;
V_235 -> V_238 |= V_239 ;
return;
}
memset ( V_67 , 0 , sizeof( V_91 ) * V_99 ) ;
if ( V_235 -> V_238 & V_240 ) {
if ( F_68 ( V_6 , V_241 , & V_67 [ 0 ] ) != 0 )
V_235 -> V_238 |= V_239 ;
if ( F_68 ( V_6 , V_242 , & V_67 [ 1 ] ) != 0 )
V_235 -> V_238 |= V_239 ;
if ( V_235 -> V_238 & V_243 ) {
if ( F_68 ( V_6 , V_244 ,
& V_67 [ 2 ] ) != 0 )
V_235 -> V_238 |= V_239 ;
V_235 -> V_238 |= V_245 ;
}
}
if ( ! F_8 ( V_6 ) && F_66 ( V_6 ) != 0 ) {
V_67 [ 3 ] = 1 ;
V_235 -> V_238 |= V_239 ;
}
V_32 = F_38 ( V_6 , NULL , & V_152 , 0 ) ;
if ( V_32 ) {
V_235 -> V_238 |= V_239 ;
V_67 [ 4 ] = - 1 ;
} else if ( ! V_152 ) {
V_235 -> V_238 |= V_239 ;
V_67 [ 4 ] = 1 ;
}
}
static int F_72 ( struct V_1 * V_2 , struct V_246 * V_247 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_73 ( V_6 , V_247 -> V_67 ) ;
}
static int
F_74 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_56 ( V_6 , V_206 ) )
return - V_207 ;
V_204 -> V_182 = F_7 ( V_6 ) ;
V_204 -> V_9 = 1 ;
V_204 -> V_208 = 0x1 ;
return 0 ;
}
static int
F_75 ( struct V_1 * V_2 , struct V_203 * V_204 ,
void * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( ! F_56 ( V_6 , V_206 ) )
return - V_207 ;
V_32 = F_15 ( V_6 , V_204 -> V_182 , V_27 ) ;
return F_51 ( V_32 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_56 ( V_6 , V_206 ) )
return 0 ;
if ( F_8 ( V_6 ) ) {
if ( F_77 ( V_6 ) )
return F_5 ( V_6 ,
V_248 ) ;
else
return F_5 ( V_6 ,
V_249 ) ;
} else {
return V_250 ;
}
}
static int F_78 ( struct V_1 * V_2 ,
struct V_251 * V_252 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 V_253 ;
struct V_254 * V_255 ;
int V_32 ;
if ( ! V_252 -> V_182 )
return - V_103 ;
if ( F_8 ( V_6 ) ) {
if ( F_77 ( V_6 ) )
return F_9 ( V_6 , V_248 ,
V_252 -> V_182 , V_67 ) ;
else
return F_9 ( V_6 , V_249 ,
V_252 -> V_182 , V_67 ) ;
}
V_252 -> V_256 = V_257 | ( V_6 -> V_16 -> V_205 << 16 ) ;
memset ( & V_253 , 0 , sizeof( struct V_21 ) ) ;
V_253 . V_33 = sizeof( struct V_258 ) ;
V_253 . V_35 = F_10 ( & V_6 -> V_16 -> V_36 ,
V_253 . V_33 , & V_253 . V_37 ,
V_223 ) ;
if ( ! V_253 . V_35 )
return - V_39 ;
V_32 = F_79 ( V_6 , & V_253 ) ;
if ( ! V_32 ) {
V_255 = V_253 . V_35 ;
memcpy ( V_67 , V_255 -> V_259 + V_252 -> V_79 , V_252 -> V_182 ) ;
}
F_14 ( & V_6 -> V_16 -> V_36 , V_253 . V_33 , V_253 . V_35 ,
V_253 . V_37 ) ;
return F_51 ( V_32 ) ;
}
static T_1 F_80 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_260 ;
}
static void F_81 ( struct V_1 * V_2 , T_1 V_261 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_260 == V_261 )
return;
if ( ( V_261 & V_262 ) != ( V_6 -> V_260 & V_262 ) )
if ( F_82 ( V_6 ) )
F_83 ( V_6 , V_261 & V_262 ?
V_263 :
V_264 ) ;
V_6 -> V_260 = V_261 ;
}
static V_91 F_84 ( struct V_5 * V_6 , V_91 V_265 )
{
V_91 V_67 = 0 ;
switch ( V_265 ) {
case V_266 :
if ( V_6 -> V_267 . V_268 & V_269 )
V_67 |= V_270 | V_271 ;
if ( V_6 -> V_267 . V_268 & V_272 )
V_67 |= V_273 | V_274 ;
break;
case V_275 :
if ( V_6 -> V_267 . V_268 & V_269 )
V_67 |= V_270 | V_271 ;
if ( V_6 -> V_267 . V_268 & V_276 )
V_67 |= V_273 | V_274 ;
break;
case V_277 :
if ( V_6 -> V_267 . V_268 & V_278 )
V_67 |= V_270 | V_271 ;
if ( V_6 -> V_267 . V_268 & V_279 )
V_67 |= V_273 | V_274 ;
break;
case V_280 :
if ( V_6 -> V_267 . V_268 & V_278 )
V_67 |= V_270 | V_271 ;
if ( V_6 -> V_267 . V_268 & V_281 )
V_67 |= V_273 | V_274 ;
break;
}
return V_67 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_282 * V_219 ,
T_1 * V_283 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_86 ( V_6 ) ) {
F_58 ( & V_6 -> V_16 -> V_36 ,
L_12 ) ;
return - V_103 ;
}
switch ( V_219 -> V_219 ) {
case V_284 :
V_219 -> V_67 = F_84 ( V_6 , V_219 -> V_265 ) ;
break;
case V_285 :
V_219 -> V_67 = V_6 -> V_96 - 1 ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_87 ( struct V_5 * V_6 ,
struct V_282 * V_219 )
{
int V_32 ;
T_1 V_268 = V_6 -> V_267 . V_268 ;
if ( V_219 -> V_67 != V_286 &&
V_219 -> V_67 != ( V_286 | V_287 ) )
return - V_103 ;
switch ( V_219 -> V_265 ) {
case V_266 :
if ( V_219 -> V_67 == V_286 )
V_268 &= ~ V_272 ;
else if ( V_219 -> V_67 == ( V_286 | V_287 ) )
V_268 |= V_269 |
V_272 ;
break;
case V_277 :
if ( V_219 -> V_67 == V_286 )
V_268 &= ~ V_279 ;
else if ( V_219 -> V_67 == ( V_286 | V_287 ) )
V_268 |= V_278 |
V_279 ;
break;
case V_275 :
if ( ( V_219 -> V_67 == ( V_286 | V_287 ) ) &&
F_82 ( V_6 ) )
return - V_103 ;
if ( V_219 -> V_67 == V_286 )
V_268 &= ~ V_276 ;
else if ( V_219 -> V_67 == ( V_286 | V_287 ) )
V_268 |= V_269 |
V_276 ;
break;
case V_280 :
if ( ( V_219 -> V_67 == ( V_286 | V_287 ) ) &&
F_82 ( V_6 ) )
return - V_103 ;
if ( V_219 -> V_67 == V_286 )
V_268 &= ~ V_281 ;
else if ( V_219 -> V_67 == ( V_286 | V_287 ) )
V_268 |= V_278 |
V_281 ;
break;
default:
return - V_103 ;
}
if ( V_268 == V_6 -> V_267 . V_268 )
return 0 ;
V_32 = F_88 ( V_6 , V_6 -> V_267 . V_288 ,
V_268 , V_289 ,
V_6 -> V_267 . V_290 ) ;
if ( ! V_32 )
V_6 -> V_267 . V_268 = V_268 ;
return F_51 ( V_32 ) ;
}
static int F_89 ( struct V_1 * V_2 , struct V_282 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 = 0 ;
if ( ! F_86 ( V_6 ) ) {
F_11 ( & V_6 -> V_16 -> V_36 ,
L_13 ) ;
return - V_103 ;
}
switch ( V_219 -> V_219 ) {
case V_291 :
V_32 = F_87 ( V_6 , V_219 ) ;
break;
default:
return - V_103 ;
}
return V_32 ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_6 V_294 = F_91 ( T_6 , V_6 -> V_295 , 1 ) ;
V_293 -> V_296 = F_20 ( V_6 -> V_97 , V_294 ) ;
V_293 -> V_297 = V_294 - V_293 -> V_296 ;
V_293 -> V_298 = V_6 -> V_97 - V_293 -> V_296 ;
V_293 -> V_299 = F_92 ( V_6 ) ;
V_293 -> V_300 = F_93 ( V_6 ) - 1 ;
V_293 -> V_301 = F_94 ( V_6 ) - 1 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( V_293 -> V_302 || ! V_293 -> V_296 ||
( V_293 -> V_297 && V_293 -> V_298 ) )
return - V_103 ;
if ( V_293 -> V_296 > F_92 ( V_6 ) ||
( V_293 -> V_297 &&
( V_293 -> V_297 + V_293 -> V_296 ) > F_93 ( V_6 ) ) ||
( V_293 -> V_298 &&
( V_293 -> V_298 + V_293 -> V_296 ) > F_94 ( V_6 ) ) )
return - V_103 ;
V_6 -> V_303 = V_293 -> V_296 + V_293 -> V_297 ;
V_6 -> V_304 = V_293 -> V_296 + V_293 -> V_298 ;
V_32 = F_96 ( V_6 ) ;
return F_51 ( V_32 ) ;
}
static T_1 F_97 ( struct V_1 * V_2 )
{
return V_289 ;
}
static T_1 F_98 ( struct V_1 * V_2 )
{
return V_305 ;
}
static int F_99 ( struct V_1 * V_2 , T_1 * V_306 , T_2 * V_307 ,
T_2 * V_308 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_62 ;
struct V_267 * V_309 = & V_6 -> V_267 ;
if ( V_306 ) {
for ( V_62 = 0 ; V_62 < V_289 ; V_62 ++ )
V_306 [ V_62 ] = V_309 -> V_310 [ V_62 ] ;
}
if ( V_307 )
memcpy ( V_307 , V_309 -> V_290 , V_305 ) ;
if ( V_308 )
* V_308 = V_311 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , const T_1 * V_306 ,
const T_2 * V_307 , const T_2 V_308 )
{
int V_312 = 0 , V_62 , V_73 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_288 [ V_289 ] ;
if ( V_308 != V_313 && V_308 != V_311 )
return - V_207 ;
if ( V_306 ) {
struct V_68 * V_69 ;
for ( V_62 = 0 ; V_62 < V_289 ; V_62 ++ ) {
V_73 = V_306 [ V_62 ] ;
V_69 = & V_6 -> V_180 [ V_73 ] ;
V_288 [ V_62 ] = V_69 -> V_314 ;
V_6 -> V_267 . V_310 [ V_62 ] = V_73 ;
}
} else {
memcpy ( V_288 , V_6 -> V_267 . V_288 ,
V_289 ) ;
}
if ( ! V_307 )
V_307 = V_6 -> V_267 . V_290 ;
V_312 = F_88 ( V_6 , V_288 ,
V_6 -> V_267 . V_268 ,
V_289 , V_307 ) ;
if ( V_312 ) {
V_6 -> V_267 . V_268 = V_315 ;
return - V_41 ;
}
memcpy ( V_6 -> V_267 . V_290 , V_307 , V_305 ) ;
memcpy ( V_6 -> V_267 . V_288 , V_288 ,
V_289 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_316 * V_317 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_318 [ V_319 ] ;
int V_32 ;
if ( ! F_56 ( V_6 , V_206 ) )
return - V_207 ;
V_32 = F_102 ( V_6 , V_320 ,
V_318 ) ;
if ( ! V_32 ) {
if ( ! V_318 [ V_321 ] ) {
V_317 -> type = V_322 ;
V_317 -> V_323 = V_319 ;
} else {
V_317 -> type = V_324 ;
V_317 -> V_323 = 2 * V_319 ;
}
}
return F_51 ( V_32 ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_251 * V_252 , T_2 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( ! F_56 ( V_6 , V_206 ) )
return - V_207 ;
V_32 = F_102 ( V_6 , V_320 ,
V_67 ) ;
if ( V_32 )
goto V_225;
if ( V_252 -> V_79 + V_252 -> V_182 > V_319 ) {
V_32 = F_102 ( V_6 ,
V_325 ,
V_67 +
V_319 ) ;
if ( V_32 )
goto V_225;
}
if ( V_252 -> V_79 )
memcpy ( V_67 , V_67 + V_252 -> V_79 , V_252 -> V_182 ) ;
V_225:
return F_51 ( V_32 ) ;
}
static T_1 F_104 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_326 ;
}
static int F_105 ( struct V_1 * V_2 , T_1 V_238 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_327 = ! ! ( V_6 -> V_326 & V_328 ) ;
bool V_329 = ! ! ( V_238 & V_328 ) ;
if ( V_327 != V_329 ) {
if ( V_329 ) {
V_6 -> V_326 |= V_328 ;
F_58 ( & V_6 -> V_16 -> V_36 ,
L_14 ) ;
} else {
V_6 -> V_326 &= ~ V_328 ;
F_58 ( & V_6 -> V_16 -> V_36 ,
L_15 ) ;
}
}
return 0 ;
}
