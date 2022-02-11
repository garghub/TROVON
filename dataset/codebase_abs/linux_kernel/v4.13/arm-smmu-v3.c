static inline void T_1 * F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
if ( ( V_1 > V_4 ) &&
( V_3 -> V_5 & V_6 ) )
V_1 -= V_4 ;
return V_3 -> V_7 + V_1 ;
}
static struct V_8 * F_2 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , struct V_8 , V_11 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
int V_12 = 0 ;
do {
if ( F_5 ( V_3 -> V_13 -> V_14 ,
V_15 [ V_12 ] . V_16 ) ) {
V_3 -> V_5 |= V_15 [ V_12 ] . V_17 ;
F_6 ( V_3 -> V_13 , L_1 ,
V_15 [ V_12 ] . V_16 ) ;
}
} while ( V_15 [ ++ V_12 ] . V_17 );
}
static bool F_7 ( struct V_18 * V_19 )
{
return F_8 ( V_19 , V_19 -> V_20 ) == F_8 ( V_19 , V_19 -> V_21 ) &&
F_9 ( V_19 , V_19 -> V_20 ) != F_9 ( V_19 , V_19 -> V_21 ) ;
}
static bool F_10 ( struct V_18 * V_19 )
{
return F_8 ( V_19 , V_19 -> V_20 ) == F_8 ( V_19 , V_19 -> V_21 ) &&
F_9 ( V_19 , V_19 -> V_20 ) == F_9 ( V_19 , V_19 -> V_21 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
V_19 -> V_21 = F_12 ( V_19 -> V_22 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
T_2 V_21 = ( F_9 ( V_19 , V_19 -> V_21 ) | F_8 ( V_19 , V_19 -> V_21 ) ) + 1 ;
V_19 -> V_21 = F_14 ( V_19 , V_19 -> V_21 ) | F_9 ( V_19 , V_21 ) | F_8 ( V_19 , V_21 ) ;
F_15 ( V_19 -> V_21 , V_19 -> V_22 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
int V_23 = 0 ;
T_2 V_20 = F_12 ( V_19 -> V_24 ) ;
if ( F_14 ( V_19 , V_20 ) != F_14 ( V_19 , V_19 -> V_20 ) )
V_23 = - V_25 ;
V_19 -> V_20 = V_20 ;
return V_23 ;
}
static void F_17 ( struct V_18 * V_19 )
{
T_2 V_20 = ( F_9 ( V_19 , V_19 -> V_20 ) | F_8 ( V_19 , V_19 -> V_20 ) ) + 1 ;
V_19 -> V_20 = F_14 ( V_19 , V_19 -> V_20 ) | F_9 ( V_19 , V_20 ) | F_8 ( V_19 , V_20 ) ;
F_15 ( V_19 -> V_20 , V_19 -> V_24 ) ;
}
static int F_18 ( struct V_18 * V_19 , bool V_26 , bool V_27 )
{
T_3 V_28 ;
unsigned int V_29 = 1 ;
V_28 = F_19 ( F_20 () , V_26 ?
V_30 :
V_31 ) ;
while ( F_11 ( V_19 ) , ( V_26 ? ! F_10 ( V_19 ) : F_7 ( V_19 ) ) ) {
if ( F_21 ( F_20 () , V_28 ) > 0 )
return - V_32 ;
if ( V_27 ) {
V_27 () ;
} else {
F_22 () ;
F_23 ( V_29 ) ;
V_29 *= 2 ;
}
}
return 0 ;
}
static void F_24 ( T_4 * V_33 , T_5 * V_34 , T_6 V_35 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
* V_33 ++ = F_25 ( * V_34 ++ ) ;
}
static int F_26 ( struct V_18 * V_19 , T_5 * V_36 )
{
if ( F_7 ( V_19 ) )
return - V_37 ;
F_24 ( F_27 ( V_19 , V_19 -> V_20 ) , V_36 , V_19 -> V_38 ) ;
F_17 ( V_19 ) ;
return 0 ;
}
static void F_28 ( T_4 * V_33 , T_5 * V_34 , T_6 V_35 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
* V_33 ++ = F_29 ( * V_34 ++ ) ;
}
static int F_30 ( struct V_18 * V_19 , T_5 * V_36 )
{
if ( F_10 ( V_19 ) )
return - V_39 ;
F_28 ( V_36 , F_27 ( V_19 , V_19 -> V_21 ) , V_19 -> V_38 ) ;
F_13 ( V_19 ) ;
return 0 ;
}
static int F_31 ( T_5 * V_40 , struct V_41 * V_36 )
{
memset ( V_40 , 0 , V_42 << 3 ) ;
V_40 [ 0 ] |= ( V_36 -> V_43 & V_44 ) << V_45 ;
switch ( V_36 -> V_43 ) {
case V_46 :
case V_47 :
break;
case V_48 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_49 . V_50 << V_51 ;
V_40 [ 1 ] |= V_36 -> V_49 . V_52 << V_53 ;
V_40 [ 1 ] |= V_36 -> V_49 . V_54 & V_55 ;
break;
case V_56 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_57 . V_50 << V_58 ;
V_40 [ 1 ] |= V_36 -> V_57 . V_59 ? V_60 : 0 ;
break;
case V_61 :
V_40 [ 1 ] |= V_62 << V_63 ;
break;
case V_64 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_65 . V_66 << V_67 ;
V_40 [ 1 ] |= V_36 -> V_65 . V_59 ? V_68 : 0 ;
V_40 [ 1 ] |= V_36 -> V_65 . V_54 & V_69 ;
break;
case V_70 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_65 . V_71 << V_72 ;
V_40 [ 1 ] |= V_36 -> V_65 . V_59 ? V_68 : 0 ;
V_40 [ 1 ] |= V_36 -> V_65 . V_54 & V_73 ;
break;
case V_74 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_65 . V_66 << V_67 ;
case V_75 :
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_65 . V_71 << V_72 ;
break;
case V_76 :
V_40 [ 0 ] |= V_36 -> V_77 ? V_78 : 0 ;
V_40 [ 0 ] |= V_36 -> V_79 . V_80 << V_81 ;
V_40 [ 0 ] |= ( T_5 ) V_36 -> V_79 . V_50 << V_82 ;
V_40 [ 1 ] |= V_36 -> V_79 . V_83 << V_84 ;
switch ( V_36 -> V_79 . V_85 ) {
case V_86 :
V_40 [ 1 ] |= V_87 ;
break;
case V_88 :
V_40 [ 1 ] |= V_89 ;
break;
case V_90 :
V_40 [ 1 ] |= V_91 ;
break;
default:
return - V_92 ;
}
break;
case V_93 :
V_40 [ 0 ] |= V_94 ;
break;
default:
return - V_95 ;
}
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
static const char * V_96 [] = {
[ V_97 ] = L_2 ,
[ V_98 ] = L_3 ,
[ V_99 ] = L_4 ,
} ;
int V_12 ;
T_5 V_40 [ V_42 ] ;
struct V_18 * V_19 = & V_3 -> V_100 . V_19 ;
T_2 V_21 = F_12 ( V_19 -> V_22 ) ;
T_2 V_101 = V_21 >> V_102 & V_103 ;
struct V_41 V_104 = {
. V_43 = V_93 ,
} ;
F_33 ( V_3 -> V_13 , L_5 , V_21 ,
V_101 < F_34 ( V_96 ) ? V_96 [ V_101 ] : L_6 ) ;
switch ( V_101 ) {
case V_99 :
F_33 ( V_3 -> V_13 , L_7 ) ;
case V_97 :
return;
case V_98 :
default:
break;
}
F_28 ( V_40 , F_27 ( V_19 , V_21 ) , V_19 -> V_38 ) ;
F_33 ( V_3 -> V_13 , L_8 ) ;
for ( V_12 = 0 ; V_12 < F_34 ( V_40 ) ; ++ V_12 )
F_33 ( V_3 -> V_13 , L_9 , ( unsigned long long ) V_40 [ V_12 ] ) ;
if ( F_31 ( V_40 , & V_104 ) ) {
F_33 ( V_3 -> V_13 , L_10 ) ;
return;
}
F_24 ( F_27 ( V_19 , V_21 ) , V_40 , V_19 -> V_38 ) ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_41 * V_36 )
{
T_5 V_40 [ V_42 ] ;
unsigned long V_105 ;
bool V_27 = ! ! ( V_3 -> V_106 & V_107 ) ;
struct V_18 * V_19 = & V_3 -> V_100 . V_19 ;
if ( F_31 ( V_40 , V_36 ) ) {
F_36 ( V_3 -> V_13 , L_11 ,
V_36 -> V_43 ) ;
return;
}
F_37 ( & V_3 -> V_100 . V_108 , V_105 ) ;
while ( F_26 ( V_19 , V_40 ) == - V_37 ) {
if ( F_18 ( V_19 , false , V_27 ) )
F_38 ( V_3 -> V_13 , L_12 ) ;
}
if ( V_36 -> V_43 == V_93 && F_18 ( V_19 , true , V_27 ) )
F_38 ( V_3 -> V_13 , L_13 ) ;
F_39 ( & V_3 -> V_100 . V_108 , V_105 ) ;
}
static T_5 F_40 ( T_5 V_109 )
{
T_5 V_110 = 0 ;
V_110 |= F_41 ( V_109 , V_111 ) ;
V_110 |= F_41 ( V_109 , V_112 ) ;
V_110 |= F_41 ( V_109 , V_113 ) ;
V_110 |= F_41 ( V_109 , V_114 ) ;
V_110 |= F_41 ( V_109 , V_115 ) ;
V_110 |= F_41 ( V_109 , V_116 ) ;
V_110 |= F_41 ( V_109 , V_117 ) ;
V_110 |= F_41 ( V_109 , V_118 ) ;
V_110 |= F_41 ( V_109 , V_119 ) ;
return V_110 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_120 * V_121 )
{
T_5 V_110 ;
V_110 = F_40 ( V_121 -> V_122 . V_109 ) |
#ifdef F_43
V_123 |
#endif
V_124 | V_125 | V_126 |
V_127 | ( T_5 ) V_121 -> V_122 . V_66 << V_128 |
V_129 ;
V_121 -> V_130 [ 0 ] = F_25 ( V_110 ) ;
V_110 = V_121 -> V_122 . V_131 & V_132 << V_133 ;
V_121 -> V_130 [ 1 ] = F_25 ( V_110 ) ;
V_121 -> V_130 [ 3 ] = F_25 ( V_121 -> V_122 . V_134 << V_135 ) ;
}
static void
F_44 ( T_4 * V_33 , struct V_136 * V_137 )
{
T_5 V_110 = 0 ;
V_110 |= ( V_137 -> V_138 & V_139 )
<< V_140 ;
V_110 |= V_137 -> V_141 &
V_142 << V_143 ;
* V_33 = F_25 ( V_110 ) ;
}
static void F_45 ( struct V_2 * V_3 , T_2 V_50 )
{
struct V_41 V_40 = {
. V_43 = V_56 ,
. V_57 = {
. V_50 = V_50 ,
. V_59 = true ,
} ,
} ;
F_35 ( V_3 , & V_40 ) ;
V_40 . V_43 = V_93 ;
F_35 ( V_3 , & V_40 ) ;
}
static void F_46 ( struct V_2 * V_3 , T_2 V_50 ,
T_4 * V_33 , struct V_144 * V_145 )
{
T_5 V_110 = F_29 ( V_33 [ 0 ] ) ;
bool V_146 = false ;
struct V_41 V_147 = {
. V_43 = V_48 ,
. V_49 = {
. V_50 = V_50 ,
} ,
} ;
if ( V_110 & V_148 ) {
T_5 V_121 ;
V_121 = V_110 & V_149 << V_150 ;
switch ( V_121 ) {
case V_151 :
break;
case V_152 :
case V_153 :
V_146 = true ;
break;
case V_154 :
if ( V_155 )
break;
default:
F_47 () ;
}
}
V_110 = V_148 ;
if ( ! V_145 -> V_156 || ! ( V_145 -> V_157 || V_145 -> V_158 ) ) {
if ( ! V_145 -> V_156 && V_155 )
V_110 |= V_154 ;
else
V_110 |= V_151 ;
V_33 [ 0 ] = F_25 ( V_110 ) ;
V_33 [ 1 ] = F_25 ( V_159
<< V_160 ) ;
V_33 [ 2 ] = 0 ;
if ( V_146 )
F_45 ( V_3 , V_50 ) ;
return;
}
if ( V_145 -> V_157 ) {
F_48 ( V_146 ) ;
V_33 [ 1 ] = F_25 (
V_161
<< V_162 |
V_161
<< V_163 |
V_164 << V_165 |
#ifdef F_49
V_166 << V_167 |
#endif
V_168 << V_169 ) ;
if ( V_3 -> V_106 & V_170 )
V_33 [ 1 ] |= F_25 ( V_171 ) ;
V_110 |= ( V_145 -> V_157 -> V_172 & V_173
<< V_174 ) |
V_152 ;
}
if ( V_145 -> V_158 ) {
F_48 ( V_146 ) ;
V_33 [ 2 ] = F_25 (
V_145 -> V_158 -> V_71 << V_175 |
( V_145 -> V_158 -> V_176 & V_177 )
<< V_178 |
#ifdef F_43
V_179 |
#endif
V_180 | V_181 |
V_182 ) ;
V_33 [ 3 ] = F_25 ( V_145 -> V_158 -> V_183 &
V_184 << V_185 ) ;
V_110 |= V_153 ;
}
F_45 ( V_3 , V_50 ) ;
V_33 [ 0 ] = F_25 ( V_110 ) ;
F_45 ( V_3 , V_50 ) ;
if ( ! ( V_3 -> V_5 & V_186 ) )
F_35 ( V_3 , & V_147 ) ;
}
static void F_50 ( T_5 * V_187 , unsigned int V_188 )
{
unsigned int V_12 ;
struct V_144 V_145 = { . V_156 = false } ;
for ( V_12 = 0 ; V_12 < V_188 ; ++ V_12 ) {
F_46 ( NULL , - 1 , V_187 , & V_145 ) ;
V_187 += V_189 ;
}
}
static int F_51 ( struct V_2 * V_3 , T_2 V_50 )
{
T_6 V_52 ;
void * V_187 ;
struct V_190 * V_121 = & V_3 -> V_191 ;
struct V_136 * V_137 = & V_121 -> V_192 [ V_50 >> V_193 ] ;
if ( V_137 -> V_194 )
return 0 ;
V_52 = 1 << ( V_193 + F_52 ( V_189 ) + 3 ) ;
V_187 = & V_121 -> V_187 [ ( V_50 >> V_193 ) * V_195 ] ;
V_137 -> V_138 = V_193 + 1 ;
V_137 -> V_194 = F_53 ( V_3 -> V_13 , V_52 , & V_137 -> V_141 ,
V_196 | V_197 ) ;
if ( ! V_137 -> V_194 ) {
F_33 ( V_3 -> V_13 ,
L_14 ,
V_50 ) ;
return - V_198 ;
}
F_50 ( V_137 -> V_194 , 1 << V_193 ) ;
F_44 ( V_187 , V_137 ) ;
return 0 ;
}
static T_7 F_54 ( int V_199 , void * V_13 )
{
int V_12 ;
struct V_2 * V_3 = V_13 ;
struct V_18 * V_19 = & V_3 -> V_200 . V_19 ;
T_5 V_201 [ V_202 ] ;
do {
while ( ! F_30 ( V_19 , V_201 ) ) {
T_8 V_203 = V_201 [ 0 ] >> V_204 & V_205 ;
F_55 ( V_3 -> V_13 , L_15 , V_203 ) ;
for ( V_12 = 0 ; V_12 < F_34 ( V_201 ) ; ++ V_12 )
F_55 ( V_3 -> V_13 , L_9 ,
( unsigned long long ) V_201 [ V_12 ] ) ;
}
if ( F_16 ( V_19 ) == - V_25 )
F_33 ( V_3 -> V_13 , L_16 ) ;
} while ( ! F_10 ( V_19 ) );
V_19 -> V_21 = F_14 ( V_19 , V_19 -> V_20 ) | F_9 ( V_19 , V_19 -> V_21 ) | F_8 ( V_19 , V_19 -> V_21 ) ;
return V_206 ;
}
static void F_56 ( struct V_2 * V_3 , T_5 * V_201 )
{
T_2 V_50 , V_80 ;
T_9 V_83 ;
bool V_207 , V_208 ;
V_50 = V_201 [ 0 ] >> V_209 & V_210 ;
V_207 = V_201 [ 0 ] & V_211 ;
V_80 = V_207 ? V_201 [ 0 ] >> V_212 & V_213 : 0 ;
V_208 = V_201 [ 0 ] & V_214 ;
V_83 = V_201 [ 1 ] >> V_215 & V_216 ;
F_55 ( V_3 -> V_13 , L_17 ) ;
F_55 ( V_3 -> V_13 ,
L_18 ,
V_50 , V_80 , V_83 , V_208 ? L_19 : L_20 ,
V_201 [ 0 ] & V_217 ? L_20 : L_21 ,
V_201 [ 0 ] & V_218 ? L_22 : L_20 ,
V_201 [ 0 ] & V_219 ? L_23 : L_20 ,
V_201 [ 0 ] & V_220 ? L_24 : L_20 ,
V_201 [ 1 ] & V_221 << V_222 ) ;
if ( V_208 ) {
struct V_41 V_40 = {
. V_43 = V_76 ,
. V_77 = V_207 ,
. V_79 = {
. V_50 = V_50 ,
. V_80 = V_80 ,
. V_83 = V_83 ,
. V_85 = V_86 ,
} ,
} ;
F_35 ( V_3 , & V_40 ) ;
}
}
static T_7 F_57 ( int V_199 , void * V_13 )
{
struct V_2 * V_3 = V_13 ;
struct V_18 * V_19 = & V_3 -> V_223 . V_19 ;
T_5 V_201 [ V_224 ] ;
do {
while ( ! F_30 ( V_19 , V_201 ) )
F_56 ( V_3 , V_201 ) ;
if ( F_16 ( V_19 ) == - V_25 )
F_33 ( V_3 -> V_13 , L_25 ) ;
} while ( ! F_10 ( V_19 ) );
V_19 -> V_21 = F_14 ( V_19 , V_19 -> V_20 ) | F_9 ( V_19 , V_19 -> V_21 ) | F_8 ( V_19 , V_19 -> V_21 ) ;
return V_206 ;
}
static T_7 F_58 ( int V_199 , void * V_13 )
{
return V_206 ;
}
static T_7 F_59 ( int V_199 , void * V_13 )
{
T_2 V_225 , V_226 , V_227 ;
struct V_2 * V_3 = V_13 ;
V_225 = F_12 ( V_3 -> V_7 + V_228 ) ;
V_226 = F_12 ( V_3 -> V_7 + V_229 ) ;
V_227 = V_225 ^ V_226 ;
if ( ! ( V_227 & V_230 ) )
return V_231 ;
F_36 ( V_3 -> V_13 ,
L_26 ,
V_227 ) ;
if ( V_227 & V_232 ) {
F_33 ( V_3 -> V_13 , L_27 ) ;
F_60 ( V_3 ) ;
}
if ( V_227 & V_233 )
F_36 ( V_3 -> V_13 , L_28 ) ;
if ( V_227 & V_234 )
F_36 ( V_3 -> V_13 , L_29 ) ;
if ( V_227 & V_235 )
F_36 ( V_3 -> V_13 , L_30 ) ;
if ( V_227 & V_236 ) {
F_36 ( V_3 -> V_13 , L_31 ) ;
F_58 ( V_199 , V_3 -> V_13 ) ;
}
if ( V_227 & V_237 )
F_33 ( V_3 -> V_13 , L_32 ) ;
if ( V_227 & V_238 )
F_33 ( V_3 -> V_13 , L_33 ) ;
if ( V_227 & V_239 )
F_32 ( V_3 ) ;
F_15 ( V_225 , V_3 -> V_7 + V_229 ) ;
return V_206 ;
}
static T_7 F_61 ( int V_199 , void * V_13 )
{
struct V_2 * V_3 = V_13 ;
F_54 ( V_199 , V_13 ) ;
if ( V_3 -> V_106 & V_240 )
F_57 ( V_199 , V_13 ) ;
return V_206 ;
}
static T_7 F_62 ( int V_199 , void * V_13 )
{
F_59 ( V_199 , V_13 ) ;
F_58 ( V_199 , V_13 ) ;
return V_241 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_41 V_40 ;
V_40 . V_43 = V_93 ;
F_35 ( V_3 , & V_40 ) ;
}
static void F_64 ( void * V_242 )
{
struct V_8 * V_243 = V_242 ;
F_63 ( V_243 -> V_3 ) ;
}
static void F_65 ( void * V_242 )
{
struct V_8 * V_243 = V_242 ;
struct V_2 * V_3 = V_243 -> V_3 ;
struct V_41 V_40 ;
if ( V_243 -> V_244 == V_245 ) {
V_40 . V_43 = V_74 ;
V_40 . V_65 . V_66 = V_243 -> V_157 . V_122 . V_66 ;
V_40 . V_65 . V_71 = 0 ;
} else {
V_40 . V_43 = V_75 ;
V_40 . V_65 . V_71 = V_243 -> V_158 . V_71 ;
}
F_35 ( V_3 , & V_40 ) ;
F_63 ( V_3 ) ;
}
static void F_66 ( unsigned long V_246 , T_6 V_52 ,
T_6 V_247 , bool V_59 , void * V_242 )
{
struct V_8 * V_243 = V_242 ;
struct V_2 * V_3 = V_243 -> V_3 ;
struct V_41 V_40 = {
. V_65 = {
. V_59 = V_59 ,
. V_54 = V_246 ,
} ,
} ;
if ( V_243 -> V_244 == V_245 ) {
V_40 . V_43 = V_64 ;
V_40 . V_65 . V_66 = V_243 -> V_157 . V_122 . V_66 ;
} else {
V_40 . V_43 = V_70 ;
V_40 . V_65 . V_71 = V_243 -> V_158 . V_71 ;
}
do {
F_35 ( V_3 , & V_40 ) ;
V_40 . V_65 . V_54 += V_247 ;
} while ( V_52 -= V_247 );
}
static bool F_67 ( enum V_248 V_249 )
{
switch ( V_249 ) {
case V_250 :
return true ;
case V_251 :
return true ;
default:
return false ;
}
}
static struct V_9 * F_68 ( unsigned type )
{
struct V_8 * V_243 ;
if ( type != V_252 &&
type != V_253 &&
type != V_254 )
return NULL ;
V_243 = F_69 ( sizeof( * V_243 ) , V_196 ) ;
if ( ! V_243 )
return NULL ;
if ( type == V_253 &&
F_70 ( & V_243 -> V_11 ) ) {
F_71 ( V_243 ) ;
return NULL ;
}
F_72 ( & V_243 -> V_255 ) ;
return & V_243 -> V_11 ;
}
static int F_73 ( unsigned long * V_256 , int V_138 )
{
int V_101 , V_52 = 1 << V_138 ;
do {
V_101 = F_74 ( V_256 , V_52 ) ;
if ( V_101 == V_52 )
return - V_37 ;
} while ( F_75 ( V_101 , V_256 ) );
return V_101 ;
}
static void F_76 ( unsigned long * V_256 , int V_101 )
{
F_77 ( V_101 , V_256 ) ;
}
static void F_78 ( struct V_9 * V_11 )
{
struct V_8 * V_243 = F_2 ( V_11 ) ;
struct V_2 * V_3 = V_243 -> V_3 ;
F_79 ( V_11 ) ;
F_80 ( V_243 -> V_257 ) ;
if ( V_243 -> V_244 == V_245 ) {
struct V_120 * V_121 = & V_243 -> V_157 ;
if ( V_121 -> V_130 ) {
F_81 ( V_243 -> V_3 -> V_13 ,
V_258 << 3 ,
V_121 -> V_130 ,
V_121 -> V_172 ) ;
F_76 ( V_3 -> V_259 , V_121 -> V_122 . V_66 ) ;
}
} else {
struct V_260 * V_121 = & V_243 -> V_158 ;
if ( V_121 -> V_71 )
F_76 ( V_3 -> V_261 , V_121 -> V_71 ) ;
}
F_71 ( V_243 ) ;
}
static int F_82 ( struct V_8 * V_243 ,
struct V_262 * V_263 )
{
int V_23 ;
int V_66 ;
struct V_2 * V_3 = V_243 -> V_3 ;
struct V_120 * V_121 = & V_243 -> V_157 ;
V_66 = F_73 ( V_3 -> V_259 , V_3 -> V_264 ) ;
if ( V_66 < 0 )
return V_66 ;
V_121 -> V_130 = F_53 ( V_3 -> V_13 , V_258 << 3 ,
& V_121 -> V_172 ,
V_196 | V_197 ) ;
if ( ! V_121 -> V_130 ) {
F_36 ( V_3 -> V_13 , L_34 ) ;
V_23 = - V_198 ;
goto V_265;
}
V_121 -> V_122 . V_66 = ( T_9 ) V_66 ;
V_121 -> V_122 . V_131 = V_263 -> V_266 . V_131 [ 0 ] ;
V_121 -> V_122 . V_109 = V_263 -> V_266 . V_109 ;
V_121 -> V_122 . V_134 = V_263 -> V_266 . V_134 [ 0 ] ;
return 0 ;
V_265:
F_76 ( V_3 -> V_259 , V_66 ) ;
return V_23 ;
}
static int F_83 ( struct V_8 * V_243 ,
struct V_262 * V_263 )
{
int V_71 ;
struct V_2 * V_3 = V_243 -> V_3 ;
struct V_260 * V_121 = & V_243 -> V_158 ;
V_71 = F_73 ( V_3 -> V_261 , V_3 -> V_267 ) ;
if ( V_71 < 0 )
return V_71 ;
V_121 -> V_71 = ( T_9 ) V_71 ;
V_121 -> V_183 = V_263 -> V_268 . V_183 ;
V_121 -> V_176 = V_263 -> V_268 . V_176 ;
return 0 ;
}
static int F_84 ( struct V_9 * V_11 )
{
int V_23 ;
unsigned long V_269 , V_270 ;
enum V_271 V_272 ;
struct V_262 V_263 ;
struct V_273 * V_257 ;
int (* F_85)( struct V_8 * ,
struct V_262 * );
struct V_8 * V_243 = F_2 ( V_11 ) ;
struct V_2 * V_3 = V_243 -> V_3 ;
if ( V_11 -> type == V_254 ) {
V_243 -> V_244 = V_274 ;
return 0 ;
}
if ( ! ( V_3 -> V_106 & V_275 ) )
V_243 -> V_244 = V_276 ;
if ( ! ( V_3 -> V_106 & V_277 ) )
V_243 -> V_244 = V_245 ;
switch ( V_243 -> V_244 ) {
case V_245 :
V_269 = V_278 ;
V_270 = V_3 -> V_269 ;
V_272 = V_279 ;
F_85 = F_82 ;
break;
case V_280 :
case V_276 :
V_269 = V_3 -> V_269 ;
V_270 = V_3 -> V_270 ;
V_272 = V_281 ;
F_85 = F_83 ;
break;
default:
return - V_92 ;
}
V_263 = (struct V_262 ) {
. V_282 = V_3 -> V_282 ,
. V_269 = V_269 ,
. V_270 = V_270 ,
. V_283 = & V_284 ,
. V_285 = V_3 -> V_13 ,
} ;
if ( V_3 -> V_106 & V_286 )
V_263 . V_287 = V_288 ;
V_257 = F_86 ( V_272 , & V_263 , V_243 ) ;
if ( ! V_257 )
return - V_198 ;
V_11 -> V_282 = V_263 . V_282 ;
V_11 -> V_289 . V_290 = ( 1UL << V_269 ) - 1 ;
V_11 -> V_289 . V_291 = true ;
V_243 -> V_257 = V_257 ;
V_23 = F_85 ( V_243 , & V_263 ) ;
if ( V_23 < 0 )
F_80 ( V_257 ) ;
return V_23 ;
}
static T_4 * F_87 ( struct V_2 * V_3 , T_2 V_50 )
{
T_4 * V_292 ;
struct V_190 * V_121 = & V_3 -> V_191 ;
if ( V_3 -> V_106 & V_293 ) {
struct V_136 * V_192 ;
int V_101 ;
V_101 = ( V_50 >> V_193 ) * V_195 ;
V_192 = & V_121 -> V_192 [ V_101 ] ;
V_101 = ( V_50 & ( ( 1 << V_193 ) - 1 ) ) * V_189 ;
V_292 = & V_192 -> V_194 [ V_101 ] ;
} else {
V_292 = & V_121 -> V_187 [ V_50 * V_189 ] ;
}
return V_292 ;
}
static void F_88 ( struct V_294 * V_295 )
{
int V_12 ;
struct V_296 * V_297 = V_295 -> V_298 ;
struct V_2 * V_3 = V_297 -> V_3 ;
for ( V_12 = 0 ; V_12 < V_295 -> V_299 ; ++ V_12 ) {
T_2 V_50 = V_295 -> V_300 [ V_12 ] ;
T_4 * V_292 = F_87 ( V_3 , V_50 ) ;
F_46 ( V_3 , V_50 , V_292 , & V_297 -> V_145 ) ;
}
}
static void F_89 ( struct V_301 * V_13 )
{
struct V_296 * V_297 = V_13 -> V_294 -> V_298 ;
V_297 -> V_145 . V_156 = false ;
F_88 ( V_13 -> V_294 ) ;
}
static int F_90 ( struct V_9 * V_11 , struct V_301 * V_13 )
{
int V_23 = 0 ;
struct V_2 * V_3 ;
struct V_8 * V_243 = F_2 ( V_11 ) ;
struct V_296 * V_297 ;
struct V_144 * V_145 ;
if ( ! V_13 -> V_294 )
return - V_95 ;
V_297 = V_13 -> V_294 -> V_298 ;
V_3 = V_297 -> V_3 ;
V_145 = & V_297 -> V_145 ;
if ( V_145 -> V_156 )
F_89 ( V_13 ) ;
F_91 ( & V_243 -> V_255 ) ;
if ( ! V_243 -> V_3 ) {
V_243 -> V_3 = V_3 ;
V_23 = F_84 ( V_11 ) ;
if ( V_23 ) {
V_243 -> V_3 = NULL ;
goto V_302;
}
} else if ( V_243 -> V_3 != V_3 ) {
F_33 ( V_13 ,
L_35 ,
F_92 ( V_243 -> V_3 -> V_13 ) ,
F_92 ( V_3 -> V_13 ) ) ;
V_23 = - V_303 ;
goto V_302;
}
V_145 -> V_156 = true ;
if ( V_243 -> V_244 == V_274 ) {
V_145 -> V_157 = NULL ;
V_145 -> V_158 = NULL ;
} else if ( V_243 -> V_244 == V_245 ) {
V_145 -> V_157 = & V_243 -> V_157 ;
V_145 -> V_158 = NULL ;
F_42 ( V_3 , V_145 -> V_157 ) ;
} else {
V_145 -> V_157 = NULL ;
V_145 -> V_158 = & V_243 -> V_158 ;
}
F_88 ( V_13 -> V_294 ) ;
V_302:
F_93 ( & V_243 -> V_255 ) ;
return V_23 ;
}
static int F_94 ( struct V_9 * V_11 , unsigned long V_246 ,
T_10 V_304 , T_6 V_52 , int V_305 )
{
struct V_273 * V_306 = F_2 ( V_11 ) -> V_257 ;
if ( ! V_306 )
return - V_307 ;
return V_306 -> V_256 ( V_306 , V_246 , V_304 , V_52 , V_305 ) ;
}
static T_6
F_95 ( struct V_9 * V_11 , unsigned long V_246 , T_6 V_52 )
{
struct V_273 * V_306 = F_2 ( V_11 ) -> V_257 ;
if ( ! V_306 )
return 0 ;
return V_306 -> V_308 ( V_306 , V_246 , V_52 ) ;
}
static T_10
F_96 ( struct V_9 * V_11 , T_11 V_246 )
{
struct V_273 * V_306 = F_2 ( V_11 ) -> V_257 ;
if ( V_11 -> type == V_254 )
return V_246 ;
if ( ! V_306 )
return 0 ;
return V_306 -> V_309 ( V_306 , V_246 ) ;
}
static int F_97 ( struct V_301 * V_13 , void * V_310 )
{
return V_13 -> V_311 == V_310 ;
}
static
struct V_2 * F_98 ( struct V_312 * V_311 )
{
struct V_301 * V_13 = F_99 ( & V_313 . V_314 , NULL ,
V_311 , F_97 ) ;
F_100 ( V_13 ) ;
return V_13 ? F_101 ( V_13 ) : NULL ;
}
static bool F_102 ( struct V_2 * V_3 , T_2 V_50 )
{
unsigned long V_315 = V_3 -> V_191 . V_316 ;
if ( V_3 -> V_106 & V_293 )
V_315 *= 1UL << V_193 ;
return V_50 < V_315 ;
}
static int F_103 ( struct V_301 * V_13 )
{
int V_12 , V_23 ;
struct V_2 * V_3 ;
struct V_296 * V_297 ;
struct V_294 * V_295 = V_13 -> V_294 ;
struct V_317 * V_318 ;
if ( ! V_295 || V_295 -> V_306 != & V_319 )
return - V_307 ;
if ( F_104 ( V_295 -> V_298 ) ) {
V_297 = V_295 -> V_298 ;
V_3 = V_297 -> V_3 ;
} else {
V_3 = F_98 ( V_295 -> V_320 ) ;
if ( ! V_3 )
return - V_307 ;
V_297 = F_69 ( sizeof( * V_297 ) , V_196 ) ;
if ( ! V_297 )
return - V_198 ;
V_297 -> V_3 = V_3 ;
V_295 -> V_298 = V_297 ;
}
for ( V_12 = 0 ; V_12 < V_295 -> V_299 ; V_12 ++ ) {
T_2 V_50 = V_295 -> V_300 [ V_12 ] ;
if ( ! F_102 ( V_3 , V_50 ) )
return - V_321 ;
if ( V_3 -> V_106 & V_293 ) {
V_23 = F_51 ( V_3 , V_50 ) ;
if ( V_23 )
return V_23 ;
}
}
V_318 = F_105 ( V_13 ) ;
if ( ! F_106 ( V_318 ) ) {
F_107 ( V_318 ) ;
F_108 ( & V_3 -> V_322 , V_13 ) ;
}
return F_109 ( V_318 ) ;
}
static void F_110 ( struct V_301 * V_13 )
{
struct V_294 * V_295 = V_13 -> V_294 ;
struct V_296 * V_297 ;
struct V_2 * V_3 ;
if ( ! V_295 || V_295 -> V_306 != & V_319 )
return;
V_297 = V_295 -> V_298 ;
V_3 = V_297 -> V_3 ;
if ( V_297 && V_297 -> V_145 . V_156 )
F_89 ( V_13 ) ;
F_111 ( V_13 ) ;
F_112 ( & V_3 -> V_322 , V_13 ) ;
F_71 ( V_297 ) ;
F_113 ( V_13 ) ;
}
static struct V_317 * F_114 ( struct V_301 * V_13 )
{
struct V_317 * V_318 ;
if ( F_115 ( V_13 ) )
V_318 = F_116 ( V_13 ) ;
else
V_318 = F_117 ( V_13 ) ;
return V_318 ;
}
static int F_118 ( struct V_9 * V_11 ,
enum V_323 V_324 , void * V_310 )
{
struct V_8 * V_243 = F_2 ( V_11 ) ;
if ( V_11 -> type != V_252 )
return - V_92 ;
switch ( V_324 ) {
case V_325 :
* ( int * ) V_310 = ( V_243 -> V_244 == V_280 ) ;
return 0 ;
default:
return - V_307 ;
}
}
static int F_119 ( struct V_9 * V_11 ,
enum V_323 V_324 , void * V_310 )
{
int V_23 = 0 ;
struct V_8 * V_243 = F_2 ( V_11 ) ;
if ( V_11 -> type != V_252 )
return - V_92 ;
F_91 ( & V_243 -> V_255 ) ;
switch ( V_324 ) {
case V_325 :
if ( V_243 -> V_3 ) {
V_23 = - V_326 ;
goto V_302;
}
if ( * ( int * ) V_310 )
V_243 -> V_244 = V_280 ;
else
V_243 -> V_244 = V_245 ;
break;
default:
V_23 = - V_307 ;
}
V_302:
F_93 ( & V_243 -> V_255 ) ;
return V_23 ;
}
static int F_120 ( struct V_301 * V_13 , struct V_327 * args )
{
return F_121 ( V_13 , args -> args , 1 ) ;
}
static void F_122 ( struct V_301 * V_13 ,
struct V_328 * V_329 )
{
struct V_330 * V_331 ;
int V_305 = V_332 | V_333 | V_334 ;
V_331 = F_123 ( V_335 , V_336 ,
V_305 , V_337 ) ;
if ( ! V_331 )
return;
F_124 ( & V_331 -> V_338 , V_329 ) ;
F_125 ( V_13 , V_329 ) ;
}
static void F_126 ( struct V_301 * V_13 ,
struct V_328 * V_329 )
{
struct V_330 * V_339 , * V_340 ;
F_127 (entry, next, head, list)
F_71 ( V_339 ) ;
}
static int F_128 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
unsigned long V_341 ,
unsigned long V_342 ,
T_6 V_343 )
{
T_6 V_344 = ( ( 1 << V_19 -> V_345 ) * V_343 ) << 3 ;
V_19 -> V_7 = F_53 ( V_3 -> V_13 , V_344 , & V_19 -> V_346 , V_196 ) ;
if ( ! V_19 -> V_7 ) {
F_33 ( V_3 -> V_13 , L_36 ,
V_344 ) ;
return - V_198 ;
}
V_19 -> V_24 = F_1 ( V_341 , V_3 ) ;
V_19 -> V_22 = F_1 ( V_342 , V_3 ) ;
V_19 -> V_38 = V_343 ;
V_19 -> V_347 = V_348 ;
V_19 -> V_347 |= V_19 -> V_346 & V_349 << V_350 ;
V_19 -> V_347 |= ( V_19 -> V_345 & V_351 )
<< V_352 ;
V_19 -> V_20 = V_19 -> V_21 = 0 ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 )
{
int V_23 ;
F_130 ( & V_3 -> V_100 . V_108 ) ;
V_23 = F_128 ( V_3 , & V_3 -> V_100 . V_19 , V_353 ,
V_354 , V_42 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_128 ( V_3 , & V_3 -> V_200 . V_19 , V_355 ,
V_356 , V_202 ) ;
if ( V_23 )
return V_23 ;
if ( ! ( V_3 -> V_106 & V_240 ) )
return 0 ;
return F_128 ( V_3 , & V_3 -> V_223 . V_19 , V_357 ,
V_358 , V_224 ) ;
}
static int F_131 ( struct V_2 * V_3 )
{
unsigned int V_12 ;
struct V_190 * V_121 = & V_3 -> V_191 ;
T_6 V_52 = sizeof( * V_121 -> V_192 ) * V_121 -> V_316 ;
void * V_187 = V_3 -> V_191 . V_187 ;
V_121 -> V_192 = F_132 ( V_3 -> V_13 , V_52 , V_196 ) ;
if ( ! V_121 -> V_192 ) {
F_33 ( V_3 -> V_13 , L_37 ) ;
return - V_198 ;
}
for ( V_12 = 0 ; V_12 < V_121 -> V_316 ; ++ V_12 ) {
F_44 ( V_187 , & V_121 -> V_192 [ V_12 ] ) ;
V_187 += V_195 << 3 ;
}
return 0 ;
}
static int F_133 ( struct V_2 * V_3 )
{
void * V_187 ;
T_5 V_359 ;
T_2 V_52 , V_360 ;
struct V_190 * V_121 = & V_3 -> V_191 ;
V_52 = V_361 - ( F_52 ( V_195 ) + 3 ) ;
V_52 = F_134 ( V_52 , V_3 -> V_362 - V_193 ) ;
V_121 -> V_316 = 1 << V_52 ;
V_52 += V_193 ;
if ( V_52 < V_3 -> V_362 )
F_36 ( V_3 -> V_13 ,
L_38 ,
V_52 , V_3 -> V_362 ) ;
V_360 = V_121 -> V_316 * ( V_195 << 3 ) ;
V_187 = F_53 ( V_3 -> V_13 , V_360 , & V_121 -> V_363 ,
V_196 | V_197 ) ;
if ( ! V_187 ) {
F_33 ( V_3 -> V_13 ,
L_39 ,
V_52 ) ;
return - V_198 ;
}
V_121 -> V_187 = V_187 ;
V_359 = V_364 ;
V_359 |= ( V_52 & V_365 )
<< V_366 ;
V_359 |= ( V_193 & V_367 )
<< V_368 ;
V_121 -> V_369 = V_359 ;
return F_131 ( V_3 ) ;
}
static int F_135 ( struct V_2 * V_3 )
{
void * V_187 ;
T_5 V_359 ;
T_2 V_52 ;
struct V_190 * V_121 = & V_3 -> V_191 ;
V_52 = ( 1 << V_3 -> V_362 ) * ( V_189 << 3 ) ;
V_187 = F_53 ( V_3 -> V_13 , V_52 , & V_121 -> V_363 ,
V_196 | V_197 ) ;
if ( ! V_187 ) {
F_33 ( V_3 -> V_13 ,
L_40 ,
V_52 ) ;
return - V_198 ;
}
V_121 -> V_187 = V_187 ;
V_121 -> V_316 = 1 << V_3 -> V_362 ;
V_359 = V_370 ;
V_359 |= ( V_3 -> V_362 & V_365 )
<< V_366 ;
V_121 -> V_369 = V_359 ;
F_50 ( V_187 , V_121 -> V_316 ) ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 )
{
T_5 V_359 ;
int V_23 ;
if ( V_3 -> V_106 & V_293 )
V_23 = F_133 ( V_3 ) ;
else
V_23 = F_135 ( V_3 ) ;
if ( V_23 )
return V_23 ;
V_359 = V_3 -> V_191 . V_363 &
V_371 << V_372 ;
V_359 |= V_373 ;
V_3 -> V_191 . V_374 = V_359 ;
F_137 ( 0 , V_3 -> V_261 ) ;
return 0 ;
}
static int F_138 ( struct V_2 * V_3 )
{
int V_23 ;
V_23 = F_129 ( V_3 ) ;
if ( V_23 )
return V_23 ;
return F_136 ( V_3 ) ;
}
static int F_139 ( struct V_2 * V_3 , T_2 V_110 ,
unsigned int V_375 , unsigned int V_376 )
{
T_2 V_359 ;
F_140 ( V_110 , V_3 -> V_7 + V_375 ) ;
return F_141 ( V_3 -> V_7 + V_376 , V_359 , V_359 == V_110 ,
1 , V_31 ) ;
}
static int F_142 ( struct V_2 * V_3 , T_2 V_377 , T_2 V_378 )
{
int V_23 ;
T_2 V_359 , T_1 * V_379 = V_3 -> V_7 + V_380 ;
V_23 = F_141 ( V_379 , V_359 , ! ( V_359 & V_381 ) ,
1 , V_31 ) ;
if ( V_23 )
return V_23 ;
V_359 &= ~ V_378 ;
V_359 |= V_377 ;
F_140 ( V_359 | V_381 , V_379 ) ;
return F_141 ( V_379 , V_359 , ! ( V_359 & V_381 ) ,
1 , V_31 ) ;
}
static void F_143 ( void * V_310 )
{
struct V_301 * V_13 = V_310 ;
F_144 ( V_13 ) ;
}
static void F_145 ( struct V_382 * V_137 , struct V_383 * V_384 )
{
T_10 V_385 ;
struct V_301 * V_13 = F_146 ( V_137 ) ;
struct V_2 * V_3 = F_101 ( V_13 ) ;
T_10 * V_121 = V_386 [ V_137 -> V_387 . V_388 ] ;
V_385 = ( ( ( T_5 ) V_384 -> V_389 ) << 32 ) | V_384 -> V_390 ;
V_385 &= V_391 << V_392 ;
F_147 ( V_385 , V_3 -> V_7 + V_121 [ 0 ] ) ;
F_140 ( V_384 -> V_310 , V_3 -> V_7 + V_121 [ 1 ] ) ;
F_140 ( V_393 , V_3 -> V_7 + V_121 [ 2 ] ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
struct V_382 * V_137 ;
int V_23 , V_394 = V_395 ;
struct V_301 * V_13 = V_3 -> V_13 ;
F_147 ( 0 , V_3 -> V_7 + V_396 ) ;
F_147 ( 0 , V_3 -> V_7 + V_397 ) ;
if ( V_3 -> V_106 & V_240 )
F_147 ( 0 , V_3 -> V_7 + V_398 ) ;
else
V_394 -- ;
if ( ! ( V_3 -> V_106 & V_399 ) )
return;
V_23 = F_149 ( V_13 , V_394 , F_145 ) ;
if ( V_23 ) {
F_36 ( V_13 , L_41 ) ;
return;
}
F_150 (desc, dev) {
switch ( V_137 -> V_387 . V_388 ) {
case V_400 :
V_3 -> V_200 . V_19 . V_199 = V_137 -> V_199 ;
break;
case V_401 :
V_3 -> V_402 = V_137 -> V_199 ;
break;
case V_403 :
V_3 -> V_223 . V_19 . V_199 = V_137 -> V_199 ;
break;
default:
continue;
}
}
F_151 ( V_13 , F_143 , V_13 ) ;
}
static void F_152 ( struct V_2 * V_3 )
{
int V_199 , V_23 ;
F_148 ( V_3 ) ;
V_199 = V_3 -> V_200 . V_19 . V_199 ;
if ( V_199 ) {
V_23 = F_153 ( V_3 -> V_13 , V_199 , NULL ,
F_54 ,
V_404 ,
L_42 , V_3 ) ;
if ( V_23 < 0 )
F_36 ( V_3 -> V_13 , L_43 ) ;
}
V_199 = V_3 -> V_100 . V_19 . V_199 ;
if ( V_199 ) {
V_23 = F_154 ( V_3 -> V_13 , V_199 ,
F_58 , 0 ,
L_44 , V_3 ) ;
if ( V_23 < 0 )
F_36 ( V_3 -> V_13 , L_45 ) ;
}
V_199 = V_3 -> V_402 ;
if ( V_199 ) {
V_23 = F_154 ( V_3 -> V_13 , V_199 , F_59 ,
0 , L_46 , V_3 ) ;
if ( V_23 < 0 )
F_36 ( V_3 -> V_13 , L_47 ) ;
}
if ( V_3 -> V_106 & V_240 ) {
V_199 = V_3 -> V_223 . V_19 . V_199 ;
if ( V_199 ) {
V_23 = F_153 ( V_3 -> V_13 , V_199 , NULL ,
F_57 ,
V_404 ,
L_48 ,
V_3 ) ;
if ( V_23 < 0 )
F_36 ( V_3 -> V_13 ,
L_49 ) ;
}
}
}
static int F_155 ( struct V_2 * V_3 )
{
int V_23 , V_199 ;
T_2 V_405 = V_406 | V_407 ;
V_23 = F_139 ( V_3 , 0 , V_408 ,
V_409 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_50 ) ;
return V_23 ;
}
V_199 = V_3 -> V_410 ;
if ( V_199 ) {
V_23 = F_153 ( V_3 -> V_13 , V_199 ,
F_62 ,
F_61 ,
V_404 ,
L_51 , V_3 ) ;
if ( V_23 < 0 )
F_36 ( V_3 -> V_13 , L_52 ) ;
} else
F_152 ( V_3 ) ;
if ( V_3 -> V_106 & V_240 )
V_405 |= V_411 ;
V_23 = F_139 ( V_3 , V_405 ,
V_408 , V_409 ) ;
if ( V_23 )
F_36 ( V_3 -> V_13 , L_53 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
int V_23 ;
V_23 = F_139 ( V_3 , 0 , V_412 , V_413 ) ;
if ( V_23 )
F_33 ( V_3 -> V_13 , L_54 ) ;
return V_23 ;
}
static int F_156 ( struct V_2 * V_3 , bool V_414 )
{
int V_23 ;
T_2 V_359 , V_415 ;
struct V_41 V_40 ;
V_359 = F_12 ( V_3 -> V_7 + V_412 ) ;
if ( V_359 & V_416 )
F_36 ( V_3 -> V_13 , L_55 ) ;
V_23 = F_60 ( V_3 ) ;
if ( V_23 )
return V_23 ;
V_359 = ( V_417 << V_418 ) |
( V_419 << V_420 ) |
( V_419 << V_421 ) |
( V_417 << V_422 ) |
( V_419 << V_423 ) |
( V_419 << V_424 ) ;
F_140 ( V_359 , V_3 -> V_7 + V_425 ) ;
V_359 = V_426 | V_427 | V_428 ;
F_140 ( V_359 , V_3 -> V_7 + V_429 ) ;
F_147 ( V_3 -> V_191 . V_374 ,
V_3 -> V_7 + V_430 ) ;
F_140 ( V_3 -> V_191 . V_369 ,
V_3 -> V_7 + V_431 ) ;
F_147 ( V_3 -> V_100 . V_19 . V_347 , V_3 -> V_7 + V_432 ) ;
F_140 ( V_3 -> V_100 . V_19 . V_20 , V_3 -> V_7 + V_353 ) ;
F_140 ( V_3 -> V_100 . V_19 . V_21 , V_3 -> V_7 + V_354 ) ;
V_415 = V_433 ;
V_23 = F_139 ( V_3 , V_415 , V_412 ,
V_413 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_56 ) ;
return V_23 ;
}
V_40 . V_43 = V_61 ;
F_35 ( V_3 , & V_40 ) ;
V_40 . V_43 = V_93 ;
F_35 ( V_3 , & V_40 ) ;
if ( V_3 -> V_106 & V_434 ) {
V_40 . V_43 = V_46 ;
F_35 ( V_3 , & V_40 ) ;
}
V_40 . V_43 = V_47 ;
F_35 ( V_3 , & V_40 ) ;
V_40 . V_43 = V_93 ;
F_35 ( V_3 , & V_40 ) ;
F_147 ( V_3 -> V_200 . V_19 . V_347 , V_3 -> V_7 + V_435 ) ;
F_140 ( V_3 -> V_200 . V_19 . V_20 ,
F_1 ( V_355 , V_3 ) ) ;
F_140 ( V_3 -> V_200 . V_19 . V_21 ,
F_1 ( V_356 , V_3 ) ) ;
V_415 |= V_436 ;
V_23 = F_139 ( V_3 , V_415 , V_412 ,
V_413 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_57 ) ;
return V_23 ;
}
if ( V_3 -> V_106 & V_240 ) {
F_147 ( V_3 -> V_223 . V_19 . V_347 ,
V_3 -> V_7 + V_437 ) ;
F_140 ( V_3 -> V_223 . V_19 . V_20 ,
F_1 ( V_357 , V_3 ) ) ;
F_140 ( V_3 -> V_223 . V_19 . V_21 ,
F_1 ( V_358 , V_3 ) ) ;
V_415 |= V_438 ;
V_23 = F_139 ( V_3 , V_415 , V_412 ,
V_413 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_58 ) ;
return V_23 ;
}
}
V_23 = F_155 ( V_3 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_59 ) ;
return V_23 ;
}
if ( ! V_414 || V_155 ) {
V_415 |= V_416 ;
} else {
V_23 = F_142 ( V_3 , 0 , V_439 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_60 ) ;
return V_23 ;
}
}
V_23 = F_139 ( V_3 , V_415 , V_412 ,
V_413 ) ;
if ( V_23 ) {
F_33 ( V_3 -> V_13 , L_61 ) ;
return V_23 ;
}
return 0 ;
}
static int F_157 ( struct V_2 * V_3 )
{
T_2 V_359 ;
bool V_440 = V_3 -> V_106 & V_286 ;
V_359 = F_12 ( V_3 -> V_7 + V_441 ) ;
if ( ( V_359 & V_442 << V_443 ) == V_444 )
V_3 -> V_106 |= V_293 ;
if ( V_359 & V_445 )
V_3 -> V_106 |= V_446 ;
switch ( V_359 & V_447 << V_448 ) {
case V_449 :
V_3 -> V_106 |= V_450 | V_451 ;
break;
#ifdef F_43
case V_452 :
V_3 -> V_106 |= V_451 ;
break;
#else
case V_453 :
V_3 -> V_106 |= V_450 ;
break;
#endif
default:
F_33 ( V_3 -> V_13 , L_62 ) ;
return - V_303 ;
}
if ( F_158 ( V_454 ) && V_359 & V_455 )
V_3 -> V_106 |= V_240 ;
if ( F_158 ( F_49 ) && V_359 & V_456 )
V_3 -> V_106 |= V_457 ;
if ( V_359 & V_458 )
V_3 -> V_106 |= V_107 ;
if ( V_359 & V_459 )
V_3 -> V_106 |= V_399 ;
if ( V_359 & V_460 )
V_3 -> V_106 |= V_434 ;
if ( ! ! ( V_359 & V_461 ) != V_440 )
F_36 ( V_3 -> V_13 , L_63 ,
V_440 ? L_64 : L_65 ) ;
switch ( V_359 & V_462 << V_463 ) {
case V_464 :
case V_465 :
V_3 -> V_106 |= V_170 ;
}
if ( V_359 & V_466 )
V_3 -> V_106 |= V_275 ;
if ( V_359 & V_467 )
V_3 -> V_106 |= V_277 ;
if ( ! ( V_359 & ( V_466 | V_467 ) ) ) {
F_33 ( V_3 -> V_13 , L_66 ) ;
return - V_303 ;
}
switch ( V_359 & V_468 << V_469 ) {
case V_470 :
V_3 -> V_269 = 40 ;
case V_471 :
break;
default:
F_33 ( V_3 -> V_13 , L_67 ) ;
return - V_303 ;
}
V_3 -> V_264 = V_359 & V_472 ? 16 : 8 ;
V_3 -> V_267 = V_359 & V_473 ? 16 : 8 ;
V_359 = F_12 ( V_3 -> V_7 + V_474 ) ;
if ( V_359 & ( V_475 | V_476 | V_477 ) ) {
F_33 ( V_3 -> V_13 , L_68 ) ;
return - V_303 ;
}
V_3 -> V_100 . V_19 . V_345 = F_134 ( ( T_2 ) V_478 ,
V_359 >> V_479 & V_480 ) ;
if ( ! V_3 -> V_100 . V_19 . V_345 ) {
F_33 ( V_3 -> V_13 , L_69 ) ;
return - V_303 ;
}
V_3 -> V_200 . V_19 . V_345 = F_134 ( ( T_2 ) V_481 ,
V_359 >> V_482 & V_483 ) ;
V_3 -> V_223 . V_19 . V_345 = F_134 ( ( T_2 ) V_484 ,
V_359 >> V_485 & V_486 ) ;
V_3 -> V_487 = V_359 >> V_488 & V_489 ;
V_3 -> V_362 = V_359 >> V_490 & V_491 ;
if ( V_3 -> V_362 <= V_193 )
V_3 -> V_106 &= ~ V_293 ;
V_359 = F_12 ( V_3 -> V_7 + V_492 ) ;
V_3 -> V_200 . V_493 = V_359 >> V_494
& V_495 ;
if ( V_359 & V_496 )
V_3 -> V_282 |= V_4 | V_497 ;
if ( V_359 & V_498 )
V_3 -> V_282 |= V_499 | V_500 ;
if ( V_359 & V_501 )
V_3 -> V_282 |= V_502 | V_503 | V_504 ;
if ( V_319 . V_282 == - 1UL )
V_319 . V_282 = V_3 -> V_282 ;
else
V_319 . V_282 |= V_3 -> V_282 ;
switch ( V_359 & V_505 << V_506 ) {
case V_507 :
V_3 -> V_270 = 32 ;
break;
case V_508 :
V_3 -> V_270 = 36 ;
break;
case V_509 :
V_3 -> V_270 = 40 ;
break;
case V_510 :
V_3 -> V_270 = 42 ;
break;
case V_511 :
V_3 -> V_270 = 44 ;
break;
default:
F_55 ( V_3 -> V_13 ,
L_70 ) ;
case V_512 :
V_3 -> V_270 = 48 ;
}
if ( F_159 ( V_3 -> V_13 , F_160 ( V_3 -> V_270 ) ) )
F_36 ( V_3 -> V_13 ,
L_71 ) ;
V_3 -> V_269 = F_161 ( V_3 -> V_269 , V_3 -> V_270 ) ;
F_55 ( V_3 -> V_13 , L_72 ,
V_3 -> V_269 , V_3 -> V_270 , V_3 -> V_106 ) ;
return 0 ;
}
static void F_162 ( T_2 V_513 , struct V_2 * V_3 )
{
switch ( V_513 ) {
case V_514 :
V_3 -> V_5 |= V_6 ;
break;
case V_515 :
V_3 -> V_5 |= V_186 ;
break;
}
F_6 ( V_3 -> V_13 , L_73 , V_3 -> V_5 ) ;
}
static int F_163 ( struct V_516 * V_517 ,
struct V_2 * V_3 )
{
struct V_518 * V_519 ;
struct V_301 * V_13 = V_3 -> V_13 ;
struct V_520 * V_521 ;
V_521 = * (struct V_520 * * ) F_164 ( V_13 ) ;
V_519 = (struct V_518 * ) V_521 -> V_522 ;
F_162 ( V_519 -> V_513 , V_3 ) ;
if ( V_519 -> V_105 & V_523 )
V_3 -> V_106 |= V_286 ;
return 0 ;
}
static inline int F_163 ( struct V_516 * V_517 ,
struct V_2 * V_3 )
{
return - V_307 ;
}
static int F_165 ( struct V_516 * V_517 ,
struct V_2 * V_3 )
{
struct V_301 * V_13 = & V_517 -> V_13 ;
T_2 V_524 ;
int V_23 = - V_92 ;
if ( F_166 ( V_13 -> V_14 , L_74 , & V_524 ) )
F_33 ( V_13 , L_75 ) ;
else if ( V_524 != 1 )
F_33 ( V_13 , L_76 , V_524 ) ;
else
V_23 = 0 ;
F_4 ( V_3 ) ;
if ( F_167 ( V_13 -> V_14 ) )
V_3 -> V_106 |= V_286 ;
return V_23 ;
}
static unsigned long F_168 ( struct V_2 * V_3 )
{
if ( V_3 -> V_5 & V_6 )
return V_4 ;
else
return V_525 ;
}
static int F_169 ( struct V_516 * V_517 )
{
int V_199 , V_23 ;
struct V_526 * V_527 ;
T_12 V_528 ;
struct V_2 * V_3 ;
struct V_301 * V_13 = & V_517 -> V_13 ;
bool V_414 ;
V_3 = F_132 ( V_13 , sizeof( * V_3 ) , V_196 ) ;
if ( ! V_3 ) {
F_33 ( V_13 , L_77 ) ;
return - V_198 ;
}
V_3 -> V_13 = V_13 ;
if ( V_13 -> V_14 ) {
V_23 = F_165 ( V_517 , V_3 ) ;
} else {
V_23 = F_163 ( V_517 , V_3 ) ;
if ( V_23 == - V_307 )
return V_23 ;
}
V_414 = ! ! V_23 ;
V_527 = F_170 ( V_517 , V_529 , 0 ) ;
if ( F_171 ( V_527 ) + 1 < F_168 ( V_3 ) ) {
F_33 ( V_13 , L_78 , V_527 ) ;
return - V_92 ;
}
V_528 = V_527 -> V_530 ;
V_3 -> V_7 = F_172 ( V_13 , V_527 ) ;
if ( F_106 ( V_3 -> V_7 ) )
return F_173 ( V_3 -> V_7 ) ;
V_199 = F_174 ( V_517 , L_79 ) ;
if ( V_199 > 0 )
V_3 -> V_410 = V_199 ;
else {
V_199 = F_174 ( V_517 , L_80 ) ;
if ( V_199 > 0 )
V_3 -> V_200 . V_19 . V_199 = V_199 ;
V_199 = F_174 ( V_517 , L_81 ) ;
if ( V_199 > 0 )
V_3 -> V_223 . V_19 . V_199 = V_199 ;
V_199 = F_174 ( V_517 , L_82 ) ;
if ( V_199 > 0 )
V_3 -> V_100 . V_19 . V_199 = V_199 ;
V_199 = F_174 ( V_517 , L_83 ) ;
if ( V_199 > 0 )
V_3 -> V_402 = V_199 ;
}
V_23 = F_157 ( V_3 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_138 ( V_3 ) ;
if ( V_23 )
return V_23 ;
F_175 ( V_517 , V_3 ) ;
V_23 = F_156 ( V_3 , V_414 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_176 ( & V_3 -> V_322 , V_13 , NULL ,
L_84 , & V_528 ) ;
if ( V_23 )
return V_23 ;
F_177 ( & V_3 -> V_322 , & V_319 ) ;
F_178 ( & V_3 -> V_322 , V_13 -> V_311 ) ;
V_23 = F_179 ( & V_3 -> V_322 ) ;
if ( V_23 ) {
F_33 ( V_13 , L_85 ) ;
return V_23 ;
}
#ifdef F_180
if ( V_531 . V_532 != & V_319 ) {
F_181 () ;
V_23 = F_182 ( & V_531 , & V_319 ) ;
if ( V_23 )
return V_23 ;
}
#endif
#ifdef F_183
if ( V_533 . V_532 != & V_319 ) {
V_23 = F_182 ( & V_533 , & V_319 ) ;
if ( V_23 )
return V_23 ;
}
#endif
if ( V_534 . V_532 != & V_319 ) {
V_23 = F_182 ( & V_534 , & V_319 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_184 ( struct V_516 * V_517 )
{
struct V_2 * V_3 = F_185 ( V_517 ) ;
F_60 ( V_3 ) ;
return 0 ;
}
