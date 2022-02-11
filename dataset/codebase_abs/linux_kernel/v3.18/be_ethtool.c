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
V_29 . V_35 = F_8 ( V_6 -> V_16 , V_29 . V_33 ,
& V_29 . V_36 ) ;
if ( ! V_29 . V_35 ) {
F_9 ( & V_6 -> V_16 -> V_37 ,
L_2 ) ;
return - V_38 ;
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
V_22 &= V_39 ;
} else {
V_26 = - V_40 ;
break;
}
}
F_12 ( V_6 -> V_16 , V_29 . V_33 , V_29 . V_35 ,
V_29 . V_36 ) ;
return V_26 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_41 = 0 ;
if ( ! F_14 ( V_6 , V_42 ) )
return 0 ;
if ( F_15 ( V_6 ) ) {
if ( F_16 ( V_6 ) )
V_41 = F_5 ( V_6 ,
V_43 ) ;
else
F_17 ( V_6 , & V_41 ) ;
}
return V_41 ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_44 * V_45 , void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_15 ( V_6 ) ) {
memset ( V_28 , 0 , V_45 -> V_46 ) ;
if ( F_16 ( V_6 ) )
F_7 ( V_6 , V_43 ,
V_45 -> V_46 , V_28 ) ;
else
F_19 ( V_6 , V_45 -> V_46 , V_28 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_49 * V_50 = & V_6 -> V_51 [ 0 ] ;
V_48 -> V_52 = V_50 -> V_53 ;
V_48 -> V_54 = V_50 -> V_55 ;
V_48 -> V_56 = V_50 -> V_57 ;
V_48 -> V_58 = V_50 -> V_53 ;
V_48 -> V_59 = V_50 -> V_55 ;
V_48 -> V_60 = V_50 -> V_57 ;
V_48 -> V_61 = V_50 -> V_62 ;
V_48 -> V_63 = V_50 -> V_62 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_49 * V_50 = & V_6 -> V_51 [ 0 ] ;
struct V_64 * V_65 ;
int V_66 ;
F_22 (adapter, eqo, i) {
V_50 -> V_62 = V_48 -> V_61 ;
V_50 -> V_55 = F_23 ( V_48 -> V_54 , V_67 ) ;
V_50 -> V_57 = F_23 ( V_48 -> V_56 , V_50 -> V_55 ) ;
V_50 -> V_68 = F_23 ( V_48 -> V_52 , V_50 -> V_55 ) ;
V_50 -> V_68 = F_24 ( V_50 -> V_68 , V_50 -> V_57 ) ;
V_50 ++ ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
void * V_76 ;
unsigned int V_66 , V_77 , V_78 = 0 , V_79 ;
for ( V_66 = 0 ; V_66 < V_80 ; V_66 ++ ) {
V_76 = ( T_2 * ) & V_6 -> V_81 + V_82 [ V_66 ] . V_83 ;
V_71 [ V_66 ] = * ( T_1 * ) V_76 ;
}
V_78 += V_80 ;
F_26 (adapter, rxo, j) {
struct V_84 * V_70 = F_27 ( V_73 ) ;
do {
V_79 = F_28 ( & V_70 -> V_85 ) ;
V_71 [ V_78 ] = V_70 -> V_86 ;
V_71 [ V_78 + 1 ] = V_70 -> V_87 ;
} while ( F_29 ( & V_70 -> V_85 , V_79 ) );
for ( V_66 = 2 ; V_66 < V_88 ; V_66 ++ ) {
V_76 = ( T_2 * ) V_70 + V_89 [ V_66 ] . V_83 ;
V_71 [ V_78 + V_66 ] = * ( T_1 * ) V_76 ;
}
V_78 += V_88 ;
}
F_30 (adapter, txo, j) {
struct V_90 * V_70 = F_31 ( V_75 ) ;
do {
V_79 = F_28 ( & V_70 -> V_91 ) ;
V_71 [ V_78 ] = V_70 -> V_92 ;
} while ( F_29 ( & V_70 -> V_91 , V_79 ) );
do {
V_79 = F_28 ( & V_70 -> V_85 ) ;
for ( V_66 = 1 ; V_66 < V_93 ; V_66 ++ ) {
V_76 = ( T_2 * ) V_70 + V_94 [ V_66 ] . V_83 ;
V_71 [ V_78 + V_66 ] =
( V_94 [ V_66 ] . V_33 == sizeof( V_95 ) ) ?
* ( V_95 * ) V_76 : * ( T_1 * ) V_76 ;
}
} while ( F_29 ( & V_70 -> V_85 , V_79 ) );
V_78 += V_93 ;
}
}
static void F_32 ( struct V_1 * V_2 , T_4 V_96 ,
T_5 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_66 , V_77 ;
switch ( V_96 ) {
case V_97 :
for ( V_66 = 0 ; V_66 < V_80 ; V_66 ++ ) {
memcpy ( V_71 , V_82 [ V_66 ] . V_98 , V_99 ) ;
V_71 += V_99 ;
}
for ( V_66 = 0 ; V_66 < V_6 -> V_100 ; V_66 ++ ) {
for ( V_77 = 0 ; V_77 < V_88 ; V_77 ++ ) {
sprintf ( V_71 , L_3 , V_66 ,
V_89 [ V_77 ] . V_98 ) ;
V_71 += V_99 ;
}
}
for ( V_66 = 0 ; V_66 < V_6 -> V_101 ; V_66 ++ ) {
for ( V_77 = 0 ; V_77 < V_93 ; V_77 ++ ) {
sprintf ( V_71 , L_4 , V_66 ,
V_94 [ V_77 ] . V_98 ) ;
V_71 += V_99 ;
}
}
break;
case V_102 :
for ( V_66 = 0 ; V_66 < V_103 ; V_66 ++ ) {
memcpy ( V_71 , V_104 [ V_66 ] , V_99 ) ;
V_71 += V_99 ;
}
break;
}
}
static int F_33 ( struct V_1 * V_2 , int V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_96 ) {
case V_102 :
return V_103 ;
case V_97 :
return V_80 +
V_6 -> V_100 * V_88 +
V_6 -> V_101 * V_93 ;
default:
return - V_105 ;
}
}
static T_1 F_34 ( struct V_5 * V_6 )
{
T_1 V_106 ;
switch ( V_6 -> V_107 . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
V_106 = V_112 ;
break;
case V_113 :
if ( V_6 -> V_107 . V_114 & V_115 )
V_106 = V_116 ;
else
V_106 = V_117 ;
break;
case V_118 :
if ( V_6 -> V_107 . V_114 & V_119 )
V_106 = V_116 ;
else
V_106 = V_117 ;
break;
case V_120 :
case V_121 :
V_106 = V_117 ;
break;
case V_122 :
V_106 = V_112 ;
break;
default:
V_106 = V_123 ;
}
return V_106 ;
}
static T_1 F_35 ( struct V_5 * V_6 , T_1 V_124 )
{
T_1 V_125 = 0 ;
switch ( V_6 -> V_107 . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
V_125 |= V_126 ;
if ( V_124 & V_127 )
V_125 |= V_128 ;
if ( V_124 & V_129 )
V_125 |= V_130 ;
if ( V_124 & V_131 )
V_125 |= V_132 ;
break;
case V_133 :
V_125 |= V_134 ;
if ( V_124 & V_127 )
V_125 |= V_135 ;
if ( V_124 & V_136 )
V_125 |= V_137 ;
break;
case V_138 :
V_125 |= V_134 ;
if ( V_124 & V_136 )
V_125 |= V_139 ;
if ( V_124 & V_140 )
V_125 |= V_141 ;
break;
case V_142 :
V_125 |= V_134 |
V_139 ;
break;
case V_143 :
V_125 |= V_134 ;
if ( V_124 & V_136 )
V_125 |= V_139 ;
if ( V_124 & V_144 )
V_125 |= V_145 ;
break;
case V_118 :
if ( V_124 & V_144 ) {
switch ( V_6 -> V_107 . V_114 ) {
case V_119 :
V_125 |= V_146 ;
break;
case V_147 :
V_125 |= V_148 ;
break;
default:
V_125 |= V_149 ;
break;
}
}
case V_113 :
case V_120 :
case V_121 :
V_125 |= V_150 ;
if ( V_124 & V_136 )
V_125 |= V_151 ;
if ( V_124 & V_127 )
V_125 |= V_128 ;
break;
case V_122 :
V_125 |= V_126 ;
if ( V_124 & V_136 )
V_125 |= V_151 ;
if ( V_124 & V_127 )
V_125 |= V_128 ;
if ( V_124 & V_129 )
V_125 |= V_130 ;
break;
default:
V_125 |= V_126 ;
}
return V_125 ;
}
bool F_36 ( struct V_5 * V_6 )
{
return ( V_6 -> V_107 . V_108 == V_113 ||
V_6 -> V_107 . V_108 == V_120 ) ?
false : true ;
}
static int F_37 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_154 ;
T_6 V_155 = 0 ;
int V_26 ;
T_1 V_156 ;
T_1 V_157 ;
if ( V_6 -> V_107 . V_155 < 0 ) {
V_26 = F_38 ( V_6 , & V_155 ,
& V_154 , 0 ) ;
if ( ! V_26 )
F_39 ( V_6 , V_154 ) ;
F_40 ( V_153 , V_155 ) ;
V_26 = F_41 ( V_6 ) ;
if ( ! V_26 ) {
V_156 = V_6 -> V_107 . V_158 ;
V_157 = V_6 -> V_107 . V_159 ;
F_42 ( V_6 ) ;
V_153 -> V_160 =
F_35 ( V_6 ,
V_156 |
V_157 ) ;
V_153 -> V_161 =
F_35 ( V_6 , V_156 ) ;
V_153 -> V_106 = F_34 ( V_6 ) ;
if ( V_6 -> V_107 . V_158 ) {
V_153 -> V_160 |= V_162 ;
V_153 -> V_163 = V_164 ;
V_153 -> V_161 |= V_165 ;
}
V_153 -> V_160 |= V_166 ;
if ( F_36 ( V_6 ) )
V_153 -> V_161 |= V_167 ;
switch ( V_6 -> V_107 . V_108 ) {
case V_142 :
case V_133 :
V_153 -> V_168 = V_169 ;
break;
default:
V_153 -> V_168 = V_170 ;
break;
}
} else {
V_153 -> V_106 = V_123 ;
V_153 -> V_163 = V_171 ;
V_153 -> V_168 = V_172 ;
}
V_6 -> V_107 . V_155 = F_43 ( V_153 ) ;
V_6 -> V_107 . V_173 = V_153 -> V_106 ;
V_6 -> V_107 . V_168 = V_153 -> V_168 ;
V_6 -> V_107 . V_163 = V_153 -> V_163 ;
V_6 -> V_107 . V_161 = V_153 -> V_161 ;
V_6 -> V_107 . V_160 = V_153 -> V_160 ;
} else {
F_40 ( V_153 , V_6 -> V_107 . V_155 ) ;
V_153 -> V_106 = V_6 -> V_107 . V_173 ;
V_153 -> V_168 = V_6 -> V_107 . V_168 ;
V_153 -> V_163 = V_6 -> V_107 . V_163 ;
V_153 -> V_161 = V_6 -> V_107 . V_161 ;
V_153 -> V_160 = V_6 -> V_107 . V_160 ;
}
V_153 -> V_174 = F_44 ( V_2 ) ? V_175 : V_176 ;
V_153 -> V_177 = V_6 -> V_178 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_180 -> V_181 = V_6 -> V_182 [ 0 ] . V_183 . V_46 ;
V_180 -> V_184 = V_6 -> V_182 [ 0 ] . V_183 . V_46 ;
V_180 -> V_185 = V_6 -> V_186 [ 0 ] . V_183 . V_46 ;
V_180 -> V_187 = V_6 -> V_186 [ 0 ] . V_183 . V_46 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_188 * V_153 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_47 ( V_6 , & V_153 -> V_189 , & V_153 -> V_190 ) ;
V_153 -> V_163 = V_6 -> V_107 . V_191 ;
}
static int
F_48 ( struct V_1 * V_2 , struct V_188 * V_153 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_153 -> V_163 != V_6 -> V_107 . V_191 )
return - V_105 ;
V_6 -> V_192 = V_153 -> V_189 ;
V_6 -> V_193 = V_153 -> V_190 ;
V_26 = F_49 ( V_6 ,
V_6 -> V_192 , V_6 -> V_193 ) ;
if ( V_26 )
F_50 ( & V_6 -> V_16 -> V_37 , L_5 ) ;
return F_51 ( V_26 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_194 V_195 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_195 ) {
case V_196 :
F_53 ( V_6 , V_6 -> V_197 ,
& V_6 -> V_198 ) ;
return 1 ;
case V_199 :
F_54 ( V_6 , V_6 -> V_197 , 0 , 0 ,
V_200 ) ;
break;
case V_201 :
F_54 ( V_6 , V_6 -> V_197 , 0 , 0 ,
V_202 ) ;
break;
case V_203 :
F_54 ( V_6 , V_6 -> V_197 , 0 , 0 ,
V_6 -> V_198 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_206 * V_37 = & V_6 -> V_16 -> V_37 ;
int V_26 ;
if ( ! F_16 ( V_6 ) ||
! F_14 ( V_6 , V_42 ) )
return - V_207 ;
switch ( V_205 -> V_208 ) {
case V_209 :
V_26 = F_56 ( V_6 ) ;
if ( ! V_26 )
F_57 ( V_37 , L_6 ) ;
break;
case V_210 :
V_26 = F_58 ( V_6 ) ;
if ( ! V_26 )
F_57 ( V_37 , L_7 ) ;
break;
default:
F_9 ( V_37 , L_8 , V_205 -> V_208 ) ;
return - V_105 ;
}
return V_26 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_213 & V_214 ) {
V_212 -> V_160 |= V_215 ;
if ( V_6 -> V_216 )
V_212 -> V_217 |= V_215 ;
} else {
V_212 -> V_217 = 0 ;
}
memset ( & V_212 -> V_218 , 0 , sizeof( V_212 -> V_218 ) ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_212 -> V_217 & ~ V_215 )
return - V_207 ;
if ( ! ( V_6 -> V_213 & V_214 ) ) {
F_50 ( & V_6 -> V_16 -> V_37 , L_9 ) ;
return - V_207 ;
}
if ( V_212 -> V_217 & V_215 )
V_6 -> V_216 = true ;
else
V_6 -> V_216 = false ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
int V_219 , V_66 ;
struct V_24 V_220 ;
static const V_95 V_221 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_220 . V_33 = sizeof( struct V_222 ) ;
V_220 . V_35 = F_62 ( & V_6 -> V_16 -> V_37 , V_220 . V_33 ,
& V_220 . V_36 , V_223 ) ;
if ( ! V_220 . V_35 )
return - V_38 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
V_219 = F_63 ( V_6 , V_221 [ V_66 ] ,
4096 , & V_220 ) ;
if ( V_219 != 0 )
goto V_224;
}
V_224:
F_64 ( & V_6 -> V_16 -> V_37 , V_220 . V_33 , V_220 . V_35 ,
V_220 . V_36 ) ;
return F_51 ( V_219 ) ;
}
static V_95 F_65 ( struct V_5 * V_6 , T_2 V_225 ,
V_95 * V_26 )
{
F_66 ( V_6 , V_6 -> V_197 , V_225 , 1 ) ;
* V_26 = F_67 ( V_6 , V_6 -> V_197 ,
V_225 , 1500 , 2 , 0xabc ) ;
F_66 ( V_6 , V_6 -> V_197 , V_226 , 1 ) ;
return * V_26 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_227 * V_228 ,
V_95 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
T_2 V_154 = 0 ;
if ( V_6 -> V_229 & V_230 ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_10 ) ;
V_228 -> V_231 |= V_232 ;
return;
}
memset ( V_71 , 0 , sizeof( V_95 ) * V_103 ) ;
if ( V_228 -> V_231 & V_233 ) {
if ( F_65 ( V_6 , V_234 , & V_71 [ 0 ] ) != 0 )
V_228 -> V_231 |= V_232 ;
if ( F_65 ( V_6 , V_235 , & V_71 [ 1 ] ) != 0 )
V_228 -> V_231 |= V_232 ;
if ( V_228 -> V_231 & V_236 ) {
if ( F_65 ( V_6 , V_237 ,
& V_71 [ 2 ] ) != 0 )
V_228 -> V_231 |= V_232 ;
V_228 -> V_231 |= V_238 ;
}
}
if ( ! F_16 ( V_6 ) && F_61 ( V_6 ) != 0 ) {
V_71 [ 3 ] = 1 ;
V_228 -> V_231 |= V_232 ;
}
V_26 = F_38 ( V_6 , NULL , & V_154 , 0 ) ;
if ( V_26 ) {
V_228 -> V_231 |= V_232 ;
V_71 [ 4 ] = - 1 ;
} else if ( ! V_154 ) {
V_228 -> V_231 |= V_232 ;
V_71 [ 4 ] = 1 ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_239 * V_240 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_70 ( V_6 , V_240 -> V_71 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_6 , V_42 ) )
return 0 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_5 ( V_6 ,
V_241 ) ;
else
return F_5 ( V_6 ,
V_242 ) ;
} else {
return V_243 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_244 * V_245 , T_5 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_246 ;
struct V_247 * V_248 ;
int V_26 ;
if ( ! V_245 -> V_46 )
return - V_105 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_7 ( V_6 , V_241 ,
V_245 -> V_46 , V_71 ) ;
else
return F_7 ( V_6 , V_242 ,
V_245 -> V_46 , V_71 ) ;
}
V_245 -> V_249 = V_250 | ( V_6 -> V_16 -> V_206 << 16 ) ;
memset ( & V_246 , 0 , sizeof( struct V_24 ) ) ;
V_246 . V_33 = sizeof( struct V_251 ) ;
V_246 . V_35 = F_62 ( & V_6 -> V_16 -> V_37 , V_246 . V_33 ,
& V_246 . V_36 , V_223 ) ;
if ( ! V_246 . V_35 )
return - V_38 ;
V_26 = F_73 ( V_6 , & V_246 ) ;
if ( ! V_26 ) {
V_248 = V_246 . V_35 ;
memcpy ( V_71 , V_248 -> V_252 + V_245 -> V_83 , V_245 -> V_46 ) ;
}
F_64 ( & V_6 -> V_16 -> V_37 , V_246 . V_33 , V_246 . V_35 ,
V_246 . V_36 ) ;
return F_51 ( V_26 ) ;
}
static T_1 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_253 ;
}
static void F_75 ( struct V_1 * V_2 , T_1 V_254 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_253 == V_254 )
return;
if ( ( V_254 & V_255 ) != ( V_6 -> V_253 & V_255 ) )
if ( F_76 ( V_6 ) )
F_77 ( V_6 , V_254 & V_255 ?
V_256 :
V_257 ) ;
V_6 -> V_253 = V_254 ;
}
static V_95 F_78 ( struct V_5 * V_6 , V_95 V_258 )
{
V_95 V_71 = 0 ;
switch ( V_258 ) {
case V_259 :
if ( V_6 -> V_260 . V_261 & V_262 )
V_71 |= V_263 | V_264 ;
if ( V_6 -> V_260 . V_261 & V_265 )
V_71 |= V_266 | V_267 ;
break;
case V_268 :
if ( V_6 -> V_260 . V_261 & V_262 )
V_71 |= V_263 | V_264 ;
if ( V_6 -> V_260 . V_261 & V_269 )
V_71 |= V_266 | V_267 ;
break;
case V_270 :
if ( V_6 -> V_260 . V_261 & V_271 )
V_71 |= V_263 | V_264 ;
if ( V_6 -> V_260 . V_261 & V_272 )
V_71 |= V_266 | V_267 ;
break;
case V_273 :
if ( V_6 -> V_260 . V_261 & V_271 )
V_71 |= V_263 | V_264 ;
if ( V_6 -> V_260 . V_261 & V_274 )
V_71 |= V_266 | V_267 ;
break;
}
return V_71 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_275 * V_276 ,
T_1 * V_277 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_80 ( V_6 ) ) {
F_57 ( & V_6 -> V_16 -> V_37 ,
L_11 ) ;
return - V_105 ;
}
switch ( V_276 -> V_276 ) {
case V_278 :
V_276 -> V_71 = F_78 ( V_6 , V_276 -> V_258 ) ;
break;
case V_279 :
V_276 -> V_71 = V_6 -> V_100 - 1 ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_81 ( struct V_5 * V_6 ,
struct V_275 * V_276 )
{
struct V_72 * V_73 ;
int V_26 = 0 , V_66 , V_77 ;
T_2 V_280 [ 128 ] ;
T_1 V_261 = V_6 -> V_260 . V_261 ;
if ( V_276 -> V_71 != V_281 &&
V_276 -> V_71 != ( V_281 | V_282 ) )
return - V_105 ;
switch ( V_276 -> V_258 ) {
case V_259 :
if ( V_276 -> V_71 == V_281 )
V_261 &= ~ V_265 ;
else if ( V_276 -> V_71 == ( V_281 | V_282 ) )
V_261 |= V_262 |
V_265 ;
break;
case V_270 :
if ( V_276 -> V_71 == V_281 )
V_261 &= ~ V_272 ;
else if ( V_276 -> V_71 == ( V_281 | V_282 ) )
V_261 |= V_271 |
V_272 ;
break;
case V_268 :
if ( ( V_276 -> V_71 == ( V_281 | V_282 ) ) &&
F_76 ( V_6 ) )
return - V_105 ;
if ( V_276 -> V_71 == V_281 )
V_261 &= ~ V_269 ;
else if ( V_276 -> V_71 == ( V_281 | V_282 ) )
V_261 |= V_262 |
V_269 ;
break;
case V_273 :
if ( ( V_276 -> V_71 == ( V_281 | V_282 ) ) &&
F_76 ( V_6 ) )
return - V_105 ;
if ( V_276 -> V_71 == V_281 )
V_261 &= ~ V_274 ;
else if ( V_276 -> V_71 == ( V_281 | V_282 ) )
V_261 |= V_271 |
V_274 ;
break;
default:
return - V_105 ;
}
if ( V_261 == V_6 -> V_260 . V_261 )
return V_26 ;
if ( F_80 ( V_6 ) ) {
for ( V_77 = 0 ; V_77 < 128 ; V_77 += V_6 -> V_100 - 1 ) {
F_82 (adapter, rxo, i) {
if ( ( V_77 + V_66 ) >= 128 )
break;
V_280 [ V_77 + V_66 ] = V_73 -> V_283 ;
}
}
}
V_26 = F_83 ( V_6 , V_6 -> V_260 . V_280 ,
V_261 , 128 , V_6 -> V_260 . V_284 ) ;
if ( ! V_26 )
V_6 -> V_260 . V_261 = V_261 ;
return F_51 ( V_26 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_275 * V_276 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( ! F_80 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_37 ,
L_12 ) ;
return - V_105 ;
}
switch ( V_276 -> V_276 ) {
case V_285 :
V_26 = F_81 ( V_6 , V_276 ) ;
break;
default:
return - V_105 ;
}
return V_26 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_286 * V_287 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_287 -> V_288 = V_6 -> V_289 ;
V_287 -> V_290 = F_86 ( V_6 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_286 * V_287 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_287 -> V_291 || V_287 -> V_292 || V_287 -> V_293 ||
! V_287 -> V_288 || V_287 -> V_288 > F_86 ( V_6 ) )
return - V_105 ;
V_6 -> V_294 = V_287 -> V_288 ;
V_26 = F_88 ( V_6 ) ;
return F_51 ( V_26 ) ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
return V_295 ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
return V_296 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 * V_297 , T_2 * V_298 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_66 ;
struct V_260 * V_299 = & V_6 -> V_260 ;
if ( V_297 ) {
for ( V_66 = 0 ; V_66 < V_295 ; V_66 ++ )
V_297 [ V_66 ] = V_299 -> V_300 [ V_66 ] ;
}
if ( V_298 )
memcpy ( V_298 , V_299 -> V_284 , V_296 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , const T_1 * V_297 ,
const T_2 * V_298 )
{
int V_301 = 0 , V_66 , V_77 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_280 [ V_295 ] ;
if ( V_297 ) {
struct V_72 * V_73 ;
for ( V_66 = 0 ; V_66 < V_295 ; V_66 ++ ) {
V_77 = V_297 [ V_66 ] ;
V_73 = & V_6 -> V_182 [ V_77 ] ;
V_280 [ V_66 ] = V_73 -> V_283 ;
V_6 -> V_260 . V_300 [ V_66 ] = V_77 ;
}
} else {
memcpy ( V_280 , V_6 -> V_260 . V_280 ,
V_295 ) ;
}
if ( ! V_298 )
V_298 = V_6 -> V_260 . V_284 ;
V_301 = F_83 ( V_6 , V_280 ,
V_6 -> V_260 . V_261 ,
V_295 , V_298 ) ;
if ( V_301 ) {
V_6 -> V_260 . V_261 = V_302 ;
return - V_40 ;
}
memcpy ( V_6 -> V_260 . V_284 , V_298 , V_296 ) ;
memcpy ( V_6 -> V_260 . V_280 , V_280 ,
V_295 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_303 * V_304 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_305 [ V_306 ] ;
int V_26 ;
if ( ! F_14 ( V_6 , V_42 ) )
return - V_207 ;
V_26 = F_94 ( V_6 , V_307 ,
V_305 ) ;
if ( ! V_26 ) {
if ( ! V_305 [ V_308 ] ) {
V_304 -> type = V_309 ;
V_304 -> V_310 = V_306 ;
} else {
V_304 -> type = V_311 ;
V_304 -> V_310 = 2 * V_306 ;
}
}
return F_51 ( V_26 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_244 * V_245 , T_2 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( ! F_14 ( V_6 , V_42 ) )
return - V_207 ;
V_26 = F_94 ( V_6 , V_307 ,
V_71 ) ;
if ( V_26 )
goto V_224;
if ( V_245 -> V_83 + V_245 -> V_46 > V_306 ) {
V_26 = F_94 ( V_6 ,
V_312 ,
V_71 +
V_306 ) ;
if ( V_26 )
goto V_224;
}
if ( V_245 -> V_83 )
memcpy ( V_71 , V_71 + V_245 -> V_83 , V_245 -> V_46 ) ;
V_224:
return F_51 ( V_26 ) ;
}
