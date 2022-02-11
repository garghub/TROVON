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
int V_23 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_23 = F_6 ( V_6 , & V_22 , 0 , 0 ,
V_17 , & V_18 , & V_19 ,
& V_20 ) ;
return V_18 ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_17 ,
T_1 V_24 , void * V_25 )
{
struct V_21 V_26 ;
T_1 V_27 = 0 , V_28 = 0 , V_29 ;
T_1 V_19 = 0 ;
T_2 V_20 ;
int V_23 = 0 ;
V_26 . V_30 = V_31 ;
V_26 . V_32 = F_8 ( & V_6 -> V_16 -> V_33 , V_26 . V_30 ,
& V_26 . V_34 , V_35 ) ;
if ( ! V_26 . V_32 ) {
F_9 ( & V_6 -> V_16 -> V_33 ,
L_2 ) ;
return - V_36 ;
}
while ( ( V_28 < V_24 ) && ! V_19 ) {
V_29 = F_10 ( T_1 , ( V_24 - V_28 ) ,
V_31 ) ;
V_29 = F_11 ( V_29 , 4 ) ;
V_23 = F_6 ( V_6 , & V_26 , V_29 ,
V_28 , V_17 ,
& V_27 , & V_19 , & V_20 ) ;
if ( ! V_23 ) {
memcpy ( V_25 + V_28 , V_26 . V_32 , V_27 ) ;
V_28 += V_27 ;
V_19 &= V_37 ;
} else {
V_23 = - V_38 ;
break;
}
}
F_12 ( & V_6 -> V_16 -> V_33 , V_26 . V_30 , V_26 . V_32 ,
V_26 . V_34 ) ;
return V_23 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_39 = 0 ;
if ( ! F_14 ( V_6 , V_40 ) )
return 0 ;
if ( F_15 ( V_6 ) ) {
if ( F_16 ( V_6 ) )
V_39 = F_5 ( V_6 ,
V_41 ) ;
else
F_17 ( V_6 , & V_39 ) ;
}
return V_39 ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_42 * V_43 , void * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_15 ( V_6 ) ) {
memset ( V_25 , 0 , V_43 -> V_44 ) ;
if ( F_16 ( V_6 ) )
F_7 ( V_6 , V_41 ,
V_43 -> V_44 , V_25 ) ;
else
F_19 ( V_6 , V_43 -> V_44 , V_25 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_47 * V_48 = & V_6 -> V_49 [ 0 ] ;
V_46 -> V_50 = V_48 -> V_51 ;
V_46 -> V_52 = V_48 -> V_53 ;
V_46 -> V_54 = V_48 -> V_55 ;
V_46 -> V_56 = V_48 -> V_51 ;
V_46 -> V_57 = V_48 -> V_53 ;
V_46 -> V_58 = V_48 -> V_55 ;
V_46 -> V_59 = V_48 -> V_60 ;
V_46 -> V_61 = V_48 -> V_60 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_47 * V_48 = & V_6 -> V_49 [ 0 ] ;
struct V_62 * V_63 ;
int V_64 ;
F_22 (adapter, eqo, i) {
V_48 -> V_60 = V_46 -> V_59 ;
V_48 -> V_53 = F_23 ( V_46 -> V_52 , V_65 ) ;
V_48 -> V_55 = F_23 ( V_46 -> V_54 , V_48 -> V_53 ) ;
V_48 -> V_66 = F_23 ( V_46 -> V_50 , V_48 -> V_53 ) ;
V_48 -> V_66 = F_24 ( V_48 -> V_66 , V_48 -> V_55 ) ;
V_48 ++ ;
}
if ( ! V_46 -> V_59 && F_25 ( V_6 ) )
F_26 ( V_6 , true ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_67 * V_68 , T_3 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
void * V_74 ;
unsigned int V_64 , V_75 , V_76 = 0 , V_77 ;
for ( V_64 = 0 ; V_64 < V_78 ; V_64 ++ ) {
V_74 = ( T_2 * ) & V_6 -> V_79 + V_80 [ V_64 ] . V_81 ;
V_69 [ V_64 ] = * ( T_1 * ) V_74 ;
}
V_76 += V_78 ;
F_28 (adapter, rxo, j) {
struct V_82 * V_68 = F_29 ( V_71 ) ;
do {
V_77 = F_30 ( & V_68 -> V_83 ) ;
V_69 [ V_76 ] = V_68 -> V_84 ;
V_69 [ V_76 + 1 ] = V_68 -> V_85 ;
} while ( F_31 ( & V_68 -> V_83 , V_77 ) );
for ( V_64 = 2 ; V_64 < V_86 ; V_64 ++ ) {
V_74 = ( T_2 * ) V_68 + V_87 [ V_64 ] . V_81 ;
V_69 [ V_76 + V_64 ] = * ( T_1 * ) V_74 ;
}
V_76 += V_86 ;
}
F_32 (adapter, txo, j) {
struct V_88 * V_68 = F_33 ( V_73 ) ;
do {
V_77 = F_30 ( & V_68 -> V_89 ) ;
V_69 [ V_76 ] = V_68 -> V_90 ;
} while ( F_31 ( & V_68 -> V_89 , V_77 ) );
do {
V_77 = F_30 ( & V_68 -> V_83 ) ;
for ( V_64 = 1 ; V_64 < V_91 ; V_64 ++ ) {
V_74 = ( T_2 * ) V_68 + V_92 [ V_64 ] . V_81 ;
V_69 [ V_76 + V_64 ] =
( V_92 [ V_64 ] . V_30 == sizeof( V_93 ) ) ?
* ( V_93 * ) V_74 : * ( T_1 * ) V_74 ;
}
} while ( F_31 ( & V_68 -> V_83 , V_77 ) );
V_76 += V_91 ;
}
}
static void F_34 ( struct V_1 * V_2 , T_4 V_94 ,
T_5 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_64 , V_75 ;
switch ( V_94 ) {
case V_95 :
for ( V_64 = 0 ; V_64 < V_78 ; V_64 ++ ) {
memcpy ( V_69 , V_80 [ V_64 ] . V_96 , V_97 ) ;
V_69 += V_97 ;
}
for ( V_64 = 0 ; V_64 < V_6 -> V_98 ; V_64 ++ ) {
for ( V_75 = 0 ; V_75 < V_86 ; V_75 ++ ) {
sprintf ( V_69 , L_3 , V_64 ,
V_87 [ V_75 ] . V_96 ) ;
V_69 += V_97 ;
}
}
for ( V_64 = 0 ; V_64 < V_6 -> V_99 ; V_64 ++ ) {
for ( V_75 = 0 ; V_75 < V_91 ; V_75 ++ ) {
sprintf ( V_69 , L_4 , V_64 ,
V_92 [ V_75 ] . V_96 ) ;
V_69 += V_97 ;
}
}
break;
case V_100 :
for ( V_64 = 0 ; V_64 < V_101 ; V_64 ++ ) {
memcpy ( V_69 , V_102 [ V_64 ] , V_97 ) ;
V_69 += V_97 ;
}
break;
}
}
static int F_35 ( struct V_1 * V_2 , int V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_94 ) {
case V_100 :
return V_101 ;
case V_95 :
return V_78 +
V_6 -> V_98 * V_86 +
V_6 -> V_99 * V_91 ;
default:
return - V_103 ;
}
}
static T_1 F_36 ( struct V_5 * V_6 )
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
static T_1 F_37 ( struct V_5 * V_6 , T_1 V_122 )
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
bool F_38 ( struct V_5 * V_6 )
{
return ( V_6 -> V_105 . V_106 == V_111 ||
V_6 -> V_105 . V_106 == V_118 ) ?
false : true ;
}
static int F_39 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_152 ;
T_6 V_153 = 0 ;
int V_23 ;
T_1 V_154 ;
T_1 V_155 ;
if ( V_6 -> V_105 . V_153 < 0 ) {
V_23 = F_40 ( V_6 , & V_153 ,
& V_152 , 0 ) ;
if ( ! V_23 )
F_41 ( V_6 , V_152 ) ;
F_42 ( V_151 , V_153 ) ;
V_23 = F_43 ( V_6 ) ;
if ( ! V_23 ) {
V_154 = V_6 -> V_105 . V_156 ;
V_155 = V_6 -> V_105 . V_157 ;
F_44 ( V_6 ) ;
V_151 -> V_158 =
F_37 ( V_6 ,
V_154 |
V_155 ) ;
V_151 -> V_159 =
F_37 ( V_6 , V_154 ) ;
V_151 -> V_104 = F_36 ( V_6 ) ;
if ( V_6 -> V_105 . V_156 ) {
V_151 -> V_158 |= V_160 ;
V_151 -> V_161 = V_162 ;
V_151 -> V_159 |= V_163 ;
}
V_151 -> V_158 |= V_164 ;
if ( F_38 ( V_6 ) )
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
V_6 -> V_105 . V_153 = F_45 ( V_151 ) ;
V_6 -> V_105 . V_171 = V_151 -> V_104 ;
V_6 -> V_105 . V_166 = V_151 -> V_166 ;
V_6 -> V_105 . V_161 = V_151 -> V_161 ;
V_6 -> V_105 . V_159 = V_151 -> V_159 ;
V_6 -> V_105 . V_158 = V_151 -> V_158 ;
} else {
F_42 ( V_151 , V_6 -> V_105 . V_153 ) ;
V_151 -> V_104 = V_6 -> V_105 . V_171 ;
V_151 -> V_166 = V_6 -> V_105 . V_166 ;
V_151 -> V_161 = V_6 -> V_105 . V_161 ;
V_151 -> V_159 = V_6 -> V_105 . V_159 ;
V_151 -> V_158 = V_6 -> V_105 . V_158 ;
}
V_151 -> V_172 = F_46 ( V_2 ) ? V_173 : V_174 ;
V_151 -> V_175 = V_6 -> V_176 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_178 -> V_179 = V_6 -> V_180 [ 0 ] . V_181 . V_44 ;
V_178 -> V_182 = V_6 -> V_180 [ 0 ] . V_181 . V_44 ;
V_178 -> V_183 = V_6 -> V_184 [ 0 ] . V_181 . V_44 ;
V_178 -> V_185 = V_6 -> V_184 [ 0 ] . V_181 . V_44 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_186 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_49 ( V_6 , & V_151 -> V_187 , & V_151 -> V_188 ) ;
V_151 -> V_161 = V_6 -> V_105 . V_189 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_186 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 ;
if ( V_151 -> V_161 != V_6 -> V_105 . V_189 )
return - V_103 ;
V_23 = F_51 ( V_6 , V_151 -> V_187 ,
V_151 -> V_188 ) ;
if ( V_23 ) {
F_52 ( & V_6 -> V_16 -> V_33 , L_5 ) ;
return F_53 ( V_23 ) ;
}
V_6 -> V_190 = V_151 -> V_187 ;
V_6 -> V_191 = V_151 -> V_188 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_192 V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_193 ) {
case V_194 :
F_55 ( V_6 , V_6 -> V_195 ,
& V_6 -> V_196 ) ;
return 1 ;
case V_197 :
F_56 ( V_6 , V_6 -> V_195 , 0 , 0 ,
V_198 ) ;
break;
case V_199 :
F_56 ( V_6 , V_6 -> V_195 , 0 , 0 ,
V_200 ) ;
break;
case V_201 :
F_56 ( V_6 , V_6 -> V_195 , 0 , 0 ,
V_6 -> V_196 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_204 * V_33 = & V_6 -> V_16 -> V_33 ;
int V_23 ;
if ( ! F_16 ( V_6 ) ||
! F_14 ( V_6 , V_40 ) )
return - V_205 ;
switch ( V_203 -> V_206 ) {
case V_207 :
V_23 = F_58 ( V_6 ) ;
if ( ! V_23 )
F_59 ( V_33 , L_6 ) ;
break;
case V_208 :
V_23 = F_60 ( V_6 ) ;
if ( ! V_23 )
F_59 ( V_33 , L_7 ) ;
break;
default:
F_9 ( V_33 , L_8 , V_203 -> V_206 ) ;
return - V_103 ;
}
return V_23 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_211 & V_212 ) {
V_210 -> V_158 |= V_213 ;
if ( V_6 -> V_214 )
V_210 -> V_215 |= V_213 ;
} else {
V_210 -> V_215 = 0 ;
}
memset ( & V_210 -> V_216 , 0 , sizeof( V_210 -> V_216 ) ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_210 -> V_215 & ~ V_213 )
return - V_205 ;
if ( ! ( V_6 -> V_211 & V_212 ) ) {
F_52 ( & V_6 -> V_16 -> V_33 , L_9 ) ;
return - V_205 ;
}
if ( V_210 -> V_215 & V_213 )
V_6 -> V_214 = true ;
else
V_6 -> V_214 = false ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
int V_217 , V_64 ;
struct V_21 V_218 ;
static const V_93 V_219 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_218 . V_30 = sizeof( struct V_220 ) ;
V_218 . V_32 = F_8 ( & V_6 -> V_16 -> V_33 ,
V_218 . V_30 , & V_218 . V_34 ,
V_221 ) ;
if ( ! V_218 . V_32 )
return - V_36 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
V_217 = F_64 ( V_6 , V_219 [ V_64 ] ,
4096 , & V_218 ) ;
if ( V_217 != 0 )
goto V_222;
}
V_222:
F_12 ( & V_6 -> V_16 -> V_33 , V_218 . V_30 , V_218 . V_32 ,
V_218 . V_34 ) ;
return F_53 ( V_217 ) ;
}
static V_93 F_65 ( struct V_5 * V_6 , T_2 V_223 ,
V_93 * V_23 )
{
int V_217 ;
V_217 = F_66 ( V_6 , V_6 -> V_195 ,
V_223 , 1 ) ;
if ( V_217 )
return V_217 ;
* V_23 = F_67 ( V_6 , V_6 -> V_195 ,
V_223 , 1500 , 2 , 0xabc ) ;
V_217 = F_66 ( V_6 , V_6 -> V_195 ,
V_224 , 1 ) ;
if ( V_217 )
return V_217 ;
return * V_23 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_225 * V_226 ,
V_93 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 ;
T_2 V_152 = 0 ;
if ( V_6 -> V_227 & V_228 ) {
F_9 ( & V_6 -> V_16 -> V_33 , L_10 ) ;
V_226 -> V_229 |= V_230 ;
return;
}
memset ( V_69 , 0 , sizeof( V_93 ) * V_101 ) ;
if ( V_226 -> V_229 & V_231 ) {
if ( F_65 ( V_6 , V_232 , & V_69 [ 0 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
if ( F_65 ( V_6 , V_233 , & V_69 [ 1 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
if ( V_226 -> V_229 & V_234 ) {
if ( F_65 ( V_6 , V_235 ,
& V_69 [ 2 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
V_226 -> V_229 |= V_236 ;
}
}
if ( ! F_16 ( V_6 ) && F_63 ( V_6 ) != 0 ) {
V_69 [ 3 ] = 1 ;
V_226 -> V_229 |= V_230 ;
}
V_23 = F_40 ( V_6 , NULL , & V_152 , 0 ) ;
if ( V_23 ) {
V_226 -> V_229 |= V_230 ;
V_69 [ 4 ] = - 1 ;
} else if ( ! V_152 ) {
V_226 -> V_229 |= V_230 ;
V_69 [ 4 ] = 1 ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_70 ( V_6 , V_238 -> V_69 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_6 , V_40 ) )
return 0 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_5 ( V_6 ,
V_239 ) ;
else
return F_5 ( V_6 ,
V_240 ) ;
} else {
return V_241 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_242 * V_243 , T_5 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 V_244 ;
struct V_245 * V_246 ;
int V_23 ;
if ( ! V_243 -> V_44 )
return - V_103 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_7 ( V_6 , V_239 ,
V_243 -> V_44 , V_69 ) ;
else
return F_7 ( V_6 , V_240 ,
V_243 -> V_44 , V_69 ) ;
}
V_243 -> V_247 = V_248 | ( V_6 -> V_16 -> V_204 << 16 ) ;
memset ( & V_244 , 0 , sizeof( struct V_21 ) ) ;
V_244 . V_30 = sizeof( struct V_249 ) ;
V_244 . V_32 = F_8 ( & V_6 -> V_16 -> V_33 ,
V_244 . V_30 , & V_244 . V_34 ,
V_221 ) ;
if ( ! V_244 . V_32 )
return - V_36 ;
V_23 = F_73 ( V_6 , & V_244 ) ;
if ( ! V_23 ) {
V_246 = V_244 . V_32 ;
memcpy ( V_69 , V_246 -> V_250 + V_243 -> V_81 , V_243 -> V_44 ) ;
}
F_12 ( & V_6 -> V_16 -> V_33 , V_244 . V_30 , V_244 . V_32 ,
V_244 . V_34 ) ;
return F_53 ( V_23 ) ;
}
static T_1 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_251 ;
}
static void F_75 ( struct V_1 * V_2 , T_1 V_252 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_251 == V_252 )
return;
if ( ( V_252 & V_253 ) != ( V_6 -> V_251 & V_253 ) )
if ( F_76 ( V_6 ) )
F_77 ( V_6 , V_252 & V_253 ?
V_254 :
V_255 ) ;
V_6 -> V_251 = V_252 ;
}
static V_93 F_78 ( struct V_5 * V_6 , V_93 V_256 )
{
V_93 V_69 = 0 ;
switch ( V_256 ) {
case V_257 :
if ( V_6 -> V_258 . V_259 & V_260 )
V_69 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_263 )
V_69 |= V_264 | V_265 ;
break;
case V_266 :
if ( V_6 -> V_258 . V_259 & V_260 )
V_69 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_267 )
V_69 |= V_264 | V_265 ;
break;
case V_268 :
if ( V_6 -> V_258 . V_259 & V_269 )
V_69 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_270 )
V_69 |= V_264 | V_265 ;
break;
case V_271 :
if ( V_6 -> V_258 . V_259 & V_269 )
V_69 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_272 )
V_69 |= V_264 | V_265 ;
break;
}
return V_69 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_273 * V_274 ,
T_1 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_80 ( V_6 ) ) {
F_59 ( & V_6 -> V_16 -> V_33 ,
L_11 ) ;
return - V_103 ;
}
switch ( V_274 -> V_274 ) {
case V_276 :
V_274 -> V_69 = F_78 ( V_6 , V_274 -> V_256 ) ;
break;
case V_277 :
V_274 -> V_69 = V_6 -> V_98 - 1 ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_81 ( struct V_5 * V_6 ,
struct V_273 * V_274 )
{
int V_23 ;
T_1 V_259 = V_6 -> V_258 . V_259 ;
if ( V_274 -> V_69 != V_278 &&
V_274 -> V_69 != ( V_278 | V_279 ) )
return - V_103 ;
switch ( V_274 -> V_256 ) {
case V_257 :
if ( V_274 -> V_69 == V_278 )
V_259 &= ~ V_263 ;
else if ( V_274 -> V_69 == ( V_278 | V_279 ) )
V_259 |= V_260 |
V_263 ;
break;
case V_268 :
if ( V_274 -> V_69 == V_278 )
V_259 &= ~ V_270 ;
else if ( V_274 -> V_69 == ( V_278 | V_279 ) )
V_259 |= V_269 |
V_270 ;
break;
case V_266 :
if ( ( V_274 -> V_69 == ( V_278 | V_279 ) ) &&
F_76 ( V_6 ) )
return - V_103 ;
if ( V_274 -> V_69 == V_278 )
V_259 &= ~ V_267 ;
else if ( V_274 -> V_69 == ( V_278 | V_279 ) )
V_259 |= V_260 |
V_267 ;
break;
case V_271 :
if ( ( V_274 -> V_69 == ( V_278 | V_279 ) ) &&
F_76 ( V_6 ) )
return - V_103 ;
if ( V_274 -> V_69 == V_278 )
V_259 &= ~ V_272 ;
else if ( V_274 -> V_69 == ( V_278 | V_279 ) )
V_259 |= V_269 |
V_272 ;
break;
default:
return - V_103 ;
}
if ( V_259 == V_6 -> V_258 . V_259 )
return 0 ;
V_23 = F_82 ( V_6 , V_6 -> V_258 . V_280 ,
V_259 , V_281 ,
V_6 -> V_258 . V_282 ) ;
if ( ! V_23 )
V_6 -> V_258 . V_259 = V_259 ;
return F_53 ( V_23 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_273 * V_274 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 = 0 ;
if ( ! F_80 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_33 ,
L_12 ) ;
return - V_103 ;
}
switch ( V_274 -> V_274 ) {
case V_283 :
V_23 = F_81 ( V_6 , V_274 ) ;
break;
default:
return - V_103 ;
}
return V_23 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_285 -> V_286 = V_6 -> V_287 ;
V_285 -> V_288 = F_85 ( V_6 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 ;
if ( V_285 -> V_289 || V_285 -> V_290 || V_285 -> V_291 ||
! V_285 -> V_286 || V_285 -> V_286 > F_85 ( V_6 ) )
return - V_103 ;
V_6 -> V_292 = V_285 -> V_286 ;
V_23 = F_87 ( V_6 ) ;
return F_53 ( V_23 ) ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
return V_281 ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
return V_293 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 * V_294 , T_2 * V_295 ,
T_2 * V_296 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_64 ;
struct V_258 * V_297 = & V_6 -> V_258 ;
if ( V_294 ) {
for ( V_64 = 0 ; V_64 < V_281 ; V_64 ++ )
V_294 [ V_64 ] = V_297 -> V_298 [ V_64 ] ;
}
if ( V_295 )
memcpy ( V_295 , V_297 -> V_282 , V_293 ) ;
if ( V_296 )
* V_296 = V_299 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , const T_1 * V_294 ,
const T_2 * V_295 , const T_2 V_296 )
{
int V_300 = 0 , V_64 , V_75 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_280 [ V_281 ] ;
if ( V_296 != V_301 && V_296 != V_299 )
return - V_205 ;
if ( V_294 ) {
struct V_70 * V_71 ;
for ( V_64 = 0 ; V_64 < V_281 ; V_64 ++ ) {
V_75 = V_294 [ V_64 ] ;
V_71 = & V_6 -> V_180 [ V_75 ] ;
V_280 [ V_64 ] = V_71 -> V_302 ;
V_6 -> V_258 . V_298 [ V_64 ] = V_75 ;
}
} else {
memcpy ( V_280 , V_6 -> V_258 . V_280 ,
V_281 ) ;
}
if ( ! V_295 )
V_295 = V_6 -> V_258 . V_282 ;
V_300 = F_82 ( V_6 , V_280 ,
V_6 -> V_258 . V_259 ,
V_281 , V_295 ) ;
if ( V_300 ) {
V_6 -> V_258 . V_259 = V_303 ;
return - V_38 ;
}
memcpy ( V_6 -> V_258 . V_282 , V_295 , V_293 ) ;
memcpy ( V_6 -> V_258 . V_280 , V_280 ,
V_281 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_304 * V_305 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_306 [ V_307 ] ;
int V_23 ;
if ( ! F_14 ( V_6 , V_40 ) )
return - V_205 ;
V_23 = F_93 ( V_6 , V_308 ,
V_306 ) ;
if ( ! V_23 ) {
if ( ! V_306 [ V_309 ] ) {
V_305 -> type = V_310 ;
V_305 -> V_311 = V_307 ;
} else {
V_305 -> type = V_312 ;
V_305 -> V_311 = 2 * V_307 ;
}
}
return F_53 ( V_23 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_242 * V_243 , T_2 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 ;
if ( ! F_14 ( V_6 , V_40 ) )
return - V_205 ;
V_23 = F_93 ( V_6 , V_308 ,
V_69 ) ;
if ( V_23 )
goto V_222;
if ( V_243 -> V_81 + V_243 -> V_44 > V_307 ) {
V_23 = F_93 ( V_6 ,
V_313 ,
V_69 +
V_307 ) ;
if ( V_23 )
goto V_222;
}
if ( V_243 -> V_81 )
memcpy ( V_69 , V_69 + V_243 -> V_81 , V_243 -> V_44 ) ;
V_222:
return F_53 ( V_23 ) ;
}
