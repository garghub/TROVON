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
V_90 [ V_95 ] ) ;
switch ( V_95 ) {
case V_92 :
break;
case V_93 :
F_33 ( V_6 -> V_8 , L_6 ) ;
case V_91 :
return;
}
F_28 ( V_34 , F_27 ( V_15 , V_95 ) , V_15 -> V_32 ) ;
F_33 ( V_6 -> V_8 , L_7 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_34 ) ; ++ V_7 )
F_33 ( V_6 -> V_8 , L_8 , ( unsigned long long ) V_34 [ V_7 ] ) ;
if ( F_31 ( V_34 , & V_98 ) ) {
F_33 ( V_6 -> V_8 , L_9 ) ;
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
F_36 ( V_6 -> V_8 , L_10 ,
V_30 -> V_37 ) ;
return;
}
F_37 ( & V_6 -> V_94 . V_101 ) ;
while ( V_22 = V_15 -> V_16 + 1 , F_26 ( V_15 , V_34 ) == - V_31 ) {
if ( F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_11 ) ;
}
if ( V_30 -> V_37 == V_87 && F_18 ( V_15 , V_22 , V_23 ) )
F_38 ( V_6 -> V_8 , L_12 ) ;
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
V_27 [ 2 ] = 0 ;
if ( V_139 )
F_45 ( V_6 , V_44 ) ;
return;
}
if ( V_138 -> V_151 ) {
F_48 ( V_139 ) ;
V_27 [ 1 ] = F_25 (
V_152
<< V_153 |
V_152
<< V_154 |
V_155 << V_156 |
V_157 |
#ifdef F_49
V_158 << V_159 |
#endif
V_160 << V_161 ) ;
V_103 |= ( V_138 -> V_151 -> V_162 & V_163
<< V_164 ) |
V_145 ;
}
if ( V_138 -> V_165 ) {
F_48 ( V_139 ) ;
V_27 [ 2 ] = F_25 (
V_138 -> V_165 -> V_65 << V_166 |
( V_138 -> V_165 -> V_167 & V_168 )
<< V_169 |
#ifdef F_43
V_170 |
#endif
V_171 | V_172 |
V_173 ) ;
V_27 [ 3 ] = F_25 ( V_138 -> V_165 -> V_174 &
V_175 << V_176 ) ;
V_103 |= V_146 ;
}
F_45 ( V_6 , V_44 ) ;
V_27 [ 0 ] = F_25 ( V_103 ) ;
F_45 ( V_6 , V_44 ) ;
if ( ! ( V_6 -> V_12 & V_177 ) )
F_35 ( V_6 , & V_140 ) ;
}
static void F_50 ( T_4 * V_178 , unsigned int V_179 )
{
unsigned int V_7 ;
struct V_137 V_138 = {
. V_147 = true ,
. V_148 = true ,
} ;
for ( V_7 = 0 ; V_7 < V_179 ; ++ V_7 ) {
F_46 ( NULL , - 1 , V_178 , & V_138 ) ;
V_178 += V_180 ;
}
}
static int F_51 ( struct V_5 * V_6 , T_1 V_44 )
{
T_5 V_46 ;
void * V_178 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
struct V_129 * V_130 = & V_114 -> V_183 [ V_44 >> V_184 ] ;
if ( V_130 -> V_185 )
return 0 ;
V_46 = 1 << ( V_184 + F_52 ( V_180 ) + 3 ) ;
V_178 = & V_114 -> V_178 [ ( V_44 >> V_184 ) * V_186 ] ;
V_130 -> V_131 = V_184 + 1 ;
V_130 -> V_185 = F_53 ( V_6 -> V_8 , V_46 , & V_130 -> V_134 ,
V_187 ) ;
if ( ! V_130 -> V_185 ) {
F_33 ( V_6 -> V_8 ,
L_13 ,
V_44 ) ;
return - V_188 ;
}
F_50 ( V_130 -> V_185 , 1 << V_184 ) ;
F_44 ( V_178 , V_130 ) ;
return 0 ;
}
static T_6 F_54 ( int V_189 , void * V_8 )
{
int V_7 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_190 . V_15 ;
T_4 V_191 [ V_192 ] ;
while ( ! F_30 ( V_15 , V_191 ) ) {
T_7 V_193 = V_191 [ 0 ] >> V_194 & V_195 ;
F_55 ( V_6 -> V_8 , L_14 , V_193 ) ;
for ( V_7 = 0 ; V_7 < F_34 ( V_191 ) ; ++ V_7 )
F_55 ( V_6 -> V_8 , L_8 ,
( unsigned long long ) V_191 [ V_7 ] ) ;
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_196 ;
}
static T_6 F_56 ( int V_189 , void * V_8 )
{
T_6 V_19 = V_197 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_190 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_15 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_198 ;
return V_19 ;
}
static T_6 F_57 ( int V_189 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_199 . V_15 ;
T_4 V_191 [ V_200 ] ;
while ( ! F_30 ( V_15 , V_191 ) ) {
T_1 V_44 , V_74 ;
T_8 V_77 ;
bool V_201 , V_202 ;
V_44 = V_191 [ 0 ] >> V_203 & V_204 ;
V_201 = V_191 [ 0 ] & V_205 ;
V_74 = V_201 ? V_191 [ 0 ] >> V_206 & V_207 : 0 ;
V_202 = V_191 [ 0 ] & V_208 ;
V_77 = V_191 [ 1 ] >> V_209 & V_210 ;
F_55 ( V_6 -> V_8 , L_16 ) ;
F_55 ( V_6 -> V_8 ,
L_17 ,
V_44 , V_74 , V_77 , V_202 ? L_18 : L_19 ,
V_191 [ 0 ] & V_211 ? L_19 : L_20 ,
V_191 [ 0 ] & V_212 ? L_21 : L_19 ,
V_191 [ 0 ] & V_213 ? L_22 : L_19 ,
V_191 [ 0 ] & V_214 ? L_23 : L_19 ,
V_191 [ 1 ] & V_215 << V_216 ) ;
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
F_35 ( V_6 , & V_34 ) ;
}
}
V_15 -> V_17 = F_13 ( V_15 , V_15 -> V_16 ) | F_8 ( V_15 , V_15 -> V_17 ) | F_7 ( V_15 , V_15 -> V_17 ) ;
return V_196 ;
}
static T_6 F_58 ( int V_189 , void * V_8 )
{
T_6 V_19 = V_197 ;
struct V_5 * V_6 = V_8 ;
struct V_14 * V_15 = & V_6 -> V_199 . V_15 ;
if ( F_15 ( V_15 ) == - V_21 )
F_33 ( V_6 -> V_8 , L_24 ) ;
else if ( F_9 ( V_15 ) )
V_19 = V_198 ;
return V_19 ;
}
static T_6 F_59 ( int V_189 , void * V_8 )
{
return V_196 ;
}
static T_6 F_60 ( int V_189 , void * V_8 )
{
T_1 V_217 , V_218 ;
struct V_5 * V_6 = V_8 ;
V_217 = F_11 ( V_6 -> V_219 + V_220 ) ;
V_218 = F_11 ( V_6 -> V_219 + V_221 ) ;
V_217 ^= V_218 ;
if ( ! ( V_217 & V_222 ) )
return V_198 ;
F_36 ( V_6 -> V_8 ,
L_25 ,
V_217 ) ;
if ( V_217 & V_223 ) {
F_33 ( V_6 -> V_8 , L_26 ) ;
F_61 ( V_6 ) ;
}
if ( V_217 & V_224 )
F_36 ( V_6 -> V_8 , L_27 ) ;
if ( V_217 & V_225 ) {
F_36 ( V_6 -> V_8 , L_28 ) ;
F_58 ( V_189 , V_6 -> V_8 ) ;
}
if ( V_217 & V_226 ) {
F_36 ( V_6 -> V_8 , L_29 ) ;
F_56 ( V_189 , V_6 -> V_8 ) ;
}
if ( V_217 & V_227 ) {
F_36 ( V_6 -> V_8 , L_30 ) ;
F_59 ( V_189 , V_6 -> V_8 ) ;
}
if ( V_217 & V_228 )
F_33 ( V_6 -> V_8 , L_31 ) ;
if ( V_217 & V_229 )
F_33 ( V_6 -> V_8 , L_32 ) ;
if ( V_217 & V_230 )
F_32 ( V_6 ) ;
F_14 ( V_217 , V_6 -> V_219 + V_221 ) ;
return V_196 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_35 V_34 ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
}
static void F_63 ( void * V_231 )
{
struct V_1 * V_232 = V_231 ;
F_62 ( V_232 -> V_6 ) ;
}
static void F_64 ( void * V_231 )
{
struct V_1 * V_232 = V_231 ;
struct V_5 * V_6 = V_232 -> V_6 ;
struct V_35 V_34 ;
if ( V_232 -> V_233 == V_234 ) {
V_34 . V_37 = V_68 ;
V_34 . V_59 . V_60 = V_232 -> V_151 . V_115 . V_60 ;
V_34 . V_59 . V_65 = 0 ;
} else {
V_34 . V_37 = V_69 ;
V_34 . V_59 . V_65 = V_232 -> V_165 . V_65 ;
}
F_35 ( V_6 , & V_34 ) ;
F_62 ( V_6 ) ;
}
static void F_65 ( unsigned long V_235 , T_5 V_46 ,
bool V_53 , void * V_231 )
{
struct V_1 * V_232 = V_231 ;
struct V_5 * V_6 = V_232 -> V_6 ;
struct V_35 V_34 = {
. V_59 = {
. V_53 = V_53 ,
. V_48 = V_235 ,
} ,
} ;
if ( V_232 -> V_233 == V_234 ) {
V_34 . V_37 = V_58 ;
V_34 . V_59 . V_60 = V_232 -> V_151 . V_115 . V_60 ;
} else {
V_34 . V_37 = V_64 ;
V_34 . V_59 . V_65 = V_232 -> V_165 . V_65 ;
}
F_35 ( V_6 , & V_34 ) ;
}
static bool F_66 ( enum V_236 V_237 )
{
switch ( V_237 ) {
case V_238 :
return true ;
case V_239 :
return true ;
case V_240 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_67 ( unsigned type )
{
struct V_1 * V_232 ;
if ( type != V_241 )
return NULL ;
V_232 = F_68 ( sizeof( * V_232 ) , V_187 ) ;
if ( ! V_232 )
return NULL ;
F_69 ( & V_232 -> V_242 ) ;
F_70 ( & V_232 -> V_243 ) ;
return & V_232 -> V_4 ;
}
static int F_71 ( unsigned long * V_244 , int V_131 )
{
int V_95 , V_46 = 1 << V_131 ;
do {
V_95 = F_72 ( V_244 , V_46 ) ;
if ( V_95 == V_46 )
return - V_31 ;
} while ( F_73 ( V_95 , V_244 ) );
return V_95 ;
}
static void F_74 ( unsigned long * V_244 , int V_95 )
{
F_75 ( V_95 , V_244 ) ;
}
static void F_76 ( struct V_2 * V_4 )
{
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_232 -> V_6 ;
F_77 ( V_232 -> V_245 ) ;
if ( V_232 -> V_233 == V_234 ) {
struct V_113 * V_114 = & V_232 -> V_151 ;
if ( V_114 -> V_123 ) {
F_78 ( V_232 -> V_6 -> V_8 ,
V_246 << 3 ,
V_114 -> V_123 ,
V_114 -> V_162 ) ;
F_74 ( V_6 -> V_247 , V_114 -> V_115 . V_60 ) ;
}
} else {
struct V_248 * V_114 = & V_232 -> V_165 ;
if ( V_114 -> V_65 )
F_74 ( V_6 -> V_249 , V_114 -> V_65 ) ;
}
F_79 ( V_232 ) ;
}
static int F_80 ( struct V_1 * V_232 ,
struct V_250 * V_251 )
{
int V_19 ;
T_8 V_60 ;
struct V_5 * V_6 = V_232 -> V_6 ;
struct V_113 * V_114 = & V_232 -> V_151 ;
V_60 = F_71 ( V_6 -> V_247 , V_6 -> V_252 ) ;
if ( F_81 ( V_60 ) )
return V_60 ;
V_114 -> V_123 = F_53 ( V_6 -> V_8 , V_246 << 3 ,
& V_114 -> V_162 , V_187 ) ;
if ( ! V_114 -> V_123 ) {
F_36 ( V_6 -> V_8 , L_33 ) ;
goto V_253;
}
V_114 -> V_115 . V_60 = V_60 ;
V_114 -> V_115 . V_124 = V_251 -> V_254 . V_124 [ 0 ] ;
V_114 -> V_115 . V_102 = V_251 -> V_254 . V_102 ;
V_114 -> V_115 . V_127 = V_251 -> V_254 . V_127 [ 0 ] ;
return 0 ;
V_253:
F_74 ( V_6 -> V_247 , V_60 ) ;
return V_19 ;
}
static int F_82 ( struct V_1 * V_232 ,
struct V_250 * V_251 )
{
T_8 V_65 ;
struct V_5 * V_6 = V_232 -> V_6 ;
struct V_248 * V_114 = & V_232 -> V_165 ;
V_65 = F_71 ( V_6 -> V_249 , V_6 -> V_255 ) ;
if ( F_81 ( V_65 ) )
return V_65 ;
V_114 -> V_65 = V_65 ;
V_114 -> V_174 = V_251 -> V_256 . V_174 ;
V_114 -> V_167 = V_251 -> V_256 . V_167 ;
return 0 ;
}
static int F_83 ( struct V_2 * V_4 )
{
int V_19 ;
unsigned long V_257 , V_258 ;
enum V_259 V_260 ;
struct V_250 V_251 ;
struct V_261 * V_245 ;
int (* F_84)( struct V_1 * ,
struct V_250 * );
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_232 -> V_6 ;
if ( ! ( V_6 -> V_99 & V_262 ) )
V_232 -> V_233 = V_263 ;
if ( ! ( V_6 -> V_99 & V_264 ) )
V_232 -> V_233 = V_234 ;
switch ( V_232 -> V_233 ) {
case V_234 :
V_257 = V_265 ;
V_258 = V_6 -> V_257 ;
V_260 = V_266 ;
F_84 = F_80 ;
break;
case V_267 :
case V_263 :
V_257 = V_6 -> V_257 ;
V_258 = V_6 -> V_258 ;
V_260 = V_268 ;
F_84 = F_82 ;
break;
default:
return - V_86 ;
}
V_251 = (struct V_250 ) {
. V_269 = V_270 . V_269 ,
. V_257 = V_257 ,
. V_258 = V_258 ,
. V_271 = & V_272 ,
. V_273 = V_6 -> V_8 ,
} ;
V_245 = F_85 ( V_260 , & V_251 , V_232 ) ;
if ( ! V_245 )
return - V_188 ;
V_270 . V_269 = V_251 . V_269 ;
V_232 -> V_245 = V_245 ;
V_19 = F_84 ( V_232 , & V_251 ) ;
if ( F_81 ( V_19 ) )
F_77 ( V_245 ) ;
return V_19 ;
}
static struct V_274 * F_86 ( struct V_275 * V_8 )
{
struct V_276 * V_277 ;
struct V_274 * V_278 ;
V_277 = F_87 ( V_8 ) ;
if ( ! V_277 )
return NULL ;
V_278 = F_88 ( V_277 ) ;
F_89 ( V_277 ) ;
return V_278 ;
}
static T_3 * F_90 ( struct V_5 * V_6 , T_1 V_44 )
{
T_3 * V_279 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
if ( V_6 -> V_99 & V_280 ) {
struct V_129 * V_183 ;
int V_95 ;
V_95 = ( V_44 >> V_184 ) * V_186 ;
V_183 = & V_114 -> V_183 [ V_95 ] ;
V_95 = ( V_44 & ( ( 1 << V_184 ) - 1 ) ) * V_180 ;
V_279 = & V_183 -> V_185 [ V_95 ] ;
} else {
V_279 = & V_114 -> V_178 [ V_44 * V_180 ] ;
}
return V_279 ;
}
static int F_91 ( struct V_274 * V_278 )
{
int V_7 ;
struct V_1 * V_232 = V_278 -> V_4 ;
struct V_137 * V_138 = & V_278 -> V_138 ;
struct V_5 * V_6 = V_278 -> V_6 ;
if ( V_232 -> V_233 == V_234 ) {
V_138 -> V_151 = & V_232 -> V_151 ;
V_138 -> V_165 = NULL ;
F_42 ( V_6 , V_138 -> V_151 ) ;
} else {
V_138 -> V_151 = NULL ;
V_138 -> V_165 = & V_232 -> V_165 ;
}
for ( V_7 = 0 ; V_7 < V_278 -> V_281 ; ++ V_7 ) {
T_1 V_44 = V_278 -> V_282 [ V_7 ] ;
T_3 * V_279 = F_90 ( V_6 , V_44 ) ;
F_46 ( V_6 , V_44 , V_279 , V_138 ) ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_4 , struct V_275 * V_8 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_274 * V_278 = F_86 ( V_8 ) ;
if ( ! V_278 )
return - V_89 ;
if ( V_278 -> V_4 && V_278 -> V_4 != V_232 )
return - V_283 ;
V_6 = V_278 -> V_6 ;
F_93 ( & V_232 -> V_242 ) ;
if ( ! V_232 -> V_6 ) {
V_232 -> V_6 = V_6 ;
V_19 = F_83 ( V_4 ) ;
if ( V_19 ) {
V_232 -> V_6 = NULL ;
goto V_284;
}
} else if ( V_232 -> V_6 != V_6 ) {
F_33 ( V_8 ,
L_34 ,
F_94 ( V_232 -> V_6 -> V_8 ) ,
F_94 ( V_6 -> V_8 ) ) ;
V_19 = - V_285 ;
goto V_284;
}
if ( V_278 -> V_4 )
goto V_284;
V_278 -> V_4 = V_232 ;
V_278 -> V_138 . V_148 = false ;
V_19 = F_91 ( V_278 ) ;
if ( F_81 ( V_19 ) )
V_278 -> V_4 = NULL ;
V_284:
F_95 ( & V_232 -> V_242 ) ;
return V_19 ;
}
static void F_96 ( struct V_2 * V_4 , struct V_275 * V_8 )
{
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_274 * V_278 = F_86 ( V_8 ) ;
F_48 ( ! V_232 ) ;
F_48 ( ! V_278 ) ;
F_93 ( & V_232 -> V_242 ) ;
F_48 ( V_278 -> V_4 != V_232 ) ;
V_278 -> V_138 . V_148 = true ;
if ( F_81 ( F_91 ( V_278 ) ) )
F_36 ( V_8 , L_35 ) ;
V_278 -> V_4 = NULL ;
F_95 ( & V_232 -> V_242 ) ;
}
static int F_97 ( struct V_2 * V_4 , unsigned long V_235 ,
T_9 V_286 , T_5 V_46 , int V_287 )
{
int V_19 ;
unsigned long V_288 ;
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_261 * V_289 = V_232 -> V_245 ;
if ( ! V_289 )
return - V_290 ;
F_98 ( & V_232 -> V_243 , V_288 ) ;
V_19 = V_289 -> V_244 ( V_289 , V_235 , V_286 , V_46 , V_287 ) ;
F_99 ( & V_232 -> V_243 , V_288 ) ;
return V_19 ;
}
static T_5
F_100 ( struct V_2 * V_4 , unsigned long V_235 , T_5 V_46 )
{
T_5 V_19 ;
unsigned long V_288 ;
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_261 * V_289 = V_232 -> V_245 ;
if ( ! V_289 )
return 0 ;
F_98 ( & V_232 -> V_243 , V_288 ) ;
V_19 = V_289 -> V_291 ( V_289 , V_235 , V_46 ) ;
F_99 ( & V_232 -> V_243 , V_288 ) ;
return V_19 ;
}
static T_9
F_101 ( struct V_2 * V_4 , T_10 V_235 )
{
T_9 V_19 ;
unsigned long V_288 ;
struct V_1 * V_232 = F_1 ( V_4 ) ;
struct V_261 * V_289 = V_232 -> V_245 ;
if ( ! V_289 )
return 0 ;
F_98 ( & V_232 -> V_243 , V_288 ) ;
V_19 = V_289 -> V_292 ( V_289 , V_235 ) ;
F_99 ( & V_232 -> V_243 , V_288 ) ;
return V_19 ;
}
static int F_102 ( struct V_293 * V_294 , T_8 V_295 , void * V_296 )
{
* ( T_1 * ) V_296 = V_295 ;
return 0 ;
}
static void F_103 ( void * V_297 )
{
F_79 ( V_297 ) ;
}
static struct V_5 * F_104 ( struct V_293 * V_294 )
{
struct V_298 * V_9 ;
struct V_5 * V_299 , * V_6 = NULL ;
struct V_300 * V_301 = V_294 -> V_301 ;
while ( ! F_105 ( V_301 ) )
V_301 = V_301 -> V_302 ;
V_9 = F_106 ( V_301 -> V_303 -> V_302 -> V_9 , L_36 , 0 ) ;
if ( ! V_9 )
return NULL ;
F_37 ( & V_304 ) ;
F_107 (curr, &arm_smmu_devices, list) {
if ( V_299 -> V_8 -> V_9 == V_9 ) {
V_6 = V_299 ;
break;
}
}
F_39 ( & V_304 ) ;
F_108 ( V_9 ) ;
return V_6 ;
}
static bool F_109 ( struct V_5 * V_6 , T_1 V_44 )
{
unsigned long V_305 = V_6 -> V_182 . V_306 ;
if ( V_6 -> V_99 & V_280 )
V_305 *= 1UL << V_184 ;
return V_44 < V_305 ;
}
static int F_110 ( struct V_275 * V_8 )
{
int V_7 , V_19 ;
T_1 V_44 , * V_282 ;
struct V_293 * V_294 ;
struct V_276 * V_277 ;
struct V_274 * V_278 ;
struct V_5 * V_6 ;
if ( ! F_111 ( V_8 ) )
return - V_290 ;
V_294 = F_112 ( V_8 ) ;
V_277 = F_113 ( V_8 ) ;
if ( F_114 ( V_277 ) )
return F_115 ( V_277 ) ;
V_278 = F_88 ( V_277 ) ;
if ( ! V_278 ) {
V_6 = F_104 ( V_294 ) ;
if ( ! V_6 ) {
V_19 = - V_89 ;
goto V_307;
}
V_278 = F_68 ( sizeof( * V_278 ) , V_187 ) ;
if ( ! V_278 ) {
V_19 = - V_188 ;
goto V_307;
}
V_278 -> V_138 . V_147 = true ;
V_278 -> V_6 = V_6 ;
F_116 ( V_277 , V_278 ,
F_103 ) ;
} else {
V_6 = V_278 -> V_6 ;
}
F_117 ( V_294 , F_102 , & V_44 ) ;
for ( V_7 = 0 ; V_7 < V_278 -> V_281 ; ++ V_7 ) {
if ( V_278 -> V_282 [ V_7 ] == V_44 )
return 0 ;
}
if ( ! F_109 ( V_6 , V_44 ) ) {
V_19 = - V_308 ;
goto V_307;
}
if ( V_6 -> V_99 & V_280 ) {
V_19 = F_51 ( V_6 , V_44 ) ;
if ( V_19 )
goto V_307;
}
V_278 -> V_281 ++ ;
V_282 = F_118 ( V_278 -> V_282 , V_278 -> V_281 * sizeof( * V_282 ) ,
V_187 ) ;
if ( ! V_282 ) {
V_278 -> V_281 -- ;
V_19 = - V_188 ;
goto V_307;
}
V_282 [ V_278 -> V_281 - 1 ] = V_44 ;
V_278 -> V_282 = V_282 ;
return 0 ;
V_307:
F_89 ( V_277 ) ;
return V_19 ;
}
static void F_119 ( struct V_275 * V_8 )
{
F_120 ( V_8 ) ;
}
static int F_121 ( struct V_2 * V_4 ,
enum V_309 V_310 , void * V_297 )
{
struct V_1 * V_232 = F_1 ( V_4 ) ;
switch ( V_310 ) {
case V_311 :
* ( int * ) V_297 = ( V_232 -> V_233 == V_267 ) ;
return 0 ;
default:
return - V_290 ;
}
}
static int F_122 ( struct V_2 * V_4 ,
enum V_309 V_310 , void * V_297 )
{
int V_19 = 0 ;
struct V_1 * V_232 = F_1 ( V_4 ) ;
F_93 ( & V_232 -> V_242 ) ;
switch ( V_310 ) {
case V_311 :
if ( V_232 -> V_6 ) {
V_19 = - V_312 ;
goto V_284;
}
if ( * ( int * ) V_297 )
V_232 -> V_233 = V_267 ;
else
V_232 -> V_233 = V_234 ;
break;
default:
V_19 = - V_290 ;
}
V_284:
F_95 ( & V_232 -> V_242 ) ;
return V_19 ;
}
static int F_123 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned long V_313 ,
unsigned long V_314 ,
T_5 V_315 )
{
T_5 V_316 = ( ( 1 << V_15 -> V_317 ) * V_315 ) << 3 ;
V_15 -> V_219 = F_124 ( V_6 -> V_8 , V_316 , & V_15 -> V_318 , V_187 ) ;
if ( ! V_15 -> V_219 ) {
F_33 ( V_6 -> V_8 , L_37 ,
V_316 ) ;
return - V_188 ;
}
V_15 -> V_20 = V_6 -> V_219 + V_313 ;
V_15 -> V_18 = V_6 -> V_219 + V_314 ;
V_15 -> V_32 = V_315 ;
V_15 -> V_319 = V_320 ;
V_15 -> V_319 |= V_15 -> V_318 & V_321 << V_322 ;
V_15 -> V_319 |= ( V_15 -> V_317 & V_323 )
<< V_324 ;
V_15 -> V_16 = V_15 -> V_17 = 0 ;
return 0 ;
}
static void F_125 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
T_5 V_316 = ( ( 1 << V_15 -> V_317 ) * V_15 -> V_32 ) << 3 ;
F_78 ( V_6 -> V_8 , V_316 , V_15 -> V_219 , V_15 -> V_318 ) ;
}
static void F_126 ( struct V_5 * V_6 )
{
F_125 ( V_6 , & V_6 -> V_94 . V_15 ) ;
F_125 ( V_6 , & V_6 -> V_190 . V_15 ) ;
if ( V_6 -> V_99 & V_325 )
F_125 ( V_6 , & V_6 -> V_199 . V_15 ) ;
}
static int F_127 ( struct V_5 * V_6 )
{
int V_19 ;
F_70 ( & V_6 -> V_94 . V_101 ) ;
V_19 = F_123 ( V_6 , & V_6 -> V_94 . V_15 , V_326 ,
V_327 , V_36 ) ;
if ( V_19 )
goto V_328;
V_19 = F_123 ( V_6 , & V_6 -> V_190 . V_15 , V_329 ,
V_330 , V_192 ) ;
if ( V_19 )
goto V_331;
if ( ! ( V_6 -> V_99 & V_325 ) )
return 0 ;
V_19 = F_123 ( V_6 , & V_6 -> V_199 . V_15 , V_332 ,
V_333 , V_200 ) ;
if ( V_19 )
goto V_334;
return 0 ;
V_334:
F_125 ( V_6 , & V_6 -> V_190 . V_15 ) ;
V_331:
F_125 ( V_6 , & V_6 -> V_94 . V_15 ) ;
V_328:
return V_19 ;
}
static void F_128 ( struct V_5 * V_6 )
{
int V_7 ;
T_5 V_46 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
V_46 = 1 << ( V_184 + F_52 ( V_180 ) + 3 ) ;
for ( V_7 = 0 ; V_7 < V_114 -> V_306 ; ++ V_7 ) {
struct V_129 * V_130 = & V_114 -> V_183 [ V_7 ] ;
if ( ! V_130 -> V_185 )
continue;
F_78 ( V_6 -> V_8 , V_46 , V_130 -> V_185 ,
V_130 -> V_134 ) ;
}
}
static int F_129 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
T_5 V_46 = sizeof( * V_114 -> V_183 ) * V_114 -> V_306 ;
void * V_178 = V_6 -> V_182 . V_178 ;
V_114 -> V_183 = F_130 ( V_6 -> V_8 , V_46 , V_187 ) ;
if ( ! V_114 -> V_183 ) {
F_33 ( V_6 -> V_8 , L_38 ) ;
return - V_188 ;
}
for ( V_7 = 0 ; V_7 < V_114 -> V_306 ; ++ V_7 ) {
F_44 ( V_178 , & V_114 -> V_183 [ V_7 ] ) ;
V_178 += V_186 << 3 ;
}
return 0 ;
}
static int F_131 ( struct V_5 * V_6 )
{
void * V_178 ;
T_4 V_335 ;
T_1 V_46 , V_336 ;
int V_19 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
if ( V_6 -> V_337 < V_184 ) {
V_46 = 0 ;
} else {
V_46 = V_338 - ( F_52 ( V_186 ) + 3 ) ;
V_46 = F_132 ( V_46 , V_6 -> V_337 - V_184 ) ;
}
V_114 -> V_306 = 1 << V_46 ;
V_46 += V_184 ;
if ( V_46 < V_6 -> V_337 )
F_36 ( V_6 -> V_8 ,
L_39 ,
V_46 , V_6 -> V_337 ) ;
V_336 = V_114 -> V_306 * ( V_186 << 3 ) ;
V_178 = F_53 ( V_6 -> V_8 , V_336 , & V_114 -> V_339 ,
V_187 ) ;
if ( ! V_178 ) {
F_33 ( V_6 -> V_8 ,
L_40 ,
V_46 ) ;
return - V_188 ;
}
V_114 -> V_178 = V_178 ;
V_335 = V_340 ;
V_335 |= ( V_46 & V_341 )
<< V_342 ;
V_335 |= ( V_184 & V_343 )
<< V_344 ;
V_114 -> V_345 = V_335 ;
V_19 = F_129 ( V_6 ) ;
if ( V_19 )
F_78 ( V_6 -> V_8 ,
V_336 ,
V_178 ,
V_114 -> V_339 ) ;
return V_19 ;
}
static int F_133 ( struct V_5 * V_6 )
{
void * V_178 ;
T_4 V_335 ;
T_1 V_46 ;
struct V_181 * V_114 = & V_6 -> V_182 ;
V_46 = ( 1 << V_6 -> V_337 ) * ( V_180 << 3 ) ;
V_178 = F_53 ( V_6 -> V_8 , V_46 , & V_114 -> V_339 ,
V_187 ) ;
if ( ! V_178 ) {
F_33 ( V_6 -> V_8 ,
L_41 ,
V_46 ) ;
return - V_188 ;
}
V_114 -> V_178 = V_178 ;
V_114 -> V_306 = 1 << V_6 -> V_337 ;
V_335 = V_346 ;
V_335 |= ( V_6 -> V_337 & V_341 )
<< V_342 ;
V_114 -> V_345 = V_335 ;
F_50 ( V_178 , V_114 -> V_306 ) ;
return 0 ;
}
static int F_134 ( struct V_5 * V_6 )
{
T_4 V_335 ;
int V_19 ;
if ( V_6 -> V_99 & V_280 )
V_19 = F_131 ( V_6 ) ;
else
V_19 = F_133 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_335 = V_6 -> V_182 . V_339 &
V_347 << V_348 ;
V_335 |= V_349 ;
V_6 -> V_182 . V_350 = V_335 ;
F_135 ( 0 , V_6 -> V_249 ) ;
return 0 ;
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_181 * V_114 = & V_6 -> V_182 ;
T_1 V_46 = V_114 -> V_306 ;
if ( V_6 -> V_99 & V_280 ) {
F_128 ( V_6 ) ;
V_46 *= V_186 << 3 ;
} else {
V_46 *= V_180 * 3 ;
}
F_78 ( V_6 -> V_8 , V_46 , V_114 -> V_178 , V_114 -> V_339 ) ;
}
static int F_137 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_127 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_134 ( V_6 ) ;
if ( V_19 )
goto V_351;
return 0 ;
V_351:
F_126 ( V_6 ) ;
return V_19 ;
}
static void F_138 ( struct V_5 * V_6 )
{
F_136 ( V_6 ) ;
F_126 ( V_6 ) ;
}
static int F_139 ( struct V_5 * V_6 , T_1 V_103 ,
unsigned int V_352 , unsigned int V_353 )
{
T_1 V_335 ;
F_140 ( V_103 , V_6 -> V_219 + V_352 ) ;
return F_141 ( V_6 -> V_219 + V_353 , V_335 , V_335 == V_103 ,
1 , V_25 ) ;
}
static int F_142 ( struct V_5 * V_6 )
{
int V_19 , V_189 ;
T_1 V_354 = V_355 | V_356 ;
V_19 = F_139 ( V_6 , 0 , V_357 ,
V_358 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_42 ) ;
return V_19 ;
}
F_143 ( 0 , V_6 -> V_219 + V_359 ) ;
F_143 ( 0 , V_6 -> V_219 + V_360 ) ;
V_189 = V_6 -> V_190 . V_15 . V_189 ;
if ( V_189 ) {
V_19 = F_144 ( V_6 -> V_8 , V_189 ,
F_56 ,
F_54 ,
0 , L_43 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_44 ) ;
}
V_189 = V_6 -> V_94 . V_15 . V_189 ;
if ( V_189 ) {
V_19 = F_145 ( V_6 -> V_8 , V_189 ,
F_59 , 0 ,
L_45 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_46 ) ;
}
V_189 = V_6 -> V_361 ;
if ( V_189 ) {
V_19 = F_145 ( V_6 -> V_8 , V_189 , F_60 ,
0 , L_47 , V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 , L_48 ) ;
}
if ( V_6 -> V_99 & V_325 ) {
F_143 ( 0 , V_6 -> V_219 + V_362 ) ;
V_189 = V_6 -> V_199 . V_15 . V_189 ;
if ( V_189 ) {
V_19 = F_144 ( V_6 -> V_8 , V_189 ,
F_58 ,
F_57 ,
0 , L_49 ,
V_6 ) ;
if ( F_81 ( V_19 ) )
F_36 ( V_6 -> V_8 ,
L_50 ) ;
else
V_354 |= V_363 ;
}
}
V_19 = F_139 ( V_6 , V_354 ,
V_357 , V_358 ) ;
if ( V_19 )
F_36 ( V_6 -> V_8 , L_51 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
int V_19 ;
V_19 = F_139 ( V_6 , 0 , V_364 , V_365 ) ;
if ( V_19 )
F_33 ( V_6 -> V_8 , L_52 ) ;
return V_19 ;
}
static int F_146 ( struct V_5 * V_6 )
{
int V_19 ;
T_1 V_335 , V_366 ;
struct V_35 V_34 ;
V_335 = F_11 ( V_6 -> V_219 + V_364 ) ;
if ( V_335 & V_367 )
F_36 ( V_6 -> V_8 , L_53 ) ;
V_19 = F_61 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_335 = ( V_368 << V_369 ) |
( V_370 << V_371 ) |
( V_370 << V_372 ) |
( V_368 << V_373 ) |
( V_370 << V_374 ) |
( V_370 << V_375 ) ;
F_140 ( V_335 , V_6 -> V_219 + V_376 ) ;
V_335 = V_377 | V_378 | V_379 ;
F_140 ( V_335 , V_6 -> V_219 + V_380 ) ;
F_143 ( V_6 -> V_182 . V_350 ,
V_6 -> V_219 + V_381 ) ;
F_140 ( V_6 -> V_182 . V_345 ,
V_6 -> V_219 + V_382 ) ;
F_143 ( V_6 -> V_94 . V_15 . V_319 , V_6 -> V_219 + V_383 ) ;
F_140 ( V_6 -> V_94 . V_15 . V_16 , V_6 -> V_219 + V_326 ) ;
F_140 ( V_6 -> V_94 . V_15 . V_17 , V_6 -> V_219 + V_327 ) ;
V_366 = V_384 ;
V_19 = F_139 ( V_6 , V_366 , V_364 ,
V_365 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_54 ) ;
return V_19 ;
}
V_34 . V_37 = V_55 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
if ( V_6 -> V_99 & V_385 ) {
V_34 . V_37 = V_40 ;
F_35 ( V_6 , & V_34 ) ;
}
V_34 . V_37 = V_41 ;
F_35 ( V_6 , & V_34 ) ;
V_34 . V_37 = V_87 ;
F_35 ( V_6 , & V_34 ) ;
F_143 ( V_6 -> V_190 . V_15 . V_319 , V_6 -> V_219 + V_386 ) ;
F_140 ( V_6 -> V_190 . V_15 . V_16 , V_6 -> V_219 + V_329 ) ;
F_140 ( V_6 -> V_190 . V_15 . V_17 , V_6 -> V_219 + V_330 ) ;
V_366 |= V_387 ;
V_19 = F_139 ( V_6 , V_366 , V_364 ,
V_365 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_55 ) ;
return V_19 ;
}
if ( V_6 -> V_99 & V_325 ) {
F_143 ( V_6 -> V_199 . V_15 . V_319 ,
V_6 -> V_219 + V_388 ) ;
F_140 ( V_6 -> V_199 . V_15 . V_16 ,
V_6 -> V_219 + V_332 ) ;
F_140 ( V_6 -> V_199 . V_15 . V_17 ,
V_6 -> V_219 + V_333 ) ;
V_366 |= V_389 ;
V_19 = F_139 ( V_6 , V_366 , V_364 ,
V_365 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_56 ) ;
return V_19 ;
}
}
V_19 = F_142 ( V_6 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_57 ) ;
return V_19 ;
}
V_366 |= V_367 ;
V_19 = F_139 ( V_6 , V_366 , V_364 ,
V_365 ) ;
if ( V_19 ) {
F_33 ( V_6 -> V_8 , L_58 ) ;
return V_19 ;
}
return 0 ;
}
static int F_147 ( struct V_5 * V_6 )
{
T_1 V_335 ;
bool V_390 ;
unsigned long V_269 = 0 ;
V_335 = F_11 ( V_6 -> V_219 + V_391 ) ;
if ( ( V_335 & V_392 << V_393 ) == V_394 )
V_6 -> V_99 |= V_280 ;
if ( V_335 & V_395 )
V_6 -> V_99 |= V_396 ;
switch ( V_335 & V_397 << V_398 ) {
case V_399 :
V_6 -> V_99 |= V_400 | V_401 ;
break;
#ifdef F_43
case V_402 :
V_6 -> V_99 |= V_401 ;
break;
#else
case V_403 :
V_6 -> V_99 |= V_400 ;
break;
#endif
default:
F_33 ( V_6 -> V_8 , L_59 ) ;
return - V_285 ;
}
if ( F_148 ( V_404 ) && V_335 & V_405 )
V_6 -> V_99 |= V_325 ;
if ( F_148 ( F_49 ) && V_335 & V_406 )
V_6 -> V_99 |= V_407 ;
if ( V_335 & V_408 )
V_6 -> V_99 |= V_100 ;
if ( V_335 & V_409 )
V_6 -> V_99 |= V_410 ;
if ( V_335 & V_411 )
V_6 -> V_99 |= V_385 ;
V_390 = F_149 ( V_6 -> V_8 -> V_9 ) ;
if ( V_390 )
V_6 -> V_99 |= V_412 ;
if ( ! ! ( V_335 & V_413 ) != V_390 )
F_36 ( V_6 -> V_8 , L_60 ,
V_390 ? L_61 : L_62 ) ;
if ( V_335 & V_414 )
V_6 -> V_99 |= V_415 ;
if ( V_335 & V_416 )
V_6 -> V_99 |= V_262 ;
if ( V_335 & V_417 )
V_6 -> V_99 |= V_264 ;
if ( ! ( V_335 & ( V_416 | V_417 ) ) ) {
F_33 ( V_6 -> V_8 , L_63 ) ;
return - V_285 ;
}
switch ( V_335 & V_418 << V_419 ) {
case V_420 :
V_6 -> V_257 = 40 ;
case V_421 :
break;
default:
F_33 ( V_6 -> V_8 , L_64 ) ;
return - V_285 ;
}
V_6 -> V_252 = V_335 & V_422 ? 16 : 8 ;
V_6 -> V_255 = V_335 & V_423 ? 16 : 8 ;
V_335 = F_11 ( V_6 -> V_219 + V_424 ) ;
if ( V_335 & ( V_425 | V_426 | V_427 ) ) {
F_33 ( V_6 -> V_8 , L_65 ) ;
return - V_285 ;
}
V_6 -> V_94 . V_15 . V_317 = F_132 ( ( T_1 ) V_428 ,
V_335 >> V_429 & V_430 ) ;
if ( ! V_6 -> V_94 . V_15 . V_317 ) {
F_33 ( V_6 -> V_8 , L_66 ) ;
return - V_285 ;
}
V_6 -> V_190 . V_15 . V_317 = F_132 ( ( T_1 ) V_431 ,
V_335 >> V_432 & V_433 ) ;
V_6 -> V_199 . V_15 . V_317 = F_132 ( ( T_1 ) V_434 ,
V_335 >> V_435 & V_436 ) ;
V_6 -> V_437 = V_335 >> V_438 & V_439 ;
V_6 -> V_337 = V_335 >> V_440 & V_441 ;
V_335 = F_11 ( V_6 -> V_219 + V_442 ) ;
V_6 -> V_190 . V_443 = V_335 >> V_444
& V_445 ;
if ( V_335 & V_446 )
V_269 |= V_447 | V_448 ;
if ( V_335 & V_449 )
V_269 |= V_450 | V_451 ;
if ( V_335 & V_452 )
V_269 |= V_453 | V_454 | V_455 ;
V_270 . V_269 &= V_269 ;
switch ( V_335 & V_456 << V_457 ) {
case V_458 :
V_6 -> V_258 = 32 ;
break;
case V_459 :
V_6 -> V_258 = 36 ;
break;
case V_460 :
V_6 -> V_258 = 40 ;
break;
case V_461 :
V_6 -> V_258 = 42 ;
break;
case V_462 :
V_6 -> V_258 = 44 ;
break;
default:
F_55 ( V_6 -> V_8 ,
L_67 ) ;
case V_463 :
V_6 -> V_258 = 48 ;
}
if ( F_150 ( V_6 -> V_8 , F_151 ( V_6 -> V_258 ) ) )
F_36 ( V_6 -> V_8 ,
L_68 ) ;
V_6 -> V_257 = F_152 ( V_6 -> V_257 , V_6 -> V_258 ) ;
F_55 ( V_6 -> V_8 , L_69 ,
V_6 -> V_257 , V_6 -> V_258 , V_6 -> V_99 ) ;
return 0 ;
}
static int F_153 ( struct V_464 * V_294 )
{
int V_189 , V_19 ;
struct V_465 * V_466 ;
struct V_5 * V_6 ;
struct V_275 * V_8 = & V_294 -> V_8 ;
V_6 = F_130 ( V_8 , sizeof( * V_6 ) , V_187 ) ;
if ( ! V_6 ) {
F_33 ( V_8 , L_70 ) ;
return - V_188 ;
}
V_6 -> V_8 = V_8 ;
V_466 = F_154 ( V_294 , V_467 , 0 ) ;
if ( F_155 ( V_466 ) + 1 < V_468 ) {
F_33 ( V_8 , L_71 , V_466 ) ;
return - V_86 ;
}
V_6 -> V_219 = F_156 ( V_8 , V_466 ) ;
if ( F_114 ( V_6 -> V_219 ) )
return F_115 ( V_6 -> V_219 ) ;
V_189 = F_157 ( V_294 , L_72 ) ;
if ( V_189 > 0 )
V_6 -> V_190 . V_15 . V_189 = V_189 ;
V_189 = F_157 ( V_294 , L_73 ) ;
if ( V_189 > 0 )
V_6 -> V_199 . V_15 . V_189 = V_189 ;
V_189 = F_157 ( V_294 , L_74 ) ;
if ( V_189 > 0 )
V_6 -> V_94 . V_15 . V_189 = V_189 ;
V_189 = F_157 ( V_294 , L_75 ) ;
if ( V_189 > 0 )
V_6 -> V_361 = V_189 ;
F_3 ( V_6 ) ;
V_19 = F_147 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_137 ( V_6 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_146 ( V_6 ) ;
if ( V_19 )
goto V_469;
F_158 ( & V_6 -> V_470 ) ;
F_37 ( & V_304 ) ;
F_159 ( & V_6 -> V_470 , & V_471 ) ;
F_39 ( & V_304 ) ;
return 0 ;
V_469:
F_138 ( V_6 ) ;
return V_19 ;
}
static int F_160 ( struct V_464 * V_294 )
{
struct V_5 * V_299 , * V_6 = NULL ;
struct V_275 * V_8 = & V_294 -> V_8 ;
F_37 ( & V_304 ) ;
F_107 (curr, &arm_smmu_devices, list) {
if ( V_299 -> V_8 == V_8 ) {
V_6 = V_299 ;
F_161 ( & V_6 -> V_470 ) ;
break;
}
}
F_39 ( & V_304 ) ;
if ( ! V_6 )
return - V_290 ;
F_61 ( V_6 ) ;
F_138 ( V_6 ) ;
return 0 ;
}
static int T_11 F_162 ( void )
{
struct V_298 * V_472 ;
int V_19 ;
V_472 = F_163 ( NULL , V_473 ) ;
if ( ! V_472 )
return 0 ;
F_108 ( V_472 ) ;
V_19 = F_164 ( & V_474 ) ;
if ( V_19 )
return V_19 ;
return F_165 ( & V_475 , & V_270 ) ;
}
static void T_12 F_166 ( void )
{
return F_167 ( & V_474 ) ;
}
