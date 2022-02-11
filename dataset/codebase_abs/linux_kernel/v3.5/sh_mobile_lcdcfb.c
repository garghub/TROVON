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
unsigned long V_21 , unsigned long V_18 )
{
F_4 ( V_18 , V_25 -> V_20 + V_21 ) ;
}
static unsigned long F_9 ( struct V_24 * V_25 ,
unsigned long V_21 )
{
return F_7 ( V_25 -> V_20 + V_21 ) ;
}
static void F_10 ( struct V_24 * V_25 ,
unsigned long V_21 ,
unsigned long V_26 , unsigned long V_27 )
{
while ( ( F_9 ( V_25 , V_21 ) & V_26 ) != V_27 )
F_11 () ;
}
static void F_12 ( struct V_24 * V_25 )
{
if ( F_13 ( & V_25 -> V_28 ) ) {
if ( V_25 -> V_29 )
F_14 ( V_25 -> V_29 ) ;
F_15 ( V_25 -> V_30 ) ;
if ( V_25 -> V_31 && V_25 -> V_31 -> V_32 )
F_15 ( & V_25 -> V_31 -> V_32 -> V_30 ) ;
}
}
static void F_16 ( struct V_24 * V_25 )
{
if ( F_17 ( 1 , & V_25 -> V_28 ) == - 1 ) {
if ( V_25 -> V_31 && V_25 -> V_31 -> V_32 )
F_18 ( & V_25 -> V_31 -> V_32 -> V_30 ) ;
F_19 ( V_25 -> V_30 ) ;
if ( V_25 -> V_29 )
F_20 ( V_25 -> V_29 ) ;
}
}
static int F_21 ( struct V_24 * V_25 ,
int V_33 )
{
struct V_34 * V_34 ;
char * V_35 ;
switch ( V_33 ) {
case V_36 :
V_35 = L_1 ;
V_25 -> V_37 = V_38 ;
break;
case V_39 :
V_35 = L_2 ;
V_25 -> V_37 = V_40 ;
break;
case V_41 :
V_35 = NULL ;
V_25 -> V_37 = V_42 ;
break;
default:
return - V_43 ;
}
if ( V_35 == NULL )
return 0 ;
V_34 = F_22 ( V_25 -> V_30 , V_35 ) ;
if ( F_23 ( V_34 ) ) {
F_24 ( V_25 -> V_30 , L_3 , V_35 ) ;
return F_25 ( V_34 ) ;
}
V_25 -> V_29 = V_34 ;
return 0 ;
}
static void F_26 ( void * V_44 , unsigned long V_18 )
{
struct V_14 * V_45 = V_44 ;
F_8 ( V_45 -> V_19 , V_46 , V_18 | V_47 ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
F_8 ( V_45 -> V_19 , V_50 , V_51 |
( F_2 ( V_45 ) ? 2 : 0 ) ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
}
static void F_27 ( void * V_44 , unsigned long V_18 )
{
struct V_14 * V_45 = V_44 ;
F_8 ( V_45 -> V_19 , V_46 , V_18 | V_47 | V_52 ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
F_8 ( V_45 -> V_19 , V_50 , V_51 |
( F_2 ( V_45 ) ? 2 : 0 ) ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
}
static unsigned long F_28 ( void * V_44 )
{
struct V_14 * V_45 = V_44 ;
F_8 ( V_45 -> V_19 , V_53 , V_54 ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
F_8 ( V_45 -> V_19 , V_55 , V_56 |
( F_2 ( V_45 ) ? 2 : 0 ) ) ;
F_29 ( 1 ) ;
F_10 ( V_45 -> V_19 , V_48 , V_49 , 0 ) ;
return F_9 ( V_45 -> V_19 , V_53 ) & V_57 ;
}
static int F_30 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
unsigned int V_63 = V_45 -> V_64 >> V_65 ;
struct V_66 * V_66 ;
int V_67 = 0 ;
F_31 ( V_45 -> V_68 , V_63 ) ;
F_32 (page, pagelist, lru)
F_33 ( & V_45 -> V_68 [ V_67 ++ ] , V_66 , V_69 , 0 ) ;
return V_67 ;
}
static void F_34 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
const struct V_70 * V_71 = & V_45 -> V_16 -> V_72 ;
F_12 ( V_45 -> V_19 ) ;
if ( ! F_35 ( V_61 ) ) {
unsigned int V_67 = F_30 ( V_59 , V_61 ) ;
F_36 ( V_45 -> V_19 -> V_30 , V_45 -> V_68 , V_67 , V_73 ) ;
if ( V_71 -> V_74 )
V_71 -> V_74 ( V_45 , & V_75 ) ;
F_3 ( V_45 , V_76 , V_77 ) ;
F_37 ( V_45 -> V_19 -> V_30 , V_45 -> V_68 , V_67 ,
V_73 ) ;
} else {
if ( V_71 -> V_74 )
V_71 -> V_74 ( V_45 , & V_75 ) ;
F_3 ( V_45 , V_76 , V_77 ) ;
}
}
static void F_38 ( struct V_58 * V_59 )
{
struct V_78 * V_79 = V_59 -> V_79 ;
if ( V_79 )
F_39 ( & V_59 -> V_80 , V_79 -> V_81 ) ;
}
static void F_40 ( struct V_14 * V_45 )
{
const struct V_70 * V_71 = & V_45 -> V_16 -> V_72 ;
if ( V_45 -> V_82 ) {
int V_83 ;
V_83 = V_45 -> V_82 -> V_84 -> V_85 ( V_45 -> V_82 ) ;
if ( V_83 < 0 )
return;
if ( V_83 == V_86 )
V_45 -> V_59 -> V_87 = V_88 ;
}
if ( V_71 -> V_85 )
V_71 -> V_85 () ;
}
static void F_41 ( struct V_14 * V_45 )
{
const struct V_70 * V_71 = & V_45 -> V_16 -> V_72 ;
if ( V_71 -> V_89 )
V_71 -> V_89 () ;
if ( V_45 -> V_82 )
V_45 -> V_82 -> V_84 -> V_89 ( V_45 -> V_82 ) ;
}
static bool
F_42 ( struct V_14 * V_45 ,
const struct V_90 * V_91 )
{
F_43 ( V_45 -> V_59 -> V_30 , L_4 ,
V_45 -> V_92 . V_93 . V_94 , V_45 -> V_92 . V_93 . V_95 ,
V_91 -> V_94 , V_91 -> V_95 ) ;
if ( F_44 ( & V_45 -> V_92 . V_93 , V_91 ) )
return false ;
F_43 ( V_45 -> V_59 -> V_30 , L_5 ,
V_45 -> V_92 . V_93 . V_95 , V_91 -> V_95 ) ;
V_45 -> V_92 . V_93 = * V_91 ;
return true ;
}
static int F_45 ( struct V_14 * V_45 ,
enum V_96 V_97 ,
const struct V_90 * V_93 ,
const struct V_98 * V_99 )
{
struct V_58 * V_59 = V_45 -> V_59 ;
struct V_100 V_101 ;
int V_83 = 0 ;
switch ( V_97 ) {
case V_102 :
if ( F_46 ( V_59 ) ) {
F_47 () ;
V_45 -> V_92 . V_103 = V_99 -> V_104 * 10 ;
V_45 -> V_92 . V_105 = V_99 -> V_106 * 10 ;
if ( ! F_42 ( V_45 , V_93 ) &&
V_59 -> V_87 == V_107 ) {
V_59 -> V_101 . V_103 = V_99 -> V_104 * 10 ;
V_59 -> V_101 . V_105 = V_99 -> V_106 * 10 ;
F_40 ( V_45 ) ;
} else {
F_48 ( V_59 , 0 ) ;
}
F_49 () ;
F_50 ( V_59 ) ;
}
break;
case V_108 :
if ( F_46 ( V_59 ) ) {
F_47 () ;
F_48 ( V_59 , 1 ) ;
F_49 () ;
F_50 ( V_59 ) ;
}
break;
case V_109 :
F_51 ( & V_101 , V_93 ) ;
V_101 . V_110 = V_59 -> V_101 . V_110 ;
V_101 . V_111 = V_59 -> V_101 . V_111 ;
V_83 = F_52 ( & V_101 , V_59 ) ;
break;
}
return V_83 ;
}
static const struct V_112 *
F_53 ( T_1 V_113 )
{
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < F_54 ( V_115 ) ; ++ V_114 ) {
if ( V_115 [ V_114 ] . V_113 == V_113 )
return & V_115 [ V_114 ] ;
}
return NULL ;
}
static int F_55 ( const struct V_100 * V_101 )
{
if ( V_101 -> V_111 > 1 )
return V_101 -> V_111 ;
switch ( V_101 -> V_110 ) {
case 16 :
return V_116 ;
case 24 :
return V_117 ;
case 32 :
return V_118 ;
default:
return 0 ;
}
}
static int F_56 ( const struct V_100 * V_101 )
{
return V_101 -> V_111 > 1 ;
}
static T_2 F_57 ( int V_119 , void * V_18 )
{
struct V_24 * V_25 = V_18 ;
struct V_14 * V_45 ;
unsigned long V_120 ;
int V_121 ;
int V_122 ;
V_120 = F_9 ( V_25 , V_123 ) ;
F_8 ( V_25 , V_123 , ( V_120 ^ V_124 ) & ~ V_125 ) ;
V_121 = ( F_9 ( V_25 , V_48 ) & V_126 ) ? 1 : 0 ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
if ( V_120 & V_128 ) {
if ( V_121 == F_2 ( V_45 ) ) {
V_45 -> V_129 = 1 ;
F_58 ( & V_45 -> V_130 ) ;
F_16 ( V_25 ) ;
}
}
if ( V_120 & V_131 )
F_59 ( & V_45 -> V_132 ) ;
}
return V_133 ;
}
static int F_60 ( struct V_14 * V_45 )
{
unsigned long V_120 ;
int V_83 ;
V_120 = F_9 ( V_45 -> V_19 , V_123 ) ;
V_120 |= V_125 | V_124 ;
F_8 ( V_45 -> V_19 , V_123 , V_120 ) ;
V_83 = F_61 ( & V_45 -> V_132 ,
F_62 ( 100 ) ) ;
if ( ! V_83 )
return - V_134 ;
return 0 ;
}
static void F_63 ( struct V_24 * V_25 ,
int V_135 )
{
unsigned long V_136 = F_9 ( V_25 , V_137 ) ;
int V_122 ;
if ( V_135 )
F_8 ( V_25 , V_137 , V_136 | V_138 ) ;
else
F_8 ( V_25 , V_137 , V_136 & ~ V_138 ) ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ )
if ( F_9 ( V_25 , V_137 ) & V_25 -> V_45 [ V_122 ] . V_127 )
while ( 1 ) {
V_136 = F_6 ( & V_25 -> V_45 [ V_122 ] , V_139 )
& V_140 ;
if ( V_135 && V_136 == V_140 )
break;
if ( ! V_135 && V_136 == 0 )
break;
F_11 () ;
}
if ( ! V_135 )
F_8 ( V_25 , V_141 , 1 ) ;
}
static void F_64 ( struct V_14 * V_45 )
{
const struct V_100 * V_101 = & V_45 -> V_59 -> V_101 ;
const struct V_90 * V_93 = & V_45 -> V_92 . V_93 ;
unsigned long V_142 , V_143 , V_144 ;
T_1 V_136 ;
V_136 = V_45 -> V_145 ;
V_136 |= ( V_101 -> V_146 & V_147 ) ? 0 : V_148 ;
V_136 |= ( V_101 -> V_146 & V_149 ) ? 0 : V_150 ;
V_136 |= ( V_45 -> V_16 -> V_151 & V_152 ) ? V_153 : 0 ;
V_136 |= ( V_45 -> V_16 -> V_151 & V_154 ) ? V_155 : 0 ;
V_136 |= ( V_45 -> V_16 -> V_151 & V_156 ) ? V_157 : 0 ;
V_136 |= ( V_45 -> V_16 -> V_151 & V_158 ) ? V_159 : 0 ;
V_136 |= ( V_45 -> V_16 -> V_151 & V_160 ) ? V_161 : 0 ;
F_3 ( V_45 , V_2 , V_136 ) ;
F_3 ( V_45 , V_3 , V_45 -> V_16 -> V_162 . V_163 ) ;
F_3 ( V_45 , V_4 , V_45 -> V_16 -> V_162 . V_164 ) ;
V_142 = V_93 -> V_94 + V_93 -> V_165 + V_93 -> V_166
+ V_93 -> V_167 ;
V_136 = V_142 / 8 ;
V_136 |= ( F_65 ( V_93 -> V_94 , V_45 -> V_94 ) / 8 ) << 16 ;
F_3 ( V_45 , V_10 , V_136 ) ;
V_143 = V_93 -> V_94 + V_93 -> V_167 ;
V_136 = V_143 / 8 ;
V_136 |= ( V_93 -> V_165 / 8 ) << 16 ;
F_3 ( V_45 , V_11 , V_136 ) ;
V_136 = V_93 -> V_95 + V_93 -> V_168 + V_93 -> V_169
+ V_93 -> V_170 ;
V_136 |= F_65 ( V_93 -> V_95 , V_45 -> V_95 ) << 16 ;
F_3 ( V_45 , V_12 , V_136 ) ;
V_136 = V_93 -> V_95 + V_93 -> V_170 ;
V_136 |= V_93 -> V_168 << 16 ;
F_3 ( V_45 , V_13 , V_136 ) ;
V_144 = V_93 -> V_94 + V_93 -> V_165 + V_93 -> V_166
+ V_93 -> V_167 ;
V_136 = ( ( V_93 -> V_94 & 7 ) << 24 ) | ( ( V_144 & 7 ) << 16 )
| ( ( V_93 -> V_165 & 7 ) << 8 ) | ( V_143 & 7 ) ;
F_3 ( V_45 , V_171 , V_136 ) ;
}
static void F_66 ( struct V_24 * V_25 )
{
struct V_14 * V_45 ;
unsigned long V_136 ;
int V_122 , V_172 ;
F_8 ( V_25 , V_137 , V_25 -> V_45 [ 0 ] . V_127 | V_25 -> V_45 [ 1 ] . V_127 ) ;
F_63 ( V_25 , 0 ) ;
F_8 ( V_25 , V_123 , 0 ) ;
V_136 = V_25 -> V_37 ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
F_3 ( V_45 , V_139 , 0 ) ;
V_172 = V_45 -> V_16 -> V_173 ;
if ( ! V_172 )
continue;
F_3 ( V_45 , V_174 , 0 ) ;
F_3 ( V_45 , V_175 , ( 1 << ( V_172 / 2 ) ) - 1 ) ;
if ( V_172 == 1 )
V_172 = V_176 ;
V_136 |= V_172 << ( F_2 ( V_45 ) ? 8 : 0 ) ;
}
F_8 ( V_25 , V_177 , V_136 ) ;
F_8 ( V_25 , V_141 , 0 ) ;
F_10 ( V_25 , V_141 , ~ 0 , 0 ) ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
F_64 ( V_45 ) ;
V_136 = V_45 -> V_178 -> V_179 ;
if ( V_45 -> V_178 -> V_180 ) {
switch ( V_45 -> V_181 ) {
case V_182 :
V_136 |= V_183 ;
break;
case V_184 :
V_136 |= V_185 ;
break;
}
}
F_3 ( V_45 , V_5 , V_136 ) ;
F_3 ( V_45 , V_9 , V_45 -> V_186 ) ;
F_3 ( V_45 , V_7 , V_45 -> V_187 ) ;
if ( V_45 -> V_178 -> V_180 )
F_3 ( V_45 , V_8 , V_45 -> V_188 ) ;
if ( V_45 -> V_145 & V_189 &&
V_45 -> V_16 -> V_162 . V_190 ) {
F_3 ( V_45 , V_6 , V_191 ) ;
F_8 ( V_25 , V_123 , V_192 ) ;
} else {
F_3 ( V_45 , V_6 , 0 ) ;
}
}
switch ( V_25 -> V_45 [ 0 ] . V_178 -> V_113 ) {
case V_116 :
case V_193 :
case V_194 :
case V_195 :
V_136 = V_196 | V_197 ;
break;
case V_117 :
case V_198 :
case V_199 :
case V_200 :
V_136 = V_196 | V_197 | V_201 ;
break;
case V_118 :
default:
V_136 = V_196 ;
break;
}
F_8 ( V_25 , V_202 , V_136 ) ;
F_8 ( V_25 , V_203 , V_204 ) ;
F_63 ( V_25 , 1 ) ;
V_25 -> V_205 = 1 ;
}
static int F_67 ( struct V_24 * V_25 )
{
struct V_206 * V_207 = V_25 -> V_31 ;
struct V_14 * V_45 ;
unsigned long V_136 ;
int V_83 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
if ( V_25 -> V_45 [ V_122 ] . V_127 )
F_12 ( V_25 ) ;
}
F_8 ( V_25 , V_137 , F_9 ( V_25 , V_137 ) | V_208 ) ;
F_10 ( V_25 , V_137 , V_208 , 0 ) ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
const struct V_70 * V_71 ;
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
V_71 = & V_45 -> V_16 -> V_72 ;
if ( V_71 -> V_209 ) {
V_83 = V_71 -> V_209 ( V_45 , & V_75 ) ;
if ( V_83 )
return V_83 ;
}
}
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
int V_210 ;
void * V_211 ;
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
V_45 -> V_187 = V_45 -> V_212 ;
V_45 -> V_188 = V_45 -> V_187 + V_45 -> V_94 * V_45 -> V_213 ;
V_45 -> V_186 = V_45 -> V_214 ;
if ( V_207 == NULL || V_207 -> V_84 == NULL ||
V_45 -> V_16 -> V_215 == NULL )
continue;
if ( V_45 -> V_211 ) {
V_207 -> V_84 -> V_216 ( V_207 , V_45 -> V_211 ) ;
V_45 -> V_211 = NULL ;
}
switch ( V_45 -> V_178 -> V_113 ) {
case V_198 :
case V_193 :
case V_199 :
case V_194 :
V_210 = V_217 ;
break;
case V_200 :
case V_195 :
V_210 = V_218 ;
break;
case V_116 :
case V_117 :
case V_118 :
default:
V_210 = V_219 ;
break;
}
V_211 = V_207 -> V_84 -> V_220 ( V_207 , V_45 -> V_16 -> V_215 ,
V_45 -> V_214 , V_45 -> V_95 , V_210 ,
& V_45 -> V_186 ) ;
if ( ! F_23 ( V_211 ) ) {
V_207 -> V_84 -> V_221 ( V_207 , V_211 ,
V_45 -> V_187 , V_45 -> V_188 ,
& V_45 -> V_187 , & V_45 -> V_188 ) ;
V_45 -> V_211 = V_211 ;
}
}
F_66 ( V_25 ) ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
V_136 = V_45 -> V_16 -> V_162 . V_190 ;
if ( V_45 -> V_145 & V_189 && V_136 ) {
V_45 -> V_222 . V_223 = F_34 ;
V_45 -> V_222 . V_81 = F_62 ( V_136 ) ;
V_45 -> V_59 -> V_79 = & V_45 -> V_222 ;
F_68 ( V_45 -> V_59 ) ;
}
F_40 ( V_45 ) ;
if ( V_45 -> V_224 ) {
V_45 -> V_224 -> V_225 . V_226 = V_227 ;
F_69 ( V_45 -> V_224 ) ;
}
}
return 0 ;
}
static void F_70 ( struct V_24 * V_25 )
{
struct V_14 * V_45 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ ) {
V_45 = & V_25 -> V_45 [ V_122 ] ;
if ( ! V_45 -> V_127 )
continue;
if ( V_45 -> V_59 && V_45 -> V_59 -> V_79 ) {
V_45 -> V_129 = 0 ;
F_39 ( & V_45 -> V_59 -> V_80 , 0 ) ;
F_71 ( V_45 -> V_130 , V_45 -> V_129 ) ;
F_72 ( V_45 -> V_59 ) ;
V_45 -> V_59 -> V_79 = NULL ;
F_12 ( V_25 ) ;
}
if ( V_45 -> V_224 ) {
V_45 -> V_224 -> V_225 . V_226 = V_228 ;
F_69 ( V_45 -> V_224 ) ;
}
F_41 ( V_45 ) ;
if ( V_45 -> V_211 ) {
struct V_206 * V_207 ;
V_207 = V_25 -> V_31 ;
V_207 -> V_84 -> V_216 ( V_207 , V_45 -> V_211 ) ;
V_45 -> V_211 = 0 ;
}
}
if ( V_25 -> V_205 ) {
F_63 ( V_25 , 0 ) ;
V_25 -> V_205 = 0 ;
}
for ( V_122 = 0 ; V_122 < F_54 ( V_25 -> V_45 ) ; V_122 ++ )
if ( V_25 -> V_45 [ V_122 ] . V_127 )
F_16 ( V_25 ) ;
}
static int F_73 ( T_3 V_229 ,
T_3 V_230 , T_3 V_231 , T_3 V_232 ,
T_3 V_233 , struct V_58 * V_59 )
{
T_1 * V_234 = V_59 -> V_235 ;
if ( V_229 >= V_236 )
return - V_43 ;
V_230 >>= 16 - V_59 -> V_101 . V_230 . V_237 ;
V_231 >>= 16 - V_59 -> V_101 . V_231 . V_237 ;
V_232 >>= 16 - V_59 -> V_101 . V_232 . V_237 ;
V_233 >>= 16 - V_59 -> V_101 . V_233 . V_237 ;
V_234 [ V_229 ] = ( V_230 << V_59 -> V_101 . V_230 . V_238 ) |
( V_231 << V_59 -> V_101 . V_231 . V_238 ) |
( V_232 << V_59 -> V_101 . V_232 . V_238 ) |
( V_233 << V_59 -> V_101 . V_233 . V_238 ) ;
return 0 ;
}
static void F_74 ( struct V_58 * V_59 ,
const struct V_239 * V_240 )
{
F_75 ( V_59 , V_240 ) ;
F_38 ( V_59 ) ;
}
static void F_76 ( struct V_58 * V_59 ,
const struct V_241 * V_242 )
{
F_77 ( V_59 , V_242 ) ;
F_38 ( V_59 ) ;
}
static void F_78 ( struct V_58 * V_59 ,
const struct V_243 * V_244 )
{
F_79 ( V_59 , V_244 ) ;
F_38 ( V_59 ) ;
}
static int F_80 ( struct V_100 * V_101 ,
struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_25 = V_45 -> V_19 ;
unsigned long V_245 ;
unsigned long V_246 ;
unsigned long V_187 , V_188 ;
unsigned long V_247 ;
if ( ! V_45 -> V_178 -> V_180 )
V_246 = V_101 -> V_248 * V_45 -> V_214
+ V_101 -> V_249 * ( V_45 -> V_178 -> V_250 / 8 ) ;
else
V_246 = V_101 -> V_248 * V_45 -> V_214 + V_101 -> V_249 ;
if ( V_246 == V_45 -> V_251 )
return 0 ;
V_245 = F_9 ( V_25 , V_252 ) ;
V_187 = V_45 -> V_212 + V_246 ;
if ( V_45 -> V_178 -> V_180 ) {
V_247 = V_101 -> V_248 * V_45 -> V_214
* ( V_45 -> V_178 -> V_250 - 8 ) / 8 ;
V_188 = V_45 -> V_212 + V_45 -> V_94 * V_45 -> V_213
+ V_247 ;
if ( V_45 -> V_178 -> V_113 == V_200 )
V_188 += 2 * V_101 -> V_249 ;
else
V_188 += V_101 -> V_249 ;
}
if ( V_45 -> V_211 ) {
struct V_206 * V_207 ;
V_207 = V_25 -> V_31 ;
V_207 -> V_84 -> V_221 ( V_207 , V_45 -> V_211 ,
V_187 , V_188 ,
& V_187 , & V_188 ) ;
}
V_45 -> V_187 = V_187 ;
V_45 -> V_188 = V_188 ;
F_5 ( V_45 , V_7 , V_187 ) ;
if ( V_45 -> V_178 -> V_180 )
F_5 ( V_45 , V_8 , V_188 ) ;
if ( F_2 ( V_45 ) )
F_8 ( V_45 -> V_19 , V_252 , V_245 ^ V_253 ) ;
else
F_8 ( V_45 -> V_19 , V_252 , V_245 ^ V_254 ) ;
V_45 -> V_251 = V_246 ;
F_38 ( V_59 ) ;
return 0 ;
}
static int F_81 ( struct V_58 * V_59 , unsigned int V_255 ,
unsigned long V_256 )
{
int V_257 ;
switch ( V_255 ) {
case V_258 :
V_257 = F_60 ( V_59 -> V_62 ) ;
break;
default:
V_257 = - V_259 ;
break;
}
return V_257 ;
}
static void F_82 ( struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_100 V_101 ;
struct V_90 V_93 ;
struct V_260 V_97 ;
int V_261 = V_262 ;
if ( V_45 -> V_263 > 1 || ( V_45 -> V_263 == 1 && ! V_59 -> V_264 ) )
return;
F_83 ( & V_93 , & V_59 -> V_101 ) ;
if ( F_44 ( & V_45 -> V_92 . V_93 , & V_93 ) )
return;
V_101 = V_59 -> V_101 ;
F_51 ( & V_101 , & V_45 -> V_92 . V_93 ) ;
V_101 . V_103 = V_45 -> V_92 . V_103 ;
V_101 . V_105 = V_45 -> V_92 . V_105 ;
V_101 . V_265 = V_266 ;
if ( F_84 ( V_59 , & V_101 ) < 0 )
return;
V_97 . V_59 = V_59 ;
V_97 . V_18 = & V_45 -> V_92 . V_93 ;
F_85 ( V_261 , & V_97 ) ;
}
static int F_86 ( struct V_58 * V_59 , int V_267 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
F_87 ( & V_45 -> V_268 ) ;
F_43 ( V_59 -> V_30 , L_6 , V_269 , V_45 -> V_263 ) ;
V_45 -> V_263 -- ;
if ( V_267 ) {
F_47 () ;
F_82 ( V_59 ) ;
F_49 () ;
}
F_88 ( & V_45 -> V_268 ) ;
return 0 ;
}
static int F_89 ( struct V_58 * V_59 , int V_267 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
F_87 ( & V_45 -> V_268 ) ;
V_45 -> V_263 ++ ;
F_43 ( V_59 -> V_30 , L_6 , V_269 , V_45 -> V_263 ) ;
F_88 ( & V_45 -> V_268 ) ;
return 0 ;
}
static int F_52 ( struct V_100 * V_101 , struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_270 = V_45 -> V_19 ;
unsigned int V_271 = ( unsigned int ) - 1 ;
unsigned int V_272 = 0 ;
unsigned int V_273 = 0 ;
unsigned int V_114 ;
if ( V_101 -> V_94 > V_274 || V_101 -> V_95 > V_275 )
return - V_43 ;
for ( V_114 = 0 ; V_114 < V_45 -> V_16 -> V_276 ; ++ V_114 ) {
const struct V_90 * V_93 = & V_45 -> V_16 -> V_277 [ V_114 ] ;
unsigned int V_278 ;
if ( V_101 -> V_94 > V_93 -> V_94 || V_101 -> V_95 > V_93 -> V_95 )
continue;
V_278 = V_101 -> V_94 * V_101 -> V_95 + V_93 -> V_94 * V_93 -> V_95
- 2 * F_65 ( V_101 -> V_94 , V_93 -> V_94 )
* F_65 ( V_101 -> V_95 , V_93 -> V_95 ) ;
if ( V_278 < V_271 ) {
V_272 = V_93 -> V_94 ;
V_273 = V_93 -> V_95 ;
V_271 = V_278 ;
}
}
if ( V_45 -> V_16 -> V_276 != 0 ) {
if ( V_271 == ( unsigned int ) - 1 )
return - V_43 ;
V_101 -> V_94 = V_272 ;
V_101 -> V_95 = V_273 ;
}
if ( V_101 -> V_279 < V_101 -> V_94 )
V_101 -> V_279 = V_101 -> V_94 ;
if ( V_101 -> V_213 < V_101 -> V_95 )
V_101 -> V_213 = V_101 -> V_95 ;
if ( F_56 ( V_101 ) ) {
const struct V_112 * V_178 ;
V_178 = F_53 ( V_101 -> V_111 ) ;
if ( V_178 == NULL )
return - V_43 ;
V_101 -> V_110 = V_178 -> V_250 ;
if ( ! V_178 -> V_180 )
V_101 -> V_181 = V_280 ;
else if ( V_101 -> V_181 != V_182 )
V_101 -> V_181 = V_184 ;
} else {
if ( V_101 -> V_110 <= 16 ) {
V_101 -> V_110 = 16 ;
V_101 -> V_230 . V_238 = 11 ;
V_101 -> V_230 . V_237 = 5 ;
V_101 -> V_231 . V_238 = 5 ;
V_101 -> V_231 . V_237 = 6 ;
V_101 -> V_232 . V_238 = 0 ;
V_101 -> V_232 . V_237 = 5 ;
V_101 -> V_233 . V_238 = 0 ;
V_101 -> V_233 . V_237 = 0 ;
} else if ( V_101 -> V_110 <= 24 ) {
V_101 -> V_110 = 24 ;
V_101 -> V_230 . V_238 = 16 ;
V_101 -> V_230 . V_237 = 8 ;
V_101 -> V_231 . V_238 = 8 ;
V_101 -> V_231 . V_237 = 8 ;
V_101 -> V_232 . V_238 = 0 ;
V_101 -> V_232 . V_237 = 8 ;
V_101 -> V_233 . V_238 = 0 ;
V_101 -> V_233 . V_237 = 0 ;
} else if ( V_101 -> V_110 <= 32 ) {
V_101 -> V_110 = 32 ;
V_101 -> V_230 . V_238 = 16 ;
V_101 -> V_230 . V_237 = 8 ;
V_101 -> V_231 . V_238 = 8 ;
V_101 -> V_231 . V_237 = 8 ;
V_101 -> V_232 . V_238 = 0 ;
V_101 -> V_232 . V_237 = 8 ;
V_101 -> V_233 . V_238 = 24 ;
V_101 -> V_233 . V_237 = 8 ;
} else
return - V_43 ;
V_101 -> V_230 . V_281 = 0 ;
V_101 -> V_231 . V_281 = 0 ;
V_101 -> V_232 . V_281 = 0 ;
V_101 -> V_233 . V_281 = 0 ;
}
if ( V_101 -> V_279 * V_101 -> V_213 * V_101 -> V_110 / 8 >
V_59 -> V_282 . V_283 )
return - V_43 ;
if ( V_270 -> V_284 &&
V_270 -> V_284 != F_55 ( V_101 ) )
return - V_43 ;
return 0 ;
}
static int F_90 ( struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
int V_83 ;
F_70 ( V_45 -> V_19 ) ;
V_45 -> V_178 = F_53 ( F_55 ( & V_59 -> V_101 ) ) ;
V_45 -> V_181 = V_59 -> V_101 . V_181 ;
V_45 -> V_94 = V_59 -> V_101 . V_94 ;
V_45 -> V_279 = V_59 -> V_101 . V_279 ;
V_45 -> V_95 = V_59 -> V_101 . V_95 ;
V_45 -> V_213 = V_59 -> V_101 . V_213 ;
if ( V_45 -> V_178 -> V_180 )
V_45 -> V_214 = V_59 -> V_101 . V_94 ;
else
V_45 -> V_214 = V_59 -> V_101 . V_94 * V_45 -> V_178 -> V_250 / 8 ;
V_83 = F_67 ( V_45 -> V_19 ) ;
if ( V_83 < 0 )
F_24 ( V_59 -> V_30 , L_7 , V_269 ) ;
V_59 -> V_282 . V_285 = V_45 -> V_214 ;
if ( F_56 ( & V_59 -> V_101 ) ) {
V_59 -> V_282 . type = V_286 ;
V_59 -> V_282 . V_287 = V_288 ;
} else {
V_59 -> V_282 . type = V_289 ;
V_59 -> V_282 . V_287 = V_290 ;
}
return V_83 ;
}
static int F_91 ( int V_291 , struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_270 = V_45 -> V_19 ;
if ( V_291 > V_227 && V_45 -> V_292 == V_227 ) {
struct V_239 V_240 = {
. V_103 = V_45 -> V_94 ,
. V_105 = V_45 -> V_95 ,
} ;
F_74 ( V_59 , & V_240 ) ;
}
if ( V_291 <= V_293 && V_45 -> V_292 > V_293 ) {
F_12 ( V_270 ) ;
}
if ( V_291 > V_293 && V_45 -> V_292 <= V_293 ) {
if ( ! V_59 -> V_79 ) {
F_60 ( V_45 ) ;
F_60 ( V_45 ) ;
}
F_16 ( V_270 ) ;
}
V_45 -> V_292 = V_291 ;
return 0 ;
}
static void
F_92 ( struct V_14 * V_45 )
{
if ( V_45 -> V_59 && V_45 -> V_59 -> V_30 )
F_93 ( V_45 -> V_59 ) ;
}
static int T_4
F_94 ( struct V_14 * V_45 )
{
struct V_58 * V_59 = V_45 -> V_59 ;
int V_83 ;
if ( V_59 -> V_79 ) {
V_45 -> V_68 = F_95 ( sizeof( struct V_294 ) *
V_45 -> V_64 >> V_65 ) ;
if ( ! V_45 -> V_68 ) {
F_24 ( V_45 -> V_19 -> V_30 , L_8 ) ;
return - V_295 ;
}
}
V_59 -> V_296 = V_45 -> V_224 ;
V_83 = F_96 ( V_59 ) ;
if ( V_83 < 0 )
return V_83 ;
F_97 ( V_45 -> V_19 -> V_30 , L_9 ,
F_98 ( V_45 -> V_19 -> V_30 ) , ( V_45 -> V_16 -> V_15 == V_297 ) ?
L_10 : L_11 , V_59 -> V_101 . V_94 , V_59 -> V_101 . V_95 ,
V_59 -> V_101 . V_110 ) ;
if ( V_59 -> V_79 || V_59 -> V_87 == V_88 )
F_16 ( V_45 -> V_19 ) ;
return V_83 ;
}
static void
F_99 ( struct V_14 * V_45 )
{
struct V_58 * V_59 = V_45 -> V_59 ;
if ( ! V_59 || ! V_59 -> V_298 )
return;
if ( V_45 -> V_68 )
F_100 ( V_45 -> V_68 ) ;
F_101 ( & V_59 -> V_299 ) ;
F_102 ( V_59 ) ;
}
static int T_4
F_103 ( struct V_14 * V_45 ,
const struct V_90 * V_93 ,
unsigned int V_276 )
{
struct V_24 * V_25 = V_45 -> V_19 ;
struct V_100 * V_101 ;
struct V_58 * V_59 ;
int V_83 ;
V_59 = F_104 ( 0 , V_25 -> V_30 ) ;
if ( V_59 == NULL ) {
F_24 ( V_25 -> V_30 , L_12 ) ;
return - V_295 ;
}
V_45 -> V_59 = V_59 ;
V_59 -> V_151 = V_300 ;
V_59 -> V_301 = & V_302 ;
V_59 -> V_298 = V_25 -> V_30 ;
V_59 -> V_303 = V_45 -> V_304 ;
V_59 -> V_235 = & V_45 -> V_235 ;
V_59 -> V_62 = V_45 ;
F_105 ( V_93 , V_276 , & V_59 -> V_305 ) ;
V_83 = F_106 ( & V_59 -> V_299 , V_236 , 0 ) ;
if ( V_83 < 0 ) {
F_24 ( V_25 -> V_30 , L_13 ) ;
return V_83 ;
}
V_59 -> V_282 = V_306 ;
V_59 -> V_282 . V_307 = V_45 -> V_212 ;
V_59 -> V_282 . V_283 = V_45 -> V_64 ;
V_59 -> V_282 . V_285 = V_45 -> V_214 ;
if ( V_45 -> V_178 -> V_180 )
V_59 -> V_282 . V_287 = V_288 ;
else
V_59 -> V_282 . V_287 = V_290 ;
if ( V_45 -> V_178 -> V_113 == V_198 ||
V_45 -> V_178 -> V_113 == V_193 )
V_59 -> V_282 . V_308 = 2 ;
V_101 = & V_59 -> V_101 ;
F_51 ( V_101 , V_93 ) ;
V_101 -> V_103 = V_45 -> V_16 -> V_72 . V_103 ;
V_101 -> V_105 = V_45 -> V_16 -> V_72 . V_105 ;
V_101 -> V_213 = V_101 -> V_95 * 2 ;
V_101 -> V_265 = V_266 ;
if ( ! V_45 -> V_178 -> V_180 )
V_101 -> V_110 = V_45 -> V_178 -> V_250 ;
else
V_101 -> V_111 = V_45 -> V_178 -> V_113 ;
V_83 = F_52 ( V_101 , V_59 ) ;
if ( V_83 )
return V_83 ;
return 0 ;
}
static int F_107 ( struct V_309 * V_310 )
{
struct V_14 * V_45 = F_108 ( V_310 ) ;
int V_311 = V_310 -> V_225 . V_311 ;
if ( V_310 -> V_225 . V_226 != V_227 ||
V_310 -> V_225 . V_87 & ( V_312 | V_313 ) )
V_311 = 0 ;
return V_45 -> V_16 -> V_314 . V_315 ( V_311 ) ;
}
static int F_109 ( struct V_309 * V_310 )
{
struct V_14 * V_45 = F_108 ( V_310 ) ;
return V_45 -> V_16 -> V_314 . V_316 () ;
}
static int F_110 ( struct V_309 * V_310 ,
struct V_58 * V_59 )
{
return ( V_59 -> V_296 == V_310 ) ;
}
static struct V_309 * F_111 ( struct V_298 * V_317 ,
struct V_14 * V_45 )
{
struct V_309 * V_224 ;
V_224 = F_112 ( V_45 -> V_16 -> V_314 . V_318 , V_317 , V_45 ,
& V_319 , NULL ) ;
if ( F_23 ( V_224 ) ) {
F_24 ( V_317 , L_14 ,
F_25 ( V_224 ) ) ;
return NULL ;
}
V_224 -> V_225 . V_320 = V_45 -> V_16 -> V_314 . V_320 ;
V_224 -> V_225 . V_311 = V_224 -> V_225 . V_320 ;
F_69 ( V_224 ) ;
return V_224 ;
}
static void F_113 ( struct V_309 * V_310 )
{
F_114 ( V_310 ) ;
}
static int F_115 ( struct V_298 * V_30 )
{
struct V_321 * V_32 = F_116 ( V_30 ) ;
F_70 ( F_117 ( V_32 ) ) ;
return 0 ;
}
static int F_118 ( struct V_298 * V_30 )
{
struct V_321 * V_32 = F_116 ( V_30 ) ;
return F_67 ( F_117 ( V_32 ) ) ;
}
static int F_119 ( struct V_298 * V_30 )
{
struct V_321 * V_32 = F_116 ( V_30 ) ;
struct V_24 * V_25 = F_117 ( V_32 ) ;
F_8 ( V_25 , V_203 , 0 ) ;
return 0 ;
}
static int F_120 ( struct V_298 * V_30 )
{
struct V_321 * V_32 = F_116 ( V_30 ) ;
struct V_24 * V_25 = F_117 ( V_32 ) ;
F_66 ( V_25 ) ;
return 0 ;
}
static int F_121 ( struct V_322 * V_323 ,
unsigned long V_324 , void * V_18 )
{
struct V_260 * V_97 = V_18 ;
struct V_58 * V_59 = V_97 -> V_59 ;
struct V_14 * V_45 = V_59 -> V_62 ;
if ( & V_45 -> V_19 -> V_325 != V_323 )
return V_326 ;
F_43 ( V_59 -> V_30 , L_15 ,
V_269 , V_324 , V_97 -> V_18 ) ;
switch( V_324 ) {
case V_327 :
F_41 ( V_45 ) ;
F_70 ( V_45 -> V_19 ) ;
break;
case V_328 :
F_87 ( & V_45 -> V_268 ) ;
F_82 ( V_59 ) ;
F_88 ( & V_45 -> V_268 ) ;
F_40 ( V_45 ) ;
F_67 ( V_45 -> V_19 ) ;
}
return V_329 ;
}
static int F_122 ( struct V_321 * V_32 )
{
struct V_24 * V_25 = F_117 ( V_32 ) ;
int V_114 ;
F_123 ( & V_25 -> V_325 ) ;
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ )
F_92 ( & V_25 -> V_45 [ V_114 ] ) ;
F_70 ( V_25 ) ;
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ ) {
struct V_14 * V_45 = & V_25 -> V_45 [ V_114 ] ;
if ( V_45 -> V_82 ) {
V_45 -> V_82 -> V_19 = NULL ;
F_124 ( V_45 -> V_16 -> V_82 -> V_30 . V_330 -> V_331 ) ;
}
F_99 ( V_45 ) ;
if ( V_45 -> V_304 )
F_125 ( & V_32 -> V_30 , V_45 -> V_64 ,
V_45 -> V_304 , V_45 -> V_212 ) ;
}
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ ) {
if ( V_25 -> V_45 [ V_114 ] . V_224 )
F_113 ( V_25 -> V_45 [ V_114 ] . V_224 ) ;
}
if ( V_25 -> V_29 ) {
F_126 ( & V_32 -> V_30 ) ;
F_127 ( V_25 -> V_29 ) ;
}
if ( V_25 -> V_20 )
F_128 ( V_25 -> V_20 ) ;
if ( V_25 -> V_119 )
F_129 ( V_25 -> V_119 , V_25 ) ;
F_130 ( V_25 ) ;
return 0 ;
}
static int T_4 F_131 ( struct V_14 * V_45 )
{
int V_332 = V_45 -> V_16 -> V_332 ;
switch ( V_332 ) {
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
break;
default:
return - V_43 ;
}
if ( F_2 ( V_45 ) ) {
if ( ! ( V_332 & V_189 ) )
return - V_43 ;
V_332 &= ~ V_189 ;
}
V_45 -> V_145 = V_332 ;
return 0 ;
}
static int T_4
F_132 ( struct V_24 * V_25 ,
struct V_14 * V_45 )
{
const struct V_112 * V_178 ;
const struct V_351 * V_16 = V_45 -> V_16 ;
const struct V_90 * V_352 ;
const struct V_90 * V_93 ;
unsigned int V_276 ;
unsigned int V_353 ;
unsigned int V_114 ;
F_133 ( & V_45 -> V_268 ) ;
V_45 -> V_354 = F_45 ;
V_178 = F_53 ( V_16 -> V_113 ) ;
if ( V_178 == NULL ) {
F_24 ( V_25 -> V_30 , L_16 , V_16 -> V_113 ) ;
return - V_43 ;
}
V_352 = NULL ;
V_353 = 0 ;
for ( V_114 = 0 , V_93 = V_16 -> V_277 ; V_114 < V_16 -> V_276 ; V_114 ++ , V_93 ++ ) {
unsigned int V_355 = V_93 -> V_95 * V_93 -> V_94 ;
if ( ( V_16 -> V_113 == V_198 ||
V_16 -> V_113 == V_193 ) && ( V_93 -> V_95 & 0x1 ) ) {
F_24 ( V_25 -> V_30 , L_17
L_18 ) ;
return - V_43 ;
}
if ( V_355 > V_353 ) {
V_352 = V_93 ;
V_353 = V_355 ;
}
}
if ( ! V_353 )
V_353 = V_274 * V_275 ;
else
F_43 ( V_25 -> V_30 , L_19 ,
V_352 -> V_94 , V_352 -> V_95 ) ;
if ( V_16 -> V_277 == NULL ) {
V_93 = & V_356 ;
V_276 = 1 ;
} else {
V_93 = V_16 -> V_277 ;
V_276 = V_16 -> V_276 ;
}
V_45 -> V_178 = V_178 ;
V_45 -> V_94 = V_93 -> V_94 ;
V_45 -> V_279 = V_93 -> V_94 ;
V_45 -> V_95 = V_93 -> V_95 ;
V_45 -> V_213 = V_93 -> V_95 * 2 ;
if ( ! V_178 -> V_180 ) {
V_45 -> V_181 = V_280 ;
V_45 -> V_214 = V_45 -> V_94 * V_178 -> V_250 / 8 ;
} else {
V_45 -> V_181 = V_182 ;
V_45 -> V_214 = V_45 -> V_94 ;
}
V_45 -> V_92 . V_103 = V_16 -> V_72 . V_103 ;
V_45 -> V_92 . V_105 = V_16 -> V_72 . V_105 ;
V_45 -> V_92 . V_93 = * V_93 ;
V_45 -> V_64 = V_353 * V_178 -> V_250 / 8 * 2 ;
V_45 -> V_304 = F_134 ( V_25 -> V_30 , V_45 -> V_64 , & V_45 -> V_212 ,
V_357 ) ;
if ( V_45 -> V_304 == NULL ) {
F_24 ( V_25 -> V_30 , L_20 ) ;
return - V_295 ;
}
if ( V_16 -> V_82 ) {
if ( ! V_16 -> V_82 -> V_30 . V_330 ||
! F_135 ( V_16 -> V_82 -> V_30 . V_330 -> V_331 ) ) {
F_136 ( V_25 -> V_30 ,
L_21 ) ;
return - V_43 ;
}
V_45 -> V_82 = F_117 ( V_16 -> V_82 ) ;
V_45 -> V_82 -> V_19 = V_45 ;
V_45 -> V_82 -> V_358 = * V_93 ;
}
return F_103 ( V_45 , V_93 , V_276 ) ;
}
static int T_4 F_137 ( struct V_321 * V_32 )
{
struct V_359 * V_360 = V_32 -> V_30 . V_361 ;
struct V_24 * V_25 ;
struct V_362 * V_363 ;
int V_364 ;
int error ;
int V_114 ;
if ( ! V_360 ) {
F_24 ( & V_32 -> V_30 , L_22 ) ;
return - V_43 ;
}
V_363 = F_138 ( V_32 , V_365 , 0 ) ;
V_114 = F_139 ( V_32 , 0 ) ;
if ( ! V_363 || V_114 < 0 ) {
F_24 ( & V_32 -> V_30 , L_23 ) ;
return - V_366 ;
}
V_25 = F_140 ( sizeof( * V_25 ) , V_357 ) ;
if ( ! V_25 ) {
F_24 ( & V_32 -> V_30 , L_24 ) ;
return - V_295 ;
}
V_25 -> V_30 = & V_32 -> V_30 ;
V_25 -> V_31 = V_360 -> V_31 ;
F_141 ( V_32 , V_25 ) ;
error = F_142 ( V_114 , F_57 , 0 ,
F_98 ( & V_32 -> V_30 ) , V_25 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_25 ) ;
goto V_367;
}
V_25 -> V_119 = V_114 ;
F_143 ( & V_25 -> V_28 , - 1 ) ;
for ( V_114 = 0 , V_364 = 0 ; V_114 < F_54 ( V_360 -> V_45 ) ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_364 ;
V_45 -> V_19 = V_25 ;
V_45 -> V_16 = & V_360 -> V_45 [ V_114 ] ;
error = F_131 ( V_45 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_26 ) ;
goto V_367;
}
F_144 ( & V_45 -> V_130 ) ;
F_145 ( & V_45 -> V_132 ) ;
V_45 -> V_251 = 0 ;
if ( V_45 -> V_16 -> V_314 . V_320 )
V_45 -> V_224 = F_111 ( & V_32 -> V_30 , V_45 ) ;
switch ( V_360 -> V_45 [ V_114 ] . V_15 ) {
case V_297 :
V_45 -> V_127 = V_368 ;
V_45 -> V_21 = V_369 ;
V_364 ++ ;
break;
case V_17 :
V_45 -> V_127 = V_370 ;
V_45 -> V_21 = V_371 ;
V_364 ++ ;
break;
}
}
if ( ! V_364 ) {
F_24 ( & V_32 -> V_30 , L_27 ) ;
error = - V_43 ;
goto V_367;
}
if ( V_364 == 2 )
V_25 -> V_284 = V_360 -> V_45 [ 0 ] . V_113 ;
V_25 -> V_20 = F_146 ( V_363 -> V_135 , F_147 ( V_363 ) ) ;
if ( ! V_25 -> V_20 )
goto V_367;
error = F_21 ( V_25 , V_360 -> V_33 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_28 ) ;
goto V_367;
}
F_148 ( & V_32 -> V_30 ) ;
for ( V_114 = 0 ; V_114 < V_364 ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_114 ;
error = F_132 ( V_25 , V_45 ) ;
if ( error )
goto V_367;
}
error = F_67 ( V_25 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_29 ) ;
goto V_367;
}
for ( V_114 = 0 ; V_114 < V_364 ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_114 ;
error = F_94 ( V_45 ) ;
if ( error )
goto V_367;
}
V_25 -> V_325 . V_372 = F_121 ;
F_149 ( & V_25 -> V_325 ) ;
return 0 ;
V_367:
F_122 ( V_32 ) ;
return error ;
}
