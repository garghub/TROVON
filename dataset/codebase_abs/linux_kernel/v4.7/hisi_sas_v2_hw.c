static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_2 ( V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
return F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 , int V_5 ,
T_1 V_2 , T_1 V_4 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
F_6 ( V_4 , V_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 ,
int V_5 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_3 + ( 0x400 * V_5 ) + V_2 ;
return F_2 ( V_3 ) ;
}
static int
F_9 ( struct V_1 * V_1 , int * V_6 ,
struct V_7 * V_8 )
{
unsigned int V_9 = 0 ;
void * V_10 = V_1 -> V_11 ;
int V_12 = F_10 ( V_8 ) ;
while ( 1 ) {
V_9 = F_11 ( V_10 , V_1 -> V_13 ,
V_9 ) ;
if ( V_9 >= V_1 -> V_13 )
return - V_14 ;
if ( V_12 || ( V_9 & 1 ) )
break;
V_9 ++ ;
}
F_12 ( V_9 , V_10 ) ;
* V_6 = V_9 ;
return 0 ;
}
static struct
V_15 * F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_8 -> V_16 -> V_17 -> V_18 ;
struct V_15 * V_19 = NULL ;
int V_20 , V_12 = F_10 ( V_8 ) ;
F_14 ( & V_1 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_12 && ( V_20 & 1 ) )
continue;
if ( V_1 -> V_23 [ V_20 ] . V_24 == V_25 ) {
V_1 -> V_23 [ V_20 ] . V_26 = V_20 ;
V_19 = & V_1 -> V_23 [ V_20 ] ;
V_19 -> V_27 = V_28 ;
V_19 -> V_24 = V_8 -> V_24 ;
V_19 -> V_1 = V_1 ;
V_19 -> V_29 = V_8 ;
break;
}
}
F_15 ( & V_1 -> V_21 ) ;
return V_19 ;
}
static void F_16 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 &= ~ V_32 ;
V_30 |= 1 << V_33 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_17 ( struct V_1 * V_1 , int V_5 )
{
struct V_34 V_35 ;
T_1 * V_36 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_24 = V_37 ;
V_35 . V_38 = 0 ;
V_35 . V_39 = 1 ;
V_35 . V_40 = V_41 ;
V_35 . V_42 = V_43 ;
memcpy ( & V_35 . V_44 [ 0 ] , V_1 -> V_45 , V_46 ) ;
memcpy ( & V_35 . V_45 [ 0 ] , V_1 -> V_45 , V_46 ) ;
V_35 . V_47 = V_5 ;
V_36 = ( T_1 * ) ( & V_35 ) ;
F_7 ( V_1 , V_5 , V_48 ,
F_18 ( V_36 [ 0 ] ) ) ;
F_7 ( V_1 , V_5 , V_49 ,
V_36 [ 2 ] ) ;
F_7 ( V_1 , V_5 , V_50 ,
V_36 [ 1 ] ) ;
F_7 ( V_1 , V_5 , V_51 ,
V_36 [ 4 ] ) ;
F_7 ( V_1 , V_5 , V_52 ,
V_36 [ 3 ] ) ;
F_7 ( V_1 , V_5 , V_53 ,
F_18 ( V_36 [ 5 ] ) ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ )
F_17 ( V_1 , V_20 ) ;
}
static void F_20 ( struct V_1 * V_1 ,
struct V_15 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_29 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_3 V_57 , V_26 = V_19 -> V_26 ;
struct V_58 * V_59 = & V_1 -> V_59 [ V_26 ] ;
struct V_7 * V_60 = V_8 -> V_61 ;
struct V_62 * V_16 = V_8 -> V_16 -> V_63 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_57 = 0 ;
switch ( V_19 -> V_24 ) {
case V_37 :
case V_64 :
case V_65 :
V_57 = V_66 << V_67 ;
break;
case V_68 :
if ( V_60 && F_21 ( V_60 -> V_24 ) )
V_57 = V_69 << V_67 ;
else
V_57 = V_70 << V_67 ;
break;
default:
F_22 ( V_55 , L_1 ,
V_19 -> V_24 ) ;
}
V_57 |= ( ( 1 << V_71 ) |
( V_8 -> V_72 << V_73 ) |
( 1 << V_74 ) |
( V_16 -> V_75 << V_76 ) ) ;
V_59 -> V_57 = F_23 ( V_57 ) ;
memcpy ( & V_59 -> V_45 , V_8 -> V_45 , V_46 ) ;
V_59 -> V_45 = F_24 ( V_59 -> V_45 ) ;
if ( ! F_10 ( V_8 ) )
V_59 -> V_77 = F_23 ( ( 500ULL << V_78 ) |
( 0x1ULL << V_79 ) |
( 0x32ULL << V_80 ) |
( 0x1ULL << V_81 ) ) ;
}
static void F_25 ( struct V_1 * V_1 ,
struct V_15 * V_19 )
{
T_3 V_57 , V_82 = V_19 -> V_26 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_58 * V_59 = & V_1 -> V_59 [ V_82 ] ;
T_1 V_83 = F_1 ( V_1 , V_84 ) ;
int V_20 ;
if ( V_85 & V_83 )
F_5 ( V_1 , V_84 ,
V_85 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_83 = F_1 ( V_1 , V_86 ) ;
V_83 |= V_87 | ( V_82 & V_88 ) ;
F_5 ( V_1 , V_86 , V_83 ) ;
F_26 ( 10 ) ;
V_83 = F_1 ( V_1 , V_84 ) ;
if ( V_85 & V_83 ) {
F_27 ( V_55 , L_2 ) ;
V_57 = F_23 ( V_59 -> V_57 ) ;
V_57 &= ~ ( 1 << V_71 ) ;
F_5 ( V_1 , V_84 ,
V_85 ) ;
V_1 -> V_23 [ V_82 ] . V_24 = V_25 ;
V_1 -> V_23 [ V_82 ] . V_27 = V_28 ;
F_5 ( V_1 , V_86 , 0 ) ;
F_27 ( V_55 , L_3 ) ;
break;
}
}
}
static int F_28 ( struct V_1 * V_1 )
{
int V_20 , V_89 ;
T_1 V_4 ;
unsigned long V_90 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
if ( V_1 -> V_54 == 9 )
V_89 = 0x1fffff ;
else
V_89 = 0x7ffff ;
for ( V_20 = 0 ; V_20 < V_91 ; V_20 ++ )
F_5 ( V_1 , V_92 , 0 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
T_1 V_93 = F_8 ( V_1 , V_20 , V_31 ) ;
V_93 &= ~ V_94 ;
F_7 ( V_1 , V_20 , V_31 , V_93 ) ;
}
F_26 ( 50 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
T_1 V_95 , V_96 ;
V_90 = V_97 + F_29 ( 1000 ) ;
while ( 1 ) {
V_95 = F_8 ( V_1 , V_20 ,
V_98 ) ;
V_96 = F_8 ( V_1 , V_20 ,
V_99 ) ;
if ( ! ( V_95 & V_100 ) &&
! ( V_96 & V_101 ) )
break;
F_30 ( 20 ) ;
if ( F_31 ( V_97 , V_90 ) )
return - V_102 ;
}
}
V_90 = V_97 + F_29 ( 1000 ) ;
while ( 1 ) {
T_1 V_103 =
F_1 ( V_1 , V_104 ) ;
if ( V_103 == 0 )
break;
F_30 ( 20 ) ;
if ( F_31 ( V_97 , V_90 ) )
return - V_102 ;
}
F_32 ( V_1 -> V_105 , V_1 -> V_106 ,
V_89 ) ;
F_32 ( V_1 -> V_105 , V_1 -> V_107 + 4 ,
V_89 ) ;
F_30 ( 1 ) ;
F_33 ( V_1 -> V_105 , V_1 -> V_108 , & V_4 ) ;
if ( V_89 != ( V_4 & V_89 ) ) {
F_34 ( V_55 , L_4 ) ;
return - V_102 ;
}
F_32 ( V_1 -> V_105 , V_1 -> V_106 + 4 ,
V_89 ) ;
F_32 ( V_1 -> V_105 , V_1 -> V_107 ,
V_89 ) ;
F_30 ( 1 ) ;
F_33 ( V_1 -> V_105 , V_1 -> V_108 ,
& V_4 ) ;
if ( V_4 & V_89 ) {
F_34 ( V_55 , L_5 ) ;
return - V_102 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_109 * V_110 = V_55 -> V_111 ;
int V_20 ;
if ( F_36 ( V_110 , L_6 , NULL ) ) {
F_5 ( V_1 , V_112 , 0x2020 ) ;
F_5 ( V_1 , V_113 ,
0x2020 ) ;
}
F_5 ( V_1 , V_92 ,
( T_1 ) ( ( 1ULL << V_1 -> V_114 ) - 1 ) ) ;
F_5 ( V_1 , V_115 , 0xc0000000 ) ;
F_5 ( V_1 , V_116 , 0x10000 ) ;
F_5 ( V_1 , V_117 , 0x108 ) ;
F_5 ( V_1 , V_118 , 0x7FF ) ;
F_5 ( V_1 , V_119 , 0x1 ) ;
F_5 ( V_1 , V_120 , 0x1F4 ) ;
F_5 ( V_1 , V_121 , 0x32 ) ;
F_5 ( V_1 , V_122 , 0x1 ) ;
F_5 ( V_1 , V_123 , 0x1 ) ;
F_5 ( V_1 , V_124 , 0x1 ) ;
F_5 ( V_1 , V_125 , 0x1 ) ;
F_5 ( V_1 , V_126 , 0x1 ) ;
F_5 ( V_1 , V_127 , 0x1 ) ;
F_5 ( V_1 , V_128 , 0x1 ) ;
F_5 ( V_1 , V_129 , 0x1 ) ;
F_5 ( V_1 , V_130 , 0x1 ) ;
F_5 ( V_1 , V_131 , 0x0 ) ;
F_5 ( V_1 , V_132 , 0xffffffff ) ;
F_5 ( V_1 , V_133 , 0xffffffff ) ;
F_5 ( V_1 , V_84 , 0xffffffff ) ;
F_5 ( V_1 , V_134 , 0x7efefefe ) ;
F_5 ( V_1 , V_135 , 0x7efefefe ) ;
F_5 ( V_1 , V_136 , 0x7ffffffe ) ;
F_5 ( V_1 , V_137 , 0xfffff3c0 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_114 ; V_20 ++ )
F_5 ( V_1 , V_138 + 0x4 * V_20 , 0 ) ;
F_5 ( V_1 , V_139 , 1 ) ;
F_5 ( V_1 , V_140 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
F_7 ( V_1 , V_20 , V_141 , 0x855 ) ;
F_7 ( V_1 , V_20 , V_142 , 0x30b9908 ) ;
F_7 ( V_1 , V_20 , V_143 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_20 , V_144 , 0x10 ) ;
F_7 ( V_1 , V_20 , V_145 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_146 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_147 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_148 , 0x1000 ) ;
F_7 ( V_1 , V_20 , V_149 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_150 , 0x8ffffbff ) ;
F_7 ( V_1 , V_20 , V_151 , 0x23f801fc ) ;
F_7 ( V_1 , V_20 , V_152 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_153 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_154 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_155 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_156 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_157 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_158 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_159 , 0x199B694 ) ;
}
for ( V_20 = 0 ; V_20 < V_1 -> V_114 ; V_20 ++ ) {
F_5 ( V_1 ,
V_160 + ( V_20 * 0x14 ) ,
F_37 ( V_1 -> V_161 [ V_20 ] ) ) ;
F_5 ( V_1 , V_162 + ( V_20 * 0x14 ) ,
F_38 ( V_1 -> V_161 [ V_20 ] ) ) ;
F_5 ( V_1 , V_163 + ( V_20 * 0x14 ) ,
V_164 ) ;
F_5 ( V_1 , V_165 + ( V_20 * 0x14 ) ,
F_37 ( V_1 -> V_166 [ V_20 ] ) ) ;
F_5 ( V_1 , V_167 + ( V_20 * 0x14 ) ,
F_38 ( V_1 -> V_166 [ V_20 ] ) ) ;
F_5 ( V_1 , V_168 + ( V_20 * 0x14 ) ,
V_164 ) ;
}
F_5 ( V_1 , V_169 ,
F_38 ( V_1 -> V_170 ) ) ;
F_5 ( V_1 , V_171 ,
F_37 ( V_1 -> V_170 ) ) ;
F_5 ( V_1 , V_172 ,
F_38 ( V_1 -> V_173 ) ) ;
F_5 ( V_1 , V_174 ,
F_37 ( V_1 -> V_173 ) ) ;
F_5 ( V_1 , V_175 ,
F_38 ( V_1 -> V_176 ) ) ;
F_5 ( V_1 , V_177 ,
F_37 ( V_1 -> V_176 ) ) ;
F_5 ( V_1 , V_178 ,
F_38 ( V_1 -> V_179 ) ) ;
F_5 ( V_1 , V_180 ,
F_37 ( V_1 -> V_179 ) ) ;
F_5 ( V_1 , V_181 ,
F_38 ( V_1 -> V_182 ) ) ;
F_5 ( V_1 , V_183 ,
F_37 ( V_1 -> V_182 ) ) ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
int V_184 ;
V_184 = F_28 ( V_1 ) ;
if ( V_184 ) {
F_34 ( V_55 , L_7 , V_184 ) ;
return V_184 ;
}
F_30 ( 100 ) ;
F_35 ( V_1 ) ;
F_19 ( V_1 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 |= V_185 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_41 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 &= ~ V_185 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_42 ( struct V_1 * V_1 , int V_5 )
{
F_17 ( V_1 , V_5 ) ;
F_16 ( V_1 , V_5 ) ;
F_40 ( V_1 , V_5 ) ;
}
static void F_43 ( struct V_1 * V_1 , int V_5 )
{
F_41 ( V_1 , V_5 ) ;
}
static void F_44 ( struct V_1 * V_1 , int V_5 )
{
F_43 ( V_1 , V_5 ) ;
F_30 ( 100 ) ;
F_42 ( V_1 , V_5 ) ;
}
static void F_45 ( unsigned long V_186 )
{
struct V_1 * V_1 = (struct V_1 * ) V_186 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ )
F_42 ( V_1 , V_20 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
int V_20 ;
struct V_187 * V_188 = & V_1 -> V_188 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
F_7 ( V_1 , V_20 , V_150 , 0x6a ) ;
F_8 ( V_1 , V_20 , V_150 ) ;
}
F_47 ( V_188 , F_45 , ( unsigned long ) V_1 ) ;
F_48 ( V_188 , V_97 + V_189 ) ;
}
static void F_49 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_190 ;
V_190 = F_8 ( V_1 , V_5 , V_191 ) ;
V_190 |= V_192 ;
F_7 ( V_1 , V_5 , V_191 , V_190 ) ;
F_30 ( 1 ) ;
V_190 = F_8 ( V_1 , V_5 , V_191 ) ;
V_190 &= ~ V_192 ;
F_7 ( V_1 , V_5 , V_191 , V_190 ) ;
}
static int F_50 ( struct V_1 * V_1 , int V_193 )
{
int V_20 , V_10 = 0 ;
T_1 V_194 = F_1 ( V_1 , V_195 ) ;
T_1 V_196 = F_1 ( V_1 , V_197 ) ;
for ( V_20 = 0 ; V_20 < ( V_1 -> V_54 < 9 ? V_1 -> V_54 : 8 ) ; V_20 ++ )
if ( V_196 & 1 << V_20 )
if ( ( ( V_194 >> ( V_20 * 4 ) ) & 0xf ) == V_193 )
V_10 |= 1 << V_20 ;
if ( V_1 -> V_54 == 9 ) {
T_1 V_198 = F_1 ( V_1 , V_199 ) ;
if ( V_196 & 1 << 8 )
if ( ( ( V_198 & V_200 ) >>
V_201 ) == V_193 )
V_10 |= 1 << 9 ;
}
return V_10 ;
}
static int F_51 ( struct V_1 * V_1 , int * V_202 , int * V_203 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 V_204 , V_205 ;
int V_206 = V_1 -> V_206 ;
while ( 1 ) {
V_205 = F_3 ( V_1 ,
V_207 + ( V_206 * 0x14 ) ) ;
V_204 = F_3 ( V_1 ,
V_208 + ( V_206 * 0x14 ) ) ;
if ( V_204 == ( V_205 + 1 ) % V_164 ) {
V_206 = ( V_206 + 1 ) % V_1 -> V_114 ;
if ( V_206 == V_1 -> V_206 ) {
F_22 ( V_55 , L_8 ) ;
return - V_209 ;
}
continue;
}
break;
}
V_1 -> V_206 = ( V_206 + 1 ) % V_1 -> V_114 ;
* V_202 = V_206 ;
* V_203 = V_205 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_1 )
{
int V_210 = V_1 -> V_211 -> V_210 ;
int V_212 = V_1 -> V_211 -> V_212 ;
F_5 ( V_1 , V_207 + ( V_210 * 0x14 ) ,
++ V_212 % V_164 ) ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_213 * V_214 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
int V_219 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_217 * V_220 ;
int V_20 ;
if ( V_219 > V_221 ) {
F_34 ( V_55 , L_9 ,
V_219 ) ;
return - V_222 ;
}
V_214 -> V_223 = F_54 ( V_1 -> V_224 , V_225 ,
& V_214 -> V_226 ) ;
if ( ! V_214 -> V_223 )
return - V_227 ;
F_55 (scatter, sg, n_elem, i) {
struct V_228 * V_229 = & V_214 -> V_223 -> V_230 [ V_20 ] ;
V_229 -> V_231 = F_23 ( F_56 ( V_220 ) ) ;
V_229 -> V_232 = V_229 -> V_233 = 0 ;
V_229 -> V_234 = F_57 ( F_58 ( V_220 ) ) ;
V_229 -> V_235 = 0 ;
}
V_216 -> V_236 = F_23 ( V_214 -> V_226 ) ;
V_216 -> V_237 = F_57 ( V_219 << V_238 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_213 * V_214 )
{
struct V_239 * V_240 = V_214 -> V_240 ;
struct V_215 * V_216 = V_214 -> V_241 ;
struct V_7 * V_8 = V_240 -> V_55 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_62 * V_16 = V_214 -> V_16 ;
struct V_217 * V_242 , * V_243 ;
struct V_15 * V_19 = V_8 -> V_244 ;
T_4 V_245 ;
unsigned int V_246 , V_247 ;
int V_248 , V_184 ;
V_242 = & V_240 -> V_249 . V_250 ;
V_248 = F_60 ( V_55 , V_242 , 1 , V_251 ) ;
if ( ! V_248 )
return - V_227 ;
V_246 = F_58 ( V_242 ) ;
V_245 = F_56 ( V_242 ) ;
V_243 = & V_240 -> V_249 . V_252 ;
V_248 = F_60 ( V_55 , V_243 , 1 , V_253 ) ;
if ( ! V_248 ) {
V_184 = - V_227 ;
goto V_254;
}
V_247 = F_58 ( V_243 ) ;
if ( ( V_246 & 0x3 ) || ( V_247 & 0x3 ) ) {
V_184 = - V_222 ;
goto V_255;
}
V_216 -> V_256 = F_57 ( ( V_16 -> V_75 << V_257 ) |
( 1 << V_258 ) |
( 2 << V_259 ) ) ;
V_216 -> V_260 = F_57 ( ( V_19 -> V_26 << V_261 ) |
( 1 << V_262 ) |
( V_263 << V_264 ) ) ;
V_216 -> V_265 = F_57 ( ( ( ( V_246 - 4 ) / 4 ) << V_266 ) |
( V_267 / 4 <<
V_268 ) ) ;
V_216 -> V_269 = F_57 ( V_214 -> V_270 << V_271 ) ;
V_216 -> V_272 = F_23 ( V_245 ) ;
V_216 -> V_273 = F_23 ( V_214 -> V_274 ) ;
return 0 ;
V_255:
F_61 ( V_55 , & V_214 -> V_240 -> V_249 . V_252 , 1 ,
V_253 ) ;
V_254:
F_61 ( V_55 , & V_214 -> V_240 -> V_249 . V_250 , 1 ,
V_251 ) ;
return V_184 ;
}
static int F_62 ( struct V_1 * V_1 ,
struct V_213 * V_214 , int V_275 ,
struct V_276 * V_277 )
{
struct V_239 * V_240 = V_214 -> V_240 ;
struct V_215 * V_216 = V_214 -> V_241 ;
struct V_7 * V_8 = V_240 -> V_55 ;
struct V_15 * V_19 = V_8 -> V_244 ;
struct V_62 * V_16 = V_214 -> V_16 ;
struct V_278 * V_279 = & V_240 -> V_279 ;
struct V_280 * V_280 = V_279 -> V_281 ;
int V_282 = 0 , V_184 , V_283 = V_275 ;
T_5 * V_284 ;
T_1 V_260 = 0 , V_265 = 0 ;
V_216 -> V_256 = F_57 ( ( 1 << V_285 ) |
( 2 << V_286 ) |
( V_16 -> V_75 << V_257 ) |
( V_283 << V_258 ) |
( 1 << V_259 ) ) ;
V_260 = 1 << V_287 ;
if ( V_275 ) {
V_260 |= 2 << V_262 ;
V_260 |= V_263 << V_264 ;
} else {
V_260 |= 1 << V_262 ;
switch ( V_280 -> V_288 ) {
case V_251 :
V_282 = 1 ;
V_260 |= V_289 << V_264 ;
break;
case V_253 :
V_282 = 1 ;
V_260 |= V_290 << V_264 ;
break;
default:
V_260 &= ~ V_291 ;
}
}
V_260 |= V_19 -> V_26 << V_261 ;
V_216 -> V_260 = F_57 ( V_260 ) ;
V_265 = ( ( ( sizeof( struct V_292 ) + sizeof( struct V_293 )
+ 3 ) / 4 ) << V_266 ) |
( ( V_294 / 4 ) << V_268 ) |
( 2 << V_295 ) ;
V_216 -> V_265 = F_57 ( V_265 ) ;
V_216 -> V_269 = F_57 ( V_214 -> V_270 ) ;
if ( V_282 ) {
V_184 = F_53 ( V_1 , V_214 , V_216 , V_240 -> V_218 ,
V_214 -> V_219 ) ;
if ( V_184 )
return V_184 ;
}
V_216 -> V_296 = F_57 ( V_240 -> V_297 ) ;
V_216 -> V_272 = F_23 ( V_214 -> V_298 ) ;
V_216 -> V_273 = F_23 ( V_214 -> V_274 ) ;
V_284 = V_214 -> V_299 + sizeof( struct V_293 ) ;
memcpy ( V_284 , & V_240 -> V_279 . V_300 , 8 ) ;
if ( ! V_275 ) {
V_284 [ 9 ] = V_240 -> V_279 . V_301 |
( V_240 -> V_279 . V_302 << 3 ) ;
memcpy ( V_284 + 12 , V_240 -> V_279 . V_281 -> V_303 ,
V_240 -> V_279 . V_281 -> V_304 ) ;
} else {
V_284 [ 10 ] = V_277 -> V_277 ;
switch ( V_277 -> V_277 ) {
case V_305 :
case V_306 :
V_284 [ 12 ] =
( V_277 -> V_307 >> 8 ) & 0xff ;
V_284 [ 13 ] =
V_277 -> V_307 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_63 ( struct V_1 * V_1 , struct V_239 * V_240 ,
struct V_213 * V_214 )
{
struct V_308 * V_309 = & V_240 -> V_310 ;
struct V_311 * V_312 = (struct V_311 * ) V_309 -> V_313 ;
struct V_314 * V_315 = V_214 -> V_316 +
sizeof( struct V_317 ) ;
V_312 -> V_318 = sizeof( struct V_314 ) ;
memcpy ( & V_312 -> V_319 [ 0 ] , V_315 , sizeof( struct V_314 ) ) ;
V_309 -> V_320 = sizeof( * V_312 ) ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_239 * V_240 ,
struct V_213 * V_214 )
{
struct V_308 * V_309 = & V_240 -> V_310 ;
struct V_321 * V_322 = V_214 -> V_316 ;
T_1 V_323 = F_57 ( V_322 -> V_323 ) ;
T_1 V_324 = F_57 ( V_322 -> V_324 ) ;
T_6 V_325 = F_65 ( V_322 -> V_325 ) ;
T_6 V_326 = F_65 ( V_322 -> V_326 ) ;
T_1 V_327 = F_57 ( V_322 -> V_327 ) ;
int error = - 1 ;
if ( V_327 ) {
error = F_66 ( V_327 )
- 1 + V_328 ;
} else if ( V_326 ) {
error = F_66 ( V_326 )
- 1 + V_329 ;
} else if ( V_325 ) {
error = F_66 ( V_325 )
- 1 + V_330 ;
} else if ( V_324 ) {
error = F_66 ( V_324 )
- 1 + V_331 ;
} else if ( V_323 ) {
error = F_66 ( V_323 )
- 1 + V_332 ;
}
switch ( V_240 -> V_333 ) {
case V_334 :
{
switch ( error ) {
case V_335 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_339 ;
break;
}
case V_340 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_341 ;
break;
}
case V_342 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_343 ;
break;
}
case V_344 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_345 ;
break;
}
case V_346 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_347 ;
break;
}
case V_348 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_349 ;
break;
}
case V_350 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_351 ;
break;
}
case V_352 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_353 ;
break;
}
case V_354 :
{
V_309 -> V_336 = V_355 ;
break;
}
case V_356 :
{
V_309 -> V_336 = V_357 ;
break;
}
case V_358 :
{
V_309 -> V_336 = V_359 ;
break;
}
case V_360 :
{
V_309 -> V_336 = V_361 ;
V_309 -> V_362 = 0 ;
break;
}
case V_363 :
case V_364 :
{
V_309 -> V_362 = V_323 ;
V_309 -> V_336 = V_365 ;
break;
}
case V_366 :
{
V_309 -> V_336 = V_14 ;
V_214 -> abort = 1 ;
break;
}
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
{
V_309 -> V_336 = V_337 ;
V_309 -> V_338 = V_353 ;
break;
}
default:
break;
}
}
break;
case V_405 :
V_309 -> V_336 = V_406 ;
break;
case V_407 :
case V_408 :
case V_407 | V_408 :
{
switch ( error ) {
case V_354 :
case V_340 :
case V_335 :
{
V_309 -> V_312 = V_409 ;
V_309 -> V_336 = V_355 ;
break;
}
case V_342 :
case V_344 :
case V_346 :
case V_348 :
case V_350 :
case V_352 :
case V_410 :
{
V_309 -> V_336 = V_337 ;
break;
}
case V_358 :
{
V_309 -> V_336 = V_359 ;
break;
}
case V_360 :
{
V_309 -> V_336 = V_361 ;
break;
}
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_382 :
case V_411 :
case V_384 :
case V_385 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_389 :
case V_356 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_403 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_404 :
{
V_309 -> V_336 = V_337 ;
break;
}
default:
{
V_309 -> V_336 = V_434 ;
break;
}
}
F_63 ( V_1 , V_240 , V_214 ) ;
}
break;
default:
break;
}
}
static int
F_67 ( struct V_1 * V_1 , struct V_213 * V_214 ,
int abort )
{
struct V_239 * V_240 = V_214 -> V_240 ;
struct V_15 * V_19 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_308 * V_309 ;
struct V_7 * V_8 ;
enum V_435 V_436 ;
struct V_437 * V_438 =
V_1 -> V_439 [ V_214 -> V_440 ] ;
struct V_437 * V_439 =
& V_438 [ V_214 -> V_441 ] ;
if ( F_68 ( ! V_240 || ! V_240 -> V_442 || ! V_240 -> V_55 ) )
return - V_222 ;
V_309 = & V_240 -> V_310 ;
V_8 = V_240 -> V_55 ;
V_19 = V_8 -> V_244 ;
V_240 -> V_443 &=
~ ( V_444 | V_445 ) ;
V_240 -> V_443 |= V_446 ;
memset ( V_309 , 0 , sizeof( * V_309 ) ) ;
V_309 -> V_312 = V_447 ;
if ( F_68 ( ! V_19 || abort ) ) {
if ( ! V_19 )
F_27 ( V_55 , L_10 ) ;
V_309 -> V_336 = V_357 ;
goto V_448;
}
if ( ( V_439 -> V_256 & V_449 ) &&
( ! ( V_439 -> V_256 & V_450 ) ) ) {
F_64 ( V_1 , V_240 , V_214 ) ;
if ( F_68 ( V_214 -> abort ) ) {
F_69 ( V_1 -> V_451 , & V_214 -> V_452 ) ;
return V_309 -> V_336 ;
}
goto V_448;
}
switch ( V_240 -> V_333 ) {
case V_334 :
{
struct V_453 * V_454 = V_214 -> V_316 +
sizeof( struct V_317 ) ;
F_70 ( V_55 , V_240 , V_454 ) ;
break;
}
case V_405 :
{
struct V_217 * V_243 = & V_240 -> V_249 . V_252 ;
void * V_455 ;
V_309 -> V_336 = V_456 ;
V_455 = F_71 ( F_72 ( V_243 ) ) ;
F_61 ( V_55 , & V_240 -> V_249 . V_252 , 1 ,
V_253 ) ;
F_61 ( V_55 , & V_240 -> V_249 . V_250 , 1 ,
V_251 ) ;
memcpy ( V_455 + V_243 -> V_457 ,
V_214 -> V_316 +
sizeof( struct V_317 ) ,
F_58 ( V_243 ) ) ;
F_73 ( V_455 ) ;
break;
}
case V_407 :
case V_408 :
case V_407 | V_408 :
{
V_309 -> V_336 = V_456 ;
F_63 ( V_1 , V_240 , V_214 ) ;
break;
}
default:
V_309 -> V_336 = V_406 ;
break;
}
if ( ! V_214 -> V_16 -> V_458 ) {
F_34 ( V_55 , L_11 ,
V_214 -> V_16 -> V_459 . V_75 ) ;
V_309 -> V_336 = V_357 ;
}
V_448:
if ( V_19 && V_19 -> V_460 )
V_19 -> V_460 -- ;
F_74 ( V_1 , V_240 , V_214 ) ;
V_436 = V_309 -> V_336 ;
if ( V_240 -> V_461 )
V_240 -> V_461 ( V_240 ) ;
return V_436 ;
}
static T_5 F_75 ( T_5 V_281 , int V_462 )
{
switch ( V_281 ) {
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
return V_468 ;
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
return V_478 ;
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
return V_486 ;
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
return V_497 ;
default:
if ( V_462 == V_498 )
return V_497 ;
return V_478 ;
}
}
static int F_76 ( struct V_239 * V_240 , T_1 * V_499 )
{
struct V_500 * V_501 = V_240 -> V_502 ;
if ( V_501 ) {
if ( V_501 -> V_503 . V_504 == V_463 ||
V_501 -> V_503 . V_504 == V_464 ) {
* V_499 = V_501 -> V_499 ;
return 1 ;
}
}
return 0 ;
}
static int F_77 ( struct V_1 * V_1 ,
struct V_213 * V_214 )
{
struct V_239 * V_240 = V_214 -> V_240 ;
struct V_7 * V_8 = V_240 -> V_55 ;
struct V_7 * V_60 = V_8 -> V_61 ;
struct V_15 * V_19 = V_8 -> V_244 ;
struct V_215 * V_216 = V_214 -> V_241 ;
struct V_62 * V_16 = V_8 -> V_16 -> V_63 ;
T_5 * V_284 ;
int V_282 = 0 , V_184 = 0 , V_505 = 0 ;
T_1 V_260 = 0 , V_265 = 0 ;
V_216 -> V_256 = F_57 ( V_16 -> V_75 << V_257 ) ;
if ( V_60 && F_21 ( V_60 -> V_24 ) )
V_216 -> V_256 |= F_57 ( 3 << V_259 ) ;
else
V_216 -> V_256 |= F_57 ( 4 << V_259 ) ;
switch ( V_240 -> V_506 ) {
case V_251 :
V_282 = 1 ;
V_260 |= V_289 << V_264 ;
break;
case V_253 :
V_282 = 1 ;
V_260 |= V_290 << V_264 ;
break;
default:
V_260 &= ~ V_291 ;
}
if ( 0 == V_240 -> V_507 . V_508 . V_504 )
V_260 |= 1 << V_509 ;
V_260 |= ( F_75 ( V_240 -> V_507 . V_508 . V_504 , V_240 -> V_506 ) )
<< V_262 ;
V_260 |= V_19 -> V_26 << V_261 ;
V_216 -> V_260 = F_57 ( V_260 ) ;
if ( V_240 -> V_507 . V_510 && F_76 ( V_240 , & V_505 ) ) {
V_240 -> V_507 . V_508 . V_511 |= ( T_5 ) ( V_505 << 3 ) ;
V_265 |= V_505 << V_512 ;
}
V_265 |= ( V_513 / 4 ) << V_266 |
2 << V_295 ;
V_216 -> V_265 = F_57 ( V_265 ) ;
V_216 -> V_269 = F_57 ( V_214 -> V_270 ) ;
if ( V_282 ) {
V_184 = F_53 ( V_1 , V_214 , V_216 , V_240 -> V_218 ,
V_214 -> V_219 ) ;
if ( V_184 )
return V_184 ;
}
V_216 -> V_296 = F_57 ( V_240 -> V_297 ) ;
V_216 -> V_272 = F_23 ( V_214 -> V_298 ) ;
V_216 -> V_273 = F_23 ( V_214 -> V_274 ) ;
V_284 = V_214 -> V_299 ;
if ( F_78 ( ! V_240 -> V_507 . V_514 ) )
V_240 -> V_507 . V_508 . V_515 |= 0x80 ;
memcpy ( V_284 , & V_240 -> V_507 . V_508 , sizeof( struct V_516 ) ) ;
return 0 ;
}
static int F_79 ( int V_5 , struct V_1 * V_1 )
{
int V_20 , V_517 = 0 ;
T_1 V_518 , V_193 , V_519 , V_520 ;
struct V_521 * V_522 = & V_1 -> V_522 [ V_5 ] ;
struct V_523 * V_524 = & V_522 -> V_524 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 * V_525 = ( T_1 * ) V_524 -> V_525 ;
struct V_34 * V_75 = (struct V_34 * ) V_525 ;
F_7 ( V_1 , V_5 , V_155 , 1 ) ;
V_518 = F_1 ( V_1 , V_526 ) ;
if ( V_518 & ( 1 << V_5 ) )
goto V_527;
if ( V_5 == 8 ) {
T_1 V_198 = F_1 ( V_1 , V_199 ) ;
V_193 = ( V_198 & V_200 ) >>
V_201 ;
V_519 = ( V_198 & V_528 ) >>
V_529 ;
} else {
V_193 = F_1 ( V_1 , V_195 ) ;
V_193 = ( V_193 >> ( 4 * V_5 ) ) & 0xf ;
V_519 = F_1 ( V_1 , V_530 ) ;
V_519 = ( V_519 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_193 == 0xf ) {
F_34 ( V_55 , L_12 , V_5 ) ;
V_517 = V_531 ;
goto V_527;
}
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
T_1 V_532 = F_8 ( V_1 , V_5 ,
V_533 + ( V_20 * 4 ) ) ;
V_525 [ V_20 ] = F_18 ( V_532 ) ;
}
V_519 = F_1 ( V_1 , V_530 ) ;
V_519 = ( V_519 >> ( V_5 * 4 ) ) & 0xf ;
V_524 -> V_72 = V_519 ;
V_520 = F_8 ( V_1 , V_5 ,
V_534 ) ;
V_522 -> V_535 = V_520 & 0xf ;
V_522 -> V_536 = ( V_520 >> 4 ) & 0xf ;
V_524 -> V_537 = V_538 ;
memcpy ( V_524 -> V_539 , & V_75 -> V_45 , V_46 ) ;
F_80 ( V_55 , L_13 , V_5 , V_519 ) ;
V_522 -> V_193 = V_193 ;
V_522 -> V_540 &= ~ ( V_541 | V_542 ) ;
V_522 -> V_540 |= V_541 ;
V_522 -> V_543 = 1 ;
V_522 -> V_544 . V_545 = V_75 -> V_24 ;
V_522 -> V_546 = sizeof( struct V_34 ) ;
if ( V_522 -> V_544 . V_545 == V_37 )
V_522 -> V_544 . V_547 =
V_334 ;
else if ( V_522 -> V_544 . V_545 != V_25 )
V_522 -> V_544 . V_547 =
V_405 ;
F_69 ( V_1 -> V_451 , & V_522 -> V_548 ) ;
V_527:
F_7 ( V_1 , V_5 , V_145 ,
V_549 ) ;
F_7 ( V_1 , V_5 , V_155 , 0 ) ;
return V_517 ;
}
static int F_81 ( int V_5 , struct V_1 * V_1 )
{
int V_517 = 0 ;
T_1 V_93 , V_196 ;
F_7 ( V_1 , V_5 , V_153 , 1 ) ;
V_93 = F_8 ( V_1 , V_5 , V_31 ) ;
V_196 = F_1 ( V_1 , V_197 ) ;
F_82 ( V_1 , V_5 , ( V_196 & 1 << V_5 ) ? 1 : 0 ) ;
F_7 ( V_1 , V_5 , V_145 , V_550 ) ;
F_7 ( V_1 , V_5 , V_153 , 0 ) ;
return V_517 ;
}
static T_7 F_83 ( int V_551 , void * V_552 )
{
struct V_1 * V_1 = V_552 ;
T_1 V_553 ;
int V_5 = 0 ;
T_7 V_517 = V_554 ;
V_553 = ( F_1 ( V_1 , V_555 )
>> V_556 ) & 0x1ff ;
while ( V_553 ) {
if ( V_553 & 1 ) {
T_1 V_557 = F_8 ( V_1 , V_5 ,
V_145 ) ;
if ( V_557 & V_549 )
if ( F_79 ( V_5 , V_1 ) ) {
V_517 = V_531 ;
goto V_527;
}
if ( V_557 & V_550 )
if ( F_81 ( V_5 , V_1 ) ) {
V_517 = V_531 ;
goto V_527;
}
}
V_553 >>= 1 ;
V_5 ++ ;
}
V_527:
return V_517 ;
}
static void F_84 ( int V_5 , struct V_1 * V_1 )
{
struct V_521 * V_522 = & V_1 -> V_522 [ V_5 ] ;
struct V_523 * V_524 = & V_522 -> V_524 ;
struct V_558 * V_559 = & V_1 -> V_560 ;
unsigned long V_515 ;
F_7 ( V_1 , V_5 , V_156 , 1 ) ;
F_85 ( & V_1 -> V_21 , V_515 ) ;
V_559 -> V_561 ( V_524 , V_562 ) ;
F_86 ( & V_1 -> V_21 , V_515 ) ;
F_7 ( V_1 , V_5 , V_145 ,
V_563 ) ;
F_7 ( V_1 , V_5 , V_156 , 0 ) ;
}
static T_7 F_87 ( int V_551 , void * V_552 )
{
struct V_1 * V_1 = V_552 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 V_564 , V_565 , V_553 ;
int V_5 = 0 ;
V_564 = F_1 ( V_1 , V_136 ) ;
V_565 = V_564 ;
V_564 |= V_566 ;
F_5 ( V_1 , V_136 , V_564 ) ;
V_553 = ( F_1 ( V_1 , V_555 ) >>
V_567 ) & 0x1ff ;
while ( V_553 ) {
if ( V_553 & ( 1 << V_5 ) ) {
T_1 V_568 = F_8 ( V_1 , V_5 ,
V_145 ) ;
T_1 V_569 = F_8 ( V_1 , V_5 ,
V_146 ) ;
T_1 V_570 = F_8 ( V_1 , V_5 ,
V_147 ) ;
if ( V_569 ) {
if ( V_569 & ( V_571 |
V_572 ) )
F_88 ( L_14 ,
F_89 ( V_55 ) , V_569 ) ;
F_7 ( V_1 , V_5 ,
V_146 , V_569 ) ;
}
if ( V_570 )
F_7 ( V_1 , V_5 ,
V_147 , V_570 ) ;
if ( V_568 ) {
if ( V_568 & V_563 )
F_84 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_145 , V_568
& ( ~ V_573 )
& ( ~ V_549 )
& ( ~ V_550 ) ) ;
}
}
V_553 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_136 , V_565 ) ;
return V_554 ;
}
static T_7 F_90 ( int V_551 , void * V_552 )
{
struct V_574 * V_575 = V_552 ;
struct V_1 * V_1 = V_575 -> V_1 ;
struct V_213 * V_214 ;
struct V_58 * V_59 ;
struct V_437 * V_438 ;
T_1 V_557 , V_576 , V_577 , V_82 ;
int V_206 = V_575 -> V_75 ;
V_438 = V_1 -> V_439 [ V_206 ] ;
V_557 = F_1 ( V_1 , V_131 ) ;
F_5 ( V_1 , V_131 , 1 << V_206 ) ;
V_576 = F_1 ( V_1 , V_578 +
( 0x14 * V_206 ) ) ;
V_577 = F_1 ( V_1 , V_579 +
( 0x14 * V_206 ) ) ;
while ( V_576 != V_577 ) {
struct V_437 * V_439 ;
int V_580 ;
V_439 = & V_438 [ V_576 ] ;
if ( V_439 -> V_581 ) {
T_1 V_582 = V_439 -> V_581 ;
int V_583 = F_66 ( V_582 ) ;
V_82 = ( V_439 -> V_260 & V_584 ) >>
V_585 ;
V_59 = & V_1 -> V_59 [ V_82 ] ;
while ( V_583 ) {
T_8 * V_586 = & V_59 -> V_587 [ 0 ] ;
V_583 -= 1 ;
V_580 = ( V_586 [ V_583 / 5 ]
>> ( V_583 % 5 ) * 12 ) & 0xfff ;
V_214 = & V_1 -> V_588 [ V_580 ] ;
V_214 -> V_441 = V_576 ;
V_214 -> V_440 = V_206 ;
F_67 ( V_1 , V_214 , 0 ) ;
V_582 &= ~ ( 1 << V_583 ) ;
V_583 = F_66 ( V_582 ) ;
}
} else {
V_580 = ( V_439 -> V_260 ) & V_589 ;
V_214 = & V_1 -> V_588 [ V_580 ] ;
V_214 -> V_441 = V_576 ;
V_214 -> V_440 = V_206 ;
F_67 ( V_1 , V_214 , 0 ) ;
}
if ( ++ V_576 >= V_164 )
V_576 = 0 ;
}
F_5 ( V_1 , V_578 + ( 0x14 * V_206 ) , V_576 ) ;
return V_554 ;
}
static T_7 F_91 ( int V_551 , void * V_552 )
{
struct V_521 * V_522 = V_552 ;
struct V_1 * V_1 = V_522 -> V_1 ;
struct V_523 * V_524 = & V_522 -> V_524 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_590 * V_591 ;
struct V_314 * V_508 ;
T_1 V_565 , V_564 , V_592 , V_193 , V_519 , V_520 ;
T_7 V_517 = V_554 ;
T_5 V_539 [ V_46 ] = { 0 } ;
int V_5 , V_457 ;
V_5 = V_524 -> V_75 ;
V_591 = & V_1 -> V_591 [ V_5 ] ;
V_508 = & V_591 -> V_508 ;
V_457 = 4 * ( V_5 / 4 ) ;
V_564 = F_1 ( V_1 , V_134 + V_457 ) ;
F_5 ( V_1 , V_134 + V_457 ,
V_564 | 1 << ( ( V_5 % 4 ) * 8 ) ) ;
V_592 = F_1 ( V_1 , V_132 + V_457 ) ;
V_565 = V_592 & ( 1 << ( V_593 *
( V_5 % 4 ) ) ) ;
V_592 >>= V_593 * ( V_5 % 4 ) ;
if ( ( V_592 & V_594 ) == 0 ) {
F_22 ( V_55 , L_15 , V_5 ) ;
V_517 = V_531 ;
goto V_527;
}
if ( F_68 ( V_5 == 8 ) ) {
T_1 V_198 = F_1 ( V_1 , V_199 ) ;
V_193 = ( V_198 & V_200 ) >>
V_201 ;
V_519 = ( V_198 & V_528 ) >>
V_529 ;
} else {
V_193 = F_1 ( V_1 , V_195 ) ;
V_193 = ( V_193 >> ( 4 * V_5 ) ) & 0xf ;
V_519 = F_1 ( V_1 , V_530 ) ;
V_519 = ( V_519 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_193 == 0xf ) {
F_34 ( V_55 , L_16 , V_5 ) ;
V_517 = V_531 ;
goto V_527;
}
V_524 -> V_72 = V_519 ;
V_520 = F_8 ( V_1 , V_5 ,
V_534 ) ;
V_522 -> V_535 = V_520 & 0xf ;
V_522 -> V_536 = ( V_520 >> 4 ) & 0xf ;
V_524 -> V_537 = V_595 ;
V_539 [ 0 ] = 0x50 ;
V_539 [ 7 ] = V_5 ;
memcpy ( V_524 -> V_539 , V_539 , V_46 ) ;
memcpy ( V_524 -> V_525 , V_508 , sizeof( struct V_314 ) ) ;
F_80 ( V_55 , L_17 , V_5 , V_519 ) ;
V_522 -> V_540 &= ~ ( V_541 | V_542 ) ;
V_522 -> V_193 = V_193 ;
V_522 -> V_540 |= V_542 ;
V_522 -> V_543 = 1 ;
V_522 -> V_544 . V_545 = V_68 ;
V_522 -> V_546 = sizeof( struct V_314 ) ;
V_522 -> V_544 . V_547 = V_407 ;
F_69 ( V_1 -> V_451 , & V_522 -> V_548 ) ;
V_527:
F_5 ( V_1 , V_132 + V_457 , V_565 ) ;
F_5 ( V_1 , V_134 + V_457 , V_564 ) ;
return V_517 ;
}
static int F_92 ( struct V_1 * V_1 )
{
struct V_596 * V_56 = V_1 -> V_56 ;
struct V_8 * V_55 = & V_56 -> V_55 ;
int V_20 , V_597 , V_184 , V_598 [ 128 ] ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ )
V_598 [ V_20 ] = F_93 ( V_56 , V_20 ) ;
for ( V_20 = 0 ; V_20 < V_599 ; V_20 ++ ) {
int V_270 = V_20 ;
V_597 = V_598 [ V_270 + 1 ] ;
if ( ! V_597 ) {
F_34 ( V_55 , L_18 ,
V_270 ) ;
return - V_600 ;
}
V_184 = F_94 ( V_55 , V_597 , V_601 [ V_20 ] , 0 ,
V_602 L_19 , V_1 ) ;
if ( V_184 ) {
F_34 ( V_55 , L_20
L_21 ,
V_597 , V_184 ) ;
return - V_600 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
struct V_521 * V_522 = & V_1 -> V_522 [ V_20 ] ;
int V_270 = V_20 + 72 ;
V_597 = V_598 [ V_270 ] ;
if ( ! V_597 ) {
F_34 ( V_55 , L_18 ,
V_270 ) ;
return - V_600 ;
}
V_184 = F_94 ( V_55 , V_597 , F_91 , 0 ,
V_602 L_22 , V_522 ) ;
if ( V_184 ) {
F_34 ( V_55 , L_20
L_23 ,
V_597 , V_184 ) ;
return - V_600 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_114 ; V_20 ++ ) {
int V_270 = V_20 + 96 ;
V_597 = V_598 [ V_270 ] ;
if ( ! V_597 ) {
F_34 ( V_55 ,
L_24 ,
V_270 ) ;
return - V_600 ;
}
V_184 = F_94 ( V_55 , V_597 , F_90 , 0 ,
V_602 L_25 , & V_1 -> V_575 [ V_20 ] ) ;
if ( V_184 ) {
F_34 ( V_55 ,
L_26 ,
V_597 , V_184 ) ;
return - V_600 ;
}
}
return 0 ;
}
static int F_95 ( struct V_1 * V_1 )
{
int V_184 ;
V_184 = F_39 ( V_1 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_92 ( V_1 ) ;
if ( V_184 )
return V_184 ;
F_46 ( V_1 ) ;
return 0 ;
}
static int F_96 ( struct V_596 * V_56 )
{
return F_97 ( V_56 , & V_603 ) ;
}
static int F_98 ( struct V_596 * V_56 )
{
return F_99 ( V_56 ) ;
}
