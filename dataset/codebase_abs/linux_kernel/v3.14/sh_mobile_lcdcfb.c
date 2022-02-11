static bool F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
}
return false ;
}
static int F_2 ( struct V_14 * V_15 )
{
return V_15 -> V_16 -> V_15 == V_17 ;
}
static void F_3 ( struct V_14 * V_15 ,
int V_1 , unsigned long V_18 )
{
F_4 ( V_18 , V_15 -> V_19 -> V_20 + V_15 -> V_21 [ V_1 ] ) ;
if ( F_1 ( V_1 ) )
F_4 ( V_18 , V_15 -> V_19 -> V_20 + V_15 -> V_21 [ V_1 ] +
V_22 ) ;
}
static void F_5 ( struct V_14 * V_15 ,
int V_1 , unsigned long V_18 )
{
F_4 ( V_18 , V_15 -> V_19 -> V_20 + V_15 -> V_21 [ V_1 ] +
V_23 ) ;
}
static unsigned long F_6 ( struct V_14 * V_15 ,
int V_1 )
{
return F_7 ( V_15 -> V_19 -> V_20 + V_15 -> V_21 [ V_1 ] ) ;
}
static void F_8 ( struct V_24 * V_25 ,
int V_26 , unsigned long V_18 )
{
F_4 ( V_18 , V_25 -> V_27 -> V_19 -> V_20 + V_26 ) ;
F_4 ( V_18 , V_25 -> V_27 -> V_19 -> V_20 + V_26 + V_22 ) ;
}
static void F_9 ( struct V_28 * V_29 ,
unsigned long V_21 , unsigned long V_18 )
{
F_4 ( V_18 , V_29 -> V_20 + V_21 ) ;
}
static unsigned long F_10 ( struct V_28 * V_29 ,
unsigned long V_21 )
{
return F_7 ( V_29 -> V_20 + V_21 ) ;
}
static void F_11 ( struct V_28 * V_29 ,
unsigned long V_21 ,
unsigned long V_30 , unsigned long V_31 )
{
while ( ( F_10 ( V_29 , V_21 ) & V_30 ) != V_31 )
F_12 () ;
}
static void F_13 ( struct V_28 * V_29 )
{
if ( F_14 ( & V_29 -> V_32 ) ) {
if ( V_29 -> V_33 )
F_15 ( V_29 -> V_33 ) ;
F_16 ( V_29 -> V_34 ) ;
if ( V_29 -> V_35 && V_29 -> V_35 -> V_36 )
F_16 ( & V_29 -> V_35 -> V_36 -> V_34 ) ;
}
}
static void F_17 ( struct V_28 * V_29 )
{
if ( F_18 ( 1 , & V_29 -> V_32 ) == - 1 ) {
if ( V_29 -> V_35 && V_29 -> V_35 -> V_36 )
F_19 ( & V_29 -> V_35 -> V_36 -> V_34 ) ;
F_20 ( V_29 -> V_34 ) ;
if ( V_29 -> V_33 )
F_21 ( V_29 -> V_33 ) ;
}
}
static int F_22 ( struct V_28 * V_29 ,
int V_37 )
{
struct V_38 * V_38 ;
char * V_39 ;
switch ( V_37 ) {
case V_40 :
V_39 = L_1 ;
V_29 -> V_41 = V_42 ;
break;
case V_43 :
V_39 = L_2 ;
V_29 -> V_41 = V_44 ;
break;
case V_45 :
V_39 = NULL ;
V_29 -> V_41 = V_46 ;
break;
default:
return - V_47 ;
}
if ( V_39 == NULL )
return 0 ;
V_38 = F_23 ( V_29 -> V_34 , V_39 ) ;
if ( F_24 ( V_38 ) ) {
F_25 ( V_29 -> V_34 , L_3 , V_39 ) ;
return F_26 ( V_38 ) ;
}
V_29 -> V_33 = V_38 ;
return 0 ;
}
static void F_27 ( void * V_48 , unsigned long V_18 )
{
struct V_14 * V_49 = V_48 ;
F_9 ( V_49 -> V_19 , V_50 , V_18 | V_51 ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
F_9 ( V_49 -> V_19 , V_54 , V_55 |
( F_2 ( V_49 ) ? 2 : 0 ) ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
}
static void F_28 ( void * V_48 , unsigned long V_18 )
{
struct V_14 * V_49 = V_48 ;
F_9 ( V_49 -> V_19 , V_50 , V_18 | V_51 | V_56 ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
F_9 ( V_49 -> V_19 , V_54 , V_55 |
( F_2 ( V_49 ) ? 2 : 0 ) ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
}
static unsigned long F_29 ( void * V_48 )
{
struct V_14 * V_49 = V_48 ;
F_9 ( V_49 -> V_19 , V_57 , V_58 ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
F_9 ( V_49 -> V_19 , V_59 , V_60 |
( F_2 ( V_49 ) ? 2 : 0 ) ) ;
F_30 ( 1 ) ;
F_11 ( V_49 -> V_19 , V_52 , V_53 , 0 ) ;
return F_10 ( V_49 -> V_19 , V_57 ) & V_61 ;
}
static int F_31 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
unsigned int V_67 = V_49 -> V_68 >> V_69 ;
struct V_70 * V_70 ;
int V_71 = 0 ;
F_32 ( V_49 -> V_72 , V_67 ) ;
F_33 (page, pagelist, lru)
F_34 ( & V_49 -> V_72 [ V_71 ++ ] , V_70 , V_73 , 0 ) ;
return V_71 ;
}
static void F_35 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
const struct V_74 * V_75 = & V_49 -> V_16 -> V_76 ;
F_13 ( V_49 -> V_19 ) ;
if ( ! F_36 ( V_65 ) ) {
unsigned int V_71 = F_31 ( V_63 , V_65 ) ;
F_37 ( V_49 -> V_19 -> V_34 , V_49 -> V_72 , V_71 , V_77 ) ;
if ( V_75 -> V_78 )
V_75 -> V_78 ( V_49 , & V_79 ) ;
F_3 ( V_49 , V_80 , V_81 ) ;
F_38 ( V_49 -> V_19 -> V_34 , V_49 -> V_72 , V_71 ,
V_77 ) ;
} else {
if ( V_75 -> V_78 )
V_75 -> V_78 ( V_49 , & V_79 ) ;
F_3 ( V_49 , V_80 , V_81 ) ;
}
}
static void F_39 ( struct V_62 * V_63 )
{
struct V_82 * V_83 = V_63 -> V_83 ;
if ( V_83 )
F_40 ( & V_63 -> V_84 , V_83 -> V_85 ) ;
}
static void F_41 ( struct V_14 * V_49 )
{
const struct V_74 * V_75 = & V_49 -> V_16 -> V_76 ;
if ( V_49 -> V_86 ) {
int V_87 ;
V_87 = V_49 -> V_86 -> V_88 -> V_89 ( V_49 -> V_86 ) ;
if ( V_87 < 0 )
return;
if ( V_87 == V_90 )
V_49 -> V_63 -> V_91 = V_92 ;
}
if ( V_75 -> V_89 )
V_75 -> V_89 () ;
}
static void F_42 ( struct V_14 * V_49 )
{
const struct V_74 * V_75 = & V_49 -> V_16 -> V_76 ;
if ( V_75 -> V_93 )
V_75 -> V_93 () ;
if ( V_49 -> V_86 )
V_49 -> V_86 -> V_88 -> V_93 ( V_49 -> V_86 ) ;
}
static bool
F_43 ( struct V_14 * V_49 ,
const struct V_94 * V_95 )
{
F_44 ( V_49 -> V_63 -> V_34 , L_4 ,
V_49 -> V_96 . V_97 . V_98 , V_49 -> V_96 . V_97 . V_99 ,
V_95 -> V_98 , V_95 -> V_99 ) ;
if ( F_45 ( & V_49 -> V_96 . V_97 , V_95 ) )
return false ;
F_44 ( V_49 -> V_63 -> V_34 , L_5 ,
V_49 -> V_96 . V_97 . V_99 , V_95 -> V_99 ) ;
V_49 -> V_96 . V_97 = * V_95 ;
return true ;
}
static int F_46 ( struct V_14 * V_49 ,
enum V_100 V_101 ,
const struct V_94 * V_97 ,
const struct V_102 * V_103 )
{
struct V_62 * V_63 = V_49 -> V_63 ;
struct V_104 V_105 ;
int V_87 = 0 ;
switch ( V_101 ) {
case V_106 :
F_47 () ;
if ( F_48 ( V_63 ) ) {
V_49 -> V_96 . V_107 = V_103 -> V_108 * 10 ;
V_49 -> V_96 . V_109 = V_103 -> V_110 * 10 ;
if ( ! F_43 ( V_49 , V_97 ) &&
V_63 -> V_91 == V_111 ) {
V_63 -> V_105 . V_107 = V_49 -> V_96 . V_107 ;
V_63 -> V_105 . V_109 = V_49 -> V_96 . V_109 ;
F_41 ( V_49 ) ;
} else {
F_49 ( V_63 , 0 ) ;
}
F_50 ( V_63 ) ;
}
F_51 () ;
break;
case V_112 :
F_47 () ;
if ( F_48 ( V_63 ) ) {
F_49 ( V_63 , 1 ) ;
F_50 ( V_63 ) ;
}
F_51 () ;
break;
case V_113 :
F_52 ( & V_105 , V_97 ) ;
V_105 . V_114 = V_63 -> V_105 . V_114 ;
V_105 . V_115 = V_63 -> V_105 . V_115 ;
V_87 = F_53 ( & V_105 , V_63 ) ;
break;
}
return V_87 ;
}
static const struct V_116 *
F_54 ( T_1 V_117 )
{
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < F_55 ( V_119 ) ; ++ V_118 ) {
if ( V_119 [ V_118 ] . V_117 == V_117 )
return & V_119 [ V_118 ] ;
}
return NULL ;
}
static int F_56 ( const struct V_104 * V_105 )
{
if ( V_105 -> V_115 > 1 )
return V_105 -> V_115 ;
switch ( V_105 -> V_114 ) {
case 16 :
return V_120 ;
case 24 :
return V_121 ;
case 32 :
return V_122 ;
default:
return 0 ;
}
}
static int F_57 ( const struct V_104 * V_105 )
{
return V_105 -> V_115 > 1 ;
}
static T_2 F_58 ( int V_123 , void * V_18 )
{
struct V_28 * V_29 = V_18 ;
struct V_14 * V_49 ;
unsigned long V_124 ;
int V_125 ;
int V_126 ;
V_124 = F_10 ( V_29 , V_127 ) ;
F_9 ( V_29 , V_127 , ( V_124 ^ V_128 ) & ~ V_129 ) ;
V_125 = ( F_10 ( V_29 , V_52 ) & V_130 ) ? 1 : 0 ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
if ( V_124 & V_132 ) {
if ( V_125 == F_2 ( V_49 ) ) {
V_49 -> V_133 = 1 ;
F_59 ( & V_49 -> V_134 ) ;
F_17 ( V_29 ) ;
}
}
if ( V_124 & V_135 )
F_60 ( & V_49 -> V_136 ) ;
}
return V_137 ;
}
static int F_61 ( struct V_14 * V_49 )
{
unsigned long V_124 ;
int V_87 ;
V_124 = F_10 ( V_49 -> V_19 , V_127 ) ;
V_124 |= V_129 | V_128 ;
F_9 ( V_49 -> V_19 , V_127 , V_124 ) ;
V_87 = F_62 ( & V_49 -> V_136 ,
F_63 ( 100 ) ) ;
if ( ! V_87 )
return - V_138 ;
return 0 ;
}
static void F_64 ( struct V_28 * V_29 ,
int V_139 )
{
unsigned long V_140 = F_10 ( V_29 , V_141 ) ;
int V_126 ;
if ( V_139 )
F_9 ( V_29 , V_141 , V_140 | V_142 ) ;
else
F_9 ( V_29 , V_141 , V_140 & ~ V_142 ) ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ )
if ( F_10 ( V_29 , V_141 ) & V_29 -> V_49 [ V_126 ] . V_131 )
while ( 1 ) {
V_140 = F_6 ( & V_29 -> V_49 [ V_126 ] , V_143 )
& V_144 ;
if ( V_139 && V_140 == V_144 )
break;
if ( ! V_139 && V_140 == 0 )
break;
F_12 () ;
}
if ( ! V_139 )
F_9 ( V_29 , V_145 , 1 ) ;
}
static void F_65 ( struct V_14 * V_49 )
{
const struct V_104 * V_105 = & V_49 -> V_63 -> V_105 ;
const struct V_94 * V_97 = & V_49 -> V_96 . V_97 ;
unsigned long V_146 , V_147 , V_148 ;
T_1 V_140 ;
V_140 = V_49 -> V_149 ;
V_140 |= ( V_105 -> V_150 & V_151 ) ? 0 : V_152 ;
V_140 |= ( V_105 -> V_150 & V_153 ) ? 0 : V_154 ;
V_140 |= ( V_49 -> V_16 -> V_155 & V_156 ) ? V_157 : 0 ;
V_140 |= ( V_49 -> V_16 -> V_155 & V_158 ) ? V_159 : 0 ;
V_140 |= ( V_49 -> V_16 -> V_155 & V_160 ) ? V_161 : 0 ;
V_140 |= ( V_49 -> V_16 -> V_155 & V_162 ) ? V_163 : 0 ;
V_140 |= ( V_49 -> V_16 -> V_155 & V_164 ) ? V_165 : 0 ;
F_3 ( V_49 , V_2 , V_140 ) ;
F_3 ( V_49 , V_3 , V_49 -> V_16 -> V_166 . V_167 ) ;
F_3 ( V_49 , V_4 , V_49 -> V_16 -> V_166 . V_168 ) ;
V_146 = V_97 -> V_98 + V_97 -> V_169 + V_97 -> V_170
+ V_97 -> V_171 ;
V_140 = V_146 / 8 ;
V_140 |= ( F_66 ( V_97 -> V_98 , V_49 -> V_98 ) / 8 ) << 16 ;
F_3 ( V_49 , V_10 , V_140 ) ;
V_147 = V_97 -> V_98 + V_97 -> V_171 ;
V_140 = V_147 / 8 ;
V_140 |= ( V_97 -> V_169 / 8 ) << 16 ;
F_3 ( V_49 , V_11 , V_140 ) ;
V_140 = V_97 -> V_99 + V_97 -> V_172 + V_97 -> V_173
+ V_97 -> V_174 ;
V_140 |= F_66 ( V_97 -> V_99 , V_49 -> V_99 ) << 16 ;
F_3 ( V_49 , V_12 , V_140 ) ;
V_140 = V_97 -> V_99 + V_97 -> V_174 ;
V_140 |= V_97 -> V_172 << 16 ;
F_3 ( V_49 , V_13 , V_140 ) ;
V_148 = V_97 -> V_98 + V_97 -> V_169 + V_97 -> V_170
+ V_97 -> V_171 ;
V_140 = ( ( V_97 -> V_98 & 7 ) << 24 ) | ( ( V_148 & 7 ) << 16 )
| ( ( V_97 -> V_169 & 7 ) << 8 ) | ( V_147 & 7 ) ;
F_3 ( V_49 , V_175 , V_140 ) ;
F_5 ( V_49 , V_175 , V_140 ) ;
}
static void F_67 ( struct V_24 * V_25 )
{
T_1 V_176 = 0 ;
if ( ! V_25 -> V_131 ) {
F_9 ( V_25 -> V_27 -> V_19 , V_177 , F_68 ( V_25 -> V_178 ) ) ;
F_8 ( V_25 , F_69 ( V_25 -> V_178 ) , 0 ) ;
F_9 ( V_25 -> V_27 -> V_19 , V_177 ,
F_70 ( V_25 -> V_178 ) | F_71 ( V_25 -> V_178 ) ) ;
return;
}
V_25 -> V_179 = V_25 -> V_180 ;
V_25 -> V_181 = V_25 -> V_180
+ V_25 -> V_182 * V_25 -> V_183 ;
switch ( V_25 -> V_97 ) {
case V_184 :
V_176 = V_185 | ( V_25 -> V_186 << V_187 ) ;
break;
case V_188 :
V_176 = V_185 | V_189
| ( V_25 -> V_190 << V_191 ) ;
break;
}
switch ( V_25 -> V_176 -> V_117 ) {
case V_120 :
case V_192 :
case V_193 :
case V_194 :
V_176 |= V_195 | V_196 ;
break;
case V_121 :
case V_197 :
case V_198 :
case V_199 :
V_176 |= V_195 | V_196 | V_200 ;
break;
case V_122 :
default:
V_176 |= V_195 ;
break;
}
switch ( V_25 -> V_176 -> V_117 ) {
case V_120 :
V_176 |= V_201 | V_202 | V_203 ;
break;
case V_121 :
V_176 |= V_201 | V_202 | V_204 ;
break;
case V_122 :
V_176 |= V_205 | V_202 | V_206 ;
break;
case V_197 :
case V_192 :
V_176 |= V_201 | V_207 ;
break;
case V_198 :
case V_193 :
V_176 |= V_201 | V_208 ;
break;
case V_199 :
case V_194 :
V_176 |= V_201 | V_209 ;
break;
}
F_9 ( V_25 -> V_27 -> V_19 , V_177 , F_68 ( V_25 -> V_178 ) ) ;
F_8 ( V_25 , F_69 ( V_25 -> V_178 ) , V_176 ) ;
F_8 ( V_25 , F_72 ( V_25 -> V_178 ) ,
( V_25 -> V_99 << V_210 ) |
( V_25 -> V_98 << V_211 ) ) ;
F_8 ( V_25 , F_73 ( V_25 -> V_178 ) ,
( V_25 -> V_212 << V_213 ) |
( V_25 -> V_214 << V_215 ) ) ;
F_8 ( V_25 , F_74 ( V_25 -> V_178 ) ,
V_25 -> V_216 << V_217 ) ;
F_8 ( V_25 , F_75 ( V_25 -> V_178 ) , V_25 -> V_179 ) ;
F_8 ( V_25 , F_76 ( V_25 -> V_178 ) , V_25 -> V_181 ) ;
F_9 ( V_25 -> V_27 -> V_19 , V_177 ,
F_70 ( V_25 -> V_178 ) | F_71 ( V_25 -> V_178 ) ) ;
}
static void F_77 ( struct V_28 * V_29 )
{
struct V_14 * V_49 ;
unsigned long V_140 ;
int V_126 , V_218 ;
F_9 ( V_29 , V_141 , V_29 -> V_49 [ 0 ] . V_131 | V_29 -> V_49 [ 1 ] . V_131 ) ;
F_64 ( V_29 , 0 ) ;
F_9 ( V_29 , V_127 , 0 ) ;
V_140 = V_29 -> V_41 ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
F_3 ( V_49 , V_143 , 0 ) ;
V_218 = V_49 -> V_16 -> V_219 ;
if ( ! V_218 )
continue;
F_3 ( V_49 , V_220 , 0 ) ;
F_3 ( V_49 , V_221 , ( 1 << ( V_218 / 2 ) ) - 1 ) ;
if ( V_218 == 1 )
V_218 = V_222 ;
V_140 |= V_218 << ( F_2 ( V_49 ) ? 8 : 0 ) ;
}
F_9 ( V_29 , V_223 , V_140 ) ;
F_9 ( V_29 , V_145 , 0 ) ;
F_11 ( V_29 , V_145 , ~ 0 , 0 ) ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
F_65 ( V_49 ) ;
V_140 = V_49 -> V_176 -> V_224 ;
if ( V_49 -> V_176 -> V_225 ) {
switch ( V_49 -> V_226 ) {
case V_227 :
V_140 |= V_228 ;
break;
case V_229 :
V_140 |= V_230 ;
break;
}
}
F_3 ( V_49 , V_5 , V_140 ) ;
F_3 ( V_49 , V_9 , V_49 -> V_231 ) ;
F_3 ( V_49 , V_7 , V_49 -> V_179 ) ;
if ( V_49 -> V_176 -> V_225 )
F_3 ( V_49 , V_8 , V_49 -> V_181 ) ;
if ( V_49 -> V_149 & V_232 &&
V_49 -> V_16 -> V_166 . V_233 ) {
F_3 ( V_49 , V_6 , V_234 ) ;
F_9 ( V_29 , V_127 , V_235 ) ;
} else {
F_3 ( V_49 , V_6 , 0 ) ;
}
}
switch ( V_29 -> V_49 [ 0 ] . V_176 -> V_117 ) {
case V_120 :
case V_192 :
case V_193 :
case V_194 :
V_140 = V_236 | V_237 ;
break;
case V_121 :
case V_197 :
case V_198 :
case V_199 :
V_140 = V_236 | V_237 | V_238 ;
break;
case V_122 :
default:
V_140 = V_236 ;
break;
}
F_9 ( V_29 , V_239 , V_140 ) ;
F_9 ( V_29 , V_240 , V_241 ) ;
F_64 ( V_29 , 1 ) ;
V_29 -> V_242 = 1 ;
}
static int F_78 ( struct V_28 * V_29 )
{
struct V_243 * V_244 = V_29 -> V_35 ;
struct V_14 * V_49 ;
unsigned long V_140 ;
int V_87 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
if ( V_29 -> V_49 [ V_126 ] . V_131 )
F_13 ( V_29 ) ;
}
F_9 ( V_29 , V_141 , F_10 ( V_29 , V_141 ) | V_245 ) ;
F_11 ( V_29 , V_141 , V_245 , 0 ) ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
const struct V_74 * V_75 ;
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
V_75 = & V_49 -> V_16 -> V_76 ;
if ( V_75 -> V_246 ) {
V_87 = V_75 -> V_246 ( V_49 , & V_79 ) ;
if ( V_87 )
return V_87 ;
}
}
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
int V_247 ;
void * V_248 ;
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
V_49 -> V_179 = V_49 -> V_180 ;
V_49 -> V_181 = V_49 -> V_180
+ V_49 -> V_182 * V_49 -> V_183 ;
V_49 -> V_231 = V_49 -> V_216 ;
if ( V_244 == NULL || V_49 -> V_16 -> V_249 == NULL )
continue;
if ( V_49 -> V_248 ) {
F_79 ( V_244 , V_49 -> V_248 ) ;
V_49 -> V_248 = NULL ;
}
switch ( V_49 -> V_176 -> V_117 ) {
case V_197 :
case V_192 :
case V_198 :
case V_193 :
V_247 = V_250 ;
break;
case V_199 :
case V_194 :
V_247 = V_251 ;
break;
case V_120 :
case V_121 :
case V_122 :
default:
V_247 = V_252 ;
break;
}
V_248 = F_80 ( V_244 , V_49 -> V_16 -> V_249 ,
V_49 -> V_216 , V_49 -> V_99 , V_247 ,
& V_49 -> V_231 ) ;
if ( ! F_24 ( V_248 ) ) {
F_81 ( V_244 , V_248 ,
V_49 -> V_179 , V_49 -> V_181 ,
& V_49 -> V_179 , & V_49 -> V_181 ) ;
V_49 -> V_248 = V_248 ;
}
}
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_253 ) ; ++ V_126 ) {
struct V_24 * V_25 = & V_29 -> V_253 [ V_126 ] ;
F_67 ( V_25 ) ;
}
F_77 ( V_29 ) ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
V_140 = V_49 -> V_16 -> V_166 . V_233 ;
if ( V_49 -> V_149 & V_232 && V_140 ) {
V_49 -> V_254 . V_255 = F_35 ;
V_49 -> V_254 . V_85 = F_63 ( V_140 ) ;
V_49 -> V_63 -> V_83 = & V_49 -> V_254 ;
F_82 ( V_49 -> V_63 ) ;
}
F_41 ( V_49 ) ;
if ( V_49 -> V_256 ) {
V_49 -> V_256 -> V_257 . V_258 = V_259 ;
F_83 ( V_49 -> V_256 ) ;
}
}
return 0 ;
}
static void F_84 ( struct V_28 * V_29 )
{
struct V_14 * V_49 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ ) {
V_49 = & V_29 -> V_49 [ V_126 ] ;
if ( ! V_49 -> V_131 )
continue;
if ( V_49 -> V_63 && V_49 -> V_63 -> V_83 ) {
V_49 -> V_133 = 0 ;
F_40 ( & V_49 -> V_63 -> V_84 , 0 ) ;
F_85 ( V_49 -> V_134 , V_49 -> V_133 ) ;
F_86 ( V_49 -> V_63 ) ;
V_49 -> V_63 -> V_83 = NULL ;
F_13 ( V_29 ) ;
}
if ( V_49 -> V_256 ) {
V_49 -> V_256 -> V_257 . V_258 = V_260 ;
F_83 ( V_49 -> V_256 ) ;
}
F_42 ( V_49 ) ;
if ( V_49 -> V_248 ) {
F_79 ( V_29 -> V_35 , V_49 -> V_248 ) ;
V_49 -> V_248 = NULL ;
}
}
if ( V_29 -> V_242 ) {
F_64 ( V_29 , 0 ) ;
V_29 -> V_242 = 0 ;
}
for ( V_126 = 0 ; V_126 < F_55 ( V_29 -> V_49 ) ; V_126 ++ )
if ( V_29 -> V_49 [ V_126 ] . V_131 )
F_17 ( V_29 ) ;
}
static int F_87 ( struct V_104 * V_105 ,
struct V_62 * V_63 )
{
if ( V_105 -> V_98 > V_261 || V_105 -> V_99 > V_262 )
return - V_47 ;
if ( V_105 -> V_182 < V_105 -> V_98 )
V_105 -> V_182 = V_105 -> V_98 ;
if ( V_105 -> V_183 < V_105 -> V_99 )
V_105 -> V_183 = V_105 -> V_99 ;
if ( F_57 ( V_105 ) ) {
const struct V_116 * V_176 ;
V_176 = F_54 ( V_105 -> V_115 ) ;
if ( V_176 == NULL )
return - V_47 ;
V_105 -> V_114 = V_176 -> V_263 ;
if ( ! V_176 -> V_225 )
V_105 -> V_226 = V_264 ;
else if ( V_105 -> V_226 != V_227 )
V_105 -> V_226 = V_229 ;
} else {
if ( V_105 -> V_114 <= 16 ) {
V_105 -> V_114 = 16 ;
V_105 -> V_265 . V_266 = 11 ;
V_105 -> V_265 . V_267 = 5 ;
V_105 -> V_268 . V_266 = 5 ;
V_105 -> V_268 . V_267 = 6 ;
V_105 -> V_269 . V_266 = 0 ;
V_105 -> V_269 . V_267 = 5 ;
V_105 -> V_270 . V_266 = 0 ;
V_105 -> V_270 . V_267 = 0 ;
} else if ( V_105 -> V_114 <= 24 ) {
V_105 -> V_114 = 24 ;
V_105 -> V_265 . V_266 = 16 ;
V_105 -> V_265 . V_267 = 8 ;
V_105 -> V_268 . V_266 = 8 ;
V_105 -> V_268 . V_267 = 8 ;
V_105 -> V_269 . V_266 = 0 ;
V_105 -> V_269 . V_267 = 8 ;
V_105 -> V_270 . V_266 = 0 ;
V_105 -> V_270 . V_267 = 0 ;
} else if ( V_105 -> V_114 <= 32 ) {
V_105 -> V_114 = 32 ;
V_105 -> V_265 . V_266 = 16 ;
V_105 -> V_265 . V_267 = 8 ;
V_105 -> V_268 . V_266 = 8 ;
V_105 -> V_268 . V_267 = 8 ;
V_105 -> V_269 . V_266 = 0 ;
V_105 -> V_269 . V_267 = 8 ;
V_105 -> V_270 . V_266 = 24 ;
V_105 -> V_270 . V_267 = 8 ;
} else
return - V_47 ;
V_105 -> V_265 . V_271 = 0 ;
V_105 -> V_268 . V_271 = 0 ;
V_105 -> V_269 . V_271 = 0 ;
V_105 -> V_270 . V_271 = 0 ;
}
if ( V_105 -> V_182 * V_105 -> V_183 * V_105 -> V_114 / 8 >
V_63 -> V_272 . V_273 )
return - V_47 ;
return 0 ;
}
static T_3
F_88 ( struct V_274 * V_34 , struct V_275 * V_276 , char * V_277 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
return F_90 ( V_277 , V_73 , L_6 , V_25 -> V_186 ) ;
}
static T_3
F_91 ( struct V_274 * V_34 , struct V_275 * V_276 ,
const char * V_277 , T_4 V_278 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
unsigned int V_186 ;
char * V_279 ;
V_186 = F_92 ( V_277 , & V_279 , 10 ) ;
if ( isspace ( * V_279 ) )
V_279 ++ ;
if ( V_279 - V_277 != V_278 )
return - V_47 ;
if ( V_186 > 255 )
return - V_47 ;
if ( V_25 -> V_186 != V_186 ) {
V_25 -> V_186 = V_186 ;
if ( V_25 -> V_97 == V_184 && V_25 -> V_131 )
F_67 ( V_25 ) ;
}
return V_278 ;
}
static T_3
F_93 ( struct V_274 * V_34 , struct V_275 * V_276 , char * V_277 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
return F_90 ( V_277 , V_73 , L_6 , V_25 -> V_97 ) ;
}
static T_3
F_94 ( struct V_274 * V_34 , struct V_275 * V_276 ,
const char * V_277 , T_4 V_278 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
unsigned int V_97 ;
char * V_279 ;
V_97 = F_92 ( V_277 , & V_279 , 10 ) ;
if ( isspace ( * V_279 ) )
V_279 ++ ;
if ( V_279 - V_277 != V_278 )
return - V_47 ;
if ( V_97 != V_184 && V_97 != V_188 )
return - V_47 ;
if ( V_25 -> V_97 != V_97 ) {
V_25 -> V_97 = V_97 ;
if ( V_25 -> V_131 )
F_67 ( V_25 ) ;
}
return V_278 ;
}
static T_3
F_95 ( struct V_274 * V_34 , struct V_275 * V_276 ,
char * V_277 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
return F_90 ( V_277 , V_73 , L_7 , V_25 -> V_214 , V_25 -> V_212 ) ;
}
static T_3
F_96 ( struct V_274 * V_34 , struct V_275 * V_276 ,
const char * V_277 , T_4 V_278 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
char * V_279 ;
int V_214 ;
int V_212 ;
V_214 = F_97 ( V_277 , & V_279 , 10 ) ;
if ( * V_279 != ',' )
return - V_47 ;
V_212 = F_97 ( V_279 + 1 , & V_279 , 10 ) ;
if ( isspace ( * V_279 ) )
V_279 ++ ;
if ( V_279 - V_277 != V_278 )
return - V_47 ;
if ( V_25 -> V_214 != V_214 || V_25 -> V_212 != V_212 ) {
V_25 -> V_214 = V_214 ;
V_25 -> V_212 = V_212 ;
if ( V_25 -> V_131 )
F_67 ( V_25 ) ;
}
return V_278 ;
}
static T_3
F_98 ( struct V_274 * V_34 , struct V_275 * V_276 , char * V_277 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
return F_90 ( V_277 , V_73 , L_6 , V_25 -> V_190 ) ;
}
static T_3
F_99 ( struct V_274 * V_34 , struct V_275 * V_276 ,
const char * V_277 , T_4 V_278 )
{
struct V_62 * V_63 = F_89 ( V_34 ) ;
struct V_24 * V_25 = V_63 -> V_66 ;
unsigned int V_190 ;
char * V_279 ;
V_190 = ! ! F_92 ( V_277 , & V_279 , 10 ) ;
if ( isspace ( * V_279 ) )
V_279 ++ ;
if ( V_279 - V_277 != V_278 )
return - V_47 ;
if ( V_190 > 255 )
return - V_47 ;
if ( V_25 -> V_190 != V_190 ) {
V_25 -> V_190 = V_190 ;
if ( V_25 -> V_97 == V_188 && V_25 -> V_131 )
F_67 ( V_25 ) ;
}
return V_278 ;
}
static int F_100 ( struct V_104 * V_105 ,
struct V_62 * V_63 )
{
struct V_24 * V_25 = V_63 -> V_66 ;
unsigned long V_179 ;
unsigned long V_181 ;
unsigned long V_280 ;
unsigned long V_281 ;
if ( ! V_25 -> V_176 -> V_225 ) {
V_280 = ( V_105 -> V_282 * V_25 -> V_182 + V_105 -> V_283 )
* V_25 -> V_176 -> V_263 / 8 ;
V_281 = 0 ;
} else {
unsigned int V_284 = V_25 -> V_176 -> V_263 < 24 ? 2 : 1 ;
unsigned int V_285 = V_25 -> V_176 -> V_263 < 16 ? 2 : 1 ;
V_280 = V_105 -> V_282 * V_25 -> V_182 + V_105 -> V_283 ;
V_281 = V_105 -> V_282 / V_285 * V_25 -> V_182 * 2 / V_284
+ V_105 -> V_283 * 2 / V_284 ;
}
if ( V_280 == V_25 -> V_286 )
return 0 ;
V_179 = V_25 -> V_180 + V_280 ;
V_181 = V_25 -> V_180 + V_25 -> V_182 * V_25 -> V_183
+ V_281 ;
V_25 -> V_179 = V_179 ;
V_25 -> V_181 = V_181 ;
V_25 -> V_286 = V_280 ;
F_9 ( V_25 -> V_27 -> V_19 , V_177 , F_68 ( V_25 -> V_178 ) ) ;
F_8 ( V_25 , F_75 ( V_25 -> V_178 ) , V_25 -> V_179 ) ;
F_8 ( V_25 , F_76 ( V_25 -> V_178 ) , V_25 -> V_181 ) ;
F_9 ( V_25 -> V_27 -> V_19 , V_177 ,
F_70 ( V_25 -> V_178 ) | F_71 ( V_25 -> V_178 ) ) ;
return 0 ;
}
static int F_101 ( struct V_62 * V_63 , unsigned int V_287 ,
unsigned long V_288 )
{
struct V_24 * V_25 = V_63 -> V_66 ;
switch ( V_287 ) {
case V_289 :
return F_61 ( V_25 -> V_27 ) ;
default:
return - V_290 ;
}
}
static int F_102 ( struct V_104 * V_105 ,
struct V_62 * V_63 )
{
return F_87 ( V_105 , V_63 ) ;
}
static int F_103 ( struct V_62 * V_63 )
{
struct V_24 * V_25 = V_63 -> V_66 ;
V_25 -> V_176 =
F_54 ( F_56 ( & V_63 -> V_105 ) ) ;
V_25 -> V_98 = V_63 -> V_105 . V_98 ;
V_25 -> V_182 = V_63 -> V_105 . V_182 ;
V_25 -> V_99 = V_63 -> V_105 . V_99 ;
V_25 -> V_183 = V_63 -> V_105 . V_183 ;
if ( V_25 -> V_176 -> V_225 )
V_25 -> V_216 = V_63 -> V_105 . V_182 ;
else
V_25 -> V_216 = V_63 -> V_105 . V_182 * V_25 -> V_176 -> V_263 / 8 ;
F_67 ( V_25 ) ;
V_63 -> V_272 . V_291 = V_25 -> V_216 ;
if ( F_57 ( & V_63 -> V_105 ) ) {
V_63 -> V_272 . type = V_292 ;
V_63 -> V_272 . V_293 = V_294 ;
} else {
V_63 -> V_272 . type = V_295 ;
V_63 -> V_272 . V_293 = V_296 ;
}
return 0 ;
}
static int F_104 ( int V_297 , struct V_62 * V_63 )
{
struct V_24 * V_25 = V_63 -> V_66 ;
V_25 -> V_131 = ! V_297 ;
F_67 ( V_25 ) ;
return 1 ;
}
static int
F_105 ( struct V_62 * V_63 , struct V_298 * V_299 )
{
struct V_24 * V_25 = V_63 -> V_66 ;
return F_106 ( V_25 -> V_27 -> V_19 -> V_34 , V_299 , V_25 -> V_300 ,
V_25 -> V_180 , V_25 -> V_68 ) ;
}
static void
F_107 ( struct V_24 * V_25 )
{
struct V_62 * V_63 = V_25 -> V_63 ;
if ( V_63 == NULL || V_63 -> V_34 == NULL )
return;
F_108 ( V_25 -> V_63 ) ;
}
static int
F_109 ( struct V_24 * V_25 )
{
struct V_28 * V_19 = V_25 -> V_27 -> V_19 ;
struct V_62 * V_63 = V_25 -> V_63 ;
unsigned int V_118 ;
int V_87 ;
if ( V_63 == NULL )
return 0 ;
V_87 = F_110 ( V_63 ) ;
if ( V_87 < 0 )
return V_87 ;
F_111 ( V_19 -> V_34 , L_8 ,
F_112 ( V_19 -> V_34 ) , V_25 -> V_178 , V_63 -> V_105 . V_98 ,
V_63 -> V_105 . V_99 , V_63 -> V_105 . V_114 ) ;
for ( V_118 = 0 ; V_118 < F_55 ( V_301 ) ; ++ V_118 ) {
V_87 = F_113 ( V_63 -> V_34 , & V_301 [ V_118 ] ) ;
if ( V_87 < 0 )
return V_87 ;
}
return 0 ;
}
static void
F_114 ( struct V_24 * V_25 )
{
struct V_62 * V_63 = V_25 -> V_63 ;
if ( V_63 == NULL || V_63 -> V_274 == NULL )
return;
F_115 ( V_63 ) ;
}
static int
F_116 ( struct V_24 * V_25 )
{
struct V_28 * V_29 = V_25 -> V_27 -> V_19 ;
struct V_104 * V_105 ;
struct V_62 * V_63 ;
V_63 = F_117 ( 0 , V_29 -> V_34 ) ;
if ( V_63 == NULL ) {
F_25 ( V_29 -> V_34 , L_9 ) ;
return - V_302 ;
}
V_25 -> V_63 = V_63 ;
V_63 -> V_155 = V_303 ;
V_63 -> V_304 = & V_305 ;
V_63 -> V_274 = V_29 -> V_34 ;
V_63 -> V_306 = V_25 -> V_300 ;
V_63 -> V_66 = V_25 ;
V_63 -> V_272 = V_307 ;
snprintf ( V_63 -> V_272 . V_308 , sizeof( V_63 -> V_272 . V_308 ) ,
L_10 , V_25 -> V_178 ) ;
V_63 -> V_272 . V_309 = V_25 -> V_180 ;
V_63 -> V_272 . V_273 = V_25 -> V_68 ;
V_63 -> V_272 . V_291 = V_25 -> V_216 ;
if ( V_25 -> V_176 -> V_225 )
V_63 -> V_272 . V_293 = V_294 ;
else
V_63 -> V_272 . V_293 = V_296 ;
switch ( V_25 -> V_176 -> V_117 ) {
case V_197 :
case V_192 :
V_63 -> V_272 . V_310 = 2 ;
case V_198 :
case V_193 :
V_63 -> V_272 . V_311 = 2 ;
}
V_105 = & V_63 -> V_105 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_98 = V_25 -> V_98 ;
V_105 -> V_99 = V_25 -> V_99 ;
V_105 -> V_182 = V_25 -> V_182 ;
V_105 -> V_183 = V_25 -> V_183 ;
V_105 -> V_312 = V_313 ;
if ( ! V_25 -> V_176 -> V_225 )
V_105 -> V_114 = V_25 -> V_176 -> V_263 ;
else
V_105 -> V_115 = V_25 -> V_176 -> V_117 ;
return F_102 ( V_105 , V_63 ) ;
}
static int F_118 ( T_5 V_314 ,
T_5 V_265 , T_5 V_268 , T_5 V_269 ,
T_5 V_270 , struct V_62 * V_63 )
{
T_1 * V_315 = V_63 -> V_316 ;
if ( V_314 >= V_317 )
return - V_47 ;
V_265 >>= 16 - V_63 -> V_105 . V_265 . V_267 ;
V_268 >>= 16 - V_63 -> V_105 . V_268 . V_267 ;
V_269 >>= 16 - V_63 -> V_105 . V_269 . V_267 ;
V_270 >>= 16 - V_63 -> V_105 . V_270 . V_267 ;
V_315 [ V_314 ] = ( V_265 << V_63 -> V_105 . V_265 . V_266 ) |
( V_268 << V_63 -> V_105 . V_268 . V_266 ) |
( V_269 << V_63 -> V_105 . V_269 . V_266 ) |
( V_270 << V_63 -> V_105 . V_270 . V_266 ) ;
return 0 ;
}
static void F_119 ( struct V_62 * V_63 ,
const struct V_318 * V_319 )
{
F_120 ( V_63 , V_319 ) ;
F_39 ( V_63 ) ;
}
static void F_121 ( struct V_62 * V_63 ,
const struct V_320 * V_321 )
{
F_122 ( V_63 , V_321 ) ;
F_39 ( V_63 ) ;
}
static void F_123 ( struct V_62 * V_63 ,
const struct V_322 * V_323 )
{
F_124 ( V_63 , V_323 ) ;
F_39 ( V_63 ) ;
}
static int F_125 ( struct V_104 * V_105 ,
struct V_62 * V_63 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
struct V_28 * V_29 = V_49 -> V_19 ;
unsigned long V_324 ;
unsigned long V_179 , V_181 ;
unsigned long V_280 ;
unsigned long V_281 ;
if ( ! V_49 -> V_176 -> V_225 ) {
V_280 = ( V_105 -> V_282 * V_49 -> V_182 + V_105 -> V_283 )
* V_49 -> V_176 -> V_263 / 8 ;
V_281 = 0 ;
} else {
unsigned int V_284 = V_49 -> V_176 -> V_263 < 24 ? 2 : 1 ;
unsigned int V_285 = V_49 -> V_176 -> V_263 < 16 ? 2 : 1 ;
V_280 = V_105 -> V_282 * V_49 -> V_182 + V_105 -> V_283 ;
V_281 = V_105 -> V_282 / V_285 * V_49 -> V_182 * 2 / V_284
+ V_105 -> V_283 * 2 / V_284 ;
}
if ( V_280 == V_49 -> V_286 )
return 0 ;
V_179 = V_49 -> V_180 + V_280 ;
V_181 = V_49 -> V_180 + V_49 -> V_182 * V_49 -> V_183
+ V_281 ;
if ( V_49 -> V_248 )
F_81 ( V_29 -> V_35 , V_49 -> V_248 ,
V_179 , V_181 ,
& V_179 , & V_181 ) ;
V_49 -> V_179 = V_179 ;
V_49 -> V_181 = V_181 ;
V_49 -> V_286 = V_280 ;
F_5 ( V_49 , V_7 , V_179 ) ;
if ( V_49 -> V_176 -> V_225 )
F_5 ( V_49 , V_8 , V_181 ) ;
V_324 = F_10 ( V_29 , V_325 ) ;
if ( F_2 ( V_49 ) )
F_9 ( V_49 -> V_19 , V_325 , V_324 ^ V_326 ) ;
else
F_9 ( V_49 -> V_19 , V_325 , V_324 ^ V_327 ) ;
F_39 ( V_63 ) ;
return 0 ;
}
static int F_126 ( struct V_62 * V_63 , unsigned int V_287 ,
unsigned long V_288 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
int V_328 ;
switch ( V_287 ) {
case V_289 :
V_328 = F_61 ( V_49 ) ;
break;
default:
V_328 = - V_290 ;
break;
}
return V_328 ;
}
static void F_127 ( struct V_62 * V_63 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
struct V_104 V_105 ;
struct V_94 V_97 ;
struct V_329 V_101 ;
int V_330 = V_331 ;
if ( V_49 -> V_332 > 1 || ( V_49 -> V_332 == 1 && ! V_63 -> V_333 ) )
return;
F_128 ( & V_97 , & V_63 -> V_105 ) ;
if ( F_45 ( & V_49 -> V_96 . V_97 , & V_97 ) )
return;
V_105 = V_63 -> V_105 ;
F_52 ( & V_105 , & V_49 -> V_96 . V_97 ) ;
V_105 . V_107 = V_49 -> V_96 . V_107 ;
V_105 . V_109 = V_49 -> V_96 . V_109 ;
V_105 . V_312 = V_313 ;
if ( F_129 ( V_63 , & V_105 ) < 0 )
return;
V_101 . V_63 = V_63 ;
V_101 . V_18 = & V_49 -> V_96 . V_97 ;
F_130 ( V_330 , & V_101 ) ;
}
static int F_131 ( struct V_62 * V_63 , int V_334 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
F_132 ( & V_49 -> V_335 ) ;
F_44 ( V_63 -> V_34 , L_11 , V_336 , V_49 -> V_332 ) ;
V_49 -> V_332 -- ;
if ( V_334 ) {
F_47 () ;
F_127 ( V_63 ) ;
F_51 () ;
}
F_133 ( & V_49 -> V_335 ) ;
return 0 ;
}
static int F_134 ( struct V_62 * V_63 , int V_334 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
F_132 ( & V_49 -> V_335 ) ;
V_49 -> V_332 ++ ;
F_44 ( V_63 -> V_34 , L_11 , V_336 , V_49 -> V_332 ) ;
F_133 ( & V_49 -> V_335 ) ;
return 0 ;
}
static int F_53 ( struct V_104 * V_105 ,
struct V_62 * V_63 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
struct V_28 * V_337 = V_49 -> V_19 ;
unsigned int V_338 = ( unsigned int ) - 1 ;
unsigned int V_339 = 0 ;
unsigned int V_340 = 0 ;
unsigned int V_118 ;
int V_87 ;
for ( V_118 = 0 ; V_118 < V_49 -> V_16 -> V_341 ; ++ V_118 ) {
const struct V_94 * V_97 = & V_49 -> V_16 -> V_342 [ V_118 ] ;
unsigned int V_343 ;
if ( V_105 -> V_98 > V_97 -> V_98 || V_105 -> V_99 > V_97 -> V_99 )
continue;
V_343 = V_105 -> V_98 * V_105 -> V_99 + V_97 -> V_98 * V_97 -> V_99
- 2 * F_66 ( V_105 -> V_98 , V_97 -> V_98 )
* F_66 ( V_105 -> V_99 , V_97 -> V_99 ) ;
if ( V_343 < V_338 ) {
V_339 = V_97 -> V_98 ;
V_340 = V_97 -> V_99 ;
V_338 = V_343 ;
}
}
if ( V_49 -> V_16 -> V_341 != 0 ) {
if ( V_338 == ( unsigned int ) - 1 )
return - V_47 ;
V_105 -> V_98 = V_339 ;
V_105 -> V_99 = V_340 ;
}
V_87 = F_87 ( V_105 , V_63 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_337 -> V_344 &&
V_337 -> V_344 != F_56 ( V_105 ) )
return - V_47 ;
return 0 ;
}
static int F_135 ( struct V_62 * V_63 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
int V_87 ;
F_84 ( V_49 -> V_19 ) ;
V_49 -> V_176 = F_54 ( F_56 ( & V_63 -> V_105 ) ) ;
V_49 -> V_226 = V_63 -> V_105 . V_226 ;
V_49 -> V_98 = V_63 -> V_105 . V_98 ;
V_49 -> V_182 = V_63 -> V_105 . V_182 ;
V_49 -> V_99 = V_63 -> V_105 . V_99 ;
V_49 -> V_183 = V_63 -> V_105 . V_183 ;
if ( V_49 -> V_176 -> V_225 )
V_49 -> V_216 = V_63 -> V_105 . V_182 ;
else
V_49 -> V_216 = V_63 -> V_105 . V_182 * V_49 -> V_176 -> V_263 / 8 ;
V_87 = F_78 ( V_49 -> V_19 ) ;
if ( V_87 < 0 )
F_25 ( V_63 -> V_34 , L_12 , V_336 ) ;
V_63 -> V_272 . V_291 = V_49 -> V_216 ;
if ( F_57 ( & V_63 -> V_105 ) ) {
V_63 -> V_272 . type = V_292 ;
V_63 -> V_272 . V_293 = V_294 ;
} else {
V_63 -> V_272 . type = V_295 ;
V_63 -> V_272 . V_293 = V_296 ;
}
return V_87 ;
}
static int F_136 ( int V_297 , struct V_62 * V_63 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
struct V_28 * V_337 = V_49 -> V_19 ;
if ( V_297 > V_259 && V_49 -> V_345 == V_259 ) {
struct V_318 V_319 = {
. V_107 = V_49 -> V_98 ,
. V_109 = V_49 -> V_99 ,
} ;
F_119 ( V_63 , & V_319 ) ;
}
if ( V_297 <= V_346 && V_49 -> V_345 > V_346 ) {
F_13 ( V_337 ) ;
}
if ( V_297 > V_346 && V_49 -> V_345 <= V_346 ) {
if ( ! V_63 -> V_83 ) {
F_61 ( V_49 ) ;
F_61 ( V_49 ) ;
}
F_17 ( V_337 ) ;
}
V_49 -> V_345 = V_297 ;
return 0 ;
}
static int
F_137 ( struct V_62 * V_63 , struct V_298 * V_299 )
{
struct V_14 * V_49 = V_63 -> V_66 ;
return F_106 ( V_49 -> V_19 -> V_34 , V_299 , V_49 -> V_300 ,
V_49 -> V_180 , V_49 -> V_68 ) ;
}
static void
F_138 ( struct V_14 * V_49 )
{
if ( V_49 -> V_63 && V_49 -> V_63 -> V_34 )
F_108 ( V_49 -> V_63 ) ;
}
static int
F_139 ( struct V_14 * V_49 )
{
struct V_62 * V_63 = V_49 -> V_63 ;
int V_87 ;
if ( V_63 -> V_83 ) {
V_49 -> V_72 = F_140 ( sizeof( struct V_347 ) *
V_49 -> V_68 >> V_69 ) ;
if ( ! V_49 -> V_72 ) {
F_25 ( V_49 -> V_19 -> V_34 , L_13 ) ;
return - V_302 ;
}
}
V_63 -> V_348 = V_49 -> V_256 ;
V_87 = F_110 ( V_63 ) ;
if ( V_87 < 0 )
return V_87 ;
F_111 ( V_49 -> V_19 -> V_34 , L_14 ,
F_112 ( V_49 -> V_19 -> V_34 ) , ( V_49 -> V_16 -> V_15 == V_349 ) ?
L_15 : L_16 , V_63 -> V_105 . V_98 , V_63 -> V_105 . V_99 ,
V_63 -> V_105 . V_114 ) ;
if ( V_63 -> V_83 || V_63 -> V_91 == V_92 )
F_17 ( V_49 -> V_19 ) ;
return V_87 ;
}
static void
F_141 ( struct V_14 * V_49 )
{
struct V_62 * V_63 = V_49 -> V_63 ;
if ( ! V_63 || ! V_63 -> V_274 )
return;
if ( V_49 -> V_72 )
F_142 ( V_49 -> V_72 ) ;
F_143 ( & V_63 -> V_350 ) ;
F_115 ( V_63 ) ;
}
static int
F_144 ( struct V_14 * V_49 ,
const struct V_94 * V_351 ,
unsigned int V_341 )
{
struct V_28 * V_29 = V_49 -> V_19 ;
struct V_104 * V_105 ;
struct V_62 * V_63 ;
int V_87 ;
V_63 = F_117 ( 0 , V_29 -> V_34 ) ;
if ( V_63 == NULL ) {
F_25 ( V_29 -> V_34 , L_9 ) ;
return - V_302 ;
}
V_49 -> V_63 = V_63 ;
V_63 -> V_155 = V_303 ;
V_63 -> V_304 = & V_352 ;
V_63 -> V_274 = V_29 -> V_34 ;
V_63 -> V_306 = V_49 -> V_300 ;
V_63 -> V_316 = & V_49 -> V_316 ;
V_63 -> V_66 = V_49 ;
F_145 ( V_351 , V_341 , & V_63 -> V_353 ) ;
V_87 = F_146 ( & V_63 -> V_350 , V_317 , 0 ) ;
if ( V_87 < 0 ) {
F_25 ( V_29 -> V_34 , L_17 ) ;
return V_87 ;
}
V_63 -> V_272 = V_354 ;
V_63 -> V_272 . V_309 = V_49 -> V_180 ;
V_63 -> V_272 . V_273 = V_49 -> V_68 ;
V_63 -> V_272 . V_291 = V_49 -> V_216 ;
if ( V_49 -> V_176 -> V_225 )
V_63 -> V_272 . V_293 = V_294 ;
else
V_63 -> V_272 . V_293 = V_296 ;
switch ( V_49 -> V_176 -> V_117 ) {
case V_197 :
case V_192 :
V_63 -> V_272 . V_310 = 2 ;
case V_198 :
case V_193 :
V_63 -> V_272 . V_311 = 2 ;
}
V_105 = & V_63 -> V_105 ;
F_52 ( V_105 , V_351 ) ;
V_105 -> V_107 = V_49 -> V_96 . V_107 ;
V_105 -> V_109 = V_49 -> V_96 . V_109 ;
V_105 -> V_182 = V_49 -> V_182 ;
V_105 -> V_183 = V_49 -> V_183 ;
V_105 -> V_312 = V_313 ;
if ( ! V_49 -> V_176 -> V_225 )
V_105 -> V_114 = V_49 -> V_176 -> V_263 ;
else
V_105 -> V_115 = V_49 -> V_176 -> V_117 ;
V_87 = F_53 ( V_105 , V_63 ) ;
if ( V_87 )
return V_87 ;
return 0 ;
}
static int F_147 ( struct V_355 * V_356 )
{
struct V_14 * V_49 = F_148 ( V_356 ) ;
int V_357 = V_356 -> V_257 . V_357 ;
if ( V_356 -> V_257 . V_258 != V_259 ||
V_356 -> V_257 . V_91 & ( V_358 | V_359 ) )
V_357 = 0 ;
V_49 -> V_360 = V_357 ;
return V_49 -> V_16 -> V_361 . V_362 ( V_357 ) ;
}
static int F_149 ( struct V_355 * V_356 )
{
struct V_14 * V_49 = F_148 ( V_356 ) ;
return V_49 -> V_360 ;
}
static int F_150 ( struct V_355 * V_356 ,
struct V_62 * V_63 )
{
return ( V_63 -> V_348 == V_356 ) ;
}
static struct V_355 * F_151 ( struct V_274 * V_363 ,
struct V_14 * V_49 )
{
struct V_355 * V_256 ;
V_256 = F_152 ( V_49 -> V_16 -> V_361 . V_364 , V_363 , V_49 ,
& V_365 , NULL ) ;
if ( F_24 ( V_256 ) ) {
F_25 ( V_363 , L_18 ,
F_26 ( V_256 ) ) ;
return NULL ;
}
V_256 -> V_257 . V_366 = V_49 -> V_16 -> V_361 . V_366 ;
V_256 -> V_257 . V_357 = V_256 -> V_257 . V_366 ;
F_83 ( V_256 ) ;
return V_256 ;
}
static void F_153 ( struct V_355 * V_356 )
{
F_154 ( V_356 ) ;
}
static int F_155 ( struct V_274 * V_34 )
{
struct V_367 * V_36 = F_156 ( V_34 ) ;
F_84 ( F_157 ( V_36 ) ) ;
return 0 ;
}
static int F_158 ( struct V_274 * V_34 )
{
struct V_367 * V_36 = F_156 ( V_34 ) ;
return F_78 ( F_157 ( V_36 ) ) ;
}
static int F_159 ( struct V_274 * V_34 )
{
struct V_367 * V_36 = F_156 ( V_34 ) ;
struct V_28 * V_29 = F_157 ( V_36 ) ;
F_9 ( V_29 , V_240 , 0 ) ;
return 0 ;
}
static int F_160 ( struct V_274 * V_34 )
{
struct V_367 * V_36 = F_156 ( V_34 ) ;
struct V_28 * V_29 = F_157 ( V_36 ) ;
F_77 ( V_29 ) ;
return 0 ;
}
static int F_161 ( struct V_368 * V_369 ,
unsigned long V_370 , void * V_18 )
{
struct V_329 * V_101 = V_18 ;
struct V_62 * V_63 = V_101 -> V_63 ;
struct V_14 * V_49 = V_63 -> V_66 ;
if ( & V_49 -> V_19 -> V_371 != V_369 )
return V_372 ;
F_44 ( V_63 -> V_34 , L_19 ,
V_336 , V_370 , V_101 -> V_18 ) ;
switch( V_370 ) {
case V_373 :
F_42 ( V_49 ) ;
F_84 ( V_49 -> V_19 ) ;
break;
case V_374 :
F_132 ( & V_49 -> V_335 ) ;
F_127 ( V_63 ) ;
F_133 ( & V_49 -> V_335 ) ;
F_41 ( V_49 ) ;
F_78 ( V_49 -> V_19 ) ;
}
return V_375 ;
}
static int F_162 ( struct V_367 * V_36 )
{
struct V_28 * V_29 = F_157 ( V_36 ) ;
unsigned int V_118 ;
F_163 ( & V_29 -> V_371 ) ;
for ( V_118 = 0 ; V_118 < F_55 ( V_29 -> V_253 ) ; V_118 ++ )
F_107 ( & V_29 -> V_253 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < F_55 ( V_29 -> V_49 ) ; V_118 ++ )
F_138 ( & V_29 -> V_49 [ V_118 ] ) ;
F_84 ( V_29 ) ;
for ( V_118 = 0 ; V_118 < F_55 ( V_29 -> V_253 ) ; V_118 ++ ) {
struct V_24 * V_25 = & V_29 -> V_253 [ V_118 ] ;
F_114 ( V_25 ) ;
if ( V_25 -> V_300 )
F_164 ( & V_36 -> V_34 , V_25 -> V_68 ,
V_25 -> V_300 , V_25 -> V_180 ) ;
}
for ( V_118 = 0 ; V_118 < F_55 ( V_29 -> V_49 ) ; V_118 ++ ) {
struct V_14 * V_49 = & V_29 -> V_49 [ V_118 ] ;
if ( V_49 -> V_86 ) {
V_49 -> V_86 -> V_19 = NULL ;
F_165 ( V_49 -> V_16 -> V_86 -> V_34 . V_376 -> V_377 ) ;
}
F_141 ( V_49 ) ;
if ( V_49 -> V_300 )
F_164 ( & V_36 -> V_34 , V_49 -> V_68 ,
V_49 -> V_300 , V_49 -> V_180 ) ;
}
for ( V_118 = 0 ; V_118 < F_55 ( V_29 -> V_49 ) ; V_118 ++ ) {
struct V_14 * V_49 = & V_29 -> V_49 [ V_118 ] ;
if ( V_49 -> V_256 )
F_153 ( V_49 -> V_256 ) ;
F_166 ( & V_49 -> V_335 ) ;
}
if ( V_29 -> V_33 ) {
F_167 ( & V_36 -> V_34 ) ;
F_168 ( V_29 -> V_33 ) ;
}
if ( V_29 -> V_20 )
F_169 ( V_29 -> V_20 ) ;
if ( V_29 -> V_123 )
F_170 ( V_29 -> V_123 , V_29 ) ;
F_171 ( V_29 ) ;
return 0 ;
}
static int F_172 ( struct V_14 * V_49 )
{
int V_378 = V_49 -> V_16 -> V_378 ;
switch ( V_378 ) {
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
break;
default:
return - V_47 ;
}
if ( F_2 ( V_49 ) ) {
if ( ! ( V_378 & V_232 ) )
return - V_47 ;
V_378 &= ~ V_232 ;
}
V_49 -> V_149 = V_378 ;
return 0 ;
}
static int
F_173 ( struct V_24 * V_25 )
{
const struct V_116 * V_176 ;
struct V_274 * V_34 = V_25 -> V_27 -> V_19 -> V_34 ;
int V_87 ;
if ( V_25 -> V_16 -> V_117 == 0 )
return 0 ;
V_176 = F_54 ( V_25 -> V_16 -> V_117 ) ;
if ( V_176 == NULL ) {
F_25 ( V_34 , L_20 , V_25 -> V_16 -> V_117 ) ;
return - V_47 ;
}
V_25 -> V_131 = false ;
V_25 -> V_97 = V_184 ;
V_25 -> V_186 = 255 ;
V_25 -> V_190 = 0 ;
V_25 -> V_214 = 0 ;
V_25 -> V_212 = 0 ;
V_25 -> V_176 = V_176 ;
V_25 -> V_98 = V_25 -> V_16 -> V_397 ;
V_25 -> V_182 = V_25 -> V_98 ;
V_25 -> V_99 = V_25 -> V_16 -> V_398 ;
V_25 -> V_183 = V_25 -> V_99 * 2 ;
if ( ! V_176 -> V_225 )
V_25 -> V_216 = V_25 -> V_182 * V_176 -> V_263 / 8 ;
else
V_25 -> V_216 = V_25 -> V_182 ;
V_25 -> V_68 = V_25 -> V_16 -> V_397 * V_25 -> V_16 -> V_398
* V_176 -> V_263 / 8 * 2 ;
V_25 -> V_300 = F_174 ( V_34 , V_25 -> V_68 , & V_25 -> V_180 ,
V_399 ) ;
if ( ! V_25 -> V_300 ) {
F_25 ( V_34 , L_21 ) ;
return - V_302 ;
}
V_87 = F_116 ( V_25 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
static int
F_175 ( struct V_14 * V_49 )
{
const struct V_116 * V_176 ;
const struct V_400 * V_16 = V_49 -> V_16 ;
struct V_274 * V_34 = V_49 -> V_19 -> V_34 ;
const struct V_94 * V_401 ;
const struct V_94 * V_97 ;
unsigned int V_341 ;
unsigned int V_402 ;
unsigned int V_118 ;
F_176 ( & V_49 -> V_335 ) ;
V_49 -> V_403 = F_46 ;
V_176 = F_54 ( V_16 -> V_117 ) ;
if ( V_176 == NULL ) {
F_25 ( V_34 , L_22 , V_16 -> V_117 ) ;
return - V_47 ;
}
V_401 = NULL ;
V_402 = 0 ;
for ( V_118 = 0 , V_97 = V_16 -> V_342 ; V_118 < V_16 -> V_341 ; V_118 ++ , V_97 ++ ) {
unsigned int V_404 = V_97 -> V_99 * V_97 -> V_98 ;
if ( ( V_16 -> V_117 == V_197 ||
V_16 -> V_117 == V_192 ) && ( V_97 -> V_99 & 0x1 ) ) {
F_25 ( V_34 , L_23
L_24 ) ;
return - V_47 ;
}
if ( V_404 > V_402 ) {
V_401 = V_97 ;
V_402 = V_404 ;
}
}
if ( ! V_402 )
V_402 = V_261 * V_262 ;
else
F_44 ( V_34 , L_25 ,
V_401 -> V_98 , V_401 -> V_99 ) ;
if ( V_16 -> V_342 == NULL ) {
V_97 = & V_405 ;
V_341 = 1 ;
} else {
V_97 = V_16 -> V_342 ;
V_341 = V_16 -> V_341 ;
}
V_49 -> V_176 = V_176 ;
V_49 -> V_98 = V_97 -> V_98 ;
V_49 -> V_182 = V_97 -> V_98 ;
V_49 -> V_99 = V_97 -> V_99 ;
V_49 -> V_183 = V_97 -> V_99 * 2 ;
if ( ! V_176 -> V_225 ) {
V_49 -> V_226 = V_264 ;
V_49 -> V_216 = V_49 -> V_182 * V_176 -> V_263 / 8 ;
} else {
V_49 -> V_226 = V_227 ;
V_49 -> V_216 = V_49 -> V_182 ;
}
V_49 -> V_96 . V_107 = V_16 -> V_76 . V_107 ;
V_49 -> V_96 . V_109 = V_16 -> V_76 . V_109 ;
V_49 -> V_96 . V_97 = * V_97 ;
V_49 -> V_68 = V_402 * V_176 -> V_263 / 8 * 2 ;
V_49 -> V_300 = F_174 ( V_34 , V_49 -> V_68 , & V_49 -> V_180 ,
V_399 ) ;
if ( V_49 -> V_300 == NULL ) {
F_25 ( V_34 , L_21 ) ;
return - V_302 ;
}
if ( V_16 -> V_86 ) {
if ( ! V_16 -> V_86 -> V_34 . V_376 ||
! F_177 ( V_16 -> V_86 -> V_34 . V_376 -> V_377 ) ) {
F_178 ( V_34 , L_26 ) ;
return - V_47 ;
}
V_49 -> V_86 = F_157 ( V_16 -> V_86 ) ;
V_49 -> V_86 -> V_19 = V_49 ;
V_49 -> V_86 -> V_406 = * V_97 ;
}
return F_144 ( V_49 , V_97 , V_341 ) ;
}
static int F_179 ( struct V_367 * V_36 )
{
struct V_407 * V_408 = V_36 -> V_34 . V_409 ;
struct V_28 * V_29 ;
struct V_410 * V_411 ;
int V_412 ;
int error ;
int V_118 ;
if ( ! V_408 ) {
F_25 ( & V_36 -> V_34 , L_27 ) ;
return - V_47 ;
}
V_411 = F_180 ( V_36 , V_413 , 0 ) ;
V_118 = F_181 ( V_36 , 0 ) ;
if ( ! V_411 || V_118 < 0 ) {
F_25 ( & V_36 -> V_34 , L_28 ) ;
return - V_414 ;
}
V_29 = F_182 ( sizeof( * V_29 ) , V_399 ) ;
if ( ! V_29 ) {
F_25 ( & V_36 -> V_34 , L_29 ) ;
return - V_302 ;
}
V_29 -> V_34 = & V_36 -> V_34 ;
V_29 -> V_35 = V_408 -> V_35 ;
F_183 ( V_36 , V_29 ) ;
error = F_184 ( V_118 , F_58 , 0 ,
F_112 ( & V_36 -> V_34 ) , V_29 ) ;
if ( error ) {
F_25 ( & V_36 -> V_34 , L_30 ) ;
goto V_415;
}
V_29 -> V_123 = V_118 ;
F_185 ( & V_29 -> V_32 , - 1 ) ;
for ( V_118 = 0 , V_412 = 0 ; V_118 < F_55 ( V_408 -> V_49 ) ; V_118 ++ ) {
struct V_14 * V_49 = V_29 -> V_49 + V_412 ;
V_49 -> V_19 = V_29 ;
V_49 -> V_16 = & V_408 -> V_49 [ V_118 ] ;
error = F_172 ( V_49 ) ;
if ( error ) {
F_25 ( & V_36 -> V_34 , L_31 ) ;
goto V_415;
}
F_186 ( & V_49 -> V_134 ) ;
F_187 ( & V_49 -> V_136 ) ;
if ( V_49 -> V_16 -> V_361 . V_366 )
V_49 -> V_256 = F_151 ( & V_36 -> V_34 , V_49 ) ;
switch ( V_408 -> V_49 [ V_118 ] . V_15 ) {
case V_349 :
V_49 -> V_131 = V_416 ;
V_49 -> V_21 = V_417 ;
V_412 ++ ;
break;
case V_17 :
V_49 -> V_131 = V_418 ;
V_49 -> V_21 = V_419 ;
V_412 ++ ;
break;
}
}
if ( ! V_412 ) {
F_25 ( & V_36 -> V_34 , L_32 ) ;
error = - V_47 ;
goto V_415;
}
if ( V_412 == 2 )
V_29 -> V_344 = V_408 -> V_49 [ 0 ] . V_117 ;
V_29 -> V_20 = F_188 ( V_411 -> V_139 , F_189 ( V_411 ) ) ;
if ( ! V_29 -> V_20 )
goto V_415;
error = F_22 ( V_29 , V_408 -> V_37 ) ;
if ( error ) {
F_25 ( & V_36 -> V_34 , L_33 ) ;
goto V_415;
}
F_190 ( & V_36 -> V_34 ) ;
for ( V_118 = 0 ; V_118 < V_412 ; V_118 ++ ) {
struct V_14 * V_49 = & V_29 -> V_49 [ V_118 ] ;
error = F_175 ( V_49 ) ;
if ( error )
goto V_415;
}
for ( V_118 = 0 ; V_118 < F_55 ( V_408 -> V_253 ) ; V_118 ++ ) {
struct V_24 * V_25 = & V_29 -> V_253 [ V_118 ] ;
V_25 -> V_16 = & V_408 -> V_253 [ V_118 ] ;
V_25 -> V_27 = & V_29 -> V_49 [ 0 ] ;
error = F_173 ( V_25 ) ;
if ( error )
goto V_415;
}
error = F_78 ( V_29 ) ;
if ( error ) {
F_25 ( & V_36 -> V_34 , L_34 ) ;
goto V_415;
}
for ( V_118 = 0 ; V_118 < V_412 ; V_118 ++ ) {
struct V_14 * V_49 = V_29 -> V_49 + V_118 ;
error = F_139 ( V_49 ) ;
if ( error )
goto V_415;
}
for ( V_118 = 0 ; V_118 < F_55 ( V_408 -> V_253 ) ; V_118 ++ ) {
struct V_24 * V_25 = & V_29 -> V_253 [ V_118 ] ;
error = F_109 ( V_25 ) ;
if ( error )
goto V_415;
}
V_29 -> V_371 . V_420 = F_161 ;
F_191 ( & V_29 -> V_371 ) ;
return 0 ;
V_415:
F_162 ( V_36 ) ;
return error ;
}
