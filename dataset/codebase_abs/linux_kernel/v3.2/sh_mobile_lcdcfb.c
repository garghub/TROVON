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
static void F_16 ( struct V_22 * V_23 )
{
if ( F_17 ( & V_23 -> V_42 ) ) {
if ( V_23 -> V_43 )
F_18 ( V_23 -> V_43 ) ;
F_19 ( V_23 -> V_44 ) ;
if ( V_23 -> V_45 && V_23 -> V_45 -> V_46 )
F_19 ( & V_23 -> V_45 -> V_46 -> V_44 ) ;
}
}
static void F_20 ( struct V_22 * V_23 )
{
if ( F_21 ( 1 , & V_23 -> V_42 ) == - 1 ) {
if ( V_23 -> V_45 && V_23 -> V_45 -> V_46 )
F_22 ( & V_23 -> V_45 -> V_46 -> V_44 ) ;
F_23 ( V_23 -> V_44 ) ;
if ( V_23 -> V_43 )
F_24 ( V_23 -> V_43 ) ;
}
}
static int F_25 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
unsigned int V_52 = V_48 -> V_53 . V_54 >> V_55 ;
struct V_56 * V_56 ;
int V_57 = 0 ;
F_26 ( V_29 -> V_58 , V_52 ) ;
F_27 (page, pagelist, lru)
F_28 ( & V_29 -> V_58 [ V_57 ++ ] , V_56 , V_59 , 0 ) ;
return V_57 ;
}
static void F_29 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_60 * V_61 = & V_29 -> V_26 . V_62 ;
F_16 ( V_29 -> V_17 ) ;
if ( ! F_30 ( V_50 ) ) {
unsigned int V_57 = F_25 ( V_48 , V_50 ) ;
F_31 ( V_48 -> V_44 , V_29 -> V_58 , V_57 , V_63 ) ;
if ( V_61 -> V_64 )
V_61 -> V_64 ( V_61 -> V_65 , V_29 ,
& V_66 ) ;
F_2 ( V_29 , V_67 , V_68 ) ;
F_32 ( V_48 -> V_44 , V_29 -> V_58 , V_57 , V_63 ) ;
} else {
if ( V_61 -> V_64 )
V_61 -> V_64 ( V_61 -> V_65 , V_29 ,
& V_66 ) ;
F_2 ( V_29 , V_67 , V_68 ) ;
}
}
static void F_33 ( struct V_47 * V_48 )
{
struct V_69 * V_70 = V_48 -> V_70 ;
if ( V_70 )
F_34 ( & V_48 -> V_71 , V_70 -> V_72 ) ;
}
static T_1 F_35 ( int V_73 , void * V_16 )
{
struct V_22 * V_23 = V_16 ;
struct V_14 * V_29 ;
unsigned long V_74 ;
int V_75 ;
int V_76 ;
V_74 = F_8 ( V_23 , V_77 ) ;
F_7 ( V_23 , V_77 , ( V_74 ^ V_78 ) & ~ V_79 ) ;
V_75 = ( F_8 ( V_23 , V_32 ) & V_80 ) ? 1 : 0 ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
if ( V_74 & V_82 ) {
if ( V_75 == F_11 ( V_29 ) ) {
V_29 -> V_83 = 1 ;
F_37 ( & V_29 -> V_84 ) ;
F_20 ( V_23 ) ;
}
}
if ( V_74 & V_85 )
F_38 ( & V_29 -> V_86 ) ;
}
return V_87 ;
}
static void F_39 ( struct V_22 * V_23 ,
int V_88 )
{
unsigned long V_89 = F_8 ( V_23 , V_90 ) ;
int V_76 ;
if ( V_88 )
F_7 ( V_23 , V_90 , V_89 | V_91 ) ;
else
F_7 ( V_23 , V_90 , V_89 & ~ V_91 ) ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ )
if ( F_8 ( V_23 , V_90 ) & V_23 -> V_29 [ V_76 ] . V_81 )
while ( 1 ) {
V_89 = F_5 ( & V_23 -> V_29 [ V_76 ] , V_92 )
& V_93 ;
if ( V_88 && V_89 == V_93 )
break;
if ( ! V_88 && V_89 == 0 )
break;
F_10 () ;
}
if ( ! V_88 )
F_7 ( V_23 , V_94 , 1 ) ;
}
static void F_40 ( struct V_14 * V_29 )
{
struct V_95 * V_96 = & V_29 -> V_48 -> V_96 , * V_97 = & V_29 -> V_97 ;
unsigned long V_98 , V_99 , V_100 ;
T_2 V_89 ;
V_89 = V_29 -> V_101 ;
V_89 |= ( V_96 -> V_102 & V_103 ) ? 0 : V_104 ;
V_89 |= ( V_96 -> V_102 & V_105 ) ? 0 : V_106 ;
V_89 |= ( V_29 -> V_26 . V_107 & V_108 ) ? V_109 : 0 ;
V_89 |= ( V_29 -> V_26 . V_107 & V_110 ) ? V_111 : 0 ;
V_89 |= ( V_29 -> V_26 . V_107 & V_112 ) ? V_113 : 0 ;
V_89 |= ( V_29 -> V_26 . V_107 & V_114 ) ? V_115 : 0 ;
V_89 |= ( V_29 -> V_26 . V_107 & V_116 ) ? V_117 : 0 ;
F_2 ( V_29 , V_2 , V_89 ) ;
F_2 ( V_29 , V_3 , V_29 -> V_26 . V_118 . V_119 ) ;
F_2 ( V_29 , V_4 , V_29 -> V_26 . V_118 . V_120 ) ;
V_98 = V_97 -> V_121 + V_97 -> V_122 +
V_97 -> V_123 + V_97 -> V_124 ;
V_89 = V_98 / 8 ;
V_89 |= ( F_41 ( V_97 -> V_121 , V_96 -> V_121 ) / 8 ) << 16 ;
F_2 ( V_29 , V_10 , V_89 ) ;
V_99 = V_97 -> V_121 + V_97 -> V_124 ;
V_89 = V_99 / 8 ;
V_89 |= ( V_97 -> V_122 / 8 ) << 16 ;
F_2 ( V_29 , V_11 , V_89 ) ;
V_89 = V_97 -> V_125 + V_97 -> V_126 +
V_97 -> V_127 + V_97 -> V_128 ;
V_89 |= F_41 ( V_97 -> V_125 , V_96 -> V_125 ) << 16 ;
F_2 ( V_29 , V_12 , V_89 ) ;
V_89 = V_97 -> V_125 + V_97 -> V_128 ;
V_89 |= V_97 -> V_126 << 16 ;
F_2 ( V_29 , V_13 , V_89 ) ;
V_100 = V_97 -> V_121 + V_97 -> V_122 +
V_97 -> V_123 + V_97 -> V_124 ;
V_89 = ( ( V_97 -> V_121 & 7 ) << 24 ) |
( ( V_100 & 7 ) << 16 ) |
( ( V_97 -> V_122 & 7 ) << 8 ) |
V_99 ;
F_2 ( V_29 , V_129 , V_89 ) ;
}
static void F_42 ( struct V_22 * V_23 )
{
struct V_14 * V_29 ;
unsigned long V_89 ;
int V_130 = 0 ;
int V_76 , V_131 ;
F_7 ( V_23 , V_90 , V_23 -> V_29 [ 0 ] . V_81 | V_23 -> V_29 [ 1 ] . V_81 ) ;
F_39 ( V_23 , 0 ) ;
F_7 ( V_23 , V_77 , 0 ) ;
V_89 = V_23 -> V_132 ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
if ( ! V_130 )
V_130 = V_29 -> V_48 -> V_96 . V_133 ;
F_2 ( V_29 , V_92 , 0 ) ;
V_131 = V_29 -> V_26 . V_134 ;
if ( ! V_131 )
continue;
F_2 ( V_29 , V_135 , 0 ) ;
F_2 ( V_29 , V_136 , ( 1 << ( V_131 / 2 ) ) - 1 ) ;
if ( V_131 == 1 )
V_131 = V_137 ;
V_89 |= V_131 << ( F_11 ( V_29 ) ? 8 : 0 ) ;
}
F_7 ( V_23 , V_138 , V_89 ) ;
F_7 ( V_23 , V_94 , 0 ) ;
F_9 ( V_23 , V_94 , ~ 0 , 0 ) ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
F_40 ( V_29 ) ;
if ( V_29 -> V_48 -> V_96 . V_139 ) {
V_89 = ( V_29 -> V_48 -> V_96 . V_139 << 16 ) ;
switch ( V_29 -> V_48 -> V_96 . V_133 ) {
case 12 :
V_89 |= V_140 ;
break;
case 16 :
V_89 |= V_141 ;
break;
case 24 :
default:
V_89 |= V_142 ;
break;
}
} else {
switch ( V_29 -> V_48 -> V_96 . V_133 ) {
case 16 :
V_89 = V_143 ;
break;
case 24 :
V_89 = V_144 ;
break;
case 32 :
default:
V_89 = V_145 ;
break;
}
}
F_2 ( V_29 , V_5 , V_89 ) ;
F_2 ( V_29 , V_9 , V_29 -> V_146 ) ;
F_2 ( V_29 , V_7 , V_29 -> V_147 ) ;
if ( V_29 -> V_48 -> V_96 . V_139 )
F_2 ( V_29 , V_8 , V_29 -> V_148 ) ;
if ( V_29 -> V_101 & V_149 &&
V_29 -> V_26 . V_118 . V_150 ) {
F_2 ( V_29 , V_6 , V_151 ) ;
F_7 ( V_23 , V_77 , V_152 ) ;
} else {
F_2 ( V_29 , V_6 , 0 ) ;
}
}
if ( V_23 -> V_29 [ 0 ] . V_48 -> V_96 . V_139 )
V_89 = V_153 | V_154 | V_155 ;
else {
switch ( V_130 ) {
case 16 :
V_89 = V_153 | V_154 ;
break;
case 24 :
V_89 = V_153 | V_154 | V_155 ;
break;
case 32 :
default:
V_89 = V_153 ;
break;
}
}
F_7 ( V_23 , V_156 , V_89 ) ;
F_7 ( V_23 , V_157 , V_158 ) ;
F_39 ( V_23 , 1 ) ;
V_23 -> V_159 = 1 ;
}
static int F_43 ( struct V_22 * V_23 )
{
struct V_160 * V_161 = V_23 -> V_45 ;
struct V_60 * V_62 ;
struct V_14 * V_29 ;
unsigned long V_89 ;
int V_162 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
if ( V_23 -> V_29 [ V_76 ] . V_81 )
F_16 ( V_23 ) ;
}
F_7 ( V_23 , V_90 , F_8 ( V_23 , V_90 ) | V_163 ) ;
F_9 ( V_23 , V_90 , V_163 , 0 ) ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
V_62 = & V_29 -> V_26 . V_62 ;
if ( V_62 -> V_164 ) {
V_162 = V_62 -> V_164 ( V_62 -> V_65 , V_29 ,
& V_66 ) ;
if ( V_162 )
return V_162 ;
}
}
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
struct V_165 * V_26 ;
int V_166 ;
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
V_29 -> V_147 = V_29 -> V_48 -> V_53 . V_167 ;
V_29 -> V_148 = V_29 -> V_147
+ V_29 -> V_48 -> V_96 . V_121
* V_29 -> V_48 -> V_96 . V_168 ;
V_29 -> V_146 = V_29 -> V_48 -> V_53 . V_169 ;
V_26 = V_29 -> V_26 . V_170 ;
if ( V_161 == NULL || V_161 -> V_171 == NULL || V_26 == NULL )
continue;
if ( V_29 -> V_172 ) {
V_161 -> V_171 -> V_173 ( V_161 , V_26 ) ;
V_29 -> V_172 = 0 ;
}
if ( ! V_29 -> V_48 -> V_96 . V_139 )
V_166 = V_174 ;
else if ( V_29 -> V_48 -> V_96 . V_133 == 24 )
V_166 = V_175 ;
else
V_166 = V_176 ;
V_162 = V_161 -> V_171 -> V_177 ( V_161 , V_26 , V_29 -> V_146 ,
V_29 -> V_48 -> V_96 . V_125 , V_166 ,
V_29 -> V_147 , V_29 -> V_148 ,
& V_29 -> V_147 , & V_29 -> V_148 ,
& V_29 -> V_146 ) ;
if ( ! V_162 )
V_29 -> V_172 = 1 ;
}
F_42 ( V_23 ) ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
V_89 = V_29 -> V_26 . V_118 . V_150 ;
if ( V_29 -> V_101 & V_149 && V_89 ) {
V_29 -> V_178 . V_179 = F_29 ;
V_29 -> V_178 . V_72 = F_44 ( V_89 ) ;
V_29 -> V_48 -> V_70 = & V_29 -> V_178 ;
F_45 ( V_29 -> V_48 ) ;
}
V_62 = & V_29 -> V_26 . V_62 ;
if ( V_62 -> V_180 && F_46 ( V_62 -> V_181 ) ) {
V_62 -> V_180 ( V_62 -> V_65 , V_29 -> V_48 ) ;
F_47 ( V_62 -> V_181 ) ;
}
if ( V_29 -> V_182 ) {
V_29 -> V_182 -> V_183 . V_184 = V_185 ;
F_48 ( V_29 -> V_182 ) ;
}
}
return 0 ;
}
static void F_49 ( struct V_22 * V_23 )
{
struct V_14 * V_29 ;
struct V_60 * V_62 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ ) {
V_29 = & V_23 -> V_29 [ V_76 ] ;
if ( ! V_29 -> V_81 )
continue;
if ( V_29 -> V_48 && V_29 -> V_48 -> V_70 ) {
V_29 -> V_83 = 0 ;
F_34 ( & V_29 -> V_48 -> V_71 , 0 ) ;
F_50 ( V_29 -> V_84 , V_29 -> V_83 ) ;
F_51 ( V_29 -> V_48 ) ;
V_29 -> V_48 -> V_70 = NULL ;
F_16 ( V_23 ) ;
}
if ( V_29 -> V_182 ) {
V_29 -> V_182 -> V_183 . V_184 = V_186 ;
F_48 ( V_29 -> V_182 ) ;
}
V_62 = & V_29 -> V_26 . V_62 ;
if ( V_62 -> V_187 && F_46 ( V_62 -> V_181 ) ) {
V_62 -> V_187 ( V_62 -> V_65 ) ;
F_47 ( V_62 -> V_181 ) ;
}
if ( V_29 -> V_172 ) {
struct V_165 * V_26 ;
struct V_160 * V_161 ;
V_26 = V_29 -> V_26 . V_170 ;
V_161 = V_23 -> V_45 ;
V_161 -> V_171 -> V_173 ( V_161 , V_26 ) ;
V_29 -> V_172 = 0 ;
}
}
if ( V_23 -> V_159 ) {
F_39 ( V_23 , 0 ) ;
V_23 -> V_159 = 0 ;
}
for ( V_76 = 0 ; V_76 < F_36 ( V_23 -> V_29 ) ; V_76 ++ )
if ( V_23 -> V_29 [ V_76 ] . V_81 )
F_20 ( V_23 ) ;
}
static int F_52 ( struct V_14 * V_29 )
{
int V_188 = V_29 -> V_26 . V_188 ;
switch ( V_188 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
break;
default:
return - V_207 ;
}
if ( F_11 ( V_29 ) ) {
if ( ! ( V_188 & V_149 ) )
return - V_207 ;
V_188 &= ~ V_149 ;
}
V_29 -> V_101 = V_188 ;
return 0 ;
}
static int F_53 ( struct V_208 * V_46 ,
int V_209 ,
struct V_22 * V_23 )
{
char * V_210 ;
switch ( V_209 ) {
case V_211 :
V_210 = L_1 ;
V_23 -> V_132 = V_212 ;
break;
case V_213 :
V_210 = L_2 ;
V_23 -> V_132 = V_214 ;
break;
case V_215 :
V_210 = NULL ;
V_23 -> V_132 = V_216 ;
break;
default:
return - V_207 ;
}
if ( V_210 ) {
V_23 -> V_43 = F_54 ( & V_46 -> V_44 , V_210 ) ;
if ( F_55 ( V_23 -> V_43 ) ) {
F_56 ( & V_46 -> V_44 , L_3 , V_210 ) ;
return F_57 ( V_23 -> V_43 ) ;
}
}
V_23 -> V_44 = & V_46 -> V_44 ;
F_58 ( V_23 -> V_44 ) ;
F_59 ( V_23 -> V_44 ) ;
return 0 ;
}
static int F_60 ( T_3 V_217 ,
T_3 V_218 , T_3 V_219 , T_3 V_220 ,
T_3 V_221 , struct V_47 * V_48 )
{
T_2 * V_222 = V_48 -> V_223 ;
if ( V_217 >= V_224 )
return - V_207 ;
V_218 >>= 16 - V_48 -> V_96 . V_218 . V_225 ;
V_219 >>= 16 - V_48 -> V_96 . V_219 . V_225 ;
V_220 >>= 16 - V_48 -> V_96 . V_220 . V_225 ;
V_221 >>= 16 - V_48 -> V_96 . V_221 . V_225 ;
V_222 [ V_217 ] = ( V_218 << V_48 -> V_96 . V_218 . V_226 ) |
( V_219 << V_48 -> V_96 . V_219 . V_226 ) |
( V_220 << V_48 -> V_96 . V_220 . V_226 ) |
( V_221 << V_48 -> V_96 . V_221 . V_226 ) ;
return 0 ;
}
static void F_61 ( struct V_47 * V_48 ,
const struct V_227 * V_228 )
{
F_62 ( V_48 , V_228 ) ;
F_33 ( V_48 ) ;
}
static void F_63 ( struct V_47 * V_48 ,
const struct V_229 * V_230 )
{
F_64 ( V_48 , V_230 ) ;
F_33 ( V_48 ) ;
}
static void F_65 ( struct V_47 * V_48 ,
const struct V_231 * V_232 )
{
F_66 ( V_48 , V_232 ) ;
F_33 ( V_48 ) ;
}
static int F_67 ( struct V_95 * V_96 ,
struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_22 * V_23 = V_29 -> V_17 ;
unsigned long V_233 ;
unsigned long V_234 ;
unsigned long V_147 , V_148 ;
unsigned long V_235 ;
if ( ! V_48 -> V_96 . V_139 )
V_234 = V_96 -> V_236 * V_48 -> V_53 . V_169
+ V_96 -> V_237 * ( V_48 -> V_96 . V_133 / 8 ) ;
else
V_234 = V_96 -> V_236 * V_48 -> V_53 . V_169
+ V_96 -> V_237 ;
if ( V_234 == V_29 -> V_238 )
return 0 ;
V_233 = F_8 ( V_23 , V_239 ) ;
V_147 = V_29 -> V_240 + V_234 ;
if ( V_48 -> V_96 . V_139 ) {
V_235 = V_96 -> V_236 * V_48 -> V_53 . V_169
* ( V_48 -> V_96 . V_133 - 8 ) / 8 ;
V_148 = V_29 -> V_240
+ V_48 -> V_96 . V_121 * V_48 -> V_96 . V_168
+ V_235 ;
if ( V_48 -> V_96 . V_133 == 24 )
V_148 += 2 * V_96 -> V_237 ;
else
V_148 += V_96 -> V_237 ;
}
if ( V_29 -> V_172 ) {
struct V_165 * V_26 ;
struct V_160 * V_161 ;
int V_162 ;
V_26 = V_29 -> V_26 . V_170 ;
V_161 = V_23 -> V_45 ;
V_162 = V_161 -> V_171 -> V_241 ( V_161 , V_26 ,
V_147 , V_148 ,
& V_147 , & V_148 ) ;
if ( V_162 )
return V_162 ;
}
V_29 -> V_147 = V_147 ;
V_29 -> V_148 = V_148 ;
F_4 ( V_29 , V_7 , V_147 ) ;
if ( V_48 -> V_96 . V_139 )
F_4 ( V_29 , V_8 , V_148 ) ;
if ( F_11 ( V_29 ) )
F_7 ( V_29 -> V_17 , V_239 , V_233 ^ V_242 ) ;
else
F_7 ( V_29 -> V_17 , V_239 , V_233 ^ V_243 ) ;
V_29 -> V_238 = V_234 ;
F_33 ( V_48 ) ;
return 0 ;
}
static int F_68 ( struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
unsigned long V_74 ;
int V_162 ;
V_74 = F_8 ( V_29 -> V_17 , V_77 ) ;
V_74 |= V_79 | V_78 ;
F_7 ( V_29 -> V_17 , V_77 , V_74 ) ;
V_162 = F_69 ( & V_29 -> V_86 ,
F_44 ( 100 ) ) ;
if ( ! V_162 )
return - V_244 ;
return 0 ;
}
static int F_70 ( struct V_47 * V_48 , unsigned int V_245 ,
unsigned long V_246 )
{
int V_247 ;
switch ( V_245 ) {
case V_248 :
V_247 = F_68 ( V_48 ) ;
break;
default:
V_247 = - V_249 ;
break;
}
return V_247 ;
}
static void F_71 ( struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_250 V_251 , V_252 ;
struct V_253 V_254 ;
int V_255 = V_256 ;
if ( V_29 -> V_257 > 1 || ( V_29 -> V_257 == 1 && ! V_48 -> V_258 ) )
return;
F_72 ( & V_251 , & V_29 -> V_97 ) ;
F_72 ( & V_252 , & V_48 -> V_96 ) ;
if ( F_73 ( & V_251 , & V_252 ) )
return;
if ( F_74 ( V_48 , & V_29 -> V_97 ) < 0 )
return;
V_254 . V_48 = V_48 ;
V_254 . V_16 = & V_251 ;
F_75 ( V_255 , & V_254 ) ;
}
static int F_76 ( struct V_47 * V_48 , int V_259 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
F_77 ( & V_29 -> V_260 ) ;
F_78 ( V_48 -> V_44 , L_4 , V_261 , V_29 -> V_257 ) ;
V_29 -> V_257 -- ;
if ( V_259 ) {
F_79 () ;
F_71 ( V_48 ) ;
F_80 () ;
}
F_81 ( & V_29 -> V_260 ) ;
return 0 ;
}
static int F_82 ( struct V_47 * V_48 , int V_259 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
F_77 ( & V_29 -> V_260 ) ;
V_29 -> V_257 ++ ;
F_78 ( V_48 -> V_44 , L_4 , V_261 , V_29 -> V_257 ) ;
F_81 ( & V_29 -> V_260 ) ;
return 0 ;
}
static int F_83 ( struct V_95 * V_96 , struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_22 * V_262 = V_29 -> V_17 ;
unsigned int V_263 = ( unsigned int ) - 1 ;
unsigned int V_264 = 0 ;
unsigned int V_265 = 0 ;
unsigned int V_266 ;
if ( V_96 -> V_121 > V_267 || V_96 -> V_125 > V_268 )
return - V_207 ;
for ( V_266 = 0 ; V_266 < V_29 -> V_26 . V_269 ; ++ V_266 ) {
const struct V_250 * V_270 = & V_29 -> V_26 . V_271 [ V_266 ] ;
unsigned int V_272 ;
if ( V_96 -> V_121 > V_270 -> V_121 || V_96 -> V_125 > V_270 -> V_125 )
continue;
V_272 = V_96 -> V_121 * V_96 -> V_125 + V_270 -> V_121 * V_270 -> V_125
- 2 * F_41 ( V_96 -> V_121 , V_270 -> V_121 )
* F_41 ( V_96 -> V_125 , V_270 -> V_125 ) ;
if ( V_272 < V_263 ) {
V_264 = V_270 -> V_121 ;
V_265 = V_270 -> V_125 ;
V_263 = V_272 ;
}
}
if ( V_29 -> V_26 . V_269 != 0 ) {
if ( V_263 == ( unsigned int ) - 1 )
return - V_207 ;
V_96 -> V_121 = V_264 ;
V_96 -> V_125 = V_265 ;
}
if ( V_96 -> V_273 < V_96 -> V_121 )
V_96 -> V_273 = V_96 -> V_121 ;
if ( V_96 -> V_168 < V_96 -> V_125 )
V_96 -> V_168 = V_96 -> V_125 ;
if ( V_96 -> V_133 <= 16 ) {
V_96 -> V_133 = 16 ;
V_96 -> V_218 . V_226 = 11 ;
V_96 -> V_218 . V_225 = 5 ;
V_96 -> V_219 . V_226 = 5 ;
V_96 -> V_219 . V_225 = 6 ;
V_96 -> V_220 . V_226 = 0 ;
V_96 -> V_220 . V_225 = 5 ;
V_96 -> V_221 . V_226 = 0 ;
V_96 -> V_221 . V_225 = 0 ;
} else if ( V_96 -> V_133 <= 24 ) {
V_96 -> V_133 = 24 ;
V_96 -> V_218 . V_226 = 16 ;
V_96 -> V_218 . V_225 = 8 ;
V_96 -> V_219 . V_226 = 8 ;
V_96 -> V_219 . V_225 = 8 ;
V_96 -> V_220 . V_226 = 0 ;
V_96 -> V_220 . V_225 = 8 ;
V_96 -> V_221 . V_226 = 0 ;
V_96 -> V_221 . V_225 = 0 ;
} else if ( V_96 -> V_133 <= 32 ) {
V_96 -> V_133 = 32 ;
V_96 -> V_218 . V_226 = 16 ;
V_96 -> V_218 . V_225 = 8 ;
V_96 -> V_219 . V_226 = 8 ;
V_96 -> V_219 . V_225 = 8 ;
V_96 -> V_220 . V_226 = 0 ;
V_96 -> V_220 . V_225 = 8 ;
V_96 -> V_221 . V_226 = 24 ;
V_96 -> V_221 . V_225 = 8 ;
} else
return - V_207 ;
V_96 -> V_218 . V_274 = 0 ;
V_96 -> V_219 . V_274 = 0 ;
V_96 -> V_220 . V_274 = 0 ;
V_96 -> V_221 . V_274 = 0 ;
if ( V_96 -> V_273 * V_96 -> V_168 * V_96 -> V_133 / 8 >
V_48 -> V_53 . V_54 )
return - V_207 ;
if ( V_262 -> V_275 && V_262 -> V_275 != V_96 -> V_133 )
return - V_207 ;
return 0 ;
}
static int F_84 ( struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
T_2 V_169 = V_48 -> V_53 . V_169 ;
int V_162 ;
F_49 ( V_29 -> V_17 ) ;
if ( V_48 -> V_96 . V_139 )
V_48 -> V_53 . V_169 = V_48 -> V_96 . V_121 ;
else
V_48 -> V_53 . V_169 = V_48 -> V_96 . V_121
* V_48 -> V_96 . V_133 / 8 ;
V_162 = F_43 ( V_29 -> V_17 ) ;
if ( V_162 < 0 ) {
F_56 ( V_48 -> V_44 , L_5 , V_261 ) ;
V_48 -> V_53 . V_169 = V_169 ;
}
return V_162 ;
}
static int F_85 ( int V_276 , struct V_47 * V_48 )
{
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_22 * V_262 = V_29 -> V_17 ;
if ( V_276 > V_185 && V_29 -> V_277 == V_185 ) {
struct V_227 V_228 = {
. V_278 = V_48 -> V_96 . V_121 ,
. V_279 = V_48 -> V_96 . V_125 ,
} ;
F_61 ( V_48 , & V_228 ) ;
}
if ( V_276 <= V_280 && V_29 -> V_277 > V_280 ) {
F_16 ( V_262 ) ;
}
if ( V_276 > V_280 && V_29 -> V_277 <= V_280 ) {
if ( ! V_48 -> V_70 ) {
F_68 ( V_48 ) ;
F_68 ( V_48 ) ;
}
F_20 ( V_262 ) ;
}
V_29 -> V_277 = V_276 ;
return 0 ;
}
static int F_86 ( struct V_281 * V_282 )
{
struct V_14 * V_29 = F_87 ( V_282 ) ;
struct V_60 * V_26 = & V_29 -> V_26 . V_62 ;
int V_283 = V_282 -> V_183 . V_283 ;
if ( V_282 -> V_183 . V_184 != V_185 ||
V_282 -> V_183 . V_284 & ( V_285 | V_286 ) )
V_283 = 0 ;
return V_26 -> V_287 ( V_26 -> V_65 , V_283 ) ;
}
static int F_88 ( struct V_281 * V_282 )
{
struct V_14 * V_29 = F_87 ( V_282 ) ;
struct V_60 * V_26 = & V_29 -> V_26 . V_62 ;
return V_26 -> V_288 ( V_26 -> V_65 ) ;
}
static int F_89 ( struct V_281 * V_282 ,
struct V_47 * V_48 )
{
return ( V_48 -> V_289 == V_282 ) ;
}
static struct V_281 * F_90 ( struct V_290 * V_291 ,
struct V_14 * V_29 )
{
struct V_281 * V_182 ;
V_182 = F_91 ( V_29 -> V_26 . V_292 . V_293 , V_291 , V_29 ,
& V_294 , NULL ) ;
if ( F_55 ( V_182 ) ) {
F_56 ( V_291 , L_6 ,
F_57 ( V_182 ) ) ;
return NULL ;
}
V_182 -> V_183 . V_295 = V_29 -> V_26 . V_292 . V_295 ;
V_182 -> V_183 . V_283 = V_182 -> V_183 . V_295 ;
F_48 ( V_182 ) ;
return V_182 ;
}
static void F_92 ( struct V_281 * V_282 )
{
F_93 ( V_282 ) ;
}
static int F_94 ( struct V_290 * V_44 )
{
struct V_208 * V_46 = F_95 ( V_44 ) ;
F_49 ( F_96 ( V_46 ) ) ;
return 0 ;
}
static int F_97 ( struct V_290 * V_44 )
{
struct V_208 * V_46 = F_95 ( V_44 ) ;
return F_43 ( F_96 ( V_46 ) ) ;
}
static int F_98 ( struct V_290 * V_44 )
{
struct V_208 * V_46 = F_95 ( V_44 ) ;
struct V_22 * V_23 = F_96 ( V_46 ) ;
F_7 ( V_23 , V_157 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_290 * V_44 )
{
struct V_208 * V_46 = F_95 ( V_44 ) ;
struct V_22 * V_23 = F_96 ( V_46 ) ;
F_42 ( V_23 ) ;
return 0 ;
}
static int F_100 ( struct V_296 * V_297 ,
unsigned long V_298 , void * V_16 )
{
struct V_253 * V_254 = V_16 ;
struct V_47 * V_48 = V_254 -> V_48 ;
struct V_14 * V_29 = V_48 -> V_51 ;
struct V_60 * V_62 = & V_29 -> V_26 . V_62 ;
if ( & V_29 -> V_17 -> V_299 != V_297 )
return V_300 ;
F_78 ( V_48 -> V_44 , L_7 ,
V_261 , V_298 , V_254 -> V_16 ) ;
switch( V_298 ) {
case V_301 :
if ( V_62 -> V_187 && F_46 ( V_62 -> V_181 ) ) {
V_62 -> V_187 ( V_62 -> V_65 ) ;
F_47 ( V_62 -> V_181 ) ;
}
F_49 ( V_29 -> V_17 ) ;
break;
case V_302 :
F_77 ( & V_29 -> V_260 ) ;
F_71 ( V_48 ) ;
F_81 ( & V_29 -> V_260 ) ;
if ( V_62 -> V_180 && F_46 ( V_62 -> V_181 ) ) {
V_62 -> V_180 ( V_62 -> V_65 , V_48 ) ;
F_47 ( V_62 -> V_181 ) ;
}
F_43 ( V_29 -> V_17 ) ;
}
return V_303 ;
}
static int F_101 ( struct V_208 * V_46 )
{
struct V_22 * V_23 = F_96 ( V_46 ) ;
struct V_47 * V_48 ;
int V_266 ;
F_102 ( & V_23 -> V_299 ) ;
for ( V_266 = 0 ; V_266 < F_36 ( V_23 -> V_29 ) ; V_266 ++ )
if ( V_23 -> V_29 [ V_266 ] . V_48 && V_23 -> V_29 [ V_266 ] . V_48 -> V_44 )
F_103 ( V_23 -> V_29 [ V_266 ] . V_48 ) ;
F_49 ( V_23 ) ;
for ( V_266 = 0 ; V_266 < F_36 ( V_23 -> V_29 ) ; V_266 ++ ) {
V_48 = V_23 -> V_29 [ V_266 ] . V_48 ;
if ( ! V_48 || ! V_48 -> V_290 )
continue;
if ( V_23 -> V_29 [ V_266 ] . V_58 )
F_104 ( V_23 -> V_29 [ V_266 ] . V_58 ) ;
if ( V_48 -> V_304 )
F_105 ( & V_46 -> V_44 , V_48 -> V_53 . V_54 ,
V_48 -> V_304 ,
V_23 -> V_29 [ V_266 ] . V_240 ) ;
F_106 ( & V_48 -> V_305 ) ;
F_107 ( V_48 ) ;
}
for ( V_266 = 0 ; V_266 < F_36 ( V_23 -> V_29 ) ; V_266 ++ ) {
if ( V_23 -> V_29 [ V_266 ] . V_182 )
F_92 ( V_23 -> V_29 [ V_266 ] . V_182 ) ;
}
if ( V_23 -> V_43 )
F_108 ( V_23 -> V_43 ) ;
if ( V_23 -> V_44 )
F_109 ( V_23 -> V_44 ) ;
if ( V_23 -> V_18 )
F_110 ( V_23 -> V_18 ) ;
if ( V_23 -> V_73 )
F_111 ( V_23 -> V_73 , V_23 ) ;
F_112 ( V_23 ) ;
return 0 ;
}
static int T_4 F_113 ( struct V_14 * V_29 ,
struct V_290 * V_44 )
{
struct V_306 * V_26 = & V_29 -> V_26 ;
const struct V_250 * V_307 ;
const struct V_250 * V_270 ;
struct V_95 * V_96 ;
struct V_47 * V_48 ;
unsigned int V_308 ;
int V_269 ;
void * V_309 ;
int V_162 ;
int V_266 ;
F_114 ( & V_29 -> V_260 ) ;
V_29 -> V_48 = F_115 ( 0 , V_44 ) ;
if ( ! V_29 -> V_48 ) {
F_56 ( V_44 , L_8 ) ;
return - V_310 ;
}
V_48 = V_29 -> V_48 ;
V_48 -> V_311 = & V_312 ;
V_48 -> V_51 = V_29 ;
V_48 -> V_223 = & V_29 -> V_223 ;
V_48 -> V_107 = V_313 ;
V_307 = NULL ;
V_308 = 0 ;
for ( V_266 = 0 , V_270 = V_26 -> V_271 ; V_266 < V_26 -> V_269 ; V_266 ++ , V_270 ++ ) {
unsigned int V_314 = V_270 -> V_125 * V_270 -> V_121 ;
if ( ( V_26 -> V_139 ) && V_26 -> V_130 == 12 &&
( V_270 -> V_125 & 0x1 ) ) {
F_56 ( V_44 , L_9
L_10 ) ;
return - V_207 ;
}
if ( V_314 > V_308 ) {
V_307 = V_270 ;
V_308 = V_314 ;
}
}
if ( ! V_308 )
V_308 = V_267 * V_268 ;
else
F_78 ( V_44 , L_11 ,
V_307 -> V_121 , V_307 -> V_125 ) ;
V_48 -> V_53 = V_315 ;
V_48 -> V_53 . V_54 = V_308 * 2 * V_26 -> V_130 / 8 ;
if ( V_26 -> V_139 && V_26 -> V_130 == 12 )
V_48 -> V_53 . V_316 = 2 ;
if ( V_26 -> V_271 == NULL ) {
V_270 = & V_317 ;
V_269 = 1 ;
} else {
V_270 = V_26 -> V_271 ;
V_269 = V_26 -> V_269 ;
}
F_116 ( V_270 , V_269 , & V_48 -> V_318 ) ;
V_96 = & V_48 -> V_96 ;
F_117 ( V_96 , V_270 ) ;
V_96 -> V_133 = V_26 -> V_130 ;
V_96 -> V_278 = V_26 -> V_319 . V_278 ;
V_96 -> V_279 = V_26 -> V_319 . V_279 ;
V_96 -> V_168 = V_96 -> V_125 * 2 ;
V_96 -> V_320 = V_321 ;
V_162 = F_83 ( V_96 , V_48 ) ;
if ( V_162 )
return V_162 ;
V_309 = F_118 ( V_44 , V_48 -> V_53 . V_54 , & V_29 -> V_240 ,
V_322 ) ;
if ( ! V_309 ) {
F_56 ( V_44 , L_12 ) ;
return - V_310 ;
}
V_162 = F_119 ( & V_48 -> V_305 , V_224 , 0 ) ;
if ( V_162 < 0 ) {
F_56 ( V_44 , L_13 ) ;
F_105 ( V_44 , V_48 -> V_53 . V_54 ,
V_309 , V_29 -> V_240 ) ;
return V_162 ;
}
V_48 -> V_53 . V_167 = V_29 -> V_240 ;
if ( V_96 -> V_139 )
V_48 -> V_53 . V_169 = V_96 -> V_121 ;
else
V_48 -> V_53 . V_169 = V_96 -> V_121 * ( V_26 -> V_130 / 8 ) ;
V_48 -> V_304 = V_309 ;
V_48 -> V_290 = V_44 ;
V_29 -> V_97 = * V_96 ;
return 0 ;
}
static int T_4 F_120 ( struct V_208 * V_46 )
{
struct V_323 * V_324 = V_46 -> V_44 . V_325 ;
struct V_22 * V_23 ;
struct V_326 * V_327 ;
int V_328 ;
int error ;
int V_266 ;
if ( ! V_324 ) {
F_56 ( & V_46 -> V_44 , L_14 ) ;
return - V_207 ;
}
V_327 = F_121 ( V_46 , V_329 , 0 ) ;
V_266 = F_122 ( V_46 , 0 ) ;
if ( ! V_327 || V_266 < 0 ) {
F_56 ( & V_46 -> V_44 , L_15 ) ;
return - V_330 ;
}
V_23 = F_123 ( sizeof( * V_23 ) , V_322 ) ;
if ( ! V_23 ) {
F_56 ( & V_46 -> V_44 , L_16 ) ;
return - V_310 ;
}
F_124 ( V_46 , V_23 ) ;
error = F_125 ( V_266 , F_35 , 0 ,
F_126 ( & V_46 -> V_44 ) , V_23 ) ;
if ( error ) {
F_56 ( & V_46 -> V_44 , L_17 ) ;
goto V_331;
}
V_23 -> V_73 = V_266 ;
F_127 ( & V_23 -> V_42 , - 1 ) ;
for ( V_266 = 0 , V_328 = 0 ; V_266 < F_36 ( V_324 -> V_29 ) ; V_266 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_328 ;
V_29 -> V_17 = V_23 ;
memcpy ( & V_29 -> V_26 , & V_324 -> V_29 [ V_266 ] , sizeof( V_324 -> V_29 [ V_266 ] ) ) ;
error = F_52 ( V_29 ) ;
if ( error ) {
F_56 ( & V_46 -> V_44 , L_18 ) ;
goto V_331;
}
F_128 ( & V_29 -> V_84 ) ;
F_129 ( & V_29 -> V_86 ) ;
V_29 -> V_238 = 0 ;
if ( V_29 -> V_26 . V_292 . V_295 )
V_29 -> V_182 = F_90 ( & V_46 -> V_44 , V_29 ) ;
switch ( V_324 -> V_29 [ V_266 ] . V_15 ) {
case V_332 :
V_29 -> V_81 = V_333 ;
V_29 -> V_19 = V_334 ;
V_328 ++ ;
break;
case V_27 :
V_29 -> V_81 = V_335 ;
V_29 -> V_19 = V_336 ;
V_328 ++ ;
break;
}
}
if ( ! V_328 ) {
F_56 ( & V_46 -> V_44 , L_19 ) ;
error = - V_207 ;
goto V_331;
}
if ( V_328 == 2 )
V_23 -> V_275 = V_324 -> V_29 [ 0 ] . V_130 ;
V_23 -> V_18 = F_130 ( V_327 -> V_88 , F_131 ( V_327 ) ) ;
if ( ! V_23 -> V_18 )
goto V_331;
error = F_53 ( V_46 , V_324 -> V_209 , V_23 ) ;
if ( error ) {
F_56 ( & V_46 -> V_44 , L_20 ) ;
goto V_331;
}
V_23 -> V_45 = V_324 -> V_45 ;
for ( V_266 = 0 ; V_266 < V_328 ; V_266 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_266 ;
error = F_113 ( V_29 , & V_46 -> V_44 ) ;
if ( error )
goto V_331;
}
error = F_43 ( V_23 ) ;
if ( error ) {
F_56 ( & V_46 -> V_44 , L_21 ) ;
goto V_331;
}
for ( V_266 = 0 ; V_266 < V_328 ; V_266 ++ ) {
struct V_14 * V_29 = V_23 -> V_29 + V_266 ;
struct V_47 * V_48 = V_29 -> V_48 ;
if ( V_48 -> V_70 ) {
V_29 -> V_58 = F_132 ( sizeof( struct V_337 ) *
V_48 -> V_53 . V_54 >> V_55 ) ;
if ( ! V_29 -> V_58 ) {
F_56 ( & V_46 -> V_44 , L_22 ) ;
goto V_331;
}
}
V_48 -> V_289 = V_29 -> V_182 ;
error = F_133 ( V_48 ) ;
if ( error < 0 )
goto V_331;
F_134 ( V_48 -> V_44 ,
L_23 ,
V_46 -> V_293 ,
( V_29 -> V_26 . V_15 == V_332 ) ?
L_24 : L_25 ,
V_48 -> V_96 . V_121 , V_48 -> V_96 . V_125 ,
V_29 -> V_26 . V_130 ) ;
if ( V_48 -> V_70 || V_48 -> V_284 == V_338 )
F_20 ( V_23 ) ;
}
V_23 -> V_299 . V_339 = F_100 ;
F_135 ( & V_23 -> V_299 ) ;
return 0 ;
V_331:
F_101 ( V_46 ) ;
return error ;
}
static int T_5 F_136 ( void )
{
return F_137 ( & V_340 ) ;
}
static void T_6 F_138 ( void )
{
F_139 ( & V_340 ) ;
}
