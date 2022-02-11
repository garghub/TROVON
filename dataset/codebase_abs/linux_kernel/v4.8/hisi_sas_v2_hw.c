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
if ( F_32 ( V_55 ) ) {
T_4 V_105 ;
V_105 = F_33 ( F_32 ( V_55 ) , L_4 , NULL , NULL ) ;
if ( F_34 ( V_105 ) ) {
F_35 ( V_55 , L_5 ) ;
return - V_102 ;
}
} else if ( V_1 -> V_106 ) {
F_36 ( V_1 -> V_106 , V_1 -> V_107 ,
V_89 ) ;
F_36 ( V_1 -> V_106 , V_1 -> V_108 + 4 ,
V_89 ) ;
F_30 ( 1 ) ;
F_37 ( V_1 -> V_106 , V_1 -> V_109 , & V_4 ) ;
if ( V_89 != ( V_4 & V_89 ) ) {
F_35 ( V_55 , L_6 ) ;
return - V_102 ;
}
F_36 ( V_1 -> V_106 , V_1 -> V_107 + 4 ,
V_89 ) ;
F_36 ( V_1 -> V_106 , V_1 -> V_108 ,
V_89 ) ;
F_30 ( 1 ) ;
F_37 ( V_1 -> V_106 , V_1 -> V_109 ,
& V_4 ) ;
if ( V_4 & V_89 ) {
F_35 ( V_55 , L_7 ) ;
return - V_102 ;
}
} else
F_22 ( V_55 , L_8 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
int V_20 ;
if ( F_39 ( V_55 , L_9 ) ) {
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
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
F_7 ( V_1 , V_20 , V_139 , 0x855 ) ;
F_7 ( V_1 , V_20 , V_140 , 0x30b9908 ) ;
F_7 ( V_1 , V_20 , V_141 , 0x7d7d7d7d ) ;
F_7 ( V_1 , V_20 , V_142 , 0x10 ) ;
F_7 ( V_1 , V_20 , V_143 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_144 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_145 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_146 , 0x1000 ) ;
F_7 ( V_1 , V_20 , V_147 , 0xffffffff ) ;
F_7 ( V_1 , V_20 , V_148 , 0x8ffffbff ) ;
F_7 ( V_1 , V_20 , V_149 , 0x23f801fc ) ;
F_7 ( V_1 , V_20 , V_150 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_151 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_152 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_153 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_154 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_155 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_156 , 0x0 ) ;
F_7 ( V_1 , V_20 , V_157 , 0x199B694 ) ;
}
for ( V_20 = 0 ; V_20 < V_1 -> V_112 ; V_20 ++ ) {
F_5 ( V_1 ,
V_158 + ( V_20 * 0x14 ) ,
F_40 ( V_1 -> V_159 [ V_20 ] ) ) ;
F_5 ( V_1 , V_160 + ( V_20 * 0x14 ) ,
F_41 ( V_1 -> V_159 [ V_20 ] ) ) ;
F_5 ( V_1 , V_161 + ( V_20 * 0x14 ) ,
V_162 ) ;
F_5 ( V_1 , V_163 + ( V_20 * 0x14 ) ,
F_40 ( V_1 -> V_164 [ V_20 ] ) ) ;
F_5 ( V_1 , V_165 + ( V_20 * 0x14 ) ,
F_41 ( V_1 -> V_164 [ V_20 ] ) ) ;
F_5 ( V_1 , V_166 + ( V_20 * 0x14 ) ,
V_162 ) ;
}
F_5 ( V_1 , V_167 ,
F_41 ( V_1 -> V_168 ) ) ;
F_5 ( V_1 , V_169 ,
F_40 ( V_1 -> V_168 ) ) ;
F_5 ( V_1 , V_170 ,
F_41 ( V_1 -> V_171 ) ) ;
F_5 ( V_1 , V_172 ,
F_40 ( V_1 -> V_171 ) ) ;
F_5 ( V_1 , V_173 ,
F_41 ( V_1 -> V_174 ) ) ;
F_5 ( V_1 , V_175 ,
F_40 ( V_1 -> V_174 ) ) ;
F_5 ( V_1 , V_176 ,
F_41 ( V_1 -> V_177 ) ) ;
F_5 ( V_1 , V_178 ,
F_40 ( V_1 -> V_177 ) ) ;
F_5 ( V_1 , V_179 ,
F_41 ( V_1 -> V_180 ) ) ;
F_5 ( V_1 , V_181 ,
F_40 ( V_1 -> V_180 ) ) ;
}
static int F_42 ( struct V_1 * V_1 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
int V_182 ;
V_182 = F_28 ( V_1 ) ;
if ( V_182 ) {
F_35 ( V_55 , L_10 , V_182 ) ;
return V_182 ;
}
F_30 ( 100 ) ;
F_38 ( V_1 ) ;
F_19 ( V_1 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 |= V_183 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_44 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_30 = F_8 ( V_1 , V_5 , V_31 ) ;
V_30 &= ~ V_183 ;
F_7 ( V_1 , V_5 , V_31 , V_30 ) ;
}
static void F_45 ( struct V_1 * V_1 , int V_5 )
{
F_17 ( V_1 , V_5 ) ;
F_16 ( V_1 , V_5 ) ;
F_43 ( V_1 , V_5 ) ;
}
static void F_46 ( struct V_1 * V_1 , int V_5 )
{
F_44 ( V_1 , V_5 ) ;
}
static void F_47 ( struct V_1 * V_1 , int V_5 )
{
F_46 ( V_1 , V_5 ) ;
F_30 ( 100 ) ;
F_45 ( V_1 , V_5 ) ;
}
static void F_48 ( unsigned long V_184 )
{
struct V_1 * V_1 = (struct V_1 * ) V_184 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ )
F_45 ( V_1 , V_20 ) ;
}
static void F_49 ( struct V_1 * V_1 )
{
int V_20 ;
struct V_185 * V_186 = & V_1 -> V_186 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
F_7 ( V_1 , V_20 , V_148 , 0x6a ) ;
F_8 ( V_1 , V_20 , V_148 ) ;
}
F_50 ( V_186 , F_48 , ( unsigned long ) V_1 ) ;
F_51 ( V_186 , V_97 + V_187 ) ;
}
static void F_52 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_188 ;
V_188 = F_8 ( V_1 , V_5 , V_189 ) ;
V_188 |= V_190 ;
F_7 ( V_1 , V_5 , V_189 , V_188 ) ;
F_30 ( 1 ) ;
V_188 = F_8 ( V_1 , V_5 , V_189 ) ;
V_188 &= ~ V_190 ;
F_7 ( V_1 , V_5 , V_189 , V_188 ) ;
}
static int F_53 ( struct V_1 * V_1 , int V_191 )
{
int V_20 , V_10 = 0 ;
T_1 V_192 = F_1 ( V_1 , V_193 ) ;
T_1 V_194 = F_1 ( V_1 , V_195 ) ;
for ( V_20 = 0 ; V_20 < ( V_1 -> V_54 < 9 ? V_1 -> V_54 : 8 ) ; V_20 ++ )
if ( V_194 & 1 << V_20 )
if ( ( ( V_192 >> ( V_20 * 4 ) ) & 0xf ) == V_191 )
V_10 |= 1 << V_20 ;
if ( V_1 -> V_54 == 9 ) {
T_1 V_196 = F_1 ( V_1 , V_197 ) ;
if ( V_194 & 1 << 8 )
if ( ( ( V_196 & V_198 ) >>
V_199 ) == V_191 )
V_10 |= 1 << 9 ;
}
return V_10 ;
}
static int F_54 ( struct V_1 * V_1 , int * V_200 , int * V_105 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 V_201 , V_202 ;
int V_203 = V_1 -> V_203 ;
while ( 1 ) {
V_202 = F_3 ( V_1 ,
V_204 + ( V_203 * 0x14 ) ) ;
V_201 = F_3 ( V_1 ,
V_205 + ( V_203 * 0x14 ) ) ;
if ( V_201 == ( V_202 + 1 ) % V_162 ) {
V_203 = ( V_203 + 1 ) % V_1 -> V_112 ;
if ( V_203 == V_1 -> V_203 ) {
F_22 ( V_55 , L_11 ) ;
return - V_206 ;
}
continue;
}
break;
}
V_1 -> V_203 = ( V_203 + 1 ) % V_1 -> V_112 ;
* V_200 = V_203 ;
* V_105 = V_202 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_1 )
{
int V_207 = V_1 -> V_208 -> V_207 ;
int V_209 = V_1 -> V_208 -> V_209 ;
F_5 ( V_1 , V_204 + ( V_207 * 0x14 ) ,
++ V_209 % V_162 ) ;
}
static int F_56 ( struct V_1 * V_1 ,
struct V_210 * V_211 ,
struct V_212 * V_213 ,
struct V_214 * V_215 ,
int V_216 )
{
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_214 * V_217 ;
int V_20 ;
if ( V_216 > V_218 ) {
F_35 ( V_55 , L_12 ,
V_216 ) ;
return - V_219 ;
}
V_211 -> V_220 = F_57 ( V_1 -> V_221 , V_222 ,
& V_211 -> V_223 ) ;
if ( ! V_211 -> V_220 )
return - V_224 ;
F_58 (scatter, sg, n_elem, i) {
struct V_225 * V_226 = & V_211 -> V_220 -> V_227 [ V_20 ] ;
V_226 -> V_228 = F_23 ( F_59 ( V_217 ) ) ;
V_226 -> V_229 = V_226 -> V_230 = 0 ;
V_226 -> V_231 = F_60 ( F_61 ( V_217 ) ) ;
V_226 -> V_232 = 0 ;
}
V_213 -> V_233 = F_23 ( V_211 -> V_223 ) ;
V_213 -> V_234 = F_60 ( V_216 << V_235 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
struct V_236 * V_237 = V_211 -> V_237 ;
struct V_212 * V_213 = V_211 -> V_238 ;
struct V_7 * V_8 = V_237 -> V_55 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_62 * V_16 = V_211 -> V_16 ;
struct V_214 * V_239 , * V_240 ;
struct V_15 * V_19 = V_8 -> V_241 ;
T_5 V_242 ;
unsigned int V_243 , V_244 ;
int V_245 , V_182 ;
V_239 = & V_237 -> V_246 . V_247 ;
V_245 = F_63 ( V_55 , V_239 , 1 , V_248 ) ;
if ( ! V_245 )
return - V_224 ;
V_243 = F_61 ( V_239 ) ;
V_242 = F_59 ( V_239 ) ;
V_240 = & V_237 -> V_246 . V_249 ;
V_245 = F_63 ( V_55 , V_240 , 1 , V_250 ) ;
if ( ! V_245 ) {
V_182 = - V_224 ;
goto V_251;
}
V_244 = F_61 ( V_240 ) ;
if ( ( V_243 & 0x3 ) || ( V_244 & 0x3 ) ) {
V_182 = - V_219 ;
goto V_252;
}
V_213 -> V_253 = F_60 ( ( V_16 -> V_75 << V_254 ) |
( 1 << V_255 ) |
( 2 << V_256 ) ) ;
V_213 -> V_257 = F_60 ( ( V_19 -> V_26 << V_258 ) |
( 1 << V_259 ) |
( V_260 << V_261 ) ) ;
V_213 -> V_262 = F_60 ( ( ( ( V_243 - 4 ) / 4 ) << V_263 ) |
( V_264 / 4 <<
V_265 ) ) ;
V_213 -> V_266 = F_60 ( V_211 -> V_267 << V_268 ) ;
V_213 -> V_269 = F_23 ( V_242 ) ;
V_213 -> V_270 = F_23 ( V_211 -> V_271 ) ;
return 0 ;
V_252:
F_64 ( V_55 , & V_211 -> V_237 -> V_246 . V_249 , 1 ,
V_250 ) ;
V_251:
F_64 ( V_55 , & V_211 -> V_237 -> V_246 . V_247 , 1 ,
V_248 ) ;
return V_182 ;
}
static int F_65 ( struct V_1 * V_1 ,
struct V_210 * V_211 , int V_272 ,
struct V_273 * V_274 )
{
struct V_236 * V_237 = V_211 -> V_237 ;
struct V_212 * V_213 = V_211 -> V_238 ;
struct V_7 * V_8 = V_237 -> V_55 ;
struct V_15 * V_19 = V_8 -> V_241 ;
struct V_62 * V_16 = V_211 -> V_16 ;
struct V_275 * V_276 = & V_237 -> V_276 ;
struct V_277 * V_277 = V_276 -> V_278 ;
int V_279 = 0 , V_182 , V_280 = V_272 ;
T_6 * V_281 ;
T_1 V_257 = 0 , V_262 = 0 ;
V_213 -> V_253 = F_60 ( ( 1 << V_282 ) |
( 2 << V_283 ) |
( V_16 -> V_75 << V_254 ) |
( V_280 << V_255 ) |
( 1 << V_256 ) ) ;
V_257 = 1 << V_284 ;
if ( V_272 ) {
V_257 |= 2 << V_259 ;
V_257 |= V_260 << V_261 ;
} else {
V_257 |= 1 << V_259 ;
switch ( V_277 -> V_285 ) {
case V_248 :
V_279 = 1 ;
V_257 |= V_286 << V_261 ;
break;
case V_250 :
V_279 = 1 ;
V_257 |= V_287 << V_261 ;
break;
default:
V_257 &= ~ V_288 ;
}
}
V_257 |= V_19 -> V_26 << V_258 ;
V_213 -> V_257 = F_60 ( V_257 ) ;
V_262 = ( ( ( sizeof( struct V_289 ) + sizeof( struct V_290 )
+ 3 ) / 4 ) << V_263 ) |
( ( V_291 / 4 ) << V_265 ) |
( 2 << V_292 ) ;
V_213 -> V_262 = F_60 ( V_262 ) ;
V_213 -> V_266 = F_60 ( V_211 -> V_267 ) ;
if ( V_279 ) {
V_182 = F_56 ( V_1 , V_211 , V_213 , V_237 -> V_215 ,
V_211 -> V_216 ) ;
if ( V_182 )
return V_182 ;
}
V_213 -> V_293 = F_60 ( V_237 -> V_294 ) ;
V_213 -> V_269 = F_23 ( V_211 -> V_295 ) ;
V_213 -> V_270 = F_23 ( V_211 -> V_271 ) ;
V_281 = V_211 -> V_296 + sizeof( struct V_290 ) ;
memcpy ( V_281 , & V_237 -> V_276 . V_297 , 8 ) ;
if ( ! V_272 ) {
V_281 [ 9 ] = V_237 -> V_276 . V_298 |
( V_237 -> V_276 . V_299 << 3 ) ;
memcpy ( V_281 + 12 , V_237 -> V_276 . V_278 -> V_300 ,
V_237 -> V_276 . V_278 -> V_301 ) ;
} else {
V_281 [ 10 ] = V_274 -> V_274 ;
switch ( V_274 -> V_274 ) {
case V_302 :
case V_303 :
V_281 [ 12 ] =
( V_274 -> V_304 >> 8 ) & 0xff ;
V_281 [ 13 ] =
V_274 -> V_304 & 0xff ;
break;
default:
break;
}
}
return 0 ;
}
static void F_66 ( struct V_1 * V_1 , struct V_236 * V_237 ,
struct V_210 * V_211 )
{
struct V_305 * V_306 = & V_237 -> V_307 ;
struct V_308 * V_309 = (struct V_308 * ) V_306 -> V_310 ;
struct V_311 * V_312 = V_211 -> V_313 +
sizeof( struct V_314 ) ;
V_309 -> V_315 = sizeof( struct V_311 ) ;
memcpy ( & V_309 -> V_316 [ 0 ] , V_312 , sizeof( struct V_311 ) ) ;
V_306 -> V_317 = sizeof( * V_309 ) ;
}
static void F_67 ( struct V_1 * V_1 ,
struct V_236 * V_237 ,
struct V_210 * V_211 )
{
struct V_305 * V_306 = & V_237 -> V_307 ;
struct V_318 * V_319 = V_211 -> V_313 ;
T_1 V_320 = F_60 ( V_319 -> V_320 ) ;
T_1 V_321 = F_60 ( V_319 -> V_321 ) ;
T_7 V_322 = F_68 ( V_319 -> V_322 ) ;
T_7 V_323 = F_68 ( V_319 -> V_323 ) ;
T_1 V_324 = F_60 ( V_319 -> V_324 ) ;
int error = - 1 ;
if ( V_324 ) {
error = F_69 ( V_324 )
- 1 + V_325 ;
} else if ( V_323 ) {
error = F_69 ( V_323 )
- 1 + V_326 ;
} else if ( V_322 ) {
error = F_69 ( V_322 )
- 1 + V_327 ;
} else if ( V_321 ) {
error = F_69 ( V_321 )
- 1 + V_328 ;
} else if ( V_320 ) {
error = F_69 ( V_320 )
- 1 + V_329 ;
}
switch ( V_237 -> V_330 ) {
case V_331 :
{
switch ( error ) {
case V_332 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_336 ;
break;
}
case V_337 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_338 ;
break;
}
case V_339 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_340 ;
break;
}
case V_341 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_342 ;
break;
}
case V_343 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_344 ;
break;
}
case V_345 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_346 ;
break;
}
case V_347 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_348 ;
break;
}
case V_349 :
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_350 ;
break;
}
case V_351 :
{
V_306 -> V_333 = V_352 ;
break;
}
case V_353 :
{
V_306 -> V_333 = V_354 ;
break;
}
case V_355 :
{
V_306 -> V_333 = V_356 ;
break;
}
case V_357 :
{
V_306 -> V_333 = V_358 ;
V_306 -> V_359 = 0 ;
break;
}
case V_360 :
case V_361 :
{
V_306 -> V_359 = V_320 ;
V_306 -> V_333 = V_362 ;
break;
}
case V_363 :
{
V_306 -> V_333 = V_14 ;
V_211 -> abort = 1 ;
break;
}
case V_364 :
case V_365 :
case V_366 :
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
{
V_306 -> V_333 = V_334 ;
V_306 -> V_335 = V_350 ;
break;
}
default:
break;
}
}
break;
case V_402 :
V_306 -> V_333 = V_403 ;
break;
case V_404 :
case V_405 :
case V_404 | V_405 :
{
switch ( error ) {
case V_351 :
case V_337 :
case V_332 :
{
V_306 -> V_309 = V_406 ;
V_306 -> V_333 = V_352 ;
break;
}
case V_339 :
case V_341 :
case V_343 :
case V_345 :
case V_347 :
case V_349 :
case V_407 :
{
V_306 -> V_333 = V_334 ;
break;
}
case V_355 :
{
V_306 -> V_333 = V_356 ;
break;
}
case V_357 :
{
V_306 -> V_333 = V_358 ;
break;
}
case V_364 :
case V_365 :
case V_366 :
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
case V_379 :
case V_408 :
case V_381 :
case V_382 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_386 :
case V_353 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_400 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_401 :
{
V_306 -> V_333 = V_334 ;
break;
}
default:
{
V_306 -> V_333 = V_431 ;
break;
}
}
F_66 ( V_1 , V_237 , V_211 ) ;
}
break;
default:
break;
}
}
static int
F_70 ( struct V_1 * V_1 , struct V_210 * V_211 ,
int abort )
{
struct V_236 * V_237 = V_211 -> V_237 ;
struct V_15 * V_19 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_305 * V_306 ;
struct V_7 * V_8 ;
enum V_432 V_433 ;
struct V_434 * V_435 =
V_1 -> V_436 [ V_211 -> V_437 ] ;
struct V_434 * V_436 =
& V_435 [ V_211 -> V_438 ] ;
if ( F_71 ( ! V_237 || ! V_237 -> V_439 || ! V_237 -> V_55 ) )
return - V_219 ;
V_306 = & V_237 -> V_307 ;
V_8 = V_237 -> V_55 ;
V_19 = V_8 -> V_241 ;
V_237 -> V_440 &=
~ ( V_441 | V_442 ) ;
V_237 -> V_440 |= V_443 ;
memset ( V_306 , 0 , sizeof( * V_306 ) ) ;
V_306 -> V_309 = V_444 ;
if ( F_71 ( ! V_19 || abort ) ) {
if ( ! V_19 )
F_27 ( V_55 , L_13 ) ;
V_306 -> V_333 = V_354 ;
goto V_445;
}
if ( ( V_436 -> V_253 & V_446 ) &&
( ! ( V_436 -> V_253 & V_447 ) ) ) {
F_67 ( V_1 , V_237 , V_211 ) ;
if ( F_71 ( V_211 -> abort ) ) {
F_72 ( V_1 -> V_448 , & V_211 -> V_449 ) ;
return V_306 -> V_333 ;
}
goto V_445;
}
switch ( V_237 -> V_330 ) {
case V_331 :
{
struct V_450 * V_451 = V_211 -> V_313 +
sizeof( struct V_314 ) ;
F_73 ( V_55 , V_237 , V_451 ) ;
break;
}
case V_402 :
{
struct V_214 * V_240 = & V_237 -> V_246 . V_249 ;
void * V_452 ;
V_306 -> V_333 = V_453 ;
V_452 = F_74 ( F_75 ( V_240 ) ) ;
F_64 ( V_55 , & V_237 -> V_246 . V_249 , 1 ,
V_250 ) ;
F_64 ( V_55 , & V_237 -> V_246 . V_247 , 1 ,
V_248 ) ;
memcpy ( V_452 + V_240 -> V_454 ,
V_211 -> V_313 +
sizeof( struct V_314 ) ,
F_61 ( V_240 ) ) ;
F_76 ( V_452 ) ;
break;
}
case V_404 :
case V_405 :
case V_404 | V_405 :
{
V_306 -> V_333 = V_453 ;
F_66 ( V_1 , V_237 , V_211 ) ;
break;
}
default:
V_306 -> V_333 = V_403 ;
break;
}
if ( ! V_211 -> V_16 -> V_455 ) {
F_35 ( V_55 , L_14 ,
V_211 -> V_16 -> V_456 . V_75 ) ;
V_306 -> V_333 = V_354 ;
}
V_445:
if ( V_19 && V_19 -> V_457 )
V_19 -> V_457 -- ;
F_77 ( V_1 , V_237 , V_211 ) ;
V_433 = V_306 -> V_333 ;
if ( V_237 -> V_458 )
V_237 -> V_458 ( V_237 ) ;
return V_433 ;
}
static T_6 F_78 ( T_6 V_278 , int V_459 )
{
switch ( V_278 ) {
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
return V_465 ;
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
return V_475 ;
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
return V_483 ;
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
return V_494 ;
default:
if ( V_459 == V_495 )
return V_494 ;
return V_475 ;
}
}
static int F_79 ( struct V_236 * V_237 , T_1 * V_496 )
{
struct V_497 * V_498 = V_237 -> V_499 ;
if ( V_498 ) {
if ( V_498 -> V_500 . V_501 == V_460 ||
V_498 -> V_500 . V_501 == V_461 ) {
* V_496 = V_498 -> V_496 ;
return 1 ;
}
}
return 0 ;
}
static int F_80 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
struct V_236 * V_237 = V_211 -> V_237 ;
struct V_7 * V_8 = V_237 -> V_55 ;
struct V_7 * V_60 = V_8 -> V_61 ;
struct V_15 * V_19 = V_8 -> V_241 ;
struct V_212 * V_213 = V_211 -> V_238 ;
struct V_62 * V_16 = V_8 -> V_16 -> V_63 ;
T_6 * V_281 ;
int V_279 = 0 , V_182 = 0 , V_502 = 0 ;
T_1 V_257 = 0 , V_262 = 0 ;
V_213 -> V_253 = F_60 ( V_16 -> V_75 << V_254 ) ;
if ( V_60 && F_21 ( V_60 -> V_24 ) )
V_213 -> V_253 |= F_60 ( 3 << V_256 ) ;
else
V_213 -> V_253 |= F_60 ( 4 << V_256 ) ;
switch ( V_237 -> V_503 ) {
case V_248 :
V_279 = 1 ;
V_257 |= V_286 << V_261 ;
break;
case V_250 :
V_279 = 1 ;
V_257 |= V_287 << V_261 ;
break;
default:
V_257 &= ~ V_288 ;
}
if ( 0 == V_237 -> V_504 . V_505 . V_501 )
V_257 |= 1 << V_506 ;
V_257 |= ( F_78 ( V_237 -> V_504 . V_505 . V_501 , V_237 -> V_503 ) )
<< V_259 ;
V_257 |= V_19 -> V_26 << V_258 ;
V_213 -> V_257 = F_60 ( V_257 ) ;
if ( V_237 -> V_504 . V_507 && F_79 ( V_237 , & V_502 ) ) {
V_237 -> V_504 . V_505 . V_508 |= ( T_6 ) ( V_502 << 3 ) ;
V_262 |= V_502 << V_509 ;
}
V_262 |= ( V_510 / 4 ) << V_263 |
2 << V_292 ;
V_213 -> V_262 = F_60 ( V_262 ) ;
V_213 -> V_266 = F_60 ( V_211 -> V_267 ) ;
if ( V_279 ) {
V_182 = F_56 ( V_1 , V_211 , V_213 , V_237 -> V_215 ,
V_211 -> V_216 ) ;
if ( V_182 )
return V_182 ;
}
V_213 -> V_293 = F_60 ( V_237 -> V_294 ) ;
V_213 -> V_269 = F_23 ( V_211 -> V_295 ) ;
V_213 -> V_270 = F_23 ( V_211 -> V_271 ) ;
V_281 = V_211 -> V_296 ;
if ( F_81 ( ! V_237 -> V_504 . V_511 ) )
V_237 -> V_504 . V_505 . V_512 |= 0x80 ;
memcpy ( V_281 , & V_237 -> V_504 . V_505 , sizeof( struct V_513 ) ) ;
return 0 ;
}
static int F_82 ( int V_5 , struct V_1 * V_1 )
{
int V_20 , V_514 = 0 ;
T_1 V_515 , V_191 , V_516 , V_517 ;
struct V_518 * V_519 = & V_1 -> V_519 [ V_5 ] ;
struct V_520 * V_521 = & V_519 -> V_521 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 * V_522 = ( T_1 * ) V_521 -> V_522 ;
struct V_34 * V_75 = (struct V_34 * ) V_522 ;
F_7 ( V_1 , V_5 , V_153 , 1 ) ;
V_515 = F_1 ( V_1 , V_523 ) ;
if ( V_515 & ( 1 << V_5 ) )
goto V_524;
if ( V_5 == 8 ) {
T_1 V_196 = F_1 ( V_1 , V_197 ) ;
V_191 = ( V_196 & V_198 ) >>
V_199 ;
V_516 = ( V_196 & V_525 ) >>
V_526 ;
} else {
V_191 = F_1 ( V_1 , V_193 ) ;
V_191 = ( V_191 >> ( 4 * V_5 ) ) & 0xf ;
V_516 = F_1 ( V_1 , V_527 ) ;
V_516 = ( V_516 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_191 == 0xf ) {
F_35 ( V_55 , L_15 , V_5 ) ;
V_514 = V_528 ;
goto V_524;
}
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
T_1 V_529 = F_8 ( V_1 , V_5 ,
V_530 + ( V_20 * 4 ) ) ;
V_522 [ V_20 ] = F_18 ( V_529 ) ;
}
V_516 = F_1 ( V_1 , V_527 ) ;
V_516 = ( V_516 >> ( V_5 * 4 ) ) & 0xf ;
V_521 -> V_72 = V_516 ;
V_517 = F_8 ( V_1 , V_5 ,
V_531 ) ;
V_519 -> V_532 = V_517 & 0xf ;
V_519 -> V_533 = ( V_517 >> 4 ) & 0xf ;
V_521 -> V_534 = V_535 ;
memcpy ( V_521 -> V_536 , & V_75 -> V_45 , V_46 ) ;
F_83 ( V_55 , L_16 , V_5 , V_516 ) ;
V_519 -> V_191 = V_191 ;
V_519 -> V_537 &= ~ ( V_538 | V_539 ) ;
V_519 -> V_537 |= V_538 ;
V_519 -> V_540 = 1 ;
V_519 -> V_541 . V_542 = V_75 -> V_24 ;
V_519 -> V_543 = sizeof( struct V_34 ) ;
if ( V_519 -> V_541 . V_542 == V_37 )
V_519 -> V_541 . V_544 =
V_331 ;
else if ( V_519 -> V_541 . V_542 != V_25 )
V_519 -> V_541 . V_544 =
V_402 ;
F_72 ( V_1 -> V_448 , & V_519 -> V_545 ) ;
V_524:
F_7 ( V_1 , V_5 , V_143 ,
V_546 ) ;
F_7 ( V_1 , V_5 , V_153 , 0 ) ;
return V_514 ;
}
static int F_84 ( int V_5 , struct V_1 * V_1 )
{
int V_514 = 0 ;
T_1 V_93 , V_194 ;
F_7 ( V_1 , V_5 , V_151 , 1 ) ;
V_93 = F_8 ( V_1 , V_5 , V_31 ) ;
V_194 = F_1 ( V_1 , V_195 ) ;
F_85 ( V_1 , V_5 , ( V_194 & 1 << V_5 ) ? 1 : 0 ) ;
F_7 ( V_1 , V_5 , V_143 , V_547 ) ;
F_7 ( V_1 , V_5 , V_151 , 0 ) ;
return V_514 ;
}
static T_8 F_86 ( int V_548 , void * V_549 )
{
struct V_1 * V_1 = V_549 ;
T_1 V_550 ;
int V_5 = 0 ;
T_8 V_514 = V_551 ;
V_550 = ( F_1 ( V_1 , V_552 )
>> V_553 ) & 0x1ff ;
while ( V_550 ) {
if ( V_550 & 1 ) {
T_1 V_554 = F_8 ( V_1 , V_5 ,
V_143 ) ;
if ( V_554 & V_546 )
if ( F_82 ( V_5 , V_1 ) ) {
V_514 = V_528 ;
goto V_524;
}
if ( V_554 & V_547 )
if ( F_84 ( V_5 , V_1 ) ) {
V_514 = V_528 ;
goto V_524;
}
}
V_550 >>= 1 ;
V_5 ++ ;
}
V_524:
return V_514 ;
}
static void F_87 ( int V_5 , struct V_1 * V_1 )
{
struct V_518 * V_519 = & V_1 -> V_519 [ V_5 ] ;
struct V_520 * V_521 = & V_519 -> V_521 ;
struct V_555 * V_556 = & V_1 -> V_557 ;
F_7 ( V_1 , V_5 , V_154 , 1 ) ;
V_556 -> V_558 ( V_521 , V_559 ) ;
F_7 ( V_1 , V_5 , V_143 ,
V_560 ) ;
F_7 ( V_1 , V_5 , V_154 , 0 ) ;
}
static T_8 F_88 ( int V_548 , void * V_549 )
{
struct V_1 * V_1 = V_549 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
T_1 V_561 , V_562 , V_550 ;
int V_5 = 0 ;
V_561 = F_1 ( V_1 , V_134 ) ;
V_562 = V_561 ;
V_561 |= V_563 ;
F_5 ( V_1 , V_134 , V_561 ) ;
V_550 = ( F_1 ( V_1 , V_552 ) >>
V_564 ) & 0x1ff ;
while ( V_550 ) {
if ( V_550 & ( 1 << V_5 ) ) {
T_1 V_565 = F_8 ( V_1 , V_5 ,
V_143 ) ;
T_1 V_566 = F_8 ( V_1 , V_5 ,
V_144 ) ;
T_1 V_567 = F_8 ( V_1 , V_5 ,
V_145 ) ;
if ( V_566 ) {
if ( V_566 & ( V_568 |
V_569 ) )
F_89 ( L_17 ,
F_90 ( V_55 ) , V_566 ) ;
F_7 ( V_1 , V_5 ,
V_144 , V_566 ) ;
}
if ( V_567 )
F_7 ( V_1 , V_5 ,
V_145 , V_567 ) ;
if ( V_565 ) {
if ( V_565 & V_560 )
F_87 ( V_5 , V_1 ) ;
F_7 ( V_1 , V_5 ,
V_143 , V_565
& ( ~ V_570 )
& ( ~ V_546 )
& ( ~ V_547 ) ) ;
}
}
V_550 &= ~ ( 1 << V_5 ) ;
V_5 ++ ;
}
F_5 ( V_1 , V_134 , V_562 ) ;
return V_551 ;
}
static T_8 F_91 ( int V_548 , void * V_549 )
{
struct V_571 * V_572 = V_549 ;
struct V_1 * V_1 = V_572 -> V_1 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
struct V_434 * V_435 ;
T_1 V_554 , V_573 , V_574 , V_82 ;
int V_203 = V_572 -> V_75 ;
V_435 = V_1 -> V_436 [ V_203 ] ;
V_554 = F_1 ( V_1 , V_129 ) ;
F_5 ( V_1 , V_129 , 1 << V_203 ) ;
V_573 = F_1 ( V_1 , V_575 +
( 0x14 * V_203 ) ) ;
V_574 = F_1 ( V_1 , V_576 +
( 0x14 * V_203 ) ) ;
while ( V_573 != V_574 ) {
struct V_434 * V_436 ;
int V_577 ;
V_436 = & V_435 [ V_573 ] ;
if ( V_436 -> V_578 ) {
T_1 V_579 = V_436 -> V_578 ;
int V_580 = F_69 ( V_579 ) ;
V_82 = ( V_436 -> V_257 & V_581 ) >>
V_582 ;
V_59 = & V_1 -> V_59 [ V_82 ] ;
while ( V_580 ) {
T_9 * V_583 = & V_59 -> V_584 [ 0 ] ;
V_580 -= 1 ;
V_577 = ( V_583 [ V_580 / 5 ]
>> ( V_580 % 5 ) * 12 ) & 0xfff ;
V_211 = & V_1 -> V_585 [ V_577 ] ;
V_211 -> V_438 = V_573 ;
V_211 -> V_437 = V_203 ;
F_70 ( V_1 , V_211 , 0 ) ;
V_579 &= ~ ( 1 << V_580 ) ;
V_580 = F_69 ( V_579 ) ;
}
} else {
V_577 = ( V_436 -> V_257 ) & V_586 ;
V_211 = & V_1 -> V_585 [ V_577 ] ;
V_211 -> V_438 = V_573 ;
V_211 -> V_437 = V_203 ;
F_70 ( V_1 , V_211 , 0 ) ;
}
if ( ++ V_573 >= V_162 )
V_573 = 0 ;
}
F_5 ( V_1 , V_575 + ( 0x14 * V_203 ) , V_573 ) ;
return V_551 ;
}
static T_8 F_92 ( int V_548 , void * V_549 )
{
struct V_518 * V_519 = V_549 ;
struct V_1 * V_1 = V_519 -> V_1 ;
struct V_520 * V_521 = & V_519 -> V_521 ;
struct V_8 * V_55 = & V_1 -> V_56 -> V_55 ;
struct V_587 * V_588 ;
struct V_311 * V_505 ;
T_1 V_562 , V_561 , V_589 , V_191 , V_516 , V_517 ;
T_8 V_514 = V_551 ;
T_6 V_536 [ V_46 ] = { 0 } ;
int V_5 , V_454 ;
V_5 = V_521 -> V_75 ;
V_588 = & V_1 -> V_588 [ V_5 ] ;
V_505 = & V_588 -> V_505 ;
V_454 = 4 * ( V_5 / 4 ) ;
V_561 = F_1 ( V_1 , V_132 + V_454 ) ;
F_5 ( V_1 , V_132 + V_454 ,
V_561 | 1 << ( ( V_5 % 4 ) * 8 ) ) ;
V_589 = F_1 ( V_1 , V_130 + V_454 ) ;
V_562 = V_589 & ( 1 << ( V_590 *
( V_5 % 4 ) ) ) ;
V_589 >>= V_590 * ( V_5 % 4 ) ;
if ( ( V_589 & V_591 ) == 0 ) {
F_22 ( V_55 , L_18 , V_5 ) ;
V_514 = V_528 ;
goto V_524;
}
if ( F_71 ( V_5 == 8 ) ) {
T_1 V_196 = F_1 ( V_1 , V_197 ) ;
V_191 = ( V_196 & V_198 ) >>
V_199 ;
V_516 = ( V_196 & V_525 ) >>
V_526 ;
} else {
V_191 = F_1 ( V_1 , V_193 ) ;
V_191 = ( V_191 >> ( 4 * V_5 ) ) & 0xf ;
V_516 = F_1 ( V_1 , V_527 ) ;
V_516 = ( V_516 >> ( V_5 * 4 ) ) & 0xf ;
}
if ( V_191 == 0xf ) {
F_35 ( V_55 , L_19 , V_5 ) ;
V_514 = V_528 ;
goto V_524;
}
V_521 -> V_72 = V_516 ;
V_517 = F_8 ( V_1 , V_5 ,
V_531 ) ;
V_519 -> V_532 = V_517 & 0xf ;
V_519 -> V_533 = ( V_517 >> 4 ) & 0xf ;
V_521 -> V_534 = V_592 ;
V_536 [ 0 ] = 0x50 ;
V_536 [ 7 ] = V_5 ;
memcpy ( V_521 -> V_536 , V_536 , V_46 ) ;
memcpy ( V_521 -> V_522 , V_505 , sizeof( struct V_311 ) ) ;
F_83 ( V_55 , L_20 , V_5 , V_516 ) ;
V_519 -> V_537 &= ~ ( V_538 | V_539 ) ;
V_519 -> V_191 = V_191 ;
V_519 -> V_537 |= V_539 ;
V_519 -> V_540 = 1 ;
V_519 -> V_541 . V_542 = V_68 ;
V_519 -> V_543 = sizeof( struct V_311 ) ;
V_519 -> V_541 . V_544 = V_404 ;
F_72 ( V_1 -> V_448 , & V_519 -> V_545 ) ;
V_524:
F_5 ( V_1 , V_130 + V_454 , V_562 ) ;
F_5 ( V_1 , V_132 + V_454 , V_561 ) ;
return V_514 ;
}
static int F_93 ( struct V_1 * V_1 )
{
struct V_593 * V_56 = V_1 -> V_56 ;
struct V_8 * V_55 = & V_56 -> V_55 ;
int V_20 , V_594 , V_182 , V_595 [ 128 ] ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ )
V_595 [ V_20 ] = F_94 ( V_56 , V_20 ) ;
for ( V_20 = 0 ; V_20 < V_596 ; V_20 ++ ) {
int V_267 = V_20 ;
V_594 = V_595 [ V_267 + 1 ] ;
if ( ! V_594 ) {
F_35 ( V_55 , L_21 ,
V_267 ) ;
return - V_597 ;
}
V_182 = F_95 ( V_55 , V_594 , V_598 [ V_20 ] , 0 ,
V_599 L_22 , V_1 ) ;
if ( V_182 ) {
F_35 ( V_55 , L_23
L_24 ,
V_594 , V_182 ) ;
return - V_597 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_54 ; V_20 ++ ) {
struct V_518 * V_519 = & V_1 -> V_519 [ V_20 ] ;
int V_267 = V_20 + 72 ;
V_594 = V_595 [ V_267 ] ;
if ( ! V_594 ) {
F_35 ( V_55 , L_21 ,
V_267 ) ;
return - V_597 ;
}
V_182 = F_95 ( V_55 , V_594 , F_92 , 0 ,
V_599 L_25 , V_519 ) ;
if ( V_182 ) {
F_35 ( V_55 , L_23
L_26 ,
V_594 , V_182 ) ;
return - V_597 ;
}
}
for ( V_20 = 0 ; V_20 < V_1 -> V_112 ; V_20 ++ ) {
int V_267 = V_20 + 96 ;
V_594 = V_595 [ V_267 ] ;
if ( ! V_594 ) {
F_35 ( V_55 ,
L_27 ,
V_267 ) ;
return - V_597 ;
}
V_182 = F_95 ( V_55 , V_594 , F_91 , 0 ,
V_599 L_28 , & V_1 -> V_572 [ V_20 ] ) ;
if ( V_182 ) {
F_35 ( V_55 ,
L_29 ,
V_594 , V_182 ) ;
return - V_597 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_1 )
{
int V_182 ;
V_182 = F_42 ( V_1 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_93 ( V_1 ) ;
if ( V_182 )
return V_182 ;
F_49 ( V_1 ) ;
return 0 ;
}
static int F_97 ( struct V_593 * V_56 )
{
return F_98 ( V_56 , & V_600 ) ;
}
static int F_99 ( struct V_593 * V_56 )
{
return F_100 ( V_56 ) ;
}
