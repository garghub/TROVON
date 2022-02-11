static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> error ;
V_2 -> error = 0 ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_4 , T_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_2 V_11 = V_4 ;
struct V_12 V_13 [] = {
{
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 ,
. V_6 = 1 ,
. V_5 = & V_11
} ,
{
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 | V_16 ,
. V_6 = V_6 ,
. V_5 = V_5
} ,
} ;
int V_3 ;
if ( V_2 -> error )
return;
V_3 = F_4 ( V_10 -> V_17 , V_13 , 2 ) ;
F_5 ( V_8 , L_1 , V_4 , V_6 , V_5 , V_3 ) ;
if ( V_3 != 2 ) {
F_6 ( V_8 , L_2 ,
V_4 , V_6 , V_3 ) ;
V_2 -> error = V_3 < 0 ? V_3 : - V_18 ;
}
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 , 1 ) ;
return V_3 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_4 , const T_2 * V_5 ,
int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_2 V_11 [ 2 ] ;
struct V_12 V_13 = {
. V_4 = V_14 [ V_4 >> 8 ] ,
. V_15 = V_10 -> V_15 ,
. V_6 = V_6 + 1 ,
} ;
int V_3 ;
if ( V_2 -> error )
return;
if ( V_6 > 1 ) {
V_13 . V_5 = F_9 ( V_6 + 1 , V_19 ) ;
if ( ! V_13 . V_5 ) {
V_2 -> error = - V_20 ;
return;
}
memcpy ( V_13 . V_5 + 1 , V_5 , V_6 ) ;
} else {
V_13 . V_5 = V_11 ;
V_13 . V_5 [ 1 ] = * V_5 ;
}
V_13 . V_5 [ 0 ] = V_4 ;
V_3 = F_4 ( V_10 -> V_17 , & V_13 , 1 ) ;
F_5 ( V_8 , L_3 , V_4 , V_6 , V_5 , V_3 ) ;
if ( V_3 != 1 ) {
F_6 ( V_8 , L_4 ,
V_4 , V_6 , V_5 , V_3 ) ;
V_2 -> error = V_3 ? : - V_18 ;
}
if ( V_6 > 1 )
F_10 ( V_13 . V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 , const T_1 * V_21 , int V_6 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 += 2 )
F_12 ( V_2 , V_21 [ V_22 ] , V_21 [ V_22 + 1 ] ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_23 , T_2 V_24 )
{
V_24 = ( V_24 & V_23 ) | ( F_7 ( V_2 , V_4 ) & ~ V_23 ) ;
F_12 ( V_2 , V_4 , V_24 ) ;
}
static inline bool F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_25 >= V_26 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_27 * V_13 , * V_28 ;
F_16 (msg, n, &ctx->mt_queue, node) {
F_17 ( & V_13 -> V_29 ) ;
F_10 ( V_13 ) ;
}
V_2 -> V_30 = V_31 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_27 * V_13 ;
if ( V_2 -> error )
return;
if ( V_2 -> V_30 == V_32 || F_19 ( & V_2 -> V_33 ) )
return;
if ( V_2 -> V_30 == V_34 ) {
V_2 -> V_30 = V_31 ;
V_13 = F_20 ( & V_2 -> V_33 , struct V_27 ,
V_29 ) ;
F_17 ( & V_13 -> V_29 ) ;
if ( V_13 -> V_35 )
V_13 -> V_35 ( V_2 , V_13 ) ;
if ( V_13 -> V_36 )
V_13 -> V_36 ( V_2 , V_13 -> V_3 ) ;
F_10 ( V_13 ) ;
}
if ( V_2 -> V_30 != V_31 || F_19 ( & V_2 -> V_33 ) )
return;
V_2 -> V_30 = V_32 ;
V_13 = F_20 ( & V_2 -> V_33 , struct V_27 , V_29 ) ;
if ( V_13 -> V_37 )
V_13 -> V_37 ( V_2 , V_13 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_38 = V_39 ;
if ( V_2 -> V_40 )
return;
if ( V_2 -> V_25 >= V_41 )
V_38 |= V_42 ;
F_22 ( V_2 ,
V_43 , 100 ,
V_44 , V_38
) ;
V_2 -> V_40 = 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 )
return;
F_24 ( V_2 ,
V_45 , 0 ,
V_44 , 0
) ;
V_2 -> V_40 = 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_46 , V_47
| V_48 | V_49
| V_50 | V_51
| V_52 ,
V_53 , V_54
| V_55
| V_56
) ;
F_21 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_27 * V_13 )
{
if ( V_13 -> V_57 [ 0 ] == V_58 &&
V_13 -> V_57 [ 1 ] == F_27 ( V_59 ) &&
V_13 -> V_57 [ 2 ] == V_60 )
F_21 ( V_2 ) ;
else
F_23 ( V_2 ) ;
switch ( V_13 -> V_57 [ 0 ] ) {
case V_61 :
case V_58 :
F_8 ( V_2 , V_62 , V_13 -> V_57 + 1 , 2 ) ;
F_12 ( V_2 , V_63 ,
V_64 ) ;
break;
case V_65 :
F_8 ( V_2 , V_62 , V_13 -> V_57 , 3 ) ;
F_12 ( V_2 , V_63 ,
V_66 ) ;
break;
case V_67 :
case V_68 :
F_12 ( V_2 , V_62 , V_13 -> V_57 [ 1 ] ) ;
F_12 ( V_2 , V_63 ,
V_69 ) ;
break;
default:
F_6 ( V_2 -> V_8 , L_5 , V_70 ,
V_13 -> V_57 [ 0 ] ) ;
}
}
static struct V_27 * F_28 ( struct V_1 * V_2 )
{
struct V_27 * V_13 = F_29 ( sizeof( * V_13 ) , V_19 ) ;
if ( ! V_13 )
V_2 -> error = - V_20 ;
else
F_30 ( & V_13 -> V_29 , & V_2 -> V_33 ) ;
return V_13 ;
}
static void F_31 ( struct V_1 * V_2 , T_3 V_71 )
{
struct V_27 * V_13 ;
if ( V_2 -> error )
return;
if ( F_19 ( & V_2 -> V_33 ) ) {
V_2 -> error = - V_72 ;
return;
}
V_13 = F_32 ( & V_2 -> V_33 , struct V_27 , V_29 ) ;
V_13 -> V_36 = V_71 ;
}
static void F_33 ( struct V_1 * V_2 , T_2 V_73 , T_2 V_74 , T_2 V_75 )
{
struct V_27 * V_13 = F_28 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_57 [ 0 ] = V_73 ;
V_13 -> V_57 [ 1 ] = V_74 ;
V_13 -> V_57 [ 2 ] = V_75 ;
V_13 -> V_37 = F_26 ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_57 , T_2 V_24 )
{
F_33 ( V_2 , V_61 , V_57 , V_24 ) ;
}
static inline void F_35 ( struct V_1 * V_2 , T_2 V_76 , T_2 V_23 )
{
F_33 ( V_2 , V_58 , V_76 , V_23 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_2 V_73 , T_2 V_11 )
{
F_33 ( V_2 , V_65 , V_73 , V_11 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_77 )
{
F_36 ( V_2 , V_78 , V_77 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_27 * V_13 )
{
T_2 V_38 = V_79
| V_80
| V_81 ;
if ( V_13 -> V_57 [ 0 ] == V_82 )
V_38 |= V_83 ;
F_22 ( V_2 ,
V_84 , V_85 ,
V_86 , V_38 ,
V_87 , V_88
) ;
}
static void F_39 ( T_2 * V_89 , T_2 * V_90 , int V_91 )
{
while ( -- V_91 >= 0 ) {
* V_90 ^= * V_89 ;
* V_89 ++ ^= * V_90 ++ ;
}
}
static void F_40 ( struct V_1 * V_2 , int V_3 )
{
static const char * const V_92 [] = {
[ V_93 ] = L_6 ,
[ V_94 ] = L_7 ,
[ V_95 ] = L_8
} ;
char V_96 [ 20 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_3 < 0 )
return;
F_41 ( V_2 ) ;
if ( ! V_2 -> V_97 ) {
F_6 ( V_2 -> V_8 , L_9 ) ;
F_42 ( V_2 ) ;
return;
}
if ( F_43 ( V_2 -> V_97 ) )
V_2 -> V_98 = V_94 ;
else
V_2 -> V_98 = V_95 ;
F_44 ( V_2 -> V_97 , V_96 , F_45 ( V_96 ) ) ;
F_46 ( V_8 , L_10 ,
V_92 [ V_2 -> V_98 ] , V_96 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_2 ) )
return;
F_12 ( V_2 , V_99 ,
V_100 | V_101 ) ;
F_13 ( V_2 , V_102 ,
V_103 | V_104 , ~ 0 ) ;
F_13 ( V_2 , V_105 , V_106 , 4 ) ;
F_13 ( V_2 , V_107 , V_108 , ~ 0 ) ;
F_13 ( V_2 , V_109 , V_110 , 0 ) ;
F_13 ( V_2 , V_111 , V_112 , V_113 ) ;
F_24 ( V_2 ,
V_114 , 0 ,
V_115 , V_116 | V_117 |
V_118 | V_119 ,
V_115 , V_116 | V_117 ,
V_120 , 0xff ,
V_121 , 0xff ,
V_122 , 0xff ,
V_123 , 0xff ,
V_124 , 0xff ,
V_125 , 0xff ,
V_126 , 0xff ,
V_127 , 0xff ,
V_128 , 0xff ,
V_129 , 0xff ,
V_130 , 0xff ,
V_131 , 0xff ,
V_132 , 0xff ,
V_133 , 0xff ,
V_134 , 0xff ,
V_135 , 0xff
) ;
}
static void F_48 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 )
return;
F_49 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_2 V_136 [ V_137 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_2 ( V_2 , V_138 , V_136 , V_137 ) ;
if ( V_2 -> error < 0 )
return;
F_46 ( V_8 , L_11 ,
V_136 [ V_139 ] / 16 ,
V_136 [ V_139 ] % 16 ,
V_136 [ V_140 ] , V_136 [ V_141 ] ,
V_136 [ V_142 ] , V_136 [ V_143 ] ) ;
F_39 ( V_2 -> V_144 , V_136 , V_137 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_138 , V_2 -> V_145 ,
V_146 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_27 * V_13 )
{
T_2 V_38 = V_79
| V_80
| V_81 ;
if ( V_13 -> V_57 [ 0 ] == V_82 )
V_38 |= V_83 ;
F_22 ( V_2 ,
V_84 , V_85 | V_147
| V_148 ,
V_86 , V_38 ,
V_149 , 0
) ;
if ( V_13 -> V_57 [ 0 ] == V_82 )
F_52 ( V_2 ) ;
else
F_51 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 , bool V_145 )
{
struct V_27 * V_13 = F_28 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_57 [ 0 ] = V_145 ? V_82 : V_150 ;
V_13 -> V_37 = F_38 ;
V_13 -> V_35 = F_53 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_27 * V_13 )
{
T_2 V_57 = V_13 -> V_57 [ 0 ] & 0x7f ;
if ( V_13 -> V_57 [ 0 ] & 0x80 )
V_2 -> V_145 [ V_57 ] = V_13 -> V_3 ;
else
V_2 -> V_144 [ V_57 ] = V_13 -> V_3 ;
}
static void F_56 ( struct V_1 * V_2 , T_2 V_57 )
{
struct V_27 * V_13 = F_28 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_57 [ 0 ] = ( V_57 & 0x80 ) ? V_68 : V_67 ;
V_13 -> V_57 [ 1 ] = V_57 ;
V_13 -> V_37 = F_26 ;
V_13 -> V_35 = F_55 ;
}
static inline void F_57 ( struct V_1 * V_2 , T_2 V_57 )
{
F_56 ( V_2 , V_57 | 0x80 ) ;
}
static void * F_58 ( struct V_1 * V_2 , int V_6 )
{
T_2 * V_5 = & V_2 -> V_151 . V_152 [ V_2 -> V_151 . V_153 ] ;
int V_154 = V_6 + 2 ;
if ( V_2 -> V_151 . V_153 + V_154 > F_45 ( V_2 -> V_151 . V_152 ) ) {
F_6 ( V_2 -> V_8 , L_12 ) ;
V_2 -> error = - V_72 ;
return NULL ;
}
V_2 -> V_151 . V_153 += V_154 ;
V_5 [ 1 ] = V_6 ;
return V_5 + 2 ;
}
static T_2 * F_59 ( struct V_1 * V_2 , int V_6 )
{
T_2 * V_5 = & V_2 -> V_151 . V_155 [ V_2 -> V_151 . V_156 ] ;
int V_154 = V_6 + 1 ;
if ( V_2 -> V_151 . V_153 + V_154 > F_45 ( V_2 -> V_151 . V_152 ) ) {
F_6 ( V_2 -> V_8 , L_13 ) ;
V_2 -> error = - V_72 ;
return NULL ;
}
V_2 -> V_151 . V_156 += V_154 ;
V_5 [ 0 ] = V_6 ;
return V_5 + 1 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_157 = V_2 -> V_151 . V_153 ;
T_2 * V_158 = V_2 -> V_151 . V_152 ;
while ( V_157 > 0 ) {
int V_6 = V_158 [ 1 ] + 2 ;
if ( V_2 -> V_151 . V_159 + V_6 > V_2 -> V_151 . V_160 )
break;
V_158 [ 0 ] = F_61 ( V_2 -> V_151 . V_161 , 255 ) ;
V_2 -> V_151 . V_161 -= V_158 [ 0 ] ;
F_8 ( V_2 , V_162 , V_158 , V_6 ) ;
V_2 -> V_151 . V_159 += V_6 ;
V_157 -= V_6 ;
V_158 += V_6 ;
}
V_2 -> V_151 . V_153 = V_157 ;
while ( V_2 -> V_151 . V_161 > 0 ) {
T_2 V_163 [ 2 ] = { F_61 ( V_2 -> V_151 . V_161 , 255 ) , 0 } ;
if ( V_2 -> V_151 . V_159 + 2 > V_2 -> V_151 . V_160 )
break;
V_2 -> V_151 . V_161 -= V_163 [ 0 ] ;
F_8 ( V_2 , V_162 , V_163 , 2 ) ;
V_2 -> V_151 . V_159 += 2 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
T_2 V_5 [ 3 ] , * V_158 ;
int V_91 ;
F_2 ( V_2 , V_164 , V_5 , 2 ) ;
V_91 = F_63 ( V_5 ) ;
while ( V_91 > 0 ) {
int V_6 = F_61 ( V_91 , 3 ) ;
F_2 ( V_2 , V_165 , V_5 , V_6 ) ;
V_91 -= V_6 ;
V_2 -> V_151 . V_161 += V_6 - 1 ;
V_2 -> V_151 . V_159 -= V_5 [ 1 ] ;
if ( V_2 -> V_151 . V_159 < 0 )
V_2 -> V_151 . V_159 = 0 ;
if ( V_6 < 3 || ! V_5 [ 2 ] )
continue;
V_6 = V_5 [ 2 ] ;
V_158 = F_59 ( V_2 , V_6 ) ;
if ( ! V_158 )
continue;
F_2 ( V_2 , V_165 , V_158 , V_6 ) ;
V_91 -= V_6 ;
V_2 -> V_151 . V_161 += V_6 ;
}
}
static void F_64 ( struct V_1 * V_2 , int V_154 )
{
struct V_166 * V_158 =
F_58 ( V_2 , sizeof( * V_158 ) ) ;
if ( ! V_158 )
return;
V_158 -> V_167 = F_65 ( V_168 ) ;
V_158 -> V_154 = F_66 ( V_154 ) ;
}
static T_2 F_67 ( void * V_169 , int V_154 )
{
T_2 * V_158 = V_169 , V_170 = 0 ;
while ( V_154 -- )
V_170 += * V_158 ++ ;
return V_170 ;
}
static void F_68 ( struct V_171 * V_172 ,
enum V_173 V_167 )
{
V_172 -> V_167 = F_65 ( V_167 ) ;
V_172 -> V_174 = 1 ;
V_172 -> V_175 = 1 ;
}
static void F_69 ( struct V_1 * V_2 , T_2 V_176 )
{
struct V_177 * V_158 ;
const int V_154 = sizeof( * V_158 ) + sizeof( V_158 -> V_178 [ 0 ] ) ;
V_158 = F_58 ( V_2 , V_154 ) ;
if ( ! V_158 )
return;
F_68 ( & V_158 -> V_179 , V_180 ) ;
V_158 -> V_181 = 1 ;
V_158 -> V_178 [ 0 ] . V_182 = 0 ;
V_158 -> V_178 [ 0 ] . V_183 = V_176 ;
V_158 -> V_179 . V_184 -= F_67 ( V_158 , V_154 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_2 * V_158 = V_2 -> V_151 . V_155 ;
int V_91 = V_2 -> V_151 . V_156 ;
while ( V_91 -- > 0 ) {
int V_6 = * V_158 ++ ;
int V_167 = F_71 ( & V_158 [ 0 ] ) ;
switch ( V_167 ) {
case V_168 :
V_2 -> V_151 . V_160 = F_63 ( & V_158 [ 2 ] ) ;
break;
default:
break;
}
V_91 -= V_6 ;
V_158 += V_6 ;
}
V_2 -> V_151 . V_156 = 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_2 V_185 , V_186 , V_187 , V_188 ;
int V_189 , V_22 ;
int V_190 = V_191 ;
T_2 * V_97 ;
F_7 ( V_2 , V_192 ) ;
V_185 = F_7 ( V_2 , V_193 ) ;
V_186 = F_7 ( V_2 , V_194 ) ;
F_22 ( V_2 ,
V_84 , 0 ,
V_86 , V_80 ,
V_195 , 0x71 ,
V_196 , V_197 ,
V_193 , V_185 | V_198 ,
) ;
for ( V_22 = 0 ; V_22 < 256 ; ++ V_22 ) {
T_2 V_199 = F_7 ( V_2 , V_200 ) ;
if ( ! ( V_199 & V_201 ) )
break;
F_12 ( V_2 , V_200 ,
V_202 ) ;
}
F_12 ( V_2 , V_203 , 0x50 << 1 ) ;
V_97 = F_9 ( V_191 , V_19 ) ;
if ( ! V_97 ) {
V_2 -> error = - V_20 ;
return;
}
#define F_72 16
for ( V_189 = 0 ; V_189 < V_190 ; V_189 += F_72 ) {
F_7 ( V_2 , V_200 ) ;
F_22 ( V_2 ,
V_194 , V_186 | V_204 ,
V_194 , V_186 | V_205 ,
V_200 , V_202
) ;
F_22 ( V_2 ,
V_206 , V_189 >> 8 ,
V_207 , V_189 & 0xff ,
V_208 , F_72 ,
V_209 , 0 ,
V_194 , V_186 | V_210
) ;
do {
V_187 = F_7 ( V_2 , V_211 ) ;
V_188 = F_7 ( V_2 , V_192 ) ;
if ( V_187 & V_212 )
break;
if ( ! ( V_188 & V_213 ) ) {
F_10 ( V_97 ) ;
V_97 = NULL ;
goto V_214;
}
} while ( 1 );
F_7 ( V_2 , V_200 ) ;
while ( F_7 ( V_2 , V_215 ) < F_72 )
F_73 ( 10 , 20 ) ;
F_2 ( V_2 , V_216 , V_97 + V_189 , F_72 ) ;
if ( V_189 + F_72 == V_191 ) {
T_2 V_217 = ( (struct V_97 * ) V_97 ) -> V_218 ;
if ( V_217 ) {
T_2 * V_219 ;
V_190 += V_217 * V_191 ;
V_219 = F_74 ( V_97 , V_190 , V_19 ) ;
if ( ! V_219 ) {
F_10 ( V_97 ) ;
V_2 -> error = - V_20 ;
return;
}
V_97 = V_219 ;
}
}
}
F_22 ( V_2 ,
V_220 , V_212 ,
V_193 , V_185
) ;
V_214:
F_10 ( V_2 -> V_97 ) ;
V_2 -> V_97 = (struct V_97 * ) V_97 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_221 , V_222 | V_223
| V_224 , 0xff ) ;
F_24 ( V_2 ,
V_225 , 0x00 ,
V_226 , 0xFF ,
V_227 , 0xFF ,
V_228 , 0x06
) ;
F_13 ( V_2 , V_229 ,
V_230 , 0xff ) ;
F_24 ( V_2 ,
V_86 , V_80
| V_81 ,
V_149 , 0 ,
) ;
F_8 ( V_2 , V_231 , ( T_2 * ) V_2 -> V_97 ,
( V_2 -> V_97 -> V_218 + 1 ) * V_191 ) ;
F_24 ( V_2 ,
V_86 , V_232
| V_80
| V_81 ,
V_233 , V_234 ,
V_84 , 0
) ;
}
static void F_75 ( struct V_1 * V_2 )
{
static const struct {
unsigned int V_235 ;
T_2 div ;
T_2 V_236 ;
} V_237 [] = {
{ 19200 , 0x04 , 0x53 } ,
{ 20000 , 0x04 , 0x62 } ,
{ 24000 , 0x05 , 0x75 } ,
{ 30000 , 0x06 , 0x92 } ,
{ 38400 , 0x0c , 0xbc } ,
} ;
unsigned long V_235 = F_76 ( V_2 -> V_238 ) / 1000 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_45 ( V_237 ) - 1 ; ++ V_22 )
if ( V_235 <= V_237 [ V_22 ] . V_235 )
break;
if ( V_235 != V_237 [ V_22 ] . V_235 )
F_6 ( V_2 -> V_8 , L_14 ,
V_235 , V_237 [ V_22 ] . V_235 ) ;
F_12 ( V_2 , V_239 , V_237 [ V_22 ] . div ) ;
F_12 ( V_2 , V_240 , V_237 [ V_22 ] . V_236 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_78 ( F_45 ( V_2 -> V_241 ) , V_2 -> V_241 ) ;
if ( V_3 )
return V_3 ;
F_73 ( 10000 , 20000 ) ;
return F_79 ( V_2 -> V_238 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_81 ( V_2 -> V_238 ) ;
F_82 ( V_2 -> V_242 , 1 ) ;
return F_83 ( F_45 ( V_2 -> V_241 ) , V_2 -> V_241 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_73 ( 10000 , 20000 ) ;
F_82 ( V_2 -> V_242 , 0 ) ;
F_73 ( 5000 , 20000 ) ;
F_82 ( V_2 -> V_242 , 1 ) ;
F_73 ( 10000 , 20000 ) ;
F_82 ( V_2 -> V_242 , 0 ) ;
F_85 ( 300 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_243 , V_244
| V_245 ) ;
F_73 ( 10000 , 20000 ) ;
F_12 ( V_2 , V_243 , V_245 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 != V_41 ) {
F_24 ( V_2 ,
V_246 , 0x0 ,
V_247 , V_248
| V_249
| V_250
) ;
} else {
F_24 ( V_2 ,
V_246 , V_251 ,
V_247 , V_248
| V_250
) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
T_2 V_252 ( V_24 ) ;
F_24 ( V_2 ,
V_253 , 0 ,
V_254 , 0 ,
V_255 , 0 ,
V_256 , ~ 0 ,
) ;
switch ( V_2 -> V_98 ) {
case V_95 :
V_24 = V_257
| V_258 ;
break;
case V_94 :
default:
V_24 = V_257
| V_258
| V_259 ;
break;
}
F_12 ( V_2 , V_260 , V_24 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_2 V_261 ;
if ( F_14 ( V_2 ) ) {
F_13 ( V_2 , V_262 ,
V_263 ,
V_2 -> V_264 ? ~ 0 : 0 ) ;
} else {
if ( V_2 -> V_264 )
F_24 ( V_2 ,
V_265 , V_266 ,
V_267 , V_268 | 1 ,
V_269 , 0x60
) ;
else
F_24 ( V_2 ,
V_265 , 0 ,
V_267 , 1 ,
V_269 , 0xa0
) ;
}
if ( V_2 -> V_264 )
V_261 = F_90 ( V_270 , V_271 ) |
V_272 ;
else
V_261 = F_90 ( V_273 , V_271 ) ;
F_22 ( V_2 ,
V_274 , F_90 ( V_273 , V_271 ) ,
V_275 , V_261 ,
) ;
}
static int F_91 ( struct V_276 * V_277 )
{
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_278 = 3 ;
V_277 -> V_279 = - 1 ;
return 0 ;
}
static T_4 F_92 ( struct V_276 * V_277 ,
void * V_280 , T_5 V_154 )
{
const int V_281 = V_282 + V_283 ;
T_2 * V_169 = V_280 ;
if ( V_154 < V_281 )
return - V_284 ;
memset ( V_280 , 0 , V_154 ) ;
V_169 [ 0 ] = V_285 ;
V_169 [ 1 ] = V_277 -> V_278 ;
V_169 [ 2 ] = V_283 ;
V_169 [ 4 ] = V_286 & 0xff ;
V_169 [ 5 ] = ( V_286 >> 8 ) & 0xff ;
V_169 [ 6 ] = ( V_286 >> 16 ) & 0xff ;
V_169 [ 7 ] = V_277 -> V_287 & 0x3 ;
V_169 [ 7 ] |= ( V_277 -> V_288 & 0x7 ) << 2 ;
V_169 [ 7 ] |= V_277 -> V_289 ? F_93 ( 5 ) : 0 ;
if ( V_277 -> V_279 >= 0 ) {
V_169 [ 9 ] = 1 ;
V_169 [ 10 ] = ( V_277 -> V_279 >> 8 ) & 0xff ;
V_169 [ 11 ] = V_277 -> V_279 & 0xff ;
}
if ( V_277 -> V_290 ) {
bool V_291 = V_277 -> V_290 < 0 ;
int V_292 = V_291 ? - V_277 -> V_290 : V_277 -> V_290 ;
V_169 [ 12 ] = ( V_292 >> 16 ) & 0xf ;
if ( V_291 )
V_169 [ 12 ] |= F_93 ( 4 ) ;
V_169 [ 13 ] = ( V_292 >> 8 ) & 0xff ;
V_169 [ 14 ] = V_292 & 0xff ;
}
V_169 [ 3 ] -= F_67 ( V_280 , V_281 ) ;
return V_281 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_276 V_293 ;
union V_294 V_295 ;
T_2 V_5 [ 31 ] ;
int V_3 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_264 ) {
F_12 ( V_2 , V_260 ,
V_259 ) ;
F_8 ( V_2 , V_296 , V_2 -> V_297 + 3 ,
F_45 ( V_2 -> V_297 ) - 3 ) ;
F_12 ( V_2 , V_226 ,
V_298 |
V_299 |
V_300 ,
V_301 ) ;
return;
}
V_3 = F_95 ( & V_295 . V_302 ) ;
V_295 . V_302 . V_303 = V_304 ;
V_295 . V_302 . V_305 = V_306 ;
V_295 . V_302 . V_307 = V_308 ;
V_295 . V_302 . V_309 = V_310 ;
V_295 . V_302 . V_311 = V_2 -> V_311 ;
if ( ! V_3 )
V_3 = F_96 ( & V_295 . V_302 , V_5 , F_45 ( V_5 ) ) ;
if ( V_3 > 0 )
F_8 ( V_2 , V_296 , V_5 + 3 , V_3 - 3 ) ;
F_12 ( V_2 , V_226 ,
V_298 |
V_299 |
V_312 |
V_300 ,
V_313 |
V_301 |
V_314 ) ;
F_12 ( V_2 , V_315 , V_316
| V_317 | V_318 ) ;
V_3 = F_91 ( & V_293 ) ;
if ( ! V_3 )
V_3 = F_92 ( & V_293 , V_5 , F_45 ( V_5 ) ) ;
F_8 ( V_2 , V_319 , V_5 , V_3 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_320 , V_321
| V_322 ,
V_323 , V_324
| V_325 ) ;
F_89 ( V_2 ) ;
if ( ! F_14 ( V_2 ) ) {
F_34 ( V_2 , F_98 ( V_326 ) ,
V_327 | V_328 ) ;
F_87 ( V_2 ) ;
} else {
static const struct {
int V_329 ;
T_2 V_330 ;
T_2 V_331 ;
T_2 V_332 ;
} V_333 [] = {
{ 150000 , V_334 ,
V_335 , 0x38 } ,
{ 300000 , V_336 ,
V_337 , 0x40 } ,
{ 600000 , V_338 ,
V_339 , 0x40 } ,
} ;
T_2 V_340 = V_341 ;
int V_342 = V_2 -> V_343 * ( V_2 -> V_264 ? 2 : 3 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_45 ( V_333 ) ; ++ V_22 )
if ( V_342 < V_333 [ V_22 ] . V_329 )
break;
if ( 100 * V_342 >= 98 * V_333 [ V_22 ] . V_329 )
V_340 |= V_344 ;
F_69 ( V_2 , V_2 -> V_264 ) ;
F_60 ( V_2 ) ;
F_22 ( V_2 ,
V_345 , 0xf0 ,
V_346 , V_333 [ V_22 ] . V_330 ) ;
F_13 ( V_2 , V_262 ,
V_341
| V_344 , V_340 ) ;
F_13 ( V_2 , V_347 , V_348 ,
V_333 [ V_22 ] . V_332 ) ;
F_24 ( V_2 ,
V_349 , V_350
| V_351 ,
V_349 , V_350
) ;
F_34 ( V_2 , F_99 ( V_352 ) ,
V_333 [ V_22 ] . V_331 ) ;
}
F_94 ( V_2 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
if ( ! F_14 ( V_2 ) )
F_88 ( V_2 ) ;
switch ( V_2 -> V_98 ) {
case V_94 :
F_97 ( V_2 ) ;
break;
case V_95 :
default:
break;
}
}
static void F_101 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_86 , V_232 , 0 ) ;
F_24 ( V_2 ,
V_353 , V_354 ,
V_355 , 0
) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_356 ,
V_357
| V_358 , ~ 0 ) ;
F_24 ( V_2 ,
V_353 , V_354
| V_359 ,
) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_360 , V_361
| V_362 ,
V_363 , F_103 ( V_364 , V_365 ) ,
V_366 , V_367
| V_368
| V_369
| V_370
| V_371
| V_372 ,
V_247 , V_248
| V_249
| V_250 ,
V_345 , V_373
| V_374 ,
V_349 , V_350 ,
V_375 , 0xA2 ,
V_376 , 0x03 ,
V_377 , 0x35 ,
V_378 , 0x02 ,
V_379 , 0x02 ,
V_380 , 0x03 ,
V_381 , 0xFF ,
V_221 , V_382 | V_383
| V_384 | V_385 ,
V_386 , V_387
| V_388 ,
V_389 , V_390
| V_391 ,
V_392 , V_393
| V_394
| V_395
| V_396
| V_397
| V_398
| V_399
) ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 ) )
F_24 ( V_2 ,
V_400 , V_401 ,
V_402 ,
V_403
) ;
else
F_24 ( V_2 ,
V_254 , 0x00 ,
V_402 , 0x00 ,
V_404 , 0xFF ,
V_405 , 0xFF ,
V_400 , V_401
| V_406
) ;
}
static void F_105 ( struct V_1 * V_2 )
{
static const T_2 V_144 [ V_137 ] = {
[ V_139 ] = V_407 ,
[ V_408 ] = V_409 | V_410 ,
[ V_140 ] = 0x01 ,
[ V_141 ] = 0x41 ,
[ V_411 ] = V_412
| V_413
| V_414 ,
[ V_415 ] = V_416 ,
[ V_417 ] = V_418 ,
[ V_419 ] = V_420 ,
[ V_421 ] = 0x0f ,
[ V_422 ] = V_423
| V_424
| V_425 ,
[ V_426 ] = V_427 ,
[ V_428 ] = V_429 ,
} ;
static const T_2 V_430 [ V_146 ] = {
[ V_431 ] = V_432
| V_433 ,
[ V_434 ] = V_435
| V_436 | V_437 ,
[ V_438 ] = V_439 ,
[ V_440 ] = V_441 ,
} ;
F_8 ( V_2 , V_442 , V_144 , F_45 ( V_144 ) ) ;
F_8 ( V_2 , V_443 , V_430 , F_45 ( V_430 ) ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_363 , F_103 ( V_444 , V_365 ) ,
V_445 ,
V_446 ,
) ;
F_104 ( V_2 ) ;
F_101 ( V_2 ) ;
F_24 ( V_2 ,
V_86 , V_80 ,
V_360 , V_361
| V_447 ,
V_448 , 0x90 ,
V_449 , 0x01 ,
V_450 , 0x11 ,
V_451 , 0x87 ,
V_452 , 0xE8 ,
V_453 , 0x04 ,
) ;
F_13 ( V_2 , V_193 , V_198 , 0 ) ;
F_24 ( V_2 ,
V_454 , 0x76 ,
V_455 , V_456 ,
V_457 , 79 ,
) ;
F_105 ( V_2 ) ;
F_24 ( V_2 ,
V_458 , 100 ,
V_45 , 0x03 ,
V_459 , 0x00 ,
V_43 , 100 ,
V_460 , 0x1D ,
) ;
F_25 ( V_2 ) ;
F_24 ( V_2 ,
V_461 , 0x00 ,
V_462 , 0x10 ,
V_463 , 0x18 ,
V_464 , 0x07 ,
V_465 , 0xF8 ,
V_466 , 0x61 ,
V_467 , 0x46 ,
V_468 , 0x15 ,
V_469 , 0x01 ,
V_470 , V_471 ,
V_472 , 0x2D ,
V_473 , 0xF9 ,
V_474 , 0x27 ,
) ;
F_23 ( V_2 ) ;
F_34 ( V_2 , F_98 ( V_475 ) , V_407 ) ;
F_34 ( V_2 , F_98 ( V_476 ) ,
V_477 | V_478
| V_479 ) ;
F_35 ( V_2 , F_27 ( V_59 ) , V_480 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_2 V_57 ;
F_13 ( V_2 , V_481 , V_482
| V_483
| V_484 , ~ 0 ) ;
F_13 ( V_2 , V_481 , V_483
| V_484 , 0 ) ;
F_13 ( V_2 , V_485 , V_486 , ~ 0 ) ;
V_57 = F_7 ( V_2 , V_487 ) ;
F_12 ( V_2 , V_487 , V_57 ) ;
F_12 ( V_2 , V_488 , V_489 ) ;
}
static int F_108 ( struct V_1 * V_2 , T_2 V_490 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 10 ; ++ V_22 ) {
T_2 V_491 = F_7 ( V_2 , V_492 ) ;
if ( ( V_491 & V_493 ) == V_490 )
return 0 ;
if ( ! ( V_491 & V_494 ) )
return - V_495 ;
F_73 ( 4000 , 6000 ) ;
}
return - V_496 ;
}
static void F_109 ( struct V_1 * V_2 , enum V_497 V_25 )
{
int V_3 ;
if ( V_2 -> V_25 == V_25 )
return;
switch ( V_25 ) {
case V_41 :
F_24 ( V_2 ,
V_445 , 0x02 ,
V_349 , V_498 ,
V_221 , V_382 | V_383
| V_384 ,
V_386 , 0
) ;
V_2 -> V_25 = V_25 ;
break;
case V_26 :
F_12 ( V_2 , V_349 , V_350 ) ;
V_2 -> V_25 = V_25 ;
return;
case V_499 :
F_107 ( V_2 ) ;
F_24 ( V_2 ,
V_500 , 4 ,
V_501 , 4 ,
V_502 , 0x14 ,
V_503 , 0x14 ,
V_504 , 0x18 ,
V_505 , 0x18 ,
V_243 , V_506
| V_245 ,
V_507 , 0xbd ,
V_243 , V_245 ,
V_508 , 0x01 ,
V_509 , 0x5c ,
V_510 , 0x03 ,
V_511 , 0x80 ,
V_379 , V_512
| V_513
| V_514 ,
V_515 , 0x03
) ;
V_3 = F_108 ( V_2 , 0x03 ) ;
F_24 ( V_2 ,
V_510 , 0x00 ,
V_511 , 0x80
) ;
if ( ! V_3 )
F_12 ( V_2 , V_516 , 0x85 ) ;
else
F_110 ( V_2 ) ;
return;
case V_517 :
V_2 -> V_25 = V_25 ;
break;
default:
F_6 ( V_2 -> V_8 , L_15 , V_70 , V_25 ) ;
break;
}
F_87 ( V_2 ) ;
if ( V_25 != V_41 )
return;
F_24 ( V_2 ,
V_345 , 0xBC ,
V_375 , 0xBB ,
V_377 , 0x48 ,
V_378 , 0x39 ,
V_376 , 0x2A ,
V_379 , 0x2A ,
V_380 , 0x08
) ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_88 ( V_2 ) ;
F_85 ( 100 ) ;
F_86 ( V_2 ) ;
F_109 ( V_2 , V_517 ) ;
F_24 ( V_2 ,
V_246 , 0 ,
V_247 , 0x07 ,
V_509 , 0x40 ,
V_516 , 0x84 ,
V_510 , 0x00 ,
V_509 , 0x40 ,
V_102 , 0x07 ,
V_247 , V_248
| V_249
| V_250 ,
V_345 , V_373
| V_374 ,
V_375 , 0xBB ,
V_377 , 0x48 ,
V_378 , 0x3F ,
V_376 , 0x2F ,
V_379 , 0x2A ,
V_380 , 0x03
) ;
F_101 ( V_2 ) ;
F_24 ( V_2 ,
V_349 , V_350 ,
V_507 , 0x07 ,
V_363 , F_103 ( V_444 , V_365 ) ,
V_518 , 0x00 ,
V_360 , V_361
| V_447 ,
V_519 , 0x00 ,
V_474 , 0x27 ,
V_520 , 0x25 ,
V_521 , ( T_2 ) ~ V_372 ,
V_366 , V_372 ,
V_522 , 0xff ,
V_46 , 0x00 ,
V_523 , 0xff ,
V_53 , 0x00 ,
V_524 , 0xff ,
V_386 , 0x00 ,
V_125 , 0xff ,
V_525 , 0x00 ,
V_526 , 0xff ,
V_392 , 0x00 ,
V_527 , 0xff ,
V_389 , 0x00 ,
V_487 , 0xff ,
V_488 , 0x00 ,
V_528 , 0xff ,
V_402 , 0x00 ,
V_529 , 0xff ,
V_355 , 0x00 ,
V_256 , 0xff ,
V_253 , 0x00 ,
V_404 , 0xff ,
V_254 , 0x00 ,
V_530 , 0xff ,
V_84 , 0x00 ,
V_211 , 0xff ,
V_220 , 0x00 ,
V_531 , 0xff ,
V_233 , 0x00 ,
V_532 , 0xff ,
V_533 , 0x00 ,
) ;
memset ( V_2 -> V_534 , 0 , sizeof( V_2 -> V_534 ) ) ;
memset ( V_2 -> V_535 , 0 , sizeof( V_2 -> V_535 ) ) ;
memset ( V_2 -> V_144 , 0 , sizeof( V_2 -> V_144 ) ) ;
memset ( V_2 -> V_145 , 0 , sizeof( V_2 -> V_145 ) ) ;
V_2 -> V_536 = 0 ;
V_2 -> V_98 = V_93 ;
F_10 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
F_15 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_363 , F_103 ( V_444 , V_365 ) ,
V_445 ,
V_446
) ;
F_110 ( V_2 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_521 ) ;
if ( V_534 & V_537 )
F_42 ( V_2 ) ;
if ( V_534 & V_372 ) {
T_2 V_538 = F_7 ( V_2 , V_539 ) ;
if ( ( V_538 & V_540 ) == V_541 ) {
F_102 ( V_2 ) ;
} else {
F_24 ( V_2 ,
V_360 , V_361
| V_542
| V_447 ,
V_366 , V_372
| V_370
| V_371
| V_369
) ;
}
}
if ( V_534 & V_368 )
F_106 ( V_2 ) ;
F_12 ( V_2 , V_521 , V_534 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_2 V_5 [ 17 ] ;
F_2 ( V_2 , V_543 , V_5 , F_45 ( V_5 ) ) ;
F_12 ( V_2 , V_44 , V_39 |
V_42 |
V_544 ) ;
F_7 ( V_2 , V_545 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_523 ) ;
if ( V_534 & V_55 )
if ( F_14 ( V_2 ) )
F_35 ( V_2 , F_27 ( V_59 ) ,
V_546 ) ;
if ( V_534 & V_56 )
F_112 ( V_2 ) ;
if ( V_534 & V_54 )
F_12 ( V_2 , V_45 , 0 ) ;
F_12 ( V_2 , V_523 , V_534 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
enum V_497 V_25 ;
V_25 = V_2 -> V_534 [ V_547 ] >= 0x30 ? V_26 : V_41 ;
if ( V_25 > V_2 -> V_25 )
F_109 ( V_2 , V_25 ) ;
F_104 ( V_2 ) ;
F_12 ( V_2 , V_84 , V_85
| V_147 | V_148 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_534 [ V_548 ] & V_328 ) {
F_34 ( V_2 , F_98 ( V_326 ) ,
V_327
| V_328 ) ;
if ( ! F_14 ( V_2 ) )
F_54 ( V_2 , false ) ;
F_31 ( V_2 , F_40 ) ;
} else {
F_34 ( V_2 , F_98 ( V_326 ) ,
V_327 ) ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
T_2 V_549 [ V_550 ] , V_551 [ V_552 ] ;
F_2 ( V_2 , V_553 , V_549 , V_550 ) ;
F_2 ( V_2 , V_554 , V_551 , V_552 ) ;
F_39 ( V_2 -> V_534 , V_549 , V_550 ) ;
F_39 ( V_2 -> V_535 , V_551 , V_552 ) ;
if ( V_2 -> V_534 [ V_555 ] & V_477 )
F_114 ( V_2 ) ;
if ( V_549 [ V_548 ] & V_328 )
F_115 ( V_2 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 )
return;
F_109 ( V_2 , V_499 ) ;
}
static void F_118 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 )
return;
F_34 ( V_2 , F_99 ( V_556 ) ,
V_557 | V_558 ) ;
F_37 ( V_2 , V_559 ) ;
F_31 ( V_2 , F_117 ) ;
}
static void F_119 ( struct V_560 * V_158 ,
enum V_173 V_167 )
{
F_68 ( & V_158 -> V_179 , V_561 ) ;
V_158 -> V_181 = 1 ;
V_158 -> V_562 [ 0 ] = F_65 ( V_167 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
T_2 V_5 [ 16 ] ;
F_12 ( V_2 , V_45 , V_563
| V_564 ) ;
F_119 ( ( void * ) V_5 ,
V_565 ) ;
F_8 ( V_2 , V_566 , V_5 , F_45 ( V_5 ) ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_2 V_567 [ V_568 ] ;
F_2 ( V_2 , V_569 , V_567 , V_568 ) ;
F_8 ( V_2 , V_569 , V_567 , V_568 ) ;
if ( V_567 [ V_570 ] & V_480 ) {
switch ( V_2 -> V_25 ) {
case V_26 :
F_57 ( V_2 , V_431 ) ;
F_31 ( V_2 , F_118 ) ;
break;
case V_499 :
F_54 ( V_2 , true ) ;
break;
default:
break;
}
}
if ( V_567 [ V_570 ] & V_60 )
F_120 ( V_2 ) ;
if ( V_567 [ V_570 ] & V_546 )
F_48 ( V_2 , 0 ) ;
}
static struct V_27 * F_122 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( F_19 ( & V_2 -> V_33 ) ) {
F_6 ( V_8 , L_16 ) ;
return NULL ;
}
return F_20 ( & V_2 -> V_33 , struct V_27 , V_29 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_27 * V_13 = F_122 ( V_2 ) ;
if ( ! V_13 )
return;
V_13 -> V_3 = F_7 ( V_2 , V_571 ) ;
V_2 -> V_30 = V_34 ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_27 * V_13 = F_122 ( V_2 ) ;
T_2 V_5 [ 2 ] ;
if ( ! V_13 )
return;
F_2 ( V_2 , V_572 , V_5 , 2 ) ;
switch ( V_5 [ 0 ] ) {
case V_573 :
V_13 -> V_3 = V_5 [ 1 ] ;
V_2 -> V_30 = V_34 ;
break;
default:
F_6 ( V_2 -> V_8 , L_17 ,
V_70 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_526 ) ;
if ( V_534 & ~ V_394 )
F_12 ( V_2 , V_526 , V_534 & ~ V_394 ) ;
if ( V_534 & V_394 ) {
T_2 V_574 = F_7 ( V_2 , V_192 ) ;
if ( ( V_574 ^ V_2 -> V_536 ) & V_575 ) {
F_12 ( V_2 , V_526 , V_394 ) ;
} else {
V_534 ^= V_575 ;
V_574 ^= V_575 ;
}
V_2 -> V_536 = V_574 ;
}
if ( V_534 & V_395 )
F_116 ( V_2 ) ;
if ( V_534 & V_398 )
F_121 ( V_2 ) ;
if ( V_534 & V_393 )
F_123 ( V_2 ) ;
if ( V_534 & V_396 )
F_124 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_524 ) ;
if ( V_534 & V_388 ) {
T_2 V_576 = F_7 ( V_2 , V_492 ) ;
V_576 &= V_494 | V_493 ;
if ( V_576 == ( V_494 | 0x02 ) ) {
F_24 ( V_2 ,
V_508 , 0 ,
V_525 , V_577
| V_578
) ;
}
}
F_12 ( V_2 , V_524 , V_534 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_527 ) ;
F_12 ( V_2 , V_527 , V_534 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_530 ) ;
F_12 ( V_2 , V_530 , V_534 ) ;
if ( V_534 & V_85 )
V_2 -> V_30 = V_34 ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_24 ( V_2 ,
V_355 , V_579 | V_580 ,
V_260 , V_259 ,
) ;
}
static void F_130 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_531 ) ;
if ( V_534 & V_234 ) {
T_2 V_576 = F_7 ( V_2 , V_356 ) ;
if ( V_576 & V_581 )
F_129 ( V_2 ) ;
}
F_12 ( V_2 , V_531 , V_534 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
T_2 V_582 [ 11 ] ;
F_12 ( V_2 , V_320 ,
V_321 |
V_583 ) ;
F_2 ( V_2 , V_584 , V_582 ,
F_45 ( V_582 ) ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_320 , V_321 ) ;
F_2 ( V_2 , V_584 , V_2 -> V_297 ,
F_45 ( V_2 -> V_297 ) ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_529 )
& ( V_580 | V_579 ) ;
F_12 ( V_2 , V_529 , V_534 ) ;
if ( V_534 & V_580 )
F_131 ( V_2 ) ;
if ( V_534 & V_579 )
F_132 ( V_2 ) ;
if ( V_534 & ( V_580 | V_579 ) )
F_100 ( V_2 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 )
return;
F_54 ( V_2 , false ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_125 ) ;
T_2 V_585 = F_7 ( V_2 , V_586 ) ;
if ( ( V_585 & V_587 ) == V_588 ) {
V_2 -> V_25 = V_499 ;
V_2 -> V_151 . V_161 = 0 ;
V_2 -> V_151 . V_160 = V_589 ;
F_64 ( V_2 , V_589 ) ;
F_54 ( V_2 , true ) ;
F_31 ( V_2 , F_134 ) ;
} else {
F_24 ( V_2 ,
V_590 , 0 ,
V_590 , V_591
) ;
}
F_12 ( V_2 , V_125 , V_534 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_487 ) ;
if ( V_534 & V_489 ) {
T_2 V_592 = F_7 ( V_2 , V_593 ) ;
if ( V_592 & V_594 )
F_62 ( V_2 ) ;
}
F_12 ( V_2 , V_487 , V_534 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
T_2 V_534 = F_7 ( V_2 , V_211 ) ;
if ( V_534 & V_212 ) {
F_12 ( V_2 , V_220 , 0 ) ;
if ( F_14 ( V_2 ) )
F_35 ( V_2 , F_27 ( V_59 ) ,
V_60 ) ;
else
F_48 ( V_2 , 0 ) ;
}
F_12 ( V_2 , V_211 , V_534 ) ;
}
static bool F_138 ( unsigned int V_595 , const T_2 * V_4 )
{
return 1 & ( V_4 [ V_595 / V_596 ] >> ( V_595 % V_596 ) ) ;
}
static T_6 F_139 ( int V_76 , void * V_11 )
{
static const struct {
int V_597 ;
void (* F_140)( struct V_1 * V_2 );
} V_598 [] = {
{ V_599 , F_111 } ,
{ V_600 , F_113 } ,
{ V_601 , F_126 } ,
{ V_602 , F_135 } ,
{ V_603 , F_125 } ,
{ V_604 , F_127 } ,
{ V_605 , F_136 } ,
{ V_606 , F_128 } ,
{ V_607 , F_137 } ,
{ V_608 , F_130 } ,
{ V_609 , F_133 } ,
} ;
struct V_1 * V_2 = V_11 ;
T_2 V_610 [ V_611 ] ;
int V_22 , V_3 ;
F_141 ( & V_2 -> V_612 ) ;
F_2 ( V_2 , V_613 , V_610 , F_45 ( V_610 ) ) ;
for ( V_22 = 0 ; V_22 < F_45 ( V_598 ) ; ++ V_22 )
if ( F_138 ( V_598 [ V_22 ] . V_597 , V_610 ) )
V_598 [ V_22 ] . F_140 ( V_2 ) ;
F_70 ( V_2 ) ;
F_18 ( V_2 ) ;
F_60 ( V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_8 , L_18 , V_3 ) ;
F_42 ( V_2 ) ;
}
F_142 ( & V_2 -> V_612 ) ;
return V_614 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_2 V_615 [ 5 ] ;
int V_3 ;
V_3 = F_77 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_19 , V_3 ) ;
return;
}
F_84 ( V_2 ) ;
F_2 ( V_2 , V_616 , V_615 , F_45 ( V_615 ) ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_20 , V_3 ) ;
return;
}
F_46 ( V_8 , L_21 , V_615 [ 1 ] , V_615 [ 0 ] ,
V_615 [ 3 ] , V_615 [ 2 ] , V_615 [ 4 ] ) ;
F_12 ( V_2 , V_221 ,
V_382 | V_383 | V_384 ) ;
F_75 ( V_2 ) ;
F_110 ( V_2 ) ;
F_24 ( V_2 ,
V_617 , V_618
| V_619 ,
V_620 , V_621 ,
V_221 , V_382 | V_383 | V_384 ,
) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_6 ( V_8 , L_20 , V_3 ) ;
return;
}
F_144 ( F_3 ( V_2 -> V_8 ) -> V_76 ) ;
}
static inline struct V_1 * F_145 ( struct V_622 * V_623 )
{
return F_146 ( V_623 , struct V_1 , V_623 ) ;
}
static bool F_147 ( struct V_622 * V_623 ,
const struct V_624 * V_25 ,
struct V_624 * V_625 )
{
struct V_1 * V_2 = F_145 ( V_623 ) ;
int V_626 ;
bool V_3 = true ;
F_141 ( & V_2 -> V_612 ) ;
V_626 = F_14 ( V_2 ) ? V_627 : V_628 ;
if ( V_626 > 3 * V_625 -> clock ) {
V_2 -> V_264 = 0 ;
goto V_214;
}
if ( ( V_2 -> V_144 [ V_411 ] & V_413 ) &&
V_626 > 2 * V_625 -> clock ) {
V_2 -> V_264 = 1 ;
goto V_214;
}
V_3 = false ;
V_214:
if ( V_3 ) {
T_2 V_629 = F_148 ( V_625 ) ;
if ( ! V_629 ) {
union V_294 V_295 ;
T_2 V_630 [] = { 0 , 95 , 94 , 93 , 98 } ;
F_149 (
& V_295 . V_631 . V_632 , V_625 ) ;
V_629 = V_295 . V_631 . V_632 . V_629 ;
if ( V_629 >= F_45 ( V_630 ) )
V_629 = 0 ;
V_629 = V_630 [ V_629 ] ;
}
V_2 -> V_311 = V_629 ;
V_2 -> V_343 = V_625 -> clock ;
}
F_142 ( & V_2 -> V_612 ) ;
return V_3 ;
}
static int F_150 ( struct V_9 * V_10 ,
const struct V_633 * V_167 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_151 ( V_8 , sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_8 = V_8 ;
F_152 ( & V_2 -> V_612 ) ;
F_153 ( & V_2 -> V_33 ) ;
V_2 -> V_238 = F_154 ( V_8 , L_22 ) ;
if ( F_155 ( V_2 -> V_238 ) ) {
F_6 ( V_8 , L_23 ) ;
return F_156 ( V_2 -> V_238 ) ;
}
if ( ! V_10 -> V_76 ) {
F_6 ( V_8 , L_24 ) ;
return - V_72 ;
}
F_157 ( V_10 -> V_76 , V_634 ) ;
V_3 = F_158 ( V_8 , V_10 -> V_76 , NULL ,
F_139 ,
V_635 | V_636 ,
L_25 , V_2 ) ;
if ( V_3 < 0 ) {
F_6 ( V_8 , L_26 ) ;
return V_3 ;
}
V_2 -> V_242 = F_159 ( V_8 , L_27 , V_637 ) ;
if ( F_155 ( V_2 -> V_242 ) ) {
F_6 ( V_8 , L_28 ) ;
return F_156 ( V_2 -> V_242 ) ;
}
V_2 -> V_241 [ 0 ] . V_638 = L_29 ;
V_2 -> V_241 [ 1 ] . V_638 = L_30 ;
V_3 = F_160 ( V_8 , 2 , V_2 -> V_241 ) ;
if ( V_3 )
return V_3 ;
F_161 ( V_10 , V_2 ) ;
V_2 -> V_623 . V_639 = & V_640 ;
V_2 -> V_623 . V_641 = V_8 -> V_641 ;
F_162 ( & V_2 -> V_623 ) ;
F_143 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_164 ( V_10 ) ;
F_165 ( F_3 ( V_2 -> V_8 ) -> V_76 ) ;
F_166 ( & V_2 -> V_623 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
