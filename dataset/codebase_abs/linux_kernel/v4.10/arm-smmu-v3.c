static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
do {
if ( F_4 ( V_6 -> V_8 -> V_9 ,
V_10 [ V_7 ] . V_11 ) ) {
V_6 -> V_12 |= V_10 [ V_7 ] . V_13 ;
F_5 ( V_6 -> V_8 , L_1 ,
V_10 [ V_7 ] . V_11 ) ;
}
} while ( V_10 [ ++ V_7 ] . V_13 );
}
static bool F_6 ( struct V_14 * V_15 )
{
return F_7 ( V_15 , V_15 -> V_16 ) == F_7 ( V_15 , V_15 -> V_17 ) &&
F_8 ( V_15 , V_15 -> V_16 ) != F_8 ( V_15 , V_15 -> V_17 ) ;
}
static bool F_9 ( struct V_14 * V_15 )
{
return F_7 ( V_15 , V_15 -> V_16 ) == F_7 ( V_15 , V_15 -> V_17 ) &&
F_8 ( V_15 , V_15 -> V_16 ) == F_8 ( V_15 , V_15 -> V_17 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
V_15 -> V_17 = F_11 ( V_15 -> V_18 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
T_1 V_17 = ( F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ) + 1 ;
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_17 ) | F_8 ( V_15 , V_17 ) | F_7 ( V_15 , V_17 ) ;
F_14 ( V_15 -> V_17 , V_15 -> V_18 ) ;
}
static int F_15 ( struct V_14 * V_15 )
{
int V_19 = 0 ;
T_1 V_16 = F_11 ( V_15 -> V_20 ) ;
if ( F_13 ( V_15 , V_16 ) != F_13 ( V_15 , V_15 -> V_16 ) )
V_19 = - V_21 ;
V_15 -> V_16 = V_16 ;
return V_19 ;
}
static void F_16 ( struct V_14 * V_15 )
{
T_1 V_16 = ( F_8 ( V_15 , V_15 -> V_16 ) | F_7 ( V_15 , V_15 -> V_16 ) ) + 1 ;
V_15 -> V_16 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_16 ) | F_7 ( V_15 , V_16 ) ;
F_14 ( V_15 -> V_16 , V_15 -> V_20 ) ;
}
static int F_17 ( struct V_14 * V_15 , bool V_22 , bool V_23 )
{
T_2 V_24 = F_18 ( F_19 () , V_25 ) ;
while ( F_10 ( V_15 ) , ( V_22 ? ! F_9 ( V_15 ) : F_6 ( V_15 ) ) ) {
if ( F_20 ( F_19 () , V_24 ) > 0 )
return - V_26 ;
if ( V_23 ) {
V_23 () ;
} else {
F_21 () ;
F_22 ( 1 ) ;
}
}
return 0 ;
}
static void F_23 ( T_3 * V_27 , T_4 * V_28 , T_5 V_29 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_29 ; ++ V_7 )
* V_27 ++ = F_24 ( * V_28 ++ ) ;
}
static int F_25 ( struct V_14 * V_15 , T_4 * V_30 )
{
if ( F_6 ( V_15 ) )
return - V_31 ;
F_23 ( F_26 ( V_15 , V_15 -> V_16 ) , V_30 , V_15 -> V_32 ) ;
F_16 ( V_15 ) ;
return 0 ;
}
static void F_27 ( T_3 * V_27 , T_4 * V_28 , T_5 V_29 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_29 ; ++ V_7 )
* V_27 ++ = F_28 ( * V_28 ++ ) ;
}
static int F_29 ( struct V_14 * V_15 , T_4 * V_30 )
{
if ( F_9 ( V_15 ) )
return - V_33 ;
F_27 ( V_30 , F_26 ( V_15 , V_15 -> V_17 ) , V_15 -> V_32 ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_30 ( T_4 * V_34 , struct V_35 * V_30 )
{
memset ( V_34 , 0 , V_36 << 3 ) ;
V_34 [ 0 ] |= ( V_30 -> V_37 & V_38 ) << V_39 ;
switch ( V_30 -> V_37 ) {
case V_40 :
case V_41 :
break;
case V_42 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_43 . V_44 << V_45 ;
V_34 [ 1 ] |= V_30 -> V_43 . V_46 << V_47 ;
V_34 [ 1 ] |= V_30 -> V_43 . V_48 & V_49 ;
break;
case V_50 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_51 . V_44 << V_52 ;
V_34 [ 1 ] |= V_30 -> V_51 . V_53 ? V_54 : 0 ;
break;
case V_55 :
V_34 [ 1 ] |= V_56 << V_57 ;
break;
case V_58 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_60 << V_61 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_53 ? V_62 : 0 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_48 & V_63 ;
break;
case V_64 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_65 << V_66 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_53 ? V_62 : 0 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_48 & V_67 ;
break;
case V_68 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_60 << V_61 ;
case V_69 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_65 << V_66 ;
break;
case V_70 :
V_34 [ 0 ] |= V_30 -> V_71 ? V_72 : 0 ;
V_34 [ 0 ] |= V_30 -> V_73 . V_74 << V_75 ;
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_73 . V_44 << V_76 ;
V_34 [ 1 ] |= V_30 -> V_73 . V_77 << V_78 ;
switch ( V_30 -> V_73 . V_79 ) {
case V_80 :
V_34 [ 1 ] |= V_81 ;
break;
case V_82 :
V_34 [ 1 ] |= V_83 ;
break;
case V_84 :
V_34 [ 1 ] |= V_85 ;
break;
default:
return - V_86 ;
}
break;
case V_87 :
V_34 [ 0 ] |= V_88 ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static void F_31 ( struct V_5 * V_6 )
{
static const char * V_90 [] = {
[ V_91 ] = L_2 ,
[ V_92 ] = L_3 ,
[ V_93 ] = L_4 ,
} ;
int V_7 ;
T_4 V_34 [ V_36 ] ;
struct V_14 * V_15 = & V_6 -> V_94 . V_15 ;
T_1 V_17 = F_11 ( V_15 -> V_18 ) ;
T_1 V_95 = V_17 >> V_96 & V_97 ;
struct V_35 V_98 = {
. V_37 = V_87 ,
} ;
F_32 ( V_6 -> V_8 , L_5 , V_17 ,
V_95 < F_33 ( V_90 ) ? V_90 [ V_95 ] : L_6 ) ;
switch ( V_95 ) {
case V_93 :
F_32 ( V_6 -> V_8 , L_7 ) ;
case V_91 :
return;
case V_92 :
default:
break;
}
F_27 ( V_34 , F_26 ( V_15 , V_17 ) , V_15 -> V_32 ) ;
F_32 ( V_6 -> V_8 , L_8 ) ;
for ( V_7 = 0 ; V_7 < F_33 ( V_34 ) ; ++ V_7 )
F_32 ( V_6 -> V_8 , L_9 , ( unsigned long long ) V_34 [ V_7 ] ) ;
if ( F_30 ( V_34 , & V_98 ) ) {
F_32 ( V_6 -> V_8 , L_10 ) ;
return;
}
F_23 ( F_26 ( V_15 , V_17 ) , V_34 , V_15 -> V_32 ) ;
}
static void F_34 ( struct V_5 * V_6 ,
struct V_35 * V_30 )
{
T_4 V_34 [ V_36 ] ;
unsigned long V_99 ;
bool V_23 = ! ! ( V_6 -> V_100 & V_101 ) ;
struct V_14 * V_15 = & V_6 -> V_94 . V_15 ;
if ( F_30 ( V_34 , V_30 ) ) {
F_35 ( V_6 -> V_8 , L_11 ,
V_30 -> V_37 ) ;
return;
}
F_36 ( & V_6 -> V_94 . V_102 , V_99 ) ;
while ( F_25 ( V_15 , V_34 ) == - V_31 ) {
if ( F_17 ( V_15 , false , V_23 ) )
F_37 ( V_6 -> V_8 , L_12 ) ;
}
if ( V_30 -> V_37 == V_87 && F_17 ( V_15 , true , V_23 ) )
F_37 ( V_6 -> V_8 , L_13 ) ;
F_38 ( & V_6 -> V_94 . V_102 , V_99 ) ;
}
static T_4 F_39 ( T_4 V_103 )
{
T_4 V_104 = 0 ;
V_104 |= F_40 ( V_103 , V_105 ) ;
V_104 |= F_40 ( V_103 , V_106 ) ;
V_104 |= F_40 ( V_103 , V_107 ) ;
V_104 |= F_40 ( V_103 , V_108 ) ;
V_104 |= F_40 ( V_103 , V_109 ) ;
V_104 |= F_40 ( V_103 , V_110 ) ;
V_104 |= F_40 ( V_103 , V_111 ) ;
V_104 |= F_40 ( V_103 , V_112 ) ;
V_104 |= F_40 ( V_103 , V_113 ) ;
return V_104 ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_114 * V_115 )
{
T_4 V_104 ;
V_104 = F_39 ( V_115 -> V_116 . V_103 ) |
#ifdef F_42
V_117 |
#endif
V_118 | V_119 | V_120 |
V_121 | ( T_4 ) V_115 -> V_116 . V_60 << V_122 |
V_123 ;
V_115 -> V_124 [ 0 ] = F_24 ( V_104 ) ;
V_104 = V_115 -> V_116 . V_125 & V_126 << V_127 ;
V_115 -> V_124 [ 1 ] = F_24 ( V_104 ) ;
V_115 -> V_124 [ 3 ] = F_24 ( V_115 -> V_116 . V_128 << V_129 ) ;
}
static void
F_43 ( T_3 * V_27 , struct V_130 * V_131 )
{
T_4 V_104 = 0 ;
V_104 |= ( V_131 -> V_132 & V_133 )
<< V_134 ;
V_104 |= V_131 -> V_135 &
V_136 << V_137 ;
* V_27 = F_24 ( V_104 ) ;
}
static void F_44 ( struct V_5 * V_6 , T_1 V_44 )
{
struct V_35 V_34 = {
. V_37 = V_50 ,
. V_51 = {
. V_44 = V_44 ,
. V_53 = true ,
} ,
} ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
}
static void F_45 ( struct V_5 * V_6 , T_1 V_44 ,
T_3 * V_27 , struct V_138 * V_139 )
{
T_4 V_104 = F_28 ( V_27 [ 0 ] ) ;
bool V_140 = false ;
struct V_35 V_141 = {
. V_37 = V_42 ,
. V_43 = {
. V_44 = V_44 ,
} ,
} ;
if ( V_104 & V_142 ) {
T_4 V_115 ;
V_115 = V_104 & V_143 << V_144 ;
switch ( V_115 ) {
case V_145 :
break;
case V_146 :
case V_147 :
V_140 = true ;
break;
case V_148 :
if ( V_149 )
break;
default:
F_46 () ;
}
}
V_104 &= ~ ( V_143 << V_144 ) ;
if ( V_139 -> V_150 )
V_104 |= V_142 ;
else
V_104 &= ~ V_142 ;
if ( V_139 -> V_151 ) {
V_104 |= V_149 ? V_148
: V_145 ;
V_27 [ 0 ] = F_24 ( V_104 ) ;
V_27 [ 1 ] = F_24 ( V_152
<< V_153 ) ;
V_27 [ 2 ] = 0 ;
if ( V_140 )
F_44 ( V_6 , V_44 ) ;
return;
}
if ( V_139 -> V_154 ) {
F_47 ( V_140 ) ;
V_27 [ 1 ] = F_24 (
V_155
<< V_156 |
V_155
<< V_157 |
V_158 << V_159 |
#ifdef F_48
V_160 << V_161 |
#endif
V_162 << V_163 |
V_164 <<
V_165 ) ;
if ( V_6 -> V_100 & V_166 )
V_27 [ 1 ] |= F_24 ( V_167 ) ;
V_104 |= ( V_139 -> V_154 -> V_168 & V_169
<< V_170 ) |
V_146 ;
}
if ( V_139 -> V_171 ) {
F_47 ( V_140 ) ;
V_27 [ 2 ] = F_24 (
V_139 -> V_171 -> V_65 << V_172 |
( V_139 -> V_171 -> V_173 & V_174 )
<< V_175 |
#ifdef F_42
V_176 |
#endif
V_177 | V_178 |
V_179 ) ;
V_27 [ 3 ] = F_24 ( V_139 -> V_171 -> V_180 &
V_181 << V_182 ) ;
V_104 |= V_147 ;
}
F_44 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_24 ( V_104 ) ;
F_44 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_183 ) )
F_34 ( V_6 , & V_141 ) ;
}
static void F_49 ( T_4 * V_184 , unsigned int V_185 )
{
unsigned int V_7 ;
struct V_138 V_139 = {
. V_150 = true ,
. V_151 = true ,
} ;
for ( V_7 = 0 ; V_7 < V_185 ; ++ V_7 ) {
F_45 ( NULL , - 1 , V_184 , & V_139 ) ;
V_184 += V_186 ;
}
}
static int F_50 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_184 ;
struct V_187 * V_115 = & V_6 -> V_188 ;
struct V_130 * V_131 = & V_115 -> V_189 [ V_44 >> V_190 ] ;
if ( V_131 -> V_191 )
return 0 ;
V_46 = 1 << ( V_190 + F_51 ( V_186 ) + 3 ) ;
V_184 = & V_115 -> V_184 [ ( V_44 >> V_190 ) * V_192 ] ;
V_131 -> V_132 = V_190 + 1 ;
V_131 -> V_191 = F_52 ( V_6 -> V_8 , V_46 , & V_131 -> V_135 ,
V_193 | V_194 ) ;
if ( ! V_131 -> V_191 ) {
F_32 ( V_6 -> V_8 ,
L_14 ,
V_44 ) ;
return - V_195 ;
}
F_49 ( V_131 -> V_191 , 1 << V_190 ) ;
F_43 ( V_184 , V_131 ) ;
return 0 ;
}
static T_6 F_53 ( int V_196 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_197 . V_15 ;
T_4 V_198 [ V_199 ] ;
do {
while ( ! F_29 ( V_15 , V_198 ) ) {
T_7 V_200 = V_198 [ 0 ] >> V_201 & V_202 ;
F_54 ( V_6 -> V_8 , L_15 , V_200 ) ;
for ( V_7 = 0 ; V_7 < F_33 ( V_198 ) ; ++ V_7 )
F_54 ( V_6 -> V_8 , L_9 ,
( unsigned long long ) V_198 [ V_7 ] ) ;
}
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_16 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_203 ;
}
static void F_55 ( struct V_5 * V_6 , T_4 * V_198 )
{
T_1 V_44 , V_74 ;
T_8 V_77 ;
bool V_204 , V_205 ;
V_44 = V_198 [ 0 ] >> V_206 & V_207 ;
V_204 = V_198 [ 0 ] & V_208 ;
V_74 = V_204 ? V_198 [ 0 ] >> V_209 & V_210 : 0 ;
V_205 = V_198 [ 0 ] & V_211 ;
V_77 = V_198 [ 1 ] >> V_212 & V_213 ;
F_54 ( V_6 -> V_8 , L_17 ) ;
F_54 ( V_6 -> V_8 ,
L_18 ,
V_44 , V_74 , V_77 , V_205 ? L_19 : L_20 ,
V_198 [ 0 ] & V_214 ? L_20 : L_21 ,
V_198 [ 0 ] & V_215 ? L_22 : L_20 ,
V_198 [ 0 ] & V_216 ? L_23 : L_20 ,
V_198 [ 0 ] & V_217 ? L_24 : L_20 ,
V_198 [ 1 ] & V_218 << V_219 ) ;
if ( V_205 ) {
struct V_35 V_34 = {
. V_37 = V_70 ,
. V_71 = V_204 ,
. V_73 = {
. V_44 = V_44 ,
. V_74 = V_74 ,
. V_77 = V_77 ,
. V_79 = V_80 ,
} ,
} ;
F_34 ( V_6 , & V_34 ) ;
}
}
static T_6 F_56 ( int V_196 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_220 . V_15 ;
T_4 V_198 [ V_221 ] ;
do {
while ( ! F_29 ( V_15 , V_198 ) )
F_55 ( V_6 , V_198 ) ;
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_25 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_203 ;
}
static T_6 F_57 ( int V_196 , void * V_8 )
{
return V_203 ;
}
static T_6 F_58 ( int V_196 , void * V_8 )
{
T_1 V_222 , V_223 , V_224 ;
struct V_5 * V_6 = V_8 ;
V_222 = F_11 ( V_6 -> V_225 + V_226 ) ;
V_223 = F_11 ( V_6 -> V_225 + V_227 ) ;
V_224 = V_222 ^ V_223 ;
if ( ! ( V_224 & V_228 ) )
return V_229 ;
F_35 ( V_6 -> V_8 ,
L_26 ,
V_224 ) ;
if ( V_224 & V_230 ) {
F_32 ( V_6 -> V_8 , L_27 ) ;
F_59 ( V_6 ) ;
}
if ( V_224 & V_231 )
F_35 ( V_6 -> V_8 , L_28 ) ;
if ( V_224 & V_232 )
F_35 ( V_6 -> V_8 , L_29 ) ;
if ( V_224 & V_233 )
F_35 ( V_6 -> V_8 , L_30 ) ;
if ( V_224 & V_234 ) {
F_35 ( V_6 -> V_8 , L_31 ) ;
F_57 ( V_196 , V_6 -> V_8 ) ;
}
if ( V_224 & V_235 )
F_32 ( V_6 -> V_8 , L_32 ) ;
if ( V_224 & V_236 )
F_32 ( V_6 -> V_8 , L_33 ) ;
if ( V_224 & V_237 )
F_31 ( V_6 ) ;
F_14 ( V_222 , V_6 -> V_225 + V_227 ) ;
return V_203 ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
}
static void F_61 ( void * V_238 )
{
struct V_1 * V_239 = V_238 ;
F_60 ( V_239 -> V_6 ) ;
}
static void F_62 ( void * V_238 )
{
struct V_1 * V_239 = V_238 ;
struct V_5 * V_6 = V_239 -> V_6 ;
struct V_35 V_34 ;
if ( V_239 -> V_240 == V_241 ) {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_60 = V_239 -> V_154 . V_116 . V_60 ;
V_34 . V_59 . V_65 = 0 ;
} else {
V_34 . V_37 = V_69 ;
V_34 . V_59 . V_65 = V_239 -> V_171 . V_65 ;
}
F_34 ( V_6 , & V_34 ) ;
F_60 ( V_6 ) ;
}
static void F_63 ( unsigned long V_242 , T_5 V_46 ,
T_5 V_243 , bool V_53 , void * V_238 )
{
struct V_1 * V_239 = V_238 ;
struct V_5 * V_6 = V_239 -> V_6 ;
struct V_35 V_34 = {
. V_59 = {
. V_53 = V_53 ,
. V_48 = V_242 ,
} ,
} ;
if ( V_239 -> V_240 == V_241 ) {
V_34 . V_37 = V_58 ;
V_34 . V_59 . V_60 = V_239 -> V_154 . V_116 . V_60 ;
} else {
V_34 . V_37 = V_64 ;
V_34 . V_59 . V_65 = V_239 -> V_171 . V_65 ;
}
do {
F_34 ( V_6 , & V_34 ) ;
V_34 . V_59 . V_48 += V_243 ;
} while ( V_46 -= V_243 );
}
static bool F_64 ( enum V_244 V_245 )
{
switch ( V_245 ) {
case V_246 :
return true ;
case V_247 :
return true ;
case V_248 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_65 ( unsigned type )
{
struct V_1 * V_239 ;
if ( type != V_249 && type != V_250 )
return NULL ;
V_239 = F_66 ( sizeof( * V_239 ) , V_193 ) ;
if ( ! V_239 )
return NULL ;
if ( type == V_250 &&
F_67 ( & V_239 -> V_4 ) ) {
F_68 ( V_239 ) ;
return NULL ;
}
F_69 ( & V_239 -> V_251 ) ;
F_70 ( & V_239 -> V_252 ) ;
return & V_239 -> V_4 ;
}
static int F_71 ( unsigned long * V_253 , int V_132 )
{
int V_95 , V_46 = 1 << V_132 ;
do {
V_95 = F_72 ( V_253 , V_46 ) ;
if ( V_95 == V_46 )
return - V_31 ;
} while ( F_73 ( V_95 , V_253 ) );
return V_95 ;
}
static void F_74 ( unsigned long * V_253 , int V_95 )
{
F_75 ( V_95 , V_253 ) ;
}
static void F_76 ( struct V_2 * V_4 )
{
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_239 -> V_6 ;
F_77 ( V_4 ) ;
F_78 ( V_239 -> V_254 ) ;
if ( V_239 -> V_240 == V_241 ) {
struct V_114 * V_115 = & V_239 -> V_154 ;
if ( V_115 -> V_124 ) {
F_79 ( V_239 -> V_6 -> V_8 ,
V_255 << 3 ,
V_115 -> V_124 ,
V_115 -> V_168 ) ;
F_74 ( V_6 -> V_256 , V_115 -> V_116 . V_60 ) ;
}
} else {
struct V_257 * V_115 = & V_239 -> V_171 ;
if ( V_115 -> V_65 )
F_74 ( V_6 -> V_258 , V_115 -> V_65 ) ;
}
F_68 ( V_239 ) ;
}
static int F_80 ( struct V_1 * V_239 ,
struct V_259 * V_260 )
{
int V_19 ;
int V_60 ;
struct V_5 * V_6 = V_239 -> V_6 ;
struct V_114 * V_115 = & V_239 -> V_154 ;
V_60 = F_71 ( V_6 -> V_256 , V_6 -> V_261 ) ;
if ( V_60 < 0 )
return V_60 ;
V_115 -> V_124 = F_52 ( V_6 -> V_8 , V_255 << 3 ,
& V_115 -> V_168 ,
V_193 | V_194 ) ;
if ( ! V_115 -> V_124 ) {
F_35 ( V_6 -> V_8 , L_34 ) ;
V_19 = - V_195 ;
goto V_262;
}
V_115 -> V_116 . V_60 = ( T_8 ) V_60 ;
V_115 -> V_116 . V_125 = V_260 -> V_263 . V_125 [ 0 ] ;
V_115 -> V_116 . V_103 = V_260 -> V_263 . V_103 ;
V_115 -> V_116 . V_128 = V_260 -> V_263 . V_128 [ 0 ] ;
return 0 ;
V_262:
F_74 ( V_6 -> V_256 , V_60 ) ;
return V_19 ;
}
static int F_81 ( struct V_1 * V_239 ,
struct V_259 * V_260 )
{
int V_65 ;
struct V_5 * V_6 = V_239 -> V_6 ;
struct V_257 * V_115 = & V_239 -> V_171 ;
V_65 = F_71 ( V_6 -> V_258 , V_6 -> V_264 ) ;
if ( V_65 < 0 )
return V_65 ;
V_115 -> V_65 = ( T_8 ) V_65 ;
V_115 -> V_180 = V_260 -> V_265 . V_180 ;
V_115 -> V_173 = V_260 -> V_265 . V_173 ;
return 0 ;
}
static int F_82 ( struct V_2 * V_4 )
{
int V_19 ;
unsigned long V_266 , V_267 ;
enum V_268 V_269 ;
struct V_259 V_260 ;
struct V_270 * V_254 ;
int (* F_83)( struct V_1 * ,
struct V_259 * );
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_239 -> V_6 ;
if ( ! ( V_6 -> V_100 & V_271 ) )
V_239 -> V_240 = V_272 ;
if ( ! ( V_6 -> V_100 & V_273 ) )
V_239 -> V_240 = V_241 ;
switch ( V_239 -> V_240 ) {
case V_241 :
V_266 = V_274 ;
V_267 = V_6 -> V_266 ;
V_269 = V_275 ;
F_83 = F_80 ;
break;
case V_276 :
case V_272 :
V_266 = V_6 -> V_266 ;
V_267 = V_6 -> V_267 ;
V_269 = V_277 ;
F_83 = F_81 ;
break;
default:
return - V_86 ;
}
V_260 = (struct V_259 ) {
. V_278 = V_6 -> V_278 ,
. V_266 = V_266 ,
. V_267 = V_267 ,
. V_279 = & V_280 ,
. V_281 = V_6 -> V_8 ,
} ;
V_254 = F_84 ( V_269 , & V_260 , V_239 ) ;
if ( ! V_254 )
return - V_195 ;
V_4 -> V_278 = V_260 . V_278 ;
V_4 -> V_282 . V_283 = ( 1UL << V_266 ) - 1 ;
V_4 -> V_282 . V_284 = true ;
V_239 -> V_254 = V_254 ;
V_19 = F_83 ( V_239 , & V_260 ) ;
if ( V_19 < 0 )
F_78 ( V_254 ) ;
return V_19 ;
}
static T_3 * F_85 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_285 ;
struct V_187 * V_115 = & V_6 -> V_188 ;
if ( V_6 -> V_100 & V_286 ) {
struct V_130 * V_189 ;
int V_95 ;
V_95 = ( V_44 >> V_190 ) * V_192 ;
V_189 = & V_115 -> V_189 [ V_95 ] ;
V_95 = ( V_44 & ( ( 1 << V_190 ) - 1 ) ) * V_186 ;
V_285 = & V_189 -> V_191 [ V_95 ] ;
} else {
V_285 = & V_115 -> V_184 [ V_44 * V_186 ] ;
}
return V_285 ;
}
static int F_86 ( struct V_287 * V_288 )
{
int V_7 ;
struct V_289 * V_290 = V_288 -> V_291 ;
struct V_5 * V_6 = V_290 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_288 -> V_292 ; ++ V_7 ) {
T_1 V_44 = V_288 -> V_293 [ V_7 ] ;
T_3 * V_285 = F_85 ( V_6 , V_44 ) ;
F_45 ( V_6 , V_44 , V_285 , & V_290 -> V_139 ) ;
}
return 0 ;
}
static void F_87 ( struct V_294 * V_8 )
{
struct V_289 * V_290 = V_8 -> V_287 -> V_291 ;
V_290 -> V_139 . V_151 = true ;
if ( F_86 ( V_8 -> V_287 ) < 0 )
F_35 ( V_8 , L_35 ) ;
}
static int F_88 ( struct V_2 * V_4 , struct V_294 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_289 * V_290 ;
struct V_138 * V_139 ;
if ( ! V_8 -> V_287 )
return - V_89 ;
V_290 = V_8 -> V_287 -> V_291 ;
V_6 = V_290 -> V_6 ;
V_139 = & V_290 -> V_139 ;
if ( ! V_139 -> V_151 )
F_87 ( V_8 ) ;
F_89 ( & V_239 -> V_251 ) ;
if ( ! V_239 -> V_6 ) {
V_239 -> V_6 = V_6 ;
V_19 = F_82 ( V_4 ) ;
if ( V_19 ) {
V_239 -> V_6 = NULL ;
goto V_295;
}
} else if ( V_239 -> V_6 != V_6 ) {
F_32 ( V_8 ,
L_36 ,
F_90 ( V_239 -> V_6 -> V_8 ) ,
F_90 ( V_6 -> V_8 ) ) ;
V_19 = - V_296 ;
goto V_295;
}
V_139 -> V_151 = false ;
V_139 -> V_150 = true ;
if ( V_239 -> V_240 == V_241 ) {
V_139 -> V_154 = & V_239 -> V_154 ;
V_139 -> V_171 = NULL ;
F_41 ( V_6 , V_139 -> V_154 ) ;
} else {
V_139 -> V_154 = NULL ;
V_139 -> V_171 = & V_239 -> V_171 ;
}
V_19 = F_86 ( V_8 -> V_287 ) ;
if ( V_19 < 0 )
V_139 -> V_150 = false ;
V_295:
F_91 ( & V_239 -> V_251 ) ;
return V_19 ;
}
static int F_92 ( struct V_2 * V_4 , unsigned long V_242 ,
T_9 V_297 , T_5 V_46 , int V_298 )
{
int V_19 ;
unsigned long V_99 ;
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_270 * V_299 = V_239 -> V_254 ;
if ( ! V_299 )
return - V_300 ;
F_36 ( & V_239 -> V_252 , V_99 ) ;
V_19 = V_299 -> V_253 ( V_299 , V_242 , V_297 , V_46 , V_298 ) ;
F_38 ( & V_239 -> V_252 , V_99 ) ;
return V_19 ;
}
static T_5
F_93 ( struct V_2 * V_4 , unsigned long V_242 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_99 ;
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_270 * V_299 = V_239 -> V_254 ;
if ( ! V_299 )
return 0 ;
F_36 ( & V_239 -> V_252 , V_99 ) ;
V_19 = V_299 -> V_301 ( V_299 , V_242 , V_46 ) ;
F_38 ( & V_239 -> V_252 , V_99 ) ;
return V_19 ;
}
static T_9
F_94 ( struct V_2 * V_4 , T_10 V_242 )
{
T_9 V_19 ;
unsigned long V_99 ;
struct V_1 * V_239 = F_1 ( V_4 ) ;
struct V_270 * V_299 = V_239 -> V_254 ;
if ( ! V_299 )
return 0 ;
F_36 ( & V_239 -> V_252 , V_99 ) ;
V_19 = V_299 -> V_302 ( V_299 , V_242 ) ;
F_38 ( & V_239 -> V_252 , V_99 ) ;
return V_19 ;
}
static int F_95 ( struct V_294 * V_8 , void * V_303 )
{
return V_8 -> V_304 == V_303 ;
}
static
struct V_5 * F_96 ( struct V_305 * V_304 )
{
struct V_294 * V_8 = F_97 ( & V_306 . V_307 , NULL ,
V_304 , F_95 ) ;
F_98 ( V_8 ) ;
return V_8 ? F_99 ( V_8 ) : NULL ;
}
static bool F_100 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_308 = V_6 -> V_188 . V_309 ;
if ( V_6 -> V_100 & V_286 )
V_308 *= 1UL << V_190 ;
return V_44 < V_308 ;
}
static int F_101 ( struct V_294 * V_8 )
{
int V_7 , V_19 ;
struct V_5 * V_6 ;
struct V_289 * V_290 ;
struct V_287 * V_288 = V_8 -> V_287 ;
struct V_310 * V_311 ;
if ( ! V_288 || V_288 -> V_299 != & V_312 )
return - V_300 ;
if ( F_102 ( V_288 -> V_291 ) ) {
V_290 = V_288 -> V_291 ;
V_6 = V_290 -> V_6 ;
} else {
V_6 = F_96 ( V_288 -> V_313 ) ;
if ( ! V_6 )
return - V_300 ;
V_290 = F_66 ( sizeof( * V_290 ) , V_193 ) ;
if ( ! V_290 )
return - V_195 ;
V_290 -> V_6 = V_6 ;
V_288 -> V_291 = V_290 ;
}
for ( V_7 = 0 ; V_7 < V_288 -> V_292 ; V_7 ++ ) {
T_1 V_44 = V_288 -> V_293 [ V_7 ] ;
if ( ! F_100 ( V_6 , V_44 ) )
return - V_314 ;
if ( V_6 -> V_100 & V_286 ) {
V_19 = F_50 ( V_6 , V_44 ) ;
if ( V_19 )
return V_19 ;
}
}
V_311 = F_103 ( V_8 ) ;
if ( ! F_104 ( V_311 ) )
F_105 ( V_311 ) ;
return F_106 ( V_311 ) ;
}
static void F_107 ( struct V_294 * V_8 )
{
struct V_287 * V_288 = V_8 -> V_287 ;
struct V_289 * V_290 ;
if ( ! V_288 || V_288 -> V_299 != & V_312 )
return;
V_290 = V_288 -> V_291 ;
if ( V_290 && V_290 -> V_139 . V_150 )
F_87 ( V_8 ) ;
F_108 ( V_8 ) ;
F_68 ( V_290 ) ;
F_109 ( V_8 ) ;
}
static struct V_310 * F_110 ( struct V_294 * V_8 )
{
struct V_310 * V_311 ;
if ( F_111 ( V_8 ) )
V_311 = F_112 ( V_8 ) ;
else
V_311 = F_113 ( V_8 ) ;
return V_311 ;
}
static int F_114 ( struct V_2 * V_4 ,
enum V_315 V_316 , void * V_303 )
{
struct V_1 * V_239 = F_1 ( V_4 ) ;
switch ( V_316 ) {
case V_317 :
* ( int * ) V_303 = ( V_239 -> V_240 == V_276 ) ;
return 0 ;
default:
return - V_300 ;
}
}
static int F_115 ( struct V_2 * V_4 ,
enum V_315 V_316 , void * V_303 )
{
int V_19 = 0 ;
struct V_1 * V_239 = F_1 ( V_4 ) ;
F_89 ( & V_239 -> V_251 ) ;
switch ( V_316 ) {
case V_317 :
if ( V_239 -> V_6 ) {
V_19 = - V_318 ;
goto V_295;
}
if ( * ( int * ) V_303 )
V_239 -> V_240 = V_276 ;
else
V_239 -> V_240 = V_241 ;
break;
default:
V_19 = - V_300 ;
}
V_295:
F_91 ( & V_239 -> V_251 ) ;
return V_19 ;
}
static int F_116 ( struct V_294 * V_8 , struct V_319 * args )
{
return F_117 ( V_8 , args -> args , 1 ) ;
}
static int F_118 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_320 ,
unsigned long V_321 ,
T_5 V_322 )
{
T_5 V_323 = ( ( 1 << V_15 -> V_324 ) * V_322 ) << 3 ;
V_15 -> V_225 = F_52 ( V_6 -> V_8 , V_323 , & V_15 -> V_325 , V_193 ) ;
if ( ! V_15 -> V_225 ) {
F_32 ( V_6 -> V_8 , L_37 ,
V_323 ) ;
return - V_195 ;
}
V_15 -> V_20 = V_6 -> V_225 + V_320 ;
V_15 -> V_18 = V_6 -> V_225 + V_321 ;
V_15 -> V_32 = V_322 ;
V_15 -> V_326 = V_327 ;
V_15 -> V_326 |= V_15 -> V_325 & V_328 << V_329 ;
V_15 -> V_326 |= ( V_15 -> V_324 & V_330 )
<< V_331 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static int F_119 ( struct V_5 * V_6 )
{
int V_19 ;
F_70 ( & V_6 -> V_94 . V_102 ) ;
V_19 = F_118 ( V_6 , & V_6 -> V_94 . V_15 , V_332 ,
V_333 , V_36 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_118 ( V_6 , & V_6 -> V_197 . V_15 , V_334 ,
V_335 , V_199 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_6 -> V_100 & V_336 ) )
return 0 ;
return F_118 ( V_6 , & V_6 -> V_220 . V_15 , V_337 ,
V_338 , V_221 ) ;
}
static int F_120 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_187 * V_115 = & V_6 -> V_188 ;
T_5 V_46 = sizeof( * V_115 -> V_189 ) * V_115 -> V_309 ;
void * V_184 = V_6 -> V_188 . V_184 ;
V_115 -> V_189 = F_121 ( V_6 -> V_8 , V_46 , V_193 ) ;
if ( ! V_115 -> V_189 ) {
F_32 ( V_6 -> V_8 , L_38 ) ;
return - V_195 ;
}
for ( V_7 = 0 ; V_7 < V_115 -> V_309 ; ++ V_7 ) {
F_43 ( V_184 , & V_115 -> V_189 [ V_7 ] ) ;
V_184 += V_192 << 3 ;
}
return 0 ;
}
static int F_122 ( struct V_5 * V_6 )
{
void * V_184 ;
T_4 V_339 ;
T_1 V_46 , V_340 ;
struct V_187 * V_115 = & V_6 -> V_188 ;
if ( V_6 -> V_341 < V_190 ) {
V_46 = 0 ;
} else {
V_46 = V_342 - ( F_51 ( V_192 ) + 3 ) ;
V_46 = F_123 ( V_46 , V_6 -> V_341 - V_190 ) ;
}
V_115 -> V_309 = 1 << V_46 ;
V_46 += V_190 ;
if ( V_46 < V_6 -> V_341 )
F_35 ( V_6 -> V_8 ,
L_39 ,
V_46 , V_6 -> V_341 ) ;
V_340 = V_115 -> V_309 * ( V_192 << 3 ) ;
V_184 = F_52 ( V_6 -> V_8 , V_340 , & V_115 -> V_343 ,
V_193 | V_194 ) ;
if ( ! V_184 ) {
F_32 ( V_6 -> V_8 ,
L_40 ,
V_46 ) ;
return - V_195 ;
}
V_115 -> V_184 = V_184 ;
V_339 = V_344 ;
V_339 |= ( V_46 & V_345 )
<< V_346 ;
V_339 |= ( V_190 & V_347 )
<< V_348 ;
V_115 -> V_349 = V_339 ;
return F_120 ( V_6 ) ;
}
static int F_124 ( struct V_5 * V_6 )
{
void * V_184 ;
T_4 V_339 ;
T_1 V_46 ;
struct V_187 * V_115 = & V_6 -> V_188 ;
V_46 = ( 1 << V_6 -> V_341 ) * ( V_186 << 3 ) ;
V_184 = F_52 ( V_6 -> V_8 , V_46 , & V_115 -> V_343 ,
V_193 | V_194 ) ;
if ( ! V_184 ) {
F_32 ( V_6 -> V_8 ,
L_41 ,
V_46 ) ;
return - V_195 ;
}
V_115 -> V_184 = V_184 ;
V_115 -> V_309 = 1 << V_6 -> V_341 ;
V_339 = V_350 ;
V_339 |= ( V_6 -> V_341 & V_345 )
<< V_346 ;
V_115 -> V_349 = V_339 ;
F_49 ( V_184 , V_115 -> V_309 ) ;
return 0 ;
}
static int F_125 ( struct V_5 * V_6 )
{
T_4 V_339 ;
int V_19 ;
if ( V_6 -> V_100 & V_286 )
V_19 = F_122 ( V_6 ) ;
else
V_19 = F_124 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = V_6 -> V_188 . V_343 &
V_351 << V_352 ;
V_339 |= V_353 ;
V_6 -> V_188 . V_354 = V_339 ;
F_126 ( 0 , V_6 -> V_258 ) ;
return 0 ;
}
static int F_127 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_119 ( V_6 ) ;
if ( V_19 )
return V_19 ;
return F_125 ( V_6 ) ;
}
static int F_128 ( struct V_5 * V_6 , T_1 V_104 ,
unsigned int V_355 , unsigned int V_356 )
{
T_1 V_339 ;
F_129 ( V_104 , V_6 -> V_225 + V_355 ) ;
return F_130 ( V_6 -> V_225 + V_356 , V_339 , V_339 == V_104 ,
1 , V_25 ) ;
}
static int F_131 ( struct V_5 * V_6 , T_1 V_357 , T_1 V_358 )
{
int V_19 ;
T_1 V_339 , V_359 * V_360 = V_6 -> V_225 + V_361 ;
V_19 = F_130 ( V_360 , V_339 , ! ( V_339 & V_362 ) ,
1 , V_25 ) ;
if ( V_19 )
return V_19 ;
V_339 &= ~ V_358 ;
V_339 |= V_357 ;
F_129 ( V_339 | V_362 , V_360 ) ;
return F_130 ( V_360 , V_339 , ! ( V_339 & V_362 ) ,
1 , V_25 ) ;
}
static void F_132 ( void * V_303 )
{
struct V_294 * V_8 = V_303 ;
F_133 ( V_8 ) ;
}
static void F_134 ( struct V_363 * V_131 , struct V_364 * V_365 )
{
T_9 V_366 ;
struct V_294 * V_8 = F_135 ( V_131 ) ;
struct V_5 * V_6 = F_99 ( V_8 ) ;
T_9 * V_115 = V_367 [ V_131 -> V_368 . V_369 ] ;
V_366 = ( ( ( T_4 ) V_365 -> V_370 ) << 32 ) | V_365 -> V_371 ;
V_366 &= V_372 << V_373 ;
F_136 ( V_366 , V_6 -> V_225 + V_115 [ 0 ] ) ;
F_129 ( V_365 -> V_303 , V_6 -> V_225 + V_115 [ 1 ] ) ;
F_129 ( V_374 , V_6 -> V_225 + V_115 [ 2 ] ) ;
}
static void F_137 ( struct V_5 * V_6 )
{
struct V_363 * V_131 ;
int V_19 , V_375 = V_376 ;
struct V_294 * V_8 = V_6 -> V_8 ;
F_136 ( 0 , V_6 -> V_225 + V_377 ) ;
F_136 ( 0 , V_6 -> V_225 + V_378 ) ;
if ( V_6 -> V_100 & V_336 )
F_136 ( 0 , V_6 -> V_225 + V_379 ) ;
else
V_375 -- ;
if ( ! ( V_6 -> V_100 & V_380 ) )
return;
V_19 = F_138 ( V_8 , V_375 , F_134 ) ;
if ( V_19 ) {
F_35 ( V_8 , L_42 ) ;
return;
}
F_139 (desc, dev) {
switch ( V_131 -> V_368 . V_369 ) {
case V_381 :
V_6 -> V_197 . V_15 . V_196 = V_131 -> V_196 ;
break;
case V_382 :
V_6 -> V_383 = V_131 -> V_196 ;
break;
case V_384 :
V_6 -> V_220 . V_15 . V_196 = V_131 -> V_196 ;
break;
default:
continue;
}
}
F_140 ( V_8 , F_132 , V_8 ) ;
}
static int F_141 ( struct V_5 * V_6 )
{
int V_19 , V_196 ;
T_1 V_385 = V_386 | V_387 ;
V_19 = F_128 ( V_6 , 0 , V_388 ,
V_389 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_43 ) ;
return V_19 ;
}
F_137 ( V_6 ) ;
V_196 = V_6 -> V_197 . V_15 . V_196 ;
if ( V_196 ) {
V_19 = F_142 ( V_6 -> V_8 , V_196 , NULL ,
F_53 ,
V_390 ,
L_44 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_45 ) ;
}
V_196 = V_6 -> V_94 . V_15 . V_196 ;
if ( V_196 ) {
V_19 = F_143 ( V_6 -> V_8 , V_196 ,
F_57 , 0 ,
L_46 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_47 ) ;
}
V_196 = V_6 -> V_383 ;
if ( V_196 ) {
V_19 = F_143 ( V_6 -> V_8 , V_196 , F_58 ,
0 , L_48 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_49 ) ;
}
if ( V_6 -> V_100 & V_336 ) {
V_196 = V_6 -> V_220 . V_15 . V_196 ;
if ( V_196 ) {
V_19 = F_142 ( V_6 -> V_8 , V_196 , NULL ,
F_56 ,
V_390 ,
L_50 ,
V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 ,
L_51 ) ;
else
V_385 |= V_391 ;
}
}
V_19 = F_128 ( V_6 , V_385 ,
V_388 , V_389 ) ;
if ( V_19 )
F_35 ( V_6 -> V_8 , L_52 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_128 ( V_6 , 0 , V_392 , V_393 ) ;
if ( V_19 )
F_32 ( V_6 -> V_8 , L_53 ) ;
return V_19 ;
}
static int F_144 ( struct V_5 * V_6 , bool V_151 )
{
int V_19 ;
T_1 V_339 , V_394 ;
struct V_35 V_34 ;
V_339 = F_11 ( V_6 -> V_225 + V_392 ) ;
if ( V_339 & V_395 )
F_35 ( V_6 -> V_8 , L_54 ) ;
V_19 = F_59 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = ( V_396 << V_397 ) |
( V_398 << V_399 ) |
( V_398 << V_400 ) |
( V_396 << V_401 ) |
( V_398 << V_402 ) |
( V_398 << V_403 ) ;
F_129 ( V_339 , V_6 -> V_225 + V_404 ) ;
V_339 = V_405 | V_406 | V_407 ;
F_129 ( V_339 , V_6 -> V_225 + V_408 ) ;
F_136 ( V_6 -> V_188 . V_354 ,
V_6 -> V_225 + V_409 ) ;
F_129 ( V_6 -> V_188 . V_349 ,
V_6 -> V_225 + V_410 ) ;
F_136 ( V_6 -> V_94 . V_15 . V_326 , V_6 -> V_225 + V_411 ) ;
F_129 ( V_6 -> V_94 . V_15 . V_16 , V_6 -> V_225 + V_332 ) ;
F_129 ( V_6 -> V_94 . V_15 . V_17 , V_6 -> V_225 + V_333 ) ;
V_394 = V_412 ;
V_19 = F_128 ( V_6 , V_394 , V_392 ,
V_393 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_55 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
if ( V_6 -> V_100 & V_413 ) {
V_34 . V_37 = V_40 ;
F_34 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
F_136 ( V_6 -> V_197 . V_15 . V_326 , V_6 -> V_225 + V_414 ) ;
F_129 ( V_6 -> V_197 . V_15 . V_16 , V_6 -> V_225 + V_334 ) ;
F_129 ( V_6 -> V_197 . V_15 . V_17 , V_6 -> V_225 + V_335 ) ;
V_394 |= V_415 ;
V_19 = F_128 ( V_6 , V_394 , V_392 ,
V_393 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
if ( V_6 -> V_100 & V_336 ) {
F_136 ( V_6 -> V_220 . V_15 . V_326 ,
V_6 -> V_225 + V_416 ) ;
F_129 ( V_6 -> V_220 . V_15 . V_16 ,
V_6 -> V_225 + V_337 ) ;
F_129 ( V_6 -> V_220 . V_15 . V_17 ,
V_6 -> V_225 + V_338 ) ;
V_394 |= V_417 ;
V_19 = F_128 ( V_6 , V_394 , V_392 ,
V_393 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
}
V_19 = F_141 ( V_6 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
if ( ! V_151 || V_149 ) {
V_394 |= V_395 ;
} else {
V_19 = F_131 ( V_6 , 0 , V_418 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_59 ) ;
return V_19 ;
}
}
V_19 = F_128 ( V_6 , V_394 , V_392 ,
V_393 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_60 ) ;
return V_19 ;
}
return 0 ;
}
static int F_145 ( struct V_5 * V_6 )
{
T_1 V_339 ;
bool V_419 = V_6 -> V_100 & V_420 ;
V_339 = F_11 ( V_6 -> V_225 + V_421 ) ;
if ( ( V_339 & V_422 << V_423 ) == V_424 )
V_6 -> V_100 |= V_286 ;
if ( V_339 & V_425 )
V_6 -> V_100 |= V_426 ;
switch ( V_339 & V_427 << V_428 ) {
case V_429 :
V_6 -> V_100 |= V_430 | V_431 ;
break;
#ifdef F_42
case V_432 :
V_6 -> V_100 |= V_431 ;
break;
#else
case V_433 :
V_6 -> V_100 |= V_430 ;
break;
#endif
default:
F_32 ( V_6 -> V_8 , L_61 ) ;
return - V_296 ;
}
if ( F_146 ( V_434 ) && V_339 & V_435 )
V_6 -> V_100 |= V_336 ;
if ( F_146 ( F_48 ) && V_339 & V_436 )
V_6 -> V_100 |= V_437 ;
if ( V_339 & V_438 )
V_6 -> V_100 |= V_101 ;
if ( V_339 & V_439 )
V_6 -> V_100 |= V_380 ;
if ( V_339 & V_440 )
V_6 -> V_100 |= V_413 ;
if ( ! ! ( V_339 & V_441 ) != V_419 )
F_35 ( V_6 -> V_8 , L_62 ,
V_419 ? L_63 : L_64 ) ;
switch ( V_339 & V_442 << V_443 ) {
case V_444 :
case V_445 :
V_6 -> V_100 |= V_166 ;
}
if ( V_339 & V_446 )
V_6 -> V_100 |= V_271 ;
if ( V_339 & V_447 )
V_6 -> V_100 |= V_273 ;
if ( ! ( V_339 & ( V_446 | V_447 ) ) ) {
F_32 ( V_6 -> V_8 , L_65 ) ;
return - V_296 ;
}
switch ( V_339 & V_448 << V_449 ) {
case V_450 :
V_6 -> V_266 = 40 ;
case V_451 :
break;
default:
F_32 ( V_6 -> V_8 , L_66 ) ;
return - V_296 ;
}
V_6 -> V_261 = V_339 & V_452 ? 16 : 8 ;
V_6 -> V_264 = V_339 & V_453 ? 16 : 8 ;
V_339 = F_11 ( V_6 -> V_225 + V_454 ) ;
if ( V_339 & ( V_455 | V_456 | V_457 ) ) {
F_32 ( V_6 -> V_8 , L_67 ) ;
return - V_296 ;
}
V_6 -> V_94 . V_15 . V_324 = F_123 ( ( T_1 ) V_458 ,
V_339 >> V_459 & V_460 ) ;
if ( ! V_6 -> V_94 . V_15 . V_324 ) {
F_32 ( V_6 -> V_8 , L_68 ) ;
return - V_296 ;
}
V_6 -> V_197 . V_15 . V_324 = F_123 ( ( T_1 ) V_461 ,
V_339 >> V_462 & V_463 ) ;
V_6 -> V_220 . V_15 . V_324 = F_123 ( ( T_1 ) V_464 ,
V_339 >> V_465 & V_466 ) ;
V_6 -> V_467 = V_339 >> V_468 & V_469 ;
V_6 -> V_341 = V_339 >> V_470 & V_471 ;
V_339 = F_11 ( V_6 -> V_225 + V_472 ) ;
V_6 -> V_197 . V_473 = V_339 >> V_474
& V_475 ;
if ( V_339 & V_476 )
V_6 -> V_278 |= V_477 | V_478 ;
if ( V_339 & V_479 )
V_6 -> V_278 |= V_480 | V_481 ;
if ( V_339 & V_482 )
V_6 -> V_278 |= V_483 | V_484 | V_485 ;
if ( V_312 . V_278 == - 1UL )
V_312 . V_278 = V_6 -> V_278 ;
else
V_312 . V_278 |= V_6 -> V_278 ;
switch ( V_339 & V_486 << V_487 ) {
case V_488 :
V_6 -> V_267 = 32 ;
break;
case V_489 :
V_6 -> V_267 = 36 ;
break;
case V_490 :
V_6 -> V_267 = 40 ;
break;
case V_491 :
V_6 -> V_267 = 42 ;
break;
case V_492 :
V_6 -> V_267 = 44 ;
break;
default:
F_54 ( V_6 -> V_8 ,
L_69 ) ;
case V_493 :
V_6 -> V_267 = 48 ;
}
if ( F_147 ( V_6 -> V_8 , F_148 ( V_6 -> V_267 ) ) )
F_35 ( V_6 -> V_8 ,
L_70 ) ;
V_6 -> V_266 = F_149 ( V_6 -> V_266 , V_6 -> V_267 ) ;
F_54 ( V_6 -> V_8 , L_71 ,
V_6 -> V_266 , V_6 -> V_267 , V_6 -> V_100 ) ;
return 0 ;
}
static int F_150 ( struct V_494 * V_495 ,
struct V_5 * V_6 )
{
struct V_496 * V_497 ;
struct V_294 * V_8 = V_6 -> V_8 ;
struct V_498 * V_499 ;
V_499 = * (struct V_498 * * ) F_151 ( V_8 ) ;
V_497 = (struct V_496 * ) V_499 -> V_500 ;
if ( V_497 -> V_99 & V_501 )
V_6 -> V_100 |= V_420 ;
return 0 ;
}
static inline int F_150 ( struct V_494 * V_495 ,
struct V_5 * V_6 )
{
return - V_300 ;
}
static int F_152 ( struct V_494 * V_495 ,
struct V_5 * V_6 )
{
struct V_294 * V_8 = & V_495 -> V_8 ;
T_1 V_502 ;
int V_19 = - V_86 ;
if ( F_153 ( V_8 -> V_9 , L_72 , & V_502 ) )
F_32 ( V_8 , L_73 ) ;
else if ( V_502 != 1 )
F_32 ( V_8 , L_74 , V_502 ) ;
else
V_19 = 0 ;
F_3 ( V_6 ) ;
if ( F_154 ( V_8 -> V_9 ) )
V_6 -> V_100 |= V_420 ;
return V_19 ;
}
static int F_155 ( struct V_494 * V_495 )
{
int V_196 , V_19 ;
struct V_503 * V_504 ;
struct V_5 * V_6 ;
struct V_294 * V_8 = & V_495 -> V_8 ;
bool V_151 ;
V_6 = F_121 ( V_8 , sizeof( * V_6 ) , V_193 ) ;
if ( ! V_6 ) {
F_32 ( V_8 , L_75 ) ;
return - V_195 ;
}
V_6 -> V_8 = V_8 ;
V_504 = F_156 ( V_495 , V_505 , 0 ) ;
if ( F_157 ( V_504 ) + 1 < V_506 ) {
F_32 ( V_8 , L_76 , V_504 ) ;
return - V_86 ;
}
V_6 -> V_225 = F_158 ( V_8 , V_504 ) ;
if ( F_104 ( V_6 -> V_225 ) )
return F_159 ( V_6 -> V_225 ) ;
V_196 = F_160 ( V_495 , L_77 ) ;
if ( V_196 > 0 )
V_6 -> V_197 . V_15 . V_196 = V_196 ;
V_196 = F_160 ( V_495 , L_78 ) ;
if ( V_196 > 0 )
V_6 -> V_220 . V_15 . V_196 = V_196 ;
V_196 = F_160 ( V_495 , L_79 ) ;
if ( V_196 > 0 )
V_6 -> V_94 . V_15 . V_196 = V_196 ;
V_196 = F_160 ( V_495 , L_80 ) ;
if ( V_196 > 0 )
V_6 -> V_383 = V_196 ;
if ( V_8 -> V_9 ) {
V_19 = F_152 ( V_495 , V_6 ) ;
} else {
V_19 = F_150 ( V_495 , V_6 ) ;
if ( V_19 == - V_300 )
return V_19 ;
}
V_151 = ! ! V_19 ;
V_19 = F_145 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_127 ( V_6 ) ;
if ( V_19 )
return V_19 ;
F_161 ( V_495 , V_6 ) ;
V_19 = F_144 ( V_6 , V_151 ) ;
if ( V_19 )
return V_19 ;
F_162 ( V_8 -> V_304 , & V_312 ) ;
#ifdef F_163
if ( V_507 . V_508 != & V_312 ) {
F_164 () ;
V_19 = F_165 ( & V_507 , & V_312 ) ;
if ( V_19 )
return V_19 ;
}
#endif
#ifdef F_166
if ( V_509 . V_508 != & V_312 ) {
V_19 = F_165 ( & V_509 , & V_312 ) ;
if ( V_19 )
return V_19 ;
}
#endif
if ( V_510 . V_508 != & V_312 ) {
V_19 = F_165 ( & V_510 , & V_312 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_167 ( struct V_494 * V_495 )
{
struct V_5 * V_6 = F_168 ( V_495 ) ;
F_59 ( V_6 ) ;
return 0 ;
}
static int T_11 F_169 ( void )
{
static bool V_511 ;
int V_19 = 0 ;
if ( ! V_511 ) {
V_19 = F_170 ( & V_306 ) ;
V_511 = ! V_19 ;
}
return V_19 ;
}
static void T_12 F_171 ( void )
{
return F_172 ( & V_306 ) ;
}
static int T_11 F_173 ( struct V_512 * V_513 )
{
int V_19 = F_169 () ;
if ( V_19 )
return V_19 ;
if ( ! F_174 ( V_513 , NULL , V_510 . V_514 ) )
return - V_300 ;
return 0 ;
}
static int T_11 F_175 ( struct V_515 * V_516 )
{
if ( F_176 ( V_517 ) )
return F_169 () ;
return 0 ;
}
