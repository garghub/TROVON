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
V_104 = V_139 -> V_150 ? V_142 : 0 ;
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
V_162 << V_163 ) ;
if ( V_6 -> V_100 & V_164 )
V_27 [ 1 ] |= F_24 ( V_165 ) ;
V_104 |= ( V_139 -> V_154 -> V_166 & V_167
<< V_168 ) |
V_146 ;
}
if ( V_139 -> V_169 ) {
F_47 ( V_140 ) ;
V_27 [ 2 ] = F_24 (
V_139 -> V_169 -> V_65 << V_170 |
( V_139 -> V_169 -> V_171 & V_172 )
<< V_173 |
#ifdef F_42
V_174 |
#endif
V_175 | V_176 |
V_177 ) ;
V_27 [ 3 ] = F_24 ( V_139 -> V_169 -> V_178 &
V_179 << V_180 ) ;
V_104 |= V_147 ;
}
F_44 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_24 ( V_104 ) ;
F_44 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_181 ) )
F_34 ( V_6 , & V_141 ) ;
}
static void F_49 ( T_4 * V_182 , unsigned int V_183 )
{
unsigned int V_7 ;
struct V_138 V_139 = {
. V_150 = true ,
. V_151 = true ,
} ;
for ( V_7 = 0 ; V_7 < V_183 ; ++ V_7 ) {
F_45 ( NULL , - 1 , V_182 , & V_139 ) ;
V_182 += V_184 ;
}
}
static int F_50 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_182 ;
struct V_185 * V_115 = & V_6 -> V_186 ;
struct V_130 * V_131 = & V_115 -> V_187 [ V_44 >> V_188 ] ;
if ( V_131 -> V_189 )
return 0 ;
V_46 = 1 << ( V_188 + F_51 ( V_184 ) + 3 ) ;
V_182 = & V_115 -> V_182 [ ( V_44 >> V_188 ) * V_190 ] ;
V_131 -> V_132 = V_188 + 1 ;
V_131 -> V_189 = F_52 ( V_6 -> V_8 , V_46 , & V_131 -> V_135 ,
V_191 | V_192 ) ;
if ( ! V_131 -> V_189 ) {
F_32 ( V_6 -> V_8 ,
L_14 ,
V_44 ) ;
return - V_193 ;
}
F_49 ( V_131 -> V_189 , 1 << V_188 ) ;
F_43 ( V_182 , V_131 ) ;
return 0 ;
}
static T_6 F_53 ( int V_194 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_195 . V_15 ;
T_4 V_196 [ V_197 ] ;
do {
while ( ! F_29 ( V_15 , V_196 ) ) {
T_7 V_198 = V_196 [ 0 ] >> V_199 & V_200 ;
F_54 ( V_6 -> V_8 , L_15 , V_198 ) ;
for ( V_7 = 0 ; V_7 < F_33 ( V_196 ) ; ++ V_7 )
F_54 ( V_6 -> V_8 , L_9 ,
( unsigned long long ) V_196 [ V_7 ] ) ;
}
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_16 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_201 ;
}
static void F_55 ( struct V_5 * V_6 , T_4 * V_196 )
{
T_1 V_44 , V_74 ;
T_8 V_77 ;
bool V_202 , V_203 ;
V_44 = V_196 [ 0 ] >> V_204 & V_205 ;
V_202 = V_196 [ 0 ] & V_206 ;
V_74 = V_202 ? V_196 [ 0 ] >> V_207 & V_208 : 0 ;
V_203 = V_196 [ 0 ] & V_209 ;
V_77 = V_196 [ 1 ] >> V_210 & V_211 ;
F_54 ( V_6 -> V_8 , L_17 ) ;
F_54 ( V_6 -> V_8 ,
L_18 ,
V_44 , V_74 , V_77 , V_203 ? L_19 : L_20 ,
V_196 [ 0 ] & V_212 ? L_20 : L_21 ,
V_196 [ 0 ] & V_213 ? L_22 : L_20 ,
V_196 [ 0 ] & V_214 ? L_23 : L_20 ,
V_196 [ 0 ] & V_215 ? L_24 : L_20 ,
V_196 [ 1 ] & V_216 << V_217 ) ;
if ( V_203 ) {
struct V_35 V_34 = {
. V_37 = V_70 ,
. V_71 = V_202 ,
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
static T_6 F_56 ( int V_194 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_218 . V_15 ;
T_4 V_196 [ V_219 ] ;
do {
while ( ! F_29 ( V_15 , V_196 ) )
F_55 ( V_6 , V_196 ) ;
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_25 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_201 ;
}
static T_6 F_57 ( int V_194 , void * V_8 )
{
return V_201 ;
}
static T_6 F_58 ( int V_194 , void * V_8 )
{
T_1 V_220 , V_221 , V_222 ;
struct V_5 * V_6 = V_8 ;
V_220 = F_11 ( V_6 -> V_223 + V_224 ) ;
V_221 = F_11 ( V_6 -> V_223 + V_225 ) ;
V_222 = V_220 ^ V_221 ;
if ( ! ( V_222 & V_226 ) )
return V_227 ;
F_35 ( V_6 -> V_8 ,
L_26 ,
V_222 ) ;
if ( V_222 & V_228 ) {
F_32 ( V_6 -> V_8 , L_27 ) ;
F_59 ( V_6 ) ;
}
if ( V_222 & V_229 )
F_35 ( V_6 -> V_8 , L_28 ) ;
if ( V_222 & V_230 )
F_35 ( V_6 -> V_8 , L_29 ) ;
if ( V_222 & V_231 )
F_35 ( V_6 -> V_8 , L_30 ) ;
if ( V_222 & V_232 ) {
F_35 ( V_6 -> V_8 , L_31 ) ;
F_57 ( V_194 , V_6 -> V_8 ) ;
}
if ( V_222 & V_233 )
F_32 ( V_6 -> V_8 , L_32 ) ;
if ( V_222 & V_234 )
F_32 ( V_6 -> V_8 , L_33 ) ;
if ( V_222 & V_235 )
F_31 ( V_6 ) ;
F_14 ( V_220 , V_6 -> V_223 + V_225 ) ;
return V_201 ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
}
static void F_61 ( void * V_236 )
{
struct V_1 * V_237 = V_236 ;
F_60 ( V_237 -> V_6 ) ;
}
static void F_62 ( void * V_236 )
{
struct V_1 * V_237 = V_236 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_35 V_34 ;
if ( V_237 -> V_238 == V_239 ) {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_60 = V_237 -> V_154 . V_116 . V_60 ;
V_34 . V_59 . V_65 = 0 ;
} else {
V_34 . V_37 = V_69 ;
V_34 . V_59 . V_65 = V_237 -> V_169 . V_65 ;
}
F_34 ( V_6 , & V_34 ) ;
F_60 ( V_6 ) ;
}
static void F_63 ( unsigned long V_240 , T_5 V_46 ,
T_5 V_241 , bool V_53 , void * V_236 )
{
struct V_1 * V_237 = V_236 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_35 V_34 = {
. V_59 = {
. V_53 = V_53 ,
. V_48 = V_240 ,
} ,
} ;
if ( V_237 -> V_238 == V_239 ) {
V_34 . V_37 = V_58 ;
V_34 . V_59 . V_60 = V_237 -> V_154 . V_116 . V_60 ;
} else {
V_34 . V_37 = V_64 ;
V_34 . V_59 . V_65 = V_237 -> V_169 . V_65 ;
}
do {
F_34 ( V_6 , & V_34 ) ;
V_34 . V_59 . V_48 += V_241 ;
} while ( V_46 -= V_241 );
}
static bool F_64 ( enum V_242 V_243 )
{
switch ( V_243 ) {
case V_244 :
return true ;
case V_245 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_65 ( unsigned type )
{
struct V_1 * V_237 ;
if ( type != V_246 && type != V_247 )
return NULL ;
V_237 = F_66 ( sizeof( * V_237 ) , V_191 ) ;
if ( ! V_237 )
return NULL ;
if ( type == V_247 &&
F_67 ( & V_237 -> V_4 ) ) {
F_68 ( V_237 ) ;
return NULL ;
}
F_69 ( & V_237 -> V_248 ) ;
F_70 ( & V_237 -> V_249 ) ;
return & V_237 -> V_4 ;
}
static int F_71 ( unsigned long * V_250 , int V_132 )
{
int V_95 , V_46 = 1 << V_132 ;
do {
V_95 = F_72 ( V_250 , V_46 ) ;
if ( V_95 == V_46 )
return - V_31 ;
} while ( F_73 ( V_95 , V_250 ) );
return V_95 ;
}
static void F_74 ( unsigned long * V_250 , int V_95 )
{
F_75 ( V_95 , V_250 ) ;
}
static void F_76 ( struct V_2 * V_4 )
{
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_237 -> V_6 ;
F_77 ( V_4 ) ;
F_78 ( V_237 -> V_251 ) ;
if ( V_237 -> V_238 == V_239 ) {
struct V_114 * V_115 = & V_237 -> V_154 ;
if ( V_115 -> V_124 ) {
F_79 ( V_237 -> V_6 -> V_8 ,
V_252 << 3 ,
V_115 -> V_124 ,
V_115 -> V_166 ) ;
F_74 ( V_6 -> V_253 , V_115 -> V_116 . V_60 ) ;
}
} else {
struct V_254 * V_115 = & V_237 -> V_169 ;
if ( V_115 -> V_65 )
F_74 ( V_6 -> V_255 , V_115 -> V_65 ) ;
}
F_68 ( V_237 ) ;
}
static int F_80 ( struct V_1 * V_237 ,
struct V_256 * V_257 )
{
int V_19 ;
int V_60 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_114 * V_115 = & V_237 -> V_154 ;
V_60 = F_71 ( V_6 -> V_253 , V_6 -> V_258 ) ;
if ( V_60 < 0 )
return V_60 ;
V_115 -> V_124 = F_52 ( V_6 -> V_8 , V_252 << 3 ,
& V_115 -> V_166 ,
V_191 | V_192 ) ;
if ( ! V_115 -> V_124 ) {
F_35 ( V_6 -> V_8 , L_34 ) ;
V_19 = - V_193 ;
goto V_259;
}
V_115 -> V_116 . V_60 = ( T_8 ) V_60 ;
V_115 -> V_116 . V_125 = V_257 -> V_260 . V_125 [ 0 ] ;
V_115 -> V_116 . V_103 = V_257 -> V_260 . V_103 ;
V_115 -> V_116 . V_128 = V_257 -> V_260 . V_128 [ 0 ] ;
return 0 ;
V_259:
F_74 ( V_6 -> V_253 , V_60 ) ;
return V_19 ;
}
static int F_81 ( struct V_1 * V_237 ,
struct V_256 * V_257 )
{
int V_65 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_254 * V_115 = & V_237 -> V_169 ;
V_65 = F_71 ( V_6 -> V_255 , V_6 -> V_261 ) ;
if ( V_65 < 0 )
return V_65 ;
V_115 -> V_65 = ( T_8 ) V_65 ;
V_115 -> V_178 = V_257 -> V_262 . V_178 ;
V_115 -> V_171 = V_257 -> V_262 . V_171 ;
return 0 ;
}
static int F_82 ( struct V_2 * V_4 )
{
int V_19 ;
unsigned long V_263 , V_264 ;
enum V_265 V_266 ;
struct V_256 V_257 ;
struct V_267 * V_251 ;
int (* F_83)( struct V_1 * ,
struct V_256 * );
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_237 -> V_6 ;
if ( ! ( V_6 -> V_100 & V_268 ) )
V_237 -> V_238 = V_269 ;
if ( ! ( V_6 -> V_100 & V_270 ) )
V_237 -> V_238 = V_239 ;
switch ( V_237 -> V_238 ) {
case V_239 :
V_263 = V_271 ;
V_264 = V_6 -> V_263 ;
V_266 = V_272 ;
F_83 = F_80 ;
break;
case V_273 :
case V_269 :
V_263 = V_6 -> V_263 ;
V_264 = V_6 -> V_264 ;
V_266 = V_274 ;
F_83 = F_81 ;
break;
default:
return - V_86 ;
}
V_257 = (struct V_256 ) {
. V_275 = V_6 -> V_275 ,
. V_263 = V_263 ,
. V_264 = V_264 ,
. V_276 = & V_277 ,
. V_278 = V_6 -> V_8 ,
} ;
V_251 = F_84 ( V_266 , & V_257 , V_237 ) ;
if ( ! V_251 )
return - V_193 ;
V_4 -> V_275 = V_257 . V_275 ;
V_4 -> V_279 . V_280 = ( 1UL << V_263 ) - 1 ;
V_4 -> V_279 . V_281 = true ;
V_237 -> V_251 = V_251 ;
V_19 = F_83 ( V_237 , & V_257 ) ;
if ( V_19 < 0 )
F_78 ( V_251 ) ;
return V_19 ;
}
static T_3 * F_85 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_282 ;
struct V_185 * V_115 = & V_6 -> V_186 ;
if ( V_6 -> V_100 & V_283 ) {
struct V_130 * V_187 ;
int V_95 ;
V_95 = ( V_44 >> V_188 ) * V_190 ;
V_187 = & V_115 -> V_187 [ V_95 ] ;
V_95 = ( V_44 & ( ( 1 << V_188 ) - 1 ) ) * V_184 ;
V_282 = & V_187 -> V_189 [ V_95 ] ;
} else {
V_282 = & V_115 -> V_182 [ V_44 * V_184 ] ;
}
return V_282 ;
}
static int F_86 ( struct V_284 * V_285 )
{
int V_7 ;
struct V_286 * V_287 = V_285 -> V_288 ;
struct V_5 * V_6 = V_287 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_285 -> V_289 ; ++ V_7 ) {
T_1 V_44 = V_285 -> V_290 [ V_7 ] ;
T_3 * V_282 = F_85 ( V_6 , V_44 ) ;
F_45 ( V_6 , V_44 , V_282 , & V_287 -> V_139 ) ;
}
return 0 ;
}
static void F_87 ( struct V_291 * V_8 )
{
struct V_286 * V_287 = V_8 -> V_284 -> V_288 ;
V_287 -> V_139 . V_151 = true ;
if ( F_86 ( V_8 -> V_284 ) < 0 )
F_35 ( V_8 , L_35 ) ;
}
static int F_88 ( struct V_2 * V_4 , struct V_291 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_286 * V_287 ;
struct V_138 * V_139 ;
if ( ! V_8 -> V_284 )
return - V_89 ;
V_287 = V_8 -> V_284 -> V_288 ;
V_6 = V_287 -> V_6 ;
V_139 = & V_287 -> V_139 ;
if ( ! V_139 -> V_151 )
F_87 ( V_8 ) ;
F_89 ( & V_237 -> V_248 ) ;
if ( ! V_237 -> V_6 ) {
V_237 -> V_6 = V_6 ;
V_19 = F_82 ( V_4 ) ;
if ( V_19 ) {
V_237 -> V_6 = NULL ;
goto V_292;
}
} else if ( V_237 -> V_6 != V_6 ) {
F_32 ( V_8 ,
L_36 ,
F_90 ( V_237 -> V_6 -> V_8 ) ,
F_90 ( V_6 -> V_8 ) ) ;
V_19 = - V_293 ;
goto V_292;
}
V_139 -> V_151 = false ;
V_139 -> V_150 = true ;
if ( V_237 -> V_238 == V_239 ) {
V_139 -> V_154 = & V_237 -> V_154 ;
V_139 -> V_169 = NULL ;
F_41 ( V_6 , V_139 -> V_154 ) ;
} else {
V_139 -> V_154 = NULL ;
V_139 -> V_169 = & V_237 -> V_169 ;
}
V_19 = F_86 ( V_8 -> V_284 ) ;
if ( V_19 < 0 )
V_139 -> V_150 = false ;
V_292:
F_91 ( & V_237 -> V_248 ) ;
return V_19 ;
}
static int F_92 ( struct V_2 * V_4 , unsigned long V_240 ,
T_9 V_294 , T_5 V_46 , int V_295 )
{
int V_19 ;
unsigned long V_99 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_296 = V_237 -> V_251 ;
if ( ! V_296 )
return - V_297 ;
F_36 ( & V_237 -> V_249 , V_99 ) ;
V_19 = V_296 -> V_250 ( V_296 , V_240 , V_294 , V_46 , V_295 ) ;
F_38 ( & V_237 -> V_249 , V_99 ) ;
return V_19 ;
}
static T_5
F_93 ( struct V_2 * V_4 , unsigned long V_240 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_99 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_296 = V_237 -> V_251 ;
if ( ! V_296 )
return 0 ;
F_36 ( & V_237 -> V_249 , V_99 ) ;
V_19 = V_296 -> V_298 ( V_296 , V_240 , V_46 ) ;
F_38 ( & V_237 -> V_249 , V_99 ) ;
return V_19 ;
}
static T_9
F_94 ( struct V_2 * V_4 , T_10 V_240 )
{
T_9 V_19 ;
unsigned long V_99 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_296 = V_237 -> V_251 ;
if ( ! V_296 )
return 0 ;
F_36 ( & V_237 -> V_249 , V_99 ) ;
V_19 = V_296 -> V_299 ( V_296 , V_240 ) ;
F_38 ( & V_237 -> V_249 , V_99 ) ;
return V_19 ;
}
static int F_95 ( struct V_291 * V_8 , void * V_300 )
{
return V_8 -> V_301 == V_300 ;
}
static
struct V_5 * F_96 ( struct V_302 * V_301 )
{
struct V_291 * V_8 = F_97 ( & V_303 . V_304 , NULL ,
V_301 , F_95 ) ;
F_98 ( V_8 ) ;
return V_8 ? F_99 ( V_8 ) : NULL ;
}
static bool F_100 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_305 = V_6 -> V_186 . V_306 ;
if ( V_6 -> V_100 & V_283 )
V_305 *= 1UL << V_188 ;
return V_44 < V_305 ;
}
static int F_101 ( struct V_291 * V_8 )
{
int V_7 , V_19 ;
struct V_5 * V_6 ;
struct V_286 * V_287 ;
struct V_284 * V_285 = V_8 -> V_284 ;
struct V_307 * V_308 ;
if ( ! V_285 || V_285 -> V_296 != & V_309 )
return - V_297 ;
if ( F_102 ( V_285 -> V_288 ) ) {
V_287 = V_285 -> V_288 ;
V_6 = V_287 -> V_6 ;
} else {
V_6 = F_96 ( V_285 -> V_310 ) ;
if ( ! V_6 )
return - V_297 ;
V_287 = F_66 ( sizeof( * V_287 ) , V_191 ) ;
if ( ! V_287 )
return - V_193 ;
V_287 -> V_6 = V_6 ;
V_285 -> V_288 = V_287 ;
}
for ( V_7 = 0 ; V_7 < V_285 -> V_289 ; V_7 ++ ) {
T_1 V_44 = V_285 -> V_290 [ V_7 ] ;
if ( ! F_100 ( V_6 , V_44 ) )
return - V_311 ;
if ( V_6 -> V_100 & V_283 ) {
V_19 = F_50 ( V_6 , V_44 ) ;
if ( V_19 )
return V_19 ;
}
}
V_308 = F_103 ( V_8 ) ;
if ( ! F_104 ( V_308 ) ) {
F_105 ( V_308 ) ;
F_106 ( & V_6 -> V_312 , V_8 ) ;
}
return F_107 ( V_308 ) ;
}
static void F_108 ( struct V_291 * V_8 )
{
struct V_284 * V_285 = V_8 -> V_284 ;
struct V_286 * V_287 ;
struct V_5 * V_6 ;
if ( ! V_285 || V_285 -> V_296 != & V_309 )
return;
V_287 = V_285 -> V_288 ;
V_6 = V_287 -> V_6 ;
if ( V_287 && V_287 -> V_139 . V_150 )
F_87 ( V_8 ) ;
F_109 ( V_8 ) ;
F_110 ( & V_6 -> V_312 , V_8 ) ;
F_68 ( V_287 ) ;
F_111 ( V_8 ) ;
}
static struct V_307 * F_112 ( struct V_291 * V_8 )
{
struct V_307 * V_308 ;
if ( F_113 ( V_8 ) )
V_308 = F_114 ( V_8 ) ;
else
V_308 = F_115 ( V_8 ) ;
return V_308 ;
}
static int F_116 ( struct V_2 * V_4 ,
enum V_313 V_314 , void * V_300 )
{
struct V_1 * V_237 = F_1 ( V_4 ) ;
switch ( V_314 ) {
case V_315 :
* ( int * ) V_300 = ( V_237 -> V_238 == V_273 ) ;
return 0 ;
default:
return - V_297 ;
}
}
static int F_117 ( struct V_2 * V_4 ,
enum V_313 V_314 , void * V_300 )
{
int V_19 = 0 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
F_89 ( & V_237 -> V_248 ) ;
switch ( V_314 ) {
case V_315 :
if ( V_237 -> V_6 ) {
V_19 = - V_316 ;
goto V_292;
}
if ( * ( int * ) V_300 )
V_237 -> V_238 = V_273 ;
else
V_237 -> V_238 = V_239 ;
break;
default:
V_19 = - V_297 ;
}
V_292:
F_91 ( & V_237 -> V_248 ) ;
return V_19 ;
}
static int F_118 ( struct V_291 * V_8 , struct V_317 * args )
{
return F_119 ( V_8 , args -> args , 1 ) ;
}
static void F_120 ( struct V_291 * V_8 ,
struct V_318 * V_319 )
{
struct V_320 * V_321 ;
int V_295 = V_322 | V_323 | V_324 ;
V_321 = F_121 ( V_325 , V_326 ,
V_295 , V_327 ) ;
if ( ! V_321 )
return;
F_122 ( & V_321 -> V_328 , V_319 ) ;
}
static void F_123 ( struct V_291 * V_8 ,
struct V_318 * V_319 )
{
struct V_320 * V_329 , * V_330 ;
F_124 (entry, next, head, list)
F_68 ( V_329 ) ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_331 ,
unsigned long V_332 ,
T_5 V_333 )
{
T_5 V_334 = ( ( 1 << V_15 -> V_335 ) * V_333 ) << 3 ;
V_15 -> V_223 = F_52 ( V_6 -> V_8 , V_334 , & V_15 -> V_336 , V_191 ) ;
if ( ! V_15 -> V_223 ) {
F_32 ( V_6 -> V_8 , L_37 ,
V_334 ) ;
return - V_193 ;
}
V_15 -> V_20 = V_6 -> V_223 + V_331 ;
V_15 -> V_18 = V_6 -> V_223 + V_332 ;
V_15 -> V_32 = V_333 ;
V_15 -> V_337 = V_338 ;
V_15 -> V_337 |= V_15 -> V_336 & V_339 << V_340 ;
V_15 -> V_337 |= ( V_15 -> V_335 & V_341 )
<< V_342 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static int F_126 ( struct V_5 * V_6 )
{
int V_19 ;
F_70 ( & V_6 -> V_94 . V_102 ) ;
V_19 = F_125 ( V_6 , & V_6 -> V_94 . V_15 , V_343 ,
V_344 , V_36 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_125 ( V_6 , & V_6 -> V_195 . V_15 , V_345 ,
V_346 , V_197 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_6 -> V_100 & V_347 ) )
return 0 ;
return F_125 ( V_6 , & V_6 -> V_218 . V_15 , V_348 ,
V_349 , V_219 ) ;
}
static int F_127 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_185 * V_115 = & V_6 -> V_186 ;
T_5 V_46 = sizeof( * V_115 -> V_187 ) * V_115 -> V_306 ;
void * V_182 = V_6 -> V_186 . V_182 ;
V_115 -> V_187 = F_128 ( V_6 -> V_8 , V_46 , V_191 ) ;
if ( ! V_115 -> V_187 ) {
F_32 ( V_6 -> V_8 , L_38 ) ;
return - V_193 ;
}
for ( V_7 = 0 ; V_7 < V_115 -> V_306 ; ++ V_7 ) {
F_43 ( V_182 , & V_115 -> V_187 [ V_7 ] ) ;
V_182 += V_190 << 3 ;
}
return 0 ;
}
static int F_129 ( struct V_5 * V_6 )
{
void * V_182 ;
T_4 V_350 ;
T_1 V_46 , V_351 ;
struct V_185 * V_115 = & V_6 -> V_186 ;
V_46 = V_352 - ( F_51 ( V_190 ) + 3 ) ;
V_46 = F_130 ( V_46 , V_6 -> V_353 - V_188 ) ;
V_115 -> V_306 = 1 << V_46 ;
V_46 += V_188 ;
if ( V_46 < V_6 -> V_353 )
F_35 ( V_6 -> V_8 ,
L_39 ,
V_46 , V_6 -> V_353 ) ;
V_351 = V_115 -> V_306 * ( V_190 << 3 ) ;
V_182 = F_52 ( V_6 -> V_8 , V_351 , & V_115 -> V_354 ,
V_191 | V_192 ) ;
if ( ! V_182 ) {
F_32 ( V_6 -> V_8 ,
L_40 ,
V_46 ) ;
return - V_193 ;
}
V_115 -> V_182 = V_182 ;
V_350 = V_355 ;
V_350 |= ( V_46 & V_356 )
<< V_357 ;
V_350 |= ( V_188 & V_358 )
<< V_359 ;
V_115 -> V_360 = V_350 ;
return F_127 ( V_6 ) ;
}
static int F_131 ( struct V_5 * V_6 )
{
void * V_182 ;
T_4 V_350 ;
T_1 V_46 ;
struct V_185 * V_115 = & V_6 -> V_186 ;
V_46 = ( 1 << V_6 -> V_353 ) * ( V_184 << 3 ) ;
V_182 = F_52 ( V_6 -> V_8 , V_46 , & V_115 -> V_354 ,
V_191 | V_192 ) ;
if ( ! V_182 ) {
F_32 ( V_6 -> V_8 ,
L_41 ,
V_46 ) ;
return - V_193 ;
}
V_115 -> V_182 = V_182 ;
V_115 -> V_306 = 1 << V_6 -> V_353 ;
V_350 = V_361 ;
V_350 |= ( V_6 -> V_353 & V_356 )
<< V_357 ;
V_115 -> V_360 = V_350 ;
F_49 ( V_182 , V_115 -> V_306 ) ;
return 0 ;
}
static int F_132 ( struct V_5 * V_6 )
{
T_4 V_350 ;
int V_19 ;
if ( V_6 -> V_100 & V_283 )
V_19 = F_129 ( V_6 ) ;
else
V_19 = F_131 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_350 = V_6 -> V_186 . V_354 &
V_362 << V_363 ;
V_350 |= V_364 ;
V_6 -> V_186 . V_365 = V_350 ;
F_133 ( 0 , V_6 -> V_255 ) ;
return 0 ;
}
static int F_134 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_126 ( V_6 ) ;
if ( V_19 )
return V_19 ;
return F_132 ( V_6 ) ;
}
static int F_135 ( struct V_5 * V_6 , T_1 V_104 ,
unsigned int V_366 , unsigned int V_367 )
{
T_1 V_350 ;
F_136 ( V_104 , V_6 -> V_223 + V_366 ) ;
return F_137 ( V_6 -> V_223 + V_367 , V_350 , V_350 == V_104 ,
1 , V_25 ) ;
}
static int F_138 ( struct V_5 * V_6 , T_1 V_368 , T_1 V_369 )
{
int V_19 ;
T_1 V_350 , V_370 * V_371 = V_6 -> V_223 + V_372 ;
V_19 = F_137 ( V_371 , V_350 , ! ( V_350 & V_373 ) ,
1 , V_25 ) ;
if ( V_19 )
return V_19 ;
V_350 &= ~ V_369 ;
V_350 |= V_368 ;
F_136 ( V_350 | V_373 , V_371 ) ;
return F_137 ( V_371 , V_350 , ! ( V_350 & V_373 ) ,
1 , V_25 ) ;
}
static void F_139 ( void * V_300 )
{
struct V_291 * V_8 = V_300 ;
F_140 ( V_8 ) ;
}
static void F_141 ( struct V_374 * V_131 , struct V_375 * V_376 )
{
T_9 V_377 ;
struct V_291 * V_8 = F_142 ( V_131 ) ;
struct V_5 * V_6 = F_99 ( V_8 ) ;
T_9 * V_115 = V_378 [ V_131 -> V_379 . V_380 ] ;
V_377 = ( ( ( T_4 ) V_376 -> V_381 ) << 32 ) | V_376 -> V_382 ;
V_377 &= V_383 << V_384 ;
F_143 ( V_377 , V_6 -> V_223 + V_115 [ 0 ] ) ;
F_136 ( V_376 -> V_300 , V_6 -> V_223 + V_115 [ 1 ] ) ;
F_136 ( V_385 , V_6 -> V_223 + V_115 [ 2 ] ) ;
}
static void F_144 ( struct V_5 * V_6 )
{
struct V_374 * V_131 ;
int V_19 , V_386 = V_387 ;
struct V_291 * V_8 = V_6 -> V_8 ;
F_143 ( 0 , V_6 -> V_223 + V_388 ) ;
F_143 ( 0 , V_6 -> V_223 + V_389 ) ;
if ( V_6 -> V_100 & V_347 )
F_143 ( 0 , V_6 -> V_223 + V_390 ) ;
else
V_386 -- ;
if ( ! ( V_6 -> V_100 & V_391 ) )
return;
V_19 = F_145 ( V_8 , V_386 , F_141 ) ;
if ( V_19 ) {
F_35 ( V_8 , L_42 ) ;
return;
}
F_146 (desc, dev) {
switch ( V_131 -> V_379 . V_380 ) {
case V_392 :
V_6 -> V_195 . V_15 . V_194 = V_131 -> V_194 ;
break;
case V_393 :
V_6 -> V_394 = V_131 -> V_194 ;
break;
case V_395 :
V_6 -> V_218 . V_15 . V_194 = V_131 -> V_194 ;
break;
default:
continue;
}
}
F_147 ( V_8 , F_139 , V_8 ) ;
}
static int F_148 ( struct V_5 * V_6 )
{
int V_19 , V_194 ;
T_1 V_396 = V_397 | V_398 ;
V_19 = F_135 ( V_6 , 0 , V_399 ,
V_400 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_43 ) ;
return V_19 ;
}
F_144 ( V_6 ) ;
V_194 = V_6 -> V_195 . V_15 . V_194 ;
if ( V_194 ) {
V_19 = F_149 ( V_6 -> V_8 , V_194 , NULL ,
F_53 ,
V_401 ,
L_44 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_45 ) ;
}
V_194 = V_6 -> V_94 . V_15 . V_194 ;
if ( V_194 ) {
V_19 = F_150 ( V_6 -> V_8 , V_194 ,
F_57 , 0 ,
L_46 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_47 ) ;
}
V_194 = V_6 -> V_394 ;
if ( V_194 ) {
V_19 = F_150 ( V_6 -> V_8 , V_194 , F_58 ,
0 , L_48 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_49 ) ;
}
if ( V_6 -> V_100 & V_347 ) {
V_194 = V_6 -> V_218 . V_15 . V_194 ;
if ( V_194 ) {
V_19 = F_149 ( V_6 -> V_8 , V_194 , NULL ,
F_56 ,
V_401 ,
L_50 ,
V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 ,
L_51 ) ;
else
V_396 |= V_402 ;
}
}
V_19 = F_135 ( V_6 , V_396 ,
V_399 , V_400 ) ;
if ( V_19 )
F_35 ( V_6 -> V_8 , L_52 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_135 ( V_6 , 0 , V_403 , V_404 ) ;
if ( V_19 )
F_32 ( V_6 -> V_8 , L_53 ) ;
return V_19 ;
}
static int F_151 ( struct V_5 * V_6 , bool V_151 )
{
int V_19 ;
T_1 V_350 , V_405 ;
struct V_35 V_34 ;
V_350 = F_11 ( V_6 -> V_223 + V_403 ) ;
if ( V_350 & V_406 )
F_35 ( V_6 -> V_8 , L_54 ) ;
V_19 = F_59 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_350 = ( V_407 << V_408 ) |
( V_409 << V_410 ) |
( V_409 << V_411 ) |
( V_407 << V_412 ) |
( V_409 << V_413 ) |
( V_409 << V_414 ) ;
F_136 ( V_350 , V_6 -> V_223 + V_415 ) ;
V_350 = V_416 | V_417 | V_418 ;
F_136 ( V_350 , V_6 -> V_223 + V_419 ) ;
F_143 ( V_6 -> V_186 . V_365 ,
V_6 -> V_223 + V_420 ) ;
F_136 ( V_6 -> V_186 . V_360 ,
V_6 -> V_223 + V_421 ) ;
F_143 ( V_6 -> V_94 . V_15 . V_337 , V_6 -> V_223 + V_422 ) ;
F_136 ( V_6 -> V_94 . V_15 . V_16 , V_6 -> V_223 + V_343 ) ;
F_136 ( V_6 -> V_94 . V_15 . V_17 , V_6 -> V_223 + V_344 ) ;
V_405 = V_423 ;
V_19 = F_135 ( V_6 , V_405 , V_403 ,
V_404 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_55 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
if ( V_6 -> V_100 & V_424 ) {
V_34 . V_37 = V_40 ;
F_34 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
F_143 ( V_6 -> V_195 . V_15 . V_337 , V_6 -> V_223 + V_425 ) ;
F_136 ( V_6 -> V_195 . V_15 . V_16 , V_6 -> V_223 + V_345 ) ;
F_136 ( V_6 -> V_195 . V_15 . V_17 , V_6 -> V_223 + V_346 ) ;
V_405 |= V_426 ;
V_19 = F_135 ( V_6 , V_405 , V_403 ,
V_404 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
if ( V_6 -> V_100 & V_347 ) {
F_143 ( V_6 -> V_218 . V_15 . V_337 ,
V_6 -> V_223 + V_427 ) ;
F_136 ( V_6 -> V_218 . V_15 . V_16 ,
V_6 -> V_223 + V_348 ) ;
F_136 ( V_6 -> V_218 . V_15 . V_17 ,
V_6 -> V_223 + V_349 ) ;
V_405 |= V_428 ;
V_19 = F_135 ( V_6 , V_405 , V_403 ,
V_404 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
}
V_19 = F_148 ( V_6 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
if ( ! V_151 || V_149 ) {
V_405 |= V_406 ;
} else {
V_19 = F_138 ( V_6 , 0 , V_429 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_59 ) ;
return V_19 ;
}
}
V_19 = F_135 ( V_6 , V_405 , V_403 ,
V_404 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_60 ) ;
return V_19 ;
}
return 0 ;
}
static int F_152 ( struct V_5 * V_6 )
{
T_1 V_350 ;
bool V_430 = V_6 -> V_100 & V_431 ;
V_350 = F_11 ( V_6 -> V_223 + V_432 ) ;
if ( ( V_350 & V_433 << V_434 ) == V_435 )
V_6 -> V_100 |= V_283 ;
if ( V_350 & V_436 )
V_6 -> V_100 |= V_437 ;
switch ( V_350 & V_438 << V_439 ) {
case V_440 :
V_6 -> V_100 |= V_441 | V_442 ;
break;
#ifdef F_42
case V_443 :
V_6 -> V_100 |= V_442 ;
break;
#else
case V_444 :
V_6 -> V_100 |= V_441 ;
break;
#endif
default:
F_32 ( V_6 -> V_8 , L_61 ) ;
return - V_293 ;
}
if ( F_153 ( V_445 ) && V_350 & V_446 )
V_6 -> V_100 |= V_347 ;
if ( F_153 ( F_48 ) && V_350 & V_447 )
V_6 -> V_100 |= V_448 ;
if ( V_350 & V_449 )
V_6 -> V_100 |= V_101 ;
if ( V_350 & V_450 )
V_6 -> V_100 |= V_391 ;
if ( V_350 & V_451 )
V_6 -> V_100 |= V_424 ;
if ( ! ! ( V_350 & V_452 ) != V_430 )
F_35 ( V_6 -> V_8 , L_62 ,
V_430 ? L_63 : L_64 ) ;
switch ( V_350 & V_453 << V_454 ) {
case V_455 :
case V_456 :
V_6 -> V_100 |= V_164 ;
}
if ( V_350 & V_457 )
V_6 -> V_100 |= V_268 ;
if ( V_350 & V_458 )
V_6 -> V_100 |= V_270 ;
if ( ! ( V_350 & ( V_457 | V_458 ) ) ) {
F_32 ( V_6 -> V_8 , L_65 ) ;
return - V_293 ;
}
switch ( V_350 & V_459 << V_460 ) {
case V_461 :
V_6 -> V_263 = 40 ;
case V_462 :
break;
default:
F_32 ( V_6 -> V_8 , L_66 ) ;
return - V_293 ;
}
V_6 -> V_258 = V_350 & V_463 ? 16 : 8 ;
V_6 -> V_261 = V_350 & V_464 ? 16 : 8 ;
V_350 = F_11 ( V_6 -> V_223 + V_465 ) ;
if ( V_350 & ( V_466 | V_467 | V_468 ) ) {
F_32 ( V_6 -> V_8 , L_67 ) ;
return - V_293 ;
}
V_6 -> V_94 . V_15 . V_335 = F_130 ( ( T_1 ) V_469 ,
V_350 >> V_470 & V_471 ) ;
if ( ! V_6 -> V_94 . V_15 . V_335 ) {
F_32 ( V_6 -> V_8 , L_68 ) ;
return - V_293 ;
}
V_6 -> V_195 . V_15 . V_335 = F_130 ( ( T_1 ) V_472 ,
V_350 >> V_473 & V_474 ) ;
V_6 -> V_218 . V_15 . V_335 = F_130 ( ( T_1 ) V_475 ,
V_350 >> V_476 & V_477 ) ;
V_6 -> V_478 = V_350 >> V_479 & V_480 ;
V_6 -> V_353 = V_350 >> V_481 & V_482 ;
if ( V_6 -> V_353 <= V_188 )
V_6 -> V_100 &= ~ V_283 ;
V_350 = F_11 ( V_6 -> V_223 + V_483 ) ;
V_6 -> V_195 . V_484 = V_350 >> V_485
& V_486 ;
if ( V_350 & V_487 )
V_6 -> V_275 |= V_488 | V_489 ;
if ( V_350 & V_490 )
V_6 -> V_275 |= V_491 | V_492 ;
if ( V_350 & V_493 )
V_6 -> V_275 |= V_494 | V_495 | V_496 ;
if ( V_309 . V_275 == - 1UL )
V_309 . V_275 = V_6 -> V_275 ;
else
V_309 . V_275 |= V_6 -> V_275 ;
switch ( V_350 & V_497 << V_498 ) {
case V_499 :
V_6 -> V_264 = 32 ;
break;
case V_500 :
V_6 -> V_264 = 36 ;
break;
case V_501 :
V_6 -> V_264 = 40 ;
break;
case V_502 :
V_6 -> V_264 = 42 ;
break;
case V_503 :
V_6 -> V_264 = 44 ;
break;
default:
F_54 ( V_6 -> V_8 ,
L_69 ) ;
case V_504 :
V_6 -> V_264 = 48 ;
}
if ( F_154 ( V_6 -> V_8 , F_155 ( V_6 -> V_264 ) ) )
F_35 ( V_6 -> V_8 ,
L_70 ) ;
V_6 -> V_263 = F_156 ( V_6 -> V_263 , V_6 -> V_264 ) ;
F_54 ( V_6 -> V_8 , L_71 ,
V_6 -> V_263 , V_6 -> V_264 , V_6 -> V_100 ) ;
return 0 ;
}
static int F_157 ( struct V_505 * V_506 ,
struct V_5 * V_6 )
{
struct V_507 * V_508 ;
struct V_291 * V_8 = V_6 -> V_8 ;
struct V_509 * V_510 ;
V_510 = * (struct V_509 * * ) F_158 ( V_8 ) ;
V_508 = (struct V_507 * ) V_510 -> V_511 ;
if ( V_508 -> V_99 & V_512 )
V_6 -> V_100 |= V_431 ;
return 0 ;
}
static inline int F_157 ( struct V_505 * V_506 ,
struct V_5 * V_6 )
{
return - V_297 ;
}
static int F_159 ( struct V_505 * V_506 ,
struct V_5 * V_6 )
{
struct V_291 * V_8 = & V_506 -> V_8 ;
T_1 V_513 ;
int V_19 = - V_86 ;
if ( F_160 ( V_8 -> V_9 , L_72 , & V_513 ) )
F_32 ( V_8 , L_73 ) ;
else if ( V_513 != 1 )
F_32 ( V_8 , L_74 , V_513 ) ;
else
V_19 = 0 ;
F_3 ( V_6 ) ;
if ( F_161 ( V_8 -> V_9 ) )
V_6 -> V_100 |= V_431 ;
return V_19 ;
}
static int F_162 ( struct V_505 * V_506 )
{
int V_194 , V_19 ;
struct V_514 * V_515 ;
T_11 V_516 ;
struct V_5 * V_6 ;
struct V_291 * V_8 = & V_506 -> V_8 ;
bool V_151 ;
V_6 = F_128 ( V_8 , sizeof( * V_6 ) , V_191 ) ;
if ( ! V_6 ) {
F_32 ( V_8 , L_75 ) ;
return - V_193 ;
}
V_6 -> V_8 = V_8 ;
V_515 = F_163 ( V_506 , V_517 , 0 ) ;
if ( F_164 ( V_515 ) + 1 < V_518 ) {
F_32 ( V_8 , L_76 , V_515 ) ;
return - V_86 ;
}
V_516 = V_515 -> V_519 ;
V_6 -> V_223 = F_165 ( V_8 , V_515 ) ;
if ( F_104 ( V_6 -> V_223 ) )
return F_166 ( V_6 -> V_223 ) ;
V_194 = F_167 ( V_506 , L_77 ) ;
if ( V_194 > 0 )
V_6 -> V_195 . V_15 . V_194 = V_194 ;
V_194 = F_167 ( V_506 , L_78 ) ;
if ( V_194 > 0 )
V_6 -> V_218 . V_15 . V_194 = V_194 ;
V_194 = F_167 ( V_506 , L_79 ) ;
if ( V_194 > 0 )
V_6 -> V_94 . V_15 . V_194 = V_194 ;
V_194 = F_167 ( V_506 , L_80 ) ;
if ( V_194 > 0 )
V_6 -> V_394 = V_194 ;
if ( V_8 -> V_9 ) {
V_19 = F_159 ( V_506 , V_6 ) ;
} else {
V_19 = F_157 ( V_506 , V_6 ) ;
if ( V_19 == - V_297 )
return V_19 ;
}
V_151 = ! ! V_19 ;
V_19 = F_152 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_134 ( V_6 ) ;
if ( V_19 )
return V_19 ;
F_168 ( V_506 , V_6 ) ;
V_19 = F_151 ( V_6 , V_151 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_169 ( & V_6 -> V_312 , V_8 , NULL ,
L_81 , & V_516 ) ;
if ( V_19 )
return V_19 ;
F_170 ( & V_6 -> V_312 , & V_309 ) ;
F_171 ( & V_6 -> V_312 , V_8 -> V_301 ) ;
V_19 = F_172 ( & V_6 -> V_312 ) ;
#ifdef F_173
if ( V_520 . V_521 != & V_309 ) {
F_174 () ;
V_19 = F_175 ( & V_520 , & V_309 ) ;
if ( V_19 )
return V_19 ;
}
#endif
#ifdef F_176
if ( V_522 . V_521 != & V_309 ) {
V_19 = F_175 ( & V_522 , & V_309 ) ;
if ( V_19 )
return V_19 ;
}
#endif
if ( V_523 . V_521 != & V_309 ) {
V_19 = F_175 ( & V_523 , & V_309 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_177 ( struct V_505 * V_506 )
{
struct V_5 * V_6 = F_178 ( V_506 ) ;
F_59 ( V_6 ) ;
return 0 ;
}
static int T_12 F_179 ( void )
{
static bool V_524 ;
int V_19 = 0 ;
if ( ! V_524 ) {
V_19 = F_180 ( & V_303 ) ;
V_524 = ! V_19 ;
}
return V_19 ;
}
static void T_13 F_181 ( void )
{
return F_182 ( & V_303 ) ;
}
static int T_12 F_183 ( struct V_525 * V_526 )
{
int V_19 = F_179 () ;
if ( V_19 )
return V_19 ;
if ( ! F_184 ( V_526 , NULL , V_523 . V_527 ) )
return - V_297 ;
return 0 ;
}
static int T_12 F_185 ( struct V_528 * V_529 )
{
if ( F_186 ( V_530 ) )
return F_179 () ;
return 0 ;
}
