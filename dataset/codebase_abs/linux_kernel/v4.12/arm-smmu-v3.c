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
V_104 = V_142 ;
if ( ! V_139 -> V_150 || ! ( V_139 -> V_151 || V_139 -> V_152 ) ) {
if ( ! V_139 -> V_150 && V_149 )
V_104 |= V_148 ;
else
V_104 |= V_145 ;
V_27 [ 0 ] = F_24 ( V_104 ) ;
V_27 [ 1 ] = F_24 ( V_153
<< V_154 ) ;
V_27 [ 2 ] = 0 ;
if ( V_140 )
F_44 ( V_6 , V_44 ) ;
return;
}
if ( V_139 -> V_151 ) {
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
V_104 |= ( V_139 -> V_151 -> V_166 & V_167
<< V_168 ) |
V_146 ;
}
if ( V_139 -> V_152 ) {
F_47 ( V_140 ) ;
V_27 [ 2 ] = F_24 (
V_139 -> V_152 -> V_65 << V_169 |
( V_139 -> V_152 -> V_170 & V_171 )
<< V_172 |
#ifdef F_42
V_173 |
#endif
V_174 | V_175 |
V_176 ) ;
V_27 [ 3 ] = F_24 ( V_139 -> V_152 -> V_177 &
V_178 << V_179 ) ;
V_104 |= V_147 ;
}
F_44 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_24 ( V_104 ) ;
F_44 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_180 ) )
F_34 ( V_6 , & V_141 ) ;
}
static void F_49 ( T_4 * V_181 , unsigned int V_182 )
{
unsigned int V_7 ;
struct V_138 V_139 = { . V_150 = false } ;
for ( V_7 = 0 ; V_7 < V_182 ; ++ V_7 ) {
F_45 ( NULL , - 1 , V_181 , & V_139 ) ;
V_181 += V_183 ;
}
}
static int F_50 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_181 ;
struct V_184 * V_115 = & V_6 -> V_185 ;
struct V_130 * V_131 = & V_115 -> V_186 [ V_44 >> V_187 ] ;
if ( V_131 -> V_188 )
return 0 ;
V_46 = 1 << ( V_187 + F_51 ( V_183 ) + 3 ) ;
V_181 = & V_115 -> V_181 [ ( V_44 >> V_187 ) * V_189 ] ;
V_131 -> V_132 = V_187 + 1 ;
V_131 -> V_188 = F_52 ( V_6 -> V_8 , V_46 , & V_131 -> V_135 ,
V_190 | V_191 ) ;
if ( ! V_131 -> V_188 ) {
F_32 ( V_6 -> V_8 ,
L_14 ,
V_44 ) ;
return - V_192 ;
}
F_49 ( V_131 -> V_188 , 1 << V_187 ) ;
F_43 ( V_181 , V_131 ) ;
return 0 ;
}
static T_6 F_53 ( int V_193 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_194 . V_15 ;
T_4 V_195 [ V_196 ] ;
do {
while ( ! F_29 ( V_15 , V_195 ) ) {
T_7 V_197 = V_195 [ 0 ] >> V_198 & V_199 ;
F_54 ( V_6 -> V_8 , L_15 , V_197 ) ;
for ( V_7 = 0 ; V_7 < F_33 ( V_195 ) ; ++ V_7 )
F_54 ( V_6 -> V_8 , L_9 ,
( unsigned long long ) V_195 [ V_7 ] ) ;
}
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_16 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_200 ;
}
static void F_55 ( struct V_5 * V_6 , T_4 * V_195 )
{
T_1 V_44 , V_74 ;
T_8 V_77 ;
bool V_201 , V_202 ;
V_44 = V_195 [ 0 ] >> V_203 & V_204 ;
V_201 = V_195 [ 0 ] & V_205 ;
V_74 = V_201 ? V_195 [ 0 ] >> V_206 & V_207 : 0 ;
V_202 = V_195 [ 0 ] & V_208 ;
V_77 = V_195 [ 1 ] >> V_209 & V_210 ;
F_54 ( V_6 -> V_8 , L_17 ) ;
F_54 ( V_6 -> V_8 ,
L_18 ,
V_44 , V_74 , V_77 , V_202 ? L_19 : L_20 ,
V_195 [ 0 ] & V_211 ? L_20 : L_21 ,
V_195 [ 0 ] & V_212 ? L_22 : L_20 ,
V_195 [ 0 ] & V_213 ? L_23 : L_20 ,
V_195 [ 0 ] & V_214 ? L_24 : L_20 ,
V_195 [ 1 ] & V_215 << V_216 ) ;
if ( V_202 ) {
struct V_35 V_34 = {
. V_37 = V_70 ,
. V_71 = V_201 ,
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
static T_6 F_56 ( int V_193 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_217 . V_15 ;
T_4 V_195 [ V_218 ] ;
do {
while ( ! F_29 ( V_15 , V_195 ) )
F_55 ( V_6 , V_195 ) ;
if ( F_15 ( V_15 ) == - V_21 )
F_32 ( V_6 -> V_8 , L_25 ) ;
} while ( ! F_9 ( V_15 ) );
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_200 ;
}
static T_6 F_57 ( int V_193 , void * V_8 )
{
return V_200 ;
}
static T_6 F_58 ( int V_193 , void * V_8 )
{
T_1 V_219 , V_220 , V_221 ;
struct V_5 * V_6 = V_8 ;
V_219 = F_11 ( V_6 -> V_222 + V_223 ) ;
V_220 = F_11 ( V_6 -> V_222 + V_224 ) ;
V_221 = V_219 ^ V_220 ;
if ( ! ( V_221 & V_225 ) )
return V_226 ;
F_35 ( V_6 -> V_8 ,
L_26 ,
V_221 ) ;
if ( V_221 & V_227 ) {
F_32 ( V_6 -> V_8 , L_27 ) ;
F_59 ( V_6 ) ;
}
if ( V_221 & V_228 )
F_35 ( V_6 -> V_8 , L_28 ) ;
if ( V_221 & V_229 )
F_35 ( V_6 -> V_8 , L_29 ) ;
if ( V_221 & V_230 )
F_35 ( V_6 -> V_8 , L_30 ) ;
if ( V_221 & V_231 ) {
F_35 ( V_6 -> V_8 , L_31 ) ;
F_57 ( V_193 , V_6 -> V_8 ) ;
}
if ( V_221 & V_232 )
F_32 ( V_6 -> V_8 , L_32 ) ;
if ( V_221 & V_233 )
F_32 ( V_6 -> V_8 , L_33 ) ;
if ( V_221 & V_234 )
F_31 ( V_6 ) ;
F_14 ( V_219 , V_6 -> V_222 + V_224 ) ;
return V_200 ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
}
static void F_61 ( void * V_235 )
{
struct V_1 * V_236 = V_235 ;
F_60 ( V_236 -> V_6 ) ;
}
static void F_62 ( void * V_235 )
{
struct V_1 * V_236 = V_235 ;
struct V_5 * V_6 = V_236 -> V_6 ;
struct V_35 V_34 ;
if ( V_236 -> V_237 == V_238 ) {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_60 = V_236 -> V_151 . V_116 . V_60 ;
V_34 . V_59 . V_65 = 0 ;
} else {
V_34 . V_37 = V_69 ;
V_34 . V_59 . V_65 = V_236 -> V_152 . V_65 ;
}
F_34 ( V_6 , & V_34 ) ;
F_60 ( V_6 ) ;
}
static void F_63 ( unsigned long V_239 , T_5 V_46 ,
T_5 V_240 , bool V_53 , void * V_235 )
{
struct V_1 * V_236 = V_235 ;
struct V_5 * V_6 = V_236 -> V_6 ;
struct V_35 V_34 = {
. V_59 = {
. V_53 = V_53 ,
. V_48 = V_239 ,
} ,
} ;
if ( V_236 -> V_237 == V_238 ) {
V_34 . V_37 = V_58 ;
V_34 . V_59 . V_60 = V_236 -> V_151 . V_116 . V_60 ;
} else {
V_34 . V_37 = V_64 ;
V_34 . V_59 . V_65 = V_236 -> V_152 . V_65 ;
}
do {
F_34 ( V_6 , & V_34 ) ;
V_34 . V_59 . V_48 += V_240 ;
} while ( V_46 -= V_240 );
}
static bool F_64 ( enum V_241 V_242 )
{
switch ( V_242 ) {
case V_243 :
return true ;
case V_244 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_65 ( unsigned type )
{
struct V_1 * V_236 ;
if ( type != V_245 &&
type != V_246 &&
type != V_247 )
return NULL ;
V_236 = F_66 ( sizeof( * V_236 ) , V_190 ) ;
if ( ! V_236 )
return NULL ;
if ( type == V_246 &&
F_67 ( & V_236 -> V_4 ) ) {
F_68 ( V_236 ) ;
return NULL ;
}
F_69 ( & V_236 -> V_248 ) ;
F_70 ( & V_236 -> V_249 ) ;
return & V_236 -> V_4 ;
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
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_236 -> V_6 ;
F_77 ( V_4 ) ;
F_78 ( V_236 -> V_251 ) ;
if ( V_236 -> V_237 == V_238 ) {
struct V_114 * V_115 = & V_236 -> V_151 ;
if ( V_115 -> V_124 ) {
F_79 ( V_236 -> V_6 -> V_8 ,
V_252 << 3 ,
V_115 -> V_124 ,
V_115 -> V_166 ) ;
F_74 ( V_6 -> V_253 , V_115 -> V_116 . V_60 ) ;
}
} else {
struct V_254 * V_115 = & V_236 -> V_152 ;
if ( V_115 -> V_65 )
F_74 ( V_6 -> V_255 , V_115 -> V_65 ) ;
}
F_68 ( V_236 ) ;
}
static int F_80 ( struct V_1 * V_236 ,
struct V_256 * V_257 )
{
int V_19 ;
int V_60 ;
struct V_5 * V_6 = V_236 -> V_6 ;
struct V_114 * V_115 = & V_236 -> V_151 ;
V_60 = F_71 ( V_6 -> V_253 , V_6 -> V_258 ) ;
if ( V_60 < 0 )
return V_60 ;
V_115 -> V_124 = F_52 ( V_6 -> V_8 , V_252 << 3 ,
& V_115 -> V_166 ,
V_190 | V_191 ) ;
if ( ! V_115 -> V_124 ) {
F_35 ( V_6 -> V_8 , L_34 ) ;
V_19 = - V_192 ;
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
static int F_81 ( struct V_1 * V_236 ,
struct V_256 * V_257 )
{
int V_65 ;
struct V_5 * V_6 = V_236 -> V_6 ;
struct V_254 * V_115 = & V_236 -> V_152 ;
V_65 = F_71 ( V_6 -> V_255 , V_6 -> V_261 ) ;
if ( V_65 < 0 )
return V_65 ;
V_115 -> V_65 = ( T_8 ) V_65 ;
V_115 -> V_177 = V_257 -> V_262 . V_177 ;
V_115 -> V_170 = V_257 -> V_262 . V_170 ;
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
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_236 -> V_6 ;
if ( V_4 -> type == V_247 ) {
V_236 -> V_237 = V_268 ;
return 0 ;
}
if ( ! ( V_6 -> V_100 & V_269 ) )
V_236 -> V_237 = V_270 ;
if ( ! ( V_6 -> V_100 & V_271 ) )
V_236 -> V_237 = V_238 ;
switch ( V_236 -> V_237 ) {
case V_238 :
V_263 = V_272 ;
V_264 = V_6 -> V_263 ;
V_266 = V_273 ;
F_83 = F_80 ;
break;
case V_274 :
case V_270 :
V_263 = V_6 -> V_263 ;
V_264 = V_6 -> V_264 ;
V_266 = V_275 ;
F_83 = F_81 ;
break;
default:
return - V_86 ;
}
V_257 = (struct V_256 ) {
. V_276 = V_6 -> V_276 ,
. V_263 = V_263 ,
. V_264 = V_264 ,
. V_277 = & V_278 ,
. V_279 = V_6 -> V_8 ,
} ;
V_251 = F_84 ( V_266 , & V_257 , V_236 ) ;
if ( ! V_251 )
return - V_192 ;
V_4 -> V_276 = V_257 . V_276 ;
V_4 -> V_280 . V_281 = ( 1UL << V_263 ) - 1 ;
V_4 -> V_280 . V_282 = true ;
V_236 -> V_251 = V_251 ;
V_19 = F_83 ( V_236 , & V_257 ) ;
if ( V_19 < 0 )
F_78 ( V_251 ) ;
return V_19 ;
}
static T_3 * F_85 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_283 ;
struct V_184 * V_115 = & V_6 -> V_185 ;
if ( V_6 -> V_100 & V_284 ) {
struct V_130 * V_186 ;
int V_95 ;
V_95 = ( V_44 >> V_187 ) * V_189 ;
V_186 = & V_115 -> V_186 [ V_95 ] ;
V_95 = ( V_44 & ( ( 1 << V_187 ) - 1 ) ) * V_183 ;
V_283 = & V_186 -> V_188 [ V_95 ] ;
} else {
V_283 = & V_115 -> V_181 [ V_44 * V_183 ] ;
}
return V_283 ;
}
static void F_86 ( struct V_285 * V_286 )
{
int V_7 ;
struct V_287 * V_288 = V_286 -> V_289 ;
struct V_5 * V_6 = V_288 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_286 -> V_290 ; ++ V_7 ) {
T_1 V_44 = V_286 -> V_291 [ V_7 ] ;
T_3 * V_283 = F_85 ( V_6 , V_44 ) ;
F_45 ( V_6 , V_44 , V_283 , & V_288 -> V_139 ) ;
}
}
static void F_87 ( struct V_292 * V_8 )
{
struct V_287 * V_288 = V_8 -> V_285 -> V_289 ;
V_288 -> V_139 . V_150 = false ;
F_86 ( V_8 -> V_285 ) ;
}
static int F_88 ( struct V_2 * V_4 , struct V_292 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_287 * V_288 ;
struct V_138 * V_139 ;
if ( ! V_8 -> V_285 )
return - V_89 ;
V_288 = V_8 -> V_285 -> V_289 ;
V_6 = V_288 -> V_6 ;
V_139 = & V_288 -> V_139 ;
if ( V_139 -> V_150 )
F_87 ( V_8 ) ;
F_89 ( & V_236 -> V_248 ) ;
if ( ! V_236 -> V_6 ) {
V_236 -> V_6 = V_6 ;
V_19 = F_82 ( V_4 ) ;
if ( V_19 ) {
V_236 -> V_6 = NULL ;
goto V_293;
}
} else if ( V_236 -> V_6 != V_6 ) {
F_32 ( V_8 ,
L_35 ,
F_90 ( V_236 -> V_6 -> V_8 ) ,
F_90 ( V_6 -> V_8 ) ) ;
V_19 = - V_294 ;
goto V_293;
}
V_139 -> V_150 = true ;
if ( V_236 -> V_237 == V_268 ) {
V_139 -> V_151 = NULL ;
V_139 -> V_152 = NULL ;
} else if ( V_236 -> V_237 == V_238 ) {
V_139 -> V_151 = & V_236 -> V_151 ;
V_139 -> V_152 = NULL ;
F_41 ( V_6 , V_139 -> V_151 ) ;
} else {
V_139 -> V_151 = NULL ;
V_139 -> V_152 = & V_236 -> V_152 ;
}
F_86 ( V_8 -> V_285 ) ;
V_293:
F_91 ( & V_236 -> V_248 ) ;
return V_19 ;
}
static int F_92 ( struct V_2 * V_4 , unsigned long V_239 ,
T_9 V_295 , T_5 V_46 , int V_296 )
{
int V_19 ;
unsigned long V_99 ;
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_267 * V_297 = V_236 -> V_251 ;
if ( ! V_297 )
return - V_298 ;
F_36 ( & V_236 -> V_249 , V_99 ) ;
V_19 = V_297 -> V_250 ( V_297 , V_239 , V_295 , V_46 , V_296 ) ;
F_38 ( & V_236 -> V_249 , V_99 ) ;
return V_19 ;
}
static T_5
F_93 ( struct V_2 * V_4 , unsigned long V_239 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_99 ;
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_267 * V_297 = V_236 -> V_251 ;
if ( ! V_297 )
return 0 ;
F_36 ( & V_236 -> V_249 , V_99 ) ;
V_19 = V_297 -> V_299 ( V_297 , V_239 , V_46 ) ;
F_38 ( & V_236 -> V_249 , V_99 ) ;
return V_19 ;
}
static T_9
F_94 ( struct V_2 * V_4 , T_10 V_239 )
{
T_9 V_19 ;
unsigned long V_99 ;
struct V_1 * V_236 = F_1 ( V_4 ) ;
struct V_267 * V_297 = V_236 -> V_251 ;
if ( V_4 -> type == V_247 )
return V_239 ;
if ( ! V_297 )
return 0 ;
F_36 ( & V_236 -> V_249 , V_99 ) ;
V_19 = V_297 -> V_300 ( V_297 , V_239 ) ;
F_38 ( & V_236 -> V_249 , V_99 ) ;
return V_19 ;
}
static int F_95 ( struct V_292 * V_8 , void * V_301 )
{
return V_8 -> V_302 == V_301 ;
}
static
struct V_5 * F_96 ( struct V_303 * V_302 )
{
struct V_292 * V_8 = F_97 ( & V_304 . V_305 , NULL ,
V_302 , F_95 ) ;
F_98 ( V_8 ) ;
return V_8 ? F_99 ( V_8 ) : NULL ;
}
static bool F_100 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_306 = V_6 -> V_185 . V_307 ;
if ( V_6 -> V_100 & V_284 )
V_306 *= 1UL << V_187 ;
return V_44 < V_306 ;
}
static int F_101 ( struct V_292 * V_8 )
{
int V_7 , V_19 ;
struct V_5 * V_6 ;
struct V_287 * V_288 ;
struct V_285 * V_286 = V_8 -> V_285 ;
struct V_308 * V_309 ;
if ( ! V_286 || V_286 -> V_297 != & V_310 )
return - V_298 ;
if ( F_102 ( V_286 -> V_289 ) ) {
V_288 = V_286 -> V_289 ;
V_6 = V_288 -> V_6 ;
} else {
V_6 = F_96 ( V_286 -> V_311 ) ;
if ( ! V_6 )
return - V_298 ;
V_288 = F_66 ( sizeof( * V_288 ) , V_190 ) ;
if ( ! V_288 )
return - V_192 ;
V_288 -> V_6 = V_6 ;
V_286 -> V_289 = V_288 ;
}
for ( V_7 = 0 ; V_7 < V_286 -> V_290 ; V_7 ++ ) {
T_1 V_44 = V_286 -> V_291 [ V_7 ] ;
if ( ! F_100 ( V_6 , V_44 ) )
return - V_312 ;
if ( V_6 -> V_100 & V_284 ) {
V_19 = F_50 ( V_6 , V_44 ) ;
if ( V_19 )
return V_19 ;
}
}
V_309 = F_103 ( V_8 ) ;
if ( ! F_104 ( V_309 ) ) {
F_105 ( V_309 ) ;
F_106 ( & V_6 -> V_313 , V_8 ) ;
}
return F_107 ( V_309 ) ;
}
static void F_108 ( struct V_292 * V_8 )
{
struct V_285 * V_286 = V_8 -> V_285 ;
struct V_287 * V_288 ;
struct V_5 * V_6 ;
if ( ! V_286 || V_286 -> V_297 != & V_310 )
return;
V_288 = V_286 -> V_289 ;
V_6 = V_288 -> V_6 ;
if ( V_288 && V_288 -> V_139 . V_150 )
F_87 ( V_8 ) ;
F_109 ( V_8 ) ;
F_110 ( & V_6 -> V_313 , V_8 ) ;
F_68 ( V_288 ) ;
F_111 ( V_8 ) ;
}
static struct V_308 * F_112 ( struct V_292 * V_8 )
{
struct V_308 * V_309 ;
if ( F_113 ( V_8 ) )
V_309 = F_114 ( V_8 ) ;
else
V_309 = F_115 ( V_8 ) ;
return V_309 ;
}
static int F_116 ( struct V_2 * V_4 ,
enum V_314 V_315 , void * V_301 )
{
struct V_1 * V_236 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_245 )
return - V_86 ;
switch ( V_315 ) {
case V_316 :
* ( int * ) V_301 = ( V_236 -> V_237 == V_274 ) ;
return 0 ;
default:
return - V_298 ;
}
}
static int F_117 ( struct V_2 * V_4 ,
enum V_314 V_315 , void * V_301 )
{
int V_19 = 0 ;
struct V_1 * V_236 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_245 )
return - V_86 ;
F_89 ( & V_236 -> V_248 ) ;
switch ( V_315 ) {
case V_316 :
if ( V_236 -> V_6 ) {
V_19 = - V_317 ;
goto V_293;
}
if ( * ( int * ) V_301 )
V_236 -> V_237 = V_274 ;
else
V_236 -> V_237 = V_238 ;
break;
default:
V_19 = - V_298 ;
}
V_293:
F_91 ( & V_236 -> V_248 ) ;
return V_19 ;
}
static int F_118 ( struct V_292 * V_8 , struct V_318 * args )
{
return F_119 ( V_8 , args -> args , 1 ) ;
}
static void F_120 ( struct V_292 * V_8 ,
struct V_319 * V_320 )
{
struct V_321 * V_322 ;
int V_296 = V_323 | V_324 | V_325 ;
V_322 = F_121 ( V_326 , V_327 ,
V_296 , V_328 ) ;
if ( ! V_322 )
return;
F_122 ( & V_322 -> V_329 , V_320 ) ;
F_123 ( V_8 , V_320 ) ;
}
static void F_124 ( struct V_292 * V_8 ,
struct V_319 * V_320 )
{
struct V_321 * V_330 , * V_331 ;
F_125 (entry, next, head, list)
F_68 ( V_330 ) ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_332 ,
unsigned long V_333 ,
T_5 V_334 )
{
T_5 V_335 = ( ( 1 << V_15 -> V_336 ) * V_334 ) << 3 ;
V_15 -> V_222 = F_52 ( V_6 -> V_8 , V_335 , & V_15 -> V_337 , V_190 ) ;
if ( ! V_15 -> V_222 ) {
F_32 ( V_6 -> V_8 , L_36 ,
V_335 ) ;
return - V_192 ;
}
V_15 -> V_20 = V_6 -> V_222 + V_332 ;
V_15 -> V_18 = V_6 -> V_222 + V_333 ;
V_15 -> V_32 = V_334 ;
V_15 -> V_338 = V_339 ;
V_15 -> V_338 |= V_15 -> V_337 & V_340 << V_341 ;
V_15 -> V_338 |= ( V_15 -> V_336 & V_342 )
<< V_343 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static int F_127 ( struct V_5 * V_6 )
{
int V_19 ;
F_70 ( & V_6 -> V_94 . V_102 ) ;
V_19 = F_126 ( V_6 , & V_6 -> V_94 . V_15 , V_344 ,
V_345 , V_36 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_126 ( V_6 , & V_6 -> V_194 . V_15 , V_346 ,
V_347 , V_196 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_6 -> V_100 & V_348 ) )
return 0 ;
return F_126 ( V_6 , & V_6 -> V_217 . V_15 , V_349 ,
V_350 , V_218 ) ;
}
static int F_128 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_184 * V_115 = & V_6 -> V_185 ;
T_5 V_46 = sizeof( * V_115 -> V_186 ) * V_115 -> V_307 ;
void * V_181 = V_6 -> V_185 . V_181 ;
V_115 -> V_186 = F_129 ( V_6 -> V_8 , V_46 , V_190 ) ;
if ( ! V_115 -> V_186 ) {
F_32 ( V_6 -> V_8 , L_37 ) ;
return - V_192 ;
}
for ( V_7 = 0 ; V_7 < V_115 -> V_307 ; ++ V_7 ) {
F_43 ( V_181 , & V_115 -> V_186 [ V_7 ] ) ;
V_181 += V_189 << 3 ;
}
return 0 ;
}
static int F_130 ( struct V_5 * V_6 )
{
void * V_181 ;
T_4 V_351 ;
T_1 V_46 , V_352 ;
struct V_184 * V_115 = & V_6 -> V_185 ;
V_46 = V_353 - ( F_51 ( V_189 ) + 3 ) ;
V_46 = F_131 ( V_46 , V_6 -> V_354 - V_187 ) ;
V_115 -> V_307 = 1 << V_46 ;
V_46 += V_187 ;
if ( V_46 < V_6 -> V_354 )
F_35 ( V_6 -> V_8 ,
L_38 ,
V_46 , V_6 -> V_354 ) ;
V_352 = V_115 -> V_307 * ( V_189 << 3 ) ;
V_181 = F_52 ( V_6 -> V_8 , V_352 , & V_115 -> V_355 ,
V_190 | V_191 ) ;
if ( ! V_181 ) {
F_32 ( V_6 -> V_8 ,
L_39 ,
V_46 ) ;
return - V_192 ;
}
V_115 -> V_181 = V_181 ;
V_351 = V_356 ;
V_351 |= ( V_46 & V_357 )
<< V_358 ;
V_351 |= ( V_187 & V_359 )
<< V_360 ;
V_115 -> V_361 = V_351 ;
return F_128 ( V_6 ) ;
}
static int F_132 ( struct V_5 * V_6 )
{
void * V_181 ;
T_4 V_351 ;
T_1 V_46 ;
struct V_184 * V_115 = & V_6 -> V_185 ;
V_46 = ( 1 << V_6 -> V_354 ) * ( V_183 << 3 ) ;
V_181 = F_52 ( V_6 -> V_8 , V_46 , & V_115 -> V_355 ,
V_190 | V_191 ) ;
if ( ! V_181 ) {
F_32 ( V_6 -> V_8 ,
L_40 ,
V_46 ) ;
return - V_192 ;
}
V_115 -> V_181 = V_181 ;
V_115 -> V_307 = 1 << V_6 -> V_354 ;
V_351 = V_362 ;
V_351 |= ( V_6 -> V_354 & V_357 )
<< V_358 ;
V_115 -> V_361 = V_351 ;
F_49 ( V_181 , V_115 -> V_307 ) ;
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
T_4 V_351 ;
int V_19 ;
if ( V_6 -> V_100 & V_284 )
V_19 = F_130 ( V_6 ) ;
else
V_19 = F_132 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_351 = V_6 -> V_185 . V_355 &
V_363 << V_364 ;
V_351 |= V_365 ;
V_6 -> V_185 . V_366 = V_351 ;
F_134 ( 0 , V_6 -> V_255 ) ;
return 0 ;
}
static int F_135 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_127 ( V_6 ) ;
if ( V_19 )
return V_19 ;
return F_133 ( V_6 ) ;
}
static int F_136 ( struct V_5 * V_6 , T_1 V_104 ,
unsigned int V_367 , unsigned int V_368 )
{
T_1 V_351 ;
F_137 ( V_104 , V_6 -> V_222 + V_367 ) ;
return F_138 ( V_6 -> V_222 + V_368 , V_351 , V_351 == V_104 ,
1 , V_25 ) ;
}
static int F_139 ( struct V_5 * V_6 , T_1 V_369 , T_1 V_370 )
{
int V_19 ;
T_1 V_351 , V_371 * V_372 = V_6 -> V_222 + V_373 ;
V_19 = F_138 ( V_372 , V_351 , ! ( V_351 & V_374 ) ,
1 , V_25 ) ;
if ( V_19 )
return V_19 ;
V_351 &= ~ V_370 ;
V_351 |= V_369 ;
F_137 ( V_351 | V_374 , V_372 ) ;
return F_138 ( V_372 , V_351 , ! ( V_351 & V_374 ) ,
1 , V_25 ) ;
}
static void F_140 ( void * V_301 )
{
struct V_292 * V_8 = V_301 ;
F_141 ( V_8 ) ;
}
static void F_142 ( struct V_375 * V_131 , struct V_376 * V_377 )
{
T_9 V_378 ;
struct V_292 * V_8 = F_143 ( V_131 ) ;
struct V_5 * V_6 = F_99 ( V_8 ) ;
T_9 * V_115 = V_379 [ V_131 -> V_380 . V_381 ] ;
V_378 = ( ( ( T_4 ) V_377 -> V_382 ) << 32 ) | V_377 -> V_383 ;
V_378 &= V_384 << V_385 ;
F_144 ( V_378 , V_6 -> V_222 + V_115 [ 0 ] ) ;
F_137 ( V_377 -> V_301 , V_6 -> V_222 + V_115 [ 1 ] ) ;
F_137 ( V_386 , V_6 -> V_222 + V_115 [ 2 ] ) ;
}
static void F_145 ( struct V_5 * V_6 )
{
struct V_375 * V_131 ;
int V_19 , V_387 = V_388 ;
struct V_292 * V_8 = V_6 -> V_8 ;
F_144 ( 0 , V_6 -> V_222 + V_389 ) ;
F_144 ( 0 , V_6 -> V_222 + V_390 ) ;
if ( V_6 -> V_100 & V_348 )
F_144 ( 0 , V_6 -> V_222 + V_391 ) ;
else
V_387 -- ;
if ( ! ( V_6 -> V_100 & V_392 ) )
return;
V_19 = F_146 ( V_8 , V_387 , F_142 ) ;
if ( V_19 ) {
F_35 ( V_8 , L_41 ) ;
return;
}
F_147 (desc, dev) {
switch ( V_131 -> V_380 . V_381 ) {
case V_393 :
V_6 -> V_194 . V_15 . V_193 = V_131 -> V_193 ;
break;
case V_394 :
V_6 -> V_395 = V_131 -> V_193 ;
break;
case V_396 :
V_6 -> V_217 . V_15 . V_193 = V_131 -> V_193 ;
break;
default:
continue;
}
}
F_148 ( V_8 , F_140 , V_8 ) ;
}
static int F_149 ( struct V_5 * V_6 )
{
int V_19 , V_193 ;
T_1 V_397 = V_398 | V_399 ;
V_19 = F_136 ( V_6 , 0 , V_400 ,
V_401 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_42 ) ;
return V_19 ;
}
F_145 ( V_6 ) ;
V_193 = V_6 -> V_194 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_150 ( V_6 -> V_8 , V_193 , NULL ,
F_53 ,
V_402 ,
L_43 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_44 ) ;
}
V_193 = V_6 -> V_94 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_151 ( V_6 -> V_8 , V_193 ,
F_57 , 0 ,
L_45 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_46 ) ;
}
V_193 = V_6 -> V_395 ;
if ( V_193 ) {
V_19 = F_151 ( V_6 -> V_8 , V_193 , F_58 ,
0 , L_47 , V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 , L_48 ) ;
}
if ( V_6 -> V_100 & V_348 ) {
V_193 = V_6 -> V_217 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_150 ( V_6 -> V_8 , V_193 , NULL ,
F_56 ,
V_402 ,
L_49 ,
V_6 ) ;
if ( V_19 < 0 )
F_35 ( V_6 -> V_8 ,
L_50 ) ;
else
V_397 |= V_403 ;
}
}
V_19 = F_136 ( V_6 , V_397 ,
V_400 , V_401 ) ;
if ( V_19 )
F_35 ( V_6 -> V_8 , L_51 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_136 ( V_6 , 0 , V_404 , V_405 ) ;
if ( V_19 )
F_32 ( V_6 -> V_8 , L_52 ) ;
return V_19 ;
}
static int F_152 ( struct V_5 * V_6 , bool V_406 )
{
int V_19 ;
T_1 V_351 , V_407 ;
struct V_35 V_34 ;
V_351 = F_11 ( V_6 -> V_222 + V_404 ) ;
if ( V_351 & V_408 )
F_35 ( V_6 -> V_8 , L_53 ) ;
V_19 = F_59 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_351 = ( V_409 << V_410 ) |
( V_411 << V_412 ) |
( V_411 << V_413 ) |
( V_409 << V_414 ) |
( V_411 << V_415 ) |
( V_411 << V_416 ) ;
F_137 ( V_351 , V_6 -> V_222 + V_417 ) ;
V_351 = V_418 | V_419 | V_420 ;
F_137 ( V_351 , V_6 -> V_222 + V_421 ) ;
F_144 ( V_6 -> V_185 . V_366 ,
V_6 -> V_222 + V_422 ) ;
F_137 ( V_6 -> V_185 . V_361 ,
V_6 -> V_222 + V_423 ) ;
F_144 ( V_6 -> V_94 . V_15 . V_338 , V_6 -> V_222 + V_424 ) ;
F_137 ( V_6 -> V_94 . V_15 . V_16 , V_6 -> V_222 + V_344 ) ;
F_137 ( V_6 -> V_94 . V_15 . V_17 , V_6 -> V_222 + V_345 ) ;
V_407 = V_425 ;
V_19 = F_136 ( V_6 , V_407 , V_404 ,
V_405 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_54 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
if ( V_6 -> V_100 & V_426 ) {
V_34 . V_37 = V_40 ;
F_34 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_34 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_34 ( V_6 , & V_34 ) ;
F_144 ( V_6 -> V_194 . V_15 . V_338 , V_6 -> V_222 + V_427 ) ;
F_137 ( V_6 -> V_194 . V_15 . V_16 , V_6 -> V_222 + V_346 ) ;
F_137 ( V_6 -> V_194 . V_15 . V_17 , V_6 -> V_222 + V_347 ) ;
V_407 |= V_428 ;
V_19 = F_136 ( V_6 , V_407 , V_404 ,
V_405 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_55 ) ;
return V_19 ;
}
if ( V_6 -> V_100 & V_348 ) {
F_144 ( V_6 -> V_217 . V_15 . V_338 ,
V_6 -> V_222 + V_429 ) ;
F_137 ( V_6 -> V_217 . V_15 . V_16 ,
V_6 -> V_222 + V_349 ) ;
F_137 ( V_6 -> V_217 . V_15 . V_17 ,
V_6 -> V_222 + V_350 ) ;
V_407 |= V_430 ;
V_19 = F_136 ( V_6 , V_407 , V_404 ,
V_405 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
}
V_19 = F_149 ( V_6 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
if ( ! V_406 || V_149 ) {
V_407 |= V_408 ;
} else {
V_19 = F_139 ( V_6 , 0 , V_431 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
}
V_19 = F_136 ( V_6 , V_407 , V_404 ,
V_405 ) ;
if ( V_19 ) {
F_32 ( V_6 -> V_8 , L_59 ) ;
return V_19 ;
}
return 0 ;
}
static int F_153 ( struct V_5 * V_6 )
{
T_1 V_351 ;
bool V_432 = V_6 -> V_100 & V_433 ;
V_351 = F_11 ( V_6 -> V_222 + V_434 ) ;
if ( ( V_351 & V_435 << V_436 ) == V_437 )
V_6 -> V_100 |= V_284 ;
if ( V_351 & V_438 )
V_6 -> V_100 |= V_439 ;
switch ( V_351 & V_440 << V_441 ) {
case V_442 :
V_6 -> V_100 |= V_443 | V_444 ;
break;
#ifdef F_42
case V_445 :
V_6 -> V_100 |= V_444 ;
break;
#else
case V_446 :
V_6 -> V_100 |= V_443 ;
break;
#endif
default:
F_32 ( V_6 -> V_8 , L_60 ) ;
return - V_294 ;
}
if ( F_154 ( V_447 ) && V_351 & V_448 )
V_6 -> V_100 |= V_348 ;
if ( F_154 ( F_48 ) && V_351 & V_449 )
V_6 -> V_100 |= V_450 ;
if ( V_351 & V_451 )
V_6 -> V_100 |= V_101 ;
if ( V_351 & V_452 )
V_6 -> V_100 |= V_392 ;
if ( V_351 & V_453 )
V_6 -> V_100 |= V_426 ;
if ( ! ! ( V_351 & V_454 ) != V_432 )
F_35 ( V_6 -> V_8 , L_61 ,
V_432 ? L_62 : L_63 ) ;
switch ( V_351 & V_455 << V_456 ) {
case V_457 :
case V_458 :
V_6 -> V_100 |= V_164 ;
}
if ( V_351 & V_459 )
V_6 -> V_100 |= V_269 ;
if ( V_351 & V_460 )
V_6 -> V_100 |= V_271 ;
if ( ! ( V_351 & ( V_459 | V_460 ) ) ) {
F_32 ( V_6 -> V_8 , L_64 ) ;
return - V_294 ;
}
switch ( V_351 & V_461 << V_462 ) {
case V_463 :
V_6 -> V_263 = 40 ;
case V_464 :
break;
default:
F_32 ( V_6 -> V_8 , L_65 ) ;
return - V_294 ;
}
V_6 -> V_258 = V_351 & V_465 ? 16 : 8 ;
V_6 -> V_261 = V_351 & V_466 ? 16 : 8 ;
V_351 = F_11 ( V_6 -> V_222 + V_467 ) ;
if ( V_351 & ( V_468 | V_469 | V_470 ) ) {
F_32 ( V_6 -> V_8 , L_66 ) ;
return - V_294 ;
}
V_6 -> V_94 . V_15 . V_336 = F_131 ( ( T_1 ) V_471 ,
V_351 >> V_472 & V_473 ) ;
if ( ! V_6 -> V_94 . V_15 . V_336 ) {
F_32 ( V_6 -> V_8 , L_67 ) ;
return - V_294 ;
}
V_6 -> V_194 . V_15 . V_336 = F_131 ( ( T_1 ) V_474 ,
V_351 >> V_475 & V_476 ) ;
V_6 -> V_217 . V_15 . V_336 = F_131 ( ( T_1 ) V_477 ,
V_351 >> V_478 & V_479 ) ;
V_6 -> V_480 = V_351 >> V_481 & V_482 ;
V_6 -> V_354 = V_351 >> V_483 & V_484 ;
if ( V_6 -> V_354 <= V_187 )
V_6 -> V_100 &= ~ V_284 ;
V_351 = F_11 ( V_6 -> V_222 + V_485 ) ;
V_6 -> V_194 . V_486 = V_351 >> V_487
& V_488 ;
if ( V_351 & V_489 )
V_6 -> V_276 |= V_490 | V_491 ;
if ( V_351 & V_492 )
V_6 -> V_276 |= V_493 | V_494 ;
if ( V_351 & V_495 )
V_6 -> V_276 |= V_496 | V_497 | V_498 ;
if ( V_310 . V_276 == - 1UL )
V_310 . V_276 = V_6 -> V_276 ;
else
V_310 . V_276 |= V_6 -> V_276 ;
switch ( V_351 & V_499 << V_500 ) {
case V_501 :
V_6 -> V_264 = 32 ;
break;
case V_502 :
V_6 -> V_264 = 36 ;
break;
case V_503 :
V_6 -> V_264 = 40 ;
break;
case V_504 :
V_6 -> V_264 = 42 ;
break;
case V_505 :
V_6 -> V_264 = 44 ;
break;
default:
F_54 ( V_6 -> V_8 ,
L_68 ) ;
case V_506 :
V_6 -> V_264 = 48 ;
}
if ( F_155 ( V_6 -> V_8 , F_156 ( V_6 -> V_264 ) ) )
F_35 ( V_6 -> V_8 ,
L_69 ) ;
V_6 -> V_263 = F_157 ( V_6 -> V_263 , V_6 -> V_264 ) ;
F_54 ( V_6 -> V_8 , L_70 ,
V_6 -> V_263 , V_6 -> V_264 , V_6 -> V_100 ) ;
return 0 ;
}
static int F_158 ( struct V_507 * V_508 ,
struct V_5 * V_6 )
{
struct V_509 * V_510 ;
struct V_292 * V_8 = V_6 -> V_8 ;
struct V_511 * V_512 ;
V_512 = * (struct V_511 * * ) F_159 ( V_8 ) ;
V_510 = (struct V_509 * ) V_512 -> V_513 ;
if ( V_510 -> V_99 & V_514 )
V_6 -> V_100 |= V_433 ;
return 0 ;
}
static inline int F_158 ( struct V_507 * V_508 ,
struct V_5 * V_6 )
{
return - V_298 ;
}
static int F_160 ( struct V_507 * V_508 ,
struct V_5 * V_6 )
{
struct V_292 * V_8 = & V_508 -> V_8 ;
T_1 V_515 ;
int V_19 = - V_86 ;
if ( F_161 ( V_8 -> V_9 , L_71 , & V_515 ) )
F_32 ( V_8 , L_72 ) ;
else if ( V_515 != 1 )
F_32 ( V_8 , L_73 , V_515 ) ;
else
V_19 = 0 ;
F_3 ( V_6 ) ;
if ( F_162 ( V_8 -> V_9 ) )
V_6 -> V_100 |= V_433 ;
return V_19 ;
}
static int F_163 ( struct V_507 * V_508 )
{
int V_193 , V_19 ;
struct V_516 * V_517 ;
T_11 V_518 ;
struct V_5 * V_6 ;
struct V_292 * V_8 = & V_508 -> V_8 ;
bool V_406 ;
V_6 = F_129 ( V_8 , sizeof( * V_6 ) , V_190 ) ;
if ( ! V_6 ) {
F_32 ( V_8 , L_74 ) ;
return - V_192 ;
}
V_6 -> V_8 = V_8 ;
V_517 = F_164 ( V_508 , V_519 , 0 ) ;
if ( F_165 ( V_517 ) + 1 < V_520 ) {
F_32 ( V_8 , L_75 , V_517 ) ;
return - V_86 ;
}
V_518 = V_517 -> V_521 ;
V_6 -> V_222 = F_166 ( V_8 , V_517 ) ;
if ( F_104 ( V_6 -> V_222 ) )
return F_167 ( V_6 -> V_222 ) ;
V_193 = F_168 ( V_508 , L_76 ) ;
if ( V_193 > 0 )
V_6 -> V_194 . V_15 . V_193 = V_193 ;
V_193 = F_168 ( V_508 , L_77 ) ;
if ( V_193 > 0 )
V_6 -> V_217 . V_15 . V_193 = V_193 ;
V_193 = F_168 ( V_508 , L_78 ) ;
if ( V_193 > 0 )
V_6 -> V_94 . V_15 . V_193 = V_193 ;
V_193 = F_168 ( V_508 , L_79 ) ;
if ( V_193 > 0 )
V_6 -> V_395 = V_193 ;
if ( V_8 -> V_9 ) {
V_19 = F_160 ( V_508 , V_6 ) ;
} else {
V_19 = F_158 ( V_508 , V_6 ) ;
if ( V_19 == - V_298 )
return V_19 ;
}
V_406 = ! ! V_19 ;
V_19 = F_153 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_135 ( V_6 ) ;
if ( V_19 )
return V_19 ;
F_169 ( V_508 , V_6 ) ;
V_19 = F_152 ( V_6 , V_406 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_170 ( & V_6 -> V_313 , V_8 , NULL ,
L_80 , & V_518 ) ;
if ( V_19 )
return V_19 ;
F_171 ( & V_6 -> V_313 , & V_310 ) ;
F_172 ( & V_6 -> V_313 , V_8 -> V_302 ) ;
V_19 = F_173 ( & V_6 -> V_313 ) ;
#ifdef F_174
if ( V_522 . V_523 != & V_310 ) {
F_175 () ;
V_19 = F_176 ( & V_522 , & V_310 ) ;
if ( V_19 )
return V_19 ;
}
#endif
#ifdef F_177
if ( V_524 . V_523 != & V_310 ) {
V_19 = F_176 ( & V_524 , & V_310 ) ;
if ( V_19 )
return V_19 ;
}
#endif
if ( V_525 . V_523 != & V_310 ) {
V_19 = F_176 ( & V_525 , & V_310 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_178 ( struct V_507 * V_508 )
{
struct V_5 * V_6 = F_179 ( V_508 ) ;
F_59 ( V_6 ) ;
return 0 ;
}
