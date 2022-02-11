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
static T_1
F_5 ( struct V_5 * V_6 , T_2 * V_20 )
{
T_1 V_21 = 0 , V_22 ;
T_2 V_23 ;
struct V_24 V_25 ;
int V_26 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_26 = F_6 ( V_6 , & V_25 , 0 , 0 ,
V_20 , & V_21 , & V_22 , & V_23 ) ;
return V_21 ;
}
static int
F_7 ( struct V_5 * V_6 , T_2 * V_20 ,
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
V_31 , V_20 , & V_30 ,
& V_22 , & V_23 ) ;
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
static int
F_13 ( struct V_1 * V_2 )
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
struct V_49 * V_50 ;
int V_64 ;
F_22 (adapter, eqo, i) {
V_50 -> V_62 = V_48 -> V_61 ;
V_50 -> V_55 = F_23 ( V_48 -> V_54 , V_65 ) ;
V_50 -> V_57 = F_23 ( V_48 -> V_56 , V_50 -> V_55 ) ;
V_50 -> V_66 = V_48 -> V_52 ;
}
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 ,
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
F_25 (adapter, rxo, j) {
struct V_82 * V_68 = F_26 ( V_71 ) ;
do {
V_77 = F_27 ( & V_68 -> V_83 ) ;
V_69 [ V_76 ] = V_68 -> V_84 ;
V_69 [ V_76 + 1 ] = V_68 -> V_85 ;
} while ( F_28 ( & V_68 -> V_83 , V_77 ) );
for ( V_64 = 2 ; V_64 < V_86 ; V_64 ++ ) {
V_74 = ( T_2 * ) V_68 + V_87 [ V_64 ] . V_81 ;
V_69 [ V_76 + V_64 ] = * ( T_1 * ) V_74 ;
}
V_76 += V_86 ;
}
F_29 (adapter, txo, j) {
struct V_88 * V_68 = F_30 ( V_73 ) ;
do {
V_77 = F_27 ( & V_68 -> V_89 ) ;
V_69 [ V_76 ] = V_68 -> V_90 ;
} while ( F_28 ( & V_68 -> V_89 , V_77 ) );
do {
V_77 = F_27 ( & V_68 -> V_83 ) ;
for ( V_64 = 1 ; V_64 < V_91 ; V_64 ++ ) {
V_74 = ( T_2 * ) V_68 + V_92 [ V_64 ] . V_81 ;
V_69 [ V_76 + V_64 ] =
( V_92 [ V_64 ] . V_33 == sizeof( V_93 ) ) ?
* ( V_93 * ) V_74 : * ( T_1 * ) V_74 ;
}
} while ( F_28 ( & V_68 -> V_83 , V_77 ) );
V_76 += V_91 ;
}
}
static void
F_31 ( struct V_1 * V_2 , T_4 V_94 ,
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
static int F_32 ( struct V_1 * V_2 , int V_94 )
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
static T_1 F_33 ( T_1 V_104 , T_1 V_105 )
{
T_1 V_106 ;
switch ( V_104 ) {
case V_107 :
case V_108 :
case V_109 :
V_106 = V_110 ;
break;
case V_111 :
V_106 = V_105 ? V_112 : V_113 ;
break;
case V_114 :
case V_115 :
V_106 = V_113 ;
break;
case V_116 :
V_106 = V_110 ;
break;
default:
V_106 = V_117 ;
}
return V_106 ;
}
static T_1 F_34 ( T_1 V_118 , T_1 V_119 )
{
T_1 V_120 = 0 ;
switch ( V_118 ) {
case V_107 :
case V_108 :
case V_109 :
V_120 |= V_121 ;
if ( V_119 & V_122 )
V_120 |= V_123 ;
if ( V_119 & V_124 )
V_120 |= V_125 ;
if ( V_119 & V_126 )
V_120 |= V_127 ;
break;
case V_128 :
V_120 |= V_129 ;
if ( V_119 & V_122 )
V_120 |= V_130 ;
if ( V_119 & V_131 )
V_120 |= V_132 ;
break;
case V_133 :
V_120 |= V_129 |
V_134 ;
break;
case V_111 :
case V_114 :
case V_115 :
V_120 |= V_135 ;
if ( V_119 & V_131 )
V_120 |= V_136 ;
if ( V_119 & V_122 )
V_120 |= V_123 ;
break;
case V_116 :
V_120 |= V_121 ;
if ( V_119 & V_131 )
V_120 |= V_136 ;
if ( V_119 & V_122 )
V_120 |= V_123 ;
if ( V_119 & V_124 )
V_120 |= V_125 ;
break;
default:
V_120 |= V_121 ;
}
return V_120 ;
}
bool F_35 ( struct V_5 * V_6 )
{
return ( V_6 -> V_137 . V_138 == V_111 ||
V_6 -> V_137 . V_138 == V_114 ) ?
false : true ;
}
static int F_36 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_141 ;
T_6 V_142 = 0 ;
int V_26 ;
T_1 V_143 ;
T_1 V_144 ;
T_1 V_105 ;
T_6 V_138 ;
if ( V_6 -> V_137 . V_142 < 0 ) {
V_26 = F_37 ( V_6 , & V_142 ,
& V_141 , 0 ) ;
if ( ! V_26 )
F_38 ( V_6 , V_141 ) ;
F_39 ( V_140 , V_142 ) ;
V_26 = F_40 ( V_6 ) ;
if ( ! V_26 ) {
V_138 = V_6 -> V_137 . V_138 ;
V_143 = V_6 -> V_137 . V_145 ;
V_144 = V_6 -> V_137 . V_146 ;
V_105 = V_6 -> V_137 . V_105 ;
V_140 -> V_147 =
F_34 ( V_138 ,
V_143 |
V_144 ) ;
V_140 -> V_148 =
F_34 ( V_138 ,
V_143 ) ;
V_140 -> V_106 = F_33 ( V_138 ,
V_105 ) ;
if ( V_6 -> V_137 . V_145 ) {
V_140 -> V_147 |= V_149 ;
V_140 -> V_150 = V_151 ;
V_140 -> V_148 |= V_152 ;
}
V_140 -> V_147 |= V_153 ;
if ( F_35 ( V_6 ) )
V_140 -> V_148 |= V_154 ;
switch ( V_6 -> V_137 . V_138 ) {
case V_133 :
case V_128 :
V_140 -> V_155 = V_156 ;
break;
default:
V_140 -> V_155 = V_157 ;
break;
}
} else {
V_140 -> V_106 = V_117 ;
V_140 -> V_150 = V_158 ;
V_140 -> V_155 = V_159 ;
}
V_6 -> V_137 . V_142 = F_41 ( V_140 ) ;
V_6 -> V_137 . V_160 = V_140 -> V_106 ;
V_6 -> V_137 . V_155 = V_140 -> V_155 ;
V_6 -> V_137 . V_150 = V_140 -> V_150 ;
V_6 -> V_137 . V_148 = V_140 -> V_148 ;
V_6 -> V_137 . V_147 = V_140 -> V_147 ;
} else {
F_39 ( V_140 , V_6 -> V_137 . V_142 ) ;
V_140 -> V_106 = V_6 -> V_137 . V_160 ;
V_140 -> V_155 = V_6 -> V_137 . V_155 ;
V_140 -> V_150 = V_6 -> V_137 . V_150 ;
V_140 -> V_148 = V_6 -> V_137 . V_148 ;
V_140 -> V_147 = V_6 -> V_137 . V_147 ;
}
V_140 -> V_161 = F_42 ( V_2 ) ? V_162 : V_163 ;
V_140 -> V_164 = V_6 -> V_165 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_166 * V_167 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_167 -> V_168 = V_167 -> V_169 = V_6 -> V_170 [ 0 ] . V_171 . V_46 ;
V_167 -> V_172 = V_167 -> V_173 = V_6 -> V_174 [ 0 ] . V_171 . V_46 ;
}
static void
F_44 ( struct V_1 * V_2 , struct V_175 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_45 ( V_6 , & V_140 -> V_176 , & V_140 -> V_177 ) ;
V_140 -> V_150 = V_6 -> V_137 . V_178 ;
}
static int
F_46 ( struct V_1 * V_2 , struct V_175 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_140 -> V_150 != V_6 -> V_137 . V_178 )
return - V_103 ;
V_6 -> V_179 = V_140 -> V_176 ;
V_6 -> V_180 = V_140 -> V_177 ;
V_26 = F_47 ( V_6 ,
V_6 -> V_179 , V_6 -> V_180 ) ;
if ( V_26 )
F_48 ( & V_6 -> V_16 -> V_37 , L_5 ) ;
return V_26 ;
}
static int
F_49 ( struct V_1 * V_2 ,
enum V_181 V_182 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_182 ) {
case V_183 :
F_50 ( V_6 , V_6 -> V_184 ,
& V_6 -> V_185 ) ;
return 1 ;
case V_186 :
F_51 ( V_6 , V_6 -> V_184 , 0 , 0 ,
V_187 ) ;
break;
case V_188 :
F_51 ( V_6 , V_6 -> V_184 , 0 , 0 ,
V_189 ) ;
break;
case V_190 :
F_51 ( V_6 , V_6 -> V_184 , 0 , 0 ,
V_6 -> V_185 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_191 * V_192 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_193 * V_37 = & V_6 -> V_16 -> V_37 ;
int V_26 ;
if ( ! F_16 ( V_6 ) ) {
F_9 ( V_37 , L_6 ) ;
return - V_194 ;
}
if ( F_53 ( V_6 ) ) {
F_9 ( V_37 , L_7 ) ;
return 0 ;
}
switch ( V_192 -> V_195 ) {
case V_196 :
V_26 = F_54 ( V_6 ) ;
if ( ! V_26 )
F_55 ( V_37 , L_8 ) ;
break;
default:
F_9 ( V_37 , L_9 , V_192 -> V_195 ) ;
return - V_103 ;
}
return V_26 ;
}
static void
F_56 ( struct V_1 * V_2 , struct V_197 * V_198 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_57 ( V_6 ) ) {
V_198 -> V_147 |= V_199 ;
if ( V_6 -> V_198 )
V_198 -> V_200 |= V_199 ;
} else
V_198 -> V_200 = 0 ;
memset ( & V_198 -> V_201 , 0 , sizeof( V_198 -> V_201 ) ) ;
}
static int
F_58 ( struct V_1 * V_2 , struct V_197 * V_198 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_198 -> V_200 & ~ V_199 )
return - V_194 ;
if ( ! F_57 ( V_6 ) ) {
F_48 ( & V_6 -> V_16 -> V_37 , L_10 ) ;
return - V_194 ;
}
if ( V_198 -> V_200 & V_199 )
V_6 -> V_198 = true ;
else
V_6 -> V_198 = false ;
return 0 ;
}
static int
F_59 ( struct V_5 * V_6 )
{
int V_202 , V_64 ;
struct V_24 V_203 ;
static const V_93 V_204 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_203 . V_33 = sizeof( struct V_205 ) ;
V_203 . V_35 = F_60 ( & V_6 -> V_16 -> V_37 , V_203 . V_33 ,
& V_203 . V_36 , V_206 ) ;
if ( ! V_203 . V_35 )
return - V_38 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
V_202 = F_61 ( V_6 , V_204 [ V_64 ] ,
4096 , & V_203 ) ;
if ( V_202 != 0 )
goto V_207;
}
V_207:
F_62 ( & V_6 -> V_16 -> V_37 , V_203 . V_33 , V_203 . V_35 ,
V_203 . V_36 ) ;
return V_202 ;
}
static V_93 F_63 ( struct V_5 * V_6 , T_2 V_208 ,
V_93 * V_26 )
{
F_64 ( V_6 , V_6 -> V_184 ,
V_208 , 1 ) ;
* V_26 = F_65 ( V_6 , V_6 -> V_184 ,
V_208 , 1500 ,
2 , 0xabc ) ;
F_64 ( V_6 , V_6 -> V_184 ,
V_209 , 1 ) ;
return * V_26 ;
}
static void
F_66 ( struct V_1 * V_2 , struct V_210 * V_211 , V_93 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
T_2 V_141 = 0 ;
if ( V_6 -> V_212 & V_213 ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_11 ) ;
V_211 -> V_214 |= V_215 ;
return;
}
memset ( V_69 , 0 , sizeof( V_93 ) * V_101 ) ;
if ( V_211 -> V_214 & V_216 ) {
if ( F_63 ( V_6 , V_217 ,
& V_69 [ 0 ] ) != 0 ) {
V_211 -> V_214 |= V_215 ;
}
if ( F_63 ( V_6 , V_218 ,
& V_69 [ 1 ] ) != 0 ) {
V_211 -> V_214 |= V_215 ;
}
if ( F_63 ( V_6 , V_219 ,
& V_69 [ 2 ] ) != 0 ) {
V_211 -> V_214 |= V_215 ;
}
}
if ( ! F_16 ( V_6 ) && F_59 ( V_6 ) != 0 ) {
V_69 [ 3 ] = 1 ;
V_211 -> V_214 |= V_215 ;
}
V_26 = F_37 ( V_6 , NULL , & V_141 , 0 ) ;
if ( V_26 ) {
V_211 -> V_214 |= V_215 ;
V_69 [ 4 ] = - 1 ;
} else if ( ! V_141 ) {
V_211 -> V_214 |= V_215 ;
V_69 [ 4 ] = 1 ;
}
}
static int
F_67 ( struct V_1 * V_2 , struct V_220 * V_221 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_68 ( V_6 , V_221 -> V_69 ) ;
}
static int
F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_6 , V_42 ) )
return 0 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_5 ( V_6 ,
V_222 ) ;
else
return F_5 ( V_6 ,
V_223 ) ;
} else {
return V_224 ;
}
}
static int
F_70 ( struct V_1 * V_2 , struct V_225 * V_226 ,
T_5 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_227 ;
struct V_228 * V_229 ;
int V_26 ;
if ( ! V_226 -> V_46 )
return - V_103 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_7 ( V_6 , V_222 ,
V_226 -> V_46 , V_69 ) ;
else
return F_7 ( V_6 , V_223 ,
V_226 -> V_46 , V_69 ) ;
}
V_226 -> V_230 = V_231 | ( V_6 -> V_16 -> V_193 << 16 ) ;
memset ( & V_227 , 0 , sizeof( struct V_24 ) ) ;
V_227 . V_33 = sizeof( struct V_232 ) ;
V_227 . V_35 = F_60 ( & V_6 -> V_16 -> V_37 , V_227 . V_33 ,
& V_227 . V_36 , V_206 ) ;
if ( ! V_227 . V_35 )
return - V_38 ;
V_26 = F_71 ( V_6 , & V_227 ) ;
if ( ! V_26 ) {
V_229 = V_227 . V_35 ;
memcpy ( V_69 , V_229 -> V_233 + V_226 -> V_81 , V_226 -> V_46 ) ;
}
F_62 ( & V_6 -> V_16 -> V_37 , V_227 . V_33 , V_227 . V_35 ,
V_227 . V_36 ) ;
return V_26 ;
}
static T_1 F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_16 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_12 ) ;
return - V_194 ;
}
return V_6 -> V_234 ;
}
static void F_73 ( struct V_5 * V_6 , T_1 V_235 )
{
struct V_24 V_236 ;
struct V_237 * V_238 ;
int V_26 ;
int V_64 , V_75 ;
memset ( & V_236 , 0 , sizeof( struct V_24 ) ) ;
V_236 . V_33 = sizeof( struct V_239 ) ;
V_236 . V_35 = F_8 ( V_6 -> V_16 , V_236 . V_33 ,
& V_236 . V_36 ) ;
if ( ! V_236 . V_35 ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_13 ,
V_240 ) ;
goto V_207;
}
V_26 = F_74 ( V_6 , & V_236 ) ;
if ( ! V_26 ) {
V_238 = (struct V_237 * ) ( V_236 . V_35 +
sizeof( struct V_241 ) ) ;
for ( V_64 = 0 ; V_64 < F_75 ( V_238 -> V_242 ) ; V_64 ++ ) {
T_1 V_243 = F_75 ( V_238 -> V_244 [ V_64 ] . V_243 ) ;
for ( V_75 = 0 ; V_75 < V_243 ; V_75 ++ ) {
if ( V_238 -> V_244 [ V_64 ] . V_245 [ V_75 ] . V_246 ==
V_247 )
V_238 -> V_244 [ V_64 ] . V_245 [ V_75 ] . V_248 =
F_76 ( V_235 ) ;
}
}
V_26 = F_77 ( V_6 , & V_236 ,
V_238 ) ;
if ( V_26 )
F_9 ( & V_6 -> V_16 -> V_37 ,
L_14 ) ;
} else {
F_9 ( & V_6 -> V_16 -> V_37 , L_15 ) ;
}
F_12 ( V_6 -> V_16 , V_236 . V_33 , V_236 . V_35 ,
V_236 . V_36 ) ;
V_207:
return;
}
static void F_78 ( struct V_1 * V_2 , T_1 V_235 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_16 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_37 , L_12 ) ;
return;
}
if ( V_6 -> V_234 == V_235 )
return;
if ( ( V_235 & V_249 ) != ( V_6 -> V_234 & V_249 ) )
F_73 ( V_6 , V_235 & V_249 ?
V_250 : V_251 ) ;
V_6 -> V_234 = V_235 ;
return;
}
static V_93 F_79 ( struct V_5 * V_6 , V_93 V_252 )
{
V_93 V_69 = 0 ;
switch ( V_252 ) {
case V_253 :
if ( V_6 -> V_254 & V_255 )
V_69 |= V_256 | V_257 ;
if ( V_6 -> V_254 & V_258 )
V_69 |= V_259 | V_260 ;
break;
case V_261 :
if ( V_6 -> V_254 & V_255 )
V_69 |= V_256 | V_257 ;
if ( V_6 -> V_254 & V_262 )
V_69 |= V_259 | V_260 ;
break;
case V_263 :
if ( V_6 -> V_254 & V_264 )
V_69 |= V_256 | V_257 ;
if ( V_6 -> V_254 & V_265 )
V_69 |= V_259 | V_260 ;
break;
case V_266 :
if ( V_6 -> V_254 & V_264 )
V_69 |= V_256 | V_257 ;
if ( V_6 -> V_254 & V_267 )
V_69 |= V_259 | V_260 ;
break;
}
return V_69 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_268 * V_269 ,
T_1 * V_270 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_81 ( V_6 ) ) {
F_55 ( & V_6 -> V_16 -> V_37 ,
L_16 ) ;
return - V_103 ;
}
switch ( V_269 -> V_269 ) {
case V_271 :
V_269 -> V_69 = F_79 ( V_6 , V_269 -> V_252 ) ;
break;
case V_272 :
V_269 -> V_69 = V_6 -> V_98 - 1 ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_268 * V_269 )
{
struct V_70 * V_71 ;
int V_26 = 0 , V_64 , V_75 ;
T_2 V_273 [ 128 ] ;
T_1 V_254 = V_6 -> V_254 ;
if ( V_269 -> V_69 != V_274 &&
V_269 -> V_69 != ( V_274 | V_275 ) )
return - V_103 ;
switch ( V_269 -> V_252 ) {
case V_253 :
if ( V_269 -> V_69 == V_274 )
V_254 &= ~ V_258 ;
else if ( V_269 -> V_69 == ( V_274 | V_275 ) )
V_254 |= V_255 |
V_258 ;
break;
case V_263 :
if ( V_269 -> V_69 == V_274 )
V_254 &= ~ V_265 ;
else if ( V_269 -> V_69 == ( V_274 | V_275 ) )
V_254 |= V_264 |
V_265 ;
break;
case V_261 :
if ( ( V_269 -> V_69 == ( V_274 | V_275 ) ) &&
F_83 ( V_6 ) )
return - V_103 ;
if ( V_269 -> V_69 == V_274 )
V_254 &= ~ V_262 ;
else if ( V_269 -> V_69 == ( V_274 | V_275 ) )
V_254 |= V_255 |
V_262 ;
break;
case V_266 :
if ( ( V_269 -> V_69 == ( V_274 | V_275 ) ) &&
F_83 ( V_6 ) )
return - V_103 ;
if ( V_269 -> V_69 == V_274 )
V_254 &= ~ V_267 ;
else if ( V_269 -> V_69 == ( V_274 | V_275 ) )
V_254 |= V_264 |
V_267 ;
break;
default:
return - V_103 ;
}
if ( V_254 == V_6 -> V_254 )
return V_26 ;
if ( F_81 ( V_6 ) ) {
for ( V_75 = 0 ; V_75 < 128 ; V_75 += V_6 -> V_98 - 1 ) {
F_84 (adapter, rxo, i) {
if ( ( V_75 + V_64 ) >= 128 )
break;
V_273 [ V_75 + V_64 ] = V_71 -> V_276 ;
}
}
}
V_26 = F_85 ( V_6 , V_273 , V_254 , 128 ) ;
if ( ! V_26 )
V_6 -> V_254 = V_254 ;
return V_26 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( ! F_81 ( V_6 ) ) {
F_9 ( & V_6 -> V_16 -> V_37 ,
L_17 ) ;
return - V_103 ;
}
switch ( V_269 -> V_269 ) {
case V_277 :
V_26 = F_82 ( V_6 , V_269 ) ;
break;
default:
return - V_103 ;
}
return V_26 ;
}
