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
static T_1 F_34 ( T_1 V_106 , T_1 V_107 )
{
T_1 V_108 ;
switch ( V_106 ) {
case V_109 :
case V_110 :
case V_111 :
V_108 = V_112 ;
break;
case V_113 :
V_108 = V_107 ? V_114 : V_115 ;
break;
case V_116 :
case V_117 :
V_108 = V_115 ;
break;
case V_118 :
V_108 = V_112 ;
break;
default:
V_108 = V_119 ;
}
return V_108 ;
}
static T_1 F_35 ( T_1 V_120 , T_1 V_121 )
{
T_1 V_122 = 0 ;
switch ( V_120 ) {
case V_109 :
case V_110 :
case V_111 :
V_122 |= V_123 ;
if ( V_121 & V_124 )
V_122 |= V_125 ;
if ( V_121 & V_126 )
V_122 |= V_127 ;
if ( V_121 & V_128 )
V_122 |= V_129 ;
break;
case V_130 :
V_122 |= V_131 ;
if ( V_121 & V_124 )
V_122 |= V_132 ;
if ( V_121 & V_133 )
V_122 |= V_134 ;
break;
case V_135 :
V_122 |= V_131 |
V_136 ;
break;
case V_113 :
case V_116 :
case V_117 :
V_122 |= V_137 ;
if ( V_121 & V_133 )
V_122 |= V_138 ;
if ( V_121 & V_124 )
V_122 |= V_125 ;
break;
case V_118 :
V_122 |= V_123 ;
if ( V_121 & V_133 )
V_122 |= V_138 ;
if ( V_121 & V_124 )
V_122 |= V_125 ;
if ( V_121 & V_126 )
V_122 |= V_127 ;
break;
default:
V_122 |= V_123 ;
}
return V_122 ;
}
bool F_36 ( struct V_5 * V_6 )
{
return ( V_6 -> V_139 . V_140 == V_113 ||
V_6 -> V_139 . V_140 == V_116 ) ?
false : true ;
}
static int F_37 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_143 ;
T_6 V_144 = 0 ;
int V_26 ;
T_1 V_145 ;
T_1 V_146 ;
T_1 V_107 ;
T_6 V_140 ;
if ( V_6 -> V_139 . V_144 < 0 ) {
V_26 = F_38 ( V_6 , & V_144 ,
& V_143 , 0 ) ;
if ( ! V_26 )
F_39 ( V_6 , V_143 ) ;
F_40 ( V_142 , V_144 ) ;
V_26 = F_41 ( V_6 ) ;
if ( ! V_26 ) {
V_140 = V_6 -> V_139 . V_140 ;
V_145 = V_6 -> V_139 . V_147 ;
V_146 = V_6 -> V_139 . V_148 ;
V_107 = V_6 -> V_139 . V_107 ;
V_142 -> V_149 =
F_35 ( V_140 ,
V_145 |
V_146 ) ;
V_142 -> V_150 =
F_35 ( V_140 ,
V_145 ) ;
V_142 -> V_108 = F_34 ( V_140 ,
V_107 ) ;
if ( V_6 -> V_139 . V_147 ) {
V_142 -> V_149 |= V_151 ;
V_142 -> V_152 = V_153 ;
V_142 -> V_150 |= V_154 ;
}
V_142 -> V_149 |= V_155 ;
if ( F_36 ( V_6 ) )
V_142 -> V_150 |= V_156 ;
switch ( V_6 -> V_139 . V_140 ) {
case V_135 :
case V_130 :
V_142 -> V_157 = V_158 ;
break;
default:
V_142 -> V_157 = V_159 ;
break;
}
} else {
V_142 -> V_108 = V_119 ;
V_142 -> V_152 = V_160 ;
V_142 -> V_157 = V_161 ;
}
V_6 -> V_139 . V_144 = F_42 ( V_142 ) ;
V_6 -> V_139 . V_162 = V_142 -> V_108 ;
V_6 -> V_139 . V_157 = V_142 -> V_157 ;
V_6 -> V_139 . V_152 = V_142 -> V_152 ;
V_6 -> V_139 . V_150 = V_142 -> V_150 ;
V_6 -> V_139 . V_149 = V_142 -> V_149 ;
} else {
F_40 ( V_142 , V_6 -> V_139 . V_144 ) ;
V_142 -> V_108 = V_6 -> V_139 . V_162 ;
V_142 -> V_157 = V_6 -> V_139 . V_157 ;
V_142 -> V_152 = V_6 -> V_139 . V_152 ;
V_142 -> V_150 = V_6 -> V_139 . V_150 ;
V_142 -> V_149 = V_6 -> V_139 . V_149 ;
}
V_142 -> V_163 = F_43 ( V_2 ) ? V_164 : V_165 ;
V_142 -> V_166 = V_6 -> V_167 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_169 -> V_170 = V_169 -> V_171 = V_6 -> V_172 [ 0 ] . V_173 . V_46 ;
V_169 -> V_174 = V_169 -> V_175 = V_6 -> V_176 [ 0 ] . V_173 . V_46 ;
}
static void
F_45 ( struct V_1 * V_2 , struct V_177 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_46 ( V_6 , & V_142 -> V_178 , & V_142 -> V_179 ) ;
V_142 -> V_152 = V_6 -> V_139 . V_180 ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_177 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_142 -> V_152 != V_6 -> V_139 . V_180 )
return - V_105 ;
V_6 -> V_181 = V_142 -> V_178 ;
V_6 -> V_182 = V_142 -> V_179 ;
V_26 = F_48 ( V_6 ,
V_6 -> V_181 , V_6 -> V_182 ) ;
if ( V_26 )
F_49 ( & V_6 -> V_16 -> V_37 , L_5 ) ;
return F_50 ( V_26 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_183 V_184 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_184 ) {
case V_185 :
F_52 ( V_6 , V_6 -> V_186 ,
& V_6 -> V_187 ) ;
return 1 ;
case V_188 :
F_53 ( V_6 , V_6 -> V_186 , 0 , 0 ,
V_189 ) ;
break;
case V_190 :
F_53 ( V_6 , V_6 -> V_186 , 0 , 0 ,
V_191 ) ;
break;
case V_192 :
F_53 ( V_6 , V_6 -> V_186 , 0 , 0 ,
V_6 -> V_187 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_193 * V_194 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_195 * V_37 = & V_6 -> V_16 -> V_37 ;
int V_26 ;
if ( ! F_16 ( V_6 ) ||
! F_14 ( V_6 , V_42 ) )
return - V_196 ;
switch ( V_194 -> V_197 ) {
case V_198 :
V_26 = F_55 ( V_6 ) ;
if ( ! V_26 )
F_56 ( V_37 , L_6 ) ;
break;
case V_199 :
V_26 = F_57 ( V_6 ) ;
if ( ! V_26 )
F_56 ( V_37 , L_7 ) ;
break;
default:
F_9 ( V_37 , L_8 , V_194 -> V_197 ) ;
return - V_105 ;
}
return V_26 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_202 & V_203 ) {
V_201 -> V_149 |= V_204 ;
if ( V_6 -> V_205 )
V_201 -> V_206 |= V_204 ;
} else {
V_201 -> V_206 = 0 ;
}
memset ( & V_201 -> V_207 , 0 , sizeof( V_201 -> V_207 ) ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_201 -> V_206 & ~ V_204 )
return - V_196 ;
if ( ! ( V_6 -> V_202 & V_203 ) ) {
F_49 ( & V_6 -> V_16 -> V_37 , L_9 ) ;
return - V_196 ;
}
if ( V_201 -> V_206 & V_204 )
V_6 -> V_205 = true ;
else
V_6 -> V_205 = false ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
int V_208 , V_66 ;
struct V_24 V_209 ;
static const V_95 V_210 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_209 . V_33 = sizeof( struct V_211 ) ;
V_209 . V_35 = F_61 ( & V_6 -> V_16 -> V_37 , V_209 . V_33 ,
& V_209 . V_36 , V_212 ) ;
if ( ! V_209 . V_35 )
return - V_38 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
V_208 = F_62 ( V_6 , V_210 [ V_66 ] ,
4096 , & V_209 ) ;
if ( V_208 != 0 )
goto V_213;
}
V_213:
F_63 ( & V_6 -> V_16 -> V_37 , V_209 . V_33 , V_209 . V_35 ,
V_209 . V_36 ) ;
return F_50 ( V_208 ) ;
}
static V_95 F_64 ( struct V_5 * V_6 , T_2 V_214 ,
V_95 * V_26 )
{
F_65 ( V_6 , V_6 -> V_186 , V_214 , 1 ) ;
* V_26 = F_66 ( V_6 , V_6 -> V_186 ,
V_214 , 1500 , 2 , 0xabc ) ;
F_65 ( V_6 , V_6 -> V_186 , V_215 , 1 ) ;
return * V_26 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_216 * V_217 ,
V_95 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
T_2 V_143 = 0 ;
if ( V_6 -> V_218 & V_219 ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_10 ) ;
V_217 -> V_220 |= V_221 ;
return;
}
memset ( V_71 , 0 , sizeof( V_95 ) * V_103 ) ;
if ( V_217 -> V_220 & V_222 ) {
if ( F_64 ( V_6 , V_223 , & V_71 [ 0 ] ) != 0 )
V_217 -> V_220 |= V_221 ;
if ( F_64 ( V_6 , V_224 , & V_71 [ 1 ] ) != 0 )
V_217 -> V_220 |= V_221 ;
if ( V_217 -> V_220 & V_225 ) {
if ( F_64 ( V_6 , V_226 ,
& V_71 [ 2 ] ) != 0 )
V_217 -> V_220 |= V_221 ;
V_217 -> V_220 |= V_227 ;
}
}
if ( ! F_16 ( V_6 ) && F_60 ( V_6 ) != 0 ) {
V_71 [ 3 ] = 1 ;
V_217 -> V_220 |= V_221 ;
}
V_26 = F_38 ( V_6 , NULL , & V_143 , 0 ) ;
if ( V_26 ) {
V_217 -> V_220 |= V_221 ;
V_71 [ 4 ] = - 1 ;
} else if ( ! V_143 ) {
V_217 -> V_220 |= V_221 ;
V_71 [ 4 ] = 1 ;
}
}
static int F_68 ( struct V_1 * V_2 , struct V_228 * V_229 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_69 ( V_6 , V_229 -> V_71 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_6 , V_42 ) )
return 0 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_5 ( V_6 ,
V_230 ) ;
else
return F_5 ( V_6 ,
V_231 ) ;
} else {
return V_232 ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_233 * V_234 , T_5 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_235 ;
struct V_236 * V_237 ;
int V_26 ;
if ( ! V_234 -> V_46 )
return - V_105 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_7 ( V_6 , V_230 ,
V_234 -> V_46 , V_71 ) ;
else
return F_7 ( V_6 , V_231 ,
V_234 -> V_46 , V_71 ) ;
}
V_234 -> V_238 = V_239 | ( V_6 -> V_16 -> V_195 << 16 ) ;
memset ( & V_235 , 0 , sizeof( struct V_24 ) ) ;
V_235 . V_33 = sizeof( struct V_240 ) ;
V_235 . V_35 = F_61 ( & V_6 -> V_16 -> V_37 , V_235 . V_33 ,
& V_235 . V_36 , V_212 ) ;
if ( ! V_235 . V_35 )
return - V_38 ;
V_26 = F_72 ( V_6 , & V_235 ) ;
if ( ! V_26 ) {
V_237 = V_235 . V_35 ;
memcpy ( V_71 , V_237 -> V_241 + V_234 -> V_83 , V_234 -> V_46 ) ;
}
F_63 ( & V_6 -> V_16 -> V_37 , V_235 . V_33 , V_235 . V_35 ,
V_235 . V_36 ) ;
return F_50 ( V_26 ) ;
}
static T_1 F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_242 ;
}
static void F_74 ( struct V_1 * V_2 , T_1 V_243 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_242 == V_243 )
return;
if ( ( V_243 & V_244 ) != ( V_6 -> V_242 & V_244 ) )
if ( F_75 ( V_6 ) )
F_76 ( V_6 , V_243 & V_244 ?
V_245 :
V_246 ) ;
V_6 -> V_242 = V_243 ;
return;
}
static V_95 F_77 ( struct V_5 * V_6 , V_95 V_247 )
{
V_95 V_71 = 0 ;
switch ( V_247 ) {
case V_248 :
if ( V_6 -> V_249 . V_250 & V_251 )
V_71 |= V_252 | V_253 ;
if ( V_6 -> V_249 . V_250 & V_254 )
V_71 |= V_255 | V_256 ;
break;
case V_257 :
if ( V_6 -> V_249 . V_250 & V_251 )
V_71 |= V_252 | V_253 ;
if ( V_6 -> V_249 . V_250 & V_258 )
V_71 |= V_255 | V_256 ;
break;
case V_259 :
if ( V_6 -> V_249 . V_250 & V_260 )
V_71 |= V_252 | V_253 ;
if ( V_6 -> V_249 . V_250 & V_261 )
V_71 |= V_255 | V_256 ;
break;
case V_262 :
if ( V_6 -> V_249 . V_250 & V_260 )
V_71 |= V_252 | V_253 ;
if ( V_6 -> V_249 . V_250 & V_263 )
V_71 |= V_255 | V_256 ;
break;
}
return V_71 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_264 * V_265 ,
T_1 * V_266 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_79 ( V_6 ) ) {
F_56 ( & V_6 -> V_16 -> V_37 ,
L_11 ) ;
return - V_105 ;
}
switch ( V_265 -> V_265 ) {
case V_267 :
V_265 -> V_71 = F_77 ( V_6 , V_265 -> V_247 ) ;
break;
case V_268 :
V_265 -> V_71 = V_6 -> V_100 - 1 ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_80 ( struct V_5 * V_6 ,
struct V_264 * V_265 )
{
struct V_72 * V_73 ;
int V_26 = 0 , V_66 , V_77 ;
T_2 V_269 [ 128 ] ;
T_1 V_250 = V_6 -> V_249 . V_250 ;
if ( V_265 -> V_71 != V_270 &&
V_265 -> V_71 != ( V_270 | V_271 ) )
return - V_105 ;
switch ( V_265 -> V_247 ) {
case V_248 :
if ( V_265 -> V_71 == V_270 )
V_250 &= ~ V_254 ;
else if ( V_265 -> V_71 == ( V_270 | V_271 ) )
V_250 |= V_251 |
V_254 ;
break;
case V_259 :
if ( V_265 -> V_71 == V_270 )
V_250 &= ~ V_261 ;
else if ( V_265 -> V_71 == ( V_270 | V_271 ) )
V_250 |= V_260 |
V_261 ;
break;
case V_257 :
if ( ( V_265 -> V_71 == ( V_270 | V_271 ) ) &&
F_75 ( V_6 ) )
return - V_105 ;
if ( V_265 -> V_71 == V_270 )
V_250 &= ~ V_258 ;
else if ( V_265 -> V_71 == ( V_270 | V_271 ) )
V_250 |= V_251 |
V_258 ;
break;
case V_262 :
if ( ( V_265 -> V_71 == ( V_270 | V_271 ) ) &&
F_75 ( V_6 ) )
return - V_105 ;
if ( V_265 -> V_71 == V_270 )
V_250 &= ~ V_263 ;
else if ( V_265 -> V_71 == ( V_270 | V_271 ) )
V_250 |= V_260 |
V_263 ;
break;
default:
return - V_105 ;
}
if ( V_250 == V_6 -> V_249 . V_250 )
return V_26 ;
if ( F_79 ( V_6 ) ) {
for ( V_77 = 0 ; V_77 < 128 ; V_77 += V_6 -> V_100 - 1 ) {
F_81 (adapter, rxo, i) {
if ( ( V_77 + V_66 ) >= 128 )
break;
V_269 [ V_77 + V_66 ] = V_73 -> V_272 ;
}
}
}
V_26 = F_82 ( V_6 , V_6 -> V_249 . V_269 ,
V_250 , 128 , V_6 -> V_249 . V_273 ) ;
if ( ! V_26 )
V_6 -> V_249 . V_250 = V_250 ;
return F_50 ( V_26 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_264 * V_265 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( ! F_79 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_37 ,
L_12 ) ;
return - V_105 ;
}
switch ( V_265 -> V_265 ) {
case V_274 :
V_26 = F_80 ( V_6 , V_265 ) ;
break;
default:
return - V_105 ;
}
return V_26 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_276 -> V_277 = V_6 -> V_278 ;
V_276 -> V_279 = F_85 ( V_6 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_275 * V_276 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_276 -> V_280 || V_276 -> V_281 || V_276 -> V_282 ||
! V_276 -> V_277 || V_276 -> V_277 > F_85 ( V_6 ) )
return - V_105 ;
V_6 -> V_283 = V_276 -> V_277 ;
V_26 = F_87 ( V_6 ) ;
return F_50 ( V_26 ) ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
return V_284 ;
}
static T_1 F_89 ( struct V_1 * V_2 )
{
return V_285 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 * V_286 , T_2 * V_287 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_66 ;
struct V_249 * V_288 = & V_6 -> V_249 ;
if ( V_286 ) {
for ( V_66 = 0 ; V_66 < V_284 ; V_66 ++ )
V_286 [ V_66 ] = V_288 -> V_289 [ V_66 ] ;
}
if ( V_287 )
memcpy ( V_287 , V_288 -> V_273 , V_285 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , const T_1 * V_286 ,
const T_2 * V_287 )
{
int V_290 = 0 , V_66 , V_77 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_269 [ V_284 ] ;
if ( V_286 ) {
struct V_72 * V_73 ;
for ( V_66 = 0 ; V_66 < V_284 ; V_66 ++ ) {
V_77 = V_286 [ V_66 ] ;
V_73 = & V_6 -> V_172 [ V_77 ] ;
V_269 [ V_66 ] = V_73 -> V_272 ;
V_6 -> V_249 . V_289 [ V_66 ] = V_77 ;
}
} else {
memcpy ( V_269 , V_6 -> V_249 . V_269 ,
V_284 ) ;
}
if ( ! V_287 )
V_287 = V_6 -> V_249 . V_273 ;
V_290 = F_82 ( V_6 , V_269 ,
V_6 -> V_249 . V_250 ,
V_284 , V_287 ) ;
if ( V_290 ) {
V_6 -> V_249 . V_250 = V_291 ;
return - V_40 ;
}
memcpy ( V_6 -> V_249 . V_273 , V_287 , V_285 ) ;
memcpy ( V_6 -> V_249 . V_269 , V_269 ,
V_284 ) ;
return 0 ;
}
