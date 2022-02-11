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
F_18 ( V_36 [ 1 ] ) ) ;
F_7 ( V_1 , V_5 , V_50 ,
F_18 ( V_36 [ 2 ] ) ) ;
F_7 ( V_1 , V_5 , V_51 ,
F_18 ( V_36 [ 3 ] ) ) ;
F_7 ( V_1 , V_5 , V_52 ,
F_18 ( V_36 [ 4 ] ) ) ;
F_7 ( V_1 , V_5 , V_53 ,
F_18 ( V_36 [ 5 ] ) ) ;
}
static void F_19 ( struct V_1 * V_1 ,
struct V_15 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_29 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
T_3 V_56 , V_26 = V_19 -> V_26 ;
struct V_57 * V_58 = & V_1 -> V_58 [ V_26 ] ;
struct V_7 * V_59 = V_8 -> V_60 ;
struct V_61 * V_16 = V_8 -> V_16 -> V_62 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_56 = 0 ;
switch ( V_19 -> V_24 ) {
case V_37 :
case V_63 :
case V_64 :
V_56 = V_65 << V_66 ;
break;
case V_67 :
case V_68 :
if ( V_59 && F_20 ( V_59 -> V_24 ) )
V_56 = V_69 << V_66 ;
else
V_56 = V_70 << V_66 ;
break;
default:
F_21 ( V_54 , L_1 ,
V_19 -> V_24 ) ;
}
V_56 |= ( ( 1 << V_71 ) |
( V_8 -> V_72 << V_73 ) |
( 1 << V_74 ) |
( V_16 -> V_75 << V_76 ) ) ;
V_58 -> V_56 = F_22 ( V_56 ) ;
memcpy ( & V_58 -> V_45 , V_8 -> V_45 , V_46 ) ;
V_58 -> V_45 = F_23 ( V_58 -> V_45 ) ;
if ( ! F_10 ( V_8 ) )
V_58 -> V_77 = F_22 ( ( 500ULL << V_78 ) |
( 0x1ULL << V_79 ) |
( 0x32ULL << V_80 ) |
( 0x1ULL << V_81 ) ) ;
}
static void F_24 ( struct V_1 * V_1 ,
struct V_15 * V_19 )
{
T_3 V_56 , V_82 = V_19 -> V_26 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_57 * V_58 = & V_1 -> V_58 [ V_82 ] ;
T_1 V_83 = F_1 ( V_1 , V_84 ) ;
int V_20 ;
if ( V_85 & V_83 )
F_5 ( V_1 , V_84 ,
V_85 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_83 = F_1 ( V_1 , V_86 ) ;
V_83 |= V_87 | ( V_82 & V_88 ) ;
F_5 ( V_1 , V_86 , V_83 ) ;
F_25 ( 10 ) ;
V_83 = F_1 ( V_1 , V_84 ) ;
if ( V_85 & V_83 ) {
F_26 ( V_54 , L_2 ) ;
V_56 = F_22 ( V_58 -> V_56 ) ;
V_56 &= ~ ( 1 << V_71 ) ;
F_5 ( V_1 , V_84 ,
V_85 ) ;
V_1 -> V_23 [ V_82 ] . V_24 = V_25 ;
V_1 -> V_23 [ V_82 ] . V_27 = V_28 ;
F_5 ( V_1 , V_86 , 0 ) ;
F_26 ( V_54 , L_3 ) ;
break;
}
}
}
static int F_27 ( struct V_1 * V_1 )
{
int V_20 , V_89 ;
T_1 V_4 ;
unsigned long V_90 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
if ( V_1 -> V_91 == 9 )
V_89 = 0x1fffff ;
else
V_89 = 0x7ffff ;
F_5 ( V_1 , V_92 , 0 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_91 ; V_20 ++ ) {
T_1 V_93 = F_8 ( V_1 , V_20 , V_31 ) ;
V_93 &= ~ V_94 ;
F_7 ( V_1 , V_20 , V_31 , V_93 ) ;
}
F_25 ( 50 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_91 ; V_20 ++ ) {
T_1 V_95 , V_96 ;
V_90 = V_97 + F_28 ( 1000 ) ;
while ( 1 ) {
V_95 = F_8 ( V_1 , V_20 ,
V_98 ) ;
V_96 = F_8 ( V_1 , V_20 ,
V_99 ) ;
if ( ! ( V_95 & V_100 ) &&
! ( V_96 & V_101 ) )
break;
F_29 ( 20 ) ;
if ( F_30 ( V_97 , V_90 ) )
return - V_102 ;
}
}
V_90 = V_97 + F_28 ( 1000 ) ;
while ( 1 ) {
T_1 V_103 =
F_1 ( V_1 , V_104 ) ;
if ( V_103 == 0 )
break;
F_29 ( 20 ) ;
if ( F_30 ( V_97 , V_90 ) )
return - V_102 ;
}
if ( F_31 ( V_54 ) ) {
T_4 V_105 ;
V_105 = F_32 ( F_31 ( V_54 ) , L_4 , NULL , NULL ) ;
if ( F_33 ( V_105 ) ) {
F_34 ( V_54 , L_5 ) ;
return - V_102 ;
}
} else if ( V_1 -> V_106 ) {
F_35 ( V_1 -> V_106 , V_1 -> V_107 ,
V_89 ) ;
F_35 ( V_1 -> V_106 , V_1 -> V_108 + 4 ,
V_89 ) ;
F_29 ( 1 ) ;
F_36 ( V_1 -> V_106 , V_1 -> V_109 , & V_4 ) ;
if ( V_89 != ( V_4 & V_89 ) ) {
F_34 ( V_54 , L_6 ) ;
return - V_102 ;
}
F_35 ( V_1 -> V_106 , V_1 -> V_107 + 4 ,
V_89 ) ;
F_35 ( V_1 -> V_106 , V_1 -> V_108 ,
V_89 ) ;
F_29 ( 1 ) ;
F_36 ( V_1 -> V_106 , V_1 -> V_109 ,
& V_4 ) ;
if ( V_4 & V_89 ) {
F_34 ( V_54 , L_7 ) ;
return - V_102 ;
}
} else
F_21 ( V_54 , L_8 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
int V_20 ;
if ( F_38 ( V_54 , L_9 ) ) {
F_5 ( V_1 , V_110 , 0x2020 ) ;
F_5 ( V_1 , V_111 ,
0x2020 ) ;
}
F_5 ( V_1 , V_92 ,
( T_1 ) ( ( 1ULL << V_1 -> V_112 ) - 1 ) ) ;
F_5 ( V_1 , V_113 , 0xc0000000 ) ;
F_5 ( V_1 , V_114 , 0x10000 ) ;
F_5 ( V_1 , V_115 , 0x108 ) ;
F_5 ( V_1 , V_116 , 0x7FF ) ;
F_5 ( V_1 , V_117 , 0x1 ) ;
F_5 ( V_1 , V_118 , 0x1F4 ) ;
F_5 ( V_1 , V_119 , 0x32 ) ;
F_5 ( V_1 , V_120 , 0x1 ) ;
F_5 ( V_1 , V_121 , 0x1 ) ;
F_5 ( V_1 , V_122 , 0x1 ) ;
F_5 ( V_1 , V_123 , 0x1 ) ;
F_5 ( V_1 , V_124 , 0x1 ) ;
F_5 ( V_1 , V_125 , 0x1 ) ;
F_5 ( V_1 , V_126 , 0x1 ) ;
F_5 ( V_1 , V_127 , 0x1 ) ;
F_5 ( V_1 , V_128 , 0x1 ) ;
F_5 ( V_1 , V_129 , 0x0 ) ;
F_5 ( V_1 , V_130 , 0xffffffff ) ;
F_5 ( V_1 , V_131 , 0xffffffff ) ;
F_5 ( V_1 , V_84 , 0xffffffff ) ;
F_5 ( V_1 , V_132 , 0x7efefefe ) ;
F_5 ( V_1 , V_133 , 0x7efefefe ) ;
F_5 ( V_1 , V_134 , 0x7ffffffe ) ;
F_5 ( V_1 , V_135 , 0xfffff3c0 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_112 ; V_20 ++ )
F_5 ( V_1 , V_136 + 0x4 * V_20 , 0 ) ;
F_5 ( V_1 , V_137 , 1 ) ;
F_5 ( V_1 , V_138 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_1 -> V_91 ; V_20 ++ ) {
F_7 ( V_1 , V_20 , V_139 , 0x855 ) ;
F_7 ( V_1 , V_20 , V_140 , 0x30b9908 ) ;
F_7 ( V_1 , V_20 , V_141 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_20 , V_142 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_143 , 0x2 ) ;
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
for ( V_20 = 0 ; V_20 < V_1 -> V_112 ; V_20 ++ ) {
F_5 ( V_1 ,
V_160 + ( V_20 * 0x14 ) ,
F_39 ( V_1 -> V_161 [ V_20 ] ) ) ;
F_5 ( V_1 , V_162 + ( V_20 * 0x14 ) ,
F_40 ( V_1 -> V_161 [ V_20 ] ) ) ;
F_5 ( V_1 , V_163 + ( V_20 * 0x14 ) ,
V_164 ) ;
F_5 ( V_1 , V_165 + ( V_20 * 0x14 ) ,
F_39 ( V_1 -> V_166 [ V_20 ] ) ) ;
F_5 ( V_1 , V_167 + ( V_20 * 0x14 ) ,
F_40 ( V_1 -> V_166 [ V_20 ] ) ) ;
F_5 ( V_1 , V_168 + ( V_20 * 0x14 ) ,
V_164 ) ;
}
F_5 ( V_1 , V_169 ,
F_40 ( V_1 -> V_170 ) ) ;
F_5 ( V_1 , V_171 ,
F_39 ( V_1 -> V_170 ) ) ;
F_5 ( V_1 , V_172 ,
F_40 ( V_1 -> V_173 ) ) ;
F_5 ( V_1 , V_174 ,
F_39 ( V_1 -> V_173 ) ) ;
F_5 ( V_1 , V_175 ,
F_40 ( V_1 -> V_176 ) ) ;
F_5 ( V_1 , V_177 ,
F_39 ( V_1 -> V_176 ) ) ;
F_5 ( V_1 , V_178 ,
F_40 ( V_1 -> V_179 ) ) ;
F_5 ( V_1 , V_180 ,
F_39 ( V_1 -> V_179 ) ) ;
F_5 ( V_1 , V_181 ,
F_40 ( V_1 -> V_182 ) ) ;
F_5 ( V_1 , V_183 ,
F_39 ( V_1 -> V_182 ) ) ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
int V_184 ;
V_184 = F_27 ( V_1 ) ;
if ( V_184 ) {
F_34 ( V_54 , L_10 , V_184 ) ;
return V_184 ;
}
F_29 ( 100 ) ;
F_37 ( V_1 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 |= V_185 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_43 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 &= ~ V_185 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_44 ( struct V_1 * V_1 , int V_5 )
{
F_17 ( V_1 , V_5 ) ;
F_16 ( V_1 , V_5 ) ;
F_42 ( V_1 , V_5 ) ;
}
static void F_45 ( struct V_1 * V_1 , int V_5 )
{
F_43 ( V_1 , V_5 ) ;
}
static void F_46 ( struct V_1 * V_1 , int V_5 )
{
F_45 ( V_1 , V_5 ) ;
F_29 ( 100 ) ;
F_44 ( V_1 , V_5 ) ;
}
static void F_47 ( unsigned long V_186 )
{
struct V_1 * V_1 = (struct V_1 * ) V_186 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_91 ; V_20 ++ )
F_44 ( V_1 , V_20 ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_187 * V_188 = & V_1 -> V_188 ;
F_49 ( V_188 , F_47 , ( unsigned long ) V_1 ) ;
F_50 ( V_188 , V_97 + V_189 ) ;
}
static void F_51 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_190 ;
V_190 = F_8 ( V_1 , V_5 , V_142 ) ;
V_190 |= V_191 ;
F_7 ( V_1 , V_5 , V_142 , V_190 ) ;
F_29 ( 1 ) ;
V_190 = F_8 ( V_1 , V_5 , V_142 ) ;
V_190 &= ~ V_191 ;
F_7 ( V_1 , V_5 , V_142 , V_190 ) ;
}
static int F_52 ( struct V_1 * V_1 , int V_192 )
{
int V_20 , V_10 = 0 ;
T_1 V_193 = F_1 ( V_1 , V_194 ) ;
T_1 V_195 = F_1 ( V_1 , V_196 ) ;
for ( V_20 = 0 ; V_20 < ( V_1 -> V_91 < 9 ? V_1 -> V_91 : 8 ) ; V_20 ++ )
if ( V_195 & 1 << V_20 )
if ( ( ( V_193 >> ( V_20 * 4 ) ) & 0xf ) == V_192 )
V_10 |= 1 << V_20 ;
if ( V_1 -> V_91 == 9 ) {
T_1 V_197 = F_1 ( V_1 , V_198 ) ;
if ( V_195 & 1 << 8 )
if ( ( ( V_197 & V_199 ) >>
V_200 ) == V_192 )
V_10 |= 1 << 9 ;
}
return V_10 ;
}
static int F_53 ( struct V_1 * V_1 , int * V_201 , int * V_105 )
{
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_202 * V_203 ;
T_1 V_204 , V_205 ;
int V_206 = V_1 -> V_206 ;
while ( 1 ) {
V_203 = & V_1 -> V_203 [ V_206 ] ;
V_205 = V_203 -> V_207 ;
V_204 = F_3 ( V_1 ,
V_208 + ( V_206 * 0x14 ) ) ;
if ( V_204 == ( V_205 + 1 ) % V_164 ) {
V_206 = ( V_206 + 1 ) % V_1 -> V_112 ;
if ( V_206 == V_1 -> V_206 ) {
F_21 ( V_54 , L_11 ) ;
return - V_209 ;
}
continue;
}
break;
}
V_1 -> V_206 = ( V_206 + 1 ) % V_1 -> V_112 ;
* V_201 = V_206 ;
* V_105 = V_205 ;
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
int V_210 = V_1 -> V_211 -> V_210 ;
int V_212 = V_1 -> V_211 -> V_212 ;
struct V_202 * V_203 = & V_1 -> V_203 [ V_210 ] ;
V_203 -> V_207 = ++ V_212 % V_164 ;
F_5 ( V_1 , V_213 + ( V_210 * 0x14 ) ,
V_203 -> V_207 ) ;
}
static int F_55 ( struct V_1 * V_1 ,
struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_218 * V_219 ,
int V_220 )
{
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_218 * V_221 ;
int V_20 ;
if ( V_220 > V_222 ) {
F_34 ( V_54 , L_12 ,
V_220 ) ;
return - V_223 ;
}
V_215 -> V_224 = F_56 ( V_1 -> V_225 , V_226 ,
& V_215 -> V_227 ) ;
if ( ! V_215 -> V_224 )
return - V_228 ;
F_57 (scatter, sg, n_elem, i) {
struct V_229 * V_230 = & V_215 -> V_224 -> V_231 [ V_20 ] ;
V_230 -> V_232 = F_22 ( F_58 ( V_221 ) ) ;
V_230 -> V_233 = V_230 -> V_234 = 0 ;
V_230 -> V_235 = F_59 ( F_60 ( V_221 ) ) ;
V_230 -> V_236 = 0 ;
}
V_217 -> V_237 = F_22 ( V_215 -> V_227 ) ;
V_217 -> V_238 = F_59 ( V_220 << V_239 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_1 ,
struct V_214 * V_215 )
{
struct V_240 * V_241 = V_215 -> V_241 ;
struct V_216 * V_217 = V_215 -> V_242 ;
struct V_7 * V_8 = V_241 -> V_54 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_61 * V_16 = V_215 -> V_16 ;
struct V_218 * V_243 , * V_244 ;
struct V_15 * V_19 = V_8 -> V_245 ;
T_5 V_246 ;
unsigned int V_247 , V_248 ;
int V_249 , V_184 ;
V_243 = & V_241 -> V_250 . V_251 ;
V_249 = F_62 ( V_54 , V_243 , 1 , V_252 ) ;
if ( ! V_249 )
return - V_228 ;
V_247 = F_60 ( V_243 ) ;
V_246 = F_58 ( V_243 ) ;
V_244 = & V_241 -> V_250 . V_253 ;
V_249 = F_62 ( V_54 , V_244 , 1 , V_254 ) ;
if ( ! V_249 ) {
V_184 = - V_228 ;
goto V_255;
}
V_248 = F_60 ( V_244 ) ;
if ( ( V_247 & 0x3 ) || ( V_248 & 0x3 ) ) {
V_184 = - V_223 ;
goto V_256;
}
V_217 -> V_257 = F_59 ( ( V_16 -> V_75 << V_258 ) |
( 1 << V_259 ) |
( 2 << V_260 ) ) ;
V_217 -> V_261 = F_59 ( ( V_19 -> V_26 << V_262 ) |
( 1 << V_263 ) |
( V_264 << V_265 ) ) ;
V_217 -> V_266 = F_59 ( ( ( ( V_247 - 4 ) / 4 ) << V_267 ) |
( V_268 / 4 <<
V_269 ) ) ;
V_217 -> V_270 = F_59 ( V_215 -> V_271 << V_272 ) ;
V_217 -> V_273 = F_22 ( V_246 ) ;
V_217 -> V_274 = F_22 ( V_215 -> V_275 ) ;
return 0 ;
V_256:
F_63 ( V_54 , & V_215 -> V_241 -> V_250 . V_253 , 1 ,
V_254 ) ;
V_255:
F_63 ( V_54 , & V_215 -> V_241 -> V_250 . V_251 , 1 ,
V_252 ) ;
return V_184 ;
}
static int F_64 ( struct V_1 * V_1 ,
struct V_214 * V_215 , int V_276 ,
struct V_277 * V_278 )
{
struct V_240 * V_241 = V_215 -> V_241 ;
struct V_216 * V_217 = V_215 -> V_242 ;
struct V_7 * V_8 = V_241 -> V_54 ;
struct V_15 * V_19 = V_8 -> V_245 ;
struct V_61 * V_16 = V_215 -> V_16 ;
struct V_279 * V_280 = & V_241 -> V_280 ;
struct V_281 * V_281 = V_280 -> V_282 ;
int V_283 = 0 , V_184 , V_284 = V_276 ;
T_6 * V_285 ;
T_1 V_261 = 0 , V_266 = 0 ;
V_217 -> V_257 = F_59 ( ( 1 << V_286 ) |
( 2 << V_287 ) |
( V_16 -> V_75 << V_258 ) |
( V_284 << V_259 ) |
( 1 << V_260 ) ) ;
V_261 = 1 << V_288 ;
if ( V_276 ) {
V_261 |= 2 << V_263 ;
V_261 |= V_264 << V_265 ;
} else {
V_261 |= 1 << V_263 ;
switch ( V_281 -> V_289 ) {
case V_252 :
V_283 = 1 ;
V_261 |= V_290 << V_265 ;
break;
case V_254 :
V_283 = 1 ;
V_261 |= V_291 << V_265 ;
break;
default:
V_261 &= ~ V_292 ;
}
}
V_261 |= V_19 -> V_26 << V_262 ;
V_217 -> V_261 = F_59 ( V_261 ) ;
V_266 = ( ( ( sizeof( struct V_293 ) + sizeof( struct V_294 )
+ 3 ) / 4 ) << V_267 ) |
( ( V_295 / 4 ) << V_269 ) |
( 2 << V_296 ) ;
V_217 -> V_266 = F_59 ( V_266 ) ;
V_217 -> V_270 = F_59 ( V_215 -> V_271 ) ;
if ( V_283 ) {
V_184 = F_55 ( V_1 , V_215 , V_217 , V_241 -> V_219 ,
V_215 -> V_220 ) ;
if ( V_184 )
return V_184 ;
}
V_217 -> V_297 = F_59 ( V_241 -> V_298 ) ;
V_217 -> V_273 = F_22 ( V_215 -> V_299 ) ;
V_217 -> V_274 = F_22 ( V_215 -> V_275 ) ;
V_285 = V_215 -> V_300 + sizeof( struct V_294 ) ;
memcpy ( V_285 , & V_241 -> V_280 . V_301 , 8 ) ;
if ( ! V_276 ) {
V_285 [ 9 ] = V_241 -> V_280 . V_302 |
( V_241 -> V_280 . V_303 << 3 ) ;
memcpy ( V_285 + 12 , V_241 -> V_280 . V_282 -> V_304 ,
V_241 -> V_280 . V_282 -> V_305 ) ;
} else {
V_285 [ 10 ] = V_278 -> V_278 ;
switch ( V_278 -> V_278 ) {
case V_306 :
case V_307 :
V_285 [ 12 ] =
( V_278 -> V_308 >> 8 ) & 0xff ;
V_285 [ 13 ] =
V_278 -> V_308 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_65 ( struct V_1 * V_1 , struct V_240 * V_241 ,
struct V_214 * V_215 )
{
struct V_309 * V_310 = & V_241 -> V_311 ;
struct V_312 * V_313 = (struct V_312 * ) V_310 -> V_314 ;
struct V_315 * V_316 = V_215 -> V_317 +
sizeof( struct V_318 ) ;
V_313 -> V_319 = sizeof( struct V_315 ) ;
memcpy ( & V_313 -> V_320 [ 0 ] , V_316 , sizeof( struct V_315 ) ) ;
V_310 -> V_321 = sizeof( * V_313 ) ;
}
static void F_66 ( struct V_1 * V_1 ,
struct V_240 * V_241 ,
struct V_214 * V_215 )
{
struct V_309 * V_310 = & V_241 -> V_311 ;
struct V_322 * V_323 = V_215 -> V_317 ;
T_1 V_324 = F_59 ( V_323 -> V_324 ) ;
T_1 V_325 = F_59 ( V_323 -> V_325 ) ;
T_7 V_326 = F_67 ( V_323 -> V_326 ) ;
T_7 V_327 = F_67 ( V_323 -> V_327 ) ;
T_1 V_328 = F_59 ( V_323 -> V_328 ) ;
int error = - 1 ;
if ( V_328 ) {
error = F_68 ( V_328 )
- 1 + V_329 ;
} else if ( V_327 ) {
error = F_68 ( V_327 )
- 1 + V_330 ;
} else if ( V_326 ) {
error = F_68 ( V_326 )
- 1 + V_331 ;
} else if ( V_325 ) {
error = F_68 ( V_325 )
- 1 + V_332 ;
} else if ( V_324 ) {
error = F_68 ( V_324 )
- 1 + V_333 ;
}
switch ( V_241 -> V_334 ) {
case V_335 :
{
switch ( error ) {
case V_336 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_340 ;
break;
}
case V_341 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_342 ;
break;
}
case V_343 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_344 ;
break;
}
case V_345 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_346 ;
break;
}
case V_347 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_348 ;
break;
}
case V_349 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_350 ;
break;
}
case V_351 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_352 ;
break;
}
case V_353 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_354 ;
break;
}
case V_355 :
{
V_310 -> V_337 = V_356 ;
break;
}
case V_357 :
{
V_310 -> V_337 = V_358 ;
break;
}
case V_359 :
{
V_310 -> V_337 = V_360 ;
break;
}
case V_361 :
{
V_310 -> V_337 = V_362 ;
V_310 -> V_363 = 0 ;
break;
}
case V_364 :
case V_365 :
{
V_310 -> V_363 = V_324 ;
V_310 -> V_337 = V_366 ;
break;
}
case V_367 :
{
V_310 -> V_337 = V_14 ;
V_215 -> abort = 1 ;
break;
}
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
case V_405 :
{
V_310 -> V_337 = V_338 ;
V_310 -> V_339 = V_354 ;
break;
}
default:
break;
}
}
break;
case V_406 :
V_310 -> V_337 = V_407 ;
break;
case V_408 :
case V_409 :
case V_408 | V_409 :
{
switch ( error ) {
case V_355 :
case V_341 :
case V_336 :
{
V_310 -> V_313 = V_410 ;
V_310 -> V_337 = V_356 ;
break;
}
case V_343 :
case V_345 :
case V_347 :
case V_349 :
case V_351 :
case V_353 :
case V_411 :
{
V_310 -> V_337 = V_338 ;
break;
}
case V_359 :
{
V_310 -> V_337 = V_360 ;
break;
}
case V_361 :
{
V_310 -> V_337 = V_362 ;
break;
}
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
case V_383 :
case V_412 :
case V_385 :
case V_386 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_390 :
case V_357 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_404 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_405 :
{
V_310 -> V_337 = V_338 ;
break;
}
default:
{
V_310 -> V_337 = V_435 ;
break;
}
}
F_65 ( V_1 , V_241 , V_215 ) ;
}
break;
default:
break;
}
}
static int
F_69 ( struct V_1 * V_1 , struct V_214 * V_215 ,
int abort )
{
struct V_240 * V_241 = V_215 -> V_241 ;
struct V_15 * V_19 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_309 * V_310 ;
struct V_7 * V_8 ;
enum V_436 V_437 ;
struct V_438 * V_439 =
V_1 -> V_440 [ V_215 -> V_441 ] ;
struct V_438 * V_440 =
& V_439 [ V_215 -> V_442 ] ;
if ( F_70 ( ! V_241 || ! V_241 -> V_443 || ! V_241 -> V_54 ) )
return - V_223 ;
V_310 = & V_241 -> V_311 ;
V_8 = V_241 -> V_54 ;
V_19 = V_8 -> V_245 ;
V_241 -> V_444 &=
~ ( V_445 | V_446 ) ;
V_241 -> V_444 |= V_447 ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
V_310 -> V_313 = V_448 ;
if ( F_70 ( ! V_19 || abort ) ) {
if ( ! V_19 )
F_26 ( V_54 , L_13 ) ;
V_310 -> V_337 = V_358 ;
goto V_449;
}
switch ( ( V_440 -> V_257 & V_450 )
>> V_451 ) {
case V_452 :
V_310 -> V_337 = V_453 ;
goto V_449;
case V_454 :
V_310 -> V_337 = V_455 ;
goto V_449;
case V_456 :
V_310 -> V_337 = V_455 ;
goto V_449;
case V_457 :
V_310 -> V_337 = V_458 ;
goto V_449;
default:
break;
}
if ( ( V_440 -> V_257 & V_459 ) &&
( ! ( V_440 -> V_257 & V_460 ) ) ) {
F_66 ( V_1 , V_241 , V_215 ) ;
if ( F_70 ( V_215 -> abort ) ) {
F_71 ( V_1 -> V_461 , & V_215 -> V_462 ) ;
return V_310 -> V_337 ;
}
goto V_449;
}
switch ( V_241 -> V_334 ) {
case V_335 :
{
struct V_463 * V_464 = V_215 -> V_317 +
sizeof( struct V_318 ) ;
F_72 ( V_54 , V_241 , V_464 ) ;
break;
}
case V_406 :
{
struct V_218 * V_244 = & V_241 -> V_250 . V_253 ;
void * V_465 ;
V_310 -> V_337 = V_466 ;
V_465 = F_73 ( F_74 ( V_244 ) ) ;
F_63 ( V_54 , & V_241 -> V_250 . V_253 , 1 ,
V_254 ) ;
F_63 ( V_54 , & V_241 -> V_250 . V_251 , 1 ,
V_252 ) ;
memcpy ( V_465 + V_244 -> V_467 ,
V_215 -> V_317 +
sizeof( struct V_318 ) ,
F_60 ( V_244 ) ) ;
F_75 ( V_465 ) ;
break;
}
case V_408 :
case V_409 :
case V_408 | V_409 :
{
V_310 -> V_337 = V_466 ;
F_65 ( V_1 , V_241 , V_215 ) ;
break;
}
default:
V_310 -> V_337 = V_407 ;
break;
}
if ( ! V_215 -> V_16 -> V_468 ) {
F_34 ( V_54 , L_14 ,
V_215 -> V_16 -> V_469 . V_75 ) ;
V_310 -> V_337 = V_358 ;
}
V_449:
if ( V_19 && V_19 -> V_470 )
V_19 -> V_470 -- ;
F_76 ( V_1 , V_241 , V_215 ) ;
V_437 = V_310 -> V_337 ;
if ( V_241 -> V_471 )
V_241 -> V_471 ( V_241 ) ;
return V_437 ;
}
static T_6 F_77 ( T_6 V_282 , int V_472 )
{
switch ( V_282 ) {
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
case V_486 :
case V_487 :
return V_488 ;
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
return V_496 ;
case V_497 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
case V_502 :
case V_503 :
case V_504 :
case V_505 :
case V_506 :
return V_507 ;
default:
if ( V_472 == V_508 )
return V_507 ;
return V_488 ;
}
}
static int F_78 ( struct V_240 * V_241 , T_1 * V_509 )
{
struct V_510 * V_511 = V_241 -> V_512 ;
if ( V_511 ) {
if ( V_511 -> V_513 . V_514 == V_473 ||
V_511 -> V_513 . V_514 == V_474 ) {
* V_509 = V_511 -> V_509 ;
return 1 ;
}
}
return 0 ;
}
static int F_79 ( struct V_1 * V_1 ,
struct V_214 * V_215 )
{
struct V_240 * V_241 = V_215 -> V_241 ;
struct V_7 * V_8 = V_241 -> V_54 ;
struct V_7 * V_59 = V_8 -> V_60 ;
struct V_15 * V_19 = V_8 -> V_245 ;
struct V_216 * V_217 = V_215 -> V_242 ;
struct V_61 * V_16 = V_8 -> V_16 -> V_62 ;
T_6 * V_285 ;
int V_283 = 0 , V_184 = 0 , V_515 = 0 ;
T_1 V_261 = 0 , V_266 = 0 ;
V_217 -> V_257 = F_59 ( V_16 -> V_75 << V_258 ) ;
if ( V_59 && F_20 ( V_59 -> V_24 ) )
V_217 -> V_257 |= F_59 ( 3 << V_260 ) ;
else
V_217 -> V_257 |= F_59 ( 4 << V_260 ) ;
switch ( V_241 -> V_516 ) {
case V_252 :
V_283 = 1 ;
V_261 |= V_290 << V_265 ;
break;
case V_254 :
V_283 = 1 ;
V_261 |= V_291 << V_265 ;
break;
default:
V_261 &= ~ V_292 ;
}
if ( 0 == V_241 -> V_517 . V_518 . V_514 )
V_261 |= 1 << V_519 ;
V_261 |= ( F_77 ( V_241 -> V_517 . V_518 . V_514 , V_241 -> V_516 ) )
<< V_263 ;
V_261 |= V_19 -> V_26 << V_262 ;
V_217 -> V_261 = F_59 ( V_261 ) ;
if ( V_241 -> V_517 . V_520 && F_78 ( V_241 , & V_515 ) ) {
V_241 -> V_517 . V_518 . V_521 |= ( T_6 ) ( V_515 << 3 ) ;
V_266 |= V_515 << V_522 ;
}
V_266 |= ( V_523 / 4 ) << V_267 |
2 << V_296 ;
V_217 -> V_266 = F_59 ( V_266 ) ;
V_217 -> V_270 = F_59 ( V_215 -> V_271 ) ;
if ( V_283 ) {
V_184 = F_55 ( V_1 , V_215 , V_217 , V_241 -> V_219 ,
V_215 -> V_220 ) ;
if ( V_184 )
return V_184 ;
}
V_217 -> V_297 = F_59 ( V_241 -> V_298 ) ;
V_217 -> V_273 = F_22 ( V_215 -> V_299 ) ;
V_217 -> V_274 = F_22 ( V_215 -> V_275 ) ;
V_285 = V_215 -> V_300 ;
if ( F_80 ( ! V_241 -> V_517 . V_524 ) )
V_241 -> V_517 . V_518 . V_525 |= 0x80 ;
memcpy ( V_285 , & V_241 -> V_517 . V_518 , sizeof( struct V_526 ) ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 ,
struct V_214 * V_215 ,
int V_26 , int V_527 , int V_528 )
{
struct V_240 * V_241 = V_215 -> V_241 ;
struct V_7 * V_54 = V_241 -> V_54 ;
struct V_216 * V_217 = V_215 -> V_242 ;
struct V_61 * V_16 = V_215 -> V_16 ;
V_217 -> V_257 = F_59 ( ( 5 << V_260 ) |
( V_16 -> V_75 << V_258 ) |
( ( F_10 ( V_54 ) ? 1 : 0 ) <<
V_529 ) |
( V_527 << V_530 ) ) ;
V_217 -> V_261 = F_59 ( V_26 << V_262 ) ;
V_217 -> V_531 = F_59 ( V_528 << V_532 ) ;
V_217 -> V_270 = F_59 ( V_215 -> V_271 ) ;
return 0 ;
}
static int F_82 ( int V_5 , struct V_1 * V_1 )
{
int V_20 , V_533 = 0 ;
T_1 V_534 , V_192 , V_535 , V_536 ;
struct V_537 * V_538 = & V_1 -> V_538 [ V_5 ] ;
struct V_539 * V_540 = & V_538 -> V_540 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
T_1 * V_541 = ( T_1 * ) V_540 -> V_541 ;
struct V_34 * V_75 = (struct V_34 * ) V_541 ;
F_7 ( V_1 , V_5 , V_155 , 1 ) ;
V_534 = F_1 ( V_1 , V_542 ) ;
if ( V_534 & ( 1 << V_5 ) )
goto V_543;
if ( V_5 == 8 ) {
T_1 V_197 = F_1 ( V_1 , V_198 ) ;
V_192 = ( V_197 & V_199 ) >>
V_200 ;
V_535 = ( V_197 & V_544 ) >>
V_545 ;
} else {
V_192 = F_1 ( V_1 , V_194 ) ;
V_192 = ( V_192 >> ( 4 * V_5 ) ) & 0xf ;
V_535 = F_1 ( V_1 , V_546 ) ;
V_535 = ( V_535 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_192 == 0xf ) {
F_34 ( V_54 , L_15 , V_5 ) ;
V_533 = V_547 ;
goto V_543;
}
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
T_1 V_548 = F_8 ( V_1 , V_5 ,
V_549 + ( V_20 * 4 ) ) ;
V_541 [ V_20 ] = F_18 ( V_548 ) ;
}
V_540 -> V_72 = V_535 ;
V_536 = F_8 ( V_1 , V_5 ,
V_550 ) ;
V_538 -> V_551 = V_536 & 0xf ;
V_538 -> V_552 = ( V_536 >> 4 ) & 0xf ;
V_540 -> V_553 = V_554 ;
memcpy ( V_540 -> V_555 , & V_75 -> V_45 , V_46 ) ;
F_83 ( V_54 , L_16 , V_5 , V_535 ) ;
V_538 -> V_192 = V_192 ;
V_538 -> V_556 &= ~ ( V_557 | V_558 ) ;
V_538 -> V_556 |= V_557 ;
V_538 -> V_559 = 1 ;
V_538 -> V_560 . V_561 = V_75 -> V_24 ;
V_538 -> V_562 = sizeof( struct V_34 ) ;
if ( V_538 -> V_560 . V_561 == V_37 )
V_538 -> V_560 . V_563 =
V_335 ;
else if ( V_538 -> V_560 . V_561 != V_25 )
V_538 -> V_560 . V_563 =
V_406 ;
F_71 ( V_1 -> V_461 , & V_538 -> V_564 ) ;
V_543:
F_7 ( V_1 , V_5 , V_145 ,
V_565 ) ;
F_7 ( V_1 , V_5 , V_155 , 0 ) ;
return V_533 ;
}
static int F_84 ( int V_5 , struct V_1 * V_1 )
{
int V_533 = 0 ;
T_1 V_195 , V_566 , V_567 ;
F_7 ( V_1 , V_5 , V_153 , 1 ) ;
V_195 = F_1 ( V_1 , V_196 ) ;
F_85 ( V_1 , V_5 , ( V_195 & 1 << V_5 ) ? 1 : 0 ) ;
V_566 = F_8 ( V_1 , V_5 , V_142 ) ;
F_7 ( V_1 , V_5 , V_142 ,
V_566 & ~ V_568 ) ;
V_567 = F_8 ( V_1 , V_5 , V_143 ) ;
F_7 ( V_1 , V_5 , V_143 ,
V_567 | V_569 ) ;
F_7 ( V_1 , V_5 , V_145 , V_570 ) ;
F_7 ( V_1 , V_5 , V_153 , 0 ) ;
return V_533 ;
}
static T_8 F_86 ( int V_571 , void * V_572 )
{
struct V_1 * V_1 = V_572 ;
T_1 V_573 ;
int V_5 = 0 ;
T_8 V_533 = V_574 ;
V_573 = ( F_1 ( V_1 , V_575 )
>> V_576 ) & 0x1ff ;
while ( V_573 ) {
if ( V_573 & 1 ) {
T_1 V_577 = F_8 ( V_1 , V_5 ,
V_145 ) ;
if ( V_577 & V_565 )
if ( F_82 ( V_5 , V_1 ) ) {
V_533 = V_547 ;
goto V_543;
}
if ( V_577 & V_570 )
if ( F_84 ( V_5 , V_1 ) ) {
V_533 = V_547 ;
goto V_543;
}
}
V_573 >>= 1 ;
V_5 ++ ;
}
V_543:
return V_533 ;
}
static void F_87 ( int V_5 , struct V_1 * V_1 )
{
struct V_537 * V_538 = & V_1 -> V_538 [ V_5 ] ;
struct V_539 * V_540 = & V_538 -> V_540 ;
struct V_578 * V_579 = & V_1 -> V_580 ;
F_7 ( V_1 , V_5 , V_156 , 1 ) ;
V_579 -> V_581 ( V_540 , V_582 ) ;
F_7 ( V_1 , V_5 , V_145 ,
V_583 ) ;
F_7 ( V_1 , V_5 , V_156 , 0 ) ;
}
static T_8 F_88 ( int V_571 , void * V_572 )
{
struct V_1 * V_1 = V_572 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
T_1 V_584 , V_585 , V_573 ;
int V_5 = 0 ;
V_584 = F_1 ( V_1 , V_134 ) ;
V_585 = V_584 ;
V_584 |= V_586 ;
F_5 ( V_1 , V_134 , V_584 ) ;
V_573 = ( F_1 ( V_1 , V_575 ) >>
V_587 ) & 0x1ff ;
while ( V_573 ) {
if ( V_573 & ( 1 << V_5 ) ) {
T_1 V_588 = F_8 ( V_1 , V_5 ,
V_145 ) ;
T_1 V_589 = F_8 ( V_1 , V_5 ,
V_146 ) ;
T_1 V_590 = F_8 ( V_1 , V_5 ,
V_147 ) ;
if ( V_589 ) {
if ( V_589 & ( V_591 |
V_592 ) )
F_89 ( L_17 ,
F_90 ( V_54 ) , V_589 ) ;
F_7 ( V_1 , V_5 ,
V_146 , V_589 ) ;
}
if ( V_590 )
F_7 ( V_1 , V_5 ,
V_147 , V_590 ) ;
if ( V_588 ) {
if ( V_588 & V_583 )
F_87 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_145 , V_588
& ( ~ V_593 )
& ( ~ V_565 )
& ( ~ V_570 ) ) ;
}
}
V_573 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_134 , V_585 ) ;
return V_574 ;
}
static T_8 F_91 ( int V_571 , void * V_572 )
{
struct V_594 * V_595 = V_572 ;
struct V_1 * V_1 = V_595 -> V_1 ;
struct V_214 * V_215 ;
struct V_57 * V_58 ;
struct V_438 * V_439 ;
T_1 V_577 , V_596 = V_595 -> V_596 , V_207 , V_82 ;
int V_206 = V_595 -> V_75 ;
V_439 = V_1 -> V_440 [ V_206 ] ;
V_577 = F_1 ( V_1 , V_129 ) ;
F_5 ( V_1 , V_129 , 1 << V_206 ) ;
V_207 = F_1 ( V_1 , V_597 +
( 0x14 * V_206 ) ) ;
while ( V_596 != V_207 ) {
struct V_438 * V_440 ;
int V_598 ;
V_440 = & V_439 [ V_596 ] ;
if ( V_440 -> V_599 ) {
T_1 V_600 = V_440 -> V_599 ;
int V_601 = F_68 ( V_600 ) ;
V_82 = ( V_440 -> V_261 & V_602 ) >>
V_603 ;
V_58 = & V_1 -> V_58 [ V_82 ] ;
while ( V_601 ) {
T_9 * V_604 = & V_58 -> V_605 [ 0 ] ;
V_601 -= 1 ;
V_598 = ( V_604 [ V_601 / 5 ]
>> ( V_601 % 5 ) * 12 ) & 0xfff ;
V_215 = & V_1 -> V_606 [ V_598 ] ;
V_215 -> V_442 = V_596 ;
V_215 -> V_441 = V_206 ;
F_69 ( V_1 , V_215 , 0 ) ;
V_600 &= ~ ( 1 << V_601 ) ;
V_601 = F_68 ( V_600 ) ;
}
} else {
V_598 = ( V_440 -> V_261 ) & V_607 ;
V_215 = & V_1 -> V_606 [ V_598 ] ;
V_215 -> V_442 = V_596 ;
V_215 -> V_441 = V_206 ;
F_69 ( V_1 , V_215 , 0 ) ;
}
if ( ++ V_596 >= V_164 )
V_596 = 0 ;
}
V_595 -> V_596 = V_596 ;
F_5 ( V_1 , V_608 + ( 0x14 * V_206 ) , V_596 ) ;
return V_574 ;
}
static T_8 F_92 ( int V_571 , void * V_572 )
{
struct V_537 * V_538 = V_572 ;
struct V_1 * V_1 = V_538 -> V_1 ;
struct V_539 * V_540 = & V_538 -> V_540 ;
struct V_8 * V_54 = & V_1 -> V_55 -> V_54 ;
struct V_609 * V_610 ;
struct V_315 * V_518 ;
T_1 V_585 , V_584 , V_611 , V_192 , V_535 , V_536 ;
T_8 V_533 = V_574 ;
T_6 V_555 [ V_46 ] = { 0 } ;
int V_5 , V_467 ;
V_5 = V_540 -> V_75 ;
V_610 = & V_1 -> V_610 [ V_5 ] ;
V_518 = & V_610 -> V_518 ;
V_467 = 4 * ( V_5 / 4 ) ;
V_584 = F_1 ( V_1 , V_132 + V_467 ) ;
F_5 ( V_1 , V_132 + V_467 ,
V_584 | 1 << ( ( V_5 % 4 ) * 8 ) ) ;
V_611 = F_1 ( V_1 , V_130 + V_467 ) ;
V_585 = V_611 & ( 1 << ( V_612 *
( V_5 % 4 ) ) ) ;
V_611 >>= V_612 * ( V_5 % 4 ) ;
if ( ( V_611 & V_613 ) == 0 ) {
F_21 ( V_54 , L_18 , V_5 ) ;
V_533 = V_547 ;
goto V_543;
}
if ( F_70 ( V_5 == 8 ) ) {
T_1 V_197 = F_1 ( V_1 , V_198 ) ;
V_192 = ( V_197 & V_199 ) >>
V_200 ;
V_535 = ( V_197 & V_544 ) >>
V_545 ;
} else {
V_192 = F_1 ( V_1 , V_194 ) ;
V_192 = ( V_192 >> ( 4 * V_5 ) ) & 0xf ;
V_535 = F_1 ( V_1 , V_546 ) ;
V_535 = ( V_535 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_192 == 0xf ) {
F_34 ( V_54 , L_19 , V_5 ) ;
V_533 = V_547 ;
goto V_543;
}
V_540 -> V_72 = V_535 ;
V_536 = F_8 ( V_1 , V_5 ,
V_550 ) ;
V_538 -> V_551 = V_536 & 0xf ;
V_538 -> V_552 = ( V_536 >> 4 ) & 0xf ;
V_540 -> V_553 = V_614 ;
V_555 [ 0 ] = 0x50 ;
V_555 [ 7 ] = V_5 ;
memcpy ( V_540 -> V_555 , V_555 , V_46 ) ;
memcpy ( V_540 -> V_541 , V_518 , sizeof( struct V_315 ) ) ;
F_83 ( V_54 , L_20 , V_5 , V_535 ) ;
V_538 -> V_556 &= ~ ( V_557 | V_558 ) ;
V_538 -> V_192 = V_192 ;
V_538 -> V_556 |= V_558 ;
V_538 -> V_559 = 1 ;
V_538 -> V_560 . V_561 = V_67 ;
V_538 -> V_562 = sizeof( struct V_315 ) ;
V_538 -> V_560 . V_563 = V_408 ;
F_71 ( V_1 -> V_461 , & V_538 -> V_564 ) ;
V_543:
F_5 ( V_1 , V_130 + V_467 , V_585 ) ;
F_5 ( V_1 , V_132 + V_467 , V_584 ) ;
return V_533 ;
}
static int F_93 ( struct V_1 * V_1 )
{
struct V_615 * V_55 = V_1 -> V_55 ;
struct V_8 * V_54 = & V_55 -> V_54 ;
int V_20 , V_616 , V_184 , V_617 [ 128 ] ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ )
V_617 [ V_20 ] = F_94 ( V_55 , V_20 ) ;
for ( V_20 = 0 ; V_20 < V_618 ; V_20 ++ ) {
int V_271 = V_20 ;
V_616 = V_617 [ V_271 + 1 ] ;
if ( ! V_616 ) {
F_34 ( V_54 , L_21 ,
V_271 ) ;
return - V_619 ;
}
V_184 = F_95 ( V_54 , V_616 , V_620 [ V_20 ] , 0 ,
V_621 L_22 , V_1 ) ;
if ( V_184 ) {
F_34 ( V_54 , L_23
L_24 ,
V_616 , V_184 ) ;
return - V_619 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_91 ; V_20 ++ ) {
struct V_537 * V_538 = & V_1 -> V_538 [ V_20 ] ;
int V_271 = V_20 + 72 ;
V_616 = V_617 [ V_271 ] ;
if ( ! V_616 ) {
F_34 ( V_54 , L_21 ,
V_271 ) ;
return - V_619 ;
}
V_184 = F_95 ( V_54 , V_616 , F_92 , 0 ,
V_621 L_25 , V_538 ) ;
if ( V_184 ) {
F_34 ( V_54 , L_23
L_26 ,
V_616 , V_184 ) ;
return - V_619 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_112 ; V_20 ++ ) {
int V_271 = V_20 + 96 ;
V_616 = V_617 [ V_271 ] ;
if ( ! V_616 ) {
F_34 ( V_54 ,
L_27 ,
V_271 ) ;
return - V_619 ;
}
V_184 = F_95 ( V_54 , V_616 , F_91 , 0 ,
V_621 L_28 , & V_1 -> V_595 [ V_20 ] ) ;
if ( V_184 ) {
F_34 ( V_54 ,
L_29 ,
V_616 , V_184 ) ;
return - V_619 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_1 )
{
int V_184 ;
V_184 = F_41 ( V_1 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_93 ( V_1 ) ;
if ( V_184 )
return V_184 ;
F_48 ( V_1 ) ;
return 0 ;
}
static int F_97 ( struct V_615 * V_55 )
{
return F_98 ( V_55 , & V_622 ) ;
}
static int F_99 ( struct V_615 * V_55 )
{
return F_100 ( V_55 ) ;
}
