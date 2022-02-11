static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
V_7 = 0 ;
V_8 = 0 ;
if ( ! V_6 -> V_9 ) {
V_4 -> V_10 . V_11 = V_12 ;
V_4 -> V_10 . V_13 = V_14 ;
return 0 ;
}
switch ( V_6 -> V_13 ) {
case V_15 :
V_4 -> V_10 . V_16 = V_17 | V_18 ;
V_4 -> V_10 . V_19 = V_20 ;
V_7 |= V_21 | V_22 ;
V_7 |= V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ;
V_7 |= V_29 ;
V_8 |= V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ;
break;
case V_36 :
if ( V_6 -> V_37 == V_38 ) {
V_4 -> V_10 . V_16 = V_18 ;
V_7 |= V_22 ;
} else {
V_4 -> V_10 . V_16 = V_39 ;
V_7 |= V_40 ;
}
V_4 -> V_10 . V_19 = V_41 ;
V_7 |= V_42 ;
break;
case V_43 :
V_4 -> V_10 . V_16 = V_39 ;
V_4 -> V_10 . V_19 = V_41 ;
V_7 |= V_40 ;
V_7 |= V_44 ;
break;
}
V_4 -> V_10 . V_11 = V_6 -> V_11 ;
V_4 -> V_10 . V_13 = V_6 -> V_13 ;
F_3 ( V_4 -> V_45 . V_7 ,
V_7 ) ;
F_3 ( V_4 -> V_45 . V_8 ,
V_8 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_9 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( V_47 -> V_48 , V_49 , sizeof( V_47 -> V_48 ) ) ;
F_6 ( V_47 -> V_50 , V_51 , sizeof( V_47 -> V_50 ) ) ;
F_6 ( V_47 -> V_52 , F_7 ( V_6 -> V_53 ) , sizeof( V_47 -> V_52 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_54 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_54 = V_55 ;
}
static void F_10 ( struct V_5 * V_6 , T_2 * * V_56 , int V_57 )
{
int V_58 , V_59 ;
int V_60 = V_57 * V_61 ;
for ( V_59 = 0 ; V_59 < V_6 -> V_62 -> V_63 ; V_59 ++ ) {
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ ) {
sprintf ( * V_56 , L_1 , V_59 + V_60 ,
V_65 [ V_58 ] . V_66 ) ;
* V_56 += V_67 ;
}
}
for ( V_59 = 0 ; V_59 < V_6 -> V_62 -> V_68 ; V_59 ++ ) {
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ ) {
sprintf ( * V_56 , L_2 , V_59 + V_60 ,
V_65 [ V_58 ] . V_66 ) ;
* V_56 += V_67 ;
}
}
}
static void F_11 ( struct V_1 * V_2 , T_1 V_69 , T_2 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_58 ;
int V_70 ;
if ( V_69 != V_71 )
return;
for ( V_58 = 0 ; V_58 < V_72 ; V_58 ++ ) {
memcpy ( V_56 , V_73 [ V_58 ] . V_66 , V_67 ) ;
V_56 += V_67 ;
}
for ( V_58 = 0 ; V_58 < V_74 ; V_58 ++ ) {
memcpy ( V_56 , V_75 [ V_58 ] . V_66 , V_67 ) ;
V_56 += V_67 ;
}
F_10 ( V_6 , & V_56 , 0 ) ;
for ( V_70 = 0 ; V_70 < V_6 -> V_76 ; V_70 ++ ) {
if ( ! V_6 -> V_77 [ V_70 ] )
continue;
F_10 ( V_6 -> V_77 [ V_70 ] , & V_56 , V_70 + 1 ) ;
}
for ( V_58 = 0 ; V_58 < V_78 ; V_58 ++ ) {
sprintf ( V_56 , L_3 , V_58 ) ;
V_56 += V_67 ;
}
for ( V_58 = 0 ; V_58 < V_79 ; V_58 ++ ) {
sprintf ( V_56 , L_4 , V_58 ) ;
V_56 += V_67 ;
}
}
static int F_12 ( struct V_1 * V_2 , int V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_80 ;
int V_70 ;
if ( V_69 != V_71 )
return - V_81 ;
V_80 = V_64 *
( V_6 -> V_62 -> V_63 + V_6 -> V_62 -> V_68 ) ;
for ( V_70 = 0 ; V_70 < V_6 -> V_76 ; V_70 ++ ) {
struct V_5 * V_82 ;
V_82 = V_6 -> V_77 [ V_70 ] ;
if ( ! V_82 )
continue;
V_80 += V_64 *
( V_82 -> V_62 -> V_63 + V_82 -> V_62 -> V_68 ) ;
}
return V_72 + V_74 +
V_80 +
V_78 + V_79 ;
}
static void F_13 ( struct V_5 * V_6 ,
struct V_83 * V_58 , T_3 * * V_56 )
{
int V_84 , V_59 ;
if ( ! V_6 )
return;
for ( V_59 = 0 ; V_59 < V_6 -> V_62 -> V_63 ; V_59 ++ ) {
F_14 ( V_6 , V_59 ) ;
for ( V_84 = 0 ; V_84 < V_64 ; V_84 ++ )
* ( ( * V_56 ) ++ ) = ( ( T_3 * ) & V_6 -> V_62 -> V_85 [ V_59 ] . V_58 )
[ V_65 [ V_84 ] . V_86 ] ;
}
for ( V_59 = 0 ; V_59 < V_6 -> V_62 -> V_68 ; V_59 ++ ) {
F_15 ( V_6 , V_59 ) ;
for ( V_84 = 0 ; V_84 < V_64 ; V_84 ++ )
* ( ( * V_56 ) ++ ) = ( ( T_3 * ) & V_6 -> V_62 -> V_87 [ V_59 ] . V_58 )
[ V_65 [ V_84 ] . V_86 ] ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_83 * V_58 , T_3 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 , V_88 ;
int V_70 , V_89 ;
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
for ( V_84 = 0 ; V_84 < V_72 ; V_84 ++ )
* ( V_56 ++ ) = ( ( T_3 * ) & V_6 -> V_90 )
[ V_73 [ V_84 ] . V_86 ] ;
for ( V_84 = 0 ; V_84 < V_74 ; V_84 ++ ) {
V_88 = 0 ;
F_19 (cpu)
V_88 += ( ( T_3 * ) F_20 ( V_6 -> V_91 , V_89 ) )
[ V_75 [ V_84 ] . V_86 ] ;
* ( V_56 ++ ) = V_88 ;
}
F_13 ( V_6 , V_58 , & V_56 ) ;
for ( V_70 = 0 ; V_70 < V_6 -> V_76 ; V_70 ++ ) {
if ( ! V_6 -> V_77 [ V_70 ] )
continue;
F_13 ( V_6 -> V_77 [ V_70 ] , V_58 , & V_56 ) ;
}
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ )
* ( V_56 ++ ) = V_6 -> V_92 . V_93 [ V_84 ] ;
for ( V_84 = 0 ; V_84 < V_79 ; V_84 ++ )
* ( V_56 ++ ) = V_6 -> V_92 . V_94 [ V_84 ] ;
}
static int F_21 ( struct V_1 * V_95 )
{
return sizeof( T_3 ) * V_96 ;
}
static void F_22 ( struct V_1 * V_95 ,
struct V_97 * V_98 , void * V_99 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
T_3 * V_100 = ( T_3 * ) V_99 ;
T_3 V_101 ;
int V_102 , V_103 , V_84 , V_104 ;
int V_105 = 0 ;
V_98 -> V_50 = 0 ;
memset ( V_100 , 0 , V_96 ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_106 ) ;
for ( V_102 = 0 ; V_102 < V_107 ; V_102 ++ )
V_100 [ V_105 ++ ] = F_23 ( V_6 ,
V_108 | ( V_102 << 3 ) ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_109 ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_110 ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_111 ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_112 ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_113 ) ;
for ( V_103 = 0 ; V_103 < V_114 ; V_103 ++ )
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_115 | ( V_103 << 3 ) ) ;
for ( V_84 = 0 ; V_84 < V_116 ; V_84 ++ )
V_100 [ V_105 ++ ] = F_23 ( V_6 ,
V_117 | ( V_84 << 3 ) ) ;
for ( V_105 = 0 ; V_105 < V_118 ; V_105 ++ )
V_100 [ V_105 ++ ] = F_23 ( V_6 ,
V_119 | ( V_84 << 3 ) ) ;
V_100 [ V_105 ++ ] = F_23 ( V_6 , V_120 ) ;
for ( V_104 = 0 ; V_104 < V_121 ; V_104 ++ ) {
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_122 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_123 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_124 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_125 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_126 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_127 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_128 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_129 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_130 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_131 , V_104 ) ;
}
for ( V_104 = 0 ; V_104 < V_61 ; V_104 ++ ) {
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_132 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 ,
V_133 , V_104 ) ;
V_101 = V_133 | ( 1 << 3 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_101 , V_104 ) ;
}
for ( V_104 = 0 ; V_104 < V_134 ; V_104 ++ ) {
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_135 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_136 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_137 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_138 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_139 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_140 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_141 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_142 , V_104 ) ;
V_100 [ V_105 ++ ] = 0 ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_143 , V_104 ) ;
V_101 = V_143 | ( 1 << 3 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_101 , V_104 ) ;
}
for ( V_104 = 0 ; V_104 < V_144 ; V_104 ++ ) {
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_145 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_146 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_147 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_148 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_149 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_150 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 ,
V_151 , V_104 ) ;
V_100 [ V_105 ++ ] = F_24 ( V_6 ,
V_152 , V_104 ) ;
V_101 = V_153 ;
V_100 [ V_105 ++ ] = F_24 ( V_6 , V_101 , V_104 ) ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_154 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_155 = V_6 -> V_156 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_159 * V_62 = V_6 -> V_62 ;
V_158 -> V_160 = V_161 ;
V_158 -> V_162 = V_62 -> V_163 ;
V_158 -> V_164 = V_165 ;
V_158 -> V_166 = V_62 -> V_167 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_168 * V_47 )
{
V_47 -> V_56 = 0 ;
switch ( V_47 -> V_169 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_47 -> V_56 |= V_176 | V_177 ;
case V_178 :
case V_179 :
V_47 -> V_56 |= V_180 | V_181 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_95 ,
struct V_168 * V_47 , T_1 * V_182 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
int V_183 = - V_184 ;
switch ( V_47 -> V_4 ) {
case V_185 :
V_47 -> V_56 = V_6 -> V_186 ;
V_183 = 0 ;
break;
case V_187 :
return F_27 ( V_6 , V_47 ) ;
default:
break;
}
return V_183 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_168 * V_47 )
{
struct V_188 * V_189 = & V_6 -> V_190 ;
T_3 V_191 = F_23 ( V_6 , V_113 ) ;
if ( ! V_189 -> V_192 )
F_30 ( V_6 -> V_2 ,
L_5 ) ;
F_31 ( V_6 -> V_2 , L_6 ,
V_47 -> V_169 , V_47 -> V_56 ) ;
if ( ! ( V_47 -> V_56 & V_180 ) || ! ( V_47 -> V_56 & V_181 ) )
return - V_81 ;
switch ( V_47 -> V_169 ) {
case V_170 :
case V_171 :
switch ( V_47 -> V_56 & ( V_176 | V_177 ) ) {
case 0 :
V_191 &= ~ ( 1ULL << V_193 ) ;
break;
case ( V_176 | V_177 ) :
V_191 |= ( 1ULL << V_193 ) ;
break;
default:
return - V_81 ;
}
break;
case V_172 :
case V_173 :
switch ( V_47 -> V_56 & ( V_176 | V_177 ) ) {
case 0 :
V_191 &= ~ ( 1ULL << V_194 ) ;
break;
case ( V_176 | V_177 ) :
V_191 |= ( 1ULL << V_194 ) ;
break;
default:
return - V_81 ;
}
break;
case V_174 :
case V_175 :
switch ( V_47 -> V_56 & ( V_176 | V_177 ) ) {
case 0 :
V_191 &= ~ ( 1ULL << V_195 ) ;
break;
case ( V_176 | V_177 ) :
V_191 |= ( 1ULL << V_195 ) ;
break;
default:
return - V_81 ;
}
break;
case V_178 :
case V_179 :
V_191 = V_196 ;
break;
default:
return - V_81 ;
}
F_32 ( V_6 , V_113 , V_191 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_95 , struct V_168 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
switch ( V_47 -> V_4 ) {
case V_197 :
return F_29 ( V_6 , V_47 ) ;
default:
break;
}
return - V_184 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
return V_114 * sizeof( T_3 ) ;
}
static T_1 F_35 ( struct V_1 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
return V_6 -> V_190 . V_198 ;
}
static int F_36 ( struct V_1 * V_95 , T_1 * V_199 , T_2 * V_200 ,
T_2 * V_201 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
struct V_188 * V_189 = & V_6 -> V_190 ;
int V_202 ;
if ( V_199 ) {
for ( V_202 = 0 ; V_202 < V_189 -> V_198 ; V_202 ++ )
V_199 [ V_202 ] = V_189 -> V_203 [ V_202 ] ;
}
if ( V_200 )
memcpy ( V_200 , V_189 -> V_103 , V_114 * sizeof( T_3 ) ) ;
if ( V_201 )
* V_201 = V_204 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_95 , const T_1 * V_199 ,
const T_2 * V_200 , T_2 V_201 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
struct V_188 * V_189 = & V_6 -> V_190 ;
int V_202 ;
if ( V_201 != V_205 && V_201 != V_204 )
return - V_184 ;
if ( ! V_189 -> V_192 ) {
F_30 ( V_6 -> V_2 ,
L_7 ) ;
return - V_206 ;
}
if ( V_199 ) {
for ( V_202 = 0 ; V_202 < V_189 -> V_198 ; V_202 ++ )
V_189 -> V_203 [ V_202 ] = V_199 [ V_202 ] ;
}
if ( V_200 ) {
memcpy ( V_189 -> V_103 , V_200 , V_114 * sizeof( T_3 ) ) ;
F_38 ( V_6 ) ;
}
F_39 ( V_6 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_95 ,
struct V_207 * V_208 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_208 -> V_209 = V_6 -> V_210 ;
V_208 -> V_211 = V_6 -> V_210 ;
V_208 -> V_212 = V_6 -> V_186 ;
V_208 -> V_213 = V_6 -> V_214 ;
}
static int F_41 ( struct V_1 * V_95 ,
struct V_207 * V_208 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
int V_215 = 0 ;
bool V_216 = F_42 ( V_95 ) ;
int V_217 ;
if ( ! V_208 -> V_212 || ! V_208 -> V_213 )
return - V_81 ;
if ( V_208 -> V_212 > V_6 -> V_210 )
return - V_81 ;
if ( V_208 -> V_213 > V_6 -> V_210 )
return - V_81 ;
if ( V_216 )
F_43 ( V_95 ) ;
V_217 = F_44 ( V_208 -> V_212 , V_208 -> V_213 ) ;
if ( V_217 > V_121 ) {
V_6 -> V_76 = F_45 ( V_217 , V_121 ) ;
V_6 -> V_76 = ( V_6 -> V_76 / V_121 ) - 1 ;
} else {
V_6 -> V_76 = 0 ;
}
V_6 -> V_62 -> V_63 = F_46 ( T_1 , V_208 -> V_212 , V_61 ) ;
V_6 -> V_62 -> V_68 = F_46 ( T_1 , V_208 -> V_213 , V_134 ) ;
V_6 -> V_62 -> V_218 = F_44 ( V_6 -> V_62 -> V_63 , V_6 -> V_62 -> V_68 ) ;
V_6 -> V_186 = V_208 -> V_212 ;
V_6 -> V_214 = V_208 -> V_213 ;
V_215 = F_47 ( V_95 , V_6 -> V_214 , V_6 -> V_186 ) ;
if ( V_215 )
return V_215 ;
if ( V_216 )
F_48 ( V_95 ) ;
F_31 ( V_95 , L_8 ,
V_6 -> V_214 , V_6 -> V_186 ) ;
return V_215 ;
}
static void F_49 ( struct V_1 * V_95 ,
struct V_219 * V_220 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
union V_221 V_222 = {} ;
if ( ( V_6 -> V_37 == V_223 ) ||
( V_6 -> V_37 == V_224 ) ||
( V_6 -> V_37 == V_225 ) )
return;
V_222 . V_226 . V_227 = V_228 ;
V_222 . V_226 . V_229 = 1 ;
if ( ! F_50 ( V_6 , & V_222 ) ) {
V_220 -> V_19 = V_6 -> V_226 . V_19 ;
V_220 -> V_230 = V_6 -> V_226 . V_231 ;
V_220 -> V_232 = V_6 -> V_226 . V_233 ;
}
}
static int F_51 ( struct V_1 * V_95 ,
struct V_219 * V_220 )
{
struct V_5 * V_6 = F_2 ( V_95 ) ;
union V_221 V_222 = {} ;
if ( ( V_6 -> V_37 == V_223 ) ||
( V_6 -> V_37 == V_224 ) ||
( V_6 -> V_37 == V_225 ) )
return - V_184 ;
if ( V_220 -> V_19 )
return - V_184 ;
V_222 . V_226 . V_227 = V_228 ;
V_222 . V_226 . V_229 = 0 ;
V_222 . V_226 . V_231 = V_220 -> V_230 ;
V_222 . V_226 . V_233 = V_220 -> V_232 ;
if ( F_50 ( V_6 , & V_222 ) )
return - V_234 ;
V_6 -> V_226 . V_231 = V_220 -> V_230 ;
V_6 -> V_226 . V_233 = V_220 -> V_232 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_235 = & V_236 ;
}
