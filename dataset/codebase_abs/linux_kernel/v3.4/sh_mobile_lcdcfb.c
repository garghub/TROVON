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
if ( V_207 == NULL || V_207 -> V_84 == NULL ||
V_45 -> V_16 -> V_214 == NULL )
continue;
if ( V_45 -> V_211 ) {
V_207 -> V_84 -> V_215 ( V_207 , V_45 -> V_211 ) ;
V_45 -> V_211 = NULL ;
}
switch ( V_45 -> V_178 -> V_113 ) {
case V_198 :
case V_193 :
case V_199 :
case V_194 :
V_210 = V_216 ;
break;
case V_200 :
case V_195 :
V_210 = V_217 ;
break;
case V_116 :
case V_117 :
case V_118 :
default:
V_210 = V_218 ;
break;
}
V_211 = V_207 -> V_84 -> V_219 ( V_207 , V_45 -> V_16 -> V_214 ,
V_45 -> V_186 , V_45 -> V_95 , V_210 ,
& V_45 -> V_186 ) ;
if ( ! F_23 ( V_211 ) ) {
V_207 -> V_84 -> V_220 ( V_207 , V_211 ,
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
V_45 -> V_221 . V_222 = F_34 ;
V_45 -> V_221 . V_81 = F_62 ( V_136 ) ;
V_45 -> V_59 -> V_79 = & V_45 -> V_221 ;
F_68 ( V_45 -> V_59 ) ;
}
F_40 ( V_45 ) ;
if ( V_45 -> V_223 ) {
V_45 -> V_223 -> V_224 . V_225 = V_226 ;
F_69 ( V_45 -> V_223 ) ;
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
if ( V_45 -> V_223 ) {
V_45 -> V_223 -> V_224 . V_225 = V_227 ;
F_69 ( V_45 -> V_223 ) ;
}
F_41 ( V_45 ) ;
if ( V_45 -> V_211 ) {
struct V_206 * V_207 ;
V_207 = V_25 -> V_31 ;
V_207 -> V_84 -> V_215 ( V_207 , V_45 -> V_211 ) ;
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
static int F_73 ( T_3 V_228 ,
T_3 V_229 , T_3 V_230 , T_3 V_231 ,
T_3 V_232 , struct V_58 * V_59 )
{
T_1 * V_233 = V_59 -> V_234 ;
if ( V_228 >= V_235 )
return - V_43 ;
V_229 >>= 16 - V_59 -> V_101 . V_229 . V_236 ;
V_230 >>= 16 - V_59 -> V_101 . V_230 . V_236 ;
V_231 >>= 16 - V_59 -> V_101 . V_231 . V_236 ;
V_232 >>= 16 - V_59 -> V_101 . V_232 . V_236 ;
V_233 [ V_228 ] = ( V_229 << V_59 -> V_101 . V_229 . V_237 ) |
( V_230 << V_59 -> V_101 . V_230 . V_237 ) |
( V_231 << V_59 -> V_101 . V_231 . V_237 ) |
( V_232 << V_59 -> V_101 . V_232 . V_237 ) ;
return 0 ;
}
static void F_74 ( struct V_58 * V_59 ,
const struct V_238 * V_239 )
{
F_75 ( V_59 , V_239 ) ;
F_38 ( V_59 ) ;
}
static void F_76 ( struct V_58 * V_59 ,
const struct V_240 * V_241 )
{
F_77 ( V_59 , V_241 ) ;
F_38 ( V_59 ) ;
}
static void F_78 ( struct V_58 * V_59 ,
const struct V_242 * V_243 )
{
F_79 ( V_59 , V_243 ) ;
F_38 ( V_59 ) ;
}
static int F_80 ( struct V_100 * V_101 ,
struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_25 = V_45 -> V_19 ;
unsigned long V_244 ;
unsigned long V_245 ;
unsigned long V_187 , V_188 ;
unsigned long V_246 ;
if ( ! V_45 -> V_178 -> V_180 )
V_245 = V_101 -> V_247 * V_45 -> V_186
+ V_101 -> V_248 * ( V_45 -> V_178 -> V_249 / 8 ) ;
else
V_245 = V_101 -> V_247 * V_45 -> V_186 + V_101 -> V_248 ;
if ( V_245 == V_45 -> V_250 )
return 0 ;
V_244 = F_9 ( V_25 , V_251 ) ;
V_187 = V_45 -> V_212 + V_245 ;
if ( V_45 -> V_178 -> V_180 ) {
V_246 = V_101 -> V_247 * V_45 -> V_186
* ( V_45 -> V_178 -> V_249 - 8 ) / 8 ;
V_188 = V_45 -> V_212 + V_45 -> V_94 * V_45 -> V_213
+ V_246 ;
if ( V_45 -> V_178 -> V_113 == V_200 )
V_188 += 2 * V_101 -> V_248 ;
else
V_188 += V_101 -> V_248 ;
}
if ( V_45 -> V_211 ) {
struct V_206 * V_207 ;
V_207 = V_25 -> V_31 ;
V_207 -> V_84 -> V_220 ( V_207 , V_45 -> V_211 ,
V_187 , V_188 ,
& V_187 , & V_188 ) ;
}
V_45 -> V_187 = V_187 ;
V_45 -> V_188 = V_188 ;
F_5 ( V_45 , V_7 , V_187 ) ;
if ( V_45 -> V_178 -> V_180 )
F_5 ( V_45 , V_8 , V_188 ) ;
if ( F_2 ( V_45 ) )
F_8 ( V_45 -> V_19 , V_251 , V_244 ^ V_252 ) ;
else
F_8 ( V_45 -> V_19 , V_251 , V_244 ^ V_253 ) ;
V_45 -> V_250 = V_245 ;
F_38 ( V_59 ) ;
return 0 ;
}
static int F_81 ( struct V_58 * V_59 , unsigned int V_254 ,
unsigned long V_255 )
{
int V_256 ;
switch ( V_254 ) {
case V_257 :
V_256 = F_60 ( V_59 -> V_62 ) ;
break;
default:
V_256 = - V_258 ;
break;
}
return V_256 ;
}
static void F_82 ( struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_100 V_101 ;
struct V_90 V_93 ;
struct V_259 V_97 ;
int V_260 = V_261 ;
if ( V_45 -> V_262 > 1 || ( V_45 -> V_262 == 1 && ! V_59 -> V_263 ) )
return;
F_83 ( & V_93 , & V_59 -> V_101 ) ;
if ( F_44 ( & V_45 -> V_92 . V_93 , & V_93 ) )
return;
V_101 = V_59 -> V_101 ;
F_51 ( & V_101 , & V_45 -> V_92 . V_93 ) ;
V_101 . V_103 = V_45 -> V_92 . V_103 ;
V_101 . V_105 = V_45 -> V_92 . V_105 ;
V_101 . V_264 = V_265 ;
if ( F_84 ( V_59 , & V_101 ) < 0 )
return;
V_97 . V_59 = V_59 ;
V_97 . V_18 = & V_45 -> V_92 . V_93 ;
F_85 ( V_260 , & V_97 ) ;
}
static int F_86 ( struct V_58 * V_59 , int V_266 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
F_87 ( & V_45 -> V_267 ) ;
F_43 ( V_59 -> V_30 , L_6 , V_268 , V_45 -> V_262 ) ;
V_45 -> V_262 -- ;
if ( V_266 ) {
F_47 () ;
F_82 ( V_59 ) ;
F_49 () ;
}
F_88 ( & V_45 -> V_267 ) ;
return 0 ;
}
static int F_89 ( struct V_58 * V_59 , int V_266 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
F_87 ( & V_45 -> V_267 ) ;
V_45 -> V_262 ++ ;
F_43 ( V_59 -> V_30 , L_6 , V_268 , V_45 -> V_262 ) ;
F_88 ( & V_45 -> V_267 ) ;
return 0 ;
}
static int F_52 ( struct V_100 * V_101 , struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_269 = V_45 -> V_19 ;
unsigned int V_270 = ( unsigned int ) - 1 ;
unsigned int V_271 = 0 ;
unsigned int V_272 = 0 ;
unsigned int V_114 ;
if ( V_101 -> V_94 > V_273 || V_101 -> V_95 > V_274 )
return - V_43 ;
for ( V_114 = 0 ; V_114 < V_45 -> V_16 -> V_275 ; ++ V_114 ) {
const struct V_90 * V_93 = & V_45 -> V_16 -> V_276 [ V_114 ] ;
unsigned int V_277 ;
if ( V_101 -> V_94 > V_93 -> V_94 || V_101 -> V_95 > V_93 -> V_95 )
continue;
V_277 = V_101 -> V_94 * V_101 -> V_95 + V_93 -> V_94 * V_93 -> V_95
- 2 * F_65 ( V_101 -> V_94 , V_93 -> V_94 )
* F_65 ( V_101 -> V_95 , V_93 -> V_95 ) ;
if ( V_277 < V_270 ) {
V_271 = V_93 -> V_94 ;
V_272 = V_93 -> V_95 ;
V_270 = V_277 ;
}
}
if ( V_45 -> V_16 -> V_275 != 0 ) {
if ( V_270 == ( unsigned int ) - 1 )
return - V_43 ;
V_101 -> V_94 = V_271 ;
V_101 -> V_95 = V_272 ;
}
if ( V_101 -> V_278 < V_101 -> V_94 )
V_101 -> V_278 = V_101 -> V_94 ;
if ( V_101 -> V_213 < V_101 -> V_95 )
V_101 -> V_213 = V_101 -> V_95 ;
if ( F_56 ( V_101 ) ) {
const struct V_112 * V_178 ;
V_178 = F_53 ( V_101 -> V_111 ) ;
if ( V_178 == NULL )
return - V_43 ;
V_101 -> V_110 = V_178 -> V_249 ;
if ( ! V_178 -> V_180 )
V_101 -> V_181 = V_279 ;
else if ( V_101 -> V_181 != V_182 )
V_101 -> V_181 = V_184 ;
} else {
if ( V_101 -> V_110 <= 16 ) {
V_101 -> V_110 = 16 ;
V_101 -> V_229 . V_237 = 11 ;
V_101 -> V_229 . V_236 = 5 ;
V_101 -> V_230 . V_237 = 5 ;
V_101 -> V_230 . V_236 = 6 ;
V_101 -> V_231 . V_237 = 0 ;
V_101 -> V_231 . V_236 = 5 ;
V_101 -> V_232 . V_237 = 0 ;
V_101 -> V_232 . V_236 = 0 ;
} else if ( V_101 -> V_110 <= 24 ) {
V_101 -> V_110 = 24 ;
V_101 -> V_229 . V_237 = 16 ;
V_101 -> V_229 . V_236 = 8 ;
V_101 -> V_230 . V_237 = 8 ;
V_101 -> V_230 . V_236 = 8 ;
V_101 -> V_231 . V_237 = 0 ;
V_101 -> V_231 . V_236 = 8 ;
V_101 -> V_232 . V_237 = 0 ;
V_101 -> V_232 . V_236 = 0 ;
} else if ( V_101 -> V_110 <= 32 ) {
V_101 -> V_110 = 32 ;
V_101 -> V_229 . V_237 = 16 ;
V_101 -> V_229 . V_236 = 8 ;
V_101 -> V_230 . V_237 = 8 ;
V_101 -> V_230 . V_236 = 8 ;
V_101 -> V_231 . V_237 = 0 ;
V_101 -> V_231 . V_236 = 8 ;
V_101 -> V_232 . V_237 = 24 ;
V_101 -> V_232 . V_236 = 8 ;
} else
return - V_43 ;
V_101 -> V_229 . V_280 = 0 ;
V_101 -> V_230 . V_280 = 0 ;
V_101 -> V_231 . V_280 = 0 ;
V_101 -> V_232 . V_280 = 0 ;
}
if ( V_101 -> V_278 * V_101 -> V_213 * V_101 -> V_110 / 8 >
V_59 -> V_281 . V_282 )
return - V_43 ;
if ( V_269 -> V_283 &&
V_269 -> V_283 != F_55 ( V_101 ) )
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
V_45 -> V_278 = V_59 -> V_101 . V_278 ;
V_45 -> V_95 = V_59 -> V_101 . V_95 ;
V_45 -> V_213 = V_59 -> V_101 . V_213 ;
if ( V_45 -> V_178 -> V_180 )
V_45 -> V_186 = V_59 -> V_101 . V_94 ;
else
V_45 -> V_186 = V_59 -> V_101 . V_94 * V_45 -> V_178 -> V_249 / 8 ;
V_83 = F_67 ( V_45 -> V_19 ) ;
if ( V_83 < 0 )
F_24 ( V_59 -> V_30 , L_7 , V_268 ) ;
V_59 -> V_281 . V_284 = V_45 -> V_186 ;
if ( F_56 ( & V_59 -> V_101 ) ) {
V_59 -> V_281 . type = V_285 ;
V_59 -> V_281 . V_286 = V_287 ;
} else {
V_59 -> V_281 . type = V_288 ;
V_59 -> V_281 . V_286 = V_289 ;
}
return V_83 ;
}
static int F_91 ( int V_290 , struct V_58 * V_59 )
{
struct V_14 * V_45 = V_59 -> V_62 ;
struct V_24 * V_269 = V_45 -> V_19 ;
if ( V_290 > V_226 && V_45 -> V_291 == V_226 ) {
struct V_238 V_239 = {
. V_103 = V_45 -> V_94 ,
. V_105 = V_45 -> V_95 ,
} ;
F_74 ( V_59 , & V_239 ) ;
}
if ( V_290 <= V_292 && V_45 -> V_291 > V_292 ) {
F_12 ( V_269 ) ;
}
if ( V_290 > V_292 && V_45 -> V_291 <= V_292 ) {
if ( ! V_59 -> V_79 ) {
F_60 ( V_45 ) ;
F_60 ( V_45 ) ;
}
F_16 ( V_269 ) ;
}
V_45 -> V_291 = V_290 ;
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
V_45 -> V_68 = F_95 ( sizeof( struct V_293 ) *
V_45 -> V_64 >> V_65 ) ;
if ( ! V_45 -> V_68 ) {
F_24 ( V_45 -> V_19 -> V_30 , L_8 ) ;
return - V_294 ;
}
}
V_59 -> V_295 = V_45 -> V_223 ;
V_83 = F_96 ( V_59 ) ;
if ( V_83 < 0 )
return V_83 ;
F_97 ( V_45 -> V_19 -> V_30 , L_9 ,
F_98 ( V_45 -> V_19 -> V_30 ) , ( V_45 -> V_16 -> V_15 == V_296 ) ?
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
if ( ! V_59 || ! V_59 -> V_297 )
return;
if ( V_45 -> V_68 )
F_100 ( V_45 -> V_68 ) ;
F_101 ( & V_59 -> V_298 ) ;
F_102 ( V_59 ) ;
}
static int T_4
F_103 ( struct V_14 * V_45 ,
const struct V_90 * V_93 ,
unsigned int V_275 )
{
struct V_24 * V_25 = V_45 -> V_19 ;
struct V_100 * V_101 ;
struct V_58 * V_59 ;
int V_83 ;
V_59 = F_104 ( 0 , V_25 -> V_30 ) ;
if ( V_59 == NULL ) {
F_24 ( V_25 -> V_30 , L_12 ) ;
return - V_294 ;
}
V_45 -> V_59 = V_59 ;
V_59 -> V_151 = V_299 ;
V_59 -> V_300 = & V_301 ;
V_59 -> V_297 = V_25 -> V_30 ;
V_59 -> V_302 = V_45 -> V_303 ;
V_59 -> V_234 = & V_45 -> V_234 ;
V_59 -> V_62 = V_45 ;
F_105 ( V_93 , V_275 , & V_59 -> V_304 ) ;
V_83 = F_106 ( & V_59 -> V_298 , V_235 , 0 ) ;
if ( V_83 < 0 ) {
F_24 ( V_25 -> V_30 , L_13 ) ;
return V_83 ;
}
V_59 -> V_281 = V_305 ;
V_59 -> V_281 . V_306 = V_45 -> V_212 ;
V_59 -> V_281 . V_282 = V_45 -> V_64 ;
V_59 -> V_281 . V_284 = V_45 -> V_186 ;
if ( V_45 -> V_178 -> V_180 )
V_59 -> V_281 . V_286 = V_287 ;
else
V_59 -> V_281 . V_286 = V_289 ;
if ( V_45 -> V_178 -> V_113 == V_198 ||
V_45 -> V_178 -> V_113 == V_193 )
V_59 -> V_281 . V_307 = 2 ;
V_101 = & V_59 -> V_101 ;
F_51 ( V_101 , V_93 ) ;
V_101 -> V_103 = V_45 -> V_16 -> V_72 . V_103 ;
V_101 -> V_105 = V_45 -> V_16 -> V_72 . V_105 ;
V_101 -> V_213 = V_101 -> V_95 * 2 ;
V_101 -> V_264 = V_265 ;
if ( ! V_45 -> V_178 -> V_180 )
V_101 -> V_110 = V_45 -> V_178 -> V_249 ;
else
V_101 -> V_111 = V_45 -> V_178 -> V_113 ;
V_83 = F_52 ( V_101 , V_59 ) ;
if ( V_83 )
return V_83 ;
return 0 ;
}
static int F_107 ( struct V_308 * V_309 )
{
struct V_14 * V_45 = F_108 ( V_309 ) ;
int V_310 = V_309 -> V_224 . V_310 ;
if ( V_309 -> V_224 . V_225 != V_226 ||
V_309 -> V_224 . V_87 & ( V_311 | V_312 ) )
V_310 = 0 ;
return V_45 -> V_16 -> V_313 . V_314 ( V_310 ) ;
}
static int F_109 ( struct V_308 * V_309 )
{
struct V_14 * V_45 = F_108 ( V_309 ) ;
return V_45 -> V_16 -> V_313 . V_315 () ;
}
static int F_110 ( struct V_308 * V_309 ,
struct V_58 * V_59 )
{
return ( V_59 -> V_295 == V_309 ) ;
}
static struct V_308 * F_111 ( struct V_297 * V_316 ,
struct V_14 * V_45 )
{
struct V_308 * V_223 ;
V_223 = F_112 ( V_45 -> V_16 -> V_313 . V_317 , V_316 , V_45 ,
& V_318 , NULL ) ;
if ( F_23 ( V_223 ) ) {
F_24 ( V_316 , L_14 ,
F_25 ( V_223 ) ) ;
return NULL ;
}
V_223 -> V_224 . V_319 = V_45 -> V_16 -> V_313 . V_319 ;
V_223 -> V_224 . V_310 = V_223 -> V_224 . V_319 ;
F_69 ( V_223 ) ;
return V_223 ;
}
static void F_113 ( struct V_308 * V_309 )
{
F_114 ( V_309 ) ;
}
static int F_115 ( struct V_297 * V_30 )
{
struct V_320 * V_32 = F_116 ( V_30 ) ;
F_70 ( F_117 ( V_32 ) ) ;
return 0 ;
}
static int F_118 ( struct V_297 * V_30 )
{
struct V_320 * V_32 = F_116 ( V_30 ) ;
return F_67 ( F_117 ( V_32 ) ) ;
}
static int F_119 ( struct V_297 * V_30 )
{
struct V_320 * V_32 = F_116 ( V_30 ) ;
struct V_24 * V_25 = F_117 ( V_32 ) ;
F_8 ( V_25 , V_203 , 0 ) ;
return 0 ;
}
static int F_120 ( struct V_297 * V_30 )
{
struct V_320 * V_32 = F_116 ( V_30 ) ;
struct V_24 * V_25 = F_117 ( V_32 ) ;
F_66 ( V_25 ) ;
return 0 ;
}
static int F_121 ( struct V_321 * V_322 ,
unsigned long V_323 , void * V_18 )
{
struct V_259 * V_97 = V_18 ;
struct V_58 * V_59 = V_97 -> V_59 ;
struct V_14 * V_45 = V_59 -> V_62 ;
if ( & V_45 -> V_19 -> V_324 != V_322 )
return V_325 ;
F_43 ( V_59 -> V_30 , L_15 ,
V_268 , V_323 , V_97 -> V_18 ) ;
switch( V_323 ) {
case V_326 :
F_41 ( V_45 ) ;
F_70 ( V_45 -> V_19 ) ;
break;
case V_327 :
F_87 ( & V_45 -> V_267 ) ;
F_82 ( V_59 ) ;
F_88 ( & V_45 -> V_267 ) ;
F_40 ( V_45 ) ;
F_67 ( V_45 -> V_19 ) ;
}
return V_328 ;
}
static int F_122 ( struct V_320 * V_32 )
{
struct V_24 * V_25 = F_117 ( V_32 ) ;
int V_114 ;
F_123 ( & V_25 -> V_324 ) ;
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ )
F_92 ( & V_25 -> V_45 [ V_114 ] ) ;
F_70 ( V_25 ) ;
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ ) {
struct V_14 * V_45 = & V_25 -> V_45 [ V_114 ] ;
if ( V_45 -> V_82 ) {
V_45 -> V_82 -> V_19 = NULL ;
F_124 ( V_45 -> V_16 -> V_82 -> V_30 . V_329 -> V_330 ) ;
}
F_99 ( V_45 ) ;
if ( V_45 -> V_303 )
F_125 ( & V_32 -> V_30 , V_45 -> V_64 ,
V_45 -> V_303 , V_45 -> V_212 ) ;
}
for ( V_114 = 0 ; V_114 < F_54 ( V_25 -> V_45 ) ; V_114 ++ ) {
if ( V_25 -> V_45 [ V_114 ] . V_223 )
F_113 ( V_25 -> V_45 [ V_114 ] . V_223 ) ;
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
int V_331 = V_45 -> V_16 -> V_331 ;
switch ( V_331 ) {
case V_332 :
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
break;
default:
return - V_43 ;
}
if ( F_2 ( V_45 ) ) {
if ( ! ( V_331 & V_189 ) )
return - V_43 ;
V_331 &= ~ V_189 ;
}
V_45 -> V_145 = V_331 ;
return 0 ;
}
static int T_4
F_132 ( struct V_24 * V_25 ,
struct V_14 * V_45 )
{
const struct V_112 * V_178 ;
const struct V_350 * V_16 = V_45 -> V_16 ;
const struct V_90 * V_351 ;
const struct V_90 * V_93 ;
unsigned int V_275 ;
unsigned int V_352 ;
unsigned int V_114 ;
F_133 ( & V_45 -> V_267 ) ;
V_45 -> V_353 = F_45 ;
V_178 = F_53 ( V_16 -> V_113 ) ;
if ( V_178 == NULL ) {
F_24 ( V_25 -> V_30 , L_16 , V_16 -> V_113 ) ;
return - V_43 ;
}
V_351 = NULL ;
V_352 = 0 ;
for ( V_114 = 0 , V_93 = V_16 -> V_276 ; V_114 < V_16 -> V_275 ; V_114 ++ , V_93 ++ ) {
unsigned int V_354 = V_93 -> V_95 * V_93 -> V_94 ;
if ( ( V_16 -> V_113 == V_198 ||
V_16 -> V_113 == V_193 ) && ( V_93 -> V_95 & 0x1 ) ) {
F_24 ( V_25 -> V_30 , L_17
L_18 ) ;
return - V_43 ;
}
if ( V_354 > V_352 ) {
V_351 = V_93 ;
V_352 = V_354 ;
}
}
if ( ! V_352 )
V_352 = V_273 * V_274 ;
else
F_43 ( V_25 -> V_30 , L_19 ,
V_351 -> V_94 , V_351 -> V_95 ) ;
if ( V_16 -> V_276 == NULL ) {
V_93 = & V_355 ;
V_275 = 1 ;
} else {
V_93 = V_16 -> V_276 ;
V_275 = V_16 -> V_275 ;
}
V_45 -> V_178 = V_178 ;
V_45 -> V_94 = V_93 -> V_94 ;
V_45 -> V_278 = V_93 -> V_94 ;
V_45 -> V_95 = V_93 -> V_95 ;
V_45 -> V_213 = V_93 -> V_95 * 2 ;
if ( ! V_178 -> V_180 ) {
V_45 -> V_181 = V_279 ;
V_45 -> V_186 = V_45 -> V_94 * V_178 -> V_249 / 8 ;
} else {
V_45 -> V_181 = V_182 ;
V_45 -> V_186 = V_45 -> V_94 ;
}
V_45 -> V_92 . V_103 = V_16 -> V_72 . V_103 ;
V_45 -> V_92 . V_105 = V_16 -> V_72 . V_105 ;
V_45 -> V_92 . V_93 = * V_93 ;
V_45 -> V_64 = V_352 * V_178 -> V_249 / 8 * 2 ;
V_45 -> V_303 = F_134 ( V_25 -> V_30 , V_45 -> V_64 , & V_45 -> V_212 ,
V_356 ) ;
if ( V_45 -> V_303 == NULL ) {
F_24 ( V_25 -> V_30 , L_20 ) ;
return - V_294 ;
}
if ( V_16 -> V_82 ) {
if ( ! V_16 -> V_82 -> V_30 . V_329 ||
! F_135 ( V_16 -> V_82 -> V_30 . V_329 -> V_330 ) ) {
F_136 ( V_25 -> V_30 ,
L_21 ) ;
return - V_43 ;
}
V_45 -> V_82 = F_117 ( V_16 -> V_82 ) ;
V_45 -> V_82 -> V_19 = V_45 ;
V_45 -> V_82 -> V_357 = * V_93 ;
}
return F_103 ( V_45 , V_93 , V_275 ) ;
}
static int T_4 F_137 ( struct V_320 * V_32 )
{
struct V_358 * V_359 = V_32 -> V_30 . V_360 ;
struct V_24 * V_25 ;
struct V_361 * V_362 ;
int V_363 ;
int error ;
int V_114 ;
if ( ! V_359 ) {
F_24 ( & V_32 -> V_30 , L_22 ) ;
return - V_43 ;
}
V_362 = F_138 ( V_32 , V_364 , 0 ) ;
V_114 = F_139 ( V_32 , 0 ) ;
if ( ! V_362 || V_114 < 0 ) {
F_24 ( & V_32 -> V_30 , L_23 ) ;
return - V_365 ;
}
V_25 = F_140 ( sizeof( * V_25 ) , V_356 ) ;
if ( ! V_25 ) {
F_24 ( & V_32 -> V_30 , L_24 ) ;
return - V_294 ;
}
V_25 -> V_30 = & V_32 -> V_30 ;
V_25 -> V_31 = V_359 -> V_31 ;
F_141 ( V_32 , V_25 ) ;
error = F_142 ( V_114 , F_57 , 0 ,
F_98 ( & V_32 -> V_30 ) , V_25 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_25 ) ;
goto V_366;
}
V_25 -> V_119 = V_114 ;
F_143 ( & V_25 -> V_28 , - 1 ) ;
for ( V_114 = 0 , V_363 = 0 ; V_114 < F_54 ( V_359 -> V_45 ) ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_363 ;
V_45 -> V_19 = V_25 ;
V_45 -> V_16 = & V_359 -> V_45 [ V_114 ] ;
error = F_131 ( V_45 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_26 ) ;
goto V_366;
}
F_144 ( & V_45 -> V_130 ) ;
F_145 ( & V_45 -> V_132 ) ;
V_45 -> V_250 = 0 ;
if ( V_45 -> V_16 -> V_313 . V_319 )
V_45 -> V_223 = F_111 ( & V_32 -> V_30 , V_45 ) ;
switch ( V_359 -> V_45 [ V_114 ] . V_15 ) {
case V_296 :
V_45 -> V_127 = V_367 ;
V_45 -> V_21 = V_368 ;
V_363 ++ ;
break;
case V_17 :
V_45 -> V_127 = V_369 ;
V_45 -> V_21 = V_370 ;
V_363 ++ ;
break;
}
}
if ( ! V_363 ) {
F_24 ( & V_32 -> V_30 , L_27 ) ;
error = - V_43 ;
goto V_366;
}
if ( V_363 == 2 )
V_25 -> V_283 = V_359 -> V_45 [ 0 ] . V_113 ;
V_25 -> V_20 = F_146 ( V_362 -> V_135 , F_147 ( V_362 ) ) ;
if ( ! V_25 -> V_20 )
goto V_366;
error = F_21 ( V_25 , V_359 -> V_33 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_28 ) ;
goto V_366;
}
F_148 ( & V_32 -> V_30 ) ;
for ( V_114 = 0 ; V_114 < V_363 ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_114 ;
error = F_132 ( V_25 , V_45 ) ;
if ( error )
goto V_366;
}
error = F_67 ( V_25 ) ;
if ( error ) {
F_24 ( & V_32 -> V_30 , L_29 ) ;
goto V_366;
}
for ( V_114 = 0 ; V_114 < V_363 ; V_114 ++ ) {
struct V_14 * V_45 = V_25 -> V_45 + V_114 ;
error = F_94 ( V_45 ) ;
if ( error )
goto V_366;
}
V_25 -> V_324 . V_371 = F_121 ;
F_149 ( & V_25 -> V_324 ) ;
return 0 ;
V_366:
F_122 ( V_32 ) ;
return error ;
}
