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
}
}
static int F_32 ( struct V_1 * V_2 , int V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_92 ) {
case V_98 :
return V_99 ;
case V_93 :
return V_76 +
V_6 -> V_96 * V_84 +
V_6 -> V_97 * V_89 ;
default:
return - V_101 ;
}
}
static T_1 F_33 ( struct V_5 * V_6 )
{
T_1 V_102 ;
switch ( V_6 -> V_103 . V_104 ) {
case V_105 :
case V_106 :
case V_107 :
V_102 = V_108 ;
break;
case V_109 :
if ( V_6 -> V_103 . V_110 & V_111 )
V_102 = V_112 ;
else
V_102 = V_113 ;
break;
case V_114 :
if ( V_6 -> V_103 . V_110 & V_115 )
V_102 = V_112 ;
else
V_102 = V_113 ;
break;
case V_116 :
case V_117 :
V_102 = V_113 ;
break;
case V_118 :
V_102 = V_108 ;
break;
default:
V_102 = V_119 ;
}
return V_102 ;
}
static T_1 F_34 ( struct V_5 * V_6 , T_1 V_120 )
{
T_1 V_121 = 0 ;
switch ( V_6 -> V_103 . V_104 ) {
case V_105 :
case V_106 :
case V_107 :
V_121 |= V_122 ;
if ( V_120 & V_123 )
V_121 |= V_124 ;
if ( V_120 & V_125 )
V_121 |= V_126 ;
if ( V_120 & V_127 )
V_121 |= V_128 ;
break;
case V_129 :
V_121 |= V_130 ;
if ( V_120 & V_123 )
V_121 |= V_131 ;
if ( V_120 & V_132 )
V_121 |= V_133 ;
break;
case V_134 :
V_121 |= V_130 ;
if ( V_120 & V_132 )
V_121 |= V_135 ;
if ( V_120 & V_136 )
V_121 |= V_137 ;
break;
case V_138 :
V_121 |= V_130 |
V_135 ;
break;
case V_139 :
V_121 |= V_130 ;
if ( V_120 & V_132 )
V_121 |= V_135 ;
if ( V_120 & V_140 )
V_121 |= V_141 ;
break;
case V_114 :
if ( V_120 & V_140 ) {
switch ( V_6 -> V_103 . V_110 ) {
case V_115 :
V_121 |= V_142 ;
break;
case V_143 :
V_121 |= V_144 ;
break;
default:
V_121 |= V_145 ;
break;
}
}
case V_109 :
case V_116 :
case V_117 :
V_121 |= V_146 ;
if ( V_120 & V_132 )
V_121 |= V_147 ;
if ( V_120 & V_123 )
V_121 |= V_124 ;
break;
case V_118 :
V_121 |= V_122 ;
if ( V_120 & V_132 )
V_121 |= V_147 ;
if ( V_120 & V_123 )
V_121 |= V_124 ;
if ( V_120 & V_125 )
V_121 |= V_126 ;
break;
default:
V_121 |= V_122 ;
}
return V_121 ;
}
bool F_35 ( struct V_5 * V_6 )
{
return ( V_6 -> V_103 . V_104 == V_109 ||
V_6 -> V_103 . V_104 == V_116 ) ?
false : true ;
}
static int F_36 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_150 ;
T_6 V_151 = 0 ;
int V_32 ;
T_1 V_152 ;
T_1 V_153 ;
if ( V_6 -> V_103 . V_151 < 0 ) {
V_32 = F_37 ( V_6 , & V_151 ,
& V_150 , 0 ) ;
if ( ! V_32 )
F_38 ( V_6 , V_150 ) ;
F_39 ( V_149 , V_151 ) ;
V_32 = F_40 ( V_6 ) ;
if ( ! V_32 ) {
V_152 = V_6 -> V_103 . V_154 ;
V_153 = V_6 -> V_103 . V_155 ;
F_41 ( V_6 ) ;
V_149 -> V_156 =
F_34 ( V_6 ,
V_152 |
V_153 ) ;
V_149 -> V_157 =
F_34 ( V_6 , V_152 ) ;
V_149 -> V_102 = F_33 ( V_6 ) ;
if ( V_6 -> V_103 . V_154 ) {
V_149 -> V_156 |= V_158 ;
V_149 -> V_159 = V_160 ;
V_149 -> V_157 |= V_161 ;
}
V_149 -> V_156 |= V_162 ;
if ( F_35 ( V_6 ) )
V_149 -> V_157 |= V_163 ;
switch ( V_6 -> V_103 . V_104 ) {
case V_138 :
case V_129 :
V_149 -> V_164 = V_165 ;
break;
default:
V_149 -> V_164 = V_166 ;
break;
}
} else {
V_149 -> V_102 = V_119 ;
V_149 -> V_159 = V_167 ;
V_149 -> V_164 = V_168 ;
}
V_6 -> V_103 . V_151 = F_42 ( V_149 ) ;
V_6 -> V_103 . V_169 = V_149 -> V_102 ;
V_6 -> V_103 . V_164 = V_149 -> V_164 ;
V_6 -> V_103 . V_159 = V_149 -> V_159 ;
V_6 -> V_103 . V_157 = V_149 -> V_157 ;
V_6 -> V_103 . V_156 = V_149 -> V_156 ;
} else {
F_39 ( V_149 , V_6 -> V_103 . V_151 ) ;
V_149 -> V_102 = V_6 -> V_103 . V_169 ;
V_149 -> V_164 = V_6 -> V_103 . V_164 ;
V_149 -> V_159 = V_6 -> V_103 . V_159 ;
V_149 -> V_157 = V_6 -> V_103 . V_157 ;
V_149 -> V_156 = V_6 -> V_103 . V_156 ;
}
V_149 -> V_170 = F_43 ( V_2 ) ? V_171 : V_172 ;
V_149 -> V_173 = V_6 -> V_174 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_176 -> V_177 = V_6 -> V_178 [ 0 ] . V_179 . V_180 ;
V_176 -> V_181 = V_6 -> V_178 [ 0 ] . V_179 . V_180 ;
V_176 -> V_182 = V_6 -> V_183 [ 0 ] . V_179 . V_180 ;
V_176 -> V_184 = V_6 -> V_183 [ 0 ] . V_179 . V_180 ;
}
static void
F_45 ( struct V_1 * V_2 , struct V_185 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_46 ( V_6 , & V_149 -> V_186 , & V_149 -> V_187 ) ;
V_149 -> V_159 = V_6 -> V_103 . V_188 ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_185 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( V_149 -> V_159 != V_6 -> V_103 . V_188 )
return - V_101 ;
V_32 = F_48 ( V_6 , V_149 -> V_186 ,
V_149 -> V_187 ) ;
if ( V_32 ) {
F_49 ( & V_6 -> V_16 -> V_36 , L_5 ) ;
return F_50 ( V_32 ) ;
}
V_6 -> V_189 = V_149 -> V_186 ;
V_6 -> V_190 = V_149 -> V_187 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_191 V_192 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 = 0 ;
switch ( V_192 ) {
case V_193 :
V_32 = F_52 ( V_6 , V_6 -> V_194 ,
& V_6 -> V_195 ) ;
if ( V_32 )
return F_50 ( V_32 ) ;
return 1 ;
case V_196 :
V_32 = F_53 ( V_6 , V_6 -> V_194 ,
0 , 0 , V_197 ) ;
break;
case V_198 :
V_32 = F_53 ( V_6 , V_6 -> V_194 ,
0 , 0 , V_199 ) ;
break;
case V_200 :
V_32 = F_53 ( V_6 , V_6 -> V_194 ,
0 , 0 , V_6 -> V_195 ) ;
}
return F_50 ( V_32 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_203 * V_36 = & V_6 -> V_16 -> V_36 ;
int V_32 ;
if ( ! F_8 ( V_6 ) ||
! F_55 ( V_6 , V_204 ) )
return - V_205 ;
switch ( V_202 -> V_206 ) {
case V_207 :
V_32 = F_56 ( V_6 ) ;
if ( ! V_32 )
F_57 ( V_36 , L_6 ) ;
break;
case V_208 :
V_32 = F_58 ( V_6 ) ;
if ( ! V_32 )
F_57 ( V_36 , L_7 ) ;
break;
default:
F_11 ( V_36 , L_8 , V_202 -> V_206 ) ;
return - V_101 ;
}
return V_32 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_211 & V_212 ) {
V_210 -> V_156 |= V_213 ;
if ( V_6 -> V_214 )
V_210 -> V_215 |= V_213 ;
} else {
V_210 -> V_215 = 0 ;
}
memset ( & V_210 -> V_216 , 0 , sizeof( V_210 -> V_216 ) ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_209 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_210 -> V_215 & ~ V_213 )
return - V_205 ;
if ( ! ( V_6 -> V_211 & V_212 ) ) {
F_49 ( & V_6 -> V_16 -> V_36 , L_9 ) ;
return - V_205 ;
}
if ( V_210 -> V_215 & V_213 )
V_6 -> V_214 = true ;
else
V_6 -> V_214 = false ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
int V_217 , V_62 ;
struct V_21 V_218 ;
static const V_91 V_219 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_218 . V_33 = sizeof( struct V_220 ) ;
V_218 . V_35 = F_10 ( & V_6 -> V_16 -> V_36 ,
V_218 . V_33 , & V_218 . V_37 ,
V_221 ) ;
if ( ! V_218 . V_35 )
return - V_39 ;
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
V_217 = F_62 ( V_6 , V_219 [ V_62 ] ,
4096 , & V_218 ) ;
if ( V_217 != 0 )
goto V_222;
}
V_222:
F_14 ( & V_6 -> V_16 -> V_36 , V_218 . V_33 , V_218 . V_35 ,
V_218 . V_37 ) ;
return F_50 ( V_217 ) ;
}
static V_91 F_63 ( struct V_5 * V_6 , T_2 V_223 ,
V_91 * V_32 )
{
int V_217 ;
V_217 = F_64 ( V_6 , V_6 -> V_194 ,
V_223 , 1 ) ;
if ( V_217 )
return V_217 ;
* V_32 = F_65 ( V_6 , V_6 -> V_194 ,
V_223 , 1500 , 2 , 0xabc ) ;
V_217 = F_64 ( V_6 , V_6 -> V_194 ,
V_224 , 1 ) ;
if ( V_217 )
return V_217 ;
return * V_32 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_225 * V_226 ,
V_91 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
T_2 V_150 = 0 ;
if ( V_6 -> V_227 & V_228 ) {
F_11 ( & V_6 -> V_16 -> V_36 , L_10 ) ;
V_226 -> V_229 |= V_230 ;
return;
}
memset ( V_67 , 0 , sizeof( V_91 ) * V_99 ) ;
if ( V_226 -> V_229 & V_231 ) {
if ( F_63 ( V_6 , V_232 , & V_67 [ 0 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
if ( F_63 ( V_6 , V_233 , & V_67 [ 1 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
if ( V_226 -> V_229 & V_234 ) {
if ( F_63 ( V_6 , V_235 ,
& V_67 [ 2 ] ) != 0 )
V_226 -> V_229 |= V_230 ;
V_226 -> V_229 |= V_236 ;
}
}
if ( ! F_8 ( V_6 ) && F_61 ( V_6 ) != 0 ) {
V_67 [ 3 ] = 1 ;
V_226 -> V_229 |= V_230 ;
}
V_32 = F_37 ( V_6 , NULL , & V_150 , 0 ) ;
if ( V_32 ) {
V_226 -> V_229 |= V_230 ;
V_67 [ 4 ] = - 1 ;
} else if ( ! V_150 ) {
V_226 -> V_229 |= V_230 ;
V_67 [ 4 ] = 1 ;
}
}
static int F_67 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_68 ( V_6 , V_238 -> V_67 ) ;
}
static int
F_69 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( V_6 , V_204 ) )
return - V_205 ;
V_202 -> V_180 = F_7 ( V_6 ) ;
V_202 -> V_9 = 1 ;
V_202 -> V_206 = 0x1 ;
return 0 ;
}
static int
F_70 ( struct V_1 * V_2 , struct V_201 * V_202 ,
void * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( ! F_55 ( V_6 , V_204 ) )
return - V_205 ;
V_32 = F_15 ( V_6 , V_202 -> V_180 , V_27 ) ;
return F_50 ( V_32 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( V_6 , V_204 ) )
return 0 ;
if ( F_8 ( V_6 ) ) {
if ( F_72 ( V_6 ) )
return F_5 ( V_6 ,
V_239 ) ;
else
return F_5 ( V_6 ,
V_240 ) ;
} else {
return V_241 ;
}
}
static int F_73 ( struct V_1 * V_2 ,
struct V_242 * V_243 , T_5 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 V_244 ;
struct V_245 * V_246 ;
int V_32 ;
if ( ! V_243 -> V_180 )
return - V_101 ;
if ( F_8 ( V_6 ) ) {
if ( F_72 ( V_6 ) )
return F_9 ( V_6 , V_239 ,
V_243 -> V_180 , V_67 ) ;
else
return F_9 ( V_6 , V_240 ,
V_243 -> V_180 , V_67 ) ;
}
V_243 -> V_247 = V_248 | ( V_6 -> V_16 -> V_203 << 16 ) ;
memset ( & V_244 , 0 , sizeof( struct V_21 ) ) ;
V_244 . V_33 = sizeof( struct V_249 ) ;
V_244 . V_35 = F_10 ( & V_6 -> V_16 -> V_36 ,
V_244 . V_33 , & V_244 . V_37 ,
V_221 ) ;
if ( ! V_244 . V_35 )
return - V_39 ;
V_32 = F_74 ( V_6 , & V_244 ) ;
if ( ! V_32 ) {
V_246 = V_244 . V_35 ;
memcpy ( V_67 , V_246 -> V_250 + V_243 -> V_79 , V_243 -> V_180 ) ;
}
F_14 ( & V_6 -> V_16 -> V_36 , V_244 . V_33 , V_244 . V_35 ,
V_244 . V_37 ) ;
return F_50 ( V_32 ) ;
}
static T_1 F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_251 ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_252 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_251 == V_252 )
return;
if ( ( V_252 & V_253 ) != ( V_6 -> V_251 & V_253 ) )
if ( F_77 ( V_6 ) )
F_78 ( V_6 , V_252 & V_253 ?
V_254 :
V_255 ) ;
V_6 -> V_251 = V_252 ;
}
static V_91 F_79 ( struct V_5 * V_6 , V_91 V_256 )
{
V_91 V_67 = 0 ;
switch ( V_256 ) {
case V_257 :
if ( V_6 -> V_258 . V_259 & V_260 )
V_67 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_263 )
V_67 |= V_264 | V_265 ;
break;
case V_266 :
if ( V_6 -> V_258 . V_259 & V_260 )
V_67 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_267 )
V_67 |= V_264 | V_265 ;
break;
case V_268 :
if ( V_6 -> V_258 . V_259 & V_269 )
V_67 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_270 )
V_67 |= V_264 | V_265 ;
break;
case V_271 :
if ( V_6 -> V_258 . V_259 & V_269 )
V_67 |= V_261 | V_262 ;
if ( V_6 -> V_258 . V_259 & V_272 )
V_67 |= V_264 | V_265 ;
break;
}
return V_67 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_273 * V_274 ,
T_1 * V_275 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_81 ( V_6 ) ) {
F_57 ( & V_6 -> V_16 -> V_36 ,
L_11 ) ;
return - V_101 ;
}
switch ( V_274 -> V_274 ) {
case V_276 :
V_274 -> V_67 = F_79 ( V_6 , V_274 -> V_256 ) ;
break;
case V_277 :
V_274 -> V_67 = V_6 -> V_96 - 1 ;
break;
default:
return - V_101 ;
}
return 0 ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_273 * V_274 )
{
int V_32 ;
T_1 V_259 = V_6 -> V_258 . V_259 ;
if ( V_274 -> V_67 != V_278 &&
V_274 -> V_67 != ( V_278 | V_279 ) )
return - V_101 ;
switch ( V_274 -> V_256 ) {
case V_257 :
if ( V_274 -> V_67 == V_278 )
V_259 &= ~ V_263 ;
else if ( V_274 -> V_67 == ( V_278 | V_279 ) )
V_259 |= V_260 |
V_263 ;
break;
case V_268 :
if ( V_274 -> V_67 == V_278 )
V_259 &= ~ V_270 ;
else if ( V_274 -> V_67 == ( V_278 | V_279 ) )
V_259 |= V_269 |
V_270 ;
break;
case V_266 :
if ( ( V_274 -> V_67 == ( V_278 | V_279 ) ) &&
F_77 ( V_6 ) )
return - V_101 ;
if ( V_274 -> V_67 == V_278 )
V_259 &= ~ V_267 ;
else if ( V_274 -> V_67 == ( V_278 | V_279 ) )
V_259 |= V_260 |
V_267 ;
break;
case V_271 :
if ( ( V_274 -> V_67 == ( V_278 | V_279 ) ) &&
F_77 ( V_6 ) )
return - V_101 ;
if ( V_274 -> V_67 == V_278 )
V_259 &= ~ V_272 ;
else if ( V_274 -> V_67 == ( V_278 | V_279 ) )
V_259 |= V_269 |
V_272 ;
break;
default:
return - V_101 ;
}
if ( V_259 == V_6 -> V_258 . V_259 )
return 0 ;
V_32 = F_83 ( V_6 , V_6 -> V_258 . V_280 ,
V_259 , V_281 ,
V_6 -> V_258 . V_282 ) ;
if ( ! V_32 )
V_6 -> V_258 . V_259 = V_259 ;
return F_50 ( V_32 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_273 * V_274 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 = 0 ;
if ( ! F_81 ( V_6 ) ) {
F_11 ( & V_6 -> V_16 -> V_36 ,
L_12 ) ;
return - V_101 ;
}
switch ( V_274 -> V_274 ) {
case V_283 :
V_32 = F_82 ( V_6 , V_274 ) ;
break;
default:
return - V_101 ;
}
return V_32 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_285 -> V_286 = V_6 -> V_287 ;
V_285 -> V_288 = F_86 ( V_6 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( V_285 -> V_289 || V_285 -> V_290 || V_285 -> V_291 ||
! V_285 -> V_286 || V_285 -> V_286 > F_86 ( V_6 ) )
return - V_101 ;
V_6 -> V_292 = V_285 -> V_286 ;
V_32 = F_88 ( V_6 ) ;
return F_50 ( V_32 ) ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
return V_281 ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
return V_293 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_294 , T_2 * V_295 ,
T_2 * V_296 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_62 ;
struct V_258 * V_297 = & V_6 -> V_258 ;
if ( V_294 ) {
for ( V_62 = 0 ; V_62 < V_281 ; V_62 ++ )
V_294 [ V_62 ] = V_297 -> V_298 [ V_62 ] ;
}
if ( V_295 )
memcpy ( V_295 , V_297 -> V_282 , V_293 ) ;
if ( V_296 )
* V_296 = V_299 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , const T_1 * V_294 ,
const T_2 * V_295 , const T_2 V_296 )
{
int V_300 = 0 , V_62 , V_73 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_280 [ V_281 ] ;
if ( V_296 != V_301 && V_296 != V_299 )
return - V_205 ;
if ( V_294 ) {
struct V_68 * V_69 ;
for ( V_62 = 0 ; V_62 < V_281 ; V_62 ++ ) {
V_73 = V_294 [ V_62 ] ;
V_69 = & V_6 -> V_178 [ V_73 ] ;
V_280 [ V_62 ] = V_69 -> V_302 ;
V_6 -> V_258 . V_298 [ V_62 ] = V_73 ;
}
} else {
memcpy ( V_280 , V_6 -> V_258 . V_280 ,
V_281 ) ;
}
if ( ! V_295 )
V_295 = V_6 -> V_258 . V_282 ;
V_300 = F_83 ( V_6 , V_280 ,
V_6 -> V_258 . V_259 ,
V_281 , V_295 ) ;
if ( V_300 ) {
V_6 -> V_258 . V_259 = V_303 ;
return - V_41 ;
}
memcpy ( V_6 -> V_258 . V_282 , V_295 , V_293 ) ;
memcpy ( V_6 -> V_258 . V_280 , V_280 ,
V_281 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_304 * V_305 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_306 [ V_307 ] ;
int V_32 ;
if ( ! F_55 ( V_6 , V_204 ) )
return - V_205 ;
V_32 = F_94 ( V_6 , V_308 ,
V_306 ) ;
if ( ! V_32 ) {
if ( ! V_306 [ V_309 ] ) {
V_305 -> type = V_310 ;
V_305 -> V_311 = V_307 ;
} else {
V_305 -> type = V_312 ;
V_305 -> V_311 = 2 * V_307 ;
}
}
return F_50 ( V_32 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_242 * V_243 , T_2 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_32 ;
if ( ! F_55 ( V_6 , V_204 ) )
return - V_205 ;
V_32 = F_94 ( V_6 , V_308 ,
V_67 ) ;
if ( V_32 )
goto V_222;
if ( V_243 -> V_79 + V_243 -> V_180 > V_307 ) {
V_32 = F_94 ( V_6 ,
V_313 ,
V_67 +
V_307 ) ;
if ( V_32 )
goto V_222;
}
if ( V_243 -> V_79 )
memcpy ( V_67 , V_67 + V_243 -> V_79 , V_243 -> V_180 ) ;
V_222:
return F_50 ( V_32 ) ;
}
