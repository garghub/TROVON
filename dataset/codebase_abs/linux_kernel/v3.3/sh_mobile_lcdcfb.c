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
static void F_2 ( struct V_14 * V_15 ,
int V_1 , unsigned long V_16 )
{
F_3 ( V_16 , V_15 -> V_17 -> V_18 + V_15 -> V_19 [ V_1 ] ) ;
if ( F_1 ( V_1 ) )
F_3 ( V_16 , V_15 -> V_17 -> V_18 + V_15 -> V_19 [ V_1 ] +
V_20 ) ;
}
static void F_4 ( struct V_14 * V_15 ,
int V_1 , unsigned long V_16 )
{
F_3 ( V_16 , V_15 -> V_17 -> V_18 + V_15 -> V_19 [ V_1 ] +
V_21 ) ;
}
static unsigned long F_5 ( struct V_14 * V_15 ,
int V_1 )
{
return F_6 ( V_15 -> V_17 -> V_18 + V_15 -> V_19 [ V_1 ] ) ;
}
static void F_7 ( struct V_22 * V_23 ,
unsigned long V_19 , unsigned long V_16 )
{
F_3 ( V_16 , V_23 -> V_18 + V_19 ) ;
}
static unsigned long F_8 ( struct V_22 * V_23 ,
unsigned long V_19 )
{
return F_6 ( V_23 -> V_18 + V_19 ) ;
}
static void F_9 ( struct V_22 * V_23 ,
unsigned long V_19 ,
unsigned long V_24 , unsigned long V_25 )
{
while ( ( F_8 ( V_23 , V_19 ) & V_24 ) != V_25 )
F_10 () ;
}
static int F_11 ( struct V_14 * V_15 )
{
return V_15 -> V_26 . V_15 == V_27 ;
}
static void F_12 ( void * V_28 , unsigned long V_16 )
{
struct V_14 * V_29 = V_28 ;
F_7 ( V_29 -> V_17 , V_30 , V_16 | V_31 ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
F_7 ( V_29 -> V_17 , V_34 , V_35 |
( F_11 ( V_29 ) ? 2 : 0 ) ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
}
static void F_13 ( void * V_28 , unsigned long V_16 )
{
struct V_14 * V_29 = V_28 ;
F_7 ( V_29 -> V_17 , V_30 , V_16 | V_31 | V_36 ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
F_7 ( V_29 -> V_17 , V_34 , V_35 |
( F_11 ( V_29 ) ? 2 : 0 ) ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
}
static unsigned long F_14 ( void * V_28 )
{
struct V_14 * V_29 = V_28 ;
F_7 ( V_29 -> V_17 , V_37 , V_38 ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
F_7 ( V_29 -> V_17 , V_39 , V_40 |
( F_11 ( V_29 ) ? 2 : 0 ) ) ;
F_15 ( 1 ) ;
F_9 ( V_29 -> V_17 , V_32 , V_33 , 0 ) ;
return F_8 ( V_29 -> V_17 , V_37 ) & V_41 ;
}
static int F_16 ( const struct V_42 * V_43 )
{
if ( V_43 -> V_44 > 1 )
return V_43 -> V_44 ;
switch ( V_43 -> V_45 ) {
case 16 :
return V_46 ;
case 24 :
return V_47 ;
case 32 :
return V_48 ;
default:
return 0 ;
}
}
static int F_17 ( const struct V_42 * V_43 )
{
return V_43 -> V_44 > 1 ;
}
static bool F_18 ( const struct V_42 * V_43 )
{
if ( V_43 -> V_44 <= 1 )
return false ;
switch ( V_43 -> V_44 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
}
}
static void F_19 ( struct V_22 * V_23 )
{
if ( F_20 ( & V_23 -> V_55 ) ) {
if ( V_23 -> V_56 )
F_21 ( V_23 -> V_56 ) ;
F_22 ( V_23 -> V_57 ) ;
if ( V_23 -> V_58 && V_23 -> V_58 -> V_59 )
F_22 ( & V_23 -> V_58 -> V_59 -> V_57 ) ;
}
}
static void F_23 ( struct V_22 * V_23 )
{
if ( F_24 ( 1 , & V_23 -> V_55 ) == - 1 ) {
if ( V_23 -> V_58 && V_23 -> V_58 -> V_59 )
F_25 ( & V_23 -> V_58 -> V_59 -> V_57 ) ;
F_26 ( V_23 -> V_57 ) ;
if ( V_23 -> V_56 )
F_27 ( V_23 -> V_56 ) ;
}
}
static int F_28 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
unsigned int V_65 = V_61 -> V_66 . V_67 >> V_68 ;
struct V_69 * V_69 ;
int V_70 = 0 ;
F_29 ( V_29 -> V_71 , V_65 ) ;
F_30 (page, pagelist, lru)
F_31 ( & V_29 -> V_71 [ V_70 ++ ] , V_69 , V_72 , 0 ) ;
return V_70 ;
}
static void F_32 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_73 * V_74 = & V_29 -> V_26 . V_75 ;
F_19 ( V_29 -> V_17 ) ;
if ( ! F_33 ( V_63 ) ) {
unsigned int V_70 = F_28 ( V_61 , V_63 ) ;
F_34 ( V_61 -> V_57 , V_29 -> V_71 , V_70 , V_76 ) ;
if ( V_74 -> V_77 )
V_74 -> V_77 ( V_74 -> V_78 , V_29 ,
& V_79 ) ;
F_2 ( V_29 , V_80 , V_81 ) ;
F_35 ( V_61 -> V_57 , V_29 -> V_71 , V_70 , V_76 ) ;
} else {
if ( V_74 -> V_77 )
V_74 -> V_77 ( V_74 -> V_78 , V_29 ,
& V_79 ) ;
F_2 ( V_29 , V_80 , V_81 ) ;
}
}
static void F_36 ( struct V_60 * V_61 )
{
struct V_82 * V_83 = V_61 -> V_83 ;
if ( V_83 )
F_37 ( & V_61 -> V_84 , V_83 -> V_85 ) ;
}
static T_1 F_38 ( int V_86 , void * V_16 )
{
struct V_22 * V_23 = V_16 ;
struct V_14 * V_29 ;
unsigned long V_87 ;
int V_88 ;
int V_89 ;
V_87 = F_8 ( V_23 , V_90 ) ;
F_7 ( V_23 , V_90 , ( V_87 ^ V_91 ) & ~ V_92 ) ;
V_88 = ( F_8 ( V_23 , V_32 ) & V_93 ) ? 1 : 0 ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
if ( V_87 & V_95 ) {
if ( V_88 == F_11 ( V_29 ) ) {
V_29 -> V_96 = 1 ;
F_40 ( & V_29 -> V_97 ) ;
F_23 ( V_23 ) ;
}
}
if ( V_87 & V_98 )
F_41 ( & V_29 -> V_99 ) ;
}
return V_100 ;
}
static void F_42 ( struct V_22 * V_23 ,
int V_101 )
{
unsigned long V_102 = F_8 ( V_23 , V_103 ) ;
int V_89 ;
if ( V_101 )
F_7 ( V_23 , V_103 , V_102 | V_104 ) ;
else
F_7 ( V_23 , V_103 , V_102 & ~ V_104 ) ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ )
if ( F_8 ( V_23 , V_103 ) & V_23 -> V_29 [ V_89 ] . V_94 )
while ( 1 ) {
V_102 = F_5 ( & V_23 -> V_29 [ V_89 ] , V_105 )
& V_106 ;
if ( V_101 && V_102 == V_106 )
break;
if ( ! V_101 && V_102 == 0 )
break;
F_10 () ;
}
if ( ! V_101 )
F_7 ( V_23 , V_107 , 1 ) ;
}
static void F_43 ( struct V_14 * V_29 )
{
struct V_42 * V_43 = & V_29 -> V_61 -> V_43 , * V_108 = & V_29 -> V_108 ;
unsigned long V_109 , V_110 , V_111 ;
T_2 V_102 ;
V_102 = V_29 -> V_112 ;
V_102 |= ( V_43 -> V_113 & V_114 ) ? 0 : V_115 ;
V_102 |= ( V_43 -> V_113 & V_116 ) ? 0 : V_117 ;
V_102 |= ( V_29 -> V_26 . V_118 & V_119 ) ? V_120 : 0 ;
V_102 |= ( V_29 -> V_26 . V_118 & V_121 ) ? V_122 : 0 ;
V_102 |= ( V_29 -> V_26 . V_118 & V_123 ) ? V_124 : 0 ;
V_102 |= ( V_29 -> V_26 . V_118 & V_125 ) ? V_126 : 0 ;
V_102 |= ( V_29 -> V_26 . V_118 & V_127 ) ? V_128 : 0 ;
F_2 ( V_29 , V_2 , V_102 ) ;
F_2 ( V_29 , V_3 , V_29 -> V_26 . V_129 . V_130 ) ;
F_2 ( V_29 , V_4 , V_29 -> V_26 . V_129 . V_131 ) ;
V_109 = V_108 -> V_132 + V_108 -> V_133 +
V_108 -> V_134 + V_108 -> V_135 ;
V_102 = V_109 / 8 ;
V_102 |= ( F_44 ( V_108 -> V_132 , V_43 -> V_132 ) / 8 ) << 16 ;
F_2 ( V_29 , V_10 , V_102 ) ;
V_110 = V_108 -> V_132 + V_108 -> V_135 ;
V_102 = V_110 / 8 ;
V_102 |= ( V_108 -> V_133 / 8 ) << 16 ;
F_2 ( V_29 , V_11 , V_102 ) ;
V_102 = V_108 -> V_136 + V_108 -> V_137 +
V_108 -> V_138 + V_108 -> V_139 ;
V_102 |= F_44 ( V_108 -> V_136 , V_43 -> V_136 ) << 16 ;
F_2 ( V_29 , V_12 , V_102 ) ;
V_102 = V_108 -> V_136 + V_108 -> V_139 ;
V_102 |= V_108 -> V_137 << 16 ;
F_2 ( V_29 , V_13 , V_102 ) ;
V_111 = V_108 -> V_132 + V_108 -> V_133 +
V_108 -> V_134 + V_108 -> V_135 ;
V_102 = ( ( V_108 -> V_132 & 7 ) << 24 ) |
( ( V_111 & 7 ) << 16 ) |
( ( V_108 -> V_133 & 7 ) << 8 ) |
( V_110 & 7 ) ;
F_2 ( V_29 , V_140 , V_102 ) ;
}
static void F_45 ( struct V_22 * V_23 )
{
struct V_14 * V_29 ;
unsigned long V_102 ;
int V_89 , V_141 ;
F_7 ( V_23 , V_103 , V_23 -> V_29 [ 0 ] . V_94 | V_23 -> V_29 [ 1 ] . V_94 ) ;
F_42 ( V_23 , 0 ) ;
F_7 ( V_23 , V_90 , 0 ) ;
V_102 = V_23 -> V_142 ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
F_2 ( V_29 , V_105 , 0 ) ;
V_141 = V_29 -> V_26 . V_143 ;
if ( ! V_141 )
continue;
F_2 ( V_29 , V_144 , 0 ) ;
F_2 ( V_29 , V_145 , ( 1 << ( V_141 / 2 ) ) - 1 ) ;
if ( V_141 == 1 )
V_141 = V_146 ;
V_102 |= V_141 << ( F_11 ( V_29 ) ? 8 : 0 ) ;
}
F_7 ( V_23 , V_147 , V_102 ) ;
F_7 ( V_23 , V_107 , 0 ) ;
F_9 ( V_23 , V_107 , ~ 0 , 0 ) ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
F_43 ( V_29 ) ;
switch ( F_16 ( & V_29 -> V_61 -> V_43 ) ) {
case V_46 :
V_102 = V_148 ;
break;
case V_47 :
V_102 = V_149 ;
break;
case V_48 :
V_102 = V_150 ;
break;
case V_49 :
case V_50 :
V_102 = V_151 | V_152 ;
break;
case V_51 :
case V_52 :
V_102 = V_151 | V_153 ;
break;
case V_53 :
case V_54 :
V_102 = V_151 | V_154 ;
break;
}
if ( F_18 ( & V_29 -> V_61 -> V_43 ) ) {
switch ( V_29 -> V_61 -> V_43 . V_155 ) {
case V_156 :
V_102 |= V_157 ;
break;
case V_158 :
V_102 |= V_159 ;
break;
}
}
F_2 ( V_29 , V_5 , V_102 ) ;
F_2 ( V_29 , V_9 , V_29 -> V_160 ) ;
F_2 ( V_29 , V_7 , V_29 -> V_161 ) ;
if ( F_18 ( & V_29 -> V_61 -> V_43 ) )
F_2 ( V_29 , V_8 , V_29 -> V_162 ) ;
if ( V_29 -> V_112 & V_163 &&
V_29 -> V_26 . V_129 . V_164 ) {
F_2 ( V_29 , V_6 , V_165 ) ;
F_7 ( V_23 , V_90 , V_166 ) ;
} else {
F_2 ( V_29 , V_6 , 0 ) ;
}
}
switch ( F_16 ( & V_23 -> V_29 [ 0 ] . V_61 -> V_43 ) ) {
case V_46 :
case V_50 :
case V_52 :
case V_54 :
V_102 = V_167 | V_168 ;
break;
case V_47 :
case V_49 :
case V_51 :
case V_53 :
V_102 = V_167 | V_168 | V_169 ;
break;
case V_48 :
default:
V_102 = V_167 ;
break;
}
F_7 ( V_23 , V_170 , V_102 ) ;
F_7 ( V_23 , V_171 , V_172 ) ;
F_42 ( V_23 , 1 ) ;
V_23 -> V_173 = 1 ;
}
static int F_46 ( struct V_22 * V_23 )
{
struct V_174 * V_175 = V_23 -> V_58 ;
struct V_73 * V_75 ;
struct V_14 * V_29 ;
unsigned long V_102 ;
int V_176 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
if ( V_23 -> V_29 [ V_89 ] . V_94 )
F_19 ( V_23 ) ;
}
F_7 ( V_23 , V_103 , F_8 ( V_23 , V_103 ) | V_177 ) ;
F_9 ( V_23 , V_103 , V_177 , 0 ) ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
V_75 = & V_29 -> V_26 . V_75 ;
if ( V_75 -> V_178 ) {
V_176 = V_75 -> V_178 ( V_75 -> V_78 , V_29 ,
& V_79 ) ;
if ( V_176 )
return V_176 ;
}
}
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
struct V_179 * V_26 ;
int V_180 ;
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
V_29 -> V_161 = V_29 -> V_61 -> V_66 . V_181 ;
V_29 -> V_162 = V_29 -> V_161
+ V_29 -> V_61 -> V_43 . V_132
* V_29 -> V_61 -> V_43 . V_182 ;
V_29 -> V_160 = V_29 -> V_61 -> V_66 . V_183 ;
V_26 = V_29 -> V_26 . V_184 ;
if ( V_175 == NULL || V_175 -> V_185 == NULL || V_26 == NULL )
continue;
if ( V_29 -> V_186 ) {
V_175 -> V_185 -> V_187 ( V_175 , V_26 ) ;
V_29 -> V_186 = 0 ;
}
switch ( F_16 ( & V_29 -> V_61 -> V_43 ) ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_180 = V_188 ;
break;
case V_53 :
case V_54 :
V_180 = V_189 ;
break;
case V_46 :
case V_47 :
case V_48 :
default:
V_180 = V_190 ;
break;
}
V_176 = V_175 -> V_185 -> V_191 ( V_175 , V_26 , V_29 -> V_160 ,
V_29 -> V_61 -> V_43 . V_136 , V_180 ,
V_29 -> V_161 , V_29 -> V_162 ,
& V_29 -> V_161 , & V_29 -> V_162 ,
& V_29 -> V_160 ) ;
if ( ! V_176 )
V_29 -> V_186 = 1 ;
}
F_45 ( V_23 ) ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
V_102 = V_29 -> V_26 . V_129 . V_164 ;
if ( V_29 -> V_112 & V_163 && V_102 ) {
V_29 -> V_192 . V_193 = F_32 ;
V_29 -> V_192 . V_85 = F_47 ( V_102 ) ;
V_29 -> V_61 -> V_83 = & V_29 -> V_192 ;
F_48 ( V_29 -> V_61 ) ;
}
V_75 = & V_29 -> V_26 . V_75 ;
if ( V_75 -> V_194 && F_49 ( V_75 -> V_195 ) ) {
V_75 -> V_194 ( V_75 -> V_78 , V_29 -> V_61 ) ;
F_50 ( V_75 -> V_195 ) ;
}
if ( V_29 -> V_196 ) {
V_29 -> V_196 -> V_197 . V_198 = V_199 ;
F_51 ( V_29 -> V_196 ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_22 * V_23 )
{
struct V_14 * V_29 ;
struct V_73 * V_75 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ ) {
V_29 = & V_23 -> V_29 [ V_89 ] ;
if ( ! V_29 -> V_94 )
continue;
if ( V_29 -> V_61 && V_29 -> V_61 -> V_83 ) {
V_29 -> V_96 = 0 ;
F_37 ( & V_29 -> V_61 -> V_84 , 0 ) ;
F_53 ( V_29 -> V_97 , V_29 -> V_96 ) ;
F_54 ( V_29 -> V_61 ) ;
V_29 -> V_61 -> V_83 = NULL ;
F_19 ( V_23 ) ;
}
if ( V_29 -> V_196 ) {
V_29 -> V_196 -> V_197 . V_198 = V_200 ;
F_51 ( V_29 -> V_196 ) ;
}
V_75 = & V_29 -> V_26 . V_75 ;
if ( V_75 -> V_201 && F_49 ( V_75 -> V_195 ) ) {
V_75 -> V_201 ( V_75 -> V_78 ) ;
F_50 ( V_75 -> V_195 ) ;
}
if ( V_29 -> V_186 ) {
struct V_179 * V_26 ;
struct V_174 * V_175 ;
V_26 = V_29 -> V_26 . V_184 ;
V_175 = V_23 -> V_58 ;
V_175 -> V_185 -> V_187 ( V_175 , V_26 ) ;
V_29 -> V_186 = 0 ;
}
}
if ( V_23 -> V_173 ) {
F_42 ( V_23 , 0 ) ;
V_23 -> V_173 = 0 ;
}
for ( V_89 = 0 ; V_89 < F_39 ( V_23 -> V_29 ) ; V_89 ++ )
if ( V_23 -> V_29 [ V_89 ] . V_94 )
F_23 ( V_23 ) ;
}
static int F_55 ( struct V_14 * V_29 )
{
int V_202 = V_29 -> V_26 . V_202 ;
switch ( V_202 ) {
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
break;
default:
return - V_221 ;
}
if ( F_11 ( V_29 ) ) {
if ( ! ( V_202 & V_163 ) )
return - V_221 ;
V_202 &= ~ V_163 ;
}
V_29 -> V_112 = V_202 ;
return 0 ;
}
static int F_56 ( struct V_222 * V_59 ,
int V_223 ,
struct V_22 * V_23 )
{
char * V_224 ;
switch ( V_223 ) {
case V_225 :
V_224 = L_1 ;
V_23 -> V_142 = V_226 ;
break;
case V_227 :
V_224 = L_2 ;
V_23 -> V_142 = V_228 ;
break;
case V_229 :
V_224 = NULL ;
V_23 -> V_142 = V_230 ;
break;
default:
return - V_221 ;
}
if ( V_224 ) {
V_23 -> V_56 = F_57 ( & V_59 -> V_57 , V_224 ) ;
if ( F_58 ( V_23 -> V_56 ) ) {
F_59 ( & V_59 -> V_57 , L_3 , V_224 ) ;
return F_60 ( V_23 -> V_56 ) ;
}
}
V_23 -> V_57 = & V_59 -> V_57 ;
F_61 ( V_23 -> V_57 ) ;
F_62 ( V_23 -> V_57 ) ;
return 0 ;
}
static int F_63 ( T_3 V_231 ,
T_3 V_232 , T_3 V_233 , T_3 V_234 ,
T_3 V_235 , struct V_60 * V_61 )
{
T_2 * V_236 = V_61 -> V_237 ;
if ( V_231 >= V_238 )
return - V_221 ;
V_232 >>= 16 - V_61 -> V_43 . V_232 . V_239 ;
V_233 >>= 16 - V_61 -> V_43 . V_233 . V_239 ;
V_234 >>= 16 - V_61 -> V_43 . V_234 . V_239 ;
V_235 >>= 16 - V_61 -> V_43 . V_235 . V_239 ;
V_236 [ V_231 ] = ( V_232 << V_61 -> V_43 . V_232 . V_240 ) |
( V_233 << V_61 -> V_43 . V_233 . V_240 ) |
( V_234 << V_61 -> V_43 . V_234 . V_240 ) |
( V_235 << V_61 -> V_43 . V_235 . V_240 ) ;
return 0 ;
}
static void F_64 ( struct V_60 * V_61 ,
const struct V_241 * V_242 )
{
F_65 ( V_61 , V_242 ) ;
F_36 ( V_61 ) ;
}
static void F_66 ( struct V_60 * V_61 ,
const struct V_243 * V_244 )
{
F_67 ( V_61 , V_244 ) ;
F_36 ( V_61 ) ;
}
static void F_68 ( struct V_60 * V_61 ,
const struct V_245 * V_246 )
{
F_69 ( V_61 , V_246 ) ;
F_36 ( V_61 ) ;
}
static int F_70 ( struct V_42 * V_43 ,
struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_22 * V_23 = V_29 -> V_17 ;
unsigned long V_247 ;
unsigned long V_248 ;
unsigned long V_161 , V_162 ;
unsigned long V_249 ;
bool V_250 = F_18 ( & V_61 -> V_43 ) ;
if ( ! V_250 )
V_248 = V_43 -> V_251 * V_61 -> V_66 . V_183
+ V_43 -> V_252 * ( V_61 -> V_43 . V_45 / 8 ) ;
else
V_248 = V_43 -> V_251 * V_61 -> V_66 . V_183
+ V_43 -> V_252 ;
if ( V_248 == V_29 -> V_253 )
return 0 ;
V_247 = F_8 ( V_23 , V_254 ) ;
V_161 = V_29 -> V_255 + V_248 ;
if ( V_250 ) {
V_249 = V_43 -> V_251 * V_61 -> V_66 . V_183
* ( V_61 -> V_43 . V_45 - 8 ) / 8 ;
V_162 = V_29 -> V_255
+ V_61 -> V_43 . V_132 * V_61 -> V_43 . V_182
+ V_249 ;
if ( F_16 ( & V_61 -> V_43 ) == V_53 )
V_162 += 2 * V_43 -> V_252 ;
else
V_162 += V_43 -> V_252 ;
}
if ( V_29 -> V_186 ) {
struct V_179 * V_26 ;
struct V_174 * V_175 ;
int V_176 ;
V_26 = V_29 -> V_26 . V_184 ;
V_175 = V_23 -> V_58 ;
V_176 = V_175 -> V_185 -> V_256 ( V_175 , V_26 ,
V_161 , V_162 ,
& V_161 , & V_162 ) ;
if ( V_176 )
return V_176 ;
}
V_29 -> V_161 = V_161 ;
V_29 -> V_162 = V_162 ;
F_4 ( V_29 , V_7 , V_161 ) ;
if ( V_250 )
F_4 ( V_29 , V_8 , V_162 ) ;
if ( F_11 ( V_29 ) )
F_7 ( V_29 -> V_17 , V_254 , V_247 ^ V_257 ) ;
else
F_7 ( V_29 -> V_17 , V_254 , V_247 ^ V_258 ) ;
V_29 -> V_253 = V_248 ;
F_36 ( V_61 ) ;
return 0 ;
}
static int F_71 ( struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
unsigned long V_87 ;
int V_176 ;
V_87 = F_8 ( V_29 -> V_17 , V_90 ) ;
V_87 |= V_92 | V_91 ;
F_7 ( V_29 -> V_17 , V_90 , V_87 ) ;
V_176 = F_72 ( & V_29 -> V_99 ,
F_47 ( 100 ) ) ;
if ( ! V_176 )
return - V_259 ;
return 0 ;
}
static int F_73 ( struct V_60 * V_61 , unsigned int V_260 ,
unsigned long V_261 )
{
int V_262 ;
switch ( V_260 ) {
case V_263 :
V_262 = F_71 ( V_61 ) ;
break;
default:
V_262 = - V_264 ;
break;
}
return V_262 ;
}
static void F_74 ( struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_265 V_266 , V_267 ;
struct V_268 V_269 ;
int V_270 = V_271 ;
if ( V_29 -> V_272 > 1 || ( V_29 -> V_272 == 1 && ! V_61 -> V_273 ) )
return;
F_75 ( & V_266 , & V_29 -> V_108 ) ;
F_75 ( & V_267 , & V_61 -> V_43 ) ;
if ( F_76 ( & V_266 , & V_267 ) )
return;
if ( F_77 ( V_61 , & V_29 -> V_108 ) < 0 )
return;
V_269 . V_61 = V_61 ;
V_269 . V_16 = & V_266 ;
F_78 ( V_270 , & V_269 ) ;
}
static int F_79 ( struct V_60 * V_61 , int V_274 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
F_80 ( & V_29 -> V_275 ) ;
F_81 ( V_61 -> V_57 , L_4 , V_276 , V_29 -> V_272 ) ;
V_29 -> V_272 -- ;
if ( V_274 ) {
F_82 () ;
F_74 ( V_61 ) ;
F_83 () ;
}
F_84 ( & V_29 -> V_275 ) ;
return 0 ;
}
static int F_85 ( struct V_60 * V_61 , int V_274 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
F_80 ( & V_29 -> V_275 ) ;
V_29 -> V_272 ++ ;
F_81 ( V_61 -> V_57 , L_4 , V_276 , V_29 -> V_272 ) ;
F_84 ( & V_29 -> V_275 ) ;
return 0 ;
}
static int F_86 ( struct V_42 * V_43 , struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_22 * V_277 = V_29 -> V_17 ;
unsigned int V_278 = ( unsigned int ) - 1 ;
unsigned int V_279 = 0 ;
unsigned int V_280 = 0 ;
unsigned int V_281 ;
if ( V_43 -> V_132 > V_282 || V_43 -> V_136 > V_283 )
return - V_221 ;
for ( V_281 = 0 ; V_281 < V_29 -> V_26 . V_284 ; ++ V_281 ) {
const struct V_265 * V_285 = & V_29 -> V_26 . V_286 [ V_281 ] ;
unsigned int V_287 ;
if ( V_43 -> V_132 > V_285 -> V_132 || V_43 -> V_136 > V_285 -> V_136 )
continue;
V_287 = V_43 -> V_132 * V_43 -> V_136 + V_285 -> V_132 * V_285 -> V_136
- 2 * F_44 ( V_43 -> V_132 , V_285 -> V_132 )
* F_44 ( V_43 -> V_136 , V_285 -> V_136 ) ;
if ( V_287 < V_278 ) {
V_279 = V_285 -> V_132 ;
V_280 = V_285 -> V_136 ;
V_278 = V_287 ;
}
}
if ( V_29 -> V_26 . V_284 != 0 ) {
if ( V_278 == ( unsigned int ) - 1 )
return - V_221 ;
V_43 -> V_132 = V_279 ;
V_43 -> V_136 = V_280 ;
}
if ( V_43 -> V_288 < V_43 -> V_132 )
V_43 -> V_288 = V_43 -> V_132 ;
if ( V_43 -> V_182 < V_43 -> V_136 )
V_43 -> V_182 = V_43 -> V_136 ;
if ( F_17 ( V_43 ) ) {
switch ( V_43 -> V_44 ) {
case V_49 :
case V_50 :
V_43 -> V_45 = 12 ;
break;
case V_46 :
case V_51 :
case V_52 :
V_43 -> V_45 = 16 ;
break;
case V_47 :
case V_53 :
case V_54 :
V_43 -> V_45 = 24 ;
break;
case V_48 :
V_43 -> V_45 = 32 ;
break;
default:
return - V_221 ;
}
if ( ! F_18 ( V_43 ) )
V_43 -> V_155 = V_289 ;
else if ( V_43 -> V_155 != V_156 )
V_43 -> V_155 = V_158 ;
} else {
if ( V_43 -> V_45 <= 16 ) {
V_43 -> V_45 = 16 ;
V_43 -> V_232 . V_240 = 11 ;
V_43 -> V_232 . V_239 = 5 ;
V_43 -> V_233 . V_240 = 5 ;
V_43 -> V_233 . V_239 = 6 ;
V_43 -> V_234 . V_240 = 0 ;
V_43 -> V_234 . V_239 = 5 ;
V_43 -> V_235 . V_240 = 0 ;
V_43 -> V_235 . V_239 = 0 ;
} else if ( V_43 -> V_45 <= 24 ) {
V_43 -> V_45 = 24 ;
V_43 -> V_232 . V_240 = 16 ;
V_43 -> V_232 . V_239 = 8 ;
V_43 -> V_233 . V_240 = 8 ;
V_43 -> V_233 . V_239 = 8 ;
V_43 -> V_234 . V_240 = 0 ;
V_43 -> V_234 . V_239 = 8 ;
V_43 -> V_235 . V_240 = 0 ;
V_43 -> V_235 . V_239 = 0 ;
} else if ( V_43 -> V_45 <= 32 ) {
V_43 -> V_45 = 32 ;
V_43 -> V_232 . V_240 = 16 ;
V_43 -> V_232 . V_239 = 8 ;
V_43 -> V_233 . V_240 = 8 ;
V_43 -> V_233 . V_239 = 8 ;
V_43 -> V_234 . V_240 = 0 ;
V_43 -> V_234 . V_239 = 8 ;
V_43 -> V_235 . V_240 = 24 ;
V_43 -> V_235 . V_239 = 8 ;
} else
return - V_221 ;
V_43 -> V_232 . V_290 = 0 ;
V_43 -> V_233 . V_290 = 0 ;
V_43 -> V_234 . V_290 = 0 ;
V_43 -> V_235 . V_290 = 0 ;
}
if ( V_43 -> V_288 * V_43 -> V_182 * V_43 -> V_45 / 8 >
V_61 -> V_66 . V_67 )
return - V_221 ;
if ( V_277 -> V_291 &&
V_277 -> V_291 != F_16 ( V_43 ) )
return - V_221 ;
return 0 ;
}
static int F_87 ( struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
T_2 V_183 = V_61 -> V_66 . V_183 ;
int V_176 ;
F_52 ( V_29 -> V_17 ) ;
if ( F_18 ( & V_61 -> V_43 ) )
V_61 -> V_66 . V_183 = V_61 -> V_43 . V_132 ;
else
V_61 -> V_66 . V_183 = V_61 -> V_43 . V_132
* V_61 -> V_43 . V_45 / 8 ;
V_176 = F_46 ( V_29 -> V_17 ) ;
if ( V_176 < 0 ) {
F_59 ( V_61 -> V_57 , L_5 , V_276 ) ;
V_61 -> V_66 . V_183 = V_183 ;
}
if ( F_17 ( & V_61 -> V_43 ) ) {
V_61 -> V_66 . type = V_292 ;
V_61 -> V_66 . V_293 = V_294 ;
} else {
V_61 -> V_66 . type = V_295 ;
V_61 -> V_66 . V_293 = V_296 ;
}
return V_176 ;
}
static int F_88 ( int V_297 , struct V_60 * V_61 )
{
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_22 * V_277 = V_29 -> V_17 ;
if ( V_297 > V_199 && V_29 -> V_298 == V_199 ) {
struct V_241 V_242 = {
. V_299 = V_61 -> V_43 . V_132 ,
. V_300 = V_61 -> V_43 . V_136 ,
} ;
F_64 ( V_61 , & V_242 ) ;
}
if ( V_297 <= V_301 && V_29 -> V_298 > V_301 ) {
F_19 ( V_277 ) ;
}
if ( V_297 > V_301 && V_29 -> V_298 <= V_301 ) {
if ( ! V_61 -> V_83 ) {
F_71 ( V_61 ) ;
F_71 ( V_61 ) ;
}
F_23 ( V_277 ) ;
}
V_29 -> V_298 = V_297 ;
return 0 ;
}
static int F_89 ( struct V_302 * V_303 )
{
struct V_14 * V_29 = F_90 ( V_303 ) ;
struct V_73 * V_26 = & V_29 -> V_26 . V_75 ;
int V_304 = V_303 -> V_197 . V_304 ;
if ( V_303 -> V_197 . V_198 != V_199 ||
V_303 -> V_197 . V_305 & ( V_306 | V_307 ) )
V_304 = 0 ;
return V_26 -> V_308 ( V_26 -> V_78 , V_304 ) ;
}
static int F_91 ( struct V_302 * V_303 )
{
struct V_14 * V_29 = F_90 ( V_303 ) ;
struct V_73 * V_26 = & V_29 -> V_26 . V_75 ;
return V_26 -> V_309 ( V_26 -> V_78 ) ;
}
static int F_92 ( struct V_302 * V_303 ,
struct V_60 * V_61 )
{
return ( V_61 -> V_310 == V_303 ) ;
}
static struct V_302 * F_93 ( struct V_311 * V_312 ,
struct V_14 * V_29 )
{
struct V_302 * V_196 ;
V_196 = F_94 ( V_29 -> V_26 . V_313 . V_314 , V_312 , V_29 ,
& V_315 , NULL ) ;
if ( F_58 ( V_196 ) ) {
F_59 ( V_312 , L_6 ,
F_60 ( V_196 ) ) ;
return NULL ;
}
V_196 -> V_197 . V_316 = V_29 -> V_26 . V_313 . V_316 ;
V_196 -> V_197 . V_304 = V_196 -> V_197 . V_316 ;
F_51 ( V_196 ) ;
return V_196 ;
}
static void F_95 ( struct V_302 * V_303 )
{
F_96 ( V_303 ) ;
}
static int F_97 ( struct V_311 * V_57 )
{
struct V_222 * V_59 = F_98 ( V_57 ) ;
F_52 ( F_99 ( V_59 ) ) ;
return 0 ;
}
static int F_100 ( struct V_311 * V_57 )
{
struct V_222 * V_59 = F_98 ( V_57 ) ;
return F_46 ( F_99 ( V_59 ) ) ;
}
static int F_101 ( struct V_311 * V_57 )
{
struct V_222 * V_59 = F_98 ( V_57 ) ;
struct V_22 * V_23 = F_99 ( V_59 ) ;
F_7 ( V_23 , V_171 , 0 ) ;
return 0 ;
}
static int F_102 ( struct V_311 * V_57 )
{
struct V_222 * V_59 = F_98 ( V_57 ) ;
struct V_22 * V_23 = F_99 ( V_59 ) ;
F_45 ( V_23 ) ;
return 0 ;
}
static int F_103 ( struct V_317 * V_318 ,
unsigned long V_319 , void * V_16 )
{
struct V_268 * V_269 = V_16 ;
struct V_60 * V_61 = V_269 -> V_61 ;
struct V_14 * V_29 = V_61 -> V_64 ;
struct V_73 * V_75 = & V_29 -> V_26 . V_75 ;
if ( & V_29 -> V_17 -> V_320 != V_318 )
return V_321 ;
F_81 ( V_61 -> V_57 , L_7 ,
V_276 , V_319 , V_269 -> V_16 ) ;
switch( V_319 ) {
case V_322 :
if ( V_75 -> V_201 && F_49 ( V_75 -> V_195 ) ) {
V_75 -> V_201 ( V_75 -> V_78 ) ;
F_50 ( V_75 -> V_195 ) ;
}
F_52 ( V_29 -> V_17 ) ;
break;
case V_323 :
F_80 ( & V_29 -> V_275 ) ;
F_74 ( V_61 ) ;
F_84 ( & V_29 -> V_275 ) ;
if ( V_75 -> V_194 && F_49 ( V_75 -> V_195 ) ) {
V_75 -> V_194 ( V_75 -> V_78 , V_61 ) ;
F_50 ( V_75 -> V_195 ) ;
}
F_46 ( V_29 -> V_17 ) ;
}
return V_324 ;
}
static int F_104 ( struct V_222 * V_59 )
{
struct V_22 * V_23 = F_99 ( V_59 ) ;
struct V_60 * V_61 ;
int V_281 ;
F_105 ( & V_23 -> V_320 ) ;
for ( V_281 = 0 ; V_281 < F_39 ( V_23 -> V_29 ) ; V_281 ++ )
if ( V_23 -> V_29 [ V_281 ] . V_61 && V_23 -> V_29 [ V_281 ] . V_61 -> V_57 )
F_106 ( V_23 -> V_29 [ V_281 ] . V_61 ) ;
F_52 ( V_23 ) ;
for ( V_281 = 0 ; V_281 < F_39 ( V_23 -> V_29 ) ; V_281 ++ ) {
V_61 = V_23 -> V_29 [ V_281 ] . V_61 ;
if ( ! V_61 || ! V_61 -> V_311 )
continue;
if ( V_23 -> V_29 [ V_281 ] . V_71 )
F_107 ( V_23 -> V_29 [ V_281 ] . V_71 ) ;
if ( V_61 -> V_325 )
F_108 ( & V_59 -> V_57 , V_61 -> V_66 . V_67 ,
V_61 -> V_325 ,
V_23 -> V_29 [ V_281 ] . V_255 ) ;
F_109 ( & V_61 -> V_326 ) ;
F_110 ( V_61 ) ;
}
for ( V_281 = 0 ; V_281 < F_39 ( V_23 -> V_29 ) ; V_281 ++ ) {
if ( V_23 -> V_29 [ V_281 ] . V_196 )
F_95 ( V_23 -> V_29 [ V_281 ] . V_196 ) ;
}
if ( V_23 -> V_56 )
F_111 ( V_23 -> V_56 ) ;
if ( V_23 -> V_57 )
F_112 ( V_23 -> V_57 ) ;
if ( V_23 -> V_18 )
F_113 ( V_23 -> V_18 ) ;
if ( V_23 -> V_86 )
F_114 ( V_23 -> V_86 , V_23 ) ;
F_115 ( V_23 ) ;
return 0 ;
}
static int T_4 F_116 ( struct V_14 * V_29 ,
struct V_311 * V_57 )
{
struct V_327 * V_26 = & V_29 -> V_26 ;
const struct V_265 * V_328 ;
const struct V_265 * V_285 ;
struct V_42 * V_43 ;
struct V_60 * V_61 ;
unsigned int V_329 ;
int V_284 ;
void * V_330 ;
int V_176 ;
int V_281 ;
F_117 ( & V_29 -> V_275 ) ;
V_29 -> V_61 = F_118 ( 0 , V_57 ) ;
if ( ! V_29 -> V_61 ) {
F_59 ( V_57 , L_8 ) ;
return - V_331 ;
}
V_61 = V_29 -> V_61 ;
V_61 -> V_332 = & V_333 ;
V_61 -> V_64 = V_29 ;
V_61 -> V_237 = & V_29 -> V_237 ;
V_61 -> V_118 = V_334 ;
V_328 = NULL ;
V_329 = 0 ;
for ( V_281 = 0 , V_285 = V_26 -> V_286 ; V_281 < V_26 -> V_284 ; V_281 ++ , V_285 ++ ) {
unsigned int V_335 = V_285 -> V_136 * V_285 -> V_132 ;
if ( ( V_26 -> V_336 == V_49 ||
V_26 -> V_336 == V_50 ) && ( V_285 -> V_136 & 0x1 ) ) {
F_59 ( V_57 , L_9
L_10 ) ;
return - V_221 ;
}
if ( V_335 > V_329 ) {
V_328 = V_285 ;
V_329 = V_335 ;
}
}
if ( ! V_329 )
V_329 = V_282 * V_283 ;
else
F_81 ( V_57 , L_11 ,
V_328 -> V_132 , V_328 -> V_136 ) ;
if ( V_26 -> V_286 == NULL ) {
V_285 = & V_337 ;
V_284 = 1 ;
} else {
V_285 = V_26 -> V_286 ;
V_284 = V_26 -> V_284 ;
}
F_119 ( V_285 , V_284 , & V_61 -> V_338 ) ;
V_43 = & V_61 -> V_43 ;
F_120 ( V_43 , V_285 ) ;
V_43 -> V_299 = V_26 -> V_339 . V_299 ;
V_43 -> V_300 = V_26 -> V_339 . V_300 ;
V_43 -> V_182 = V_43 -> V_136 * 2 ;
V_43 -> V_340 = V_341 ;
switch ( V_26 -> V_336 ) {
case V_46 :
V_43 -> V_45 = 16 ;
break;
case V_47 :
V_43 -> V_45 = 24 ;
break;
case V_48 :
V_43 -> V_45 = 32 ;
break;
default:
V_43 -> V_44 = V_26 -> V_336 ;
break;
}
V_61 -> V_66 . V_67 = V_342 ;
V_176 = F_86 ( V_43 , V_61 ) ;
if ( V_176 )
return V_176 ;
V_329 = V_329 * V_43 -> V_45 / 8 * 2 ;
V_330 = F_121 ( V_57 , V_329 , & V_29 -> V_255 , V_343 ) ;
if ( ! V_330 ) {
F_59 ( V_57 , L_12 ) ;
return - V_331 ;
}
V_176 = F_122 ( & V_61 -> V_326 , V_238 , 0 ) ;
if ( V_176 < 0 ) {
F_59 ( V_57 , L_13 ) ;
F_108 ( V_57 , V_329 , V_330 , V_29 -> V_255 ) ;
return V_176 ;
}
V_61 -> V_66 = V_344 ;
V_61 -> V_66 . V_181 = V_29 -> V_255 ;
V_61 -> V_66 . V_67 = V_329 ;
if ( V_26 -> V_336 == V_49 ||
V_26 -> V_336 == V_50 )
V_61 -> V_66 . V_345 = 2 ;
if ( F_18 ( V_43 ) ) {
V_61 -> V_66 . V_183 = V_43 -> V_132 ;
V_61 -> V_66 . V_293 = V_294 ;
} else {
V_61 -> V_66 . V_183 = V_43 -> V_132 * V_43 -> V_45 / 8 ;
V_61 -> V_66 . V_293 = V_296 ;
}
V_61 -> V_325 = V_330 ;
V_61 -> V_311 = V_57 ;
V_29 -> V_108 = * V_43 ;
return 0 ;
}
static int T_4 F_123 ( struct V_222 * V_59 )
{
struct V_346 * V_347 = V_59 -> V_57 . V_348 ;
struct V_22 * V_23 ;
struct V_349 * V_350 ;
int V_351 ;
int error ;
int V_281 ;
if ( ! V_347 ) {
F_59 ( & V_59 -> V_57 , L_14 ) ;
return - V_221 ;
}
V_350 = F_124 ( V_59 , V_352 , 0 ) ;
V_281 = F_125 ( V_59 , 0 ) ;
if ( ! V_350 || V_281 < 0 ) {
F_59 ( & V_59 -> V_57 , L_15 ) ;
return - V_353 ;
}
V_23 = F_126 ( sizeof( * V_23 ) , V_343 ) ;
if ( ! V_23 ) {
F_59 ( & V_59 -> V_57 , L_16 ) ;
return - V_331 ;
}
F_127 ( V_59 , V_23 ) ;
error = F_128 ( V_281 , F_38 , 0 ,
F_129 ( & V_59 -> V_57 ) , V_23 ) ;
if ( error ) {
F_59 ( & V_59 -> V_57 , L_17 ) ;
goto V_354;
}
V_23 -> V_86 = V_281 ;
F_130 ( & V_23 -> V_55 , - 1 ) ;
for ( V_281 = 0 , V_351 = 0 ; V_281 < F_39 ( V_347 -> V_29 ) ; V_281 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_351 ;
V_29 -> V_17 = V_23 ;
memcpy ( & V_29 -> V_26 , & V_347 -> V_29 [ V_281 ] , sizeof( V_347 -> V_29 [ V_281 ] ) ) ;
error = F_55 ( V_29 ) ;
if ( error ) {
F_59 ( & V_59 -> V_57 , L_18 ) ;
goto V_354;
}
F_131 ( & V_29 -> V_97 ) ;
F_132 ( & V_29 -> V_99 ) ;
V_29 -> V_253 = 0 ;
if ( V_29 -> V_26 . V_313 . V_316 )
V_29 -> V_196 = F_93 ( & V_59 -> V_57 , V_29 ) ;
switch ( V_347 -> V_29 [ V_281 ] . V_15 ) {
case V_355 :
V_29 -> V_94 = V_356 ;
V_29 -> V_19 = V_357 ;
V_351 ++ ;
break;
case V_27 :
V_29 -> V_94 = V_358 ;
V_29 -> V_19 = V_359 ;
V_351 ++ ;
break;
}
}
if ( ! V_351 ) {
F_59 ( & V_59 -> V_57 , L_19 ) ;
error = - V_221 ;
goto V_354;
}
if ( V_351 == 2 )
V_23 -> V_291 = V_347 -> V_29 [ 0 ] . V_336 ;
V_23 -> V_18 = F_133 ( V_350 -> V_101 , F_134 ( V_350 ) ) ;
if ( ! V_23 -> V_18 )
goto V_354;
error = F_56 ( V_59 , V_347 -> V_223 , V_23 ) ;
if ( error ) {
F_59 ( & V_59 -> V_57 , L_20 ) ;
goto V_354;
}
V_23 -> V_58 = V_347 -> V_58 ;
for ( V_281 = 0 ; V_281 < V_351 ; V_281 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_281 ;
error = F_116 ( V_29 , & V_59 -> V_57 ) ;
if ( error )
goto V_354;
}
error = F_46 ( V_23 ) ;
if ( error ) {
F_59 ( & V_59 -> V_57 , L_21 ) ;
goto V_354;
}
for ( V_281 = 0 ; V_281 < V_351 ; V_281 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_281 ;
struct V_60 * V_61 = V_29 -> V_61 ;
if ( V_61 -> V_83 ) {
V_29 -> V_71 = F_135 ( sizeof( struct V_360 ) *
V_61 -> V_66 . V_67 >> V_68 ) ;
if ( ! V_29 -> V_71 ) {
F_59 ( & V_59 -> V_57 , L_22 ) ;
goto V_354;
}
}
V_61 -> V_310 = V_29 -> V_196 ;
error = F_136 ( V_61 ) ;
if ( error < 0 )
goto V_354;
F_137 ( V_61 -> V_57 , L_23 ,
V_59 -> V_314 , ( V_29 -> V_26 . V_15 == V_355 ) ?
L_24 : L_25 , V_61 -> V_43 . V_132 , V_61 -> V_43 . V_136 ,
V_61 -> V_43 . V_45 ) ;
if ( V_61 -> V_83 || V_61 -> V_305 == V_361 )
F_23 ( V_23 ) ;
}
V_23 -> V_320 . V_362 = F_103 ;
F_138 ( & V_23 -> V_320 ) ;
return 0 ;
V_354:
F_104 ( V_59 ) ;
return error ;
}
