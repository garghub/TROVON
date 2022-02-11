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
case V_62 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_63 << V_64 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_53 ? V_65 : 0 ;
V_34 [ 1 ] |= V_30 -> V_59 . V_48 & V_66 ;
break;
case V_67 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_60 << V_61 ;
case V_68 :
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_59 . V_63 << V_64 ;
break;
case V_69 :
V_34 [ 0 ] |= V_30 -> V_70 ? V_71 : 0 ;
V_34 [ 0 ] |= V_30 -> V_72 . V_73 << V_74 ;
V_34 [ 0 ] |= ( T_4 ) V_30 -> V_72 . V_44 << V_75 ;
V_34 [ 1 ] |= V_30 -> V_72 . V_76 << V_77 ;
switch ( V_30 -> V_72 . V_78 ) {
case V_79 :
V_34 [ 1 ] |= V_80 ;
break;
case V_81 :
V_34 [ 1 ] |= V_82 ;
break;
case V_83 :
V_34 [ 1 ] |= V_84 ;
break;
default:
return - V_85 ;
}
break;
case V_86 :
V_34 [ 0 ] |= V_87 ;
break;
default:
return - V_88 ;
}
return 0 ;
}
static void F_32 ( struct V_5 * V_6 )
{
static const char * V_89 [] = {
[ V_90 ] = L_2 ,
[ V_91 ] = L_3 ,
[ V_92 ] = L_4 ,
} ;
int V_7 ;
T_4 V_34 [ V_36 ] ;
struct V_14 * V_15 = & V_6 -> V_93 . V_15 ;
T_1 V_17 = F_11 ( V_15 -> V_18 ) ;
T_1 V_94 = V_17 >> V_95 & V_96 ;
struct V_35 V_97 = {
. V_37 = V_86 ,
} ;
F_33 ( V_6 -> V_8 , L_5 , V_17 ,
V_89 [ V_94 ] ) ;
switch ( V_94 ) {
case V_91 :
break;
case V_92 :
F_33 ( V_6 -> V_8 , L_6 ) ;
case V_90 :
return;
}
F_28 ( V_34 , F_27 ( V_15 , V_94 ) , V_15 -> V_32 ) ;
F_33 ( V_6 -> V_8 , L_7 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_34 ) ; ++ V_7 )
F_33 ( V_6 -> V_8 , L_8 , ( unsigned long long ) V_34 [ V_7 ] ) ;
if ( F_31 ( V_34 , & V_97 ) ) {
F_33 ( V_6 -> V_8 , L_9 ) ;
return;
}
F_24 ( V_34 , F_27 ( V_15 , V_94 ) , V_15 -> V_32 ) ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_35 * V_30 )
{
T_1 V_22 ;
T_4 V_34 [ V_36 ] ;
bool V_23 = ! ! ( V_6 -> V_98 & V_99 ) ;
struct V_14 * V_15 = & V_6 -> V_93 . V_15 ;
if ( F_31 ( V_34 , V_30 ) ) {
F_36 ( V_6 -> V_8 , L_10 ,
V_30 -> V_37 ) ;
return;
}
F_37 ( & V_6 -> V_93 . V_100 ) ;
while ( V_22 = V_15 -> V_16 + 1 , F_26 ( V_15 , V_34 ) == - V_31 ) {
if ( F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_11 ) ;
}
if ( V_30 -> V_37 == V_86 && F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_12 ) ;
F_39 ( & V_6 -> V_93 . V_100 ) ;
}
static T_4 F_40 ( T_4 V_101 )
{
T_4 V_102 = 0 ;
V_102 |= F_41 ( V_101 , V_103 ) ;
V_102 |= F_41 ( V_101 , V_104 ) ;
V_102 |= F_41 ( V_101 , V_105 ) ;
V_102 |= F_41 ( V_101 , V_106 ) ;
V_102 |= F_41 ( V_101 , V_107 ) ;
V_102 |= F_41 ( V_101 , V_108 ) ;
V_102 |= F_41 ( V_101 , V_109 ) ;
V_102 |= F_41 ( V_101 , V_110 ) ;
V_102 |= F_41 ( V_101 , V_111 ) ;
return V_102 ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_112 * V_113 )
{
T_4 V_102 ;
V_102 = F_40 ( V_113 -> V_114 . V_101 ) |
#ifdef F_43
V_115 |
#endif
V_116 | V_117 | V_118 |
V_119 | ( T_4 ) V_113 -> V_114 . V_60 << V_120 |
V_121 ;
V_113 -> V_122 [ 0 ] = F_25 ( V_102 ) ;
V_102 = V_113 -> V_114 . V_123 & V_124 << V_125 ;
V_113 -> V_122 [ 1 ] = F_25 ( V_102 ) ;
V_113 -> V_122 [ 3 ] = F_25 ( V_113 -> V_114 . V_126 << V_127 ) ;
}
static void
F_44 ( T_3 * V_27 , struct V_128 * V_129 )
{
T_4 V_102 = 0 ;
V_102 |= ( V_129 -> V_130 & V_131 )
<< V_132 ;
V_102 |= V_129 -> V_133 &
V_134 << V_135 ;
* V_27 = F_25 ( V_102 ) ;
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
V_34 . V_37 = V_86 ;
F_35 ( V_6 , & V_34 ) ;
}
static void F_46 ( struct V_5 * V_6 , T_1 V_44 ,
T_3 * V_27 , struct V_136 * V_137 )
{
T_4 V_102 = F_29 ( V_27 [ 0 ] ) ;
bool V_138 = false ;
struct V_35 V_139 = {
. V_37 = V_42 ,
. V_43 = {
. V_44 = V_44 ,
} ,
} ;
if ( V_102 & V_140 ) {
T_4 V_113 ;
V_113 = V_102 & V_141 << V_142 ;
switch ( V_113 ) {
case V_143 :
break;
case V_144 :
case V_145 :
V_138 = true ;
break;
default:
F_47 () ;
}
}
V_102 &= ~ ( V_141 << V_142 ) ;
if ( V_137 -> V_146 )
V_102 |= V_140 ;
else
V_102 &= ~ V_140 ;
if ( V_137 -> V_147 ) {
V_102 |= V_148 ? V_149
: V_143 ;
V_27 [ 0 ] = F_25 ( V_102 ) ;
V_27 [ 2 ] = 0 ;
if ( V_138 )
F_45 ( V_6 , V_44 ) ;
return;
}
if ( V_137 -> V_150 ) {
F_48 ( V_138 ) ;
V_27 [ 1 ] = F_25 (
V_151
<< V_152 |
V_151
<< V_153 |
V_154 << V_155 |
V_156 |
#ifdef F_49
V_157 << V_158 |
#endif
V_159 << V_160 ) ;
V_102 |= ( V_137 -> V_150 -> V_161 & V_162
<< V_163 ) |
V_144 ;
}
if ( V_137 -> V_164 ) {
F_48 ( V_138 ) ;
V_27 [ 2 ] = F_25 (
V_137 -> V_164 -> V_63 << V_165 |
( V_137 -> V_164 -> V_166 & V_167 )
<< V_168 |
#ifdef F_43
V_169 |
#endif
V_170 | V_171 |
V_172 ) ;
V_27 [ 3 ] = F_25 ( V_137 -> V_164 -> V_173 &
V_174 << V_175 ) ;
V_102 |= V_145 ;
}
F_45 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_25 ( V_102 ) ;
F_45 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_176 ) )
F_35 ( V_6 , & V_139 ) ;
}
static void F_50 ( T_4 * V_177 , unsigned int V_178 )
{
unsigned int V_7 ;
struct V_136 V_137 = {
. V_146 = true ,
. V_147 = true ,
} ;
for ( V_7 = 0 ; V_7 < V_178 ; ++ V_7 ) {
F_46 ( NULL , - 1 , V_177 , & V_137 ) ;
V_177 += V_179 ;
}
}
static int F_51 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_177 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
struct V_128 * V_129 = & V_113 -> V_182 [ V_44 >> V_183 ] ;
if ( V_129 -> V_184 )
return 0 ;
V_46 = 1 << ( V_183 + F_52 ( V_179 ) + 3 ) ;
V_177 = & V_113 -> V_177 [ ( V_44 >> V_183 ) * V_185 ] ;
V_129 -> V_130 = V_183 + 1 ;
V_129 -> V_184 = F_53 ( V_6 -> V_8 , V_46 , & V_129 -> V_133 ,
V_186 ) ;
if ( ! V_129 -> V_184 ) {
F_33 ( V_6 -> V_8 ,
L_13 ,
V_44 ) ;
return - V_187 ;
}
F_50 ( V_129 -> V_184 , 1 << V_183 ) ;
F_44 ( V_177 , V_129 ) ;
return 0 ;
}
static T_6 F_54 ( int V_188 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_189 . V_15 ;
T_4 V_190 [ V_191 ] ;
while ( ! F_30 ( V_15 , V_190 ) ) {
T_7 V_192 = V_190 [ 0 ] >> V_193 & V_194 ;
F_55 ( V_6 -> V_8 , L_14 , V_192 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_190 ) ; ++ V_7 )
F_55 ( V_6 -> V_8 , L_8 ,
( unsigned long long ) V_190 [ V_7 ] ) ;
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_195 ;
}
static T_6 F_56 ( int V_188 , void * V_8 )
{
T_6 V_19 = V_196 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_189 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_15 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_197 ;
return V_19 ;
}
static T_6 F_57 ( int V_188 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_198 . V_15 ;
T_4 V_190 [ V_199 ] ;
while ( ! F_30 ( V_15 , V_190 ) ) {
T_1 V_44 , V_73 ;
T_8 V_76 ;
bool V_200 , V_201 ;
V_44 = V_190 [ 0 ] >> V_202 & V_203 ;
V_200 = V_190 [ 0 ] & V_204 ;
V_73 = V_200 ? V_190 [ 0 ] >> V_205 & V_206 : 0 ;
V_201 = V_190 [ 0 ] & V_207 ;
V_76 = V_190 [ 1 ] >> V_208 & V_209 ;
F_55 ( V_6 -> V_8 , L_16 ) ;
F_55 ( V_6 -> V_8 ,
L_17 ,
V_44 , V_73 , V_76 , V_201 ? L_18 : L_19 ,
V_190 [ 0 ] & V_210 ? L_19 : L_20 ,
V_190 [ 0 ] & V_211 ? L_21 : L_19 ,
V_190 [ 0 ] & V_212 ? L_22 : L_19 ,
V_190 [ 0 ] & V_213 ? L_23 : L_19 ,
V_190 [ 1 ] & V_214 << V_215 ) ;
if ( V_201 ) {
struct V_35 V_34 = {
. V_37 = V_69 ,
. V_70 = V_200 ,
. V_72 = {
. V_44 = V_44 ,
. V_73 = V_73 ,
. V_76 = V_76 ,
. V_78 = V_79 ,
} ,
} ;
F_35 ( V_6 , & V_34 ) ;
}
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_195 ;
}
static T_6 F_58 ( int V_188 , void * V_8 )
{
T_6 V_19 = V_196 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_198 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_24 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_197 ;
return V_19 ;
}
static T_6 F_59 ( int V_188 , void * V_8 )
{
return V_195 ;
}
static T_6 F_60 ( int V_188 , void * V_8 )
{
T_1 V_216 , V_217 ;
struct V_5 * V_6 = V_8 ;
V_216 = F_11 ( V_6 -> V_218 + V_219 ) ;
V_217 = F_11 ( V_6 -> V_218 + V_220 ) ;
V_216 ^= V_217 ;
if ( ! ( V_216 & V_221 ) )
return V_197 ;
F_36 ( V_6 -> V_8 ,
L_25 ,
V_216 ) ;
if ( V_216 & V_222 ) {
F_33 ( V_6 -> V_8 , L_26 ) ;
F_61 ( V_6 ) ;
}
if ( V_216 & V_223 )
F_36 ( V_6 -> V_8 , L_27 ) ;
if ( V_216 & V_224 ) {
F_36 ( V_6 -> V_8 , L_28 ) ;
F_58 ( V_188 , V_6 -> V_8 ) ;
}
if ( V_216 & V_225 ) {
F_36 ( V_6 -> V_8 , L_29 ) ;
F_56 ( V_188 , V_6 -> V_8 ) ;
}
if ( V_216 & V_226 ) {
F_36 ( V_6 -> V_8 , L_30 ) ;
F_59 ( V_188 , V_6 -> V_8 ) ;
}
if ( V_216 & V_227 )
F_33 ( V_6 -> V_8 , L_31 ) ;
if ( V_216 & V_228 )
F_33 ( V_6 -> V_8 , L_32 ) ;
if ( V_216 & V_229 )
F_32 ( V_6 ) ;
F_14 ( V_216 , V_6 -> V_218 + V_220 ) ;
return V_195 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_86 ;
F_35 ( V_6 , & V_34 ) ;
}
static void F_63 ( void * V_230 )
{
struct V_1 * V_231 = V_230 ;
F_62 ( V_231 -> V_6 ) ;
}
static void F_64 ( void * V_230 )
{
struct V_1 * V_231 = V_230 ;
struct V_5 * V_6 = V_231 -> V_6 ;
struct V_35 V_34 ;
if ( V_231 -> V_232 == V_233 ) {
V_34 . V_37 = V_67 ;
V_34 . V_59 . V_60 = V_231 -> V_150 . V_114 . V_60 ;
V_34 . V_59 . V_63 = 0 ;
} else {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_63 = V_231 -> V_164 . V_63 ;
}
F_35 ( V_6 , & V_34 ) ;
F_62 ( V_6 ) ;
}
static void F_65 ( unsigned long V_234 , T_5 V_46 ,
bool V_53 , void * V_230 )
{
struct V_1 * V_231 = V_230 ;
struct V_5 * V_6 = V_231 -> V_6 ;
struct V_35 V_34 = {
. V_59 = {
. V_53 = V_53 ,
. V_48 = V_234 ,
} ,
} ;
if ( V_231 -> V_232 == V_233 ) {
V_34 . V_37 = V_58 ;
V_34 . V_59 . V_60 = V_231 -> V_150 . V_114 . V_60 ;
} else {
V_34 . V_37 = V_62 ;
V_34 . V_59 . V_63 = V_231 -> V_164 . V_63 ;
}
F_35 ( V_6 , & V_34 ) ;
}
static void F_66 ( void * V_48 , T_5 V_46 , void * V_230 )
{
struct V_1 * V_231 = V_230 ;
struct V_5 * V_6 = V_231 -> V_6 ;
unsigned long V_235 = ( unsigned long ) V_48 & ~ V_236 ;
if ( V_6 -> V_98 & V_237 ) {
F_67 ( V_238 ) ;
} else {
T_9 V_239 ;
struct V_240 * V_8 = V_6 -> V_8 ;
V_239 = F_68 ( V_8 , F_69 ( V_48 ) , V_235 , V_46 ,
V_241 ) ;
if ( F_70 ( V_8 , V_239 ) )
F_33 ( V_8 , L_33 , V_48 ) ;
else
F_71 ( V_8 , V_239 , V_46 , V_241 ) ;
}
}
static bool F_72 ( enum V_242 V_243 )
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
static struct V_2 * F_73 ( unsigned type )
{
struct V_1 * V_231 ;
if ( type != V_247 )
return NULL ;
V_231 = F_74 ( sizeof( * V_231 ) , V_186 ) ;
if ( ! V_231 )
return NULL ;
F_75 ( & V_231 -> V_248 ) ;
F_76 ( & V_231 -> V_249 ) ;
return & V_231 -> V_4 ;
}
static int F_77 ( unsigned long * V_250 , int V_130 )
{
int V_94 , V_46 = 1 << V_130 ;
do {
V_94 = F_78 ( V_250 , V_46 ) ;
if ( V_94 == V_46 )
return - V_31 ;
} while ( F_79 ( V_94 , V_250 ) );
return V_94 ;
}
static void F_80 ( unsigned long * V_250 , int V_94 )
{
F_81 ( V_94 , V_250 ) ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_231 -> V_6 ;
F_83 ( V_231 -> V_251 ) ;
if ( V_231 -> V_232 == V_233 ) {
struct V_112 * V_113 = & V_231 -> V_150 ;
if ( V_113 -> V_122 ) {
F_84 ( V_231 -> V_6 -> V_8 ,
V_252 << 3 ,
V_113 -> V_122 ,
V_113 -> V_161 ) ;
F_80 ( V_6 -> V_253 , V_113 -> V_114 . V_60 ) ;
}
} else {
struct V_254 * V_113 = & V_231 -> V_164 ;
if ( V_113 -> V_63 )
F_80 ( V_6 -> V_255 , V_113 -> V_63 ) ;
}
F_85 ( V_231 ) ;
}
static int F_86 ( struct V_1 * V_231 ,
struct V_256 * V_257 )
{
int V_19 ;
T_8 V_60 ;
struct V_5 * V_6 = V_231 -> V_6 ;
struct V_112 * V_113 = & V_231 -> V_150 ;
V_60 = F_77 ( V_6 -> V_253 , V_6 -> V_258 ) ;
if ( F_87 ( V_60 ) )
return V_60 ;
V_113 -> V_122 = F_53 ( V_6 -> V_8 , V_252 << 3 ,
& V_113 -> V_161 , V_186 ) ;
if ( ! V_113 -> V_122 ) {
F_36 ( V_6 -> V_8 , L_34 ) ;
goto V_259;
}
V_113 -> V_114 . V_60 = V_60 ;
V_113 -> V_114 . V_123 = V_257 -> V_260 . V_123 [ 0 ] ;
V_113 -> V_114 . V_101 = V_257 -> V_260 . V_101 ;
V_113 -> V_114 . V_126 = V_257 -> V_260 . V_126 [ 0 ] ;
return 0 ;
V_259:
F_80 ( V_6 -> V_253 , V_60 ) ;
return V_19 ;
}
static int F_88 ( struct V_1 * V_231 ,
struct V_256 * V_257 )
{
T_8 V_63 ;
struct V_5 * V_6 = V_231 -> V_6 ;
struct V_254 * V_113 = & V_231 -> V_164 ;
V_63 = F_77 ( V_6 -> V_255 , V_6 -> V_261 ) ;
if ( F_87 ( V_63 ) )
return V_63 ;
V_113 -> V_63 = V_63 ;
V_113 -> V_173 = V_257 -> V_262 . V_173 ;
V_113 -> V_166 = V_257 -> V_262 . V_166 ;
return 0 ;
}
static int F_89 ( struct V_2 * V_4 )
{
int V_19 ;
unsigned long V_263 , V_264 ;
enum V_265 V_266 ;
struct V_256 V_257 ;
struct V_267 * V_251 ;
int (* F_90)( struct V_1 * ,
struct V_256 * );
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_231 -> V_6 ;
if ( ! ( V_6 -> V_98 & V_268 ) )
V_231 -> V_232 = V_269 ;
if ( ! ( V_6 -> V_98 & V_270 ) )
V_231 -> V_232 = V_233 ;
switch ( V_231 -> V_232 ) {
case V_233 :
V_263 = V_271 ;
V_264 = V_6 -> V_263 ;
V_266 = V_272 ;
F_90 = F_86 ;
break;
case V_273 :
case V_269 :
V_263 = V_6 -> V_263 ;
V_264 = V_6 -> V_264 ;
V_266 = V_274 ;
F_90 = F_88 ;
break;
default:
return - V_85 ;
}
V_257 = (struct V_256 ) {
. V_275 = V_276 . V_275 ,
. V_263 = V_263 ,
. V_264 = V_264 ,
. V_277 = & V_278 ,
} ;
V_251 = F_91 ( V_266 , & V_257 , V_231 ) ;
if ( ! V_251 )
return - V_187 ;
V_276 . V_275 = V_257 . V_275 ;
V_231 -> V_251 = V_251 ;
V_19 = F_90 ( V_231 , & V_257 ) ;
if ( F_87 ( V_19 ) )
F_83 ( V_251 ) ;
return V_19 ;
}
static struct V_279 * F_92 ( struct V_240 * V_8 )
{
struct V_280 * V_281 ;
struct V_279 * V_282 ;
V_281 = F_93 ( V_8 ) ;
if ( ! V_281 )
return NULL ;
V_282 = F_94 ( V_281 ) ;
F_95 ( V_281 ) ;
return V_282 ;
}
static T_3 * F_96 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_283 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
if ( V_6 -> V_98 & V_284 ) {
struct V_128 * V_182 ;
int V_94 ;
V_94 = ( V_44 >> V_183 ) * V_185 ;
V_182 = & V_113 -> V_182 [ V_94 ] ;
V_94 = ( V_44 & ( ( 1 << V_183 ) - 1 ) ) * V_179 ;
V_283 = & V_182 -> V_184 [ V_94 ] ;
} else {
V_283 = & V_113 -> V_177 [ V_44 * V_179 ] ;
}
return V_283 ;
}
static int F_97 ( struct V_279 * V_282 )
{
int V_7 ;
struct V_1 * V_231 = V_282 -> V_4 ;
struct V_136 * V_137 = & V_282 -> V_137 ;
struct V_5 * V_6 = V_282 -> V_6 ;
if ( V_231 -> V_232 == V_233 ) {
V_137 -> V_150 = & V_231 -> V_150 ;
V_137 -> V_164 = NULL ;
F_42 ( V_6 , V_137 -> V_150 ) ;
} else {
V_137 -> V_150 = NULL ;
V_137 -> V_164 = & V_231 -> V_164 ;
}
for ( V_7 = 0 ; V_7 < V_282 -> V_285 ; ++ V_7 ) {
T_1 V_44 = V_282 -> V_286 [ V_7 ] ;
T_3 * V_283 = F_96 ( V_6 , V_44 ) ;
F_46 ( V_6 , V_44 , V_283 , V_137 ) ;
}
return 0 ;
}
static int F_98 ( struct V_2 * V_4 , struct V_240 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_279 * V_282 = F_92 ( V_8 ) ;
if ( ! V_282 )
return - V_88 ;
if ( V_282 -> V_4 && V_282 -> V_4 != V_231 )
return - V_287 ;
V_6 = V_282 -> V_6 ;
F_99 ( & V_231 -> V_248 ) ;
if ( ! V_231 -> V_6 ) {
V_231 -> V_6 = V_6 ;
V_19 = F_89 ( V_4 ) ;
if ( V_19 ) {
V_231 -> V_6 = NULL ;
goto V_288;
}
} else if ( V_231 -> V_6 != V_6 ) {
F_33 ( V_8 ,
L_35 ,
F_100 ( V_231 -> V_6 -> V_8 ) ,
F_100 ( V_6 -> V_8 ) ) ;
V_19 = - V_289 ;
goto V_288;
}
if ( V_282 -> V_4 )
goto V_288;
V_282 -> V_4 = V_231 ;
V_282 -> V_137 . V_147 = false ;
V_19 = F_97 ( V_282 ) ;
if ( F_87 ( V_19 ) )
V_282 -> V_4 = NULL ;
V_288:
F_101 ( & V_231 -> V_248 ) ;
return V_19 ;
}
static void F_102 ( struct V_2 * V_4 , struct V_240 * V_8 )
{
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_279 * V_282 = F_92 ( V_8 ) ;
F_48 ( ! V_231 ) ;
F_48 ( ! V_282 ) ;
F_99 ( & V_231 -> V_248 ) ;
F_48 ( V_282 -> V_4 != V_231 ) ;
V_282 -> V_137 . V_147 = true ;
if ( F_87 ( F_97 ( V_282 ) ) )
F_36 ( V_8 , L_36 ) ;
V_282 -> V_4 = NULL ;
F_101 ( & V_231 -> V_248 ) ;
}
static int F_103 ( struct V_2 * V_4 , unsigned long V_234 ,
T_10 V_290 , T_5 V_46 , int V_291 )
{
int V_19 ;
unsigned long V_292 ;
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_267 * V_293 = V_231 -> V_251 ;
if ( ! V_293 )
return - V_294 ;
F_104 ( & V_231 -> V_249 , V_292 ) ;
V_19 = V_293 -> V_250 ( V_293 , V_234 , V_290 , V_46 , V_291 ) ;
F_105 ( & V_231 -> V_249 , V_292 ) ;
return V_19 ;
}
static T_5
F_106 ( struct V_2 * V_4 , unsigned long V_234 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_292 ;
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_267 * V_293 = V_231 -> V_251 ;
if ( ! V_293 )
return 0 ;
F_104 ( & V_231 -> V_249 , V_292 ) ;
V_19 = V_293 -> V_295 ( V_293 , V_234 , V_46 ) ;
F_105 ( & V_231 -> V_249 , V_292 ) ;
return V_19 ;
}
static T_10
F_107 ( struct V_2 * V_4 , T_9 V_234 )
{
T_10 V_19 ;
unsigned long V_292 ;
struct V_1 * V_231 = F_1 ( V_4 ) ;
struct V_267 * V_293 = V_231 -> V_251 ;
if ( ! V_293 )
return 0 ;
F_104 ( & V_231 -> V_249 , V_292 ) ;
V_19 = V_293 -> V_296 ( V_293 , V_234 ) ;
F_105 ( & V_231 -> V_249 , V_292 ) ;
return V_19 ;
}
static int F_108 ( struct V_297 * V_298 , T_8 V_299 , void * V_300 )
{
* ( T_1 * ) V_300 = V_299 ;
return 0 ;
}
static void F_109 ( void * V_301 )
{
F_85 ( V_301 ) ;
}
static struct V_5 * F_110 ( struct V_297 * V_298 )
{
struct V_302 * V_9 ;
struct V_5 * V_303 , * V_6 = NULL ;
struct V_304 * V_305 = V_298 -> V_305 ;
while ( ! F_111 ( V_305 ) )
V_305 = V_305 -> V_306 ;
V_9 = F_112 ( V_305 -> V_307 -> V_306 -> V_9 , L_37 , 0 ) ;
if ( ! V_9 )
return NULL ;
F_37 ( & V_308 ) ;
F_113 (curr, &arm_smmu_devices, list) {
if ( V_303 -> V_8 -> V_9 == V_9 ) {
V_6 = V_303 ;
break;
}
}
F_39 ( & V_308 ) ;
F_114 ( V_9 ) ;
return V_6 ;
}
static bool F_115 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_309 = V_6 -> V_181 . V_310 ;
if ( V_6 -> V_98 & V_284 )
V_309 *= 1UL << V_183 ;
return V_44 < V_309 ;
}
static int F_116 ( struct V_240 * V_8 )
{
int V_7 , V_19 ;
T_1 V_44 , * V_286 ;
struct V_297 * V_298 ;
struct V_280 * V_281 ;
struct V_279 * V_282 ;
struct V_5 * V_6 ;
if ( ! F_117 ( V_8 ) )
return - V_294 ;
V_298 = F_118 ( V_8 ) ;
V_281 = F_119 ( V_8 ) ;
if ( F_120 ( V_281 ) )
return F_121 ( V_281 ) ;
V_282 = F_94 ( V_281 ) ;
if ( ! V_282 ) {
V_6 = F_110 ( V_298 ) ;
if ( ! V_6 ) {
V_19 = - V_88 ;
goto V_311;
}
V_282 = F_74 ( sizeof( * V_282 ) , V_186 ) ;
if ( ! V_282 ) {
V_19 = - V_187 ;
goto V_311;
}
V_282 -> V_137 . V_146 = true ;
V_282 -> V_6 = V_6 ;
F_122 ( V_281 , V_282 ,
F_109 ) ;
} else {
V_6 = V_282 -> V_6 ;
}
F_123 ( V_298 , F_108 , & V_44 ) ;
for ( V_7 = 0 ; V_7 < V_282 -> V_285 ; ++ V_7 ) {
if ( V_282 -> V_286 [ V_7 ] == V_44 )
return 0 ;
}
if ( ! F_115 ( V_6 , V_44 ) ) {
V_19 = - V_312 ;
goto V_311;
}
if ( V_6 -> V_98 & V_284 ) {
V_19 = F_51 ( V_6 , V_44 ) ;
if ( V_19 )
goto V_311;
}
V_282 -> V_285 ++ ;
V_286 = F_124 ( V_282 -> V_286 , V_282 -> V_285 * sizeof( * V_286 ) ,
V_186 ) ;
if ( ! V_286 ) {
V_282 -> V_285 -- ;
V_19 = - V_187 ;
goto V_311;
}
V_286 [ V_282 -> V_285 - 1 ] = V_44 ;
V_282 -> V_286 = V_286 ;
return 0 ;
V_311:
F_95 ( V_281 ) ;
return V_19 ;
}
static void F_125 ( struct V_240 * V_8 )
{
F_126 ( V_8 ) ;
}
static int F_127 ( struct V_2 * V_4 ,
enum V_313 V_314 , void * V_301 )
{
struct V_1 * V_231 = F_1 ( V_4 ) ;
switch ( V_314 ) {
case V_315 :
* ( int * ) V_301 = ( V_231 -> V_232 == V_273 ) ;
return 0 ;
default:
return - V_294 ;
}
}
static int F_128 ( struct V_2 * V_4 ,
enum V_313 V_314 , void * V_301 )
{
int V_19 = 0 ;
struct V_1 * V_231 = F_1 ( V_4 ) ;
F_99 ( & V_231 -> V_248 ) ;
switch ( V_314 ) {
case V_315 :
if ( V_231 -> V_6 ) {
V_19 = - V_316 ;
goto V_288;
}
if ( * ( int * ) V_301 )
V_231 -> V_232 = V_273 ;
else
V_231 -> V_232 = V_233 ;
break;
default:
V_19 = - V_294 ;
}
V_288:
F_101 ( & V_231 -> V_248 ) ;
return V_19 ;
}
static int F_129 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_317 ,
unsigned long V_318 ,
T_5 V_319 )
{
T_5 V_320 = ( ( 1 << V_15 -> V_321 ) * V_319 ) << 3 ;
V_15 -> V_218 = F_130 ( V_6 -> V_8 , V_320 , & V_15 -> V_322 , V_186 ) ;
if ( ! V_15 -> V_218 ) {
F_33 ( V_6 -> V_8 , L_38 ,
V_320 ) ;
return - V_187 ;
}
V_15 -> V_20 = V_6 -> V_218 + V_317 ;
V_15 -> V_18 = V_6 -> V_218 + V_318 ;
V_15 -> V_32 = V_319 ;
V_15 -> V_323 = V_324 ;
V_15 -> V_323 |= V_15 -> V_322 & V_325 << V_326 ;
V_15 -> V_323 |= ( V_15 -> V_321 & V_327 )
<< V_328 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static void F_131 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
T_5 V_320 = ( ( 1 << V_15 -> V_321 ) * V_15 -> V_32 ) << 3 ;
F_84 ( V_6 -> V_8 , V_320 , V_15 -> V_218 , V_15 -> V_322 ) ;
}
static void F_132 ( struct V_5 * V_6 )
{
F_131 ( V_6 , & V_6 -> V_93 . V_15 ) ;
F_131 ( V_6 , & V_6 -> V_189 . V_15 ) ;
if ( V_6 -> V_98 & V_329 )
F_131 ( V_6 , & V_6 -> V_198 . V_15 ) ;
}
static int F_133 ( struct V_5 * V_6 )
{
int V_19 ;
F_76 ( & V_6 -> V_93 . V_100 ) ;
V_19 = F_129 ( V_6 , & V_6 -> V_93 . V_15 , V_330 ,
V_331 , V_36 ) ;
if ( V_19 )
goto V_332;
V_19 = F_129 ( V_6 , & V_6 -> V_189 . V_15 , V_333 ,
V_334 , V_191 ) ;
if ( V_19 )
goto V_335;
if ( ! ( V_6 -> V_98 & V_329 ) )
return 0 ;
V_19 = F_129 ( V_6 , & V_6 -> V_198 . V_15 , V_336 ,
V_337 , V_199 ) ;
if ( V_19 )
goto V_338;
return 0 ;
V_338:
F_131 ( V_6 , & V_6 -> V_189 . V_15 ) ;
V_335:
F_131 ( V_6 , & V_6 -> V_93 . V_15 ) ;
V_332:
return V_19 ;
}
static void F_134 ( struct V_5 * V_6 )
{
int V_7 ;
T_5 V_46 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
V_46 = 1 << ( V_183 + F_52 ( V_179 ) + 3 ) ;
for ( V_7 = 0 ; V_7 < V_113 -> V_310 ; ++ V_7 ) {
struct V_128 * V_129 = & V_113 -> V_182 [ V_7 ] ;
if ( ! V_129 -> V_184 )
continue;
F_84 ( V_6 -> V_8 , V_46 , V_129 -> V_184 ,
V_129 -> V_133 ) ;
}
}
static int F_135 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
T_5 V_46 = sizeof( * V_113 -> V_182 ) * V_113 -> V_310 ;
void * V_177 = V_6 -> V_181 . V_177 ;
V_113 -> V_182 = F_136 ( V_6 -> V_8 , V_46 , V_186 ) ;
if ( ! V_113 -> V_182 ) {
F_33 ( V_6 -> V_8 , L_39 ) ;
return - V_187 ;
}
for ( V_7 = 0 ; V_7 < V_113 -> V_310 ; ++ V_7 ) {
F_44 ( V_177 , & V_113 -> V_182 [ V_7 ] ) ;
V_177 += V_185 << 3 ;
}
return 0 ;
}
static int F_137 ( struct V_5 * V_6 )
{
void * V_177 ;
T_4 V_339 ;
T_1 V_46 , V_340 ;
int V_19 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
V_46 = V_341 - ( F_52 ( V_185 ) + 3 ) ;
V_46 = F_138 ( V_46 , V_6 -> V_342 - V_183 ) ;
V_113 -> V_310 = 1 << V_46 ;
V_46 += V_183 ;
if ( V_46 < V_6 -> V_342 )
F_36 ( V_6 -> V_8 ,
L_40 ,
V_46 , V_6 -> V_342 ) ;
V_340 = V_113 -> V_310 * ( V_185 << 3 ) ;
V_177 = F_53 ( V_6 -> V_8 , V_340 , & V_113 -> V_343 ,
V_186 ) ;
if ( ! V_177 ) {
F_33 ( V_6 -> V_8 ,
L_41 ,
V_46 ) ;
return - V_187 ;
}
V_113 -> V_177 = V_177 ;
V_339 = V_344 ;
V_339 |= ( V_46 & V_345 )
<< V_346 ;
V_339 |= ( V_183 & V_347 )
<< V_348 ;
V_113 -> V_349 = V_339 ;
V_19 = F_135 ( V_6 ) ;
if ( V_19 )
F_84 ( V_6 -> V_8 ,
V_340 ,
V_177 ,
V_113 -> V_343 ) ;
return V_19 ;
}
static int F_139 ( struct V_5 * V_6 )
{
void * V_177 ;
T_4 V_339 ;
T_1 V_46 ;
struct V_180 * V_113 = & V_6 -> V_181 ;
V_46 = ( 1 << V_6 -> V_342 ) * ( V_179 << 3 ) ;
V_177 = F_53 ( V_6 -> V_8 , V_46 , & V_113 -> V_343 ,
V_186 ) ;
if ( ! V_177 ) {
F_33 ( V_6 -> V_8 ,
L_42 ,
V_46 ) ;
return - V_187 ;
}
V_113 -> V_177 = V_177 ;
V_113 -> V_310 = 1 << V_6 -> V_342 ;
V_339 = V_350 ;
V_339 |= ( V_6 -> V_342 & V_345 )
<< V_346 ;
V_113 -> V_349 = V_339 ;
F_50 ( V_177 , V_113 -> V_310 ) ;
return 0 ;
}
static int F_140 ( struct V_5 * V_6 )
{
T_4 V_339 ;
int V_19 ;
if ( V_6 -> V_98 & V_284 )
V_19 = F_137 ( V_6 ) ;
else
V_19 = F_139 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = V_6 -> V_181 . V_343 &
V_351 << V_352 ;
V_339 |= V_353 ;
V_6 -> V_181 . V_354 = V_339 ;
F_141 ( 0 , V_6 -> V_255 ) ;
return 0 ;
}
static void F_142 ( struct V_5 * V_6 )
{
struct V_180 * V_113 = & V_6 -> V_181 ;
T_1 V_46 = V_113 -> V_310 ;
if ( V_6 -> V_98 & V_284 ) {
F_134 ( V_6 ) ;
V_46 *= V_185 << 3 ;
} else {
V_46 *= V_179 * 3 ;
}
F_84 ( V_6 -> V_8 , V_46 , V_113 -> V_177 , V_113 -> V_343 ) ;
}
static int F_143 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_133 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_140 ( V_6 ) ;
if ( V_19 )
goto V_355;
return 0 ;
V_355:
F_132 ( V_6 ) ;
return V_19 ;
}
static void F_144 ( struct V_5 * V_6 )
{
F_142 ( V_6 ) ;
F_132 ( V_6 ) ;
}
static int F_145 ( struct V_5 * V_6 , T_1 V_102 ,
unsigned int V_356 , unsigned int V_357 )
{
T_1 V_339 ;
F_146 ( V_102 , V_6 -> V_218 + V_356 ) ;
return F_147 ( V_6 -> V_218 + V_357 , V_339 , V_339 == V_102 ,
1 , V_25 ) ;
}
static int F_148 ( struct V_5 * V_6 )
{
int V_19 , V_188 ;
V_19 = F_145 ( V_6 , 0 , V_358 ,
V_359 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_43 ) ;
return V_19 ;
}
F_149 ( 0 , V_6 -> V_218 + V_360 ) ;
F_149 ( 0 , V_6 -> V_218 + V_361 ) ;
V_188 = V_6 -> V_189 . V_15 . V_188 ;
if ( V_188 ) {
V_19 = F_150 ( V_6 -> V_8 , V_188 ,
F_56 ,
F_54 ,
0 , L_44 , V_6 ) ;
if ( F_87 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_45 ) ;
}
V_188 = V_6 -> V_93 . V_15 . V_188 ;
if ( V_188 ) {
V_19 = F_151 ( V_6 -> V_8 , V_188 ,
F_59 , 0 ,
L_46 , V_6 ) ;
if ( F_87 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_47 ) ;
}
V_188 = V_6 -> V_362 ;
if ( V_188 ) {
V_19 = F_151 ( V_6 -> V_8 , V_188 , F_60 ,
0 , L_48 , V_6 ) ;
if ( F_87 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_49 ) ;
}
if ( V_6 -> V_98 & V_329 ) {
F_149 ( 0 , V_6 -> V_218 + V_363 ) ;
V_188 = V_6 -> V_198 . V_15 . V_188 ;
if ( V_188 ) {
V_19 = F_150 ( V_6 -> V_8 , V_188 ,
F_58 ,
F_57 ,
0 , L_50 ,
V_6 ) ;
if ( F_87 ( V_19 ) )
F_36 ( V_6 -> V_8 ,
L_51 ) ;
}
}
V_19 = F_145 ( V_6 ,
V_364 |
V_365 ,
V_358 , V_359 ) ;
if ( V_19 )
F_36 ( V_6 -> V_8 , L_52 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_145 ( V_6 , 0 , V_366 , V_367 ) ;
if ( V_19 )
F_33 ( V_6 -> V_8 , L_53 ) ;
return V_19 ;
}
static int F_152 ( struct V_5 * V_6 )
{
int V_19 ;
T_1 V_339 , V_368 ;
struct V_35 V_34 ;
V_339 = F_11 ( V_6 -> V_218 + V_366 ) ;
if ( V_339 & V_369 )
F_36 ( V_6 -> V_8 , L_54 ) ;
V_19 = F_61 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_339 = ( V_370 << V_371 ) |
( V_372 << V_373 ) |
( V_372 << V_374 ) |
( V_370 << V_375 ) |
( V_372 << V_376 ) |
( V_372 << V_377 ) ;
F_146 ( V_339 , V_6 -> V_218 + V_378 ) ;
V_339 = V_379 | V_380 | V_381 ;
F_146 ( V_339 , V_6 -> V_218 + V_382 ) ;
F_149 ( V_6 -> V_181 . V_354 ,
V_6 -> V_218 + V_383 ) ;
F_146 ( V_6 -> V_181 . V_349 ,
V_6 -> V_218 + V_384 ) ;
F_149 ( V_6 -> V_93 . V_15 . V_323 , V_6 -> V_218 + V_385 ) ;
F_146 ( V_6 -> V_93 . V_15 . V_16 , V_6 -> V_218 + V_330 ) ;
F_146 ( V_6 -> V_93 . V_15 . V_17 , V_6 -> V_218 + V_331 ) ;
V_368 = V_386 ;
V_19 = F_145 ( V_6 , V_368 , V_366 ,
V_367 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_55 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_86 ;
F_35 ( V_6 , & V_34 ) ;
if ( V_6 -> V_98 & V_387 ) {
V_34 . V_37 = V_40 ;
F_35 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_86 ;
F_35 ( V_6 , & V_34 ) ;
F_149 ( V_6 -> V_189 . V_15 . V_323 , V_6 -> V_218 + V_388 ) ;
F_146 ( V_6 -> V_189 . V_15 . V_16 , V_6 -> V_218 + V_333 ) ;
F_146 ( V_6 -> V_189 . V_15 . V_17 , V_6 -> V_218 + V_334 ) ;
V_368 |= V_389 ;
V_19 = F_145 ( V_6 , V_368 , V_366 ,
V_367 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
if ( V_6 -> V_98 & V_329 ) {
F_149 ( V_6 -> V_198 . V_15 . V_323 ,
V_6 -> V_218 + V_390 ) ;
F_146 ( V_6 -> V_198 . V_15 . V_16 ,
V_6 -> V_218 + V_336 ) ;
F_146 ( V_6 -> V_198 . V_15 . V_17 ,
V_6 -> V_218 + V_337 ) ;
V_368 |= V_391 ;
V_19 = F_145 ( V_6 , V_368 , V_366 ,
V_367 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
}
V_19 = F_148 ( V_6 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
V_368 |= V_369 ;
V_19 = F_145 ( V_6 , V_368 , V_366 ,
V_367 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_59 ) ;
return V_19 ;
}
return 0 ;
}
static int F_153 ( struct V_5 * V_6 )
{
T_1 V_339 ;
bool V_392 ;
unsigned long V_275 = 0 ;
V_339 = F_11 ( V_6 -> V_218 + V_393 ) ;
if ( ( V_339 & V_394 << V_395 ) == V_396 )
V_6 -> V_98 |= V_284 ;
if ( V_339 & V_397 )
V_6 -> V_98 |= V_398 ;
switch ( V_339 & V_399 << V_400 ) {
case V_401 :
V_6 -> V_98 |= V_402 | V_403 ;
break;
#ifdef F_43
case V_404 :
V_6 -> V_98 |= V_403 ;
break;
#else
case V_405 :
V_6 -> V_98 |= V_402 ;
break;
#endif
default:
F_33 ( V_6 -> V_8 , L_60 ) ;
return - V_289 ;
}
if ( F_154 ( V_406 ) && V_339 & V_407 )
V_6 -> V_98 |= V_329 ;
if ( F_154 ( F_49 ) && V_339 & V_408 )
V_6 -> V_98 |= V_409 ;
if ( V_339 & V_410 )
V_6 -> V_98 |= V_99 ;
if ( V_339 & V_411 )
V_6 -> V_98 |= V_412 ;
if ( V_339 & V_413 )
V_6 -> V_98 |= V_387 ;
V_392 = F_155 ( V_6 -> V_8 -> V_9 ) ;
if ( V_392 )
V_6 -> V_98 |= V_237 ;
if ( ! ! ( V_339 & V_414 ) != V_392 )
F_36 ( V_6 -> V_8 , L_61 ,
V_392 ? L_62 : L_63 ) ;
if ( V_339 & V_415 )
V_6 -> V_98 |= V_416 ;
if ( V_339 & V_417 )
V_6 -> V_98 |= V_268 ;
if ( V_339 & V_418 )
V_6 -> V_98 |= V_270 ;
if ( ! ( V_339 & ( V_417 | V_418 ) ) ) {
F_33 ( V_6 -> V_8 , L_64 ) ;
return - V_289 ;
}
if ( ( V_339 & V_419 << V_420 ) < V_421 ) {
F_33 ( V_6 -> V_8 , L_65 ) ;
return - V_289 ;
}
V_6 -> V_258 = V_339 & V_422 ? 16 : 8 ;
V_6 -> V_261 = V_339 & V_423 ? 16 : 8 ;
V_339 = F_11 ( V_6 -> V_218 + V_424 ) ;
if ( V_339 & ( V_425 | V_426 | V_427 ) ) {
F_33 ( V_6 -> V_8 , L_66 ) ;
return - V_289 ;
}
V_6 -> V_93 . V_15 . V_321 = F_138 ( ( T_1 ) V_428 ,
V_339 >> V_429 & V_430 ) ;
if ( ! V_6 -> V_93 . V_15 . V_321 ) {
F_33 ( V_6 -> V_8 , L_67 ) ;
return - V_289 ;
}
V_6 -> V_189 . V_15 . V_321 = F_138 ( ( T_1 ) V_431 ,
V_339 >> V_432 & V_433 ) ;
V_6 -> V_198 . V_15 . V_321 = F_138 ( ( T_1 ) V_434 ,
V_339 >> V_435 & V_436 ) ;
V_6 -> V_437 = V_339 >> V_438 & V_439 ;
V_6 -> V_342 = V_339 >> V_440 & V_441 ;
V_339 = F_11 ( V_6 -> V_218 + V_442 ) ;
V_6 -> V_189 . V_443 = V_339 >> V_444
& V_445 ;
if ( V_339 & V_446 )
V_275 |= V_447 | V_448 ;
if ( V_339 & V_449 )
V_275 |= V_450 | V_451 ;
if ( V_339 & V_452 )
V_275 |= V_453 | V_454 | V_455 ;
V_276 . V_275 &= V_275 ;
switch ( V_339 & V_456 << V_457 ) {
case V_458 :
V_6 -> V_264 = 32 ;
break;
case V_459 :
V_6 -> V_264 = 36 ;
break;
case V_460 :
V_6 -> V_264 = 40 ;
break;
case V_461 :
V_6 -> V_264 = 42 ;
break;
case V_462 :
V_6 -> V_264 = 44 ;
break;
case V_463 :
V_6 -> V_264 = 48 ;
break;
default:
F_33 ( V_6 -> V_8 , L_68 ) ;
return - V_289 ;
}
if ( F_156 ( V_6 -> V_8 , F_157 ( V_6 -> V_264 ) ) )
F_36 ( V_6 -> V_8 ,
L_69 ) ;
if ( ! V_6 -> V_263 )
V_6 -> V_263 = V_6 -> V_264 ;
F_55 ( V_6 -> V_8 , L_70 ,
V_6 -> V_263 , V_6 -> V_264 , V_6 -> V_98 ) ;
return 0 ;
}
static int F_158 ( struct V_464 * V_298 )
{
int V_188 , V_19 ;
struct V_465 * V_466 ;
struct V_5 * V_6 ;
struct V_240 * V_8 = & V_298 -> V_8 ;
V_6 = F_136 ( V_8 , sizeof( * V_6 ) , V_186 ) ;
if ( ! V_6 ) {
F_33 ( V_8 , L_71 ) ;
return - V_187 ;
}
V_6 -> V_8 = V_8 ;
V_466 = F_159 ( V_298 , V_467 , 0 ) ;
if ( F_160 ( V_466 ) + 1 < V_468 ) {
F_33 ( V_8 , L_72 , V_466 ) ;
return - V_85 ;
}
V_6 -> V_218 = F_161 ( V_8 , V_466 ) ;
if ( F_120 ( V_6 -> V_218 ) )
return F_121 ( V_6 -> V_218 ) ;
V_188 = F_162 ( V_298 , L_73 ) ;
if ( V_188 > 0 )
V_6 -> V_189 . V_15 . V_188 = V_188 ;
V_188 = F_162 ( V_298 , L_74 ) ;
if ( V_188 > 0 )
V_6 -> V_198 . V_15 . V_188 = V_188 ;
V_188 = F_162 ( V_298 , L_75 ) ;
if ( V_188 > 0 )
V_6 -> V_93 . V_15 . V_188 = V_188 ;
V_188 = F_162 ( V_298 , L_76 ) ;
if ( V_188 > 0 )
V_6 -> V_362 = V_188 ;
F_3 ( V_6 ) ;
V_19 = F_153 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_143 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_152 ( V_6 ) ;
if ( V_19 )
goto V_469;
F_163 ( & V_6 -> V_470 ) ;
F_37 ( & V_308 ) ;
F_164 ( & V_6 -> V_470 , & V_471 ) ;
F_39 ( & V_308 ) ;
return 0 ;
V_469:
F_144 ( V_6 ) ;
return V_19 ;
}
static int F_165 ( struct V_464 * V_298 )
{
struct V_5 * V_303 , * V_6 = NULL ;
struct V_240 * V_8 = & V_298 -> V_8 ;
F_37 ( & V_308 ) ;
F_113 (curr, &arm_smmu_devices, list) {
if ( V_303 -> V_8 == V_8 ) {
V_6 = V_303 ;
F_166 ( & V_6 -> V_470 ) ;
break;
}
}
F_39 ( & V_308 ) ;
if ( ! V_6 )
return - V_294 ;
F_61 ( V_6 ) ;
F_144 ( V_6 ) ;
return 0 ;
}
static int T_11 F_167 ( void )
{
struct V_302 * V_472 ;
int V_19 ;
V_472 = F_168 ( NULL , V_473 ) ;
if ( ! V_472 )
return 0 ;
F_114 ( V_472 ) ;
V_19 = F_169 ( & V_474 ) ;
if ( V_19 )
return V_19 ;
return F_170 ( & V_475 , & V_276 ) ;
}
static void T_12 F_171 ( void )
{
return F_172 ( & V_474 ) ;
}
