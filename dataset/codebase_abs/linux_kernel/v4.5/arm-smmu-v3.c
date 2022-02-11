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
static bool F_17 ( struct V_14 * V_15 , T_1 V_22 )
{
if ( F_8 ( V_15 , V_15 -> V_17 ) == F_8 ( V_15 , V_22 ) )
return F_7 ( V_15 , V_15 -> V_17 ) < F_7 ( V_15 , V_22 ) ;
return F_7 ( V_15 , V_15 -> V_17 ) >= F_7 ( V_15 , V_22 ) ;
}
static int F_18 ( struct V_14 * V_15 , T_1 V_22 , bool V_23 )
{
T_2 V_24 = F_19 ( F_20 () , V_25 ) ;
while ( F_10 ( V_15 ) , F_17 ( V_15 , V_22 ) ) {
if ( F_21 ( F_20 () , V_24 ) > 0 )
return - V_26 ;
if ( V_23 ) {
V_23 () ;
} else {
F_22 () ;
F_23 ( 1 ) ;
}
}
return 0 ;
}
static void F_24 ( T_3 * V_27 , T_4 * V_28 , T_5 V_29 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_29 ; ++ V_7 )
* V_27 ++ = F_25 ( * V_28 ++ ) ;
}
static int F_26 ( struct V_14 * V_15 , T_4 * V_30 )
{
if ( F_6 ( V_15 ) )
return - V_31 ;
F_24 ( F_27 ( V_15 , V_15 -> V_16 ) , V_30 , V_15 -> V_32 ) ;
F_16 ( V_15 ) ;
return 0 ;
}
static void F_28 ( T_3 * V_27 , T_4 * V_28 , T_5 V_29 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_29 ; ++ V_7 )
* V_27 ++ = F_29 ( * V_28 ++ ) ;
}
static int F_30 ( struct V_14 * V_15 , T_4 * V_30 )
{
if ( F_9 ( V_15 ) )
return - V_33 ;
F_28 ( V_30 , F_27 ( V_15 , V_15 -> V_17 ) , V_15 -> V_32 ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_31 ( T_4 * V_34 , struct V_35 * V_30 )
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
static void F_32 ( struct V_5 * V_6 )
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
F_33 ( V_6 -> V_8 , L_5 , V_17 ,
V_95 < F_34 ( V_90 ) ? V_90 [ V_95 ] : L_6 ) ;
switch ( V_95 ) {
case V_93 :
F_33 ( V_6 -> V_8 , L_7 ) ;
case V_91 :
return;
case V_92 :
default:
break;
}
F_28 ( V_34 , F_27 ( V_15 , V_95 ) , V_15 -> V_32 ) ;
F_33 ( V_6 -> V_8 , L_8 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_34 ) ; ++ V_7 )
F_33 ( V_6 -> V_8 , L_9 , ( unsigned long long ) V_34 [ V_7 ] ) ;
if ( F_31 ( V_34 , & V_98 ) ) {
F_33 ( V_6 -> V_8 , L_10 ) ;
return;
}
F_24 ( V_34 , F_27 ( V_15 , V_95 ) , V_15 -> V_32 ) ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_35 * V_30 )
{
T_1 V_22 ;
T_4 V_34 [ V_36 ] ;
bool V_23 = ! ! ( V_6 -> V_99 & V_100 ) ;
struct V_14 * V_15 = & V_6 -> V_94 . V_15 ;
if ( F_31 ( V_34 , V_30 ) ) {
F_36 ( V_6 -> V_8 , L_11 ,
V_30 -> V_37 ) ;
return;
}
F_37 ( & V_6 -> V_94 . V_101 ) ;
while ( V_22 = V_15 -> V_16 + 1 , F_26 ( V_15 , V_34 ) == - V_31 ) {
if ( F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_12 ) ;
}
if ( V_30 -> V_37 == V_87 && F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_13 ) ;
F_39 ( & V_6 -> V_94 . V_101 ) ;
}
static T_4 F_40 ( T_4 V_102 )
{
T_4 V_103 = 0 ;
V_103 |= F_41 ( V_102 , V_104 ) ;
V_103 |= F_41 ( V_102 , V_105 ) ;
V_103 |= F_41 ( V_102 , V_106 ) ;
V_103 |= F_41 ( V_102 , V_107 ) ;
V_103 |= F_41 ( V_102 , V_108 ) ;
V_103 |= F_41 ( V_102 , V_109 ) ;
V_103 |= F_41 ( V_102 , V_110 ) ;
V_103 |= F_41 ( V_102 , V_111 ) ;
V_103 |= F_41 ( V_102 , V_112 ) ;
return V_103 ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_113 * V_114 )
{
T_4 V_103 ;
V_103 = F_40 ( V_114 -> V_115 . V_102 ) |
#ifdef F_43
V_116 |
#endif
V_117 | V_118 | V_119 |
V_120 | ( T_4 ) V_114 -> V_115 . V_60 << V_121 |
V_122 ;
V_114 -> V_123 [ 0 ] = F_25 ( V_103 ) ;
V_103 = V_114 -> V_115 . V_124 & V_125 << V_126 ;
V_114 -> V_123 [ 1 ] = F_25 ( V_103 ) ;
V_114 -> V_123 [ 3 ] = F_25 ( V_114 -> V_115 . V_127 << V_128 ) ;
}
static void
F_44 ( T_3 * V_27 , struct V_129 * V_130 )
{
T_4 V_103 = 0 ;
V_103 |= ( V_130 -> V_131 & V_132 )
<< V_133 ;
V_103 |= V_130 -> V_134 &
V_135 << V_136 ;
* V_27 = F_25 ( V_103 ) ;
}
static void F_45 ( struct V_5 * V_6 , T_1 V_44 )
{
struct V_35 V_34 = {
. V_37 = V_50 ,
. V_51 = {
. V_44 = V_44 ,
. V_53 = true ,
} ,
} ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
}
static void F_46 ( struct V_5 * V_6 , T_1 V_44 ,
T_3 * V_27 , struct V_137 * V_138 )
{
T_4 V_103 = F_29 ( V_27 [ 0 ] ) ;
bool V_139 = false ;
struct V_35 V_140 = {
. V_37 = V_42 ,
. V_43 = {
. V_44 = V_44 ,
} ,
} ;
if ( V_103 & V_141 ) {
T_4 V_114 ;
V_114 = V_103 & V_142 << V_143 ;
switch ( V_114 ) {
case V_144 :
break;
case V_145 :
case V_146 :
V_139 = true ;
break;
default:
F_47 () ;
}
}
V_103 &= ~ ( V_142 << V_143 ) ;
if ( V_138 -> V_147 )
V_103 |= V_141 ;
else
V_103 &= ~ V_141 ;
if ( V_138 -> V_148 ) {
V_103 |= V_149 ? V_150
: V_144 ;
V_27 [ 0 ] = F_25 ( V_103 ) ;
V_27 [ 1 ] = F_25 ( V_151
<< V_152 ) ;
V_27 [ 2 ] = 0 ;
if ( V_139 )
F_45 ( V_6 , V_44 ) ;
return;
}
if ( V_138 -> V_153 ) {
F_48 ( V_139 ) ;
V_27 [ 1 ] = F_25 (
V_154
<< V_155 |
V_154
<< V_156 |
V_157 << V_158 |
#ifdef F_49
V_159 << V_160 |
#endif
V_161 << V_162 ) ;
if ( V_6 -> V_99 & V_163 )
V_27 [ 1 ] |= F_25 ( V_164 ) ;
V_103 |= ( V_138 -> V_153 -> V_165 & V_166
<< V_167 ) |
V_145 ;
}
if ( V_138 -> V_168 ) {
F_48 ( V_139 ) ;
V_27 [ 2 ] = F_25 (
V_138 -> V_168 -> V_65 << V_169 |
( V_138 -> V_168 -> V_170 & V_171 )
<< V_172 |
#ifdef F_43
V_173 |
#endif
V_174 | V_175 |
V_176 ) ;
V_27 [ 3 ] = F_25 ( V_138 -> V_168 -> V_177 &
V_178 << V_179 ) ;
V_103 |= V_146 ;
}
F_45 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_25 ( V_103 ) ;
F_45 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_180 ) )
F_35 ( V_6 , & V_140 ) ;
}
static void F_50 ( T_4 * V_181 , unsigned int V_182 )
{
unsigned int V_7 ;
struct V_137 V_138 = {
. V_147 = true ,
. V_148 = true ,
} ;
for ( V_7 = 0 ; V_7 < V_182 ; ++ V_7 ) {
F_46 ( NULL , - 1 , V_181 , & V_138 ) ;
V_181 += V_183 ;
}
}
static int F_51 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_181 ;
struct V_184 * V_114 = & V_6 -> V_185 ;
struct V_129 * V_130 = & V_114 -> V_186 [ V_44 >> V_187 ] ;
if ( V_130 -> V_188 )
return 0 ;
V_46 = 1 << ( V_187 + F_52 ( V_183 ) + 3 ) ;
V_181 = & V_114 -> V_181 [ ( V_44 >> V_187 ) * V_189 ] ;
V_130 -> V_131 = V_187 + 1 ;
V_130 -> V_188 = F_53 ( V_6 -> V_8 , V_46 , & V_130 -> V_134 ,
V_190 | V_191 ) ;
if ( ! V_130 -> V_188 ) {
F_33 ( V_6 -> V_8 ,
L_14 ,
V_44 ) ;
return - V_192 ;
}
F_50 ( V_130 -> V_188 , 1 << V_187 ) ;
F_44 ( V_181 , V_130 ) ;
return 0 ;
}
static T_6 F_54 ( int V_193 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_194 . V_15 ;
T_4 V_195 [ V_196 ] ;
while ( ! F_30 ( V_15 , V_195 ) ) {
T_7 V_197 = V_195 [ 0 ] >> V_198 & V_199 ;
F_55 ( V_6 -> V_8 , L_15 , V_197 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_195 ) ; ++ V_7 )
F_55 ( V_6 -> V_8 , L_9 ,
( unsigned long long ) V_195 [ V_7 ] ) ;
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_200 ;
}
static T_6 F_56 ( int V_193 , void * V_8 )
{
T_6 V_19 = V_201 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_194 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_16 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_202 ;
return V_19 ;
}
static T_6 F_57 ( int V_193 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_203 . V_15 ;
T_4 V_195 [ V_204 ] ;
while ( ! F_30 ( V_15 , V_195 ) ) {
T_1 V_44 , V_74 ;
T_8 V_77 ;
bool V_205 , V_206 ;
V_44 = V_195 [ 0 ] >> V_207 & V_208 ;
V_205 = V_195 [ 0 ] & V_209 ;
V_74 = V_205 ? V_195 [ 0 ] >> V_210 & V_211 : 0 ;
V_206 = V_195 [ 0 ] & V_212 ;
V_77 = V_195 [ 1 ] >> V_213 & V_214 ;
F_55 ( V_6 -> V_8 , L_17 ) ;
F_55 ( V_6 -> V_8 ,
L_18 ,
V_44 , V_74 , V_77 , V_206 ? L_19 : L_20 ,
V_195 [ 0 ] & V_215 ? L_20 : L_21 ,
V_195 [ 0 ] & V_216 ? L_22 : L_20 ,
V_195 [ 0 ] & V_217 ? L_23 : L_20 ,
V_195 [ 0 ] & V_218 ? L_24 : L_20 ,
V_195 [ 1 ] & V_219 << V_220 ) ;
if ( V_206 ) {
struct V_35 V_34 = {
. V_37 = V_70 ,
. V_71 = V_205 ,
. V_73 = {
. V_44 = V_44 ,
. V_74 = V_74 ,
. V_77 = V_77 ,
. V_79 = V_80 ,
} ,
} ;
F_35 ( V_6 , & V_34 ) ;
}
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_200 ;
}
static T_6 F_58 ( int V_193 , void * V_8 )
{
T_6 V_19 = V_201 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_203 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_25 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_202 ;
return V_19 ;
}
static T_6 F_59 ( int V_193 , void * V_8 )
{
return V_200 ;
}
static T_6 F_60 ( int V_193 , void * V_8 )
{
T_1 V_221 , V_222 , V_223 ;
struct V_5 * V_6 = V_8 ;
V_221 = F_11 ( V_6 -> V_224 + V_225 ) ;
V_222 = F_11 ( V_6 -> V_224 + V_226 ) ;
V_223 = V_221 ^ V_222 ;
if ( ! ( V_223 & V_227 ) )
return V_202 ;
F_36 ( V_6 -> V_8 ,
L_26 ,
V_223 ) ;
if ( V_223 & V_228 ) {
F_33 ( V_6 -> V_8 , L_27 ) ;
F_61 ( V_6 ) ;
}
if ( V_223 & V_229 )
F_36 ( V_6 -> V_8 , L_28 ) ;
if ( V_223 & V_230 ) {
F_36 ( V_6 -> V_8 , L_29 ) ;
F_58 ( V_193 , V_6 -> V_8 ) ;
}
if ( V_223 & V_231 ) {
F_36 ( V_6 -> V_8 , L_30 ) ;
F_56 ( V_193 , V_6 -> V_8 ) ;
}
if ( V_223 & V_232 ) {
F_36 ( V_6 -> V_8 , L_31 ) ;
F_59 ( V_193 , V_6 -> V_8 ) ;
}
if ( V_223 & V_233 )
F_33 ( V_6 -> V_8 , L_32 ) ;
if ( V_223 & V_234 )
F_33 ( V_6 -> V_8 , L_33 ) ;
if ( V_223 & V_235 )
F_32 ( V_6 ) ;
F_14 ( V_221 , V_6 -> V_224 + V_226 ) ;
return V_200 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
}
static void F_63 ( void * V_236 )
{
struct V_1 * V_237 = V_236 ;
F_62 ( V_237 -> V_6 ) ;
}
static void F_64 ( void * V_236 )
{
struct V_1 * V_237 = V_236 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_35 V_34 ;
if ( V_237 -> V_238 == V_239 ) {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_60 = V_237 -> V_153 . V_115 . V_60 ;
V_34 . V_59 . V_65 = 0 ;
} else {
V_34 . V_37 = V_69 ;
V_34 . V_59 . V_65 = V_237 -> V_168 . V_65 ;
}
F_35 ( V_6 , & V_34 ) ;
F_62 ( V_6 ) ;
}
static void F_65 ( unsigned long V_240 , T_5 V_46 ,
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
V_34 . V_59 . V_60 = V_237 -> V_153 . V_115 . V_60 ;
} else {
V_34 . V_37 = V_64 ;
V_34 . V_59 . V_65 = V_237 -> V_168 . V_65 ;
}
do {
F_35 ( V_6 , & V_34 ) ;
V_34 . V_59 . V_48 += V_241 ;
} while ( V_46 -= V_241 );
}
static bool F_66 ( enum V_242 V_243 )
{
switch ( V_243 ) {
case V_244 :
return true ;
case V_245 :
return true ;
case V_246 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_237 ;
if ( type != V_247 )
return NULL ;
V_237 = F_68 ( sizeof( * V_237 ) , V_190 ) ;
if ( ! V_237 )
return NULL ;
F_69 ( & V_237 -> V_248 ) ;
F_70 ( & V_237 -> V_249 ) ;
return & V_237 -> V_4 ;
}
static int F_71 ( unsigned long * V_250 , int V_131 )
{
int V_95 , V_46 = 1 << V_131 ;
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
F_77 ( V_237 -> V_251 ) ;
if ( V_237 -> V_238 == V_239 ) {
struct V_113 * V_114 = & V_237 -> V_153 ;
if ( V_114 -> V_123 ) {
F_78 ( V_237 -> V_6 -> V_8 ,
V_252 << 3 ,
V_114 -> V_123 ,
V_114 -> V_165 ) ;
F_74 ( V_6 -> V_253 , V_114 -> V_115 . V_60 ) ;
}
} else {
struct V_254 * V_114 = & V_237 -> V_168 ;
if ( V_114 -> V_65 )
F_74 ( V_6 -> V_255 , V_114 -> V_65 ) ;
}
F_79 ( V_237 ) ;
}
static int F_80 ( struct V_1 * V_237 ,
struct V_256 * V_257 )
{
int V_19 ;
int V_60 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_113 * V_114 = & V_237 -> V_153 ;
V_60 = F_71 ( V_6 -> V_253 , V_6 -> V_258 ) ;
if ( F_81 ( V_60 ) )
return V_60 ;
V_114 -> V_123 = F_53 ( V_6 -> V_8 , V_252 << 3 ,
& V_114 -> V_165 ,
V_190 | V_191 ) ;
if ( ! V_114 -> V_123 ) {
F_36 ( V_6 -> V_8 , L_34 ) ;
V_19 = - V_192 ;
goto V_259;
}
V_114 -> V_115 . V_60 = ( T_8 ) V_60 ;
V_114 -> V_115 . V_124 = V_257 -> V_260 . V_124 [ 0 ] ;
V_114 -> V_115 . V_102 = V_257 -> V_260 . V_102 ;
V_114 -> V_115 . V_127 = V_257 -> V_260 . V_127 [ 0 ] ;
return 0 ;
V_259:
F_74 ( V_6 -> V_253 , V_60 ) ;
return V_19 ;
}
static int F_82 ( struct V_1 * V_237 ,
struct V_256 * V_257 )
{
int V_65 ;
struct V_5 * V_6 = V_237 -> V_6 ;
struct V_254 * V_114 = & V_237 -> V_168 ;
V_65 = F_71 ( V_6 -> V_255 , V_6 -> V_261 ) ;
if ( F_81 ( V_65 ) )
return V_65 ;
V_114 -> V_65 = ( T_8 ) V_65 ;
V_114 -> V_177 = V_257 -> V_262 . V_177 ;
V_114 -> V_170 = V_257 -> V_262 . V_170 ;
return 0 ;
}
static int F_83 ( struct V_2 * V_4 )
{
int V_19 ;
unsigned long V_263 , V_264 ;
enum V_265 V_266 ;
struct V_256 V_257 ;
struct V_267 * V_251 ;
int (* F_84)( struct V_1 * ,
struct V_256 * );
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_237 -> V_6 ;
if ( ! ( V_6 -> V_99 & V_268 ) )
V_237 -> V_238 = V_269 ;
if ( ! ( V_6 -> V_99 & V_270 ) )
V_237 -> V_238 = V_239 ;
switch ( V_237 -> V_238 ) {
case V_239 :
V_263 = V_271 ;
V_264 = V_6 -> V_263 ;
V_266 = V_272 ;
F_84 = F_80 ;
break;
case V_273 :
case V_269 :
V_263 = V_6 -> V_263 ;
V_264 = V_6 -> V_264 ;
V_266 = V_274 ;
F_84 = F_82 ;
break;
default:
return - V_86 ;
}
V_257 = (struct V_256 ) {
. V_275 = V_276 . V_275 ,
. V_263 = V_263 ,
. V_264 = V_264 ,
. V_277 = & V_278 ,
. V_279 = V_6 -> V_8 ,
} ;
V_251 = F_85 ( V_266 , & V_257 , V_237 ) ;
if ( ! V_251 )
return - V_192 ;
V_276 . V_275 = V_257 . V_275 ;
V_237 -> V_251 = V_251 ;
V_19 = F_84 ( V_237 , & V_257 ) ;
if ( F_81 ( V_19 ) )
F_77 ( V_251 ) ;
return V_19 ;
}
static struct V_280 * F_86 ( struct V_281 * V_8 )
{
struct V_282 * V_283 ;
struct V_280 * V_284 ;
V_283 = F_87 ( V_8 ) ;
if ( ! V_283 )
return NULL ;
V_284 = F_88 ( V_283 ) ;
F_89 ( V_283 ) ;
return V_284 ;
}
static T_3 * F_90 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_285 ;
struct V_184 * V_114 = & V_6 -> V_185 ;
if ( V_6 -> V_99 & V_286 ) {
struct V_129 * V_186 ;
int V_95 ;
V_95 = ( V_44 >> V_187 ) * V_189 ;
V_186 = & V_114 -> V_186 [ V_95 ] ;
V_95 = ( V_44 & ( ( 1 << V_187 ) - 1 ) ) * V_183 ;
V_285 = & V_186 -> V_188 [ V_95 ] ;
} else {
V_285 = & V_114 -> V_181 [ V_44 * V_183 ] ;
}
return V_285 ;
}
static int F_91 ( struct V_280 * V_284 )
{
int V_7 ;
struct V_1 * V_237 = V_284 -> V_4 ;
struct V_137 * V_138 = & V_284 -> V_138 ;
struct V_5 * V_6 = V_284 -> V_6 ;
if ( V_237 -> V_238 == V_239 ) {
V_138 -> V_153 = & V_237 -> V_153 ;
V_138 -> V_168 = NULL ;
F_42 ( V_6 , V_138 -> V_153 ) ;
} else {
V_138 -> V_153 = NULL ;
V_138 -> V_168 = & V_237 -> V_168 ;
}
for ( V_7 = 0 ; V_7 < V_284 -> V_287 ; ++ V_7 ) {
T_1 V_44 = V_284 -> V_288 [ V_7 ] ;
T_3 * V_285 = F_90 ( V_6 , V_44 ) ;
F_46 ( V_6 , V_44 , V_285 , V_138 ) ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_4 , struct V_281 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_280 * V_284 = F_86 ( V_8 ) ;
if ( ! V_284 )
return - V_89 ;
if ( V_284 -> V_4 && V_284 -> V_4 != V_237 )
return - V_289 ;
V_6 = V_284 -> V_6 ;
F_93 ( & V_237 -> V_248 ) ;
if ( ! V_237 -> V_6 ) {
V_237 -> V_6 = V_6 ;
V_19 = F_83 ( V_4 ) ;
if ( V_19 ) {
V_237 -> V_6 = NULL ;
goto V_290;
}
} else if ( V_237 -> V_6 != V_6 ) {
F_33 ( V_8 ,
L_35 ,
F_94 ( V_237 -> V_6 -> V_8 ) ,
F_94 ( V_6 -> V_8 ) ) ;
V_19 = - V_291 ;
goto V_290;
}
if ( V_284 -> V_4 )
goto V_290;
V_284 -> V_4 = V_237 ;
V_284 -> V_138 . V_148 = false ;
V_19 = F_91 ( V_284 ) ;
if ( F_81 ( V_19 ) )
V_284 -> V_4 = NULL ;
V_290:
F_95 ( & V_237 -> V_248 ) ;
return V_19 ;
}
static void F_96 ( struct V_2 * V_4 , struct V_281 * V_8 )
{
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_280 * V_284 = F_86 ( V_8 ) ;
F_48 ( ! V_237 ) ;
F_48 ( ! V_284 ) ;
F_93 ( & V_237 -> V_248 ) ;
F_48 ( V_284 -> V_4 != V_237 ) ;
V_284 -> V_138 . V_148 = true ;
if ( F_81 ( F_91 ( V_284 ) ) )
F_36 ( V_8 , L_36 ) ;
V_284 -> V_4 = NULL ;
F_95 ( & V_237 -> V_248 ) ;
}
static int F_97 ( struct V_2 * V_4 , unsigned long V_240 ,
T_9 V_292 , T_5 V_46 , int V_293 )
{
int V_19 ;
unsigned long V_294 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_295 = V_237 -> V_251 ;
if ( ! V_295 )
return - V_296 ;
F_98 ( & V_237 -> V_249 , V_294 ) ;
V_19 = V_295 -> V_250 ( V_295 , V_240 , V_292 , V_46 , V_293 ) ;
F_99 ( & V_237 -> V_249 , V_294 ) ;
return V_19 ;
}
static T_5
F_100 ( struct V_2 * V_4 , unsigned long V_240 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_294 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_295 = V_237 -> V_251 ;
if ( ! V_295 )
return 0 ;
F_98 ( & V_237 -> V_249 , V_294 ) ;
V_19 = V_295 -> V_297 ( V_295 , V_240 , V_46 ) ;
F_99 ( & V_237 -> V_249 , V_294 ) ;
return V_19 ;
}
static T_9
F_101 ( struct V_2 * V_4 , T_10 V_240 )
{
T_9 V_19 ;
unsigned long V_294 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
struct V_267 * V_295 = V_237 -> V_251 ;
if ( ! V_295 )
return 0 ;
F_98 ( & V_237 -> V_249 , V_294 ) ;
V_19 = V_295 -> V_298 ( V_295 , V_240 ) ;
F_99 ( & V_237 -> V_249 , V_294 ) ;
return V_19 ;
}
static int F_102 ( struct V_299 * V_300 , T_8 V_301 , void * V_302 )
{
* ( T_1 * ) V_302 = V_301 ;
return 0 ;
}
static void F_103 ( void * V_303 )
{
F_79 ( V_303 ) ;
}
static struct V_5 * F_104 ( struct V_299 * V_300 )
{
struct V_304 * V_9 ;
struct V_305 * V_306 ;
struct V_5 * V_6 = NULL ;
struct V_307 * V_308 = V_300 -> V_308 ;
while ( ! F_105 ( V_308 ) )
V_308 = V_308 -> V_309 ;
V_9 = F_106 ( V_308 -> V_310 -> V_309 -> V_9 , L_37 , 0 ) ;
if ( ! V_9 )
return NULL ;
V_306 = F_107 ( V_9 ) ;
if ( V_306 )
V_6 = F_108 ( V_306 ) ;
F_109 ( V_9 ) ;
return V_6 ;
}
static bool F_110 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_311 = V_6 -> V_185 . V_312 ;
if ( V_6 -> V_99 & V_286 )
V_311 *= 1UL << V_187 ;
return V_44 < V_311 ;
}
static int F_111 ( struct V_281 * V_8 )
{
int V_7 , V_19 ;
T_1 V_44 , * V_288 ;
struct V_299 * V_300 ;
struct V_282 * V_283 ;
struct V_280 * V_284 ;
struct V_5 * V_6 ;
if ( ! F_112 ( V_8 ) )
return - V_296 ;
V_300 = F_113 ( V_8 ) ;
V_283 = F_114 ( V_8 ) ;
if ( F_115 ( V_283 ) )
return F_116 ( V_283 ) ;
V_284 = F_88 ( V_283 ) ;
if ( ! V_284 ) {
V_6 = F_104 ( V_300 ) ;
if ( ! V_6 ) {
V_19 = - V_89 ;
goto V_313;
}
V_284 = F_68 ( sizeof( * V_284 ) , V_190 ) ;
if ( ! V_284 ) {
V_19 = - V_192 ;
goto V_313;
}
V_284 -> V_138 . V_147 = true ;
V_284 -> V_6 = V_6 ;
F_117 ( V_283 , V_284 ,
F_103 ) ;
} else {
V_6 = V_284 -> V_6 ;
}
F_118 ( V_300 , F_102 , & V_44 ) ;
for ( V_7 = 0 ; V_7 < V_284 -> V_287 ; ++ V_7 ) {
if ( V_284 -> V_288 [ V_7 ] == V_44 )
goto V_314;
}
if ( ! F_110 ( V_6 , V_44 ) ) {
V_19 = - V_315 ;
goto V_313;
}
if ( V_6 -> V_99 & V_286 ) {
V_19 = F_51 ( V_6 , V_44 ) ;
if ( V_19 )
goto V_313;
}
V_284 -> V_287 ++ ;
V_288 = F_119 ( V_284 -> V_288 , V_284 -> V_287 * sizeof( * V_288 ) ,
V_190 ) ;
if ( ! V_288 ) {
V_284 -> V_287 -- ;
V_19 = - V_192 ;
goto V_313;
}
V_288 [ V_284 -> V_287 - 1 ] = V_44 ;
V_284 -> V_288 = V_288 ;
V_314:
F_89 ( V_283 ) ;
return 0 ;
V_313:
F_120 ( V_8 ) ;
F_89 ( V_283 ) ;
return V_19 ;
}
static void F_121 ( struct V_281 * V_8 )
{
F_120 ( V_8 ) ;
}
static int F_122 ( struct V_2 * V_4 ,
enum V_316 V_317 , void * V_303 )
{
struct V_1 * V_237 = F_1 ( V_4 ) ;
switch ( V_317 ) {
case V_318 :
* ( int * ) V_303 = ( V_237 -> V_238 == V_273 ) ;
return 0 ;
default:
return - V_296 ;
}
}
static int F_123 ( struct V_2 * V_4 ,
enum V_316 V_317 , void * V_303 )
{
int V_19 = 0 ;
struct V_1 * V_237 = F_1 ( V_4 ) ;
F_93 ( & V_237 -> V_248 ) ;
switch ( V_317 ) {
case V_318 :
if ( V_237 -> V_6 ) {
V_19 = - V_319 ;
goto V_290;
}
if ( * ( int * ) V_303 )
V_237 -> V_238 = V_273 ;
else
V_237 -> V_238 = V_239 ;
break;
default:
V_19 = - V_296 ;
}
V_290:
F_95 ( & V_237 -> V_248 ) ;
return V_19 ;
}
static int F_124 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_320 ,
unsigned long V_321 ,
T_5 V_322 )
{
T_5 V_323 = ( ( 1 << V_15 -> V_324 ) * V_322 ) << 3 ;
V_15 -> V_224 = F_53 ( V_6 -> V_8 , V_323 , & V_15 -> V_325 , V_190 ) ;
if ( ! V_15 -> V_224 ) {
F_33 ( V_6 -> V_8 , L_38 ,
V_323 ) ;
return - V_192 ;
}
V_15 -> V_20 = V_6 -> V_224 + V_320 ;
V_15 -> V_18 = V_6 -> V_224 + V_321 ;
V_15 -> V_32 = V_322 ;
V_15 -> V_326 = V_327 ;
V_15 -> V_326 |= V_15 -> V_325 & V_328 << V_329 ;
V_15 -> V_326 |= ( V_15 -> V_324 & V_330 )
<< V_331 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static int F_125 ( struct V_5 * V_6 )
{
int V_19 ;
F_70 ( & V_6 -> V_94 . V_101 ) ;
V_19 = F_124 ( V_6 , & V_6 -> V_94 . V_15 , V_332 ,
V_333 , V_36 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_124 ( V_6 , & V_6 -> V_194 . V_15 , V_334 ,
V_335 , V_196 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_6 -> V_99 & V_336 ) )
return 0 ;
return F_124 ( V_6 , & V_6 -> V_203 . V_15 , V_337 ,
V_338 , V_204 ) ;
}
static int F_126 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_184 * V_114 = & V_6 -> V_185 ;
T_5 V_46 = sizeof( * V_114 -> V_186 ) * V_114 -> V_312 ;
void * V_181 = V_6 -> V_185 . V_181 ;
V_114 -> V_186 = F_127 ( V_6 -> V_8 , V_46 , V_190 ) ;
if ( ! V_114 -> V_186 ) {
F_33 ( V_6 -> V_8 , L_39 ) ;
return - V_192 ;
}
for ( V_7 = 0 ; V_7 < V_114 -> V_312 ; ++ V_7 ) {
F_44 ( V_181 , & V_114 -> V_186 [ V_7 ] ) ;
V_181 += V_189 << 3 ;
}
return 0 ;
}
static int F_128 ( struct V_5 * V_6 )
{
void * V_181 ;
T_4 V_339 ;
T_1 V_46 , V_340 ;
struct V_184 * V_114 = & V_6 -> V_185 ;
if ( V_6 -> V_341 < V_187 ) {
V_46 = 0 ;
} else {
V_46 = V_342 - ( F_52 ( V_189 ) + 3 ) ;
V_46 = F_129 ( V_46 , V_6 -> V_341 - V_187 ) ;
}
V_114 -> V_312 = 1 << V_46 ;
V_46 += V_187 ;
if ( V_46 < V_6 -> V_341 )
F_36 ( V_6 -> V_8 ,
L_40 ,
V_46 , V_6 -> V_341 ) ;
V_340 = V_114 -> V_312 * ( V_189 << 3 ) ;
V_181 = F_53 ( V_6 -> V_8 , V_340 , & V_114 -> V_343 ,
V_190 | V_191 ) ;
if ( ! V_181 ) {
F_33 ( V_6 -> V_8 ,
L_41 ,
V_46 ) ;
return - V_192 ;
}
V_114 -> V_181 = V_181 ;
V_339 = V_344 ;
V_339 |= ( V_46 & V_345 )
<< V_346 ;
V_339 |= ( V_187 & V_347 )
<< V_348 ;
V_114 -> V_349 = V_339 ;
return F_126 ( V_6 ) ;
}
static int F_130 ( struct V_5 * V_6 )
{
void * V_181 ;
T_4 V_339 ;
T_1 V_46 ;
struct V_184 * V_114 = & V_6 -> V_185 ;
V_46 = ( 1 << V_6 -> V_341 ) * ( V_183 << 3 ) ;
V_181 = F_53 ( V_6 -> V_8 , V_46 , & V_114 -> V_343 ,
V_190 | V_191 ) ;
if ( ! V_181 ) {
F_33 ( V_6 -> V_8 ,
L_42 ,
V_46 ) ;
return - V_192 ;
}
V_114 -> V_181 = V_181 ;
V_114 -> V_312 = 1 << V_6 -> V_341 ;
V_339 = V_350 ;
V_339 |= ( V_6 -> V_341 & V_345 )
<< V_346 ;
V_114 -> V_349 = V_339 ;
F_50 ( V_181 , V_114 -> V_312 ) ;
return 0 ;
}
static int F_131 ( struct V_5 * V_6 )
{
T_4 V_339 ;
int V_19 ;
if ( V_6 -> V_99 & V_286 )
V_19 = F_128 ( V_6 ) ;
else
V_19 = F_130 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = V_6 -> V_185 . V_343 &
V_351 << V_352 ;
V_339 |= V_353 ;
V_6 -> V_185 . V_354 = V_339 ;
F_132 ( 0 , V_6 -> V_255 ) ;
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_125 ( V_6 ) ;
if ( V_19 )
return V_19 ;
return F_131 ( V_6 ) ;
}
static int F_134 ( struct V_5 * V_6 , T_1 V_103 ,
unsigned int V_355 , unsigned int V_356 )
{
T_1 V_339 ;
F_135 ( V_103 , V_6 -> V_224 + V_355 ) ;
return F_136 ( V_6 -> V_224 + V_356 , V_339 , V_339 == V_103 ,
1 , V_25 ) ;
}
static void F_137 ( void * V_303 )
{
struct V_281 * V_8 = V_303 ;
F_138 ( V_8 ) ;
}
static void F_139 ( struct V_357 * V_130 , struct V_358 * V_359 )
{
T_9 V_360 ;
struct V_281 * V_8 = F_140 ( V_130 ) ;
struct V_5 * V_6 = F_141 ( V_8 ) ;
T_9 * V_114 = V_361 [ V_130 -> V_362 . V_363 ] ;
V_360 = ( ( ( T_4 ) V_359 -> V_364 ) << 32 ) | V_359 -> V_365 ;
V_360 &= V_366 << V_367 ;
F_142 ( V_360 , V_6 -> V_224 + V_114 [ 0 ] ) ;
F_135 ( V_359 -> V_303 , V_6 -> V_224 + V_114 [ 1 ] ) ;
F_135 ( V_368 , V_6 -> V_224 + V_114 [ 2 ] ) ;
}
static void F_143 ( struct V_5 * V_6 )
{
struct V_357 * V_130 ;
int V_19 , V_369 = V_370 ;
struct V_281 * V_8 = V_6 -> V_8 ;
F_142 ( 0 , V_6 -> V_224 + V_371 ) ;
F_142 ( 0 , V_6 -> V_224 + V_372 ) ;
if ( V_6 -> V_99 & V_336 )
F_142 ( 0 , V_6 -> V_224 + V_373 ) ;
else
V_369 -- ;
if ( ! ( V_6 -> V_99 & V_374 ) )
return;
V_19 = F_144 ( V_8 , V_369 , F_139 ) ;
if ( V_19 ) {
F_36 ( V_8 , L_43 ) ;
return;
}
F_145 (desc, dev) {
switch ( V_130 -> V_362 . V_363 ) {
case V_375 :
V_6 -> V_194 . V_15 . V_193 = V_130 -> V_193 ;
break;
case V_376 :
V_6 -> V_377 = V_130 -> V_193 ;
break;
case V_378 :
V_6 -> V_203 . V_15 . V_193 = V_130 -> V_193 ;
break;
default:
continue;
}
}
F_146 ( V_8 , F_137 , V_8 ) ;
}
static int F_147 ( struct V_5 * V_6 )
{
int V_19 , V_193 ;
T_1 V_379 = V_380 | V_381 ;
V_19 = F_134 ( V_6 , 0 , V_382 ,
V_383 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_44 ) ;
return V_19 ;
}
F_143 ( V_6 ) ;
V_193 = V_6 -> V_194 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_148 ( V_6 -> V_8 , V_193 ,
F_56 ,
F_54 ,
0 , L_45 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_46 ) ;
}
V_193 = V_6 -> V_94 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_149 ( V_6 -> V_8 , V_193 ,
F_59 , 0 ,
L_47 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_48 ) ;
}
V_193 = V_6 -> V_377 ;
if ( V_193 ) {
V_19 = F_149 ( V_6 -> V_8 , V_193 , F_60 ,
0 , L_49 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_50 ) ;
}
if ( V_6 -> V_99 & V_336 ) {
V_193 = V_6 -> V_203 . V_15 . V_193 ;
if ( V_193 ) {
V_19 = F_148 ( V_6 -> V_8 , V_193 ,
F_58 ,
F_57 ,
0 , L_51 ,
V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 ,
L_52 ) ;
else
V_379 |= V_384 ;
}
}
V_19 = F_134 ( V_6 , V_379 ,
V_382 , V_383 ) ;
if ( V_19 )
F_36 ( V_6 -> V_8 , L_53 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_134 ( V_6 , 0 , V_385 , V_386 ) ;
if ( V_19 )
F_33 ( V_6 -> V_8 , L_54 ) ;
return V_19 ;
}
static int F_150 ( struct V_5 * V_6 )
{
int V_19 ;
T_1 V_339 , V_387 ;
struct V_35 V_34 ;
V_339 = F_11 ( V_6 -> V_224 + V_385 ) ;
if ( V_339 & V_388 )
F_36 ( V_6 -> V_8 , L_55 ) ;
V_19 = F_61 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = ( V_389 << V_390 ) |
( V_391 << V_392 ) |
( V_391 << V_393 ) |
( V_389 << V_394 ) |
( V_391 << V_395 ) |
( V_391 << V_396 ) ;
F_135 ( V_339 , V_6 -> V_224 + V_397 ) ;
V_339 = V_398 | V_399 | V_400 ;
F_135 ( V_339 , V_6 -> V_224 + V_401 ) ;
F_142 ( V_6 -> V_185 . V_354 ,
V_6 -> V_224 + V_402 ) ;
F_135 ( V_6 -> V_185 . V_349 ,
V_6 -> V_224 + V_403 ) ;
F_142 ( V_6 -> V_94 . V_15 . V_326 , V_6 -> V_224 + V_404 ) ;
F_135 ( V_6 -> V_94 . V_15 . V_16 , V_6 -> V_224 + V_332 ) ;
F_135 ( V_6 -> V_94 . V_15 . V_17 , V_6 -> V_224 + V_333 ) ;
V_387 = V_405 ;
V_19 = F_134 ( V_6 , V_387 , V_385 ,
V_386 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
if ( V_6 -> V_99 & V_406 ) {
V_34 . V_37 = V_40 ;
F_35 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
F_142 ( V_6 -> V_194 . V_15 . V_326 , V_6 -> V_224 + V_407 ) ;
F_135 ( V_6 -> V_194 . V_15 . V_16 , V_6 -> V_224 + V_334 ) ;
F_135 ( V_6 -> V_194 . V_15 . V_17 , V_6 -> V_224 + V_335 ) ;
V_387 |= V_408 ;
V_19 = F_134 ( V_6 , V_387 , V_385 ,
V_386 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
if ( V_6 -> V_99 & V_336 ) {
F_142 ( V_6 -> V_203 . V_15 . V_326 ,
V_6 -> V_224 + V_409 ) ;
F_135 ( V_6 -> V_203 . V_15 . V_16 ,
V_6 -> V_224 + V_337 ) ;
F_135 ( V_6 -> V_203 . V_15 . V_17 ,
V_6 -> V_224 + V_338 ) ;
V_387 |= V_410 ;
V_19 = F_134 ( V_6 , V_387 , V_385 ,
V_386 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
}
V_19 = F_147 ( V_6 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_59 ) ;
return V_19 ;
}
V_387 |= V_388 ;
V_19 = F_134 ( V_6 , V_387 , V_385 ,
V_386 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_60 ) ;
return V_19 ;
}
return 0 ;
}
static int F_151 ( struct V_5 * V_6 )
{
T_1 V_339 ;
bool V_411 ;
unsigned long V_275 = 0 ;
V_339 = F_11 ( V_6 -> V_224 + V_412 ) ;
if ( ( V_339 & V_413 << V_414 ) == V_415 )
V_6 -> V_99 |= V_286 ;
if ( V_339 & V_416 )
V_6 -> V_99 |= V_417 ;
switch ( V_339 & V_418 << V_419 ) {
case V_420 :
V_6 -> V_99 |= V_421 | V_422 ;
break;
#ifdef F_43
case V_423 :
V_6 -> V_99 |= V_422 ;
break;
#else
case V_424 :
V_6 -> V_99 |= V_421 ;
break;
#endif
default:
F_33 ( V_6 -> V_8 , L_61 ) ;
return - V_291 ;
}
if ( F_152 ( V_425 ) && V_339 & V_426 )
V_6 -> V_99 |= V_336 ;
if ( F_152 ( F_49 ) && V_339 & V_427 )
V_6 -> V_99 |= V_428 ;
if ( V_339 & V_429 )
V_6 -> V_99 |= V_100 ;
if ( V_339 & V_430 )
V_6 -> V_99 |= V_374 ;
if ( V_339 & V_431 )
V_6 -> V_99 |= V_406 ;
V_411 = F_153 ( V_6 -> V_8 -> V_9 ) ;
if ( V_411 )
V_6 -> V_99 |= V_432 ;
if ( ! ! ( V_339 & V_433 ) != V_411 )
F_36 ( V_6 -> V_8 , L_62 ,
V_411 ? L_63 : L_64 ) ;
switch ( V_339 & V_434 << V_435 ) {
case V_436 :
case V_437 :
V_6 -> V_99 |= V_163 ;
}
if ( V_339 & V_438 )
V_6 -> V_99 |= V_268 ;
if ( V_339 & V_439 )
V_6 -> V_99 |= V_270 ;
if ( ! ( V_339 & ( V_438 | V_439 ) ) ) {
F_33 ( V_6 -> V_8 , L_65 ) ;
return - V_291 ;
}
switch ( V_339 & V_440 << V_441 ) {
case V_442 :
V_6 -> V_263 = 40 ;
case V_443 :
break;
default:
F_33 ( V_6 -> V_8 , L_66 ) ;
return - V_291 ;
}
V_6 -> V_258 = V_339 & V_444 ? 16 : 8 ;
V_6 -> V_261 = V_339 & V_445 ? 16 : 8 ;
V_339 = F_11 ( V_6 -> V_224 + V_446 ) ;
if ( V_339 & ( V_447 | V_448 | V_449 ) ) {
F_33 ( V_6 -> V_8 , L_67 ) ;
return - V_291 ;
}
V_6 -> V_94 . V_15 . V_324 = F_129 ( ( T_1 ) V_450 ,
V_339 >> V_451 & V_452 ) ;
if ( ! V_6 -> V_94 . V_15 . V_324 ) {
F_33 ( V_6 -> V_8 , L_68 ) ;
return - V_291 ;
}
V_6 -> V_194 . V_15 . V_324 = F_129 ( ( T_1 ) V_453 ,
V_339 >> V_454 & V_455 ) ;
V_6 -> V_203 . V_15 . V_324 = F_129 ( ( T_1 ) V_456 ,
V_339 >> V_457 & V_458 ) ;
V_6 -> V_459 = V_339 >> V_460 & V_461 ;
V_6 -> V_341 = V_339 >> V_462 & V_463 ;
V_339 = F_11 ( V_6 -> V_224 + V_464 ) ;
V_6 -> V_194 . V_465 = V_339 >> V_466
& V_467 ;
if ( V_339 & V_468 )
V_275 |= V_469 | V_470 ;
if ( V_339 & V_471 )
V_275 |= V_472 | V_473 ;
if ( V_339 & V_474 )
V_275 |= V_475 | V_476 | V_477 ;
V_276 . V_275 &= V_275 ;
switch ( V_339 & V_478 << V_479 ) {
case V_480 :
V_6 -> V_264 = 32 ;
break;
case V_481 :
V_6 -> V_264 = 36 ;
break;
case V_482 :
V_6 -> V_264 = 40 ;
break;
case V_483 :
V_6 -> V_264 = 42 ;
break;
case V_484 :
V_6 -> V_264 = 44 ;
break;
default:
F_55 ( V_6 -> V_8 ,
L_69 ) ;
case V_485 :
V_6 -> V_264 = 48 ;
}
if ( F_154 ( V_6 -> V_8 , F_155 ( V_6 -> V_264 ) ) )
F_36 ( V_6 -> V_8 ,
L_70 ) ;
V_6 -> V_263 = F_156 ( V_6 -> V_263 , V_6 -> V_264 ) ;
F_55 ( V_6 -> V_8 , L_71 ,
V_6 -> V_263 , V_6 -> V_264 , V_6 -> V_99 ) ;
return 0 ;
}
static int F_157 ( struct V_305 * V_300 )
{
int V_193 , V_19 ;
struct V_486 * V_487 ;
struct V_5 * V_6 ;
struct V_281 * V_8 = & V_300 -> V_8 ;
V_6 = F_127 ( V_8 , sizeof( * V_6 ) , V_190 ) ;
if ( ! V_6 ) {
F_33 ( V_8 , L_72 ) ;
return - V_192 ;
}
V_6 -> V_8 = V_8 ;
V_487 = F_158 ( V_300 , V_488 , 0 ) ;
if ( F_159 ( V_487 ) + 1 < V_489 ) {
F_33 ( V_8 , L_73 , V_487 ) ;
return - V_86 ;
}
V_6 -> V_224 = F_160 ( V_8 , V_487 ) ;
if ( F_115 ( V_6 -> V_224 ) )
return F_116 ( V_6 -> V_224 ) ;
V_193 = F_161 ( V_300 , L_74 ) ;
if ( V_193 > 0 )
V_6 -> V_194 . V_15 . V_193 = V_193 ;
V_193 = F_161 ( V_300 , L_75 ) ;
if ( V_193 > 0 )
V_6 -> V_203 . V_15 . V_193 = V_193 ;
V_193 = F_161 ( V_300 , L_76 ) ;
if ( V_193 > 0 )
V_6 -> V_94 . V_15 . V_193 = V_193 ;
V_193 = F_161 ( V_300 , L_77 ) ;
if ( V_193 > 0 )
V_6 -> V_377 = V_193 ;
F_3 ( V_6 ) ;
V_19 = F_151 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_133 ( V_6 ) ;
if ( V_19 )
return V_19 ;
F_162 ( V_300 , V_6 ) ;
return F_150 ( V_6 ) ;
}
static int F_163 ( struct V_305 * V_300 )
{
struct V_5 * V_6 = F_108 ( V_300 ) ;
F_61 ( V_6 ) ;
return 0 ;
}
static int T_11 F_164 ( void )
{
struct V_304 * V_490 ;
int V_19 ;
V_490 = F_165 ( NULL , V_491 ) ;
if ( ! V_490 )
return 0 ;
F_109 ( V_490 ) ;
V_19 = F_166 ( & V_492 ) ;
if ( V_19 )
return V_19 ;
return F_167 ( & V_493 , & V_276 ) ;
}
static void T_12 F_168 ( void )
{
return F_169 ( & V_492 ) ;
}
